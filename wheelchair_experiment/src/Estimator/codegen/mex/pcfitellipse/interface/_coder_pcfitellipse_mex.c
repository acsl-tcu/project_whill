/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_pcfitellipse_mex.c
 *
 * Code generation for function '_coder_pcfitellipse_mex'
 *
 */

/* Include files */
#include "_coder_pcfitellipse_mex.h"
#include "_coder_pcfitellipse_api.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_initialize.h"
#include "pcfitellipse_terminate.h"
#include "pcfitellipse_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  pcfitellipseStackData *pcfitellipseStackDataGlobal = NULL;
  pcfitellipseStackDataGlobal = (pcfitellipseStackData *)emlrtMxCalloc(
      (size_t)1, (size_t)1U * sizeof(pcfitellipseStackData));
  mexAtExit(&pcfitellipse_atexit);
  /* Module initialization. */
  pcfitellipse_initialize();
  /* Dispatch the entry-point. */
  pcfitellipse_mexFunction(pcfitellipseStackDataGlobal, nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  pcfitellipse_terminate();
  emlrtMxFree(pcfitellipseStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "Shift_JIS", true);
  return emlrtRootTLSGlobal;
}

void pcfitellipse_mexFunction(pcfitellipseStackData *SD, int32_T nlhs,
                              mxArray *plhs[5], int32_T nrhs,
                              const mxArray *prhs[19])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[5];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 19) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 19, 4,
                        12, "pcfitellipse");
  }
  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "pcfitellipse");
  }
  /* Call the function. */
  pcfitellipse_api(SD, prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_pcfitellipse_mex.c) */
