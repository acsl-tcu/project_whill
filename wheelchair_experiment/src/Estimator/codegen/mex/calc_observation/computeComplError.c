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
#include "calc_observation_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo rf_emlrtRSI = {
    1,                   /* lineNo */
    "computeComplError", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeComplError.p" /* pathName */
};

static emlrtBCInfo jb_emlrtBCI = {
    1,                   /* iFirst */
    8,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "computeComplError", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeComplError.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    1,                   /* iFirst */
    5,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "computeComplError", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeComplError.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    1,                   /* iFirst */
    15,                  /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "computeComplError", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeComplError.p", /* pName */
    0                                /* checkKind */
};

/* Function Definitions */
real_T computeComplError(const emlrtStack *sp, const real_T xCurrent[5],
                         const real_T cIneq[2], const int32_T finiteLB[8],
                         int32_T mLB, const real_T lb[5],
                         const int32_T finiteUB[8], int32_T mUB,
                         const real_T ub[5], const real_T lambda[15],
                         int32_T iL0)
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
      muDoubleScalarMax(
          0.0, muDoubleScalarMin(
                   muDoubleScalarAbs(cIneq[0] * lbDelta),
                   muDoubleScalarMin(muDoubleScalarAbs(cIneq[0]), lbDelta))),
      muDoubleScalarMin(
          muDoubleScalarAbs(cIneq[1] * lambda[iL0]),
          muDoubleScalarMin(muDoubleScalarAbs(cIneq[1]), lambda[iL0])));
  ubOffset = (iL0 + mLB) + 2;
  st.site = &rf_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 8) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &jb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = finiteLB[idx];
    if ((i1 < 1) || (i1 > 5)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 5, &kb_emlrtBCI, (emlrtConstCTX)sp);
    }
    lbDelta = xCurrent[i1 - 1] - lb[i1 - 1];
    i1 = (iL0 + idx) + 2;
    if ((i1 < 1) || (i1 > 15)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 15, &lb_emlrtBCI, (emlrtConstCTX)sp);
    }
    lbLambda = lambda[i1 - 1];
    nlpComplError = muDoubleScalarMax(
        nlpComplError,
        muDoubleScalarMin(
            muDoubleScalarAbs(lbDelta * lbLambda),
            muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
  }
  st.site = &rf_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    i1 = finiteUB[idx];
    if ((i1 < 1) || (i1 > 5)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 5, &kb_emlrtBCI, (emlrtConstCTX)sp);
    }
    lbDelta = ub[i1 - 1] - xCurrent[i1 - 1];
    i1 = ubOffset + idx;
    if ((i1 < 1) || (i1 > 15)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 15, &lb_emlrtBCI, (emlrtConstCTX)sp);
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
