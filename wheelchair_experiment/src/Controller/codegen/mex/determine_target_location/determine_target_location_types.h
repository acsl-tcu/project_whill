/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * determine_target_location_types.h
 *
 * Code generation for function 'determine_target_location'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_50x2
#define struct_emxArray_real_T_50x2
struct emxArray_real_T_50x2 {
  real_T data[100];
  int32_T size[2];
};
#endif /* struct_emxArray_real_T_50x2 */
#ifndef typedef_emxArray_real_T_50x2
#define typedef_emxArray_real_T_50x2
typedef struct emxArray_real_T_50x2 emxArray_real_T_50x2;
#endif /* typedef_emxArray_real_T_50x2 */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T NP;
  real_T K;
  emxArray_real_T_50x2 waypoint;
  real_T target_n[21000];
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef c_typedef_b_determine_target_lo
#define c_typedef_b_determine_target_lo
typedef struct {
  real_T px[42000];
  real_T dv[42000];
} b_determine_target_location;
#endif /* c_typedef_b_determine_target_lo */

#ifndef d_typedef_b_determine_target_lo
#define d_typedef_b_determine_target_lo
typedef struct {
  struct0_T obj;
} b_determine_target_location_api;
#endif /* d_typedef_b_determine_target_lo */

#ifndef c_typedef_c_determine_target_lo
#define c_typedef_c_determine_target_lo
typedef struct {
  b_determine_target_location f0;
  b_determine_target_location_api f1;
} c_determine_target_locationStac;
#endif /* c_typedef_c_determine_target_lo */

/* End of code generation (determine_target_location_types.h) */
