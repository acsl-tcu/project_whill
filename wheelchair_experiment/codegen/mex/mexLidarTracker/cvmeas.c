/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cvmeas.c
 *
 * Code generation for function 'cvmeas'
 *
 */

/* Include files */
#include "cvmeas.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void cvmeas(const emlrtStack *sp, const real_T state[6], real_T measurement[3])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T tgtpos_idx_0;
  real_T tgtpos_idx_1;
  real_T tgtpos_idx_2;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dcb_emlrtRSI;
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
        "MATLAB:cvmeas:expectedFinite", 3, 4, 22, "input number 1, state,");
  }
  tgtpos_idx_0 = state[0];
  tgtpos_idx_1 = state[2];
  tgtpos_idx_2 = state[4];
  for (k = 0; k < 3; k++) {
    measurement[k] =
        ((real_T)iv1[k] * tgtpos_idx_0 + (real_T)iv1[k + 3] * tgtpos_idx_1) +
        (real_T)iv1[k + 6] * tgtpos_idx_2;
  }
}

/* End of code generation (cvmeas.c) */
