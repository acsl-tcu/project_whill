/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexLidarTracker_types.h
 *
 * Code generation for function 'mexLidarTracker'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T X;
  real_T Y;
  real_T yaw;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3
typedef struct {
  uint32_T f1[8];
} cell_wrap_3;
#endif /* typedef_cell_wrap_3 */

#ifndef typedef_trackHistoryLogic
#define typedef_trackHistoryLogic
typedef struct {
  boolean_T pRecentHistory[50];
  boolean_T pIsFirstUpdate;
} trackHistoryLogic;
#endif /* typedef_trackHistoryLogic */

#ifndef typedef_c_matlabshared_tracking_interna
#define typedef_c_matlabshared_tracking_interna
typedef struct {
  int32_T isInitialized;
  cell_wrap_3 inputVarSize[4];
} c_matlabshared_tracking_interna;
#endif /* typedef_c_matlabshared_tracking_interna */

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

#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T
struct emxArray_real32_T {
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real32_T */
#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T
typedef struct emxArray_real32_T emxArray_real32_T;
#endif /* typedef_emxArray_real32_T */

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T
struct emxArray_uint32_T {
  uint32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_uint32_T */
#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T
typedef struct emxArray_uint32_T emxArray_uint32_T;
#endif /* typedef_emxArray_uint32_T */

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

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T
struct emxArray_int8_T {
  int8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int8_T */
#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T
typedef struct emxArray_int8_T emxArray_int8_T;
#endif /* typedef_emxArray_int8_T */

#ifndef struct_emxArray_uint32_T_1x31
#define struct_emxArray_uint32_T_1x31
struct emxArray_uint32_T_1x31 {
  uint32_T data[31];
  int32_T size[2];
};
#endif /* struct_emxArray_uint32_T_1x31 */
#ifndef typedef_emxArray_uint32_T_1x31
#define typedef_emxArray_uint32_T_1x31
typedef struct emxArray_uint32_T_1x31 emxArray_uint32_T_1x31;
#endif /* typedef_emxArray_uint32_T_1x31 */

#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  emxArray_uint32_T *DetectionIndices;
  emxArray_uint32_T_1x31 TrackIDs;
  emxArray_boolean_T *ValidationMatrix;
  uint32_T SensorIndex;
  real_T TimeStamp;
  emxArray_real_T *MarginalProbabilities;
  emxArray_real_T *Likelihood;
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T
typedef struct {
  struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct_T;
#endif /* typedef_emxArray_struct_T */

#ifndef typedef_emxArray_struct_T_1x30
#define typedef_emxArray_struct_T_1x30
typedef struct {
  struct_T data[30];
  int32_T size[2];
} emxArray_struct_T_1x30;
#endif /* typedef_emxArray_struct_T_1x30 */

#ifndef typedef_objectDetection
#define typedef_objectDetection
typedef struct {
  real_T Time;
  real_T Measurement[3];
  real_T SensorIndex;
  real_T ObjectClassID;
  real_T pMeasurementNoise[9];
} objectDetection;
#endif /* typedef_objectDetection */

#ifndef typedef_emxArray_objectDetection
#define typedef_emxArray_objectDetection
typedef struct {
  objectDetection *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_objectDetection;
#endif /* typedef_emxArray_objectDetection */

#ifndef typedef_c_emxArray_pointclouds_internal
#define typedef_c_emxArray_pointclouds_internal
typedef struct {
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} c_emxArray_pointclouds_internal;
#endif /* typedef_c_emxArray_pointclouds_internal */

#ifndef typedef_pointCloud
#define typedef_pointCloud
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  emxArray_real32_T *Location;
  emxArray_uint8_T *Color;
  emxArray_real32_T *Normal;
  emxArray_real32_T *Intensity;
  emxArray_real32_T *RangeData;
  void *Kdtree;
  void *LocationHandle;
  boolean_T HasKdtreeConstructed;
  boolean_T HasLocationHandleAllocated;
  c_emxArray_pointclouds_internal *PointCloudArrayData;
} pointCloud;
#endif /* typedef_pointCloud */

#ifndef typedef_trackingEKF
#define typedef_trackingEKF
typedef struct {
  real_T pState[6];
  real_T pSqrtStateCovariance[36];
  real_T pSqrtStateCovarianceScalar;
  boolean_T pIsSetStateCovariance;
  real_T pSqrtProcessNoise[9];
  real_T pSqrtProcessNoiseScalar;
  boolean_T pIsSetProcessNoise;
  real_T pSqrtMeasurementNoise[9];
  real_T pSqrtMeasurementNoiseScalar;
  boolean_T pIsSetMeasurementNoise;
  boolean_T pHasPrediction;
  boolean_T pIsValidStateTransitionFcn;
  boolean_T pIsValidMeasurementFcn;
  boolean_T pIsFirstCallPredict;
  boolean_T pIsFirstCallCorrect;
  real_T pJacobian[36];
  boolean_T pIsDistributionsSetup;
  boolean_T pIsInitialized;
  boolean_T IsLastJacobianInitialized;
  boolean_T pShouldWarn;
  boolean_T pWasRetrodicted;
} trackingEKF;
#endif /* typedef_trackingEKF */

#ifndef typedef_d_matlabshared_tracking_interna
#define typedef_d_matlabshared_tracking_interna
typedef struct {
  uint32_T BranchID;
  uint32_T TrackID;
  real_T Time;
  trackHistoryLogic *TrackLogic;
  boolean_T IsConfirmed;
  real_T ObjectClassID;
  real_T UpdateTime;
  trackingEKF *Filter;
  uint32_T pAge;
  boolean_T pIsCoasted;
  trackingEKF *pDistanceFilter;
  boolean_T pUsedObjectAttributes[20];
} d_matlabshared_tracking_interna;
#endif /* typedef_d_matlabshared_tracking_interna */

#ifndef typedef_e_matlabshared_tracking_interna
#define typedef_e_matlabshared_tracking_interna
typedef struct {
  int32_T isInitialized;
  int32_T pNumDetections;
  emxArray_objectDetection *pDetections;
  emxArray_real_T *pOriginatingSensor;
  emxArray_boolean_T *pIsOOSM;
  objectDetection pSampleDetection;
  emxArray_real_T *pDetectionTimes;
} e_matlabshared_tracking_interna;
#endif /* typedef_e_matlabshared_tracking_interna */

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  uint32_T SensorIndex;
  real_T TimeStamp;
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_c_emxArray_matlabshared_trackin
#define typedef_c_emxArray_matlabshared_trackin
typedef struct {
  int32_T size[2];
} c_emxArray_matlabshared_trackin;
#endif /* typedef_c_emxArray_matlabshared_trackin */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  uint32_T TrackID;
  uint32_T BranchID;
  uint32_T SourceIndex;
  real_T UpdateTime;
  uint32_T Age;
  real_T State[6];
  real_T StateCovariance[36];
  real_T ObjectClassID;
  real_T ObjectClassProbabilities;
  char_T TrackLogic[7];
  boolean_T TrackLogicState[10];
  boolean_T IsConfirmed;
  boolean_T IsCoasted;
  boolean_T IsSelfReported;
  c_emxArray_matlabshared_trackin ObjectAttributes;
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_trackerJPDA
#define typedef_trackerJPDA
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_3 inputVarSize[3];
  d_matlabshared_tracking_interna *pTracksList[30];
  int32_T pNumLiveTracks;
  uint32_T pTrackIDs[30];
  boolean_T pConfirmedTracks[30];
  objectDetection pSampleDetection;
  trackingEKF *pDistFilter;
  e_matlabshared_tracking_interna *cDetectionManager;
  uint32_T pUsedSensors[20];
  real_T pLastTimeStamp;
  uint32_T pLastTrackID;
  boolean_T pWasDetectable[30];
  real_T pTrackDetectionProbability[30];
  b_struct_T pClusterTypeDef;
  c_matlabshared_tracking_interna cCostCalculator;
  uint32_T c_pCurrentMaxNumDetectionsPerCl;
  uint32_T pCurrentMaxNumTracksPerCluster;
  trackingEKF _pobj0[61];
  trackHistoryLogic _pobj1[30];
  d_matlabshared_tracking_interna _pobj2[30];
  e_matlabshared_tracking_interna _pobj3;
} trackerJPDA;
#endif /* typedef_trackerJPDA */

/* End of code generation (mexLidarTracker_types.h) */
