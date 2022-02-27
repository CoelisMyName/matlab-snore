//
// File: abs.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "abs.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <math.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
void b_abs(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y)
{
    int nx;
    nx = x.size(0);
    y.set_size(x.size(0));
    for (int k = 0; k < nx; k++) {
        y[k] = fabs(x[k]);
    }
}

//
// Arguments    : double x
// Return Type  : double
//
double b_abs(double x)
{
    return fabs(x);
}

} // namespace coder

//
// File trailer for abs.cpp
//
// [EOF]
//
