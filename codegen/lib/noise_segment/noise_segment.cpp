//
// File: noise_segment.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "noise_segment.h"
#include "eml_i64relops.h"
#include "minOrMax.h"
#include "noise_segment_data.h"
#include "noise_segment_initialize.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// function [ostart, olength] = noise_segment(w_starts, w_ends, fs, min_gap,
// margin)
//
// Arguments    : const coder::array<long long, 1U> &w_starts
//                const coder::array<long long, 1U> &w_ends
//                double fs
//                double min_gap
//                double margin
//                double *ostart
//                double *olength
// Return Type  : void
//
void noise_segment(const coder::array<long long, 1U> &w_starts,
                   const coder::array<long long, 1U> &w_ends, double fs,
                   double min_gap, double margin, double *ostart,
                   double *olength)
{
    double d;
    int i;
    boolean_T exitg1;
    if (!isInitialized_noise_segment) {
        noise_segment_initialize();
    }
    //  输入有声片段数组，返回无声段起点（秒）和长度（秒），-1则找不到符合的无声段
    // 'noise_segment:3' len = min(length(w_starts), length(w_ends));
    // 'noise_segment:4' ostart = -1.0;
    *ostart = -1.0;
    // 'noise_segment:5' olength = -1.0;
    *olength = -1.0;
    // 'noise_segment:7' for i = 1:len - 1
    d = coder::internal::minimum2(static_cast<double>(w_starts.size(0)),
                                  static_cast<double>(w_ends.size(0))) -
        1.0;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i <= static_cast<int>(d) - 1)) {
        long long q0;
        long long q1;
        // 'noise_segment:9' if w_starts(i + 1) - w_ends(i) > margin
        q0 = w_starts[static_cast<int>((static_cast<double>(i) + 1.0) + 1.0) -
                      1];
        q1 = w_ends[i];
        if ((q0 >= 0LL) && (q1 < q0 - MAX_int64_T)) {
            q0 = MAX_int64_T;
        } else if ((q0 < 0LL) && (q1 > q0 - MIN_int64_T)) {
            q0 = MIN_int64_T;
        } else {
            q0 -= q1;
        }
        if (coder::eml_i64relops(q0, margin)) {
            // 'noise_segment:10' oend = (double(w_starts(i + 1)) - min_gap) /
            // fs; 'noise_segment:11' ostart = (double(w_ends(i)) + min_gap) /
            // fs;
            *ostart = (static_cast<double>(w_ends[i]) + min_gap) / fs;
            // 'noise_segment:12' olength = oend - ostart;
            *olength =
                (static_cast<double>(w_starts[i + 1]) - min_gap) / fs - *ostart;
            exitg1 = true;
        } else {
            i++;
        }
    }
}

//
// File trailer for noise_segment.cpp
//
// [EOF]
//
