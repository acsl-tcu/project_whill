/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexLidarTracker_emxutil.h
 *
 * Code generation for function 'mexLidarTracker_emxutil'
 *
 */

#pragma once

/* Include files */
#include "mexLidarTracker_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void c_emxEnsureCapacity_objectDetec(const emlrtStack *sp,
                                     emxArray_objectDetection *emxArray,
                                     int32_T oldNumel,
                                     const emlrtRTEInfo *srcLocation);

void c_emxFreeStruct_matlabshared_tr(const emlrtStack *sp,
                                     e_matlabshared_tracking_interna *pStruct);

void c_emxFree_pointclouds_internal_(
    const emlrtStack *sp, c_emxArray_pointclouds_internal **pEmxArray);

void c_emxInitStruct_matlabshared_tr(const emlrtStack *sp,
                                     e_matlabshared_tracking_interna *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void c_emxInit_pointclouds_internal_(
    const emlrtStack *sp, c_emxArray_pointclouds_internal **pEmxArray,
    const emlrtRTEInfo *srcLocation);

void emxCopyStruct_struct_T(const emlrtStack *sp, struct_T *dst,
                            const struct_T *src,
                            const emlrtRTEInfo *srcLocation);

void emxCopy_boolean_T(const emlrtStack *sp, emxArray_boolean_T **dst,
                       emxArray_boolean_T *const *src,
                       const emlrtRTEInfo *srcLocation);

void emxCopy_real_T(const emlrtStack *sp, emxArray_real_T **dst,
                    emxArray_real_T *const *src,
                    const emlrtRTEInfo *srcLocation);

void emxCopy_uint32_T(const emlrtStack *sp, emxArray_uint32_T **dst,
                      emxArray_uint32_T *const *src,
                      const emlrtRTEInfo *srcLocation);

void emxCopy_uint32_T_1x31(emxArray_uint32_T_1x31 *dst,
                           const emxArray_uint32_T_1x31 *src);

void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_int8_T(const emlrtStack *sp, emxArray_int8_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real32_T(const emlrtStack *sp,
                                emxArray_real32_T *emxArray, int32_T oldNumel,
                                const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_struct_T(const emlrtStack *sp,
                                emxArray_struct_T *emxArray, int32_T oldNumel,
                                const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_struct_T1(const emlrtStack *sp, struct_T data[30],
                                 const int32_T size[2], int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_uint32_T(const emlrtStack *sp,
                                emxArray_uint32_T *emxArray, int32_T oldNumel,
                                const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_uint8_T(const emlrtStack *sp, emxArray_uint8_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxExpand_struct_T(const emlrtStack *sp, emxArray_struct_T *emxArray,
                        int32_T fromIndex, int32_T toIndex,
                        const emlrtRTEInfo *srcLocation);

void emxExpand_struct_T_1x30(const emlrtStack *sp, struct_T data[30],
                             int32_T fromIndex, int32_T toIndex,
                             const emlrtRTEInfo *srcLocation);

void emxFreeStruct_pointCloud(const emlrtStack *sp, pointCloud *pStruct);

void emxFreeStruct_struct_T(const emlrtStack *sp, struct_T *pStruct);

void emxFreeStruct_trackerJPDA(const emlrtStack *sp, trackerJPDA *pStruct);

void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray);

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray);

void emxFree_int8_T(const emlrtStack *sp, emxArray_int8_T **pEmxArray);

void emxFree_objectDetection(const emlrtStack *sp,
                             emxArray_objectDetection **pEmxArray);

void emxFree_real32_T(const emlrtStack *sp, emxArray_real32_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxFree_struct_T(const emlrtStack *sp, emxArray_struct_T **pEmxArray);

void emxFree_struct_T_1x30(const emlrtStack *sp,
                           emxArray_struct_T_1x30 *pEmxArray);

void emxFree_uint32_T(const emlrtStack *sp, emxArray_uint32_T **pEmxArray);

void emxFree_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray);

void emxInitStruct_pointCloud(const emlrtStack *sp, pointCloud *pStruct,
                              const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct_T(const emlrtStack *sp, struct_T *pStruct,
                            const emlrtRTEInfo *srcLocation, boolean_T doPush);

void emxInitStruct_trackerJPDA(const emlrtStack *sp, trackerJPDA *pStruct,
                               const emlrtRTEInfo *srcLocation);

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                       boolean_T doPush);

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     int32_T numDimensions, const emlrtRTEInfo *srcLocation);

void emxInit_int8_T(const emlrtStack *sp, emxArray_int8_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation);

void emxInit_objectDetection(const emlrtStack *sp,
                             emxArray_objectDetection **pEmxArray,
                             int32_T numDimensions,
                             const emlrtRTEInfo *srcLocation, boolean_T doPush);

void emxInit_real32_T(const emlrtStack *sp, emxArray_real32_T **pEmxArray,
                      int32_T numDimensions, const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                    boolean_T doPush);

void emxInit_struct_T(const emlrtStack *sp, emxArray_struct_T **pEmxArray,
                      const emlrtRTEInfo *srcLocation);

void emxInit_struct_T_1x30(emxArray_struct_T_1x30 *pEmxArray);

void emxInit_uint32_T(const emlrtStack *sp, emxArray_uint32_T **pEmxArray,
                      int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                      boolean_T doPush);

void emxInit_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxTrim_struct_T(const emlrtStack *sp, emxArray_struct_T *emxArray,
                      int32_T fromIndex, int32_T toIndex);

void emxTrim_struct_T_1x30(const emlrtStack *sp, struct_T data[30],
                           int32_T fromIndex, int32_T toIndex);

/* End of code generation (mexLidarTracker_emxutil.h) */
