/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EKFCorrector.c
 *
 * Code generation for function 'EKFCorrector'
 *
 */

/* Include files */
#include "EKFCorrector.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo jnb_emlrtRSI = {
    32,                                       /* lineNo */
    "EKFCorrector/correctStateAndCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m" /* pathName */
};

/* Function Definitions */
void c_EKFCorrector_correctStateAndC(const emlrtStack *sp, real_T x[6],
                                     real_T P[36], const real_T y[3],
                                     const real_T Pxy[18], const real_T Pyy[9],
                                     const real_T dHdx[18], real_T gain[18])
{
  __m128d b_r1;
  __m128d b_r2;
  __m128d b_r3;
  __m128d r;
  __m128d r10;
  __m128d r4;
  __m128d r5;
  __m128d r6;
  __m128d r7;
  __m128d r8;
  __m128d r9;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T b_P[36];
  real_T b_gain[36];
  real_T A[9];
  real_T a21;
  real_T maxval;
  int32_T i;
  int32_T i1;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jnb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &gcb_emlrtRSI;
  c_st.site = &hcb_emlrtRSI;
  d_st.site = &icb_emlrtRSI;
  memcpy(&A[0], &Pyy[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = muDoubleScalarAbs(Pyy[0]);
  a21 = muDoubleScalarAbs(Pyy[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (muDoubleScalarAbs(Pyy[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  A[r2] = Pyy[r2] / Pyy[r1];
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
    e_st.site = &jcb_emlrtRSI;
    f_st.site = &lcb_emlrtRSI;
    d_warning(&f_st);
  }
  r = _mm_set1_pd(A[r1]);
  _mm_storeu_pd(&gain[6 * r1], _mm_div_pd(_mm_loadu_pd(&Pxy[0]), r));
  b_r1 = _mm_loadu_pd(&gain[6 * r1]);
  b_r2 = _mm_set1_pd(A[r1 + 3]);
  _mm_storeu_pd(&gain[6 * r2],
                _mm_sub_pd(_mm_loadu_pd(&Pxy[6]), _mm_mul_pd(b_r1, b_r2)));
  b_r1 = _mm_loadu_pd(&gain[6 * r1]);
  b_r3 = _mm_set1_pd(A[r1 + 6]);
  _mm_storeu_pd(&gain[6 * r3],
                _mm_sub_pd(_mm_loadu_pd(&Pxy[12]), _mm_mul_pd(b_r1, b_r3)));
  b_r1 = _mm_loadu_pd(&gain[6 * r2]);
  r4 = _mm_set1_pd(A[r2 + 3]);
  _mm_storeu_pd(&gain[6 * r2], _mm_div_pd(b_r1, r4));
  b_r1 = _mm_loadu_pd(&gain[6 * r2]);
  r5 = _mm_loadu_pd(&gain[6 * r3]);
  r6 = _mm_set1_pd(A[r2 + 6]);
  _mm_storeu_pd(&gain[6 * r3], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r6)));
  b_r1 = _mm_loadu_pd(&gain[6 * r3]);
  r7 = _mm_set1_pd(A[r3 + 6]);
  _mm_storeu_pd(&gain[6 * r3], _mm_div_pd(b_r1, r7));
  b_r1 = _mm_loadu_pd(&gain[6 * r3]);
  r5 = _mm_loadu_pd(&gain[6 * r2]);
  r8 = _mm_set1_pd(A[r3 + 3]);
  _mm_storeu_pd(&gain[6 * r2], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r8)));
  b_r1 = _mm_loadu_pd(&gain[6 * r3]);
  r5 = _mm_loadu_pd(&gain[6 * r1]);
  r9 = _mm_set1_pd(A[r3]);
  _mm_storeu_pd(&gain[6 * r1], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r9)));
  b_r1 = _mm_loadu_pd(&gain[6 * r2]);
  r5 = _mm_loadu_pd(&gain[6 * r1]);
  r10 = _mm_set1_pd(A[r2]);
  _mm_storeu_pd(&gain[6 * r1], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r10)));
  i = 6 * r1 + 2;
  _mm_storeu_pd(&gain[i], _mm_div_pd(_mm_loadu_pd(&Pxy[2]), r));
  b_r1 = _mm_loadu_pd(&gain[i]);
  i1 = 6 * r2 + 2;
  _mm_storeu_pd(&gain[i1],
                _mm_sub_pd(_mm_loadu_pd(&Pxy[8]), _mm_mul_pd(b_r1, b_r2)));
  b_r1 = _mm_loadu_pd(&gain[i]);
  rtemp = 6 * r3 + 2;
  _mm_storeu_pd(&gain[rtemp],
                _mm_sub_pd(_mm_loadu_pd(&Pxy[14]), _mm_mul_pd(b_r1, b_r3)));
  b_r1 = _mm_loadu_pd(&gain[i1]);
  _mm_storeu_pd(&gain[i1], _mm_div_pd(b_r1, r4));
  b_r1 = _mm_loadu_pd(&gain[i1]);
  r5 = _mm_loadu_pd(&gain[rtemp]);
  _mm_storeu_pd(&gain[rtemp], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r6)));
  b_r1 = _mm_loadu_pd(&gain[rtemp]);
  _mm_storeu_pd(&gain[rtemp], _mm_div_pd(b_r1, r7));
  b_r1 = _mm_loadu_pd(&gain[rtemp]);
  r5 = _mm_loadu_pd(&gain[i1]);
  _mm_storeu_pd(&gain[i1], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r8)));
  b_r1 = _mm_loadu_pd(&gain[rtemp]);
  r5 = _mm_loadu_pd(&gain[i]);
  _mm_storeu_pd(&gain[i], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r9)));
  b_r1 = _mm_loadu_pd(&gain[i1]);
  r5 = _mm_loadu_pd(&gain[i]);
  _mm_storeu_pd(&gain[i], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r10)));
  i = 6 * r1 + 4;
  _mm_storeu_pd(&gain[i], _mm_div_pd(_mm_loadu_pd(&Pxy[4]), r));
  b_r1 = _mm_loadu_pd(&gain[i]);
  i1 = 6 * r2 + 4;
  _mm_storeu_pd(&gain[i1],
                _mm_sub_pd(_mm_loadu_pd(&Pxy[10]), _mm_mul_pd(b_r1, b_r2)));
  b_r1 = _mm_loadu_pd(&gain[i]);
  rtemp = 6 * r3 + 4;
  _mm_storeu_pd(&gain[rtemp],
                _mm_sub_pd(_mm_loadu_pd(&Pxy[16]), _mm_mul_pd(b_r1, b_r3)));
  b_r1 = _mm_loadu_pd(&gain[i1]);
  _mm_storeu_pd(&gain[i1], _mm_div_pd(b_r1, r4));
  b_r1 = _mm_loadu_pd(&gain[i1]);
  r5 = _mm_loadu_pd(&gain[rtemp]);
  _mm_storeu_pd(&gain[rtemp], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r6)));
  b_r1 = _mm_loadu_pd(&gain[rtemp]);
  _mm_storeu_pd(&gain[rtemp], _mm_div_pd(b_r1, r7));
  b_r1 = _mm_loadu_pd(&gain[rtemp]);
  r5 = _mm_loadu_pd(&gain[i1]);
  _mm_storeu_pd(&gain[i1], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r8)));
  b_r1 = _mm_loadu_pd(&gain[rtemp]);
  r5 = _mm_loadu_pd(&gain[i]);
  _mm_storeu_pd(&gain[i], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r9)));
  b_r1 = _mm_loadu_pd(&gain[i1]);
  r5 = _mm_loadu_pd(&gain[i]);
  _mm_storeu_pd(&gain[i], _mm_sub_pd(r5, _mm_mul_pd(b_r1, r10)));
  for (i = 0; i < 6; i++) {
    maxval = gain[i + 6];
    a21 = gain[i + 12];
    x[i] += (gain[i] * y[0] + maxval * y[1]) + a21 * y[2];
    for (i1 = 0; i1 < 6; i1++) {
      b_gain[i + 6 * i1] =
          (gain[i] * dHdx[3 * i1] + maxval * dHdx[3 * i1 + 1]) +
          a21 * dHdx[3 * i1 + 2];
    }
    for (i1 = 0; i1 < 6; i1++) {
      maxval = 0.0;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        maxval += b_gain[i + 6 * rtemp] * P[rtemp + 6 * i1];
      }
      rtemp = i + 6 * i1;
      b_P[rtemp] = P[rtemp] - maxval;
    }
  }
  memcpy(&P[0], &b_P[0], 36U * sizeof(real_T));
}

/* End of code generation (EKFCorrector.c) */
