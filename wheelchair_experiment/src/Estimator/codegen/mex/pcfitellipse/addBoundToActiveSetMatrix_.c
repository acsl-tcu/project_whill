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
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ph_emlrtRSI = {
    1,                            /* lineNo */
    "addBoundToActiveSetMatrix_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p" /* pathName */
};

static emlrtBCInfo be_emlrtBCI = {
    1,                            /* iFirst */
    120,                          /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = {
    1,                            /* iFirst */
    8,                            /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addBoundToActiveSetMatrix_.p", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = {
    1,                            /* iFirst */
    15,                           /* iLast */
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
void addBoundToActiveSetMatrix_(const emlrtStack *sp, k_struct_T *obj,
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
  st.site = &ph_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj->nWConstr[TYPE - 1]++;
  i = (obj->isActiveIdx[TYPE - 1] + idx_local) - 1;
  if ((i < 1) || (i > 15)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 15, &vd_emlrtBCI, &st);
  }
  obj->isActiveConstr[i - 1] = true;
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &vd_emlrtBCI, &st);
  }
  i = obj->nActiveConstr - 1;
  obj->Wid[i] = TYPE;
  obj->Wlocalidx[i] = idx_local;
  colOffset = i << 3;
  if (TYPE == 5) {
    if ((idx_local < 1) || (idx_local > 8)) {
      emlrtDynamicBoundsCheckR2012b(idx_local, 1, 8, &ce_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    idx_bnd_local = obj->indexUB[idx_local - 1];
    if ((idx_bnd_local < 1) || (idx_bnd_local > 8)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx_local - 1], 1, 8,
                                    &ce_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
      emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &de_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->bwset[i] = obj->ub[idx_bnd_local - 1];
  } else {
    if ((idx_local < 1) || (idx_local > 8)) {
      emlrtDynamicBoundsCheckR2012b(idx_local, 1, 8, &ce_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    idx_bnd_local = obj->indexLB[idx_local - 1];
    if ((idx_bnd_local < 1) || (idx_bnd_local > 8)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx_local - 1], 1, 8,
                                    &ce_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
      emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &de_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->bwset[i] = obj->lb[idx_bnd_local - 1];
  }
  st.site = &ph_emlrtRSI;
  for (idx = 0; idx <= idx_bnd_local - 2; idx++) {
    i = (idx + colOffset) + 1;
    if ((i < 1) || (i > 120)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &be_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  i = idx_bnd_local + colOffset;
  if ((i < 1) || (i > 120)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 120, &be_emlrtBCI, (emlrtConstCTX)sp);
  }
  obj->ATwset[i - 1] = 2.0 * (real_T)(TYPE == 5) - 1.0;
  a = idx_bnd_local + 1;
  b = obj->nVar;
  st.site = &ph_emlrtRSI;
  if ((idx_bnd_local + 1 <= obj->nVar) && (obj->nVar > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = a; idx <= b; idx++) {
    i = idx + colOffset;
    if ((i < 1) || (i > 120)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &be_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  switch (obj->probType) {
  case 3:
  case 2:
    break;
  default:
    i = obj->nVar + colOffset;
    if ((i < 1) || (i > 120)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &be_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = -1.0;
    break;
  }
}

/* End of code generation (addBoundToActiveSetMatrix_.c) */
