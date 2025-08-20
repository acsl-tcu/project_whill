/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkStoppingAndUpdateFval.c
 *
 * Code generation for function 'checkStoppingAndUpdateFval'
 *
 */

/* Include files */
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kh_emlrtRSI = {
    1,                            /* lineNo */
    "checkStoppingAndUpdateFval", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkStoppingAndUpdateFval.p" /* pathName */
};

static emlrtBCInfo ud_emlrtBCI = {
    1,                            /* iFirst */
    7,                            /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "checkStoppingAndUpdateFval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "stopping\\checkStoppingAndUpdateFval.p", /* pName */
    0                                         /* checkKind */
};

/* Function Definitions */
void checkStoppingAndUpdateFval(const emlrtStack *sp,
                                int32_T *activeSetChangeID, const real_T f[7],
                                h_struct_T *solution, d_struct_T *memspace,
                                const struct_T *objective,
                                i_struct_T *workingset, e_struct_T *qrmanager,
                                real_T options_ObjectiveLimit,
                                int32_T runTimeOptions_MaxIterations,
                                boolean_T updateFval)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  solution->iterations++;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }
  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    real_T tempMaxConstr;
    st.site = &kh_emlrtRSI;
    solution->maxConstr =
        c_maxConstraintViolation(&st, workingset, solution->xstar);
    tempMaxConstr = solution->maxConstr;
    if (objective->objtype == 5) {
      if ((objective->nvar < 1) || (objective->nvar > 7)) {
        emlrtDynamicBoundsCheckR2012b(objective->nvar, 1, 7, &ud_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      tempMaxConstr =
          solution->maxConstr - solution->xstar[objective->nvar - 1];
    }
    if (tempMaxConstr > 1.0E-6) {
      boolean_T nonDegenerateWset;
      st.site = &kh_emlrtRSI;
      d_xcopy(&st, objective->nvar, solution->xstar, solution->searchDir);
      st.site = &kh_emlrtRSI;
      nonDegenerateWset =
          feasibleX0ForWorkingSet(&st, memspace->workspace_double,
                                  solution->searchDir, workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }
      *activeSetChangeID = 0;
      st.site = &kh_emlrtRSI;
      tempMaxConstr =
          c_maxConstraintViolation(&st, workingset, solution->searchDir);
      if (tempMaxConstr < solution->maxConstr) {
        int32_T i;
        st.site = &kh_emlrtRSI;
        if (objective->nvar > 2147483646) {
          b_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        i = (uint8_T)objective->nvar;
        if (i - 1 >= 0) {
          memcpy(&solution->xstar[0], &solution->searchDir[0],
                 (uint32_T)i * sizeof(real_T));
        }
        solution->maxConstr = tempMaxConstr;
      }
    }
  }
  if (updateFval && (options_ObjectiveLimit > rtMinusInf)) {
    st.site = &kh_emlrtRSI;
    solution->fstar = computeFval_ReuseHx(
        &st, objective, memspace->workspace_double, f, solution->xstar);
    if ((solution->fstar < options_ObjectiveLimit) &&
        ((solution->state != 0) || (objective->objtype != 5))) {
      solution->state = 2;
    }
  }
}

/* End of code generation (checkStoppingAndUpdateFval.c) */
