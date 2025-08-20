//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  trackerJPDA.cpp
//
//  Code generation for function 'trackerJPDA'
//


// Include files
#include "trackerJPDA.h"
#include "AssignmentCostCalculator.h"
#include "ObjectTrack.h"
#include "SystemCore.h"
#include "all.h"
#include "assertValidSizeArg.h"
#include "combineVectorElements.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "initializeEKF.h"
#include "jpdaEvents.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "nullAssignment.h"
#include "objectDetection.h"
#include "power.h"
#include "prod.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "trackHistoryLogic.h"
#include "trackingEKF.h"
#include "unique.h"
#include "warning.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <string.h>

// Type Definitions
struct struct_T
{
  coder::array<real_T, 2U> DetectionIndices;
  coder::array<uint32_T, 2U> TrackIDs;
  coder::array<real_T, 2U> ValidationMatrix;
  uint32_T SensorIndex;
  real_T TimeStamp;
  coder::array<real_T, 2U> MarginalProbabilities;
};

// Variable Definitions
static emlrtRSInfo as_emlrtRSI = { 1052,// lineNo
  "trackerJPDA/validateInputsImpl",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo bs_emlrtRSI = { 1080,// lineNo
  "trackerJPDA/setupImpl",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo cs_emlrtRSI = { 1105,// lineNo
  "trackerJPDA/setupImpl",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ds_emlrtRSI = { 1120,// lineNo
  "trackerJPDA/setupImpl",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo es_emlrtRSI = { 1140,// lineNo
  "trackerJPDA",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo fs_emlrtRSI = { 1093,// lineNo
  "trackerJPDA/setupImpl",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo gs_emlrtRSI = { 1113,// lineNo
  "trackerJPDA/setupImpl",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo uu_emlrtRSI = { 2562,// lineNo
  "createLogic",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo wu_emlrtRSI = { 325,// lineNo
  "TrackManager/setupImpl",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo xu_emlrtRSI = { 335,// lineNo
  "TrackManager/setupImpl",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo yu_emlrtRSI = { 324,// lineNo
  "TrackManager",                      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo av_emlrtRSI = { 330,// lineNo
  "TrackManager/setupImpl",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo bv_emlrtRSI = { 340,// lineNo
  "TrackManager/setupImpl",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo cv_emlrtRSI = { 1121,// lineNo
  "allocateTrack",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo ev_emlrtRSI = { 1089,// lineNo
  "allocateTrack",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo kx_emlrtRSI = { 1149,// lineNo
  "trackerJPDA/resetImpl",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo lx_emlrtRSI = { 348,// lineNo
  "TrackManager/resetImpl",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo nx_emlrtRSI = { 1303,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ox_emlrtRSI = { 1306,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo px_emlrtRSI = { 1310,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo qx_emlrtRSI = { 1311,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo rx_emlrtRSI = { 1314,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo sx_emlrtRSI = { 1319,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo tx_emlrtRSI = { 1323,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ux_emlrtRSI = { 1326,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo vx_emlrtRSI = { 1329,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo wx_emlrtRSI = { 1332,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo xx_emlrtRSI = { 1352,// lineNo
  "trackerJPDA/stepImpl",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo yx_emlrtRSI = { 1620,// lineNo
  "trackerJPDA/preprocessDetections",  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo dy_emlrtRSI = { 1666,// lineNo
  "trackerJPDA/trackDetectability",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ey_emlrtRSI = { 1670,// lineNo
  "trackerJPDA/trackDetectability",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo fy_emlrtRSI = { 1676,// lineNo
  "trackerJPDA/trackDetectability",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo gy_emlrtRSI = { 1982,// lineNo
  "trackerJPDA/predictTracks",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo vab_emlrtRSI = { 1411,// lineNo
  "trackerJPDA/clusterAssignUpdate",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo wab_emlrtRSI = { 1414,// lineNo
  "trackerJPDA/clusterAssignUpdate",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo xab_emlrtRSI = { 1419,// lineNo
  "trackerJPDA/clusterAssignUpdate",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo yab_emlrtRSI = { 1431,// lineNo
  "trackerJPDA/createClusters",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo abb_emlrtRSI = { 1437,// lineNo
  "trackerJPDA/createClusters",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo bbb_emlrtRSI = { 1440,// lineNo
  "trackerJPDA/createClusters",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo cbb_emlrtRSI = { 1444,// lineNo
  "trackerJPDA/createClusters",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo dbb_emlrtRSI = { 1928,// lineNo
  "trackerJPDA/selectDetections",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ebb_emlrtRSI = { 1455,// lineNo
  "trackerJPDA/sensorValidationMatrix",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo fbb_emlrtRSI = { 1461,// lineNo
  "trackerJPDA/sensorValidationMatrix",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo gbb_emlrtRSI = { 1383,// lineNo
  "trackerJPDA/calcCostMatrix",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ceb_emlrtRSI = { 1485,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo deb_emlrtRSI = { 1486,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo eeb_emlrtRSI = { 1488,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo feb_emlrtRSI = { 1493,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo geb_emlrtRSI = { 1494,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo heb_emlrtRSI = { 1497,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ieb_emlrtRSI = { 1504,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo jeb_emlrtRSI = { 1506,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo keb_emlrtRSI = { 1508,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo leb_emlrtRSI = { 1510,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo meb_emlrtRSI = { 1512,// lineNo
  "trackerJPDA/clusterDetections",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo reb_emlrtRSI = { 2520,// lineNo
  "trackerJPDA/connectedTracks",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo seb_emlrtRSI = { 2523,// lineNo
  "trackerJPDA/connectedTracks",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo cfb_emlrtRSI = { 1528,// lineNo
  "trackerJPDA/jpdaClusterUpdate",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo dfb_emlrtRSI = { 1547,// lineNo
  "trackerJPDA/jpdaClusterUpdate",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo efb_emlrtRSI = { 1548,// lineNo
  "trackerJPDA/jpdaClusterUpdate",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ffb_emlrtRSI = { 1552,// lineNo
  "trackerJPDA/jpdaClusterUpdate",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo gfb_emlrtRSI = { 1555,// lineNo
  "trackerJPDA/jpdaClusterUpdate",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo hfb_emlrtRSI = { 1558,// lineNo
  "trackerJPDA/jpdaClusterUpdate",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ifb_emlrtRSI = { 1564,// lineNo
  "trackerJPDA/jpdaClusterUpdate",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo jfb_emlrtRSI = { 1567,// lineNo
  "trackerJPDA/jpdaClusterUpdate",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo kfb_emlrtRSI = { 1575,// lineNo
  "trackerJPDA/jpdaClusterUpdate",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo lfb_emlrtRSI = { 2007,// lineNo
  "trackerJPDA/validateClusterDetectionsTime",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo mfb_emlrtRSI = { 2008,// lineNo
  "trackerJPDA/validateClusterDetectionsTime",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo nfb_emlrtRSI = { 1934,// lineNo
  "trackerJPDA/findTracksByIDs",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ofb_emlrtRSI = { 1703,// lineNo
  "trackerJPDA/likelihoodMatrix",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo pfb_emlrtRSI = { 1708,// lineNo
  "trackerJPDA/likelihoodMatrix",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo qfb_emlrtRSI = { 1712,// lineNo
  "trackerJPDA/likelihoodMatrix",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo tgb_emlrtRSI = { 1890,// lineNo
  "trackerJPDA/calcEventProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ugb_emlrtRSI = { 1892,// lineNo
  "trackerJPDA/calcEventProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo vgb_emlrtRSI = { 1898,// lineNo
  "trackerJPDA/calcEventProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo wgb_emlrtRSI = { 1904,// lineNo
  "trackerJPDA/calcEventProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo xgb_emlrtRSI = { 1905,// lineNo
  "trackerJPDA/calcEventProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ygb_emlrtRSI = { 1911,// lineNo
  "trackerJPDA/calcEventProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ghb_emlrtRSI = { 1847,// lineNo
  "trackerJPDA/associationProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo hhb_emlrtRSI = { 1848,// lineNo
  "trackerJPDA/associationProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ihb_emlrtRSI = { 1850,// lineNo
  "trackerJPDA/associationProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo jhb_emlrtRSI = { 1851,// lineNo
  "trackerJPDA/associationProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo khb_emlrtRSI = { 1857,// lineNo
  "trackerJPDA/associationProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo lhb_emlrtRSI = { 1863,// lineNo
  "trackerJPDA/associationProbabilities",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ohb_emlrtRSI = { 1862,// lineNo
  "@(x,n)round(x.*10.^n)./(10.^n)",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo phb_emlrtRSI = { 10,// lineNo
  "round",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/round.m"// pathName
};

static emlrtRSInfo qhb_emlrtRSI = { 1942,// lineNo
  "trackerJPDA/identLowProbDet",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo rhb_emlrtRSI = { 1943,// lineNo
  "trackerJPDA/identLowProbDet",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo shb_emlrtRSI = { 22,// lineNo
  "nullAssignment",                    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo thb_emlrtRSI = { 26,// lineNo
  "nullAssignment",                    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo uhb_emlrtRSI = { 274,// lineNo
  "delete_rows",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo vhb_emlrtRSI = { 275,// lineNo
  "delete_rows",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pathName 
};

static emlrtRSInfo whb_emlrtRSI = { 1630,// lineNo
  "trackerJPDA/updateAssignedTracks",  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo xhb_emlrtRSI = { 1632,// lineNo
  "trackerJPDA/updateAssignedTracks",  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo yhb_emlrtRSI = { 1731,// lineNo
  "trackerJPDA/updateClusterTracks",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo aib_emlrtRSI = { 1737,// lineNo
  "trackerJPDA/updateClusterTracks",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo bib_emlrtRSI = { 1738,// lineNo
  "trackerJPDA/updateClusterTracks",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo cib_emlrtRSI = { 1740,// lineNo
  "trackerJPDA/updateClusterTracks",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo dib_emlrtRSI = { 1749,// lineNo
  "trackerJPDA/extractDetectionsForCluster",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo eib_emlrtRSI = { 144,// lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

static emlrtRSInfo fib_emlrtRSI = { 139,// lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

static emlrtRSInfo kjb_emlrtRSI = { 1762,// lineNo
  "trackerJPDA/initializeTracks",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ljb_emlrtRSI = { 1769,// lineNo
  "trackerJPDA/initializeTracks",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo mjb_emlrtRSI = { 1790,// lineNo
  "trackerJPDA/initializeTracks",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo njb_emlrtRSI = { 1798,// lineNo
  "trackerJPDA/initializeTracks",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ojb_emlrtRSI = { 1808,// lineNo
  "trackerJPDA/initializeTracks",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo pjb_emlrtRSI = { 1773,// lineNo
  "trackerJPDA/initializeTracks",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo qjb_emlrtRSI = { 539,// lineNo
  "TrackManager/initiateTrack",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo rjb_emlrtRSI = { 535,// lineNo
  "TrackManager/initiateTrack",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo sjb_emlrtRSI = { 534,// lineNo
  "TrackManager/initiateTrack",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo tjb_emlrtRSI = { 528,// lineNo
  "TrackManager/initiateTrack",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo ujb_emlrtRSI = { 526,// lineNo
  "TrackManager/initiateTrack",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo vjb_emlrtRSI = { 519,// lineNo
  "TrackManager/initiateTrack",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo wjb_emlrtRSI = { 559,// lineNo
  "TrackManager/initializeFilter",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo xjb_emlrtRSI = { 564,// lineNo
  "TrackManager/initializeFilter",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo yjb_emlrtRSI = { 565,// lineNo
  "TrackManager/initializeFilter",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo akb_emlrtRSI = { 554,// lineNo
  "TrackManager/initializeFilter",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo bkb_emlrtRSI = { 1950,// lineNo
  "trackerJPDA/coastUnassignedTracks", // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo dkb_emlrtRSI = { 1965,// lineNo
  "trackerJPDA/deleteOldTracks",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo ekb_emlrtRSI = { 1969,// lineNo
  "trackerJPDA/deleteOldTracks",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pathName
};

static emlrtRSInfo hkb_emlrtRSI = { 580,// lineNo
  "TrackManager/recycleTracks",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo ikb_emlrtRSI = { 748,// lineNo
  "TrackManager/formatTrackOutputs",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo jkb_emlrtRSI = { 770,// lineNo
  "TrackManager/getTracks",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo kkb_emlrtRSI = { 778,// lineNo
  "TrackManager/getTracks",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo lkb_emlrtRSI = { 833,// lineNo
  "TrackManager/getTracksCodegen",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo mkb_emlrtRSI = { 835,// lineNo
  "TrackManager/getTracksCodegen",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRSInfo nkb_emlrtRSI = { 840,// lineNo
  "TrackManager/getTracksCodegen",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pathName 
};

static emlrtRTEInfo rb_emlrtRTEI = { 1979,// lineNo
  23,                                  // colNo
  "trackerJPDA/predictTracks",         // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo ic_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1951,                                // lineNo
  56,                                  // colNo
  "",                                  // aName
  "trackerJPDA/coastUnassignedTracks", // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo sb_emlrtRTEI = { 1614,// lineNo
  25,                                  // colNo
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo jc_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1347,                                // lineNo
  53,                                  // colNo
  "",                                  // aName
  "trackerJPDA/stepImpl",              // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo h_emlrtDCI = { 1347,// lineNo
  53,                                  // colNo
  "trackerJPDA/stepImpl",              // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo kc_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1300,                                // lineNo
  40,                                  // colNo
  "",                                  // aName
  "trackerJPDA/stepImpl",              // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo i_emlrtDCI = { 1300,// lineNo
  40,                                  // colNo
  "trackerJPDA/stepImpl",              // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtRTEInfo tb_emlrtRTEI = { 1294,// lineNo
  21,                                  // colNo
  "trackerJPDA/stepImpl",              // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtDCInfo j_emlrtDCI = { 1594,// lineNo
  37,                                  // colNo
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo k_emlrtDCI = { 1594,// lineNo
  37,                                  // colNo
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo l_emlrtDCI = { 1594,// lineNo
  13,                                  // colNo
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo m_emlrtDCI = { 1594,// lineNo
  13,                                  // colNo
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo lc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1612,                                // lineNo
  26,                                  // colNo
  "",                                  // aName
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1613,                                // lineNo
  25,                                  // colNo
  "",                                  // aName
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nc_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  1980,                                // lineNo
  29,                                  // colNo
  "",                                  // aName
  "trackerJPDA/predictTracks",         // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1616,                                // lineNo
  46,                                  // colNo
  "",                                  // aName
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1616,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qc_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1949,                                // lineNo
  20,                                  // colNo
  "",                                  // aName
  "trackerJPDA/coastUnassignedTracks", // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1949,                                // lineNo
  20,                                  // colNo
  "",                                  // aName
  "trackerJPDA/coastUnassignedTracks", // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1617,                                // lineNo
  49,                                  // colNo
  "",                                  // aName
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1617,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "trackerJPDA/preprocessDetections",  // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1951,                                // lineNo
  56,                                  // colNo
  "",                                  // aName
  "trackerJPDA/coastUnassignedTracks", // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vc_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  1950,                                // lineNo
  41,                                  // colNo
  "",                                  // aName
  "trackerJPDA/coastUnassignedTracks", // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1950,                                // lineNo
  41,                                  // colNo
  "",                                  // aName
  "trackerJPDA/coastUnassignedTracks", // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1336,                                // lineNo
  36,                                  // colNo
  "",                                  // aName
  "trackerJPDA/stepImpl",              // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yc_emlrtBCI = { 1,  // iFirst
  4,                                   // iLast
  137,                                 // lineNo
  20,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo vb_emlrtRTEI = { 2550,// lineNo
  9,                                   // colNo
  "getDetectionFromInput",             // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo ad_emlrtBCI = { 1,  // iFirst
  2,                                   // iLast
  102,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  89,                                  // lineNo
  35,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dd_emlrtBCI = { 1,  // iFirst
  4,                                   // iLast
  119,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  3                                    // checkKind
};

static emlrtRTEInfo xb_emlrtRTEI = { 1056,// lineNo
  21,                                  // colNo
  "trackerJPDA/validateInputsImpl",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtDCInfo o_emlrtDCI = { 1655,// lineNo
  38,                                  // colNo
  "trackerJPDA/trackDetectability",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ed_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1655,                                // lineNo
  38,                                  // colNo
  "",                                  // aName
  "trackerJPDA/trackDetectability",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1676,                                // lineNo
  58,                                  // colNo
  "",                                  // aName
  "trackerJPDA/trackDetectability",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo dc_emlrtRTEI = { 28,// lineNo
  27,                                  // colNo
  "validatelt",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatelt.m"// pName 
};

static emlrtBCInfo gd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1679,                                // lineNo
  29,                                  // colNo
  "",                                  // aName
  "trackerJPDA/trackDetectability",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1437,                                // lineNo
  69,                                  // colNo
  "",                                  // aName
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo id_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1444,                                // lineNo
  109,                                 // colNo
  "",                                  // aName
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtECInfo k_emlrtECI = { -1,  // nDims
  1448,                                // lineNo
  17,                                  // colNo
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtECInfo l_emlrtECI = { -1,  // nDims
  1456,                                // lineNo
  13,                                  // colNo
  "trackerJPDA/sensorValidationMatrix",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo jd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1484,                                // lineNo
  35,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo ec_emlrtRTEI = { 1505,// lineNo
  19,                                  // colNo
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo kd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1506,                                // lineNo
  69,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ld_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1508,                                // lineNo
  88,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo md_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1510,                                // lineNo
  82,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtECInfo m_emlrtECI = { -1,  // nDims
  705,                                 // lineNo
  13,                                  // colNo
  "TrackManager/trackIDs",             // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtRTEInfo gc_emlrtRTEI = { 58,// lineNo
  23,                                  // colNo
  "assertValidSizeArg",                // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"// pName 
};

static emlrtDCInfo q_emlrtDCI = { 1430,// lineNo
  46,                                  // colNo
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo r_emlrtDCI = { 1430,// lineNo
  46,                                  // colNo
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo nd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1507,                                // lineNo
  26,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo od_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1512,                                // lineNo
  75,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo s_emlrtDCI = { 1430,// lineNo
  13,                                  // colNo
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo t_emlrtDCI = { 1430,// lineNo
  13,                                  // colNo
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo pd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1417,                                // lineNo
  40,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterAssignUpdate",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1456,                                // lineNo
  31,                                  // colNo
  "",                                  // aName
  "trackerJPDA/sensorValidationMatrix",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1447,                                // lineNo
  58,                                  // colNo
  "",                                  // aName
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1447,                                // lineNo
  39,                                  // colNo
  "",                                  // aName
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo td_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1448,                                // lineNo
  40,                                  // colNo
  "",                                  // aName
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ud_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1448,                                // lineNo
  82,                                  // colNo
  "",                                  // aName
  "trackerJPDA/createClusters",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1507,                                // lineNo
  61,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1507,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xd_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  705,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "TrackManager/trackIDs",             // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo yd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1508,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ae_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1510,                                // lineNo
  42,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo be_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1509,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ce_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1510,                                // lineNo
  31,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo de_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1511,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ee_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1512,                                // lineNo
  66,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1512,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/clusterDetections",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtECInfo t_emlrtECI = { 2,   // nDims
  2513,                                // lineNo
  21,                                  // colNo
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtECInfo u_emlrtECI = { 2,   // nDims
  2526,                                // lineNo
  41,                                  // colNo
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo lc_emlrtRTEI = { 13,// lineNo
  13,                                  // colNo
  "toLogicalCheck",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/toLogicalCheck.m"// pName 
};

static emlrtBCInfo mf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2508,                                // lineNo
  20,                                  // colNo
  "",                                  // aName
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2511,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo of_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2516,                                // lineNo
  38,                                  // colNo
  "",                                  // aName
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2520,                                // lineNo
  32,                                  // colNo
  "",                                  // aName
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2520,                                // lineNo
  53,                                  // colNo
  "",                                  // aName
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2521,                                // lineNo
  33,                                  // colNo
  "",                                  // aName
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2523,                                // lineNo
  40,                                  // colNo
  "",                                  // aName
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2523,                                // lineNo
  58,                                  // colNo
  "",                                  // aName
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2524,                                // lineNo
  41,                                  // colNo
  "",                                  // aName
  "trackerJPDA/connectedTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo nc_emlrtRTEI = { 2010,// lineNo
  13,                                  // colNo
  "trackerJPDA/validateClusterDetectionsTime",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo vf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2009,                                // lineNo
  47,                                  // colNo
  "",                                  // aName
  "trackerJPDA/validateClusterDetectionsTime",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2009,                                // lineNo
  58,                                  // colNo
  "",                                  // aName
  "trackerJPDA/validateClusterDetectionsTime",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2007,                                // lineNo
  47,                                  // colNo
  "",                                  // aName
  "trackerJPDA/validateClusterDetectionsTime",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  2008,                                // lineNo
  47,                                  // colNo
  "",                                  // aName
  "trackerJPDA/validateClusterDetectionsTime",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ag_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1934,                                // lineNo
  57,                                  // colNo
  "",                                  // aName
  "trackerJPDA/findTracksByIDs",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtECInfo v_emlrtECI = { -1,  // nDims
  1934,                                // lineNo
  17,                                  // colNo
  "trackerJPDA/findTracksByIDs",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo bg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1934,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/findTracksByIDs",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtECInfo w_emlrtECI = { -1,  // nDims
  1905,                                // lineNo
  46,                                  // colNo
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtECInfo x_emlrtECI = { -1,  // nDims
  1904,                                // lineNo
  41,                                  // colNo
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo sg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1899,                                // lineNo
  75,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1898,                                // lineNo
  50,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ug_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1898,                                // lineNo
  48,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1898,                                // lineNo
  43,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1892,                                // lineNo
  38,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1892,                                // lineNo
  36,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1891,                                // lineNo
  33,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ah_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1889,                                // lineNo
  29,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1897,                                // lineNo
  24,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ch_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1909,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1899,                                // lineNo
  49,                                  // colNo
  "",                                  // aName
  "trackerJPDA/calcEventProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo eh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1843,                                // lineNo
  27,                                  // colNo
  "",                                  // aName
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1843,                                // lineNo
  29,                                  // colNo
  "",                                  // aName
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1843,                                // lineNo
  33,                                  // colNo
  "",                                  // aName
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1844,                                // lineNo
  31,                                  // colNo
  "",                                  // aName
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo cb_emlrtDCI = { 1851,// lineNo
  26,                                  // colNo
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo db_emlrtDCI = { 1857,// lineNo
  34,                                  // colNo
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  4                                    // checkKind
};

static emlrtECInfo y_emlrtECI = { -1,  // nDims
  1859,                                // lineNo
  46,                                  // colNo
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo ih_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1861,                                // lineNo
  23,                                  // colNo
  "",                                  // aName
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ab_emlrtECI = { -1, // nDims
  1861,                                // lineNo
  13,                                  // colNo
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo jh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1850,                                // lineNo
  49,                                  // colNo
  "",                                  // aName
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1859,                                // lineNo
  60,                                  // colNo
  "",                                  // aName
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo eb_emlrtDCI = { 1839,// lineNo
  31,                                  // colNo
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo fb_emlrtDCI = { 1839,// lineNo
  13,                                  // colNo
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo lh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1850,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1859,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/associationProbabilities",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gi_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1797,                                // lineNo
  51,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hi_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1785,                                // lineNo
  53,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ii_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1763,                                // lineNo
  39,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ji_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1817,                                // lineNo
  54,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo jb_emlrtDCI = { 1817,// lineNo
  54,                                  // colNo
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ki_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1817,                                // lineNo
  39,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo kb_emlrtDCI = { 1817,// lineNo
  39,                                  // colNo
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtECInfo bb_emlrtECI = { -1, // nDims
  1790,                                // lineNo
  21,                                  // colNo
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtDCInfo lb_emlrtDCI = { 1785,// lineNo
  53,                                  // colNo
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo mb_emlrtDCI = { 1763,// lineNo
  39,                                  // colNo
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo li_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  512,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "TrackManager/initiateTrack",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  3                                    // checkKind
};

static emlrtDCInfo nb_emlrtDCI = { 512,// lineNo
  17,                                  // colNo
  "TrackManager/initiateTrack",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo mi_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  1784,                                // lineNo
  29,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ob_emlrtDCI = { 1784,// lineNo
  29,                                  // colNo
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ni_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1787,                                // lineNo
  68,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo pb_emlrtDCI = { 1787,// lineNo
  68,                                  // colNo
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo oi_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1789,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pi_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1790,                                // lineNo
  98,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qi_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1790,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ri_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1804,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  3                                    // checkKind
};

static emlrtDCInfo qb_emlrtDCI = { 1804,// lineNo
  21,                                  // colNo
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo si_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1795,                                // lineNo
  28,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ti_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1801,                                // lineNo
  52,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ui_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1801,                                // lineNo
  29,                                  // colNo
  "",                                  // aName
  "trackerJPDA/initializeTracks",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo cd_emlrtRTEI = { 1963,// lineNo
  19,                                  // colNo
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtBCInfo vi_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  600,                                 // lineNo
  37,                                  // colNo
  "",                                  // aName
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  3                                    // checkKind
};

static emlrtECInfo cb_emlrtECI = { -1, // nDims
  603,                                 // lineNo
  21,                                  // colNo
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtBCInfo wi_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  603,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo db_emlrtECI = { -1, // nDims
  602,                                 // lineNo
  21,                                  // colNo
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtBCInfo xi_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  602,                                 // lineNo
  82,                                  // colNo
  "",                                  // aName
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo rb_emlrtDCI = { 600,// lineNo
  37,                                  // colNo
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  1                                    // checkKind
};

static emlrtRTEInfo dd_emlrtRTEI = { 597,// lineNo
  29,                                  // colNo
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtRTEInfo ed_emlrtRTEI = { 594,// lineNo
  25,                                  // colNo
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtBCInfo yi_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1964,                                // lineNo
  20,                                  // colNo
  "",                                  // aName
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo sb_emlrtDCI = { 1964,// lineNo
  20,                                  // colNo
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo aj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1964,                                // lineNo
  20,                                  // colNo
  "",                                  // aName
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bj_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  1965,                                // lineNo
  61,                                  // colNo
  "",                                  // aName
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo tb_emlrtDCI = { 1965,// lineNo
  61,                                  // colNo
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo cj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1965,                                // lineNo
  61,                                  // colNo
  "",                                  // aName
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dj_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  1965,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  3                                    // checkKind
};

static emlrtDCInfo ub_emlrtDCI = { 1965,// lineNo
  21,                                  // colNo
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ej_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1965,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "trackerJPDA/deleteOldTracks",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  580,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo gj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  595,                                 // lineNo
  34,                                  // colNo
  "",                                  // aName
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hj_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  598,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo vb_emlrtDCI = { 598,// lineNo
  48,                                  // colNo
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo ij_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  598,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  3                                    // checkKind
};

static emlrtDCInfo wb_emlrtDCI = { 598,// lineNo
  25,                                  // colNo
  "TrackManager/recycleTracks",        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo xb_emlrtDCI = { 750,// lineNo
  59,                                  // colNo
  "TrackManager/formatTrackOutputs",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo jj_emlrtBCI = { 1,  // iFirst
  30,                                  // iLast
  750,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "TrackManager/formatTrackOutputs",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  772,                                 // lineNo
  45,                                  // colNo
  "",                                  // aName
  "TrackManager/getTracks",            // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo lj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  840,                                 // lineNo
  75,                                  // colNo
  "",                                  // aName
  "TrackManager/getTracksCodegen",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo yb_emlrtDCI = { 748,// lineNo
  41,                                  // colNo
  "TrackManager/formatTrackOutputs",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo ac_emlrtDCI = { 748,// lineNo
  41,                                  // colNo
  "TrackManager/formatTrackOutputs",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  4                                    // checkKind
};

static emlrtBCInfo mj_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  840,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "TrackManager/getTracksCodegen",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo bc_emlrtDCI = { 840,// lineNo
  40,                                  // colNo
  "TrackManager/getTracksCodegen",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo nj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  842,                                 // lineNo
  21,                                  // colNo
  "",                                  // aName
  "TrackManager/getTracksCodegen",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo oj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  749,                                 // lineNo
  35,                                  // colNo
  "",                                  // aName
  "TrackManager/formatTrackOutputs",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo pj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  750,                                 // lineNo
  35,                                  // colNo
  "",                                  // aName
  "TrackManager/formatTrackOutputs",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1546,                                // lineNo
  50,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1549,                                // lineNo
  39,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1575,                                // lineNo
  54,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1705,                                // lineNo
  45,                                  // colNo
  "",                                  // aName
  "trackerJPDA/likelihoodMatrix",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1706,                                // lineNo
  47,                                  // colNo
  "",                                  // aName
  "trackerJPDA/likelihoodMatrix",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vj_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  1709,                                // lineNo
  44,                                  // colNo
  "",                                  // aName
  "trackerJPDA/likelihoodMatrix",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1740,                                // lineNo
  54,                                  // colNo
  "",                                  // aName
  "trackerJPDA/updateClusterTracks",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1738,                                // lineNo
  22,                                  // colNo
  "",                                  // aName
  "trackerJPDA/updateClusterTracks",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo ld_emlrtRTEI = { 297,// lineNo
  1,                                   // colNo
  "delete_rows",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pName 
};

static emlrtBCInfo yj_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1749,                                // lineNo
  70,                                  // colNo
  "",                                  // aName
  "trackerJPDA/extractDetectionsForCluster",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ak_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1749,                                // lineNo
  51,                                  // colNo
  "",                                  // aName
  "trackerJPDA/extractDetectionsForCluster",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1572,                                // lineNo
  29,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ck_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1526,                                // lineNo
  41,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1526,                                // lineNo
  25,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ek_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1539,                                // lineNo
  38,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1539,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1548,                                // lineNo
  54,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1703,                                // lineNo
  24,                                  // colNo
  "",                                  // aName
  "trackerJPDA/likelihoodMatrix",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ik_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1707,                                // lineNo
  34,                                  // colNo
  "",                                  // aName
  "trackerJPDA/likelihoodMatrix",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1708,                                // lineNo
  51,                                  // colNo
  "",                                  // aName
  "trackerJPDA/likelihoodMatrix",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1712,                                // lineNo
  29,                                  // colNo
  "",                                  // aName
  "trackerJPDA/likelihoodMatrix",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1944,                                // lineNo
  51,                                  // colNo
  "",                                  // aName
  "trackerJPDA/identLowProbDet",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1569,                                // lineNo
  39,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1572,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/jpdaClusterUpdate",     // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ok_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1751,                                // lineNo
  34,                                  // colNo
  "",                                  // aName
  "trackerJPDA/extractDetectionsForCluster",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1751,                                // lineNo
  17,                                  // colNo
  "",                                  // aName
  "trackerJPDA/extractDetectionsForCluster",// fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1735,                                // lineNo
  25,                                  // colNo
  "",                                  // aName
  "trackerJPDA/updateClusterTracks",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1737,                                // lineNo
  50,                                  // colNo
  "",                                  // aName
  "trackerJPDA/updateClusterTracks",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1743,                                // lineNo
  65,                                  // colNo
  "",                                  // aName
  "trackerJPDA/updateClusterTracks",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo xh_emlrtRTEI = { 1594,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo yh_emlrtRTEI = { 1602,// lineNo
  21,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ai_emlrtRTEI = { 1608,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo bi_emlrtRTEI = { 1609,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ci_emlrtRTEI = { 1612,// lineNo
  26,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo di_emlrtRTEI = { 1613,// lineNo
  25,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ei_emlrtRTEI = { 1616,// lineNo
  46,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo fi_emlrtRTEI = { 1617,// lineNo
  49,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo gi_emlrtRTEI = { 1620,// lineNo
  36,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo hi_emlrtRTEI = { 1596,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ii_emlrtRTEI = { 1597,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ji_emlrtRTEI = { 1599,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ki_emlrtRTEI = { 1310,// lineNo
  28,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo li_emlrtRTEI = { 1364,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo mi_emlrtRTEI = { 1365,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ni_emlrtRTEI = { 1366,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo oi_emlrtRTEI = { 1153,// lineNo
  46,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo pi_emlrtRTEI = { 1160,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo qi_emlrtRTEI = { 1161,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ri_emlrtRTEI = { 1162,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ui_emlrtRTEI = { 1429,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo vi_emlrtRTEI = { 1430,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo wi_emlrtRTEI = { 1431,// lineNo
  32,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo xi_emlrtRTEI = { 1433,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo yi_emlrtRTEI = { 1928,// lineNo
  29,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo aj_emlrtRTEI = { 1437,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo bj_emlrtRTEI = { 1384,// lineNo
  21,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo cj_emlrtRTEI = { 1456,// lineNo
  29,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo dj_emlrtRTEI = { 1456,// lineNo
  31,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ej_emlrtRTEI = { 1461,// lineNo
  43,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo fj_emlrtRTEI = { 1440,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo gj_emlrtRTEI = { 1485,// lineNo
  39,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo hj_emlrtRTEI = { 1486,// lineNo
  41,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ij_emlrtRTEI = { 1486,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo jj_emlrtRTEI = { 1484,// lineNo
  21,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo kj_emlrtRTEI = { 1494,// lineNo
  36,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo lj_emlrtRTEI = { 1493,// lineNo
  27,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo mj_emlrtRTEI = { 53,// lineNo
  13,                                  // colNo
  "repmat",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pName
};

static emlrtRTEInfo nj_emlrtRTEI = { 1504,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo oj_emlrtRTEI = { 1506,// lineNo
  35,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo pj_emlrtRTEI = { 1506,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo qj_emlrtRTEI = { 1507,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo rj_emlrtRTEI = { 1508,// lineNo
  58,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo sj_emlrtRTEI = { 40,// lineNo
  5,                                   // colNo
  "find",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

static emlrtRTEInfo tj_emlrtRTEI = { 705,// lineNo
  30,                                  // colNo
  "TrackManager",                      // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtRTEInfo uj_emlrtRTEI = { 1508,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo vj_emlrtRTEI = { 1510,// lineNo
  52,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo wj_emlrtRTEI = { 1510,// lineNo
  42,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo xj_emlrtRTEI = { 1509,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo yj_emlrtRTEI = { 1512,// lineNo
  46,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ak_emlrtRTEI = { 1447,// lineNo
  39,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo bk_emlrtRTEI = { 1448,// lineNo
  40,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ck_emlrtRTEI = { 1448,// lineNo
  59,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo dk_emlrtRTEI = { 1389,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ek_emlrtRTEI = { 1416,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo fk_emlrtRTEI = { 1417,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo gk_emlrtRTEI = { 1419,// lineNo
  59,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo hk_emlrtRTEI = { 1419,// lineNo
  22,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ik_emlrtRTEI = { 1418,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo jl_emlrtRTEI = { 2502,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo kl_emlrtRTEI = { 2503,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ml_emlrtRTEI = { 2007,// lineNo
  27,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo nl_emlrtRTEI = { 2008,// lineNo
  27,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ol_emlrtRTEI = { 1932,// lineNo
  23,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo am_emlrtRTEI = { 1876,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo bm_emlrtRTEI = { 1886,// lineNo
  32,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo cm_emlrtRTEI = { 1889,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo dm_emlrtRTEI = { 1890,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo em_emlrtRTEI = { 1892,// lineNo
  28,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo fm_emlrtRTEI = { 1892,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo gm_emlrtRTEI = { 1898,// lineNo
  41,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo hm_emlrtRTEI = { 1904,// lineNo
  41,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo im_emlrtRTEI = { 1904,// lineNo
  40,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo jm_emlrtRTEI = { 1905,// lineNo
  46,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo km_emlrtRTEI = { 1905,// lineNo
  44,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo lm_emlrtRTEI = { 1905,// lineNo
  61,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo mm_emlrtRTEI = { 1911,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo om_emlrtRTEI = { 1839,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo pm_emlrtRTEI = { 1840,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo qm_emlrtRTEI = { 1847,// lineNo
  29,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo rm_emlrtRTEI = { 1847,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo sm_emlrtRTEI = { 1848,// lineNo
  35,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo tm_emlrtRTEI = { 1820,// lineNo
  30,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo um_emlrtRTEI = { 1850,// lineNo
  39,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo vm_emlrtRTEI = { 1859,// lineNo
  74,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo wm_emlrtRTEI = { 1859,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo cn_emlrtRTEI = { 1763,// lineNo
  23,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo dn_emlrtRTEI = { 1783,// lineNo
  21,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo en_emlrtRTEI = { 1785,// lineNo
  37,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo fn_emlrtRTEI = { 1787,// lineNo
  21,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo gn_emlrtRTEI = { 1790,// lineNo
  98,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo hn_emlrtRTEI = { 1755,// lineNo
  30,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo in_emlrtRTEI = { 1790,// lineNo
  80,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo jn_emlrtRTEI = { 1790,// lineNo
  63,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo kn_emlrtRTEI = { 1792,// lineNo
  21,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ln_emlrtRTEI = { 1797,// lineNo
  35,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo mn_emlrtRTEI = { 1808,// lineNo
  25,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo nn_emlrtRTEI = { 1808,// lineNo
  43,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo on_emlrtRTEI = { 1961,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo qn_emlrtRTEI = { 748,// lineNo
  41,                                  // colNo
  "TrackManager",                      // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtRTEInfo rn_emlrtRTEI = { 771,// lineNo
  13,                                  // colNo
  "TrackManager",                      // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtRTEInfo sn_emlrtRTEI = { 748,// lineNo
  26,                                  // colNo
  "TrackManager",                      // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtRTEInfo tn_emlrtRTEI = { 748,// lineNo
  17,                                  // colNo
  "TrackManager",                      // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/TrackManager.m"// pName 
};

static emlrtRTEInfo un_emlrtRTEI = { 1497,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo fo_emlrtRTEI = { 1531,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo go_emlrtRTEI = { 1537,// lineNo
  38,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ho_emlrtRTEI = { 1552,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo io_emlrtRTEI = { 1705,// lineNo
  29,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo jo_emlrtRTEI = { 1708,// lineNo
  51,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ko_emlrtRTEI = { 1567,// lineNo
  55,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo lo_emlrtRTEI = { 298,// lineNo
  5,                                   // colNo
  "nullAssignment",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"// pName 
};

static emlrtRTEInfo mo_emlrtRTEI = { 1942,// lineNo
  13,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo no_emlrtRTEI = { 1943,// lineNo
  25,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo oo_emlrtRTEI = { 1567,// lineNo
  35,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo po_emlrtRTEI = { 1569,// lineNo
  39,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo qo_emlrtRTEI = { 1572,// lineNo
  17,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo ro_emlrtRTEI = { 1749,// lineNo
  35,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo so_emlrtRTEI = { 92,// lineNo
  25,                                  // colNo
  "repmat",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pName
};

static emlrtRTEInfo to_emlrtRTEI = { 1751,// lineNo
  34,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo uo_emlrtRTEI = { 1737,// lineNo
  30,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

static emlrtRTEInfo vo_emlrtRTEI = { 1740,// lineNo
  42,                                  // colNo
  "trackerJPDA",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/trackerJPDA.m"// pName
};

// Function Declarations
static void cast(const emlrtStack *sp, const coder::array<b_struct_T, 2U> &b,
                 coder::array<struct_T, 2U> &c);

// Function Definitions
namespace coder
{
  void trackerJPDA::associationProbabilities(const emlrtStack *sp, const ::coder::
    array<boolean_T, 3U> &FJE, const ::coder::array<real_T, 2U> &FJEprobs, const
    ::coder::array<real_T, 2U> &clusterDetectionId, const ::coder::array<
    uint32_T, 2U> &clusterTrackId, ::coder::array<real_T, 2U> &posterior)
  {
    array<real_T, 2U> b_posterior_end;
    array<real_T, 1U> b_posterior;
    array<real_T, 1U> posterior_end;
    array<int32_T, 2U> r1;
    array<int32_T, 2U> r2;
    array<int32_T, 1U> r;
    array<boolean_T, 2U> assigned;
    array<boolean_T, 2U> unassignedT;
    array<boolean_T, 2U> varargin_1;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    int32_T b_input_sizes[2];
    int32_T input_sizes[2];
    int32_T b_loop_ub;
    int32_T c_loop_ub;
    int32_T d_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T i3;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
    int32_T nz;
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
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    if (static_cast<real_T>(clusterDetectionId.size(1)) + 1.0 !=
        clusterDetectionId.size(1) + 1) {
      emlrtIntegerCheckR2012b(static_cast<real_T>(clusterDetectionId.size(1)) +
        1.0, &eb_emlrtDCI, sp);
    }

    posterior.set_size(&om_emlrtRTEI, sp, clusterDetectionId.size(1) + 1,
                       clusterTrackId.size(1));
    if (static_cast<real_T>(clusterDetectionId.size(1)) + 1.0 !=
        clusterDetectionId.size(1) + 1) {
      emlrtIntegerCheckR2012b(static_cast<real_T>(clusterDetectionId.size(1)) +
        1.0, &fb_emlrtDCI, sp);
    }

    loop_ub = (clusterDetectionId.size(1) + 1) * clusterTrackId.size(1);
    for (i = 0; i < loop_ub; i++) {
      posterior[i] = 0.0;
    }

    posterior_end.set_size(&pm_emlrtRTEI, sp, clusterTrackId.size(1));
    loop_ub = clusterTrackId.size(1);
    for (i = 0; i < loop_ub; i++) {
      posterior_end[i] = 0.0;
    }

    i = FJE.size(2);
    if (0 <= FJE.size(2) - 1) {
      if (2U > clusterTrackId.size(1) + 1U) {
        i1 = -1;
        i3 = -1;
      } else {
        if (2 > FJE.size(1)) {
          emlrtDynamicBoundsCheckR2012b(2, 1, FJE.size(1), &eh_emlrtBCI, sp);
        }

        i1 = 0;
        if ((static_cast<int32_T>(clusterTrackId.size(1) + 1U) < 1) || (
             static_cast<int32_T>(clusterTrackId.size(1) + 1U) > FJE.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(clusterTrackId.size
            (1) + 1U), 1, FJE.size(1), &fh_emlrtBCI, sp);
        }

        i3 = clusterTrackId.size(1);
      }

      b_loop_ub = FJE.size(0);
      loop_ub_tmp = i3 - i1;
      c_loop_ub = FJE.size(0);
    }

    if (0 <= i - 1) {
      i2 = i3 - i1;
    }

    for (int32_T e = 0; e < i; e++) {
      real_T b_FJEprobs;
      int32_T i4;
      int32_T i5;
      int8_T sizes_idx_0;
      boolean_T empty_non_axis_sizes;
      i4 = e + 1;
      if ((i4 < 1) || (i4 > FJE.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, FJE.size(2), &gh_emlrtBCI, sp);
      }

      if (i4 > FJEprobs.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, FJEprobs.size(1), &hh_emlrtBCI, sp);
      }

      st.site = &ghb_emlrtRSI;
      varargin_1.set_size(&qm_emlrtRTEI, &st, b_loop_ub, i2);
      for (i4 = 0; i4 < loop_ub_tmp; i4++) {
        for (i5 = 0; i5 < b_loop_ub; i5++) {
          varargin_1[i5 + varargin_1.size(0) * i4] = FJE[(i5 + FJE.size(0) *
            ((i1 + i4) + 1)) + FJE.size(0) * FJE.size(1) * e];
        }
      }

      b_st.site = &aeb_emlrtRSI;
      if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
        nz = varargin_1.size(1);
      } else if (i2 != 0) {
        nz = i2;
      } else {
        i4 = varargin_1.size(1);
        nz = muIntScalarMax_sint32(i4, 0);
      }

      c_st.site = &beb_emlrtRSI;
      if ((varargin_1.size(1) != nz) && ((varargin_1.size(0) != 0) &&
           (varargin_1.size(1) != 0))) {
        emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      if ((i3 - i1 != nz) && (i2 != 0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      empty_non_axis_sizes = (nz == 0);
      if (empty_non_axis_sizes || ((varargin_1.size(0) != 0) && (varargin_1.size
            (1) != 0))) {
        loop_ub = varargin_1.size(0);
      } else {
        loop_ub = 0;
      }

      if (empty_non_axis_sizes || (i2 != 0)) {
        sizes_idx_0 = 1;
      } else {
        sizes_idx_0 = 0;
      }

      assigned.set_size(&rm_emlrtRTEI, &b_st, loop_ub + sizes_idx_0, nz);
      for (i4 = 0; i4 < nz; i4++) {
        for (i5 = 0; i5 < loop_ub; i5++) {
          assigned[i5 + assigned.size(0) * i4] = varargin_1[i5 + loop_ub * i4];
        }
      }

      for (i4 = 0; i4 < nz; i4++) {
        d_loop_ub = sizes_idx_0;
        for (i5 = 0; i5 < d_loop_ub; i5++) {
          assigned[loop_ub + assigned.size(0) * i4] = false;
        }
      }

      varargin_1.set_size(&sm_emlrtRTEI, sp, c_loop_ub, i2);
      for (i4 = 0; i4 < loop_ub_tmp; i4++) {
        for (i5 = 0; i5 < c_loop_ub; i5++) {
          varargin_1[i5 + varargin_1.size(0) * i4] = !FJE[(i5 + FJE.size(0) *
            ((i1 + i4) + 1)) + FJE.size(0) * FJE.size(1) * e];
        }
      }

      st.site = &hhb_emlrtRSI;
      c_all(&st, varargin_1, unassignedT);
      b_input_sizes[0] = (*(int32_T (*)[2])posterior.size())[0];
      b_input_sizes[1] = (*(int32_T (*)[2])posterior.size())[1];
      input_sizes[0] = (*(int32_T (*)[2])assigned.size())[0];
      input_sizes[1] = (*(int32_T (*)[2])assigned.size())[1];
      st.site = &ihb_emlrtRSI;
      internal::indexShapeCheck(&st, b_input_sizes, input_sizes);
      d_loop_ub = assigned.size(0) * assigned.size(1);
      for (loop_ub = 0; loop_ub < d_loop_ub; loop_ub++) {
        if (assigned[loop_ub]) {
          i4 = posterior.size(0) * posterior.size(1);
          if ((loop_ub + 1 < 1) || (loop_ub + 1 > i4)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i4, &jh_emlrtBCI, sp);
          }
        }
      }

      d_loop_ub = assigned.size(0) * assigned.size(1) - 1;
      nz = 0;
      for (loop_ub = 0; loop_ub <= d_loop_ub; loop_ub++) {
        if (assigned[loop_ub]) {
          nz++;
        }
      }

      r.set_size(&tm_emlrtRTEI, sp, nz);
      nz = 0;
      for (loop_ub = 0; loop_ub <= d_loop_ub; loop_ub++) {
        if (assigned[loop_ub]) {
          r[nz] = loop_ub + 1;
          nz++;
        }
      }

      b_FJEprobs = FJEprobs[e];
      nz = posterior.size(0) * posterior.size(1);
      loop_ub = r.size(0);
      b_posterior.set_size(&um_emlrtRTEI, sp, r.size(0));
      for (i4 = 0; i4 < loop_ub; i4++) {
        b_posterior[i4] = posterior[r[i4] - 1] + b_FJEprobs;
      }

      loop_ub = b_posterior.size(0);
      for (i4 = 0; i4 < loop_ub; i4++) {
        if ((r[i4] < 1) || (r[i4] > nz)) {
          emlrtDynamicBoundsCheckR2012b(r[i4], 1, nz, &lh_emlrtBCI, sp);
        }

        posterior[r[i4] - 1] = b_posterior[i4];
      }

      st.site = &jhb_emlrtRSI;
      b_st.site = &wi_emlrtRSI;
      c_st.site = &xi_emlrtRSI;
      nz = c_combineVectorElements(&c_st, unassignedT);
      if (nz < 0) {
        emlrtNonNegativeCheckR2012b(static_cast<real_T>(nz), &cb_emlrtDCI, sp);
      }

      st.site = &khb_emlrtRSI;
      b_st.site = &wi_emlrtRSI;
      c_st.site = &xi_emlrtRSI;
      nz = c_combineVectorElements(&c_st, unassignedT);
      if (nz < 0) {
        emlrtNonNegativeCheckR2012b(static_cast<real_T>(nz), &db_emlrtDCI, sp);
      }

      d_loop_ub = unassignedT.size(1);
      for (loop_ub = 0; loop_ub < d_loop_ub; loop_ub++) {
        if (unassignedT[loop_ub] && ((loop_ub + 1 < 1) || (loop_ub + 1 >
              posterior_end.size(0)))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, posterior_end.size(0),
            &kh_emlrtBCI, sp);
        }
      }

      b_FJEprobs = FJEprobs[e];
      b_posterior.set_size(&vm_emlrtRTEI, sp, nz);
      for (i4 = 0; i4 < nz; i4++) {
        b_posterior[i4] = b_FJEprobs;
      }

      d_loop_ub = unassignedT.size(1) - 1;
      nz = 0;
      for (loop_ub = 0; loop_ub <= d_loop_ub; loop_ub++) {
        if (unassignedT[loop_ub]) {
          nz++;
        }
      }

      r1.set_size(&tm_emlrtRTEI, sp, 1, nz);
      nz = 0;
      for (loop_ub = 0; loop_ub <= d_loop_ub; loop_ub++) {
        if (unassignedT[loop_ub]) {
          r1[nz] = loop_ub + 1;
          nz++;
        }
      }

      if (r1.size(1) != b_posterior.size(0)) {
        emlrtSizeEqCheck1DR2012b(r1.size(1), b_posterior.size(0), &y_emlrtECI,
          sp);
      }

      d_loop_ub = unassignedT.size(1) - 1;
      nz = 0;
      for (loop_ub = 0; loop_ub <= d_loop_ub; loop_ub++) {
        if (unassignedT[loop_ub]) {
          nz++;
        }
      }

      r2.set_size(&tm_emlrtRTEI, sp, 1, nz);
      nz = 0;
      for (loop_ub = 0; loop_ub <= d_loop_ub; loop_ub++) {
        if (unassignedT[loop_ub]) {
          r2[nz] = loop_ub + 1;
          nz++;
        }
      }

      nz = posterior_end.size(0);
      loop_ub = r2.size(1);
      b_posterior_end.set_size(&wm_emlrtRTEI, sp, 1, r2.size(1));
      for (i4 = 0; i4 < loop_ub; i4++) {
        b_posterior_end[i4] = posterior_end[r2[i4] - 1] + b_posterior[i4];
      }

      loop_ub = b_posterior_end.size(0) * b_posterior_end.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        if ((r2[i4] < 1) || (r2[i4] > nz)) {
          emlrtDynamicBoundsCheckR2012b(r2[i4], 1, nz, &mh_emlrtBCI, sp);
        }

        posterior_end[r2[i4] - 1] = b_posterior_end[i4];
      }
    }

    i = clusterDetectionId.size(1) + 1;
    if ((i < 1) || (i > posterior.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, posterior.size(0), &ih_emlrtBCI, sp);
    }

    input_sizes[0] = 1;
    input_sizes[1] = posterior.size(1);
    b_input_sizes[0] = 1;
    b_input_sizes[1] = posterior_end.size(0);
    emlrtSubAssignSizeCheckR2012b(&input_sizes[0], 2, &b_input_sizes[0], 2,
      &ab_emlrtECI, sp);
    loop_ub = posterior_end.size(0);
    for (i = 0; i < loop_ub; i++) {
      posterior[clusterDetectionId.size(1) + posterior.size(0) * i] =
        posterior_end[i];
    }

    st.site = &lhb_emlrtRSI;
    b_st.site = &ohb_emlrtRSI;
    c_st.site = &qk_emlrtRSI;
    b_st.site = &ohb_emlrtRSI;
    loop_ub = posterior.size(0) * posterior.size(1);
    for (i = 0; i < loop_ub; i++) {
      posterior[i] = posterior[i] * 1.0E+9;
    }

    c_st.site = &phb_emlrtRSI;
    nz = posterior.size(0) * posterior.size(1);
    d_st.site = &tk_emlrtRSI;
    if ((1 <= nz) && (nz > 2147483646)) {
      e_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (d_loop_ub = 0; d_loop_ub < nz; d_loop_ub++) {
      posterior[d_loop_ub] = muDoubleScalarRound(posterior[d_loop_ub]);
    }

    loop_ub = posterior.size(0) * posterior.size(1);
    for (i = 0; i < loop_ub; i++) {
      posterior[i] = posterior[i] / 1.0E+9;
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::calcEventProbabilities(const emlrtStack *sp, const ::coder::
    array<boolean_T, 3U> &FJE, const ::coder::array<real_T, 2U> &lhoodMatrix,
    const ::coder::array<real_T, 2U> &clusterDetectionId, const ::coder::array<
    uint32_T, 2U> &clusterTrackId, ::coder::array<real_T, 2U> &eventProb) const
  {
    array<real_T, 1U> Pd;
    array<real_T, 1U> b_deltap1;
    array<real_T, 1U> r;
    array<real_T, 1U> r1;
    array<int32_T, 2U> deltap1;
    array<int32_T, 2U> nz;
    array<int32_T, 1U> b_nz;
    array<boolean_T, 2U> X;
    array<boolean_T, 2U> b_X;
    array<boolean_T, 1U> tau;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack st;
    real_T lhood;
    int32_T b_loop_ub;
    int32_T b_vlen;
    int32_T c_loop_ub;
    int32_T d_loop_ub;
    int32_T e_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T i3;
    int32_T i5;
    int32_T i7;
    int32_T i8;
    int32_T i9;
    int32_T loop_ub;
    int32_T vlen;
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
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    Pd.set_size(&am_emlrtRTEI, sp, clusterTrackId.size(1));
    loop_ub = clusterTrackId.size(1);
    for (i = 0; i < loop_ub; i++) {
      Pd[i] = this->pTrackDetectionProbability[static_cast<int32_T>
        (clusterTrackId[i]) - 1];
    }

    eventProb.set_size(&bm_emlrtRTEI, sp, 1, FJE.size(2));
    i = FJE.size(2);
    if (0 <= FJE.size(2) - 1) {
      b_loop_ub = FJE.size(0);
      i1 = FJE.size(1);
      c_loop_ub = FJE.size(1);
      vlen = FJE.size(0);
      i2 = FJE.size(0);
      i3 = FJE.size(1);
      if (2 > FJE.size(1)) {
        i5 = -1;
        i7 = -1;
      } else {
        if (2 > FJE.size(1)) {
          emlrtDynamicBoundsCheckR2012b(2, 1, FJE.size(1), &xg_emlrtBCI, sp);
        }

        i5 = 0;
        if (FJE.size(1) < 1) {
          emlrtDynamicBoundsCheckR2012b(FJE.size(1), 1, FJE.size(1),
            &wg_emlrtBCI, sp);
        }

        i7 = FJE.size(1) - 1;
      }

      b_vlen = i7 - i5;
      i8 = FJE.size(0);
      i9 = clusterDetectionId.size(1);
      d_loop_ub = clusterTrackId.size(1);
      e_loop_ub = Pd.size(0);
    }

    for (int32_T event = 0; event < i; event++) {
      real_T product_detected;
      real_T product_undetected;
      int32_T i10;
      int32_T i11;
      int32_T i4;
      int32_T i6;
      int32_T k;
      int32_T xpageoffset;
      boolean_T guard1 = false;
      boolean_T overflow;
      if ((event + 1 < 1) || (event + 1 > FJE.size(2))) {
        emlrtDynamicBoundsCheckR2012b(event + 1, 1, FJE.size(2), &ah_emlrtBCI,
          sp);
      }

      X.set_size(&cm_emlrtRTEI, sp, b_loop_ub, i1);
      for (i4 = 0; i4 < c_loop_ub; i4++) {
        for (i6 = 0; i6 < b_loop_ub; i6++) {
          X[i6 + X.size(0) * i4] = FJE[(i6 + FJE.size(0) * i4) + FJE.size(0) *
            FJE.size(1) * event];
        }
      }

      st.site = &tgb_emlrtRSI;
      b_st.site = &wi_emlrtRSI;
      c_st.site = &xi_emlrtRSI;
      if ((i2 == 0) || (i3 == 0) || (FJE.size(0) == 0)) {
        nz.set_size(&lg_emlrtRTEI, &c_st, 1, FJE.size(1));
        loop_ub = FJE.size(1);
        for (i4 = 0; i4 < loop_ub; i4++) {
          nz[i4] = 0;
        }
      } else {
        d_st.site = &yi_emlrtRSI;
        i4 = FJE.size(1) - 1;
        nz.set_size(&kg_emlrtRTEI, &d_st, 1, FJE.size(1));
        e_st.site = &ogb_emlrtRSI;
        overflow = ((1 <= FJE.size(1)) && (FJE.size(1) > 2147483646));
        if (overflow) {
          f_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (loop_ub = 0; loop_ub <= i4; loop_ub++) {
          xpageoffset = loop_ub * FJE.size(0);
          nz[loop_ub] = X[xpageoffset];
          e_st.site = &lk_emlrtRSI;
          if ((2 <= vlen) && (vlen > 2147483646)) {
            f_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          for (k = 2; k <= vlen; k++) {
            nz[loop_ub] = nz[loop_ub] + X[(xpageoffset + k) - 1];
          }
        }
      }

      deltap1.set_size(&dm_emlrtRTEI, &st, 1, nz.size(1));
      loop_ub = nz.size(0) * nz.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        deltap1[i4] = nz[i4];
      }

      if (2 > deltap1.size(1)) {
        i4 = 0;
        i6 = 0;
      } else {
        i4 = 1;
        if (deltap1.size(1) < 1) {
          emlrtDynamicBoundsCheckR2012b(deltap1.size(1), 1, deltap1.size(1),
            &yg_emlrtBCI, sp);
        }

        i6 = deltap1.size(1);
      }

      st.site = &ugb_emlrtRSI;
      b_st.site = &wi_emlrtRSI;
      c_st.site = &xi_emlrtRSI;
      guard1 = false;
      if ((i8 == 0) || (i7 - i5 == 0)) {
        guard1 = true;
      } else {
        i10 = i7 - i5;
        if (i10 == 0) {
          guard1 = true;
        } else {
          d_st.site = &yi_emlrtRSI;
          i11 = FJE.size(0);
          b_nz.set_size(&kg_emlrtRTEI, &d_st, FJE.size(0));
          e_st.site = &aj_emlrtRSI;
          overflow = ((1 <= FJE.size(0)) && (FJE.size(0) > 2147483646));
          if (overflow) {
            f_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          for (loop_ub = 0; loop_ub < i11; loop_ub++) {
            b_nz[loop_ub] = X[loop_ub % FJE.size(0) + X.size(0) * ((i5 + loop_ub
              / FJE.size(0)) + 1)];
          }

          e_st.site = &lk_emlrtRSI;
          overflow = ((2 <= i10) && (i10 > 2147483646));
          if (overflow) {
            f_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          for (k = 2; k <= b_vlen; k++) {
            xpageoffset = (k - 1) * i11;
            e_st.site = &bj_emlrtRSI;
            if ((1 <= i11) && (i11 > 2147483646)) {
              f_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&f_st);
            }

            for (loop_ub = 0; loop_ub < i11; loop_ub++) {
              i10 = xpageoffset + loop_ub;
              b_nz[loop_ub] = b_nz[loop_ub] + FJE[(i10 % FJE.size(0) + FJE.size
                (0) * ((i5 + i10 / FJE.size(0)) + 1)) + FJE.size(0) * FJE.size(1)
                * event];
            }
          }
        }
      }

      if (guard1) {
        b_nz.set_size(&lg_emlrtRTEI, &c_st, FJE.size(0));
        loop_ub = FJE.size(0);
        for (i10 = 0; i10 < loop_ub; i10++) {
          b_nz[i10] = 0;
        }
      }

      r.set_size(&em_emlrtRTEI, &st, b_nz.size(0));
      loop_ub = b_nz.size(0);
      for (i10 = 0; i10 < loop_ub; i10++) {
        r[i10] = b_nz[i10];
      }

      st.site = &ugb_emlrtRSI;
      tau.set_size(&fm_emlrtRTEI, sp, r.size(0));
      loop_ub = r.size(0);
      for (i10 = 0; i10 < loop_ub; i10++) {
        tau[i10] = (r[i10] != 0.0);
      }

      lhood = 1.0;
      for (k = 0; k < i9; k++) {
        if ((k + 1 < 1) || (k + 1 > tau.size(0))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, tau.size(0), &bh_emlrtBCI, sp);
        }

        if (tau[k]) {
          if (2 > FJE.size(1)) {
            i10 = 0;
            i11 = 0;
          } else {
            if (2 > FJE.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, FJE.size(1), &ug_emlrtBCI, sp);
            }

            i10 = 1;
            if (FJE.size(1) < 1) {
              emlrtDynamicBoundsCheckR2012b(FJE.size(1), 1, FJE.size(1),
                &tg_emlrtBCI, sp);
            }

            i11 = FJE.size(1);
          }

          st.site = &vgb_emlrtRSI;
          xpageoffset = k + 1;
          if ((xpageoffset < 1) || (xpageoffset > FJE.size(0))) {
            emlrtDynamicBoundsCheckR2012b(xpageoffset, 1, FJE.size(0),
              &vg_emlrtBCI, &st);
          }

          loop_ub = i11 - i10;
          b_X.set_size(&gm_emlrtRTEI, &st, 1, loop_ub);
          for (i11 = 0; i11 < loop_ub; i11++) {
            b_X[i11] = X[k + X.size(0) * (i10 + i11)];
          }

          b_st.site = &jf_emlrtRSI;
          b_eml_find(&b_st, b_X, nz);
          if (1 > nz.size(1)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, nz.size(1), &sg_emlrtBCI, sp);
          }

          if ((k + 1 < 1) || (k + 1 > lhoodMatrix.size(0))) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, lhoodMatrix.size(0),
              &dh_emlrtBCI, sp);
          }

          if ((nz[0] < 1) || (nz[0] > lhoodMatrix.size(1))) {
            emlrtDynamicBoundsCheckR2012b(nz[0], 1, lhoodMatrix.size(1),
              &dh_emlrtBCI, sp);
          }

          lhood = lhood / 0.93033323307719429 / 1.0E-5 * lhoodMatrix[k +
            lhoodMatrix.size(0) * (nz[0] - 1)];
        }
      }

      r.set_size(&hm_emlrtRTEI, sp, clusterTrackId.size(1));
      for (i10 = 0; i10 < d_loop_ub; i10++) {
        r[i10] = 0.93033323307719429;
      }

      if (r.size(0) != Pd.size(0)) {
        emlrtSizeEqCheck1DR2012b(r.size(0), Pd.size(0), &x_emlrtECI, sp);
      }

      r1.set_size(&hm_emlrtRTEI, sp, r.size(0));
      loop_ub = r.size(0);
      for (i10 = 0; i10 < loop_ub; i10++) {
        r1[i10] = r[i10] * Pd[i10];
      }

      loop_ub = i6 - i4;
      b_deltap1.set_size(&im_emlrtRTEI, sp, loop_ub);
      for (i6 = 0; i6 < loop_ub; i6++) {
        b_deltap1[i6] = deltap1[i4 + i6];
      }

      st.site = &wgb_emlrtRSI;
      power(&st, r1, b_deltap1, r);
      st.site = &wgb_emlrtRSI;
      product_detected = prod(&st, r);
      r.set_size(&jm_emlrtRTEI, sp, Pd.size(0));
      for (i6 = 0; i6 < e_loop_ub; i6++) {
        r[i6] = Pd[i6] * 0.93033323307719429;
      }

      if (r.size(0) != clusterTrackId.size(1)) {
        emlrtSizeEqCheck1DR2012b(r.size(0), clusterTrackId.size(1), &w_emlrtECI,
          sp);
      }

      r1.set_size(&km_emlrtRTEI, sp, r.size(0));
      xpageoffset = r.size(0);
      for (i6 = 0; i6 < xpageoffset; i6++) {
        r1[i6] = 1.0 - r[i6];
      }

      b_deltap1.set_size(&lm_emlrtRTEI, sp, loop_ub);
      for (i6 = 0; i6 < loop_ub; i6++) {
        b_deltap1[i6] = 1.0 - static_cast<real_T>(deltap1[i4 + i6]);
      }

      st.site = &xgb_emlrtRSI;
      power(&st, r1, b_deltap1, r);
      st.site = &xgb_emlrtRSI;
      product_undetected = prod(&st, r);
      if ((event + 1 < 1) || (event + 1 > eventProb.size(1))) {
        emlrtDynamicBoundsCheckR2012b(event + 1, 1, eventProb.size(1),
          &ch_emlrtBCI, sp);
      }

      eventProb[event] = lhood * (product_detected * product_undetected);
    }

    st.site = &ygb_emlrtRSI;
    b_st.site = &fk_emlrtRSI;
    c_st.site = &xi_emlrtRSI;
    lhood = b_combineVectorElements(&c_st, eventProb);
    i = eventProb.size(0) * eventProb.size(1);
    eventProb.set_size(&mm_emlrtRTEI, sp, 1, eventProb.size(1));
    loop_ub = i - 1;
    for (i = 0; i <= loop_ub; i++) {
      eventProb[i] = eventProb[i] / (lhood + 2.2204460492503131E-16);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::checkTunableProps()
  {
    if (this->TunablePropsChanged) {
      this->TunablePropsChanged = false;
    }
  }

  void trackerJPDA::clusterAssignUpdate(const emlrtStack *sp, ::coder::array<
    real_T, 2U> &unassignedDets, ::coder::array<real_T, 2U>
    &trueUnassignedTrackId, ::coder::array<struct_T, 2U> &clusterInfo)
  {
    matlabshared::tracking::internal::fusion::ObjectTrack *c_obj[30];
    array<objectDetection, 2U> b_obj;
    array<b_struct_T, 2U> c_a;
    array<struct_T, 2U> clusters;
    array<struct_T, 2U> preClusters;
    array<real_T, 2U> a;
    array<real_T, 2U> b_costMatrix;
    array<real_T, 2U> b_sensorIDs;
    array<real_T, 2U> clustdetid;
    array<real_T, 2U> clusterNumero;
    array<real_T, 2U> costMatrix;
    array<real_T, 2U> detections2cluster;
    array<real_T, 2U> sensorDetectionsId;
    array<real_T, 2U> tracks2cluster;
    array<real_T, 2U> unassignedTrack;
    array<real_T, 2U> unassignedTrackCounter;
    array<real_T, 1U> b_unassignedTrackCounter;
    array<int32_T, 2U> ii;
    array<int32_T, 2U> r;
    array<int32_T, 2U> sensorDetIds;
    array<int32_T, 1U> b_ii;
    array<int32_T, 1U> r1;
    array<uint32_T, 2U> trackIDList;
    array<boolean_T, 2U> isUnassignedDetection;
    array<boolean_T, 2U> varargin_2;
    array<boolean_T, 2U> x;
    array<boolean_T, 1U> b_x;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    real_T sensorIDs;
    int32_T sizes[2];
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T b_sensorDetIds;
    int32_T c_costMatrix;
    int32_T c_loop_ub;
    int32_T d_costMatrix;
    int32_T d_loop_ub;
    int32_T d_obj;
    int32_T i;
    int32_T loop_ub;
    int32_T obj;
    int32_T result;
    uint32_T u;
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
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &vab_emlrtRSI;
    isUnassignedDetection.set_size(&ui_emlrtRTEI, &st, 1, this->pDetections.size
      (0) * this->pDetections.size(1));
    loop_ub = this->pDetections.size(0) * this->pDetections.size(1);
    for (i = 0; i < loop_ub; i++) {
      isUnassignedDetection[i] = false;
    }

    unassignedTrackCounter.set_size(&vi_emlrtRTEI, &st, 1,
      unassignedTrackCounter.size(1));
    if (!(this->pNumLiveTracks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(this->pNumLiveTracks, &r_emlrtDCI, &st);
    }

    sensorIDs = this->pNumLiveTracks;
    if (sensorIDs != static_cast<int32_T>(muDoubleScalarFloor(sensorIDs))) {
      emlrtIntegerCheckR2012b(sensorIDs, &q_emlrtDCI, &st);
    }

    unassignedTrackCounter.set_size(&vi_emlrtRTEI, &st,
      unassignedTrackCounter.size(0), static_cast<int32_T>(sensorIDs));
    if (!(this->pNumLiveTracks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(this->pNumLiveTracks, &t_emlrtDCI, &st);
    }

    sensorIDs = this->pNumLiveTracks;
    if (sensorIDs != static_cast<int32_T>(muDoubleScalarFloor(sensorIDs))) {
      emlrtIntegerCheckR2012b(sensorIDs, &s_emlrtDCI, &st);
    }

    loop_ub = static_cast<int32_T>(sensorIDs);
    for (i = 0; i < loop_ub; i++) {
      unassignedTrackCounter[i] = 0.0;
    }

    b_st.site = &yab_emlrtRSI;
    a.set_size(&wi_emlrtRTEI, &b_st, 1, this->pOriginatingSensor.size(1));
    loop_ub = this->pOriginatingSensor.size(0) * this->pOriginatingSensor.size(1);
    for (i = 0; i < loop_ub; i++) {
      a[i] = this->pOriginatingSensor[i];
    }

    c_st.site = &gn_emlrtRSI;
    unique_vector(&c_st, a, b_sensorIDs);
    preClusters.set_size(&xi_emlrtRTEI, &st, 1, 0);
    i = b_sensorIDs.size(1);
    for (int32_T s = 0; s < i; s++) {
      b_struct_T b_a;
      real_T nClusters;
      int32_T i1;
      int32_T i2;
      int32_T i4;
      int8_T i5;
      boolean_T empty_non_axis_sizes;
      b_st.site = &abb_emlrtRSI;
      i1 = s + 1;
      if ((i1 < 1) || (i1 > b_sensorIDs.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_sensorIDs.size(1), &hd_emlrtBCI,
          &b_st);
      }

      c_st.site = &dbb_emlrtRSI;
      x.set_size(&yi_emlrtRTEI, &c_st, 1, this->pOriginatingSensor.size(1));
      sensorIDs = b_sensorIDs[s];
      loop_ub = this->pOriginatingSensor.size(0) * this->pOriginatingSensor.size
        (1);
      for (i2 = 0; i2 < loop_ub; i2++) {
        x[i2] = (this->pOriginatingSensor[i2] == sensorIDs);
      }

      d_st.site = &jf_emlrtRSI;
      b_eml_find(&d_st, x, ii);
      sensorDetectionsId.set_size(&aj_emlrtRTEI, &c_st, 1, ii.size(1));
      loop_ub = ii.size(0) * ii.size(1);
      for (i2 = 0; i2 < loop_ub; i2++) {
        sensorDetectionsId[i2] = ii[i2];
      }

      b_st.site = &bbb_emlrtRSI;
      c_st.site = &ebb_emlrtRSI;
      b_obj.set_size(&bj_emlrtRTEI, &c_st, this->pDetections.size(0),
                     this->pDetections.size(1));
      loop_ub = this->pDetections.size(0) * this->pDetections.size(1) - 1;
      for (i2 = 0; i2 <= loop_ub; i2++) {
        b_obj[i2] = this->pDetections[i2];
      }

      for (int32_T i3 = 0; i3 < 30; i3++) {
        c_obj[i3] = this->pTracksList[i3];
      }

      d_st.site = &gbb_emlrtRSI;
      this->cCostCalculator.step(&d_st, c_obj, b_obj, this->pNumLiveTracks,
        sensorDetectionsId, costMatrix);
      loop_ub = this->pCostMatrix.size(0);
      r1.set_size(&cj_emlrtRTEI, &b_st, loop_ub);
      for (i2 = 0; i2 < loop_ub; i2++) {
        r1[i2] = i2;
      }

      obj = this->pCostMatrix.size(1);
      b_ii.set_size(&dj_emlrtRTEI, &b_st, sensorDetectionsId.size(1));
      loop_ub = sensorDetectionsId.size(1);
      for (i2 = 0; i2 < loop_ub; i2++) {
        i4 = static_cast<int32_T>(sensorDetectionsId[i2]);
        if ((i4 < 1) || (i4 > obj)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>
            (sensorDetectionsId[i2]), 1, obj, &qd_emlrtBCI, &b_st);
        }

        b_ii[i2] = i4 - 1;
      }

      sizes[0] = r1.size(0);
      sizes[1] = b_ii.size(0);
      emlrtSubAssignSizeCheckR2012b(&sizes[0], 2, costMatrix.size(), 2,
        &l_emlrtECI, &b_st);
      loop_ub = costMatrix.size(1);
      for (i2 = 0; i2 < loop_ub; i2++) {
        obj = costMatrix.size(0);
        for (i4 = 0; i4 < obj; i4++) {
          this->pCostMatrix[r1[i4] + this->pCostMatrix.size(0) * b_ii[i2]] =
            costMatrix[i4 + costMatrix.size(0) * i2];
        }
      }

      c_st.site = &fbb_emlrtRSI;
      varargin_2.set_size(&ej_emlrtRTEI, &c_st, costMatrix.size(1),
                          costMatrix.size(0));
      loop_ub = costMatrix.size(0);
      for (i2 = 0; i2 < loop_ub; i2++) {
        obj = costMatrix.size(1);
        for (i4 = 0; i4 < obj; i4++) {
          varargin_2[i4 + varargin_2.size(0) * i2] = (costMatrix[i2 +
            costMatrix.size(0) * i4] < 50.0);
        }
      }

      d_st.site = &aeb_emlrtRSI;
      if (sensorDetectionsId.size(1) != 0) {
        result = sensorDetectionsId.size(1);
      } else if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0)) {
        result = varargin_2.size(0);
      } else {
        i2 = sensorDetectionsId.size(1);
        result = muIntScalarMax_sint32(i2, 0);
        if (varargin_2.size(0) > result) {
          result = varargin_2.size(0);
        }
      }

      e_st.site = &beb_emlrtRSI;
      if ((sensorDetectionsId.size(1) != result) && (sensorDetectionsId.size(1)
           != 0)) {
        emlrtErrorWithMessageIdR2018a(&e_st, &emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      if ((varargin_2.size(0) != result) && ((varargin_2.size(0) != 0) &&
           (varargin_2.size(1) != 0))) {
        emlrtErrorWithMessageIdR2018a(&e_st, &emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes || (sensorDetectionsId.size(1) != 0)) {
        i5 = 1;
      } else {
        i5 = 0;
      }

      if (empty_non_axis_sizes || ((varargin_2.size(0) != 0) && (varargin_2.size
            (1) != 0))) {
        sizes[1] = varargin_2.size(1);
      } else {
        sizes[1] = 0;
      }

      costMatrix.set_size(&fj_emlrtRTEI, &d_st, result, i5 + sizes[1]);
      loop_ub = i5;
      for (i2 = 0; i2 < loop_ub; i2++) {
        for (i4 = 0; i4 < result; i4++) {
          costMatrix[i4] = 1.0;
        }
      }

      loop_ub = sizes[1];
      for (i2 = 0; i2 < loop_ub; i2++) {
        for (i4 = 0; i4 < result; i4++) {
          costMatrix[i4 + costMatrix.size(0) * (i2 + i5)] = varargin_2[i4 +
            result * i2];
        }
      }

      b_st.site = &cbb_emlrtRSI;
      if (i1 > b_sensorIDs.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_sensorIDs.size(1), &id_emlrtBCI,
          &b_st);
      }

      if (2 > costMatrix.size(1)) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = 1;
        if (costMatrix.size(1) < 1) {
          emlrtDynamicBoundsCheckR2012b(costMatrix.size(1), 1, costMatrix.size(1),
            &jd_emlrtBCI, &b_st);
        }

        i2 = costMatrix.size(1);
      }

      c_st.site = &ceb_emlrtRSI;
      c_st.site = &ceb_emlrtRSI;
      loop_ub = costMatrix.size(0);
      obj = i2 - i1;
      varargin_2.set_size(&gj_emlrtRTEI, &c_st, costMatrix.size(0), obj);
      for (i2 = 0; i2 < obj; i2++) {
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_2[i4 + varargin_2.size(0) * i2] = !(costMatrix[i4 +
            costMatrix.size(0) * (i1 + i2)] != 0.0);
        }
      }

      d_st.site = &ceb_emlrtRSI;
      b_all(&d_st, varargin_2, b_x);
      d_st.site = &jf_emlrtRSI;
      eml_find(&d_st, b_x, b_ii);
      c_st.site = &deb_emlrtRSI;
      c_st.site = &deb_emlrtRSI;
      loop_ub = costMatrix.size(0);
      varargin_2.set_size(&hj_emlrtRTEI, &c_st, costMatrix.size(0), obj);
      for (i2 = 0; i2 < obj; i2++) {
        for (i4 = 0; i4 < loop_ub; i4++) {
          varargin_2[i4 + varargin_2.size(0) * i2] = !(costMatrix[i4 +
            costMatrix.size(0) * (i1 + i2)] != 0.0);
        }
      }

      d_st.site = &deb_emlrtRSI;
      c_all(&d_st, varargin_2, x);
      d_st.site = &jf_emlrtRSI;
      b_eml_find(&d_st, x, ii);
      unassignedTrack.set_size(&ij_emlrtRTEI, &c_st, 1, ii.size(1));
      loop_ub = ii.size(0) * ii.size(1);
      for (i2 = 0; i2 < loop_ub; i2++) {
        unassignedTrack[i2] = ii[i2];
      }

      loop_ub = costMatrix.size(0);
      b_costMatrix.set_size(&jj_emlrtRTEI, &b_st, costMatrix.size(0), obj);
      for (i2 = 0; i2 < obj; i2++) {
        for (i4 = 0; i4 < loop_ub; i4++) {
          b_costMatrix[i4 + b_costMatrix.size(0) * i2] = costMatrix[i4 +
            costMatrix.size(0) * (i1 + i2)];
        }
      }

      c_st.site = &eeb_emlrtRSI;
      trackerJPDA::connectedTracks(&c_st, b_costMatrix, detections2cluster,
        tracks2cluster, &sensorIDs);
      nClusters = sensorIDs - static_cast<real_T>(unassignedTrack.size(1));
      a.set_size(&kj_emlrtRTEI, &b_st, 1, tracks2cluster.size(1));
      loop_ub = tracks2cluster.size(0) * tracks2cluster.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        a[i1] = tracks2cluster[i1];
      }

      ii.set_size(&lj_emlrtRTEI, &b_st, 1, unassignedTrack.size(1));
      loop_ub = unassignedTrack.size(0) * unassignedTrack.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        ii[i1] = static_cast<int32_T>(unassignedTrack[i1]);
      }

      c_st.site = &feb_emlrtRSI;
      internal::nullAssignment(&c_st, a, ii);
      c_st.site = &geb_emlrtRSI;
      d_st.site = &gn_emlrtRSI;
      unique_vector(&d_st, a, clusterNumero);
      c_st.site = &heb_emlrtRSI;
      b_a = this->pClusterTypeDef;
      d_st.site = &yk_emlrtRSI;
      if ((nClusters != nClusters) || muDoubleScalarIsInf(nClusters) ||
          (nClusters > 2.147483647E+9)) {
        emlrtErrorWithMessageIdR2018a(&d_st, &gc_emlrtRTEI,
          "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
          MIN_int32_T, 12, MAX_int32_T);
      }

      if (nClusters <= 0.0) {
        sensorIDs = 0.0;
      } else {
        sensorIDs = nClusters;
      }

      if (!(sensorIDs <= 2.147483647E+9)) {
        emlrtErrorWithMessageIdR2018a(&d_st, &db_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", "Coder:MATLAB:pmaxsize", 0);
      }

      if (!(nClusters >= 0.0)) {
        emlrtNonNegativeCheckR2012b(nClusters, &p_emlrtDCI, &c_st);
      }

      c_a.set_size(&mj_emlrtRTEI, &b_st, 1, static_cast<int32_T>(nClusters));
      loop_ub = static_cast<int32_T>(nClusters);
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_a[i1] = b_a;
      }

      c_st.site = &heb_emlrtRSI;
      cast(&c_st, c_a, clusters);
      c_st.site = &ieb_emlrtRSI;
      d_st.site = &dbb_emlrtRSI;
      x.set_size(&yi_emlrtRTEI, &d_st, 1, this->pOriginatingSensor.size(1));
      sensorIDs = b_sensorIDs[s];
      loop_ub = this->pOriginatingSensor.size(0) * this->pOriginatingSensor.size
        (1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        x[i1] = (this->pOriginatingSensor[i1] == sensorIDs);
      }

      e_st.site = &jf_emlrtRSI;
      b_eml_find(&e_st, x, ii);
      sensorDetIds.set_size(&nj_emlrtRTEI, &d_st, 1, ii.size(1));
      loop_ub = ii.size(0) * ii.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        sensorDetIds[i1] = ii[i1];
      }

      i1 = static_cast<int32_T>(nClusters);
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, nClusters, mxDOUBLE_CLASS,
        static_cast<int32_T>(nClusters), &ec_emlrtRTEI, &b_st);
      if (0 <= static_cast<int32_T>(nClusters) - 1) {
        b_loop_ub = detections2cluster.size(0) * detections2cluster.size(1);
        b_sensorDetIds = sensorDetIds.size(1);
        c_loop_ub = tracks2cluster.size(0) * tracks2cluster.size(1);
        d_loop_ub = tracks2cluster.size(0) * tracks2cluster.size(1);
        c_costMatrix = costMatrix.size(0);
        d_costMatrix = costMatrix.size(1);
        d_obj = this->pDetectionTimes.size(1);
      }

      if (0 <= i1 - 1) {
        sensorIDs = muDoubleScalarRound(b_sensorIDs[s]);
        if (sensorIDs < 4.294967296E+9) {
          if (sensorIDs >= 0.0) {
            u = static_cast<uint32_T>(sensorIDs);
          } else {
            u = 0U;
          }
        } else if (sensorIDs >= 4.294967296E+9) {
          u = MAX_uint32_T;
        } else {
          u = 0U;
        }
      }

      for (int32_T c = 0; c < i1; c++) {
        c_st.site = &jeb_emlrtRSI;
        i2 = c + 1;
        if ((i2 < 1) || (i2 > clusterNumero.size(1))) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, clusterNumero.size(1),
            &kd_emlrtBCI, &c_st);
        }

        sensorIDs = clusterNumero[c];
        x.set_size(&oj_emlrtRTEI, &c_st, 1, detections2cluster.size(1));
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          x[i4] = (detections2cluster[i4] == sensorIDs);
        }

        d_st.site = &jf_emlrtRSI;
        b_eml_find(&d_st, x, ii);
        clustdetid.set_size(&pj_emlrtRTEI, &c_st, 1, ii.size(1));
        loop_ub = ii.size(0) * ii.size(1);
        for (i4 = 0; i4 < loop_ub; i4++) {
          clustdetid[i4] = ii[i4];
        }

        loop_ub = clustdetid.size(0) * clustdetid.size(1) - 1;
        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             clusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
            clusters.size(1), &nd_emlrtBCI, &b_st);
        }

        clusters[clusters.size(0) * c].DetectionIndices.set_size(&qj_emlrtRTEI,
          &b_st, 1, clusters[clusters.size(0) * c].DetectionIndices.size(1));
        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             clusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
            clusters.size(1), &nd_emlrtBCI, &b_st);
        }

        clusters[clusters.size(0) * c].DetectionIndices.set_size(&qj_emlrtRTEI,
          &b_st, clusters[clusters.size(0) * c].DetectionIndices.size(0),
          clustdetid.size(1));
        result = clusters.size(1);
        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             clusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
            clusters.size(1), &nd_emlrtBCI, &b_st);
        }

        for (i4 = 0; i4 <= loop_ub; i4++) {
          b_i = static_cast<int32_T>(clustdetid[i4]);
          if ((b_i < 1) || (b_i > b_sensorDetIds)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(clustdetid[i4]),
              1, b_sensorDetIds, &vd_emlrtBCI, &b_st);
          }

          if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U)
               > result)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
              result, &wd_emlrtBCI, &b_st);
          }

          clusters[c].DetectionIndices[i4] = sensorDetIds[b_i - 1];
        }

        c_st.site = &keb_emlrtRSI;
        if (i2 > clusterNumero.size(1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, clusterNumero.size(1),
            &ld_emlrtBCI, &c_st);
        }

        sensorIDs = clusterNumero[c];
        x.set_size(&rj_emlrtRTEI, &c_st, 1, tracks2cluster.size(1));
        for (i4 = 0; i4 < c_loop_ub; i4++) {
          x[i4] = (tracks2cluster[i4] == sensorIDs);
        }

        d_st.site = &jf_emlrtRSI;
        b_eml_find(&d_st, x, ii);
        a.set_size(&sj_emlrtRTEI, &c_st, 1, ii.size(1));
        loop_ub = ii.size(0) * ii.size(1);
        for (i4 = 0; i4 < loop_ub; i4++) {
          a[i4] = ii[i4];
        }

        c_st.site = &keb_emlrtRSI;
        trackIDList.set_size(&tj_emlrtRTEI, &c_st, 1, a.size(1));
        loop_ub = a.size(0) * a.size(1);
        for (i4 = 0; i4 < loop_ub; i4++) {
          b_i = static_cast<int32_T>(a[i4]);
          if ((b_i < 1) || (b_i > 30)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a[i4]), 1, 30,
              &xd_emlrtBCI, &c_st);
          }

          trackIDList[i4] = this->pTrackIDs[b_i - 1];
        }

        if (a.size(1) != trackIDList.size(1)) {
          emlrtSubAssignSizeCheck1dR2017a(a.size(1), trackIDList.size(1),
            &m_emlrtECI, &c_st);
        }

        result = clusters.size(1);
        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             clusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
            clusters.size(1), &yd_emlrtBCI, &b_st);
        }

        clusters[clusters.size(0) * c].TrackIDs.set_size(&uj_emlrtRTEI, &b_st, 1,
          clusters[clusters.size(0) * c].TrackIDs.size(1));
        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             result)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1, result,
            &yd_emlrtBCI, &b_st);
        }

        clusters[clusters.size(0) * c].TrackIDs.set_size(&uj_emlrtRTEI, &b_st,
          clusters[clusters.size(0) * c].TrackIDs.size(0), a.size(1));
        loop_ub = a.size(1);
        for (i4 = 0; i4 < loop_ub; i4++) {
          if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U)
               > result)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
              result, &yd_emlrtBCI, &b_st);
          }

          clusters[c].TrackIDs[i4] = trackIDList[i4];
        }

        c_st.site = &leb_emlrtRSI;
        if (i2 > clusterNumero.size(1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, clusterNumero.size(1),
            &md_emlrtBCI, &c_st);
        }

        sensorIDs = clusterNumero[c];
        x.set_size(&vj_emlrtRTEI, &c_st, 1, tracks2cluster.size(1));
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          x[i2] = (tracks2cluster[i2] == sensorIDs);
        }

        d_st.site = &jf_emlrtRSI;
        b_eml_find(&d_st, x, ii);
        r1.set_size(&wj_emlrtRTEI, &b_st, ii.size(1) + 1);
        if (1 > d_costMatrix) {
          emlrtDynamicBoundsCheckR2012b(1, 1, d_costMatrix, &ae_emlrtBCI, &b_st);
        }

        r1[0] = 0;
        loop_ub = ii.size(1);
        for (i2 = 0; i2 < loop_ub; i2++) {
          i4 = ii[i2] + 1;
          if ((i4 < 1) || (i4 > d_costMatrix)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, d_costMatrix, &ae_emlrtBCI,
              &b_st);
          }

          r1[i2 + 1] = i4 - 1;
        }

        result = clusters.size(1);
        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             clusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
            clusters.size(1), &be_emlrtBCI, &b_st);
        }

        clusters[clusters.size(0) * c].ValidationMatrix.set_size(&xj_emlrtRTEI,
          &b_st, clustdetid.size(1), clusters[clusters.size(0) * c].
          ValidationMatrix.size(1));
        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             result)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1, result,
            &be_emlrtBCI, &b_st);
        }

        clusters[clusters.size(0) * c].ValidationMatrix.set_size(&xj_emlrtRTEI,
          &b_st, clusters[clusters.size(0) * c].ValidationMatrix.size(0),
          r1.size(0));
        loop_ub = r1.size(0);
        for (i2 = 0; i2 < loop_ub; i2++) {
          obj = clustdetid.size(1);
          for (i4 = 0; i4 < obj; i4++) {
            b_i = static_cast<int32_T>(clustdetid[i4]);
            if ((b_i < 1) || (b_i > c_costMatrix)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(clustdetid[i4]),
                1, c_costMatrix, &ce_emlrtBCI, &b_st);
            }

            if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c +
                  1U) > result)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
                result, &be_emlrtBCI, &b_st);
            }

            clusters[c].ValidationMatrix[i4 + clusters[c].ValidationMatrix.size
              (0) * i2] = costMatrix[(b_i + costMatrix.size(0) * r1[i2]) - 1];
          }
        }

        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             clusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
            clusters.size(1), &de_emlrtBCI, &b_st);
        }

        clusters[c].SensorIndex = u;
        c_st.site = &meb_emlrtRSI;
        clustdetid.set_size(&yj_emlrtRTEI, &c_st, 1, clustdetid.size(1));
        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             clusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
            clusters.size(1), &od_emlrtBCI, &c_st);
        }

        clustdetid.set_size(&yj_emlrtRTEI, &c_st, clustdetid.size(0),
                            clusters[clusters.size(0) * c].DetectionIndices.size
                            (1));
        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             clusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
            clusters.size(1), &od_emlrtBCI, &c_st);
        }

        loop_ub = clusters[c].DetectionIndices.size(0) * clusters[c].
          DetectionIndices.size(1);
        for (i2 = 0; i2 < loop_ub; i2++) {
          if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U)
               > clusters.size(1))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
              clusters.size(1), &ee_emlrtBCI, &c_st);
          }

          i4 = static_cast<int32_T>(clusters[c].DetectionIndices[i2]);
          if ((i4 < 1) || (i4 > d_obj)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, d_obj, &ee_emlrtBCI, &c_st);
          }

          clustdetid[i2] = this->pDetectionTimes[i4 - 1];
        }

        if ((static_cast<int32_T>(c + 1U) < 1) || (static_cast<int32_T>(c + 1U) >
             clusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c + 1U), 1,
            clusters.size(1), &fe_emlrtBCI, &c_st);
        }

        d_st.site = &un_emlrtRSI;
        clusters[c].TimeStamp = b_combineVectorElements(&d_st, clustdetid) /
          static_cast<real_T>(clustdetid.size(1));
      }

      r1.set_size(&ak_emlrtRTEI, &st, b_ii.size(0));
      loop_ub = b_ii.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        if ((b_ii[i1] < 1) || (b_ii[i1] > sensorDetectionsId.size(1))) {
          emlrtDynamicBoundsCheckR2012b(b_ii[i1], 1, sensorDetectionsId.size(1),
            &rd_emlrtBCI, &st);
        }

        i2 = static_cast<int32_T>(sensorDetectionsId[b_ii[i1] - 1]);
        if ((i2 < 1) || (i2 > isUnassignedDetection.size(1))) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, isUnassignedDetection.size(1),
            &sd_emlrtBCI, &st);
        }

        r1[i1] = i2;
      }

      loop_ub = r1.size(0) - 1;
      for (i1 = 0; i1 <= loop_ub; i1++) {
        isUnassignedDetection[r1[i1] - 1] = true;
      }

      ii.set_size(&bk_emlrtRTEI, &st, 1, unassignedTrack.size(1));
      loop_ub = unassignedTrack.size(0) * unassignedTrack.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        i2 = static_cast<int32_T>(unassignedTrack[i1]);
        if ((i2 < 1) || (i2 > unassignedTrackCounter.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(unassignedTrack[i1]),
            1, unassignedTrackCounter.size(1), &td_emlrtBCI, &st);
        }

        ii[i1] = i2;
      }

      loop_ub = unassignedTrack.size(0) * unassignedTrack.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        i2 = static_cast<int32_T>(unassignedTrack[i1]);
        if ((i2 < 1) || (i2 > unassignedTrackCounter.size(1))) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, unassignedTrackCounter.size(1),
            &ud_emlrtBCI, &st);
        }
      }

      if (ii.size(1) != unassignedTrack.size(1)) {
        emlrtSubAssignSizeCheck1dR2017a(ii.size(1), unassignedTrack.size(1),
          &k_emlrtECI, &st);
      }

      loop_ub = unassignedTrack.size(0) * unassignedTrack.size(1);
      b_unassignedTrackCounter.set_size(&ck_emlrtRTEI, &st, loop_ub);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_unassignedTrackCounter[i1] = unassignedTrackCounter
          [static_cast<int32_T>(unassignedTrack[i1]) - 1] + 1.0;
      }

      loop_ub = b_unassignedTrackCounter.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        unassignedTrackCounter[ii[i1] - 1] = b_unassignedTrackCounter[i1];
      }

      i1 = preClusters.size(1);
      loop_ub = clusters.size(1);
      preClusters.set_size(&dk_emlrtRTEI, &st, preClusters.size(0),
                           preClusters.size(1) + clusters.size(1));
      for (i2 = 0; i2 < loop_ub; i2++) {
        preClusters[i1 + i2] = clusters[i2];
      }
    }

    st.site = &wab_emlrtRSI;
    this->jpdaClusterUpdate(&st, preClusters, isUnassignedDetection, clusterInfo);
    if (isUnassignedDetection.size(1) < 1) {
      clustdetid.set_size(&ek_emlrtRTEI, sp, 1, 0);
    } else {
      clustdetid.set_size(&ek_emlrtRTEI, sp, 1, static_cast<int32_T>(
        static_cast<real_T>(isUnassignedDetection.size(1)) - 1.0) + 1);
      loop_ub = static_cast<int32_T>(static_cast<real_T>
        (isUnassignedDetection.size(1)) - 1.0);
      for (i = 0; i <= loop_ub; i++) {
        clustdetid[i] = static_cast<real_T>(i) + 1.0;
      }
    }

    result = isUnassignedDetection.size(1) - 1;
    obj = 0;
    for (b_i = 0; b_i <= result; b_i++) {
      if (isUnassignedDetection[b_i]) {
        obj++;
      }
    }

    r.set_size(&dk_emlrtRTEI, sp, 1, obj);
    obj = 0;
    for (b_i = 0; b_i <= result; b_i++) {
      if (isUnassignedDetection[b_i]) {
        r[obj] = b_i + 1;
        obj++;
      }
    }

    unassignedDets.set_size(&fk_emlrtRTEI, sp, 1, r.size(1));
    loop_ub = r.size(1);
    for (i = 0; i < loop_ub; i++) {
      if ((r[i] < 1) || (r[i] > clustdetid.size(1))) {
        emlrtDynamicBoundsCheckR2012b(r[i], 1, clustdetid.size(1), &pd_emlrtBCI,
          sp);
      }

      unassignedDets[i] = clustdetid[r[i] - 1];
    }

    st.site = &xab_emlrtRSI;
    a.set_size(&gk_emlrtRTEI, &st, 1, this->pOriginatingSensor.size(1));
    loop_ub = this->pOriginatingSensor.size(0) * this->pOriginatingSensor.size(1);
    for (i = 0; i < loop_ub; i++) {
      a[i] = this->pOriginatingSensor[i];
    }

    b_st.site = &gn_emlrtRSI;
    unique_vector(&b_st, a, clustdetid);
    sizes[1] = clustdetid.size(1);
    st.site = &xab_emlrtRSI;
    x.set_size(&hk_emlrtRTEI, &st, 1, unassignedTrackCounter.size(1));
    loop_ub = unassignedTrackCounter.size(0) * unassignedTrackCounter.size(1);
    for (i = 0; i < loop_ub; i++) {
      x[i] = (unassignedTrackCounter[i] == sizes[1]);
    }

    b_st.site = &jf_emlrtRSI;
    b_eml_find(&b_st, x, ii);
    trueUnassignedTrackId.set_size(&ik_emlrtRTEI, &st, 1, ii.size(1));
    loop_ub = ii.size(0) * ii.size(1);
    for (i = 0; i < loop_ub; i++) {
      trueUnassignedTrackId[i] = ii[i];
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::connectedTracks(const emlrtStack *sp, const ::coder::array<
    real_T, 2U> &A, ::coder::array<real_T, 2U> &clustDets, ::coder::array<real_T,
    2U> &clustTracks, real_T *numClusters)
  {
    emlrtStack st;
    int32_T colStack_size_idx_1;
    int32_T i;
    int32_T nxout;
    uint32_T colStack_data[31];
    uint32_T b_colStack_data[30];
    uint32_T c_colStack_data[30];
    st.prev = sp;
    st.tls = sp->tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    clustDets.set_size(&jl_emlrtRTEI, sp, 1, A.size(0));
    nxout = A.size(0);
    for (i = 0; i < nxout; i++) {
      clustDets[i] = 0.0;
    }

    clustTracks.set_size(&kl_emlrtRTEI, sp, 1, A.size(1));
    nxout = A.size(1);
    for (i = 0; i < nxout; i++) {
      clustTracks[i] = 0.0;
    }

    *numClusters = 0.0;
    colStack_size_idx_1 = 0;
    i = A.size(1);
    for (int32_T track = 0; track < i; track++) {
      if ((track + 1 < 1) || (track + 1 > clustTracks.size(1))) {
        emlrtDynamicBoundsCheckR2012b(track + 1, 1, clustTracks.size(1),
          &mf_emlrtBCI, sp);
      }

      if (clustTracks[track] == 0.0) {
        real_T colStackSize;
        int32_T b_colStack_size_idx_1;
        (*numClusters)++;
        if ((track + 1 < 1) || (track + 1 > clustTracks.size(1))) {
          emlrtDynamicBoundsCheckR2012b(track + 1, 1, clustTracks.size(1),
            &nf_emlrtBCI, sp);
        }

        clustTracks[track] = *numClusters;
        colStackSize = 1.0;
        b_colStack_size_idx_1 = colStack_size_idx_1 + 1;
        if (0 <= colStack_size_idx_1 - 1) {
          memcpy(&colStack_data[0], &b_colStack_data[0], colStack_size_idx_1 *
                 sizeof(uint32_T));
        }

        colStack_data[colStack_size_idx_1] = static_cast<uint32_T>(track + 1);
        if (30 < colStack_size_idx_1 + 1) {
          emlrtDimSizeGeqCheckR2012b(30, 31, &t_emlrtECI, sp);
        }

        colStack_size_idx_1++;
        if (0 <= b_colStack_size_idx_1 - 1) {
          memcpy(&b_colStack_data[0], &colStack_data[0], b_colStack_size_idx_1 *
                 sizeof(uint32_T));
        }

        while (colStackSize > 0.0) {
          int32_T currentCol;
          int32_T k;
          if (colStack_size_idx_1 < 1) {
            emlrtDynamicBoundsCheckR2012b(colStack_size_idx_1, 1,
              colStack_size_idx_1, &of_emlrtBCI, sp);
          }

          currentCol = static_cast<int32_T>(b_colStack_data[colStack_size_idx_1
            - 1]);
          colStackSize--;
          nxout = colStack_size_idx_1 - 1;
          for (k = colStack_size_idx_1; k <= nxout; k++) {
            b_colStack_data[k - 1] = b_colStack_data[k];
          }

          if (1 > colStack_size_idx_1 - 1) {
            nxout = -1;
          } else {
            nxout = colStack_size_idx_1 - 2;
          }

          b_colStack_size_idx_1 = nxout + 1;
          if (0 <= nxout) {
            memcpy(&c_colStack_data[0], &b_colStack_data[0], (nxout + 1) *
                   sizeof(uint32_T));
          }

          colStack_size_idx_1 = nxout + 1;
          if (0 <= b_colStack_size_idx_1 - 1) {
            memcpy(&b_colStack_data[0], &c_colStack_data[0],
                   b_colStack_size_idx_1 * sizeof(uint32_T));
          }

          nxout = A.size(0);
          for (int32_T row = 0; row < nxout; row++) {
            real_T x;
            if ((row + 1 < 1) || (row + 1 > A.size(0))) {
              emlrtDynamicBoundsCheckR2012b(row + 1, 1, A.size(0), &pf_emlrtBCI,
                sp);
            }

            if ((currentCol < 1) || (currentCol > A.size(1))) {
              emlrtDynamicBoundsCheckR2012b(currentCol, 1, A.size(1),
                &pf_emlrtBCI, sp);
            }

            x = A[row + A.size(0) * (currentCol - 1)];
            st.site = &reb_emlrtRSI;
            if (muDoubleScalarIsNaN(x)) {
              emlrtErrorWithMessageIdR2018a(&st, &lc_emlrtRTEI,
                "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
            }

            if (x != 0.0) {
              if ((row + 1 < 1) || (row + 1 > clustDets.size(1))) {
                emlrtDynamicBoundsCheckR2012b(row + 1, 1, clustDets.size(1),
                  &qf_emlrtBCI, sp);
              }

              if (clustDets[row] == 0.0) {
                if ((row + 1 < 1) || (row + 1 > clustDets.size(1))) {
                  emlrtDynamicBoundsCheckR2012b(row + 1, 1, clustDets.size(1),
                    &rf_emlrtBCI, sp);
                }

                clustDets[row] = *numClusters;
                k = A.size(1);
                for (int32_T nextCol = 0; nextCol < k; nextCol++) {
                  if ((row + 1 < 1) || (row + 1 > A.size(0))) {
                    emlrtDynamicBoundsCheckR2012b(row + 1, 1, A.size(0),
                      &sf_emlrtBCI, sp);
                  }

                  if ((nextCol + 1 < 1) || (nextCol + 1 > A.size(1))) {
                    emlrtDynamicBoundsCheckR2012b(nextCol + 1, 1, A.size(1),
                      &sf_emlrtBCI, sp);
                  }

                  x = A[row + A.size(0) * nextCol];
                  st.site = &seb_emlrtRSI;
                  if (muDoubleScalarIsNaN(x)) {
                    emlrtErrorWithMessageIdR2018a(&st, &lc_emlrtRTEI,
                      "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
                  }

                  if (x != 0.0) {
                    if ((nextCol + 1 < 1) || (nextCol + 1 > clustTracks.size(1)))
                    {
                      emlrtDynamicBoundsCheckR2012b(nextCol + 1, 1,
                        clustTracks.size(1), &tf_emlrtBCI, sp);
                    }

                    if (clustTracks[nextCol] == 0.0) {
                      if ((nextCol + 1 < 1) || (nextCol + 1 > clustTracks.size(1)))
                      {
                        emlrtDynamicBoundsCheckR2012b(nextCol + 1, 1,
                          clustTracks.size(1), &uf_emlrtBCI, sp);
                      }

                      clustTracks[nextCol] = *numClusters;
                      colStackSize++;
                      b_colStack_size_idx_1 = colStack_size_idx_1 + 1;
                      if (0 <= colStack_size_idx_1 - 1) {
                        memcpy(&colStack_data[0], &b_colStack_data[0],
                               colStack_size_idx_1 * sizeof(uint32_T));
                      }

                      colStack_data[colStack_size_idx_1] = static_cast<uint32_T>
                        (nextCol + 1);
                      if (30 < colStack_size_idx_1 + 1) {
                        emlrtDimSizeGeqCheckR2012b(30, 31, &u_emlrtECI, sp);
                      }

                      colStack_size_idx_1++;
                      if (0 <= b_colStack_size_idx_1 - 1) {
                        memcpy(&b_colStack_data[0], &colStack_data[0],
                               b_colStack_size_idx_1 * sizeof(uint32_T));
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::deleteOldTracks(const emlrtStack *sp, uint32_T
    delTrIDs_data[], int32_T delTrIDs_size[2])
  {
    matlabshared::tracking::internal::fusion::ObjectTrack *temp;
    array<real_T, 2U> unassigned;
    emlrtStack b_st;
    emlrtStack st;
    real_T NumberOfTracks;
    real_T b;
    real_T d;
    int32_T b_i;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T idx;
    int32_T ii_size_idx_1;
    int32_T nz;
    int32_T trueCount;
    uint32_T b_tmp_data[31];
    int8_T ii_data[30];
    boolean_T tmp_data[31];
    boolean_T toDelete[30];
    boolean_T exitg1;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    NumberOfTracks = this->pNumLiveTracks;
    b = this->pNumLiveTracks;
    if (muDoubleScalarIsNaN(b)) {
      unassigned.set_size(&on_emlrtRTEI, sp, 1, 1);
      unassigned[0] = rtNaN;
    } else if (b < 1.0) {
      unassigned.set_size(&on_emlrtRTEI, sp, 1, 0);
    } else if (muDoubleScalarIsInf(b) && (1.0 == b)) {
      unassigned.set_size(&on_emlrtRTEI, sp, 1, 1);
      unassigned[0] = rtNaN;
    } else {
      idx = static_cast<int32_T>(muDoubleScalarFloor(b - 1.0));
      unassigned.set_size(&on_emlrtRTEI, sp, 1, idx + 1);
      for (i = 0; i <= idx; i++) {
        unassigned[i] = static_cast<real_T>(i) + 1.0;
      }
    }

    for (i = 0; i < 30; i++) {
      toDelete[i] = false;
    }

    i = static_cast<int32_T>(((-1.0 - NumberOfTracks) + 1.0) / -1.0);
    emlrtForLoopVectorCheckR2012b(NumberOfTracks, -1.0, 1.0, mxDOUBLE_CLASS, i,
      &cd_emlrtRTEI, sp);
    for (b_i = 0; b_i < i; b_i++) {
      b = NumberOfTracks + -static_cast<real_T>(b_i);
      i1 = static_cast<int32_T>(muDoubleScalarFloor(b));
      if (b != i1) {
        emlrtIntegerCheckR2012b(b, &sb_emlrtDCI, sp);
      }

      i2 = static_cast<int32_T>(b);
      if ((b < 1.0) || (i2 > unassigned.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b), 1,
          unassigned.size(1), &aj_emlrtBCI, sp);
      }

      d = unassigned[static_cast<int32_T>(b) - 1];
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &sb_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) > 30)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, 30,
          &yi_emlrtBCI, sp);
      }

      if (this->pWasDetectable[static_cast<int32_T>(d) - 1]) {
        if (i2 != i1) {
          emlrtIntegerCheckR2012b(b, &tb_emlrtDCI, sp);
        }

        if ((b < 1.0) || (i2 > unassigned.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b), 1,
            unassigned.size(1), &cj_emlrtBCI, sp);
        }

        d = unassigned[static_cast<int32_T>(b) - 1];
        if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
          emlrtIntegerCheckR2012b(d, &tb_emlrtDCI, sp);
        }

        if ((static_cast<int32_T>(d) - 1 < 0) || (static_cast<int32_T>(d) - 1 >
             29)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d) - 1, 0, 29,
            &bj_emlrtBCI, sp);
        }

        if (i2 != i1) {
          emlrtIntegerCheckR2012b(b, &ub_emlrtDCI, sp);
        }

        if ((b < 1.0) || (i2 > unassigned.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b), 1,
            unassigned.size(1), &ej_emlrtBCI, sp);
        }

        b = unassigned[static_cast<int32_T>(b) - 1];
        if (b != static_cast<int32_T>(muDoubleScalarFloor(b))) {
          emlrtIntegerCheckR2012b(b, &ub_emlrtDCI, sp);
        }

        if ((static_cast<int32_T>(b) < 1) || (static_cast<int32_T>(b) > 30)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b), 1, 30,
            &dj_emlrtBCI, sp);
        }

        st.site = &dkb_emlrtRSI;
        toDelete[static_cast<int32_T>(b) - 1] = this->pTracksList
          [static_cast<int32_T>(d) - 1]->checkDeletion(&st);
      }
    }

    trueCount = 0;
    idx = 0;
    for (b_i = 0; b_i < 30; b_i++) {
      if (toDelete[b_i]) {
        trueCount++;
        ii_data[idx] = static_cast<int8_T>(b_i + 1);
        idx++;
      }
    }

    delTrIDs_size[0] = 1;
    delTrIDs_size[1] = trueCount;
    for (i = 0; i < trueCount; i++) {
      delTrIDs_data[i] = this->pTrackIDs[ii_data[i] - 1];
    }

    st.site = &ekb_emlrtRSI;
    nz = toDelete[0];
    for (idx = 0; idx < 29; idx++) {
      nz += toDelete[idx + 1];
    }

    idx = 0;
    trueCount = 0;
    exitg1 = false;
    while ((!exitg1) && (trueCount < 30)) {
      if (toDelete[trueCount]) {
        idx++;
        ii_data[idx - 1] = static_cast<int8_T>(trueCount + 1);
        if (idx >= 30) {
          exitg1 = true;
        } else {
          trueCount++;
        }
      } else {
        trueCount++;
      }
    }

    if (1 > idx) {
      ii_size_idx_1 = 0;
    } else {
      ii_size_idx_1 = idx;
    }

    for (b_i = 0; b_i < nz; b_i++) {
      if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>(b_i + 1U)
           > ii_size_idx_1)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
          ii_size_idx_1, &fj_emlrtBCI, &st);
      }

      b_st.site = &hkb_emlrtRSI;
      this->pTracksList[ii_data[b_i] - 1]->nullify(&b_st);
    }

    i = static_cast<int32_T>(((-1.0 - static_cast<real_T>(nz)) + 1.0) / -1.0);
    emlrtForLoopVectorCheckR2012b(static_cast<real_T>(nz), -1.0, 1.0,
      mxDOUBLE_CLASS, i, &ed_emlrtRTEI, &st);
    for (b_i = 0; b_i < i; b_i++) {
      int32_T currentInd_tmp;
      b = static_cast<real_T>(nz) + -static_cast<real_T>(b_i);
      if ((static_cast<int32_T>(b) < 1) || (static_cast<int32_T>(b) >
           ii_size_idx_1)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b), 1, ii_size_idx_1,
          &gj_emlrtBCI, &st);
      }

      currentInd_tmp = ii_data[static_cast<int32_T>(b) - 1];
      temp = this->pTracksList[currentInd_tmp - 1];
      d = this->pNumLiveTracks;
      i1 = static_cast<int32_T>(d + (1.0 - (static_cast<real_T>(currentInd_tmp)
        + 1.0)));
      emlrtForLoopVectorCheckR2012b(static_cast<real_T>(currentInd_tmp) + 1.0,
        1.0, d, mxDOUBLE_CLASS, i1, &dd_emlrtRTEI, &st);
      for (idx = 0; idx < i1; idx++) {
        uint32_T j;
        j = (static_cast<uint32_T>(currentInd_tmp) + idx) + 1U;
        if (static_cast<real_T>(j) != static_cast<int32_T>(j)) {
          emlrtIntegerCheckR2012b(static_cast<real_T>(j), &vb_emlrtDCI, &st);
        }

        if ((static_cast<int32_T>(j) - 1 < 0) || (static_cast<int32_T>(j) - 1 >
             29)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j) - 1, 0, 29,
            &hj_emlrtBCI, &st);
        }

        if (static_cast<real_T>(j) - 1.0 != static_cast<int32_T>
            (static_cast<real_T>(j) - 1.0)) {
          emlrtIntegerCheckR2012b(static_cast<real_T>(j) - 1.0, &wb_emlrtDCI,
            &st);
        }

        if ((static_cast<int32_T>(static_cast<real_T>(j) - 1.0) - 1 < 0) || (
             static_cast<int32_T>(static_cast<real_T>(j) - 1.0) - 1 > 29)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(static_cast<real_T>
            (j) - 1.0) - 1, 0, 29, &ij_emlrtBCI, &st);
        }

        this->pTracksList[static_cast<int32_T>(static_cast<real_T>(j) - 1.0) - 1]
          = this->pTracksList[static_cast<int32_T>(j) - 1];
      }

      if (this->pNumLiveTracks != static_cast<int32_T>(muDoubleScalarFloor
           (this->pNumLiveTracks))) {
        emlrtIntegerCheckR2012b(this->pNumLiveTracks, &rb_emlrtDCI, &st);
      }

      i1 = static_cast<int32_T>(this->pNumLiveTracks) - 1;
      if ((i1 < 0) || (i1 > 29)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, 29, &vi_emlrtBCI, &st);
      }

      this->pTracksList[i1] = temp;
      this->pNumLiveTracks--;
      if (currentInd_tmp + 1 > 30) {
        i1 = 0;
        i2 = 0;
      } else {
        if (currentInd_tmp + 1 > 30) {
          emlrtDynamicBoundsCheckR2012b(currentInd_tmp + 1, 1, 30, &xi_emlrtBCI,
            &st);
        }

        i1 = currentInd_tmp;
        i2 = 30;
      }

      idx = i2 - i1;
      trueCount = idx + 1;
      for (i2 = 0; i2 < idx; i2++) {
        tmp_data[i2] = this->pConfirmedTracks[i1 + i2];
      }

      tmp_data[idx] = false;
      if (31 - currentInd_tmp != idx + 1) {
        emlrtSubAssignSizeCheck1dR2017a(31 - currentInd_tmp, idx + 1,
          &db_emlrtECI, &st);
      }

      for (i1 = 0; i1 < trueCount; i1++) {
        this->pConfirmedTracks[(currentInd_tmp + i1) - 1] = tmp_data[i1];
      }

      if (ii_data[static_cast<int32_T>(b) - 1] + 1 > 30) {
        i1 = 0;
        i2 = 0;
      } else {
        if (currentInd_tmp + 1 > 30) {
          emlrtDynamicBoundsCheckR2012b(currentInd_tmp + 1, 1, 30, &wi_emlrtBCI,
            &st);
        }

        i1 = currentInd_tmp;
        i2 = 30;
      }

      idx = i2 - i1;
      trueCount = idx + 1;
      for (i2 = 0; i2 < idx; i2++) {
        b_tmp_data[i2] = this->pTrackIDs[i1 + i2];
      }

      b_tmp_data[idx] = 0U;
      if (31 - currentInd_tmp != idx + 1) {
        emlrtSubAssignSizeCheck1dR2017a(31 - currentInd_tmp, idx + 1,
          &cb_emlrtECI, &st);
      }

      for (i1 = 0; i1 < trueCount; i1++) {
        this->pTrackIDs[(currentInd_tmp + i1) - 1] = b_tmp_data[i1];
      }
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::findTracksByIDs(const emlrtStack *sp, const ::coder::array<
    uint32_T, 2U> &trackIDs, ::coder::array<uint32_T, 2U> &indices) const
  {
    emlrtStack st;
    int32_T tmp_size[2];
    int32_T tmp_data[1];
    int32_T i;
    uint32_T b_tmp_data[1];
    boolean_T x[30];
    st.prev = sp;
    st.tls = sp->tls;
    i = trackIDs.size(1);
    indices.set_size(&ol_emlrtRTEI, sp, 1, trackIDs.size(1));
    for (int32_T b_i = 0; b_i < i; b_i++) {
      int32_T i1;
      int32_T loop_ub;
      uint32_T b_trackIDs;
      st.site = &nfb_emlrtRSI;
      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > trackIDs.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, trackIDs.size(1), &ag_emlrtBCI, &st);
      }

      b_trackIDs = trackIDs[b_i];
      for (i1 = 0; i1 < 30; i1++) {
        x[i1] = (b_trackIDs == this->pTrackIDs[i1]);
      }

      c_eml_find(x, tmp_data, tmp_size);
      loop_ub = tmp_size[0] * tmp_size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        int32_T i2;
        i2 = tmp_data[i1];
        if (i2 < 0) {
          i2 = 0;
        }

        b_tmp_data[i1] = static_cast<uint32_T>(i2);
      }

      if (1 != tmp_size[1]) {
        emlrtSubAssignSizeCheck1dR2017a(1, tmp_size[1], &v_emlrtECI, sp);
      }

      if ((b_i + 1 < 1) || (b_i + 1 > indices.size(1))) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, indices.size(1), &bg_emlrtBCI,
          sp);
      }

      indices[b_i] = b_tmp_data[0];
    }
  }

  void trackerJPDA::formatTrackOutputs(const emlrtStack *sp, struct1_T
    varargout_1_data[], int32_T varargout_1_size[1], struct1_T varargout_2_data[],
    int32_T varargout_2_size[1], ::coder::array<struct1_T, 2U> &varargout_3)
  {
    array<real_T, 2U> liveTracks;
    array<int32_T, 1U> r;
    array<boolean_T, 1U> list;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    struct1_T st;
    real_T varargin_1[2];
    real_T b;
    int32_T i;
    int32_T loop_ub;
    int32_T nz;
    int32_T partialTrueCount;
    int32_T trueCount;
    int8_T c_tmp_data[30];
    int8_T tmp_data[30];
    int8_T b_i;
    boolean_T b_tmp_data[30];
    b_st.prev = sp;
    b_st.tls = sp->tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    b_st.site = &ikb_emlrtRSI;
    if (!(this->pNumLiveTracks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(this->pNumLiveTracks, &ac_emlrtDCI, &b_st);
    }

    b = this->pNumLiveTracks;
    if (b != static_cast<int32_T>(muDoubleScalarFloor(b))) {
      emlrtIntegerCheckR2012b(b, &yb_emlrtDCI, &b_st);
    }

    list.set_size(&qn_emlrtRTEI, &b_st, static_cast<int32_T>(b));
    if (!(this->pNumLiveTracks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(this->pNumLiveTracks, &ac_emlrtDCI, &b_st);
    }

    b = this->pNumLiveTracks;
    if (b != static_cast<int32_T>(muDoubleScalarFloor(b))) {
      emlrtIntegerCheckR2012b(b, &yb_emlrtDCI, &b_st);
    }

    loop_ub = static_cast<int32_T>(b);
    for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
      list[partialTrueCount] = true;
    }

    c_st.site = &jkb_emlrtRSI;
    d_st.site = &wi_emlrtRSI;
    e_st.site = &xi_emlrtRSI;
    nz = combineVectorElements(&e_st, list);
    b = this->pNumLiveTracks;
    if (muDoubleScalarIsNaN(b)) {
      liveTracks.set_size(&rn_emlrtRTEI, &b_st, 1, 1);
      liveTracks[0] = rtNaN;
    } else if (b < 1.0) {
      liveTracks.set_size(&rn_emlrtRTEI, &b_st, 1, 0);
    } else if (muDoubleScalarIsInf(b) && (1.0 == b)) {
      liveTracks.set_size(&rn_emlrtRTEI, &b_st, 1, 1);
      liveTracks[0] = rtNaN;
    } else {
      loop_ub = static_cast<int32_T>(muDoubleScalarFloor(b - 1.0));
      liveTracks.set_size(&rn_emlrtRTEI, &b_st, 1, loop_ub + 1);
      for (partialTrueCount = 0; partialTrueCount <= loop_ub; partialTrueCount++)
      {
        liveTracks[partialTrueCount] = static_cast<real_T>(partialTrueCount) +
          1.0;
      }
    }

    loop_ub = static_cast<int32_T>(this->pNumLiveTracks);
    for (i = 0; i < loop_ub; i++) {
      if ((i + 1 < 1) || (i + 1 > liveTracks.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, liveTracks.size(1), &kj_emlrtBCI,
          &b_st);
      }
    }

    loop_ub = static_cast<int32_T>(this->pNumLiveTracks) - 1;
    trueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      trueCount++;
    }

    r.set_size(&sn_emlrtRTEI, &b_st, trueCount);
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      r[partialTrueCount] = i + 1;
      partialTrueCount++;
    }

    c_st.site = &kkb_emlrtRSI;
    d_st.site = &lkb_emlrtRSI;
    this->pTracksList[0]->trackToStruct(&d_st, &st);
    d_st.site = &mkb_emlrtRSI;
    varargin_1[0] = nz;
    varargin_1[1] = 1.0;
    e_st.site = &yk_emlrtRSI;
    internal::assertValidSizeArg(&e_st, varargin_1);
    if (nz < 0) {
      emlrtNonNegativeCheckR2012b(static_cast<real_T>(nz), &p_emlrtDCI, &d_st);
    }

    varargout_3.set_size(&tn_emlrtRTEI, &d_st, nz, 1);
    for (partialTrueCount = 0; partialTrueCount < nz; partialTrueCount++) {
      varargout_3[partialTrueCount] = st;
    }

    if (nz > 0) {
      loop_ub = r.size(0);
      for (i = 0; i < nz; i++) {
        partialTrueCount = i + 1;
        if (partialTrueCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(partialTrueCount, 1, loop_ub,
            &lj_emlrtBCI, &c_st);
        }

        b = liveTracks[r[i] - 1];
        if (b != static_cast<int32_T>(muDoubleScalarFloor(b))) {
          emlrtIntegerCheckR2012b(b, &bc_emlrtDCI, &c_st);
        }

        if ((static_cast<int32_T>(b) - 1 < 0) || (static_cast<int32_T>(b) - 1 >
             29)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b) - 1, 0, 29,
            &mj_emlrtBCI, &c_st);
        }

        if (i + 1 > varargout_3.size(0)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, varargout_3.size(0),
            &nj_emlrtBCI, &c_st);
        }

        d_st.site = &nkb_emlrtRSI;
        this->pTracksList[static_cast<int32_T>(b) - 1]->trackToStruct(&d_st,
          &varargout_3[i]);
      }
    }

    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i < 30; i++) {
      if (this->pConfirmedTracks[i]) {
        trueCount++;
      }

      if (this->pConfirmedTracks[i]) {
        tmp_data[partialTrueCount] = static_cast<int8_T>(i + 1);
        partialTrueCount++;
      }
    }

    varargout_1_size[0] = trueCount;
    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      b_i = tmp_data[partialTrueCount];
      if (b_i > varargout_3.size(0)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i), 1,
          varargout_3.size(0), &oj_emlrtBCI, sp);
      }

      varargout_1_data[partialTrueCount] = varargout_3[b_i - 1];
    }

    b = this->pNumLiveTracks;
    if (1.0 > b) {
      loop_ub = 0;
    } else {
      if (b != static_cast<int32_T>(muDoubleScalarFloor(b))) {
        emlrtIntegerCheckR2012b(b, &xb_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(b) < 1) || (static_cast<int32_T>(b) > 30)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b), 1, 30,
          &jj_emlrtBCI, sp);
      }

      loop_ub = static_cast<int32_T>(b);
    }

    for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
      b_tmp_data[partialTrueCount] = !this->pConfirmedTracks[partialTrueCount];
    }

    loop_ub--;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i <= loop_ub; i++) {
      if (b_tmp_data[i]) {
        trueCount++;
        c_tmp_data[partialTrueCount] = static_cast<int8_T>(i + 1);
        partialTrueCount++;
      }
    }

    varargout_2_size[0] = trueCount;
    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      b_i = c_tmp_data[partialTrueCount];
      if ((b_i < 1) || (b_i > varargout_3.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i), 1,
          varargout_3.size(0), &pj_emlrtBCI, sp);
      }

      varargout_2_data[partialTrueCount] = varargout_3[b_i - 1];
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::initializeTracks(const emlrtStack *sp, ::coder::array<real_T,
    2U> &OverallUnassigned, uint32_T initTrIDs_data[], int32_T initTrIDs_size[2])
  {
    matlabshared::tracking::internal::fusion::ObjectTrack *track;
    objectDetection rv[1];
    trackingEKF filter;
    array<objectDetection, 2U> b_obj;
    array<objectDetection, 1U> r;
    array<real_T, 2U> b_OverallUnassigned;
    array<real_T, 2U> costMatrix;
    array<real_T, 2U> r3;
    array<real_T, 2U> sensorsInUnassigned;
    array<int32_T, 2U> b_m;
    array<int32_T, 1U> r2;
    array<boolean_T, 1U> r1;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T dv[9];
    real_T lastTrackInd;
    real_T newTrackIndex;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    lastTrackInd = this->pNumLiveTracks;
    int32_T exitg1;
    do {
      exitg1 = 0;
      st.site = &kjb_emlrtRSI;
      if (OverallUnassigned.size(1) != 0) {
        real_T NewTrackNumber;
        uint32_T m;
        uint32_T qY;
        boolean_T tf;
        r.set_size(&cn_emlrtRTEI, sp, this->pDetections.size(0) *
                   this->pDetections.size(1));
        loop_ub = this->pDetections.size(0) * this->pDetections.size(1);
        for (i = 0; i < loop_ub; i++) {
          r[i] = this->pDetections[i];
        }

        i = static_cast<int32_T>(muDoubleScalarFloor(OverallUnassigned[0]));
        if (OverallUnassigned[0] != i) {
          emlrtIntegerCheckR2012b(OverallUnassigned[0], &mb_emlrtDCI, sp);
        }

        i1 = static_cast<int32_T>(OverallUnassigned[0]) - 1;
        if ((i1 < 0) || (i1 > r.size(0) - 1)) {
          emlrtDynamicBoundsCheckR2012b(i1, 0, r.size(0) - 1, &ii_emlrtBCI, sp);
        }

        NewTrackNumber = this->pNumLiveTracks + 1.0;
        m = this->pLastTrackID;
        qY = m + 1U;
        if (m + 1U < m) {
          qY = MAX_uint32_T;
        }

        st.site = &ljb_emlrtRSI;
        newTrackIndex = this->pNumLiveTracks + 1.0;
        if (newTrackIndex <= 30.0) {
          if (newTrackIndex != static_cast<int32_T>(muDoubleScalarFloor
               (newTrackIndex))) {
            emlrtIntegerCheckR2012b(newTrackIndex, &nb_emlrtDCI, &st);
          }

          if ((static_cast<int32_T>(newTrackIndex) < 1) || (static_cast<int32_T>
               (newTrackIndex) > 30)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(newTrackIndex), 1,
              30, &li_emlrtBCI, &st);
          }

          this->pTrackIDs[static_cast<int32_T>(newTrackIndex) - 1] = qY;
          this->pNumLiveTracks++;
          track = this->pTracksList[static_cast<int32_T>(newTrackIndex) - 1];
          track->TrackID = qY;
          b_st.site = &vjb_emlrtRSI;
          track->setObjectAttributes(&b_st, r[static_cast<int32_T>
            (OverallUnassigned[0]) - 1].SensorIndex);
          track->Time = r[i1].Time;
          track->ObjectClassID = r[i1].ObjectClassID;
          track->pAge = 1U;
          b_st.site = &ujb_emlrtRSI;
          track->TrackLogic->reset();
          b_st.site = &tjb_emlrtRSI;
          track->TrackLogic->init(&b_st);
          b_st.site = &sjb_emlrtRSI;
          track->IsConfirmed = track->checkPromotion();
          b_st.site = &rjb_emlrtRSI;
          track->set_IsCoasted();
          this->pConfirmedTracks[static_cast<int32_T>(newTrackIndex) - 1] =
            track->IsConfirmed;
          b_st.site = &qjb_emlrtRSI;
          c_st.site = &akb_emlrtRSI;
          initializeEKF(&c_st, &r[static_cast<int32_T>(OverallUnassigned[0]) - 1],
                        &filter);
          r[static_cast<int32_T>(OverallUnassigned[0]) - 1].get_MeasurementNoise
            (dv);
          c_st.site = &wjb_emlrtRSI;
          filter.set_MeasurementNoise(&c_st, dv);
          track = this->pTracksList[static_cast<int32_T>(newTrackIndex) - 1];
          c_st.site = &xjb_emlrtRSI;
          track->Filter->sync(&c_st, &filter);
          c_st.site = &yjb_emlrtRSI;
          track->pDistanceFilter->sync(&c_st, &filter);
          tf = true;
        } else {
          tf = false;
        }

        if (tf) {
          int32_T b_i;
          int32_T i2;
          int32_T i3;
          int32_T obj;
          this->pLastTrackID = qY;
          costMatrix.set_size(&dn_emlrtRTEI, sp, 1, OverallUnassigned.size(1));
          loop_ub = OverallUnassigned.size(1);
          for (i2 = 0; i2 < loop_ub; i2++) {
            costMatrix[i2] = 0.0;
          }

          i2 = static_cast<int32_T>(muDoubleScalarFloor(NewTrackNumber));
          if (NewTrackNumber != i2) {
            emlrtIntegerCheckR2012b(NewTrackNumber, &ob_emlrtDCI, sp);
          }

          i3 = static_cast<int32_T>(NewTrackNumber) - 1;
          if ((i3 < 0.0) || (i3 > 29.0)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(NewTrackNumber) -
              1, 0, 29, &mi_emlrtBCI, sp);
          }

          track = this->pTracksList[i3];
          r.set_size(&en_emlrtRTEI, sp, this->pDetections.size(0) *
                     this->pDetections.size(1));
          loop_ub = this->pDetections.size(0) * this->pDetections.size(1);
          for (b_i = 0; b_i < loop_ub; b_i++) {
            r[b_i] = this->pDetections[b_i];
          }

          if (OverallUnassigned[0] != i) {
            emlrtIntegerCheckR2012b(OverallUnassigned[0], &lb_emlrtDCI, sp);
          }

          if (i1 > r.size(0) - 1) {
            emlrtDynamicBoundsCheckR2012b(i1, 0, r.size(0) - 1, &hi_emlrtBCI, sp);
          }

          newTrackIndex = r[i1].SensorIndex;
          obj = this->pOriginatingSensor.size(1);
          sensorsInUnassigned.set_size(&fn_emlrtRTEI, sp, 1,
            OverallUnassigned.size(1));
          loop_ub = OverallUnassigned.size(1);
          for (i = 0; i < loop_ub; i++) {
            if (OverallUnassigned[i] != static_cast<int32_T>(muDoubleScalarFloor
                 (OverallUnassigned[i]))) {
              emlrtIntegerCheckR2012b(OverallUnassigned[i], &pb_emlrtDCI, sp);
            }

            b_i = static_cast<int32_T>(OverallUnassigned[i]);
            if ((b_i < 1) || (b_i > obj)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, obj, &ni_emlrtBCI, sp);
            }

            sensorsInUnassigned[i] = this->pOriginatingSensor[b_i - 1];
          }

          loop_ub = sensorsInUnassigned.size(1);
          for (b_i = 0; b_i < loop_ub; b_i++) {
            if (sensorsInUnassigned[b_i] == newTrackIndex) {
              if ((b_i + 1 < 1) || (b_i + 1 > costMatrix.size(1))) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, costMatrix.size(1),
                  &oi_emlrtBCI, sp);
              }

              costMatrix[b_i] = rtInf;
            }
          }

          r1.set_size(&gn_emlrtRTEI, sp, sensorsInUnassigned.size(1));
          loop_ub = sensorsInUnassigned.size(1);
          for (i = 0; i < loop_ub; i++) {
            r1[i] = !(sensorsInUnassigned[i] == r[i1].SensorIndex);
          }

          loop_ub = r1.size(0) - 1;
          obj = 0;
          for (b_i = 0; b_i <= loop_ub; b_i++) {
            if (r1[b_i]) {
              obj++;
            }
          }

          r2.set_size(&hn_emlrtRTEI, sp, obj);
          obj = 0;
          for (b_i = 0; b_i <= loop_ub; b_i++) {
            if (r1[b_i]) {
              r2[obj] = b_i + 1;
              obj++;
            }
          }

          b_OverallUnassigned.set_size(&in_emlrtRTEI, sp, 1, r2.size(0));
          loop_ub = r2.size(0);
          for (i = 0; i < loop_ub; i++) {
            if ((r2[i] < 1) || (r2[i] > OverallUnassigned.size(1))) {
              emlrtDynamicBoundsCheckR2012b(r2[i], 1, OverallUnassigned.size(1),
                &pi_emlrtBCI, sp);
            }

            b_OverallUnassigned[i] = OverallUnassigned[r2[i] - 1];
          }

          b_obj.set_size(&jn_emlrtRTEI, sp, this->pDetections.size(0),
                         this->pDetections.size(1));
          loop_ub = this->pDetections.size(0) * this->pDetections.size(1) - 1;
          for (i = 0; i <= loop_ub; i++) {
            b_obj[i] = this->pDetections[i];
          }

          st.site = &mjb_emlrtRSI;
          track->distance(&st, b_obj, b_OverallUnassigned, r3);
          loop_ub = sensorsInUnassigned.size(1);
          obj = 0;
          for (b_i = 0; b_i < loop_ub; b_i++) {
            if (!(sensorsInUnassigned[b_i] == newTrackIndex)) {
              obj++;
            }
          }

          if (obj != r3.size(1)) {
            emlrtSubAssignSizeCheck1dR2017a(obj, r3.size(1), &bb_emlrtECI, sp);
          }

          loop_ub = sensorsInUnassigned.size(1);
          obj = 0;
          for (b_i = 0; b_i < loop_ub; b_i++) {
            if (!(sensorsInUnassigned[b_i] == newTrackIndex)) {
              if ((b_i + 1 < 1) || (b_i + 1 > costMatrix.size(1))) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, costMatrix.size(1),
                  &qi_emlrtBCI, sp);
              }

              costMatrix[b_i] = r3[obj];
              obj++;
            }
          }

          sensorsInUnassigned.set_size(&kn_emlrtRTEI, sp, 1,
            OverallUnassigned.size(1));
          loop_ub = OverallUnassigned.size(1);
          for (i = 0; i < loop_ub; i++) {
            sensorsInUnassigned[i] = 0.0;
          }

          m = 0U;
          i = OverallUnassigned.size(1);
          for (obj = 0; obj <= i - 2; obj++) {
            if ((obj + 2 < 1) || (obj + 2 > costMatrix.size(1))) {
              emlrtDynamicBoundsCheckR2012b(obj + 2, 1, costMatrix.size(1),
                &si_emlrtBCI, sp);
            }

            if (costMatrix[obj + 1] <= 50.0) {
              r.set_size(&ln_emlrtRTEI, sp, this->pDetections.size(0) *
                         this->pDetections.size(1));
              loop_ub = this->pDetections.size(0) * this->pDetections.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                r[i1] = this->pDetections[i1];
              }

              if ((obj + 2 < 1) || (obj + 2 > OverallUnassigned.size(1))) {
                emlrtDynamicBoundsCheckR2012b(obj + 2, 1, OverallUnassigned.size
                  (1), &gi_emlrtBCI, sp);
              }

              i1 = static_cast<int32_T>(OverallUnassigned[obj + 1]) - 1;
              if ((i1 < 0) || (i1 > r.size(0) - 1)) {
                emlrtDynamicBoundsCheckR2012b(i1, 0, r.size(0) - 1, &gi_emlrtBCI,
                  sp);
              }

              rv[0] = r[static_cast<int32_T>(OverallUnassigned[obj + 1]) - 1];
              st.site = &njb_emlrtRSI;
              track->correctjpda(&st, rv);
            } else {
              m++;
              if ((obj + 2 < 1) || (obj + 2 > OverallUnassigned.size(1))) {
                emlrtDynamicBoundsCheckR2012b(obj + 2, 1, OverallUnassigned.size
                  (1), &ti_emlrtBCI, sp);
              }

              if ((static_cast<int32_T>(m) < 1) || (static_cast<int32_T>(m) >
                   sensorsInUnassigned.size(1))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(m), 1,
                  sensorsInUnassigned.size(1), &ui_emlrtBCI, sp);
              }

              sensorsInUnassigned[static_cast<int32_T>(m) - 1] =
                OverallUnassigned[obj + 1];
            }
          }

          if (static_cast<int32_T>(NewTrackNumber) != i2) {
            emlrtIntegerCheckR2012b(NewTrackNumber, &qb_emlrtDCI, sp);
          }

          if ((NewTrackNumber < 1.0) || (NewTrackNumber > 30.0)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(NewTrackNumber),
              1, 30, &ri_emlrtBCI, sp);
          }

          this->pConfirmedTracks[i3] = this->pTracksList[i3]->IsConfirmed;
          if (static_cast<int32_T>(m) > 0) {
            OverallUnassigned.set_size(&mn_emlrtRTEI, sp, 1,
              sensorsInUnassigned.size(1));
            loop_ub = sensorsInUnassigned.size(0) * sensorsInUnassigned.size(1);
            for (i = 0; i < loop_ub; i++) {
              OverallUnassigned[i] = sensorsInUnassigned[i];
            }

            b_m.set_size(&nn_emlrtRTEI, sp, 1, sensorsInUnassigned.size(1) -
                         static_cast<int32_T>(m));
            loop_ub = sensorsInUnassigned.size(1) - static_cast<int32_T>(m);
            for (i = 0; i < loop_ub; i++) {
              b_m[i] = (static_cast<int32_T>(m) + i) + 1;
            }

            st.site = &ojb_emlrtRSI;
            internal::nullAssignment(&st, OverallUnassigned, b_m);
          } else {
            exitg1 = 1;
          }
        } else {
          st.site = &pjb_emlrtRSI;
          internal::g_warning(&st);
          exitg1 = 1;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    newTrackIndex = this->pNumLiveTracks;
    if (lastTrackInd + 1.0 > newTrackIndex) {
      i = 0;
      i1 = 0;
    } else {
      if (lastTrackInd + 1.0 != static_cast<int32_T>(muDoubleScalarFloor
           (lastTrackInd + 1.0))) {
        emlrtIntegerCheckR2012b(lastTrackInd + 1.0, &kb_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(lastTrackInd + 1.0) < 1) || (static_cast<int32_T>
           (lastTrackInd + 1.0) > 30)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(lastTrackInd + 1.0),
          1, 30, &ki_emlrtBCI, sp);
      }

      i = static_cast<int32_T>(lastTrackInd + 1.0) - 1;
      if (newTrackIndex != static_cast<int32_T>(muDoubleScalarFloor
           (newTrackIndex))) {
        emlrtIntegerCheckR2012b(newTrackIndex, &jb_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(newTrackIndex) < 1) || (static_cast<int32_T>
           (newTrackIndex) > 30)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(newTrackIndex), 1, 30,
          &ji_emlrtBCI, sp);
      }

      i1 = static_cast<int32_T>(newTrackIndex);
    }

    initTrIDs_size[0] = 1;
    loop_ub = i1 - i;
    initTrIDs_size[1] = loop_ub;
    for (i1 = 0; i1 < loop_ub; i1++) {
      initTrIDs_data[i1] = this->pTrackIDs[i + i1];
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::jpdaClusterUpdate(const emlrtStack *sp, const ::coder::array<
    struct_T, 2U> &preClusters, ::coder::array<boolean_T, 2U>
    &isUnassignedDetection, ::coder::array<struct_T, 2U> &clusterInfo)
  {
    matlabshared::tracking::internal::fusion::ObjectTrack *track;
    trackingEKF *filter;
    array<objectDetection, 2U> dets;
    array<objectDetection, 1U> r;
    array<objectDetection, 1U> r1;
    array<real_T, 2U> b_jpda_beta;
    array<real_T, 2U> jpda_beta;
    array<real_T, 2U> lhoodMatrix;
    array<real_T, 2U> sorting;
    array<real_T, 1U> b_clusterInfo;
    array<int32_T, 2U> iidx;
    array<int32_T, 1U> r2;
    array<uint32_T, 2U> clusterTrackId;
    array<boolean_T, 3U> FJE;
    array<boolean_T, 2U> c_jpda_beta;
    array<boolean_T, 1U> isWeak;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack st;
    real_T dv[9];
    real_T varargin_1[2];
    int32_T i;
    int32_T i1;
    int32_T ncolx;
    int32_T ntilerows;
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
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    if (preClusters.size(1) != 0) {
      i = preClusters.size(1);
      sorting.set_size(&go_emlrtRTEI, sp, 1, preClusters.size(1));
      for (ntilerows = 0; ntilerows < i; ntilerows++) {
        if ((ntilerows + 1 < 1) || (ntilerows + 1 > preClusters.size(1))) {
          emlrtDynamicBoundsCheckR2012b(ntilerows + 1, 1, preClusters.size(1),
            &ck_emlrtBCI, sp);
        }

        if ((ntilerows + 1 < 1) || (ntilerows + 1 > sorting.size(1))) {
          emlrtDynamicBoundsCheckR2012b(ntilerows + 1, 1, sorting.size(1),
            &dk_emlrtBCI, sp);
        }

        sorting[ntilerows] = preClusters[ntilerows].TimeStamp;
      }

      st.site = &cfb_emlrtRSI;
      b_st.site = &tbb_emlrtRSI;
      internal::sort(&b_st, sorting, iidx);
      sorting.set_size(&rk_emlrtRTEI, &st, 1, iidx.size(1));
      ncolx = iidx.size(0) * iidx.size(1);
      for (i = 0; i < ncolx; i++) {
        sorting[i] = iidx[i];
      }
    } else {
      sorting.set_size(&fo_emlrtRTEI, sp, 1, 0);
    }

    i = preClusters.size(1);
    clusterInfo.set_size(&go_emlrtRTEI, sp, 1, preClusters.size(1));
    for (ntilerows = 0; ntilerows < i; ntilerows++) {
      if ((ntilerows + 1 < 1) || (ntilerows + 1 > sorting.size(1))) {
        emlrtDynamicBoundsCheckR2012b(ntilerows + 1, 1, sorting.size(1),
          &ek_emlrtBCI, sp);
      }

      i1 = static_cast<int32_T>(sorting[ntilerows]);
      if ((i1 < 1) || (i1 > preClusters.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, preClusters.size(1), &ek_emlrtBCI,
          sp);
      }

      if (ntilerows > clusterInfo.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(ntilerows, 0, clusterInfo.size(1) - 1,
          &fk_emlrtBCI, sp);
      }

      clusterInfo[ntilerows] = preClusters[i1 - 1];
    }

    i = clusterInfo.size(1);
    if (0 <= clusterInfo.size(1) - 1) {
      varargin_1[1] = 1.0;
    }

    for (int32_T cl = 0; cl < i; cl++) {
      real_T mtime;
      int32_T b_i;
      int32_T col;
      int32_T i2;
      int32_T nrows;
      if (cl > clusterInfo.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(cl, 0, clusterInfo.size(1) - 1,
          &qj_emlrtBCI, sp);
      }

      st.site = &dfb_emlrtRSI;
      this->validateClusterDetectionsTime(&st, clusterInfo[cl].DetectionIndices);
      if (cl > clusterInfo.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(cl, 0, clusterInfo.size(1) - 1,
          &gk_emlrtBCI, sp);
      }

      st.site = &efb_emlrtRSI;
      this->findTracksByIDs(&st, clusterInfo[cl].TrackIDs, clusterTrackId);
      if (cl > clusterInfo.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(cl, 0, clusterInfo.size(1) - 1,
          &rj_emlrtBCI, sp);
      }

      st.site = &ffb_emlrtRSI;
      lhoodMatrix.set_size(&ho_emlrtRTEI, &st, clusterInfo[clusterInfo.size(0) *
                           cl].DetectionIndices.size(1), clusterTrackId.size(1));
      ncolx = clusterInfo[cl].DetectionIndices.size(1) * clusterTrackId.size(1);
      for (i1 = 0; i1 < ncolx; i1++) {
        lhoodMatrix[i1] = 0.0;
      }

      i1 = clusterInfo[cl].DetectionIndices.size(1);
      for (nrows = 0; nrows < i1; nrows++) {
        i2 = clusterTrackId.size(1);
        for (col = 0; col < i2; col++) {
          b_i = clusterInfo[cl].ValidationMatrix.size(0);
          if ((nrows + 1 < 1) || (nrows + 1 > b_i)) {
            emlrtDynamicBoundsCheckR2012b(nrows + 1, 1, b_i, &hk_emlrtBCI, &st);
          }

          b_i = clusterInfo[cl].ValidationMatrix.size(1);
          if ((static_cast<int32_T>(col + 2U) < 1) || (static_cast<int32_T>(col
                + 2U) > b_i)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(col + 2U), 1, b_i,
              &hk_emlrtBCI, &st);
          }

          mtime = clusterInfo[cl].ValidationMatrix[nrows + clusterInfo[cl].
            ValidationMatrix.size(0) * (col + 1)];
          b_st.site = &ofb_emlrtRSI;
          if (muDoubleScalarIsNaN(mtime)) {
            emlrtErrorWithMessageIdR2018a(&b_st, &lc_emlrtRTEI,
              "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
          }

          if (mtime != 0.0) {
            r.set_size(&io_emlrtRTEI, &st, this->pDetections.size(0) *
                       this->pDetections.size(1));
            ncolx = this->pDetections.size(0) * this->pDetections.size(1);
            for (b_i = 0; b_i < ncolx; b_i++) {
              r[b_i] = this->pDetections[b_i];
            }

            b_i = clusterInfo[cl].DetectionIndices.size(1);
            if ((nrows + 1 < 1) || (nrows + 1 > b_i)) {
              emlrtDynamicBoundsCheckR2012b(nrows + 1, 1, b_i, &tj_emlrtBCI, &st);
            }

            b_i = static_cast<int32_T>(clusterInfo[cl].DetectionIndices[nrows])
              - 1;
            if ((b_i < 0) || (b_i > r.size(0) - 1)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, r.size(0) - 1, &tj_emlrtBCI,
                &st);
            }

            ntilerows = this->pDetections.size(0) * this->pDetections.size(1);
            b_i = clusterInfo[cl].DetectionIndices.size(1);
            if ((nrows + 1 < 1) || (nrows + 1 > b_i)) {
              emlrtDynamicBoundsCheckR2012b(nrows + 1, 1, b_i, &uj_emlrtBCI, &st);
            }

            b_i = static_cast<int32_T>(clusterInfo[cl].DetectionIndices[nrows])
              - 1;
            if ((b_i < 0) || (b_i > ntilerows - 1)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, ntilerows - 1, &uj_emlrtBCI,
                &st);
            }

            if ((static_cast<int32_T>(col + 1U) < 1) || (static_cast<int32_T>
                 (col + 1U) > clusterTrackId.size(1))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(col + 1U), 1,
                clusterTrackId.size(1), &ik_emlrtBCI, &st);
            }

            filter = this->pTracksList[static_cast<int32_T>(clusterTrackId[col])
              - 1]->Filter;
            r1.set_size(&jo_emlrtRTEI, &st, this->pDetections.size(0) *
                        this->pDetections.size(1));
            ncolx = this->pDetections.size(0) * this->pDetections.size(1);
            for (b_i = 0; b_i < ncolx; b_i++) {
              r1[b_i] = this->pDetections[b_i];
            }

            b_i = clusterInfo[cl].DetectionIndices.size(1);
            if ((nrows + 1 < 1) || (nrows + 1 > b_i)) {
              emlrtDynamicBoundsCheckR2012b(nrows + 1, 1, b_i, &jk_emlrtBCI, &st);
            }

            b_i = static_cast<int32_T>(clusterInfo[cl].DetectionIndices[nrows])
              - 1;
            if ((b_i < 0) || (b_i > r1.size(0) - 1)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, r1.size(0) - 1, &jk_emlrtBCI,
                &st);
            }

            r1[b_i].get_MeasurementNoise(dv);
            b_st.site = &pfb_emlrtRSI;
            filter->set_MeasurementNoise(&b_st, dv);
            if (col > 29) {
              emlrtDynamicBoundsCheckR2012b(col, 0, 29, &vj_emlrtBCI, &st);
            }

            if ((nrows + 1 < 1) || (nrows + 1 > lhoodMatrix.size(0))) {
              emlrtDynamicBoundsCheckR2012b(nrows + 1, 1, lhoodMatrix.size(0),
                &kk_emlrtBCI, &st);
            }

            if (static_cast<int32_T>(col + 1U) > lhoodMatrix.size(1)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(col + 1U), 1,
                lhoodMatrix.size(1), &kk_emlrtBCI, &st);
            }

            b_st.site = &qfb_emlrtRSI;
            lhoodMatrix[nrows + lhoodMatrix.size(0) * col] = filter->likelihood(
              &b_st, r[static_cast<int32_T>(clusterInfo[cl]
              .DetectionIndices[nrows]) - 1].Measurement);
          }
        }
      }

      st.site = &gfb_emlrtRSI;
      jpdaEvents(&st, clusterInfo[cl].ValidationMatrix, FJE);
      st.site = &hfb_emlrtRSI;
      this->calcEventProbabilities(&st, FJE, lhoodMatrix, clusterInfo[cl].
        DetectionIndices, clusterTrackId, sorting);
      st.site = &ifb_emlrtRSI;
      trackerJPDA::associationProbabilities(&st, FJE, sorting, clusterInfo[cl].
        DetectionIndices, clusterTrackId, lhoodMatrix);
      st.site = &jfb_emlrtRSI;
      jpda_beta.set_size(&ko_emlrtRTEI, &st, lhoodMatrix.size(0),
                         lhoodMatrix.size(1));
      ncolx = lhoodMatrix.size(0) * lhoodMatrix.size(1);
      for (i1 = 0; i1 < ncolx; i1++) {
        jpda_beta[i1] = lhoodMatrix[i1];
      }

      b_st.site = &qhb_emlrtRSI;
      ntilerows = lhoodMatrix.size(0);
      c_st.site = &shb_emlrtRSI;
      c_st.site = &thb_emlrtRSI;
      ncolx = lhoodMatrix.size(1);
      nrows = lhoodMatrix.size(0) - 1;
      d_st.site = &uhb_emlrtRSI;
      if ((1 <= lhoodMatrix.size(1)) && (lhoodMatrix.size(1) > 2147483646)) {
        e_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (col = 0; col < ncolx; col++) {
        d_st.site = &vhb_emlrtRSI;
        for (b_i = ntilerows; b_i <= nrows; b_i++) {
          jpda_beta[(b_i + jpda_beta.size(0) * col) - 1] = jpda_beta[b_i +
            jpda_beta.size(0) * col];
        }
      }

      if (lhoodMatrix.size(0) - 1 > lhoodMatrix.size(0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &ld_emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      if (1 > lhoodMatrix.size(0) - 1) {
        ncolx = 0;
      } else {
        ncolx = lhoodMatrix.size(0) - 1;
      }

      ntilerows = jpda_beta.size(1) - 1;
      b_jpda_beta.set_size(&lo_emlrtRTEI, &c_st, ncolx, jpda_beta.size(1));
      for (i1 = 0; i1 <= ntilerows; i1++) {
        for (i2 = 0; i2 < ncolx; i2++) {
          b_jpda_beta[i2 + b_jpda_beta.size(0) * i1] = jpda_beta[i2 +
            jpda_beta.size(0) * i1];
        }
      }

      jpda_beta.set_size(&mo_emlrtRTEI, &c_st, b_jpda_beta.size(0),
                         b_jpda_beta.size(1));
      ncolx = b_jpda_beta.size(0) * b_jpda_beta.size(1);
      for (i1 = 0; i1 < ncolx; i1++) {
        jpda_beta[i1] = b_jpda_beta[i1];
      }

      c_jpda_beta.set_size(&no_emlrtRTEI, &st, jpda_beta.size(0), jpda_beta.size
                           (1));
      ncolx = jpda_beta.size(0) * jpda_beta.size(1);
      for (i1 = 0; i1 < ncolx; i1++) {
        c_jpda_beta[i1] = (jpda_beta[i1] < 0.0);
      }

      b_st.site = &rhb_emlrtRSI;
      b_all(&b_st, c_jpda_beta, isWeak);
      ncolx = isWeak.size(0) - 1;
      ntilerows = 0;
      for (b_i = 0; b_i <= ncolx; b_i++) {
        if (isWeak[b_i]) {
          ntilerows++;
        }
      }

      r2.set_size(&oo_emlrtRTEI, &st, ntilerows);
      ntilerows = 0;
      for (b_i = 0; b_i <= ncolx; b_i++) {
        if (isWeak[b_i]) {
          r2[ntilerows] = b_i + 1;
          ntilerows++;
        }
      }

      ncolx = r2.size(0);
      for (i1 = 0; i1 < ncolx; i1++) {
        i2 = clusterInfo[cl].DetectionIndices.size(1);
        if ((r2[i1] < 1) || (r2[i1] > i2)) {
          emlrtDynamicBoundsCheckR2012b(r2[i1], 1, i2, &lk_emlrtBCI, &st);
        }
      }

      ntilerows = isUnassignedDetection.size(1);
      ncolx = r2.size(0);
      iidx.set_size(&po_emlrtRTEI, sp, 1, r2.size(0));
      for (i1 = 0; i1 < ncolx; i1++) {
        i2 = static_cast<int32_T>(clusterInfo[cl].DetectionIndices[r2[i1] - 1]);
        if ((i2 < 1) || (i2 > ntilerows)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, ntilerows, &mk_emlrtBCI, sp);
        }

        iidx[i1] = i2;
      }

      ncolx = iidx.size(1);
      for (i1 = 0; i1 < ncolx; i1++) {
        isUnassignedDetection[iidx[i1] - 1] = true;
      }

      ncolx = lhoodMatrix.size(0) * lhoodMatrix.size(1);
      if (cl > clusterInfo.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(cl, 0, clusterInfo.size(1) - 1,
          &bk_emlrtBCI, sp);
      }

      clusterInfo[clusterInfo.size(0) * cl].MarginalProbabilities.set_size
        (&qo_emlrtRTEI, sp, lhoodMatrix.size(0), clusterInfo[clusterInfo.size(0)
         * cl].MarginalProbabilities.size(1));
      if (cl > clusterInfo.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(cl, 0, clusterInfo.size(1) - 1,
          &bk_emlrtBCI, sp);
      }

      clusterInfo[clusterInfo.size(0) * cl].MarginalProbabilities.set_size
        (&qo_emlrtRTEI, sp, clusterInfo[clusterInfo.size(0) * cl].
         MarginalProbabilities.size(0), lhoodMatrix.size(1));
      i1 = clusterInfo.size(1);
      if (cl > clusterInfo.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(cl, 0, clusterInfo.size(1) - 1,
          &bk_emlrtBCI, sp);
      }

      if (cl > clusterInfo.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(cl, 0, clusterInfo.size(1) - 1,
          &bk_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < ncolx; i2++) {
        if (cl > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(cl, 0, i1 - 1, &nk_emlrtBCI, sp);
        }

        clusterInfo[cl].MarginalProbabilities[i2] = lhoodMatrix[i2];
      }

      st.site = &kfb_emlrtRSI;
      if (cl > clusterInfo.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(cl, 0, clusterInfo.size(1) - 1,
          &sj_emlrtBCI, &st);
      }

      b_st.site = &whb_emlrtRSI;
      this->findTracksByIDs(&b_st, clusterInfo[cl].TrackIDs, clusterTrackId);
      b_st.site = &xhb_emlrtRSI;
      c_st.site = &yhb_emlrtRSI;
      r.set_size(&ro_emlrtRTEI, &c_st, this->pDetections.size(0) *
                 this->pDetections.size(1));
      ncolx = this->pDetections.size(0) * this->pDetections.size(1);
      for (i1 = 0; i1 < ncolx; i1++) {
        r[i1] = this->pDetections[i1];
      }

      i1 = clusterInfo[cl].DetectionIndices.size(1);
      if (1 > i1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i1, &yj_emlrtBCI, &c_st);
      }

      i1 = static_cast<int32_T>(clusterInfo[cl].DetectionIndices[0]) - 1;
      if ((i1 < 0) || (i1 > r.size(0) - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, r.size(0) - 1, &ak_emlrtBCI, &c_st);
      }

      d_st.site = &dib_emlrtRSI;
      varargin_1[0] = clusterInfo[cl].DetectionIndices.size(1);
      e_st.site = &yk_emlrtRSI;
      internal::assertValidSizeArg(&e_st, varargin_1);
      dets.set_size(&so_emlrtRTEI, &d_st, clusterInfo[clusterInfo.size(0) * cl].
                    DetectionIndices.size(1), 1);
      if (clusterInfo[cl].DetectionIndices.size(1) != 0) {
        ntilerows = clusterInfo[cl].DetectionIndices.size(1);
        e_st.site = &fib_emlrtRSI;
        for (ncolx = 0; ncolx < ntilerows; ncolx++) {
          dets[ncolx] = r[i1];
        }

        e_st.site = &eib_emlrtRSI;
        if ((1 <= clusterInfo[cl].DetectionIndices.size(1)) && (clusterInfo[cl].
             DetectionIndices.size(1) > 2147483646)) {
          f_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }
      }

      i1 = clusterInfo[cl].DetectionIndices.size(1);
      for (b_i = 0; b_i <= i1 - 2; b_i++) {
        r.set_size(&to_emlrtRTEI, &c_st, this->pDetections.size(0) *
                   this->pDetections.size(1));
        ncolx = this->pDetections.size(0) * this->pDetections.size(1);
        for (i2 = 0; i2 < ncolx; i2++) {
          r[i2] = this->pDetections[i2];
        }

        i2 = clusterInfo[cl].DetectionIndices.size(1);
        if ((b_i + 2 < 1) || (b_i + 2 > i2)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, i2, &ok_emlrtBCI, &c_st);
        }

        i2 = static_cast<int32_T>(clusterInfo[cl].DetectionIndices[b_i + 1]) - 1;
        if ((i2 < 0) || (i2 > r.size(0) - 1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 0, r.size(0) - 1, &ok_emlrtBCI,
            &c_st);
        }

        if ((b_i + 1 < 0) || (b_i + 1 > dets.size(0) - 1)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 0, dets.size(0) - 1,
            &pk_emlrtBCI, &c_st);
        }

        dets[b_i + 1] = r[i2];
      }

      i1 = clusterTrackId.size(1);
      for (nrows = 0; nrows < i1; nrows++) {
        if ((nrows + 1 < 1) || (nrows + 1 > clusterTrackId.size(1))) {
          emlrtDynamicBoundsCheckR2012b(nrows + 1, 1, clusterTrackId.size(1),
            &qk_emlrtBCI, &b_st);
        }

        track = this->pTracksList[static_cast<int32_T>(clusterTrackId[nrows]) -
          1];
        c_st.site = &aib_emlrtRSI;
        sorting.set_size(&uo_emlrtRTEI, &c_st, 1, clusterInfo[clusterInfo.size(0)
                         * cl].DetectionIndices.size(1));
        ntilerows = this->pDetectionTimes.size(1);
        ncolx = clusterInfo[cl].DetectionIndices.size(0) * clusterInfo[cl].
          DetectionIndices.size(1);
        for (i2 = 0; i2 < ncolx; i2++) {
          b_i = static_cast<int32_T>(clusterInfo[cl].DetectionIndices[i2]);
          if ((b_i < 1) || (b_i > ntilerows)) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, ntilerows, &rk_emlrtBCI, &c_st);
          }

          sorting[i2] = this->pDetectionTimes[b_i - 1];
        }

        d_st.site = &un_emlrtRSI;
        mtime = b_combineVectorElements(&d_st, sorting) / static_cast<real_T>
          (sorting.size(1));
        if (0 > dets.size(0) - 1) {
          emlrtDynamicBoundsCheckR2012b(0, 0, dets.size(0) - 1, &xj_emlrtBCI,
            &b_st);
        }

        c_st.site = &bib_emlrtRSI;
        dets[0].set_Time(&c_st, mtime);
        i2 = clusterInfo[cl].MarginalProbabilities.size(1);
        if ((nrows + 1 < 1) || (nrows + 1 > i2)) {
          emlrtDynamicBoundsCheckR2012b(nrows + 1, 1, i2, &wj_emlrtBCI, &b_st);
        }

        ncolx = clusterInfo[cl].MarginalProbabilities.size(0);
        b_clusterInfo.set_size(&vo_emlrtRTEI, &b_st,
          clusterInfo[clusterInfo.size(0) * cl].MarginalProbabilities.size(0));
        for (i2 = 0; i2 < ncolx; i2++) {
          b_clusterInfo[i2] = clusterInfo[cl].MarginalProbabilities[i2 +
            clusterInfo[cl].MarginalProbabilities.size(0) * nrows];
        }

        c_st.site = &cib_emlrtRSI;
        track->correctjpda(&c_st, dets, b_clusterInfo);
        if ((nrows + 1 < 1) || (nrows + 1 > clusterTrackId.size(1))) {
          emlrtDynamicBoundsCheckR2012b(nrows + 1, 1, clusterTrackId.size(1),
            &sk_emlrtBCI, &b_st);
        }

        this->pConfirmedTracks[static_cast<int32_T>(clusterTrackId[nrows]) - 1] =
          this->pTracksList[static_cast<int32_T>(clusterTrackId[nrows]) - 1]
          ->IsConfirmed;
      }
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::release()
  {
    if (this->isInitialized == 1) {
      this->isInitialized = 2;
      this->releaseWrapper();
    }
  }

  void trackerJPDA::releaseWrapper()
  {
    if (this->isSetupComplete) {
      this->pNumLiveTracks = 0.0;
      memset(&this->pTrackIDs[0], 0, 30U * sizeof(uint32_T));
      for (int32_T i = 0; i < 30; i++) {
        this->pConfirmedTracks[i] = false;
      }

      this->pLastTrackID = 0U;
      this->pLastTimeStamp = -2.2204460492503131E-16;
    }
  }

  void trackerJPDA::setup(const emlrtStack *sp, const ::coder::array<
    objectDetection, 2U> &varargin_1, real_T varargin_2, const int32_T
    varargin_3_size[2])
  {
    matlabshared::tracking::internal::fusion::ObjectTrack *tracks[30];
    matlabshared::tracking::internal::fusion::ObjectTrack track;
    objectDetection sampleDetection;
    trackHistoryLogic *trackLogic;
    trackingEKF f;
    trackingEKF lobj_1;
    trackingEKF *filter;
    array<int32_T, 2U> ii;
    array<boolean_T, 2U> b_z_data;
    array<boolean_T, 2U> d_z_data;
    array<boolean_T, 2U> e_z_data;
    array<boolean_T, 2U> f_z_data;
    cell_wrap_3 varSizes[3];
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack st;
    struct1_T hlb_emlrtRSI;
    real_T dv[9];
    real_T nFJE;
    int32_T X_idx_0;
    int32_T X_idx_2;
    int32_T XjL;
    int32_T idx;
    int32_T j;
    int8_T Xjs[4];
    int8_T ii_data[2];
    int8_T z_data[2];
    boolean_T x_data[6];
    boolean_T c_z_data[2];
    boolean_T exitg1;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    this->isSetupComplete = false;
    if (this->isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(sp, &wb_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    this->isInitialized = 1;
    st.site = &xr_emlrtRSI;
    varSizes[0].f1[0] = static_cast<uint32_T>(varargin_1.size(0));
    varSizes[0].f1[1] = 1U;
    for (j = 0; j < 6; j++) {
      varSizes[0].f1[j + 2] = 1U;
    }

    for (j = 0; j < 8; j++) {
      varSizes[1].f1[j] = 1U;
    }

    varSizes[2].f1[0] = static_cast<uint32_T>(varargin_3_size[0]);
    varSizes[2].f1[1] = static_cast<uint32_T>(varargin_3_size[1]);
    for (j = 0; j < 6; j++) {
      varSizes[2].f1[j + 2] = 1U;
    }

    this->inputVarSize[0] = varSizes[0];
    this->inputVarSize[1] = varSizes[1];
    this->inputVarSize[2] = varSizes[2];
    st.site = &xr_emlrtRSI;
    SystemCore::validateProperties();
    st.site = &xr_emlrtRSI;
    this->validateInputsImpl(&st, varargin_2);
    st.site = &xr_emlrtRSI;
    b_st.site = &bs_emlrtRSI;
    if (varargin_1.size(0) == 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &vb_emlrtRTEI,
        "fusion:trackerJPDA:UndefinedSampleDetection",
        "fusion:trackerJPDA:UndefinedSampleDetection", 0);
    } else {
      sampleDetection = varargin_1[0];
    }

    this->pSampleDetection = sampleDetection;
    sampleDetection = this->pSampleDetection;
    b_st.site = &fs_emlrtRSI;
    initializeEKF(&b_st, &sampleDetection, &f);
    b_st.site = &cs_emlrtRSI;
    XjL = 0;
    X_idx_0 = 0;
    X_idx_2 = 0;
    idx = 0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 2)) {
      idx++;
      ii_data[idx - 1] = static_cast<int8_T>(j + 1);
      if (idx >= 2) {
        exitg1 = true;
      } else {
        j++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    for (j = 0; j < idx; j++) {
      z_data[j] = static_cast<int8_T>(ii_data[j] - 1);
    }

    c_st.site = &su_emlrtRSI;
    for (j = 0; j < idx; j++) {
      c_z_data[j] = (z_data[j] > 0);
    }

    b_z_data.set(&c_z_data[0], 1, idx);
    d_st.site = &jf_emlrtRSI;
    b_eml_find(&d_st, b_z_data, ii);
    if (ii.size(1) == 0) {
      Xjs[0] = 0;
    } else {
      if (1 > ii.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ii.size(1), &bd_emlrtBCI, &b_st);
      }

      if ((ii[0] < 1) || (ii[0] > idx)) {
        emlrtDynamicBoundsCheckR2012b(ii[0], 1, idx, &cd_emlrtBCI, &b_st);
      }

      Xjs[0] = z_data[ii[0] - 1];
    }

    c_st.site = &su_emlrtRSI;
    if (0 <= idx - 1) {
      memset(&c_z_data[0], 0, idx * sizeof(boolean_T));
    }

    d_z_data.set(&c_z_data[0], 1, idx);
    d_st.site = &jf_emlrtRSI;
    b_eml_find(&d_st, d_z_data, ii);
    if (ii.size(1) == 0) {
      Xjs[2] = 0;
    } else {
      if (1 > ii.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ii.size(1), &bd_emlrtBCI, &b_st);
      }

      if ((ii[0] < 1) || (ii[0] > idx)) {
        emlrtDynamicBoundsCheckR2012b(ii[0], 1, idx, &cd_emlrtBCI, &b_st);
      }

      Xjs[2] = z_data[ii[0] - 1];
    }

    idx = 0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 2)) {
      idx++;
      ii_data[idx - 1] = static_cast<int8_T>(j + 1);
      if (idx >= 2) {
        exitg1 = true;
      } else {
        j++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    for (j = 0; j < idx; j++) {
      z_data[j] = static_cast<int8_T>(ii_data[j] - 1);
    }

    c_st.site = &su_emlrtRSI;
    for (j = 0; j < idx; j++) {
      c_z_data[j] = (z_data[j] > 0);
    }

    e_z_data.set(&c_z_data[0], 1, idx);
    d_st.site = &jf_emlrtRSI;
    b_eml_find(&d_st, e_z_data, ii);
    if (ii.size(1) == 0) {
      Xjs[1] = 0;
    } else {
      if (1 > ii.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ii.size(1), &bd_emlrtBCI, &b_st);
      }

      if ((ii[0] < 1) || (ii[0] > idx)) {
        emlrtDynamicBoundsCheckR2012b(ii[0], 1, idx, &cd_emlrtBCI, &b_st);
      }

      Xjs[1] = z_data[ii[0] - 1];
    }

    c_st.site = &su_emlrtRSI;
    if (0 <= idx - 1) {
      memset(&c_z_data[0], 0, idx * sizeof(boolean_T));
    }

    f_z_data.set(&c_z_data[0], 1, idx);
    d_st.site = &jf_emlrtRSI;
    b_eml_find(&d_st, f_z_data, ii);
    if (ii.size(1) == 0) {
      Xjs[3] = 0;
    } else {
      if (1 > ii.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ii.size(1), &bd_emlrtBCI, &b_st);
      }

      if ((ii[0] < 1) || (ii[0] > idx)) {
        emlrtDynamicBoundsCheckR2012b(ii[0], 1, idx, &cd_emlrtBCI, &b_st);
      }

      Xjs[3] = z_data[ii[0] - 1];
    }

    idx = 0;
    j = 1;
    nFJE = 1.0;
    while (j <= 2) {
      while ((idx < 1) && (j <= 2)) {
        if (j < 1) {
          emlrtDynamicBoundsCheckR2012b(j, 1, 2, &ad_emlrtBCI, &b_st);
        }

        if (static_cast<uint32_T>(Xjs[(j + (XjL << 1)) - 1]) == 0U) {
          XjL = 0;
          j = static_cast<int32_T>(j + 1U);
        } else {
          int32_T k;
          boolean_T y;
          XjL = 1;
          x_data[0] = (static_cast<uint32_T>(X_idx_2) == 1U);
          x_data[1] = false;
          y = false;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k <= 1)) {
            if (!x_data[k]) {
              k++;
            } else {
              y = true;
              exitg1 = true;
            }
          }

          if (!y) {
            idx = 1;
            X_idx_0 = j;
            X_idx_2 = 1;
            j = static_cast<int32_T>(j + 1U);
            nFJE++;
            if ((static_cast<int32_T>(nFJE) < 1) || (static_cast<int32_T>(nFJE) >
                 4)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nFJE), 1, 4,
                &dd_emlrtBCI, &b_st);
            }

            XjL = 0;
          }
        }
      }

      if (idx >= 1) {
        j = X_idx_0;
        XjL = X_idx_2;
        X_idx_0 = 0;
        X_idx_2 = 0;
        idx = 0;
      }
    }

    if ((static_cast<int32_T>(nFJE) < 1) || (static_cast<int32_T>(nFJE) > 4)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nFJE), 1, 4,
        &yc_emlrtBCI, &b_st);
    }

    b_st.site = &gs_emlrtRSI;
    c_st.site = &uu_emlrtRSI;
    trackLogic = this->_pobj3.init();
    this->pLogic = trackLogic;
    b_st.site = &ds_emlrtRSI;
    sampleDetection = this->pSampleDetection;
    trackLogic = this->pLogic;
    c_st.site = &yu_emlrtRSI;
    d_st.site = &ev_emlrtRSI;
    filter = initializeEKF(&d_st, &sampleDetection, &lobj_1);
    sampleDetection.get_MeasurementNoise(dv);
    d_st.site = &cv_emlrtRSI;
    filter->set_MeasurementNoise(&d_st, dv);
    track.init(filter, sampleDetection.ObjectClassID, trackLogic);
    c_st.site = &wu_emlrtRSI;
    track.nullify(&c_st);
    c_st.site = &av_emlrtRSI;
    tracks[0] = track.copy(&c_st, &this->_pobj2[0], &this->_pobj1[0],
      &this->_pobj0[0]);
    c_st.site = &av_emlrtRSI;
    tracks[1] = track.copy(&c_st, &this->_pobj2[1], &this->_pobj1[1],
      &this->_pobj0[1]);
    c_st.site = &av_emlrtRSI;
    tracks[2] = track.copy(&c_st, &this->_pobj2[2], &this->_pobj1[2],
      &this->_pobj0[2]);
    c_st.site = &av_emlrtRSI;
    tracks[3] = track.copy(&c_st, &this->_pobj2[3], &this->_pobj1[3],
      &this->_pobj0[3]);
    c_st.site = &av_emlrtRSI;
    tracks[4] = track.copy(&c_st, &this->_pobj2[4], &this->_pobj1[4],
      &this->_pobj0[4]);
    c_st.site = &av_emlrtRSI;
    tracks[5] = track.copy(&c_st, &this->_pobj2[5], &this->_pobj1[5],
      &this->_pobj0[5]);
    c_st.site = &av_emlrtRSI;
    tracks[6] = track.copy(&c_st, &this->_pobj2[6], &this->_pobj1[6],
      &this->_pobj0[6]);
    c_st.site = &av_emlrtRSI;
    tracks[7] = track.copy(&c_st, &this->_pobj2[7], &this->_pobj1[7],
      &this->_pobj0[7]);
    c_st.site = &av_emlrtRSI;
    tracks[8] = track.copy(&c_st, &this->_pobj2[8], &this->_pobj1[8],
      &this->_pobj0[8]);
    c_st.site = &av_emlrtRSI;
    tracks[9] = track.copy(&c_st, &this->_pobj2[9], &this->_pobj1[9],
      &this->_pobj0[9]);
    c_st.site = &av_emlrtRSI;
    tracks[10] = track.copy(&c_st, &this->_pobj2[10], &this->_pobj1[10],
      &this->_pobj0[10]);
    c_st.site = &av_emlrtRSI;
    tracks[11] = track.copy(&c_st, &this->_pobj2[11], &this->_pobj1[11],
      &this->_pobj0[11]);
    c_st.site = &av_emlrtRSI;
    tracks[12] = track.copy(&c_st, &this->_pobj2[12], &this->_pobj1[12],
      &this->_pobj0[12]);
    c_st.site = &av_emlrtRSI;
    tracks[13] = track.copy(&c_st, &this->_pobj2[13], &this->_pobj1[13],
      &this->_pobj0[13]);
    c_st.site = &av_emlrtRSI;
    tracks[14] = track.copy(&c_st, &this->_pobj2[14], &this->_pobj1[14],
      &this->_pobj0[14]);
    c_st.site = &av_emlrtRSI;
    tracks[15] = track.copy(&c_st, &this->_pobj2[15], &this->_pobj1[15],
      &this->_pobj0[15]);
    c_st.site = &av_emlrtRSI;
    tracks[16] = track.copy(&c_st, &this->_pobj2[16], &this->_pobj1[16],
      &this->_pobj0[16]);
    c_st.site = &av_emlrtRSI;
    tracks[17] = track.copy(&c_st, &this->_pobj2[17], &this->_pobj1[17],
      &this->_pobj0[17]);
    c_st.site = &av_emlrtRSI;
    tracks[18] = track.copy(&c_st, &this->_pobj2[18], &this->_pobj1[18],
      &this->_pobj0[18]);
    c_st.site = &av_emlrtRSI;
    tracks[19] = track.copy(&c_st, &this->_pobj2[19], &this->_pobj1[19],
      &this->_pobj0[19]);
    c_st.site = &av_emlrtRSI;
    tracks[20] = track.copy(&c_st, &this->_pobj2[20], &this->_pobj1[20],
      &this->_pobj0[20]);
    c_st.site = &av_emlrtRSI;
    tracks[21] = track.copy(&c_st, &this->_pobj2[21], &this->_pobj1[21],
      &this->_pobj0[21]);
    c_st.site = &av_emlrtRSI;
    tracks[22] = track.copy(&c_st, &this->_pobj2[22], &this->_pobj1[22],
      &this->_pobj0[22]);
    c_st.site = &av_emlrtRSI;
    tracks[23] = track.copy(&c_st, &this->_pobj2[23], &this->_pobj1[23],
      &this->_pobj0[23]);
    c_st.site = &av_emlrtRSI;
    tracks[24] = track.copy(&c_st, &this->_pobj2[24], &this->_pobj1[24],
      &this->_pobj0[24]);
    c_st.site = &av_emlrtRSI;
    tracks[25] = track.copy(&c_st, &this->_pobj2[25], &this->_pobj1[25],
      &this->_pobj0[25]);
    c_st.site = &av_emlrtRSI;
    tracks[26] = track.copy(&c_st, &this->_pobj2[26], &this->_pobj1[26],
      &this->_pobj0[26]);
    c_st.site = &av_emlrtRSI;
    tracks[27] = track.copy(&c_st, &this->_pobj2[27], &this->_pobj1[27],
      &this->_pobj0[27]);
    c_st.site = &av_emlrtRSI;
    tracks[28] = track.copy(&c_st, &this->_pobj2[28], &this->_pobj1[28],
      &this->_pobj0[28]);
    c_st.site = &av_emlrtRSI;
    tracks[29] = track.copy(&c_st, &this->_pobj2[29], &this->_pobj1[29],
      &this->_pobj0[29]);
    for (j = 0; j < 30; j++) {
      this->pTracksList[j] = tracks[j];
    }

    c_st.site = &xu_emlrtRSI;
    track.trackToStruct(&c_st, &hlb_emlrtRSI);
    c_st.site = &bv_emlrtRSI;
    this->pDistFilter = this->pTracksList[0]->Filter->clone(&this->_pobj0[30]);
    this->pClusterTypeDef.SensorIndex = 0U;
    this->pClusterTypeDef.TimeStamp = 0.0;
    for (idx = 0; idx < 30; idx++) {
      this->pTrackDetectionProbability[idx] = 0.9;
    }

    b_st.site = &es_emlrtRSI;
    this->cCostCalculator.init();
    this->isSetupComplete = true;
    this->TunablePropsChanged = false;
    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::setupAndReset(const emlrtStack *sp, const ::coder::array<
    objectDetection, 2U> &varargin_1, real_T varargin_2, const int32_T
    varargin_3_size[2])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T i;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &wr_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    this->setup(&st, varargin_1, varargin_2, varargin_3_size);
    st.site = &wr_emlrtRSI;
    b_st.site = &kx_emlrtRSI;
    for (i = 0; i < 30; i++) {
      c_st.site = &lx_emlrtRSI;
      this->pTracksList[i]->nullify(&c_st);
    }

    this->pNumLiveTracks = 0.0;
    for (i = 0; i < 30; i++) {
      this->pTrackIDs[i] = 0U;
    }

    for (i = 0; i < 30; i++) {
      this->pConfirmedTracks[i] = false;
    }

    this->pDetections.set_size(&oi_emlrtRTEI, &st, 1, 1);
    this->pLastTimeStamp = -2.2204460492503131E-16;
    this->pOriginatingSensor.set_size(&pi_emlrtRTEI, &st, 1, 0);
    this->pCostMatrix.set_size(&qi_emlrtRTEI, &st, 0, 0);
    this->pDetectionTimes.set_size(&ri_emlrtRTEI, &st, 1, 0);
    this->pLastTrackID = 0U;
    for (i = 0; i < 30; i++) {
      this->pWasDetectable[i] = true;
    }
  }

  void trackerJPDA::trackDetectability(const emlrtStack *sp, const real_T
    varargin_2_data[], const int32_T varargin_2_size[2])
  {
    emlrtStack b_st;
    emlrtStack st;
    real_T varargin_2;
    int32_T ind_size[2];
    int32_T ind_data[1];
    int32_T i;
    int32_T loop_ub;
    boolean_T b_varargin_2[30];
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    for (i = 0; i < 30; i++) {
      this->pTrackDetectionProbability[i] = 0.9;
    }

    varargin_2 = this->pNumLiveTracks;
    if (1.0 > varargin_2) {
      loop_ub = 0;
    } else {
      if (varargin_2 != static_cast<int32_T>(muDoubleScalarFloor(varargin_2))) {
        emlrtIntegerCheckR2012b(varargin_2, &o_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(varargin_2) < 1) || (static_cast<int32_T>
           (varargin_2) > 30)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(varargin_2), 1, 30,
          &ed_emlrtBCI, sp);
      }

      loop_ub = static_cast<int32_T>(varargin_2);
    }

    if (0 <= loop_ub - 1) {
      memset(&this->pWasDetectable[0], 0, loop_ub * sizeof(boolean_T));
    }

    if ((varargin_2_size[0] << 1) > 0) {
      int32_T b_i;
      boolean_T exitg1;
      boolean_T p;
      st.site = &dy_emlrtRSI;
      b_st.site = &yb_emlrtRSI;
      p = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= varargin_2_size[0] - 1)) {
        if (!(varargin_2_data[loop_ub] <= 0.0)) {
          loop_ub++;
        } else {
          p = false;
          exitg1 = true;
        }
      }

      if (!p) {
        emlrtErrorWithMessageIdR2018a(&b_st, &y_emlrtRTEI,
          "Coder:toolbox:ValidateattributesexpectedPositive",
          "MATLAB:step:expectedPositive", 3, 4, 18, "detectableTrackIDs");
      }

      b_st.site = &yb_emlrtRSI;
      p = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= varargin_2_size[0] - 1)) {
        if ((!muDoubleScalarIsInf(varargin_2_data[loop_ub])) &&
            (!muDoubleScalarIsNaN(varargin_2_data[loop_ub])) &&
            (muDoubleScalarFloor(varargin_2_data[loop_ub]) ==
             varargin_2_data[loop_ub])) {
          loop_ub++;
        } else {
          p = false;
          exitg1 = true;
        }
      }

      if (!p) {
        emlrtErrorWithMessageIdR2018a(&b_st, &s_emlrtRTEI,
          "Coder:toolbox:ValidateattributesexpectedInteger",
          "MATLAB:step:expectedInteger", 3, 4, 18, "detectableTrackIDs");
      }

      st.site = &ey_emlrtRSI;
      b_st.site = &yb_emlrtRSI;
      p = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= varargin_2_size[0] - 1)) {
        if (!(varargin_2_data[loop_ub + varargin_2_size[0]] < 0.0)) {
          loop_ub++;
        } else {
          p = false;
          exitg1 = true;
        }
      }

      if (!p) {
        emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI,
          "Coder:toolbox:ValidateattributesexpectedNonnegative",
          "MATLAB:step:expectedNonnegative", 3, 4, 20, "detectionProbability");
      }

      b_st.site = &yb_emlrtRSI;
      p = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= varargin_2_size[0] - 1)) {
        if (varargin_2_data[loop_ub + varargin_2_size[0]] < 1.0) {
          loop_ub++;
        } else {
          p = false;
          exitg1 = true;
        }
      }

      if (!p) {
        emlrtErrorWithMessageIdR2018a(&b_st, &dc_emlrtRTEI,
          "MATLAB:validateattributes:expectedArray", "MATLAB:step:notLess", 9, 4,
          20, "detectionProbability", 4, 1, "<", 4, 1, "1");
      }

      b_i = varargin_2_size[0] - 1;
      for (i = 0; i <= b_i; i++) {
        int32_T i1;
        st.site = &fy_emlrtRSI;
        i1 = i + 1;
        if ((i1 < 1) || (i1 > varargin_2_size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, varargin_2_size[0], &fd_emlrtBCI,
            &st);
        }

        varargin_2 = varargin_2_data[i];
        for (i1 = 0; i1 < 30; i1++) {
          b_varargin_2[i1] = (varargin_2 == this->pTrackIDs[i1]);
        }

        c_eml_find(b_varargin_2, ind_data, ind_size);
        if (ind_size[1] != 0) {
          loop_ub = ind_size[0] * ind_size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            this->pWasDetectable[ind_data[i1] - 1] = true;
          }

          loop_ub = ind_size[0] * ind_size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            if ((i + 1 < 1) || (i + 1 > varargin_2_size[0])) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, varargin_2_size[0],
                &gd_emlrtBCI, sp);
            }

            this->pTrackDetectionProbability[ind_data[i1] - 1] =
              varargin_2_data[i + varargin_2_size[0]];
          }
        }
      }
    }
  }

  void trackerJPDA::validateClusterDetectionsTime(const emlrtStack *sp, const ::
    coder::array<real_T, 2U> &detIndices) const
  {
    array<real_T, 2U> varargin_1;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack g_st;
    emlrtStack h_st;
    emlrtStack i_st;
    emlrtStack st;
    real_T d;
    real_T maxTime;
    real_T minTime;
    int32_T a;
    int32_T idx;
    int32_T k;
    int32_T n;
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
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &lfb_emlrtRSI;
    varargin_1.set_size(&ml_emlrtRTEI, &st, 1, detIndices.size(1));
    n = this->pDetectionTimes.size(1);
    idx = detIndices.size(0) * detIndices.size(1);
    for (k = 0; k < idx; k++) {
      a = static_cast<int32_T>(detIndices[k]);
      if ((a < 1) || (a > n)) {
        emlrtDynamicBoundsCheckR2012b(a, 1, n, &xf_emlrtBCI, &st);
      }

      varargin_1[k] = this->pDetectionTimes[a - 1];
    }

    b_st.site = &md_emlrtRSI;
    c_st.site = &nd_emlrtRSI;
    d_st.site = &od_emlrtRSI;
    if (varargin_1.size(1) < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &pd_emlrtRSI;
    f_st.site = &qd_emlrtRSI;
    n = varargin_1.size(1);
    if (varargin_1.size(1) <= 2) {
      if (varargin_1.size(1) == 1) {
        maxTime = varargin_1[0];
      } else if ((varargin_1[0] < varargin_1[1]) || (muDoubleScalarIsNaN
                  (varargin_1[0]) && (!muDoubleScalarIsNaN(varargin_1[1])))) {
        maxTime = varargin_1[1];
      } else {
        maxTime = varargin_1[0];
      }
    } else {
      g_st.site = &vn_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &wn_emlrtRSI;
        if (varargin_1.size(1) > 2147483646) {
          i_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= varargin_1.size(1))) {
          if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        maxTime = varargin_1[0];
      } else {
        g_st.site = &rd_emlrtRSI;
        maxTime = varargin_1[idx - 1];
        a = idx + 1;
        h_st.site = &sd_emlrtRSI;
        if ((idx + 1 <= varargin_1.size(1)) && (varargin_1.size(1) > 2147483646))
        {
          i_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        for (k = a; k <= n; k++) {
          d = varargin_1[k - 1];
          if (maxTime < d) {
            maxTime = d;
          }
        }
      }
    }

    st.site = &mfb_emlrtRSI;
    varargin_1.set_size(&nl_emlrtRTEI, &st, 1, detIndices.size(1));
    n = this->pDetectionTimes.size(1);
    idx = detIndices.size(0) * detIndices.size(1);
    for (k = 0; k < idx; k++) {
      a = static_cast<int32_T>(detIndices[k]);
      if ((a < 1) || (a > n)) {
        emlrtDynamicBoundsCheckR2012b(a, 1, n, &yf_emlrtBCI, &st);
      }

      varargin_1[k] = this->pDetectionTimes[a - 1];
    }

    b_st.site = &td_emlrtRSI;
    c_st.site = &ud_emlrtRSI;
    d_st.site = &vd_emlrtRSI;
    if (varargin_1.size(1) < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &wd_emlrtRSI;
    f_st.site = &xd_emlrtRSI;
    n = varargin_1.size(1);
    if (varargin_1.size(1) <= 2) {
      if (varargin_1.size(1) == 1) {
        minTime = varargin_1[0];
      } else if ((varargin_1[0] > varargin_1[1]) || (muDoubleScalarIsNaN
                  (varargin_1[0]) && (!muDoubleScalarIsNaN(varargin_1[1])))) {
        minTime = varargin_1[1];
      } else {
        minTime = varargin_1[0];
      }
    } else {
      g_st.site = &vn_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &wn_emlrtRSI;
        if (varargin_1.size(1) > 2147483646) {
          i_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= varargin_1.size(1))) {
          if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        minTime = varargin_1[0];
      } else {
        g_st.site = &rd_emlrtRSI;
        minTime = varargin_1[idx - 1];
        a = idx + 1;
        h_st.site = &sd_emlrtRSI;
        if ((idx + 1 <= varargin_1.size(1)) && (varargin_1.size(1) > 2147483646))
        {
          i_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        for (k = a; k <= n; k++) {
          d = varargin_1[k - 1];
          if (minTime > d) {
            minTime = d;
          }
        }
      }
    }

    if (1 > detIndices.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, detIndices.size(1), &wf_emlrtBCI, sp);
    }

    k = this->pOriginatingSensor.size(1);
    a = static_cast<int32_T>(detIndices[0]);
    if ((a < 1) || (a > k)) {
      emlrtDynamicBoundsCheckR2012b(a, 1, k, &vf_emlrtBCI, sp);
    }

    if (maxTime - minTime > 1.0E-5) {
      emlrtErrorWithMessageIdR2018a(sp, &nc_emlrtRTEI,
        "fusion:trackerJPDA:SensorTimeTolerance",
        "fusion:trackerJPDA:SensorTimeTolerance", 5, 6, this->
        pOriginatingSensor[static_cast<int32_T>(detIndices[0]) - 1], 4, 13,
        "TimeTolerance");
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void trackerJPDA::validateInputsImpl(const emlrtStack *sp, real_T varargin_1)
    const
  {
    emlrtStack b_st;
    emlrtStack st;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &as_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    b_st.site = &yb_emlrtRSI;
    p = ((!muDoubleScalarIsInf(varargin_1)) && (!muDoubleScalarIsNaN(varargin_1)));
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:step:expectedFinite", 3, 4, 4, "time");
    }

    b_st.site = &yb_emlrtRSI;
    p = !(varargin_1 < 0.0);
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:step:expectedNonnegative", 3, 4, 4, "time");
    }

    if (varargin_1 <= this->pLastTimeStamp) {
      emlrtErrorWithMessageIdR2018a(sp, &xb_emlrtRTEI,
        "fusion:trackerJPDA:TimeMustIncrease",
        "fusion:trackerJPDA:TimeMustIncrease", 3, 4, 4, "step");
    }
  }
}

static void cast(const emlrtStack *sp, const coder::array<b_struct_T, 2U> &b,
                 coder::array<struct_T, 2U> &c)
{
  int32_T i;
  c.set_size(&un_emlrtRTEI, sp, 1, b.size(1));
  i = b.size(1) - 1;
  for (int32_T i1 = 0; i1 <= i; i1++) {
    c[c.size(0) * i1].DetectionIndices.set_size(&un_emlrtRTEI, sp, 1, 0);
    c[c.size(0) * i1].TrackIDs.set_size(&un_emlrtRTEI, sp, 1, 0);
    c[c.size(0) * i1].ValidationMatrix.set_size(&un_emlrtRTEI, sp, 0, 0);
    c[i1].SensorIndex = b[i1].SensorIndex;
    c[i1].TimeStamp = b[i1].TimeStamp;
    c[c.size(0) * i1].MarginalProbabilities.set_size(&un_emlrtRTEI, sp, 0, 0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

namespace coder
{
  trackerJPDA::trackerJPDA()
  {
    this->matlabCodegenIsDeleted = true;
  }

  trackerJPDA::~trackerJPDA()
  {
    if (!this->matlabCodegenIsDeleted) {
      emlrtSetIsInDestructor(emlrtRootTLSGlobal, true);
      try {
        this->matlabCodegenDestructor();
      } catch (...) {
      }

      emlrtSetIsInDestructor(emlrtRootTLSGlobal, false);
    }
  }

  trackerJPDA *trackerJPDA::init(const emlrtStack *sp)
  {
    trackerJPDA *obj;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    obj = this;
    obj->isInitialized = 0;
    obj->pLastTimeStamp = -2.2204460492503131E-16;
    obj->matlabCodegenIsDeleted = false;
    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    return obj;
  }

  void trackerJPDA::matlabCodegenDestructor()
  {
    if (!this->matlabCodegenIsDeleted) {
      this->matlabCodegenIsDeleted = true;
      this->release();
    }
  }

  void trackerJPDA::step(const emlrtStack *sp, const ::coder::array<
    objectDetection, 2U> &varargin_1, real_T varargin_2, const real_T
    varargin_3_data[], const int32_T varargin_3_size[2], struct1_T
    varargout_1_data[], int32_T varargout_1_size[1], struct1_T varargout_2_data[],
    int32_T varargout_2_size[1], ::coder::array<struct1_T, 2U> &varargout_3)
  {
    matlabshared::tracking::internal::fusion::ObjectTrack *track;
    array<objectDetection, 1U> r;
    array<struct_T, 2U> clusterInfo;
    array<real_T, 2U> b_a;
    array<real_T, 2U> ilb_emlrtRSI;
    array<real_T, 2U> unassignedTrackId;
    bounded_array<uint32_T, 30U, 2U> hlb_emlrtRSI;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack g_st;
    emlrtStack h_st;
    emlrtStack i_st;
    emlrtStack j_st;
    emlrtStack st;
    real_T d;
    int32_T a;
    int32_T i;
    int32_T idx;
    int32_T k;
    int32_T n;
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
    j_st.prev = &i_st;
    j_st.tls = i_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    if (this->isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(sp, &ub_emlrtRTEI,
        "MATLAB:system:methodCalledWhenReleasedCodegen",
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
    }

    if (this->isInitialized != 1) {
      st.site = &vr_emlrtRSI;
      this->setupAndReset(&st, varargin_1, varargin_2, varargin_3_size);
    }

    st.site = &vr_emlrtRSI;
    this->checkTunableProps();
    st.site = &vr_emlrtRSI;
    anyInputSizeChanged = false;
    inSize[0] = static_cast<uint32_T>(varargin_1.size(0));
    inSize[1] = 1U;
    for (i = 0; i < 6; i++) {
      inSize[i + 2] = 1U;
    }

    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (this->inputVarSize[0].f1[k] != inSize[k]) {
        anyInputSizeChanged = true;
        for (i = 0; i < 8; i++) {
          this->inputVarSize[0].f1[i] = inSize[i];
        }

        exitg1 = true;
      } else {
        k++;
      }
    }

    inSize[0] = static_cast<uint32_T>(varargin_3_size[0]);
    inSize[1] = static_cast<uint32_T>(varargin_3_size[1]);
    for (i = 0; i < 6; i++) {
      inSize[i + 2] = 1U;
    }

    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (this->inputVarSize[2].f1[k] != static_cast<uint32_T>(static_cast<
           int8_T>(inSize[k]))) {
        anyInputSizeChanged = true;
        for (i = 0; i < 8; i++) {
          this->inputVarSize[2].f1[i] = inSize[i];
        }

        exitg1 = true;
      } else {
        k++;
      }
    }

    if (anyInputSizeChanged) {
      st.site = &vr_emlrtRSI;
      this->validateInputsImpl(&st, varargin_2);
    }

    st.site = &vr_emlrtRSI;
    if (varargin_2 <= this->pLastTimeStamp) {
      emlrtErrorWithMessageIdR2018a(&st, &tb_emlrtRTEI,
        "fusion:trackerJPDA:TimeMustIncrease",
        "fusion:trackerJPDA:TimeMustIncrease", 3, 4, 4, "step");
    }

    d = this->pNumLiveTracks;
    if (1.0 > d) {
      i = 0;
    } else {
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &i_emlrtDCI, &st);
      }

      if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) > 30)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, 30,
          &kc_emlrtBCI, &st);
      }

      i = static_cast<int32_T>(d);
    }

    b_st.site = &nx_emlrtRSI;
    if (!(this->pNumLiveTracks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(this->pNumLiveTracks, &k_emlrtDCI, &b_st);
    }

    d = this->pNumLiveTracks;
    if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
      emlrtIntegerCheckR2012b(d, &j_emlrtDCI, &b_st);
    }

    this->pCostMatrix.set_size(&xh_emlrtRTEI, &b_st, static_cast<int32_T>(d),
      varargin_1.size(0));
    if (!(this->pNumLiveTracks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(this->pNumLiveTracks, &m_emlrtDCI, &b_st);
    }

    d = this->pNumLiveTracks;
    if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
      emlrtIntegerCheckR2012b(d, &l_emlrtDCI, &b_st);
    }

    n = static_cast<int32_T>(d) * varargin_1.size(0);
    for (a = 0; a < n; a++) {
      this->pCostMatrix[a] = 0.0;
    }

    if (varargin_1.size(0) == 0) {
      this->pDetections.set_size(&hi_emlrtRTEI, &b_st, 0, 0);
      this->pOriginatingSensor.set_size(&ii_emlrtRTEI, &b_st, 1, 0);
      this->pDetectionTimes.set_size(&ji_emlrtRTEI, &b_st, 1, 0);
    } else {
      this->pDetections.set_size(&yh_emlrtRTEI, &b_st, varargin_1.size(0), 1);
      n = varargin_1.size(0) * varargin_1.size(1);
      for (a = 0; a < n; a++) {
        this->pDetections[a] = varargin_1[a];
      }

      this->pOriginatingSensor.set_size(&ai_emlrtRTEI, &b_st, 1, varargin_1.size
        (0));
      n = varargin_1.size(0);
      for (a = 0; a < n; a++) {
        this->pOriginatingSensor[a] = 0.0;
      }

      this->pDetectionTimes.set_size(&bi_emlrtRTEI, &b_st, 1, varargin_1.size(0));
      n = varargin_1.size(0);
      for (a = 0; a < n; a++) {
        this->pDetectionTimes[a] = 0.0;
      }

      a = varargin_1.size(0);
      for (idx = 0; idx < a; idx++) {
        boolean_T guard1 = false;
        r.set_size(&ci_emlrtRTEI, &b_st, this->pDetections.size(0) *
                   this->pDetections.size(1));
        n = this->pDetections.size(0) * this->pDetections.size(1);
        for (k = 0; k < n; k++) {
          r[k] = this->pDetections[k];
        }

        if (idx > r.size(0) - 1) {
          emlrtDynamicBoundsCheckR2012b(idx, 0, r.size(0) - 1, &lc_emlrtBCI,
            &b_st);
        }

        guard1 = false;
        if (r[idx].Time <= this->pLastTimeStamp) {
          guard1 = true;
        } else {
          r.set_size(&di_emlrtRTEI, &b_st, this->pDetections.size(0) *
                     this->pDetections.size(1));
          n = this->pDetections.size(0) * this->pDetections.size(1);
          for (k = 0; k < n; k++) {
            r[k] = this->pDetections[k];
          }

          if (idx > r.size(0) - 1) {
            emlrtDynamicBoundsCheckR2012b(idx, 0, r.size(0) - 1, &mc_emlrtBCI,
              &b_st);
          }

          if (r[idx].Time > varargin_2 + 1.0E-5) {
            guard1 = true;
          }
        }

        if (guard1) {
          emlrtErrorWithMessageIdR2018a(&b_st, &sb_emlrtRTEI,
            "fusion:trackerJPDA:DetectionTimeMismatch",
            "fusion:trackerJPDA:DetectionTimeMismatch", 3, 4, 12, "updateTracks");
        }

        r.set_size(&ei_emlrtRTEI, &b_st, this->pDetections.size(0) *
                   this->pDetections.size(1));
        n = this->pDetections.size(0) * this->pDetections.size(1);
        for (k = 0; k < n; k++) {
          r[k] = this->pDetections[k];
        }

        if (idx > r.size(0) - 1) {
          emlrtDynamicBoundsCheckR2012b(idx, 0, r.size(0) - 1, &oc_emlrtBCI,
            &b_st);
        }

        k = this->pDetectionTimes.size(1);
        if ((idx + 1 < 1) || (idx + 1 > k)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, k, &pc_emlrtBCI, &b_st);
        }

        this->pDetectionTimes[idx] = r[idx].Time;
        r.set_size(&fi_emlrtRTEI, &b_st, this->pDetections.size(0) *
                   this->pDetections.size(1));
        n = this->pDetections.size(0) * this->pDetections.size(1);
        for (k = 0; k < n; k++) {
          r[k] = this->pDetections[k];
        }

        if (idx > r.size(0) - 1) {
          emlrtDynamicBoundsCheckR2012b(idx, 0, r.size(0) - 1, &sc_emlrtBCI,
            &b_st);
        }

        k = this->pOriginatingSensor.size(1);
        if ((idx + 1 < 1) || (idx + 1 > k)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, k, &tc_emlrtBCI, &b_st);
        }

        this->pOriginatingSensor[idx] = r[idx].SensorIndex;
      }

      c_st.site = &yx_emlrtRSI;
      b_a.set_size(&gi_emlrtRTEI, &c_st, 1, this->pOriginatingSensor.size(1));
      n = this->pOriginatingSensor.size(0) * this->pOriginatingSensor.size(1);
      for (a = 0; a < n; a++) {
        b_a[a] = this->pOriginatingSensor[a];
      }

      d_st.site = &gn_emlrtRSI;
      unique_vector(&d_st, b_a, ilb_emlrtRSI);
    }

    b_st.site = &ox_emlrtRSI;
    this->trackDetectability(&b_st, varargin_3_data, varargin_3_size);
    if (varargin_1.size(0) != 0) {
      real_T tmin;
      b_st.site = &px_emlrtRSI;
      b_a.set_size(&ki_emlrtRTEI, &b_st, 1, this->pDetectionTimes.size(1));
      n = this->pDetectionTimes.size(0) * this->pDetectionTimes.size(1);
      for (a = 0; a < n; a++) {
        b_a[a] = this->pDetectionTimes[a];
      }

      c_st.site = &td_emlrtRSI;
      d_st.site = &ud_emlrtRSI;
      e_st.site = &vd_emlrtRSI;
      if (b_a.size(1) < 1) {
        emlrtErrorWithMessageIdR2018a(&e_st, &jb_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      f_st.site = &wd_emlrtRSI;
      g_st.site = &xd_emlrtRSI;
      n = b_a.size(1);
      if (b_a.size(1) <= 2) {
        if (b_a.size(1) == 1) {
          tmin = b_a[0];
        } else if ((b_a[0] > b_a[1]) || (muDoubleScalarIsNaN(b_a[0]) &&
                    (!muDoubleScalarIsNaN(b_a[1])))) {
          tmin = b_a[1];
        } else {
          tmin = b_a[0];
        }
      } else {
        h_st.site = &vn_emlrtRSI;
        if (!muDoubleScalarIsNaN(b_a[0])) {
          idx = 1;
        } else {
          idx = 0;
          i_st.site = &wn_emlrtRSI;
          if (b_a.size(1) > 2147483646) {
            j_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&j_st);
          }

          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= b_a.size(1))) {
            if (!muDoubleScalarIsNaN(b_a[k - 1])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }

        if (idx == 0) {
          tmin = b_a[0];
        } else {
          h_st.site = &rd_emlrtRSI;
          tmin = b_a[idx - 1];
          a = idx + 1;
          i_st.site = &sd_emlrtRSI;
          if ((idx + 1 <= b_a.size(1)) && (b_a.size(1) > 2147483646)) {
            j_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&j_st);
          }

          for (k = a; k <= n; k++) {
            d = b_a[k - 1];
            if (tmin > d) {
              tmin = d;
            }
          }
        }
      }

      b_st.site = &qx_emlrtRSI;
      if (tmin > this->pLastTimeStamp) {
        d = this->pNumLiveTracks;
        a = static_cast<int32_T>(d);
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, d, mxDOUBLE_CLASS, static_cast<
          int32_T>(d), &rb_emlrtRTEI, &b_st);
        for (idx = 0; idx < a; idx++) {
          if (idx > 29) {
            emlrtDynamicBoundsCheckR2012b(idx, 0, 29, &nc_emlrtBCI, &b_st);
          }

          track = this->pTracksList[idx];
          if (tmin > track->Time) {
            c_st.site = &gy_emlrtRSI;
            track->predict(&c_st, tmin);
          }
        }
      }

      this->pLastTimeStamp = tmin;
    } else {
      b_st.site = &rx_emlrtRSI;
      if (varargin_2 > this->pLastTimeStamp) {
        d = this->pNumLiveTracks;
        a = static_cast<int32_T>(d);
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, d, mxDOUBLE_CLASS, static_cast<
          int32_T>(d), &rb_emlrtRTEI, &b_st);
        for (idx = 0; idx < a; idx++) {
          if (idx > 29) {
            emlrtDynamicBoundsCheckR2012b(idx, 0, 29, &nc_emlrtBCI, &b_st);
          }

          track = this->pTracksList[idx];
          if (varargin_2 > track->Time) {
            c_st.site = &gy_emlrtRSI;
            track->predict(&c_st, varargin_2);
          }
        }
      }

      this->pLastTimeStamp = varargin_2;
    }

    b_st.site = &sx_emlrtRSI;
    this->clusterAssignUpdate(&b_st, b_a, unassignedTrackId, clusterInfo);
    b_st.site = &tx_emlrtRSI;
    this->initializeTracks(&b_st, b_a, hlb_emlrtRSI.data, hlb_emlrtRSI.size);
    b_st.site = &ux_emlrtRSI;
    a = unassignedTrackId.size(1);
    for (n = 0; n < a; n++) {
      if ((n + 1 < 1) || (n + 1 > unassignedTrackId.size(1))) {
        emlrtDynamicBoundsCheckR2012b(n + 1, 1, unassignedTrackId.size(1),
          &rc_emlrtBCI, &b_st);
      }

      k = static_cast<int32_T>(unassignedTrackId[n]);
      if ((k < 1) || (k > 30)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, 30, &qc_emlrtBCI, &b_st);
      }

      if (this->pWasDetectable[k - 1]) {
        if ((n + 1 < 1) || (n + 1 > unassignedTrackId.size(1))) {
          emlrtDynamicBoundsCheckR2012b(n + 1, 1, unassignedTrackId.size(1),
            &uc_emlrtBCI, &b_st);
        }

        k = static_cast<int32_T>(unassignedTrackId[n]);
        if ((k < 1) || (k > 30)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, 30, &ic_emlrtBCI, &b_st);
        }

        if ((n + 1 < 1) || (n + 1 > unassignedTrackId.size(1))) {
          emlrtDynamicBoundsCheckR2012b(n + 1, 1, unassignedTrackId.size(1),
            &wc_emlrtBCI, &b_st);
        }

        k = static_cast<int32_T>(unassignedTrackId[n]) - 1;
        if ((k < 0) || (k > 29)) {
          emlrtDynamicBoundsCheckR2012b(k, 0, 29, &vc_emlrtBCI, &b_st);
        }

        c_st.site = &bkb_emlrtRSI;
        this->pTracksList[k]->updateNotAssociated(&c_st);
      }
    }

    b_st.site = &vx_emlrtRSI;
    if (varargin_2 > this->pLastTimeStamp) {
      d = this->pNumLiveTracks;
      a = static_cast<int32_T>(d);
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, d, mxDOUBLE_CLASS,
        static_cast<int32_T>(d), &rb_emlrtRTEI, &b_st);
      for (idx = 0; idx < a; idx++) {
        if (idx > 29) {
          emlrtDynamicBoundsCheckR2012b(idx, 0, 29, &nc_emlrtBCI, &b_st);
        }

        track = this->pTracksList[idx];
        if (varargin_2 > track->Time) {
          c_st.site = &gy_emlrtRSI;
          track->predict(&c_st, varargin_2);
        }
      }
    }

    b_st.site = &wx_emlrtRSI;
    this->deleteOldTracks(&b_st, hlb_emlrtRSI.data, hlb_emlrtRSI.size);
    if (unassignedTrackId.size(1) != 0) {
      n = unassignedTrackId.size(0) * unassignedTrackId.size(1);
      for (a = 0; a < n; a++) {
        k = static_cast<int32_T>(unassignedTrackId[a]);
        if ((k < 1) || (k > static_cast<int8_T>(i))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, static_cast<int32_T>(static_cast<
            int8_T>(i)), &xc_emlrtBCI, &st);
        }
      }
    }

    d = this->pNumLiveTracks;
    if (!(1.0 > d)) {
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &h_emlrtDCI, &st);
      }

      if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) > 30)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, 30,
          &jc_emlrtBCI, &st);
      }
    }

    b_st.site = &xx_emlrtRSI;
    this->formatTrackOutputs(&b_st, varargout_1_data, varargout_1_size,
      varargout_2_data, varargout_2_size, varargout_3);
    this->pDetections.set_size(&li_emlrtRTEI, &st, 0, 0);
    this->pOriginatingSensor.set_size(&mi_emlrtRTEI, &st, 1, 0);
    this->pDetectionTimes.set_size(&ni_emlrtRTEI, &st, 1, 0);
    this->pLastTimeStamp = varargin_2;
    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }
}

// End of code generation (trackerJPDA.cpp)
