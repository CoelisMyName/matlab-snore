//
// File: levinson.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

#ifndef LEVINSON_H
#define LEVINSON_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void levinson(const ::coder::array<creal_T, 1U> &R, creal_T A_data[],
              int A_size[2], double E_data[], int E_size[2]);

}

#endif
//
// File trailer for levinson.h
//
// [EOF]
//
