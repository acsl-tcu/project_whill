//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xrot.cpp
//
//  Code generation for function 'xrot'
//


// Include files
#include "xrot.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo gq_emlrtRSI = { 32, // lineNo
  "xrot",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/xrot.m"// pathName 
};

static emlrtRSInfo hq_emlrtRSI = { 24, // lineNo
  "xrot",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xrot.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace blas
    {
      void b_xrot(const emlrtStack *sp, int32_T n, real_T x[36], int32_T ix0,
                  int32_T iy0, real_T c, real_T s)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T ix;
        int32_T iy;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &gq_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        ix = ix0 - 1;
        iy = iy0 - 1;
        b_st.site = &hq_emlrtRSI;
        if ((1 <= n) && (n > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = 0; k < n; k++) {
          real_T temp;
          temp = c * x[ix] + s * x[iy];
          x[iy] = c * x[iy] - s * x[ix];
          x[ix] = temp;
          iy += 6;
          ix += 6;
        }
      }

      void b_xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T c, real_T s)
      {
        real_T temp;
        real_T temp_tmp;
        temp = x[iy0 - 1];
        temp_tmp = x[ix0 - 1];
        x[iy0 - 1] = c * temp - s * temp_tmp;
        x[ix0 - 1] = c * temp_tmp + s * temp;
        temp = c * x[ix0] + s * x[iy0];
        x[iy0] = c * x[iy0] - s * x[ix0];
        x[ix0] = temp;
        temp = x[iy0 + 1];
        temp_tmp = x[ix0 + 1];
        x[iy0 + 1] = c * temp - s * temp_tmp;
        x[ix0 + 1] = c * temp_tmp + s * temp;
      }

      void c_xrot(const emlrtStack *sp, int32_T n, real_T x[36], int32_T ix0,
                  int32_T iy0, real_T c, real_T s)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &gq_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        if (n >= 1) {
          int32_T ix;
          int32_T iy;
          ix = ix0 - 1;
          iy = iy0 - 1;
          b_st.site = &hq_emlrtRSI;
          if (n > 2147483646) {
            c_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (int32_T k = 0; k < n; k++) {
            real_T temp;
            temp = c * x[ix] + s * x[iy];
            x[iy] = c * x[iy] - s * x[ix];
            x[ix] = temp;
            iy++;
            ix++;
          }
        }
      }

      void xrot(const emlrtStack *sp, int32_T n, real_T x[9], int32_T ix0,
                int32_T iy0, real_T c, real_T s)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        int32_T ix;
        int32_T iy;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &gq_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        ix = ix0 - 1;
        iy = iy0 - 1;
        b_st.site = &hq_emlrtRSI;
        if ((1 <= n) && (n > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = 0; k < n; k++) {
          real_T temp;
          temp = c * x[ix] + s * x[iy];
          x[iy] = c * x[iy] - s * x[ix];
          x[ix] = temp;
          iy += 3;
          ix += 3;
        }
      }

      void xrot(int32_T n, real_T x[9], int32_T ix0, int32_T iy0, real_T c,
                real_T s)
      {
        if (n >= 1) {
          real_T b_temp_tmp;
          real_T temp_tmp;
          temp_tmp = x[iy0 - 1];
          b_temp_tmp = x[ix0 - 1];
          x[iy0 - 1] = c * temp_tmp - s * b_temp_tmp;
          x[ix0 - 1] = c * b_temp_tmp + s * temp_tmp;
        }
      }

      void xrot(real_T x[36], int32_T ix0, int32_T iy0, real_T c, real_T s)
      {
        int32_T ix;
        int32_T iy;
        ix = ix0 - 1;
        iy = iy0 - 1;
        for (int32_T k = 0; k < 6; k++) {
          real_T temp;
          temp = c * x[ix] + s * x[iy];
          x[iy] = c * x[iy] - s * x[ix];
          x[ix] = temp;
          iy++;
          ix++;
        }
      }
    }
  }
}

// End of code generation (xrot.cpp)
