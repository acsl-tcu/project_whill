//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xswap.cpp
//
//  Code generation for function 'xswap'
//


// Include files
#include "xswap.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace blas
    {
      void b_xswap(real_T x[9], int32_T ix0, int32_T iy0)
      {
        real_T temp;
        temp = x[ix0 - 1];
        x[ix0 - 1] = x[iy0 - 1];
        x[iy0 - 1] = temp;
        temp = x[ix0];
        x[ix0] = x[iy0];
        x[iy0] = temp;
        temp = x[ix0 + 1];
        x[ix0 + 1] = x[iy0 + 1];
        x[iy0 + 1] = temp;
      }

      void xswap(real_T x[36], int32_T ix0, int32_T iy0)
      {
        int32_T ix;
        int32_T iy;
        ix = ix0 - 1;
        iy = iy0 - 1;
        for (int32_T k = 0; k < 6; k++) {
          real_T temp;
          temp = x[ix];
          x[ix] = x[iy];
          x[iy] = temp;
          ix++;
          iy++;
        }
      }
    }
  }
}

// End of code generation (xswap.cpp)
