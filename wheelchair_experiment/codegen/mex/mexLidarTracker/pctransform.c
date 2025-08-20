/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pctransform.c
 *
 * Code generation for function 'pctransform'
 *
 */

/* Include files */
#include "pctransform.h"
#include "handle.h"
#include "isRigidTransform.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "pointCloud.h"
#include "rt_nonfinite.h"
#include "PCANormalCore_api.hpp"
#include "blas.h"
#include "cvstCG_kdtree.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <xmmintrin.h>

/* Variable Definitions */
static emlrtRSInfo ue_emlrtRSI = {
    9,                                                             /* lineNo */
    "pctransform",                                                 /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pctransform.m" /* pathName
                                                                    */
};

static emlrtRSInfo ve_emlrtRSI = {
    60,                                                            /* lineNo */
    "pctransform",                                                 /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pctransform.m" /* pathName
                                                                    */
};

static emlrtRSInfo xe_emlrtRSI = {
    15,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo ye_emlrtRSI = {
    41,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo af_emlrtRSI = {
    43,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo bf_emlrtRSI = {
    49,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo cf_emlrtRSI = {
    53,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo df_emlrtRSI = {
    55,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo rf_emlrtRSI = {
    430,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo sf_emlrtRSI = {
    432,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo tf_emlrtRSI = {
    454,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo uf_emlrtRSI = {
    461,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo vf_emlrtRSI = {
    469,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtECInfo f_emlrtECI = {
    -1,          /* nDims */
    18,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtECInfo g_emlrtECI = {
    -1,          /* nDims */
    17,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtECInfo h_emlrtECI = {
    -1,          /* nDims */
    16,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo re_emlrtRTEI = {
    15,          /* lineNo */
    11,          /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo se_emlrtRTEI = {
    16,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo te_emlrtRTEI =
    {
        218,      /* lineNo */
        20,       /* colNo */
        "mtimes", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = {
    17,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = {
    18,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo we_emlrtRTEI = {
    53,          /* lineNo */
    39,          /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = {
    43,          /* lineNo */
    18,          /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = {
    54,          /* lineNo */
    18,          /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo af_emlrtRTEI = {
    451,          /* lineNo */
    21,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = {
    433,          /* lineNo */
    17,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = {
    49,          /* lineNo */
    9,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo df_emlrtRTEI = {
    43,          /* lineNo */
    13,          /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = {
    462,          /* lineNo */
    47,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = {
    151,               /* lineNo */
    38,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo gf_emlrtRTEI = {
    152,               /* lineNo */
    36,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo hf_emlrtRTEI = {
    153,               /* lineNo */
    36,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo if_emlrtRTEI = {
    49,                   /* lineNo */
    17,                   /* colNo */
    "PCANormalBuildable", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/PCANormalBuildable.m" /* pName */
};

static emlrtRTEInfo jf_emlrtRTEI = {
    469,          /* lineNo */
    21,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo kf_emlrtRTEI = {
    1,                                                             /* lineNo */
    23,                                                            /* colNo */
    "pctransform",                                                 /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pctransform.m" /* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = {
    15,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = {
    39,          /* lineNo */
    1,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

/* Function Definitions */
pointCloud *pctransform(const emlrtStack *sp, const pointCloud *ptCloudIn,
                        const real_T tform_AffineTform_T[16],
                        pointCloud *iobj_0)
{
  __m128 r;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real32_T *a;
  emxArray_real32_T *a__8;
  emxArray_real32_T *b_loc;
  emxArray_real32_T *loc;
  emxArray_real32_T *nv;
  emxArray_real32_T *queryPoints;
  emxArray_real32_T *tempNormals;
  emxArray_uint32_T *indices;
  emxArray_uint32_T *valid;
  emxArray_uint8_T *b_ptCloudIn;
  pointCloud lobj_0;
  pointCloud *ptCloudOut;
  pointCloud *this;
  int32_T K;
  int32_T R_tmp;
  int32_T i;
  int32_T loop_ub;
  real32_T T[16];
  real32_T R[9];
  real32_T alpha1;
  real32_T beta1;
  real32_T *b_loc_data;
  real32_T *loc_data;
  real32_T *tempNormals_data;
  uint32_T *indices_data;
  uint32_T *valid_data;
  char_T TRANSA1;
  char_T TRANSB1;
  uint8_T *ptCloudIn_data;
  boolean_T b;
  boolean_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud(sp, &lobj_0, &kf_emlrtRTEI);
  emxInit_real32_T(sp, &loc, 2, &lf_emlrtRTEI);
  loc_data = loc->data;
  emxInit_real32_T(sp, &nv, 2, &mf_emlrtRTEI);
  emxInit_real32_T(sp, &a, 2, &xe_emlrtRTEI);
  emxInit_real32_T(sp, &a__8, 2, &kf_emlrtRTEI);
  emxInit_real32_T(sp, &tempNormals, 2, &jf_emlrtRTEI);
  emxInit_uint32_T(sp, &indices, 2, &kf_emlrtRTEI, true);
  emxInit_uint32_T(sp, &valid, 1, &kf_emlrtRTEI, true);
  emxInit_real32_T(sp, &queryPoints, 2, &ef_emlrtRTEI);
  emxInit_real32_T(sp, &b_loc, 1, &se_emlrtRTEI);
  emxInit_uint8_T(sp, &b_ptCloudIn, &we_emlrtRTEI);
  st.site = &ue_emlrtRSI;
  b_st.site = &jc_emlrtRSI;
  c_st.site = &we_emlrtRSI;
  n = (ptCloudIn->PointCloudArrayData->size[0] *
           ptCloudIn->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &t_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:pctransform:expectedScalar", 3, 4, 9, "ptCloudIn");
  }
  for (i = 0; i < 16; i++) {
    T[i] = (real32_T)tform_AffineTform_T[i];
  }
  st.site = &ve_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, &lobj_0,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  lobj_0.matlabCodegenIsDeleted = true;
  for (i = 0; i < 3; i++) {
    R_tmp = i << 2;
    R[3 * i] = T[R_tmp];
    R[3 * i + 1] = T[R_tmp + 1];
    R[3 * i + 2] = T[R_tmp + 2];
  }
  b_st.site = &xe_emlrtRSI;
  i = tempNormals->size[0] * tempNormals->size[1];
  tempNormals->size[0] = ptCloudIn->Location->size[0];
  tempNormals->size[1] = 3;
  emxEnsureCapacity_real32_T(&b_st, tempNormals, i, &re_emlrtRTEI);
  tempNormals_data = tempNormals->data;
  loop_ub = ptCloudIn->Location->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    tempNormals_data[i] = ptCloudIn->Location->data[i];
  }
  c_st.site = &ef_emlrtRSI;
  if (tempNormals->size[0] == 0) {
    loc->size[0] = 0;
    loc->size[1] = 3;
  } else {
    d_st.site = &ff_emlrtRSI;
    e_st.site = &hf_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0F;
    beta1 = 0.0F;
    m_t = (ptrdiff_t)tempNormals->size[0];
    n_t = (ptrdiff_t)3;
    k_t = (ptrdiff_t)3;
    lda_t = (ptrdiff_t)tempNormals->size[0];
    ldb_t = (ptrdiff_t)3;
    ldc_t = (ptrdiff_t)tempNormals->size[0];
    i = loc->size[0] * loc->size[1];
    loc->size[0] = tempNormals->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real32_T(&e_st, loc, i, &te_emlrtRTEI);
    loc_data = loc->data;
    sgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &tempNormals_data[0],
          &lda_t, &R[0], &ldb_t, &beta1, &loc_data[0], &ldc_t);
  }
  emlrtSubAssignSizeCheckR2012b(&loc->size[0], 1, &loc->size[0], 1, &h_emlrtECI,
                                &st);
  alpha1 = T[3];
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real32_T(&st, b_loc, i, &se_emlrtRTEI);
  b_loc_data = b_loc->data;
  loop_ub = loc->size[0];
  R_tmp = (loc->size[0] / 4) << 2;
  K = R_tmp - 4;
  for (i = 0; i <= K; i += 4) {
    r = _mm_loadu_ps(&loc_data[i]);
    _mm_storeu_ps(&b_loc_data[i], _mm_add_ps(r, _mm_set1_ps(alpha1)));
  }
  for (i = R_tmp; i < loop_ub; i++) {
    b_loc_data[i] = loc_data[i] + alpha1;
  }
  loop_ub = b_loc->size[0];
  for (i = 0; i < loop_ub; i++) {
    loc_data[i] = b_loc_data[i];
  }
  emlrtSubAssignSizeCheckR2012b(&loc->size[0], 1, &loc->size[0], 1, &g_emlrtECI,
                                &st);
  alpha1 = T[7];
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real32_T(&st, b_loc, i, &ue_emlrtRTEI);
  b_loc_data = b_loc->data;
  loop_ub = loc->size[0];
  for (i = 0; i <= K; i += 4) {
    r = _mm_loadu_ps(&loc_data[i + loc->size[0]]);
    _mm_storeu_ps(&b_loc_data[i], _mm_add_ps(r, _mm_set1_ps(alpha1)));
  }
  for (i = R_tmp; i < loop_ub; i++) {
    b_loc_data[i] = loc_data[i + loc->size[0]] + alpha1;
  }
  loop_ub = b_loc->size[0];
  for (i = 0; i < loop_ub; i++) {
    loc_data[i + loc->size[0]] = b_loc_data[i];
  }
  emlrtSubAssignSizeCheckR2012b(&loc->size[0], 1, &loc->size[0], 1, &f_emlrtECI,
                                &st);
  alpha1 = T[11];
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real32_T(&st, b_loc, i, &ve_emlrtRTEI);
  b_loc_data = b_loc->data;
  loop_ub = loc->size[0];
  for (i = 0; i <= K; i += 4) {
    r = _mm_loadu_ps(&loc_data[i + loc->size[0] * 2]);
    _mm_storeu_ps(&b_loc_data[i], _mm_add_ps(r, _mm_set1_ps(alpha1)));
  }
  for (i = R_tmp; i < loop_ub; i++) {
    b_loc_data[i] = loc_data[i + loc->size[0] * 2] + alpha1;
  }
  loop_ub = b_loc->size[0];
  for (i = 0; i < loop_ub; i++) {
    loc_data[i + loc->size[0] * 2] = b_loc_data[i];
  }
  nv->size[0] = 0;
  nv->size[1] = 0;
  n = (ptCloudIn->Normal->size[0] == 0);
  b = (ptCloudIn->Normal->size[1] == 0);
  if ((!n) && (!b)) {
    b_st.site = &ye_emlrtRSI;
    if (isRigidTransform(&b_st, T)) {
      b_st.site = &af_emlrtRSI;
      i = a->size[0] * a->size[1];
      a->size[0] = ptCloudIn->Normal->size[0];
      a->size[1] = ptCloudIn->Normal->size[1];
      emxEnsureCapacity_real32_T(&b_st, a, i, &xe_emlrtRTEI);
      loc_data = a->data;
      loop_ub = ptCloudIn->Normal->size[0] * ptCloudIn->Normal->size[1];
      for (i = 0; i < loop_ub; i++) {
        loc_data[i] = ptCloudIn->Normal->data[i];
      }
      c_st.site = &qf_emlrtRSI;
      if (a->size[1] != 3) {
        if ((a->size[0] == 1) && (a->size[1] == 1)) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &r_emlrtRTEI,
              "Coder:toolbox:mtimes_noDynamicScalarExpansion",
              "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &s_emlrtRTEI, "MATLAB:innerdim",
                                        "MATLAB:innerdim", 0);
        }
      }
      c_st.site = &ef_emlrtRSI;
      if (a->size[0] == 0) {
        tempNormals->size[0] = 0;
        tempNormals->size[1] = 3;
      } else {
        d_st.site = &ff_emlrtRSI;
        e_st.site = &hf_emlrtRSI;
        TRANSB1 = 'N';
        TRANSA1 = 'N';
        alpha1 = 1.0F;
        beta1 = 0.0F;
        m_t = (ptrdiff_t)a->size[0];
        n_t = (ptrdiff_t)3;
        k_t = (ptrdiff_t)3;
        lda_t = (ptrdiff_t)a->size[0];
        ldb_t = (ptrdiff_t)3;
        ldc_t = (ptrdiff_t)a->size[0];
        i = tempNormals->size[0] * tempNormals->size[1];
        tempNormals->size[0] = a->size[0];
        tempNormals->size[1] = 3;
        emxEnsureCapacity_real32_T(&e_st, tempNormals, i, &te_emlrtRTEI);
        tempNormals_data = tempNormals->data;
        sgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &loc_data[0],
              &lda_t, &R[0], &ldb_t, &beta1, &tempNormals_data[0], &ldc_t);
      }
      i = nv->size[0] * nv->size[1];
      nv->size[0] = tempNormals->size[0];
      nv->size[1] = 3;
      emxEnsureCapacity_real32_T(&st, nv, i, &df_emlrtRTEI);
      loc_data = nv->data;
      loop_ub = tempNormals->size[0] * 3;
      for (i = 0; i < loop_ub; i++) {
        loc_data[i] = tempNormals_data[i];
      }
    } else {
      b_st.site = &bf_emlrtRSI;
      c_st.site = &bf_emlrtRSI;
      this = pointCloud_pointCloud(&c_st, &lobj_0, loc);
      c_st.site = &rf_emlrtRSI;
      R_tmp = this->Location->size[0];
      K = (int32_T)muDoubleScalarMin(6.0, R_tmp);
      c_st.site = &sf_emlrtRSI;
      R_tmp = this->Location->size[0];
      if (R_tmp <= 2) {
        uint32_T unnamed_idx_0;
        unnamed_idx_0 = (uint32_T)this->Location->size[0];
        i = tempNormals->size[0] * tempNormals->size[1];
        tempNormals->size[0] = (int32_T)unnamed_idx_0;
        tempNormals->size[1] = 3;
        emxEnsureCapacity_real32_T(&b_st, tempNormals, i, &bf_emlrtRTEI);
        tempNormals_data = tempNormals->data;
        loop_ub = (int32_T)unnamed_idx_0 * 3;
        for (i = 0; i < loop_ub; i++) {
          tempNormals_data[i] = rtNaNF;
        }
      } else {
        void *kdtreeObj;
        i = tempNormals->size[0] * tempNormals->size[1];
        tempNormals->size[0] = this->Location->size[0];
        tempNormals->size[1] = 3;
        emxEnsureCapacity_real32_T(&b_st, tempNormals, i, &af_emlrtRTEI);
        tempNormals_data = tempNormals->data;
        loop_ub = this->Location->size[0] * 3;
        for (i = 0; i < loop_ub; i++) {
          tempNormals_data[i] = this->Location->data[i];
        }
        c_st.site = &tf_emlrtRSI;
        pointCloud_buildKdtree(&c_st, this);
        c_st.site = &uf_emlrtRSI;
        kdtreeObj = this->Kdtree;
        i = queryPoints->size[0] * queryPoints->size[1];
        queryPoints->size[0] = tempNormals->size[0];
        queryPoints->size[1] = 3;
        emxEnsureCapacity_real32_T(&c_st, queryPoints, i, &ef_emlrtRTEI);
        loc_data = queryPoints->data;
        loop_ub = tempNormals->size[0] * 3;
        for (i = 0; i < loop_ub; i++) {
          loc_data[i] = tempNormals_data[i];
        }
        i = indices->size[0] * indices->size[1];
        indices->size[0] = K;
        indices->size[1] = tempNormals->size[0];
        emxEnsureCapacity_uint32_T(&c_st, indices, i, &ff_emlrtRTEI);
        indices_data = indices->data;
        i = a__8->size[0] * a__8->size[1];
        a__8->size[0] = K;
        a__8->size[1] = tempNormals->size[0];
        emxEnsureCapacity_real32_T(&c_st, a__8, i, &gf_emlrtRTEI);
        b_loc_data = a__8->data;
        i = valid->size[0];
        valid->size[0] = tempNormals->size[0];
        emxEnsureCapacity_uint32_T(&c_st, valid, i, &hf_emlrtRTEI);
        valid_data = valid->data;
        kdtreeKNNSearch_single(kdtreeObj, &loc_data[0],
                               (uint32_T)tempNormals->size[0], 3U, (uint32_T)K,
                               0.0, 0.0F, &indices_data[0], &b_loc_data[0],
                               &valid_data[0], 2000, 500U);
        c_st.site = &vf_emlrtRSI;
        i = nv->size[0] * nv->size[1];
        nv->size[0] = tempNormals->size[0];
        nv->size[1] = 3;
        emxEnsureCapacity_real32_T(&c_st, nv, i, &if_emlrtRTEI);
        loc_data = nv->data;
        PCANormalImpl_single(&tempNormals_data[0], &indices_data[0],
                             &valid_data[0], (uint32_T)tempNormals->size[0],
                             (uint32_T)indices->size[0], &loc_data[0]);
        i = tempNormals->size[0] * tempNormals->size[1];
        tempNormals->size[0] = nv->size[0];
        tempNormals->size[1] = 3;
        emxEnsureCapacity_real32_T(&b_st, tempNormals, i, &jf_emlrtRTEI);
        tempNormals_data = tempNormals->data;
        loop_ub = nv->size[0] * 3;
        for (i = 0; i < loop_ub; i++) {
          tempNormals_data[i] = loc_data[i];
        }
      }
      i = nv->size[0] * nv->size[1];
      nv->size[0] = tempNormals->size[0];
      nv->size[1] = 3;
      emxEnsureCapacity_real32_T(&st, nv, i, &cf_emlrtRTEI);
      loc_data = nv->data;
      loop_ub = tempNormals->size[0] * 3;
      for (i = 0; i < loop_ub; i++) {
        loc_data[i] = tempNormals_data[i];
      }
    }
  }
  i = b_ptCloudIn->size[0] * b_ptCloudIn->size[1];
  b_ptCloudIn->size[0] = ptCloudIn->Color->size[0];
  b_ptCloudIn->size[1] = ptCloudIn->Color->size[1];
  emxEnsureCapacity_uint8_T(&st, b_ptCloudIn, i, &we_emlrtRTEI);
  ptCloudIn_data = b_ptCloudIn->data;
  loop_ub = ptCloudIn->Color->size[0] * ptCloudIn->Color->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    ptCloudIn_data[i] = ptCloudIn->Color->data[i];
  }
  i = a->size[0] * a->size[1];
  a->size[0] = ptCloudIn->Intensity->size[0];
  a->size[1] = ptCloudIn->Intensity->size[1];
  emxEnsureCapacity_real32_T(&st, a, i, &ye_emlrtRTEI);
  loc_data = a->data;
  loop_ub = ptCloudIn->Intensity->size[0] * ptCloudIn->Intensity->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    loc_data[i] = ptCloudIn->Intensity->data[i];
  }
  b_st.site = &cf_emlrtRSI;
  ptCloudOut = b_pointCloud_pointCloud(&b_st, iobj_0, loc, b_ptCloudIn, nv, a);
  b_st.site = &df_emlrtRSI;
  handle_matlabCodegenDestructor(&b_st, &lobj_0);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
  emxFree_uint8_T(sp, &b_ptCloudIn);
  emxFree_real32_T(sp, &b_loc);
  emxFree_real32_T(sp, &queryPoints);
  emxFree_uint32_T(sp, &valid);
  emxFree_uint32_T(sp, &indices);
  emxFree_real32_T(sp, &tempNormals);
  emxFree_real32_T(sp, &a__8);
  emxFree_real32_T(sp, &a);
  emxFree_real32_T(sp, &nv);
  emxFree_real32_T(sp, &loc);
  emxFreeStruct_pointCloud(sp, &lobj_0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return ptCloudOut;
}

/* End of code generation (pctransform.c) */
