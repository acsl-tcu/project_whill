/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_observation_initialize.c
 *
 * Code generation for function 'calc_observation_initialize'
 *
 */

/* Include files */
#include "calc_observation_initialize.h"
#include "_coder_calc_observation_mex.h"
#include "calc_observation.h"
#include "calc_observation_data.h"
#include "eml_rand.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_rand_shr3cong_stateful.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void calc_observation_once(const emlrtStack *sp);

/* Function Definitions */
static void calc_observation_once(const emlrtStack *sp)
{
  emlrtStack st;
  mex_InitInfAndNan();
  st.prev = sp;
  st.tls = sp->tls;
  method_not_empty_main = false;
  state_not_empty_main = false;
  st.site = NULL;
  initThreadID(&st);
  st.site = NULL;
  eml_rand_init(&st);
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
  st.site = NULL;
  c_eml_rand_mt19937ar_stateful_i(&st);
}

void calc_observation_initialize(void)
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
                          "optimization_toolbox", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "video_and_image_blockset", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    calc_observation_once(&st);
  }
}

/* End of code generation (calc_observation_initialize.c) */
