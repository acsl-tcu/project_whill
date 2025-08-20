/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzsvdc.c
 *
 * Code generation for function 'xzsvdc'
 *
 */

/* Include files */
#include "xzsvdc.h"
#include "calc_observation_data.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = {
    404,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    293,      /* lineNo */
    13,       /* colNo */
    "xzsvdc", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pName */
};

/* Function Definitions */
void xzsvdc(const emlrtStack *sp, real_T A[6], real_T S[2])
{
  __m128d r;
  emlrtStack st;
  real_T e[3];
  real_T s[3];
  real_T anrm;
  real_T b;
  real_T b_r;
  real_T cscale;
  real_T nrm;
  real_T scale;
  real_T sm;
  real_T sn;
  real_T snorm;
  real_T sqds;
  int32_T iter;
  int32_T kase;
  int32_T m;
  boolean_T apply_transform;
  boolean_T doscale;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  e[0] = 0.0;
  doscale = false;
  anrm = xzlangeM(A);
  cscale = anrm;
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    b_xzlascl(anrm, cscale, A);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    b_xzlascl(anrm, cscale, A);
  }
  apply_transform = false;
  nrm = xnrm2(A);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[0] < 0.0) {
      s[0] = -nrm;
    } else {
      s[0] = nrm;
    }
    if (muDoubleScalarAbs(s[0]) >= 1.0020841800044864E-292) {
      r = _mm_loadu_pd(&A[0]);
      _mm_storeu_pd(&A[0], _mm_mul_pd(_mm_set1_pd(1.0 / s[0]), r));
    } else {
      r = _mm_loadu_pd(&A[0]);
      _mm_storeu_pd(&A[0], _mm_div_pd(r, _mm_set1_pd(s[0])));
    }
    A[0]++;
    s[0] = -s[0];
    xaxpy(-(xdotc(A, A, 3) / A[0]), A, 3);
  } else {
    s[0] = 0.0;
  }
  e[1] = A[2];
  if (apply_transform) {
    xaxpy(-(xdotc(A, A, 5) / A[0]), A, 5);
  }
  e[2] = A[4];
  nrm = b_xnrm2(e);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -nrm;
    } else {
      e[0] = nrm;
    }
    if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
      r = _mm_loadu_pd(&e[1]);
      _mm_storeu_pd(&e[1], _mm_mul_pd(_mm_set1_pd(1.0 / e[0]), r));
    } else {
      r = _mm_loadu_pd(&e[1]);
      _mm_storeu_pd(&e[1], _mm_div_pd(r, _mm_set1_pd(e[0])));
    }
    e[1]++;
    e[0] = -e[0];
    nrm = 0.0;
    if (!(e[1] == 0.0)) {
      nrm = e[1] * A[3];
    }
    if (!(e[2] == 0.0)) {
      nrm += e[2] * A[5];
    }
    sm = -e[1] / e[1];
    if (!(sm == 0.0)) {
      A[3] += sm * nrm;
    }
    sm = -e[2] / e[1];
    if (!(sm == 0.0)) {
      A[5] += sm * nrm;
    }
  }
  m = 1;
  s[1] = A[3];
  s[2] = 0.0;
  e[1] = A[5];
  e[2] = 0.0;
  iter = 0;
  sqds = s[0];
  if (s[0] != 0.0) {
    nrm = muDoubleScalarAbs(s[0]);
    b_r = s[0] / nrm;
    sqds = nrm;
    s[0] = nrm;
    e[0] /= b_r;
  }
  if (e[0] != 0.0) {
    nrm = muDoubleScalarAbs(e[0]);
    b_r = nrm / e[0];
    e[0] = nrm;
    s[1] = A[3] * b_r;
  }
  snorm = muDoubleScalarMax(muDoubleScalarAbs(sqds), e[0]);
  sqds = s[1];
  if (s[1] != 0.0) {
    nrm = muDoubleScalarAbs(s[1]);
    b_r = s[1] / nrm;
    sqds = nrm;
    s[1] = nrm;
    e[1] = A[5] / b_r;
  }
  if (e[1] != 0.0) {
    nrm = muDoubleScalarAbs(e[1]);
    b_r = nrm / e[1];
    e[1] = nrm;
    s[2] = 0.0 * b_r;
  }
  snorm = muDoubleScalarMax(snorm,
                            muDoubleScalarMax(muDoubleScalarAbs(sqds), e[1]));
  if (s[2] != 0.0) {
    s[2] = rtNaN;
  }
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &f_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      int32_T ii_tmp_tmp;
      int32_T q;
      boolean_T exitg2;
      ii_tmp_tmp = m + 1;
      q = m + 1;
      exitg2 = false;
      while (!(exitg2 || (q == 0))) {
        nrm = muDoubleScalarAbs(e[q - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[q - 1]) +
                                              muDoubleScalarAbs(s[q]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[q - 1] = 0.0;
          exitg2 = true;
        } else {
          q--;
        }
      }
      if (q == m + 1) {
        kase = 4;
      } else {
        int32_T qs;
        qs = m + 2;
        kase = m + 2;
        exitg2 = false;
        while ((!exitg2) && (kase >= q)) {
          qs = kase;
          if (kase == q) {
            exitg2 = true;
          } else {
            nrm = 0.0;
            if (kase < m + 2) {
              nrm = muDoubleScalarAbs(e[kase - 1]);
            }
            if (kase > q + 1) {
              nrm += muDoubleScalarAbs(e[kase - 2]);
            }
            b_r = muDoubleScalarAbs(s[kase - 1]);
            if ((b_r <= 2.2204460492503131E-16 * nrm) ||
                (b_r <= 1.0020841800044864E-292)) {
              s[kase - 1] = 0.0;
              exitg2 = true;
            } else {
              kase--;
            }
          }
        }
        if (qs == q) {
          kase = 3;
        } else if (qs == m + 2) {
          kase = 1;
        } else {
          kase = 2;
          q = qs;
        }
      }
      switch (kase) {
      case 1:
        b_r = e[m];
        e[m] = 0.0;
        for (kase = ii_tmp_tmp; kase >= q + 1; kase--) {
          scale = 0.0;
          sn = 0.0;
          drotg(&s[kase - 1], &b_r, &scale, &sn);
          if (kase > q + 1) {
            b_r = -sn * e[0];
            e[0] *= scale;
          }
        }
        break;
      case 2:
        b_r = e[q - 1];
        e[q - 1] = 0.0;
        for (kase = q + 1; kase <= m + 2; kase++) {
          scale = 0.0;
          sn = 0.0;
          drotg(&s[kase - 1], &b_r, &scale, &sn);
          nrm = e[kase - 1];
          b_r = -sn * nrm;
          e[kase - 1] = nrm * scale;
        }
        break;
      case 3:
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[q])),
            muDoubleScalarAbs(e[q]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        b_r = e[m] / scale;
        sqds = s[q] / scale;
        b = ((nrm + sm) * (nrm - sm) + b_r * b_r) / 2.0;
        nrm = sm * b_r;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          b_r = b * b + nrm;
          st.site = &rb_emlrtRSI;
          if (b_r < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &i_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          b_r = muDoubleScalarSqrt(b_r);
          if (b < 0.0) {
            b_r = -b_r;
          }
          b_r = nrm / (b + b_r);
        } else {
          b_r = 0.0;
        }
        b_r += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        for (kase = q + 1; kase <= ii_tmp_tmp; kase++) {
          scale = 0.0;
          sn = 0.0;
          drotg(&b_r, &nrm, &scale, &sn);
          if (kase > q + 1) {
            e[0] = b_r;
          }
          nrm = e[kase - 1];
          b_r = s[kase - 1];
          sm = scale * b_r + sn * nrm;
          e[kase - 1] = scale * nrm - sn * b_r;
          sqds = s[kase];
          b = sn * sqds;
          sqds *= scale;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          s[kase - 1] = sm;
          nrm = e[kase - 1];
          b_r = scale * nrm + sn * sqds;
          sqds = -sn * nrm + scale * sqds;
          s[kase] = sqds;
          nrm = sn * e[kase];
          e[kase] *= scale;
        }
        e[m] = b_r;
        iter++;
        break;
      default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
        }
        kase = q + 1;
        while ((q + 1 < 3) && (s[q] < s[kase])) {
          nrm = s[q];
          s[q] = s[kase];
          s[kase] = nrm;
          q = kase;
          kase++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  S[0] = s[0];
  S[1] = s[1];
  if (doscale) {
    xzlascl(cscale, anrm, S);
  }
}

/* End of code generation (xzsvdc.c) */
