//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  svdPSD.cpp
//
//  Code generation for function 'svdPSD'
//


// Include files
#include "svdPSD.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "xzsvdc.h"
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
        void svdPSD(const emlrtStack *sp, const real_T A[9], real_T R[9])
        {
          static const int32_T b_iv[2] = { 3, 3 };

          emlrtStack b_st;
          emlrtStack c_st;
          emlrtStack d_st;
          emlrtStack e_st;
          emlrtStack st;
          real_T Ss[9];
          real_T V[9];
          real_T b_A[9];
          real_T s[3];
          int32_T k;
          boolean_T p;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &xt_emlrtRSI;
          b_st.prev = &st;
          b_st.tls = st.tls;
          c_st.prev = &b_st;
          c_st.tls = b_st.tls;
          d_st.prev = &c_st;
          d_st.tls = c_st.tls;
          e_st.prev = &d_st;
          e_st.tls = d_st.tls;
          b_st.site = &ec_emlrtRSI;
          c_st.site = &gc_emlrtRSI;
          d_st.site = &hc_emlrtRSI;
          p = ::coder::internal::flatVectorAllOrAny(A, b_iv);
          if (p) {
            b_st.site = &au_emlrtRSI;
            c_st.site = &cu_emlrtRSI;
            d_st.site = &lc_emlrtRSI;
            memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
            e_st.site = &mc_emlrtRSI;
            ::coder::internal::reflapack::b_xzsvdc(&e_st, b_A, Ss, s, V);
          } else {
            b_st.site = &bu_emlrtRSI;
            c_st.site = &cu_emlrtRSI;
            d_st.site = &lc_emlrtRSI;
            memset(&b_A[0], 0, 9U * sizeof(real_T));
            e_st.site = &mc_emlrtRSI;
            ::coder::internal::reflapack::b_xzsvdc(&e_st, b_A, Ss, s, V);
            s[0] = rtNaN;
            s[1] = rtNaN;
            s[2] = rtNaN;
            for (k = 0; k < 9; k++) {
              V[k] = rtNaN;
            }
          }

          memset(&Ss[0], 0, 9U * sizeof(real_T));
          Ss[0] = s[0];
          Ss[4] = s[1];
          Ss[8] = s[2];
          st.site = &yt_emlrtRSI;
          p = false;
          for (k = 0; k < 9; k++) {
            if (p || (Ss[k] < 0.0)) {
              p = true;
            }
          }

          if (p) {
            emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          for (k = 0; k < 9; k++) {
            Ss[k] = muDoubleScalarSqrt(Ss[k]);
          }

          for (k = 0; k < 3; k++) {
            real_T d;
            real_T d1;
            real_T d2;
            d = V[k];
            d1 = V[k + 3];
            d2 = V[k + 6];
            for (int32_T i = 0; i < 3; i++) {
              R[k + 3 * i] = (d * Ss[3 * i] + d1 * Ss[3 * i + 1]) + d2 * Ss[3 *
                i + 2];
            }
          }
        }
      }
    }
  }
}

// End of code generation (svdPSD.cpp)
