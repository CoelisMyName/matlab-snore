#include "_coder_SnoringRecognition_api.h"
#include "_coder_SnoringRecognition_mex.h"
#include "coder_array_mex.h"

emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,
    false,
    131610U,
    NULL,
    "SnoringRecognition",
    NULL,
    false,
    {2045744189U, 2170104910U, 2743257031U, 4284093946U},
    NULL};

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<int64_T, 1U> &ret);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *BARKEE,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret);

static const mxArray *b_emlrt_marshallOut(const real_T u[17]);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *GTCCmean,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *w_starts,
                             const char_T *identifier,
                             coder::array<int64_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int64_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *MFCC_feature,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

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

static const mxArray *emlrt_marshallOut(const real_T u_data[],
                                        const int32_T u_size[2]);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const coder::array<int64_T, 1U> &u);

static const mxArray *emlrt_marshallOut(const real_T u[8]);

static const mxArray *emlrt_marshallOut(const real_T u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

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

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
    e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *BARKEE,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = const_cast<const char_T *>(identifier);
    thisId.fParent = NULL;
    thisId.bParentIsCell = false;
    b_emlrt_marshallIn(sp, emlrtAlias(BARKEE), &thisId, y);
    emlrtDestroyArray(&BARKEE);
}

static const mxArray *b_emlrt_marshallOut(const real_T u[17])
{
    static const int32_T iv[2] = {0, 0};
    static const int32_T iv1[2] = {1, 17};
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

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
    f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *GTCCmean,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = const_cast<const char_T *>(identifier);
    thisId.fParent = NULL;
    thisId.bParentIsCell = false;
    c_emlrt_marshallIn(sp, emlrtAlias(GTCCmean), &thisId, y);
    emlrtDestroyArray(&GTCCmean);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
    static const int32_T dims[2] = {-1, 39};
    int32_T iv[2];
    const boolean_T bv[2] = {true, false};
    emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src,
                              (const char_T *)"double", false, 2U,
                              (void *)&dims[0], &bv[0], &iv[0]);
    ret.prealloc(iv[0] * iv[1]);
    ret.set_size(iv[0], iv[1]);
    ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1));
    emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
    static const int32_T dims[2] = {-1, 17};
    int32_T iv[2];
    const boolean_T bv[2] = {true, false};
    emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src,
                              (const char_T *)"double", false, 2U,
                              (void *)&dims[0], &bv[0], &iv[0]);
    ret.prealloc(iv[0] * iv[1]);
    ret.set_size(iv[0], iv[1]);
    ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1));
    emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
    d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

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

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int64_T, 1U> &y)
{
    b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *MFCC_feature,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = const_cast<const char_T *>(identifier);
    thisId.fParent = NULL;
    thisId.bParentIsCell = false;
    emlrt_marshallIn(sp, emlrtAlias(MFCC_feature), &thisId, y);
    emlrtDestroyArray(&MFCC_feature);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y)
{
    b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

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

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
    real_T y;
    y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

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

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
    static const int32_T i = 0;
    const mxArray *m;
    const mxArray *y;
    y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
    emlrtMxSetData((mxArray *)m,
                   &(((coder::array<real_T, 1U> *)&u)->data())[0]);
    emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 1U> *)&u)->size(),
                       1);
    emlrtAssign(&y, m);
    return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
    static const int32_T iv[2] = {0, 0};
    const mxArray *m;
    const mxArray *y;
    y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS,
                                mxREAL);
    emlrtMxSetData((mxArray *)m,
                   &(((coder::array<real_T, 2U> *)&u)->data())[0]);
    emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(),
                       2);
    emlrtAssign(&y, m);
    return y;
}

static const mxArray *emlrt_marshallOut(const real_T u_data[],
                                        const int32_T u_size[2])
{
    static const int32_T iv[2] = {0, 0};
    const mxArray *m;
    const mxArray *y;
    y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS,
                                mxREAL);
    emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
    emlrtSetDimensions((mxArray *)m, &u_size[0], 2);
    emlrtAssign(&y, m);
    return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
    const mxArray *m;
    const mxArray *y;
    y = NULL;
    m = emlrtCreateDoubleScalar(u);
    emlrtAssign(&y, m);
    return y;
}

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

static const mxArray *emlrt_marshallOut(const coder::array<int64_T, 1U> &u)
{
    static const int32_T i = 0;
    const mxArray *m;
    const mxArray *y;
    y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i, mxINT64_CLASS, mxREAL);
    emlrtMxSetData((mxArray *)m,
                   &(((coder::array<int64_T, 1U> *)&u)->data())[0]);
    emlrtSetDimensions((mxArray *)m, ((coder::array<int64_T, 1U> *)&u)->size(),
                       1);
    emlrtAssign(&y, m);
    return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
    static const int32_T dims[2] = {-1, 20};
    int32_T iv[2];
    const boolean_T bv[2] = {true, false};
    emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src,
                              (const char_T *)"double", false, 2U,
                              (void *)&dims[0], &bv[0], &iv[0]);
    ret.prealloc(iv[0] * iv[1]);
    ret.set_size(iv[0], iv[1]);
    ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1));
    emlrtDestroyArray(&src);
}

void SnoringRecognition_atexit()
{
    emlrtStack st = {NULL, NULL, NULL};
    mexFunctionCreateRootTLS();
    st.tls = emlrtRootTLSGlobal;
    emlrtEnterRtStackR2012b(&st);
    emlrtLeaveRtStackR2012b(&st);
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    SnoringRecognition_xil_terminate();
    SnoringRecognition_xil_shutdown();
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void SnoringRecognition_initialize()
{
    emlrtStack st = {NULL, NULL, NULL};
    mexFunctionCreateRootTLS();
    st.tls = emlrtRootTLSGlobal;
    emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
    emlrtEnterRtStackR2012b(&st);
    emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void SnoringRecognition_terminate()
{
    emlrtStack st = {NULL, NULL, NULL};
    st.tls = emlrtRootTLSGlobal;
    emlrtLeaveRtStackR2012b(&st);
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void aweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3])
{
    coder::array<real_T, 1U> x;
    emlrtStack st = {NULL, NULL, NULL};
    real_T(*f)[8];
    real_T(*p)[8];
    real_T s;
    st.tls = emlrtRootTLSGlobal;
    p = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    f = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    x.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs), "x", x);

    aweight(x, *p, *f, &s);

    plhs[0] = emlrt_marshallOut(*p);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(*f);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(s);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void bark_feat_api(const mxArray *const prhs[2], const mxArray **plhs)
{
    coder::array<real_T, 1U> sig;
    emlrtStack st = {NULL, NULL, NULL};
    real_T(*barkee)[17];
    real_T fs;
    st.tls = emlrtRootTLSGlobal;
    barkee = (real_T(*)[17])mxMalloc(sizeof(real_T[17]));
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    sig.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "sig", sig);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");

    bark_feat(sig, fs, *barkee);

    *plhs = b_emlrt_marshallOut(*barkee);
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void cep_feat_api(const mxArray *const prhs[2], const mxArray **plhs)
{
    coder::array<real_T, 1U> sig;
    emlrtStack st = {NULL, NULL, NULL};
    real_T(*cep_data)[39];
    real_T fs;
    int32_T cep_size[2];
    st.tls = emlrtRootTLSGlobal;
    cep_data = (real_T(*)[39])mxMalloc(sizeof(real_T[39]));
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    sig.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "sig", sig);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");

    cep_feat(sig, fs, *cep_data, cep_size);

    *plhs = emlrt_marshallOut(*cep_data, cep_size);
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void classifier_api(const mxArray *const prhs[4], const mxArray **plhs)
{
    coder::array<int64_T, 1U> w_ends;
    coder::array<int64_T, 1U> w_starts;
    coder::array<real_T, 1U> predict_label;
    coder::array<real_T, 1U> x;
    emlrtStack st = {NULL, NULL, NULL};
    real_T fs;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    x.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x", x);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");
    w_starts.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "w_starts", w_starts);
    w_ends.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "w_ends", w_ends);

    classifier(x, fs, w_starts, w_ends, predict_label);

    predict_label.no_free();
    *plhs = emlrt_marshallOut(predict_label);
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void cweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3])
{
    coder::array<real_T, 1U> x;
    emlrtStack st = {NULL, NULL, NULL};
    real_T(*f)[8];
    real_T(*p)[8];
    real_T s;
    st.tls = emlrtRootTLSGlobal;
    p = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    f = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    x.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs), "x", x);

    cweight(x, *p, *f, &s);

    plhs[0] = emlrt_marshallOut(*p);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(*f);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(s);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void fmt_feat_api(const mxArray *const prhs[2], int32_T nlhs,
                  const mxArray *plhs[3])
{
    coder::array<real_T, 1U> sig;
    emlrtStack st = {NULL, NULL, NULL};
    real_T Formant1;
    real_T Formant2;
    real_T Formant3;
    real_T fs;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    sig.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "sig", sig);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");

    fmt_feat(sig, fs, &Formant1, &Formant2, &Formant3);

    plhs[0] = emlrt_marshallOut(Formant1);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(Formant2);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(Formant3);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void gtcc_feat_api(const mxArray *const prhs[2], const mxArray **plhs)
{
    coder::array<real_T, 2U> GTCCmean;
    coder::array<real_T, 1U> sig;
    emlrtStack st = {NULL, NULL, NULL};
    real_T fs;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    sig.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "sig", sig);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");

    gtcc_feat(sig, fs, GTCCmean);

    GTCCmean.no_free();
    *plhs = emlrt_marshallOut(GTCCmean);
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void mfcc_feat_api(const mxArray *const prhs[2], const mxArray **plhs)
{
    coder::array<real_T, 2U> MFCC_feature;
    coder::array<real_T, 1U> sig;
    emlrtStack st = {NULL, NULL, NULL};
    real_T fs;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    sig.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "sig", sig);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");

    mfcc_feat(sig, fs, MFCC_feature);

    MFCC_feature.no_free();
    *plhs = emlrt_marshallOut(MFCC_feature);
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void noise_segment_api(const mxArray *const prhs[5], int32_T nlhs,
                       const mxArray *plhs[2])
{
    coder::array<int64_T, 1U> ends;
    coder::array<int64_T, 1U> starts;
    emlrtStack st = {NULL, NULL, NULL};
    real_T fs;
    real_T margin;
    real_T min_gap;
    real_T olength;
    real_T ostart;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    starts.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "starts", starts);
    ends.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "ends", ends);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "fs");
    min_gap = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "min_gap");
    margin = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "margin");

    noise_segment(starts, ends, fs, min_gap, margin, &ostart, &olength);

    plhs[0] = emlrt_marshallOut(ostart);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(olength);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void patient_classifier_api(const mxArray *const prhs[19], const mxArray **plhs)
{
    coder::array<real_T, 2U> BARKEE;
    coder::array<real_T, 2U> GTCCmean;
    coder::array<real_T, 2U> MFCC_feature;
    coder::array<real_T, 2U> cep;
    coder::array<real_T, 1U> Formant1;
    coder::array<real_T, 1U> Formant2;
    coder::array<real_T, 1U> Formant3;
    coder::array<real_T, 1U> PR800max;
    coder::array<real_T, 1U> PR800mean;
    coder::array<real_T, 1U> PR800min;
    coder::array<real_T, 1U> PR800var;
    coder::array<real_T, 1U> SE_max;
    coder::array<real_T, 1U> SE_mean;
    coder::array<real_T, 1U> SE_min;
    coder::array<real_T, 1U> SE_var;
    coder::array<real_T, 1U> period_max;
    coder::array<real_T, 1U> period_mean;
    coder::array<real_T, 1U> period_min;
    coder::array<real_T, 1U> period_var;
    emlrtStack st = {NULL, NULL, NULL};
    real_T label_OSA;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    MFCC_feature.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "MFCC_feature", MFCC_feature);
    BARKEE.no_free();
    b_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "BARKEE", BARKEE);
    period_mean.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "period_mean", period_mean);
    period_max.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "period_max", period_max);
    period_min.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "period_min", period_min);
    period_var.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "period_var", period_var);
    cep.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "cep", cep);
    Formant1.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "Formant1", Formant1);
    Formant2.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "Formant2", Formant2);
    Formant3.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "Formant3", Formant3);
    GTCCmean.no_free();
    c_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "GTCCmean", GTCCmean);
    PR800mean.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "PR800mean", PR800mean);
    PR800max.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "PR800max", PR800max);
    PR800min.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "PR800min", PR800min);
    PR800var.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "PR800var", PR800var);
    SE_mean.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[15]), "SE_mean", SE_mean);
    SE_max.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[16]), "SE_max", SE_max);
    SE_min.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[17]), "SE_min", SE_min);
    SE_var.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[18]), "SE_var", SE_var);

    label_OSA = patient_classifier(
        MFCC_feature, BARKEE, period_mean, period_max, period_min, period_var,
        cep, Formant1, Formant2, Formant3, GTCCmean, PR800mean, PR800max,
        PR800min, PR800var, SE_mean, SE_max, SE_min, SE_var);

    *plhs = emlrt_marshallOut(label_OSA);
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void pitch_feat_api(const mxArray *const prhs[2], int32_T nlhs,
                    const mxArray *plhs[4])
{
    coder::array<real_T, 1U> sig;
    emlrtStack st = {NULL, NULL, NULL};
    real_T fs;
    real_T period_max;
    real_T period_mean;
    real_T period_min;
    real_T period_var;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    sig.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "sig", sig);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");

    pitch_feat(sig, fs, &period_mean, &period_max, &period_min, &period_var);

    plhs[0] = emlrt_marshallOut(period_mean);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(period_max);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(period_min);
    }
    if (nlhs > 3) {
        plhs[3] = emlrt_marshallOut(period_var);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void pr800_feat_api(const mxArray *const prhs[2], int32_T nlhs,
                    const mxArray *plhs[4])
{
    coder::array<real_T, 1U> sig;
    emlrtStack st = {NULL, NULL, NULL};
    real_T PR800_max;
    real_T PR800_mean;
    real_T PR800_min;
    real_T PR800_var;
    real_T fs;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    sig.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "sig", sig);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");

    pr800_feat(sig, fs, &PR800_mean, &PR800_max, &PR800_min, &PR800_var);

    plhs[0] = emlrt_marshallOut(PR800_mean);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(PR800_max);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(PR800_min);
    }
    if (nlhs > 3) {
        plhs[3] = emlrt_marshallOut(PR800_var);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void se_feat_api(const mxArray *const prhs[2], int32_T nlhs,
                 const mxArray *plhs[4])
{
    coder::array<real_T, 1U> sig;
    emlrtStack st = {NULL, NULL, NULL};
    real_T SE_max;
    real_T SE_mean;
    real_T SE_min;
    real_T SE_var;
    real_T fs;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    sig.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "sig", sig);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");

    se_feat(sig, fs, &SE_mean, &SE_max, &SE_min, &SE_var);

    plhs[0] = emlrt_marshallOut(SE_mean);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(SE_max);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(SE_min);
    }
    if (nlhs > 3) {
        plhs[3] = emlrt_marshallOut(SE_var);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void vad_api(const mxArray *const prhs[2], int32_T nlhs, const mxArray *plhs[2])
{
    coder::array<int64_T, 1U> w_ends;
    coder::array<int64_T, 1U> w_starts;
    coder::array<real_T, 1U> x;
    emlrtStack st = {NULL, NULL, NULL};
    real_T fs;
    st.tls = emlrtRootTLSGlobal;
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    x.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x", x);
    fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");

    vad(x, fs, w_starts, w_ends);

    w_starts.no_free();
    plhs[0] = emlrt_marshallOut(w_starts);
    if (nlhs > 1) {
        w_ends.no_free();
        plhs[1] = emlrt_marshallOut(w_ends);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void zweight_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3])
{
    coder::array<real_T, 1U> x;
    emlrtStack st = {NULL, NULL, NULL};
    real_T(*f)[8];
    real_T(*p)[8];
    real_T s;
    st.tls = emlrtRootTLSGlobal;
    p = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    f = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
    emlrtHeapReferenceStackEnterFcnR2012b(&st);

    x.no_free();
    emlrt_marshallIn(&st, emlrtAlias(prhs), "x", x);

    zweight(x, *p, *f, &s);

    plhs[0] = emlrt_marshallOut(*p);
    if (nlhs > 1) {
        plhs[1] = emlrt_marshallOut(*f);
    }
    if (nlhs > 2) {
        plhs[2] = emlrt_marshallOut(s);
    }
    emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}
