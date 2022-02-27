//
// File: NCF.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "NCF.h"
#include "FFTImplementationCallback.h"
#include "classifier_rtwutil.h"
#include "fft.h"
#include "getCandidates.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <math.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &y
//                ::coder::array<double, 1U> &f0
// Return Type  : void
//
namespace coder {
namespace audio {
namespace internal {
namespace pitch {
void NCF(const ::coder::array<double, 2U> &y, ::coder::array<double, 1U> &f0)
{
    array<creal_T, 2U> x;
    array<double, 2U> Rt;
    array<double, 2U> b_c1;
    array<double, 2U> b_x;
    array<double, 2U> b_y;
    array<double, 2U> c1;
    array<double, 2U> c_y;
    array<double, 2U> lag;
    array<double, 1U> peak;
    double edge[2];
    int i;
    int i1;
    int ibmat;
    int itilerow;
    int jcol;
    int lag_tmp;
    int nx;
    short sizes_idx_0;
    unsigned char input_sizes_idx_0;
    boolean_T empty_non_axis_sizes;
    edge[0] = 20.0;
    edge[1] = 160.0;
    fft(y, x);
    nx = x.size(1) << 10;
    c1.set_size(1024, x.size(1));
    for (ibmat = 0; ibmat < nx; ibmat++) {
        c1[ibmat] = rt_hypotd_snf(x[ibmat].re, x[ibmat].im);
    }
    b_y.set_size(1024, c1.size(1));
    nx = c1.size(1) << 10;
    for (ibmat = 0; ibmat < nx; ibmat++) {
        b_y[ibmat] = c1[ibmat] * c1[ibmat];
    }
    if (b_y.size(1) == 0) {
        x.set_size(1024, 0);
    } else {
        nx = b_y.size(1);
        x.set_size(1024, b_y.size(1));
        for (ibmat = 0; ibmat < nx; ibmat++) {
            ::coder::internal::FFTImplementationCallback::b_doHalfLengthRadix2(
                b_y, ibmat << 10, *(creal_T(*)[1024]) & x[1024 * ibmat]);
        }
        itilerow = 1024 * x.size(1);
        x.set_size(1024, x.size(1));
        for (i = 0; i < itilerow; i++) {
            x[i].re = 0.0009765625 * x[i].re;
            x[i].im = 0.0009765625 * x[i].im;
        }
    }
    c1.set_size(1024, x.size(1));
    itilerow = 1024 * x.size(1);
    for (i = 0; i < itilerow; i++) {
        c1[i] = x[i].re / 32.0;
    }
    c_y.set_size(1, 160);
    for (i = 0; i < 160; i++) {
        c_y[i] = static_cast<double>(i) + 1.0;
    }
    itilerow = c1.size(1);
    lag.set_size(160, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 160; i1++) {
            lag[i1 + lag.size(0) * i] =
                c1[(static_cast<int>(c_y[i1]) + 1024 * i) + 863];
        }
    }
    if (c1.size(1) != 0) {
        nx = c1.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        input_sizes_idx_0 = 160U;
    } else {
        input_sizes_idx_0 = 0U;
    }
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        sizes_idx_0 = 161;
    } else {
        sizes_idx_0 = 0;
    }
    ibmat = input_sizes_idx_0;
    itilerow = c1.size(1);
    b_c1.set_size(161, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 161; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = c1[i1 + 1024 * i];
        }
    }
    jcol = sizes_idx_0;
    Rt.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < ibmat; i1++) {
            Rt[i1 + Rt.size(0) * i] = lag[i1 + input_sizes_idx_0 * i];
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            Rt[(i1 + input_sizes_idx_0) + Rt.size(0) * i] =
                b_c1[i1 + sizes_idx_0 * i];
        }
    }
    if (181 > Rt.size(0)) {
        i = -1;
        i1 = -1;
    } else {
        i = 179;
        i1 = Rt.size(0) - 1;
    }
    itilerow = Rt.size(1);
    b_x.set_size(1, Rt.size(1));
    for (nx = 0; nx < itilerow; nx++) {
        b_x[nx] = Rt[Rt.size(0) * nx + 160];
    }
    nx = Rt.size(1) - 1;
    for (ibmat = 0; ibmat <= nx; ibmat++) {
        b_x[ibmat] = sqrt(b_x[ibmat]);
    }
    lag_tmp = i1 - i;
    lag.set_size(lag_tmp, b_x.size(1));
    nx = b_x.size(1);
    for (jcol = 0; jcol < nx; jcol++) {
        ibmat = jcol * lag_tmp;
        for (itilerow = 0; itilerow < lag_tmp; itilerow++) {
            lag[ibmat + itilerow] = b_x[jcol];
        }
    }
    itilerow = Rt.size(1);
    lag.set_size(lag_tmp, Rt.size(1));
    for (i1 = 0; i1 < itilerow; i1++) {
        for (nx = 0; nx < lag_tmp; nx++) {
            lag[nx + lag.size(0) * i1] = Rt[((i + nx) + Rt.size(0) * i1) + 1] /
                                         lag[nx + lag.size(0) * i1];
        }
    }
    if (lag.size(1) != 0) {
        nx = lag.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (lag.size(1) != 0)) {
        input_sizes_idx_0 = 19U;
    } else {
        input_sizes_idx_0 = 0U;
    }
    if (empty_non_axis_sizes || ((lag.size(0) != 0) && (lag.size(1) != 0))) {
        sizes_idx_0 = static_cast<short>(lag.size(0));
    } else {
        sizes_idx_0 = 0;
    }
    jcol = sizes_idx_0;
    b_c1.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        itilerow = input_sizes_idx_0;
        for (i1 = 0; i1 < itilerow; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = 0.0;
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            b_c1[(i1 + input_sizes_idx_0) + b_c1.size(0) * i] =
                lag[i1 + sizes_idx_0 * i];
        }
    }
    getCandidates(b_c1, edge, peak, f0);
    itilerow = f0.size(0);
    for (i = 0; i < itilerow; i++) {
        f0[i] = 8000.0 / f0[i];
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &y
//                ::coder::array<double, 1U> &f0
// Return Type  : void
//
void b_NCF(const ::coder::array<double, 2U> &y, ::coder::array<double, 1U> &f0)
{
    array<creal_T, 2U> x;
    array<double, 2U> Rt;
    array<double, 2U> b_c1;
    array<double, 2U> b_x;
    array<double, 2U> b_y;
    array<double, 2U> c1;
    array<double, 2U> c_y;
    array<double, 2U> lag;
    array<double, 1U> locs;
    array<double, 1U> peak;
    double edge[2];
    int i;
    int i1;
    int ibmat;
    int itilerow;
    int jcol;
    int lag_tmp;
    int nx;
    short sizes_idx_0;
    unsigned char input_sizes_idx_0;
    boolean_T empty_non_axis_sizes;
    edge[0] = 28.0;
    edge[1] = 221.0;
    b_fft(y, x);
    nx = x.size(1) << 11;
    c1.set_size(2048, x.size(1));
    for (ibmat = 0; ibmat < nx; ibmat++) {
        c1[ibmat] = rt_hypotd_snf(x[ibmat].re, x[ibmat].im);
    }
    b_y.set_size(2048, c1.size(1));
    nx = c1.size(1) << 11;
    for (ibmat = 0; ibmat < nx; ibmat++) {
        b_y[ibmat] = c1[ibmat] * c1[ibmat];
    }
    if (b_y.size(1) == 0) {
        x.set_size(2048, 0);
    } else {
        nx = b_y.size(1);
        x.set_size(2048, b_y.size(1));
        for (ibmat = 0; ibmat < nx; ibmat++) {
            ::coder::internal::FFTImplementationCallback::d_doHalfLengthRadix2(
                b_y, ibmat << 11, *(creal_T(*)[2048]) & x[2048 * ibmat]);
        }
        itilerow = 2048 * x.size(1);
        x.set_size(2048, x.size(1));
        for (i = 0; i < itilerow; i++) {
            x[i].re = 0.00048828125 * x[i].re;
            x[i].im = 0.00048828125 * x[i].im;
        }
    }
    c1.set_size(2048, x.size(1));
    itilerow = 2048 * x.size(1);
    for (i = 0; i < itilerow; i++) {
        c1[i] = x[i].re / 45.254833995939045;
    }
    c_y.set_size(1, 221);
    for (i = 0; i < 221; i++) {
        c_y[i] = static_cast<double>(i) + 1.0;
    }
    itilerow = c1.size(1);
    lag.set_size(221, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 221; i1++) {
            lag[i1 + lag.size(0) * i] =
                c1[(static_cast<int>(c_y[i1] + 1827.0) + 2048 * i) - 1];
        }
    }
    if (c1.size(1) != 0) {
        nx = c1.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        input_sizes_idx_0 = 221U;
    } else {
        input_sizes_idx_0 = 0U;
    }
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        sizes_idx_0 = 222;
    } else {
        sizes_idx_0 = 0;
    }
    ibmat = input_sizes_idx_0;
    itilerow = c1.size(1);
    b_c1.set_size(222, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 222; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = c1[i1 + 2048 * i];
        }
    }
    jcol = sizes_idx_0;
    Rt.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < ibmat; i1++) {
            Rt[i1 + Rt.size(0) * i] = lag[i1 + input_sizes_idx_0 * i];
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            Rt[(i1 + input_sizes_idx_0) + Rt.size(0) * i] =
                b_c1[i1 + sizes_idx_0 * i];
        }
    }
    if (250 > Rt.size(0)) {
        i = -1;
        i1 = -1;
    } else {
        i = 248;
        i1 = Rt.size(0) - 1;
    }
    itilerow = Rt.size(1);
    b_x.set_size(1, Rt.size(1));
    for (nx = 0; nx < itilerow; nx++) {
        b_x[nx] = Rt[Rt.size(0) * nx + 221];
    }
    nx = Rt.size(1) - 1;
    for (ibmat = 0; ibmat <= nx; ibmat++) {
        b_x[ibmat] = sqrt(b_x[ibmat]);
    }
    lag_tmp = i1 - i;
    lag.set_size(lag_tmp, b_x.size(1));
    nx = b_x.size(1);
    for (jcol = 0; jcol < nx; jcol++) {
        ibmat = jcol * lag_tmp;
        for (itilerow = 0; itilerow < lag_tmp; itilerow++) {
            lag[ibmat + itilerow] = b_x[jcol];
        }
    }
    itilerow = Rt.size(1);
    lag.set_size(lag_tmp, Rt.size(1));
    for (i1 = 0; i1 < itilerow; i1++) {
        for (nx = 0; nx < lag_tmp; nx++) {
            lag[nx + lag.size(0) * i1] = Rt[((i + nx) + Rt.size(0) * i1) + 1] /
                                         lag[nx + lag.size(0) * i1];
        }
    }
    if (lag.size(1) != 0) {
        nx = lag.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (lag.size(1) != 0)) {
        input_sizes_idx_0 = 27U;
    } else {
        input_sizes_idx_0 = 0U;
    }
    if (empty_non_axis_sizes || ((lag.size(0) != 0) && (lag.size(1) != 0))) {
        sizes_idx_0 = static_cast<short>(lag.size(0));
    } else {
        sizes_idx_0 = 0;
    }
    jcol = sizes_idx_0;
    b_c1.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        itilerow = input_sizes_idx_0;
        for (i1 = 0; i1 < itilerow; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = 0.0;
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            b_c1[(i1 + input_sizes_idx_0) + b_c1.size(0) * i] =
                lag[i1 + sizes_idx_0 * i];
        }
    }
    getCandidates(b_c1, edge, peak, locs);
    f0.set_size(locs.size(0));
    itilerow = locs.size(0);
    for (i = 0; i < itilerow; i++) {
        f0[i] = 11025.0 / locs[i];
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &y
//                ::coder::array<double, 1U> &f0
// Return Type  : void
//
void c_NCF(const ::coder::array<double, 2U> &y, ::coder::array<double, 1U> &f0)
{
    array<creal_T, 2U> x;
    array<double, 2U> Rt;
    array<double, 2U> b_c1;
    array<double, 2U> b_x;
    array<double, 2U> b_y;
    array<double, 2U> c1;
    array<double, 2U> c_y;
    array<double, 2U> lag;
    array<double, 1U> locs;
    array<double, 1U> peak;
    double edge[2];
    int i;
    int i1;
    int ibmat;
    int itilerow;
    int jcol;
    int lag_tmp;
    int nx;
    short sizes_idx_0;
    unsigned char input_sizes_idx_0;
    boolean_T empty_non_axis_sizes;
    edge[0] = 30.0;
    edge[1] = 240.0;
    c_fft(y, x);
    nx = x.size(1) << 11;
    c1.set_size(2048, x.size(1));
    for (ibmat = 0; ibmat < nx; ibmat++) {
        c1[ibmat] = rt_hypotd_snf(x[ibmat].re, x[ibmat].im);
    }
    b_y.set_size(2048, c1.size(1));
    nx = c1.size(1) << 11;
    for (ibmat = 0; ibmat < nx; ibmat++) {
        b_y[ibmat] = c1[ibmat] * c1[ibmat];
    }
    if (b_y.size(1) == 0) {
        x.set_size(2048, 0);
    } else {
        nx = b_y.size(1);
        x.set_size(2048, b_y.size(1));
        for (ibmat = 0; ibmat < nx; ibmat++) {
            ::coder::internal::FFTImplementationCallback::d_doHalfLengthRadix2(
                b_y, ibmat << 11, *(creal_T(*)[2048]) & x[2048 * ibmat]);
        }
        itilerow = 2048 * x.size(1);
        x.set_size(2048, x.size(1));
        for (i = 0; i < itilerow; i++) {
            x[i].re = 0.00048828125 * x[i].re;
            x[i].im = 0.00048828125 * x[i].im;
        }
    }
    c1.set_size(2048, x.size(1));
    itilerow = 2048 * x.size(1);
    for (i = 0; i < itilerow; i++) {
        c1[i] = x[i].re / 45.254833995939045;
    }
    c_y.set_size(1, 240);
    for (i = 0; i < 240; i++) {
        c_y[i] = static_cast<double>(i) + 1.0;
    }
    itilerow = c1.size(1);
    lag.set_size(240, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 240; i1++) {
            lag[i1 + lag.size(0) * i] =
                c1[(static_cast<int>(c_y[i1]) + 2048 * i) + 1807];
        }
    }
    if (c1.size(1) != 0) {
        nx = c1.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        input_sizes_idx_0 = 240U;
    } else {
        input_sizes_idx_0 = 0U;
    }
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        sizes_idx_0 = 241;
    } else {
        sizes_idx_0 = 0;
    }
    ibmat = input_sizes_idx_0;
    itilerow = c1.size(1);
    b_c1.set_size(241, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 241; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = c1[i1 + 2048 * i];
        }
    }
    jcol = sizes_idx_0;
    Rt.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < ibmat; i1++) {
            Rt[i1 + Rt.size(0) * i] = lag[i1 + input_sizes_idx_0 * i];
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            Rt[(i1 + input_sizes_idx_0) + Rt.size(0) * i] =
                b_c1[i1 + sizes_idx_0 * i];
        }
    }
    if (271 > Rt.size(0)) {
        i = -1;
        i1 = -1;
    } else {
        i = 269;
        i1 = Rt.size(0) - 1;
    }
    itilerow = Rt.size(1);
    b_x.set_size(1, Rt.size(1));
    for (nx = 0; nx < itilerow; nx++) {
        b_x[nx] = Rt[Rt.size(0) * nx + 240];
    }
    nx = Rt.size(1) - 1;
    for (ibmat = 0; ibmat <= nx; ibmat++) {
        b_x[ibmat] = sqrt(b_x[ibmat]);
    }
    lag_tmp = i1 - i;
    lag.set_size(lag_tmp, b_x.size(1));
    nx = b_x.size(1);
    for (jcol = 0; jcol < nx; jcol++) {
        ibmat = jcol * lag_tmp;
        for (itilerow = 0; itilerow < lag_tmp; itilerow++) {
            lag[ibmat + itilerow] = b_x[jcol];
        }
    }
    itilerow = Rt.size(1);
    lag.set_size(lag_tmp, Rt.size(1));
    for (i1 = 0; i1 < itilerow; i1++) {
        for (nx = 0; nx < lag_tmp; nx++) {
            lag[nx + lag.size(0) * i1] = Rt[((i + nx) + Rt.size(0) * i1) + 1] /
                                         lag[nx + lag.size(0) * i1];
        }
    }
    if (lag.size(1) != 0) {
        nx = lag.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (lag.size(1) != 0)) {
        input_sizes_idx_0 = 29U;
    } else {
        input_sizes_idx_0 = 0U;
    }
    if (empty_non_axis_sizes || ((lag.size(0) != 0) && (lag.size(1) != 0))) {
        sizes_idx_0 = static_cast<short>(lag.size(0));
    } else {
        sizes_idx_0 = 0;
    }
    jcol = sizes_idx_0;
    b_c1.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        itilerow = input_sizes_idx_0;
        for (i1 = 0; i1 < itilerow; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = 0.0;
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            b_c1[(i1 + input_sizes_idx_0) + b_c1.size(0) * i] =
                lag[i1 + sizes_idx_0 * i];
        }
    }
    getCandidates(b_c1, edge, peak, locs);
    f0.set_size(locs.size(0));
    itilerow = locs.size(0);
    for (i = 0; i < itilerow; i++) {
        f0[i] = 12000.0 / locs[i];
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &y
//                ::coder::array<double, 1U> &f0
// Return Type  : void
//
void d_NCF(const ::coder::array<double, 2U> &y, ::coder::array<double, 1U> &f0)
{
    array<creal_T, 2U> x;
    array<double, 2U> Rt;
    array<double, 2U> b_c1;
    array<double, 2U> b_x;
    array<double, 2U> b_y;
    array<double, 2U> c1;
    array<double, 2U> c_y;
    array<double, 2U> lag;
    array<double, 1U> locs;
    array<double, 1U> peak;
    double edge[2];
    int i;
    int i1;
    int ibmat;
    int itilerow;
    int jcol;
    int lag_tmp;
    int nx;
    short input_sizes_idx_0;
    short sizes_idx_0;
    boolean_T empty_non_axis_sizes;
    edge[0] = 55.0;
    edge[1] = 441.0;
    d_fft(y, x);
    nx = x.size(1) << 12;
    c1.set_size(4096, x.size(1));
    for (ibmat = 0; ibmat < nx; ibmat++) {
        c1[ibmat] = rt_hypotd_snf(x[ibmat].re, x[ibmat].im);
    }
    b_y.set_size(4096, c1.size(1));
    nx = c1.size(1) << 12;
    for (ibmat = 0; ibmat < nx; ibmat++) {
        b_y[ibmat] = c1[ibmat] * c1[ibmat];
    }
    if (b_y.size(1) == 0) {
        x.set_size(4096, 0);
    } else {
        nx = b_y.size(1);
        x.set_size(4096, b_y.size(1));
        for (ibmat = 0; ibmat < nx; ibmat++) {
            ::coder::internal::FFTImplementationCallback::g_doHalfLengthRadix2(
                b_y, ibmat << 12, *(creal_T(*)[4096]) & x[4096 * ibmat]);
        }
        itilerow = 4096 * x.size(1);
        x.set_size(4096, x.size(1));
        for (i = 0; i < itilerow; i++) {
            x[i].re = 0.000244140625 * x[i].re;
            x[i].im = 0.000244140625 * x[i].im;
        }
    }
    c1.set_size(4096, x.size(1));
    itilerow = 4096 * x.size(1);
    for (i = 0; i < itilerow; i++) {
        c1[i] = x[i].re / 64.0;
    }
    c_y.set_size(1, 441);
    for (i = 0; i < 441; i++) {
        c_y[i] = static_cast<double>(i) + 1.0;
    }
    itilerow = c1.size(1);
    lag.set_size(441, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 441; i1++) {
            lag[i1 + lag.size(0) * i] =
                c1[(static_cast<int>(c_y[i1]) + 4096 * i) + 3654];
        }
    }
    if (c1.size(1) != 0) {
        nx = c1.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        input_sizes_idx_0 = 441;
    } else {
        input_sizes_idx_0 = 0;
    }
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        sizes_idx_0 = 442;
    } else {
        sizes_idx_0 = 0;
    }
    ibmat = input_sizes_idx_0;
    itilerow = c1.size(1);
    b_c1.set_size(442, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 442; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = c1[i1 + 4096 * i];
        }
    }
    jcol = sizes_idx_0;
    Rt.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < ibmat; i1++) {
            Rt[i1 + Rt.size(0) * i] = lag[i1 + input_sizes_idx_0 * i];
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            Rt[(i1 + input_sizes_idx_0) + Rt.size(0) * i] =
                b_c1[i1 + sizes_idx_0 * i];
        }
    }
    if (497 > Rt.size(0)) {
        i = -1;
        i1 = -1;
    } else {
        i = 495;
        i1 = Rt.size(0) - 1;
    }
    itilerow = Rt.size(1);
    b_x.set_size(1, Rt.size(1));
    for (nx = 0; nx < itilerow; nx++) {
        b_x[nx] = Rt[Rt.size(0) * nx + 441];
    }
    nx = Rt.size(1) - 1;
    for (ibmat = 0; ibmat <= nx; ibmat++) {
        b_x[ibmat] = sqrt(b_x[ibmat]);
    }
    lag_tmp = i1 - i;
    lag.set_size(lag_tmp, b_x.size(1));
    nx = b_x.size(1);
    for (jcol = 0; jcol < nx; jcol++) {
        ibmat = jcol * lag_tmp;
        for (itilerow = 0; itilerow < lag_tmp; itilerow++) {
            lag[ibmat + itilerow] = b_x[jcol];
        }
    }
    itilerow = Rt.size(1);
    lag.set_size(lag_tmp, Rt.size(1));
    for (i1 = 0; i1 < itilerow; i1++) {
        for (nx = 0; nx < lag_tmp; nx++) {
            lag[nx + lag.size(0) * i1] = Rt[((i + nx) + Rt.size(0) * i1) + 1] /
                                         lag[nx + lag.size(0) * i1];
        }
    }
    if (lag.size(1) != 0) {
        nx = lag.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (lag.size(1) != 0)) {
        input_sizes_idx_0 = 54;
    } else {
        input_sizes_idx_0 = 0;
    }
    if (empty_non_axis_sizes || ((lag.size(0) != 0) && (lag.size(1) != 0))) {
        sizes_idx_0 = static_cast<short>(lag.size(0));
    } else {
        sizes_idx_0 = 0;
    }
    jcol = sizes_idx_0;
    b_c1.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        itilerow = input_sizes_idx_0;
        for (i1 = 0; i1 < itilerow; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = 0.0;
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            b_c1[(i1 + input_sizes_idx_0) + b_c1.size(0) * i] =
                lag[i1 + sizes_idx_0 * i];
        }
    }
    getCandidates(b_c1, edge, peak, locs);
    f0.set_size(locs.size(0));
    itilerow = locs.size(0);
    for (i = 0; i < itilerow; i++) {
        f0[i] = 22050.0 / locs[i];
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &y
//                ::coder::array<double, 1U> &f0
// Return Type  : void
//
void e_NCF(const ::coder::array<double, 2U> &y, ::coder::array<double, 1U> &f0)
{
    array<creal_T, 2U> x;
    array<double, 2U> Rt;
    array<double, 2U> b_c1;
    array<double, 2U> b_x;
    array<double, 2U> b_y;
    array<double, 2U> c1;
    array<double, 2U> c_y;
    array<double, 2U> lag;
    array<double, 1U> locs;
    array<double, 1U> peak;
    double edge[2];
    int i;
    int i1;
    int ibmat;
    int itilerow;
    int jcol;
    int lag_tmp;
    int nx;
    short input_sizes_idx_0;
    short sizes_idx_0;
    boolean_T empty_non_axis_sizes;
    edge[0] = 60.0;
    edge[1] = 480.0;
    e_fft(y, x);
    nx = x.size(1) << 12;
    c1.set_size(4096, x.size(1));
    for (ibmat = 0; ibmat < nx; ibmat++) {
        c1[ibmat] = rt_hypotd_snf(x[ibmat].re, x[ibmat].im);
    }
    b_y.set_size(4096, c1.size(1));
    nx = c1.size(1) << 12;
    for (ibmat = 0; ibmat < nx; ibmat++) {
        b_y[ibmat] = c1[ibmat] * c1[ibmat];
    }
    if (b_y.size(1) == 0) {
        x.set_size(4096, 0);
    } else {
        nx = b_y.size(1);
        x.set_size(4096, b_y.size(1));
        for (ibmat = 0; ibmat < nx; ibmat++) {
            ::coder::internal::FFTImplementationCallback::g_doHalfLengthRadix2(
                b_y, ibmat << 12, *(creal_T(*)[4096]) & x[4096 * ibmat]);
        }
        itilerow = 4096 * x.size(1);
        x.set_size(4096, x.size(1));
        for (i = 0; i < itilerow; i++) {
            x[i].re = 0.000244140625 * x[i].re;
            x[i].im = 0.000244140625 * x[i].im;
        }
    }
    c1.set_size(4096, x.size(1));
    itilerow = 4096 * x.size(1);
    for (i = 0; i < itilerow; i++) {
        c1[i] = x[i].re / 64.0;
    }
    c_y.set_size(1, 480);
    for (i = 0; i < 480; i++) {
        c_y[i] = static_cast<double>(i) + 1.0;
    }
    itilerow = c1.size(1);
    lag.set_size(480, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 480; i1++) {
            lag[i1 + lag.size(0) * i] =
                c1[(static_cast<int>(c_y[i1]) + 4096 * i) + 3615];
        }
    }
    if (c1.size(1) != 0) {
        nx = c1.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        input_sizes_idx_0 = 480;
    } else {
        input_sizes_idx_0 = 0;
    }
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        sizes_idx_0 = 481;
    } else {
        sizes_idx_0 = 0;
    }
    ibmat = input_sizes_idx_0;
    itilerow = c1.size(1);
    b_c1.set_size(481, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 481; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = c1[i1 + 4096 * i];
        }
    }
    jcol = sizes_idx_0;
    Rt.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < ibmat; i1++) {
            Rt[i1 + Rt.size(0) * i] = lag[i1 + input_sizes_idx_0 * i];
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            Rt[(i1 + input_sizes_idx_0) + Rt.size(0) * i] =
                b_c1[i1 + sizes_idx_0 * i];
        }
    }
    if (541 > Rt.size(0)) {
        i = -1;
        i1 = -1;
    } else {
        i = 539;
        i1 = Rt.size(0) - 1;
    }
    itilerow = Rt.size(1);
    b_x.set_size(1, Rt.size(1));
    for (nx = 0; nx < itilerow; nx++) {
        b_x[nx] = Rt[Rt.size(0) * nx + 480];
    }
    nx = Rt.size(1) - 1;
    for (ibmat = 0; ibmat <= nx; ibmat++) {
        b_x[ibmat] = sqrt(b_x[ibmat]);
    }
    lag_tmp = i1 - i;
    lag.set_size(lag_tmp, b_x.size(1));
    nx = b_x.size(1);
    for (jcol = 0; jcol < nx; jcol++) {
        ibmat = jcol * lag_tmp;
        for (itilerow = 0; itilerow < lag_tmp; itilerow++) {
            lag[ibmat + itilerow] = b_x[jcol];
        }
    }
    itilerow = Rt.size(1);
    lag.set_size(lag_tmp, Rt.size(1));
    for (i1 = 0; i1 < itilerow; i1++) {
        for (nx = 0; nx < lag_tmp; nx++) {
            lag[nx + lag.size(0) * i1] = Rt[((i + nx) + Rt.size(0) * i1) + 1] /
                                         lag[nx + lag.size(0) * i1];
        }
    }
    if (lag.size(1) != 0) {
        nx = lag.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (lag.size(1) != 0)) {
        input_sizes_idx_0 = 59;
    } else {
        input_sizes_idx_0 = 0;
    }
    if (empty_non_axis_sizes || ((lag.size(0) != 0) && (lag.size(1) != 0))) {
        sizes_idx_0 = static_cast<short>(lag.size(0));
    } else {
        sizes_idx_0 = 0;
    }
    jcol = sizes_idx_0;
    b_c1.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        itilerow = input_sizes_idx_0;
        for (i1 = 0; i1 < itilerow; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = 0.0;
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            b_c1[(i1 + input_sizes_idx_0) + b_c1.size(0) * i] =
                lag[i1 + sizes_idx_0 * i];
        }
    }
    getCandidates(b_c1, edge, peak, locs);
    f0.set_size(locs.size(0));
    itilerow = locs.size(0);
    for (i = 0; i < itilerow; i++) {
        f0[i] = 24000.0 / locs[i];
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &y
//                ::coder::array<double, 1U> &f0
// Return Type  : void
//
void f_NCF(const ::coder::array<double, 2U> &y, ::coder::array<double, 1U> &f0)
{
    array<creal_T, 2U> x;
    array<double, 2U> Rt;
    array<double, 2U> b_c1;
    array<double, 2U> b_x;
    array<double, 2U> b_y;
    array<double, 2U> c1;
    array<double, 2U> c_y;
    array<double, 2U> lag;
    array<double, 1U> locs;
    array<double, 1U> peak;
    double edge[2];
    int i;
    int i1;
    int ibmat;
    int itilerow;
    int jcol;
    int lag_tmp;
    int nx;
    short input_sizes_idx_0;
    short sizes_idx_0;
    boolean_T empty_non_axis_sizes;
    edge[0] = 110.0;
    edge[1] = 882.0;
    f_fft(y, x);
    nx = x.size(1) << 13;
    c1.set_size(8192, x.size(1));
    for (ibmat = 0; ibmat < nx; ibmat++) {
        c1[ibmat] = rt_hypotd_snf(x[ibmat].re, x[ibmat].im);
    }
    b_y.set_size(8192, c1.size(1));
    nx = c1.size(1) << 13;
    for (ibmat = 0; ibmat < nx; ibmat++) {
        b_y[ibmat] = c1[ibmat] * c1[ibmat];
    }
    if (b_y.size(1) == 0) {
        x.set_size(8192, 0);
    } else {
        nx = b_y.size(1);
        x.set_size(8192, b_y.size(1));
        for (ibmat = 0; ibmat < nx; ibmat++) {
            ::coder::internal::FFTImplementationCallback::j_doHalfLengthRadix2(
                b_y, ibmat << 13, *(creal_T(*)[8192]) & x[8192 * ibmat]);
        }
        itilerow = 8192 * x.size(1);
        x.set_size(8192, x.size(1));
        for (i = 0; i < itilerow; i++) {
            x[i].re = 0.0001220703125 * x[i].re;
            x[i].im = 0.0001220703125 * x[i].im;
        }
    }
    c1.set_size(8192, x.size(1));
    itilerow = 8192 * x.size(1);
    for (i = 0; i < itilerow; i++) {
        c1[i] = x[i].re / 90.509667991878089;
    }
    c_y.set_size(1, 882);
    for (i = 0; i < 882; i++) {
        c_y[i] = static_cast<double>(i) + 1.0;
    }
    itilerow = c1.size(1);
    lag.set_size(882, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 882; i1++) {
            lag[i1 + lag.size(0) * i] =
                c1[(static_cast<int>(c_y[i1]) + 8192 * i) + 7309];
        }
    }
    if (c1.size(1) != 0) {
        nx = c1.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        input_sizes_idx_0 = 882;
    } else {
        input_sizes_idx_0 = 0;
    }
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        sizes_idx_0 = 883;
    } else {
        sizes_idx_0 = 0;
    }
    ibmat = input_sizes_idx_0;
    itilerow = c1.size(1);
    b_c1.set_size(883, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 883; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = c1[i1 + 8192 * i];
        }
    }
    jcol = sizes_idx_0;
    Rt.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < ibmat; i1++) {
            Rt[i1 + Rt.size(0) * i] = lag[i1 + input_sizes_idx_0 * i];
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            Rt[(i1 + input_sizes_idx_0) + Rt.size(0) * i] =
                b_c1[i1 + sizes_idx_0 * i];
        }
    }
    if (993 > Rt.size(0)) {
        i = -1;
        i1 = -1;
    } else {
        i = 991;
        i1 = Rt.size(0) - 1;
    }
    itilerow = Rt.size(1);
    b_x.set_size(1, Rt.size(1));
    for (nx = 0; nx < itilerow; nx++) {
        b_x[nx] = Rt[Rt.size(0) * nx + 882];
    }
    nx = Rt.size(1) - 1;
    for (ibmat = 0; ibmat <= nx; ibmat++) {
        b_x[ibmat] = sqrt(b_x[ibmat]);
    }
    lag_tmp = i1 - i;
    lag.set_size(lag_tmp, b_x.size(1));
    nx = b_x.size(1);
    for (jcol = 0; jcol < nx; jcol++) {
        ibmat = jcol * lag_tmp;
        for (itilerow = 0; itilerow < lag_tmp; itilerow++) {
            lag[ibmat + itilerow] = b_x[jcol];
        }
    }
    itilerow = Rt.size(1);
    lag.set_size(lag_tmp, Rt.size(1));
    for (i1 = 0; i1 < itilerow; i1++) {
        for (nx = 0; nx < lag_tmp; nx++) {
            lag[nx + lag.size(0) * i1] = Rt[((i + nx) + Rt.size(0) * i1) + 1] /
                                         lag[nx + lag.size(0) * i1];
        }
    }
    if (lag.size(1) != 0) {
        nx = lag.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (lag.size(1) != 0)) {
        input_sizes_idx_0 = 109;
    } else {
        input_sizes_idx_0 = 0;
    }
    if (empty_non_axis_sizes || ((lag.size(0) != 0) && (lag.size(1) != 0))) {
        sizes_idx_0 = static_cast<short>(lag.size(0));
    } else {
        sizes_idx_0 = 0;
    }
    jcol = sizes_idx_0;
    b_c1.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        itilerow = input_sizes_idx_0;
        for (i1 = 0; i1 < itilerow; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = 0.0;
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            b_c1[(i1 + input_sizes_idx_0) + b_c1.size(0) * i] =
                lag[i1 + sizes_idx_0 * i];
        }
    }
    getCandidates(b_c1, edge, peak, locs);
    f0.set_size(locs.size(0));
    itilerow = locs.size(0);
    for (i = 0; i < itilerow; i++) {
        f0[i] = 44100.0 / locs[i];
    }
}

//
// Arguments    : const ::coder::array<double, 2U> &y
//                ::coder::array<double, 1U> &f0
// Return Type  : void
//
void g_NCF(const ::coder::array<double, 2U> &y, ::coder::array<double, 1U> &f0)
{
    array<creal_T, 2U> x;
    array<double, 2U> Rt;
    array<double, 2U> b_c1;
    array<double, 2U> b_x;
    array<double, 2U> b_y;
    array<double, 2U> c1;
    array<double, 2U> c_y;
    array<double, 2U> lag;
    array<double, 1U> locs;
    array<double, 1U> peak;
    double edge[2];
    int i;
    int i1;
    int ibmat;
    int itilerow;
    int jcol;
    int lag_tmp;
    int nx;
    short input_sizes_idx_0;
    short sizes_idx_0;
    boolean_T empty_non_axis_sizes;
    edge[0] = 120.0;
    edge[1] = 960.0;
    g_fft(y, x);
    nx = x.size(1) << 13;
    c1.set_size(8192, x.size(1));
    for (ibmat = 0; ibmat < nx; ibmat++) {
        c1[ibmat] = rt_hypotd_snf(x[ibmat].re, x[ibmat].im);
    }
    b_y.set_size(8192, c1.size(1));
    nx = c1.size(1) << 13;
    for (ibmat = 0; ibmat < nx; ibmat++) {
        b_y[ibmat] = c1[ibmat] * c1[ibmat];
    }
    if (b_y.size(1) == 0) {
        x.set_size(8192, 0);
    } else {
        nx = b_y.size(1);
        x.set_size(8192, b_y.size(1));
        for (ibmat = 0; ibmat < nx; ibmat++) {
            ::coder::internal::FFTImplementationCallback::j_doHalfLengthRadix2(
                b_y, ibmat << 13, *(creal_T(*)[8192]) & x[8192 * ibmat]);
        }
        itilerow = 8192 * x.size(1);
        x.set_size(8192, x.size(1));
        for (i = 0; i < itilerow; i++) {
            x[i].re = 0.0001220703125 * x[i].re;
            x[i].im = 0.0001220703125 * x[i].im;
        }
    }
    c1.set_size(8192, x.size(1));
    itilerow = 8192 * x.size(1);
    for (i = 0; i < itilerow; i++) {
        c1[i] = x[i].re / 90.509667991878089;
    }
    c_y.set_size(1, 960);
    for (i = 0; i < 960; i++) {
        c_y[i] = static_cast<double>(i) + 1.0;
    }
    itilerow = c1.size(1);
    lag.set_size(960, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 960; i1++) {
            lag[i1 + lag.size(0) * i] =
                c1[(static_cast<int>(c_y[i1]) + 8192 * i) + 7231];
        }
    }
    if (c1.size(1) != 0) {
        nx = c1.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        input_sizes_idx_0 = 960;
    } else {
        input_sizes_idx_0 = 0;
    }
    if (empty_non_axis_sizes || (c1.size(1) != 0)) {
        sizes_idx_0 = 961;
    } else {
        sizes_idx_0 = 0;
    }
    ibmat = input_sizes_idx_0;
    itilerow = c1.size(1);
    b_c1.set_size(961, c1.size(1));
    for (i = 0; i < itilerow; i++) {
        for (i1 = 0; i1 < 961; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = c1[i1 + 8192 * i];
        }
    }
    jcol = sizes_idx_0;
    Rt.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < ibmat; i1++) {
            Rt[i1 + Rt.size(0) * i] = lag[i1 + input_sizes_idx_0 * i];
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            Rt[(i1 + input_sizes_idx_0) + Rt.size(0) * i] =
                b_c1[i1 + sizes_idx_0 * i];
        }
    }
    if (1081 > Rt.size(0)) {
        i = -1;
        i1 = -1;
    } else {
        i = 1079;
        i1 = Rt.size(0) - 1;
    }
    itilerow = Rt.size(1);
    b_x.set_size(1, Rt.size(1));
    for (nx = 0; nx < itilerow; nx++) {
        b_x[nx] = Rt[Rt.size(0) * nx + 960];
    }
    nx = Rt.size(1) - 1;
    for (ibmat = 0; ibmat <= nx; ibmat++) {
        b_x[ibmat] = sqrt(b_x[ibmat]);
    }
    lag_tmp = i1 - i;
    lag.set_size(lag_tmp, b_x.size(1));
    nx = b_x.size(1);
    for (jcol = 0; jcol < nx; jcol++) {
        ibmat = jcol * lag_tmp;
        for (itilerow = 0; itilerow < lag_tmp; itilerow++) {
            lag[ibmat + itilerow] = b_x[jcol];
        }
    }
    itilerow = Rt.size(1);
    lag.set_size(lag_tmp, Rt.size(1));
    for (i1 = 0; i1 < itilerow; i1++) {
        for (nx = 0; nx < lag_tmp; nx++) {
            lag[nx + lag.size(0) * i1] = Rt[((i + nx) + Rt.size(0) * i1) + 1] /
                                         lag[nx + lag.size(0) * i1];
        }
    }
    if (lag.size(1) != 0) {
        nx = lag.size(1);
    } else {
        nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
    if (empty_non_axis_sizes || (lag.size(1) != 0)) {
        input_sizes_idx_0 = 119;
    } else {
        input_sizes_idx_0 = 0;
    }
    if (empty_non_axis_sizes || ((lag.size(0) != 0) && (lag.size(1) != 0))) {
        sizes_idx_0 = static_cast<short>(lag.size(0));
    } else {
        sizes_idx_0 = 0;
    }
    jcol = sizes_idx_0;
    b_c1.set_size(input_sizes_idx_0 + sizes_idx_0, nx);
    for (i = 0; i < nx; i++) {
        itilerow = input_sizes_idx_0;
        for (i1 = 0; i1 < itilerow; i1++) {
            b_c1[i1 + b_c1.size(0) * i] = 0.0;
        }
    }
    for (i = 0; i < nx; i++) {
        for (i1 = 0; i1 < jcol; i1++) {
            b_c1[(i1 + input_sizes_idx_0) + b_c1.size(0) * i] =
                lag[i1 + sizes_idx_0 * i];
        }
    }
    getCandidates(b_c1, edge, peak, locs);
    f0.set_size(locs.size(0));
    itilerow = locs.size(0);
    for (i = 0; i < itilerow; i++) {
        f0[i] = 48000.0 / locs[i];
    }
}

} // namespace pitch
} // namespace internal
} // namespace audio
} // namespace coder

//
// File trailer for NCF.cpp
//
// [EOF]
//