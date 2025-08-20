/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeConstraints_.c
 *
 * Code generation for function 'computeConstraints_'
 *
 */

/* Include files */
#include "computeConstraints_.h"
#include "calc_observation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
int32_T computeConstraints_(const real_T c_obj_next_next_next_next_next_[2],
                            const struct1_T d_obj_next_next_next_next_next_,
                            const real_T x[5], real_T Cineq_workspace[2])
{
  real_T b_cxe_adjusted_tmp[9];
  real_T c_cxe_adjusted_tmp[9];
  real_T dv[9];
  real_T L_local[6];
  real_T e_obj_next_next_next_next_next_[6];
  real_T cxe_adjusted_tmp;
  real_T cye_adjusted_tmp;
  real_T d;
  int32_T i;
  int32_T i1;
  int32_T idx_current;
  int32_T status;
  boolean_T allFinite;
  /* %%% 関数 %%%% */
  /*  RANSACで制約条件の追加points(x,y,alpha,beta,theta):観測値,COG:点群重心 */
  /*  c(points) <= 0 */
  /* GLOBAL_TO_LOCAL Transfer from GLOBAL to LOCAL */
  /*  state: Ego-vehicle's position in global system coordinates X Y Theta which
   * are */
  /*  measured by Autoware/Gazebo. */
  /*  cxe_global, cye_global: Obstacle's position in global system coordinates
   */
  /*  SP: distance between LiDAR and vehicle, generally, zero. */
  /* %% Adjust for the sensor's offset from the plant (vehicle center) %%% */
  cxe_adjusted_tmp = muDoubleScalarCos(d_obj_next_next_next_next_next_.yaw);
  cye_adjusted_tmp = muDoubleScalarSin(d_obj_next_next_next_next_next_.yaw);
  /*  Translation vector for the ego-vehicle's position */
  /*  Rotation matrix for the ego-vehicle's orientation (inverse rotation) */
  /*  Combine translation and rotation to form the inverse transformation matrix
   */
  /*  Represent global coordinates as homogeneous coordinates */
  /*  Apply the inverse transformation */
  b_cxe_adjusted_tmp[0] = cxe_adjusted_tmp;
  b_cxe_adjusted_tmp[3] = cye_adjusted_tmp;
  b_cxe_adjusted_tmp[6] = 0.0;
  b_cxe_adjusted_tmp[1] = -cye_adjusted_tmp;
  b_cxe_adjusted_tmp[4] = cxe_adjusted_tmp;
  b_cxe_adjusted_tmp[7] = 0.0;
  dv[0] = 1.0;
  dv[3] = 0.0;
  dv[6] = -d_obj_next_next_next_next_next_.X;
  dv[1] = 0.0;
  dv[4] = 1.0;
  dv[7] = -d_obj_next_next_next_next_next_.Y;
  b_cxe_adjusted_tmp[2] = 0.0;
  dv[2] = 0.0;
  b_cxe_adjusted_tmp[5] = 0.0;
  dv[5] = 0.0;
  b_cxe_adjusted_tmp[8] = 1.0;
  dv[8] = 1.0;
  d = 0.0 * cxe_adjusted_tmp;
  cxe_adjusted_tmp = 0.0 * cye_adjusted_tmp;
  for (idx_current = 0; idx_current < 3; idx_current++) {
    real_T d1;
    cye_adjusted_tmp = b_cxe_adjusted_tmp[idx_current];
    d1 = b_cxe_adjusted_tmp[idx_current + 3];
    i = (int32_T)b_cxe_adjusted_tmp[idx_current + 6];
    for (i1 = 0; i1 < 3; i1++) {
      c_cxe_adjusted_tmp[idx_current + 3 * i1] =
          (cye_adjusted_tmp * dv[3 * i1] + d1 * dv[3 * i1 + 1]) +
          (real_T)i * dv[3 * i1 + 2];
    }
  }
  e_obj_next_next_next_next_next_[0] = c_obj_next_next_next_next_next_[0] + d;
  e_obj_next_next_next_next_next_[1] =
      c_obj_next_next_next_next_next_[1] + cxe_adjusted_tmp;
  e_obj_next_next_next_next_next_[2] = 1.0;
  e_obj_next_next_next_next_next_[3] = x[0] + d;
  e_obj_next_next_next_next_next_[4] = x[1] + cxe_adjusted_tmp;
  e_obj_next_next_next_next_next_[5] = 1.0;
  for (idx_current = 0; idx_current < 3; idx_current++) {
    d = c_cxe_adjusted_tmp[idx_current];
    cxe_adjusted_tmp = c_cxe_adjusted_tmp[idx_current + 3];
    cye_adjusted_tmp = c_cxe_adjusted_tmp[idx_current + 6];
    for (i = 0; i < 2; i++) {
      L_local[idx_current + 3 * i] =
          (d * e_obj_next_next_next_next_next_[3 * i] +
           cxe_adjusted_tmp * e_obj_next_next_next_next_next_[3 * i + 1]) +
          cye_adjusted_tmp * e_obj_next_next_next_next_next_[3 * i + 2];
    }
  }
  /*  Extract local coordinates */
  cxe_adjusted_tmp = muDoubleScalarHypot(L_local[0], L_local[4]) -
                     muDoubleScalarHypot(L_local[3], L_local[4]);
  Cineq_workspace[1] = cxe_adjusted_tmp;
  status = 1;
  allFinite = true;
  idx_current = 0;
  while (allFinite && (idx_current + 2 <= 2)) {
    allFinite = ((!muDoubleScalarIsInf(cxe_adjusted_tmp)) &&
                 (!muDoubleScalarIsNaN(cxe_adjusted_tmp)));
    idx_current = 1;
  }
  if (!allFinite) {
    if (muDoubleScalarIsNaN(Cineq_workspace[idx_current])) {
      status = -3;
    } else if (Cineq_workspace[idx_current] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }
  return status;
}

/* End of code generation (computeConstraints_.c) */
