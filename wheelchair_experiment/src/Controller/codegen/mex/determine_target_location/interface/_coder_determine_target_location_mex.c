/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_determine_target_location_mex.c
 *
 * Code generation for function '_coder_determine_target_location_mex'
 *
 */

/* Include files */
#include "_coder_determine_target_location_mex.h"
#include "_coder_determine_target_location_api.h"
#include "determine_target_location_data.h"
#include "determine_target_location_initialize.h"
#include "determine_target_location_terminate.h"
#include "determine_target_location_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void determine_target_location_mexFunction(c_determine_target_locationStac *SD,
                                           int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        25, "determine_target_location");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 25,
                        "determine_target_location");
  }
  /* Call the function. */
  determine_target_location_api(SD, prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  c_determine_target_locationStac *d_determine_target_locationStac = NULL;
  d_determine_target_locationStac =
      (c_determine_target_locationStac *)emlrtMxCalloc(
          (size_t)1, (size_t)1U * sizeof(c_determine_target_locationStac));
  mexAtExit(&determine_target_location_atexit);
  determine_target_location_initialize();
  determine_target_location_mexFunction(d_determine_target_locationStac, nlhs,
                                        plhs, nrhs, prhs);
  determine_target_location_terminate();
  emlrtMxFree(d_determine_target_locationStac);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_determine_target_location_mex.c) */
