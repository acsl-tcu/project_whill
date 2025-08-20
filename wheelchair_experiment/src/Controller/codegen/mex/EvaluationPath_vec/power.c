/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "power.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

/* Function Definitions */
void power(const real_T a_data[], const int32_T a_size[3], real_T y_data[],
           int32_T y_size[3])
{
  int32_T i;
  int32_T loop_ub_tmp;
  int32_T scalarLB;
  int32_T vectorUB;
  y_size[0] = a_size[0];
  y_size[1] = 1;
  y_size[2] = a_size[2];
  loop_ub_tmp = a_size[0] * a_size[2];
  scalarLB = loop_ub_tmp / 2 * 2;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    __m128d r;
    r = _mm_loadu_pd(&a_data[i]);
    r = _mm_mul_pd(r, r);
    _mm_storeu_pd(&y_data[i], r);
  }
  for (i = scalarLB; i < loop_ub_tmp; i++) {
    real_T varargin_1;
    varargin_1 = a_data[i];
    y_data[i] = varargin_1 * varargin_1;
  }
}

/* End of code generation (power.c) */
