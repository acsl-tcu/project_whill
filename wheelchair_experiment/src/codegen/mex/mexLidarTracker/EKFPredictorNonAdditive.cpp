//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EKFPredictorNonAdditive.cpp
//
//  Code generation for function 'EKFPredictorNonAdditive'
//


// Include files
#include "EKFPredictorNonAdditive.h"
#include "constvel.h"
#include "mexLidarTracker_data.h"
#include "qrFactor.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo qy_emlrtRSI = { 13, // lineNo
  "EKFPredictorNonAdditive/validateStateTransitionFcn",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m"// pathName 
};

static emlrtRSInfo uy_emlrtRSI = { 68, // lineNo
  "EKFPredictorNonAdditive/predict",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m"// pathName 
};

static emlrtRSInfo vy_emlrtRSI = { 72, // lineNo
  "EKFPredictorNonAdditive/predict",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m"// pathName 
};

static emlrtRSInfo wy_emlrtRSI = { 73, // lineNo
  "EKFPredictorNonAdditive/predict",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m"// pathName 
};

static emlrtRSInfo xy_emlrtRSI = { 54, // lineNo
  "constveljac",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constveljac.m"// pathName 
};

static emlrtRSInfo yy_emlrtRSI = { 67, // lineNo
  "constveljac",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constveljac.m"// pathName 
};

static emlrtRSInfo aab_emlrtRSI = { 73,// lineNo
  "constveljac",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/constveljac.m"// pathName 
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
        void EKFPredictorNonAdditive::predict(const emlrtStack *sp, const real_T
          Qs[9], real_T x[6], real_T S[36], real_T varargin_1)
        {
          emlrtStack b_st;
          emlrtStack c_st;
          emlrtStack st;
          real_T dFdx[36];
          real_T b_dFdw[18];
          real_T dFdw[18];
          real_T B_idx_0;
          int32_T k;
          boolean_T exitg1;
          boolean_T p;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &uy_emlrtRSI;
          b_st.prev = &st;
          b_st.tls = st.tls;
          c_st.prev = &b_st;
          c_st.tls = b_st.tls;
          b_st.site = &xy_emlrtRSI;
          c_st.site = &yb_emlrtRSI;
          p = true;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 6)) {
            if ((!muDoubleScalarIsInf(x[k])) && (!muDoubleScalarIsNaN(x[k]))) {
              k++;
            } else {
              p = false;
              exitg1 = true;
            }
          }

          if (!p) {
            emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedFinite",
              "MATLAB:constveljac:expectedFinite", 3, 4, 22,
              "input number 1, state,");
          }

          b_st.site = &yy_emlrtRSI;
          c_st.site = &yb_emlrtRSI;
          p = ((!muDoubleScalarIsInf(varargin_1)) && (!muDoubleScalarIsNaN
                (varargin_1)));
          if (!p) {
            emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedFinite",
              "MATLAB:constveljac:expectedFinite", 3, 4, 19,
              "input number 3, dt,");
          }

          b_st.site = &aab_emlrtRSI;
          B_idx_0 = varargin_1 * varargin_1 / 2.0;
          memset(&dFdx[0], 0, 36U * sizeof(real_T));
          dFdx[0] = 1.0;
          dFdx[14] = 1.0;
          dFdx[28] = 1.0;
          dFdx[1] = 0.0;
          dFdx[15] = 0.0;
          dFdx[29] = 0.0;
          dFdx[6] = varargin_1;
          dFdx[20] = varargin_1;
          dFdx[34] = varargin_1;
          dFdx[7] = 1.0;
          dFdx[21] = 1.0;
          dFdx[35] = 1.0;
          memset(&dFdw[0], 0, 18U * sizeof(real_T));
          dFdw[0] = B_idx_0;
          dFdw[8] = B_idx_0;
          dFdw[16] = B_idx_0;
          dFdw[1] = varargin_1;
          dFdw[9] = varargin_1;
          dFdw[17] = varargin_1;
          st.site = &vy_emlrtRSI;
          constvel(&st, x, varargin_1);
          for (k = 0; k < 6; k++) {
            real_T d;
            real_T d1;
            B_idx_0 = dFdw[k];
            d = dFdw[k + 6];
            d1 = dFdw[k + 12];
            for (int32_T i = 0; i < 3; i++) {
              b_dFdw[k + 6 * i] = (B_idx_0 * Qs[3 * i] + d * Qs[3 * i + 1]) + d1
                * Qs[3 * i + 2];
            }
          }

          st.site = &wy_emlrtRSI;
          qrFactor(&st, dFdx, S, b_dFdw);
        }

        void EKFPredictorNonAdditive::validateStateTransitionFcn(const
          emlrtStack *sp, const real_T x[6], real_T varargin_1)
        {
          emlrtStack st;
          real_T dv[6];
          st.prev = sp;
          st.tls = sp->tls;
          for (int32_T i = 0; i < 6; i++) {
            dv[i] = x[i];
          }

          st.site = &qy_emlrtRSI;
          constvel(&st, dv, varargin_1);
        }
      }
    }
  }
}

// End of code generation (EKFPredictorNonAdditive.cpp)
