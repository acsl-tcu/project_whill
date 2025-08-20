/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * determine_target_location_fordemo_types.h
 *
 * Code generation for function 'determine_target_location_fordemo'
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

#ifndef struct_emxArray_real_T_50x4
#define struct_emxArray_real_T_50x4
struct emxArray_real_T_50x4 {
  real_T data[200];
  int32_T size[2];
};
#endif /* struct_emxArray_real_T_50x4 */
#ifndef typedef_emxArray_real_T_50x4
#define typedef_emxArray_real_T_50x4
typedef struct emxArray_real_T_50x4 emxArray_real_T_50x4;
#endif /* typedef_emxArray_real_T_50x4 */

#ifndef struct_emxArray_real_T_50x3
#define struct_emxArray_real_T_50x3
struct emxArray_real_T_50x3 {
  real_T data[150];
  int32_T size[2];
};
#endif /* struct_emxArray_real_T_50x3 */
#ifndef typedef_emxArray_real_T_50x3
#define typedef_emxArray_real_T_50x3
typedef struct emxArray_real_T_50x3 emxArray_real_T_50x3;
#endif /* typedef_emxArray_real_T_50x3 */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T NP;
  real_T K;
  emxArray_real_T_50x2 waypoint;
  emxArray_real_T *target_n;
  emxArray_real_T *target;
  emxArray_real_T *limit;
  emxArray_real_T_50x4 wall;
  emxArray_real_T_50x3 abc;
} struct0_T;
#endif /* typedef_struct0_T */

/* End of code generation (determine_target_location_fordemo_types.h) */
