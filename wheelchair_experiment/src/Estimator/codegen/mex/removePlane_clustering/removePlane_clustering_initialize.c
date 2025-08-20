/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removePlane_clustering_initialize.c
 *
 * Code generation for function 'removePlane_clustering_initialize'
 *
 */

/* Include files */
#include "removePlane_clustering_initialize.h"
#include "_coder_removePlane_clustering_mex.h"
#include "removePlane_clustering_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void removePlane_clustering_once(void);

/* Function Definitions */
static void removePlane_clustering_once(void)
{
  mex_InitInfAndNan();
}

void removePlane_clustering_initialize(void)
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
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "video_and_image_blockset", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    removePlane_clustering_once();
  }
}

/* End of code generation (removePlane_clustering_initialize.c) */
