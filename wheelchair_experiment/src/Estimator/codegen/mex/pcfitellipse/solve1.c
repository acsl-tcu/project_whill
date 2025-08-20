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
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wg_emlrtRSI = {
    1,       /* lineNo */
    "solve", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI = {
    44,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

static emlrtRSInfo yg_emlrtRSI = {
    53,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

static emlrtBCInfo qd_emlrtBCI = {
    1,       /* iFirst */
    8,       /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p", /* pName */
    3                                 /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = {
    1,       /* iFirst */
    225,     /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    1,       /* iFirst */
    120,     /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p", /* pName */
    3                                 /* checkKind */
};

/* Function Definitions */
void b_solve(const emlrtStack *sp, const h_struct_T *obj, real_T rhs[8])
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
  st.site = &wg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  jA = obj->ndims - 1;
  b_st.site = &le_emlrtRSI;
  if (obj->ndims != 0) {
    c_st.site = &xg_emlrtRSI;
    if (obj->ndims > 2147483646) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= jA; j++) {
      jjA = j + j * 15;
      b = jA - j;
      c_st.site = &yg_emlrtRSI;
      if (b > 2147483646) {
        d_st.site = &o_emlrtRSI;
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
  st.site = &wg_emlrtRSI;
  if (obj->ndims > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (jA = 0; jA < b; jA++) {
    if ((jA + 1 < 1) || (jA + 1 > 8)) {
      emlrtDynamicBoundsCheckR2012b(jA + 1, 1, 8, &qd_emlrtBCI,
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

void c_solve(const emlrtStack *sp, const h_struct_T *obj, real_T rhs[120])
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
  st.site = &wg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  jA = obj->ndims - 1;
  b_st.site = &le_emlrtRSI;
  if (obj->ndims != 0) {
    c_st.site = &xg_emlrtRSI;
    if (obj->ndims > 2147483646) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= jA; j++) {
      jjA = j + j * 15;
      b = jA - j;
      c_st.site = &yg_emlrtRSI;
      if (b > 2147483646) {
        d_st.site = &o_emlrtRSI;
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
  st.site = &wg_emlrtRSI;
  if (obj->ndims > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (jA = 0; jA < jjA; jA++) {
    b = (jA + 15 * jA) + 1;
    if ((b < 1) || (b > 225)) {
      emlrtDynamicBoundsCheckR2012b(b, 1, 225, &rd_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((jA + 1 < 1) || (jA + 1 > 120)) {
      emlrtDynamicBoundsCheckR2012b(jA + 1, 1, 120, &sd_emlrtBCI,
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
