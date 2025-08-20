//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  trackingEKF.cpp
//
//  Code generation for function 'trackingEKF'
//


// Include files
#include "trackingEKF.h"
#include "EKFCorrector.h"
#include "EKFCorrectorAdditive.h"
#include "EKFPredictorNonAdditive.h"
#include "anonymous_function.h"
#include "chol.h"
#include "cholPSD.h"
#include "cvmeas.h"
#include "cvmeasjac.h"
#include "det.h"
#include "eig.h"
#include "eml_int_forloop_overflow_check.h"
#include "isSymmetricPositiveSemiDefinite.h"
#include "mexLidarTracker_data.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "svdPSD.h"
#include "validateInputSizeAndType.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <math.h>
#include <string.h>

// Variable Definitions
static emlrtRSInfo ho_emlrtRSI = { 10, // lineNo
  "isSymmetricPositiveSemiDefinite",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/isSymmetricPositiveSemiDefinite.m"// pathName 
};

static emlrtRSInfo io_emlrtRSI = { 11, // lineNo
  "isSymmetricPositiveSemiDefinite",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/isSymmetricPositiveSemiDefinite.m"// pathName 
};

static emlrtRSInfo ms_emlrtRSI = { 119,// lineNo
  "trackingEKF/trackingEKF",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo ns_emlrtRSI = { 122,// lineNo
  "trackingEKF/trackingEKF",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo ps_emlrtRSI = { 465,// lineNo
  "ExtendedKalmanFilter/ExtendedKalmanFilter",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo qs_emlrtRSI = { 473,// lineNo
  "ExtendedKalmanFilter/ExtendedKalmanFilter",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo ts_emlrtRSI = { 513,// lineNo
  "ExtendedKalmanFilter/ExtendedKalmanFilter",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo us_emlrtRSI = { 537,// lineNo
  "ExtendedKalmanFilter/ExtendedKalmanFilter",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo vs_emlrtRSI = { 801,// lineNo
  "ExtendedKalmanFilter/set.State",    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo ws_emlrtRSI = { 889,// lineNo
  "ExtendedKalmanFilter/set.StateCovariance",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo xs_emlrtRSI = { 898,// lineNo
  "ExtendedKalmanFilter/set.StateCovariance",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo ys_emlrtRSI = { 902,// lineNo
  "ExtendedKalmanFilter/set.StateCovariance",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo at_emlrtRSI = { 909,// lineNo
  "ExtendedKalmanFilter/set.StateCovariance",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo ju_emlrtRSI = { 960,// lineNo
  "ExtendedKalmanFilter/set.ProcessNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo ku_emlrtRSI = { 967,// lineNo
  "ExtendedKalmanFilter/set.ProcessNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo lu_emlrtRSI = { 1000,// lineNo
  "ExtendedKalmanFilter/set.MeasurementNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo mu_emlrtRSI = { 1011,// lineNo
  "ExtendedKalmanFilter/set.MeasurementNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo nu_emlrtRSI = { 1022,// lineNo
  "ExtendedKalmanFilter/set.MeasurementNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo ou_emlrtRSI = { 1029,// lineNo
  "ExtendedKalmanFilter/set.MeasurementNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo vv_emlrtRSI = { 377,// lineNo
  "trackingEKF/nullify",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo wv_emlrtRSI = { 378,// lineNo
  "trackingEKF/nullify",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo xv_emlrtRSI = { 1154,// lineNo
  "ExtendedKalmanFilter/set.pStateCovariance",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo jw_emlrtRSI = { 405,// lineNo
  "trackingEKF/sync",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo kw_emlrtRSI = { 406,// lineNo
  "trackingEKF/sync",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo lw_emlrtRSI = { 407,// lineNo
  "trackingEKF/sync",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo mw_emlrtRSI = { 408,// lineNo
  "trackingEKF/sync",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo tw_emlrtRSI = { 1215,// lineNo
  "ExtendedKalmanFilter/set.pMeasurementNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo xw_emlrtRSI = { 1185,// lineNo
  "ExtendedKalmanFilter/set.pProcessNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo oy_emlrtRSI = { 606,// lineNo
  "ExtendedKalmanFilter/predict",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo py_emlrtRSI = { 615,// lineNo
  "ExtendedKalmanFilter/predict",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo acb_emlrtRSI = { 423,// lineNo
  "@(state,dt) filter.StateTransitionFcn(state,v,dt)",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo ddb_emlrtRSI = { 271,// lineNo
  "trackingEKF/distance",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo edb_emlrtRSI = { 284,// lineNo
  "trackingEKF/distance",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo fdb_emlrtRSI = { 287,// lineNo
  "trackingEKF/distance",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo gdb_emlrtRSI = { 6, // lineNo
  "validateMeasurementMatrix",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/validateMeasurementMatrix.m"// pathName 
};

static emlrtRSInfo hdb_emlrtRSI = { 1735,// lineNo
  "ExtendedKalmanFilter/validateMeasurementAndRelatedProperties",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo idb_emlrtRSI = { 1737,// lineNo
  "ExtendedKalmanFilter/validateMeasurementAndRelatedProperties",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo jdb_emlrtRSI = { 1741,// lineNo
  "ExtendedKalmanFilter/validateMeasurementAndRelatedProperties",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo ldb_emlrtRSI = { 1710,// lineNo
  "ExtendedKalmanFilter/validateMeasurementFcn",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo pdb_emlrtRSI = { 46,// lineNo
  "EKFDistanceAdditive",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFDistanceAdditive.m"// pathName 
};

static emlrtRSInfo qdb_emlrtRSI = { 49,// lineNo
  "EKFDistanceAdditive",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFDistanceAdditive.m"// pathName 
};

static emlrtRSInfo rdb_emlrtRSI = { 54,// lineNo
  "EKFDistanceAdditive",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFDistanceAdditive.m"// pathName 
};

static emlrtRSInfo sdb_emlrtRSI = { 56,// lineNo
  "EKFDistanceAdditive",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFDistanceAdditive.m"// pathName 
};

static emlrtRSInfo tdb_emlrtRSI = { 59,// lineNo
  "EKFDistanceAdditive",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFDistanceAdditive.m"// pathName 
};

static emlrtRSInfo vdb_emlrtRSI = { 40,// lineNo
  "KFDistance",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/KFDistance.m"// pathName 
};

static emlrtRSInfo wdb_emlrtRSI = { 6, // lineNo
  "normalizedDistance",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/normalizedDistance.m"// pathName 
};

static emlrtRSInfo xdb_emlrtRSI = { 7, // lineNo
  "normalizedDistance",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/normalizedDistance.m"// pathName 
};

static emlrtRSInfo ydb_emlrtRSI = { 8, // lineNo
  "normalizedDistance",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/normalizedDistance.m"// pathName 
};

static emlrtRSInfo rfb_emlrtRSI = { 361,// lineNo
  "trackingEKF/likelihood",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo sfb_emlrtRSI = { 362,// lineNo
  "trackingEKF/likelihood",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo tfb_emlrtRSI = { 315,// lineNo
  "trackingEKF/residual",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo ufb_emlrtRSI = { 722,// lineNo
  "ExtendedKalmanFilter/residual",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo vfb_emlrtRSI = { 734,// lineNo
  "ExtendedKalmanFilter/residual",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo wfb_emlrtRSI = { 737,// lineNo
  "ExtendedKalmanFilter/residual",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m"// pathName 
};

static emlrtRSInfo dgb_emlrtRSI = { 19,// lineNo
  "KalmanLikelihood",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/KalmanLikelihood.m"// pathName 
};

static emlrtRSInfo egb_emlrtRSI = { 21,// lineNo
  "KalmanLikelihood",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/KalmanLikelihood.m"// pathName 
};

static emlrtRSInfo sib_emlrtRSI = { 178,// lineNo
  "trackingEKF/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo tib_emlrtRSI = { 184,// lineNo
  "trackingEKF/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo uib_emlrtRSI = { 193,// lineNo
  "trackingEKF/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo vib_emlrtRSI = { 198,// lineNo
  "trackingEKF/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo wib_emlrtRSI = { 203,// lineNo
  "trackingEKF/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo xib_emlrtRSI = { 212,// lineNo
  "trackingEKF/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo yib_emlrtRSI = { 214,// lineNo
  "trackingEKF/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRSInfo ajb_emlrtRSI = { 208,// lineNo
  "trackingEKF/correctjpda",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pathName 
};

static emlrtRTEInfo wc_emlrtRTEI = { 28,// lineNo
  27,                                  // colNo
  "validatele",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatele.m"// pName 
};

static emlrtRTEInfo xc_emlrtRTEI = { 204,// lineNo
  16,                                  // colNo
  "trackingEKF/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m"// pName 
};

static emlrtBCInfo ei_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  193,                                 // lineNo
  64,                                  // colNo
  "",                                  // aName
  "trackingEKF/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo fi_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  185,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "trackingEKF/correctjpda",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackingEKF.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo eb_emlrtECI = { -1, // nDims
  146,                                 // lineNo
  5,                                   // colNo
  "constvel",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pName 
};

static emlrtECInfo fb_emlrtECI = { 2,  // nDims
  146,                                 // lineNo
  23,                                  // colNo
  "constvel",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pName 
};

static emlrtECInfo gb_emlrtECI = { -1, // nDims
  145,                                 // lineNo
  5,                                   // colNo
  "constvel",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pName 
};

static emlrtECInfo hb_emlrtECI = { 2,  // nDims
  145,                                 // lineNo
  25,                                  // colNo
  "constvel",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pName 
};

static emlrtRTEInfo jd_emlrtRTEI = { 130,// lineNo
  27,                                  // colNo
  "constvel",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pName 
};

static emlrtRTEInfo bo_emlrtRTEI = { 126,// lineNo
  9,                                   // colNo
  "constvel",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pName 
};

static emlrtRTEInfo co_emlrtRTEI = { 145,// lineNo
  25,                                  // colNo
  "constvel",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pName 
};

static emlrtRTEInfo do_emlrtRTEI = { 146,// lineNo
  23,                                  // colNo
  "constvel",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constvel.m"// pName 
};

static const int8_T iv1[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

// Function Definitions
namespace coder
{
  void trackingEKF::ExtendedKalmanFilter_residual(const emlrtStack *sp, const
    real_T z[3], real_T res[3], real_T S[9])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T b_obj[36];
    real_T obj[9];
    real_T c_obj[6];
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ufb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    b_st.site = &xfb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if ((!muDoubleScalarIsInf(z[k])) && (!muDoubleScalarIsNaN(z[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:residual:expectedFinite", 3, 4, 1, "z");
    }

    st.site = &vfb_emlrtRSI;
    this->c_validateMeasurementAndRelated(&st);
    memcpy(&obj[0], &this->pSqrtMeasurementNoise[0], 9U * sizeof(real_T));
    for (int32_T i = 0; i < 6; i++) {
      c_obj[i] = this->pState[i];
    }

    memcpy(&b_obj[0], &this->pSqrtStateCovariance[0], 36U * sizeof(real_T));
    st.site = &wfb_emlrtRSI;
    matlabshared::tracking::internal::EKFCorrector::residual(&st, z, obj, c_obj,
      b_obj, res, S);
  }

  void trackingEKF::c_validateMeasurementAndRelated(const emlrtStack *sp)
  {
    emlrtStack b_st;
    emlrtStack st;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &hdb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    if ((!this->pIsSetStateCovariance) || (this->pSqrtStateCovarianceScalar !=
         -1.0)) {
      real_T a;
      a = this->pSqrtStateCovarianceScalar;
      for (int32_T i = 0; i < 36; i++) {
        this->pSqrtStateCovariance[i] = a * static_cast<real_T>(iv1[i]);
      }

      this->pIsSetStateCovariance = true;
      this->pSqrtStateCovarianceScalar = -1.0;
    }

    if (this->pIsFirstCallCorrect) {
      st.site = &idb_emlrtRSI;
      matlabshared::tracking::internal::EKFCorrectorAdditive::
        getNumberOfMandatoryInputs();
      if (!this->pIsValidMeasurementFcn) {
        b_st.site = &ldb_emlrtRSI;
        matlabshared::tracking::internal::EKFCorrectorAdditive::
          validateMeasurementFcn(&b_st, this);
        this->pIsValidMeasurementFcn = true;
      }

      this->pIsFirstCallCorrect = false;
    }

    st.site = &jdb_emlrtRSI;
    this->ensureMeasurementNoiseIsDefined();
  }

  void trackingEKF::ensureMeasurementNoiseIsDefined()
  {
    if ((!this->pIsSetMeasurementNoise) || (this->pSqrtMeasurementNoiseScalar !=
         -1.0)) {
      real_T a;
      a = this->pSqrtMeasurementNoiseScalar;
      for (int32_T i = 0; i < 9; i++) {
        this->pSqrtMeasurementNoise[i] = a * static_cast<real_T>(iv[i]);
      }

      this->pIsSetMeasurementNoise = true;
      this->pSqrtMeasurementNoiseScalar = -1.0;
    }
  }

  void trackingEKF::get_MeasurementNoise(real_T value[9])
  {
    int32_T i;
    if ((!this->pIsSetMeasurementNoise) || (this->pSqrtMeasurementNoiseScalar !=
         -1.0)) {
      real_T a;
      a = this->pSqrtMeasurementNoiseScalar;
      for (i = 0; i < 9; i++) {
        this->pSqrtMeasurementNoise[i] = a * static_cast<real_T>(iv[i]);
      }

      this->pIsSetMeasurementNoise = true;
      this->pSqrtMeasurementNoiseScalar = -1.0;
    }

    for (i = 0; i < 3; i++) {
      for (int32_T i1 = 0; i1 < 3; i1++) {
        value[i + 3 * i1] = (this->pSqrtMeasurementNoise[i] *
                             this->pSqrtMeasurementNoise[i1] +
                             this->pSqrtMeasurementNoise[i + 3] *
                             this->pSqrtMeasurementNoise[i1 + 3]) +
          this->pSqrtMeasurementNoise[i + 6] * this->pSqrtMeasurementNoise[i1 +
          6];
      }
    }
  }

  void trackingEKF::get_ProcessNoise(real_T value[9])
  {
    int32_T i;
    if ((!this->pIsSetProcessNoise) || (this->pSqrtProcessNoiseScalar != -1.0))
    {
      real_T a;
      a = this->pSqrtProcessNoiseScalar;
      for (i = 0; i < 9; i++) {
        this->pSqrtProcessNoise[i] = a * static_cast<real_T>(iv[i]);
      }

      this->pIsSetProcessNoise = true;
      this->pSqrtProcessNoiseScalar = -1.0;
    }

    for (i = 0; i < 3; i++) {
      for (int32_T i1 = 0; i1 < 3; i1++) {
        value[i + 3 * i1] = (this->pSqrtProcessNoise[i] *
                             this->pSqrtProcessNoise[i1] +
                             this->pSqrtProcessNoise[i + 3] *
                             this->pSqrtProcessNoise[i1 + 3]) +
          this->pSqrtProcessNoise[i + 6] * this->pSqrtProcessNoise[i1 + 6];
      }
    }
  }

  trackingEKF *trackingEKF::init()
  {
    trackingEKF *EKF;
    EKF = this;
    EKF->pIsFirstCallPredict = true;
    EKF->pIsFirstCallCorrect = true;
    EKF->pSqrtStateCovarianceScalar = 1.0;
    EKF->pIsValidMeasurementFcn = false;
    EKF->pIsValidStateTransitionFcn = false;
    EKF->pSqrtProcessNoiseScalar = 1.0;
    EKF->pSqrtMeasurementNoiseScalar = 1.0;
    EKF->pHasPrediction = false;
    return EKF;
  }

  void trackingEKF::residual(const emlrtStack *sp, const real_T z[3], real_T
    res[3], real_T S[9])
  {
    emlrtStack st;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &tfb_emlrtRSI;
    this->ExtendedKalmanFilter_residual(&st, z, res, S);
  }

  void trackingEKF::set_MeasurementFcn()
  {
    this->pIsValidMeasurementFcn = false;
  }

  void trackingEKF::set_ProcessNoise(const emlrtStack *sp)
  {
    static const real_T A[9] = { 0.01, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.01
    };

    static const real_T dv[9] = { 0.1, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.1 };

    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T B_data[36];
    int32_T B_size[2];
    int32_T info;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ju_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    b_st.site = &et_emlrtRSI;
    B_size[0] = 3;
    B_size[1] = 3;
    memcpy(&B_data[0], &A[0], 9U * sizeof(real_T));
    c_st.site = &ht_emlrtRSI;
    info = cholesky(&c_st, B_data, B_size);
    if (info == 0) {
      memcpy(&this->pSqrtProcessNoise[0], &dv[0], 9U * sizeof(real_T));
    } else {
      b_st.site = &gt_emlrtRSI;
      matlabshared::tracking::internal::svdPSD(&b_st, A, this->pSqrtProcessNoise);
    }

    st.site = &ku_emlrtRSI;
    this->pIsSetProcessNoise = true;
    this->pSqrtProcessNoiseScalar = -1.0;
  }

  void trackingEKF::set_State(const emlrtStack *sp, const real_T value[6])
  {
    emlrtStack b_st;
    emlrtStack st;
    int32_T i;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &vs_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    b_st.site = &yb_emlrtRSI;
    p = true;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 6)) {
      if ((!muDoubleScalarIsInf(value[i])) && (!muDoubleScalarIsNaN(value[i])))
      {
        i++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ExtendedKalmanFilter:expectedFinite", 3, 4, 5, "State");
    }

    for (i = 0; i < 6; i++) {
      this->pState[i] = value[i];
    }
  }

  void trackingEKF::set_StateCovariance(const emlrtStack *sp, real_T value[36])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    creal_T d[6];
    real_T b_x[36];
    real_T y[36];
    real_T varargin_1[6];
    real_T tol;
    real_T x;
    int32_T a;
    int32_T i1;
    int32_T idx;
    int32_T iy;
    boolean_T b_y[6];
    boolean_T c_y;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ws_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    b_st.site = &yb_emlrtRSI;
    p = true;
    i1 = 0;
    exitg1 = false;
    while ((!exitg1) && (i1 < 36)) {
      if ((!muDoubleScalarIsInf(value[i1])) && (!muDoubleScalarIsNaN(value[i1])))
      {
        i1++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ExtendedKalmanFilter:expectedFinite", 3, 4, 15,
        "StateCovariance");
    }

    st.site = &xs_emlrtRSI;
    b_st.site = &ho_emlrtRSI;
    for (i1 = 0; i1 < 6; i1++) {
      varargin_1[i1] = muDoubleScalarAbs(value[i1 + 6 * i1]);
    }

    c_st.site = &md_emlrtRSI;
    d_st.site = &nd_emlrtRSI;
    if (!muDoubleScalarIsNaN(varargin_1[0])) {
      idx = 1;
    } else {
      idx = 0;
      i1 = 2;
      exitg1 = false;
      while ((!exitg1) && (i1 < 7)) {
        if (!muDoubleScalarIsNaN(varargin_1[i1 - 1])) {
          idx = i1;
          exitg1 = true;
        } else {
          i1++;
        }
      }
    }

    if (idx == 0) {
      tol = varargin_1[0];
    } else {
      tol = varargin_1[idx - 1];
      a = idx + 1;
      for (i1 = a; i1 < 7; i1++) {
        x = varargin_1[i1 - 1];
        if (tol < x) {
          tol = x;
        }
      }
    }

    b_st.site = &ho_emlrtRSI;
    c_st.site = &yd_emlrtRSI;
    if ((!muDoubleScalarIsInf(tol)) && (!muDoubleScalarIsNaN(tol))) {
      if (tol <= 2.2250738585072014E-308) {
        tol = 4.94065645841247E-324;
      } else {
        frexp(tol, &iy);
        tol = ldexp(1.0, iy - 53);
      }
    } else {
      tol = rtNaN;
    }

    tol *= 100.0;
    for (iy = 0; iy < 6; iy++) {
      for (i1 = 0; i1 < 6; i1++) {
        idx = i1 + 6 * iy;
        b_x[idx] = value[idx] - value[iy + 6 * i1];
      }
    }

    for (i1 = 0; i1 < 36; i1++) {
      y[i1] = muDoubleScalarAbs(b_x[i1]);
    }

    b_st.site = &io_emlrtRSI;
    x = muDoubleScalarSqrt(tol);
    b_st.site = &io_emlrtRSI;
    c_st.site = &tj_emlrtRSI;
    for (iy = 0; iy < 6; iy++) {
      b_y[iy] = true;
    }

    idx = 6;
    iy = -1;
    for (int32_T i = 0; i < 6; i++) {
      a = idx;
      i1 = idx - 5;
      idx += 6;
      iy++;
      d_st.site = &uj_emlrtRSI;
      if ((i1 <= a) && (a > 2147483646)) {
        e_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      exitg1 = false;
      while ((!exitg1) && (i1 <= a)) {
        if (!(y[i1 - 1] < x)) {
          b_y[iy] = false;
          exitg1 = true;
        } else {
          i1++;
        }
      }
    }

    p = true;
    i1 = 0;
    exitg1 = false;
    while ((!exitg1) && (i1 <= 5)) {
      if (!b_y[i1]) {
        p = false;
        exitg1 = true;
      } else {
        i1++;
      }
    }

    for (iy = 0; iy < 6; iy++) {
      for (i1 = 0; i1 < 6; i1++) {
        idx = i1 + 6 * iy;
        b_x[idx] = (value[idx] + value[iy + 6 * i1]) / 2.0;
      }
    }

    b_st.site = &jo_emlrtRSI;
    b_eig(&b_st, b_x, d);
    for (iy = 0; iy < 6; iy++) {
      b_y[iy] = (d[iy].re < -tol);
    }

    c_y = false;
    i1 = 0;
    exitg1 = false;
    while ((!exitg1) && (i1 <= 5)) {
      if (!b_y[i1]) {
        i1++;
      } else {
        c_y = true;
        exitg1 = true;
      }
    }

    if (c_y || (!p)) {
      emlrtErrorWithMessageIdR2018a(&st, &qb_emlrtRTEI,
        "shared_tracking:KalmanFilter:invalidCovarianceValues",
        "shared_tracking:KalmanFilter:invalidCovarianceValues", 3, 4, 15,
        "StateCovariance");
    }

    memcpy(&b_x[0], &value[0], 36U * sizeof(real_T));
    st.site = &ys_emlrtRSI;
    matlabshared::tracking::internal::cholPSD(&st, b_x, value);
    st.site = &at_emlrtRSI;
    memcpy(&this->pSqrtStateCovariance[0], &value[0], 36U * sizeof(real_T));
    this->pIsSetStateCovariance = true;
    this->pSqrtStateCovarianceScalar = -1.0;
  }

  void trackingEKF::set_StateTransitionFcn()
  {
    this->pIsValidStateTransitionFcn = false;
  }

  void trackingEKF::anon(const emlrtStack *sp, ::coder::array<real_T, 2U> &state,
    real_T dt)
  {
    array<real_T, 2U> b_state;
    array<real_T, 2U> c_state;
    array<real_T, 2U> r;
    array<int8_T, 2U> wcol;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T a;
    int32_T varargin_2[2];
    int32_T acoef;
    int32_T i;
    int32_T i1;
    int32_T k;
    uint32_T varargin_1[2];
    boolean_T b_p;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &acb_emlrtRSI;
    b_st.site = &ry_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    p = true;
    i = 6 * state.size(1);
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= i - 1)) {
      if ((!muDoubleScalarIsInf(state[k])) && (!muDoubleScalarIsNaN(state[k])))
      {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:constvel:expectedFinite", 3, 4, 22, "input number 1, state,");
    }

    wcol.set_size(&bo_emlrtRTEI, &st, 3, state.size(1));
    acoef = 3 * state.size(1);
    for (i = 0; i < acoef; i++) {
      wcol[i] = 0;
    }

    varargin_1[0] = static_cast<uint32_T>(wcol.size(0));
    varargin_1[1] = static_cast<uint32_T>(wcol.size(1));
    varargin_2[0] = 3;
    varargin_2[1] = state.size(1);
    b_p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (static_cast<int32_T>(varargin_1[k]) != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    p = b_p;
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&st, &jd_emlrtRTEI,
        "shared_tracking:motion:incorrectNoiseDim",
        "shared_tracking:motion:incorrectNoiseDim", 7, 4, 1, "w", 6, 3.0, 6,
        static_cast<real_T>(state.size(1)));
    }

    b_st.site = &sy_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    p = ((!muDoubleScalarIsInf(dt)) && (!muDoubleScalarIsNaN(dt)));
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:constvel:expectedFinite", 3, 4, 19, "input number 3, dt,");
    }

    a = 0.5 * (dt * dt);
    i = wcol.size(1) - 1;
    i1 = wcol.size(1) - 1;
    for (int32_T b_i = 0; b_i < 3; b_i++) {
      int32_T i2;
      i2 = state.size(1);
      b_state.set_size(&wk_emlrtRTEI, &st, 1, i2);
      acoef = (state.size(1) != 1);
      i2--;
      for (k = 0; k <= i2; k++) {
        b_state[k] = state[(((b_i + 1) << 1) + 6 * (acoef * k)) - 1] * dt;
      }

      i2 = (b_i + 1) << 1;
      acoef = state.size(1);
      c_state.set_size(&co_emlrtRTEI, &st, 1, acoef);
      for (k = 0; k < acoef; k++) {
        c_state[k] = state[(i2 + 6 * k) - 2];
      }

      emlrtSizeEqCheckNDR2012b(c_state.size(), b_state.size(), &hb_emlrtECI, &st);
      b_st.site = &ty_emlrtRSI;
      r.set_size(&wk_emlrtRTEI, &st, 1, wcol.size(1));
      for (k = 0; k <= i; k++) {
        r[k] = a * 0.0;
      }

      acoef = state.size(1);
      c_state.set_size(&co_emlrtRTEI, &st, 1, acoef);
      for (k = 0; k < acoef; k++) {
        c_state[k] = state[(i2 + 6 * k) - 2];
      }

      emlrtSizeEqCheckNDR2012b(c_state.size(), r.size(), &hb_emlrtECI, &st);
      acoef = state.size(1);
      c_state.set_size(&co_emlrtRTEI, &st, 1, acoef);
      for (k = 0; k < acoef; k++) {
        c_state[k] = state[(i2 + 6 * k) - 2];
      }

      varargin_2[0] = 1;
      varargin_2[1] = state.size(1);
      emlrtSubAssignSizeCheckR2012b(&varargin_2[0], 2, c_state.size(), 2,
        &gb_emlrtECI, &st);
      acoef = state.size(1) - 1;
      b_state.set_size(&co_emlrtRTEI, &st, 1, acoef + 1);
      for (k = 0; k <= acoef; k++) {
        b_state[k] = (state[(i2 + 6 * k) - 2] + b_state[k]) + r[k];
      }

      acoef = b_state.size(1);
      for (k = 0; k < acoef; k++) {
        state[(i2 + 6 * k) - 2] = b_state[k];
      }

      b_state.set_size(&wk_emlrtRTEI, &st, 1, wcol.size(1));
      for (k = 0; k <= i1; k++) {
        b_state[k] = 0.0 * dt;
      }

      acoef = state.size(1);
      c_state.set_size(&do_emlrtRTEI, &st, 1, acoef);
      for (k = 0; k < acoef; k++) {
        c_state[k] = state[(i2 + 6 * k) - 1];
      }

      emlrtSizeEqCheckNDR2012b(c_state.size(), b_state.size(), &fb_emlrtECI, &st);
      acoef = state.size(1);
      c_state.set_size(&do_emlrtRTEI, &st, 1, acoef);
      for (k = 0; k < acoef; k++) {
        c_state[k] = state[(i2 + 6 * k) - 1];
      }

      varargin_2[0] = 1;
      varargin_2[1] = state.size(1);
      emlrtSubAssignSizeCheckR2012b(&varargin_2[0], 2, c_state.size(), 2,
        &eb_emlrtECI, &st);
      acoef = state.size(1) - 1;
      b_state.set_size(&do_emlrtRTEI, &st, 1, acoef + 1);
      for (k = 0; k <= acoef; k++) {
        b_state[k] = state[(i2 + 6 * k) - 1] + b_state[k];
      }

      acoef = b_state.size(1);
      for (k = 0; k < acoef; k++) {
        state[(i2 + 6 * k) - 1] = b_state[k];
      }
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  trackingEKF *trackingEKF::clone(trackingEKF *iobj_0) const
  {
    trackingEKF *newEKF;
    real_T value[36];
    real_T b_value[9];
    real_T EKF[6];
    int32_T i;
    newEKF = iobj_0->init();
    newEKF->pIsSetStateCovariance = this->pIsSetStateCovariance;
    newEKF->pIsSetProcessNoise = this->pIsSetProcessNoise;
    newEKF->pIsSetMeasurementNoise = this->pIsSetMeasurementNoise;
    for (i = 0; i < 6; i++) {
      EKF[i] = this->pState[i];
    }

    for (i = 0; i < 6; i++) {
      newEKF->pState[i] = EKF[i];
    }

    newEKF->set_StateTransitionFcn();
    newEKF->set_MeasurementFcn();
    for (i = 0; i < 36; i++) {
      value[i] = this->pSqrtStateCovariance[i];
    }

    for (i = 0; i < 36; i++) {
      newEKF->pSqrtStateCovariance[i] = value[i];
    }

    newEKF->pIsSetStateCovariance = true;
    newEKF->pSqrtStateCovarianceScalar = -1.0;
    newEKF->pSqrtStateCovarianceScalar = this->pSqrtStateCovarianceScalar;
    for (i = 0; i < 9; i++) {
      b_value[i] = this->pSqrtProcessNoise[i];
    }

    for (i = 0; i < 9; i++) {
      newEKF->pSqrtProcessNoise[i] = b_value[i];
    }

    newEKF->pIsSetProcessNoise = true;
    newEKF->pSqrtProcessNoiseScalar = -1.0;
    newEKF->pSqrtProcessNoiseScalar = this->pSqrtProcessNoiseScalar;
    for (i = 0; i < 9; i++) {
      b_value[i] = this->pSqrtMeasurementNoise[i];
    }

    for (i = 0; i < 9; i++) {
      newEKF->pSqrtMeasurementNoise[i] = b_value[i];
    }

    newEKF->pIsSetMeasurementNoise = true;
    newEKF->pSqrtMeasurementNoiseScalar = -1.0;
    newEKF->pSqrtMeasurementNoiseScalar = this->pSqrtMeasurementNoiseScalar;
    newEKF->pHasPrediction = this->pHasPrediction;
    newEKF->pIsValidStateTransitionFcn = this->pIsValidStateTransitionFcn;
    newEKF->pIsValidMeasurementFcn = this->pIsValidMeasurementFcn;
    return newEKF;
  }

  void trackingEKF::correctjpda(const emlrtStack *sp, const real_T z[3])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T b_a[36];
    real_T dv2[36];
    real_T value[36];
    real_T a[9];
    real_T c_a[9];
    real_T dv[9];
    real_T dv1[6];
    real_T d;
    int32_T b_i;
    int32_T i;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &sib_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    b_st.site = &yb_emlrtRSI;
    p = true;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      if ((!muDoubleScalarIsInf(z[i])) && (!muDoubleScalarIsNaN(z[i]))) {
        i++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:trackingEKF:expectedFinite", 3, 4, 1, "z");
    }

    st.site = &tib_emlrtRSI;
    matlabshared::tracking::internal::validateInputSizeAndType(&st, z);
    st.site = &uib_emlrtRSI;
    this->c_validateMeasurementAndRelated(&st);
    st.site = &xib_emlrtRSI;
    for (i = 0; i < 9; i++) {
      dv[i] = this->pSqrtMeasurementNoise[i];
    }

    for (i = 0; i < 9; i++) {
      a[i] = this->pSqrtMeasurementNoise[i];
    }

    st.site = &yib_emlrtRSI;
    for (i = 0; i < 36; i++) {
      value[i] = this->pSqrtStateCovariance[i];
    }

    for (i = 0; i < 36; i++) {
      b_a[i] = this->pSqrtStateCovariance[i];
    }

    for (i = 0; i < 6; i++) {
      dv1[i] = this->pState[i];
    }

    for (i = 0; i < 6; i++) {
      for (b_i = 0; b_i < 6; b_i++) {
        d = 0.0;
        for (int32_T i1 = 0; i1 < 6; i1++) {
          d += b_a[i + 6 * i1] * value[b_i + 6 * i1];
        }

        dv2[i + 6 * b_i] = d;
      }
    }

    for (i = 0; i < 3; i++) {
      real_T d1;
      real_T d2;
      d = a[i];
      d1 = a[i + 3];
      d2 = a[i + 6];
      for (b_i = 0; b_i < 3; b_i++) {
        c_a[i + 3 * b_i] = (d * dv[b_i] + d1 * dv[b_i + 3]) + d2 * dv[b_i + 6];
      }
    }

    st.site = &ajb_emlrtRSI;
    matlabshared::tracking::internal::EKFCorrector::correctjpda(&st, z, c_a, dv1,
      dv2);
    for (i = 0; i < 6; i++) {
      this->pState[i] = dv1[i];
    }

    st.site = &ajb_emlrtRSI;
    b_st.site = &xv_emlrtRSI;
    c_st.site = &xv_emlrtRSI;
    matlabshared::tracking::internal::cholPSD(&c_st, dv2, value);
    for (i = 0; i < 36; i++) {
      this->pSqrtStateCovariance[i] = value[i];
    }

    this->pIsSetStateCovariance = true;
    this->pSqrtStateCovarianceScalar = -1.0;
    this->pHasPrediction = false;
  }

  void trackingEKF::correctjpda(const emlrtStack *sp, const ::coder::array<
    real_T, 2U> &z, const ::coder::array<real_T, 1U> &jpda)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T b_a[36];
    real_T dv2[36];
    real_T value[36];
    real_T a[9];
    real_T c_a[9];
    real_T dv[9];
    real_T dv1[6];
    real_T x;
    int32_T b_i;
    int32_T i;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &sib_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    b_st.site = &yb_emlrtRSI;
    p = true;
    i = 3 * z.size(1);
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i <= i - 1)) {
      if ((!muDoubleScalarIsInf(z[b_i])) && (!muDoubleScalarIsNaN(z[b_i]))) {
        b_i++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:trackingEKF:expectedFinite", 3, 4, 1, "z");
    }

    if (1 > z.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, z.size(1), &fi_emlrtBCI, sp);
    }

    st.site = &tib_emlrtRSI;
    matlabshared::tracking::internal::validateInputSizeAndType(&st, *(real_T (*)
      [3])&z[0]);
    if (1 > z.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, z.size(1), &ei_emlrtBCI, sp);
    }

    st.site = &uib_emlrtRSI;
    this->c_validateMeasurementAndRelated(&st);
    st.site = &vib_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    p = true;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i <= jpda.size(0) - 1)) {
      if ((!muDoubleScalarIsInf(jpda[b_i])) && (!muDoubleScalarIsNaN(jpda[b_i])))
      {
        b_i++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:correctjpda:expectedFinite", 3, 4, 4, "jpda");
    }

    b_st.site = &yb_emlrtRSI;
    p = true;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i <= jpda.size(0) - 1)) {
      if (!(jpda[b_i] < 0.0)) {
        b_i++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:correctjpda:expectedNonnegative", 3, 4, 4, "jpda");
    }

    b_st.site = &yb_emlrtRSI;
    if (static_cast<uint32_T>(jpda.size(0)) != z.size(1) + 1U) {
      emlrtErrorWithMessageIdR2018a(&b_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesincorrectNumel",
        "MATLAB:correctjpda:incorrectNumel", 5, 4, 4, "jpda", 6,
        static_cast<real_T>(z.size(1)) + 1.0);
    }

    b_st.site = &yb_emlrtRSI;
    p = true;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i <= jpda.size(0) - 1)) {
      if (jpda[b_i] <= 1.0) {
        b_i++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &wc_emlrtRTEI,
        "MATLAB:validateattributes:expectedArray",
        "MATLAB:correctjpda:notLessEqual", 9, 4, 4, "jpda", 4, 2, "<=", 4, 1,
        "1");
    }

    st.site = &wib_emlrtRSI;
    x = sum(&st, jpda) - 1.0;
    st.site = &wib_emlrtRSI;
    if (muDoubleScalarAbs(x) > 1.4901161193847656E-8) {
      emlrtErrorWithMessageIdR2018a(sp, &xc_emlrtRTEI,
        "shared_tracking:ExtendedKalmanFilter:InvalidJPDAInput",
        "shared_tracking:ExtendedKalmanFilter:InvalidJPDAInput", 3, 4, 4, "jpda");
    }

    st.site = &xib_emlrtRSI;
    for (i = 0; i < 9; i++) {
      dv[i] = this->pSqrtMeasurementNoise[i];
    }

    for (i = 0; i < 9; i++) {
      a[i] = this->pSqrtMeasurementNoise[i];
    }

    st.site = &yib_emlrtRSI;
    for (i = 0; i < 36; i++) {
      value[i] = this->pSqrtStateCovariance[i];
    }

    for (i = 0; i < 36; i++) {
      b_a[i] = this->pSqrtStateCovariance[i];
    }

    for (b_i = 0; b_i < 6; b_i++) {
      dv1[b_i] = this->pState[b_i];
    }

    for (i = 0; i < 6; i++) {
      for (b_i = 0; b_i < 6; b_i++) {
        x = 0.0;
        for (int32_T i1 = 0; i1 < 6; i1++) {
          x += b_a[i + 6 * i1] * value[b_i + 6 * i1];
        }

        dv2[i + 6 * b_i] = x;
      }
    }

    for (i = 0; i < 3; i++) {
      real_T d;
      real_T d1;
      x = a[i];
      d = a[i + 3];
      d1 = a[i + 6];
      for (b_i = 0; b_i < 3; b_i++) {
        c_a[i + 3 * b_i] = (x * dv[b_i] + d * dv[b_i + 3]) + d1 * dv[b_i + 6];
      }
    }

    st.site = &ajb_emlrtRSI;
    matlabshared::tracking::internal::EKFCorrector::correctjpda(&st, z, jpda,
      c_a, dv1, dv2);
    for (b_i = 0; b_i < 6; b_i++) {
      this->pState[b_i] = dv1[b_i];
    }

    st.site = &ajb_emlrtRSI;
    b_st.site = &xv_emlrtRSI;
    c_st.site = &xv_emlrtRSI;
    matlabshared::tracking::internal::cholPSD(&c_st, dv2, value);
    for (i = 0; i < 36; i++) {
      this->pSqrtStateCovariance[i] = value[i];
    }

    this->pIsSetStateCovariance = true;
    this->pSqrtStateCovarianceScalar = -1.0;
    this->pHasPrediction = false;
  }

  real_T trackingEKF::distance(const emlrtStack *sp, const real_T z_matrix[3])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    real_T b[36];
    real_T b_dHdx[18];
    real_T dHdx[18];
    real_T dv[9];
    real_T residualCovariance[9];
    real_T unusedExpr[6];
    real_T Y[3];
    real_T zEstimated[3];
    real_T x;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ddb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    b_st.site = &gdb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if ((!muDoubleScalarIsInf(z_matrix[k])) && (!muDoubleScalarIsNaN
           (z_matrix[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:trackingEKF:expectedFinite", 3, 4, 8, "z_matrix");
    }

    st.site = &edb_emlrtRSI;
    this->c_validateMeasurementAndRelated(&st);
    st.site = &fdb_emlrtRSI;
    b_st.site = &pdb_emlrtRSI;
    this->get_State(unusedExpr);
    b_st.site = &pdb_emlrtRSI;
    cvmeasjac(&b_st, unusedExpr, dHdx);
    b_st.site = &qdb_emlrtRSI;
    this->get_State(unusedExpr);
    b_st.site = &rdb_emlrtRSI;
    this->get_State(unusedExpr);
    b_st.site = &rdb_emlrtRSI;
    cvmeas(&b_st, unusedExpr, zEstimated);
    b_st.site = &sdb_emlrtRSI;
    this->get_StateCovariance(b);
    b_st.site = &sdb_emlrtRSI;
    this->get_MeasurementNoise(dv);
    for (int32_T i = 0; i < 3; i++) {
      int32_T i1;
      for (i1 = 0; i1 < 6; i1++) {
        x = 0.0;
        for (k = 0; k < 6; k++) {
          x += dHdx[i + 3 * k] * b[k + 6 * i1];
        }

        b_dHdx[i + 3 * i1] = x;
      }

      for (i1 = 0; i1 < 3; i1++) {
        x = 0.0;
        for (k = 0; k < 6; k++) {
          x += b_dHdx[i + 3 * k] * dHdx[i1 + 3 * k];
        }

        k = i + 3 * i1;
        residualCovariance[k] = x + dv[k];
      }
    }

    b_st.site = &tdb_emlrtRSI;
    c_st.site = &vdb_emlrtRSI;
    zEstimated[0] = z_matrix[0] - zEstimated[0];
    zEstimated[1] = z_matrix[1] - zEstimated[1];
    zEstimated[2] = z_matrix[2] - zEstimated[2];
    d_st.site = &wdb_emlrtRSI;
    e_st.site = &hcb_emlrtRSI;
    internal::mrdiv(&e_st, zEstimated, residualCovariance, Y);
    d_st.site = &xdb_emlrtRSI;
    x = det(&d_st, residualCovariance);
    d_st.site = &ydb_emlrtRSI;
    if (x < 0.0) {
      emlrtErrorWithMessageIdR2018a(&d_st, &jc_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        3, "log");
    }

    x = muDoubleScalarLog(x);
    return ((Y[0] * zEstimated[0] + Y[1] * zEstimated[1]) + Y[2] * zEstimated[2])
      + x;
  }

  void trackingEKF::get_State(real_T value[6]) const
  {
    for (int32_T i = 0; i < 6; i++) {
      value[i] = this->pState[i];
    }
  }

  void trackingEKF::get_StateCovariance(real_T value[36])
  {
    real_T a;
    int32_T i;
    if ((!this->pIsSetStateCovariance) || (this->pSqrtStateCovarianceScalar !=
         -1.0)) {
      a = this->pSqrtStateCovarianceScalar;
      for (i = 0; i < 36; i++) {
        this->pSqrtStateCovariance[i] = a * static_cast<real_T>(iv1[i]);
      }

      this->pIsSetStateCovariance = true;
      this->pSqrtStateCovarianceScalar = -1.0;
    }

    for (i = 0; i < 6; i++) {
      for (int32_T i1 = 0; i1 < 6; i1++) {
        a = 0.0;
        for (int32_T i2 = 0; i2 < 6; i2++) {
          a += this->pSqrtStateCovariance[i + 6 * i2] *
            this->pSqrtStateCovariance[i1 + 6 * i2];
        }

        value[i + 6 * i1] = a;
      }
    }
  }

  trackingEKF *trackingEKF::init(const emlrtStack *sp, const real_T varargin_3[6],
    const real_T varargin_9[36], const real_T varargin_11[9])
  {
    trackingEKF *EKF;
    emlrtStack b_st;
    emlrtStack st;
    real_T b_varargin_9[36];
    real_T b_varargin_11[9];
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    EKF = this;
    st.site = &ms_emlrtRSI;
    st.site = &ms_emlrtRSI;
    st.site = &ns_emlrtRSI;
    EKF->pIsFirstCallPredict = true;
    EKF->pIsFirstCallCorrect = true;
    b_st.site = &ps_emlrtRSI;
    EKF->set_State(&b_st, varargin_3);
    EKF->pSqrtStateCovarianceScalar = 1.0;
    memcpy(&b_varargin_9[0], &varargin_9[0], 36U * sizeof(real_T));
    b_st.site = &qs_emlrtRSI;
    EKF->set_StateCovariance(&b_st, b_varargin_9);
    EKF->set_StateTransitionFcn();
    EKF->set_MeasurementFcn();
    EKF->pIsValidMeasurementFcn = false;
    EKF->pIsValidStateTransitionFcn = false;
    EKF->pSqrtProcessNoiseScalar = 1.0;
    b_st.site = &ts_emlrtRSI;
    EKF->set_ProcessNoise(&b_st);
    EKF->pSqrtMeasurementNoiseScalar = 1.0;
    memcpy(&b_varargin_11[0], &varargin_11[0], 9U * sizeof(real_T));
    b_st.site = &us_emlrtRSI;
    EKF->set_MeasurementNoise(&b_st, b_varargin_11);
    EKF->pHasPrediction = false;
    return EKF;
  }

  real_T trackingEKF::likelihood(const emlrtStack *sp, const real_T z[3])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T S[9];
    real_T Y[3];
    real_T zres[3];
    real_T x;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &rfb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    this->residual(&st, z, zres, S);
    st.site = &sfb_emlrtRSI;
    b_st.site = &dgb_emlrtRSI;
    c_st.site = &hcb_emlrtRSI;
    internal::mrdiv(&c_st, zres, S, Y);
    b_st.site = &egb_emlrtRSI;
    c_st.site = &egb_emlrtRSI;
    x = det(&c_st, S);
    if (x < 0.0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &ob_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    x = muDoubleScalarSqrt(x);
    return muDoubleScalarMax(muDoubleScalarExp(-((Y[0] * zres[0] + Y[1] * zres[1])
      + Y[2] * zres[2]) / 2.0) / 15.749609945722419 / x, 2.2250738585072014E-308);
  }

  anonymous_function trackingEKF::models()
  {
    anonymous_function stm;
    real_T unusedExpr[6];
    this->get_State(unusedExpr);
    stm.tunableEnvironment[0] = this;
    return stm;
  }

  void trackingEKF::nullify(const emlrtStack *sp)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T b_I[36];
    real_T unusedExpr[6];
    int32_T i;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &vv_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    this->get_State(unusedExpr);
    for (i = 0; i < 6; i++) {
      this->pState[i] = 0.0;
    }

    st.site = &wv_emlrtRSI;
    this->get_State(unusedExpr);
    memset(&b_I[0], 0, 36U * sizeof(real_T));
    for (i = 0; i < 6; i++) {
      b_I[i + 6 * i] = 1.0;
    }

    st.site = &wv_emlrtRSI;
    b_st.site = &xv_emlrtRSI;
    c_st.site = &xv_emlrtRSI;
    matlabshared::tracking::internal::cholPSD(&c_st, b_I,
      this->pSqrtStateCovariance);
    this->pIsSetStateCovariance = true;
    this->pSqrtStateCovarianceScalar = -1.0;
  }

  void trackingEKF::predict(const emlrtStack *sp, real_T varargin_1)
  {
    emlrtStack st;
    real_T dv[36];
    real_T b_obj[9];
    real_T obj[6];
    real_T a;
    int32_T i;
    st.prev = sp;
    st.tls = sp->tls;
    if ((!this->pIsSetStateCovariance) || (this->pSqrtStateCovarianceScalar !=
         -1.0)) {
      a = this->pSqrtStateCovarianceScalar;
      for (i = 0; i < 36; i++) {
        this->pSqrtStateCovariance[i] = a * static_cast<real_T>(iv1[i]);
      }

      this->pIsSetStateCovariance = true;
      this->pSqrtStateCovarianceScalar = -1.0;
    }

    if ((!this->pIsSetProcessNoise) || (this->pSqrtProcessNoiseScalar != -1.0))
    {
      a = this->pSqrtProcessNoiseScalar;
      for (i = 0; i < 9; i++) {
        this->pSqrtProcessNoise[i] = a * static_cast<real_T>(iv[i]);
      }

      this->pIsSetProcessNoise = true;
      this->pSqrtProcessNoiseScalar = -1.0;
    }

    if (this->pIsFirstCallPredict) {
      if (!this->pIsValidStateTransitionFcn) {
        for (int32_T b_i = 0; b_i < 6; b_i++) {
          obj[b_i] = this->pState[b_i];
        }

        st.site = &oy_emlrtRSI;
        matlabshared::tracking::internal::EKFPredictorNonAdditive::
          validateStateTransitionFcn(&st, obj, varargin_1);
        this->pIsValidStateTransitionFcn = true;
      }

      this->pIsFirstCallPredict = false;
    }

    for (i = 0; i < 6; i++) {
      obj[i] = this->pState[i];
    }

    for (i = 0; i < 36; i++) {
      dv[i] = this->pSqrtStateCovariance[i];
    }

    memcpy(&b_obj[0], &this->pSqrtProcessNoise[0], 9U * sizeof(real_T));
    st.site = &py_emlrtRSI;
    matlabshared::tracking::internal::EKFPredictorNonAdditive::predict(&st,
      b_obj, obj, dv, varargin_1);
    for (i = 0; i < 6; i++) {
      this->pState[i] = obj[i];
    }

    for (i = 0; i < 36; i++) {
      this->pSqrtStateCovariance[i] = dv[i];
    }

    this->pIsSetStateCovariance = true;
    this->pSqrtStateCovarianceScalar = -1.0;
    this->pHasPrediction = true;
  }

  void trackingEKF::set_MeasurementNoise(const emlrtStack *sp, real_T value[9])
  {
    emlrtStack b_st;
    emlrtStack st;
    real_T b_value[9];
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &lu_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    b_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if ((!muDoubleScalarIsInf(value[k])) && (!muDoubleScalarIsNaN(value[k])))
      {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ExtendedKalmanFilter:expectedFinite", 3, 4, 16,
        "MeasurementNoise");
    }

    st.site = &mu_emlrtRSI;
    matlabshared::tracking::internal::isSymmetricPositiveSemiDefinite(&st, value);
    memcpy(&b_value[0], &value[0], 9U * sizeof(real_T));
    st.site = &nu_emlrtRSI;
    matlabshared::tracking::internal::b_cholPSD(&st, b_value, value);
    st.site = &ou_emlrtRSI;
    memcpy(&this->pSqrtMeasurementNoise[0], &value[0], 9U * sizeof(real_T));
    this->pIsSetMeasurementNoise = true;
    this->pSqrtMeasurementNoiseScalar = -1.0;
  }

  void trackingEKF::sync(const emlrtStack *sp, trackingEKF *EKF2)
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T b_value[36];
    real_T value[36];
    real_T c_value[9];
    real_T d_value[9];
    real_T dv[6];
    int32_T i1;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &jw_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    EKF2->get_State(dv);
    for (int32_T i = 0; i < 6; i++) {
      this->pState[i] = dv[i];
    }

    st.site = &kw_emlrtRSI;
    b_st.site = &kw_emlrtRSI;
    EKF2->get_StateCovariance(value);
    b_st.site = &xv_emlrtRSI;
    c_st.site = &xv_emlrtRSI;
    matlabshared::tracking::internal::cholPSD(&c_st, value, b_value);
    for (i1 = 0; i1 < 36; i1++) {
      this->pSqrtStateCovariance[i1] = b_value[i1];
    }

    this->pIsSetStateCovariance = true;
    this->pSqrtStateCovarianceScalar = -1.0;
    st.site = &lw_emlrtRSI;
    b_st.site = &lw_emlrtRSI;
    EKF2->get_MeasurementNoise(c_value);
    b_st.site = &tw_emlrtRSI;
    c_st.site = &tw_emlrtRSI;
    matlabshared::tracking::internal::b_cholPSD(&c_st, c_value, d_value);
    for (i1 = 0; i1 < 9; i1++) {
      this->pSqrtMeasurementNoise[i1] = d_value[i1];
    }

    this->pIsSetMeasurementNoise = true;
    this->pSqrtMeasurementNoiseScalar = -1.0;
    st.site = &mw_emlrtRSI;
    b_st.site = &mw_emlrtRSI;
    EKF2->get_ProcessNoise(c_value);
    b_st.site = &xw_emlrtRSI;
    c_st.site = &xw_emlrtRSI;
    matlabshared::tracking::internal::b_cholPSD(&c_st, c_value, d_value);
    for (i1 = 0; i1 < 9; i1++) {
      this->pSqrtProcessNoise[i1] = d_value[i1];
    }

    this->pIsSetProcessNoise = true;
    this->pSqrtProcessNoiseScalar = -1.0;
  }
}

// End of code generation (trackingEKF.cpp)
