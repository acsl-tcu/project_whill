/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mexLidarTracker_mex.c
 *
 * Code generation for function '_coder_mexLidarTracker_mex'
 *
 */

/* Include files */
#include "_coder_mexLidarTracker_mex.h"
#include "_coder_mexLidarTracker_api.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_initialize.h"
#include "mexLidarTracker_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&mexLidarTracker_atexit);
  /* Module initialization. */
  mexLidarTracker_initialize();
  /* Dispatch the entry-point. */
  mexLidarTracker_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  mexLidarTracker_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

void mexLidarTracker_mexFunction(int32_T nlhs, mxArray *plhs[7], int32_T nrhs,
                                 const mxArray *prhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[7];
  const mxArray *b_prhs[6];
  int32_T i;
  int32_T i1;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        15, "mexLidarTracker");
  }
  if (nlhs > 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "mexLidarTracker");
  }
  /* Call the function. */
  for (i = 0; i < 6; i++) {
    b_prhs[i] = prhs[i];
  }
  mexLidarTracker_api(b_prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i1 = 1;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_mexLidarTracker_mex.c) */
