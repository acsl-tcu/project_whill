/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removePlane_BBox_terminate.c
 *
 * Code generation for function 'removePlane_BBox_terminate'
 *
 */

/* Include files */
#include "removePlane_BBox_terminate.h"
#include "_coder_removePlane_BBox_mex.h"
#include "removePlane_BBox_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void removePlane_BBox_atexit(void)
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

void removePlane_BBox_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (removePlane_BBox_terminate.c) */
