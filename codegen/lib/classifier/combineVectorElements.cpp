//
// File: combineVectorElements.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 2U> &x
// Return Type  : int
//
namespace coder {
int b_combineVectorElements(const ::coder::array<boolean_T, 2U> &x)
{
    int vlen;
    int y;
    vlen = x.size(1);
    if (x.size(1) == 0) {
        y = 0;
    } else {
        y = x[0];
        for (int k = 2; k <= vlen; k++) {
            y += x[k - 1];
        }
    }
    return y;
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                double y[17]
// Return Type  : void
//
void combineVectorElements(const ::coder::array<double, 2U> &x, double y[17])
{
    if (x.size(0) == 0) {
        memset(&y[0], 0, 17U * sizeof(double));
    } else {
        int firstBlockLength;
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
        for (int xi = 0; xi < 17; xi++) {
            int k;
            int xpageoffset;
            xpageoffset = xi * x.size(0);
            y[xi] = x[xpageoffset];
            for (k = 2; k <= firstBlockLength; k++) {
                y[xi] += x[(xpageoffset + k) - 1];
            }
            for (int ib = 2; ib <= nblocks; ib++) {
                double bsum;
                int hi;
                int xblockoffset;
                xblockoffset = xpageoffset + ((ib - 1) << 10);
                bsum = x[xblockoffset];
                if (ib == nblocks) {
                    hi = lastBlockLength;
                } else {
                    hi = 1024;
                }
                for (k = 2; k <= hi; k++) {
                    bsum += x[(xblockoffset + k) - 1];
                }
                y[xi] += bsum;
            }
        }
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
// Return Type  : double
//
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