/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeGradLag.c
 *
 * Code generation for function 'computeGradLag'
 *
 */

/* Include files */
#include "computeGradLag.h"
#include "calc_observation_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kf_emlrtRSI = {
    1,                /* lineNo */
    "computeGradLag", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeGradLag.p" /* pathName */
};

static emlrtBCInfo ag_emlrtBCI = {
    1,                /* iFirst */
    8,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeGradLag.p", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo bg_emlrtBCI = {
    1,                /* iFirst */
    8,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeGradLag.p", /* pName */
    3                             /* checkKind */
};

static emlrtBCInfo cg_emlrtBCI = {
    1,                /* iFirst */
    15,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeGradLag.p", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = {
    1,                /* iFirst */
    120,              /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeGradLag.p", /* pName */
    3                             /* checkKind */
};

/* Function Definitions */
void b_computeGradLag(const emlrtStack *sp, real_T workspace[120], int32_T nVar,
                      const real_T grad[8], const real_T AineqTrans[16],
                      const int32_T finiteFixed[8], int32_T mFixed,
                      const int32_T finiteLB[8], int32_T mLB,
                      const int32_T finiteUB[8], int32_T mUB,
                      const real_T lambda[15])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T iL0;
  int32_T idx;
  int32_T ix;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (nVar > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)nVar;
  memcpy(&workspace[0], &grad[0], (uint32_T)i * sizeof(real_T));
  st.site = &kf_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mFixed;
  for (idx = 0; idx < i; idx++) {
    ix = finiteFixed[idx];
    if ((ix < 1) || (ix > 120)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 120, &gg_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    workspace[ix - 1] += lambda[idx];
  }
  st.site = &kf_emlrtRSI;
  ix = mFixed;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  for (iL0 = 0; iL0 <= 8; iL0 += 8) {
    b = iL0 + nVar;
    c_st.site = &lf_emlrtRSI;
    if ((iL0 + 1 <= b) && (b > 2147483646)) {
      d_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (idx = iL0 + 1; idx <= b; idx++) {
      i = (idx - iL0) - 1;
      workspace[i] += AineqTrans[idx - 1] * lambda[ix];
    }
    ix++;
  }
  st.site = &kf_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 8) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &ag_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ix = (mFixed + idx) + 3;
    if ((ix < 1) || (ix > 15)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 15, &cg_emlrtBCI, (emlrtConstCTX)sp);
    }
    b = finiteLB[idx];
    if ((b < 1) || (b > 120)) {
      emlrtDynamicBoundsCheckR2012b(b, 1, 120, &gg_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[b - 1] -= lambda[ix - 1];
  }
  if ((uint8_T)mLB - 1 < 0) {
    iL0 = mFixed + 3;
  } else {
    iL0 = (mFixed + (uint8_T)mLB) + 3;
  }
  st.site = &kf_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    ix = iL0 + idx;
    if ((ix < 1) || (ix > 15)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 15, &cg_emlrtBCI, (emlrtConstCTX)sp);
    }
    b = finiteUB[idx];
    if ((b < 1) || (b > 120)) {
      emlrtDynamicBoundsCheckR2012b(b, 1, 120, &gg_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[b - 1] += lambda[ix - 1];
  }
}

void computeGradLag(const emlrtStack *sp, real_T workspace[8], int32_T nVar,
                    const real_T grad[8], const real_T AineqTrans[16],
                    const int32_T finiteFixed[8], int32_T mFixed,
                    const int32_T finiteLB[8], int32_T mLB,
                    const int32_T finiteUB[8], int32_T mUB,
                    const real_T lambda[15])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T iL0;
  int32_T idx;
  int32_T ix;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (nVar > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)nVar;
  memcpy(&workspace[0], &grad[0], (uint32_T)i * sizeof(real_T));
  st.site = &kf_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mFixed;
  for (idx = 0; idx < i; idx++) {
    ix = finiteFixed[idx];
    if ((ix < 1) || (ix > 8)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 8, &bg_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[ix - 1] += lambda[idx];
  }
  st.site = &kf_emlrtRSI;
  ix = mFixed;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  for (iL0 = 0; iL0 <= 8; iL0 += 8) {
    b = iL0 + nVar;
    c_st.site = &lf_emlrtRSI;
    if ((iL0 + 1 <= b) && (b > 2147483646)) {
      d_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (idx = iL0 + 1; idx <= b; idx++) {
      i = (idx - iL0) - 1;
      workspace[i] += AineqTrans[idx - 1] * lambda[ix];
    }
    ix++;
  }
  st.site = &kf_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 8) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &ag_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ix = (mFixed + idx) + 3;
    if ((ix < 1) || (ix > 15)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 15, &cg_emlrtBCI, (emlrtConstCTX)sp);
    }
    b = finiteLB[idx];
    if ((b < 1) || (b > 8)) {
      emlrtDynamicBoundsCheckR2012b(b, 1, 8, &bg_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[b - 1] -= lambda[ix - 1];
  }
  if ((uint8_T)mLB - 1 < 0) {
    iL0 = mFixed + 3;
  } else {
    iL0 = (mFixed + (uint8_T)mLB) + 3;
  }
  st.site = &kf_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    ix = iL0 + idx;
    if ((ix < 1) || (ix > 15)) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, 15, &cg_emlrtBCI, (emlrtConstCTX)sp);
    }
    b = finiteUB[idx];
    if ((b < 1) || (b > 8)) {
      emlrtDynamicBoundsCheckR2012b(b, 1, 8, &bg_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[b - 1] += lambda[ix - 1];
  }
}

/* End of code generation (computeGradLag.c) */
