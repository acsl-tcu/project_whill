/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeLinearResiduals.c
 *
 * Code generation for function 'computeLinearResiduals'
 *
 */

/* Include files */
#include "computeLinearResiduals.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = {
    1,                        /* lineNo */
    "computeLinearResiduals", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\computeLinearResiduals.p" /* pathName */
};

/* Function Definitions */
real_T computeLinearResiduals(const emlrtStack *sp, const real_T x[5],
                              int32_T nVar, const real_T AineqT[7],
                              real_T bineq)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T c;
  int32_T ia;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &oc_emlrtRSI;
  c_st.site = &pc_emlrtRSI;
  st.site = &jc_emlrtRSI;
  b_st.site = &kc_emlrtRSI;
  c_st.site = &nf_emlrtRSI;
  c_st.site = &lc_emlrtRSI;
  c = 0.0;
  c_st.site = &mc_emlrtRSI;
  if (nVar > 2147483646) {
    d_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (ia = 1; ia <= nVar; ia++) {
    c += AineqT[ia - 1] * x[ia - 1];
  }
  return -bineq + c;
}

/* End of code generation (computeLinearResiduals.c) */
