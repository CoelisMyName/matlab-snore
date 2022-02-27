//
// File: vad_below_threshold.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "vad_below_threshold.h"
#include "ceil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// function [ostarts, oends] = vad_below_threshold(xn, dth, width)
//
// Arguments    : const coder::array<double, 2U> &xn
//                double dth
//                coder::array<long long, 1U> &ostarts
//                coder::array<long long, 1U> &oends
// Return Type  : void
//
void vad_below_threshold(const coder::array<double, 2U> &xn, double dth,
                         coder::array<long long, 1U> &ostarts,
                         coder::array<long long, 1U> &oends)
{
    coder::array<long long, 2U> ends;
    coder::array<long long, 2U> starts;
    double count;
    double d;
    long long i1;
    int i;
    int len;
    int loop_ub_tmp;
    //  获取高于阈值的段 x数组，dth阈值，width宽度
    // 'vad_below_threshold:3' starts = zeros(1, ceil(length(xn) / width) + 1,
    // 'int64');
    d = static_cast<double>(xn.size(1)) / 6.0;
    coder::b_ceil(&d);
    loop_ub_tmp = static_cast<int>(d + 1.0);
    starts.set_size(1, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
        starts[i] = 0LL;
    }
    // 'vad_below_threshold:4' ends = zeros(1, ceil(length(xn) / width) + 1,
    // 'int64');
    d = static_cast<double>(xn.size(1)) / 6.0;
    coder::b_ceil(&d);
    loop_ub_tmp = static_cast<int>(d + 1.0);
    ends.set_size(1, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
        ends[i] = 0LL;
    }
    // 'vad_below_threshold:5' len = 0;
    len = -1;
    // 'vad_below_threshold:6' count = 0;
    count = 0.0;
    // 'vad_below_threshold:7' coder.varsize('starts');
    // 'vad_below_threshold:8' coder.varsize('ends');
    // 'vad_below_threshold:10' for i = 1:length(xn)
    i = xn.size(1);
    for (int b_i = 0; b_i < i; b_i++) {
        // 'vad_below_threshold:12' if xn(i) > dth
        d = xn[b_i];
        if (d > dth) {
            // 'vad_below_threshold:13' count = count + 1;
            count++;
        }
        // 'vad_below_threshold:16' if xn(i) <= dth && count >= width
        if ((d <= dth) && (count >= 6.0)) {
            double d1;
            // 'vad_below_threshold:17' len = len + 1;
            len++;
            // 'vad_below_threshold:18' starts(len) = i - count;
            d1 = (static_cast<double>(b_i) + 1.0) - count;
            if (d1 >= -9.2233720368547758E+18) {
                i1 = static_cast<long long>(d1);
            } else {
                i1 = MIN_int64_T;
            }
            starts[len] = i1;
            // 'vad_below_threshold:19' ends(len) = i - 1;
            ends[len] = b_i;
        }
        // 'vad_below_threshold:22' if xn(i) <= dth
        if (d <= dth) {
            // 'vad_below_threshold:23' count = 0;
            count = 0.0;
        }
    }
    //  到末尾，有声段可能大于
    // 'vad_below_threshold:29' if count >= width
    if (count >= 6.0) {
        // 'vad_below_threshold:30' len = len + 1;
        len++;
        // 'vad_below_threshold:31' starts(len) = length(xn) - count + 1;
        d = (static_cast<double>(xn.size(1)) - count) + 1.0;
        if (d >= -9.2233720368547758E+18) {
            i1 = static_cast<long long>(d);
        } else {
            i1 = MIN_int64_T;
        }
        starts[len] = i1;
        // 'vad_below_threshold:32' ends(len) = length(xn);
        ends[len] = xn.size(1);
    }
    // 'vad_below_threshold:35' ostarts = starts(1:len)';
    if (1 > len + 1) {
        loop_ub_tmp = -1;
    } else {
        loop_ub_tmp = len;
    }
    ostarts.set_size(loop_ub_tmp + 1);
    for (i = 0; i <= loop_ub_tmp; i++) {
        ostarts[i] = starts[i];
    }
    // 'vad_below_threshold:36' oends = ends(1:len)';
    if (1 > len + 1) {
        loop_ub_tmp = -1;
    } else {
        loop_ub_tmp = len;
    }
    oends.set_size(loop_ub_tmp + 1);
    for (i = 0; i <= loop_ub_tmp; i++) {
        oends[i] = ends[i];
    }
}

//
// File trailer for vad_below_threshold.cpp
//
// [EOF]
//
