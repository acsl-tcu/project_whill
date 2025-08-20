/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "mean.h"
#include "calc_observation_data.h"
#include "calc_observation_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
void mean(const emlrtStack *sp, const emxArray_real_T *x, real_T y[3])
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T col;
  int32_T ib;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &y_emlrtRSI;
  if (x->size[0] == 0) {
    y[0] = 0.0;
    y[1] = 0.0;
    y[2] = 0.0;
  } else {
    c_st.site = &ab_emlrtRSI;
    d_st.site = &bb_emlrtRSI;
    if (x->size[0] < 4096) {
      e_st.site = &cb_emlrtRSI;
      y[0] = sumColumnB(&e_st, x, 1, x->size[0]);
      e_st.site = &cb_emlrtRSI;
      y[1] = sumColumnB(&e_st, x, 2, x->size[0]);
      e_st.site = &cb_emlrtRSI;
      y[2] = sumColumnB(&e_st, x, 3, x->size[0]);
    } else {
      int32_T inb;
      int32_T nfb;
      int32_T nleft;
      nfb = (int32_T)((uint32_T)x->size[0] >> 12);
      inb = nfb << 12;
      nleft = x->size[0] - inb;
      for (col = 0; col < 3; col++) {
        real_T s;
        s = sumColumnB4(x, col + 1, 1);
        for (ib = 2; ib <= nfb; ib++) {
          s += sumColumnB4(x, col + 1, ((ib - 1) << 12) + 1);
        }
        if (nleft > 0) {
          e_st.site = &eb_emlrtRSI;
          s += b_sumColumnB(&e_st, x, col + 1, nleft, inb + 1);
        }
        y[col] = s;
      }
    }
  }
  r = _mm_loadu_pd(&y[0]);
  _mm_storeu_pd(&y[0], _mm_div_pd(r, _mm_set1_pd(x->size[0])));
  y[2] /= (real_T)x->size[0];
}

/* End of code generation (mean.c) */
