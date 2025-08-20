//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  sum.cpp
//
//  Code generation for function 'sum'
//


// Include files
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRTEInfo yl_emlrtRTEI = { 20,// lineNo
  1,                                   // colNo
  "sum",                               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sum.m"// pName
};

// Function Definitions
namespace coder
{
  void sum(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x, ::coder::
           array<real_T, 1U> &y)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    int32_T vlen;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &fk_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    b_st.site = &xi_emlrtRSI;
    vlen = x.size(1);
    if (x.size(0) == 0) {
      y.set_size(&yl_emlrtRTEI, &b_st, 0);
    } else {
      int32_T j;
      int32_T vstride;
      c_st.site = &yi_emlrtRSI;
      vstride = x.size(0);
      y.set_size(&kg_emlrtRTEI, &c_st, x.size(0));
      d_st.site = &aj_emlrtRSI;
      if (x.size(0) > 2147483646) {
        e_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (j = 0; j < vstride; j++) {
        y[j] = x[j];
      }

      d_st.site = &lk_emlrtRSI;
      if ((2 <= x.size(1)) && (x.size(1) > 2147483646)) {
        e_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (int32_T k = 2; k <= vlen; k++) {
        int32_T xoffset;
        xoffset = (k - 1) * vstride;
        d_st.site = &bj_emlrtRSI;
        if (vstride > 2147483646) {
          e_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (j = 0; j < vstride; j++) {
          y[j] = y[j] + x[xoffset + j];
        }
      }
    }
  }

  void sum(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x, ::coder::
           array<real_T, 2U> &y)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    int32_T vlen;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &fk_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    b_st.site = &xi_emlrtRSI;
    vlen = x.size(0);
    if (x.size(0) == 0) {
      vlen = x.size(1);
      y.set_size(&yl_emlrtRTEI, &b_st, 1, x.size(1));
      for (int32_T npages = 0; npages < vlen; npages++) {
        y[npages] = 0.0;
      }
    } else {
      int32_T npages;
      c_st.site = &yi_emlrtRSI;
      npages = x.size(1);
      y.set_size(&kg_emlrtRTEI, &c_st, 1, x.size(1));
      d_st.site = &ogb_emlrtRSI;
      for (int32_T i = 0; i < npages; i++) {
        int32_T xpageoffset;
        xpageoffset = i * x.size(0);
        y[i] = x[xpageoffset];
        d_st.site = &lk_emlrtRSI;
        if ((2 <= vlen) && (vlen > 2147483646)) {
          e_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (int32_T k = 2; k <= vlen; k++) {
          y[i] = y[i] + x[(xpageoffset + k) - 1];
        }
      }
    }
  }

  real_T sum(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    real_T y;
    int32_T vlen;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &fk_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    b_st.site = &xi_emlrtRSI;
    vlen = x.size(0);
    if (x.size(0) == 0) {
      y = 0.0;
    } else {
      c_st.site = &yi_emlrtRSI;
      y = x[0];
      d_st.site = &lk_emlrtRSI;
      if ((2 <= x.size(0)) && (x.size(0) > 2147483646)) {
        e_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (int32_T k = 2; k <= vlen; k++) {
        y += x[k - 1];
      }
    }

    return y;
  }
}

// End of code generation (sum.cpp)
