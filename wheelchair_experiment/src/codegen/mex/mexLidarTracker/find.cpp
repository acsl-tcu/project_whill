//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  find.cpp
//
//  Code generation for function 'find'
//


// Include files
#include "find.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo kf_emlrtRSI = { 144,// lineNo
  "eml_find",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

static emlrtRSInfo lf_emlrtRSI = { 382,// lineNo
  "find_first_indices",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

static emlrtRSInfo mf_emlrtRSI = { 402,// lineNo
  "find_first_indices",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

static emlrtRTEInfo q_emlrtRTEI = { 392,// lineNo
  1,                                   // colNo
  "find_first_indices",                // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

static emlrtRTEInfo hf_emlrtRTEI = { 369,// lineNo
  24,                                  // colNo
  "find",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

static emlrtRTEInfo if_emlrtRTEI = { 144,// lineNo
  9,                                   // colNo
  "find",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

static emlrtRTEInfo rh_emlrtRTEI = { 364,// lineNo
  24,                                  // colNo
  "find",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

// Function Definitions
namespace coder
{
  void b_eml_find(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &x, ::
                  coder::array<int32_T, 2U> &i)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T idx;
    int32_T ii;
    int32_T nx;
    boolean_T exitg1;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    nx = x.size(1);
    st.site = &kf_emlrtRSI;
    idx = 0;
    i.set_size(&rh_emlrtRTEI, &st, 1, x.size(1));
    b_st.site = &lf_emlrtRSI;
    if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
      c_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= nx - 1)) {
      if (x[ii]) {
        idx++;
        i[idx - 1] = ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ii++;
        }
      } else {
        ii++;
      }
    }

    if (idx > x.size(1)) {
      emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (x.size(1) == 1) {
      if (idx == 0) {
        i.set_size(&if_emlrtRTEI, &st, 1, 0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      i.set_size(&if_emlrtRTEI, &st, i.size(0), idx);
    }
  }

  void c_eml_find(const boolean_T x[30], int32_T i_data[], int32_T i_size[2])
  {
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    idx = 0;
    i_size[0] = 1;
    i_size[1] = 1;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii < 30)) {
      if (x[ii]) {
        idx = 1;
        i_data[0] = ii + 1;
        exitg1 = true;
      } else {
        ii++;
      }
    }

    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  }

  void eml_find(const emlrtStack *sp, const ::coder::array<boolean_T, 1U> &x, ::
                coder::array<int32_T, 1U> &i)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T b_iv[2];
    int32_T idx;
    int32_T ii;
    int32_T nx;
    boolean_T exitg1;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    nx = x.size(0);
    st.site = &kf_emlrtRSI;
    idx = 0;
    i.set_size(&hf_emlrtRTEI, &st, x.size(0));
    b_st.site = &lf_emlrtRSI;
    if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
      c_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= nx - 1)) {
      if (x[ii]) {
        idx++;
        i[idx - 1] = ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ii++;
        }
      } else {
        ii++;
      }
    }

    if (idx > x.size(0)) {
      emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (x.size(0) == 1) {
      if (idx == 0) {
        i.set_size(&if_emlrtRTEI, &st, 0);
      }
    } else {
      if (1 > idx) {
        nx = 0;
      } else {
        nx = idx;
      }

      b_iv[0] = 1;
      b_iv[1] = nx;
      b_st.site = &mf_emlrtRSI;
      internal::indexShapeCheck(&b_st, i.size(0), b_iv);
      i.set_size(&if_emlrtRTEI, &st, nx);
    }
  }
}

// End of code generation (find.cpp)
