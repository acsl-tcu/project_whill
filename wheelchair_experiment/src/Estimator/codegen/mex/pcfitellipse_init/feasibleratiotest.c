/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * feasibleratiotest.c
 *
 * Code generation for function 'feasibleratiotest'
 *
 */

/* Include files */
#include "feasibleratiotest.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xnrm2.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo eh_emlrtRSI = {
    1,                   /* lineNo */
    "feasibleratiotest", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\feasibleratiotest.p" /* pathName */
};

static emlrtBCInfo xe_emlrtBCI = {
    1,                   /* iFirst */
    7,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "feasibleratiotest", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\feasibleratiotest.p", /* pName */
    0                                   /* checkKind */
};

/* Function Definitions */
real_T feasibleratiotest(
    const emlrtStack *sp, const real_T solution_xstar[7],
    const real_T solution_searchDir[7], real_T workspace[91],
    int32_T workingset_nVar, const real_T workingset_Aineq[7],
    real_T workingset_bineq, const real_T workingset_lb[7],
    const real_T workingset_ub[7], const int32_T workingset_indexLB[7],
    const int32_T workingset_indexUB[7], const int32_T workingset_sizes[5],
    const int32_T workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr[13],
    const int32_T workingset_nWConstr[5], boolean_T isPhaseOne,
    boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T alpha;
  real_T c;
  real_T denomTol;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T ratio;
  int32_T i;
  int32_T i1;
  int32_T ia;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  st.site = &eh_emlrtRSI;
  denomTol =
      2.2204460492503131E-13 * xnrm2(&st, workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 1) {
    st.site = &eh_emlrtRSI;
    b_st.site = &oc_emlrtRSI;
    c_st.site = &pc_emlrtRSI;
    workspace[0] = workingset_bineq;
    st.site = &eh_emlrtRSI;
    c_xgemv(&st, workingset_nVar, workingset_Aineq, solution_xstar, workspace);
    st.site = &eh_emlrtRSI;
    b_st.site = &kc_emlrtRSI;
    workspace[13] = 0.0;
    c_st.site = &lc_emlrtRSI;
    c = 0.0;
    c_st.site = &mc_emlrtRSI;
    if (workingset_nVar > 2147483646) {
      d_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (ia = 1; ia <= workingset_nVar; ia++) {
      c += workingset_Aineq[ia - 1] * solution_searchDir[ia - 1];
    }
    workspace[13] += c;
    st.site = &eh_emlrtRSI;
    if (workspace[13] > denomTol) {
      st.site = &eh_emlrtRSI;
      if ((workingset_isActiveIdx[2] < 1) || (workingset_isActiveIdx[2] > 13)) {
        emlrtDynamicBoundsCheckR2012b(workingset_isActiveIdx[2], 1, 13,
                                      &fb_emlrtBCI, &st);
      }
      if (!workingset_isActiveConstr[workingset_isActiveIdx[2] - 1]) {
        c = muDoubleScalarMin(muDoubleScalarAbs(workspace[0]),
                              1.0E-6 - workspace[0]) /
            workspace[13];
        if (c < 1.0E+30) {
          alpha = c;
          *constrType = 3;
          *constrIdx = 1;
          *newBlocking = true;
        }
      }
    }
  }
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX =
        (real_T)isPhaseOne * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP =
        (real_T)isPhaseOne * solution_searchDir[workingset_nVar - 1];
    ia = workingset_sizes[3];
    st.site = &eh_emlrtRSI;
    for (idx = 0; idx <= ia - 2; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 7)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 7, &xe_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i = workingset_indexLB[idx];
      if ((i < 1) || (i > 7)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 7, &xe_emlrtBCI, (emlrtConstCTX)sp);
      }
      c = -solution_searchDir[i - 1] - phaseOneCorrectionP;
      if (c > denomTol) {
        st.site = &eh_emlrtRSI;
        i1 = workingset_isActiveIdx[3] + idx;
        if ((i1 < 1) || (i1 > 13)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, 13, &fb_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[i1 - 1]) {
          ratio = (-solution_xstar[i - 1] - workingset_lb[i - 1]) -
                  phaseOneCorrectionX;
          c = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) / c;
          if (c < alpha) {
            alpha = c;
            *constrType = 4;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
      }
    }
    if ((workingset_sizes[3] < 1) || (workingset_sizes[3] > 7)) {
      emlrtDynamicBoundsCheckR2012b(workingset_sizes[3], 1, 7, &xe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ia = workingset_indexLB[workingset_sizes[3] - 1];
    if ((ia < 1) || (ia > 7)) {
      emlrtDynamicBoundsCheckR2012b(ia, 1, 7, &xe_emlrtBCI, (emlrtConstCTX)sp);
    }
    c = -solution_searchDir[ia - 1];
    if (c > denomTol) {
      st.site = &eh_emlrtRSI;
      i = workingset_isActiveIdx[3] + workingset_sizes[3];
      if ((i - 1 < 1) || (i - 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(i - 1, 1, 13, &fb_emlrtBCI, &st);
      }
      if (!workingset_isActiveConstr[i - 2]) {
        ratio = -solution_xstar[ia - 1] - workingset_lb[ia - 1];
        c = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) / c;
        if (c < alpha) {
          alpha = c;
          *constrType = 4;
          *constrIdx = workingset_sizes[3];
          *newBlocking = true;
        }
      }
    }
  }
  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    phaseOneCorrectionX =
        (real_T)isPhaseOne * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP =
        (real_T)isPhaseOne * solution_searchDir[workingset_nVar - 1];
    st.site = &eh_emlrtRSI;
    if (workingset_sizes[4] > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    ia = (uint8_T)workingset_sizes[4];
    for (idx = 0; idx < ia; idx++) {
      i = workingset_indexUB[idx];
      if ((i < 1) || (i > 7)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 7, &xe_emlrtBCI, (emlrtConstCTX)sp);
      }
      c = solution_searchDir[i - 1] - phaseOneCorrectionP;
      if (c > denomTol) {
        st.site = &eh_emlrtRSI;
        i1 = workingset_isActiveIdx[4] + idx;
        if ((i1 < 1) || (i1 > 13)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, 13, &fb_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[i1 - 1]) {
          ratio = (solution_xstar[i - 1] - workingset_ub[i - 1]) -
                  phaseOneCorrectionX;
          c = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) / c;
          if (c < alpha) {
            alpha = c;
            *constrType = 5;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
      }
    }
  }
  if (!isPhaseOne) {
    if ((*newBlocking) && (alpha > 1.0)) {
      *newBlocking = false;
    }
    alpha = muDoubleScalarMin(alpha, 1.0);
  }
  return alpha;
}

/* End of code generation (feasibleratiotest.c) */
