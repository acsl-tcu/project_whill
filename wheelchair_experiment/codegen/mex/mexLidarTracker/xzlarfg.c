/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlarfg.c
 *
 * Code generation for function 'xzlarfg'
 *
 */

/* Include files */
#include "xzlarfg.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xscal.h"
#include "mwmathutil.h"

/* Function Definitions */
real_T b_xzlarfg(const emlrtStack *sp, int32_T n, real_T *alpha1, real_T x[3])
{
  emlrtStack st;
  real_T tau;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  tau = 0.0;
  if (n > 0) {
    real_T xnorm;
    xnorm = c_xnrm2(n - 1, x);
    if (xnorm != 0.0) {
      xnorm = muDoubleScalarHypot(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }
      if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
        int32_T knt;
        knt = 0;
        do {
          knt++;
          st.site = &fm_emlrtRSI;
          c_xscal(&st, n - 1, 9.9792015476736E+291, x);
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                 (knt < 20));
        xnorm = c_xnrm2(n - 1, x);
        xnorm = muDoubleScalarHypot(*alpha1, xnorm);
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &dm_emlrtRSI;
        c_xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x);
        for (k = 0; k < knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }
        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &bm_emlrtRSI;
        c_xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x);
        *alpha1 = xnorm;
      }
    }
  }
  return tau;
}

real_T xzlarfg(const emlrtStack *sp, int32_T n, real_T *alpha1, real_T x[9],
               int32_T ix0)
{
  emlrtStack st;
  real_T tau;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  tau = 0.0;
  if (n > 0) {
    real_T xnorm;
    st.site = &gm_emlrtRSI;
    xnorm = xnrm2(&st, n - 1, x, ix0);
    if (xnorm != 0.0) {
      xnorm = muDoubleScalarHypot(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }
      if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
        int32_T knt;
        knt = 0;
        do {
          knt++;
          st.site = &fm_emlrtRSI;
          xscal(&st, n - 1, 9.9792015476736E+291, x, ix0);
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                 (knt < 20));
        st.site = &em_emlrtRSI;
        xnorm = xnrm2(&st, n - 1, x, ix0);
        xnorm = muDoubleScalarHypot(*alpha1, xnorm);
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &dm_emlrtRSI;
        xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x, ix0);
        for (k = 0; k < knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }
        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &bm_emlrtRSI;
        xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x, ix0);
        *alpha1 = xnorm;
      }
    }
  }
  return tau;
}

/* End of code generation (xzlarfg.c) */
