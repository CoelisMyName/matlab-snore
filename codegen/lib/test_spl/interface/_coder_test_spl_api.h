//
// File: _coder_test_spl_api.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 22:09:11
//

#ifndef _CODER_TEST_SPL_API_H
#define _CODER_TEST_SPL_API_H

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
void aweight(coder::array<real_T, 1U> *x, real_T p[8], real_T f[8], real_T *s);

void aweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3]);

void cweight(coder::array<real_T, 1U> *x, real_T p[8], real_T f[8], real_T *s);

void cweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3]);

void test_spl_atexit();

void test_spl_initialize();

void test_spl_terminate();

void test_spl_xil_shutdown();

void test_spl_xil_terminate();

void zweight(coder::array<real_T, 1U> *x, real_T p[8], real_T f[8], real_T *s);

void zweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3]);

#endif
//
// File trailer for _coder_test_spl_api.h
//
// [EOF]
//
