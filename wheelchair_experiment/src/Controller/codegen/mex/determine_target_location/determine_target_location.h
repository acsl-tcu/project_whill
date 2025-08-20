/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * determine_target_location.h
 *
 * Code generation for function 'determine_target_location'
 *
 */

#pragma once

/* Include files */
#include "determine_target_location_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void determine_target_location(c_determine_target_locationStac *SD,
                               const emlrtStack *sp, const struct0_T *obj,
                               const real_T px[63000], real_T tgt_n[21000]);

/* End of code generation (determine_target_location.h) */
