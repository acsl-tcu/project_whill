/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * atan2.c
 *
 * Code generation for function 'atan2'
 *
 */

/* Include files */
#include "atan2.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo vpb_emlrtRSI = {
    13,      /* lineNo */
    "atan2", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elfun/atan2.m" /* pathName
                                                                     */
};

/* Function Definitions */
int32_T b_atan2(const emlrtStack *sp, const real_T y_data[], int32_T y_size,
                const real_T x_data[], int32_T x_size, real_T r_data[])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T i;
  int32_T k;
  int32_T r_size;
  int8_T z_size_idx_0_tmp;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vpb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &spb_emlrtRSI;
  c_st.site = &tpb_emlrtRSI;
  if (y_size <= x_size) {
    z_size_idx_0_tmp = (int8_T)y_size;
  } else {
    z_size_idx_0_tmp = (int8_T)x_size;
  }
  d_st.site = &upb_emlrtRSI;
  p = true;
  if (z_size_idx_0_tmp == y_size) {
    if (z_size_idx_0_tmp != x_size) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &id_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  i = z_size_idx_0_tmp;
  r_size = z_size_idx_0_tmp;
  for (k = 0; k < i; k++) {
    r_data[k] = muDoubleScalarAtan2(y_data[k], x_data[k]);
  }
  return r_size;
}

/* End of code generation (atan2.c) */
