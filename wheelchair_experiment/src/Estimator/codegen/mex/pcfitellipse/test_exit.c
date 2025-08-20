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
#include "computeComplError.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computePrimalFeasError.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "isDeltaXTooSmall.h"
#include "ixamax.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "pcfitellipse_mexutil.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSetForNewQP.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "xtrsv.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ed_emlrtRSI = {
    1,           /* lineNo */
    "test_exit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\test_"
    "exit.p" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    1,                  /* lineNo */
    "computeLambdaLSQ", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeLambdaLSQ.p" /* pathName */
};

static emlrtBCInfo oe_emlrtBCI = {
    1,                  /* iFirst */
    225,                /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "computeLambdaLSQ", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeLambdaLSQ.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = {
    1,                  /* iFirst */
    15,                 /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "computeLambdaLSQ", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeLambdaLSQ.p", /* pName */
    3                               /* checkKind */
};

/* Function Definitions */
void b_test_exit(const emlrtStack *sp, d_struct_T *Flags, f_struct_T *memspace,
                 c_struct_T *MeritFunction, k_struct_T *WorkingSet,
                 j_struct_T *TrialState, g_struct_T *QRManager,
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
  st.site = &ed_emlrtRSI;
  xcopy(&st, mLambda, TrialState->lambdasqp, TrialState->lambdaStopTest);
  st.site = &ed_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aineq, WorkingSet->indexFixed,
                 WorkingSet->sizes[0], WorkingSet->indexLB,
                 WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdaStopTest);
  st.site = &ed_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &ed_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
      WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub);
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor =
        muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  }
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  st.site = &ed_emlrtRSI;
  Flags->gradOK =
      computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag,
                           &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    real_T nlpComplErrorTmp;
    st.site = &ed_emlrtRSI;
    MeritFunction->nlpComplError = computeComplError(
        &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
        WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub,
        TrialState->lambdaStopTest, WorkingSet->sizes[0] + 1);
    MeritFunction->firstOrderOpt = muDoubleScalarMax(
        MeritFunction->nlpDualFeasError, MeritFunction->nlpComplError);
    if (TrialState->sqpIterations > 1) {
      st.site = &ed_emlrtRSI;
      b_computeGradLag(
          &st, memspace->workspace_double, WorkingSet->nVar, TrialState->grad,
          WorkingSet->Aineq, WorkingSet->indexFixed, WorkingSet->sizes[0],
          WorkingSet->indexLB, WorkingSet->sizes[3], WorkingSet->indexUB,
          WorkingSet->sizes[4], TrialState->lambdaStopTestPrev);
      st.site = &ed_emlrtRSI;
      b_computeDualFeasError(&st, WorkingSet->nVar, memspace->workspace_double,
                             &c);
      st.site = &ed_emlrtRSI;
      nlpComplErrorTmp = computeComplError(
          &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
          WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4],
          ub, TrialState->lambdaStopTestPrev, WorkingSet->sizes[0] + 1);
      if ((c < MeritFunction->nlpDualFeasError) &&
          (nlpComplErrorTmp < MeritFunction->nlpComplError)) {
        MeritFunction->nlpDualFeasError = c;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        MeritFunction->firstOrderOpt = muDoubleScalarMax(c, nlpComplErrorTmp);
        st.site = &ed_emlrtRSI;
        xcopy(&st, mLambda, TrialState->lambdaStopTestPrev,
              TrialState->lambdaStopTest);
      } else {
        st.site = &ed_emlrtRSI;
        xcopy(&st, mLambda, TrialState->lambdaStopTest,
              TrialState->lambdaStopTestPrev);
      }
    } else {
      st.site = &ed_emlrtRSI;
      xcopy(&st, mLambda, TrialState->lambdaStopTest,
            TrialState->lambdaStopTestPrev);
    }
    if (isFeasible &&
        (MeritFunction->nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) &&
        (MeritFunction->nlpComplError <= 1.0E-6 * optimRelativeFactor)) {
      Flags->done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags->done = true;
        TrialState->sqpExitFlag = -3;
      } else {
        boolean_T guard1;
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          boolean_T dxTooSmall;
          st.site = &ed_emlrtRSI;
          dxTooSmall = isDeltaXTooSmall(&st, TrialState->xstarsqp,
                                        TrialState->delta_x, WorkingSet->nVar);
          if (dxTooSmall) {
            if (!isFeasible) {
              if (Flags->stepType != 2) {
                Flags->stepType = 2;
                Flags->failedLineSearch = false;
                Flags->stepAccepted = false;
                guard1 = true;
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = -2;
              }
            } else {
              int32_T nActiveConstr;
              nActiveConstr = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr == 0) {
                Flags->done = true;
                TrialState->sqpExitFlag = 2;
              } else {
                real_T d;
                boolean_T exitg1;
                boolean_T guard2;
                st.site = &ed_emlrtRSI;
                b_updateWorkingSetForNewQP(
                    &st, TrialState->xstarsqp, WorkingSet, TrialState->cIneq,
                    WorkingSet->sizes[3], lb, WorkingSet->sizes[4], ub,
                    WorkingSet->sizes[0]);
                st.site = &ed_emlrtRSI;
                b_st.site = &he_emlrtRSI;
                g_xcopy(&b_st, nActiveConstr, TrialState->lambda);
                b_st.site = &he_emlrtRSI;
                rankR = nVar * nActiveConstr;
                guard2 = false;
                if (rankR > 0) {
                  c_st.site = &od_emlrtRSI;
                  if (nActiveConstr > 2147483646) {
                    d_st.site = &o_emlrtRSI;
                    check_forloop_overflow_error(&d_st);
                  }
                  for (iQR_diag = 0; iQR_diag < nActiveConstr; iQR_diag++) {
                    c_st.site = &od_emlrtRSI;
                    b_xcopy(&c_st, nVar, WorkingSet->ATwset,
                            (iQR_diag << 3) + 1, QRManager->QR,
                            15 * iQR_diag + 1);
                  }
                  guard2 = true;
                } else if (rankR == 0) {
                  QRManager->mrows = nVar;
                  QRManager->ncols = nActiveConstr;
                  QRManager->minRowCol = 0;
                } else {
                  guard2 = true;
                }
                if (guard2) {
                  QRManager->usedPivoting = true;
                  QRManager->mrows = nVar;
                  QRManager->ncols = nActiveConstr;
                  QRManager->minRowCol =
                      muIntScalarMin_sint32(nVar, nActiveConstr);
                  c_st.site = &od_emlrtRSI;
                  xgeqp3(&c_st, QRManager->QR, nVar, nActiveConstr,
                         QRManager->jpvt, QRManager->tau);
                }
                b_st.site = &he_emlrtRSI;
                c_st.site = &ie_emlrtRSI;
                computeQ_(&c_st, QRManager, QRManager->mrows);
                b_st.site = &he_emlrtRSI;
                c_st.site = &sc_emlrtRSI;
                d_st.site = &ce_emlrtRSI;
                if (nVar > 2147483646) {
                  e_st.site = &o_emlrtRSI;
                  check_forloop_overflow_error(&e_st);
                }
                rankR = (uint8_T)nVar;
                memset(&memspace->workspace_double[0], 0,
                       (uint32_T)rankR * sizeof(real_T));
                iQR_diag = 15 * (nVar - 1) + 1;
                d_st.site = &tc_emlrtRSI;
                if (iQR_diag > 2147483632) {
                  e_st.site = &o_emlrtRSI;
                  check_forloop_overflow_error(&e_st);
                }
                for (iac = 1; iac <= iQR_diag; iac += 15) {
                  c = 0.0;
                  idx_max = (iac + nVar) - 1;
                  d_st.site = &uc_emlrtRSI;
                  if ((iac <= idx_max) && (idx_max > 2147483646)) {
                    e_st.site = &o_emlrtRSI;
                    check_forloop_overflow_error(&e_st);
                  }
                  for (rankR = iac; rankR <= idx_max; rankR++) {
                    c +=
                        QRManager->Q[rankR - 1] * TrialState->grad[rankR - iac];
                  }
                  rankR = div_nde_s32_floor(iac - 1);
                  memspace->workspace_double[rankR] -= c;
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
                                                  &oe_emlrtBCI, &st);
                  }
                  if (muDoubleScalarAbs(QRManager->QR[iQR_diag - 1]) > c) {
                    rankR++;
                    iQR_diag += 16;
                  } else {
                    exitg1 = true;
                  }
                }
                b_st.site = &he_emlrtRSI;
                xtrsv(rankR, QRManager->QR, memspace->workspace_double);
                idx_max = muIntScalarMin_sint32(nActiveConstr, idx_max);
                b_st.site = &he_emlrtRSI;
                for (iQR_diag = 0; iQR_diag < idx_max; iQR_diag++) {
                  rankR = QRManager->jpvt[iQR_diag];
                  if ((rankR < 1) || (rankR > 15)) {
                    emlrtDynamicBoundsCheckR2012b(rankR, 1, 15, &pe_emlrtBCI,
                                                  &st);
                  }
                  TrialState->lambda[QRManager->jpvt[iQR_diag] - 1] =
                      memspace->workspace_double[iQR_diag];
                }
                st.site = &ed_emlrtRSI;
                sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
                             WorkingSet->sizes, WorkingSet->isActiveIdx,
                             WorkingSet->Wid, WorkingSet->Wlocalidx,
                             memspace->workspace_double);
                st.site = &ed_emlrtRSI;
                b_computeGradLag(&st, memspace->workspace_double, nVar,
                                 TrialState->grad, WorkingSet->Aineq,
                                 WorkingSet->indexFixed, mFixed,
                                 WorkingSet->indexLB, mLB, WorkingSet->indexUB,
                                 mUB, TrialState->lambda);
                st.site = &ed_emlrtRSI;
                b_computeDualFeasError(&st, nVar, memspace->workspace_double,
                                       &c);
                st.site = &ed_emlrtRSI;
                nlpComplErrorTmp = computeComplError(
                    &st, TrialState->xstarsqp, TrialState->cIneq,
                    WorkingSet->indexLB, mLB, lb, WorkingSet->indexUB, mUB, ub,
                    TrialState->lambda, mFixed + 1);
                d = muDoubleScalarMax(c, nlpComplErrorTmp);
                if (d <= muDoubleScalarMax(MeritFunction->nlpDualFeasError,
                                           MeritFunction->nlpComplError)) {
                  MeritFunction->nlpDualFeasError = c;
                  MeritFunction->nlpComplError = nlpComplErrorTmp;
                  MeritFunction->firstOrderOpt = d;
                  st.site = &ed_emlrtRSI;
                  xcopy(&st, mLambda, TrialState->lambda,
                        TrialState->lambdaStopTest);
                }
                if ((MeritFunction->nlpDualFeasError <=
                     1.0E-6 * optimRelativeFactor) &&
                    (MeritFunction->nlpComplError <=
                     1.0E-6 * optimRelativeFactor)) {
                  TrialState->sqpExitFlag = 1;
                } else {
                  TrialState->sqpExitFlag = 2;
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
            TrialState->sqpExitFlag = 0;
          } else if (TrialState->FunctionEvaluations >= 500) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          }
        }
      }
    }
  }
}

boolean_T test_exit(const emlrtStack *sp, c_struct_T *MeritFunction,
                    const k_struct_T *WorkingSet, j_struct_T *TrialState,
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
  st.site = &ed_emlrtRSI;
  xcopy(&st, mLambda, TrialState->lambdasqp, TrialState->lambdaStopTest);
  st.site = &ed_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aineq, WorkingSet->indexFixed,
                 WorkingSet->sizes[0], WorkingSet->indexLB,
                 WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdaStopTest);
  st.site = &ed_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &ed_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
      WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub);
  MeritFunction->feasRelativeFactor =
      muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  st.site = &ed_emlrtRSI;
  Flags_gradOK =
      computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag,
                           &MeritFunction->nlpDualFeasError);
  if (!Flags_gradOK) {
    *Flags_done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    st.site = &ed_emlrtRSI;
    computeComplError(&st, TrialState->xstarsqp, TrialState->cIneq,
                      WorkingSet->indexLB, WorkingSet->sizes[3], lb,
                      WorkingSet->indexUB, WorkingSet->sizes[4], ub,
                      TrialState->lambdaStopTest, WorkingSet->sizes[0] + 1);
    MeritFunction->nlpComplError = 0.0;
    MeritFunction->firstOrderOpt =
        muDoubleScalarMax(MeritFunction->nlpDualFeasError, 0.0);
    st.site = &ed_emlrtRSI;
    xcopy(&st, mLambda, TrialState->lambdaStopTest,
          TrialState->lambdaStopTestPrev);
    if (isFeasible &&
        (MeritFunction->nlpDualFeasError <= 1.0E-6 * optimRelativeFactor)) {
      *Flags_done = true;
      TrialState->sqpExitFlag = 1;
    } else if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
      *Flags_done = true;
      TrialState->sqpExitFlag = -3;
    } else if (TrialState->FunctionEvaluations >= 500) {
      *Flags_done = true;
      TrialState->sqpExitFlag = 0;
    }
  }
  return Flags_gradOK;
}

/* End of code generation (test_exit.c) */
