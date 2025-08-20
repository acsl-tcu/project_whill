/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * constvel.c
 *
 * Code generation for function 'constvel'
 *
 */

/* Include files */
#include "constvel.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                      const real_T in2_data[], const int32_T in2_size[2],
                      int32_T in3)
{
  real_T b_in2_data[30];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  i = in3 << 1;
  if (in1_size[1] == 1) {
    loop_ub = in2_size[1];
  } else {
    loop_ub = in1_size[1];
  }
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_in2_data[i1] =
        in2_data[(i + 6 * (i1 * stride_0_1)) - 1] + in1_data[i1 * stride_1_1];
  }
  in1_size[0] = 1;
  in1_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in2_data[0], (uint32_T)loop_ub * sizeof(real_T));
  }
}

void constvel(const emlrtStack *sp, real_T state[6], real_T varargin_2)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T d;
  real_T d1;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &acb_emlrtRSI;
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
        "MATLAB:constvel:expectedFinite", 3, 4, 22, "input number 1, state,");
  }
  st.site = &bcb_emlrtRSI;
  b_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_2) || muDoubleScalarIsNaN(varargin_2)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:constvel:expectedFinite", 3, 4, 19, "input number 3, dt,");
  }
  st.site = &ccb_emlrtRSI;
  d = state[1];
  d1 = 0.5 * (varargin_2 * varargin_2) * 0.0;
  state[0] = (state[0] + d * varargin_2) + d1;
  d += 0.0 * varargin_2;
  state[1] = d;
  st.site = &ccb_emlrtRSI;
  d = state[3];
  state[2] = (state[2] + d * varargin_2) + d1;
  d += 0.0 * varargin_2;
  state[3] = d;
  st.site = &ccb_emlrtRSI;
  d = state[5];
  state[4] = (state[4] + d * varargin_2) + d1;
  d += 0.0 * varargin_2;
  state[5] = d;
}

void plus(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[],
          const int32_T in2_size[2])
{
  real_T b_in1_data[30];
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  if (in2_size[1] == 1) {
    loop_ub = in1_size[1];
  } else {
    loop_ub = in2_size[1];
  }
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] + in2_data[i * stride_1_1];
  }
  in1_size[0] = 1;
  in1_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in1_data[0], (uint32_T)loop_ub * sizeof(real_T));
  }
}

/* End of code generation (constvel.c) */
