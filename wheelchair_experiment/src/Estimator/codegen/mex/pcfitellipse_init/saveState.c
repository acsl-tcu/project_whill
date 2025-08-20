/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * saveState.c
 *
 * Code generation for function 'saveState'
 *
 */

/* Include files */
#include "saveState.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void saveState(h_struct_T *obj)
{
  int32_T k;
  obj->sqpFval_old = obj->sqpFval;
  for (k = 0; k < 5; k++) {
    obj->xstarsqp_old[k] = obj->xstarsqp[k];
    obj->grad_old[k] = obj->grad[k];
  }
  obj->cIneq_old = obj->cIneq;
}

/* End of code generation (saveState.c) */
