//
// File: fft.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <math.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
namespace coder {
void b_fft(const ::coder::array<double, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
    if (x.size(1) == 0) {
        y.set_size(2048, 0);
    } else {
        int i;
        int loop_ub;
        int nChan;
        nChan = x.size(1);
        y.set_size(2048, x.size(1));
        loop_ub = 2048 * x.size(1);
        for (i = 0; i < loop_ub; i++) {
            y[i].re = 0.0;
            y[i].im = 0.0;
        }
        for (loop_ub = 0; loop_ub < nChan; loop_ub++) {
            for (i = 0; i < 2048; i++) {
                y[i + 2048 * loop_ub].re = 0.0;
                y[i + 2048 * loop_ub].im = 0.0;
            }
            internal::FFTImplementationCallback::c_doHalfLengthRadix2(
                x, loop_ub * 551, *(creal_T(*)[2048]) & y[2048 * loop_ub]);
        }
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
void c_fft(const ::coder::array<double, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
    if (x.size(1) == 0) {
        y.set_size(2048, 0);
    } else {
        int i;
        int loop_ub;
        int nChan;
        nChan = x.size(1);
        y.set_size(2048, x.size(1));
        loop_ub = 2048 * x.size(1);
        for (i = 0; i < loop_ub; i++) {
            y[i].re = 0.0;
            y[i].im = 0.0;
        }
        for (loop_ub = 0; loop_ub < nChan; loop_ub++) {
            for (i = 0; i < 2048; i++) {
                y[i + 2048 * loop_ub].re = 0.0;
                y[i + 2048 * loop_ub].im = 0.0;
            }
            internal::FFTImplementationCallback::e_doHalfLengthRadix2(
                x, loop_ub * 600, *(creal_T(*)[2048]) & y[2048 * loop_ub]);
        }
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
void d_fft(const ::coder::array<double, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
    if (x.size(1) == 0) {
        y.set_size(4096, 0);
    } else {
        int i;
        int loop_ub;
        int nChan;
        nChan = x.size(1);
        y.set_size(4096, x.size(1));
        loop_ub = 4096 * x.size(1);
        for (i = 0; i < loop_ub; i++) {
            y[i].re = 0.0;
            y[i].im = 0.0;
        }
        for (loop_ub = 0; loop_ub < nChan; loop_ub++) {
            for (i = 0; i < 4096; i++) {
                y[i + 4096 * loop_ub].re = 0.0;
                y[i + 4096 * loop_ub].im = 0.0;
            }
            internal::FFTImplementationCallback::f_doHalfLengthRadix2(
                x, loop_ub * 1103, *(creal_T(*)[4096]) & y[4096 * loop_ub]);
        }
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
void e_fft(const ::coder::array<double, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
    if (x.size(1) == 0) {
        y.set_size(4096, 0);
    } else {
        int i;
        int loop_ub;
        int nChan;
        nChan = x.size(1);
        y.set_size(4096, x.size(1));
        loop_ub = 4096 * x.size(1);
        for (i = 0; i < loop_ub; i++) {
            y[i].re = 0.0;
            y[i].im = 0.0;
        }
        for (loop_ub = 0; loop_ub < nChan; loop_ub++) {
            for (i = 0; i < 4096; i++) {
                y[i + 4096 * loop_ub].re = 0.0;
                y[i + 4096 * loop_ub].im = 0.0;
            }
            internal::FFTImplementationCallback::h_doHalfLengthRadix2(
                x, loop_ub * 1200, *(creal_T(*)[4096]) & y[4096 * loop_ub]);
        }
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
void f_fft(const ::coder::array<double, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
    if (x.size(1) == 0) {
        y.set_size(8192, 0);
    } else {
        int i;
        int loop_ub;
        int nChan;
        nChan = x.size(1);
        y.set_size(8192, x.size(1));
        loop_ub = 8192 * x.size(1);
        for (i = 0; i < loop_ub; i++) {
            y[i].re = 0.0;
            y[i].im = 0.0;
        }
        for (loop_ub = 0; loop_ub < nChan; loop_ub++) {
            for (i = 0; i < 8192; i++) {
                y[i + 8192 * loop_ub].re = 0.0;
                y[i + 8192 * loop_ub].im = 0.0;
            }
            internal::FFTImplementationCallback::i_doHalfLengthRadix2(
                x, loop_ub * 2205, *(creal_T(*)[8192]) & y[8192 * loop_ub]);
        }
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
void fft(const ::coder::array<double, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
    if (x.size(1) == 0) {
        y.set_size(1024, 0);
    } else {
        int i;
        int loop_ub;
        int nChan;
        nChan = x.size(1);
        y.set_size(1024, x.size(1));
        loop_ub = 1024 * x.size(1);
        for (i = 0; i < loop_ub; i++) {
            y[i].re = 0.0;
            y[i].im = 0.0;
        }
        for (loop_ub = 0; loop_ub < nChan; loop_ub++) {
            for (i = 0; i < 1024; i++) {
                y[i + 1024 * loop_ub].re = 0.0;
                y[i + 1024 * loop_ub].im = 0.0;
            }
            internal::FFTImplementationCallback::doHalfLengthRadix2(
                x, loop_ub * 400, *(creal_T(*)[1024]) & y[1024 * loop_ub]);
        }
    }
}

//
// Arguments    : const ::coder::array<double, 1U> &x
//                double varargin_1
//                ::coder::array<creal_T, 1U> &y
// Return Type  : void
//
void fft(const ::coder::array<double, 1U> &x, double varargin_1,
         ::coder::array<creal_T, 1U> &y)
{
    array<double, 2U> costab;
    array<double, 2U> sintab;
    array<double, 2U> sintabinv;
    int N2blue;
    int nRows;
    if ((x.size(0) == 0) || (0 == static_cast<int>(varargin_1))) {
        N2blue = static_cast<int>(varargin_1);
        y.set_size(N2blue);
        for (nRows = 0; nRows < N2blue; nRows++) {
            y[nRows].re = 0.0;
            y[nRows].im = 0.0;
        }
    } else {
        boolean_T useRadix2;
        useRadix2 = ((static_cast<int>(varargin_1) > 0) &&
                     ((static_cast<int>(varargin_1) &
                       (static_cast<int>(varargin_1) - 1)) == 0));
        internal::FFTImplementationCallback::get_algo_sizes(
            static_cast<int>(varargin_1), useRadix2, &N2blue, &nRows);
        internal::FFTImplementationCallback::generate_twiddle_tables(
            nRows, useRadix2, costab, sintab, sintabinv);
        if (useRadix2) {
            internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
                x, static_cast<int>(varargin_1), costab, sintab, y);
        } else {
            internal::FFTImplementationCallback::dobluesteinfft(
                x, N2blue, static_cast<int>(varargin_1), costab, sintab,
                sintabinv, y);
        }
    }
}

//
// Arguments    : const ::coder::array<double, 1U> &x
//                ::coder::array<creal_T, 1U> &y
// Return Type  : void
//
void fft(const ::coder::array<double, 1U> &x, ::coder::array<creal_T, 1U> &y)
{
    array<double, 2U> costab;
    array<double, 2U> sintab;
    array<double, 2U> sintabinv;
    int N2blue;
    int nRows;
    if (x.size(0) == 0) {
        y.set_size(0);
    } else {
        boolean_T useRadix2;
        useRadix2 = ((x.size(0) & (x.size(0) - 1)) == 0);
        internal::FFTImplementationCallback::get_algo_sizes(
            x.size(0), useRadix2, &N2blue, &nRows);
        internal::FFTImplementationCallback::generate_twiddle_tables(
            nRows, useRadix2, costab, sintab, sintabinv);
        if (useRadix2) {
            internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
                x, x.size(0), costab, sintab, y);
        } else {
            internal::FFTImplementationCallback::dobluesteinfft(
                x, N2blue, x.size(0), costab, sintab, sintabinv, y);
        }
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
void g_fft(const ::coder::array<double, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
    if (x.size(1) == 0) {
        y.set_size(8192, 0);
    } else {
        int i;
        int loop_ub;
        int nChan;
        nChan = x.size(1);
        y.set_size(8192, x.size(1));
        loop_ub = 8192 * x.size(1);
        for (i = 0; i < loop_ub; i++) {
            y[i].re = 0.0;
            y[i].im = 0.0;
        }
        for (loop_ub = 0; loop_ub < nChan; loop_ub++) {
            for (i = 0; i < 8192; i++) {
                y[i + 8192 * loop_ub].re = 0.0;
                y[i + 8192 * loop_ub].im = 0.0;
            }
            internal::FFTImplementationCallback::k_doHalfLengthRadix2(
                x, loop_ub * 2400, *(creal_T(*)[8192]) & y[8192 * loop_ub]);
        }
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
void h_fft(const ::coder::array<double, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
    array<creal_T, 1U> b_fv;
    array<creal_T, 1U> fv;
    array<creal_T, 1U> r;
    array<creal_T, 1U> wwc;
    array<double, 2U> costab;
    array<double, 2U> sintab;
    array<double, 2U> sintabinv;
    int ihi;
    int minNrowsNx;
    int nfft;
    nfft = x.size(0);
    if ((x.size(0) == 0) || (x.size(1) == 0)) {
        y.set_size(x.size(0), x.size(1));
        minNrowsNx = x.size(0) * x.size(1);
        for (int nRowsD2 = 0; nRowsD2 < minNrowsNx; nRowsD2++) {
            y[nRowsD2].re = 0.0;
            y[nRowsD2].im = 0.0;
        }
    } else {
        boolean_T useRadix2;
        useRadix2 = ((x.size(0) & (x.size(0) - 1)) == 0);
        internal::FFTImplementationCallback::get_algo_sizes(
            x.size(0), useRadix2, &ihi, &minNrowsNx);
        internal::FFTImplementationCallback::generate_twiddle_tables(
            minNrowsNx, useRadix2, costab, sintab, sintabinv);
        if (useRadix2) {
            int nChan;
            int sz_idx_0;
            nChan = x.size(1);
            y.set_size(x.size(0), x.size(1));
            sz_idx_0 = x.size(0);
            useRadix2 = (x.size(0) != 1);
            for (int chan = 0; chan < nChan; chan++) {
                int nRowsD2;
                int xoffInit;
                xoffInit = chan * x.size(0);
                r.set_size(sz_idx_0);
                if (nfft > x.size(0)) {
                    r.set_size(sz_idx_0);
                    for (nRowsD2 = 0; nRowsD2 < sz_idx_0; nRowsD2++) {
                        r[nRowsD2].re = 0.0;
                        r[nRowsD2].im = 0.0;
                    }
                }
                if (useRadix2) {
                    internal::FFTImplementationCallback::doHalfLengthRadix2(
                        x, xoffInit, r, nfft, costab, sintab);
                } else {
                    double nt_im;
                    double nt_re;
                    double twid_im;
                    double twid_re;
                    int i;
                    int ju;
                    int k;
                    int nInt2;
                    int nInt2m1;
                    int rt;
                    rt = x.size(0);
                    if (rt >= nfft) {
                        rt = nfft;
                    }
                    nInt2 = nfft - 2;
                    nRowsD2 = nfft / 2;
                    k = nRowsD2 / 2;
                    nInt2m1 = 0;
                    ju = 0;
                    for (i = 0; i <= rt - 2; i++) {
                        boolean_T tst;
                        r[nInt2m1].re = x[xoffInit + i];
                        r[nInt2m1].im = 0.0;
                        nInt2m1 = nfft;
                        tst = true;
                        while (tst) {
                            nInt2m1 >>= 1;
                            ju ^= nInt2m1;
                            tst = ((ju & nInt2m1) == 0);
                        }
                        nInt2m1 = ju;
                    }
                    r[nInt2m1].re = x[(xoffInit + rt) - 1];
                    r[nInt2m1].im = 0.0;
                    if (nfft > 1) {
                        for (i = 0; i <= nInt2; i += 2) {
                            nt_re = r[i + 1].re;
                            nt_im = r[i + 1].im;
                            twid_im = r[i].re;
                            twid_re = r[i].im;
                            r[i + 1].re = r[i].re - r[i + 1].re;
                            r[i + 1].im = r[i].im - r[i + 1].im;
                            twid_im += nt_re;
                            twid_re += nt_im;
                            r[i].re = twid_im;
                            r[i].im = twid_re;
                        }
                    }
                    nInt2m1 = 2;
                    rt = 4;
                    nInt2 = ((k - 1) << 2) + 1;
                    while (k > 0) {
                        int nt_re_tmp;
                        for (i = 0; i < nInt2; i += rt) {
                            nt_re_tmp = i + nInt2m1;
                            nt_re = r[nt_re_tmp].re;
                            nt_im = r[nt_re_tmp].im;
                            r[nt_re_tmp].re = r[i].re - nt_re;
                            r[nt_re_tmp].im = r[i].im - nt_im;
                            r[i].re = r[i].re + nt_re;
                            r[i].im = r[i].im + nt_im;
                        }
                        minNrowsNx = 1;
                        for (ju = k; ju < nRowsD2; ju += k) {
                            twid_re = costab[ju];
                            twid_im = sintab[ju];
                            i = minNrowsNx;
                            ihi = minNrowsNx + nInt2;
                            while (i < ihi) {
                                nt_re_tmp = i + nInt2m1;
                                nt_re = twid_re * r[nt_re_tmp].re -
                                        twid_im * r[nt_re_tmp].im;
                                nt_im = twid_re * r[nt_re_tmp].im +
                                        twid_im * r[nt_re_tmp].re;
                                r[nt_re_tmp].re = r[i].re - nt_re;
                                r[nt_re_tmp].im = r[i].im - nt_im;
                                r[i].re = r[i].re + nt_re;
                                r[i].im = r[i].im + nt_im;
                                i += rt;
                            }
                            minNrowsNx++;
                        }
                        k /= 2;
                        nInt2m1 = rt;
                        rt += rt;
                        nInt2 -= nInt2m1;
                    }
                }
                minNrowsNx = r.size(0);
                for (nRowsD2 = 0; nRowsD2 < minNrowsNx; nRowsD2++) {
                    y[nRowsD2 + y.size(0) * chan] = r[nRowsD2];
                }
            }
        } else {
            int k;
            int nChan;
            int nRowsD2;
            int sz_idx_0;
            nfft = x.size(0);
            nChan = x.size(1);
            if ((x.size(0) != 1) && ((x.size(0) & 1) == 0)) {
                int nInt2;
                int nInt2m1;
                int rt;
                minNrowsNx = x.size(0) / 2;
                nInt2m1 = (minNrowsNx + minNrowsNx) - 1;
                wwc.set_size(nInt2m1);
                rt = 0;
                wwc[minNrowsNx - 1].re = 1.0;
                wwc[minNrowsNx - 1].im = 0.0;
                nInt2 = minNrowsNx << 1;
                for (k = 0; k <= minNrowsNx - 2; k++) {
                    double nt_im;
                    double nt_re;
                    int ju;
                    ju = ((k + 1) << 1) - 1;
                    if (nInt2 - rt <= ju) {
                        rt += ju - nInt2;
                    } else {
                        rt += ju;
                    }
                    nt_im = -3.1415926535897931 * static_cast<double>(rt) /
                            static_cast<double>(minNrowsNx);
                    if (nt_im == 0.0) {
                        nt_re = 1.0;
                        nt_im = 0.0;
                    } else {
                        nt_re = cos(nt_im);
                        nt_im = sin(nt_im);
                    }
                    nRowsD2 = (minNrowsNx - k) - 2;
                    wwc[nRowsD2].re = nt_re;
                    wwc[nRowsD2].im = -nt_im;
                }
                nRowsD2 = nInt2m1 - 1;
                for (k = nRowsD2; k >= minNrowsNx; k--) {
                    wwc[k] = wwc[(nInt2m1 - k) - 1];
                }
            } else {
                int nInt2;
                int nInt2m1;
                int rt;
                nInt2m1 = (x.size(0) + x.size(0)) - 1;
                wwc.set_size(nInt2m1);
                rt = 0;
                wwc[x.size(0) - 1].re = 1.0;
                wwc[x.size(0) - 1].im = 0.0;
                nInt2 = x.size(0) << 1;
                nRowsD2 = x.size(0);
                for (k = 0; k <= nRowsD2 - 2; k++) {
                    double nt_im;
                    double nt_re;
                    int ju;
                    ju = ((k + 1) << 1) - 1;
                    if (nInt2 - rt <= ju) {
                        rt += ju - nInt2;
                    } else {
                        rt += ju;
                    }
                    nt_im = -3.1415926535897931 * static_cast<double>(rt) /
                            static_cast<double>(nfft);
                    if (nt_im == 0.0) {
                        nt_re = 1.0;
                        nt_im = 0.0;
                    } else {
                        nt_re = cos(nt_im);
                        nt_im = sin(nt_im);
                    }
                    wwc[(x.size(0) - k) - 2].re = nt_re;
                    wwc[(x.size(0) - k) - 2].im = -nt_im;
                }
                nRowsD2 = nInt2m1 - 1;
                for (k = nRowsD2; k >= nfft; k--) {
                    wwc[k] = wwc[(nInt2m1 - k) - 1];
                }
            }
            y.set_size(x.size(0), x.size(1));
            sz_idx_0 = x.size(0);
            if ((ihi != 1) && ((x.size(0) & 1) == 0)) {
                useRadix2 = true;
            } else {
                useRadix2 = false;
            }
            for (int chan = 0; chan < nChan; chan++) {
                int xoffInit;
                xoffInit = chan * x.size(0);
                r.set_size(sz_idx_0);
                if (nfft > x.size(0)) {
                    r.set_size(sz_idx_0);
                    for (nRowsD2 = 0; nRowsD2 < sz_idx_0; nRowsD2++) {
                        r[nRowsD2].re = 0.0;
                        r[nRowsD2].im = 0.0;
                    }
                }
                if (useRadix2) {
                    internal::FFTImplementationCallback::doHalfLengthBluestein(
                        x, xoffInit, r, x.size(0), nfft, ihi, wwc, costab,
                        sintab, costab, sintabinv);
                } else {
                    double twid_re;
                    minNrowsNx = x.size(0);
                    if (nfft < minNrowsNx) {
                        minNrowsNx = nfft;
                    }
                    for (k = 0; k < minNrowsNx; k++) {
                        int nt_re_tmp;
                        nt_re_tmp = (nfft + k) - 1;
                        nRowsD2 = xoffInit + k;
                        r[k].re = wwc[nt_re_tmp].re * x[nRowsD2];
                        r[k].im = wwc[nt_re_tmp].im * -x[nRowsD2];
                    }
                    nRowsD2 = minNrowsNx + 1;
                    for (k = nRowsD2; k <= nfft; k++) {
                        r[k - 1].re = 0.0;
                        r[k - 1].im = 0.0;
                    }
                    internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
                        r, ihi, costab, sintab, fv);
                    internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
                        wwc, ihi, costab, sintab, b_fv);
                    b_fv.set_size(fv.size(0));
                    minNrowsNx = fv.size(0);
                    for (nRowsD2 = 0; nRowsD2 < minNrowsNx; nRowsD2++) {
                        twid_re = fv[nRowsD2].re * b_fv[nRowsD2].im +
                                  fv[nRowsD2].im * b_fv[nRowsD2].re;
                        b_fv[nRowsD2].re = fv[nRowsD2].re * b_fv[nRowsD2].re -
                                           fv[nRowsD2].im * b_fv[nRowsD2].im;
                        b_fv[nRowsD2].im = twid_re;
                    }
                    internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
                        b_fv, ihi, costab, sintabinv, fv);
                    if (fv.size(0) > 1) {
                        twid_re = 1.0 / static_cast<double>(fv.size(0));
                        minNrowsNx = fv.size(0);
                        for (nRowsD2 = 0; nRowsD2 < minNrowsNx; nRowsD2++) {
                            fv[nRowsD2].re = twid_re * fv[nRowsD2].re;
                            fv[nRowsD2].im = twid_re * fv[nRowsD2].im;
                        }
                    }
                    nRowsD2 = wwc.size(0);
                    for (k = nfft; k <= nRowsD2; k++) {
                        minNrowsNx = k - nfft;
                        r[minNrowsNx].re = wwc[k - 1].re * fv[k - 1].re +
                                           wwc[k - 1].im * fv[k - 1].im;
                        r[minNrowsNx].im = wwc[k - 1].re * fv[k - 1].im -
                                           wwc[k - 1].im * fv[k - 1].re;
                    }
                }
                minNrowsNx = r.size(0);
                for (nRowsD2 = 0; nRowsD2 < minNrowsNx; nRowsD2++) {
                    y[nRowsD2 + y.size(0) * chan] = r[nRowsD2];
                }
            }
        }
    }
}

} // namespace coder

//
// File trailer for fft.cpp
//
// [EOF]
//
