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
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqp3.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo gf_emlrtRSI = {
    1,                      /* lineNo */
    "RemoveDependentIneq_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p" /* pathName */
};

static emlrtBCInfo jc_emlrtBCI = {
    1,                      /* iFirst */
    15,                     /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p", /* pName */
    3                                     /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    1,                      /* iFirst */
    225,                    /* iLast */
    1,                      /* lineNo */
    1,                      /* colNo */
    "",                     /* aName */
    "RemoveDependentIneq_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\RemoveDependentIneq_.p", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    1,                      /* iFirst */
    15,                     /* iLast */
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
void RemoveDependentIneq_(const emlrtStack *sp, k_struct_T *workingset,
                          g_struct_T *qrmanager, f_struct_T *memspace,
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
    st.site = &gf_emlrtRSI;
    if (nFixedConstr > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < nFixedConstr; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 15)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 15, &jc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      qrmanager->jpvt[idx] = 1;
    }
    idxDiag = nFixedConstr + 1;
    st.site = &gf_emlrtRSI;
    if ((nFixedConstr + 1 <= workingset->nActiveConstr) &&
        (workingset->nActiveConstr > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = idxDiag; idx <= nActiveConstr_tmp; idx++) {
      if ((idx < 1) || (idx > 15)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &jc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      qrmanager->jpvt[idx - 1] = 0;
    }
    st.site = &gf_emlrtRSI;
    if (workingset->nActiveConstr > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idxDiag = 0; idxDiag < nActiveConstr_tmp; idxDiag++) {
      st.site = &gf_emlrtRSI;
      b_xcopy(&st, nVar, workingset->ATwset, (idxDiag << 3) + 1, qrmanager->QR,
              15 * idxDiag + 1);
    }
    st.site = &gf_emlrtRSI;
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
      b_st.site = &od_emlrtRSI;
      xgeqp3(&b_st, qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
             qrmanager->jpvt, qrmanager->tau);
    }
    nDepIneq = 0;
    for (idx = workingset->nActiveConstr; idx > nVar; idx--) {
      nDepIneq++;
      if ((idx < 1) || (idx > 15)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &lc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (nDepIneq > 15) {
        emlrtDynamicBoundsCheckR2012b(16, 1, 15, &jc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
    }
    if (idx <= workingset->nVar) {
      boolean_T exitg1;
      idxDiag = idx + 15 * (idx - 1);
      exitg1 = false;
      while ((!exitg1) && (idx > nFixedConstr)) {
        if ((idxDiag < 1) || (idxDiag > 225)) {
          emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 225, &kc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (muDoubleScalarAbs(qrmanager->QR[idxDiag - 1]) < tol) {
          nDepIneq++;
          if ((idx < 1) || (idx > 15)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &lc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (nDepIneq > 15) {
            emlrtDynamicBoundsCheckR2012b(16, 1, 15, &jc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
          idx--;
          idxDiag -= 16;
        } else {
          exitg1 = true;
        }
      }
    }
    st.site = &gf_emlrtRSI;
    countsort(&st, memspace->workspace_int, nDepIneq, memspace->workspace_sort,
              nFixedConstr + 1, workingset->nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      st.site = &gf_emlrtRSI;
      idxDiag = memspace->workspace_int[idx - 1];
      if ((idxDiag < 1) || (idxDiag > 15)) {
        emlrtDynamicBoundsCheckR2012b(idxDiag, 1, 15, &qb_emlrtBCI, &st);
      }
      nActiveConstr_tmp = workingset->Wid[idxDiag - 1];
      if ((nActiveConstr_tmp < 1) || (nActiveConstr_tmp > 6)) {
        emlrtDynamicBoundsCheckR2012b(nActiveConstr_tmp, 1, 6, &nb_emlrtBCI,
                                      &st);
      }
      nVar = (workingset->isActiveIdx[nActiveConstr_tmp - 1] +
              workingset->Wlocalidx[idxDiag - 1]) -
             1;
      if ((nVar < 1) || (nVar > 15)) {
        emlrtDynamicBoundsCheckR2012b(nVar, 1, 15, &rb_emlrtBCI, &st);
      }
      workingset->isActiveConstr[nVar - 1] = false;
      if (idxDiag < workingset->nActiveConstr) {
        b_st.site = &ef_emlrtRSI;
        moveConstraint_(&b_st, workingset, workingset->nActiveConstr, idxDiag);
      }
      workingset->nActiveConstr--;
      if ((nActiveConstr_tmp < 1) || (nActiveConstr_tmp > 5)) {
        emlrtDynamicBoundsCheckR2012b(nActiveConstr_tmp, 1, 5, &tb_emlrtBCI,
                                      &st);
      }
      workingset->nWConstr[nActiveConstr_tmp - 1]--;
    }
  }
}

/* End of code generation (RemoveDependentIneq_.c) */
