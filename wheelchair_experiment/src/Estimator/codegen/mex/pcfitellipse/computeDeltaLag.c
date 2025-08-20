/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeDeltaLag.c
 *
 * Code generation for function 'computeDeltaLag'
 *
 */

/* Include files */
#include "computeDeltaLag.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mi_emlrtRSI = {
    1,                 /* lineNo */
    "computeDeltaLag", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "stopping\\computeDeltaLag.p" /* pathName */
};

/* Function Definitions */
void computeDeltaLag(const emlrtStack *sp, int32_T nVar, real_T workspace[8],
                     const real_T grad[8], const real_T JacIneqTrans[16],
                     const real_T grad_old[8], const real_T JacIneqTrans_old[8],
                     const real_T lambda[15], int32_T ineqL0)
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T ia;
  int32_T ixlast;
  int32_T k;
  int32_T scalarLB;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (nVar > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  ixlast = (uint8_T)nVar;
  memcpy(&workspace[0], &grad[0], (uint32_T)ixlast * sizeof(real_T));
  if (nVar >= 1) {
    ixlast = nVar - 1;
    scalarLB = (nVar / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      r = _mm_loadu_pd(&workspace[k]);
      _mm_storeu_pd(&workspace[k], _mm_sub_pd(r, _mm_loadu_pd(&grad_old[k])));
    }
    for (k = scalarLB; k <= ixlast; k++) {
      workspace[k] -= grad_old[k];
    }
  }
  st.site = &mi_emlrtRSI;
  b_st.site = &sc_emlrtRSI;
  c_st.site = &hd_emlrtRSI;
  ixlast = nVar + 8;
  c_st.site = &gd_emlrtRSI;
  if (nVar + 8 > 2147483646) {
    d_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  k = (nVar / 2) << 1;
  scalarLB = k + 9;
  vectorUB = k + 7;
  for (ia = 9; ia <= vectorUB; ia += 2) {
    r = _mm_loadu_pd(&workspace[ia - 9]);
    _mm_storeu_pd(&workspace[ia - 9],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&JacIneqTrans[ia - 1]),
                                           _mm_set1_pd(lambda[ineqL0 - 1]))));
  }
  for (ia = scalarLB; ia <= ixlast; ia++) {
    workspace[ia - 9] += JacIneqTrans[ia - 1] * lambda[ineqL0 - 1];
  }
  st.site = &mi_emlrtRSI;
  b_st.site = &sc_emlrtRSI;
  c_st.site = &hd_emlrtRSI;
  c_st.site = &gd_emlrtRSI;
  scalarLB = k + 1;
  vectorUB = k - 1;
  for (ia = 1; ia <= vectorUB; ia += 2) {
    r = _mm_loadu_pd(&workspace[ia - 1]);
    _mm_storeu_pd(
        &workspace[ia - 1],
        _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&JacIneqTrans_old[ia - 1]),
                                 _mm_set1_pd(-lambda[ineqL0 - 1]))));
  }
  for (ia = scalarLB; ia <= nVar; ia++) {
    workspace[ia - 1] += JacIneqTrans_old[ia - 1] * -lambda[ineqL0 - 1];
  }
}

/* End of code generation (computeDeltaLag.c) */
