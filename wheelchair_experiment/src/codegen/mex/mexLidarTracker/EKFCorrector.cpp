//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EKFCorrector.cpp
//
//  Code generation for function 'EKFCorrector'
//


// Include files
#include "EKFCorrector.h"
#include "EKFCorrectorAdditive.h"
#include "indexShapeCheck.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <stddef.h>
#include <string.h>

// Variable Definitions
static emlrtRSInfo yfb_emlrtRSI = { 115,// lineNo
  "EKFCorrector/residual",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m"// pathName 
};

static emlrtRSInfo djb_emlrtRSI = { 154,// lineNo
  "EKFCorrector/correctjpda",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m"// pathName 
};

static emlrtRSInfo ejb_emlrtRSI = { 157,// lineNo
  "EKFCorrector/correctjpda",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m"// pathName 
};

static emlrtRSInfo fjb_emlrtRSI = { 159,// lineNo
  "EKFCorrector/correctjpda",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m"// pathName 
};

static emlrtRSInfo gjb_emlrtRSI = { 163,// lineNo
  "EKFCorrector/correctjpda",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m"// pathName 
};

static emlrtRSInfo hjb_emlrtRSI = { 20,// lineNo
  "jpdaWeightInnovationAndCovariances",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/jpdaWeightInnovationAndCovariance"
  "s.m"                                // pathName
};

static emlrtRSInfo ijb_emlrtRSI = { 21,// lineNo
  "jpdaWeightInnovationAndCovariances",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/jpdaWeightInnovationAndCovariance"
  "s.m"                                // pathName
};

static emlrtBCInfo tk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  157,                                 // lineNo
  26,                                  // colNo
  "",                                  // aName
  "EKFCorrector/correctjpda",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo uk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  157,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "EKFCorrector/correctjpda",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  158,                                 // lineNo
  29,                                  // colNo
  "",                                  // aName
  "EKFCorrector/correctjpda",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo md_emlrtRTEI = { 53,// lineNo
  15,                                  // colNo
  "bsxfun",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/bsxfun.m"// pName
};

static emlrtRTEInfo wo_emlrtRTEI = { 157,// lineNo
  13,                                  // colNo
  "EKFCorrector",                      // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFCorrector.m"// pName 
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
        void EKFCorrector::correctjpda(const emlrtStack *sp, const ::coder::
          array<real_T, 2U> &z, const ::coder::array<real_T, 1U> &beta, const
          real_T zcov[9], real_T x[6], real_T P[36])
        {
          ptrdiff_t k_t;
          ptrdiff_t lda_t;
          ptrdiff_t ldb_t;
          ptrdiff_t ldc_t;
          ptrdiff_t m_t;
          ptrdiff_t n_t;
          array<real_T, 2U> a;
          array<real_T, 2U> innovations;
          array<real_T, 1U> betas;
          emlrtStack b_st;
          emlrtStack c_st;
          emlrtStack st;
          real_T Pxy[18];
          real_T dHdx[18];
          real_T gain[18];
          real_T Pyy[9];
          real_T b_beta[9];
          real_T yy[9];
          real_T zEstimated[3];
          real_T alpha1;
          real_T beta1;
          int32_T b_iv[2];
          int32_T acoef;
          int32_T csz_idx_1;
          int32_T i;
          int32_T k;
          int32_T loop_ub;
          int32_T varargin_2;
          char_T TRANSA1;
          char_T TRANSB1;
          st.prev = sp;
          st.tls = sp->tls;
          b_st.prev = &st;
          b_st.tls = st.tls;
          c_st.prev = &b_st;
          c_st.tls = b_st.tls;
          emlrtHeapReferenceStackEnterFcnR2012b(sp);
          st.site = &djb_emlrtRSI;
          EKFCorrectorAdditive::c_getPredictedMeasurementAndCov(&st, zcov, x, P,
            zEstimated, Pxy, Pyy, dHdx);
          if (1 > beta.size(0) - 1) {
            loop_ub = 0;
          } else {
            if (1 > beta.size(0)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, beta.size(0), &tk_emlrtBCI, sp);
            }

            if ((beta.size(0) - 1 < 1) || (beta.size(0) - 1 > beta.size(0))) {
              emlrtDynamicBoundsCheckR2012b(beta.size(0) - 1, 1, beta.size(0),
                &uk_emlrtBCI, sp);
            }

            loop_ub = beta.size(0) - 1;
          }

          b_iv[0] = 1;
          b_iv[1] = loop_ub;
          st.site = &ejb_emlrtRSI;
          ::coder::internal::indexShapeCheck(&st, beta.size(0), b_iv);
          betas.set_size(&wo_emlrtRTEI, sp, loop_ub);
          for (i = 0; i < loop_ub; i++) {
            betas[i] = beta[i];
          }

          if (beta.size(0) < 1) {
            emlrtDynamicBoundsCheckR2012b(beta.size(0), 1, beta.size(0),
              &vk_emlrtBCI, sp);
          }

          st.site = &fjb_emlrtRSI;
          innovations.set_size(&wk_emlrtRTEI, &st, 3, z.size(1));
          if (z.size(1) != 0) {
            acoef = (z.size(1) != 1);
            i = z.size(1) - 1;
            for (k = 0; k <= i; k++) {
              varargin_2 = acoef * k;
              innovations[3 * k] = z[3 * varargin_2] - zEstimated[0];
              innovations[3 * k + 1] = z[3 * varargin_2 + 1] - zEstimated[1];
              innovations[3 * k + 2] = z[3 * varargin_2 + 2] - zEstimated[2];
            }
          }

          b_st.site = &hjb_emlrtRSI;
          c_st.site = &xe_emlrtRSI;
          if (innovations.size(1) != loop_ub) {
            if (loop_ub == 1) {
              emlrtErrorWithMessageIdR2018a(&c_st, &n_emlrtRTEI,
                "Coder:toolbox:mtimes_noDynamicScalarExpansion",
                "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
            } else {
              emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
                "MATLAB:innerdim", "MATLAB:innerdim", 0);
            }
          }

          if ((innovations.size(1) == 0) || (loop_ub == 0)) {
            zEstimated[0] = 0.0;
            zEstimated[1] = 0.0;
            zEstimated[2] = 0.0;
          } else {
            TRANSB1 = 'N';
            TRANSA1 = 'N';
            alpha1 = 1.0;
            beta1 = 0.0;
            m_t = (ptrdiff_t)3;
            n_t = (ptrdiff_t)1;
            k_t = (ptrdiff_t)innovations.size(1);
            lda_t = (ptrdiff_t)3;
            ldb_t = (ptrdiff_t)loop_ub;
            ldc_t = (ptrdiff_t)3;
            dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
                  &(innovations.data())[0], &lda_t, &(betas.data())[0], &ldb_t,
                  &beta1, &zEstimated[0], &ldc_t);
          }

          b_st.site = &ijb_emlrtRSI;
          c_st.site = &ijb_emlrtRSI;
          if (innovations.size(1) == 1) {
            csz_idx_1 = loop_ub;
          } else if (loop_ub == 1) {
            csz_idx_1 = innovations.size(1);
          } else if (loop_ub == innovations.size(1)) {
            csz_idx_1 = loop_ub;
          } else {
            emlrtErrorWithMessageIdR2018a(&c_st, &md_emlrtRTEI,
              "MATLAB:bsxfun:arrayDimensionsMustMatch",
              "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
          }

          a.set_size(&wk_emlrtRTEI, &c_st, 3, csz_idx_1);
          if (csz_idx_1 != 0) {
            int32_T bcoef;
            acoef = (loop_ub != 1);
            bcoef = (innovations.size(1) != 1);
            i = csz_idx_1 - 1;
            for (k = 0; k <= i; k++) {
              varargin_2 = acoef * k;
              loop_ub = bcoef * k;
              a[3 * k] = beta[varargin_2] * innovations[3 * loop_ub];
              a[3 * k + 1] = beta[varargin_2] * innovations[3 * loop_ub + 1];
              a[3 * k + 2] = beta[varargin_2] * innovations[3 * loop_ub + 2];
            }
          }

          c_st.site = &xe_emlrtRSI;
          if (a.size(1) != innovations.size(1)) {
            emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI, "MATLAB:innerdim",
              "MATLAB:innerdim", 0);
          }

          if ((a.size(1) == 0) || (innovations.size(1) == 0)) {
            memset(&yy[0], 0, 9U * sizeof(real_T));
          } else {
            TRANSB1 = 'T';
            TRANSA1 = 'N';
            alpha1 = 1.0;
            beta1 = 0.0;
            m_t = (ptrdiff_t)3;
            n_t = (ptrdiff_t)3;
            k_t = (ptrdiff_t)a.size(1);
            lda_t = (ptrdiff_t)3;
            ldb_t = (ptrdiff_t)3;
            ldc_t = (ptrdiff_t)3;
            dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(a.data())[0],
                  &lda_t, &(innovations.data())[0], &ldb_t, &beta1, &yy[0],
                  &ldc_t);
          }

          st.site = &gjb_emlrtRSI;
          EKFCorrectorAdditive::correctStateAndCovariance(&st, x, P, zEstimated,
            Pxy, Pyy, dHdx, gain);
          for (i = 0; i < 3; i++) {
            b_beta[3 * i] = (beta[beta.size(0) - 1] * Pyy[3 * i] + yy[3 * i]) -
              zEstimated[0] * zEstimated[i];
            loop_ub = 3 * i + 1;
            b_beta[loop_ub] = (beta[beta.size(0) - 1] * Pyy[loop_ub] +
                               yy[loop_ub]) - zEstimated[1] * zEstimated[i];
            loop_ub = 3 * i + 2;
            b_beta[loop_ub] = (beta[beta.size(0) - 1] * Pyy[loop_ub] +
                               yy[loop_ub]) - zEstimated[2] * zEstimated[i];
          }

          for (i = 0; i < 6; i++) {
            real_T d;
            alpha1 = gain[i];
            beta1 = gain[i + 6];
            d = gain[i + 12];
            for (csz_idx_1 = 0; csz_idx_1 < 3; csz_idx_1++) {
              Pxy[i + 6 * csz_idx_1] = (alpha1 * b_beta[3 * csz_idx_1] + beta1 *
                b_beta[3 * csz_idx_1 + 1]) + d * b_beta[3 * csz_idx_1 + 2];
            }

            alpha1 = Pxy[i];
            beta1 = Pxy[i + 6];
            d = Pxy[i + 12];
            for (csz_idx_1 = 0; csz_idx_1 < 6; csz_idx_1++) {
              loop_ub = i + 6 * csz_idx_1;
              P[loop_ub] += (alpha1 * gain[csz_idx_1] + beta1 * gain[csz_idx_1 +
                             6]) + d * gain[csz_idx_1 + 12];
            }
          }

          emlrtHeapReferenceStackLeaveFcnR2012b(sp);
        }

        void EKFCorrector::correctjpda(const emlrtStack *sp, const real_T z[3],
          const real_T zcov[9], real_T x[6], real_T P[36])
        {
          emlrtStack st;
          real_T Pxy[18];
          real_T dHdx[18];
          real_T gain[18];
          real_T Pyy[9];
          real_T dv[9];
          real_T innovations[3];
          real_T zEstimated[3];
          real_T d;
          real_T d1;
          real_T d2;
          int32_T i;
          int32_T i1;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &djb_emlrtRSI;
          EKFCorrectorAdditive::c_getPredictedMeasurementAndCov(&st, zcov, x, P,
            zEstimated, Pxy, Pyy, dHdx);
          d = z[0] - zEstimated[0];
          innovations[0] = d;
          zEstimated[0] = d;
          d = z[1] - zEstimated[1];
          innovations[1] = d;
          zEstimated[1] = d;
          d = z[2] - zEstimated[2];
          innovations[2] = d;
          st.site = &gjb_emlrtRSI;
          EKFCorrectorAdditive::correctStateAndCovariance(&st, x, P, innovations,
            Pxy, Pyy, dHdx, gain);
          d1 = zEstimated[0];
          d2 = zEstimated[1];
          for (i = 0; i < 3; i++) {
            real_T d3;
            dv[3 * i] = 0.0 * Pyy[3 * i] + d1 * innovations[i];
            Pyy[3 * i] = innovations[0] * innovations[i];
            i1 = 3 * i + 1;
            dv[i1] = 0.0 * Pyy[i1] + d2 * innovations[i];
            Pyy[i1] = innovations[1] * innovations[i];
            i1 = 3 * i + 2;
            d3 = d * innovations[i];
            dv[i1] = 0.0 * Pyy[i1] + d3;
            Pyy[i1] = d3;
          }

          for (i = 0; i < 9; i++) {
            dv[i] -= Pyy[i];
          }

          for (i = 0; i < 6; i++) {
            d = gain[i];
            d1 = gain[i + 6];
            d2 = gain[i + 12];
            for (i1 = 0; i1 < 3; i1++) {
              Pxy[i + 6 * i1] = (d * dv[3 * i1] + d1 * dv[3 * i1 + 1]) + d2 *
                dv[3 * i1 + 2];
            }

            d = Pxy[i];
            d1 = Pxy[i + 6];
            d2 = Pxy[i + 12];
            for (i1 = 0; i1 < 6; i1++) {
              int32_T i2;
              i2 = i + 6 * i1;
              P[i2] += (d * gain[i1] + d1 * gain[i1 + 6]) + d2 * gain[i1 + 12];
            }
          }
        }

        void EKFCorrector::residual(const emlrtStack *sp, const real_T z[3],
          const real_T Rs[9], const real_T x[6], const real_T S[36], real_T res
          [3], real_T b_S[9])
        {
          emlrtStack st;
          real_T unusedU0[18];
          real_T unusedU1[18];
          real_T Sy[9];
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &yfb_emlrtRSI;
          EKFCorrectorAdditive::c_getMeasurementJacobianAndCova(&st, Rs, x, S,
            res, unusedU0, Sy, unusedU1);
          for (int32_T i = 0; i < 3; i++) {
            for (int32_T i1 = 0; i1 < 3; i1++) {
              b_S[i + 3 * i1] = (Sy[i] * Sy[i1] + Sy[i + 3] * Sy[i1 + 3]) + Sy[i
                + 6] * Sy[i1 + 6];
            }

            res[i] = z[i] - res[i];
          }
        }
      }
    }
  }
}

// End of code generation (EKFCorrector.cpp)
