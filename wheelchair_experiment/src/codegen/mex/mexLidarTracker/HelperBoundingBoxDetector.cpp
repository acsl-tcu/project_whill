//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  HelperBoundingBoxDetector.cpp
//
//  Code generation for function 'HelperBoundingBoxDetector'
//


// Include files
#include "HelperBoundingBoxDetector.h"
#include "ProcessConstructorArguments.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "homogeneous.h"
#include "mean.h"
#include "mexLidarTracker_data.h"
#include "mode.h"
#include "objectDetection.h"
#include "pcfitplane.h"
#include "pcsegdist.h"
#include "pctransform.h"
#include "planeModel.h"
#include "pointCloud.h"
#include "rigid3d.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo hb_emlrtRSI = { 76, // lineNo
  "HelperBoundingBoxDetector/stepImpl",// fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo ib_emlrtRSI = { 83, // lineNo
  "HelperBoundingBoxDetector/stepImpl",// fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo jb_emlrtRSI = { 84, // lineNo
  "HelperBoundingBoxDetector/stepImpl",// fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo kb_emlrtRSI = { 72, // lineNo
  "HelperBoundingBoxDetector/stepImpl",// fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo lb_emlrtRSI = { 74, // lineNo
  "HelperBoundingBoxDetector/stepImpl",// fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo mb_emlrtRSI = { 276,// lineNo
  "cropPointCloud2",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo nb_emlrtRSI = { 289,// lineNo
  "cropPointCloud2",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo ob_emlrtRSI = { 290,// lineNo
  "cropPointCloud2",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo pb_emlrtRSI = { 292,// lineNo
  "cropPointCloud2",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo qb_emlrtRSI = { 272,// lineNo
  "cropPointCloud2",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo rb_emlrtRSI = { 273,// lineNo
  "HelperBoundingBoxDetector",         // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo sb_emlrtRSI = { 291,// lineNo
  "cropPointCloud2",                   // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo if_emlrtRSI = { 29, // lineNo
  "reshapeSizeChecks",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pathName 
};

static emlrtRSInfo tf_emlrtRSI = { 225,// lineNo
  "removeGroundPlane",                 // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo uf_emlrtRSI = { 226,// lineNo
  "removeGroundPlane",                 // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo vf_emlrtRSI = { 227,// lineNo
  "removeGroundPlane",                 // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo xl_emlrtRSI = { 110,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo yl_emlrtRSI = { 115,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo am_emlrtRSI = { 118,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo bm_emlrtRSI = { 121,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo cm_emlrtRSI = { 122,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo dm_emlrtRSI = { 123,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo em_emlrtRSI = { 124,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo fm_emlrtRSI = { 125,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo gm_emlrtRSI = { 126,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo hm_emlrtRSI = { 133,// lineNo
  "getBoundingBoxes",                  // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRSInfo rn_emlrtRSI = { 57, // lineNo
  "mode",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/mode.m"// pathName
};

static emlrtRSInfo xn_emlrtRSI = { 93, // lineNo
  "assembleDetections",                // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pathName 
};

static emlrtRTEInfo f_emlrtRTEI = { 116,// lineNo
  9,                                   // colNo
  "computeDimsData",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pName 
};

static emlrtBCInfo i_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  93,                                  // lineNo
  56,                                  // colNo
  "bboxes",                            // aName
  "assembleDetections",                // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo g_emlrtRTEI = { 52,// lineNo
  13,                                  // colNo
  "reshapeSizeChecks",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pName 
};

static emlrtRTEInfo h_emlrtRTEI = { 59,// lineNo
  23,                                  // colNo
  "reshapeSizeChecks",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pName 
};

static emlrtECInfo b_emlrtECI = { -1,  // nDims
  280,                                 // lineNo
  14,                                  // colNo
  "cropPointCloud2",                   // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtECInfo c_emlrtECI = { -1,  // nDims
  279,                                 // lineNo
  15,                                  // colNo
  "cropPointCloud2",                   // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtECInfo d_emlrtECI = { -1,  // nDims
  278,                                 // lineNo
  15,                                  // colNo
  "cropPointCloud2",                   // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtECInfo e_emlrtECI = { -1,  // nDims
  277,                                 // lineNo
  15,                                  // colNo
  "cropPointCloud2",                   // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo i_emlrtRTEI = { 1, // lineNo
  1,                                   // colNo
  "SystemCore/release",                // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pName 
};

static emlrtBCInfo j_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  228,                                 // lineNo
  38,                                  // colNo
  "currentIndices",                    // aName
  "removeGroundPlane",                 // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo k_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  229,                                 // lineNo
  36,                                  // colNo
  "currentIndices",                    // aName
  "removeGroundPlane",                 // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo l_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  93,                                  // lineNo
  5,                                   // colNo
  "detections",                        // aName
  "assembleDetections",                // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ab_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  138,                                 // lineNo
  22,                                  // colNo
  "bboxes",                            // aName
  "getBoundingBoxes",                  // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo mb_emlrtRTEI = { 116,// lineNo
  13,                                  // colNo
  "getBoundingBoxes",                  // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtDCInfo c_emlrtDCI = { 113, // lineNo
  20,                                  // colNo
  "getBoundingBoxes",                  // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo d_emlrtDCI = { 114, // lineNo
  30,                                  // colNo
  "getBoundingBoxes",                  // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo e_emlrtDCI = { 113, // lineNo
  5,                                   // colNo
  "getBoundingBoxes",                  // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo f_emlrtDCI = { 114, // lineNo
  5,                                   // colNo
  "getBoundingBoxes",                  // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo bb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  117,                                 // lineNo
  35,                                  // colNo
  "pointData",                         // aName
  "getBoundingBoxes",                  // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo cb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  139,                                 // lineNo
  13,                                  // colNo
  "isValidCluster",                    // aName
  "getBoundingBoxes",                  // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo db_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  142,                                 // lineNo
  23,                                  // colNo
  "bboxes",                            // aName
  "getBoundingBoxes",                  // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo be_emlrtRTEI = { 275,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo ce_emlrtRTEI = { 276,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo de_emlrtRTEI = { 277,// lineNo
  15,                                  // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo ee_emlrtRTEI = { 277,// lineNo
  45,                                  // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo fe_emlrtRTEI = { 278,// lineNo
  15,                                  // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo ge_emlrtRTEI = { 278,// lineNo
  45,                                  // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo he_emlrtRTEI = { 279,// lineNo
  15,                                  // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo ie_emlrtRTEI = { 279,// lineNo
  45,                                  // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo je_emlrtRTEI = { 289,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo ke_emlrtRTEI = { 290,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo le_emlrtRTEI = { 228,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo me_emlrtRTEI = { 229,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo ne_emlrtRTEI = { 83,// lineNo
  24,                                  // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo ug_emlrtRTEI = { 111,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo vg_emlrtRTEI = { 113,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo wg_emlrtRTEI = { 114,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo xg_emlrtRTEI = { 99,// lineNo
  40,                                  // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo yg_emlrtRTEI = { 117,// lineNo
  9,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo ah_emlrtRTEI = { 142,// lineNo
  14,                                  // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo bh_emlrtRTEI = { 142,// lineNo
  5,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

static emlrtRTEInfo ch_emlrtRTEI = { 144,// lineNo
  9,                                   // colNo
  "HelperBoundingBoxDetector",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/HelperBoundingBoxDetector.m"// pName 
};

// Function Definitions
void HelperBoundingBoxDetector::getBoundingBoxes(const emlrtStack *sp, coder::
  b_pointCloud *ptCloud, real_T minDistance, real_T minDetsPerCluster, real_T
  maxZDistance, real_T minZDistance, real_T Plant_X, real_T Plant_Y, real_T
  Plant_yaw, real_T b_time, real_T SP, coder::array<real_T, 2U> &bboxes,
  real32_T *numClusters, coder::array<uint32_T, 1U> &labels)
{
  coder::array<real_T, 2U> b_bboxes;
  coder::array<int32_T, 2U> r;
  coder::array<int32_T, 1U> r1;
  coder::array<real32_T, 2U> pointData;
  coder::array<real32_T, 2U> thisPointData;
  coder::array<boolean_T, 2U> isValidCluster;
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
  int32_T b_i;
  int32_T end;
  int32_T i;
  int32_T idx;
  real32_T meanPoint[3];
  real32_T x_global;
  real32_T y_global;
  emlrtProfilerSentinel profilerSentinel;
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
  emlrtMEXProfilingFunctionEntryCPP(getBoundingBoxes_complete_name,
    static_cast<boolean_T>(isMexOutdated), &profilerSentinel);
  emlrtMEXProfilingStatement(1, static_cast<boolean_T>(isMexOutdated));
  st.site = &xl_emlrtRSI;
  coder::pcsegdist(&st, ptCloud, minDistance, labels, numClusters);
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  pointData.set_size(&ug_emlrtRTEI, sp, ptCloud->Location.size(0), 3);
  idx = ptCloud->Location.size(0) * ptCloud->Location.size(1);
  for (i = 0; i < idx; i++) {
    pointData[i] = ptCloud->Location[i];
  }

  emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
  bboxes.set_size(&vg_emlrtRTEI, sp, 3, bboxes.size(1));
  d = static_cast<int32_T>(muDoubleScalarFloor(static_cast<real_T>(*numClusters)));
  if (*numClusters != d) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(*numClusters), &c_emlrtDCI, sp);
  }

  bboxes.set_size(&vg_emlrtRTEI, sp, bboxes.size(0), static_cast<int32_T>
                  (*numClusters));
  if (*numClusters != d) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(*numClusters), &e_emlrtDCI, sp);
  }

  idx = 3 * static_cast<int32_T>(*numClusters);
  for (i = 0; i < idx; i++) {
    bboxes[i] = rtNaN;
  }

  emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));
  isValidCluster.set_size(&wg_emlrtRTEI, sp, 1, isValidCluster.size(1));
  if (*numClusters != d) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(*numClusters), &d_emlrtDCI, sp);
  }

  isValidCluster.set_size(&wg_emlrtRTEI, sp, isValidCluster.size(0),
    static_cast<int32_T>(*numClusters));
  if (*numClusters != d) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(*numClusters), &f_emlrtDCI, sp);
  }

  idx = static_cast<int32_T>(*numClusters);
  for (i = 0; i < idx; i++) {
    isValidCluster[i] = false;
  }

  emlrtMEXProfilingStatement(5, static_cast<boolean_T>(isMexOutdated));
  st.site = &yl_emlrtRSI;
  b_st.site = &rn_emlrtRSI;
  coder::arraymode(&b_st, labels);
  emlrtMEXProfilingStatement(6, static_cast<boolean_T>(isMexOutdated));
  i = static_cast<int32_T>(*numClusters);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, static_cast<real_T>(*numClusters),
    mxSINGLE_CLASS, static_cast<int32_T>(*numClusters), &mb_emlrtRTEI, sp);
  for (b_i = 0; b_i < i; b_i++) {
    int32_T c_i;
    int32_T i1;
    emlrtMEXProfilingStatement(7, static_cast<boolean_T>(isMexOutdated));
    end = labels.size(0) - 1;
    idx = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (labels[c_i] == static_cast<uint32_T>(static_cast<real32_T>(b_i) + 1.0F))
      {
        idx++;
      }
    }

    r1.set_size(&xg_emlrtRTEI, sp, idx);
    idx = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (labels[c_i] == static_cast<uint32_T>(static_cast<real32_T>(b_i) + 1.0F))
      {
        r1[idx] = c_i + 1;
        idx++;
      }
    }

    idx = r1.size(0);
    thisPointData.set_size(&yg_emlrtRTEI, sp, r1.size(0), 3);
    for (i1 = 0; i1 < 3; i1++) {
      for (end = 0; end < idx; end++) {
        if ((r1[end] < 1) || (r1[end] > pointData.size(0))) {
          emlrtDynamicBoundsCheckR2012b(r1[end], 1, pointData.size(0),
            &bb_emlrtBCI, sp);
        }

        thisPointData[end + thisPointData.size(0) * i1] = pointData[(r1[end] +
          pointData.size(0) * i1) - 1];
      }
    }

    emlrtMEXProfilingStatement(8, static_cast<boolean_T>(isMexOutdated));
    st.site = &am_emlrtRSI;
    coder::mean(&st, thisPointData, meanPoint);
    emlrtMEXProfilingStatement(9, static_cast<boolean_T>(isMexOutdated));
    i1 = r1.size(0);
    if ((r1.size(0) > minDetsPerCluster) && (meanPoint[2] < maxZDistance) &&
        (meanPoint[2] > minZDistance)) {
      real32_T a;
      real32_T l;
      real32_T xMax;
      real32_T xMin;
      real32_T yMax;
      real32_T yMin;
      boolean_T exitg1;
      boolean_T overflow;
      emlrtMEXProfilingStatement(11, static_cast<boolean_T>(isMexOutdated));
      st.site = &bm_emlrtRSI;
      b_st.site = &td_emlrtRSI;
      c_st.site = &ud_emlrtRSI;
      d_st.site = &vd_emlrtRSI;
      if (r1.size(0) < 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      e_st.site = &wd_emlrtRSI;
      f_st.site = &xd_emlrtRSI;
      if (r1.size(0) <= 2) {
        if (r1.size(0) == 1) {
          xMin = thisPointData[0];
        } else if ((thisPointData[0] > thisPointData[1]) || (muSingleScalarIsNaN
                    (thisPointData[0]) && (!muSingleScalarIsNaN(thisPointData[1]))))
        {
          xMin = thisPointData[1];
        } else {
          xMin = thisPointData[0];
        }
      } else {
        g_st.site = &vn_emlrtRSI;
        if (!muSingleScalarIsNaN(thisPointData[0])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &wn_emlrtRSI;
          overflow = ((2 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          c_i = 2;
          exitg1 = false;
          while ((!exitg1) && (c_i <= r1.size(0))) {
            if (!muSingleScalarIsNaN(thisPointData[c_i - 1])) {
              idx = c_i;
              exitg1 = true;
            } else {
              c_i++;
            }
          }
        }

        if (idx == 0) {
          xMin = thisPointData[0];
        } else {
          g_st.site = &rd_emlrtRSI;
          xMin = thisPointData[idx - 1];
          end = idx + 1;
          h_st.site = &sd_emlrtRSI;
          overflow = ((idx + 1 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          for (c_i = end; c_i <= i1; c_i++) {
            a = thisPointData[c_i - 1];
            if (xMin > a) {
              xMin = a;
            }
          }
        }
      }

      emlrtMEXProfilingStatement(12, static_cast<boolean_T>(isMexOutdated));
      st.site = &cm_emlrtRSI;
      b_st.site = &md_emlrtRSI;
      c_st.site = &nd_emlrtRSI;
      d_st.site = &od_emlrtRSI;
      i1 = r1.size(0);
      if (r1.size(0) < 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      e_st.site = &pd_emlrtRSI;
      f_st.site = &qd_emlrtRSI;
      if (r1.size(0) <= 2) {
        if (r1.size(0) == 1) {
          xMax = thisPointData[0];
        } else if ((thisPointData[0] < thisPointData[1]) || (muSingleScalarIsNaN
                    (thisPointData[0]) && (!muSingleScalarIsNaN(thisPointData[1]))))
        {
          xMax = thisPointData[1];
        } else {
          xMax = thisPointData[0];
        }
      } else {
        g_st.site = &vn_emlrtRSI;
        if (!muSingleScalarIsNaN(thisPointData[0])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &wn_emlrtRSI;
          overflow = ((2 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          c_i = 2;
          exitg1 = false;
          while ((!exitg1) && (c_i <= r1.size(0))) {
            if (!muSingleScalarIsNaN(thisPointData[c_i - 1])) {
              idx = c_i;
              exitg1 = true;
            } else {
              c_i++;
            }
          }
        }

        if (idx == 0) {
          xMax = thisPointData[0];
        } else {
          g_st.site = &rd_emlrtRSI;
          xMax = thisPointData[idx - 1];
          end = idx + 1;
          h_st.site = &sd_emlrtRSI;
          overflow = ((idx + 1 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          for (c_i = end; c_i <= i1; c_i++) {
            a = thisPointData[c_i - 1];
            if (xMax < a) {
              xMax = a;
            }
          }
        }
      }

      emlrtMEXProfilingStatement(13, static_cast<boolean_T>(isMexOutdated));
      st.site = &dm_emlrtRSI;
      b_st.site = &td_emlrtRSI;
      c_st.site = &ud_emlrtRSI;
      d_st.site = &vd_emlrtRSI;
      i1 = r1.size(0);
      if (r1.size(0) < 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      e_st.site = &wd_emlrtRSI;
      f_st.site = &xd_emlrtRSI;
      if (r1.size(0) <= 2) {
        if (r1.size(0) == 1) {
          yMin = thisPointData[thisPointData.size(0)];
        } else if ((thisPointData[thisPointData.size(0)] >
                    thisPointData[thisPointData.size(0) + 1]) ||
                   (muSingleScalarIsNaN(thisPointData[thisPointData.size(0)]) &&
                    (!muSingleScalarIsNaN(thisPointData[thisPointData.size(0) +
                      1])))) {
          yMin = thisPointData[thisPointData.size(0) + 1];
        } else {
          yMin = thisPointData[thisPointData.size(0)];
        }
      } else {
        g_st.site = &vn_emlrtRSI;
        if (!muSingleScalarIsNaN(thisPointData[thisPointData.size(0)])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &wn_emlrtRSI;
          overflow = ((2 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          c_i = 2;
          exitg1 = false;
          while ((!exitg1) && (c_i <= r1.size(0))) {
            if (!muSingleScalarIsNaN(thisPointData[(c_i + thisPointData.size(0))
                 - 1])) {
              idx = c_i;
              exitg1 = true;
            } else {
              c_i++;
            }
          }
        }

        if (idx == 0) {
          yMin = thisPointData[thisPointData.size(0)];
        } else {
          g_st.site = &rd_emlrtRSI;
          yMin = thisPointData[(idx + thisPointData.size(0)) - 1];
          end = idx + 1;
          h_st.site = &sd_emlrtRSI;
          overflow = ((idx + 1 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          for (c_i = end; c_i <= i1; c_i++) {
            a = thisPointData[(c_i + thisPointData.size(0)) - 1];
            if (yMin > a) {
              yMin = a;
            }
          }
        }
      }

      emlrtMEXProfilingStatement(14, static_cast<boolean_T>(isMexOutdated));
      st.site = &em_emlrtRSI;
      b_st.site = &md_emlrtRSI;
      c_st.site = &nd_emlrtRSI;
      d_st.site = &od_emlrtRSI;
      i1 = r1.size(0);
      if (r1.size(0) < 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      e_st.site = &pd_emlrtRSI;
      f_st.site = &qd_emlrtRSI;
      if (r1.size(0) <= 2) {
        if (r1.size(0) == 1) {
          yMax = thisPointData[thisPointData.size(0)];
        } else if ((thisPointData[thisPointData.size(0)] <
                    thisPointData[thisPointData.size(0) + 1]) ||
                   (muSingleScalarIsNaN(thisPointData[thisPointData.size(0)]) &&
                    (!muSingleScalarIsNaN(thisPointData[thisPointData.size(0) +
                      1])))) {
          yMax = thisPointData[thisPointData.size(0) + 1];
        } else {
          yMax = thisPointData[thisPointData.size(0)];
        }
      } else {
        g_st.site = &vn_emlrtRSI;
        if (!muSingleScalarIsNaN(thisPointData[thisPointData.size(0)])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &wn_emlrtRSI;
          overflow = ((2 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          c_i = 2;
          exitg1 = false;
          while ((!exitg1) && (c_i <= r1.size(0))) {
            if (!muSingleScalarIsNaN(thisPointData[(c_i + thisPointData.size(0))
                 - 1])) {
              idx = c_i;
              exitg1 = true;
            } else {
              c_i++;
            }
          }
        }

        if (idx == 0) {
          yMax = thisPointData[thisPointData.size(0)];
        } else {
          g_st.site = &rd_emlrtRSI;
          yMax = thisPointData[(idx + thisPointData.size(0)) - 1];
          end = idx + 1;
          h_st.site = &sd_emlrtRSI;
          overflow = ((idx + 1 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          for (c_i = end; c_i <= i1; c_i++) {
            a = thisPointData[(c_i + thisPointData.size(0)) - 1];
            if (yMax < a) {
              yMax = a;
            }
          }
        }
      }

      emlrtMEXProfilingStatement(15, static_cast<boolean_T>(isMexOutdated));
      st.site = &fm_emlrtRSI;
      b_st.site = &td_emlrtRSI;
      c_st.site = &ud_emlrtRSI;
      d_st.site = &vd_emlrtRSI;
      if (r1.size(0) < 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      e_st.site = &wd_emlrtRSI;
      f_st.site = &xd_emlrtRSI;
      if (r1.size(0) > 2) {
        g_st.site = &vn_emlrtRSI;
        if (!muSingleScalarIsNaN(thisPointData[thisPointData.size(0) * 2])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &wn_emlrtRSI;
          overflow = ((2 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          c_i = 2;
          exitg1 = false;
          while ((!exitg1) && (c_i <= r1.size(0))) {
            if (!muSingleScalarIsNaN(thisPointData[(c_i + thisPointData.size(0) *
                  2) - 1])) {
              idx = c_i;
              exitg1 = true;
            } else {
              c_i++;
            }
          }
        }

        if (idx != 0) {
          g_st.site = &rd_emlrtRSI;
          h_st.site = &sd_emlrtRSI;
          overflow = ((idx + 1 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }
        }
      }

      emlrtMEXProfilingStatement(16, static_cast<boolean_T>(isMexOutdated));
      st.site = &gm_emlrtRSI;
      b_st.site = &md_emlrtRSI;
      c_st.site = &nd_emlrtRSI;
      d_st.site = &od_emlrtRSI;
      if (r1.size(0) < 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      e_st.site = &pd_emlrtRSI;
      f_st.site = &qd_emlrtRSI;
      if (r1.size(0) > 2) {
        g_st.site = &vn_emlrtRSI;
        if (!muSingleScalarIsNaN(thisPointData[thisPointData.size(0) * 2])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &wn_emlrtRSI;
          overflow = ((2 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }

          c_i = 2;
          exitg1 = false;
          while ((!exitg1) && (c_i <= r1.size(0))) {
            if (!muSingleScalarIsNaN(thisPointData[(c_i + thisPointData.size(0) *
                  2) - 1])) {
              idx = c_i;
              exitg1 = true;
            } else {
              c_i++;
            }
          }
        }

        if (idx != 0) {
          g_st.site = &rd_emlrtRSI;
          h_st.site = &sd_emlrtRSI;
          overflow = ((idx + 1 <= r1.size(0)) && (r1.size(0) > 2147483646));
          if (overflow) {
            i_st.site = &jc_emlrtRSI;
            coder::check_forloop_overflow_error(&i_st);
          }
        }
      }

      emlrtMEXProfilingStatement(17, static_cast<boolean_T>(isMexOutdated));
      l = xMax - xMin;
      emlrtMEXProfilingStatement(18, static_cast<boolean_T>(isMexOutdated));
      a = yMax - yMin;
      emlrtMEXProfilingStatement(20, static_cast<boolean_T>(isMexOutdated));
      emlrtMEXProfilingStatement(21, static_cast<boolean_T>(isMexOutdated));
      emlrtMEXProfilingStatement(23, static_cast<boolean_T>(isMexOutdated));
      st.site = &hm_emlrtRSI;
      b_st.site = &pk_emlrtRSI;
      c_st.site = &qk_emlrtRSI;
      st.site = &hm_emlrtRSI;
      b_st.site = &pk_emlrtRSI;
      c_st.site = &qk_emlrtRSI;
      a = l * l + a * a;
      st.site = &hm_emlrtRSI;
      if (a < 0.0F) {
        emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      a = muSingleScalarSqrt(a);
      emlrtMEXProfilingStatement(24, static_cast<boolean_T>(isMexOutdated));
      homogeneous(Plant_X, Plant_Y, Plant_yaw, (xMin + xMax) / 2.0F, (yMin +
        yMax) / 2.0F, SP, &x_global, &y_global);
      emlrtMEXProfilingStatement(25, static_cast<boolean_T>(isMexOutdated));
      if ((static_cast<int32_T>(static_cast<real32_T>(b_i) + 1.0F) < 1) || (
           static_cast<int32_T>(static_cast<real32_T>(b_i) + 1.0F) > bboxes.size
           (1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(static_cast<real32_T>
          (b_i) + 1.0F), 1, bboxes.size(1), &ab_emlrtBCI, sp);
      }

      bboxes[3 * (static_cast<int32_T>(static_cast<real32_T>(b_i) + 1.0F) - 1)] =
        x_global;
      bboxes[3 * (static_cast<int32_T>(static_cast<real32_T>(b_i) + 1.0F) - 1) +
        1] = y_global;
      bboxes[3 * (static_cast<int32_T>(static_cast<real32_T>(b_i) + 1.0F) - 1) +
        2] = a / 2.0F;
      emlrtMEXProfilingStatement(26, static_cast<boolean_T>(isMexOutdated));
      if ((static_cast<int32_T>(static_cast<real32_T>(b_i) + 1.0F) < 1) || (
           static_cast<int32_T>(static_cast<real32_T>(b_i) + 1.0F) >
           isValidCluster.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(static_cast<real32_T>
          (b_i) + 1.0F), 1, isValidCluster.size(1), &cb_emlrtBCI, sp);
      }

      isValidCluster[static_cast<int32_T>(static_cast<real32_T>
        (static_cast<int32_T>(static_cast<real32_T>(b_i) + 1.0F))) - 1] = (l <
        5.0F);
      emlrtMEXProfilingStatement(27, static_cast<boolean_T>(isMexOutdated));
    }

    emlrtMEXProfilingStatement(28, static_cast<boolean_T>(isMexOutdated));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtMEXProfilingStatement(29, static_cast<boolean_T>(isMexOutdated));
  end = isValidCluster.size(1) - 1;
  idx = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if (isValidCluster[b_i]) {
      idx++;
    }
  }

  r.set_size(&xg_emlrtRTEI, sp, 1, idx);
  idx = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if (isValidCluster[b_i]) {
      r[idx] = b_i + 1;
      idx++;
    }
  }

  b_bboxes.set_size(&ah_emlrtRTEI, sp, 3, r.size(1));
  idx = r.size(1);
  for (i = 0; i < idx; i++) {
    if ((r[i] < 1) || (r[i] > bboxes.size(1))) {
      emlrtDynamicBoundsCheckR2012b(r[i], 1, bboxes.size(1), &db_emlrtBCI, sp);
    }

    b_bboxes[3 * i] = bboxes[3 * (r[i] - 1)];
    if ((r[i] < 1) || (r[i] > bboxes.size(1))) {
      emlrtDynamicBoundsCheckR2012b(r[i], 1, bboxes.size(1), &db_emlrtBCI, sp);
    }

    b_bboxes[3 * i + 1] = bboxes[3 * (r[i] - 1) + 1];
    if ((r[i] < 1) || (r[i] > bboxes.size(1))) {
      emlrtDynamicBoundsCheckR2012b(r[i], 1, bboxes.size(1), &db_emlrtBCI, sp);
    }

    b_bboxes[3 * i + 2] = bboxes[3 * (r[i] - 1) + 2];
  }

  bboxes.set_size(&bh_emlrtRTEI, sp, 3, b_bboxes.size(1));
  idx = b_bboxes.size(0) * b_bboxes.size(1);
  for (i = 0; i < idx; i++) {
    bboxes[i] = b_bboxes[i];
  }

  emlrtMEXProfilingStatement(30, static_cast<boolean_T>(isMexOutdated));
  if ((bboxes.size(1) == 0) && (b_time < 0.008)) {
    emlrtMEXProfilingStatement(31, static_cast<boolean_T>(isMexOutdated));
    bboxes.set_size(&ch_emlrtRTEI, sp, 3, 1);
    bboxes[0] = 100000.0;
    bboxes[1] = 100000.0;
    bboxes[2] = 0.001;
    emlrtMEXProfilingStatement(32, static_cast<boolean_T>(isMexOutdated));
  }

  emlrtMEXProfilingStatement(33, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void HelperBoundingBoxDetector::setup(const emlrtStack *sp)
{
  if (this->isInitialized != 0) {
    emlrtErrorWithMessageIdR2018a(sp, &i_emlrtRTEI,
      "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
      "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
  }

  this->isInitialized = 1;
}

void HelperBoundingBoxDetector::setupAndReset(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  this->setup(&st);
}

HelperBoundingBoxDetector *HelperBoundingBoxDetector::init()
{
  static real_T dv[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, -1.0 };

  HelperBoundingBoxDetector *obj;
  emlrtProfilerSentinel profilerSentinel;
  dv[0U] = rtMinusInf;
  dv[1U] = rtMinusInf;
  dv[2U] = rtMinusInf;
  dv[3U] = rtInf;
  dv[4U] = rtInf;
  emlrtMEXProfilingFunctionEntryCPP(c_HelperBoundingBoxDetector_Hel,
    static_cast<boolean_T>(isMexOutdated), &profilerSentinel);
  obj = this;
  obj->GroundReferenceVector[0] = 0.0;
  obj->GroundReferenceVector[1] = 0.0;
  obj->GroundReferenceVector[2] = 1.0;
  for (int32_T i = 0; i < 6; i++) {
    obj->roi[i] = dv[i];
  }

  obj->GroundMaxAngularDistance = 5.0;
  obj->MaxZDistanceCluster = 3.0;
  obj->MinZDistanceCluster = -3.0;
  emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
  obj->isInitialized = 0;
  emlrtMEXProfilingStatement(1, static_cast<boolean_T>(isMexOutdated));
  coder::matlab::system::coder::ProcessConstructorArguments::b_do(obj);
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
  return obj;
}

boolean_T HelperBoundingBoxDetector::isLockedAndNotReleased() const
{
  return this->isInitialized == 1;
}

void HelperBoundingBoxDetector::step(const emlrtStack *sp, coder::b_pointCloud
  *varargin_1, real_T varargin_2, real_T varargin_3_X, real_T varargin_3_Y,
  real_T varargin_3_yaw, const real_T varargin_4[6], real_T varargin_5, real_T
  varargin_6, coder::array<coder::objectDetection, 2U> &varargout_1, coder::
  array<real_T, 1U> &varargout_2, coder::array<real_T, 1U> &varargout_3, coder::
  array<real_T, 1U> &varargout_4, real32_T *varargout_5, coder::array<uint32_T,
  1U> &varargout_6)
{
  coder::b_pointCloud pcObstacles;
  coder::b_pointCloud pcSurvived;
  coder::b_pointCloud ptCloud_obs;
  coder::planeModel unusedU0;
  coder::planeModel *r1;
  coder::rigid3d tform;
  coder::array<real_T, 2U> detBBoxes;
  coder::array<real_T, 1U> groundIndices;
  coder::array<real_T, 1U> outliers;
  coder::array<real_T, 1U> survivedIndices;
  coder::array<int32_T, 1U> ii;
  coder::array<real32_T, 2U> locations;
  coder::array<uint32_T, 1U> sampleIndices;
  coder::array<boolean_T, 1U> insideX;
  coder::array<boolean_T, 1U> insideY;
  coder::array<boolean_T, 1U> insideZ;
  coder::array<boolean_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T c_rot_tmp[9];
  real_T b_roi[6];
  real_T trans[3];
  real_T b_rot_tmp;
  real_T rot_tmp;
  int32_T calclen;
  int32_T i;
  int32_T loop_ub;
  int32_T nx;
  emlrtProfilerSentinel b_profilerSentinel;
  emlrtProfilerSentinel c_profilerSentinel;
  emlrtProfilerSentinel d_profilerSentinel;
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
  if (this->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(sp, &i_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen",
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (this->isInitialized != 1) {
    st.site = &l_emlrtRSI;
    this->setupAndReset(&st);
  }

  st.site = &l_emlrtRSI;
  emlrtMEXProfilingFunctionEntryCPP(c_HelperBoundingBoxDetector_ste,
    static_cast<boolean_T>(isMexOutdated), &profilerSentinel);
  pcObstacles.matlabCodegenIsDeleted = true;
  pcSurvived.matlabCodegenIsDeleted = true;
  emlrtMEXProfilingStatement(1, static_cast<boolean_T>(isMexOutdated));
  b_st.site = &kb_emlrtRSI;
  emlrtMEXProfilingFunctionEntryCPP(cropPointCloud2_complete_name,
    static_cast<boolean_T>(isMexOutdated), &b_profilerSentinel);
  ptCloud_obs.matlabCodegenIsDeleted = true;

  //  function [detections,obstacleIndices,groundIndices,croppedIndices,...
  //      confirmedTracks, modelProbs,numClusters,labels] = HelperBoundingBoxDetector(ptCloudLocations,time,Plant) 
  //  HelperBoundingBoxDetector A helper class to segment the point cloud
  //  into bounding box detections.
  //  The step call to the object does the following things:
  //
  //  1. Removes point cloud outside the limits.
  //  2. From the survived point cloud, segments out ground
  //  3. From the obstacle point cloud, forms clusters and puts bounding
  //     box on each cluster.
  //  Cropping properties
  //  XLimits XLimits for the scene
  //  YLimits YLimits for the scene
  //  ZLimits ZLimits fot the scene
  //  Ground Segmentation Properties
  //  GroundMaxDistance Maximum distance of point to the ground plane
  //  GroundReferenceVector Reference vector of ground plane
  //  GroundMaxAngularDistance Maximum angular distance of point to reference vector 
  //  Bounding box Segmentation properties
  //  SegmentationMinDistance Distance threshold for segmentation
  //  MinDetectionsPerCluster Minimum number of detections per cluster
  //  MaxZDistanceCluster Maximum Z-coordinate of cluster
  //  MinZDistanceCluster Minimum Z-coordinate of cluster
  //  Ego vehicle radius to remove ego vehicle point cloud.
  //  EgoVehicleRadius Radius of ego vehicle
  //  MeasurementNoise Measurement noise for the bounding box detection
  //          MeasurementNoise = blkdiag(eye(3),eye(3));
  //  Crop point cloud
  //              [pcSurvived,survivedIndices,croppedIndices] = cropPointCloud(currentPointCloud,obj.XLimits,obj.YLimits,obj.ZLimits,obj.EgoVehicleRadius); 
  //  Remove ground plane
  //  Form clusters and get bounding boxes
  //  Assemble detections
  //  This method assembles the detections in objectDetection format.
  //  This method fits bounding boxes on each cluster with some basic
  //  rules.
  //  Cluster must have atleast minDetsPerCluster points.
  //  Its mean z must be between maxZDistance and minZDistance.
  //  length, width and height are calculated using min and max from each
  //  dimension.
  //      global writerObj
  //      bboxes = nan(3,numClusters,'like',pointData);
  // && i ~= M
  //              bboxes(:,i) = [x y z l w h]';
  //              bboxes(:,i) = [x y z]';
  //  max length of 20 meters
  //      open(writerObj)
  //      figure(99)
  //      numClusters = numClusters+1;
  //      labelColorIndex = labels+1;
  //      pcshow(ptCloud.Location,labelColorIndex,'MarkerSize',50)
  //      colormap([hsv(numClusters);[1 1 1]])
  //      title('Point Cloud Clusters')
  //      view(0,90)
  //      xlim([-15 15])bboxes
  //      ylim([-15 15])
  //      ax = gca;
  //      ax.XColor = 'white';
  //      ax.YColor = 'white';
  //      refreshdata(gcf);
  //      %-- get frames as images --%
  //      frame = getframe(gcf);
  //      %- Add frame to video object -%
  //      writeVideo(writerObj, frame);
  //      drawnow limitrate;
  //      hold off;
  //      close(writerObj)
  // CIRCLEFITTING 最小二乗法による円フィッテングをする関数
  //  input: x,y 円フィッティングする点群
  //  output cx 中心x座標
  //         cy 中心y座標
  //         r  半径
  // && i ~= M
  //  This method removes the ground plane from point cloud using
  //  pcfitplane.
  //  This method selects the point cloud within limits and removes the
  //  ego vehicle point cloud using findNeighborsInRadius
  //  Remove ego vehicle
  //  This method selects the point cloud within limits and removes the
  //  ego vehicle point cloud using findNeighborsInRadius
  //  pcshow(ptCloudIn);
  emlrtMEXProfilingStatement(1, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
  rot_tmp = muDoubleScalarSin(varargin_3_yaw);
  b_rot_tmp = muDoubleScalarCos(varargin_3_yaw);
  emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
  if (varargin_5 == 1.0) {
    emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));
    trans[0] = 0.0;
    trans[1] = varargin_3_Y;
    trans[2] = 0.0;
    emlrtMEXProfilingStatement(9, static_cast<boolean_T>(isMexOutdated));
  } else {
    emlrtMEXProfilingStatement(5, static_cast<boolean_T>(isMexOutdated));
    if (varargin_5 == 2.0) {
      emlrtMEXProfilingStatement(6, static_cast<boolean_T>(isMexOutdated));
      trans[0] = varargin_3_X;
      trans[1] = 0.0;
      trans[2] = 0.0;
      emlrtMEXProfilingStatement(9, static_cast<boolean_T>(isMexOutdated));
    } else {
      emlrtMEXProfilingStatement(7, static_cast<boolean_T>(isMexOutdated));

      //  axis == 3
      emlrtMEXProfilingStatement(8, static_cast<boolean_T>(isMexOutdated));
      trans[0] = varargin_3_X;
      trans[1] = varargin_3_Y;
      trans[2] = 0.0;
      emlrtMEXProfilingStatement(9, static_cast<boolean_T>(isMexOutdated));
    }
  }

  emlrtMEXProfilingStatement(10, static_cast<boolean_T>(isMexOutdated));
  c_rot_tmp[0] = b_rot_tmp;
  c_rot_tmp[3] = rot_tmp;
  c_rot_tmp[6] = 0.0;
  c_rot_tmp[1] = -rot_tmp;
  c_rot_tmp[4] = b_rot_tmp;
  c_rot_tmp[7] = 0.0;
  c_rot_tmp[2] = 0.0;
  c_rot_tmp[5] = 0.0;
  c_rot_tmp[8] = 1.0;
  c_st.site = &qb_emlrtRSI;
  tform.init(&c_st, c_rot_tmp, trans);
  emlrtMEXProfilingStatement(11, static_cast<boolean_T>(isMexOutdated));
  c_st.site = &rb_emlrtRSI;
  coder::pctransform(&c_st, varargin_1, &tform, &ptCloud_obs);

  //     pcshow(ptCloud_obs)
  emlrtMEXProfilingStatement(12, static_cast<boolean_T>(isMexOutdated));
  locations.set_size(&be_emlrtRTEI, &b_st, ptCloud_obs.Location.size(0), 3);
  loop_ub = ptCloud_obs.Location.size(0) * ptCloud_obs.Location.size(1);
  for (i = 0; i < loop_ub; i++) {
    locations[i] = ptCloud_obs.Location[i];
  }

  emlrtMEXProfilingStatement(13, static_cast<boolean_T>(isMexOutdated));
  c_st.site = &mb_emlrtRSI;
  nx = locations.size(0) * 3;
  d_st.site = &if_emlrtRSI;
  calclen = nx / 3;
  if (calclen > nx) {
    emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  loop_ub = locations.size(0);
  if (3 > locations.size(0)) {
    loop_ub = 3;
  }

  if (calclen > muIntScalarMax_sint32(nx, loop_ub)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &g_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (calclen * 3 != nx) {
    emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  locations.set_size(&ce_emlrtRTEI, &b_st, calclen, 3);
  emlrtMEXProfilingStatement(14, static_cast<boolean_T>(isMexOutdated));
  insideX.set_size(&de_emlrtRTEI, &b_st, calclen);
  for (i = 0; i < calclen; i++) {
    insideX[i] = (locations[i] < varargin_4[3]);
  }

  r.set_size(&ee_emlrtRTEI, &b_st, calclen);
  for (i = 0; i < calclen; i++) {
    r[i] = (locations[i] > varargin_4[0]);
  }

  if (insideX.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(insideX.size(0), r.size(0), &e_emlrtECI, &b_st);
  }

  loop_ub = insideX.size(0);
  for (i = 0; i < loop_ub; i++) {
    insideX[i] = (insideX[i] && r[i]);
  }

  emlrtMEXProfilingStatement(15, static_cast<boolean_T>(isMexOutdated));
  insideY.set_size(&fe_emlrtRTEI, &b_st, calclen);
  for (i = 0; i < calclen; i++) {
    insideY[i] = (locations[i + locations.size(0)] < varargin_4[4]);
  }

  r.set_size(&ge_emlrtRTEI, &b_st, calclen);
  for (i = 0; i < calclen; i++) {
    r[i] = (locations[i + locations.size(0)] > varargin_4[1]);
  }

  if (insideY.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(insideY.size(0), r.size(0), &d_emlrtECI, &b_st);
  }

  loop_ub = insideY.size(0);
  for (i = 0; i < loop_ub; i++) {
    insideY[i] = (insideY[i] && r[i]);
  }

  emlrtMEXProfilingStatement(16, static_cast<boolean_T>(isMexOutdated));
  insideZ.set_size(&he_emlrtRTEI, &b_st, calclen);
  for (i = 0; i < calclen; i++) {
    insideZ[i] = (locations[i + locations.size(0) * 2] < varargin_4[5]);
  }

  r.set_size(&ie_emlrtRTEI, &b_st, calclen);
  for (i = 0; i < calclen; i++) {
    r[i] = (locations[i + locations.size(0) * 2] > varargin_4[2]);
  }

  if (insideZ.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(insideZ.size(0), r.size(0), &c_emlrtECI, &b_st);
  }

  loop_ub = insideZ.size(0);
  for (i = 0; i < loop_ub; i++) {
    insideZ[i] = (insideZ[i] && r[i]);
  }

  emlrtMEXProfilingStatement(17, static_cast<boolean_T>(isMexOutdated));
  if (insideX.size(0) != insideY.size(0)) {
    emlrtSizeEqCheck1DR2012b(insideX.size(0), insideY.size(0), &b_emlrtECI,
      &b_st);
  }

  loop_ub = insideX.size(0);
  for (i = 0; i < loop_ub; i++) {
    insideX[i] = (insideX[i] && insideY[i]);
  }

  if (insideX.size(0) != insideZ.size(0)) {
    emlrtSizeEqCheck1DR2012b(insideX.size(0), insideZ.size(0), &b_emlrtECI,
      &b_st);
  }

  loop_ub = insideX.size(0);
  for (i = 0; i < loop_ub; i++) {
    insideX[i] = (insideX[i] && insideZ[i]);
  }

  //  Remove ego vehicle
  //      nearIndices = findNeighborsInRadius(ptCloudIn,[0 0 0],egoVehicleRadius); 
  //      nonEgoIndices = true(ptCloudIn.Count,1);
  //      nonEgoIndices(nearIndices) = false;
  emlrtMEXProfilingStatement(18, static_cast<boolean_T>(isMexOutdated));

  // & nonEgoIndices;
  emlrtMEXProfilingStatement(19, static_cast<boolean_T>(isMexOutdated));
  c_st.site = &nb_emlrtRSI;
  d_st.site = &jf_emlrtRSI;
  coder::eml_find(&d_st, insideX, ii);
  survivedIndices.set_size(&je_emlrtRTEI, &c_st, ii.size(0));
  loop_ub = ii.size(0);
  for (i = 0; i < loop_ub; i++) {
    survivedIndices[i] = ii[i];
  }

  emlrtMEXProfilingStatement(20, static_cast<boolean_T>(isMexOutdated));
  c_st.site = &ob_emlrtRSI;
  loop_ub = insideX.size(0);
  for (i = 0; i < loop_ub; i++) {
    insideX[i] = !insideX[i];
  }

  d_st.site = &jf_emlrtRSI;
  coder::eml_find(&d_st, insideX, ii);
  varargout_4.set_size(&ke_emlrtRTEI, &c_st, ii.size(0));
  loop_ub = ii.size(0);
  for (i = 0; i < loop_ub; i++) {
    varargout_4[i] = ii[i];
  }

  emlrtMEXProfilingStatement(21, static_cast<boolean_T>(isMexOutdated));
  c_st.site = &sb_emlrtRSI;
  varargin_1->b_select(&c_st, survivedIndices, &pcSurvived);
  c_st.site = &pb_emlrtRSI;
  ptCloud_obs.matlabCodegenDestructor();
  emlrtMEXProfilingFunctionExitCPP(&b_profilerSentinel);
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  b_st.site = &lb_emlrtRSI;
  rot_tmp = this->GroundMaxDistance;
  trans[0] = this->GroundReferenceVector[0];
  trans[1] = this->GroundReferenceVector[1];
  trans[2] = this->GroundReferenceVector[2];
  b_rot_tmp = this->GroundMaxAngularDistance;
  for (i = 0; i < 6; i++) {
    b_roi[i] = this->roi[i];
  }

  emlrtMEXProfilingFunctionEntryCPP(removeGroundPlane_complete_name,
    static_cast<boolean_T>(isMexOutdated), &c_profilerSentinel);
  emlrtMEXProfilingStatement(1, static_cast<boolean_T>(isMexOutdated));
  c_st.site = &tf_emlrtRSI;
  pcSurvived.findPointsInROI(&c_st, b_roi, sampleIndices);
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  c_st.site = &uf_emlrtRSI;
  coder::pcfitplane(&c_st, &pcSurvived, rot_tmp, trans, b_rot_tmp, sampleIndices,
                    &unusedU0, &r1, groundIndices, outliers);
  emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
  c_st.site = &vf_emlrtRSI;
  pcSurvived.b_select(&c_st, outliers, &pcObstacles);
  emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));
  varargout_2.set_size(&le_emlrtRTEI, &b_st, outliers.size(0));
  loop_ub = outliers.size(0);
  for (i = 0; i < loop_ub; i++) {
    nx = static_cast<int32_T>(outliers[i]);
    if ((nx < 1) || (nx > survivedIndices.size(0))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, survivedIndices.size(0), &j_emlrtBCI,
        &b_st);
    }

    varargout_2[i] = survivedIndices[nx - 1];
  }

  emlrtMEXProfilingStatement(5, static_cast<boolean_T>(isMexOutdated));
  varargout_3.set_size(&me_emlrtRTEI, &b_st, groundIndices.size(0));
  loop_ub = groundIndices.size(0);
  for (i = 0; i < loop_ub; i++) {
    nx = static_cast<int32_T>(groundIndices[i]);
    if ((nx < 1) || (nx > survivedIndices.size(0))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, survivedIndices.size(0), &k_emlrtBCI,
        &b_st);
    }

    varargout_3[i] = survivedIndices[nx - 1];
  }

  emlrtMEXProfilingStatement(6, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingFunctionExitCPP(&c_profilerSentinel);
  emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
  b_st.site = &hb_emlrtRSI;
  HelperBoundingBoxDetector::getBoundingBoxes(&b_st, &pcObstacles,
    this->SegmentationMinDistance, this->MinDetectionsPerCluster,
    this->MaxZDistanceCluster, this->MinZDistanceCluster, varargin_3_X,
    varargin_3_Y, varargin_3_yaw, varargin_2, varargin_6, detBBoxes, varargout_5,
    varargout_6);
  emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(8, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(9, static_cast<boolean_T>(isMexOutdated));
  b_st.site = &ib_emlrtRSI;
  for (i = 0; i < 9; i++) {
    c_rot_tmp[i] = this->MeasurementNoise[i];
  }

  emlrtMEXProfilingFunctionEntryCPP(c_assembleDetections_complete_n,
    static_cast<boolean_T>(isMexOutdated), &d_profilerSentinel);
  emlrtMEXProfilingStatement(1, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  varargout_1.set_size(&ne_emlrtRTEI, &b_st, detBBoxes.size(1), 1);
  emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
  i = detBBoxes.size(1);
  for (nx = 0; nx < i; nx++) {
    emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(5, static_cast<boolean_T>(isMexOutdated));
    if ((nx + 1 < 1) || (nx + 1 > detBBoxes.size(1))) {
      emlrtDynamicBoundsCheckR2012b(nx + 1, 1, detBBoxes.size(1), &i_emlrtBCI,
        &b_st);
    }

    if (nx > varargout_1.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(nx, 0, varargout_1.size(0) - 1, &l_emlrtBCI,
        &b_st);
    }

    c_st.site = &xn_emlrtRSI;
    varargout_1[nx].init(&c_st, varargin_2, *(real_T (*)[3])&detBBoxes[3 * nx],
                         c_rot_tmp);
    emlrtMEXProfilingStatement(7, static_cast<boolean_T>(isMexOutdated));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&b_st);
    }
  }

  emlrtMEXProfilingStatement(8, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingFunctionExitCPP(&d_profilerSentinel);
  b_st.site = &jb_emlrtRSI;
  pcSurvived.matlabCodegenDestructor();
  b_st.site = &jb_emlrtRSI;
  pcObstacles.matlabCodegenDestructor();
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (HelperBoundingBoxDetector.cpp)
