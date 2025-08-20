/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver.c
 *
 * Code generation for function 'driver'
 *
 */

/* Include files */
#include "driver.h"
#include "PresolveWorkingSet.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "computeFval.h"
#include "eml_int_forloop_overflow_check.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "phaseone.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo yg_emlrtRSI = {
    1,             /* lineNo */
    "snap_bounds", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "snap_bounds.p" /* pathName */
};

static emlrtBCInfo hc_emlrtBCI = {
    1,             /* iFirst */
    8,             /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "snap_bounds", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "snap_bounds.p", /* pName */
    0                /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    1,             /* iFirst */
    8,             /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "snap_bounds", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "snap_bounds.p", /* pName */
    3                /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    1,             /* iFirst */
    15,            /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "snap_bounds", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "snap_bounds.p", /* pName */
    0                /* checkKind */
};

/* Function Definitions */
void driver(const emlrtStack *sp, const real_T H[25], const real_T f[8],
            f_struct_T *solution, c_struct_T *memspace, g_struct_T *workingset,
            j_struct_T *qrmanager, k_struct_T *cholmanager,
            l_struct_T *objective, const m_struct_T *options,
            const m_struct_T *runTimeOptions)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx;
  int32_T nVar;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  solution->iterations = 0;
  nVar = workingset->nVar;
  guard1 = false;
  if (workingset->probType == 3) {
    int32_T i;
    int32_T i1;
    st.site = &xg_emlrtRSI;
    b_st.site = &yg_emlrtRSI;
    if (workingset->sizes[0] > 2147483646) {
      c_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)workingset->sizes[0];
    for (idx = 0; idx < i; idx++) {
      if ((workingset->indexFixed[idx] < 1) ||
          (workingset->indexFixed[idx] > 8)) {
        emlrtDynamicBoundsCheckR2012b(workingset->indexFixed[idx], 1, 8,
                                      &ic_emlrtBCI, &st);
      }
      solution->xstar[workingset->indexFixed[idx] - 1] =
          workingset->ub[workingset->indexFixed[idx] - 1];
    }
    b_st.site = &yg_emlrtRSI;
    if (workingset->sizes[3] > 2147483646) {
      c_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)workingset->sizes[3];
    for (idx = 0; idx < i; idx++) {
      i1 = workingset->isActiveIdx[3] + idx;
      if ((i1 < 1) || (i1 > 15)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 15, &jc_emlrtBCI, &st);
      }
      if (workingset->isActiveConstr[i1 - 1]) {
        if (idx + 1 > 8) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 8, &hc_emlrtBCI, &st);
        }
        if ((workingset->indexLB[idx] < 1) || (workingset->indexLB[idx] > 8)) {
          emlrtDynamicBoundsCheckR2012b(workingset->indexLB[idx], 1, 8,
                                        &ic_emlrtBCI, &st);
        }
        solution->xstar[workingset->indexLB[idx] - 1] =
            -workingset->lb[workingset->indexLB[idx] - 1];
      }
    }
    b_st.site = &yg_emlrtRSI;
    if (workingset->sizes[4] > 2147483646) {
      c_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)workingset->sizes[4];
    for (idx = 0; idx < i; idx++) {
      i1 = workingset->isActiveIdx[4] + idx;
      if ((i1 < 1) || (i1 > 15)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 15, &jc_emlrtBCI, &st);
      }
      if (workingset->isActiveConstr[i1 - 1]) {
        if ((workingset->indexUB[idx] < 1) || (workingset->indexUB[idx] > 8)) {
          emlrtDynamicBoundsCheckR2012b(workingset->indexUB[idx], 1, 8,
                                        &ic_emlrtBCI, &st);
        }
        solution->xstar[workingset->indexUB[idx] - 1] =
            workingset->ub[workingset->indexUB[idx] - 1];
      }
    }
    st.site = &xg_emlrtRSI;
    PresolveWorkingSet(&st, solution, memspace, workingset, qrmanager);
    if (solution->state >= 0) {
      guard1 = true;
    }
  } else {
    solution->state = 82;
    guard1 = true;
  }
  if (guard1) {
    solution->iterations = 0;
    st.site = &xg_emlrtRSI;
    solution->maxConstr =
        c_maxConstraintViolation(&st, workingset, solution->xstar);
    if (solution->maxConstr > 1.0E-6) {
      st.site = &xg_emlrtRSI;
      phaseone(&st, H, f, solution, memspace, workingset, qrmanager,
               cholmanager, objective, options->SolverName, runTimeOptions);
      if (solution->state != 0) {
        st.site = &xg_emlrtRSI;
        solution->maxConstr =
            c_maxConstraintViolation(&st, workingset, solution->xstar);
        if (solution->maxConstr > 1.0E-6) {
          st.site = &xg_emlrtRSI;
          b_xcopy(&st, 15, solution->lambda);
          st.site = &xg_emlrtRSI;
          solution->fstar = computeFval(
              &st, objective, memspace->workspace_float, H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            real_T maxConstr_new;
            st.site = &xg_emlrtRSI;
            e_xcopy(&st, nVar, solution->xstar, solution->searchDir);
            st.site = &xg_emlrtRSI;
            PresolveWorkingSet(&st, solution, memspace, workingset, qrmanager);
            st.site = &xg_emlrtRSI;
            maxConstr_new =
                c_maxConstraintViolation(&st, workingset, solution->xstar);
            if (maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = maxConstr_new;
              st.site = &xg_emlrtRSI;
              e_xcopy(&st, nVar, solution->searchDir, solution->xstar);
            }
          }
          st.site = &xg_emlrtRSI;
          iterate(&st, H, f, solution, memspace, workingset, qrmanager,
                  cholmanager, objective, options->SolverName,
                  runTimeOptions->MaxIterations);
        }
      }
    } else {
      st.site = &xg_emlrtRSI;
      iterate(&st, H, f, solution, memspace, workingset, qrmanager, cholmanager,
              objective, options->SolverName, runTimeOptions->MaxIterations);
    }
  }
}

/* End of code generation (driver.c) */
