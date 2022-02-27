//
// File: _coder_noise_segment_mex.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "_coder_noise_segment_mex.h"
#include "_coder_noise_segment_api.h"

// Function Definitions
//
// Arguments    : int32_T nlhs
//                mxArray *plhs[]
//                int32_T nrhs
//                const mxArray *prhs[]
// Return Type  : void
//
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
    static const char_T *emlrtEntryPoints[2] = {"noise_segment", "vad"};
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    mexAtExit(&noise_segment_atexit);
    // Module initialization.
    noise_segment_initialize();
    st.tls = emlrtRootTLSGlobal;
    try {
        emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);
        // Dispatch the entry-point.
        switch (emlrtGetEntryPointIndexR2016a(
            &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 2)) {
        case 0:
            unsafe_noise_segment_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 1:
            unsafe_vad_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        }
        // Module termination.
        noise_segment_terminate();
    } catch (...) {
        emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
        throw;
    }
}

//
// Arguments    : void
// Return Type  : emlrtCTX
//
emlrtCTX mexFunctionCreateRootTLS()
{
    emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                             NULL);
    return emlrtRootTLSGlobal;
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[2]
//                int32_T nrhs
//                const mxArray *prhs[5]
// Return Type  : void
//
void unsafe_noise_segment_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                      int32_T nrhs, const mxArray *prhs[5])
{
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    const mxArray *outputs[2];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;
    // Check for proper number of arguments.
    if (nrhs != 5) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5,
                            4, 13, "noise_segment");
    }
    if (nlhs > 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            13, "noise_segment");
    }
    // Call the function.
    noise_segment_api(prhs, nlhs, outputs);
    // Copy over outputs to the caller.
    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[2]
//                int32_T nrhs
//                const mxArray *prhs[2]
// Return Type  : void
//
void unsafe_vad_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                            const mxArray *prhs[2])
{
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    const mxArray *outputs[2];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;
    // Check for proper number of arguments.
    if (nrhs != 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2,
                            4, 3, "vad");
    }
    if (nlhs > 2) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            3, "vad");
    }
    // Call the function.
    vad_api(prhs, nlhs, outputs);
    // Copy over outputs to the caller.
    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

//
// File trailer for _coder_noise_segment_mex.cpp
//
// [EOF]
//
