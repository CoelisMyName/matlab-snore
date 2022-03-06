#ifndef _CODER_SNORINGRECOGNITION_MEX_H
#define _CODER_SNORINGRECOGNITION_MEX_H

#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_aweight_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                const mxArray *prhs[1]);

void unsafe_bark_feat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[2]);

void unsafe_cep_feat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                 const mxArray *prhs[2]);

void unsafe_classifier_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                   const mxArray *prhs[4]);

void unsafe_cweight_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                const mxArray *prhs[1]);

void unsafe_fmt_feat_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                 const mxArray *prhs[2]);

void unsafe_gtcc_feat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[2]);

void unsafe_mfcc_feat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[2]);

void unsafe_noise_segment_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                      int32_T nrhs, const mxArray *prhs[5]);

void unsafe_patient_classifier_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs,
                                           const mxArray *prhs[19]);

void unsafe_pitch_feat_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
                                   const mxArray *prhs[2]);

void unsafe_pr800_feat_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
                                   const mxArray *prhs[2]);

void unsafe_se_feat_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
                                const mxArray *prhs[2]);

void unsafe_vad_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                            const mxArray *prhs[2]);

void unsafe_zweight_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                const mxArray *prhs[1]);

#endif
