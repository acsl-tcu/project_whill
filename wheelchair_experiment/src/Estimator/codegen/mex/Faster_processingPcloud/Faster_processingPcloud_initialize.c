/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Faster_processingPcloud_initialize.c
 *
 * Code generation for function 'Faster_processingPcloud_initialize'
 *
 */

/* Include files */
#include "Faster_processingPcloud_initialize.h"
#include "Faster_processingPcloud.h"
#include "Faster_processingPcloud_data.h"
#include "_coder_Faster_processingPcloud_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void Faster_processingPcloud_once(void);

/* Function Definitions */
static void Faster_processingPcloud_once(void)
{
  mex_InitInfAndNan();
  Faster_processingPcloud_init();
}

void Faster_processingPcloud_initialize(void)
{
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
                          "image_toolbox", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "video_and_image_blockset", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    Faster_processingPcloud_once();
  }
}

/* End of code generation (Faster_processingPcloud_initialize.c) */
