/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removeleg_terminate.c
 *
 * Code generation for function 'removeleg_terminate'
 *
 */

/* Include files */
#include "removeleg_terminate.h"
#include "_coder_removeleg_mex.h"
#include "removeleg_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void removeleg_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void removeleg_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (removeleg_terminate.c) */
