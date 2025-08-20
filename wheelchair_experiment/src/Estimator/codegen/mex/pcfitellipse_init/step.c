/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * step.c
 *
 * Code generation for function 'step'
 *
 */

/* Include files */
#include "step.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "relaxed.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "soc.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ie_emlrtRSI =
    {
        1,      /* lineNo */
        "step", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
        "fminconsqp\\step.p" /* pathName */
};

static emlrtRSInfo je_emlrtRSI = {
    1,        /* lineNo */
    "normal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\normal.p" /* pathName */
};

static emlrtRSInfo nh_emlrtRSI = {
    1,                   /* lineNo */
    "makeBoundFeasible", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\makeBoundFeasible.p" /* pathName */
};

static emlrtRSInfo xh_emlrtRSI = {
    1,                   /* lineNo */
    "saturateDirection", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\saturateDirection.p" /* pathName */
};

static emlrtRSInfo yh_emlrtRSI = {
    1,           /* lineNo */
    "BFGSReset", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\BFGSReset.p" /* pathName */
};

static emlrtBCInfo y_emlrtBCI = {
    1,                   /* iFirst */
    7,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "makeBoundFeasible", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\makeBoundFeasible.p", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    1,                   /* iFirst */
    5,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "makeBoundFeasible", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\makeBoundFeasible.p", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    1,                   /* iFirst */
    7,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "saturateDirection", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\saturateDirection.p", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    1,                   /* iFirst */
    5,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "saturateDirection", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\saturateDirection.p", /* pName */
    0                            /* checkKind */
};

/* Function Definitions */
boolean_T step(const emlrtStack *sp, int32_T *STEP_TYPE, real_T Hessian[25],
               const real_T lb[5], const real_T ub[5], h_struct_T *TrialState,
               b_struct_T *MeritFunction, d_struct_T *memspace,
               i_struct_T *WorkingSet, e_struct_T *QRManager,
               f_struct_T *CholManager, struct_T *QPObjective,
               k_struct_T *qpoptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  k_struct_T b_qpoptions;
  real_T dv[7];
  real_T constrViolDelta;
  real_T linearizedConstrViolPrev;
  int32_T b_i;
  int32_T i;
  int32_T idx;
  int32_T nVar;
  int32_T vectorUB;
  boolean_T checkBoundViolation;
  boolean_T stepSuccess;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  stepSuccess = true;
  checkBoundViolation = true;
  nVar = WorkingSet->nVar;
  if (*STEP_TYPE != 3) {
    st.site = &ie_emlrtRSI;
    c_xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar);
  } else {
    st.site = &ie_emlrtRSI;
    d_xcopy(&st, WorkingSet->nVar, TrialState->xstar, TrialState->searchDir);
  }
  int32_T exitg1;
  boolean_T guard1 = false;
  do {
    exitg1 = 0;
    guard1 = false;
    switch (*STEP_TYPE) {
    case 1: {
      st.site = &ie_emlrtRSI;
      b_qpoptions = *qpoptions;
      b_st.site = &je_emlrtRSI;
      driver(&b_st, Hessian, TrialState->grad, TrialState, memspace, WorkingSet,
             QRManager, CholManager, QPObjective, &b_qpoptions,
             qpoptions->MaxIterations);
      if (TrialState->state > 0) {
        real_T constrViolationIneq;
        real_T penaltyParamTrial;
        b_st.site = &je_emlrtRSI;
        penaltyParamTrial = MeritFunction->penaltyParam;
        linearizedConstrViolPrev = TrialState->cIneq;
        constrViolationIneq = 0.0;
        if (linearizedConstrViolPrev > 0.0) {
          constrViolationIneq = linearizedConstrViolPrev;
        }
        linearizedConstrViolPrev = MeritFunction->linearizedConstrViol;
        MeritFunction->linearizedConstrViol = 0.0;
        constrViolDelta = constrViolationIneq + linearizedConstrViolPrev;
        if ((constrViolDelta > 2.2204460492503131E-16) &&
            (TrialState->fstar > 0.0)) {
          if (TrialState->sqpFval == 0.0) {
            penaltyParamTrial = 1.0;
          } else {
            penaltyParamTrial = 1.5;
          }
          penaltyParamTrial =
              penaltyParamTrial * TrialState->fstar / constrViolDelta;
        }
        if (penaltyParamTrial < MeritFunction->penaltyParam) {
          MeritFunction->phi =
              TrialState->sqpFval + penaltyParamTrial * constrViolationIneq;
          if ((MeritFunction->initFval +
               penaltyParamTrial * MeritFunction->initConstrViolationIneq) -
                  MeritFunction->phi >
              (real_T)MeritFunction->nPenaltyDecreases *
                  MeritFunction->threshold) {
            MeritFunction->nPenaltyDecreases++;
            if ((MeritFunction->nPenaltyDecreases << 1) >
                TrialState->sqpIterations) {
              MeritFunction->threshold *= 10.0;
            }
            MeritFunction->penaltyParam =
                muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
          } else {
            MeritFunction->phi =
                TrialState->sqpFval +
                MeritFunction->penaltyParam * constrViolationIneq;
          }
        } else {
          MeritFunction->penaltyParam =
              muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
          MeritFunction->phi =
              TrialState->sqpFval +
              MeritFunction->penaltyParam * constrViolationIneq;
        }
        MeritFunction->phiPrimePlus =
            muDoubleScalarMin(TrialState->fstar - MeritFunction->penaltyParam *
                                                      constrViolationIneq,
                              0.0);
      }
      b_st.site = &je_emlrtRSI;
      sortLambdaQP(&b_st, TrialState->lambda, WorkingSet->nActiveConstr,
                   WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                   WorkingSet->Wlocalidx, memspace->workspace_double);
      if (WorkingSet->mEqRemoved > 0) {
        b_st.site = &je_emlrtRSI;
      }
      if ((TrialState->state <= 0) && (TrialState->state != -6)) {
        *STEP_TYPE = 2;
      } else {
        st.site = &ie_emlrtRSI;
        d_xcopy(&st, nVar, TrialState->xstar, TrialState->delta_x);
        guard1 = true;
      }
    } break;
    case 2:
      st.site = &ie_emlrtRSI;
      removeAllIneqConstr(&st, WorkingSet);
      st.site = &ie_emlrtRSI;
      for (i = 0; i < 7; i++) {
        dv[i] = TrialState->xstar[i];
      }
      b_st.site = &nh_emlrtRSI;
      if (WorkingSet->sizes[3] > 2147483646) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      b_i = (uint8_T)WorkingSet->sizes[3];
      for (idx = 0; idx < b_i; idx++) {
        if (idx + 1 > 7) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &y_emlrtBCI, &st);
        }
        if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 7)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 7,
                                        &y_emlrtBCI, &st);
        }
        linearizedConstrViolPrev = WorkingSet->lb[WorkingSet->indexLB[idx] - 1];
        if (-dv[WorkingSet->indexLB[idx] - 1] > linearizedConstrViolPrev) {
          if ((WorkingSet->indexLB[idx] < 1) ||
              (WorkingSet->indexLB[idx] > 5)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 5,
                                          &ab_emlrtBCI, &st);
          }
          if (muDoubleScalarIsInf(ub[WorkingSet->indexLB[idx] - 1])) {
            dv[WorkingSet->indexLB[idx] - 1] =
                -linearizedConstrViolPrev +
                muDoubleScalarAbs(linearizedConstrViolPrev);
          } else {
            dv[WorkingSet->indexLB[idx] - 1] =
                (WorkingSet->ub[WorkingSet->indexLB[idx] - 1] -
                 linearizedConstrViolPrev) /
                2.0;
          }
        }
      }
      b_st.site = &nh_emlrtRSI;
      if (WorkingSet->sizes[4] > 2147483646) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      b_i = (uint8_T)WorkingSet->sizes[4];
      for (idx = 0; idx < b_i; idx++) {
        if ((WorkingSet->indexUB[idx] < 1) || (WorkingSet->indexUB[idx] > 7)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->indexUB[idx], 1, 7,
                                        &y_emlrtBCI, &st);
        }
        linearizedConstrViolPrev = WorkingSet->ub[WorkingSet->indexUB[idx] - 1];
        if (dv[WorkingSet->indexUB[idx] - 1] > linearizedConstrViolPrev) {
          if (muDoubleScalarIsInf(lb[WorkingSet->indexUB[idx] - 1])) {
            dv[WorkingSet->indexUB[idx] - 1] =
                linearizedConstrViolPrev -
                muDoubleScalarAbs(linearizedConstrViolPrev);
          } else {
            dv[WorkingSet->indexUB[idx] - 1] =
                (linearizedConstrViolPrev -
                 WorkingSet->lb[WorkingSet->indexUB[idx] - 1]) /
                2.0;
          }
        }
      }
      for (i = 0; i < 7; i++) {
        TrialState->xstar[i] = dv[i];
      }
      st.site = &ie_emlrtRSI;
      relaxed(&st, Hessian, TrialState->grad, TrialState, MeritFunction,
              memspace, WorkingSet, QRManager, CholManager, QPObjective,
              qpoptions);
      st.site = &ie_emlrtRSI;
      d_xcopy(&st, nVar, TrialState->xstar, TrialState->delta_x);
      guard1 = true;
      break;
    default: {
      for (i = 0; i < 7; i++) {
        dv[i] = TrialState->grad[i];
      }
      st.site = &ie_emlrtRSI;
      stepSuccess = soc(&st, Hessian, dv, TrialState, memspace, WorkingSet,
                        QRManager, CholManager, QPObjective, qpoptions);
      checkBoundViolation = stepSuccess;
      if (stepSuccess && (TrialState->state != -6)) {
        st.site = &ie_emlrtRSI;
        if (nVar > 2147483646) {
          b_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        b_i = (uint8_T)nVar;
        i = ((uint8_T)nVar >> 1) << 1;
        vectorUB = i - 2;
        for (idx = 0; idx <= vectorUB; idx += 2) {
          __m128d r;
          __m128d r1;
          r = _mm_loadu_pd(&TrialState->xstar[idx]);
          r1 = _mm_loadu_pd(&TrialState->socDirection[idx]);
          _mm_storeu_pd(&TrialState->delta_x[idx], _mm_add_pd(r, r1));
        }
        for (idx = i; idx < b_i; idx++) {
          TrialState->delta_x[idx] =
              TrialState->xstar[idx] + TrialState->socDirection[idx];
        }
      }
      guard1 = true;
    } break;
    }
    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        st.site = &ie_emlrtRSI;
        linearizedConstrViolPrev = 0.0;
        constrViolDelta = 1.0;
        for (idx = 0; idx < 5; idx++) {
          linearizedConstrViolPrev =
              muDoubleScalarMax(linearizedConstrViolPrev,
                                muDoubleScalarAbs(TrialState->grad[idx]));
          constrViolDelta = muDoubleScalarMax(
              constrViolDelta, muDoubleScalarAbs(TrialState->xstar[idx]));
        }
        linearizedConstrViolPrev = muDoubleScalarMax(
            2.2204460492503131E-16, linearizedConstrViolPrev / constrViolDelta);
        for (vectorUB = 0; vectorUB < 5; vectorUB++) {
          b_st.site = &yh_emlrtRSI;
          g_xcopy(&b_st, vectorUB, Hessian, 5 * vectorUB + 1);
          b_i = vectorUB + 5 * vectorUB;
          Hessian[b_i] = linearizedConstrViolPrev;
          b_st.site = &yh_emlrtRSI;
          g_xcopy(&b_st, 4 - vectorUB, Hessian, b_i + 2);
        }
      }
    }
  } while (exitg1 == 0);
  if (checkBoundViolation) {
    st.site = &ie_emlrtRSI;
    for (i = 0; i < 7; i++) {
      dv[i] = TrialState->delta_x[i];
    }
    b_st.site = &xh_emlrtRSI;
    if (WorkingSet->sizes[3] > 2147483646) {
      c_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    b_i = (uint8_T)WorkingSet->sizes[3];
    for (idx = 0; idx < b_i; idx++) {
      if (idx + 1 > 7) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &bb_emlrtBCI, &st);
      }
      i = WorkingSet->indexLB[idx];
      if ((i < 1) || (i > 5)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 5, &cb_emlrtBCI, &st);
      }
      linearizedConstrViolPrev = dv[WorkingSet->indexLB[idx] - 1];
      constrViolDelta = (TrialState->xstarsqp[WorkingSet->indexLB[idx] - 1] +
                         linearizedConstrViolPrev) -
                        lb[WorkingSet->indexLB[idx] - 1];
      if (constrViolDelta < 0.0) {
        dv[WorkingSet->indexLB[idx] - 1] =
            linearizedConstrViolPrev - constrViolDelta;
        TrialState->xstar[WorkingSet->indexLB[idx] - 1] -= constrViolDelta;
      }
    }
    b_st.site = &xh_emlrtRSI;
    if (WorkingSet->sizes[4] > 2147483646) {
      c_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    b_i = (uint8_T)WorkingSet->sizes[4];
    for (idx = 0; idx < b_i; idx++) {
      i = WorkingSet->indexUB[idx];
      if ((i < 1) || (i > 5)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 5, &cb_emlrtBCI, &st);
      }
      linearizedConstrViolPrev = dv[WorkingSet->indexUB[idx] - 1];
      constrViolDelta = (ub[WorkingSet->indexUB[idx] - 1] -
                         TrialState->xstarsqp[WorkingSet->indexUB[idx] - 1]) -
                        linearizedConstrViolPrev;
      if (constrViolDelta < 0.0) {
        dv[WorkingSet->indexUB[idx] - 1] =
            linearizedConstrViolPrev + constrViolDelta;
        TrialState->xstar[WorkingSet->indexUB[idx] - 1] += constrViolDelta;
      }
    }
    for (i = 0; i < 7; i++) {
      TrialState->delta_x[i] = dv[i];
    }
  }
  return stepSuccess;
}

/* End of code generation (step.c) */
