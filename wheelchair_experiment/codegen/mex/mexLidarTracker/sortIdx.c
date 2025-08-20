/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include "sortIdx.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo sk_emlrtRSI = {
    561,     /* lineNo */
    "merge", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo tk_emlrtRSI = {
    530,     /* lineNo */
    "merge", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo tx_emlrtRSI = {
    340,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo ux_emlrtRSI = {
    392,                      /* lineNo */
    "initialize_vector_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo vx_emlrtRSI = {
    420,                      /* lineNo */
    "initialize_vector_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo wx_emlrtRSI = {
    427,                      /* lineNo */
    "initialize_vector_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo xx_emlrtRSI = {
    354,          /* lineNo */
    "shift_NaNs", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo yx_emlrtRSI = {
    363,          /* lineNo */
    "shift_NaNs", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRTEInfo eo_emlrtRTEI = {
    61,        /* lineNo */
    5,         /* colNo */
    "sortIdx", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName
                                                                           */
};

/* Function Declarations */
static void b_merge(const emlrtStack *sp, emxArray_int32_T *idx,
                    emxArray_real_T *x, int32_T offset, int32_T np, int32_T nq,
                    emxArray_int32_T *iwork, emxArray_real_T *xwork);

static void b_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
                          emxArray_real_T *x, int32_T offset, int32_T n,
                          int32_T preSortLevel, emxArray_int32_T *iwork,
                          emxArray_real_T *xwork);

static void c_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
                          emxArray_real_T *x, int32_T offset, int32_T n,
                          int32_T preSortLevel, emxArray_int32_T *iwork,
                          emxArray_real_T *xwork);

static void d_merge(const emlrtStack *sp, emxArray_int32_T *idx,
                    emxArray_real_T *x, int32_T offset, int32_T np, int32_T nq,
                    emxArray_int32_T *iwork, emxArray_real_T *xwork);

static void merge(const emlrtStack *sp, emxArray_int32_T *idx,
                  emxArray_uint32_T *x, int32_T offset, int32_T np, int32_T nq,
                  emxArray_int32_T *iwork, emxArray_uint32_T *xwork);

/* Function Definitions */
static void b_merge(const emlrtStack *sp, emxArray_int32_T *idx,
                    emxArray_real_T *x, int32_T offset, int32_T np, int32_T nq,
                    emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T *x_data;
  real_T *xwork_data;
  int32_T j;
  int32_T *idx_data;
  int32_T *iwork_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  xwork_data = xwork->data;
  iwork_data = iwork->data;
  x_data = x->data;
  idx_data = idx->data;
  if (nq != 0) {
    int32_T iout;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &tk_emlrtRSI;
    if (n_tmp > 2147483646) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork_data[j] = idx_data[iout];
      xwork_data[j] = x_data[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] >= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          st.site = &sk_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx_data[iout] = iwork_data[j - 1];
            x_data[iout] = xwork_data[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void b_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
                          emxArray_real_T *x, int32_T offset, int32_T n,
                          int32_T preSortLevel, emxArray_int32_T *iwork,
                          emxArray_real_T *xwork)
{
  emlrtStack st;
  int32_T bLen;
  int32_T nPairs;
  int32_T nTail;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    int32_T tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &ok_emlrtRSI;
        b_merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &qk_emlrtRSI;
      b_merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork,
              xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &rk_emlrtRSI;
    b_merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

static void c_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
                          emxArray_real_T *x, int32_T offset, int32_T n,
                          int32_T preSortLevel, emxArray_int32_T *iwork,
                          emxArray_real_T *xwork)
{
  emlrtStack st;
  int32_T bLen;
  int32_T nPairs;
  int32_T nTail;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    int32_T tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &ok_emlrtRSI;
        d_merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &qk_emlrtRSI;
      d_merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork,
              xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &rk_emlrtRSI;
    d_merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

static void d_merge(const emlrtStack *sp, emxArray_int32_T *idx,
                    emxArray_real_T *x, int32_T offset, int32_T np, int32_T nq,
                    emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T *x_data;
  real_T *xwork_data;
  int32_T j;
  int32_T *idx_data;
  int32_T *iwork_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  xwork_data = xwork->data;
  iwork_data = iwork->data;
  x_data = x->data;
  idx_data = idx->data;
  if (nq != 0) {
    int32_T iout;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &tk_emlrtRSI;
    if (n_tmp > 2147483646) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork_data[j] = idx_data[iout];
      xwork_data[j] = x_data[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          st.site = &sk_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx_data[iout] = iwork_data[j - 1];
            x_data[iout] = xwork_data[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge(const emlrtStack *sp, emxArray_int32_T *idx,
                  emxArray_uint32_T *x, int32_T offset, int32_T np, int32_T nq,
                  emxArray_int32_T *iwork, emxArray_uint32_T *xwork)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T j;
  int32_T *idx_data;
  int32_T *iwork_data;
  uint32_T *x_data;
  uint32_T *xwork_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  xwork_data = xwork->data;
  iwork_data = iwork->data;
  x_data = x->data;
  idx_data = idx->data;
  if (nq != 0) {
    int32_T iout;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &tk_emlrtRSI;
    if (n_tmp > 2147483646) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork_data[j] = idx_data[iout];
      xwork_data[j] = x_data[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          st.site = &sk_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx_data[iout] = iwork_data[j - 1];
            x_data[iout] = xwork_data[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

void b_sortIdx(const emlrtStack *sp, emxArray_uint32_T *x,
               emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *iwork;
  emxArray_uint32_T *xwork;
  int32_T idx4[4];
  int32_T b;
  int32_T b_b;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T j;
  int32_T k;
  int32_T nQuartets;
  int32_T *idx_data;
  int32_T *iwork_data;
  uint32_T x4[4];
  uint32_T unnamed_idx_0;
  uint32_T *x_data;
  uint32_T *xwork_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  unnamed_idx_0 = (uint32_T)x->size[0];
  i = idx->size[0];
  idx->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity_int32_T(sp, idx, i, &eo_emlrtRTEI);
  idx_data = idx->data;
  nQuartets = (int32_T)unnamed_idx_0;
  for (i = 0; i < nQuartets; i++) {
    idx_data[i] = 0;
  }
  st.site = &ck_emlrtRSI;
  b_st.site = &dk_emlrtRSI;
  x4[0] = 0U;
  idx4[0] = 0;
  x4[1] = 0U;
  idx4[1] = 0;
  x4[2] = 0U;
  idx4[2] = 0;
  x4[3] = 0U;
  idx4[3] = 0;
  emxInit_int32_T(&b_st, &iwork, 1, &ho_emlrtRTEI);
  i = iwork->size[0];
  iwork->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity_int32_T(&b_st, iwork, i, &fo_emlrtRTEI);
  iwork_data = iwork->data;
  for (i = 0; i < nQuartets; i++) {
    iwork_data[i] = 0;
  }
  nQuartets = x->size[0];
  emxInit_uint32_T(&b_st, &xwork, 1, &io_emlrtRTEI, true);
  i = xwork->size[0];
  xwork->size[0] = nQuartets;
  emxEnsureCapacity_uint32_T(&b_st, xwork, i, &go_emlrtRTEI);
  xwork_data = xwork->data;
  for (i = 0; i < nQuartets; i++) {
    xwork_data[i] = 0U;
  }
  nQuartets = x->size[0] >> 2;
  c_st.site = &ik_emlrtRSI;
  for (j = 0; j < nQuartets; j++) {
    uint32_T u;
    uint32_T u1;
    uint32_T u2;
    int8_T b_i1;
    int8_T b_i2;
    int8_T b_i3;
    int8_T b_i4;
    b_i = j << 2;
    idx4[0] = b_i + 1;
    idx4[1] = b_i + 2;
    idx4[2] = b_i + 3;
    idx4[3] = b_i + 4;
    unnamed_idx_0 = x_data[b_i];
    x4[0] = unnamed_idx_0;
    u = x_data[b_i + 1];
    x4[1] = u;
    u1 = x_data[b_i + 2];
    x4[2] = u1;
    u2 = x_data[b_i + 3];
    x4[3] = u2;
    if (unnamed_idx_0 <= u) {
      i1 = 1;
      i2 = 2;
    } else {
      i1 = 2;
      i2 = 1;
    }
    if (u1 <= u2) {
      i3 = 3;
      i4 = 4;
    } else {
      i3 = 4;
      i4 = 3;
    }
    unnamed_idx_0 = x4[i3 - 1];
    u = x4[i1 - 1];
    if (u <= unnamed_idx_0) {
      u = x4[i2 - 1];
      if (u <= unnamed_idx_0) {
        b_i1 = (int8_T)i1;
        b_i2 = (int8_T)i2;
        b_i3 = (int8_T)i3;
        b_i4 = (int8_T)i4;
      } else if (u <= x4[i4 - 1]) {
        b_i1 = (int8_T)i1;
        b_i2 = (int8_T)i3;
        b_i3 = (int8_T)i2;
        b_i4 = (int8_T)i4;
      } else {
        b_i1 = (int8_T)i1;
        b_i2 = (int8_T)i3;
        b_i3 = (int8_T)i4;
        b_i4 = (int8_T)i2;
      }
    } else {
      unnamed_idx_0 = x4[i4 - 1];
      if (u <= unnamed_idx_0) {
        if (x4[i2 - 1] <= unnamed_idx_0) {
          b_i1 = (int8_T)i3;
          b_i2 = (int8_T)i1;
          b_i3 = (int8_T)i2;
          b_i4 = (int8_T)i4;
        } else {
          b_i1 = (int8_T)i3;
          b_i2 = (int8_T)i1;
          b_i3 = (int8_T)i4;
          b_i4 = (int8_T)i2;
        }
      } else {
        b_i1 = (int8_T)i3;
        b_i2 = (int8_T)i4;
        b_i3 = (int8_T)i1;
        b_i4 = (int8_T)i2;
      }
    }
    idx_data[b_i] = idx4[b_i1 - 1];
    idx_data[b_i + 1] = idx4[b_i2 - 1];
    idx_data[b_i + 2] = idx4[b_i3 - 1];
    idx_data[b_i + 3] = idx4[b_i4 - 1];
    x_data[b_i] = x4[b_i1 - 1];
    x_data[b_i + 1] = x4[b_i2 - 1];
    x_data[b_i + 2] = x4[b_i3 - 1];
    x_data[b_i + 3] = x4[b_i4 - 1];
  }
  b_i = nQuartets << 2;
  i1 = x->size[0] - b_i;
  if (i1 > 0) {
    int8_T perm[4];
    c_st.site = &jk_emlrtRSI;
    if (i1 > 2147483646) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < i1; k++) {
      nQuartets = b_i + k;
      idx4[k] = nQuartets + 1;
      x4[k] = x_data[nQuartets];
    }
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (i1 == 1) {
      perm[0] = 1;
    } else if (i1 == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }
    c_st.site = &kk_emlrtRSI;
    for (k = 0; k < i1; k++) {
      i2 = perm[k] - 1;
      nQuartets = b_i + k;
      idx_data[nQuartets] = idx4[i2];
      x_data[nQuartets] = x4[i2];
    }
  }
  nQuartets = 2;
  if (x->size[0] > 1) {
    if (x->size[0] >= 256) {
      i4 = x->size[0] >> 8;
      b_st.site = &ek_emlrtRSI;
      for (b = 0; b < i4; b++) {
        int32_T b_iwork[256];
        int32_T offset;
        uint32_T b_xwork[256];
        b_st.site = &fk_emlrtRSI;
        offset = (b << 8) - 1;
        for (b_b = 0; b_b < 6; b_b++) {
          int32_T bLen;
          int32_T bLen2;
          bLen = 1 << (b_b + 2);
          bLen2 = bLen << 1;
          i = 256 >> (b_b + 3);
          c_st.site = &lk_emlrtRSI;
          for (k = 0; k < i; k++) {
            i1 = (offset + k * bLen2) + 1;
            c_st.site = &mk_emlrtRSI;
            for (j = 0; j < bLen2; j++) {
              nQuartets = i1 + j;
              b_iwork[j] = idx_data[nQuartets];
              b_xwork[j] = x_data[nQuartets];
            }
            i3 = 0;
            b_i = bLen;
            nQuartets = i1 - 1;
            int32_T exitg1;
            do {
              exitg1 = 0;
              nQuartets++;
              if (b_xwork[i3] <= b_xwork[b_i]) {
                idx_data[nQuartets] = b_iwork[i3];
                x_data[nQuartets] = b_xwork[i3];
                if (i3 + 1 < bLen) {
                  i3++;
                } else {
                  exitg1 = 1;
                }
              } else {
                idx_data[nQuartets] = b_iwork[b_i];
                x_data[nQuartets] = b_xwork[b_i];
                if (b_i + 1 < bLen2) {
                  b_i++;
                } else {
                  nQuartets -= i3;
                  c_st.site = &nk_emlrtRSI;
                  for (j = i3 + 1; j <= bLen; j++) {
                    i2 = nQuartets + j;
                    idx_data[i2] = b_iwork[j - 1];
                    x_data[i2] = b_xwork[j - 1];
                  }
                  exitg1 = 1;
                }
              }
            } while (exitg1 == 0);
          }
        }
      }
      nQuartets = i4 << 8;
      b_i = x->size[0] - nQuartets;
      if (b_i > 0) {
        b_st.site = &gk_emlrtRSI;
        merge_block(&b_st, idx, x, nQuartets, b_i, 2, iwork, xwork);
      }
      nQuartets = 8;
    }
    b_st.site = &hk_emlrtRSI;
    merge_block(&b_st, idx, x, 0, x->size[0], nQuartets, iwork, xwork);
  }
  emxFree_uint32_T(&st, &xwork);
  emxFree_int32_T(&st, &iwork);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void c_merge(const emlrtStack *sp, int32_T idx[20], uint32_T x[20],
             int32_T offset, int32_T np, int32_T nq, int32_T iwork[20],
             uint32_T xwork[20])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T j;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq != 0) {
    int32_T iout;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    st.site = &tk_emlrtRSI;
    if (n_tmp > 2147483646) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = x[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          st.site = &sk_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx[iout] = iwork[j - 1];
            x[iout] = xwork[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

void c_sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  real_T *x_data;
  real_T *xwork_data;
  int32_T b;
  int32_T b_b;
  int32_T i;
  int32_T ib;
  int32_T k;
  int32_T quartetOffset;
  int32_T *idx_data;
  int32_T *iwork_data;
  uint32_T unnamed_idx_0;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  unnamed_idx_0 = (uint32_T)x->size[0];
  i = idx->size[0];
  idx->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity_int32_T(sp, idx, i, &eo_emlrtRTEI);
  idx_data = idx->data;
  ib = (int32_T)unnamed_idx_0;
  for (i = 0; i < ib; i++) {
    idx_data[i] = 0;
  }
  if (x->size[0] != 0) {
    real_T x4[4];
    int32_T idx4[4];
    int32_T i2;
    int32_T i3;
    int32_T i4;
    int32_T idx_tmp;
    int32_T n;
    int32_T nNaNs;
    int32_T wOffset_tmp;
    st.site = &ck_emlrtRSI;
    b_st.site = &dk_emlrtRSI;
    n = x->size[0];
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    emxInit_int32_T(&b_st, &iwork, 1, &ho_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = (int32_T)unnamed_idx_0;
    emxEnsureCapacity_int32_T(&b_st, iwork, i, &fo_emlrtRTEI);
    iwork_data = iwork->data;
    for (i = 0; i < ib; i++) {
      iwork_data[i] = 0;
    }
    ib = x->size[0];
    emxInit_real_T(&b_st, &xwork, 1, &io_emlrtRTEI, true);
    i = xwork->size[0];
    xwork->size[0] = ib;
    emxEnsureCapacity_real_T(&b_st, xwork, i, &go_emlrtRTEI);
    xwork_data = xwork->data;
    for (i = 0; i < ib; i++) {
      xwork_data[i] = 0.0;
    }
    nNaNs = 0;
    ib = 0;
    c_st.site = &ux_emlrtRSI;
    if (x->size[0] > 2147483646) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < n; k++) {
      if (muDoubleScalarIsNaN(x_data[k])) {
        idx_tmp = (n - nNaNs) - 1;
        idx_data[idx_tmp] = k + 1;
        xwork_data[idx_tmp] = x_data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib - 1] = k + 1;
        x4[ib - 1] = x_data[k];
        if (ib == 4) {
          real_T d;
          real_T d1;
          int8_T b_i2;
          int8_T b_i3;
          int8_T b_i4;
          int8_T i1;
          quartetOffset = k - nNaNs;
          if (x4[0] >= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }
          if (x4[2] >= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[i3 - 1];
          d1 = x4[ib - 1];
          if (d1 >= d) {
            d1 = x4[i2 - 1];
            if (d1 >= d) {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i2;
              b_i3 = (int8_T)i3;
              b_i4 = (int8_T)i4;
            } else if (d1 >= x4[i4 - 1]) {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i3;
              b_i3 = (int8_T)i2;
              b_i4 = (int8_T)i4;
            } else {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i3;
              b_i3 = (int8_T)i4;
              b_i4 = (int8_T)i2;
            }
          } else {
            d = x4[i4 - 1];
            if (d1 >= d) {
              if (x4[i2 - 1] >= d) {
                i1 = (int8_T)i3;
                b_i2 = (int8_T)ib;
                b_i3 = (int8_T)i2;
                b_i4 = (int8_T)i4;
              } else {
                i1 = (int8_T)i3;
                b_i2 = (int8_T)ib;
                b_i3 = (int8_T)i4;
                b_i4 = (int8_T)i2;
              }
            } else {
              i1 = (int8_T)i3;
              b_i2 = (int8_T)i4;
              b_i3 = (int8_T)ib;
              b_i4 = (int8_T)i2;
            }
          }
          idx_data[quartetOffset - 3] = idx4[i1 - 1];
          idx_data[quartetOffset - 2] = idx4[b_i2 - 1];
          idx_data[quartetOffset - 1] = idx4[b_i3 - 1];
          idx_data[quartetOffset] = idx4[b_i4 - 1];
          x_data[quartetOffset - 3] = x4[i1 - 1];
          x_data[quartetOffset - 2] = x4[b_i2 - 1];
          x_data[quartetOffset - 1] = x4[b_i3 - 1];
          x_data[quartetOffset] = x4[b_i4 - 1];
          ib = 0;
        }
      }
    }
    wOffset_tmp = x->size[0] - nNaNs;
    if (ib > 0) {
      int8_T perm[4];
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
        if (x4[0] >= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] >= x4[1]) {
        if (x4[1] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      c_st.site = &vx_emlrtRSI;
      if (ib > 2147483646) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      i = (uint8_T)ib;
      for (k = 0; k < i; k++) {
        idx_tmp = perm[k] - 1;
        quartetOffset = (wOffset_tmp - ib) + k;
        idx_data[quartetOffset] = idx4[idx_tmp];
        x_data[quartetOffset] = x4[idx_tmp];
      }
    }
    ib = nNaNs >> 1;
    c_st.site = &wx_emlrtRSI;
    for (k = 0; k < ib; k++) {
      quartetOffset = wOffset_tmp + k;
      i2 = idx_data[quartetOffset];
      idx_tmp = (n - k) - 1;
      idx_data[quartetOffset] = idx_data[idx_tmp];
      idx_data[idx_tmp] = i2;
      x_data[quartetOffset] = xwork_data[idx_tmp];
      x_data[idx_tmp] = xwork_data[quartetOffset];
    }
    if ((nNaNs & 1) != 0) {
      i = wOffset_tmp + ib;
      x_data[i] = xwork_data[i];
    }
    ib = 2;
    if (wOffset_tmp > 1) {
      if (x->size[0] >= 256) {
        int32_T nBlocks;
        nBlocks = wOffset_tmp >> 8;
        if (nBlocks > 0) {
          b_st.site = &ek_emlrtRSI;
          for (b = 0; b < nBlocks; b++) {
            real_T b_xwork[256];
            int32_T b_iwork[256];
            b_st.site = &fk_emlrtRSI;
            i4 = (b << 8) - 1;
            for (b_b = 0; b_b < 6; b_b++) {
              int32_T bLen2;
              n = 1 << (b_b + 2);
              bLen2 = n << 1;
              i = 256 >> (b_b + 3);
              c_st.site = &lk_emlrtRSI;
              for (k = 0; k < i; k++) {
                i2 = (i4 + k * bLen2) + 1;
                c_st.site = &mk_emlrtRSI;
                for (quartetOffset = 0; quartetOffset < bLen2;
                     quartetOffset++) {
                  ib = i2 + quartetOffset;
                  b_iwork[quartetOffset] = idx_data[ib];
                  b_xwork[quartetOffset] = x_data[ib];
                }
                i3 = 0;
                quartetOffset = n;
                ib = i2 - 1;
                int32_T exitg1;
                do {
                  exitg1 = 0;
                  ib++;
                  if (b_xwork[i3] >= b_xwork[quartetOffset]) {
                    idx_data[ib] = b_iwork[i3];
                    x_data[ib] = b_xwork[i3];
                    if (i3 + 1 < n) {
                      i3++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    idx_data[ib] = b_iwork[quartetOffset];
                    x_data[ib] = b_xwork[quartetOffset];
                    if (quartetOffset + 1 < bLen2) {
                      quartetOffset++;
                    } else {
                      ib -= i3;
                      c_st.site = &nk_emlrtRSI;
                      for (quartetOffset = i3 + 1; quartetOffset <= n;
                           quartetOffset++) {
                        idx_tmp = ib + quartetOffset;
                        idx_data[idx_tmp] = b_iwork[quartetOffset - 1];
                        x_data[idx_tmp] = b_xwork[quartetOffset - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          ib = nBlocks << 8;
          quartetOffset = wOffset_tmp - ib;
          if (quartetOffset > 0) {
            b_st.site = &gk_emlrtRSI;
            b_merge_block(&b_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      b_st.site = &hk_emlrtRSI;
      b_merge_block(&b_st, idx, x, 0, wOffset_tmp, ib, iwork, xwork);
      xwork_data = xwork->data;
      iwork_data = iwork->data;
      x_data = x->data;
      idx_data = idx->data;
    }
    if ((nNaNs > 0) && (wOffset_tmp > 0)) {
      b_st.site = &tx_emlrtRSI;
      c_st.site = &xx_emlrtRSI;
      if (nNaNs > 2147483646) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (k = 0; k < nNaNs; k++) {
        ib = wOffset_tmp + k;
        xwork_data[k] = x_data[ib];
        iwork_data[k] = idx_data[ib];
      }
      for (k = wOffset_tmp; k >= 1; k--) {
        i = (nNaNs + k) - 1;
        x_data[i] = x_data[k - 1];
        idx_data[i] = idx_data[k - 1];
      }
      c_st.site = &yx_emlrtRSI;
      for (k = 0; k < nNaNs; k++) {
        x_data[k] = xwork_data[k];
        idx_data[k] = iwork_data[k];
      }
    }
    emxFree_real_T(&st, &xwork);
    emxFree_int32_T(&st, &iwork);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void d_sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  real_T *x_data;
  real_T *xwork_data;
  int32_T b;
  int32_T b_b;
  int32_T i;
  int32_T ib;
  int32_T k;
  int32_T quartetOffset;
  int32_T *idx_data;
  int32_T *iwork_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(sp, idx, i, &dm_emlrtRTEI);
  idx_data = idx->data;
  ib = x->size[1];
  for (i = 0; i < ib; i++) {
    idx_data[i] = 0;
  }
  if (x->size[1] != 0) {
    real_T x4[4];
    int32_T idx4[4];
    int32_T bLen;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    int32_T idx_tmp;
    int32_T n;
    int32_T wOffset_tmp;
    st.site = &ck_emlrtRSI;
    b_st.site = &dk_emlrtRSI;
    n = x->size[1];
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    ib = x->size[1];
    emxInit_int32_T(&b_st, &iwork, 1, &ho_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = ib;
    emxEnsureCapacity_int32_T(&b_st, iwork, i, &fo_emlrtRTEI);
    iwork_data = iwork->data;
    emxInit_real_T(&b_st, &xwork, 1, &io_emlrtRTEI, true);
    i = xwork->size[0];
    xwork->size[0] = x->size[1];
    emxEnsureCapacity_real_T(&b_st, xwork, i, &go_emlrtRTEI);
    xwork_data = xwork->data;
    for (i = 0; i < ib; i++) {
      iwork_data[i] = 0;
      xwork_data[i] = 0.0;
    }
    bLen = 0;
    ib = 0;
    c_st.site = &ux_emlrtRSI;
    if (x->size[1] > 2147483646) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < n; k++) {
      if (muDoubleScalarIsNaN(x_data[k])) {
        idx_tmp = (n - bLen) - 1;
        idx_data[idx_tmp] = k + 1;
        xwork_data[idx_tmp] = x_data[k];
        bLen++;
      } else {
        ib++;
        idx4[ib - 1] = k + 1;
        x4[ib - 1] = x_data[k];
        if (ib == 4) {
          real_T d;
          real_T d1;
          int8_T b_i2;
          int8_T b_i3;
          int8_T b_i4;
          int8_T i1;
          quartetOffset = k - bLen;
          if (x4[0] <= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }
          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[i3 - 1];
          d1 = x4[ib - 1];
          if (d1 <= d) {
            d1 = x4[i2 - 1];
            if (d1 <= d) {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i2;
              b_i3 = (int8_T)i3;
              b_i4 = (int8_T)i4;
            } else if (d1 <= x4[i4 - 1]) {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i3;
              b_i3 = (int8_T)i2;
              b_i4 = (int8_T)i4;
            } else {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i3;
              b_i3 = (int8_T)i4;
              b_i4 = (int8_T)i2;
            }
          } else {
            d = x4[i4 - 1];
            if (d1 <= d) {
              if (x4[i2 - 1] <= d) {
                i1 = (int8_T)i3;
                b_i2 = (int8_T)ib;
                b_i3 = (int8_T)i2;
                b_i4 = (int8_T)i4;
              } else {
                i1 = (int8_T)i3;
                b_i2 = (int8_T)ib;
                b_i3 = (int8_T)i4;
                b_i4 = (int8_T)i2;
              }
            } else {
              i1 = (int8_T)i3;
              b_i2 = (int8_T)i4;
              b_i3 = (int8_T)ib;
              b_i4 = (int8_T)i2;
            }
          }
          idx_data[quartetOffset - 3] = idx4[i1 - 1];
          idx_data[quartetOffset - 2] = idx4[b_i2 - 1];
          idx_data[quartetOffset - 1] = idx4[b_i3 - 1];
          idx_data[quartetOffset] = idx4[b_i4 - 1];
          x_data[quartetOffset - 3] = x4[i1 - 1];
          x_data[quartetOffset - 2] = x4[b_i2 - 1];
          x_data[quartetOffset - 1] = x4[b_i3 - 1];
          x_data[quartetOffset] = x4[b_i4 - 1];
          ib = 0;
        }
      }
    }
    wOffset_tmp = x->size[1] - bLen;
    if (ib > 0) {
      int8_T perm[4];
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      c_st.site = &vx_emlrtRSI;
      if (ib > 2147483646) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      i = (uint8_T)ib;
      for (k = 0; k < i; k++) {
        idx_tmp = perm[k] - 1;
        quartetOffset = (wOffset_tmp - ib) + k;
        idx_data[quartetOffset] = idx4[idx_tmp];
        x_data[quartetOffset] = x4[idx_tmp];
      }
    }
    ib = bLen >> 1;
    c_st.site = &wx_emlrtRSI;
    for (k = 0; k < ib; k++) {
      quartetOffset = wOffset_tmp + k;
      i2 = idx_data[quartetOffset];
      idx_tmp = (n - k) - 1;
      idx_data[quartetOffset] = idx_data[idx_tmp];
      idx_data[idx_tmp] = i2;
      x_data[quartetOffset] = xwork_data[idx_tmp];
      x_data[idx_tmp] = xwork_data[quartetOffset];
    }
    if ((bLen & 1) != 0) {
      i = wOffset_tmp + ib;
      x_data[i] = xwork_data[i];
    }
    ib = 2;
    if (wOffset_tmp > 1) {
      if (x->size[1] >= 256) {
        int32_T nBlocks;
        nBlocks = wOffset_tmp >> 8;
        if (nBlocks > 0) {
          b_st.site = &ek_emlrtRSI;
          for (b = 0; b < nBlocks; b++) {
            real_T b_xwork[256];
            int32_T b_iwork[256];
            b_st.site = &fk_emlrtRSI;
            i4 = (b << 8) - 1;
            for (b_b = 0; b_b < 6; b_b++) {
              bLen = 1 << (b_b + 2);
              n = bLen << 1;
              i = 256 >> (b_b + 3);
              c_st.site = &lk_emlrtRSI;
              for (k = 0; k < i; k++) {
                i2 = (i4 + k * n) + 1;
                c_st.site = &mk_emlrtRSI;
                for (quartetOffset = 0; quartetOffset < n; quartetOffset++) {
                  ib = i2 + quartetOffset;
                  b_iwork[quartetOffset] = idx_data[ib];
                  b_xwork[quartetOffset] = x_data[ib];
                }
                i3 = 0;
                quartetOffset = bLen;
                ib = i2 - 1;
                int32_T exitg1;
                do {
                  exitg1 = 0;
                  ib++;
                  if (b_xwork[i3] <= b_xwork[quartetOffset]) {
                    idx_data[ib] = b_iwork[i3];
                    x_data[ib] = b_xwork[i3];
                    if (i3 + 1 < bLen) {
                      i3++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    idx_data[ib] = b_iwork[quartetOffset];
                    x_data[ib] = b_xwork[quartetOffset];
                    if (quartetOffset + 1 < n) {
                      quartetOffset++;
                    } else {
                      ib -= i3;
                      c_st.site = &nk_emlrtRSI;
                      for (quartetOffset = i3 + 1; quartetOffset <= bLen;
                           quartetOffset++) {
                        idx_tmp = ib + quartetOffset;
                        idx_data[idx_tmp] = b_iwork[quartetOffset - 1];
                        x_data[idx_tmp] = b_xwork[quartetOffset - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          ib = nBlocks << 8;
          quartetOffset = wOffset_tmp - ib;
          if (quartetOffset > 0) {
            b_st.site = &gk_emlrtRSI;
            c_merge_block(&b_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      b_st.site = &hk_emlrtRSI;
      c_merge_block(&b_st, idx, x, 0, wOffset_tmp, ib, iwork, xwork);
    }
    emxFree_real_T(&st, &xwork);
    emxFree_int32_T(&st, &iwork);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void e_sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  real_T *x_data;
  real_T *xwork_data;
  int32_T b;
  int32_T b_b;
  int32_T i;
  int32_T ib;
  int32_T k;
  int32_T quartetOffset;
  int32_T *idx_data;
  int32_T *iwork_data;
  uint32_T unnamed_idx_0;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  unnamed_idx_0 = (uint32_T)x->size[0];
  i = idx->size[0];
  idx->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity_int32_T(sp, idx, i, &eo_emlrtRTEI);
  idx_data = idx->data;
  ib = (int32_T)unnamed_idx_0;
  for (i = 0; i < ib; i++) {
    idx_data[i] = 0;
  }
  if (x->size[0] != 0) {
    real_T x4[4];
    int32_T idx4[4];
    int32_T bLen;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    int32_T idx_tmp;
    int32_T n;
    int32_T wOffset_tmp;
    st.site = &ck_emlrtRSI;
    b_st.site = &dk_emlrtRSI;
    n = x->size[0];
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    emxInit_int32_T(&b_st, &iwork, 1, &ho_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = (int32_T)unnamed_idx_0;
    emxEnsureCapacity_int32_T(&b_st, iwork, i, &fo_emlrtRTEI);
    iwork_data = iwork->data;
    for (i = 0; i < ib; i++) {
      iwork_data[i] = 0;
    }
    ib = x->size[0];
    emxInit_real_T(&b_st, &xwork, 1, &io_emlrtRTEI, true);
    i = xwork->size[0];
    xwork->size[0] = ib;
    emxEnsureCapacity_real_T(&b_st, xwork, i, &go_emlrtRTEI);
    xwork_data = xwork->data;
    for (i = 0; i < ib; i++) {
      xwork_data[i] = 0.0;
    }
    bLen = 0;
    ib = 0;
    c_st.site = &ux_emlrtRSI;
    if (x->size[0] > 2147483646) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < n; k++) {
      if (muDoubleScalarIsNaN(x_data[k])) {
        idx_tmp = (n - bLen) - 1;
        idx_data[idx_tmp] = k + 1;
        xwork_data[idx_tmp] = x_data[k];
        bLen++;
      } else {
        ib++;
        idx4[ib - 1] = k + 1;
        x4[ib - 1] = x_data[k];
        if (ib == 4) {
          real_T d;
          real_T d1;
          int8_T b_i2;
          int8_T b_i3;
          int8_T b_i4;
          int8_T i1;
          quartetOffset = k - bLen;
          if (x4[0] <= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }
          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[i3 - 1];
          d1 = x4[ib - 1];
          if (d1 <= d) {
            d1 = x4[i2 - 1];
            if (d1 <= d) {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i2;
              b_i3 = (int8_T)i3;
              b_i4 = (int8_T)i4;
            } else if (d1 <= x4[i4 - 1]) {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i3;
              b_i3 = (int8_T)i2;
              b_i4 = (int8_T)i4;
            } else {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i3;
              b_i3 = (int8_T)i4;
              b_i4 = (int8_T)i2;
            }
          } else {
            d = x4[i4 - 1];
            if (d1 <= d) {
              if (x4[i2 - 1] <= d) {
                i1 = (int8_T)i3;
                b_i2 = (int8_T)ib;
                b_i3 = (int8_T)i2;
                b_i4 = (int8_T)i4;
              } else {
                i1 = (int8_T)i3;
                b_i2 = (int8_T)ib;
                b_i3 = (int8_T)i4;
                b_i4 = (int8_T)i2;
              }
            } else {
              i1 = (int8_T)i3;
              b_i2 = (int8_T)i4;
              b_i3 = (int8_T)ib;
              b_i4 = (int8_T)i2;
            }
          }
          idx_data[quartetOffset - 3] = idx4[i1 - 1];
          idx_data[quartetOffset - 2] = idx4[b_i2 - 1];
          idx_data[quartetOffset - 1] = idx4[b_i3 - 1];
          idx_data[quartetOffset] = idx4[b_i4 - 1];
          x_data[quartetOffset - 3] = x4[i1 - 1];
          x_data[quartetOffset - 2] = x4[b_i2 - 1];
          x_data[quartetOffset - 1] = x4[b_i3 - 1];
          x_data[quartetOffset] = x4[b_i4 - 1];
          ib = 0;
        }
      }
    }
    wOffset_tmp = x->size[0] - bLen;
    if (ib > 0) {
      int8_T perm[4];
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      c_st.site = &vx_emlrtRSI;
      if (ib > 2147483646) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      i = (uint8_T)ib;
      for (k = 0; k < i; k++) {
        idx_tmp = perm[k] - 1;
        quartetOffset = (wOffset_tmp - ib) + k;
        idx_data[quartetOffset] = idx4[idx_tmp];
        x_data[quartetOffset] = x4[idx_tmp];
      }
    }
    ib = bLen >> 1;
    c_st.site = &wx_emlrtRSI;
    for (k = 0; k < ib; k++) {
      quartetOffset = wOffset_tmp + k;
      i2 = idx_data[quartetOffset];
      idx_tmp = (n - k) - 1;
      idx_data[quartetOffset] = idx_data[idx_tmp];
      idx_data[idx_tmp] = i2;
      x_data[quartetOffset] = xwork_data[idx_tmp];
      x_data[idx_tmp] = xwork_data[quartetOffset];
    }
    if ((bLen & 1) != 0) {
      i = wOffset_tmp + ib;
      x_data[i] = xwork_data[i];
    }
    ib = 2;
    if (wOffset_tmp > 1) {
      if (x->size[0] >= 256) {
        int32_T nBlocks;
        nBlocks = wOffset_tmp >> 8;
        if (nBlocks > 0) {
          b_st.site = &ek_emlrtRSI;
          for (b = 0; b < nBlocks; b++) {
            real_T b_xwork[256];
            int32_T b_iwork[256];
            b_st.site = &fk_emlrtRSI;
            i4 = (b << 8) - 1;
            for (b_b = 0; b_b < 6; b_b++) {
              bLen = 1 << (b_b + 2);
              n = bLen << 1;
              i = 256 >> (b_b + 3);
              c_st.site = &lk_emlrtRSI;
              for (k = 0; k < i; k++) {
                i2 = (i4 + k * n) + 1;
                c_st.site = &mk_emlrtRSI;
                for (quartetOffset = 0; quartetOffset < n; quartetOffset++) {
                  ib = i2 + quartetOffset;
                  b_iwork[quartetOffset] = idx_data[ib];
                  b_xwork[quartetOffset] = x_data[ib];
                }
                i3 = 0;
                quartetOffset = bLen;
                ib = i2 - 1;
                int32_T exitg1;
                do {
                  exitg1 = 0;
                  ib++;
                  if (b_xwork[i3] <= b_xwork[quartetOffset]) {
                    idx_data[ib] = b_iwork[i3];
                    x_data[ib] = b_xwork[i3];
                    if (i3 + 1 < bLen) {
                      i3++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    idx_data[ib] = b_iwork[quartetOffset];
                    x_data[ib] = b_xwork[quartetOffset];
                    if (quartetOffset + 1 < n) {
                      quartetOffset++;
                    } else {
                      ib -= i3;
                      c_st.site = &nk_emlrtRSI;
                      for (quartetOffset = i3 + 1; quartetOffset <= bLen;
                           quartetOffset++) {
                        idx_tmp = ib + quartetOffset;
                        idx_data[idx_tmp] = b_iwork[quartetOffset - 1];
                        x_data[idx_tmp] = b_xwork[quartetOffset - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          ib = nBlocks << 8;
          quartetOffset = wOffset_tmp - ib;
          if (quartetOffset > 0) {
            b_st.site = &gk_emlrtRSI;
            c_merge_block(&b_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      b_st.site = &hk_emlrtRSI;
      c_merge_block(&b_st, idx, x, 0, wOffset_tmp, ib, iwork, xwork);
    }
    emxFree_real_T(&st, &xwork);
    emxFree_int32_T(&st, &iwork);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
                 emxArray_uint32_T *x, int32_T offset, int32_T n,
                 int32_T preSortLevel, emxArray_int32_T *iwork,
                 emxArray_uint32_T *xwork)
{
  emlrtStack st;
  int32_T bLen;
  int32_T nPairs;
  int32_T nTail;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    int32_T tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &ok_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
              xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &qk_emlrtRSI;
      merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &rk_emlrtRSI;
    merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

void sortIdx(const emlrtStack *sp, const emxArray_int32_T *x,
             emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_int32_T *iwork;
  const int32_T *x_data;
  int32_T b_i;
  int32_T i;
  int32_T k;
  int32_T n;
  int32_T pEnd;
  int32_T qEnd;
  int32_T *idx_data;
  int32_T *iwork_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  n = x->size[1] + 1;
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(sp, idx, i, &dm_emlrtRTEI);
  idx_data = idx->data;
  b_i = x->size[1];
  for (i = 0; i < b_i; i++) {
    idx_data[i] = 0;
  }
  if (x->size[1] != 0) {
    st.site = &nj_emlrtRSI;
    emxInit_int32_T(&st, &iwork, 1, &jh_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = x->size[1];
    emxEnsureCapacity_int32_T(&st, iwork, i, &gh_emlrtRTEI);
    iwork_data = iwork->data;
    b_i = x->size[1] - 1;
    b_st.site = &oj_emlrtRSI;
    if (x->size[1] - 1 > 2147483645) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 1; k <= b_i; k += 2) {
      if (x_data[k - 1] <= x_data[k]) {
        idx_data[k - 1] = k;
        idx_data[k] = k + 1;
      } else {
        idx_data[k - 1] = k + 1;
        idx_data[k] = k;
      }
    }
    if ((x->size[1] & 1) != 0) {
      idx_data[x->size[1] - 1] = x->size[1];
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
          int32_T i1;
          i = idx_data[p - 1];
          i1 = idx_data[q - 1];
          if (x_data[i - 1] <= x_data[i1 - 1]) {
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
        b_st.site = &pj_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          idx_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      b_i = i2;
    }
    emxFree_int32_T(&st, &iwork);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (sortIdx.c) */
