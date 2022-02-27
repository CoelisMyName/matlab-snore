//
// File: filter.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 22:09:11
//

// Include Files
#include "filter.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const double b[7]
//                const double a[7]
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
void filter(const double b[7], const double a[7],
            const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y)
{
    int loop_ub;
    int naxpy;
    int nx;
    nx = x.size(0) - 1;
    y.set_size(x.size(0));
    loop_ub = x.size(0);
    for (naxpy = 0; naxpy < loop_ub; naxpy++) {
        y[naxpy] = 0.0;
    }
    for (int k = 0; k <= nx; k++) {
        double as;
        int j;
        int y_tmp;
        loop_ub = nx - k;
        naxpy = loop_ub + 1;
        if (naxpy >= 7) {
            naxpy = 7;
        }
        for (j = 0; j < naxpy; j++) {
            y_tmp = k + j;
            y[y_tmp] = y[y_tmp] + x[k] * b[j];
        }
        if (loop_ub < 6) {
            naxpy = loop_ub;
        } else {
            naxpy = 6;
        }
        as = -y[k];
        for (j = 0; j < naxpy; j++) {
            y_tmp = (k + j) + 1;
            y[y_tmp] = y[y_tmp] + as * a[j + 1];
        }
    }
}

} // namespace coder

//
// File trailer for filter.cpp
//
// [EOF]
//
