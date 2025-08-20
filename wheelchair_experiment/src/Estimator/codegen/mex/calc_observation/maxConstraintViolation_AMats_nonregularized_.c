/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation_AMats_nonregularized_.c
 *
 * Code generation for function 'maxConstraintViolation_AMats_nonregularized_'
 *
 */

/* Include files */
#include "maxConstraintViolation_AMats_nonregularized_.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T d_maxConstraintViolation_AMats_(const emlrtStack *sp, g_struct_T *obj,
                                       const real_T x[8])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  obj->maxConstrWorkspace[0] = obj->bineq[0];
  obj->maxConstrWorkspace[1] = obj->bineq[1];
  st.site = &uh_emlrtRSI;
  e_xgemv(&st, obj->nVar, obj->Aineq, x, obj->maxConstrWorkspace);
  return muDoubleScalarMax(muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]),
                           obj->maxConstrWorkspace[1]);
}

/* End of code generation (maxConstraintViolation_AMats_nonregularized_.c) */
