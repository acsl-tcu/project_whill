/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removeleg_initialize.c
 *
 * Code generation for function 'removeleg_initialize'
 *
 */

/* Include files */
#include "removeleg_initialize.h"
#include "_coder_removeleg_mex.h"
#include "removeleg_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void removeleg_once(void);

/* Function Definitions */
static void removeleg_once(void)
{
  mex_InitInfAndNan();
}

void removeleg_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    removeleg_once();
  }
}

/* End of code generation (removeleg_initialize.c) */
