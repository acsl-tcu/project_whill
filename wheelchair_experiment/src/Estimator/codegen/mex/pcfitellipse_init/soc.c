/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soc.c
 *
 * Code generation for function 'soc'
 *
 */

/* Include files */
#include "soc.h"
#include "addAineqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "xnrm2.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo uh_emlrtRSI = {
    1,     /* lineNo */
    "soc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\soc.p" /* pathName */
};

static emlrtRSInfo vh_emlrtRSI = {
    1,                  /* lineNo */
    "updateWorkingSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+soc\\updateWorkingSet.p" /* pathName */
};

static emlrtRSInfo wh_emlrtRSI = {
    1,                   /* lineNo */
    "restoreWorkingSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+soc\\restoreWorkingSet.p" /* pathName */
};

static emlrtBCInfo ce_emlrtBCI = {
    1,                  /* iFirst */
    1,                  /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "updateWorkingSet", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+soc\\updateWorkingSet.p", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = {
    1,                  /* iFirst */
    13,                 /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "updateWorkingSet", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+soc\\updateWorkingSet.p", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = {
    1,                   /* iFirst */
    13,                  /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "restoreWorkingSet", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+soc\\restoreWorkingSet.p", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = {
    1,                  /* iFirst */
    13,                 /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "updateWorkingSet", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+soc\\updateWorkingSet.p", /* pName */
    3                                 /* checkKind */
};

/* Function Definitions */
boolean_T soc(const emlrtStack *sp, const real_T Hessian[25],
              const real_T grad[7], h_struct_T *TrialState,
              d_struct_T *memspace, i_struct_T *WorkingSet,
              e_struct_T *QRManager, f_struct_T *CholManager,
              struct_T *QPObjective, const k_struct_T *qpoptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  k_struct_T b_qpoptions;
  real_T c;
  real_T oldDirIdx;
  int32_T b;
  int32_T i;
  int32_T idx;
  int32_T idxIneqOffset;
  int32_T idx_Aineq;
  int32_T idx_lower;
  int32_T idx_upper;
  int32_T nVar_tmp;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  boolean_T b_b;
  boolean_T success;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  nWIneq_old = WorkingSet->nWConstr[2];
  nWLower_old = WorkingSet->nWConstr[3];
  nWUpper_old = WorkingSet->nWConstr[4];
  nVar_tmp = WorkingSet->nVar;
  st.site = &uh_emlrtRSI;
  b_st.site = &oc_emlrtRSI;
  c_st.site = &pc_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    d_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  i = (uint8_T)WorkingSet->nVar;
  memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0],
         (uint32_T)i * sizeof(real_T));
  st.site = &uh_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  memcpy(&TrialState->socDirection[0], &TrialState->xstar[0],
         (uint32_T)i * sizeof(real_T));
  st.site = &uh_emlrtRSI;
  xcopy(&st, 13, TrialState->lambda, TrialState->lambdaStopTest);
  st.site = &uh_emlrtRSI;
  idxIneqOffset = WorkingSet->isActiveIdx[2];
  b_st.site = &vh_emlrtRSI;
  WorkingSet->bineq = -TrialState->cIneq;
  b_st.site = &vh_emlrtRSI;
  c_st.site = &kc_emlrtRSI;
  d_st.site = &lc_emlrtRSI;
  c = 0.0;
  d_st.site = &mc_emlrtRSI;
  if (nVar_tmp > 2147483646) {
    e_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (idx_Aineq = 1; idx_Aineq <= nVar_tmp; idx_Aineq++) {
    c +=
        WorkingSet->Aineq[idx_Aineq - 1] * TrialState->searchDir[idx_Aineq - 1];
  }
  c += WorkingSet->bineq;
  WorkingSet->bineq = c;
  idx_Aineq = 1;
  idx_lower = 2;
  idx_upper = WorkingSet->sizes[3] + 2;
  b = WorkingSet->nActiveConstr;
  b_st.site = &vh_emlrtRSI;
  if ((WorkingSet->isActiveIdx[2] <= WorkingSet->nActiveConstr) &&
      (WorkingSet->nActiveConstr > 2147483646)) {
    c_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (idx = idxIneqOffset; idx <= b; idx++) {
    int32_T idx_Partition;
    if ((idx < 1) || (idx > 13)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &de_emlrtBCI, &st);
    }
    switch (WorkingSet->Wid[idx - 1]) {
    case 3:
      idx_Partition = idx_Aineq;
      idx_Aineq++;
      i = WorkingSet->Wlocalidx[idx - 1];
      if ((i < 1) || (i > 1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 1, &ce_emlrtBCI, &st);
      }
      WorkingSet->bwset[idx - 1] = c;
      break;
    case 4:
      idx_Partition = idx_lower;
      idx_lower++;
      break;
    default:
      idx_Partition = idx_upper;
      idx_upper++;
      break;
    }
    if ((idx_Partition < 1) || (idx_Partition > 13)) {
      emlrtDynamicBoundsCheckR2012b(idx_Partition, 1, 13, &fe_emlrtBCI, &st);
    }
    TrialState->workingset_old[idx_Partition - 1] =
        WorkingSet->Wlocalidx[idx - 1];
  }
  st.site = &uh_emlrtRSI;
  c_xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar);
  b_qpoptions = *qpoptions;
  st.site = &uh_emlrtRSI;
  driver(&st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
         CholManager, QPObjective, &b_qpoptions, qpoptions->MaxIterations);
  st.site = &uh_emlrtRSI;
  i = (uint8_T)nVar_tmp;
  idx_Aineq = ((uint8_T)nVar_tmp >> 1) << 1;
  idx_lower = idx_Aineq - 2;
  for (idx = 0; idx <= idx_lower; idx += 2) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&TrialState->socDirection[idx]);
    r1 = _mm_loadu_pd(&TrialState->xstar[idx]);
    _mm_storeu_pd(&TrialState->socDirection[idx], _mm_sub_pd(r1, r));
    _mm_storeu_pd(&TrialState->xstar[idx], r);
  }
  for (idx = idx_Aineq; idx < i; idx++) {
    c = TrialState->socDirection[idx];
    oldDirIdx = c;
    c = TrialState->xstar[idx] - c;
    TrialState->socDirection[idx] = c;
    TrialState->xstar[idx] = oldDirIdx;
  }
  st.site = &uh_emlrtRSI;
  c = xnrm2(&st, nVar_tmp, TrialState->socDirection);
  st.site = &uh_emlrtRSI;
  oldDirIdx = xnrm2(&st, nVar_tmp, TrialState->xstar);
  success = (c <= 2.0 * oldDirIdx);
  st.site = &uh_emlrtRSI;
  idx_Aineq = WorkingSet->sizes[3];
  b_st.site = &wh_emlrtRSI;
  WorkingSet->bineq = -TrialState->cIneq;
  b_b = !success;
  if (b_b) {
    b_st.site = &wh_emlrtRSI;
    removeAllIneqConstr(&b_st, WorkingSet);
    b_st.site = &wh_emlrtRSI;
    if (nWIneq_old > 2147483646) {
      c_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (idx = 0; idx < nWIneq_old; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &ee_emlrtBCI, &st);
      }
      b_st.site = &wh_emlrtRSI;
      addAineqConstr(&b_st, WorkingSet, TrialState->workingset_old[idx]);
    }
    b_st.site = &wh_emlrtRSI;
    if (nWLower_old > 2147483646) {
      c_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (idx = 0; idx < nWLower_old; idx++) {
      b_st.site = &wh_emlrtRSI;
      if ((idx + 2 < 1) || (idx + 2 > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx + 2, 1, 13, &ee_emlrtBCI, &b_st);
      }
      c_st.site = &gh_emlrtRSI;
      addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4,
                                 TrialState->workingset_old[idx + 1]);
    }
    b_st.site = &wh_emlrtRSI;
    if (nWUpper_old > 2147483646) {
      c_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (idx = 0; idx < nWUpper_old; idx++) {
      b_st.site = &wh_emlrtRSI;
      i = (idx + idx_Aineq) + 2;
      if ((i < 1) || (i > 13)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 13, &ee_emlrtBCI, &b_st);
      }
      c_st.site = &ih_emlrtRSI;
      addBoundToActiveSetMatrix_(&c_st, WorkingSet, 5,
                                 TrialState->workingset_old[i - 1]);
    }
  }
  if (b_b) {
    st.site = &uh_emlrtRSI;
    xcopy(&st, 13, TrialState->lambdaStopTest, TrialState->lambda);
  } else {
    st.site = &uh_emlrtRSI;
    sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
                 WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                 WorkingSet->Wlocalidx, memspace->workspace_double);
  }
  return success;
}

/* End of code generation (soc.c) */
