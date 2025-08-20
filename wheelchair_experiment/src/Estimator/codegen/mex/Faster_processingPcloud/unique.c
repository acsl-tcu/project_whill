/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unique.c
 *
 * Code generation for function 'unique'
 *
 */

/* Include files */
#include "unique.h"
#include "Faster_processingPcloud_data.h"
#include "Faster_processingPcloud_emxutil.h"
#include "Faster_processingPcloud_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo di_emlrtRSI = {
    164,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRSInfo ei_emlrtRSI = {
    166,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRSInfo fi_emlrtRSI = {
    210,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRSInfo gi_emlrtRSI = {
    234,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRSInfo hi_emlrtRSI = {
    242,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRSInfo ii_emlrtRSI = {
    248,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRSInfo ji_emlrtRSI = {
    145,       /* lineNo */
    "sortIdx", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    ki_emlrtRSI =
        {
            57,          /* lineNo */
            "mergesort", /* fcnName */
            "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pathName */
};

static emlrtRSInfo
    li_emlrtRSI =
        {
            113,         /* lineNo */
            "mergesort", /* fcnName */
            "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pathName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    241,                                                           /* lineNo */
    1,                                                             /* colNo */
    "unique_vector",                                               /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pName */
};

static emlrtRTEInfo se_emlrtRTEI = {
    164,                                                           /* lineNo */
    1,                                                             /* colNo */
    "unique",                                                      /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pName */
};

static emlrtRTEInfo
    te_emlrtRTEI =
        {
            52,          /* lineNo */
            9,           /* colNo */
            "mergesort", /* fName */
            "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = {
    165,                                                           /* lineNo */
    20,                                                            /* colNo */
    "unique",                                                      /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = {
    242,                                                           /* lineNo */
    1,                                                             /* colNo */
    "unique",                                                      /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pName */
};

static emlrtRTEInfo
    we_emlrtRTEI =
        {
            52,          /* lineNo */
            1,           /* colNo */
            "mergesort", /* fName */
            "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pName */
};

/* Function Definitions */
void unique_vector(const emlrtStack *sp, const emxArray_uint32_T *a,
                   emxArray_uint32_T *b)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  int32_T iv[2];
  int32_T b_a;
  int32_T b_i;
  int32_T i;
  int32_T k;
  int32_T n;
  int32_T na_tmp;
  int32_T pEnd;
  int32_T qEnd;
  int32_T *idx_data;
  int32_T *iwork_data;
  const uint32_T *a_data;
  uint32_T *b_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  a_data = a->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  na_tmp = a->size[0];
  st.site = &di_emlrtRSI;
  n = a->size[0] + 1;
  emxInit_int32_T(&st, &idx, 1, &se_emlrtRTEI);
  i = idx->size[0];
  idx->size[0] = a->size[0];
  emxEnsureCapacity_int32_T(&st, idx, i, &se_emlrtRTEI);
  idx_data = idx->data;
  for (i = 0; i < na_tmp; i++) {
    idx_data[i] = 0;
  }
  if (a->size[0] != 0) {
    b_st.site = &ji_emlrtRSI;
    emxInit_int32_T(&b_st, &iwork, 1, &we_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = a->size[0];
    emxEnsureCapacity_int32_T(&b_st, iwork, i, &te_emlrtRTEI);
    iwork_data = iwork->data;
    b_i = a->size[0] - 1;
    c_st.site = &ki_emlrtRSI;
    if (a->size[0] - 1 > 2147483645) {
      d_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 1; k <= b_i; k += 2) {
      if (a_data[k - 1] <= a_data[k]) {
        idx_data[k - 1] = k;
        idx_data[k] = k + 1;
      } else {
        idx_data[k - 1] = k + 1;
        idx_data[k] = k;
      }
    }
    if (((uint32_T)a->size[0] & 1U) != 0U) {
      idx_data[a->size[0] - 1] = a->size[0];
    }
    b_i = 2;
    while (b_i < n - 1) {
      int32_T i2;
      int32_T j;
      i2 = b_i << 1;
      j = 1;
      for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
        int32_T kEnd;
        int32_T p;
        int32_T q;
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          i = idx_data[q - 1];
          b_a = idx_data[p - 1];
          if (a_data[b_a - 1] <= a_data[i - 1]) {
            iwork_data[k] = b_a;
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork_data[k] = idx_data[q - 1];
                q++;
              }
            }
          } else {
            iwork_data[k] = i;
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork_data[k] = idx_data[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        c_st.site = &li_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          idx_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      b_i = i2;
    }
    emxFree_int32_T(&b_st, &iwork);
  }
  i = b->size[0];
  b->size[0] = a->size[0];
  emxEnsureCapacity_uint32_T(sp, b, i, &ue_emlrtRTEI);
  b_data = b->data;
  st.site = &ei_emlrtRSI;
  if (a->size[0] > 2147483646) {
    b_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < na_tmp; k++) {
    b_data[k] = a_data[idx_data[k] - 1];
  }
  emxFree_int32_T(sp, &idx);
  b_i = 0;
  k = 0;
  while (k + 1 <= na_tmp) {
    uint32_T x;
    x = b_data[k];
    b_a = k;
    do {
      k++;
    } while (!((k + 1 > na_tmp) || (b_data[k] != x)));
    b_i++;
    b_data[b_i - 1] = x;
    st.site = &fi_emlrtRSI;
    if ((b_a + 1 <= k) && (k > 2147483646)) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }
  st.site = &gi_emlrtRSI;
  if (b_i > a->size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &bb_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (b_i < 1) {
    i = 0;
  } else {
    i = b_i;
  }
  iv[0] = 1;
  iv[1] = i;
  st.site = &hi_emlrtRSI;
  indexShapeCheck(&st, b->size[0], iv);
  b_a = b->size[0];
  b->size[0] = i;
  emxEnsureCapacity_uint32_T(sp, b, b_a, &ve_emlrtRTEI);
  st.site = &ii_emlrtRSI;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (unique.c) */
