`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 19.16-s111_1
// Generated on: May 30 2023 21:44:30 CST (May 30 2023 13:44:30 UTC)

module SobelFilter_Sub_5Ux1U_6S_4(in2, in1, out1);
  input [4:0] in2;
  input in1;
  output [5:0] out1;
  wire [4:0] in2;
  wire in1;
  wire [5:0] out1;
  wire dec_sub_23_2_1_n_0, dec_sub_23_2_1_n_1, dec_sub_23_2_1_n_2,
       dec_sub_23_2_1_n_4, dec_sub_23_2_1_n_6, dec_sub_23_2_1_n_7,
       dec_sub_23_2_1_n_10;
  XNOR2X1 dec_sub_23_2_1_g53(.A (in2[3]), .B (dec_sub_23_2_1_n_7), .Y
       (out1[3]));
  INVX1 dec_sub_23_2_1_g54(.A (dec_sub_23_2_1_n_10), .Y (out1[4]));
  ADDHX1 dec_sub_23_2_1_g55(.A (dec_sub_23_2_1_n_0), .B
       (dec_sub_23_2_1_n_6), .CO (out1[5]), .S (dec_sub_23_2_1_n_10));
  OAI2BB1X1 dec_sub_23_2_1_g56(.A0N (in2[2]), .A1N
       (dec_sub_23_2_1_n_4), .B0 (dec_sub_23_2_1_n_7), .Y (out1[2]));
  OR2XL dec_sub_23_2_1_g57(.A (in2[2]), .B (dec_sub_23_2_1_n_4), .Y
       (dec_sub_23_2_1_n_7));
  NOR3X1 dec_sub_23_2_1_g58(.A (dec_sub_23_2_1_n_4), .B (in2[3]), .C
       (in2[2]), .Y (dec_sub_23_2_1_n_6));
  OAI2BB1X1 dec_sub_23_2_1_g59(.A0N (in2[1]), .A1N
       (dec_sub_23_2_1_n_2), .B0 (dec_sub_23_2_1_n_4), .Y (out1[1]));
  OR2X1 dec_sub_23_2_1_g60(.A (in2[1]), .B (dec_sub_23_2_1_n_2), .Y
       (dec_sub_23_2_1_n_4));
  OAI2BB1X1 dec_sub_23_2_1_g61(.A0N (in2[0]), .A1N
       (dec_sub_23_2_1_n_1), .B0 (dec_sub_23_2_1_n_2), .Y (out1[0]));
  NAND2BX1 dec_sub_23_2_1_g62(.AN (in2[0]), .B (in1), .Y
       (dec_sub_23_2_1_n_2));
  INVXL dec_sub_23_2_1_g63(.A (in1), .Y (dec_sub_23_2_1_n_1));
  INVX1 dec_sub_23_2_1_g64(.A (in2[4]), .Y (dec_sub_23_2_1_n_0));
endmodule


