/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * determine_target_location_fordemo_terminate.c
 *
 * Code generation for function 'determine_target_location_fordemo_terminate'
 *
 */

/* Include files */
#include "determine_target_location_fordemo_terminate.h"
#include "_coder_determine_target_location_fordemo_mex.h"
#include "determine_target_location_fordemo_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void determine_target_location_fordemo_atexit(void)
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

void determine_target_location_fordemo_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (determine_target_location_fordemo_terminate.c) */
