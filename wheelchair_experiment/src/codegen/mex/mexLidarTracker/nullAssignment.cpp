//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  nullAssignment.cpp
//
//  Code generation for function 'nullAssignment'
//


// Include files
#include "nullAssignment.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo teb_emlrtRSI = { 13,// lineNo
  "nullAssignment",                    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo ueb_emlrtRSI = { 17,// lineNo
  "nullAssignment",                    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo web_emlrtRSI = { 167,// lineNo
  "onearg_null_assignment",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo xeb_emlrtRSI = { 169,// lineNo
  "onearg_null_assignment",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo yeb_emlrtRSI = { 172,// lineNo
  "onearg_null_assignment",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo afb_emlrtRSI = { 259,// lineNo
  "make_bitarray",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo bfb_emlrtRSI = { 132,// lineNo
  "num_true",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRTEInfo mc_emlrtRTEI = { 85,// lineNo
  27,                                  // colNo
  "validate_inputs",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pName 
};

static emlrtRTEInfo kd_emlrtRTEI = { 184,// lineNo
  9,                                   // colNo
  "onearg_null_assignment",            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pName 
};

static emlrtRTEInfo ll_emlrtRTEI = { 17,// lineNo
  9,                                   // colNo
  "nullAssignment",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pName 
};

static emlrtRTEInfo eo_emlrtRTEI = { 167,// lineNo
  9,                                   // colNo
  "nullAssignment",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    void nullAssignment(const emlrtStack *sp, ::coder::array<real_T, 2U> &x,
                        const ::coder::array<int32_T, 2U> &idx)
    {
      array<boolean_T, 2U> b;
      emlrtStack b_st;
      emlrtStack c_st;
      emlrtStack d_st;
      emlrtStack st;
      int32_T k;
      int32_T k0;
      int32_T nxin;
      int32_T nxout;
      boolean_T exitg1;
      boolean_T p;
      st.prev = sp;
      st.tls = sp->tls;
      b_st.prev = &st;
      b_st.tls = st.tls;
      c_st.prev = &b_st;
      c_st.tls = b_st.tls;
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      emlrtHeapReferenceStackEnterFcnR2012b(sp);
      st.site = &teb_emlrtRSI;
      p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= idx.size(1) - 1)) {
        if (idx[k] > x.size(1)) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (!p) {
        emlrtErrorWithMessageIdR2018a(&st, &mc_emlrtRTEI,
          "MATLAB:subsdeldimmismatch", "MATLAB:subsdeldimmismatch", 0);
      }

      st.site = &ueb_emlrtRSI;
      nxin = x.size(1);
      b_st.site = &web_emlrtRSI;
      b.set_size(&eo_emlrtRTEI, &b_st, 1, x.size(1));
      nxout = x.size(1);
      for (k0 = 0; k0 < nxout; k0++) {
        b[k0] = false;
      }

      nxout = idx.size(1);
      c_st.site = &afb_emlrtRSI;
      if ((1 <= idx.size(1)) && (idx.size(1) > 2147483646)) {
        d_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 0; k < nxout; k++) {
        b[idx[k] - 1] = true;
      }

      b_st.site = &xeb_emlrtRSI;
      k0 = 0;
      nxout = b.size(1);
      c_st.site = &bfb_emlrtRSI;
      if ((1 <= b.size(1)) && (b.size(1) > 2147483646)) {
        d_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 0; k < nxout; k++) {
        k0 += b[k];
      }

      nxout = x.size(1) - k0;
      k0 = -1;
      b_st.site = &yeb_emlrtRSI;
      if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
        c_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (k = 0; k < nxin; k++) {
        if ((k + 1 > b.size(1)) || (!b[k])) {
          k0++;
          x[k0] = x[k];
        }
      }

      if (nxout > nxin) {
        emlrtErrorWithMessageIdR2018a(&st, &kd_emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      if (1 > nxout) {
        nxout = 0;
      }

      x.set_size(&ll_emlrtRTEI, &st, x.size(0), nxout);
      emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    }
  }
}

// End of code generation (nullAssignment.cpp)
