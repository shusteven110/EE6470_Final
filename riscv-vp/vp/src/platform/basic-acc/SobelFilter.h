#ifndef SOBEL_FILTER_H_
#define SOBEL_FILTER_H_
#include <systemc>
#include <cmath>
#include <iomanip>
using namespace sc_core;

#include <tlm>
#include <tlm_utils/simple_target_socket.h>

#include "filter_def.h"

struct SobelFilter : public sc_module {
  tlm_utils::simple_target_socket<SobelFilter> tsock;

  sc_fifo<unsigned char> i_r;
  sc_fifo<unsigned char> i_g;
  sc_fifo<unsigned char> i_b;
  sc_fifo<unsigned int> o_result;

  SC_HAS_PROCESS(SobelFilter);

  SobelFilter(sc_module_name n): 
    sc_module(n), 
    tsock("t_skt"), 
    base_offset(0) 
  {
    tsock.register_b_transport(this, &SobelFilter::blocking_transport);
    SC_THREAD(do_filter);
  }

  ~SobelFilter() {
	}

  // int val[MASK_N];
  unsigned int base_offset;


  int ORDER = 28;
  int params[ORDER] = {
      8, 11, -7, -2, 11, -11, -2, 19, -21, -3,
      39, -53, -3, 283, 283, -3, -53, 39, -3, -21,
      19, -2, -11, 11, -2, -7, 11, 8};
  
  int shift_reg[ORDER];
  int output = 0;


  /*初始化*/
  for (int t = 0; t != ORDER; t++)
  {
    shift_reg[t] = 0;
  }


  void do_filter(){
    { wait(CLOCK_PERIOD, SC_NS); }
    while (true) {
      for (int i = ORDER - 1; i > 0; --i)
      {
        shift_reg[i] = shift_reg[i - 1];
        output += shift_reg[i] * params[i];
      }
      int rgb = 0;
      rgb = i_rgb.read();
      shift_reg[0] = rgb;
      output += shift_reg[0] * params[0];

      sc_dt::sc_uint<16> out_avg_all;
      out_avg_all = output;
      o_avg.write(out_avg_all);
      wait();
    }
  }

  void blocking_transport(tlm::tlm_generic_payload &payload, sc_core::sc_time &delay){
    wait(delay);
    // unsigned char *mask_ptr = payload.get_byte_enable_ptr();
    // auto len = payload.get_data_length();
    tlm::tlm_command cmd = payload.get_command();
    sc_dt::uint64 addr = payload.get_address();
    int *data_ptr = payload.get_data_ptr();

    addr -= base_offset;


    // cout << (int)data_ptr[0] << endl;
    // cout << (int)data_ptr[1] << endl;
    // cout << (int)data_ptr[2] << endl;
    word buffer;

    switch (cmd) {
      case tlm::TLM_READ_COMMAND:
        // cout << "READ" << endl;
        switch (addr) {
          case SOBEL_FILTER_RESULT_ADDR:
            buffer.uint = o_result.read();
            break;
          default:
            std::cerr << "READ Error! SobelFilter::blocking_transport: address 0x"
                      << std::setfill('0') << std::setw(8) << std::hex << addr
                      << std::dec << " is not valid" << std::endl;
          }
        data_ptr[0] = buffer.uc[0];
        data_ptr[1] = buffer.uc[1];
        data_ptr[2] = buffer.uc[2];
        data_ptr[3] = buffer.uc[3];
        break;
      case tlm::TLM_WRITE_COMMAND:
        // cout << "WRITE" << endl;
        switch (addr) {
          case SOBEL_FILTER_R_ADDR:
            i_r.write(data_ptr[3]);
            i_g.write(data_ptr[2]);
            i_b.write(data_ptr[1]);
            break;
          default:
            std::cerr << "WRITE Error! SobelFilter::blocking_transport: address 0x"
                      << std::setfill('0') << std::setw(8) << std::hex << addr
                      << std::dec << " is not valid" << std::endl;
        }
        break;
      case tlm::TLM_IGNORE_COMMAND:
        payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
        return;
      default:
        payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
        return;
      }
      payload.set_response_status(tlm::TLM_OK_RESPONSE); // Always OK
  }
};
#endif
