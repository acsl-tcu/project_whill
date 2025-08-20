//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xnrm2.cpp
//
//  Code generation for function 'xnrm2'
//


// Include files
#include "xnrm2.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ad_emlrtRSI = { 23, // lineNo
  "xnrm2",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/xnrm2.m"// pathName 
};

static emlrtRSInfo bd_emlrtRSI = { 38, // lineNo
  "xnrm2",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xnrm2.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace blas
    {
      real_T b_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[36],
                     int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T y;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ad_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        y = 0.0;
        if (n >= 1) {
          if (n == 1) {
            y = muDoubleScalarAbs(x[ix0 - 1]);
          } else {
            real_T scale;
            int32_T kend;
            scale = 3.3121686421112381E-170;
            kend = (ix0 + n) - 1;
            b_st.site = &bd_emlrtRSI;
            if ((ix0 <= kend) && (kend > 2147483646)) {
              c_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            for (int32_T k = ix0; k <= kend; k++) {
              real_T absxk;
              absxk = muDoubleScalarAbs(x[k - 1]);
              if (absxk > scale) {
                real_T t;
                t = scale / absxk;
                y = y * t * t + 1.0;
                scale = absxk;
              } else {
                real_T t;
                t = absxk / scale;
                y += t * t;
              }
            }

            y = scale * muDoubleScalarSqrt(y);
          }
        }

        return y;
      }

      real_T c_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[6], int32_T
                     ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T scale;
        real_T y;
        int32_T kend;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ad_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        y = 0.0;
        scale = 3.3121686421112381E-170;
        kend = (ix0 + n) - 1;
        b_st.site = &bd_emlrtRSI;
        if ((ix0 <= kend) && (kend > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= kend; k++) {
          real_T absxk;
          absxk = muDoubleScalarAbs(x[k - 1]);
          if (absxk > scale) {
            real_T t;
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            real_T t;
            t = absxk / scale;
            y += t * t;
          }
        }

        return scale * muDoubleScalarSqrt(y);
      }

      real_T d_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[54],
                     int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T scale;
        real_T y;
        int32_T kend;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ad_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        y = 0.0;
        scale = 3.3121686421112381E-170;
        kend = (ix0 + n) - 1;
        b_st.site = &bd_emlrtRSI;
        if ((ix0 <= kend) && (kend > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= kend; k++) {
          real_T absxk;
          absxk = muDoubleScalarAbs(x[k - 1]);
          if (absxk > scale) {
            real_T t;
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            real_T t;
            t = absxk / scale;
            y += t * t;
          }
        }

        return scale * muDoubleScalarSqrt(y);
      }

      real_T e_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[27],
                     int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T scale;
        real_T y;
        int32_T kend;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ad_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        y = 0.0;
        scale = 3.3121686421112381E-170;
        kend = (ix0 + n) - 1;
        b_st.site = &bd_emlrtRSI;
        if ((ix0 <= kend) && (kend > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= kend; k++) {
          real_T absxk;
          absxk = muDoubleScalarAbs(x[k - 1]);
          if (absxk > scale) {
            real_T t;
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            real_T t;
            t = absxk / scale;
            y += t * t;
          }
        }

        return scale * muDoubleScalarSqrt(y);
      }

      real_T xnrm2(int32_T n, const real_T x[3])
      {
        real_T y;
        y = 0.0;
        if (n >= 1) {
          if (n == 1) {
            y = muDoubleScalarAbs(x[1]);
          } else {
            real_T absxk;
            real_T scale;
            real_T t;
            scale = 3.3121686421112381E-170;
            absxk = muDoubleScalarAbs(x[1]);
            if (absxk > 3.3121686421112381E-170) {
              y = 1.0;
              scale = absxk;
            } else {
              t = absxk / 3.3121686421112381E-170;
              y = t * t;
            }

            absxk = muDoubleScalarAbs(x[2]);
            if (absxk > scale) {
              t = scale / absxk;
              y = y * t * t + 1.0;
              scale = absxk;
            } else {
              t = absxk / scale;
              y += t * t;
            }

            y = scale * muDoubleScalarSqrt(y);
          }
        }

        return y;
      }

      real_T xnrm2(const emlrtStack *sp, const real_T x[3], int32_T ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T scale;
        real_T y;
        int32_T kend;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ad_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        y = 0.0;
        scale = 3.3121686421112381E-170;
        kend = ix0 + 1;
        b_st.site = &bd_emlrtRSI;
        if ((ix0 <= ix0 + 1) && (ix0 + 1 > 2147483646)) {
          c_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (int32_T k = ix0; k <= kend; k++) {
          real_T absxk;
          absxk = muDoubleScalarAbs(x[k - 1]);
          if (absxk > scale) {
            real_T t;
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            real_T t;
            t = absxk / scale;
            y += t * t;
          }
        }

        return scale * muDoubleScalarSqrt(y);
      }

      real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T
                   ix0)
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T y;
        st.prev = sp;
        st.tls = sp->tls;
        st.site = &ad_emlrtRSI;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        y = 0.0;
        if (n >= 1) {
          if (n == 1) {
            y = muDoubleScalarAbs(x[ix0 - 1]);
          } else {
            real_T scale;
            int32_T kend;
            scale = 3.3121686421112381E-170;
            kend = (ix0 + n) - 1;
            b_st.site = &bd_emlrtRSI;
            if ((ix0 <= kend) && (kend > 2147483646)) {
              c_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            for (int32_T k = ix0; k <= kend; k++) {
              real_T absxk;
              absxk = muDoubleScalarAbs(x[k - 1]);
              if (absxk > scale) {
                real_T t;
                t = scale / absxk;
                y = y * t * t + 1.0;
                scale = absxk;
              } else {
                real_T t;
                t = absxk / scale;
                y += t * t;
              }
            }

            y = scale * muDoubleScalarSqrt(y);
          }
        }

        return y;
      }
    }
  }
}

// End of code generation (xnrm2.cpp)
