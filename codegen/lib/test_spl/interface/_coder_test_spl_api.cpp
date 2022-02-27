//
// File: _coder_test_spl_api.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 22:09:11
//

// Include Files
#include "_coder_test_spl_api.h"
#include "_coder_test_spl_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131610U,                                              // fVersionInfo
    NULL,                                                 // fErrorFunction
    "test_spl",                                           // fFunctionName
    NULL,                                                 // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    NULL                                                  // fSigMem
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y);

static const mxArray *emlrt_marshallOut(const real_T u[8]);

static const mxArray *emlrt_marshallOut(const real_T u);

// Function Definitions
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
// Arguments    : const real_T u[8]
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const real_T u[8])
{
    static const int32_T iv[2] = {0, 0};
    static const int32_T iv1[2] = {1, 8};
    const mxArray *m;
    const mxArray *y;
    y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS,
                                mxREAL);
    emlrtMxSetData((mxArray *)m, (void *)&u[0]);
    emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
    emlrtAssign(&y, m);
    return y;
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
// Arguments    : const mxArray *prhs
//                int32_T nlhs
//                const mxArray *plhs[3]
// Return Type  : void
//
void aweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3])
{
    coder::array<real_T, 1U> x;
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    real_T(*f)[8];
    real_T(*p)[8];
    real_T s;
    st.tls = emlrtRootTLSGlobal;
    p = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    f = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    emlrtHeapReferenceStackEnterFcnR2012b(&st);
    // Marshall function inputs
    x.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs), "x", x);
    // Invoke the target function
    aweight(x, *p, *f, &s);
    // Marshall function outputs
    plhs[0] = emlrt_marshallOut(*p);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(*f);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(s);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray *prhs
//                int32_T nlhs
//                const mxArray *plhs[3]
// Return Type  : void
//
void cweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3])
{
    coder::array<real_T, 1U> x;
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    real_T(*f)[8];
    real_T(*p)[8];
    real_T s;
    st.tls = emlrtRootTLSGlobal;
    p = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    f = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    emlrtHeapReferenceStackEnterFcnR2012b(&st);
    // Marshall function inputs
    x.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs), "x", x);
    // Invoke the target function
    cweight(x, *p, *f, &s);
    // Marshall function outputs
    plhs[0] = emlrt_marshallOut(*p);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(*f);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(s);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void test_spl_atexit()
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
    test_spl_xil_terminate();
    test_spl_xil_shutdown();
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void test_spl_initialize()
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
void test_spl_terminate()
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
// Arguments    : const mxArray *prhs
//                int32_T nlhs
//                const mxArray *plhs[3]
// Return Type  : void
//
void zweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3])
{
    coder::array<real_T, 1U> x;
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    real_T(*f)[8];
    real_T(*p)[8];
    real_T s;
    st.tls = emlrtRootTLSGlobal;
    p = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    f = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    emlrtHeapReferenceStackEnterFcnR2012b(&st);
    // Marshall function inputs
    x.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs), "x", x);
    // Invoke the target function
    zweight(x, *p, *f, &s);
    // Marshall function outputs
    plhs[0] = emlrt_marshallOut(*p);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(*f);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(s);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// File trailer for _coder_test_spl_api.cpp
//
// [EOF]
//
