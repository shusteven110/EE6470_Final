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
/*111*/

SobelFilter::~SobelFilter() {}
const int ORDER = 28;
/*222*/
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
  /*參數區*/
  int filter_coeffs[ORDER] = {9	,-48	,-22	,30,	37,	-30,	-65,	20,	105,	11,	-173,	-98,	367,	846,	846,	367,	-98,	-173,	11,	105,	20,	-65,	-30,	37,	30,	-22,	-48,	9};

  int shift_reg[ORDER];
  int filtered_output = 0;

  /*初始化*/
  for (int t = 0; t != 28; t++)
  {
    shift_reg[t] = 0;
  }

  // int width = i_img_width.read() * 4;
  // cout << "Now at width " << width << endl;

  /*3333*/
while_1:
  while (true)
  {
loop_1:
    filtered_output = 0;
    for (int i = ORDER - 1; i > 0; --i)
    {
      shift_reg[i] = shift_reg[i - 1];
      filtered_output += shift_reg[i] * filter_coeffs[i];
      // printf("%d\n", filtered_output);
      wait();
    }
    /*從channel拿資料*/
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
    filtered_output += shift_reg[0] * filter_coeffs[0];
    
    sc_dt::sc_uint<32> out_avg_all;
    out_avg_all = filtered_output;
    // printf("%d\n", filtered_output);
#ifndef NATIVE_SYSTEMC
    {
      HLS_DEFINE_PROTOCOL("output");
      o_avg.put(filtered_output);
    }
#else
    o_avg.write(out_avg_all);
#endif
    wait();
  }
}
