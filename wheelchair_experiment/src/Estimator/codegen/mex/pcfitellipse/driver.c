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
#include "computeFval.h"
#include "eml_int_forloop_overflow_check.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "moveConstraint_.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo se_emlrtRSI = {
    1,        /* lineNo */
    "driver", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\driver.p" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    1,             /* lineNo */
    "snap_bounds", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_"
    "bounds.p" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    1,          /* lineNo */
    "phaseone", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\phaseone.p" /* pathName */
};

static emlrtBCInfo kb_emlrtBCI = {
    1,             /* iFirst */
    8,             /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "snap_bounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_"
    "bounds.p", /* pName */
    0           /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    1,          /* iFirst */
    8,          /* iLast */
    1,          /* lineNo */
    1,          /* colNo */
    "",         /* aName */
    "phaseone", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\phaseone.p", /* pName */
    3                          /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    1,             /* iFirst */
    8,             /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "snap_bounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_"
    "bounds.p", /* pName */
    3           /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    1,             /* iFirst */
    15,            /* iLast */
    1,             /* lineNo */
    1,             /* colNo */
    "",            /* aName */
    "snap_bounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_"
    "bounds.p", /* pName */
    0           /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    1,          /* iFirst */
    15,         /* iLast */
    1,          /* lineNo */
    1,          /* colNo */
    "",         /* aName */
    "phaseone", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\phaseone.p", /* pName */
    0                          /* checkKind */
};

/* Function Definitions */
void driver(const emlrtStack *sp, const real_T H[25], const real_T f[8],
            j_struct_T *solution, f_struct_T *memspace, k_struct_T *workingset,
            g_struct_T *qrmanager, h_struct_T *cholmanager,
            b_struct_T *objective, m_struct_T *options,
            int32_T runTimeOptions_MaxIterations)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T TYPE;
  int32_T i;
  int32_T mEqFixed;
  int32_T nVar_tmp;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  solution->iterations = 0;
  nVar_tmp = workingset->nVar;
  guard1 = false;
  if (workingset->probType == 3) {
    st.site = &se_emlrtRSI;
    b_st.site = &te_emlrtRSI;
    if (workingset->sizes[0] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)workingset->sizes[0];
    for (mEqFixed = 0; mEqFixed < i; mEqFixed++) {
      if ((workingset->indexFixed[mEqFixed] < 1) ||
          (workingset->indexFixed[mEqFixed] > 8)) {
        emlrtDynamicBoundsCheckR2012b(workingset->indexFixed[mEqFixed], 1, 8,
                                      &ob_emlrtBCI, &st);
      }
      solution->xstar[workingset->indexFixed[mEqFixed] - 1] =
          workingset->ub[workingset->indexFixed[mEqFixed] - 1];
    }
    b_st.site = &te_emlrtRSI;
    if (workingset->sizes[3] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)workingset->sizes[3];
    for (mEqFixed = 0; mEqFixed < i; mEqFixed++) {
      TYPE = workingset->isActiveIdx[3] + mEqFixed;
      if ((TYPE < 1) || (TYPE > 15)) {
        emlrtDynamicBoundsCheckR2012b(TYPE, 1, 15, &pb_emlrtBCI, &st);
      }
      if (workingset->isActiveConstr[TYPE - 1]) {
        if (mEqFixed + 1 > 8) {
          emlrtDynamicBoundsCheckR2012b(mEqFixed + 1, 1, 8, &kb_emlrtBCI, &st);
        }
        if ((workingset->indexLB[mEqFixed] < 1) ||
            (workingset->indexLB[mEqFixed] > 8)) {
          emlrtDynamicBoundsCheckR2012b(workingset->indexLB[mEqFixed], 1, 8,
                                        &ob_emlrtBCI, &st);
        }
        solution->xstar[workingset->indexLB[mEqFixed] - 1] =
            -workingset->lb[workingset->indexLB[mEqFixed] - 1];
      }
    }
    b_st.site = &te_emlrtRSI;
    if (workingset->sizes[4] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)workingset->sizes[4];
    for (mEqFixed = 0; mEqFixed < i; mEqFixed++) {
      TYPE = workingset->isActiveIdx[4] + mEqFixed;
      if ((TYPE < 1) || (TYPE > 15)) {
        emlrtDynamicBoundsCheckR2012b(TYPE, 1, 15, &pb_emlrtBCI, &st);
      }
      if (workingset->isActiveConstr[TYPE - 1]) {
        if ((workingset->indexUB[mEqFixed] < 1) ||
            (workingset->indexUB[mEqFixed] > 8)) {
          emlrtDynamicBoundsCheckR2012b(workingset->indexUB[mEqFixed], 1, 8,
                                        &ob_emlrtBCI, &st);
        }
        solution->xstar[workingset->indexUB[mEqFixed] - 1] =
            workingset->ub[workingset->indexUB[mEqFixed] - 1];
      }
    }
    st.site = &se_emlrtRSI;
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
    st.site = &se_emlrtRSI;
    solution->maxConstr =
        c_maxConstraintViolation(&st, workingset, solution->xstar);
    if (solution->maxConstr > 1.0E-6) {
      int32_T PROBTYPE_ORIG;
      st.site = &se_emlrtRSI;
      PROBTYPE_ORIG = workingset->probType;
      i = workingset->nVar + 1;
      if ((i < 1) || (i > 8)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 8, &lb_emlrtBCI, &st);
      }
      solution->xstar[i - 1] = solution->maxConstr + 1.0;
      if (workingset->probType == 3) {
        i = 1;
      } else {
        i = 4;
      }
      b_st.site = &yf_emlrtRSI;
      setProblemType(&b_st, workingset, i);
      b_st.site = &yf_emlrtRSI;
      removeAllIneqConstr(&b_st, workingset);
      objective->prev_objtype = objective->objtype;
      objective->prev_nvar = objective->nvar;
      objective->prev_hasLinear = objective->hasLinear;
      objective->objtype = 5;
      objective->nvar = nVar_tmp + 1;
      objective->gammaScalar = 1.0;
      objective->hasLinear = true;
      b_st.site = &yf_emlrtRSI;
      solution->fstar = computeFval(
          &b_st, objective, memspace->workspace_double, H, f, solution->xstar);
      solution->state = 5;
      b_st.site = &yf_emlrtRSI;
      iterate(&b_st, H, f, solution, memspace, workingset, qrmanager,
              cholmanager, objective, options->SolverName,
              1.4901161193847657E-10, 1.0E-6, runTimeOptions_MaxIterations);
      b_st.site = &yf_emlrtRSI;
      i = workingset->isActiveIdx[3] + workingset->sizes[3];
      if ((i - 1 < 1) || (i - 1 > 15)) {
        emlrtDynamicBoundsCheckR2012b(i - 1, 1, 15, &mb_emlrtBCI, &b_st);
      }
      if (workingset->isActiveConstr[i - 2]) {
        boolean_T exitg1;
        b_st.site = &yf_emlrtRSI;
        if ((workingset->sizes[0] + 1 <= workingset->nActiveConstr) &&
            (workingset->nActiveConstr > 2147483646)) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        mEqFixed = workingset->sizes[0];
        exitg1 = false;
        while ((!exitg1) && (mEqFixed + 1 <= workingset->nActiveConstr)) {
          if ((mEqFixed + 1 < 1) || (mEqFixed + 1 > 15)) {
            emlrtDynamicBoundsCheckR2012b(mEqFixed + 1, 1, 15, &sb_emlrtBCI,
                                          &st);
          }
          if ((workingset->Wid[mEqFixed] == 4) &&
              (workingset->Wlocalidx[mEqFixed] == workingset->sizes[3])) {
            b_st.site = &yf_emlrtRSI;
            TYPE = workingset->Wid[mEqFixed];
            if ((workingset->Wid[mEqFixed] < 1) ||
                (workingset->Wid[mEqFixed] > 6)) {
              emlrtDynamicBoundsCheckR2012b(workingset->Wid[mEqFixed], 1, 6,
                                            &nb_emlrtBCI, &b_st);
            }
            i = (workingset->isActiveIdx[workingset->Wid[mEqFixed] - 1] +
                 workingset->Wlocalidx[mEqFixed]) -
                1;
            if ((i < 1) || (i > 15)) {
              emlrtDynamicBoundsCheckR2012b(i, 1, 15, &rb_emlrtBCI, &b_st);
            }
            workingset->isActiveConstr[i - 1] = false;
            if (mEqFixed + 1 < workingset->nActiveConstr) {
              c_st.site = &ef_emlrtRSI;
              moveConstraint_(&c_st, workingset, workingset->nActiveConstr,
                              mEqFixed + 1);
            }
            workingset->nActiveConstr--;
            if ((TYPE < 1) || (TYPE > 5)) {
              emlrtDynamicBoundsCheckR2012b(TYPE, 1, 5, &tb_emlrtBCI, &b_st);
            }
            workingset->nWConstr[TYPE - 1]--;
            exitg1 = true;
          } else {
            mEqFixed++;
          }
        }
      }
      TYPE = workingset->nActiveConstr;
      mEqFixed = workingset->sizes[0];
      while ((TYPE > mEqFixed) && (TYPE > nVar_tmp)) {
        int32_T TYPE_tmp;
        b_st.site = &yf_emlrtRSI;
        if ((TYPE < 1) || (TYPE > 15)) {
          emlrtDynamicBoundsCheckR2012b(TYPE, 1, 15, &qb_emlrtBCI, &b_st);
        }
        TYPE_tmp = workingset->Wid[TYPE - 1];
        if ((TYPE_tmp < 1) || (TYPE_tmp > 6)) {
          emlrtDynamicBoundsCheckR2012b(workingset->Wid[TYPE - 1], 1, 6,
                                        &nb_emlrtBCI, &b_st);
        }
        i = (workingset->isActiveIdx[TYPE_tmp - 1] +
             workingset->Wlocalidx[TYPE - 1]) -
            1;
        if ((i < 1) || (i > 15)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 15, &rb_emlrtBCI, &b_st);
        }
        workingset->isActiveConstr[i - 1] = false;
        if (TYPE < workingset->nActiveConstr) {
          c_st.site = &ef_emlrtRSI;
          moveConstraint_(&c_st, workingset, workingset->nActiveConstr, TYPE);
        }
        workingset->nActiveConstr--;
        if (TYPE_tmp > 5) {
          emlrtDynamicBoundsCheckR2012b(6, 1, 5, &tb_emlrtBCI, &b_st);
        }
        workingset->nWConstr[TYPE_tmp - 1]--;
        TYPE--;
      }
      solution->maxConstr = solution->xstar[nVar_tmp];
      b_st.site = &yf_emlrtRSI;
      setProblemType(&b_st, workingset, PROBTYPE_ORIG);
      objective->objtype = objective->prev_objtype;
      objective->nvar = objective->prev_nvar;
      objective->hasLinear = objective->prev_hasLinear;
      options->ObjectiveLimit = rtMinusInf;
      options->StepTolerance = 1.0E-6;
      if (solution->state != 0) {
        st.site = &se_emlrtRSI;
        solution->maxConstr =
            c_maxConstraintViolation(&st, workingset, solution->xstar);
        if (solution->maxConstr > 1.0E-6) {
          st.site = &se_emlrtRSI;
          g_xcopy(&st, 15, solution->lambda);
          st.site = &se_emlrtRSI;
          solution->fstar =
              computeFval(&st, objective, memspace->workspace_double, H, f,
                          solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            real_T maxConstr_new;
            st.site = &se_emlrtRSI;
            d_xcopy(&st, nVar_tmp, solution->xstar, solution->searchDir);
            st.site = &se_emlrtRSI;
            PresolveWorkingSet(&st, solution, memspace, workingset, qrmanager);
            st.site = &se_emlrtRSI;
            maxConstr_new =
                c_maxConstraintViolation(&st, workingset, solution->xstar);
            if (maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = maxConstr_new;
              st.site = &se_emlrtRSI;
              d_xcopy(&st, nVar_tmp, solution->searchDir, solution->xstar);
            }
          }
          st.site = &se_emlrtRSI;
          iterate(&st, H, f, solution, memspace, workingset, qrmanager,
                  cholmanager, objective, options->SolverName,
                  options->StepTolerance, options->ObjectiveLimit,
                  runTimeOptions_MaxIterations);
        }
      }
    } else {
      st.site = &se_emlrtRSI;
      iterate(&st, H, f, solution, memspace, workingset, qrmanager, cholmanager,
              objective, options->SolverName, options->StepTolerance,
              options->ObjectiveLimit, runTimeOptions_MaxIterations);
    }
  }
}

/* End of code generation (driver.c) */
