/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * solve1.c
 *
 * Code generation for function 'solve1'
 *
 */

/* Include files */
#include "solve1.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo vi_emlrtRSI = {
    1,       /* lineNo */
    "solve", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/solve.p" /* pathName */
};

static emlrtRSInfo wi_emlrtRSI =
    {
        44,      /* lineNo */
        "xtrsv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xtrsv.m" /* pathName */
};

static emlrtRSInfo xi_emlrtRSI =
    {
        53,      /* lineNo */
        "xtrsv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xtrsv.m" /* pathName */
};

static emlrtBCInfo ke_emlrtBCI = {
    1,       /* iFirst */
    8,       /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/solve.p", /* pName */
    3                                 /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = {
    1,       /* iFirst */
    225,     /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/solve.p", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = {
    1,       /* iFirst */
    120,     /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/solve.p", /* pName */
    3                                 /* checkKind */
};

/* Function Definitions */
void b_solve(const emlrtStack *sp, const k_struct_T *obj, real_T rhs[8])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T j;
  int32_T jA;
  int32_T jjA;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  jA = obj->ndims - 1;
  b_st.site = &qg_emlrtRSI;
  if (obj->ndims != 0) {
    c_st.site = &wi_emlrtRSI;
    if (obj->ndims > 2147483646) {
      d_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= jA; j++) {
      jjA = j + j * 15;
      b = jA - j;
      c_st.site = &xi_emlrtRSI;
      if (b > 2147483646) {
        d_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (i = 0; i < b; i++) {
        int32_T ix;
        ix = (j + i) + 1;
        rhs[ix] -= rhs[j] * obj->FMat[(jjA + i) + 1];
      }
    }
  }
  b = obj->ndims;
  st.site = &vi_emlrtRSI;
  if (obj->ndims > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (jA = 0; jA < b; jA++) {
    if ((jA + 1 < 1) || (jA + 1 > 8)) {
      emlrtDynamicBoundsCheckR2012b(jA + 1, 1, 8, &ke_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    rhs[jA] /= obj->FMat[jA + 15 * jA];
  }
  if (obj->ndims != 0) {
    for (j = b; j >= 1; j--) {
      real_T temp;
      jA = (j - 1) * 15;
      temp = rhs[j - 1];
      jjA = j + 1;
      for (i = b; i >= jjA; i--) {
        temp -= obj->FMat[(jA + i) - 1] * rhs[i - 1];
      }
      rhs[j - 1] = temp;
    }
  }
}

void c_solve(const emlrtStack *sp, const k_struct_T *obj, real_T rhs[120])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T j;
  int32_T jA;
  int32_T jjA;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  jA = obj->ndims - 1;
  b_st.site = &qg_emlrtRSI;
  if (obj->ndims != 0) {
    c_st.site = &wi_emlrtRSI;
    if (obj->ndims > 2147483646) {
      d_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= jA; j++) {
      jjA = j + j * 15;
      b = jA - j;
      c_st.site = &xi_emlrtRSI;
      if (b > 2147483646) {
        d_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (i = 0; i < b; i++) {
        int32_T ix;
        ix = (j + i) + 1;
        rhs[ix] -= rhs[j] * obj->FMat[(jjA + i) + 1];
      }
    }
  }
  jjA = obj->ndims;
  st.site = &vi_emlrtRSI;
  if (obj->ndims > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (jA = 0; jA < jjA; jA++) {
    b = (jA + 15 * jA) + 1;
    if ((b < 1) || (b > 225)) {
      emlrtDynamicBoundsCheckR2012b(b, 1, 225, &le_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((jA + 1 < 1) || (jA + 1 > 120)) {
      emlrtDynamicBoundsCheckR2012b(jA + 1, 1, 120, &me_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    rhs[jA] /= obj->FMat[b - 1];
  }
  if (obj->ndims != 0) {
    for (j = jjA; j >= 1; j--) {
      real_T temp;
      jA = (j - 1) * 15;
      temp = rhs[j - 1];
      b = j + 1;
      for (i = jjA; i >= b; i--) {
        temp -= obj->FMat[(jA + i) - 1] * rhs[i - 1];
      }
      rhs[j - 1] = temp;
    }
  }
}

/* End of code generation (solve1.c) */
