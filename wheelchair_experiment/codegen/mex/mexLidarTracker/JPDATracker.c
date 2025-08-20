/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * JPDATracker.c
 *
 * Code generation for function 'JPDATracker'
 *
 */

/* Include files */
#include "JPDATracker.h"
#include "AssignmentCostCalculator.h"
#include "ExtendedKalmanFilter.h"
#include "ObjectTrack.h"
#include "SystemCore.h"
#include "all.h"
#include "assertValidSizeArg.h"
#include "colon.h"
#include "combineVectorElements.h"
#include "constrainedConnectedTracks.h"
#include "det.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_setop.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "initializeEKF.h"
#include "jpdaEvents.h"
#include "mean.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "mrdivide_helper.h"
#include "nullAssignment.h"
#include "objectDetection.h"
#include "predictTrackFilter.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sortIdx.h"
#include "sum.h"
#include "trackingEKF.h"
#include "unique.h"
#include "warning.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_uint32_T_1x30
#define struct_emxArray_uint32_T_1x30

struct emxArray_uint32_T_1x30
{
  uint32_T data[30];
  int32_T size[2];
};

#endif                                 /* struct_emxArray_uint32_T_1x30 */

#ifndef typedef_emxArray_uint32_T_1x30
#define typedef_emxArray_uint32_T_1x30

typedef struct emxArray_uint32_T_1x30 emxArray_uint32_T_1x30;

#endif                                 /* typedef_emxArray_uint32_T_1x30 */

/* Variable Definitions */
static emlrtRSInfo pp_emlrtRSI = { 1091,/* lineNo */
  "JPDATracker/validateInputsImpl",    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo qp_emlrtRSI = { 1100,/* lineNo */
  "JPDATracker/validateTimeInput",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo my_emlrtRSI = { 1408,/* lineNo */
  "JPDATracker/stepImpl",              /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ny_emlrtRSI = { 1411,/* lineNo */
  "JPDATracker/stepImpl",              /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo oy_emlrtRSI = { 1414,/* lineNo */
  "JPDATracker/stepImpl",              /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo py_emlrtRSI = { 1508,/* lineNo */
  "JPDATracker/processInputs",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo qy_emlrtRSI = { 1509,/* lineNo */
  "JPDATracker/processInputs",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ry_emlrtRSI = { 1874,/* lineNo */
  "JPDATracker/preprocessDetections",  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo sy_emlrtRSI = { 1875,/* lineNo */
  "JPDATracker/preprocessDetections",  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ty_emlrtRSI = { 1876,/* lineNo */
  "JPDATracker/preprocessDetections",  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo uy_emlrtRSI = { 1878,/* lineNo */
  "JPDATracker/preprocessDetections",  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo vy_emlrtRSI = { 1879,/* lineNo */
  "JPDATracker/preprocessDetections",  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo wy_emlrtRSI = { 180,/* lineNo */
  "DynamicMemoryDetectionManager/stepImpl",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m"                               /* pathName */
};

static emlrtRSInfo xy_emlrtRSI = { 82, /* lineNo */
  "AbstractDetectionManager/setOriginatingSensor",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pathName */
};

static emlrtRSInfo aab_emlrtRSI = { 640,/* lineNo */
  "TrackManager/updateUsedSensors",    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo cab_emlrtRSI = { 19,/* lineNo */
  "setdiff",                           /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/setdiff.m"/* pathName */
};

static emlrtRSInfo dab_emlrtRSI = { 94,/* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRSInfo hab_emlrtRSI = { 1423,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo iab_emlrtRSI = { 1435,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo jab_emlrtRSI = { 1440,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo kab_emlrtRSI = { 1446,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo lab_emlrtRSI = { 1449,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo mab_emlrtRSI = { 1450,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo nab_emlrtRSI = { 1451,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo oab_emlrtRSI = { 1452,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo pab_emlrtRSI = { 1453,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo qab_emlrtRSI = { 1455,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo rab_emlrtRSI = { 1459,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo sab_emlrtRSI = { 1463,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo tab_emlrtRSI = { 1467,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo uab_emlrtRSI = { 1470,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo vab_emlrtRSI = { 1473,/* lineNo */
  "JPDATracker/coreAlgorithm",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo wab_emlrtRSI = { 925,/* lineNo */
  "TrackManager/getLiveTrackIDs",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo xab_emlrtRSI = { 1236,/* lineNo */
  "TrackManager/getLiveTrackIndices",  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo dbb_emlrtRSI = { 1907,/* lineNo */
  "JPDATracker/getCostMatrix",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ebb_emlrtRSI = { 1902,/* lineNo */
  "JPDATracker/getCostMatrix",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo fbb_emlrtRSI = { 1900,/* lineNo */
  "JPDATracker/getCostMatrix",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo gbb_emlrtRSI = { 85,/* lineNo */
  "DynamicMemoryDetectionManager/inSequenceIndices",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m"                               /* pathName */
};

static emlrtRSInfo ibb_emlrtRSI = { 183,/* lineNo */
  "AssignmentCostCalculator/stepImpl", /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pathName */
};

static emlrtRSInfo jbb_emlrtRSI = { 186,/* lineNo */
  "AssignmentCostCalculator/stepImpl", /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pathName */
};

static emlrtRSInfo kbb_emlrtRSI = { 191,/* lineNo */
  "AssignmentCostCalculator/stepImpl", /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pathName */
};

static emlrtRSInfo mcb_emlrtRSI = { 1056,/* lineNo */
  "ObjectTrack/distance",              /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo ncb_emlrtRSI = { 1087,/* lineNo */
  "ObjectTrack/distance",              /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo ocb_emlrtRSI = { 1603,/* lineNo */
  "ObjectTrack/calcCostMatrixFull",    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo pcb_emlrtRSI = { 1604,/* lineNo */
  "ObjectTrack/calcCostMatrixFull",    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo scb_emlrtRSI = { 1715,/* lineNo */
  "ObjectTrack/distanceFull",          /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo tcb_emlrtRSI = { 1722,/* lineNo */
  "ObjectTrack/distanceFull",          /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo ucb_emlrtRSI = { 1729,/* lineNo */
  "ObjectTrack/distanceFull",          /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo vcb_emlrtRSI = { 1746,/* lineNo */
  "ObjectTrack/distanceFull",          /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo wcb_emlrtRSI = { 1751,/* lineNo */
  "ObjectTrack/distanceFull",          /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo xfb_emlrtRSI = { 1981,/* lineNo */
  "JPDATracker/trackDetectability",    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo yfb_emlrtRSI = { 1985,/* lineNo */
  "JPDATracker/trackDetectability",    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo agb_emlrtRSI = { 1991,/* lineNo */
  "JPDATracker/trackDetectability",    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo bgb_emlrtRSI = { 2365,/* lineNo */
  "JPDATracker/predictTracks",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo cgb_emlrtRSI = { 2368,/* lineNo */
  "JPDATracker/predictTracks",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ggb_emlrtRSI = { 1656,/* lineNo */
  "JPDATracker/clusterAssignUpdate",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo hgb_emlrtRSI = { 1659,/* lineNo */
  "JPDATracker/clusterAssignUpdate",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo igb_emlrtRSI = { 1661,/* lineNo */
  "JPDATracker/clusterAssignUpdate",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo jgb_emlrtRSI = { 1663,/* lineNo */
  "JPDATracker/clusterAssignUpdate",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo kgb_emlrtRSI = { 1665,/* lineNo */
  "JPDATracker/clusterAssignUpdate",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo lgb_emlrtRSI = { 1686,/* lineNo */
  "JPDATracker/createClusters",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo mgb_emlrtRSI = { 1687,/* lineNo */
  "JPDATracker/createClusters",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ngb_emlrtRSI = { 1693,/* lineNo */
  "JPDATracker/createClusters",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ogb_emlrtRSI = { 1695,/* lineNo */
  "JPDATracker/createClusters",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo pgb_emlrtRSI = { 1698,/* lineNo */
  "JPDATracker/createClusters",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo qgb_emlrtRSI = { 1702,/* lineNo */
  "JPDATracker/createClusters",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo rgb_emlrtRSI = { 2309,/* lineNo */
  "JPDATracker/selectDetections",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo sgb_emlrtRSI = { 1204,/* lineNo */
  "TrackManager/IntFind",              /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo tgb_emlrtRSI = { 1717,/* lineNo */
  "JPDATracker/sensorValidationMatrix",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ugb_emlrtRSI = { 1736,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo vgb_emlrtRSI = { 1750,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo wgb_emlrtRSI = { 1751,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo xgb_emlrtRSI = { 1757,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ygb_emlrtRSI = { 1758,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ahb_emlrtRSI = { 1762,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo bhb_emlrtRSI = { 1771,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo chb_emlrtRSI = { 1772,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo dhb_emlrtRSI = { 1774,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ehb_emlrtRSI = { 1775,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo fhb_emlrtRSI = { 1777,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ghb_emlrtRSI = { 1779,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo hhb_emlrtRSI = { 1781,/* lineNo */
  "JPDATracker/clusterDetections",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo nib_emlrtRSI = { 136,/* lineNo */
  "allOrAny",                          /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pathName */
};

static emlrtRSInfo tib_emlrtRSI = { 1789,/* lineNo */
  "JPDATracker/jpdaClusterUpdate",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo uib_emlrtRSI = { 1795,/* lineNo */
  "JPDATracker/jpdaClusterUpdate",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo vib_emlrtRSI = { 1798,/* lineNo */
  "JPDATracker/jpdaClusterUpdate",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo wib_emlrtRSI = { 1804,/* lineNo */
  "JPDATracker/jpdaClusterUpdate",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo xib_emlrtRSI = { 1840,/* lineNo */
  "JPDATracker/sortClusterByTime",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo yib_emlrtRSI = { 1846,/* lineNo */
  "JPDATracker/sortClusterByTime",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ajb_emlrtRSI = { 1849,/* lineNo */
  "JPDATracker/sortClusterByTime",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo bjb_emlrtRSI = { 1811,/* lineNo */
  "JPDATracker/calculateClusterPosterior",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo cjb_emlrtRSI = { 1812,/* lineNo */
  "JPDATracker/calculateClusterPosterior",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo djb_emlrtRSI = { 1822,/* lineNo */
  "JPDATracker/calculateClusterPosterior",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ejb_emlrtRSI = { 1831,/* lineNo */
  "JPDATracker/calculateClusterPosterior",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo fjb_emlrtRSI = { 2394,/* lineNo */
  "JPDATracker/validateClusterDetectionsTime",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo gjb_emlrtRSI = { 2396,/* lineNo */
  "JPDATracker/validateClusterDetectionsTime",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo hjb_emlrtRSI = { 2397,/* lineNo */
  "JPDATracker/validateClusterDetectionsTime",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ijb_emlrtRSI = { 2398,/* lineNo */
  "JPDATracker/validateClusterDetectionsTime",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo jjb_emlrtRSI = { 2317,/* lineNo */
  "JPDATracker/findTracksByIDs",       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo kjb_emlrtRSI = { 2283,/* lineNo */
  "JPDATracker/calcEventAndProbabilities",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ljb_emlrtRSI = { 2290,/* lineNo */
  "JPDATracker/calcEventAndProbabilities",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo mjb_emlrtRSI = { 2063,/* lineNo */
  "JPDATracker/likelihoodMatrix",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo njb_emlrtRSI = { 798,/* lineNo */
  "ObjectTrack/likelihood",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo ojb_emlrtRSI = { 800,/* lineNo */
  "ObjectTrack/likelihood",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo pjb_emlrtRSI = { 801,/* lineNo */
  "ObjectTrack/likelihood",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo qjb_emlrtRSI = { 808,/* lineNo */
  "ObjectTrack/likelihood",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo rjb_emlrtRSI = { 816,/* lineNo */
  "ObjectTrack/likelihood",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo sjb_emlrtRSI = { 824,/* lineNo */
  "ObjectTrack/likelihood",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo tjb_emlrtRSI = { 394,/* lineNo */
  "trackingEKF/likelihood",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/trackingEKF.m"/* pathName */
};

static emlrtRSInfo ujb_emlrtRSI = { 395,/* lineNo */
  "trackingEKF/likelihood",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/trackingEKF.m"/* pathName */
};

static emlrtRSInfo gkb_emlrtRSI = { 19,/* lineNo */
  "KalmanLikelihood",                  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/KalmanLikelihood.m"/* pathName */
};

static emlrtRSInfo hkb_emlrtRSI = { 21,/* lineNo */
  "KalmanLikelihood",                  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/KalmanLikelihood.m"/* pathName */
};

static emlrtRSInfo ikb_emlrtRSI = { 2256,/* lineNo */
  "JPDATracker/associationProbabilities",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo jkb_emlrtRSI = { 34,/* lineNo */
  "jointEventsToPosterior",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m"/* pathName */
};

static emlrtRSInfo kkb_emlrtRSI = { 23,/* lineNo */
  "jointEventsToPosterior",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m"/* pathName */
};

static emlrtRSInfo lkb_emlrtRSI = { 119,/* lineNo */
  "computeDimsData",                   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"/* pathName */
};

static emlrtRSInfo mkb_emlrtRSI = { 207,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pathName */
};

static emlrtRSInfo nkb_emlrtRSI = { 225,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pathName */
};

static emlrtRSInfo okb_emlrtRSI = { 227,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pathName */
};

static emlrtRSInfo pkb_emlrtRSI = { 238,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pathName */
};

static emlrtRSInfo qkb_emlrtRSI = { 2325,/* lineNo */
  "JPDATracker/identLowProbDet",       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo rkb_emlrtRSI = { 2326,/* lineNo */
  "JPDATracker/identLowProbDet",       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo skb_emlrtRSI = { 22,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo tkb_emlrtRSI = { 26,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo ukb_emlrtRSI = { 273,/* lineNo */
  "delete_rows",                       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo vkb_emlrtRSI = { 274,/* lineNo */
  "delete_rows",                       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo wkb_emlrtRSI = { 1947,/* lineNo */
  "JPDATracker/updateAssignedTracks",  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo xkb_emlrtRSI = { 1949,/* lineNo */
  "JPDATracker/updateAssignedTracks",  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ykb_emlrtRSI = { 2145,/* lineNo */
  "JPDATracker/updateClusterTracks",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo alb_emlrtRSI = { 2146,/* lineNo */
  "JPDATracker/updateClusterTracks",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo blb_emlrtRSI = { 2147,/* lineNo */
  "JPDATracker/updateClusterTracks",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo clb_emlrtRSI = { 2152,/* lineNo */
  "JPDATracker/updateClusterTracks",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo dlb_emlrtRSI = { 2154,/* lineNo */
  "JPDATracker/updateClusterTracks",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo elb_emlrtRSI = { 2156,/* lineNo */
  "JPDATracker/updateClusterTracks",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo flb_emlrtRSI = { 2176,/* lineNo */
  "JPDATracker/extractDetectionsForCluster",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo glb_emlrtRSI = { 144,/* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo hlb_emlrtRSI = { 2165,/* lineNo */
  "JPDATracker/correctTrack",          /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo ilb_emlrtRSI = { 2166,/* lineNo */
  "JPDATracker/correctTrack",          /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo jlb_emlrtRSI = { 18,/* lineNo */
  "ifWhileCond",                       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/ifWhileCond.m"/* pathName */
};

static emlrtRSInfo klb_emlrtRSI = { 31,/* lineNo */
  "checkNoNaNs",                       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/ifWhileCond.m"/* pathName */
};

static emlrtRSInfo vlb_emlrtRSI = { 970,/* lineNo */
  "ObjectTrack/updateClassificationFromDetectionsJPDA",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo wlb_emlrtRSI = { 971,/* lineNo */
  "ObjectTrack/updateClassificationFromDetectionsJPDA",/* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo ylb_emlrtRSI = { 18,/* lineNo */
  "hasSameClassID",                    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m"/* pathName */
};

static emlrtRSInfo amb_emlrtRSI = { 19,/* lineNo */
  "hasSameClassID",                    /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m"/* pathName */
};

static emlrtRSInfo cmb_emlrtRSI = { 1843,/* lineNo */
  "ObjectTrack/prepareTrackForJPDA",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo mnb_emlrtRSI = { 1864,/* lineNo */
  "ObjectTrack/updateTrackLogicJPDA",  /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo onb_emlrtRSI = { 2191,/* lineNo */
  "JPDATracker/initializeTracks",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo pnb_emlrtRSI = { 2198,/* lineNo */
  "JPDATracker/initializeTracks",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo qnb_emlrtRSI = { 2216,/* lineNo */
  "JPDATracker/initializeTracks",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo rnb_emlrtRSI = { 2220,/* lineNo */
  "JPDATracker/initializeTracks",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo snb_emlrtRSI = { 2228,/* lineNo */
  "JPDATracker/initializeTracks",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo tnb_emlrtRSI = { 2238,/* lineNo */
  "JPDATracker/initializeTracks",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo unb_emlrtRSI = { 2202,/* lineNo */
  "JPDATracker/initializeTracks",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo vnb_emlrtRSI = { 766,/* lineNo */
  "TrackManager/initiateTrack",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo wnb_emlrtRSI = { 765,/* lineNo */
  "TrackManager/initiateTrack",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo xnb_emlrtRSI = { 759,/* lineNo */
  "TrackManager/initiateTrack",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo ynb_emlrtRSI = { 755,/* lineNo */
  "TrackManager/initiateTrack",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo aob_emlrtRSI = { 747,/* lineNo */
  "TrackManager/initiateTrack",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo bob_emlrtRSI = { 745,/* lineNo */
  "TrackManager/initiateTrack",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo cob_emlrtRSI = { 738,/* lineNo */
  "TrackManager/initiateTrack",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo dob_emlrtRSI = { 788,/* lineNo */
  "TrackManager/initializeFilter",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo eob_emlrtRSI = { 793,/* lineNo */
  "TrackManager/initializeFilter",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo fob_emlrtRSI = { 794,/* lineNo */
  "TrackManager/initializeFilter",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo gob_emlrtRSI = { 779,/* lineNo */
  "TrackManager/initializeFilter",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo hob_emlrtRSI = { 2333,/* lineNo */
  "JPDATracker/coastUnassignedTracks", /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo iob_emlrtRSI = { 1004,/* lineNo */
  "ObjectTrack/updateNotAssociated",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo job_emlrtRSI = { 2346,/* lineNo */
  "JPDATracker/deleteOldTracks",       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo kob_emlrtRSI = { 2351,/* lineNo */
  "JPDATracker/deleteOldTracks",       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo lob_emlrtRSI = { 2355,/* lineNo */
  "JPDATracker/deleteOldTracks",       /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo mob_emlrtRSI = { 1030,/* lineNo */
  "ObjectTrack/checkDeletion",         /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pathName */
};

static emlrtRSInfo nob_emlrtRSI = { 290,/* lineNo */
  "trackHistoryLogic/checkDeletion",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/trackHistoryLogic.m"/* pathName */
};

static emlrtRSInfo oob_emlrtRSI = { 832,/* lineNo */
  "TrackManager/recycleTracks",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo pob_emlrtRSI = { 815,/* lineNo */
  "TrackManager/recycleTracks",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo qob_emlrtRSI = { 814,/* lineNo */
  "TrackManager/recycleTracks",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo rob_emlrtRSI = { 1517,/* lineNo */
  "JPDATracker/processOutputs",        /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

static emlrtRSInfo sob_emlrtRSI = { 945,/* lineNo */
  "TrackManager/formatTrackOutputs",   /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo tob_emlrtRSI = { 960,/* lineNo */
  "TrackManager/getTracks",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo uob_emlrtRSI = { 965,/* lineNo */
  "TrackManager/getTracks",            /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo vob_emlrtRSI = { 1006,/* lineNo */
  "TrackManager/getTracksCodegen",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo wob_emlrtRSI = { 1005,/* lineNo */
  "TrackManager/getTracksCodegen",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo xob_emlrtRSI = { 1001,/* lineNo */
  "TrackManager/getTracksCodegen",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtRSInfo yob_emlrtRSI = { 996,/* lineNo */
  "TrackManager/getTracksCodegen",     /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pathName */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  71,                                  /* colNo */
  "",                                  /* aName */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gc_emlrtRTEI = { 93,/* lineNo */
  37,                                  /* colNo */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 85,/* lineNo */
  21,                                  /* colNo */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1006,                                /* lineNo */
  75,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/getTracksCodegen",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ic_emlrtRTEI = { 1235,/* lineNo */
  13,                                  /* colNo */
  "TrackManager/getLiveTrackIndices",  /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 643,/* lineNo */
  17,                                  /* colNo */
  "TrackManager/updateUsedSensors",    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pName */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "DynamicMemoryDetectionManager/originatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m",                              /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "DynamicMemoryDetectionManager/originatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m",                              /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 944, /* lineNo */
  36,                                  /* colNo */
  "TrackManager/formatTrackOutputs",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo kc_emlrtRTEI = { 942,/* lineNo */
  13,                                  /* colNo */
  "TrackManager/formatTrackOutputs",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 1505,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker/processInputs",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  71,                                  /* colNo */
  "",                                  /* aName */
  "AbstractDetectionManager/setOriginatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  961,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/getTracks",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  644,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/updateUsedSensors",    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { 0,  /* iFirst */
  29,                                  /* iLast */
  1006,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/getTracksCodegen",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1008,                                /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/getTracksCodegen",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  946,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/formatTrackOutputs",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  947,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/formatTrackOutputs",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo qc_emlrtRTEI = { 214,/* lineNo */
  56,                                  /* colNo */
  "trackHistoryLogic/miss",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/trackHistoryLogic.m"/* pName */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "DynamicMemoryDetectionManager/isInSequence",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m",                              /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "DynamicMemoryDetectionManager/isInSequence",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m",                              /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  1436,                                /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/coreAlgorithm",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  1436,                                /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/coreAlgorithm",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  925,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/getLiveTrackIDs",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1662,                                /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterAssignUpdate",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1452,                                /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/coreAlgorithm",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "DynamicMemoryDetectionManager/originatingSensor",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m",                              /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  2332,                                /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/coastUnassignedTracks", /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2332,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/coastUnassignedTracks", /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2334,                                /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/coastUnassignedTracks", /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1477,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/coreAlgorithm",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2333,                                /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/coastUnassignedTracks", /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1728,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/distanceFull",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  1605,                                /* lineNo */
  13,                                  /* colNo */
  "ObjectTrack/calcCostMatrixFull",    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pName */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  157,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "AssignmentCostCalculator/setupImpl",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  191,                                 /* lineNo */
  17,                                  /* colNo */
  "AssignmentCostCalculator/stepImpl", /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pName */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  191,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "AssignmentCostCalculator/stepImpl", /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  188,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "AssignmentCostCalculator/stepImpl", /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "DynamicMemoryDetectionManager/inSequenceIndices",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m",                              /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "DynamicMemoryDetectionManager/inSequenceIndices",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m",                              /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo rc_emlrtRTEI = { 1903,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker/getCostMatrix",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  1907,                                /* lineNo */
  17,                                  /* colNo */
  "JPDATracker/getCostMatrix",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtDCInfo i_emlrtDCI = { 1906,/* lineNo */
  33,                                  /* colNo */
  "JPDATracker/getCostMatrix",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 1906,/* lineNo */
  35,                                  /* colNo */
  "JPDATracker/getCostMatrix",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1907,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/getCostMatrix",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1932,                                /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/getCostMatrix",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  189,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "AssignmentCostCalculator/stepImpl", /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  191,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "AssignmentCostCalculator/stepImpl", /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1604,                                /* lineNo */
  69,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/calcCostMatrixFull",    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1728,                                /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/distanceFull",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1605,                                /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/calcCostMatrixFull",    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1753,                                /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/distanceFull",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gf_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  1970,                                /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/trackDetectability",    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1991,                                /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/trackDetectability",    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo tc_emlrtRTEI = { 28,/* lineNo */
  27,                                  /* colNo */
  "validatelt",                        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/validatelt.m"/* pName */
};

static emlrtBCInfo if_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1994,                                /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/trackDetectability",    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jf_emlrtBCI = { 0,  /* iFirst */
  29,                                  /* iLast */
  2366,                                /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/predictTracks",         /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo v_emlrtECI = { 2,   /* nDims */
  1708,                                /* lineNo */
  17,                                  /* colNo */
  "JPDATracker/createClusters",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 1682,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker/createClusters",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtBCInfo kf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1688,                                /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/createClusters",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1695,                                /* lineNo */
  69,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/createClusters",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1714,                                /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/sensorValidationMatrix",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1703,                                /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/createClusters",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo of_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1706,                                /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/createClusters",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1706,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/createClusters",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1707,                                /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/createClusters",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1707,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/createClusters",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo w_emlrtECI = { 2,   /* nDims */
  2309,                                /* lineNo */
  36,                                  /* colNo */
  "JPDATracker/selectDetections",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtECInfo x_emlrtECI = { -1,  /* nDims */
  921,                                 /* lineNo */
  13,                                  /* colNo */
  "TrackManager/trackIDs",             /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pName */
};

static emlrtBCInfo sf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1775,                                /* lineNo */
  69,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo vc_emlrtRTEI = { 1761,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtBCInfo tf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1776,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1781,                                /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1776,                                /* lineNo */
  66,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1776,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xf_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  921,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/trackIDs",             /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1779,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ag_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1778,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1779,                                /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1781,                                /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/clusterDetections",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2395,                                /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/validateClusterDetectionsTime",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2399,                                /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/validateClusterDetectionsTime",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo yc_emlrtRTEI = { 2401,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker/validateClusterDetectionsTime",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtBCInfo hg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2317,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/findTracksByIDs",       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo y_emlrtECI = { -1,  /* nDims */
  2317,                                /* lineNo */
  17,                                  /* colNo */
  "JPDATracker/findTracksByIDs",       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtBCInfo ig_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2317,                                /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/findTracksByIDs",       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo ab_emlrtECI = { -1, /* nDims */
  34,                                  /* lineNo */
  1,                                   /* colNo */
  "jointEventsToPosterior",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m"/* pName */
};

static emlrtBCInfo jg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "jointEventsToPosterior",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo bb_emlrtECI = { -1, /* nDims */
  23,                                  /* lineNo */
  5,                                   /* colNo */
  "jointEventsToPosterior",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m"/* pName */
};

static emlrtBCInfo kg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "jointEventsToPosterior",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 13,  /* lineNo */
  34,                                  /* colNo */
  "jointEventsToPosterior",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo lg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2156,                                /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/updateClusterTracks",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2154,                                /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/updateClusterTracks",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ng_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2176,                                /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/extractDetectionsForCluster",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo og_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2176,                                /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/extractDetectionsForCluster",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1838,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/prepareTrackForJPDA",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1853,                                /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/updateTrackLogicJPDA",  /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1853,                                /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/updateTrackLogicJPDA",  /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2178,                                /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/extractDetectionsForCluster",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2178,                                /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/extractDetectionsForCluster",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ug_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2178,                                /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/extractDetectionsForCluster",/* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2150,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/updateClusterTracks",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2152,                                /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/updateClusterTracks",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2153,                                /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/updateClusterTracks",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2159,                                /* lineNo */
  96,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/updateClusterTracks",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ah_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "hasSameClassID",                    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "hasSameClassID",                    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ch_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "hasSameClassID",                    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "hasSameClassID",                    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "hasSameClassID",                    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "hasSameClassID",                    /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1838,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/prepareTrackForJPDA",   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo fb_emlrtECI = { 2,  /* nDims */
  2218,                                /* lineNo */
  34,                                  /* colNo */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtECInfo gb_emlrtECI = { -1, /* nDims */
  2220,                                /* lineNo */
  21,                                  /* colNo */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtBCInfo mh_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  2247,                                /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nh_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  2247,                                /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2192,                                /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ph_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2227,                                /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gd_emlrtRTEI = { 199,/* lineNo */
  35,                                  /* colNo */
  "trackHistoryLogic/init",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/trackHistoryLogic.m"/* pName */
};

static emlrtBCInfo qh_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  730,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/initiateTrack",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo rh_emlrtBCI = { 0,  /* iFirst */
  29,                                  /* iLast */
  2213,                                /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2217,                                /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo th_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2219,                                /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2220,                                /* lineNo */
  87,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2220,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2225,                                /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2227,                                /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2231,                                /* lineNo */
  70,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ai_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2231,                                /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/initializeTracks",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  830,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/recycleTracks",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ci_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  837,                                 /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/recycleTracks",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo hb_emlrtECI = { -1, /* nDims */
  837,                                 /* lineNo */
  21,                                  /* colNo */
  "TrackManager/recycleTracks",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pName */
};

static emlrtBCInfo di_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  838,                                 /* lineNo */
  68,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/recycleTracks",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo ib_emlrtECI = { -1, /* nDims */
  838,                                 /* lineNo */
  21,                                  /* colNo */
  "TrackManager/recycleTracks",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pName */
};

static emlrtBCInfo ei_emlrtBCI = { 0,  /* iFirst */
  29,                                  /* iLast */
  835,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/recycleTracks",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo hd_emlrtRTEI = { 2345,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker/deleteOldTracks",       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtBCInfo fi_emlrtBCI = { 1,  /* iFirst */
  30,                                  /* iLast */
  2350,                                /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/deleteOldTracks",       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2350,                                /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/deleteOldTracks",       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2351,                                /* lineNo */
  88,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/deleteOldTracks",       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ii_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2351,                                /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/deleteOldTracks",       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ji_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  815,                                 /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/recycleTracks",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ki_emlrtBCI = { 0,  /* iFirst */
  29,                                  /* iLast */
  833,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/recycleTracks",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo li_emlrtBCI = { 0,  /* iFirst */
  29,                                  /* iLast */
  833,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "TrackManager/recycleTracks",        /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",/* pName */
  3                                    /* checkKind */
};

static emlrtECInfo kb_emlrtECI = { -1, /* nDims */
  1849,                                /* lineNo */
  24,                                  /* colNo */
  "JPDATracker/sortClusterByTime",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtBCInfo bj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1795,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/jpdaClusterUpdate",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2062,                                /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2057,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ej_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2063,                                /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo lb_emlrtECI = { -1, /* nDims */
  2063,                                /* lineNo */
  17,                                  /* colNo */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtECInfo mb_emlrtECI = { -1, /* nDims */
  2067,                                /* lineNo */
  13,                                  /* colNo */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtECInfo nb_emlrtECI = { 2,  /* nDims */
  2070,                                /* lineNo */
  42,                                  /* colNo */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtECInfo ob_emlrtECI = { -1, /* nDims */
  2070,                                /* lineNo */
  13,                                  /* colNo */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo od_emlrtRTEI = { 81,/* lineNo */
  27,                                  /* colNo */
  "validate_inputs",                   /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = { 296,/* lineNo */
  1,                                   /* colNo */
  "delete_rows",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtBCInfo fj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  806,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/likelihood",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 2045,/* lineNo */
  35,                                  /* colNo */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo gj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1798,                                /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/jpdaClusterUpdate",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2063,                                /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ij_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2327,                                /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/identLowProbDet",       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1801,                                /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/jpdaClusterUpdate",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1792,                                /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/jpdaClusterUpdate",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1847,                                /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/sortClusterByTime",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1847,                                /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/sortClusterByTime",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1795,                                /* lineNo */
  75,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/jpdaClusterUpdate",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 2045,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo oj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2061,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2063,                                /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "JPDATracker/likelihoodMatrix",      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  806,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/likelihood",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  806,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/likelihood",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  824,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "ObjectTrack/likelihood",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo li_emlrtRTEI = { 166,/* lineNo */
  13,                                  /* colNo */
  "DynamicMemoryDetectionManager",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m"                               /* pName */
};

static emlrtRTEInfo mi_emlrtRTEI = { 167,/* lineNo */
  13,                                  /* colNo */
  "DynamicMemoryDetectionManager",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m"                               /* pName */
};

static emlrtRTEInfo ni_emlrtRTEI = { 168,/* lineNo */
  13,                                  /* colNo */
  "DynamicMemoryDetectionManager",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m"                               /* pName */
};

static emlrtRTEInfo oi_emlrtRTEI = { 171,/* lineNo */
  21,                                  /* colNo */
  "DynamicMemoryDetectionManager",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m"                               /* pName */
};

static emlrtRTEInfo pi_emlrtRTEI = { 78,/* lineNo */
  13,                                  /* colNo */
  "AbstractDetectionManager",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtRTEInfo qi_emlrtRTEI = { 1875,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ri_emlrtRTEI = { 79,/* lineNo */
  13,                                  /* colNo */
  "AbstractDetectionManager",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtRTEInfo si_emlrtRTEI = { 80,/* lineNo */
  13,                                  /* colNo */
  "AbstractDetectionManager",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtRTEInfo ti_emlrtRTEI = { 1509,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ui_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/sort.m"/* pName */
};

static emlrtRTEInfo vi_emlrtRTEI = { 84,/* lineNo */
  48,                                  /* colNo */
  "AbstractDetectionManager",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtRTEInfo wi_emlrtRTEI = { 87,/* lineNo */
  45,                                  /* colNo */
  "AbstractDetectionManager",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtRTEInfo xi_emlrtRTEI = { 88,/* lineNo */
  55,                                  /* colNo */
  "AbstractDetectionManager",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtRTEInfo yi_emlrtRTEI = { 1251,/* lineNo */
  30,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo aj_emlrtRTEI = { 89,/* lineNo */
  42,                                  /* colNo */
  "AbstractDetectionManager",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtRTEInfo bj_emlrtRTEI = { 1878,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo cj_emlrtRTEI = { 640,/* lineNo */
  13,                                  /* colNo */
  "TrackManager",                      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pName */
};

static emlrtRTEInfo dj_emlrtRTEI = { 640,/* lineNo */
  34,                                  /* colNo */
  "TrackManager",                      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pName */
};

static emlrtRTEInfo ej_emlrtRTEI = { 1236,/* lineNo */
  23,                                  /* colNo */
  "TrackManager",                      /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"/* pName */
};

static emlrtRTEInfo fj_emlrtRTEI = { 84,/* lineNo */
  64,                                  /* colNo */
  "AbstractDetectionManager",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AbstractDetectionManager.m"/* pName */
};

static emlrtRTEInfo kj_emlrtRTEI = { 1449,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo lj_emlrtRTEI = { 1451,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo mj_emlrtRTEI = { 1421,/* lineNo */
  32,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo nj_emlrtRTEI = { 1662,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo oj_emlrtRTEI = { 1440,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo pj_emlrtRTEI = { 1452,/* lineNo */
  35,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo qj_emlrtRTEI = { 1661,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo rj_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo sj_emlrtRTEI = { 1662,/* lineNo */
  40,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo uj_emlrtRTEI = { 85,/* lineNo */
  35,                                  /* colNo */
  "DynamicMemoryDetectionManager",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m"                               /* pName */
};

static emlrtRTEInfo vj_emlrtRTEI = { 1900,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo wj_emlrtRTEI = { 1906,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo xj_emlrtRTEI = { 1907,/* lineNo */
  27,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo yj_emlrtRTEI = { 1907,/* lineNo */
  41,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ak_emlrtRTEI = { 188,/* lineNo */
  39,                                  /* colNo */
  "AssignmentCostCalculator",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pName */
};

static emlrtRTEInfo bk_emlrtRTEI = { 1883,/* lineNo */
  37,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ck_emlrtRTEI = { 191,/* lineNo */
  30,                                  /* colNo */
  "AssignmentCostCalculator",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pName */
};

static emlrtRTEInfo dk_emlrtRTEI = { 189,/* lineNo */
  37,                                  /* colNo */
  "AssignmentCostCalculator",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pName */
};

static emlrtRTEInfo ek_emlrtRTEI = { 191,/* lineNo */
  53,                                  /* colNo */
  "AssignmentCostCalculator",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pName */
};

static emlrtRTEInfo fk_emlrtRTEI = { 1605,/* lineNo */
  20,                                  /* colNo */
  "ObjectTrack",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pName */
};

static emlrtRTEInfo gk_emlrtRTEI = { 1605,/* lineNo */
  13,                                  /* colNo */
  "ObjectTrack",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pName */
};

static emlrtRTEInfo hk_emlrtRTEI = { 1907,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ik_emlrtRTEI = { 183,/* lineNo */
  13,                                  /* colNo */
  "AssignmentCostCalculator",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pName */
};

static emlrtRTEInfo jk_emlrtRTEI = { 191,/* lineNo */
  17,                                  /* colNo */
  "AssignmentCostCalculator",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pName */
};

static emlrtRTEInfo kk_emlrtRTEI = { 189,/* lineNo */
  48,                                  /* colNo */
  "AssignmentCostCalculator",          /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"/* pName */
};

static emlrtRTEInfo xk_emlrtRTEI = { 1685,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo yk_emlrtRTEI = { 1671,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo al_emlrtRTEI = { 1714,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo bl_emlrtRTEI = { 1715,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo cl_emlrtRTEI = { 1698,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo dl_emlrtRTEI = { 1708,/* lineNo */
  28,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo el_emlrtRTEI = { 1708,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo fl_emlrtRTEI = { 1687,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo gl_emlrtRTEI = { 1695,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo hl_emlrtRTEI = { 1687,/* lineNo */
  32,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo il_emlrtRTEI = { 54,/* lineNo */
  17,                                  /* colNo */
  "DynamicMemoryDetectionManager",     /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/DynamicMemoryDetectionManag"
  "er.m"                               /* pName */
};

static emlrtRTEInfo kl_emlrtRTEI = { 1737,/* lineNo */
  57,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ll_emlrtRTEI = { 1750,/* lineNo */
  46,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo nl_emlrtRTEI = { 1757,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ol_emlrtRTEI = { 1762,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo pl_emlrtRTEI = { 1772,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ql_emlrtRTEI = { 1775,/* lineNo */
  35,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo rl_emlrtRTEI = { 1775,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo sl_emlrtRTEI = { 1776,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo tl_emlrtRTEI = { 1778,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ul_emlrtRTEI = { 1781,/* lineNo */
  46,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo vl_emlrtRTEI = { 1771,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo wl_emlrtRTEI = { 1721,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo xl_emlrtRTEI = { 1751,/* lineNo */
  48,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo yl_emlrtRTEI = { 1750,/* lineNo */
  42,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo em_emlrtRTEI = { 2394,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo fm_emlrtRTEI = { 2395,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo gm_emlrtRTEI = { 2398,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo hm_emlrtRTEI = { 2256,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo im_emlrtRTEI = { 23,/* lineNo */
  32,                                  /* colNo */
  "jointEventsToPosterior",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m"/* pName */
};

static emlrtRTEInfo jm_emlrtRTEI = { 23,/* lineNo */
  28,                                  /* colNo */
  "jointEventsToPosterior",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m"/* pName */
};

static emlrtRTEInfo km_emlrtRTEI = { 153,/* lineNo */
  23,                                  /* colNo */
  "blockedSummation",                  /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pName */
};

static emlrtRTEInfo lm_emlrtRTEI = { 34,/* lineNo */
  34,                                  /* colNo */
  "jointEventsToPosterior",            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/+assignment/jointEventsToPosterior.m"/* pName */
};

static emlrtRTEInfo mm_emlrtRTEI = { 153,/* lineNo */
  1,                                   /* colNo */
  "blockedSummation",                  /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pName */
};

static emlrtRTEInfo nm_emlrtRTEI = { 92,/* lineNo */
  25,                                  /* colNo */
  "repmat",                            /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo om_emlrtRTEI = { 2146,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo pm_emlrtRTEI = { 2147,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo qm_emlrtRTEI = { 2152,/* lineNo */
  30,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo rm_emlrtRTEI = { 2156,/* lineNo */
  46,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo sm_emlrtRTEI = { 2165,/* lineNo */
  16,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo tm_emlrtRTEI = { 970,/* lineNo */
  17,                                  /* colNo */
  "ObjectTrack",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pName */
};

static emlrtRTEInfo um_emlrtRTEI = { 932,/* lineNo */
  13,                                  /* colNo */
  "ObjectTrack",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pName */
};

static emlrtRTEInfo vm_emlrtRTEI = { 1844,/* lineNo */
  20,                                  /* colNo */
  "ObjectTrack",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pName */
};

static emlrtRTEInfo wm_emlrtRTEI = { 1853,/* lineNo */
  40,                                  /* colNo */
  "ObjectTrack",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pName */
};

static emlrtRTEInfo xm_emlrtRTEI = { 2145,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ym_emlrtRTEI = { 1941,/* lineNo */
  18,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo kn_emlrtRTEI = { 2212,/* lineNo */
  21,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ln_emlrtRTEI = { 2216,/* lineNo */
  21,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo mn_emlrtRTEI = { 2217,/* lineNo */
  21,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo nn_emlrtRTEI = { 2218,/* lineNo */
  73,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo on_emlrtRTEI = { 2182,/* lineNo */
  32,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo pn_emlrtRTEI = { 2220,/* lineNo */
  87,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo qn_emlrtRTEI = { 2222,/* lineNo */
  21,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo rn_emlrtRTEI = { 1603,/* lineNo */
  13,                                  /* colNo */
  "ObjectTrack",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pName */
};

static emlrtRTEInfo sn_emlrtRTEI = { 2238,/* lineNo */
  25,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo tn_emlrtRTEI = { 2238,/* lineNo */
  43,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo un_emlrtRTEI = { 2220,/* lineNo */
  47,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo vn_emlrtRTEI = { 2218,/* lineNo */
  34,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo wn_emlrtRTEI = { 2220,/* lineNo */
  21,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo xn_emlrtRTEI = { 290,/* lineNo */
  45,                                  /* colNo */
  "trackHistoryLogic",                 /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/trackHistoryLogic.m"/* pName */
};

static emlrtRTEInfo yn_emlrtRTEI = { 2346,/* lineNo */
  26,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ro_emlrtRTEI = { 2045,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo so_emlrtRTEI = { 2062,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo to_emlrtRTEI = { 2063,/* lineNo */
  31,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo uo_emlrtRTEI = { 1785,/* lineNo */
  54,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo vo_emlrtRTEI = { 2063,/* lineNo */
  76,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo wo_emlrtRTEI = { 2070,/* lineNo */
  42,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo xo_emlrtRTEI = { 2063,/* lineNo */
  53,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo yo_emlrtRTEI = { 1824,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ap_emlrtRTEI = { 1798,/* lineNo */
  55,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo bp_emlrtRTEI = { 2325,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo cp_emlrtRTEI = { 2326,/* lineNo */
  25,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo dp_emlrtRTEI = { 1804,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ep_emlrtRTEI = { 2326,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo fp_emlrtRTEI = { 2063,/* lineNo */
  17,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo gp_emlrtRTEI = { 2070,/* lineNo */
  13,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo hp_emlrtRTEI = { 2063,/* lineNo */
  95,                                  /* colNo */
  "JPDATracker",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pName */
};

static emlrtRTEInfo ip_emlrtRTEI = { 798,/* lineNo */
  13,                                  /* colNo */
  "ObjectTrack",                       /* fName */
  "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"/* pName */
};

static emlrtRSInfo hqb_emlrtRSI = { 2070,/* lineNo */
  "JPDATracker/likelihoodMatrix",      /* fcnName */
  "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/JPDATracker.m"/* pathName */
};

/* Function Declarations */
static void JPDATracker_clusterDetections(const emlrtStack *sp, trackerJPDA *obj,
  const emxArray_boolean_T *valMatrix, real_T sensorID, const emxArray_boolean_T
  *detSelector, emxArray_int32_T *unassignedDets, int32_T unassignedTracks_data[],
  int32_T unassignedTracks_size[2], struct_T clusters_data[], int32_T
  clusters_size[2]);
static void JPDATracker_coreAlgorithm(const emlrtStack *sp, trackerJPDA *obj,
  const emxArray_objectDetection *dets, real_T b_time, const real_T
  varargin_2_data[], const int32_T varargin_2_size[2]);
static void JPDATracker_createClusters(const emlrtStack *sp, trackerJPDA *obj,
  const emxArray_real_T *overallCostMatrix, const emxArray_boolean_T
  *detSelector, emxArray_struct_T *clusters, emxArray_boolean_T
  *isUnassignedDetection, int32_T unassignedTrackCounter_data[], int32_T
  unassignedTrackCounter_size[2]);
static void JPDATracker_deleteOldTracks(const emlrtStack *sp, trackerJPDA *obj,
  uint32_T delTrIDs_data[], int32_T delTrIDs_size[2]);
static void JPDATracker_findTracksByIDs(const emlrtStack *sp, const trackerJPDA *
  obj, const uint32_T trackIDs_data[], const int32_T trackIDs_size[2], uint32_T
  indices_data[], int32_T indices_size[2]);
static void JPDATracker_getCostMatrix(const emlrtStack *sp, trackerJPDA *obj,
  const emxArray_objectDetection *dets, emxArray_real_T *cost);
static void JPDATracker_initializeTracks(const emlrtStack *sp, trackerJPDA *obj,
  emxArray_int32_T *OverallUnassigned, const emxArray_objectDetection *dets,
  uint32_T newTrackIDs_data[], int32_T newTrackIDs_size[2]);
static void JPDATracker_jpdaClusterUpdate(const emlrtStack *sp, trackerJPDA *obj,
  emxArray_struct_T *clusters, emxArray_boolean_T *isUnassignedDetection, const
  emxArray_objectDetection *dets);
static void JPDATracker_predictTracks(const emlrtStack *sp, trackerJPDA *obj,
  real_T t);
static void JPDATracker_selectDetections(const emlrtStack *sp, trackerJPDA *obj,
  real_T ID, const emxArray_boolean_T *detSelector, emxArray_int32_T *indices);
static void JPDATracker_trackDetectability(const emlrtStack *sp, trackerJPDA
  *obj, const real_T varargin_2_data[], const int32_T varargin_2_size[2]);
static void c_JPDATracker_associationProbab(const emlrtStack *sp, const
  emxArray_boolean_T *FJE, const emxArray_real_T *FJEprobs, emxArray_real_T
  *posterior);
static void c_JPDATracker_updateAssignedTra(const emlrtStack *sp, trackerJPDA
  *obj, const emxArray_uint32_T *cluster_DetectionIndices, const uint32_T
  cluster_TrackIDs_data[], const int32_T cluster_TrackIDs_size[2], const
  emxArray_real_T *cluster_MarginalProbabilities, const emxArray_objectDetection
  *dets);
static void c_JPDATracker_validateClusterDe(const emlrtStack *sp, trackerJPDA
  *obj, const emxArray_uint32_T *detIndices);
static void d_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1, const
  real_T in2_data[], const int32_T in2_size[2], const emxArray_real_T *in3,
  int32_T in4, int32_T in5, int32_T in6, int32_T in7);

/* Function Definitions */
static void JPDATracker_clusterDetections(const emlrtStack *sp, trackerJPDA *obj,
  const emxArray_boolean_T *valMatrix, real_T sensorID, const emxArray_boolean_T
  *detSelector, emxArray_int32_T *unassignedDets, int32_T unassignedTracks_data[],
  int32_T unassignedTracks_size[2], struct_T clusters_data[], int32_T
  clusters_size[2])
{
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T b_y_data;
  emxArray_boolean_T c_y_data;
  emxArray_boolean_T d_y_data;
  emxArray_boolean_T *Omega;
  emxArray_boolean_T *b_Omega;
  emxArray_boolean_T *b_detections2cluster;
  emxArray_boolean_T *in;
  emxArray_int32_T b_a_data;
  emxArray_int32_T *clustdetid;
  emxArray_int32_T *detections2cluster;
  emxArray_int32_T *ii;
  emxArray_int32_T *sensorDetIds;
  emxArray_real_T *b_detTimes;
  emxArray_real_T *detTimes;
  real_T a_TimeStamp;
  real_T *b_detTimes_data;
  real_T *detTimes_data;
  int32_T a_data[31];
  int32_T clusterNumero_data[31];
  int32_T tracks2cluster_data[31];
  int32_T b_iv[4];
  int32_T b_iv1[4];
  int32_T a_size[2];
  int32_T tracks2cluster_size[2];
  int32_T y_size[2];
  int32_T b_i;
  int32_T b_i1;
  int32_T b_i2;
  int32_T b_loop_ub;
  int32_T c;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T nAllClusters;
  int32_T nClusters;
  int32_T nb;
  int32_T *clustdetid_data;
  int32_T *detections2cluster_data;
  int32_T *ii_data;
  int32_T *sensorDetIds_data;
  uint32_T b_trackIDList_data[31];
  uint32_T trackIDList_data[31];
  uint32_T u;
  uint32_T x;
  uint32_T y;
  boolean_T y_data[31];
  const boolean_T *valMatrix_data;
  boolean_T *Omega_data;
  boolean_T *b_Omega_data;
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
  valMatrix_data = valMatrix->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (valMatrix->size[1] < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = valMatrix->size[1];
  }

  emxInit_boolean_T(sp, &Omega, 2, &xl_emlrtRTEI, true);
  i2 = Omega->size[0] * Omega->size[1];
  Omega->size[0] = valMatrix->size[0];
  loop_ub = i1 - i;
  Omega->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, Omega, i2, &kl_emlrtRTEI);
  Omega_data = Omega->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    nb = valMatrix->size[0];
    for (i2 = 0; i2 < nb; i2++) {
      Omega_data[i2 + Omega->size[0] * i1] = valMatrix_data[i2 + valMatrix->
        size[0] * (i + i1)];
    }
  }

  emxInit_int32_T(sp, &detections2cluster, 2, &wl_emlrtRTEI);
  st.site = &ugb_emlrtRSI;
  nAllClusters = constrainedConnectedTracks(&st, Omega, detections2cluster,
    tracks2cluster_data, tracks2cluster_size, &nb, &i2);
  detections2cluster_data = detections2cluster->data;
  x = obj->c_pCurrentMaxNumDetectionsPerCl;
  if (nb < 0) {
    nb = 0;
  }

  y = (uint32_T)nb;
  obj->c_pCurrentMaxNumDetectionsPerCl = muIntScalarMax_uint32(x, y);
  x = obj->pCurrentMaxNumTracksPerCluster;
  if (i2 < 0) {
    i2 = 0;
  }

  y = (uint32_T)i2;
  obj->pCurrentMaxNumTracksPerCluster = muIntScalarMax_uint32(x, y);
  st.site = &vgb_emlrtRSI;
  emxInit_boolean_T(&st, &b_Omega, 2, &ll_emlrtRTEI, true);
  i = b_Omega->size[0] * b_Omega->size[1];
  b_Omega->size[0] = Omega->size[0];
  b_Omega->size[1] = Omega->size[1];
  emxEnsureCapacity_boolean_T(&st, b_Omega, i, &ll_emlrtRTEI);
  b_Omega_data = b_Omega->data;
  nb = Omega->size[0] * Omega->size[1];
  for (i = 0; i < nb; i++) {
    b_Omega_data[i] = !Omega_data[i];
  }

  emxInit_boolean_T(&st, &in, 1, &yl_emlrtRTEI, true);
  b_st.site = &vgb_emlrtRSI;
  c_all(&b_st, b_Omega, in);
  emxFree_boolean_T(&st, &b_Omega);
  b_st.site = &sgb_emlrtRSI;
  c_st.site = &kx_emlrtRSI;
  d_st.site = &cg_emlrtRSI;
  eml_find(&d_st, in, unassignedDets);
  emxFree_boolean_T(&c_st, &in);
  st.site = &wgb_emlrtRSI;
  b_st.site = &wgb_emlrtRSI;
  for (i = 0; i < nb; i++) {
    Omega_data[i] = !Omega_data[i];
  }

  c_st.site = &lib_emlrtRSI;
  y_size[0] = 1;
  y_size[1] = Omega->size[1];
  loop_ub = Omega->size[1];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = true;
  }

  i = Omega->size[1];
  i2 = 0;
  d_st.site = &nib_emlrtRSI;
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T exitg1;
    nb = i2 + Omega->size[0];
    b_i1 = i2 + 1;
    i2 = nb;
    d_st.site = &pl_emlrtRSI;
    if ((b_i1 <= nb) && (nb > 2147483646)) {
      e_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    exitg1 = false;
    while ((!exitg1) && (b_i1 <= nb)) {
      if (!Omega_data[b_i1 - 1]) {
        y_data[b_i] = false;
        exitg1 = true;
      } else {
        b_i1++;
      }
    }
  }

  emxFree_boolean_T(&c_st, &Omega);
  b_st.site = &sgb_emlrtRSI;
  c_st.site = &kx_emlrtRSI;
  b_y_data.data = &y_data[0];
  b_y_data.size = &y_size[0];
  b_y_data.allocatedSize = 31;
  b_y_data.numDimensions = 2;
  b_y_data.canFreeData = false;
  emxInit_int32_T(&c_st, &ii, 2, &qe_emlrtRTEI);
  d_st.site = &cg_emlrtRSI;
  b_eml_find(&d_st, &b_y_data, ii);
  ii_data = ii->data;
  unassignedTracks_size[0] = 1;
  unassignedTracks_size[1] = ii->size[1];
  loop_ub = ii->size[1];
  for (i = 0; i < loop_ub; i++) {
    unassignedTracks_data[i] = ii_data[i];
  }

  nClusters = (nAllClusters - ii->size[1]) - unassignedDets->size[0];
  emxInit_int32_T(sp, &sensorDetIds, 2, &vl_emlrtRTEI);
  i = sensorDetIds->size[0] * sensorDetIds->size[1];
  sensorDetIds->size[0] = 1;
  sensorDetIds->size[1] = tracks2cluster_size[1];
  emxEnsureCapacity_int32_T(sp, sensorDetIds, i, &nl_emlrtRTEI);
  sensorDetIds_data = sensorDetIds->data;
  loop_ub = tracks2cluster_size[1];
  for (i = 0; i < loop_ub; i++) {
    sensorDetIds_data[i] = tracks2cluster_data[i];
  }

  st.site = &xgb_emlrtRSI;
  nullAssignment(&st, sensorDetIds, ii);
  sensorDetIds_data = sensorDetIds->data;
  a_size[0] = 1;
  a_size[1] = sensorDetIds->size[1];
  loop_ub = sensorDetIds->size[1];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = sensorDetIds_data[i];
  }

  st.site = &ygb_emlrtRSI;
  b_st.site = &fj_emlrtRSI;
  i2 = a_size[1];
  b_a_data.data = &a_data[0];
  b_a_data.size = &a_size[0];
  b_a_data.allocatedSize = 31;
  b_a_data.numDimensions = 2;
  b_a_data.canFreeData = false;
  c_st.site = &gj_emlrtRSI;
  sortIdx(&c_st, &b_a_data, sensorDetIds);
  sensorDetIds_data = sensorDetIds->data;
  c_st.site = &hj_emlrtRSI;
  for (nAllClusters = 0; nAllClusters < i2; nAllClusters++) {
    clusterNumero_data[nAllClusters] = a_data[sensorDetIds_data[nAllClusters] -
      1];
  }

  nb = 0;
  nAllClusters = 1;
  while (nAllClusters <= i2) {
    b_i1 = clusterNumero_data[nAllClusters - 1];
    do {
      nAllClusters++;
    } while (!((nAllClusters > i2) || (clusterNumero_data[nAllClusters - 1] !=
               b_i1)));

    nb++;
    clusterNumero_data[nb - 1] = b_i1;
    c_st.site = &ij_emlrtRSI;
  }

  c_st.site = &kj_emlrtRSI;
  if (nb > a_size[1]) {
    emlrtErrorWithMessageIdR2018a(&b_st, &jb_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (nb < 1) {
    b_i = 0;
  } else {
    b_i = nb;
  }

  c_st.site = &mj_emlrtRSI;
  if (nClusters > 30) {
    emlrtErrorWithMessageIdR2018a(sp, &vc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  st.site = &ahb_emlrtRSI;
  x = obj->pClusterTypeDef.SensorIndex;
  a_TimeStamp = obj->pClusterTypeDef.TimeStamp;
  b_st.site = &ib_emlrtRSI;
  if (nClusters < 0) {
    emlrtNonNegativeCheckR2012b(nClusters, &g_emlrtDCI, &st);
  }

  i = clusters_size[0] * clusters_size[1];
  clusters_size[0] = 1;
  clusters_size[1] = nClusters;
  emxEnsureCapacity_struct_T1(sp, clusters_data, clusters_size, i, &ol_emlrtRTEI);
  i = nClusters - 1;
  for (i1 = 0; i1 <= i; i1++) {
    clusters_data[i1].DetectionIndices->size[0] = 1;
    clusters_data[i1].DetectionIndices->size[1] = 0;
    clusters_data[i1].TrackIDs.size[0] = 1;
    clusters_data[i1].TrackIDs.size[1] = 0;
    clusters_data[i1].ValidationMatrix->size[0] = 0;
    clusters_data[i1].ValidationMatrix->size[1] = 0;
    clusters_data[i1].SensorIndex = x;
    clusters_data[i1].TimeStamp = a_TimeStamp;
    clusters_data[i1].MarginalProbabilities->size[0] = 0;
    clusters_data[i1].MarginalProbabilities->size[1] = 0;
    clusters_data[i1].Likelihood->size[0] = 0;
    clusters_data[i1].Likelihood->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }

  st.site = &bhb_emlrtRSI;
  JPDATracker_selectDetections(&st, obj, sensorID, detSelector, sensorDetIds);
  sensorDetIds_data = sensorDetIds->data;
  st.site = &chb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  emxInit_real_T(&st, &detTimes, 2, &pl_emlrtRTEI, true);
  i = detTimes->size[0] * detTimes->size[1];
  detTimes->size[0] = 1;
  detTimes->size[1] = b_obj->pDetectionTimes->size[1];
  emxEnsureCapacity_real_T(&st, detTimes, i, &pl_emlrtRTEI);
  detTimes_data = detTimes->data;
  loop_ub = b_obj->pDetectionTimes->size[1];
  for (i = 0; i < loop_ub; i++) {
    detTimes_data[i] = b_obj->pDetectionTimes->data[i];
  }

  st.site = &dhb_emlrtRSI;
  emxInit_int32_T(sp, &clustdetid, 2, &rl_emlrtRTEI);
  emxInit_boolean_T(sp, &b_detections2cluster, 2, &ql_emlrtRTEI, true);
  emxInit_real_T(sp, &b_detTimes, 2, &ul_emlrtRTEI, true);
  if (nClusters - 1 >= 0) {
    b_i2 = clusters_size[1];
    b_loop_ub = tracks2cluster_size[1];
    c_loop_ub = tracks2cluster_size[1];
    a_TimeStamp = muDoubleScalarRound(sensorID);
    if (a_TimeStamp < 4.294967296E+9) {
      if (a_TimeStamp >= 0.0) {
        u = (uint32_T)a_TimeStamp;
      } else {
        u = 0U;
      }
    } else if (a_TimeStamp >= 4.294967296E+9) {
      u = MAX_uint32_T;
    } else {
      u = 0U;
    }

    i3 = clusters_size[1];
  }

  for (c = 0; c < nClusters; c++) {
    int32_T tmp_data[32];
    st.site = &ehb_emlrtRSI;
    if (c + 1 > b_i) {
      emlrtDynamicBoundsCheckR2012b(c + 1, 1, b_i, &sf_emlrtBCI, &st);
    }

    nb = clusterNumero_data[c];
    i = b_detections2cluster->size[0] * b_detections2cluster->size[1];
    b_detections2cluster->size[0] = 1;
    loop_ub = detections2cluster->size[1];
    b_detections2cluster->size[1] = detections2cluster->size[1];
    emxEnsureCapacity_boolean_T(&st, b_detections2cluster, i, &ql_emlrtRTEI);
    Omega_data = b_detections2cluster->data;
    for (i = 0; i < loop_ub; i++) {
      Omega_data[i] = (detections2cluster_data[i] == nb);
    }

    b_st.site = &cg_emlrtRSI;
    b_eml_find(&b_st, b_detections2cluster, ii);
    ii_data = ii->data;
    i = clustdetid->size[0] * clustdetid->size[1];
    clustdetid->size[0] = 1;
    clustdetid->size[1] = ii->size[1];
    emxEnsureCapacity_int32_T(&st, clustdetid, i, &rl_emlrtRTEI);
    clustdetid_data = clustdetid->data;
    loop_ub = ii->size[1];
    for (i = 0; i < loop_ub; i++) {
      clustdetid_data[i] = ii_data[i];
    }

    if (c + 1 > b_i2) {
      emlrtDynamicBoundsCheckR2012b(c + 1, 1, b_i2, &tf_emlrtBCI, (emlrtConstCTX)
        sp);
    }

    i = clusters_data[c].DetectionIndices->size[0] * clusters_data[c].
      DetectionIndices->size[1];
    clusters_data[c].DetectionIndices->size[0] = 1;
    emxEnsureCapacity_uint32_T(sp, clusters_data[c].DetectionIndices, i,
      &sl_emlrtRTEI);
    i = clusters_data[c].DetectionIndices->size[0] * clusters_data[c].
      DetectionIndices->size[1];
    clusters_data[c].DetectionIndices->size[1] = clustdetid->size[1];
    emxEnsureCapacity_uint32_T(sp, clusters_data[c].DetectionIndices, i,
      &sl_emlrtRTEI);
    if (c + 1 > b_i2) {
      emlrtDynamicBoundsCheckR2012b(c + 1, 1, b_i2, &tf_emlrtBCI, (emlrtConstCTX)
        sp);
    }

    loop_ub = clustdetid->size[1];
    for (i = 0; i < loop_ub; i++) {
      if ((clustdetid_data[i] < 1) || (clustdetid_data[i] > sensorDetIds->size[1]))
      {
        emlrtDynamicBoundsCheckR2012b(clustdetid_data[i], 1, sensorDetIds->size
          [1], &vf_emlrtBCI, (emlrtConstCTX)sp);
      }

      i1 = clusters_size[1];
      if (c + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(c + 1, 1, i1, &wf_emlrtBCI, (emlrtConstCTX)
          sp);
      }

      i1 = sensorDetIds_data[clustdetid_data[i] - 1];
      if (i1 < 0) {
        i1 = 0;
      }

      clusters_data[c].DetectionIndices->data[i] = (uint32_T)i1;
    }

    st.site = &fhb_emlrtRSI;
    nb = clusterNumero_data[c];
    y_size[0] = 1;
    y_size[1] = tracks2cluster_size[1];
    for (i = 0; i < b_loop_ub; i++) {
      y_data[i] = (tracks2cluster_data[i] == nb);
    }

    c_y_data.data = &y_data[0];
    c_y_data.size = &y_size[0];
    c_y_data.allocatedSize = 31;
    c_y_data.numDimensions = 2;
    c_y_data.canFreeData = false;
    b_st.site = &cg_emlrtRSI;
    b_eml_find(&b_st, &c_y_data, ii);
    ii_data = ii->data;
    st.site = &fhb_emlrtRSI;
    nb = ii->size[1];
    loop_ub = ii->size[1];
    for (i = 0; i < loop_ub; i++) {
      if ((ii_data[i] < 1) || (ii_data[i] > 30)) {
        emlrtDynamicBoundsCheckR2012b(ii_data[i], 1, 30, &xf_emlrtBCI, &st);
      }

      b_trackIDList_data[i] = obj->pTrackIDs[ii_data[i] - 1];
    }

    if (ii->size[1] != nb) {
      emlrtSubAssignSizeCheck1dR2017a(ii->size[1], nb, &x_emlrtECI, &st);
    }

    loop_ub = ii->size[1];
    nb = ii->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&trackIDList_data[0], &b_trackIDList_data[0], (uint32_T)loop_ub *
             sizeof(uint32_T));
    }

    clusters_data[c].TrackIDs.size[0] = 1;
    clusters_data[c].TrackIDs.size[1] = nb;
    for (i = 0; i < nb; i++) {
      clusters_data[c].TrackIDs.data[i] = trackIDList_data[i];
    }

    st.site = &ghb_emlrtRSI;
    nb = clusterNumero_data[c];
    y_size[0] = 1;
    y_size[1] = tracks2cluster_size[1];
    for (i = 0; i < c_loop_ub; i++) {
      y_data[i] = (tracks2cluster_data[i] == nb);
    }

    d_y_data.data = &y_data[0];
    d_y_data.size = &y_size[0];
    d_y_data.allocatedSize = 31;
    d_y_data.numDimensions = 2;
    d_y_data.canFreeData = false;
    b_st.site = &cg_emlrtRSI;
    b_eml_find(&b_st, &d_y_data, ii);
    ii_data = ii->data;
    i2 = valMatrix->size[1];
    nAllClusters = ii->size[1] + 1;
    if (valMatrix->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, valMatrix->size[1], &yf_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    tmp_data[0] = 0;
    loop_ub = ii->size[1];
    b_i1 = (ii->size[1] / 4) << 2;
    nb = b_i1 - 4;
    for (i = 0; i <= nb; i += 4) {
      __m128i r;
      __m128i r1;
      r = _mm_loadu_si128((const __m128i *)&ii_data[i]);
      r1 = _mm_set1_epi32(1);
      _mm_storeu_si128((__m128i *)&b_iv[0], _mm_add_epi32(r, r1));
      if ((b_iv[0] < 1) || (b_iv[0] > i2)) {
        emlrtDynamicBoundsCheckR2012b(b_iv[0], 1, i2, &yf_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      b_iv1[0] = b_iv[0];
      if ((b_iv[1] < 1) || (b_iv[1] > i2)) {
        emlrtDynamicBoundsCheckR2012b(b_iv[1], 1, i2, &yf_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      b_iv1[1] = b_iv[1];
      if ((b_iv[2] < 1) || (b_iv[2] > i2)) {
        emlrtDynamicBoundsCheckR2012b(b_iv[2], 1, i2, &yf_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      b_iv1[2] = b_iv[2];
      if ((b_iv[3] < 1) || (b_iv[3] > i2)) {
        emlrtDynamicBoundsCheckR2012b(b_iv[3], 1, i2, &yf_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      b_iv1[3] = b_iv[3];
      r = _mm_loadu_si128((const __m128i *)&b_iv1[0]);
      _mm_storeu_si128((__m128i *)&tmp_data[i + 1], _mm_sub_epi32(r, r1));
    }

    for (i = b_i1; i < loop_ub; i++) {
      i1 = ii_data[i] + 1;
      if ((i1 < 1) || (i1 > i2)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &yf_emlrtBCI, (emlrtConstCTX)sp);
      }

      tmp_data[i + 1] = i1 - 1;
    }

    i = clusters_data[c].ValidationMatrix->size[0] * clusters_data[c].
      ValidationMatrix->size[1];
    clusters_data[c].ValidationMatrix->size[0] = clustdetid->size[1];
    emxEnsureCapacity_boolean_T(sp, clusters_data[c].ValidationMatrix, i,
      &tl_emlrtRTEI);
    i = clusters_data[c].ValidationMatrix->size[0] * clusters_data[c].
      ValidationMatrix->size[1];
    clusters_data[c].ValidationMatrix->size[1] = nAllClusters;
    emxEnsureCapacity_boolean_T(sp, clusters_data[c].ValidationMatrix, i,
      &tl_emlrtRTEI);
    for (i = 0; i < nAllClusters; i++) {
      loop_ub = clustdetid->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        if ((clustdetid_data[i1] < 1) || (clustdetid_data[i1] > valMatrix->size
             [0])) {
          emlrtDynamicBoundsCheckR2012b(clustdetid_data[i1], 1, valMatrix->size
            [0], &bg_emlrtBCI, (emlrtConstCTX)sp);
        }

        i2 = clusters_size[1];
        if (c + 1 > i2) {
          emlrtDynamicBoundsCheckR2012b(c + 1, 1, i2, &ag_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        clusters_data[c].ValidationMatrix->data[i1 + clusters_data[c].
          ValidationMatrix->size[0] * i] = valMatrix_data[(clustdetid_data[i1] +
          valMatrix->size[0] * tmp_data[i]) - 1];
      }
    }

    clusters_data[c].SensorIndex = u;
    i = b_detTimes->size[0] * b_detTimes->size[1];
    b_detTimes->size[0] = 1;
    b_detTimes->size[1] = clusters_data[c].DetectionIndices->size[1];
    emxEnsureCapacity_real_T(sp, b_detTimes, i, &ul_emlrtRTEI);
    b_detTimes_data = b_detTimes->data;
    if (c + 1 > i3) {
      emlrtDynamicBoundsCheckR2012b(c + 1, 1, i3, &uf_emlrtBCI, (emlrtConstCTX)
        sp);
    }

    loop_ub = clusters_data[c].DetectionIndices->size[1];
    for (i = 0; i < loop_ub; i++) {
      i1 = (int32_T)clusters_data[c].DetectionIndices->data[i];
      if ((i1 < 1) || (i1 > detTimes->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, detTimes->size[1], &cg_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      b_detTimes_data[i] = detTimes_data[i1 - 1];
    }

    st.site = &hhb_emlrtRSI;
    clusters_data[c].TimeStamp = b_mean(&st, b_detTimes);
  }

  emxFree_real_T(sp, &b_detTimes);
  emxFree_boolean_T(sp, &b_detections2cluster);
  emxFree_int32_T(sp, &ii);
  emxFree_int32_T(sp, &detections2cluster);
  emxFree_int32_T(sp, &clustdetid);
  emxFree_real_T(sp, &detTimes);
  emxFree_int32_T(sp, &sensorDetIds);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void JPDATracker_coreAlgorithm(const emlrtStack *sp, trackerJPDA *obj,
  const emxArray_objectDetection *dets, real_T b_time, const real_T
  varargin_2_data[], const int32_T varargin_2_size[2])
{
  d_matlabshared_tracking_interna *track;
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T b_unassignedTrackCounter_data;
  emxArray_boolean_T *inseq;
  emxArray_boolean_T *isUnassignedDetection;
  emxArray_int32_T *detInds;
  emxArray_int32_T *r;
  emxArray_int32_T *unassignedDetectionId;
  emxArray_real_T *costMatrix;
  emxArray_real_T *dTimes;
  emxArray_real_T *r2;
  emxArray_struct_T *clusters;
  emxArray_uint32_T_1x30 iqb_emlrtRSI;
  trackHistoryLogic *c_obj;
  real_T *dTimes_data;
  int32_T b_detInds_data[30];
  int32_T detInds_size[2];
  int32_T unassignedTrackCounter_size[2];
  int32_T N;
  int32_T i;
  int32_T last;
  int32_T numLiveTracksBeg;
  int32_T *detInds_data;
  int32_T *r1;
  int32_T *unassignedDetectionId_data;
  int8_T trIDsAfterOOSM_size_idx_1;
  boolean_T unassignedTrackCounter_data[30];
  boolean_T exitg1;
  boolean_T y;
  boolean_T *inseq_data;
  boolean_T *isUnassignedDetection_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &hab_emlrtRSI;
  b_st.site = &wab_emlrtRSI;
  N = obj->pNumLiveTracks;
  if (N > 30) {
    emlrtErrorWithMessageIdR2018a(&b_st, &ic_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  emxInit_int32_T(&b_st, &detInds, 2, &qj_emlrtRTEI);
  c_st.site = &xab_emlrtRSI;
  d_st.site = &yab_emlrtRSI;
  e_st.site = &abb_emlrtRSI;
  eml_integer_colon_dispatcher(&e_st, N, detInds);
  detInds_data = detInds->data;
  last = detInds->size[1];
  for (i = 0; i < last; i++) {
    if ((detInds_data[i] < 1) || (detInds_data[i] > 30)) {
      emlrtDynamicBoundsCheckR2012b(detInds_data[i], 1, 30, &pd_emlrtBCI, &st);
    }
  }

  numLiveTracksBeg = obj->pNumLiveTracks + 1;
  st.site = &iab_emlrtRSI;
  b_st.site = &wab_emlrtRSI;
  N = obj->pNumLiveTracks;
  if (N > 30) {
    emlrtErrorWithMessageIdR2018a(&b_st, &ic_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  c_st.site = &xab_emlrtRSI;
  d_st.site = &yab_emlrtRSI;
  e_st.site = &abb_emlrtRSI;
  eml_integer_colon_dispatcher(&e_st, N, detInds);
  detInds_data = detInds->data;
  detInds_size[0] = 1;
  detInds_size[1] = detInds->size[1];
  last = detInds->size[1];
  for (i = 0; i < last; i++) {
    if ((detInds_data[i] < 1) || (detInds_data[i] > 30)) {
      emlrtDynamicBoundsCheckR2012b(detInds_data[i], 1, 30, &pd_emlrtBCI, &st);
    }

    b_detInds_data[i] = detInds_data[i];
  }

  trIDsAfterOOSM_size_idx_1 = (int8_T)detInds_size[1];
  i = obj->pNumLiveTracks;
  if (numLiveTracksBeg <= i) {
    if ((numLiveTracksBeg < 1) || (numLiveTracksBeg > 30)) {
      emlrtDynamicBoundsCheckR2012b(numLiveTracksBeg, 1, 30, &od_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if ((i < 1) || (i > 30)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 30, &nd_emlrtBCI, (emlrtConstCTX)sp);
    }
  }

  emxInit_real_T(sp, &costMatrix, 2, &oj_emlrtRTEI, true);
  st.site = &jab_emlrtRSI;
  JPDATracker_getCostMatrix(&st, obj, dets, costMatrix);
  st.site = &kab_emlrtRSI;
  JPDATracker_trackDetectability(&st, obj, varargin_2_data, varargin_2_size);
  st.site = &lab_emlrtRSI;
  b_obj = obj->cDetectionManager;
  last = b_obj->pNumDetections;
  if (last < 1) {
    last = 0;
  } else {
    i = b_obj->pIsOOSM->size[1];
    if (i < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &md_emlrtBCI, &st);
    }

    i = b_obj->pIsOOSM->size[1];
    if (last > i) {
      emlrtDynamicBoundsCheckR2012b(last, 1, i, &ld_emlrtBCI, &st);
    }
  }

  emxInit_boolean_T(&st, &inseq, 2, &kj_emlrtRTEI, true);
  i = inseq->size[0] * inseq->size[1];
  inseq->size[0] = 1;
  inseq->size[1] = last;
  emxEnsureCapacity_boolean_T(&st, inseq, i, &kj_emlrtRTEI);
  inseq_data = inseq->data;
  for (i = 0; i < last; i++) {
    inseq_data[i] = !b_obj->pIsOOSM->data[i];
  }

  st.site = &mab_emlrtRSI;
  b_st.site = &lx_emlrtRSI;
  y = false;
  c_st.site = &pl_emlrtRSI;
  if (inseq->size[1] > 2147483646) {
    d_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  N = 1;
  exitg1 = false;
  while ((!exitg1) && (N <= inseq->size[1])) {
    if (inseq_data[N - 1]) {
      y = true;
      exitg1 = true;
    } else {
      N++;
    }
  }

  emxInit_real_T(sp, &dTimes, 2, &lj_emlrtRTEI, true);
  emxInit_int32_T(sp, &unassignedDetectionId, 2, &pj_emlrtRTEI);
  if (y) {
    real_T tmin;
    st.site = &nab_emlrtRSI;
    b_obj = obj->cDetectionManager;
    i = dTimes->size[0] * dTimes->size[1];
    dTimes->size[0] = 1;
    dTimes->size[1] = b_obj->pDetectionTimes->size[1];
    emxEnsureCapacity_real_T(&st, dTimes, i, &lj_emlrtRTEI);
    dTimes_data = dTimes->data;
    last = b_obj->pDetectionTimes->size[1];
    for (i = 0; i < last; i++) {
      dTimes_data[i] = b_obj->pDetectionTimes->data[i];
    }

    last = inseq->size[1] - 1;
    N = 0;
    for (numLiveTracksBeg = 0; numLiveTracksBeg <= last; numLiveTracksBeg++) {
      if (inseq_data[numLiveTracksBeg]) {
        N++;
      }
    }

    i = unassignedDetectionId->size[0] * unassignedDetectionId->size[1];
    unassignedDetectionId->size[0] = 1;
    unassignedDetectionId->size[1] = N;
    emxEnsureCapacity_int32_T(sp, unassignedDetectionId, i, &mj_emlrtRTEI);
    unassignedDetectionId_data = unassignedDetectionId->data;
    N = 0;
    for (numLiveTracksBeg = 0; numLiveTracksBeg <= last; numLiveTracksBeg++) {
      if (inseq_data[numLiveTracksBeg]) {
        unassignedDetectionId_data[N] = numLiveTracksBeg;
        N++;
      }
    }

    st.site = &oab_emlrtRSI;
    last = unassignedDetectionId->size[1];
    for (i = 0; i < last; i++) {
      if (unassignedDetectionId_data[i] > dTimes->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(unassignedDetectionId_data[i], 0,
          dTimes->size[1] - 1, &rd_emlrtBCI, &st);
      }
    }

    b_st.site = &vd_emlrtRSI;
    c_st.site = &wd_emlrtRSI;
    d_st.site = &xd_emlrtRSI;
    if (unassignedDetectionId->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &eb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    last = unassignedDetectionId->size[1];
    if (unassignedDetectionId->size[1] <= 2) {
      if (unassignedDetectionId->size[1] == 1) {
        tmin = dTimes_data[unassignedDetectionId_data[0]];
      } else {
        real_T d;
        tmin = dTimes_data[unassignedDetectionId_data[0]];
        d = dTimes_data[unassignedDetectionId_data[1]];
        if ((tmin > d) || (muDoubleScalarIsNaN(tmin) && (!muDoubleScalarIsNaN(d))))
        {
          tmin = d;
        }
      }
    } else {
      tmin = dTimes_data[unassignedDetectionId_data[0]];
      if (!muDoubleScalarIsNaN(tmin)) {
        N = 1;
      } else {
        N = 0;
        numLiveTracksBeg = 2;
        exitg1 = false;
        while ((!exitg1) && (numLiveTracksBeg <= last)) {
          if (!muDoubleScalarIsNaN
              (dTimes_data[unassignedDetectionId_data[numLiveTracksBeg - 1]])) {
            N = numLiveTracksBeg;
            exitg1 = true;
          } else {
            numLiveTracksBeg++;
          }
        }
      }

      if (N != 0) {
        tmin = dTimes_data[unassignedDetectionId_data[N - 1]];
        N++;
        for (numLiveTracksBeg = N; numLiveTracksBeg <= last; numLiveTracksBeg++)
        {
          i = unassignedDetectionId_data[numLiveTracksBeg - 1];
          if (tmin > dTimes_data[i]) {
            tmin = dTimes_data[i];
          }
        }
      }
    }

    st.site = &pab_emlrtRSI;
    JPDATracker_predictTracks(&st, obj, tmin);
  } else {
    st.site = &qab_emlrtRSI;
    JPDATracker_predictTracks(&st, obj, b_time);
  }

  st.site = &rab_emlrtRSI;
  emxInit_struct_T(&st, &clusters, &mj_emlrtRTEI);
  emxInit_boolean_T(&st, &isUnassignedDetection, 2, &mj_emlrtRTEI, true);
  b_st.site = &ggb_emlrtRSI;
  JPDATracker_createClusters(&b_st, obj, costMatrix, inseq, clusters,
    isUnassignedDetection, b_detInds_data, detInds_size);
  emxFree_real_T(&st, &costMatrix);
  b_st.site = &hgb_emlrtRSI;
  JPDATracker_jpdaClusterUpdate(&b_st, obj, clusters, isUnassignedDetection,
    dets);
  isUnassignedDetection_data = isUnassignedDetection->data;
  emxFree_struct_T(&st, &clusters);
  b_st.site = &igb_emlrtRSI;
  c_st.site = &yab_emlrtRSI;
  d_st.site = &abb_emlrtRSI;
  eml_integer_colon_dispatcher(&d_st, isUnassignedDetection->size[1], detInds);
  detInds_data = detInds->data;
  last = isUnassignedDetection->size[1] - 1;
  N = 0;
  for (numLiveTracksBeg = 0; numLiveTracksBeg <= last; numLiveTracksBeg++) {
    if (isUnassignedDetection_data[numLiveTracksBeg]) {
      N++;
    }
  }

  emxInit_int32_T(&st, &r, 2, &sj_emlrtRTEI);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = N;
  emxEnsureCapacity_int32_T(&st, r, i, &mj_emlrtRTEI);
  r1 = r->data;
  N = 0;
  for (numLiveTracksBeg = 0; numLiveTracksBeg <= last; numLiveTracksBeg++) {
    if (isUnassignedDetection_data[numLiveTracksBeg]) {
      r1[N] = numLiveTracksBeg;
      N++;
    }
  }

  emxFree_boolean_T(&st, &isUnassignedDetection);
  i = unassignedDetectionId->size[0] * unassignedDetectionId->size[1];
  unassignedDetectionId->size[0] = 1;
  unassignedDetectionId->size[1] = r->size[1];
  emxEnsureCapacity_int32_T(&st, unassignedDetectionId, i, &nj_emlrtRTEI);
  unassignedDetectionId_data = unassignedDetectionId->data;
  last = r->size[1];
  for (i = 0; i < last; i++) {
    if (r1[i] > detInds->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 0, detInds->size[1] - 1, &qd_emlrtBCI,
        &st);
    }

    unassignedDetectionId_data[i] = detInds_data[r1[i]];
  }

  emxFree_int32_T(&st, &r);
  b_st.site = &jgb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  last = inseq->size[1] - 1;
  N = 0;
  for (numLiveTracksBeg = 0; numLiveTracksBeg <= last; numLiveTracksBeg++) {
    if (inseq_data[numLiveTracksBeg]) {
      N++;
    }
  }

  i = dTimes->size[0] * dTimes->size[1];
  dTimes->size[0] = 1;
  dTimes->size[1] = N;
  emxEnsureCapacity_real_T(&b_st, dTimes, i, &mj_emlrtRTEI);
  dTimes_data = dTimes->data;
  N = 0;
  for (numLiveTracksBeg = 0; numLiveTracksBeg <= last; numLiveTracksBeg++) {
    if (inseq_data[numLiveTracksBeg]) {
      i = b_obj->pOriginatingSensor->size[1] - 1;
      if (numLiveTracksBeg > i) {
        emlrtDynamicBoundsCheckR2012b(numLiveTracksBeg, 0, i, &sd_emlrtBCI,
          &b_st);
      }

      dTimes_data[N] = b_obj->pOriginatingSensor->data[numLiveTracksBeg];
      N++;
    }
  }

  emxFree_boolean_T(&b_st, &inseq);
  b_st.site = &kgb_emlrtRSI;
  emxInit_real_T(&b_st, &r2, 2, &rj_emlrtRTEI, true);
  c_st.site = &fj_emlrtRSI;
  b_unique_vector(&c_st, dTimes, r2);
  emxFree_real_T(&b_st, &dTimes);
  N = r2->size[1];
  emxFree_real_T(&b_st, &r2);
  b_st.site = &kgb_emlrtRSI;
  c_st.site = &sgb_emlrtRSI;
  d_st.site = &kx_emlrtRSI;
  unassignedTrackCounter_size[0] = 1;
  unassignedTrackCounter_size[1] = detInds_size[1];
  last = detInds_size[1];
  for (i = 0; i < last; i++) {
    unassignedTrackCounter_data[i] = (b_detInds_data[i] == N);
  }

  b_unassignedTrackCounter_data.data = &unassignedTrackCounter_data[0];
  b_unassignedTrackCounter_data.size = &unassignedTrackCounter_size[0];
  b_unassignedTrackCounter_data.allocatedSize = 30;
  b_unassignedTrackCounter_data.numDimensions = 2;
  b_unassignedTrackCounter_data.canFreeData = false;
  e_st.site = &cg_emlrtRSI;
  b_eml_find(&e_st, &b_unassignedTrackCounter_data, detInds);
  detInds_data = detInds->data;
  st.site = &sab_emlrtRSI;
  JPDATracker_initializeTracks(&st, obj, unassignedDetectionId, dets,
    iqb_emlrtRSI.data, iqb_emlrtRSI.size);
  emxFree_int32_T(sp, &unassignedDetectionId);
  st.site = &tab_emlrtRSI;
  i = detInds->size[1];
  for (N = 0; N < i; N++) {
    if (N + 1 > detInds->size[1]) {
      emlrtDynamicBoundsCheckR2012b(N + 1, 1, detInds->size[1], &ud_emlrtBCI,
        &st);
    }

    numLiveTracksBeg = detInds_data[N];
    if ((numLiveTracksBeg < 1) || (numLiveTracksBeg > 30)) {
      emlrtDynamicBoundsCheckR2012b(numLiveTracksBeg, 1, 30, &td_emlrtBCI, &st);
    }

    if (obj->pWasDetectable[numLiveTracksBeg - 1]) {
      uint32_T q0;
      uint32_T qY;
      boolean_T bv[50];
      if (N + 1 > detInds->size[1]) {
        emlrtDynamicBoundsCheckR2012b(N + 1, 1, detInds->size[1], &vd_emlrtBCI,
          &st);
      }

      b_st.site = &hob_emlrtRSI;
      if (N + 1 > detInds->size[1]) {
        emlrtDynamicBoundsCheckR2012b(N + 1, 1, detInds->size[1], &xd_emlrtBCI,
          &b_st);
      }

      track = obj->pTracksList[numLiveTracksBeg - 1];
      track->pIsCoasted = true;
      c_st.site = &iob_emlrtRSI;
      c_obj = track->TrackLogic;
      if (c_obj->pIsFirstUpdate) {
        emlrtErrorWithMessageIdR2018a(&c_st, &qc_emlrtRTEI,
          "shared_tracking:trackHistoryLogic:notInitialized",
          "shared_tracking:trackHistoryLogic:notInitialized", 3, 4, 4, "miss");
      }

      bv[0] = false;
      for (numLiveTracksBeg = 0; numLiveTracksBeg < 49; numLiveTracksBeg++) {
        bv[numLiveTracksBeg + 1] = c_obj->pRecentHistory[numLiveTracksBeg];
      }

      for (numLiveTracksBeg = 0; numLiveTracksBeg < 50; numLiveTracksBeg++) {
        c_obj->pRecentHistory[numLiveTracksBeg] = bv[numLiveTracksBeg];
      }

      c_obj->pIsFirstUpdate = false;
      q0 = track->pAge;
      qY = q0 + 1U;
      if (q0 + 1U < q0) {
        qY = MAX_uint32_T;
      }

      track->pAge = qY;
    }
  }

  st.site = &uab_emlrtRSI;
  JPDATracker_predictTracks(&st, obj, b_time);
  st.site = &vab_emlrtRSI;
  JPDATracker_deleteOldTracks(&st, obj, iqb_emlrtRSI.data, iqb_emlrtRSI.size);
  if (detInds->size[1] != 0) {
    last = detInds->size[1];
    for (i = 0; i < last; i++) {
      if ((detInds_data[i] < 1) || (detInds_data[i] > trIDsAfterOOSM_size_idx_1))
      {
        emlrtDynamicBoundsCheckR2012b(detInds_data[i], 1,
          trIDsAfterOOSM_size_idx_1, &wd_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
  }

  emxFree_int32_T(sp, &detInds);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void JPDATracker_createClusters(const emlrtStack *sp, trackerJPDA *obj,
  const emxArray_real_T *overallCostMatrix, const emxArray_boolean_T
  *detSelector, emxArray_struct_T *clusters, emxArray_boolean_T
  *isUnassignedDetection, int32_T unassignedTrackCounter_data[], int32_T
  unassignedTrackCounter_size[2])
{
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_boolean_T *m;
  emxArray_boolean_T *r;
  emxArray_int32_T *sensorDetectionsId;
  emxArray_int32_T *unassignedDet;
  emxArray_real_T *a;
  emxArray_real_T *costMatrix;
  emxArray_real_T *sensorIDs;
  emxArray_struct_T *b_clusters;
  emxArray_struct_T_1x30 thisSensorClusters;
  struct_T *b_clusters_data;
  struct_T *clusters_data;
  const real_T *overallCostMatrix_data;
  real_T *costMatrix_data;
  real_T *sensorIDs_data;
  int32_T unassignedTrack_data[31];
  int32_T unassignedTrack_size[2];
  int32_T N;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T s;
  int32_T sizes_idx_1;
  int32_T trueCount;
  int32_T *sensorDetectionsId_data;
  int32_T *unassignedDet_data;
  const boolean_T *detSelector_data;
  boolean_T *isUnassignedDetection_data;
  boolean_T *m_data;
  boolean_T *r1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  clusters_data = clusters->data;
  detSelector_data = detSelector->data;
  overallCostMatrix_data = overallCostMatrix->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  N = obj->pNumLiveTracks;
  if (N > 30) {
    emlrtErrorWithMessageIdR2018a(sp, &uc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  i = isUnassignedDetection->size[0] * isUnassignedDetection->size[1];
  isUnassignedDetection->size[0] = 1;
  isUnassignedDetection->size[1] = detSelector->size[1];
  emxEnsureCapacity_boolean_T(sp, isUnassignedDetection, i, &xk_emlrtRTEI);
  isUnassignedDetection_data = isUnassignedDetection->data;
  loop_ub = detSelector->size[1];
  for (i = 0; i < loop_ub; i++) {
    isUnassignedDetection_data[i] = false;
  }

  emxInit_int32_T(sp, &sensorDetectionsId, 2, &gl_emlrtRTEI);
  st.site = &lgb_emlrtRSI;
  repmat(&st, N, sensorDetectionsId);
  sensorDetectionsId_data = sensorDetectionsId->data;
  unassignedTrackCounter_size[0] = 1;
  unassignedTrackCounter_size[1] = sensorDetectionsId->size[1];
  loop_ub = sensorDetectionsId->size[1];
  for (i = 0; i < loop_ub; i++) {
    unassignedTrackCounter_data[i] = sensorDetectionsId_data[i];
  }

  st.site = &mgb_emlrtRSI;
  b_st.site = &mgb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  N = detSelector->size[1] - 1;
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= N; loop_ub++) {
    if (detSelector_data[loop_ub]) {
      trueCount++;
    }
  }

  emxInit_real_T(&b_st, &a, 2, &hl_emlrtRTEI, true);
  i = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = trueCount;
  emxEnsureCapacity_real_T(&b_st, a, i, &yk_emlrtRTEI);
  sensorIDs_data = a->data;
  sizes_idx_1 = 0;
  for (loop_ub = 0; loop_ub <= N; loop_ub++) {
    if (detSelector_data[loop_ub]) {
      i = b_obj->pOriginatingSensor->size[1] - 1;
      if (loop_ub > i) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i, &sd_emlrtBCI, &b_st);
      }

      sensorIDs_data[sizes_idx_1] = b_obj->pOriginatingSensor->data[loop_ub];
      sizes_idx_1++;
    }
  }

  emxInit_real_T(&st, &sensorIDs, 2, &fl_emlrtRTEI, true);
  b_st.site = &fj_emlrtRSI;
  b_unique_vector(&b_st, a, sensorIDs);
  sensorIDs_data = sensorIDs->data;
  emxFree_real_T(&st, &a);
  N = sensorIDs->size[1] - 1;
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= N; loop_ub++) {
    if (sensorIDs_data[loop_ub] > 0.0) {
      trueCount++;
    }
  }

  sizes_idx_1 = 0;
  for (loop_ub = 0; loop_ub <= N; loop_ub++) {
    if (sensorIDs_data[loop_ub] > 0.0) {
      if (loop_ub > sensorIDs->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sensorIDs->size[1] - 1,
          &kf_emlrtBCI, (emlrtConstCTX)sp);
      }

      sensorIDs_data[sizes_idx_1] = sensorIDs_data[loop_ub];
      sizes_idx_1++;
    }
  }

  i = sensorIDs->size[0] * sensorIDs->size[1];
  sensorIDs->size[0] = 1;
  sensorIDs->size[1] = trueCount;
  emxEnsureCapacity_real_T(sp, sensorIDs, i, &yk_emlrtRTEI);
  sensorIDs_data = sensorIDs->data;
  clusters->size[0] = 1;
  clusters->size[1] = 0;
  obj->c_pCurrentMaxNumDetectionsPerCl = 0U;
  obj->pCurrentMaxNumTracksPerCluster = 0U;
  st.site = &ngb_emlrtRSI;
  if (trueCount > 2147483646) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  emxInit_real_T(sp, &costMatrix, 2, &yk_emlrtRTEI, true);
  emxInit_int32_T(sp, &unassignedDet, 1, &yk_emlrtRTEI);
  emxInit_struct_T_1x30(&thisSensorClusters);
  emxInit_struct_T(sp, &b_clusters, &el_emlrtRTEI);
  emxInit_boolean_T(sp, &m, 2, &bl_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r, 2, &cl_emlrtRTEI, true);
  for (s = 0; s < trueCount; s++) {
    real_T sensorDetectionsId_tmp;
    int32_T b_unassignedTrackCounter_data[31];
    int8_T i2;
    boolean_T empty_non_axis_sizes;
    if (s + 1 > trueCount) {
      emlrtDynamicBoundsCheckR2012b(s + 1, 1, trueCount, &lf_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    sensorDetectionsId_tmp = sensorIDs_data[s];
    st.site = &ogb_emlrtRSI;
    JPDATracker_selectDetections(&st, obj, sensorDetectionsId_tmp, detSelector,
      sensorDetectionsId);
    sensorDetectionsId_data = sensorDetectionsId->data;
    st.site = &pgb_emlrtRSI;
    i = costMatrix->size[0] * costMatrix->size[1];
    costMatrix->size[0] = sensorDetectionsId->size[1];
    loop_ub = overallCostMatrix->size[0];
    costMatrix->size[1] = overallCostMatrix->size[0];
    emxEnsureCapacity_real_T(&st, costMatrix, i, &al_emlrtRTEI);
    costMatrix_data = costMatrix->data;
    for (i = 0; i < loop_ub; i++) {
      N = sensorDetectionsId->size[1];
      for (i1 = 0; i1 < N; i1++) {
        if ((sensorDetectionsId_data[i1] < 1) || (sensorDetectionsId_data[i1] >
             overallCostMatrix->size[1])) {
          emlrtDynamicBoundsCheckR2012b(sensorDetectionsId_data[i1], 1,
            overallCostMatrix->size[1], &mf_emlrtBCI, &st);
        }

        costMatrix_data[i1 + costMatrix->size[0] * i] = overallCostMatrix_data[i
          + overallCostMatrix->size[0] * (sensorDetectionsId_data[i1] - 1)];
      }
    }

    i = m->size[0] * m->size[1];
    m->size[0] = costMatrix->size[0];
    m->size[1] = costMatrix->size[1];
    emxEnsureCapacity_boolean_T(&st, m, i, &bl_emlrtRTEI);
    m_data = m->data;
    loop_ub = costMatrix->size[0] * costMatrix->size[1];
    for (i = 0; i < loop_ub; i++) {
      m_data[i] = ((!muDoubleScalarIsInf(costMatrix_data[i])) &&
                   (!muDoubleScalarIsNaN(costMatrix_data[i])));
    }

    b_st.site = &tgb_emlrtRSI;
    c_st.site = &hx_emlrtRSI;
    if (sensorDetectionsId->size[1] != 0) {
      N = sensorDetectionsId->size[1];
    } else if ((costMatrix->size[0] != 0) && (costMatrix->size[1] != 0)) {
      N = m->size[0];
    } else {
      N = 0;
      if (m->size[0] > 0) {
        N = m->size[0];
      }
    }

    d_st.site = &ix_emlrtRSI;
    if ((sensorDetectionsId->size[1] != N) && (sensorDetectionsId->size[1] != 0))
    {
      emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if ((m->size[0] != N) && ((costMatrix->size[0] != 0) && (costMatrix->size[1]
          != 0))) {
      emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    empty_non_axis_sizes = (N == 0);
    if (empty_non_axis_sizes || (sensorDetectionsId->size[1] != 0)) {
      i2 = 1;
    } else {
      i2 = 0;
    }

    if (empty_non_axis_sizes || ((costMatrix->size[0] != 0) && (costMatrix->
          size[1] != 0))) {
      sizes_idx_1 = m->size[1];
    } else {
      sizes_idx_1 = 0;
    }

    i = r->size[0] * r->size[1];
    r->size[0] = N;
    r->size[1] = i2 + sizes_idx_1;
    emxEnsureCapacity_boolean_T(sp, r, i, &cl_emlrtRTEI);
    r1 = r->data;
    loop_ub = i2;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < N; i1++) {
        r1[i1] = true;
      }
    }

    for (i = 0; i < sizes_idx_1; i++) {
      for (i1 = 0; i1 < N; i1++) {
        r1[i1 + r->size[0] * (i + i2)] = m_data[i1 + N * i];
      }
    }

    if (s + 1 > trueCount) {
      emlrtDynamicBoundsCheckR2012b(s + 1, 1, trueCount, &nf_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    st.site = &qgb_emlrtRSI;
    JPDATracker_clusterDetections(&st, obj, r, sensorDetectionsId_tmp,
      detSelector, unassignedDet, unassignedTrack_data, unassignedTrack_size,
      thisSensorClusters.data, thisSensorClusters.size);
    unassignedDet_data = unassignedDet->data;
    loop_ub = unassignedDet->size[0];
    for (i = 0; i < loop_ub; i++) {
      if ((unassignedDet_data[i] < 1) || (unassignedDet_data[i] >
           sensorDetectionsId->size[1])) {
        emlrtDynamicBoundsCheckR2012b(unassignedDet_data[i], 1,
          sensorDetectionsId->size[1], &of_emlrtBCI, (emlrtConstCTX)sp);
      }
    }

    loop_ub = unassignedDet->size[0];
    for (i = 0; i < loop_ub; i++) {
      i1 = sensorDetectionsId_data[unassignedDet_data[i] - 1];
      if ((i1 < 1) || (i1 > isUnassignedDetection->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, isUnassignedDetection->size[1],
          &pf_emlrtBCI, (emlrtConstCTX)sp);
      }

      isUnassignedDetection_data[i1 - 1] = true;
    }

    loop_ub = unassignedTrack_size[1];
    for (i = 0; i < loop_ub; i++) {
      i1 = unassignedTrack_data[i];
      N = unassignedTrackCounter_size[1];
      if ((i1 < 1) || (i1 > N)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, N, &qf_emlrtBCI, (emlrtConstCTX)sp);
      }
    }

    loop_ub = unassignedTrack_size[1];
    for (i = 0; i < loop_ub; i++) {
      b_unassignedTrackCounter_data[i] =
        unassignedTrackCounter_data[unassignedTrack_data[i] - 1] + 1;
    }

    for (i = 0; i < loop_ub; i++) {
      i1 = unassignedTrack_data[i];
      N = unassignedTrackCounter_size[1];
      if ((i1 < 1) || (i1 > N)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, N, &rf_emlrtBCI, (emlrtConstCTX)sp);
      }

      unassignedTrackCounter_data[i1 - 1] = b_unassignedTrackCounter_data[i];
    }

    i = b_clusters->size[0] * b_clusters->size[1];
    b_clusters->size[0] = 1;
    loop_ub = clusters->size[1];
    b_clusters->size[1] = clusters->size[1] + thisSensorClusters.size[1];
    emxEnsureCapacity_struct_T(sp, b_clusters, i, &dl_emlrtRTEI);
    b_clusters_data = b_clusters->data;
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_struct_T(sp, &b_clusters_data[i], &clusters_data[i],
        &dl_emlrtRTEI);
    }

    loop_ub = thisSensorClusters.size[1];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_struct_T(sp, &b_clusters_data[i + clusters->size[1]],
        &thisSensorClusters.data[i], &dl_emlrtRTEI);
    }

    if (b_clusters->size[1] > 600) {
      emlrtDimSizeGeqCheckR2012b(600, b_clusters->size[1], &v_emlrtECI,
        (emlrtCTX)sp);
    }

    i = clusters->size[0] * clusters->size[1];
    clusters->size[0] = 1;
    clusters->size[1] = b_clusters->size[1];
    emxEnsureCapacity_struct_T(sp, clusters, i, &el_emlrtRTEI);
    clusters_data = clusters->data;
    loop_ub = b_clusters->size[1];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_struct_T(sp, &clusters_data[i], &b_clusters_data[i],
        &el_emlrtRTEI);
    }
  }

  emxFree_boolean_T(sp, &r);
  emxFree_boolean_T(sp, &m);
  emxFree_struct_T(sp, &b_clusters);
  emxFree_struct_T_1x30(sp, &thisSensorClusters);
  emxFree_int32_T(sp, &unassignedDet);
  emxFree_real_T(sp, &costMatrix);
  emxFree_int32_T(sp, &sensorDetectionsId);
  emxFree_real_T(sp, &sensorIDs);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void JPDATracker_deleteOldTracks(const emlrtStack *sp, trackerJPDA *obj,
  uint32_T delTrIDs_data[], int32_T delTrIDs_size[2])
{
  d_matlabshared_tracking_interna *temp;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T *x;
  emxArray_int32_T *y;
  trackHistoryLogic *b_obj;
  int32_T NumberOfTracks;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T ii_size_idx_1;
  int32_T k;
  int32_T loop_ub;
  int32_T nz;
  int32_T *y_data;
  int8_T ii_data[30];
  boolean_T toDelete[30];
  boolean_T exitg1;
  boolean_T *x_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  NumberOfTracks = obj->pNumLiveTracks;
  if (NumberOfTracks > 30) {
    emlrtErrorWithMessageIdR2018a(sp, &hd_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  emxInit_int32_T(sp, &y, 2, &yn_emlrtRTEI);
  st.site = &job_emlrtRSI;
  b_st.site = &yab_emlrtRSI;
  c_st.site = &abb_emlrtRSI;
  eml_integer_colon_dispatcher(&c_st, NumberOfTracks, y);
  y_data = y->data;
  for (i = 0; i < 30; i++) {
    toDelete[i] = false;
  }

  emxInit_boolean_T(sp, &x, 2, &xn_emlrtRTEI, true);
  for (b_i = NumberOfTracks; b_i >= 1; b_i--) {
    if (b_i > y->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, y->size[1], &gi_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    i = y_data[b_i - 1];
    if ((i < 1) || (i > 30)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 30, &fi_emlrtBCI, (emlrtConstCTX)sp);
    }

    if (obj->pWasDetectable[i - 1]) {
      uint32_T age;
      boolean_T tentativeTrack;
      st.site = &kob_emlrtRSI;
      if (b_i > y->size[1]) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, y->size[1], &hi_emlrtBCI, &st);
      }

      temp = obj->pTracksList[i - 1];
      b_st.site = &mob_emlrtRSI;
      b_obj = temp->TrackLogic;
      tentativeTrack = !temp->IsConfirmed;
      age = temp->pAge;
      if (b_obj->pIsFirstUpdate) {
        if (b_i > y->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, y->size[1], &ii_emlrtBCI, &b_st);
        }

        toDelete[i - 1] = false;
      } else if (!tentativeTrack) {
        if (age > 10U) {
          boolean_T b_x[10];
          for (i1 = 0; i1 < 10; i1++) {
            b_x[i1] = !b_obj->pRecentHistory[i1];
          }

          nz = b_x[0];
          for (k = 0; k < 9; k++) {
            nz += b_x[k + 1];
          }

          if (b_i > y->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, y->size[1], &ii_emlrtBCI,
              &b_st);
          }

          toDelete[i - 1] = (nz >= 3);
        } else {
          if (age < 1U) {
            loop_ub = 0;
          } else {
            loop_ub = (int32_T)age;
          }

          c_st.site = &nob_emlrtRSI;
          i1 = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = loop_ub;
          emxEnsureCapacity_boolean_T(&c_st, x, i1, &xn_emlrtRTEI);
          x_data = x->data;
          for (i1 = 0; i1 < loop_ub; i1++) {
            x_data[i1] = !b_obj->pRecentHistory[i1];
          }

          d_st.site = &uh_emlrtRSI;
          e_st.site = &vh_emlrtRSI;
          nz = combineVectorElements(&e_st, x);
          if (b_i > y->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, y->size[1], &ii_emlrtBCI,
              &b_st);
          }

          if (nz < 0) {
            nz = 0;
          }

          toDelete[i - 1] = ((uint32_T)nz >= 3U);
        }
      } else {
        uint32_T b_qY;
        uint32_T qY;
        boolean_T b_x[10];
        for (i1 = 0; i1 < 10; i1++) {
          b_x[i1] = b_obj->pRecentHistory[i1];
        }

        nz = b_x[0];
        for (k = 0; k < 9; k++) {
          nz += b_x[k + 1];
        }

        if (b_i > y->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, y->size[1], &ii_emlrtBCI, &b_st);
        }

        if (nz < 0) {
          nz = 0;
        }

        qY = 7U - (uint32_T)nz;
        if (7U - (uint32_T)nz > 7U) {
          qY = 0U;
        }

        b_qY = 10U - age;
        if (10U - age > 10U) {
          b_qY = 0U;
        }

        toDelete[i - 1] = (qY > b_qY);
      }
    }
  }

  emxFree_boolean_T(sp, &x);
  emxFree_int32_T(sp, &y);
  NumberOfTracks = 0;
  for (b_i = 0; b_i < 30; b_i++) {
    if (toDelete[b_i]) {
      NumberOfTracks++;
    }
  }

  delTrIDs_size[0] = 1;
  delTrIDs_size[1] = NumberOfTracks;
  NumberOfTracks = 0;
  for (b_i = 0; b_i < 30; b_i++) {
    if (toDelete[b_i]) {
      delTrIDs_data[NumberOfTracks] = obj->pTrackIDs[b_i];
      NumberOfTracks++;
    }
  }

  st.site = &lob_emlrtRSI;
  nz = toDelete[0];
  for (k = 0; k < 29; k++) {
    nz += toDelete[k + 1];
  }

  NumberOfTracks = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 30)) {
    if (toDelete[k]) {
      NumberOfTracks++;
      ii_data[NumberOfTracks - 1] = (int8_T)(k + 1);
      if (NumberOfTracks >= 30) {
        exitg1 = true;
      } else {
        k++;
      }
    } else {
      k++;
    }
  }

  if (NumberOfTracks < 1) {
    ii_size_idx_1 = 0;
  } else {
    ii_size_idx_1 = NumberOfTracks;
  }

  b_st.site = &qob_emlrtRSI;
  for (b_i = 0; b_i < nz; b_i++) {
    if (b_i + 1 > ii_size_idx_1) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size_idx_1, &ji_emlrtBCI, &st);
    }

    b_st.site = &pob_emlrtRSI;
    ObjectTrack_nullify(&b_st, obj->pTracksList[ii_data[b_i] - 1]);
  }

  for (b_i = nz; b_i >= 1; b_i--) {
    int32_T temp_tmp;
    uint32_T b_tmp_data[31];
    boolean_T tmp_data[31];
    if (b_i > ii_size_idx_1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, ii_size_idx_1, &bi_emlrtBCI, &st);
    }

    temp_tmp = ii_data[b_i - 1];
    temp = obj->pTracksList[temp_tmp - 1];
    k = temp_tmp + 1;
    NumberOfTracks = obj->pNumLiveTracks;
    b_st.site = &oob_emlrtRSI;
    if ((temp_tmp + 1 <= NumberOfTracks) && (NumberOfTracks > 2147483646)) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (loop_ub = k; loop_ub <= NumberOfTracks; loop_ub++) {
      if (loop_ub - 1 > 29) {
        emlrtDynamicBoundsCheckR2012b(loop_ub - 1, 0, 29, &ki_emlrtBCI, &st);
      }

      if (loop_ub - 2 > 29) {
        emlrtDynamicBoundsCheckR2012b(loop_ub - 2, 0, 29, &li_emlrtBCI, &st);
      }

      obj->pTracksList[loop_ub - 2] = obj->pTracksList[loop_ub - 1];
    }

    i = obj->pNumLiveTracks - 1;
    if ((i < 0) || (i > 29)) {
      emlrtDynamicBoundsCheckR2012b(i, 0, 29, &ei_emlrtBCI, &st);
    }

    obj->pTracksList[i] = temp;
    obj->pNumLiveTracks--;
    if (temp_tmp + 1 > 30) {
      i = 0;
      i1 = 0;
    } else {
      if (temp_tmp + 1 > 30) {
        emlrtDynamicBoundsCheckR2012b(31, 1, 30, &ci_emlrtBCI, &st);
      }

      i = temp_tmp;
      i1 = 30;
    }

    loop_ub = i1 - i;
    k = loop_ub + 1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      tmp_data[i1] = obj->pConfirmedTracks[i + i1];
    }

    tmp_data[loop_ub] = false;
    if (31 - temp_tmp != loop_ub + 1) {
      emlrtSubAssignSizeCheck1dR2017a(31 - temp_tmp, loop_ub + 1, &hb_emlrtECI,
        &st);
    }

    for (i = 0; i < k; i++) {
      obj->pConfirmedTracks[(temp_tmp + i) - 1] = tmp_data[i];
    }

    if (temp_tmp + 1 > 30) {
      i = 0;
      i1 = 0;
    } else {
      if (temp_tmp + 1 > 30) {
        emlrtDynamicBoundsCheckR2012b(31, 1, 30, &di_emlrtBCI, &st);
      }

      i = temp_tmp;
      i1 = 30;
    }

    loop_ub = i1 - i;
    k = loop_ub + 1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_tmp_data[i1] = obj->pTrackIDs[i + i1];
    }

    b_tmp_data[loop_ub] = 0U;
    if (31 - temp_tmp != loop_ub + 1) {
      emlrtSubAssignSizeCheck1dR2017a(31 - temp_tmp, loop_ub + 1, &ib_emlrtECI,
        &st);
    }

    for (i = 0; i < k; i++) {
      obj->pTrackIDs[(temp_tmp + i) - 1] = b_tmp_data[i];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void JPDATracker_findTracksByIDs(const emlrtStack *sp, const trackerJPDA *
  obj, const uint32_T trackIDs_data[], const int32_T trackIDs_size[2], uint32_T
  indices_data[], int32_T indices_size[2])
{
  emlrtStack st;
  int32_T b_i;
  int32_T b_tmp_data;
  int32_T i;
  uint32_T tmp_data;
  st.prev = sp;
  st.tls = sp->tls;
  i = trackIDs_size[1];
  indices_size[0] = 1;
  indices_size[1] = trackIDs_size[1];
  if (trackIDs_size[1] - 1 >= 0) {
  }

  for (b_i = 0; b_i < i; b_i++) {
    int32_T tmp_size[2];
    uint32_T trackIDs;
    boolean_T in[30];
    st.site = &jjb_emlrtRSI;
    if (b_i + 1 > trackIDs_size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, trackIDs_size[1], &hg_emlrtBCI,
        &st);
    }

    trackIDs = trackIDs_data[b_i];
    for (b_tmp_data = 0; b_tmp_data < 30; b_tmp_data++) {
      in[b_tmp_data] = (trackIDs == obj->pTrackIDs[b_tmp_data]);
    }

    c_eml_find(in, (int32_T *)&b_tmp_data, tmp_size);
    if (tmp_size[1] - 1 >= 0) {
      if (b_tmp_data < 0) {
        b_tmp_data = 0;
      }

      tmp_data = (uint32_T)b_tmp_data;
    }

    if (tmp_size[1] != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, 0, &y_emlrtECI, (emlrtConstCTX)sp);
    }

    if (b_i + 1 > indices_size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, indices_size[1], &ig_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    indices_data[b_i] = tmp_data;
  }
}

static void JPDATracker_getCostMatrix(const emlrtStack *sp, trackerJPDA *obj,
  const emxArray_objectDetection *dets, emxArray_real_T *cost)
{
  static const int8_T b_inSize[8] = { 1, 30, 1, 1, 1, 1, 1, 1 };

  static const int8_T b_iv[8] = { 1, 30, 1, 1, 1, 1, 1, 1 };

  static const int8_T b_iv1[8] = { 1, 30, 1, 1, 1, 1, 1, 1 };

  c_matlabshared_tracking_interna *c_obj;
  d_matlabshared_tracking_interna *d_obj[30];
  d_matlabshared_tracking_interna *e_obj[30];
  d_matlabshared_tracking_interna *f_obj[30];
  d_matlabshared_tracking_interna *track;
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_boolean_T *toCalculate;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_int32_T *r;
  emxArray_int32_T *r4;
  emxArray_int32_T *r7;
  emxArray_int32_T *r8;
  emxArray_real_T *r2;
  emxArray_real_T *r5;
  emxArray_real_T *r9;
  emxArray_uint32_T *b_detIndices;
  emxArray_uint32_T *detIndices;
  const objectDetection *dets_data;
  real_T b_expl_temp[9];
  real_T *cost_data;
  real_T *r12;
  real_T *r3;
  real_T *r6;
  int32_T b_iv2[4];
  int32_T b_n[2];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T m;
  int32_T n;
  int32_T *ii_data;
  int32_T *r1;
  int32_T *r10;
  int32_T *r11;
  uint32_T inSize[8];
  uint32_T *b_detIndices_data;
  uint32_T *detIndices_data;
  boolean_T anyInputSizeChanged;
  boolean_T exitg1;
  boolean_T *toCalculate_data;
  boolean_T *x_data;
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
  dets_data = dets->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &fbb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  loop_ub = b_obj->pNumDetections;
  if (loop_ub < 1) {
    loop_ub = 0;
  } else {
    i = b_obj->pIsOOSM->size[1];
    if (i < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &ee_emlrtBCI, &st);
    }

    i = b_obj->pIsOOSM->size[1];
    if (loop_ub > i) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &de_emlrtBCI, &st);
    }
  }

  b_st.site = &gbb_emlrtRSI;
  emxInit_boolean_T(&b_st, &x, 2, &uj_emlrtRTEI, true);
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(&b_st, x, i, &uj_emlrtRTEI);
  x_data = x->data;
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = !b_obj->pIsOOSM->data[i];
  }

  emxInit_int32_T(&b_st, &ii, 2, &qe_emlrtRTEI);
  c_st.site = &cg_emlrtRSI;
  b_eml_find(&c_st, x, ii);
  ii_data = ii->data;
  emxInit_uint32_T(&st, &detIndices, 2, &vj_emlrtRTEI, true);
  i = detIndices->size[0] * detIndices->size[1];
  detIndices->size[0] = 1;
  detIndices->size[1] = ii->size[1];
  emxEnsureCapacity_uint32_T(&st, detIndices, i, &vj_emlrtRTEI);
  detIndices_data = detIndices->data;
  loop_ub = ii->size[1];
  for (i = 0; i < loop_ub; i++) {
    i1 = ii_data[i];
    if (i1 < 0) {
      i1 = 0;
    }

    detIndices_data[i] = (uint32_T)i1;
  }

  n = obj->pNumLiveTracks;
  st.site = &ebb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  m = b_obj->pNumDetections;
  if (n > 30) {
    emlrtErrorWithMessageIdR2018a(sp, &rc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (n < 0) {
    emlrtNonNegativeCheckR2012b(n, &i_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (m < 0) {
    emlrtNonNegativeCheckR2012b(m, &j_emlrtDCI, (emlrtConstCTX)sp);
  }

  i = cost->size[0] * cost->size[1];
  cost->size[0] = n;
  cost->size[1] = m;
  emxEnsureCapacity_real_T(sp, cost, i, &wj_emlrtRTEI);
  cost_data = cost->data;
  loop_ub = n * m;
  for (i = 0; i < loop_ub; i++) {
    cost_data[i] = 0.0;
  }

  emxInit_int32_T(sp, &r, 1, &hk_emlrtRTEI);
  i = r->size[0];
  r->size[0] = detIndices->size[1];
  emxEnsureCapacity_int32_T(sp, r, i, &xj_emlrtRTEI);
  r1 = r->data;
  loop_ub = detIndices->size[1];
  for (i = 0; i < loop_ub; i++) {
    if (((int32_T)detIndices_data[i] < 1) || ((int32_T)detIndices_data[i] > m))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)detIndices_data[i], 1, m,
        &fe_emlrtBCI, (emlrtConstCTX)sp);
    }

    r1[i] = (int32_T)detIndices_data[i] - 1;
  }

  st.site = &dbb_emlrtRSI;
  c_obj = &obj->cCostCalculator;
  for (i = 0; i < 30; i++) {
    e_obj[i] = obj->pTracksList[i];
  }

  for (i = 0; i < 30; i++) {
    d_obj[i] = e_obj[i];
  }

  for (i = 0; i < 30; i++) {
    e_obj[i] = d_obj[i];
  }

  if (obj->cCostCalculator.isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(&st, &nb_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen",
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (obj->cCostCalculator.isInitialized != 1) {
    cell_wrap_3 varSizes[4];
    b_st.site = &lp_emlrtRSI;
    c_st.site = &mp_emlrtRSI;
    if (obj->cCostCalculator.isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &qb_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    obj->cCostCalculator.isInitialized = 1;
    d_st.site = &np_emlrtRSI;
    for (i = 0; i < 8; i++) {
      varSizes[0].f1[i] = (uint32_T)b_iv1[i];
    }

    varSizes[1].f1[0] = (uint32_T)dets->size[0];
    varSizes[1].f1[1] = (uint32_T)dets->size[1];
    for (i = 0; i < 6; i++) {
      varSizes[1].f1[i + 2] = 1U;
    }

    for (i = 0; i < 8; i++) {
      varSizes[2].f1[i] = 1U;
    }

    varSizes[3].f1[0] = 1U;
    varSizes[3].f1[1] = (uint32_T)detIndices->size[1];
    for (i = 0; i < 6; i++) {
      varSizes[3].f1[i + 2] = 1U;
    }

    obj->cCostCalculator.inputVarSize[0] = varSizes[0];
    obj->cCostCalculator.inputVarSize[1] = varSizes[1];
    obj->cCostCalculator.inputVarSize[2] = varSizes[2];
    obj->cCostCalculator.inputVarSize[3] = varSizes[3];
    d_st.site = &np_emlrtRSI;
    c_AssignmentCostCalculator_vali(&d_st, n);
    d_st.site = &np_emlrtRSI;
    i = dets->size[0] * dets->size[1] - 1;
    if (i < 0) {
      emlrtDynamicBoundsCheckR2012b(0, 0, i, &ae_emlrtBCI, &d_st);
    }

    e_st.site = &fy_emlrtRSI;
  }

  b_st.site = &lp_emlrtRSI;
  anyInputSizeChanged = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (c_obj->inputVarSize[0].f1[k] != (uint32_T)b_iv[k]) {
      anyInputSizeChanged = true;
      for (i = 0; i < 8; i++) {
        c_obj->inputVarSize[0].f1[i] = (uint32_T)b_inSize[i];
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  inSize[0] = (uint32_T)dets->size[0];
  inSize[1] = (uint32_T)dets->size[1];
  for (i = 0; i < 6; i++) {
    inSize[i + 2] = 1U;
  }

  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (c_obj->inputVarSize[1].f1[k] != inSize[k]) {
      anyInputSizeChanged = true;
      for (i = 0; i < 8; i++) {
        c_obj->inputVarSize[1].f1[i] = inSize[i];
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (c_obj->inputVarSize[2].f1[k] != 1U) {
      anyInputSizeChanged = true;
      for (i = 0; i < 8; i++) {
        c_obj->inputVarSize[2].f1[i] = 1U;
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  inSize[0] = 1U;
  inSize[1] = (uint32_T)detIndices->size[1];
  for (i = 0; i < 6; i++) {
    inSize[i + 2] = 1U;
  }

  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (c_obj->inputVarSize[3].f1[k] != inSize[k]) {
      anyInputSizeChanged = true;
      for (i = 0; i < 8; i++) {
        c_obj->inputVarSize[3].f1[i] = inSize[i];
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  if (anyInputSizeChanged) {
    b_st.site = &lp_emlrtRSI;
    c_AssignmentCostCalculator_vali(&b_st, n);
  }

  b_st.site = &lp_emlrtRSI;
  emxInit_real_T(&b_st, &r2, 2, &hk_emlrtRTEI, true);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = n;
  r2->size[1] = detIndices->size[1];
  emxEnsureCapacity_real_T(&b_st, r2, i, &yj_emlrtRTEI);
  r3 = r2->data;
  loop_ub = n * detIndices->size[1];
  for (i = 0; i < loop_ub; i++) {
    r3[i] = rtInf;
  }

  emxInit_boolean_T(&b_st, &toCalculate, 2, &ik_emlrtRTEI, true);
  for (i2 = 0; i2 < 30; i2++) {
    f_obj[i2] = e_obj[i2];
  }

  c_st.site = &ibb_emlrtRSI;
  c_AssignmentCostCalculator_find(&c_st, f_obj, dets, n, detIndices, toCalculate);
  toCalculate_data = toCalculate->data;
  c_st.site = &jbb_emlrtRSI;
  emxInit_int32_T(&b_st, &r4, 1, &jk_emlrtRTEI);
  emxInit_real_T(&b_st, &r5, 2, &jk_emlrtRTEI, true);
  r6 = r5->data;
  emxInit_int32_T(&b_st, &r7, 2, &kk_emlrtRTEI);
  emxInit_int32_T(&b_st, &r8, 1, &gk_emlrtRTEI);
  emxInit_uint32_T(&b_st, &b_detIndices, 2, &dk_emlrtRTEI, true);
  emxInit_real_T(&b_st, &r9, 2, &gk_emlrtRTEI, true);
  for (j = 0; j < n; j++) {
    boolean_T guard1;
    track = e_obj[j];
    if ((j + 1 < 1) || (j + 1 > toCalculate->size[0])) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, toCalculate->size[0], &ce_emlrtBCI,
        &b_st);
    }

    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    loop_ub = toCalculate->size[1];
    x->size[1] = toCalculate->size[1];
    emxEnsureCapacity_boolean_T(&b_st, x, i, &ak_emlrtRTEI);
    x_data = x->data;
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = toCalculate_data[j + toCalculate->size[0] * i];
    }

    k = x->size[1] - 1;
    m = 0;
    for (loop_ub = 0; loop_ub <= k; loop_ub++) {
      if (x_data[loop_ub]) {
        m++;
      }
    }

    i = r7->size[0] * r7->size[1];
    r7->size[0] = 1;
    r7->size[1] = m;
    emxEnsureCapacity_int32_T(&b_st, r7, i, &bk_emlrtRTEI);
    r10 = r7->data;
    m = 0;
    for (loop_ub = 0; loop_ub <= k; loop_ub++) {
      if (x_data[loop_ub]) {
        r10[m] = loop_ub;
        m++;
      }
    }

    loop_ub = r7->size[1];
    for (i = 0; i < loop_ub; i++) {
      if ((r10[i] < 0) || (r10[i] > detIndices->size[1] - 1)) {
        emlrtDynamicBoundsCheckR2012b(r10[i], 0, detIndices->size[1] - 1,
          &he_emlrtBCI, &b_st);
      }
    }

    if ((j + 1 < 1) || (j + 1 > r2->size[0])) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, r2->size[0], &be_emlrtBCI, &b_st);
    }

    loop_ub = r7->size[1];
    i = r4->size[0];
    r4->size[0] = r7->size[1];
    emxEnsureCapacity_int32_T(&b_st, r4, i, &ck_emlrtRTEI);
    r11 = r4->data;
    for (i = 0; i < loop_ub; i++) {
      if ((r10[i] < 0) || (r10[i] > r2->size[1] - 1)) {
        emlrtDynamicBoundsCheckR2012b(r10[i], 0, r2->size[1] - 1, &ie_emlrtBCI,
          &b_st);
      }

      r11[i] = r10[i];
    }

    c_st.site = &kbb_emlrtRSI;
    guard1 = false;
    if ((dets->size[0] == 0) || (dets->size[1] == 0)) {
      guard1 = true;
    } else {
      loop_ub = r7->size[1];
      if (r7->size[1] == 0) {
        guard1 = true;
      } else {
        real_T trackTime;
        d_st.site = &ncb_emlrtRSI;
        i = b_detIndices->size[0] * b_detIndices->size[1];
        b_detIndices->size[0] = 1;
        b_detIndices->size[1] = r7->size[1];
        emxEnsureCapacity_uint32_T(&d_st, b_detIndices, i, &dk_emlrtRTEI);
        b_detIndices_data = b_detIndices->data;
        for (i = 0; i < loop_ub; i++) {
          b_detIndices_data[i] = detIndices_data[r10[i]];
        }

        e_st.site = &ocb_emlrtRSI;
        c_ObjectTrack_sortDetectionsByT(&e_st, dets, b_detIndices, ii);
        ii_data = ii->data;
        e_st.site = &pcb_emlrtRSI;
        loop_ub = ii->size[1];
        for (i = 0; i < loop_ub; i++) {
          if ((ii_data[i] < 1) || (ii_data[i] > r7->size[1])) {
            emlrtDynamicBoundsCheckR2012b(ii_data[i], 1, r7->size[1],
              &je_emlrtBCI, &e_st);
          }
        }

        i = r5->size[0] * r5->size[1];
        r5->size[0] = 1;
        r5->size[1] = ii->size[1];
        emxEnsureCapacity_real_T(&e_st, r5, i, &ek_emlrtRTEI);
        r6 = r5->data;
        loop_ub = ii->size[1];
        for (i = 0; i < loop_ub; i++) {
          r6[i] = rtInf;
        }

        trackTime = e_obj[j]->Time;
        f_st.site = &tcb_emlrtRSI;
        trackingEKF_sync(&f_st, e_obj[j]->pDistanceFilter, e_obj[j]->Filter);
        i = ii->size[1];
        for (k = 0; k < i; k++) {
          objectDetection expl_temp;
          if (k + 1 > ii->size[1]) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, ii->size[1], &yd_emlrtBCI,
              &e_st);
          }

          i1 = dets->size[0] * dets->size[1] - 1;
          m = (int32_T)detIndices_data[r10[ii_data[k] - 1]] - 1;
          if ((m < 0) || (m > i1)) {
            emlrtDynamicBoundsCheckR2012b(m, 0, i1, &ke_emlrtBCI, &e_st);
          }

          expl_temp = dets_data[m];
          memcpy(&b_expl_temp[0], &expl_temp.pMeasurementNoise[0], 9U * sizeof
                 (real_T));
          f_st.site = &ucb_emlrtRSI;
          c_ExtendedKalmanFilter_set_Meas(&f_st, track->pDistanceFilter,
            b_expl_temp);
          if ((track->ObjectClassID == 0.0) || (dets_data[m].ObjectClassID ==
               0.0) || (track->ObjectClassID == dets_data[m].ObjectClassID)) {
            trackTime = expl_temp.Time - trackTime;
            if (trackTime > 0.0) {
              f_st.site = &vcb_emlrtRSI;
              predictTrackFilter(&f_st, track->pDistanceFilter, trackTime);
            }

            trackTime = expl_temp.Time;
            if (k + 1 > r5->size[1]) {
              emlrtDynamicBoundsCheckR2012b(k + 1, 1, r5->size[1], &me_emlrtBCI,
                &e_st);
            }

            f_st.site = &wcb_emlrtRSI;
            r6[k] = c_ObjectTrack_calcCostOneDetect(&f_st, track, dets_data
              [(int32_T)detIndices_data[r10[ii_data[k] - 1]] - 1].Measurement);
          }
        }

        i = r5->size[1];
        i1 = r8->size[0];
        r8->size[0] = ii->size[1];
        emxEnsureCapacity_int32_T(&d_st, r8, i1, &fk_emlrtRTEI);
        r10 = r8->data;
        loop_ub = ii->size[1];
        m = (ii->size[1] / 4) << 2;
        k = m - 4;
        for (i1 = 0; i1 <= k; i1 += 4) {
          __m128i r13;
          if ((ii_data[i1] < 1) || (ii_data[i1] > i)) {
            emlrtDynamicBoundsCheckR2012b(ii_data[i1], 1, i, &le_emlrtBCI, &d_st);
          }

          b_iv2[0] = ii_data[i1];
          if ((ii_data[i1 + 1] < 1) || (ii_data[i1 + 1] > i)) {
            emlrtDynamicBoundsCheckR2012b(ii_data[i1 + 1], 1, i, &le_emlrtBCI,
              &d_st);
          }

          b_iv2[1] = ii_data[i1 + 1];
          if ((ii_data[i1 + 2] < 1) || (ii_data[i1 + 2] > i)) {
            emlrtDynamicBoundsCheckR2012b(ii_data[i1 + 2], 1, i, &le_emlrtBCI,
              &d_st);
          }

          b_iv2[2] = ii_data[i1 + 2];
          if ((ii_data[i1 + 3] < 1) || (ii_data[i1 + 3] > i)) {
            emlrtDynamicBoundsCheckR2012b(ii_data[i1 + 3], 1, i, &le_emlrtBCI,
              &d_st);
          }

          b_iv2[3] = ii_data[i1 + 3];
          r13 = _mm_loadu_si128((const __m128i *)&b_iv2[0]);
          _mm_storeu_si128((__m128i *)&r10[i1], _mm_sub_epi32(r13,
            _mm_set1_epi32(1)));
        }

        for (i1 = m; i1 < loop_ub; i1++) {
          if ((ii_data[i1] < 1) || (ii_data[i1] > i)) {
            emlrtDynamicBoundsCheckR2012b(ii_data[i1], 1, i, &le_emlrtBCI, &d_st);
          }

          r10[i1] = ii_data[i1] - 1;
        }

        b_n[0] = 1;
        b_n[1] = r8->size[0];
        emlrtSubAssignSizeCheckR2012b(&b_n[0], 2, &r5->size[0], 2, &j_emlrtECI,
          &d_st);
        i = r9->size[0] * r9->size[1];
        r9->size[0] = 1;
        r9->size[1] = r8->size[0];
        emxEnsureCapacity_real_T(&d_st, r9, i, &gk_emlrtRTEI);
        r12 = r9->data;
        loop_ub = r8->size[0];
        for (i = 0; i < loop_ub; i++) {
          r12[i] = r6[i];
        }

        loop_ub = r9->size[1];
        for (i = 0; i < loop_ub; i++) {
          r6[r10[i]] = r12[i];
        }
      }
    }

    if (guard1) {
      d_st.site = &mcb_emlrtRSI;
      e_st.site = &gy_emlrtRSI;
      r5->size[0] = 1;
      r5->size[1] = 0;
    }

    b_n[0] = 1;
    b_n[1] = r4->size[0];
    emlrtSubAssignSizeCheckR2012b(&b_n[0], 2, &r5->size[0], 2, &k_emlrtECI,
      &b_st);
    loop_ub = r4->size[0];
    for (i = 0; i < loop_ub; i++) {
      r3[j + r2->size[0] * r11[i]] = r6[i];
    }
  }

  emxFree_real_T(&b_st, &r9);
  emxFree_uint32_T(&b_st, &b_detIndices);
  emxFree_int32_T(&b_st, &r8);
  emxFree_int32_T(&b_st, &r7);
  emxFree_real_T(&b_st, &r5);
  emxFree_int32_T(&b_st, &r4);
  emxFree_boolean_T(&b_st, &toCalculate);
  emxFree_int32_T(&b_st, &ii);
  emxFree_boolean_T(&b_st, &x);
  emxFree_uint32_T(&b_st, &detIndices);
  b_n[0] = n;
  b_n[1] = r->size[0];
  emlrtSubAssignSizeCheckR2012b(&b_n[0], 2, &r2->size[0], 2, &l_emlrtECI,
    (emlrtCTX)sp);
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < n; i1++) {
      cost_data[i1 + cost->size[0] * r1[i]] = r3[i1 + n * i];
    }
  }

  emxFree_real_T(sp, &r2);
  emxFree_int32_T(sp, &r);
  k = cost->size[0] * cost->size[1] - 1;
  for (loop_ub = 0; loop_ub <= k; loop_ub++) {
    if (cost_data[loop_ub] > 50.0) {
      i = cost->size[0] * cost->size[1] - 1;
      if (loop_ub > i) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i, &ge_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      cost_data[loop_ub] = rtInf;
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void JPDATracker_initializeTracks(const emlrtStack *sp, trackerJPDA *obj,
  emxArray_int32_T *OverallUnassigned, const emxArray_objectDetection *dets,
  uint32_T newTrackIDs_data[], int32_T newTrackIDs_size[2])
{
  d_matlabshared_tracking_interna *b_track;
  d_matlabshared_tracking_interna *track;
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T *r;
  emxArray_boolean_T *r3;
  emxArray_int32_T *iidx;
  emxArray_int32_T *m;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *sorting;
  emxArray_real_T *costMatrix;
  emxArray_real_T *detTimes;
  emxArray_real_T *origSen;
  emxArray_real_T *sensorsInUnassigned;
  const objectDetection *dets_data;
  objectDetection b_dets;
  trackHistoryLogic *c_obj;
  trackingEKF filter;
  real_T b_dets_data[9];
  real_T *costMatrix_data;
  real_T *origSen_data;
  real_T *sensorsInUnassigned_data;
  int32_T ind_data[20];
  int32_T b_iv[4];
  int32_T ind_size[2];
  int32_T b_i;
  int32_T end_tmp;
  int32_T i;
  int32_T i1;
  int32_T lastTrackInd;
  int32_T loop_ub;
  int32_T *OverallUnassigned_data;
  int32_T *iidx_data;
  int32_T *r5;
  int32_T *r7;
  int32_T *sorting_data;
  boolean_T *r4;
  boolean_T *r6;
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
  dets_data = dets->data;
  OverallUnassigned_data = OverallUnassigned->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  lastTrackInd = obj->pNumLiveTracks + 1;
  emxInit_real_T(sp, &costMatrix, 2, &kn_emlrtRTEI, true);
  emxInit_real_T(sp, &origSen, 2, &ln_emlrtRTEI, true);
  emxInit_real_T(sp, &sensorsInUnassigned, 2, &mn_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r, 2, &vn_emlrtRTEI, true);
  emxInit_int32_T(sp, &r1, 2, &wn_emlrtRTEI);
  emxInit_int32_T(sp, &r2, 1, &pn_emlrtRTEI);
  emxInit_int32_T(sp, &sorting, 2, &rn_emlrtRTEI);
  emxInit_real_T(sp, &detTimes, 1, &tk_emlrtRTEI, true);
  emxInit_int32_T(sp, &iidx, 1, &gk_emlrtRTEI);
  emxInit_boolean_T(sp, &r3, 1, &pn_emlrtRTEI, true);
  emxInit_int32_T(sp, &m, 2, &tn_emlrtRTEI);
  int32_T exitg1;
  do {
    exitg1 = 0;
    st.site = &onb_emlrtRSI;
    if (OverallUnassigned->size[1] != 0) {
      real_T trackTime;
      int32_T NewTrackNumber;
      int32_T newTrackIndex;
      uint32_T q0;
      uint32_T qY;
      boolean_T tf;
      i = dets->size[0] * dets->size[1];
      i1 = OverallUnassigned_data[0] - 1;
      if ((i1 < 0) || (i1 > i - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, i - 1, &oh_emlrtBCI, (emlrtConstCTX)
          sp);
      }

      NewTrackNumber = obj->pNumLiveTracks;
      q0 = obj->pLastTrackID;
      qY = q0 + 1U;
      if (q0 + 1U < q0) {
        qY = MAX_uint32_T;
      }

      st.site = &pnb_emlrtRSI;
      newTrackIndex = obj->pNumLiveTracks;
      if (newTrackIndex + 1 <= 30) {
        boolean_T bv[50];
        boolean_T in[20];
        if ((newTrackIndex + 1 < 1) || (newTrackIndex + 1 > 30)) {
          emlrtDynamicBoundsCheckR2012b(newTrackIndex + 1, 1, 30, &qh_emlrtBCI,
            &st);
        }

        obj->pTrackIDs[newTrackIndex] = qY;
        obj->pNumLiveTracks++;
        track = obj->pTracksList[newTrackIndex];
        track->TrackID = qY;
        for (i1 = 0; i1 < 20; i1++) {
          trackTime = muDoubleScalarRound(dets_data[OverallUnassigned_data[0] -
            1].SensorIndex);
          if (trackTime < 4.294967296E+9) {
            if (trackTime >= 0.0) {
              q0 = (uint32_T)trackTime;
            } else {
              q0 = 0U;
            }
          } else if (trackTime >= 4.294967296E+9) {
            q0 = MAX_uint32_T;
          } else {
            q0 = 0U;
          }

          in[i1] = (q0 == obj->pUsedSensors[i1]);
        }

        d_eml_find(in, ind_data, ind_size);
        b_st.site = &cob_emlrtRSI;
        c_st.site = &tlb_emlrtRSI;
        d_st.site = &jc_emlrtRSI;
        d_st.site = &jc_emlrtRSI;
        if (ind_size[1] != 1) {
          emlrtErrorWithMessageIdR2018a(&d_st, &t_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedScalar",
            "MATLAB:MultiObjectTracker:expectedScalar", 3, 4, 27,
            "objectDetection.SensorIndex");
        }

        d_st.site = &jc_emlrtRSI;
        c_st.site = &ulb_emlrtRSI;
        track->pUsedObjectAttributes[ind_data[0] - 1] = true;
        trackTime = dets_data[OverallUnassigned_data[0] - 1].Time;
        track->Time = trackTime;
        track->UpdateTime = trackTime;
        track->pAge = 1U;
        b_st.site = &bob_emlrtRSI;
        c_obj = track->TrackLogic;
        for (i1 = 0; i1 < 50; i1++) {
          c_obj->pRecentHistory[i1] = false;
        }

        c_obj->pIsFirstUpdate = true;
        b_st.site = &aob_emlrtRSI;
        c_obj = track->TrackLogic;
        if (!c_obj->pIsFirstUpdate) {
          emlrtErrorWithMessageIdR2018a(&b_st, &gd_emlrtRTEI,
            "shared_tracking:trackHistoryLogic:alreadyInitialized",
            "shared_tracking:trackHistoryLogic:alreadyInitialized", 0);
        }

        bv[0] = true;
        for (i1 = 0; i1 < 49; i1++) {
          bv[i1 + 1] = c_obj->pRecentHistory[i1];
        }

        for (i1 = 0; i1 < 50; i1++) {
          c_obj->pRecentHistory[i1] = bv[i1];
        }

        c_obj->pIsFirstUpdate = false;
        b_st.site = &ynb_emlrtRSI;
        c_st.site = &gob_emlrtRSI;
        initializeEKF(&c_st, dets_data[OverallUnassigned_data[0] - 1].
                      Measurement, dets_data[OverallUnassigned_data[0] - 1].
                      pMeasurementNoise, &filter);
        memcpy(&b_dets_data[0], &dets_data[OverallUnassigned_data[0] - 1].
               pMeasurementNoise[0], 9U * sizeof(real_T));
        c_st.site = &dob_emlrtRSI;
        c_ExtendedKalmanFilter_set_Meas(&c_st, &filter, b_dets_data);
        b_track = obj->pTracksList[newTrackIndex];
        c_st.site = &eob_emlrtRSI;
        trackingEKF_sync(&c_st, b_track->Filter, &filter);
        c_st.site = &fob_emlrtRSI;
        trackingEKF_sync(&c_st, b_track->pDistanceFilter, &filter);
        b_st.site = &xnb_emlrtRSI;
        if (dets_data[OverallUnassigned_data[0] - 1].ObjectClassID != 0.0) {
          track->ObjectClassID = dets_data[OverallUnassigned_data[0] - 1].
            ObjectClassID;
        }

        b_st.site = &wnb_emlrtRSI;
        track->IsConfirmed = ObjectTrack_checkPromotion(track);
        b_st.site = &vnb_emlrtRSI;
        track->pIsCoasted = false;
        obj->pConfirmedTracks[newTrackIndex] = track->IsConfirmed;
        tf = true;
      } else {
        tf = false;
      }

      if (tf) {
        int32_T b_m;
        obj->pLastTrackID = qY;
        i1 = costMatrix->size[0] * costMatrix->size[1];
        costMatrix->size[0] = 1;
        costMatrix->size[1] = OverallUnassigned->size[1];
        emxEnsureCapacity_real_T(sp, costMatrix, i1, &kn_emlrtRTEI);
        costMatrix_data = costMatrix->data;
        loop_ub = OverallUnassigned->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          costMatrix_data[i1] = 0.0;
        }

        if ((NewTrackNumber < 0) || (NewTrackNumber > 29)) {
          emlrtDynamicBoundsCheckR2012b(NewTrackNumber, 0, 29, &rh_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        track = obj->pTracksList[NewTrackNumber];
        st.site = &qnb_emlrtRSI;
        b_obj = obj->cDetectionManager;
        loop_ub = b_obj->pNumDetections;
        if (loop_ub < 1) {
          loop_ub = 0;
        } else {
          i1 = b_obj->pOriginatingSensor->size[1];
          if (i1 < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i1, &xc_emlrtBCI, &st);
          }

          i1 = b_obj->pOriginatingSensor->size[1];
          if (loop_ub > i1) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &wc_emlrtBCI, &st);
          }
        }

        i1 = origSen->size[0] * origSen->size[1];
        origSen->size[0] = 1;
        origSen->size[1] = loop_ub;
        emxEnsureCapacity_real_T(&st, origSen, i1, &ln_emlrtRTEI);
        origSen_data = origSen->data;
        for (i1 = 0; i1 < loop_ub; i1++) {
          origSen_data[i1] = b_obj->pOriginatingSensor->data[i1];
        }

        i1 = sensorsInUnassigned->size[0] * sensorsInUnassigned->size[1];
        sensorsInUnassigned->size[0] = 1;
        sensorsInUnassigned->size[1] = OverallUnassigned->size[1];
        emxEnsureCapacity_real_T(sp, sensorsInUnassigned, i1, &mn_emlrtRTEI);
        sensorsInUnassigned_data = sensorsInUnassigned->data;
        loop_ub = OverallUnassigned->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          if ((OverallUnassigned_data[i1] < 1) || (OverallUnassigned_data[i1] >
               origSen->size[1])) {
            emlrtDynamicBoundsCheckR2012b(OverallUnassigned_data[i1], 1,
              origSen->size[1], &sh_emlrtBCI, (emlrtConstCTX)sp);
          }

          sensorsInUnassigned_data[i1] = origSen_data[OverallUnassigned_data[i1]
            - 1];
        }

        i1 = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = sensorsInUnassigned->size[1];
        emxEnsureCapacity_boolean_T(sp, r, i1, &nn_emlrtRTEI);
        r4 = r->data;
        loop_ub = sensorsInUnassigned->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          r4[i1] = (sensorsInUnassigned_data[i1] == 0.0);
        }

        ind_size[0] = 1;
        ind_size[1] = sensorsInUnassigned->size[1];
        if (sensorsInUnassigned->size[1] != r->size[1]) {
          emlrtSizeEqCheckNDErrorR2021b(&ind_size[0], &r->size[0], &fb_emlrtECI,
            (emlrtCTX)sp);
        }

        end_tmp = sensorsInUnassigned->size[1] - 1;
        for (b_i = 0; b_i <= end_tmp; b_i++) {
          if ((sensorsInUnassigned_data[b_i] ==
               dets_data[OverallUnassigned_data[0] - 1].SensorIndex) || r4[b_i])
          {
            if (b_i > OverallUnassigned->size[1] - 1) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, OverallUnassigned->size[1] -
                1, &th_emlrtBCI, (emlrtConstCTX)sp);
            }

            costMatrix_data[b_i] = rtInf;
          }
        }

        newTrackIndex = 0;
        for (b_i = 0; b_i <= end_tmp; b_i++) {
          if ((!(sensorsInUnassigned_data[b_i] ==
                 dets_data[OverallUnassigned_data[0] - 1].SensorIndex)) &&
              (!r4[b_i])) {
            newTrackIndex++;
          }
        }

        i1 = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        r1->size[1] = newTrackIndex;
        emxEnsureCapacity_int32_T(sp, r1, i1, &on_emlrtRTEI);
        r5 = r1->data;
        newTrackIndex = 0;
        for (b_i = 0; b_i <= end_tmp; b_i++) {
          if ((!(sensorsInUnassigned_data[b_i] ==
                 dets_data[OverallUnassigned_data[0] - 1].SensorIndex)) &&
              (!r4[b_i])) {
            r5[newTrackIndex] = b_i;
            newTrackIndex++;
          }
        }

        i1 = r3->size[0];
        r3->size[0] = sensorsInUnassigned->size[1];
        emxEnsureCapacity_boolean_T(sp, r3, i1, &pn_emlrtRTEI);
        r6 = r3->data;
        loop_ub = sensorsInUnassigned->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          r6[i1] = ((!(sensorsInUnassigned_data[i1] ==
                       dets_data[OverallUnassigned_data[0] - 1].SensorIndex)) &&
                    (!r4[i1]));
        }

        newTrackIndex = 0;
        for (b_i = 0; b_i <= end_tmp; b_i++) {
          if (r6[b_i]) {
            newTrackIndex++;
          }
        }

        i1 = r2->size[0];
        r2->size[0] = newTrackIndex;
        emxEnsureCapacity_int32_T(sp, r2, i1, &on_emlrtRTEI);
        r7 = r2->data;
        newTrackIndex = 0;
        for (b_i = 0; b_i <= end_tmp; b_i++) {
          if (r6[b_i]) {
            r7[newTrackIndex] = b_i;
            newTrackIndex++;
          }
        }

        st.site = &rnb_emlrtRSI;
        loop_ub = r2->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          if ((r7[i1] < 0) || (r7[i1] > OverallUnassigned->size[1] - 1)) {
            emlrtDynamicBoundsCheckR2012b(r7[i1], 0, OverallUnassigned->size[1]
              - 1, &uh_emlrtBCI, &st);
          }
        }

        if ((dets->size[0] == 0) || (dets->size[1] == 0) || (r2->size[0] == 0))
        {
          b_st.site = &mcb_emlrtRSI;
          c_st.site = &gy_emlrtRSI;
          origSen->size[0] = 1;
          origSen->size[1] = 0;
        } else {
          b_st.site = &ncb_emlrtRSI;
          c_st.site = &ocb_emlrtRSI;
          d_st.site = &qcb_emlrtRSI;
          repmat(&d_st, r2->size[0], sorting);
          if (i - 1 < 0) {
            emlrtDynamicBoundsCheckR2012b(0, 0, i - 1, &cf_emlrtBCI, &c_st);
          }

          i1 = detTimes->size[0];
          detTimes->size[0] = r2->size[0];
          emxEnsureCapacity_real_T(&c_st, detTimes, i1, &tk_emlrtRTEI);
          origSen_data = detTimes->data;
          loop_ub = r2->size[0];
          for (i1 = 0; i1 < loop_ub; i1++) {
            origSen_data[i1] = 0.0;
          }

          i1 = r2->size[0];
          for (b_i = 0; b_i < i1; b_i++) {
            if (b_i + 1 > r2->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, r2->size[0],
                &ef_emlrtBCI, &c_st);
            }

            newTrackIndex = OverallUnassigned_data[r7[b_i]] - 1;
            if ((newTrackIndex < 0) || (newTrackIndex > i - 1)) {
              emlrtDynamicBoundsCheckR2012b(newTrackIndex, 0, i - 1,
                &df_emlrtBCI, &c_st);
            }

            if (b_i + 1 > detTimes->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, detTimes->size[0],
                &ff_emlrtBCI, &c_st);
            }

            origSen_data[b_i] = dets_data[newTrackIndex].Time;
          }

          d_st.site = &rcb_emlrtRSI;
          e_st.site = &sx_emlrtRSI;
          f_sort(&e_st, detTimes, iidx);
          iidx_data = iidx->data;
          i1 = detTimes->size[0];
          detTimes->size[0] = iidx->size[0];
          emxEnsureCapacity_real_T(&d_st, detTimes, i1, &nk_emlrtRTEI);
          origSen_data = detTimes->data;
          loop_ub = iidx->size[0];
          for (i1 = 0; i1 < loop_ub; i1++) {
            origSen_data[i1] = iidx_data[i1];
          }

          if (detTimes->size[0] != sorting->size[1]) {
            emlrtSubAssignSizeCheck1dR2017a(sorting->size[1], detTimes->size[0],
              &u_emlrtECI, &c_st);
          }

          ind_size[1] = sorting->size[1];
          i1 = sorting->size[0] * sorting->size[1];
          sorting->size[0] = 1;
          sorting->size[1] = ind_size[1];
          emxEnsureCapacity_int32_T(&c_st, sorting, i1, &rn_emlrtRTEI);
          sorting_data = sorting->data;
          loop_ub = ind_size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            sorting_data[i1] = (int32_T)origSen_data[i1];
          }

          c_st.site = &pcb_emlrtRSI;
          loop_ub = sorting->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            if ((sorting_data[i1] < 1) || (sorting_data[i1] > r2->size[0])) {
              emlrtDynamicBoundsCheckR2012b(sorting_data[i1], 1, r2->size[0],
                &je_emlrtBCI, &c_st);
            }
          }

          d_st.site = &scb_emlrtRSI;
          i1 = origSen->size[0] * origSen->size[1];
          origSen->size[0] = 1;
          origSen->size[1] = sorting->size[1];
          emxEnsureCapacity_real_T(&c_st, origSen, i1, &un_emlrtRTEI);
          origSen_data = origSen->data;
          loop_ub = sorting->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            origSen_data[i1] = rtInf;
          }

          trackTime = track->Time;
          d_st.site = &tcb_emlrtRSI;
          trackingEKF_sync(&d_st, track->pDistanceFilter, track->Filter);
          i1 = sorting->size[1];
          for (end_tmp = 0; end_tmp < i1; end_tmp++) {
            if (end_tmp + 1 > sorting->size[1]) {
              emlrtDynamicBoundsCheckR2012b(end_tmp + 1, 1, sorting->size[1],
                &yd_emlrtBCI, &c_st);
            }

            newTrackIndex = OverallUnassigned_data[r7[sorting_data[end_tmp] - 1]]
              - 1;
            if ((newTrackIndex < 0) || (newTrackIndex > i - 1)) {
              emlrtDynamicBoundsCheckR2012b(newTrackIndex, 0, i - 1,
                &ke_emlrtBCI, &c_st);
            }

            memcpy(&b_dets_data[0],
                   &dets_data[OverallUnassigned_data[r7[sorting_data[end_tmp] -
                   1]] - 1].pMeasurementNoise[0], 9U * sizeof(real_T));
            d_st.site = &ucb_emlrtRSI;
            c_ExtendedKalmanFilter_set_Meas(&d_st, track->pDistanceFilter,
              b_dets_data);
            if ((track->ObjectClassID == 0.0) || (dets_data[newTrackIndex].
                 ObjectClassID == 0.0) || (track->ObjectClassID ==
                 dets_data[newTrackIndex].ObjectClassID)) {
              real_T dt_tmp;
              dt_tmp = dets_data[newTrackIndex].Time;
              trackTime = dt_tmp - trackTime;
              if (trackTime > 0.0) {
                d_st.site = &vcb_emlrtRSI;
                predictTrackFilter(&d_st, track->pDistanceFilter, trackTime);
              }

              trackTime = dt_tmp;
              if (end_tmp + 1 > origSen->size[1]) {
                emlrtDynamicBoundsCheckR2012b(end_tmp + 1, 1, origSen->size[1],
                  &me_emlrtBCI, &c_st);
              }

              d_st.site = &wcb_emlrtRSI;
              origSen_data[end_tmp] = c_ObjectTrack_calcCostOneDetect(&d_st,
                track, dets_data[OverallUnassigned_data[r7[sorting_data[end_tmp]
                - 1]] - 1].Measurement);
            }
          }

          newTrackIndex = origSen->size[1];
          i1 = iidx->size[0];
          iidx->size[0] = sorting->size[1];
          emxEnsureCapacity_int32_T(&b_st, iidx, i1, &fk_emlrtRTEI);
          iidx_data = iidx->data;
          loop_ub = sorting->size[1];
          end_tmp = (sorting->size[1] / 4) << 2;
          b_i = end_tmp - 4;
          for (i1 = 0; i1 <= b_i; i1 += 4) {
            __m128i r8;
            if ((sorting_data[i1] < 1) || (sorting_data[i1] > newTrackIndex)) {
              emlrtDynamicBoundsCheckR2012b(sorting_data[i1], 1, newTrackIndex,
                &le_emlrtBCI, &b_st);
            }

            b_iv[0] = sorting_data[i1];
            if ((sorting_data[i1 + 1] < 1) || (sorting_data[i1 + 1] >
                 newTrackIndex)) {
              emlrtDynamicBoundsCheckR2012b(sorting_data[i1 + 1], 1,
                newTrackIndex, &le_emlrtBCI, &b_st);
            }

            b_iv[1] = sorting_data[i1 + 1];
            if ((sorting_data[i1 + 2] < 1) || (sorting_data[i1 + 2] >
                 newTrackIndex)) {
              emlrtDynamicBoundsCheckR2012b(sorting_data[i1 + 2], 1,
                newTrackIndex, &le_emlrtBCI, &b_st);
            }

            b_iv[2] = sorting_data[i1 + 2];
            if ((sorting_data[i1 + 3] < 1) || (sorting_data[i1 + 3] >
                 newTrackIndex)) {
              emlrtDynamicBoundsCheckR2012b(sorting_data[i1 + 3], 1,
                newTrackIndex, &le_emlrtBCI, &b_st);
            }

            b_iv[3] = sorting_data[i1 + 3];
            r8 = _mm_loadu_si128((const __m128i *)&b_iv[0]);
            _mm_storeu_si128((__m128i *)&iidx_data[i1], _mm_sub_epi32(r8,
              _mm_set1_epi32(1)));
          }

          for (i1 = end_tmp; i1 < loop_ub; i1++) {
            if ((sorting_data[i1] < 1) || (sorting_data[i1] > newTrackIndex)) {
              emlrtDynamicBoundsCheckR2012b(sorting_data[i1], 1, newTrackIndex,
                &le_emlrtBCI, &b_st);
            }

            iidx_data[i1] = sorting_data[i1] - 1;
          }

          ind_size[0] = 1;
          ind_size[1] = iidx->size[0];
          emlrtSubAssignSizeCheckR2012b(&ind_size[0], 2, &origSen->size[0], 2,
            &j_emlrtECI, &b_st);
          i1 = sensorsInUnassigned->size[0] * sensorsInUnassigned->size[1];
          sensorsInUnassigned->size[0] = 1;
          sensorsInUnassigned->size[1] = iidx->size[0];
          emxEnsureCapacity_real_T(&b_st, sensorsInUnassigned, i1, &gk_emlrtRTEI);
          sensorsInUnassigned_data = sensorsInUnassigned->data;
          loop_ub = iidx->size[0];
          for (i1 = 0; i1 < loop_ub; i1++) {
            sensorsInUnassigned_data[i1] = origSen_data[i1];
          }

          loop_ub = sensorsInUnassigned->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            origSen_data[iidx_data[i1]] = sensorsInUnassigned_data[i1];
          }
        }

        if (r1->size[1] != origSen->size[1]) {
          emlrtSubAssignSizeCheck1dR2017a(r1->size[1], origSen->size[1],
            &gb_emlrtECI, (emlrtConstCTX)sp);
        }

        loop_ub = origSen->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          if ((r5[i1] < 0) || (r5[i1] > costMatrix->size[1] - 1)) {
            emlrtDynamicBoundsCheckR2012b(r5[i1], 0, costMatrix->size[1] - 1,
              &vh_emlrtBCI, (emlrtConstCTX)sp);
          }

          costMatrix_data[r5[i1]] = origSen_data[i1];
        }

        i1 = sorting->size[0] * sorting->size[1];
        sorting->size[0] = 1;
        sorting->size[1] = OverallUnassigned->size[1];
        emxEnsureCapacity_int32_T(sp, sorting, i1, &qn_emlrtRTEI);
        sorting_data = sorting->data;
        loop_ub = OverallUnassigned->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          sorting_data[i1] = 0;
        }

        b_m = 0;
        i1 = OverallUnassigned->size[1];
        for (end_tmp = 0; end_tmp <= i1 - 2; end_tmp++) {
          if (end_tmp + 2 > costMatrix->size[1]) {
            emlrtDynamicBoundsCheckR2012b(end_tmp + 2, 1, costMatrix->size[1],
              &wh_emlrtBCI, (emlrtConstCTX)sp);
          }

          if (costMatrix_data[end_tmp + 1] <= 50.0) {
            if (end_tmp + 2 > OverallUnassigned->size[1]) {
              emlrtDynamicBoundsCheckR2012b(end_tmp + 2, 1,
                OverallUnassigned->size[1], &xh_emlrtBCI, (emlrtConstCTX)sp);
            }

            newTrackIndex = OverallUnassigned_data[end_tmp + 1] - 1;
            if ((newTrackIndex < 0) || (newTrackIndex > i - 1)) {
              emlrtDynamicBoundsCheckR2012b(newTrackIndex, 0, i - 1,
                &ph_emlrtBCI, (emlrtConstCTX)sp);
            }

            b_dets = dets_data[OverallUnassigned_data[end_tmp + 1] - 1];
            st.site = &snb_emlrtRSI;
            ObjectTrack_correctjpda(&st, track, &b_dets, obj->pUsedSensors);
          } else {
            b_m++;
            if (end_tmp + 2 > OverallUnassigned->size[1]) {
              emlrtDynamicBoundsCheckR2012b(end_tmp + 2, 1,
                OverallUnassigned->size[1], &yh_emlrtBCI, (emlrtConstCTX)sp);
            }

            if ((b_m < 1) || (b_m > sorting->size[1])) {
              emlrtDynamicBoundsCheckR2012b(b_m, 1, sorting->size[1],
                &ai_emlrtBCI, (emlrtConstCTX)sp);
            }

            sorting_data[b_m - 1] = OverallUnassigned_data[end_tmp + 1];
          }
        }

        obj->pConfirmedTracks[NewTrackNumber] = obj->pTracksList[NewTrackNumber
          ]->IsConfirmed;
        if (b_m > 0) {
          i = OverallUnassigned->size[0] * OverallUnassigned->size[1];
          OverallUnassigned->size[0] = 1;
          OverallUnassigned->size[1] = sorting->size[1];
          emxEnsureCapacity_int32_T(sp, OverallUnassigned, i, &sn_emlrtRTEI);
          OverallUnassigned_data = OverallUnassigned->data;
          loop_ub = sorting->size[1];
          for (i = 0; i < loop_ub; i++) {
            OverallUnassigned_data[i] = sorting_data[i];
          }

          i = m->size[0] * m->size[1];
          m->size[0] = 1;
          loop_ub = sorting->size[1] - b_m;
          m->size[1] = loop_ub;
          emxEnsureCapacity_int32_T(sp, m, i, &tn_emlrtRTEI);
          OverallUnassigned_data = m->data;
          end_tmp = (loop_ub / 4) << 2;
          b_i = end_tmp - 4;
          for (i = 0; i <= b_i; i += 4) {
            _mm_storeu_si128((__m128i *)&OverallUnassigned_data[i],
                             _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(b_m),
              _mm_add_epi32(_mm_set1_epi32(i), _mm_loadu_si128((const __m128i *)
              &iv[0]))), _mm_set1_epi32(1)));
          }

          for (i = end_tmp; i < loop_ub; i++) {
            OverallUnassigned_data[i] = (b_m + i) + 1;
          }

          st.site = &tnb_emlrtRSI;
          nullAssignment(&st, OverallUnassigned, m);
          OverallUnassigned_data = OverallUnassigned->data;
        } else {
          exitg1 = 1;
        }
      } else {
        st.site = &unb_emlrtRSI;
        e_warning(&st);
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_int32_T(sp, &m);
  emxFree_boolean_T(sp, &r3);
  emxFree_int32_T(sp, &iidx);
  emxFree_real_T(sp, &detTimes);
  emxFree_int32_T(sp, &sorting);
  emxFree_int32_T(sp, &r2);
  emxFree_int32_T(sp, &r1);
  emxFree_boolean_T(sp, &r);
  emxFree_real_T(sp, &sensorsInUnassigned);
  emxFree_real_T(sp, &origSen);
  emxFree_real_T(sp, &costMatrix);
  i = obj->pNumLiveTracks;
  if (lastTrackInd > i) {
    i1 = 0;
    i = 0;
  } else {
    if ((lastTrackInd < 1) || (lastTrackInd > 30)) {
      emlrtDynamicBoundsCheckR2012b(lastTrackInd, 1, 30, &mh_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    i1 = lastTrackInd - 1;
    if ((i < 1) || (i > 30)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 30, &nh_emlrtBCI, (emlrtConstCTX)sp);
    }
  }

  newTrackIDs_size[0] = 1;
  loop_ub = i - i1;
  newTrackIDs_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    newTrackIDs_data[i] = obj->pTrackIDs[i1 + i];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void JPDATracker_jpdaClusterUpdate(const emlrtStack *sp, trackerJPDA *obj,
  emxArray_struct_T *clusters, emxArray_boolean_T *isUnassignedDetection, const
  emxArray_objectDetection *dets)
{
  d_matlabshared_tracking_interna *track;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *FJE;
  emxArray_boolean_T *b_jpda_beta;
  emxArray_boolean_T *ingate;
  emxArray_boolean_T *isWeak;
  emxArray_boolean_T *r4;
  emxArray_int32_T *r;
  emxArray_int32_T *r3;
  emxArray_int32_T *sorting;
  emxArray_real_T *FJEProb;
  emxArray_real_T *jpda_beta;
  emxArray_real_T *kinLikelihood;
  emxArray_real_T *r1;
  emxArray_real_T *r2;
  emxArray_uint32_T *b_clusters;
  const objectDetection *dets_data;
  struct_T expl_temp;
  struct_T *clusters_data;
  trackingEKF *filter;
  real_T timestamps_data[600];
  real_T b_tmp_data[32];
  real_T Pd_data[31];
  real_T tmp_data[31];
  real_T c_expl_temp[9];
  real_T *kinLikelihood_data;
  real_T *r9;
  int32_T b_sorting_data[600];
  int32_T b_iv[2];
  int32_T b_tmp_size[2];
  int32_T timestamps_size[2];
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_clusters;
  int32_T cl;
  int32_T col;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T sorting_size_idx_1;
  int32_T *r7;
  int32_T *r8;
  int32_T *sorting_data;
  uint32_T clusterTrackId_data[31];
  uint32_T *b_clusters_data;
  boolean_T *ingate_data;
  boolean_T *isUnassignedDetection_data;
  boolean_T *r6;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  dets_data = dets->data;
  isUnassignedDetection_data = isUnassignedDetection->data;
  clusters_data = clusters->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &tib_emlrtRSI;
  emxInit_int32_T(&st, &sorting, 2, &ip_emlrtRTEI);
  b_st.site = &xib_emlrtRSI;
  repmat(&b_st, clusters->size[1], sorting);
  sorting_data = sorting->data;
  sorting_size_idx_1 = sorting->size[1];
  loop_ub = sorting->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_sorting_data[i] = sorting_data[i];
  }

  if (clusters->size[1] != 0) {
    int32_T iidx_size[2];
    timestamps_size[0] = 1;
    timestamps_size[1] = clusters->size[1];
    loop_ub = clusters->size[1];
    if (loop_ub - 1 >= 0) {
      memset(&timestamps_data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
    }

    i = clusters->size[1];
    b_st.site = &yib_emlrtRSI;
    for (k = 0; k < i; k++) {
      i1 = clusters->size[1];
      if (k + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, i1, &lj_emlrtBCI, &st);
      }

      if (k + 1 > timestamps_size[1]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, timestamps_size[1], &mj_emlrtBCI,
          &st);
      }

      timestamps_data[k] = clusters_data[k].TimeStamp;
    }

    b_st.site = &ajb_emlrtRSI;
    c_st.site = &sx_emlrtRSI;
    g_sort(&c_st, timestamps_data, timestamps_size, b_sorting_data, iidx_size);
    loop_ub = iidx_size[1];
    for (i = 0; i < loop_ub; i++) {
      timestamps_data[i] = b_sorting_data[i];
    }

    if (sorting_size_idx_1 != iidx_size[1]) {
      emlrtSubAssignSizeCheck1dR2017a(sorting_size_idx_1, iidx_size[1],
        &kb_emlrtECI, &st);
    }

    sorting_size_idx_1 = iidx_size[1];
    loop_ub = iidx_size[1];
    for (i = 0; i < loop_ub; i++) {
      b_sorting_data[i] = (int32_T)timestamps_data[i];
    }
  }

  i = clusters->size[1];
  emxInit_real_T(sp, &jpda_beta, 2, &ap_emlrtRTEI, true);
  emxInit_boolean_T(sp, &isWeak, 1, &ep_emlrtRTEI, true);
  emxInit_boolean_T(sp, &FJE, 3, &uo_emlrtRTEI, true);
  emxInit_real_T(sp, &FJEProb, 1, &uo_emlrtRTEI, true);
  emxInit_real_T(sp, &kinLikelihood, 2, &ro_emlrtRTEI, true);
  emxInit_boolean_T(sp, &ingate, 2, &so_emlrtRTEI, true);
  emxInit_int32_T(sp, &r, 1, &fp_emlrtRTEI);
  emxInit_real_T(sp, &r1, 2, &fp_emlrtRTEI, true);
  emxInit_real_T(sp, &r2, 2, &gp_emlrtRTEI, true);
  emxInit_int32_T(sp, &r3, 2, &hp_emlrtRTEI);
  emxInitStruct_struct_T(sp, &expl_temp, &dp_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r4, 2, &to_emlrtRTEI, true);
  emxInit_uint32_T(sp, &b_clusters, 2, &vo_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_jpda_beta, 2, &cp_emlrtRTEI, true);
  if (i - 1 >= 0) {
    tmp_size[0] = 1;
  }

  for (cl = 0; cl < i; cl++) {
    __m128d r5;
    real_T dt;
    int32_T i5;
    int32_T i6;
    int32_T trueCount;
    if (cl + 1 > sorting_size_idx_1) {
      emlrtDynamicBoundsCheckR2012b(cl + 1, 1, sorting_size_idx_1, &kj_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    i1 = b_sorting_data[cl];
    st.site = &uib_emlrtRSI;
    i2 = clusters->size[1];
    if ((i1 < 1) || (i1 > i2)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &nj_emlrtBCI, &st);
    }

    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &bj_emlrtBCI, &st);
    }

    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &bj_emlrtBCI, &st);
    }

    b_st.site = &bjb_emlrtRSI;
    c_JPDATracker_validateClusterDe(&b_st, obj, clusters_data[i1 - 1].
      DetectionIndices);
    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &bj_emlrtBCI, &st);
    }

    b_st.site = &cjb_emlrtRSI;
    JPDATracker_findTracksByIDs(&b_st, obj, clusters_data[i1 - 1].TrackIDs.data,
      clusters_data[i1 - 1].TrackIDs.size, clusterTrackId_data, timestamps_size);
    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &bj_emlrtBCI, &st);
    }

    b_st.site = &djb_emlrtRSI;
    c_st.site = &kjb_emlrtRSI;
    dt = (real_T)clusters_data[i1 - 1].DetectionIndices->size[1] + 1.0;
    if (dt != (int32_T)dt) {
      emlrtIntegerCheckR2012b(dt, &l_emlrtDCI, &c_st);
    }

    i2 = kinLikelihood->size[0] * kinLikelihood->size[1];
    kinLikelihood->size[0] = (int32_T)dt;
    kinLikelihood->size[1] = timestamps_size[1] + 1;
    emxEnsureCapacity_real_T(&c_st, kinLikelihood, i2, &ro_emlrtRTEI);
    kinLikelihood_data = kinLikelihood->data;
    if (dt != (int32_T)dt) {
      emlrtIntegerCheckR2012b(dt, &m_emlrtDCI, &c_st);
    }

    loop_ub = (int32_T)dt * (timestamps_size[1] + 1);
    for (i2 = 0; i2 < loop_ub; i2++) {
      kinLikelihood_data[i2] = 0.0;
    }

    loop_ub = timestamps_size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      Pd_data[i2] = obj->pTrackDetectionProbability[(int32_T)
        clusterTrackId_data[i2] - 1];
    }

    i2 = b_sorting_data[cl];
    if (clusters_data[i2 - 1].DetectionIndices->size[1] + 1 < 2) {
      i3 = 0;
      i2 = 0;
    } else {
      i2 = clusters_data[i2 - 1].DetectionIndices->size[1] + 1;
      if (i2 < 2) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i2, &dj_emlrtBCI, &c_st);
      }

      i3 = 1;
    }

    loop_ub = i2 - i3;
    for (i2 = 0; i2 < loop_ub; i2++) {
      kinLikelihood_data[i3 + i2] = 1.0E-5;
    }

    i2 = timestamps_size[1];
    if (timestamps_size[1] - 1 >= 0) {
      i3 = b_sorting_data[cl];
      b_loop_ub = clusters_data[i3 - 1].ValidationMatrix->size[0];
      c_clusters = clusters_data[i3 - 1].DetectionIndices->size[1];
    }

    for (col = 0; col < i2; col++) {
      real_T trackTime;
      if (col + 1 > timestamps_size[1]) {
        emlrtDynamicBoundsCheckR2012b(col + 1, 1, timestamps_size[1],
          &oj_emlrtBCI, &c_st);
      }

      track = obj->pTracksList[(int32_T)clusterTrackId_data[col] - 1];
      i3 = clusters_data[i1 - 1].ValidationMatrix->size[1];
      if (col + 2 > i3) {
        emlrtDynamicBoundsCheckR2012b(col + 2, 1, i3, &cj_emlrtBCI, &c_st);
      }

      i3 = ingate->size[0] * ingate->size[1];
      ingate->size[0] = 1;
      ingate->size[1] = b_loop_ub;
      emxEnsureCapacity_boolean_T(&c_st, ingate, i3, &so_emlrtRTEI);
      ingate_data = ingate->data;
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        ingate_data[i3] = clusters_data[i1 - 1].ValidationMatrix->data[i3 +
          clusters_data[i1 - 1].ValidationMatrix->size[0] * (col + 1)];
      }

      i3 = r4->size[0] * r4->size[1];
      r4->size[0] = 1;
      r4->size[1] = ingate->size[1] + 1;
      emxEnsureCapacity_boolean_T(&c_st, r4, i3, &to_emlrtRTEI);
      r6 = r4->data;
      r6[0] = false;
      loop_ub = ingate->size[1];
      for (i3 = 0; i3 < loop_ub; i3++) {
        r6[i3 + 1] = ingate_data[i3];
      }

      k = r4->size[1] - 1;
      trueCount = 0;
      for (b_i = 0; b_i <= k; b_i++) {
        if (r6[b_i]) {
          trueCount++;
        }
      }

      i3 = r->size[0];
      r->size[0] = trueCount;
      emxEnsureCapacity_int32_T(&c_st, r, i3, &uo_emlrtRTEI);
      r7 = r->data;
      trueCount = 0;
      for (b_i = 0; b_i <= k; b_i++) {
        if (r6[b_i]) {
          if (b_i > kinLikelihood->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, kinLikelihood->size[0] - 1,
              &hj_emlrtBCI, &c_st);
          }

          r7[trueCount] = b_i;
          trueCount++;
        }
      }

      if (col + 2 > kinLikelihood->size[1]) {
        emlrtDynamicBoundsCheckR2012b(col + 2, 1, kinLikelihood->size[1],
          &ej_emlrtBCI, &c_st);
      }

      k = ingate->size[1] - 1;
      trueCount = 0;
      for (b_i = 0; b_i <= k; b_i++) {
        if (ingate_data[b_i]) {
          trueCount++;
        }
      }

      i3 = r3->size[0] * r3->size[1];
      r3->size[0] = 1;
      r3->size[1] = trueCount;
      emxEnsureCapacity_int32_T(&c_st, r3, i3, &uo_emlrtRTEI);
      r8 = r3->data;
      trueCount = 0;
      for (b_i = 0; b_i <= k; b_i++) {
        if (ingate_data[b_i]) {
          r8[trueCount] = b_i;
          trueCount++;
        }
      }

      d_st.site = &mjb_emlrtRSI;
      loop_ub = r3->size[1];
      for (i3 = 0; i3 < loop_ub; i3++) {
        if ((r8[i3] < 0) || (r8[i3] > c_clusters - 1)) {
          emlrtDynamicBoundsCheckR2012b(r8[i3], 0, c_clusters - 1, &pj_emlrtBCI,
            &d_st);
        }
      }

      i3 = b_clusters->size[0] * b_clusters->size[1];
      b_clusters->size[0] = 1;
      loop_ub = r3->size[1];
      b_clusters->size[1] = r3->size[1];
      emxEnsureCapacity_uint32_T(&d_st, b_clusters, i3, &vo_emlrtRTEI);
      b_clusters_data = b_clusters->data;
      for (i3 = 0; i3 < loop_ub; i3++) {
        b_clusters_data[i3] = clusters_data[i1 - 1].DetectionIndices->data[r8[i3]];
      }

      e_st.site = &njb_emlrtRSI;
      c_ObjectTrack_sortDetectionsByT(&e_st, dets, b_clusters, sorting);
      sorting_data = sorting->data;
      e_st.site = &ojb_emlrtRSI;
      f_st.site = &gy_emlrtRSI;
      i3 = r1->size[0] * r1->size[1];
      r1->size[0] = 1;
      i4 = r3->size[1];
      r1->size[1] = r3->size[1];
      emxEnsureCapacity_real_T(&d_st, r1, i3, &xo_emlrtRTEI);
      r9 = r1->data;
      e_st.site = &pjb_emlrtRSI;
      trackingEKF_sync(&e_st, track->pDistanceFilter, track->Filter);
      filter = track->pDistanceFilter;
      trackTime = track->Time;
      for (j = 0; j < i4; j++) {
        objectDetection b_expl_temp;
        real_T Y[3];
        real_T zres[3];
        real_T dt_tmp;
        if (j + 1 > sorting->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, sorting->size[1], &qj_emlrtBCI,
            &d_st);
        }

        i3 = sorting_data[j];
        if ((i3 < 1) || (i3 > r3->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, r3->size[1], &fj_emlrtBCI, &d_st);
        }

        i3 = dets->size[0] * dets->size[1] - 1;
        k = (int32_T)clusters_data[b_sorting_data[cl] - 1]
          .DetectionIndices->data[r8[sorting_data[j] - 1]] - 1;
        if ((k < 0) || (k > i3)) {
          emlrtDynamicBoundsCheckR2012b(k, 0, i3, &rj_emlrtBCI, &d_st);
        }

        b_expl_temp = dets_data[k];
        memcpy(&c_expl_temp[0], &b_expl_temp.pMeasurementNoise[0], 9U * sizeof
               (real_T));
        e_st.site = &qjb_emlrtRSI;
        c_ExtendedKalmanFilter_set_Meas(&e_st, filter, c_expl_temp);
        dt_tmp = dets_data[k].Time;
        dt = dt_tmp - trackTime;
        if (dt > 0.0) {
          e_st.site = &rjb_emlrtRSI;
          predictTrackFilter(&e_st, filter, dt);
        }

        trackTime = dt_tmp;
        e_st.site = &sjb_emlrtRSI;
        f_st.site = &tjb_emlrtRSI;
        trackingEKF_residual(&f_st, filter, b_expl_temp.Measurement, zres,
                             c_expl_temp);
        f_st.site = &ujb_emlrtRSI;
        g_st.site = &gkb_emlrtRSI;
        h_st.site = &gcb_emlrtRSI;
        b_mrdiv(&h_st, zres, c_expl_temp, Y);
        g_st.site = &hkb_emlrtRSI;
        h_st.site = &hkb_emlrtRSI;
        dt = det(&h_st, c_expl_temp);
        if (dt < 0.0) {
          emlrtErrorWithMessageIdR2018a(&g_st, &hb_emlrtRTEI,
            "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
            3, 4, 4, "sqrt");
        }

        dt = muDoubleScalarSqrt(dt);
        if (j + 1 > r1->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, r1->size[1], &sj_emlrtBCI,
            &f_st);
        }

        r9[j] = muDoubleScalarMax(muDoubleScalarExp(-((Y[0] * zres[0] + Y[1] *
          zres[1]) + Y[2] * zres[2]) / 2.0) / 15.749609945722419 / dt,
          2.2250738585072014E-308);
      }

      emlrtSubAssignSizeCheckR2012b(&r->size[0], 1, &r1->size[0], 2,
        &lb_emlrtECI, &c_st);
      loop_ub = r->size[0];
      for (i3 = 0; i3 < loop_ub; i3++) {
        kinLikelihood_data[r7[i3] + kinLikelihood->size[0] * (col + 1)] = r9[i3];
      }
    }

    loop_ub = timestamps_size[1];
    b_tmp_size[0] = 1;
    b_tmp_size[1] = timestamps_size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&tmp_data[0], &Pd_data[0], (uint32_T)loop_ub * sizeof(real_T));
    }

    loop_ub = b_tmp_size[1];
    tmp_size[1] = b_tmp_size[1] + 1;
    b_tmp_data[0] = 1.0;
    k = (b_tmp_size[1] / 2) << 1;
    trueCount = k - 2;
    for (i1 = 0; i1 <= trueCount; i1 += 2) {
      r5 = _mm_loadu_pd(&tmp_data[i1]);
      _mm_storeu_pd(&b_tmp_data[i1 + 1], _mm_sub_pd(_mm_set1_pd(1.0), _mm_mul_pd
        (r5, _mm_set1_pd(0.93033323307719429))));
    }

    for (i1 = k; i1 < loop_ub; i1++) {
      b_tmp_data[i1 + 1] = 1.0 - tmp_data[i1] * 0.93033323307719429;
    }

    b_iv[0] = 1;
    b_iv[1] = kinLikelihood->size[1];
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &tmp_size[0], 2, &mb_emlrtECI,
      &c_st);
    loop_ub = kinLikelihood->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      kinLikelihood_data[kinLikelihood->size[0] * i1] = b_tmp_data[i1];
    }

    if (kinLikelihood->size[0] < 2) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = kinLikelihood->size[0];
    }

    if (kinLikelihood->size[1] < 2) {
      i3 = 0;
      i4 = 0;
    } else {
      i3 = 1;
      i4 = kinLikelihood->size[1];
    }

    k = i4 - i3;
    loop_ub = b_tmp_size[1];
    if ((b_tmp_size[1] != k) && ((b_tmp_size[1] != 1) && (k != 1))) {
      emlrtDimSizeImpxCheckR2021b(b_tmp_size[1], k, &nb_emlrtECI, &c_st);
    }

    if (kinLikelihood->size[0] < 2) {
      b_i = 0;
      col = 0;
    } else {
      b_i = 1;
      col = kinLikelihood->size[0];
    }

    if (kinLikelihood->size[1] < 2) {
      i5 = 0;
      i6 = 0;
    } else {
      i5 = 1;
      i6 = kinLikelihood->size[1];
    }

    if (b_tmp_size[1] == k) {
      j = i2 - i1;
      i2 = r2->size[0] * r2->size[1];
      r2->size[0] = j;
      r2->size[1] = b_tmp_size[1];
      emxEnsureCapacity_real_T(&c_st, r2, i2, &wo_emlrtRTEI);
      r9 = r2->data;
      for (i2 = 0; i2 < loop_ub; i2++) {
        k = (j / 2) << 1;
        trueCount = k - 2;
        for (i4 = 0; i4 <= trueCount; i4 += 2) {
          r5 = _mm_loadu_pd(&kinLikelihood_data[(i1 + i4) + kinLikelihood->size
                            [0] * (i3 + i2)]);
          _mm_storeu_pd(&r9[i4 + r2->size[0] * i2], _mm_mul_pd(_mm_set1_pd
            (tmp_data[i2]), r5));
        }

        for (i4 = k; i4 < j; i4++) {
          r9[i4 + r2->size[0] * i2] = tmp_data[i2] * kinLikelihood_data[(i1 + i4)
            + kinLikelihood->size[0] * (i3 + i2)];
        }
      }
    } else {
      d_st.site = &hqb_emlrtRSI;
      d_binary_expand_op(&d_st, r2, tmp_data, b_tmp_size, kinLikelihood, i1, i2
                         - 1, i3, i4);
      r9 = r2->data;
    }

    loop_ub = col - b_i;
    b_iv[0] = loop_ub;
    j = i6 - i5;
    b_iv[1] = j;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &r2->size[0], 2, &ob_emlrtECI,
      &c_st);
    for (i1 = 0; i1 < j; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        kinLikelihood_data[(b_i + i2) + kinLikelihood->size[0] * (i5 + i1)] =
          r9[i2 + loop_ub * i1];
      }
    }

    c_st.site = &ljb_emlrtRSI;
    jpdaEvents(&c_st, kinLikelihood, FJE, FJEProb);
    loop_ub = kinLikelihood->size[0] * kinLikelihood->size[1];
    i1 = b_sorting_data[cl];
    i2 = clusters_data[i1 - 1].Likelihood->size[0] * clusters_data[i1 - 1].
      Likelihood->size[1];
    clusters_data[i1 - 1].Likelihood->size[0] = kinLikelihood->size[0];
    emxEnsureCapacity_real_T(&st, clusters_data[i1 - 1].Likelihood, i2,
      &yo_emlrtRTEI);
    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &bj_emlrtBCI, &st);
    }

    i2 = clusters_data[i1 - 1].Likelihood->size[0] * clusters_data[i1 - 1].
      Likelihood->size[1];
    clusters_data[i1 - 1].Likelihood->size[1] = kinLikelihood->size[1];
    emxEnsureCapacity_real_T(&st, clusters_data[i1 - 1].Likelihood, i2,
      &yo_emlrtRTEI);
    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &bj_emlrtBCI, &st);
    }

    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &bj_emlrtBCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      clusters_data[b_sorting_data[cl] - 1].Likelihood->data[i1] =
        kinLikelihood_data[i1];
    }

    i1 = b_sorting_data[cl];
    b_st.site = &ejb_emlrtRSI;
    c_JPDATracker_associationProbab(&b_st, FJE, FJEProb, clusters_data[i1 - 1].
      MarginalProbabilities);
    st.site = &vib_emlrtRSI;
    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &gj_emlrtBCI, &st);
    }

    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &gj_emlrtBCI, &st);
    }

    i2 = jpda_beta->size[0] * jpda_beta->size[1];
    jpda_beta->size[0] = clusters_data[i1 - 1].MarginalProbabilities->size[0];
    jpda_beta->size[1] = clusters_data[i1 - 1].MarginalProbabilities->size[1];
    emxEnsureCapacity_real_T(&st, jpda_beta, i2, &ap_emlrtRTEI);
    kinLikelihood_data = jpda_beta->data;
    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &gj_emlrtBCI, &st);
    }

    i2 = clusters->size[1];
    if (i1 > i2) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &gj_emlrtBCI, &st);
    }

    loop_ub = clusters_data[i1 - 1].MarginalProbabilities->size[0] *
      clusters_data[i1 - 1].MarginalProbabilities->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      kinLikelihood_data[i1] = clusters_data[b_sorting_data[cl] - 1].
        MarginalProbabilities->data[i1];
    }

    b_st.site = &qkb_emlrtRSI;
    i1 = b_sorting_data[cl];
    k = clusters_data[i1 - 1].MarginalProbabilities->size[0];
    c_st.site = &skb_emlrtRSI;
    if (clusters_data[i1 - 1].MarginalProbabilities->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&c_st, &od_emlrtRTEI,
        "MATLAB:subsdeldimmismatch", "MATLAB:subsdeldimmismatch", 0);
    }

    c_st.site = &tkb_emlrtRSI;
    i2 = clusters_data[i1 - 1].MarginalProbabilities->size[1];
    trueCount = clusters_data[i1 - 1].MarginalProbabilities->size[0] - 1;
    d_st.site = &ukb_emlrtRSI;
    for (j = 0; j < i2; j++) {
      d_st.site = &vkb_emlrtRSI;
      for (b_i = k; b_i <= trueCount; b_i++) {
        kinLikelihood_data[(b_i + jpda_beta->size[0] * j) - 1] =
          kinLikelihood_data[b_i + jpda_beta->size[0] * j];
      }
    }

    if (clusters_data[b_sorting_data[cl] - 1].MarginalProbabilities->size[0] - 1
        > jpda_beta->size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &pd_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (jpda_beta->size[0] - 1 < 1) {
      trueCount = 0;
    }

    k = jpda_beta->size[1];
    for (i1 = 0; i1 < k; i1++) {
      for (i2 = 0; i2 < trueCount; i2++) {
        kinLikelihood_data[i2 + trueCount * i1] = kinLikelihood_data[i2 +
          jpda_beta->size[0] * i1];
      }
    }

    i1 = jpda_beta->size[0] * jpda_beta->size[1];
    jpda_beta->size[0] = trueCount;
    emxEnsureCapacity_real_T(&c_st, jpda_beta, i1, &bp_emlrtRTEI);
    kinLikelihood_data = jpda_beta->data;
    i1 = b_jpda_beta->size[0] * b_jpda_beta->size[1];
    b_jpda_beta->size[0] = trueCount;
    b_jpda_beta->size[1] = jpda_beta->size[1];
    emxEnsureCapacity_boolean_T(&st, b_jpda_beta, i1, &cp_emlrtRTEI);
    ingate_data = b_jpda_beta->data;
    k = trueCount * jpda_beta->size[1];
    for (i1 = 0; i1 < k; i1++) {
      ingate_data[i1] = (kinLikelihood_data[i1] < 0.0);
    }

    b_st.site = &rkb_emlrtRSI;
    c_all(&b_st, b_jpda_beta, isWeak);
    ingate_data = isWeak->data;
    k = isWeak->size[0] - 1;
    for (b_i = 0; b_i <= k; b_i++) {
      if (ingate_data[b_i]) {
        i1 = clusters_data[b_sorting_data[cl] - 1].DetectionIndices->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ij_emlrtBCI, &st);
        }
      }
    }

    trueCount = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if (ingate_data[b_i]) {
        trueCount++;
      }
    }

    i1 = sorting->size[0] * sorting->size[1];
    sorting->size[0] = 1;
    sorting->size[1] = trueCount;
    emxEnsureCapacity_int32_T(sp, sorting, i1, &uo_emlrtRTEI);
    sorting_data = sorting->data;
    trueCount = 0;
    for (b_i = 0; b_i <= k; b_i++) {
      if (ingate_data[b_i]) {
        i1 = isUnassignedDetection->size[1];
        i2 = (int32_T)clusters_data[b_sorting_data[cl] - 1]
          .DetectionIndices->data[b_i];
        if ((i2 < 1) || (i2 > i1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &jj_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        sorting_data[trueCount] = i2;
        trueCount++;
      }
    }

    loop_ub = sorting->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      isUnassignedDetection_data[sorting_data[i1] - 1] = true;
    }

    emxCopyStruct_struct_T(sp, &expl_temp, &clusters_data[b_sorting_data[cl] - 1],
      &dp_emlrtRTEI);
    st.site = &wib_emlrtRSI;
    c_JPDATracker_updateAssignedTra(&st, obj, expl_temp.DetectionIndices,
      expl_temp.TrackIDs.data, expl_temp.TrackIDs.size,
      expl_temp.MarginalProbabilities, dets);
  }

  emxFree_boolean_T(sp, &b_jpda_beta);
  emxFree_uint32_T(sp, &b_clusters);
  emxFree_boolean_T(sp, &r4);
  emxFreeStruct_struct_T(sp, &expl_temp);
  emxFree_int32_T(sp, &sorting);
  emxFree_int32_T(sp, &r3);
  emxFree_real_T(sp, &r2);
  emxFree_real_T(sp, &r1);
  emxFree_int32_T(sp, &r);
  emxFree_boolean_T(sp, &ingate);
  emxFree_real_T(sp, &kinLikelihood);
  emxFree_real_T(sp, &FJEProb);
  emxFree_boolean_T(sp, &FJE);
  emxFree_boolean_T(sp, &isWeak);
  emxFree_real_T(sp, &jpda_beta);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void JPDATracker_predictTracks(const emlrtStack *sp, trackerJPDA *obj,
  real_T t)
{
  d_matlabshared_tracking_interna *track;
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (t > obj->pLastTimeStamp) {
    int32_T b;
    b = obj->pNumLiveTracks;
    st.site = &bgb_emlrtRSI;
    if (b > 2147483646) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 0; i < b; i++) {
      if (i > 29) {
        emlrtDynamicBoundsCheckR2012b(i, 0, 29, &jf_emlrtBCI, (emlrtConstCTX)sp);
      }

      track = obj->pTracksList[i];
      if (t > track->Time) {
        st.site = &cgb_emlrtRSI;
        ObjectTrack_predict(&st, track, t);
      }
    }
  }

  obj->pLastTimeStamp = t;
}

static void JPDATracker_selectDetections(const emlrtStack *sp, trackerJPDA *obj,
  real_T ID, const emxArray_boolean_T *detSelector, emxArray_int32_T *indices)
{
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_boolean_T *r;
  emxArray_boolean_T *r2;
  emxArray_real_T *sensors;
  real_T *sensors_data;
  int32_T i;
  int32_T loop_ub;
  const boolean_T *detSelector_data;
  boolean_T *r1;
  boolean_T *r3;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  detSelector_data = detSelector->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &sensors, 2, &jl_emlrtRTEI, true);
  st.site = &rgb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  loop_ub = b_obj->pNumDetections;
  if (loop_ub < 1) {
    loop_ub = 0;
  } else {
    i = b_obj->pOriginatingSensor->size[1];
    if (i < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &xc_emlrtBCI, &st);
    }

    i = b_obj->pOriginatingSensor->size[1];
    if (loop_ub > i) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &wc_emlrtBCI, &st);
    }
  }

  i = sensors->size[0] * sensors->size[1];
  sensors->size[0] = 1;
  sensors->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&st, sensors, i, &il_emlrtRTEI);
  sensors_data = sensors->data;
  for (i = 0; i < loop_ub; i++) {
    sensors_data[i] = b_obj->pOriginatingSensor->data[i];
  }

  emxInit_boolean_T(sp, &r, 2, &jl_emlrtRTEI, true);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = sensors->size[1];
  emxEnsureCapacity_boolean_T(sp, r, i, &jl_emlrtRTEI);
  r1 = r->data;
  loop_ub = sensors->size[1];
  for (i = 0; i < loop_ub; i++) {
    r1[i] = (sensors_data[i] == ID);
  }

  emxFree_real_T(sp, &sensors);
  if ((r->size[1] != detSelector->size[1]) && ((r->size[1] != 1) &&
       (detSelector->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[1], detSelector->size[1], &w_emlrtECI,
      (emlrtConstCTX)sp);
  }

  st.site = &rgb_emlrtRSI;
  b_st.site = &sgb_emlrtRSI;
  c_st.site = &kx_emlrtRSI;
  if (r->size[1] == detSelector->size[1]) {
    emxInit_boolean_T(&c_st, &r2, 2, &jl_emlrtRTEI, true);
    i = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = r->size[1];
    emxEnsureCapacity_boolean_T(&c_st, r2, i, &jl_emlrtRTEI);
    r3 = r2->data;
    loop_ub = r->size[1];
    for (i = 0; i < loop_ub; i++) {
      r3[i] = (r1[i] && detSelector_data[i]);
    }

    d_st.site = &cg_emlrtRSI;
    b_eml_find(&d_st, r2, indices);
    emxFree_boolean_T(&c_st, &r2);
  } else {
    d_st.site = &cg_emlrtRSI;
    b_binary_expand_op(&d_st, indices, cg_emlrtRSI, r, detSelector);
  }

  emxFree_boolean_T(&c_st, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void JPDATracker_trackDetectability(const emlrtStack *sp, trackerJPDA
  *obj, const real_T varargin_2_data[], const int32_T varargin_2_size[2])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T ind_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 30; i++) {
    obj->pTrackDetectionProbability[i] = 0.9;
  }

  ind_data = obj->pNumLiveTracks;
  if (ind_data < 1) {
    ind_data = 0;
  } else if (ind_data > 30) {
    emlrtDynamicBoundsCheckR2012b(ind_data, 1, 30, &gf_emlrtBCI, (emlrtConstCTX)
      sp);
  }

  if (ind_data - 1 >= 0) {
    memset(&obj->pWasDetectable[0], 0, (uint32_T)ind_data * sizeof(boolean_T));
  }

  if ((varargin_2_size[0] << 1) > 0) {
    int32_T b_i;
    boolean_T exitg1;
    boolean_T p;
    st.site = &xfb_emlrtRSI;
    b_st.site = &jc_emlrtRSI;
    p = true;
    ind_data = 0;
    exitg1 = false;
    while ((!exitg1) && (ind_data <= varargin_2_size[0] - 1)) {
      if (!(varargin_2_data[ind_data] <= 0.0)) {
        ind_data++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &fb_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:step:expectedPositive", 3, 4, 18, "detectableTrackIDs");
    }

    b_st.site = &jc_emlrtRSI;
    p = true;
    ind_data = 0;
    exitg1 = false;
    while ((!exitg1) && (ind_data <= varargin_2_size[0] - 1)) {
      if ((!muDoubleScalarIsInf(varargin_2_data[ind_data])) &&
          (!muDoubleScalarIsNaN(varargin_2_data[ind_data])) &&
          (muDoubleScalarFloor(varargin_2_data[ind_data]) ==
           varargin_2_data[ind_data])) {
        ind_data++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:step:expectedInteger", 3, 4, 18, "detectableTrackIDs");
    }

    st.site = &yfb_emlrtRSI;
    b_st.site = &jc_emlrtRSI;
    p = true;
    ind_data = 0;
    exitg1 = false;
    while ((!exitg1) && (ind_data <= varargin_2_size[0] - 1)) {
      if (!(varargin_2_data[ind_data + varargin_2_size[0]] < 0.0)) {
        ind_data++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:step:expectedNonnegative", 3, 4, 20, "detectionProbability");
    }

    b_st.site = &jc_emlrtRSI;
    p = true;
    ind_data = 0;
    exitg1 = false;
    while ((!exitg1) && (ind_data <= varargin_2_size[0] - 1)) {
      if (varargin_2_data[ind_data + varargin_2_size[0]] < 1.0) {
        ind_data++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &tc_emlrtRTEI,
        "MATLAB:validateattributes:expectedArray", "MATLAB:step:notLess", 9, 4,
        20, "detectionProbability", 4, 1, "<", 4, 1, "1");
    }

    b_i = varargin_2_size[0];
    for (i = 0; i < b_i; i++) {
      real_T varargin_2;
      int32_T ind_size[2];
      boolean_T b_varargin_2[30];
      st.site = &agb_emlrtRSI;
      if (i + 1 > varargin_2_size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, varargin_2_size[0], &hf_emlrtBCI,
          &st);
      }

      varargin_2 = varargin_2_data[i];
      for (ind_data = 0; ind_data < 30; ind_data++) {
        b_varargin_2[ind_data] = (varargin_2 == obj->pTrackIDs[ind_data]);
      }

      c_eml_find(b_varargin_2, (int32_T *)&ind_data, ind_size);
      if (ind_size[1] != 0) {
        obj->pWasDetectable[ind_data - 1] = true;
        if (i + 1 > varargin_2_size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, varargin_2_size[0],
            &if_emlrtBCI, (emlrtConstCTX)sp);
        }

        obj->pTrackDetectionProbability[ind_data - 1] = varargin_2_data[i +
          varargin_2_size[0]];
      }
    }
  }
}

static void c_JPDATracker_associationProbab(const emlrtStack *sp, const
  emxArray_boolean_T *FJE, const emxArray_real_T *FJEprobs, emxArray_real_T
  *posterior)
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_real_T *b_posterior;
  emxArray_real_T *bsum;
  emxArray_real_T *x;
  real_T varargin_2_data[31];
  const real_T *FJEprobs_data;
  real_T *b_posterior_data;
  real_T *bsum_data;
  real_T *posterior_data;
  real_T *x_data;
  int32_T b_FJE[2];
  int32_T varargin_2_size[2];
  int32_T hi;
  int32_T ib;
  int32_T k;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T nx;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T vstride;
  int32_T xj;
  int32_T xoffset;
  const boolean_T *FJE_data;
  boolean_T b;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  FJEprobs_data = FJEprobs->data;
  FJE_data = FJE->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ikb_emlrtRSI;
  b = (FJE->size[1] - 1 < 0);
  if (b) {
    emlrtNonNegativeCheckR2012b(-1.0, &k_emlrtDCI, &st);
  }

  ib = posterior->size[0] * posterior->size[1];
  posterior->size[0] = FJE->size[0] + 1;
  posterior->size[1] = FJE->size[1] - 1;
  emxEnsureCapacity_real_T(&st, posterior, ib, &hm_emlrtRTEI);
  posterior_data = posterior->data;
  nblocks = (FJE->size[0] + 1) * (FJE->size[1] - 1);
  for (ib = 0; ib < nblocks; ib++) {
    posterior_data[ib] = 0.0;
  }

  if (FJE->size[1] < 2) {
    ib = 0;
    vstride = 0;
  } else {
    ib = 1;
    vstride = FJE->size[1];
  }

  b_st.site = &kkb_emlrtRSI;
  nx = FJEprobs->size[0];
  c_st.site = &bg_emlrtRSI;
  d_st.site = &lkb_emlrtRSI;
  hi = FJEprobs->size[0];
  if (FJEprobs->size[0] < 1) {
    hi = 1;
  }

  if (FJE->size[2] > muIntScalarMax_sint32(nx, hi)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &k_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (FJEprobs->size[0] != FJE->size[2]) {
    emlrtErrorWithMessageIdR2018a(&b_st, &l_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  if ((FJE->size[0] < 1) || (FJE->size[0] > FJE->size[0] + 1)) {
    emlrtDynamicBoundsCheckR2012b(FJE->size[0], 1, FJE->size[0] + 1,
      &kg_emlrtBCI, &st);
  }

  b_st.site = &kkb_emlrtRSI;
  emxInit_real_T(&b_st, &x, 3, &im_emlrtRTEI, true);
  lastBlockLength = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = FJE->size[0];
  nblocks = vstride - ib;
  x->size[1] = nblocks;
  x->size[2] = FJE->size[2];
  emxEnsureCapacity_real_T(&b_st, x, lastBlockLength, &im_emlrtRTEI);
  x_data = x->data;
  nx = FJE->size[2];
  for (vstride = 0; vstride < nx; vstride++) {
    for (lastBlockLength = 0; lastBlockLength < nblocks; lastBlockLength++) {
      hi = FJE->size[0];
      for (xoffset = 0; xoffset < hi; xoffset++) {
        x_data[(xoffset + x->size[0] * lastBlockLength) + x->size[0] * x->size[1]
          * vstride] = (real_T)FJE_data[(xoffset + FJE->size[0] * (ib +
          lastBlockLength)) + FJE->size[0] * FJE->size[1] * vstride] *
          FJEprobs_data[vstride];
      }
    }
  }

  c_st.site = &vi_emlrtRSI;
  d_st.site = &vh_emlrtRSI;
  e_st.site = &wi_emlrtRSI;
  emxInit_real_T(&e_st, &b_posterior, 2, &lm_emlrtRTEI, true);
  if ((x->size[0] == 0) || (x->size[1] == 0) || (x->size[2] == 0)) {
    ib = b_posterior->size[0] * b_posterior->size[1];
    b_posterior->size[0] = x->size[0];
    b_posterior->size[1] = x->size[1];
    emxEnsureCapacity_real_T(&e_st, b_posterior, ib, &jm_emlrtRTEI);
    b_posterior_data = b_posterior->data;
    nblocks = x->size[0] * x->size[1];
    for (ib = 0; ib < nblocks; ib++) {
      b_posterior_data[ib] = 0.0;
    }
  } else {
    __m128d r1;
    int32_T bvstride;
    f_st.site = &mw_emlrtRSI;
    vstride = x->size[0] * x->size[1];
    bvstride = vstride << 10;
    ib = b_posterior->size[0] * b_posterior->size[1];
    b_posterior->size[0] = x->size[0];
    b_posterior->size[1] = x->size[1];
    emxEnsureCapacity_real_T(&f_st, b_posterior, ib, &rh_emlrtRTEI);
    b_posterior_data = b_posterior->data;
    emxInit_real_T(&f_st, &bsum, 1, &mm_emlrtRTEI, true);
    ib = bsum->size[0];
    bsum->size[0] = vstride;
    emxEnsureCapacity_real_T(&f_st, bsum, ib, &km_emlrtRTEI);
    bsum_data = bsum->data;
    if (x->size[2] <= 1024) {
      nx = x->size[2];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      nx = 1024;
      nblocks = (int32_T)((uint32_T)x->size[2] >> 10);
      lastBlockLength = x->size[2] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }

    g_st.site = &qw_emlrtRSI;
    if (vstride > 2147483646) {
      h_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&h_st);
    }

    for (xj = 0; xj < vstride; xj++) {
      b_posterior_data[xj] = x_data[xj];
      bsum_data[xj] = 0.0;
    }

    g_st.site = &pw_emlrtRSI;
    for (k = 2; k <= nx; k++) {
      xoffset = (k - 1) * vstride;
      g_st.site = &ow_emlrtRSI;
      scalarLB = (vstride / 2) << 1;
      vectorUB = scalarLB - 2;
      for (xj = 0; xj <= vectorUB; xj += 2) {
        r = _mm_loadu_pd(&b_posterior_data[xj]);
        r1 = _mm_loadu_pd(&x_data[xoffset + xj]);
        _mm_storeu_pd(&b_posterior_data[xj], _mm_add_pd(r, r1));
      }

      for (xj = scalarLB; xj < vstride; xj++) {
        b_posterior_data[xj] += x_data[xoffset + xj];
      }
    }

    g_st.site = &nw_emlrtRSI;
    for (ib = 2; ib <= nblocks; ib++) {
      nx = (ib - 1) * bvstride;
      g_st.site = &mkb_emlrtRSI;
      for (xj = 0; xj < vstride; xj++) {
        bsum_data[xj] = x_data[nx + xj];
      }

      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }

      g_st.site = &nkb_emlrtRSI;
      for (k = 2; k <= hi; k++) {
        xoffset = nx + (k - 1) * vstride;
        g_st.site = &okb_emlrtRSI;
        scalarLB = (vstride / 2) << 1;
        vectorUB = scalarLB - 2;
        for (xj = 0; xj <= vectorUB; xj += 2) {
          r = _mm_loadu_pd(&bsum_data[xj]);
          r1 = _mm_loadu_pd(&x_data[xoffset + xj]);
          _mm_storeu_pd(&bsum_data[xj], _mm_add_pd(r, r1));
        }

        for (xj = scalarLB; xj < vstride; xj++) {
          bsum_data[xj] += x_data[xoffset + xj];
        }
      }

      g_st.site = &pkb_emlrtRSI;
      scalarLB = (vstride / 2) << 1;
      vectorUB = scalarLB - 2;
      for (xj = 0; xj <= vectorUB; xj += 2) {
        r = _mm_loadu_pd(&b_posterior_data[xj]);
        r1 = _mm_loadu_pd(&bsum_data[xj]);
        _mm_storeu_pd(&b_posterior_data[xj], _mm_add_pd(r, r1));
      }

      for (xj = scalarLB; xj < vstride; xj++) {
        b_posterior_data[xj] += bsum_data[xj];
      }
    }

    emxFree_real_T(&f_st, &bsum);
  }

  emxFree_real_T(&e_st, &x);
  b_FJE[0] = FJE->size[0];
  b_FJE[1] = FJE->size[1] - 1;
  emlrtSubAssignSizeCheckR2012b(&b_FJE[0], 2, &b_posterior->size[0], 2,
    &bb_emlrtECI, &st);
  b_FJE[0] = FJE->size[0];
  nblocks = FJE->size[1] - 1;
  for (ib = 0; ib < nblocks; ib++) {
    nx = b_FJE[0];
    for (vstride = 0; vstride < nx; vstride++) {
      posterior_data[vstride + posterior->size[0] * ib] =
        b_posterior_data[vstride + b_FJE[0] * ib];
    }
  }

  if ((posterior->size[0] - 1 < 1) || (posterior->size[0] - 1 > posterior->size
       [0])) {
    emlrtDynamicBoundsCheckR2012b(posterior->size[0] - 1, 1, posterior->size[0],
      &jg_emlrtBCI, &st);
  }

  ib = b_posterior->size[0] * b_posterior->size[1];
  b_posterior->size[0] = posterior->size[0] - 1;
  b_posterior->size[1] = posterior->size[1];
  emxEnsureCapacity_real_T(&st, b_posterior, ib, &lm_emlrtRTEI);
  b_posterior_data = b_posterior->data;
  nblocks = posterior->size[1];
  for (ib = 0; ib < nblocks; ib++) {
    nx = posterior->size[0];
    for (vstride = 0; vstride <= nx - 2; vstride++) {
      b_posterior_data[vstride + b_posterior->size[0] * ib] =
        posterior_data[vstride + posterior->size[0] * ib];
    }
  }

  b_st.site = &jkb_emlrtRSI;
  sum(&b_st, b_posterior, varargin_2_data, varargin_2_size);
  emxFree_real_T(&st, &b_posterior);
  nblocks = varargin_2_size[1] - 1;
  scalarLB = (varargin_2_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (ib = 0; ib <= vectorUB; ib += 2) {
    r = _mm_loadu_pd(&varargin_2_data[ib]);
    _mm_storeu_pd(&varargin_2_data[ib], _mm_sub_pd(_mm_set1_pd(1.0), r));
  }

  for (ib = scalarLB; ib <= nblocks; ib++) {
    varargin_2_data[ib] = 1.0 - varargin_2_data[ib];
  }

  varargin_2_size[0] = 1;
  nblocks = varargin_2_size[1] - 1;
  for (ib = 0; ib <= nblocks; ib++) {
    varargin_2_data[ib] = muDoubleScalarMax(0.0, varargin_2_data[ib]);
  }

  b_FJE[0] = 1;
  b_FJE[1] = posterior->size[1];
  emlrtSubAssignSizeCheckR2012b(&b_FJE[0], 2, &varargin_2_size[0], 2,
    &ab_emlrtECI, &st);
  nblocks = posterior->size[1];
  for (ib = 0; ib < nblocks; ib++) {
    posterior_data[(posterior->size[0] + posterior->size[0] * ib) - 1] =
      varargin_2_data[ib];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void c_JPDATracker_updateAssignedTra(const emlrtStack *sp, trackerJPDA
  *obj, const emxArray_uint32_T *cluster_DetectionIndices, const uint32_T
  cluster_TrackIDs_data[], const int32_T cluster_TrackIDs_size[2], const
  emxArray_real_T *cluster_MarginalProbabilities, const emxArray_objectDetection
  *dets)
{
  d_matlabshared_tracking_interna *track;
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_boolean_T b_flag;
  emxArray_boolean_T *flag;
  emxArray_boolean_T *isoosm;
  emxArray_boolean_T *x;
  emxArray_objectDetection *b_dets;
  emxArray_real_T *b_cluster_MarginalProbabilities;
  emxArray_real_T *betas;
  emxArray_real_T *c_detTimes;
  emxArray_real_T *detTimes;
  emxArray_real_T *z;
  const objectDetection *dets_data;
  objectDetection *b_dets_data;
  trackHistoryLogic *c_obj;
  real_T c_dets_data[9];
  real_T varargin_1[2];
  const real_T *c_cluster_MarginalProbabilities;
  real_T *b_detTimes_data;
  real_T *detTimes_data;
  int32_T clusterTrackId_size[2];
  int32_T b_detTimes;
  int32_T b_i;
  int32_T b_isoosm;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T itilerow;
  int32_T loop_ub;
  int32_T ntilerows;
  int32_T tile_size;
  int32_T trackID;
  uint32_T clusterTrackId_data[31];
  const uint32_T *cluster_DetectionIndices_data;
  boolean_T *flag_data;
  boolean_T *isoosm_data;
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
  dets_data = dets->data;
  c_cluster_MarginalProbabilities = cluster_MarginalProbabilities->data;
  cluster_DetectionIndices_data = cluster_DetectionIndices->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &wkb_emlrtRSI;
  JPDATracker_findTracksByIDs(&st, obj, cluster_TrackIDs_data,
    cluster_TrackIDs_size, clusterTrackId_data, clusterTrackId_size);
  st.site = &xkb_emlrtRSI;
  b_st.site = &ykb_emlrtRSI;
  if (cluster_DetectionIndices->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, cluster_DetectionIndices->size[1],
      &ng_emlrtBCI, &b_st);
  }

  i = dets->size[0] * dets->size[1] - 1;
  i1 = (int32_T)cluster_DetectionIndices_data[0] - 1;
  if ((i1 < 0) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 0, i, &og_emlrtBCI, &b_st);
  }

  c_st.site = &flb_emlrtRSI;
  varargin_1[0] = cluster_DetectionIndices->size[1];
  varargin_1[1] = 1.0;
  d_st.site = &ib_emlrtRSI;
  assertValidSizeArg(&d_st, varargin_1);
  emxInit_objectDetection(&c_st, &b_dets, 2, &xm_emlrtRTEI, true);
  ntilerows = b_dets->size[0] * b_dets->size[1];
  b_dets->size[0] = cluster_DetectionIndices->size[1];
  b_dets->size[1] = 1;
  c_emxEnsureCapacity_objectDetec(&c_st, b_dets, ntilerows, &nm_emlrtRTEI);
  b_dets_data = b_dets->data;
  if (cluster_DetectionIndices->size[1] != 0) {
    ntilerows = cluster_DetectionIndices->size[1];
    d_st.site = &glb_emlrtRSI;
    if (cluster_DetectionIndices->size[1] > 2147483646) {
      e_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b_dets_data[itilerow] = dets_data[i1];
    }
  }

  i1 = cluster_DetectionIndices->size[1];
  for (b_i = 0; b_i <= i1 - 2; b_i++) {
    if (b_i + 2 > cluster_DetectionIndices->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, cluster_DetectionIndices->size[1],
        &tg_emlrtBCI, &b_st);
    }

    ntilerows = (int32_T)cluster_DetectionIndices_data[b_i + 1] - 1;
    if ((ntilerows < 0) || (ntilerows > i)) {
      emlrtDynamicBoundsCheckR2012b(ntilerows, 0, i, &sg_emlrtBCI, &b_st);
    }

    if (b_i + 1 > b_dets->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 0, b_dets->size[0] - 1,
        &ug_emlrtBCI, &b_st);
    }

    b_dets_data[b_i + 1] = dets_data[ntilerows];
  }

  b_st.site = &alb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  emxInit_real_T(&b_st, &detTimes, 2, &om_emlrtRTEI, true);
  i = detTimes->size[0] * detTimes->size[1];
  detTimes->size[0] = 1;
  detTimes->size[1] = b_obj->pDetectionTimes->size[1];
  emxEnsureCapacity_real_T(&b_st, detTimes, i, &om_emlrtRTEI);
  detTimes_data = detTimes->data;
  itilerow = b_obj->pDetectionTimes->size[1];
  for (i = 0; i < itilerow; i++) {
    detTimes_data[i] = b_obj->pDetectionTimes->data[i];
  }

  b_st.site = &blb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  emxInit_boolean_T(&b_st, &isoosm, 2, &pm_emlrtRTEI, true);
  i = isoosm->size[0] * isoosm->size[1];
  isoosm->size[0] = 1;
  isoosm->size[1] = b_obj->pIsOOSM->size[1];
  emxEnsureCapacity_boolean_T(&b_st, isoosm, i, &pm_emlrtRTEI);
  isoosm_data = isoosm->data;
  itilerow = b_obj->pIsOOSM->size[1];
  for (i = 0; i < itilerow; i++) {
    isoosm_data[i] = b_obj->pIsOOSM->data[i];
  }

  i = clusterTrackId_size[1];
  if (clusterTrackId_size[1] - 1 >= 0) {
    b_detTimes = detTimes->size[1];
    loop_ub = cluster_DetectionIndices->size[1];
    b_isoosm = isoosm->size[1];
    b_loop_ub = cluster_DetectionIndices->size[1];
    c_loop_ub = cluster_MarginalProbabilities->size[0];
    d_loop_ub = cluster_DetectionIndices->size[1];
  }

  emxInit_real_T(&st, &betas, 1, &rm_emlrtRTEI, true);
  emxInit_boolean_T(&st, &x, 2, &sm_emlrtRTEI, true);
  emxInit_real_T(&st, &z, 2, &ym_emlrtRTEI, true);
  emxInit_boolean_T(&st, &flag, 2, &tm_emlrtRTEI, true);
  emxInit_real_T(&st, &c_detTimes, 2, &qm_emlrtRTEI, true);
  emxInit_real_T(&st, &b_cluster_MarginalProbabilities, 1, &vm_emlrtRTEI, true);
  for (trackID = 0; trackID < i; trackID++) {
    real_T mtime;
    int32_T track_tmp_tmp;
    boolean_T y;
    if (trackID + 1 > clusterTrackId_size[1]) {
      emlrtDynamicBoundsCheckR2012b(trackID + 1, 1, clusterTrackId_size[1],
        &vg_emlrtBCI, &st);
    }

    track_tmp_tmp = (int32_T)clusterTrackId_data[trackID] - 1;
    track = obj->pTracksList[track_tmp_tmp];
    i1 = c_detTimes->size[0] * c_detTimes->size[1];
    c_detTimes->size[0] = 1;
    c_detTimes->size[1] = cluster_DetectionIndices->size[1];
    emxEnsureCapacity_real_T(&st, c_detTimes, i1, &qm_emlrtRTEI);
    b_detTimes_data = c_detTimes->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      if (((int32_T)cluster_DetectionIndices_data[i1] < 1) || ((int32_T)
           cluster_DetectionIndices_data[i1] > b_detTimes)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)cluster_DetectionIndices_data[i1],
          1, b_detTimes, &wg_emlrtBCI, &st);
      }

      b_detTimes_data[i1] = detTimes_data[(int32_T)
        cluster_DetectionIndices_data[i1] - 1];
    }

    b_st.site = &clb_emlrtRSI;
    mtime = b_mean(&b_st, c_detTimes);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (((int32_T)cluster_DetectionIndices_data[i1] < 1) || ((int32_T)
           cluster_DetectionIndices_data[i1] > b_isoosm)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)cluster_DetectionIndices_data[i1],
          1, b_isoosm, &xg_emlrtBCI, &st);
      }
    }

    if (b_dets->size[0] - 1 < 0) {
      emlrtDynamicBoundsCheckR2012b(0, 0, b_dets->size[0] - 1, &mg_emlrtBCI, &st);
    }

    b_st.site = &dlb_emlrtRSI;
    objectDetection_set_Time(&b_st, &b_dets_data[0], mtime);
    b_st.site = &elb_emlrtRSI;
    if (trackID + 1 > cluster_MarginalProbabilities->size[1]) {
      emlrtDynamicBoundsCheckR2012b(trackID + 1, 1,
        cluster_MarginalProbabilities->size[1], &lg_emlrtBCI, &b_st);
    }

    i1 = betas->size[0];
    betas->size[0] = cluster_MarginalProbabilities->size[0];
    emxEnsureCapacity_real_T(&b_st, betas, i1, &rm_emlrtRTEI);
    b_detTimes_data = betas->data;
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      b_detTimes_data[i1] = c_cluster_MarginalProbabilities[i1 +
        cluster_MarginalProbabilities->size[0] * trackID];
    }

    c_st.site = &hlb_emlrtRSI;
    i1 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = cluster_DetectionIndices->size[1];
    emxEnsureCapacity_boolean_T(&c_st, x, i1, &sm_emlrtRTEI);
    flag_data = x->data;
    for (i1 = 0; i1 < d_loop_ub; i1++) {
      flag_data[i1] = !isoosm_data[(int32_T)cluster_DetectionIndices_data[i1] -
        1];
    }

    y = (x->size[1] != 0);
    if (y) {
      boolean_T exitg1;
      d_st.site = &jlb_emlrtRSI;
      e_st.site = &klb_emlrtRSI;
      if (x->size[1] > 2147483646) {
        f_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      ntilerows = 0;
      exitg1 = false;
      while ((!exitg1) && (ntilerows <= x->size[1] - 1)) {
        if (!flag_data[ntilerows]) {
          y = false;
          exitg1 = true;
        } else {
          ntilerows++;
        }
      }
    }

    if (y) {
      uint32_T usedSensors[20];
      c_st.site = &ilb_emlrtRSI;
      for (i1 = 0; i1 < 20; i1++) {
        usedSensors[i1] = obj->pUsedSensors[i1];
      }

      if (b_dets->size[0] >= 1) {
        int32_T b_iv[2];
        int32_T N;
        uint32_T q0;
        uint32_T qY;
        d_st.site = &llb_emlrtRSI;
        ObjectTrack_predict(&d_st, track, b_dets_data[0].Time);
        if (b_dets->size[0] == 1) {
          d_st.site = &mlb_emlrtRSI;
          c_ObjectTrack_setAttributesFrom(&d_st, track, b_dets_data[0].
            SensorIndex, usedSensors);
        }

        d_st.site = &nlb_emlrtRSI;
        e_st.site = &vlb_emlrtRSI;
        N = b_dets->size[0];
        i1 = flag->size[0] * flag->size[1];
        flag->size[0] = b_dets->size[0];
        flag->size[1] = b_dets->size[0];
        emxEnsureCapacity_boolean_T(&e_st, flag, i1, &tm_emlrtRTEI);
        flag_data = flag->data;
        itilerow = b_dets->size[0] * b_dets->size[0];
        for (i1 = 0; i1 < itilerow; i1++) {
          flag_data[i1] = true;
        }

        i1 = b_dets->size[0];
        f_st.site = &ylb_emlrtRSI;
        for (b_i = 0; b_i <= i1 - 2; b_i++) {
          ntilerows = b_i + 2;
          f_st.site = &amb_emlrtRSI;
          if ((b_i + 2 <= N) && (N > 2147483646)) {
            g_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }

          for (itilerow = ntilerows; itilerow <= N; itilerow++) {
            if (b_i > b_dets->size[0] - 1) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, b_dets->size[0] - 1,
                &ah_emlrtBCI, &e_st);
            }

            if (itilerow - 1 > b_dets->size[0] - 1) {
              emlrtDynamicBoundsCheckR2012b(itilerow - 1, 0, b_dets->size[0] - 1,
                &bh_emlrtBCI, &e_st);
            }

            if (b_dets_data[b_i].ObjectClassID != b_dets_data[itilerow - 1].
                ObjectClassID) {
              if (b_i + 1 > flag->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, flag->size[0],
                  &ch_emlrtBCI, &e_st);
              }

              if (itilerow > flag->size[1]) {
                emlrtDynamicBoundsCheckR2012b(itilerow, 1, flag->size[1],
                  &dh_emlrtBCI, &e_st);
              }

              flag_data[b_i + flag->size[0] * (itilerow - 1)] = false;
              if (itilerow > flag->size[0]) {
                emlrtDynamicBoundsCheckR2012b(itilerow, 1, flag->size[0],
                  &eh_emlrtBCI, &e_st);
              }

              if (b_i + 1 > flag->size[1]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, flag->size[1],
                  &fh_emlrtBCI, &e_st);
              }

              flag_data[(itilerow + flag->size[0] * b_i) - 1] = false;
            }
          }
        }

        ntilerows = flag->size[0] * flag->size[1];
        b_flag = *flag;
        tile_size = ntilerows;
        b_flag.size = &tile_size;
        b_flag.numDimensions = 1;
        e_st.site = &wlb_emlrtRSI;
        if (b_all(&e_st, &b_flag)) {
          e_st.site = &xlb_emlrtRSI;
          if (b_dets_data[0].ObjectClassID != 0.0) {
            track->ObjectClassID = b_dets_data[0].ObjectClassID;
          }
        }

        d_st.site = &olb_emlrtRSI;
        memcpy(&c_dets_data[0], &b_dets_data[0].pMeasurementNoise[0], 9U *
               sizeof(real_T));
        e_st.site = &bmb_emlrtRSI;
        c_ExtendedKalmanFilter_set_Meas(&e_st, track->Filter, c_dets_data);
        i1 = z->size[0] * z->size[1];
        z->size[0] = 3;
        z->size[1] = b_dets->size[0];
        emxEnsureCapacity_real_T(&d_st, z, i1, &um_emlrtRTEI);
        b_detTimes_data = z->data;
        i1 = b_dets->size[0];
        for (b_i = 0; b_i < i1; b_i++) {
          if (b_i + 1 > z->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, z->size[1], &pg_emlrtBCI,
              &d_st);
          }

          if (b_i > b_dets->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, b_dets->size[0] - 1,
              &gh_emlrtBCI, &d_st);
          }

          b_detTimes_data[3 * b_i] = b_dets_data[b_i].Measurement[0];
          if (b_i > b_dets->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, b_dets->size[0] - 1,
              &gh_emlrtBCI, &d_st);
          }

          b_detTimes_data[3 * b_i + 1] = b_dets_data[b_i].Measurement[1];
          if (b_i > b_dets->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, b_dets->size[0] - 1,
              &gh_emlrtBCI, &d_st);
          }

          b_detTimes_data[3 * b_i + 2] = b_dets_data[b_i].Measurement[2];
        }

        e_st.site = &cmb_emlrtRSI;
        mtime = b_sum(&e_st, betas);
        itilerow = cluster_MarginalProbabilities->size[0];
        i1 = b_cluster_MarginalProbabilities->size[0];
        b_cluster_MarginalProbabilities->size[0] =
          cluster_MarginalProbabilities->size[0];
        emxEnsureCapacity_real_T(&c_st, b_cluster_MarginalProbabilities, i1,
          &vm_emlrtRTEI);
        b_detTimes_data = b_cluster_MarginalProbabilities->data;
        ntilerows = (cluster_MarginalProbabilities->size[0] / 2) << 1;
        N = ntilerows - 2;
        for (i1 = 0; i1 <= N; i1 += 2) {
          _mm_storeu_pd(&b_detTimes_data[i1], _mm_div_pd(_mm_loadu_pd
            (&c_cluster_MarginalProbabilities[i1 +
             cluster_MarginalProbabilities->size[0] * trackID]), _mm_set1_pd
            (mtime)));
        }

        for (i1 = ntilerows; i1 < itilerow; i1++) {
          b_detTimes_data[i1] = c_cluster_MarginalProbabilities[i1 +
            cluster_MarginalProbabilities->size[0] * trackID] / mtime;
        }

        d_st.site = &plb_emlrtRSI;
        trackingEKF_correctjpda(&d_st, track->Filter, z,
          b_cluster_MarginalProbabilities);
        q0 = track->pAge;
        qY = q0 + 1U;
        if (q0 + 1U < q0) {
          qY = MAX_uint32_T;
        }

        track->pAge = qY;
        track->UpdateTime = b_dets_data[0].Time;
        d_st.site = &qlb_emlrtRSI;
        if (cluster_MarginalProbabilities->size[0] - 1 < 1) {
          itilerow = 0;
        } else {
          if (cluster_MarginalProbabilities->size[0] < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1,
              cluster_MarginalProbabilities->size[0], &qg_emlrtBCI, &d_st);
          }

          if ((cluster_MarginalProbabilities->size[0] - 1 < 1) ||
              (cluster_MarginalProbabilities->size[0] - 1 >
               cluster_MarginalProbabilities->size[0])) {
            emlrtDynamicBoundsCheckR2012b(cluster_MarginalProbabilities->size[0]
              - 1, 1, cluster_MarginalProbabilities->size[0], &rg_emlrtBCI,
              &d_st);
          }

          itilerow = cluster_MarginalProbabilities->size[0] - 1;
        }

        b_iv[0] = 1;
        b_iv[1] = itilerow;
        e_st.site = &knb_emlrtRSI;
        indexShapeCheck(&e_st, cluster_MarginalProbabilities->size[0], b_iv);
        i1 = b_cluster_MarginalProbabilities->size[0];
        b_cluster_MarginalProbabilities->size[0] = itilerow;
        emxEnsureCapacity_real_T(&d_st, b_cluster_MarginalProbabilities, i1,
          &wm_emlrtRTEI);
        b_detTimes_data = b_cluster_MarginalProbabilities->data;
        for (i1 = 0; i1 < itilerow; i1++) {
          b_detTimes_data[i1] = c_cluster_MarginalProbabilities[i1 +
            cluster_MarginalProbabilities->size[0] * trackID];
        }

        e_st.site = &knb_emlrtRSI;
        mtime = b_sum(&e_st, b_cluster_MarginalProbabilities) / b_sum(&e_st,
          betas);
        if (mtime > 0.2) {
          boolean_T bv[50];
          track->pIsCoasted = false;
          e_st.site = &lnb_emlrtRSI;
          c_obj = track->TrackLogic;
          if (c_obj->pIsFirstUpdate) {
            emlrtErrorWithMessageIdR2018a(&e_st, &ad_emlrtRTEI,
              "shared_tracking:trackHistoryLogic:notInitialized",
              "shared_tracking:trackHistoryLogic:notInitialized", 3, 4, 3, "hit");
          }

          bv[0] = true;
          for (i1 = 0; i1 < 49; i1++) {
            bv[i1 + 1] = c_obj->pRecentHistory[i1];
          }

          for (i1 = 0; i1 < 50; i1++) {
            c_obj->pRecentHistory[i1] = bv[i1];
          }

          c_obj->pIsFirstUpdate = false;
        } else {
          boolean_T bv[50];
          track->pIsCoasted = true;
          e_st.site = &mnb_emlrtRSI;
          c_obj = track->TrackLogic;
          if (c_obj->pIsFirstUpdate) {
            emlrtErrorWithMessageIdR2018a(&e_st, &qc_emlrtRTEI,
              "shared_tracking:trackHistoryLogic:notInitialized",
              "shared_tracking:trackHistoryLogic:notInitialized", 3, 4, 4,
              "miss");
          }

          bv[0] = false;
          for (i1 = 0; i1 < 49; i1++) {
            bv[i1 + 1] = c_obj->pRecentHistory[i1];
          }

          for (i1 = 0; i1 < 50; i1++) {
            c_obj->pRecentHistory[i1] = bv[i1];
          }

          c_obj->pIsFirstUpdate = false;
        }

        if (!track->IsConfirmed) {
          d_st.site = &rlb_emlrtRSI;
          track->IsConfirmed = ObjectTrack_checkPromotion(track);
        }
      }
    }

    if (trackID + 1 > clusterTrackId_size[1]) {
      emlrtDynamicBoundsCheckR2012b(trackID + 1, 1, clusterTrackId_size[1],
        &yg_emlrtBCI, &st);
    }

    obj->pConfirmedTracks[track_tmp_tmp] = obj->pTracksList[track_tmp_tmp]
      ->IsConfirmed;
  }

  emxFree_real_T(&st, &b_cluster_MarginalProbabilities);
  emxFree_real_T(&st, &c_detTimes);
  emxFree_boolean_T(&st, &flag);
  emxFree_real_T(&st, &z);
  emxFree_boolean_T(&st, &x);
  emxFree_real_T(&st, &betas);
  emxFree_boolean_T(&st, &isoosm);
  emxFree_real_T(&st, &detTimes);
  emxFree_objectDetection(&st, &b_dets);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void c_JPDATracker_validateClusterDe(const emlrtStack *sp, trackerJPDA
  *obj, const emxArray_uint32_T *detIndices)
{
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_real_T *detTimes;
  emxArray_real_T *thisDetTimes;
  real_T d;
  real_T maxTime;
  real_T minTime;
  real_T *detTimes_data;
  real_T *thisDetTimes_data;
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
  const uint32_T *detIndices_data;
  boolean_T exitg1;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  detIndices_data = detIndices->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &fjb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  emxInit_real_T(&st, &detTimes, 2, &em_emlrtRTEI, true);
  idx = detTimes->size[0] * detTimes->size[1];
  detTimes->size[0] = 1;
  detTimes->size[1] = b_obj->pDetectionTimes->size[1];
  emxEnsureCapacity_real_T(&st, detTimes, idx, &em_emlrtRTEI);
  detTimes_data = detTimes->data;
  last = b_obj->pDetectionTimes->size[1];
  for (idx = 0; idx < last; idx++) {
    detTimes_data[idx] = b_obj->pDetectionTimes->data[idx];
  }

  emxInit_real_T(sp, &thisDetTimes, 2, &fm_emlrtRTEI, true);
  idx = thisDetTimes->size[0] * thisDetTimes->size[1];
  thisDetTimes->size[0] = 1;
  thisDetTimes->size[1] = detIndices->size[1];
  emxEnsureCapacity_real_T(sp, thisDetTimes, idx, &fm_emlrtRTEI);
  thisDetTimes_data = thisDetTimes->data;
  last = detIndices->size[1];
  for (idx = 0; idx < last; idx++) {
    if (((int32_T)detIndices_data[idx] < 1) || ((int32_T)detIndices_data[idx] >
         detTimes->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)detIndices_data[idx], 1,
        detTimes->size[1], &fg_emlrtBCI, (emlrtConstCTX)sp);
    }

    thisDetTimes_data[idx] = detTimes_data[(int32_T)detIndices_data[idx] - 1];
  }

  st.site = &gjb_emlrtRSI;
  b_st.site = &lf_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  d_st.site = &nf_emlrtRSI;
  if (detIndices->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &eb_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &of_emlrtRSI;
  f_st.site = &pf_emlrtRSI;
  last = detIndices->size[1];
  if (detIndices->size[1] <= 2) {
    if (detIndices->size[1] == 1) {
      maxTime = detTimes_data[(int32_T)detIndices_data[0] - 1];
    } else {
      maxTime = detTimes_data[(int32_T)detIndices_data[0] - 1];
      d = detTimes_data[(int32_T)detIndices_data[1] - 1];
      if ((maxTime < d) || (muDoubleScalarIsNaN(maxTime) &&
                            (!muDoubleScalarIsNaN(d)))) {
        maxTime = d;
      }
    }
  } else {
    g_st.site = &og_emlrtRSI;
    maxTime = detTimes_data[(int32_T)detIndices_data[0] - 1];
    if (!muDoubleScalarIsNaN(maxTime)) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &pg_emlrtRSI;
      if (detIndices->size[1] > 2147483646) {
        i_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(thisDetTimes_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      g_st.site = &be_emlrtRSI;
      maxTime = detTimes_data[(int32_T)detIndices_data[idx - 1] - 1];
      a = idx + 1;
      h_st.site = &ce_emlrtRSI;
      if ((idx + 1 <= detIndices->size[1]) && (detIndices->size[1] > 2147483646))
      {
        i_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= last; k++) {
        d = thisDetTimes_data[k - 1];
        if (maxTime < d) {
          maxTime = d;
        }
      }
    }
  }

  st.site = &hjb_emlrtRSI;
  b_st.site = &vd_emlrtRSI;
  c_st.site = &wd_emlrtRSI;
  d_st.site = &xd_emlrtRSI;
  e_st.site = &yd_emlrtRSI;
  f_st.site = &ae_emlrtRSI;
  last = detIndices->size[1];
  if (detIndices->size[1] <= 2) {
    if (detIndices->size[1] == 1) {
      minTime = detTimes_data[(int32_T)detIndices_data[0] - 1];
    } else {
      minTime = detTimes_data[(int32_T)detIndices_data[0] - 1];
      d = detTimes_data[(int32_T)detIndices_data[1] - 1];
      if ((minTime > d) || (muDoubleScalarIsNaN(minTime) &&
                            (!muDoubleScalarIsNaN(d)))) {
        minTime = d;
      }
    }
  } else {
    g_st.site = &og_emlrtRSI;
    minTime = detTimes_data[(int32_T)detIndices_data[0] - 1];
    if (!muDoubleScalarIsNaN(minTime)) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &pg_emlrtRSI;
      if (detIndices->size[1] > 2147483646) {
        i_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(thisDetTimes_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      g_st.site = &be_emlrtRSI;
      minTime = detTimes_data[(int32_T)detIndices_data[idx - 1] - 1];
      a = idx + 1;
      h_st.site = &ce_emlrtRSI;
      if ((idx + 1 <= detIndices->size[1]) && (detIndices->size[1] > 2147483646))
      {
        i_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= last; k++) {
        d = thisDetTimes_data[k - 1];
        if (minTime > d) {
          minTime = d;
        }
      }
    }
  }

  emxFree_real_T(&f_st, &thisDetTimes);
  st.site = &ijb_emlrtRSI;
  b_obj = obj->cDetectionManager;
  last = b_obj->pNumDetections;
  if (last < 1) {
    last = 0;
  } else {
    idx = b_obj->pOriginatingSensor->size[1];
    if (idx < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, idx, &xc_emlrtBCI, &st);
    }

    idx = b_obj->pOriginatingSensor->size[1];
    if (last > idx) {
      emlrtDynamicBoundsCheckR2012b(last, 1, idx, &wc_emlrtBCI, &st);
    }
  }

  idx = detTimes->size[0] * detTimes->size[1];
  detTimes->size[0] = 1;
  detTimes->size[1] = last;
  emxEnsureCapacity_real_T(&st, detTimes, idx, &gm_emlrtRTEI);
  detTimes_data = detTimes->data;
  for (idx = 0; idx < last; idx++) {
    detTimes_data[idx] = b_obj->pOriginatingSensor->data[idx];
  }

  if (((int32_T)detIndices_data[0] < 1) || ((int32_T)detIndices_data[0] >
       detTimes->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)detIndices_data[0], 1, detTimes->
      size[1], &gg_emlrtBCI, (emlrtConstCTX)sp);
  }

  if (maxTime - minTime > 1.0E-5) {
    emlrtErrorWithMessageIdR2018a(sp, &yc_emlrtRTEI,
      "fusion:trackerJPDA:SensorTimeTolerance",
      "fusion:trackerJPDA:SensorTimeTolerance", 5, 6, detTimes_data[(int32_T)
      detIndices_data[0] - 1], 4, 13, "TimeTolerance");
  }

  emxFree_real_T(sp, &detTimes);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void d_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1, const
  real_T in2_data[], const int32_T in2_size[2], const emxArray_real_T *in3,
  int32_T in4, int32_T in5, int32_T in6, int32_T in7)
{
  const real_T *in3_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in3_data = in3->data;
  loop_ub = in5 - in4;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub + 1;
  emxEnsureCapacity_real_T(sp, in1, i, &wo_emlrtRTEI);
  i = in7 - in6;
  if (i == 1) {
    b_loop_ub = in2_size[1];
  } else {
    b_loop_ub = i;
  }

  i1 = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i1, &wo_emlrtRTEI);
  in1_data = in1->data;
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (i != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    int32_T scalarLB;
    int32_T vectorUB;
    scalarLB = ((loop_ub + 1) / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      __m128d r;
      r = _mm_loadu_pd(&in3_data[(in4 + i1) + in3->size[0] * (in6 + aux_1_1)]);
      _mm_storeu_pd(&in1_data[i1 + in1->size[0] * i], _mm_mul_pd(_mm_set1_pd
        (in2_data[aux_0_1]), r));
    }

    for (i1 = scalarLB; i1 <= loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = in2_data[aux_0_1] * in3_data[(in4 + i1)
        + in3->size[0] * (in6 + aux_1_1)];
    }

    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

int32_T JPDATracker_stepImpl(const emlrtStack *sp, trackerJPDA *obj, const
  emxArray_objectDetection *detsIn, real_T varargin_1, const real_T
  varargin_2_data[], const int32_T varargin_2_size[2], struct1_T
  varargout_1_data[], struct1_T varargout_2_data[], struct1_T varargout_3_data[],
  int32_T *varargout_2_size, int32_T *varargout_3_size)
{
  e_matlabshared_tracking_interna *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emxArray_int32_T *b_y;
  emxArray_int32_T *ia;
  emxArray_objectDetection *dets;
  emxArray_objectDetection *r;
  emxArray_real_T *origSen;
  emxArray_real_T *sensorIDs;
  emxArray_uint32_T *newIndices;
  emxArray_uint32_T *y;
  const objectDetection *detsIn_data;
  objectDetection *dets_data;
  struct1_T st;
  real_T previousTime;
  real_T *origSen_data;
  int32_T b;
  int32_T b_i;
  int32_T i;
  int32_T n;
  int32_T numDets;
  int32_T varargout_1_size;
  int32_T *y_data;
  uint32_T *newIndices_data;
  int8_T b_tmp_data[30];
  int8_T c_tmp_data[30];
  int8_T tmp_data[30];
  int8_T ii_data;
  b_st.prev = sp;
  b_st.tls = sp->tls;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  detsIn_data = detsIn->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  b_st.site = &my_emlrtRSI;
  if (varargin_1 <= obj->pLastTimeStamp) {
    emlrtErrorWithMessageIdR2018a(&b_st, &lc_emlrtRTEI,
      "fusion:trackerJPDA:TimeMustIncrease",
      "fusion:trackerJPDA:TimeMustIncrease", 3, 4, 4, "step");
  }

  c_st.site = &py_emlrtRSI;
  d_st.site = &ry_emlrtRSI;
  b_obj = obj->cDetectionManager;
  previousTime = obj->pLastTimeStamp;
  if (b_obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(&d_st, &nb_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen",
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (b_obj->isInitialized != 1) {
    e_st.site = &lp_emlrtRSI;
    f_st.site = &mp_emlrtRSI;
    b_SystemCore_setup(&f_st, b_obj, detsIn);
    f_st.site = &mp_emlrtRSI;
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

  e_st.site = &lp_emlrtRSI;
  b_obj->pNumDetections = detsIn->size[0];
  i = b_obj->pOriginatingSensor->size[0] * b_obj->pOriginatingSensor->size[1];
  b_obj->pOriginatingSensor->size[0] = 1;
  b_obj->pOriginatingSensor->size[1] = detsIn->size[0];
  emxEnsureCapacity_real_T(&e_st, b_obj->pOriginatingSensor, i, &li_emlrtRTEI);
  numDets = detsIn->size[0];
  for (i = 0; i < numDets; i++) {
    b_obj->pOriginatingSensor->data[i] = 0.0;
  }

  i = b_obj->pIsOOSM->size[0] * b_obj->pIsOOSM->size[1];
  b_obj->pIsOOSM->size[0] = 1;
  b_obj->pIsOOSM->size[1] = detsIn->size[0];
  emxEnsureCapacity_boolean_T(&e_st, b_obj->pIsOOSM, i, &mi_emlrtRTEI);
  numDets = detsIn->size[0];
  for (i = 0; i < numDets; i++) {
    b_obj->pIsOOSM->data[i] = false;
  }

  i = b_obj->pDetectionTimes->size[0] * b_obj->pDetectionTimes->size[1];
  b_obj->pDetectionTimes->size[0] = 1;
  b_obj->pDetectionTimes->size[1] = detsIn->size[0];
  emxEnsureCapacity_real_T(&e_st, b_obj->pDetectionTimes, i, &ni_emlrtRTEI);
  numDets = detsIn->size[0];
  for (i = 0; i < numDets; i++) {
    b_obj->pDetectionTimes->data[i] = 0.0;
  }

  if (b_obj->pNumDetections > 0) {
    i = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
    b_obj->pDetections->size[0] = detsIn->size[0];
    b_obj->pDetections->size[1] = 1;
    c_emxEnsureCapacity_objectDetec(&e_st, b_obj->pDetections, i, &oi_emlrtRTEI);
    numDets = detsIn->size[0];
    for (i = 0; i < numDets; i++) {
      b_obj->pDetections->data[i] = detsIn_data[i];
    }

    f_st.site = &wy_emlrtRSI;
    numDets = b_obj->pOriginatingSensor->size[1];
    i = b_obj->pOriginatingSensor->size[0] * b_obj->pOriginatingSensor->size[1];
    b_obj->pOriginatingSensor->size[0] = 1;
    b_obj->pOriginatingSensor->size[1] = numDets;
    emxEnsureCapacity_real_T(&f_st, b_obj->pOriginatingSensor, i, &pi_emlrtRTEI);
    for (i = 0; i < numDets; i++) {
      b_obj->pOriginatingSensor->data[i] = 0.0;
    }

    numDets = b_obj->pIsOOSM->size[1];
    i = b_obj->pIsOOSM->size[0] * b_obj->pIsOOSM->size[1];
    b_obj->pIsOOSM->size[0] = 1;
    b_obj->pIsOOSM->size[1] = numDets;
    emxEnsureCapacity_boolean_T(&f_st, b_obj->pIsOOSM, i, &ri_emlrtRTEI);
    for (i = 0; i < numDets; i++) {
      b_obj->pIsOOSM->data[i] = false;
    }

    numDets = b_obj->pDetectionTimes->size[1];
    i = b_obj->pDetectionTimes->size[0] * b_obj->pDetectionTimes->size[1];
    b_obj->pDetectionTimes->size[0] = 1;
    b_obj->pDetectionTimes->size[1] = numDets;
    emxEnsureCapacity_real_T(&f_st, b_obj->pDetectionTimes, i, &si_emlrtRTEI);
    for (i = 0; i < numDets; i++) {
      b_obj->pDetectionTimes->data[i] = 0.0;
    }

    b = b_obj->pNumDetections;
    g_st.site = &xy_emlrtRSI;
    if (b > 2147483646) {
      h_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&h_st);
    }

    emxInit_objectDetection(&f_st, &r, 1, &fj_emlrtRTEI, true);
    for (b_i = 0; b_i < b; b_i++) {
      i = r->size[0];
      r->size[0] = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
      c_emxEnsureCapacity_objectDetec(&f_st, r, i, &vi_emlrtRTEI);
      dets_data = r->data;
      numDets = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
      for (i = 0; i < numDets; i++) {
        dets_data[i] = b_obj->pDetections->data[i];
      }

      if (b_i > r->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, r->size[0] - 1, &uc_emlrtBCI,
          &f_st);
      }

      if (dets_data[b_i].Time > varargin_1 + 1.0E-5) {
        emlrtErrorWithMessageIdR2018a(&f_st, &hc_emlrtRTEI,
          "shared_tracking:internal:TrackManager:DetectionTimeMismatch",
          "shared_tracking:internal:TrackManager:DetectionTimeMismatch", 3, 4, 4,
          "step");
      }

      i = r->size[0];
      r->size[0] = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
      c_emxEnsureCapacity_objectDetec(&f_st, r, i, &wi_emlrtRTEI);
      dets_data = r->data;
      numDets = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
      for (i = 0; i < numDets; i++) {
        dets_data[i] = b_obj->pDetections->data[i];
      }

      if (b_i > r->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, r->size[0] - 1, &yc_emlrtBCI,
          &f_st);
      }

      i = b_obj->pOriginatingSensor->size[1];
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &ad_emlrtBCI, &f_st);
      }

      b_obj->pOriginatingSensor->data[b_i] = dets_data[b_i].SensorIndex;
      i = r->size[0];
      r->size[0] = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
      c_emxEnsureCapacity_objectDetec(&f_st, r, i, &xi_emlrtRTEI);
      dets_data = r->data;
      numDets = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
      for (i = 0; i < numDets; i++) {
        dets_data[i] = b_obj->pDetections->data[i];
      }

      if (b_i > r->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, r->size[0] - 1, &tc_emlrtBCI,
          &f_st);
      }

      i = b_obj->pIsOOSM->size[1];
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &bd_emlrtBCI, &f_st);
      }

      b_obj->pIsOOSM->data[b_i] = (dets_data[b_i].Time <= previousTime);
      i = r->size[0];
      r->size[0] = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
      c_emxEnsureCapacity_objectDetec(&f_st, r, i, &aj_emlrtRTEI);
      dets_data = r->data;
      numDets = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
      for (i = 0; i < numDets; i++) {
        dets_data[i] = b_obj->pDetections->data[i];
      }

      if (b_i > r->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, r->size[0] - 1, &cd_emlrtBCI,
          &f_st);
      }

      i = b_obj->pDetectionTimes->size[1];
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &dd_emlrtBCI, &f_st);
      }

      b_obj->pDetectionTimes->data[b_i] = dets_data[b_i].Time;
      i = b_obj->pIsOOSM->size[1];
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &ed_emlrtBCI, &f_st);
      }

      if (b_obj->pIsOOSM->data[b_i]) {
        emlrtErrorWithMessageIdR2018a(&f_st, &gc_emlrtRTEI,
          "shared_tracking:internal:TrackManager:OOSMError",
          "shared_tracking:internal:TrackManager:OOSMError", 9, 4, 12,
          "OOSMHandling", 4, 9, "Terminate", 4, 4, "step");
      }
    }

    emxFree_objectDetection(&f_st, &r);
  } else {
    b_obj->pDetections->size[0] = 0;
    b_obj->pDetections->size[1] = 1;
  }

  d_st.site = &sy_emlrtRSI;
  b_obj = obj->cDetectionManager;
  numDets = b_obj->pNumDetections;
  if (numDets < 1) {
    numDets = 0;
  } else {
    i = b_obj->pOriginatingSensor->size[1];
    if (i < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &xc_emlrtBCI, &d_st);
    }

    i = b_obj->pOriginatingSensor->size[1];
    if (numDets > i) {
      emlrtDynamicBoundsCheckR2012b(numDets, 1, i, &wc_emlrtBCI, &d_st);
    }
  }

  emxInit_real_T(&d_st, &origSen, 2, &qi_emlrtRTEI, true);
  i = origSen->size[0] * origSen->size[1];
  origSen->size[0] = 1;
  origSen->size[1] = numDets;
  emxEnsureCapacity_real_T(&d_st, origSen, i, &qi_emlrtRTEI);
  origSen_data = origSen->data;
  for (i = 0; i < numDets; i++) {
    origSen_data[i] = b_obj->pOriginatingSensor->data[i];
  }

  d_st.site = &ty_emlrtRSI;
  b_obj = obj->cDetectionManager;
  numDets = b_obj->pNumDetections;
  if (numDets > 0) {
    uint32_T x[20];
    d_st.site = &uy_emlrtRSI;
    emxInit_real_T(&d_st, &sensorIDs, 2, &bj_emlrtRTEI, true);
    e_st.site = &fj_emlrtRSI;
    b_unique_vector(&e_st, origSen, sensorIDs);
    origSen_data = sensorIDs->data;
    d_st.site = &vy_emlrtRSI;
    emxInit_uint32_T(&d_st, &y, 2, &dj_emlrtRTEI, true);
    e_st.site = &aab_emlrtRSI;
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = sensorIDs->size[1];
    emxEnsureCapacity_uint32_T(&e_st, y, i, &ui_emlrtRTEI);
    newIndices_data = y->data;
    numDets = sensorIDs->size[1];
    for (i = 0; i < numDets; i++) {
      uint32_T u;
      previousTime = muDoubleScalarRound(origSen_data[i]);
      if (previousTime < 4.294967296E+9) {
        if (previousTime >= 0.0) {
          u = (uint32_T)previousTime;
        } else {
          u = 0U;
        }
      } else if (previousTime >= 4.294967296E+9) {
        u = MAX_uint32_T;
      } else {
        u = 0U;
      }

      newIndices_data[i] = u;
    }

    emxFree_real_T(&e_st, &sensorIDs);
    f_st.site = &tj_emlrtRSI;
    c_sort(&f_st, y);
    e_st.site = &aab_emlrtRSI;
    for (i = 0; i < 20; i++) {
      x[i] = obj->pUsedSensors[i];
    }

    f_st.site = &tj_emlrtRSI;
    d_sort(&f_st, x);
    e_st.site = &aab_emlrtRSI;
    f_st.site = &cab_emlrtRSI;
    emxInit_uint32_T(&f_st, &newIndices, 2, &cj_emlrtRTEI, true);
    emxInit_int32_T(&f_st, &ia, 1, &yi_emlrtRTEI);
    g_st.site = &dab_emlrtRSI;
    do_vectors(&g_st, y, x, newIndices, ia);
    newIndices_data = newIndices->data;
    emxFree_int32_T(&f_st, &ia);
    emxFree_uint32_T(&f_st, &y);
    i = newIndices->size[1];
    for (b_i = 0; b_i < i; b_i++) {
      boolean_T in[20];
      boolean_T exitg1;
      for (numDets = 0; numDets < 20; numDets++) {
        in[numDets] = (obj->pUsedSensors[numDets] == 0U);
      }

      numDets = 0;
      b = 0;
      exitg1 = false;
      while ((!exitg1) && (b < 20)) {
        if (in[b]) {
          numDets = 1;
          ii_data = (int8_T)(b + 1);
          exitg1 = true;
        } else {
          b++;
        }
      }

      if (numDets == 0) {
        emlrtErrorWithMessageIdR2018a(&d_st, &jc_emlrtRTEI,
          "shared_tracking:internal:TrackManager:invalidDetectionSensorIndex",
          "shared_tracking:internal:TrackManager:invalidDetectionSensorIndex", 0);
      }

      if (b_i + 1 > newIndices->size[1]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, newIndices->size[1],
          &gd_emlrtBCI, &d_st);
      }

      obj->pUsedSensors[ii_data - 1] = newIndices_data[b_i];
    }

    emxFree_uint32_T(&d_st, &newIndices);
  }

  emxFree_real_T(&c_st, &origSen);
  c_st.site = &qy_emlrtRSI;
  b_obj = obj->cDetectionManager;
  emxInit_objectDetection(&c_st, &dets, 2, &yi_emlrtRTEI, true);
  if (b_obj->pNumDetections > 0) {
    i = dets->size[0] * dets->size[1];
    dets->size[0] = b_obj->pDetections->size[0];
    dets->size[1] = b_obj->pDetections->size[1];
    c_emxEnsureCapacity_objectDetec(&c_st, dets, i, &ti_emlrtRTEI);
    dets_data = dets->data;
    numDets = b_obj->pDetections->size[0] * b_obj->pDetections->size[1];
    for (i = 0; i < numDets; i++) {
      dets_data[i] = b_obj->pDetections->data[i];
    }
  } else {
    dets->size[0] = 0;
    dets->size[1] = 0;
  }

  b_st.site = &ny_emlrtRSI;
  JPDATracker_coreAlgorithm(&b_st, obj, dets, varargin_1, varargin_2_data,
    varargin_2_size);
  emxFree_objectDetection(sp, &dets);
  b_st.site = &oy_emlrtRSI;
  c_st.site = &rob_emlrtRSI;
  n = obj->pNumLiveTracks;
  if (n > 30) {
    emlrtErrorWithMessageIdR2018a(&c_st, &kc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (n < 0) {
    emlrtNonNegativeCheckR2012b(n, &h_emlrtDCI, &c_st);
  }

  d_st.site = &sob_emlrtRSI;
  e_st.site = &tob_emlrtRSI;
  numDets = obj->pNumLiveTracks;
  if (numDets > 30) {
    emlrtErrorWithMessageIdR2018a(&e_st, &ic_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  emxInit_int32_T(&e_st, &b_y, 2, &ej_emlrtRTEI);
  f_st.site = &xab_emlrtRSI;
  g_st.site = &yab_emlrtRSI;
  h_st.site = &abb_emlrtRSI;
  eml_integer_colon_dispatcher(&h_st, numDets, b_y);
  y_data = b_y->data;
  numDets = n - 1;
  *varargout_3_size = 0;
  for (b_i = 0; b_i <= numDets; b_i++) {
    (*varargout_3_size)++;
    tmp_data[b_i] = (int8_T)b_i;
  }

  for (i = 0; i < *varargout_3_size; i++) {
    ii_data = tmp_data[i];
    if (ii_data > b_y->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(ii_data, 0, b_y->size[1] - 1, &fd_emlrtBCI,
        &d_st);
    }
  }

  e_st.site = &uob_emlrtRSI;
  f_st.site = &yob_emlrtRSI;
  f_st.site = &yob_emlrtRSI;
  ObjectTrack_trackToStruct(&f_st, obj->pTracksList[0], &st);
  f_st.site = &xob_emlrtRSI;
  g_st.site = &ib_emlrtRSI;
  for (i = 0; i < *varargout_3_size; i++) {
    varargout_3_data[i] = st;
  }

  if (*varargout_3_size > 0) {
    f_st.site = &wob_emlrtRSI;
    for (b_i = 0; b_i < *varargout_3_size; b_i++) {
      f_st.site = &vob_emlrtRSI;
      if (b_i + 1 > *varargout_3_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, *varargout_3_size,
          &vc_emlrtBCI, &e_st);
      }

      i = y_data[tmp_data[b_i]] - 1;
      if ((i < 0) || (i > 29)) {
        emlrtDynamicBoundsCheckR2012b(i, 0, 29, &hd_emlrtBCI, &e_st);
      }

      if (b_i + 1 > *varargout_3_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, *varargout_3_size,
          &id_emlrtBCI, &e_st);
      }

      f_st.site = &vob_emlrtRSI;
      ObjectTrack_trackToStruct(&f_st, obj->pTracksList[i],
        &varargout_3_data[b_i]);
    }
  }

  emxFree_int32_T(&e_st, &b_y);
  varargout_1_size = 0;
  for (b_i = 0; b_i < 30; b_i++) {
    if (obj->pConfirmedTracks[b_i]) {
      varargout_1_size++;
    }
  }

  b = 0;
  for (b_i = 0; b_i < 30; b_i++) {
    if (obj->pConfirmedTracks[b_i]) {
      b_tmp_data[b] = (int8_T)b_i;
      b++;
    }
  }

  for (i = 0; i < varargout_1_size; i++) {
    ii_data = b_tmp_data[i];
    if (ii_data > *varargout_3_size - 1) {
      emlrtDynamicBoundsCheckR2012b(ii_data, 0, *varargout_3_size - 1,
        &jd_emlrtBCI, &c_st);
    }

    varargout_1_data[i] = varargout_3_data[ii_data];
  }

  if (n < 1) {
    n = 0;
  }

  numDets = n - 1;
  *varargout_2_size = 0;
  for (b_i = 0; b_i <= numDets; b_i++) {
    if (!obj->pConfirmedTracks[b_i]) {
      (*varargout_2_size)++;
    }
  }

  b = 0;
  for (b_i = 0; b_i <= numDets; b_i++) {
    if (!obj->pConfirmedTracks[b_i]) {
      c_tmp_data[b] = (int8_T)b_i;
      b++;
    }
  }

  for (i = 0; i < *varargout_2_size; i++) {
    ii_data = c_tmp_data[i];
    if (ii_data > *varargout_3_size - 1) {
      emlrtDynamicBoundsCheckR2012b(ii_data, 0, *varargout_3_size - 1,
        &kd_emlrtBCI, &c_st);
    }

    varargout_2_data[i] = varargout_3_data[ii_data];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return varargout_1_size;
}

void JPDATracker_validateInputsImpl(const emlrtStack *sp, real_T varargin_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pp_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &qp_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_1) || muDoubleScalarIsNaN(varargin_1)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:step:expectedFinite", 3, 4, 4, "time");
  }

  c_st.site = &jc_emlrtRSI;
  if (varargin_1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &ib_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonnegative",
      "MATLAB:step:expectedNonnegative", 3, 4, 4, "time");
  }
}

/* End of code generation (JPDATracker.c) */
