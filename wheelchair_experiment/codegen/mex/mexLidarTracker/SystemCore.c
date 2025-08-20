/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.c
 *
 * Code generation for function 'SystemCore'
 *
 */

/* Include files */
#include "SystemCore.h"
#include "ExtendedKalmanFilter.h"
#include "HelperBoundingBoxDetector.h"
#include "JPDATracker.h"
#include "ObjectTrack.h"
#include "affine3d.h"
#include "find.h"
#include "handle.h"
#include "initializeEKF.h"
#include "isSymmetricPositiveSemiDefinite.h"
#include "jpdaEvents.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_internal_types.h"
#include "mexLidarTracker_types.h"
#include "objectDetection.h"
#include "pctransform.h"
#include "pointCloud.h"
#include "rigid3dImpl.h"
#include "rt_nonfinite.h"
#include "trackingEKF.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = {
    1,               /* lineNo */
    "System/System", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/System.p" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    1,                       /* lineNo */
    "SystemProp/SystemProp", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemProp.p" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    1,                       /* lineNo */
    "SystemCore/SystemCore", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    1,                                                 /* lineNo */
    "AbstractContainsFilters/AbstractContainsFilters", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/AbstractContainsFilters.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    67,                                   /* lineNo */
    "HelperBoundingBoxDetector/stepImpl", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    74,                                   /* lineNo */
    "HelperBoundingBoxDetector/stepImpl", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    75,                                   /* lineNo */
    "HelperBoundingBoxDetector/stepImpl", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    63,                                   /* lineNo */
    "HelperBoundingBoxDetector/stepImpl", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    267,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    280,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    281,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    283,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    263,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    264,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    282,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    49,                /* lineNo */
    "rigid3d/rigid3d", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/+coder/"
    "rigid3d.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    50,                /* lineNo */
    "rigid3d/rigid3d", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/+coder/"
    "rigid3d.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    86,                        /* lineNo */
    "rigid3dImpl/rigid3dImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    87,                        /* lineNo */
    "rigid3dImpl/rigid3dImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    98,                        /* lineNo */
    "rigid3dImpl/rigid3dImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo hc_emlrtRSI = {
    102,                       /* lineNo */
    "rigid3dImpl/rigid3dImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo dl_emlrtRSI = {
    84,                   /* lineNo */
    "assembleDetections", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo el_emlrtRSI = {
    171,                               /* lineNo */
    "objectDetection/objectDetection", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m" /* pathName */
};

static emlrtRSInfo fl_emlrtRSI = {
    288,                             /* lineNo */
    "objectDetection/setProperties", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m" /* pathName */
};

static emlrtRSInfo gl_emlrtRSI = {
    289,                             /* lineNo */
    "objectDetection/setProperties", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m" /* pathName */
};

static emlrtRSInfo hl_emlrtRSI = {
    290,                             /* lineNo */
    "objectDetection/setProperties", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m" /* pathName */
};

static emlrtRSInfo il_emlrtRSI = {
    188,                               /* lineNo */
    "objectDetection/set.Measurement", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m" /* pathName */
};

static emlrtRSInfo kl_emlrtRSI = {
    230,                                    /* lineNo */
    "objectDetection/set.MeasurementNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m" /* pathName */
};

static emlrtRSInfo ll_emlrtRSI = {
    244,                                    /* lineNo */
    "objectDetection/set.MeasurementNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m" /* pathName */
};

static emlrtRSInfo op_emlrtRSI = {
    1,                               /* lineNo */
    "SystemCore/validateProperties", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pathName */
};

static emlrtRSInfo rp_emlrtRSI = {
    1152,                    /* lineNo */
    "JPDATracker/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "JPDATracker.m" /* pathName */
};

static emlrtRSInfo sp_emlrtRSI = {
    1155,                    /* lineNo */
    "JPDATracker/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "JPDATracker.m" /* pathName */
};

static emlrtRSInfo tp_emlrtRSI = {
    1160,                    /* lineNo */
    "JPDATracker/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "JPDATracker.m" /* pathName */
};

static emlrtRSInfo up_emlrtRSI = {
    1164,                    /* lineNo */
    "JPDATracker/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "JPDATracker.m" /* pathName */
};

static emlrtRSInfo vp_emlrtRSI = {
    440,                      /* lineNo */
    "TrackManager/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo wp_emlrtRSI = {
    454,                      /* lineNo */
    "TrackManager/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo xp_emlrtRSI = {
    482,                      /* lineNo */
    "TrackManager/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo yp_emlrtRSI = {
    487,                      /* lineNo */
    "TrackManager/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo aq_emlrtRSI = {
    491,                      /* lineNo */
    "TrackManager/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo bq_emlrtRSI = {
    706,                                  /* lineNo */
    "TrackManager/setupDetectionManager", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo cq_emlrtRSI = {
    711,                                  /* lineNo */
    "TrackManager/setupDetectionManager", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo dq_emlrtRSI = {
    705,                                  /* lineNo */
    "TrackManager/setupDetectionManager", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo eq_emlrtRSI = {
    1158,                                  /* lineNo */
    "TrackManager/createDetectionManager", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo iq_emlrtRSI = {
    1241,                                      /* lineNo */
    "TrackManager/initializeDetectionManager", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo jq_emlrtRSI = {
    1244,                                      /* lineNo */
    "TrackManager/initializeDetectionManager", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo kq_emlrtRSI = {
    103,                                  /* lineNo */
    "MATLABDetectionManager/getDataType", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/MATLABDetectionManager.m" /* pathName */
};

static emlrtRSInfo lq_emlrtRSI = {
    56,                                 /* lineNo */
    "MATLABDetectionManager/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/MATLABDetectionManager.m" /* pathName */
};

static emlrtRSInfo mq_emlrtRSI = {
    90,                                          /* lineNo */
    "MATLABDetectionManager/detectionFromInput", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/MATLABDetectionManager.m" /* pathName */
};

static emlrtRSInfo gt_emlrtRSI = {
    1285,                             /* lineNo */
    "TrackManager/createSampleTrack", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo ht_emlrtRSI = {
    1284,                             /* lineNo */
    "TrackManager/createSampleTrack", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo it_emlrtRSI = {
    1127,                         /* lineNo */
    "TrackManager/allocateTrack", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo jt_emlrtRSI = {
    1132,                         /* lineNo */
    "TrackManager/allocateTrack", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo kt_emlrtRSI = {
    1080,                         /* lineNo */
    "TrackManager/allocateTrack", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo lt_emlrtRSI = {
    1087,                         /* lineNo */
    "TrackManager/allocateTrack", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo mt_emlrtRSI = {
    1135,                         /* lineNo */
    "TrackManager/allocateTrack", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo sv_emlrtRSI = {
    1215,                                     /* lineNo */
    "JPDATracker/validateEventGenerationFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "JPDATracker.m" /* pathName */
};

static emlrtRSInfo dy_emlrtRSI = {
    120,                                                 /* lineNo */
    "AssignmentCostCalculator/AssignmentCostCalculator", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo hy_emlrtRSI = {
    1229,                    /* lineNo */
    "JPDATracker/resetImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "JPDATracker.m" /* pathName */
};

static emlrtRSInfo iy_emlrtRSI = {
    1232,                    /* lineNo */
    "JPDATracker/resetImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "JPDATracker.m" /* pathName */
};

static emlrtRSInfo jy_emlrtRSI = {
    514,                      /* lineNo */
    "TrackManager/resetImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo ky_emlrtRSI = {
    520,                      /* lineNo */
    "TrackManager/resetImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/TrackManager.m" /* pathName */
};

static emlrtRSInfo ly_emlrtRSI = {
    1,                              /* lineNo */
    "SystemCore/checkTunableProps", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pathName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    126,               /* lineNo */
    9,                 /* colNo */
    "computeDimsData", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    99,                        /* lineNo */
    21,                        /* colNo */
    "rigid3dImpl/rigid3dImpl", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pName */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    84,                   /* lineNo */
    56,                   /* colNo */
    "bboxes",             /* aName */
    "assembleDetections", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    0       /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    1,                 /* nDims */
    271,               /* lineNo */
    14,                /* colNo */
    "cropPointCloud2", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    -1,                /* nDims */
    270,               /* lineNo */
    15,                /* colNo */
    "cropPointCloud2", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    -1,                /* nDims */
    269,               /* lineNo */
    15,                /* colNo */
    "cropPointCloud2", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    -1,                /* nDims */
    268,               /* lineNo */
    15,                /* colNo */
    "cropPointCloud2", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    1,                    /* lineNo */
    1,                    /* colNo */
    "SystemCore/release", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pName */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    84,                   /* lineNo */
    16,                   /* colNo */
    "detections",         /* aName */
    "assembleDetections", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    245,                                    /* lineNo */
    21,                                     /* colNo */
    "detections",                           /* aName */
    "objectDetection/set.MeasurementNoise", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    191,                               /* lineNo */
    13,                                /* colNo */
    "detections",                      /* aName */
    "objectDetection/set.Measurement", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m", /* pName */
    0                    /* checkKind */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    1,                  /* lineNo */
    1,                  /* colNo */
    "SystemCore/reset", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    181,                                          /* lineNo */
    17,                                           /* colNo */
    "AbstractDetectionManager/getDataTypeMATLAB", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AbstractDetectionManager.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    1221,                                     /* lineNo */
    40,                                       /* colNo */
    "JPDATracker/validateEventGenerationFcn", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "JPDATracker.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    157,                                                 /* lineNo */
    21,                                                  /* colNo */
    "AbstractDetectionManager/detectionFromInputMATLAB", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AbstractDetectionManager.m" /* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    266,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = {
    267,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI = {
    268,                         /* lineNo */
    15,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = {
    268,                         /* lineNo */
    45,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo de_emlrtRTEI = {
    269,                         /* lineNo */
    15,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = {
    269,                         /* lineNo */
    45,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = {
    270,                         /* lineNo */
    15,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = {
    270,                         /* lineNo */
    45,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo he_emlrtRTEI = {
    280,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = {
    281,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo je_emlrtRTEI = {
    74,                          /* lineNo */
    24,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = {
    63,                          /* lineNo */
    14,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo le_emlrtRTEI = {
    1,            /* lineNo */
    1,            /* colNo */
    "SystemCore", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pName */
};

static emlrtRTEInfo me_emlrtRTEI = {
    264,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = {
    268,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = {
    269,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = {
    270,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo mh_emlrtRTEI = {
    82,                       /* lineNo */
    46,                       /* colNo */
    "MATLABDetectionManager", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/MATLABDetectionManager.m" /* pName */
};

static emlrtRSInfo gqb_emlrtRSI = {
    271,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

/* Function Declarations */
static void SystemCore_setup(const emlrtStack *sp, trackerJPDA *obj,
                             const emxArray_objectDetection *varargin_1,
                             real_T varargin_2,
                             const int32_T varargin_3_size[2]);

/* Function Definitions */
static void SystemCore_setup(const emlrtStack *sp, trackerJPDA *obj,
                             const emxArray_objectDetection *varargin_1,
                             real_T varargin_2,
                             const int32_T varargin_3_size[2])
{
  static const int8_T b_iv[8] = {1, 30, 1, 1, 1, 1, 1, 1};
  static const int8_T b_iv1[8] = {0, 1, 1, 1, 1, 1, 1, 1};
  cell_wrap_3 b_varSizes[4];
  cell_wrap_3 varSizes[3];
  d_matlabshared_tracking_interna *b_tracks[30];
  d_matlabshared_tracking_interna *tracks[30];
  d_matlabshared_tracking_interna track;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_boolean_T *fje;
  emxArray_real_T *fjeprobs;
  emxArray_real_T *r;
  const objectDetection *varargin_1_data;
  objectDetection detection;
  trackHistoryLogic lobj_3;
  trackingEKF lobj_2[2];
  trackingEKF f;
  trackingEKF *filter;
  trackingEKF *iobj_0;
  real_T b_detection[9];
  real_T *r1;
  int32_T b_i;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  obj->isSetupComplete = false;
  if (obj->isInitialized != 0) {
    emlrtErrorWithMessageIdR2018a(
        sp, &qb_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
        "setup");
  }
  obj->isInitialized = 1;
  st.site = &np_emlrtRSI;
  varSizes[0].f1[0] = (uint32_T)varargin_1->size[0];
  varSizes[0].f1[1] = 1U;
  for (i = 0; i < 6; i++) {
    varSizes[0].f1[i + 2] = 1U;
  }
  for (i = 0; i < 8; i++) {
    varSizes[1].f1[i] = 1U;
  }
  varSizes[2].f1[0] = (uint32_T)varargin_3_size[0];
  varSizes[2].f1[1] = 2U;
  for (i = 0; i < 6; i++) {
    varSizes[2].f1[i + 2] = 1U;
  }
  obj->inputVarSize[0] = varSizes[0];
  obj->inputVarSize[1] = varSizes[1];
  obj->inputVarSize[2] = varSizes[2];
  st.site = &np_emlrtRSI;
  b_st.site = &op_emlrtRSI;
  st.site = &np_emlrtRSI;
  JPDATracker_validateInputsImpl(&st, varargin_2);
  st.site = &np_emlrtRSI;
  b_st.site = &rp_emlrtRSI;
  c_st.site = &vp_emlrtRSI;
  d_st.site = &dq_emlrtRSI;
  e_st.site = &eq_emlrtRSI;
  obj->_pobj3.isInitialized = 0;
  obj->cDetectionManager = &obj->_pobj3;
  d_st.site = &bq_emlrtRSI;
  e_st.site = &iq_emlrtRSI;
  f_st.site = &kq_emlrtRSI;
  if (varargin_1->size[0] == 0) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &pb_emlrtRTEI,
        "shared_tracking:internal:TrackManager:UndefinedSampleDetection",
        "shared_tracking:internal:TrackManager:UndefinedSampleDetection", 0);
  }
  e_st.site = &jq_emlrtRSI;
  b_SystemCore_setup(&e_st, obj->cDetectionManager, varargin_1);
  d_st.site = &cq_emlrtRSI;
  e_st.site = &mq_emlrtRSI;
  obj->pSampleDetection = varargin_1_data[0];
  obj->pLastTimeStamp = -2.2204460492503131E-16;
  c_st.site = &wp_emlrtRSI;
  initializeEKF(&c_st, obj->pSampleDetection.Measurement,
                obj->pSampleDetection.pMeasurementNoise, &f);
  c_st.site = &xp_emlrtRSI;
  iobj_0 = &lobj_2[0];
  detection = obj->pSampleDetection;
  d_st.site = &ht_emlrtRSI;
  e_st.site = &kt_emlrtRSI;
  for (i = 0; i < 50; i++) {
    lobj_3.pRecentHistory[i] = false;
  }
  e_st.site = &lt_emlrtRSI;
  filter = initializeEKF(&e_st, detection.Measurement,
                         detection.pMeasurementNoise, &(&iobj_0[0])[0]);
  memcpy(&b_detection[0], &detection.pMeasurementNoise[0], 9U * sizeof(real_T));
  e_st.site = &it_emlrtRSI;
  c_ExtendedKalmanFilter_set_Meas(&e_st, filter, b_detection);
  e_st.site = &jt_emlrtRSI;
  filter->pShouldWarn = false;
  e_st.site = &mt_emlrtRSI;
  track.BranchID = 1U;
  track.TrackID = 0U;
  track.Filter = filter;
  track.pDistanceFilter = trackingEKF_clone(filter, &(&iobj_0[0])[1]);
  track.UpdateTime = 0.0;
  track.Time = 0.0;
  track.ObjectClassID = detection.ObjectClassID;
  track.TrackLogic = &lobj_3;
  track.IsConfirmed = false;
  for (b_i = 0; b_i < 20; b_i++) {
    track.pUsedObjectAttributes[b_i] = false;
  }
  track.pUsedObjectAttributes[0] = true;
  d_st.site = &gt_emlrtRSI;
  ObjectTrack_nullify(&d_st, &track);
  c_st.site = &yp_emlrtRSI;
  tracks[0] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[0], &obj->_pobj1[0],
                               &obj->_pobj0[0]);
  c_st.site = &yp_emlrtRSI;
  tracks[1] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[1], &obj->_pobj1[1],
                               &obj->_pobj0[2]);
  c_st.site = &yp_emlrtRSI;
  tracks[2] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[2], &obj->_pobj1[2],
                               &obj->_pobj0[4]);
  c_st.site = &yp_emlrtRSI;
  tracks[3] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[3], &obj->_pobj1[3],
                               &obj->_pobj0[6]);
  c_st.site = &yp_emlrtRSI;
  tracks[4] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[4], &obj->_pobj1[4],
                               &obj->_pobj0[8]);
  c_st.site = &yp_emlrtRSI;
  tracks[5] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[5], &obj->_pobj1[5],
                               &obj->_pobj0[10]);
  c_st.site = &yp_emlrtRSI;
  tracks[6] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[6], &obj->_pobj1[6],
                               &obj->_pobj0[12]);
  c_st.site = &yp_emlrtRSI;
  tracks[7] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[7], &obj->_pobj1[7],
                               &obj->_pobj0[14]);
  c_st.site = &yp_emlrtRSI;
  tracks[8] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[8], &obj->_pobj1[8],
                               &obj->_pobj0[16]);
  c_st.site = &yp_emlrtRSI;
  tracks[9] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[9], &obj->_pobj1[9],
                               &obj->_pobj0[18]);
  c_st.site = &yp_emlrtRSI;
  tracks[10] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[10],
                                &obj->_pobj1[10], &obj->_pobj0[20]);
  c_st.site = &yp_emlrtRSI;
  tracks[11] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[11],
                                &obj->_pobj1[11], &obj->_pobj0[22]);
  c_st.site = &yp_emlrtRSI;
  tracks[12] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[12],
                                &obj->_pobj1[12], &obj->_pobj0[24]);
  c_st.site = &yp_emlrtRSI;
  tracks[13] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[13],
                                &obj->_pobj1[13], &obj->_pobj0[26]);
  c_st.site = &yp_emlrtRSI;
  tracks[14] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[14],
                                &obj->_pobj1[14], &obj->_pobj0[28]);
  c_st.site = &yp_emlrtRSI;
  tracks[15] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[15],
                                &obj->_pobj1[15], &obj->_pobj0[30]);
  c_st.site = &yp_emlrtRSI;
  tracks[16] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[16],
                                &obj->_pobj1[16], &obj->_pobj0[32]);
  c_st.site = &yp_emlrtRSI;
  tracks[17] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[17],
                                &obj->_pobj1[17], &obj->_pobj0[34]);
  c_st.site = &yp_emlrtRSI;
  tracks[18] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[18],
                                &obj->_pobj1[18], &obj->_pobj0[36]);
  c_st.site = &yp_emlrtRSI;
  tracks[19] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[19],
                                &obj->_pobj1[19], &obj->_pobj0[38]);
  c_st.site = &yp_emlrtRSI;
  tracks[20] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[20],
                                &obj->_pobj1[20], &obj->_pobj0[40]);
  c_st.site = &yp_emlrtRSI;
  tracks[21] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[21],
                                &obj->_pobj1[21], &obj->_pobj0[42]);
  c_st.site = &yp_emlrtRSI;
  tracks[22] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[22],
                                &obj->_pobj1[22], &obj->_pobj0[44]);
  c_st.site = &yp_emlrtRSI;
  tracks[23] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[23],
                                &obj->_pobj1[23], &obj->_pobj0[46]);
  c_st.site = &yp_emlrtRSI;
  tracks[24] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[24],
                                &obj->_pobj1[24], &obj->_pobj0[48]);
  c_st.site = &yp_emlrtRSI;
  tracks[25] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[25],
                                &obj->_pobj1[25], &obj->_pobj0[50]);
  c_st.site = &yp_emlrtRSI;
  tracks[26] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[26],
                                &obj->_pobj1[26], &obj->_pobj0[52]);
  c_st.site = &yp_emlrtRSI;
  tracks[27] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[27],
                                &obj->_pobj1[27], &obj->_pobj0[54]);
  c_st.site = &yp_emlrtRSI;
  tracks[28] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[28],
                                &obj->_pobj1[28], &obj->_pobj0[56]);
  c_st.site = &yp_emlrtRSI;
  tracks[29] = ObjectTrack_copy(&c_st, &track, &obj->_pobj2[29],
                                &obj->_pobj1[29], &obj->_pobj0[58]);
  for (i = 0; i < 30; i++) {
    b_tracks[i] = tracks[i];
  }
  for (i = 0; i < 30; i++) {
    tracks[i] = b_tracks[i];
  }
  for (i = 0; i < 30; i++) {
    obj->pTracksList[i] = tracks[i];
  }
  c_st.site = &aq_emlrtRSI;
  obj->pDistFilter =
      trackingEKF_clone(obj->pTracksList[0]->Filter, &obj->_pobj0[60]);
  obj->pNumLiveTracks = 0;
  for (i = 0; i < 20; i++) {
    obj->pUsedSensors[i] = 0U;
  }
  b_st.site = &sp_emlrtRSI;
  emxInit_real_T(&b_st, &r, 2, &le_emlrtRTEI, true);
  i = r->size[0] * r->size[1];
  r->size[0] = 5;
  r->size[1] = 5;
  emxEnsureCapacity_real_T(&b_st, r, i, &le_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < 25; i++) {
    r1[i] = 1.0;
  }
  emxInit_real_T(&b_st, &fjeprobs, 1, &le_emlrtRTEI, true);
  emxInit_boolean_T(&b_st, &fje, 3, &le_emlrtRTEI, true);
  c_st.site = &sv_emlrtRSI;
  jpdaEvents(&c_st, r, fje, fjeprobs);
  emxFree_real_T(&b_st, &r);
  if ((fje->size[1] != 5) || (fjeprobs->size[0] != fje->size[2])) {
    emlrtErrorWithMessageIdR2018a(&b_st, &rb_emlrtRTEI,
                                  "fusion:trackerJPDA:InvalidEventGenFcn",
                                  "fusion:trackerJPDA:InvalidEventGenFcn", 3, 4,
                                  18, "EventGenerationFcn");
  }
  emxFree_boolean_T(&b_st, &fje);
  emxFree_real_T(&b_st, &fjeprobs);
  for (b_i = 0; b_i < 30; b_i++) {
    obj->pTrackDetectionProbability[b_i] = 0.9;
  }
  b_st.site = &tp_emlrtRSI;
  c_st.site = &dy_emlrtRSI;
  d_st.site = &j_emlrtRSI;
  e_st.site = &s_emlrtRSI;
  d_st.site = &j_emlrtRSI;
  e_st.site = &t_emlrtRSI;
  obj->cCostCalculator.isInitialized = 0;
  c_st.site = &dy_emlrtRSI;
  d_st.site = &u_emlrtRSI;
  b_st.site = &up_emlrtRSI;
  b_i = obj->pNumLiveTracks;
  if (obj->cCostCalculator.isInitialized != 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &qb_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
        "setup");
  }
  obj->cCostCalculator.isInitialized = 1;
  c_st.site = &np_emlrtRSI;
  for (i = 0; i < 8; i++) {
    b_varSizes[0].f1[i] = (uint32_T)b_iv[i];
    b_varSizes[1].f1[i] = 1U;
    b_varSizes[2].f1[i] = 1U;
    b_varSizes[3].f1[i] = (uint32_T)b_iv1[i];
  }
  obj->cCostCalculator.inputVarSize[0] = b_varSizes[0];
  obj->cCostCalculator.inputVarSize[1] = b_varSizes[1];
  obj->cCostCalculator.inputVarSize[2] = b_varSizes[2];
  obj->cCostCalculator.inputVarSize[3] = b_varSizes[3];
  c_st.site = &np_emlrtRSI;
  d_st.site = &ey_emlrtRSI;
  e_st.site = &jc_emlrtRSI;
  if (b_i < 0) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:AssignmentCostCalculator:expectedNonnegative", 3, 4, 13,
        "numLiveTracks");
  }
  c_st.site = &np_emlrtRSI;
  d_st.site = &fy_emlrtRSI;
  e_st.site = &gy_emlrtRSI;
  obj->pClusterTypeDef.SensorIndex = 0U;
  obj->pClusterTypeDef.TimeStamp = 0.0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

real32_T SystemCore_step(const emlrtStack *sp, HelperBoundingBoxDetector *obj,
                         pointCloud *varargin_1, real_T varargin_2,
                         real_T varargin_3_X, real_T varargin_3_Y,
                         real_T varargin_3_yaw, const real_T varargin_4[6],
                         real_T varargin_5, real_T varargin_6,
                         emxArray_objectDetection *varargout_1,
                         emxArray_real_T *varargout_2,
                         emxArray_real_T *varargout_3,
                         emxArray_uint32_T *varargout_5)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_boolean_T *insideX;
  emxArray_boolean_T *insideY;
  emxArray_boolean_T *insideZ;
  emxArray_boolean_T *r;
  emxArray_int32_T *ii;
  emxArray_real32_T *locations;
  emxArray_real_T *detBBoxes;
  objectDetection *varargout_1_data;
  pointCloud pcSurvived;
  pointCloud ptCloud_obs;
  real_T T[16];
  real_T tform_AffineTform_T[16];
  real_T unusedExpr[16];
  real_T rot[9];
  real_T trans[3];
  real_T b_rot_tmp;
  real_T rot_tmp;
  real_T *varargout_2_data;
  int32_T emptyDimValue;
  int32_T i;
  int32_T i1;
  int32_T n;
  int32_T nx;
  int32_T *ii_data;
  real32_T f;
  real32_T varargout_4;
  real32_T *locations_data;
  boolean_T *insideX_data;
  boolean_T *insideY_data;
  boolean_T *insideZ_data;
  boolean_T *r1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud(sp, &pcSurvived, &ke_emlrtRTEI);
  emxInit_real_T(sp, &detBBoxes, 2, &le_emlrtRTEI, true);
  emxInitStruct_pointCloud(sp, &ptCloud_obs, &me_emlrtRTEI);
  emxInit_real32_T(sp, &locations, 2, &yd_emlrtRTEI);
  emxInit_boolean_T(sp, &insideX, 1, &ne_emlrtRTEI, true);
  emxInit_boolean_T(sp, &insideY, 1, &oe_emlrtRTEI, true);
  emxInit_boolean_T(sp, &insideZ, 1, &pe_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r, 1, &be_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &qe_emlrtRTEI);
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(
        sp, &m_emlrtRTEI, "MATLAB:system:methodCalledWhenReleasedCodegen",
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }
  if (obj->isInitialized != 1) {
    st.site = &l_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    if (obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &m_emlrtRTEI,
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
          "setup");
    }
    obj->isInitialized = 1;
  }
  st.site = &l_emlrtRSI;
  emlrtMEXProfilingFunctionEntry((char_T *)c_HelperBoundingBoxDetector_ste,
                                 isMexOutdated);
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, &pcSurvived,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  pcSurvived.matlabCodegenIsDeleted = true;
  /*  Crop point cloud */
  /*              [pcSurvived,survivedIndices,croppedIndices] =
   * cropPointCloud(currentPointCloud,obj.XLimits,obj.YLimits,obj.ZLimits,obj.EgoVehicleRadius);
   */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  b_st.site = &tb_emlrtRSI;
  emlrtMEXProfilingFunctionEntry((char_T *)cropPointCloud2_complete_name,
                                 isMexOutdated);
  emlrtHeapReferenceStackEnterFcnR2012b(&b_st);
  emlrtPushHeapReferenceStackR2021a(&b_st, true, &ptCloud_obs,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  ptCloud_obs.matlabCodegenIsDeleted = true;
  /*  This method selects the point cloud within limits and removes the */
  /*  ego vehicle point cloud using findNeighborsInRadius */
  /*  pcshow(ptCloudIn); */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  emlrtMEXProfilingStatement(2, isMexOutdated);
  emlrtMEXProfilingStatement(0, isMexOutdated);
  rot_tmp = muDoubleScalarSin(varargin_3_yaw);
  b_rot_tmp = muDoubleScalarCos(varargin_3_yaw);
  rot[0] = b_rot_tmp;
  rot[3] = rot_tmp;
  rot[6] = 0.0;
  rot[1] = -rot_tmp;
  rot[4] = b_rot_tmp;
  rot[7] = 0.0;
  rot[2] = 0.0;
  rot[5] = 0.0;
  rot[8] = 1.0;
  emlrtMEXProfilingStatement(3, isMexOutdated);
  if (varargin_5 == 1.0) {
    emlrtMEXProfilingStatement(4, isMexOutdated);
    trans[0] = 0.0;
    trans[1] = varargin_3_Y;
    trans[2] = 0.0;
    emlrtMEXProfilingStatement(9, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(5, isMexOutdated);
    if (varargin_5 == 2.0) {
      emlrtMEXProfilingStatement(6, isMexOutdated);
      trans[0] = varargin_3_X;
      trans[1] = 0.0;
      trans[2] = 0.0;
      emlrtMEXProfilingStatement(9, isMexOutdated);
    } else {
      emlrtMEXProfilingStatement(7, isMexOutdated);
      /*  axis == 3 */
      emlrtMEXProfilingStatement(8, isMexOutdated);
      trans[0] = varargin_3_X;
      trans[1] = varargin_3_Y;
      trans[2] = 0.0;
      emlrtMEXProfilingStatement(9, isMexOutdated);
    }
  }
  emlrtMEXProfilingStatement(10, isMexOutdated);
  c_st.site = &yb_emlrtRSI;
  d_st.site = &cc_emlrtRSI;
  e_st.site = &ec_emlrtRSI;
  validateRotationMatrix(&e_st, rot);
  e_st.site = &fc_emlrtRSI;
  validateTranslationVector(&e_st, trans);
  for (i = 0; i < 3; i++) {
    nx = i << 2;
    T[nx] = rot[3 * i];
    T[nx + 1] = rot[3 * i + 1];
    T[nx + 2] = rot[3 * i + 2];
    T[i + 12] = 0.0;
    T[nx + 3] = trans[i];
  }
  T[15] = 1.0;
  e_st.site = &gc_emlrtRSI;
  if (!c_rigid3dImpl_isTransformationM(&e_st, T)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI,
                                  "images:geotrans:invalidRigidMatrix",
                                  "images:geotrans:invalidRigidMatrix", 0);
  }
  e_st.site = &hc_emlrtRSI;
  affine3d_affine3d(&e_st, T, tform_AffineTform_T);
  d_st.site = &dc_emlrtRSI;
  e_st.site = &ec_emlrtRSI;
  validateRotationMatrix(&e_st, rot);
  e_st.site = &fc_emlrtRSI;
  validateTranslationVector(&e_st, trans);
  for (i = 0; i < 3; i++) {
    nx = i << 2;
    T[nx] = rot[3 * i];
    T[nx + 1] = rot[3 * i + 1];
    T[nx + 2] = rot[3 * i + 2];
    T[i + 12] = 0.0;
    T[nx + 3] = trans[i];
  }
  T[15] = 1.0;
  e_st.site = &gc_emlrtRSI;
  if (!c_rigid3dImpl_isTransformationM(&e_st, T)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI,
                                  "images:geotrans:invalidRigidMatrix",
                                  "images:geotrans:invalidRigidMatrix", 0);
  }
  e_st.site = &hc_emlrtRSI;
  affine3d_affine3d(&e_st, T, unusedExpr);
  emlrtMEXProfilingStatement(11, isMexOutdated);
  c_st.site = &ac_emlrtRSI;
  pctransform(&c_st, varargin_1, tform_AffineTform_T, &ptCloud_obs);
  /*     pcshow(ptCloud_obs) */
  emlrtMEXProfilingStatement(12, isMexOutdated);
  i = locations->size[0] * locations->size[1];
  locations->size[0] = ptCloud_obs.Location->size[0];
  locations->size[1] = 3;
  emxEnsureCapacity_real32_T(&b_st, locations, i, &yd_emlrtRTEI);
  locations_data = locations->data;
  nx = ptCloud_obs.Location->size[0] * 3;
  for (i = 0; i < nx; i++) {
    locations_data[i] = ptCloud_obs.Location->data[i];
  }
  emlrtMEXProfilingStatement(13, isMexOutdated);
  c_st.site = &ub_emlrtRSI;
  nx = locations->size[0] * 3;
  d_st.site = &bg_emlrtRSI;
  emptyDimValue = (int32_T)((uint32_T)nx / 3U);
  if (emptyDimValue > nx) {
    emlrtErrorWithMessageIdR2018a(&d_st, &i_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  n = locations->size[0];
  if (locations->size[0] < 3) {
    n = 3;
  }
  if (emptyDimValue > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &k_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (emptyDimValue * 3 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &l_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  i = locations->size[0] * locations->size[1];
  locations->size[0] = emptyDimValue;
  locations->size[1] = 3;
  emxEnsureCapacity_real32_T(&b_st, locations, i, &ae_emlrtRTEI);
  locations_data = locations->data;
  emlrtMEXProfilingStatement(14, isMexOutdated);
  i = insideX->size[0];
  insideX->size[0] = emptyDimValue;
  emxEnsureCapacity_boolean_T(&b_st, insideX, i, &be_emlrtRTEI);
  insideX_data = insideX->data;
  i = r->size[0];
  r->size[0] = emptyDimValue;
  emxEnsureCapacity_boolean_T(&b_st, r, i, &ce_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < emptyDimValue; i++) {
    f = locations_data[i];
    insideX_data[i] = (f < varargin_4[3]);
    r1[i] = (f > varargin_4[0]);
  }
  if (insideX->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(insideX->size[0], r->size[0], &e_emlrtECI, &b_st);
  }
  nx = insideX->size[0];
  for (i = 0; i < nx; i++) {
    insideX_data[i] = (insideX_data[i] && r1[i]);
  }
  emlrtMEXProfilingStatement(15, isMexOutdated);
  i = insideY->size[0];
  insideY->size[0] = emptyDimValue;
  emxEnsureCapacity_boolean_T(&b_st, insideY, i, &de_emlrtRTEI);
  insideY_data = insideY->data;
  i = r->size[0];
  r->size[0] = emptyDimValue;
  emxEnsureCapacity_boolean_T(&b_st, r, i, &ee_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < emptyDimValue; i++) {
    f = locations_data[i + locations->size[0]];
    insideY_data[i] = (f < varargin_4[4]);
    r1[i] = (f > varargin_4[1]);
  }
  if (insideY->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(insideY->size[0], r->size[0], &d_emlrtECI, &b_st);
  }
  nx = insideY->size[0];
  for (i = 0; i < nx; i++) {
    insideY_data[i] = (insideY_data[i] && r1[i]);
  }
  emlrtMEXProfilingStatement(16, isMexOutdated);
  i = insideZ->size[0];
  insideZ->size[0] = emptyDimValue;
  emxEnsureCapacity_boolean_T(&b_st, insideZ, i, &fe_emlrtRTEI);
  insideZ_data = insideZ->data;
  i = r->size[0];
  r->size[0] = emptyDimValue;
  emxEnsureCapacity_boolean_T(&b_st, r, i, &ge_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < emptyDimValue; i++) {
    f = locations_data[i + locations->size[0] * 2];
    insideZ_data[i] = (f < varargin_4[5]);
    r1[i] = (f > varargin_4[2]);
  }
  if (insideZ->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(insideZ->size[0], r->size[0], &c_emlrtECI, &b_st);
  }
  nx = insideZ->size[0];
  for (i = 0; i < nx; i++) {
    insideZ_data[i] = (insideZ_data[i] && r1[i]);
  }
  emlrtMEXProfilingStatement(17, isMexOutdated);
  if ((insideX->size[0] != insideY->size[0]) &&
      ((insideX->size[0] != 1) && (insideY->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(insideX->size[0], insideY->size[0], &b_emlrtECI,
                                &b_st);
  }
  if (insideX->size[0] == insideY->size[0]) {
    nx = insideX->size[0];
    for (i = 0; i < nx; i++) {
      insideX_data[i] = (insideX_data[i] && insideY_data[i]);
    }
  } else {
    c_st.site = &gqb_emlrtRSI;
    b_and(&c_st, insideX, insideY);
    insideX_data = insideX->data;
  }
  if ((insideX->size[0] != insideZ->size[0]) &&
      ((insideX->size[0] != 1) && (insideZ->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(insideX->size[0], insideZ->size[0], &b_emlrtECI,
                                &b_st);
  }
  if (insideX->size[0] == insideZ->size[0]) {
    nx = insideX->size[0];
    for (i = 0; i < nx; i++) {
      insideX_data[i] = (insideX_data[i] && insideZ_data[i]);
    }
  } else {
    c_st.site = &gqb_emlrtRSI;
    b_and(&c_st, insideX, insideZ);
    insideX_data = insideX->data;
  }
  /*  Remove ego vehicle */
  /*      nearIndices = findNeighborsInRadius(ptCloudIn,[0 0
   * 0],egoVehicleRadius); */
  /*      nonEgoIndices = true(ptCloudIn.Count,1); */
  /*      nonEgoIndices(nearIndices) = false; */
  emlrtMEXProfilingStatement(18, isMexOutdated);
  /* & nonEgoIndices; */
  emlrtMEXProfilingStatement(19, isMexOutdated);
  c_st.site = &vb_emlrtRSI;
  d_st.site = &cg_emlrtRSI;
  eml_find(&d_st, insideX, ii);
  ii_data = ii->data;
  i = varargout_2->size[0];
  varargout_2->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(&c_st, varargout_2, i, &he_emlrtRTEI);
  varargout_2_data = varargout_2->data;
  nx = ii->size[0];
  for (i = 0; i < nx; i++) {
    varargout_2_data[i] = ii_data[i];
  }
  emlrtMEXProfilingStatement(20, isMexOutdated);
  c_st.site = &wb_emlrtRSI;
  nx = insideX->size[0];
  for (i = 0; i < nx; i++) {
    insideX_data[i] = !insideX_data[i];
  }
  d_st.site = &cg_emlrtRSI;
  eml_find(&d_st, insideX, ii);
  ii_data = ii->data;
  i = varargout_3->size[0];
  varargout_3->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(&c_st, varargout_3, i, &ie_emlrtRTEI);
  varargout_2_data = varargout_3->data;
  nx = ii->size[0];
  for (i = 0; i < nx; i++) {
    varargout_2_data[i] = ii_data[i];
  }
  emlrtMEXProfilingStatement(21, isMexOutdated);
  c_st.site = &bc_emlrtRSI;
  pointCloud_select(&c_st, varargin_1, varargout_2, &pcSurvived);
  c_st.site = &xb_emlrtRSI;
  handle_matlabCodegenDestructor(&c_st, &ptCloud_obs);
  emlrtHeapReferenceStackLeaveFcnR2012b(&b_st);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  /*  Remove ground plane */
  /*  [pcObstacles,obstacleIndices,groundIndices] =
   * removeGroundPlane(pcSurvived,obj.GroundMaxDistance,obj.GroundReferenceVector,obj.GroundMaxAngularDistance,survivedIndices,obj.roi);
   */
  /*  Form clusters and get bounding boxes */
  emlrtMEXProfilingStatement(2, isMexOutdated);
  b_st.site = &qb_emlrtRSI;
  varargout_4 =
      getBoundingBoxes(&b_st, &pcSurvived, obj->SegmentationMinDistance,
                       obj->MinDetectionsPerCluster, obj->MaxZDistanceCluster,
                       obj->MinZDistanceCluster, varargin_3_X, varargin_3_Y,
                       varargin_3_yaw, varargin_6, detBBoxes, varargout_5);
  varargout_2_data = detBBoxes->data;
  /*  Assemble detections */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  emlrtMEXProfilingStatement(7, isMexOutdated);
  emlrtMEXProfilingStatement(8, isMexOutdated);
  b_st.site = &rb_emlrtRSI;
  memcpy(&rot[0], &obj->MeasurementNoise[0], 9U * sizeof(real_T));
  emlrtMEXProfilingFunctionEntry((char_T *)c_assembleDetections_complete_n,
                                 isMexOutdated);
  /*  This method assembles the detections in objectDetection format. */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  emlrtMEXProfilingStatement(2, isMexOutdated);
  i = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = detBBoxes->size[1];
  varargout_1->size[1] = 1;
  c_emxEnsureCapacity_objectDetec(&b_st, varargout_1, i, &je_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  emlrtMEXProfilingStatement(3, isMexOutdated);
  i = detBBoxes->size[1];
  for (emptyDimValue = 0; emptyDimValue < i; emptyDimValue++) {
    boolean_T exitg1;
    boolean_T p;
    emlrtMEXProfilingStatement(4, isMexOutdated);
    emlrtMEXProfilingStatement(5, isMexOutdated);
    c_st.site = &dl_emlrtRSI;
    if (emptyDimValue + 1 > detBBoxes->size[1]) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue + 1, 1, detBBoxes->size[1],
                                    &i_emlrtBCI, &c_st);
    }
    d_st.site = &el_emlrtRSI;
    nx = varargout_1->size[0] - 1;
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    e_st.site = &fl_emlrtRSI;
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &e_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &e_st);
    }
    f_st.site = &il_emlrtRSI;
    g_st.site = &jc_emlrtRSI;
    p = true;
    n = 0;
    exitg1 = false;
    while ((!exitg1) && (n < 3)) {
      i1 = n + 3 * emptyDimValue;
      if ((!muDoubleScalarIsInf(varargout_2_data[i1])) &&
          (!muDoubleScalarIsNaN(varargout_2_data[i1]))) {
        n++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &g_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:objectDetection:expectedFinite", 3, 4, 11, "Measurement");
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &l_emlrtBCI, &e_st);
    }
    varargout_1_data[emptyDimValue].Measurement[0] =
        varargout_2_data[3 * emptyDimValue];
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &l_emlrtBCI, &e_st);
    }
    varargout_1_data[emptyDimValue].Measurement[1] =
        varargout_2_data[3 * emptyDimValue + 1];
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &l_emlrtBCI, &e_st);
    }
    varargout_1_data[emptyDimValue].Measurement[2] =
        varargout_2_data[3 * emptyDimValue + 2];
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    e_st.site = &gl_emlrtRSI;
    objectDetection_set_Time(&e_st, &varargout_1_data[emptyDimValue],
                             varargin_2);
    e_st.site = &hl_emlrtRSI;
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &e_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &e_st);
    }
    f_st.site = &kl_emlrtRSI;
    g_st.site = &jc_emlrtRSI;
    p = true;
    n = 0;
    exitg1 = false;
    while ((!exitg1) && (n < 9)) {
      if ((!muDoubleScalarIsInf(rot[n])) && (!muDoubleScalarIsNaN(rot[n]))) {
        n++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &g_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:objectDetection:expectedFinite", 3, 4, 16,
          "MeasurementNoise");
    }
    f_st.site = &ll_emlrtRSI;
    isSymmetricPositiveSemiDefinite(&f_st, rot);
    for (i1 = 0; i1 < 9; i1++) {
      if (emptyDimValue > nx) {
        emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, nx, &k_emlrtBCI, &e_st);
      }
      varargout_1_data[emptyDimValue].pMeasurementNoise[i1] = rot[i1];
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    varargout_1_data[emptyDimValue].SensorIndex = 1.0;
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    varargout_1_data[emptyDimValue].ObjectClassID = 0.0;
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    if (emptyDimValue > varargout_1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(emptyDimValue, 0, varargout_1->size[0] - 1,
                                    &j_emlrtBCI, &d_st);
    }
    emlrtMEXProfilingStatement(7, isMexOutdated);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&b_st);
    }
  }
  emlrtMEXProfilingStatement(8, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  b_st.site = &sb_emlrtRSI;
  handle_matlabCodegenDestructor(&b_st, &pcSurvived);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emxFree_int32_T(sp, &ii);
  emxFree_boolean_T(sp, &r);
  emxFree_boolean_T(sp, &insideZ);
  emxFree_boolean_T(sp, &insideY);
  emxFree_boolean_T(sp, &insideX);
  emxFree_real32_T(sp, &locations);
  emxFreeStruct_pointCloud(sp, &ptCloud_obs);
  emxFree_real_T(sp, &detBBoxes);
  emxFreeStruct_pointCloud(sp, &pcSurvived);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return varargout_4;
}

void b_SystemCore_setup(const emlrtStack *sp,
                        e_matlabshared_tracking_interna *obj,
                        const emxArray_objectDetection *varargin_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const objectDetection *varargin_1_data;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  varargin_1_data = varargin_1->data;
  if (obj->isInitialized != 0) {
    emlrtErrorWithMessageIdR2018a(
        sp, &qb_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
        "setup");
  }
  obj->isInitialized = 1;
  st.site = &np_emlrtRSI;
  b_st.site = &lq_emlrtRSI;
  c_st.site = &mq_emlrtRSI;
  if (varargin_1->size[0] == 0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &sb_emlrtRTEI,
        "shared_tracking:internal:TrackManager:UndefinedSampleDetection",
        "shared_tracking:internal:TrackManager:UndefinedSampleDetection", 0);
  } else {
    obj->pSampleDetection = varargin_1_data[0];
  }
  obj->pOriginatingSensor->size[0] = 1;
  obj->pOriginatingSensor->size[1] = 0;
  obj->pIsOOSM->size[0] = 1;
  obj->pIsOOSM->size[1] = 0;
  obj->pDetectionTimes->size[0] = 1;
  obj->pDetectionTimes->size[1] = 0;
  i = obj->pDetections->size[0] * obj->pDetections->size[1];
  obj->pDetections->size[0] = 1;
  obj->pDetections->size[1] = 1;
  c_emxEnsureCapacity_objectDetec(&st, obj->pDetections, i, &mh_emlrtRTEI);
  obj->pNumDetections = varargin_1->size[0];
}

int32_T b_SystemCore_step(const emlrtStack *sp, trackerJPDA *obj,
                          const emxArray_objectDetection *varargin_1,
                          real_T varargin_2, const real_T varargin_3_data[],
                          const int32_T varargin_3_size[2],
                          struct1_T varargout_1_data[],
                          struct1_T varargout_2_data[],
                          struct1_T varargout_3_data[],
                          int32_T *varargout_2_size, int32_T *varargout_3_size)
{
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T i;
  uint32_T inSize[8];
  boolean_T anyInputSizeChanged;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(
        sp, &nb_emlrtRTEI, "MATLAB:system:methodCalledWhenReleasedCodegen",
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }
  if (obj->isInitialized != 1) {
    st.site = &lp_emlrtRSI;
    b_st.site = &mp_emlrtRSI;
    SystemCore_setup(&b_st, obj, varargin_1, varargin_2, varargin_3_size);
    b_st.site = &mp_emlrtRSI;
    c_st.site = &hy_emlrtRSI;
    for (i = 0; i < 30; i++) {
      d_st.site = &jy_emlrtRSI;
      ObjectTrack_nullify(&d_st, obj->pTracksList[i]);
    }
    obj->pNumLiveTracks = 0;
    for (i = 0; i < 30; i++) {
      obj->pTrackIDs[i] = 0U;
    }
    for (i = 0; i < 30; i++) {
      obj->pConfirmedTracks[i] = false;
    }
    for (i = 0; i < 20; i++) {
      obj->pUsedSensors[i] = 0U;
    }
    d_st.site = &ky_emlrtRSI;
    b_obj = obj->cDetectionManager;
    if (b_obj->isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &m_emlrtRTEI, "MATLAB:system:methodCalledWhenReleasedCodegen",
          "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 5, "reset");
    }
    if (b_obj->isInitialized == 1) {
      b_obj->pDetections->size[0] = 0;
      b_obj->pDetections->size[1] = 0;
      b_obj->pNumDetections = 0;
      b_obj->pOriginatingSensor->size[0] = 1;
      b_obj->pOriginatingSensor->size[1] = 0;
      b_obj->pIsOOSM->size[0] = 1;
      b_obj->pIsOOSM->size[1] = 0;
      b_obj->pDetectionTimes->size[0] = 1;
      b_obj->pDetectionTimes->size[1] = 0;
    }
    c_st.site = &iy_emlrtRSI;
    if (obj->cCostCalculator.isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &ob_emlrtRTEI, "MATLAB:system:methodCalledWhenReleasedCodegen",
          "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 5, "reset");
    }
    obj->pLastTimeStamp = -2.2204460492503131E-16;
    obj->pLastTrackID = 0U;
    for (i = 0; i < 30; i++) {
      obj->pWasDetectable[i] = true;
    }
  }
  st.site = &lp_emlrtRSI;
  if (obj->TunablePropsChanged) {
    b_st.site = &ly_emlrtRSI;
    obj->TunablePropsChanged = false;
  }
  st.site = &lp_emlrtRSI;
  anyInputSizeChanged = false;
  inSize[0] = (uint32_T)varargin_1->size[0];
  inSize[1] = 1U;
  for (i = 0; i < 6; i++) {
    inSize[i + 2] = 1U;
  }
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8)) {
    if (obj->inputVarSize[0].f1[i] != inSize[i]) {
      anyInputSizeChanged = true;
      for (i = 0; i < 8; i++) {
        obj->inputVarSize[0].f1[i] = inSize[i];
      }
      exitg1 = true;
    } else {
      i++;
    }
  }
  inSize[0] = (uint32_T)varargin_3_size[0];
  inSize[1] = 2U;
  for (i = 0; i < 6; i++) {
    inSize[i + 2] = 1U;
  }
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8)) {
    if (obj->inputVarSize[2].f1[i] != inSize[i]) {
      anyInputSizeChanged = true;
      for (i = 0; i < 8; i++) {
        obj->inputVarSize[2].f1[i] = inSize[i];
      }
      exitg1 = true;
    } else {
      i++;
    }
  }
  if (anyInputSizeChanged) {
    st.site = &lp_emlrtRSI;
    JPDATracker_validateInputsImpl(&st, varargin_2);
  }
  st.site = &lp_emlrtRSI;
  return JPDATracker_stepImpl(&st, obj, varargin_1, varargin_2, varargin_3_data,
                              varargin_3_size, varargout_1_data,
                              varargout_2_data, varargout_3_data,
                              varargout_2_size, varargout_3_size);
}

/* End of code generation (SystemCore.c) */
