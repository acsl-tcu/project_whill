/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * jpdaWeightInnovationAndCovariances.c
 *
 * Code generation for function 'jpdaWeightInnovationAndCovariances'
 *
 */

/* Include files */
#include "jpdaWeightInnovationAndCovariances.h"
#include "all.h"
#include "eml_int_forloop_overflow_check.h"
#include "ixfun.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "wrapResidual.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo vmb_emlrtRSI = {
    27,                                   /* lineNo */
    "jpdaWeightInnovationAndCovariances", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/jpdaWeightInnovationAndCovariance"
    "s.m" /* pathName */
};

static emlrtRSInfo wmb_emlrtRSI = {
    28,                                   /* lineNo */
    "jpdaWeightInnovationAndCovariances", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/jpdaWeightInnovationAndCovariance"
    "s.m" /* pathName */
};

static emlrtRSInfo xmb_emlrtRSI = {
    26,             /* lineNo */
    "wrapResidual", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pathName */
};

static emlrtRSInfo ymb_emlrtRSI = {
    44,             /* lineNo */
    "wrapResidual", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pathName */
};

static emlrtRSInfo anb_emlrtRSI = {
    49,             /* lineNo */
    "wrapResidual", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pathName */
};

static emlrtRSInfo bnb_emlrtRSI = {
    18,                                                           /* lineNo */
    "abs",                                                        /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elfun/abs.m" /* pathName */
};

static emlrtRSInfo cnb_emlrtRSI = {
    74,                    /* lineNo */
    "applyScalarFunction", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunction.m" /* pathName */
};

static emlrtRSInfo dnb_emlrtRSI =
    {
        318,                     /* lineNo */
        "unaryMinOrMaxDispatch", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo enb_emlrtRSI =
    {
        392,          /* lineNo */
        "minOrMax2D", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo fnb_emlrtRSI =
    {
        496,                         /* lineNo */
        "minOrMax2DColumnMajorDim2", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo gnb_emlrtRSI = {
    75,                                                           /* lineNo */
    "mod",                                                        /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elfun/mod.m" /* pathName */
};

static emlrtRSInfo hnb_emlrtRSI = {
    57,      /* lineNo */
    "ixfun", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pathName
                                                                         */
};

static emlrtRSInfo inb_emlrtRSI = {
    102,                          /* lineNo */
    "binaryImplicitExpansionFun", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pathName
                                                                         */
};

static emlrtECInfo db_emlrtECI = {
    1,              /* nDims */
    49,             /* lineNo */
    13,             /* colNo */
    "wrapResidual", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = {
    53,       /* lineNo */
    15,       /* colNo */
    "bsxfun", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/bsxfun.m" /* pName */
};

static emlrtRTEInfo pk_emlrtRTEI = {
    60,       /* lineNo */
    20,       /* colNo */
    "bsxfun", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/bsxfun.m" /* pName */
};

static emlrtRTEInfo bn_emlrtRTEI = {
    26,                                   /* lineNo */
    63,                                   /* colNo */
    "jpdaWeightInnovationAndCovariances", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/jpdaWeightInnovationAndCovariance"
    "s.m" /* pName */
};

static emlrtRTEInfo cn_emlrtRTEI = {
    30,                    /* lineNo */
    21,                    /* colNo */
    "applyScalarFunction", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunction.m" /* pName */
};

static emlrtRTEInfo dn_emlrtRTEI = {
    49,             /* lineNo */
    18,             /* colNo */
    "wrapResidual", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pName */
};

static emlrtRTEInfo en_emlrtRTEI = {
    49,             /* lineNo */
    13,             /* colNo */
    "wrapResidual", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pName */
};

static emlrtRTEInfo gn_emlrtRTEI = {
    26,                                   /* lineNo */
    5,                                    /* colNo */
    "jpdaWeightInnovationAndCovariances", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/jpdaWeightInnovationAndCovariance"
    "s.m" /* pName */
};

static emlrtRTEInfo hn_emlrtRTEI = {
    46,             /* lineNo */
    1,              /* colNo */
    "wrapResidual", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pName */
};

static emlrtRTEInfo in_emlrtRTEI = {
    44,             /* lineNo */
    10,             /* colNo */
    "wrapResidual", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pName */
};

/* Function Definitions */
void c_jpdaWeightInnovationAndCovari(const emlrtStack *sp,
                                     const emxArray_real_T *z,
                                     const real_T zEstimated[3],
                                     const emxArray_real_T *beta,
                                     const real_T wrapping[6], real_T y[3],
                                     real_T yy[9])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  emxArray_real_T *innovations;
  emxArray_real_T *r1;
  emxArray_real_T *resToWrap;
  emxArray_real_T *varargin_1;
  real_T bounds[6];
  const real_T *beta_data;
  const real_T *z_data;
  real_T alpha1;
  real_T beta1;
  real_T *innovations_data;
  real_T *r2;
  real_T *resToWrap_data;
  int32_T c_y[2];
  int32_T tmp_size[2];
  int32_T acoef;
  int32_T bcoef;
  int32_T csz_idx_1;
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T nx;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T c_tmp_data[3];
  int8_T tmp_data[3];
  boolean_T isf[3];
  boolean_T b_y;
  boolean_T exitg1;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  beta_data = beta->data;
  z_data = z->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &umb_emlrtRSI;
  emxInit_real_T(&st, &innovations, 2, &gn_emlrtRTEI, true);
  i = innovations->size[0] * innovations->size[1];
  innovations->size[0] = 3;
  innovations->size[1] = z->size[1];
  emxEnsureCapacity_real_T(&st, innovations, i, &bn_emlrtRTEI);
  innovations_data = innovations->data;
  loop_ub = z->size[1];
  for (i = 0; i < loop_ub; i++) {
    _mm_storeu_pd(
        &innovations_data[3 * i],
        _mm_sub_pd(_mm_loadu_pd(&z_data[3 * i]), _mm_loadu_pd(&zEstimated[0])));
    bcoef = 3 * i + 2;
    innovations_data[bcoef] = z_data[bcoef] - zEstimated[2];
  }
  for (i = 0; i < 6; i++) {
    bounds[i] = wrapping[i];
  }
  b_st.site = &xmb_emlrtRSI;
  d_all(isf);
  b_y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 2)) {
    if (isf[k]) {
      b_y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  emxInit_real_T(&st, &varargin_1, 2, &in_emlrtRTEI, true);
  if (b_y) {
    real_T b_tmp_data[6];
    real_T ma[3];
    int8_T i1;
    boolean_T b;
    boolean_T b1;
    acoef = 0;
    if (isf[0]) {
      acoef = 1;
    }
    if (isf[1]) {
      acoef++;
    }
    if (isf[2]) {
      acoef++;
    }
    nx = 0;
    if (isf[0]) {
      tmp_data[0] = 0;
      nx = 1;
    }
    if (isf[1]) {
      tmp_data[nx] = 1;
      nx++;
    }
    if (isf[2]) {
      tmp_data[nx] = 2;
    }
    for (i = 0; i < acoef; i++) {
      i1 = tmp_data[i];
      ma[i] = (wrapping[i1 + 3] + wrapping[i1]) / 2.0;
    }
    tmp_size[0] = acoef;
    tmp_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (bcoef = 0; bcoef < acoef; bcoef++) {
        b_tmp_data[bcoef + acoef * i] =
            wrapping[tmp_data[bcoef] + 3 * i] - ma[bcoef];
      }
    }
    c_y[0] = acoef;
    c_y[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&c_y[0], 2, &tmp_size[0], 2, &cb_emlrtECI,
                                  &st);
    for (i = 0; i < 2; i++) {
      for (bcoef = 0; bcoef < acoef; bcoef++) {
        bounds[tmp_data[bcoef] + 3 * i] = b_tmp_data[bcoef + tmp_size[0] * i];
      }
    }
    b_st.site = &ymb_emlrtRSI;
    c_st.site = &ymb_emlrtRSI;
    d_st.site = &bnb_emlrtRSI;
    nx = 3 * innovations->size[1];
    i = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 3;
    varargin_1->size[1] = innovations->size[1];
    emxEnsureCapacity_real_T(&d_st, varargin_1, i, &cn_emlrtRTEI);
    resToWrap_data = varargin_1->data;
    e_st.site = &cnb_emlrtRSI;
    if (nx > 2147483646) {
      f_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (k = 0; k < nx; k++) {
      resToWrap_data[k] = muDoubleScalarAbs(innovations_data[k]);
    }
    c_st.site = &lf_emlrtRSI;
    d_st.site = &mf_emlrtRSI;
    e_st.site = &nf_emlrtRSI;
    if (varargin_1->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &eb_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    f_st.site = &gib_emlrtRSI;
    g_st.site = &dnb_emlrtRSI;
    h_st.site = &enb_emlrtRSI;
    nx = varargin_1->size[1];
    ma[0] = resToWrap_data[0];
    ma[1] = resToWrap_data[1];
    ma[2] = resToWrap_data[2];
    i_st.site = &fnb_emlrtRSI;
    if (varargin_1->size[1] > 2147483646) {
      j_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&j_st);
    }
    for (loop_ub = 2; loop_ub <= nx; loop_ub++) {
      for (acoef = 0; acoef < 3; acoef++) {
        alpha1 = resToWrap_data[acoef + 3 * (loop_ub - 1)];
        if (muDoubleScalarIsNaN(alpha1)) {
          b_y = false;
        } else {
          beta1 = ma[acoef];
          if (muDoubleScalarIsNaN(beta1)) {
            b_y = true;
          } else {
            b_y = (beta1 < alpha1);
          }
        }
        if (b_y) {
          ma[acoef] = alpha1;
        }
      }
    }
    acoef = 0;
    b_y = (isf[0] && (muDoubleScalarAbs(ma[0] / bounds[3]) > 0.001));
    if (b_y) {
      acoef = 1;
    }
    b = (isf[1] && (muDoubleScalarAbs(ma[1] / bounds[4]) > 0.001));
    if (b) {
      acoef++;
    }
    b1 = (isf[2] && (muDoubleScalarAbs(ma[2] / bounds[5]) > 0.001));
    if (b1) {
      acoef++;
    }
    nx = 0;
    if (b_y) {
      c_tmp_data[0] = 0;
      nx = 1;
    }
    if (b) {
      c_tmp_data[nx] = 1;
      nx++;
    }
    if (b1) {
      c_tmp_data[nx] = 2;
    }
    b_st.site = &anb_emlrtRSI;
    emxInit_real_T(&b_st, &resToWrap, 2, &hn_emlrtRTEI, true);
    i = resToWrap->size[0] * resToWrap->size[1];
    resToWrap->size[0] = acoef;
    resToWrap->size[1] = innovations->size[1];
    emxEnsureCapacity_real_T(&b_st, resToWrap, i, &dn_emlrtRTEI);
    resToWrap_data = resToWrap->data;
    loop_ub = innovations->size[1];
    for (i = 0; i < loop_ub; i++) {
      for (bcoef = 0; bcoef < acoef; bcoef++) {
        i1 = c_tmp_data[bcoef];
        resToWrap_data[bcoef + resToWrap->size[0] * i] =
            innovations_data[i1 + 3 * i] - bounds[i1];
      }
    }
    for (i = 0; i < acoef; i++) {
      i1 = c_tmp_data[i];
      ma[i] = bounds[i1 + 3] - bounds[i1];
    }
    c_st.site = &gnb_emlrtRSI;
    d_st.site = &hnb_emlrtRSI;
    emxInit_real_T(&d_st, &r1, 2, &en_emlrtRTEI, true);
    if ((resToWrap->size[0] == acoef) && (resToWrap->size[1] == 1)) {
      loop_ub = resToWrap->size[0];
      nx = resToWrap->size[0];
      for (i = 0; i < loop_ub; i++) {
        alpha1 = resToWrap_data[i];
        ma[i] = b_mod(alpha1, ma[i]);
      }
      i = r1->size[0] * r1->size[1];
      r1->size[0] = nx;
      r1->size[1] = 1;
      emxEnsureCapacity_real_T(&d_st, r1, i, &en_emlrtRTEI);
      r2 = r1->data;
      for (i = 0; i < nx; i++) {
        r2[i] = ma[i];
      }
    } else {
      e_st.site = &inb_emlrtRSI;
      expand_mod(&e_st, resToWrap, ma, acoef, r1);
      r2 = r1->data;
    }
    if ((r1->size[0] != acoef) && ((r1->size[0] != 1) && (acoef != 1))) {
      emlrtDimSizeImpxCheckR2021b(r1->size[0], acoef, &db_emlrtECI, &st);
    }
    if (r1->size[0] == acoef) {
      i = resToWrap->size[0] * resToWrap->size[1];
      resToWrap->size[0] = r1->size[0];
      resToWrap->size[1] = r1->size[1];
      emxEnsureCapacity_real_T(&st, resToWrap, i, &fn_emlrtRTEI);
      resToWrap_data = resToWrap->data;
      loop_ub = r1->size[1];
      for (i = 0; i < loop_ub; i++) {
        nx = r1->size[0];
        for (bcoef = 0; bcoef < nx; bcoef++) {
          resToWrap_data[bcoef + resToWrap->size[0] * i] =
              r2[bcoef + r1->size[0] * i] + bounds[c_tmp_data[bcoef]];
        }
      }
    } else {
      b_st.site = &anb_emlrtRSI;
      c_binary_expand_op(&b_st, resToWrap, r1, bounds, c_tmp_data, &acoef);
      resToWrap_data = resToWrap->data;
    }
    emxFree_real_T(&st, &r1);
    c_y[0] = acoef;
    c_y[1] = innovations->size[1];
    emlrtSubAssignSizeCheckR2012b(&c_y[0], 2, &resToWrap->size[0], 2,
                                  &eb_emlrtECI, &st);
    loop_ub = innovations->size[1];
    for (i = 0; i < loop_ub; i++) {
      for (bcoef = 0; bcoef < acoef; bcoef++) {
        innovations_data[c_tmp_data[bcoef] + 3 * i] =
            resToWrap_data[bcoef + acoef * i];
      }
    }
    emxFree_real_T(&st, &resToWrap);
  }
  st.site = &vmb_emlrtRSI;
  b_st.site = &qf_emlrtRSI;
  if (beta->size[0] != innovations->size[1]) {
    if (beta->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &r_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &s_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  b_st.site = &ef_emlrtRSI;
  if ((innovations->size[1] == 0) || (beta->size[0] == 0)) {
    y[0] = 0.0;
    y[1] = 0.0;
    y[2] = 0.0;
  } else {
    c_st.site = &ff_emlrtRSI;
    d_st.site = &hf_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)3;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)innovations->size[1];
    lda_t = (ptrdiff_t)3;
    ldb_t = (ptrdiff_t)beta->size[0];
    ldc_t = (ptrdiff_t)3;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &innovations_data[0],
          &lda_t, (real_T *)&beta_data[0], &ldb_t, &beta1, &y[0], &ldc_t);
  }
  st.site = &wmb_emlrtRSI;
  b_st.site = &wmb_emlrtRSI;
  if (innovations->size[1] == 1) {
    csz_idx_1 = beta->size[0];
  } else if (beta->size[0] == 1) {
    csz_idx_1 = innovations->size[1];
  } else if (beta->size[0] == innovations->size[1]) {
    csz_idx_1 = beta->size[0];
  } else {
    emlrtErrorWithMessageIdR2018a(&b_st, &ed_emlrtRTEI,
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch",
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }
  i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 3;
  varargin_1->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(&b_st, varargin_1, i, &pk_emlrtRTEI);
  resToWrap_data = varargin_1->data;
  if (csz_idx_1 != 0) {
    acoef = (beta->size[0] != 1);
    bcoef = (innovations->size[1] != 1);
    i = csz_idx_1 - 1;
    for (k = 0; k <= i; k++) {
      __m128d r;
      nx = acoef * k;
      loop_ub = bcoef * k;
      r = _mm_loadu_pd(&innovations_data[3 * loop_ub]);
      _mm_storeu_pd(&resToWrap_data[3 * k],
                    _mm_mul_pd(_mm_set1_pd(beta_data[nx]), r));
      resToWrap_data[3 * k + 2] =
          beta_data[nx] * innovations_data[3 * loop_ub + 2];
    }
  }
  b_st.site = &qf_emlrtRSI;
  if (varargin_1->size[1] != innovations->size[1]) {
    emlrtErrorWithMessageIdR2018a(&b_st, &s_emlrtRTEI, "MATLAB:innerdim",
                                  "MATLAB:innerdim", 0);
  }
  b_st.site = &ef_emlrtRSI;
  if ((varargin_1->size[1] == 0) || (innovations->size[1] == 0)) {
    memset(&yy[0], 0, 9U * sizeof(real_T));
  } else {
    c_st.site = &ff_emlrtRSI;
    d_st.site = &hf_emlrtRSI;
    TRANSB1 = 'T';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)3;
    n_t = (ptrdiff_t)3;
    k_t = (ptrdiff_t)varargin_1->size[1];
    lda_t = (ptrdiff_t)3;
    ldb_t = (ptrdiff_t)3;
    ldc_t = (ptrdiff_t)3;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &resToWrap_data[0],
          &lda_t, &innovations_data[0], &ldb_t, &beta1, &yy[0], &ldc_t);
  }
  emxFree_real_T(&b_st, &varargin_1);
  emxFree_real_T(&b_st, &innovations);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (jpdaWeightInnovationAndCovariances.c) */
