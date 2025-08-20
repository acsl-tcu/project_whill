/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * feasibleJPDAEvents.h
 *
 * Code generation for function 'feasibleJPDAEvents'
 *
 */

#pragma once

/* Include files */
#include "mexLidarTracker_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void feasibleJPDAEvents(const emlrtStack *sp,
                        const emxArray_boolean_T *validationMatrix,
                        emxArray_boolean_T *outFJE);

/* End of code generation (feasibleJPDAEvents.h) */
