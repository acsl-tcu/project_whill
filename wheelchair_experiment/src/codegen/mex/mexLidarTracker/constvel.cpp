//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  constvel.cpp
//
//  Code generation for function 'constvel'
//


// Include files
#include "constvel.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder
{
  void constvel(const emlrtStack *sp, real_T state[6], real_T varargin_2)
  {
    emlrtStack b_st;
    emlrtStack st;
    real_T d;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ry_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    b_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if ((!muDoubleScalarIsInf(state[k])) && (!muDoubleScalarIsNaN(state[k])))
      {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:constvel:expectedFinite", 3, 4, 22, "input number 1, state,");
    }

    st.site = &sy_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    p = ((!muDoubleScalarIsInf(varargin_2)) && (!muDoubleScalarIsNaN(varargin_2)));
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:constvel:expectedFinite", 3, 4, 19, "input number 3, dt,");
    }

    st.site = &ty_emlrtRSI;
    d = 0.5 * (varargin_2 * varargin_2) * 0.0;
    state[0] = (state[0] + state[1] * varargin_2) + d;
    state[1] += 0.0 * varargin_2;
    st.site = &ty_emlrtRSI;
    state[2] = (state[2] + state[3] * varargin_2) + d;
    state[3] += 0.0 * varargin_2;
    st.site = &ty_emlrtRSI;
    state[4] = (state[4] + state[5] * varargin_2) + d;
    state[5] += 0.0 * varargin_2;
  }
}

// End of code generation (constvel.cpp)
