//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  FPM_4.h
//
//  Code generation for function 'FPM_4'
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

// Function Declarations
void FPM_4(const emlrtStack *sp, real_T obj_ObsNum, real_T obj_r_wheel, real_T
           obj_r_obs, real_T x, real_T y, real_T th, const real_T obs_data[],
           const int32_T obs_size[2], const real_T obs_now_data[], const int32_T
           obs_now_size[2], const real_T target[2], real_T *Grade, real_T
           *Grade_old);

// End of code generation (FPM_4.h)
