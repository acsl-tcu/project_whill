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
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo jj_emlrtRSI = {
    223,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRSInfo lj_emlrtRSI = {
    242,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRSInfo yy_emlrtRSI = {
    183,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

/* Function Definitions */
void b_unique_vector(const emlrtStack *sp, const emxArray_real_T *a,
                     emxArray_real_T *b)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  const real_T *a_data;
  real_T x;
  real_T *b_data;
  int32_T b_i;
  int32_T i;
  int32_T i2;
  int32_T j;
  int32_T k;
  int32_T n;
  int32_T na;
  int32_T nb;
  int32_T p;
  int32_T pEnd;
  int32_T qEnd;
  int32_T *idx_data;
  int32_T *iwork_data;
  boolean_T exitg1;
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
  na = a->size[1];
  st.site = &gj_emlrtRSI;
  n = a->size[1] + 1;
  emxInit_int32_T(&st, &idx, 2, &fh_emlrtRTEI);
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = a->size[1];
  emxEnsureCapacity_int32_T(&st, idx, i, &fh_emlrtRTEI);
  idx_data = idx->data;
  b_i = a->size[1];
  for (i = 0; i < b_i; i++) {
    idx_data[i] = 0;
  }
  if (a->size[1] != 0) {
    b_st.site = &nj_emlrtRSI;
    emxInit_int32_T(&b_st, &iwork, 1, &jh_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = a->size[1];
    emxEnsureCapacity_int32_T(&b_st, iwork, i, &gh_emlrtRTEI);
    iwork_data = iwork->data;
    b_i = a->size[1] - 1;
    c_st.site = &oj_emlrtRSI;
    if (a->size[1] - 1 > 2147483645) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 1; k <= b_i; k += 2) {
      x = a_data[k];
      if ((a_data[k - 1] <= x) || muDoubleScalarIsNaN(x)) {
        idx_data[k - 1] = k;
        idx_data[k] = k + 1;
      } else {
        idx_data[k - 1] = k + 1;
        idx_data[k] = k;
      }
    }
    if ((a->size[1] & 1) != 0) {
      idx_data[a->size[1] - 1] = a->size[1];
    }
    b_i = 2;
    while (b_i < n - 1) {
      i2 = b_i << 1;
      j = 1;
      for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
        int32_T kEnd;
        p = j;
        nb = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          x = a_data[idx_data[nb] - 1];
          i = idx_data[p - 1];
          if ((a_data[i - 1] <= x) || muDoubleScalarIsNaN(x)) {
            iwork_data[k] = i;
            p++;
            if (p == pEnd) {
              while (nb + 1 < qEnd) {
                k++;
                iwork_data[k] = idx_data[nb];
                nb++;
              }
            }
          } else {
            iwork_data[k] = idx_data[nb];
            nb++;
            if (nb + 1 == qEnd) {
              while (p < pEnd) {
                k++;
                iwork_data[k] = idx_data[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        c_st.site = &pj_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          idx_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      b_i = i2;
    }
    emxFree_int32_T(&b_st, &iwork);
  }
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = a->size[1];
  emxEnsureCapacity_real_T(sp, b, i, &hh_emlrtRTEI);
  b_data = b->data;
  st.site = &hj_emlrtRSI;
  if (a->size[1] > 2147483646) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < na; k++) {
    b_data[k] = a_data[idx_data[k] - 1];
  }
  emxFree_int32_T(sp, &idx);
  k = 0;
  while ((k + 1 <= na) && muDoubleScalarIsInf(b_data[k]) && (b_data[k] < 0.0)) {
    k++;
  }
  pEnd = k;
  k = a->size[1];
  while ((k >= 1) && muDoubleScalarIsNaN(b_data[k - 1])) {
    k--;
  }
  p = a->size[1] - k;
  exitg1 = false;
  while ((!exitg1) && (k >= 1)) {
    x = b_data[k - 1];
    if (muDoubleScalarIsInf(x) && (x > 0.0)) {
      k--;
    } else {
      exitg1 = true;
    }
  }
  b_i = (a->size[1] - k) - p;
  nb = 0;
  if (pEnd > 0) {
    nb = 1;
    st.site = &yy_emlrtRSI;
    if (pEnd > 2147483646) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }
  while (pEnd + 1 <= k) {
    x = b_data[pEnd];
    i2 = pEnd;
    do {
      pEnd++;
    } while (!((pEnd + 1 > k) || (b_data[pEnd] != x)));
    nb++;
    b_data[nb - 1] = x;
    st.site = &ij_emlrtRSI;
    if ((i2 + 1 <= pEnd) && (pEnd > 2147483646)) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }
  if (b_i > 0) {
    nb++;
    b_data[nb - 1] = b_data[k];
    st.site = &jj_emlrtRSI;
    if (b_i > 2147483646) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }
  pEnd = k + b_i;
  st.site = &kj_emlrtRSI;
  for (j = 0; j < p; j++) {
    b_data[nb + j] = b_data[pEnd + j];
  }
  if (p - 1 >= 0) {
    nb += p;
  }
  if (nb > a->size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &jb_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  i = b->size[0] * b->size[1];
  if (nb < 1) {
    b->size[1] = 0;
  } else {
    b->size[1] = nb;
  }
  emxEnsureCapacity_real_T(sp, b, i, &ih_emlrtRTEI);
  st.site = &mj_emlrtRSI;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void unique_vector(const emlrtStack *sp, const emxArray_uint32_T *a,
                   emxArray_uint32_T *b)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  int32_T b_iv[2];
  int32_T b_a;
  int32_T b_i;
  int32_T i;
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
  st.site = &gj_emlrtRSI;
  n = a->size[0] + 1;
  emxInit_int32_T(&st, &idx, 1, &fh_emlrtRTEI);
  i = idx->size[0];
  idx->size[0] = a->size[0];
  emxEnsureCapacity_int32_T(&st, idx, i, &fh_emlrtRTEI);
  idx_data = idx->data;
  b_i = a->size[0];
  for (i = 0; i < b_i; i++) {
    idx_data[i] = 0;
  }
  if (a->size[0] != 0) {
    b_st.site = &nj_emlrtRSI;
    emxInit_int32_T(&b_st, &iwork, 1, &jh_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = a->size[0];
    emxEnsureCapacity_int32_T(&b_st, iwork, i, &gh_emlrtRTEI);
    iwork_data = iwork->data;
    b_i = a->size[0] - 1;
    c_st.site = &oj_emlrtRSI;
    if (a->size[0] - 1 > 2147483645) {
      d_st.site = &mb_emlrtRSI;
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
          b_a = idx_data[q - 1];
          if (a_data[i - 1] <= a_data[b_a - 1]) {
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
            iwork_data[k] = b_a;
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
        c_st.site = &pj_emlrtRSI;
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
  emxEnsureCapacity_uint32_T(sp, b, i, &hh_emlrtRTEI);
  b_data = b->data;
  st.site = &hj_emlrtRSI;
  if (a->size[0] > 2147483646) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < na; k++) {
    b_data[k] = a_data[idx_data[k] - 1];
  }
  emxFree_int32_T(sp, &idx);
  b_i = 0;
  k = 0;
  while (k + 1 <= na) {
    uint32_T x;
    x = b_data[k];
    b_a = k;
    do {
      k++;
    } while (!((k + 1 > na) || (b_data[k] != x)));
    b_i++;
    b_data[b_i - 1] = x;
    st.site = &ij_emlrtRSI;
    if ((b_a + 1 <= k) && (k > 2147483646)) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }
  st.site = &kj_emlrtRSI;
  if (b_i > a->size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &jb_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (b_i < 1) {
    i = 0;
  } else {
    i = b_i;
  }
  b_iv[0] = 1;
  b_iv[1] = i;
  st.site = &lj_emlrtRSI;
  indexShapeCheck(&st, b->size[0], b_iv);
  b_a = b->size[0];
  b->size[0] = i;
  emxEnsureCapacity_uint32_T(sp, b, b_a, &ih_emlrtRTEI);
  st.site = &mj_emlrtRSI;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (unique.c) */
