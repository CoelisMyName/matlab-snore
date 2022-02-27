//
// File: mpower.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "mpower.h"
#include "classifier_rtwutil.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : double a
//                double b
// Return Type  : double
//
namespace coder {
double mpower(double a, double b)
{
    return rt_powd_snf(a, b);
}

} // namespace coder

//
// File trailer for mpower.cpp
//
// [EOF]
//
