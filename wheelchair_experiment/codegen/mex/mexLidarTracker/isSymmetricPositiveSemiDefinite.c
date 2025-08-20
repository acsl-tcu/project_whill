/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * isSymmetricPositiveSemiDefinite.c
 *
 * Code generation for function 'isSymmetricPositiveSemiDefinite'
 *
 */

/* Include files */
#include "isSymmetricPositiveSemiDefinite.h"
#include "eigStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "warning.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xhseqr.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void isSymmetricPositiveSemiDefinite(const emlrtStack *sp,
                                     const real_T b_value[9])
{
  static const int32_T b_iv[2] = {3, 3};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  creal_T b_d[3];
  real_T A[9];
  real_T y[9];
  real_T work[3];
  real_T absx;
  real_T d;
  real_T tol;
  int32_T exponent;
  int32_T i;
  int32_T i1;
  int32_T idx;
  boolean_T x_data[6];
  boolean_T b_y[3];
  boolean_T c_y;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  work[0] = muDoubleScalarAbs(b_value[0]);
  work[1] = muDoubleScalarAbs(b_value[4]);
  work[2] = muDoubleScalarAbs(b_value[8]);
  if (!muDoubleScalarIsNaN(work[0])) {
    idx = 1;
  } else {
    idx = 0;
    i1 = 2;
    exitg1 = false;
    while ((!exitg1) && (i1 < 4)) {
      if (!muDoubleScalarIsNaN(work[i1 - 1])) {
        idx = i1;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
  if (idx == 0) {
    absx = work[0];
  } else {
    absx = work[idx - 1];
    idx++;
    for (i1 = idx; i1 < 4; i1++) {
      d = work[i1 - 1];
      if (absx < d) {
        absx = d;
      }
    }
  }
  if (muDoubleScalarIsInf(absx) || muDoubleScalarIsNaN(absx)) {
    absx = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    absx = 4.94065645841247E-324;
  } else {
    frexp(absx, &exponent);
    absx = ldexp(1.0, exponent - 53);
  }
  tol = 100.0 * absx;
  for (idx = 0; idx < 3; idx++) {
    A[3 * idx] = b_value[idx];
    A[3 * idx + 1] = b_value[idx + 3];
    A[3 * idx + 2] = b_value[idx + 6];
  }
  for (i1 = 0; i1 < 9; i1++) {
    y[i1] = muDoubleScalarAbs(b_value[i1] - A[i1]);
  }
  st.site = &ml_emlrtRSI;
  absx = muDoubleScalarSqrt(tol);
  st.site = &ml_emlrtRSI;
  b_st.site = &ol_emlrtRSI;
  b_y[0] = true;
  b_y[1] = true;
  b_y[2] = true;
  idx = 3;
  for (i = 0; i < 3; i++) {
    exponent = idx;
    i1 = idx - 2;
    idx += 3;
    c_st.site = &pl_emlrtRSI;
    if ((i1 <= exponent) && (exponent > 2147483646)) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    exitg1 = false;
    while ((!exitg1) && (i1 <= exponent)) {
      if (!(y[i1 - 1] < absx)) {
        b_y[i] = false;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
  c_y = true;
  i1 = 0;
  exitg1 = false;
  while ((!exitg1) && (i1 <= 2)) {
    if (!b_y[i1]) {
      c_y = false;
      exitg1 = true;
    } else {
      i1++;
    }
  }
  __m128d r;
  __m128d r1;
  st.site = &nl_emlrtRSI;
  r = _mm_loadu_pd(&A[0]);
  r1 = _mm_set1_pd(2.0);
  _mm_storeu_pd(&A[0],
                _mm_div_pd(_mm_add_pd(_mm_loadu_pd(&b_value[0]), r), r1));
  r = _mm_loadu_pd(&A[2]);
  _mm_storeu_pd(&A[2],
                _mm_div_pd(_mm_add_pd(_mm_loadu_pd(&b_value[2]), r), r1));
  r = _mm_loadu_pd(&A[4]);
  _mm_storeu_pd(&A[4],
                _mm_div_pd(_mm_add_pd(_mm_loadu_pd(&b_value[4]), r), r1));
  r = _mm_loadu_pd(&A[6]);
  _mm_storeu_pd(&A[6],
                _mm_div_pd(_mm_add_pd(_mm_loadu_pd(&b_value[6]), r), r1));
  A[8] = (b_value[8] + A[8]) / 2.0;
  b_st.site = &ql_emlrtRSI;
  c_st.site = &qc_emlrtRSI;
  d_st.site = &rc_emlrtRSI;
  p = flatVectorAllOrAny(A, b_iv);
  if (!p) {
    b_d[0].re = rtNaN;
    b_d[1].re = rtNaN;
    b_d[2].re = rtNaN;
  } else {
    int32_T exitg2;
    p = true;
    exponent = 0;
    exitg1 = false;
    while ((!exitg1) && (exponent < 3)) {
      i = 0;
      do {
        exitg2 = 0;
        if (i <= exponent) {
          if (!(A[i + 3 * exponent] == A[exponent + 3 * i])) {
            p = false;
            exitg2 = 1;
          } else {
            i++;
          }
        } else {
          exponent++;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
    if (p) {
      ptrdiff_t n_t;
      b_st.site = &rl_emlrtRSI;
      c_st.site = &ul_emlrtRSI;
      d_st.site = &wl_emlrtRSI;
      n_t = (ptrdiff_t)3;
      n_t = LAPACKE_dsyev(102, 'N', 'L', n_t, &A[0], n_t, &work[0]);
      e_st.site = &xl_emlrtRSI;
      if ((int32_T)n_t < 0) {
        if ((int32_T)n_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&e_st, &lb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&e_st, &kb_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 13, &cv[0], 12, (int32_T)n_t);
        }
      }
      b_d[0].re = work[0];
      b_d[1].re = work[1];
      b_d[2].re = work[2];
      if ((int32_T)n_t != 0) {
        c_st.site = &vl_emlrtRSI;
        warning(&c_st);
      }
    } else {
      p = true;
      exponent = 0;
      exitg1 = false;
      while ((!exitg1) && (exponent < 3)) {
        i = 0;
        do {
          exitg2 = 0;
          if (i <= exponent) {
            if (!(A[i + 3 * exponent] == -A[exponent + 3 * i])) {
              p = false;
              exitg2 = 1;
            } else {
              i++;
            }
          } else {
            exponent++;
            exitg2 = 2;
          }
        } while (exitg2 == 0);
        if (exitg2 == 1) {
          exitg1 = true;
        }
      }
      if (p) {
        b_st.site = &sl_emlrtRSI;
        c_st.site = &hm_emlrtRSI;
        d_st.site = &im_emlrtRSI;
        e_st.site = &jm_emlrtRSI;
        f_st.site = &qc_emlrtRSI;
        g_st.site = &rc_emlrtRSI;
        p = flatVectorAllOrAny(A, b_iv);
        if (!p) {
          for (idx = 0; idx < 9; idx++) {
            A[idx] = rtNaN;
          }
          idx = 2;
          for (exponent = 0; exponent < 2; exponent++) {
            if (idx <= 3) {
              memset(&A[(exponent * 3 + idx) + -1], 0,
                     (uint32_T)(-idx + 4) * sizeof(real_T));
            }
            idx++;
          }
        } else {
          real_T tau[2];
          e_st.site = &km_emlrtRSI;
          f_st.site = &nm_emlrtRSI;
          work[0] = 0.0;
          work[1] = 0.0;
          work[2] = 0.0;
          for (i = 0; i < 2; i++) {
            int32_T alpha1_tmp;
            int32_T in;
            idx = i * 3 + 2;
            in = (i + 1) * 3 + 1;
            alpha1_tmp = (i + 3 * i) + 1;
            absx = A[alpha1_tmp];
            g_st.site = &om_emlrtRSI;
            d = xzlarfg(&g_st, 2 - i, &absx, A, idx + 1);
            tau[i] = d;
            A[alpha1_tmp] = 1.0;
            exponent = i + idx;
            g_st.site = &pm_emlrtRSI;
            if (d != 0.0) {
              i1 = 2 - i;
              idx = exponent - i;
              while ((i1 > 0) && (A[idx] == 0.0)) {
                i1--;
                idx--;
              }
              h_st.site = &rm_emlrtRSI;
              idx = ilazlr(&h_st, 3, i1, A, in);
            } else {
              i1 = 0;
              idx = 0;
            }
            if (i1 > 0) {
              h_st.site = &sm_emlrtRSI;
              xgemv(&h_st, idx, i1, A, in, A, exponent, work);
              h_st.site = &tm_emlrtRSI;
              xgerc(&h_st, idx, i1, -tau[i], work, exponent, A, in);
            }
            g_st.site = &qm_emlrtRSI;
            xzlarf(&g_st, 2 - i, 2 - i, exponent, tau[i], A, (i + in) + 1,
                   work);
            A[alpha1_tmp] = absx;
          }
          e_st.site = &lm_emlrtRSI;
          idx = xhseqr(&e_st, A);
          if (idx != 0) {
            e_st.site = &mm_emlrtRSI;
            b_warning(&e_st);
          }
        }
        i = 1;
        do {
          exitg2 = 0;
          if (i <= 3) {
            boolean_T guard1;
            guard1 = false;
            if (i != 3) {
              d = A[i + 3 * (i - 1)];
              if (d != 0.0) {
                absx = muDoubleScalarAbs(d);
                b_d[i - 1].re = 0.0;
                b_d[i - 1].im = absx;
                b_d[i].re = 0.0;
                b_d[i].im = -absx;
                i += 2;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }
            if (guard1) {
              b_d[i - 1].re = 0.0;
              b_d[i - 1].im = 0.0;
              i++;
            }
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      } else {
        b_st.site = &tl_emlrtRSI;
        eigStandard(&b_st, A, b_d);
      }
    }
  }
  x_data[0] = (b_d[0].re < -tol);
  x_data[1] = (b_d[1].re < -tol);
  x_data[2] = (b_d[2].re < -tol);
  p = false;
  i1 = 0;
  exitg1 = false;
  while ((!exitg1) && (i1 <= 2)) {
    if (x_data[i1]) {
      p = true;
      exitg1 = true;
    } else {
      i1++;
    }
  }
  if (p || (!c_y)) {
    emlrtErrorWithMessageIdR2018a(
        sp, &mb_emlrtRTEI,
        "shared_tracking:KalmanFilter:invalidCovarianceValues",
        "shared_tracking:KalmanFilter:invalidCovarianceValues", 3, 4, 16,
        "MeasurementNoise");
  }
}

/* End of code generation (isSymmetricPositiveSemiDefinite.c) */
