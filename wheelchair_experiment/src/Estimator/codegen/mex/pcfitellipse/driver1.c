/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver1.c
 *
 * Code generation for function 'driver1'
 *
 */

/* Include files */
#include "driver1.h"
#include "BFGSUpdate.h"
#include "computeConstrViolationIneq_.h"
#include "computeConstraints_.h"
#include "computeDeltaLag.h"
#include "computeForwardDifferences.h"
#include "computeLinearResiduals.h"
#include "computeObjective_.h"
#include "eml_int_forloop_overflow_check.h"
#include "isDeltaXTooSmall.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "pcfitellipse_types.h"
#include "rt_nonfinite.h"
#include "saveJacobian.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo dd_emlrtRSI = {
    1,        /* lineNo */
    "driver", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\driver.p" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    1,           /* lineNo */
    "saveState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "TrialState\\saveState.p" /* pathName */
};

static emlrtRSInfo ii_emlrtRSI = {
    1,                  /* lineNo */
    "evalObjAndConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "ObjNonlinEvaluator\\evalObjAndConstr.p" /* pathName */
};

static emlrtRSInfo ji_emlrtRSI = {
    1,                 /* lineNo */
    "computeMeritFcn", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "MeritFunction\\computeMeritFcn.p" /* pathName */
};

static emlrtRSInfo ki_emlrtRSI = {
    1,            /* lineNo */
    "linesearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\linesearch.p" /* pathName */
};

static emlrtRSInfo li_emlrtRSI = {
    1,                /* lineNo */
    "revertSolution", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "TrialState\\revertSolution.p" /* pathName */
};

static emlrtBCInfo ue_emlrtBCI = {
    1,        /* iFirst */
    5,        /* iLast */
    1,        /* lineNo */
    1,        /* colNo */
    "",       /* aName */
    "driver", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\driver.p", /* pName */
    3                       /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = {
    1,            /* iFirst */
    5,            /* iLast */
    1,            /* lineNo */
    1,            /* colNo */
    "",           /* aName */
    "linesearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\linesearch.p", /* pName */
    3                           /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = {
    1,        /* iFirst */
    15,       /* iLast */
    1,        /* lineNo */
    1,        /* colNo */
    "",       /* aName */
    "driver", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\driver.p", /* pName */
    3                       /* checkKind */
};

/* Function Definitions */
void b_driver(const emlrtStack *sp, real_T bineq, const real_T lb[5],
              const real_T ub[5], j_struct_T *TrialState,
              c_struct_T *MeritFunction,
              const i_coder_internal_stickyStruct *FcnEvaluator,
              l_struct_T *FiniteDifferences, f_struct_T *memspace,
              k_struct_T *WorkingSet, real_T Hessian[25], g_struct_T *QRManager,
              h_struct_T *CholManager, b_struct_T *QPObjective)
{
  static const char_T qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                                 'c', 'o', 'n'};
  static const int8_T b_iv[25] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
                                  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1};
  d_struct_T Flags;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  m_struct_T b_expl_temp;
  m_struct_T expl_temp;
  int32_T b_i;
  int32_T i;
  int32_T k;
  int32_T mConstr;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  int32_T nVar_tmp_tmp;
  int32_T qpoptions_MaxIterations;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  memset(&QPObjective->grad[0], 0, 8U * sizeof(real_T));
  for (i = 0; i < 7; i++) {
    QPObjective->Hx[i] = 0.0;
  }
  QPObjective->hasLinear = true;
  QPObjective->nvar = 5;
  QPObjective->maxVar = 8;
  QPObjective->beta = 0.0;
  QPObjective->rho = 0.0;
  QPObjective->objtype = 3;
  QPObjective->prev_objtype = 3;
  QPObjective->prev_nvar = 0;
  QPObjective->prev_hasLinear = false;
  QPObjective->gammaScalar = 0.0;
  CholManager->ldm = 15;
  CholManager->ndims = 0;
  CholManager->info = 0;
  CholManager->scaleFactor = 0.0;
  CholManager->ConvexCheck = true;
  CholManager->regTol_ = rtInf;
  CholManager->workspace_ = rtInf;
  CholManager->workspace2_ = rtInf;
  QRManager->ldq = 15;
  memset(&CholManager->FMat[0], 0, 225U * sizeof(real_T));
  memset(&QRManager->QR[0], 0, 225U * sizeof(real_T));
  memset(&QRManager->Q[0], 0, 225U * sizeof(real_T));
  QRManager->mrows = 0;
  QRManager->ncols = 0;
  memset(&QRManager->tau[0], 0, 15U * sizeof(real_T));
  for (i = 0; i < 15; i++) {
    QRManager->jpvt[i] = 0;
  }
  QRManager->minRowCol = 0;
  QRManager->usedPivoting = false;
  for (b_i = 0; b_i < 25; b_i++) {
    Hessian[b_i] = b_iv[b_i];
  }
  nVar_tmp_tmp = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mConstr =
      ((WorkingSet->sizes[0] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
      2;
  i = ((WorkingSet->sizes[3] + WorkingSet->sizes[4]) +
       (WorkingSet->sizes[0] << 1)) +
      2;
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet->nVar, i);
  TrialState->steplength = 1.0;
  st.site = &dd_emlrtRSI;
  Flags.gradOK = test_exit(&st, MeritFunction, WorkingSet, TrialState, lb, ub,
                           &Flags.fevalOK, &Flags.done, &Flags.stepAccepted,
                           &Flags.failedLineSearch, &Flags.stepType);
  st.site = &dd_emlrtRSI;
  saveJacobian(&st, TrialState, nVar_tmp_tmp, WorkingSet->Aineq);
  st.site = &dd_emlrtRSI;
  TrialState->sqpFval_old = TrialState->sqpFval;
  for (k = 0; k < 5; k++) {
    TrialState->xstarsqp_old[k] = TrialState->xstarsqp[k];
    TrialState->grad_old[k] = TrialState->grad[k];
  }
  b_st.site = &pe_emlrtRSI;
  f_xcopy(TrialState->cIneq, TrialState->cIneq_old);
  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }
  while (!Flags.done) {
    __m128d r;
    __m128d r1;
    real_T phi_alpha;
    int32_T scalarLB;
    int32_T vectorUB;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      real_T constrViolationIneq;
      if (Flags.stepType != 3) {
        st.site = &dd_emlrtRSI;
        b_updateWorkingSetForNewQP(&st, TrialState->xstarsqp, WorkingSet,
                                   TrialState->cIneq, mLB, lb, mUB, ub, mFixed);
      }
      expl_temp.ObjectiveLimit = rtMinusInf;
      expl_temp.StepTolerance = 1.0E-6;
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (b_i = 0; b_i < 7; b_i++) {
        expl_temp.SolverName[b_i] = qpoptions_SolverName[b_i];
      }
      b_expl_temp = expl_temp;
      st.site = &dd_emlrtRSI;
      Flags.stepAccepted =
          step(&st, &Flags.stepType, Hessian, lb, ub, TrialState, MeritFunction,
               memspace, WorkingSet, QRManager, CholManager, QPObjective,
               &b_expl_temp);
      if (Flags.stepAccepted) {
        st.site = &dd_emlrtRSI;
        if (nVar_tmp_tmp > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        b_i = (uint8_T)nVar_tmp_tmp;
        for (i = 0; i < b_i; i++) {
          if (i + 1 > 5) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, 5, &ue_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          TrialState->xstarsqp[i] += TrialState->delta_x[i];
        }
        st.site = &dd_emlrtRSI;
        b_st.site = &ii_emlrtRSI;
        phi_alpha = computeObjective_(&b_st,
                                      &FcnEvaluator->next.next.next.next.next
                                           .next.next.next.value.workspace,
                                      TrialState->xstarsqp, &i);
        if (i == 1) {
          b_st.site = &ii_emlrtRSI;
          i = computeConstraints_(FcnEvaluator->next.next.next.next.next.next
                                      .next.value.workspace.COG_init,
                                  TrialState->xstarsqp, TrialState->cIneq);
        }
        TrialState->sqpFval = phi_alpha;
        Flags.fevalOK = (i == 1);
        TrialState->FunctionEvaluations++;
        st.site = &dd_emlrtRSI;
        computeLinearResiduals(&st, TrialState->xstarsqp, nVar_tmp_tmp,
                               TrialState->cIneq, WorkingSet->Aineq, bineq);
        st.site = &dd_emlrtRSI;
        if (Flags.fevalOK) {
          b_st.site = &ji_emlrtRSI;
          constrViolationIneq = computeConstrViolationIneq_(TrialState->cIneq);
          MeritFunction->phiFullStep =
              phi_alpha + MeritFunction->penaltyParam * constrViolationIneq;
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        real_T alpha;
        int32_T exitflagLnSrch;
        boolean_T evalWellDefined;
        boolean_T socTaken;
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        st.site = &dd_emlrtRSI;
        evalWellDefined = Flags.fevalOK;
        b_i = WorkingSet->nVar;
        alpha = 1.0;
        exitflagLnSrch = 1;
        phi_alpha = MeritFunction->phiFullStep;
        b_st.site = &ki_emlrtRSI;
        d_xcopy(&b_st, WorkingSet->nVar, TrialState->delta_x,
                TrialState->searchDir);
        int32_T exitg1;
        do {
          exitg1 = 0;
          if (TrialState->FunctionEvaluations < 500) {
            if (evalWellDefined &&
                (phi_alpha <=
                 MeritFunction->phi +
                     alpha * 0.0001 * MeritFunction->phiPrimePlus)) {
              exitg1 = 1;
            } else {
              int32_T i1;
              boolean_T tooSmallX;
              alpha *= 0.7;
              b_st.site = &ki_emlrtRSI;
              if (b_i > 2147483646) {
                c_st.site = &o_emlrtRSI;
                check_forloop_overflow_error(&c_st);
              }
              i1 = (uint8_T)b_i;
              scalarLB = ((uint8_T)b_i >> 1) << 1;
              vectorUB = scalarLB - 2;
              for (i = 0; i <= vectorUB; i += 2) {
                r = _mm_loadu_pd(&TrialState->xstar[i]);
                _mm_storeu_pd(&TrialState->delta_x[i],
                              _mm_mul_pd(_mm_set1_pd(alpha), r));
              }
              for (i = scalarLB; i < i1; i++) {
                TrialState->delta_x[i] = alpha * TrialState->xstar[i];
              }
              if (socTaken) {
                phi_alpha = alpha * alpha;
                if ((b_i >= 1) && (!(phi_alpha == 0.0))) {
                  i = b_i - 1;
                  scalarLB = (b_i / 2) << 1;
                  vectorUB = scalarLB - 2;
                  for (k = 0; k <= vectorUB; k += 2) {
                    r = _mm_loadu_pd(&TrialState->socDirection[k]);
                    r1 = _mm_loadu_pd(&TrialState->delta_x[k]);
                    _mm_storeu_pd(
                        &TrialState->delta_x[k],
                        _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(phi_alpha), r)));
                  }
                  for (k = scalarLB; k <= i; k++) {
                    TrialState->delta_x[k] +=
                        phi_alpha * TrialState->socDirection[k];
                  }
                }
              }
              b_st.site = &ki_emlrtRSI;
              tooSmallX = isDeltaXTooSmall(&b_st, TrialState->xstarsqp,
                                           TrialState->delta_x, b_i);
              if (tooSmallX) {
                exitflagLnSrch = -2;
                exitg1 = 1;
              } else {
                b_st.site = &ki_emlrtRSI;
                for (i = 0; i < i1; i++) {
                  if (i + 1 > 5) {
                    emlrtDynamicBoundsCheckR2012b(i + 1, 1, 5, &ve_emlrtBCI,
                                                  &st);
                  }
                  TrialState->xstarsqp[i] =
                      TrialState->xstarsqp_old[i] + TrialState->delta_x[i];
                }
                b_st.site = &ki_emlrtRSI;
                c_st.site = &ii_emlrtRSI;
                phi_alpha =
                    computeObjective_(&c_st,
                                      &FcnEvaluator->next.next.next.next.next
                                           .next.next.next.value.workspace,
                                      TrialState->xstarsqp, &i);
                if (i == 1) {
                  i = computeConstraints_(
                      FcnEvaluator->next.next.next.next.next.next.next.value
                          .workspace.COG_init,
                      TrialState->xstarsqp, TrialState->cIneq);
                }
                TrialState->sqpFval = phi_alpha;
                b_st.site = &ki_emlrtRSI;
                computeLinearResiduals(&b_st, TrialState->xstarsqp, b_i,
                                       TrialState->cIneq, WorkingSet->Aineq,
                                       bineq);
                TrialState->FunctionEvaluations++;
                evalWellDefined = (i == 1);
                b_st.site = &ki_emlrtRSI;
                if (evalWellDefined) {
                  constrViolationIneq =
                      computeConstrViolationIneq_(TrialState->cIneq);
                  phi_alpha +=
                      MeritFunction->penaltyParam * constrViolationIneq;
                } else {
                  phi_alpha = rtInf;
                }
              }
            }
          } else {
            exitflagLnSrch = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
        Flags.fevalOK = evalWellDefined;
        TrialState->steplength = alpha;
        if (exitflagLnSrch > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      st.site = &dd_emlrtRSI;
      if (nVar_tmp_tmp > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      b_i = (uint8_T)nVar_tmp_tmp;
      for (i = 0; i < b_i; i++) {
        if (i + 1 > 5) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, 5, &ue_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        TrialState->xstarsqp[i] =
            TrialState->xstarsqp_old[i] + TrialState->delta_x[i];
      }
      st.site = &dd_emlrtRSI;
      if (mConstr > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      b_i = (uint8_T)mConstr;
      scalarLB = ((uint8_T)mConstr >> 1) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r = _mm_loadu_pd(&TrialState->lambda[i]);
        r1 = _mm_loadu_pd(&TrialState->lambdasqp[i]);
        if (i + 1 > 15) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, 15, &we_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        _mm_storeu_pd(
            &TrialState->lambdasqp[i],
            _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(TrialState->steplength),
                                      _mm_sub_pd(r, r1))));
      }
      for (i = scalarLB; i < b_i; i++) {
        phi_alpha = TrialState->lambdasqp[i];
        phi_alpha +=
            TrialState->steplength * (TrialState->lambda[i] - phi_alpha);
        if (i + 1 > 15) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, 15, &we_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        TrialState->lambdasqp[i] = phi_alpha;
      }
      st.site = &dd_emlrtRSI;
      TrialState->sqpFval_old = TrialState->sqpFval;
      for (k = 0; k < 5; k++) {
        TrialState->xstarsqp_old[k] = TrialState->xstarsqp[k];
        TrialState->grad_old[k] = TrialState->grad[k];
      }
      b_st.site = &pe_emlrtRSI;
      f_xcopy(TrialState->cIneq, TrialState->cIneq_old);
      st.site = &dd_emlrtRSI;
      b_st.site = &oc_emlrtRSI;
      Flags.gradOK = computeForwardDifferences(
          &b_st, FiniteDifferences, TrialState->sqpFval, TrialState->cIneq,
          TrialState->xstarsqp, TrialState->grad, WorkingSet->Aineq, lb, ub);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      st.site = &dd_emlrtRSI;
      TrialState->sqpFval = TrialState->sqpFval_old;
      for (k = 0; k < 5; k++) {
        TrialState->xstarsqp[k] = TrialState->xstarsqp_old[k];
      }
      b_st.site = &li_emlrtRSI;
      f_xcopy(TrialState->cIneq_old, TrialState->cIneq);
    }
    st.site = &dd_emlrtRSI;
    b_test_exit(&st, &Flags, memspace, MeritFunction, WorkingSet, TrialState,
                QRManager, lb, ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      st.site = &dd_emlrtRSI;
      computeDeltaLag(&st, nVar_tmp_tmp, TrialState->delta_gradLag,
                      TrialState->grad, WorkingSet->Aineq, TrialState->grad_old,
                      TrialState->JacCineqTrans_old, TrialState->lambdasqp,
                      mFixed + 2);
      st.site = &dd_emlrtRSI;
      saveJacobian(&st, TrialState, nVar_tmp_tmp, WorkingSet->Aineq);
      st.site = &dd_emlrtRSI;
      BFGSUpdate(&st, nVar_tmp_tmp, Hessian, TrialState->delta_x,
                 TrialState->delta_gradLag, memspace->workspace_double);
      TrialState->sqpIterations++;
    }
  }
}

/* End of code generation (driver1.c) */
