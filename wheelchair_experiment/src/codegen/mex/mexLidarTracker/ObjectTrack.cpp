//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  ObjectTrack.cpp
//
//  Code generation for function 'ObjectTrack'
//


// Include files
#include "ObjectTrack.h"
#include "all.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "objectDetection.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "trackHistoryLogic.h"
#include "trackingEKF.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo tv_emlrtRSI = { 549,// lineNo
  "ObjectTrack/nullify",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo uv_emlrtRSI = { 550,// lineNo
  "ObjectTrack/nullify",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo aw_emlrtRSI = { 966,// lineNo
  "ObjectTrack/copy",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo gw_emlrtRSI = { 988,// lineNo
  "ObjectTrack/copyPrivateProperties", // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo hw_emlrtRSI = { 989,// lineNo
  "ObjectTrack/copyPrivateProperties", // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo fx_emlrtRSI = { 424,// lineNo
  "ObjectTrack/trackToStruct",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo hx_emlrtRSI = { 381,// lineNo
  "ObjectTrack/get.ObjectAttributes",  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo ix_emlrtRSI = { 27, // lineNo
  "horzcatCellList",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/horzcatCellList.m"// pathName 
};

static emlrtRSInfo hy_emlrtRSI = { 566,// lineNo
  "ObjectTrack/predict",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo iy_emlrtRSI = { 591,// lineNo
  "ObjectTrack/predict",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo ly_emlrtRSI = { 22, // lineNo
  "predictTrackFilter",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/predictTrackFilter.m"// pathName 
};

static emlrtRSInfo ncb_emlrtRSI = { 911,// lineNo
  "ObjectTrack/distance",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo ocb_emlrtRSI = { 942,// lineNo
  "ObjectTrack/distance",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo pcb_emlrtRSI = { 1150,// lineNo
  "ObjectTrack/calcCostMatrixFull",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo qcb_emlrtRSI = { 1152,// lineNo
  "ObjectTrack/calcCostMatrixFull",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo rcb_emlrtRSI = { 27,// lineNo
  "sortrows",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRSInfo scb_emlrtRSI = { 28,// lineNo
  "sortrows",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRSInfo tcb_emlrtRSI = { 86,// lineNo
  "sortIdx",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo ucb_emlrtRSI = { 40,// lineNo
  "apply_row_permutation",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRSInfo vcb_emlrtRSI = { 43,// lineNo
  "apply_row_permutation",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRSInfo wcb_emlrtRSI = { 1243,// lineNo
  "ObjectTrack/distanceFull",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo xcb_emlrtRSI = { 1250,// lineNo
  "ObjectTrack/distanceFull",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo ycb_emlrtRSI = { 1257,// lineNo
  "ObjectTrack/distanceFull",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo adb_emlrtRSI = { 1273,// lineNo
  "ObjectTrack/distanceFull",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo bdb_emlrtRSI = { 1278,// lineNo
  "ObjectTrack/distanceFull",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo cdb_emlrtRSI = { 1309,// lineNo
  "ObjectTrack/calcCostOneDetection",  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo gib_emlrtRSI = { 736,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo hib_emlrtRSI = { 749,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo iib_emlrtRSI = { 758,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo jib_emlrtRSI = { 760,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo kib_emlrtRSI = { 776,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo lib_emlrtRSI = { 788,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo mib_emlrtRSI = { 793,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo nib_emlrtRSI = { 810,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo oib_emlrtRSI = { 816,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo pib_emlrtRSI = { 822,// lineNo
  "ObjectTrack/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo rib_emlrtRSI = { 301,// lineNo
  "ObjectTrack/setObjectAttributes",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo ckb_emlrtRSI = { 859,// lineNo
  "ObjectTrack/updateNotAssociated",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRSInfo fkb_emlrtRSI = { 885,// lineNo
  "ObjectTrack/checkDeletion",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pathName 
};

static emlrtRTEInfo cc_emlrtRTEI = { 110,// lineNo
  9,                                   // colNo
  "allocOutput",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/horzcatCellList.m"// pName 
};

static emlrtDCInfo n_emlrtDCI = { 120, // lineNo
  60,                                  // colNo
  "allocOutput",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/horzcatCellList.m",// pName 
  4                                    // checkKind
};

static emlrtBCInfo gf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1256,                                // lineNo
  40,                                  // colNo
  "",                                  // aName
  "ObjectTrack/distanceFull",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1146,                                // lineNo
  74,                                  // colNo
  "",                                  // aName
  "ObjectTrack/calcCostMatrixFull",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo if_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1148,                                // lineNo
  26,                                  // colNo
  "",                                  // aName
  "ObjectTrack/calcCostMatrixFull",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1148,                                // lineNo
  37,                                  // colNo
  "",                                  // aName
  "ObjectTrack/calcCostMatrixFull",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1152,                                // lineNo
  69,                                  // colNo
  "",                                  // aName
  "ObjectTrack/calcCostMatrixFull",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo bb_emlrtDCI = { 1152,// lineNo
  69,                                  // colNo
  "ObjectTrack/calcCostMatrixFull",    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo lf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  1280,                                // lineNo
  21,                                  // colNo
  "",                                  // aName
  "ObjectTrack/distanceFull",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo nh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  21,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo oh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  810,                                 // lineNo
  45,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ph_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  810,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  735,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  760,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  767,                                 // lineNo
  36,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo th_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  762,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo uh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  780,                                 // lineNo
  34,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  804,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  19,                                  // lineNo
  12,                                  // colNo
  "",                                  // aName
  "hasSameClassID",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  19,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "hasSameClassID",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo gb_emlrtDCI = { 19, // lineNo
  43,                                  // colNo
  "hasSameClassID",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo yh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  20,                                  // lineNo
  13,                                  // colNo
  "",                                  // aName
  "hasSameClassID",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ai_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  21,                                  // lineNo
  13,                                  // colNo
  "",                                  // aName
  "hasSameClassID",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/hasSameClassID.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bi_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  26,                                  // colNo
  "",                                  // aName
  "ObjectTrack/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo hb_emlrtDCI = { 322,// lineNo
  49,                                  // colNo
  "ObjectTrack/setObjectAttributes",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo ib_emlrtDCI = { 324,// lineNo
  49,                                  // colNo
  "ObjectTrack/setObjectAttributes",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo ci_emlrtBCI = { 1,  // iFirst
  20,                                  // iLast
  324,                                 // lineNo
  49,                                  // colNo
  "",                                  // aName
  "ObjectTrack/setObjectAttributes",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  3                                    // checkKind
};

static emlrtBCInfo di_emlrtBCI = { 0,  // iFirst
  19,                                  // iLast
  322,                                 // lineNo
  49,                                  // colNo
  "",                                  // aName
  "ObjectTrack/setObjectAttributes",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m",// pName 
  3                                    // checkKind
};

static emlrtRTEInfo vc_emlrtRTEI = { 22,// lineNo
  27,                                  // colNo
  "validatele",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatele.m"// pName 
};

static emlrtRTEInfo cl_emlrtRTEI = { 1146,// lineNo
  13,                                  // colNo
  "ObjectTrack",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pName 
};

static emlrtRTEInfo dl_emlrtRTEI = { 27,// lineNo
  1,                                   // colNo
  "sortrows",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"// pName
};

static emlrtRTEInfo el_emlrtRTEI = { 38,// lineNo
  23,                                  // colNo
  "sortrows",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"// pName
};

static emlrtRTEInfo fl_emlrtRTEI = { 1152,// lineNo
  52,                                  // colNo
  "ObjectTrack",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pName 
};

static emlrtRTEInfo gl_emlrtRTEI = { 942,// lineNo
  17,                                  // colNo
  "ObjectTrack",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pName 
};

static emlrtRTEInfo hl_emlrtRTEI = { 911,// lineNo
  17,                                  // colNo
  "ObjectTrack",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pName 
};

static emlrtRTEInfo xm_emlrtRTEI = { 758,// lineNo
  13,                                  // colNo
  "ObjectTrack",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pName 
};

static emlrtRTEInfo ym_emlrtRTEI = { 781,// lineNo
  17,                                  // colNo
  "ObjectTrack",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pName 
};

static emlrtRTEInfo an_emlrtRTEI = { 789,// lineNo
  13,                                  // colNo
  "ObjectTrack",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pName 
};

static emlrtRTEInfo bn_emlrtRTEI = { 810,// lineNo
  40,                                  // colNo
  "ObjectTrack",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/ObjectTrack.m"// pName 
};

// Function Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        namespace fusion
        {
          void ObjectTrack::copyPrivateProperties(const emlrtStack *sp,
            ObjectTrack *newTrack)
          {
            emlrtStack st;
            int32_T i;
            boolean_T track[20];
            st.prev = sp;
            st.tls = sp->tls;
            newTrack->UpdateTime = this->UpdateTime;
            newTrack->pIsCoasted = this->pIsCoasted;
            newTrack->pMotionModel = this->pMotionModel;
            for (i = 0; i < 20; i++) {
              track[i] = this->pUsedObjectAttributes[i];
            }

            for (i = 0; i < 20; i++) {
              newTrack->pUsedObjectAttributes[i] = track[i];
            }

            newTrack->pAge = this->pAge;
            newTrack->IsConfirmed = newTrack->checkPromotion();
            st.site = &gw_emlrtRSI;
            newTrack->Filter->sync(&st, this->Filter);
            st.site = &hw_emlrtRSI;
            newTrack->pDistanceFilter->sync(&st, this->pDistanceFilter);
          }

          boolean_T ObjectTrack::get_IsCoasted() const
          {
            return this->pIsCoasted;
          }

          void ObjectTrack::get_ObjectAttributes(const emlrtStack *sp, int32_T
            value_size[2]) const
          {
            emlrtStack b_st;
            emlrtStack st;
            int32_T k;
            boolean_T exitg1;
            boolean_T p;
            st.prev = sp;
            st.tls = sp->tls;
            st.site = &hx_emlrtRSI;
            b_st.prev = &st;
            b_st.tls = st.tls;
            b_st.site = &ix_emlrtRSI;
            p = true;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 20)) {
              if (this->pUsedObjectAttributes[k]) {
                p = false;
                exitg1 = true;
              } else {
                k++;
              }
            }

            if (p) {
              value_size[0] = 1;
              value_size[1] = 0;
            } else {
              int32_T maxsize2;
              int32_T sz2;
              maxsize2 = 0;
              sz2 = 0;
              for (k = 0; k < 20; k++) {
                if (1 > maxsize2) {
                  maxsize2 = 1;
                }

                if (this->pUsedObjectAttributes[k]) {
                  sz2++;
                }
              }

              if (sz2 > maxsize2 * 20) {
                emlrtErrorWithMessageIdR2018a(&b_st, &cc_emlrtRTEI,
                  "Coder:builtins:AssertionFailed",
                  "Coder:builtins:AssertionFailed", 0);
              }

              value_size[0] = 1;
              if (sz2 < 0) {
                emlrtNonNegativeCheckR2012b(static_cast<real_T>(sz2),
                  &n_emlrtDCI, &b_st);
              }

              value_size[1] = sz2;
            }
          }

          void ObjectTrack::get_StateCovariance(real_T covariance[36])
          {
            this->Filter->get_StateCovariance(covariance);
          }

          ObjectTrack *ObjectTrack::init(uint32_T varargin_2, uint32_T
            varargin_4, real_T varargin_6, trackingEKF *varargin_8, real_T
            varargin_10, trackHistoryLogic *varargin_12)
          {
            ObjectTrack *b_track;
            ObjectTrack *track;
            b_trackHistoryLogic lobj_0;
            track = this;
            lobj_0.init();
            b_track = track;
            track->BranchID = varargin_2;
            track->TrackID = varargin_4;
            track->set_Filter(varargin_8);
            track->pDistanceFilter = varargin_8->clone(&track->_pobj0);
            b_track->UpdateTime = varargin_6;
            b_track->Time = varargin_6;
            b_track->ObjectClassID = varargin_10;
            b_track->set_TrackLogic(varargin_12);
            for (int32_T i = 0; i < 20; i++) {
              b_track->pUsedObjectAttributes[i] = false;
            }

            b_track->pUsedObjectAttributes[0] = true;
            return track;
          }

          void ObjectTrack::setDependentFilterValues(const trackingEKF *filter)
          {
            real_T unusedExpr[6];
            this->pMotionModel = 0U;
            filter->get_State(unusedExpr);
          }

          void ObjectTrack::set_Filter(trackingEKF *value)
          {
            this->Filter = value;
            this->setDependentFilterValues(value);
          }

          void ObjectTrack::set_TrackLogic(trackHistoryLogic *value)
          {
            this->TrackLogic = value;
          }

          boolean_T ObjectTrack::checkDeletion(const emlrtStack *sp) const
          {
            emlrtStack st;
            st.prev = sp;
            st.tls = sp->tls;
            st.site = &fkb_emlrtRSI;
            return this->TrackLogic->checkDeletion(&st, !this->IsConfirmed,
              this->pAge);
          }

          boolean_T ObjectTrack::checkPromotion() const
          {
            boolean_T toPromote;
            if (this->ObjectClassID != 0.0) {
              toPromote = true;
            } else {
              toPromote = this->TrackLogic->checkConfirmation();
            }

            return toPromote;
          }

          ObjectTrack *ObjectTrack::copy(const emlrtStack *sp, ObjectTrack
            *iobj_0, trackHistoryLogic *iobj_1, trackingEKF *iobj_2)
          {
            ObjectTrack *newTrack;
            trackHistoryLogic *trackConf;
            trackingEKF *filter;
            emlrtStack st;
            st.prev = sp;
            st.tls = sp->tls;
            filter = this->Filter->clone(iobj_2);
            trackConf = this->TrackLogic->clone(iobj_1);
            newTrack = iobj_0->init(this->BranchID, this->TrackID, this->Time,
              filter, this->ObjectClassID, trackConf);
            st.site = &aw_emlrtRSI;
            this->copyPrivateProperties(&st, newTrack);
            return newTrack;
          }

          void ObjectTrack::correctjpda(const emlrtStack *sp, const
            objectDetection detections[1])
          {
            emlrtStack st;
            real_T dv[9];
            uint32_T q0;
            uint32_T qY;
            st.prev = sp;
            st.tls = sp->tls;
            st.site = &gib_emlrtRSI;
            this->predict(&st, detections[0].Time);
            st.site = &hib_emlrtRSI;
            this->setObjectAttributes(&st, detections[0].SensorIndex);
            if (detections[0].ObjectClassID != 0.0) {
              this->ObjectClassID = detections[0].ObjectClassID;
            }

            detections[0].get_MeasurementNoise(dv);
            st.site = &kib_emlrtRSI;
            this->Filter->set_MeasurementNoise(&st, dv);
            st.site = &mib_emlrtRSI;
            this->Filter->correctjpda(&st, detections[0].Measurement);
            q0 = this->pAge;
            qY = q0 + 1U;
            if (q0 + 1U < q0) {
              qY = MAX_uint32_T;
            }

            this->pAge = qY;
            this->UpdateTime = detections[0].Time;
            this->pIsCoasted = false;
            st.site = &oib_emlrtRSI;
            this->TrackLogic->hit(&st);
            if (!this->IsConfirmed) {
              this->IsConfirmed = this->checkPromotion();
            }
          }

          void ObjectTrack::correctjpda(const emlrtStack *sp, const ::coder::
            array<objectDetection, 2U> &detections, const ::coder::array<real_T,
            1U> &posterior)
          {
            array<real_T, 2U> z;
            array<real_T, 1U> b_jpda;
            array<real_T, 1U> jpda;
            array<boolean_T, 2U> flag;
            array<boolean_T, 1U> b_flag;
            emlrtStack st;
            real_T dv[9];
            real_T ptes;
            int32_T b_iv[2];
            int32_T b_i;
            int32_T i;
            int32_T loop_ub;
            uint32_T b_j;
            uint32_T qY;
            st.prev = sp;
            st.tls = sp->tls;
            emlrtHeapReferenceStackEnterFcnR2012b(sp);
            if (0 > detections.size(0) - 1) {
              emlrtDynamicBoundsCheckR2012b(0, 0, detections.size(0) - 1,
                &qh_emlrtBCI, sp);
            }

            st.site = &gib_emlrtRSI;
            this->predict(&st, detections[0].Time);
            if (detections.size(0) == 1) {
              st.site = &hib_emlrtRSI;
              this->setObjectAttributes(&st, detections[0].SensorIndex);
            }

            st.site = &iib_emlrtRSI;
            flag.set_size(&xm_emlrtRTEI, &st, detections.size(0),
                          detections.size(0));
            loop_ub = detections.size(0) * detections.size(0);
            for (i = 0; i < loop_ub; i++) {
              flag[i] = true;
            }

            i = detections.size(0);
            for (b_i = 0; b_i <= i - 2; b_i++) {
              loop_ub = detections.size(0) - b_i;
              for (int32_T j = 0; j <= loop_ub - 2; j++) {
                b_j = (static_cast<uint32_T>(b_i) + j) + 2U;
                if (b_i > detections.size(0) - 1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 0, detections.size(0) - 1,
                    &wh_emlrtBCI, &st);
                }

                if (static_cast<real_T>(b_j) != static_cast<int32_T>(b_j)) {
                  emlrtIntegerCheckR2012b(static_cast<real_T>(b_j), &gb_emlrtDCI,
                    &st);
                }

                if ((static_cast<int32_T>(b_j) - 1 < 0) || (static_cast<int32_T>
                     (b_j) - 1 > detections.size(0) - 1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_j) - 1, 0,
                    detections.size(0) - 1, &xh_emlrtBCI, &st);
                }

                if (detections[b_i].ObjectClassID != detections
                    [static_cast<int32_T>(b_j) - 1].ObjectClassID) {
                  if ((b_i + 1 < 1) || (b_i + 1 > flag.size(0))) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, flag.size(0),
                      &yh_emlrtBCI, &st);
                  }

                  if ((static_cast<int32_T>(b_j) < 1) || (static_cast<int32_T>
                       (b_j) > flag.size(1))) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_j), 1,
                      flag.size(1), &yh_emlrtBCI, &st);
                  }

                  flag[b_i + flag.size(0) * (static_cast<int32_T>(b_j) - 1)] =
                    false;
                  if ((static_cast<int32_T>(b_j) < 1) || (static_cast<int32_T>
                       (b_j) > flag.size(0))) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_j), 1,
                      flag.size(0), &ai_emlrtBCI, &st);
                  }

                  if ((b_i + 1 < 1) || (b_i + 1 > flag.size(1))) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, flag.size(1),
                      &ai_emlrtBCI, &st);
                  }

                  flag[(static_cast<int32_T>(b_j) + flag.size(0) * b_i) - 1] =
                    false;
                }
              }
            }

            loop_ub = flag.size(0) * flag.size(1);
            b_flag = flag.reshape(loop_ub);
            st.site = &jib_emlrtRSI;
            if (all(&st, b_flag)) {
              if (0 > detections.size(0) - 1) {
                emlrtDynamicBoundsCheckR2012b(0, 0, detections.size(0) - 1,
                  &rh_emlrtBCI, sp);
              }

              if (detections[0].ObjectClassID != 0.0) {
                if (0 > detections.size(0) - 1) {
                  emlrtDynamicBoundsCheckR2012b(0, 0, detections.size(0) - 1,
                    &th_emlrtBCI, sp);
                }

                this->ObjectClassID = detections[0].ObjectClassID;
              }
            }

            if (0 > detections.size(0) - 1) {
              emlrtDynamicBoundsCheckR2012b(0, 0, detections.size(0) - 1,
                &sh_emlrtBCI, sp);
            }

            detections[0].get_MeasurementNoise(dv);
            st.site = &kib_emlrtRSI;
            this->Filter->set_MeasurementNoise(&st, dv);
            if (0 > detections.size(0) - 1) {
              emlrtDynamicBoundsCheckR2012b(0, 0, detections.size(0) - 1,
                &uh_emlrtBCI, sp);
            }

            z.set_size(&ym_emlrtRTEI, sp, 3, detections.size(0));
            i = detections.size(0);
            for (b_i = 0; b_i < i; b_i++) {
              if ((b_i + 1 < 1) || (b_i + 1 > z.size(1))) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, z.size(1),
                  &nh_emlrtBCI, sp);
              }

              if (b_i > detections.size(0) - 1) {
                emlrtDynamicBoundsCheckR2012b(b_i, 0, detections.size(0) - 1,
                  &bi_emlrtBCI, sp);
              }

              z[3 * b_i] = detections[b_i].Measurement[0];
              if (b_i > detections.size(0) - 1) {
                emlrtDynamicBoundsCheckR2012b(b_i, 0, detections.size(0) - 1,
                  &bi_emlrtBCI, sp);
              }

              z[3 * b_i + 1] = detections[b_i].Measurement[1];
              if (b_i > detections.size(0) - 1) {
                emlrtDynamicBoundsCheckR2012b(b_i, 0, detections.size(0) - 1,
                  &bi_emlrtBCI, sp);
              }

              z[3 * b_i + 2] = detections[b_i].Measurement[2];
            }

            st.site = &lib_emlrtRSI;
            ptes = sum(&st, posterior);
            jpda.set_size(&an_emlrtRTEI, sp, posterior.size(0));
            loop_ub = posterior.size(0);
            for (i = 0; i < loop_ub; i++) {
              jpda[i] = posterior[i] / ptes;
            }

            st.site = &mib_emlrtRSI;
            this->Filter->correctjpda(&st, z, jpda);
            b_j = this->pAge;
            qY = b_j + 1U;
            if (b_j + 1U < b_j) {
              qY = MAX_uint32_T;
            }

            this->pAge = qY;
            if (0 > detections.size(0) - 1) {
              emlrtDynamicBoundsCheckR2012b(0, 0, detections.size(0) - 1,
                &vh_emlrtBCI, sp);
            }

            this->UpdateTime = detections[0].Time;
            if (1 > jpda.size(0) - 1) {
              loop_ub = 0;
            } else {
              if (1 > jpda.size(0)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, jpda.size(0), &oh_emlrtBCI,
                  sp);
              }

              if ((jpda.size(0) - 1 < 1) || (jpda.size(0) - 1 > jpda.size(0))) {
                emlrtDynamicBoundsCheckR2012b(jpda.size(0) - 1, 1, jpda.size(0),
                  &ph_emlrtBCI, sp);
              }

              loop_ub = jpda.size(0) - 1;
            }

            b_iv[0] = 1;
            b_iv[1] = loop_ub;
            st.site = &nib_emlrtRSI;
            ::coder::internal::indexShapeCheck(&st, jpda.size(0), b_iv);
            b_jpda.set_size(&bn_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_jpda[i] = jpda[i];
            }

            jpda.set_size(&bn_emlrtRTEI, sp, b_jpda.size(0));
            loop_ub = b_jpda.size(0);
            for (i = 0; i < loop_ub; i++) {
              jpda[i] = b_jpda[i];
            }

            st.site = &nib_emlrtRSI;
            ptes = sum(&st, jpda);
            if (ptes > 0.2) {
              this->pIsCoasted = false;
              st.site = &oib_emlrtRSI;
              this->TrackLogic->hit(&st);
            } else {
              this->pIsCoasted = true;
              st.site = &pib_emlrtRSI;
              this->TrackLogic->miss(&st);
            }

            if (!this->IsConfirmed) {
              this->IsConfirmed = this->checkPromotion();
            }

            emlrtHeapReferenceStackLeaveFcnR2012b(sp);
          }

          void ObjectTrack::distance(const emlrtStack *sp, const ::coder::array<
            objectDetection, 2U> &detections, const ::coder::array<real_T, 2U>
            &sensorDetections, ::coder::array<real_T, 2U> &cost)
          {
            trackingEKF *filter;
            array<real_T, 2U> b_sensorDetections;
            array<real_T, 2U> detTimes;
            array<real_T, 1U> ycol;
            array<int32_T, 1U> idx;
            array<int32_T, 1U> iwork;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack d_st;
            emlrtStack e_st;
            emlrtStack f_st;
            emlrtStack st;
            real_T dv[9];
            real_T unusedExpr[6];
            int32_T b_iv[2];
            int32_T b_i;
            int32_T k;
            int32_T qEnd;
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
            if ((detections.size(0) == 0) || (detections.size(1) == 0) ||
                (sensorDetections.size(1) == 0)) {
              st.site = &ncb_emlrtRSI;
              this->get_State(unusedExpr);
              cost.set_size(&hl_emlrtRTEI, sp, 1, 0);
            } else {
              real_T v1;
              real_T v2;
              int32_T i;
              int32_T j;
              int32_T m;
              int32_T n;
              int32_T pEnd;
              boolean_T b_overflow;
              boolean_T overflow;
              st.site = &ocb_emlrtRSI;
              pEnd = detections.size(0) * detections.size(1) - 1;
              if (0 > pEnd) {
                emlrtDynamicBoundsCheckR2012b(0, 0, pEnd, &hf_emlrtBCI, &st);
              }

              detTimes.set_size(&cl_emlrtRTEI, &st, sensorDetections.size(1), 2);
              m = sensorDetections.size(1) << 1;
              for (pEnd = 0; pEnd < m; pEnd++) {
                detTimes[pEnd] = 0.0;
              }

              pEnd = sensorDetections.size(1);
              for (i = 0; i < pEnd; i++) {
                if ((i + 1 < 1) || (i + 1 > detTimes.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(i + 1, 1, detTimes.size(0),
                    &if_emlrtBCI, &st);
                }

                detTimes[i] = static_cast<real_T>(i) + 1.0;
                j = detections.size(0) * detections.size(1) - 1;
                if ((i + 1 < 1) || (i + 1 > sensorDetections.size(1))) {
                  emlrtDynamicBoundsCheckR2012b(i + 1, 1, sensorDetections.size
                    (1), &jf_emlrtBCI, &st);
                }

                m = static_cast<int32_T>(sensorDetections[i]) - 1;
                if ((m < 0) || (m > j)) {
                  emlrtDynamicBoundsCheckR2012b(m, 0, j, &jf_emlrtBCI, &st);
                }

                detTimes[i + detTimes.size(0)] = detections[m].Time;
              }

              b_st.site = &pcb_emlrtRSI;
              c_st.site = &rcb_emlrtRSI;
              n = detTimes.size(0) + 1;
              idx.set_size(&dl_emlrtRTEI, &c_st, detTimes.size(0));
              m = detTimes.size(0);
              for (pEnd = 0; pEnd < m; pEnd++) {
                idx[pEnd] = 0;
              }

              d_st.site = &tcb_emlrtRSI;
              iwork.set_size(&th_emlrtRTEI, &d_st, detTimes.size(0));
              m = detTimes.size(0) - 1;
              e_st.site = &pn_emlrtRSI;
              if ((1 <= detTimes.size(0) - 1) && (detTimes.size(0) - 1 >
                   2147483645)) {
                f_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&f_st);
              }

              for (k = 1; k <= m; k += 2) {
                v1 = detTimes[(k + detTimes.size(0)) - 1];
                v2 = detTimes[k + detTimes.size(0)];
                if ((v1 == v2) || (muDoubleScalarIsNaN(v1) &&
                                   muDoubleScalarIsNaN(v2)) || (v1 <= v2) ||
                    muDoubleScalarIsNaN(v2)) {
                  idx[k - 1] = k;
                  idx[k] = k + 1;
                } else {
                  idx[k - 1] = k + 1;
                  idx[k] = k;
                }
              }

              if ((detTimes.size(0) & 1) != 0) {
                idx[detTimes.size(0) - 1] = detTimes.size(0);
              }

              i = 2;
              while (i < n - 1) {
                m = i << 1;
                j = 1;
                for (pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
                  int32_T kEnd;
                  int32_T p;
                  int32_T q;
                  p = j;
                  q = pEnd;
                  qEnd = j + m;
                  if (qEnd > n) {
                    qEnd = n;
                  }

                  k = 0;
                  kEnd = qEnd - j;
                  while (k + 1 <= kEnd) {
                    int32_T v1_tmp;
                    int32_T v2_tmp;
                    v1_tmp = idx[p - 1];
                    v1 = detTimes[(v1_tmp + detTimes.size(0)) - 1];
                    v2_tmp = idx[q - 1];
                    v2 = detTimes[(v2_tmp + detTimes.size(0)) - 1];
                    if ((v1 == v2) || (muDoubleScalarIsNaN(v1) &&
                                       muDoubleScalarIsNaN(v2)) || (v1 <= v2) ||
                        muDoubleScalarIsNaN(v2)) {
                      iwork[k] = v1_tmp;
                      p++;
                      if (p == pEnd) {
                        while (q < qEnd) {
                          k++;
                          iwork[k] = idx[q - 1];
                          q++;
                        }
                      }
                    } else {
                      iwork[k] = v2_tmp;
                      q++;
                      if (q == qEnd) {
                        while (p < pEnd) {
                          k++;
                          iwork[k] = idx[p - 1];
                          p++;
                        }
                      }
                    }

                    k++;
                  }

                  e_st.site = &qn_emlrtRSI;
                  for (k = 0; k < kEnd; k++) {
                    idx[(j + k) - 1] = iwork[k];
                  }

                  j = qEnd;
                }

                i = m;
              }

              c_st.site = &scb_emlrtRSI;
              m = detTimes.size(0);
              ycol.set_size(&el_emlrtRTEI, &c_st, detTimes.size(0));
              overflow = (detTimes.size(0) > 2147483646);
              b_overflow = (detTimes.size(0) > 2147483646);
              d_st.site = &ucb_emlrtRSI;
              if (overflow) {
                e_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&e_st);
              }

              for (i = 0; i < m; i++) {
                ycol[i] = detTimes[idx[i] - 1];
              }

              d_st.site = &vcb_emlrtRSI;
              if (b_overflow) {
                e_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&e_st);
              }

              for (i = 0; i < m; i++) {
                detTimes[i] = ycol[i];
              }

              d_st.site = &ucb_emlrtRSI;
              for (i = 0; i < m; i++) {
                ycol[i] = detTimes[(idx[i] + detTimes.size(0)) - 1];
              }

              d_st.site = &vcb_emlrtRSI;
              for (i = 0; i < m; i++) {
                detTimes[i + detTimes.size(0)] = ycol[i];
              }

              b_iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                          &sensorDetections)->size())[0];
              b_iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                          &sensorDetections)->size())[1];
              b_st.site = &qcb_emlrtRSI;
              ::coder::internal::b_indexShapeCheck(&b_st, b_iv, detTimes.size(0));
              b_st.site = &qcb_emlrtRSI;
              m = detTimes.size(0);
              b_sensorDetections.set_size(&fl_emlrtRTEI, &b_st, 1, detTimes.size
                (0));
              for (pEnd = 0; pEnd < m; pEnd++) {
                if (detTimes[pEnd] != static_cast<int32_T>(muDoubleScalarFloor
                     (detTimes[pEnd]))) {
                  emlrtIntegerCheckR2012b(detTimes[pEnd], &bb_emlrtDCI, &b_st);
                }

                j = static_cast<int32_T>(detTimes[pEnd]);
                if ((j < 1) || (j > sensorDetections.size(1))) {
                  emlrtDynamicBoundsCheckR2012b(j, 1, sensorDetections.size(1),
                    &kf_emlrtBCI, &b_st);
                }

                b_sensorDetections[pEnd] = sensorDetections[j - 1];
              }

              c_st.site = &wcb_emlrtRSI;
              this->get_State(unusedExpr);
              cost.set_size(&gl_emlrtRTEI, &b_st, 1, detTimes.size(0));
              m = detTimes.size(0);
              for (pEnd = 0; pEnd < m; pEnd++) {
                cost[pEnd] = rtInf;
              }

              v1 = this->Time;
              c_st.site = &xcb_emlrtRSI;
              this->pDistanceFilter->sync(&c_st, this->Filter);
              pEnd = detTimes.size(0);
              if (0 <= detTimes.size(0) - 1) {
                b_i = detTimes.size(0);
              }

              for (k = 0; k < pEnd; k++) {
                if ((k + 1 < 1) || (k + 1 > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_i, &gf_emlrtBCI,
                    &b_st);
                }

                v2 = b_sensorDetections[k];
                j = detections.size(0) * detections.size(1) - 1;
                if ((static_cast<int32_T>(v2) - 1 < 0) || (static_cast<int32_T>
                     (v2) - 1 > j)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(v2) - 1, 0,
                    j, &gf_emlrtBCI, &b_st);
                }

                detections[static_cast<int32_T>(v2) - 1].get_MeasurementNoise(dv);
                c_st.site = &ycb_emlrtRSI;
                this->pDistanceFilter->set_MeasurementNoise(&c_st, dv);
                if ((this->ObjectClassID == 0.0) || (detections
                     [static_cast<int32_T>(v2) - 1].ObjectClassID == 0.0) ||
                    (this->ObjectClassID == detections[static_cast<int32_T>(v2)
                     - 1].ObjectClassID)) {
                  v1 = detections[static_cast<int32_T>(v2) - 1].Time - v1;
                  if (v1 > 0.0) {
                    c_st.site = &adb_emlrtRSI;
                    filter = this->pDistanceFilter;
                    d_st.site = &ly_emlrtRSI;
                    filter->predict(&d_st, v1);
                  }

                  v1 = detections[static_cast<int32_T>(v2) - 1].Time;
                  c_st.site = &bdb_emlrtRSI;
                  if ((k + 1 < 1) || (k + 1 > cost.size(1))) {
                    emlrtDynamicBoundsCheckR2012b(k + 1, 1, cost.size(1),
                      &lf_emlrtBCI, &c_st);
                  }

                  d_st.site = &cdb_emlrtRSI;
                  cost[k] = this->pDistanceFilter->distance(&d_st, detections[
                    static_cast<int32_T>(v2) - 1].Measurement);
                }
              }
            }

            emlrtHeapReferenceStackLeaveFcnR2012b(sp);
          }

          void ObjectTrack::get_State(real_T state[6]) const
          {
            this->Filter->get_State(state);
          }

          ObjectTrack *ObjectTrack::init(trackingEKF *varargin_4, real_T
            varargin_10, trackHistoryLogic *varargin_12)
          {
            ObjectTrack *b_track;
            ObjectTrack *track;
            b_trackHistoryLogic lobj_0;
            track = this;
            lobj_0.init();
            b_track = track;
            track->BranchID = 1U;
            track->TrackID = 0U;
            track->set_Filter(varargin_4);
            track->pDistanceFilter = varargin_4->clone(&track->_pobj0);
            b_track->UpdateTime = 0.0;
            b_track->Time = 0.0;
            b_track->ObjectClassID = varargin_10;
            b_track->set_TrackLogic(varargin_12);
            for (int32_T i = 0; i < 20; i++) {
              b_track->pUsedObjectAttributes[i] = false;
            }

            b_track->pUsedObjectAttributes[0] = true;
            return track;
          }

          void ObjectTrack::nullify(const emlrtStack *sp)
          {
            emlrtStack st;
            st.prev = sp;
            st.tls = sp->tls;
            this->BranchID = 0U;
            this->TrackID = 0U;
            this->IsConfirmed = false;
            this->ObjectClassID = 0.0;
            for (int32_T i = 0; i < 20; i++) {
              this->pUsedObjectAttributes[i] = false;
            }

            this->UpdateTime = 0.0;
            this->Time = 0.0;
            this->pAge = 0U;
            this->pIsCoasted = true;
            this->TrackLogic->reset();
            st.site = &tv_emlrtRSI;
            this->Filter->nullify(&st);
            st.site = &uv_emlrtRSI;
            this->pDistanceFilter->nullify(&st);
          }

          void ObjectTrack::predict(const emlrtStack *sp, real_T b_time)
          {
            trackingEKF *filter;
            emlrtStack b_st;
            emlrtStack st;
            real_T dt;
            boolean_T p;
            st.prev = sp;
            st.tls = sp->tls;
            st.site = &hy_emlrtRSI;
            b_st.prev = &st;
            b_st.tls = st.tls;
            b_st.site = &yb_emlrtRSI;
            p = !(b_time < 0.0);
            if (!p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI,
                "Coder:toolbox:ValidateattributesexpectedNonnegative",
                "MATLAB:predict:expectedNonnegative", 3, 4, 4, "time");
            }

            b_st.site = &yb_emlrtRSI;
            p = ((!muDoubleScalarIsInf(b_time)) && (!muDoubleScalarIsNaN(b_time)));
            if (!p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
                "Coder:toolbox:ValidateattributesexpectedFinite",
                "MATLAB:predict:expectedFinite", 3, 4, 4, "time");
            }

            dt = b_time - this->Time;
            if (!(dt <= 0.0)) {
              st.site = &iy_emlrtRSI;
              filter = this->Filter;
              b_st.site = &ly_emlrtRSI;
              filter->predict(&b_st, dt);
              this->Time = b_time;
            }
          }

          void ObjectTrack::setObjectAttributes(const emlrtStack *sp, real_T
            sensorIndex)
          {
            emlrtStack b_st;
            emlrtStack st;
            int32_T i;
            int32_T i1;
            boolean_T p;
            st.prev = sp;
            st.tls = sp->tls;
            st.site = &rib_emlrtRSI;
            b_st.prev = &st;
            b_st.tls = st.tls;
            b_st.site = &yb_emlrtRSI;
            p = !(sensorIndex <= 0.0);
            if (!p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &y_emlrtRTEI,
                "Coder:toolbox:ValidateattributesexpectedPositive",
                "MATLAB:MultiObjectTracker:expectedPositive", 3, 4, 27,
                "objectDetection.SensorIndex");
            }

            b_st.site = &yb_emlrtRSI;
            p = true;
            if (muDoubleScalarIsInf(sensorIndex) || muDoubleScalarIsNaN
                (sensorIndex) || (!(muDoubleScalarFloor(sensorIndex) ==
                                    sensorIndex))) {
              p = false;
            }

            if (!p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &s_emlrtRTEI,
                "Coder:toolbox:ValidateattributesexpectedInteger",
                "MATLAB:MultiObjectTracker:expectedInteger", 3, 4, 27,
                "objectDetection.SensorIndex");
            }

            b_st.site = &yb_emlrtRSI;
            p = (sensorIndex <= 20.0);
            if (!p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &vc_emlrtRTEI,
                "MATLAB:validateattributes:expectedScalar",
                "MATLAB:MultiObjectTracker:notLessEqual", 9, 4, 27,
                "objectDetection.SensorIndex", 4, 2, "<=", 4, 2, "20");
            }

            i = static_cast<int32_T>(muDoubleScalarFloor(sensorIndex));
            if (sensorIndex != i) {
              emlrtIntegerCheckR2012b(sensorIndex, &hb_emlrtDCI, sp);
            }

            i1 = static_cast<int32_T>(sensorIndex);
            if ((i1 - 1 < 0.0) || (i1 - 1 > 19.0)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(sensorIndex) -
                1, 0, 19, &di_emlrtBCI, sp);
            }

            if (i1 != i) {
              emlrtIntegerCheckR2012b(sensorIndex, &ib_emlrtDCI, sp);
            }

            if ((sensorIndex < 1.0) || (sensorIndex > 20.0)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(sensorIndex), 1,
                20, &ci_emlrtBCI, sp);
            }

            this->pUsedObjectAttributes[static_cast<int32_T>(sensorIndex) - 1] =
              true;
          }

          void ObjectTrack::set_IsCoasted()
          {
            this->pIsCoasted = false;
          }

          void ObjectTrack::trackToStruct(const emlrtStack *sp, struct1_T
            *trackStruct)
          {
            static const char_T logicType[7] = { 'H', 'i', 's', 't', 'o', 'r',
              'y' };

            emlrtStack st;
            real_T dv[36];
            real_T t0_UpdateTime;
            int32_T i;
            uint32_T t0_Age;
            uint32_T t0_BranchID;
            uint32_T t0_TrackID;
            int8_T b_iv[6];
            boolean_T t0_IsCoasted;
            st.prev = sp;
            st.tls = sp->tls;
            t0_TrackID = this->TrackID;
            t0_BranchID = this->BranchID;
            t0_UpdateTime = this->Time;
            t0_Age = this->pAge;
            this->get_State(trackStruct->State);
            for (i = 0; i < 6; i++) {
              b_iv[i] = static_cast<int8_T>(i + 1);
            }

            this->get_StateCovariance(dv);
            for (i = 0; i < 6; i++) {
              for (int32_T i1 = 0; i1 < 6; i1++) {
                trackStruct->StateCovariance[i1 + 6 * i] = dv[(b_iv[i1] + 6 *
                  (b_iv[i] - 1)) - 1];
              }
            }

            this->TrackLogic->output(trackStruct->TrackLogicState);
            t0_IsCoasted = this->get_IsCoasted();
            trackStruct->TrackID = t0_TrackID;
            trackStruct->BranchID = t0_BranchID;
            trackStruct->SourceIndex = 0U;
            trackStruct->UpdateTime = t0_UpdateTime;
            trackStruct->Age = t0_Age;
            trackStruct->ObjectClassID = this->ObjectClassID;
            for (i = 0; i < 7; i++) {
              trackStruct->TrackLogic[i] = logicType[i];
            }

            trackStruct->IsConfirmed = this->IsConfirmed;
            trackStruct->IsCoasted = t0_IsCoasted;
            trackStruct->IsSelfReported = true;
            st.site = &fx_emlrtRSI;
            this->get_ObjectAttributes(&st, trackStruct->ObjectAttributes.size);
          }

          void ObjectTrack::updateNotAssociated(const emlrtStack *sp)
          {
            emlrtStack st;
            uint32_T q0;
            uint32_T qY;
            st.prev = sp;
            st.tls = sp->tls;
            this->pIsCoasted = true;
            st.site = &ckb_emlrtRSI;
            this->TrackLogic->miss(&st);
            q0 = this->pAge;
            qY = q0 + 1U;
            if (q0 + 1U < q0) {
              qY = MAX_uint32_T;
            }

            this->pAge = qY;
          }
        }
      }
    }
  }
}

// End of code generation (ObjectTrack.cpp)
