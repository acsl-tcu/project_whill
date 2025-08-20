/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_exit.c
 *
 * Code generation for function 'test_exit'
 *
 */

/* Include files */
#include "test_exit.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "calc_observation_mexutil.h"
#include "computeComplError.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computePrimalFeasError.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQRE.h"
#include "isDeltaXTooSmall.h"
#include "ixamax.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSetForNewQP.h"
#include "xcopy.h"
#include "xtrsv.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo jf_emlrtRSI = {
    1,           /* lineNo */
    "test_exit", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "test_exit.p" /* pathName */
};

static emlrtRSInfo tf_emlrtRSI = {
    1,                  /* lineNo */
    "computeLambdaLSQ", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeLambdaLSQ.p" /* pathName */
};

static emlrtBCInfo mf_emlrtBCI = {
    1,                  /* iFirst */
    225,                /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "computeLambdaLSQ", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeLambdaLSQ.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo nf_emlrtBCI = {
    1,                  /* iFirst */
    15,                 /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "computeLambdaLSQ", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeLambdaLSQ.p", /* pName */
    3                               /* checkKind */
};

/* Function Definitions */
void b_test_exit(const emlrtStack *sp, b_struct_T *Flags, c_struct_T *memspace,
                 i_struct_T *MeritFunction, g_struct_T *WorkingSet,
                 f_struct_T *TrialState, j_struct_T *QRManager,
                 const real_T lb[5], const real_T ub[5])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T c;
  real_T optimRelativeFactor;
  int32_T iQR_diag;
  int32_T iac;
  int32_T idx_max;
  int32_T mFixed;
  int32_T mLB;
  int32_T mLambda;
  int32_T mUB;
  int32_T nVar;
  int32_T rankR;
  boolean_T isFeasible;
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
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mLambda =
      ((WorkingSet->sizes[0] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
      2;
  st.site = &jf_emlrtRSI;
  xcopy(&st, mLambda, TrialState->lambdasqp, TrialState->lambdaStopTest);
  st.site = &jf_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aineq, WorkingSet->indexFixed,
                 WorkingSet->sizes[0], WorkingSet->indexLB,
                 WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdaStopTest);
  st.site = &jf_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &jf_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
      WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub);
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor =
        muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  }
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  st.site = &jf_emlrtRSI;
  Flags->gradOK =
      computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag,
                           &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
  } else {
    real_T nlpComplErrorTmp;
    st.site = &jf_emlrtRSI;
    MeritFunction->nlpComplError = computeComplError(
        &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
        WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub,
        TrialState->lambdaStopTest, WorkingSet->sizes[0] + 1);
    if (TrialState->sqpIterations > 1) {
      st.site = &jf_emlrtRSI;
      b_computeGradLag(
          &st, memspace->workspace_float, WorkingSet->nVar, TrialState->grad,
          WorkingSet->Aineq, WorkingSet->indexFixed, WorkingSet->sizes[0],
          WorkingSet->indexLB, WorkingSet->sizes[3], WorkingSet->indexUB,
          WorkingSet->sizes[4], TrialState->lambdaStopTestPrev);
      st.site = &jf_emlrtRSI;
      b_computeDualFeasError(&st, WorkingSet->nVar, memspace->workspace_float,
                             &c);
      st.site = &jf_emlrtRSI;
      nlpComplErrorTmp = computeComplError(
          &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
          WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4],
          ub, TrialState->lambdaStopTestPrev, WorkingSet->sizes[0] + 1);
      if ((c < MeritFunction->nlpDualFeasError) &&
          (nlpComplErrorTmp < MeritFunction->nlpComplError)) {
        MeritFunction->nlpDualFeasError = c;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        st.site = &jf_emlrtRSI;
        xcopy(&st, mLambda, TrialState->lambdaStopTestPrev,
              TrialState->lambdaStopTest);
      } else {
        st.site = &jf_emlrtRSI;
        xcopy(&st, mLambda, TrialState->lambdaStopTest,
              TrialState->lambdaStopTestPrev);
      }
    } else {
      st.site = &jf_emlrtRSI;
      xcopy(&st, mLambda, TrialState->lambdaStopTest,
            TrialState->lambdaStopTestPrev);
    }
    if (isFeasible &&
        (MeritFunction->nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) &&
        (MeritFunction->nlpComplError <= 1.0E-6 * optimRelativeFactor)) {
      Flags->done = true;
    } else {
      Flags->done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags->done = true;
      } else {
        boolean_T guard1;
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          boolean_T dxTooSmall;
          st.site = &jf_emlrtRSI;
          dxTooSmall = isDeltaXTooSmall(&st, TrialState->xstarsqp,
                                        TrialState->delta_x, WorkingSet->nVar);
          if (dxTooSmall) {
            if (!isFeasible) {
              if (Flags->stepType == 2) {
                Flags->done = true;
              } else {
                Flags->stepType = 2;
                Flags->failedLineSearch = false;
                Flags->stepAccepted = false;
                guard1 = true;
              }
            } else {
              int32_T nActiveConstr;
              nActiveConstr = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr == 0) {
                Flags->done = true;
              } else {
                real_T d;
                boolean_T exitg1;
                st.site = &jf_emlrtRSI;
                b_updateWorkingSetForNewQP(
                    &st, TrialState->xstarsqp, WorkingSet, TrialState->cIneq,
                    WorkingSet->sizes[3], lb, WorkingSet->sizes[4], ub,
                    WorkingSet->sizes[0]);
                st.site = &jf_emlrtRSI;
                b_st.site = &tf_emlrtRSI;
                b_xcopy(&b_st, nActiveConstr, TrialState->lambda);
                b_st.site = &tf_emlrtRSI;
                factorQRE(&b_st, QRManager, WorkingSet->ATwset, nVar,
                          nActiveConstr);
                b_st.site = &tf_emlrtRSI;
                c_st.site = &mg_emlrtRSI;
                computeQ_(&c_st, QRManager, QRManager->mrows);
                b_st.site = &tf_emlrtRSI;
                c_st.site = &xe_emlrtRSI;
                d_st.site = &ig_emlrtRSI;
                if (nVar > 2147483646) {
                  e_st.site = &u_emlrtRSI;
                  check_forloop_overflow_error(&e_st);
                }
                rankR = (uint8_T)nVar;
                memset(&memspace->workspace_float[0], 0,
                       (uint32_T)rankR * sizeof(real_T));
                iQR_diag = 15 * (nVar - 1) + 1;
                d_st.site = &ye_emlrtRSI;
                if (iQR_diag > 2147483632) {
                  e_st.site = &u_emlrtRSI;
                  check_forloop_overflow_error(&e_st);
                }
                for (iac = 1; iac <= iQR_diag; iac += 15) {
                  c = 0.0;
                  idx_max = (iac + nVar) - 1;
                  d_st.site = &af_emlrtRSI;
                  if ((iac <= idx_max) && (idx_max > 2147483646)) {
                    e_st.site = &u_emlrtRSI;
                    check_forloop_overflow_error(&e_st);
                  }
                  for (rankR = iac; rankR <= idx_max; rankR++) {
                    c +=
                        QRManager->Q[rankR - 1] * TrialState->grad[rankR - iac];
                  }
                  rankR = div_nde_s32_floor(iac - 1);
                  memspace->workspace_float[rankR] -= c;
                }
                c = muDoubleScalarAbs(QRManager->QR[0]) *
                    muDoubleScalarMin(
                        1.4901161193847656E-8,
                        (real_T)muIntScalarMax_sint32(nVar, nActiveConstr) *
                            2.2204460492503131E-16);
                idx_max = muIntScalarMin_sint32(nVar, nActiveConstr);
                rankR = 0;
                iQR_diag = 1;
                exitg1 = false;
                while ((!exitg1) && (rankR < idx_max)) {
                  if (iQR_diag > 225) {
                    emlrtDynamicBoundsCheckR2012b(iQR_diag, 1, 225,
                                                  &mf_emlrtBCI, &st);
                  }
                  if (muDoubleScalarAbs(QRManager->QR[iQR_diag - 1]) > c) {
                    rankR++;
                    iQR_diag += 16;
                  } else {
                    exitg1 = true;
                  }
                }
                b_st.site = &tf_emlrtRSI;
                xtrsv(rankR, QRManager->QR, memspace->workspace_float);
                idx_max = muIntScalarMin_sint32(nActiveConstr, idx_max);
                b_st.site = &tf_emlrtRSI;
                for (iQR_diag = 0; iQR_diag < idx_max; iQR_diag++) {
                  rankR = QRManager->jpvt[iQR_diag];
                  if ((rankR < 1) || (rankR > 15)) {
                    emlrtDynamicBoundsCheckR2012b(rankR, 1, 15, &nf_emlrtBCI,
                                                  &st);
                  }
                  TrialState->lambda[QRManager->jpvt[iQR_diag] - 1] =
                      memspace->workspace_float[iQR_diag];
                }
                st.site = &jf_emlrtRSI;
                sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
                             WorkingSet->sizes, WorkingSet->isActiveIdx,
                             WorkingSet->Wid, WorkingSet->Wlocalidx,
                             memspace->workspace_float);
                st.site = &jf_emlrtRSI;
                b_computeGradLag(&st, memspace->workspace_float, nVar,
                                 TrialState->grad, WorkingSet->Aineq,
                                 WorkingSet->indexFixed, mFixed,
                                 WorkingSet->indexLB, mLB, WorkingSet->indexUB,
                                 mUB, TrialState->lambda);
                st.site = &jf_emlrtRSI;
                b_computeDualFeasError(&st, nVar, memspace->workspace_float,
                                       &c);
                st.site = &jf_emlrtRSI;
                nlpComplErrorTmp = computeComplError(
                    &st, TrialState->xstarsqp, TrialState->cIneq,
                    WorkingSet->indexLB, mLB, lb, WorkingSet->indexUB, mUB, ub,
                    TrialState->lambda, mFixed + 1);
                d = muDoubleScalarMax(c, nlpComplErrorTmp);
                if (d <= muDoubleScalarMax(MeritFunction->nlpDualFeasError,
                                           MeritFunction->nlpComplError)) {
                  MeritFunction->nlpDualFeasError = c;
                  MeritFunction->nlpComplError = nlpComplErrorTmp;
                  st.site = &jf_emlrtRSI;
                  xcopy(&st, mLambda, TrialState->lambda,
                        TrialState->lambdaStopTest);
                }
                Flags->done = true;
                guard1 = true;
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          if (TrialState->sqpIterations >= 400) {
            Flags->done = true;
          } else if (TrialState->FunctionEvaluations >= 500) {
            Flags->done = true;
          }
        }
      }
    }
  }
}

boolean_T test_exit(const emlrtStack *sp, i_struct_T *MeritFunction,
                    const g_struct_T *WorkingSet, f_struct_T *TrialState,
                    const real_T lb[5], const real_T ub[5],
                    boolean_T *Flags_fevalOK, boolean_T *Flags_done,
                    boolean_T *Flags_stepAccepted,
                    boolean_T *Flags_failedLineSearch, int32_T *Flags_stepType)
{
  emlrtStack st;
  real_T optimRelativeFactor;
  int32_T idx_max;
  int32_T mLambda;
  boolean_T Flags_gradOK;
  boolean_T isFeasible;
  st.prev = sp;
  st.tls = sp->tls;
  *Flags_fevalOK = true;
  *Flags_done = false;
  *Flags_stepAccepted = false;
  *Flags_failedLineSearch = false;
  *Flags_stepType = 1;
  mLambda =
      ((WorkingSet->sizes[0] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
      2;
  st.site = &jf_emlrtRSI;
  xcopy(&st, mLambda, TrialState->lambdasqp, TrialState->lambdaStopTest);
  st.site = &jf_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aineq, WorkingSet->indexFixed,
                 WorkingSet->sizes[0], WorkingSet->indexLB,
                 WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdaStopTest);
  st.site = &jf_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &jf_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
      WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub);
  MeritFunction->feasRelativeFactor =
      muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  st.site = &jf_emlrtRSI;
  Flags_gradOK =
      computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag,
                           &MeritFunction->nlpDualFeasError);
  if (!Flags_gradOK) {
    *Flags_done = true;
  } else {
    st.site = &jf_emlrtRSI;
    computeComplError(&st, TrialState->xstarsqp, TrialState->cIneq,
                      WorkingSet->indexLB, WorkingSet->sizes[3], lb,
                      WorkingSet->indexUB, WorkingSet->sizes[4], ub,
                      TrialState->lambdaStopTest, WorkingSet->sizes[0] + 1);
    MeritFunction->nlpComplError = 0.0;
    st.site = &jf_emlrtRSI;
    xcopy(&st, mLambda, TrialState->lambdaStopTest,
          TrialState->lambdaStopTestPrev);
    if (isFeasible &&
        (MeritFunction->nlpDualFeasError <= 1.0E-6 * optimRelativeFactor)) {
      *Flags_done = true;
    } else if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
      *Flags_done = true;
    } else if (TrialState->FunctionEvaluations >= 500) {
      *Flags_done = true;
    }
  }
  return Flags_gradOK;
}

/* End of code generation (test_exit.c) */
