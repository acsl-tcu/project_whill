/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * feasibleratiotest.h
 *
 * Code generation for function 'feasibleratiotest'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T feasibleratiotest(
    const emlrtStack *sp, const real_T solution_xstar[8],
    const real_T solution_searchDir[8], real_T workspace[120],
    int32_T workingset_nVar, const real_T workingset_Aineq[16],
    const real_T workingset_bineq[2], const real_T workingset_lb[8],
    const real_T workingset_ub[8], const int32_T workingset_indexLB[8],
    const int32_T workingset_indexUB[8], const int32_T workingset_sizes[5],
    const int32_T workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr[15],
    const int32_T workingset_nWConstr[5], boolean_T isPhaseOne,
    boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);

/* End of code generation (feasibleratiotest.h) */
