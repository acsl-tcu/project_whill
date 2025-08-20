//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  hypot.cpp
//
//  Code generation for function 'hypot'
//


// Include files
#include "hypot.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "scalexpAlloc.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo wkb_emlrtRSI = { 13,// lineNo
  "hypot",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/hypot.m"// pathName
};

// Function Definitions
namespace coder
{
  void b_hypot(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x, const ::
               coder::array<real_T, 1U> &y, ::coder::array<real_T, 1U> &r)
  {
    array<real_T, 1U> z;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack st;
    int32_T csz_idx_0;
    int32_T k;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &wkb_emlrtRSI;
    b_st.site = &chb_emlrtRSI;
    if (x.size(0) <= y.size(0)) {
      csz_idx_0 = x.size(0);
      k = x.size(0);
    } else {
      csz_idx_0 = y.size(0);
      k = y.size(0);
    }

    z.set_size(&nm_emlrtRTEI, &b_st, k);
    if (!internal::dimagree(z, x, y)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &uc_emlrtRTEI, "MATLAB:dimagree",
        "MATLAB:dimagree", 0);
    }

    r.set_size(&uf_emlrtRTEI, &st, csz_idx_0);
    b_st.site = &il_emlrtRSI;
    c_st.site = &dhb_emlrtRSI;
    if ((1 <= z.size(0)) && (z.size(0) > 2147483646)) {
      d_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k < csz_idx_0; k++) {
      r[k] = muDoubleScalarHypot(x[k], y[k]);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }
}

// End of code generation (hypot.cpp)
