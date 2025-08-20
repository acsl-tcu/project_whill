/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RemoveDependentIneq_.c
 *
 * Code generation for function 'RemoveDependentIneq_'
 *
 */

/* Include files */
#include "RemoveDependentIneq_.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "moveConstraint_.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo xe_emlrtRSI = {
    1,                      /* lineNo */
    "RemoveDependentIneq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p" /* pathName */
};

static emlrtBCInfo cc_emlrtBCI = {
    1,                      /* iFirst */
    13,                     /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p", /* pName */
    3                                     /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    1,                      /* iFirst */
    169,                    /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    1,                      /* iFirst */
    13,                     /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p", /* pName */
    0                                     /* checkKind */
};

/* Function Definitions */
void RemoveDependentIneq_(const emlrtStack *sp, i_struct_T *workingset,
                          e_struct_T *qrmanager, d_struct_T *memspace,
                          real_T tolfactor)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  int32_T idxDiag;
  int32_T nActiveConstr_tmp;
  int32_T nFixedConstr;
  int32_T nVar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nActiveConstr_tmp = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
          workingset->nWConstr[4] >
      0) {
    real_T tol;
    int32_T nDepIneq;
    tol = tolfactor * (real_T)workingset->nVar * 2.2204460492503131E-16;
    st.site = &xe_emlrtRSI;
    if (nFixedConstr > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < nFixedConstr; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      qrmanager->jpvt[idx] = 1;
    }
    idxDiag = nFixedConstr + 1;
    st.site = &xe_emlrtRSI;
    if ((nFixedConstr + 1 <= workingset->nActiveConstr) &&
        (workingset->nActiveConstr > 2147483646)) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = idxDiag; idx <= nActiveConstr_tmp; idx++) {
      if ((idx < 1) || (idx > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      qrmanager->jpvt[idx - 1] = 0;
    }
    st.site = &xe_emlrtRSI;
    if (workingset->nActiveConstr > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idxDiag = 0; idxDiag < nActiveConstr_tmp; idxDiag++) {
      st.site = &xe_emlrtRSI;
      b_xcopy(&st, nVar, workingset->ATwset, 7 * idxDiag + 1, qrmanager->QR,
              13 * idxDiag + 1);
    }
    st.site = &xe_emlrtRSI;
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
      b_st.site = &gd_emlrtRSI;
      xgeqp3(&b_st, qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
             qrmanager->jpvt, qrmanager->tau);
    }
    nDepIneq = 0;
    for (idx = workingset->nActiveConstr; idx > nVar; idx--) {
      nDepIneq++;
      if ((idx < 1) || (idx > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &ec_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (nDepIneq > 13) {
        emlrtDynamicBoundsCheckR2012b(14, 1, 13, &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
    }
    if (idx <= workingset->nVar) {
      boolean_T exitg1;
      idxDiag = idx + 13 * (idx - 1);
      exitg1 = false;
      while ((!exitg1) && (idx > nFixedConstr)) {
        if ((idxDiag < 1) || (idxDiag > 169)) {
          emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 169, &dc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (muDoubleScalarAbs(qrmanager->QR[idxDiag - 1]) < tol) {
          nDepIneq++;
          if ((idx < 1) || (idx > 13)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &ec_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (nDepIneq > 13) {
            emlrtDynamicBoundsCheckR2012b(14, 1, 13, &cc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
          idx--;
          idxDiag -= 14;
        } else {
          exitg1 = true;
        }
      }
    }
    st.site = &xe_emlrtRSI;
    countsort(&st, memspace->workspace_int, nDepIneq, memspace->workspace_sort,
              nFixedConstr + 1, workingset->nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      st.site = &xe_emlrtRSI;
      idxDiag = memspace->workspace_int[idx - 1];
      if ((idxDiag < 1) || (idxDiag > 13)) {
        emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 13, &jb_emlrtBCI, &st);
      }
      nActiveConstr_tmp = workingset->Wid[idxDiag - 1];
      if ((nActiveConstr_tmp < 1) || (nActiveConstr_tmp > 6)) {
        emlrtDynamicBoundsCheckR2012b(nActiveConstr_tmp, 1, 6, &gb_emlrtBCI,
                                      &st);
      }
      nVar = (workingset->isActiveIdx[nActiveConstr_tmp - 1] +
              workingset->Wlocalidx[idxDiag - 1]) -
             1;
      if ((nVar < 1) || (nVar > 13)) {
        emlrtDynamicBoundsCheckR2012b(nVar, 1, 13, &kb_emlrtBCI, &st);
      }
      workingset->isActiveConstr[nVar - 1] = false;
      b_st.site = &ve_emlrtRSI;
      moveConstraint_(&b_st, workingset, workingset->nActiveConstr, idxDiag);
      workingset->nActiveConstr--;
      if ((nActiveConstr_tmp < 1) || (nActiveConstr_tmp > 5)) {
        emlrtDynamicBoundsCheckR2012b(nActiveConstr_tmp, 1, 5, &mb_emlrtBCI,
                                      &st);
      }
      workingset->nWConstr[nActiveConstr_tmp - 1]--;
    }
  }
}

/* End of code generation (RemoveDependentIneq_.c) */
