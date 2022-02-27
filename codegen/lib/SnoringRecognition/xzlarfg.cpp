//
// File: xzlarfg.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 27-Feb-2022 11:31:05
//

// Include Files
#include "xzlarfg.h"
#include "SnoringRecognition_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <math.h>

// Function Definitions
//
// Arguments    : int n
//                double *alpha1
//                double x[3]
// Return Type  : double
//
namespace coder {
namespace internal {
namespace reflapack {
double xzlarfg(int n, double *alpha1, double x[3])
{
    double tau;
    tau = 0.0;
    if (n > 0) {
        double xnorm;
        xnorm = blas::xnrm2(n - 1, x);
        if (xnorm != 0.0) {
            double beta1;
            beta1 = rt_hypotd_snf(*alpha1, xnorm);
            if (*alpha1 >= 0.0) {
                beta1 = -beta1;
            }
            if (fabs(beta1) < 1.0020841800044864E-292) {
                int k;
                int knt;
                knt = -1;
                do {
                    knt++;
                    for (k = 2; k <= n; k++) {
                        x[k - 1] *= 9.9792015476736E+291;
                    }
                    beta1 *= 9.9792015476736E+291;
                    *alpha1 *= 9.9792015476736E+291;
                } while (!(fabs(beta1) >= 1.0020841800044864E-292));
                beta1 = rt_hypotd_snf(*alpha1, blas::xnrm2(n - 1, x));
                if (*alpha1 >= 0.0) {
                    beta1 = -beta1;
                }
                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);
                for (k = 2; k <= n; k++) {
                    x[k - 1] *= xnorm;
                }
                for (k = 0; k <= knt; k++) {
                    beta1 *= 1.0020841800044864E-292;
                }
                *alpha1 = beta1;
            } else {
                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);
                for (int k = 2; k <= n; k++) {
                    x[k - 1] *= xnorm;
                }
                *alpha1 = beta1;
            }
        }
    }
    return tau;
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzlarfg.cpp
//
// [EOF]
//
