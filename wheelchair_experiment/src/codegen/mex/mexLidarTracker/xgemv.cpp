//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xgemv.cpp
//
//  Code generation for function 'xgemv'
//


// Include files
#include "xgemv.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace blas
    {
      void b_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[27],
                   int32_T ia0, const real_T x[27], int32_T ix0, real_T y[3])
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T c;
        int32_T iac;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &fp_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        if (n != 0) {
          int32_T i;
          int32_T iy;
          b_st.site = &hp_emlrtRSI;
          if ((1 <= n) && (n > 2147483646)) {
            c_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          if (0 <= n - 1) {
            memset(&y[0], 0, n * sizeof(real_T));
          }

          iy = 0;
          i = ia0 + 9 * (n - 1);
          for (iac = ia0; iac <= i; iac += 9) {
            int32_T b;
            int32_T ix;
            ix = ix0;
            c = 0.0;
            b = (iac + m) - 1;
            b_st.site = &np_emlrtRSI;
            if ((iac <= b) && (b > 2147483646)) {
              c_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            for (int32_T ia = iac; ia <= b; ia++) {
              c += A[ia - 1] * x[ix - 1];
              ix++;
            }

            y[iy] += c;
            iy++;
          }
        }
      }

      void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[54],
                 int32_T ia0, const real_T x[54], int32_T ix0, real_T y[6])
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T c;
        int32_T iac;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &fp_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        if (n != 0) {
          int32_T i;
          int32_T iy;
          b_st.site = &hp_emlrtRSI;
          if ((1 <= n) && (n > 2147483646)) {
            c_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          if (0 <= n - 1) {
            memset(&y[0], 0, n * sizeof(real_T));
          }

          iy = 0;
          i = ia0 + 9 * (n - 1);
          for (iac = ia0; iac <= i; iac += 9) {
            int32_T b;
            int32_T ix;
            ix = ix0;
            c = 0.0;
            b = (iac + m) - 1;
            b_st.site = &np_emlrtRSI;
            if ((iac <= b) && (b > 2147483646)) {
              c_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            for (int32_T ia = iac; ia <= b; ia++) {
              c += A[ia - 1] * x[ix - 1];
              ix++;
            }

            y[iy] += c;
            iy++;
          }
        }
      }
    }
  }
}

// End of code generation (xgemv.cpp)
