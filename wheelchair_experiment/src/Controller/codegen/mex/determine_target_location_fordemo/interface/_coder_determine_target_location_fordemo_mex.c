/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_determine_target_location_fordemo_mex.c
 *
 * Code generation for function '_coder_determine_target_location_fordemo_mex'
 *
 */

/* Include files */
#include "_coder_determine_target_location_fordemo_mex.h"
#include "_coder_determine_target_location_fordemo_api.h"
#include "determine_target_location_fordemo_data.h"
#include "determine_target_location_fordemo_initialize.h"
#include "determine_target_location_fordemo_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void determine_target_location_fordemo_mexFunction(int32_T nlhs,
                                                   mxArray *plhs[3],
                                                   int32_T nrhs,
                                                   const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        33, "determine_target_location_fordemo");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 33,
                        "determine_target_location_fordemo");
  }
  /* Call the function. */
  c_determine_target_location_for(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&determine_target_location_fordemo_atexit);
  /* Module initialization. */
  determine_target_location_fordemo_initialize();
  /* Dispatch the entry-point. */
  determine_target_location_fordemo_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  determine_target_location_fordemo_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_determine_target_location_fordemo_mex.c) */
