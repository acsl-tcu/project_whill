/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * deleteColMoveEnd.c
 *
 * Code generation for function 'deleteColMoveEnd'
 *
 */

/* Include files */
#include "deleteColMoveEnd.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo dg_emlrtRSI = {
    1,                  /* lineNo */
    "deleteColMoveEnd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\deleteColMoveEnd.p" /* pathName */
};

static emlrtBCInfo xc_emlrtBCI = {
    1,                  /* iFirst */
    13,                 /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "deleteColMoveEnd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\deleteColMoveEnd.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    1,                  /* iFirst */
    13,                 /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "deleteColMoveEnd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\deleteColMoveEnd.p", /* pName */
    3                                /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    1,                  /* iFirst */
    169,                /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "deleteColMoveEnd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\deleteColMoveEnd.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    1,                  /* iFirst */
    169,                /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "deleteColMoveEnd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\deleteColMoveEnd.p", /* pName */
    3                                /* checkKind */
};

/* Function Definitions */
void deleteColMoveEnd(const emlrtStack *sp, e_struct_T *obj, int32_T idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T c;
  real_T s;
  real_T temp;
  real_T temp_tmp;
  int32_T b_k;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (obj->usedPivoting) {
    boolean_T exitg1;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i <= obj->ncols)) {
      if (i > 13) {
        emlrtDynamicBoundsCheckR2012b(14, 1, 13, &xc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (obj->jpvt[i - 1] != idx) {
        i++;
      } else {
        exitg1 = true;
      }
    }
    idx = i;
  }
  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    int32_T QRk0;
    int32_T b_i;
    int32_T n;
    if ((obj->ncols < 1) || (obj->ncols > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, 13, &xc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((idx < 1) || (idx > 13)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &yc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_i = obj->ncols - 1;
    obj->jpvt[idx - 1] = obj->jpvt[b_i];
    i = obj->minRowCol;
    st.site = &dg_emlrtRSI;
    if (obj->minRowCol > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k < i; k++) {
      n = (k + 13 * b_i) + 1;
      if ((n < 1) || (n > 169)) {
        emlrtDynamicBoundsCheckR2012b(n, 1, 169, &ad_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      QRk0 = (k + 13 * (idx - 1)) + 1;
      if ((QRk0 < 1) || (QRk0 > 169)) {
        emlrtDynamicBoundsCheckR2012b(QRk0, 1, 169, &bd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->QR[QRk0 - 1] = obj->QR[n - 1];
    }
    obj->ncols = b_i;
    obj->minRowCol = muIntScalarMin_sint32(obj->mrows, obj->ncols);
    if (idx < obj->mrows) {
      int32_T b_temp_tmp;
      int32_T endIdx;
      i = obj->mrows - 1;
      endIdx = muIntScalarMin_sint32(i, obj->ncols);
      k = endIdx;
      i = 13 * (idx - 1);
      while (k >= idx) {
        st.site = &dg_emlrtRSI;
        b_i = k + i;
        if ((b_i < 1) || (b_i > 169)) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, 169, &ad_emlrtBCI, &st);
        }
        temp_tmp = obj->QR[b_i - 1];
        if ((b_i + 1 < 1) || (b_i + 1 > 169)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, 169, &ad_emlrtBCI, &st);
        }
        temp = obj->QR[b_i];
        b_st.site = &ag_emlrtRSI;
        c = 0.0;
        s = 0.0;
        drotg(&temp_tmp, &temp, &c, &s);
        obj->QR[b_i - 1] = temp_tmp;
        obj->QR[b_i] = temp;
        b_i = 13 * (k - 1);
        n = (k + b_i) + 1;
        if ((n < 1) || (n > 169)) {
          emlrtDynamicBoundsCheckR2012b(n, 1, 169, &bd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        obj->QR[n - 1] = 0.0;
        QRk0 = k + 13 * idx;
        st.site = &dg_emlrtRSI;
        n = obj->ncols - idx;
        if (n >= 1) {
          b_st.site = &cg_emlrtRSI;
          if (n > 2147483646) {
            c_st.site = &hb_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (b_k = 0; b_k < n; b_k++) {
            b_temp_tmp = QRk0 + b_k * 13;
            temp_tmp = obj->QR[b_temp_tmp - 1];
            temp = c * temp_tmp + s * obj->QR[b_temp_tmp];
            obj->QR[b_temp_tmp] = c * obj->QR[b_temp_tmp] - s * temp_tmp;
            obj->QR[b_temp_tmp - 1] = temp;
          }
        }
        st.site = &dg_emlrtRSI;
        n = obj->mrows;
        b_st.site = &cg_emlrtRSI;
        if (obj->mrows > 2147483646) {
          c_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (b_k = 0; b_k < n; b_k++) {
          b_temp_tmp = b_i + b_k;
          temp_tmp = obj->Q[b_temp_tmp + 13];
          temp = c * obj->Q[b_temp_tmp] + s * temp_tmp;
          obj->Q[b_temp_tmp + 13] = c * temp_tmp - s * obj->Q[b_temp_tmp];
          obj->Q[b_temp_tmp] = temp;
        }
        k--;
      }
      b_i = idx + 1;
      st.site = &dg_emlrtRSI;
      for (k = b_i; k <= endIdx; k++) {
        i = 13 * (k - 1);
        st.site = &dg_emlrtRSI;
        n = k + i;
        if ((n < 1) || (n > 169)) {
          emlrtDynamicBoundsCheckR2012b(n, 1, 169, &ad_emlrtBCI, &st);
        }
        temp_tmp = obj->QR[n - 1];
        if ((n + 1 < 1) || (n + 1 > 169)) {
          emlrtDynamicBoundsCheckR2012b(n + 1, 1, 169, &ad_emlrtBCI, &st);
        }
        temp = obj->QR[n];
        b_st.site = &ag_emlrtRSI;
        c = 0.0;
        s = 0.0;
        drotg(&temp_tmp, &temp, &c, &s);
        obj->QR[n - 1] = temp_tmp;
        obj->QR[n] = temp;
        QRk0 = k * 14;
        st.site = &dg_emlrtRSI;
        n = obj->ncols - k;
        if (n >= 1) {
          b_st.site = &cg_emlrtRSI;
          if (n > 2147483646) {
            c_st.site = &hb_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (b_k = 0; b_k < n; b_k++) {
            b_temp_tmp = QRk0 + b_k * 13;
            temp_tmp = obj->QR[b_temp_tmp - 1];
            temp = c * temp_tmp + s * obj->QR[b_temp_tmp];
            obj->QR[b_temp_tmp] = c * obj->QR[b_temp_tmp] - s * temp_tmp;
            obj->QR[b_temp_tmp - 1] = temp;
          }
        }
        st.site = &dg_emlrtRSI;
        n = obj->mrows;
        b_st.site = &cg_emlrtRSI;
        if (obj->mrows > 2147483646) {
          c_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (b_k = 0; b_k < n; b_k++) {
          b_temp_tmp = i + b_k;
          temp_tmp = obj->Q[b_temp_tmp + 13];
          temp = c * obj->Q[b_temp_tmp] + s * temp_tmp;
          obj->Q[b_temp_tmp + 13] = c * temp_tmp - s * obj->Q[b_temp_tmp];
          obj->Q[b_temp_tmp] = temp;
        }
      }
    }
  }
}

/* End of code generation (deleteColMoveEnd.c) */
