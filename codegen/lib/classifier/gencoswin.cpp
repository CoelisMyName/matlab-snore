//
// File: gencoswin.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "gencoswin.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <math.h>

// Function Definitions
//
// Arguments    : double m
//                double n
//                ::coder::array<double, 1U> &w
// Return Type  : void
//
namespace coder {
void calc_window(double m, double n, ::coder::array<double, 1U> &w)
{
    array<double, 2U> y;
    int k;
    int nx;
    if (rtIsNaN(m - 1.0)) {
        y.set_size(1, 1);
        y[0] = rtNaN;
    } else if (m - 1.0 < 0.0) {
        y.set_size(1, 0);
    } else if (rtIsInf(m - 1.0) && (0.0 == m - 1.0)) {
        y.set_size(1, 1);
        y[0] = rtNaN;
    } else {
        nx = static_cast<int>(floor(m - 1.0));
        y.set_size(1, nx + 1);
        for (k = 0; k <= nx; k++) {
            y[k] = k;
        }
    }
    w.set_size(y.size(1));
    nx = y.size(1);
    for (k = 0; k < nx; k++) {
        w[k] = 6.2831853071795862 * (y[k] / (n - 1.0));
    }
    nx = w.size(0);
    for (k = 0; k < nx; k++) {
        w[k] = cos(w[k]);
    }
    nx = w.size(0);
    for (k = 0; k < nx; k++) {
        w[k] = 0.54 - 0.46 * w[k];
    }
}

} // namespace coder

//
// File trailer for gencoswin.cpp
//
// [EOF]
//