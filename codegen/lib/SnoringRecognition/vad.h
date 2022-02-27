//
// File: vad.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 27-Feb-2022 00:06:11
//

#ifndef VAD_H
#define VAD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void vad(coder::array<double, 1U> &x, double fs,
                coder::array<long long, 2U> &w_starts,
                coder::array<long long, 2U> &w_ends);

#endif
//
// File trailer for vad.h
//
// [EOF]
//
