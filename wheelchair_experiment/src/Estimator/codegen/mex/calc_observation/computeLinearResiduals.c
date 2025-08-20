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
#include "calc_observation_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo we_emlrtRSI = {
    1,                        /* lineNo */
    "computeLinearResiduals", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/computeLinearResiduals.p" /* pathName */
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
  st.site = &we_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &cf_emlrtRSI;
  c_st.site = &df_emlrtRSI;
  workspaceIneq[0] = bineq;
  st.site = &we_emlrtRSI;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &th_emlrtRSI;
  workspaceIneq[0] = -workspaceIneq[0];
  c_st.site = &ye_emlrtRSI;
  c = 0.0;
  c_st.site = &af_emlrtRSI;
  if (nVar > 2147483646) {
    d_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (ia = 1; ia <= nVar; ia++) {
    c += AineqT[ia - 1] * x[ia - 1];
  }
  workspaceIneq[0] += c;
}

/* End of code generation (computeLinearResiduals.c) */
