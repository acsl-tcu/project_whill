//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mrdivide_helper.cpp
//
//  Code generation for function 'mrdivide_helper'
//


// Include files
#include "mrdivide_helper.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

// Function Definitions
namespace coder
{
  namespace internal
  {
    void mrdiv(const emlrtStack *sp, const real_T A[3], const real_T B[9],
               real_T Y[3])
    {
      emlrtStack b_st;
      emlrtStack c_st;
      emlrtStack d_st;
      emlrtStack st;
      real_T b_A[9];
      real_T a21;
      real_T maxval;
      int32_T r1;
      int32_T r2;
      int32_T r3;
      st.prev = sp;
      st.tls = sp->tls;
      st.site = &icb_emlrtRSI;
      b_st.prev = &st;
      b_st.tls = st.tls;
      c_st.prev = &b_st;
      c_st.tls = b_st.tls;
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      b_st.site = &jcb_emlrtRSI;
      memcpy(&b_A[0], &B[0], 9U * sizeof(real_T));
      r1 = 0;
      r2 = 1;
      r3 = 2;
      maxval = muDoubleScalarAbs(B[0]);
      a21 = muDoubleScalarAbs(B[1]);
      if (a21 > maxval) {
        maxval = a21;
        r1 = 1;
        r2 = 0;
      }

      if (muDoubleScalarAbs(B[2]) > maxval) {
        r1 = 2;
        r2 = 1;
        r3 = 0;
      }

      b_A[r2] = B[r2] / B[r1];
      b_A[r3] /= b_A[r1];
      b_A[r2 + 3] -= b_A[r2] * b_A[r1 + 3];
      b_A[r3 + 3] -= b_A[r3] * b_A[r1 + 3];
      b_A[r2 + 6] -= b_A[r2] * b_A[r1 + 6];
      b_A[r3 + 6] -= b_A[r3] * b_A[r1 + 6];
      if (muDoubleScalarAbs(b_A[r3 + 3]) > muDoubleScalarAbs(b_A[r2 + 3])) {
        int32_T rtemp;
        rtemp = r2;
        r2 = r3;
        r3 = rtemp;
      }

      b_A[r3 + 3] /= b_A[r2 + 3];
      b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
      if ((b_A[r1] == 0.0) || (b_A[r2 + 3] == 0.0) || (b_A[r3 + 6] == 0.0)) {
        c_st.site = &kcb_emlrtRSI;
        d_st.site = &mcb_emlrtRSI;
        f_warning(&d_st);
      }

      Y[r1] = A[0] / b_A[r1];
      Y[r2] = A[1] - Y[r1] * b_A[r1 + 3];
      Y[r3] = A[2] - Y[r1] * b_A[r1 + 6];
      Y[r2] /= b_A[r2 + 3];
      Y[r3] -= Y[r2] * b_A[r2 + 6];
      Y[r3] /= b_A[r3 + 6];
      Y[r2] -= Y[r3] * b_A[r3 + 3];
      Y[r1] -= Y[r3] * b_A[r3];
      Y[r1] -= Y[r2] * b_A[r2];
    }
  }
}

// End of code generation (mrdivide_helper.cpp)
