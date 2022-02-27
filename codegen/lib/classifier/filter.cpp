//
// File: filter.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "filter.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
void b_filter(const ::coder::array<double, 1U> &x,
              ::coder::array<double, 1U> &y)
{
    int i;
    int nx;
    int nx_m_nb;
    nx = x.size(0);
    y.set_size(x.size(0));
    nx_m_nb = x.size(0);
    for (i = 0; i < nx_m_nb; i++) {
        y[i] = 0.0;
    }
    if (x.size(0) >= 4) {
        for (int k = 0; k < 2; k++) {
            nx_m_nb = k + 1;
            for (int j = nx_m_nb; j <= nx; j++) {
                y[j - 1] = y[j - 1] + (-1.99 * static_cast<double>(k) + 1.0) *
                                          x[(j - k) - 1];
            }
        }
    } else {
        int k;
        int naxpy;
        if (x.size(0) > 2) {
            nx_m_nb = 0;
        } else {
            nx_m_nb = -1;
        }
        for (k = 0; k <= nx_m_nb; k++) {
            y[0] = y[0] + x[0];
            y[1] = y[1] + x[0] * -0.99;
        }
        naxpy = x.size(0) - nx_m_nb;
        i = nx_m_nb + 2;
        for (k = i; k <= nx; k++) {
            for (int j = 0; j <= naxpy - 2; j++) {
                nx_m_nb = (k + j) - 1;
                y[nx_m_nb] = y[nx_m_nb] +
                             x[k - 1] * (-1.99 * static_cast<double>(j) + 1.0);
            }
            naxpy--;
        }
    }
}

//
// Arguments    : const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
void filter(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y)
{
    int i;
    int nx;
    int nx_m_nb;
    nx = x.size(0);
    y.set_size(x.size(0));
    nx_m_nb = x.size(0);
    for (i = 0; i < nx_m_nb; i++) {
        y[i] = 0.0;
    }
    if (x.size(0) >= 4) {
        for (int k = 0; k < 2; k++) {
            nx_m_nb = k + 1;
            for (int j = nx_m_nb; j <= nx; j++) {
                y[j - 1] = y[j - 1] + (-1.9375 * static_cast<double>(k) + 1.0) *
                                          x[(j - k) - 1];
            }
        }
    } else {
        int k;
        int naxpy;
        if (x.size(0) > 2) {
            nx_m_nb = 0;
        } else {
            nx_m_nb = -1;
        }
        for (k = 0; k <= nx_m_nb; k++) {
            y[0] = y[0] + x[0];
            y[1] = y[1] + x[0] * -0.9375;
        }
        naxpy = x.size(0) - nx_m_nb;
        i = nx_m_nb + 2;
        for (k = i; k <= nx; k++) {
            for (int j = 0; j <= naxpy - 2; j++) {
                nx_m_nb = (k + j) - 1;
                y[nx_m_nb] =
                    y[nx_m_nb] +
                    x[k - 1] * (-1.9375 * static_cast<double>(j) + 1.0);
            }
            naxpy--;
        }
    }
}

} // namespace coder

//
// File trailer for filter.cpp
//
// [EOF]
//
