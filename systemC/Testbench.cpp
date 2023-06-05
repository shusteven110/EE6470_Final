#include <cassert>
#include <cstdio>
#include <cstdlib>
using namespace std;

#include "Testbench.h"
#include <esc.h>
/*unsigned char header[54] = {
    0x42,        // identity : B
    0x4d,        // identity : M
    0, 0, 0, 0,  // file size
    0, 0,        // reserved1
    0, 0,        // reserved2
    54, 0, 0, 0, // RGB data offset
    40, 0, 0, 0, // struct BITMAPINFOHEADER size
    0, 0, 0, 0,  // bmp width
    0, 0, 0, 0,  // bmp height
    1, 0,        // planes
    24, 0,       // bit per pixel
    0, 0, 0, 0,  // compression
    0, 0, 0, 0,  // data size
    0, 0, 0, 0,  // h resolution
    0, 0, 0, 0,  // v resolution
    0, 0, 0, 0,  // used colors
    0, 0, 0, 0   // important colors
};*/
int data_length = 8000;
Testbench::Testbench(sc_module_name n)
    : sc_module(n), output_rgb_raw_data_offset(54)
{
  SC_THREAD(do_sobel);
  sensitive << i_clk.pos();
  dont_initialize();
  SC_THREAD(fetch_result);
  sensitive << i_clk.pos();
  dont_initialize();
}

Testbench::~Testbench()
{
  // cout<< "Max txn time = " << max_txn_time << endl;
  // cout<< "Min txn time = " << min_txn_time << endl;
  // cout<< "Avg txn time = " << total_txn_time/n_txn << endl;
  cout << "Total run time = " << total_run_time << endl;
  cout << "Throught = " << throughput << " outputs/clock" << endl;
  cout << "Average latency = " << avg_latency << " clocks/output" << endl;
}

int Testbench::read_bmp(string infile_name)
{
  FILE *fp_s = NULL; // source file handler
  fp_s = fopen(infile_name.c_str(), "r");
  if (fp_s == NULL)
  {
    printf("fopen %s error\n", infile_name.c_str());
    return -1;
  }

  // // move offset to input_rgb_raw_data_offset to get RGB raw data
  // fseek(fp_s, input_rgb_raw_data_offset, SEEK_SET);

  source_bitmap = (int *)malloc(sizeof(int) * data_length);
  if (source_bitmap == NULL)
  {
    printf("malloc images_s error\n");
    return -1;
  }

  target_bitmap = (int *)malloc(sizeof(int) * data_length);
  if (target_bitmap == NULL)
  {
    printf("malloc target_bitmap error\n");
    return -1;
  }

  for (int i = 0; i < data_length; i++)
  {
    fscanf(fp_s, "%d", &source_bitmap[i]);
    carrier[i] = source_bitmap[i];
  }
  fclose(fp_s);

  return 0;
}

int Testbench::write_bmp(string outfile_name)
{
  FILE *fp_t = NULL;      // target file handler
  unsigned int file_size; // file size

  // fp_t = fopen(outfile_name.c_str(), "w");

  fp_t = fopen("out.txt", "w");
  if (fp_t == NULL)
  {
    return -1;
  }

  // write image

  for (int ll = 0; ll < data_length; ++ll)
  {
    fprintf(fp_t, "%d\n", T_carrier[ll]); 
  }

  // fwrite(target_bitmap, sizeof(int),
  //        (size_t)(long)4 * data_length, fp_t);

  fclose(fp_t);
  return 0;
}

void Testbench::do_sobel()
{
  unsigned int x, v, u;  // for loop counter
  unsigned char R, G, B; // color of R, G, B
  int adjustX, adjustY, xBound, yBound;

  n_txn = 0;
  max_txn_time = SC_ZERO_TIME;
  min_txn_time = SC_ZERO_TIME;
  total_txn_time = SC_ZERO_TIME;

#ifndef NATIVE_SYSTEMC
  o_rgb.reset();
#endif
  o_rst.write(false);
  wait(5);
  o_rst.write(true);
  wait(1);
  total_start_time = sc_time_stamp();

    for (int y = 0; y != data_length; y++)
    {
      feed_time = sc_time_stamp();
      time_queue.write(sc_time_stamp());


      // sc_dt::sc_uint<channel_bit> rgb_temp;
      int rgb_temp;
      rgb_temp = carrier[y];


#ifndef NATIVE_SYSTEMC
      o_rgb.put(rgb_temp);
#else
      o_rgb.write(rgb_temp);
#endif
      wait();
    }
}

void Testbench::fetch_result()
{
  unsigned int x, y; // for loop counter
  int total;
  unsigned long total_latency = 0;
  int total_count;
  total_latency_mine = 0;
#ifndef NATIVE_SYSTEMC
  i_avg_rgb.reset();
#endif
  wait(5);
  wait(1);
  for (y = 0; y != data_length; ++y)
  {

#ifndef NATIVE_SYSTEMC
    total = i_avg_rgb.get();
    latency_time = sc_time_stamp() - feed_time; //  ns/output
    unsigned int latency = clock_cycle(sc_time_stamp() - time_queue.read());
    total_latency_mine += clock_cycle(latency_time); //  clk/output
    total_latency += latency;
#else
    total = i_avg_rgb.read();
#endif

    // total_count += 1;
    //*(target_bitmap + 4 * y) = total;
    T_carrier[y] = total;
  }
  total_count = data_length;
  total_run_time = sc_time_stamp() - total_start_time;
  throughput = (double)total_count / total_run_time.to_seconds() / 100000000;
  avg_latency = total_latency_mine;

  unsigned int average_latency = (total_latency / total_count) + 1;
  esc_log_latency("filter", average_latency, "average_latency");
  cout << "Testbench sink thread read 65536 values. Average latency " << average_latency << "." << endl;
  sc_stop();
}

unsigned int Testbench::clock_cycle(sc_time time)
{
  sc_clock *clk_p = dynamic_cast<sc_clock *>(i_clk.get_interface());
  sc_time clock_period = clk_p->period(); // get period from the sc_clock object.
  return (unsigned int)(time / clock_period);
}