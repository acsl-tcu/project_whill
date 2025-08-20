/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitptCOG.h
 *
 * Code generation for function 'pcfitptCOG'
 *
 */

#pragma once

/* Include files */
#include "calc_observation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void pcfitptCOG(const emlrtStack *sp, const pointCloud *point,
                const real_T xhat[6], real_T modelptCOG_crr[2],
                real_T modelptCOG[2]);

/* End of code generation (pcfitptCOG.h) */
