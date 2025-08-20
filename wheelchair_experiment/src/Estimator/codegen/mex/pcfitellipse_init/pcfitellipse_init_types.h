/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse_init_types.h
 *
 * Code generation for function 'pcfitellipse_init'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_b_pcfitellipse_init
#define typedef_b_pcfitellipse_init
typedef struct {
  real_T points_data[3000];
} b_pcfitellipse_init;
#endif /* typedef_b_pcfitellipse_init */

#ifndef typedef_pcfitellipse_initStackData
#define typedef_pcfitellipse_initStackData
typedef struct {
  b_pcfitellipse_init f0;
} pcfitellipse_initStackData;
#endif /* typedef_pcfitellipse_initStackData */

/* End of code generation (pcfitellipse_init_types.h) */
