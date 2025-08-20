/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeComplError.c
 *
 * Code generation for function 'computeComplError'
 *
 */

/* Include files */
#include "computeComplError.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ed_emlrtRSI = {
    1,                   /* lineNo */
    "computeComplError", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeComplError.p" /* pathName */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                   /* iFirst */
    7,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "computeComplError", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeComplError.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                   /* iFirst */
    5,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "computeComplError", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeComplError.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    1,                   /* iFirst */
    13,                  /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "computeComplError", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeComplError.p", /* pName */
    0                                /* checkKind */
};

/* Function Definitions */
real_T computeComplError(const emlrtStack *sp, const real_T xCurrent[5],
                         real_T cIneq, const int32_T finiteLB[7], int32_T mLB,
                         const real_T lb[5], const int32_T finiteUB[7],
                         int32_T mUB, const real_T ub[5],
                         const real_T lambda[13], int32_T iL0)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T lbDelta;
  real_T lbLambda;
  real_T nlpComplError;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T ubOffset;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  lbDelta = lambda[iL0 - 1];
  nlpComplError = muDoubleScalarMax(
      0.0,
      muDoubleScalarMin(muDoubleScalarAbs(cIneq * lbDelta),
                        muDoubleScalarMin(muDoubleScalarAbs(cIneq), lbDelta)));
  ubOffset = (iL0 + mLB) + 1;
  st.site = &ed_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 7) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &j_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = finiteLB[idx];
    if ((i1 < 1) || (i1 > 5)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 5, &k_emlrtBCI, (emlrtConstCTX)sp);
    }
    lbDelta = xCurrent[i1 - 1] - lb[i1 - 1];
    i1 = (iL0 + idx) + 1;
    if ((i1 < 1) || (i1 > 13)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 13, &l_emlrtBCI, (emlrtConstCTX)sp);
    }
    lbLambda = lambda[i1 - 1];
    nlpComplError = muDoubleScalarMax(
        nlpComplError,
        muDoubleScalarMin(
            muDoubleScalarAbs(lbDelta * lbLambda),
            muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
  }
  st.site = &ed_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    i1 = finiteUB[idx];
    if ((i1 < 1) || (i1 > 5)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 5, &k_emlrtBCI, (emlrtConstCTX)sp);
    }
    lbDelta = ub[i1 - 1] - xCurrent[i1 - 1];
    i1 = ubOffset + idx;
    if ((i1 < 1) || (i1 > 13)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 13, &l_emlrtBCI, (emlrtConstCTX)sp);
    }
    lbLambda = lambda[i1 - 1];
    nlpComplError = muDoubleScalarMax(
        nlpComplError,
        muDoubleScalarMin(
            muDoubleScalarAbs(lbDelta * lbLambda),
            muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
  }
  return nlpComplError;
}

/* End of code generation (computeComplError.c) */
