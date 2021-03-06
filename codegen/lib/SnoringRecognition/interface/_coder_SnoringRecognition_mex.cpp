#include "_coder_SnoringRecognition_mex.h"
#include "_coder_SnoringRecognition_api.h"

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
    static const char_T *emlrtEntryPoints[15] = {
        "aweight",       "bark_feat",
        "cep_feat",      "classifier",
        "cweight",       "fmt_feat",
        "gtcc_feat",     "mfcc_feat",
        "noise_segment", "patient_classifier",
        "pitch_feat",    "pr800_feat",
        "se_feat",       "vad",
        "zweight"};
    emlrtStack st = {NULL, NULL, NULL};
    mexAtExit(&SnoringRecognition_atexit);

    SnoringRecognition_initialize();
    st.tls = emlrtRootTLSGlobal;
    try {
        emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);

        switch (emlrtGetEntryPointIndexR2016a(
            &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 15)) {
        case 0:
            unsafe_aweight_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 1:
            unsafe_bark_feat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 2:
            unsafe_cep_feat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 3:
            unsafe_classifier_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 4:
            unsafe_cweight_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 5:
            unsafe_fmt_feat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 6:
            unsafe_gtcc_feat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 7:
            unsafe_mfcc_feat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 8:
            unsafe_noise_segment_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 9:
            unsafe_patient_classifier_mexFunction(nlhs, plhs, nrhs - 1,
                                                  &prhs[1]);
            break;
        case 10:
            unsafe_pitch_feat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 11:
            unsafe_pr800_feat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 12:
            unsafe_se_feat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 13:
            unsafe_vad_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 14:
            unsafe_zweight_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        }

        SnoringRecognition_terminate();
    } catch (...) {
        emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
        throw;
    }
}

emlrtCTX mexFunctionCreateRootTLS()
{
    emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                             NULL);
    return emlrtRootTLSGlobal;
}

void unsafe_aweight_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                const mxArray *prhs[1])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs[3];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1,
                            4, 7, "aweight");
    }
    if (nlhs > 3) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            7, "aweight");
    }

    aweight_api(prhs[0], nlhs, outputs);

    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void unsafe_bark_feat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[2])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 9, "bark_feat");
    }
    if (nlhs > 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            9, "bark_feat");
    }

    bark_feat_api(prhs, &outputs);

    emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_cep_feat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                 const mxArray *prhs[2])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 8, "cep_feat");
    }
    if (nlhs > 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            8, "cep_feat");
    }

    cep_feat_api(prhs, &outputs);

    emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_classifier_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                   const mxArray *prhs[4])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 4) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4,
                            4, 10, "classifier");
    }
    if (nlhs > 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            10, "classifier");
    }

    classifier_api(prhs, &outputs);

    emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_cweight_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                const mxArray *prhs[1])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs[3];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1,
                            4, 7, "cweight");
    }
    if (nlhs > 3) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            7, "cweight");
    }

    cweight_api(prhs[0], nlhs, outputs);

    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void unsafe_fmt_feat_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                 const mxArray *prhs[2])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs[3];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 8, "fmt_feat");
    }
    if (nlhs > 3) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            8, "fmt_feat");
    }

    fmt_feat_api(prhs, nlhs, outputs);

    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void unsafe_gtcc_feat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[2])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 9, "gtcc_feat");
    }
    if (nlhs > 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            9, "gtcc_feat");
    }

    gtcc_feat_api(prhs, &outputs);

    emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_mfcc_feat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[2])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 9, "mfcc_feat");
    }
    if (nlhs > 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            9, "mfcc_feat");
    }

    mfcc_feat_api(prhs, &outputs);

    emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_noise_segment_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                      int32_T nrhs, const mxArray *prhs[5])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs[2];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 5) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5,
                            4, 13, "noise_segment");
    }
    if (nlhs > 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            13, "noise_segment");
    }

    noise_segment_api(prhs, nlhs, outputs);

    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void unsafe_patient_classifier_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs,
                                           const mxArray *prhs[19])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 19) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 19,
                            4, 18, "patient_classifier");
    }
    if (nlhs > 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            18, "patient_classifier");
    }

    patient_classifier_api(prhs, &outputs);

    emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_pitch_feat_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
                                   const mxArray *prhs[2])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs[4];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 10, "pitch_feat");
    }
    if (nlhs > 4) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            10, "pitch_feat");
    }

    pitch_feat_api(prhs, nlhs, outputs);

    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void unsafe_pr800_feat_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
                                   const mxArray *prhs[2])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs[4];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 10, "pr800_feat");
    }
    if (nlhs > 4) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            10, "pr800_feat");
    }

    pr800_feat_api(prhs, nlhs, outputs);

    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void unsafe_se_feat_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
                                const mxArray *prhs[2])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs[4];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 7, "se_feat");
    }
    if (nlhs > 4) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            7, "se_feat");
    }

    se_feat_api(prhs, nlhs, outputs);

    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void unsafe_vad_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                            const mxArray *prhs[2])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs[2];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 3, "vad");
    }
    if (nlhs > 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            3, "vad");
    }

    vad_api(prhs, nlhs, outputs);

    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void unsafe_zweight_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                const mxArray *prhs[1])
{
    emlrtStack st = {NULL, NULL, NULL};
    const mxArray *outputs[3];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;

    if (nrhs != 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1,
                            4, 7, "zweight");
    }
    if (nlhs > 3) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            7, "zweight");
    }

    zweight_api(prhs[0], nlhs, outputs);

    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}
