// Generated by stratus_hls 21.20-p100  (96289.240513)
// Tue May 30 22:52:21 2023
// from ../SobelFilter.cpp

`timescale 1ps / 1ps


module SobelFilter_RAM_28X32_1( DIN, CE, RW, in1, out1, clk );

    input [31:0] DIN;
    input CE;
    input RW;
    input [4:0] in1;
    input clk;
    output [31:0] out1;
    reg [31:0] out1;
    reg[31:0] mem[27:0];

    
always @(posedge clk)
      begin : SobelFilter_RAM_28X32_1_thread_1
        if (in1 < 5'd28) 
          begin
            if (CE) 
              begin
                if (RW) 
                  begin
                    mem[in1] = DIN;
                  end 
                else 
                  begin
                    out1 <= mem[in1];
                  end
              end 
            else 
              begin
                out1 <= 32'd0000000000;
              end
          end 
      end

endmodule

