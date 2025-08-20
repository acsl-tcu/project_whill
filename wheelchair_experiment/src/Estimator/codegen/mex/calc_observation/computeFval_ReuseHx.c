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
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xdot.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ai_emlrtRSI = {
    1,                     /* lineNo */
    "computeFval_ReuseHx", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval_ReuseHx.p" /* pathName */
};

static emlrtBCInfo td_emlrtBCI = {
    1,                     /* iFirst */
    8,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeFval_ReuseHx", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval_ReuseHx.p", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = {
    1,                     /* iFirst */
    7,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeFval_ReuseHx", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval_ReuseHx.p", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = {
    1,                     /* iFirst */
    120,                   /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "computeFval_ReuseHx", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval_ReuseHx.p", /* pName */
    3                                   /* checkKind */
};

/* Function Definitions */
real_T computeFval_ReuseHx(const emlrtStack *sp, const l_struct_T *obj,
                           real_T workspace[120], const real_T f[8],
                           const real_T x[8])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T val;
  int32_T b;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  val = 0.0;
  switch (obj->objtype) {
  case 5:
    if ((obj->nvar < 1) || (obj->nvar > 8)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, 8, &td_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    val = obj->gammaScalar * x[obj->nvar - 1];
    break;
  case 3: {
    if (obj->hasLinear) {
      int32_T scalarLB;
      int32_T vectorUB;
      b = obj->nvar;
      st.site = &ai_emlrtRSI;
      if (obj->nvar > 2147483646) {
        b_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      scalarLB = (b / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        __m128d r;
        if ((i + 1 < 1) || (i + 1 > 7)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, 7, &ud_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        r = _mm_loadu_pd(&obj->Hx[i]);
        if ((i + 1 < 1) || (i + 1 > 120)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, 120, &vd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        _mm_storeu_pd(&workspace[i], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5), r),
                                                _mm_loadu_pd(&f[i])));
      }
      for (i = scalarLB; i < b; i++) {
        if ((i + 1 < 1) || (i + 1 > 7)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, 7, &ud_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if ((i + 1 < 1) || (i + 1 > 120)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, 120, &vd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        workspace[i] = 0.5 * obj->Hx[i] + f[i];
      }
      st.site = &ai_emlrtRSI;
      val = xdot(&st, obj->nvar, x, workspace);
    } else {
      st.site = &ai_emlrtRSI;
      val = b_xdot(&st, obj->nvar, x, obj->Hx);
      val *= 0.5;
    }
  } break;
  case 4: {
    if (obj->hasLinear) {
      b = obj->nvar;
      st.site = &ai_emlrtRSI;
      if (obj->nvar > 2147483646) {
        b_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < b; i++) {
        if ((i + 1 < 1) || (i + 1 > 8)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, 8, &td_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        workspace[i] = f[i];
      }
      b = 7 - obj->nvar;
      st.site = &ai_emlrtRSI;
      if (b > 2147483646) {
        b_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < b; i++) {
        int32_T scalarLB;
        scalarLB = (obj->nvar + i) + 1;
        if ((scalarLB < 1) || (scalarLB > 120)) {
          emlrtDynamicBoundsCheckR2012b(scalarLB, 1, 120, &vd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        workspace[scalarLB - 1] = obj->rho;
      }
      st.site = &ai_emlrtRSI;
      for (i = 0; i <= 4; i += 2) {
        __m128d r;
        __m128d r1;
        r = _mm_loadu_pd(&obj->Hx[i]);
        r = _mm_mul_pd(_mm_set1_pd(0.5), r);
        r1 = _mm_loadu_pd(&workspace[i]);
        r = _mm_add_pd(r1, r);
        _mm_storeu_pd(&workspace[i], r);
      }
      workspace[6] += 0.5 * obj->Hx[6];
      st.site = &ai_emlrtRSI;
      val = xdot(&st, 7, x, workspace);
    } else {
      int32_T scalarLB;
      st.site = &ai_emlrtRSI;
      val = b_xdot(&st, 7, x, obj->Hx);
      val *= 0.5;
      scalarLB = obj->nvar + 1;
      st.site = &ai_emlrtRSI;
      for (b = scalarLB; b < 8; b++) {
        if (b < 1) {
          emlrtDynamicBoundsCheckR2012b(b, 1, 8, &td_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        val += x[b - 1] * obj->rho;
      }
    }
  } break;
  }
  return val;
}

/* End of code generation (computeFval_ReuseHx.c) */
