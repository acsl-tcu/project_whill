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
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo oj_emlrtRSI = {
    1,                            /* lineNo */
    "addBoundToActiveSetMatrix_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addBoundToActiveSetMatrix_.p" /* pathName */
};

static emlrtBCInfo ue_emlrtBCI = {
    1,                            /* iFirst */
    120,                          /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addBoundToActiveSetMatrix_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = {
    1,                            /* iFirst */
    8,                            /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addBoundToActiveSetMatrix_.p", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = {
    1,                            /* iFirst */
    15,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "addBoundToActiveSetMatrix_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addBoundToActiveSetMatrix_.p", /* pName */
    3                                           /* checkKind */
};

/* Function Definitions */
void addBoundToActiveSetMatrix_(const emlrtStack *sp, g_struct_T *obj,
                                int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a_tmp;
  int32_T b;
  int32_T colOffset;
  int32_T i;
  int32_T i1;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oj_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj->nWConstr[3]++;
  i = (obj->isActiveIdx[3] + idx_local) - 1;
  if ((i < 1) || (i > 15)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 15, &pe_emlrtBCI, &st);
  }
  obj->isActiveConstr[i - 1] = true;
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &pe_emlrtBCI, &st);
  }
  i = obj->nActiveConstr - 1;
  obj->Wid[i] = 4;
  obj->Wlocalidx[i] = idx_local;
  colOffset = i << 3;
  if ((idx_local < 1) || (idx_local > 8)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, 8, &ve_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  i1 = obj->indexLB[idx_local - 1];
  if ((i1 < 1) || (i1 > 8)) {
    emlrtDynamicBoundsCheckR2012b(obj->indexLB[idx_local - 1], 1, 8,
                                  &ve_emlrtBCI, (emlrtConstCTX)sp);
  }
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &we_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->bwset[i] = obj->lb[i1 - 1];
  st.site = &oj_emlrtRSI;
  for (idx = 0; idx <= i1 - 2; idx++) {
    i = (idx + colOffset) + 1;
    if ((i < 1) || (i > 120)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &ue_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  i = i1 + colOffset;
  if ((i < 1) || (i > 120)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 120, &ue_emlrtBCI, (emlrtConstCTX)sp);
  }
  obj->ATwset[i - 1] = -1.0;
  a_tmp = i1 + 1;
  b = obj->nVar;
  st.site = &oj_emlrtRSI;
  if ((i1 + 1 <= obj->nVar) && (obj->nVar > 2147483646)) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = a_tmp; idx <= b; idx++) {
    i = idx + colOffset;
    if ((i < 1) || (i > 120)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &ue_emlrtBCI, (emlrtConstCTX)sp);
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
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &ue_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = -1.0;
    break;
  }
}

void b_addBoundToActiveSetMatrix_(const emlrtStack *sp, g_struct_T *obj,
                                  int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a_tmp;
  int32_T b;
  int32_T colOffset;
  int32_T i;
  int32_T i1;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oj_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj->nWConstr[4]++;
  i = (obj->isActiveIdx[4] + idx_local) - 1;
  if ((i < 1) || (i > 15)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 15, &pe_emlrtBCI, &st);
  }
  obj->isActiveConstr[i - 1] = true;
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &pe_emlrtBCI, &st);
  }
  i = obj->nActiveConstr - 1;
  obj->Wid[i] = 5;
  obj->Wlocalidx[i] = idx_local;
  colOffset = i << 3;
  if ((idx_local < 1) || (idx_local > 8)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, 8, &ve_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  i1 = obj->indexUB[idx_local - 1];
  if ((i1 < 1) || (i1 > 8)) {
    emlrtDynamicBoundsCheckR2012b(obj->indexUB[idx_local - 1], 1, 8,
                                  &ve_emlrtBCI, (emlrtConstCTX)sp);
  }
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &we_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->bwset[i] = obj->ub[i1 - 1];
  st.site = &oj_emlrtRSI;
  for (idx = 0; idx <= i1 - 2; idx++) {
    i = (idx + colOffset) + 1;
    if ((i < 1) || (i > 120)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &ue_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = 0.0;
  }
  i = i1 + colOffset;
  if ((i < 1) || (i > 120)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 120, &ue_emlrtBCI, (emlrtConstCTX)sp);
  }
  obj->ATwset[i - 1] = 1.0;
  a_tmp = i1 + 1;
  b = obj->nVar;
  st.site = &oj_emlrtRSI;
  if ((i1 + 1 <= obj->nVar) && (obj->nVar > 2147483646)) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = a_tmp; idx <= b; idx++) {
    i = idx + colOffset;
    if ((i < 1) || (i > 120)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &ue_emlrtBCI, (emlrtConstCTX)sp);
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
      emlrtDynamicBoundsCheckR2012b(i, 1, 120, &ue_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = -1.0;
    break;
  }
}

/* End of code generation (addBoundToActiveSetMatrix_.c) */
