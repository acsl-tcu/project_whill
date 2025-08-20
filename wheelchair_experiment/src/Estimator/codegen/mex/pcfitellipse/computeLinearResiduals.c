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
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo rc_emlrtRSI = {
    1,                        /* lineNo */
    "computeLinearResiduals", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\computeLinearResiduals.p" /* pathName */
};

/* Function Definitions */
void computeLinearResiduals(const emlrtStack *sp, const real_T x[5],
                            int32_T nVar, real_T workspaceIneq[2],
                            const real_T AineqT[16], real_T bineq)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T c;
  int32_T ia;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &wc_emlrtRSI;
  c_st.site = &xc_emlrtRSI;
  workspaceIneq[0] = bineq;
  st.site = &rc_emlrtRSI;
  b_st.site = &sc_emlrtRSI;
  c_st.site = &vf_emlrtRSI;
  workspaceIneq[0] = -workspaceIneq[0];
  c_st.site = &tc_emlrtRSI;
  c = 0.0;
  c_st.site = &uc_emlrtRSI;
  if (nVar > 2147483646) {
    d_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (ia = 1; ia <= nVar; ia++) {
    c += AineqT[ia - 1] * x[ia - 1];
  }
  workspaceIneq[0] += c;
}

/* End of code generation (computeLinearResiduals.c) */
