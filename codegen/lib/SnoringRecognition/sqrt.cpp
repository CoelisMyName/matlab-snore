#include "sqrt.h"
#include "SnoringRecognition_rtwutil.h"
#include "rt_nonfinite.h"
#include "mylock.h"
#include "rt_nonfinite.h"
#include <math.h>

namespace coder {
void b_sqrt(creal_T *x)
{
    double absxi;
    double xi;
    double xr;
    xr = x->re;
    xi = x->im;
    if (xi == 0.0) {
        if (xr < 0.0) {
            absxi = 0.0;
            xr = sqrt(-xr);
        } else {
            absxi = sqrt(xr);
            xr = 0.0;
        }
    } else if (xr == 0.0) {
        if (xi < 0.0) {
            absxi = sqrt(-xi / 2.0);
            xr = -absxi;
        } else {
            absxi = sqrt(xi / 2.0);
            xr = absxi;
        }
    } else if (rtIsNaN(xr)) {
        absxi = xr;
    } else if (rtIsNaN(xi)) {
        absxi = xi;
        xr = xi;
    } else if (rtIsInf(xi)) {
        absxi = fabs(xi);
        xr = xi;
    } else if (rtIsInf(xr)) {
        if (xr < 0.0) {
            absxi = 0.0;
            xr = xi * -xr;
        } else {
            absxi = xr;
            xr = 0.0;
        }
    } else {
        double absxr;
        absxr = fabs(xr);
        absxi = fabs(xi);
        if ((absxr > 4.4942328371557893E+307) ||
            (absxi > 4.4942328371557893E+307)) {
            absxr *= 0.5;
            absxi = rt_hypotd_snf(absxr, absxi * 0.5);
            if (absxi > absxr) {
                absxi = sqrt(absxi) * sqrt(absxr / absxi + 1.0);
            } else {
                absxi = sqrt(absxi) * 1.4142135623730951;
            }
        } else {
            absxi = sqrt((rt_hypotd_snf(absxr, absxi) + absxr) * 0.5);
        }
        if (xr > 0.0) {
            xr = 0.5 * (xi / absxi);
        } else {
            if (xi < 0.0) {
                xr = -absxi;
            } else {
                xr = absxi;
            }
            absxi = 0.5 * (xi / xr);
        }
    }
    x->re = absxi;
    x->im = xr;
}

} // namespace coder
