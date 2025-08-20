//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  eigHermitianStandard.cpp
//
//  Code generation for function 'eigHermitianStandard'
//


// Include files
#include "eigHermitianStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "warning.h"
#include "xhseqr.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "mwmathutil.h"
#include <string.h>

// Function Definitions
namespace coder
{
  void eigHermitianStandard(const emlrtStack *sp, const real_T A[9], real_T V[3])
  {
    static const int32_T b_iv[2] = { 3, 3 };

    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack g_st;
    emlrtStack h_st;
    emlrtStack i_st;
    emlrtStack j_st;
    emlrtStack st;
    real_T T[9];
    real_T work[3];
    real_T alpha1;
    real_T xnorm;
    int32_T iac;
    int32_T jy;
    int32_T knt;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &no_emlrtRSI;
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
    memcpy(&T[0], &A[0], 9U * sizeof(real_T));
    b_st.site = &oo_emlrtRSI;
    c_st.site = &gc_emlrtRSI;
    d_st.site = &hc_emlrtRSI;
    p = internal::flatVectorAllOrAny(A, b_iv);
    if (!p) {
      for (int32_T a = 0; a < 9; a++) {
        T[a] = rtNaN;
      }

      for (knt = 2; knt < 4; knt++) {
        T[knt - 1] = 0.0;
      }
    } else {
      real_T tau_idx_0;
      int32_T a;
      int32_T b;
      int32_T exitg1;
      int32_T ijA;
      int32_T ix;
      int32_T lastc;
      int32_T lastv;
      boolean_T exitg2;
      b_st.site = &po_emlrtRSI;
      c_st.site = &so_emlrtRSI;
      work[0] = 0.0;
      work[1] = 0.0;
      work[2] = 0.0;
      alpha1 = T[1];
      d_st.site = &to_emlrtRSI;
      tau_idx_0 = 0.0;
      e_st.site = &wo_emlrtRSI;
      xnorm = internal::blas::xnrm2(&e_st, 1, T, 3);
      if (xnorm != 0.0) {
        xnorm = muDoubleScalarHypot(T[1], xnorm);
        if (T[1] >= 0.0) {
          xnorm = -xnorm;
        }

        if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          do {
            knt++;
            e_st.site = &xo_emlrtRSI;
            internal::blas::xscal(&e_st, 1, 9.9792015476736E+291, T, 3);
            xnorm *= 9.9792015476736E+291;
            alpha1 *= 9.9792015476736E+291;
          } while (!(muDoubleScalarAbs(xnorm) >= 1.0020841800044864E-292));

          e_st.site = &yo_emlrtRSI;
          xnorm = internal::blas::xnrm2(&e_st, 1, T, 3);
          xnorm = muDoubleScalarHypot(alpha1, xnorm);
          if (alpha1 >= 0.0) {
            xnorm = -xnorm;
          }

          tau_idx_0 = (xnorm - alpha1) / xnorm;
          e_st.site = &ap_emlrtRSI;
          internal::blas::xscal(&e_st, 1, 1.0 / (alpha1 - xnorm), T, 3);
          e_st.site = &bp_emlrtRSI;
          if ((1 <= knt) && (knt > 2147483646)) {
            f_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          for (jy = 0; jy < knt; jy++) {
            xnorm *= 1.0020841800044864E-292;
          }

          alpha1 = xnorm;
        } else {
          tau_idx_0 = (xnorm - T[1]) / xnorm;
          e_st.site = &cp_emlrtRSI;
          internal::blas::xscal(&e_st, 1, 1.0 / (T[1] - xnorm), T, 3);
          alpha1 = xnorm;
        }
      }

      T[1] = 1.0;
      d_st.site = &uo_emlrtRSI;
      if (tau_idx_0 != 0.0) {
        lastv = 1;
        knt = 1;
        while ((lastv + 1 > 0) && (T[knt + 1] == 0.0)) {
          lastv--;
          knt--;
        }

        lastc = 3;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          jy = lastc + 3;
          do {
            exitg1 = 0;
            if (jy <= (lastc + lastv * 3) + 3) {
              if (T[jy - 1] != 0.0) {
                exitg1 = 1;
              } else {
                jy += 3;
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
        e_st.site = &dp_emlrtRSI;
        f_st.site = &fp_emlrtRSI;
        if (lastc != 0) {
          g_st.site = &hp_emlrtRSI;
          if (0 <= lastc - 1) {
            memset(&work[0], 0, lastc * sizeof(real_T));
          }

          ix = 1;
          a = 3 * lastv + 4;
          for (iac = 4; iac <= a; iac += 3) {
            knt = 0;
            b = (iac + lastc) - 1;
            g_st.site = &gp_emlrtRSI;
            for (jy = iac; jy <= b; jy++) {
              work[knt] += T[jy - 1] * T[ix];
              knt++;
            }

            ix++;
          }
        }

        e_st.site = &ep_emlrtRSI;
        f_st.site = &ip_emlrtRSI;
        g_st.site = &ie_emlrtRSI;
        h_st.site = &je_emlrtRSI;
        if (!(-tau_idx_0 == 0.0)) {
          knt = 3;
          jy = 1;
          i_st.site = &le_emlrtRSI;
          for (iac = 0; iac <= lastv; iac++) {
            if (T[jy] != 0.0) {
              xnorm = T[jy] * -tau_idx_0;
              ix = 0;
              a = knt + 1;
              b = lastc + knt;
              i_st.site = &ke_emlrtRSI;
              if ((knt + 1 <= b) && (b > 2147483646)) {
                j_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&j_st);
              }

              for (ijA = a; ijA <= b; ijA++) {
                T[ijA - 1] += work[ix] * xnorm;
                ix++;
              }
            }

            jy++;
            knt += 3;
          }
        }
      }

      d_st.site = &vo_emlrtRSI;
      internal::reflapack::xzlarf(&d_st, 2, 2, 2, tau_idx_0, T, 5, work);
      T[1] = alpha1;
      alpha1 = T[5];
      d_st.site = &to_emlrtRSI;
      tau_idx_0 = 0.0;
      e_st.site = &wo_emlrtRSI;
      xnorm = internal::blas::xnrm2(&e_st, 0, T, 6);
      if (xnorm != 0.0) {
        xnorm = muDoubleScalarHypot(T[5], xnorm);
        if (T[5] >= 0.0) {
          xnorm = -xnorm;
        }

        if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          do {
            knt++;
            e_st.site = &xo_emlrtRSI;
            internal::blas::xscal(&e_st, 0, 9.9792015476736E+291, T, 6);
            xnorm *= 9.9792015476736E+291;
            alpha1 *= 9.9792015476736E+291;
          } while (!(muDoubleScalarAbs(xnorm) >= 1.0020841800044864E-292));

          e_st.site = &yo_emlrtRSI;
          xnorm = internal::blas::xnrm2(&e_st, 0, T, 6);
          xnorm = muDoubleScalarHypot(alpha1, xnorm);
          if (alpha1 >= 0.0) {
            xnorm = -xnorm;
          }

          tau_idx_0 = (xnorm - alpha1) / xnorm;
          e_st.site = &ap_emlrtRSI;
          internal::blas::xscal(&e_st, 0, 1.0 / (alpha1 - xnorm), T, 6);
          e_st.site = &bp_emlrtRSI;
          if ((1 <= knt) && (knt > 2147483646)) {
            f_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          for (jy = 0; jy < knt; jy++) {
            xnorm *= 1.0020841800044864E-292;
          }

          alpha1 = xnorm;
        } else {
          tau_idx_0 = (xnorm - T[5]) / xnorm;
          e_st.site = &cp_emlrtRSI;
          internal::blas::xscal(&e_st, 0, 1.0 / (T[5] - xnorm), T, 6);
          alpha1 = xnorm;
        }
      }

      T[5] = 1.0;
      d_st.site = &uo_emlrtRSI;
      if (tau_idx_0 != 0.0) {
        lastv = 0;
        knt = 4;
        while ((lastv + 1 > 0) && (T[knt + 1] == 0.0)) {
          lastv--;
          knt--;
        }

        lastc = 3;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          jy = lastc + 6;
          do {
            exitg1 = 0;
            if (jy <= (lastc + lastv * 3) + 6) {
              if (T[jy - 1] != 0.0) {
                exitg1 = 1;
              } else {
                jy += 3;
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
        e_st.site = &dp_emlrtRSI;
        f_st.site = &fp_emlrtRSI;
        if (lastc != 0) {
          g_st.site = &hp_emlrtRSI;
          if (0 <= lastc - 1) {
            memset(&work[0], 0, lastc * sizeof(real_T));
          }

          ix = 5;
          a = 3 * lastv + 7;
          for (iac = 7; iac <= a; iac += 3) {
            knt = 0;
            b = (iac + lastc) - 1;
            g_st.site = &gp_emlrtRSI;
            for (jy = iac; jy <= b; jy++) {
              work[knt] += T[jy - 1] * T[ix];
              knt++;
            }

            ix++;
          }
        }

        e_st.site = &ep_emlrtRSI;
        f_st.site = &ip_emlrtRSI;
        g_st.site = &ie_emlrtRSI;
        h_st.site = &je_emlrtRSI;
        if (!(-tau_idx_0 == 0.0)) {
          knt = 6;
          jy = 5;
          i_st.site = &le_emlrtRSI;
          for (iac = 0; iac <= lastv; iac++) {
            if (T[jy] != 0.0) {
              xnorm = T[jy] * -tau_idx_0;
              ix = 0;
              a = knt + 1;
              b = lastc + knt;
              i_st.site = &ke_emlrtRSI;
              if ((knt + 1 <= b) && (b > 2147483646)) {
                j_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&j_st);
              }

              for (ijA = a; ijA <= b; ijA++) {
                T[ijA - 1] += work[ix] * xnorm;
                ix++;
              }
            }

            jy++;
            knt += 3;
          }
        }
      }

      d_st.site = &vo_emlrtRSI;
      internal::reflapack::xzlarf(&d_st, 1, 1, 6, tau_idx_0, T, 9, work);
      T[5] = alpha1;
      b_st.site = &qo_emlrtRSI;
      knt = internal::lapack::xhseqr(&b_st, T);
      if (knt != 0) {
        b_st.site = &ro_emlrtRSI;
        internal::d_warning(&b_st);
      }
    }

    V[0] = T[0];
    V[1] = T[4];
    V[2] = T[8];
  }
}

// End of code generation (eigHermitianStandard.cpp)
