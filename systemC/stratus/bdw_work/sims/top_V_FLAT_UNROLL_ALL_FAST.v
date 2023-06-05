//
// Top-level Verilog module

// One of these modules is created for each testcase that involves
// co-simulation.  This one is for the 'V_FLAT_UNROLL_ALL_FAST' testcase.
// The top-level module contains:
//	- An instances of a co-simulation wrapper module for each instance
//	  simulating in Verilog.
//	- Hub initialization calls that load the shared library for the
//	  simulation.
//
// You can add any other legal Verilog to this template file, and it appear in
// the verilog module.

`timescale 1 ps / 1 ps

module top;

	// RTL wrapper instances for cosim.
	SobelFilter_cosim SobelFilter0();


	integer n_cur_time;
	initial n_cur_time=0;
	reg [63:0] cur_time;
	initial cur_time=0;

	`include "hub.v"

    reg[2048:0] dump_file;

	// Load library and begin co-simulation.
	initial begin

        // For gate-level simulations we back-annotate the instances with delays
        // from the SDF file
        

		// Open the trace file if that's appropriate.
		
			$value$plusargs("BDW_VLOG_DUMPFILE+%s",dump_file);
		if ( hubCurrentProjectDoesTrace( hub_trace_vcd ) )
			$dumpfile( dump_file );
		if ( hubCurrentProjectDoesTrace( hub_trace_vcd ) ) begin
		$dumpvars( 0, SobelFilter0.i_clk );
		$dumpvars( 0, SobelFilter0.i_rst );
		$dumpvars( 0, SobelFilter0.i_rgb_busy );
		$dumpvars( 0, SobelFilter0.i_rgb_vld );
		$dumpvars( 0, SobelFilter0.i_rgb_data );
		$dumpvars( 0, SobelFilter0.o_avg_busy );
		$dumpvars( 0, SobelFilter0.o_avg_vld );
		$dumpvars( 0, SobelFilter0.o_avg_data );
			$dumpvars( 4, SobelFilter0.SobelFilter0 );
		end


		// If the SystemC shared library will be loaded using +qbSetOption+libdef=libname.so
		// from the Verilog simulator's command line, the following line can be left
		// out.  In order to load the shared library directly from Verilog, uncomment
		// the following line using either ther automatically generated SIM_EXEC string,
		// or a hard-coded string giving the path to the shared library.
		//hubLoadLibrary( "bdw_work/sims/V_FLAT_UNROLL_ALL_FAST/sim_V_FLAT_UNROLL_ALL_FAST.so", "" );

		// Begin a co-simulation.
		// This task returns after esc_end_cosim() is called from SystemC.
		hubStartCosim;
		#100 $stop;
	end
endmodule

//
// The following wrapper modules are used only for NCSim cosims.
//

`ifdef BDW_NCSC

module SobelFilter_nc_cosim(i_clk,
 i_rst,
 i_rgb_busy,
 i_rgb_vld,
 i_rgb_data,
 o_avg_busy,
 o_avg_vld,
 o_avg_data
);

input i_clk;
wire i_clk;
input i_rst;
wire i_rst;
output i_rgb_busy;
wire i_rgb_busy;
input i_rgb_vld;
wire i_rgb_vld;
input i_rgb_data;
wire[31:0] i_rgb_data;
input o_avg_busy;
wire o_avg_busy;
output o_avg_vld;
wire o_avg_vld;
output o_avg_data;
wire[31:0] o_avg_data;

	reg i_rgb_vld_delayed;
	always @ (i_rgb_vld) i_rgb_vld_delayed <= i_rgb_vld;
	reg [31:0]i_rgb_data_delayed;
	always @ (i_rgb_data) i_rgb_data_delayed <= i_rgb_data;
	reg o_avg_busy_delayed;
	always @ (o_avg_busy) o_avg_busy_delayed <= o_avg_busy;
SobelFilter SobelFilter0( 	.i_clk(i_clk),
	.i_rst(i_rst),
	.i_rgb_busy(i_rgb_busy),
	.i_rgb_vld(i_rgb_vld_delayed),
	.i_rgb_data(i_rgb_data_delayed),
	.o_avg_busy(o_avg_busy_delayed),
	.o_avg_vld(o_avg_vld),
	.o_avg_data(o_avg_data)
);

   `include "hub.v"

	reg[2048:0] dump_file;

   initial begin


	$value$plusargs("BDW_VLOG_DUMPFILE+%s",dump_file);
if ( hubCurrentProjectDoesTrace( hub_trace_vcd ) )
	$dumpfile( dump_file );
if ( hubCurrentProjectDoesTrace( hub_trace_vcd ) ) begin
$dumpvars( 0, SobelFilter0.i_clk );
$dumpvars( 0, SobelFilter0.i_rst );
$dumpvars( 0, SobelFilter0.i_rgb_busy );
$dumpvars( 0, SobelFilter0.i_rgb_vld );
$dumpvars( 0, SobelFilter0.i_rgb_data );
$dumpvars( 0, SobelFilter0.o_avg_busy );
$dumpvars( 0, SobelFilter0.o_avg_vld );
$dumpvars( 0, SobelFilter0.o_avg_data );
	$dumpvars( 4, SobelFilter0 );
end
   end

endmodule


`endif


