//
// File: sum.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "sum.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
// Return Type  : double
//
namespace coder {
double sum(const ::coder::array<double, 2U> &x)
{
    return combineVectorElements(x);
}

} // namespace coder

//
// File trailer for sum.cpp
//
// [EOF]
//
