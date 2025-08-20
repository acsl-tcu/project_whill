/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeConstrViolationIneq_.c
 *
 * Code generation for function 'computeConstrViolationIneq_'
 *
 */

/* Include files */
#include "computeConstrViolationIneq_.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
real_T computeConstrViolationIneq_(const real_T ineq_workspace[2])
{
  real_T normResid;
  normResid = 0.0;
  if (ineq_workspace[0] > 0.0) {
    normResid = ineq_workspace[0];
  }
  if (ineq_workspace[1] > 0.0) {
    normResid += ineq_workspace[1];
  }
  return normResid;
}

/* End of code generation (computeConstrViolationIneq_.c) */
