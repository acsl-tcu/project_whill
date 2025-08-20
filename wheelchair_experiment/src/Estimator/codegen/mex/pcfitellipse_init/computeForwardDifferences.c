/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeForwardDifferences.c
 *
 * Code generation for function 'computeForwardDifferences'
 *
 */

/* Include files */
#include "computeForwardDifferences.h"
#include "pcfitellipse_init.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hc_emlrtRSI = {
    1,                           /* lineNo */
    "computeForwardDifferences", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\optimlib\\+optim\\+coder\\+"
    "utils\\+FiniteDifferences\\+internal\\computeForw"
    "ardDifferences.p" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI = {
    1,                      /* lineNo */
    "finDiffEvalAndChkErr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\optimlib\\+optim\\+coder\\+"
    "utils\\+FiniteDifferences\\+internal\\finDiffEval"
    "AndChkErr.p" /* pathName */
};

/* Function Definitions */
boolean_T computeForwardDifferences(const emlrtStack *sp, j_struct_T *obj,
                                    real_T fCurrent, real_T xk[5],
                                    real_T gradf[7], const real_T lb[5],
                                    const real_T ub[5])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx;
  boolean_T evalOK;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  evalOK = true;
  obj->numEvals = 0;
  st.site = &hc_emlrtRSI;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 5)) {
    real_T deltaX;
    real_T lbDiff;
    real_T ubDiff;
    boolean_T guard1 = false;
    boolean_T modifiedStep;
    modifiedStep = false;
    deltaX = 1.4901161193847656E-8 * (1.0 - 2.0 * (real_T)(xk[idx] < 0.0)) *
             muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
    if (obj->hasLB[idx] || obj->hasUB[idx]) {
      if (obj->hasLB[idx] && obj->hasUB[idx]) {
        lbDiff = deltaX;
        if ((lb[idx] != ub[idx]) && (xk[idx] >= lb[idx]) &&
            (xk[idx] <= ub[idx])) {
          ubDiff = xk[idx] + deltaX;
          if ((ubDiff > ub[idx]) || (ubDiff < lb[idx])) {
            lbDiff = -deltaX;
            modifiedStep = true;
            ubDiff = xk[idx] - deltaX;
            if ((ubDiff > ub[idx]) || (ubDiff < lb[idx])) {
              lbDiff = xk[idx] - lb[idx];
              ubDiff = ub[idx] - xk[idx];
              if (lbDiff <= ubDiff) {
                lbDiff = -lbDiff;
              } else {
                lbDiff = ubDiff;
              }
            }
          }
        }
        deltaX = lbDiff;
      } else if (obj->hasUB[idx]) {
        if ((xk[idx] <= ub[idx]) && (xk[idx] + deltaX > ub[idx])) {
          deltaX = -deltaX;
          modifiedStep = true;
        }
      } else if ((xk[idx] >= lb[idx]) && (xk[idx] + deltaX < lb[idx])) {
        deltaX = -deltaX;
        modifiedStep = true;
      }
    }
    st.site = &hc_emlrtRSI;
    lbDiff = xk[idx];
    xk[idx] += deltaX;
    b_st.site = &ic_emlrtRSI;
    c_st.site = &cb_emlrtRSI;
    ubDiff = c_pcfitellipse_init_anonFcn1_an(
        &c_st, obj->objfun.workspace.points.data,
        obj->objfun.workspace.points.size, xk);
    evalOK = ((!muDoubleScalarIsInf(ubDiff)) && (!muDoubleScalarIsNaN(ubDiff)));
    if (evalOK) {
      xk[idx] = lbDiff;
    }
    obj->f_1 = ubDiff;
    obj->numEvals++;
    guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        deltaX = -deltaX;
        if (obj->hasLB[idx]) {
          ubDiff = xk[idx] + deltaX;
          if ((ubDiff >= lb[idx]) && obj->hasUB[idx] && (ubDiff <= ub[idx])) {
            modifiedStep = true;
          } else {
            modifiedStep = false;
          }
        } else {
          modifiedStep = false;
        }
        if ((!obj->hasBounds) || modifiedStep) {
          st.site = &hc_emlrtRSI;
          lbDiff = xk[idx];
          xk[idx] += deltaX;
          b_st.site = &ic_emlrtRSI;
          c_st.site = &cb_emlrtRSI;
          ubDiff = c_pcfitellipse_init_anonFcn1_an(
              &c_st, obj->objfun.workspace.points.data,
              obj->objfun.workspace.points.size, xk);
          evalOK = ((!muDoubleScalarIsInf(ubDiff)) &&
                    (!muDoubleScalarIsNaN(ubDiff)));
          if (evalOK) {
            xk[idx] = lbDiff;
          }
          obj->f_1 = ubDiff;
          obj->numEvals++;
        }
      }
      if (!evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      gradf[idx] = (obj->f_1 - fCurrent) / deltaX;
      idx++;
    }
  }
  return evalOK;
}

/* End of code generation (computeForwardDifferences.c) */
