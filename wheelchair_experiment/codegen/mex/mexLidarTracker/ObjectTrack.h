/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ObjectTrack.h
 *
 * Code generation for function 'ObjectTrack'
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
boolean_T ObjectTrack_checkPromotion(d_matlabshared_tracking_interna *track);

d_matlabshared_tracking_interna *
ObjectTrack_copy(const emlrtStack *sp, d_matlabshared_tracking_interna *track,
                 d_matlabshared_tracking_interna *iobj_0,
                 trackHistoryLogic *iobj_1, trackingEKF *iobj_2);

void ObjectTrack_correctjpda(const emlrtStack *sp,
                             d_matlabshared_tracking_interna *track,
                             const objectDetection *detections,
                             const uint32_T usedSensors[20]);

void ObjectTrack_nullify(const emlrtStack *sp,
                         d_matlabshared_tracking_interna *track);

void ObjectTrack_predict(const emlrtStack *sp,
                         d_matlabshared_tracking_interna *track, real_T b_time);

void ObjectTrack_trackToStruct(const emlrtStack *sp,
                               d_matlabshared_tracking_interna *track,
                               struct1_T *trackStruct);

real_T c_ObjectTrack_calcCostOneDetect(const emlrtStack *sp,
                                       d_matlabshared_tracking_interna *track,
                                       const real_T detection_Measurement[3]);

void c_ObjectTrack_setAttributesFrom(const emlrtStack *sp,
                                     d_matlabshared_tracking_interna *track,
                                     real_T detection_SensorIndex,
                                     const uint32_T usedSensors[20]);

void c_ObjectTrack_sortDetectionsByT(const emlrtStack *sp,
                                     const emxArray_objectDetection *detections,
                                     const emxArray_uint32_T *detectionIndices,
                                     emxArray_int32_T *sorting);

/* End of code generation (ObjectTrack.h) */
