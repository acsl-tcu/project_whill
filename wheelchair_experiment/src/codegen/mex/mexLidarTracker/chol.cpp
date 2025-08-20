//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  chol.cpp
//
//  Code generation for function 'chol'
//


// Include files
#include "chol.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>

// Variable Definitions
static emlrtRSInfo lt_emlrtRSI = { 79, // lineNo
  "ceval_xpotrf",                      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xpotrf.m"// pathName 
};

static emlrtRSInfo nt_emlrtRSI = { 13, // lineNo
  "xpotrf",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xpotrf.m"// pathName 
};

static emlrtRTEInfo hd_emlrtRTEI = { 99,// lineNo
  5,                                   // colNo
  "cholesky",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/chol.m"// pName
};

// Function Definitions
namespace coder
{
  int32_T cholesky(const emlrtStack *sp, real_T A_data[], int32_T A_size[2])
  {
    static const char_T fname[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
      'd', 'p', 'o', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

    ptrdiff_t info_t;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T b_A_data[36];
    int32_T a;
    int32_T i;
    int32_T info;
    int32_T j;
    int32_T jmax;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &kt_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    b_st.site = &nt_emlrtRSI;
    info_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)A_size[1], &A_data[0],
      (ptrdiff_t)A_size[1]);
    info = (int32_T)info_t;
    c_st.site = &lt_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&c_st, &ac_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &yb_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 19, fname, 12, info);
      }
    }

    if (info == 0) {
      jmax = A_size[1];
    } else {
      jmax = info - 1;
    }

    st.site = &jt_emlrtRSI;
    for (j = 0; j < jmax; j++) {
      a = j + 2;
      st.site = &it_emlrtRSI;
      for (i = a; i <= jmax; i++) {
        A_data[(i + A_size[0] * j) - 1] = 0.0;
      }
    }

    if (jmax > A_size[0]) {
      emlrtErrorWithMessageIdR2018a(sp, &hd_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > jmax) {
      j = 0;
      a = 0;
    } else {
      j = jmax;
      a = jmax;
    }

    for (jmax = 0; jmax < a; jmax++) {
      for (i = 0; i < j; i++) {
        b_A_data[i + j * jmax] = A_data[i + A_size[0] * jmax];
      }
    }

    A_size[0] = j;
    A_size[1] = a;
    for (jmax = 0; jmax < a; jmax++) {
      for (i = 0; i < j; i++) {
        A_data[i + A_size[0] * jmax] = b_A_data[i + j * jmax];
      }
    }

    return info;
  }
}

// End of code generation (chol.cpp)
