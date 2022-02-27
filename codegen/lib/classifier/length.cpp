//
// File: length.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "length.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int varargin_1
//                int varargin_2
// Return Type  : int
//
namespace coder {
namespace internal {
int intlength(int varargin_1, int varargin_2)
{
    int n;
    if ((varargin_1 == 0) || (varargin_2 == 0)) {
        n = 0;
    } else if (varargin_1 > 1) {
        n = varargin_1;
    } else {
        n = 1;
    }
    return n;
}

} // namespace internal
} // namespace coder

//
// File trailer for length.cpp
//
// [EOF]
//
