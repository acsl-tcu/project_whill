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
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
real_T homogeneous(real_T state_X, real_T state_Y, real_T state_yaw, real_T cxe,
                   real_T cye, real_T *cye_global)
{
  real_T b_H_tmp[9];
  real_T dv[9];
  real_T G[3];
  real_T b_cxe[3];
  real_T H_tmp;
  real_T cxe_global;
  int32_T i;
  int32_T i3;
  /* HOMOGENEOUS Transfer to GLOBAL */
  /*  state: Ego-vehicle's position in global system coordinates X Y Theta which
   * are */
  /*  measured by Autoware/Gazebo. */
  /*  cxe, cye: Obstacle's position in local system coordinates */
  /*  SP: distance between LiDAR and vhicle, generally, zero. */
  /*  if length(cxe) == 1 */
  H_tmp = muDoubleScalarSin(state_yaw);
  cxe_global = muDoubleScalarCos(state_yaw);
  dv[0] = 1.0;
  dv[3] = 0.0;
  dv[6] = state_X;
  dv[1] = 0.0;
  dv[4] = 1.0;
  dv[7] = state_Y;
  b_H_tmp[0] = cxe_global;
  b_H_tmp[3] = -H_tmp;
  b_H_tmp[6] = 0.0;
  b_H_tmp[1] = H_tmp;
  b_H_tmp[4] = cxe_global;
  b_H_tmp[7] = 0.0;
  dv[2] = 0.0;
  b_H_tmp[2] = 0.0;
  dv[5] = 0.0;
  b_H_tmp[5] = 0.0;
  dv[8] = 1.0;
  b_H_tmp[8] = 1.0;
  b_cxe[0] = cxe;
  b_cxe[1] = cye;
  b_cxe[2] = 1.0;
  for (i = 0; i < 3; i++) {
    real_T d;
    real_T d1;
    int32_T i1;
    int32_T i2;
    d = 0.0;
    i1 = (int32_T)dv[i];
    i2 = (int32_T)dv[i + 3];
    d1 = dv[i + 6];
    for (i3 = 0; i3 < 3; i3++) {
      d += (((real_T)i1 * b_H_tmp[3 * i3] + (real_T)i2 * b_H_tmp[3 * i3 + 1]) +
            d1 * b_H_tmp[3 * i3 + 2]) *
           b_cxe[i3];
    }
    G[i] = d;
  }
  /* %% sensor to the plant %%% */
  cxe_global = G[0] - 0.0 * cxe_global;
  *cye_global = G[1] - 0.0 * H_tmp;
  return cxe_global;
}

/* End of code generation (homogeneous.c) */
