/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Discretemodel_mex.c
 *
 * Code generation for function '_coder_Discretemodel_mex'
 *
 */

/* Include files */
#include "Discretemodel.h"
#include "_coder_Discretemodel_mex.h"
#include "Discretemodel_terminate.h"
#include "_coder_Discretemodel_api.h"
#include "Discretemodel_initialize.h"
#include "Discretemodel_data.h"

/* Function Declarations */
static void Discretemodel_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[3]);

/* Function Definitions */
static void Discretemodel_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        13, "Discretemodel");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "Discretemodel");
  }

  /* Call the function. */
  Discretemodel_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Discretemodel_atexit);

  /* Module initialization. */
  Discretemodel_initialize();

  /* Dispatch the entry-point. */
  Discretemodel_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Discretemodel_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Discretemodel_mex.c) */
