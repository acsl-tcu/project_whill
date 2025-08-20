//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mexLidarTracker_initialize.cpp
//
//  Code generation for function 'mexLidarTracker_initialize'
//


// Include files
#include "mexLidarTracker_initialize.h"
#include "_coder_mexLidarTracker_mex.h"
#include "mexLidarTracker.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void mexLidarTracker_once();

// Function Definitions
static void mexLidarTracker_once()
{
  static const int32_T d_lineInfo[33] = { 110, 111, 113, 114, 115, 116, 117, 118,
    119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133,
    137, 138, 139, 140, 141, 142, 143, 144, 145, 167 };

  static const int32_T f_lineInfo[33] = { 75, 76, 83, 84, 85, 108, 109, 119, 120,
    121, 122, 129, 134, 135, 136, 137, 138, 140, 142, 143, 144, 145, 146, 147,
    148, 149, 150, 151, 152, 153, 154, 157, 158 };

  static const int32_T lineInfo[25] = { 4, 7, 14, 16, 20, 23, 24, 25, 26, 29, 32,
    34, 35, 36, 37, 42, 44, 45, 47, 52, 63, 65, 66, 82, 96 };

  static const int32_T c_lineInfo[22] = { 260, 261, 264, 265, 266, 267, 268, 269,
    270, 272, 273, 275, 276, 277, 278, 279, 280, 288, 289, 290, 291, 292 };

  static const int32_T b_lineInfo[10] = { 72, 74, 76, 78, 79, 80, 81, 82, 83, 84
  };

  static const int32_T e_lineInfo[9] = { 4, 5, 6, 8, 9, 11, 14, 15, 16 };

  int32_T iv3[26];
  int32_T iv2[8];
  int32_T b_iv1[6];
  int32_T b_iv[2];
  int32_T i;
  mex_InitInfAndNan();
  c_helperCalcDetectability_compl =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m>helperCalcDetectability(codegen)";
  initializeEKF_complete_name =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/initializeEKF.m>initializeEKF(codegen)";
  c_assembleDetections_complete_n =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m>assembleDetections(codegen)";
  homogeneous_complete_name =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/homogeneous.m>homogeneous(codegen)";
  getBoundingBoxes_complete_name =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m>getBoundingBoxes(codegen)";
  removeGroundPlane_complete_name =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m>removeGroundPlane(codegen)";
  cropPointCloud2_complete_name =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m>cropPointCloud2(codegen)";
  c_HelperBoundingBoxDetector_ste =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m>HelperBoundingBoxDetector.stepImpl(codegen)";
  c_HelperBoundingBoxDetector_Hel =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m>HelperBoundingBoxDetector.HelperBoundingBoxDetecto"
    "r(codegen)";
  mexLidarTracker_complete_name =
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m>mexLidarTracker(codegen)";
  isMexOutdated = true;
  currentNumTracks_not_empty_init();
  b_detectableTracksInput_not_emp();
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  emlrtProfilerRegisterMEXFcn(mexLidarTracker_complete_name,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/mexLidarTracker.m",
    "mexLidarTracker", 25, &lineInfo[0], static_cast<boolean_T>(isMexOutdated));
  b_iv[0] = 64;
  b_iv[1] = 65;
  emlrtProfilerRegisterMEXFcn(c_HelperBoundingBoxDetector_Hel,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",
    "HelperBoundingBoxDetector>HelperBoundingBoxDetector.HelperBoundingBoxDetector",
    2, &b_iv[0], static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(c_HelperBoundingBoxDetector_ste,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",
    "HelperBoundingBoxDetector>HelperBoundingBoxDetector.stepImpl", 10,
    &b_lineInfo[0], static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(cropPointCloud2_complete_name,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",
    "HelperBoundingBoxDetector>cropPointCloud2", 22, &c_lineInfo[0],
    static_cast<boolean_T>(isMexOutdated));
  for (i = 0; i < 6; i++) {
    b_iv1[i] = i + 225;
  }

  emlrtProfilerRegisterMEXFcn(removeGroundPlane_complete_name,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",
    "HelperBoundingBoxDetector>removeGroundPlane", 6, &b_iv1[0],
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(getBoundingBoxes_complete_name,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",
    "HelperBoundingBoxDetector>getBoundingBoxes", 33, &d_lineInfo[0],
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(homogeneous_complete_name,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/homogeneous.m",
    "homogeneous", 9, &e_lineInfo[0], static_cast<boolean_T>(isMexOutdated));
  for (i = 0; i < 8; i++) {
    iv2[i] = i + 90;
  }

  emlrtProfilerRegisterMEXFcn(c_assembleDetections_complete_n,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",
    "HelperBoundingBoxDetector>assembleDetections", 8, &iv2[0],
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(initializeEKF_complete_name,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/initializeEKF.m",
    "initializeEKF", 33, &f_lineInfo[0], static_cast<boolean_T>(isMexOutdated));
  for (i = 0; i < 26; i++) {
    iv3[i] = i + 13;
  }

  emlrtProfilerRegisterMEXFcn(c_helperCalcDetectability_compl,
    "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/helperCalcDetectability.m",
    "helperCalcDetectability", 26, &iv3[0], static_cast<boolean_T>(isMexOutdated));
  mexLidarTracker_init();
}

void mexLidarTracker_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "sensor_fusion_and_tracking", 2);
  emlrtLicenseCheckR2012b(&st, "image_toolbox", 2);
  emlrtLicenseCheckR2012b(&st, "video_and_image_blockset", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    mexLidarTracker_once();
  }
}

// End of code generation (mexLidarTracker_initialize.cpp)
