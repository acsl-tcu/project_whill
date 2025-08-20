/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_removePlane_BBox_mex.c
 *
 * Code generation for function '_coder_removePlane_BBox_mex'
 *
 */

/* Include files */
#include "_coder_removePlane_BBox_mex.h"
#include "_coder_removePlane_BBox_api.h"
#include "removePlane_BBox_data.h"
#include "removePlane_BBox_initialize.h"
#include "removePlane_BBox_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&removePlane_BBox_atexit);
  /* Module initialization. */
  removePlane_BBox_initialize();
  /* Dispatch the entry-point. */
  removePlane_BBox_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  removePlane_BBox_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "Shift_JIS", true);
  return emlrtRootTLSGlobal;
}

void removePlane_BBox_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                                  const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        16, "removePlane_BBox");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "removePlane_BBox");
  }
  /* Call the function. */
  removePlane_BBox_api(prhs[0], nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_removePlane_BBox_mex.c) */
