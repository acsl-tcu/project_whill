//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mexLidarTracker.cpp
//
//  Code generation for function 'mexLidarTracker'
//


// Include files
#include "mexLidarTracker.h"
#include "HelperBoundingBoxDetector.h"
#include "atan2.h"
#include "hypot.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "objectDetection.h"
#include "pointCloud.h"
#include "rt_nonfinite.h"
#include "trackerJPDA.h"
#include "coder_array.h"
#include <string.h>

// Variable Definitions
static HelperBoundingBoxDetector detectorModel;
static boolean_T detectorModel_not_empty;
static coder::trackerJPDA tracker;
static boolean_T tracker_not_empty;
static real_T detectableTracksInput[60];
static boolean_T detectableTracksInput_not_empty;
static real_T currentNumTracks;
static boolean_T currentNumTracks_not_empty;
static emlrtRSInfo emlrtRSI = { 14,    // lineNo
  "mexLidarTracker",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m"// pathName 
};

static emlrtRSInfo b_emlrtRSI = { 32,  // lineNo
  "mexLidarTracker",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 47,  // lineNo
  "mexLidarTracker",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 52,  // lineNo
  "mexLidarTracker",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 63,  // lineNo
  "mexLidarTracker",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 66,  // lineNo
  "mexLidarTracker",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 96,  // lineNo
  "mexLidarTracker",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m"// pathName 
};

static emlrtRSInfo ur_emlrtRSI = { 1,  // lineNo
  "SystemCore/parenReference",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

static emlrtRSInfo okb_emlrtRSI = { 24,// lineNo
  "helperCalcDetectability",           // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m"// pathName 
};

static emlrtRSInfo pkb_emlrtRSI = { 33,// lineNo
  "helperCalcDetectability",           // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m"// pathName 
};

static emlrtRSInfo qkb_emlrtRSI = { 37,// lineNo
  "helperCalcDetectability",           // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m"// pathName 
};

static emlrtRSInfo rkb_emlrtRSI = { 43,// lineNo
  "getTrackPositions",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/getTrackPositions.m"// pathName 
};

static emlrtRSInfo skb_emlrtRSI = { 9, // lineNo
  "cart2sph",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/specfun/cart2sph.m"// pathName 
};

static emlrtRSInfo tkb_emlrtRSI = { 10,// lineNo
  "cart2sph",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/specfun/cart2sph.m"// pathName 
};

static emlrtRSInfo ukb_emlrtRSI = { 11,// lineNo
  "cart2sph",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/specfun/cart2sph.m"// pathName 
};

static emlrtRSInfo vkb_emlrtRSI = { 12,// lineNo
  "cart2sph",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/specfun/cart2sph.m"// pathName 
};

static emlrtRSInfo ykb_emlrtRSI = { 22,// lineNo
  "cat",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"// pathName
};

static emlrtBCInfo emlrtBCI = { -1,    // iFirst
  -1,                                  // iLast
  69,                                  // lineNo
  17,                                  // colNo
  "",                                  // aName
  "getTrackPosVel",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/getTrackPosVel.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  69,                                  // lineNo
  44,                                  // colNo
  "",                                  // aName
  "getTrackPosVel",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/getTrackPosVel.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo emlrtECI = { -1,    // nDims
  66,                                  // lineNo
  9,                                   // colNo
  "mexLidarTracker",                   // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m"// pName 
};

static emlrtBCInfo c_emlrtBCI = { 1,   // iFirst
  30,                                  // iLast
  66,                                  // lineNo
  33,                                  // colNo
  "detectableTracksInput",             // aName
  "mexLidarTracker",                   // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI = { 1,   // iFirst
  30,                                  // iLast
  63,                                  // lineNo
  89,                                  // colNo
  "detectableTracksInput",             // aName
  "mexLidarTracker",                   // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  30,                                  // lineNo
  23,                                  // colNo
  "tracks",                            // aName
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  30,                                  // lineNo
  9,                                   // colNo
  "trackIDs",                          // aName
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo g_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  35,                                  // lineNo
  1,                                   // colNo
  "probDetection",                     // aName
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  1,                                   // colNo
  "probDetection",                     // aName
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo nd_emlrtRTEI = { 43,// lineNo
  17,                                  // colNo
  "getTrackPositions",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/getTrackPositions.m"// pName 
};

static emlrtRTEInfo od_emlrtRTEI = { 28,// lineNo
  5,                                   // colNo
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m"// pName 
};

static emlrtRTEInfo pd_emlrtRTEI = { 33,// lineNo
  20,                                  // colNo
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m"// pName 
};

static emlrtRTEInfo qd_emlrtRTEI = { 33,// lineNo
  29,                                  // colNo
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m"// pName 
};

static emlrtRTEInfo rd_emlrtRTEI = { 33,// lineNo
  38,                                  // colNo
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m"// pName 
};

static emlrtRTEInfo sd_emlrtRTEI = { 34,// lineNo
  1,                                   // colNo
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m"// pName 
};

static emlrtRTEInfo td_emlrtRTEI = { 37,// lineNo
  26,                                  // colNo
  "helperCalcDetectability",           // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m"// pName 
};

static emlrtRTEInfo ud_emlrtRTEI = { 66,// lineNo
  55,                                  // colNo
  "mexLidarTracker",                   // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m"// pName 
};

// Function Definitions
void b_detectableTracksInput_not_emp()
{
  detectableTracksInput_not_empty = false;
}

void currentNumTracks_not_empty_init()
{
  currentNumTracks_not_empty = false;
}

void mexLidarTracker(const emlrtStack *sp, const coder::array<real32_T, 2U>
                     &ptCloudLocations, real_T b_time, const struct0_T *Plant,
                     const real_T wall[6], real_T axis, real_T SP, coder::array<
                     coder::objectDetection, 2U> &detections, coder::array<
                     real_T, 1U> &obstacleIndices, coder::array<real_T, 1U>
                     &groundIndices, coder::array<real_T, 1U> &croppedIndices,
                     struct1_T confirmedTracks_data[], int32_T
                     confirmedTracks_size[1], real_T modelProbs_data[], int32_T
                     modelProbs_size[2], real32_T *numClusters, coder::array<
                     uint32_T, 1U> &labels)
{
  static const int8_T b_a[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1 };

  HelperBoundingBoxDetector *obj;
  coder::b_pointCloud ptCloud;
  coder::trackerJPDA *b_obj;
  coder::array<struct1_T, 2U> varargout_3;
  coder::array<real_T, 2U> pos;
  coder::array<real_T, 2U> r;
  coder::array<real_T, 1U> b_pos;
  coder::array<real_T, 1U> b_r;
  coder::array<real_T, 1U> hlb_emlrtRSI;
  coder::array<real_T, 1U> hypotxy;
  coder::array<real_T, 1U> ilb_emlrtRSI;
  coder::array<real_T, 1U> probDetection;
  coder::array<uint32_T, 2U> trackIDs;
  coder::bounded_array<struct1_T, 30U, 1U> varargout_2;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T varargin_3_data[60];
  real_T a[3];
  real_T d;
  int32_T varargin_3_size[2];
  int32_T i;
  int32_T loop_ub;
  emlrtProfilerSentinel b_profilerSentinel;
  emlrtProfilerSentinel profilerSentinel;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emlrtMEXProfilingFunctionEntryCPP(mexLidarTracker_complete_name,
    static_cast<boolean_T>(isMexOutdated), &profilerSentinel);
  ptCloud.matlabCodegenIsDeleted = true;

  // ,obspredict
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  if ((!detectorModel_not_empty) || (!tracker_not_empty) ||
      (!detectableTracksInput_not_empty) || (!currentNumTracks_not_empty)) {
    //  Use the same starting seed as MATLAB to reproduce results in SIL
    //  simulation.
    //      rng(2018);
    //  A bounding box detector model.
    //               % min-max
    //                 % min-max
    //                 % min-max
    //    % minimum Euclidian distance
    //      % minimum points per cluster
    //        % measurement noise in detection report.
    emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));
    st.site = &emlrtRSI;
    detectorModel.init();
    detectorModel_not_empty = true;

    //  maximum distance of ground points from ground plane
    // 30*[1 inf]; % Assignment threshold;
    // [3 10];    % Confirmation threshold for history logic
    // [8 10];     % Deletion threshold for history logic
    //  False-alarm rate per unit volume
    //      filterInitFcn = @helperInitIMMFilter;
    emlrtMEXProfilingStatement(11, static_cast<boolean_T>(isMexOutdated));
    st.site = &b_emlrtRSI;
    tracker.init(&st);
    tracker_not_empty = true;
    emlrtMEXProfilingStatement(16, static_cast<boolean_T>(isMexOutdated));
    memset(&detectableTracksInput[0], 0, 60U * sizeof(real_T));
    detectableTracksInput_not_empty = true;
    emlrtMEXProfilingStatement(17, static_cast<boolean_T>(isMexOutdated));
    currentNumTracks = 0.0;
    currentNumTracks_not_empty = true;
    emlrtMEXProfilingStatement(18, static_cast<boolean_T>(isMexOutdated));
  }

  emlrtMEXProfilingStatement(19, static_cast<boolean_T>(isMexOutdated));
  st.site = &c_emlrtRSI;
  ptCloud.init(&st, ptCloudLocations);

  //  Detector model
  emlrtMEXProfilingStatement(20, static_cast<boolean_T>(isMexOutdated));
  st.site = &d_emlrtRSI;
  obj = &detectorModel;
  b_st.site = &l_emlrtRSI;
  obj->step(&b_st, &ptCloud, b_time, Plant->X, Plant->Y, Plant->yaw, wall, axis,
            SP, detections, obstacleIndices, groundIndices, croppedIndices,
            numClusters, labels);

  //  loading dammy file
  //       if isempty(detections) && time < 8e-03
  //                  detections = cell(1,1);
  //                  detections{1} = objectDetection(time,cast([100000;100000;100000],'double'),... 
  //                  'MeasurementNoise',double([0.00100000000000000,0,0;0,0.00100000000000000,0;0,0,0.00100000000000000]),'ObjectAttributes',struct,... 
  //                  'MeasurementParameters',{});
  //       end
  //  Call tracker
  emlrtMEXProfilingStatement(21, static_cast<boolean_T>(isMexOutdated));
  if (1.0 > currentNumTracks) {
    loop_ub = 0;
  } else {
    i = static_cast<int32_T>(currentNumTracks);
    if ((static_cast<int32_T>(currentNumTracks) < 1) || (static_cast<int32_T>
         (currentNumTracks) > 30)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 30, &d_emlrtBCI, sp);
    }

    loop_ub = static_cast<int32_T>(currentNumTracks);
  }

  st.site = &e_emlrtRSI;
  b_obj = &tracker;
  varargin_3_size[0] = loop_ub;
  varargin_3_size[1] = 2;
  if (0 <= loop_ub - 1) {
    memcpy(&varargin_3_data[0], &detectableTracksInput[0], loop_ub * sizeof
           (real_T));
  }

  for (i = 0; i < loop_ub; i++) {
    varargin_3_data[i + loop_ub] = detectableTracksInput[i + 30];
  }

  b_st.site = &ur_emlrtRSI;
  b_obj->step(&b_st, detections, b_time, varargin_3_data, varargin_3_size,
              confirmedTracks_data, confirmedTracks_size, varargout_2.data,
              varargout_2.size, varargout_3);

  //  Update the detectability input
  emlrtMEXProfilingStatement(22, static_cast<boolean_T>(isMexOutdated));
  currentNumTracks = varargout_3.size(0);
  emlrtMEXProfilingStatement(23, static_cast<boolean_T>(isMexOutdated));
  if (1.0 > currentNumTracks) {
    i = 0;
  } else {
    i = static_cast<int32_T>(currentNumTracks);
    if ((static_cast<int32_T>(currentNumTracks) < 1) || (static_cast<int32_T>
         (currentNumTracks) > 30)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 30, &c_emlrtBCI, sp);
    }

    i = static_cast<int32_T>(currentNumTracks);
  }

  st.site = &f_emlrtRSI;
  emlrtMEXProfilingFunctionEntryCPP(c_helperCalcDetectability_compl,
    static_cast<boolean_T>(isMexOutdated), &b_profilerSentinel);

  //  This is a helper function to calculate the detection probability of
  //  tracks for the lidar tracking example. It may be removed in a future
  //  release.
  //  Copyright 2019 The MathWorks, Inc.
  //  The bounding box detector has low probability of segmenting point clouds
  //  into bounding boxes are distances greater than 40 meters. This function
  //  models this effect using a state-dependent probability of detection for
  //  each tracker. After a maximum range, the Pd is set to a high value to
  //  enable deletion of track at a faster rate.
  emlrtMEXProfilingStatement(1, static_cast<boolean_T>(isMexOutdated));
  if (varargout_3.size(0) == 0) {
    emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
    r.set_size(&ud_emlrtRTEI, &st, 0, 2);
    emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
  } else {
    int32_T b_i;
    int32_T i1;
    emlrtMEXProfilingStatement(7, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(12, static_cast<boolean_T>(isMexOutdated));
    b_st.site = &okb_emlrtRSI;
    c_st.site = &rkb_emlrtRSI;
    pos.set_size(&nd_emlrtRTEI, &c_st, varargout_3.size(0), 3);
    i1 = varargout_3.size(0);
    for (b_i = 0; b_i < i1; b_i++) {
      loop_ub = b_i + 1;
      if ((loop_ub < 1) || (loop_ub > varargout_3.size(0))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, varargout_3.size(0),
          &b_emlrtBCI, &c_st);
      }

      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        d = 0.0;
        for (int32_T i2 = 0; i2 < 6; i2++) {
          d += static_cast<real_T>(b_a[loop_ub + 3 * i2]) * varargout_3[b_i].
            State[i2];
        }

        a[loop_ub] = d;
      }

      if ((b_i + 1 < 1) || (b_i + 1 > pos.size(0))) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pos.size(0), &emlrtBCI, &c_st);
      }

      pos[b_i] = a[0];
      pos[b_i + pos.size(0)] = a[1];
      pos[b_i + pos.size(0) * 2] = a[2];
    }

    emlrtMEXProfilingStatement(13, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(15, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(16, static_cast<boolean_T>(isMexOutdated));
    trackIDs.set_size(&od_emlrtRTEI, &st, 1, varargout_3.size(0));
    loop_ub = varargout_3.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      trackIDs[i1] = 0U;
    }

    emlrtMEXProfilingStatement(17, static_cast<boolean_T>(isMexOutdated));
    i1 = varargout_3.size(0);
    for (b_i = 0; b_i < i1; b_i++) {
      emlrtMEXProfilingStatement(18, static_cast<boolean_T>(isMexOutdated));
      if ((b_i + 1 < 1) || (b_i + 1 > varargout_3.size(0))) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, varargout_3.size(0),
          &e_emlrtBCI, &st);
      }

      if ((b_i + 1 < 1) || (b_i + 1 > trackIDs.size(1))) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, trackIDs.size(1), &f_emlrtBCI,
          &st);
      }

      trackIDs[b_i] = varargout_3[b_i].TrackID;
      emlrtMEXProfilingStatement(19, static_cast<boolean_T>(isMexOutdated));
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtMEXProfilingStatement(20, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(21, static_cast<boolean_T>(isMexOutdated));
    b_st.site = &pkb_emlrtRSI;
    loop_ub = pos.size(0);
    probDetection.set_size(&pd_emlrtRTEI, &b_st, pos.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      probDetection[i1] = pos[i1];
    }

    loop_ub = pos.size(0);
    b_pos.set_size(&qd_emlrtRTEI, &b_st, pos.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_pos[i1] = pos[i1 + pos.size(0)];
    }

    c_st.site = &skb_emlrtRSI;
    coder::b_hypot(&c_st, probDetection, b_pos, hypotxy);
    loop_ub = pos.size(0);
    probDetection.set_size(&rd_emlrtRTEI, &b_st, pos.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      probDetection[i1] = pos[i1 + pos.size(0) * 2];
    }

    c_st.site = &tkb_emlrtRSI;
    coder::b_hypot(&c_st, hypotxy, probDetection, b_r);
    loop_ub = pos.size(0);
    probDetection.set_size(&rd_emlrtRTEI, &b_st, pos.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      probDetection[i1] = pos[i1 + pos.size(0) * 2];
    }

    c_st.site = &ukb_emlrtRSI;
    coder::b_atan2(&c_st, probDetection, hypotxy, hlb_emlrtRSI);
    loop_ub = pos.size(0);
    probDetection.set_size(&qd_emlrtRTEI, &b_st, pos.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      probDetection[i1] = pos[i1 + pos.size(0)];
    }

    loop_ub = pos.size(0);
    b_pos.set_size(&pd_emlrtRTEI, &b_st, pos.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_pos[i1] = pos[i1];
    }

    c_st.site = &vkb_emlrtRSI;
    coder::b_atan2(&c_st, probDetection, b_pos, ilb_emlrtRSI);
    emlrtMEXProfilingStatement(22, static_cast<boolean_T>(isMexOutdated));
    probDetection.set_size(&sd_emlrtRTEI, &st, varargout_3.size(0));
    loop_ub = varargout_3.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      probDetection[i1] = 0.9;
    }

    emlrtMEXProfilingStatement(23, static_cast<boolean_T>(isMexOutdated));
    loop_ub = b_r.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_r[b_i] > 40.0) {
        if ((b_i + 1 < 1) || (b_i + 1 > probDetection.size(0))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, probDetection.size(0),
            &g_emlrtBCI, &st);
        }

        probDetection[b_i] = 0.4;
      }
    }

    emlrtMEXProfilingStatement(24, static_cast<boolean_T>(isMexOutdated));
    loop_ub = b_r.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_r[b_i] > 75.0) {
        if ((b_i + 1 < 1) || (b_i + 1 > probDetection.size(0))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, probDetection.size(0),
            &h_emlrtBCI, &st);
        }

        probDetection[b_i] = 0.99;
      }
    }

    emlrtMEXProfilingStatement(25, static_cast<boolean_T>(isMexOutdated));
    b_st.site = &qkb_emlrtRSI;
    hypotxy.set_size(&td_emlrtRTEI, &b_st, trackIDs.size(1));
    loop_ub = trackIDs.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      hypotxy[i1] = trackIDs[i1];
    }

    c_st.site = &ykb_emlrtRSI;
    d_st.site = &beb_emlrtRSI;
    if (probDetection.size(0) != hypotxy.size(0)) {
      emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    r.set_size(&ud_emlrtRTEI, &c_st, hypotxy.size(0), 2);
    loop_ub = hypotxy.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r[i1] = hypotxy[i1];
    }

    loop_ub = probDetection.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r[i1 + r.size(0)] = probDetection[i1];
    }
  }

  emlrtMEXProfilingStatement(26, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingFunctionExitCPP(&b_profilerSentinel);
  varargin_3_size[0] = i;
  varargin_3_size[1] = 2;
  emlrtSubAssignSizeCheckR2012b(&varargin_3_size[0], 2, r.size(), 2, &emlrtECI,
    sp);
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    detectableTracksInput[i] = r[i];
  }

  for (i = 0; i < loop_ub; i++) {
    detectableTracksInput[i + 30] = r[i + r.size(0)];
  }

  //
  //          dt = 0.5;
  //          H = 21;
  //          t = time+dt:dt:time+dt*(H-1);
  //          obspredict = cell(1,length(t));
  //          if numel(confirmedTracks)~=0
  //              for i=1:length(t)
  //                 obspredict{i} = predictTracksToTime(tracker,'confirmed',t(i),'WithCovariance',true).StateCovariance; 
  //              end
  //          end
  //  Get model probabilities
  emlrtMEXProfilingStatement(24, static_cast<boolean_T>(isMexOutdated));
  modelProbs_size[0] = 2;
  modelProbs_size[1] = confirmedTracks_size[0];
  loop_ub = confirmedTracks_size[0] << 1;
  if (0 <= loop_ub - 1) {
    memset(&modelProbs_data[0], 0, loop_ub * sizeof(real_T));
  }

  //  if isLocked(tracker)
  //      for k = 1:numel(confirmedTracks)
  //          c1 = getTrackFilterProperties(tracker,confirmedTracks(k).TrackID,'ModelProbabilities'); 
  //          probs = c1{1};
  //          modelProbs(1,k) = probs(1);
  //          modelProbs(2,k) = probs(2);
  //      end
  //  end
  //       else
  //           confirmedTracks = [];
  //           modelProbs = [];
  //       end
  st.site = &g_emlrtRSI;
  ptCloud.matlabCodegenDestructor();
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void mexLidarTracker_free()
{
  tracker.matlabCodegenDestructor();
}

void mexLidarTracker_init()
{
  tracker_not_empty = false;
  detectorModel_not_empty = false;
  tracker.matlabCodegenIsDeleted = true;
}

// End of code generation (mexLidarTracker.cpp)
