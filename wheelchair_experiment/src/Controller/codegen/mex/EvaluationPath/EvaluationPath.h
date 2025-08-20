/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath.h
 *
 * Code generation for function 'EvaluationPath'
 *
 */

#pragma once

/* Include files */
#include "EvaluationPath_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void EvaluationPath(EvaluationPathStackData *SD, const emlrtStack *sp,
                    const struct0_T *obj, const real_T px[63000],
                    const real_T pu[42000], const real_T preobs_data[],
                    const int32_T preobs_size[3], const struct1_T *param_FPM,
                    emxArray_real_T *pw, boolean_T remove_sample[1000]);

/* End of code generation (EvaluationPath.h) */
