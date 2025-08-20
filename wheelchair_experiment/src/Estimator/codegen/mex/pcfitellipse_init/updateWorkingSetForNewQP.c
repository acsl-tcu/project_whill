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
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo nc_emlrtRSI = {
    1,                          /* lineNo */
    "updateWorkingSetForNewQP", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p" /* pathName */
};

static emlrtBCInfo ie_emlrtBCI = {
    1,                          /* iFirst */
    7,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    3                                       /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = {
    1,                          /* iFirst */
    1,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = {
    1,                          /* iFirst */
    7,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = {
    1,                          /* iFirst */
    13,                         /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = {
    1,                          /* iFirst */
    5,                          /* iLast */
    1,                          /* lineNo */
    1,                          /* colNo */
    "",                         /* aName */
    "updateWorkingSetForNewQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "internal\\updateWorkingSetForNewQP.p", /* pName */
    0                                       /* checkKind */
};

/* Function Definitions */
void b_updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[5],
                                i_struct_T *WorkingSet, real_T cIneq,
                                int32_T mLB, const real_T lb[5], int32_T mUB,
                                const real_T ub[5], int32_T mFixed)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  st.site = &nc_emlrtRSI;
  st.site = &nc_emlrtRSI;
  WorkingSet->bineq = -cIneq;
  st.site = &nc_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 7) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &qe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 5)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 5,
                                    &se_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 7,
                                    &ie_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->lb[WorkingSet->indexLB[idx] - 1] =
        -lb[WorkingSet->indexLB[idx] - 1] + xk[WorkingSet->indexLB[idx] - 1];
  }
  st.site = &nc_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    if ((WorkingSet->indexUB[idx] < 1) || (WorkingSet->indexUB[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexUB[idx], 1, 7,
                                    &ie_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->ub[WorkingSet->indexUB[idx] - 1] =
        ub[WorkingSet->indexUB[idx] - 1] - xk[WorkingSet->indexUB[idx] - 1];
  }
  st.site = &nc_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mFixed;
  for (idx = 0; idx < i; idx++) {
    real_T d;
    if ((WorkingSet->indexFixed[idx] < 1) ||
        (WorkingSet->indexFixed[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexFixed[idx], 1, 7,
                                    &ie_emlrtBCI, (emlrtConstCTX)sp);
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
    st.site = &nc_emlrtRSI;
    if ((ineqStart <= WorkingSet->nActiveConstr) &&
        (WorkingSet->nActiveConstr > 2147483646)) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = ineqStart; idx <= b; idx++) {
      if (idx > 13) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &re_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      switch (WorkingSet->Wid[idx - 1]) {
      case 4:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 7)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 7,
                                        &qe_emlrtBCI, (emlrtConstCTX)sp);
        }
        i = WorkingSet->indexLB[i - 1];
        if ((i < 1) || (i > 7)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 7, &qe_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        WorkingSet->bwset[idx - 1] = WorkingSet->lb[i - 1];
        break;
      case 5:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 7)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 7,
                                        &qe_emlrtBCI, (emlrtConstCTX)sp);
        }
        i = WorkingSet->indexUB[i - 1];
        if ((i < 1) || (i > 7)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 7, &qe_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        WorkingSet->bwset[idx - 1] = WorkingSet->ub[i - 1];
        break;
      default:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 1)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 1,
                                        &pe_emlrtBCI, (emlrtConstCTX)sp);
        }
        WorkingSet->bwset[idx - 1] = WorkingSet->bineq;
        break;
      }
    }
  }
}

void updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[5],
                              i_struct_T *WorkingSet, real_T cIneq, int32_T mLB,
                              const real_T lb[5], int32_T mUB,
                              const real_T ub[5], int32_T mFixed)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  WorkingSet->bineq = -cIneq;
  st.site = &nc_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mLB;
  for (idx = 0; idx < i; idx++) {
    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 7,
                                    &ie_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->lb[WorkingSet->indexLB[idx] - 1] =
        -lb[WorkingSet->indexLB[idx] - 1] + xk[WorkingSet->indexLB[idx] - 1];
  }
  st.site = &nc_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    if ((WorkingSet->indexUB[idx] < 1) || (WorkingSet->indexUB[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexUB[idx], 1, 7,
                                    &ie_emlrtBCI, (emlrtConstCTX)sp);
    }
    WorkingSet->ub[WorkingSet->indexUB[idx] - 1] =
        ub[WorkingSet->indexUB[idx] - 1] - xk[WorkingSet->indexUB[idx] - 1];
  }
  st.site = &nc_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)mFixed;
  for (idx = 0; idx < i; idx++) {
    real_T d;
    if ((WorkingSet->indexFixed[idx] < 1) ||
        (WorkingSet->indexFixed[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexFixed[idx], 1, 7,
                                    &ie_emlrtBCI, (emlrtConstCTX)sp);
    }
    d = ub[WorkingSet->indexFixed[idx] - 1] -
        xk[WorkingSet->indexFixed[idx] - 1];
    WorkingSet->ub[WorkingSet->indexFixed[idx] - 1] = d;
    WorkingSet->bwset[idx] = d;
  }
}

/* End of code generation (updateWorkingSetForNewQP.c) */
