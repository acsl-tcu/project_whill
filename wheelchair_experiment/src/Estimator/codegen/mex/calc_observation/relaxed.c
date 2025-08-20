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
#include "PresolveWorkingSet.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "computeFval.h"
#include "eml_int_forloop_overflow_check.h"
#include "iterate.h"
#include "ixamax.h"
#include "maxConstraintViolation.h"
#include "phaseone.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include "xasum.h"
#include "xcopy.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wj_emlrtRSI = {
    1,                             /* lineNo */
    "computeConstrViolationIneq_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+MeritFunction/computeConstrViolationIneq_.p" /* pathName */
};

static emlrtRSInfo yj_emlrtRSI = {
    1,         /* lineNo */
    "relaxed", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "relaxed.p" /* pathName */
};

static emlrtRSInfo ak_emlrtRSI = {
    1,                         /* lineNo */
    "assignResidualsToXSlack", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/assignResidualsToXSlack.p" /* pathName */
};

static emlrtRSInfo bk_emlrtRSI = {
    1,                            /* lineNo */
    "findActiveSlackLowerBounds", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/findActiveSlackLowerBounds.p" /* pathName */
};

static emlrtRSInfo ek_emlrtRSI = {
    1,                              /* lineNo */
    "removeActiveSlackLowerBounds", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/removeActiveSlackLowerBounds.p" /* pathName */
};

static emlrtBCInfo cf_emlrtBCI = {
    1,                              /* iFirst */
    15,                             /* iLast */
    1,                              /* lineNo */
    1,                              /* colNo */
    "",                             /* aName */
    "removeActiveSlackLowerBounds", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/removeActiveSlackLowerBounds.p", /* pName */
    3                                          /* checkKind */
};

static emlrtBCInfo df_emlrtBCI = {
    1,         /* iFirst */
    15,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "relaxed.p", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ef_emlrtBCI = {
    1,         /* iFirst */
    8,         /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "relaxed.p", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = {
    1,         /* iFirst */
    5,         /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "relaxed", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "relaxed.p", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo gf_emlrtBCI = {
    1,                              /* iFirst */
    15,                             /* iLast */
    1,                              /* lineNo */
    1,                              /* colNo */
    "",                             /* aName */
    "removeActiveSlackLowerBounds", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/removeActiveSlackLowerBounds.p", /* pName */
    0                                          /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = {
    1,                         /* iFirst */
    8,                         /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "assignResidualsToXSlack", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/assignResidualsToXSlack.p", /* pName */
    3                                     /* checkKind */
};

/* Function Definitions */
void relaxed(const emlrtStack *sp, const real_T Hessian[25],
             const real_T grad[8], f_struct_T *TrialState,
             i_struct_T *MeritFunction, c_struct_T *memspace,
             g_struct_T *WorkingSet, j_struct_T *QRManager,
             k_struct_T *CholManager, l_struct_T *QPObjective,
             m_struct_T *qpoptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T beta;
  real_T rho;
  real_T s;
  real_T smax;
  int32_T i;
  int32_T idx;
  int32_T idx_max;
  int32_T k;
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
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  nVarOrig = WorkingSet->nVar;
  beta = 0.0;
  st.site = &yj_emlrtRSI;
  if (WorkingSet->nVar > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)WorkingSet->nVar;
  for (idx = 0; idx < i; idx++) {
    if (idx + 1 > 5) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 5, &ff_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    beta += Hessian[idx + 5 * idx];
  }
  beta /= (real_T)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    st.site = &yj_emlrtRSI;
    idx_max = ixamax(&st, QPObjective->nvar, grad);
    if ((idx_max < 1) || (idx_max > 8)) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, 8, &ef_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    rho = 100.0 * muDoubleScalarMax(1.0, muDoubleScalarAbs(grad[idx_max - 1]));
  } else {
    st.site = &yj_emlrtRSI;
    temp = WorkingSet->mConstr;
    b_st.site = &nf_emlrtRSI;
    idx_max = 1;
    smax = muDoubleScalarAbs(TrialState->lambdasqp[0]);
    c_st.site = &of_emlrtRSI;
    if (WorkingSet->mConstr > 2147483646) {
      d_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 2; k <= temp; k++) {
      s = muDoubleScalarAbs(TrialState->lambdasqp[k - 1]);
      if (s > smax) {
        idx_max = k;
        smax = s;
      }
    }
    if (idx_max > 15) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, 15, &df_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    rho = muDoubleScalarAbs(TrialState->lambdasqp[idx_max - 1]);
  }
  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = rho;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  st.site = &yj_emlrtRSI;
  b_setProblemType(&st, WorkingSet);
  st.site = &yj_emlrtRSI;
  b_st.site = &ak_emlrtRSI;
  c_st.site = &cf_emlrtRSI;
  d_st.site = &df_emlrtRSI;
  memspace->workspace_float[0] = WorkingSet->bineq[0];
  memspace->workspace_float[1] = WorkingSet->bineq[1];
  b_st.site = &ak_emlrtRSI;
  f_xgemv(&b_st, nVarOrig, WorkingSet->Aineq, TrialState->xstar,
          memspace->workspace_float);
  b_st.site = &ak_emlrtRSI;
  if ((nVarOrig + 1 < 1) || (nVarOrig + 1 > 8)) {
    emlrtDynamicBoundsCheckR2012b(nVarOrig + 1, 1, 8, &hf_emlrtBCI, &st);
  }
  TrialState->xstar[nVarOrig] = (real_T)(memspace->workspace_float[0] > 0.0) *
                                memspace->workspace_float[0];
  if ((nVarOrig + 2 < 1) || (nVarOrig + 2 > 8)) {
    emlrtDynamicBoundsCheckR2012b(nVarOrig + 2, 1, 8, &hf_emlrtBCI, &st);
  }
  TrialState->xstar[nVarOrig + 1] =
      (real_T)(memspace->workspace_float[1] > 0.0) *
      memspace->workspace_float[1];
  b_st.site = &ak_emlrtRSI;
  temp = qpoptions->MaxIterations;
  qpoptions->MaxIterations = (qpoptions->MaxIterations - nVarOrig) + 7;
  st.site = &yj_emlrtRSI;
  TrialState->state = 82;
  TrialState->iterations = 0;
  b_st.site = &xg_emlrtRSI;
  TrialState->maxConstr =
      c_maxConstraintViolation(&b_st, WorkingSet, TrialState->xstar);
  if (TrialState->maxConstr > 1.0E-6) {
    b_st.site = &xg_emlrtRSI;
    phaseone(&b_st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
             CholManager, QPObjective, qpoptions->SolverName, qpoptions);
    if (TrialState->state != 0) {
      b_st.site = &xg_emlrtRSI;
      TrialState->maxConstr =
          c_maxConstraintViolation(&b_st, WorkingSet, TrialState->xstar);
      if (TrialState->maxConstr > 1.0E-6) {
        b_st.site = &xg_emlrtRSI;
        b_xcopy(&b_st, 15, TrialState->lambda);
        b_st.site = &xg_emlrtRSI;
        TrialState->fstar =
            computeFval(&b_st, QPObjective, memspace->workspace_float, Hessian,
                        grad, TrialState->xstar);
        TrialState->state = -2;
      } else {
        if (TrialState->maxConstr > 0.0) {
          b_st.site = &xg_emlrtRSI;
          e_xcopy(&b_st, 7, TrialState->xstar, TrialState->searchDir);
          b_st.site = &xg_emlrtRSI;
          PresolveWorkingSet(&b_st, TrialState, memspace, WorkingSet,
                             QRManager);
          b_st.site = &xg_emlrtRSI;
          smax = c_maxConstraintViolation(&b_st, WorkingSet, TrialState->xstar);
          if (smax >= TrialState->maxConstr) {
            TrialState->maxConstr = smax;
            b_st.site = &xg_emlrtRSI;
            e_xcopy(&b_st, 7, TrialState->searchDir, TrialState->xstar);
          }
        }
        b_st.site = &xg_emlrtRSI;
        iterate(&b_st, Hessian, grad, TrialState, memspace, WorkingSet,
                QRManager, CholManager, QPObjective, qpoptions->SolverName,
                qpoptions->MaxIterations);
      }
    }
  } else {
    b_st.site = &xg_emlrtRSI;
    iterate(&b_st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
            CholManager, QPObjective, qpoptions->SolverName,
            qpoptions->MaxIterations);
  }
  qpoptions->MaxIterations = temp;
  st.site = &yj_emlrtRSI;
  b_st.site = &bk_emlrtRSI;
  b_st.site = &bk_emlrtRSI;
  b_st.site = &bk_emlrtRSI;
  i = WorkingSet->isActiveIdx[3] + WorkingSet->sizes[3];
  if ((i - 2 < 1) || (i - 2 > 15)) {
    emlrtDynamicBoundsCheckR2012b(i - 2, 1, 15, &kd_emlrtBCI, &b_st);
  }
  mFiniteLBOrig = WorkingSet->isActiveConstr[i - 3];
  memspace->workspace_int[0] = mFiniteLBOrig;
  b_st.site = &bk_emlrtRSI;
  if ((i - 1 < 1) || (i - 1 > 15)) {
    emlrtDynamicBoundsCheckR2012b(i - 1, 1, 15, &kd_emlrtBCI, &b_st);
  }
  tf = WorkingSet->isActiveConstr[i - 2];
  memspace->workspace_int[1] = tf;
  if (TrialState->state != -6) {
    real_T d;
    st.site = &yj_emlrtRSI;
    smax = xasum(&st, 7 - nVarOrig, TrialState->xstar, nVarOrig + 1);
    st.site = &yj_emlrtRSI;
    b_st.site = &dh_emlrtRSI;
    c_st.site = &eh_emlrtRSI;
    s = 0.0;
    if (7 - nVarOrig >= 1) {
      d_st.site = &fh_emlrtRSI;
      if (7 - nVarOrig > 2147483646) {
        e_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      i = (uint8_T)(7 - nVarOrig);
      for (k = 0; k < i; k++) {
        d = TrialState->xstar[nVarOrig + k];
        s += d * d;
      }
    }
    s = (TrialState->fstar - rho * smax) - beta / 2.0 * s;
    st.site = &yj_emlrtRSI;
    rho = MeritFunction->penaltyParam;
    b_st.site = &vj_emlrtRSI;
    beta = 0.0;
    c_st.site = &wj_emlrtRSI;
    d = TrialState->cIneq[0];
    if (d > 0.0) {
      beta = d;
    }
    d = TrialState->cIneq[1];
    if (d > 0.0) {
      beta += d;
    }
    smax = MeritFunction->linearizedConstrViol;
    b_st.site = &vj_emlrtRSI;
    MeritFunction->linearizedConstrViol =
        xasum(&b_st, 7 - nVarOrig, TrialState->xstar, nVarOrig + 1);
    smax = (beta + smax) - MeritFunction->linearizedConstrViol;
    if ((smax > 2.2204460492503131E-16) && (s > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        rho = 1.0;
      } else {
        rho = 1.5;
      }
      rho = rho * s / smax;
    }
    if (rho < MeritFunction->penaltyParam) {
      MeritFunction->phi = TrialState->sqpFval + rho * beta;
      if ((MeritFunction->initFval +
           rho * MeritFunction->initConstrViolationIneq) -
              MeritFunction->phi >
          (real_T)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) >
            TrialState->sqpIterations) {
          MeritFunction->threshold *= 10.0;
        }
        MeritFunction->penaltyParam = muDoubleScalarMax(rho, 1.0E-10);
      } else {
        MeritFunction->phi =
            TrialState->sqpFval + MeritFunction->penaltyParam * beta;
      }
    } else {
      MeritFunction->penaltyParam = muDoubleScalarMax(rho, 1.0E-10);
      MeritFunction->phi =
          TrialState->sqpFval + MeritFunction->penaltyParam * beta;
    }
    MeritFunction->phiPrimePlus =
        muDoubleScalarMin(s - MeritFunction->penaltyParam * beta, 0.0);
    st.site = &yj_emlrtRSI;
    temp = WorkingSet->isActiveIdx[2];
    idx_max = WorkingSet->nActiveConstr;
    st.site = &yj_emlrtRSI;
    if ((WorkingSet->isActiveIdx[2] <= WorkingSet->nActiveConstr) &&
        (WorkingSet->nActiveConstr > 2147483646)) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = temp; idx <= idx_max; idx++) {
      if ((idx < 1) || (idx > 15)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &df_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (WorkingSet->Wid[idx - 1] == 3) {
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 15)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 15, &df_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        TrialState->lambda[idx - 1] *= (real_T)memspace->workspace_int[i - 1];
      }
    }
  }
  st.site = &yj_emlrtRSI;
  temp = mFiniteLBOrig + tf;
  idx_max = WorkingSet->sizes[0];
  mFiniteLBOrig = WorkingSet->sizes[3] - 2;
  idx = WorkingSet->nActiveConstr;
  while ((idx > idx_max) && (temp > 0)) {
    if ((idx < 1) || (idx > 15)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &gf_emlrtBCI, &st);
    }
    if ((WorkingSet->Wid[idx - 1] == 4) &&
        (WorkingSet->Wlocalidx[idx - 1] > mFiniteLBOrig)) {
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 15)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 15,
                                      &gf_emlrtBCI, &st);
      }
      k = WorkingSet->nActiveConstr - 1;
      smax = TrialState->lambda[k];
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 15)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 15,
                                      &cf_emlrtBCI, &st);
      }
      TrialState->lambda[k] = 0.0;
      TrialState->lambda[idx - 1] = smax;
      b_st.site = &ek_emlrtRSI;
      removeConstr(&b_st, WorkingSet, idx);
      temp--;
    }
    idx--;
  }
  QPObjective->nvar = nVarOrig;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  st.site = &yj_emlrtRSI;
  WorkingSet->nVar = 5;
  WorkingSet->mConstr = WorkingSet->mConstrOrig;
  if (WorkingSet->nWConstr[4] > 0) {
    temp = WorkingSet->isActiveIdx[4];
    b_st.site = &ff_emlrtRSI;
    if (WorkingSet->sizesNormal[4] > 2147483646) {
      c_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)WorkingSet->sizesNormal[4];
    for (idx = 0; idx < i; idx++) {
      mFiniteLBOrig = temp + idx;
      if ((mFiniteLBOrig < 1) || (mFiniteLBOrig > 15)) {
        emlrtDynamicBoundsCheckR2012b(mFiniteLBOrig, 1, 15, &sb_emlrtBCI, &st);
      }
      idx_max = WorkingSet->isActiveIdxNormal[4] + idx;
      if ((idx_max < 1) || (idx_max > 15)) {
        emlrtDynamicBoundsCheckR2012b(idx_max, 1, 15, &rb_emlrtBCI, &st);
      }
      WorkingSet->isActiveConstr[idx_max - 1] =
          WorkingSet->isActiveConstr[mFiniteLBOrig - 1];
      WorkingSet->isActiveConstr[mFiniteLBOrig - 1] = false;
    }
  }
  for (i = 0; i < 5; i++) {
    WorkingSet->sizes[i] = WorkingSet->sizesNormal[i];
  }
  for (i = 0; i < 6; i++) {
    WorkingSet->isActiveIdx[i] = WorkingSet->isActiveIdxNormal[i];
  }
  WorkingSet->probType = 3;
  st.site = &yj_emlrtRSI;
  sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
               WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
               WorkingSet->Wlocalidx, memspace->workspace_float);
}

/* End of code generation (relaxed.c) */
