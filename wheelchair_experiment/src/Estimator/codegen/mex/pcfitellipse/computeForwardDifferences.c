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
#include "pcfitellipse.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = {
    1,                           /* lineNo */
    "computeForwardDifferences", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\optimlib\\+optim\\+coder\\+"
    "utils\\+FiniteDifferences\\+internal\\computeForw"
    "ardDifferences.p" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    1,                      /* lineNo */
    "finDiffEvalAndChkErr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\optimlib\\+optim\\+coder\\+"
    "utils\\+FiniteDifferences\\+internal\\finDiffEval"
    "AndChkErr.p" /* pathName */
};

/* Function Definitions */
boolean_T computeForwardDifferences(const emlrtStack *sp, l_struct_T *obj,
                                    real_T fCurrent,
                                    const real_T cIneqCurrent[2], real_T xk[5],
                                    real_T gradf[8], real_T JacCineqTrans[16],
                                    const real_T lb[5], const real_T ub[5])
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
  st.site = &pc_emlrtRSI;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 5)) {
    real_T cIneqPlus;
    real_T deltaX;
    real_T lbDiff;
    real_T ubDiff;
    int32_T b_idx;
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
    st.site = &pc_emlrtRSI;
    cIneqPlus = obj->cIneq_1;
    lbDiff = xk[idx];
    xk[idx] += deltaX;
    b_st.site = &qc_emlrtRSI;
    c_st.site = &ub_emlrtRSI;
    ubDiff =
        pcfitellipse_anonFcn2_anonFcn1(&c_st, obj->objfun.workspace.points.data,
                                       obj->objfun.workspace.points.size, xk);
    evalOK = ((!muDoubleScalarIsInf(ubDiff)) && (!muDoubleScalarIsNaN(ubDiff)));
    if (evalOK) {
      /* %%% 関数 %%%% */
      /*  2ndRANSACで制約条件の追加points(x,y,alpha,beta,theta):観測値,COG:点群重心
       */
      /*  c(points) <= 0 */
      cIneqPlus = muDoubleScalarHypot(obj->nonlin.workspace.COG_init[0],
                                      obj->nonlin.workspace.COG_init[1]) -
                  muDoubleScalarHypot(xk[0], xk[1]);
      b_idx = 1;
      while (evalOK && (b_idx <= 1)) {
        evalOK = ((!muDoubleScalarIsInf(cIneqPlus)) &&
                  (!muDoubleScalarIsNaN(cIneqPlus)));
        b_idx = 2;
      }
      if (evalOK) {
        xk[idx] = lbDiff;
      }
    }
    obj->f_1 = ubDiff;
    obj->cIneq_1 = cIneqPlus;
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
          st.site = &pc_emlrtRSI;
          lbDiff = xk[idx];
          xk[idx] += deltaX;
          b_st.site = &qc_emlrtRSI;
          c_st.site = &ub_emlrtRSI;
          ubDiff = pcfitellipse_anonFcn2_anonFcn1(
              &c_st, obj->objfun.workspace.points.data,
              obj->objfun.workspace.points.size, xk);
          evalOK = ((!muDoubleScalarIsInf(ubDiff)) &&
                    (!muDoubleScalarIsNaN(ubDiff)));
          if (evalOK) {
            /* %%% 関数 %%%% */
            /*  2ndRANSACで制約条件の追加points(x,y,alpha,beta,theta):観測値,COG:点群重心
             */
            /*  c(points) <= 0 */
            cIneqPlus = muDoubleScalarHypot(obj->nonlin.workspace.COG_init[0],
                                            obj->nonlin.workspace.COG_init[1]) -
                        muDoubleScalarHypot(xk[0], xk[1]);
            b_idx = 1;
            while (evalOK && (b_idx <= 1)) {
              evalOK = ((!muDoubleScalarIsInf(cIneqPlus)) &&
                        (!muDoubleScalarIsNaN(cIneqPlus)));
              b_idx = 2;
            }
            if (evalOK) {
              xk[idx] = lbDiff;
            }
          }
          obj->f_1 = ubDiff;
          obj->cIneq_1 = cIneqPlus;
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
      st.site = &pc_emlrtRSI;
      JacCineqTrans[idx + 8] = (obj->cIneq_1 - cIneqCurrent[1]) / deltaX;
      st.site = &pc_emlrtRSI;
      idx++;
    }
  }
  return evalOK;
}

/* End of code generation (computeForwardDifferences.c) */
