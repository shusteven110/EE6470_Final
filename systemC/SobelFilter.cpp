#include <cmath>
#include <vector>

#ifndef NATIVE_SYSTEMC
#include "stratus_hls.h"
#endif

#include "SobelFilter.h"
#include <algorithm>
#include <iostream>

using namespace std;
/*11*/
SobelFilter::SobelFilter(sc_module_name n) : sc_module(n)
{
#ifndef NATIVE_SYSTEMC
  // HLS_FLATTEN_ARRAY(data_buffer);
  // HLS_FLATTEN_ARRAY(box);
  // HLS_FLATTEN_ARRAY(center);
  // HLS_FLATTEN_ARRAY(result);
#endif
  SC_THREAD(do_filter);
  sensitive << i_clk.pos();
  dont_initialize();
  reset_signal_is(i_rst, false);
#ifndef NATIVE_SYSTEMC
  i_rgb.clk_rst(i_clk, i_rst);
  o_avg.clk_rst(i_clk, i_rst);
#endif
}


SobelFilter::~SobelFilter() {}
const int ORDER = 28;

void SobelFilter::do_filter()
{
  {
#ifndef NATIVE_SYSTEMC
    HLS_DEFINE_PROTOCOL("main_reset");
    i_rgb.reset();
    o_avg.reset();
#endif
    wait();
  }
  int params[ORDER] = {9	,-48	,-22	,30,	37,	-30,	-65,	20,	105,	11,	-173,	-98,	367,	846,	846,	367,	-98,	-173,	11,	105,	20,	-65,	-30,	37,	30,	-22,	-48,	9};
  sc_dt::sc_uint<32> output_fifo;
  int shift_reg[ORDER];
  int output = 0;

  for (int t = 0; t != ORDER; t++)
  {
    shift_reg[t] = 0;
  }
while_1:
  while (true)
  {
loop_1:
    output = 0;
    for (int i = 0; i < ORDER; i++)
    {
      reg[i] = reg[i - 1];
      output += reg[i] * parameter[i];
      wait();
    }
    int rgb = 0;
#ifndef NATIVE_SYSTEMC
    {
      HLS_DEFINE_PROTOCOL("input");
      rgb = i_rgb.get();
      wait();
    }
#else
    rgb = i_rgb.read();
#endif
    shift_reg[0] = rgb;
    output += shift_reg[0] * params[0];
    
    output_fifo = output;
#ifndef NATIVE_SYSTEMC
    {
      HLS_DEFINE_PROTOCOL("output");
      o_avg.put(output);
    }
#else
    o_avg.write(output_fifo);
#endif
    wait();
  }
}
