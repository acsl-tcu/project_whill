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
#include "coder_array.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    boolean_T dimagree(const ::coder::array<real_T, 1U> &z, const ::coder::array<
                       real_T, 1U> &varargin_1, const ::coder::array<real_T, 1U>
                       &varargin_2)
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
          i = z.size(0);
          i1 = varargin_1.size(0);
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
            i = z.size(0);
            i1 = varargin_2.size(0);
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
