/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath_vec.h
 *
 * Code generation for function 'EvaluationPath_vec'
 *
 */

#pragma once

/* Include files */
#include "EvaluationPath_vec_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void EvaluationPath_vec(const emlrtStack *sp, const struct0_T *obj,
                        const emxArray_real_T *px, const emxArray_real_T *pu,
                        const real_T preobs_data[],
                        const int32_T preobs_size[3],
                        const struct1_T *param_FPM, emxArray_real_T *pw,
                        emxArray_boolean_T *remove_sample);

/* End of code generation (EvaluationPath_vec.h) */
