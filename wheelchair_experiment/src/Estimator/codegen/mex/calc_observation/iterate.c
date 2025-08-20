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
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
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
#include "find_neg_lambda.h"
#include "maxConstraintViolation.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xcopy.h"
#include "xnrm2.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
void iterate(const emlrtStack *sp, const real_T H[25], const real_T f[8],
             f_struct_T *solution, c_struct_T *memspace, g_struct_T *workingset,
             j_struct_T *qrmanager, k_struct_T *cholmanager,
             l_struct_T *objective, const char_T options_SolverName[7],
             int32_T runTimeOptions_MaxIterations)
{
  static const char_T b[7] = {'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T TYPE;
  int32_T activeSetChangeID;
  int32_T globalActiveConstrIdx;
  int32_T idxMinLambda;
  int32_T k;
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
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective->objtype;
  nVar = workingset->nVar;
  globalActiveConstrIdx = 0;
  st.site = &xh_emlrtRSI;
  computeGrad_StoreHx(&st, objective, H, f, solution->xstar);
  st.site = &xh_emlrtRSI;
  solution->fstar = computeFval_ReuseHx(
      &st, objective, memspace->workspace_float, f, solution->xstar);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }
  st.site = &xh_emlrtRSI;
  b_xcopy(&st, 15, solution->lambda);
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      real_T normDelta;
      boolean_T guard1;
      boolean_T guard2;
      guard1 = false;
      guard2 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          st.site = &xh_emlrtRSI;
          squareQ_appendCol(&st, qrmanager, workingset->ATwset,
                            ((workingset->nActiveConstr - 1) << 3) + 1);
          break;
        case -1:
          st.site = &xh_emlrtRSI;
          deleteColMoveEnd(&st, qrmanager, globalActiveConstrIdx);
          break;
        default:
          st.site = &xh_emlrtRSI;
          factorQR(&st, qrmanager, workingset->ATwset, nVar,
                   workingset->nActiveConstr);
          st.site = &xh_emlrtRSI;
          b_st.site = &mg_emlrtRSI;
          computeQ_(&b_st, qrmanager, qrmanager->mrows);
          break;
        }
        st.site = &xh_emlrtRSI;
        compute_deltax(
            &st, H, solution, memspace, qrmanager, cholmanager, objective,
            memcmp((char_T *)&options_SolverName[0], (char_T *)&b[0], 7) == 0);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          st.site = &xh_emlrtRSI;
          normDelta = c_xnrm2(&st, nVar, solution->searchDir);
          if ((normDelta < 1.0E-6) || (workingset->nActiveConstr >= nVar)) {
            guard2 = true;
          } else {
            real_T a;
            st.site = &xh_emlrtRSI;
            a = feasibleratiotest(
                &st, solution->xstar, solution->searchDir,
                memspace->workspace_float, workingset->nVar, workingset->Aineq,
                workingset->bineq, workingset->lb, workingset->ub,
                workingset->indexLB, workingset->indexUB, workingset->sizes,
                workingset->isActiveIdx, workingset->isActiveConstr,
                workingset->nWConstr, TYPE == 5, &updateFval, &vectorUB,
                &idxMinLambda);
            if (updateFval) {
              switch (vectorUB) {
              case 3:
                st.site = &xh_emlrtRSI;
                addAineqConstr(&st, workingset, idxMinLambda);
                break;
              case 4:
                st.site = &xh_emlrtRSI;
                b_st.site = &nj_emlrtRSI;
                addBoundToActiveSetMatrix_(&b_st, workingset, idxMinLambda);
                break;
              default:
                st.site = &xh_emlrtRSI;
                b_st.site = &pj_emlrtRSI;
                b_addBoundToActiveSetMatrix_(&b_st, workingset, idxMinLambda);
                break;
              }
              activeSetChangeID = 1;
            } else {
              st.site = &xh_emlrtRSI;
              if (objective->objtype == 5) {
                b_st.site = &qj_emlrtRSI;
                normDelta =
                    c_xnrm2(&b_st, objective->nvar, solution->searchDir);
                b_st.site = &qj_emlrtRSI;
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
            if (!(a == 0.0)) {
              idxMinLambda = (nVar / 2) << 1;
              vectorUB = idxMinLambda - 2;
              for (k = 0; k <= vectorUB; k += 2) {
                __m128d r;
                __m128d r1;
                r = _mm_loadu_pd(&solution->searchDir[k]);
                r1 = _mm_loadu_pd(&solution->xstar[k]);
                _mm_storeu_pd(&solution->xstar[k],
                              _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(a), r)));
              }
              for (k = idxMinLambda; k < nVar; k++) {
                solution->xstar[k] += a * solution->searchDir[k];
              }
            }
            st.site = &xh_emlrtRSI;
            computeGrad_StoreHx(&st, objective, H, f, solution->xstar);
            guard1 = true;
          }
        }
      } else {
        st.site = &xh_emlrtRSI;
        g_xcopy(&st, nVar, solution->searchDir);
        guard2 = true;
      }
      if (guard2) {
        st.site = &xh_emlrtRSI;
        compute_lambda(&st, memspace->workspace_float, solution, objective,
                       qrmanager);
        if ((solution->state != -7) || (workingset->nActiveConstr > nVar)) {
          st.site = &xh_emlrtRSI;
          idxMinLambda =
              find_neg_lambda(&st, solution->lambda, workingset->nActiveConstr,
                              workingset->nWConstr);
          if (idxMinLambda == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = idxMinLambda;
            subProblemChanged = true;
            st.site = &xh_emlrtRSI;
            removeConstr(&st, workingset, idxMinLambda);
            if (idxMinLambda < workingset->nActiveConstr + 1) {
              vectorUB = workingset->nActiveConstr + 1;
              if ((vectorUB < 1) || (vectorUB > 15)) {
                emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 15, &ld_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              solution->lambda[idxMinLambda - 1] =
                  solution->lambda[vectorUB - 1];
            }
            vectorUB = workingset->nActiveConstr + 1;
            if ((vectorUB < 1) || (vectorUB > 15)) {
              emlrtDynamicBoundsCheckR2012b(vectorUB, 1, 15, &md_emlrtBCI,
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
                                          &ld_emlrtBCI, (emlrtConstCTX)sp);
          }
          st.site = &xh_emlrtRSI;
          removeConstr(&st, workingset, workingset->nActiveConstr);
          solution->lambda[idxMinLambda - 1] = 0.0;
        }
        guard1 = true;
      }
      if (guard1) {
        st.site = &xh_emlrtRSI;
        solution->iterations++;
        idxMinLambda = objective->nvar;
        if ((solution->iterations >= runTimeOptions_MaxIterations) &&
            ((solution->state != 1) || (objective->objtype == 5))) {
          solution->state = 0;
        }
        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          b_st.site = &rj_emlrtRSI;
          solution->maxConstr =
              c_maxConstraintViolation(&b_st, workingset, solution->xstar);
          normDelta = solution->maxConstr;
          if (objective->objtype == 5) {
            if ((objective->nvar < 1) || (objective->nvar > 8)) {
              emlrtDynamicBoundsCheckR2012b(objective->nvar, 1, 8, &od_emlrtBCI,
                                            &st);
            }
            normDelta =
                solution->maxConstr - solution->xstar[objective->nvar - 1];
          }
          if (normDelta > 1.0E-6) {
            b_st.site = &rj_emlrtRSI;
            e_xcopy(&b_st, objective->nvar, solution->xstar,
                    solution->searchDir);
            b_st.site = &rj_emlrtRSI;
            updateFval = feasibleX0ForWorkingSet(
                &b_st, memspace->workspace_float, solution->searchDir,
                workingset, qrmanager);
            if ((!updateFval) && (solution->state != 0)) {
              solution->state = -2;
            }
            activeSetChangeID = 0;
            b_st.site = &rj_emlrtRSI;
            normDelta = c_maxConstraintViolation(&b_st, workingset,
                                                 solution->searchDir);
            if (normDelta < solution->maxConstr) {
              b_st.site = &rj_emlrtRSI;
              if (objective->nvar > 2147483646) {
                c_st.site = &u_emlrtRSI;
                check_forloop_overflow_error(&c_st);
              }
              for (vectorUB = 0; vectorUB < idxMinLambda; vectorUB++) {
                if ((vectorUB + 1 < 1) || (vectorUB + 1 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(vectorUB + 1, 1, 8,
                                                &pd_emlrtBCI, &st);
                }
                solution->xstar[vectorUB] = solution->searchDir[vectorUB];
              }
              solution->maxConstr = normDelta;
            }
          }
        }
        updateFval = false;
      }
    } else {
      if (!updateFval) {
        st.site = &xh_emlrtRSI;
        solution->fstar = computeFval_ReuseHx(
            &st, objective, memspace->workspace_float, f, solution->xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (iterate.c) */
