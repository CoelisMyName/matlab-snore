//
// File: power.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 22:09:11
//

// Include Files
#include "power.h"
#include "rt_nonfinite.h"
#include "test_spl_rtwutil.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &a
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
void power(const ::coder::array<double, 1U> &a, ::coder::array<double, 1U> &y)
{
    int nx;
    y.set_size(a.size(0));
    nx = a.size(0);
    for (int k = 0; k < nx; k++) {
        y[k] = a[k] * a[k];
    }
}

//
// Arguments    : const double b[8]
//                double y[8]
// Return Type  : void
//
void power(const double b[8], double y[8])
{
    for (int k = 0; k < 8; k++) {
        y[k] = rt_powd_snf(10.0, b[k]);
    }
}

} // namespace coder

//
// File trailer for power.cpp
//
// [EOF]
//
