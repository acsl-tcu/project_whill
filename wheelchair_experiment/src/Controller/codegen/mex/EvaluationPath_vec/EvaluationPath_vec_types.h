/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath_vec_types.h
 *
 * Code generation for function 'EvaluationPath_vec'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T eta;
  real_T alpha;
  real_T margin;
  real_T obs_cost;
} struct1_T;
#endif /* typedef_struct1_T */

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

#ifndef struct_emxArray_real_T_50
#define struct_emxArray_real_T_50
struct emxArray_real_T_50 {
  real_T data[50];
  int32_T size[1];
};
#endif /* struct_emxArray_real_T_50 */
#ifndef typedef_emxArray_real_T_50
#define typedef_emxArray_real_T_50
typedef struct emxArray_real_T_50 emxArray_real_T_50;
#endif /* typedef_emxArray_real_T_50 */

#ifndef struct_emxArray_real_T_6x4x10
#define struct_emxArray_real_T_6x4x10
struct emxArray_real_T_6x4x10 {
  real_T data[240];
  int32_T size[3];
};
#endif /* struct_emxArray_real_T_6x4x10 */
#ifndef typedef_emxArray_real_T_6x4x10
#define typedef_emxArray_real_T_6x4x10
typedef struct emxArray_real_T_6x4x10 emxArray_real_T_6x4x10;
#endif /* typedef_emxArray_real_T_6x4x10 */

#ifndef struct_emxArray_real_T_10
#define struct_emxArray_real_T_10
struct emxArray_real_T_10 {
  real_T data[10];
  int32_T size[1];
};
#endif /* struct_emxArray_real_T_10 */
#ifndef typedef_emxArray_real_T_10
#define typedef_emxArray_real_T_10
typedef struct emxArray_real_T_10 emxArray_real_T_10;
#endif /* typedef_emxArray_real_T_10 */

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
  real_T K;
  real_T NP;
  real_T ObsNum;
  real_T R[2];
  real_T W;
  real_T Wo;
  emxArray_real_T *target;
  real_T ltheta[16];
  real_T wall_penalty1;
  real_T wall_threshold;
  real_T wheel_width;
  real_T wheel_len_front;
  real_T wheel_len_rear;
  emxArray_real_T *target_n;
  emxArray_real_T_50 selectZone;
  emxArray_real_T_6x4x10 NoEntryZone;
  emxArray_real_T_10 ZoneNum;
  emxArray_real_T_50 V_ref;
  emxArray_real_T_50 th_target_w;
  emxArray_real_T_50x2 waypoint;
} struct0_T;
#endif /* typedef_struct0_T */

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

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef typedef_cell_wrap_7
#define typedef_cell_wrap_7
typedef struct {
  emxArray_boolean_T *f1;
} cell_wrap_7;
#endif /* typedef_cell_wrap_7 */

/* End of code generation (EvaluationPath_vec_types.h) */
