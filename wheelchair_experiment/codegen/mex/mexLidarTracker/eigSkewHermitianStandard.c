/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eigSkewHermitianStandard.c
 *
 * Code generation for function 'eigSkewHermitianStandard'
 *
 */

/* Include files */
#include "eigSkewHermitianStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xhseqr.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo
    sc_emlrtRSI =
        {
            103,                  /* lineNo */
            "flatVectorAllOrAny", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
            "vAllOrAny.m" /* pathName */
};

static emlrtRSInfo cm_emlrtRSI = {
    71,        /* lineNo */
    "xzlarfg", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarfg.m" /* pathName */
};

/* Function Definitions */
void eigSkewHermitianStandard(const emlrtStack *sp, const real_T A[36],
                              creal_T V[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack st;
  real_T T[36];
  real_T work[6];
  real_T xnorm;
  int32_T b_i;
  int32_T exitg1;
  int32_T i;
  int32_T ia;
  int32_T iac;
  int32_T vectorUB;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hm_emlrtRSI;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  b_st.site = &im_emlrtRSI;
  memcpy(&T[0], &A[0], 36U * sizeof(real_T));
  c_st.site = &jm_emlrtRSI;
  d_st.site = &qc_emlrtRSI;
  e_st.site = &rc_emlrtRSI;
  p = true;
  f_st.site = &sc_emlrtRSI;
  for (i = 0; i < 36; i++) {
    if (p) {
      xnorm = A[i];
      if (muDoubleScalarIsInf(xnorm) || muDoubleScalarIsNaN(xnorm)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    for (vectorUB = 0; vectorUB < 36; vectorUB++) {
      T[vectorUB] = rtNaN;
    }
    i = 2;
    for (ia = 0; ia < 5; ia++) {
      if (i <= 6) {
        memset(&T[(ia * 6 + i) + -1], 0, (uint32_T)(-i + 7) * sizeof(real_T));
      }
      i++;
    }
  } else {
    real_T tau[5];
    c_st.site = &km_emlrtRSI;
    d_st.site = &nm_emlrtRSI;
    for (b_i = 0; b_i < 6; b_i++) {
      work[b_i] = 0.0;
    }
    for (b_i = 0; b_i < 5; b_i++) {
      real_T alpha1_tmp;
      int32_T alpha1_tmp_tmp_tmp;
      int32_T ic0;
      int32_T in;
      int32_T knt;
      int32_T lastc;
      int32_T lastv;
      in = (b_i + 1) * 6;
      alpha1_tmp_tmp_tmp = b_i + 6 * b_i;
      alpha1_tmp = T[alpha1_tmp_tmp_tmp + 1];
      i = b_i + 3;
      i = muIntScalarMin_sint32(i, 6) + b_i * 6;
      e_st.site = &om_emlrtRSI;
      tau[b_i] = 0.0;
      f_st.site = &gm_emlrtRSI;
      xnorm = d_xnrm2(&f_st, 4 - b_i, T, i);
      if (xnorm != 0.0) {
        xnorm = muDoubleScalarHypot(alpha1_tmp, xnorm);
        if (alpha1_tmp >= 0.0) {
          xnorm = -xnorm;
        }
        if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          do {
            knt++;
            f_st.site = &fm_emlrtRSI;
            e_xscal(&f_st, 4 - b_i, 9.9792015476736E+291, T, i);
            xnorm *= 9.9792015476736E+291;
            alpha1_tmp *= 9.9792015476736E+291;
          } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                   (knt < 20));
          f_st.site = &em_emlrtRSI;
          xnorm = d_xnrm2(&f_st, 4 - b_i, T, i);
          xnorm = muDoubleScalarHypot(alpha1_tmp, xnorm);
          if (alpha1_tmp >= 0.0) {
            xnorm = -xnorm;
          }
          tau[b_i] = (xnorm - alpha1_tmp) / xnorm;
          f_st.site = &dm_emlrtRSI;
          e_xscal(&f_st, 4 - b_i, 1.0 / (alpha1_tmp - xnorm), T, i);
          f_st.site = &cm_emlrtRSI;
          for (i = 0; i < knt; i++) {
            xnorm *= 1.0020841800044864E-292;
          }
          alpha1_tmp = xnorm;
        } else {
          tau[b_i] = (xnorm - alpha1_tmp) / xnorm;
          f_st.site = &bm_emlrtRSI;
          e_xscal(&f_st, 4 - b_i, 1.0 / (alpha1_tmp - xnorm), T, i);
          alpha1_tmp = xnorm;
        }
      }
      T[alpha1_tmp_tmp_tmp + 1] = 1.0;
      ic0 = in + 1;
      e_st.site = &pm_emlrtRSI;
      if (tau[b_i] != 0.0) {
        boolean_T exitg2;
        lastv = 4 - b_i;
        i = (alpha1_tmp_tmp_tmp - b_i) + 5;
        while ((lastv + 1 > 0) && (T[i] == 0.0)) {
          lastv--;
          i--;
        }
        lastc = 6;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          knt = in + lastc;
          ia = knt;
          do {
            exitg1 = 0;
            if (ia <= knt + lastv * 6) {
              if (T[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia += 6;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = -1;
        lastc = 0;
      }
      if (lastv + 1 > 0) {
        int32_T work_tmp;
        f_st.site = &sm_emlrtRSI;
        g_st.site = &vm_emlrtRSI;
        if (lastc != 0) {
          h_st.site = &ym_emlrtRSI;
          memset(&work[0], 0, (uint32_T)lastc * sizeof(real_T));
          knt = alpha1_tmp_tmp_tmp + 1;
          vectorUB = (in + 6 * lastv) + 1;
          for (iac = ic0; iac <= vectorUB; iac += 6) {
            i = (iac + lastc) - 1;
            h_st.site = &wm_emlrtRSI;
            for (ia = iac; ia <= i; ia++) {
              work_tmp = ia - iac;
              work[work_tmp] += T[ia - 1] * T[knt];
            }
            knt++;
          }
        }
        f_st.site = &tm_emlrtRSI;
        g_st.site = &an_emlrtRSI;
        h_st.site = &le_emlrtRSI;
        i_st.site = &me_emlrtRSI;
        if (!(-tau[b_i] == 0.0)) {
          knt = in;
          j_st.site = &oe_emlrtRSI;
          for (ia = 0; ia <= lastv; ia++) {
            xnorm = T[(alpha1_tmp_tmp_tmp + ia) + 1];
            if (xnorm != 0.0) {
              xnorm *= -tau[b_i];
              i = knt + 1;
              work_tmp = lastc + knt;
              j_st.site = &ne_emlrtRSI;
              if ((knt + 1 <= work_tmp) && (work_tmp > 2147483646)) {
                k_st.site = &mb_emlrtRSI;
                check_forloop_overflow_error(&k_st);
              }
              ic0 = ((((work_tmp - knt) / 2) << 1) + knt) + 1;
              vectorUB = ic0 - 2;
              for (iac = i; iac <= vectorUB; iac += 2) {
                __m128d r;
                __m128d r1;
                r = _mm_loadu_pd(&work[(iac - knt) - 1]);
                r1 = _mm_loadu_pd(&T[iac - 1]);
                _mm_storeu_pd(
                    &T[iac - 1],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xnorm))));
              }
              for (iac = ic0; iac <= work_tmp; iac++) {
                T[iac - 1] += work[(iac - knt) - 1] * xnorm;
              }
            }
            knt += 6;
          }
        }
      }
      e_st.site = &qm_emlrtRSI;
      b_xzlarf(&e_st, 5 - b_i, 5 - b_i, alpha1_tmp_tmp_tmp + 2, tau[b_i], T,
               (b_i + in) + 2, work);
      T[alpha1_tmp_tmp_tmp + 1] = alpha1_tmp;
    }
    c_st.site = &lm_emlrtRSI;
    i = b_xhseqr(&c_st, T);
    if (i != 0) {
      c_st.site = &mm_emlrtRSI;
      b_warning(&c_st);
    }
  }
  b_i = 1;
  do {
    exitg1 = 0;
    if (b_i <= 6) {
      boolean_T guard1;
      guard1 = false;
      if (b_i != 6) {
        xnorm = T[b_i + 6 * (b_i - 1)];
        if (xnorm != 0.0) {
          xnorm = muDoubleScalarAbs(xnorm);
          V[b_i - 1].re = 0.0;
          V[b_i - 1].im = xnorm;
          V[b_i].re = 0.0;
          V[b_i].im = -xnorm;
          b_i += 2;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        V[b_i - 1].re = 0.0;
        V[b_i - 1].im = 0.0;
        b_i++;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (eigSkewHermitianStandard.c) */
