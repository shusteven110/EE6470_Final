#include "string"
#include "string.h"
#include "cassert"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include <iostream>

unsing namespace std;
unsigned char header[54] = {
    0x42,          // identity : B
    0x4d,          // identity : M
    0,    0, 0, 0, // file size
    0,    0,       // reserved1
    0,    0,       // reserved2
    54,   0, 0, 0, // RGB data offset
    40,   0, 0, 0, // struct BITMAPINFOHEADER size
    0,    0, 0, 0, // bmp width
    0,    0, 0, 0, // bmp height
    1,    0,       // planes
    24,   0,       // bit per pixel
    0,    0, 0, 0, // compression
    0,    0, 0, 0, // data size
    0,    0, 0, 0, // h resolution
    0,    0, 0, 0, // v resolution
    0,    0, 0, 0, // used colors
    0,    0, 0, 0  // important colors
};

union word {
  int sint;
  unsigned int uint;
  unsigned char uc[4];
};

unsigned int input_rgb_raw_data_offset;
const unsigned int output_rgb_raw_data_offset=54;
int width;
int height;
const int data_length = 8000;
unsigned int width_bytes;
unsigned char bits_per_pixel;
unsigned short bytes_per_pixel;
int *source_bitmap;
int *target_bitmap;
const int WHITE = 255;
const int BLACK = 0;
const int THRESHOLD = 90;
unsigned char carrier[data_length];
unsigned char T_carrier[data_length];

// Sobel Filter ACC
static char* const SOBELFILTER_START_ADDR = reinterpret_cast<char* const>(0x73000000);
static char* const SOBELFILTER_READ_ADDR  = reinterpret_cast<char* const>(0x73000004);

// DMA 
static volatile uint32_t * const DMA_SRC_ADDR  = (uint32_t * const)0x70000000;
static volatile uint32_t * const DMA_DST_ADDR  = (uint32_t * const)0x70000004;
static volatile uint32_t * const DMA_LEN_ADDR  = (uint32_t * const)0x70000008;
static volatile uint32_t * const DMA_OP_ADDR   = (uint32_t * const)0x7000000C;
static volatile uint32_t * const DMA_STAT_ADDR = (uint32_t * const)0x70000010;
static const uint32_t DMA_OP_MEMCPY = 1;

bool _is_using_dma = true;
int read_bmp(std::string infile_name) {
FILE *fp_s = NULL; // source file handler
  fp_s = fopen(infile_name.c_str(), "r");
  if (fp_s == NULL)
  {
    return -1;
  }

  // // move offset to input_rgb_raw_data_offset to get RGB raw data
  // fseek(fp_s, input_rgb_raw_data_offset, SEEK_SET);

  source_bitmap = (int *)malloc(sizeof(unsigned char) * data_length);
  if (source_bitmap == NULL)
  {
    return -1;
  }
  target_bitmap = (int *)malloc(sizeof(int) * data_length);
  if (target_bitmap == NULL)
  {
    return -1;
  }

  for (int i = 0; i < data_length; i++)
  {
    fscanf(fp_s, "%d", &source_bitmap[i]);
    carrier[i] = source_bitmap[i];
    printf("%d\n", source_bitmap[i]);
  }
  fclose(fp_s);
  return 0;
}

int write_bmp(std::string outfile_name) {
  FILE *fp_t = NULL;      // target file handler
  unsigned int file_size; // file size

  // fp_t = fopen(outfile_name.c_str(), "w");
  // printf("open txt\n\n\n\n\n\n\n\n\n\n\n\nn\\n\n\nn\n\n\\n");
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

void write_data_to_ACC(char* ADDR, unsigned char* buffer, int len){
  if(_is_using_dma){  
    // Using DMA 
    *DMA_SRC_ADDR = (uint32_t)(buffer);
    *DMA_DST_ADDR = (uint32_t)(ADDR);
    *DMA_LEN_ADDR = len;
    *DMA_OP_ADDR  = DMA_OP_MEMCPY;
  }else{
    // Directly Send
    memcpy(ADDR, buffer, sizeof(unsigned char)*len);
  }
}
void read_data_from_ACC(char* ADDR, unsigned char* buffer, int len){
  if(_is_using_dma){
    // Using DMA 
    *DMA_SRC_ADDR = (uint32_t)(ADDR);
    *DMA_DST_ADDR = (uint32_t)(buffer);
    *DMA_LEN_ADDR = len;
    *DMA_OP_ADDR  = DMA_OP_MEMCPY;
  }else{
    // Directly Read
    memcpy(buffer, ADDR, sizeof(unsigned char)*len);
  }
}

int main(int argc, char *argv[]) {

  read_bmp("data.txt");
  printf("======================================\n");
  printf("\t  Reading from array\n");
  printf("======================================\n");
	printf(" input_rgb_raw_data_offset\t= %d\n", input_rgb_raw_data_offset);
	printf(" width\t\t\t\t= %d\n", width);
	printf(" height\t\t\t\t= %d\n", height);
	printf(" bytes_per_pixel\t\t= %d\n",bytes_per_pixel);
  printf("======================================\n");

  unsigned char  buffer[4] = {0};
  word data;
  int total;
  printf("Start processing...(%d, %d)\n", width, height);

  int total_latency=0;
  for(int i = 0; i < data_length; i++){
      buffer[0] = carrier[i];
      buffer[1] = 0;
      buffer[2] = 0;
      buffer[3] = 0;
          
      write_data_to_ACC(SOBELFILTER_START_ADDR, buffer, 4);
      read_data_from_ACC(SOBELFILTER_READ_ADDR, buffer, 4);
      memcpy(data.uc, buffer, 4);
      // print the buffer
      
      // total = (data).sint;
      // print all the binary bits of total
      
      // if (total - THRESHOLD >= 0) {
      //   // black
      //   *(target_bitmap + bytes_per_pixel * (width * i + j) + 2) = BLACK;
      //   *(target_bitmap + bytes_per_pixel * (width * i + j) + 1) = BLACK;
      //   *(target_bitmap + bytes_per_pixel * (width * i + j) + 0) = BLACK;
      // } else {
      //   // white
      //   *(target_bitmap + bytes_per_pixel * (width * i + j) + 2) = WHITE;
      //   *(target_bitmap + bytes_per_pixel * (width * i + j) + 1) = WHITE;
      //   *(target_bitmap + bytes_per_pixel * (width * i + j) + 0) = WHITE;
      // }

    // total_count += 1;
    //*(target_bitmap + 4 * y) = total;
      T_carrier[i] = total;
      T_carrier[i] = data.uc[0];
      // Print data.uc[0], data.uc[1], data.uc[2]
      // printf("data.uc[0] = %d, data.uc[1] = %d, data.uc[2] = %d\n", data.uc[0], data.uc[1], data.uc[2]);

      latency_time = sc_time_stamp() - feed_time; //  ns/output
      unsigned int latency = clock_cycle(sc_time_stamp() - time_queue.read());
      total_latency += clock_cycle(latency_time); //  clk/output
    }
    cout << "Average latency = " << total_latency << " clocks/output" << std::endl;
  write_bmp("output.txt");
}
