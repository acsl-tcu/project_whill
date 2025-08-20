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
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo og_emlrtRSI = {
    1,       /* lineNo */
    "solve", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p" /* pathName */
};

static emlrtRSInfo pg_emlrtRSI = {
    44,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

static emlrtRSInfo qg_emlrtRSI = {
    53,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

static emlrtBCInfo jd_emlrtBCI = {
    1,       /* iFirst */
    7,       /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p", /* pName */
    3                                 /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = {
    1,       /* iFirst */
    169,     /* iLast */
    1,       /* lineNo */
    1,       /* colNo */
    "",      /* aName */
    "solve", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\solve.p", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = {
    1,       /* iFirst */
    91,      /* iLast */
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
void b_solve(const emlrtStack *sp, const f_struct_T *obj, real_T rhs[7])
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
  st.site = &og_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  jA = obj->ndims - 1;
  b_st.site = &de_emlrtRSI;
  if (obj->ndims != 0) {
    c_st.site = &pg_emlrtRSI;
    if (obj->ndims > 2147483646) {
      d_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= jA; j++) {
      jjA = j + j * 13;
      b = jA - j;
      c_st.site = &qg_emlrtRSI;
      if (b > 2147483646) {
        d_st.site = &hb_emlrtRSI;
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
  st.site = &og_emlrtRSI;
  if (obj->ndims > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (jA = 0; jA < b; jA++) {
    if ((jA + 1 < 1) || (jA + 1 > 7)) {
      emlrtDynamicBoundsCheckR2012b(jA + 1, 1, 7, &jd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    rhs[jA] /= obj->FMat[jA + 13 * jA];
  }
  if (obj->ndims != 0) {
    for (j = b; j >= 1; j--) {
      real_T temp;
      jA = (j - 1) * 13;
      temp = rhs[j - 1];
      jjA = j + 1;
      for (i = b; i >= jjA; i--) {
        temp -= obj->FMat[(jA + i) - 1] * rhs[i - 1];
      }
      rhs[j - 1] = temp;
    }
  }
}

void c_solve(const emlrtStack *sp, const f_struct_T *obj, real_T rhs[91])
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
  st.site = &og_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  jA = obj->ndims - 1;
  b_st.site = &de_emlrtRSI;
  if (obj->ndims != 0) {
    c_st.site = &pg_emlrtRSI;
    if (obj->ndims > 2147483646) {
      d_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= jA; j++) {
      jjA = j + j * 13;
      b = jA - j;
      c_st.site = &qg_emlrtRSI;
      if (b > 2147483646) {
        d_st.site = &hb_emlrtRSI;
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
  st.site = &og_emlrtRSI;
  if (obj->ndims > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (jA = 0; jA < jjA; jA++) {
    b = (jA + 13 * jA) + 1;
    if ((b < 1) || (b > 169)) {
      emlrtDynamicBoundsCheckR2012b(b, 1, 169, &kd_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((jA + 1 < 1) || (jA + 1 > 91)) {
      emlrtDynamicBoundsCheckR2012b(jA + 1, 1, 91, &ld_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    rhs[jA] /= obj->FMat[b - 1];
  }
  if (obj->ndims != 0) {
    for (j = jjA; j >= 1; j--) {
      real_T temp;
      jA = (j - 1) * 13;
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
