//
// File: mtimes.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 2U> &B
//                double C_data[]
//                int *C_size
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void mtimes(const ::coder::array<double, 2U> &A,
            const ::coder::array<double, 2U> &B, double C_data[], int *C_size)
{
    int inner;
    inner = A.size(1);
    *C_size = 16;
    memset(&C_data[0], 0, 16U * sizeof(double));
    for (int k = 0; k < inner; k++) {
        int aoffset;
        aoffset = k << 4;
        for (int i = 0; i < 16; i++) {
            C_data[i] += A[aoffset + i] * B[k];
        }
    }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for mtimes.cpp
//
// [EOF]
//
