/********************/
state0:;
/*HLS_SET_OUTPUT_OPTIONS(i_rgb_m_use_stall_reg_ip, 4ULL);*//* 51ULL */
/*HLS_SET_OUTPUT_OPTIONS(o_avg_m_req_m_trig_req, 0ULL);*//* 71ULL */
/*HLS_SET_OUTPUT_OPTIONS(i_rgb_m_stalling, 11ULL);*//* 36ULL */
/*HLS_SET_OUTPUT_OPTIONS(i_rgb_m_busy_req_0, 0ULL);*//* 46ULL */
/*HLS_SET_INPUT_DELAY(i_rgb_data, -1.000000);*//* 59ULL */
/*HLS_SET_OUTPUT_OPTIONS(o_avg_data, 2ULL);*//* 72ULL */
goto state1;
/********************/
state1:;
goto state2;
/********************/
state2:;
/*HLS_DEFINE_PROTOCOL("main_reset");*//* 33ULL */
i_rgb_m_busy_req_0 = 1ULL;
i_rgb_m_stalling = 0ULL;
o_avg_m_req_m_trig_req = 0ULL;
goto state3;
/********************/
state3:;
/*HLS_DEFINE_PROTOCOL("main_reset");*//* 33ULL */
wait( 1LL ); // cycle_id 1
goto state4;
/********************/
state4:;
check = (sc_int<32> ) (0ULL);
(temp_r)[((/*imp*/sc_uint<1> )(0ULL))] = 0ULL;
(temp_r)[((/*imp*/sc_uint<1> )(1ULL))] = 0ULL;
(temp_r)[((/*imp*/sc_uint<2> )(2ULL))] = 0ULL;
(temp_r)[((/*imp*/sc_uint<2> )(3ULL))] = 0ULL;
(temp_r)[((/*imp*/sc_uint<3> )(4ULL))] = 0ULL;
(temp_r)[((/*imp*/sc_uint<3> )(5ULL))] = 0ULL;
(temp_r)[((/*imp*/sc_uint<3> )(6ULL))] = 0ULL;
(temp_r)[((/*imp*/sc_uint<3> )(7ULL))] = 0ULL;
(temp_r)[((/*imp*/sc_uint<4> )(8ULL))] = 0ULL;
(temp_g)[((/*imp*/sc_uint<1> )(0ULL))] = 0ULL;
(temp_g)[((/*imp*/sc_uint<1> )(1ULL))] = 0ULL;
(temp_g)[((/*imp*/sc_uint<2> )(2ULL))] = 0ULL;
(temp_g)[((/*imp*/sc_uint<2> )(3ULL))] = 0ULL;
(temp_g)[((/*imp*/sc_uint<3> )(4ULL))] = 0ULL;
(temp_g)[((/*imp*/sc_uint<3> )(5ULL))] = 0ULL;
(temp_g)[((/*imp*/sc_uint<3> )(6ULL))] = 0ULL;
(temp_g)[((/*imp*/sc_uint<3> )(7ULL))] = 0ULL;
(temp_g)[((/*imp*/sc_uint<4> )(8ULL))] = 0ULL;
(temp_b)[((/*imp*/sc_uint<1> )(0ULL))] = 0ULL;
(temp_b)[((/*imp*/sc_uint<1> )(1ULL))] = 0ULL;
(temp_b)[((/*imp*/sc_uint<2> )(2ULL))] = 0ULL;
(temp_b)[((/*imp*/sc_uint<2> )(3ULL))] = 0ULL;
(temp_b)[((/*imp*/sc_uint<3> )(4ULL))] = 0ULL;
(temp_b)[((/*imp*/sc_uint<3> )(5ULL))] = 0ULL;
(temp_b)[((/*imp*/sc_uint<3> )(6ULL))] = 0ULL;
(temp_b)[((/*imp*/sc_uint<3> )(7ULL))] = 0ULL;
(temp_b)[((/*imp*/sc_uint<4> )(8ULL))] = 0ULL;
goto state5;
/********************/
state5:;
(buffer_r)[((/*imp*/sc_uint<1> )(0ULL))] = 0ULL;
(buffer_r)[((/*imp*/sc_uint<1> )(1ULL))] = 0ULL;
(buffer_r)[((/*imp*/sc_uint<2> )(2ULL))] = 0ULL;
(buffer_r)[((/*imp*/sc_uint<2> )(3ULL))] = 0ULL;
(buffer_r)[((/*imp*/sc_uint<3> )(4ULL))] = 0ULL;
(buffer_r)[((/*imp*/sc_uint<3> )(5ULL))] = 0ULL;
(buffer_g)[((/*imp*/sc_uint<1> )(0ULL))] = 0ULL;
(buffer_g)[((/*imp*/sc_uint<1> )(1ULL))] = 0ULL;
(buffer_g)[((/*imp*/sc_uint<2> )(2ULL))] = 0ULL;
(buffer_g)[((/*imp*/sc_uint<2> )(3ULL))] = 0ULL;
(buffer_g)[((/*imp*/sc_uint<3> )(4ULL))] = 0ULL;
(buffer_g)[((/*imp*/sc_uint<3> )(5ULL))] = 0ULL;
(buffer_b)[((/*imp*/sc_uint<1> )(0ULL))] = 0ULL;
(buffer_b)[((/*imp*/sc_uint<1> )(1ULL))] = 0ULL;
(buffer_b)[((/*imp*/sc_uint<2> )(2ULL))] = 0ULL;
(buffer_b)[((/*imp*/sc_uint<2> )(3ULL))] = 0ULL;
(buffer_b)[((/*imp*/sc_uint<3> )(4ULL))] = 0ULL;
(buffer_b)[((/*imp*/sc_uint<3> )(5ULL))] = 0ULL;
avg_r = 0ULL;
avg_g = 0ULL;
avg_b = 0ULL;
v = 0ULL;
goto state6;
/********************/
state6:;
u = 0ULL;
goto state7;
/********************/
state7:;
switch( (sc_uint<1>)(((sc_uint<32>)check).or_reduce() & (u != 2ULL)) ) {
case 1ULL: 
  goto state14;
case 0ULL: 
  goto state8;
}
/********************/
state8:;
/*HLS_DEFINE_PROTOCOL("input");*//* 43ULL */
i_rgb_m_busy_req_0 = 0ULL;
goto state9;
/********************/
state9:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "get", (long long)0x0ULL);*//* 54ULL */
/*HLS_DEFINE_PROTOCOL("input");*//* 43ULL */
goto state10;
/********************/
state10:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "get", (long long)0x0ULL);*//* 54ULL */
/*HLS_DEFINE_PROTOCOL("input");*//* 43ULL */
wait( 1LL ); // cycle_id 2
stall0 = i_rgb_m_data_is_invalid;
goto state11;
/********************/
state11:;
/*HLS_DEFINE_PROTOCOL("input");*//* 43ULL */
/*HLS_SET_STALL_LOCAL(i_rgb_m_stalling, 1ULL, 0ULL, (long long)0x0ULL, 
(long long)0x0ULL);*//* 57ULL */
i_rgb_m_busy_req_0 = 1ULL;
$$g$$n$$$649 = i_rgb_data;
goto state12;
/********************/
state12:;
/*HLS_DEFINE_PROTOCOL("input");*//* 43ULL */
wait( 1LL ); // cycle_id 3
goto state13;
/********************/
state13:;
(temp_r)[((/*imp*/sc_uint<4> )((/*cliff*/sc_uint<32>)(u + (/*cliff*/sc_uint<32>)
v * 3ULL)))] = (sc_uint<8> )($$g$$n$$$649.range(7,0));
(temp_g)[((/*imp*/sc_uint<4> )((/*cliff*/sc_uint<32>)(u + (/*cliff*/sc_uint<32>)
v * 3ULL)))] = (sc_uint<8> )($$g$$n$$$649.range(15,8));
(temp_b)[((/*imp*/sc_uint<4> )((/*cliff*/sc_uint<32>)(u + (/*cliff*/sc_uint<32>)
v * 3ULL)))] = (sc_uint<8> )($$g$$n$$$649.range(23,16));
goto state14;
/********************/
state14:;
amtmp001 = (u == 1ULL) & (v == 1ULL);
avg_r = (/*cliff*/sc_uint<32>)(( amtmp001 ? (sc_uint<8> )
        (0ULL) : (sc_uint<8> )
        ((sc_uint<8> )(/*Enable*/(!amtmp001?(sc_uint<8> )(temp_r)[((/*imp*/
        sc_uint<4> )((/*cliff*/sc_uint<32>)(u + (/*cliff*/sc_uint<32>)v * 3ULL)
        ))]:(sc_uint<8> )0ULL)))) + avg_r);
avg_g = (/*cliff*/sc_uint<32>)(( amtmp001 ? (sc_uint<8> )
        (0ULL) : (sc_uint<8> )
        ((sc_uint<8> )(/*Enable*/(!amtmp001?(sc_uint<8> )(temp_g)[((/*imp*/
        sc_uint<4> )((/*cliff*/sc_uint<32>)(u + (/*cliff*/sc_uint<32>)v * 3ULL)
        ))]:(sc_uint<8> )0ULL)))) + avg_g);
avg_b = (/*cliff*/sc_uint<32>)(( amtmp001 ? (sc_uint<8> )
        (0ULL) : (sc_uint<8> )
        ((sc_uint<8> )(/*Enable*/(!amtmp001?(sc_uint<8> )(temp_b)[((/*imp*/
        sc_uint<4> )((/*cliff*/sc_uint<32>)(u + (/*cliff*/sc_uint<32>)v * 3ULL)
        ))]:(sc_uint<8> )0ULL)))) + avg_b);
u = (/*cliff*/sc_uint<32>)(u + 1ULL);
switch( (sc_uint<1>)((/*imp*/sc_uint<1>)(u < ((/*imp*/sc_uint<2> )(3ULL)))) ) {
case 0ULL: 
  goto state15;
case 1ULL: 
  goto state7;
}
/********************/
state15:;
v = (/*cliff*/sc_uint<32>)(v + 1ULL);
switch( (sc_uint<1>)((/*imp*/sc_uint<1>)(v < ((/*imp*/sc_uint<2> )(3ULL)))) ) {
case 0ULL: 
  goto state16;
case 1ULL: 
  goto state6;
}
/********************/
state16:;
check_u0 = (/*cliff*/sc_int<32>)(check + 1ULL);
check = ( (check_u0 == 256ULL) ? (sc_int<32> )
        (0ULL) : (sc_int<32> )
        (check_u0));
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_r)[((/*imp*/sc_uint<1> )(0ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_r)[((/*imp*/
                                                               sc_uint<1> )(1ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_g)[((/*imp*/sc_uint<1> )(0ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_g)[((/*imp*/
                                                               sc_uint<1> )(1ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_b)[((/*imp*/sc_uint<1> )(0ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_b)[((/*imp*/
                                                               sc_uint<1> )(1ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_r)[((/*imp*/sc_uint<1> )(1ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_r)[((/*imp*/
                                                               sc_uint<2> )(2ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_g)[((/*imp*/sc_uint<1> )(1ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_g)[((/*imp*/
                                                               sc_uint<2> )(2ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_b)[((/*imp*/sc_uint<1> )(1ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_b)[((/*imp*/
                                                               sc_uint<2> )(2ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_r)[((/*imp*/sc_uint<2> )(2ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_r)[((/*imp*/
                                                               sc_uint<3> )(4ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_g)[((/*imp*/sc_uint<2> )(2ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_g)[((/*imp*/
                                                               sc_uint<3> )(4ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_b)[((/*imp*/sc_uint<2> )(2ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_b)[((/*imp*/
                                                               sc_uint<3> )(4ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_r)[((/*imp*/sc_uint<2> )(3ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_r)[((/*imp*/
                                                               sc_uint<3> )(5ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_g)[((/*imp*/sc_uint<2> )(3ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_g)[((/*imp*/
                                                               sc_uint<3> )(5ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_b)[((/*imp*/sc_uint<2> )(3ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_b)[((/*imp*/
                                                               sc_uint<3> )(5ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_r)[((/*imp*/sc_uint<3> )(4ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_r)[((/*imp*/
                                                               sc_uint<3> )(7ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_g)[((/*imp*/sc_uint<3> )(4ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_g)[((/*imp*/
                                                               sc_uint<3> )(7ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_b)[((/*imp*/sc_uint<3> )(4ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_b)[((/*imp*/
                                                               sc_uint<3> )(7ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_r)[((/*imp*/sc_uint<3> )(5ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_r)[((/*imp*/
                                                               sc_uint<4> )(8ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_g)[((/*imp*/sc_uint<3> )(5ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_g)[((/*imp*/
                                                               sc_uint<4> )(8ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (buffer_b)[((/*imp*/sc_uint<3> )(5ULL))] = /*Enable*/(
                                                               ((sc_uint<32>)
                                                               check)
                                                               .or_reduce()?(
                                                               sc_uint<8> )(
                                                               temp_b)[((/*imp*/
                                                               sc_uint<4> )(8ULL
                                                               ))]:(sc_uint<8> 
                                                               )0ULL);
(*(sc_uint<8>  *)temp_r) = arg_001;
(temp_r)[((/*imp*/sc_uint<4> )(9ULL))] = arg_002;
(*(sc_uint<8>  *)temp_g) = arg_003;
(temp_g)[((/*imp*/sc_uint<4> )(9ULL))] = arg_004;
(*(sc_uint<8>  *)temp_b) = arg_005;
(temp_b)[((/*imp*/sc_uint<4> )(9ULL))] = arg_006;
avg_r_u0 = (/*cliff*/sc_uint<32>)((/*imp*/sc_uint<32> ) ((/*cliff*/sc_uint<32>)(
           avg_r + ( (sc_uint<9> )(sc_bv<9>)((sc_bv<8>)((sc_uint<8> )((temp_r)[
           ((/*imp*/sc_uint<3> )(4ULL))])), 
           (sc_bv<1>)(0ULL)) )))).range(31,1) / 5ULL;
avg_g_u0 = (/*cliff*/sc_uint<32>)((/*imp*/sc_uint<32> ) ((/*cliff*/sc_uint<32>)(
           avg_g + ( (sc_uint<9> )(sc_bv<9>)((sc_bv<8>)((sc_uint<8> )((temp_g)[
           ((/*imp*/sc_uint<3> )(4ULL))])), 
           (sc_bv<1>)(0ULL)) )))).range(31,1) / 5ULL;
avg_b_u0 = (/*cliff*/sc_uint<32>)((/*imp*/sc_uint<32> ) ((/*cliff*/sc_uint<32>)(
           avg_b + ( (sc_uint<9> )(sc_bv<9>)((sc_bv<8>)((sc_uint<8> )((temp_b)[
           ((/*imp*/sc_uint<3> )(4ULL))])), 
           (sc_bv<1>)(0ULL)) )))).range(31,1) / 5ULL;
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_r)[((/*imp*/sc_uint<1> )(0ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_r)[((/*imp*/
                                                             sc_uint<1> )(0ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_g)[((/*imp*/sc_uint<1> )(0ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_g)[((/*imp*/
                                                             sc_uint<1> )(0ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_b)[((/*imp*/sc_uint<1> )(0ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_b)[((/*imp*/
                                                             sc_uint<1> )(0ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_r)[((/*imp*/sc_uint<1> )(1ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_r)[((/*imp*/
                                                             sc_uint<1> )(1ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_g)[((/*imp*/sc_uint<1> )(1ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_g)[((/*imp*/
                                                             sc_uint<1> )(1ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_b)[((/*imp*/sc_uint<1> )(1ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_b)[((/*imp*/
                                                             sc_uint<1> )(1ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_r)[((/*imp*/sc_uint<2> )(3ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_r)[((/*imp*/
                                                             sc_uint<2> )(2ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_g)[((/*imp*/sc_uint<2> )(3ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_g)[((/*imp*/
                                                             sc_uint<2> )(2ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_b)[((/*imp*/sc_uint<2> )(3ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_b)[((/*imp*/
                                                             sc_uint<2> )(2ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_r)[((/*imp*/sc_uint<3> )(4ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_r)[((/*imp*/
                                                             sc_uint<2> )(3ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_g)[((/*imp*/sc_uint<3> )(4ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_g)[((/*imp*/
                                                             sc_uint<2> )(3ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_b)[((/*imp*/sc_uint<3> )(4ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_b)[((/*imp*/
                                                             sc_uint<2> )(3ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_r)[((/*imp*/sc_uint<3> )(6ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_r)[((/*imp*/
                                                             sc_uint<3> )(4ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_g)[((/*imp*/sc_uint<3> )(6ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_g)[((/*imp*/
                                                             sc_uint<3> )(4ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_b)[((/*imp*/sc_uint<3> )(6ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_b)[((/*imp*/
                                                             sc_uint<3> )(4ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_r)[((/*imp*/sc_uint<3> )(7ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_r)[((/*imp*/
                                                             sc_uint<3> )(5ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_g)[((/*imp*/sc_uint<3> )(7ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_g)[((/*imp*/
                                                             sc_uint<3> )(5ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
if /*guard*/( ((sc_uint<32>)check).or_reduce() ) /*Enable*/if (((sc_uint<32>)
check).or_reduce()) (temp_b)[((/*imp*/sc_uint<3> )(7ULL))] = /*Enable*/(
                                                             ((sc_uint<32>)check
                                                             ).or_reduce()?(
                                                             sc_uint<8> )(
                                                             buffer_b)[((/*imp*/
                                                             sc_uint<3> )(5ULL))
                                                             ]:(sc_uint<8> 
                                                             )0ULL);
out_avg_all = ( (sc_uint<24> )(sc_bv<24>)((sc_bv<8>)((sc_uint<8> )avg_b_u0), 
              (sc_bv<16>)((sc_bv<8>)((sc_uint<8> )avg_g_u0), 
              (sc_bv<8>)((sc_uint<8> )avg_r_u0))) );
goto state17;
/********************/
state17:;
/*HLS_DEFINE_PROTOCOL("output");*//* 62ULL */
o_avg_data = out_avg_all;
o_avg_m_req_m_trig_req = o_avg_m_req_m_next_trig_req;
goto state18;
/********************/
state18:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "put", (long long)0x0ULL);*//* 73ULL */
/*HLS_DEFINE_PROTOCOL("output");*//* 62ULL */
goto state19;
/********************/
state19:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "put", (long long)0x0ULL);*//* 73ULL */
/*HLS_DEFINE_PROTOCOL("output");*//* 62ULL */
wait( 1LL ); // cycle_id 4
stall0 = o_avg_m_stalling;
goto state20;
/********************/
state20:;
/*HLS_DEFINE_PROTOCOL("output");*//* 62ULL */
goto state21;
/********************/
state21:;
/*HLS_DEFINE_PROTOCOL("output");*//* 62ULL */
wait( 1LL ); // cycle_id 5
goto state5;
