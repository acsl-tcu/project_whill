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
#include "calc_observation_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ok_emlrtRSI = {
    1,                 /* lineNo */
    "computeDeltaLag", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeDeltaLag.p" /* pathName */
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
  int32_T k;
  int32_T scalarLB;
  int32_T scalarLB_tmp;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ok_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (nVar > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  k = (uint8_T)nVar;
  memcpy(&workspace[0], &grad[0], (uint32_T)k * sizeof(real_T));
  scalarLB_tmp = (nVar / 2) << 1;
  vectorUB = scalarLB_tmp - 2;
  for (k = 0; k <= vectorUB; k += 2) {
    r = _mm_loadu_pd(&workspace[k]);
    _mm_storeu_pd(&workspace[k], _mm_sub_pd(r, _mm_loadu_pd(&grad_old[k])));
  }
  for (k = scalarLB_tmp; k < nVar; k++) {
    workspace[k] -= grad_old[k];
  }
  st.site = &ok_emlrtRSI;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  k = nVar + 8;
  c_st.site = &lf_emlrtRSI;
  if (nVar + 8 > 2147483646) {
    d_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  scalarLB = scalarLB_tmp + 9;
  vectorUB = scalarLB_tmp + 7;
  for (ia = 9; ia <= vectorUB; ia += 2) {
    r = _mm_loadu_pd(&workspace[ia - 9]);
    _mm_storeu_pd(&workspace[ia - 9],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&JacIneqTrans[ia - 1]),
                                           _mm_set1_pd(lambda[ineqL0 - 1]))));
  }
  for (ia = scalarLB; ia <= k; ia++) {
    workspace[ia - 9] += JacIneqTrans[ia - 1] * lambda[ineqL0 - 1];
  }
  st.site = &ok_emlrtRSI;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  c_st.site = &lf_emlrtRSI;
  scalarLB = scalarLB_tmp + 1;
  vectorUB = scalarLB_tmp - 1;
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
