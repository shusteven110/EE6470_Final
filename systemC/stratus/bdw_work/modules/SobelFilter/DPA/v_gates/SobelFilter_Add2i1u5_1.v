`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 19.16-s111_1
// Generated on: May 30 2023 22:08:27 CST (May 30 2023 14:08:27 UTC)

module SobelFilter_Add2i1u5_1(in1, out1);
  input [4:0] in1;
  output [5:0] out1;
  wire [4:0] in1;
  wire [5:0] out1;
  wire inc_add_21_2_1_n_0, inc_add_21_2_1_n_1, inc_add_21_2_1_n_2,
       inc_add_21_2_1_n_3, inc_add_21_2_1_n_4, inc_add_21_2_1_n_5,
       inc_add_21_2_1_n_7, inc_add_21_2_1_n_8;
  INVX1 g2(.A (in1[0]), .Y (out1[0]));
  MXI2X1 inc_add_21_2_1_g46(.A (inc_add_21_2_1_n_3), .B (in1[3]), .S0
       (inc_add_21_2_1_n_8), .Y (out1[3]));
  MXI2X1 inc_add_21_2_1_g47(.A (inc_add_21_2_1_n_2), .B (in1[4]), .S0
       (inc_add_21_2_1_n_7), .Y (out1[4]));
  NOR3X1 inc_add_21_2_1_g48(.A (inc_add_21_2_1_n_2), .B
       (inc_add_21_2_1_n_5), .C (inc_add_21_2_1_n_4), .Y (out1[5]));
  MXI2XL inc_add_21_2_1_g49(.A (in1[2]), .B (inc_add_21_2_1_n_1), .S0
       (inc_add_21_2_1_n_4), .Y (out1[2]));
  NOR2X2 inc_add_21_2_1_g50(.A (inc_add_21_2_1_n_1), .B
       (inc_add_21_2_1_n_4), .Y (inc_add_21_2_1_n_8));
  NOR2X2 inc_add_21_2_1_g51(.A (inc_add_21_2_1_n_5), .B
       (inc_add_21_2_1_n_4), .Y (inc_add_21_2_1_n_7));
  MXI2XL inc_add_21_2_1_g52(.A (inc_add_21_2_1_n_0), .B (in1[1]), .S0
       (in1[0]), .Y (out1[1]));
  NAND2X8 inc_add_21_2_1_g53(.A (in1[3]), .B (in1[2]), .Y
       (inc_add_21_2_1_n_5));
  NAND2X8 inc_add_21_2_1_g54(.A (in1[1]), .B (in1[0]), .Y
       (inc_add_21_2_1_n_4));
  INVXL inc_add_21_2_1_g55(.A (in1[3]), .Y (inc_add_21_2_1_n_3));
  INVX1 inc_add_21_2_1_g56(.A (in1[4]), .Y (inc_add_21_2_1_n_2));
  INVX1 inc_add_21_2_1_g57(.A (in1[2]), .Y (inc_add_21_2_1_n_1));
  INVX1 inc_add_21_2_1_g58(.A (in1[1]), .Y (inc_add_21_2_1_n_0));
endmodule

