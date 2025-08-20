//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  objectDetection.h
//
//  Code generation for function 'objectDetection'
//


#pragma once

// Include files
#include "pointCloud.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder
{
  class objectDetection
  {
   public:
    void init(const emlrtStack *sp, real_T varargin_1, const real_T varargin_2[3],
              const real_T varargin_4[9]);
    void get_MeasurementNoise(real_T value[9]) const;
    void set_Measurement(const emlrtStack *sp, const real_T value[3]);
    void set_Time(const emlrtStack *sp, real_T value);
    void set_MeasurementNoise(const emlrtStack *sp, const real_T value[9]);
    void set_SensorIndex();
    void set_ObjectClassID();
    real_T Time;
    real_T Measurement[3];
    real_T SensorIndex;
    real_T ObjectClassID;
    pointCloud MeasurementParameters;
    real_T pMeasurementNoise[9];
  };
}

// End of code generation (objectDetection.h)
