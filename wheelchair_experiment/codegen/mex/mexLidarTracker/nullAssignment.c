/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.c
 *
 * Code generation for function 'nullAssignment'
 *
 */

/* Include files */
#include "nullAssignment.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo oib_emlrtRSI =
    {
        167,                      /* lineNo */
        "onearg_null_assignment", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pathName */
};

static emlrtRSInfo pib_emlrtRSI =
    {
        169,                      /* lineNo */
        "onearg_null_assignment", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pathName */
};

static emlrtRSInfo qib_emlrtRSI =
    {
        172,                      /* lineNo */
        "onearg_null_assignment", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pathName */
};

static emlrtRSInfo rib_emlrtRSI =
    {
        258,             /* lineNo */
        "make_bitarray", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pathName */
};

static emlrtRSInfo sib_emlrtRSI =
    {
        132,        /* lineNo */
        "num_true", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pathName */
};

static emlrtRTEInfo ld_emlrtRTEI =
    {
        85,                /* lineNo */
        27,                /* colNo */
        "validate_inputs", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pName */
};

static emlrtRTEInfo nd_emlrtRTEI =
    {
        184,                      /* lineNo */
        9,                        /* colNo */
        "onearg_null_assignment", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pName */
};

static emlrtRTEInfo oo_emlrtRTEI =
    {
        167,              /* lineNo */
        9,                /* colNo */
        "nullAssignment", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pName */
};

static emlrtRTEInfo po_emlrtRTEI =
    {
        17,               /* lineNo */
        9,                /* colNo */
        "nullAssignment", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pName */
};

static emlrtRTEInfo qo_emlrtRTEI =
    {
        165,              /* lineNo */
        9,                /* colNo */
        "nullAssignment", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pName */
};

/* Function Definitions */
void nullAssignment(const emlrtStack *sp, emxArray_int32_T *x,
                    const emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_boolean_T *b;
  const int32_T *idx_data;
  int32_T k;
  int32_T k0;
  int32_T nxin;
  int32_T nxout;
  int32_T *x_data;
  boolean_T exitg1;
  boolean_T p;
  boolean_T *b_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  idx_data = idx->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &vhb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx->size[1] - 1)) {
    if (idx_data[k] > x->size[1]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &ld_emlrtRTEI,
                                  "MATLAB:subsdeldimmismatch",
                                  "MATLAB:subsdeldimmismatch", 0);
  }
  st.site = &whb_emlrtRSI;
  nxin = x->size[1];
  b_st.site = &oib_emlrtRSI;
  emxInit_boolean_T(&b_st, &b, 2, &qo_emlrtRTEI, true);
  k = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = x->size[1];
  emxEnsureCapacity_boolean_T(&b_st, b, k, &oo_emlrtRTEI);
  b_data = b->data;
  k0 = x->size[1];
  for (k = 0; k < k0; k++) {
    b_data[k] = false;
  }
  k0 = idx->size[1];
  c_st.site = &rib_emlrtRSI;
  if (idx->size[1] > 2147483646) {
    d_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < k0; k++) {
    b_data[idx_data[k] - 1] = true;
  }
  b_st.site = &pib_emlrtRSI;
  nxout = 0;
  k0 = b->size[1];
  c_st.site = &sib_emlrtRSI;
  if (b->size[1] > 2147483646) {
    d_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < k0; k++) {
    nxout += b_data[k];
  }
  nxout = x->size[1] - nxout;
  k0 = -1;
  b_st.site = &qib_emlrtRSI;
  if (x->size[1] > 2147483646) {
    c_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b->size[1]) || (!b_data[k])) {
      k0++;
      x_data[k0] = x_data[k];
    }
  }
  emxFree_boolean_T(&st, &b);
  if (nxout > x->size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &nd_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  k = x->size[0] * x->size[1];
  if (nxout < 1) {
    x->size[1] = 0;
  } else {
    x->size[1] = nxout;
  }
  emxEnsureCapacity_int32_T(&st, x, k, &po_emlrtRTEI);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (nullAssignment.c) */
