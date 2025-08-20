//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inpolygon.cpp
//
// Code generation for function 'inpolygon'
//

// Include files
#include "inpolygon.h"
#include "WP_extraction_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo l_emlrtRSI{
    331,            // lineNo
    "computeRange", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

// Function Definitions
namespace coder {
void computeRange(const emlrtStack *sp, const real_T xv[4], int32_T nloops,
                  const int32_T first[4], const int32_T last[4], real_T *minxv,
                  real_T *maxxv)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  *minxv = xv[first[0] - 1];
  *maxxv = *minxv;
  for (int32_T k{0}; k < nloops; k++) {
    int32_T a;
    int32_T b;
    a = first[k];
    b = last[k];
    st.site = &l_emlrtRSI;
    if ((a <= b) && (b > 2147483646)) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T j{a}; j <= b; j++) {
      real_T d;
      d = xv[j - 1];
      if (d < *minxv) {
        *minxv = d;
      } else if (d > *maxxv) {
        *maxxv = d;
      }
    }
  }
}

void contrib(real_T x1, real_T b_y1, real_T x2, real_T y2, int8_T quad1,
             int8_T quad2, real_T scale, int8_T *diffQuad, boolean_T *onj)
{
  real_T cp;
  *onj = false;
  *diffQuad = static_cast<int8_T>(quad2 - quad1);
  cp = x1 * y2 - x2 * b_y1;
  if (muDoubleScalarAbs(cp) < scale) {
    *onj = (x1 * x2 + b_y1 * y2 <= 0.0);
    if ((*diffQuad == 2) || (*diffQuad == -2)) {
      *diffQuad = 0;
    } else if (*diffQuad == -3) {
      *diffQuad = 1;
    } else if (*diffQuad == 3) {
      *diffQuad = -1;
    }
  } else if (cp < 0.0) {
    if (*diffQuad == 2) {
      *diffQuad = -2;
    } else if (*diffQuad == -3) {
      *diffQuad = 1;
    } else if (*diffQuad == 3) {
      *diffQuad = -1;
    }
  } else if (*diffQuad == -2) {
    *diffQuad = 2;
  } else if (*diffQuad == -3) {
    *diffQuad = 1;
  } else if (*diffQuad == 3) {
    *diffQuad = -1;
  }
}

} // namespace coder

// End of code generation (inpolygon.cpp)
