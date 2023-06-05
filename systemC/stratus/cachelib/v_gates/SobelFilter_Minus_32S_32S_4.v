`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 19.16-s111_1
// Generated on: May 30 2023 21:54:31 CST (May 30 2023 13:54:31 UTC)

module SobelFilter_Minus_32S_32S_4(in1, out1);
  input [31:0] in1;
  output [31:0] out1;
  wire [31:0] in1;
  wire [31:0] out1;
  wire minus_20_2_n_0, minus_20_2_n_1, minus_20_2_n_2, minus_20_2_n_3,
       minus_20_2_n_4, minus_20_2_n_5, minus_20_2_n_6, minus_20_2_n_7;
  wire minus_20_2_n_8, minus_20_2_n_9, minus_20_2_n_10,
       minus_20_2_n_12, minus_20_2_n_13, minus_20_2_n_14,
       minus_20_2_n_15, minus_20_2_n_17;
  wire minus_20_2_n_18, minus_20_2_n_19, minus_20_2_n_21,
       minus_20_2_n_22, minus_20_2_n_23, minus_20_2_n_24,
       minus_20_2_n_27, minus_20_2_n_28;
  wire minus_20_2_n_29, minus_20_2_n_30, minus_20_2_n_31,
       minus_20_2_n_32, minus_20_2_n_33, minus_20_2_n_38,
       minus_20_2_n_39, minus_20_2_n_40;
  wire minus_20_2_n_41, minus_20_2_n_42, minus_20_2_n_43,
       minus_20_2_n_49, minus_20_2_n_50, minus_20_2_n_51,
       minus_20_2_n_52, minus_20_2_n_58;
  assign out1[0] = in1[0];
  XNOR2X1 minus_20_2_g592(.A (in1[31]), .B (minus_20_2_n_58), .Y
       (out1[31]));
  XNOR2X1 minus_20_2_g593(.A (in1[27]), .B (minus_20_2_n_50), .Y
       (out1[27]));
  XNOR2X1 minus_20_2_g594(.A (in1[23]), .B (minus_20_2_n_51), .Y
       (out1[23]));
  XNOR2X1 minus_20_2_g595(.A (in1[29]), .B (minus_20_2_n_49), .Y
       (out1[29]));
  XNOR2X1 minus_20_2_g596(.A (in1[25]), .B (minus_20_2_n_41), .Y
       (out1[25]));
  XNOR2X1 minus_20_2_g597(.A (in1[21]), .B (minus_20_2_n_40), .Y
       (out1[21]));
  XNOR2X1 minus_20_2_g598(.A (in1[19]), .B (minus_20_2_n_39), .Y
       (out1[19]));
  XNOR2X1 minus_20_2_g599(.A (in1[15]), .B (minus_20_2_n_33), .Y
       (out1[15]));
  XNOR2X1 minus_20_2_g600(.A (in1[13]), .B (minus_20_2_n_32), .Y
       (out1[13]));
  XNOR2X1 minus_20_2_g601(.A (in1[11]), .B (minus_20_2_n_31), .Y
       (out1[11]));
  XNOR2X1 minus_20_2_g602(.A (in1[17]), .B (minus_20_2_n_28), .Y
       (out1[17]));
  XNOR2X1 minus_20_2_g603(.A (in1[30]), .B (minus_20_2_n_52), .Y
       (out1[30]));
  NOR2BX1 minus_20_2_g604(.AN (minus_20_2_n_52), .B (in1[30]), .Y
       (minus_20_2_n_58));
  XNOR2X1 minus_20_2_g605(.A (in1[28]), .B (minus_20_2_n_38), .Y
       (out1[28]));
  XNOR2X1 minus_20_2_g606(.A (in1[7]), .B (minus_20_2_n_23), .Y
       (out1[7]));
  XNOR2X1 minus_20_2_g607(.A (in1[9]), .B (minus_20_2_n_0), .Y
       (out1[9]));
  XNOR2X1 minus_20_2_g608(.A (in1[26]), .B (minus_20_2_n_42), .Y
       (out1[26]));
  XNOR2X1 minus_20_2_g609(.A (in1[22]), .B (minus_20_2_n_43), .Y
       (out1[22]));
  NOR2BX1 minus_20_2_g610(.AN (minus_20_2_n_43), .B (in1[22]), .Y
       (minus_20_2_n_51));
  NOR2BX1 minus_20_2_g611(.AN (minus_20_2_n_42), .B (in1[26]), .Y
       (minus_20_2_n_50));
  NOR2BX1 minus_20_2_g612(.AN (minus_20_2_n_38), .B (in1[28]), .Y
       (minus_20_2_n_49));
  NOR3BX1 minus_20_2_g613(.AN (minus_20_2_n_38), .B (in1[29]), .C
       (in1[28]), .Y (minus_20_2_n_52));
  XNOR2X1 minus_20_2_g614(.A (in1[20]), .B (minus_20_2_n_30), .Y
       (out1[20]));
  XNOR2X1 minus_20_2_g615(.A (in1[14]), .B (minus_20_2_n_27), .Y
       (out1[14]));
  XNOR2X1 minus_20_2_g616(.A (in1[5]), .B (minus_20_2_n_19), .Y
       (out1[5]));
  XNOR2X1 minus_20_2_g617(.A (in1[18]), .B (minus_20_2_n_29), .Y
       (out1[18]));
  XOR2XL minus_20_2_g618(.A (in1[24]), .B (minus_20_2_n_1), .Y
       (out1[24]));
  NOR2X1 minus_20_2_g619(.A (in1[24]), .B (minus_20_2_n_1), .Y
       (minus_20_2_n_41));
  NOR2BX1 minus_20_2_g620(.AN (minus_20_2_n_30), .B (in1[20]), .Y
       (minus_20_2_n_40));
  NOR2BX1 minus_20_2_g621(.AN (minus_20_2_n_29), .B (in1[18]), .Y
       (minus_20_2_n_39));
  AND2XL minus_20_2_g622(.A (minus_20_2_n_5), .B (minus_20_2_n_30), .Y
       (minus_20_2_n_43));
  NOR2BX1 minus_20_2_g623(.AN (minus_20_2_n_2), .B (minus_20_2_n_1), .Y
       (minus_20_2_n_42));
  XOR2XL minus_20_2_g624(.A (in1[16]), .B (minus_20_2_n_21), .Y
       (out1[16]));
  XNOR2X1 minus_20_2_g625(.A (in1[3]), .B (minus_20_2_n_15), .Y
       (out1[3]));
  XOR2XL minus_20_2_g626(.A (in1[10]), .B (minus_20_2_n_24), .Y
       (out1[10]));
  XOR2XL minus_20_2_g627(.A (in1[12]), .B (minus_20_2_n_22), .Y
       (out1[12]));
  NOR2BX1 minus_20_2_g628(.AN (minus_20_2_n_27), .B (in1[14]), .Y
       (minus_20_2_n_33));
  NOR4BX1 minus_20_2_g629(.AN (minus_20_2_n_2), .B (minus_20_2_n_1), .C
       (in1[27]), .D (in1[26]), .Y (minus_20_2_n_38));
  NOR2X1 minus_20_2_g630(.A (in1[12]), .B (minus_20_2_n_22), .Y
       (minus_20_2_n_32));
  NOR2X1 minus_20_2_g631(.A (in1[10]), .B (minus_20_2_n_24), .Y
       (minus_20_2_n_31));
  NOR2BX1 minus_20_2_g632(.AN (minus_20_2_n_13), .B (minus_20_2_n_21),
       .Y (minus_20_2_n_30));
  NOR2BX1 minus_20_2_g633(.AN (minus_20_2_n_7), .B (minus_20_2_n_21),
       .Y (minus_20_2_n_29));
  NOR2X1 minus_20_2_g634(.A (in1[16]), .B (minus_20_2_n_21), .Y
       (minus_20_2_n_28));
  NOR2BX1 minus_20_2_g635(.AN (minus_20_2_n_10), .B (minus_20_2_n_22),
       .Y (minus_20_2_n_27));
  XNOR2X1 minus_20_2_g637(.A (in1[8]), .B (minus_20_2_n_17), .Y
       (out1[8]));
  XOR2XL minus_20_2_g638(.A (in1[6]), .B (minus_20_2_n_18), .Y
       (out1[6]));
  NAND2X1 minus_20_2_g639(.A (minus_20_2_n_8), .B (minus_20_2_n_17), .Y
       (minus_20_2_n_24));
  NOR2X1 minus_20_2_g641(.A (in1[6]), .B (minus_20_2_n_18), .Y
       (minus_20_2_n_23));
  NAND2X1 minus_20_2_g642(.A (minus_20_2_n_12), .B (minus_20_2_n_17),
       .Y (minus_20_2_n_22));
  NAND4XL minus_20_2_g644(.A (minus_20_2_n_17), .B (minus_20_2_n_12),
       .C (minus_20_2_n_3), .D (minus_20_2_n_10), .Y (minus_20_2_n_21));
  XNOR2X1 minus_20_2_g645(.A (in1[4]), .B (minus_20_2_n_14), .Y
       (out1[4]));
  NOR2BX1 minus_20_2_g646(.AN (minus_20_2_n_14), .B (in1[4]), .Y
       (minus_20_2_n_19));
  NAND2X1 minus_20_2_g647(.A (minus_20_2_n_4), .B (minus_20_2_n_14), .Y
       (minus_20_2_n_18));
  NOR4BBX1 minus_20_2_g649(.AN (minus_20_2_n_14), .BN (minus_20_2_n_4),
       .C (in1[7]), .D (in1[6]), .Y (minus_20_2_n_17));
  XNOR2X1 minus_20_2_g650(.A (in1[2]), .B (minus_20_2_n_6), .Y
       (out1[2]));
  NOR2BX1 minus_20_2_g651(.AN (minus_20_2_n_6), .B (in1[2]), .Y
       (minus_20_2_n_15));
  NOR3BX1 minus_20_2_g652(.AN (minus_20_2_n_6), .B (in1[3]), .C
       (in1[2]), .Y (minus_20_2_n_14));
  NOR4X1 minus_20_2_g653(.A (in1[19]), .B (in1[18]), .C (in1[17]), .D
       (in1[16]), .Y (minus_20_2_n_13));
  NOR4X1 minus_20_2_g654(.A (in1[11]), .B (in1[10]), .C (in1[9]), .D
       (in1[8]), .Y (minus_20_2_n_12));
  XOR2XL minus_20_2_g655(.A (in1[1]), .B (in1[0]), .Y (out1[1]));
  NOR2X1 minus_20_2_g656(.A (in1[13]), .B (in1[12]), .Y
       (minus_20_2_n_10));
  NOR2X1 minus_20_2_g657(.A (in1[23]), .B (in1[22]), .Y
       (minus_20_2_n_9));
  NOR2X1 minus_20_2_g658(.A (in1[9]), .B (in1[8]), .Y (minus_20_2_n_8));
  NOR2X1 minus_20_2_g659(.A (in1[17]), .B (in1[16]), .Y
       (minus_20_2_n_7));
  NOR2X1 minus_20_2_g660(.A (in1[1]), .B (in1[0]), .Y (minus_20_2_n_6));
  NOR2X1 minus_20_2_g661(.A (in1[21]), .B (in1[20]), .Y
       (minus_20_2_n_5));
  NOR2X1 minus_20_2_g662(.A (in1[5]), .B (in1[4]), .Y (minus_20_2_n_4));
  NOR2X1 minus_20_2_g663(.A (in1[15]), .B (in1[14]), .Y
       (minus_20_2_n_3));
  NOR2X1 minus_20_2_g664(.A (in1[25]), .B (in1[24]), .Y
       (minus_20_2_n_2));
  NAND4BX1 minus_20_2_g2(.AN (minus_20_2_n_21), .B (minus_20_2_n_13),
       .C (minus_20_2_n_9), .D (minus_20_2_n_5), .Y (minus_20_2_n_1));
  NOR2BX1 minus_20_2_g665(.AN (minus_20_2_n_17), .B (in1[8]), .Y
       (minus_20_2_n_0));
endmodule


