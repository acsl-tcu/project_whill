//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  any1.cpp
//
//  Code generation for function 'any1'
//


// Include files
#include "any1.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  boolean_T any(const boolean_T x[4])
  {
    int32_T k;
    boolean_T exitg1;
    boolean_T y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!x[k]) {
        k++;
      } else {
        y = true;
        exitg1 = true;
      }
    }

    return y;
  }
}

// End of code generation (any1.cpp)
