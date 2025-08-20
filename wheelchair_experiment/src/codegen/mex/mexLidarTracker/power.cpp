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
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "scalexpAlloc.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ic_emlrtRSI = { 103,// lineNo
  "flatVectorAllOrAny",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"// pathName 
};

static emlrtRSInfo ahb_emlrtRSI = { 79,// lineNo
  "fltpower",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"// pathName
};

static emlrtRSInfo bhb_emlrtRSI = { 81,// lineNo
  "fltpower",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"// pathName
};

static emlrtRSInfo ehb_emlrtRSI = { 94,// lineNo
  "fltpower_domain_error",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"// pathName
};

static emlrtRSInfo fhb_emlrtRSI = { 101,// lineNo
  "fltpower_domain_error",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"// pathName
};

static emlrtRTEInfo tc_emlrtRTEI = { 82,// lineNo
  5,                                   // colNo
  "fltpower",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"// pName
};

// Function Definitions
namespace coder
{
  void power(const emlrtStack *sp, const ::coder::array<real_T, 1U> &a, const ::
             coder::array<real_T, 1U> &b, ::coder::array<real_T, 1U> &y)
  {
    array<real_T, 1U> z;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack st;
    int32_T csz_idx_0;
    int32_T k;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    f_st.prev = &e_st;
    f_st.tls = e_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &qk_emlrtRSI;
    b_st.site = &ahb_emlrtRSI;
    c_st.site = &chb_emlrtRSI;
    if (a.size(0) <= b.size(0)) {
      csz_idx_0 = a.size(0);
      k = a.size(0);
    } else {
      csz_idx_0 = b.size(0);
      k = b.size(0);
    }

    z.set_size(&nm_emlrtRTEI, &c_st, k);
    if (!internal::dimagree(z, a, b)) {
      emlrtErrorWithMessageIdR2018a(&c_st, &uc_emlrtRTEI, "MATLAB:dimagree",
        "MATLAB:dimagree", 0);
    }

    y.set_size(&uf_emlrtRTEI, &b_st, csz_idx_0);
    c_st.site = &il_emlrtRSI;
    d_st.site = &dhb_emlrtRSI;
    if ((1 <= z.size(0)) && (z.size(0) > 2147483646)) {
      e_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 0; k < csz_idx_0; k++) {
      y[k] = muDoubleScalarPower(a[k], b[k]);
    }

    b_st.site = &bhb_emlrtRSI;
    if (a.size(0) == 1) {
      if (a[0] < 0.0) {
        c_st.site = &ehb_emlrtRSI;
        d_st.site = &hc_emlrtRSI;
        csz_idx_0 = b.size(0);
        p = false;
        e_st.site = &ic_emlrtRSI;
        if ((1 <= b.size(0)) && (b.size(0) > 2147483646)) {
          f_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (k = 0; k < csz_idx_0; k++) {
          if (p || ((!muDoubleScalarIsNaN(b[k])) && (muDoubleScalarFloor(b[k])
                != b[k]))) {
            p = true;
          }
        }
      } else {
        p = false;
      }
    } else if (b.size(0) == 1) {
      if ((!muDoubleScalarIsNaN(b[0])) && (muDoubleScalarFloor(b[0]) != b[0])) {
        c_st.site = &fhb_emlrtRSI;
        d_st.site = &hc_emlrtRSI;
        csz_idx_0 = a.size(0);
        p = false;
        e_st.site = &ic_emlrtRSI;
        if ((1 <= a.size(0)) && (a.size(0) > 2147483646)) {
          f_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (k = 0; k < csz_idx_0; k++) {
          if (p || (a[k] < 0.0)) {
            p = true;
          }
        }
      } else {
        p = false;
      }
    } else {
      p = false;
      csz_idx_0 = a.size(0);
      for (k = 0; k < csz_idx_0; k++) {
        if (p || ((a[k] < 0.0) && (!muDoubleScalarIsNaN(b[k])) &&
                  (muDoubleScalarFloor(b[k]) != b[k]))) {
          p = true;
        }
      }
    }

    if (p) {
      emlrtErrorWithMessageIdR2018a(&st, &tc_emlrtRTEI,
        "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }
}

// End of code generation (power.cpp)
