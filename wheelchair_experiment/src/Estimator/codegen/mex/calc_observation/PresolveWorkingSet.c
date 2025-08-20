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
#include "RemoveDependentEq_.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "removeAllIneqConstr.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ah_emlrtRSI = {
    1,                    /* lineNo */
    "PresolveWorkingSet", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/PresolveWorkingSet.p" /* pathName */
};

static emlrtRSInfo kh_emlrtRSI = {
    1,                      /* lineNo */
    "RemoveDependentIneq_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentIneq_.p" /* pathName */
};

static emlrtBCInfo kc_emlrtBCI = {
    1,                      /* iFirst */
    15,                     /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentIneq_.p", /* pName */
    3                                     /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    1,                      /* iFirst */
    225,                    /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentIneq_.p", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    1,                      /* iFirst */
    15,                     /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentIneq_.p", /* pName */
    0                                     /* checkKind */
};

/* Function Definitions */
void PresolveWorkingSet(const emlrtStack *sp, f_struct_T *solution,
                        c_struct_T *memspace, g_struct_T *workingset,
                        j_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx;
  int32_T idxDiag;
  int32_T nFixedConstr_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  solution->state = 82;
  st.site = &ah_emlrtRSI;
  nFixedConstr_tmp = RemoveDependentEq_(&st, memspace, workingset, qrmanager);
  if ((nFixedConstr_tmp != -1) && (workingset->nActiveConstr <= 15)) {
    real_T maxDiag;
    real_T tol;
    int32_T nDepIneq;
    int32_T nVar_tmp;
    boolean_T exitg1;
    boolean_T guard1;
    boolean_T okWorkingSet;
    st.site = &ah_emlrtRSI;
    nDepIneq = workingset->nActiveConstr;
    nFixedConstr_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
    nVar_tmp = workingset->nVar;
    if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
            workingset->nWConstr[4] >
        0) {
      tol = muDoubleScalarMin(
          1.4901161193847656E-8,
          2.2204460492503131E-15 *
              (real_T)muIntScalarMax_sint32(workingset->nVar,
                                            workingset->nActiveConstr));
      b_st.site = &kh_emlrtRSI;
      if (nFixedConstr_tmp > 2147483646) {
        c_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx = 0; idx < nFixedConstr_tmp; idx++) {
        if ((idx + 1 < 1) || (idx + 1 > 15)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 15, &kc_emlrtBCI, &st);
        }
        qrmanager->jpvt[idx] = 1;
      }
      idxDiag = nFixedConstr_tmp + 1;
      b_st.site = &kh_emlrtRSI;
      if ((nFixedConstr_tmp + 1 <= workingset->nActiveConstr) &&
          (workingset->nActiveConstr > 2147483646)) {
        c_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx = idxDiag; idx <= nDepIneq; idx++) {
        if ((idx < 1) || (idx > 15)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &kc_emlrtBCI, &st);
        }
        qrmanager->jpvt[idx - 1] = 0;
      }
      b_st.site = &kh_emlrtRSI;
      if (workingset->nActiveConstr > 2147483646) {
        c_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idxDiag = 0; idxDiag < nDepIneq; idxDiag++) {
        b_st.site = &kh_emlrtRSI;
        c_xcopy(&b_st, nVar_tmp, workingset->ATwset, (idxDiag << 3) + 1,
                qrmanager->QR, 15 * idxDiag + 1);
      }
      b_st.site = &kh_emlrtRSI;
      if (workingset->nVar * workingset->nActiveConstr == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        qrmanager->minRowCol =
            muIntScalarMin_sint32(workingset->nVar, workingset->nActiveConstr);
        c_st.site = &uf_emlrtRSI;
        xgeqp3(&c_st, qrmanager->QR, workingset->nVar,
               workingset->nActiveConstr, qrmanager->jpvt, qrmanager->tau);
      }
      nDepIneq = 0;
      for (idx = workingset->nActiveConstr; idx > nVar_tmp; idx--) {
        nDepIneq++;
        if ((idx < 1) || (idx > 15)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &mc_emlrtBCI, &st);
        }
        if (nDepIneq > 15) {
          emlrtDynamicBoundsCheckR2012b(16, 1, 15, &kc_emlrtBCI, &st);
        }
        memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
      }
      maxDiag = muDoubleScalarAbs(qrmanager->QR[0]);
      b_st.site = &kh_emlrtRSI;
      if (idx - 1 > 2147483646) {
        c_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idxDiag = 0; idxDiag <= idx - 2; idxDiag++) {
        maxDiag = muDoubleScalarMax(
            maxDiag, muDoubleScalarAbs(
                         qrmanager->QR[(15 * (idxDiag + 1) + idxDiag) + 1]));
      }
      if (idx <= workingset->nVar) {
        idxDiag = idx + 15 * (idx - 1);
        exitg1 = false;
        while ((!exitg1) && (idx > nFixedConstr_tmp)) {
          if ((idxDiag < 1) || (idxDiag > 225)) {
            emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 225, &lc_emlrtBCI, &st);
          }
          if (muDoubleScalarAbs(qrmanager->QR[idxDiag - 1]) < tol * maxDiag) {
            nDepIneq++;
            if ((idx < 1) || (idx > 15)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &mc_emlrtBCI, &st);
            }
            if (nDepIneq > 15) {
              emlrtDynamicBoundsCheckR2012b(16, 1, 15, &kc_emlrtBCI, &st);
            }
            memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
            idx--;
            idxDiag -= 16;
          } else {
            exitg1 = true;
          }
        }
      }
      b_st.site = &kh_emlrtRSI;
      countsort(&b_st, memspace->workspace_int, nDepIneq,
                memspace->workspace_sort, nFixedConstr_tmp + 1,
                workingset->nActiveConstr);
      for (idx = nDepIneq; idx >= 1; idx--) {
        b_st.site = &kh_emlrtRSI;
        removeConstr(&b_st, workingset, memspace->workspace_int[idx - 1]);
      }
    }
    st.site = &ah_emlrtRSI;
    okWorkingSet = feasibleX0ForWorkingSet(
        &st, memspace->workspace_float, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      st.site = &ah_emlrtRSI;
      nDepIneq = workingset->nActiveConstr;
      nFixedConstr_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
      if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
              workingset->nWConstr[4] >
          0) {
        tol = 10.0 * muDoubleScalarMin(
                         1.4901161193847656E-8,
                         2.2204460492503131E-15 *
                             (real_T)muIntScalarMax_sint32(
                                 workingset->nVar, workingset->nActiveConstr));
        b_st.site = &kh_emlrtRSI;
        if (nFixedConstr_tmp > 2147483646) {
          c_st.site = &u_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idx = 0; idx < nFixedConstr_tmp; idx++) {
          if ((idx + 1 < 1) || (idx + 1 > 15)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 15, &kc_emlrtBCI, &st);
          }
          qrmanager->jpvt[idx] = 1;
        }
        idxDiag = nFixedConstr_tmp + 1;
        b_st.site = &kh_emlrtRSI;
        if ((nFixedConstr_tmp + 1 <= workingset->nActiveConstr) &&
            (workingset->nActiveConstr > 2147483646)) {
          c_st.site = &u_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idx = idxDiag; idx <= nDepIneq; idx++) {
          if ((idx < 1) || (idx > 15)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &kc_emlrtBCI, &st);
          }
          qrmanager->jpvt[idx - 1] = 0;
        }
        b_st.site = &kh_emlrtRSI;
        if (workingset->nActiveConstr > 2147483646) {
          c_st.site = &u_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idxDiag = 0; idxDiag < nDepIneq; idxDiag++) {
          b_st.site = &kh_emlrtRSI;
          c_xcopy(&b_st, nVar_tmp, workingset->ATwset, (idxDiag << 3) + 1,
                  qrmanager->QR, 15 * idxDiag + 1);
        }
        b_st.site = &kh_emlrtRSI;
        if (workingset->nVar * workingset->nActiveConstr == 0) {
          qrmanager->mrows = workingset->nVar;
          qrmanager->ncols = workingset->nActiveConstr;
          qrmanager->minRowCol = 0;
        } else {
          qrmanager->usedPivoting = true;
          qrmanager->mrows = workingset->nVar;
          qrmanager->ncols = workingset->nActiveConstr;
          qrmanager->minRowCol = muIntScalarMin_sint32(
              workingset->nVar, workingset->nActiveConstr);
          c_st.site = &uf_emlrtRSI;
          xgeqp3(&c_st, qrmanager->QR, workingset->nVar,
                 workingset->nActiveConstr, qrmanager->jpvt, qrmanager->tau);
        }
        nDepIneq = 0;
        for (idx = workingset->nActiveConstr; idx > nVar_tmp; idx--) {
          nDepIneq++;
          if ((idx < 1) || (idx > 15)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &mc_emlrtBCI, &st);
          }
          if (nDepIneq > 15) {
            emlrtDynamicBoundsCheckR2012b(16, 1, 15, &kc_emlrtBCI, &st);
          }
          memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
        }
        maxDiag = muDoubleScalarAbs(qrmanager->QR[0]);
        b_st.site = &kh_emlrtRSI;
        if (idx - 1 > 2147483646) {
          c_st.site = &u_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (idxDiag = 0; idxDiag <= idx - 2; idxDiag++) {
          maxDiag = muDoubleScalarMax(
              maxDiag, muDoubleScalarAbs(
                           qrmanager->QR[(15 * (idxDiag + 1) + idxDiag) + 1]));
        }
        if (idx <= workingset->nVar) {
          idxDiag = idx + 15 * (idx - 1);
          exitg1 = false;
          while ((!exitg1) && (idx > nFixedConstr_tmp)) {
            if ((idxDiag < 1) || (idxDiag > 225)) {
              emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 225, &lc_emlrtBCI, &st);
            }
            if (muDoubleScalarAbs(qrmanager->QR[idxDiag - 1]) < tol * maxDiag) {
              nDepIneq++;
              if ((idx < 1) || (idx > 15)) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &mc_emlrtBCI, &st);
              }
              if (nDepIneq > 15) {
                emlrtDynamicBoundsCheckR2012b(16, 1, 15, &kc_emlrtBCI, &st);
              }
              memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
              idx--;
              idxDiag -= 16;
            } else {
              exitg1 = true;
            }
          }
        }
        b_st.site = &kh_emlrtRSI;
        countsort(&b_st, memspace->workspace_int, nDepIneq,
                  memspace->workspace_sort, nFixedConstr_tmp + 1,
                  workingset->nActiveConstr);
        for (idx = nDepIneq; idx >= 1; idx--) {
          b_st.site = &kh_emlrtRSI;
          removeConstr(&b_st, workingset, memspace->workspace_int[idx - 1]);
        }
      }
      st.site = &ah_emlrtRSI;
      okWorkingSet =
          feasibleX0ForWorkingSet(&st, memspace->workspace_float,
                                  solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 && (workingset->nWConstr[0] + workingset->nWConstr[1] ==
                   workingset->nVar)) {
      st.site = &ah_emlrtRSI;
      tol = c_maxConstraintViolation(&st, workingset, solution->xstar);
      if (tol > 1.0E-6) {
        solution->state = -2;
      }
    }
  } else {
    solution->state = -3;
    st.site = &ah_emlrtRSI;
    removeAllIneqConstr(&st, workingset);
  }
}

/* End of code generation (PresolveWorkingSet.c) */
