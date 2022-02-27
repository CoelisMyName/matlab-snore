//
// File: vad_length_filter.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

#ifndef VAD_LENGTH_FILTER_H
#define VAD_LENGTH_FILTER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void vad_length_filter(const coder::array<long long, 2U> &starts,
                       const coder::array<long long, 2U> &ends, double min_len,
                       double max_len, coder::array<long long, 1U> &ostarts,
                       coder::array<long long, 1U> &oends);

#endif
//
// File trailer for vad_length_filter.h
//
// [EOF]
//
