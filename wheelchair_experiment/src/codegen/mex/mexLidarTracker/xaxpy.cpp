//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xaxpy.cpp
//
//  Code generation for function 'xaxpy'
//


// Include files
#include "xaxpy.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace blas
    {
      void b_xaxpy(int32_T n, real_T a, const real_T x[3], int32_T ix0, real_T
                   y[9], int32_T iy0)
      {
        if (!(a == 0.0)) {
          int32_T i;
          int32_T ix;
          int32_T iy;
          ix = ix0 - 1;
          iy = iy0 - 1;
          i = n - 1;
          for (int32_T k = 0; k <= i; k++) {
            y[iy] += a * x[ix];
            ix++;
            iy++;
          }
        }
      }

      void b_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[36], int32_T iy0)
      {
        if (!(a == 0.0)) {
          int32_T i;
          int32_T ix;
          int32_T iy;
          ix = ix0 - 1;
          iy = iy0 - 1;
          i = n - 1;
          for (int32_T k = 0; k <= i; k++) {
            y[iy] += a * y[ix];
            ix++;
            iy++;
          }
        }
      }

      void c_xaxpy(int32_T n, real_T a, const real_T x[36], int32_T ix0, real_T
                   y[6], int32_T iy0)
      {
        if (!(a == 0.0)) {
          int32_T i;
          int32_T ix;
          int32_T iy;
          ix = ix0 - 1;
          iy = iy0 - 1;
          i = n - 1;
          for (int32_T k = 0; k <= i; k++) {
            y[iy] += a * x[ix];
            ix++;
            iy++;
          }
        }
      }

      void d_xaxpy(int32_T n, real_T a, const real_T x[6], int32_T ix0, real_T
                   y[36], int32_T iy0)
      {
        if (!(a == 0.0)) {
          int32_T i;
          int32_T ix;
          int32_T iy;
          ix = ix0 - 1;
          iy = iy0 - 1;
          i = n - 1;
          for (int32_T k = 0; k <= i; k++) {
            y[iy] += a * x[ix];
            ix++;
            iy++;
          }
        }
      }

      void xaxpy(int32_T n, real_T a, const real_T x[9], int32_T ix0, real_T y[3],
                 int32_T iy0)
      {
        if (!(a == 0.0)) {
          int32_T i;
          int32_T ix;
          int32_T iy;
          ix = ix0 - 1;
          iy = iy0 - 1;
          i = n - 1;
          for (int32_T k = 0; k <= i; k++) {
            y[iy] += a * x[ix];
            ix++;
            iy++;
          }
        }
      }

      void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0)
      {
        if (!(a == 0.0)) {
          int32_T i;
          int32_T ix;
          int32_T iy;
          ix = ix0 - 1;
          iy = iy0 - 1;
          i = n - 1;
          for (int32_T k = 0; k <= i; k++) {
            y[iy] += a * y[ix];
            ix++;
            iy++;
          }
        }
      }
    }
  }
}

// End of code generation (xaxpy.cpp)
