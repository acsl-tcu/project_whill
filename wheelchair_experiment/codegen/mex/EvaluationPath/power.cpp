//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  power.cpp
//
//  Code generation for function 'power'
//


// Include files
#include "power.h"
#include "EvaluationPath_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo dc_emlrtRSI = { 79, // lineNo
  "fltpower",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"// pathName
};

static emlrtRTEInfo hd_emlrtRTEI = { 46,// lineNo
  6,                                   // colNo
  "applyBinaryScalarFunction",         // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pName 
};

// Function Definitions
namespace coder
{
  void power(const emlrtStack *sp, const ::coder::array<real_T, 3U> &a, ::coder::
             array<real_T, 3U> &y)
  {
    emlrtStack b_st;
    emlrtStack st;
    int32_T nx;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &wb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    b_st.site = &dc_emlrtRSI;
    y.set_size(&hd_emlrtRTEI, &b_st, 1, 20, static_cast<int32_T>
               (static_cast<int16_T>(a.size(2))));
    nx = 20 * static_cast<int16_T>(a.size(2));
    for (int32_T k = 0; k < nx; k++) {
      y[k] = a[k] * a[k];
    }
  }
}

// End of code generation (power.cpp)
