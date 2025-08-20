/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * relaxed.c
 *
 * Code generation for function 'relaxed'
 *
 */

/* Include files */
#include "relaxed.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "ixamax.h"
#include "moveConstraint_.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include "xasum.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo lh_emlrtRSI = {
    1,                    /* lineNo */
    "updatePenaltyParam", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "MeritFunction\\updatePenaltyParam.p" /* pathName */
};

static emlrtRSInfo mh_emlrtRSI = {
    1,                             /* lineNo */
    "computeConstrViolationIneq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "MeritFunction\\computeConstrViolationIneq_.p" /* pathName */
};

static emlrtRSInfo oh_emlrtRSI = {
    1,         /* lineNo */
    "relaxed", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p" /* pathName */
};

static emlrtRSInfo ph_emlrtRSI = {
    1,                         /* lineNo */
    "assignResidualsToXSlack", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\assignResidualsToXSlack.p" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    1,                            /* lineNo */
    "findActiveSlackLowerBounds", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\findActiveSlackLowerBounds.p" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    1,                              /* lineNo */
    "removeActiveSlackLowerBounds", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\removeActiveSlackLowerBounds.p" /* pathName */
};

static emlrtBCInfo vd_emlrtBCI = {
    1,                              /* iFirst */
    13,                             /* iLast */
    1,                              /* lineNo */
    1,                              /* colNo */
    "",                             /* aName */
    "removeActiveSlackLowerBounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\removeActiveSlackLowerBounds.p", /* pName */
    3                                                 /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = {
    1,         /* iFirst */
    13,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = {
    1,         /* iFirst */
    7,         /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = {
    1,         /* iFirst */
    5,         /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = {
    1,                              /* iFirst */
    13,                             /* iLast */
    1,                              /* lineNo */
    1,                              /* colNo */
    "",                             /* aName */
    "removeActiveSlackLowerBounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\removeActiveSlackLowerBounds.p", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = {
    1,                         /* iFirst */
    7,                         /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "assignResidualsToXSlack", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\assignResidualsToXSlack.p", /* pName */
    3                                            /* checkKind */
};

/* Function Definitions */
void relaxed(const emlrtStack *sp, const real_T Hessian[25],
             const real_T grad[7], h_struct_T *TrialState,
             b_struct_T *MeritFunction, d_struct_T *memspace,
             i_struct_T *WorkingSet, e_struct_T *QRManager,
             f_struct_T *CholManager, struct_T *QPObjective,
             k_struct_T *qpoptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  k_struct_T b_qpoptions;
  real_T beta;
  real_T s;
  real_T smax;
  int32_T i;
  int32_T idx;
  int32_T idx_max;
  int32_T mFiniteLBOrig;
  int32_T nVarOrig;
  int32_T temp;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  nVarOrig = WorkingSet->nVar;
  beta = 0.0;
  st.site = &oh_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)WorkingSet->nVar;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 5) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 5, &yd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    beta += Hessian[idx + 5 * idx];
  }
  beta /= (real_T)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    st.site = &oh_emlrtRSI;
    idx_max = ixamax(&st, QPObjective->nvar, grad);
    if ((idx_max < 1) || (idx_max > 7)) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, 7, &xd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    smax = 100.0 * muDoubleScalarMax(1.0, muDoubleScalarAbs(grad[idx_max - 1]));
  } else {
    st.site = &oh_emlrtRSI;
    temp = WorkingSet->mConstr;
    b_st.site = &ad_emlrtRSI;
    idx_max = 1;
    if (WorkingSet->mConstr > 1) {
      smax = muDoubleScalarAbs(TrialState->lambdasqp[0]);
      c_st.site = &bd_emlrtRSI;
      if (WorkingSet->mConstr > 2147483646) {
        d_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (mFiniteLBOrig = 2; mFiniteLBOrig <= temp; mFiniteLBOrig++) {
        s = muDoubleScalarAbs(TrialState->lambdasqp[mFiniteLBOrig - 1]);
        if (s > smax) {
          idx_max = mFiniteLBOrig;
          smax = s;
        }
      }
    }
    if (idx_max > 13) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, 13, &wd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    smax = muDoubleScalarAbs(TrialState->lambdasqp[idx_max - 1]);
  }
  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = smax;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  st.site = &oh_emlrtRSI;
  setProblemType(&st, WorkingSet, 2);
  st.site = &oh_emlrtRSI;
  b_st.site = &ph_emlrtRSI;
  c_st.site = &oc_emlrtRSI;
  memspace->workspace_double[0] = WorkingSet->bineq;
  b_st.site = &ph_emlrtRSI;
  c_xgemv(&b_st, nVarOrig, WorkingSet->Aineq, TrialState->xstar,
          memspace->workspace_double);
  b_st.site = &ph_emlrtRSI;
  if ((nVarOrig + 1 < 1) || (nVarOrig + 1 > 7)) {
    emlrtDynamicBoundsCheckR2012b(nVarOrig + 1, 1, 7, &be_emlrtBCI, &st);
  }
  TrialState->xstar[nVarOrig] = (real_T)(memspace->workspace_double[0] > 0.0) *
                                memspace->workspace_double[0];
  b_st.site = &ph_emlrtRSI;
  temp = qpoptions->MaxIterations;
  qpoptions->MaxIterations =
      (qpoptions->MaxIterations + WorkingSet->nVar) - nVarOrig;
  b_qpoptions = *qpoptions;
  st.site = &oh_emlrtRSI;
  driver(&st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
         CholManager, QPObjective, &b_qpoptions, qpoptions->MaxIterations);
  qpoptions->MaxIterations = temp;
  st.site = &oh_emlrtRSI;
  b_st.site = &qh_emlrtRSI;
  b_st.site = &qh_emlrtRSI;
  b_st.site = &qh_emlrtRSI;
  i = (WorkingSet->isActiveIdx[3] + WorkingSet->sizes[3]) - 1;
  if ((i < 1) || (i > 13)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 13, &fb_emlrtBCI, &b_st);
  }
  tf = WorkingSet->isActiveConstr[i - 1];
  memspace->workspace_int[0] = tf;
  if (TrialState->state != -6) {
    real_T qpfvalQuadExcess;
    st.site = &oh_emlrtRSI;
    s = xasum(&st, 6 - nVarOrig, TrialState->xstar, nVarOrig + 1);
    st.site = &oh_emlrtRSI;
    b_st.site = &pe_emlrtRSI;
    c_st.site = &qe_emlrtRSI;
    qpfvalQuadExcess = 0.0;
    if (6 - nVarOrig >= 1) {
      qpfvalQuadExcess =
          TrialState->xstar[nVarOrig] * TrialState->xstar[nVarOrig];
    }
    s = (TrialState->fstar - smax * s) - beta / 2.0 * qpfvalQuadExcess;
    st.site = &oh_emlrtRSI;
    qpfvalQuadExcess = MeritFunction->penaltyParam;
    b_st.site = &lh_emlrtRSI;
    smax = TrialState->cIneq;
    beta = 0.0;
    c_st.site = &mh_emlrtRSI;
    if (smax > 0.0) {
      beta = smax;
    }
    smax = MeritFunction->linearizedConstrViol;
    b_st.site = &lh_emlrtRSI;
    MeritFunction->linearizedConstrViol =
        xasum(&b_st, 6 - nVarOrig, TrialState->xstar, nVarOrig + 1);
    smax = (beta + smax) - MeritFunction->linearizedConstrViol;
    if ((smax > 2.2204460492503131E-16) && (s > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        qpfvalQuadExcess = 1.0;
      } else {
        qpfvalQuadExcess = 1.5;
      }
      qpfvalQuadExcess = qpfvalQuadExcess * s / smax;
    }
    if (qpfvalQuadExcess < MeritFunction->penaltyParam) {
      MeritFunction->phi = TrialState->sqpFval + qpfvalQuadExcess * beta;
      if ((MeritFunction->initFval +
           qpfvalQuadExcess * MeritFunction->initConstrViolationIneq) -
              MeritFunction->phi >
          (real_T)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) >
            TrialState->sqpIterations) {
          MeritFunction->threshold *= 10.0;
        }
        MeritFunction->penaltyParam =
            muDoubleScalarMax(qpfvalQuadExcess, 1.0E-10);
      } else {
        MeritFunction->phi =
            TrialState->sqpFval + MeritFunction->penaltyParam * beta;
      }
    } else {
      MeritFunction->penaltyParam =
          muDoubleScalarMax(qpfvalQuadExcess, 1.0E-10);
      MeritFunction->phi =
          TrialState->sqpFval + MeritFunction->penaltyParam * beta;
    }
    MeritFunction->phiPrimePlus =
        muDoubleScalarMin(s - MeritFunction->penaltyParam * beta, 0.0);
    st.site = &oh_emlrtRSI;
    temp = WorkingSet->isActiveIdx[2];
    idx_max = WorkingSet->nActiveConstr;
    st.site = &oh_emlrtRSI;
    if ((WorkingSet->isActiveIdx[2] <= WorkingSet->nActiveConstr) &&
        (WorkingSet->nActiveConstr > 2147483646)) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = temp; idx <= idx_max; idx++) {
      if ((idx < 1) || (idx > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &wd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (WorkingSet->Wid[idx - 1] == 3) {
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 13)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 13, &wd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        TrialState->lambda[idx - 1] *= (real_T)memspace->workspace_int[i - 1];
      }
    }
  }
  st.site = &oh_emlrtRSI;
  temp = tf;
  idx_max = WorkingSet->sizes[0];
  mFiniteLBOrig = WorkingSet->sizes[3] - 1;
  idx = WorkingSet->nActiveConstr - 1;
  while ((idx + 1 > idx_max) && (temp > 0)) {
    if ((idx + 1 < 1) || (idx + 1 > 13)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &ae_emlrtBCI, &st);
    }
    if ((WorkingSet->Wid[idx] == 4) &&
        (WorkingSet->Wlocalidx[idx] > mFiniteLBOrig)) {
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 13)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 13,
                                      &ae_emlrtBCI, &st);
      }
      smax = TrialState->lambda[WorkingSet->nActiveConstr - 1];
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 13)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 13,
                                      &vd_emlrtBCI, &st);
      }
      TrialState->lambda[WorkingSet->nActiveConstr - 1] = 0.0;
      TrialState->lambda[idx] = smax;
      b_st.site = &th_emlrtRSI;
      temp = WorkingSet->Wid[idx];
      if ((WorkingSet->Wid[idx] < 1) || (WorkingSet->Wid[idx] > 6)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->Wid[idx], 1, 6, &gb_emlrtBCI,
                                      &b_st);
      }
      i = (WorkingSet->isActiveIdx[WorkingSet->Wid[idx] - 1] +
           WorkingSet->Wlocalidx[idx]) -
          1;
      if ((i < 1) || (i > 13)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 13, &kb_emlrtBCI, &b_st);
      }
      WorkingSet->isActiveConstr[i - 1] = false;
      c_st.site = &ve_emlrtRSI;
      moveConstraint_(&c_st, WorkingSet, WorkingSet->nActiveConstr, idx + 1);
      WorkingSet->nActiveConstr--;
      if ((temp < 1) || (temp > 5)) {
        emlrtDynamicBoundsCheckR2012b(temp, 1, 5, &mb_emlrtBCI, &b_st);
      }
      WorkingSet->nWConstr[temp - 1]--;
      temp = 0;
    }
    idx--;
  }
  QPObjective->nvar = nVarOrig;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  st.site = &oh_emlrtRSI;
  setProblemType(&st, WorkingSet, 3);
  st.site = &oh_emlrtRSI;
  sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
               WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
               WorkingSet->Wlocalidx, memspace->workspace_double);
}

/* End of code generation (relaxed.c) */
