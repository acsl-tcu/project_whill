//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// determine_target_location_gpu_initialize.cu
//
// Code generation for function 'determine_target_location_gpu_initialize'
//

// Include files
#include "determine_target_location_gpu_initialize.h"
#include "_coder_determine_target_location_gpu_mex.h"
#include "determine_target_location_gpu_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void determine_target_location_gpu_initialize()
{
  mex_InitInfAndNan();
  emlrtInitGPU(emlrtRootTLSGlobal);
  cudaGetLastError();
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLicenseCheckR2022a(emlrtRootTLSGlobal,
                          "EMLRT:runTime:MexFunctionNeedsLicense",
                          "distrib_computing_toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation (determine_target_location_gpu_initialize.cu)
