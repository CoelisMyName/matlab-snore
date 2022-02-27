//
// File: vad_length_filter.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "vad_length_filter.h"
#include "eml_i64relops.h"
#include "length.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// function [ostarts, oends] = vad_length_filter(starts, ends, min_len, max_len)
//
// Arguments    : const coder::array<long long, 2U> &starts
//                const coder::array<long long, 2U> &ends
//                double min_len
//                double max_len
//                coder::array<long long, 1U> &ostarts
//                coder::array<long long, 1U> &oends
// Return Type  : void
//
void vad_length_filter(const coder::array<long long, 2U> &starts,
                       const coder::array<long long, 2U> &ends, double min_len,
                       double max_len, coder::array<long long, 1U> &ostarts,
                       coder::array<long long, 1U> &oends)
{
    coder::array<long long, 2U> tends;
    coder::array<long long, 2U> tstarts;
    int i;
    unsigned int k;
    int n;
    // vad_length_filter: stars 开始 ends 结束 min_len 最小长度 max_len 最大长度
    // 'vad_length_filter:3' k = 0;
    k = 0U;
    // 'vad_length_filter:4' tstarts = zeros(1, length(starts), 'int64');
    n = coder::internal::intlength(starts.size(0), starts.size(1));
    tstarts.set_size(1, n);
    for (i = 0; i < n; i++) {
        tstarts[i] = 0LL;
    }
    // 'vad_length_filter:5' tends = zeros(1, length(ends), 'int64');
    n = coder::internal::intlength(ends.size(0), ends.size(1));
    tends.set_size(1, n);
    for (i = 0; i < n; i++) {
        tends[i] = 0LL;
    }
    // 'vad_length_filter:6' coder.varsize('tstarts');
    // 'vad_length_filter:7' coder.varsize('tends');
    // 'vad_length_filter:9' for i = 1:min(length(starts), length(ends))
    i = static_cast<int>(coder::internal::minimum2(
        static_cast<double>(
            coder::internal::intlength(starts.size(0), starts.size(1))),
        static_cast<double>(
            coder::internal::intlength(ends.size(0), ends.size(1)))));
    for (int b_i = 0; b_i < i; b_i++) {
        long long q0;
        long long q1;
        // 'vad_length_filter:10' len = ends(i) - starts(i) + 1;
        q0 = ends[b_i];
        q1 = starts[b_i];
        if ((q0 >= 0LL) && (q1 < q0 - MAX_int64_T)) {
            q0 = MAX_int64_T;
        } else if ((q0 < 0LL) && (q1 > q0 - MIN_int64_T)) {
            q0 = MIN_int64_T;
        } else {
            q0 -= q1;
        }
        if (q0 > 9223372036854775806LL) {
            q0 = MAX_int64_T;
        } else {
            q0++;
        }
        //  小于限定长度或大于限定长度的都抛弃
        // 'vad_length_filter:12' if len > min_len && len < max_len
        if (coder::eml_i64relops(q0, min_len) &&
            coder::b_eml_i64relops(q0, max_len)) {
            // 'vad_length_filter:13' k = k + 1;
            k++;
            // 'vad_length_filter:14' tstarts(k) = starts(i);
            tstarts[static_cast<int>(k) - 1] = starts[b_i];
            // 'vad_length_filter:15' tends(k) = ends(i);
            tends[static_cast<int>(k) - 1] = ends[b_i];
        }
    }
    //  对结果进行裁剪
    // 'vad_length_filter:21' ostarts = tstarts(1:k)';
    if (1 > static_cast<int>(k)) {
        n = 0;
    } else {
        n = static_cast<int>(k);
    }
    ostarts.set_size(n);
    for (i = 0; i < n; i++) {
        ostarts[i] = tstarts[i];
    }
    // 'vad_length_filter:22' oends = tends(1:k)';
    if (1 > static_cast<int>(k)) {
        n = 0;
    } else {
        n = static_cast<int>(k);
    }
    oends.set_size(n);
    for (i = 0; i < n; i++) {
        oends[i] = tends[i];
    }
}

//
// File trailer for vad_length_filter.cpp
//
// [EOF]
//
