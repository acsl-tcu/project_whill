/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeGrad_StoreHx.c
 *
 * Code generation for function 'computeGrad_StoreHx'
 *
 */

/* Include files */
#include "computeGrad_StoreHx.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo yh_emlrtRSI = {
    1,                     /* lineNo */
    "computeGrad_StoreHx", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeGrad_StoreHx.p" /* pathName */
};

static emlrtBCInfo qd_emlrtBCI = {
    1,                     /* iFirst */
    8,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeGrad_StoreHx", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeGrad_StoreHx.p", /* pName */
    3                                   /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = {
    1,                     /* iFirst */
    7,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeGrad_StoreHx", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeGrad_StoreHx.p", /* pName */
    3                                   /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    1,                     /* iFirst */
    7,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeGrad_StoreHx", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeGrad_StoreHx.p", /* pName */
    0                                   /* checkKind */
};

/* Function Definitions */
void computeGrad_StoreHx(const emlrtStack *sp, l_struct_T *obj,
                         const real_T H[25], const real_T f[8],
                         const real_T x[8])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_i;
  int32_T ixlast;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  switch (obj->objtype) {
  case 5:
    ixlast = obj->nvar;
    st.site = &yh_emlrtRSI;
    if (obj->nvar - 1 > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (b_i = 0; b_i <= ixlast - 2; b_i++) {
      if ((b_i + 1 < 1) || (b_i + 1 > 8)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, 8, &qd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->grad[b_i] = 0.0;
    }
    if ((obj->nvar < 1) || (obj->nvar > 8)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, 8, &qd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;
  case 3: {
    st.site = &yh_emlrtRSI;
    xgemv(&st, obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    ixlast = obj->nvar;
    st.site = &yh_emlrtRSI;
    if (obj->nvar > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (b_i = 0; b_i < ixlast; b_i++) {
      if ((b_i + 1 < 1) || (b_i + 1 > 7)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, 7, &sd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->grad[b_i] = obj->Hx[b_i];
    }
    if (obj->hasLinear && (obj->nvar >= 1)) {
      int32_T scalarLB;
      int32_T vectorUB;
      scalarLB = (ixlast / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj->grad[k]);
        _mm_storeu_pd(&obj->grad[k], _mm_add_pd(r, _mm_loadu_pd(&f[k])));
      }
      for (k = scalarLB; k < ixlast; k++) {
        obj->grad[k] += f[k];
      }
    }
  } break;
  case 4: {
    __m128d r;
    int32_T i;
    int32_T scalarLB;
    int32_T vectorUB;
    st.site = &yh_emlrtRSI;
    xgemv(&st, obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    i = obj->nvar + 1;
    st.site = &yh_emlrtRSI;
    scalarLB = (((8 - i) / 2) << 1) + i;
    vectorUB = scalarLB - 2;
    for (ixlast = i; ixlast <= vectorUB; ixlast += 2) {
      if ((ixlast < 1) || (ixlast > 7)) {
        emlrtDynamicBoundsCheckR2012b(ixlast, 1, 7, &rd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      _mm_storeu_pd(
          &obj->Hx[ixlast - 1],
          _mm_mul_pd(_mm_set1_pd(obj->beta), _mm_loadu_pd(&x[ixlast - 1])));
    }
    for (ixlast = scalarLB; ixlast < 8; ixlast++) {
      if (ixlast < 1) {
        emlrtDynamicBoundsCheckR2012b(ixlast, 1, 7, &rd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->Hx[ixlast - 1] = obj->beta * x[ixlast - 1];
    }
    st.site = &yh_emlrtRSI;
    for (b_i = 0; b_i < 7; b_i++) {
      obj->grad[b_i] = obj->Hx[b_i];
    }
    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar;
      scalarLB = (ixlast / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        r = _mm_loadu_pd(&obj->grad[k]);
        _mm_storeu_pd(&obj->grad[k], _mm_add_pd(r, _mm_loadu_pd(&f[k])));
      }
      for (k = scalarLB; k < ixlast; k++) {
        obj->grad[k] += f[k];
      }
    }
    if (7 - obj->nvar >= 1) {
      ixlast = obj->nvar;
      i = 6 - obj->nvar;
      scalarLB = ((i + 1) / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        b_i = ixlast + k;
        r = _mm_loadu_pd(&obj->grad[b_i]);
        _mm_storeu_pd(&obj->grad[b_i], _mm_add_pd(r, _mm_set1_pd(obj->rho)));
      }
      for (k = scalarLB; k <= i; k++) {
        b_i = ixlast + k;
        obj->grad[b_i] += obj->rho;
      }
    }
  } break;
  }
}

/* End of code generation (computeGrad_StoreHx.c) */
