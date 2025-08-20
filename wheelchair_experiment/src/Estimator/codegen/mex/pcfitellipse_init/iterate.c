/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * iterate.c
 *
 * Code generation for function 'iterate'
 *
 */

/* Include files */
#include "iterate.h"
#include "addAineqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "deleteColMoveEnd.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "feasibleratiotest.h"
#include "moveConstraint_.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xcopy.h"
#include "xgemv.h"
#include "xnrm2.h"
#include "xtrsv.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo vf_emlrtRSI = {
    1,         /* lineNo */
    "iterate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\iterate.p" /* pathName */
};

static emlrtRSInfo ch_emlrtRSI = {
    1,                /* lineNo */
    "compute_lambda", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_lambda.p" /* pathName */
};

static emlrtRSInfo dh_emlrtRSI = {
    1,                 /* lineNo */
    "find_neg_lambda", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\find_"
    "neg_lambda.p" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    1,                          /* lineNo */
    "checkUnboundedOrIllPosed", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkUnboundedOrIllPosed.p" /* pathName */
};

static emlrtBCInfo nc_emlrtBCI = {
    1,                 /* iFirst */
    169,               /* iLast */
    1,                 /* lineNo */
    1,                 /* colNo */
    "",                /* aName */
    "isNonDegenerate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\isNonDegenerate.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    1,         /* iFirst */
    13,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "iterate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\iterate.p", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    1,                /* iFirst */
    13,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compute_lambda", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_lambda.p", /* pName */
    3                                /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    1,                 /* iFirst */
    13,                /* iLast */
    1,                 /* lineNo */
    1,                 /* colNo */
    "",                /* aName */
    "find_neg_lambda", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\find_"
    "neg_lambda.p", /* pName */
    0               /* checkKind */
};

/* Function Definitions */
void iterate(const emlrtStack *sp, const real_T H[25], const real_T f[7],
             h_struct_T *solution, d_struct_T *memspace, i_struct_T *workingset,
             e_struct_T *qrmanager, f_struct_T *cholmanager,
             struct_T *objective, const char_T options_SolverName[7],
             real_T options_StepTolerance, real_T options_ObjectiveLimit,
             int32_T runTimeOptions_MaxIterations)
{
  static const char_T b[7] = {'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T TYPE;
  int32_T activeSetChangeID;
  int32_T b_TYPE;
  int32_T globalActiveConstrIdx;
  int32_T idx;
  int32_T idxMinLambda;
  int32_T nVar;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective->objtype;
  nVar = workingset->nVar;
  globalActiveConstrIdx = 0;
  st.site = &vf_emlrtRSI;
  computeGrad_StoreHx(&st, objective, H, f, solution->xstar);
  st.site = &vf_emlrtRSI;
  solution->fstar = computeFval_ReuseHx(
      &st, objective, memspace->workspace_double, f, solution->xstar);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }
  st.site = &vf_emlrtRSI;
  f_xcopy(&st, 13, solution->lambda);
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      real_T a;
      real_T normDelta;
      int32_T ixlast;
      boolean_T guard1 = false;
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          st.site = &vf_emlrtRSI;
          squareQ_appendCol(&st, qrmanager, workingset->ATwset,
                            7 * (workingset->nActiveConstr - 1) + 1);
          break;
        case -1:
          st.site = &vf_emlrtRSI;
          deleteColMoveEnd(&st, qrmanager, globalActiveConstrIdx);
          break;
        default:
          st.site = &vf_emlrtRSI;
          factorQR(&st, qrmanager, workingset->ATwset, nVar,
                   workingset->nActiveConstr);
          st.site = &vf_emlrtRSI;
          b_st.site = &ae_emlrtRSI;
          computeQ_(&b_st, qrmanager, qrmanager->mrows);
          break;
        }
        st.site = &vf_emlrtRSI;
        compute_deltax(
            &st, H, solution, memspace, qrmanager, cholmanager, objective,
            memcmp((char_T *)&options_SolverName[0], (char_T *)&b[0], 7) == 0);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          st.site = &vf_emlrtRSI;
          normDelta = xnrm2(&st, nVar, solution->searchDir);
          if ((normDelta < options_StepTolerance) ||
              (workingset->nActiveConstr >= nVar)) {
            guard1 = true;
          } else {
            st.site = &vf_emlrtRSI;
            a = feasibleratiotest(
                &st, solution->xstar, solution->searchDir,
                memspace->workspace_double, workingset->nVar, workingset->Aineq,
                workingset->bineq, workingset->lb, workingset->ub,
                workingset->indexLB, workingset->indexUB, workingset->sizes,
                workingset->isActiveIdx, workingset->isActiveConstr,
                workingset->nWConstr, TYPE == 5, &updateFval, &idx, &b_TYPE);
            if (updateFval) {
              switch (idx) {
              case 3:
                st.site = &vf_emlrtRSI;
                addAineqConstr(&st, workingset, b_TYPE);
                break;
              case 4:
                st.site = &vf_emlrtRSI;
                b_st.site = &gh_emlrtRSI;
                addBoundToActiveSetMatrix_(&b_st, workingset, 4, b_TYPE);
                break;
              default:
                st.site = &vf_emlrtRSI;
                b_st.site = &ih_emlrtRSI;
                addBoundToActiveSetMatrix_(&b_st, workingset, 5, b_TYPE);
                break;
              }
              activeSetChangeID = 1;
            } else {
              st.site = &vf_emlrtRSI;
              if (objective->objtype == 5) {
                b_st.site = &jh_emlrtRSI;
                normDelta = xnrm2(&b_st, objective->nvar, solution->searchDir);
                b_st.site = &jh_emlrtRSI;
                if (normDelta >
                    100.0 * (real_T)objective->nvar * 1.4901161193847656E-8) {
                  solution->state = 3;
                } else {
                  solution->state = 4;
                }
              }
              subProblemChanged = false;
              if (workingset->nActiveConstr == 0) {
                solution->state = 1;
              }
            }
            if ((nVar >= 1) && (!(a == 0.0))) {
              ixlast = nVar - 1;
              b_TYPE = (nVar / 2) << 1;
              idx = b_TYPE - 2;
              for (idxMinLambda = 0; idxMinLambda <= idx; idxMinLambda += 2) {
                __m128d r;
                __m128d r1;
                r = _mm_loadu_pd(&solution->searchDir[idxMinLambda]);
                r1 = _mm_loadu_pd(&solution->xstar[idxMinLambda]);
                _mm_storeu_pd(&solution->xstar[idxMinLambda],
                              _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(a), r)));
              }
              for (idxMinLambda = b_TYPE; idxMinLambda <= ixlast;
                   idxMinLambda++) {
                solution->xstar[idxMinLambda] +=
                    a * solution->searchDir[idxMinLambda];
              }
            }
            st.site = &vf_emlrtRSI;
            computeGrad_StoreHx(&st, objective, H, f, solution->xstar);
            updateFval = true;
            st.site = &vf_emlrtRSI;
            checkStoppingAndUpdateFval(
                &st, &activeSetChangeID, f, solution, memspace, objective,
                workingset, qrmanager, options_ObjectiveLimit,
                runTimeOptions_MaxIterations, updateFval);
          }
        }
      } else {
        st.site = &vf_emlrtRSI;
        b_st.site = &oc_emlrtRSI;
        c_st.site = &pc_emlrtRSI;
        if (nVar > 2147483646) {
          d_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        idx = (uint8_T)nVar;
        memset(&solution->searchDir[0], 0, (uint32_T)idx * sizeof(real_T));
        guard1 = true;
      }
      if (guard1) {
        st.site = &vf_emlrtRSI;
        b_TYPE = qrmanager->ncols;
        if (qrmanager->ncols > 0) {
          boolean_T b_guard1 = false;
          b_guard1 = false;
          if (objective->objtype != 4) {
            normDelta =
                100.0 * (real_T)qrmanager->mrows * 2.2204460492503131E-16;
            b_st.site = &ch_emlrtRSI;
            if ((qrmanager->mrows > 0) && (qrmanager->ncols > 0)) {
              updateFval = true;
            } else {
              updateFval = false;
            }
            if (updateFval) {
              boolean_T exitg2;
              boolean_T guard2 = false;
              idx = b_TYPE;
              guard2 = false;
              if (qrmanager->mrows < qrmanager->ncols) {
                ixlast = qrmanager->mrows + 13 * (qrmanager->ncols - 1);
                exitg2 = false;
                while ((!exitg2) && (idx > qrmanager->mrows)) {
                  if ((ixlast < 1) || (ixlast > 169)) {
                    emlrtDynamicBoundsCheckR2012b(ixlast, 1, 169, &nc_emlrtBCI,
                                                  &b_st);
                  }
                  if (muDoubleScalarAbs(qrmanager->QR[ixlast - 1]) >=
                      normDelta) {
                    idx--;
                    ixlast -= 13;
                  } else {
                    exitg2 = true;
                  }
                }
                updateFval = (idx == qrmanager->mrows);
                if (updateFval) {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }
              if (guard2) {
                ixlast = idx + 13 * (idx - 1);
                exitg2 = false;
                while ((!exitg2) && (idx >= 1)) {
                  if ((ixlast < 1) || (ixlast > 169)) {
                    emlrtDynamicBoundsCheckR2012b(ixlast, 1, 169, &nc_emlrtBCI,
                                                  &b_st);
                  }
                  if (muDoubleScalarAbs(qrmanager->QR[ixlast - 1]) >=
                      normDelta) {
                    idx--;
                    ixlast -= 14;
                  } else {
                    exitg2 = true;
                  }
                }
                updateFval = (idx == 0);
              }
            }
            if (!updateFval) {
              solution->state = -7;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }
          if (b_guard1) {
            b_st.site = &ch_emlrtRSI;
            b_xgemv(&b_st, qrmanager->mrows, qrmanager->ncols, qrmanager->Q,
                    objective->grad, memspace->workspace_double);
            b_st.site = &ch_emlrtRSI;
            xtrsv(qrmanager->ncols, qrmanager->QR, memspace->workspace_double);
            b_st.site = &ch_emlrtRSI;
            if (qrmanager->ncols > 2147483646) {
              c_st.site = &hb_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }
            for (idx = 0; idx < b_TYPE; idx++) {
              if ((idx + 1 < 1) || (idx + 1 > 13)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &pc_emlrtBCI,
                                              &st);
              }
              solution->lambda[idx] = -memspace->workspace_double[idx];
            }
          }
        }
        if ((solution->state != -7) || (workingset->nActiveConstr > nVar)) {
          st.site = &vf_emlrtRSI;
          idxMinLambda = -1;
          normDelta = 0.0;
          b_TYPE = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
          ixlast = workingset->nActiveConstr;
          b_st.site = &dh_emlrtRSI;
          if ((b_TYPE <= workingset->nActiveConstr) &&
              (workingset->nActiveConstr > 2147483646)) {
            c_st.site = &hb_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (idx = b_TYPE; idx <= ixlast; idx++) {
            if ((idx < 1) || (idx > 13)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &qc_emlrtBCI, &st);
            }
            a = solution->lambda[idx - 1];
            if (a < normDelta) {
              normDelta = a;
              idxMinLambda = idx - 1;
            }
          }
          if (idxMinLambda + 1 == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = idxMinLambda + 1;
            subProblemChanged = true;
            st.site = &vf_emlrtRSI;
            b_TYPE = workingset->Wid[idxMinLambda];
            if ((workingset->Wid[idxMinLambda] < 1) ||
                (workingset->Wid[idxMinLambda] > 6)) {
              emlrtDynamicBoundsCheckR2012b(workingset->Wid[idxMinLambda], 1, 6,
                                            &gb_emlrtBCI, &st);
            }
            idx = (workingset->isActiveIdx[workingset->Wid[idxMinLambda] - 1] +
                   workingset->Wlocalidx[idxMinLambda]) -
                  1;
            if ((idx < 1) || (idx > 13)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &kb_emlrtBCI, &st);
            }
            workingset->isActiveConstr[idx - 1] = false;
            b_st.site = &ve_emlrtRSI;
            moveConstraint_(&b_st, workingset, workingset->nActiveConstr,
                            idxMinLambda + 1);
            workingset->nActiveConstr--;
            if ((b_TYPE < 1) || (b_TYPE > 5)) {
              emlrtDynamicBoundsCheckR2012b(b_TYPE, 1, 5, &mb_emlrtBCI, &st);
            }
            workingset->nWConstr[b_TYPE - 1]--;
            solution->lambda[idxMinLambda] = 0.0;
          }
        } else {
          idxMinLambda = workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          if ((workingset->nActiveConstr < 1) ||
              (workingset->nActiveConstr > 13)) {
            emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, 13,
                                          &oc_emlrtBCI, (emlrtConstCTX)sp);
          }
          st.site = &vf_emlrtRSI;
          b_TYPE = workingset->nActiveConstr - 1;
          ixlast = workingset->Wid[b_TYPE];
          if ((ixlast < 1) || (ixlast > 6)) {
            emlrtDynamicBoundsCheckR2012b(
                workingset->Wid[workingset->nActiveConstr - 1], 1, 6,
                &gb_emlrtBCI, &st);
          }
          idx = (workingset->isActiveIdx[ixlast - 1] +
                 workingset->Wlocalidx[b_TYPE]) -
                1;
          if ((idx < 1) || (idx > 13)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &kb_emlrtBCI, &st);
          }
          workingset->isActiveConstr[idx - 1] = false;
          b_st.site = &ve_emlrtRSI;
          moveConstraint_(&b_st, workingset, workingset->nActiveConstr,
                          workingset->nActiveConstr);
          workingset->nActiveConstr = b_TYPE;
          if (ixlast > 5) {
            emlrtDynamicBoundsCheckR2012b(6, 1, 5, &mb_emlrtBCI, &st);
          }
          workingset->nWConstr[ixlast - 1]--;
          solution->lambda[idxMinLambda - 1] = 0.0;
        }
        updateFval = false;
        st.site = &vf_emlrtRSI;
        checkStoppingAndUpdateFval(&st, &activeSetChangeID, f, solution,
                                   memspace, objective, workingset, qrmanager,
                                   options_ObjectiveLimit,
                                   runTimeOptions_MaxIterations, updateFval);
      }
    } else {
      if (!updateFval) {
        st.site = &vf_emlrtRSI;
        solution->fstar = computeFval_ReuseHx(
            &st, objective, memspace->workspace_double, f, solution->xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (iterate.c) */
