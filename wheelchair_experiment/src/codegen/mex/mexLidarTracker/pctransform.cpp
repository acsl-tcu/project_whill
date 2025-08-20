//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pctransform.cpp
//
//  Code generation for function 'pctransform'
//


// Include files
#include "pctransform.h"
#include "det.h"
#include "mexLidarTracker_data.h"
#include "pointCloud.h"
#include "rigid3d.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <math.h>

// Variable Definitions
static emlrtRSInfo pe_emlrtRSI = { 115,// lineNo
  "pctransform",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pathName
};

static emlrtRSInfo qe_emlrtRSI = { 117,// lineNo
  "pctransform",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pathName
};

static emlrtRSInfo re_emlrtRSI = { 123,// lineNo
  "pctransform",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pathName
};

static emlrtRSInfo se_emlrtRSI = { 127,// lineNo
  "pctransform",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pathName
};

static emlrtRSInfo te_emlrtRSI = { 131,// lineNo
  "pctransform",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pathName
};

static emlrtRSInfo ue_emlrtRSI = { 10, // lineNo
  "isRigidTransform",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/isRigidTransform.m"// pathName 
};

static emlrtRSInfo we_emlrtRSI = { 12, // lineNo
  "isRigidTransform",                  // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/isRigidTransform.m"// pathName 
};

static emlrtECInfo f_emlrtECI = { -1,  // nDims
  92,                                  // lineNo
  9,                                   // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtECInfo g_emlrtECI = { -1,  // nDims
  91,                                  // lineNo
  9,                                   // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtECInfo h_emlrtECI = { -1,  // nDims
  90,                                  // lineNo
  9,                                   // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtRTEInfo oe_emlrtRTEI = { 89,// lineNo
  15,                                  // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtRTEInfo pe_emlrtRTEI = { 89,// lineNo
  9,                                   // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtRTEInfo qe_emlrtRTEI = { 90,// lineNo
  20,                                  // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtRTEInfo re_emlrtRTEI = { 91,// lineNo
  20,                                  // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtRTEInfo se_emlrtRTEI = { 92,// lineNo
  20,                                  // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtRTEInfo te_emlrtRTEI = { 113,// lineNo
  5,                                   // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtRTEInfo ue_emlrtRTEI = { 123,// lineNo
  13,                                  // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtRTEInfo ve_emlrtRTEI = { 117,// lineNo
  22,                                  // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

static emlrtRTEInfo we_emlrtRTEI = { 117,// lineNo
  17,                                  // colNo
  "pctransform",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pctransform.m"// pName
};

// Function Definitions
namespace coder
{
  b_pointCloud *pctransform(const emlrtStack *sp, const b_pointCloud *ptCloudIn,
    const rigid3d *tform, b_pointCloud *iobj_0)
  {
    b_pointCloud lobj_0;
    b_pointCloud *ptCloudOut;
    array<real32_T, 2U> a;
    array<real32_T, 2U> b_a;
    array<real32_T, 2U> loc;
    array<real32_T, 2U> nv;
    array<real32_T, 1U> b_loc;
    emlrtStack b_st;
    emlrtStack st;
    real_T dv[16];
    real_T R[9];
    real_T dv1[9];
    real_T dv2[3];
    real_T t[3];
    int32_T exponent;
    int32_T i;
    int32_T i1;
    int32_T idx;
    int32_T loop_ub;
    real32_T f;
    boolean_T b;
    boolean_T tf;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    lobj_0.matlabCodegenIsDeleted = true;
    tform->get_T(dv);
    for (i = 0; i < 3; i++) {
      idx = i << 2;
      R[3 * i] = dv[idx];
      R[3 * i + 1] = dv[idx + 1];
      R[3 * i + 2] = dv[idx + 2];
    }

    tform->get_T(dv);
    t[0] = dv[3];
    t[1] = dv[7];
    t[2] = dv[11];
    a.set_size(&oe_emlrtRTEI, sp, ptCloudIn->Location.size(0), 3);
    loop_ub = ptCloudIn->Location.size(0) * ptCloudIn->Location.size(1);
    for (i = 0; i < loop_ub; i++) {
      a[i] = ptCloudIn->Location[i];
    }

    loc.set_size(&pe_emlrtRTEI, sp, a.size(0), 3);
    loop_ub = a.size(0);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < 3; i1++) {
        loc[i + loc.size(0) * i1] = (a[i] * static_cast<real32_T>(R[3 * i1]) +
          a[i + a.size(0)] * static_cast<real32_T>(R[3 * i1 + 1])) + a[i +
          a.size(0) * 2] * static_cast<real32_T>(R[3 * i1 + 2]);
      }
    }

    emlrtSubAssignSizeCheckR2012b(loc.size(), 1, loc.size(), 1, &h_emlrtECI, sp);
    idx = loc.size(0) - 1;
    b_loc.set_size(&qe_emlrtRTEI, sp, loc.size(0));
    for (i = 0; i <= idx; i++) {
      b_loc[i] = loc[i] + static_cast<real32_T>(t[0]);
    }

    loop_ub = b_loc.size(0);
    for (i = 0; i < loop_ub; i++) {
      loc[i] = b_loc[i];
    }

    emlrtSubAssignSizeCheckR2012b(loc.size(), 1, loc.size(), 1, &g_emlrtECI, sp);
    idx = loc.size(0) - 1;
    b_loc.set_size(&re_emlrtRTEI, sp, loc.size(0));
    for (i = 0; i <= idx; i++) {
      b_loc[i] = loc[i + loc.size(0)] + static_cast<real32_T>(t[1]);
    }

    loop_ub = b_loc.size(0);
    for (i = 0; i < loop_ub; i++) {
      loc[i + loc.size(0)] = b_loc[i];
    }

    emlrtSubAssignSizeCheckR2012b(loc.size(), 1, loc.size(), 1, &f_emlrtECI, sp);
    idx = loc.size(0) - 1;
    b_loc.set_size(&se_emlrtRTEI, sp, loc.size(0));
    for (i = 0; i <= idx; i++) {
      b_loc[i] = loc[i + loc.size(0) * 2] + static_cast<real32_T>(t[2]);
    }

    loop_ub = b_loc.size(0);
    for (i = 0; i < loop_ub; i++) {
      loc[i + loc.size(0) * 2] = b_loc[i];
    }

    nv.set_size(&te_emlrtRTEI, sp, 0, 0);
    tf = (ptCloudIn->Normal.size(0) == 0);
    b = (ptCloudIn->Normal.size(1) == 0);
    if ((!tf) && (!b)) {
      real_T absx;
      real_T b_ex;
      real_T c_ex;
      real_T ex;
      boolean_T exitg1;
      st.site = &pe_emlrtRSI;
      tform->get_T(dv);
      for (i = 0; i < 3; i++) {
        i1 = i << 2;
        dv1[3 * i] = dv[i1];
        dv1[3 * i + 1] = dv[i1 + 1];
        dv1[3 * i + 2] = dv[i1 + 2];
      }

      b_st.site = &ue_emlrtRSI;
      svd(&b_st, dv1, dv2);
      t[0] = dv2[0];
      t[1] = dv2[1];
      t[2] = dv2[2];
      tf = muDoubleScalarIsNaN(dv2[0]);
      if (!tf) {
        idx = 1;
      } else {
        idx = 0;
        loop_ub = 2;
        exitg1 = false;
        while ((!exitg1) && (loop_ub < 4)) {
          if (!muDoubleScalarIsNaN(t[loop_ub - 1])) {
            idx = loop_ub;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
      }

      if (idx == 0) {
        ex = dv2[0];
      } else {
        ex = t[idx - 1];
        idx++;
        for (loop_ub = idx; loop_ub < 4; loop_ub++) {
          absx = t[loop_ub - 1];
          if (ex < absx) {
            ex = absx;
          }
        }
      }

      if (!tf) {
        idx = 1;
      } else {
        idx = 0;
        loop_ub = 2;
        exitg1 = false;
        while ((!exitg1) && (loop_ub < 4)) {
          if (!muDoubleScalarIsNaN(t[loop_ub - 1])) {
            idx = loop_ub;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
      }

      if (idx == 0) {
        b_ex = dv2[0];
      } else {
        b_ex = t[idx - 1];
        idx++;
        for (loop_ub = idx; loop_ub < 4; loop_ub++) {
          absx = t[loop_ub - 1];
          if (b_ex > absx) {
            b_ex = absx;
          }
        }
      }

      if (!tf) {
        idx = 1;
      } else {
        idx = 0;
        loop_ub = 2;
        exitg1 = false;
        while ((!exitg1) && (loop_ub < 4)) {
          if (!muDoubleScalarIsNaN(t[loop_ub - 1])) {
            idx = loop_ub;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
      }

      if (idx == 0) {
        c_ex = dv2[0];
      } else {
        c_ex = t[idx - 1];
        idx++;
        for (loop_ub = idx; loop_ub < 4; loop_ub++) {
          absx = t[loop_ub - 1];
          if (c_ex < absx) {
            c_ex = absx;
          }
        }
      }

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

      if (ex - b_ex < 100.0 * absx) {
        tform->get_T(dv);
        b_st.site = &we_emlrtRSI;
        absx = b_det(&b_st, dv) - 1.0;
        if (muDoubleScalarAbs(absx) < 2.2204460492503131E-14) {
          tf = true;
        } else {
          tf = false;
        }
      } else {
        tf = false;
      }

      if (tf) {
        st.site = &qe_emlrtRSI;
        b_a.set_size(&ve_emlrtRTEI, &st, ptCloudIn->Normal.size(0),
                     ptCloudIn->Normal.size(1));
        loop_ub = ptCloudIn->Normal.size(0) * ptCloudIn->Normal.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_a[i] = ptCloudIn->Normal[i];
        }

        b_st.site = &xe_emlrtRSI;
        if (b_a.size(1) != 3) {
          if ((b_a.size(0) == 1) && (b_a.size(1) == 1)) {
            emlrtErrorWithMessageIdR2018a(&b_st, &n_emlrtRTEI,
              "Coder:toolbox:mtimes_noDynamicScalarExpansion",
              "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI, "MATLAB:innerdim",
              "MATLAB:innerdim", 0);
          }
        }

        nv.set_size(&we_emlrtRTEI, sp, b_a.size(0), 3);
        loop_ub = b_a.size(0);
        for (i = 0; i < loop_ub; i++) {
          idx = b_a.size(1);
          for (i1 = 0; i1 < 3; i1++) {
            f = 0.0F;
            for (exponent = 0; exponent < idx; exponent++) {
              f += b_a[i + b_a.size(0) * exponent] * static_cast<real32_T>
                (R[exponent + 3 * i1]);
            }

            nv[i + nv.size(0) * i1] = f;
          }
        }
      } else {
        st.site = &re_emlrtRSI;
        lobj_0.init(&st, loc)->surfaceNormalImpl(&st, a);
        nv.set_size(&ue_emlrtRTEI, sp, a.size(0), 3);
        loop_ub = a.size(0) * a.size(1);
        for (i = 0; i < loop_ub; i++) {
          nv[i] = a[i];
        }
      }
    }

    st.site = &se_emlrtRSI;
    ptCloudOut = iobj_0->init(&st, loc, ptCloudIn->Color, nv,
      ptCloudIn->Intensity);
    st.site = &te_emlrtRSI;
    lobj_0.matlabCodegenDestructor();
    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    return ptCloudOut;
  }
}

// End of code generation (pctransform.cpp)
