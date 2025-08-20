//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mexLidarTracker_data.cpp
//
//  Code generation for function 'mexLidarTracker_data'
//


// Include files
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
boolean_T isMexOutdated;
const char_T *mexLidarTracker_complete_name;
const char_T *c_HelperBoundingBoxDetector_Hel;
const char_T *c_HelperBoundingBoxDetector_ste;
const char_T *cropPointCloud2_complete_name;
const char_T *removeGroundPlane_complete_name;
const char_T *getBoundingBoxes_complete_name;
const char_T *homogeneous_complete_name;
const char_T *c_assembleDetections_complete_n;
const char_T *initializeEKF_complete_name;
const char_T *c_helperCalcDetectability_compl;
emlrtContext emlrtContextGlobal = { true,// bFirstTime
  false,                               // bInitialized
  131595U,                             // fVersionInfo
  NULL,                                // fErrorFunction
  "mexLidarTracker",                   // fFunctionName
  NULL,                                // fRTCallStack
  false,                               // bDebugMode
  { 1289804844U, 474517995U, 4058475124U, 792733075U },// fSigWrd
  NULL                                 // fSigMem
};

emlrtRSInfo l_emlrtRSI = { 1,          // lineNo
  "SystemCore/release",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

emlrtRSInfo yb_emlrtRSI = { 76,        // lineNo
  "validateattributes",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/lang/validateattributes.m"// pathName 
};

emlrtRSInfo ec_emlrtRSI = { 12,        // lineNo
  "svd",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/svd.m"// pathName
};

emlrtRSInfo gc_emlrtRSI = { 29,        // lineNo
  "anyNonFinite",                      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/anyNonFinite.m"// pathName 
};

emlrtRSInfo hc_emlrtRSI = { 44,        // lineNo
  "vAllOrAny",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"// pathName 
};

emlrtRSInfo jc_emlrtRSI = { 21,        // lineNo
  "eml_int_forloop_overflow_check",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"// pathName 
};

emlrtRSInfo lc_emlrtRSI = { 108,       // lineNo
  "callLAPACK",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/svd.m"// pathName
};

emlrtRSInfo mc_emlrtRSI = { 34,        // lineNo
  "xgesvd",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"// pathName 
};

emlrtRSInfo md_emlrtRSI = { 14,        // lineNo
  "max",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/max.m"// pathName
};

emlrtRSInfo nd_emlrtRSI = { 44,        // lineNo
  "minOrMax",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

emlrtRSInfo od_emlrtRSI = { 79,        // lineNo
  "maximum",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

emlrtRSInfo pd_emlrtRSI = { 152,       // lineNo
  "unaryMinOrMax",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo qd_emlrtRSI = { 1042,      // lineNo
  "maxRealVectorOmitNaN",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo rd_emlrtRSI = { 955,       // lineNo
  "minOrMaxRealVector",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo sd_emlrtRSI = { 1015,      // lineNo
  "minOrMaxRealVectorKernel",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo td_emlrtRSI = { 14,        // lineNo
  "min",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/min.m"// pathName
};

emlrtRSInfo ud_emlrtRSI = { 46,        // lineNo
  "minOrMax",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

emlrtRSInfo vd_emlrtRSI = { 92,        // lineNo
  "minimum",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

emlrtRSInfo wd_emlrtRSI = { 170,       // lineNo
  "unaryMinOrMax",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo xd_emlrtRSI = { 1038,      // lineNo
  "minRealVectorOmitNaN",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo yd_emlrtRSI = { 46,        // lineNo
  "eps",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/eps.m"// pathName
};

emlrtRSInfo ie_emlrtRSI = { 45,        // lineNo
  "xger",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/xger.m"// pathName 
};

emlrtRSInfo je_emlrtRSI = { 15,        // lineNo
  "xger",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xger.m"// pathName 
};

emlrtRSInfo ke_emlrtRSI = { 54,        // lineNo
  "xgerx",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xgerx.m"// pathName 
};

emlrtRSInfo le_emlrtRSI = { 41,        // lineNo
  "xgerx",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xgerx.m"// pathName 
};

emlrtRSInfo xe_emlrtRSI = { 48,        // lineNo
  "eml_mtimes_helper",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pathName 
};

emlrtRSInfo jf_emlrtRSI = { 39,        // lineNo
  "find",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

emlrtRSInfo ig_emlrtRSI = { 32,        // lineNo
  "sort",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sort.m"// pathName
};

emlrtRSInfo qg_emlrtRSI = { 105,       // lineNo
  "sortIdx",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

emlrtRSInfo rg_emlrtRSI = { 308,       // lineNo
  "block_merge_sort",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

emlrtRSInfo sg_emlrtRSI = { 316,       // lineNo
  "block_merge_sort",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

emlrtRSInfo tg_emlrtRSI = { 317,       // lineNo
  "block_merge_sort",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

emlrtRSInfo ug_emlrtRSI = { 325,       // lineNo
  "block_merge_sort",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

emlrtRSInfo vg_emlrtRSI = { 333,       // lineNo
  "block_merge_sort",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

emlrtRSInfo wi_emlrtRSI = { 15,        // lineNo
  "sum",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sum.m"// pathName
};

emlrtRSInfo xi_emlrtRSI = { 99,        // lineNo
  "sumprod",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pathName 
};

emlrtRSInfo yi_emlrtRSI = { 133,       // lineNo
  "combineVectorElements",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo aj_emlrtRSI = { 178,       // lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo bj_emlrtRSI = { 196,       // lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo tj_emlrtRSI = { 13,        // lineNo
  "all",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/all.m"// pathName
};

emlrtRSInfo uj_emlrtRSI = { 143,       // lineNo
  "allOrAny",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"// pathName 
};

emlrtRSInfo yj_emlrtRSI = { 79,        // lineNo
  "eml_mtimes_helper",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pathName 
};

emlrtRSInfo ak_emlrtRSI = { 142,       // lineNo
  "mtimes",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"// pathName 
};

emlrtRSInfo bk_emlrtRSI = { 51,        // lineNo
  "mtimes",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/mtimes.m"// pathName 
};

emlrtRSInfo ck_emlrtRSI = { 178,       // lineNo
  "mtimes_blas",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"// pathName 
};

emlrtRSInfo fk_emlrtRSI = { 20,        // lineNo
  "sum",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sum.m"// pathName
};

emlrtRSInfo gk_emlrtRSI = { 69,        // lineNo
  "combineVectorElements",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo hk_emlrtRSI = { 87,        // lineNo
  "blockedSummation",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"// pathName 
};

emlrtRSInfo ik_emlrtRSI = { 166,       // lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"// pathName 
};

emlrtRSInfo jk_emlrtRSI = { 180,       // lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"// pathName 
};

emlrtRSInfo kk_emlrtRSI = { 201,       // lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"// pathName 
};

emlrtRSInfo lk_emlrtRSI = { 194,       // lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo pk_emlrtRSI = { 45,        // lineNo
  "mpower",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/mpower.m"// pathName
};

emlrtRSInfo qk_emlrtRSI = { 70,        // lineNo
  "power",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"// pathName
};

emlrtRSInfo tk_emlrtRSI = { 33,        // lineNo
  "applyScalarFunctionInPlace",        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"// pathName 
};

emlrtRSInfo yk_emlrtRSI = { 28,        // lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

emlrtRSInfo il_emlrtRSI = { 66,        // lineNo
  "applyBinaryScalarFunction",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pathName 
};

emlrtRSInfo gn_emlrtRSI = { 44,        // lineNo
  "unique",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

emlrtRSInfo pn_emlrtRSI = { 57,        // lineNo
  "mergesort",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"// pathName 
};

emlrtRSInfo qn_emlrtRSI = { 113,       // lineNo
  "mergesort",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"// pathName 
};

emlrtRSInfo un_emlrtRSI = { 49,        // lineNo
  "mean",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/mean.m"// pathName
};

emlrtRSInfo vn_emlrtRSI = { 947,       // lineNo
  "minOrMaxRealVector",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo wn_emlrtRSI = { 998,       // lineNo
  "findFirst",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo jo_emlrtRSI = { 13,        // lineNo
  "isSymmetricPositiveSemiDefinite",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/isSymmetricPositiveSemiDefinite.m"// pathName 
};

emlrtRSInfo no_emlrtRSI = { 21,        // lineNo
  "eigHermitianStandard",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/private/eigHermitianStandard.m"// pathName 
};

emlrtRSInfo oo_emlrtRSI = { 35,        // lineNo
  "schur",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/schur.m"// pathName
};

emlrtRSInfo po_emlrtRSI = { 52,        // lineNo
  "schur",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/schur.m"// pathName
};

emlrtRSInfo qo_emlrtRSI = { 54,        // lineNo
  "schur",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/schur.m"// pathName
};

emlrtRSInfo ro_emlrtRSI = { 83,        // lineNo
  "schur",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/schur.m"// pathName
};

emlrtRSInfo so_emlrtRSI = { 18,        // lineNo
  "xgehrd",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xgehrd.m"// pathName 
};

emlrtRSInfo to_emlrtRSI = { 31,        // lineNo
  "xzgehrd",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgehrd.m"// pathName 
};

emlrtRSInfo uo_emlrtRSI = { 35,        // lineNo
  "xzgehrd",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgehrd.m"// pathName 
};

emlrtRSInfo vo_emlrtRSI = { 43,        // lineNo
  "xzgehrd",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgehrd.m"// pathName 
};

emlrtRSInfo wo_emlrtRSI = { 20,        // lineNo
  "xzlarfg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"// pathName 
};

emlrtRSInfo xo_emlrtRSI = { 41,        // lineNo
  "xzlarfg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"// pathName 
};

emlrtRSInfo yo_emlrtRSI = { 53,        // lineNo
  "xzlarfg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"// pathName 
};

emlrtRSInfo ap_emlrtRSI = { 68,        // lineNo
  "xzlarfg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"// pathName 
};

emlrtRSInfo bp_emlrtRSI = { 71,        // lineNo
  "xzlarfg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"// pathName 
};

emlrtRSInfo cp_emlrtRSI = { 81,        // lineNo
  "xzlarfg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"// pathName 
};

emlrtRSInfo dp_emlrtRSI = { 84,        // lineNo
  "xzlarf",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"// pathName 
};

emlrtRSInfo ep_emlrtRSI = { 91,        // lineNo
  "xzlarf",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"// pathName 
};

emlrtRSInfo fp_emlrtRSI = { 64,        // lineNo
  "xgemv",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/xgemv.m"// pathName 
};

emlrtRSInfo gp_emlrtRSI = { 58,        // lineNo
  "xgemv",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xgemv.m"// pathName 
};

emlrtRSInfo hp_emlrtRSI = { 37,        // lineNo
  "xgemv",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xgemv.m"// pathName 
};

emlrtRSInfo ip_emlrtRSI = { 45,        // lineNo
  "xgerc",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/xgerc.m"// pathName 
};

emlrtRSInfo jp_emlrtRSI = { 75,        // lineNo
  "xzlarf",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"// pathName 
};

emlrtRSInfo kp_emlrtRSI = { 68,        // lineNo
  "xzlarf",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"// pathName 
};

emlrtRSInfo lp_emlrtRSI = { 50,        // lineNo
  "xzlarf",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"// pathName 
};

emlrtRSInfo np_emlrtRSI = { 74,        // lineNo
  "xgemv",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/xgemv.m"// pathName 
};

emlrtRSInfo op_emlrtRSI = { 32,        // lineNo
  "xhseqr",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xhseqr.m"// pathName 
};

emlrtRSInfo pp_emlrtRSI = { 13,        // lineNo
  "xdhseqr",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xdhseqr.m"// pathName 
};

emlrtRSInfo rp_emlrtRSI = { 359,       // lineNo
  "eml_dlahqr",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xdhseqr.m"// pathName 
};

emlrtRSInfo vp_emlrtRSI = { 263,       // lineNo
  "eml_dlahqr",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xdhseqr.m"// pathName 
};

emlrtRSInfo vr_emlrtRSI = { 1,         // lineNo
  "SystemCore/step",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

emlrtRSInfo wr_emlrtRSI = { 1,         // lineNo
  "SystemCore/setupAndReset",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

emlrtRSInfo xr_emlrtRSI = { 1,         // lineNo
  "SystemCore/setup",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

emlrtRSInfo et_emlrtRSI = { 15,        // lineNo
  "cholPSD",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/cholPSD.m"// pathName 
};

emlrtRSInfo gt_emlrtRSI = { 20,        // lineNo
  "cholPSD",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/cholPSD.m"// pathName 
};

emlrtRSInfo ht_emlrtRSI = { 44,        // lineNo
  "chol",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/chol.m"// pathName
};

emlrtRSInfo it_emlrtRSI = { 92,        // lineNo
  "cholesky",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/chol.m"// pathName
};

emlrtRSInfo jt_emlrtRSI = { 91,        // lineNo
  "cholesky",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/chol.m"// pathName
};

emlrtRSInfo kt_emlrtRSI = { 74,        // lineNo
  "cholesky",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/chol.m"// pathName
};

emlrtRSInfo xt_emlrtRSI = { 15,        // lineNo
  "svdPSD",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/svdPSD.m"// pathName 
};

emlrtRSInfo yt_emlrtRSI = { 17,        // lineNo
  "svdPSD",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/svdPSD.m"// pathName 
};

emlrtRSInfo au_emlrtRSI = { 25,        // lineNo
  "svd",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/svd.m"// pathName
};

emlrtRSInfo bu_emlrtRSI = { 33,        // lineNo
  "svd",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/svd.m"// pathName
};

emlrtRSInfo cu_emlrtRSI = { 53,        // lineNo
  "svd",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/svd.m"// pathName
};

emlrtRSInfo su_emlrtRSI = { 85,        // lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

emlrtRSInfo ry_emlrtRSI = { 98,        // lineNo
  "constvel",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pathName 
};

emlrtRSInfo sy_emlrtRSI = { 139,       // lineNo
  "constvel",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pathName 
};

emlrtRSInfo ty_emlrtRSI = { 145,       // lineNo
  "constvel",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pathName 
};

emlrtRSInfo bab_emlrtRSI = { 17,       // lineNo
  "qrFactor",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/qrFactor.m"// pathName 
};

emlrtRSInfo cab_emlrtRSI = { 18,       // lineNo
  "qrFactor",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/qrFactor.m"// pathName 
};

emlrtRSInfo dab_emlrtRSI = { 136,      // lineNo
  "mtimes",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"// pathName 
};

emlrtRSInfo eab_emlrtRSI = { 150,      // lineNo
  "MMRF",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/mtimes.m"// pathName 
};

emlrtRSInfo fab_emlrtRSI = { 25,       // lineNo
  "qr",                                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/qr.m"// pathName
};

emlrtRSInfo gab_emlrtRSI = { 35,       // lineNo
  "eml_qr",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"// pathName 
};

emlrtRSInfo hab_emlrtRSI = { 153,      // lineNo
  "qr_econ",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"// pathName 
};

emlrtRSInfo iab_emlrtRSI = { 162,      // lineNo
  "qr_econ",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"// pathName 
};

emlrtRSInfo jab_emlrtRSI = { 174,      // lineNo
  "qr_econ",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"// pathName 
};

emlrtRSInfo kab_emlrtRSI = { 30,       // lineNo
  "xgeqrf",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqrf.m"// pathName 
};

emlrtRSInfo lab_emlrtRSI = { 111,      // lineNo
  "xzgeqp3",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"// pathName 
};

emlrtRSInfo mab_emlrtRSI = { 155,      // lineNo
  "qrf",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"// pathName 
};

emlrtRSInfo nab_emlrtRSI = { 141,      // lineNo
  "qrf",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"// pathName 
};

emlrtRSInfo oab_emlrtRSI = { 130,      // lineNo
  "qrf",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"// pathName 
};

emlrtRSInfo pab_emlrtRSI = { 189,      // lineNo
  "unpackQR",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"// pathName 
};

emlrtRSInfo qab_emlrtRSI = { 17,       // lineNo
  "xorgqr",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xorgqr.m"// pathName 
};

emlrtRSInfo rab_emlrtRSI = { 46,       // lineNo
  "xzungqr",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzungqr.m"// pathName 
};

emlrtRSInfo sab_emlrtRSI = { 41,       // lineNo
  "xzungqr",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzungqr.m"// pathName 
};

emlrtRSInfo tab_emlrtRSI = { 34,       // lineNo
  "xzungqr",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzungqr.m"// pathName 
};

emlrtRSInfo uab_emlrtRSI = { 16,       // lineNo
  "xzungqr",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzungqr.m"// pathName 
};

emlrtRSInfo tbb_emlrtRSI = { 27,       // lineNo
  "sort",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sort.m"// pathName
};

emlrtRSInfo ecb_emlrtRSI = { 117,      // lineNo
  "cvmeas",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/cvmeas.m"// pathName 
};

emlrtRSInfo hcb_emlrtRSI = { 20,       // lineNo
  "mrdivide_helper",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mrdivide_helper.m"// pathName 
};

emlrtRSInfo icb_emlrtRSI = { 42,       // lineNo
  "mrdiv",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mrdivide_helper.m"// pathName 
};

emlrtRSInfo jcb_emlrtRSI = { 61,       // lineNo
  "lusolve",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/lusolve.m"// pathName 
};

emlrtRSInfo kcb_emlrtRSI = { 293,      // lineNo
  "lusolve3x3",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/lusolve.m"// pathName 
};

emlrtRSInfo mcb_emlrtRSI = { 90,       // lineNo
  "warn_singular",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/lusolve.m"// pathName 
};

emlrtRSInfo aeb_emlrtRSI = { 27,       // lineNo
  "cat",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"// pathName
};

emlrtRSInfo beb_emlrtRSI = { 102,      // lineNo
  "cat_impl",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"// pathName
};

emlrtRSInfo xfb_emlrtRSI = { 14,       // lineNo
  "validateInputSizeAndType",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/validateInputSizeAndType.m"// pathName 
};

emlrtRSInfo ogb_emlrtRSI = { 173,      // lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo chb_emlrtRSI = { 46,       // lineNo
  "applyBinaryScalarFunction",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pathName 
};

emlrtRSInfo dhb_emlrtRSI = { 202,      // lineNo
  "flatIter",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pathName 
};

emlrtRTEInfo emlrtRTEI = { 283,        // lineNo
  27,                                  // colNo
  "check_non_axis_size",               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"// pName
};

emlrtRTEInfo j_emlrtRTEI = { 14,       // lineNo
  37,                                  // colNo
  "validatefinite",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatefinite.m"// pName 
};

emlrtRTEInfo n_emlrtRTEI = { 118,      // lineNo
  23,                                  // colNo
  "dynamic_size_checks",               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pName 
};

emlrtRTEInfo o_emlrtRTEI = { 123,      // lineNo
  23,                                  // colNo
  "dynamic_size_checks",               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pName 
};

emlrtRTEInfo s_emlrtRTEI = { 13,       // lineNo
  37,                                  // colNo
  "validateinteger",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validateinteger.m"// pName 
};

emlrtRTEInfo u_emlrtRTEI = { 14,       // lineNo
  37,                                  // colNo
  "validatenonnan",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnan.m"// pName 
};

emlrtRTEInfo w_emlrtRTEI = { 14,       // lineNo
  37,                                  // colNo
  "validatenonnegative",               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnegative.m"// pName 
};

emlrtRTEInfo x_emlrtRTEI = { 13,       // lineNo
  37,                                  // colNo
  "validatenonzero",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonzero.m"// pName 
};

emlrtRTEInfo y_emlrtRTEI = { 14,       // lineNo
  37,                                  // colNo
  "validatepositive",                  // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatepositive.m"// pName 
};

emlrtRTEInfo db_emlrtRTEI = { 64,      // lineNo
  15,                                  // colNo
  "assertValidSizeArg",                // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"// pName 
};

emlrtRTEInfo eb_emlrtRTEI = { 49,      // lineNo
  19,                                  // colNo
  "assertValidSizeArg",                // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"// pName 
};

emlrtRTEInfo ib_emlrtRTEI = { 18,      // lineNo
  23,                                  // colNo
  "validatenumel",                     // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenumel.m"// pName 
};

emlrtRTEInfo jb_emlrtRTEI = { 99,      // lineNo
  27,                                  // colNo
  "unaryMinOrMax",                     // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pName 
};

emlrtRTEInfo ob_emlrtRTEI = { 13,      // lineNo
  9,                                   // colNo
  "sqrt",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/sqrt.m"// pName
};

emlrtRTEInfo qb_emlrtRTEI = { 17,      // lineNo
  5,                                   // colNo
  "isSymmetricPositiveSemiDefinite",   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/isSymmetricPositiveSemiDefinite.m"// pName 
};

emlrtRTEInfo ub_emlrtRTEI = { 1,       // lineNo
  1,                                   // colNo
  "SystemCore/step",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pName 
};

emlrtRTEInfo wb_emlrtRTEI = { 1,       // lineNo
  1,                                   // colNo
  "SystemCore/setup",                  // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pName 
};

emlrtBCInfo cd_emlrtBCI = { -1,        // iFirst
  -1,                                  // iLast
  89,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

emlrtRTEInfo yb_emlrtRTEI = { 47,      // lineNo
  13,                                  // colNo
  "infocheck",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"// pName 
};

emlrtRTEInfo ac_emlrtRTEI = { 44,      // lineNo
  13,                                  // colNo
  "infocheck",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"// pName 
};

emlrtDCInfo p_emlrtDCI = { 31,         // lineNo
  14,                                  // colNo
  "repmat",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m",// pName
  4                                    // checkKind
};

emlrtRTEInfo jc_emlrtRTEI = { 14,      // lineNo
  9,                                   // colNo
  "log",                               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/log.m"// pName
};

emlrtRTEInfo uc_emlrtRTEI = { 19,      // lineNo
  23,                                  // colNo
  "scalexpAlloc",                      // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"// pName 
};

emlrtRTEInfo uf_emlrtRTEI = { 46,      // lineNo
  6,                                   // colNo
  "applyBinaryScalarFunction",         // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pName 
};

emlrtRTEInfo hg_emlrtRTEI = { 15,      // lineNo
  13,                                  // colNo
  "isinf",                             // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/isinf.m"// pName
};

emlrtRTEInfo ig_emlrtRTEI = { 15,      // lineNo
  13,                                  // colNo
  "isnan",                             // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/isnan.m"// pName
};

emlrtRTEInfo kg_emlrtRTEI = { 166,     // lineNo
  24,                                  // colNo
  "combineVectorElements",             // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pName 
};

emlrtRTEInfo lg_emlrtRTEI = { 15,      // lineNo
  9,                                   // colNo
  "sum",                               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sum.m"// pName
};

emlrtRTEInfo og_emlrtRTEI = { 218,     // lineNo
  20,                                  // colNo
  "mtimes",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"// pName 
};

emlrtRTEInfo th_emlrtRTEI = { 52,      // lineNo
  9,                                   // colNo
  "mergesort",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"// pName 
};

emlrtRTEInfo rk_emlrtRTEI = { 28,      // lineNo
  5,                                   // colNo
  "sort",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sort.m"// pName
};

emlrtRTEInfo wk_emlrtRTEI = { 60,      // lineNo
  20,                                  // colNo
  "bsxfun",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/bsxfun.m"// pName
};

emlrtRTEInfo nm_emlrtRTEI = { 17,      // lineNo
  9,                                   // colNo
  "scalexpAlloc",                      // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"// pName 
};

emlrtRTEInfo xn_emlrtRTEI = { 386,     // lineNo
  1,                                   // colNo
  "sortIdx",                           // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pName
};

emlrtRTEInfo yn_emlrtRTEI = { 388,     // lineNo
  1,                                   // colNo
  "sortIdx",                           // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pName
};

const int8_T iv[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

// End of code generation (mexLidarTracker_data.cpp)
