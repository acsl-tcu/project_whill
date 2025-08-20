/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeObjective_.c
 *
 * Code generation for function 'computeObjective_'
 *
 */

/* Include files */
#include "computeObjective_.h"
#include "pcfitellipse.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo bc_emlrtRSI = {
    1,                   /* lineNo */
    "computeObjective_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "ObjNonlinEvaluator\\computeObjective_.p" /* pathName */
};

/* Function Definitions */
real_T computeObjective_(const emlrtStack *sp,
                         const i_struct_T *c_obj_next_next_next_next_next_,
                         const real_T x[5], int32_T *status)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T fval;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &ub_emlrtRSI;
  fval = pcfitellipse_anonFcn2_anonFcn1(
      &b_st, c_obj_next_next_next_next_next_->points.data,
      c_obj_next_next_next_next_next_->points.size, x);
  *status = 1;
  b = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || b) {
    if (b) {
      *status = -3;
    } else if (fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  }
  return fval;
}

/* End of code generation (computeObjective_.c) */
