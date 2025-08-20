/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * any.c
 *
 * Code generation for function 'any'
 *
 */

/* Include files */
#include "any.h"
#include "EvaluationPath_data.h"
#include "EvaluationPath_emxutil.h"
#include "EvaluationPath_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_cell_wrap_7
#define typedef_cell_wrap_7
typedef struct {
  boolean_T f1[1000];
} cell_wrap_7;
#endif /* typedef_cell_wrap_7 */

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = {
    56,        /* lineNo */
    "permute", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

static emlrtRSInfo y_emlrtRSI = {
    60,        /* lineNo */
    "permute", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

static emlrtRSInfo ab_emlrtRSI = {
    66,        /* lineNo */
    "permute", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

static emlrtRSInfo bb_emlrtRSI = {
    85,       /* lineNo */
    "looper", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

static emlrtRSInfo cb_emlrtRSI = {
    84,       /* lineNo */
    "looper", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

static emlrtRSInfo db_emlrtRSI = {
    16,                                                         /* lineNo */
    "any",                                                      /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/any.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    57,         /* lineNo */
    "allOrAny", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pathName
                                                                            */
};

static emlrtRSInfo fb_emlrtRSI = {
    81,                    /* lineNo */
    "applyToMultipleDims", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    83,                    /* lineNo */
    "applyToMultipleDims", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    56,                                                             /* lineNo */
    "@(x)coder.internal.allOrAny(op,x,coder.internal.indexInt(1))", /* fcnName
                                                                     */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pathName
                                                                            */
};

static emlrtRSInfo jb_emlrtRSI = {
    143,        /* lineNo */
    "allOrAny", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pathName
                                                                            */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    81,                    /* lineNo */
    22,                    /* colNo */
    "applyToMultipleDims", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    81,                    /* lineNo */
    14,                    /* colNo */
    "applyToMultipleDims", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pName */
};

/* Function Definitions */
void any(const emlrtStack *sp, const emxArray_boolean_T *x, boolean_T y[1000])
{
  cell_wrap_7 outputs;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_boolean_T *r;
  int32_T b_k;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T m_tmp;
  int32_T n;
  int32_T plast;
  const boolean_T *x_data;
  boolean_T exitg1;
  boolean_T overflow;
  boolean_T *r1;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &db_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  m_tmp = 24 * x->size[2];
  c_st.site = &fb_emlrtRSI;
  overflow = true;
  if (x->size[2] != 0) {
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (x->size[k] != 1) {
        if (plast > k + 1) {
          overflow = false;
          exitg1 = true;
        } else {
          plast = k + 1;
          k++;
        }
      } else {
        k++;
      }
    }
  }
  emxInit_boolean_T(&c_st, &r, 4, &dc_emlrtRTEI);
  if (overflow) {
    d_st.site = &x_emlrtRSI;
    plast = m_tmp * 1000;
    e_st.site = &p_emlrtRSI;
    f_st.site = &q_emlrtRSI;
    n = 6;
    if (x->size[2] > 6) {
      n = x->size[2];
    }
    if (n < 1000) {
      n = 1000;
    }
    if (x->size[2] > muIntScalarMax_sint32(plast, n)) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    i = r->size[0] * r->size[1] * r->size[2] * r->size[3];
    r->size[0] = 4;
    r->size[1] = 6;
    r->size[2] = x->size[2];
    r->size[3] = 1000;
    emxEnsureCapacity_boolean_T(&c_st, r, i, &cc_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < plast; i++) {
      r1[i] = x_data[i];
    }
  } else {
    d_st.site = &y_emlrtRSI;
    plast = m_tmp * 1000;
    e_st.site = &p_emlrtRSI;
    f_st.site = &q_emlrtRSI;
    n = 6;
    if (x->size[2] > 6) {
      n = x->size[2];
    }
    if (n < 1000) {
      n = 1000;
    }
    if (x->size[2] > muIntScalarMax_sint32(plast, n)) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    i = r->size[0] * r->size[1] * r->size[2] * r->size[3];
    r->size[0] = 4;
    r->size[1] = 6;
    plast = x->size[2];
    r->size[2] = x->size[2];
    r->size[3] = 1000;
    emxEnsureCapacity_boolean_T(&c_st, r, i, &bc_emlrtRTEI);
    r1 = r->data;
    d_st.site = &ab_emlrtRSI;
    overflow = (x->size[2] > 2147483646);
    for (k = 0; k < 1000; k++) {
      e_st.site = &bb_emlrtRSI;
      f_st.site = &cb_emlrtRSI;
      if (overflow) {
        g_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }
      if (plast - 1 >= 0) {
        i1 = k + 1;
      }
      for (n = 0; n < plast; n++) {
        for (b_k = 0; b_k < 6; b_k++) {
          i = 4 * b_k + 24 * n;
          r1[i + 24 * r->size[2] * (i1 - 1)] =
              x_data[i + 24 * x->size[2] * (i1 - 1)];
          r1[((4 * b_k + 24 * n) + 24 * r->size[2] * (i1 - 1)) + 1] =
              x_data[((4 * b_k + 24 * n) + 24 * x->size[2] * (i1 - 1)) + 1];
          r1[((4 * b_k + 24 * n) + 24 * r->size[2] * (i1 - 1)) + 2] =
              x_data[((4 * b_k + 24 * n) + 24 * x->size[2] * (i1 - 1)) + 2];
          r1[((4 * b_k + 24 * n) + 24 * r->size[2] * (i1 - 1)) + 3] =
              x_data[((4 * b_k + 24 * n) + 24 * x->size[2] * (i1 - 1)) + 3];
        }
      }
    }
  }
  c_st.site = &fb_emlrtRSI;
  plast = m_tmp * 1000;
  d_st.site = &p_emlrtRSI;
  e_st.site = &q_emlrtRSI;
  n = 6;
  if (r->size[2] > 6) {
    n = r->size[2];
  }
  if (n < 1000) {
    n = 1000;
  }
  if (m_tmp > muIntScalarMax_sint32(plast, n)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (m_tmp < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if (m_tmp * 1000 != plast) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  c_st.site = &gb_emlrtRSI;
  d_st.site = &hb_emlrtRSI;
  e_st.site = &ib_emlrtRSI;
  memset(&outputs.f1[0], 0, 1000U * sizeof(boolean_T));
  plast = 0;
  for (b_k = 0; b_k < 1000; b_k++) {
    n = plast + m_tmp;
    i1 = plast + 1;
    plast = n;
    f_st.site = &jb_emlrtRSI;
    if ((i1 <= n) && (n > 2147483646)) {
      g_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&g_st);
    }
    exitg1 = false;
    while ((!exitg1) && (i1 <= n)) {
      if (r1[i1 - 1]) {
        outputs.f1[b_k] = true;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
  emxFree_boolean_T(&e_st, &r);
  memcpy(&y[0], &outputs.f1[0], 1000U * sizeof(boolean_T));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (any.c) */
