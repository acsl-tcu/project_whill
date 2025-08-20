/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation_AMats_regularized_.c
 *
 * Code generation for function 'maxConstraintViolation_AMats_regularized_'
 *
 */

/* Include files */
#include "maxConstraintViolation_AMats_regularized_.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T c_maxConstraintViolation_AMats_(const emlrtStack *sp, g_struct_T *obj,
                                       const real_T x[8])
{
  emlrtStack st;
  real_T d;
  real_T v;
  st.prev = sp;
  st.tls = sp->tls;
  obj->maxConstrWorkspace[0] = obj->bineq[0];
  obj->maxConstrWorkspace[1] = obj->bineq[1];
  st.site = &sh_emlrtRSI;
  e_xgemv(&st, 5, obj->Aineq, x, obj->maxConstrWorkspace);
  d = obj->maxConstrWorkspace[0] - x[5];
  obj->maxConstrWorkspace[0] = d;
  v = muDoubleScalarMax(0.0, d);
  d = obj->maxConstrWorkspace[1] - x[6];
  obj->maxConstrWorkspace[1] = d;
  return muDoubleScalarMax(v, d);
}

/* End of code generation (maxConstraintViolation_AMats_regularized_.c) */
