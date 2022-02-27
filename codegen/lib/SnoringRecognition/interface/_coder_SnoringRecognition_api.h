//
// File: _coder_SnoringRecognition_api.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 27-Feb-2022 00:06:11
//

#ifndef _CODER_SNORINGRECOGNITION_API_H
#define _CODER_SNORINGRECOGNITION_API_H

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
void SnoringRecognition_atexit();

void SnoringRecognition_initialize();

void SnoringRecognition_terminate();

void SnoringRecognition_xil_shutdown();

void SnoringRecognition_xil_terminate();

void aweight(coder::array<real_T, 1U> *x, real_T p[8], real_T f[8], real_T *s);

void aweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3]);

void bark_feat(coder::array<real_T, 1U> *sig, real_T fs, real_T barkee[17]);

void bark_feat_api(const mxArray *const prhs[2], const mxArray **plhs);

void cep_feat(coder::array<real_T, 1U> *sig, real_T fs, real_T cep_data[],
              int32_T cep_size[2]);

void cep_feat_api(const mxArray *const prhs[2], const mxArray **plhs);

void classifier(coder::array<real_T, 1U> *x, real_T fs,
                coder::array<int64_T, 1U> *w_starts,
                coder::array<int64_T, 1U> *w_ends,
                coder::array<real_T, 2U> *predict_label);

void classifier_api(const mxArray *const prhs[4], const mxArray **plhs);

void cweight(coder::array<real_T, 1U> *x, real_T p[8], real_T f[8], real_T *s);

void cweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3]);

void fmt_feat(coder::array<real_T, 1U> *sig, real_T fs, real_T *Formant1,
              real_T *Formant2, real_T *Formant3);

void fmt_feat_api(const mxArray *const prhs[2], int32_T nlhs,
                  const mxArray *plhs[3]);

void gtcc_feat(coder::array<real_T, 1U> *sig, real_T fs,
               coder::array<real_T, 2U> *GTCCmean);

void gtcc_feat_api(const mxArray *const prhs[2], const mxArray **plhs);

void mfcc_feat(coder::array<real_T, 1U> *sig, real_T fs,
               coder::array<real_T, 2U> *MFCC_feature);

void mfcc_feat_api(const mxArray *const prhs[2], const mxArray **plhs);

void noise_segment(coder::array<int64_T, 1U> *w_starts,
                   coder::array<int64_T, 1U> *w_ends, real_T fs, real_T min_gap,
                   real_T margin, real_T *ostart, real_T *olength);

void noise_segment_api(const mxArray *const prhs[5], int32_T nlhs,
                       const mxArray *plhs[2]);

real_T patient_classifier(
    coder::array<real_T, 2U> *MFCC_feature, coder::array<real_T, 2U> *BARKEE,
    coder::array<real_T, 1U> *period_mean, coder::array<real_T, 1U> *period_max,
    coder::array<real_T, 1U> *period_min, coder::array<real_T, 1U> *period_var,
    coder::array<real_T, 2U> *cep, coder::array<real_T, 1U> *Formant1,
    coder::array<real_T, 1U> *Formant2, coder::array<real_T, 1U> *Formant3,
    coder::array<real_T, 2U> *GTCCmean, coder::array<real_T, 1U> *PR800mean,
    coder::array<real_T, 1U> *PR800max, coder::array<real_T, 1U> *PR800min,
    coder::array<real_T, 1U> *PR800var, coder::array<real_T, 1U> *SE_mean,
    coder::array<real_T, 1U> *SE_max, coder::array<real_T, 1U> *SE_min,
    coder::array<real_T, 1U> *SE_var);

void patient_classifier_api(const mxArray *const prhs[19],
                            const mxArray **plhs);

void pitch_feat(coder::array<real_T, 1U> *sig, real_T fs, real_T *period_mean,
                real_T *period_min, real_T *period_max, real_T *period_var);

void pitch_feat_api(const mxArray *const prhs[2], int32_T nlhs,
                    const mxArray *plhs[4]);

void pr800_feat(coder::array<real_T, 1U> *sig, real_T fs, real_T *PR800_mean,
                real_T *PR800_max, real_T *PR800_min, real_T *PR800_var);

void pr800_feat_api(const mxArray *const prhs[2], int32_T nlhs,
                    const mxArray *plhs[4]);

void se_feat(coder::array<real_T, 1U> *sig, real_T fs, real_T *SE_mean,
             real_T *SE_max, real_T *SE_min, real_T *SE_var);

void se_feat_api(const mxArray *const prhs[2], int32_T nlhs,
                 const mxArray *plhs[4]);

void vad(coder::array<real_T, 1U> *x, real_T fs,
         coder::array<int64_T, 2U> *w_starts,
         coder::array<int64_T, 2U> *w_ends);

void vad_api(const mxArray *const prhs[2], int32_T nlhs,
             const mxArray *plhs[2]);

void zweight(coder::array<real_T, 1U> *x, real_T p[8], real_T f[8], real_T *s);

void zweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3]);

#endif
//
// File trailer for _coder_SnoringRecognition_api.h
//
// [EOF]
//
