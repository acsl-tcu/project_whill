//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EKFCorrectorAdditive.cpp
//
//  Code generation for function 'EKFCorrectorAdditive'
//


// Include files
#include "EKFCorrectorAdditive.h"
#include "cvmeas.h"
#include "cvmeasjac.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "trackingEKF.h"
#include "warning.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo mdb_emlrtRSI = { 14,// lineNo
  "EKFCorrectorAdditive/validateMeasurementFcn",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m"// pathName 
};

static emlrtRSInfo agb_emlrtRSI = { 106,// lineNo
  "EKFCorrectorAdditive/getMeasurementJacobianAndCovariance",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m"// pathName 
};

static emlrtRSInfo bgb_emlrtRSI = { 110,// lineNo
  "EKFCorrectorAdditive/getMeasurementJacobianAndCovariance",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m"// pathName 
};

static emlrtRSInfo cgb_emlrtRSI = { 119,// lineNo
  "EKFCorrectorAdditive/getMeasurementJacobianAndCovariance",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m"// pathName 
};

static emlrtRSInfo bjb_emlrtRSI = { 58,// lineNo
  "EKFCorrectorAdditive/getPredictedMeasurementAndCovariances",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m"// pathName 
};

static emlrtRSInfo cjb_emlrtRSI = { 63,// lineNo
  "EKFCorrectorAdditive/getPredictedMeasurementAndCovariances",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m"// pathName 
};

static emlrtRSInfo jjb_emlrtRSI = { 26,// lineNo
  "EKFCorrector/correctStateAndCovariance",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        void EKFCorrectorAdditive::c_getMeasurementJacobianAndCova(const
          emlrtStack *sp, const real_T Rs[9], const real_T x[6], const real_T S
          [36], real_T zEstimated[3], real_T Pxy[18], real_T Sy[9], real_T dHdx
          [18])
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
          emlrtStack st;
          real_T b_S[36];
          real_T M[27];
          real_T y[18];
          real_T R[9];
          real_T tau[3];
          real_T work[3];
          real_T atmp;
          real_T d;
          real_T s;
          int32_T aoffset;
          int32_T coffset;
          int32_T i;
          int32_T j;
          int32_T lastv;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &agb_emlrtRSI;
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
          cvmeasjac(&st, x, dHdx);
          st.site = &bgb_emlrtRSI;
          cvmeas(&st, x, zEstimated);
          for (lastv = 0; lastv < 6; lastv++) {
            for (coffset = 0; coffset < 6; coffset++) {
              d = 0.0;
              for (aoffset = 0; aoffset < 6; aoffset++) {
                d += S[lastv + 6 * aoffset] * S[coffset + 6 * aoffset];
              }

              b_S[lastv + 6 * coffset] = d;
            }

            for (coffset = 0; coffset < 3; coffset++) {
              d = 0.0;
              for (aoffset = 0; aoffset < 6; aoffset++) {
                d += b_S[lastv + 6 * aoffset] * dHdx[coffset + 3 * aoffset];
              }

              Pxy[lastv + 6 * coffset] = d;
            }
          }

          st.site = &cgb_emlrtRSI;
          b_st.site = &bab_emlrtRSI;
          c_st.site = &yj_emlrtRSI;
          d_st.site = &dab_emlrtRSI;
          e_st.site = &bk_emlrtRSI;
          for (j = 0; j < 3; j++) {
            coffset = j * 6;
            for (i = 0; i < 6; i++) {
              aoffset = i * 6;
              s = 0.0;
              f_st.site = &eab_emlrtRSI;
              for (lastv = 0; lastv < 6; lastv++) {
                s += S[aoffset + lastv] * dHdx[lastv * 3 + j];
              }

              y[coffset + i] = s;
            }
          }

          for (lastv = 0; lastv < 3; lastv++) {
            for (coffset = 0; coffset < 6; coffset++) {
              M[coffset + 9 * lastv] = y[coffset + 6 * lastv];
            }

            M[9 * lastv + 6] = Rs[lastv];
            M[9 * lastv + 7] = Rs[lastv + 3];
            M[9 * lastv + 8] = Rs[lastv + 6];
          }

          b_st.site = &cab_emlrtRSI;
          c_st.site = &fab_emlrtRSI;
          d_st.site = &gab_emlrtRSI;
          e_st.site = &hab_emlrtRSI;
          f_st.site = &kab_emlrtRSI;
          g_st.site = &lab_emlrtRSI;
          work[0] = 0.0;
          work[1] = 0.0;
          work[2] = 0.0;
          h_st.site = &oab_emlrtRSI;
          for (i = 0; i < 3; i++) {
            aoffset = i * 9 + i;
            atmp = M[aoffset];
            h_st.site = &nab_emlrtRSI;
            tau[i] = 0.0;
            i_st.site = &wo_emlrtRSI;
            s = ::coder::internal::blas::e_xnrm2(&i_st, 8 - i, M, aoffset + 2);
            if (s != 0.0) {
              d = M[aoffset];
              s = muDoubleScalarHypot(d, s);
              if (d >= 0.0) {
                s = -s;
              }

              if (muDoubleScalarAbs(s) < 1.0020841800044864E-292) {
                coffset = 0;
                do {
                  coffset++;
                  i_st.site = &xo_emlrtRSI;
                  ::coder::internal::blas::e_xscal(&i_st, 8 - i,
                    9.9792015476736E+291, M, aoffset + 2);
                  s *= 9.9792015476736E+291;
                  atmp *= 9.9792015476736E+291;
                } while (!(muDoubleScalarAbs(s) >= 1.0020841800044864E-292));

                i_st.site = &yo_emlrtRSI;
                s = ::coder::internal::blas::e_xnrm2(&i_st, 8 - i, M, aoffset +
                  2);
                s = muDoubleScalarHypot(atmp, s);
                if (atmp >= 0.0) {
                  s = -s;
                }

                tau[i] = (s - atmp) / s;
                i_st.site = &ap_emlrtRSI;
                ::coder::internal::blas::e_xscal(&i_st, 8 - i, 1.0 / (atmp - s),
                  M, aoffset + 2);
                i_st.site = &bp_emlrtRSI;
                if ((1 <= coffset) && (coffset > 2147483646)) {
                  j_st.site = &jc_emlrtRSI;
                  check_forloop_overflow_error(&j_st);
                }

                for (lastv = 0; lastv < coffset; lastv++) {
                  s *= 1.0020841800044864E-292;
                }

                atmp = s;
              } else {
                tau[i] = (s - d) / s;
                i_st.site = &cp_emlrtRSI;
                ::coder::internal::blas::e_xscal(&i_st, 8 - i, 1.0 / (M[aoffset]
                  - s), M, aoffset + 2);
                atmp = s;
              }
            }

            M[aoffset] = atmp;
            if (i + 1 < 3) {
              M[aoffset] = 1.0;
              h_st.site = &mab_emlrtRSI;
              if (tau[i] != 0.0) {
                lastv = 9 - i;
                coffset = (aoffset - i) + 8;
                while ((lastv > 0) && (M[coffset] == 0.0)) {
                  lastv--;
                  coffset--;
                }

                i_st.site = &lp_emlrtRSI;
                coffset = ::coder::internal::reflapack::b_ilazlc(&i_st, lastv, 2
                  - i, M, aoffset + 10);
              } else {
                lastv = 0;
                coffset = 0;
              }

              if (lastv > 0) {
                i_st.site = &kp_emlrtRSI;
                ::coder::internal::blas::b_xgemv(&i_st, lastv, coffset, M,
                  aoffset + 10, M, aoffset + 1, work);
                i_st.site = &jp_emlrtRSI;
                ::coder::internal::blas::b_xgerc(&i_st, lastv, coffset, -tau[i],
                  aoffset + 1, work, M, aoffset + 10);
              }

              M[aoffset] = atmp;
            }
          }

          for (j = 0; j < 3; j++) {
            e_st.site = &iab_emlrtRSI;
            for (i = 0; i <= j; i++) {
              R[i + 3 * j] = M[i + 9 * j];
            }

            lastv = j + 2;
            if (lastv <= 3) {
              memset(&R[(j * 3 + lastv) + -1], 0, (4 - lastv) * sizeof(real_T));
            }
          }

          e_st.site = &jab_emlrtRSI;
          f_st.site = &pab_emlrtRSI;
          g_st.site = &qab_emlrtRSI;
          h_st.site = &uab_emlrtRSI;
          aoffset = 2;
          work[0] = 0.0;
          work[1] = 0.0;
          work[2] = 0.0;
          for (i = 2; i >= 0; i--) {
            int32_T iaii;
            iaii = i + i * 9;
            if (i + 1 < 3) {
              M[iaii] = 1.0;
              h_st.site = &tab_emlrtRSI;
              if (tau[aoffset] != 0.0) {
                lastv = 9 - i;
                coffset = iaii - i;
                while ((lastv > 0) && (M[coffset + 8] == 0.0)) {
                  lastv--;
                  coffset--;
                }

                i_st.site = &lp_emlrtRSI;
                coffset = ::coder::internal::reflapack::b_ilazlc(&i_st, lastv, 2
                  - i, M, iaii + 10);
              } else {
                lastv = 0;
                coffset = 0;
              }

              if (lastv > 0) {
                i_st.site = &kp_emlrtRSI;
                ::coder::internal::blas::b_xgemv(&i_st, lastv, coffset, M, iaii
                  + 10, M, iaii + 1, work);
                i_st.site = &jp_emlrtRSI;
                ::coder::internal::blas::b_xgerc(&i_st, lastv, coffset,
                  -tau[aoffset], iaii + 1, work, M, iaii + 10);
              }
            }

            h_st.site = &sab_emlrtRSI;
            ::coder::internal::blas::e_xscal(&h_st, 8 - i, -tau[aoffset], M,
              iaii + 2);
            M[iaii] = 1.0 - tau[aoffset];
            h_st.site = &rab_emlrtRSI;
            for (j = 0; j < i; j++) {
              M[(iaii - j) - 1] = 0.0;
            }

            aoffset--;
          }

          for (lastv = 0; lastv < 3; lastv++) {
            Sy[3 * lastv] = R[lastv];
            Sy[3 * lastv + 1] = R[lastv + 3];
            Sy[3 * lastv + 2] = R[lastv + 6];
          }
        }

        void EKFCorrectorAdditive::c_getPredictedMeasurementAndCov(const
          emlrtStack *sp, const real_T zcov[9], const real_T x[6], const real_T
          P[36], real_T zEstimated[3], real_T Pxy[18], real_T Pyy[9], real_T
          dHdx[18])
        {
          emlrtStack st;
          real_T b_dHdx[18];
          real_T d;
          int32_T Pyy_tmp;
          int32_T i;
          int32_T i1;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &bjb_emlrtRSI;
          cvmeasjac(&st, x, dHdx);
          for (i = 0; i < 6; i++) {
            for (i1 = 0; i1 < 3; i1++) {
              d = 0.0;
              for (Pyy_tmp = 0; Pyy_tmp < 6; Pyy_tmp++) {
                d += P[i + 6 * Pyy_tmp] * dHdx[i1 + 3 * Pyy_tmp];
              }

              Pxy[i + 6 * i1] = d;
            }
          }

          for (i = 0; i < 3; i++) {
            for (i1 = 0; i1 < 6; i1++) {
              d = 0.0;
              for (Pyy_tmp = 0; Pyy_tmp < 6; Pyy_tmp++) {
                d += dHdx[i + 3 * Pyy_tmp] * P[Pyy_tmp + 6 * i1];
              }

              b_dHdx[i + 3 * i1] = d;
            }

            for (i1 = 0; i1 < 3; i1++) {
              d = 0.0;
              for (Pyy_tmp = 0; Pyy_tmp < 6; Pyy_tmp++) {
                d += b_dHdx[i + 3 * Pyy_tmp] * dHdx[i1 + 3 * Pyy_tmp];
              }

              Pyy_tmp = i + 3 * i1;
              Pyy[Pyy_tmp] = d + zcov[Pyy_tmp];
            }
          }

          st.site = &cjb_emlrtRSI;
          cvmeas(&st, x, zEstimated);
        }

        void EKFCorrectorAdditive::correctStateAndCovariance(const emlrtStack
          *sp, real_T x[6], real_T P[36], const real_T y[3], const real_T Pxy[18],
          const real_T Pyy[9], const real_T dHdx[18], real_T gain[18])
        {
          emlrtStack b_st;
          emlrtStack c_st;
          emlrtStack d_st;
          emlrtStack e_st;
          emlrtStack f_st;
          emlrtStack st;
          real_T b_P[36];
          real_T b_gain[36];
          real_T A[9];
          real_T a21;
          real_T maxval;
          int32_T b_gain_tmp;
          int32_T gain_tmp;
          int32_T r1;
          int32_T r2;
          int32_T r3;
          int32_T rtemp;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &jjb_emlrtRSI;
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
          b_st.site = &hcb_emlrtRSI;
          c_st.site = &icb_emlrtRSI;
          d_st.site = &jcb_emlrtRSI;
          memcpy(&A[0], &Pyy[0], 9U * sizeof(real_T));
          r1 = 0;
          r2 = 1;
          r3 = 2;
          maxval = muDoubleScalarAbs(Pyy[0]);
          a21 = muDoubleScalarAbs(Pyy[1]);
          if (a21 > maxval) {
            maxval = a21;
            r1 = 1;
            r2 = 0;
          }

          if (muDoubleScalarAbs(Pyy[2]) > maxval) {
            r1 = 2;
            r2 = 1;
            r3 = 0;
          }

          A[r2] = Pyy[r2] / Pyy[r1];
          A[r3] /= A[r1];
          A[r2 + 3] -= A[r2] * A[r1 + 3];
          A[r3 + 3] -= A[r3] * A[r1 + 3];
          A[r2 + 6] -= A[r2] * A[r1 + 6];
          A[r3 + 6] -= A[r3] * A[r1 + 6];
          if (muDoubleScalarAbs(A[r3 + 3]) > muDoubleScalarAbs(A[r2 + 3])) {
            rtemp = r2;
            r2 = r3;
            r3 = rtemp;
          }

          A[r3 + 3] /= A[r2 + 3];
          A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
          if ((A[r1] == 0.0) || (A[r2 + 3] == 0.0) || (A[r3 + 6] == 0.0)) {
            e_st.site = &kcb_emlrtRSI;
            f_st.site = &mcb_emlrtRSI;
            ::coder::internal::f_warning(&f_st);
          }

          for (int32_T k = 0; k < 6; k++) {
            rtemp = k + 6 * r1;
            gain[rtemp] = Pxy[k] / A[r1];
            gain_tmp = k + 6 * r2;
            gain[gain_tmp] = Pxy[k + 6] - gain[rtemp] * A[r1 + 3];
            b_gain_tmp = k + 6 * r3;
            gain[b_gain_tmp] = Pxy[k + 12] - gain[rtemp] * A[r1 + 6];
            gain[gain_tmp] /= A[r2 + 3];
            gain[b_gain_tmp] -= gain[gain_tmp] * A[r2 + 6];
            gain[b_gain_tmp] /= A[r3 + 6];
            gain[gain_tmp] -= gain[b_gain_tmp] * A[r3 + 3];
            gain[rtemp] -= gain[b_gain_tmp] * A[r3];
            gain[rtemp] -= gain[gain_tmp] * A[r2];
          }

          for (gain_tmp = 0; gain_tmp < 6; gain_tmp++) {
            maxval = gain[gain_tmp + 6];
            a21 = gain[gain_tmp + 12];
            x[gain_tmp] += (gain[gain_tmp] * y[0] + maxval * y[1]) + a21 * y[2];
            for (b_gain_tmp = 0; b_gain_tmp < 6; b_gain_tmp++) {
              b_gain[gain_tmp + 6 * b_gain_tmp] = (gain[gain_tmp] * dHdx[3 *
                b_gain_tmp] + maxval * dHdx[3 * b_gain_tmp + 1]) + a21 * dHdx[3 *
                b_gain_tmp + 2];
            }

            for (b_gain_tmp = 0; b_gain_tmp < 6; b_gain_tmp++) {
              maxval = 0.0;
              for (rtemp = 0; rtemp < 6; rtemp++) {
                maxval += b_gain[gain_tmp + 6 * rtemp] * P[rtemp + 6 *
                  b_gain_tmp];
              }

              rtemp = gain_tmp + 6 * b_gain_tmp;
              b_P[rtemp] = P[rtemp] - maxval;
            }
          }

          memcpy(&P[0], &b_P[0], 36U * sizeof(real_T));
        }

        void EKFCorrectorAdditive::getNumberOfMandatoryInputs()
        {
        }

        void EKFCorrectorAdditive::validateMeasurementFcn(const emlrtStack *sp,
          const trackingEKF *ekf)
        {
          emlrtStack st;
          real_T unusedExpr[6];
          real_T b_unusedExpr[3];
          st.prev = sp;
          st.tls = sp->tls;
          ekf->get_State(unusedExpr);
          st.site = &mdb_emlrtRSI;
          cvmeas(&st, unusedExpr, b_unusedExpr);
          ekf->get_State(unusedExpr);
        }
      }
    }
  }
}

// End of code generation (EKFCorrectorAdditive.cpp)
