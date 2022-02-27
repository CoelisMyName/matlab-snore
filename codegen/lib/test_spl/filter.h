//
// File: filter.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 22:09:11
//

#ifndef FILTER_H
#define FILTER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void filter(const double b[7], const double a[7],
            const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y);

}

#endif
//
// File trailer for filter.h
//
// [EOF]
//
