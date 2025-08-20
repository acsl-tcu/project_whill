/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_observation_types.h
 *
 * Code generation for function 'calc_observation'
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
  real_T X;
  real_T Y;
  real_T yaw;
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  real_T COG_init[2];
  struct1_T Plant;
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_anonymous_function
#define typedef_anonymous_function
typedef struct {
  struct_T workspace;
} anonymous_function;
#endif /* typedef_anonymous_function */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  real_T f1[36];
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  real_T model[5];
  real_T inlierpoints[4000];
  real_T ModelType;
} struct2_T;
#endif /* typedef_struct2_T */

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

#ifndef typedef_emxArray_struct2_T
#define typedef_emxArray_struct2_T
typedef struct {
  struct2_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct2_T;
#endif /* typedef_emxArray_struct2_T */

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_uint8_T */
#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T
typedef struct emxArray_uint8_T emxArray_uint8_T;
#endif /* typedef_emxArray_uint8_T */

#ifndef typedef_pointCloud
#define typedef_pointCloud
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  emxArray_real_T *Location;
  emxArray_uint8_T *Color;
  emxArray_real_T *Normal;
  emxArray_real_T *Intensity;
  void *Kdtree;
  void *LocationHandle;
  boolean_T HasKdtreeConstructed;
  boolean_T HasLocationHandleAllocated;
} pointCloud;
#endif /* typedef_pointCloud */

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

#ifndef typedef_d_struct_T
#define typedef_d_struct_T
typedef struct {
  emxArray_real_T *points;
} d_struct_T;
#endif /* typedef_d_struct_T */

#ifndef typedef_b_anonymous_function
#define typedef_b_anonymous_function
typedef struct {
  d_struct_T workspace;
} b_anonymous_function;
#endif /* typedef_b_anonymous_function */

#ifndef c_typedef_coder_internal_sticky
#define c_typedef_coder_internal_sticky
typedef struct {
  b_anonymous_function value;
} coder_internal_stickyStruct;
#endif /* c_typedef_coder_internal_sticky */

#ifndef c_typedef_b_coder_internal_stic
#define c_typedef_b_coder_internal_stic
typedef struct {
  anonymous_function value;
  coder_internal_stickyStruct next;
} b_coder_internal_stickyStruct;
#endif /* c_typedef_b_coder_internal_stic */

#ifndef c_typedef_c_coder_internal_stic
#define c_typedef_c_coder_internal_stic
typedef struct {
  b_coder_internal_stickyStruct next;
} c_coder_internal_stickyStruct;
#endif /* c_typedef_c_coder_internal_stic */

#ifndef c_typedef_d_coder_internal_stic
#define c_typedef_d_coder_internal_stic
typedef struct {
  c_coder_internal_stickyStruct next;
} d_coder_internal_stickyStruct;
#endif /* c_typedef_d_coder_internal_stic */

#ifndef c_typedef_e_coder_internal_stic
#define c_typedef_e_coder_internal_stic
typedef struct {
  d_coder_internal_stickyStruct next;
} e_coder_internal_stickyStruct;
#endif /* c_typedef_e_coder_internal_stic */

#ifndef c_typedef_f_coder_internal_stic
#define c_typedef_f_coder_internal_stic
typedef struct {
  e_coder_internal_stickyStruct next;
} f_coder_internal_stickyStruct;
#endif /* c_typedef_f_coder_internal_stic */

#ifndef c_typedef_g_coder_internal_stic
#define c_typedef_g_coder_internal_stic
typedef struct {
  f_coder_internal_stickyStruct next;
} g_coder_internal_stickyStruct;
#endif /* c_typedef_g_coder_internal_stic */

#ifndef c_typedef_h_coder_internal_stic
#define c_typedef_h_coder_internal_stic
typedef struct {
  g_coder_internal_stickyStruct next;
} h_coder_internal_stickyStruct;
#endif /* c_typedef_h_coder_internal_stic */

#ifndef c_typedef_i_coder_internal_stic
#define c_typedef_i_coder_internal_stic
typedef struct {
  h_coder_internal_stickyStruct next;
} i_coder_internal_stickyStruct;
#endif /* c_typedef_i_coder_internal_stic */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T sampleSize;
  real_T maxDistance;
  real_T TrialNum;
  real_T confDegree;
  real_T A[5];
  real_T B;
  real_T tth;
  real_T MD_threshold;
  real_T MSANum;
  real_T selectedArea;
  real_T eta;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_h_struct_T
#define typedef_h_struct_T
typedef struct {
  b_anonymous_function objfun;
  anonymous_function nonlin;
  real_T f_1;
  real_T cIneq_1;
  int32_T numEvals;
  boolean_T hasLB[5];
  boolean_T hasUB[5];
  boolean_T hasBounds;
} h_struct_T;
#endif /* typedef_h_struct_T */

/* End of code generation (calc_observation_types.h) */
