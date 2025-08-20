//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xhseqr.cpp
//
//  Code generation for function 'xhseqr'
//


// Include files
#include "xhseqr.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xrot.h"
#include "xzlarfg.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace lapack
    {
      int32_T xhseqr(const emlrtStack *sp, real_T h[9])
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T v[3];
        real_T aa;
        real_T ab;
        real_T ba;
        real_T bb;
        real_T d;
        real_T h22;
        real_T rt1r;
        real_T s;
        real_T tst;
        int32_T i;
        int32_T info;
        boolean_T exitg1;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &op_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b_st.site = &pp_emlrtRSI;
        info = 0;
        v[0] = 0.0;
        v[1] = 0.0;
        v[2] = 0.0;
        h[2] = 0.0;
        i = 2;
        exitg1 = false;
        while ((!exitg1) && (i + 1 >= 1)) {
          int32_T hoffset;
          int32_T its;
          int32_T k;
          int32_T nr;
          boolean_T exitg2;
          boolean_T goto150;
          k = -1;
          goto150 = false;
          its = 0;
          exitg2 = false;
          while ((!exitg2) && (its < 301)) {
            boolean_T exitg3;
            k = i - 1;
            exitg3 = false;
            while ((!exitg3) && (k + 2 > 1)) {
              hoffset = k + 3 * k;
              ba = muDoubleScalarAbs(h[hoffset + 1]);
              if (ba <= 3.0062525400134592E-292) {
                exitg3 = true;
              } else {
                nr = k + 3 * (k + 1);
                bb = muDoubleScalarAbs(h[nr + 1]);
                tst = muDoubleScalarAbs(h[hoffset]) + bb;
                if (tst == 0.0) {
                  if (k >= 1) {
                    tst = muDoubleScalarAbs(h[k + 3 * (k - 1)]);
                  }

                  if (k + 3 <= 3) {
                    tst += muDoubleScalarAbs(h[nr + 2]);
                  }
                }

                if (ba <= 2.2204460492503131E-16 * tst) {
                  tst = muDoubleScalarAbs(h[nr]);
                  if (ba > tst) {
                    ab = ba;
                    ba = tst;
                  } else {
                    ab = tst;
                  }

                  tst = muDoubleScalarAbs(h[hoffset] - h[nr + 1]);
                  if (bb > tst) {
                    aa = bb;
                    bb = tst;
                  } else {
                    aa = tst;
                  }

                  s = aa + ab;
                  if (ba * (ab / s) <= muDoubleScalarMax(3.0062525400134592E-292,
                       2.2204460492503131E-16 * (bb * (aa / s)))) {
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
              goto150 = true;
              exitg2 = true;
            } else {
              int32_T m;
              if (its == 10) {
                s = muDoubleScalarAbs(h[1]) + muDoubleScalarAbs(h[5]);
                tst = 0.75 * s + h[0];
                aa = -0.4375 * s;
                ab = s;
                h22 = tst;
              } else if (its == 20) {
                s = muDoubleScalarAbs(h[i + 3 * (i - 1)]) + muDoubleScalarAbs
                  (h[i - 1]);
                tst = 0.75 * s + h[i + 3 * i];
                aa = -0.4375 * s;
                ab = s;
                h22 = tst;
              } else {
                nr = i + 3 * (i - 1);
                tst = h[nr - 1];
                ab = h[nr];
                aa = h[(i + 3 * i) - 1];
                h22 = h[i + 3 * i];
              }

              s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(aa)) +
                   muDoubleScalarAbs(ab)) + muDoubleScalarAbs(h22);
              if (s == 0.0) {
                rt1r = 0.0;
                tst = 0.0;
                bb = 0.0;
                ab = 0.0;
              } else {
                tst /= s;
                ab /= s;
                aa /= s;
                h22 /= s;
                ba = (tst + h22) / 2.0;
                tst = (tst - ba) * (h22 - ba) - aa * ab;
                ab = muDoubleScalarSqrt(muDoubleScalarAbs(tst));
                if (tst >= 0.0) {
                  rt1r = ba * s;
                  bb = rt1r;
                  tst = ab * s;
                  ab = -tst;
                } else {
                  rt1r = ba + ab;
                  bb = ba - ab;
                  if (muDoubleScalarAbs(rt1r - h22) <= muDoubleScalarAbs(bb -
                       h22)) {
                    rt1r *= s;
                    bb = rt1r;
                  } else {
                    bb *= s;
                    rt1r = bb;
                  }

                  tst = 0.0;
                  ab = 0.0;
                }
              }

              m = i - 1;
              if (i - 1 >= 1) {
                aa = h[0] - bb;
                s = (muDoubleScalarAbs(aa) + muDoubleScalarAbs(ab)) +
                  muDoubleScalarAbs(h[1]);
                ba = h[1] / s;
                v[0] = (ba * h[3] + (h[0] - rt1r) * (aa / s)) - tst * (ab / s);
                v[1] = ba * (((h[0] + h[4]) - rt1r) - bb);
                v[2] = ba * h[5];
                s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
                  muDoubleScalarAbs(v[2]);
                v[0] /= s;
                v[1] /= s;
                v[2] /= s;
              }

              for (int32_T b_k = m; b_k <= i; b_k++) {
                int32_T j;
                nr = (i - b_k) + 2;
                nr = muIntScalarMin_sint32(3, nr);
                if (b_k > i - 1) {
                  hoffset = (b_k + 3 * (b_k - 2)) - 1;
                  for (j = 0; j < nr; j++) {
                    v[j] = h[j + hoffset];
                  }
                }

                tst = v[0];
                c_st.site = &vp_emlrtRSI;
                bb = reflapack::xzlarfg(&c_st, nr, &tst, v);
                v[0] = tst;
                if (b_k > i - 1) {
                  h[b_k - 1] = tst;
                  h[b_k] = 0.0;
                  if (b_k < i) {
                    h[2] = 0.0;
                  }
                }

                s = v[1];
                tst = bb * v[1];
                if (nr == 3) {
                  int32_T sum1_tmp;
                  d = v[2];
                  ba = bb * v[2];
                  for (j = b_k; j < 4; j++) {
                    nr = 3 * (j - 1);
                    sum1_tmp = b_k + nr;
                    ab = h[sum1_tmp - 1];
                    aa = (ab + s * h[sum1_tmp]) + d * h[nr + 2];
                    h[sum1_tmp - 1] = ab - aa * bb;
                    h[sum1_tmp] -= aa * tst;
                    h[nr + 2] -= aa * ba;
                  }

                  nr = b_k + 3;
                  hoffset = i + 1;
                  hoffset = muIntScalarMin_sint32(nr, hoffset);
                  for (j = 0; j < hoffset; j++) {
                    sum1_tmp = j + 3 * (b_k - 1);
                    ab = h[sum1_tmp];
                    nr = j + 3 * b_k;
                    aa = (ab + s * h[nr]) + d * h[j + 6];
                    h[sum1_tmp] = ab - aa * bb;
                    h[nr] -= aa * tst;
                    h[j + 6] -= aa * ba;
                  }
                } else {
                  if (nr == 2) {
                    int32_T sum1_tmp;
                    for (j = b_k; j < 4; j++) {
                      sum1_tmp = b_k + 3 * (j - 1);
                      ab = h[sum1_tmp - 1];
                      aa = ab + s * h[sum1_tmp];
                      h[sum1_tmp - 1] = ab - aa * bb;
                      h[sum1_tmp] -= aa * tst;
                    }

                    for (j = 0; j <= i; j++) {
                      sum1_tmp = j + 3 * (b_k - 1);
                      nr = j + 3 * b_k;
                      aa = h[sum1_tmp] + s * h[nr];
                      h[sum1_tmp] -= aa * bb;
                      h[nr] -= aa * tst;
                    }
                  }
                }
              }

              its++;
            }
          }

          if (!goto150) {
            info = i + 1;
            exitg1 = true;
          } else {
            if ((k + 2 != i + 1) && (k + 2 == i)) {
              hoffset = i + 3 * i;
              s = h[hoffset - 1];
              nr = i + 3 * (i - 1);
              d = h[nr];
              tst = h[hoffset];
              reflapack::xdlanv2(&h[(i + 3 * (i - 1)) - 1], &s, &d, &tst, &ab,
                                 &aa, &ba, &bb, &h22, &rt1r);
              h[hoffset - 1] = s;
              h[nr] = d;
              h[hoffset] = tst;
              if (3 > i + 1) {
                c_st.site = &rp_emlrtRSI;
                blas::xrot(&c_st, 2 - i, h, i + (i + 1) * 3, (i + (i + 1) * 3) +
                           1, h22, rt1r);
              }

              blas::xrot(i - 1, h, (i - 1) * 3 + 1, i * 3 + 1, h22, rt1r);
            }

            i = k;
          }
        }

        return info;
      }
    }
  }
}

// End of code generation (xhseqr.cpp)
