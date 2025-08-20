/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeFval.c
 *
 * Code generation for function 'computeFval'
 *
 */

/* Include files */
#include "computeFval.h"
#include "calc_observation_internal_types.h"
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include "xdot.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo sj_emlrtRSI = {
    1,             /* lineNo */
    "computeFval", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval.p" /* pathName */
};

static emlrtBCInfo xe_emlrtBCI = {
    1,             /* iFirst */
    8,             /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "computeFval", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval.p", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = {
    1,                /* iFirst */
    120,              /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "linearFormReg_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/linearFormReg_.p", /* pName */
    3                              /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = {
    1,             /* iFirst */
    120,           /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "computeFval", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval.p", /* pName */
    3                           /* checkKind */
};

/* Function Definitions */
real_T computeFval(const emlrtStack *sp, const l_struct_T *obj,
                   real_T workspace[120], const real_T H[25], const real_T f[8],
                   const real_T x[8])
{
  emlrtStack st;
  real_T val;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  val = 0.0;
  switch (obj->objtype) {
  case 5:
    if ((obj->nvar < 1) || (obj->nvar > 8)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, 8, &xe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    val = obj->gammaScalar * x[obj->nvar - 1];
    break;
  case 3:
    st.site = &sj_emlrtRSI;
    linearForm_(&st, obj->hasLinear, obj->nvar, workspace, H, f, x);
    st.site = &sj_emlrtRSI;
    val = xdot(&st, obj->nvar, x, workspace);
    break;
  case 4: {
    int32_T i;
    int32_T scalarLB;
    int32_T vectorUB;
    st.site = &sj_emlrtRSI;
    linearForm_(&st, obj->hasLinear, obj->nvar, workspace, H, f, x);
    st.site = &sj_emlrtRSI;
    i = obj->nvar + 1;
    scalarLB = (((8 - i) / 2) << 1) + i;
    vectorUB = scalarLB - 2;
    for (idx = i; idx <= vectorUB; idx += 2) {
      if ((idx < 1) || (idx > 120)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 120, &af_emlrtBCI, &st);
      }
      _mm_storeu_pd(&workspace[idx - 1],
                    _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5 * obj->beta),
                                          _mm_loadu_pd(&x[idx - 1])),
                               _mm_set1_pd(obj->rho)));
    }
    for (idx = scalarLB; idx < 8; idx++) {
      if (idx < 1) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 120, &ye_emlrtBCI, &st);
      }
      workspace[idx - 1] = 0.5 * obj->beta * x[idx - 1] + obj->rho;
    }
    st.site = &sj_emlrtRSI;
    val = xdot(&st, 7, x, workspace);
  } break;
  }
  return val;
}

/* End of code generation (computeFval.c) */
