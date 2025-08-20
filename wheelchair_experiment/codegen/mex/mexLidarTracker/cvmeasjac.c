/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cvmeasjac.c
 *
 * Code generation for function 'cvmeasjac'
 *
 */

/* Include files */
#include "cvmeasjac.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo
    lfb_emlrtRSI =
        {
            98,          /* lineNo */
            "cvmeasjac", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
            "cvmeasjac.m" /* pathName */
};

/* Function Definitions */
void cvmeasjac(const emlrtStack *sp, const real_T state[6], real_T jacobian[18])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lfb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 6)) {
    if ((!muDoubleScalarIsInf(state[k])) && (!muDoubleScalarIsNaN(state[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cvmeasjac:expectedFinite", 3, 4, 22, "input number 1, state,");
  }
  memset(&jacobian[0], 0, 18U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    k = 3 * (((i + 1) << 1) - 2);
    jacobian[k] = iv1[3 * i];
    jacobian[k + 1] = iv1[3 * i + 1];
    jacobian[k + 2] = iv1[3 * i + 2];
  }
}

/* End of code generation (cvmeasjac.c) */
