/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkLinearInputs.c
 *
 * Code generation for function 'checkLinearInputs'
 *
 */

/* Include files */
#include "checkLinearInputs.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo xb_emlrtRSI = {
    1,                   /* lineNo */
    "checkLinearInputs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "validate\\checkLinearInputs.p" /* pathName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    1,                   /* lineNo */
    1,                   /* colNo */
    "checkLinearInputs", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "validate\\checkLinearInputs.p" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    1,             /* lineNo */
    1,             /* colNo */
    "checkBounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\optimlib\\+optim\\+coder\\+"
    "validate\\checkBounds.p" /* pName */
};

/* Function Definitions */
void checkLinearInputs(const emlrtStack *sp, const real_T Aineq[5],
                       real_T bineq, const real_T lb[5], const real_T ub[5])
{
  emlrtStack st;
  int32_T k;
  boolean_T b[5];
  boolean_T b_b[5];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  for (k = 0; k < 5; k++) {
    real_T d;
    d = Aineq[k];
    b[k] = muDoubleScalarIsInf(d);
    b_b[k] = muDoubleScalarIsNaN(d);
  }
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 5)) {
    if (b[k] || b_b[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!y) {
    emlrtErrorWithMessageIdR2018a(
        sp, &r_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
        "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 1, "A");
  }
  if (muDoubleScalarIsInf(bineq) || muDoubleScalarIsNaN(bineq)) {
    emlrtErrorWithMessageIdR2018a(
        sp, &r_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
        "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 1, "B");
  }
  st.site = &xb_emlrtRSI;
  for (k = 0; k < 5; k++) {
    b[k] = (lb[k] >= rtInf);
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 5)) {
    if (b[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  guard1 = false;
  if (y) {
    guard1 = true;
  } else {
    for (k = 0; k < 5; k++) {
      b[k] = muDoubleScalarIsNaN(lb[k]);
    }
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (b[k]) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      guard1 = true;
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &s_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetectedLB",
        "optimlib_codegen:common:InfNaNComplexDetectedLB", 0);
  }
  for (k = 0; k < 5; k++) {
    b[k] = (ub[k] <= rtMinusInf);
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 5)) {
    if (b[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  guard1 = false;
  if (y) {
    guard1 = true;
  } else {
    for (k = 0; k < 5; k++) {
      b[k] = muDoubleScalarIsNaN(ub[k]);
    }
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (b[k]) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      guard1 = true;
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &s_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetectedUB",
        "optimlib_codegen:common:InfNaNComplexDetectedUB", 0);
  }
}

/* End of code generation (checkLinearInputs.c) */
