//
// File: _coder_myadd_mex.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 28-Sep-2024 21:22:24
//

// Include Files
#include "_coder_myadd_mex.h"
#include "_coder_myadd_api.h"

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
  mexAtExit(&myadd_atexit);
  myadd_initialize();
  unsafe_myadd_mexFunction(nlhs, plhs, nrhs, prhs);
  myadd_terminate();
}

//
// Arguments    : void
// Return Type  : emlrtCTX
//
emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           nullptr, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[1]
//                int32_T nrhs
//                const mxArray *prhs[2]
// Return Type  : void
//
void unsafe_myadd_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[2])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *b_prhs[2];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        5, "myadd");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "myadd");
  }
  // Call the function.
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  myadd_api(b_prhs, &outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

//
// File trailer for _coder_myadd_mex.cpp
//
// [EOF]
//
