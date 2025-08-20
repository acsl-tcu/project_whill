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
#include "EvaluationPath_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo xb_emlrtRSI = { 20, // lineNo
  "sum",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sum.m"// pathName
};

static emlrtRSInfo yb_emlrtRSI = { 99, // lineNo
  "sumprod",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pathName 
};

static emlrtRSInfo ac_emlrtRSI = { 133,// lineNo
  "combineVectorElements",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

static emlrtRSInfo bc_emlrtRSI = { 173,// lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

static emlrtRSInfo cc_emlrtRSI = { 194,// lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

static emlrtRSInfo fc_emlrtRSI = { 178,// lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

static emlrtRSInfo gc_emlrtRSI = { 196,// lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

static emlrtRTEInfo q_emlrtRTEI = { 76,// lineNo
  9,                                   // colNo
  "sumprod",                           // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pName 
};

static emlrtRTEInfo r_emlrtRTEI = { 46,// lineNo
  23,                                  // colNo
  "sumprod",                           // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pName 
};

static emlrtRTEInfo kd_emlrtRTEI = { 166,// lineNo
  24,                                  // colNo
  "combineVectorElements",             // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pName 
};

static emlrtRTEInfo ld_emlrtRTEI = { 20,// lineNo
  1,                                   // colNo
  "sum",                               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sum.m"// pName
};

// Function Definitions
namespace coder
{
  void sum(const emlrtStack *sp, const ::coder::array<real_T, 3U> &x, ::coder::
           array<real_T, 3U> &y)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    int32_T npages;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &xb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    b_st.site = &yb_emlrtRSI;
    if (x.size(2) == 0) {
      y.set_size(&ld_emlrtRTEI, &b_st, 1, 1, 0);
    } else {
      int32_T k;
      int32_T xpageoffset;
      c_st.site = &ac_emlrtRSI;
      npages = 1;
      k = 3;
      if (x.size(2) == 1) {
        k = 2;
      }

      for (xpageoffset = 3; xpageoffset <= k; xpageoffset++) {
        npages *= x.size(2);
      }

      y.set_size(&kd_emlrtRTEI, &c_st, 1, 1, static_cast<int32_T>
                 (static_cast<int16_T>(x.size(2))));
      d_st.site = &bc_emlrtRSI;
      if ((1 <= npages) && (npages > 2147483646)) {
        e_st.site = &v_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (int32_T i = 0; i < npages; i++) {
        xpageoffset = i * 20;
        d_st.site = &fc_emlrtRSI;
        y[i] = x[xpageoffset];
        for (k = 0; k < 19; k++) {
          d_st.site = &gc_emlrtRSI;
          y[i] = y[i] + x[(xpageoffset + k) + 1];
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
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &xb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    if ((x.size(0) == 1) && (x.size(1) != 1)) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    p = false;
    if ((x.size(0) == 0) && (x.size(1) == 0)) {
      p = true;
    }

    if (p) {
      emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
        "Coder:toolbox:UnsupportedSpecialEmpty",
        "Coder:toolbox:UnsupportedSpecialEmpty", 0);
    }

    b_st.site = &yb_emlrtRSI;
    vlen = x.size(0);
    if ((x.size(0) == 0) || (x.size(1) == 0)) {
      y.set_size(&ld_emlrtRTEI, &b_st, 1, x.size(1));
      vlen = x.size(1);
      for (int32_T npages = 0; npages < vlen; npages++) {
        y[npages] = 0.0;
      }
    } else {
      int32_T npages;
      c_st.site = &ac_emlrtRSI;
      npages = x.size(1);
      y.set_size(&kd_emlrtRTEI, &c_st, 1, x.size(1));
      d_st.site = &bc_emlrtRSI;
      if (x.size(1) > 2147483646) {
        e_st.site = &v_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (int32_T i = 0; i < npages; i++) {
        int32_T xpageoffset;
        xpageoffset = i * x.size(0);
        y[i] = x[xpageoffset];
        d_st.site = &cc_emlrtRSI;
        if ((2 <= vlen) && (vlen > 2147483646)) {
          e_st.site = &v_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (int32_T k = 2; k <= vlen; k++) {
          y[i] = y[i] + x[(xpageoffset + k) - 1];
        }
      }
    }
  }
}

// End of code generation (sum.cpp)
