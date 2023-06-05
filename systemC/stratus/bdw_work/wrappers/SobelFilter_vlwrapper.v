/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* Verilog Verification wrapper module for the SobelFilter module.
*
* This module contains the followng items:
*	- A foreign module definition for use in instantiatin the type_wrapper module
*      which contains the BEH module instance.
*	- An instance of the type_wrapper foreign module.
*   - alwyas blocks each type_wrapper output.
*
****************************************************************************/

`timescale 1 ps / 1 ps

module SobelFilter_vlwrapper(
      i_clk,
       i_rst,
       i_rgb_busy,
       i_rgb_vld,
       i_rgb_data,
       o_avg_busy,
       o_avg_vld,
       o_avg_data

    );

`ifdef BDW_RTL_SobelFilter
	input i_clk;
	input i_rst;
	output i_rgb_busy;
	input i_rgb_vld;
	input [31:0] i_rgb_data;
	input o_avg_busy;
	output o_avg_vld;
	output [31:0] o_avg_data;


    // Instantiate the Verilog module 
    SobelFilter SobelFilter_v(
        .i_clk(i_clk),
         .i_rst(i_rst),
         .i_rgb_busy(i_rgb_busy),
         .i_rgb_vld(i_rgb_vld),
         .i_rgb_data(i_rgb_data),
         .o_avg_busy(o_avg_busy),
         .o_avg_vld(o_avg_vld),
         .o_avg_data(o_avg_data)

    );
`else
	input i_clk;
	input i_rst;
	output i_rgb_busy;
	reg i_rgb_busy;
	wire m_i_rgb_busy;
	input i_rgb_vld;
	input [31:0] i_rgb_data;
	input o_avg_busy;
	output o_avg_vld;
	reg o_avg_vld;
	wire m_o_avg_vld;
	output [31:0] o_avg_data;
	reg[31:0] o_avg_data;
	wire [31:0] m_o_avg_data;


    // Instantiate the Verilog module that instantiates the SystemC module
    SobelFilter_type_wrapper SobelFilter_sc(
        .i_clk(i_clk),
         .i_rst(i_rst),
         .i_rgb_busy(m_i_rgb_busy),
         .i_rgb_vld(i_rgb_vld),
         .i_rgb_data(i_rgb_data),
         .o_avg_busy(o_avg_busy),
         .o_avg_vld(m_o_avg_vld),
         .o_avg_data(m_o_avg_data)

    );

    // Always blocks for non-blocking assignments of type_wrapper outputs to
    // Verilog Verificatoin wrapper outputs.

    always @(m_i_rgb_busy)
     begin
      i_rgb_busy <= m_i_rgb_busy;
     end
    always @(m_o_avg_vld)
     begin
      o_avg_vld <= m_o_avg_vld;
     end
    always @(m_o_avg_data)
     begin
      o_avg_data <= m_o_avg_data;
     end


`endif

endmodule

// This is an internal module that instantiates the user's SystemC input module
// using the Incisive foreign module instantiation feature.
// The name of the module and the names of the inputs and outputs must match
// with those defined in the SystemC type_wrapper module

`ifndef BDW_RTL_SobelFilter

module SobelFilter_type_wrapper(
      i_clk,
       i_rst,
       i_rgb_busy,
       i_rgb_vld,
       i_rgb_data,
       o_avg_busy,
       o_avg_vld,
       o_avg_data

    ) (* integer foreign = "SystemC";
    *);

	input i_clk;
	input i_rst;
	output i_rgb_busy;
	input i_rgb_vld;
	input [31:0] i_rgb_data;
	input o_avg_busy;
	output o_avg_vld;
	output [31:0] o_avg_data;


endmodule

`endif
