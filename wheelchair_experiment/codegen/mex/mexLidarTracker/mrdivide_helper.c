/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kcb_emlrtRSI = {
    299,          /* lineNo */
    "lusolve3x3", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

/* Function Definitions */
void b_mrdiv(const emlrtStack *sp, const real_T A[3], const real_T B[9],
             real_T Y[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_A[9];
  real_T a21;
  real_T maxval;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hcb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &icb_emlrtRSI;
  memcpy(&b_A[0], &B[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = muDoubleScalarAbs(B[0]);
  a21 = muDoubleScalarAbs(B[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (muDoubleScalarAbs(B[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  b_A[r2] = B[r2] / B[r1];
  b_A[r3] /= b_A[r1];
  b_A[r2 + 3] -= b_A[r2] * b_A[r1 + 3];
  b_A[r3 + 3] -= b_A[r3] * b_A[r1 + 3];
  b_A[r2 + 6] -= b_A[r2] * b_A[r1 + 6];
  b_A[r3 + 6] -= b_A[r3] * b_A[r1 + 6];
  if (muDoubleScalarAbs(b_A[r3 + 3]) > muDoubleScalarAbs(b_A[r2 + 3])) {
    int32_T rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  b_A[r3 + 3] /= b_A[r2 + 3];
  b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
  if ((b_A[r1] == 0.0) || (b_A[r2 + 3] == 0.0) || (b_A[r3 + 6] == 0.0)) {
    c_st.site = &jcb_emlrtRSI;
    d_st.site = &lcb_emlrtRSI;
    d_warning(&d_st);
  }
  Y[r1] = A[0] / b_A[r1];
  Y[r2] = A[1] - Y[r1] * b_A[r1 + 3];
  Y[r3] = A[2] - Y[r1] * b_A[r1 + 6];
  Y[r2] /= b_A[r2 + 3];
  Y[r3] -= Y[r2] * b_A[r2 + 6];
  Y[r3] /= b_A[r3 + 6];
  Y[r2] -= Y[r3] * b_A[r3 + 3];
  Y[r1] -= Y[r3] * b_A[r3];
  Y[r1] -= Y[r2] * b_A[r2];
}

void mrdiv(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
           const real_T B[9], real_T Y_data[], int32_T Y_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T A[9];
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (A_size[0] == 0) {
    Y_size[0] = 0;
    Y_size[1] = 3;
  } else {
    real_T a21;
    real_T maxval;
    int32_T Y_data_tmp;
    int32_T b_Y_data_tmp;
    int32_T nb;
    int32_T r1;
    int32_T r2;
    int32_T r3;
    int32_T rtemp;
    int32_T scalarLB;
    st.site = &hcb_emlrtRSI;
    b_st.site = &icb_emlrtRSI;
    memcpy(&A[0], &B[0], 9U * sizeof(real_T));
    r1 = 0;
    r2 = 1;
    r3 = 2;
    maxval = muDoubleScalarAbs(B[0]);
    a21 = muDoubleScalarAbs(B[1]);
    if (a21 > maxval) {
      maxval = a21;
      r1 = 1;
      r2 = 0;
    }
    if (muDoubleScalarAbs(B[2]) > maxval) {
      r1 = 2;
      r2 = 1;
      r3 = 0;
    }
    A[r2] = B[r2] / B[r1];
    A[r3] /= A[r1];
    A[r2 + 3] -= A[r2] * A[r1 + 3];
    A[r3 + 3] -= A[r3] * A[r1 + 3];
    A[r2 + 6] -= A[r2] * A[r1 + 6];
    A[r3 + 6] -= A[r3] * A[r1 + 6];
    if (muDoubleScalarAbs(A[r3 + 3]) > muDoubleScalarAbs(A[r2 + 3])) {
      rtemp = r2;
      r2 = r3;
      r3 = rtemp;
    }
    A[r3 + 3] /= A[r2 + 3];
    A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
    if ((A[r1] == 0.0) || (A[r2 + 3] == 0.0) || (A[r3 + 6] == 0.0)) {
      c_st.site = &jcb_emlrtRSI;
      d_st.site = &lcb_emlrtRSI;
      d_warning(&d_st);
    }
    nb = A_size[0];
    Y_size[0] = A_size[0];
    Y_size[1] = 3;
    c_st.site = &kcb_emlrtRSI;
    scalarLB = (A_size[0] / 2) << 1;
    rtemp = scalarLB - 2;
    for (k = 0; k <= rtemp; k += 2) {
      __m128d b_r1;
      __m128d r;
      int32_T i;
      Y_data_tmp = k + Y_size[0] * r1;
      _mm_storeu_pd(&Y_data[Y_data_tmp],
                    _mm_div_pd(_mm_loadu_pd(&A_data[k]), _mm_set1_pd(A[r1])));
      r = _mm_loadu_pd(&Y_data[Y_data_tmp]);
      b_Y_data_tmp = k + Y_size[0] * r2;
      _mm_storeu_pd(&Y_data[b_Y_data_tmp],
                    _mm_sub_pd(_mm_loadu_pd(&A_data[k + A_size[0]]),
                               _mm_mul_pd(r, _mm_set1_pd(A[r1 + 3]))));
      r = _mm_loadu_pd(&Y_data[Y_data_tmp]);
      i = k + Y_size[0] * r3;
      _mm_storeu_pd(&Y_data[i],
                    _mm_sub_pd(_mm_loadu_pd(&A_data[k + A_size[0] * 2]),
                               _mm_mul_pd(r, _mm_set1_pd(A[r1 + 6]))));
      r = _mm_loadu_pd(&Y_data[b_Y_data_tmp]);
      _mm_storeu_pd(&Y_data[b_Y_data_tmp],
                    _mm_div_pd(r, _mm_set1_pd(A[r2 + 3])));
      r = _mm_loadu_pd(&Y_data[b_Y_data_tmp]);
      b_r1 = _mm_loadu_pd(&Y_data[i]);
      _mm_storeu_pd(&Y_data[i],
                    _mm_sub_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(A[r2 + 6]))));
      r = _mm_loadu_pd(&Y_data[i]);
      _mm_storeu_pd(&Y_data[i], _mm_div_pd(r, _mm_set1_pd(A[r3 + 6])));
      r = _mm_loadu_pd(&Y_data[i]);
      b_r1 = _mm_loadu_pd(&Y_data[b_Y_data_tmp]);
      _mm_storeu_pd(&Y_data[b_Y_data_tmp],
                    _mm_sub_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(A[r3 + 3]))));
      r = _mm_loadu_pd(&Y_data[i]);
      b_r1 = _mm_loadu_pd(&Y_data[Y_data_tmp]);
      _mm_storeu_pd(&Y_data[Y_data_tmp],
                    _mm_sub_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(A[r3]))));
      r = _mm_loadu_pd(&Y_data[b_Y_data_tmp]);
      b_r1 = _mm_loadu_pd(&Y_data[Y_data_tmp]);
      _mm_storeu_pd(&Y_data[Y_data_tmp],
                    _mm_sub_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(A[r2]))));
    }
    for (k = scalarLB; k < nb; k++) {
      rtemp = k + Y_size[0] * r1;
      Y_data[rtemp] = A_data[k] / A[r1];
      Y_data_tmp = k + Y_size[0] * r2;
      Y_data[Y_data_tmp] = A_data[k + A_size[0]] - Y_data[rtemp] * A[r1 + 3];
      b_Y_data_tmp = k + Y_size[0] * r3;
      Y_data[b_Y_data_tmp] =
          A_data[k + A_size[0] * 2] - Y_data[rtemp] * A[r1 + 6];
      Y_data[Y_data_tmp] /= A[r2 + 3];
      Y_data[b_Y_data_tmp] -= Y_data[Y_data_tmp] * A[r2 + 6];
      Y_data[b_Y_data_tmp] /= A[r3 + 6];
      Y_data[Y_data_tmp] -= Y_data[b_Y_data_tmp] * A[r3 + 3];
      Y_data[rtemp] -= Y_data[b_Y_data_tmp] * A[r3];
      Y_data[rtemp] -= Y_data[Y_data_tmp] * A[r2];
    }
  }
}

/* End of code generation (mrdivide_helper.c) */
