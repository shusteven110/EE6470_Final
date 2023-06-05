// Generated by stratus_hls 21.20-p100  (96289.240513)
// Tue May 30 22:08:43 2023
// from ../SobelFilter.cpp

`timescale 1ps / 1ps


module SobelFilter( i_clk, i_rst, i_rgb_busy, i_rgb_vld, i_rgb_data, o_avg_busy, o_avg_vld, o_avg_data );

    input i_clk;
    input i_rst;
    input i_rgb_vld;
    input [31:0] i_rgb_data;
    input o_avg_busy;
    output i_rgb_busy;
    output o_avg_vld;
    output [31:0] o_avg_data;
    reg [31:0] o_avg_data;
    reg o_avg_m_req_m_prev_trig_req;
    reg o_avg_m_unacked_req;
    wire SobelFilter_Xor_1Ux1U_1U_1_1_out1;
    wire SobelFilter_Or_1Ux1U_1U_4_2_out1;
    reg SobelFilter_N_Muxb_1_2_8_4_4_out1;
    reg i_rgb_m_unvalidated_req;
    wire SobelFilter_gen_busy_r_4_14_gnew_req;
    wire SobelFilter_gen_busy_r_4_14_gdiv;
    wire SobelFilter_gen_busy_r_4_14_i_rgb_gen_busy_i_rgb_m_data_is_invalid_next;
    reg[3:0] global_state_next;
    wire[31:0] SobelFilter_Add_32Ux32U_32U_4_11_in2;
    /*signed*/wire[63:0] t_60;
    reg gs_ctrl_do_filter_h8;
    reg[4:0] SobelFilter_Sub_5Ux1U_6S_4_7_in2;
    reg gs_ctrl_do_filter_h18;
    reg[1:0] gs_ctrl_do_filter_h27;
    reg[1:0] gs_ctrl_do_filter_h17f;
    reg[1:0] gs_ctrl_do_filter_h24;
    reg[1:0] gs_ctrl_do_filter_h172;
    /*signed*/wire[31:0] SobelFilter_Add2Mul2s32s32s32_4_10_out1;
    reg[31:0] s_reg_5;
    /*signed*/wire[5:0] SobelFilter_Sub_5Ux1U_6S_4_7_out1;
    wire[5:0] SobelFilter_Add2i1u5_4_6_out1;
    reg[5:0] s_reg_10;
    wire SobelFilter_And_1Ux1U_1U_4_12_out1;
    wire[2:0] SobelFilter_gen_busy_r_4_14_out1;
    wire SobelFilter_Not_1U_1U_1_3_out1;
    reg o_avg_m_req_m_trig_req;
    wire SobelFilter_Gti0s6_4_9_out1;
    reg[3:0] global_state;
    reg i_rgb_m_busy_req_0;
    wire[31:0] SobelFilter_Add_32Ux32U_32U_4_11_out1;
    reg stall0;
    reg filter_coeffs_CE;
    wire[4:0] filter_coeffs_in1;
    wire[31:0] filter_coeffs_out1;
    reg[31:0] shift_reg_DIN;
    reg shift_reg_CE;
    reg shift_reg_RW;
    reg[4:0] shift_reg_in1;
    wire[31:0] shift_reg_out1;

    SobelFilter_RAM_28X32_1 shift_reg( 
                              .DIN( shift_reg_DIN ),
                              .CE( shift_reg_CE ),
                              .RW( shift_reg_RW ),
                              .in1( shift_reg_in1 ),
                              .out1( shift_reg_out1 ),
                              .clk( i_clk )
                            );
    SobelFilter_ROM_28X32_filter_coeffs filter_coeffs( 
                                          .CE( filter_coeffs_CE ),
                                          .in1( filter_coeffs_in1 ),
                                          .out1( filter_coeffs_out1 ),
                                          .clk( i_clk )
                                        );
    
    // resource: regr_en_32
    always @(posedge i_clk)
      begin : drive_o_avg_data
        case (stall0) 
          1'b1: 
            begin
            end
          default: 
            begin
              o_avg_data <= SobelFilter_Add_32Ux32U_32U_4_11_out1;
            end
        endcase
      end
    
    // resource: mux_1bx2i2c
    // resource: regr_en_ss_1
    always @(posedge i_clk)
      begin : drive_i_rgb_m_busy_req_0
        if (i_rst == 1'b0) 
          begin
            i_rgb_m_busy_req_0 <= 1'd1;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state) 
                    4'd04: 
                      begin
                        if (SobelFilter_Gti0s6_4_9_out1) 
                          begin
                          end 
                        else 
                          begin
                            i_rgb_m_busy_req_0 <= 1'd0;
                          end
                      end
                    4'd05: 
                      begin
                        i_rgb_m_busy_req_0 <= 1'd1;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // resource: regr_en_sc_1
    always @(posedge i_clk)
      begin : drive_o_avg_m_req_m_trig_req
        if (i_rst == 1'b0) 
          begin
            o_avg_m_req_m_trig_req <= 1'd0;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state) 
                    4'd07: 
                      begin
                        o_avg_m_req_m_trig_req <= SobelFilter_Not_1U_1U_1_3_out1;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // resource: mux_1bx3i1c
    always @(SobelFilter_And_1Ux1U_1U_4_12_out1 or SobelFilter_gen_busy_r_4_14_out1[0] or global_state)
      begin : drive_stall0
        case (global_state) 
          4'd05: 
            begin
              stall0 = SobelFilter_gen_busy_r_4_14_out1[0];
            end
          4'd08: 
            begin
              stall0 = SobelFilter_And_1Ux1U_1U_4_12_out1;
            end
          default: 
            begin
              stall0 = 1'b0;
            end
        endcase
      end
    
    // resource: mux_6bx3i1c
    // resource: regr_en_sc_6
    always @(posedge i_clk)
      begin : drive_s_reg_10
        if (i_rst == 1'b0) 
          begin
            s_reg_10 <= 6'd00;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state) 
                    4'd01: 
                      begin
                        case (SobelFilter_Add2i1u5_4_6_out1) 
                          6'd28: 
                            begin
                              s_reg_10 <= 6'd27;
                            end
                          default: 
                            begin
                              s_reg_10 <= SobelFilter_Add2i1u5_4_6_out1;
                            end
                        endcase
                      end
                    4'd03: 
                      begin
                        s_reg_10 <= SobelFilter_Sub_5Ux1U_6S_4_7_out1;
                      end
                    4'd08: 
                      begin
                        s_reg_10 <= 6'd27;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // resource: mux_32bx2i0c
    // resource: regr_en_sc_32
    always @(posedge i_clk)
      begin : drive_s_reg_5
        if (i_rst == 1'b0) 
          begin
            s_reg_5 <= 32'd0000000000;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state) 
                    4'd04: 
                      begin
                        s_reg_5 <= SobelFilter_Add2Mul2s32s32s32_4_10_out1;
                      end
                    4'd07: 
                      begin
                        s_reg_5 <= SobelFilter_Add_32Ux32U_32U_4_11_out1;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // resource: SobelFilter_Add2i1u5_4  instance: SobelFilter_Add2i1u5_4_6
    assign SobelFilter_Add2i1u5_4_6_out1 = {1'b0, s_reg_10[4:0]} + 6'd01;
    
    // resource: mux_5bx4i1c
    always @(s_reg_10[4:0] or SobelFilter_Add2i1u5_4_6_out1 or SobelFilter_Sub_5Ux1U_6S_4_7_out1[4:0] or gs_ctrl_do_filter_h172)
      begin : drive_shift_reg_in1
        case (gs_ctrl_do_filter_h172) 
          2'd1: 
            begin
              case (SobelFilter_Add2i1u5_4_6_out1) 
                6'd28: 
                  begin
                    shift_reg_in1 = SobelFilter_Sub_5Ux1U_6S_4_7_out1[4:0];
                  end
                default: 
                  begin
                    shift_reg_in1 = SobelFilter_Add2i1u5_4_6_out1[4:0];
                  end
              endcase
            end
          2'd2: 
            begin
              shift_reg_in1 = SobelFilter_Sub_5Ux1U_6S_4_7_out1[4:0];
            end
          2'd3: 
            begin
              shift_reg_in1 = 5'd00;
            end
          default: 
            begin
              shift_reg_in1 = s_reg_10[4:0];
            end
        endcase
      end
    
    // resource: mux_32bx3i1c
    always @(i_rgb_data or shift_reg_out1 or gs_ctrl_do_filter_h24)
      begin : drive_shift_reg_DIN
        case (gs_ctrl_do_filter_h24) 
          2'd1: 
            begin
              shift_reg_DIN = shift_reg_out1;
            end
          2'd2: 
            begin
              shift_reg_DIN = i_rgb_data;
            end
          default: 
            begin
              shift_reg_DIN = 32'd0000000000;
            end
        endcase
      end
    
    // resource: mux_1bx2i2c
    always @(stall0 or SobelFilter_Gti0s6_4_9_out1 or gs_ctrl_do_filter_h17f)
      begin : drive_shift_reg_CE
        if (stall0) 
          begin
            shift_reg_CE = 1'b0;
          end 
        else 
          begin
            case (gs_ctrl_do_filter_h17f) 
              2'd1: 
                begin
                  shift_reg_CE = 1'b1;
                end
              2'd2: 
                begin
                  if (SobelFilter_Gti0s6_4_9_out1) 
                    begin
                      shift_reg_CE = 1'b1;
                    end 
                  else 
                    begin
                      shift_reg_CE = 1'b0;
                    end
                end
              default: 
                begin
                  shift_reg_CE = 1'b0;
                end
            endcase
          end
      end
    
    // resource: mux_1bx2i2c
    always @(stall0 or SobelFilter_Add2i1u5_4_6_out1 or gs_ctrl_do_filter_h27)
      begin : drive_shift_reg_RW
        if (stall0) 
          begin
            shift_reg_RW = 1'b0;
          end 
        else 
          begin
            case (gs_ctrl_do_filter_h27) 
              2'd1: 
                begin
                  shift_reg_RW = 1'b1;
                end
              2'd2: 
                begin
                  case (SobelFilter_Add2i1u5_4_6_out1) 
                    6'd28: 
                      begin
                        shift_reg_RW = 1'b0;
                      end
                    default: 
                      begin
                        shift_reg_RW = 1'b1;
                      end
                  endcase
                end
              default: 
                begin
                  shift_reg_RW = 1'b0;
                end
            endcase
          end
      end
    
    // resource: mux_5bx2i1c
    always @(s_reg_10[4:0] or gs_ctrl_do_filter_h18)
      begin : drive_SobelFilter_Sub_5Ux1U_6S_4_7_in2
        if (gs_ctrl_do_filter_h18) 
          begin
            SobelFilter_Sub_5Ux1U_6S_4_7_in2 = s_reg_10[4:0];
          end 
        else 
          begin
            SobelFilter_Sub_5Ux1U_6S_4_7_in2 = 5'd27;
          end
      end
    
    // resource: SobelFilter_Sub_5Ux1U_6S_4  instance: SobelFilter_Sub_5Ux1U_6S_4_7
    assign SobelFilter_Sub_5Ux1U_6S_4_7_out1 = {1'b0, SobelFilter_Sub_5Ux1U_6S_4_7_in2} - 6'd01;
    
    // resource: SobelFilter_Gti0s6_4  instance: SobelFilter_Gti0s6_4_9
    assign SobelFilter_Gti0s6_4_9_out1 = s_reg_10[5] ^ s_reg_10 > 6'd00;
    
    // instance: drive_filter_coeffs_in1
    assign filter_coeffs_in1 = s_reg_10[4:0];
    
    // resource: mux_1bx2i2c
    always @(stall0 or gs_ctrl_do_filter_h8)
      begin : drive_filter_coeffs_CE
        if (stall0) 
          begin
            filter_coeffs_CE = 1'b0;
          end 
        else 
          begin
            if (gs_ctrl_do_filter_h8) 
              begin
                filter_coeffs_CE = 1'b1;
              end 
            else 
              begin
                filter_coeffs_CE = 1'b0;
              end
          end
      end
    
    // resource: SobelFilter_Add2Mul2s32s32s32_4  instance: SobelFilter_Add2Mul2s32s32s32_4_10
    assign t_60 = shift_reg_out1 * filter_coeffs_out1;
    assign SobelFilter_Add2Mul2s32s32s32_4_10_out1 = s_reg_5 + t_60[31:0];
    
    // instance: drive_SobelFilter_Add_32Ux32U_32U_4_11_in2
    assign SobelFilter_Add_32Ux32U_32U_4_11_in2 = {shift_reg_out1[28:0], 3'd0};
    
    // resource: SobelFilter_Add_32Ux32U_32U_4  instance: SobelFilter_Add_32Ux32U_32U_4_11
    assign SobelFilter_Add_32Ux32U_32U_4_11_out1 = SobelFilter_Add_32Ux32U_32U_4_11_in2 + s_reg_5;
    
    // resource: regr_en_sc_4
    always @(posedge i_clk)
      begin : drive_global_state
        if (i_rst == 1'b0) 
          begin
            global_state <= 4'd00;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  global_state <= global_state_next;
                end
            endcase
          end
      end
    
    // resource: mux_4bx3i2c
    always @(SobelFilter_Add2i1u5_4_6_out1 or SobelFilter_Gti0s6_4_9_out1 or global_state)
      begin : drive_global_state_next
        case (global_state) 
          4'd01: 
            begin
              case (SobelFilter_Add2i1u5_4_6_out1) 
                6'd28: 
                  begin
                    global_state_next = global_state + 4'd01;
                  end
                default: 
                  begin
                    global_state_next = 4'd01;
                  end
              endcase
            end
          4'd04: 
            begin
              if (SobelFilter_Gti0s6_4_9_out1) 
                begin
                  global_state_next = 4'd02;
                end 
              else 
                begin
                  global_state_next = global_state + 4'd01;
                end
            end
          4'd08: 
            begin
              global_state_next = 4'd02;
            end
          default: 
            begin
              global_state_next = global_state + 4'd01;
            end
        endcase
      end
    
    // resource: mux_2bx4i4c
    // resource: regr_en_sc_2
    always @(posedge i_clk)
      begin : drive_gs_ctrl_do_filter_h172
        if (i_rst == 1'b0) 
          begin
            gs_ctrl_do_filter_h172 <= 2'd0;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state_next) 
                    4'd01: 
                      begin
                        gs_ctrl_do_filter_h172 <= 2'd1;
                      end
                    4'd04, 4'd08: 
                      begin
                        gs_ctrl_do_filter_h172 <= 2'd2;
                      end
                    4'd05, 4'd06: 
                      begin
                        gs_ctrl_do_filter_h172 <= 2'd3;
                      end
                    default: 
                      begin
                        gs_ctrl_do_filter_h172 <= 2'd0;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // resource: mux_2bx3i3c
    // resource: regr_en_sc_2
    always @(posedge i_clk)
      begin : drive_gs_ctrl_do_filter_h24
        if (i_rst == 1'b0) 
          begin
            gs_ctrl_do_filter_h24 <= 2'd0;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state_next) 
                    4'd02: 
                      begin
                        gs_ctrl_do_filter_h24 <= 2'd1;
                      end
                    4'd05: 
                      begin
                        gs_ctrl_do_filter_h24 <= 2'd2;
                      end
                    default: 
                      begin
                        gs_ctrl_do_filter_h24 <= 2'd0;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // resource: mux_2bx3i3c
    // resource: regr_en_ss_sc_2
    always @(posedge i_clk)
      begin : drive_gs_ctrl_do_filter_h17f
        if (i_rst == 1'b0) 
          begin
            gs_ctrl_do_filter_h17f <= 2'd1;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state_next) 
                    4'd00, 4'd01, 4'd02, 4'd03, 4'd05, 4'd06, 4'd08: 
                      begin
                        gs_ctrl_do_filter_h17f <= 2'd1;
                      end
                    4'd04: 
                      begin
                        gs_ctrl_do_filter_h17f <= 2'd2;
                      end
                    default: 
                      begin
                        gs_ctrl_do_filter_h17f <= 2'd0;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // resource: mux_2bx3i3c
    // resource: regr_en_ss_sc_2
    always @(posedge i_clk)
      begin : drive_gs_ctrl_do_filter_h27
        if (i_rst == 1'b0) 
          begin
            gs_ctrl_do_filter_h27 <= 2'd1;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state_next) 
                    4'd00, 4'd02, 4'd05: 
                      begin
                        gs_ctrl_do_filter_h27 <= 2'd1;
                      end
                    4'd01: 
                      begin
                        gs_ctrl_do_filter_h27 <= 2'd2;
                      end
                    default: 
                      begin
                        gs_ctrl_do_filter_h27 <= 2'd0;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // resource: mux_1bx2i2c
    // resource: regr_en_sc_1
    always @(posedge i_clk)
      begin : drive_gs_ctrl_do_filter_h18
        if (i_rst == 1'b0) 
          begin
            gs_ctrl_do_filter_h18 <= 1'b0;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state_next) 
                    4'd03, 4'd04: 
                      begin
                        gs_ctrl_do_filter_h18 <= 1'b1;
                      end
                    default: 
                      begin
                        gs_ctrl_do_filter_h18 <= 1'b0;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // resource: mux_1bx2i2c
    // resource: regr_en_sc_1
    always @(posedge i_clk)
      begin : drive_gs_ctrl_do_filter_h8
        if (i_rst == 1'b0) 
          begin
            gs_ctrl_do_filter_h8 <= 1'b0;
          end 
        else 
          begin
            case (stall0) 
              1'b1: 
                begin
                end
              default: 
                begin
                  case (global_state_next) 
                    4'd03: 
                      begin
                        gs_ctrl_do_filter_h8 <= 1'b1;
                      end
                    default: 
                      begin
                        gs_ctrl_do_filter_h8 <= 1'b0;
                      end
                  endcase
                end
            endcase
          end
      end
    
    // instance: drive_i_rgb_busy
    assign i_rgb_busy = SobelFilter_gen_busy_r_4_14_out1[2];
    
    // resource: SobelFilter_gen_busy_r_4  instance: SobelFilter_gen_busy_r_4_14 (4 concurrent statements)
      assign SobelFilter_gen_busy_r_4_14_out1 = {SobelFilter_gen_busy_r_4_14_gnew_req, {SobelFilter_gen_busy_r_4_14_gdiv, SobelFilter_gen_busy_r_4_14_i_rgb_gen_busy_i_rgb_m_data_is_invalid_next}};
      assign SobelFilter_gen_busy_r_4_14_i_rgb_gen_busy_i_rgb_m_data_is_invalid_next = ~SobelFilter_gen_busy_r_4_14_gdiv;
      assign SobelFilter_gen_busy_r_4_14_gdiv = i_rgb_vld & !SobelFilter_gen_busy_r_4_14_gnew_req;
      assign SobelFilter_gen_busy_r_4_14_gnew_req = i_rgb_m_busy_req_0 & (i_rgb_m_unvalidated_req | i_rgb_vld);
    // (end of SobelFilter_gen_busy_r_4_14)
    
    // resource: regr_ss_1
    always @(posedge i_clk)
      begin : drive_i_rgb_m_unvalidated_req
        if (i_rst == 1'b0) 
          begin
            i_rgb_m_unvalidated_req <= 1'd1;
          end 
        else 
          begin
            i_rgb_m_unvalidated_req <= SobelFilter_N_Muxb_1_2_8_4_4_out1;
          end
      end
    
    // resource: SobelFilter_N_Muxb_1_2_8_4
    always @(i_rgb_vld or i_rgb_m_busy_req_0 or i_rgb_m_unvalidated_req)
      begin : SobelFilter_N_Muxb_1_2_8_4_4
        if (i_rgb_m_busy_req_0) 
          begin
            SobelFilter_N_Muxb_1_2_8_4_4_out1 = i_rgb_m_unvalidated_req;
          end 
        else 
          begin
            SobelFilter_N_Muxb_1_2_8_4_4_out1 = i_rgb_vld;
          end
      end
    
    // instance: drive_o_avg_vld
    assign o_avg_vld = SobelFilter_Or_1Ux1U_1U_4_2_out1;
    
    // resource: SobelFilter_Or_1Ux1U_1U_4  instance: SobelFilter_Or_1Ux1U_1U_4_2
    assign SobelFilter_Or_1Ux1U_1U_4_2_out1 = o_avg_m_unacked_req | SobelFilter_Xor_1Ux1U_1U_1_1_out1;
    
    // resource: regr_sc_1
    always @(posedge i_clk)
      begin : drive_o_avg_m_unacked_req
        if (i_rst == 1'b0) 
          begin
            o_avg_m_unacked_req <= 1'd0;
          end 
        else 
          begin
            o_avg_m_unacked_req <= SobelFilter_And_1Ux1U_1U_4_12_out1;
          end
      end
    
    // resource: SobelFilter_And_1Ux1U_1U_4  instance: SobelFilter_And_1Ux1U_1U_4_12
    assign SobelFilter_And_1Ux1U_1U_4_12_out1 = o_avg_busy & o_avg_vld;
    
    // resource: SobelFilter_Xor_1Ux1U_1U_1  instance: SobelFilter_Xor_1Ux1U_1U_1_1
    assign SobelFilter_Xor_1Ux1U_1U_1_1_out1 = o_avg_m_req_m_trig_req ^ o_avg_m_req_m_prev_trig_req;
    
    // resource: regr_sc_1
    always @(posedge i_clk)
      begin : drive_o_avg_m_req_m_prev_trig_req
        if (i_rst == 1'b0) 
          begin
            o_avg_m_req_m_prev_trig_req <= 1'd0;
          end 
        else 
          begin
            o_avg_m_req_m_prev_trig_req <= o_avg_m_req_m_trig_req;
          end
      end
    
    // resource: SobelFilter_Not_1U_1U_1  instance: SobelFilter_Not_1U_1U_1_3
    assign SobelFilter_Not_1U_1U_1_3_out1 = !o_avg_m_req_m_trig_req;

endmodule

