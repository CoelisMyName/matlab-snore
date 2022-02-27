//
// File: levinson.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "levinson.h"
#include "classifier_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <math.h>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<creal_T, 1U> &R
//                creal_T A_data[]
//                int A_size[2]
//                double E_data[]
//                int E_size[2]
// Return Type  : void
//
namespace coder {
void levinson(const ::coder::array<creal_T, 1U> &R, creal_T A_data[],
              int A_size[2], double E_data[], int E_size[2])
{
    creal_T temp_A_data[12];
    creal_T temp_a_data[12];
    creal_T temp_auf_data[12];
    int N;
    N = 12;
    if ((12 == R.size(0)) || (12 > R.size(0))) {
        N = R.size(0) - 1;
    }
    if (N == 0) {
        E_size[0] = 1;
        E_size[1] = 1;
        E_data[0] = R[0].re;
        A_size[0] = 1;
        A_size[1] = 1;
        A_data[0].re = 1.0;
        A_data[0].im = 0.0;
    } else if (R.size(0) == 1) {
        A_size[0] = 1;
        A_size[1] = 1;
        A_data[0].re = 1.0;
        A_data[0].im = 0.0;
        E_size[0] = 1;
        E_size[1] = 1;
        E_data[0] = R[0].re;
    } else {
        double temp_J_im;
        double temp_J_re;
        int i;
        int temp_a_re_tmp;
        if (0 <= N - 1) {
            memset(&temp_a_data[0], 0, N * sizeof(creal_T));
            memset(&temp_A_data[0], 0, N * sizeof(creal_T));
            memset(&temp_auf_data[0], 0, N * sizeof(creal_T));
        }
        i = (2 <= N + 1);
        temp_a_data[0].re = -R[0].re;
        temp_a_data[0].im = -R[0].im;
        temp_J_re = R[0].re;
        temp_J_im = 0.0;
        for (int l = 0; l < N; l++) {
            double ar;
            double im;
            double re;
            double s;
            double temp_kprod_im;
            double temp_kprod_re;
            int j;
            temp_kprod_re = 0.0;
            temp_kprod_im = 0.0;
            for (j = 0; j < l; j++) {
                temp_auf_data[j] = temp_a_data[j];
                temp_a_re_tmp = ((i + l) - j) - 1;
                temp_kprod_re += temp_a_data[j].re * R[temp_a_re_tmp].re -
                                 temp_a_data[j].im * R[temp_a_re_tmp].im;
                temp_kprod_im += temp_a_data[j].re * R[temp_a_re_tmp].im +
                                 temp_a_data[j].im * R[temp_a_re_tmp].re;
            }
            temp_a_re_tmp = i + l;
            ar = -(R[temp_a_re_tmp].re + temp_kprod_re);
            im = -(R[temp_a_re_tmp].im + temp_kprod_im);
            if (temp_J_im == 0.0) {
                if (im == 0.0) {
                    re = ar / temp_J_re;
                    im = 0.0;
                } else if (ar == 0.0) {
                    re = 0.0;
                    im /= temp_J_re;
                } else {
                    re = ar / temp_J_re;
                    im /= temp_J_re;
                }
            } else if (temp_J_re == 0.0) {
                if (ar == 0.0) {
                    re = im / temp_J_im;
                    im = 0.0;
                } else if (im == 0.0) {
                    re = 0.0;
                    im = -(ar / temp_J_im);
                } else {
                    re = im / temp_J_im;
                    im = -(ar / temp_J_im);
                }
            } else {
                temp_kprod_im = fabs(temp_J_re);
                temp_kprod_re = fabs(temp_J_im);
                if (temp_kprod_im > temp_kprod_re) {
                    s = temp_J_im / temp_J_re;
                    temp_kprod_re = temp_J_re + s * temp_J_im;
                    re = (ar + s * im) / temp_kprod_re;
                    im = (im - s * ar) / temp_kprod_re;
                } else if (temp_kprod_re == temp_kprod_im) {
                    if (temp_J_re > 0.0) {
                        temp_kprod_re = 0.5;
                    } else {
                        temp_kprod_re = -0.5;
                    }
                    if (temp_J_im > 0.0) {
                        s = 0.5;
                    } else {
                        s = -0.5;
                    }
                    re = (ar * temp_kprod_re + im * s) / temp_kprod_im;
                    im = (im * temp_kprod_re - ar * s) / temp_kprod_im;
                } else {
                    s = temp_J_re / temp_J_im;
                    temp_kprod_re = temp_J_im + s * temp_J_re;
                    re = (s * ar + im) / temp_kprod_re;
                    im = (s * im - ar) / temp_kprod_re;
                }
            }
            temp_kprod_re = re * re - im * -im;
            temp_kprod_im = re * -im + im * re;
            s = (1.0 - temp_kprod_re) * temp_J_re -
                (0.0 - temp_kprod_im) * temp_J_im;
            temp_J_im = (1.0 - temp_kprod_re) * temp_J_im +
                        (0.0 - temp_kprod_im) * temp_J_re;
            temp_J_re = s;
            for (j = 0; j < l; j++) {
                temp_a_re_tmp = (l - j) - 1;
                temp_kprod_re = temp_auf_data[temp_a_re_tmp].re;
                s = -temp_auf_data[temp_a_re_tmp].im;
                temp_a_data[j].re =
                    temp_auf_data[j].re + (re * temp_kprod_re - im * s);
                temp_a_data[j].im =
                    temp_auf_data[j].im + (re * s + im * temp_kprod_re);
            }
            temp_a_data[l].re = re;
            temp_a_data[l].im = im;
        }
        if (0 <= N - 1) {
            memcpy(&temp_A_data[0], &temp_a_data[0], N * sizeof(creal_T));
        }
        if (1 > N) {
            temp_a_re_tmp = 0;
        } else {
            temp_a_re_tmp = N;
        }
        A_size[0] = 1;
        A_size[1] = temp_a_re_tmp + 1;
        A_data[0].re = 1.0;
        A_data[0].im = 0.0;
        if (0 <= temp_a_re_tmp - 1) {
            memcpy(&A_data[1], &temp_A_data[0],
                   temp_a_re_tmp * sizeof(creal_T));
        }
        E_size[0] = 1;
        E_size[1] = 1;
        E_data[0] = temp_J_re;
    }
}

} // namespace coder

//
// File trailer for levinson.cpp
//
// [EOF]
//
