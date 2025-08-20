//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  planeModel.cpp
//
//  Code generation for function 'planeModel'
//


// Include files
#include "planeModel.h"
#include "all.h"
#include "indexShapeCheck.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo pl_emlrtRSI = { 40, // lineNo
  "planeModel/planeModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/planeModel.m"// pathName
};

static emlrtRSInfo ql_emlrtRSI = { 45, // lineNo
  "planeModel/planeModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/planeModel.m"// pathName
};

static emlrtRSInfo rl_emlrtRSI = { 48, // lineNo
  "planeModel/planeModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/planeModel.m"// pathName
};

static emlrtRSInfo sl_emlrtRSI = { 49, // lineNo
  "planeModel/planeModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/planeModel.m"// pathName
};

static emlrtRTEInfo hb_emlrtRTEI = { 13,// lineNo
  37,                                  // colNo
  "validatevector",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatevector.m"// pName 
};

static emlrtBCInfo y_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  47,                                  // colNo
  "",                                  // aName
  "planeModel/planeModel",             // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/planeModel.m",// pName
  0                                    // checkKind
};

// Function Definitions
namespace coder
{
  planeModel *planeModel::init(const emlrtStack *sp, const real32_T params_data[],
    const int32_T params_size[2])
  {
    planeModel *this_;
    array<boolean_T, 1U> b_params_data;
    emlrtStack b_st;
    emlrtStack st;
    int32_T k;
    int32_T params_idx_0;
    boolean_T c_params_data[4];
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    this_ = this;
    st.site = &pl_emlrtRSI;
    st.site = &ql_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    p = true;
    params_idx_0 = params_size[0] * params_size[1];
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= params_idx_0 - 1)) {
      if ((!muSingleScalarIsInf(params_data[k])) && (!muSingleScalarIsNaN
           (params_data[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:planeModel:expectedFinite", 3, 4, 6, "params");
    }

    b_st.site = &yb_emlrtRSI;
    if ((params_size[0] != 1) && (params_size[1] != 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &hb_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedVector",
        "MATLAB:planeModel:expectedVector", 3, 4, 6, "params");
    }

    b_st.site = &yb_emlrtRSI;
    if (params_idx_0 != 4) {
      emlrtErrorWithMessageIdR2018a(&b_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesincorrectNumel",
        "MATLAB:planeModel:incorrectNumel", 5, 4, 6, "params", 6, 4.0);
    }

    for (k = 0; k < params_idx_0; k++) {
      c_params_data[k] = (params_data[k] == 0.0F);
    }

    b_params_data.set(&c_params_data[0], params_idx_0);
    st.site = &rl_emlrtRSI;
    if (!all(&st, b_params_data)) {
      boolean_T b_p;
      st.site = &sl_emlrtRSI;
      internal::indexShapeCheck(&st, params_size);
      if (1 > params_idx_0) {
        emlrtDynamicBoundsCheckR2012b(1, 1, params_idx_0, &y_emlrtBCI, sp);
      }

      if (2 > params_idx_0) {
        emlrtDynamicBoundsCheckR2012b(2, 1, 1, &y_emlrtBCI, sp);
      }

      if (3 > params_idx_0) {
        emlrtDynamicBoundsCheckR2012b(3, 1, 2, &y_emlrtBCI, sp);
      }

      p = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if ((params_data[k] == 0.0F) || muSingleScalarIsNaN(params_data[k])) {
          k++;
        } else {
          p = true;
          exitg1 = true;
        }
      }

      st.site = &sl_emlrtRSI;
      b_st.site = &yb_emlrtRSI;
      b_p = p;
      if (!b_p) {
        emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
          "Coder:toolbox:ValidateattributesexpectedNonZero",
          "MATLAB:planeModel:expectedNonZero", 3, 4, 20, "Normal, params(1:3),");
      }
    }

    return this_;
  }
}

// End of code generation (planeModel.cpp)
