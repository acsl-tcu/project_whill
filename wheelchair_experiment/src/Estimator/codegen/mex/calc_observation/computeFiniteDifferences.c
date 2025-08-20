/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeFiniteDifferences.c
 *
 * Code generation for function 'computeFiniteDifferences'
 *
 */

/* Include files */
#include "computeFiniteDifferences.h"
#include "calc_observation_types.h"
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo te_emlrtRSI = {
    1,                          /* lineNo */
    "computeFiniteDifferences", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/computeFiniteDifferences.p" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    1,                           /* lineNo */
    "computeForwardDifferences", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/+internal/computeForwardDifferences.p" /* pathName */
};

/* Function Definitions */
boolean_T computeFiniteDifferences(const emlrtStack *sp, h_struct_T *obj,
                                   real_T fCurrent,
                                   const real_T cIneqCurrent[2], real_T xk[5],
                                   real_T gradf[8], real_T JacCineqTrans[16],
                                   const real_T lb[5], const real_T ub[5])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T evalOK;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &te_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  evalOK = true;
  obj->numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 5)) {
    real_T d;
    real_T deltaX;
    real_T lbDiff;
    real_T t0_nonlin_workspace_Plant_yaw;
    real_T ubDiff;
    boolean_T guard1;
    boolean_T modifiedStep;
    modifiedStep = false;
    deltaX = 1.4901161193847656E-8 * (1.0 - 2.0 * (real_T)(xk[idx] < 0.0)) *
             muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
    if (obj->hasLB[idx] || obj->hasUB[idx]) {
      if (obj->hasLB[idx] && obj->hasUB[idx]) {
        lbDiff = deltaX;
        if ((lb[idx] != ub[idx]) && (xk[idx] >= lb[idx]) &&
            (xk[idx] <= ub[idx])) {
          d = xk[idx] + deltaX;
          if ((d > ub[idx]) || (d < lb[idx])) {
            lbDiff = -deltaX;
            modifiedStep = true;
            d = xk[idx] - deltaX;
            if ((d > ub[idx]) || (d < lb[idx])) {
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
    lbDiff = obj->nonlin.workspace.Plant.X;
    ubDiff = obj->nonlin.workspace.Plant.Y;
    t0_nonlin_workspace_Plant_yaw = obj->nonlin.workspace.Plant.yaw;
    b_st.site = &ue_emlrtRSI;
    evalOK = finDiffEvalAndChkErr(
        &b_st, obj->objfun.workspace.points, obj->nonlin.workspace.COG_init,
        lbDiff, ubDiff, t0_nonlin_workspace_Plant_yaw, &obj->cIneq_1, idx + 1,
        deltaX, xk, &obj->f_1);
    obj->numEvals++;
    guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        deltaX = -deltaX;
        if (obj->hasLB[idx]) {
          d = xk[idx] + deltaX;
          if ((d >= lb[idx]) && obj->hasUB[idx] && (d <= ub[idx])) {
            modifiedStep = true;
          } else {
            modifiedStep = false;
          }
        } else {
          modifiedStep = false;
        }
        if ((!obj->hasBounds) || modifiedStep) {
          b_st.site = &ue_emlrtRSI;
          evalOK = finDiffEvalAndChkErr(&b_st, obj->objfun.workspace.points,
                                        obj->nonlin.workspace.COG_init, lbDiff,
                                        ubDiff, t0_nonlin_workspace_Plant_yaw,
                                        &obj->cIneq_1, idx + 1, deltaX, xk,
                                        &obj->f_1);
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
      JacCineqTrans[idx + 8] = (obj->cIneq_1 - cIneqCurrent[1]) / deltaX;
      idx++;
    }
  }
  return evalOK;
}

/* End of code generation (computeFiniteDifferences.c) */
