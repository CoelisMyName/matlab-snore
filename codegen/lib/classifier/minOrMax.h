//
// File: minOrMax.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

#ifndef MINORMAX_H
#define MINORMAX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void b_maximum(const double x_data[], double *ex, int *idx);

void maximum(const ::coder::array<double, 2U> &x, double ex_data[],
             int ex_size[2]);

void maximum(const ::coder::array<double, 2U> &x, double ex[12]);

double maximum(const ::coder::array<double, 1U> &x);

void maximum(const double x[200], double *ex, int *idx);

double maximum(const ::coder::array<double, 2U> &x);

void minimum(const ::coder::array<double, 2U> &x, double ex_data[],
             int ex_size[2]);

void minimum(const ::coder::array<double, 2U> &x, double ex[12]);

double minimum(const ::coder::array<double, 2U> &x);

double minimum2(double x, double y);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for minOrMax.h
//
// [EOF]
//