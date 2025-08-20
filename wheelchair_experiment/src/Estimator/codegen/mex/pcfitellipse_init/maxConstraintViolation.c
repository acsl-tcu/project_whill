/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation.c
 *
 * Code generation for function 'maxConstraintViolation'
 *
 */

/* Include files */
#include "maxConstraintViolation.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo lf_emlrtRSI = {
    1,                        /* lineNo */
    "maxConstraintViolation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation.p" /* pathName */
};

static emlrtRSInfo mf_emlrtRSI = {
    1,                                           /* lineNo */
    "maxConstraintViolation_AMats_regularized_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation_AMats_regul"
    "arized_.p" /* pathName */
};

static emlrtRSInfo of_emlrtRSI = {
    1,                                              /* lineNo */
    "maxConstraintViolation_AMats_nonregularized_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation_AMats_nonre"
    "gularized_.p" /* pathName */
};

static emlrtBCInfo ic_emlrtBCI = {
    1,                        /* iFirst */
    7,                        /* iLast */
    1,                        /* lineNo */
    1,                        /* colNo */
    "",                       /* aName */
    "maxConstraintViolation", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation.p", /* pName */
    0                                       /* checkKind */
};

/* Function Definitions */
real_T b_maxConstraintViolation(const emlrtStack *sp, i_struct_T *obj,
                                const real_T x[91])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T v;
  int32_T ia;
  int32_T idx;
  int32_T idxLB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (obj->probType == 2) {
    real_T c;
    st.site = &lf_emlrtRSI;
    b_st.site = &mf_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    d_st.site = &pc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &mf_emlrtRSI;
    c_st.site = &kc_emlrtRSI;
    d_st.site = &nf_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &lc_emlrtRSI;
    c = 0.0;
    d_st.site = &mc_emlrtRSI;
    for (ia = 0; ia < 5; ia++) {
      c += obj->Aineq[ia] * x[ia + 13];
    }
    obj->maxConstrWorkspace[0] += c;
    b_st.site = &mf_emlrtRSI;
    c = obj->maxConstrWorkspace[0] - x[18];
    obj->maxConstrWorkspace[0] = c;
    v = muDoubleScalarMax(0.0, c);
  } else {
    real_T c;
    st.site = &lf_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    d_st.site = &pc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &of_emlrtRSI;
    c_st.site = &kc_emlrtRSI;
    idxLB = obj->nVar;
    d_st.site = &nf_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &lc_emlrtRSI;
    c = 0.0;
    d_st.site = &mc_emlrtRSI;
    if (idxLB > 2147483646) {
      e_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (ia = 1; ia <= idxLB; ia++) {
      c += obj->Aineq[ia - 1] * x[ia + 12];
    }
    obj->maxConstrWorkspace[0] += c;
    b_st.site = &of_emlrtRSI;
    v = muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]);
  }
  if (obj->sizes[3] > 0) {
    st.site = &lf_emlrtRSI;
    if (obj->sizes[3] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)obj->sizes[3];
    for (idx = 0; idx < ia; idx++) {
      if (idx + 1 > 7) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxLB = obj->indexLB[idx];
      if ((obj->indexLB[idx] < 1) || (obj->indexLB[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx], 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, -x[idxLB + 12] - obj->lb[idxLB - 1]);
    }
  }
  if (obj->sizes[4] > 0) {
    st.site = &lf_emlrtRSI;
    if (obj->sizes[4] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)obj->sizes[4];
    for (idx = 0; idx < ia; idx++) {
      idxLB = obj->indexUB[idx];
      if ((obj->indexUB[idx] < 1) || (obj->indexUB[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx], 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, x[idxLB + 12] - obj->ub[idxLB - 1]);
    }
  }
  if (obj->sizes[0] > 0) {
    st.site = &lf_emlrtRSI;
    if (obj->sizes[0] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)obj->sizes[0];
    for (idx = 0; idx < ia; idx++) {
      if ((obj->indexFixed[idx] < 1) || (obj->indexFixed[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexFixed[idx], 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[obj->indexFixed[idx] + 12] -
                               obj->ub[obj->indexFixed[idx] - 1]));
    }
  }
  return v;
}

real_T c_maxConstraintViolation(const emlrtStack *sp, i_struct_T *obj,
                                const real_T x[7])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T v;
  int32_T ia;
  int32_T idx;
  int32_T idxLB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (obj->probType == 2) {
    real_T c;
    st.site = &lf_emlrtRSI;
    b_st.site = &mf_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    d_st.site = &pc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &mf_emlrtRSI;
    c_st.site = &kc_emlrtRSI;
    d_st.site = &nf_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &lc_emlrtRSI;
    c = 0.0;
    d_st.site = &mc_emlrtRSI;
    for (ia = 0; ia < 5; ia++) {
      c += obj->Aineq[ia] * x[ia];
    }
    obj->maxConstrWorkspace[0] += c;
    b_st.site = &mf_emlrtRSI;
    c = obj->maxConstrWorkspace[0] - x[5];
    obj->maxConstrWorkspace[0] = c;
    v = muDoubleScalarMax(0.0, c);
  } else {
    real_T c;
    st.site = &lf_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    d_st.site = &pc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &of_emlrtRSI;
    c_st.site = &kc_emlrtRSI;
    idxLB = obj->nVar;
    d_st.site = &nf_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &lc_emlrtRSI;
    c = 0.0;
    d_st.site = &mc_emlrtRSI;
    if (idxLB > 2147483646) {
      e_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (ia = 1; ia <= idxLB; ia++) {
      c += obj->Aineq[ia - 1] * x[ia - 1];
    }
    obj->maxConstrWorkspace[0] += c;
    b_st.site = &of_emlrtRSI;
    v = muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]);
  }
  if (obj->sizes[3] > 0) {
    st.site = &lf_emlrtRSI;
    if (obj->sizes[3] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)obj->sizes[3];
    for (idx = 0; idx < ia; idx++) {
      if (idx + 1 > 7) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxLB = obj->indexLB[idx] - 1;
      if ((obj->indexLB[idx] < 1) || (obj->indexLB[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx], 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, -x[idxLB] - obj->lb[idxLB]);
    }
  }
  if (obj->sizes[4] > 0) {
    st.site = &lf_emlrtRSI;
    if (obj->sizes[4] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)obj->sizes[4];
    for (idx = 0; idx < ia; idx++) {
      idxLB = obj->indexUB[idx] - 1;
      if ((obj->indexUB[idx] < 1) || (obj->indexUB[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx], 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, x[idxLB] - obj->ub[idxLB]);
    }
  }
  if (obj->sizes[0] > 0) {
    st.site = &lf_emlrtRSI;
    if (obj->sizes[0] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)obj->sizes[0];
    for (idx = 0; idx < ia; idx++) {
      if ((obj->indexFixed[idx] < 1) || (obj->indexFixed[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexFixed[idx], 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[obj->indexFixed[idx] - 1] -
                               obj->ub[obj->indexFixed[idx] - 1]));
    }
  }
  return v;
}

real_T maxConstraintViolation(const emlrtStack *sp, i_struct_T *obj,
                              const real_T x[91])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T v;
  int32_T ia;
  int32_T idx;
  int32_T idxLB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (obj->probType == 2) {
    real_T c;
    st.site = &lf_emlrtRSI;
    b_st.site = &mf_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    d_st.site = &pc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &mf_emlrtRSI;
    c_st.site = &kc_emlrtRSI;
    d_st.site = &nf_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &lc_emlrtRSI;
    c = 0.0;
    d_st.site = &mc_emlrtRSI;
    for (ia = 0; ia < 5; ia++) {
      c += obj->Aineq[ia] * x[ia];
    }
    obj->maxConstrWorkspace[0] += c;
    b_st.site = &mf_emlrtRSI;
    c = obj->maxConstrWorkspace[0] - x[5];
    obj->maxConstrWorkspace[0] = c;
    v = muDoubleScalarMax(0.0, c);
  } else {
    real_T c;
    st.site = &lf_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    d_st.site = &pc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &of_emlrtRSI;
    c_st.site = &kc_emlrtRSI;
    idxLB = obj->nVar;
    d_st.site = &nf_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &lc_emlrtRSI;
    c = 0.0;
    d_st.site = &mc_emlrtRSI;
    if (idxLB > 2147483646) {
      e_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (ia = 1; ia <= idxLB; ia++) {
      c += obj->Aineq[ia - 1] * x[ia - 1];
    }
    obj->maxConstrWorkspace[0] += c;
    b_st.site = &of_emlrtRSI;
    v = muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]);
  }
  if (obj->sizes[3] > 0) {
    st.site = &lf_emlrtRSI;
    if (obj->sizes[3] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)obj->sizes[3];
    for (idx = 0; idx < ia; idx++) {
      if (idx + 1 > 7) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxLB = obj->indexLB[idx] - 1;
      if ((obj->indexLB[idx] < 1) || (obj->indexLB[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx], 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, -x[idxLB] - obj->lb[idxLB]);
    }
  }
  if (obj->sizes[4] > 0) {
    st.site = &lf_emlrtRSI;
    if (obj->sizes[4] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)obj->sizes[4];
    for (idx = 0; idx < ia; idx++) {
      idxLB = obj->indexUB[idx] - 1;
      if ((obj->indexUB[idx] < 1) || (obj->indexUB[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx], 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, x[idxLB] - obj->ub[idxLB]);
    }
  }
  if (obj->sizes[0] > 0) {
    st.site = &lf_emlrtRSI;
    if (obj->sizes[0] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)obj->sizes[0];
    for (idx = 0; idx < ia; idx++) {
      if ((obj->indexFixed[idx] < 1) || (obj->indexFixed[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexFixed[idx], 1, 7, &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[obj->indexFixed[idx] - 1] -
                               obj->ub[obj->indexFixed[idx] - 1]));
    }
  }
  return v;
}

/* End of code generation (maxConstraintViolation.c) */
