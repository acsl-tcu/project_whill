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
#include "Faster_processingPcloud_data.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo hc_emlrtRSI = {
    431,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI = {
    418,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    415,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    404,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    377,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    375,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    358,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    144,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    138,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    118,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    106,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    101,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    21,                   /* lineNo */
    "scaleVectorByRecip", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "scaleVectorByRecip.m" /* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    293,      /* lineNo */
    13,       /* colNo */
    "xzsvdc", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pName */
};

/* Function Definitions */
void xzsvdc(const emlrtStack *sp, real_T A[9], real_T S[3])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T e[3];
  real_T work[3];
  real_T anrm;
  real_T b;
  real_T cscale;
  real_T nrm;
  real_T r;
  real_T scale;
  real_T sm;
  real_T sn;
  real_T snorm;
  real_T sqds;
  int32_T ii;
  int32_T iter;
  int32_T k;
  int32_T m;
  int32_T q;
  int32_T qp1;
  int32_T qq;
  int32_T qs;
  int32_T vectorUB;
  boolean_T doscale;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  S[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  S[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  S[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
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
  for (q = 0; q < 2; q++) {
    __m128d b_r;
    boolean_T apply_transform;
    qp1 = q + 2;
    m = q + 3 * q;
    qq = m + 1;
    apply_transform = false;
    st.site = &sc_emlrtRSI;
    nrm = xnrm2(&st, 3 - q, A, m + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[m] < 0.0) {
        sqds = -nrm;
      } else {
        sqds = nrm;
      }
      S[q] = sqds;
      st.site = &rc_emlrtRSI;
      if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
        b_st.site = &vc_emlrtRSI;
        xscal(&b_st, 3 - q, 1.0 / sqds, A, m + 1);
      } else {
        qs = (m - q) + 3;
        iter = ((((qs - m) / 2) << 1) + m) + 1;
        vectorUB = iter - 2;
        for (k = qq; k <= vectorUB; k += 2) {
          b_r = _mm_loadu_pd(&A[k - 1]);
          _mm_storeu_pd(&A[k - 1], _mm_div_pd(b_r, _mm_set1_pd(S[q])));
        }
        for (k = iter; k <= qs; k++) {
          A[k - 1] /= S[q];
        }
      }
      A[m]++;
      S[q] = -S[q];
    } else {
      S[q] = 0.0;
    }
    for (qs = qp1; qs < 4; qs++) {
      qq = q + 3 * (qs - 1);
      if (apply_transform) {
        st.site = &qc_emlrtRSI;
        nrm = xdotc(&st, 3 - q, A, m + 1, A, qq + 1);
        nrm = -(nrm / A[m]);
        xaxpy(3 - q, nrm, m + 1, A, qq + 1);
      }
      e[qs - 1] = A[qq];
    }
    if (q + 1 <= 1) {
      st.site = &pc_emlrtRSI;
      nrm = b_xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        st.site = &oc_emlrtRSI;
        sm = e[0];
        if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
          b_xscal(1.0 / e[0], e);
        } else {
          iter = ((((2 - q) / 2) << 1) + q) + 2;
          vectorUB = iter - 2;
          for (k = qp1; k <= vectorUB; k += 2) {
            b_r = _mm_loadu_pd(&e[k - 1]);
            _mm_storeu_pd(&e[k - 1], _mm_div_pd(b_r, _mm_set1_pd(sm)));
          }
          for (k = iter; k < 4; k++) {
            e[k - 1] /= sm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (ii = qp1; ii < 4; ii++) {
          work[ii - 1] = 0.0;
        }
        for (qs = qp1; qs < 4; qs++) {
          b_xaxpy(e[qs - 1], A, 3 * (qs - 1) + 2, work);
        }
        for (qs = qp1; qs < 4; qs++) {
          c_xaxpy(-e[qs - 1] / e[1], work, A, 3 * (qs - 1) + 2);
        }
      }
    }
  }
  m = 1;
  S[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0;
  iter = 0;
  sqds = S[0];
  if (S[0] != 0.0) {
    nrm = muDoubleScalarAbs(S[0]);
    r = S[0] / nrm;
    sqds = nrm;
    S[0] = nrm;
    e[0] /= r;
  }
  if (e[0] != 0.0) {
    nrm = muDoubleScalarAbs(e[0]);
    r = nrm / e[0];
    e[0] = nrm;
    S[1] *= r;
  }
  snorm = muDoubleScalarMax(muDoubleScalarAbs(sqds), e[0]);
  sqds = S[1];
  if (S[1] != 0.0) {
    nrm = muDoubleScalarAbs(S[1]);
    r = S[1] / nrm;
    sqds = nrm;
    S[1] = nrm;
    e[1] = A[7] / r;
  }
  if (e[1] != 0.0) {
    nrm = muDoubleScalarAbs(e[1]);
    r = nrm / e[1];
    e[1] = nrm;
    S[2] = A[8] * r;
  }
  snorm = muDoubleScalarMax(snorm,
                            muDoubleScalarMax(muDoubleScalarAbs(sqds), e[1]));
  sqds = S[2];
  if (S[2] != 0.0) {
    nrm = muDoubleScalarAbs(S[2]);
    sqds = nrm;
    S[2] = nrm;
  }
  snorm =
      muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(sqds), 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &j_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      boolean_T exitg2;
      vectorUB = m + 1;
      ii = m + 1;
      exitg2 = false;
      while (!(exitg2 || (ii == 0))) {
        nrm = muDoubleScalarAbs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(S[ii - 1]) +
                                              muDoubleScalarAbs(S[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg2 = true;
        } else {
          ii--;
        }
      }
      if (ii == m + 1) {
        qq = 4;
      } else {
        qs = m + 2;
        qq = m + 2;
        exitg2 = false;
        while ((!exitg2) && (qq >= ii)) {
          qs = qq;
          if (qq == ii) {
            exitg2 = true;
          } else {
            nrm = 0.0;
            if (qq < m + 2) {
              nrm = muDoubleScalarAbs(e[qq - 1]);
            }
            if (qq > ii + 1) {
              nrm += muDoubleScalarAbs(e[qq - 2]);
            }
            r = muDoubleScalarAbs(S[qq - 1]);
            if ((r <= 2.2204460492503131E-16 * nrm) ||
                (r <= 1.0020841800044864E-292)) {
              S[qq - 1] = 0.0;
              exitg2 = true;
            } else {
              qq--;
            }
          }
        }
        if (qs == ii) {
          qq = 3;
        } else if (qs == m + 2) {
          qq = 1;
        } else {
          qq = 2;
          ii = qs;
        }
      }
      switch (qq) {
      case 1:
        r = e[m];
        e[m] = 0.0;
        for (k = vectorUB; k >= ii + 1; k--) {
          st.site = &nc_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&S[k - 1], &r, &scale, &sn);
          if (k > ii + 1) {
            r = -sn * e[0];
            e[0] *= scale;
          }
        }
        break;
      case 2:
        r = e[ii - 1];
        e[ii - 1] = 0.0;
        st.site = &mc_emlrtRSI;
        for (k = ii + 1; k <= m + 2; k++) {
          st.site = &lc_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&S[k - 1], &r, &scale, &sn);
          nrm = e[k - 1];
          r = -sn * nrm;
          e[k - 1] = nrm * scale;
        }
        break;
      case 3:
        nrm = S[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(S[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(S[ii])),
            muDoubleScalarAbs(e[ii]));
        sm = nrm / scale;
        nrm = S[m] / scale;
        r = e[m] / scale;
        sqds = S[ii] / scale;
        b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
        nrm = sm * r;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          r = b * b + nrm;
          st.site = &kc_emlrtRSI;
          if (r < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &y_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          r = muDoubleScalarSqrt(r);
          if (b < 0.0) {
            r = -r;
          }
          r = nrm / (b + r);
        } else {
          r = 0.0;
        }
        r += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[ii] / scale);
        st.site = &jc_emlrtRSI;
        for (k = ii + 1; k <= vectorUB; k++) {
          st.site = &ic_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&r, &nrm, &scale, &sn);
          if (k > ii + 1) {
            e[0] = r;
          }
          nrm = e[k - 1];
          r = S[k - 1];
          sm = scale * r + sn * nrm;
          e[k - 1] = scale * nrm - sn * r;
          sqds = S[k];
          b = sn * sqds;
          sqds *= scale;
          st.site = &hc_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          S[k - 1] = sm;
          nrm = e[k - 1];
          r = scale * nrm + sn * sqds;
          sqds = -sn * nrm + scale * sqds;
          S[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
        }
        e[m] = r;
        iter++;
        break;
      default:
        if (S[ii] < 0.0) {
          S[ii] = -S[ii];
        }
        qp1 = ii + 1;
        while ((ii + 1 < 3) && (S[ii] < S[qp1])) {
          nrm = S[ii];
          S[ii] = S[qp1];
          S[qp1] = nrm;
          ii = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  if (doscale) {
    xzlascl(cscale, anrm, S);
  }
}

/* End of code generation (xzsvdc.c) */
