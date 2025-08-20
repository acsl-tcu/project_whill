//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  all.cpp
//
//  Code generation for function 'all'
//


// Include files
#include "all.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo neb_emlrtRSI = { 16,// lineNo
  "all",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/all.m"// pathName
};

static emlrtRSInfo oeb_emlrtRSI = { 139,// lineNo
  "allOrAny",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"// pathName 
};

static emlrtRSInfo peb_emlrtRSI = { 136,// lineNo
  "allOrAny",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"// pathName 
};

static emlrtRTEInfo kc_emlrtRTEI = { 19,// lineNo
  19,                                  // colNo
  "eml_int_forloop_overflow_check",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"// pName 
};

static emlrtRTEInfo il_emlrtRTEI = { 16,// lineNo
  5,                                   // colNo
  "all",                               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/all.m"// pName
};

// Function Definitions
namespace coder
{
  boolean_T all(const emlrtStack *sp, const ::coder::array<boolean_T, 1U> &x)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T ix;
    boolean_T exitg1;
    boolean_T y;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &tj_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    y = true;
    b_st.site = &uj_emlrtRSI;
    if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
      c_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    ix = 1;
    exitg1 = false;
    while ((!exitg1) && (ix <= x.size(0))) {
      if (!x[ix - 1]) {
        y = false;
        exitg1 = true;
      } else {
        ix++;
      }
    }

    return y;
  }

  void b_all(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &x, ::
             coder::array<boolean_T, 1U> &y)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T i1;
    int32_T i2;
    int32_T ix;
    int32_T iy;
    int32_T vstride;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &neb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    y.set_size(&il_emlrtRTEI, &st, x.size(0));
    vstride = x.size(0);
    for (i2 = 0; i2 < vstride; i2++) {
      y[i2] = true;
    }

    vstride = x.size(0);
    i2 = (x.size(1) - 1) * x.size(0);
    iy = -1;
    i1 = 0;
    b_st.site = &oeb_emlrtRSI;
    if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
      c_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (int32_T j = 0; j < vstride; j++) {
      boolean_T exitg1;
      boolean_T overflow;
      i1++;
      i2++;
      iy++;
      b_st.site = &uj_emlrtRSI;
      if ((vstride == 0) || (i1 > i2)) {
        overflow = false;
      } else {
        overflow = (i2 > MAX_int32_T - vstride);
      }

      if (vstride == 0) {
        emlrtErrorWithMessageIdR2018a(&b_st, &kc_emlrtRTEI,
          "Coder:builtins:VectorStride", "Coder:builtins:VectorStride", 0);
      }

      if (overflow) {
        c_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      ix = i1;
      exitg1 = false;
      while ((!exitg1) && (ix <= i2)) {
        if (!x[ix - 1]) {
          y[iy] = false;
          exitg1 = true;
        } else {
          ix += vstride;
        }
      }
    }
  }

  void c_all(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &x, ::
             coder::array<boolean_T, 2U> &y)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T i2;
    int32_T iy;
    int32_T npages;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &neb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    y.set_size(&il_emlrtRTEI, &st, 1, x.size(1));
    npages = x.size(1);
    for (i2 = 0; i2 < npages; i2++) {
      y[i2] = true;
    }

    npages = x.size(1);
    i2 = 0;
    iy = -1;
    b_st.site = &peb_emlrtRSI;
    if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
      c_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (int32_T i = 0; i < npages; i++) {
      int32_T a;
      int32_T i1;
      boolean_T exitg1;
      a = i2 + x.size(0);
      i1 = i2 + 1;
      i2 += x.size(0);
      iy++;
      b_st.site = &uj_emlrtRSI;
      if ((i1 <= a) && (a > 2147483646)) {
        c_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      exitg1 = false;
      while ((!exitg1) && (i1 <= a)) {
        if (!x[i1 - 1]) {
          y[iy] = false;
          exitg1 = true;
        } else {
          i1++;
        }
      }
    }
  }
}

// End of code generation (all.cpp)
