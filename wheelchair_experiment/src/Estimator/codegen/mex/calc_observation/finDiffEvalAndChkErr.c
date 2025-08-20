/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * finDiffEvalAndChkErr.c
 *
 * Code generation for function 'finDiffEvalAndChkErr'
 *
 */

/* Include files */
#include "finDiffEvalAndChkErr.h"
#include "calc_observation_data.h"
#include "calc_observation_types.h"
#include "pcfitellipse.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ve_emlrtRSI = {
    1,                      /* lineNo */
    "finDiffEvalAndChkErr", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/+internal/finDiffEvalAndChkErr.p" /* pathName */
};

/* Function Definitions */
boolean_T finDiffEvalAndChkErr(
    const emlrtStack *sp, const emxArray_real_T *obj_objfun_workspace_points,
    const real_T obj_nonlin_workspace_COG_init[2],
    real_T obj_nonlin_workspace_Plant_X, real_T obj_nonlin_workspace_Plant_Y,
    real_T obj_nonlin_workspace_Plant_yaw, real_T *cIneqPlus, int32_T dim,
    real_T delta, real_T xk[5], real_T *fplus)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T temp_tmp;
  int32_T i;
  int32_T i1;
  int32_T idx;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  st.site = &ve_emlrtRSI;
  b_st.site = &de_emlrtRSI;
  *fplus =
      pcfitellipse_anonFcn2_anonFcn1(&b_st, obj_objfun_workspace_points, xk);
  evalOK = ((!muDoubleScalarIsInf(*fplus)) && (!muDoubleScalarIsNaN(*fplus)));
  if (evalOK) {
    real_T b_cxe_adjusted_tmp[9];
    real_T c_cxe_adjusted_tmp[9];
    real_T dv[9];
    real_T L_local[6];
    real_T b_obj_nonlin_workspace_COG_init[6];
    real_T cxe_adjusted_tmp;
    real_T cye_adjusted_tmp;
    real_T d;
    /* %%% 関数 %%%% */
    /*  RANSACで制約条件の追加points(x,y,alpha,beta,theta):観測値,COG:点群重心
     */
    /*  c(points) <= 0 */
    /* GLOBAL_TO_LOCAL Transfer from GLOBAL to LOCAL */
    /*  state: Ego-vehicle's position in global system coordinates X Y Theta
     * which are */
    /*  measured by Autoware/Gazebo. */
    /*  cxe_global, cye_global: Obstacle's position in global system coordinates
     */
    /*  SP: distance between LiDAR and vehicle, generally, zero. */
    /* %% Adjust for the sensor's offset from the plant (vehicle center) %%% */
    cxe_adjusted_tmp = muDoubleScalarCos(obj_nonlin_workspace_Plant_yaw);
    cye_adjusted_tmp = muDoubleScalarSin(obj_nonlin_workspace_Plant_yaw);
    /*  Translation vector for the ego-vehicle's position */
    /*  Rotation matrix for the ego-vehicle's orientation (inverse rotation) */
    /*  Combine translation and rotation to form the inverse transformation
     * matrix */
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
    dv[6] = -obj_nonlin_workspace_Plant_X;
    dv[1] = 0.0;
    dv[4] = 1.0;
    dv[7] = -obj_nonlin_workspace_Plant_Y;
    b_cxe_adjusted_tmp[2] = 0.0;
    dv[2] = 0.0;
    b_cxe_adjusted_tmp[5] = 0.0;
    dv[5] = 0.0;
    b_cxe_adjusted_tmp[8] = 1.0;
    dv[8] = 1.0;
    d = 0.0 * cxe_adjusted_tmp;
    cxe_adjusted_tmp = 0.0 * cye_adjusted_tmp;
    for (idx = 0; idx < 3; idx++) {
      real_T d1;
      cye_adjusted_tmp = b_cxe_adjusted_tmp[idx];
      d1 = b_cxe_adjusted_tmp[idx + 3];
      i = (int32_T)b_cxe_adjusted_tmp[idx + 6];
      for (i1 = 0; i1 < 3; i1++) {
        c_cxe_adjusted_tmp[idx + 3 * i1] =
            (cye_adjusted_tmp * dv[3 * i1] + d1 * dv[3 * i1 + 1]) +
            (real_T)i * dv[3 * i1 + 2];
      }
    }
    b_obj_nonlin_workspace_COG_init[0] = obj_nonlin_workspace_COG_init[0] + d;
    b_obj_nonlin_workspace_COG_init[1] =
        obj_nonlin_workspace_COG_init[1] + cxe_adjusted_tmp;
    b_obj_nonlin_workspace_COG_init[2] = 1.0;
    b_obj_nonlin_workspace_COG_init[3] = xk[0] + d;
    b_obj_nonlin_workspace_COG_init[4] = xk[1] + cxe_adjusted_tmp;
    b_obj_nonlin_workspace_COG_init[5] = 1.0;
    for (idx = 0; idx < 3; idx++) {
      d = c_cxe_adjusted_tmp[idx];
      cxe_adjusted_tmp = c_cxe_adjusted_tmp[idx + 3];
      cye_adjusted_tmp = c_cxe_adjusted_tmp[idx + 6];
      for (i = 0; i < 2; i++) {
        L_local[idx + 3 * i] =
            (d * b_obj_nonlin_workspace_COG_init[3 * i] +
             cxe_adjusted_tmp * b_obj_nonlin_workspace_COG_init[3 * i + 1]) +
            cye_adjusted_tmp * b_obj_nonlin_workspace_COG_init[3 * i + 2];
      }
    }
    /*  Extract local coordinates */
    *cIneqPlus = muDoubleScalarHypot(L_local[0], L_local[4]) -
                 muDoubleScalarHypot(L_local[3], L_local[4]);
    idx = 1;
    while (evalOK && (idx <= 1)) {
      evalOK = ((!muDoubleScalarIsInf(*cIneqPlus)) &&
                (!muDoubleScalarIsNaN(*cIneqPlus)));
      idx = 2;
    }
    if (evalOK) {
      xk[dim - 1] = temp_tmp;
    }
  }
  return evalOK;
}

/* End of code generation (finDiffEvalAndChkErr.c) */
