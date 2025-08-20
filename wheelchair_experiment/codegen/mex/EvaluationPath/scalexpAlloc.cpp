//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  scalexpAlloc.cpp
//
//  Code generation for function 'scalexpAlloc'
//


// Include files
#include "scalexpAlloc.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    boolean_T dimagree(const int32_T z_size[1], const int32_T varargin_1_size[1],
                       const int32_T varargin_2_size[1])
    {
      int32_T i;
      int32_T i1;
      int32_T k;
      boolean_T b_p;
      boolean_T exitg1;
      boolean_T p;
      p = true;
      b_p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (k + 1 <= 1) {
          i = z_size[0];
          i1 = varargin_1_size[0];
        } else {
          i = 1;
          i1 = 1;
        }

        if (i != i1) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (b_p) {
        b_p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 2)) {
          if (k + 1 <= 1) {
            i = z_size[0];
            i1 = varargin_2_size[0];
          } else {
            i = 1;
            i1 = 1;
          }

          if (i != i1) {
            b_p = false;
            exitg1 = true;
          } else {
            k++;
          }
        }

        if (!b_p) {
          p = false;
        }
      } else {
        p = false;
      }

      return p;
    }
  }
}

// End of code generation (scalexpAlloc.cpp)
