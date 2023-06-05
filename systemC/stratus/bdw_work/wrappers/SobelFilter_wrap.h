/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _SOBELFILTER_WRAP_INCLUDED_
#define _SOBELFILTER_WRAP_INCLUDED_

#ifndef BDW_NO_SUBMOD_WRAPPERS


/* Save ioConfig define values for parent module and define those for this module's ioConfigs. */


#if defined(STRATUS_VLG) 

#include <systemc.h>

#define SobelFilter_wrapper SobelFilter

/* This is the section that is seen during processing by stratus_vlg of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(SobelFilter)
{
public:
	sc_in< bool > i_clk;
	sc_in< bool > i_rst;
	sc_out< bool > i_rgb_busy;
	sc_in< bool > i_rgb_vld;
	sc_in< sc_uint< 32 > > i_rgb_data;
	sc_in< bool > o_avg_busy;
	sc_out< bool > o_avg_vld;
	sc_out< sc_uint< 32 > > o_avg_data;

	SC_CTOR(SobelFilter);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by stratus_hls or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "hls_enums.h"
#include "cynw_p2p.h"


#define SobelFilter_wrapper SobelFilter

/* Only port declarations are required for nested modules.
 */
SC_MODULE(SobelFilter)
{
public:
	sc_in< bool > i_clk;
	sc_in< bool > i_rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > i_rgb;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > o_avg;


	SC_HAS_PROCESS(SobelFilter);
    	SobelFilter_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("SobelFilter")) );
};

#else

#include <esc.h>


/* This is the section seen during processing by gcc either when the module
 * itself is compiled, or when a module that instantiates it is compiled.
 */

struct SobelFilter;
struct SobelFilter_cosim;
struct SobelFilter_rtl;

#include "hls_enums.h"
#include "cynw_p2p.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(SobelFilter_wrapper)
{
public:

	sc_in< bool > i_clk;
	sc_in< bool > i_rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > i_rgb;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > o_avg;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };
	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(SobelFilter_wrapper);

    	SobelFilter_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("SobelFilter")) )
		: sc_module(name)
		  ,i_clk("i_clk")
		  	,i_rst("i_rst")
		  	,i_rgb("i_rgb")
		  	,o_avg("o_avg")
		  	

          		  ,SobelFilter0(0), SobelFilter_cosim0(0), SobelFilter_rtl0(0)
		

    {
        InitInstances( );
		InitThreads();
    }


    // destructor
    ~SobelFilter_wrapper()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( SobelFilter_wrapper::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( SobelFilter_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( SobelFilter_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( SobelFilter_wrapper::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    
        
#ifdef SobelFilter_INTERNAL
	SobelFilter* behModule() { return SobelFilter0; }
#else
	SobelFilter* behModule() { return SobelFilter0; }
#endif
	SobelFilter_cosim* cosimModule() { return SobelFilter_cosim0; }
    	SobelFilter_rtl* rtlModule() { return SobelFilter_rtl0; }

#ifdef SobelFilter_INTERNAL
	SobelFilter* SobelFilter0;
#else
	SobelFilter* SobelFilter0;
#endif
	SobelFilter_cosim* SobelFilter_cosim0;
	SobelFilter_rtl* SobelFilter_rtl0;
	};

// Declaration of wrapper with RTL level ports

SC_MODULE(SobelFilter_wrapper_r)
{
public:

	sc_in< bool > i_clk;
	sc_in< bool > i_rst;
	sc_out< bool > i_rgb_busy;
	sc_in< bool > i_rgb_vld;
	sc_in< sc_uint< 32 > > i_rgb_data;
	sc_in< bool > o_avg_busy;
	sc_out< bool > o_avg_vld;
	sc_out< sc_uint< 32 > > o_avg_data;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };

	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(SobelFilter_wrapper_r);

	SobelFilter_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("SobelFilter")) )
		: sc_module(name)
		  ,i_clk("i_clk")
		  	,i_rst("i_rst")
		  	,i_rgb_busy("i_rgb_busy")
		  	,i_rgb_vld("i_rgb_vld")
		  	,i_rgb_data("i_rgb_data")
		  	,o_avg_busy("o_avg_busy")
		  	,o_avg_vld("o_avg_vld")
		  	,o_avg_data("o_avg_data")
		  	

          		  ,SobelFilter0(0), SobelFilter_cosim0(0), SobelFilter_rtl0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~SobelFilter_wrapper_r()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( SobelFilter_wrapper_r::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( SobelFilter_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( SobelFilter_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( SobelFilter_wrapper_r::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
	
#ifdef SobelFilter_INTERNAL
	SobelFilter* behModule() { return SobelFilter0; }
#else
	SobelFilter* behModule() { return SobelFilter0; }
#endif
	SobelFilter_cosim* cosimModule() { return SobelFilter_cosim0; }
		SobelFilter_rtl* rtlModule() { return SobelFilter_rtl0; }

protected:
#ifdef SobelFilter_INTERNAL
	SobelFilter* SobelFilter0;
#else
	SobelFilter* SobelFilter0;
#endif
	SobelFilter_cosim* SobelFilter_cosim0;
	SobelFilter_rtl* SobelFilter_rtl0;
	};

#endif

/* Restore ioConfig define values for parent module. */


#else /* BDW_NO_SUBMOD_WRAPPERS */

#define SobelFilter_wrapper SobelFilter
#include "SobelFilter.h"

#endif /* BDW_NO_SUBMOD_WRAPPERS */

#endif /*  */
