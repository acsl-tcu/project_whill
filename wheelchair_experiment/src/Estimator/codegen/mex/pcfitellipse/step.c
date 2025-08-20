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
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
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
static emlrtRSInfo qe_emlrtRSI =
    {
        1,      /* lineNo */
        "step", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
        "fminconsqp\\step.p" /* pathName */
};

static emlrtRSInfo re_emlrtRSI = {
    1,        /* lineNo */
    "normal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\normal.p" /* pathName */
};

static emlrtRSInfo vh_emlrtRSI = {
    1,                   /* lineNo */
    "makeBoundFeasible", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\makeBoundFeasible.p" /* pathName */
};

static emlrtRSInfo gi_emlrtRSI = {
    1,                   /* lineNo */
    "saturateDirection", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\saturateDirection.p" /* pathName */
};

static emlrtRSInfo hi_emlrtRSI = {
    1,           /* lineNo */
    "BFGSReset", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "fminconsqp\\BFGSReset.p" /* pathName */
};

static emlrtBCInfo gb_emlrtBCI = {
    1,                   /* iFirst */
    8,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "makeBoundFeasible", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\makeBoundFeasible.p", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
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

static emlrtBCInfo ib_emlrtBCI = {
    1,                   /* iFirst */
    8,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "saturateDirection", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\saturateDirection.p", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
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
               const real_T lb[5], const real_T ub[5], j_struct_T *TrialState,
               c_struct_T *MeritFunction, f_struct_T *memspace,
               k_struct_T *WorkingSet, g_struct_T *QRManager,
               h_struct_T *CholManager, b_struct_T *QPObjective,
               m_struct_T *qpoptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  m_struct_T b_qpoptions;
  real_T dv[8];
  real_T constrViolDelta;
  real_T linearizedConstrViolPrev;
  int32_T i;
  int32_T idx;
  int32_T nVar;
  int32_T scalarLB;
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
    st.site = &qe_emlrtRSI;
    c_xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar);
  } else {
    st.site = &qe_emlrtRSI;
    d_xcopy(&st, WorkingSet->nVar, TrialState->xstar, TrialState->searchDir);
  }
  int32_T exitg1;
  boolean_T guard1;
  do {
    exitg1 = 0;
    guard1 = false;
    switch (*STEP_TYPE) {
    case 1: {
      st.site = &qe_emlrtRSI;
      b_qpoptions = *qpoptions;
      b_st.site = &re_emlrtRSI;
      driver(&b_st, Hessian, TrialState->grad, TrialState, memspace, WorkingSet,
             QRManager, CholManager, QPObjective, &b_qpoptions,
             qpoptions->MaxIterations);
      if (TrialState->state > 0) {
        real_T constrViolationIneq;
        real_T penaltyParamTrial;
        b_st.site = &re_emlrtRSI;
        penaltyParamTrial = MeritFunction->penaltyParam;
        constrViolationIneq = 0.0;
        linearizedConstrViolPrev = TrialState->cIneq[0];
        if (linearizedConstrViolPrev > 0.0) {
          constrViolationIneq = linearizedConstrViolPrev;
        }
        linearizedConstrViolPrev = TrialState->cIneq[1];
        if (linearizedConstrViolPrev > 0.0) {
          constrViolationIneq += linearizedConstrViolPrev;
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
      b_st.site = &re_emlrtRSI;
      sortLambdaQP(&b_st, TrialState->lambda, WorkingSet->nActiveConstr,
                   WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                   WorkingSet->Wlocalidx, memspace->workspace_double);
      if (WorkingSet->mEqRemoved > 0) {
        b_st.site = &re_emlrtRSI;
      }
      if ((TrialState->state <= 0) && (TrialState->state != -6)) {
        *STEP_TYPE = 2;
      } else {
        st.site = &qe_emlrtRSI;
        d_xcopy(&st, nVar, TrialState->xstar, TrialState->delta_x);
        guard1 = true;
      }
    } break;
    case 2:
      st.site = &qe_emlrtRSI;
      removeAllIneqConstr(&st, WorkingSet);
      st.site = &qe_emlrtRSI;
      memcpy(&dv[0], &TrialState->xstar[0], 8U * sizeof(real_T));
      b_st.site = &vh_emlrtRSI;
      if (WorkingSet->sizes[3] > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      i = (uint8_T)WorkingSet->sizes[3];
      for (idx = 0; idx < i; idx++) {
        if (idx + 1 > 8) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &gb_emlrtBCI, &st);
        }
        if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 8)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 8,
                                        &gb_emlrtBCI, &st);
        }
        linearizedConstrViolPrev = WorkingSet->lb[WorkingSet->indexLB[idx] - 1];
        if (-dv[WorkingSet->indexLB[idx] - 1] > linearizedConstrViolPrev) {
          if ((WorkingSet->indexLB[idx] < 1) ||
              (WorkingSet->indexLB[idx] > 5)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 5,
                                          &hb_emlrtBCI, &st);
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
      b_st.site = &vh_emlrtRSI;
      if (WorkingSet->sizes[4] > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      i = (uint8_T)WorkingSet->sizes[4];
      for (idx = 0; idx < i; idx++) {
        if ((WorkingSet->indexUB[idx] < 1) || (WorkingSet->indexUB[idx] > 8)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->indexUB[idx], 1, 8,
                                        &gb_emlrtBCI, &st);
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
      memcpy(&TrialState->xstar[0], &dv[0], 8U * sizeof(real_T));
      st.site = &qe_emlrtRSI;
      relaxed(&st, Hessian, TrialState->grad, TrialState, MeritFunction,
              memspace, WorkingSet, QRManager, CholManager, QPObjective,
              qpoptions);
      st.site = &qe_emlrtRSI;
      d_xcopy(&st, nVar, TrialState->xstar, TrialState->delta_x);
      guard1 = true;
      break;
    default: {
      memcpy(&dv[0], &TrialState->grad[0], 8U * sizeof(real_T));
      st.site = &qe_emlrtRSI;
      stepSuccess = soc(&st, Hessian, dv, TrialState, memspace, WorkingSet,
                        QRManager, CholManager, QPObjective, qpoptions);
      checkBoundViolation = stepSuccess;
      if (stepSuccess && (TrialState->state != -6)) {
        int32_T vectorUB;
        st.site = &qe_emlrtRSI;
        if (nVar > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        i = (uint8_T)nVar;
        scalarLB = ((uint8_T)nVar >> 1) << 1;
        vectorUB = scalarLB - 2;
        for (idx = 0; idx <= vectorUB; idx += 2) {
          __m128d r;
          __m128d r1;
          r = _mm_loadu_pd(&TrialState->xstar[idx]);
          r1 = _mm_loadu_pd(&TrialState->socDirection[idx]);
          _mm_storeu_pd(&TrialState->delta_x[idx], _mm_add_pd(r, r1));
        }
        for (idx = scalarLB; idx < i; idx++) {
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
        st.site = &qe_emlrtRSI;
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
        for (scalarLB = 0; scalarLB < 5; scalarLB++) {
          b_st.site = &hi_emlrtRSI;
          h_xcopy(&b_st, scalarLB, Hessian, 5 * scalarLB + 1);
          i = scalarLB + 5 * scalarLB;
          Hessian[i] = linearizedConstrViolPrev;
          b_st.site = &hi_emlrtRSI;
          h_xcopy(&b_st, 4 - scalarLB, Hessian, i + 2);
        }
      }
    }
  } while (exitg1 == 0);
  if (checkBoundViolation) {
    st.site = &qe_emlrtRSI;
    memcpy(&dv[0], &TrialState->delta_x[0], 8U * sizeof(real_T));
    b_st.site = &gi_emlrtRSI;
    if (WorkingSet->sizes[3] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)WorkingSet->sizes[3];
    for (idx = 0; idx < i; idx++) {
      if (idx + 1 > 8) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &ib_emlrtBCI, &st);
      }
      scalarLB = WorkingSet->indexLB[idx];
      if ((scalarLB < 1) || (scalarLB > 5)) {
        emlrtDynamicBoundsCheckR2012b(scalarLB, 1, 5, &jb_emlrtBCI, &st);
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
    b_st.site = &gi_emlrtRSI;
    if (WorkingSet->sizes[4] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)WorkingSet->sizes[4];
    for (idx = 0; idx < i; idx++) {
      scalarLB = WorkingSet->indexUB[idx];
      if ((scalarLB < 1) || (scalarLB > 5)) {
        emlrtDynamicBoundsCheckR2012b(scalarLB, 1, 5, &jb_emlrtBCI, &st);
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
    memcpy(&TrialState->delta_x[0], &dv[0], 8U * sizeof(real_T));
  }
  return stepSuccess;
}

/* End of code generation (step.c) */
