//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  cos.cpp
//
//  Code generation for function 'cos'
//


// Include files
#include "cos.h"
#include "EvaluationPath_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo w_emlrtRSI = { 11,  // lineNo
  "cos",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/cos.m"// pathName
};

// Function Definitions
namespace coder
{
  void b_cos(const emlrtStack *sp, ::coder::array<real_T, 2U> &x)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T nx;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &w_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    nx = x.size(0) * x.size(1);
    b_st.site = &u_emlrtRSI;
    if ((1 <= nx) && (nx > 2147483646)) {
      c_st.site = &v_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (int32_T k = 0; k < nx; k++) {
      x[k] = muDoubleScalarCos(x[k]);
    }
  }
}

// End of code generation (cos.cpp)
