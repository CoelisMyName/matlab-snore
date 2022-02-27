//
// File: mean.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "mean.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
// Return Type  : double
//
namespace coder {
double mean(const ::coder::array<double, 2U> &x)
{
    return combineVectorElements(x) / static_cast<double>(x.size(1));
}

} // namespace coder

//
// File trailer for mean.cpp
//
// [EOF]
//
