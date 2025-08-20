/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse_initialize.c
 *
 * Code generation for function 'pcfitellipse_initialize'
 *
 */

/* Include files */
#include "pcfitellipse_initialize.h"
#include "_coder_pcfitellipse_mex.h"
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void pcfitellipse_once(void);

/* Function Definitions */
static void pcfitellipse_once(void)
{
  mex_InitInfAndNan();
}

void pcfitellipse_initialize(void)
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
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "optimization_toolbox", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "video_and_image_blockset", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    pcfitellipse_once();
  }
}

/* End of code generation (pcfitellipse_initialize.c) */
