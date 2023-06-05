	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
		if ( SobelFilter0 != NULL ) {
			esc_trace_signal( &SobelFilter0->i_clk, ( std::string(name()) + std::string( ".SobelFilter.i_clk" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SobelFilter0->i_rst, ( std::string(name()) + std::string( ".SobelFilter.i_rst" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SobelFilter0->i_rgb.busy, ( std::string(name()) + std::string( ".SobelFilter.i_rgb.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SobelFilter0->i_rgb.vld, ( std::string(name()) + std::string( ".SobelFilter.i_rgb.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SobelFilter0->i_rgb.data, ( std::string(name()) + std::string( ".SobelFilter.i_rgb.data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SobelFilter0->o_avg.busy, ( std::string(name()) + std::string( ".SobelFilter.o_avg.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SobelFilter0->o_avg.vld, ( std::string(name()) + std::string( ".SobelFilter.o_avg.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SobelFilter0->o_avg.data, ( std::string(name()) + std::string( ".SobelFilter.o_avg.data" ) ).c_str(), esc_trace_vcd );
		}
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		if ( SobelFilter0 != NULL ) {
			esc_trace_signal( &SobelFilter0->i_clk, ( std::string(name()) + std::string( ".SobelFilter.i_clk" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SobelFilter0->i_rst, ( std::string(name()) + std::string( ".SobelFilter.i_rst" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SobelFilter0->i_rgb.busy, ( std::string(name()) + std::string( ".SobelFilter.i_rgb.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SobelFilter0->i_rgb.vld, ( std::string(name()) + std::string( ".SobelFilter.i_rgb.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SobelFilter0->i_rgb.data, ( std::string(name()) + std::string( ".SobelFilter.i_rgb.data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SobelFilter0->o_avg.busy, ( std::string(name()) + std::string( ".SobelFilter.o_avg.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SobelFilter0->o_avg.vld, ( std::string(name()) + std::string( ".SobelFilter.o_avg.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SobelFilter0->o_avg.data, ( std::string(name()) + std::string( ".SobelFilter.o_avg.data" ) ).c_str(), esc_trace_fsdb );
		}
	}
