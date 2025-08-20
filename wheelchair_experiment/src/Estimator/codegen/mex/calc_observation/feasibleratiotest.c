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
#include "calc_observation_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xnrm2.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo lj_emlrtRSI = {
    1,                   /* lineNo */
    "feasibleratiotest", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "feasibleratiotest.p" /* pathName */
};

static emlrtBCInfo dg_emlrtBCI = {
    1,                   /* iFirst */
    8,                   /* iLast */
    1,                   /* lineNo */
    1,                   /* colNo */
    "",                  /* aName */
    "feasibleratiotest", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "feasibleratiotest.p", /* pName */
    0                      /* checkKind */
};

/* Function Definitions */
real_T feasibleratiotest(
    const emlrtStack *sp, const real_T solution_xstar[8],
    const real_T solution_searchDir[8], real_T workspace[120],
    int32_T workingset_nVar, const real_T workingset_Aineq[16],
    const real_T workingset_bineq[2], const real_T workingset_lb[8],
    const real_T workingset_ub[8], const int32_T workingset_indexLB[8],
    const int32_T workingset_indexUB[8], const int32_T workingset_sizes[5],
    const int32_T workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr[15],
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
  int32_T b;
  int32_T i;
  int32_T ia;
  int32_T iac;
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
  st.site = &lj_emlrtRSI;
  denomTol = 2.2204460492503131E-13 *
             c_xnrm2(&st, workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 2) {
    st.site = &lj_emlrtRSI;
    b_st.site = &cf_emlrtRSI;
    c_st.site = &df_emlrtRSI;
    workspace[0] = workingset_bineq[0];
    workspace[1] = workingset_bineq[1];
    st.site = &lj_emlrtRSI;
    f_xgemv(&st, workingset_nVar, workingset_Aineq, solution_xstar, workspace);
    st.site = &lj_emlrtRSI;
    b_st.site = &xe_emlrtRSI;
    workspace[15] = 0.0;
    workspace[16] = 0.0;
    c_st.site = &ye_emlrtRSI;
    for (iac = 0; iac <= 8; iac += 8) {
      c = 0.0;
      b = iac + workingset_nVar;
      c_st.site = &af_emlrtRSI;
      if ((iac + 1 <= b) && (b > 2147483646)) {
        d_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (ia = iac + 1; ia <= b; ia++) {
        c += workingset_Aineq[ia - 1] * solution_searchDir[(ia - iac) - 1];
      }
      i = (iac >> 3) + 15;
      workspace[i] += c;
    }
    st.site = &lj_emlrtRSI;
    for (iac = 0; iac < 2; iac++) {
      phaseOneCorrectionX = workspace[iac + 15];
      if (phaseOneCorrectionX > denomTol) {
        st.site = &lj_emlrtRSI;
        i = workingset_isActiveIdx[2] + iac;
        if ((i < 1) || (i > 15)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 15, &kd_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[i - 1]) {
          c = workspace[iac];
          c = muDoubleScalarMin(muDoubleScalarAbs(c), 1.0E-6 - c) /
              phaseOneCorrectionX;
          if (c < alpha) {
            alpha = c;
            *constrType = 3;
            *constrIdx = iac + 1;
            *newBlocking = true;
          }
        }
      }
    }
  }
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX =
        (real_T)isPhaseOne * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP =
        (real_T)isPhaseOne * solution_searchDir[workingset_nVar - 1];
    i = workingset_sizes[3];
    st.site = &lj_emlrtRSI;
    for (iac = 0; iac <= i - 2; iac++) {
      if ((iac + 1 < 1) || (iac + 1 > 8)) {
        emlrtDynamicBoundsCheckR2012b(iac + 1, 1, 8, &dg_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b = workingset_indexLB[iac];
      if ((b < 1) || (b > 8)) {
        emlrtDynamicBoundsCheckR2012b(b, 1, 8, &dg_emlrtBCI, (emlrtConstCTX)sp);
      }
      c = -solution_searchDir[b - 1] - phaseOneCorrectionP;
      if (c > denomTol) {
        st.site = &lj_emlrtRSI;
        ia = workingset_isActiveIdx[3] + iac;
        if ((ia < 1) || (ia > 15)) {
          emlrtDynamicBoundsCheckR2012b(ia, 1, 15, &kd_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[ia - 1]) {
          ratio = (-solution_xstar[b - 1] - workingset_lb[b - 1]) -
                  phaseOneCorrectionX;
          c = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) / c;
          if (c < alpha) {
            alpha = c;
            *constrType = 4;
            *constrIdx = iac + 1;
            *newBlocking = true;
          }
        }
      }
    }
    if ((workingset_sizes[3] < 1) || (workingset_sizes[3] > 8)) {
      emlrtDynamicBoundsCheckR2012b(workingset_sizes[3], 1, 8, &dg_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = workingset_indexLB[workingset_sizes[3] - 1];
    if ((i < 1) || (i > 8)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 8, &dg_emlrtBCI, (emlrtConstCTX)sp);
    }
    phaseOneCorrectionX = -solution_searchDir[i - 1];
    if (phaseOneCorrectionX > denomTol) {
      st.site = &lj_emlrtRSI;
      b = workingset_isActiveIdx[3] + workingset_sizes[3];
      if ((b - 1 < 1) || (b - 1 > 15)) {
        emlrtDynamicBoundsCheckR2012b(b - 1, 1, 15, &kd_emlrtBCI, &st);
      }
      if (!workingset_isActiveConstr[b - 2]) {
        ratio = -solution_xstar[i - 1] - workingset_lb[i - 1];
        c = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) /
            phaseOneCorrectionX;
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
    st.site = &lj_emlrtRSI;
    if (workingset_sizes[4] > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)workingset_sizes[4];
    for (iac = 0; iac < i; iac++) {
      b = workingset_indexUB[iac];
      if ((b < 1) || (b > 8)) {
        emlrtDynamicBoundsCheckR2012b(b, 1, 8, &dg_emlrtBCI, (emlrtConstCTX)sp);
      }
      c = solution_searchDir[b - 1] - phaseOneCorrectionP;
      if (c > denomTol) {
        st.site = &lj_emlrtRSI;
        ia = workingset_isActiveIdx[4] + iac;
        if ((ia < 1) || (ia > 15)) {
          emlrtDynamicBoundsCheckR2012b(ia, 1, 15, &kd_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[ia - 1]) {
          ratio = (solution_xstar[b - 1] - workingset_ub[b - 1]) -
                  phaseOneCorrectionX;
          c = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) / c;
          if (c < alpha) {
            alpha = c;
            *constrType = 5;
            *constrIdx = iac + 1;
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
