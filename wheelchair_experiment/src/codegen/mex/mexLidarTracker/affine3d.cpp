//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  affine3d.cpp
//
//  Code generation for function 'affine3d'
//


// Include files
#include "affine3d.h"
#include "det.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo me_emlrtRSI = { 128,// lineNo
  "affine3d/affine3d",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/affine3d.m"// pathName
};

static emlrtRSInfo ne_emlrtRSI = { 331,// lineNo
  "affine3d/set.T",                    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/affine3d.m"// pathName
};

static emlrtRSInfo oe_emlrtRSI = { 336,// lineNo
  "affine3d/set.T",                    // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/affine3d.m"// pathName
};

static emlrtRTEInfo fd_emlrtRTEI = { 337,// lineNo
  17,                                  // colNo
  "affine3d/set.T",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/affine3d.m"// pName
};

static emlrtRTEInfo gd_emlrtRTEI = { 342,// lineNo
  17,                                  // colNo
  "affine3d/set.T",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/affine3d.m"// pName
};

// Function Definitions
namespace coder
{
  void affine3d::set_T(const emlrtStack *sp, const real_T b_T[16])
  {
    static const int8_T varargin_2[4] = { 0, 0, 0, 1 };

    emlrtStack b_st;
    emlrtStack st;
    real_T x1;
    int32_T k;
    boolean_T b_p;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ne_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    b_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 16)) {
      if ((!muDoubleScalarIsInf(b_T[k])) && (!muDoubleScalarIsNaN(b_T[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:affine3d:set:T:expectedFinite", 3, 4, 1, "T");
    }

    b_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 16)) {
      if (!muDoubleScalarIsNaN(b_T[k])) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &u_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:affine3d:set:T:expectedNonNaN", 3, 4, 1, "T");
    }

    st.site = &oe_emlrtRSI;
    x1 = b_det(&st, b_T);
    p = (x1 == 0.0);
    if (p) {
      emlrtErrorWithMessageIdR2018a(sp, &fd_emlrtRTEI,
        "images:geotrans:singularTransformationMatrix",
        "images:geotrans:singularTransformationMatrix", 0);
    }

    b_p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(b_T[k + 12] == varargin_2[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    p = b_p;
    if (!p) {
      emlrtErrorWithMessageIdR2018a(sp, &gd_emlrtRTEI,
        "images:geotrans:invalidAffineMatrix",
        "images:geotrans:invalidAffineMatrix", 0);
    }

    memcpy(&this->T[0], &b_T[0], 16U * sizeof(real_T));
  }

  void affine3d::init(const emlrtStack *sp, const real_T A[16])
  {
    emlrtStack st;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &me_emlrtRSI;
    this->set_T(&st, A);
  }
}

// End of code generation (affine3d.cpp)
