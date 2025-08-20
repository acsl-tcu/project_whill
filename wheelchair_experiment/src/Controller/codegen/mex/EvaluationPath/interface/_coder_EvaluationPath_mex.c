/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EvaluationPath_mex.c
 *
 * Code generation for function '_coder_EvaluationPath_mex'
 *
 */

/* Include files */
#include "_coder_EvaluationPath_mex.h"
#include "EvaluationPath_data.h"
#include "EvaluationPath_initialize.h"
#include "EvaluationPath_terminate.h"
#include "EvaluationPath_types.h"
#include "_coder_EvaluationPath_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void EvaluationPath_mexFunction(EvaluationPathStackData *SD, int32_T nlhs,
                                mxArray *plhs[2], int32_T nrhs,
                                const mxArray *prhs[5])
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
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        14, "EvaluationPath");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "EvaluationPath");
  }
  /* Call the function. */
  EvaluationPath_api(SD, prhs, nlhs, outputs);
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
  EvaluationPathStackData *EvaluationPathStackDataGlobal = NULL;
  EvaluationPathStackDataGlobal = (EvaluationPathStackData *)emlrtMxCalloc(
      (size_t)1, (size_t)1U * sizeof(EvaluationPathStackData));
  mexAtExit(&EvaluationPath_atexit);
  EvaluationPath_initialize();
  EvaluationPath_mexFunction(EvaluationPathStackDataGlobal, nlhs, plhs, nrhs,
                             prhs);
  EvaluationPath_terminate();
  emlrtMxFree(EvaluationPathStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_EvaluationPath_mex.c) */
