/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexLidarTracker.c
 *
 * Code generation for function 'mexLidarTracker'
 *
 */

/* Include files */
#include "mexLidarTracker.h"
#include "SystemCore.h"
#include "atan2.h"
#include "handle.h"
#include "hypot.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_internal_types.h"
#include "mexLidarTracker_types.h"
#include "pointCloud.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T_30
#define struct_emxArray_real_T_30
struct emxArray_real_T_30 {
  real_T data[30];
};
#endif /* struct_emxArray_real_T_30 */
#ifndef typedef_emxArray_real_T_30
#define typedef_emxArray_real_T_30
typedef struct emxArray_real_T_30 emxArray_real_T_30;
#endif /* typedef_emxArray_real_T_30 */

/* Variable Definitions */
static boolean_T detectorModel_not_empty;

static trackerJPDA tracker;

static boolean_T tracker_not_empty;

static boolean_T detectableTracksInput_not_empty;

static boolean_T currentNumTracks_not_empty;

static emlrtRSInfo emlrtRSI = {
    14,                /* lineNo */
    "mexLidarTracker", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    30,                /* lineNo */
    "mexLidarTracker", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    45,                /* lineNo */
    "mexLidarTracker", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    50,                /* lineNo */
    "mexLidarTracker", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    61,                /* lineNo */
    "mexLidarTracker", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    64,                /* lineNo */
    "mexLidarTracker", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    94,                /* lineNo */
    "mexLidarTracker", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    54,                                                    /* lineNo */
    "HelperBoundingBoxDetector/HelperBoundingBoxDetector", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    55,                                                    /* lineNo */
    "HelperBoundingBoxDetector/HelperBoundingBoxDetector", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    175,                                                           /* lineNo */
    "trackerJPDA/trackerJPDA",                                     /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/trackerJPDA.m" /* pathName
                                                                    */
};

static emlrtRSInfo kp_emlrtRSI = {
    1,                           /* lineNo */
    "SystemCore/parenReference", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pathName */
};

static emlrtRSInfo jpb_emlrtRSI = {
    24,                        /* lineNo */
    "helperCalcDetectability", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/helperCalcDetectability"
    ".m" /* pathName */
};

static emlrtRSInfo kpb_emlrtRSI = {
    33,                        /* lineNo */
    "helperCalcDetectability", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/helperCalcDetectability"
    ".m" /* pathName */
};

static emlrtRSInfo lpb_emlrtRSI = {
    37,                        /* lineNo */
    "helperCalcDetectability", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/helperCalcDetectability"
    ".m" /* pathName */
};

static emlrtRSInfo mpb_emlrtRSI = {
    62,                  /* lineNo */
    "getTrackPositions", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "getTrackPositions.m" /* pathName */
};

static emlrtRSInfo npb_emlrtRSI = {
    12,         /* lineNo */
    "cart2sph", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/cart2sph.m" /* pathName
                                                                          */
};

static emlrtRSInfo opb_emlrtRSI = {
    13,         /* lineNo */
    "cart2sph", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/cart2sph.m" /* pathName
                                                                          */
};

static emlrtRSInfo ppb_emlrtRSI = {
    14,         /* lineNo */
    "cart2sph", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/cart2sph.m" /* pathName
                                                                          */
};

static emlrtRSInfo qpb_emlrtRSI = {
    15,         /* lineNo */
    "cart2sph", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/cart2sph.m" /* pathName
                                                                          */
};

static emlrtBCInfo emlrtBCI = {
    1,                       /* iFirst */
    30,                      /* iLast */
    61,                      /* lineNo */
    89,                      /* colNo */
    "detectableTracksInput", /* aName */
    "mexLidarTracker",       /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m", /* pName */
    0                                      /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    1,                       /* iFirst */
    30,                      /* iLast */
    64,                      /* lineNo */
    33,                      /* colNo */
    "detectableTracksInput", /* aName */
    "mexLidarTracker",       /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m", /* pName */
    0                                      /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,                /* nDims */
    64,                /* lineNo */
    9,                 /* colNo */
    "mexLidarTracker", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    54,               /* lineNo */
    17,               /* colNo */
    "",               /* aName */
    "getTrackPosVel", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/getTrackPosVel.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    54,               /* lineNo */
    44,               /* colNo */
    "",               /* aName */
    "getTrackPosVel", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/getTrackPosVel.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    30,                        /* lineNo */
    30,                        /* colNo */
    "tracks",                  /* aName */
    "helperCalcDetectability", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/helperCalcDetectability"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    30,                        /* lineNo */
    18,                        /* colNo */
    "trackIDs",                /* aName */
    "helperCalcDetectability", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/helperCalcDetectability"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    35,                        /* lineNo */
    15,                        /* colNo */
    "probDetection",           /* aName */
    "helperCalcDetectability", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/helperCalcDetectability"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    36,                        /* lineNo */
    15,                        /* colNo */
    "probDetection",           /* aName */
    "helperCalcDetectability", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/helperCalcDetectability"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    4,                 /* lineNo */
    26,                /* colNo */
    "mexLidarTracker", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = {
    45,                /* lineNo */
    1,                 /* colNo */
    "mexLidarTracker", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/mexLidarTracker.m" /* pName */
};

/* Function Definitions */
void b_detectableTracksInput_not_emp(void)
{
  detectableTracksInput_not_empty = false;
}

void currentNumTracks_not_empty_init(void)
{
  currentNumTracks_not_empty = false;
}

void mexLidarTracker(const emlrtStack *sp,
                     const emxArray_real32_T *ptCloudLocations, real_T b_time,
                     const struct0_T *Plant, const real_T wall[6], real_T axis,
                     real_T SP, emxArray_objectDetection *detections,
                     emxArray_real_T *obstacleIndices,
                     emxArray_real_T *croppedIndices,
                     struct1_T confirmedTracks_data[],
                     int32_T confirmedTracks_size[1], real_T modelProbs_data[],
                     int32_T modelProbs_size[2], real32_T *numClusters,
                     emxArray_uint32_T *labels)
{
  static HelperBoundingBoxDetector detectorModel;
  static const real_T varargin_6[9] = {0.001, 0.0, 0.0, 0.0,  0.001,
                                       0.0,   0.0, 0.0, 0.001};
  static real_T detectableTracksInput[60];
  static real_T currentNumTracks;
  static const int8_T b_a[18] = {1, 0, 0, 0, 0, 0, 0, 1, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 1};
  HelperBoundingBoxDetector *obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T_30 iqb_emlrtRSI;
  emxArray_struct1_T_30 varargout_2;
  emxArray_struct1_T_30 varargout_3;
  pointCloud ptCloud;
  trackerJPDA *b_obj;
  real_T pos_data[90];
  real_T varargin_3_data[60];
  real_T hypotxy_data[30];
  real_T r_data[30];
  real_T x_data[30];
  int32_T b_iv[2];
  int32_T varargin_3_size[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T loop_ub;
  int32_T probDetection_size;
  uint32_T trackIDs_data[30];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud(sp, &ptCloud, &rd_emlrtRTEI);
  emlrtMEXProfilingFunctionEntry((char_T *)mexLidarTracker_complete_name,
                                 isMexOutdated);
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ptCloud,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  ptCloud.matlabCodegenIsDeleted = true;
  /* ,obspredict */
  emlrtMEXProfilingStatement(2, isMexOutdated);
  if ((!detectorModel_not_empty) || (!tracker_not_empty) ||
      (!detectableTracksInput_not_empty) || (!currentNumTracks_not_empty)) {
    /*  Use the same starting seed as MATLAB to reproduce results in SIL */
    /*  simulation. */
    /*      rng(2018); */
    /*  A bounding box detector model. */
    emlrtMEXProfilingStatement(3, isMexOutdated);
    st.site = &emlrtRSI;
    emlrtMEXProfilingFunctionEntry((char_T *)c_HelperBoundingBoxDetector_Hel,
                                   isMexOutdated);
    detectorModel.MaxZDistanceCluster = 3.0;
    detectorModel.MinZDistanceCluster = -3.0;
    emlrtMEXProfilingStatement(0, isMexOutdated);
    emlrtMEXProfilingStatement(0, isMexOutdated);
    b_st.site = &h_emlrtRSI;
    detectorModel.isInitialized = 0;
    emlrtMEXProfilingStatement(1, isMexOutdated);
    b_st.site = &i_emlrtRSI;
    detectorModel.SegmentationMinDistance = 0.4;
    detectorModel.MinDetectionsPerCluster = 10.0;
    memcpy(&detectorModel.MeasurementNoise[0], &varargin_6[0],
           9U * sizeof(real_T));
    emlrtMEXProfilingStatement(2, isMexOutdated);
    emlrtMEXProfilingFunctionExit(isMexOutdated);
    detectorModel_not_empty = true;
    /*    % minimum Euclidian distance */
    /*      % minimum points per cluster */
    /*        % measurement noise in detection report. */
    /*  maximum distance of ground points from ground plane */
    /* 30*[1 inf]; % Assignment threshold; */
    /* [3 10];    % Confirmation threshold for history logic */
    /* [5 5];     % Deletion threshold for history logic */
    /* 1e-6;                 % False-alarm rate per unit volume */
    /*      filterInitFcn = @helperInitIMMFilter; */
    /*      filterInitFcn = @initekfimm; */
    /*      filterInitFcn = @initializeIMM; */
    emlrtMEXProfilingStatement(10, isMexOutdated);
    st.site = &b_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    tracker.isInitialized = 0;
    tracker.matlabCodegenIsDeleted = false;
    tracker_not_empty = true;
    emlrtMEXProfilingStatement(15, isMexOutdated);
    memset(&detectableTracksInput[0], 0, 60U * sizeof(real_T));
    detectableTracksInput_not_empty = true;
    emlrtMEXProfilingStatement(16, isMexOutdated);
    currentNumTracks = 0.0;
    currentNumTracks_not_empty = true;
    emlrtMEXProfilingStatement(17, isMexOutdated);
  }
  emlrtMEXProfilingStatement(18, isMexOutdated);
  st.site = &c_emlrtRSI;
  pointCloud_pointCloud(&st, &ptCloud, ptCloudLocations);
  /*  Detector model */
  emlrtMEXProfilingStatement(19, isMexOutdated);
  st.site = &d_emlrtRSI;
  obj = &detectorModel;
  b_st.site = &l_emlrtRSI;
  *numClusters = SystemCore_step(
      &b_st, obj, &ptCloud, b_time, Plant->X, Plant->Y, Plant->yaw, wall, axis,
      SP, detections, obstacleIndices, croppedIndices, labels);
  /*  loading dammy file */
  /*       if isempty(detections) && time < 8e-03 */
  /*                  detections = cell(1,1); */
  /*                  detections{1} =
   * objectDetection(time,cast([100000;100000;100000],'double'),... */
  /*                  'MeasurementNoise',double([0.00100000000000000,0,0;0,0.00100000000000000,0;0,0,0.00100000000000000]),'ObjectAttributes',struct,...
   */
  /*                  'MeasurementParameters',{}); */
  /*       end */
  /*  Call tracker */
  emlrtMEXProfilingStatement(20, isMexOutdated);
  if (currentNumTracks < 1.0) {
    loop_ub = 0;
  } else {
    i = (int32_T)currentNumTracks;
    if (((int32_T)currentNumTracks < 1) || ((int32_T)currentNumTracks > 30)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 30, &emlrtBCI, (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)currentNumTracks;
  }
  st.site = &e_emlrtRSI;
  b_obj = &tracker;
  varargin_3_size[0] = loop_ub;
  varargin_3_size[1] = 2;
  for (i = 0; i < 2; i++) {
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      varargin_3_data[b_loop_ub + loop_ub * i] =
          detectableTracksInput[b_loop_ub + 30 * i];
    }
  }
  b_st.site = &kp_emlrtRSI;
  confirmedTracks_size[0] = b_SystemCore_step(
      &b_st, b_obj, detections, b_time, varargin_3_data, varargin_3_size,
      confirmedTracks_data, varargout_2.data, varargout_3.data,
      &varargout_2.size[0], &varargout_3.size[0]);
  /*  Update the detectability input */
  emlrtMEXProfilingStatement(21, isMexOutdated);
  currentNumTracks = varargout_3.size[0];
  emlrtMEXProfilingStatement(22, isMexOutdated);
  if (currentNumTracks < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)currentNumTracks;
    if (currentNumTracks > 30.0) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 30, &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
  }
  st.site = &f_emlrtRSI;
  emlrtMEXProfilingFunctionEntry((char_T *)c_helperCalcDetectability_compl,
                                 isMexOutdated);
  /*  This is a helper function to calculate the detection probability of */
  /*  tracks for the lidar tracking example. It may be removed in a future */
  /*  release. */
  /*  Copyright 2019 The MathWorks, Inc. */
  /*  The bounding box detector has low probability of segmenting point clouds
   */
  /*  into bounding boxes are distances greater than 40 meters. This function */
  /*  models this effect using a state-dependent probability of detection for */
  /*  each tracker. After a maximum range, the Pd is set to a high value to */
  /*  enable deletion of track at a faster rate. */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  if (varargout_3.size[0] == 0) {
    emlrtMEXProfilingStatement(2, isMexOutdated);
    varargin_3_size[0] = 0;
    varargin_3_size[1] = 2;
    emlrtMEXProfilingStatement(3, isMexOutdated);
  } else {
    real_T probDetection_data[30];
    real_T z_data[30];
    int32_T pos_size_idx_0;
    int32_T trackIDs_size_idx_1;
    emlrtMEXProfilingStatement(12, isMexOutdated);
    b_st.site = &jpb_emlrtRSI;
    c_st.site = &mpb_emlrtRSI;
    pos_size_idx_0 = varargout_3.size[0];
    i = varargout_3.size[0];
    for (b_i = 0; b_i < i; b_i++) {
      real_T a[3];
      if (b_i + 1 > varargout_3.size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, varargout_3.size[0],
                                      &d_emlrtBCI, &c_st);
      }
      for (b_loop_ub = 0; b_loop_ub < 3; b_loop_ub++) {
        real_T d;
        d = 0.0;
        for (probDetection_size = 0; probDetection_size < 6;
             probDetection_size++) {
          d += (real_T)b_a[b_loop_ub + 3 * probDetection_size] *
               varargout_3.data[b_i].State[probDetection_size];
        }
        a[b_loop_ub] = d;
      }
      if (b_i + 1 > pos_size_idx_0) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pos_size_idx_0, &c_emlrtBCI,
                                      &c_st);
      }
      pos_data[b_i] = a[0];
      pos_data[b_i + pos_size_idx_0] = a[1];
      pos_data[b_i + pos_size_idx_0 * 2] = a[2];
    }
    emlrtMEXProfilingStatement(13, isMexOutdated);
    emlrtMEXProfilingStatement(15, isMexOutdated);
    emlrtMEXProfilingStatement(16, isMexOutdated);
    trackIDs_size_idx_1 = varargout_3.size[0];
    b_loop_ub = varargout_3.size[0];
    memset(&trackIDs_data[0], 0, (uint32_T)b_loop_ub * sizeof(uint32_T));
    emlrtMEXProfilingStatement(17, isMexOutdated);
    i = varargout_3.size[0];
    for (b_i = 0; b_i < i; b_i++) {
      emlrtMEXProfilingStatement(18, isMexOutdated);
      if (b_i + 1 > varargout_3.size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, varargout_3.size[0],
                                      &e_emlrtBCI, &st);
      }
      if (b_i + 1 > trackIDs_size_idx_1) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, trackIDs_size_idx_1,
                                      &f_emlrtBCI, &st);
      }
      trackIDs_data[b_i] = varargout_3.data[b_i].TrackID;
      emlrtMEXProfilingStatement(19, isMexOutdated);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    emlrtMEXProfilingStatement(20, isMexOutdated);
    emlrtMEXProfilingStatement(21, isMexOutdated);
    b_st.site = &kpb_emlrtRSI;
    memcpy(&x_data[0], &pos_data[0], (uint32_T)pos_size_idx_0 * sizeof(real_T));
    for (i = 0; i < pos_size_idx_0; i++) {
      probDetection_data[i] = pos_data[i + pos_size_idx_0];
      z_data[i] = pos_data[i + pos_size_idx_0 * 2];
    }
    c_st.site = &npb_emlrtRSI;
    b_loop_ub = b_hypot(&c_st, x_data, varargout_3.size[0], probDetection_data,
                        varargout_3.size[0], hypotxy_data);
    c_st.site = &opb_emlrtRSI;
    pos_size_idx_0 = b_hypot(&c_st, hypotxy_data, b_loop_ub, z_data,
                             varargout_3.size[0], r_data);
    c_st.site = &ppb_emlrtRSI;
    b_atan2(&c_st, z_data, varargout_3.size[0], hypotxy_data, b_loop_ub,
            iqb_emlrtRSI.data);
    c_st.site = &qpb_emlrtRSI;
    b_atan2(&c_st, probDetection_data, varargout_3.size[0], x_data,
            varargout_3.size[0], iqb_emlrtRSI.data);
    emlrtMEXProfilingStatement(22, isMexOutdated);
    probDetection_size = varargout_3.size[0];
    b_loop_ub = varargout_3.size[0];
    for (i = 0; i < b_loop_ub; i++) {
      probDetection_data[i] = 0.9;
    }
    emlrtMEXProfilingStatement(23, isMexOutdated);
    b_loop_ub = pos_size_idx_0 - 1;
    for (b_i = 0; b_i <= b_loop_ub; b_i++) {
      if (r_data[b_i] > 40.0) {
        if (b_i > varargout_3.size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, varargout_3.size[0] - 1,
                                        &g_emlrtBCI, &st);
        }
        probDetection_data[b_i] = 0.4;
      }
    }
    emlrtMEXProfilingStatement(24, isMexOutdated);
    for (b_i = 0; b_i <= b_loop_ub; b_i++) {
      if (r_data[b_i] > 75.0) {
        if (b_i > probDetection_size - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, probDetection_size - 1,
                                        &h_emlrtBCI, &st);
        }
        probDetection_data[b_i] = 0.99;
      }
    }
    emlrtMEXProfilingStatement(25, isMexOutdated);
    b_st.site = &lpb_emlrtRSI;
    for (i = 0; i < trackIDs_size_idx_1; i++) {
      x_data[i] = trackIDs_data[i];
    }
    varargin_3_size[0] = varargout_3.size[0];
    varargin_3_size[1] = 2;
    for (i = 0; i < trackIDs_size_idx_1; i++) {
      varargin_3_data[i] = x_data[i];
      varargin_3_data[i + trackIDs_size_idx_1] = probDetection_data[i];
    }
  }
  emlrtMEXProfilingStatement(26, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  b_iv[0] = loop_ub;
  b_iv[1] = 2;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &varargin_3_size[0], 2, &emlrtECI,
                                (emlrtCTX)sp);
  for (i = 0; i < 2; i++) {
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      detectableTracksInput[b_loop_ub + 30 * i] =
          varargin_3_data[b_loop_ub + varargin_3_size[0] * i];
    }
  }
  /*   */
  /*          dt = 0.5; */
  /*          H = 21; */
  /*          t = time+dt:dt:time+dt*(H-1); */
  /*          obspredict = cell(1,length(t)); */
  /*          if numel(confirmedTracks)~=0 */
  /*              for i=1:length(t) */
  /*                 obspredict{i} =
   * predictTracksToTime(tracker,'confirmed',t(i),'WithCovariance',true).StateCovariance;
   */
  /*              end */
  /*          end */
  /*  Get model probabilities */
  emlrtMEXProfilingStatement(23, isMexOutdated);
  modelProbs_size[0] = 2;
  modelProbs_size[1] = confirmedTracks_size[0];
  loop_ub = confirmedTracks_size[0] << 1;
  if (loop_ub - 1 >= 0) {
    memset(&modelProbs_data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
  }
  /*  if isLocked(tracker) */
  /*      for k = 1:numel(confirmedTracks) */
  /*          c1 =
   * getTrackFilterProperties(tracker,confirmedTracks(k).TrackID,'ModelProbabilities');
   */
  /*          probs = c1{1}; */
  /*          modelProbs(1,k) = probs(1); */
  /*          modelProbs(2,k) = probs(2); */
  /*      end */
  /*  end */
  /*       else */
  /*           confirmedTracks = []; */
  /*           modelProbs = []; */
  /*       end */
  st.site = &g_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &ptCloud);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emxFreeStruct_pointCloud(sp, &ptCloud);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void mexLidarTracker_free(const emlrtStack *sp)
{
  int32_T i;
  if (!tracker.matlabCodegenIsDeleted) {
    tracker.matlabCodegenIsDeleted = true;
    if (tracker.isInitialized == 1) {
      tracker.isInitialized = 2;
      if (tracker.isSetupComplete) {
        tracker.pNumLiveTracks = 0;
        memset(&tracker.pTrackIDs[0], 0, 30U * sizeof(uint32_T));
        for (i = 0; i < 30; i++) {
          tracker.pConfirmedTracks[i] = false;
        }
        tracker.pLastTrackID = 0U;
        tracker.pLastTimeStamp = -2.2204460492503131E-16;
      }
    }
  }
  emxFreeStruct_trackerJPDA(sp, &tracker);
}

void mexLidarTracker_init(const emlrtStack *sp)
{
  emxInitStruct_trackerJPDA(sp, &tracker, &qd_emlrtRTEI);
  tracker_not_empty = false;
  detectorModel_not_empty = false;
  tracker.matlabCodegenIsDeleted = true;
}

/* End of code generation (mexLidarTracker.c) */
