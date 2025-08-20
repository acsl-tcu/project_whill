/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxuniquecounts.c
 *
 * Code generation for function 'maxuniquecounts'
 *
 */

/* Include files */
#include "maxuniquecounts.h"
#include "combineVectorElements.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"

/* Variable Definitions */
static emlrtRSInfo yhb_emlrtRSI = {
    15,                /* lineNo */
    "maxuniquecounts", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "maxuniquecounts.m" /* pathName */
};

static emlrtRSInfo aib_emlrtRSI = {
    16,                /* lineNo */
    "maxuniquecounts", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "maxuniquecounts.m" /* pathName */
};

static emlrtRSInfo bib_emlrtRSI = {
    20,             /* lineNo */
    "uniquecounts", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "uniquecounts.m" /* pathName */
};

static emlrtRSInfo cib_emlrtRSI = {
    22,             /* lineNo */
    "uniquecounts", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "uniquecounts.m" /* pathName */
};

static emlrtRSInfo dib_emlrtRSI = {
    24,             /* lineNo */
    "uniquecounts", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "uniquecounts.m" /* pathName */
};

static emlrtRSInfo eib_emlrtRSI = {
    41,                                                            /* lineNo */
    "unique",                                                      /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRSInfo fib_emlrtRSI = {
    35,                                         /* lineNo */
    "StrictSingleCoderUtilities/IntLogicalSum", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/+codegen/StrictSingleCoderU"
    "tilities.m" /* pathName */
};

static emlrtRSInfo hib_emlrtRSI =
    {
        312,                     /* lineNo */
        "unaryMinOrMaxDispatch", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtBCInfo dg_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    24,             /* lineNo */
    109,            /* colNo */
    "",             /* aName */
    "uniquecounts", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "uniquecounts.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo eg_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    24,             /* lineNo */
    15,             /* colNo */
    "",             /* aName */
    "uniquecounts", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "uniquecounts.m", /* pName */
    0                 /* checkKind */
};

static emlrtRTEInfo am_emlrtRTEI = {
    15,                /* lineNo */
    5,                 /* colNo */
    "maxuniquecounts", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "maxuniquecounts.m" /* pName */
};

static emlrtRTEInfo bm_emlrtRTEI = {
    24,             /* lineNo */
    102,            /* colNo */
    "uniquecounts", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "uniquecounts.m" /* pName */
};

static emlrtRTEInfo cm_emlrtRTEI = {
    1,                 /* lineNo */
    21,                /* colNo */
    "maxuniquecounts", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "maxuniquecounts.m" /* pName */
};

/* Function Definitions */
int32_T maxuniquecounts(const emlrtStack *sp, const emxArray_int32_T *A)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_boolean_T *in;
  emxArray_int32_T *b;
  emxArray_int32_T *count;
  emxArray_int32_T *idx;
  const int32_T *A_data;
  int32_T b_i;
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T maxcount;
  int32_T na;
  int32_T *b_data;
  int32_T *idx_data;
  boolean_T *in_data;
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
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (A->size[1] == 0) {
    maxcount = 0;
  } else {
    int32_T nb;
    int32_T x;
    st.site = &yhb_emlrtRSI;
    b_st.site = &bib_emlrtRSI;
    c_st.site = &eib_emlrtRSI;
    na = A->size[1];
    emxInit_int32_T(&c_st, &idx, 2, &fh_emlrtRTEI);
    d_st.site = &gj_emlrtRSI;
    sortIdx(&d_st, A, idx);
    idx_data = idx->data;
    emxInit_int32_T(&c_st, &b, 2, &cm_emlrtRTEI);
    i = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = A->size[1];
    emxEnsureCapacity_int32_T(&c_st, b, i, &hh_emlrtRTEI);
    b_data = b->data;
    d_st.site = &hj_emlrtRSI;
    if (A->size[1] > 2147483646) {
      e_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (k = 0; k < na; k++) {
      b_data[k] = A_data[idx_data[k] - 1];
    }
    emxFree_int32_T(&c_st, &idx);
    nb = 0;
    k = 0;
    while (k + 1 <= na) {
      x = b_data[k];
      b_i = k;
      do {
        k++;
      } while (!((k + 1 > na) || (b_data[k] != x)));
      nb++;
      b_data[nb - 1] = x;
      d_st.site = &ij_emlrtRSI;
      if ((b_i + 1 <= k) && (k > 2147483646)) {
        e_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
    }
    d_st.site = &kj_emlrtRSI;
    if (nb > A->size[1]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &jb_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    i = b->size[0] * b->size[1];
    if (nb < 1) {
      b->size[1] = 0;
    } else {
      b->size[1] = nb;
    }
    emxEnsureCapacity_int32_T(&c_st, b, i, &ih_emlrtRTEI);
    b_data = b->data;
    d_st.site = &mj_emlrtRSI;
    b_st.site = &cib_emlrtRSI;
    c_st.site = &ib_emlrtRSI;
    emxInit_int32_T(&b_st, &count, 1, &am_emlrtRTEI);
    i = count->size[0];
    count->size[0] = b->size[1];
    emxEnsureCapacity_int32_T(&b_st, count, i, &am_emlrtRTEI);
    idx_data = count->data;
    x = b->size[1];
    for (i = 0; i < x; i++) {
      idx_data[i] = 1;
    }
    i = b->size[1];
    if (b->size[1] - 1 >= 0) {
      loop_ub = A->size[1];
    }
    emxInit_boolean_T(&st, &in, 2, &bm_emlrtRTEI, true);
    for (b_i = 0; b_i < i; b_i++) {
      b_st.site = &dib_emlrtRSI;
      na = in->size[0] * in->size[1];
      in->size[0] = 1;
      in->size[1] = A->size[1];
      emxEnsureCapacity_boolean_T(&b_st, in, na, &bm_emlrtRTEI);
      in_data = in->data;
      if (b_i + 1 > b->size[1]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, b->size[1], &dg_emlrtBCI,
                                      &b_st);
      }
      x = b_data[b_i];
      for (na = 0; na < loop_ub; na++) {
        in_data[na] = (A_data[na] == x);
      }
      c_st.site = &fib_emlrtRSI;
      d_st.site = &uh_emlrtRSI;
      if (b_i + 1 > count->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, count->size[0], &eg_emlrtBCI,
                                      &d_st);
      }
      e_st.site = &vh_emlrtRSI;
      idx_data[b_i] = combineVectorElements(&e_st, in);
    }
    emxFree_boolean_T(&st, &in);
    emxFree_int32_T(&st, &b);
    st.site = &aib_emlrtRSI;
    b_st.site = &lf_emlrtRSI;
    c_st.site = &mf_emlrtRSI;
    d_st.site = &nf_emlrtRSI;
    if (count->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &eb_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &gib_emlrtRSI;
    x = count->size[0];
    f_st.site = &hib_emlrtRSI;
    maxcount = idx_data[0];
    for (k = 2; k <= x; k++) {
      i = idx_data[k - 1];
      if (maxcount < i) {
        maxcount = i;
      }
    }
    emxFree_int32_T(&f_st, &count);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return maxcount;
}

/* End of code generation (maxuniquecounts.c) */
