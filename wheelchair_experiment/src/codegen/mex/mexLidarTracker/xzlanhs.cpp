//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xzlanhs.cpp
//
//  Code generation for function 'xzlanhs'
//


// Include files
#include "xzlanhs.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo pr_emlrtRSI = { 21, // lineNo
  "xzlanhs",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlanhs.m"// pathName 
};

static emlrtRSInfo qr_emlrtRSI = { 26, // lineNo
  "xzlanhs",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlanhs.m"// pathName 
};

static emlrtRSInfo rr_emlrtRSI = { 47, // lineNo
  "xzlanhs",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlanhs.m"// pathName 
};

static emlrtRSInfo sr_emlrtRSI = { 49, // lineNo
  "xzlanhs",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlanhs.m"// pathName 
};

static emlrtRSInfo tr_emlrtRSI = { 53, // lineNo
  "xzlanhs",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlanhs.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace reflapack
    {
      real_T xzlanhs(const emlrtStack *sp, const creal_T A[9], int32_T ilo,
                     int32_T ihi)
      {
        emlrtStack b_st;
        emlrtStack st;
        real_T colssq;
        real_T f;
        real_T ssq;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        f = 0.0;
        if (ilo <= ihi) {
          real_T scale;
          int32_T nm1;
          scale = 3.3121686421112381E-170;
          ssq = 0.0;
          nm1 = ihi - ilo;
          st.site = &pr_emlrtRSI;
          if ((1 <= nm1 + 1) && (nm1 + 1 > 2147483646)) {
            b_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          for (int32_T j = 0; j <= nm1; j++) {
            real_T absxk;
            real_T colscale;
            int32_T b;
            int32_T col;
            colscale = 3.3121686421112381E-170;
            colssq = 0.0;
            col = (ilo + j) - 1;
            b = j + 1;
            b = ilo + muIntScalarMin_sint32(b, nm1);
            st.site = &qr_emlrtRSI;
            if ((ilo <= b) && (b > 2147483646)) {
              b_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&b_st);
            }

            for (int32_T row = ilo; row <= b; row++) {
              real_T t;
              int32_T re_tmp;
              re_tmp = (row + 3 * col) - 1;
              absxk = muDoubleScalarAbs(A[re_tmp].re);
              if (absxk > colscale) {
                t = colscale / absxk;
                colssq = colssq * t * t + 1.0;
                colscale = absxk;
              } else {
                t = absxk / colscale;
                colssq += t * t;
              }

              absxk = muDoubleScalarAbs(A[re_tmp].im);
              if (absxk > colscale) {
                t = colscale / absxk;
                colssq = colssq * t * t + 1.0;
                colscale = absxk;
              } else {
                t = absxk / colscale;
                colssq += t * t;
              }
            }

            if (scale >= colscale) {
              st.site = &rr_emlrtRSI;
              absxk = colscale / scale;
              ssq += absxk * absxk * colssq;
            } else {
              st.site = &sr_emlrtRSI;
              absxk = scale / colscale;
              ssq = colssq + absxk * absxk * ssq;
              scale = colscale;
            }
          }

          st.site = &tr_emlrtRSI;
          f = scale * muDoubleScalarSqrt(ssq);
        }

        return f;
      }
    }
  }
}

// End of code generation (xzlanhs.cpp)
