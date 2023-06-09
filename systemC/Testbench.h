#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <string>
using namespace std;

#include <systemc>
using namespace sc_core;

#ifndef NATIVE_SYSTEMC
#include <cynw_p2p.h>
#endif
#include <iostream>
#include <fstream>

#include "filter_def.h"

#define WHITE 255
#define BLACK 0
#define THRESHOLD 90
#define channel_bit 32
class Testbench : public sc_module
{
public:
  sc_in_clk i_clk;
  sc_out<bool> o_rst;
#ifndef NATIVE_SYSTEMC
  cynw_p2p<sc_dt::sc_uint<channel_bit>>::base_out o_rgb;
  cynw_p2p<sc_dt::sc_uint<channel_bit>>::base_in i_avg_rgb;

#else
  sc_fifo_out<sc_dt::sc_uint<channel_bit>> o_rgb;
  sc_fifo_in<sc_dt::sc_uint<channel_bit>> i_avg_rgb;
#endif

  SC_HAS_PROCESS(Testbench);

  Testbench(sc_module_name n);
  ~Testbench();

  int read_bmp(string infile_name);
  int write_bmp(string outfile_name);

  unsigned int get_width() { return width; }

  unsigned int get_height() { return height; }

  unsigned int get_width_bytes() { return width_bytes; }

  unsigned int get_bytes_per_pixel() { return bytes_per_pixel; }

  int *get_source_image() { return source_bitmap; }
  int *get_target_image() { return target_bitmap; }

private:
  unsigned int input_rgb_raw_data_offset;
  const unsigned int output_rgb_raw_data_offset;
  unsigned int width;
  unsigned int height;
  unsigned int width_bytes;
  unsigned char bits_per_pixel;
  unsigned short bytes_per_pixel;
  int carrier[8000];
  int T_carrier[8000];
  int well = 0;
  int *source_bitmap;
  int *target_bitmap;

  unsigned int n_txn;
  double throughput;
  unsigned int total_latency_mine;
  unsigned int avg_latency;
  sc_time max_txn_time;
  sc_time min_txn_time;
  sc_time total_txn_time;
  sc_time total_start_time;
  sc_time total_run_time;
  sc_time feed_time;
  sc_time latency_time;

  void do_sobel();
  void fetch_result();
  unsigned int clock_cycle(sc_time time);
  sc_fifo<sc_time> time_queue;
};
#endif
