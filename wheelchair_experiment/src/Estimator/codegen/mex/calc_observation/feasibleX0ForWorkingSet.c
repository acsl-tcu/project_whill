/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * feasibleX0ForWorkingSet.c
 *
 * Code generation for function 'feasibleX0ForWorkingSet'
 *
 */

/* Include files */
#include "feasibleX0ForWorkingSet.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQRE.h"
#include "maxConstraintViolation.h"
#include "rank.h"
#include "rt_nonfinite.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xgeqp3.h"
#include "xtrsm.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo lh_emlrtRSI = {
    1,                         /* lineNo */
    "feasibleX0ForWorkingSet", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/feasibleX0ForWorkingSet.p" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    1,              /* lineNo */
    "computeTallQ", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+QRManager/"
    "computeTallQ.p" /* pathName */
};

static emlrtBCInfo cd_emlrtBCI = {
    1,                         /* iFirst */
    120,                       /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "feasibleX0ForWorkingSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/feasibleX0ForWorkingSet.p", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    1,                         /* iFirst */
    225,                       /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "feasibleX0ForWorkingSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/feasibleX0ForWorkingSet.p", /* pName */
    3                                        /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    1,                         /* iFirst */
    15,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "feasibleX0ForWorkingSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/feasibleX0ForWorkingSet.p", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    1,                         /* iFirst */
    15,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "feasibleX0ForWorkingSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/feasibleX0ForWorkingSet.p", /* pName */
    3                                        /* checkKind */
};

/* Function Definitions */
boolean_T feasibleX0ForWorkingSet(const emlrtStack *sp, real_T workspace[120],
                                  real_T xCurrent[8], g_struct_T *workingset,
                                  j_struct_T *qrmanager)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_workspace[120];
  int32_T idx;
  int32_T idx_row;
  int32_T ix;
  int32_T k;
  int32_T mWConstr;
  int32_T nVar;
  boolean_T nonDegenerateWset;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  mWConstr = workingset->nActiveConstr;
  nVar = workingset->nVar;
  nonDegenerateWset = true;
  if (mWConstr != 0) {
    real_T constrViolation_basicX;
    real_T d;
    int32_T i;
    int32_T rankQR;
    if (mWConstr >= nVar) {
      boolean_T overflow;
      st.site = &lh_emlrtRSI;
      if (nVar > 2147483646) {
        b_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      i = (uint8_T)nVar;
      overflow = (mWConstr > 2147483646);
      for (k = 0; k < i; k++) {
        rankQR = 15 * k + 1;
        st.site = &lh_emlrtRSI;
        if (overflow) {
          b_st.site = &u_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (idx_row = 0; idx_row < mWConstr; idx_row++) {
          idx = (k + (idx_row << 3)) + 1;
          if ((idx < 1) || (idx > 120)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 120, &cd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          ix = idx_row + rankQR;
          if ((ix < 1) || (ix > 225)) {
            emlrtDynamicBoundsCheckR2012b(ix, 1, 225, &dd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          qrmanager->QR[ix - 1] = workingset->ATwset[idx - 1];
        }
      }
      st.site = &lh_emlrtRSI;
      memset(&qrmanager->jpvt[0], 0, (uint32_T)i * sizeof(int32_T));
      st.site = &lh_emlrtRSI;
      if (mWConstr * nVar == 0) {
        qrmanager->mrows = mWConstr;
        qrmanager->ncols = nVar;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = mWConstr;
        qrmanager->ncols = nVar;
        qrmanager->minRowCol = muIntScalarMin_sint32(mWConstr, nVar);
        b_st.site = &uf_emlrtRSI;
        xgeqp3(&b_st, qrmanager->QR, mWConstr, nVar, qrmanager->jpvt,
               qrmanager->tau);
      }
      st.site = &lh_emlrtRSI;
      b_st.site = &mg_emlrtRSI;
      computeQ_(&b_st, qrmanager, qrmanager->mrows);
      rankQR = rank(qrmanager->QR, qrmanager->mrows, qrmanager->ncols);
      st.site = &lh_emlrtRSI;
      if (mWConstr > 2147483646) {
        b_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (idx = 0; idx < mWConstr; idx++) {
        constrViolation_basicX = workingset->bwset[idx];
        if ((idx + 1 < 1) || (idx + 1 > 15)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 15, &fd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        workspace[idx] = constrViolation_basicX;
        workspace[idx + 15] = constrViolation_basicX;
      }
      st.site = &lh_emlrtRSI;
      b_xgemv(&st, nVar, mWConstr, workingset->ATwset, xCurrent, workspace);
      memcpy(&b_workspace[0], &workspace[0], 120U * sizeof(real_T));
      st.site = &lh_emlrtRSI;
      xgemm(nVar, mWConstr, qrmanager->Q, b_workspace, workspace);
      st.site = &lh_emlrtRSI;
      xtrsm(rankQR, qrmanager->QR, workspace);
      rankQR++;
      st.site = &lh_emlrtRSI;
      for (ix = rankQR; ix <= nVar; ix++) {
        workspace[ix - 1] = 0.0;
        workspace[ix + 14] = 0.0;
      }
      st.site = &lh_emlrtRSI;
      for (ix = 0; ix < i; ix++) {
        idx = qrmanager->jpvt[ix];
        if ((idx < 1) || (idx > 15)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &fd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        workspace[qrmanager->jpvt[ix] + 29] = workspace[ix];
      }
      st.site = &lh_emlrtRSI;
      for (ix = 0; ix < i; ix++) {
        workspace[ix] = workspace[ix + 30];
      }
      st.site = &lh_emlrtRSI;
      for (ix = 0; ix < i; ix++) {
        idx = qrmanager->jpvt[ix];
        if ((idx < 1) || (idx > 15)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &fd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        workspace[qrmanager->jpvt[ix] + 29] = workspace[ix + 15];
      }
      st.site = &lh_emlrtRSI;
      for (ix = 0; ix < i; ix++) {
        workspace[ix + 15] = workspace[ix + 30];
      }
    } else {
      st.site = &lh_emlrtRSI;
      if (mWConstr - 1 >= 0) {
        memset(&qrmanager->jpvt[0], 0, (uint32_T)mWConstr * sizeof(int32_T));
      }
      st.site = &lh_emlrtRSI;
      factorQRE(&st, qrmanager, workingset->ATwset, nVar, mWConstr);
      st.site = &lh_emlrtRSI;
      b_st.site = &qh_emlrtRSI;
      computeQ_(&b_st, qrmanager, qrmanager->minRowCol);
      rankQR = rank(qrmanager->QR, qrmanager->mrows, qrmanager->ncols);
      st.site = &lh_emlrtRSI;
      for (idx = 0; idx < mWConstr; idx++) {
        ix = (qrmanager->jpvt[idx] - 1) << 3;
        st.site = &lh_emlrtRSI;
        b_st.site = &dh_emlrtRSI;
        c_st.site = &eh_emlrtRSI;
        d = 0.0;
        d_st.site = &fh_emlrtRSI;
        if (nVar > 2147483646) {
          e_st.site = &u_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        i = (uint8_T)nVar;
        for (k = 0; k < i; k++) {
          d += workingset->ATwset[ix + k] * xCurrent[k];
        }
        i = qrmanager->jpvt[idx];
        if ((i < 1) || (i > 15)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 15, &ed_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        constrViolation_basicX = workingset->bwset[qrmanager->jpvt[idx] - 1];
        workspace[idx] = constrViolation_basicX - d;
        i = qrmanager->jpvt[idx];
        if ((i < 1) || (i > 15)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 15, &ed_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        workspace[idx + 15] = constrViolation_basicX;
      }
      st.site = &lh_emlrtRSI;
      b_xtrsm(rankQR, qrmanager->QR, workspace);
      memcpy(&b_workspace[0], &workspace[0], 120U * sizeof(real_T));
      st.site = &lh_emlrtRSI;
      b_xgemm(nVar, rankQR, qrmanager->Q, b_workspace, workspace);
    }
    st.site = &lh_emlrtRSI;
    if (nVar > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    idx = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (idx <= (uint8_T)nVar - 1) {
        if (muDoubleScalarIsInf(workspace[idx]) ||
            muDoubleScalarIsNaN(workspace[idx])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          constrViolation_basicX = workspace[idx + 15];
          if (muDoubleScalarIsInf(constrViolation_basicX) ||
              muDoubleScalarIsNaN(constrViolation_basicX)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            idx++;
          }
        }
      } else {
        rankQR = nVar / 2 * 2;
        ix = rankQR - 2;
        for (k = 0; k <= ix; k += 2) {
          __m128d r;
          __m128d r1;
          r = _mm_loadu_pd(&workspace[k]);
          r1 = _mm_loadu_pd(&xCurrent[k]);
          r = _mm_add_pd(r, r1);
          _mm_storeu_pd(&workspace[k], r);
        }
        for (k = rankQR; k < nVar; k++) {
          workspace[k] += xCurrent[k];
        }
        st.site = &lh_emlrtRSI;
        d = maxConstraintViolation(&st, workingset, workspace);
        st.site = &lh_emlrtRSI;
        constrViolation_basicX =
            b_maxConstraintViolation(&st, workingset, workspace);
        if ((d <= 2.2204460492503131E-16) || (d < constrViolation_basicX)) {
          st.site = &lh_emlrtRSI;
          b_st.site = &cf_emlrtRSI;
          c_st.site = &df_emlrtRSI;
          i = (uint8_T)nVar;
          memcpy(&xCurrent[0], &workspace[0], (uint32_T)i * sizeof(real_T));
        } else {
          st.site = &lh_emlrtRSI;
          b_st.site = &cf_emlrtRSI;
          c_st.site = &df_emlrtRSI;
          i = (uint8_T)nVar;
          memcpy(&xCurrent[0], &workspace[15], (uint32_T)i * sizeof(real_T));
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return nonDegenerateWset;
}

/* End of code generation (feasibleX0ForWorkingSet.c) */
