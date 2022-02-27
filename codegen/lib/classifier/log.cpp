//
// File: log.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "log.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <math.h>

// Function Definitions
//
// Arguments    : double x[2]
// Return Type  : void
//
namespace coder {
void b_log(double x[2])
{
    x[0] = log(x[0]);
    x[1] = log(x[1]);
}

//
// Arguments    : ::coder::array<double, 2U> &x
// Return Type  : void
//
void b_log(::coder::array<double, 2U> &x)
{
    int nx;
    nx = x.size(1);
    for (int k = 0; k < nx; k++) {
        x[k] = log(x[k]);
    }
}

//
// Arguments    : double x_data[]
// Return Type  : void
//
void c_log(double x_data[])
{
    for (int k = 0; k < 16; k++) {
        x_data[k] = log(x_data[k]);
    }
}

} // namespace coder

//
// File trailer for log.cpp
//
// [EOF]
//
