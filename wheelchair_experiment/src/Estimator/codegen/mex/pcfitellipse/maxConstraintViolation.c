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
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo tf_emlrtRSI = {
    1,                        /* lineNo */
    "maxConstraintViolation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation.p" /* pathName */
};

static emlrtRSInfo uf_emlrtRSI = {
    1,                                           /* lineNo */
    "maxConstraintViolation_AMats_regularized_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation_AMats_regul"
    "arized_.p" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    1,                                              /* lineNo */
    "maxConstraintViolation_AMats_nonregularized_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\maxConstraintViolation_AMats_nonre"
    "gularized_.p" /* pathName */
};

static emlrtBCInfo pc_emlrtBCI = {
    1,                        /* iFirst */
    8,                        /* iLast */
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
real_T b_maxConstraintViolation(const emlrtStack *sp, k_struct_T *obj,
                                const real_T x[120])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T ia;
  int32_T iac;
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
    __m128d r;
    real_T c;
    st.site = &tf_emlrtRSI;
    b_st.site = &uf_emlrtRSI;
    c_st.site = &wc_emlrtRSI;
    d_st.site = &xc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &uf_emlrtRSI;
    c_st.site = &sc_emlrtRSI;
    d_st.site = &vf_emlrtRSI;
    r = _mm_loadu_pd(&obj->maxConstrWorkspace[0]);
    _mm_storeu_pd(&obj->maxConstrWorkspace[0],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    d_st.site = &tc_emlrtRSI;
    for (iac = 0; iac <= 8; iac += 8) {
      c = 0.0;
      i = iac + 5;
      d_st.site = &uc_emlrtRSI;
      for (ia = iac + 1; ia <= i; ia++) {
        c += obj->Aineq[ia - 1] * x[(ia - iac) + 14];
      }
      i = iac >> 3;
      obj->maxConstrWorkspace[i] += c;
    }
    b_st.site = &uf_emlrtRSI;
    c = obj->maxConstrWorkspace[0] - x[20];
    obj->maxConstrWorkspace[0] = c;
    v = muDoubleScalarMax(0.0, c);
    c = obj->maxConstrWorkspace[1] - x[21];
    obj->maxConstrWorkspace[1] = c;
    v = muDoubleScalarMax(v, c);
  } else {
    __m128d r;
    st.site = &tf_emlrtRSI;
    b_st.site = &wf_emlrtRSI;
    c_st.site = &wc_emlrtRSI;
    d_st.site = &xc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &wf_emlrtRSI;
    c_st.site = &sc_emlrtRSI;
    d_st.site = &vf_emlrtRSI;
    r = _mm_loadu_pd(&obj->maxConstrWorkspace[0]);
    _mm_storeu_pd(&obj->maxConstrWorkspace[0],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    d_st.site = &tc_emlrtRSI;
    for (iac = 0; iac <= 8; iac += 8) {
      real_T c;
      c = 0.0;
      idxLB = iac + obj->nVar;
      d_st.site = &uc_emlrtRSI;
      if ((iac + 1 <= idxLB) && (idxLB > 2147483646)) {
        e_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (ia = iac + 1; ia <= idxLB; ia++) {
        c += obj->Aineq[ia - 1] * x[(ia - iac) + 14];
      }
      i = iac >> 3;
      obj->maxConstrWorkspace[i] += c;
    }
    b_st.site = &wf_emlrtRSI;
    v = muDoubleScalarMax(muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]),
                          obj->maxConstrWorkspace[1]);
  }
  if (obj->sizes[3] > 0) {
    st.site = &tf_emlrtRSI;
    if (obj->sizes[3] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[3];
    for (iac = 0; iac < i; iac++) {
      if (iac + 1 > 8) {
        emlrtDynamicBoundsCheckR2012b(iac + 1, 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxLB = obj->indexLB[iac];
      if ((obj->indexLB[iac] < 1) || (obj->indexLB[iac] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[iac], 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, -x[idxLB + 14] - obj->lb[idxLB - 1]);
    }
  }
  if (obj->sizes[4] > 0) {
    st.site = &tf_emlrtRSI;
    if (obj->sizes[4] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[4];
    for (iac = 0; iac < i; iac++) {
      idxLB = obj->indexUB[iac];
      if ((obj->indexUB[iac] < 1) || (obj->indexUB[iac] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexUB[iac], 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, x[idxLB + 14] - obj->ub[idxLB - 1]);
    }
  }
  if (obj->sizes[0] > 0) {
    st.site = &tf_emlrtRSI;
    if (obj->sizes[0] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[0];
    for (iac = 0; iac < i; iac++) {
      if ((obj->indexFixed[iac] < 1) || (obj->indexFixed[iac] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexFixed[iac], 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[obj->indexFixed[iac] + 14] -
                               obj->ub[obj->indexFixed[iac] - 1]));
    }
  }
  return v;
}

real_T c_maxConstraintViolation(const emlrtStack *sp, k_struct_T *obj,
                                const real_T x[8])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T ia;
  int32_T iac;
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
    __m128d r;
    real_T c;
    st.site = &tf_emlrtRSI;
    b_st.site = &uf_emlrtRSI;
    c_st.site = &wc_emlrtRSI;
    d_st.site = &xc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &uf_emlrtRSI;
    c_st.site = &sc_emlrtRSI;
    d_st.site = &vf_emlrtRSI;
    r = _mm_loadu_pd(&obj->maxConstrWorkspace[0]);
    _mm_storeu_pd(&obj->maxConstrWorkspace[0],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    d_st.site = &tc_emlrtRSI;
    for (iac = 0; iac <= 8; iac += 8) {
      c = 0.0;
      i = iac + 5;
      d_st.site = &uc_emlrtRSI;
      for (ia = iac + 1; ia <= i; ia++) {
        c += obj->Aineq[ia - 1] * x[(ia - iac) - 1];
      }
      i = iac >> 3;
      obj->maxConstrWorkspace[i] += c;
    }
    b_st.site = &uf_emlrtRSI;
    c = obj->maxConstrWorkspace[0] - x[5];
    obj->maxConstrWorkspace[0] = c;
    v = muDoubleScalarMax(0.0, c);
    c = obj->maxConstrWorkspace[1] - x[6];
    obj->maxConstrWorkspace[1] = c;
    v = muDoubleScalarMax(v, c);
  } else {
    __m128d r;
    st.site = &tf_emlrtRSI;
    b_st.site = &wf_emlrtRSI;
    c_st.site = &wc_emlrtRSI;
    d_st.site = &xc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &wf_emlrtRSI;
    c_st.site = &sc_emlrtRSI;
    d_st.site = &vf_emlrtRSI;
    r = _mm_loadu_pd(&obj->maxConstrWorkspace[0]);
    _mm_storeu_pd(&obj->maxConstrWorkspace[0],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    d_st.site = &tc_emlrtRSI;
    for (iac = 0; iac <= 8; iac += 8) {
      real_T c;
      c = 0.0;
      idxLB = iac + obj->nVar;
      d_st.site = &uc_emlrtRSI;
      if ((iac + 1 <= idxLB) && (idxLB > 2147483646)) {
        e_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (ia = iac + 1; ia <= idxLB; ia++) {
        c += obj->Aineq[ia - 1] * x[(ia - iac) - 1];
      }
      i = iac >> 3;
      obj->maxConstrWorkspace[i] += c;
    }
    b_st.site = &wf_emlrtRSI;
    v = muDoubleScalarMax(muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]),
                          obj->maxConstrWorkspace[1]);
  }
  if (obj->sizes[3] > 0) {
    st.site = &tf_emlrtRSI;
    if (obj->sizes[3] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[3];
    for (iac = 0; iac < i; iac++) {
      if (iac + 1 > 8) {
        emlrtDynamicBoundsCheckR2012b(iac + 1, 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxLB = obj->indexLB[iac] - 1;
      if ((obj->indexLB[iac] < 1) || (obj->indexLB[iac] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[iac], 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, -x[idxLB] - obj->lb[idxLB]);
    }
  }
  if (obj->sizes[4] > 0) {
    st.site = &tf_emlrtRSI;
    if (obj->sizes[4] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[4];
    for (iac = 0; iac < i; iac++) {
      idxLB = obj->indexUB[iac] - 1;
      if ((obj->indexUB[iac] < 1) || (obj->indexUB[iac] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexUB[iac], 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, x[idxLB] - obj->ub[idxLB]);
    }
  }
  if (obj->sizes[0] > 0) {
    st.site = &tf_emlrtRSI;
    if (obj->sizes[0] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[0];
    for (iac = 0; iac < i; iac++) {
      if ((obj->indexFixed[iac] < 1) || (obj->indexFixed[iac] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexFixed[iac], 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[obj->indexFixed[iac] - 1] -
                               obj->ub[obj->indexFixed[iac] - 1]));
    }
  }
  return v;
}

real_T maxConstraintViolation(const emlrtStack *sp, k_struct_T *obj,
                              const real_T x[120])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T ia;
  int32_T iac;
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
    __m128d r;
    real_T c;
    st.site = &tf_emlrtRSI;
    b_st.site = &uf_emlrtRSI;
    c_st.site = &wc_emlrtRSI;
    d_st.site = &xc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &uf_emlrtRSI;
    c_st.site = &sc_emlrtRSI;
    d_st.site = &vf_emlrtRSI;
    r = _mm_loadu_pd(&obj->maxConstrWorkspace[0]);
    _mm_storeu_pd(&obj->maxConstrWorkspace[0],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    d_st.site = &tc_emlrtRSI;
    for (iac = 0; iac <= 8; iac += 8) {
      c = 0.0;
      i = iac + 5;
      d_st.site = &uc_emlrtRSI;
      for (ia = iac + 1; ia <= i; ia++) {
        c += obj->Aineq[ia - 1] * x[(ia - iac) - 1];
      }
      i = iac >> 3;
      obj->maxConstrWorkspace[i] += c;
    }
    b_st.site = &uf_emlrtRSI;
    c = obj->maxConstrWorkspace[0] - x[5];
    obj->maxConstrWorkspace[0] = c;
    v = muDoubleScalarMax(0.0, c);
    c = obj->maxConstrWorkspace[1] - x[6];
    obj->maxConstrWorkspace[1] = c;
    v = muDoubleScalarMax(v, c);
  } else {
    __m128d r;
    st.site = &tf_emlrtRSI;
    b_st.site = &wf_emlrtRSI;
    c_st.site = &wc_emlrtRSI;
    d_st.site = &xc_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &wf_emlrtRSI;
    c_st.site = &sc_emlrtRSI;
    d_st.site = &vf_emlrtRSI;
    r = _mm_loadu_pd(&obj->maxConstrWorkspace[0]);
    _mm_storeu_pd(&obj->maxConstrWorkspace[0],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    d_st.site = &tc_emlrtRSI;
    for (iac = 0; iac <= 8; iac += 8) {
      real_T c;
      c = 0.0;
      idxLB = iac + obj->nVar;
      d_st.site = &uc_emlrtRSI;
      if ((iac + 1 <= idxLB) && (idxLB > 2147483646)) {
        e_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (ia = iac + 1; ia <= idxLB; ia++) {
        c += obj->Aineq[ia - 1] * x[(ia - iac) - 1];
      }
      i = iac >> 3;
      obj->maxConstrWorkspace[i] += c;
    }
    b_st.site = &wf_emlrtRSI;
    v = muDoubleScalarMax(muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]),
                          obj->maxConstrWorkspace[1]);
  }
  if (obj->sizes[3] > 0) {
    st.site = &tf_emlrtRSI;
    if (obj->sizes[3] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[3];
    for (iac = 0; iac < i; iac++) {
      if (iac + 1 > 8) {
        emlrtDynamicBoundsCheckR2012b(iac + 1, 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxLB = obj->indexLB[iac] - 1;
      if ((obj->indexLB[iac] < 1) || (obj->indexLB[iac] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[iac], 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, -x[idxLB] - obj->lb[idxLB]);
    }
  }
  if (obj->sizes[4] > 0) {
    st.site = &tf_emlrtRSI;
    if (obj->sizes[4] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[4];
    for (iac = 0; iac < i; iac++) {
      idxLB = obj->indexUB[iac] - 1;
      if ((obj->indexUB[iac] < 1) || (obj->indexUB[iac] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexUB[iac], 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, x[idxLB] - obj->ub[idxLB]);
    }
  }
  if (obj->sizes[0] > 0) {
    st.site = &tf_emlrtRSI;
    if (obj->sizes[0] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[0];
    for (iac = 0; iac < i; iac++) {
      if ((obj->indexFixed[iac] < 1) || (obj->indexFixed[iac] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexFixed[iac], 1, 8, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[obj->indexFixed[iac] - 1] -
                               obj->ub[obj->indexFixed[iac] - 1]));
    }
  }
  return v;
}

/* End of code generation (maxConstraintViolation.c) */
