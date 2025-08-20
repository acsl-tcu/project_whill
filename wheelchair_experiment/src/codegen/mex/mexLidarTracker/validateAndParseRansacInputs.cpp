//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  validateAndParseRansacInputs.cpp
//
//  Code generation for function 'validateAndParseRansacInputs'
//


// Include files
#include "validateAndParseRansacInputs.h"
#include "mexLidarTracker_data.h"
#include "pointCloud.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo yh_emlrtRSI = { 18, // lineNo
  "validateAndParseRansacInputs",      // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRSInfo ai_emlrtRSI = { 77, // lineNo
  "parseAndValidateArgsCodegen",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRSInfo bi_emlrtRSI = { 114,// lineNo
  "parseAndValidateArgsCodegen",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRSInfo ci_emlrtRSI = { 115,// lineNo
  "parseAndValidateArgsCodegen",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRSInfo di_emlrtRSI = { 160,// lineNo
  "parseAndValidateArgsCodegen",       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRSInfo ei_emlrtRSI = { 176,// lineNo
  "checkMaxDistance",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRSInfo fi_emlrtRSI = { 182,// lineNo
  "checkReferenceVector",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRSInfo gi_emlrtRSI = { 184,// lineNo
  "checkReferenceVector",              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRSInfo hi_emlrtRSI = { 190,// lineNo
  "checkMaxAngularDistance",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRSInfo ii_emlrtRSI = { 209,// lineNo
  "checkSampleIndices",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pathName 
};

static emlrtRTEInfo fg_emlrtRTEI = { 26,// lineNo
  1,                                   // colNo
  "validateAndParseRansacInputs",      // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/validateAndParseRansacInputs.m"// pName 
};

// Function Definitions
namespace coder
{
  namespace vision
  {
    namespace internal
    {
      namespace ransac
      {
        void validateAndParseRansacInputs(const emlrtStack *sp, b_pointCloud
          *varargin_1, real_T varargin_2, const real_T varargin_3[3], real_T
          varargin_4, const ::coder::array<uint32_T, 1U> &varargin_6,
          b_pointCloud **ptCloud, real_T *ransacParams_maxDistance, real_T
          *ransacParams_maxNumTrials, real_T *ransacParams_confidence, ::coder::
          array<real_T, 2U> &sampleIndices, real_T referenceVector_data[],
          int32_T referenceVector_size[2], real_T *maxAngularDistance)
        {
          emlrtStack b_st;
          emlrtStack c_st;
          emlrtStack d_st;
          emlrtStack st;
          int32_T k;
          boolean_T b_p;
          boolean_T exitg1;
          boolean_T p;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &yh_emlrtRSI;
          b_st.prev = &st;
          b_st.tls = st.tls;
          c_st.prev = &b_st;
          c_st.tls = b_st.tls;
          d_st.prev = &c_st;
          d_st.tls = c_st.tls;
          b_st.site = &ai_emlrtRSI;
          c_st.site = &ei_emlrtRSI;
          d_st.site = &yb_emlrtRSI;
          p = muDoubleScalarIsNaN(varargin_2);
          b_p = !p;
          if (!b_p) {
            emlrtErrorWithMessageIdR2018a(&d_st, &u_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedNonNaN",
              "MATLAB:pcfitplane:expectedNonNaN", 3, 4, 11, "maxDistance");
          }

          d_st.site = &yb_emlrtRSI;
          b_p = ((!muDoubleScalarIsInf(varargin_2)) && (!p));
          if (!b_p) {
            emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedFinite",
              "MATLAB:pcfitplane:expectedFinite", 3, 4, 11, "maxDistance");
          }

          d_st.site = &yb_emlrtRSI;
          b_p = !(varargin_2 < 0.0);
          if (!b_p) {
            emlrtErrorWithMessageIdR2018a(&d_st, &w_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedNonnegative",
              "MATLAB:pcfitplane:expectedNonnegative", 3, 4, 11, "maxDistance");
          }

          b_st.site = &bi_emlrtRSI;
          c_st.site = &fi_emlrtRSI;
          d_st.site = &yb_emlrtRSI;
          b_p = true;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 3)) {
            if (!muDoubleScalarIsNaN(varargin_3[k])) {
              k++;
            } else {
              b_p = false;
              exitg1 = true;
            }
          }

          if (!b_p) {
            emlrtErrorWithMessageIdR2018a(&d_st, &u_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedNonNaN",
              "MATLAB:pcfitplane:expectedNonNaN", 3, 4, 15, "referenceVector");
          }

          d_st.site = &yb_emlrtRSI;
          b_p = true;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 3)) {
            if ((!muDoubleScalarIsInf(varargin_3[k])) && (!muDoubleScalarIsNaN
                 (varargin_3[k]))) {
              k++;
            } else {
              b_p = false;
              exitg1 = true;
            }
          }

          if (!b_p) {
            emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedFinite",
              "MATLAB:pcfitplane:expectedFinite", 3, 4, 15, "referenceVector");
          }

          b_p = false;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 3)) {
            if ((varargin_3[k] == 0.0) || muDoubleScalarIsNaN(varargin_3[k])) {
              k++;
            } else {
              b_p = true;
              exitg1 = true;
            }
          }

          c_st.site = &gi_emlrtRSI;
          d_st.site = &yb_emlrtRSI;
          p = b_p;
          if (!p) {
            emlrtErrorWithMessageIdR2018a(&d_st, &x_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedNonZero",
              "MATLAB:pcfitplane:expectedNonZero", 3, 4, 15, "referenceVector");
          }

          b_st.site = &ci_emlrtRSI;
          c_st.site = &hi_emlrtRSI;
          d_st.site = &yb_emlrtRSI;
          p = muDoubleScalarIsNaN(varargin_4);
          b_p = !p;
          if (!b_p) {
            emlrtErrorWithMessageIdR2018a(&d_st, &u_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedNonNaN",
              "MATLAB:pcfitplane:expectedNonNaN", 3, 4, 18, "maxAngularDistance");
          }

          d_st.site = &yb_emlrtRSI;
          b_p = ((!muDoubleScalarIsInf(varargin_4)) && (!p));
          if (!b_p) {
            emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedFinite",
              "MATLAB:pcfitplane:expectedFinite", 3, 4, 18, "maxAngularDistance");
          }

          d_st.site = &yb_emlrtRSI;
          b_p = !(varargin_4 < 0.0);
          if (!b_p) {
            emlrtErrorWithMessageIdR2018a(&d_st, &w_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedNonnegative",
              "MATLAB:pcfitplane:expectedNonnegative", 3, 4, 18,
              "maxAngularDistance");
          }

          b_st.site = &di_emlrtRSI;
          if (varargin_6.size(0) != 0) {
            c_st.site = &ii_emlrtRSI;
            d_st.site = &yb_emlrtRSI;
            b_p = true;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k <= varargin_6.size(0) - 1)) {
              if (varargin_6[k] > 0U) {
                k++;
              } else {
                b_p = false;
                exitg1 = true;
              }
            }

            if (!b_p) {
              emlrtErrorWithMessageIdR2018a(&d_st, &y_emlrtRTEI,
                "Coder:toolbox:ValidateattributesexpectedPositive",
                "MATLAB:pcfitplane:expectedPositive", 3, 4, 13, "SampleIndices");
            }
          }

          *ptCloud = varargin_1;
          sampleIndices.set_size(&fg_emlrtRTEI, sp, varargin_6.size(0), 1);
          k = varargin_6.size(0);
          for (int32_T i = 0; i < k; i++) {
            sampleIndices[i] = varargin_6[i];
          }

          referenceVector_size[0] = 1;
          referenceVector_size[1] = 3;
          referenceVector_data[0] = varargin_3[0];
          referenceVector_data[1] = varargin_3[1];
          referenceVector_data[2] = varargin_3[2];
          *ransacParams_maxDistance = varargin_2;
          *ransacParams_maxNumTrials = 1000.0;
          *ransacParams_confidence = 99.0;
          *maxAngularDistance = varargin_4 * 3.1415926535897931 / 180.0;
        }
      }
    }
  }
}

// End of code generation (validateAndParseRansacInputs.cpp)
