//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pointCloud.cpp
//
//  Code generation for function 'pointCloud'
//


// Include files
#include "pointCloud.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "PCANormalCore_api.hpp"
#include "coder_array.h"
#include "cvstCG_ComputeMetric.h"
#include "cvstCG_kdtree.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ab_emlrtRSI = { 27, // lineNo
  "pointCloud/pointCloud",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo bb_emlrtRSI = { 37, // lineNo
  "pointCloud/pointCloud",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo db_emlrtRSI = { 87, // lineNo
  "pointCloudBase/pointCloudBase",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo eb_emlrtRSI = { 88, // lineNo
  "pointCloudBase/pointCloudBase",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo fb_emlrtRSI = { 89, // lineNo
  "pointCloudBase/pointCloudBase",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo gb_emlrtRSI = { 90, // lineNo
  "pointCloudBase/pointCloudBase",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo bf_emlrtRSI = { 383,// lineNo
  "pointCloud/surfaceNormalImpl",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo cf_emlrtRSI = { 398,// lineNo
  "pointCloud/surfaceNormalImpl",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo df_emlrtRSI = { 408,// lineNo
  "pointCloud/surfaceNormalImpl",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo ef_emlrtRSI = { 462,// lineNo
  "pointCloud/buildKdtree",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo hf_emlrtRSI = { 480,// lineNo
  "pointCloud/buildKdtree",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo of_emlrtRSI = { 161,// lineNo
  "pointCloud/select",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo pf_emlrtRSI = { 202,// lineNo
  "pointCloud/select",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo qf_emlrtRSI = { 204,// lineNo
  "pointCloud/select",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo rf_emlrtRSI = { 206,// lineNo
  "pointCloud/select",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo sf_emlrtRSI = { 256,// lineNo
  "pointCloudBase/subsetImpl",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo wf_emlrtRSI = { 130,// lineNo
  "pointCloud/findPointsInROI",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo xf_emlrtRSI = { 360,// lineNo
  "pointCloudBase/findPointsInROIImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo yf_emlrtRSI = { 362,// lineNo
  "pointCloudBase/findPointsInROIImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo ag_emlrtRSI = { 364,// lineNo
  "pointCloudBase/findPointsInROIImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo bg_emlrtRSI = { 373,// lineNo
  "pointCloudBase/findPointsInROIImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo cg_emlrtRSI = { 811,// lineNo
  "pointCloud/validateAndParseBoxSearchOption",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo dg_emlrtRSI = { 611,// lineNo
  "pointCloudBase/validateROI",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo eg_emlrtRSI = { 536,// lineNo
  "pointCloudBase/bruteForceBoxSearch",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo fg_emlrtRSI = { 591,// lineNo
  "pointCloud/kdtreeBoxSearch",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo gg_emlrtRSI = { 593,// lineNo
  "pointCloud/kdtreeBoxSearch",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo hg_emlrtRSI = { 604,// lineNo
  "pointCloud/kdtreeBoxSearch",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo pi_emlrtRSI = { 212,// lineNo
  "pointCloud/removeInvalidPoints",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo qi_emlrtRSI = { 215,// lineNo
  "pointCloud/removeInvalidPoints",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo ri_emlrtRSI = { 217,// lineNo
  "pointCloud/removeInvalidPoints",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo si_emlrtRSI = { 221,// lineNo
  "pointCloud/removeInvalidPoints",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo ti_emlrtRSI = { 259,// lineNo
  "pointCloud/extractValidPoints",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo ui_emlrtRSI = { 265,// lineNo
  "pointCloud/extractValidPoints",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo vi_emlrtRSI = { 385,// lineNo
  "pointCloudBase/extractValidPointsImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo sk_emlrtRSI = { 16, // lineNo
  "sqrt",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/sqrt.m"// pathName
};

static emlrtRSInfo pm_emlrtRSI = { 73, // lineNo
  "pointCloud/findNeighborsInRadius",  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo qm_emlrtRSI = { 313,// lineNo
  "pointCloudBase/findNeighborsInRadiusImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo rm_emlrtRSI = { 320,// lineNo
  "pointCloudBase/findNeighborsInRadiusImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo sm_emlrtRSI = { 322,// lineNo
  "pointCloudBase/findNeighborsInRadiusImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo tm_emlrtRSI = { 337,// lineNo
  "pointCloudBase/findNeighborsInRadiusImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo um_emlrtRSI = { 348,// lineNo
  "pointCloudBase/findNeighborsInRadiusImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo vm_emlrtRSI = { 848,// lineNo
  "pointCloud/validateAndParseRadiusSearchOption",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo wm_emlrtRSI = { 854,// lineNo
  "pointCloud/validateAndParseRadiusSearchOption",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo xm_emlrtRSI = { 580,// lineNo
  "pointCloudBase/validateQueryPoint", // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo ym_emlrtRSI = { 605,// lineNo
  "pointCloudBase/validateRadius",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo an_emlrtRSI = { 507,// lineNo
  "pointCloudBase/bruteForceRadiusSearch",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo bn_emlrtRSI = { 509,// lineNo
  "pointCloudBase/bruteForceRadiusSearch",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo cn_emlrtRSI = { 514,// lineNo
  "pointCloudBase/bruteForceRadiusSearch",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pathName 
};

static emlrtRSInfo dn_emlrtRSI = { 509,// lineNo
  "pointCloud/bruteForce",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo en_emlrtRSI = { 571,// lineNo
  "pointCloud/kdtreeRadiusSearch",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRSInfo fn_emlrtRSI = { 573,// lineNo
  "pointCloud/kdtreeRadiusSearch",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pathName 
};

static emlrtRTEInfo b_emlrtRTEI = { 137,// lineNo
  13,                                  // colNo
  "pointCloudBase/set.Color",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo c_emlrtRTEI = { 151,// lineNo
  13,                                  // colNo
  "pointCloudBase/set.Normal",         // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo d_emlrtRTEI = { 174,// lineNo
  21,                                  // colNo
  "pointCloudBase/set.Intensity",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo e_emlrtRTEI = { 195,// lineNo
  13,                                  // colNo
  "pointCloudBase/set.RangeData",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo p_emlrtRTEI = { 69,// lineNo
  13,                                  // colNo
  "kdtreeBuildable/kdtreeIndex",       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/kdtreeBuildable.m"// pName 
};

static emlrtBCInfo m_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  1,                                   // lineNo
  1,                                   // colNo
  "",                                  // aName
  "getSubset",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+pc/getSubset.p",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo t_emlrtRTEI = { 838,// lineNo
  17,                                  // colNo
  "pointCloud/validateAndParseBoxSearchOption",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pName 
};

static emlrtECInfo i_emlrtECI = { -1,  // nDims
  533,                                 // lineNo
  22,                                  // colNo
  "pointCloudBase/bruteForceBoxSearch",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtDCInfo emlrtDCI = { 112,   // lineNo
  44,                                  // colNo
  "kdtreeBuildable/kdtreeBoxSearch",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/kdtreeBuildable.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo g_emlrtDCI = { 214, // lineNo
  45,                                  // colNo
  "kdtreeBuildable/kdtreeRadiusSearch",// fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/kdtreeBuildable.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo fc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  514,                                 // lineNo
  36,                                  // colNo
  "",                                  // aName
  "pointCloudBase/bruteForceRadiusSearch",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo gc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  519,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "pointCloudBase/bruteForceRadiusSearch",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  520,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "pointCloudBase/bruteForceRadiusSearch",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo vd_emlrtRTEI = { 85,// lineNo
  13,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo wd_emlrtRTEI = { 142,// lineNo
  13,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo xd_emlrtRTEI = { 157,// lineNo
  13,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo yd_emlrtRTEI = { 185,// lineNo
  17,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo ae_emlrtRTEI = { 201,// lineNo
  13,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo xe_emlrtRTEI = { 389,// lineNo
  17,                                  // colNo
  "pointCloud",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pName 
};

static emlrtRTEInfo ye_emlrtRTEI = { 399,// lineNo
  47,                                  // colNo
  "pointCloud",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pName 
};

static emlrtRTEInfo af_emlrtRTEI = { 151,// lineNo
  38,                                  // colNo
  "kdtreeBuildable",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/kdtreeBuildable.m"// pName 
};

static emlrtRTEInfo bf_emlrtRTEI = { 152,// lineNo
  36,                                  // colNo
  "kdtreeBuildable",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/kdtreeBuildable.m"// pName 
};

static emlrtRTEInfo cf_emlrtRTEI = { 153,// lineNo
  36,                                  // colNo
  "kdtreeBuildable",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/kdtreeBuildable.m"// pName 
};

static emlrtRTEInfo df_emlrtRTEI = { 49,// lineNo
  17,                                  // colNo
  "PCANormalBuildable",                // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/PCANormalBuildable.m"// pName 
};

static emlrtRTEInfo ef_emlrtRTEI = { 408,// lineNo
  13,                                  // colNo
  "pointCloud",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pName 
};

static emlrtRTEInfo ff_emlrtRTEI = { 378,// lineNo
  17,                                  // colNo
  "pointCloud",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pName 
};

static emlrtRTEInfo gf_emlrtRTEI = { 462,// lineNo
  110,                                 // colNo
  "pointCloud",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pName 
};

static emlrtRTEInfo jf_emlrtRTEI = { 1,// lineNo
  1,                                   // colNo
  "getSubset",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+pc/getSubset.p"// pName 
};

static emlrtRTEInfo kf_emlrtRTEI = { 112,// lineNo
  38,                                  // colNo
  "kdtreeBuildable",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/kdtreeBuildable.m"// pName 
};

static emlrtRTEInfo lf_emlrtRTEI = { 533,// lineNo
  22,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo mf_emlrtRTEI = { 533,// lineNo
  49,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo nf_emlrtRTEI = { 534,// lineNo
  22,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo of_emlrtRTEI = { 534,// lineNo
  49,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo pf_emlrtRTEI = { 535,// lineNo
  22,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo qf_emlrtRTEI = { 535,// lineNo
  49,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo rf_emlrtRTEI = { 130,// lineNo
  17,                                  // colNo
  "pointCloud",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pName 
};

static emlrtRTEInfo gg_emlrtRTEI = { 221,// lineNo
  21,                                  // colNo
  "pointCloud",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pName 
};

static emlrtRTEInfo jg_emlrtRTEI = { 382,// lineNo
  13,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo mg_emlrtRTEI = { 259,// lineNo
  17,                                  // colNo
  "pointCloud",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/+codegen/+pc/pointCloud.m"// pName 
};

static emlrtRTEInfo ng_emlrtRTEI = { 256,// lineNo
  13,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo ih_emlrtRTEI = { 214,// lineNo
  39,                                  // colNo
  "kdtreeBuildable",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/kdtreeBuildable.m"// pName 
};

static emlrtRTEInfo jh_emlrtRTEI = { 215,// lineNo
  37,                                  // colNo
  "kdtreeBuildable",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/kdtreeBuildable.m"// pName 
};

static emlrtRTEInfo kh_emlrtRTEI = { 507,// lineNo
  13,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo lh_emlrtRTEI = { 43,// lineNo
  21,                                  // colNo
  "ComputeMetricBuildable",            // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+buildable/ComputeMetricBuildable.m"// pName 
};

static emlrtRTEInfo mh_emlrtRTEI = { 509,// lineNo
  35,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo nh_emlrtRTEI = { 509,// lineNo
  13,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo oh_emlrtRTEI = { 514,// lineNo
  17,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo ph_emlrtRTEI = { 322,// lineNo
  17,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

static emlrtRTEInfo qh_emlrtRTEI = { 512,// lineNo
  17,                                  // colNo
  "pointCloudBase",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/pointclouds/+pointclouds/+internal/pointCloudBase.m"// pName 
};

// Function Definitions
namespace coder
{
  void b_pointCloud::b_subsetImpl(const emlrtStack *sp, const ::coder::array<
    boolean_T, 1U> &indices, ::coder::array<real32_T, 2U> &loc, ::coder::array<
    uint8_T, 2U> &c, ::coder::array<real32_T, 2U> &nv, ::coder::array<real32_T,
    2U> &intensity, ::coder::array<real32_T, 2U> &r) const
  {
    array<int32_T, 1U> b_r;
    array<int32_T, 1U> r1;
    array<int32_T, 1U> r2;
    array<int32_T, 1U> r3;
    array<int32_T, 1U> r4;
    emlrtStack st;
    int32_T b_i;
    int32_T end;
    int32_T i;
    int32_T i1;
    int32_T trueCount;
    st.prev = sp;
    st.tls = sp->tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &sf_emlrtRSI;
    if (this->Location.size(0) != 0) {
      end = indices.size(0) - 1;
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          trueCount++;
        }
      }

      b_r.set_size(&ng_emlrtRTEI, &st, trueCount);
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          b_r[trueCount] = i + 1;
          trueCount++;
        }
      }

      trueCount = this->Location.size(0);
      loc.set_size(&jf_emlrtRTEI, &st, b_r.size(0), 3);
      end = b_r.size(0);
      for (b_i = 0; b_i < 3; b_i++) {
        for (i1 = 0; i1 < end; i1++) {
          if ((b_r[i1] < 1) || (b_r[i1] > trueCount)) {
            emlrtDynamicBoundsCheckR2012b(b_r[i1], 1, trueCount, &m_emlrtBCI,
              &st);
          }

          loc[i1 + loc.size(0) * b_i] = this->Location[(b_r[i1] +
            this->Location.size(0) * b_i) - 1];
        }
      }
    } else {
      loc.set_size(&jf_emlrtRTEI, &st, 0, 3);
    }

    if ((this->Color.size(0) != 0) && (this->Color.size(1) != 0)) {
      end = indices.size(0) - 1;
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          trueCount++;
        }
      }

      r1.set_size(&ng_emlrtRTEI, &st, trueCount);
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          r1[trueCount] = i + 1;
          trueCount++;
        }
      }

      trueCount = this->Color.size(0);
      end = this->Color.size(1);
      c.set_size(&jf_emlrtRTEI, &st, r1.size(0), end);
      for (b_i = 0; b_i < end; b_i++) {
        i = r1.size(0);
        for (i1 = 0; i1 < i; i1++) {
          if ((r1[i1] < 1) || (r1[i1] > trueCount)) {
            emlrtDynamicBoundsCheckR2012b(r1[i1], 1, trueCount, &m_emlrtBCI, &st);
          }

          c[i1 + c.size(0) * b_i] = this->Color[(r1[i1] + this->Color.size(0) *
            b_i) - 1];
        }
      }
    } else {
      c.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    if ((this->Normal.size(0) != 0) && (this->Normal.size(1) != 0)) {
      end = indices.size(0) - 1;
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          trueCount++;
        }
      }

      r2.set_size(&ng_emlrtRTEI, &st, trueCount);
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          r2[trueCount] = i + 1;
          trueCount++;
        }
      }

      trueCount = this->Normal.size(0);
      end = this->Normal.size(1);
      nv.set_size(&jf_emlrtRTEI, &st, r2.size(0), end);
      for (b_i = 0; b_i < end; b_i++) {
        i = r2.size(0);
        for (i1 = 0; i1 < i; i1++) {
          if ((r2[i1] < 1) || (r2[i1] > trueCount)) {
            emlrtDynamicBoundsCheckR2012b(r2[i1], 1, trueCount, &m_emlrtBCI, &st);
          }

          nv[i1 + nv.size(0) * b_i] = this->Normal[(r2[i1] + this->Normal.size(0)
            * b_i) - 1];
        }
      }
    } else {
      nv.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    if ((this->Intensity.size(0) != 0) && (this->Intensity.size(1) != 0)) {
      end = indices.size(0) - 1;
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          trueCount++;
        }
      }

      r3.set_size(&ng_emlrtRTEI, &st, trueCount);
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          r3[trueCount] = i + 1;
          trueCount++;
        }
      }

      trueCount = this->Intensity.size(0);
      end = this->Intensity.size(1);
      intensity.set_size(&jf_emlrtRTEI, &st, r3.size(0), end);
      for (b_i = 0; b_i < end; b_i++) {
        i = r3.size(0);
        for (i1 = 0; i1 < i; i1++) {
          if ((r3[i1] < 1) || (r3[i1] > trueCount)) {
            emlrtDynamicBoundsCheckR2012b(r3[i1], 1, trueCount, &m_emlrtBCI, &st);
          }

          intensity[i1 + intensity.size(0) * b_i] = this->Intensity[(r3[i1] +
            this->Intensity.size(0) * b_i) - 1];
        }
      }
    } else {
      intensity.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    if ((this->RangeData.size(0) != 0) && (this->RangeData.size(1) != 0)) {
      end = indices.size(0) - 1;
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          trueCount++;
        }
      }

      r4.set_size(&ng_emlrtRTEI, &st, trueCount);
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (indices[i]) {
          r4[trueCount] = i + 1;
          trueCount++;
        }
      }

      trueCount = this->RangeData.size(0);
      end = this->RangeData.size(1);
      r.set_size(&jf_emlrtRTEI, &st, r4.size(0), end);
      for (b_i = 0; b_i < end; b_i++) {
        i = r4.size(0);
        for (i1 = 0; i1 < i; i1++) {
          if ((r4[i1] < 1) || (r4[i1] > trueCount)) {
            emlrtDynamicBoundsCheckR2012b(r4[i1], 1, trueCount, &m_emlrtBCI, &st);
          }

          r[i1 + r.size(0) * b_i] = this->RangeData[(r4[i1] +
            this->RangeData.size(0) * b_i) - 1];
        }
      }
    } else {
      r.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void b_pointCloud::buildKdtree(const emlrtStack *sp)
  {
    array<real32_T, 2U> location;
    emlrtStack st;
    boolean_T createIndex;
    st.prev = sp;
    st.tls = sp->tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    if (!this->HasLocationHandleAllocated) {
      int32_T loop_ub;
      st.site = &ef_emlrtRSI;
      location.set_size(&gf_emlrtRTEI, &st, this->Location.size(0), 3);
      loop_ub = this->Location.size(0) * this->Location.size(1);
      for (int32_T i = 0; i < loop_ub; i++) {
        location[i] = this->Location[i];
      }

      this->LocationHandle = NULL;
      if (location.size(0) != 0) {
        kdtreeGetLocationDataPointer_single(&location[0], static_cast<uint32_T>
          (location.size(0)), 3U, &this->LocationHandle);
      }

      this->HasLocationHandleAllocated = true;
    }

    if (!this->HasKdtreeConstructed) {
      this->Kdtree = NULL;
      kdtreeConstruct_single(&this->Kdtree);
      this->HasKdtreeConstructed = true;
      createIndex = true;
    } else {
      createIndex = kdtreeNeedsReindex_single(this->Kdtree, this->LocationHandle);
    }

    if (createIndex) {
      real_T dataSize;
      uint32_T u;
      st.site = &hf_emlrtRSI;
      dataSize = this->get_Count();
      if (dataSize == 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &p_emlrtRTEI,
          "vision:ocvShared:emptyInput", "vision:ocvShared:emptyInput", 0);
      }

      dataSize = muDoubleScalarRound(dataSize);
      if (dataSize < 4.294967296E+9) {
        if (dataSize >= 0.0) {
          u = static_cast<uint32_T>(dataSize);
        } else {
          u = 0U;
        }
      } else if (dataSize >= 4.294967296E+9) {
        u = MAX_uint32_T;
      } else {
        u = 0U;
      }

      kdtreeIndex_single(this->Kdtree, this->LocationHandle, u, 3U, 4.0, 1.0,
                         0.0);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void b_pointCloud::extractValidPoints(const emlrtStack *sp, ::coder::array<
    real32_T, 2U> &location, ::coder::array<uint8_T, 2U> &color, ::coder::array<
    real32_T, 2U> &normals, ::coder::array<real32_T, 2U> &intensity, ::coder::
    array<real32_T, 2U> &rangeData, ::coder::array<boolean_T, 1U> &indices)
    const
  {
    array<int32_T, 1U> nz;
    array<boolean_T, 2U> r;
    array<boolean_T, 2U> tf;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack g_st;
    emlrtStack st;
    int32_T vstride;
    int32_T xoffset;
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
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &ti_emlrtRSI;
    tf.set_size(&hg_emlrtRTEI, &st, this->Location.size(0), 3);
    vstride = this->Location.size(0) * this->Location.size(1);
    for (xoffset = 0; xoffset < vstride; xoffset++) {
      tf[xoffset] = muSingleScalarIsInf(this->Location[xoffset]);
    }

    r.set_size(&ig_emlrtRTEI, &st, this->Location.size(0), 3);
    vstride = this->Location.size(0) * this->Location.size(1);
    for (xoffset = 0; xoffset < vstride; xoffset++) {
      r[xoffset] = muSingleScalarIsNaN(this->Location[xoffset]);
    }

    vstride = tf.size(0) * tf.size(1);
    tf.set_size(&jg_emlrtRTEI, &st, tf.size(0), 3);
    for (xoffset = 0; xoffset < vstride; xoffset++) {
      tf[xoffset] = ((!tf[xoffset]) && (!r[xoffset]));
    }

    b_st.site = &vi_emlrtRSI;
    c_st.site = &wi_emlrtRSI;
    d_st.site = &xi_emlrtRSI;
    if (tf.size(0) == 0) {
      nz.set_size(&lg_emlrtRTEI, &d_st, 0);
    } else {
      int32_T j;
      boolean_T overflow;
      e_st.site = &yi_emlrtRSI;
      vstride = tf.size(0);
      nz.set_size(&kg_emlrtRTEI, &e_st, tf.size(0));
      f_st.site = &aj_emlrtRSI;
      if (tf.size(0) > 2147483646) {
        g_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (j = 0; j < vstride; j++) {
        nz[j] = tf[j];
      }

      overflow = (tf.size(0) > 2147483646);
      f_st.site = &bj_emlrtRSI;
      if (overflow) {
        g_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (j = 0; j < vstride; j++) {
        nz[j] = nz[j] + tf[vstride + j];
      }

      xoffset = 2 * tf.size(0);
      f_st.site = &bj_emlrtRSI;
      for (j = 0; j < vstride; j++) {
        nz[j] = nz[j] + tf[xoffset + j];
      }
    }

    indices.set_size(&mg_emlrtRTEI, &st, nz.size(0));
    vstride = nz.size(0);
    for (xoffset = 0; xoffset < vstride; xoffset++) {
      indices[xoffset] = (nz[xoffset] == 3);
    }

    st.site = &ui_emlrtRSI;
    this->b_subsetImpl(&st, indices, location, color, normals, intensity,
                       rangeData);
    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void b_pointCloud::set_Color(const emlrtStack *sp, const ::coder::array<
    uint8_T, 2U> &value)
  {
    int32_T varargin_2[2];
    int32_T k;
    uint32_T varargin_1[2];
    if ((value.size(0) != 0) && (value.size(1) != 0)) {
      boolean_T b_p;
      boolean_T exitg1;
      boolean_T p;
      varargin_1[0] = static_cast<uint32_T>(value.size(0));
      varargin_2[0] = this->Location.size(0);
      varargin_1[1] = static_cast<uint32_T>(value.size(1));
      varargin_2[1] = this->Location.size(1);
      p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (static_cast<int32_T>(varargin_1[k]) != varargin_2[k]) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }

      b_p = p;
      if (!b_p) {
        emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI,
          "vision:pointcloud:unmatchedXYZColor",
          "vision:pointcloud:unmatchedXYZColor", 0);
      }
    }

    this->Color.set_size(&wd_emlrtRTEI, sp, value.size(0), value.size(1));
    k = value.size(0) * value.size(1);
    for (int32_T i = 0; i < k; i++) {
      this->Color[i] = value[i];
    }
  }

  void b_pointCloud::set_Intensity(const emlrtStack *sp, const ::coder::array<
    real32_T, 2U> &value)
  {
    int32_T loop_ub;
    if ((value.size(0) != 0) && (value.size(1) != 0) && ((value.size(1) != 1) ||
         (value.size(0) != this->Location.size(0)) || (value.size(1) != 1))) {
      emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
        "vision:pointcloud:unmatchedXYZIntensity",
        "vision:pointcloud:unmatchedXYZIntensity", 0);
    }

    this->Intensity.set_size(&yd_emlrtRTEI, sp, value.size(0), value.size(1));
    loop_ub = value.size(0) * value.size(1);
    for (int32_T i = 0; i < loop_ub; i++) {
      this->Intensity[i] = value[i];
    }
  }

  void b_pointCloud::set_Normal(const emlrtStack *sp, const ::coder::array<
    real32_T, 2U> &value)
  {
    int32_T varargin_2[2];
    int32_T k;
    uint32_T varargin_1[2];
    if ((value.size(0) != 0) && (value.size(1) != 0)) {
      boolean_T b_p;
      boolean_T exitg1;
      boolean_T p;
      varargin_1[0] = static_cast<uint32_T>(value.size(0));
      varargin_2[0] = this->Location.size(0);
      varargin_1[1] = static_cast<uint32_T>(value.size(1));
      varargin_2[1] = this->Location.size(1);
      p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (static_cast<int32_T>(varargin_1[k]) != varargin_2[k]) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }

      b_p = p;
      if (!b_p) {
        emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
          "vision:pointcloud:unmatchedXYZNormal",
          "vision:pointcloud:unmatchedXYZNormal", 0);
      }
    }

    this->Normal.set_size(&xd_emlrtRTEI, sp, value.size(0), value.size(1));
    k = value.size(0) * value.size(1);
    for (int32_T i = 0; i < k; i++) {
      this->Normal[i] = value[i];
    }
  }

  void b_pointCloud::set_RangeData(const emlrtStack *sp, const ::coder::array<
    real32_T, 2U> &value)
  {
    int32_T varargin_2[2];
    int32_T k;
    uint32_T varargin_1[2];
    if ((value.size(0) != 0) && (value.size(1) != 0)) {
      boolean_T b_p;
      boolean_T exitg1;
      boolean_T p;
      varargin_1[0] = static_cast<uint32_T>(value.size(0));
      varargin_2[0] = this->Location.size(0);
      varargin_1[1] = static_cast<uint32_T>(value.size(1));
      varargin_2[1] = this->Location.size(1);
      p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (static_cast<int32_T>(varargin_1[k]) != varargin_2[k]) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }

      b_p = p;
      if (!b_p) {
        emlrtErrorWithMessageIdR2018a(sp, &e_emlrtRTEI,
          "vision:pointcloud:unmatchedXYZRange",
          "vision:pointcloud:unmatchedXYZRange", 0);
      }
    }

    this->RangeData.set_size(&ae_emlrtRTEI, sp, value.size(0), value.size(1));
    k = value.size(0) * value.size(1);
    for (int32_T i = 0; i < k; i++) {
      this->RangeData[i] = value[i];
    }
  }

  void b_pointCloud::subsetImpl(const emlrtStack *sp, const ::coder::array<
    real_T, 2U> &indices, ::coder::array<real32_T, 2U> &loc, ::coder::array<
    uint8_T, 2U> &c, ::coder::array<real32_T, 2U> &nv, ::coder::array<real32_T,
    2U> &intensity, ::coder::array<real32_T, 2U> &r) const
  {
    emlrtStack st;
    int32_T b_loop_ub;
    int32_T b_this;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T loop_ub;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &sf_emlrtRSI;
    if (this->Location.size(0) != 0) {
      b_this = this->Location.size(0);
      loc.set_size(&jf_emlrtRTEI, &st, indices.size(0), 3);
      loop_ub = indices.size(0);
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          loc[i1 + loc.size(0) * i] = this->Location[(i2 + this->Location.size(0)
            * i) - 1];
        }
      }
    } else {
      loc.set_size(&jf_emlrtRTEI, &st, 0, 3);
    }

    if ((this->Color.size(0) != 0) && (this->Color.size(1) != 0)) {
      b_this = this->Color.size(0);
      loop_ub = this->Color.size(1);
      c.set_size(&jf_emlrtRTEI, &st, indices.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = indices.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          c[i1 + c.size(0) * i] = this->Color[(i2 + this->Color.size(0) * i) - 1];
        }
      }
    } else {
      c.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    if ((this->Normal.size(0) != 0) && (this->Normal.size(1) != 0)) {
      b_this = this->Normal.size(0);
      loop_ub = this->Normal.size(1);
      nv.set_size(&jf_emlrtRTEI, &st, indices.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = indices.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          nv[i1 + nv.size(0) * i] = this->Normal[(i2 + this->Normal.size(0) * i)
            - 1];
        }
      }
    } else {
      nv.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    if ((this->Intensity.size(0) != 0) && (this->Intensity.size(1) != 0)) {
      b_this = this->Intensity.size(0);
      loop_ub = this->Intensity.size(1);
      intensity.set_size(&jf_emlrtRTEI, &st, indices.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = indices.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          intensity[i1 + intensity.size(0) * i] = this->Intensity[(i2 +
            this->Intensity.size(0) * i) - 1];
        }
      }
    } else {
      intensity.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    if ((this->RangeData.size(0) != 0) && (this->RangeData.size(1) != 0)) {
      b_this = this->RangeData.size(0);
      loop_ub = this->RangeData.size(1);
      r.set_size(&jf_emlrtRTEI, &st, indices.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = indices.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          r[i1 + r.size(0) * i] = this->RangeData[(i2 + this->RangeData.size(0) *
            i) - 1];
        }
      }
    } else {
      r.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }
  }

  void b_pointCloud::subsetImpl(const emlrtStack *sp, const ::coder::array<
    real_T, 1U> &indices, ::coder::array<real32_T, 2U> &loc, ::coder::array<
    uint8_T, 2U> &c, ::coder::array<real32_T, 2U> &nv, ::coder::array<real32_T,
    2U> &intensity, ::coder::array<real32_T, 2U> &r) const
  {
    emlrtStack st;
    int32_T b_loop_ub;
    int32_T b_this;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T loop_ub;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &sf_emlrtRSI;
    if (this->Location.size(0) != 0) {
      b_this = this->Location.size(0);
      loc.set_size(&jf_emlrtRTEI, &st, indices.size(0), 3);
      loop_ub = indices.size(0);
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          loc[i1 + loc.size(0) * i] = this->Location[(i2 + this->Location.size(0)
            * i) - 1];
        }
      }
    } else {
      loc.set_size(&jf_emlrtRTEI, &st, 0, 3);
    }

    if ((this->Color.size(0) != 0) && (this->Color.size(1) != 0)) {
      b_this = this->Color.size(0);
      loop_ub = this->Color.size(1);
      c.set_size(&jf_emlrtRTEI, &st, indices.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = indices.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          c[i1 + c.size(0) * i] = this->Color[(i2 + this->Color.size(0) * i) - 1];
        }
      }
    } else {
      c.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    if ((this->Normal.size(0) != 0) && (this->Normal.size(1) != 0)) {
      b_this = this->Normal.size(0);
      loop_ub = this->Normal.size(1);
      nv.set_size(&jf_emlrtRTEI, &st, indices.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = indices.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          nv[i1 + nv.size(0) * i] = this->Normal[(i2 + this->Normal.size(0) * i)
            - 1];
        }
      }
    } else {
      nv.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    if ((this->Intensity.size(0) != 0) && (this->Intensity.size(1) != 0)) {
      b_this = this->Intensity.size(0);
      loop_ub = this->Intensity.size(1);
      intensity.set_size(&jf_emlrtRTEI, &st, indices.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = indices.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          intensity[i1 + intensity.size(0) * i] = this->Intensity[(i2 +
            this->Intensity.size(0) * i) - 1];
        }
      }
    } else {
      intensity.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }

    if ((this->RangeData.size(0) != 0) && (this->RangeData.size(1) != 0)) {
      b_this = this->RangeData.size(0);
      loop_ub = this->RangeData.size(1);
      r.set_size(&jf_emlrtRTEI, &st, indices.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = indices.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          i2 = static_cast<int32_T>(indices[i1]);
          if ((i2 < 1) || (i2 > b_this)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &m_emlrtBCI, &st);
          }

          r[i1 + r.size(0) * i] = this->RangeData[(i2 + this->RangeData.size(0) *
            i) - 1];
        }
      }
    } else {
      r.set_size(&jf_emlrtRTEI, &st, 0, 0);
    }
  }

  b_pointCloud *b_pointCloud::b_select(const emlrtStack *sp, const ::coder::
    array<real_T, 1U> &varargin_1, b_pointCloud *iobj_0) const
  {
    b_pointCloud *ptCloudOut;
    array<real32_T, 2U> intensity;
    array<real32_T, 2U> loc;
    array<real32_T, 2U> nv;
    array<real32_T, 2U> r;
    array<uint8_T, 2U> c;
    emlrtStack b_st;
    emlrtStack st;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &of_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= varargin_1.size(0) - 1)) {
      if ((!muDoubleScalarIsInf(varargin_1[k])) && (!muDoubleScalarIsNaN
           (varargin_1[k])) && (muDoubleScalarFloor(varargin_1[k]) ==
           varargin_1[k])) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &s_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:expectedInteger", 3, 4, 5, "input");
    }

    st.site = &pf_emlrtRSI;
    this->subsetImpl(&st, varargin_1, loc, c, nv, intensity, r);
    st.site = &qf_emlrtRSI;
    ptCloudOut = iobj_0->init(&st, loc, c, nv, intensity);
    st.site = &rf_emlrtRSI;
    ptCloudOut->set_RangeData(&st, r);
    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    return ptCloudOut;
  }

  b_pointCloud *b_pointCloud::b_select(const emlrtStack *sp, const ::coder::
    array<real_T, 2U> &varargin_1, b_pointCloud *iobj_0) const
  {
    b_pointCloud *ptCloudOut;
    array<real32_T, 2U> intensity;
    array<real32_T, 2U> loc;
    array<real32_T, 2U> nv;
    array<real32_T, 2U> r;
    array<uint8_T, 2U> c;
    emlrtStack b_st;
    emlrtStack st;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &of_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= varargin_1.size(0) - 1)) {
      if ((!muDoubleScalarIsInf(varargin_1[k])) && (!muDoubleScalarIsNaN
           (varargin_1[k])) && (muDoubleScalarFloor(varargin_1[k]) ==
           varargin_1[k])) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &s_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:expectedInteger", 3, 4, 5, "input");
    }

    st.site = &pf_emlrtRSI;
    this->subsetImpl(&st, varargin_1, loc, c, nv, intensity, r);
    st.site = &qf_emlrtRSI;
    ptCloudOut = iobj_0->init(&st, loc, c, nv, intensity);
    st.site = &rf_emlrtRSI;
    ptCloudOut->set_RangeData(&st, r);
    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    return ptCloudOut;
  }

  b_pointCloud::b_pointCloud()
  {
    this->matlabCodegenIsDeleted = true;
  }

  b_pointCloud::~b_pointCloud()
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

  void b_pointCloud::findNeighborsInRadius(const emlrtStack *sp, const real32_T
    varargin_1[3], real32_T varargin_2, ::coder::array<uint32_T, 1U> &indices)
  {
    array<int32_T, 2U> ii;
    array<real32_T, 2U> allDists;
    array<real32_T, 2U> r;
    array<real32_T, 1U> dists_;
    array<boolean_T, 2U> b_allDists;
    array<boolean_T, 1U> b_isFinite;
    array<boolean_T, 1U> r1;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    int32_T b_iv[2];
    int32_T k;
    int32_T partialTrueCount;
    real32_T point[3];
    uint32_T x;
    boolean_T b;
    boolean_T exitg1;
    boolean_T p;
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
    st.site = &pm_emlrtRSI;
    b_st.site = &qm_emlrtRSI;
    c_st.site = &vm_emlrtRSI;
    d_st.site = &xm_emlrtRSI;
    e_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!muSingleScalarIsNaN(varargin_1[k])) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&e_st, &u_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:expectedNonNaN", 3, 4, 5, "point");
    }

    e_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if ((!muSingleScalarIsInf(varargin_1[k])) && (!muSingleScalarIsNaN
           (varargin_1[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&e_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:expectedFinite", 3, 4, 5, "point");
    }

    point[0] = varargin_1[0];
    point[1] = varargin_1[1];
    point[2] = varargin_1[2];
    c_st.site = &wm_emlrtRSI;
    d_st.site = &ym_emlrtRSI;
    e_st.site = &yb_emlrtRSI;
    b = muSingleScalarIsNaN(varargin_2);
    p = !b;
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&e_st, &u_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:expectedNonNaN", 3, 4, 6, "radius");
    }

    e_st.site = &yb_emlrtRSI;
    p = ((!muSingleScalarIsInf(varargin_2)) && (!b));
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&e_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:expectedFinite", 3, 4, 6, "radius");
    }

    e_st.site = &yb_emlrtRSI;
    p = !(varargin_2 < 0.0F);
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&e_st, &w_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:expectedNonnegative", 3, 4, 6, "radius");
    }

    b_st.site = &rm_emlrtRSI;
    if (this->get_Count() < 500.0) {
      real_T c;
      int32_T trueCount;
      b_st.site = &sm_emlrtRSI;
      c_st.site = &an_emlrtRSI;
      k = this->Location.size(0);
      d_st.site = &dn_emlrtRSI;
      allDists.set_size(&kh_emlrtRTEI, &d_st, 1, k);
      for (partialTrueCount = 0; partialTrueCount < k; partialTrueCount++) {
        allDists[partialTrueCount] = 0.0F;
      }

      r.set_size(&lh_emlrtRTEI, &d_st, 3, this->Location.size(0));
      k = this->Location.size(0);
      for (partialTrueCount = 0; partialTrueCount < k; partialTrueCount++) {
        r[3 * partialTrueCount] = this->Location[partialTrueCount];
        r[3 * partialTrueCount + 1] = this->Location[partialTrueCount +
          this->Location.size(0)];
        r[3 * partialTrueCount + 2] = this->Location[partialTrueCount +
          this->Location.size(0) * 2];
      }

      partialTrueCount = this->Location.size(0);
      if (partialTrueCount < 0) {
        partialTrueCount = 0;
      }

      ComputeMetric_ssd_single(&point[0], &r[0], &allDists[0], 1U, static_cast<
        uint32_T>(partialTrueCount), 3U);
      c_st.site = &bn_emlrtRSI;
      d_st.site = &pk_emlrtRSI;
      c = static_cast<real_T>(varargin_2) * varargin_2;
      c_st.site = &bn_emlrtRSI;
      b_allDists.set_size(&mh_emlrtRTEI, &c_st, 1, allDists.size(1));
      k = allDists.size(0) * allDists.size(1);
      for (partialTrueCount = 0; partialTrueCount < k; partialTrueCount++) {
        b_allDists[partialTrueCount] = (allDists[partialTrueCount] <= c);
      }

      d_st.site = &jf_emlrtRSI;
      b_eml_find(&d_st, b_allDists, ii);
      indices.set_size(&nh_emlrtRTEI, &b_st, ii.size(1));
      k = ii.size(1);
      for (partialTrueCount = 0; partialTrueCount < k; partialTrueCount++) {
        trueCount = ii[partialTrueCount];
        if (trueCount < 0) {
          trueCount = 0;
        }

        indices[partialTrueCount] = static_cast<uint32_T>(trueCount);
      }

      if (indices.size(0) == 0) {
        dists_.set_size(&qh_emlrtRTEI, &b_st, 0);
      } else {
        int32_T i;
        b_iv[0] = (*(int32_T (*)[2])allDists.size())[0];
        b_iv[1] = (*(int32_T (*)[2])allDists.size())[1];
        c_st.site = &cn_emlrtRSI;
        internal::b_indexShapeCheck(&c_st, b_iv, indices.size(0));
        dists_.set_size(&oh_emlrtRTEI, &b_st, indices.size(0));
        k = indices.size(0);
        for (partialTrueCount = 0; partialTrueCount < k; partialTrueCount++) {
          if ((static_cast<int32_T>(indices[partialTrueCount]) < 1) || (
               static_cast<int32_T>(indices[partialTrueCount]) > allDists.size(1)))
          {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>
              (indices[partialTrueCount]), 1, allDists.size(1), &fc_emlrtBCI,
              &b_st);
          }

          dists_[partialTrueCount] = allDists[static_cast<int32_T>
            (indices[partialTrueCount]) - 1];
        }

        b_isFinite.set_size(&hg_emlrtRTEI, &b_st, dists_.size(0));
        k = dists_.size(0);
        for (partialTrueCount = 0; partialTrueCount < k; partialTrueCount++) {
          b_isFinite[partialTrueCount] = muSingleScalarIsInf
            (dists_[partialTrueCount]);
        }

        r1.set_size(&ig_emlrtRTEI, &b_st, dists_.size(0));
        k = dists_.size(0);
        for (partialTrueCount = 0; partialTrueCount < k; partialTrueCount++) {
          r1[partialTrueCount] = muSingleScalarIsNaN(dists_[partialTrueCount]);
        }

        k = b_isFinite.size(0);
        for (partialTrueCount = 0; partialTrueCount < k; partialTrueCount++) {
          b_isFinite[partialTrueCount] = ((!b_isFinite[partialTrueCount]) &&
            (!r1[partialTrueCount]));
        }

        k = b_isFinite.size(0) - 1;
        trueCount = 0;
        for (i = 0; i <= k; i++) {
          if (b_isFinite[i]) {
            trueCount++;
          }
        }

        partialTrueCount = 0;
        for (i = 0; i <= k; i++) {
          if (b_isFinite[i]) {
            if ((i + 1 < 1) || (i + 1 > indices.size(0))) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, indices.size(0),
                &gc_emlrtBCI, &b_st);
            }

            indices[partialTrueCount] = indices[i];
            partialTrueCount++;
          }
        }

        indices.set_size(&ph_emlrtRTEI, &b_st, trueCount);
        k = b_isFinite.size(0) - 1;
        trueCount = 0;
        for (i = 0; i <= k; i++) {
          if (b_isFinite[i]) {
            trueCount++;
          }
        }

        partialTrueCount = 0;
        for (i = 0; i <= k; i++) {
          if (b_isFinite[i]) {
            if ((i + 1 < 1) || (i + 1 > dists_.size(0))) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, dists_.size(0),
                &hc_emlrtBCI, &b_st);
            }

            dists_[partialTrueCount] = dists_[i];
            partialTrueCount++;
          }
        }

        dists_.set_size(&ph_emlrtRTEI, &b_st, trueCount);
      }
    } else {
      void * ptrDists;
      void * ptrIndices;
      b_st.site = &tm_emlrtRSI;
      c_st.site = &en_emlrtRSI;
      this->buildKdtree(&c_st);
      c_st.site = &fn_emlrtRSI;
      ptrIndices = NULL;
      ptrDists = NULL;
      kdtreeRadiusSearch_single(this->Kdtree, &point[0], 1U, 3U, varargin_2, 0.0,
        0.0F, &ptrIndices, &ptrDists, &x, 1000, 500U);
      if (static_cast<real_T>(x) != static_cast<int32_T>(x)) {
        emlrtIntegerCheckR2012b(static_cast<real_T>(x), &g_emlrtDCI, &c_st);
      }

      indices.set_size(&ih_emlrtRTEI, &c_st, static_cast<int32_T>(x));
      dists_.set_size(&jh_emlrtRTEI, &c_st, static_cast<int32_T>(x));
      kdtreeRadiusSearchSetOutputs_single(ptrIndices, ptrDists, &(indices.data())
        [0], &(dists_.data())[0]);
    }

    b_st.site = &um_emlrtRSI;
    p = false;
    partialTrueCount = dists_.size(0);
    for (k = 0; k < partialTrueCount; k++) {
      if (p || (dists_[k] < 0.0F)) {
        p = true;
      }
    }

    if (p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &ob_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    c_st.site = &sk_emlrtRSI;
    d_st.site = &tk_emlrtRSI;
    if ((1 <= dists_.size(0)) && (dists_.size(0) > 2147483646)) {
      e_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void b_pointCloud::findPointsInROI(const emlrtStack *sp, const real_T
    varargin_1[6], ::coder::array<uint32_T, 1U> &indices)
  {
    array<int32_T, 1U> ii;
    array<boolean_T, 1U> r;
    array<boolean_T, 1U> r1;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    real_T roi[6];
    int32_T i;
    int32_T numOut;
    boolean_T x_data[6];
    boolean_T exitg1;
    boolean_T p;
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
    st.site = &wf_emlrtRSI;
    b_st.site = &xf_emlrtRSI;
    c_st.site = &cg_emlrtRSI;
    d_st.site = &dg_emlrtRSI;
    e_st.site = &yb_emlrtRSI;
    p = true;
    numOut = 0;
    exitg1 = false;
    while ((!exitg1) && (numOut < 6)) {
      if (!muDoubleScalarIsNaN(varargin_1[numOut])) {
        numOut++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&e_st, &u_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:expectedNonNaN", 3, 4, 3, "roi");
    }

    x_data[0] = (varargin_1[0] > varargin_1[3]);
    x_data[1] = (varargin_1[1] > varargin_1[4]);
    x_data[2] = (varargin_1[2] > varargin_1[5]);
    p = false;
    numOut = 0;
    exitg1 = false;
    while ((!exitg1) && (numOut <= 2)) {
      if (!x_data[numOut]) {
        numOut++;
      } else {
        p = true;
        exitg1 = true;
      }
    }

    if (p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &t_emlrtRTEI,
        "vision:pointcloud:invalidROI", "vision:pointcloud:invalidROI", 0);
    }

    for (i = 0; i < 6; i++) {
      roi[i] = varargin_1[i];
    }

    b_st.site = &yf_emlrtRSI;
    if (this->get_Count() < 500.0) {
      b_st.site = &ag_emlrtRSI;
      numOut = this->Location.size(0);
      r.set_size(&lf_emlrtRTEI, &b_st, numOut);
      for (i = 0; i < numOut; i++) {
        r[i] = (this->Location[i] >= varargin_1[0]);
      }

      numOut = this->Location.size(0);
      r1.set_size(&mf_emlrtRTEI, &b_st, numOut);
      for (i = 0; i < numOut; i++) {
        r1[i] = (this->Location[i] <= varargin_1[3]);
      }

      if (r.size(0) != r1.size(0)) {
        emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &i_emlrtECI, &b_st);
      }

      numOut = r.size(0);
      for (i = 0; i < numOut; i++) {
        r[i] = (r[i] && r1[i]);
      }

      numOut = this->Location.size(0);
      r1.set_size(&nf_emlrtRTEI, &b_st, numOut);
      for (i = 0; i < numOut; i++) {
        r1[i] = (this->Location[i + this->Location.size(0)] >= varargin_1[1]);
      }

      if (r.size(0) != r1.size(0)) {
        emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &i_emlrtECI, &b_st);
      }

      numOut = r.size(0);
      for (i = 0; i < numOut; i++) {
        r[i] = (r[i] && r1[i]);
      }

      numOut = this->Location.size(0);
      r1.set_size(&of_emlrtRTEI, &b_st, numOut);
      for (i = 0; i < numOut; i++) {
        r1[i] = (this->Location[i + this->Location.size(0)] <= varargin_1[4]);
      }

      if (r.size(0) != r1.size(0)) {
        emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &i_emlrtECI, &b_st);
      }

      numOut = r.size(0);
      for (i = 0; i < numOut; i++) {
        r[i] = (r[i] && r1[i]);
      }

      numOut = this->Location.size(0);
      r1.set_size(&pf_emlrtRTEI, &b_st, numOut);
      for (i = 0; i < numOut; i++) {
        r1[i] = (this->Location[i + this->Location.size(0) * 2] >= varargin_1[2]);
      }

      if (r.size(0) != r1.size(0)) {
        emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &i_emlrtECI, &b_st);
      }

      numOut = r.size(0);
      for (i = 0; i < numOut; i++) {
        r[i] = (r[i] && r1[i]);
      }

      numOut = this->Location.size(0);
      r1.set_size(&qf_emlrtRTEI, &b_st, numOut);
      for (i = 0; i < numOut; i++) {
        r1[i] = (this->Location[i + this->Location.size(0) * 2] <= varargin_1[5]);
      }

      if (r.size(0) != r1.size(0)) {
        emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &i_emlrtECI, &b_st);
      }

      c_st.site = &eg_emlrtRSI;
      numOut = r.size(0);
      for (i = 0; i < numOut; i++) {
        r[i] = (r[i] && r1[i]);
      }

      d_st.site = &jf_emlrtRSI;
      eml_find(&d_st, r, ii);
      indices.set_size(&rf_emlrtRTEI, &b_st, ii.size(0));
      numOut = ii.size(0);
      for (i = 0; i < numOut; i++) {
        int32_T i1;
        i1 = ii[i];
        if (i1 < 0) {
          i1 = 0;
        }

        indices[i] = static_cast<uint32_T>(i1);
      }
    } else {
      void * ptrIndices;
      b_st.site = &bg_emlrtRSI;
      c_st.site = &fg_emlrtRSI;
      this->buildKdtree(&c_st);
      c_st.site = &gg_emlrtRSI;
      ptrIndices = NULL;
      numOut = kdtreeBoxSearch_single(this->Kdtree, &roi[0], &ptrIndices);
      if (numOut < 0) {
        emlrtNonNegativeCheckR2012b(static_cast<real_T>(numOut), &emlrtDCI,
          &c_st);
      }

      indices.set_size(&kf_emlrtRTEI, &c_st, numOut);
      kdtreeBoxSearchSetOutputs(ptrIndices, &(indices.data())[0]);
      c_st.site = &hg_emlrtRSI;
      d_st.site = &ig_emlrtRSI;
      internal::sort(&d_st, indices);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  real_T b_pointCloud::get_Count() const
  {
    return this->Location.size(0);
  }

  b_pointCloud *b_pointCloud::init(const emlrtStack *sp, const ::coder::array<
    real32_T, 2U> &varargin_1, const ::coder::array<uint8_T, 2U> &varargin_3,
    const ::coder::array<real32_T, 2U> &varargin_5, const ::coder::array<
    real32_T, 2U> &varargin_7)
  {
    b_pointCloud *this_;
    array<real32_T, 2U> tmp_data;
    emlrtStack b_st;
    emlrtStack st;
    int32_T loop_ub;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    this_ = this;
    this_->HasKdtreeConstructed = false;
    this_->HasLocationHandleAllocated = false;
    st.site = &ab_emlrtRSI;
    this_->Location.set_size(&vd_emlrtRTEI, &st, varargin_1.size(0), 3);
    loop_ub = varargin_1.size(0) * varargin_1.size(1);
    for (int32_T i = 0; i < loop_ub; i++) {
      this_->Location[i] = varargin_1[i];
    }

    b_st.site = &db_emlrtRSI;
    this_->set_Color(&b_st, varargin_3);
    b_st.site = &eb_emlrtRSI;
    this_->set_Normal(&b_st, varargin_5);
    b_st.site = &fb_emlrtRSI;
    this_->set_Intensity(&b_st, varargin_7);
    tmp_data.set(NULL, 0, 0);
    b_st.site = &gb_emlrtRSI;
    this_->set_RangeData(&b_st, tmp_data);
    st.site = &bb_emlrtRSI;
    this_->Kdtree = NULL;
    this_->LocationHandle = NULL;
    this_->matlabCodegenIsDeleted = false;
    return this_;
  }

  b_pointCloud *b_pointCloud::init(const emlrtStack *sp, const ::coder::array<
    real32_T, 2U> &varargin_1)
  {
    b_pointCloud *this_;
    array<real32_T, 2U> b_nv_tmp_data;
    array<real32_T, 2U> c_nv_tmp_data;
    array<real32_T, 2U> nv_tmp_data;
    array<uint8_T, 2U> r;
    emlrtStack b_st;
    emlrtStack st;
    int32_T loop_ub;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    this_ = this;
    this_->HasKdtreeConstructed = false;
    this_->HasLocationHandleAllocated = false;
    st.site = &ab_emlrtRSI;
    this_->Location.set_size(&vd_emlrtRTEI, &st, varargin_1.size(0), 3);
    loop_ub = varargin_1.size(0) * varargin_1.size(1);
    for (int32_T i = 0; i < loop_ub; i++) {
      this_->Location[i] = varargin_1[i];
    }

    r.set(NULL, 0, 0);
    b_st.site = &db_emlrtRSI;
    this_->set_Color(&b_st, r);
    nv_tmp_data.set(NULL, 0, 0);
    b_st.site = &eb_emlrtRSI;
    this_->set_Normal(&b_st, nv_tmp_data);
    b_nv_tmp_data.set(NULL, 0, 0);
    b_st.site = &fb_emlrtRSI;
    this_->set_Intensity(&b_st, b_nv_tmp_data);
    c_nv_tmp_data.set(NULL, 0, 0);
    b_st.site = &gb_emlrtRSI;
    this_->set_RangeData(&b_st, c_nv_tmp_data);
    st.site = &bb_emlrtRSI;
    this_->Kdtree = NULL;
    this_->LocationHandle = NULL;
    this_->matlabCodegenIsDeleted = false;
    return this_;
  }

  void b_pointCloud::matlabCodegenDestructor()
  {
    if (!this->matlabCodegenIsDeleted) {
      this->matlabCodegenIsDeleted = true;
      if (this->HasLocationHandleAllocated) {
        kdtreeDeleteLocationDataPointer_single(this->LocationHandle);
        this->HasLocationHandleAllocated = false;
      }

      if (this->HasKdtreeConstructed) {
        kdtreeDeleteObj_single(this->Kdtree);
        this->HasKdtreeConstructed = false;
      }
    }
  }

  void b_pointCloud::removeInvalidPoints(const emlrtStack *sp, b_pointCloud
    *iobj_0, b_pointCloud **ptCloudOut, ::coder::array<real_T, 1U> &indicesOut)
    const
  {
    array<int32_T, 1U> ii;
    array<real32_T, 2U> intensity;
    array<real32_T, 2U> location;
    array<real32_T, 2U> normals;
    array<real32_T, 2U> rangeData;
    array<uint8_T, 2U> color;
    array<boolean_T, 1U> indices;
    emlrtStack b_st;
    emlrtStack st;
    int32_T loop_ub;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &pi_emlrtRSI;
    this->extractValidPoints(&st, location, color, normals, intensity, rangeData,
      indices);
    st.site = &qi_emlrtRSI;
    *ptCloudOut = iobj_0->init(&st, location, color, normals, intensity);
    st.site = &ri_emlrtRSI;
    (*ptCloudOut)->set_RangeData(&st, rangeData);
    st.site = &si_emlrtRSI;
    b_st.site = &jf_emlrtRSI;
    eml_find(&b_st, indices, ii);
    indicesOut.set_size(&gg_emlrtRTEI, &st, ii.size(0));
    loop_ub = ii.size(0);
    for (int32_T i = 0; i < loop_ub; i++) {
      indicesOut[i] = ii[i];
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void b_pointCloud::surfaceNormalImpl(const emlrtStack *sp, ::coder::array<
    real32_T, 2U> &normals)
  {
    array<real32_T, 2U> b_normals;
    array<real32_T, 2U> loc;
    array<real32_T, 2U> queryPoints;
    array<real32_T, 2U> unusedU7;
    array<uint32_T, 2U> indices;
    array<uint32_T, 1U> valid;
    emlrtStack st;
    real_T K;
    int32_T loop_ub;
    st.prev = sp;
    st.tls = sp->tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    K = this->get_Count();
    K = muDoubleScalarMin(6.0, K);
    if (this->get_Count() <= 2.0) {
      loop_ub = this->Location.size(0);
      normals.set_size(&ff_emlrtRTEI, sp, loop_ub, 3);
      loop_ub *= 3;
      for (int32_T i = 0; i < loop_ub; i++) {
        normals[i] = rtNaNF;
      }
    } else {
      int32_T i;
      st.site = &bf_emlrtRSI;
      this->buildKdtree(&st);
      loc.set_size(&xe_emlrtRTEI, sp, this->Location.size(0), 3);
      loop_ub = this->Location.size(0) * this->Location.size(1);
      for (i = 0; i < loop_ub; i++) {
        loc[i] = this->Location[i];
      }

      st.site = &cf_emlrtRSI;
      queryPoints.set_size(&ye_emlrtRTEI, &st, loc.size(0), 3);
      loop_ub = loc.size(0) * loc.size(1);
      for (i = 0; i < loop_ub; i++) {
        queryPoints[i] = loc[i];
      }

      i = loc.size(0);
      if (loc.size(0) < 0) {
        i = 0;
      }

      indices.set_size(&af_emlrtRTEI, &st, static_cast<int32_T>(K), i);
      unusedU7.set_size(&bf_emlrtRTEI, &st, static_cast<int32_T>(K), i);
      valid.set_size(&cf_emlrtRTEI, &st, i);
      K = muDoubleScalarRound(K);
      if (K >= 0.0) {
        loop_ub = static_cast<int32_T>(K);
      } else {
        loop_ub = 0;
      }

      kdtreeKNNSearch_single(this->Kdtree, &queryPoints[0], static_cast<uint32_T>
        (i), 3U, static_cast<uint32_T>(loop_ub), 0.0, 0.0F, &indices[0],
        &unusedU7[0], &(valid.data())[0], 2000, 500U);
      st.site = &df_emlrtRSI;
      b_normals.set_size(&df_emlrtRTEI, &st, loc.size(0), 3);
      i = loc.size(0);
      if (loc.size(0) < 0) {
        i = 0;
      }

      PCANormalImpl_single(&loc[0], &indices[0], &(valid.data())[0],
                           static_cast<uint32_T>(i), static_cast<uint32_T>
                           (indices.size(0)), &b_normals[0]);
      normals.set_size(&ef_emlrtRTEI, sp, b_normals.size(0), b_normals.size(1));
      loop_ub = b_normals.size(0) * b_normals.size(1);
      for (i = 0; i < loop_ub; i++) {
        normals[i] = b_normals[i];
      }
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }
}

// End of code generation (pointCloud.cpp)
