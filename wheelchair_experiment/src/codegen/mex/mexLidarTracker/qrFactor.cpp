//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  qrFactor.cpp
//
//  Code generation for function 'qrFactor'
//


// Include files
#include "qrFactor.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "mwmathutil.h"
#include <string.h>

// Function Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        void qrFactor(const emlrtStack *sp, const real_T A[36], real_T S[36],
                      const real_T Ns[18])
        {
          emlrtStack b_st;
          emlrtStack c_st;
          emlrtStack d_st;
          emlrtStack e_st;
          emlrtStack f_st;
          emlrtStack g_st;
          emlrtStack h_st;
          emlrtStack i_st;
          emlrtStack st;
          real_T M[54];
          real_T y[36];
          real_T tau[6];
          real_T work[6];
          real_T atmp;
          real_T s;
          int32_T aoffset;
          int32_T coffset;
          int32_T i;
          int32_T j;
          int32_T lastv;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &bab_emlrtRSI;
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
          b_st.site = &yj_emlrtRSI;
          c_st.site = &dab_emlrtRSI;
          d_st.site = &bk_emlrtRSI;
          for (j = 0; j < 6; j++) {
            coffset = j * 6;
            for (i = 0; i < 6; i++) {
              aoffset = i * 6;
              s = 0.0;
              e_st.site = &eab_emlrtRSI;
              for (lastv = 0; lastv < 6; lastv++) {
                s += S[aoffset + lastv] * A[lastv * 6 + j];
              }

              y[coffset + i] = s;
            }
          }

          for (aoffset = 0; aoffset < 6; aoffset++) {
            for (coffset = 0; coffset < 6; coffset++) {
              M[coffset + 9 * aoffset] = y[coffset + 6 * aoffset];
            }

            M[9 * aoffset + 6] = Ns[aoffset];
            M[9 * aoffset + 7] = Ns[aoffset + 6];
            M[9 * aoffset + 8] = Ns[aoffset + 12];
          }

          st.site = &cab_emlrtRSI;
          b_st.site = &fab_emlrtRSI;
          c_st.site = &gab_emlrtRSI;
          d_st.site = &hab_emlrtRSI;
          e_st.site = &kab_emlrtRSI;
          f_st.site = &lab_emlrtRSI;
          for (i = 0; i < 6; i++) {
            work[i] = 0.0;
          }

          g_st.site = &oab_emlrtRSI;
          for (i = 0; i < 6; i++) {
            aoffset = i * 9 + i;
            atmp = M[aoffset];
            g_st.site = &nab_emlrtRSI;
            tau[i] = 0.0;
            h_st.site = &wo_emlrtRSI;
            s = ::coder::internal::blas::d_xnrm2(&h_st, 8 - i, M, aoffset + 2);
            if (s != 0.0) {
              real_T d;
              d = M[aoffset];
              s = muDoubleScalarHypot(d, s);
              if (d >= 0.0) {
                s = -s;
              }

              if (muDoubleScalarAbs(s) < 1.0020841800044864E-292) {
                coffset = 0;
                do {
                  coffset++;
                  h_st.site = &xo_emlrtRSI;
                  ::coder::internal::blas::d_xscal(&h_st, 8 - i,
                    9.9792015476736E+291, M, aoffset + 2);
                  s *= 9.9792015476736E+291;
                  atmp *= 9.9792015476736E+291;
                } while (!(muDoubleScalarAbs(s) >= 1.0020841800044864E-292));

                h_st.site = &yo_emlrtRSI;
                s = ::coder::internal::blas::d_xnrm2(&h_st, 8 - i, M, aoffset +
                  2);
                s = muDoubleScalarHypot(atmp, s);
                if (atmp >= 0.0) {
                  s = -s;
                }

                tau[i] = (s - atmp) / s;
                h_st.site = &ap_emlrtRSI;
                ::coder::internal::blas::d_xscal(&h_st, 8 - i, 1.0 / (atmp - s),
                  M, aoffset + 2);
                h_st.site = &bp_emlrtRSI;
                if ((1 <= coffset) && (coffset > 2147483646)) {
                  i_st.site = &jc_emlrtRSI;
                  check_forloop_overflow_error(&i_st);
                }

                for (lastv = 0; lastv < coffset; lastv++) {
                  s *= 1.0020841800044864E-292;
                }

                atmp = s;
              } else {
                tau[i] = (s - d) / s;
                h_st.site = &cp_emlrtRSI;
                ::coder::internal::blas::d_xscal(&h_st, 8 - i, 1.0 / (M[aoffset]
                  - s), M, aoffset + 2);
                atmp = s;
              }
            }

            M[aoffset] = atmp;
            if (i + 1 < 6) {
              M[aoffset] = 1.0;
              g_st.site = &mab_emlrtRSI;
              if (tau[i] != 0.0) {
                lastv = 9 - i;
                coffset = (aoffset - i) + 8;
                while ((lastv > 0) && (M[coffset] == 0.0)) {
                  lastv--;
                  coffset--;
                }

                h_st.site = &lp_emlrtRSI;
                coffset = ::coder::internal::reflapack::ilazlc(&h_st, lastv, 5 -
                  i, M, aoffset + 10);
              } else {
                lastv = 0;
                coffset = 0;
              }

              if (lastv > 0) {
                h_st.site = &kp_emlrtRSI;
                ::coder::internal::blas::xgemv(&h_st, lastv, coffset, M, aoffset
                  + 10, M, aoffset + 1, work);
                h_st.site = &jp_emlrtRSI;
                ::coder::internal::blas::xgerc(&h_st, lastv, coffset, -tau[i],
                  aoffset + 1, work, M, aoffset + 10);
              }

              M[aoffset] = atmp;
            }
          }

          for (j = 0; j < 6; j++) {
            d_st.site = &iab_emlrtRSI;
            for (i = 0; i <= j; i++) {
              y[i + 6 * j] = M[i + 9 * j];
            }

            aoffset = j + 2;
            if (aoffset <= 6) {
              memset(&y[(j * 6 + aoffset) + -1], 0, (7 - aoffset) * sizeof
                     (real_T));
            }
          }

          d_st.site = &jab_emlrtRSI;
          e_st.site = &pab_emlrtRSI;
          f_st.site = &qab_emlrtRSI;
          g_st.site = &uab_emlrtRSI;
          aoffset = 5;
          for (i = 0; i < 6; i++) {
            work[i] = 0.0;
          }

          for (i = 5; i >= 0; i--) {
            int32_T iaii;
            iaii = i + i * 9;
            if (i + 1 < 6) {
              M[iaii] = 1.0;
              g_st.site = &tab_emlrtRSI;
              if (tau[aoffset] != 0.0) {
                lastv = 9 - i;
                coffset = iaii - i;
                while ((lastv > 0) && (M[coffset + 8] == 0.0)) {
                  lastv--;
                  coffset--;
                }

                h_st.site = &lp_emlrtRSI;
                coffset = ::coder::internal::reflapack::ilazlc(&h_st, lastv, 5 -
                  i, M, iaii + 10);
              } else {
                lastv = 0;
                coffset = 0;
              }

              if (lastv > 0) {
                h_st.site = &kp_emlrtRSI;
                ::coder::internal::blas::xgemv(&h_st, lastv, coffset, M, iaii +
                  10, M, iaii + 1, work);
                h_st.site = &jp_emlrtRSI;
                ::coder::internal::blas::xgerc(&h_st, lastv, coffset,
                  -tau[aoffset], iaii + 1, work, M, iaii + 10);
              }
            }

            g_st.site = &sab_emlrtRSI;
            ::coder::internal::blas::d_xscal(&g_st, 8 - i, -tau[aoffset], M,
              iaii + 2);
            M[iaii] = 1.0 - tau[aoffset];
            g_st.site = &rab_emlrtRSI;
            for (j = 0; j < i; j++) {
              M[(iaii - j) - 1] = 0.0;
            }

            aoffset--;
          }

          for (aoffset = 0; aoffset < 6; aoffset++) {
            for (coffset = 0; coffset < 6; coffset++) {
              S[coffset + 6 * aoffset] = y[aoffset + 6 * coffset];
            }
          }
        }
      }
    }
  }
}

// End of code generation (qrFactor.cpp)
