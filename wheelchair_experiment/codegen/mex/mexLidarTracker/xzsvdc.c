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
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xscal.h"
#include "xswap.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>
#include <xmmintrin.h>

/* Variable Definitions */
static emlrtRSInfo wc_emlrtRSI = {
    407,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    394,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    391,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    380,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    353,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    351,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    334,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    120,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo fd_emlrtRSI = {
    114,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    94,       /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo hd_emlrtRSI = {
    82,       /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    77,       /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    21,                   /* lineNo */
    "scaleVectorByRecip", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "scaleVectorByRecip.m" /* pathName */
};

static emlrtRSInfo hs_emlrtRSI = {
    428,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo is_emlrtRSI = {
    251,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo js_emlrtRSI = {
    240,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo ks_emlrtRSI = {
    215,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo ls_emlrtRSI = {
    194,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRSInfo ms_emlrtRSI = {
    184,      /* lineNo */
    "xzsvdc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pathName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    269,      /* lineNo */
    13,       /* colNo */
    "xzsvdc", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzsvdc.m" /* pName */
};

/* Function Definitions */
void b_xzsvdc(const emlrtStack *sp, real32_T A[9], real32_T S[3])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T ii;
  int32_T iter;
  int32_T k;
  int32_T m;
  int32_T q;
  int32_T qq;
  int32_T qs;
  int32_T vectorUB;
  real32_T e[3];
  real32_T s[3];
  real32_T work[3];
  real32_T b;
  real32_T nrm;
  real32_T rt;
  real32_T scale;
  real32_T sm;
  real32_T sn;
  real32_T snorm;
  real32_T sqds;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s[0] = 0.0F;
  e[0] = 0.0F;
  work[0] = 0.0F;
  s[1] = 0.0F;
  e[1] = 0.0F;
  work[1] = 0.0F;
  s[2] = 0.0F;
  e[2] = 0.0F;
  work[2] = 0.0F;
  for (q = 0; q < 2; q++) {
    int32_T qp1_tmp;
    boolean_T apply_transform;
    qp1_tmp = q + 2;
    m = q + 3 * q;
    qq = m + 1;
    apply_transform = false;
    st.site = &id_emlrtRSI;
    nrm = b_xnrm2(&st, 3 - q, A, m + 1);
    if (nrm > 0.0F) {
      apply_transform = true;
      if (A[m] < 0.0F) {
        sqds = -nrm;
      } else {
        sqds = nrm;
      }
      s[q] = sqds;
      st.site = &hd_emlrtRSI;
      if (muSingleScalarAbs(sqds) >= 9.86076132E-32F) {
        b_st.site = &ld_emlrtRSI;
        b_xscal(&b_st, 3 - q, 1.0F / sqds, A, m + 1);
      } else {
        qs = (m - q) + 3;
        iter = ((((qs - m) / 4) << 2) + m) + 1;
        vectorUB = iter - 4;
        for (k = qq; k <= vectorUB; k += 4) {
          __m128 r;
          r = _mm_loadu_ps(&A[k - 1]);
          _mm_storeu_ps(&A[k - 1], _mm_div_ps(r, _mm_set1_ps(s[q])));
        }
        for (k = iter; k <= qs; k++) {
          A[k - 1] /= s[q];
        }
      }
      A[m]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0F;
    }
    for (qs = qp1_tmp; qs < 4; qs++) {
      qq = q + 3 * (qs - 1);
      if (apply_transform) {
        st.site = &gd_emlrtRSI;
        nrm = b_xdotc(&st, 3 - q, A, m + 1, A, qq + 1);
        b_xaxpy(3 - q, -(nrm / A[m]), m + 1, A, qq + 1);
      }
      e[qs - 1] = A[qq];
    }
    if (q + 1 <= 1) {
      st.site = &fd_emlrtRSI;
      nrm = i_xnrm2(e);
      if (nrm == 0.0F) {
        e[0] = 0.0F;
      } else {
        if (e[1] < 0.0F) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        st.site = &ed_emlrtRSI;
        sm = e[0];
        if (muSingleScalarAbs(e[0]) >= 9.86076132E-32F) {
          l_xscal(1.0F / e[0], e);
        } else {
          for (k = qp1_tmp; k < 4; k++) {
            e[k - 1] /= sm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (ii = qp1_tmp; ii < 4; ii++) {
          work[ii - 1] = 0.0F;
        }
        for (qs = qp1_tmp; qs < 4; qs++) {
          h_xaxpy(e[qs - 1], A, 3 * (qs - 1) + 2, work);
        }
        for (qs = qp1_tmp; qs < 4; qs++) {
          i_xaxpy(-e[qs - 1] / e[1], work, A, 3 * (qs - 1) + 2);
        }
      }
    }
  }
  m = 1;
  s[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0F;
  iter = 0;
  sqds = s[0];
  if (s[0] != 0.0F) {
    rt = muSingleScalarAbs(s[0]);
    nrm = s[0] / rt;
    sqds = rt;
    s[0] = rt;
    e[0] /= nrm;
  }
  if (e[0] != 0.0F) {
    rt = muSingleScalarAbs(e[0]);
    nrm = e[0];
    e[0] = rt;
    s[1] *= rt / nrm;
  }
  snorm = muSingleScalarMax(muSingleScalarAbs(sqds), e[0]);
  sqds = s[1];
  if (s[1] != 0.0F) {
    rt = muSingleScalarAbs(s[1]);
    nrm = s[1] / rt;
    sqds = rt;
    s[1] = rt;
    e[1] = A[7] / nrm;
  }
  if (e[1] != 0.0F) {
    rt = muSingleScalarAbs(e[1]);
    nrm = e[1];
    e[1] = rt;
    s[2] = A[8] * (rt / nrm);
  }
  snorm = muSingleScalarMax(snorm,
                            muSingleScalarMax(muSingleScalarAbs(sqds), e[1]));
  sqds = s[2];
  if (s[2] != 0.0F) {
    rt = muSingleScalarAbs(s[2]);
    sqds = rt;
    s[2] = rt;
  }
  snorm = muSingleScalarMax(snorm,
                            muSingleScalarMax(muSingleScalarAbs(sqds), 0.0F));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      boolean_T exitg2;
      vectorUB = m + 1;
      ii = m + 1;
      exitg2 = false;
      while (!(exitg2 || (ii == 0))) {
        nrm = muSingleScalarAbs(e[ii - 1]);
        if ((nrm <= 1.1920929E-7F * (muSingleScalarAbs(s[ii - 1]) +
                                     muSingleScalarAbs(s[ii]))) ||
            (nrm <= 9.86076132E-32F) ||
            ((iter > 20) && (nrm <= 1.1920929E-7F * snorm))) {
          e[ii - 1] = 0.0F;
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
            nrm = 0.0F;
            if (qq < m + 2) {
              nrm = muSingleScalarAbs(e[qq - 1]);
            }
            if (qq > ii + 1) {
              nrm += muSingleScalarAbs(e[qq - 2]);
            }
            rt = muSingleScalarAbs(s[qq - 1]);
            if ((rt <= 1.1920929E-7F * nrm) || (rt <= 9.86076132E-32F)) {
              s[qq - 1] = 0.0F;
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
        rt = e[m];
        e[m] = 0.0F;
        for (k = vectorUB; k >= ii + 1; k--) {
          st.site = &dd_emlrtRSI;
          scale = 0.0F;
          sn = 0.0F;
          srotg(&s[k - 1], &rt, &scale, &sn);
          if (k > ii + 1) {
            rt = -sn * e[0];
            e[0] *= scale;
          }
        }
        break;
      case 2:
        rt = e[ii - 1];
        e[ii - 1] = 0.0F;
        st.site = &cd_emlrtRSI;
        for (k = ii + 1; k <= m + 2; k++) {
          st.site = &bd_emlrtRSI;
          scale = 0.0F;
          sn = 0.0F;
          srotg(&s[k - 1], &rt, &scale, &sn);
          nrm = e[k - 1];
          rt = -sn * nrm;
          e[k - 1] = nrm * scale;
        }
        break;
      case 3:
        nrm = s[m + 1];
        scale = muSingleScalarMax(
            muSingleScalarMax(
                muSingleScalarMax(muSingleScalarMax(muSingleScalarAbs(nrm),
                                                    muSingleScalarAbs(s[m])),
                                  muSingleScalarAbs(e[m])),
                muSingleScalarAbs(s[ii])),
            muSingleScalarAbs(e[ii]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        rt = e[m] / scale;
        sqds = s[ii] / scale;
        b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0F;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b != 0.0F) || (nrm != 0.0F)) {
          rt = b * b + nrm;
          st.site = &ad_emlrtRSI;
          if (rt < 0.0F) {
            emlrtErrorWithMessageIdR2018a(
                &st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          rt = muSingleScalarSqrt(rt);
          if (b < 0.0F) {
            rt = -rt;
          }
          rt = nrm / (b + rt);
        } else {
          rt = 0.0F;
        }
        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[ii] / scale);
        st.site = &yc_emlrtRSI;
        for (k = ii + 1; k <= vectorUB; k++) {
          st.site = &xc_emlrtRSI;
          scale = 0.0F;
          sn = 0.0F;
          srotg(&rt, &nrm, &scale, &sn);
          if (k > ii + 1) {
            e[0] = rt;
          }
          nrm = e[k - 1];
          rt = s[k - 1];
          sm = scale * rt + sn * nrm;
          e[k - 1] = scale * nrm - sn * rt;
          sqds = s[k];
          b = sn * sqds;
          sqds *= scale;
          st.site = &wc_emlrtRSI;
          scale = 0.0F;
          sn = 0.0F;
          srotg(&sm, &b, &scale, &sn);
          s[k - 1] = sm;
          nrm = e[k - 1];
          rt = scale * nrm + sn * sqds;
          sqds = -sn * nrm + scale * sqds;
          s[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
        }
        e[m] = rt;
        iter++;
        break;
      default:
        if (s[ii] < 0.0F) {
          s[ii] = -s[ii];
        }
        qq = ii + 1;
        while ((ii + 1 < 3) && (s[ii] < s[qq])) {
          rt = s[ii];
          s[ii] = s[qq];
          s[qq] = rt;
          ii = qq;
          qq++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
}

void c_xzsvdc(const emlrtStack *sp, real_T A[36], real_T U[36], real_T S[6],
              real_T V[36])
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack st;
  real_T e[6];
  real_T s[6];
  real_T work[6];
  real_T b;
  real_T nrm;
  real_T rt;
  real_T scale;
  real_T sm;
  real_T sn;
  real_T snorm;
  real_T sqds;
  int32_T b_i;
  int32_T i;
  int32_T ii;
  int32_T iter;
  int32_T k;
  int32_T m;
  int32_T q;
  int32_T qp1;
  int32_T qp1jj;
  int32_T qq;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 6; i++) {
    s[i] = 0.0;
    e[i] = 0.0;
    work[i] = 0.0;
  }
  memset(&U[0], 0, 36U * sizeof(real_T));
  memset(&V[0], 0, 36U * sizeof(real_T));
  for (q = 0; q < 5; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qp1jj = q + 6 * q;
    qq = qp1jj + 1;
    apply_transform = false;
    st.site = &id_emlrtRSI;
    nrm = d_xnrm2(&st, 6 - q, A, qp1jj + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[qp1jj] < 0.0) {
        sqds = -nrm;
      } else {
        sqds = nrm;
      }
      s[q] = sqds;
      st.site = &hd_emlrtRSI;
      if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
        b_st.site = &ld_emlrtRSI;
        e_xscal(&b_st, 6 - q, 1.0 / sqds, A, qp1jj + 1);
      } else {
        b_i = (qp1jj - q) + 6;
        iter = ((((b_i - qp1jj) / 2) << 1) + qp1jj) + 1;
        i = iter - 2;
        for (k = qq; k <= i; k += 2) {
          r = _mm_loadu_pd(&A[k - 1]);
          _mm_storeu_pd(&A[k - 1], _mm_div_pd(r, _mm_set1_pd(s[q])));
        }
        for (k = iter; k <= b_i; k++) {
          A[k - 1] /= s[q];
        }
      }
      A[qp1jj]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (iter = qp1; iter < 7; iter++) {
      i = q + 6 * (iter - 1);
      if (apply_transform) {
        st.site = &gd_emlrtRSI;
        nrm = c_xdotc(&st, 6 - q, A, qp1jj + 1, A, i + 1);
        nrm = -(nrm / A[qp1jj]);
        c_xaxpy(6 - q, nrm, qp1jj + 1, A, i + 1);
      }
      e[iter - 1] = A[i];
    }
    for (ii = q + 1; ii < 7; ii++) {
      i = (ii + 6 * q) - 1;
      U[i] = A[i];
    }
    if (q + 1 <= 4) {
      st.site = &fd_emlrtRSI;
      nrm = e_xnrm2(&st, 5 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }
        st.site = &ed_emlrtRSI;
        sm = e[q];
        if (muDoubleScalarAbs(e[q]) >= 1.0020841800044864E-292) {
          b_st.site = &ld_emlrtRSI;
          f_xscal(&b_st, 5 - q, 1.0 / e[q], e, q + 2);
        } else {
          iter = ((((5 - q) / 2) << 1) + q) + 2;
          i = iter - 2;
          for (k = qp1; k <= i; k += 2) {
            r = _mm_loadu_pd(&e[k - 1]);
            _mm_storeu_pd(&e[k - 1], _mm_div_pd(r, _mm_set1_pd(sm)));
          }
          for (k = iter; k < 7; k++) {
            e[k - 1] /= sm;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (ii = qp1; ii < 7; ii++) {
          work[ii - 1] = 0.0;
        }
        for (iter = qp1; iter < 7; iter++) {
          d_xaxpy(5 - q, e[iter - 1], A, (q + 6 * (iter - 1)) + 2, work, q + 2);
        }
        for (iter = qp1; iter < 7; iter++) {
          e_xaxpy(5 - q, -e[iter - 1] / e[q + 1], work, q + 2, A,
                  (q + 6 * (iter - 1)) + 2);
        }
      }
      for (ii = qp1; ii < 7; ii++) {
        V[(ii + 6 * q) - 1] = e[ii - 1];
      }
    }
  }
  m = 4;
  s[5] = A[35];
  e[4] = A[34];
  e[5] = 0.0;
  for (ii = 0; ii < 6; ii++) {
    U[ii + 30] = 0.0;
  }
  U[35] = 1.0;
  for (q = 4; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 6 * q;
    if (s[q] != 0.0) {
      for (iter = qp1; iter < 7; iter++) {
        i = (q + 6 * (iter - 1)) + 1;
        st.site = &ms_emlrtRSI;
        nrm = c_xdotc(&st, 6 - q, U, qq + 1, U, i);
        nrm = -(nrm / U[qq]);
        c_xaxpy(6 - q, nrm, qq + 1, U, i);
      }
      iter = ((((6 - q) / 2) << 1) + q) + 1;
      i = iter - 2;
      for (ii = q + 1; ii <= i; ii += 2) {
        b_i = (ii + 6 * q) - 1;
        r = _mm_loadu_pd(&U[b_i]);
        _mm_storeu_pd(&U[b_i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
      }
      for (ii = iter; ii < 7; ii++) {
        i = (ii + 6 * q) - 1;
        U[i] = -U[i];
      }
      U[qq]++;
      st.site = &ls_emlrtRSI;
      for (ii = 0; ii < q; ii++) {
        U[ii + 6 * q] = 0.0;
      }
    } else {
      for (ii = 0; ii < 6; ii++) {
        U[ii + 6 * q] = 0.0;
      }
      U[qq] = 1.0;
    }
  }
  for (q = 5; q >= 0; q--) {
    if ((q + 1 <= 4) && (e[q] != 0.0)) {
      qp1 = q + 2;
      i = (q + 6 * q) + 2;
      for (iter = qp1; iter < 7; iter++) {
        qp1jj = (q + 6 * (iter - 1)) + 2;
        st.site = &ks_emlrtRSI;
        nrm = c_xdotc(&st, 5 - q, V, i, V, qp1jj);
        nrm = -(nrm / V[i - 1]);
        c_xaxpy(5 - q, nrm, i, V, qp1jj);
      }
    }
    for (ii = 0; ii < 6; ii++) {
      V[ii + 6 * q] = 0.0;
    }
    V[q + 6 * q] = 1.0;
  }
  for (q = 0; q < 6; q++) {
    sqds = s[q];
    if (sqds != 0.0) {
      rt = muDoubleScalarAbs(sqds);
      nrm = sqds / rt;
      s[q] = rt;
      if (q + 1 < 6) {
        e[q] /= nrm;
      }
      st.site = &js_emlrtRSI;
      g_xscal(&st, nrm, U, 6 * q + 1);
    }
    if (q + 1 < 6) {
      sqds = e[q];
      if (sqds != 0.0) {
        rt = muDoubleScalarAbs(sqds);
        nrm = rt / sqds;
        e[q] = rt;
        s[q + 1] *= nrm;
        st.site = &is_emlrtRSI;
        g_xscal(&st, nrm, V, 6 * (q + 1) + 1);
      }
    }
  }
  iter = 0;
  snorm = 0.0;
  for (ii = 0; ii < 6; ii++) {
    snorm =
        muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(s[ii]),
                                                   muDoubleScalarAbs(e[ii])));
  }
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      boolean_T exitg2;
      qq = m + 1;
      ii = m + 1;
      exitg2 = false;
      while (!(exitg2 || (ii == 0))) {
        nrm = muDoubleScalarAbs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[ii - 1]) +
                                              muDoubleScalarAbs(s[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg2 = true;
        } else {
          ii--;
        }
      }
      if (ii == m + 1) {
        i = 4;
      } else {
        qp1jj = m + 2;
        i = m + 2;
        exitg2 = false;
        while ((!exitg2) && (i >= ii)) {
          qp1jj = i;
          if (i == ii) {
            exitg2 = true;
          } else {
            nrm = 0.0;
            if (i < m + 2) {
              nrm = muDoubleScalarAbs(e[i - 1]);
            }
            if (i > ii + 1) {
              nrm += muDoubleScalarAbs(e[i - 2]);
            }
            rt = muDoubleScalarAbs(s[i - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s[i - 1] = 0.0;
              exitg2 = true;
            } else {
              i--;
            }
          }
        }
        if (qp1jj == ii) {
          i = 3;
        } else if (qp1jj == m + 2) {
          i = 1;
        } else {
          i = 2;
          ii = qp1jj;
        }
      }
      switch (i) {
      case 1:
        rt = e[m];
        e[m] = 0.0;
        for (k = qq; k >= ii + 1; k--) {
          st.site = &dd_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &rt, &scale, &sn);
          if (k > ii + 1) {
            nrm = e[k - 2];
            rt = -sn * nrm;
            e[k - 2] = nrm * scale;
          }
          xrot(V, 6 * (k - 1) + 1, 6 * (m + 1) + 1, scale, sn);
        }
        break;
      case 2:
        rt = e[ii - 1];
        e[ii - 1] = 0.0;
        st.site = &cd_emlrtRSI;
        for (k = ii + 1; k <= m + 2; k++) {
          st.site = &bd_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &rt, &scale, &sn);
          nrm = e[k - 1];
          rt = -sn * nrm;
          e[k - 1] = nrm * scale;
          xrot(U, 6 * (k - 1) + 1, 6 * (ii - 1) + 1, scale, sn);
        }
        break;
      case 3:
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[ii])),
            muDoubleScalarAbs(e[ii]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        rt = e[m] / scale;
        sqds = s[ii] / scale;
        b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          st.site = &ad_emlrtRSI;
          if (rt < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          rt = muDoubleScalarSqrt(rt);
          if (b < 0.0) {
            rt = -rt;
          }
          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }
        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[ii] / scale);
        st.site = &yc_emlrtRSI;
        for (k = ii + 1; k <= qq; k++) {
          st.site = &xc_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&rt, &nrm, &scale, &sn);
          if (k > ii + 1) {
            e[k - 2] = rt;
          }
          nrm = e[k - 1];
          rt = s[k - 1];
          sm = scale * rt + sn * nrm;
          e[k - 1] = scale * nrm - sn * rt;
          sqds = s[k];
          b = sn * sqds;
          sqds *= scale;
          b_i = 6 * (k - 1) + 1;
          i = 6 * k + 1;
          xrot(V, b_i, i, scale, sn);
          st.site = &wc_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          s[k - 1] = sm;
          nrm = e[k - 1];
          rt = scale * nrm + sn * sqds;
          sqds = -sn * nrm + scale * sqds;
          s[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
          xrot(U, b_i, i, scale, sn);
        }
        e[m] = rt;
        iter++;
        break;
      default:
        if (s[ii] < 0.0) {
          s[ii] = -s[ii];
          st.site = &hs_emlrtRSI;
          g_xscal(&st, -1.0, V, 6 * ii + 1);
        }
        qp1 = ii + 1;
        while ((ii + 1 < 6) && (s[ii] < s[qp1])) {
          rt = s[ii];
          s[ii] = s[qp1];
          s[qp1] = rt;
          b_i = 6 * ii + 1;
          i = 6 * (ii + 1) + 1;
          b_xswap(V, b_i, i);
          b_xswap(U, b_i, i);
          ii = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  for (k = 0; k < 6; k++) {
    S[k] = s[k];
  }
}

void d_xzsvdc(const emlrtStack *sp, real_T A[9], real_T U[9], real_T S[3],
              real_T V[9])
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack st;
  real_T e[3];
  real_T s[3];
  real_T work[3];
  real_T b;
  real_T f;
  real_T nrm;
  real_T rt;
  real_T scale;
  real_T snorm;
  real_T sqds;
  int32_T i;
  int32_T ii;
  int32_T iter;
  int32_T k;
  int32_T m;
  int32_T q;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  int32_T qs;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  memset(&U[0], 0, 9U * sizeof(real_T));
  memset(&V[0], 0, 9U * sizeof(real_T));
  for (q = 0; q < 2; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qs = q + 3 * q;
    qq = qs + 1;
    apply_transform = false;
    st.site = &id_emlrtRSI;
    nrm = xnrm2(&st, 3 - q, A, qs + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[qs] < 0.0) {
        rt = -nrm;
      } else {
        rt = nrm;
      }
      s[q] = rt;
      st.site = &hd_emlrtRSI;
      if (muDoubleScalarAbs(rt) >= 1.0020841800044864E-292) {
        b_st.site = &ld_emlrtRSI;
        xscal(&b_st, 3 - q, 1.0 / rt, A, qs + 1);
      } else {
        i = (qs - q) + 3;
        iter = ((((i - qs) / 2) << 1) + qs) + 1;
        qjj = iter - 2;
        for (k = qq; k <= qjj; k += 2) {
          r = _mm_loadu_pd(&A[k - 1]);
          _mm_storeu_pd(&A[k - 1], _mm_div_pd(r, _mm_set1_pd(s[q])));
        }
        for (k = iter; k <= i; k++) {
          A[k - 1] /= s[q];
        }
      }
      A[qs]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (iter = qp1; iter < 4; iter++) {
      qjj = q + 3 * (iter - 1);
      if (apply_transform) {
        st.site = &gd_emlrtRSI;
        nrm = xdotc(&st, 3 - q, A, qs + 1, A, qjj + 1);
        nrm = -(nrm / A[qs]);
        xaxpy(3 - q, nrm, qs + 1, A, qjj + 1);
      }
      e[iter - 1] = A[qjj];
    }
    for (ii = q + 1; ii < 4; ii++) {
      qjj = (ii + 3 * q) - 1;
      U[qjj] = A[qjj];
    }
    if (q + 1 <= 1) {
      st.site = &fd_emlrtRSI;
      nrm = h_xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        st.site = &ed_emlrtRSI;
        f = e[0];
        if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
          k_xscal(1.0 / e[0], e);
        } else {
          iter = ((((2 - q) / 2) << 1) + q) + 2;
          qjj = iter - 2;
          for (k = qp1; k <= qjj; k += 2) {
            r = _mm_loadu_pd(&e[k - 1]);
            _mm_storeu_pd(&e[k - 1], _mm_div_pd(r, _mm_set1_pd(f)));
          }
          for (k = iter; k < 4; k++) {
            e[k - 1] /= f;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (ii = qp1; ii < 4; ii++) {
          work[ii - 1] = 0.0;
        }
        for (iter = qp1; iter < 4; iter++) {
          f_xaxpy(e[iter - 1], A, 3 * (iter - 1) + 2, work);
        }
        for (iter = qp1; iter < 4; iter++) {
          g_xaxpy(-e[iter - 1] / e[1], work, A, 3 * (iter - 1) + 2);
        }
      }
      for (ii = qp1; ii < 4; ii++) {
        V[ii - 1] = e[ii - 1];
      }
    }
  }
  m = 1;
  s[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (q = 1; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 3 * q;
    if (s[q] != 0.0) {
      for (iter = qp1; iter < 4; iter++) {
        qjj = (q + 3 * (iter - 1)) + 1;
        st.site = &ms_emlrtRSI;
        nrm = xdotc(&st, 3 - q, U, qq + 1, U, qjj);
        nrm = -(nrm / U[qq]);
        xaxpy(3 - q, nrm, qq + 1, U, qjj);
      }
      iter = q + 3;
      qjj = q + 1;
      for (ii = q + 1; ii <= qjj; ii += 2) {
        i = (ii + 3 * q) - 1;
        r = _mm_loadu_pd(&U[i]);
        _mm_storeu_pd(&U[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
      }
      qjj = 3 * q + 2;
      for (ii = iter; ii < 4; ii++) {
        U[qjj] = -U[qjj];
      }
      U[qq]++;
      st.site = &ls_emlrtRSI;
      if (q - 1 >= 0) {
        U[3 * q] = 0.0;
      }
    } else {
      U[3 * q] = 0.0;
      U[3 * q + 1] = 0.0;
      U[3 * q + 2] = 0.0;
      U[qq] = 1.0;
    }
  }
  for (q = 2; q >= 0; q--) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      st.site = &ks_emlrtRSI;
      nrm = xdotc(&st, 2, V, 2, V, 5);
      nrm = -(nrm / V[1]);
      xaxpy(2, nrm, 2, V, 5);
      st.site = &ks_emlrtRSI;
      nrm = xdotc(&st, 2, V, 2, V, 8);
      nrm = -(nrm / V[1]);
      xaxpy(2, nrm, 2, V, 8);
    }
    V[3 * q] = 0.0;
    V[3 * q + 1] = 0.0;
    V[3 * q + 2] = 0.0;
    V[q + 3 * q] = 1.0;
  }
  if (s[0] != 0.0) {
    rt = muDoubleScalarAbs(s[0]);
    nrm = s[0] / rt;
    s[0] = rt;
    e[0] /= nrm;
    st.site = &js_emlrtRSI;
    h_xscal(&st, nrm, U, 1);
  }
  if (e[0] != 0.0) {
    rt = muDoubleScalarAbs(e[0]);
    nrm = rt / e[0];
    e[0] = rt;
    s[1] *= nrm;
    st.site = &is_emlrtRSI;
    h_xscal(&st, nrm, V, 4);
  }
  if (s[1] != 0.0) {
    rt = muDoubleScalarAbs(s[1]);
    nrm = s[1] / rt;
    s[1] = rt;
    e[1] = A[7] / nrm;
    st.site = &js_emlrtRSI;
    h_xscal(&st, nrm, U, 4);
  }
  if (e[1] != 0.0) {
    rt = muDoubleScalarAbs(e[1]);
    nrm = rt / e[1];
    e[1] = rt;
    s[2] = A[8] * nrm;
    st.site = &is_emlrtRSI;
    h_xscal(&st, nrm, V, 7);
  }
  if (s[2] != 0.0) {
    rt = muDoubleScalarAbs(s[2]);
    nrm = s[2] / rt;
    s[2] = rt;
    st.site = &js_emlrtRSI;
    h_xscal(&st, nrm, U, 7);
  }
  iter = 0;
  snorm = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax(s[0], e[0]),
                                              muDoubleScalarMax(s[1], e[1])),
                            muDoubleScalarMax(s[2], 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      boolean_T exitg2;
      qq = m + 1;
      ii = m + 1;
      exitg2 = false;
      while (!(exitg2 || (ii == 0))) {
        nrm = muDoubleScalarAbs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[ii - 1]) +
                                              muDoubleScalarAbs(s[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg2 = true;
        } else {
          ii--;
        }
      }
      if (ii == m + 1) {
        qjj = 4;
      } else {
        qs = m + 2;
        qjj = m + 2;
        exitg2 = false;
        while ((!exitg2) && (qjj >= ii)) {
          qs = qjj;
          if (qjj == ii) {
            exitg2 = true;
          } else {
            nrm = 0.0;
            if (qjj < m + 2) {
              nrm = muDoubleScalarAbs(e[qjj - 1]);
            }
            if (qjj > ii + 1) {
              nrm += muDoubleScalarAbs(e[qjj - 2]);
            }
            rt = muDoubleScalarAbs(s[qjj - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s[qjj - 1] = 0.0;
              exitg2 = true;
            } else {
              qjj--;
            }
          }
        }
        if (qs == ii) {
          qjj = 3;
        } else if (qs == m + 2) {
          qjj = 1;
        } else {
          qjj = 2;
          ii = qs;
        }
      }
      switch (qjj) {
      case 1:
        f = e[m];
        e[m] = 0.0;
        for (k = qq; k >= ii + 1; k--) {
          st.site = &dd_emlrtRSI;
          sqds = 0.0;
          scale = 0.0;
          drotg(&s[k - 1], &f, &sqds, &scale);
          if (k > ii + 1) {
            f = -scale * e[0];
            e[0] *= sqds;
          }
          b_xrot(V, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sqds, scale);
        }
        break;
      case 2:
        f = e[ii - 1];
        e[ii - 1] = 0.0;
        st.site = &cd_emlrtRSI;
        for (k = ii + 1; k <= m + 2; k++) {
          st.site = &bd_emlrtRSI;
          sqds = 0.0;
          scale = 0.0;
          drotg(&s[k - 1], &f, &sqds, &scale);
          nrm = e[k - 1];
          f = -scale * nrm;
          e[k - 1] = nrm * sqds;
          b_xrot(U, 3 * (k - 1) + 1, 3 * (ii - 1) + 1, sqds, scale);
        }
        break;
      case 3:
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[ii])),
            muDoubleScalarAbs(e[ii]));
        f = nrm / scale;
        nrm = s[m] / scale;
        rt = e[m] / scale;
        sqds = s[ii] / scale;
        b = ((nrm + f) * (nrm - f) + rt * rt) / 2.0;
        nrm = f * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          st.site = &ad_emlrtRSI;
          if (rt < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          rt = muDoubleScalarSqrt(rt);
          if (b < 0.0) {
            rt = -rt;
          }
          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }
        f = (sqds + f) * (sqds - f) + rt;
        nrm = sqds * (e[ii] / scale);
        st.site = &yc_emlrtRSI;
        for (k = ii + 1; k <= qq; k++) {
          st.site = &xc_emlrtRSI;
          sqds = 0.0;
          scale = 0.0;
          drotg(&f, &nrm, &sqds, &scale);
          if (k > ii + 1) {
            e[0] = f;
          }
          nrm = e[k - 1];
          rt = s[k - 1];
          f = sqds * rt + scale * nrm;
          e[k - 1] = sqds * nrm - scale * rt;
          rt = s[k];
          b = scale * rt;
          rt *= sqds;
          i = 3 * (k - 1) + 1;
          qjj = 3 * k + 1;
          b_xrot(V, i, qjj, sqds, scale);
          st.site = &wc_emlrtRSI;
          sqds = 0.0;
          scale = 0.0;
          drotg(&f, &b, &sqds, &scale);
          s[k - 1] = f;
          nrm = e[k - 1];
          f = sqds * nrm + scale * rt;
          rt = -scale * nrm + sqds * rt;
          s[k] = rt;
          nrm = scale * e[k];
          e[k] *= sqds;
          b_xrot(U, i, qjj, sqds, scale);
        }
        e[m] = f;
        iter++;
        break;
      default:
        if (s[ii] < 0.0) {
          s[ii] = -s[ii];
          st.site = &hs_emlrtRSI;
          h_xscal(&st, -1.0, V, 3 * ii + 1);
        }
        qp1 = ii + 1;
        while ((ii + 1 < 3) && (s[ii] < s[qp1])) {
          rt = s[ii];
          s[ii] = s[qp1];
          s[qp1] = rt;
          i = 3 * ii + 1;
          qjj = 3 * (ii + 1) + 1;
          c_xswap(V, i, qjj);
          c_xswap(U, i, qjj);
          ii = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
}

void xzsvdc(const emlrtStack *sp, real_T A[9], real_T S[3])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T e[3];
  real_T s[3];
  real_T work[3];
  real_T b;
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
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (q = 0; q < 2; q++) {
    __m128d b_r;
    boolean_T apply_transform;
    qp1 = q + 2;
    m = q + 3 * q;
    qq = m + 1;
    apply_transform = false;
    st.site = &id_emlrtRSI;
    nrm = xnrm2(&st, 3 - q, A, m + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[m] < 0.0) {
        sqds = -nrm;
      } else {
        sqds = nrm;
      }
      s[q] = sqds;
      st.site = &hd_emlrtRSI;
      if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
        b_st.site = &ld_emlrtRSI;
        xscal(&b_st, 3 - q, 1.0 / sqds, A, m + 1);
      } else {
        qs = (m - q) + 3;
        iter = ((((qs - m) / 2) << 1) + m) + 1;
        vectorUB = iter - 2;
        for (k = qq; k <= vectorUB; k += 2) {
          b_r = _mm_loadu_pd(&A[k - 1]);
          _mm_storeu_pd(&A[k - 1], _mm_div_pd(b_r, _mm_set1_pd(s[q])));
        }
        for (k = iter; k <= qs; k++) {
          A[k - 1] /= s[q];
        }
      }
      A[m]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (qs = qp1; qs < 4; qs++) {
      qq = q + 3 * (qs - 1);
      if (apply_transform) {
        st.site = &gd_emlrtRSI;
        nrm = xdotc(&st, 3 - q, A, m + 1, A, qq + 1);
        nrm = -(nrm / A[m]);
        xaxpy(3 - q, nrm, m + 1, A, qq + 1);
      }
      e[qs - 1] = A[qq];
    }
    if (q + 1 <= 1) {
      st.site = &fd_emlrtRSI;
      nrm = h_xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        st.site = &ed_emlrtRSI;
        sm = e[0];
        if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
          k_xscal(1.0 / e[0], e);
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
          f_xaxpy(e[qs - 1], A, 3 * (qs - 1) + 2, work);
        }
        for (qs = qp1; qs < 4; qs++) {
          g_xaxpy(-e[qs - 1] / e[1], work, A, 3 * (qs - 1) + 2);
        }
      }
    }
  }
  m = 1;
  s[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0;
  iter = 0;
  sqds = s[0];
  if (s[0] != 0.0) {
    nrm = muDoubleScalarAbs(s[0]);
    r = s[0] / nrm;
    sqds = nrm;
    s[0] = nrm;
    e[0] /= r;
  }
  if (e[0] != 0.0) {
    nrm = muDoubleScalarAbs(e[0]);
    r = nrm / e[0];
    e[0] = nrm;
    s[1] *= r;
  }
  snorm = muDoubleScalarMax(muDoubleScalarAbs(sqds), e[0]);
  sqds = s[1];
  if (s[1] != 0.0) {
    nrm = muDoubleScalarAbs(s[1]);
    r = s[1] / nrm;
    sqds = nrm;
    s[1] = nrm;
    e[1] = A[7] / r;
  }
  if (e[1] != 0.0) {
    nrm = muDoubleScalarAbs(e[1]);
    r = nrm / e[1];
    e[1] = nrm;
    s[2] = A[8] * r;
  }
  snorm = muDoubleScalarMax(snorm,
                            muDoubleScalarMax(muDoubleScalarAbs(sqds), e[1]));
  sqds = s[2];
  if (s[2] != 0.0) {
    nrm = muDoubleScalarAbs(s[2]);
    sqds = nrm;
    s[2] = nrm;
  }
  snorm =
      muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(sqds), 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      boolean_T exitg2;
      vectorUB = m + 1;
      ii = m + 1;
      exitg2 = false;
      while (!(exitg2 || (ii == 0))) {
        nrm = muDoubleScalarAbs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[ii - 1]) +
                                              muDoubleScalarAbs(s[ii]))) ||
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
            r = muDoubleScalarAbs(s[qq - 1]);
            if ((r <= 2.2204460492503131E-16 * nrm) ||
                (r <= 1.0020841800044864E-292)) {
              s[qq - 1] = 0.0;
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
          st.site = &dd_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &r, &scale, &sn);
          if (k > ii + 1) {
            r = -sn * e[0];
            e[0] *= scale;
          }
        }
        break;
      case 2:
        r = e[ii - 1];
        e[ii - 1] = 0.0;
        st.site = &cd_emlrtRSI;
        for (k = ii + 1; k <= m + 2; k++) {
          st.site = &bd_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &r, &scale, &sn);
          nrm = e[k - 1];
          r = -sn * nrm;
          e[k - 1] = nrm * scale;
        }
        break;
      case 3:
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[ii])),
            muDoubleScalarAbs(e[ii]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        r = e[m] / scale;
        sqds = s[ii] / scale;
        b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
        nrm = sm * r;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          r = b * b + nrm;
          st.site = &ad_emlrtRSI;
          if (r < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
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
        st.site = &yc_emlrtRSI;
        for (k = ii + 1; k <= vectorUB; k++) {
          st.site = &xc_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&r, &nrm, &scale, &sn);
          if (k > ii + 1) {
            e[0] = r;
          }
          nrm = e[k - 1];
          r = s[k - 1];
          sm = scale * r + sn * nrm;
          e[k - 1] = scale * nrm - sn * r;
          sqds = s[k];
          b = sn * sqds;
          sqds *= scale;
          st.site = &wc_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          s[k - 1] = sm;
          nrm = e[k - 1];
          r = scale * nrm + sn * sqds;
          sqds = -sn * nrm + scale * sqds;
          s[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
        }
        e[m] = r;
        iter++;
        break;
      default:
        if (s[ii] < 0.0) {
          s[ii] = -s[ii];
        }
        qp1 = ii + 1;
        while ((ii + 1 < 3) && (s[ii] < s[qp1])) {
          nrm = s[ii];
          s[ii] = s[qp1];
          s[qp1] = nrm;
          ii = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
}

/* End of code generation (xzsvdc.c) */
