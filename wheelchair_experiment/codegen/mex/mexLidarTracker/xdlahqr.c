/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdlahqr.c
 *
 * Code generation for function 'xdlahqr'
 *
 */

/* Include files */
#include "xdlahqr.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xzlarfg.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo ln_emlrtRSI = {
    337,       /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

static emlrtRSInfo mn_emlrtRSI = {
    301,       /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

static emlrtRSInfo nn_emlrtRSI = {
    273,       /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

static emlrtRSInfo pn_emlrtRSI = {
    240,       /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

static emlrtRSInfo qn_emlrtRSI = {
    226,       /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

static emlrtRSInfo rn_emlrtRSI = {
    172,       /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

static emlrtRSInfo sn_emlrtRSI = {
    33,        /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

static emlrtRSInfo tn_emlrtRSI = {
    16,        /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

static emlrtRSInfo go_emlrtRSI = {
    292,       /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

static emlrtRSInfo ho_emlrtRSI = {
    264,       /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

/* Function Definitions */
int32_T xdlahqr(const emlrtStack *sp, int32_T ilo, int32_T ihi, real_T h[9],
                real_T *z, real_T wr[3], real_T wi[3])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T v[3];
  real_T aa;
  real_T d;
  real_T h12;
  real_T h22;
  real_T rt1r;
  real_T tr;
  real_T tst;
  int32_T b_i;
  int32_T b_k;
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  *z = 1.0;
  info = 0;
  st.site = &tn_emlrtRSI;
  if (ilo - 1 > 2147483646) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)(ilo - 1);
  for (b_i = 0; b_i < i; b_i++) {
    wr[b_i] = h[b_i + 3 * b_i];
    wi[b_i] = 0.0;
  }
  i = ihi + 1;
  for (b_i = i; b_i < 4; b_i++) {
    wr[b_i - 1] = h[(b_i + 3 * (b_i - 1)) - 1];
    wi[b_i - 1] = 0.0;
  }
  if (ilo == ihi) {
    wr[ilo - 1] = h[(ilo + 3 * (ilo - 1)) - 1];
    wi[ilo - 1] = 0.0;
  } else {
    real_T smlnum;
    int32_T kdefl;
    boolean_T exitg1;
    st.site = &sn_emlrtRSI;
    if ((ilo <= ihi - 3) && (ihi - 3 > 2147483646)) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    if (ilo <= ihi - 2) {
      h[ihi - 1] = 0.0;
    }
    smlnum = 2.2250738585072014E-308 *
             ((real_T)((ihi - ilo) + 1) / 2.2204460492503131E-16);
    kdefl = 0;
    b_i = ihi - 1;
    exitg1 = false;
    while ((!exitg1) && (b_i + 1 >= ilo)) {
      int32_T its;
      int32_T ix0;
      int32_T l;
      boolean_T converged;
      boolean_T exitg2;
      l = ilo;
      converged = false;
      its = 0;
      exitg2 = false;
      while ((!exitg2) && (its < 301)) {
        real_T rt2r;
        real_T s;
        int32_T nr;
        boolean_T exitg3;
        k = b_i;
        exitg3 = false;
        while ((!exitg3) && (k + 1 > l)) {
          i = k + 3 * (k - 1);
          d = muDoubleScalarAbs(h[i]);
          if (d <= smlnum) {
            exitg3 = true;
          } else {
            nr = k + 3 * k;
            aa = h[nr];
            tr = muDoubleScalarAbs(aa);
            h12 = h[i - 1];
            tst = muDoubleScalarAbs(h12) + tr;
            if (tst == 0.0) {
              if (k - 1 >= ilo) {
                tst = muDoubleScalarAbs(h[k - 1]);
              }
              if (k + 2 <= ihi) {
                tst += muDoubleScalarAbs(h[3 * k + 2]);
              }
            }
            if (d <= 2.2204460492503131E-16 * tst) {
              rt2r = muDoubleScalarAbs(h[nr - 1]);
              tst = muDoubleScalarAbs(h12 - aa);
              aa = muDoubleScalarMax(tr, tst);
              tst = muDoubleScalarMin(tr, tst);
              s = aa + tst;
              if (muDoubleScalarMin(d, rt2r) *
                      (muDoubleScalarMax(d, rt2r) / s) <=
                  muDoubleScalarMax(smlnum, 2.2204460492503131E-16 *
                                                (tst * (aa / s)))) {
                exitg3 = true;
              } else {
                k--;
              }
            } else {
              k--;
            }
          }
        }
        l = k + 1;
        if (k + 1 > ilo) {
          h[k + 3 * (k - 1)] = 0.0;
        }
        if (k + 1 >= b_i) {
          converged = true;
          exitg2 = true;
        } else {
          __m128d r;
          int32_T m;
          kdefl++;
          if (kdefl - kdefl / 20 * 20 == 0) {
            s = muDoubleScalarAbs(h[b_i + 3 * (b_i - 1)]) +
                muDoubleScalarAbs(h[b_i - 1]);
            tst = 0.75 * s + h[b_i + 3 * b_i];
            h12 = -0.4375 * s;
            aa = s;
            h22 = tst;
          } else if (kdefl - kdefl / 10 * 10 == 0) {
            s = muDoubleScalarAbs(h[1]) + muDoubleScalarAbs(h[5]);
            tst = 0.75 * s + h[0];
            h12 = -0.4375 * s;
            aa = s;
            h22 = tst;
          } else {
            nr = b_i + 3 * (b_i - 1);
            tst = h[nr - 1];
            aa = h[nr];
            nr = b_i + 3 * b_i;
            h12 = h[nr - 1];
            h22 = h[nr];
          }
          s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(h12)) +
               muDoubleScalarAbs(aa)) +
              muDoubleScalarAbs(h22);
          if (s == 0.0) {
            rt1r = 0.0;
            tst = 0.0;
            rt2r = 0.0;
            h12 = 0.0;
          } else {
            tst /= s;
            aa /= s;
            h12 /= s;
            h22 /= s;
            tr = (tst + h22) / 2.0;
            tst = (tst - tr) * (h22 - tr) - h12 * aa;
            h12 = muDoubleScalarAbs(tst);
            st.site = &rn_emlrtRSI;
            if (h12 < 0.0) {
              emlrtErrorWithMessageIdR2018a(
                  &st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                  "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }
            h12 = muDoubleScalarSqrt(h12);
            if (tst >= 0.0) {
              rt1r = tr * s;
              rt2r = rt1r;
              tst = h12 * s;
              h12 = -tst;
            } else {
              rt1r = tr + h12;
              rt2r = tr - h12;
              if (muDoubleScalarAbs(rt1r - h22) <=
                  muDoubleScalarAbs(rt2r - h22)) {
                rt1r *= s;
                rt2r = rt1r;
              } else {
                rt2r *= s;
                rt1r = rt2r;
              }
              tst = 0.0;
              h12 = 0.0;
            }
          }
          m = b_i - 1;
          if (b_i - 1 >= 1) {
            aa = h[0] - rt2r;
            s = (muDoubleScalarAbs(aa) + muDoubleScalarAbs(h12)) +
                muDoubleScalarAbs(h[1]);
            tr = h[1] / s;
            v[0] = (tr * h[3] + (h[0] - rt1r) * (aa / s)) - tst * (h12 / s);
            v[1] = tr * (((h[0] + h[4]) - rt1r) - rt2r);
            v[2] = tr * h[5];
            s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
                muDoubleScalarAbs(v[2]);
            r = _mm_loadu_pd(&v[0]);
            _mm_storeu_pd(&v[0], _mm_div_pd(r, _mm_set1_pd(s)));
            v[2] /= s;
          }
          st.site = &qn_emlrtRSI;
          if ((b_i - 1 <= b_i) && (b_i > 2147483646)) {
            b_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (k = m; k <= b_i; k++) {
            i = (b_i - k) + 2;
            nr = muIntScalarMin_sint32(3, i);
            if (k > b_i - 1) {
              ix0 = ((k - 2) * 3 + k) - 1;
              st.site = &pn_emlrtRSI;
              i = (uint8_T)nr;
              for (b_k = 0; b_k < i; b_k++) {
                v[b_k] = h[ix0 + b_k];
              }
            }
            tst = v[0];
            st.site = &on_emlrtRSI;
            rt2r = b_xzlarfg(&st, nr, &tst, v);
            if (k > b_i - 1) {
              h[k - 1] = tst;
              h[k] = 0.0;
              if (k < b_i) {
                h[2] = 0.0;
              }
            }
            d = v[1];
            aa = rt2r * v[1];
            if (nr == 3) {
              int32_T b;
              rt1r = v[2];
              tst = rt2r * v[2];
              st.site = &ho_emlrtRSI;
              if ((k <= b_i + 1) && (b_i + 1 > 2147483646)) {
                b_st.site = &mb_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }
              for (j = k; j <= b_i + 1; j++) {
                nr = 3 * (j - 1);
                ix0 = k + nr;
                h12 = h[ix0 - 1];
                tr = (h12 + d * h[ix0]) + rt1r * h[nr + 2];
                h[ix0 - 1] = h12 - tr * rt2r;
                h[ix0] -= tr * aa;
                h[nr + 2] -= tr * tst;
              }
              i = k + 3;
              nr = b_i + 1;
              b = muIntScalarMin_sint32(i, nr);
              st.site = &nn_emlrtRSI;
              if (b > 2147483646) {
                b_st.site = &mb_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }
              b_k = ((b / 2) << 1) + 1;
              nr = b_k - 2;
              for (j = 1; j <= nr; j += 2) {
                __m128d r1;
                __m128d r2;
                i = (j + 3 * k) - 1;
                r = _mm_loadu_pd(&h[i]);
                ix0 = (j + 3 * (k - 1)) - 1;
                r1 = _mm_loadu_pd(&h[ix0]);
                r2 = _mm_loadu_pd(&h[j + 5]);
                r = _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r)),
                               _mm_mul_pd(_mm_set1_pd(rt1r), r2));
                r1 = _mm_loadu_pd(&h[ix0]);
                _mm_storeu_pd(&h[ix0],
                              _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(rt2r))));
                r1 = _mm_loadu_pd(&h[i]);
                _mm_storeu_pd(&h[i],
                              _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(aa))));
                r1 = _mm_loadu_pd(&h[j + 5]);
                _mm_storeu_pd(&h[j + 5],
                              _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(tst))));
              }
              for (j = b_k; j <= b; j++) {
                nr = (j + 3 * (k - 1)) - 1;
                h12 = h[nr];
                ix0 = (j + 3 * k) - 1;
                tr = (h12 + d * h[ix0]) + rt1r * h[j + 5];
                h[nr] = h12 - tr * rt2r;
                h[ix0] -= tr * aa;
                h[j + 5] -= tr * tst;
              }
            } else if (nr == 2) {
              st.site = &go_emlrtRSI;
              if ((k <= b_i + 1) && (b_i + 1 > 2147483646)) {
                b_st.site = &mb_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }
              for (j = k; j <= b_i + 1; j++) {
                i = k + 3 * (j - 1);
                rt1r = h[i - 1];
                h22 = h[i];
                tr = rt1r + d * h22;
                rt1r -= tr * rt2r;
                h[i - 1] = rt1r;
                h22 -= tr * aa;
                h[i] = h22;
              }
              st.site = &mn_emlrtRSI;
              if (b_i + 1 > 2147483646) {
                b_st.site = &mb_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }
              b_k = (((b_i + 1) / 2) << 1) + 1;
              nr = b_k - 2;
              for (j = 1; j <= nr; j += 2) {
                __m128d r1;
                __m128d r2;
                i = (j + 3 * k) - 1;
                r = _mm_loadu_pd(&h[i]);
                ix0 = (j + 3 * (k - 1)) - 1;
                r1 = _mm_loadu_pd(&h[ix0]);
                r2 = _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r));
                _mm_storeu_pd(
                    &h[ix0], _mm_sub_pd(r1, _mm_mul_pd(r2, _mm_set1_pd(rt2r))));
                _mm_storeu_pd(&h[i],
                              _mm_sub_pd(r, _mm_mul_pd(r2, _mm_set1_pd(aa))));
              }
              for (j = b_k; j <= b_i + 1; j++) {
                i = (j + 3 * (k - 1)) - 1;
                rt1r = h[i];
                ix0 = (j + 3 * k) - 1;
                h22 = h[ix0];
                tr = rt1r + d * h22;
                rt1r -= tr * rt2r;
                h[i] = rt1r;
                h22 -= tr * aa;
                h[ix0] = h22;
              }
            }
          }
          its++;
        }
      }
      if (!converged) {
        info = b_i + 1;
        exitg1 = true;
      } else {
        if (l == b_i + 1) {
          wr[b_i] = h[b_i + 3 * b_i];
          wi[b_i] = 0.0;
        } else if (l == b_i) {
          i = b_i + 3 * b_i;
          d = h[i - 1];
          ix0 = b_i + 3 * (b_i - 1);
          rt1r = h[ix0];
          h22 = h[i];
          st.site = &ln_emlrtRSI;
          wr[b_i - 1] = xdlanv2(&h[ix0 - 1], &d, &rt1r, &h22, &wi[b_i - 1],
                                &tst, &h12, &aa, &tr);
          wr[b_i] = tst;
          wi[b_i] = h12;
          h[i - 1] = d;
          h[ix0] = rt1r;
          h[i] = h22;
        }
        kdefl = 0;
        b_i = l - 2;
      }
    }
    if (info != 0) {
      h[2] = 0.0;
    }
  }
  return info;
}

/* End of code generation (xdlahqr.c) */
