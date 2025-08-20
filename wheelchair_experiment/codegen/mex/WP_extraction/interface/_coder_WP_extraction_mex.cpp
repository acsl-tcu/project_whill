//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_WP_extraction_mex.cpp
//
// Code generation for function '_coder_WP_extraction_mex'
//

// Include files
#include "_coder_WP_extraction_mex.h"
#include "WP_extraction_data.h"
#include "WP_extraction_initialize.h"
#include "WP_extraction_terminate.h"
#include "WP_extraction_types.h"
#include "_coder_WP_extraction_api.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void WP_extraction_mexFunction(WP_extractionStackData *SD, int32_T nlhs,
                               mxArray *plhs[1], int32_T nrhs,
                               const mxArray *prhs[4])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        13, "WP_extraction");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "WP_extraction");
  }
  // Call the function.
  b_WP_extraction_api(SD, prhs, &outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  WP_extractionStackData *WP_extractionStackDataGlobal{nullptr};
  WP_extractionStackDataGlobal = new WP_extractionStackData;
  mexAtExit(&WP_extraction_atexit);
  // Module initialization.
  WP_extraction_initialize();
  try {
    emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);
    // Dispatch the entry-point.
    WP_extraction_mexFunction(WP_extractionStackDataGlobal, nlhs, plhs, nrhs,
                              prhs);
    // Module termination.
    WP_extraction_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
  delete WP_extractionStackDataGlobal;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_WP_extraction_mex.cpp)
