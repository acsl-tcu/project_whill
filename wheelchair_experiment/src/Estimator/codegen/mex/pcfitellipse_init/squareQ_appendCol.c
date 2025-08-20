/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squareQ_appendCol.c
 *
 * Code generation for function 'squareQ_appendCol'
 *
 */

/* Include files */
#include "squareQ_appendCol.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "pcfitellipse_init_mexutil.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo yf_emlrtRSI = {
    1,                   /* lineNo */
    "squareQ_appendCol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\squareQ_appendCol.p" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI = {
    32,           /* lineNo */
    "xrotg_blas", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg."
    "m" /* pathName */
};

static emlrtBCInfo vc_emlrtBCI = {
    1,                   /* iFirst */
    13,                  /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "squareQ_appendCol", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\squareQ_appendCol.p", /* pName */
    3                                 /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    1,                   /* iFirst */
    169,                 /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "squareQ_appendCol", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\squareQ_appendCol.p", /* pName */
    0                                 /* checkKind */
};

/* Function Definitions */
void squareQ_appendCol(const emlrtStack *sp, e_struct_T *obj,
                       const real_T vec[91], int32_T iv0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T c;
  real_T s;
  real_T temp;
  real_T temp_tmp;
  int32_T b_tmp;
  int32_T ia;
  int32_T iac;
  int32_T idx;
  int32_T iyend;
  int32_T y_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  y_tmp = obj->ncols + 1;
  obj->minRowCol = muIntScalarMin_sint32(obj->mrows, y_tmp);
  idx = 13 * obj->ncols;
  st.site = &yf_emlrtRSI;
  b_st.site = &kc_emlrtRSI;
  if (obj->mrows != 0) {
    iyend = idx + obj->mrows;
    c_st.site = &td_emlrtRSI;
    if ((idx + 1 <= iyend) && (iyend > 2147483646)) {
      d_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    if (idx + 1 <= iyend) {
      memset(&obj->QR[idx], 0, (uint32_T)(iyend - idx) * sizeof(real_T));
    }
    b_tmp = 13 * (obj->mrows - 1) + 1;
    c_st.site = &lc_emlrtRSI;
    if (b_tmp > 2147483634) {
      d_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (iac = 1; iac <= b_tmp; iac += 13) {
      c = 0.0;
      iyend = (iac + obj->mrows) - 1;
      c_st.site = &mc_emlrtRSI;
      if ((iac <= iyend) && (iyend > 2147483646)) {
        d_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (ia = iac; ia <= iyend; ia++) {
        c += obj->Q[ia - 1] * vec[((iv0 + ia) - iac) - 1];
      }
      ia = idx + div_nde_s32_floor(iac - 1, 13);
      obj->QR[ia] += c;
    }
  }
  obj->ncols = y_tmp;
  if ((obj->ncols < 1) || (obj->ncols > 13)) {
    emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, 13, &vc_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  ia = obj->ncols - 1;
  obj->jpvt[ia] = obj->ncols;
  for (idx = obj->mrows; idx > obj->ncols; idx--) {
    st.site = &yf_emlrtRSI;
    iyend = idx + 13 * ia;
    if ((iyend - 1 < 1) || (iyend - 1 > 169)) {
      emlrtDynamicBoundsCheckR2012b(iyend - 1, 1, 169, &wc_emlrtBCI, &st);
    }
    temp_tmp = obj->QR[iyend - 2];
    if ((iyend < 1) || (iyend > 169)) {
      emlrtDynamicBoundsCheckR2012b(iyend, 1, 169, &wc_emlrtBCI, &st);
    }
    temp = obj->QR[iyend - 1];
    b_st.site = &ag_emlrtRSI;
    c_st.site = &bg_emlrtRSI;
    c = 0.0;
    s = 0.0;
    drotg(&temp_tmp, &temp, &c, &s);
    obj->QR[iyend - 2] = temp_tmp;
    obj->QR[iyend - 1] = temp;
    iyend = 13 * (idx - 2);
    st.site = &yf_emlrtRSI;
    b_tmp = obj->mrows;
    if (obj->mrows >= 1) {
      b_st.site = &cg_emlrtRSI;
      if (obj->mrows > 2147483646) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (iac = 0; iac < b_tmp; iac++) {
        y_tmp = iyend + iac;
        temp_tmp = obj->Q[y_tmp + 13];
        temp = c * obj->Q[y_tmp] + s * temp_tmp;
        obj->Q[y_tmp + 13] = c * temp_tmp - s * obj->Q[y_tmp];
        obj->Q[y_tmp] = temp;
      }
    }
  }
}

/* End of code generation (squareQ_appendCol.c) */
