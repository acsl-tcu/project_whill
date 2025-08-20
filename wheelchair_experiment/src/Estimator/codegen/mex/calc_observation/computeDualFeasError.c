/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeDualFeasError.c
 *
 * Code generation for function 'computeDualFeasError'
 *
 */

/* Include files */
#include "computeDualFeasError.h"
#include "calc_observation_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qf_emlrtRSI = {
    1,                      /* lineNo */
    "computeDualFeasError", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeDualFeasError.p" /* pathName */
};

/* Function Definitions */
boolean_T b_computeDualFeasError(const emlrtStack *sp, int32_T nVar,
                                 const real_T gradLag[120], real_T *val)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T exitg1;
  boolean_T gradOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  gradOK = true;
  *val = 0.0;
  st.site = &qf_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= (uint8_T)nVar - 1)) {
    gradOK = ((!muDoubleScalarIsInf(gradLag[idx])) &&
              (!muDoubleScalarIsNaN(gradLag[idx])));
    if (!gradOK) {
      exitg1 = true;
    } else {
      *val = muDoubleScalarMax(*val, muDoubleScalarAbs(gradLag[idx]));
      idx++;
    }
  }
  return gradOK;
}

boolean_T computeDualFeasError(const emlrtStack *sp, int32_T nVar,
                               const real_T gradLag[8], real_T *val)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T exitg1;
  boolean_T gradOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  gradOK = true;
  *val = 0.0;
  st.site = &qf_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= (uint8_T)nVar - 1)) {
    gradOK = ((!muDoubleScalarIsInf(gradLag[idx])) &&
              (!muDoubleScalarIsNaN(gradLag[idx])));
    if (!gradOK) {
      exitg1 = true;
    } else {
      *val = muDoubleScalarMax(*val, muDoubleScalarAbs(gradLag[idx]));
      idx++;
    }
  }
  return gradOK;
}

/* End of code generation (computeDualFeasError.c) */
