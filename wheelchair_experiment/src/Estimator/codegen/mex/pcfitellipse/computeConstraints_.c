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
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
int32_T computeConstraints_(const real_T c_obj_next_next_next_next_next_[2],
                            const real_T x[5], real_T Cineq_workspace[2])
{
  int32_T idx_current;
  int32_T status;
  boolean_T allFinite;
  /* %%% 関数 %%%% */
  /*  2ndRANSACで制約条件の追加points(x,y,alpha,beta,theta):観測値,COG:点群重心
   */
  /*  c(points) <= 0 */
  Cineq_workspace[1] = muDoubleScalarHypot(c_obj_next_next_next_next_next_[0],
                                           c_obj_next_next_next_next_next_[1]) -
                       muDoubleScalarHypot(x[0], x[1]);
  status = 1;
  allFinite = true;
  idx_current = 0;
  while (allFinite && (idx_current + 2 <= 2)) {
    allFinite = ((!muDoubleScalarIsInf(Cineq_workspace[1])) &&
                 (!muDoubleScalarIsNaN(Cineq_workspace[1])));
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
