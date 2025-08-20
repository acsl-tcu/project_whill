/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse_init_terminate.c
 *
 * Code generation for function 'pcfitellipse_init_terminate'
 *
 */

/* Include files */
#include "pcfitellipse_init_terminate.h"
#include "_coder_pcfitellipse_init_mex.h"
#include "pcfitellipse_init_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void pcfitellipse_init_atexit(void)
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

void pcfitellipse_init_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (pcfitellipse_init_terminate.c) */
