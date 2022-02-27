//
// File: combineVectorElements.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
// Return Type  : double
//
namespace coder {
double combineVectorElements(const ::coder::array<double, 2U> &x)
{
    double y;
    if (x.size(1) == 0) {
        y = 0.0;
    } else {
        int firstBlockLength;
        int k;
        int lastBlockLength;
        int nblocks;
        if (x.size(1) <= 1024) {
            firstBlockLength = x.size(1);
            lastBlockLength = 0;
            nblocks = 1;
        } else {
            firstBlockLength = 1024;
            nblocks = x.size(1) / 1024;
            lastBlockLength = x.size(1) - (nblocks << 10);
            if (lastBlockLength > 0) {
                nblocks++;
            } else {
                lastBlockLength = 1024;
            }
        }
        y = x[0];
        for (k = 2; k <= firstBlockLength; k++) {
            y += x[k - 1];
        }
        for (int ib = 2; ib <= nblocks; ib++) {
            double bsum;
            int hi;
            firstBlockLength = (ib - 1) << 10;
            bsum = x[firstBlockLength];
            if (ib == nblocks) {
                hi = lastBlockLength;
            } else {
                hi = 1024;
            }
            for (k = 2; k <= hi; k++) {
                bsum += x[(firstBlockLength + k) - 1];
            }
            y += bsum;
        }
    }
    return y;
}

} // namespace coder

//
// File trailer for combineVectorElements.cpp
//
// [EOF]
//
