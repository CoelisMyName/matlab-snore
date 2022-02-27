//
// File: sort.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "sort.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : double x[200]
// Return Type  : void
//
namespace coder {
namespace internal {
void sort(double x[200])
{
    double xwork[200];
    double x4[4];
    int idx[200];
    int iwork[200];
    int i1;
    int i2;
    int i3;
    int ib;
    int k;
    int nNaNs;
    unsigned char idx4[4];
    signed char perm[4];
    x4[0] = 0.0;
    idx4[0] = 0U;
    x4[1] = 0.0;
    idx4[1] = 0U;
    x4[2] = 0.0;
    idx4[2] = 0U;
    x4[3] = 0.0;
    idx4[3] = 0U;
    memset(&idx[0], 0, 200U * sizeof(int));
    memset(&xwork[0], 0, 200U * sizeof(double));
    nNaNs = 0;
    ib = 0;
    for (k = 0; k < 200; k++) {
        if (rtIsNaN(x[k])) {
            idx[199 - nNaNs] = k + 1;
            xwork[199 - nNaNs] = x[k];
            nNaNs++;
        } else {
            ib++;
            idx4[ib - 1] = static_cast<unsigned char>(k + 1);
            x4[ib - 1] = x[k];
            if (ib == 4) {
                double d;
                double d1;
                int i4;
                ib = k - nNaNs;
                if (x4[0] <= x4[1]) {
                    i1 = 1;
                    i2 = 2;
                } else {
                    i1 = 2;
                    i2 = 1;
                }
                if (x4[2] <= x4[3]) {
                    i3 = 3;
                    i4 = 4;
                } else {
                    i3 = 4;
                    i4 = 3;
                }
                d = x4[i1 - 1];
                d1 = x4[i3 - 1];
                if (d <= d1) {
                    d = x4[i2 - 1];
                    if (d <= d1) {
                        perm[0] = static_cast<signed char>(i1);
                        perm[1] = static_cast<signed char>(i2);
                        perm[2] = static_cast<signed char>(i3);
                        perm[3] = static_cast<signed char>(i4);
                    } else if (d <= x4[i4 - 1]) {
                        perm[0] = static_cast<signed char>(i1);
                        perm[1] = static_cast<signed char>(i3);
                        perm[2] = static_cast<signed char>(i2);
                        perm[3] = static_cast<signed char>(i4);
                    } else {
                        perm[0] = static_cast<signed char>(i1);
                        perm[1] = static_cast<signed char>(i3);
                        perm[2] = static_cast<signed char>(i4);
                        perm[3] = static_cast<signed char>(i2);
                    }
                } else {
                    d1 = x4[i4 - 1];
                    if (d <= d1) {
                        if (x4[i2 - 1] <= d1) {
                            perm[0] = static_cast<signed char>(i3);
                            perm[1] = static_cast<signed char>(i1);
                            perm[2] = static_cast<signed char>(i2);
                            perm[3] = static_cast<signed char>(i4);
                        } else {
                            perm[0] = static_cast<signed char>(i3);
                            perm[1] = static_cast<signed char>(i1);
                            perm[2] = static_cast<signed char>(i4);
                            perm[3] = static_cast<signed char>(i2);
                        }
                    } else {
                        perm[0] = static_cast<signed char>(i3);
                        perm[1] = static_cast<signed char>(i4);
                        perm[2] = static_cast<signed char>(i1);
                        perm[3] = static_cast<signed char>(i2);
                    }
                }
                idx[ib - 3] = idx4[perm[0] - 1];
                idx[ib - 2] = idx4[perm[1] - 1];
                idx[ib - 1] = idx4[perm[2] - 1];
                idx[ib] = idx4[perm[3] - 1];
                x[ib - 3] = x4[perm[0] - 1];
                x[ib - 2] = x4[perm[1] - 1];
                x[ib - 1] = x4[perm[2] - 1];
                x[ib] = x4[perm[3] - 1];
                ib = 0;
            }
        }
    }
    if (ib > 0) {
        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
        if (ib == 1) {
            perm[0] = 1;
        } else if (ib == 2) {
            if (x4[0] <= x4[1]) {
                perm[0] = 1;
                perm[1] = 2;
            } else {
                perm[0] = 2;
                perm[1] = 1;
            }
        } else if (x4[0] <= x4[1]) {
            if (x4[1] <= x4[2]) {
                perm[0] = 1;
                perm[1] = 2;
                perm[2] = 3;
            } else if (x4[0] <= x4[2]) {
                perm[0] = 1;
                perm[1] = 3;
                perm[2] = 2;
            } else {
                perm[0] = 3;
                perm[1] = 1;
                perm[2] = 2;
            }
        } else if (x4[0] <= x4[2]) {
            perm[0] = 2;
            perm[1] = 1;
            perm[2] = 3;
        } else if (x4[1] <= x4[2]) {
            perm[0] = 2;
            perm[1] = 3;
            perm[2] = 1;
        } else {
            perm[0] = 3;
            perm[1] = 2;
            perm[2] = 1;
        }
        for (k = 0; k < ib; k++) {
            i2 = perm[k] - 1;
            i1 = ((k - nNaNs) - ib) + 200;
            idx[i1] = idx4[i2];
            x[i1] = x4[i2];
        }
    }
    ib = (nNaNs >> 1) + 200;
    for (k = 0; k <= ib - 201; k++) {
        i2 = (k - nNaNs) + 200;
        i1 = idx[i2];
        idx[i2] = idx[199 - k];
        idx[199 - k] = i1;
        x[i2] = xwork[199 - k];
        x[199 - k] = xwork[i2];
    }
    if ((nNaNs & 1) != 0) {
        ib -= nNaNs;
        x[ib] = xwork[ib];
    }
    if (200 - nNaNs > 1) {
        memset(&iwork[0], 0, 200U * sizeof(int));
        i3 = (200 - nNaNs) >> 2;
        i1 = 4;
        while (i3 > 1) {
            if ((i3 & 1) != 0) {
                i3--;
                ib = i1 * i3;
                i2 = 200 - (nNaNs + ib);
                if (i2 > i1) {
                    merge(idx, x, ib, i1, i2 - i1, iwork, xwork);
                }
            }
            ib = i1 << 1;
            i3 >>= 1;
            for (k = 0; k < i3; k++) {
                merge(idx, x, k * ib, i1, i1, iwork, xwork);
            }
            i1 = ib;
        }
        if (200 - nNaNs > i1) {
            merge(idx, x, 0, i1, 200 - (nNaNs + i1), iwork, xwork);
        }
    }
}

//
// Arguments    : ::coder::array<double, 2U> &x
// Return Type  : void
//
void sort(::coder::array<double, 2U> &x)
{
    array<double, 1U> xwork;
    array<int, 2U> idx;
    array<int, 1U> iwork;
    double x4[4];
    int idx4[4];
    int ib;
    int quartetOffset;
    signed char perm[4];
    idx.set_size(1, x.size(1));
    ib = x.size(1);
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
        idx[quartetOffset] = 0;
    }
    if (x.size(1) != 0) {
        int b_n;
        int i1;
        int i3;
        int i4;
        int k;
        int n;
        int nNaNs;
        n = x.size(1);
        b_n = x.size(1);
        x4[0] = 0.0;
        idx4[0] = 0;
        x4[1] = 0.0;
        idx4[1] = 0;
        x4[2] = 0.0;
        idx4[2] = 0;
        x4[3] = 0.0;
        idx4[3] = 0;
        ib = x.size(1);
        iwork.set_size(ib);
        for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
            iwork[quartetOffset] = 0;
        }
        ib = x.size(1);
        xwork.set_size(ib);
        for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
            xwork[quartetOffset] = 0.0;
        }
        nNaNs = 0;
        ib = -1;
        for (k = 0; k < b_n; k++) {
            if (rtIsNaN(x[k])) {
                i3 = (b_n - nNaNs) - 1;
                idx[i3] = k + 1;
                xwork[i3] = x[k];
                nNaNs++;
            } else {
                ib++;
                idx4[ib] = k + 1;
                x4[ib] = x[k];
                if (ib + 1 == 4) {
                    double d;
                    double d1;
                    quartetOffset = k - nNaNs;
                    if (x4[0] <= x4[1]) {
                        i1 = 1;
                        ib = 2;
                    } else {
                        i1 = 2;
                        ib = 1;
                    }
                    if (x4[2] <= x4[3]) {
                        i3 = 3;
                        i4 = 4;
                    } else {
                        i3 = 4;
                        i4 = 3;
                    }
                    d = x4[i1 - 1];
                    d1 = x4[i3 - 1];
                    if (d <= d1) {
                        d = x4[ib - 1];
                        if (d <= d1) {
                            perm[0] = static_cast<signed char>(i1);
                            perm[1] = static_cast<signed char>(ib);
                            perm[2] = static_cast<signed char>(i3);
                            perm[3] = static_cast<signed char>(i4);
                        } else if (d <= x4[i4 - 1]) {
                            perm[0] = static_cast<signed char>(i1);
                            perm[1] = static_cast<signed char>(i3);
                            perm[2] = static_cast<signed char>(ib);
                            perm[3] = static_cast<signed char>(i4);
                        } else {
                            perm[0] = static_cast<signed char>(i1);
                            perm[1] = static_cast<signed char>(i3);
                            perm[2] = static_cast<signed char>(i4);
                            perm[3] = static_cast<signed char>(ib);
                        }
                    } else {
                        d1 = x4[i4 - 1];
                        if (d <= d1) {
                            if (x4[ib - 1] <= d1) {
                                perm[0] = static_cast<signed char>(i3);
                                perm[1] = static_cast<signed char>(i1);
                                perm[2] = static_cast<signed char>(ib);
                                perm[3] = static_cast<signed char>(i4);
                            } else {
                                perm[0] = static_cast<signed char>(i3);
                                perm[1] = static_cast<signed char>(i1);
                                perm[2] = static_cast<signed char>(i4);
                                perm[3] = static_cast<signed char>(ib);
                            }
                        } else {
                            perm[0] = static_cast<signed char>(i3);
                            perm[1] = static_cast<signed char>(i4);
                            perm[2] = static_cast<signed char>(i1);
                            perm[3] = static_cast<signed char>(ib);
                        }
                    }
                    idx[quartetOffset - 3] = idx4[perm[0] - 1];
                    idx[quartetOffset - 2] = idx4[perm[1] - 1];
                    idx[quartetOffset - 1] = idx4[perm[2] - 1];
                    idx[quartetOffset] = idx4[perm[3] - 1];
                    x[quartetOffset - 3] = x4[perm[0] - 1];
                    x[quartetOffset - 2] = x4[perm[1] - 1];
                    x[quartetOffset - 1] = x4[perm[2] - 1];
                    x[quartetOffset] = x4[perm[3] - 1];
                    ib = -1;
                }
            }
        }
        i4 = (b_n - nNaNs) - 1;
        if (ib + 1 > 0) {
            perm[1] = 0;
            perm[2] = 0;
            perm[3] = 0;
            if (ib + 1 == 1) {
                perm[0] = 1;
            } else if (ib + 1 == 2) {
                if (x4[0] <= x4[1]) {
                    perm[0] = 1;
                    perm[1] = 2;
                } else {
                    perm[0] = 2;
                    perm[1] = 1;
                }
            } else if (x4[0] <= x4[1]) {
                if (x4[1] <= x4[2]) {
                    perm[0] = 1;
                    perm[1] = 2;
                    perm[2] = 3;
                } else if (x4[0] <= x4[2]) {
                    perm[0] = 1;
                    perm[1] = 3;
                    perm[2] = 2;
                } else {
                    perm[0] = 3;
                    perm[1] = 1;
                    perm[2] = 2;
                }
            } else if (x4[0] <= x4[2]) {
                perm[0] = 2;
                perm[1] = 1;
                perm[2] = 3;
            } else if (x4[1] <= x4[2]) {
                perm[0] = 2;
                perm[1] = 3;
                perm[2] = 1;
            } else {
                perm[0] = 3;
                perm[1] = 2;
                perm[2] = 1;
            }
            for (k = 0; k <= ib; k++) {
                i3 = perm[k] - 1;
                quartetOffset = (i4 - ib) + k;
                idx[quartetOffset] = idx4[i3];
                x[quartetOffset] = x4[i3];
            }
        }
        ib = (nNaNs >> 1) + 1;
        for (k = 0; k <= ib - 2; k++) {
            quartetOffset = (i4 + k) + 1;
            i1 = idx[quartetOffset];
            i3 = (b_n - k) - 1;
            idx[quartetOffset] = idx[i3];
            idx[i3] = i1;
            x[quartetOffset] = xwork[i3];
            x[i3] = xwork[quartetOffset];
        }
        if ((nNaNs & 1) != 0) {
            quartetOffset = i4 + ib;
            x[quartetOffset] = xwork[quartetOffset];
        }
        i1 = n - nNaNs;
        ib = 2;
        if (i1 > 1) {
            if (n >= 256) {
                quartetOffset = i1 >> 8;
                if (quartetOffset > 0) {
                    for (ib = 0; ib < quartetOffset; ib++) {
                        merge_pow2_block(idx, x, ib << 8);
                    }
                    ib = quartetOffset << 8;
                    quartetOffset = i1 - ib;
                    if (quartetOffset > 0) {
                        merge_block(idx, x, ib, quartetOffset, 2, iwork, xwork);
                    }
                    ib = 8;
                }
            }
            merge_block(idx, x, 0, i1, ib, iwork, xwork);
        }
    }
}

} // namespace internal
} // namespace coder

//
// File trailer for sort.cpp
//
// [EOF]
//
