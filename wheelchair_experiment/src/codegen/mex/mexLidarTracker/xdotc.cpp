//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xdotc.cpp
//
//  Code generation for function 'xdotc'
//


// Include files
#include "xdotc.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo gd_emlrtRSI = { 32, // lineNo
  "xdotc",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/xdotc.m"// pathName 
};

static emlrtRSInfo hd_emlrtRSI = { 35, // lineNo
  "xdot",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/xdot.m"// pathName 
};

static emlrtRSInfo id_emlrtRSI = { 15, // lineNo
  "xdot",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xdot.m"// pathName 
};

static emlrtRSInfo jd_emlrtRSI = { 42, // lineNo
  "xdotx",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xdotx.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace blas
    {
      real_T b_xdotc(const emlrtStack *sp, int32_T n, const real_T x[36],
                     int32_T ix0, const real_T y[36], int32_T iy0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack d_st;
        emlrtStack e_st;
        emlrtStack st;
        real_T d;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &gd_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        d_st.prev = &c_st;
        d_st.tls = c_st.tls;
        e_st.prev = &d_st;
        e_st.tls = d_st.tls;
        b_st.site = &hd_emlrtRSI;
        c_st.site = &id_emlrtRSI;
        d = 0.0;
        if (n >= 1) {
          int32_T ix;
          int32_T iy;
          ix = ix0;
          iy = iy0;
          d_st.site = &jd_emlrtRSI;
          if (n > 2147483646) {
            e_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          for (int32_T k = 0; k < n; k++) {
            d += x[ix - 1] * y[iy - 1];
            ix++;
            iy++;
          }
        }

        return d;
      }

      real_T xdotc(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T
                   ix0, const real_T y[9], int32_T iy0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack d_st;
        emlrtStack e_st;
        emlrtStack st;
        real_T d;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &gd_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        d_st.prev = &c_st;
        d_st.tls = c_st.tls;
        e_st.prev = &d_st;
        e_st.tls = d_st.tls;
        b_st.site = &hd_emlrtRSI;
        c_st.site = &id_emlrtRSI;
        d = 0.0;
        if (n >= 1) {
          int32_T ix;
          int32_T iy;
          ix = ix0;
          iy = iy0;
          d_st.site = &jd_emlrtRSI;
          if (n > 2147483646) {
            e_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          for (int32_T k = 0; k < n; k++) {
            d += x[ix - 1] * y[iy - 1];
            ix++;
            iy++;
          }
        }

        return d;
      }
    }
  }
}

// End of code generation (xdotc.cpp)
