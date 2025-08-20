/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexLidarTracker_internal_types.h
 *
 * Code generation for function 'mexLidarTracker'
 *
 */

#pragma once

/* Include files */
#include "mexLidarTracker_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_HelperBoundingBoxDetector
#define typedef_HelperBoundingBoxDetector
typedef struct {
  int32_T isInitialized;
  real_T SegmentationMinDistance;
  real_T MinDetectionsPerCluster;
  real_T MaxZDistanceCluster;
  real_T MinZDistanceCluster;
  real_T MeasurementNoise[9];
} HelperBoundingBoxDetector;
#endif /* typedef_HelperBoundingBoxDetector */

#ifndef typedef_emxArray_struct1_T_30
#define typedef_emxArray_struct1_T_30
typedef struct {
  struct1_T data[30];
  int32_T size[1];
} emxArray_struct1_T_30;
#endif /* typedef_emxArray_struct1_T_30 */

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

#ifndef typedef_rtRunTimeErrorInfo
#define typedef_rtRunTimeErrorInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtRunTimeErrorInfo;
#endif /* typedef_rtRunTimeErrorInfo */

/* End of code generation (mexLidarTracker_internal_types.h) */
