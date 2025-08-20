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
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "xgemv.h"
#include "xgeqp3.h"
#include "xtrsv.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo vc_emlrtRSI = {
    1,           /* lineNo */
    "test_exit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\test_"
    "exit.p" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    1,                  /* lineNo */
    "computeLambdaLSQ", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeLambdaLSQ.p" /* pathName */
};

static emlrtBCInfo ge_emlrtBCI = {
    1,                  /* iFirst */
    169,                /* iLast */
    1,                  /* lineNo */
    1,                  /* colNo */
    "",                 /* aName */
    "computeLambdaLSQ", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeLambdaLSQ.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
    1,                  /* iFirst */
    13,                 /* iLast */
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
void b_test_exit(const emlrtStack *sp, c_struct_T *Flags, d_struct_T *memspace,
                 b_struct_T *MeritFunction, const i_struct_T *WorkingSet,
                 h_struct_T *TrialState, e_struct_T *QRManager,
                 const real_T lb[5], const real_T ub[5])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T nlpComplErrorLSQ;
  real_T optimRelativeFactor;
  real_T tol;
  int32_T idx;
  int32_T idx_max;
  int32_T mFixed;
  int32_T mLambda;
  boolean_T isFeasible;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  mFixed = WorkingSet->sizes[0];
  mLambda =
      ((WorkingSet->sizes[0] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
      1;
  st.site = &vc_emlrtRSI;
  xcopy(&st, mLambda, TrialState->lambdasqp, TrialState->lambdaStopTest);
  st.site = &vc_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aineq, WorkingSet->indexFixed,
                 WorkingSet->sizes[0], WorkingSet->indexLB,
                 WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdaStopTest);
  st.site = &vc_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &vc_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
      WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub);
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor =
        muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  }
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  st.site = &vc_emlrtRSI;
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
    st.site = &vc_emlrtRSI;
    MeritFunction->nlpComplError = computeComplError(
        &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
        WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub,
        TrialState->lambdaStopTest, WorkingSet->sizes[0] + 1);
    tol = muDoubleScalarMax(MeritFunction->nlpDualFeasError,
                            MeritFunction->nlpComplError);
    MeritFunction->firstOrderOpt = tol;
    if (TrialState->sqpIterations > 1) {
      real_T d;
      real_T nlpComplErrorTmp;
      st.site = &vc_emlrtRSI;
      b_computeGradLag(
          &st, memspace->workspace_double, WorkingSet->nVar, TrialState->grad,
          WorkingSet->Aineq, WorkingSet->indexFixed, WorkingSet->sizes[0],
          WorkingSet->indexLB, WorkingSet->sizes[3], WorkingSet->indexUB,
          WorkingSet->sizes[4], TrialState->lambdaStopTestPrev);
      st.site = &vc_emlrtRSI;
      b_computeDualFeasError(&st, WorkingSet->nVar, memspace->workspace_double,
                             &nlpComplErrorLSQ);
      st.site = &vc_emlrtRSI;
      nlpComplErrorTmp = computeComplError(
          &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
          WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4],
          ub, TrialState->lambdaStopTestPrev, WorkingSet->sizes[0] + 1);
      d = muDoubleScalarMax(nlpComplErrorLSQ, nlpComplErrorTmp);
      if (d < tol) {
        MeritFunction->nlpDualFeasError = nlpComplErrorLSQ;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        MeritFunction->firstOrderOpt = d;
        st.site = &vc_emlrtRSI;
        xcopy(&st, mLambda, TrialState->lambdaStopTestPrev,
              TrialState->lambdaStopTest);
      } else {
        st.site = &vc_emlrtRSI;
        xcopy(&st, mLambda, TrialState->lambdaStopTest,
              TrialState->lambdaStopTestPrev);
      }
    } else {
      st.site = &vc_emlrtRSI;
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
        boolean_T guard1 = false;
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          boolean_T dxTooSmall;
          st.site = &vc_emlrtRSI;
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
              idx_max = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr > 0) {
                int32_T iQR_diag;
                int32_T vectorUB;
                boolean_T exitg1;
                st.site = &vc_emlrtRSI;
                b_st.site = &yd_emlrtRSI;
                f_xcopy(&b_st, WorkingSet->nActiveConstr, TrialState->lambda);
                b_st.site = &yd_emlrtRSI;
                c_st.site = &gd_emlrtRSI;
                if (WorkingSet->nActiveConstr > 2147483646) {
                  d_st.site = &hb_emlrtRSI;
                  check_forloop_overflow_error(&d_st);
                }
                for (idx = 0; idx < idx_max; idx++) {
                  c_st.site = &gd_emlrtRSI;
                  b_xcopy(&c_st, WorkingSet->nVar, WorkingSet->ATwset,
                          7 * idx + 1, QRManager->QR, 13 * idx + 1);
                }
                QRManager->usedPivoting = true;
                QRManager->mrows = WorkingSet->nVar;
                QRManager->ncols = WorkingSet->nActiveConstr;
                vectorUB = muIntScalarMin_sint32(WorkingSet->nVar,
                                                 WorkingSet->nActiveConstr);
                QRManager->minRowCol = vectorUB;
                c_st.site = &gd_emlrtRSI;
                xgeqp3(&c_st, QRManager->QR, WorkingSet->nVar,
                       WorkingSet->nActiveConstr, QRManager->jpvt,
                       QRManager->tau);
                b_st.site = &yd_emlrtRSI;
                c_st.site = &ae_emlrtRSI;
                computeQ_(&c_st, QRManager, WorkingSet->nVar);
                b_st.site = &yd_emlrtRSI;
                b_xgemv(&b_st, WorkingSet->nVar, WorkingSet->nVar, QRManager->Q,
                        TrialState->grad, memspace->workspace_double);
                tol = muDoubleScalarAbs(QRManager->QR[0]) *
                      muDoubleScalarMin(
                          1.4901161193847656E-8,
                          (real_T)muIntScalarMax_sint32(
                              WorkingSet->nVar, WorkingSet->nActiveConstr) *
                              2.2204460492503131E-16);
                idx_max = 0;
                iQR_diag = 1;
                exitg1 = false;
                while ((!exitg1) && (idx_max < vectorUB)) {
                  if (iQR_diag > 169) {
                    emlrtDynamicBoundsCheckR2012b(iQR_diag, 1, 169,
                                                  &ge_emlrtBCI, &st);
                  }
                  if (muDoubleScalarAbs(QRManager->QR[iQR_diag - 1]) > tol) {
                    idx_max++;
                    iQR_diag += 14;
                  } else {
                    exitg1 = true;
                  }
                }
                b_st.site = &yd_emlrtRSI;
                xtrsv(idx_max, QRManager->QR, memspace->workspace_double);
                idx_max =
                    muIntScalarMin_sint32(WorkingSet->nActiveConstr, vectorUB);
                b_st.site = &yd_emlrtRSI;
                if (idx_max > 2147483646) {
                  c_st.site = &hb_emlrtRSI;
                  check_forloop_overflow_error(&c_st);
                }
                vectorUB = (uint8_T)idx_max;
                for (idx = 0; idx < vectorUB; idx++) {
                  idx_max = QRManager->jpvt[idx];
                  if ((idx_max < 1) || (idx_max > 13)) {
                    emlrtDynamicBoundsCheckR2012b(idx_max, 1, 13, &he_emlrtBCI,
                                                  &st);
                  }
                  TrialState->lambda[QRManager->jpvt[idx] - 1] =
                      memspace->workspace_double[idx];
                }
                idx_max = WorkingSet->sizes[0] + 1;
                st.site = &vc_emlrtRSI;
                if ((WorkingSet->sizes[0] + 1 <= WorkingSet->sizes[0]) &&
                    (WorkingSet->sizes[0] > 2147483646)) {
                  b_st.site = &hb_emlrtRSI;
                  check_forloop_overflow_error(&b_st);
                }
                iQR_diag = ((((mFixed - idx_max) + 1) / 2) << 1) + idx_max;
                vectorUB = iQR_diag - 2;
                for (idx = idx_max; idx <= vectorUB; idx += 2) {
                  __m128d r;
                  r = _mm_loadu_pd(&TrialState->lambda[idx - 1]);
                  _mm_storeu_pd(&TrialState->lambda[idx - 1],
                                _mm_mul_pd(r, _mm_set1_pd(-1.0)));
                }
                for (idx = iQR_diag; idx <= mFixed; idx++) {
                  TrialState->lambda[idx - 1] = -TrialState->lambda[idx - 1];
                }
                st.site = &vc_emlrtRSI;
                sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
                             WorkingSet->sizes, WorkingSet->isActiveIdx,
                             WorkingSet->Wid, WorkingSet->Wlocalidx,
                             memspace->workspace_double);
                st.site = &vc_emlrtRSI;
                b_computeGradLag(&st, memspace->workspace_double,
                                 WorkingSet->nVar, TrialState->grad,
                                 WorkingSet->Aineq, WorkingSet->indexFixed,
                                 WorkingSet->sizes[0], WorkingSet->indexLB,
                                 WorkingSet->sizes[3], WorkingSet->indexUB,
                                 WorkingSet->sizes[4], TrialState->lambda);
                st.site = &vc_emlrtRSI;
                b_computeDualFeasError(&st, WorkingSet->nVar,
                                       memspace->workspace_double, &tol);
                st.site = &vc_emlrtRSI;
                nlpComplErrorLSQ = computeComplError(
                    &st, TrialState->xstarsqp, TrialState->cIneq,
                    WorkingSet->indexLB, WorkingSet->sizes[3], lb,
                    WorkingSet->indexUB, WorkingSet->sizes[4], ub,
                    TrialState->lambda, WorkingSet->sizes[0] + 1);
                if ((tol <= 1.0E-6 * optimRelativeFactor) &&
                    (nlpComplErrorLSQ <= 1.0E-6 * optimRelativeFactor)) {
                  MeritFunction->nlpDualFeasError = tol;
                  MeritFunction->nlpComplError = nlpComplErrorLSQ;
                  MeritFunction->firstOrderOpt =
                      muDoubleScalarMax(tol, nlpComplErrorLSQ);
                  st.site = &vc_emlrtRSI;
                  xcopy(&st, mLambda, TrialState->lambda,
                        TrialState->lambdaStopTest);
                  Flags->done = true;
                  TrialState->sqpExitFlag = 1;
                } else {
                  Flags->done = true;
                  TrialState->sqpExitFlag = 2;
                }
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = 2;
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

boolean_T test_exit(const emlrtStack *sp, b_struct_T *MeritFunction,
                    const i_struct_T *WorkingSet, h_struct_T *TrialState,
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
      1;
  st.site = &vc_emlrtRSI;
  xcopy(&st, mLambda, TrialState->lambdasqp, TrialState->lambdaStopTest);
  st.site = &vc_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aineq, WorkingSet->indexFixed,
                 WorkingSet->sizes[0], WorkingSet->indexLB,
                 WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdaStopTest);
  st.site = &vc_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &vc_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      &st, TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
      WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub);
  MeritFunction->feasRelativeFactor =
      muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  st.site = &vc_emlrtRSI;
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
    st.site = &vc_emlrtRSI;
    computeComplError(&st, TrialState->xstarsqp, TrialState->cIneq,
                      WorkingSet->indexLB, WorkingSet->sizes[3], lb,
                      WorkingSet->indexUB, WorkingSet->sizes[4], ub,
                      TrialState->lambdaStopTest, WorkingSet->sizes[0] + 1);
    MeritFunction->nlpComplError = 0.0;
    MeritFunction->firstOrderOpt =
        muDoubleScalarMax(MeritFunction->nlpDualFeasError, 0.0);
    st.site = &vc_emlrtRSI;
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
