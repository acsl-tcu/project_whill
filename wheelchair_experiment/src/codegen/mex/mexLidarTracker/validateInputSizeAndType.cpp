//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  validateInputSizeAndType.cpp
//
//  Code generation for function 'validateInputSizeAndType'
//


// Include files
#include "validateInputSizeAndType.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        void validateInputSizeAndType(const emlrtStack *sp, const real_T value[3])
        {
          emlrtStack b_st;
          emlrtStack st;
          int32_T k;
          boolean_T exitg1;
          boolean_T p;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &xfb_emlrtRSI;
          b_st.prev = &st;
          b_st.tls = st.tls;
          b_st.site = &yb_emlrtRSI;
          p = true;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 3)) {
            if ((!muDoubleScalarIsInf(value[k])) && (!muDoubleScalarIsNaN
                 (value[k]))) {
              k++;
            } else {
              p = false;
              exitg1 = true;
            }
          }

          if (!p) {
            emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedFinite",
              "MATLAB:trackingEKF:expectedFinite", 3, 4, 6, "z(:,1)");
          }
        }
      }
    }
  }
}

// End of code generation (validateInputSizeAndType.cpp)
