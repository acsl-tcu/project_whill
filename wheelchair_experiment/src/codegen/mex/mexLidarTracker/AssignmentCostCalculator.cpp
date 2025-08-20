//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  AssignmentCostCalculator.cpp
//
//  Code generation for function 'AssignmentCostCalculator'
//


// Include files
#include "AssignmentCostCalculator.h"
#include "ObjectTrack.h"
#include "anonymous_function.h"
#include "det.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "objectDetection.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "trackingEKF.h"
#include "warning.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

// Variable Definitions
static emlrtRSInfo hbb_emlrtRSI = { 239,// lineNo
  "AssignmentCostCalculator/validateInputsImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo ibb_emlrtRSI = { 240,// lineNo
  "AssignmentCostCalculator/validateInputsImpl",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo kbb_emlrtRSI = { 173,// lineNo
  "AssignmentCostCalculator/stepImpl", // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo lbb_emlrtRSI = { 169,// lineNo
  "AssignmentCostCalculator/stepImpl", // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo mbb_emlrtRSI = { 314,// lineNo
  "AssignmentCostCalculator/findPairsToCost",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo nbb_emlrtRSI = { 306,// lineNo
  "AssignmentCostCalculator/findPairsToCost",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo obb_emlrtRSI = { 291,// lineNo
  "AssignmentCostCalculator/findPairsToCost",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo pbb_emlrtRSI = { 285,// lineNo
  "AssignmentCostCalculator/findPairsToCost",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo qbb_emlrtRSI = { 280,// lineNo
  "AssignmentCostCalculator/findPairsToCost",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo rbb_emlrtRSI = { 273,// lineNo
  "AssignmentCostCalculator/findPairsToCost",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo sbb_emlrtRSI = { 270,// lineNo
  "AssignmentCostCalculator/findPairsToCost",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pathName 
};

static emlrtRSInfo dcb_emlrtRSI = { 47,// lineNo
  "function_handle/parenReference",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/function_handle.m"// pathName 
};

static emlrtRSInfo fcb_emlrtRSI = { 163,// lineNo
  "cvmeas",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/cvmeas.m"// pathName 
};

static emlrtRSInfo gcb_emlrtRSI = { 61,// lineNo
  "global2localcoord",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/global2localcoord.m"// pathName 
};

static emlrtRSInfo lcb_emlrtRSI = { 299,// lineNo
  "lusolve3x3",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/lusolve.m"// pathName 
};

static emlrtBCInfo ge_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  171,                                 // lineNo
  32,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo he_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  175,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ie_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  175,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo je_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  175,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ke_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  175,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo n_emlrtECI = { -1,  // nDims
  173,                                 // lineNo
  17,                                  // colNo
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtBCInfo le_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  173,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo me_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  173,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ne_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  172,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo hc_emlrtRTEI = { 170,// lineNo
  19,                                  // colNo
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtBCInfo oe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  165,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo pe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  165,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  165,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo re_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  172,                                 // lineNo
  43,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo se_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  173,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo u_emlrtDCI = { 161, // lineNo
  34,                                  // colNo
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo v_emlrtDCI = { 161, // lineNo
  34,                                  // colNo
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo w_emlrtDCI = { 161, // lineNo
  17,                                  // colNo
  "AssignmentCostCalculator/stepImpl", // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo te_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  138,                                 // lineNo
  36,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/setupImpl",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ue_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  141,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/setupImpl",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ve_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  283,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo we_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  321,                                 // lineNo
  61,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  321,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ye_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  321,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo o_emlrtECI = { -1,  // nDims
  315,                                 // lineNo
  21,                                  // colNo
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtBCInfo af_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  315,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  315,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo p_emlrtECI = { 2,   // nDims
  314,                                 // lineNo
  37,                                  // colNo
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo ic_emlrtRTEI = { 272,// lineNo
  19,                                  // colNo
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtECInfo q_emlrtECI = { -1,  // nDims
  158,                                 // lineNo
  1,                                   // colNo
  "cvmeas",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/cvmeas.m"// pName
};

static emlrtECInfo r_emlrtECI = { -1,  // nDims
  159,                                 // lineNo
  1,                                   // colNo
  "cvmeas",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/cvmeas.m"// pName
};

static emlrtECInfo s_emlrtECI = { 2,   // nDims
  61,                                  // lineNo
  26,                                  // colNo
  "global2localcoord",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/global2localcoord.m"// pName 
};

static emlrtDCInfo x_emlrtDCI = { 261, // lineNo
  39,                                  // colNo
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo y_emlrtDCI = { 261, // lineNo
  17,                                  // colNo
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo ab_emlrtDCI = { 271,// lineNo
  42,                                  // colNo
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo cf_emlrtBCI = { 0,  // iFirst
  29,                                  // iLast
  273,                                 // lineNo
  34,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo df_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  273,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ef_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  278,                                 // lineNo
  37,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ff_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  278,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "AssignmentCostCalculator/findPairsToCost",// fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo jk_emlrtRTEI = { 161,// lineNo
  17,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo kk_emlrtRTEI = { 172,// lineNo
  43,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo lk_emlrtRTEI = { 173,// lineNo
  30,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo mk_emlrtRTEI = { 1,// lineNo
  1,                                   // colNo
  "SystemCore",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pName 
};

static emlrtRTEInfo nk_emlrtRTEI = { 172,// lineNo
  32,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo ok_emlrtRTEI = { 261,// lineNo
  17,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo pk_emlrtRTEI = { 271,// lineNo
  25,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo qk_emlrtRTEI = { 276,// lineNo
  30,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo sk_emlrtRTEI = { 156,// lineNo
  1,                                   // colNo
  "cvmeas",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/cvmeas.m"// pName
};

static emlrtRTEInfo tk_emlrtRTEI = { 61,// lineNo
  34,                                  // colNo
  "global2localcoord",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/global2localcoord.m"// pName 
};

static emlrtRTEInfo uk_emlrtRTEI = { 61,// lineNo
  26,                                  // colNo
  "global2localcoord",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/global2localcoord.m"// pName 
};

static emlrtRTEInfo vk_emlrtRTEI = { 312,// lineNo
  40,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo xk_emlrtRTEI = { 298,// lineNo
  24,                                  // colNo
  "lusolve",                           // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/lusolve.m"// pName
};

static emlrtRTEInfo yk_emlrtRTEI = { 314,// lineNo
  37,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo al_emlrtRTEI = { 315,// lineNo
  58,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
};

static emlrtRTEInfo bl_emlrtRTEI = { 321,// lineNo
  13,                                  // colNo
  "AssignmentCostCalculator",          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/AssignmentCostCalculator.m"// pName 
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
          void AssignmentCostCalculator::findPairsToCost(const emlrtStack *sp,
            ObjectTrack *tracks[30], const ::coder::array<objectDetection, 2U>
            &detections, real_T numLiveTracks, const ::coder::array<real_T, 2U>
            &detIndices, ::coder::array<boolean_T, 2U> &toCalculate)
          {
            static const real_T A[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
              1.0 };

            ptrdiff_t k_t;
            ptrdiff_t lda_t;
            ptrdiff_t ldb_t;
            ptrdiff_t ldc_t;
            ptrdiff_t m_t;
            ptrdiff_t n_t;
            array<real_T, 2U> a;
            array<real_T, 2U> allStates;
            array<real_T, 2U> detectionTimes;
            array<real_T, 2U> diffs;
            array<real_T, 2U> lclRect;
            array<real_T, 2U> tgtpos;
            array<real_T, 1U> y;
            array<int32_T, 2U> iidx;
            array<boolean_T, 2U> allToCalculate;
            array<boolean_T, 1U> r;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack d_st;
            emlrtStack e_st;
            emlrtStack f_st;
            emlrtStack st;
            real_T S[9];
            real_T b_A[9];
            real_T unusedExpr[6];
            real_T alpha1;
            real_T beta1;
            real_T lastTrackTime;
            int32_T b_iv[2];
            int32_T b_iv1[2];
            int32_T acoef;
            int32_T b_i;
            int32_T i;
            int32_T i1;
            int32_T loop_ub;
            int32_T r2;
            int32_T r3;
            int32_T rtemp;
            char_T TRANSA1;
            char_T TRANSB1;
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
            i = static_cast<int32_T>(muDoubleScalarFloor(numLiveTracks));
            if (numLiveTracks != i) {
              emlrtIntegerCheckR2012b(numLiveTracks, &x_emlrtDCI, sp);
            }

            loop_ub = static_cast<int32_T>(numLiveTracks);
            allToCalculate.set_size(&ok_emlrtRTEI, sp, loop_ub, detIndices.size
              (1));
            if (loop_ub != i) {
              emlrtIntegerCheckR2012b(numLiveTracks, &y_emlrtDCI, sp);
            }

            rtemp = loop_ub * detIndices.size(1);
            for (r3 = 0; r3 < rtemp; r3++) {
              allToCalculate[r3] = true;
            }

            lastTrackTime = tracks[0]->UpdateTime;
            st.site = &sbb_emlrtRSI;
            tracks[0]->get_State(unusedExpr);
            allStates.set_size(&pk_emlrtRTEI, sp, 6, allStates.size(1));
            if (loop_ub != i) {
              emlrtIntegerCheckR2012b(numLiveTracks, &ab_emlrtDCI, sp);
            }

            allStates.set_size(&pk_emlrtRTEI, sp, allStates.size(0), loop_ub);
            emlrtForLoopVectorCheckR2012b(1.0, 1.0, numLiveTracks,
              mxDOUBLE_CLASS, static_cast<int32_T>(numLiveTracks), &ic_emlrtRTEI,
              sp);
            for (r2 = 0; r2 < loop_ub; r2++) {
              if (r2 > 29) {
                emlrtDynamicBoundsCheckR2012b(r2, 0, 29, &cf_emlrtBCI, sp);
              }

              if (r2 + 1 > allStates.size(1)) {
                emlrtDynamicBoundsCheckR2012b(r2 + 1, 1, allStates.size(1),
                  &df_emlrtBCI, sp);
              }

              st.site = &rbb_emlrtRSI;
              tracks[r2]->get_State(*(real_T (*)[6])&allStates[6 * r2]);
            }

            detectionTimes.set_size(&qk_emlrtRTEI, sp, 1, detIndices.size(1));
            i = detIndices.size(1);
            for (b_i = 0; b_i < i; b_i++) {
              r3 = detections.size(0) * detections.size(1) - 1;
              if ((b_i + 1 < 1) || (b_i + 1 > detIndices.size(1))) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, detIndices.size(1),
                  &ef_emlrtBCI, sp);
              }

              acoef = static_cast<int32_T>(detIndices[b_i]) - 1;
              if ((acoef < 0) || (acoef > r3)) {
                emlrtDynamicBoundsCheckR2012b(acoef, 0, r3, &ef_emlrtBCI, sp);
              }

              if ((b_i + 1 < 1) || (b_i + 1 > detectionTimes.size(1))) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, detectionTimes.size(1),
                  &ff_emlrtBCI, sp);
              }

              detectionTimes[b_i] = detections[acoef].Time;
            }

            st.site = &qbb_emlrtRSI;
            b_st.site = &tbb_emlrtRSI;
            ::coder::internal::sort(&b_st, detectionTimes, iidx);
            detectionTimes.set_size(&rk_emlrtRTEI, &st, 1, iidx.size(1));
            rtemp = iidx.size(0) * iidx.size(1);
            for (i = 0; i < rtemp; i++) {
              detectionTimes[i] = iidx[i];
            }

            i = detIndices.size(1);
            if (0 <= detIndices.size(1) - 1) {
              TRANSB1 = 'N';
              TRANSA1 = 'T';
              alpha1 = 1.0;
              beta1 = 0.0;
              m_t = (ptrdiff_t)3;
              k_t = (ptrdiff_t)3;
              lda_t = (ptrdiff_t)3;
              ldb_t = (ptrdiff_t)3;
              ldc_t = (ptrdiff_t)3;
            }

            if (0 <= i - 1) {
              i1 = detections.size(0) * detections.size(1) - 1;
            }

            for (b_i = 0; b_i < i; b_i++) {
              real_T a21;
              real_T maxval;
              int32_T k;
              boolean_T exitg1;
              boolean_T overflow;
              if ((b_i + 1 < 1) || (b_i + 1 > detectionTimes.size(1))) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, detectionTimes.size(1),
                  &ve_emlrtBCI, sp);
              }

              r3 = static_cast<int32_T>(detectionTimes[b_i]);
              if ((r3 < 1) || (r3 > detIndices.size(1))) {
                emlrtDynamicBoundsCheckR2012b(r3, 1, detIndices.size(1),
                  &ve_emlrtBCI, sp);
              }

              r3 = static_cast<int32_T>(detIndices[r3 - 1]) - 1;
              if ((r3 < 0) || (r3 > i1)) {
                emlrtDynamicBoundsCheckR2012b(r3, 0, i1, &ve_emlrtBCI, sp);
              }

              st.site = &pbb_emlrtRSI;
              tracks[0]->Filter->models();
              st.site = &obb_emlrtRSI;
              maxval = detectionTimes[b_i];
              b_st.site = &dcb_emlrtRSI;
              trackingEKF::anon(&b_st, allStates, detections[static_cast<int32_T>
                                (detIndices[static_cast<int32_T>(maxval) - 1]) -
                                1].Time - lastTrackTime);
              lastTrackTime = detections[static_cast<int32_T>(detIndices[
                static_cast<int32_T>(maxval) - 1]) - 1].Time;
              st.site = &nbb_emlrtRSI;
              b_st.site = &ecb_emlrtRSI;
              c_st.site = &yb_emlrtRSI;
              overflow = true;
              r3 = 6 * allStates.size(1);
              k = 0;
              exitg1 = false;
              while ((!exitg1) && (k <= r3 - 1)) {
                if ((!muDoubleScalarIsInf(allStates[k])) &&
                    (!muDoubleScalarIsNaN(allStates[k]))) {
                  k++;
                } else {
                  overflow = false;
                  exitg1 = true;
                }
              }

              if (!overflow) {
                emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
                  "Coder:toolbox:ValidateattributesexpectedFinite",
                  "MATLAB:cvmeas:expectedFinite", 3, 4, 22,
                  "input number 1, state,");
              }

              tgtpos.set_size(&sk_emlrtRTEI, &st, 3, allStates.size(1));
              rtemp = 3 * allStates.size(1);
              for (r3 = 0; r3 < rtemp; r3++) {
                tgtpos[r3] = 0.0;
              }

              rtemp = allStates.size(1);
              b_iv[0] = 3;
              b_iv[1] = allStates.size(1);
              b_iv1[0] = 3;
              b_iv1[1] = allStates.size(1);
              emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &b_iv1[0], 2,
                &q_emlrtECI, &st);
              for (r3 = 0; r3 < rtemp; r3++) {
                tgtpos[3 * r3] = allStates[6 * r3];
                tgtpos[3 * r3 + 1] = allStates[6 * r3 + 2];
                tgtpos[3 * r3 + 2] = allStates[6 * r3 + 4];
              }

              b_iv[0] = 3;
              b_iv[1] = allStates.size(1);
              b_iv1[0] = 3;
              b_iv1[1] = allStates.size(1);
              emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &b_iv1[0], 2,
                &r_emlrtECI, &st);
              b_st.site = &fcb_emlrtRSI;
              lclRect.set_size(&tk_emlrtRTEI, &b_st, 3, tgtpos.size(1));
              rtemp = tgtpos.size(1);
              for (r3 = 0; r3 < rtemp; r3++) {
                lclRect[3 * r3] = 0.0;
                lclRect[3 * r3 + 1] = 0.0;
                lclRect[3 * r3 + 2] = 0.0;
              }

              emlrtSizeEqCheckNDR2012b(tgtpos.size(), lclRect.size(),
                &s_emlrtECI, &b_st);
              c_st.site = &gcb_emlrtRSI;
              rtemp = tgtpos.size(0) * tgtpos.size(1);
              tgtpos.set_size(&uk_emlrtRTEI, &c_st, 3, tgtpos.size(1));
              for (r3 = 0; r3 < rtemp; r3++) {
                tgtpos[r3] = tgtpos[r3] - lclRect[r3];
              }

              d_st.site = &yj_emlrtRSI;
              e_st.site = &ak_emlrtRSI;
              f_st.site = &ck_emlrtRSI;
              n_t = (ptrdiff_t)tgtpos.size(1);
              lclRect.set_size(&og_emlrtRTEI, &f_st, 3, tgtpos.size(1));
              dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A
                    [0], &lda_t, &(tgtpos.data())[0], &ldb_t, &beta1,
                    &(lclRect.data())[0], &ldc_t);
              r2 = static_cast<int32_T>(detIndices[static_cast<int32_T>
                (detectionTimes[b_i]) - 1]) - 1;
              detections[r2].get_MeasurementNoise(S);
              a.set_size(&vk_emlrtRTEI, sp, lclRect.size(1), 3);
              rtemp = lclRect.size(1);
              for (r3 = 0; r3 < 3; r3++) {
                for (acoef = 0; acoef < rtemp; acoef++) {
                  a[acoef + a.size(0) * r3] = lclRect[r3 + 3 * acoef];
                }
              }

              diffs.set_size(&wk_emlrtRTEI, sp, a.size(0), 3);
              acoef = (a.size(0) != 1);
              for (k = 0; k < 3; k++) {
                r3 = diffs.size(0) - 1;
                for (rtemp = 0; rtemp <= r3; rtemp++) {
                  diffs[rtemp + diffs.size(0) * k] = a[acoef * rtemp + a.size(0)
                    * k] - detections[r2].Measurement[k];
                }
              }

              st.site = &mbb_emlrtRSI;
              b_st.site = &hcb_emlrtRSI;
              c_st.site = &icb_emlrtRSI;
              d_st.site = &jcb_emlrtRSI;
              memcpy(&b_A[0], &S[0], 9U * sizeof(real_T));
              acoef = 0;
              r2 = 1;
              r3 = 2;
              maxval = muDoubleScalarAbs(S[0]);
              a21 = muDoubleScalarAbs(S[1]);
              if (a21 > maxval) {
                maxval = a21;
                acoef = 1;
                r2 = 0;
              }

              if (muDoubleScalarAbs(S[2]) > maxval) {
                acoef = 2;
                r2 = 1;
                r3 = 0;
              }

              b_A[r2] = S[r2] / S[acoef];
              b_A[r3] /= b_A[acoef];
              b_A[r2 + 3] -= b_A[r2] * b_A[acoef + 3];
              b_A[r3 + 3] -= b_A[r3] * b_A[acoef + 3];
              b_A[r2 + 6] -= b_A[r2] * b_A[acoef + 6];
              b_A[r3 + 6] -= b_A[r3] * b_A[acoef + 6];
              if (muDoubleScalarAbs(b_A[r3 + 3]) > muDoubleScalarAbs(b_A[r2 + 3]))
              {
                rtemp = r2;
                r2 = r3;
                r3 = rtemp;
              }

              b_A[r3 + 3] /= b_A[r2 + 3];
              b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
              if ((b_A[acoef] == 0.0) || (b_A[r2 + 3] == 0.0) || (b_A[r3 + 6] ==
                   0.0)) {
                e_st.site = &kcb_emlrtRSI;
                f_st.site = &mcb_emlrtRSI;
                ::coder::internal::f_warning(&f_st);
              }

              rtemp = diffs.size(0);
              a.set_size(&xk_emlrtRTEI, &d_st, diffs.size(0), 3);
              e_st.site = &lcb_emlrtRSI;
              if ((1 <= diffs.size(0)) && (diffs.size(0) > 2147483646)) {
                f_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&f_st);
              }

              for (k = 0; k < rtemp; k++) {
                a[k + a.size(0) * acoef] = diffs[k] / b_A[acoef];
                a[k + a.size(0) * r2] = diffs[k + diffs.size(0)] - a[k + a.size
                  (0) * acoef] * b_A[acoef + 3];
                a[k + a.size(0) * r3] = diffs[k + diffs.size(0) * 2] - a[k +
                  a.size(0) * acoef] * b_A[acoef + 6];
                a[k + a.size(0) * r2] = a[k + a.size(0) * r2] / b_A[r2 + 3];
                a[k + a.size(0) * r3] = a[k + a.size(0) * r3] - a[k + a.size(0) *
                  r2] * b_A[r2 + 6];
                a[k + a.size(0) * r3] = a[k + a.size(0) * r3] / b_A[r3 + 6];
                a[k + a.size(0) * r2] = a[k + a.size(0) * r2] - a[k + a.size(0) *
                  r3] * b_A[r3 + 3];
                a[k + a.size(0) * acoef] = a[k + a.size(0) * acoef] - a[k +
                  a.size(0) * r3] * b_A[r3];
                a[k + a.size(0) * acoef] = a[k + a.size(0) * acoef] - a[k +
                  a.size(0) * r2] * b_A[r2];
              }

              emlrtSizeEqCheckNDR2012b(a.size(), diffs.size(), &p_emlrtECI, sp);
              st.site = &mbb_emlrtRSI;
              rtemp = a.size(0) * a.size(1);
              a.set_size(&yk_emlrtRTEI, &st, a.size(0), 3);
              for (r3 = 0; r3 < rtemp; r3++) {
                a[r3] = a[r3] * diffs[r3];
              }

              b_st.site = &fk_emlrtRSI;
              c_st.site = &xi_emlrtRSI;
              d_st.site = &yi_emlrtRSI;
              rtemp = a.size(0);
              y.set_size(&kg_emlrtRTEI, &d_st, a.size(0));
              e_st.site = &aj_emlrtRSI;
              if ((1 <= a.size(0)) && (a.size(0) > 2147483646)) {
                f_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&f_st);
              }

              for (r2 = 0; r2 < rtemp; r2++) {
                y[r2] = a[r2];
              }

              overflow = ((1 <= a.size(0)) && (a.size(0) > 2147483646));
              e_st.site = &bj_emlrtRSI;
              if (overflow) {
                f_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&f_st);
              }

              for (r2 = 0; r2 < rtemp; r2++) {
                y[r2] = y[r2] + a[rtemp + r2];
              }

              acoef = 2 * a.size(0);
              e_st.site = &bj_emlrtRSI;
              for (r2 = 0; r2 < rtemp; r2++) {
                y[r2] = y[r2] + a[acoef + r2];
              }

              st.site = &mbb_emlrtRSI;
              b_st.site = &mbb_emlrtRSI;
              maxval = det(&b_st, S);
              if (maxval < 0.0) {
                emlrtErrorWithMessageIdR2018a(&st, &jc_emlrtRTEI,
                  "Coder:toolbox:ElFunDomainError",
                  "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
              }

              maxval = muDoubleScalarLog(maxval);
              if ((numLiveTracks < 1.0) || (loop_ub > allToCalculate.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numLiveTracks),
                  1, allToCalculate.size(0), &bf_emlrtBCI, sp);
              }

              r3 = b_i + 1;
              if ((r3 < 1) || (r3 > allToCalculate.size(1))) {
                emlrtDynamicBoundsCheckR2012b(r3, 1, allToCalculate.size(1),
                  &af_emlrtBCI, sp);
              }

              r.set_size(&al_emlrtRTEI, sp, y.size(0));
              rtemp = y.size(0);
              for (r3 = 0; r3 < rtemp; r3++) {
                r[r3] = (y[r3] + maxval < 100.0);
              }

              emlrtSubAssignSizeCheckR2012b(&loop_ub, 1, r.size(), 1,
                &o_emlrtECI, sp);
              rtemp = r.size(0);
              for (r3 = 0; r3 < rtemp; r3++) {
                allToCalculate[r3 + allToCalculate.size(0) * b_i] = r[r3];
              }
            }

            if ((numLiveTracks < 1.0) || (loop_ub > allToCalculate.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numLiveTracks),
                1, allToCalculate.size(0), &ye_emlrtBCI, sp);
            }

            if (1 > detIndices.size(1)) {
              rtemp = 0;
            } else {
              if (1 > allToCalculate.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, allToCalculate.size(1),
                  &xe_emlrtBCI, sp);
              }

              if ((detIndices.size(1) < 1) || (detIndices.size(1) >
                   allToCalculate.size(1))) {
                emlrtDynamicBoundsCheckR2012b(detIndices.size(1), 1,
                  allToCalculate.size(1), &we_emlrtBCI, sp);
              }

              rtemp = detIndices.size(1);
            }

            toCalculate.set_size(&bl_emlrtRTEI, sp, loop_ub, rtemp);
            for (i = 0; i < rtemp; i++) {
              for (r3 = 0; r3 < loop_ub; r3++) {
                toCalculate[r3 + toCalculate.size(0) * i] = allToCalculate[r3 +
                  allToCalculate.size(0) * i];
              }
            }

            emlrtHeapReferenceStackLeaveFcnR2012b(sp);
          }

          void AssignmentCostCalculator::setup(const emlrtStack *sp, ObjectTrack
            * const varargin_1[30], const ::coder::array<objectDetection, 2U>
            &varargin_2, real_T varargin_3, const ::coder::array<real_T, 2U>
            &varargin_4)
          {
            static const int8_T b_iv[8] = { 1, 30, 1, 1, 1, 1, 1, 1 };

            cell_wrap_3 varSizes[4];
            emlrtStack st;
            real_T unusedExpr[6];
            int32_T i;
            st.prev = sp;
            st.tls = sp->tls;
            if (this->isInitialized != 0) {
              emlrtErrorWithMessageIdR2018a(sp, &wb_emlrtRTEI,
                "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
                "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
                "setup");
            }

            this->isInitialized = 1;
            for (i = 0; i < 8; i++) {
              varSizes[0].f1[i] = static_cast<uint32_T>(b_iv[i]);
            }

            varSizes[1].f1[0] = static_cast<uint32_T>(varargin_2.size(0));
            varSizes[1].f1[1] = static_cast<uint32_T>(varargin_2.size(1));
            for (i = 0; i < 6; i++) {
              varSizes[1].f1[i + 2] = 1U;
            }

            for (i = 0; i < 8; i++) {
              varSizes[2].f1[i] = 1U;
            }

            varSizes[3].f1[0] = static_cast<uint32_T>(varargin_4.size(0));
            varSizes[3].f1[1] = static_cast<uint32_T>(varargin_4.size(1));
            for (i = 0; i < 6; i++) {
              varSizes[3].f1[i + 2] = 1U;
            }

            this->inputVarSize[0] = varSizes[0];
            this->inputVarSize[1] = varSizes[1];
            this->inputVarSize[2] = varSizes[2];
            this->inputVarSize[3] = varSizes[3];
            st.site = &xr_emlrtRSI;
            AssignmentCostCalculator::validateInputsImpl(&st, varargin_3,
              varargin_4);
            st.site = &xr_emlrtRSI;
            i = varargin_2.size(0) * varargin_2.size(1) - 1;
            if (0 > i) {
              emlrtDynamicBoundsCheckR2012b(0, 0, i, &te_emlrtBCI, &st);
            }

            i = varargin_2.size(0) * varargin_2.size(1) - 1;
            if (0 > i) {
              emlrtDynamicBoundsCheckR2012b(0, 0, i, &ue_emlrtBCI, &st);
            }

            varargin_1[0]->get_State(unusedExpr);
          }

          void AssignmentCostCalculator::setupAndReset(const emlrtStack *sp,
            ObjectTrack * const varargin_1[30], const ::coder::array<
            objectDetection, 2U> &varargin_2, real_T varargin_3, const ::coder::
            array<real_T, 2U> &varargin_4)
          {
            emlrtStack st;
            st.prev = sp;
            st.tls = sp->tls;
            st.site = &wr_emlrtRSI;
            this->setup(&st, varargin_1, varargin_2, varargin_3, varargin_4);
          }

          void AssignmentCostCalculator::validateInputsImpl(const emlrtStack *sp,
            real_T numLiveTracks, const ::coder::array<real_T, 2U> &detIndices)
          {
            emlrtStack b_st;
            emlrtStack st;
            int32_T k;
            boolean_T exitg1;
            boolean_T p;
            st.prev = sp;
            st.tls = sp->tls;
            st.site = &hbb_emlrtRSI;
            b_st.prev = &st;
            b_st.tls = st.tls;
            b_st.site = &yb_emlrtRSI;
            p = !(numLiveTracks < 0.0);
            if (!p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI,
                "Coder:toolbox:ValidateattributesexpectedNonnegative",
                "MATLAB:AssignmentCostCalculator:expectedNonnegative", 3, 4, 13,
                "numLiveTracks");
            }

            b_st.site = &yb_emlrtRSI;
            p = true;
            if (muDoubleScalarIsInf(numLiveTracks) || muDoubleScalarIsNaN
                (numLiveTracks) || (!(muDoubleScalarFloor(numLiveTracks) ==
                  numLiveTracks))) {
              p = false;
            }

            if (!p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &s_emlrtRTEI,
                "Coder:toolbox:ValidateattributesexpectedInteger",
                "MATLAB:AssignmentCostCalculator:expectedInteger", 3, 4, 13,
                "numLiveTracks");
            }

            st.site = &ibb_emlrtRSI;
            b_st.site = &yb_emlrtRSI;
            p = true;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k <= detIndices.size(1) - 1)) {
              if (!(detIndices[k] <= 0.0)) {
                k++;
              } else {
                p = false;
                exitg1 = true;
              }
            }

            if (!p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &y_emlrtRTEI,
                "Coder:toolbox:ValidateattributesexpectedPositive",
                "MATLAB:AssignmentCostCalculator:expectedPositive", 3, 4, 10,
                "detIndices");
            }

            b_st.site = &yb_emlrtRSI;
            p = true;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k <= detIndices.size(1) - 1)) {
              if ((!muDoubleScalarIsInf(detIndices[k])) && (!muDoubleScalarIsNaN
                   (detIndices[k])) && (muDoubleScalarFloor(detIndices[k]) ==
                   detIndices[k])) {
                k++;
              } else {
                p = false;
                exitg1 = true;
              }
            }

            if (!p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &s_emlrtRTEI,
                "Coder:toolbox:ValidateattributesexpectedInteger",
                "MATLAB:AssignmentCostCalculator:expectedInteger", 3, 4, 10,
                "detIndices");
            }
          }

          AssignmentCostCalculator *AssignmentCostCalculator::init()
          {
            AssignmentCostCalculator *obj;
            obj = this;
            obj->isInitialized = 0;
            return obj;
          }

          void AssignmentCostCalculator::step(const emlrtStack *sp, ObjectTrack *
            varargin_1[30], const ::coder::array<objectDetection, 2U>
            &varargin_2, real_T varargin_3, const ::coder::array<real_T, 2U>
            &varargin_4, ::coder::array<real_T, 2U> &varargout_1)
          {
            static const int8_T b_inSize[8] = { 1, 30, 1, 1, 1, 1, 1, 1 };

            static const int8_T b_iv[8] = { 1, 30, 1, 1, 1, 1, 1, 1 };

            ObjectTrack *b_varargin_1[30];
            array<real_T, 2U> b_varargin_4;
            array<real_T, 2U> costMatrix;
            array<real_T, 2U> r2;
            array<int32_T, 2U> r1;
            array<int32_T, 2U> r3;
            array<int32_T, 2U> r4;
            array<boolean_T, 2U> r;
            array<boolean_T, 2U> toCalculate;
            emlrtStack b_st;
            emlrtStack st;
            real_T d;
            int32_T b_varargin_3[2];
            int32_T b_end;
            int32_T b_loop_ub;
            int32_T c_end;
            int32_T d_end;
            int32_T e_end;
            int32_T end;
            int32_T i;
            int32_T i2;
            int32_T i3;
            int32_T k;
            int32_T loop_ub;
            uint32_T inSize[8];
            boolean_T anyInputSizeChanged;
            boolean_T exitg1;
            st.prev = sp;
            st.tls = sp->tls;
            b_st.prev = &st;
            b_st.tls = st.tls;
            emlrtHeapReferenceStackEnterFcnR2012b(sp);
            if (this->isInitialized == 2) {
              emlrtErrorWithMessageIdR2018a(sp, &ub_emlrtRTEI,
                "MATLAB:system:methodCalledWhenReleasedCodegen",
                "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
            }

            if (this->isInitialized != 1) {
              st.site = &vr_emlrtRSI;
              this->setupAndReset(&st, varargin_1, varargin_2, varargin_3,
                                  varargin_4);
            }

            st.site = &vr_emlrtRSI;
            anyInputSizeChanged = false;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 8)) {
              if (this->inputVarSize[0].f1[k] != static_cast<uint32_T>(b_iv[k]))
              {
                anyInputSizeChanged = true;
                for (i = 0; i < 8; i++) {
                  this->inputVarSize[0].f1[i] = static_cast<uint32_T>(b_inSize[i]);
                }

                exitg1 = true;
              } else {
                k++;
              }
            }

            inSize[0] = static_cast<uint32_T>(varargin_2.size(0));
            inSize[1] = static_cast<uint32_T>(varargin_2.size(1));
            for (i = 0; i < 6; i++) {
              inSize[i + 2] = 1U;
            }

            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 8)) {
              if (this->inputVarSize[1].f1[k] != inSize[k]) {
                anyInputSizeChanged = true;
                for (i = 0; i < 8; i++) {
                  this->inputVarSize[1].f1[i] = inSize[i];
                }

                exitg1 = true;
              } else {
                k++;
              }
            }

            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 8)) {
              if (this->inputVarSize[2].f1[k] != 1U) {
                anyInputSizeChanged = true;
                for (i = 0; i < 8; i++) {
                  this->inputVarSize[2].f1[i] = 1U;
                }

                exitg1 = true;
              } else {
                k++;
              }
            }

            inSize[0] = static_cast<uint32_T>(varargin_4.size(0));
            inSize[1] = static_cast<uint32_T>(varargin_4.size(1));
            for (i = 0; i < 6; i++) {
              inSize[i + 2] = 1U;
            }

            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 8)) {
              if (this->inputVarSize[3].f1[k] != inSize[k]) {
                anyInputSizeChanged = true;
                for (i = 0; i < 8; i++) {
                  this->inputVarSize[3].f1[i] = inSize[i];
                }

                exitg1 = true;
              } else {
                k++;
              }
            }

            if (anyInputSizeChanged) {
              st.site = &vr_emlrtRSI;
              AssignmentCostCalculator::validateInputsImpl(&st, varargin_3,
                varargin_4);
            }

            st.site = &vr_emlrtRSI;
            if (!(varargin_3 >= 0.0)) {
              emlrtNonNegativeCheckR2012b(varargin_3, &v_emlrtDCI, &st);
            }

            d = static_cast<int32_T>(muDoubleScalarFloor(varargin_3));
            if (varargin_3 != d) {
              emlrtIntegerCheckR2012b(varargin_3, &u_emlrtDCI, &st);
            }

            costMatrix.set_size(&jk_emlrtRTEI, &st, static_cast<int32_T>
                                (varargin_3), varargin_4.size(1));
            if (varargin_3 != d) {
              emlrtIntegerCheckR2012b(varargin_3, &w_emlrtDCI, &st);
            }

            k = static_cast<int32_T>(varargin_3) * varargin_4.size(1);
            for (i = 0; i < k; i++) {
              costMatrix[i] = rtInf;
            }

            if ((varargin_3 == 0.0) || (varargin_4.size(1) == 0)) {
              if (1.0 > varargin_3) {
                k = 0;
              } else {
                if (1 > static_cast<int32_T>(varargin_3)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, static_cast<int32_T>
                    (varargin_3), &qe_emlrtBCI, &st);
                }

                if (static_cast<int32_T>(varargin_3) < 1) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(varargin_3),
                    1, static_cast<int32_T>(varargin_3), &pe_emlrtBCI, &st);
                }

                k = static_cast<int32_T>(varargin_3);
              }

              if (1 > varargin_4.size(1)) {
                loop_ub = 0;
              } else {
                if (varargin_4.size(1) < 1) {
                  emlrtDynamicBoundsCheckR2012b(varargin_4.size(1), 1,
                    varargin_4.size(1), &oe_emlrtBCI, &st);
                }

                loop_ub = varargin_4.size(1);
              }

              varargout_1.set_size(&mk_emlrtRTEI, &st, k, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                for (i2 = 0; i2 < k; i2++) {
                  varargout_1[i2 + varargout_1.size(0) * i] = rtInf;
                }
              }
            } else {
              for (int32_T i1 = 0; i1 < 30; i1++) {
                b_varargin_1[i1] = varargin_1[i1];
              }

              b_st.site = &lbb_emlrtRSI;
              AssignmentCostCalculator::findPairsToCost(&b_st, b_varargin_1,
                varargin_2, varargin_3, varargin_4, toCalculate);
              i = static_cast<int32_T>(varargin_3);
              emlrtForLoopVectorCheckR2012b(1.0, 1.0, varargin_3, mxDOUBLE_CLASS,
                static_cast<int32_T>(varargin_3), &hc_emlrtRTEI, &st);
              if (0 <= static_cast<int32_T>(varargin_3) - 1) {
                i2 = toCalculate.size(1);
                loop_ub = toCalculate.size(1);
                end = toCalculate.size(1) - 1;
                i3 = toCalculate.size(1);
                b_loop_ub = toCalculate.size(1);
                b_end = toCalculate.size(1) - 1;
                c_end = toCalculate.size(1) - 1;
                d_end = toCalculate.size(1) - 1;
                b_varargin_3[0] = 1;
                e_end = toCalculate.size(1) - 1;
              }

              for (int32_T j = 0; j < i; j++) {
                int32_T b_i;
                if (j > 29) {
                  emlrtDynamicBoundsCheckR2012b(j, 0, 29, &ge_emlrtBCI, &st);
                }

                if (j + 1 > toCalculate.size(0)) {
                  emlrtDynamicBoundsCheckR2012b(j + 1, 1, toCalculate.size(0),
                    &ne_emlrtBCI, &st);
                }

                r.set_size(&kk_emlrtRTEI, &st, 1, i2);
                for (b_i = 0; b_i < loop_ub; b_i++) {
                  r[b_i] = toCalculate[j + toCalculate.size(0) * b_i];
                }

                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && ((b_i + 1 < 1) || (b_i + 1 > varargin_4.size(1))))
                  {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, varargin_4.size(1),
                      &re_emlrtBCI, &st);
                  }
                }

                b_i = j + 1;
                if (b_i > costMatrix.size(0)) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 1, costMatrix.size(0),
                    &me_emlrtBCI, &st);
                }

                if (j + 1 > toCalculate.size(0)) {
                  emlrtDynamicBoundsCheckR2012b(j + 1, 1, toCalculate.size(0),
                    &le_emlrtBCI, &st);
                }

                r.set_size(&lk_emlrtRTEI, &st, 1, i3);
                for (b_i = 0; b_i < b_loop_ub; b_i++) {
                  r[b_i] = toCalculate[j + toCalculate.size(0) * b_i];
                }

                for (b_i = 0; b_i <= b_end; b_i++) {
                  if (r[b_i] && ((b_i + 1 < 1) || (b_i + 1 > costMatrix.size(1))))
                  {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, costMatrix.size(1),
                      &se_emlrtBCI, &st);
                  }
                }

                k = 0;
                for (b_i = 0; b_i <= c_end; b_i++) {
                  if (toCalculate[j + toCalculate.size(0) * b_i]) {
                    k++;
                  }
                }

                r1.set_size(&mk_emlrtRTEI, &st, 1, k);
                k = 0;
                for (b_i = 0; b_i <= c_end; b_i++) {
                  if (toCalculate[j + toCalculate.size(0) * b_i]) {
                    r1[k] = b_i + 1;
                    k++;
                  }
                }

                b_varargin_4.set_size(&nk_emlrtRTEI, &st, 1, r1.size(1));
                k = r1.size(0) * r1.size(1);
                for (b_i = 0; b_i < k; b_i++) {
                  b_varargin_4[b_i] = varargin_4[r1[b_i] - 1];
                }

                b_st.site = &kbb_emlrtRSI;
                varargin_1[j]->distance(&b_st, varargin_2, b_varargin_4, r2);
                k = 0;
                for (b_i = 0; b_i <= d_end; b_i++) {
                  if (toCalculate[j + toCalculate.size(0) * b_i]) {
                    k++;
                  }
                }

                r3.set_size(&mk_emlrtRTEI, &st, 1, k);
                k = 0;
                for (b_i = 0; b_i <= d_end; b_i++) {
                  if (toCalculate[j + toCalculate.size(0) * b_i]) {
                    r3[k] = b_i + 1;
                    k++;
                  }
                }

                b_varargin_3[1] = r3.size(1);
                emlrtSubAssignSizeCheckR2012b(&b_varargin_3[0], 2, r2.size(), 2,
                  &n_emlrtECI, &st);
                k = 0;
                for (b_i = 0; b_i <= e_end; b_i++) {
                  if (toCalculate[j + toCalculate.size(0) * b_i]) {
                    k++;
                  }
                }

                r4.set_size(&mk_emlrtRTEI, &st, 1, k);
                k = 0;
                for (b_i = 0; b_i <= e_end; b_i++) {
                  if (toCalculate[j + toCalculate.size(0) * b_i]) {
                    r4[k] = b_i + 1;
                    k++;
                  }
                }

                k = r2.size(1);
                for (b_i = 0; b_i < k; b_i++) {
                  costMatrix[j + costMatrix.size(0) * (r4[b_i] - 1)] = r2[b_i];
                }
              }

              if (1 > costMatrix.size(0)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, costMatrix.size(0),
                  &ke_emlrtBCI, &st);
              }

              if ((static_cast<int32_T>(varargin_3) < 1) || (static_cast<int32_T>
                   (varargin_3) > costMatrix.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(varargin_3),
                  1, costMatrix.size(0), &je_emlrtBCI, &st);
              }

              if (1 > costMatrix.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, costMatrix.size(1),
                  &ie_emlrtBCI, &st);
              }

              if ((varargin_4.size(1) < 1) || (varargin_4.size(1) >
                   costMatrix.size(1))) {
                emlrtDynamicBoundsCheckR2012b(varargin_4.size(1), 1,
                  costMatrix.size(1), &he_emlrtBCI, &st);
              }

              k = static_cast<int32_T>(varargin_3);
              loop_ub = varargin_4.size(1);
              varargout_1.set_size(&mk_emlrtRTEI, &st, static_cast<int32_T>
                                   (varargin_3), varargin_4.size(1));
              for (i = 0; i < loop_ub; i++) {
                for (i2 = 0; i2 < k; i2++) {
                  varargout_1[i2 + varargout_1.size(0) * i] = costMatrix[i2 +
                    costMatrix.size(0) * i];
                }
              }
            }

            emlrtHeapReferenceStackLeaveFcnR2012b(sp);
          }
        }
      }
    }
  }
}

// End of code generation (AssignmentCostCalculator.cpp)
