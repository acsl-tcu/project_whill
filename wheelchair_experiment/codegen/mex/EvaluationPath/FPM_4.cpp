//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  FPM_4.cpp
//
//  Code generation for function 'FPM_4'
//


// Include files
#include "FPM_4.h"
#include "EvaluationPath_data.h"
#include "asin.h"
#include "eml_int_forloop_overflow_check.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "scalexpAlloc.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo x_emlrtRSI = { 53,  // lineNo
  "FPM_4",                             // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pathName
};

static emlrtRSInfo y_emlrtRSI = { 84,  // lineNo
  "FPM_4",                             // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pathName
};

static emlrtRSInfo ab_emlrtRSI = { 110,// lineNo
  "FPM_4",                             // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pathName
};

static emlrtRSInfo bb_emlrtRSI = { 12, // lineNo
  "atan2",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/atan2.m"// pathName
};

static emlrtRSInfo cb_emlrtRSI = { 46, // lineNo
  "applyBinaryScalarFunction",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pathName 
};

static emlrtRSInfo db_emlrtRSI = { 66, // lineNo
  "applyBinaryScalarFunction",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pathName 
};

static emlrtRSInfo eb_emlrtRSI = { 202,// lineNo
  "flatIter",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pathName 
};

static emlrtRSInfo fb_emlrtRSI = { 14, // lineNo
  "min",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/min.m"// pathName
};

static emlrtRSInfo gb_emlrtRSI = { 46, // lineNo
  "minOrMax",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

static emlrtRSInfo hb_emlrtRSI = { 92, // lineNo
  "minimum",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

static emlrtRSInfo ib_emlrtRSI = { 170,// lineNo
  "unaryMinOrMax",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo jb_emlrtRSI = { 1038,// lineNo
  "minRealVectorOmitNaN",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo kb_emlrtRSI = { 955,// lineNo
  "minOrMaxRealVector",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo lb_emlrtRSI = { 947,// lineNo
  "minOrMaxRealVector",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo mb_emlrtRSI = { 998,// lineNo
  "findFirst",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo nb_emlrtRSI = { 1015,// lineNo
  "minOrMaxRealVectorKernel",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo ob_emlrtRSI = { 13, // lineNo
  "any",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/any.m"// pathName
};

static emlrtRSInfo pb_emlrtRSI = { 143,// lineNo
  "allOrAny",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"// pathName 
};

static emlrtRTEInfo k_emlrtRTEI = { 19,// lineNo
  23,                                  // colNo
  "scalexpAlloc",                      // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"// pName 
};

static emlrtRTEInfo l_emlrtRTEI = { 99,// lineNo
  27,                                  // colNo
  "unaryMinOrMax",                     // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pName 
};

static emlrtBCInfo td_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  77,                                  // colNo
  "phaiR",                             // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ud_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  64,                                  // colNo
  "tho",                               // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  50,                                  // colNo
  "phaiR",                             // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  37,                                  // colNo
  "tho",                               // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  77,                                  // colNo
  "phaiR",                             // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  64,                                  // colNo
  "tho",                               // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ae_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  50,                                  // colNo
  "phaiR",                             // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo be_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  37,                                  // colNo
  "tho",                               // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo n_emlrtRTEI = { 69,// lineNo
  13,                                  // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtBCInfo ce_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  62,                                  // lineNo
  30,                                  // colNo
  "OBS",                               // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo o_emlrtRTEI = { 59,// lineNo
  13,                                  // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtBCInfo de_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  39,                                  // lineNo
  42,                                  // colNo
  "OBS_NOW",                           // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo p_emlrtRTEI = { 38,// lineNo
  13,                                  // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtDCInfo tb_emlrtDCI = { 14, // lineNo
  17,                                  // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ub_emlrtDCI = { 13, // lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo vb_emlrtDCI = { 13, // lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo wb_emlrtDCI = { 15, // lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo xb_emlrtDCI = { 16, // lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo yb_emlrtDCI = { 17, // lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ac_emlrtDCI = { 18, // lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo bc_emlrtDCI = { 19, // lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo cc_emlrtDCI = { 20, // lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ee_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  39,                                  // lineNo
  9,                                   // colNo
  "distance_obs",                      // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  62,                                  // lineNo
  9,                                   // colNo
  "PoQo",                              // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ge_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  63,                                  // lineNo
  9,                                   // colNo
  "phaiR",                             // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo he_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  64,                                  // lineNo
  32,                                  // colNo
  "PoQo",                              // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ie_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  64,                                  // lineNo
  9,                                   // colNo
  "a",                                 // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo je_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  9,                                   // colNo
  "th_max",                            // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ke_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  9,                                   // colNo
  "th_min",                            // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo le_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  76,                                  // lineNo
  19,                                  // colNo
  "th_max",                            // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo me_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  76,                                  // lineNo
  48,                                  // colNo
  "th_min",                            // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ne_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  77,                                  // lineNo
  21,                                  // colNo
  "PoQo",                              // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  78,                                  // lineNo
  40,                                  // colNo
  "a",                                 // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  78,                                  // lineNo
  17,                                  // colNo
  "grade_obs",                         // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  17,                                  // colNo
  "grade_obs",                         // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo re_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  63,                                  // lineNo
  62,                                  // colNo
  "PoQo",                              // aName
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo ad_emlrtRTEI = { 13,// lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtRTEInfo bd_emlrtRTEI = { 15,// lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtRTEInfo cd_emlrtRTEI = { 16,// lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtRTEInfo dd_emlrtRTEI = { 17,// lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtRTEInfo ed_emlrtRTEI = { 18,// lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtRTEInfo fd_emlrtRTEI = { 19,// lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtRTEInfo gd_emlrtRTEI = { 20,// lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtRTEInfo id_emlrtRTEI = { 53,// lineNo
  5,                                   // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

static emlrtRTEInfo jd_emlrtRTEI = { 110,// lineNo
  12,                                  // colNo
  "FPM_4",                             // fName
  "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m"// pName
};

// Function Definitions
void FPM_4(const emlrtStack *sp, real_T obj_ObsNum, real_T obj_r_wheel, real_T
           obj_r_obs, real_T x, real_T y, real_T th, const real_T obs_data[],
           const int32_T obs_size[2], const real_T obs_now_data[], const int32_T
           obs_now_size[2], const real_T target[2], real_T *Grade, real_T
           *Grade_old)
{
  coder::array<real_T, 1U> PoQo;
  coder::array<real_T, 1U> a;
  coder::array<real_T, 1U> distance_obs;
  coder::array<real_T, 1U> grade_obs;
  coder::array<real_T, 1U> phaiR;
  coder::array<real_T, 1U> th_max;
  coder::array<real_T, 1U> th_min;
  coder::array<real_T, 1U> tho;
  coder::array<boolean_T, 1U> c_x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  creal_T b_x;
  real_T x_data[20];
  real_T y_data[20];
  real_T z1_data[20];
  real_T obs_now[2];
  real_T thg;
  real_T x_tmp;
  int32_T x_size[1];
  int32_T y_size[1];
  int32_T z_size[1];
  int32_T idx;
  int32_T k;
  int32_T loop_ub;
  int32_T nx;
  emlrtProfilerSentinel profilerSentinel;
  int8_T csz_idx_0;
  boolean_T b_y;
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
  emlrtMEXProfilingFunctionEntryCPP(FPM_4_complete_name, static_cast<boolean_T>
    (isMexOutdated), &profilerSentinel);
  emlrtMEXProfilingStatement(1, static_cast<boolean_T>(isMexOutdated));

  // goal = obj.goal;
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));

  //     eps = 1.0;
  //      Q = [1:-0.1:0.1];
  emlrtMEXProfilingStatement(9, static_cast<boolean_T>(isMexOutdated));
  if (!(obj_ObsNum >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj_ObsNum, &vb_emlrtDCI, sp);
  }

  k = static_cast<int32_T>(muDoubleScalarFloor(obj_ObsNum));
  if (obj_ObsNum != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &ub_emlrtDCI, sp);
  }

  distance_obs.set_size(&ad_emlrtRTEI, sp, static_cast<int32_T>(obj_ObsNum));
  if (obj_ObsNum != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &ub_emlrtDCI, sp);
  }

  loop_ub = static_cast<int32_T>(obj_ObsNum);
  for (nx = 0; nx < loop_ub; nx++) {
    distance_obs[nx] = 0.0;
  }

  emlrtMEXProfilingStatement(10, static_cast<boolean_T>(isMexOutdated));
  if (obj_ObsNum != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &tb_emlrtDCI, sp);
  }

  emlrtMEXProfilingStatement(11, static_cast<boolean_T>(isMexOutdated));
  loop_ub = static_cast<int32_T>(obj_ObsNum);
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &wb_emlrtDCI, sp);
  }

  PoQo.set_size(&bd_emlrtRTEI, sp, loop_ub);
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &wb_emlrtDCI, sp);
  }

  for (nx = 0; nx < loop_ub; nx++) {
    PoQo[nx] = 0.0;
  }

  emlrtMEXProfilingStatement(12, static_cast<boolean_T>(isMexOutdated));
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &xb_emlrtDCI, sp);
  }

  phaiR.set_size(&cd_emlrtRTEI, sp, loop_ub);
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &xb_emlrtDCI, sp);
  }

  for (nx = 0; nx < loop_ub; nx++) {
    phaiR[nx] = 0.0;
  }

  emlrtMEXProfilingStatement(13, static_cast<boolean_T>(isMexOutdated));
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &yb_emlrtDCI, sp);
  }

  a.set_size(&dd_emlrtRTEI, sp, loop_ub);
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &yb_emlrtDCI, sp);
  }

  for (nx = 0; nx < loop_ub; nx++) {
    a[nx] = 0.0;
  }

  emlrtMEXProfilingStatement(14, static_cast<boolean_T>(isMexOutdated));
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &ac_emlrtDCI, sp);
  }

  grade_obs.set_size(&ed_emlrtRTEI, sp, loop_ub);
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &ac_emlrtDCI, sp);
  }

  for (nx = 0; nx < loop_ub; nx++) {
    grade_obs[nx] = 1.0;
  }

  emlrtMEXProfilingStatement(15, static_cast<boolean_T>(isMexOutdated));
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &bc_emlrtDCI, sp);
  }

  th_max.set_size(&fd_emlrtRTEI, sp, loop_ub);
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &bc_emlrtDCI, sp);
  }

  for (nx = 0; nx < loop_ub; nx++) {
    th_max[nx] = 0.0;
  }

  emlrtMEXProfilingStatement(16, static_cast<boolean_T>(isMexOutdated));
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &cc_emlrtDCI, sp);
  }

  th_min.set_size(&gd_emlrtRTEI, sp, loop_ub);
  if (loop_ub != k) {
    emlrtIntegerCheckR2012b(obj_ObsNum, &cc_emlrtDCI, sp);
  }

  for (k = 0; k < loop_ub; k++) {
    th_min[k] = 0.0;
  }

  emlrtMEXProfilingStatement(17, static_cast<boolean_T>(isMexOutdated));

  //      OBS_NOW = cell2mat(obs_now);
  emlrtMEXProfilingStatement(18, static_cast<boolean_T>(isMexOutdated));

  //      OBS = cell2mat(obs);
  emlrtMEXProfilingStatement(19, static_cast<boolean_T>(isMexOutdated));

  //  PMFのプロットする際にコメント外す
  //      resolution = 0.1;%PMFの分解能[deg]
  //      GRADE_TRGT = zeros(1,360/resolution);
  //      GRADE_OBS = ones(1,360/resolution);
  //      GRADE_obs = ones(obsnum,360/resolution);
  //      GRADE_ANGL = [-pi + resolution*pi/180:resolution*pi/180:pi];
  //      distance = norm(goal-[x y]);
  //      tic
  //      distance_obs = sqrt(sum((OBS_NOW - state).^2,2));
  //      distance_obs = vecnorm(OBS_NOW-state,2,2);
  //      toc
  //      tic
  emlrtMEXProfilingStatement(20, static_cast<boolean_T>(isMexOutdated));
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj_ObsNum, mxDOUBLE_CLASS,
    static_cast<int32_T>(obj_ObsNum), &p_emlrtRTEI, sp);
  for (nx = 0; nx < loop_ub; nx++) {
    emlrtMEXProfilingStatement(21, static_cast<boolean_T>(isMexOutdated));
    if (static_cast<int32_T>(nx + 1U) > obs_now_size[0]) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
        obs_now_size[0], &de_emlrtBCI, sp);
    }

    obs_now[0] = obs_now_data[nx] - x;
    obs_now[1] = obs_now_data[nx + obs_now_size[0]] - y;
    if (static_cast<int32_T>(nx + 1U) > distance_obs.size(0)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
        distance_obs.size(0), &ee_emlrtBCI, sp);
    }

    distance_obs[nx] = coder::b_norm(obs_now);
    emlrtMEXProfilingStatement(22, static_cast<boolean_T>(isMexOutdated));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  //      toc
  //      tic
  //      for i = 1:obsnum
  //          distance_obs(i,1) = norm(obs_now{i,1} - [x y]);
  //      end
  //     toc
  //      if distance < eps
  //          g_a = distance / eps;		
  //          g_b = eta * g_a;
  //      end
  emlrtMEXProfilingStatement(23, static_cast<boolean_T>(isMexOutdated));
  thg = muDoubleScalarAtan2(target[1] - y, target[0] - x) - th;
  emlrtMEXProfilingStatement(24, static_cast<boolean_T>(isMexOutdated));
  st.site = &x_emlrtRSI;
  nx = obs_size[0];
  y_size[0] = obs_size[0];
  for (k = 0; k < nx; k++) {
    y_data[k] = obs_data[k + obs_size[0]] - y;
  }

  nx = obs_size[0];
  x_size[0] = obs_size[0];
  for (k = 0; k < nx; k++) {
    x_data[k] = obs_data[k] - x;
  }

  b_st.site = &bb_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  csz_idx_0 = static_cast<int8_T>(obs_size[0]);
  z_size[0] = static_cast<int8_T>(obs_size[0]);
  if (!coder::internal::dimagree(z_size, y_size, x_size)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &k_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  idx = csz_idx_0;
  c_st.site = &db_emlrtRSI;
  nx = csz_idx_0;
  d_st.site = &eb_emlrtRSI;
  for (k = 0; k < nx; k++) {
    z1_data[k] = muDoubleScalarAtan2(y_data[k], x_data[k]);
  }

  tho.set_size(&id_emlrtRTEI, sp, static_cast<int32_T>(csz_idx_0));
  for (k = 0; k < idx; k++) {
    tho[k] = z1_data[k] - th;
  }

  //      PoQo = sqrt(sum((OBS - state).^2,2));
  //      PoQo = vecnorm(OBS-state,2,2);
  //      phaiR = abs(asin((r_wheel + r_obs)./PoQo));
  //      a = (alpha - PoQo)/(alpha - (r_wheel + r_obs));
  emlrtMEXProfilingStatement(25, static_cast<boolean_T>(isMexOutdated));
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj_ObsNum, mxDOUBLE_CLASS,
    static_cast<int32_T>(obj_ObsNum), &o_emlrtRTEI, sp);
  if (0 <= loop_ub - 1) {
    x_tmp = obj_r_wheel + obj_r_obs;
  }

  for (nx = 0; nx < loop_ub; nx++) {
    //          tho(i,1) = atan2((obs{i,1}(1,2) - y),(obs{i,1}(1,1) - x)) - th;
    //          PoQo(i,1) = norm(obs{i,1} - [x y]);
    emlrtMEXProfilingStatement(26, static_cast<boolean_T>(isMexOutdated));
    if (static_cast<int32_T>(nx + 1U) > obs_size[0]) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1, obs_size[0],
        &ce_emlrtBCI, sp);
    }

    obs_now[0] = obs_data[nx] - x;
    obs_now[1] = obs_data[nx + obs_size[0]] - y;
    if (static_cast<int32_T>(nx + 1U) > PoQo.size(0)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1, PoQo.size
        (0), &fe_emlrtBCI, sp);
    }

    PoQo[nx] = coder::b_norm(obs_now);
    emlrtMEXProfilingStatement(27, static_cast<boolean_T>(isMexOutdated));
    if (static_cast<int32_T>(nx + 1U) > PoQo.size(0)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1, PoQo.size
        (0), &re_emlrtBCI, sp);
    }

    b_x.re = x_tmp / PoQo[nx];
    b_x.im = 0.0;
    coder::b_asin(&b_x);
    if (static_cast<int32_T>(nx + 1U) > phaiR.size(0)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1, phaiR.size
        (0), &ge_emlrtBCI, sp);
    }

    phaiR[nx] = muDoubleScalarHypot(b_x.re, b_x.im);
    emlrtMEXProfilingStatement(28, static_cast<boolean_T>(isMexOutdated));
    if (static_cast<int32_T>(nx + 1U) > PoQo.size(0)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1, PoQo.size
        (0), &he_emlrtBCI, sp);
    }

    if (static_cast<int32_T>(nx + 1U) > a.size(0)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1, a.size(0),
        &ie_emlrtBCI, sp);
    }

    a[nx] = (2.5 - PoQo[nx]) / (2.5 - x_tmp);
    emlrtMEXProfilingStatement(29, static_cast<boolean_T>(isMexOutdated));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtMEXProfilingStatement(30, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(31, static_cast<boolean_T>(isMexOutdated));

  //      grade_trgt = ((g_a-g_b)/pi)*(pi-abs(thg))+g_b;
  emlrtMEXProfilingStatement(32, static_cast<boolean_T>(isMexOutdated));
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj_ObsNum, mxDOUBLE_CLASS,
    static_cast<int32_T>(obj_ObsNum), &n_emlrtRTEI, sp);
  for (nx = 0; nx < loop_ub; nx++) {
    //          grade_obs(i,1) = 1.0;
    //          if tho(i,1) - phaiR(i,1) <= 0.0 && 0.0 <= tho(i,1) + phaiR(i,1)
    emlrtMEXProfilingStatement(33, static_cast<boolean_T>(isMexOutdated));
    k = nx + 1;
    if (k > tho.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, tho.size(0), &be_emlrtBCI, sp);
    }

    if (k > phaiR.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, phaiR.size(0), &ae_emlrtBCI, sp);
    }

    if (k > tho.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, tho.size(0), &yd_emlrtBCI, sp);
    }

    if (k > phaiR.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, phaiR.size(0), &xd_emlrtBCI, sp);
    }

    if (static_cast<int32_T>(nx + 1U) > th_max.size(0)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
        th_max.size(0), &je_emlrtBCI, sp);
    }

    x_tmp = tho[nx] - phaiR[nx];
    th_max[nx] = muDoubleScalarAtan2(muDoubleScalarSin(x_tmp), muDoubleScalarCos
      (x_tmp));
    emlrtMEXProfilingStatement(34, static_cast<boolean_T>(isMexOutdated));
    if (k > tho.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, tho.size(0), &wd_emlrtBCI, sp);
    }

    if (k > phaiR.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, phaiR.size(0), &vd_emlrtBCI, sp);
    }

    if (k > tho.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, tho.size(0), &ud_emlrtBCI, sp);
    }

    if (k > phaiR.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, phaiR.size(0), &td_emlrtBCI, sp);
    }

    if (static_cast<int32_T>(nx + 1U) > th_min.size(0)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
        th_min.size(0), &ke_emlrtBCI, sp);
    }

    x_tmp = tho[nx] + phaiR[nx];
    th_min[nx] = muDoubleScalarAtan2(muDoubleScalarSin(x_tmp), muDoubleScalarCos
      (x_tmp));

    //          th_max_local(i,1) = tho(i,1) - phaiR(i,1);
    //          th_min_local(i,1) = tho(i,1) + phaiR(i,1);
    emlrtMEXProfilingStatement(35, static_cast<boolean_T>(isMexOutdated));
    if (static_cast<int32_T>(nx + 1U) > th_max.size(0)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
        th_max.size(0), &le_emlrtBCI, sp);
    }

    if (th_max[nx] <= 0.0) {
      if (static_cast<int32_T>(nx + 1U) > th_min.size(0)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
          th_min.size(0), &me_emlrtBCI, sp);
      }

      if (0.0 <= th_min[nx]) {
        emlrtMEXProfilingStatement(36, static_cast<boolean_T>(isMexOutdated));
        if (static_cast<int32_T>(nx + 1U) > PoQo.size(0)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
            PoQo.size(0), &ne_emlrtBCI, sp);
        }

        if (PoQo[nx] < 2.5) {
          emlrtMEXProfilingStatement(37, static_cast<boolean_T>(isMexOutdated));
          if (static_cast<int32_T>(nx + 1U) > a.size(0)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
              a.size(0), &oe_emlrtBCI, sp);
          }

          if (static_cast<int32_T>(nx + 1U) > grade_obs.size(0)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
              grade_obs.size(0), &pe_emlrtBCI, sp);
          }

          grade_obs[nx] = 1.0 - a[nx];
          emlrtMEXProfilingStatement(40, static_cast<boolean_T>(isMexOutdated));
        } else {
          emlrtMEXProfilingStatement(38, static_cast<boolean_T>(isMexOutdated));

          //
          emlrtMEXProfilingStatement(39, static_cast<boolean_T>(isMexOutdated));
          if (static_cast<int32_T>(nx + 1U) > grade_obs.size(0)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nx + 1U), 1,
              grade_obs.size(0), &qe_emlrtBCI, sp);
          }

          grade_obs[nx] = 1.0;
          emlrtMEXProfilingStatement(40, static_cast<boolean_T>(isMexOutdated));
        }

        emlrtMEXProfilingStatement(41, static_cast<boolean_T>(isMexOutdated));
      }
    }

    emlrtMEXProfilingStatement(42, static_cast<boolean_T>(isMexOutdated));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtMEXProfilingStatement(43, static_cast<boolean_T>(isMexOutdated));
  st.site = &y_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &hb_emlrtRSI;
  if (grade_obs.size(0) < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &l_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &ib_emlrtRSI;
  f_st.site = &jb_emlrtRSI;
  nx = grade_obs.size(0);
  if (grade_obs.size(0) <= 2) {
    if (grade_obs.size(0) == 1) {
      x_tmp = grade_obs[0];
    } else if ((grade_obs[0] > grade_obs[1]) || (muDoubleScalarIsNaN(grade_obs[0])
                && (!muDoubleScalarIsNaN(grade_obs[1])))) {
      x_tmp = grade_obs[1];
    } else {
      x_tmp = grade_obs[0];
    }
  } else {
    g_st.site = &lb_emlrtRSI;
    if (!muDoubleScalarIsNaN(grade_obs[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &mb_emlrtRSI;
      if (grade_obs.size(0) > 2147483646) {
        i_st.site = &v_emlrtRSI;
        coder::check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= grade_obs.size(0))) {
        if (!muDoubleScalarIsNaN(grade_obs[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      x_tmp = grade_obs[0];
    } else {
      g_st.site = &kb_emlrtRSI;
      x_tmp = grade_obs[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &nb_emlrtRSI;
      if ((idx + 1 <= grade_obs.size(0)) && (grade_obs.size(0) > 2147483646)) {
        i_st.site = &v_emlrtRSI;
        coder::check_forloop_overflow_error(&i_st);
      }

      for (k = loop_ub; k <= nx; k++) {
        real_T d;
        d = grade_obs[k - 1];
        if (x_tmp > d) {
          x_tmp = d;
        }
      }
    }
  }

  *Grade_old = muDoubleScalarMin(-0.38197186342054879 * muDoubleScalarAbs
    (muDoubleScalarAtan2(muDoubleScalarSin(thg), muDoubleScalarCos(thg))) + 1.0,
    x_tmp);

  //      phai = -pi + resolution*pi/180;
  //      for j = 1:360/resolution
  //          phaierror = atan2(sin(thg - phai),cos(thg - phai));
  //          GRADE_TRGT(1,j) = -((g_a - g_b)/pi)*abs(phaierror) + g_a;
  //          for i = 1:obsnum
  //              if th_min_local(i,1) > pi || th_max_local(i,1) < -pi
  //                  if or(th_max(i,1) <= phai && phai <= pi,th_min(i,1) >= phai && phai >= -pi) 
  //                      if PoQo(i,1) < alpha
  //                          GRADE_obs(i,j) = 1 - a(i,1);
  //                      end
  //                  end
  //              else
  //                  if th_max(i,1) <= phai && phai <= th_min(i,1)
  //                      if PoQo(i,1) < alpha
  //                          GRADE_obs(i,j) = 1 - a(i,1);
  //                      end
  //                  end
  //              end
  //          end
  //          phai = phai + resolution*pi/180;
  //      end
  //      GRADE_OBS = min(GRADE_obs,[],1);
  //      Grade = max(min([GRADE_TRGT;GRADE_OBS],[],1));
  emlrtMEXProfilingStatement(44, static_cast<boolean_T>(isMexOutdated));
  *Grade = -10.0;
  emlrtMEXProfilingStatement(45, static_cast<boolean_T>(isMexOutdated));
  st.site = &ab_emlrtRSI;
  x_tmp = obj_r_wheel + obj_r_obs;
  loop_ub = distance_obs.size(0);
  c_x.set_size(&jd_emlrtRTEI, &st, distance_obs.size(0));
  for (k = 0; k < loop_ub; k++) {
    c_x[k] = (distance_obs[k] < x_tmp);
  }

  b_st.site = &ob_emlrtRSI;
  b_y = false;
  c_st.site = &pb_emlrtRSI;
  if ((1 <= c_x.size(0)) && (c_x.size(0) > 2147483646)) {
    d_st.site = &v_emlrtRSI;
    coder::check_forloop_overflow_error(&d_st);
  }

  nx = 1;
  exitg1 = false;
  while ((!exitg1) && (nx <= c_x.size(0))) {
    if (!c_x[nx - 1]) {
      nx++;
    } else {
      b_y = true;
      exitg1 = true;
    }
  }

  if (b_y) {
    emlrtMEXProfilingStatement(46, static_cast<boolean_T>(isMexOutdated));
    *Grade = -100.0;
    emlrtMEXProfilingStatement(47, static_cast<boolean_T>(isMexOutdated));
    *Grade_old = -100.0;
    emlrtMEXProfilingStatement(48, static_cast<boolean_T>(isMexOutdated));
  }

  emlrtMEXProfilingStatement(49, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (FPM_4.cpp)
