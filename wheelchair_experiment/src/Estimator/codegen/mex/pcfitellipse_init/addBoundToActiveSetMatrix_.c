/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * addBoundToActiveSetMatrix_.c
 *
 * Code generation for function 'addBoundToActiveSetMatrix_'
 *
 */

/* Include files */
#include "addBoundToActiveSetMatrix_.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hh_emlrtRSI = {
    1,                            /* lineNo */
    "addBoundToActiveSetMatrix_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p" /* pathName */
};

static emlrtBCInfo rd_emlrtBCI = {
    1,                            /* iFirst */
    91,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    1,                            /* iFirst */
    7,                            /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = {
    1,                            /* iFirst */
    13,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p", /* pName */
    3                                           /* checkKind */
};

/* Function Definitions */
void addBoundToActiveSetMatrix_(const emlrtStack *sp, i_struct_T *obj,
                                int32_T TYPE, int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T b;
  int32_T colOffset;
  int32_T i;
  int32_T idx;
  int32_T idx_bnd_local;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj->nWConstr[TYPE - 1]++;
  i = (obj->isActiveIdx[TYPE - 1] + idx_local) - 1;
  if ((i < 1) || (i > 13)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 13, &od_emlrtBCI, &st);
  }
  obj->isActiveConstr[i - 1] = true;
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 13)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 13, &od_emlrtBCI, &st);
  }
  i = obj->nActiveConstr - 1;
  obj->Wid[i] = TYPE;
  obj->Wlocalidx[i] = idx_local;
  colOffset = 7 * i;
  if (TYPE == 5) {
    if ((idx_local < 1) || (idx_local > 7)) {
      emlrtDynamicBoundsCheckR2012b(idx_local, 1, 7, &sd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    idx_bnd_local = obj->indexUB[idx_local - 1];
    if ((idx_bnd_local < 1) || (idx_bnd_local > 7)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx_local - 1], 1, 7,
                                    &sd_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 13, &td_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->bwset[i] = obj->ub[idx_bnd_local - 1];
  } else {
    if ((idx_local < 1) || (idx_local > 7)) {
      emlrtDynamicBoundsCheckR2012b(idx_local, 1, 7, &sd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    idx_bnd_local = obj->indexLB[idx_local - 1];
    if ((idx_bnd_local < 1) || (idx_bnd_local > 7)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx_local - 1], 1, 7,
                                    &sd_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 13)) {
      emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 13, &td_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->bwset[i] = obj->lb[idx_bnd_local - 1];
  }
  st.site = &hh_emlrtRSI;
  for (idx = 0; idx <= idx_bnd_local - 2; idx++) {
    i = (idx + colOffset) + 1;
    if ((i < 1) || (i > 91)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 91, &rd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  i = idx_bnd_local + colOffset;
  if ((i < 1) || (i > 91)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 91, &rd_emlrtBCI, (emlrtConstCTX)sp);
  }
  obj->ATwset[i - 1] = 2.0 * (real_T)(TYPE == 5) - 1.0;
  a = idx_bnd_local + 1;
  b = obj->nVar;
  st.site = &hh_emlrtRSI;
  if ((idx_bnd_local + 1 <= obj->nVar) && (obj->nVar > 2147483646)) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = a; idx <= b; idx++) {
    i = idx + colOffset;
    if ((i < 1) || (i > 91)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 91, &rd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  switch (obj->probType) {
  case 3:
  case 2:
    break;
  default:
    i = obj->nVar + colOffset;
    if ((i < 1) || (i > 91)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 91, &rd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = -1.0;
    break;
  }
}

/* End of code generation (addBoundToActiveSetMatrix_.c) */
