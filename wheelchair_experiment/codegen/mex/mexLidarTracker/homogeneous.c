/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * homogeneous.c
 *
 * Code generation for function 'homogeneous'
 *
 */

/* Include files */
#include "homogeneous.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
real32_T homogeneous(real_T state_X, real_T state_Y, real_T state_yaw,
                     real32_T cxe, real32_T cye, real_T SP,
                     real32_T *cye_global)
{
  real_T c_H_tmp[9];
  real_T dv[9];
  real_T H_tmp;
  real_T b_H_tmp;
  int32_T i;
  int32_T i3;
  real32_T G[3];
  real32_T b_cxe[3];
  real32_T cxe_global;
  emlrtMEXProfilingFunctionEntry((char_T *)homogeneous_complete_name,
                                 isMexOutdated);
  /* HOMOGENEOUS Transfer to GROBAL */
  /*    詳細説明をここに記述 */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  emlrtMEXProfilingStatement(2, isMexOutdated);
  emlrtMEXProfilingStatement(3, isMexOutdated);
  emlrtMEXProfilingStatement(0, isMexOutdated);
  emlrtMEXProfilingStatement(4, isMexOutdated);
  emlrtMEXProfilingStatement(5, isMexOutdated);
  emlrtMEXProfilingStatement(0, isMexOutdated);
  H_tmp = muDoubleScalarSin(state_yaw);
  b_H_tmp = muDoubleScalarCos(state_yaw);
  emlrtMEXProfilingStatement(6, isMexOutdated);
  dv[0] = 1.0;
  dv[3] = 0.0;
  dv[6] = state_X;
  dv[1] = 0.0;
  dv[4] = 1.0;
  dv[7] = state_Y;
  c_H_tmp[0] = b_H_tmp;
  c_H_tmp[3] = -H_tmp;
  c_H_tmp[6] = 0.0;
  c_H_tmp[1] = H_tmp;
  c_H_tmp[4] = b_H_tmp;
  c_H_tmp[7] = 0.0;
  dv[2] = 0.0;
  c_H_tmp[2] = 0.0;
  dv[5] = 0.0;
  c_H_tmp[5] = 0.0;
  dv[8] = 1.0;
  c_H_tmp[8] = 1.0;
  b_cxe[0] = cxe;
  b_cxe[1] = cye;
  b_cxe[2] = 1.0F;
  for (i = 0; i < 3; i++) {
    real_T d;
    int32_T i1;
    int32_T i2;
    real32_T f;
    f = 0.0F;
    i1 = (int32_T)dv[i];
    i2 = (int32_T)dv[i + 3];
    d = dv[i + 6];
    for (i3 = 0; i3 < 3; i3++) {
      f += (real32_T)(((real_T)i1 * c_H_tmp[3 * i3] +
                       (real_T)i2 * c_H_tmp[3 * i3 + 1]) +
                      d * c_H_tmp[3 * i3 + 2]) *
           b_cxe[i3];
    }
    G[i] = f;
  }
  /* %% sensor to the plant %%% */
  emlrtMEXProfilingStatement(7, isMexOutdated);
  cxe_global = G[0] - (real32_T)(SP * b_H_tmp);
  emlrtMEXProfilingStatement(8, isMexOutdated);
  *cye_global = G[1] - (real32_T)(SP * H_tmp);
  emlrtMEXProfilingStatement(9, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  return cxe_global;
}

/* End of code generation (homogeneous.c) */
