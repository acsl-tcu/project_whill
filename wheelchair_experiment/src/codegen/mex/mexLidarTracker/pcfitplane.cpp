//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pcfitplane.cpp
//
//  Code generation for function 'pcfitplane'
//


// Include files
#include "pcfitplane.h"
#include "dot.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "mexLidarTracker_data.h"
#include "msac.h"
#include "planeModel.h"
#include "pointCloud.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "validateAndParseRansacInputs.h"
#include "warning.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <stddef.h>

// Variable Definitions
static emlrtRSInfo jh_emlrtRSI = { 195,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo kh_emlrtRSI = { 128,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo lh_emlrtRSI = { 214,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo mh_emlrtRSI = { 208,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo nh_emlrtRSI = { 206,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo oh_emlrtRSI = { 197,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo ph_emlrtRSI = { 185,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo qh_emlrtRSI = { 182,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo rh_emlrtRSI = { 167,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo sh_emlrtRSI = { 166,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo th_emlrtRSI = { 165,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo uh_emlrtRSI = { 158,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo vh_emlrtRSI = { 156,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo wh_emlrtRSI = { 155,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo xh_emlrtRSI = { 119,// lineNo
  "pcfitplane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo ji_emlrtRSI = { 19, // lineNo
  "initializeRansacModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/initializeRansacModel.m"// pathName 
};

static emlrtRSInfo ki_emlrtRSI = { 24, // lineNo
  "initializeRansacModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/initializeRansacModel.m"// pathName 
};

static emlrtRSInfo li_emlrtRSI = { 4,  // lineNo
  "initializeRansacModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/initializeRansacModel.m"// pathName 
};

static emlrtRSInfo mi_emlrtRSI = { 17, // lineNo
  "initializeRansacModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/initializeRansacModel.m"// pathName 
};

static emlrtRSInfo ni_emlrtRSI = { 18, // lineNo
  "initializeRansacModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/initializeRansacModel.m"// pathName 
};

static emlrtRSInfo oi_emlrtRSI = { 21, // lineNo
  "initializeRansacModel",             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/initializeRansacModel.m"// pathName 
};

static emlrtRSInfo xj_emlrtRSI = { 248,// lineNo
  "evalPlane",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo dk_emlrtRSI = { 18, // lineNo
  "abs",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/abs.m"// pathName
};

static emlrtRSInfo ek_emlrtRSI = { 75, // lineNo
  "applyScalarFunction",               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"// pathName 
};

static emlrtRSInfo ml_emlrtRSI = { 17, // lineNo
  "acos",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/acos.m"// pathName
};

static emlrtRSInfo nl_emlrtRSI = { 18, // lineNo
  "ifWhileCond",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/ifWhileCond.m"// pathName 
};

static emlrtRSInfo vl_emlrtRSI = { 9,  // lineNo
  "checkRansacRuntimeStatus",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/checkRansacRuntimeStatus.m"// pathName 
};

static emlrtRSInfo wl_emlrtRSI = { 11, // lineNo
  "checkRansacRuntimeStatus",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/checkRansacRuntimeStatus.m"// pathName 
};

static emlrtRTEInfo v_emlrtRTEI = { 20,// lineNo
  15,                                  // colNo
  "rdivide_helper",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/rdivide_helper.m"// pName 
};

static emlrtBCInfo n_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  19,                                  // lineNo
  41,                                  // colNo
  "",                                  // aName
  "initializeRansacModel",             // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/initializeRansacModel.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo o_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  198,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo p_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  207,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo q_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  165,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo r_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  248,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "evalPlane",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo s_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  248,                                 // lineNo
  26,                                  // colNo
  "",                                  // aName
  "evalPlane",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo sf_emlrtRTEI = { 19,// lineNo
  5,                                   // colNo
  "initializeRansacModel",             // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/initializeRansacModel.m"// pName 
};

static emlrtRTEInfo tf_emlrtRTEI = { 158,// lineNo
  62,                                  // colNo
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pName
};

static emlrtRTEInfo vf_emlrtRTEI = { 31,// lineNo
  21,                                  // colNo
  "applyScalarFunction",               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"// pName 
};

static emlrtRTEInfo wf_emlrtRTEI = { 200,// lineNo
  9,                                   // colNo
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pName
};

static emlrtRTEInfo xf_emlrtRTEI = { 210,// lineNo
  9,                                   // colNo
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pName
};

static emlrtRTEInfo yf_emlrtRTEI = { 197,// lineNo
  44,                                  // colNo
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pName
};

static emlrtRTEInfo ag_emlrtRTEI = { 198,// lineNo
  45,                                  // colNo
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pName
};

static emlrtRTEInfo bg_emlrtRTEI = { 1,// lineNo
  62,                                  // colNo
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pName
};

static emlrtRTEInfo cg_emlrtRTEI = { 206,// lineNo
  9,                                   // colNo
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pName
};

static emlrtRTEInfo dg_emlrtRTEI = { 207,// lineNo
  14,                                  // colNo
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pName
};

static emlrtRTEInfo eg_emlrtRTEI = { 208,// lineNo
  9,                                   // colNo
  "pcfitplane",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pName
};

static emlrtRTEInfo pg_emlrtRTEI = { 79,// lineNo
  5,                                   // colNo
  "eml_mtimes_helper",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pName 
};

// Function Definitions
namespace coder
{
  void evalPlane(const emlrtStack *sp, const real32_T model_data[], const
                 int32_T model_size[2], const ::coder::array<real32_T, 2U>
                 &points, ::coder::array<real32_T, 1U> &dis)
  {
    ptrdiff_t k_t;
    ptrdiff_t lda_t;
    ptrdiff_t ldb_t;
    ptrdiff_t ldc_t;
    ptrdiff_t m_t;
    ptrdiff_t n_t;
    array<real32_T, 1U> y;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack st;
    int32_T k;
    int32_T nx;
    real32_T fv[3];
    real32_T alpha1;
    real32_T beta1;
    char_T TRANSA1;
    char_T TRANSB1;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &xj_emlrtRSI;
    internal::indexShapeCheck(&st, model_size);
    nx = model_size[0] * model_size[1];
    if (1 > nx) {
      emlrtDynamicBoundsCheckR2012b(1, 1, nx, &s_emlrtBCI, sp);
    }

    fv[0] = model_data[0];
    if (2 > nx) {
      emlrtDynamicBoundsCheckR2012b(2, 1, 1, &s_emlrtBCI, sp);
    }

    fv[1] = model_data[1];
    if (3 > nx) {
      emlrtDynamicBoundsCheckR2012b(3, 1, 2, &s_emlrtBCI, sp);
    }

    fv[2] = model_data[2];
    if (4 > nx) {
      emlrtDynamicBoundsCheckR2012b(4, 1, nx, &r_emlrtBCI, sp);
    }

    st.site = &xj_emlrtRSI;
    b_st.site = &yj_emlrtRSI;
    if (points.size(0) == 0) {
      y.set_size(&pg_emlrtRTEI, &b_st, 0);
    } else {
      c_st.site = &ak_emlrtRSI;
      d_st.site = &ck_emlrtRSI;
      TRANSB1 = 'T';
      TRANSA1 = 'N';
      alpha1 = 1.0F;
      beta1 = 0.0F;
      m_t = (ptrdiff_t)points.size(0);
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)3;
      lda_t = (ptrdiff_t)points.size(0);
      ldb_t = (ptrdiff_t)1;
      ldc_t = (ptrdiff_t)points.size(0);
      y.set_size(&og_emlrtRTEI, &d_st, points.size(0));
      sgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(((::coder::array<
               real32_T, 2U> *)&points)->data())[0], &lda_t, &fv[0], &ldb_t,
            &beta1, &(y.data())[0], &ldc_t);
    }

    st.site = &xj_emlrtRSI;
    nx = y.size(0);
    for (k = 0; k < nx; k++) {
      y[k] = y[k] + model_data[3];
    }

    b_st.site = &dk_emlrtRSI;
    nx = y.size(0);
    dis.set_size(&vf_emlrtRTEI, &b_st, y.size(0));
    c_st.site = &ek_emlrtRSI;
    if ((1 <= y.size(0)) && (y.size(0) > 2147483646)) {
      d_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k < nx; k++) {
      dis[k] = muSingleScalarAbs(y[k]);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void pcfitplane(const emlrtStack *sp, b_pointCloud *varargin_1, real_T
                  varargin_2, const real_T varargin_3[3], real_T varargin_4,
                  const ::coder::array<uint32_T, 1U> &varargin_6, planeModel
                  *iobj_0, planeModel **model, ::coder::array<real_T, 1U>
                  &inlierIndices, ::coder::array<real_T, 1U> &outlierIndices)
  {
    ptrdiff_t incx_t;
    ptrdiff_t incy_t;
    ptrdiff_t n_t;
    b_pointCloud lobj_0[3];
    b_pointCloud pc;
    b_pointCloud *b_iobj_0;
    b_pointCloud *b_pc;
    b_pointCloud *c_pc;
    b_pointCloud *d_pc;
    b_pointCloud *e_pc;
    b_pointCloud *ptCloud;
    array<real_T, 2U> sampleIndices;
    array<real_T, 1U> indices;
    array<real_T, 1U> validPtCloudIndices;
    array<int32_T, 1U> ii;
    array<real32_T, 2U> f_pc;
    array<real32_T, 1U> distances;
    array<boolean_T, 2U> r;
    array<boolean_T, 1U> flag;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T y_data[9];
    real_T denorm_data[3];
    real_T normAxis_data[3];
    real_T normAxis[2];
    real_T maxAngularDistance;
    real_T ransacParams_confidence;
    real_T ransacParams_maxDistance;
    real_T ransacParams_maxNumTrials;
    int32_T b_iv[2];
    int32_T denorm_size[2];
    int32_T modelParams_size[2];
    int32_T normAxis_size[2];
    int32_T angle_size_idx_1;
    int32_T k;
    int32_T loop_ub;
    int32_T nx;
    int32_T status;
    real32_T modelParams_data[4];
    real32_T a_data[3];
    real32_T angle_data[3];
    real32_T modelParams[3];
    real32_T varargin_2_data[3];
    boolean_T x_data[3];
    boolean_T isFound;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    lobj_0[2].matlabCodegenIsDeleted = true;
    lobj_0[0].matlabCodegenIsDeleted = true;
    lobj_0[1].matlabCodegenIsDeleted = true;
    st.site = &xh_emlrtRSI;
    vision::internal::ransac::validateAndParseRansacInputs(&st, varargin_1,
      varargin_2, varargin_3, varargin_4, varargin_6, &ptCloud,
      &ransacParams_maxDistance, &ransacParams_maxNumTrials,
      &ransacParams_confidence, sampleIndices, normAxis_data, normAxis_size,
      &maxAngularDistance);
    st.site = &kh_emlrtRSI;
    b_iobj_0 = &lobj_0[0];
    pc.matlabCodegenIsDeleted = true;
    if (sampleIndices.size(0) != 0) {
      b_st.site = &mi_emlrtRSI;
      ptCloud->b_select(&b_st, sampleIndices, &pc);
      b_st.site = &ni_emlrtRSI;
      pc.removeInvalidPoints(&b_st, &b_iobj_0[0], &c_pc, indices);
      b_iobj_0 = c_pc;
      b_iv[0] = (*(int32_T (*)[2])sampleIndices.size())[0];
      b_iv[1] = (*(int32_T (*)[2])sampleIndices.size())[1];
      b_st.site = &ji_emlrtRSI;
      internal::indexShapeCheck(&b_st, b_iv, indices.size(0));
      validPtCloudIndices.set_size(&sf_emlrtRTEI, &st, indices.size(0));
      loop_ub = indices.size(0);
      for (k = 0; k < loop_ub; k++) {
        nx = static_cast<int32_T>(indices[k]);
        if ((nx < 1) || (nx > sampleIndices.size(0))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, sampleIndices.size(0),
            &n_emlrtBCI, &st);
        }

        validPtCloudIndices[k] = sampleIndices[nx - 1];
      }
    } else {
      b_st.site = &oi_emlrtRSI;
      ptCloud->removeInvalidPoints(&b_st, &b_iobj_0[1], &b_pc,
        validPtCloudIndices);
      b_iobj_0 = b_pc;
    }

    b_st.site = &ki_emlrtRSI;
    if (b_iobj_0->get_Count() < 3.0) {
      status = 1;
    } else {
      status = 0;
    }

    b_st.site = &li_emlrtRSI;
    pc.matlabCodegenDestructor();
    d_pc = b_iobj_0;
    modelParams_size[0] = 1;
    modelParams_size[1] = 4;
    modelParams_data[0] = 0.0F;
    modelParams_data[1] = 0.0F;
    modelParams_data[2] = 0.0F;
    modelParams_data[3] = 0.0F;
    if (status == 0) {
      st.site = &wh_emlrtRSI;
      n_t = (ptrdiff_t)3;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      ransacParams_maxNumTrials = ddot(&n_t, &normAxis_data[0], &incx_t,
        &normAxis_data[0], &incy_t);
      denorm_size[0] = 1;
      denorm_size[1] = 1;
      denorm_data[0] = ransacParams_maxNumTrials;
      st.site = &wh_emlrtRSI;
      b_sqrt(&st, denorm_data, denorm_size);
      st.site = &vh_emlrtRSI;
      normAxis[0] = normAxis_size[0];
      normAxis[1] = normAxis_size[1];
      b_st.site = &vh_emlrtRSI;
      repmat(&b_st, denorm_data, denorm_size, normAxis, y_data, normAxis_size);
      if (3 != normAxis_size[1]) {
        emlrtErrorWithMessageIdR2018a(&st, &v_emlrtRTEI, "MATLAB:dimagree",
          "MATLAB:dimagree", 0);
      }

      normAxis_data[0] /= y_data[0];
      normAxis_data[1] /= y_data[1];
      normAxis_data[2] /= y_data[2];
      f_pc.set_size(&tf_emlrtRTEI, sp, b_iobj_0->Location.size(0), 3);
      loop_ub = b_iobj_0->Location.size(0) * b_iobj_0->Location.size(1) - 1;
      for (k = 0; k <= loop_ub; k++) {
        f_pc[k] = b_iobj_0->Location[k];
      }

      st.site = &uh_emlrtRSI;
      vision::internal::ransac::msac(&st, f_pc, ransacParams_maxDistance,
        normAxis_data, maxAngularDistance, &isFound, modelParams_data,
        modelParams_size);
      if (isFound) {
        boolean_T exitg1;
        st.site = &th_emlrtRSI;
        internal::indexShapeCheck(&st, modelParams_size);
        st.site = &th_emlrtRSI;
        loop_ub = modelParams_size[0] * modelParams_size[1];
        if (1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(1, 1, loop_ub, &q_emlrtBCI, &st);
        }

        modelParams[0] = modelParams_data[0];
        if (2 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(2, 1, 1, &q_emlrtBCI, &st);
        }

        modelParams[1] = modelParams_data[1];
        if (3 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(3, 1, 2, &q_emlrtBCI, &st);
        }

        modelParams[2] = modelParams_data[2];
        b_st.site = &th_emlrtRSI;
        dot(normAxis_data, modelParams, varargin_2_data, normAxis_size);
        b_st.site = &md_emlrtRSI;
        angle_size_idx_1 = static_cast<int8_T>(normAxis_size[1]);
        nx = static_cast<int8_T>(normAxis_size[1]);
        for (k = 0; k < nx; k++) {
          angle_data[k] = muSingleScalarMax(-1.0F, varargin_2_data[k]);
        }

        st.site = &th_emlrtRSI;
        b_st.site = &td_emlrtRSI;
        for (k = 0; k < angle_size_idx_1; k++) {
          a_data[k] = muSingleScalarMin(1.0F, angle_data[k]);
        }

        st.site = &sh_emlrtRSI;
        b_st.site = &ml_emlrtRSI;
        for (k = 0; k < angle_size_idx_1; k++) {
          a_data[k] = muSingleScalarAcos(a_data[k]);
        }

        st.site = &sh_emlrtRSI;
        b_st.site = &dk_emlrtRSI;
        nx = static_cast<int8_T>(normAxis_size[1]);
        angle_size_idx_1 = static_cast<int8_T>(normAxis_size[1]);
        for (k = 0; k < nx; k++) {
          angle_data[k] = muSingleScalarAbs(a_data[k]);
        }

        st.site = &rh_emlrtRSI;
        for (k = 0; k < angle_size_idx_1; k++) {
          x_data[k] = (angle_data[k] > 1.5707963267948966);
        }

        b_st.site = &nl_emlrtRSI;
        isFound = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= angle_size_idx_1 - 1)) {
          if (!x_data[k]) {
            isFound = false;
            exitg1 = true;
          } else {
            k++;
          }
        }

        if (isFound) {
          for (k = 0; k < loop_ub; k++) {
            modelParams_data[k] = -modelParams_data[k];
          }
        }
      } else {
        status = 2;
      }
    }

    if ((modelParams_size[0] == 0) || (modelParams_size[1] == 0)) {
      modelParams_size[0] = 1;
      modelParams_size[1] = 4;
      modelParams_data[0] = 0.0F;
      modelParams_data[1] = 0.0F;
      modelParams_data[2] = 0.0F;
      modelParams_data[3] = 0.0F;
    }

    st.site = &qh_emlrtRSI;
    *model = iobj_0->init(&st, modelParams_data, modelParams_size);
    st.site = &ph_emlrtRSI;
    if (status == 1) {
      b_st.site = &vl_emlrtRSI;
      internal::b_warning(&b_st);
    } else {
      if (status == 2) {
        b_st.site = &wl_emlrtRSI;
        internal::c_warning(&b_st);
      }
    }

    if (status == 0) {
      if (sampleIndices.size(0) != 0) {
        st.site = &jh_emlrtRSI;
        ptCloud->removeInvalidPoints(&st, &lobj_0[2], &e_pc, validPtCloudIndices);
        d_pc = e_pc;
      }

      f_pc.set_size(&yf_emlrtRTEI, sp, d_pc->Location.size(0), 3);
      loop_ub = d_pc->Location.size(0) * d_pc->Location.size(1) - 1;
      for (k = 0; k <= loop_ub; k++) {
        f_pc[k] = d_pc->Location[k];
      }

      st.site = &oh_emlrtRSI;
      evalPlane(&st, modelParams_data, modelParams_size, f_pc, distances);
      r.set_size(&ag_emlrtRTEI, sp, distances.size(0), 1);
      loop_ub = distances.size(0);
      for (k = 0; k < loop_ub; k++) {
        r[k] = (distances[k] < ransacParams_maxDistance);
      }

      loop_ub = r.size(0) - 1;
      nx = 0;
      for (angle_size_idx_1 = 0; angle_size_idx_1 <= loop_ub; angle_size_idx_1++)
      {
        if (r[angle_size_idx_1]) {
          nx++;
        }
      }

      inlierIndices.set_size(&bg_emlrtRTEI, sp, nx);
      nx = 0;
      for (angle_size_idx_1 = 0; angle_size_idx_1 <= loop_ub; angle_size_idx_1++)
      {
        if (r[angle_size_idx_1]) {
          if ((angle_size_idx_1 + 1 < 1) || (angle_size_idx_1 + 1 >
               validPtCloudIndices.size(0))) {
            emlrtDynamicBoundsCheckR2012b(angle_size_idx_1 + 1, 1,
              validPtCloudIndices.size(0), &o_emlrtBCI, sp);
          }

          inlierIndices[nx] = validPtCloudIndices[angle_size_idx_1];
          nx++;
        }
      }

      st.site = &nh_emlrtRSI;
      ransacParams_maxNumTrials = ptCloud->get_Count();
      flag.set_size(&cg_emlrtRTEI, &st, static_cast<int32_T>
                    (ransacParams_maxNumTrials));
      loop_ub = static_cast<int32_T>(ransacParams_maxNumTrials);
      for (k = 0; k < loop_ub; k++) {
        flag[k] = true;
      }

      ii.set_size(&dg_emlrtRTEI, &st, inlierIndices.size(0));
      loop_ub = inlierIndices.size(0);
      for (k = 0; k < loop_ub; k++) {
        nx = static_cast<int32_T>(inlierIndices[k]);
        if ((nx < 1) || (nx > flag.size(0))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, flag.size(0), &p_emlrtBCI, &st);
        }

        ii[k] = nx;
      }

      loop_ub = ii.size(0);
      for (k = 0; k < loop_ub; k++) {
        flag[ii[k] - 1] = false;
      }

      b_st.site = &mh_emlrtRSI;
      c_st.site = &jf_emlrtRSI;
      eml_find(&c_st, flag, ii);
      outlierIndices.set_size(&eg_emlrtRTEI, &b_st, ii.size(0));
      loop_ub = ii.size(0);
      for (k = 0; k < loop_ub; k++) {
        outlierIndices[k] = ii[k];
      }
    } else {
      inlierIndices.set_size(&wf_emlrtRTEI, sp, 0);
      outlierIndices.set_size(&xf_emlrtRTEI, sp, 0);
    }

    st.site = &lh_emlrtRSI;
    lobj_0[1].matlabCodegenDestructor();
    st.site = &lh_emlrtRSI;
    lobj_0[0].matlabCodegenDestructor();
    st.site = &lh_emlrtRSI;
    lobj_0[2].matlabCodegenDestructor();
    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }
}

// End of code generation (pcfitplane.cpp)
