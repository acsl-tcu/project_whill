/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computePrimalFeasError.c
 *
 * Code generation for function 'computePrimalFeasError'
 *
 */

/* Include files */
#include "computePrimalFeasError.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kd_emlrtRSI = {
    1,                        /* lineNo */
    "computePrimalFeasError", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computePrimalFeasError.p" /* pathName */
};

static emlrtBCInfo n_emlrtBCI = {
    1,                        /* iFirst */
    5,                        /* iLast */
    1,                        /* lineNo */
    1,                        /* colNo */
    "",                       /* aName */
    "computePrimalFeasError", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computePrimalFeasError.p", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                        /* iFirst */
    8,                        /* iLast */
    1,                        /* lineNo */
    1,                        /* colNo */
    "",                       /* aName */
    "computePrimalFeasError", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computePrimalFeasError.p", /* pName */
    0                                     /* checkKind */
};

/* Function Definitions */
real_T computePrimalFeasError(const emlrtStack *sp, const real_T x[5],
                              const real_T cIneq[2], const int32_T finiteLB[8],
                              int32_T mLB, const real_T lb[5],
                              const int32_T finiteUB[8], int32_T mUB,
                              const real_T ub[5])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T feasError;
  int32_T i;
  int32_T i1;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  st.site = &kd_emlrtRSI;
  feasError = muDoubleScalarMax(muDoubleScalarMax(0.0, cIneq[0]), cIneq[1]);
  st.site = &kd_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 8) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &o_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = finiteLB[idx];
    if ((i1 < 1) || (i1 > 5)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 5, &n_emlrtBCI, (emlrtConstCTX)sp);
    }
    feasError = muDoubleScalarMax(feasError, lb[i1 - 1] - x[i1 - 1]);
  }
  st.site = &kd_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    i1 = finiteUB[idx];
    if ((i1 < 1) || (i1 > 5)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 5, &n_emlrtBCI, (emlrtConstCTX)sp);
    }
    feasError = muDoubleScalarMax(feasError, x[i1 - 1] - ub[i1 - 1]);
  }
  return feasError;
}

/* End of code generation (computePrimalFeasError.c) */
