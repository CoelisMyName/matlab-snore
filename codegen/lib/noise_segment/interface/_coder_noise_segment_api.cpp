//
// File: _coder_noise_segment_api.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "_coder_noise_segment_api.h"
#include "_coder_noise_segment_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131610U,                                              // fVersionInfo
    NULL,                                                 // fErrorFunction
    "noise_segment",                                      // fFunctionName
    NULL,                                                 // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    NULL                                                  // fSigMem
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<int64_T, 1U> &ret);

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *w_starts,
                             const char_T *identifier,
                             coder::array<int64_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int64_T, 1U> &y);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *fs,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y);

static const mxArray *emlrt_marshallOut(const real_T u);

static const mxArray *emlrt_marshallOut(const coder::array<int64_T, 2U> &u);

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<int64_T, 1U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<int64_T, 1U> &ret)
{
    static const int32_T dims = -1;
    int32_T i;
    const boolean_T b = true;
    emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"int64",
                              false, 1U, (void *)&dims, &b, &i);
    ret.prealloc(i);
    ret.set_size(i);
    ret.set((int64_T *)emlrtMxGetData(src), ret.size(0));
    emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
    static const int32_T dims = 0;
    real_T ret;
    emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 0U, (void *)&dims);
    ret = *(real_T *)emlrtMxGetData(src);
    emlrtDestroyArray(&src);
    return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 1U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret)
{
    static const int32_T dims = -1;
    int32_T i;
    const boolean_T b = true;
    emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src,
                              (const char_T *)"double", false, 1U,
                              (void *)&dims, &b, &i);
    ret.prealloc(i);
    ret.set_size(i);
    ret.set((real_T *)emlrtMxGetData(src), ret.size(0));
    emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *w_starts
//                const char_T *identifier
//                coder::array<int64_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *w_starts,
                             const char_T *identifier,
                             coder::array<int64_T, 1U> &y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = const_cast<const char_T *>(identifier);
    thisId.fParent = NULL;
    thisId.bParentIsCell = false;
    emlrt_marshallIn(sp, emlrtAlias(w_starts), &thisId, y);
    emlrtDestroyArray(&w_starts);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<int64_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int64_T, 1U> &y)
{
    b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *fs
//                const char_T *identifier
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *fs,
                               const char_T *identifier)
{
    emlrtMsgIdentifier thisId;
    real_T y;
    thisId.fIdentifier = const_cast<const char_T *>(identifier);
    thisId.fParent = NULL;
    thisId.bParentIsCell = false;
    y = emlrt_marshallIn(sp, emlrtAlias(fs), &thisId);
    emlrtDestroyArray(&fs);
    return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
    real_T y;
    y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *x
//                const char_T *identifier
//                coder::array<real_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = const_cast<const char_T *>(identifier);
    thisId.fParent = NULL;
    thisId.bParentIsCell = false;
    emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y);
    emlrtDestroyArray(&x);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y)
{
    b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

//
// Arguments    : const real_T u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const real_T u)
{
    const mxArray *m;
    const mxArray *y;
    y = NULL;
    m = emlrtCreateDoubleScalar(u);
    emlrtAssign(&y, m);
    return y;
}

//
// Arguments    : const coder::array<int64_T, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const coder::array<int64_T, 2U> &u)
{
    static const int32_T iv[2] = {0, 0};
    const mxArray *m;
    const mxArray *y;
    y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxINT64_CLASS, mxREAL);
    emlrtMxSetData((mxArray *)m,
                   &(((coder::array<int64_T, 2U> *)&u)->data())[0]);
    emlrtSetDimensions((mxArray *)m, ((coder::array<int64_T, 2U> *)&u)->size(),
                       2);
    emlrtAssign(&y, m);
    return y;
}

//
// Arguments    : const mxArray * const prhs[5]
//                int32_T nlhs
//                const mxArray *plhs[2]
// Return Type  : void
//
void noise_segment_api(const mxArray *const prhs[5], int32_T nlhs,
                       const mxArray *plhs[2])
{
    coder::array<int64_T, 1U> w_ends;
    coder::array<int64_T, 1U> w_starts;
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    real_T fs;
    real_T margin;
    real_T min_gap;
    real_T olength;
    real_T ostart;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);
    // Marshall function inputs
    w_starts.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "w_starts", w_starts);
    w_ends.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "w_ends", w_ends);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "fs");
    min_gap = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "min_gap");
    margin = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "margin");
    // Invoke the target function
    noise_segment(w_starts, w_ends, fs, min_gap, margin, &ostart, &olength);
    // Marshall function outputs
    plhs[0] = emlrt_marshallOut(ostart);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(olength);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void noise_segment_atexit()
{
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    mexFunctionCreateRootTLS();
    st.tls = emlrtRootTLSGlobal;
    emlrtEnterRtStackR2012b(&st);
    emlrtLeaveRtStackR2012b(&st);
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    noise_segment_xil_terminate();
    noise_segment_xil_shutdown();
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void noise_segment_initialize()
{
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    mexFunctionCreateRootTLS();
    st.tls = emlrtRootTLSGlobal;
    emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
    emlrtEnterRtStackR2012b(&st);
    emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void noise_segment_terminate()
{
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    st.tls = emlrtRootTLSGlobal;
    emlrtLeaveRtStackR2012b(&st);
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// Arguments    : const mxArray * const prhs[2]
//                int32_T nlhs
//                const mxArray *plhs[2]
// Return Type  : void
//
void vad_api(const mxArray *const prhs[2], int32_T nlhs, const mxArray *plhs[2])
{
    coder::array<int64_T, 2U> w_ends;
    coder::array<int64_T, 2U> w_starts;
    coder::array<real_T, 1U> x;
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    const mxArray *prhs_copy_idx_0;
    real_T fs;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);
    prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, false, -1);
    // Marshall function inputs
    x.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "x", x);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");
    // Invoke the target function
    vad(x, fs, w_starts, w_ends);
    // Marshall function outputs
    w_starts.no_free();
    plhs[0] = emlrt_marshallOut(w_starts);
    if (nlhs > 1) {
        w_ends.no_free();
        plhs[1] = emlrt_marshallOut(w_ends);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// File trailer for _coder_noise_segment_api.cpp
//
// [EOF]
//
