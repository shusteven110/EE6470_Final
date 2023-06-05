`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Configured at: 21:44:38 CST (+0800), Tuesday 30 May 2023
    Configured on: ws26
    Configured by: m110061613 (m110061613)
    
    Created by: Stratus DpOpt 21.05.01 
*******************************************************************************/

module SobelFilter_GreaterThan_6Sx2S_1U_1 (
	in2,
	in1,
	out1
	); /* architecture "behavioural" */ 
input [5:0] in2;
input [1:0] in1;
output  out1;
wire  asc001;

assign asc001 = ((11'B10000000000 ^ {{5{in2[5]}}, in2})>(11'B10000000000 ^ {{9{in1[1]}}, in1}));

assign out1 = asc001;
endmodule

/* CADENCE  ubb2Sgs= : u9/ySxbfrwZIxEzHVQQV8Q== ** DO NOT EDIT THIS LINE ******/



