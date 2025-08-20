//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EKFCorrectorAdditive.h
//
//  Code generation for function 'EKFCorrectorAdditive'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace coder
{
  class trackingEKF;
}

// Type Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        class EKFCorrectorAdditive
        {
         public:
          static void getNumberOfMandatoryInputs();
          static void validateMeasurementFcn(const emlrtStack *sp, const
            trackingEKF *ekf);
          static void c_getPredictedMeasurementAndCov(const emlrtStack *sp,
            const real_T zcov[9], const real_T x[6], const real_T P[36], real_T
            zEstimated[3], real_T Pxy[18], real_T Pyy[9], real_T dHdx[18]);
          static void c_getMeasurementJacobianAndCova(const emlrtStack *sp,
            const real_T Rs[9], const real_T x[6], const real_T S[36], real_T
            zEstimated[3], real_T Pxy[18], real_T Sy[9], real_T dHdx[18]);
          static void correctStateAndCovariance(const emlrtStack *sp, real_T x[6],
            real_T P[36], const real_T y[3], const real_T Pxy[18], const real_T
            Pyy[9], const real_T dHdx[18], real_T gain[18]);
        };
      }
    }
  }
}

// End of code generation (EKFCorrectorAdditive.h)
