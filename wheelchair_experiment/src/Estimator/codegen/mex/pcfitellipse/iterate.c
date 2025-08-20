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
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "compute_lambda.h"
#include "deleteColMoveEnd.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "feasibleX0ForWorkingSet.h"
#include "feasibleratiotest.h"
#include "maxConstraintViolation.h"
#include "moveConstraint_.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xcopy.h"
#include "xnrm2.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo eg_emlrtRSI = {
    1,         /* lineNo */
    "iterate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\iterate.p" /* pathName */
};

static emlrtRSInfo lh_emlrtRSI = {
    1,                 /* lineNo */
    "find_neg_lambda", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\find_"
    "neg_lambda.p" /* pathName */
};

static emlrtRSInfo rh_emlrtRSI = {
    1,                          /* lineNo */
    "checkUnboundedOrIllPosed", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkUnboundedOrIllPosed.p" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    1,                            /* lineNo */
    "checkStoppingAndUpdateFval", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkStoppingAndUpdateFval.p" /* pathName */
};

static emlrtBCInfo uc_emlrtBCI = {
    1,         /* iFirst */
    15,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "iterate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\iterate.p", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = {
    1,         /* iFirst */
    15,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "iterate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\iterate.p", /* pName */
    3                         /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    1,                            /* iFirst */
    8,                            /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "checkStoppingAndUpdateFval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkStoppingAndUpdateFval.p", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = {
    1,                 /* iFirst */
    15,                /* iLast */
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
void iterate(const emlrtStack *sp, const real_T H[25], const real_T f[8],
             j_struct_T *solution, f_struct_T *memspace, k_struct_T *workingset,
             g_struct_T *qrmanager, h_struct_T *cholmanager,
             b_struct_T *objective, const char_T options_SolverName[7],
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
  int32_T globalActiveConstrIdx;
  int32_T idxMinLambda;
  int32_T ixlast;
  int32_T nVar;
  int32_T vectorUB;
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
  st.site = &eg_emlrtRSI;
  computeGrad_StoreHx(&st, objective, H, f, solution->xstar);
  st.site = &eg_emlrtRSI;
  solution->fstar = computeFval_ReuseHx(
      &st, objective, memspace->workspace_double, f, solution->xstar);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }
  st.site = &eg_emlrtRSI;
  g_xcopy(&st, 15, solution->lambda);
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      real_T a;
      real_T normDelta;
      int32_T scalarLB;
      boolean_T guard1;
      boolean_T guard2;
      guard1 = false;
      guard2 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          st.site = &eg_emlrtRSI;
          squareQ_appendCol(&st, qrmanager, workingset->ATwset,
                            ((workingset->nActiveConstr - 1) << 3) + 1);
          break;
        case -1:
          st.site = &eg_emlrtRSI;
          deleteColMoveEnd(&st, qrmanager, globalActiveConstrIdx);
          break;
        default:
          st.site = &eg_emlrtRSI;
          factorQR(&st, qrmanager, workingset->ATwset, nVar,
                   workingset->nActiveConstr);
          st.site = &eg_emlrtRSI;
          b_st.site = &ie_emlrtRSI;
          computeQ_(&b_st, qrmanager, qrmanager->mrows);
          break;
        }
        st.site = &eg_emlrtRSI;
        compute_deltax(
            &st, H, solution, memspace, qrmanager, cholmanager, objective,
            memcmp((char_T *)&options_SolverName[0], (char_T *)&b[0], 7) == 0);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          st.site = &eg_emlrtRSI;
          normDelta = xnrm2(&st, nVar, solution->searchDir);
          if ((normDelta < options_StepTolerance) ||
              (workingset->nActiveConstr >= nVar)) {
            guard2 = true;
          } else {
            st.site = &eg_emlrtRSI;
            a = feasibleratiotest(
                &st, solution->xstar, solution->searchDir,
                memspace->workspace_double, workingset->nVar, workingset->Aineq,
                workingset->bineq, workingset->lb, workingset->ub,
                workingset->indexLB, workingset->indexUB, workingset->sizes,
                workingset->isActiveIdx, workingset->isActiveConstr,
                workingset->nWConstr, TYPE == 5, &updateFval, &vectorUB,
                &ixlast);
            if (updateFval) {
              switch (vectorUB) {
              case 3:
                st.site = &eg_emlrtRSI;
                addAineqConstr(&st, workingset, ixlast);
                break;
              case 4:
                st.site = &eg_emlrtRSI;
                b_st.site = &oh_emlrtRSI;
                addBoundToActiveSetMatrix_(&b_st, workingset, 4, ixlast);
                break;
              default:
                st.site = &eg_emlrtRSI;
                b_st.site = &qh_emlrtRSI;
                addBoundToActiveSetMatrix_(&b_st, workingset, 5, ixlast);
                break;
              }
              activeSetChangeID = 1;
            } else {
              st.site = &eg_emlrtRSI;
              if (objective->objtype == 5) {
                b_st.site = &rh_emlrtRSI;
                normDelta = xnrm2(&b_st, objective->nvar, solution->searchDir);
                b_st.site = &rh_emlrtRSI;
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
              scalarLB = (nVar / 2) << 1;
              vectorUB = scalarLB - 2;
              for (idxMinLambda = 0; idxMinLambda <= vectorUB;
                   idxMinLambda += 2) {
                __m128d r;
                __m128d r1;
                r = _mm_loadu_pd(&solution->searchDir[idxMinLambda]);
                r1 = _mm_loadu_pd(&solution->xstar[idxMinLambda]);
                _mm_storeu_pd(&solution->xstar[idxMinLambda],
                              _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(a), r)));
              }
              for (idxMinLambda = scalarLB; idxMinLambda <= ixlast;
                   idxMinLambda++) {
                solution->xstar[idxMinLambda] +=
                    a * solution->searchDir[idxMinLambda];
              }
            }
            st.site = &eg_emlrtRSI;
            computeGrad_StoreHx(&st, objective, H, f, solution->xstar);
            updateFval = true;
            guard1 = true;
          }
        }
      } else {
        st.site = &eg_emlrtRSI;
        b_st.site = &wc_emlrtRSI;
        c_st.site = &xc_emlrtRSI;
        if (nVar > 2147483646) {
          d_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        vectorUB = (uint8_T)nVar;
        memset(&solution->searchDir[0], 0, (uint32_T)vectorUB * sizeof(real_T));
        guard2 = true;
      }
      if (guard2) {
        st.site = &eg_emlrtRSI;
        compute_lambda(&st, memspace->workspace_double, solution, objective,
                       qrmanager);
        if ((solution->state != -7) || (workingset->nActiveConstr > nVar)) {
          st.site = &eg_emlrtRSI;
          idxMinLambda = 0;
          normDelta = 0.0;
          ixlast = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
          scalarLB = workingset->nActiveConstr;
          b_st.site = &lh_emlrtRSI;
          if ((ixlast <= workingset->nActiveConstr) &&
              (workingset->nActiveConstr > 2147483646)) {
            c_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (vectorUB = ixlast; vectorUB <= scalarLB; vectorUB++) {
            if ((vectorUB < 1) || (vectorUB > 15)) {
              emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 15, &xc_emlrtBCI, &st);
            }
            a = solution->lambda[vectorUB - 1];
            if (a < normDelta) {
              normDelta = a;
              idxMinLambda = vectorUB;
            }
          }
          if (idxMinLambda == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = idxMinLambda;
            subProblemChanged = true;
            st.site = &eg_emlrtRSI;
            ixlast = workingset->Wid[idxMinLambda - 1];
            if ((ixlast < 1) || (ixlast > 6)) {
              emlrtDynamicBoundsCheckR2012b(workingset->Wid[idxMinLambda - 1],
                                            1, 6, &nb_emlrtBCI, &st);
            }
            vectorUB = (workingset->isActiveIdx[ixlast - 1] +
                        workingset->Wlocalidx[idxMinLambda - 1]) -
                       1;
            if ((vectorUB < 1) || (vectorUB > 15)) {
              emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 15, &rb_emlrtBCI, &st);
            }
            workingset->isActiveConstr[vectorUB - 1] = false;
            if (idxMinLambda < workingset->nActiveConstr) {
              b_st.site = &ef_emlrtRSI;
              moveConstraint_(&b_st, workingset, workingset->nActiveConstr,
                              idxMinLambda);
            }
            workingset->nActiveConstr--;
            if (ixlast > 5) {
              emlrtDynamicBoundsCheckR2012b(6, 1, 5, &tb_emlrtBCI, &st);
            }
            workingset->nWConstr[ixlast - 1]--;
            if (idxMinLambda < workingset->nActiveConstr + 1) {
              vectorUB = workingset->nActiveConstr + 1;
              if ((vectorUB < 1) || (vectorUB > 15)) {
                emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 15, &uc_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              solution->lambda[idxMinLambda - 1] =
                  solution->lambda[vectorUB - 1];
            }
            vectorUB = workingset->nActiveConstr + 1;
            if ((vectorUB < 1) || (vectorUB > 15)) {
              emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 15, &vc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            solution->lambda[vectorUB - 1] = 0.0;
          }
        } else {
          idxMinLambda = workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          if ((workingset->nActiveConstr < 1) ||
              (workingset->nActiveConstr > 15)) {
            emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, 15,
                                          &uc_emlrtBCI, (emlrtConstCTX)sp);
          }
          st.site = &eg_emlrtRSI;
          ixlast = workingset->nActiveConstr - 1;
          scalarLB = workingset->Wid[ixlast];
          if ((scalarLB < 1) || (scalarLB > 6)) {
            emlrtDynamicBoundsCheckR2012b(
                workingset->Wid[workingset->nActiveConstr - 1], 1, 6,
                &nb_emlrtBCI, &st);
          }
          vectorUB = (workingset->isActiveIdx[scalarLB - 1] +
                      workingset->Wlocalidx[ixlast]) -
                     1;
          if ((vectorUB < 1) || (vectorUB > 15)) {
            emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 15, &rb_emlrtBCI, &st);
          }
          workingset->isActiveConstr[vectorUB - 1] = false;
          workingset->nActiveConstr = ixlast;
          if (scalarLB > 5) {
            emlrtDynamicBoundsCheckR2012b(6, 1, 5, &tb_emlrtBCI, &st);
          }
          workingset->nWConstr[scalarLB - 1]--;
          solution->lambda[idxMinLambda - 1] = 0.0;
        }
        updateFval = false;
        guard1 = true;
      }
      if (guard1) {
        st.site = &eg_emlrtRSI;
        solution->iterations++;
        if ((solution->iterations >= runTimeOptions_MaxIterations) &&
            ((solution->state != 1) || (objective->objtype == 5))) {
          solution->state = 0;
        }
        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          b_st.site = &sh_emlrtRSI;
          solution->maxConstr =
              c_maxConstraintViolation(&b_st, workingset, solution->xstar);
          normDelta = solution->maxConstr;
          if (objective->objtype == 5) {
            if ((objective->nvar < 1) || (objective->nvar > 8)) {
              emlrtDynamicBoundsCheckR2012b(objective->nvar, 1, 8, &wc_emlrtBCI,
                                            &st);
            }
            normDelta =
                solution->maxConstr - solution->xstar[objective->nvar - 1];
          }
          if (normDelta > 1.0E-6) {
            boolean_T nonDegenerateWset;
            b_st.site = &sh_emlrtRSI;
            d_xcopy(&b_st, objective->nvar, solution->xstar,
                    solution->searchDir);
            b_st.site = &sh_emlrtRSI;
            nonDegenerateWset = feasibleX0ForWorkingSet(
                &b_st, memspace->workspace_double, solution->searchDir,
                workingset, qrmanager);
            if ((!nonDegenerateWset) && (solution->state != 0)) {
              solution->state = -2;
            }
            activeSetChangeID = 0;
            b_st.site = &sh_emlrtRSI;
            normDelta = c_maxConstraintViolation(&b_st, workingset,
                                                 solution->searchDir);
            if (normDelta < solution->maxConstr) {
              b_st.site = &sh_emlrtRSI;
              if (objective->nvar > 2147483646) {
                c_st.site = &o_emlrtRSI;
                check_forloop_overflow_error(&c_st);
              }
              vectorUB = (uint8_T)objective->nvar;
              if (vectorUB - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       (uint32_T)vectorUB * sizeof(real_T));
              }
              solution->maxConstr = normDelta;
            }
          }
        }
        if (updateFval) {
          if (options_ObjectiveLimit > rtMinusInf) {
            b_st.site = &sh_emlrtRSI;
            solution->fstar = computeFval_ReuseHx(&b_st, objective,
                                                  memspace->workspace_double, f,
                                                  solution->xstar);
            if ((solution->fstar < options_ObjectiveLimit) &&
                ((solution->state != 0) || (objective->objtype != 5))) {
              solution->state = 2;
            }
          } else {
            updateFval = false;
          }
        }
      }
    } else {
      if (!updateFval) {
        st.site = &eg_emlrtRSI;
        solution->fstar = computeFval_ReuseHx(
            &st, objective, memspace->workspace_double, f, solution->xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (iterate.c) */
