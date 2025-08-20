//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rigid3d.cpp
//
//  Code generation for function 'rigid3d'
//


// Include files
#include "rigid3d.h"
#include "affine3d.h"
#include "det.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "mwmathutil.h"
#include <math.h>
#include <string.h>

// Variable Definitions
static emlrtRSInfo tb_emlrtRSI = { 132,// lineNo
  "rigid3d/rigid3d",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pathName
};

static emlrtRSInfo ub_emlrtRSI = { 133,// lineNo
  "rigid3d/rigid3d",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pathName
};

static emlrtRSInfo vb_emlrtRSI = { 138,// lineNo
  "rigid3d/rigid3d",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pathName
};

static emlrtRSInfo wb_emlrtRSI = { 142,// lineNo
  "rigid3d/rigid3d",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pathName
};

static emlrtRSInfo xb_emlrtRSI = { 420,// lineNo
  "validateRotationMatrix",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pathName
};

static emlrtRSInfo ac_emlrtRSI = { 427,// lineNo
  "validateTranslationVector",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pathName
};

static emlrtRSInfo bc_emlrtRSI = { 381,// lineNo
  "rigid3d/isTransformationMatrixRigid",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pathName
};

static emlrtRSInfo cc_emlrtRSI = { 383,// lineNo
  "rigid3d/isTransformationMatrixRigid",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pathName
};

static emlrtRSInfo dc_emlrtRSI = { 384,// lineNo
  "rigid3d/isTransformationMatrixRigid",// fcnName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pathName
};

static emlrtRTEInfo k_emlrtRTEI = { 139,// lineNo
  21,                                  // colNo
  "rigid3d/rigid3d",                   // fName
  "/usr/local/MATLAB/R2020b/toolbox/images/images/rigid3d.m"// pName
};

// Function Definitions
namespace coder
{
  void rigid3d::get_T(real_T T[16]) const
  {
    memcpy(&T[0], &this->AffineTform.T[0], 16U * sizeof(real_T));
  }

  void rigid3d::init(const emlrtStack *sp, const real_T varargin_1[9], const
                     real_T varargin_2[3])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T T[16];
    real_T b_T[9];
    real_T singularValues[3];
    real_T absx;
    real_T b_ex;
    real_T c_ex;
    real_T ex;
    int32_T exponent;
    int32_T idx;
    int32_T k;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &tb_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if ((!muDoubleScalarIsInf(varargin_1[k])) && (!muDoubleScalarIsNaN
           (varargin_1[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rigid3d:expectedFinite", 3, 4, 3, "rot");
    }

    st.site = &ub_emlrtRSI;
    b_st.site = &ac_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if ((!muDoubleScalarIsInf(varargin_2[k])) && (!muDoubleScalarIsNaN
           (varargin_2[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rigid3d:expectedFinite", 3, 4, 5, "trans");
    }

    for (k = 0; k < 3; k++) {
      idx = k << 2;
      T[idx] = varargin_1[3 * k];
      T[idx + 1] = varargin_1[3 * k + 1];
      T[idx + 2] = varargin_1[3 * k + 2];
      T[k + 12] = 0.0;
      T[idx + 3] = varargin_2[k];
    }

    T[15] = 1.0;
    st.site = &vb_emlrtRSI;
    for (k = 0; k < 3; k++) {
      idx = k << 2;
      b_T[3 * k] = T[idx];
      b_T[3 * k + 1] = T[idx + 1];
      b_T[3 * k + 2] = T[idx + 2];
    }

    b_st.site = &bc_emlrtRSI;
    svd(&b_st, b_T, singularValues);
    b_st.site = &cc_emlrtRSI;
    p = muDoubleScalarIsNaN(singularValues[0]);
    if (!p) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(singularValues[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = singularValues[0];
    } else {
      ex = singularValues[idx - 1];
      idx++;
      for (k = idx; k < 4; k++) {
        absx = singularValues[k - 1];
        if (ex < absx) {
          ex = absx;
        }
      }
    }

    b_st.site = &cc_emlrtRSI;
    if (!p) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(singularValues[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      b_ex = singularValues[0];
    } else {
      b_ex = singularValues[idx - 1];
      idx++;
      for (k = idx; k < 4; k++) {
        absx = singularValues[k - 1];
        if (b_ex > absx) {
          b_ex = absx;
        }
      }
    }

    b_st.site = &cc_emlrtRSI;
    if (!p) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(singularValues[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      c_ex = singularValues[0];
    } else {
      c_ex = singularValues[idx - 1];
      idx++;
      for (k = idx; k < 4; k++) {
        absx = singularValues[k - 1];
        if (c_ex < absx) {
          c_ex = absx;
        }
      }
    }

    b_st.site = &cc_emlrtRSI;
    absx = muDoubleScalarAbs(c_ex);
    if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = ldexp(1.0, exponent - 53);
      }
    } else {
      absx = rtNaN;
    }

    if (ex - b_ex < 1000.0 * absx) {
      for (k = 0; k < 3; k++) {
        idx = k << 2;
        b_T[3 * k] = T[idx];
        b_T[3 * k + 1] = T[idx + 1];
        b_T[3 * k + 2] = T[idx + 2];
      }

      b_st.site = &dc_emlrtRSI;
      absx = det(&b_st, b_T) - 1.0;
      if (muDoubleScalarAbs(absx) < 2.2204460492503131E-13) {
        p = true;
      } else {
        p = false;
      }
    } else {
      p = false;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(sp, &k_emlrtRTEI,
        "images:geotrans:invalidRigidMatrix",
        "images:geotrans:invalidRigidMatrix", 0);
    }

    st.site = &wb_emlrtRSI;
    this->AffineTform.init(&st, T);
  }
}

// End of code generation (rigid3d.cpp)
