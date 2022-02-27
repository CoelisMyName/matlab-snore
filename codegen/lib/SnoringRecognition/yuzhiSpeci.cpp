//
// File: yuzhiSpeci.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 27-Feb-2022 00:06:11
//

// Include Files
#include "yuzhiSpeci.h"
#include "histcounts.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"

// Function Definitions
//
// function pianyi = yuzhiSpeci(d, position)
//
// Arguments    : const coder::array<double, 2U> &d
//                double position
// Return Type  : double
//
double yuzhiSpeci(const coder::array<double, 2U> &d, double position)
{
    coder::array<double, 2U> ddn;
    coder::array<double, 2U> ddnns;
    coder::array<double, 2U> dn;
    double a__1_data[21];
    double ddnn_data[20];
    double b_up_tmp;
    double down;
    double m;
    double pianyi;
    double up;
    double up_tmp;
    int a__1_size[2];
    int ddnn_size[2];
    int i;
    int iindx;
    int partialTrueCount;
    int trueCount;
    // 'yuzhiSpeci:2' up = (max(d) - min(d)) / 200 * position + min(d);
    up_tmp = coder::internal::minimum(d);
    b_up_tmp = (coder::internal::maximum(d) - up_tmp) / 200.0;
    up = b_up_tmp * position + up_tmp;
    // 'yuzhiSpeci:3' down = (max(d) - min(d)) / 200 * (position - 1) + min(d);
    down = b_up_tmp * (position - 1.0) + up_tmp;
    // 'yuzhiSpeci:4' dn = sort(d);
    dn.set_size(1, d.size(1));
    iindx = d.size(1);
    for (trueCount = 0; trueCount < iindx; trueCount++) {
        dn[trueCount] = d[trueCount];
    }
    coder::internal::b_sort(dn);
    // 'yuzhiSpeci:5' ddn = dn(dn <= up);
    iindx = dn.size(1) - 1;
    trueCount = 0;
    for (i = 0; i <= iindx; i++) {
        if (dn[i] <= up) {
            trueCount++;
        }
    }
    ddn.set_size(1, trueCount);
    partialTrueCount = 0;
    for (i = 0; i <= iindx; i++) {
        up_tmp = dn[i];
        if (up_tmp <= up) {
            ddn[partialTrueCount] = up_tmp;
            partialTrueCount++;
        }
    }
    // 'yuzhiSpeci:6' ddn = ddn(ddn > down);
    iindx = ddn.size(1) - 1;
    trueCount = 0;
    for (i = 0; i <= iindx; i++) {
        if (ddn[i] > down) {
            trueCount++;
        }
    }
    partialTrueCount = 0;
    for (i = 0; i <= iindx; i++) {
        if (ddn[i] > down) {
            ddn[partialTrueCount] = ddn[i];
            partialTrueCount++;
        }
    }
    ddn.set_size(1, trueCount);
    // 'yuzhiSpeci:7' [ddnn, ~] = histcounts(ddn, 20);
    coder::histcounts(ddn, ddnn_data, ddnn_size, a__1_data, a__1_size);
    // 'yuzhiSpeci:8' [~, ddmp] = max(ddnn);
    coder::internal::b_maximum(ddnn_data, &up_tmp, &iindx);
    // 'yuzhiSpeci:9' ddnns = sort(ddnn);
    ddnns.set_size(1, 20);
    for (trueCount = 0; trueCount < 20; trueCount++) {
        ddnns[trueCount] = ddnn_data[trueCount];
    }
    coder::internal::b_sort(ddnns);
    // 'yuzhiSpeci:10' m = ddnns(end) / ddnns(end - 1);
    m = ddnns[ddnns.size(1) - 1] / ddnns[ddnns.size(1) - 2];
    // 'yuzhiSpeci:12' if ddmp > 15
    if (iindx > 15) {
        // 'yuzhiSpeci:13' pianyi = max(ddnns);
        pianyi = coder::internal::maximum(ddnns);
    } else if (m >= 20.0) {
        // 'yuzhiSpeci:14' elseif m >= 20
        // 'yuzhiSpeci:15' pianyi = (max(ddnns) - min(ddnns)) / 20 * (ddmp + 4)
        // + min(ddnns);
        up_tmp = coder::internal::minimum(ddnns);
        pianyi = (coder::internal::maximum(ddnns) - up_tmp) / 20.0 *
                     (static_cast<double>(iindx) + 4.0) +
                 up_tmp;
    } else if (m > 10.0) {
        // 'yuzhiSpeci:16' elseif m > 10
        // 'yuzhiSpeci:17' pianyi = (max(ddnns) - min(ddnns)) / 20 * (ddmp + 5)
        // + min(ddnns);
        pianyi = (coder::internal::maximum(ddnns) -
                  coder::internal::minimum(ddnns)) /
                     20.0 * (static_cast<double>(iindx) + 5.0) +
                 coder::internal::minimum(ddnns);
    } else {
        // 'yuzhiSpeci:18' else
        // 'yuzhiSpeci:19' pianyi = max(ddnns);
        pianyi = coder::internal::maximum(ddnns);
    }
    return pianyi;
}

//
// File trailer for yuzhiSpeci.cpp
//
// [EOF]
//
