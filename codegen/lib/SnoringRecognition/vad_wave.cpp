//
// File: vad_wave.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 27-Feb-2022 00:06:11
//

// Include Files
#include "vad_wave.h"
#include "abs.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// function [ostarts, oends] = vad_wave(array, starts, ends)
//
// Arguments    : const coder::array<double, 2U> &array
//                const coder::array<long long, 1U> &starts
//                const coder::array<long long, 1U> &ends
//                coder::array<long long, 1U> &ostarts
//                coder::array<long long, 1U> &oends
// Return Type  : void
//
void vad_wave(const coder::array<double, 2U> &array,
              const coder::array<long long, 1U> &starts,
              const coder::array<long long, 1U> &ends,
              coder::array<long long, 1U> &ostarts,
              coder::array<long long, 1U> &oends)
{
    coder::array<long long, 2U> tends;
    coder::array<long long, 2U> tstarts;
    int i;
    unsigned int k;
    int loop_ub;
    //  按波形重新分段
    // 'vad_wave:3' tstarts = zeros(1, length(starts), 'int64');
    tstarts.set_size(1, starts.size(0));
    loop_ub = starts.size(0);
    for (i = 0; i < loop_ub; i++) {
        tstarts[i] = 0LL;
    }
    // 'vad_wave:4' tends = zeros(1, length(ends), 'int64');
    tends.set_size(1, ends.size(0));
    loop_ub = ends.size(0);
    for (i = 0; i < loop_ub; i++) {
        tends[i] = 0LL;
    }
    // 'vad_wave:5' coder.varsize('tstarts');
    // 'vad_wave:6' coder.varsize('tends');
    // 'vad_wave:7' k = 1;
    k = 1U;
    // 'vad_wave:9' for i = 1:min(length(starts), length(ends))
    i = static_cast<int>(
        coder::internal::minimum2(static_cast<double>(starts.size(0)),
                                  static_cast<double>(ends.size(0))));
    for (int b_i = 0; b_i < i; b_i++) {
        double count;
        long long lowb;
        long long q0;
        int i1;
        int i2;
        int islow;
        // 'vad_wave:11' if (k > length(tends))
        if (k > static_cast<unsigned int>(tends.size(1))) {
            // 'vad_wave:12' tends = [tends zeros(1, k, 'int64')];
            loop_ub = static_cast<int>(k);
            i1 = tends.size(1);
            tends.set_size(tends.size(0), tends.size(1) + static_cast<int>(k));
            for (i2 = 0; i2 < loop_ub; i2++) {
                tends[i1 + i2] = 0LL;
            }
            // 'vad_wave:13' tstarts = [tstarts zeros(1, k, 'int64')];
            i1 = tstarts.size(1);
            tstarts.set_size(tstarts.size(0),
                             tstarts.size(1) + static_cast<int>(k));
            for (i2 = 0; i2 < loop_ub; i2++) {
                tstarts[i1 + i2] = 0LL;
            }
        }
        // 'vad_wave:16' tstarts(k) = starts(i);
        tstarts[static_cast<int>(k) - 1] = starts[b_i];
        // 'vad_wave:17' islow = 0;
        islow = 0;
        // 'vad_wave:18' count = 0;
        count = 0.0;
        // 'vad_wave:19' lowb = int64(-1);
        lowb = -1LL;
        // 'vad_wave:21' for j = starts(i) + 1:ends(i)
        q0 = starts[b_i];
        if (q0 > 9223372036854775806LL) {
            q0 = MAX_int64_T;
        } else {
            q0++;
        }
        for (long long j = q0; j <= ends[b_i]; j++) {
            double d;
            boolean_T guard1 = false;
            // 'vad_wave:23' if array(j) - array(j - 1) < -0.01
            if (j < -9223372036854775807LL) {
                q0 = MIN_int64_T;
            } else {
                q0 = j - 1LL;
            }
            d = array[static_cast<int>(j) - 1];
            if (d - array[static_cast<int>(q0) - 1] < -0.01) {
                // 'vad_wave:24' islow = 1;
                islow = 1;
            }
            // 'vad_wave:27' if islow == 1 && abs(array(j) - array(j - 1)) <=
            // 0.01
            guard1 = false;
            if (islow == 1) {
                if (j < -9223372036854775807LL) {
                    q0 = MIN_int64_T;
                } else {
                    q0 = j - 1LL;
                }
                if (coder::b_abs(d - array[static_cast<int>(q0) - 1]) <= 0.01) {
                    // 'vad_wave:28' count = count + 1;
                    count++;
                    // 'vad_wave:30' if (lowb == int64(-1))
                    if (lowb == -1LL) {
                        // 'vad_wave:31' lowb = j;
                        lowb = j;
                    }
                } else {
                    guard1 = true;
                }
            } else {
                guard1 = true;
            }
            if (guard1 && (islow == 1)) {
                // 'vad_wave:34' elseif islow == 1
                // 连续下降的特殊情况
                // 'vad_wave:36' if array(j) < array(j - 1)
                if (j < -9223372036854775807LL) {
                    q0 = MIN_int64_T;
                } else {
                    q0 = j - 1LL;
                }
                if (d < array[static_cast<int>(q0) - 1]) {
                    // 后一个点抬升
                    // 'vad_wave:38' if (j + 1 < ends(i) && array(j + 1) -
                    // array(j) <= 0.01)
                    if (j > 9223372036854775806LL) {
                        q0 = MAX_int64_T;
                    } else {
                        q0 = j + 1LL;
                    }
                    if (q0 < ends[b_i]) {
                        if (j > 9223372036854775806LL) {
                            q0 = MAX_int64_T;
                        } else {
                            q0 = j + 1LL;
                        }
                        if (array[static_cast<int>(q0) - 1] - d <= 0.01) {
                            // 'vad_wave:39' lowb = j;
                            lowb = j;
                            // j+1;
                            // %lowb针对连续下降不断往后推，直到碰到抬升点，lowb记录的是最后一个非上升点，波谷的前一个点
                        }
                    }
                } else {
                    // 'vad_wave:42' else
                    // 'vad_wave:44' if (count >= 3)
                    if (count >= 3.0) {
                        // 'vad_wave:46' if (k > length(tends))
                        if (static_cast<int>(k) > tends.size(1)) {
                            // 'vad_wave:47' tends = [tends zeros(1, k,
                            // 'int64')];
                            i1 = tends.size(1);
                            loop_ub = static_cast<int>(k);
                            tends.set_size(tends.size(0),
                                           tends.size(1) + static_cast<int>(k));
                            for (i2 = 0; i2 < loop_ub; i2++) {
                                tends[i1 + i2] = 0LL;
                            }
                            // 'vad_wave:48' tstarts = [tstarts zeros(1, k,
                            // 'int64')];
                            i1 = tstarts.size(1);
                            loop_ub = static_cast<int>(k);
                            tstarts.set_size(tstarts.size(0),
                                             tstarts.size(1) +
                                                 static_cast<int>(k));
                            for (i2 = 0; i2 < loop_ub; i2++) {
                                tstarts[i1 + i2] = 0LL;
                            }
                        }
                        // 'vad_wave:51' tends(k) = lowb;
                        tends[static_cast<int>(k) - 1] = lowb;
                        // 'vad_wave:52' k = k + 1;
                        k++;
                        // 'vad_wave:54' if (k > length(tends))
                        if (k > static_cast<unsigned int>(tends.size(1))) {
                            // 'vad_wave:55' tends = [tends zeros(1, k,
                            // 'int64')];
                            i1 = tends.size(1);
                            loop_ub = static_cast<int>(k);
                            tends.set_size(tends.size(0),
                                           tends.size(1) + static_cast<int>(k));
                            for (i2 = 0; i2 < loop_ub; i2++) {
                                tends[i1 + i2] = 0LL;
                            }
                            // 'vad_wave:56' tstarts = [tstarts zeros(1, k,
                            // 'int64')];
                            i1 = tstarts.size(1);
                            loop_ub = static_cast<int>(k);
                            tstarts.set_size(tstarts.size(0),
                                             tstarts.size(1) +
                                                 static_cast<int>(k));
                            for (i2 = 0; i2 < loop_ub; i2++) {
                                tstarts[i1 + i2] = 0LL;
                            }
                        }
                        // 'vad_wave:59' tstarts(k) = j - 1;
                        if (j < -9223372036854775807LL) {
                            q0 = MIN_int64_T;
                        } else {
                            q0 = j - 1LL;
                        }
                        tstarts[static_cast<int>(k) - 1] = q0;
                        // 'vad_wave:60' islow = 0;
                        islow = 0;
                        // 'vad_wave:61' lowb = int64(-1);
                        lowb = -1LL;
                    }
                    // 'vad_wave:64' count = 0;
                    count = 0.0;
                }
            }
        }
        // 'vad_wave:71' if (k > length(tends))
        if (static_cast<int>(k) > tends.size(1)) {
            // 'vad_wave:72' tends = [tends zeros(1, k, 'int64')];
            loop_ub = static_cast<int>(k);
            i1 = tends.size(1);
            tends.set_size(tends.size(0), tends.size(1) + static_cast<int>(k));
            for (i2 = 0; i2 < loop_ub; i2++) {
                tends[i1 + i2] = 0LL;
            }
            // 'vad_wave:73' tstarts = [tstarts zeros(1, k, 'int64')];
            loop_ub = static_cast<int>(k);
            i1 = tstarts.size(1);
            tstarts.set_size(tstarts.size(0),
                             tstarts.size(1) + static_cast<int>(k));
            for (i2 = 0; i2 < loop_ub; i2++) {
                tstarts[i1 + i2] = 0LL;
            }
        }
        // 'vad_wave:76' tends(k) = ends(i);
        tends[static_cast<int>(k) - 1] = ends[b_i];
        // 'vad_wave:77' k = k + 1;
        k++;
    }
    // 'vad_wave:81' ostarts = tstarts(1:k - 1)';
    if (1 > static_cast<int>(k - 1U)) {
        loop_ub = 0;
    } else {
        loop_ub = static_cast<int>(k) - 1;
    }
    ostarts.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
        ostarts[i] = tstarts[i];
    }
    // 'vad_wave:82' oends = tends(1:k - 1)';
    if (1 > static_cast<int>(k - 1U)) {
        loop_ub = 0;
    } else {
        loop_ub = static_cast<int>(k) - 1;
    }
    oends.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
        oends[i] = tends[i];
    }
}

//
// File trailer for vad_wave.cpp
//
// [EOF]
//
