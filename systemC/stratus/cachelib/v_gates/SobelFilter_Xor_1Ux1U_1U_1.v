`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 19.16-s111_1
// Generated on: May 15 2023 06:00:06 CST (May 14 2023 22:00:06 UTC)

module SobelFilter_Xor_1Ux1U_1U_1(in2, in1, out1);
  input in2, in1;
  output out1;
  wire in2, in1;
  wire out1;
  wire n_0;
  MXI2X1 g10(.A (n_0), .B (in2), .S0 (in1), .Y (out1));
  CLKINVX4 g11(.A (in2), .Y (n_0));
endmodule


