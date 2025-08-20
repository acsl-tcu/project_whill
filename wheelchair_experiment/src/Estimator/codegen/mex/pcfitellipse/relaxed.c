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
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include "xasum.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo af_emlrtRSI = {
    42,      /* lineNo */
    "xdotx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdotx.m" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    1,                    /* lineNo */
    "updatePenaltyParam", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "MeritFunction\\updatePenaltyParam.p" /* pathName */
};

static emlrtRSInfo uh_emlrtRSI = {
    1,                             /* lineNo */
    "computeConstrViolationIneq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "MeritFunction\\computeConstrViolationIneq_.p" /* pathName */
};

static emlrtRSInfo wh_emlrtRSI = {
    1,         /* lineNo */
    "relaxed", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p" /* pathName */
};

static emlrtRSInfo xh_emlrtRSI = {
    1,                         /* lineNo */
    "assignResidualsToXSlack", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\assignResidualsToXSlack.p" /* pathName */
};

static emlrtRSInfo yh_emlrtRSI = {
    1,                            /* lineNo */
    "findActiveSlackLowerBounds", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\findActiveSlackLowerBounds.p" /* pathName */
};

static emlrtRSInfo ci_emlrtRSI = {
    1,                              /* lineNo */
    "removeActiveSlackLowerBounds", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\removeActiveSlackLowerBounds.p" /* pathName */
};

static emlrtBCInfo ee_emlrtBCI = {
    1,                              /* iFirst */
    15,                             /* iLast */
    1,                              /* lineNo */
    1,                              /* colNo */
    "",                             /* aName */
    "removeActiveSlackLowerBounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\removeActiveSlackLowerBounds.p", /* pName */
    3                                                 /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = {
    1,         /* iFirst */
    15,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = {
    1,         /* iFirst */
    8,         /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\relaxed.p", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
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

static emlrtBCInfo ie_emlrtBCI = {
    1,                              /* iFirst */
    15,                             /* iLast */
    1,                              /* lineNo */
    1,                              /* colNo */
    "",                             /* aName */
    "removeActiveSlackLowerBounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\removeActiveSlackLowerBounds.p", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = {
    1,                         /* iFirst */
    8,                         /* iLast */
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
             const real_T grad[8], j_struct_T *TrialState,
             c_struct_T *MeritFunction, f_struct_T *memspace,
             k_struct_T *WorkingSet, g_struct_T *QRManager,
             h_struct_T *CholManager, b_struct_T *QPObjective,
             m_struct_T *qpoptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  m_struct_T b_qpoptions;
  real_T beta;
  real_T s;
  real_T smax;
  int32_T TYPE;
  int32_T i;
  int32_T idx;
  int32_T idx_max;
  int32_T mFiniteLBOrig;
  int32_T nVarOrig;
  int32_T temp;
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
  nVarOrig = WorkingSet->nVar;
  beta = 0.0;
  st.site = &wh_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)WorkingSet->nVar;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 5) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 5, &he_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    beta += Hessian[idx + 5 * idx];
  }
  beta /= (real_T)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    st.site = &wh_emlrtRSI;
    idx_max = ixamax(&st, QPObjective->nvar, grad);
    if ((idx_max < 1) || (idx_max > 8)) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, 8, &ge_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    smax = 100.0 * muDoubleScalarMax(1.0, muDoubleScalarAbs(grad[idx_max - 1]));
  } else {
    st.site = &wh_emlrtRSI;
    temp = WorkingSet->mConstr;
    b_st.site = &id_emlrtRSI;
    idx_max = 1;
    smax = muDoubleScalarAbs(TrialState->lambdasqp[0]);
    c_st.site = &jd_emlrtRSI;
    if (WorkingSet->mConstr > 2147483646) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (idx = 2; idx <= temp; idx++) {
      s = muDoubleScalarAbs(TrialState->lambdasqp[idx - 1]);
      if (s > smax) {
        idx_max = idx;
        smax = s;
      }
    }
    if (idx_max > 15) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, 15, &fe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    smax = muDoubleScalarAbs(TrialState->lambdasqp[idx_max - 1]);
  }
  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = smax;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  st.site = &wh_emlrtRSI;
  setProblemType(&st, WorkingSet, 2);
  st.site = &wh_emlrtRSI;
  b_st.site = &xh_emlrtRSI;
  c_st.site = &wc_emlrtRSI;
  d_st.site = &xc_emlrtRSI;
  memspace->workspace_double[0] = WorkingSet->bineq[0];
  memspace->workspace_double[1] = WorkingSet->bineq[1];
  b_st.site = &xh_emlrtRSI;
  b_xgemv(&b_st, nVarOrig, WorkingSet->Aineq, TrialState->xstar,
          memspace->workspace_double);
  b_st.site = &xh_emlrtRSI;
  if ((nVarOrig + 1 < 1) || (nVarOrig + 1 > 8)) {
    emlrtDynamicBoundsCheckR2012b(nVarOrig + 1, 1, 8, &je_emlrtBCI, &st);
  }
  TrialState->xstar[nVarOrig] = (real_T)(memspace->workspace_double[0] > 0.0) *
                                memspace->workspace_double[0];
  if ((nVarOrig + 2 < 1) || (nVarOrig + 2 > 8)) {
    emlrtDynamicBoundsCheckR2012b(nVarOrig + 2, 1, 8, &je_emlrtBCI, &st);
  }
  TrialState->xstar[nVarOrig + 1] =
      (real_T)(memspace->workspace_double[1] > 0.0) *
      memspace->workspace_double[1];
  b_st.site = &xh_emlrtRSI;
  temp = qpoptions->MaxIterations;
  qpoptions->MaxIterations =
      (qpoptions->MaxIterations + WorkingSet->nVar) - nVarOrig;
  b_qpoptions = *qpoptions;
  st.site = &wh_emlrtRSI;
  driver(&st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
         CholManager, QPObjective, &b_qpoptions, qpoptions->MaxIterations);
  qpoptions->MaxIterations = temp;
  st.site = &wh_emlrtRSI;
  b_st.site = &yh_emlrtRSI;
  b_st.site = &yh_emlrtRSI;
  b_st.site = &yh_emlrtRSI;
  i = WorkingSet->isActiveIdx[3] + WorkingSet->sizes[3];
  if ((i - 2 < 1) || (i - 2 > 15)) {
    emlrtDynamicBoundsCheckR2012b(i - 2, 1, 15, &mb_emlrtBCI, &b_st);
  }
  mFiniteLBOrig = WorkingSet->isActiveConstr[i - 3];
  memspace->workspace_int[0] = mFiniteLBOrig;
  b_st.site = &yh_emlrtRSI;
  if ((i - 1 < 1) || (i - 1 > 15)) {
    emlrtDynamicBoundsCheckR2012b(i - 1, 1, 15, &mb_emlrtBCI, &b_st);
  }
  i = WorkingSet->isActiveConstr[i - 2];
  memspace->workspace_int[1] = i;
  if (TrialState->state != -6) {
    real_T d;
    real_T qpfvalQuadExcess;
    st.site = &wh_emlrtRSI;
    s = xasum(&st, 7 - nVarOrig, TrialState->xstar, nVarOrig + 1);
    st.site = &wh_emlrtRSI;
    b_st.site = &xe_emlrtRSI;
    c_st.site = &ye_emlrtRSI;
    qpfvalQuadExcess = 0.0;
    if (7 - nVarOrig >= 1) {
      d_st.site = &af_emlrtRSI;
      if (7 - nVarOrig > 2147483646) {
        e_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      TYPE = (uint8_T)(7 - nVarOrig);
      for (idx = 0; idx < TYPE; idx++) {
        d = TrialState->xstar[nVarOrig + idx];
        qpfvalQuadExcess += d * d;
      }
    }
    s = (TrialState->fstar - smax * s) - beta / 2.0 * qpfvalQuadExcess;
    st.site = &wh_emlrtRSI;
    qpfvalQuadExcess = MeritFunction->penaltyParam;
    b_st.site = &th_emlrtRSI;
    beta = 0.0;
    c_st.site = &uh_emlrtRSI;
    d = TrialState->cIneq[0];
    if (d > 0.0) {
      beta = d;
    }
    d = TrialState->cIneq[1];
    if (d > 0.0) {
      beta += d;
    }
    smax = MeritFunction->linearizedConstrViol;
    b_st.site = &th_emlrtRSI;
    MeritFunction->linearizedConstrViol =
        xasum(&b_st, 7 - nVarOrig, TrialState->xstar, nVarOrig + 1);
    smax = (beta + smax) - MeritFunction->linearizedConstrViol;
    if ((smax > 2.2204460492503131E-16) && (s > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        d = 1.0;
      } else {
        d = 1.5;
      }
      qpfvalQuadExcess = d * s / smax;
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
    st.site = &wh_emlrtRSI;
    temp = WorkingSet->isActiveIdx[2];
    idx_max = WorkingSet->nActiveConstr;
    st.site = &wh_emlrtRSI;
    if ((WorkingSet->isActiveIdx[2] <= WorkingSet->nActiveConstr) &&
        (WorkingSet->nActiveConstr > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = temp; idx <= idx_max; idx++) {
      if ((idx < 1) || (idx > 15)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &fe_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (WorkingSet->Wid[idx - 1] == 3) {
        TYPE = WorkingSet->Wlocalidx[idx - 1];
        if ((TYPE < 1) || (TYPE > 15)) {
          emlrtDynamicBoundsCheckR2012b(TYPE, 1, 15, &fe_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        TrialState->lambda[idx - 1] *=
            (real_T)memspace->workspace_int[TYPE - 1];
      }
    }
  }
  st.site = &wh_emlrtRSI;
  temp = mFiniteLBOrig + i;
  idx_max = WorkingSet->sizes[0];
  mFiniteLBOrig = WorkingSet->sizes[3] - 2;
  idx = WorkingSet->nActiveConstr - 1;
  while ((idx + 1 > idx_max) && (temp > 0)) {
    if ((idx + 1 < 1) || (idx + 1 > 15)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 15, &ie_emlrtBCI, &st);
    }
    if ((WorkingSet->Wid[idx] == 4) &&
        (WorkingSet->Wlocalidx[idx] > mFiniteLBOrig)) {
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 15)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 15,
                                      &ie_emlrtBCI, &st);
      }
      smax = TrialState->lambda[WorkingSet->nActiveConstr - 1];
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 15)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 15,
                                      &ee_emlrtBCI, &st);
      }
      TrialState->lambda[WorkingSet->nActiveConstr - 1] = 0.0;
      TrialState->lambda[idx] = smax;
      b_st.site = &ci_emlrtRSI;
      TYPE = WorkingSet->Wid[idx];
      if ((WorkingSet->Wid[idx] < 1) || (WorkingSet->Wid[idx] > 6)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->Wid[idx], 1, 6, &nb_emlrtBCI,
                                      &b_st);
      }
      i = (WorkingSet->isActiveIdx[WorkingSet->Wid[idx] - 1] +
           WorkingSet->Wlocalidx[idx]) -
          1;
      if ((i < 1) || (i > 15)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 15, &rb_emlrtBCI, &b_st);
      }
      WorkingSet->isActiveConstr[i - 1] = false;
      if (idx + 1 < WorkingSet->nActiveConstr) {
        c_st.site = &ef_emlrtRSI;
        moveConstraint_(&c_st, WorkingSet, WorkingSet->nActiveConstr, idx + 1);
      }
      WorkingSet->nActiveConstr--;
      if ((TYPE < 1) || (TYPE > 5)) {
        emlrtDynamicBoundsCheckR2012b(TYPE, 1, 5, &tb_emlrtBCI, &b_st);
      }
      WorkingSet->nWConstr[TYPE - 1]--;
      temp--;
    }
    idx--;
  }
  QPObjective->nvar = nVarOrig;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  st.site = &wh_emlrtRSI;
  setProblemType(&st, WorkingSet, 3);
  st.site = &wh_emlrtRSI;
  sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
               WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
               WorkingSet->Wlocalidx, memspace->workspace_double);
}

/* End of code generation (relaxed.c) */
