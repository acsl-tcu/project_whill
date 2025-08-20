//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  dot.cpp
//
//  Code generation for function 'dot'
//


// Include files
#include "dot.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  void dot(const real_T a_data[], const real32_T b[3], real32_T c_data[],
           int32_T c_size[2])
  {
    c_size[0] = 1;
    c_size[1] = 1;
    c_data[0] = (static_cast<real32_T>(a_data[0]) * b[0] + static_cast<real32_T>
                 (a_data[1]) * b[1]) + static_cast<real32_T>(a_data[2]) * b[2];
  }
}

// End of code generation (dot.cpp)
