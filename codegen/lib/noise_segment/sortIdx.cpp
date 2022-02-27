//
// File: sortIdx.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "sortIdx.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace coder {
namespace internal {
static void merge(::coder::array<int, 2U> &idx, ::coder::array<double, 2U> &x,
                  int offset, int np, int nq, ::coder::array<int, 1U> &iwork,
                  ::coder::array<double, 1U> &xwork);

}
} // namespace coder

// Function Definitions
//
// Arguments    : ::coder::array<int, 2U> &idx
//                ::coder::array<double, 2U> &x
//                int offset
//                int np
//                int nq
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<double, 1U> &xwork
// Return Type  : void
//
namespace coder {
namespace internal {
static void merge(::coder::array<int, 2U> &idx, ::coder::array<double, 2U> &x,
                  int offset, int np, int nq, ::coder::array<int, 1U> &iwork,
                  ::coder::array<double, 1U> &xwork)
{
    if (nq != 0) {
        int iout;
        int j;
        int n_tmp;
        int p;
        int q;
        n_tmp = np + nq;
        for (j = 0; j < n_tmp; j++) {
            iout = offset + j;
            iwork[j] = idx[iout];
            xwork[j] = x[iout];
        }
        p = 0;
        q = np;
        iout = offset - 1;
        int exitg1;
        do {
            exitg1 = 0;
            iout++;
            if (xwork[p] <= xwork[q]) {
                idx[iout] = iwork[p];
                x[iout] = xwork[p];
                if (p + 1 < np) {
                    p++;
                } else {
                    exitg1 = 1;
                }
            } else {
                idx[iout] = iwork[q];
                x[iout] = xwork[q];
                if (q + 1 < n_tmp) {
                    q++;
                } else {
                    q = iout - p;
                    for (j = p + 1; j <= np; j++) {
                        iout = q + j;
                        idx[iout] = iwork[j - 1];
                        x[iout] = xwork[j - 1];
                    }
                    exitg1 = 1;
                }
            }
        } while (exitg1 == 0);
    }
}

//
// Arguments    : int idx[200]
//                double x[200]
//                int offset
//                int np
//                int nq
//                int iwork[200]
//                double xwork[200]
// Return Type  : void
//
void merge(int idx[200], double x[200], int offset, int np, int nq,
           int iwork[200], double xwork[200])
{
    if (nq != 0) {
        int iout;
        int j;
        int n_tmp;
        int p;
        int q;
        n_tmp = np + nq;
        for (j = 0; j < n_tmp; j++) {
            iout = offset + j;
            iwork[j] = idx[iout];
            xwork[j] = x[iout];
        }
        p = 0;
        q = np;
        iout = offset - 1;
        int exitg1;
        do {
            exitg1 = 0;
            iout++;
            if (xwork[p] <= xwork[q]) {
                idx[iout] = iwork[p];
                x[iout] = xwork[p];
                if (p + 1 < np) {
                    p++;
                } else {
                    exitg1 = 1;
                }
            } else {
                idx[iout] = iwork[q];
                x[iout] = xwork[q];
                if (q + 1 < n_tmp) {
                    q++;
                } else {
                    q = iout - p;
                    for (j = p + 1; j <= np; j++) {
                        iout = q + j;
                        idx[iout] = iwork[j - 1];
                        x[iout] = xwork[j - 1];
                    }
                    exitg1 = 1;
                }
            }
        } while (exitg1 == 0);
    }
}

//
// Arguments    : ::coder::array<int, 2U> &idx
//                ::coder::array<double, 2U> &x
//                int offset
//                int n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<double, 1U> &xwork
// Return Type  : void
//
void merge_block(::coder::array<int, 2U> &idx, ::coder::array<double, 2U> &x,
                 int offset, int n, int preSortLevel,
                 ::coder::array<int, 1U> &iwork,
                 ::coder::array<double, 1U> &xwork)
{
    int bLen;
    int nPairs;
    nPairs = n >> preSortLevel;
    bLen = 1 << preSortLevel;
    while (nPairs > 1) {
        int nTail;
        int tailOffset;
        if ((nPairs & 1) != 0) {
            nPairs--;
            tailOffset = bLen * nPairs;
            nTail = n - tailOffset;
            if (nTail > bLen) {
                merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                      xwork);
            }
        }
        tailOffset = bLen << 1;
        nPairs >>= 1;
        for (nTail = 0; nTail < nPairs; nTail++) {
            merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork,
                  xwork);
        }
        bLen = tailOffset;
    }
    if (n > bLen) {
        merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
    }
}

//
// Arguments    : ::coder::array<int, 2U> &idx
//                ::coder::array<double, 2U> &x
//                int offset
// Return Type  : void
//
void merge_pow2_block(::coder::array<int, 2U> &idx,
                      ::coder::array<double, 2U> &x, int offset)
{
    double xwork[256];
    int iwork[256];
    for (int b = 0; b < 6; b++) {
        int bLen;
        int bLen2;
        int nPairs;
        bLen = 1 << (b + 2);
        bLen2 = bLen << 1;
        nPairs = 256 >> (b + 3);
        for (int k = 0; k < nPairs; k++) {
            int blockOffset;
            int iout;
            int j;
            int p;
            int q;
            blockOffset = offset + k * bLen2;
            for (j = 0; j < bLen2; j++) {
                iout = blockOffset + j;
                iwork[j] = idx[iout];
                xwork[j] = x[iout];
            }
            p = 0;
            q = bLen;
            iout = blockOffset - 1;
            int exitg1;
            do {
                exitg1 = 0;
                iout++;
                if (xwork[p] <= xwork[q]) {
                    idx[iout] = iwork[p];
                    x[iout] = xwork[p];
                    if (p + 1 < bLen) {
                        p++;
                    } else {
                        exitg1 = 1;
                    }
                } else {
                    idx[iout] = iwork[q];
                    x[iout] = xwork[q];
                    if (q + 1 < bLen2) {
                        q++;
                    } else {
                        iout -= p;
                        for (j = p + 1; j <= bLen; j++) {
                            q = iout + j;
                            idx[q] = iwork[j - 1];
                            x[q] = xwork[j - 1];
                        }
                        exitg1 = 1;
                    }
                }
            } while (exitg1 == 0);
        }
    }
}

} // namespace internal
} // namespace coder

//
// File trailer for sortIdx.cpp
//
// [EOF]
//
