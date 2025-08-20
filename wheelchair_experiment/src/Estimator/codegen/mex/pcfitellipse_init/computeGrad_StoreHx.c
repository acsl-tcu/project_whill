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
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wf_emlrtRSI = {
    1,                     /* lineNo */
    "computeGrad_StoreHx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeGrad_StoreHx.p" /* pathName */
};

static emlrtBCInfo rc_emlrtBCI = {
    1,                     /* iFirst */
    7,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeGrad_StoreHx", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeGrad_StoreHx.p", /* pName */
    3                                   /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    1,                     /* iFirst */
    6,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeGrad_StoreHx", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\computeGrad_StoreHx.p", /* pName */
    0                                   /* checkKind */
};

/* Function Definitions */
void computeGrad_StoreHx(const emlrtStack *sp, struct_T *obj,
                         const real_T H[25], const real_T f[7],
                         const real_T x[7])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T ixlast;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  switch (obj->objtype) {
  case 5:
    ixlast = obj->nvar;
    st.site = &wf_emlrtRSI;
    if (obj->nvar - 1 > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    if (ixlast - 2 >= 0) {
      memset(&obj->grad[0], 0, (uint32_T)(ixlast - 1) * sizeof(real_T));
    }
    if ((obj->nvar < 1) || (obj->nvar > 7)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, 7, &rc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;
  case 3: {
    int32_T i;
    st.site = &wf_emlrtRSI;
    xgemv(&st, obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    st.site = &wf_emlrtRSI;
    if (obj->nvar > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)obj->nvar;
    for (ixlast = 0; ixlast < i; ixlast++) {
      if (ixlast + 1 > 6) {
        emlrtDynamicBoundsCheckR2012b(ixlast + 1, 1, 6, &sc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->grad[ixlast] = obj->Hx[ixlast];
    }
    if (obj->hasLinear && (obj->nvar >= 1)) {
      int32_T scalarLB;
      int32_T vectorUB;
      ixlast = obj->nvar - 1;
      scalarLB = ((ixlast + 1) / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj->grad[k]);
        _mm_storeu_pd(&obj->grad[k], _mm_add_pd(r, _mm_loadu_pd(&f[k])));
      }
      for (k = scalarLB; k <= ixlast; k++) {
        obj->grad[k] += f[k];
      }
    }
  } break;
  default: {
    __m128d r;
    int32_T i;
    int32_T scalarLB;
    int32_T vectorUB;
    st.site = &wf_emlrtRSI;
    xgemv(&st, obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    i = obj->nvar + 1;
    st.site = &wf_emlrtRSI;
    scalarLB = (((7 - i) / 2) << 1) + i;
    vectorUB = scalarLB - 2;
    for (ixlast = i; ixlast <= vectorUB; ixlast += 2) {
      _mm_storeu_pd(
          &obj->Hx[ixlast - 1],
          _mm_mul_pd(_mm_set1_pd(obj->beta), _mm_loadu_pd(&x[ixlast - 1])));
    }
    for (ixlast = scalarLB; ixlast < 7; ixlast++) {
      obj->Hx[ixlast - 1] = obj->beta * x[ixlast - 1];
    }
    st.site = &wf_emlrtRSI;
    for (ixlast = 0; ixlast < 6; ixlast++) {
      obj->grad[ixlast] = obj->Hx[ixlast];
    }
    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar - 1;
      scalarLB = ((ixlast + 1) / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        r = _mm_loadu_pd(&obj->grad[k]);
        _mm_storeu_pd(&obj->grad[k], _mm_add_pd(r, _mm_loadu_pd(&f[k])));
      }
      for (k = scalarLB; k <= ixlast; k++) {
        obj->grad[k] += f[k];
      }
    }
    if (6 - obj->nvar >= 1) {
      int32_T i1;
      ixlast = obj->nvar;
      i = 5 - obj->nvar;
      scalarLB = ((i + 1) / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        i1 = ixlast + k;
        r = _mm_loadu_pd(&obj->grad[i1]);
        _mm_storeu_pd(&obj->grad[i1], _mm_add_pd(r, _mm_set1_pd(obj->rho)));
      }
      for (k = scalarLB; k <= i; k++) {
        i1 = ixlast + k;
        obj->grad[i1] += obj->rho;
      }
    }
  } break;
  }
}

/* End of code generation (computeGrad_StoreHx.c) */
