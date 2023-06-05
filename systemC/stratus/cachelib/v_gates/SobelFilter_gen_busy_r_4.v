`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 19.16-s111_1
// Generated on: May 15 2023 05:59:45 CST (May 14 2023 21:59:45 UTC)

module SobelFilter_gen_busy_r_4(in1, in2, in3, out1);
  input in1, in2, in3;
  output [2:0] out1;
  wire in1, in2, in3;
  wire [2:0] out1;
  INVX1 g17(.A (out1[1]), .Y (out1[0]));
  NOR2BX1 g18(.AN (in1), .B (out1[2]), .Y (out1[1]));
  OA21X1 g19(.A0 (in1), .A1 (in3), .B0 (in2), .Y (out1[2]));
endmodule


