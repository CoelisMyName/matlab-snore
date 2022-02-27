//
// File: amax_group.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "amax_group.h"
#include "abs.h"
#include "floor.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// function [result] = amax_group(array, width)
//
// Arguments    : const coder::array<double, 1U> &array
//                coder::array<double, 2U> &result
// Return Type  : void
//
void amax_group(const coder::array<double, 1U> &array,
                coder::array<double, 2U> &result)
{
    coder::array<double, 1U> b_array;
    coder::array<double, 1U> r;
    double d;
    int i;
    // 给定宽度内绝对值最大值
    // 'amax_group:3' result = zeros(1, floor(length(array) / width));
    d = static_cast<double>(array.size(0)) / 50.0;
    coder::b_floor(&d);
    // 'amax_group:5' for i = 1:length(result)
    i = static_cast<int>(d);
    result.set_size(1, i);
    for (int b_i = 0; b_i < i; b_i++) {
        int i1;
        int i2;
        int loop_ub;
        // 'amax_group:6' result(i) = max(abs(array((i - 1) * width + 1:i *
        // width)));
        i1 = b_i * 50;
        i2 = (b_i + 1) * 50;
        if (i1 + 1 > i2) {
            i1 = 0;
            i2 = 0;
        }
        loop_ub = i2 - i1;
        b_array.set_size(loop_ub);
        for (i2 = 0; i2 < loop_ub; i2++) {
            b_array[i2] = array[i1 + i2];
        }
        coder::b_abs(b_array, r);
        result[b_i] = coder::internal::maximum(r);
    }
}

//
// File trailer for amax_group.cpp
//
// [EOF]
//
