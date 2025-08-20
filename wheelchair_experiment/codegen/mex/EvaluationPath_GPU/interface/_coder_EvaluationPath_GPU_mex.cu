//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_EvaluationPath_GPU_mex.cu
//
// Code generation for function '_coder_EvaluationPath_GPU_mex'
//

// Include files
#include "_coder_EvaluationPath_GPU_mex.h"
#include "EvaluationPath_GPU_data.h"
#include "EvaluationPath_GPU_initialize.h"
#include "EvaluationPath_GPU_terminate.h"
#include "EvaluationPath_GPU_types.h"
#include "_coder_EvaluationPath_GPU_api.h"
#include "rt_nonfinite.h"

// Function Definitions
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  EvaluationPath_GPUStackData *c_EvaluationPath_GPUStackDataGl{nullptr};
  c_EvaluationPath_GPUStackDataGl = new EvaluationPath_GPUStackData;
  mexAtExit(&EvaluationPath_GPU_atexit);
  // Module initialization.
  EvaluationPath_GPU_initialize();
  // Dispatch the entry-point.
  unsafe_EvaluationPath_GPU_mexFunction(c_EvaluationPath_GPUStackDataGl, nlhs,
                                        plhs, nrhs, prhs);
  // Module termination.
  EvaluationPath_GPU_terminate();
  delete c_EvaluationPath_GPUStackDataGl;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           nullptr);
  return emlrtRootTLSGlobal;
}

void unsafe_EvaluationPath_GPU_mexFunction(EvaluationPath_GPUStackData *SD,
                                           int32_T nlhs, mxArray *plhs[2],
                                           int32_T nrhs, const mxArray *prhs[4])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  // Check for proper number of arguments.
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 4, 4, 18, "EvaluationPath_GPU");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "EvaluationPath_GPU");
  }
  // Call the function.
  b_EvaluationPath_GPU_api(SD, prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

// End of code generation (_coder_EvaluationPath_GPU_mex.cu)
