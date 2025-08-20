/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dot.c
 *
 * Code generation for function 'dot'
 *
 */

/* Include files */
#include "dot.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <emmintrin.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo ne_emlrtRSI = {
    51,    /* lineNo */
    "dot", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" /* pathName
                                                                     */
};

static emlrtRSInfo oe_emlrtRSI = {
    67,    /* lineNo */
    "dot", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" /* pathName
                                                                     */
};

static emlrtRSInfo pe_emlrtRSI = {
    70,    /* lineNo */
    "dot", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" /* pathName
                                                                     */
};

static emlrtRTEInfo n_emlrtRTEI = {
    12,                                                             /* lineNo */
    23,                                                             /* colNo */
    "dot",                                                          /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" /* pName */
};

static emlrtRTEInfo yh_emlrtRTEI = {
    60,                                                             /* lineNo */
    20,                                                             /* colNo */
    "dot",                                                          /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" /* pName */
};

static emlrtRTEInfo ai_emlrtRTEI = {
    47,                                                             /* lineNo */
    28,                                                             /* colNo */
    "dot",                                                          /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" /* pName */
};

/* Function Definitions */
void dot(const emlrtStack *sp, const emxArray_real_T *a,
         const emxArray_real_T *b, emxArray_real_T *c)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *a_data;
  const real_T *b_data;
  real_T *c_data;
  int32_T i;
  int32_T j;
  int32_T k;
  uint32_T sz[4];
  uint32_T varargin_2[4];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_data = b->data;
  a_data = a->data;
  sz[0] = (uint32_T)a->size[0];
  varargin_2[0] = (uint32_T)b->size[0];
  sz[1] = (uint32_T)a->size[1];
  varargin_2[1] = (uint32_T)b->size[1];
  sz[2] = (uint32_T)a->size[2];
  varargin_2[2] = (uint32_T)b->size[2];
  sz[3] = (uint32_T)a->size[3];
  varargin_2[3] = (uint32_T)b->size[3];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if ((int32_T)sz[k] != (int32_T)varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if ((!p) && (((a->size[0] != 1) && (a->size[1] != 1)) || (a->size[2] != 1) ||
               (a->size[3] != 1) ||
               (((b->size[0] != 1) && (b->size[1] != 1)) || (b->size[2] != 1) ||
                (b->size[3] != 1)) ||
               (a->size[0] * a->size[1] != b->size[0] * b->size[1]))) {
    emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
                                  "MATLAB:dot:InputSizeMismatch",
                                  "MATLAB:dot:InputSizeMismatch", 0);
  }
  if (a->size[1] == 1) {
    int32_T vlen;
    int32_T vstride;
    k = c->size[0] * c->size[1] * c->size[2] * c->size[3];
    c->size[0] = a->size[0];
    c->size[1] = 1;
    c->size[2] = a->size[2];
    c->size[3] = a->size[3];
    emxEnsureCapacity_real_T(sp, c, k, &ai_emlrtRTEI);
    c_data = c->data;
    k = a->size[0] * a->size[2] * a->size[3];
    st.site = &ne_emlrtRSI;
    if (k > 2147483646) {
      b_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    vlen = (k / 2) << 1;
    vstride = vlen - 2;
    for (j = 0; j <= vstride; j += 2) {
      _mm_storeu_pd(&c_data[j], _mm_mul_pd(_mm_loadu_pd(&a_data[j]),
                                           _mm_loadu_pd(&b_data[j])));
    }
    for (j = vlen; j < k; j++) {
      c_data[j] = a_data[j] * b_data[j];
    }
  } else {
    int32_T i2;
    int32_T ic;
    int32_T npages;
    int32_T vlen;
    int32_T vspread;
    int32_T vstride;
    k = c->size[0] * c->size[1] * c->size[2] * c->size[3];
    c->size[0] = a->size[0];
    c->size[1] = 1;
    c->size[2] = a->size[2];
    c->size[3] = a->size[3];
    emxEnsureCapacity_real_T(sp, c, k, &yh_emlrtRTEI);
    c_data = c->data;
    vlen = a->size[1];
    vstride = a->size[0];
    vspread = (a->size[1] - 1) * a->size[0];
    npages = a->size[2] * a->size[3];
    i2 = -1;
    ic = -1;
    st.site = &oe_emlrtRSI;
    if (npages > 2147483646) {
      b_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i = 0; i < npages; i++) {
      int32_T i1;
      i1 = i2;
      i2 += vspread;
      st.site = &pe_emlrtRSI;
      if (vstride > 2147483646) {
        b_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      k = (uint8_T)vstride;
      for (j = 0; j < k; j++) {
        i2++;
        if (vlen < 1) {
          c_data[(ic + j) + 1] = 0.0;
        } else {
          int32_T b_i;
          n_t = (ptrdiff_t)vlen;
          incx_t = (ptrdiff_t)vstride;
          incy_t = (ptrdiff_t)vstride;
          b_i = (i1 + j) + 1;
          c_data[(ic + j) + 1] = ddot(&n_t, (real_T *)&a_data[b_i], &incx_t,
                                      (real_T *)&b_data[b_i], &incy_t);
        }
      }
      if ((uint8_T)vstride - 1 >= 0) {
        ic += (uint8_T)vstride;
      }
    }
  }
}

/* End of code generation (dot.c) */
