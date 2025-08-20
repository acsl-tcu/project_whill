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
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "xnrm2.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo fk_emlrtRSI = {
    1,     /* lineNo */
    "soc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "soc.p" /* pathName */
};

static emlrtRSInfo gk_emlrtRSI = {
    1,                  /* lineNo */
    "updateWorkingSet", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/updateWorkingSet.p" /* pathName */
};

static emlrtRSInfo hk_emlrtRSI = {
    1,                   /* lineNo */
    "restoreWorkingSet", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/restoreWorkingSet.p" /* pathName */
};

static emlrtBCInfo if_emlrtBCI = {
    1,                  /* iFirst */
    15,                 /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "updateWorkingSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/updateWorkingSet.p", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo jf_emlrtBCI = {
    1,                   /* iFirst */
    15,                  /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "restoreWorkingSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/restoreWorkingSet.p", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo kf_emlrtBCI = {
    1,                  /* iFirst */
    2,                  /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "updateWorkingSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/updateWorkingSet.p", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo lf_emlrtBCI = {
    1,                  /* iFirst */
    15,                 /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "updateWorkingSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/updateWorkingSet.p", /* pName */
    3                          /* checkKind */
};

/* Function Definitions */
boolean_T soc(const emlrtStack *sp, const real_T Hessian[25],
              const real_T grad[8], f_struct_T *TrialState,
              c_struct_T *memspace, g_struct_T *WorkingSet,
              j_struct_T *QRManager, k_struct_T *CholManager,
              l_struct_T *QPObjective, const m_struct_T *qpoptions)
{
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T c;
  real_T oldDirIdx;
  int32_T b;
  int32_T i;
  int32_T idx;
  int32_T idxIneqOffset;
  int32_T idx_Aineq;
  int32_T idx_lower;
  int32_T idx_upper;
  int32_T nVar;
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
  nVar = WorkingSet->nVar;
  st.site = &fk_emlrtRSI;
  b_st.site = &cf_emlrtRSI;
  c_st.site = &df_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    d_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  i = (uint8_T)WorkingSet->nVar;
  memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0],
         (uint32_T)i * sizeof(real_T));
  st.site = &fk_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  memcpy(&TrialState->socDirection[0], &TrialState->xstar[0],
         (uint32_T)i * sizeof(real_T));
  st.site = &fk_emlrtRSI;
  xcopy(&st, 15, TrialState->lambda, TrialState->lambdaStopTest);
  st.site = &fk_emlrtRSI;
  idxIneqOffset = WorkingSet->isActiveIdx[2];
  b_st.site = &gk_emlrtRSI;
  r = _mm_loadu_pd(&TrialState->cIneq[0]);
  r1 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(&WorkingSet->bineq[0], _mm_mul_pd(r, r1));
  b_st.site = &gk_emlrtRSI;
  c_st.site = &xe_emlrtRSI;
  d_st.site = &ye_emlrtRSI;
  for (idx_lower = 0; idx_lower <= 8; idx_lower += 8) {
    c = 0.0;
    b = idx_lower + WorkingSet->nVar;
    d_st.site = &af_emlrtRSI;
    if ((idx_lower + 1 <= b) && (b > 2147483646)) {
      e_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (idx_Aineq = idx_lower + 1; idx_Aineq <= b; idx_Aineq++) {
      c += WorkingSet->Aineq[idx_Aineq - 1] *
           TrialState->searchDir[(idx_Aineq - idx_lower) - 1];
    }
    i = idx_lower >> 3;
    WorkingSet->bineq[i] += c;
  }
  idx_Aineq = 1;
  idx_lower = 3;
  idx_upper = WorkingSet->sizes[3] + 3;
  b = WorkingSet->nActiveConstr;
  b_st.site = &gk_emlrtRSI;
  if ((WorkingSet->isActiveIdx[2] <= WorkingSet->nActiveConstr) &&
      (WorkingSet->nActiveConstr > 2147483646)) {
    c_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (idx = idxIneqOffset; idx <= b; idx++) {
    int32_T idx_Partition;
    if ((idx < 1) || (idx > 15)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &if_emlrtBCI, &st);
    }
    switch (WorkingSet->Wid[idx - 1]) {
    case 3:
      idx_Partition = idx_Aineq;
      idx_Aineq++;
      i = WorkingSet->Wlocalidx[idx - 1];
      if ((i < 1) || (i > 2)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 2,
                                      &kf_emlrtBCI, &st);
      }
      WorkingSet->bwset[idx - 1] = WorkingSet->bineq[i - 1];
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
    if ((idx_Partition < 1) || (idx_Partition > 15)) {
      emlrtDynamicBoundsCheckR2012b(idx_Partition, 1, 15, &lf_emlrtBCI, &st);
    }
    TrialState->workingset_old[idx_Partition - 1] =
        WorkingSet->Wlocalidx[idx - 1];
  }
  st.site = &fk_emlrtRSI;
  d_xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar);
  st.site = &fk_emlrtRSI;
  driver(&st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
         CholManager, QPObjective, qpoptions, qpoptions);
  st.site = &fk_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)nVar;
  idx_Aineq = ((uint8_T)nVar >> 1) << 1;
  idx_lower = idx_Aineq - 2;
  for (idx = 0; idx <= idx_lower; idx += 2) {
    __m128d r2;
    r = _mm_loadu_pd(&TrialState->socDirection[idx]);
    r2 = _mm_loadu_pd(&TrialState->xstar[idx]);
    _mm_storeu_pd(&TrialState->socDirection[idx], _mm_sub_pd(r2, r));
    _mm_storeu_pd(&TrialState->xstar[idx], r);
  }
  for (idx = idx_Aineq; idx < i; idx++) {
    c = TrialState->socDirection[idx];
    oldDirIdx = c;
    c = TrialState->xstar[idx] - c;
    TrialState->socDirection[idx] = c;
    TrialState->xstar[idx] = oldDirIdx;
  }
  st.site = &fk_emlrtRSI;
  c = c_xnrm2(&st, nVar, TrialState->socDirection);
  st.site = &fk_emlrtRSI;
  oldDirIdx = c_xnrm2(&st, nVar, TrialState->xstar);
  success = (c <= 2.0 * oldDirIdx);
  st.site = &fk_emlrtRSI;
  idx_Aineq = WorkingSet->sizes[3];
  b_st.site = &hk_emlrtRSI;
  r = _mm_loadu_pd(&TrialState->cIneq[0]);
  _mm_storeu_pd(&WorkingSet->bineq[0], _mm_mul_pd(r, r1));
  b_b = !success;
  if (b_b) {
    b_st.site = &hk_emlrtRSI;
    removeAllIneqConstr(&b_st, WorkingSet);
    b_st.site = &hk_emlrtRSI;
    if (nWIneq_old > 2147483646) {
      c_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (idx = 0; idx < nWIneq_old; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 15)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 15, &jf_emlrtBCI, &st);
      }
      b_st.site = &hk_emlrtRSI;
      addAineqConstr(&b_st, WorkingSet, TrialState->workingset_old[idx]);
    }
    b_st.site = &hk_emlrtRSI;
    if (nWLower_old > 2147483646) {
      c_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (idx = 0; idx < nWLower_old; idx++) {
      b_st.site = &hk_emlrtRSI;
      if ((idx + 3 < 1) || (idx + 3 > 15)) {
        emlrtDynamicBoundsCheckR2012b(idx + 3, 1, 15, &jf_emlrtBCI, &b_st);
      }
      c_st.site = &nj_emlrtRSI;
      addBoundToActiveSetMatrix_(&c_st, WorkingSet,
                                 TrialState->workingset_old[idx + 2]);
    }
    b_st.site = &hk_emlrtRSI;
    if (nWUpper_old > 2147483646) {
      c_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (idx = 0; idx < nWUpper_old; idx++) {
      b_st.site = &hk_emlrtRSI;
      i = (idx + idx_Aineq) + 3;
      if ((i < 1) || (i > 15)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 15, &jf_emlrtBCI, &b_st);
      }
      c_st.site = &pj_emlrtRSI;
      b_addBoundToActiveSetMatrix_(&c_st, WorkingSet,
                                   TrialState->workingset_old[i - 1]);
    }
  }
  if (b_b) {
    st.site = &fk_emlrtRSI;
    xcopy(&st, 15, TrialState->lambdaStopTest, TrialState->lambda);
  } else {
    st.site = &fk_emlrtRSI;
    sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
                 WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                 WorkingSet->Wlocalidx, memspace->workspace_float);
  }
  return success;
}

/* End of code generation (soc.c) */
