/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath_types.h
 *
 * Code generation for function 'EvaluationPath'
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

#ifndef struct_emxArray_real_T_30x2
#define struct_emxArray_real_T_30x2
struct emxArray_real_T_30x2 {
  real_T data[60];
  int32_T size[2];
};
#endif /* struct_emxArray_real_T_30x2 */
#ifndef typedef_emxArray_real_T_30x2
#define typedef_emxArray_real_T_30x2
typedef struct emxArray_real_T_30x2 emxArray_real_T_30x2;
#endif /* typedef_emxArray_real_T_30x2 */

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

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T K;
  real_T NP;
  real_T ObsNum;
  emxArray_real_T_30x2 VOBS;
  real_T r_wheel;
  real_T R[2];
  real_T W;
  real_T Wo;
  real_T Vref;
  real_T limit[84000];
  real_T target[42000];
  real_T ltheta[16];
  real_T wall_penalty1;
  real_T wall_penalty2;
  real_T wall_threshold;
  real_T wheel_width;
  real_T wheel_len_front;
  real_T wheel_len_rear;
  real_T target_n[21000];
  emxArray_real_T_50x4 wall;
  emxArray_real_T_50 selectZone;
  real_T NoEntryZone[240];
  emxArray_real_T_10 ZoneNum;
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

#ifndef typedef_b_EvaluationPath
#define typedef_b_EvaluationPath
typedef struct {
  real_T px[21000];
  real_T y[20000];
  real_T a[20000];
} b_EvaluationPath;
#endif /* typedef_b_EvaluationPath */

#ifndef typedef_b_EvaluationPath_api
#define typedef_b_EvaluationPath_api
typedef struct {
  struct0_T obj;
} b_EvaluationPath_api;
#endif /* typedef_b_EvaluationPath_api */

#ifndef typedef_EvaluationPathStackData
#define typedef_EvaluationPathStackData
typedef struct {
  b_EvaluationPath f0;
  b_EvaluationPath_api f1;
} EvaluationPathStackData;
#endif /* typedef_EvaluationPathStackData */

/* End of code generation (EvaluationPath_types.h) */
