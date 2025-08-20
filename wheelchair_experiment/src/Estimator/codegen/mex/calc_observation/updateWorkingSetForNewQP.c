/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateWorkingSetForNewQP.c
 *
 * Code generation for function 'updateWorkingSetForNewQP'
 *
 */

/* Include files */
#include "updateWorkingSetForNewQP.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo bf_emlrtRSI = {
    1,                          /* lineNo */
    "updateWorkingSetForNewQP", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/updateWorkingSetForNewQP.p" /* pathName */
};

static emlrtBCInfo of_emlrtBCI = {
    1,                          /* iFirst */
    8,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/updateWorkingSetForNewQP.p", /* pName */
    3                                       /* checkKind */
};

static emlrtBCInfo vf_emlrtBCI = {
    1,                          /* iFirst */
    8,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo wf_emlrtBCI = {
    1,                          /* iFirst */
    15,                         /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo xf_emlrtBCI = {
    1,                          /* iFirst */
    5,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo yf_emlrtBCI = {
    1,                          /* iFirst */
    2,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

/* Function Definitions */
void b_updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[5],
                                g_struct_T *WorkingSet, const real_T cIneq[2],
                                int32_T mLB, const real_T lb[5], int32_T mUB,
                                const real_T ub[5], int32_T mFixed)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T nVar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  nVar = WorkingSet->nVar;
  st.site = &bf_emlrtRSI;
  st.site = &bf_emlrtRSI;
  st.site = &bf_emlrtRSI;
  _mm_storeu_pd(&WorkingSet->bineq[0],
                _mm_mul_pd(_mm_loadu_pd(&cIneq[0]), _mm_set1_pd(-1.0)));
  st.site = &bf_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 8) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &vf_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 5)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 5,
                                    &xf_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 8)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 8,
                                    &of_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->lb[WorkingSet->indexLB[idx] - 1] =
        -lb[WorkingSet->indexLB[idx] - 1] + xk[WorkingSet->indexLB[idx] - 1];
  }
  st.site = &bf_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    if ((WorkingSet->indexUB[idx] < 1) || (WorkingSet->indexUB[idx] > 8)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexUB[idx], 1, 8,
                                    &of_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->ub[WorkingSet->indexUB[idx] - 1] =
        ub[WorkingSet->indexUB[idx] - 1] - xk[WorkingSet->indexUB[idx] - 1];
  }
  st.site = &bf_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mFixed;
  for (idx = 0; idx < i; idx++) {
    real_T d;
    if ((WorkingSet->indexFixed[idx] < 1) ||
        (WorkingSet->indexFixed[idx] > 8)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexFixed[idx], 1, 8,
                                    &of_emlrtBCI, (emlrtConstCTX)sp);
    }
    d = ub[WorkingSet->indexFixed[idx] - 1] -
        xk[WorkingSet->indexFixed[idx] - 1];
    WorkingSet->ub[WorkingSet->indexFixed[idx] - 1] = d;
    WorkingSet->bwset[idx] = d;
  }
  if (WorkingSet->nActiveConstr > mFixed) {
    int32_T b;
    int32_T ineqStart;
    i = mFixed + 1;
    ineqStart = muIntScalarMax_sint32(i, 1);
    b = WorkingSet->nActiveConstr;
    st.site = &bf_emlrtRSI;
    if ((ineqStart <= WorkingSet->nActiveConstr) &&
        (WorkingSet->nActiveConstr > 2147483646)) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = ineqStart; idx <= b; idx++) {
      if (idx > 15) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &wf_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      switch (WorkingSet->Wid[idx - 1]) {
      case 4:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 8)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 8,
                                        &vf_emlrtBCI, (emlrtConstCTX)sp);
        }
        i = WorkingSet->indexLB[WorkingSet->Wlocalidx[idx - 1] - 1];
        if ((i < 1) || (i > 8)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 8, &vf_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        WorkingSet->bwset[idx - 1] = WorkingSet->lb[i - 1];
        break;
      case 5:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 8)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 8,
                                        &vf_emlrtBCI, (emlrtConstCTX)sp);
        }
        i = WorkingSet->indexUB[WorkingSet->Wlocalidx[idx - 1] - 1];
        if ((i < 1) || (i > 8)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 8, &vf_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        WorkingSet->bwset[idx - 1] = WorkingSet->ub[i - 1];
        break;
      default: {
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 2)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 2,
                                        &yf_emlrtBCI, (emlrtConstCTX)sp);
        }
        WorkingSet->bwset[idx - 1] = WorkingSet->bineq[i - 1];
        if (i > 1) {
          int32_T iy0;
          iy0 = (idx - 1) << 3;
          st.site = &bf_emlrtRSI;
          b_st.site = &cf_emlrtRSI;
          c_st.site = &df_emlrtRSI;
          if (nVar > 2147483646) {
            d_st.site = &u_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }
          i = (uint8_T)nVar;
          for (k = 0; k < i; k++) {
            WorkingSet->ATwset[iy0 + k] = WorkingSet->Aineq[k + 8];
          }
        }
      } break;
      }
    }
  }
}

void updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[5],
                              g_struct_T *WorkingSet, const real_T cIneq[2],
                              int32_T mLB, const real_T lb[5], int32_T mUB,
                              const real_T ub[5], int32_T mFixed)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  _mm_storeu_pd(&WorkingSet->bineq[0],
                _mm_mul_pd(_mm_loadu_pd(&cIneq[0]), _mm_set1_pd(-1.0)));
  st.site = &bf_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 8)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 8,
                                    &of_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->lb[WorkingSet->indexLB[idx] - 1] =
        -lb[WorkingSet->indexLB[idx] - 1] + xk[WorkingSet->indexLB[idx] - 1];
  }
  st.site = &bf_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    if ((WorkingSet->indexUB[idx] < 1) || (WorkingSet->indexUB[idx] > 8)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexUB[idx], 1, 8,
                                    &of_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->ub[WorkingSet->indexUB[idx] - 1] =
        ub[WorkingSet->indexUB[idx] - 1] - xk[WorkingSet->indexUB[idx] - 1];
  }
  st.site = &bf_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mFixed;
  for (idx = 0; idx < i; idx++) {
    real_T d;
    if ((WorkingSet->indexFixed[idx] < 1) ||
        (WorkingSet->indexFixed[idx] > 8)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexFixed[idx], 1, 8,
                                    &of_emlrtBCI, (emlrtConstCTX)sp);
    }
    d = ub[WorkingSet->indexFixed[idx] - 1] -
        xk[WorkingSet->indexFixed[idx] - 1];
    WorkingSet->ub[WorkingSet->indexFixed[idx] - 1] = d;
    WorkingSet->bwset[idx] = d;
  }
}

/* End of code generation (updateWorkingSetForNewQP.c) */
