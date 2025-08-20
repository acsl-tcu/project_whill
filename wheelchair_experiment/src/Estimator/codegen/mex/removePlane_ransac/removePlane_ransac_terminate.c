/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removePlane_ransac_terminate.c
 *
 * Code generation for function 'removePlane_ransac_terminate'
 *
 */

/* Include files */
#include "removePlane_ransac_terminate.h"
#include "_coder_removePlane_ransac_mex.h"
#include "removePlane_ransac_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void removePlane_ransac_atexit(void)
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

void removePlane_ransac_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (removePlane_ransac_terminate.c) */
