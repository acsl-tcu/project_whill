/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PresolveWorkingSet.c
 *
 * Code generation for function 'PresolveWorkingSet'
 *
 */

/* Include files */
#include "PresolveWorkingSet.h"
#include "RemoveDependentIneq_.h"
#include "computeQ_.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "moveConstraint_.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo me_emlrtRSI = {
    1,                    /* lineNo */
    "PresolveWorkingSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\PresolveWorkingSet.p" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI = {
    1,                    /* lineNo */
    "RemoveDependentEq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentEq_.p" /* pathName */
};

static emlrtRSInfo oe_emlrtRSI = {
    1,                        /* lineNo */
    "ComputeNumDependentEq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\ComputeNumDependentEq_.p" /* pathName */
};

static emlrtRSInfo se_emlrtRSI = {
    1,                     /* lineNo */
    "IndexOfDependentEq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\IndexOfDependentEq_.p" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    1,                /* lineNo */
    "removeEqConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p" /* pathName */
};

static emlrtBCInfo nb_emlrtBCI = {
    1,                    /* iFirst */
    13,                   /* iLast */
    1,                    /* lineNo */
    1,                    /* colNo */
    "",                   /* aName */
    "RemoveDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentEq_.p", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    1,                     /* iFirst */
    13,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "IndexOfDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\IndexOfDependentEq_.p", /* pName */
    3                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    1,                /* iFirst */
    6,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    1,                    /* iFirst */
    91,                   /* iLast */
    1,                    /* lineNo */
    1,                    /* colNo */
    "",                   /* aName */
    "RemoveDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentEq_.p", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    1,                    /* iFirst */
    169,                  /* iLast */
    1,                    /* lineNo */
    1,                    /* colNo */
    "",                   /* aName */
    "RemoveDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentEq_.p", /* pName */
    3                                   /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    1,                     /* iFirst */
    13,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "IndexOfDependentEq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\IndexOfDependentEq_.p", /* pName */
    0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    1,                /* iFirst */
    13,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    1,                /* iFirst */
    0,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    3                               /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    1,                /* iFirst */
    13,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    3                               /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    1,                /* iFirst */
    5,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeEqConstr.p", /* pName */
    3                               /* checkKind */
};

/* Function Definitions */
void PresolveWorkingSet(const emlrtStack *sp, h_struct_T *solution,
                        d_struct_T *memspace, i_struct_T *workingset,
                        e_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T tol;
  int32_T idxDiag;
  int32_T idx_col;
  int32_T k;
  int32_T mTotalWorkingEq_tmp_tmp;
  int32_T mWorkingFixed;
  int32_T nDepInd;
  int32_T nVar;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  solution->state = 82;
  st.site = &me_emlrtRSI;
  nVar = workingset->nVar;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp_tmp > 0) {
    int32_T i;
    int32_T totalRank_tmp;
    b_st.site = &ne_emlrtRSI;
    if (mTotalWorkingEq_tmp_tmp > 2147483646) {
      c_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    overflow = (nVar > 2147483646);
    i = (uint8_T)nVar;
    for (idxDiag = 0; idxDiag < mTotalWorkingEq_tmp_tmp; idxDiag++) {
      b_st.site = &ne_emlrtRSI;
      if (overflow) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx_col = 0; idx_col < i; idx_col++) {
        totalRank_tmp = (idx_col + 7 * idxDiag) + 1;
        if ((totalRank_tmp < 1) || (totalRank_tmp > 91)) {
          emlrtDynamicBoundsCheckR2012b(totalRank_tmp, 1, 91, &qb_emlrtBCI,
                                        &st);
        }
        k = (idxDiag + 13 * idx_col) + 1;
        if ((k < 1) || (k > 169)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, 169, &rb_emlrtBCI, &st);
        }
        qrmanager->QR[k - 1] = workingset->ATwset[totalRank_tmp - 1];
      }
    }
    b_st.site = &ne_emlrtRSI;
    idxDiag = mTotalWorkingEq_tmp_tmp - workingset->nVar;
    nDepInd = muIntScalarMax_sint32(0, idxDiag);
    c_st.site = &oe_emlrtRSI;
    if (workingset->nVar > 2147483646) {
      d_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    i = (uint8_T)workingset->nVar;
    memset(&qrmanager->jpvt[0], 0, (uint32_T)i * sizeof(int32_T));
    c_st.site = &oe_emlrtRSI;
    i = mTotalWorkingEq_tmp_tmp * workingset->nVar;
    if (i == 0) {
      qrmanager->mrows = mTotalWorkingEq_tmp_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = mTotalWorkingEq_tmp_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol =
          muIntScalarMin_sint32(mTotalWorkingEq_tmp_tmp, workingset->nVar);
      d_st.site = &gd_emlrtRSI;
      xgeqp3(&d_st, qrmanager->QR, mTotalWorkingEq_tmp_tmp, workingset->nVar,
             qrmanager->jpvt, qrmanager->tau);
    }
    tol = 100.0 * (real_T)workingset->nVar * 2.2204460492503131E-16;
    totalRank_tmp =
        muIntScalarMin_sint32(workingset->nVar, mTotalWorkingEq_tmp_tmp);
    idxDiag = totalRank_tmp + 13 * (totalRank_tmp - 1);
    while ((idxDiag > 0) &&
           (muDoubleScalarAbs(qrmanager->QR[idxDiag - 1]) < tol)) {
      idxDiag -= 14;
      nDepInd++;
    }
    if (nDepInd > 0) {
      boolean_T exitg1;
      c_st.site = &oe_emlrtRSI;
      d_st.site = &ae_emlrtRSI;
      computeQ_(&d_st, qrmanager, qrmanager->mrows);
      c_st.site = &oe_emlrtRSI;
      if (nDepInd > 2147483646) {
        d_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      idx_col = 0;
      exitg1 = false;
      while ((!exitg1) && (idx_col <= nDepInd - 1)) {
        real_T qtb;
        idxDiag = 13 * ((mTotalWorkingEq_tmp_tmp - idx_col) - 1);
        c_st.site = &oe_emlrtRSI;
        qtb = 0.0;
        for (k = 0; k < mTotalWorkingEq_tmp_tmp; k++) {
          qtb += qrmanager->Q[idxDiag + k] * workingset->bwset[k];
        }
        if (muDoubleScalarAbs(qtb) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          idx_col++;
        }
      }
    }
    if (nDepInd > 0) {
      b_st.site = &ne_emlrtRSI;
      for (idx_col = 0; idx_col < mTotalWorkingEq_tmp_tmp; idx_col++) {
        b_st.site = &ne_emlrtRSI;
        b_xcopy(&b_st, nVar, workingset->ATwset, 7 * idx_col + 1, qrmanager->QR,
                13 * idx_col + 1);
      }
      b_st.site = &ne_emlrtRSI;
      c_st.site = &se_emlrtRSI;
      if (workingset->nWConstr[0] > 2147483646) {
        d_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (idx_col = 0; idx_col < mWorkingFixed; idx_col++) {
        if ((idx_col + 1 < 1) || (idx_col + 1 > 13)) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 13, &ob_emlrtBCI,
                                        &b_st);
        }
        qrmanager->jpvt[idx_col] = 1;
      }
      idxDiag = workingset->nWConstr[0] + 1;
      c_st.site = &se_emlrtRSI;
      for (idx_col = idxDiag; idx_col <= mTotalWorkingEq_tmp_tmp; idx_col++) {
        if ((idx_col < 1) || (idx_col > 13)) {
          emlrtDynamicBoundsCheckR2012b(idx_col, 1, 13, &ob_emlrtBCI, &b_st);
        }
        qrmanager->jpvt[idx_col - 1] = 0;
      }
      c_st.site = &se_emlrtRSI;
      if (i == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp_tmp;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp_tmp;
        qrmanager->minRowCol = totalRank_tmp;
        d_st.site = &gd_emlrtRSI;
        xgeqp3(&d_st, qrmanager->QR, workingset->nVar, mTotalWorkingEq_tmp_tmp,
               qrmanager->jpvt, qrmanager->tau);
      }
      c_st.site = &se_emlrtRSI;
      for (idx_col = 0; idx_col < nDepInd; idx_col++) {
        i = ((mTotalWorkingEq_tmp_tmp - nDepInd) + idx_col) + 1;
        if ((i < 1) || (i > 13)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 13, &sb_emlrtBCI, &b_st);
        }
        if (idx_col + 1 > 13) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 13, &ob_emlrtBCI,
                                        &b_st);
        }
        memspace->workspace_int[idx_col] = qrmanager->jpvt[i - 1];
      }
      b_st.site = &ne_emlrtRSI;
      countsort(&b_st, memspace->workspace_int, nDepInd,
                memspace->workspace_sort, 1, mTotalWorkingEq_tmp_tmp);
      for (idx_col = nDepInd; idx_col >= 1; idx_col--) {
        b_st.site = &ne_emlrtRSI;
        if (idx_col > 13) {
          emlrtDynamicBoundsCheckR2012b(idx_col, 1, 13, &nb_emlrtBCI, &b_st);
        }
        i = workingset->nWConstr[0] + workingset->nWConstr[1];
        if (i != 0) {
          totalRank_tmp = memspace->workspace_int[idx_col - 1];
          if (totalRank_tmp <= i) {
            if ((workingset->nActiveConstr == i) || (totalRank_tmp == i)) {
              workingset->mEqRemoved++;
              if ((totalRank_tmp < 1) || (totalRank_tmp > 13)) {
                emlrtDynamicBoundsCheckR2012b(totalRank_tmp, 1, 13,
                                              &tb_emlrtBCI, &b_st);
              }
              if ((workingset->mEqRemoved < 1) ||
                  (workingset->mEqRemoved > 0)) {
                emlrtDynamicBoundsCheckR2012b(workingset->mEqRemoved, 1, 0,
                                              &ub_emlrtBCI, &b_st);
              }
              c_st.site = &ue_emlrtRSI;
              idxDiag = workingset->Wid[totalRank_tmp - 1];
              if ((idxDiag < 1) || (idxDiag > 6)) {
                emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 6, &gb_emlrtBCI,
                                              &c_st);
              }
              i = (workingset
                       ->isActiveIdx[workingset->Wid[totalRank_tmp - 1] - 1] +
                   workingset->Wlocalidx[totalRank_tmp - 1]) -
                  1;
              if ((i < 1) || (i > 13)) {
                emlrtDynamicBoundsCheckR2012b(i, 1, 13, &kb_emlrtBCI, &c_st);
              }
              workingset->isActiveConstr[i - 1] = false;
              d_st.site = &ve_emlrtRSI;
              moveConstraint_(&d_st, workingset, workingset->nActiveConstr,
                              totalRank_tmp);
              workingset->nActiveConstr--;
              if ((idxDiag < 1) || (idxDiag > 5)) {
                emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 5, &mb_emlrtBCI,
                                              &c_st);
              }
              workingset->nWConstr[idxDiag - 1]--;
            } else {
              workingset->mEqRemoved++;
              if ((totalRank_tmp < 1) || (totalRank_tmp > 13)) {
                emlrtDynamicBoundsCheckR2012b(totalRank_tmp, 1, 13,
                                              &tb_emlrtBCI, &b_st);
              }
              idxDiag = workingset->Wid[totalRank_tmp - 1];
              if ((workingset->mEqRemoved < 1) ||
                  (workingset->mEqRemoved > 0)) {
                emlrtDynamicBoundsCheckR2012b(workingset->mEqRemoved, 1, 0,
                                              &ub_emlrtBCI, &b_st);
              }
              if ((idxDiag < 1) || (idxDiag > 6)) {
                emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 6, &pb_emlrtBCI,
                                              &b_st);
              }
              k = (workingset->isActiveIdx[idxDiag - 1] +
                   workingset->Wlocalidx[totalRank_tmp - 1]) -
                  1;
              if ((k < 1) || (k > 13)) {
                emlrtDynamicBoundsCheckR2012b(k, 1, 13, &vb_emlrtBCI, &b_st);
              }
              workingset->isActiveConstr[k - 1] = false;
              c_st.site = &ue_emlrtRSI;
              moveConstraint_(&c_st, workingset, i, totalRank_tmp);
              c_st.site = &ue_emlrtRSI;
              moveConstraint_(&c_st, workingset, workingset->nActiveConstr, i);
              workingset->nActiveConstr--;
              if ((idxDiag < 1) || (idxDiag > 5)) {
                emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 5, &wb_emlrtBCI,
                                              &b_st);
              }
              workingset->nWConstr[idxDiag - 1]--;
            }
          }
        }
      }
    }
  }
  if ((nDepInd != -1) && (workingset->nActiveConstr <= 13)) {
    boolean_T guard1 = false;
    st.site = &me_emlrtRSI;
    RemoveDependentIneq_(&st, workingset, qrmanager, memspace, 100.0);
    st.site = &me_emlrtRSI;
    overflow = feasibleX0ForWorkingSet(&st, memspace->workspace_double,
                                       solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!overflow) {
      st.site = &me_emlrtRSI;
      RemoveDependentIneq_(&st, workingset, qrmanager, memspace, 1000.0);
      st.site = &me_emlrtRSI;
      overflow =
          feasibleX0ForWorkingSet(&st, memspace->workspace_double,
                                  solution->xstar, workingset, qrmanager);
      if (!overflow) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 && (workingset->nWConstr[0] + workingset->nWConstr[1] ==
                   workingset->nVar)) {
      st.site = &me_emlrtRSI;
      tol = c_maxConstraintViolation(&st, workingset, solution->xstar);
      if (tol > 1.0E-6) {
        solution->state = -2;
      }
    }
  } else {
    solution->state = -3;
    st.site = &me_emlrtRSI;
    removeAllIneqConstr(&st, workingset);
  }
}

/* End of code generation (PresolveWorkingSet.c) */
