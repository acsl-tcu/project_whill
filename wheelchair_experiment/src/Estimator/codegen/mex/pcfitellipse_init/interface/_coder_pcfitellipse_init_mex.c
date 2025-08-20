/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_pcfitellipse_init_mex.c
 *
 * Code generation for function '_coder_pcfitellipse_init_mex'
 *
 */

/* Include files */
#include "_coder_pcfitellipse_init_mex.h"
#include "_coder_pcfitellipse_init_api.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_initialize.h"
#include "pcfitellipse_init_terminate.h"
#include "pcfitellipse_init_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  pcfitellipse_initStackData *c_pcfitellipse_initStackDataGlo = NULL;
  c_pcfitellipse_initStackDataGlo = (pcfitellipse_initStackData *)emlrtMxCalloc(
      (size_t)1, (size_t)1U * sizeof(pcfitellipse_initStackData));
  mexAtExit(&pcfitellipse_init_atexit);
  /* Module initialization. */
  pcfitellipse_init_initialize();
  /* Dispatch the entry-point. */
  pcfitellipse_init_mexFunction(c_pcfitellipse_initStackDataGlo, nlhs, plhs,
                                nrhs, prhs);
  /* Module termination. */
  pcfitellipse_init_terminate();
  emlrtMxFree(c_pcfitellipse_initStackDataGlo);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "Shift_JIS", true);
  return emlrtRootTLSGlobal;
}

void pcfitellipse_init_mexFunction(pcfitellipse_initStackData *SD, int32_T nlhs,
                                   mxArray *plhs[2], int32_T nrhs,
                                   const mxArray *prhs[13])
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
  if (nrhs != 13) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 13, 4,
                        17, "pcfitellipse_init");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "pcfitellipse_init");
  }
  /* Call the function. */
  pcfitellipse_init_api(SD, prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_pcfitellipse_init_mex.c) */
