/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * phaseone.c
 *
 * Code generation for function 'phaseone'
 *
 */

/* Include files */
#include "phaseone.h"
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
#include "removeAllIneqConstr.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "squareQ_appendCol.h"
#include "xcopy.h"
#include "xnrm2.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wh_emlrtRSI = {
    1,          /* lineNo */
    "phaseone", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "phaseone.p" /* pathName */
};

static emlrtBCInfo jd_emlrtBCI = {
    1,          /* iFirst */
    8,          /* iLast */
    1,          /* lineNo */
    1,          /* colNo */
    "",         /* aName */
    "phaseone", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "phaseone.p", /* pName */
    3             /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = {
    1,          /* iFirst */
    15,         /* iLast */
    1,          /* lineNo */
    1,          /* colNo */
    "",         /* aName */
    "phaseone", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "phaseone.p", /* pName */
    0             /* checkKind */
};

/* Function Definitions */
void phaseone(const emlrtStack *sp, const real_T H[25], const real_T f[8],
              f_struct_T *solution, c_struct_T *memspace,
              g_struct_T *workingset, j_struct_T *qrmanager,
              k_struct_T *cholmanager, l_struct_T *objective,
              const char_T options_SolverName[7],
              const m_struct_T *runTimeOptions)
{
  static const char_T b[7] = {'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T PROBTYPE_ORIG;
  int32_T activeSetChangeID;
  int32_T globalActiveConstrIdx;
  int32_T i;
  int32_T idxMinLambda;
  int32_T k;
  int32_T nVar;
  int32_T nVar_tmp;
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
  PROBTYPE_ORIG = workingset->probType;
  nVar_tmp = workingset->nVar;
  i = workingset->nVar + 1;
  if ((i < 1) || (i > 8)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 8, &jd_emlrtBCI, (emlrtConstCTX)sp);
  }
  solution->xstar[i - 1] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    i = 1;
  } else {
    i = 4;
  }
  st.site = &wh_emlrtRSI;
  setProblemType(&st, workingset, i);
  st.site = &wh_emlrtRSI;
  removeAllIneqConstr(&st, workingset);
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = nVar_tmp + 1;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  st.site = &wh_emlrtRSI;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  i = workingset->nVar;
  globalActiveConstrIdx = 0;
  b_st.site = &xh_emlrtRSI;
  computeGrad_StoreHx(&b_st, objective, H, f, solution->xstar);
  b_st.site = &xh_emlrtRSI;
  solution->fstar = computeFval_ReuseHx(
      &b_st, objective, memspace->workspace_float, f, solution->xstar);
  solution->state = -5;
  b_st.site = &xh_emlrtRSI;
  b_xcopy(&b_st, 15, solution->lambda);
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
          b_st.site = &xh_emlrtRSI;
          squareQ_appendCol(&b_st, qrmanager, workingset->ATwset,
                            ((workingset->nActiveConstr - 1) << 3) + 1);
          break;
        case -1:
          b_st.site = &xh_emlrtRSI;
          deleteColMoveEnd(&b_st, qrmanager, globalActiveConstrIdx);
          break;
        default:
          b_st.site = &xh_emlrtRSI;
          factorQR(&b_st, qrmanager, workingset->ATwset, i,
                   workingset->nActiveConstr);
          b_st.site = &xh_emlrtRSI;
          c_st.site = &mg_emlrtRSI;
          computeQ_(&c_st, qrmanager, qrmanager->mrows);
          break;
        }
        b_st.site = &xh_emlrtRSI;
        compute_deltax(
            &b_st, H, solution, memspace, qrmanager, cholmanager, objective,
            memcmp((char_T *)&options_SolverName[0], (char_T *)&b[0], 7) == 0);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          b_st.site = &xh_emlrtRSI;
          normDelta = c_xnrm2(&b_st, i, solution->searchDir);
          if ((normDelta < 1.4901161193847657E-10) ||
              (workingset->nActiveConstr >= i)) {
            guard2 = true;
          } else {
            real_T a;
            b_st.site = &xh_emlrtRSI;
            a = feasibleratiotest(
                &b_st, solution->xstar, solution->searchDir,
                memspace->workspace_float, workingset->nVar, workingset->Aineq,
                workingset->bineq, workingset->lb, workingset->ub,
                workingset->indexLB, workingset->indexUB, workingset->sizes,
                workingset->isActiveIdx, workingset->isActiveConstr,
                workingset->nWConstr, true, &updateFval, &nVar, &idxMinLambda);
            if (updateFval) {
              switch (nVar) {
              case 3:
                b_st.site = &xh_emlrtRSI;
                addAineqConstr(&b_st, workingset, idxMinLambda);
                break;
              case 4:
                b_st.site = &xh_emlrtRSI;
                c_st.site = &nj_emlrtRSI;
                addBoundToActiveSetMatrix_(&c_st, workingset, idxMinLambda);
                break;
              default:
                b_st.site = &xh_emlrtRSI;
                c_st.site = &pj_emlrtRSI;
                b_addBoundToActiveSetMatrix_(&c_st, workingset, idxMinLambda);
                break;
              }
              activeSetChangeID = 1;
            } else {
              b_st.site = &xh_emlrtRSI;
              if (objective->objtype == 5) {
                c_st.site = &qj_emlrtRSI;
                normDelta =
                    c_xnrm2(&c_st, objective->nvar, solution->searchDir);
                c_st.site = &qj_emlrtRSI;
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
              idxMinLambda = (i / 2) << 1;
              nVar = idxMinLambda - 2;
              for (k = 0; k <= nVar; k += 2) {
                __m128d r;
                __m128d r1;
                r = _mm_loadu_pd(&solution->searchDir[k]);
                r1 = _mm_loadu_pd(&solution->xstar[k]);
                _mm_storeu_pd(&solution->xstar[k],
                              _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(a), r)));
              }
              for (k = idxMinLambda; k < i; k++) {
                solution->xstar[k] += a * solution->searchDir[k];
              }
            }
            b_st.site = &xh_emlrtRSI;
            computeGrad_StoreHx(&b_st, objective, H, f, solution->xstar);
            updateFval = true;
            guard1 = true;
          }
        }
      } else {
        b_st.site = &xh_emlrtRSI;
        g_xcopy(&b_st, i, solution->searchDir);
        guard2 = true;
      }
      if (guard2) {
        b_st.site = &xh_emlrtRSI;
        compute_lambda(&b_st, memspace->workspace_float, solution, objective,
                       qrmanager);
        if ((solution->state != -7) || (workingset->nActiveConstr > i)) {
          b_st.site = &xh_emlrtRSI;
          idxMinLambda =
              find_neg_lambda(&b_st, solution->lambda,
                              workingset->nActiveConstr, workingset->nWConstr);
          if (idxMinLambda == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = idxMinLambda;
            subProblemChanged = true;
            b_st.site = &xh_emlrtRSI;
            removeConstr(&b_st, workingset, idxMinLambda);
            if (idxMinLambda < workingset->nActiveConstr + 1) {
              nVar = workingset->nActiveConstr + 1;
              if ((nVar < 1) || (nVar > 15)) {
                emlrtDynamicBoundsCheckR2012b(nVar, 1, 15, &ld_emlrtBCI, &st);
              }
              solution->lambda[idxMinLambda - 1] = solution->lambda[nVar - 1];
            }
            nVar = workingset->nActiveConstr + 1;
            if ((nVar < 1) || (nVar > 15)) {
              emlrtDynamicBoundsCheckR2012b(nVar, 1, 15, &md_emlrtBCI, &st);
            }
            solution->lambda[nVar - 1] = 0.0;
          }
        } else {
          idxMinLambda = workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          if ((workingset->nActiveConstr < 1) ||
              (workingset->nActiveConstr > 15)) {
            emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, 15,
                                          &ld_emlrtBCI, &st);
          }
          b_st.site = &xh_emlrtRSI;
          removeConstr(&b_st, workingset, workingset->nActiveConstr);
          solution->lambda[idxMinLambda - 1] = 0.0;
        }
        updateFval = false;
        guard1 = true;
      }
      if (guard1) {
        b_st.site = &xh_emlrtRSI;
        solution->iterations++;
        nVar = objective->nvar;
        if ((solution->iterations >= runTimeOptions->MaxIterations) &&
            ((solution->state != 1) || (objective->objtype == 5))) {
          solution->state = 0;
        }
        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          c_st.site = &rj_emlrtRSI;
          solution->maxConstr =
              c_maxConstraintViolation(&c_st, workingset, solution->xstar);
          normDelta = solution->maxConstr;
          if (objective->objtype == 5) {
            if ((objective->nvar < 1) || (objective->nvar > 8)) {
              emlrtDynamicBoundsCheckR2012b(objective->nvar, 1, 8, &od_emlrtBCI,
                                            &b_st);
            }
            normDelta =
                solution->maxConstr - solution->xstar[objective->nvar - 1];
          }
          if (normDelta > 1.0E-6) {
            boolean_T nonDegenerateWset;
            c_st.site = &rj_emlrtRSI;
            e_xcopy(&c_st, objective->nvar, solution->xstar,
                    solution->searchDir);
            c_st.site = &rj_emlrtRSI;
            nonDegenerateWset = feasibleX0ForWorkingSet(
                &c_st, memspace->workspace_float, solution->searchDir,
                workingset, qrmanager);
            if ((!nonDegenerateWset) && (solution->state != 0)) {
              solution->state = -2;
            }
            activeSetChangeID = 0;
            c_st.site = &rj_emlrtRSI;
            normDelta = c_maxConstraintViolation(&c_st, workingset,
                                                 solution->searchDir);
            if (normDelta < solution->maxConstr) {
              c_st.site = &rj_emlrtRSI;
              if (objective->nvar > 2147483646) {
                d_st.site = &u_emlrtRSI;
                check_forloop_overflow_error(&d_st);
              }
              for (idxMinLambda = 0; idxMinLambda < nVar; idxMinLambda++) {
                if ((idxMinLambda + 1 < 1) || (idxMinLambda + 1 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(idxMinLambda + 1, 1, 8,
                                                &pd_emlrtBCI, &b_st);
                }
                solution->xstar[idxMinLambda] =
                    solution->searchDir[idxMinLambda];
              }
            }
          }
        }
        if (updateFval) {
          c_st.site = &rj_emlrtRSI;
          solution->fstar = computeFval_ReuseHx(
              &c_st, objective, memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < 1.0E-6) &&
              ((solution->state != 0) || (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        b_st.site = &xh_emlrtRSI;
        solution->fstar = computeFval_ReuseHx(
            &b_st, objective, memspace->workspace_float, f, solution->xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  st.site = &wh_emlrtRSI;
  i = workingset->isActiveIdx[3] + workingset->sizes[3];
  if ((i - 1 < 1) || (i - 1 > 15)) {
    emlrtDynamicBoundsCheckR2012b(i - 1, 1, 15, &kd_emlrtBCI, &st);
  }
  if (workingset->isActiveConstr[i - 2]) {
    boolean_T exitg2;
    st.site = &wh_emlrtRSI;
    if ((workingset->sizes[0] + 1 <= workingset->nActiveConstr) &&
        (workingset->nActiveConstr > 2147483646)) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    idxMinLambda = workingset->sizes[0] + 1;
    exitg2 = false;
    while ((!exitg2) && (idxMinLambda <= workingset->nActiveConstr)) {
      if ((idxMinLambda < 1) || (idxMinLambda > 15)) {
        emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, 15, &nd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((workingset->Wid[idxMinLambda - 1] == 4) &&
          (workingset->Wlocalidx[idxMinLambda - 1] == workingset->sizes[3])) {
        st.site = &wh_emlrtRSI;
        removeConstr(&st, workingset, idxMinLambda);
        exitg2 = true;
      } else {
        idxMinLambda++;
      }
    }
  }
  idxMinLambda = workingset->nActiveConstr;
  nVar = workingset->sizes[0];
  while ((idxMinLambda > nVar) && (idxMinLambda > nVar_tmp)) {
    st.site = &wh_emlrtRSI;
    removeConstr(&st, workingset, idxMinLambda);
    idxMinLambda--;
  }
  solution->maxConstr = solution->xstar[nVar_tmp];
  st.site = &wh_emlrtRSI;
  setProblemType(&st, workingset, PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
}

/* End of code generation (phaseone.c) */
