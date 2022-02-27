//
// File: cweight.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 22:09:11
//

// Include Files
#include "cweight.h"
#include "log10.h"
#include "octbank.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "test_spl_data.h"
#include "coder_array.h"

// Function Definitions
//
// function [p, f, s] = cweight(x)
//
// Arguments    : const coder::array<double, 1U> &x
//                double p[8]
//                double f[8]
//                double *s
// Return Type  : void
//
void cweight(const coder::array<double, 1U> &x, double p[8], double f[8],
             double *s)
{
    static const double weight[8] = {-0.8, -0.2, 0.0,  0.0,
                                     0.0,  -0.2, -0.8, -3.0};
    double dv[8];
    double dv1[8];
    double d;
    int i;
    for (i = 0; i < 8; i++) {
        f[i] = iv[i];
    }
    // 'cweight:2' [p, f] = octbank(x, 44100);
    octbank(x, p);
    // 'cweight:3' weight = [-0.8 -0.2 0 0 0 -0.2 -0.8 -3.0];
    // 'cweight:4' p = p + weight;
    // 'cweight:5' a = 10.^(0.1 * (p));
    // 'cweight:6' s = 10 * log10(sum(a));
    for (i = 0; i < 8; i++) {
        d = p[i] + weight[i];
        p[i] = d;
        dv[i] = 0.1 * d;
    }
    coder::power(dv, dv1);
    d = coder::sum(dv1);
    coder::b_log10(&d);
    *s = 10.0 * d;
}

//
// File trailer for cweight.cpp
//
// [EOF]
//