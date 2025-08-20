/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort.c
 *
 * Code generation for function 'sort'
 *
 */

/* Include files */
#include "sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo uj_emlrtRSI = {
    76,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo vj_emlrtRSI = {
    79,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo wj_emlrtRSI = {
    81,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo xj_emlrtRSI = {
    84,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo yj_emlrtRSI = {
    87,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo ak_emlrtRSI = {
    90,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo bab_emlrtRSI = {
    72,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRTEInfo bo_emlrtRTEI = {
    56,     /* lineNo */
    24,     /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pName
                                                                        */
};

static emlrtRTEInfo co_emlrtRTEI = {
    56,     /* lineNo */
    1,      /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pName
                                                                        */
};

static emlrtRTEInfo do_emlrtRTEI = {
    1,      /* lineNo */
    20,     /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pName
                                                                        */
};

static emlrtRTEInfo jo_emlrtRTEI = {
    75,     /* lineNo */
    26,     /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pName
                                                                        */
};

static emlrtRTEInfo jp_emlrtRTEI = {
    72,     /* lineNo */
    10,     /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sort.m" /* pName
                                                                        */
};

/* Function Definitions */
void b_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *iidx;
  emxArray_real_T *vwork;
  real_T *vwork_data;
  real_T *x_data;
  int32_T dim;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  int32_T *idx_data;
  int32_T *iidx_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    i = x->size[0];
  } else {
    i = 1;
  }
  vlen = i - 1;
  emxInit_real_T(sp, &vwork, 1, &co_emlrtRTEI, true);
  i1 = vwork->size[0];
  vwork->size[0] = i;
  emxEnsureCapacity_real_T(sp, vwork, i1, &bo_emlrtRTEI);
  vwork_data = vwork->data;
  i1 = idx->size[0];
  idx->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(sp, idx, i1, &jo_emlrtRTEI);
  idx_data = idx->data;
  st.site = &uj_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }
  st.site = &vj_emlrtRSI;
  st.site = &wj_emlrtRSI;
  if (vstride > 2147483646) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  emxInit_int32_T(sp, &iidx, 1, &do_emlrtRTEI);
  for (dim = 0; dim < vstride; dim++) {
    st.site = &xj_emlrtRSI;
    if (i > 2147483646) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork_data[k] = x_data[dim + k * vstride];
    }
    st.site = &yj_emlrtRSI;
    c_sortIdx(&st, vwork, iidx);
    iidx_data = iidx->data;
    vwork_data = vwork->data;
    st.site = &ak_emlrtRSI;
    for (k = 0; k <= vlen; k++) {
      i1 = dim + k * vstride;
      x_data[i1] = vwork_data[k];
      idx_data[i1] = iidx_data[k];
    }
  }
  emxFree_int32_T(sp, &iidx);
  emxFree_real_T(sp, &vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void c_sort(const emlrtStack *sp, emxArray_uint32_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_uint32_T *xwork;
  int32_T b;
  int32_T b_b;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nQuartets;
  int32_T *idx_data;
  int32_T *iwork_data;
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
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &bab_emlrtRSI;
  emxInit_int32_T(&st, &idx, 2, &do_emlrtRTEI);
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(&st, idx, i, &dm_emlrtRTEI);
  idx_data = idx->data;
  nQuartets = x->size[1];
  for (i = 0; i < nQuartets; i++) {
    idx_data[i] = 0;
  }
  if (x->size[1] != 0) {
    int32_T idx4[4];
    int32_T b_i;
    int32_T i1;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    uint32_T x4[4];
    b_st.site = &ck_emlrtRSI;
    c_st.site = &dk_emlrtRSI;
    x4[0] = 0U;
    idx4[0] = 0;
    x4[1] = 0U;
    idx4[1] = 0;
    x4[2] = 0U;
    idx4[2] = 0;
    x4[3] = 0U;
    idx4[3] = 0;
    nQuartets = x->size[1];
    emxInit_int32_T(&c_st, &iwork, 1, &ho_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = nQuartets;
    emxEnsureCapacity_int32_T(&c_st, iwork, i, &fo_emlrtRTEI);
    iwork_data = iwork->data;
    emxInit_uint32_T(&c_st, &xwork, 1, &io_emlrtRTEI, true);
    i = xwork->size[0];
    xwork->size[0] = x->size[1];
    emxEnsureCapacity_uint32_T(&c_st, xwork, i, &go_emlrtRTEI);
    xwork_data = xwork->data;
    for (i = 0; i < nQuartets; i++) {
      iwork_data[i] = 0;
      xwork_data[i] = 0U;
    }
    nQuartets = x->size[1] >> 2;
    d_st.site = &ik_emlrtRSI;
    for (j = 0; j < nQuartets; j++) {
      uint32_T u;
      uint32_T u1;
      uint32_T u2;
      uint32_T u3;
      int8_T b_i1;
      int8_T b_i2;
      int8_T b_i3;
      int8_T b_i4;
      b_i = j << 2;
      idx4[0] = b_i + 1;
      idx4[1] = b_i + 2;
      idx4[2] = b_i + 3;
      idx4[3] = b_i + 4;
      u = x_data[b_i];
      x4[0] = u;
      u1 = x_data[b_i + 1];
      x4[1] = u1;
      u2 = x_data[b_i + 2];
      x4[2] = u2;
      u3 = x_data[b_i + 3];
      x4[3] = u3;
      if (u <= u1) {
        i1 = 1;
        i2 = 2;
      } else {
        i1 = 2;
        i2 = 1;
      }
      if (u2 <= u3) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }
      u = x4[i3 - 1];
      u1 = x4[i1 - 1];
      if (u1 <= u) {
        u1 = x4[i2 - 1];
        if (u1 <= u) {
          b_i1 = (int8_T)i1;
          b_i2 = (int8_T)i2;
          b_i3 = (int8_T)i3;
          b_i4 = (int8_T)i4;
        } else if (u1 <= x4[i4 - 1]) {
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
        u = x4[i4 - 1];
        if (u1 <= u) {
          if (x4[i2 - 1] <= u) {
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
    i1 = x->size[1] - b_i;
    if (i1 > 0) {
      int8_T perm[4];
      d_st.site = &jk_emlrtRSI;
      if (i1 > 2147483646) {
        e_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
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
      d_st.site = &kk_emlrtRSI;
      for (k = 0; k < i1; k++) {
        i2 = perm[k] - 1;
        nQuartets = b_i + k;
        idx_data[nQuartets] = idx4[i2];
        x_data[nQuartets] = x4[i2];
      }
    }
    nQuartets = 2;
    if (x->size[1] > 1) {
      if (x->size[1] >= 256) {
        i4 = x->size[1] >> 8;
        c_st.site = &ek_emlrtRSI;
        for (b = 0; b < i4; b++) {
          int32_T b_iwork[256];
          int32_T offset;
          uint32_T b_xwork[256];
          c_st.site = &fk_emlrtRSI;
          offset = (b << 8) - 1;
          for (b_b = 0; b_b < 6; b_b++) {
            int32_T bLen;
            int32_T bLen2;
            bLen = 1 << (b_b + 2);
            bLen2 = bLen << 1;
            i = 256 >> (b_b + 3);
            d_st.site = &lk_emlrtRSI;
            for (k = 0; k < i; k++) {
              i1 = (offset + k * bLen2) + 1;
              d_st.site = &mk_emlrtRSI;
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
                    d_st.site = &nk_emlrtRSI;
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
        b_i = x->size[1] - nQuartets;
        if (b_i > 0) {
          c_st.site = &gk_emlrtRSI;
          merge_block(&c_st, idx, x, nQuartets, b_i, 2, iwork, xwork);
        }
        nQuartets = 8;
      }
      c_st.site = &hk_emlrtRSI;
      merge_block(&c_st, idx, x, 0, x->size[1], nQuartets, iwork, xwork);
    }
    emxFree_uint32_T(&b_st, &xwork);
    emxFree_int32_T(&b_st, &iwork);
  }
  emxFree_int32_T(&st, &idx);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void d_sort(const emlrtStack *sp, uint32_T x[20])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T idx[20];
  int32_T iwork[20];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T j;
  uint32_T xwork[20];
  uint32_T x4[4];
  int8_T idx4[4];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bab_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ck_emlrtRSI;
  for (j = 0; j < 5; j++) {
    int32_T i4;
    uint32_T u;
    uint32_T u1;
    uint32_T u2;
    uint32_T u3;
    int8_T b_i;
    int8_T b_i1;
    int8_T b_i2;
    int8_T b_i3;
    i = j << 2;
    idx4[0] = (int8_T)(i + 1);
    idx4[1] = (int8_T)(i + 2);
    idx4[2] = (int8_T)(i + 3);
    idx4[3] = (int8_T)(i + 4);
    u = x[i];
    x4[0] = u;
    u1 = x[i + 1];
    x4[1] = u1;
    u2 = x[i + 2];
    x4[2] = u2;
    u3 = x[i + 3];
    x4[3] = u3;
    if (u <= u1) {
      i1 = 1;
      i2 = 2;
    } else {
      i1 = 2;
      i2 = 1;
    }
    if (u2 <= u3) {
      i3 = 3;
      i4 = 4;
    } else {
      i3 = 4;
      i4 = 3;
    }
    u = x4[i3 - 1];
    u1 = x4[i1 - 1];
    if (u1 <= u) {
      u1 = x4[i2 - 1];
      if (u1 <= u) {
        b_i = (int8_T)i1;
        b_i1 = (int8_T)i2;
        b_i2 = (int8_T)i3;
        b_i3 = (int8_T)i4;
      } else if (u1 <= x4[i4 - 1]) {
        b_i = (int8_T)i1;
        b_i1 = (int8_T)i3;
        b_i2 = (int8_T)i2;
        b_i3 = (int8_T)i4;
      } else {
        b_i = (int8_T)i1;
        b_i1 = (int8_T)i3;
        b_i2 = (int8_T)i4;
        b_i3 = (int8_T)i2;
      }
    } else {
      u = x4[i4 - 1];
      if (u1 <= u) {
        if (x4[i2 - 1] <= u) {
          b_i = (int8_T)i3;
          b_i1 = (int8_T)i1;
          b_i2 = (int8_T)i2;
          b_i3 = (int8_T)i4;
        } else {
          b_i = (int8_T)i3;
          b_i1 = (int8_T)i1;
          b_i2 = (int8_T)i4;
          b_i3 = (int8_T)i2;
        }
      } else {
        b_i = (int8_T)i3;
        b_i1 = (int8_T)i4;
        b_i2 = (int8_T)i1;
        b_i3 = (int8_T)i2;
      }
    }
    idx[i] = idx4[b_i - 1];
    idx[i + 1] = idx4[b_i1 - 1];
    idx[i + 2] = idx4[b_i2 - 1];
    idx[i + 3] = idx4[b_i3 - 1];
    x[i] = x4[b_i - 1];
    x[i + 1] = x4[b_i1 - 1];
    x[i + 2] = x4[b_i2 - 1];
    x[i + 3] = x4[b_i3 - 1];
  }
  c_st.site = &hk_emlrtRSI;
  memset(&iwork[0], 0, 20U * sizeof(int32_T));
  memset(&xwork[0], 0, 20U * sizeof(uint32_T));
  i2 = 5;
  i1 = 4;
  while (i2 > 1) {
    if ((i2 & 1) != 0) {
      i2--;
      i = i1 * i2;
      if (20 - i > i1) {
        d_st.site = &ok_emlrtRSI;
        c_merge(&d_st, idx, x, i, i1, 20 - (i + i1), iwork, xwork);
      }
    }
    i = i1 << 1;
    i2 >>= 1;
    for (i3 = 0; i3 < i2; i3++) {
      d_st.site = &qk_emlrtRSI;
      c_merge(&d_st, idx, x, i3 * i, i1, i1, iwork, xwork);
    }
    i1 = i;
  }
  if (i1 < 20) {
    d_st.site = &rk_emlrtRSI;
    c_merge(&d_st, idx, x, 0, i1, 20 - i1, iwork, xwork);
  }
}

void e_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bab_emlrtRSI;
  d_sortIdx(&st, x, idx);
}

void f_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *iidx;
  emxArray_real_T *vwork;
  real_T *vwork_data;
  real_T *x_data;
  int32_T dim;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  int32_T *idx_data;
  int32_T *iidx_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    i = x->size[0];
  } else {
    i = 1;
  }
  vlen = i - 1;
  emxInit_real_T(sp, &vwork, 1, &co_emlrtRTEI, true);
  i1 = vwork->size[0];
  vwork->size[0] = i;
  emxEnsureCapacity_real_T(sp, vwork, i1, &bo_emlrtRTEI);
  vwork_data = vwork->data;
  i1 = idx->size[0];
  idx->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(sp, idx, i1, &jo_emlrtRTEI);
  idx_data = idx->data;
  st.site = &uj_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }
  st.site = &vj_emlrtRSI;
  st.site = &wj_emlrtRSI;
  if (vstride > 2147483646) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  emxInit_int32_T(sp, &iidx, 1, &do_emlrtRTEI);
  for (dim = 0; dim < vstride; dim++) {
    st.site = &xj_emlrtRSI;
    if (i > 2147483646) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork_data[k] = x_data[dim + k * vstride];
    }
    st.site = &yj_emlrtRSI;
    e_sortIdx(&st, vwork, iidx);
    iidx_data = iidx->data;
    vwork_data = vwork->data;
    st.site = &ak_emlrtRSI;
    for (k = 0; k <= vlen; k++) {
      i1 = dim + k * vstride;
      x_data[i1] = vwork_data[k];
      idx_data[i1] = iidx_data[k];
    }
  }
  emxFree_int32_T(sp, &iidx);
  emxFree_real_T(sp, &vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void g_sort(const emlrtStack *sp, real_T x_data[], int32_T x_size[2],
            int32_T idx_data[], int32_T idx_size[2])
{
  emlrtStack st;
  emxArray_int32_T *idx;
  emxArray_real_T *x;
  real_T *b_x_data;
  int32_T i;
  int32_T loop_ub;
  int32_T *b_idx_data;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &x, 2, &do_emlrtRTEI, true);
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = x_size[1];
  emxEnsureCapacity_real_T(sp, x, i, &jp_emlrtRTEI);
  b_x_data = x->data;
  loop_ub = x_size[1];
  for (i = 0; i < loop_ub; i++) {
    b_x_data[i] = x_data[i];
  }
  emxInit_int32_T(sp, &idx, 2, &do_emlrtRTEI);
  st.site = &bab_emlrtRSI;
  d_sortIdx(&st, x, idx);
  b_idx_data = idx->data;
  b_x_data = x->data;
  idx_size[0] = 1;
  idx_size[1] = idx->size[1];
  loop_ub = idx->size[1];
  for (i = 0; i < loop_ub; i++) {
    idx_data[i] = b_idx_data[i];
  }
  emxFree_int32_T(sp, &idx);
  x_size[0] = 1;
  x_size[1] = x->size[1];
  loop_ub = x->size[1];
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = b_x_data[i];
  }
  emxFree_real_T(sp, &x);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void sort(const emlrtStack *sp, emxArray_uint32_T *x)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *iqb_emlrtRSI;
  emxArray_uint32_T *vwork;
  int32_T dim;
  int32_T i;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  uint32_T *vwork_data;
  uint32_T *x_data;
  boolean_T b_overflow;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    i = x->size[0];
  } else {
    i = 1;
  }
  vlen = i - 1;
  emxInit_uint32_T(sp, &vwork, 1, &co_emlrtRTEI, true);
  vstride = vwork->size[0];
  vwork->size[0] = i;
  emxEnsureCapacity_uint32_T(sp, vwork, vstride, &bo_emlrtRTEI);
  vwork_data = vwork->data;
  st.site = &uj_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }
  st.site = &vj_emlrtRSI;
  overflow = (i > 2147483646);
  b_overflow = (i > 2147483646);
  st.site = &wj_emlrtRSI;
  if (vstride > 2147483646) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  emxInit_int32_T(sp, &iqb_emlrtRSI, 1, &do_emlrtRTEI);
  for (dim = 0; dim < vstride; dim++) {
    st.site = &xj_emlrtRSI;
    if (overflow) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork_data[k] = x_data[dim + k * vstride];
    }
    st.site = &yj_emlrtRSI;
    b_sortIdx(&st, vwork, iqb_emlrtRSI);
    vwork_data = vwork->data;
    st.site = &ak_emlrtRSI;
    if (b_overflow) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      x_data[dim + k * vstride] = vwork_data[k];
    }
  }
  emxFree_int32_T(sp, &iqb_emlrtRSI);
  emxFree_uint32_T(sp, &vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (sort.c) */
