//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_determine_target_location_gpu_mex.cu
//
// Code generation for function '_coder_determine_target_location_gpu_mex'
//

// Include files
#include "_coder_determine_target_location_gpu_mex.h"
#include "_coder_determine_target_location_gpu_api.h"
#include "determine_target_location_gpu_data.h"
#include "determine_target_location_gpu_initialize.h"
#include "determine_target_location_gpu_terminate.h"
#include "determine_target_location_gpu_types.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  d_determine_target_location_gpu *n_determine_target_location_gpu{nullptr};
  n_determine_target_location_gpu =
      static_cast<d_determine_target_location_gpu *>(
          new d_determine_target_location_gpu);
  mexAtExit(&determine_target_location_gpu_atexit);
  determine_target_location_gpu_initialize();
  try {
    unsafe_determine_target_location_gpu_mexFunction(
        n_determine_target_location_gpu, nlhs, plhs, nrhs, prhs);
    determine_target_location_gpu_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
  delete n_determine_target_location_gpu;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

void unsafe_determine_target_location_gpu_mexFunction(
    d_determine_target_location_gpu *SD, int32_T nlhs, mxArray *plhs[1],
    int32_T nrhs, const mxArray *prhs[2])
{
  const mxArray *outputs[1];
  // Check for proper number of arguments.
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 2, 4, 29, "determine_target_location_gpu");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 29,
                        "determine_target_location_gpu");
  }
  // Call the function.
  e_determine_target_location_gpu(SD, prhs, outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs[0]);
}

// End of code generation (_coder_determine_target_location_gpu_mex.cu)
