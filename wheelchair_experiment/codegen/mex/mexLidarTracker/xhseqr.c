/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xhseqr.c
 *
 * Code generation for function 'xhseqr'
 *
 */

/* Include files */
#include "xhseqr.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xzlarfg.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo hn_emlrtRSI =
    {
        32,       /* lineNo */
        "xhseqr", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xhseqr.m" /* pathName */
};

static emlrtRSInfo in_emlrtRSI = {
    22,        /* lineNo */
    "xdhseqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdhseqr.m" /* pathName */
};

/* Function Definitions */
int32_T b_xhseqr(const emlrtStack *sp, real_T h[36])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v[3];
  real_T aa;
  real_T d;
  real_T h21;
  real_T h22;
  real_T rt1r;
  real_T s_tmp_tmp;
  real_T tr;
  real_T tst;
  int32_T b_k;
  int32_T i;
  int32_T info;
  int32_T iy;
  int32_T j;
  int32_T k;
  int32_T kdefl;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hn_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &in_emlrtRSI;
  info = 0;
  h[2] = 0.0;
  h[3] = 0.0;
  h[9] = 0.0;
  h[10] = 0.0;
  h[16] = 0.0;
  h[17] = 0.0;
  h[23] = 0.0;
  kdefl = 0;
  i = 5;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    int32_T b_i;
    int32_T i1;
    int32_T its;
    int32_T l;
    int32_T nr;
    int32_T tst_tmp_tmp;
    boolean_T converged;
    boolean_T exitg2;
    l = 1;
    converged = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      real_T s;
      boolean_T exitg3;
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > l)) {
        b_i = k + 6 * (k - 1);
        d = muDoubleScalarAbs(h[b_i]);
        if (d <= 6.0125050800269183E-292) {
          exitg3 = true;
        } else {
          tst_tmp_tmp = k + 6 * k;
          h21 = h[tst_tmp_tmp];
          tr = muDoubleScalarAbs(h21);
          aa = h[b_i - 1];
          tst = muDoubleScalarAbs(aa) + tr;
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = muDoubleScalarAbs(h[(k + 6 * (k - 2)) - 1]);
            }
            if (k + 2 <= 6) {
              tst += muDoubleScalarAbs(h[tst_tmp_tmp + 1]);
            }
          }
          if (d <= 2.2204460492503131E-16 * tst) {
            h22 = muDoubleScalarAbs(h[tst_tmp_tmp - 1]);
            h21 = muDoubleScalarAbs(aa - h21);
            aa = muDoubleScalarMax(tr, h21);
            tst = muDoubleScalarMin(tr, h21);
            s = aa + tst;
            if (muDoubleScalarMin(d, h22) * (muDoubleScalarMax(d, h22) / s) <=
                muDoubleScalarMax(6.0125050800269183E-292,
                                  2.2204460492503131E-16 * (tst * (aa / s)))) {
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
      if (k + 1 > 1) {
        h[k + 6 * (k - 1)] = 0.0;
      }
      if (k + 1 >= i) {
        converged = true;
        exitg2 = true;
      } else {
        __m128d r;
        real_T rt2r;
        int32_T m;
        kdefl++;
        if (kdefl - kdefl / 20 * 20 == 0) {
          s = muDoubleScalarAbs(h[i + 6 * (i - 1)]) +
              muDoubleScalarAbs(h[(i + 6 * (i - 2)) - 1]);
          tst = 0.75 * s + h[i + 6 * i];
          aa = -0.4375 * s;
          h21 = s;
          h22 = tst;
        } else if (kdefl - kdefl / 10 * 10 == 0) {
          tst_tmp_tmp = k + 6 * k;
          s = muDoubleScalarAbs(h[tst_tmp_tmp + 1]) +
              muDoubleScalarAbs(h[(k + 6 * (k + 1)) + 2]);
          tst = 0.75 * s + h[tst_tmp_tmp];
          aa = -0.4375 * s;
          h21 = s;
          h22 = tst;
        } else {
          tst_tmp_tmp = i + 6 * (i - 1);
          tst = h[tst_tmp_tmp - 1];
          h21 = h[tst_tmp_tmp];
          tst_tmp_tmp = i + 6 * i;
          aa = h[tst_tmp_tmp - 1];
          h22 = h[tst_tmp_tmp];
        }
        s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(aa)) +
             muDoubleScalarAbs(h21)) +
            muDoubleScalarAbs(h22);
        if (s == 0.0) {
          rt1r = 0.0;
          tr = 0.0;
          rt2r = 0.0;
          h22 = 0.0;
        } else {
          tst /= s;
          h21 /= s;
          aa /= s;
          h22 /= s;
          tr = (tst + h22) / 2.0;
          tst = (tst - tr) * (h22 - tr) - aa * h21;
          h21 = muDoubleScalarSqrt(muDoubleScalarAbs(tst));
          if (tst >= 0.0) {
            rt1r = tr * s;
            rt2r = rt1r;
            tr = h21 * s;
            h22 = -tr;
          } else {
            rt1r = tr + h21;
            rt2r = tr - h21;
            if (muDoubleScalarAbs(rt1r - h22) <=
                muDoubleScalarAbs(rt2r - h22)) {
              rt1r *= s;
              rt2r = rt1r;
            } else {
              rt2r *= s;
              rt1r = rt2r;
            }
            tr = 0.0;
            h22 = 0.0;
          }
        }
        m = i - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          tst_tmp_tmp = m + 6 * (m - 1);
          tst = h[tst_tmp_tmp];
          s_tmp_tmp = h[tst_tmp_tmp - 1];
          h21 = s_tmp_tmp - rt2r;
          s = (muDoubleScalarAbs(h21) + muDoubleScalarAbs(h22)) +
              muDoubleScalarAbs(tst);
          aa = tst / s;
          tst_tmp_tmp = m + 6 * m;
          v[0] = (aa * h[tst_tmp_tmp - 1] + h21 * (h21 / s)) - tr * (h22 / s);
          tst = h[tst_tmp_tmp];
          v[1] = aa * (((s_tmp_tmp + tst) - rt1r) - rt2r);
          v[2] = aa * h[tst_tmp_tmp + 1];
          s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
              muDoubleScalarAbs(v[2]);
          r = _mm_loadu_pd(&v[0]);
          _mm_storeu_pd(&v[0], _mm_div_pd(r, _mm_set1_pd(s)));
          v[2] /= s;
          if (m == k + 1) {
            exitg3 = true;
          } else {
            b_i = m + 6 * (m - 2);
            if (muDoubleScalarAbs(h[b_i - 1]) *
                    (muDoubleScalarAbs(v[1]) + muDoubleScalarAbs(v[2])) <=
                2.2204460492503131E-16 * muDoubleScalarAbs(v[0]) *
                    ((muDoubleScalarAbs(h[b_i - 2]) +
                      muDoubleScalarAbs(s_tmp_tmp)) +
                     muDoubleScalarAbs(tst))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
        }
        for (b_k = m; b_k <= i; b_k++) {
          b_i = (i - b_k) + 2;
          nr = muIntScalarMin_sint32(3, b_i);
          if (b_k > m) {
            tst_tmp_tmp = ((b_k - 2) * 6 + b_k) - 1;
            for (iy = 0; iy < nr; iy++) {
              v[iy] = h[tst_tmp_tmp + iy];
            }
          }
          tst = v[0];
          c_st.site = &on_emlrtRSI;
          tr = b_xzlarfg(&c_st, nr, &tst, v);
          if (b_k > m) {
            b_i = b_k + 6 * (b_k - 2);
            h[b_i - 1] = tst;
            h[b_i] = 0.0;
            if (b_k < i) {
              h[b_i + 1] = 0.0;
            }
          } else if (m > k + 1) {
            b_i = (b_k + 6 * (b_k - 2)) - 1;
            h[b_i] *= 1.0 - tr;
          }
          d = v[1];
          tst = tr * v[1];
          if (nr == 3) {
            int32_T i2;
            h22 = v[2];
            aa = tr * v[2];
            for (j = b_k; j < 7; j++) {
              b_i = b_k + 6 * (j - 1);
              s_tmp_tmp = h[b_i - 1];
              rt2r = h[b_i];
              rt1r = h[b_i + 1];
              h21 = (s_tmp_tmp + d * rt2r) + h22 * rt1r;
              s_tmp_tmp -= h21 * tr;
              h[b_i - 1] = s_tmp_tmp;
              rt2r -= h21 * tst;
              h[b_i] = rt2r;
              rt1r -= h21 * aa;
              h[b_i + 1] = rt1r;
            }
            b_i = b_k + 3;
            i1 = i + 1;
            b_i = muIntScalarMin_sint32(b_i, i1);
            tst_tmp_tmp = (b_i / 2) << 1;
            iy = tst_tmp_tmp - 2;
            for (j = 0; j <= iy; j += 2) {
              __m128d r1;
              __m128d r2;
              __m128d r3;
              i1 = j + 6 * b_k;
              r = _mm_loadu_pd(&h[i1]);
              nr = j + 6 * (b_k + 1);
              r1 = _mm_loadu_pd(&h[nr]);
              i2 = j + 6 * (b_k - 1);
              r2 = _mm_loadu_pd(&h[i2]);
              r3 = _mm_add_pd(_mm_add_pd(r2, _mm_mul_pd(_mm_set1_pd(d), r)),
                              _mm_mul_pd(_mm_set1_pd(h22), r1));
              _mm_storeu_pd(&h[i2],
                            _mm_sub_pd(r2, _mm_mul_pd(r3, _mm_set1_pd(tr))));
              _mm_storeu_pd(&h[i1],
                            _mm_sub_pd(r, _mm_mul_pd(r3, _mm_set1_pd(tst))));
              _mm_storeu_pd(&h[nr],
                            _mm_sub_pd(r1, _mm_mul_pd(r3, _mm_set1_pd(aa))));
            }
            for (j = tst_tmp_tmp; j < b_i; j++) {
              i1 = j + 6 * (b_k - 1);
              s_tmp_tmp = h[i1];
              nr = j + 6 * b_k;
              rt2r = h[nr];
              i2 = j + 6 * (b_k + 1);
              rt1r = h[i2];
              h21 = (s_tmp_tmp + d * rt2r) + h22 * rt1r;
              s_tmp_tmp -= h21 * tr;
              h[i1] = s_tmp_tmp;
              rt2r -= h21 * tst;
              h[nr] = rt2r;
              rt1r -= h21 * aa;
              h[i2] = rt1r;
            }
          } else if (nr == 2) {
            for (j = b_k; j < 7; j++) {
              b_i = b_k + 6 * (j - 1);
              h22 = h[b_i - 1];
              s_tmp_tmp = h[b_i];
              h21 = h22 + d * s_tmp_tmp;
              h22 -= h21 * tr;
              h[b_i - 1] = h22;
              s_tmp_tmp -= h21 * tst;
              h[b_i] = s_tmp_tmp;
            }
            tst_tmp_tmp = ((i + 1) / 2) << 1;
            iy = tst_tmp_tmp - 2;
            for (j = 0; j <= iy; j += 2) {
              __m128d r1;
              __m128d r2;
              b_i = j + 6 * b_k;
              r = _mm_loadu_pd(&h[b_i]);
              i1 = j + 6 * (b_k - 1);
              r1 = _mm_loadu_pd(&h[i1]);
              r2 = _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r));
              _mm_storeu_pd(&h[i1],
                            _mm_sub_pd(r1, _mm_mul_pd(r2, _mm_set1_pd(tr))));
              _mm_storeu_pd(&h[b_i],
                            _mm_sub_pd(r, _mm_mul_pd(r2, _mm_set1_pd(tst))));
            }
            for (j = tst_tmp_tmp; j <= i; j++) {
              b_i = j + 6 * (b_k - 1);
              h22 = h[b_i];
              i1 = j + 6 * b_k;
              s_tmp_tmp = h[i1];
              h21 = h22 + d * s_tmp_tmp;
              h22 -= h21 * tr;
              h[b_i] = h22;
              s_tmp_tmp -= h21 * tst;
              h[i1] = s_tmp_tmp;
            }
          }
        }
        its++;
      }
    }
    if (!converged) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((l != i + 1) && (l == i)) {
        b_i = i + 6 * i;
        d = h[b_i - 1];
        i1 = 6 * (i - 1);
        nr = i + i1;
        h22 = h[nr];
        s_tmp_tmp = h[b_i];
        xdlanv2(&h[nr - 1], &d, &h22, &s_tmp_tmp, &rt1r, &tst, &h21, &aa, &tr);
        h[b_i - 1] = d;
        h[nr] = h22;
        h[b_i] = s_tmp_tmp;
        if (i + 1 < 6) {
          tst_tmp_tmp = (i + 1) * 6 + i;
          b_i = 4 - i;
          for (k = 0; k <= b_i; k++) {
            nr = tst_tmp_tmp + k * 6;
            tst = h[nr];
            h21 = h[nr - 1];
            h[nr] = aa * tst - tr * h21;
            h[nr - 1] = aa * h21 + tr * tst;
          }
        }
        if (i - 1 >= 1) {
          iy = i * 6;
          b_i = (uint8_T)(i - 1);
          for (k = 0; k < b_i; k++) {
            tst_tmp_tmp = iy + k;
            tst = h[tst_tmp_tmp];
            nr = i1 + k;
            h21 = h[nr];
            h[tst_tmp_tmp] = aa * tst - tr * h21;
            h[nr] = aa * h21 + tr * tst;
          }
        }
      }
      kdefl = 0;
      i = l - 2;
    }
  }
  for (j = 0; j < 4; j++) {
    for (i = j + 3; i < 7; i++) {
      h[(i + 6 * j) - 1] = 0.0;
    }
  }
  return info;
}

int32_T xhseqr(const emlrtStack *sp, real_T h[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v[3];
  real_T aa;
  real_T d;
  real_T h21;
  real_T h22;
  real_T rt1r;
  real_T rt2r;
  real_T s;
  real_T tr;
  real_T tst;
  int32_T b_k;
  int32_T c_k;
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T kdefl;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hn_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &in_emlrtRSI;
  info = 0;
  h[2] = 0.0;
  kdefl = 0;
  i = 2;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    int32_T b_i;
    int32_T i1;
    int32_T its;
    int32_T k;
    int32_T nr;
    int32_T tst_tmp_tmp;
    boolean_T converged;
    boolean_T exitg2;
    k = -1;
    converged = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      boolean_T exitg3;
      k = i - 1;
      exitg3 = false;
      while ((!exitg3) && (k + 2 > 1)) {
        b_i = k + 3 * k;
        d = muDoubleScalarAbs(h[b_i + 1]);
        if (d <= 3.0062525400134592E-292) {
          exitg3 = true;
        } else {
          nr = 3 * (k + 1);
          tst_tmp_tmp = k + nr;
          h21 = h[tst_tmp_tmp + 1];
          tr = muDoubleScalarAbs(h21);
          aa = h[b_i];
          tst = muDoubleScalarAbs(aa) + tr;
          if (tst == 0.0) {
            if (k >= 1) {
              tst = muDoubleScalarAbs(h[k]);
            }
            if (k + 3 <= 3) {
              tst += muDoubleScalarAbs(h[nr + 2]);
            }
          }
          if (d <= 2.2204460492503131E-16 * tst) {
            rt2r = muDoubleScalarAbs(h[tst_tmp_tmp]);
            h21 = muDoubleScalarAbs(aa - h21);
            aa = muDoubleScalarMax(tr, h21);
            tst = muDoubleScalarMin(tr, h21);
            s = aa + tst;
            if (muDoubleScalarMin(d, rt2r) * (muDoubleScalarMax(d, rt2r) / s) <=
                muDoubleScalarMax(3.0062525400134592E-292,
                                  2.2204460492503131E-16 * (tst * (aa / s)))) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }
      if (k + 2 > 1) {
        h[(k + 3 * k) + 1] = 0.0;
      }
      if (k + 2 >= i) {
        converged = true;
        exitg2 = true;
      } else {
        __m128d r;
        int32_T m;
        kdefl++;
        if (kdefl - kdefl / 20 * 20 == 0) {
          s = muDoubleScalarAbs(h[i + 3 * (i - 1)]) +
              muDoubleScalarAbs(h[i - 1]);
          tst = 0.75 * s + h[i + 3 * i];
          aa = -0.4375 * s;
          h21 = s;
          h22 = tst;
        } else if (kdefl - kdefl / 10 * 10 == 0) {
          s = muDoubleScalarAbs(h[1]) + muDoubleScalarAbs(h[5]);
          tst = 0.75 * s + h[0];
          aa = -0.4375 * s;
          h21 = s;
          h22 = tst;
        } else {
          nr = i + 3 * (i - 1);
          tst = h[nr - 1];
          h21 = h[nr];
          nr = i + 3 * i;
          aa = h[nr - 1];
          h22 = h[nr];
        }
        s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(aa)) +
             muDoubleScalarAbs(h21)) +
            muDoubleScalarAbs(h22);
        if (s == 0.0) {
          rt1r = 0.0;
          tst = 0.0;
          rt2r = 0.0;
          h21 = 0.0;
        } else {
          tst /= s;
          h21 /= s;
          aa /= s;
          h22 /= s;
          tr = (tst + h22) / 2.0;
          tst = (tst - tr) * (h22 - tr) - aa * h21;
          h21 = muDoubleScalarSqrt(muDoubleScalarAbs(tst));
          if (tst >= 0.0) {
            rt1r = tr * s;
            rt2r = rt1r;
            tst = h21 * s;
            h21 = -tst;
          } else {
            rt1r = tr + h21;
            rt2r = tr - h21;
            if (muDoubleScalarAbs(rt1r - h22) <=
                muDoubleScalarAbs(rt2r - h22)) {
              rt1r *= s;
              rt2r = rt1r;
            } else {
              rt2r *= s;
              rt1r = rt2r;
            }
            tst = 0.0;
            h21 = 0.0;
          }
        }
        m = i - 1;
        if (i - 1 >= 1) {
          aa = h[0] - rt2r;
          s = (muDoubleScalarAbs(aa) + muDoubleScalarAbs(h21)) +
              muDoubleScalarAbs(h[1]);
          tr = h[1] / s;
          v[0] = (tr * h[3] + (h[0] - rt1r) * (aa / s)) - tst * (h21 / s);
          v[1] = tr * (((h[0] + h[4]) - rt1r) - rt2r);
          v[2] = tr * h[5];
          s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
              muDoubleScalarAbs(v[2]);
          r = _mm_loadu_pd(&v[0]);
          _mm_storeu_pd(&v[0], _mm_div_pd(r, _mm_set1_pd(s)));
          v[2] /= s;
        }
        for (b_k = m; b_k <= i; b_k++) {
          b_i = (i - b_k) + 2;
          nr = muIntScalarMin_sint32(3, b_i);
          if (b_k > i - 1) {
            tst_tmp_tmp = ((b_k - 2) * 3 + b_k) - 1;
            for (c_k = 0; c_k < nr; c_k++) {
              v[c_k] = h[tst_tmp_tmp + c_k];
            }
          }
          tst = v[0];
          c_st.site = &on_emlrtRSI;
          rt2r = b_xzlarfg(&c_st, nr, &tst, v);
          if (b_k > i - 1) {
            h[b_k - 1] = tst;
            h[b_k] = 0.0;
            if (b_k < i) {
              h[2] = 0.0;
            }
          }
          d = v[1];
          aa = rt2r * v[1];
          if (nr == 3) {
            s = v[2];
            tst = rt2r * v[2];
            for (j = b_k; j < 4; j++) {
              tst_tmp_tmp = 3 * (j - 1);
              nr = b_k + tst_tmp_tmp;
              h21 = h[nr - 1];
              tr = (h21 + d * h[nr]) + s * h[tst_tmp_tmp + 2];
              h[nr - 1] = h21 - tr * rt2r;
              h[nr] -= tr * aa;
              h[tst_tmp_tmp + 2] -= tr * tst;
            }
            b_i = b_k + 3;
            i1 = i + 1;
            b_i = muIntScalarMin_sint32(b_i, i1);
            c_k = (b_i / 2) << 1;
            tst_tmp_tmp = c_k - 2;
            for (j = 0; j <= tst_tmp_tmp; j += 2) {
              __m128d r1;
              __m128d r2;
              i1 = j + 3 * b_k;
              r = _mm_loadu_pd(&h[i1]);
              nr = j + 3 * (b_k - 1);
              r1 = _mm_loadu_pd(&h[nr]);
              r2 = _mm_loadu_pd(&h[j + 6]);
              r = _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r)),
                             _mm_mul_pd(_mm_set1_pd(s), r2));
              r1 = _mm_loadu_pd(&h[nr]);
              _mm_storeu_pd(&h[nr],
                            _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(rt2r))));
              r1 = _mm_loadu_pd(&h[i1]);
              _mm_storeu_pd(&h[i1],
                            _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(aa))));
              r1 = _mm_loadu_pd(&h[j + 6]);
              _mm_storeu_pd(&h[j + 6],
                            _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(tst))));
            }
            for (j = c_k; j < b_i; j++) {
              tst_tmp_tmp = j + 3 * (b_k - 1);
              h21 = h[tst_tmp_tmp];
              nr = j + 3 * b_k;
              tr = (h21 + d * h[nr]) + s * h[j + 6];
              h[tst_tmp_tmp] = h21 - tr * rt2r;
              h[nr] -= tr * aa;
              h[j + 6] -= tr * tst;
            }
          } else if (nr == 2) {
            for (j = b_k; j < 4; j++) {
              b_i = b_k + 3 * (j - 1);
              s = h[b_i - 1];
              h22 = h[b_i];
              tr = s + d * h22;
              s -= tr * rt2r;
              h[b_i - 1] = s;
              h22 -= tr * aa;
              h[b_i] = h22;
            }
            c_k = ((i + 1) / 2) << 1;
            tst_tmp_tmp = c_k - 2;
            for (j = 0; j <= tst_tmp_tmp; j += 2) {
              __m128d r1;
              __m128d r2;
              b_i = j + 3 * b_k;
              r = _mm_loadu_pd(&h[b_i]);
              i1 = j + 3 * (b_k - 1);
              r1 = _mm_loadu_pd(&h[i1]);
              r2 = _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r));
              _mm_storeu_pd(&h[i1],
                            _mm_sub_pd(r1, _mm_mul_pd(r2, _mm_set1_pd(rt2r))));
              _mm_storeu_pd(&h[b_i],
                            _mm_sub_pd(r, _mm_mul_pd(r2, _mm_set1_pd(aa))));
            }
            for (j = c_k; j <= i; j++) {
              b_i = j + 3 * (b_k - 1);
              s = h[b_i];
              i1 = j + 3 * b_k;
              h22 = h[i1];
              tr = s + d * h22;
              s -= tr * rt2r;
              h[b_i] = s;
              h22 -= tr * aa;
              h[i1] = h22;
            }
          }
        }
        its++;
      }
    }
    if (!converged) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((k + 2 != i + 1) && (k + 2 == i)) {
        b_i = i + 3 * i;
        d = h[b_i - 1];
        i1 = 3 * (i - 1);
        nr = i + i1;
        s = h[nr];
        h22 = h[b_i];
        xdlanv2(&h[nr - 1], &d, &s, &h22, &h21, &aa, &tr, &rt2r, &rt1r);
        h[b_i - 1] = d;
        h[nr] = s;
        h[b_i] = h22;
        if (i + 1 < 3) {
          nr = (i + 1) * 3 + i;
          b_i = 1 - i;
          for (b_k = 0; b_k <= b_i; b_k++) {
            tst_tmp_tmp = nr + b_k * 3;
            tst = h[tst_tmp_tmp];
            h21 = h[tst_tmp_tmp - 1];
            h[tst_tmp_tmp] = rt2r * tst - rt1r * h21;
            h[tst_tmp_tmp - 1] = rt2r * h21 + rt1r * tst;
          }
        }
        if (i - 1 >= 1) {
          nr = i * 3;
          tst = rt2r * h[i1] + rt1r * h[nr];
          h[nr] = rt2r * h[nr] - rt1r * h[i1];
          h[i1] = tst;
        }
      }
      kdefl = 0;
      i = k;
    }
  }
  h[2] = 0.0;
  return info;
}

/* End of code generation (xhseqr.c) */
