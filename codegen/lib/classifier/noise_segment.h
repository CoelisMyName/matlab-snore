//
// File: noise_segment.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

#ifndef NOISE_SEGMENT_H
#define NOISE_SEGMENT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void noise_segment(const coder::array<long long, 1U> &w_starts,
                          const coder::array<long long, 1U> &w_ends, double fs,
                          double min_gap, double margin, double *ostart,
                          double *olength);

#endif
//
// File trailer for noise_segment.h
//
// [EOF]
//
