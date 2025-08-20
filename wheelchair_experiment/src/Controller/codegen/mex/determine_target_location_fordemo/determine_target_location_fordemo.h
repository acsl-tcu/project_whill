/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * determine_target_location_fordemo.h
 *
 * Code generation for function 'determine_target_location_fordemo'
 *
 */

#pragma once

/* Include files */
#include "determine_target_location_fordemo_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void determine_target_location_fordemo(const emlrtStack *sp, struct0_T *obj,
                                       const emxArray_real_T *px,
                                       real_T resetWPIdx, emxArray_real_T *tgt,
                                       emxArray_real_T *lim,
                                       emxArray_real_T *tgt_n);

/* End of code generation (determine_target_location_fordemo.h) */
