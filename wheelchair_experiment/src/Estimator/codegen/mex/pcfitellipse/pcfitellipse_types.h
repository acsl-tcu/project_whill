/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse_types.h
 *
 * Code generation for function 'pcfitellipse'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  real_T COG_init[2];
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_anonymous_function
#define typedef_anonymous_function
typedef struct {
  struct_T workspace;
} anonymous_function;
#endif /* typedef_anonymous_function */

#ifndef struct_emxArray_real_T_1500x2
#define struct_emxArray_real_T_1500x2
struct emxArray_real_T_1500x2 {
  real_T data[3000];
  int32_T size[2];
};
#endif /* struct_emxArray_real_T_1500x2 */
#ifndef typedef_emxArray_real_T_1500x2
#define typedef_emxArray_real_T_1500x2
typedef struct emxArray_real_T_1500x2 emxArray_real_T_1500x2;
#endif /* typedef_emxArray_real_T_1500x2 */

#ifndef typedef_i_struct_T
#define typedef_i_struct_T
typedef struct {
  emxArray_real_T_1500x2 points;
} i_struct_T;
#endif /* typedef_i_struct_T */

#ifndef typedef_b_anonymous_function
#define typedef_b_anonymous_function
typedef struct {
  i_struct_T workspace;
} b_anonymous_function;
#endif /* typedef_b_anonymous_function */

#ifndef typedef_l_struct_T
#define typedef_l_struct_T
typedef struct {
  b_anonymous_function objfun;
  anonymous_function nonlin;
  real_T f_1;
  real_T cIneq_1;
  real_T f_2;
  real_T cIneq_2;
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T isEmptyNonlcon;
  boolean_T hasLB[5];
  boolean_T hasUB[5];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
} l_struct_T;
#endif /* typedef_l_struct_T */

#ifndef typedef_b_pcfitellipse_anonFcn2
#define typedef_b_pcfitellipse_anonFcn2
typedef struct {
  l_struct_T FiniteDifferences;
} b_pcfitellipse_anonFcn2;
#endif /* typedef_b_pcfitellipse_anonFcn2 */

#ifndef typedef_b_msac
#define typedef_b_msac
typedef struct {
  real_T samplePoints_data[3000];
} b_msac;
#endif /* typedef_b_msac */

#ifndef typedef_pcfitellipseStackData
#define typedef_pcfitellipseStackData
typedef struct {
  b_pcfitellipse_anonFcn2 f0;
  b_msac f1;
} pcfitellipseStackData;
#endif /* typedef_pcfitellipseStackData */

/* End of code generation (pcfitellipse_types.h) */
