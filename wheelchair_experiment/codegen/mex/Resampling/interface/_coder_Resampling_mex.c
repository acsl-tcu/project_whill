/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Resampling_mex.c
 *
 * Code generation for function '_coder_Resampling_mex'
 *
 */

/* Include files */
#include "Resampling.h"
#include "_coder_Resampling_mex.h"
#include "Resampling_terminate.h"
#include "_coder_Resampling_api.h"
#include "Resampling_initialize.h"
#include "Resampling_data.h"

/* Function Declarations */
static void Resampling_mexFunction(ResamplingStackData *SD, int32_T nlhs,
  mxArray *plhs[3], int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */
static void Resampling_mexFunction(ResamplingStackData *SD, int32_T nlhs,
  mxArray *plhs[3], int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        10, "Resampling");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "Resampling");
  }

  /* Call the function. */
  Resampling_api(SD, prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  ResamplingStackData *ResamplingStackDataGlobal = NULL;
  ResamplingStackDataGlobal = (ResamplingStackData *)emlrtMxCalloc(1, (size_t)1U
    * sizeof(ResamplingStackData));
  mexAtExit(Resampling_atexit);

  /* Module initialization. */
  Resampling_initialize();

  /* Dispatch the entry-point. */
  Resampling_mexFunction(ResamplingStackDataGlobal, nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Resampling_terminate();
  emlrtMxFree(ResamplingStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Resampling_mex.c) */
