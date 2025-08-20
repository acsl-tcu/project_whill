/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eigStandard.c
 *
 * Code generation for function 'eigStandard'
 *
 */

/* Include files */
#include "eigStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xdlahqr.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xzgebal.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "xzlascl.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo eo_emlrtRSI = {
    28,        /* lineNo */
    "xzgehrd", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgehrd.m" /* pathName */
};

static emlrtRSInfo fo_emlrtRSI = {
    37,        /* lineNo */
    "xzgehrd", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgehrd.m" /* pathName */
};

static emlrtRSInfo ko_emlrtRSI =
    {
        54,      /* lineNo */
        "xgeev", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeev.m" /* pathName */
};

static emlrtRSInfo lo_emlrtRSI = {
    139,      /* lineNo */
    "xdgeev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdgeev.m" /* pathName */
};

static emlrtRSInfo mo_emlrtRSI = {
    134,      /* lineNo */
    "xdgeev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdgeev.m" /* pathName */
};

static emlrtRSInfo no_emlrtRSI = {
    133,      /* lineNo */
    "xdgeev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdgeev.m" /* pathName */
};

static emlrtRSInfo oo_emlrtRSI = {
    131,      /* lineNo */
    "xdgeev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdgeev.m" /* pathName */
};

static emlrtRSInfo po_emlrtRSI = {
    130,      /* lineNo */
    "xdgeev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdgeev.m" /* pathName */
};

static emlrtRSInfo qo_emlrtRSI = {
    73,       /* lineNo */
    "xdgeev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdgeev.m" /* pathName */
};

static emlrtRSInfo ro_emlrtRSI = {
    67,       /* lineNo */
    "xdgeev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdgeev.m" /* pathName */
};

static emlrtRSInfo so_emlrtRSI = {
    49,       /* lineNo */
    "xdgeev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdgeev.m" /* pathName */
};

static emlrtRSInfo to_emlrtRSI = {
    46,       /* lineNo */
    "xdgeev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdgeev.m" /* pathName */
};

/* Function Definitions */
void eigStandard(const emlrtStack *sp, const real_T A[9], creal_T V[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T a[9];
  real_T tau[2];
  real_T absxk;
  real_T anrm;
  int32_T b_i;
  int32_T i;
  int32_T ihi;
  int32_T lastc;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &io_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &ko_emlrtRSI;
  memcpy(&a[0], &A[0], 9U * sizeof(real_T));
  i = 0;
  anrm = 0.0;
  lastc = 0;
  exitg1 = false;
  while ((!exitg1) && (lastc < 9)) {
    absxk = muDoubleScalarAbs(A[lastc]);
    if (muDoubleScalarIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }
      lastc++;
    }
  }
  if (muDoubleScalarIsInf(anrm) || muDoubleScalarIsNaN(anrm)) {
    V[0].re = rtNaN;
    V[0].im = 0.0;
    V[1].re = rtNaN;
    V[1].im = 0.0;
    V[2].re = rtNaN;
    V[2].im = 0.0;
  } else {
    real_T wi[3];
    real_T work[3];
    real_T cscale;
    real_T ctoc;
    int32_T ilo;
    boolean_T guard1;
    boolean_T scalea;
    cscale = anrm;
    scalea = false;
    guard1 = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      scalea = true;
      cscale = 6.7178761075670888E-139;
      guard1 = true;
    } else if (anrm > 1.4885657073574029E+138) {
      scalea = true;
      cscale = 1.4885657073574029E+138;
      guard1 = true;
    }
    if (guard1) {
      boolean_T notdone;
      c_st.site = &to_emlrtRSI;
      absxk = anrm;
      ctoc = cscale;
      notdone = true;
      while (notdone) {
        __m128d r;
        __m128d r1;
        real_T cfrom1;
        real_T cto1;
        real_T mul;
        cfrom1 = absxk * 2.0041683600089728E-292;
        cto1 = ctoc / 4.9896007738368E+291;
        if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
          mul = 2.0041683600089728E-292;
          absxk = cfrom1;
        } else if (cto1 > absxk) {
          mul = 4.9896007738368E+291;
          ctoc = cto1;
        } else {
          mul = ctoc / absxk;
          notdone = false;
        }
        d_st.site = &yl_emlrtRSI;
        d_st.site = &am_emlrtRSI;
        r = _mm_loadu_pd(&a[0]);
        r1 = _mm_set1_pd(mul);
        _mm_storeu_pd(&a[0], _mm_mul_pd(r, r1));
        a[2] *= mul;
        d_st.site = &am_emlrtRSI;
        r = _mm_loadu_pd(&a[3]);
        _mm_storeu_pd(&a[3], _mm_mul_pd(r, r1));
        a[5] *= mul;
        d_st.site = &am_emlrtRSI;
        r = _mm_loadu_pd(&a[6]);
        _mm_storeu_pd(&a[6], _mm_mul_pd(r, r1));
        a[8] *= mul;
      }
    }
    c_st.site = &so_emlrtRSI;
    ilo = xzgebal(&c_st, a, &ihi, work);
    c_st.site = &ro_emlrtRSI;
    if ((ihi - ilo) + 1 > 1) {
      int32_T b;
      d_st.site = &eo_emlrtRSI;
      if (ilo - 1 > 2147483646) {
        e_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      lastc = (uint8_T)(ilo - 1);
      if (lastc - 1 >= 0) {
        memset(&tau[0], 0, (uint32_T)lastc * sizeof(real_T));
      }
      for (b_i = ihi; b_i < 3; b_i++) {
        tau[b_i - 1] = 0.0;
      }
      work[0] = 0.0;
      work[1] = 0.0;
      work[2] = 0.0;
      b = ihi - 1;
      d_st.site = &fo_emlrtRSI;
      if ((ilo <= ihi - 1) && (ihi - 1 > 2147483646)) {
        e_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (b_i = ilo; b_i <= b; b_i++) {
        int32_T alpha1_tmp_tmp;
        int32_T in;
        int32_T lastv;
        int32_T n;
        lastc = (b_i - 1) * 3;
        in = b_i * 3 + 1;
        alpha1_tmp_tmp = b_i + lastc;
        absxk = a[alpha1_tmp_tmp];
        n = ihi - b_i;
        d_st.site = &om_emlrtRSI;
        ctoc = xzlarfg(&d_st, n, &absxk, a, lastc + 3);
        tau[b_i - 1] = ctoc;
        a[alpha1_tmp_tmp] = 1.0;
        d_st.site = &pm_emlrtRSI;
        if (ctoc != 0.0) {
          lastv = n;
          i = (alpha1_tmp_tmp + n) + 1;
          while ((lastv > 0) && (a[i - 2] == 0.0)) {
            lastv--;
            i--;
          }
          e_st.site = &rm_emlrtRSI;
          lastc = ilazlr(&e_st, ihi, lastv, a, in);
        } else {
          lastv = 0;
          lastc = 0;
        }
        if (lastv > 0) {
          e_st.site = &sm_emlrtRSI;
          xgemv(&e_st, lastc, lastv, a, in, a, alpha1_tmp_tmp + 1, work);
          e_st.site = &tm_emlrtRSI;
          xgerc(&e_st, lastc, lastv, -tau[b_i - 1], work, alpha1_tmp_tmp + 1, a,
                in);
        }
        d_st.site = &qm_emlrtRSI;
        xzlarf(&d_st, n, 3 - b_i, alpha1_tmp_tmp + 1, tau[b_i - 1], a, b_i + in,
               work);
        a[alpha1_tmp_tmp] = absxk;
      }
    }
    c_st.site = &qo_emlrtRSI;
    i = xdlahqr(&c_st, ilo, ihi, a, &absxk, work, wi);
    if (scalea) {
      c_st.site = &po_emlrtRSI;
      xzlascl(&c_st, cscale, anrm, 3 - i, work, i + 1);
      c_st.site = &oo_emlrtRSI;
      xzlascl(&c_st, cscale, anrm, 3 - i, wi, i + 1);
      if (i != 0) {
        c_st.site = &no_emlrtRSI;
        xzlascl(&c_st, cscale, anrm, ilo - 1, work, 1);
        c_st.site = &mo_emlrtRSI;
        xzlascl(&c_st, cscale, anrm, ilo - 1, wi, 1);
      }
    }
    if (i != 0) {
      c_st.site = &lo_emlrtRSI;
      if ((ilo <= i) && (i > 2147483646)) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (b_i = ilo; b_i <= i; b_i++) {
        work[b_i - 1] = rtNaN;
        wi[b_i - 1] = 0.0;
      }
    }
    V[0].re = work[0];
    V[0].im = wi[0];
    V[1].re = work[1];
    V[1].im = wi[1];
    V[2].re = work[2];
    V[2].im = wi[2];
  }
  if (i != 0) {
    st.site = &jo_emlrtRSI;
    warning(&st);
  }
}

/* End of code generation (eigStandard.c) */
