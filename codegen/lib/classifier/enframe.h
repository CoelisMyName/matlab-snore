//
// File: enframe.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

#ifndef ENFRAME_H
#define ENFRAME_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void enframe(const coder::array<double, 1U> &x, double win, double inc,
             coder::array<double, 2U> &f);

void enframe(const coder::array<double, 1U> &x,
             const coder::array<double, 1U> &win, double inc,
             coder::array<double, 2U> &f);

#endif
//
// File trailer for enframe.h
//
// [EOF]
//
