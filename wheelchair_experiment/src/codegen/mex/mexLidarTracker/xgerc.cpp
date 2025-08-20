//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xgerc.cpp
//
//  Code generation for function 'xgerc'
//


// Include files
#include "xgerc.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace blas
    {
      void b_xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
                   int32_T ix0, const real_T y[3], real_T A[27], int32_T ia0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack d_st;
        emlrtStack e_st;
        emlrtStack st;
        int32_T jA;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ip_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        d_st.prev = &c_st;
        d_st.tls = c_st.tls;
        e_st.prev = &d_st;
        e_st.tls = d_st.tls;
        b_st.site = &ie_emlrtRSI;
        c_st.site = &je_emlrtRSI;
        if (!(alpha1 == 0.0)) {
          int32_T jy;
          jA = ia0;
          jy = 0;
          d_st.site = &le_emlrtRSI;
          if ((1 <= n) && (n > 2147483646)) {
            e_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          for (int32_T j = 0; j < n; j++) {
            if (y[jy] != 0.0) {
              real_T temp;
              int32_T b;
              int32_T ix;
              temp = y[jy] * alpha1;
              ix = ix0;
              b = (m + jA) - 1;
              d_st.site = &ke_emlrtRSI;
              if ((jA <= b) && (b > 2147483646)) {
                e_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&e_st);
              }

              for (int32_T ijA = jA; ijA <= b; ijA++) {
                A[ijA - 1] += A[ix - 1] * temp;
                ix++;
              }
            }

            jy++;
            jA += 9;
          }
        }
      }

      void xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
                 int32_T ix0, const real_T y[6], real_T A[54], int32_T ia0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack d_st;
        emlrtStack e_st;
        emlrtStack st;
        int32_T jA;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ip_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        d_st.prev = &c_st;
        d_st.tls = c_st.tls;
        e_st.prev = &d_st;
        e_st.tls = d_st.tls;
        b_st.site = &ie_emlrtRSI;
        c_st.site = &je_emlrtRSI;
        if (!(alpha1 == 0.0)) {
          int32_T jy;
          jA = ia0;
          jy = 0;
          d_st.site = &le_emlrtRSI;
          if ((1 <= n) && (n > 2147483646)) {
            e_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          for (int32_T j = 0; j < n; j++) {
            if (y[jy] != 0.0) {
              real_T temp;
              int32_T b;
              int32_T ix;
              temp = y[jy] * alpha1;
              ix = ix0;
              b = (m + jA) - 1;
              d_st.site = &ke_emlrtRSI;
              if ((jA <= b) && (b > 2147483646)) {
                e_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&e_st);
              }

              for (int32_T ijA = jA; ijA <= b; ijA++) {
                A[ijA - 1] += A[ix - 1] * temp;
                ix++;
              }
            }

            jy++;
            jA += 9;
          }
        }
      }
    }
  }
}

// End of code generation (xgerc.cpp)
