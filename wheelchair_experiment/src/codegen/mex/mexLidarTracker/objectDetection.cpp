//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  objectDetection.cpp
//
//  Code generation for function 'objectDetection'
//


// Include files
#include "objectDetection.h"
#include "isSymmetricPositiveSemiDefinite.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo yn_emlrtRSI = { 149,// lineNo
  "objectDetection/objectDetection",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/objectDetection.m"// pathName 
};

static emlrtRSInfo ao_emlrtRSI = { 258,// lineNo
  "objectDetection/setProperties",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/objectDetection.m"// pathName 
};

static emlrtRSInfo bo_emlrtRSI = { 259,// lineNo
  "objectDetection/setProperties",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/objectDetection.m"// pathName 
};

static emlrtRSInfo co_emlrtRSI = { 260,// lineNo
  "objectDetection/setProperties",     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/objectDetection.m"// pathName 
};

static emlrtRSInfo do_emlrtRSI = { 166,// lineNo
  "objectDetection/set.Measurement",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/objectDetection.m"// pathName 
};

static emlrtRSInfo eo_emlrtRSI = { 157,// lineNo
  "objectDetection/set.Time",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/objectDetection.m"// pathName 
};

static emlrtRSInfo fo_emlrtRSI = { 195,// lineNo
  "objectDetection/set.MeasurementNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/objectDetection.m"// pathName 
};

static emlrtRSInfo go_emlrtRSI = { 209,// lineNo
  "objectDetection/set.MeasurementNoise",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/objectDetection.m"// pathName 
};

// Function Definitions
namespace coder
{
  void objectDetection::set_Measurement(const emlrtStack *sp, const real_T
    value[3])
  {
    emlrtStack b_st;
    emlrtStack st;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &do_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    b_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
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
        "MATLAB:objectDetection:expectedFinite", 3, 4, 11, "Measurement");
    }

    this->Measurement[0] = value[0];
    this->Measurement[1] = value[1];
    this->Measurement[2] = value[2];
  }

  void objectDetection::set_MeasurementNoise(const emlrtStack *sp, const real_T
    value[9])
  {
    emlrtStack b_st;
    emlrtStack st;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &fo_emlrtRSI;
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
        "MATLAB:objectDetection:expectedFinite", 3, 4, 16, "MeasurementNoise");
    }

    st.site = &go_emlrtRSI;
    matlabshared::tracking::internal::isSymmetricPositiveSemiDefinite(&st, value);
    memcpy(&this->pMeasurementNoise[0], &value[0], 9U * sizeof(real_T));
  }

  void objectDetection::set_ObjectClassID()
  {
    this->ObjectClassID = 0.0;
  }

  void objectDetection::set_SensorIndex()
  {
    this->SensorIndex = 1.0;
  }

  void objectDetection::get_MeasurementNoise(real_T value[9]) const
  {
    memcpy(&value[0], &this->pMeasurementNoise[0], 9U * sizeof(real_T));
  }

  void objectDetection::init(const emlrtStack *sp, real_T varargin_1, const
    real_T varargin_2[3], const real_T varargin_4[9])
  {
    emlrtStack b_st;
    emlrtStack st;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &yn_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    b_st.site = &ao_emlrtRSI;
    this->set_Measurement(&b_st, varargin_2);
    b_st.site = &bo_emlrtRSI;
    this->set_Time(&b_st, varargin_1);
    b_st.site = &co_emlrtRSI;
    this->set_MeasurementNoise(&b_st, varargin_4);
    this->set_SensorIndex();
    this->set_ObjectClassID();
  }

  void objectDetection::set_Time(const emlrtStack *sp, real_T value)
  {
    emlrtStack b_st;
    emlrtStack st;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &eo_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    b_st.site = &yb_emlrtRSI;
    p = ((!muDoubleScalarIsInf(value)) && (!muDoubleScalarIsNaN(value)));
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:objectDetection:expectedFinite", 3, 4, 4, "Time");
    }

    b_st.site = &yb_emlrtRSI;
    p = !(value < 0.0);
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:objectDetection:expectedNonnegative", 3, 4, 4, "Time");
    }

    this->Time = value;
  }
}

// End of code generation (objectDetection.cpp)
