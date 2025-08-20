//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// EvaluationPath_GPU_initialize.cu
//
// Code generation for function 'EvaluationPath_GPU_initialize'
//

// Include files
#include "EvaluationPath_GPU_initialize.h"
#include "EvaluationPath_GPU_data.h"
#include "_coder_EvaluationPath_GPU_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void EvaluationPath_GPU_initialize()
{
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLicenseCheckR2012b(emlrtRootTLSGlobal,
                          (const char_T *)"distrib_computing_toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
  cudaGetLastError();
}

// End of code generation (EvaluationPath_GPU_initialize.cu)
