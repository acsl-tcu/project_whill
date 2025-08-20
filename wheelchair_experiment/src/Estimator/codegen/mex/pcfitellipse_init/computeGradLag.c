/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeGradLag.c
 *
 * Code generation for function 'computeGradLag'
 *
 */

/* Include files */
#include "computeGradLag.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wc_emlrtRSI = {
    1,                /* lineNo */
    "computeGradLag", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeGradLag.p" /* pathName */
};

static emlrtBCInfo te_emlrtBCI = {
    1,                /* iFirst */
    7,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeGradLag.p", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = {
    1,                /* iFirst */
    7,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeGradLag.p", /* pName */
    3                             /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = {
    1,                /* iFirst */
    13,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeGradLag.p", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = {
    1,                /* iFirst */
    91,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "computeGradLag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeGradLag.p", /* pName */
    3                             /* checkKind */
};

/* Function Definitions */
void b_computeGradLag(const emlrtStack *sp, real_T workspace[91], int32_T nVar,
                      const real_T grad[7], const real_T AineqTrans[7],
                      const int32_T finiteFixed[7], int32_T mFixed,
                      const int32_T finiteLB[7], int32_T mLB,
                      const int32_T finiteUB[7], int32_T mUB,
                      const real_T lambda[13])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T iL0;
  int32_T ia;
  int32_T idx;
  int32_T scalarLB;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nVar > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  scalarLB = (uint8_T)nVar;
  memcpy(&workspace[0], &grad[0], (uint32_T)scalarLB * sizeof(real_T));
  st.site = &wc_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  scalarLB = (uint8_T)mFixed;
  for (idx = 0; idx < scalarLB; idx++) {
    vectorUB = finiteFixed[idx];
    if ((vectorUB < 1) || (vectorUB > 91)) {
      emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 91, &af_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    workspace[vectorUB - 1] += lambda[idx];
  }
  st.site = &wc_emlrtRSI;
  scalarLB = nVar / 2 * 2 + 1;
  vectorUB = scalarLB - 2;
  for (ia = 1; ia <= vectorUB; ia += 2) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&AineqTrans[ia - 1]);
    r = _mm_mul_pd(r, _mm_set1_pd(lambda[mFixed]));
    r1 = _mm_loadu_pd(&workspace[ia - 1]);
    r = _mm_add_pd(r1, r);
    _mm_storeu_pd(&workspace[ia - 1], r);
  }
  for (ia = scalarLB; ia <= nVar; ia++) {
    workspace[ia - 1] += AineqTrans[ia - 1] * lambda[mFixed];
  }
  st.site = &wc_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  scalarLB = (uint8_T)mLB;
  for (idx = 0; idx < scalarLB; idx++) {
    if (idx + 1 > 7) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &te_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    vectorUB = (mFixed + idx) + 2;
    if ((vectorUB < 1) || (vectorUB > 13)) {
      emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 13, &ve_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ia = finiteLB[idx];
    if ((ia < 1) || (ia > 91)) {
      emlrtDynamicBoundsCheckR2012b(ia, 1, 91, &af_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[ia - 1] -= lambda[vectorUB - 1];
  }
  iL0 = (mFixed + (uint8_T)mLB) + 2;
  st.site = &wc_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  scalarLB = (uint8_T)mUB;
  for (idx = 0; idx < scalarLB; idx++) {
    vectorUB = iL0 + idx;
    if ((vectorUB < 1) || (vectorUB > 13)) {
      emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 13, &ve_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ia = finiteUB[idx];
    if ((ia < 1) || (ia > 91)) {
      emlrtDynamicBoundsCheckR2012b(ia, 1, 91, &af_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[ia - 1] += lambda[vectorUB - 1];
  }
}

void computeGradLag(const emlrtStack *sp, real_T workspace[7], int32_T nVar,
                    const real_T grad[7], const real_T AineqTrans[7],
                    const int32_T finiteFixed[7], int32_T mFixed,
                    const int32_T finiteLB[7], int32_T mLB,
                    const int32_T finiteUB[7], int32_T mUB,
                    const real_T lambda[13])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T iL0;
  int32_T ia;
  int32_T idx;
  int32_T scalarLB;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nVar > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  scalarLB = (uint8_T)nVar;
  memcpy(&workspace[0], &grad[0], (uint32_T)scalarLB * sizeof(real_T));
  st.site = &wc_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  scalarLB = (uint8_T)mFixed;
  for (idx = 0; idx < scalarLB; idx++) {
    vectorUB = finiteFixed[idx];
    if ((vectorUB < 1) || (vectorUB > 7)) {
      emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 7, &ue_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    workspace[vectorUB - 1] += lambda[idx];
  }
  st.site = &wc_emlrtRSI;
  scalarLB = ((nVar / 2) << 1) + 1;
  vectorUB = scalarLB - 2;
  for (ia = 1; ia <= vectorUB; ia += 2) {
    __m128d r;
    r = _mm_loadu_pd(&workspace[ia - 1]);
    _mm_storeu_pd(&workspace[ia - 1],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&AineqTrans[ia - 1]),
                                           _mm_set1_pd(lambda[mFixed]))));
  }
  for (ia = scalarLB; ia <= nVar; ia++) {
    workspace[ia - 1] += AineqTrans[ia - 1] * lambda[mFixed];
  }
  st.site = &wc_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  scalarLB = (uint8_T)mLB;
  for (idx = 0; idx < scalarLB; idx++) {
    if (idx + 1 > 7) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &te_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    vectorUB = (mFixed + idx) + 2;
    if ((vectorUB < 1) || (vectorUB > 13)) {
      emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 13, &ve_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ia = finiteLB[idx];
    if ((ia < 1) || (ia > 7)) {
      emlrtDynamicBoundsCheckR2012b(ia, 1, 7, &ue_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[ia - 1] -= lambda[vectorUB - 1];
  }
  iL0 = (mFixed + (uint8_T)mLB) + 2;
  st.site = &wc_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  scalarLB = (uint8_T)mUB;
  for (idx = 0; idx < scalarLB; idx++) {
    vectorUB = iL0 + idx;
    if ((vectorUB < 1) || (vectorUB > 13)) {
      emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 13, &ve_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ia = finiteUB[idx];
    if ((ia < 1) || (ia > 7)) {
      emlrtDynamicBoundsCheckR2012b(ia, 1, 7, &ue_emlrtBCI, (emlrtConstCTX)sp);
    }
    workspace[ia - 1] += lambda[vectorUB - 1];
  }
}

/* End of code generation (computeGradLag.c) */
