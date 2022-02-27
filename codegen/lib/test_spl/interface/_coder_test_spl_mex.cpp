//
// File: _coder_test_spl_mex.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 22:09:11
//

// Include Files
#include "_coder_test_spl_mex.h"
#include "_coder_test_spl_api.h"

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
    static const char_T *emlrtEntryPoints[3] = {"aweight", "cweight",
                                                "zweight"};
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    mexAtExit(&test_spl_atexit);
    // Module initialization.
    test_spl_initialize();
    st.tls = emlrtRootTLSGlobal;
    try {
        emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);
        // Dispatch the entry-point.
        switch (emlrtGetEntryPointIndexR2016a(
            &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 3)) {
        case 0:
            unsafe_aweight_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 1:
            unsafe_cweight_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        case 2:
            unsafe_zweight_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
            break;
        }
        // Module termination.
        test_spl_terminate();
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
//                mxArray *plhs[3]
//                int32_T nrhs
//                const mxArray *prhs[1]
// Return Type  : void
//
void unsafe_aweight_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                const mxArray *prhs[1])
{
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    const mxArray *outputs[3];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;
    // Check for proper number of arguments.
    if (nrhs != 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1,
                            4, 7, "aweight");
    }
    if (nlhs > 3) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            7, "aweight");
    }
    // Call the function.
    aweight_api(prhs[0], nlhs, outputs);
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
//                mxArray *plhs[3]
//                int32_T nrhs
//                const mxArray *prhs[1]
// Return Type  : void
//
void unsafe_cweight_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                const mxArray *prhs[1])
{
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    const mxArray *outputs[3];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;
    // Check for proper number of arguments.
    if (nrhs != 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1,
                            4, 7, "cweight");
    }
    if (nlhs > 3) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            7, "cweight");
    }
    // Call the function.
    cweight_api(prhs[0], nlhs, outputs);
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
//                mxArray *plhs[3]
//                int32_T nrhs
//                const mxArray *prhs[1]
// Return Type  : void
//
void unsafe_zweight_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                const mxArray *prhs[1])
{
    emlrtStack st = {
        NULL, // site
        NULL, // tls
        NULL  // prev
    };
    const mxArray *outputs[3];
    int32_T b_nlhs;
    st.tls = emlrtRootTLSGlobal;
    // Check for proper number of arguments.
    if (nrhs != 1) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1,
                            4, 7, "zweight");
    }
    if (nlhs > 3) {
        emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4,
                            7, "zweight");
    }
    // Call the function.
    zweight_api(prhs[0], nlhs, outputs);
    // Copy over outputs to the caller.
    if (nlhs < 1) {
        b_nlhs = 1;
    } else {
        b_nlhs = nlhs;
    }
    emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

//
// File trailer for _coder_test_spl_mex.cpp
//
// [EOF]
//
