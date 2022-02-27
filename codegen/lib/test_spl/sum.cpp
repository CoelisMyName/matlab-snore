//
// File: sum.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 22:09:11
//

// Include Files
#include "sum.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &x
// Return Type  : double
//
namespace coder {
double sum(const ::coder::array<double, 1U> &x)
{
    double y;
    if (x.size(0) == 0) {
        y = 0.0;
    } else {
        int firstBlockLength;
        int k;
        int lastBlockLength;
        int nblocks;
        if (x.size(0) <= 1024) {
            firstBlockLength = x.size(0);
            lastBlockLength = 0;
            nblocks = 1;
        } else {
            firstBlockLength = 1024;
            nblocks = x.size(0) / 1024;
            lastBlockLength = x.size(0) - (nblocks << 10);
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

//
// Arguments    : const double x[8]
// Return Type  : double
//
double sum(const double x[8])
{
    double y;
    y = x[0];
    for (int k = 0; k < 7; k++) {
        y += x[k + 1];
    }
    return y;
}

} // namespace coder

//
// File trailer for sum.cpp
//
// [EOF]
//