/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polyfit.c
 *
 * Code generation for function 'polyfit'
 *
 */

/* Include files */
#include "polyfit.h"
#include "eml_int_forloop_overflow_check.h"
#include "removePlane_ransac_data.h"
#include "removePlane_ransac_emxutil.h"
#include "removePlane_ransac_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = {
    36,        /* lineNo */
    "polyfit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" /* pathName
                                                                            */
};

static emlrtRSInfo y_emlrtRSI = {
    40,        /* lineNo */
    "polyfit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" /* pathName
                                                                            */
};

static emlrtRSInfo ab_emlrtRSI = {
    47,        /* lineNo */
    "polyfit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" /* pathName
                                                                            */
};

static emlrtRSInfo
    bb_emlrtRSI =
        {
            61,        /* lineNo */
            "qrsolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    cb_emlrtRSI =
        {
            80,        /* lineNo */
            "qrsolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    db_emlrtRSI =
        {
            85,        /* lineNo */
            "qrsolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    63,       /* lineNo */
    "xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    138,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    143,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    148,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    151,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo
    kb_emlrtRSI =
        {
            189,       /* lineNo */
            "nnzDiag", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    lb_emlrtRSI =
        {
            119,         /* lineNo */
            "LSQFromQR", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    mb_emlrtRSI =
        {
            128,         /* lineNo */
            "LSQFromQR", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    nb_emlrtRSI =
        {
            138,         /* lineNo */
            "LSQFromQR", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    31,         /* lineNo */
    "xunormqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    102,              /* lineNo */
    "ceval_xunormqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" /* pathName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    26,        /* lineNo */
    23,        /* colNo */
    "polyfit", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" /* pName
                                                                            */
};

static emlrtRTEInfo n_emlrtRTEI = {
    44,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    47,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo
    db_emlrtRTEI =
        {
            17,       /* lineNo */
            20,       /* colNo */
            "vander", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\vander.m" /* pName */
};

static emlrtRTEInfo
    eb_emlrtRTEI =
        {
            85,        /* lineNo */
            26,        /* colNo */
            "qrsolve", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pName */
};

static emlrtRTEInfo
    fb_emlrtRTEI =
        {
            119,       /* lineNo */
            5,         /* colNo */
            "qrsolve", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    32,        /* lineNo */
    1,         /* colNo */
    "polyfit", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m" /* pName
                                                                            */
};

/* Function Definitions */
void polyfit(const emlrtStack *sp, const emxArray_real_T *x,
             const emxArray_real_T *y, real_T p[2])
{
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'd', 'o', 'r', 'm', 'q', 'r'};
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 'q', 'p', '3'};
  ptrdiff_t jpvt_t[2];
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T *B;
  emxArray_real_T *V;
  real_T tau_data[2];
  const real_T *x_data;
  const real_T *y_data;
  real_T *B_data;
  real_T *V_data;
  int32_T jpvt[2];
  int32_T j;
  int32_T k;
  int32_T ma;
  int32_T maxmn;
  int32_T minmana_tmp;
  boolean_T b_p;
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
  y_data = y->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (x->size[0] != y->size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &m_emlrtRTEI,
                                  "MATLAB:polyfit:XYSizeMismatch",
                                  "MATLAB:polyfit:XYSizeMismatch", 0);
  }
  emxInit_real_T(sp, &V, 2, &gb_emlrtRTEI);
  j = V->size[0] * V->size[1];
  V->size[0] = x->size[0];
  V->size[1] = 2;
  emxEnsureCapacity_real_T(sp, V, j, &db_emlrtRTEI);
  V_data = V->data;
  if (x->size[0] != 0) {
    j = x->size[0];
    for (k = 0; k < j; k++) {
      V_data[k + V->size[0]] = 1.0;
      V_data[k] = x_data[k];
    }
  }
  st.site = &x_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  maxmn = V->size[0];
  c_st.site = &eb_emlrtRSI;
  ma = V->size[0];
  minmana_tmp = muIntScalarMin_sint32(ma, 2);
  if (V->size[0] == 0) {
    if (minmana_tmp - 1 >= 0) {
      memset(&tau_data[0], 0, (uint32_T)minmana_tmp * sizeof(real_T));
    }
    jpvt[0] = 1;
    jpvt[1] = 2;
  } else {
    jpvt_t[0] = (ptrdiff_t)0;
    jpvt_t[1] = (ptrdiff_t)0;
    info_t =
        LAPACKE_dgeqp3(102, (ptrdiff_t)V->size[0], (ptrdiff_t)2, &V_data[0],
                       (ptrdiff_t)V->size[0], &jpvt_t[0], &tau_data[0]);
    d_st.site = &fb_emlrtRSI;
    if ((int32_T)info_t != 0) {
      b_p = true;
      if ((int32_T)info_t != -4) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)info_t);
        }
      }
    } else {
      b_p = false;
    }
    if (b_p) {
      for (j = 0; j < 2; j++) {
        d_st.site = &gb_emlrtRSI;
        if (maxmn > 2147483646) {
          e_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        for (k = 0; k < maxmn; k++) {
          V_data[j * ma + k] = rtNaN;
        }
      }
      ma = minmana_tmp - 1;
      d_st.site = &hb_emlrtRSI;
      for (k = 0; k <= ma; k++) {
        tau_data[k] = rtNaN;
      }
      d_st.site = &ib_emlrtRSI;
      if (minmana_tmp + 1 <= minmana_tmp) {
        tau_data[1] = 0.0;
      }
      jpvt[0] = 1;
      jpvt[1] = 2;
    } else {
      jpvt[0] = (int32_T)jpvt_t[0];
      jpvt[1] = (int32_T)jpvt_t[1];
    }
  }
  minmana_tmp = 0;
  if (V->size[0] < 2) {
    ma = V->size[0];
    maxmn = 2;
  } else {
    ma = 2;
    maxmn = V->size[0];
  }
  if (ma > 0) {
    real_T tol;
    tol = muDoubleScalarMin(1.4901161193847656E-8,
                            2.2204460492503131E-15 * (real_T)maxmn) *
          muDoubleScalarAbs(V_data[0]);
    while ((minmana_tmp < ma) &&
           (!(muDoubleScalarAbs(
                  V_data[minmana_tmp + V->size[0] * minmana_tmp]) <= tol))) {
      minmana_tmp++;
    }
  }
  b_st.site = &cb_emlrtRSI;
  ma = 0;
  maxmn = muIntScalarMin_sint32(V->size[0], 2);
  if (maxmn > 0) {
    c_st.site = &kb_emlrtRSI;
    for (k = 0; k < maxmn; k++) {
      if (V_data[k + V->size[0] * k] != 0.0) {
        ma++;
      }
    }
  }
  b_st.site = &db_emlrtRSI;
  emxInit_real_T(&b_st, &B, 1, &eb_emlrtRTEI);
  j = B->size[0];
  B->size[0] = y->size[0];
  emxEnsureCapacity_real_T(&b_st, B, j, &eb_emlrtRTEI);
  B_data = B->data;
  maxmn = y->size[0];
  for (j = 0; j < maxmn; j++) {
    B_data[j] = y_data[j];
  }
  p[0] = 0.0;
  p[1] = 0.0;
  c_st.site = &lb_emlrtRSI;
  d_st.site = &ob_emlrtRSI;
  if ((V->size[0] != 0) && (B->size[0] != 0)) {
    info_t = (ptrdiff_t)B->size[0];
    info_t = LAPACKE_dormqr(102, 'L', 'T', info_t, (ptrdiff_t)1,
                            (ptrdiff_t)muIntScalarMin_sint32(V->size[0], 2),
                            &V_data[0], (ptrdiff_t)V->size[0], &tau_data[0],
                            &B_data[0], info_t);
    e_st.site = &pb_emlrtRSI;
    if ((int32_T)info_t != 0) {
      boolean_T c_p;
      b_p = true;
      c_p = false;
      if ((int32_T)info_t == -7) {
        c_p = true;
      } else if ((int32_T)info_t == -9) {
        c_p = true;
      } else if ((int32_T)info_t == -10) {
        c_p = true;
      }
      if (!c_p) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&e_st, &n_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &o_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &b_fname[0], 12,
              (int32_T)info_t);
        }
      }
    } else {
      b_p = false;
    }
    if (b_p) {
      maxmn = B->size[0];
      j = B->size[0];
      B->size[0] = maxmn;
      emxEnsureCapacity_real_T(&d_st, B, j, &fb_emlrtRTEI);
      B_data = B->data;
      for (j = 0; j < maxmn; j++) {
        B_data[j] = rtNaN;
      }
    }
  }
  c_st.site = &mb_emlrtRSI;
  for (k = 0; k < ma; k++) {
    p[jpvt[k] - 1] = B_data[k];
  }
  emxFree_real_T(&b_st, &B);
  for (j = ma; j >= 1; j--) {
    maxmn = jpvt[j - 1] - 1;
    p[maxmn] /= V_data[(j + V->size[0] * (j - 1)) - 1];
    c_st.site = &nb_emlrtRSI;
    for (k = 0; k <= j - 2; k++) {
      p[jpvt[0] - 1] -= p[maxmn] * V_data[V->size[0] * (j - 1)];
    }
  }
  emxFree_real_T(&b_st, &V);
  if (x->size[0] <= 1) {
    st.site = &y_emlrtRSI;
    warning(&st);
  } else if (minmana_tmp <= 1) {
    st.site = &ab_emlrtRSI;
    b_warning(&st);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (polyfit.c) */
