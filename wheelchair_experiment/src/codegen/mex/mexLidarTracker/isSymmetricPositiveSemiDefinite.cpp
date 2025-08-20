//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  isSymmetricPositiveSemiDefinite.cpp
//
//  Code generation for function 'isSymmetricPositiveSemiDefinite'
//


// Include files
#include "isSymmetricPositiveSemiDefinite.h"
#include "eig.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <math.h>

// Function Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        void isSymmetricPositiveSemiDefinite(const emlrtStack *sp, const real_T
          value[9])
        {
          emlrtStack st;
          creal_T d[3];
          real_T b_x[9];
          real_T y[9];
          real_T varargin_1[3];
          real_T tol;
          real_T x;
          int32_T exponent;
          int32_T idx;
          int32_T k;
          boolean_T x_data[6];
          boolean_T b_y[3];
          boolean_T c_y;
          boolean_T d_y;
          boolean_T exitg1;
          st.prev = sp;
          st.tls = sp->tls;
          varargin_1[0] = muDoubleScalarAbs(value[0]);
          varargin_1[1] = muDoubleScalarAbs(value[4]);
          varargin_1[2] = muDoubleScalarAbs(value[8]);
          if (!muDoubleScalarIsNaN(varargin_1[0])) {
            idx = 1;
          } else {
            idx = 0;
            k = 2;
            exitg1 = false;
            while ((!exitg1) && (k < 4)) {
              if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
                idx = k;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }

          if (idx == 0) {
            tol = varargin_1[0];
          } else {
            tol = varargin_1[idx - 1];
            idx++;
            for (k = idx; k < 4; k++) {
              x = varargin_1[k - 1];
              if (tol < x) {
                tol = x;
              }
            }
          }

          if ((!muDoubleScalarIsInf(tol)) && (!muDoubleScalarIsNaN(tol))) {
            if (tol <= 2.2250738585072014E-308) {
              tol = 4.94065645841247E-324;
            } else {
              frexp(tol, &exponent);
              tol = ldexp(1.0, exponent - 53);
            }
          } else {
            tol = rtNaN;
          }

          tol *= 100.0;
          for (exponent = 0; exponent < 3; exponent++) {
            b_x[3 * exponent] = value[3 * exponent] - value[exponent];
            idx = 3 * exponent + 1;
            b_x[idx] = value[idx] - value[exponent + 3];
            idx = 3 * exponent + 2;
            b_x[idx] = value[idx] - value[exponent + 6];
          }

          for (k = 0; k < 9; k++) {
            y[k] = muDoubleScalarAbs(b_x[k]);
          }

          x = muDoubleScalarSqrt(tol);
          b_y[0] = true;
          b_y[1] = true;
          b_y[2] = true;
          idx = 1;
          exitg1 = false;
          while ((!exitg1) && (idx <= 3)) {
            if (!(y[idx - 1] < x)) {
              b_y[0] = false;
              exitg1 = true;
            } else {
              idx++;
            }
          }

          idx = 4;
          exitg1 = false;
          while ((!exitg1) && (idx <= 6)) {
            if (!(y[idx - 1] < x)) {
              b_y[1] = false;
              exitg1 = true;
            } else {
              idx++;
            }
          }

          idx = 7;
          exitg1 = false;
          while ((!exitg1) && (idx <= 9)) {
            if (!(y[idx - 1] < x)) {
              b_y[2] = false;
              exitg1 = true;
            } else {
              idx++;
            }
          }

          c_y = true;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k <= 2)) {
            if (!b_y[k]) {
              c_y = false;
              exitg1 = true;
            } else {
              k++;
            }
          }

          for (exponent = 0; exponent < 3; exponent++) {
            b_x[3 * exponent] = (value[3 * exponent] + value[exponent]) / 2.0;
            idx = 3 * exponent + 1;
            b_x[idx] = (value[idx] + value[exponent + 3]) / 2.0;
            idx = 3 * exponent + 2;
            b_x[idx] = (value[idx] + value[exponent + 6]) / 2.0;
          }

          st.site = &jo_emlrtRSI;
          eig(&st, b_x, d);
          x_data[0] = (d[0].re < -tol);
          x_data[1] = (d[1].re < -tol);
          x_data[2] = (d[2].re < -tol);
          d_y = false;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k <= 2)) {
            if (!x_data[k]) {
              k++;
            } else {
              d_y = true;
              exitg1 = true;
            }
          }

          if (d_y || (!c_y)) {
            emlrtErrorWithMessageIdR2018a(sp, &qb_emlrtRTEI,
              "shared_tracking:KalmanFilter:invalidCovarianceValues",
              "shared_tracking:KalmanFilter:invalidCovarianceValues", 3, 4, 16,
              "MeasurementNoise");
          }
        }
      }
    }
  }
}

// End of code generation (isSymmetricPositiveSemiDefinite.cpp)
