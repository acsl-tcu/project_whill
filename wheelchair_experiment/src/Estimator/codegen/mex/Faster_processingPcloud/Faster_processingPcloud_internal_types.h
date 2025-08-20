/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Faster_processingPcloud_internal_types.h
 *
 * Code generation for function 'Faster_processingPcloud'
 *
 */

#pragma once

/* Include files */
#include "Faster_processingPcloud_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef c_typedef_HelperBoundingBoxDete
#define c_typedef_HelperBoundingBoxDete
typedef struct {
  int32_T isInitialized;
  real_T SegmentationMinDistance;
  real_T MinDetectionsPerCluster;
  real_T MaxZDistanceCluster;
  real_T MinZDistanceCluster;
} HelperBoundingBoxDetector;
#endif /* c_typedef_HelperBoundingBoxDete */

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

/* End of code generation (Faster_processingPcloud_internal_types.h) */
