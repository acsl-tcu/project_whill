/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * modifyOverheadPhaseOne_.c
 *
 * Code generation for function 'modifyOverheadPhaseOne_'
 *
 */

/* Include files */
#include "modifyOverheadPhaseOne_.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = {
    1,                         /* lineNo */
    "modifyOverheadPhaseOne_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p" /* pathName */
};

static emlrtBCInfo y_emlrtBCI = {
    1,                         /* iFirst */
    120,                       /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "modifyOverheadPhaseOne_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p", /* pName */
    3                                        /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    1,                         /* iFirst */
    8,                         /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "modifyOverheadPhaseOne_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p", /* pName */
    3                                        /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    1,                         /* iFirst */
    15,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "modifyOverheadPhaseOne_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p", /* pName */
    3                                        /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    1,                         /* iFirst */
    15,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "modifyOverheadPhaseOne_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p", /* pName */
    0                                        /* checkKind */
};

/* Function Definitions */
void modifyOverheadPhaseOne_(const emlrtStack *sp, k_struct_T *obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T idx;
  int32_T idxStartIneq;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj->sizes[0] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)obj->sizes[0];
  for (idx = 0; idx < i; idx++) {
    obj->ATwset[(obj->nVar + (idx << 3)) - 1] = 0.0;
  }
  st.site = &bd_emlrtRSI;
  st.site = &bd_emlrtRSI;
  i = obj->nVar - 1;
  obj->Aineq[i] = -1.0;
  obj->Aineq[obj->nVar + 7] = -1.0;
  if ((obj->sizes[3] < 1) || (obj->sizes[3] > 8)) {
    emlrtDynamicBoundsCheckR2012b(obj->sizes[3], 1, 8, &ab_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->indexLB[obj->sizes[3] - 1] = obj->nVar;
  obj->lb[i] = 1.0E-5;
  idxStartIneq = obj->isActiveIdx[2];
  b = obj->nActiveConstr;
  st.site = &bd_emlrtRSI;
  if ((obj->isActiveIdx[2] <= obj->nActiveConstr) &&
      (obj->nActiveConstr > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = idxStartIneq; idx <= b; idx++) {
    i = obj->nVar + ((idx - 1) << 3);
    if ((i < 1) || (i > 120)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &y_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = -1.0;
  }
  idxStartIneq = obj->isActiveIdx[4];
  if (obj->nWConstr[4] > 0) {
    i = obj->sizesNormal[4];
    for (idx = i; idx >= 1; idx--) {
      b = idxStartIneq + idx;
      if ((b - 1 < 1) || (b - 1 > 15)) {
        emlrtDynamicBoundsCheckR2012b(b - 1, 1, 15, &cb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((b < 1) || (b > 15)) {
        emlrtDynamicBoundsCheckR2012b(b, 1, 15, &bb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->isActiveConstr[b - 1] = obj->isActiveConstr[b - 2];
    }
  } else {
    i = obj->isActiveIdx[4] + obj->sizesNormal[4];
    if ((i < 1) || (i > 15)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 15, &bb_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->isActiveConstr[i - 1] = false;
  }
  if ((obj->isActiveIdx[4] < 1) || (obj->isActiveIdx[4] > 15)) {
    emlrtDynamicBoundsCheckR2012b(obj->isActiveIdx[4], 1, 15, &bb_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->isActiveConstr[obj->isActiveIdx[4] - 1] = false;
}

/* End of code generation (modifyOverheadPhaseOne_.c) */
