/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removePlane_BBox_initialize.c
 *
 * Code generation for function 'removePlane_BBox_initialize'
 *
 */

/* Include files */
#include "removePlane_BBox_initialize.h"
#include "_coder_removePlane_BBox_mex.h"
#include "removePlane_BBox_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void removePlane_BBox_once(void);

/* Function Definitions */
static void removePlane_BBox_once(void)
{
  mex_InitInfAndNan();
}

void removePlane_BBox_initialize(void)
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
                          "lidar_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    removePlane_BBox_once();
  }
}

/* End of code generation (removePlane_BBox_initialize.c) */
