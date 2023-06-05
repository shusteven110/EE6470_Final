`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 19.16-s111_1
// Generated on: May 30 2023 21:44:38 CST (May 30 2023 13:44:38 UTC)

module SobelFilter_Sub_5Ux1U_5S_4(in2, in1, out1);
  input [4:0] in2;
  input in1;
  output [4:0] out1;
  wire [4:0] in2;
  wire in1;
  wire [4:0] out1;
  wire dec_sub_23_2_1_n_0, dec_sub_23_2_1_n_1, dec_sub_23_2_1_n_3,
       dec_sub_23_2_1_n_5, dec_sub_23_2_1_n_6;
  XNOR2X1 dec_sub_23_2_1_g49(.A (in2[3]), .B (dec_sub_23_2_1_n_6), .Y
       (out1[3]));
  XOR2XL dec_sub_23_2_1_g50(.A (in2[4]), .B (dec_sub_23_2_1_n_5), .Y
       (out1[4]));
  OAI2BB1X1 dec_sub_23_2_1_g51(.A0N (in2[2]), .A1N
       (dec_sub_23_2_1_n_3), .B0 (dec_sub_23_2_1_n_6), .Y (out1[2]));
  OR2XL dec_sub_23_2_1_g52(.A (in2[2]), .B (dec_sub_23_2_1_n_3), .Y
       (dec_sub_23_2_1_n_6));
  NOR3X1 dec_sub_23_2_1_g53(.A (dec_sub_23_2_1_n_3), .B (in2[3]), .C
       (in2[2]), .Y (dec_sub_23_2_1_n_5));
  OAI2BB1X1 dec_sub_23_2_1_g54(.A0N (in2[1]), .A1N
       (dec_sub_23_2_1_n_1), .B0 (dec_sub_23_2_1_n_3), .Y (out1[1]));
  OR2X1 dec_sub_23_2_1_g55(.A (in2[1]), .B (dec_sub_23_2_1_n_1), .Y
       (dec_sub_23_2_1_n_3));
  OAI2BB1X1 dec_sub_23_2_1_g56(.A0N (in2[0]), .A1N
       (dec_sub_23_2_1_n_0), .B0 (dec_sub_23_2_1_n_1), .Y (out1[0]));
  NAND2BX1 dec_sub_23_2_1_g57(.AN (in2[0]), .B (in1), .Y
       (dec_sub_23_2_1_n_1));
  INVXL dec_sub_23_2_1_g58(.A (in1), .Y (dec_sub_23_2_1_n_0));
endmodule


