//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  vAllOrAny.cpp
//
//  Code generation for function 'vAllOrAny'
//


// Include files
#include "vAllOrAny.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    boolean_T flatVectorAllOrAny(const real_T x_data[], const int32_T x_size[2])
    {
      int32_T nx;
      boolean_T p;
      nx = x_size[0] * x_size[1];
      p = true;
      for (int32_T k = 0; k < nx; k++) {
        if ((!p) || (muDoubleScalarIsInf(x_data[k]) || muDoubleScalarIsNaN
                     (x_data[k]))) {
          p = false;
        }
      }

      return p;
    }
  }
}

// End of code generation (vAllOrAny.cpp)
