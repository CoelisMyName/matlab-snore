//
// File: _coder_classifier_api.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

#ifndef _CODER_CLASSIFIER_API_H
#define _CODER_CLASSIFIER_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void classifier(coder::array<real_T, 1U> *x, real_T fs,
                coder::array<int64_T, 1U> *w_starts,
                coder::array<int64_T, 1U> *w_ends,
                coder::array<real_T, 2U> *predict_label);

void classifier_api(const mxArray *const prhs[4], const mxArray **plhs);

void classifier_atexit();

void classifier_initialize();

void classifier_terminate();

void classifier_xil_shutdown();

void classifier_xil_terminate();

void noise_segment(coder::array<int64_T, 1U> *w_starts,
                   coder::array<int64_T, 1U> *w_ends, real_T fs, real_T min_gap,
                   real_T margin, real_T *ostart, real_T *olength);

void noise_segment_api(const mxArray *const prhs[5], int32_T nlhs,
                       const mxArray *plhs[2]);

void vad(coder::array<real_T, 1U> *x, real_T fs,
         coder::array<int64_T, 2U> *w_starts,
         coder::array<int64_T, 2U> *w_ends);

void vad_api(const mxArray *const prhs[2], int32_T nlhs,
             const mxArray *plhs[2]);

#endif
//
// File trailer for _coder_classifier_api.h
//
// [EOF]
//
