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
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "maxConstraintViolation_AMats_nonregularized_.h"
#include "maxConstraintViolation_AMats_regularized_.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T b_maxConstraintViolation(const emlrtStack *sp, g_struct_T *obj,
                                const real_T x[120])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T idx;
  int32_T idxLB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj->probType == 2) {
    real_T d;
    st.site = &rh_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &sh_emlrtRSI;
    d_xgemv(&b_st, 5, obj->Aineq, x, obj->maxConstrWorkspace);
    d = obj->maxConstrWorkspace[0] - x[20];
    obj->maxConstrWorkspace[0] = d;
    v = muDoubleScalarMax(0.0, d);
    d = obj->maxConstrWorkspace[1] - x[21];
    obj->maxConstrWorkspace[1] = d;
    v = muDoubleScalarMax(v, d);
  } else {
    st.site = &rh_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &uh_emlrtRSI;
    d_xgemv(&b_st, obj->nVar, obj->Aineq, x, obj->maxConstrWorkspace);
    v = muDoubleScalarMax(muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]),
                          obj->maxConstrWorkspace[1]);
  }
  if (obj->sizes[3] > 0) {
    st.site = &rh_emlrtRSI;
    if (obj->sizes[3] > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[3];
    for (idx = 0; idx < i; idx++) {
      if (idx + 1 > 8) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxLB = obj->indexLB[idx];
      if ((obj->indexLB[idx] < 1) || (obj->indexLB[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx], 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, -x[idxLB + 14] - obj->lb[idxLB - 1]);
    }
  }
  if (obj->sizes[4] > 0) {
    st.site = &rh_emlrtRSI;
    if (obj->sizes[4] > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[4];
    for (idx = 0; idx < i; idx++) {
      idxLB = obj->indexUB[idx];
      if ((obj->indexUB[idx] < 1) || (obj->indexUB[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx], 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, x[idxLB + 14] - obj->ub[idxLB - 1]);
    }
  }
  if (obj->sizes[0] > 0) {
    st.site = &rh_emlrtRSI;
    if (obj->sizes[0] > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[0];
    for (idx = 0; idx < i; idx++) {
      if ((obj->indexFixed[idx] < 1) || (obj->indexFixed[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexFixed[idx], 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[obj->indexFixed[idx] + 14] -
                               obj->ub[obj->indexFixed[idx] - 1]));
    }
  }
  return v;
}

real_T c_maxConstraintViolation(const emlrtStack *sp, g_struct_T *obj,
                                const real_T x[8])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T idx;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    st.site = &rh_emlrtRSI;
    v = c_maxConstraintViolation_AMats_(&st, obj, x);
  } else {
    st.site = &rh_emlrtRSI;
    v = d_maxConstraintViolation_AMats_(&st, obj, x);
  }
  if (mLB > 0) {
    st.site = &rh_emlrtRSI;
    if (mLB > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)mLB;
    for (idx = 0; idx < i; idx++) {
      if (idx + 1 > 8) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      mLB = obj->indexLB[idx] - 1;
      if ((obj->indexLB[idx] < 1) || (obj->indexLB[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx], 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, -x[mLB] - obj->lb[mLB]);
    }
  }
  if (mUB > 0) {
    st.site = &rh_emlrtRSI;
    if (mUB > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)mUB;
    for (idx = 0; idx < i; idx++) {
      mLB = obj->indexUB[idx] - 1;
      if ((obj->indexUB[idx] < 1) || (obj->indexUB[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx], 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, x[mLB] - obj->ub[mLB]);
    }
  }
  if (mFixed > 0) {
    st.site = &rh_emlrtRSI;
    if (mFixed > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)mFixed;
    for (idx = 0; idx < i; idx++) {
      if ((obj->indexFixed[idx] < 1) || (obj->indexFixed[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexFixed[idx], 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[obj->indexFixed[idx] - 1] -
                               obj->ub[obj->indexFixed[idx] - 1]));
    }
  }
  return v;
}

real_T maxConstraintViolation(const emlrtStack *sp, g_struct_T *obj,
                              const real_T x[120])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T idx;
  int32_T idxLB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj->probType == 2) {
    real_T d;
    st.site = &rh_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &sh_emlrtRSI;
    c_xgemv(&b_st, 5, obj->Aineq, x, obj->maxConstrWorkspace);
    d = obj->maxConstrWorkspace[0] - x[5];
    obj->maxConstrWorkspace[0] = d;
    v = muDoubleScalarMax(0.0, d);
    d = obj->maxConstrWorkspace[1] - x[6];
    obj->maxConstrWorkspace[1] = d;
    v = muDoubleScalarMax(v, d);
  } else {
    st.site = &rh_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq[0];
    obj->maxConstrWorkspace[1] = obj->bineq[1];
    b_st.site = &uh_emlrtRSI;
    c_xgemv(&b_st, obj->nVar, obj->Aineq, x, obj->maxConstrWorkspace);
    v = muDoubleScalarMax(muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]),
                          obj->maxConstrWorkspace[1]);
  }
  if (obj->sizes[3] > 0) {
    st.site = &rh_emlrtRSI;
    if (obj->sizes[3] > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[3];
    for (idx = 0; idx < i; idx++) {
      if (idx + 1 > 8) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxLB = obj->indexLB[idx] - 1;
      if ((obj->indexLB[idx] < 1) || (obj->indexLB[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx], 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, -x[idxLB] - obj->lb[idxLB]);
    }
  }
  if (obj->sizes[4] > 0) {
    st.site = &rh_emlrtRSI;
    if (obj->sizes[4] > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[4];
    for (idx = 0; idx < i; idx++) {
      idxLB = obj->indexUB[idx] - 1;
      if ((obj->indexUB[idx] < 1) || (obj->indexUB[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx], 1, 8, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      v = muDoubleScalarMax(v, x[idxLB] - obj->ub[idxLB]);
    }
  }
  if (obj->sizes[0] > 0) {
    st.site = &rh_emlrtRSI;
    if (obj->sizes[0] > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->sizes[0];
    for (idx = 0; idx < i; idx++) {
      if ((obj->indexFixed[idx] < 1) || (obj->indexFixed[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexFixed[idx], 1, 8, &cc_emlrtBCI,
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
