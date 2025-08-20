/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_removePlane_clustering_mex.c
 *
 * Code generation for function '_coder_removePlane_clustering_mex'
 *
 */

/* Include files */
#include "_coder_removePlane_clustering_mex.h"
#include "_coder_removePlane_clustering_api.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_initialize.h"
#include "removePlane_clustering_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&removePlane_clustering_atexit);
  /* Module initialization. */
  removePlane_clustering_initialize();
  /* Dispatch the entry-point. */
  removePlane_clustering_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  removePlane_clustering_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "Shift_JIS", true);
  return emlrtRootTLSGlobal;
}

void removePlane_clustering_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                        int32_T nrhs, const mxArray *prhs[4])
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
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        22, "removePlane_clustering");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "removePlane_clustering");
  }
  /* Call the function. */
  removePlane_clustering_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_removePlane_clustering_mex.c) */
