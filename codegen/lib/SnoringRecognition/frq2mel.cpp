//
// File: frq2mel.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 27-Feb-2022 00:06:11
//

// Include Files
#include "frq2mel.h"
#include "abs.h"
#include "log.h"
#include "rt_nonfinite.h"
#include "sign.h"
#include "coder_array.h"

// Function Definitions
//
// function [mel, mr] = frq2mel(frq)
//
// FRQ2ERB  Convert Hertz to Mel frequency scale MEL=(FRQ)
//  [mel,mr] = frq2mel(frq) converts a vector of frequencies (in Hz)
//  to the corresponding values on the Mel scale which corresponds
//  to the perceived pitch of a tone.
//    mr gives the corresponding gradients in Hz/mel.
//
// Arguments    : const double frq[2]
//                double mel[2]
// Return Type  : void
//
void frq2mel(const double frq[2], double mel[2])
{
    double b_dv[2];
    double b_dv1[2];
    // 	The relationship between mel and frq is given by:
    //
    // 	m = ln(1 + f/700) * 1000 / ln(1+1000/700)
    //
    //   	This means that m(1000) = 1000
    //
    // 	References:
    //
    // 	  [1] S. S. Stevens & J. Volkman "The relation of pitch to
    // 		frequency", American J of Psychology, V 53, p329 1940
    // 	  [2] C. G. M. Fant, "Acoustic description & classification
    // 		of phonetic units", Ericsson Tchnics, No 1 1959
    // 		(reprinted in "Speech Sounds & Features", MIT Press 1973)
    // 	  [3] S. B. Davis & P. Mermelstein, "Comparison of parametric
    // 		representations for monosyllabic word recognition in
    // 		continuously spoken sentences", IEEE ASSP, V 28,
    // 		pp 357-366 Aug 1980
    // 	  [4] J. R. Deller Jr, J. G. Proakis, J. H. L. Hansen,
    // 		"Discrete-Time Processing of Speech Signals", p380,
    // 		Macmillan 1993
    // 	  [5] HTK Reference Manual p73
    //
    //       Copyright (C) Mike Brookes 1998
    //       Version: $Id: frq2mel.m,v 1.7 2010/08/01 08:41:57 dmb Exp $
    //
    //    VOICEBOX is a MATLAB toolbox for speech processing.
    //    Home page: http://www.ee.ic.ac.uk/hp/staff/dmb/voicebox/voicebox.html
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //    This program is free software; you can redistribute it and/or modify
    //    it under the terms of the GNU General Public License as published by
    //    the Free Software Foundation; either version 2 of the License, or
    //    (at your option) any later version.
    //
    //    This program is distributed in the hope that it will be useful,
    //    but WITHOUT ANY WARRANTY; without even the implied warranty of
    //    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    //    GNU General Public License for more details.
    //
    //    You can obtain a copy of the GNU General Public License from
    //    http://www.gnu.org/copyleft/gpl.html or by writing to
    //    Free Software Foundation, Inc.,675 Mass Ave, Cambridge, MA 02139, USA.
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // 'frq2mel:54' if isempty(k)
    // 'frq2mel:58' af = abs(frq);
    // 'frq2mel:59' mel = sign(frq) .* log(1 + af / 700) * k;
    b_dv[0] = frq[0];
    b_dv[1] = frq[1];
    coder::b_sign(b_dv);
    coder::b_abs(frq, b_dv1);
    b_dv1[0] = b_dv1[0] / 700.0 + 1.0;
    b_dv1[1] = b_dv1[1] / 700.0 + 1.0;
    coder::c_log(b_dv1);
    mel[0] = b_dv[0] * b_dv1[0] * 1127.01048;
    mel[1] = b_dv[1] * b_dv1[1] * 1127.01048;
    // 'frq2mel:60' mr = (700 + af) / k;
    // 'frq2mel:62' if ~nargout
}

//
// function [mel, mr] = frq2mel(frq)
//
// FRQ2ERB  Convert Hertz to Mel frequency scale MEL=(FRQ)
//  [mel,mr] = frq2mel(frq) converts a vector of frequencies (in Hz)
//  to the corresponding values on the Mel scale which corresponds
//  to the perceived pitch of a tone.
//    mr gives the corresponding gradients in Hz/mel.
//
// Arguments    : const coder::array<double, 2U> &frq
//                coder::array<double, 2U> &mel
// Return Type  : void
//
void frq2mel(const coder::array<double, 2U> &frq, coder::array<double, 2U> &mel)
{
    coder::array<double, 2U> r;
    coder::array<double, 2U> r1;
    int i;
    int loop_ub;
    // 	The relationship between mel and frq is given by:
    //
    // 	m = ln(1 + f/700) * 1000 / ln(1+1000/700)
    //
    //   	This means that m(1000) = 1000
    //
    // 	References:
    //
    // 	  [1] S. S. Stevens & J. Volkman "The relation of pitch to
    // 		frequency", American J of Psychology, V 53, p329 1940
    // 	  [2] C. G. M. Fant, "Acoustic description & classification
    // 		of phonetic units", Ericsson Tchnics, No 1 1959
    // 		(reprinted in "Speech Sounds & Features", MIT Press 1973)
    // 	  [3] S. B. Davis & P. Mermelstein, "Comparison of parametric
    // 		representations for monosyllabic word recognition in
    // 		continuously spoken sentences", IEEE ASSP, V 28,
    // 		pp 357-366 Aug 1980
    // 	  [4] J. R. Deller Jr, J. G. Proakis, J. H. L. Hansen,
    // 		"Discrete-Time Processing of Speech Signals", p380,
    // 		Macmillan 1993
    // 	  [5] HTK Reference Manual p73
    //
    //       Copyright (C) Mike Brookes 1998
    //       Version: $Id: frq2mel.m,v 1.7 2010/08/01 08:41:57 dmb Exp $
    //
    //    VOICEBOX is a MATLAB toolbox for speech processing.
    //    Home page: http://www.ee.ic.ac.uk/hp/staff/dmb/voicebox/voicebox.html
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //    This program is free software; you can redistribute it and/or modify
    //    it under the terms of the GNU General Public License as published by
    //    the Free Software Foundation; either version 2 of the License, or
    //    (at your option) any later version.
    //
    //    This program is distributed in the hope that it will be useful,
    //    but WITHOUT ANY WARRANTY; without even the implied warranty of
    //    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    //    GNU General Public License for more details.
    //
    //    You can obtain a copy of the GNU General Public License from
    //    http://www.gnu.org/copyleft/gpl.html or by writing to
    //    Free Software Foundation, Inc.,675 Mass Ave, Cambridge, MA 02139, USA.
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // 'frq2mel:54' if isempty(k)
    // 'frq2mel:58' af = abs(frq);
    // 'frq2mel:59' mel = sign(frq) .* log(1 + af / 700) * k;
    r.set_size(1, frq.size(1));
    loop_ub = frq.size(1);
    for (i = 0; i < loop_ub; i++) {
        r[i] = frq[i];
    }
    coder::b_sign(r);
    coder::b_abs(frq, r1);
    r1.set_size(1, r1.size(1));
    loop_ub = r1.size(1) - 1;
    for (i = 0; i <= loop_ub; i++) {
        r1[i] = r1[i] / 700.0 + 1.0;
    }
    coder::b_log(r1);
    mel.set_size(1, r.size(1));
    loop_ub = r.size(1);
    for (i = 0; i < loop_ub; i++) {
        mel[i] = r[i] * r1[i] * 1127.01048;
    }
    // 'frq2mel:60' mr = (700 + af) / k;
    // 'frq2mel:62' if ~nargout
}

//
// File trailer for frq2mel.cpp
//
// [EOF]
//