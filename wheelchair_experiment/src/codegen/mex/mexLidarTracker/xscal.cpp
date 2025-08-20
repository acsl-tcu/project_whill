//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xscal.cpp
//
//  Code generation for function 'xscal'
//


// Include files
#include "xscal.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo ed_emlrtRSI = { 31, // lineNo
  "xscal",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"// pathName 
};

static emlrtRSInfo fd_emlrtRSI = { 18, // lineNo
  "xscal",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xscal.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace blas
    {
      void b_xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[36],
                   int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T b;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ed_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b = (ix0 + n) - 1;
        b_st.site = &fd_emlrtRSI;
        if ((ix0 <= b) && (b > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= b; k++) {
          x[k - 1] *= a;
        }
      }

      void b_xscal(const emlrtStack *sp, real_T a, real_T x[36], int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T b;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ed_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b = ix0 + 5;
        b_st.site = &fd_emlrtRSI;
        if ((ix0 <= ix0 + 5) && (ix0 + 5 > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= b; k++) {
          x[k - 1] *= a;
        }
      }

      void c_xscal(const emlrtStack *sp, real_T a, real_T x[9], int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T b;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ed_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b = ix0 + 2;
        b_st.site = &fd_emlrtRSI;
        if ((ix0 <= ix0 + 2) && (ix0 + 2 > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= b; k++) {
          x[k - 1] *= a;
        }
      }

      void c_xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[6],
                   int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T b;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ed_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b = (ix0 + n) - 1;
        b_st.site = &fd_emlrtRSI;
        if ((ix0 <= b) && (b > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= b; k++) {
          x[k - 1] *= a;
        }
      }

      void d_xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[54],
                   int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T b;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ed_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b = (ix0 + n) - 1;
        b_st.site = &fd_emlrtRSI;
        if ((ix0 <= b) && (b > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= b; k++) {
          x[k - 1] *= a;
        }
      }

      void e_xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[27],
                   int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T b;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ed_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b = (ix0 + n) - 1;
        b_st.site = &fd_emlrtRSI;
        if ((ix0 <= b) && (b > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= b; k++) {
          x[k - 1] *= a;
        }
      }

      void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[3])
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T b;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ed_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b = n + 1;
        b_st.site = &fd_emlrtRSI;
        if ((2 <= n + 1) && (n + 1 > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = 2; k <= b; k++) {
          x[k - 1] *= a;
        }
      }

      void xscal(const emlrtStack *sp, real_T a, real_T x[3], int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T b;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ed_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b = ix0 + 1;
        b_st.site = &fd_emlrtRSI;
        if ((ix0 <= ix0 + 1) && (ix0 + 1 > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= b; k++) {
          x[k - 1] *= a;
        }
      }

      void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[9], int32_T
                 ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T b;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ed_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        b = (ix0 + n) - 1;
        b_st.site = &fd_emlrtRSI;
        if ((ix0 <= b) && (b > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= b; k++) {
          x[k - 1] *= a;
        }
      }
    }
  }
}

// End of code generation (xscal.cpp)
