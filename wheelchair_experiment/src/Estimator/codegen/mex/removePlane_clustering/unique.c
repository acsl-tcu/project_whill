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
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo gh_emlrtRSI = {
    164,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo hh_emlrtRSI = {
    166,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo ih_emlrtRSI = {
    234,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo jh_emlrtRSI = {
    242,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo kh_emlrtRSI = {
    248,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo
    lh_emlrtRSI =
        {
            145,       /* lineNo */
            "sortIdx", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo mh_emlrtRSI =
    {
        57,          /* lineNo */
        "mergesort", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" /* pathName */
};

static emlrtRSInfo nh_emlrtRSI =
    {
        113,         /* lineNo */
        "mergesort", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" /* pathName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    241,             /* lineNo */
    1,               /* colNo */
    "unique_vector", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pName
                                                                       */
};

static emlrtRTEInfo je_emlrtRTEI = {
    164,      /* lineNo */
    1,        /* colNo */
    "unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pName
                                                                       */
};

static emlrtRTEInfo ke_emlrtRTEI =
    {
        52,          /* lineNo */
        9,           /* colNo */
        "mergesort", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" /* pName */
};

static emlrtRTEInfo le_emlrtRTEI = {
    165,      /* lineNo */
    20,       /* colNo */
    "unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pName
                                                                       */
};

static emlrtRTEInfo me_emlrtRTEI = {
    242,      /* lineNo */
    1,        /* colNo */
    "unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pName
                                                                       */
};

static emlrtRTEInfo ne_emlrtRTEI =
    {
        52,          /* lineNo */
        1,           /* colNo */
        "mergesort", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" /* pName */
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
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T n;
  int32_T na;
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
  na = a->size[0];
  st.site = &gh_emlrtRSI;
  n = a->size[0] + 1;
  emxInit_int32_T(&st, &idx, 1, &je_emlrtRTEI);
  i = idx->size[0];
  idx->size[0] = a->size[0];
  emxEnsureCapacity_int32_T(&st, idx, i, &je_emlrtRTEI);
  idx_data = idx->data;
  b_i = a->size[0];
  for (i = 0; i < b_i; i++) {
    idx_data[i] = 0;
  }
  if (a->size[0] != 0) {
    b_st.site = &lh_emlrtRSI;
    emxInit_int32_T(&b_st, &iwork, 1, &ne_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = a->size[0];
    emxEnsureCapacity_int32_T(&b_st, iwork, i, &ke_emlrtRTEI);
    iwork_data = iwork->data;
    b_i = a->size[0] - 1;
    c_st.site = &mh_emlrtRSI;
    if (a->size[0] - 1 > 2147483645) {
      d_st.site = &x_emlrtRSI;
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
    if ((a->size[0] & 1) != 0) {
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
          i = idx_data[p - 1];
          i1 = idx_data[q - 1];
          if (a_data[i - 1] <= a_data[i1 - 1]) {
            iwork_data[k] = i;
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork_data[k] = idx_data[q - 1];
                q++;
              }
            }
          } else {
            iwork_data[k] = i1;
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
        c_st.site = &nh_emlrtRSI;
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
  emxEnsureCapacity_uint32_T(sp, b, i, &le_emlrtRTEI);
  b_data = b->data;
  st.site = &hh_emlrtRSI;
  if (a->size[0] > 2147483646) {
    b_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < na; k++) {
    b_data[k] = a_data[idx_data[k] - 1];
  }
  emxFree_int32_T(sp, &idx);
  b_i = 0;
  k = 1;
  while (k <= na) {
    uint32_T x;
    x = b_data[k - 1];
    do {
      k++;
    } while (!((k > na) || (b_data[k - 1] != x)));
    b_i++;
    b_data[b_i - 1] = x;
  }
  st.site = &ih_emlrtRSI;
  if (b_i > a->size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &hb_emlrtRTEI,
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
  st.site = &jh_emlrtRSI;
  indexShapeCheck(&st, b->size[0], iv);
  i1 = b->size[0];
  b->size[0] = i;
  emxEnsureCapacity_uint32_T(sp, b, i1, &me_emlrtRTEI);
  st.site = &kh_emlrtRSI;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (unique.c) */
