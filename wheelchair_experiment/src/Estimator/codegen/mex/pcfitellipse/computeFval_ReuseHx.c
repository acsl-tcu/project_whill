/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeFval_ReuseHx.c
 *
 * Code generation for function 'computeFval_ReuseHx'
 *
 */

/* Include files */
#include "computeFval_ReuseHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include "xdot.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo gg_emlrtRSI = {
    1,                     /* lineNo */
    "computeFval_ReuseHx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeFval_ReuseHx.p" /* pathName */
};

static emlrtBCInfo bd_emlrtBCI = {
    1,                     /* iFirst */
    8,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeFval_ReuseHx", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeFval_ReuseHx.p", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    1,                     /* iFirst */
    7,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeFval_ReuseHx", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeFval_ReuseHx.p", /* pName */
    0                                   /* checkKind */
};

/* Function Definitions */
real_T computeFval_ReuseHx(const emlrtStack *sp, const b_struct_T *obj,
                           real_T workspace[120], const real_T f[8],
                           const real_T x[8])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T val;
  int32_T b_i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  switch (obj->objtype) {
  case 5:
    if ((obj->nvar < 1) || (obj->nvar > 8)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, 8, &bd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    val = obj->gammaScalar * x[obj->nvar - 1];
    break;
  case 3: {
    if (obj->hasLinear) {
      int32_T i;
      int32_T vectorUB;
      st.site = &gg_emlrtRSI;
      if (obj->nvar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      i = (uint8_T)obj->nvar;
      idx = (i / 2) << 1;
      vectorUB = idx - 2;
      for (b_i = 0; b_i <= vectorUB; b_i += 2) {
        __m128d r;
        if (b_i + 1 > 7) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, 7, &cd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        r = _mm_loadu_pd(&obj->Hx[b_i]);
        _mm_storeu_pd(
            &workspace[b_i],
            _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5), r), _mm_loadu_pd(&f[b_i])));
      }
      for (b_i = idx; b_i < i; b_i++) {
        if (b_i + 1 > 7) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, 7, &cd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        workspace[b_i] = 0.5 * obj->Hx[b_i] + f[b_i];
      }
      st.site = &gg_emlrtRSI;
      val = xdot(&st, obj->nvar, x, workspace);
    } else {
      st.site = &gg_emlrtRSI;
      val = b_xdot(&st, obj->nvar, x, obj->Hx);
      val *= 0.5;
    }
  } break;
  default: {
    if (obj->hasLinear) {
      int32_T i;
      st.site = &gg_emlrtRSI;
      if (obj->nvar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      i = (uint8_T)obj->nvar;
      if (i - 1 >= 0) {
        memcpy(&workspace[0], &f[0], (uint32_T)i * sizeof(real_T));
      }
      idx = 6 - obj->nvar;
      st.site = &gg_emlrtRSI;
      if (7 - obj->nvar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (b_i = 0; b_i <= idx; b_i++) {
        workspace[obj->nvar + b_i] = obj->rho;
      }
      st.site = &gg_emlrtRSI;
      for (b_i = 0; b_i <= 4; b_i += 2) {
        __m128d r;
        __m128d r1;
        r = _mm_loadu_pd(&obj->Hx[b_i]);
        r = _mm_mul_pd(_mm_set1_pd(0.5), r);
        r1 = _mm_loadu_pd(&workspace[b_i]);
        r = _mm_add_pd(r1, r);
        _mm_storeu_pd(&workspace[b_i], r);
      }
      workspace[6] += 0.5 * obj->Hx[6];
      st.site = &gg_emlrtRSI;
      val = xdot(&st, 7, x, workspace);
    } else {
      int32_T i;
      st.site = &gg_emlrtRSI;
      val = b_xdot(&st, 7, x, obj->Hx);
      val *= 0.5;
      i = obj->nvar + 1;
      st.site = &gg_emlrtRSI;
      for (idx = i; idx < 8; idx++) {
        val += x[idx - 1] * obj->rho;
      }
    }
  } break;
  }
  return val;
}

/* End of code generation (computeFval_ReuseHx.c) */
