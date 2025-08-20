//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mode.cpp
//
//  Code generation for function 'mode'
//


// Include files
#include "mode.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo sn_emlrtRSI = { 93, // lineNo
  "arraymode",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/mode.m"// pathName
};

static emlrtRSInfo tn_emlrtRSI = { 148,// lineNo
  "vectormode",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/mode.m"// pathName
};

static emlrtRTEInfo wh_emlrtRTEI = { 148,// lineNo
  1,                                   // colNo
  "mode",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/mode.m"// pName
};

// Function Definitions
namespace coder
{
  uint32_T arraymode(const emlrtStack *sp, const ::coder::array<uint32_T, 1U> &x)
  {
    array<uint32_T, 1U> v;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    uint32_T M;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    if (x.size(0) == 0) {
      M = 0U;
    } else {
      int32_T ftmp;
      int32_T i;
      int32_T loop_ub;
      uint32_T mtmp;
      st.site = &sn_emlrtRSI;
      b_st.site = &tn_emlrtRSI;
      v.set_size(&wh_emlrtRTEI, &b_st, x.size(0));
      loop_ub = x.size(0);
      for (i = 0; i < loop_ub; i++) {
        v[i] = x[i];
      }

      c_st.site = &ig_emlrtRSI;
      internal::sort(&c_st, v);
      M = v[0];
      loop_ub = 1;
      mtmp = v[0];
      ftmp = 1;
      i = v.size(0);
      for (int32_T k = 0; k <= i - 2; k++) {
        uint32_T u;
        u = v[k + 1];
        if (u == mtmp) {
          ftmp++;
        } else {
          if (ftmp > loop_ub) {
            M = mtmp;
            loop_ub = ftmp;
          }

          mtmp = u;
          ftmp = 1;
        }
      }

      if (ftmp > loop_ub) {
        M = mtmp;
      }
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    return M;
  }
}

// End of code generation (mode.cpp)
