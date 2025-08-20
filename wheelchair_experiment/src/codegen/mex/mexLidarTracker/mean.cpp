//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mean.cpp
//
//  Code generation for function 'mean'
//


// Include files
#include "mean.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder
{
  void mean(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &x,
            real32_T y[3])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    real32_T bsum;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &un_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    b_st.site = &gk_emlrtRSI;
    if (x.size(0) == 0) {
      y[0] = 0.0F;
      y[1] = 0.0F;
      y[2] = 0.0F;
    } else {
      int32_T firstBlockLength;
      int32_T lastBlockLength;
      int32_T nblocks;
      c_st.site = &hk_emlrtRSI;
      if (x.size(0) <= 1024) {
        firstBlockLength = x.size(0);
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = x.size(0) / 1024;
        lastBlockLength = x.size(0) - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }

      for (int32_T xi = 0; xi < 3; xi++) {
        int32_T k;
        int32_T xpageoffset;
        xpageoffset = xi * x.size(0);
        y[xi] = x[xpageoffset];
        d_st.site = &ik_emlrtRSI;
        for (k = 2; k <= firstBlockLength; k++) {
          y[xi] += x[(xpageoffset + k) - 1];
        }

        d_st.site = &jk_emlrtRSI;
        for (int32_T ib = 2; ib <= nblocks; ib++) {
          int32_T hi;
          int32_T xblockoffset;
          xblockoffset = xpageoffset + ((ib - 1) << 10);
          bsum = x[xblockoffset];
          if (ib == nblocks) {
            hi = lastBlockLength;
          } else {
            hi = 1024;
          }

          d_st.site = &kk_emlrtRSI;
          if ((2 <= hi) && (hi > 2147483646)) {
            e_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          for (k = 2; k <= hi; k++) {
            bsum += x[(xblockoffset + k) - 1];
          }

          y[xi] += bsum;
        }
      }
    }

    y[0] /= static_cast<real32_T>(x.size(0));
    y[1] /= static_cast<real32_T>(x.size(0));
    y[2] /= static_cast<real32_T>(x.size(0));
  }
}

// End of code generation (mean.cpp)
