/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RemoveDependentEq_.c
 *
 * Code generation for function 'RemoveDependentEq_'
 *
 */

/* Include files */
#include "RemoveDependentEq_.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo bh_emlrtRSI = {
    1,                    /* lineNo */
    "RemoveDependentEq_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentEq_.p" /* pathName */
};

static emlrtRSInfo ch_emlrtRSI = {
    1,                        /* lineNo */
    "ComputeNumDependentEq_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/ComputeNumDependentEq_.p" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    1,                     /* lineNo */
    "IndexOfDependentEq_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/IndexOfDependentEq_.p" /* pathName */
};

static emlrtBCInfo nc_emlrtBCI = {
    1,                    /* iFirst */
    15,                   /* iLast */
    1,                    /* lineNo */
    1,                    /* colNo */
    "",                   /* aName */
    "RemoveDependentEq_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentEq_.p", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    1,                     /* iFirst */
    15,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "IndexOfDependentEq_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/IndexOfDependentEq_.p", /* pName */
    3                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    1,                /* iFirst */
    15,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeEqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    1,                /* iFirst */
    0,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "removeEqConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeEqConstr.p", /* pName */
    3                               /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    1,                    /* iFirst */
    120,                  /* iLast */
    1,                    /* lineNo */
    1,                    /* colNo */
    "",                   /* aName */
    "RemoveDependentEq_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentEq_.p", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = {
    1,                    /* iFirst */
    225,                  /* iLast */
    1,                    /* lineNo */
    1,                    /* colNo */
    "",                   /* aName */
    "RemoveDependentEq_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentEq_.p", /* pName */
    3                                   /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    1,                     /* iFirst */
    15,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "IndexOfDependentEq_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/IndexOfDependentEq_.p", /* pName */
    0                                    /* checkKind */
};

/* Function Definitions */
int32_T RemoveDependentEq_(const emlrtStack *sp, c_struct_T *memspace,
                           g_struct_T *workingset, j_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx_col;
  int32_T idx_row;
  int32_T mTotalWorkingEq_tmp;
  int32_T mWorkingFixed;
  int32_T nDepInd;
  int32_T nVar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nVar = workingset->nVar;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp > 0) {
    real_T tol;
    int32_T i;
    int32_T idxDiag;
    int32_T idxEnd;
    boolean_T overflow;
    st.site = &bh_emlrtRSI;
    if (mTotalWorkingEq_tmp > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    overflow = (nVar > 2147483646);
    i = (uint8_T)nVar;
    for (idx_row = 0; idx_row < mTotalWorkingEq_tmp; idx_row++) {
      st.site = &bh_emlrtRSI;
      if (overflow) {
        b_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (idx_col = 0; idx_col < i; idx_col++) {
        idxEnd = (idx_col + (idx_row << 3)) + 1;
        if ((idxEnd < 1) || (idxEnd > 120)) {
          emlrtDynamicBoundsCheckR2012b(idxEnd, 1, 120, &sc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        idxDiag = (idx_row + 15 * idx_col) + 1;
        if ((idxDiag < 1) || (idxDiag > 225)) {
          emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 225, &tc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        qrmanager->QR[idxDiag - 1] = workingset->ATwset[idxEnd - 1];
      }
    }
    st.site = &bh_emlrtRSI;
    idxDiag = mTotalWorkingEq_tmp - workingset->nVar;
    nDepInd = muIntScalarMax_sint32(0, idxDiag);
    b_st.site = &ch_emlrtRSI;
    if (workingset->nVar > 2147483646) {
      c_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)workingset->nVar;
    memset(&qrmanager->jpvt[0], 0, (uint32_T)i * sizeof(int32_T));
    b_st.site = &ch_emlrtRSI;
    i = mTotalWorkingEq_tmp * workingset->nVar;
    if (i == 0) {
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol =
          muIntScalarMin_sint32(mTotalWorkingEq_tmp, workingset->nVar);
      c_st.site = &uf_emlrtRSI;
      xgeqp3(&c_st, qrmanager->QR, mTotalWorkingEq_tmp, workingset->nVar,
             qrmanager->jpvt, qrmanager->tau);
    }
    tol = muDoubleScalarMin(1.4901161193847656E-8,
                            2.2204460492503131E-15 *
                                (real_T)muIntScalarMax_sint32(
                                    mTotalWorkingEq_tmp, workingset->nVar));
    idxEnd = muIntScalarMin_sint32(workingset->nVar, mTotalWorkingEq_tmp);
    idxDiag = idxEnd + 15 * (idxEnd - 1);
    while ((idxDiag > 0) && (muDoubleScalarAbs(qrmanager->QR[idxDiag - 1]) <
                             tol * muDoubleScalarAbs(qrmanager->QR[0]))) {
      idxDiag -= 16;
      nDepInd++;
    }
    if (nDepInd > 0) {
      boolean_T exitg1;
      b_st.site = &ch_emlrtRSI;
      c_st.site = &mg_emlrtRSI;
      computeQ_(&c_st, qrmanager, qrmanager->mrows);
      b_st.site = &ch_emlrtRSI;
      if (nDepInd > 2147483646) {
        c_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      idx_col = 0;
      exitg1 = false;
      while ((!exitg1) && (idx_col <= nDepInd - 1)) {
        real_T qtb;
        idxDiag = 15 * ((mTotalWorkingEq_tmp - idx_col) - 1);
        b_st.site = &ch_emlrtRSI;
        qtb = 0.0;
        for (idx_row = 0; idx_row < mTotalWorkingEq_tmp; idx_row++) {
          qtb += qrmanager->Q[idxDiag + idx_row] * workingset->bwset[idx_row];
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
      st.site = &bh_emlrtRSI;
      for (idx_col = 0; idx_col < mTotalWorkingEq_tmp; idx_col++) {
        st.site = &bh_emlrtRSI;
        c_xcopy(&st, nVar, workingset->ATwset, (idx_col << 3) + 1,
                qrmanager->QR, 15 * idx_col + 1);
      }
      st.site = &bh_emlrtRSI;
      b_st.site = &gh_emlrtRSI;
      if (workingset->nWConstr[0] > 2147483646) {
        c_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx_col = 0; idx_col < mWorkingFixed; idx_col++) {
        if ((idx_col + 1 < 1) || (idx_col + 1 > 15)) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 15, &oc_emlrtBCI, &st);
        }
        qrmanager->jpvt[idx_col] = 1;
      }
      idxDiag = workingset->nWConstr[0] + 1;
      b_st.site = &gh_emlrtRSI;
      for (idx_col = idxDiag; idx_col <= mTotalWorkingEq_tmp; idx_col++) {
        if ((idx_col < 1) || (idx_col > 15)) {
          emlrtDynamicBoundsCheckR2012b(idx_col, 1, 15, &oc_emlrtBCI, &st);
        }
        qrmanager->jpvt[idx_col - 1] = 0;
      }
      b_st.site = &gh_emlrtRSI;
      if (i == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol = idxEnd;
        c_st.site = &uf_emlrtRSI;
        xgeqp3(&c_st, qrmanager->QR, workingset->nVar, mTotalWorkingEq_tmp,
               qrmanager->jpvt, qrmanager->tau);
      }
      b_st.site = &gh_emlrtRSI;
      for (idx_col = 0; idx_col < nDepInd; idx_col++) {
        i = ((mTotalWorkingEq_tmp - nDepInd) + idx_col) + 1;
        if ((i < 1) || (i > 15)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 15, &uc_emlrtBCI, &st);
        }
        if (idx_col + 1 > 15) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 15, &oc_emlrtBCI, &st);
        }
        memspace->workspace_int[idx_col] = qrmanager->jpvt[i - 1];
      }
      st.site = &bh_emlrtRSI;
      if ((nDepInd > 1) && (mTotalWorkingEq_tmp > 1)) {
        b_st.site = &hh_emlrtRSI;
        for (idx_col = 0; idx_col < mTotalWorkingEq_tmp; idx_col++) {
          if (idx_col + 1 > 15) {
            emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 15, &pc_emlrtBCI,
                                          &st);
          }
          memspace->workspace_sort[idx_col] = 0;
        }
        b_st.site = &hh_emlrtRSI;
        for (idx_col = 0; idx_col < nDepInd; idx_col++) {
          if (idx_col + 1 > 15) {
            emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 15, &vc_emlrtBCI,
                                          &st);
          }
          i = memspace->workspace_int[idx_col];
          if ((i < 1) || (i > 15)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, 15, &vc_emlrtBCI, &st);
          }
          if (idx_col + 1 > 15) {
            emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 15, &vc_emlrtBCI,
                                          &st);
          }
          idxEnd = memspace->workspace_int[idx_col];
          if ((idxEnd < 1) || (idxEnd > 15)) {
            emlrtDynamicBoundsCheckR2012b(idxEnd, 1, 15, &pc_emlrtBCI, &st);
          }
          memspace->workspace_sort[idxEnd - 1] =
              memspace->workspace_sort[i - 1] + 1;
        }
        b_st.site = &hh_emlrtRSI;
        for (idx_col = 2; idx_col <= mTotalWorkingEq_tmp; idx_col++) {
          if (idx_col > 15) {
            emlrtDynamicBoundsCheckR2012b(idx_col, 1, 15, &pc_emlrtBCI, &st);
          }
          memspace->workspace_sort[idx_col - 1] +=
              memspace->workspace_sort[idx_col - 2];
        }
        idxDiag = 1;
        idxEnd = memspace->workspace_sort[0];
        b_st.site = &hh_emlrtRSI;
        for (nVar = 0; nVar <= mTotalWorkingEq_tmp - 2; nVar++) {
          b_st.site = &hh_emlrtRSI;
          if ((idxDiag <= idxEnd) && (idxEnd > 2147483646)) {
            c_st.site = &u_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (mWorkingFixed = idxDiag; mWorkingFixed <= idxEnd;
               mWorkingFixed++) {
            if ((mWorkingFixed < 1) || (mWorkingFixed > 15)) {
              emlrtDynamicBoundsCheckR2012b(mWorkingFixed, 1, 15, &pc_emlrtBCI,
                                            &st);
            }
            memspace->workspace_int[mWorkingFixed - 1] = nVar + 1;
          }
          if (nVar + 1 > 15) {
            emlrtDynamicBoundsCheckR2012b(nVar + 1, 1, 15, &vc_emlrtBCI, &st);
          }
          idxDiag = memspace->workspace_sort[nVar] + 1;
          if (nVar + 2 > 15) {
            emlrtDynamicBoundsCheckR2012b(nVar + 2, 1, 15, &vc_emlrtBCI, &st);
          }
          idxEnd = memspace->workspace_sort[nVar + 1];
        }
        b_st.site = &hh_emlrtRSI;
        if ((idxDiag <= idxEnd) && (idxEnd > 2147483646)) {
          c_st.site = &u_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idx_col = idxDiag; idx_col <= idxEnd; idx_col++) {
          if ((idx_col < 1) || (idx_col > 15)) {
            emlrtDynamicBoundsCheckR2012b(idx_col, 1, 15, &pc_emlrtBCI, &st);
          }
          memspace->workspace_int[idx_col - 1] = mTotalWorkingEq_tmp;
        }
      }
      for (idx_col = nDepInd; idx_col >= 1; idx_col--) {
        st.site = &bh_emlrtRSI;
        if (idx_col > 15) {
          emlrtDynamicBoundsCheckR2012b(idx_col, 1, 15, &nc_emlrtBCI, &st);
        }
        if (mTotalWorkingEq_tmp != 0) {
          i = memspace->workspace_int[idx_col - 1];
          if (i <= mTotalWorkingEq_tmp) {
            if ((workingset->nActiveConstr == mTotalWorkingEq_tmp) ||
                (i == mTotalWorkingEq_tmp)) {
              workingset->mEqRemoved++;
              if ((i < 1) || (i > 15)) {
                emlrtDynamicBoundsCheckR2012b(i, 1, 15, &qc_emlrtBCI, &st);
              }
              emlrtDynamicBoundsCheckR2012b(workingset->mEqRemoved, 1, 0,
                                            &rc_emlrtBCI, &st);
            } else {
              workingset->mEqRemoved++;
              if ((i < 1) || (i > 15)) {
                emlrtDynamicBoundsCheckR2012b(i, 1, 15, &qc_emlrtBCI, &st);
              }
              emlrtDynamicBoundsCheckR2012b(workingset->mEqRemoved, 1, 0,
                                            &rc_emlrtBCI, &st);
            }
          }
        }
      }
    }
  }
  return nDepInd;
}

/* End of code generation (RemoveDependentEq_.c) */
