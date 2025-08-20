//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EvaluationPath.cpp
//
//  Code generation for function 'EvaluationPath'
//


// Include files
#include "EvaluationPath.h"
#include "EvaluationPath_data.h"
#include "EvaluationPath_types.h"
#include "FPM_4.h"
#include "any1.h"
#include "assertValidSizeArg.h"
#include "cos.h"
#include "norm.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "sum.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo emlrtRSI = { 13,    // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo b_emlrtRSI = { 14,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo c_emlrtRSI = { 16,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo d_emlrtRSI = { 17,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo e_emlrtRSI = { 19,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo f_emlrtRSI = { 20,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo g_emlrtRSI = { 22,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo h_emlrtRSI = { 23,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo i_emlrtRSI = { 36,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo j_emlrtRSI = { 49,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo k_emlrtRSI = { 50,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo l_emlrtRSI = { 62,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo m_emlrtRSI = { 78,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo n_emlrtRSI = { 79,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo o_emlrtRSI = { 80,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo p_emlrtRSI = { 81,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo q_emlrtRSI = { 82,  // lineNo
  "EvaluationPath",                    // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pathName
};

static emlrtRSInfo r_emlrtRSI = { 29,  // lineNo
  "reshapeSizeChecks",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pathName 
};

static emlrtRSInfo s_emlrtRSI = { 109, // lineNo
  "computeDimsData",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pathName 
};

static emlrtRSInfo qb_emlrtRSI = { 14, // lineNo
  "max",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/max.m"// pathName
};

static emlrtRSInfo rb_emlrtRSI = { 44, // lineNo
  "minOrMax",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

static emlrtRSInfo sb_emlrtRSI = { 79, // lineNo
  "maximum",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

static emlrtRSInfo tb_emlrtRSI = { 152,// lineNo
  "unaryMinOrMax",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo ub_emlrtRSI = { 1042,// lineNo
  "maxRealVectorOmitNaN",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo vb_emlrtRSI = { 45, // lineNo
  "mpower",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/mpower.m"// pathName
};

static emlrtRSInfo hc_emlrtRSI = { 18, // lineNo
  "reshapeSizeChecks",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pathName 
};

static emlrtRTEInfo emlrtRTEI = { 52,  // lineNo
  13,                                  // colNo
  "reshapeSizeChecks",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pName 
};

static emlrtRTEInfo b_emlrtRTEI = { 57,// lineNo
  23,                                  // colNo
  "reshapeSizeChecks",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pName 
};

static emlrtRTEInfo c_emlrtRTEI = { 59,// lineNo
  23,                                  // colNo
  "reshapeSizeChecks",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"// pName 
};

static emlrtBCInfo emlrtBCI = { 0,     // iFirst
  21,                                  // iLast
  57,                                  // lineNo
  43,                                  // colNo
  "preobs",                            // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtECInfo emlrtECI = { 2,     // nDims
  83,                                  // lineNo
  7,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo b_emlrtECI = { -1,  // nDims
  70,                                  // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  70,                                  // lineNo
  20,                                  // colNo
  "wallcost",                          // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtECInfo c_emlrtECI = { -1,  // nDims
  74,                                  // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtBCInfo c_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  74,                                  // lineNo
  19,                                  // colNo
  "obscost",                           // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtECInfo d_emlrtECI = { 3,   // nDims
  80,                                  // lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo e_emlrtECI = { 3,   // nDims
  79,                                  // lineNo
  22,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo f_emlrtECI = { -1,  // nDims
  72,                                  // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtBCInfo d_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  17,                                  // colNo
  "grade",                             // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtECInfo g_emlrtECI = { -1,  // nDims
  70,                                  // lineNo
  25,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  65,                                  // lineNo
  31,                                  // colNo
  "pu",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  57,                                  // lineNo
  50,                                  // colNo
  "preobs{i+2,1}",                     // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo emlrtDCI = { 57,    // lineNo
  43,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtRTEInfo d_emlrtRTEI = { 56,// lineNo
  19,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtBCInfo g_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  470,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI = { 1,   // iFirst
  21,                                  // iLast
  50,                                  // lineNo
  466,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo i_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  451,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  447,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo k_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  423,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo l_emlrtBCI = { 1,   // iFirst
  21,                                  // iLast
  50,                                  // lineNo
  419,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo m_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  404,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo n_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  400,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo o_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  355,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo p_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  351,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo q_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  309,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo r_emlrtBCI = { 1,   // iFirst
  21,                                  // iLast
  50,                                  // lineNo
  305,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo s_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  266,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo t_emlrtBCI = { 1,   // iFirst
  21,                                  // iLast
  50,                                  // lineNo
  262,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo u_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  243,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo v_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  239,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo w_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  172,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo x_emlrtBCI = { 1,   // iFirst
  21,                                  // iLast
  50,                                  // lineNo
  168,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo y_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  152,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ab_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  148,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  103,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cb_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  50,                                  // lineNo
  99,                                  // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo db_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  83,                                  // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo eb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  79,                                  // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  470,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gb_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  49,                                  // lineNo
  466,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  451,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ib_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  447,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  423,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kb_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  49,                                  // lineNo
  419,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  404,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  400,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  355,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ob_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  351,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  309,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qb_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  49,                                  // lineNo
  305,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  266,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sb_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  49,                                  // lineNo
  262,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  243,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ub_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  239,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  172,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wb_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  49,                                  // lineNo
  168,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  152,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  148,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ac_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  103,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bc_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  49,                                  // lineNo
  99,                                  // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  83,                                  // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  79,                                  // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ec_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  211,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fc_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  44,                                  // lineNo
  207,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  190,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  186,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ic_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  162,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jc_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  44,                                  // lineNo
  158,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  141,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  137,                                 // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  113,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nc_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  44,                                  // lineNo
  109,                                 // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  92,                                  // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  88,                                  // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  64,                                  // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rc_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  44,                                  // lineNo
  60,                                  // colNo
  "obj.limit",                         // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  43,                                  // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  39,                                  // colNo
  "vehicle_corner",                    // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtECInfo h_emlrtECI = { -1,  // nDims
  23,                                  // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo i_emlrtECI = { -1,  // nDims
  22,                                  // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo j_emlrtECI = { -1,  // nDims
  20,                                  // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo k_emlrtECI = { -1,  // nDims
  19,                                  // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo l_emlrtECI = { -1,  // nDims
  17,                                  // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo m_emlrtECI = { -1,  // nDims
  16,                                  // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo n_emlrtECI = { -1,  // nDims
  14,                                  // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo o_emlrtECI = { -1,  // nDims
  13,                                  // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtBCInfo uc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  126,                                 // colNo
  "obj.target",                        // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vc_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  36,                                  // lineNo
  122,                                 // colNo
  "obj.target",                        // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo e_emlrtRTEI = { 33,// lineNo
  17,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo f_emlrtRTEI = { 27,// lineNo
  16,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtDCInfo b_emlrtDCI = { 27,  // lineNo
  18,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtECInfo p_emlrtECI = { 2,   // nDims
  23,                                  // lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo q_emlrtECI = { 2,   // nDims
  22,                                  // lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo r_emlrtECI = { 2,   // nDims
  20,                                  // lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo s_emlrtECI = { 2,   // nDims
  19,                                  // lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo t_emlrtECI = { 2,   // nDims
  17,                                  // lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo u_emlrtECI = { 2,   // nDims
  16,                                  // lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo v_emlrtECI = { 2,   // nDims
  14,                                  // lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtECInfo w_emlrtECI = { 2,   // nDims
  13,                                  // lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtDCInfo c_emlrtDCI = { 4,   // lineNo
  16,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo d_emlrtDCI = { 4,   // lineNo
  16,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo e_emlrtDCI = { 4,   // lineNo
  24,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo f_emlrtDCI = { 4,   // lineNo
  24,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo g_emlrtDCI = { 5,   // lineNo
  29,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo h_emlrtDCI = { 5,   // lineNo
  29,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo i_emlrtDCI = { 6,   // lineNo
  21,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo j_emlrtDCI = { 6,   // lineNo
  21,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo k_emlrtDCI = { 6,   // lineNo
  29,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo l_emlrtDCI = { 6,   // lineNo
  29,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo m_emlrtDCI = { 7,   // lineNo
  22,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo n_emlrtDCI = { 7,   // lineNo
  22,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo o_emlrtDCI = { 7,   // lineNo
  30,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo p_emlrtDCI = { 7,   // lineNo
  30,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo q_emlrtDCI = { 8,   // lineNo
  21,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo r_emlrtDCI = { 8,   // lineNo
  21,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo s_emlrtDCI = { 11,  // lineNo
  33,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo t_emlrtDCI = { 11,  // lineNo
  33,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo u_emlrtDCI = { 11,  // lineNo
  39,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo v_emlrtDCI = { 11,  // lineNo
  39,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo w_emlrtDCI = { 4,   // lineNo
  2,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo x_emlrtDCI = { 4,   // lineNo
  2,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo y_emlrtDCI = { 5,   // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ab_emlrtDCI = { 5,  // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo bb_emlrtDCI = { 6,  // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo cb_emlrtDCI = { 6,  // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo db_emlrtDCI = { 7,  // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo eb_emlrtDCI = { 7,  // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo fb_emlrtDCI = { 8,  // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo gb_emlrtDCI = { 8,  // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo hb_emlrtDCI = { 11, // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ib_emlrtDCI = { 11, // lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo jb_emlrtDCI = { 28, // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo kb_emlrtDCI = { 28, // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo lb_emlrtDCI = { 30, // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo mb_emlrtDCI = { 30, // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo nb_emlrtDCI = { 31, // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ob_emlrtDCI = { 31, // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo pb_emlrtDCI = { 32, // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo qb_emlrtDCI = { 32, // lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo wc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  65,                                  // lineNo
  9,                                   // colNo
  "vcost",                             // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xc_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  36,                                  // lineNo
  45,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  45,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ad_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  36,                                  // lineNo
  57,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  57,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cd_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  36,                                  // lineNo
  69,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  69,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ed_emlrtBCI = { 0,  // iFirst
  21,                                  // iLast
  36,                                  // lineNo
  81,                                  // colNo
  "preobs",                            // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo rb_emlrtDCI = { 36, // lineNo
  81,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo fd_emlrtBCI = { 0,  // iFirst
  21,                                  // iLast
  36,                                  // lineNo
  95,                                  // colNo
  "preobs",                            // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo sb_emlrtDCI = { 36, // lineNo
  95,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo gd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  16,                                  // colNo
  "grade_temp",                        // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  68,                                  // lineNo
  9,                                   // colNo
  "wallcost_x_temp",                   // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo id_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  69,                                  // lineNo
  9,                                   // colNo
  "wallcost_y_temp",                   // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  9,                                   // colNo
  "remove_sample",                     // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  13,                                  // colNo
  "wallcost_x_temp",                   // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ld_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  13,                                  // colNo
  "wallcost_y_temp",                   // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo md_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  62,                                  // lineNo
  33,                                  // colNo
  "pu",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  62,                                  // lineNo
  33,                                  // colNo
  "pu",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo od_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  57,                                  // lineNo
  56,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  57,                                  // lineNo
  56,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qd_emlrtBCI = { 1,  // iFirst
  21,                                  // iLast
  57,                                  // lineNo
  68,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  57,                                  // lineNo
  68,                                  // colNo
  "px",                                // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  62,                                  // lineNo
  13,                                  // colNo
  "obscost_temp",                      // aName
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo t_emlrtRTEI = { 4, // lineNo
  2,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo u_emlrtRTEI = { 5, // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo v_emlrtRTEI = { 6, // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo w_emlrtRTEI = { 7, // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo x_emlrtRTEI = { 8, // lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo y_emlrtRTEI = { 11,// lineNo
  6,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo ab_emlrtRTEI = { 13,// lineNo
  40,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo bb_emlrtRTEI = { 13,// lineNo
  119,                                 // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo cb_emlrtRTEI = { 13,// lineNo
  87,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo db_emlrtRTEI = { 13,// lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo eb_emlrtRTEI = { 14,// lineNo
  40,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo fb_emlrtRTEI = { 14,// lineNo
  119,                                 // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo gb_emlrtRTEI = { 14,// lineNo
  87,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo hb_emlrtRTEI = { 14,// lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo ib_emlrtRTEI = { 16,// lineNo
  40,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo jb_emlrtRTEI = { 16,// lineNo
  119,                                 // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo kb_emlrtRTEI = { 16,// lineNo
  87,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo lb_emlrtRTEI = { 16,// lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo mb_emlrtRTEI = { 17,// lineNo
  40,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo nb_emlrtRTEI = { 17,// lineNo
  119,                                 // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo ob_emlrtRTEI = { 17,// lineNo
  87,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo pb_emlrtRTEI = { 17,// lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo qb_emlrtRTEI = { 19,// lineNo
  40,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo rb_emlrtRTEI = { 19,// lineNo
  119,                                 // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo sb_emlrtRTEI = { 19,// lineNo
  87,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo tb_emlrtRTEI = { 19,// lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo ub_emlrtRTEI = { 20,// lineNo
  40,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo vb_emlrtRTEI = { 20,// lineNo
  119,                                 // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo wb_emlrtRTEI = { 20,// lineNo
  87,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo xb_emlrtRTEI = { 20,// lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo yb_emlrtRTEI = { 22,// lineNo
  40,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo ac_emlrtRTEI = { 22,// lineNo
  119,                                 // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo bc_emlrtRTEI = { 22,// lineNo
  87,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo cc_emlrtRTEI = { 22,// lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo dc_emlrtRTEI = { 23,// lineNo
  40,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo ec_emlrtRTEI = { 23,// lineNo
  119,                                 // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo fc_emlrtRTEI = { 23,// lineNo
  87,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo gc_emlrtRTEI = { 23,// lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo hc_emlrtRTEI = { 28,// lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo ic_emlrtRTEI = { 30,// lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo jc_emlrtRTEI = { 31,// lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo kc_emlrtRTEI = { 32,// lineNo
  9,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo lc_emlrtRTEI = { 68,// lineNo
  25,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo mc_emlrtRTEI = { 1,// lineNo
  31,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo nc_emlrtRTEI = { 69,// lineNo
  25,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo oc_emlrtRTEI = { 78,// lineNo
  16,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo pc_emlrtRTEI = { 79,// lineNo
  26,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo qc_emlrtRTEI = { 79,// lineNo
  22,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo rc_emlrtRTEI = { 79,// lineNo
  63,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo sc_emlrtRTEI = { 79,// lineNo
  58,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo tc_emlrtRTEI = { 80,// lineNo
  32,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo uc_emlrtRTEI = { 80,// lineNo
  49,                                  // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo vc_emlrtRTEI = { 80,// lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo wc_emlrtRTEI = { 81,// lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo xc_emlrtRTEI = { 82,// lineNo
  5,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

static emlrtRTEInfo yc_emlrtRTEI = { 83,// lineNo
  2,                                   // colNo
  "EvaluationPath",                    // fName
  "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m"// pName
};

// Function Definitions
void EvaluationPath(const emlrtStack *sp, const struct0_T *obj, const coder::
                    array<real_T, 3U> &px, const coder::array<real_T, 3U> &pu,
                    const cell_wrap_0 preobs[22], coder::array<real_T, 2U> &pw,
                    coder::array<boolean_T, 2U> &remove_sample)
{
  coder::array<real_T, 4U> vehicle_corner;
  coder::array<real_T, 3U> a;
  coder::array<real_T, 3U> b_a;
  coder::array<real_T, 3U> b_pu;
  coder::array<real_T, 3U> b_px;
  coder::array<real_T, 3U> c_pu;
  coder::array<real_T, 2U> FPMcost;
  coder::array<real_T, 2U> OBScost;
  coder::array<real_T, 2U> WALLcost;
  coder::array<real_T, 2U> c_px;
  coder::array<real_T, 2U> grade;
  coder::array<real_T, 2U> obscost;
  coder::array<real_T, 2U> r;
  coder::array<real_T, 2U> vcost;
  coder::array<real_T, 2U> wallcost;
  coder::array<real_T, 1U> grade_temp;
  coder::array<real_T, 1U> obscost_temp;
  coder::array<real_T, 1U> wallcost_x_temp;
  coder::array<real_T, 1U> wallcost_y_temp;
  coder::array<int32_T, 1U> r2;
  coder::array<int32_T, 1U> r3;
  coder::array<boolean_T, 1U> r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T varargin_1[4];
  real_T d_px[2];
  real_T c_obj;
  real_T d;
  real_T d1;
  real_T d_obj;
  real_T obsdis_temp;
  int32_T b_iv[4];
  int32_T b_obj[2];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T maxdimlen;
  int32_T n;
  int32_T nx;
  emlrtProfilerSentinel profilerSentinel;
  boolean_T b_vehicle_corner[4];
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
  emlrtMEXProfilingFunctionEntryCPP(EvaluationPath_complete_name,
    static_cast<boolean_T>(isMexOutdated), &profilerSentinel);

  // EVALUATIONPATH この関数の概要をここに記述
  //    詳細説明をここに記述
  emlrtMEXProfilingStatement(1, static_cast<boolean_T>(isMexOutdated));
  if (!(obj->K - 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K - 1.0, &d_emlrtDCI, sp);
  }

  d = static_cast<int32_T>(muDoubleScalarFloor(obj->K - 1.0));
  if (obj->K - 1.0 != d) {
    emlrtIntegerCheckR2012b(obj->K - 1.0, &c_emlrtDCI, sp);
  }

  grade.set_size(&t_emlrtRTEI, sp, static_cast<int32_T>(obj->K - 1.0),
                 grade.size(1));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &f_emlrtDCI, sp);
  }

  d1 = static_cast<int32_T>(muDoubleScalarFloor(obj->NP));
  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &e_emlrtDCI, sp);
  }

  grade.set_size(&t_emlrtRTEI, sp, grade.size(0), static_cast<int32_T>(obj->NP));
  if (!(obj->K - 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K - 1.0, &x_emlrtDCI, sp);
  }

  if (obj->K - 1.0 != d) {
    emlrtIntegerCheckR2012b(obj->K - 1.0, &w_emlrtDCI, sp);
  }

  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &x_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &w_emlrtDCI, sp);
  }

  maxdimlen = static_cast<int32_T>(obj->K - 1.0) * static_cast<int32_T>(obj->NP);
  for (i = 0; i < maxdimlen; i++) {
    grade[i] = 0.0;
  }

  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  remove_sample.set_size(&u_emlrtRTEI, sp, 1, remove_sample.size(1));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &h_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &g_emlrtDCI, sp);
  }

  remove_sample.set_size(&u_emlrtRTEI, sp, remove_sample.size(0),
    static_cast<int32_T>(obj->NP));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &ab_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &y_emlrtDCI, sp);
  }

  loop_ub = static_cast<int32_T>(obj->NP);
  for (i = 0; i < loop_ub; i++) {
    remove_sample[i] = false;
  }

  emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
  if (!(obj->K - 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K - 1.0, &j_emlrtDCI, sp);
  }

  if (obj->K - 1.0 != d) {
    emlrtIntegerCheckR2012b(obj->K - 1.0, &i_emlrtDCI, sp);
  }

  obscost.set_size(&v_emlrtRTEI, sp, static_cast<int32_T>(obj->K - 1.0),
                   obscost.size(1));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &l_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &k_emlrtDCI, sp);
  }

  obscost.set_size(&v_emlrtRTEI, sp, obscost.size(0), static_cast<int32_T>
                   (obj->NP));
  if (!(obj->K - 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K - 1.0, &cb_emlrtDCI, sp);
  }

  if (obj->K - 1.0 != d) {
    emlrtIntegerCheckR2012b(obj->K - 1.0, &bb_emlrtDCI, sp);
  }

  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &cb_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &bb_emlrtDCI, sp);
  }

  for (i = 0; i < maxdimlen; i++) {
    obscost[i] = 0.0;
  }

  emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));
  if (!(obj->K - 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K - 1.0, &n_emlrtDCI, sp);
  }

  if (obj->K - 1.0 != d) {
    emlrtIntegerCheckR2012b(obj->K - 1.0, &m_emlrtDCI, sp);
  }

  wallcost.set_size(&w_emlrtRTEI, sp, static_cast<int32_T>(obj->K - 1.0),
                    wallcost.size(1));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &p_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &o_emlrtDCI, sp);
  }

  wallcost.set_size(&w_emlrtRTEI, sp, wallcost.size(0), static_cast<int32_T>
                    (obj->NP));
  if (!(obj->K - 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K - 1.0, &eb_emlrtDCI, sp);
  }

  if (obj->K - 1.0 != d) {
    emlrtIntegerCheckR2012b(obj->K - 1.0, &db_emlrtDCI, sp);
  }

  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &eb_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &db_emlrtDCI, sp);
  }

  for (i = 0; i < maxdimlen; i++) {
    wallcost[i] = 0.0;
  }

  emlrtMEXProfilingStatement(5, static_cast<boolean_T>(isMexOutdated));
  vcost.set_size(&x_emlrtRTEI, sp, 1, vcost.size(1));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &r_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &q_emlrtDCI, sp);
  }

  vcost.set_size(&x_emlrtRTEI, sp, vcost.size(0), static_cast<int32_T>(obj->NP));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &gb_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &fb_emlrtDCI, sp);
  }

  loop_ub = static_cast<int32_T>(obj->NP);
  for (i = 0; i < loop_ub; i++) {
    vcost[i] = 0.0;
  }

  // 高速化のための変数
  emlrtMEXProfilingStatement(6, static_cast<boolean_T>(isMexOutdated));
  vehicle_corner.set_size(&y_emlrtRTEI, sp, 4, 2, vehicle_corner.size(2),
    vehicle_corner.size(3));
  if (!(obj->K >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K, &t_emlrtDCI, sp);
  }

  d = static_cast<int32_T>(muDoubleScalarFloor(obj->K));
  if (obj->K != d) {
    emlrtIntegerCheckR2012b(obj->K, &s_emlrtDCI, sp);
  }

  vehicle_corner.set_size(&y_emlrtRTEI, sp, vehicle_corner.size(0),
    vehicle_corner.size(1), static_cast<int32_T>(obj->K), vehicle_corner.size(3));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &v_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &u_emlrtDCI, sp);
  }

  vehicle_corner.set_size(&y_emlrtRTEI, sp, vehicle_corner.size(0),
    vehicle_corner.size(1), vehicle_corner.size(2), static_cast<int32_T>(obj->NP));
  if (!(obj->K >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K, &ib_emlrtDCI, sp);
  }

  if (obj->K != d) {
    emlrtIntegerCheckR2012b(obj->K, &hb_emlrtDCI, sp);
  }

  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &ib_emlrtDCI, sp);
  }

  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &hb_emlrtDCI, sp);
  }

  loop_ub = (static_cast<int32_T>(obj->K) << 3) * static_cast<int32_T>(obj->NP);
  for (i = 0; i < loop_ub; i++) {
    vehicle_corner[i] = 0.0;
  }

  //  左後ろ
  emlrtMEXProfilingStatement(7, static_cast<boolean_T>(isMexOutdated));
  st.site = &emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  loop_ub = px.size(2);
  b_px.set_size(&ab_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  loop_ub = static_cast<int32_T>(obj->K) * static_cast<int32_T>(obj->NP);
  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&bb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  n = px.size(2);
  b_px.set_size(&bb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  r.set_size(&cb_emlrtRTEI, sp, static_cast<int32_T>(obj->K),
             static_cast<int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    r[i] = obj->ltheta[1] + b_px[i];
  }

  st.site = &emlrtRSI;
  coder::b_sin(&st, r);
  n = r.size(0) * r.size(1);
  for (i = 0; i < n; i++) {
    r[i] = obj->ltheta[0] * r[i];
  }

  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSizeEqCheckNDR2012b(&b_obj[0], r.size(), &w_emlrtECI, sp);
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = static_cast<int32_T>(obj->K);
  b_iv[3] = static_cast<int32_T>(obj->NP);
  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &o_emlrtECI, sp);
  n = px.size(2);
  b_px.set_size(&ab_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }

  c_px.set_size(&db_emlrtRTEI, sp, static_cast<int32_T>(obj->K), static_cast<
                int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    c_px[i] = b_px[i] + r[i];
  }

  b_iv[2] = static_cast<int32_T>(obj->K);
  n = static_cast<int32_T>(obj->NP);
  for (i = 0; i < n; i++) {
    maxdimlen = b_iv[2];
    for (i1 = 0; i1 < maxdimlen; i1++) {
      vehicle_corner[8 * i1 + 8 * vehicle_corner.size(2) * i] = c_px[i1 + b_iv[2]
        * i];
    }
  }

  emlrtMEXProfilingStatement(8, static_cast<boolean_T>(isMexOutdated));
  st.site = &b_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&eb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &b_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&fb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  n = px.size(2);
  b_px.set_size(&fb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  r.set_size(&gb_emlrtRTEI, sp, static_cast<int32_T>(obj->K),
             static_cast<int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    r[i] = obj->ltheta[9] + b_px[i];
  }

  st.site = &b_emlrtRSI;
  coder::b_cos(&st, r);
  n = r.size(0) * r.size(1);
  for (i = 0; i < n; i++) {
    r[i] = obj->ltheta[8] * r[i];
  }

  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSizeEqCheckNDR2012b(&b_obj[0], r.size(), &v_emlrtECI, sp);
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = vehicle_corner.size(2);
  b_iv[3] = vehicle_corner.size(3);
  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &n_emlrtECI, sp);
  n = px.size(2);
  b_px.set_size(&eb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }

  maxdimlen = vehicle_corner.size(2);
  c_px.set_size(&hb_emlrtRTEI, sp, static_cast<int32_T>(obj->K), static_cast<
                int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    c_px[i] = b_px[i] + r[i];
  }

  b_iv[2] = vehicle_corner.size(2);
  n = vehicle_corner.size(3);
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < maxdimlen; i1++) {
      vehicle_corner[(8 * i1 + 8 * vehicle_corner.size(2) * i) + 4] = c_px[i1 +
        b_iv[2] * i];
    }
  }

  // 　左前
  emlrtMEXProfilingStatement(9, static_cast<boolean_T>(isMexOutdated));
  st.site = &c_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&ib_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &c_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&jb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  n = px.size(2);
  b_px.set_size(&jb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  r.set_size(&kb_emlrtRTEI, sp, static_cast<int32_T>(obj->K),
             static_cast<int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    r[i] = obj->ltheta[3] + b_px[i];
  }

  st.site = &c_emlrtRSI;
  coder::b_cos(&st, r);
  n = r.size(0) * r.size(1);
  for (i = 0; i < n; i++) {
    r[i] = obj->ltheta[2] * r[i];
  }

  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSizeEqCheckNDR2012b(&b_obj[0], r.size(), &u_emlrtECI, sp);
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = vehicle_corner.size(2);
  b_iv[3] = vehicle_corner.size(3);
  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &m_emlrtECI, sp);
  n = px.size(2);
  b_px.set_size(&ib_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }

  maxdimlen = vehicle_corner.size(2);
  c_px.set_size(&lb_emlrtRTEI, sp, static_cast<int32_T>(obj->K), static_cast<
                int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    c_px[i] = b_px[i] + r[i];
  }

  b_iv[2] = vehicle_corner.size(2);
  n = vehicle_corner.size(3);
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < maxdimlen; i1++) {
      vehicle_corner[(8 * i1 + 8 * vehicle_corner.size(2) * i) + 1] = c_px[i1 +
        b_iv[2] * i];
    }
  }

  emlrtMEXProfilingStatement(10, static_cast<boolean_T>(isMexOutdated));
  st.site = &d_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&mb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &d_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&nb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  n = px.size(2);
  b_px.set_size(&nb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  r.set_size(&ob_emlrtRTEI, sp, static_cast<int32_T>(obj->K),
             static_cast<int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    r[i] = obj->ltheta[11] + b_px[i];
  }

  st.site = &d_emlrtRSI;
  coder::b_sin(&st, r);
  n = r.size(0) * r.size(1);
  for (i = 0; i < n; i++) {
    r[i] = obj->ltheta[10] * r[i];
  }

  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSizeEqCheckNDR2012b(&b_obj[0], r.size(), &t_emlrtECI, sp);
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = vehicle_corner.size(2);
  b_iv[3] = vehicle_corner.size(3);
  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &l_emlrtECI, sp);
  n = px.size(2);
  b_px.set_size(&mb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }

  maxdimlen = vehicle_corner.size(2);
  c_px.set_size(&pb_emlrtRTEI, sp, static_cast<int32_T>(obj->K), static_cast<
                int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    c_px[i] = b_px[i] + r[i];
  }

  b_iv[2] = vehicle_corner.size(2);
  n = vehicle_corner.size(3);
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < maxdimlen; i1++) {
      vehicle_corner[(8 * i1 + 8 * vehicle_corner.size(2) * i) + 5] = c_px[i1 +
        b_iv[2] * i];
    }
  }

  // 　右後ろ
  emlrtMEXProfilingStatement(11, static_cast<boolean_T>(isMexOutdated));
  st.site = &e_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&qb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &e_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&rb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  n = px.size(2);
  b_px.set_size(&rb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  r.set_size(&sb_emlrtRTEI, sp, static_cast<int32_T>(obj->K),
             static_cast<int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    r[i] = obj->ltheta[5] - b_px[i];
  }

  st.site = &e_emlrtRSI;
  coder::b_cos(&st, r);
  n = r.size(0) * r.size(1);
  for (i = 0; i < n; i++) {
    r[i] = obj->ltheta[4] * r[i];
  }

  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSizeEqCheckNDR2012b(&b_obj[0], r.size(), &s_emlrtECI, sp);
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = vehicle_corner.size(2);
  b_iv[3] = vehicle_corner.size(3);
  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &k_emlrtECI, sp);
  n = px.size(2);
  b_px.set_size(&qb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }

  maxdimlen = vehicle_corner.size(2);
  c_px.set_size(&tb_emlrtRTEI, sp, static_cast<int32_T>(obj->K), static_cast<
                int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    c_px[i] = b_px[i] + r[i];
  }

  b_iv[2] = vehicle_corner.size(2);
  n = vehicle_corner.size(3);
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < maxdimlen; i1++) {
      vehicle_corner[(8 * i1 + 8 * vehicle_corner.size(2) * i) + 2] = c_px[i1 +
        b_iv[2] * i];
    }
  }

  emlrtMEXProfilingStatement(12, static_cast<boolean_T>(isMexOutdated));
  st.site = &f_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&ub_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &f_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&vb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  n = px.size(2);
  b_px.set_size(&vb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  r.set_size(&wb_emlrtRTEI, sp, static_cast<int32_T>(obj->K),
             static_cast<int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    r[i] = obj->ltheta[13] - b_px[i];
  }

  st.site = &f_emlrtRSI;
  coder::b_sin(&st, r);
  n = r.size(0) * r.size(1);
  for (i = 0; i < n; i++) {
    r[i] = obj->ltheta[12] * r[i];
  }

  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSizeEqCheckNDR2012b(&b_obj[0], r.size(), &r_emlrtECI, sp);
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = vehicle_corner.size(2);
  b_iv[3] = vehicle_corner.size(3);
  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &j_emlrtECI, sp);
  n = px.size(2);
  b_px.set_size(&ub_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }

  maxdimlen = vehicle_corner.size(2);
  c_px.set_size(&xb_emlrtRTEI, sp, static_cast<int32_T>(obj->K), static_cast<
                int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    c_px[i] = b_px[i] + r[i];
  }

  b_iv[2] = vehicle_corner.size(2);
  n = vehicle_corner.size(3);
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < maxdimlen; i1++) {
      vehicle_corner[(8 * i1 + 8 * vehicle_corner.size(2) * i) + 6] = c_px[i1 +
        b_iv[2] * i];
    }
  }

  // 　右前
  emlrtMEXProfilingStatement(13, static_cast<boolean_T>(isMexOutdated));
  st.site = &g_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&yb_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &g_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&ac_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  n = px.size(2);
  b_px.set_size(&ac_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  r.set_size(&bc_emlrtRTEI, sp, static_cast<int32_T>(obj->K),
             static_cast<int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    r[i] = obj->ltheta[7] + b_px[i];
  }

  st.site = &g_emlrtRSI;
  coder::b_cos(&st, r);
  n = r.size(0) * r.size(1);
  for (i = 0; i < n; i++) {
    r[i] = obj->ltheta[6] * r[i];
  }

  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSizeEqCheckNDR2012b(&b_obj[0], r.size(), &q_emlrtECI, sp);
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = vehicle_corner.size(2);
  b_iv[3] = vehicle_corner.size(3);
  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &i_emlrtECI, sp);
  n = px.size(2);
  b_px.set_size(&yb_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }

  maxdimlen = vehicle_corner.size(2);
  c_px.set_size(&cc_emlrtRTEI, sp, static_cast<int32_T>(obj->K), static_cast<
                int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    c_px[i] = b_px[i] + r[i];
  }

  b_iv[2] = vehicle_corner.size(2);
  n = vehicle_corner.size(3);
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < maxdimlen; i1++) {
      vehicle_corner[(8 * i1 + 8 * vehicle_corner.size(2) * i) + 3] = c_px[i1 +
        b_iv[2] * i];
    }
  }

  emlrtMEXProfilingStatement(14, static_cast<boolean_T>(isMexOutdated));
  st.site = &h_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&dc_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &h_emlrtRSI;
  nx = 21 * px.size(2);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->K);
  c_st.site = &s_emlrtRSI;
  coder::internal::assertValidSizeArg(&c_st, obj->NP);
  n = px.size(2);
  b_px.set_size(&ec_emlrtRTEI, &st, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  n = 21;
  if (b_px.size(2) > 21) {
    n = b_px.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (static_cast<int32_T>(obj->K) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((static_cast<int32_T>(obj->K) < 0) || (static_cast<int32_T>(obj->NP) < 0))
  {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  n = px.size(2);
  b_px.set_size(&ec_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }

  r.set_size(&fc_emlrtRTEI, sp, static_cast<int32_T>(obj->K),
             static_cast<int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    r[i] = obj->ltheta[15] + b_px[i];
  }

  st.site = &h_emlrtRSI;
  coder::b_sin(&st, r);
  n = r.size(0) * r.size(1);
  for (i = 0; i < n; i++) {
    r[i] = obj->ltheta[14] * r[i];
  }

  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSizeEqCheckNDR2012b(&b_obj[0], r.size(), &p_emlrtECI, sp);
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = vehicle_corner.size(2);
  b_iv[3] = vehicle_corner.size(3);
  b_obj[0] = static_cast<int32_T>(obj->K);
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &h_emlrtECI, sp);
  n = px.size(2);
  b_px.set_size(&dc_emlrtRTEI, sp, 1, 21, px.size(2));
  for (i = 0; i < n; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      b_px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }

  maxdimlen = vehicle_corner.size(2);
  c_px.set_size(&gc_emlrtRTEI, sp, static_cast<int32_T>(obj->K), static_cast<
                int32_T>(obj->NP));
  for (i = 0; i < loop_ub; i++) {
    c_px[i] = b_px[i] + r[i];
  }

  b_iv[2] = vehicle_corner.size(2);
  loop_ub = vehicle_corner.size(3);
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < maxdimlen; i1++) {
      vehicle_corner[(8 * i1 + 8 * vehicle_corner.size(2) * i) + 7] = c_px[i1 +
        b_iv[2] * i];
    }
  }

  emlrtMEXProfilingStatement(15, static_cast<boolean_T>(isMexOutdated));
  if (obj->NP != d1) {
    emlrtIntegerCheckR2012b(obj->NP, &b_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(obj->NP);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj->NP, mxDOUBLE_CLASS,
    static_cast<int32_T>(obj->NP), &f_emlrtRTEI, sp);
  if (0 <= static_cast<int32_T>(obj->NP) - 1) {
    i2 = static_cast<int32_T>(obj->K - 1.0);
    if (0 <= static_cast<int32_T>(obj->K - 1.0) - 1) {
      c_obj = -obj->wall_penalty1;
      d_obj = -obj->wall_penalty1;
      i3 = static_cast<int32_T>(obj->ObsNum);
    }
  }

  for (int32_T j = 0; j < i; j++) {
    boolean_T remove_temp;

    //      ticBytes(gcp);
    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    if (!(obj->K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj->K - 1.0, &kb_emlrtDCI, sp);
    }

    if (obj->K - 1.0 != static_cast<int32_T>(muDoubleScalarFloor(obj->K - 1.0)))
    {
      emlrtIntegerCheckR2012b(obj->K - 1.0, &jb_emlrtDCI, sp);
    }

    grade_temp.set_size(&hc_emlrtRTEI, sp, static_cast<int32_T>(obj->K - 1.0));
    if (!(obj->K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj->K - 1.0, &kb_emlrtDCI, sp);
    }

    if (obj->K - 1.0 != static_cast<int32_T>(muDoubleScalarFloor(obj->K - 1.0)))
    {
      emlrtIntegerCheckR2012b(obj->K - 1.0, &jb_emlrtDCI, sp);
    }

    loop_ub = static_cast<int32_T>(obj->K - 1.0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      grade_temp[i1] = 0.0;
    }

    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    remove_temp = false;
    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    if (!(obj->K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj->K - 1.0, &mb_emlrtDCI, sp);
    }

    if (obj->K - 1.0 != static_cast<int32_T>(muDoubleScalarFloor(obj->K - 1.0)))
    {
      emlrtIntegerCheckR2012b(obj->K - 1.0, &lb_emlrtDCI, sp);
    }

    obscost_temp.set_size(&ic_emlrtRTEI, sp, static_cast<int32_T>(obj->K - 1.0));
    if (!(obj->K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj->K - 1.0, &mb_emlrtDCI, sp);
    }

    if (obj->K - 1.0 != static_cast<int32_T>(muDoubleScalarFloor(obj->K - 1.0)))
    {
      emlrtIntegerCheckR2012b(obj->K - 1.0, &lb_emlrtDCI, sp);
    }

    loop_ub = static_cast<int32_T>(obj->K - 1.0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      obscost_temp[i1] = 0.0;
    }

    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    if (!(obj->K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj->K - 1.0, &ob_emlrtDCI, sp);
    }

    if (obj->K - 1.0 != static_cast<int32_T>(muDoubleScalarFloor(obj->K - 1.0)))
    {
      emlrtIntegerCheckR2012b(obj->K - 1.0, &nb_emlrtDCI, sp);
    }

    wallcost_x_temp.set_size(&jc_emlrtRTEI, sp, static_cast<int32_T>(obj->K -
      1.0));
    if (!(obj->K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj->K - 1.0, &ob_emlrtDCI, sp);
    }

    if (obj->K - 1.0 != static_cast<int32_T>(muDoubleScalarFloor(obj->K - 1.0)))
    {
      emlrtIntegerCheckR2012b(obj->K - 1.0, &nb_emlrtDCI, sp);
    }

    loop_ub = static_cast<int32_T>(obj->K - 1.0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      wallcost_x_temp[i1] = 0.0;
    }

    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    if (!(obj->K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj->K - 1.0, &qb_emlrtDCI, sp);
    }

    if (obj->K - 1.0 != static_cast<int32_T>(muDoubleScalarFloor(obj->K - 1.0)))
    {
      emlrtIntegerCheckR2012b(obj->K - 1.0, &pb_emlrtDCI, sp);
    }

    wallcost_y_temp.set_size(&kc_emlrtRTEI, sp, static_cast<int32_T>(obj->K -
      1.0));
    if (!(obj->K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj->K - 1.0, &qb_emlrtDCI, sp);
    }

    if (obj->K - 1.0 != static_cast<int32_T>(muDoubleScalarFloor(obj->K - 1.0)))
    {
      emlrtIntegerCheckR2012b(obj->K - 1.0, &pb_emlrtDCI, sp);
    }

    loop_ub = static_cast<int32_T>(obj->K - 1.0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      wallcost_y_temp[i1] = 0.0;
    }

    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj->K - 1.0, mxDOUBLE_CLASS,
      static_cast<int32_T>(obj->K - 1.0), &e_emlrtRTEI, sp);
    for (nx = 0; nx < i2; nx++) {
      real_T b_obj_tmp;
      real_T c_obj_tmp;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T d6;
      real_T d7;
      real_T d_obj_tmp;
      real_T obj_tmp;
      real_T obsdis;
      boolean_T exitg1;

      //  FPM cost
      //  			[~,grade(i,j)] = FPM_2_6(obj,px(1,i+1,j),px(2,i+1,j),px(3,i+1,j),preobs{i+2,1},preobs{i+1,1}); 
      emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
      if ((static_cast<int32_T>(nx + 2U) < 1) || (static_cast<int32_T>(nx + 2U) >
           21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 2U), 1, 21,
          &vc_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           obj->target.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
          obj->target.size(2), &uc_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(nx + 2U) < 1) || (static_cast<int32_T>(nx + 2U) >
           21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 2U), 1, 21,
          &xc_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           px.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, px.size(2),
          &yc_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(nx + 2U) < 1) || (static_cast<int32_T>(nx + 2U) >
           21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 2U), 1, 21,
          &ad_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           px.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, px.size(2),
          &bd_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(nx + 2U) < 1) || (static_cast<int32_T>(nx + 2U) >
           21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 2U), 1, 21,
          &cd_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           px.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, px.size(2),
          &dd_emlrtBCI, sp);
      }

      if ((static_cast<real_T>(nx) + 1.0) + 2.0 != static_cast<int32_T>((
            static_cast<real_T>(nx) + 1.0) + 2.0)) {
        emlrtIntegerCheckR2012b((static_cast<real_T>(nx) + 1.0) + 2.0,
          &rb_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 2.0) - 1 < 0) ||
          (static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 2.0) - 1 > 21))
      {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 2.0) - 1, 0, 21, &ed_emlrtBCI, sp);
      }

      if ((static_cast<real_T>(nx) + 1.0) + 1.0 != static_cast<int32_T>((
            static_cast<real_T>(nx) + 1.0) + 1.0)) {
        emlrtIntegerCheckR2012b((static_cast<real_T>(nx) + 1.0) + 1.0,
          &sb_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) - 1 < 0) ||
          (static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) - 1 > 21))
      {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0) - 1, 0, 21, &fd_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(nx + 1U) < 1) || (static_cast<int32_T>(nx + 1U) >
           grade_temp.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
          grade_temp.size(0), &gd_emlrtBCI, sp);
      }

      st.site = &i_emlrtRSI;
      FPM_4(&st, obj->ObsNum, obj->r_wheel, obj->r_obs, px[3 * (nx + 1) + 63 * j],
            px[(3 * (nx + 1) + 63 * j) + 1], px[(3 * (nx + 1) + 63 * j) + 2],
            preobs[static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 2.0) -
            1].f1.data, preobs[static_cast<int32_T>((static_cast<real_T>(nx) +
              1.0) + 2.0) - 1].f1.size, preobs[static_cast<int32_T>((
              static_cast<real_T>(nx) + 1.0) + 1.0) - 1].f1.data, preobs[
            static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) - 1].
            f1.size, *(real_T (*)[2])&obj->target[2 * (nx + 1) + 42 * j],
            &obsdis_temp, &grade_temp[nx]);

      // wall cost
      //              if px(1,i+1,j) < obj.limit(1,i+1,j) || px(1,i+1,j) > obj.limit(2,i+1,j) || px(2,i+1,j) < obj.limit(3,i+1,j) || px(2,i+1,j) > obj.limit(4,i+1,j) %壁面の考慮 
      //  %                 grade_temp(i,1) = 0;
      //                  remove_temp = true;
      //              end
      emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &tc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &sc_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &rc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &qc_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &pc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &oc_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &nc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &mc_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &lc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &kc_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &jc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &ic_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &hc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &gc_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &fc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &ec_emlrtBCI,
          sp);
      }

      obsdis_temp = obj->limit[4 * (nx + 1) + 84 * j];
      obsdis = obj->limit[(4 * (nx + 1) + 84 * j) + 1];
      obj_tmp = obj->limit[(4 * (nx + 1) + 84 * j) + 2];
      b_obj_tmp = obj->limit[(4 * (nx + 1) + 84 * j) + 3];
      d = vehicle_corner[8 * (nx + 1) + 8 * vehicle_corner.size(2) * j];
      d1 = vehicle_corner[(8 * (nx + 1) + 8 * vehicle_corner.size(2) * j) + 4];
      b_vehicle_corner[0] = ((d < obsdis_temp) || (d > obsdis) || (d1 < obj_tmp)
        || (d1 > b_obj_tmp));
      d2 = vehicle_corner[(8 * (nx + 1) + 8 * vehicle_corner.size(2) * j) + 1];
      d3 = vehicle_corner[(8 * (nx + 1) + 8 * vehicle_corner.size(2) * j) + 5];
      b_vehicle_corner[1] = ((d2 < obsdis_temp) || (d2 > obsdis) || (d3 <
        obj_tmp) || (d3 > b_obj_tmp));
      d4 = vehicle_corner[(8 * (nx + 1) + 8 * vehicle_corner.size(2) * j) + 2];
      d5 = vehicle_corner[(8 * (nx + 1) + 8 * vehicle_corner.size(2) * j) + 6];
      b_vehicle_corner[2] = ((d4 < obsdis_temp) || (d4 > obsdis) || (d5 <
        obj_tmp) || (d5 > b_obj_tmp));
      d6 = vehicle_corner[(8 * (nx + 1) + 8 * vehicle_corner.size(2) * j) + 3];
      d7 = vehicle_corner[(8 * (nx + 1) + 8 * vehicle_corner.size(2) * j) + 7];
      b_vehicle_corner[3] = ((d6 < obsdis_temp) || (d6 > obsdis) || (d7 <
        obj_tmp) || (d7 > b_obj_tmp));
      if (coder::any(b_vehicle_corner)) {
        // 壁面の考慮
        //                  grade_temp(i,1) = 0;
        emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
        remove_temp = true;
        emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
      }

      emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &mb_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &lb_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &kb_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &jb_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &ib_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &hb_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &gb_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &fb_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &dc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &cc_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &bc_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &ac_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &yb_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &xb_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &wb_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &vb_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &ub_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &tb_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &sb_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &rb_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &qb_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &pb_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &ob_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &nb_emlrtBCI, sp);
      }

      st.site = &j_emlrtRSI;
      c_obj_tmp = obsdis - obj->wall_threshold;
      d_obj_tmp = obsdis_temp + obj->wall_threshold;
      varargin_1[0] = (obj->wall_penalty1 * ((d - c_obj_tmp) *
        static_cast<real_T>(d > c_obj_tmp)) + c_obj * ((d + -d_obj_tmp) *
        static_cast<real_T>(d_obj_tmp > d))) + obj->wall_penalty2 *
        static_cast<real_T>((d > obsdis) || (d < obsdis_temp));
      varargin_1[1] = (obj->wall_penalty1 * ((d2 - c_obj_tmp) *
        static_cast<real_T>(d2 > c_obj_tmp)) + c_obj * ((d2 + -d_obj_tmp) *
        static_cast<real_T>(d_obj_tmp > d2))) + obj->wall_penalty2 *
        static_cast<real_T>((d2 > obsdis) || (d2 < obsdis_temp));
      varargin_1[2] = (obj->wall_penalty1 * ((d4 - c_obj_tmp) * static_cast<
        real_T>(d4 > c_obj_tmp)) + c_obj * ((d4 + -d_obj_tmp) * static_cast<
        real_T>(d_obj_tmp > d4))) + obj->wall_penalty2 * static_cast<real_T>((d4
        > obsdis) || (d4 < obsdis_temp));
      varargin_1[3] = (obj->wall_penalty1 * ((d6 - c_obj_tmp) *
        static_cast<real_T>(d6 > c_obj_tmp)) + c_obj * ((d6 + -d_obj_tmp) *
        static_cast<real_T>(d_obj_tmp > d6))) + obj->wall_penalty2 *
        static_cast<real_T>((d6 > obsdis) || (d6 < obsdis_temp));
      b_st.site = &qb_emlrtRSI;
      c_st.site = &rb_emlrtRSI;
      d_st.site = &sb_emlrtRSI;
      e_st.site = &tb_emlrtRSI;
      f_st.site = &ub_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1[0])) {
        maxdimlen = 1;
      } else {
        maxdimlen = 0;
        n = 2;
        exitg1 = false;
        while ((!exitg1) && (n < 5)) {
          if (!muDoubleScalarIsNaN(varargin_1[n - 1])) {
            maxdimlen = n;
            exitg1 = true;
          } else {
            n++;
          }
        }
      }

      if (maxdimlen == 0) {
        if ((static_cast<int32_T>(nx + 1U) < 1) || (static_cast<int32_T>(nx + 1U)
             > wallcost_x_temp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
            wallcost_x_temp.size(0), &kd_emlrtBCI, &f_st);
        }

        wallcost_x_temp[nx] = varargin_1[0];
      } else {
        obsdis_temp = varargin_1[maxdimlen - 1];
        maxdimlen++;
        for (n = maxdimlen; n < 5; n++) {
          d = varargin_1[n - 1];
          if (obsdis_temp < d) {
            obsdis_temp = d;
          }
        }

        if ((static_cast<int32_T>(nx + 1U) < 1) || (static_cast<int32_T>(nx + 1U)
             > wallcost_x_temp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
            wallcost_x_temp.size(0), &kd_emlrtBCI, &f_st);
        }

        wallcost_x_temp[nx] = obsdis_temp;
      }

      emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &n_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3), &m_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &l_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &k_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &j_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3), &i_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &h_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &g_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &eb_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3),
          &db_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &cb_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &bb_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &ab_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3), &y_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &x_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &w_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &v_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3), &u_emlrtBCI,
          sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &t_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &s_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, 21, &r_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > obj->limit.size(2))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, obj->limit.size(2), &q_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) < 1) || (
           static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 1.0) >
           vehicle_corner.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
          (nx) + 1.0) + 1.0), 1, vehicle_corner.size(2), &p_emlrtBCI, sp);
      }

      i1 = j + 1;
      if ((i1 < 1) || (i1 > vehicle_corner.size(3))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle_corner.size(3), &o_emlrtBCI,
          sp);
      }

      st.site = &k_emlrtRSI;
      obsdis_temp = b_obj_tmp - obj->wall_threshold;
      obsdis = obj_tmp + obj->wall_threshold;
      varargin_1[0] = (obj->wall_penalty1 * ((d1 - obsdis_temp) *
        static_cast<real_T>(d1 > obsdis_temp)) + d_obj * ((d1 + -obsdis) *
        static_cast<real_T>(obsdis > d1))) + obj->wall_penalty2 *
        static_cast<real_T>((d1 > b_obj_tmp) || (d1 < obj_tmp));
      varargin_1[1] = (obj->wall_penalty1 * ((d3 - obsdis_temp) *
        static_cast<real_T>(d3 > obsdis_temp)) + d_obj * ((d3 + -obsdis) *
        static_cast<real_T>(obsdis > d3))) + obj->wall_penalty2 *
        static_cast<real_T>((d3 > b_obj_tmp) || (d3 < obj_tmp));
      varargin_1[2] = (obj->wall_penalty1 * ((d5 - obsdis_temp) *
        static_cast<real_T>(d5 > obsdis_temp)) + d_obj * ((d5 + -obsdis) *
        static_cast<real_T>(obsdis > d5))) + obj->wall_penalty2 *
        static_cast<real_T>((d5 > b_obj_tmp) || (d5 < obj_tmp));
      varargin_1[3] = (obj->wall_penalty1 * ((d7 - obsdis_temp) *
        static_cast<real_T>(d7 > obsdis_temp)) + d_obj * ((d7 + -obsdis) *
        static_cast<real_T>(obsdis > d7))) + obj->wall_penalty2 *
        static_cast<real_T>((d7 > b_obj_tmp) || (d7 < obj_tmp));
      b_st.site = &qb_emlrtRSI;
      c_st.site = &rb_emlrtRSI;
      d_st.site = &sb_emlrtRSI;
      e_st.site = &tb_emlrtRSI;
      f_st.site = &ub_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1[0])) {
        maxdimlen = 1;
      } else {
        maxdimlen = 0;
        n = 2;
        exitg1 = false;
        while ((!exitg1) && (n < 5)) {
          if (!muDoubleScalarIsNaN(varargin_1[n - 1])) {
            maxdimlen = n;
            exitg1 = true;
          } else {
            n++;
          }
        }
      }

      if (maxdimlen == 0) {
        if ((static_cast<int32_T>(nx + 1U) < 1) || (static_cast<int32_T>(nx + 1U)
             > wallcost_y_temp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
            wallcost_y_temp.size(0), &ld_emlrtBCI, &f_st);
        }

        wallcost_y_temp[nx] = varargin_1[0];
      } else {
        obsdis_temp = varargin_1[maxdimlen - 1];
        maxdimlen++;
        for (n = maxdimlen; n < 5; n++) {
          d = varargin_1[n - 1];
          if (obsdis_temp < d) {
            obsdis_temp = d;
          }
        }

        if ((static_cast<int32_T>(nx + 1U) < 1) || (static_cast<int32_T>(nx + 1U)
             > wallcost_y_temp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
            wallcost_y_temp.size(0), &ld_emlrtBCI, &f_st);
        }

        wallcost_y_temp[nx] = obsdis_temp;
      }

      // xmin xmax ymin ymax
      // obstacle cost
      emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
      obsdis = rtMinusInf;
      emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj->ObsNum, mxDOUBLE_CLASS,
        static_cast<int32_T>(obj->ObsNum), &d_emlrtRTEI, sp);
      for (n = 0; n < i3; n++) {
        emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
        if ((static_cast<real_T>(nx) + 1.0) + 2.0 != static_cast<int32_T>((
              static_cast<real_T>(nx) + 1.0) + 2.0)) {
          emlrtIntegerCheckR2012b((static_cast<real_T>(nx) + 1.0) + 2.0,
            &emlrtDCI, sp);
        }

        if ((static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 2.0) - 1 < 0)
            || (static_cast<int32_T>((static_cast<real_T>(nx) + 1.0) + 2.0) - 1 >
                21)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((static_cast<real_T>
            (nx) + 1.0) + 2.0) - 1, 0, 21, &emlrtBCI, sp);
        }

        i1 = preobs[nx + 2].f1.size[0];
        if ((static_cast<int32_T>(n + 1U) < 1) || (static_cast<int32_T>(n + 1U) >
             i1)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n + 1U), 1, i1,
            &f_emlrtBCI, sp);
        }

        if ((static_cast<int32_T>(nx + 2U) < 1) || (static_cast<int32_T>(nx + 2U)
             > 21)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 2U), 1, 21,
            &od_emlrtBCI, sp);
        }

        if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
             px.size(2))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, px.size
            (2), &pd_emlrtBCI, sp);
        }

        d = px[3 * (nx + 1) + 63 * j];
        if ((static_cast<int32_T>(nx + 2U) < 1) || (static_cast<int32_T>(nx + 2U)
             > 21)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 2U), 1, 21,
            &qd_emlrtBCI, sp);
        }

        if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
             px.size(2))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, px.size
            (2), &rd_emlrtBCI, sp);
        }

        d1 = px[(3 * (nx + 1) + 63 * j) + 1];
        d = preobs[nx + 2].f1.data[n] - d;
        d_px[0] = d;
        d1 = preobs[nx + 2].f1.data[n + preobs[nx + 2].f1.size[0]] - d1;
        d_px[1] = d1;
        obsdis_temp = coder::b_norm(d_px);
        emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
        if (obsdis_temp > obsdis) {
          emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
          obsdis = obsdis_temp;
          emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
        }

        emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
      st.site = &l_emlrtRSI;
      if ((static_cast<int32_T>(nx + 2U) < 1) || (static_cast<int32_T>(nx + 2U) >
           21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 2U), 1, 21,
          &md_emlrtBCI, &st);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           pu.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, pu.size(2),
          &nd_emlrtBCI, &st);
      }

      obsdis_temp = pu[2 * (nx + 1) + 42 * j];
      b_st.site = &vb_emlrtRSI;
      c_st.site = &wb_emlrtRSI;
      if ((static_cast<int32_T>(nx + 1U) < 1) || (static_cast<int32_T>(nx + 1U) >
           obscost_temp.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
          obscost_temp.size(0), &sd_emlrtBCI, sp);
      }

      obscost_temp[nx] = obsdis_temp * obsdis_temp / (muDoubleScalarAbs(obsdis)
        + 0.1);
      emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    // velocity cost
    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    i1 = j + 1;
    if ((i1 < 1) || (i1 > pu.size(2))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, pu.size(2), &e_emlrtBCI, sp);
    }

    if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
         vcost.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, vcost.size
        (1), &wc_emlrtBCI, sp);
    }

    vcost[j] = (pu[42 * j] - 0.55) * 5000.0 * static_cast<real_T>(pu[42 * j] >
      0.55) + (pu[42 * j] + 0.25) * -5000.0 * static_cast<real_T>(pu[42 * j] <
      -0.25);

    // wall cost
    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    r1.set_size(&lc_emlrtRTEI, sp, wallcost_x_temp.size(0));
    loop_ub = wallcost_x_temp.size(0);
    for (n = 0; n < loop_ub; n++) {
      r1[n] = muDoubleScalarIsNaN(wallcost_x_temp[n]);
    }

    n = r1.size(0) - 1;
    maxdimlen = 0;
    for (nx = 0; nx <= n; nx++) {
      if (r1[nx]) {
        maxdimlen++;
      }
    }

    r2.set_size(&mc_emlrtRTEI, sp, maxdimlen);
    maxdimlen = 0;
    for (nx = 0; nx <= n; nx++) {
      if (r1[nx]) {
        r2[maxdimlen] = nx + 1;
        maxdimlen++;
      }
    }

    loop_ub = r2.size(0) - 1;
    maxdimlen = wallcost_x_temp.size(0);
    for (n = 0; n <= loop_ub; n++) {
      if ((r2[n] < 1) || (r2[n] > maxdimlen)) {
        emlrtDynamicBoundsCheckR2012b(r2[n], 1, maxdimlen, &hd_emlrtBCI, sp);
      }

      wallcost_x_temp[r2[n] - 1] = 0.0;
    }

    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    r1.set_size(&nc_emlrtRTEI, sp, wallcost_y_temp.size(0));
    loop_ub = wallcost_y_temp.size(0);
    for (n = 0; n < loop_ub; n++) {
      r1[n] = muDoubleScalarIsNaN(wallcost_y_temp[n]);
    }

    n = r1.size(0) - 1;
    maxdimlen = 0;
    for (nx = 0; nx <= n; nx++) {
      if (r1[nx]) {
        maxdimlen++;
      }
    }

    r3.set_size(&mc_emlrtRTEI, sp, maxdimlen);
    maxdimlen = 0;
    for (nx = 0; nx <= n; nx++) {
      if (r1[nx]) {
        r3[maxdimlen] = nx + 1;
        maxdimlen++;
      }
    }

    loop_ub = r3.size(0) - 1;
    maxdimlen = wallcost_y_temp.size(0);
    for (n = 0; n <= loop_ub; n++) {
      if ((r3[n] < 1) || (r3[n] > maxdimlen)) {
        emlrtDynamicBoundsCheckR2012b(r3[n], 1, maxdimlen, &id_emlrtBCI, sp);
      }

      wallcost_y_temp[r3[n] - 1] = 0.0;
    }

    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    if (wallcost_x_temp.size(0) != wallcost_y_temp.size(0)) {
      emlrtSizeEqCheck1DR2012b(wallcost_x_temp.size(0), wallcost_y_temp.size(0),
        &g_emlrtECI, sp);
    }

    if (i1 > wallcost.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, wallcost.size(1), &b_emlrtBCI, sp);
    }

    emlrtSubAssignSizeCheckR2012b(wallcost.size(), 1, wallcost_x_temp.size(), 1,
      &b_emlrtECI, sp);
    loop_ub = wallcost_x_temp.size(0);
    for (n = 0; n < loop_ub; n++) {
      wallcost[n + wallcost.size(0) * j] = wallcost_x_temp[n] +
        wallcost_y_temp[n];
    }

    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    if (i1 > grade.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, grade.size(1), &d_emlrtBCI, sp);
    }

    emlrtSubAssignSizeCheckR2012b(grade.size(), 1, grade_temp.size(), 1,
      &f_emlrtECI, sp);
    loop_ub = grade_temp.size(0);
    for (n = 0; n < loop_ub; n++) {
      grade[n + grade.size(0) * j] = grade_temp[n];
    }

    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
         remove_sample.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
        remove_sample.size(1), &jd_emlrtBCI, sp);
    }

    remove_sample[j] = remove_temp;
    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    if (i1 > obscost.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, obscost.size(1), &c_emlrtBCI, sp);
    }

    emlrtSubAssignSizeCheckR2012b(obscost.size(), 1, obscost_temp.size(), 1,
      &c_emlrtECI, sp);
    loop_ub = obscost_temp.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      obscost[i1 + obscost.size(0) * j] = obscost_temp[i1];
    }

    emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  //      tocBytes(gcp);
  emlrtMEXProfilingStatement(16, static_cast<boolean_T>(isMexOutdated));
  r.set_size(&oc_emlrtRTEI, sp, grade.size(0), grade.size(1));
  loop_ub = grade.size(0) * grade.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = 1.0 - grade[i];
  }

  st.site = &m_emlrtRSI;
  coder::sum(&st, r, FPMcost);
  emlrtMEXProfilingStatement(17, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(0, static_cast<boolean_T>(isMexOutdated));
  loop_ub = pu.size(2);
  b_pu.set_size(&pc_emlrtRTEI, sp, 1, 20, pu.size(2));
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      b_pu[i1 + 20 * i] = pu[(2 * i1 + 42 * i) + 1];
    }
  }

  st.site = &n_emlrtRSI;
  coder::power(&st, b_pu, c_pu);
  st.site = &n_emlrtRSI;
  coder::sum(&st, c_pu, a);
  i = a.size(0) * a.size(1) * a.size(2);
  a.set_size(&qc_emlrtRTEI, sp, 1, 1, a.size(2));
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    a[i] = a[i] * obj->R[1];
  }

  loop_ub = pu.size(2);
  b_pu.set_size(&rc_emlrtRTEI, sp, 1, 20, pu.size(2));
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      b_pu[i1 + 20 * i] = pu[2 * i1 + 42 * i] - obj->Vref;
    }
  }

  st.site = &n_emlrtRSI;
  coder::power(&st, b_pu, c_pu);
  st.site = &n_emlrtRSI;
  coder::sum(&st, c_pu, b_a);
  i = b_a.size(0) * b_a.size(1) * b_a.size(2);
  b_a.set_size(&sc_emlrtRTEI, sp, 1, 1, b_a.size(2));
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_a[i] = b_a[i] * obj->R[0];
  }

  emlrtSizeEqCheckNDR2012b(a.size(), b_a.size(), &e_emlrtECI, sp);
  i = a.size(0) * a.size(1) * a.size(2);
  a.set_size(&qc_emlrtRTEI, sp, 1, 1, a.size(2));
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    a[i] = a[i] + b_a[i];
  }

  st.site = &n_emlrtRSI;
  d_px[0] = 1.0;
  d_px[1] = obj->NP;
  nx = a.size(2);
  b_st.site = &hc_emlrtRSI;
  coder::internal::assertValidSizeArg(&b_st, d_px);
  n = 1;
  if (a.size(2) > 1) {
    n = a.size(2);
  }

  if (static_cast<int32_T>(obj->NP) > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (static_cast<int32_T>(obj->NP) != a.size(2)) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emlrtMEXProfilingStatement(18, static_cast<boolean_T>(isMexOutdated));
  loop_ub = pu.size(2);
  b_pu.set_size(&tc_emlrtRTEI, sp, 1, 20, pu.size(2));
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      b_pu[i1 + 20 * i] = pu[2 * i1 + 42 * i];
    }
  }

  loop_ub = pu.size(2);
  c_pu.set_size(&uc_emlrtRTEI, sp, 1, 20, pu.size(2));
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      c_pu[i1 + 20 * i] = pu[(2 * i1 + 42 * i) + 1];
    }
  }

  emlrtSizeEqCheckNDR2012b(b_pu.size(), c_pu.size(), &d_emlrtECI, sp);
  loop_ub = pu.size(2);
  b_pu.set_size(&tc_emlrtRTEI, sp, 1, 20, pu.size(2));
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      b_pu[i1 + 20 * i] = pu[2 * i1 + 42 * i] * pu[(2 * i1 + 42 * i) + 1];
    }
  }

  st.site = &o_emlrtRSI;
  coder::power(&st, b_pu, c_pu);
  st.site = &o_emlrtRSI;
  coder::sum(&st, c_pu, b_a);
  st.site = &o_emlrtRSI;
  nx = b_a.size(2);
  b_st.site = &hc_emlrtRSI;
  coder::internal::assertValidSizeArg(&b_st, d_px);
  maxdimlen = static_cast<int32_T>(obj->NP);
  n = 1;
  if (b_a.size(2) > 1) {
    n = b_a.size(2);
  }

  if (static_cast<int32_T>(obj->NP) > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(obj->NP) < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (static_cast<int32_T>(obj->NP) != b_a.size(2)) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  pw.set_size(&vc_emlrtRTEI, sp, 1, static_cast<int32_T>(obj->NP));
  for (i = 0; i < maxdimlen; i++) {
    pw[i] = b_a[i] * obj->W;
  }

  emlrtMEXProfilingStatement(19, static_cast<boolean_T>(isMexOutdated));
  st.site = &p_emlrtRSI;
  coder::sum(&st, obscost, OBScost);
  i = OBScost.size(0) * OBScost.size(1);
  OBScost.set_size(&wc_emlrtRTEI, sp, 1, OBScost.size(1));
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    OBScost[i] = obj->Wo * OBScost[i];
  }

  emlrtMEXProfilingStatement(20, static_cast<boolean_T>(isMexOutdated));
  st.site = &q_emlrtRSI;
  coder::sum(&st, wallcost, WALLcost);
  i = WALLcost.size(0) * WALLcost.size(1);
  WALLcost.set_size(&xc_emlrtRTEI, sp, 1, WALLcost.size(1));
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    WALLcost[i] = 0.5 * WALLcost[i];
  }

  emlrtMEXProfilingStatement(21, static_cast<boolean_T>(isMexOutdated));
  b_obj[0] = 1;
  b_obj[1] = static_cast<int32_T>(obj->NP);
  emlrtSizeEqCheckNDR2012b(FPMcost.size(), &b_obj[0], &emlrtECI, sp);
  emlrtSizeEqCheckNDR2012b(FPMcost.size(), pw.size(), &emlrtECI, sp);
  emlrtSizeEqCheckNDR2012b(FPMcost.size(), OBScost.size(), &emlrtECI, sp);
  emlrtSizeEqCheckNDR2012b(FPMcost.size(), vcost.size(), &emlrtECI, sp);
  emlrtSizeEqCheckNDR2012b(FPMcost.size(), WALLcost.size(), &emlrtECI, sp);
  pw.set_size(&yc_emlrtRTEI, sp, 1, FPMcost.size(1));
  loop_ub = FPMcost.size(0) * FPMcost.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    pw[i] = ((((FPMcost[i] + a[i]) + pw[i]) + OBScost[i]) + vcost[i]) +
      WALLcost[i];
  }

  emlrtMEXProfilingStatement(22, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (EvaluationPath.cpp)
