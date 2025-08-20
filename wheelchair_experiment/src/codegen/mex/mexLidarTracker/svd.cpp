//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  svd.cpp
//
//  Code generation for function 'svd'
//


// Include files
#include "svd.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "xzsvdc.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo fc_emlrtRSI = { 15, // lineNo
  "svd",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/svd.m"// pathName
};

static emlrtRSInfo kc_emlrtRSI = { 29, // lineNo
  "svd",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/svd.m"// pathName
};

// Function Definitions
namespace coder
{
  void svd(const emlrtStack *sp, const real_T A[9], real_T U[3])
  {
    static const int32_T b_iv[2] = { 3, 3 };

    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack st;
    real_T b_A[9];
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ec_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    b_st.site = &gc_emlrtRSI;
    c_st.site = &hc_emlrtRSI;
    p = internal::flatVectorAllOrAny(A, b_iv);
    if (p) {
      st.site = &fc_emlrtRSI;
      b_st.site = &kc_emlrtRSI;
      c_st.site = &lc_emlrtRSI;
      memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
      d_st.site = &mc_emlrtRSI;
      internal::reflapack::xzsvdc(&d_st, b_A, U);
    } else {
      U[0] = rtNaN;
      U[1] = rtNaN;
      U[2] = rtNaN;
    }
  }
}

// End of code generation (svd.cpp)
