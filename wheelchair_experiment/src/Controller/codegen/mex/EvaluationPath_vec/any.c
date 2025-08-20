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
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "allOrAny.h"
#include "eml_int_forloop_overflow_check.h"
#include "permute.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = {
    16,                                                         /* lineNo */
    "any",                                                      /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/any.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    57,         /* lineNo */
    "allOrAny", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pathName
                                                                            */
};

static emlrtRSInfo rb_emlrtRSI = {
    81,                    /* lineNo */
    "applyToMultipleDims", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    83,                    /* lineNo */
    "applyToMultipleDims", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    97,                    /* lineNo */
    "applyToMultipleDims", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    27,         /* lineNo */
    "ipermute", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/ipermute.m" /* pathName
                                                                        */
};

static emlrtRTEInfo ld_emlrtRTEI = {
    16,                                                         /* lineNo */
    5,                                                          /* colNo */
    "any",                                                      /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/any.m" /* pName */
};

static emlrtRTEInfo md_emlrtRTEI = {
    41,                    /* lineNo */
    13,                    /* colNo */
    "applyToMultipleDims", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = {
    81,                    /* lineNo */
    14,                    /* colNo */
    "applyToMultipleDims", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pName */
};

/* Function Definitions */
void any(const emlrtStack *sp, const emxArray_boolean_T *x,
         emxArray_boolean_T *y)
{
  cell_wrap_7 outputs;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_boolean_T r1;
  emxArray_boolean_T *r;
  int32_T b_m[2];
  int32_T m;
  int32_T m_tmp;
  int32_T n;
  int32_T nx;
  boolean_T b;
  boolean_T *y_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &pb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  m = (x->size[1] << 2) * x->size[2];
  emxInit_boolean_T(&b_st, &r, 4, &nd_emlrtRTEI);
  c_st.site = &rb_emlrtRSI;
  permute(&c_st, x, r);
  c_st.site = &rb_emlrtRSI;
  nx = (r->size[1] << 2) * r->size[2] * r->size[3];
  d_st.site = &cb_emlrtRSI;
  e_st.site = &db_emlrtRSI;
  e_st.site = &db_emlrtRSI;
  n = 4;
  if (r->size[1] > 4) {
    n = r->size[1];
  }
  if (r->size[2] > n) {
    n = r->size[2];
  }
  if (r->size[3] > n) {
    n = r->size[3];
  }
  n = muIntScalarMax_sint32(nx, n);
  if (m > n) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (x->size[3] > n) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (m < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if (m * x->size[3] != nx) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  emxInitMatrix_cell_wrap_7(&b_st, &outputs, &md_emlrtRTEI);
  c_st.site = &sb_emlrtRSI;
  m_tmp = x->size[3];
  n = x->size[3];
  r1 = *r;
  b_m[0] = m;
  b_m[1] = n;
  r1.size = &b_m[0];
  r1.numDimensions = 2;
  d_st.site = &ub_emlrtRSI;
  allOrAny_anonFcn1(&d_st, &r1, outputs.f1);
  emxFree_boolean_T(&c_st, &r);
  c_st.site = &tb_emlrtRSI;
  nx = outputs.f1->size[1];
  d_st.site = &cb_emlrtRSI;
  e_st.site = &db_emlrtRSI;
  n = 1;
  if (outputs.f1->size[1] > 1) {
    n = outputs.f1->size[1];
  }
  if (x->size[3] > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (outputs.f1->size[1] != x->size[3]) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  c_st.site = &tb_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  b = true;
  if (x->size[3] != 0) {
    boolean_T exitg1;
    n = 0;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 4)) {
      uint32_T uv[4];
      uv[0] = 1U;
      uv[1] = 1U;
      uv[2] = 1U;
      uv[3] = (uint32_T)x->size[3];
      if ((int32_T)uv[nx] != 1) {
        if (n > nx + 1) {
          b = false;
          exitg1 = true;
        } else {
          n = nx + 1;
          nx++;
        }
      } else {
        nx++;
      }
    }
  }
  if (b) {
    e_st.site = &kb_emlrtRSI;
    f_st.site = &cb_emlrtRSI;
    n = 1;
    if (x->size[3] > 1) {
      n = x->size[3];
    }
    if (x->size[3] > muIntScalarMax_sint32(m_tmp, n)) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    n = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = 1;
    y->size[3] = x->size[3];
    emxEnsureCapacity_boolean_T(&d_st, y, n, &ld_emlrtRTEI);
    y_data = y->data;
    for (n = 0; n < m_tmp; n++) {
      y_data[n] = outputs.f1->data[n];
    }
  } else {
    e_st.site = &lb_emlrtRSI;
    f_st.site = &cb_emlrtRSI;
    n = 1;
    if (x->size[3] > 1) {
      n = x->size[3];
    }
    if (x->size[3] > muIntScalarMax_sint32(m_tmp, n)) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    n = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = 1;
    y->size[3] = x->size[3];
    emxEnsureCapacity_boolean_T(&d_st, y, n, &kd_emlrtRTEI);
    y_data = y->data;
    e_st.site = &mb_emlrtRSI;
    f_st.site = &nb_emlrtRSI;
    if (x->size[3] > 2147483646) {
      g_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&g_st);
    }
    for (nx = 0; nx < m_tmp; nx++) {
      y_data[nx] = outputs.f1->data[nx];
    }
  }
  emxFreeMatrix_cell_wrap_7(&d_st, &outputs);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void b_any(const emlrtStack *sp, const emxArray_boolean_T *x,
           emxArray_boolean_T *y)
{
  cell_wrap_7 outputs;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T r1;
  emxArray_boolean_T *r;
  int32_T b_m[2];
  int32_T k;
  int32_T m;
  int32_T n;
  int32_T n_tmp;
  int32_T nx;
  int32_T subsa_idx_3;
  int32_T unnamed_idx_2;
  boolean_T b;
  boolean_T *y_data;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &pb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  m = x->size[1] << 2;
  n_tmp = x->size[2] * x->size[3];
  emxInit_boolean_T(&b_st, &r, 4, &nd_emlrtRTEI);
  c_st.site = &rb_emlrtRSI;
  permute(&c_st, x, r);
  c_st.site = &rb_emlrtRSI;
  nx = (r->size[1] << 2) * r->size[2] * r->size[3];
  d_st.site = &cb_emlrtRSI;
  e_st.site = &db_emlrtRSI;
  e_st.site = &db_emlrtRSI;
  n = 4;
  if (r->size[1] > 4) {
    n = r->size[1];
  }
  if (r->size[2] > n) {
    n = r->size[2];
  }
  if (r->size[3] > n) {
    n = r->size[3];
  }
  n = muIntScalarMax_sint32(nx, n);
  if (m > n) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (n_tmp > n) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (n_tmp < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if (m * n_tmp != nx) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  emxInitMatrix_cell_wrap_7(&b_st, &outputs, &md_emlrtRTEI);
  c_st.site = &sb_emlrtRSI;
  r1 = *r;
  b_m[0] = m;
  b_m[1] = n_tmp;
  r1.size = &b_m[0];
  r1.numDimensions = 2;
  d_st.site = &ub_emlrtRSI;
  allOrAny_anonFcn1(&d_st, &r1, outputs.f1);
  emxFree_boolean_T(&c_st, &r);
  nx = x->size[2];
  c_st.site = &tb_emlrtRSI;
  m = outputs.f1->size[1];
  d_st.site = &cb_emlrtRSI;
  e_st.site = &db_emlrtRSI;
  e_st.site = &db_emlrtRSI;
  n = 1;
  if (outputs.f1->size[1] > 1) {
    n = outputs.f1->size[1];
  }
  n = muIntScalarMax_sint32(m, n);
  if (x->size[2] > n) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (x->size[3] > n) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (n_tmp != outputs.f1->size[1]) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  c_st.site = &tb_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  b = true;
  if ((x->size[2] != 0) && (x->size[3] != 0)) {
    boolean_T exitg1;
    m = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      uint32_T uv[4];
      uv[0] = 1U;
      uv[1] = 1U;
      uv[2] = (uint32_T)nx;
      uv[3] = (uint32_T)x->size[3];
      if ((int32_T)uv[k] != 1) {
        if (m > k + 1) {
          b = false;
          exitg1 = true;
        } else {
          m = k + 1;
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b) {
    e_st.site = &kb_emlrtRSI;
    f_st.site = &cb_emlrtRSI;
    g_st.site = &db_emlrtRSI;
    g_st.site = &db_emlrtRSI;
    n = 1;
    if (x->size[2] > 1) {
      n = x->size[2];
    }
    if (x->size[3] > n) {
      n = x->size[3];
    }
    n = muIntScalarMax_sint32(n_tmp, n);
    if (x->size[2] > n) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > n) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    n = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = x->size[2];
    y->size[3] = x->size[3];
    emxEnsureCapacity_boolean_T(&d_st, y, n, &ld_emlrtRTEI);
    y_data = y->data;
    for (n = 0; n < n_tmp; n++) {
      y_data[n] = outputs.f1->data[n];
    }
  } else {
    e_st.site = &lb_emlrtRSI;
    f_st.site = &cb_emlrtRSI;
    g_st.site = &db_emlrtRSI;
    g_st.site = &db_emlrtRSI;
    n = 1;
    if (x->size[2] > 1) {
      n = x->size[2];
    }
    if (x->size[3] > n) {
      n = x->size[3];
    }
    n = muIntScalarMax_sint32(n_tmp, n);
    if (x->size[2] > n) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > n) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    n = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = x->size[2];
    m = x->size[3];
    y->size[3] = x->size[3];
    emxEnsureCapacity_boolean_T(&d_st, y, n, &kd_emlrtRTEI);
    y_data = y->data;
    e_st.site = &mb_emlrtRSI;
    f_st.site = &nb_emlrtRSI;
    if (x->size[3] > 2147483646) {
      g_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&g_st);
    }
    for (k = 0; k < m; k++) {
      f_st.site = &ob_emlrtRSI;
      g_st.site = &nb_emlrtRSI;
      if (nx > 2147483646) {
        h_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }
      if (nx - 1 >= 0) {
        subsa_idx_3 = k + 1;
        unnamed_idx_2 = nx;
      }
      for (n = 0; n < nx; n++) {
        y_data[n + y->size[2] * (subsa_idx_3 - 1)] =
            outputs.f1->data[n + unnamed_idx_2 * (subsa_idx_3 - 1)];
      }
    }
  }
  emxFreeMatrix_cell_wrap_7(&d_st, &outputs);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (any.c) */
