//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  sin.cpp
//
//  Code generation for function 'sin'
//


// Include files
#include "sin.h"
#include "EvaluationPath_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo t_emlrtRSI = { 11,  // lineNo
  "sin",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/sin.m"// pathName
};

// Function Definitions
namespace coder
{
  void b_sin(const emlrtStack *sp, ::coder::array<real_T, 2U> &x)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T nx;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &t_emlrtRSI;
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
      x[k] = muDoubleScalarSin(x[k]);
    }
  }
}

// End of code generation (sin.cpp)
