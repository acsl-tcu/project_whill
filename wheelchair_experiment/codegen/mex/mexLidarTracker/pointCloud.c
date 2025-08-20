/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pointCloud.c
 *
 * Code generation for function 'pointCloud'
 *
 */

/* Include files */
#include "pointCloud.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "pointCloudBase.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "cvstCG_ComputeMetric.h"
#include "cvstCG_kdtree.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = {
    33,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    34,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    43,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    87,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    88,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    89,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    90,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    820,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    838,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo hg_emlrtRSI = {
    230,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ig_emlrtRSI = {
    228,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo jg_emlrtRSI = {
    220,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo kg_emlrtRSI = {
    166,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo lg_emlrtRSI = {
    162,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo mg_emlrtRSI = {
    154,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ai_emlrtRSI = {
    88,                                 /* lineNo */
    "pointCloud/findNeighborsInRadius", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo bi_emlrtRSI = {
    262,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo ci_emlrtRSI = {
    264,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo di_emlrtRSI = {
    271,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo ei_emlrtRSI = {
    273,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo fi_emlrtRSI = {
    288,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo gi_emlrtRSI = {
    299,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo hi_emlrtRSI = {
    1231,                                            /* lineNo */
    "pointCloud/validateAndParseRadiusSearchOption", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ii_emlrtRSI = {
    1237,                                            /* lineNo */
    "pointCloud/validateAndParseRadiusSearchOption", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ji_emlrtRSI = {
    649,                                 /* lineNo */
    "pointCloudBase/validateQueryPoint", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo ki_emlrtRSI = {
    674,                             /* lineNo */
    "pointCloudBase/validateRadius", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo li_emlrtRSI = {
    552,                                     /* lineNo */
    "pointCloudBase/bruteForceRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo mi_emlrtRSI = {
    554,                                     /* lineNo */
    "pointCloudBase/bruteForceRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo ni_emlrtRSI = {
    559,                                     /* lineNo */
    "pointCloudBase/bruteForceRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo oi_emlrtRSI = {
    867,                     /* lineNo */
    "pointCloud/bruteForce", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ri_emlrtRSI = {
    929,                             /* lineNo */
    "pointCloud/kdtreeRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo si_emlrtRSI = {
    931,                             /* lineNo */
    "pointCloud/kdtreeRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ti_emlrtRSI = {
    213,                                  /* lineNo */
    "kdtreeBuildable/kdtreeRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pathName */
};

static emlrtRSInfo ui_emlrtRSI = {
    214,                                  /* lineNo */
    "kdtreeBuildable/kdtreeRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pathName */
};

static emlrtRSInfo dj_emlrtRSI = {
    16,                                                            /* lineNo */
    "sqrt",                                                        /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elfun/sqrt.m" /* pathName
                                                                    */
};

static emlrtRTEInfo u_emlrtRTEI = {
    69,                            /* lineNo */
    13,                            /* colNo */
    "kdtreeBuildable/kdtreeIndex", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    166,                 /* lineNo */
    21,                  /* colNo */
    "pointCloud/select", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtDCInfo e_emlrtDCI = {
    213,                                  /* lineNo */
    45,                                   /* colNo */
    "kdtreeBuildable/kdtreeRadiusSearch", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m", /* pName */
    1                               /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    214,                                  /* lineNo */
    43,                                   /* colNo */
    "kdtreeBuildable/kdtreeRadiusSearch", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m", /* pName */
    1                               /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    559,                                     /* lineNo */
    36,                                      /* colNo */
    "",                                      /* aName */
    "pointCloudBase/bruteForceRadiusSearch", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    564,                                     /* lineNo */
    35,                                      /* colNo */
    "",                                      /* aName */
    "pointCloudBase/bruteForceRadiusSearch", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    565,                                     /* lineNo */
    33,                                      /* colNo */
    "",                                      /* aName */
    "pointCloudBase/bruteForceRadiusSearch", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtRTEInfo sd_emlrtRTEI = {
    85,               /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = {
    820,          /* lineNo */
    110,          /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = {
    208,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo rf_emlrtRTEI = {
    208,              /* lineNo */
    32,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = {
    208,              /* lineNo */
    62,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = {
    209,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo uf_emlrtRTEI = {
    209,              /* lineNo */
    33,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = {
    149,          /* lineNo */
    31,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo tg_emlrtRTEI = {
    552,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ug_emlrtRTEI = {
    43,                       /* lineNo */
    21,                       /* colNo */
    "ComputeMetricBuildable", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/ComputeMetricBuildable.m" /* pName */
};

static emlrtRTEInfo vg_emlrtRTEI = {
    213,               /* lineNo */
    39,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo wg_emlrtRTEI = {
    554,              /* lineNo */
    35,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo xg_emlrtRTEI = {
    554,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = {
    559,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = {
    214,               /* lineNo */
    37,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = {
    85,           /* lineNo */
    37,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = {
    214,               /* lineNo */
    13,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = {
    41,                       /* lineNo */
    17,                       /* colNo */
    "ComputeMetricBuildable", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "+buildable/ComputeMetricBuildable.m" /* pName */
};

/* Function Definitions */
pointCloud *b_pointCloud_pointCloud(const emlrtStack *sp, pointCloud *this,
                                    const emxArray_real32_T *varargin_1,
                                    const emxArray_uint8_T *varargin_3,
                                    const emxArray_real32_T *varargin_5,
                                    const emxArray_real32_T *varargin_7)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real32_T tmp_data;
  pointCloud *b_this;
  int32_T tmp_size[2];
  int32_T i;
  int32_T loop_ub;
  const real32_T *varargin_1_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  varargin_1_data = varargin_1->data;
  b_this = this;
  b_this->HasKdtreeConstructed = false;
  b_this->HasLocationHandleAllocated = false;
  st.site = &x_emlrtRSI;
  i = b_this->Location->size[0] * b_this->Location->size[1];
  b_this->Location->size[0] = varargin_1->size[0];
  b_this->Location->size[1] = 3;
  emxEnsureCapacity_real32_T(&st, b_this->Location, i, &sd_emlrtRTEI);
  loop_ub = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this->Location->data[i] = varargin_1_data[i];
  }
  b_st.site = &cb_emlrtRSI;
  pointCloudBase_set_Color(&b_st, b_this, varargin_3);
  b_st.site = &db_emlrtRSI;
  pointCloudBase_set_Normal(&b_st, b_this, varargin_5);
  b_st.site = &eb_emlrtRSI;
  pointCloudBase_set_Intensity(&b_st, b_this, varargin_7);
  tmp_size[0] = 0;
  tmp_size[1] = 0;
  tmp_data.size = &tmp_size[0];
  tmp_data.allocatedSize = 0;
  tmp_data.numDimensions = 2;
  tmp_data.canFreeData = false;
  b_st.site = &fb_emlrtRSI;
  pointCloudBase_set_RangeData(&b_st, b_this, &tmp_data);
  st.site = &y_emlrtRSI;
  b_this->PointCloudArrayData->size[0] = 1;
  b_this->PointCloudArrayData->size[1] = 1;
  st.site = &ab_emlrtRSI;
  b_this->Kdtree = NULL;
  b_this->LocationHandle = NULL;
  b_this->matlabCodegenIsDeleted = false;
  return b_this;
}

void c_pointCloud_findNeighborsInRad(const emlrtStack *sp, pointCloud *this,
                                     const real32_T varargin_1[3],
                                     real32_T varargin_2,
                                     emxArray_uint32_T *indices)
{
  static const char_T functionName[21] = {'f', 'i', 'n', 'd', 'N', 'e', 'i',
                                          'g', 'h', 'b', 'o', 'r', 's', 'I',
                                          'n', 'R', 'a', 'd', 'i', 'u', 's'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T *b_allDists;
  emxArray_int32_T *ii;
  emxArray_real32_T *allDists;
  emxArray_real32_T *dists_;
  emxArray_real32_T *r;
  int32_T i;
  int32_T k;
  int32_T *ii_data;
  real32_T point[3];
  real32_T *allDists_data;
  real32_T *dists__data;
  real32_T *r1;
  uint32_T *indices_data;
  boolean_T exitg1;
  boolean_T p;
  boolean_T *b_allDists_data;
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
  st.site = &ai_emlrtRSI;
  b_st.site = &bi_emlrtRSI;
  c_st.site = &ng_emlrtRSI;
  if (this->PointCloudArrayData->size[0] * this->PointCloudArrayData->size[1] !=
      1) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &y_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 21, &functionName[0]);
  }
  b_st.site = &ci_emlrtRSI;
  c_st.site = &hi_emlrtRSI;
  d_st.site = &ji_emlrtRSI;
  e_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!muSingleScalarIsNaN(varargin_1[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &q_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:expectedNonNaN", 3, 4, 5, "point");
  }
  e_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if ((!muSingleScalarIsInf(varargin_1[k])) &&
        (!muSingleScalarIsNaN(varargin_1[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:expectedFinite", 3, 4, 5, "point");
  }
  point[0] = varargin_1[0];
  point[1] = varargin_1[1];
  point[2] = varargin_1[2];
  c_st.site = &ii_emlrtRSI;
  d_st.site = &ki_emlrtRSI;
  e_st.site = &jc_emlrtRSI;
  if (muSingleScalarIsNaN(varargin_2)) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &q_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:expectedNonNaN", 3, 4, 6, "radius");
  }
  e_st.site = &jc_emlrtRSI;
  if (muSingleScalarIsInf(varargin_2)) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:expectedFinite", 3, 4, 6, "radius");
  }
  e_st.site = &jc_emlrtRSI;
  if (varargin_2 < 0.0F) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:expectedNonnegative", 3, 4, 6, "radius");
  }
  b_st.site = &di_emlrtRSI;
  emxInit_real32_T(&st, &dists_, 1, &ch_emlrtRTEI);
  dists__data = dists_->data;
  if (this->Location->size[0] < 500) {
    real_T y;
    int32_T end_tmp;
    b_st.site = &ei_emlrtRSI;
    c_st.site = &li_emlrtRSI;
    k = this->Location->size[0];
    d_st.site = &oi_emlrtRSI;
    emxInit_real32_T(&d_st, &allDists, 2, &tg_emlrtRTEI);
    i = allDists->size[0] * allDists->size[1];
    allDists->size[0] = 1;
    allDists->size[1] = k;
    emxEnsureCapacity_real32_T(&d_st, allDists, i, &tg_emlrtRTEI);
    allDists_data = allDists->data;
    emxInit_real32_T(&d_st, &r, 2, &dh_emlrtRTEI);
    i = r->size[0] * r->size[1];
    r->size[0] = 3;
    r->size[1] = this->Location->size[0];
    emxEnsureCapacity_real32_T(&d_st, r, i, &ug_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < k; i++) {
      allDists_data[i] = 0.0F;
      r1[3 * i] = this->Location->data[i];
      r1[3 * i + 1] = this->Location->data[i + this->Location->size[0]];
      r1[3 * i + 2] = this->Location->data[i + this->Location->size[0] * 2];
    }
    ComputeMetric_ssd_single(&point[0], &r1[0], &allDists_data[0], 1U,
                             (uint32_T)this->Location->size[0], 3U);
    emxFree_real32_T(&d_st, &r);
    c_st.site = &mi_emlrtRSI;
    d_st.site = &pi_emlrtRSI;
    y = (real_T)varargin_2 * varargin_2;
    c_st.site = &mi_emlrtRSI;
    emxInit_boolean_T(&c_st, &b_allDists, 2, &wg_emlrtRTEI, true);
    i = b_allDists->size[0] * b_allDists->size[1];
    b_allDists->size[0] = 1;
    b_allDists->size[1] = allDists->size[1];
    emxEnsureCapacity_boolean_T(&c_st, b_allDists, i, &wg_emlrtRTEI);
    b_allDists_data = b_allDists->data;
    k = allDists->size[1];
    for (i = 0; i < k; i++) {
      b_allDists_data[i] = (allDists_data[i] <= y);
    }
    emxInit_int32_T(&c_st, &ii, 2, &qe_emlrtRTEI);
    d_st.site = &cg_emlrtRSI;
    b_eml_find(&d_st, b_allDists, ii);
    ii_data = ii->data;
    emxFree_boolean_T(&c_st, &b_allDists);
    i = indices->size[0];
    indices->size[0] = ii->size[1];
    emxEnsureCapacity_uint32_T(&b_st, indices, i, &xg_emlrtRTEI);
    indices_data = indices->data;
    k = ii->size[1];
    for (i = 0; i < k; i++) {
      end_tmp = ii_data[i];
      if (end_tmp < 0) {
        end_tmp = 0;
      }
      indices_data[i] = (uint32_T)end_tmp;
    }
    emxFree_int32_T(&b_st, &ii);
    if (indices->size[0] == 0) {
      dists_->size[0] = 0;
    } else {
      int32_T trueCount;
      c_st.site = &ni_emlrtRSI;
      b_indexShapeCheck(&c_st, allDists->size, indices->size[0]);
      i = dists_->size[0];
      dists_->size[0] = indices->size[0];
      emxEnsureCapacity_real32_T(&b_st, dists_, i, &yg_emlrtRTEI);
      dists__data = dists_->data;
      k = indices->size[0];
      for (i = 0; i < k; i++) {
        if (((int32_T)indices_data[i] < 1) ||
            ((int32_T)indices_data[i] > allDists->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)indices_data[i], 1,
                                        allDists->size[1], &ob_emlrtBCI, &b_st);
        }
        dists__data[i] = allDists_data[(int32_T)indices_data[i] - 1];
      }
      end_tmp = dists_->size[0] - 1;
      trueCount = 0;
      for (i = 0; i <= end_tmp; i++) {
        if ((!muSingleScalarIsInf(dists__data[i])) &&
            (!muSingleScalarIsNaN(dists__data[i]))) {
          trueCount++;
        }
      }
      k = 0;
      for (i = 0; i <= end_tmp; i++) {
        if ((!muSingleScalarIsInf(dists__data[i])) &&
            (!muSingleScalarIsNaN(dists__data[i]))) {
          if (i > indices->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(i, 0, indices->size[0] - 1,
                                          &pb_emlrtBCI, &b_st);
          }
          indices_data[k] = indices_data[i];
          k++;
        }
      }
      i = indices->size[0];
      indices->size[0] = trueCount;
      emxEnsureCapacity_uint32_T(&b_st, indices, i, &bh_emlrtRTEI);
      trueCount = 0;
      for (i = 0; i <= end_tmp; i++) {
        if ((!muSingleScalarIsInf(dists__data[i])) &&
            (!muSingleScalarIsNaN(dists__data[i]))) {
          trueCount++;
        }
      }
      k = 0;
      for (i = 0; i <= end_tmp; i++) {
        if ((!muSingleScalarIsInf(dists__data[i])) &&
            (!muSingleScalarIsNaN(dists__data[i]))) {
          if (i > dists_->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(i, 0, dists_->size[0] - 1,
                                          &qb_emlrtBCI, &b_st);
          }
          dists__data[k] = dists__data[i];
          k++;
        }
      }
      i = dists_->size[0];
      dists_->size[0] = trueCount;
      emxEnsureCapacity_real32_T(&b_st, dists_, i, &bh_emlrtRTEI);
      dists__data = dists_->data;
    }
    emxFree_real32_T(&b_st, &allDists);
  } else {
    void *ptrDists;
    void *ptrIndices;
    real_T y;
    uint32_T valid;
    b_st.site = &fi_emlrtRSI;
    c_st.site = &ri_emlrtRSI;
    pointCloud_buildKdtree(&c_st, this);
    c_st.site = &si_emlrtRSI;
    ptrIndices = NULL;
    ptrDists = NULL;
    kdtreeRadiusSearch_single(this->Kdtree, &point[0], 1U, 3U, varargin_2, 0.0,
                              0.0F, &ptrIndices, &ptrDists, &valid, 1000, 500U);
    d_st.site = &ti_emlrtRSI;
    y = e_sumColumnB(valid);
    if (y != (int32_T)muDoubleScalarFloor(y)) {
      emlrtIntegerCheckR2012b(y, &e_emlrtDCI, &c_st);
    }
    i = indices->size[0];
    indices->size[0] = (int32_T)y;
    emxEnsureCapacity_uint32_T(&c_st, indices, i, &vg_emlrtRTEI);
    indices_data = indices->data;
    d_st.site = &ui_emlrtRSI;
    y = e_sumColumnB(valid);
    if (y != (int32_T)muDoubleScalarFloor(y)) {
      emlrtIntegerCheckR2012b(y, &f_emlrtDCI, &c_st);
    }
    i = dists_->size[0];
    dists_->size[0] = (int32_T)y;
    emxEnsureCapacity_real32_T(&c_st, dists_, i, &ah_emlrtRTEI);
    dists__data = dists_->data;
    kdtreeRadiusSearchSetOutputs_single(ptrIndices, ptrDists, &indices_data[0],
                                        &dists__data[0]);
  }
  b_st.site = &gi_emlrtRSI;
  p = false;
  i = dists_->size[0];
  for (k = 0; k < i; k++) {
    if (p || (dists__data[k] < 0.0F)) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  c_st.site = &dj_emlrtRSI;
  d_st.site = &ej_emlrtRSI;
  if (dists_->size[0] > 2147483646) {
    e_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  emxFree_real32_T(&d_st, &dists_);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void pointCloud_buildKdtree(const emlrtStack *sp, pointCloud *this)
{
  emlrtStack st;
  emxArray_real32_T *location;
  int32_T i;
  int32_T loop_ub;
  real32_T *location_data;
  boolean_T createIndex;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (!this->HasLocationHandleAllocated) {
    void *locationPtr;
    st.site = &wf_emlrtRSI;
    emxInit_real32_T(&st, &location, 2, &nf_emlrtRTEI);
    i = location->size[0] * location->size[1];
    location->size[0] = this->Location->size[0];
    location->size[1] = 3;
    emxEnsureCapacity_real32_T(&st, location, i, &nf_emlrtRTEI);
    location_data = location->data;
    loop_ub = this->Location->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      location_data[i] = this->Location->data[i];
    }
    locationPtr = NULL;
    if (this->Location->size[0] != 0) {
      kdtreeGetLocationDataPointer_single(&location_data[0],
                                          (uint32_T)this->Location->size[0], 3U,
                                          &locationPtr);
    }
    emxFree_real32_T(&st, &location);
    this->LocationHandle = locationPtr;
    this->HasLocationHandleAllocated = true;
  }
  if (!this->HasKdtreeConstructed) {
    this->Kdtree = NULL;
    kdtreeConstruct_single(&this->Kdtree);
    this->HasKdtreeConstructed = true;
    createIndex = true;
  } else {
    createIndex = kdtreeNeedsReindex_single(this->Kdtree, this->LocationHandle);
  }
  if (createIndex) {
    st.site = &ag_emlrtRSI;
    loop_ub = this->Location->size[0];
    if (loop_ub == 0) {
      emlrtErrorWithMessageIdR2018a(&st, &u_emlrtRTEI,
                                    "vision:ocvShared:emptyInput",
                                    "vision:ocvShared:emptyInput", 0);
    }
    kdtreeIndex_single(this->Kdtree, this->LocationHandle, (uint32_T)loop_ub,
                       3U, 4.0, 1.0, 0.0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

pointCloud *pointCloud_pointCloud(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real32_T *varargin_1)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real32_T b_nv_tmp_data;
  emxArray_real32_T c_nv_tmp_data;
  emxArray_real32_T nv_tmp_data;
  emxArray_uint8_T r;
  pointCloud *b_this;
  int32_T b_iv[2];
  int32_T nv_tmp_size[2];
  int32_T i;
  int32_T loop_ub;
  const real32_T *varargin_1_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  varargin_1_data = varargin_1->data;
  b_this = this;
  b_this->HasKdtreeConstructed = false;
  b_this->HasLocationHandleAllocated = false;
  st.site = &x_emlrtRSI;
  nv_tmp_size[0] = 0;
  nv_tmp_size[1] = 0;
  i = b_this->Location->size[0] * b_this->Location->size[1];
  b_this->Location->size[0] = varargin_1->size[0];
  b_this->Location->size[1] = 3;
  emxEnsureCapacity_real32_T(&st, b_this->Location, i, &sd_emlrtRTEI);
  loop_ub = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this->Location->data[i] = varargin_1_data[i];
  }
  b_iv[0] = 0;
  b_iv[1] = 0;
  r.size = &b_iv[0];
  r.allocatedSize = 0;
  r.numDimensions = 2;
  r.canFreeData = false;
  b_st.site = &cb_emlrtRSI;
  pointCloudBase_set_Color(&b_st, b_this, &r);
  nv_tmp_data.size = &nv_tmp_size[0];
  nv_tmp_data.allocatedSize = 0;
  nv_tmp_data.numDimensions = 2;
  nv_tmp_data.canFreeData = false;
  b_st.site = &db_emlrtRSI;
  pointCloudBase_set_Normal(&b_st, b_this, &nv_tmp_data);
  b_nv_tmp_data.size = &nv_tmp_size[0];
  b_nv_tmp_data.allocatedSize = 0;
  b_nv_tmp_data.numDimensions = 2;
  b_nv_tmp_data.canFreeData = false;
  b_st.site = &eb_emlrtRSI;
  pointCloudBase_set_Intensity(&b_st, b_this, &b_nv_tmp_data);
  nv_tmp_size[0] = 0;
  nv_tmp_size[1] = 0;
  c_nv_tmp_data.size = &nv_tmp_size[0];
  c_nv_tmp_data.allocatedSize = 0;
  c_nv_tmp_data.numDimensions = 2;
  c_nv_tmp_data.canFreeData = false;
  b_st.site = &fb_emlrtRSI;
  pointCloudBase_set_RangeData(&b_st, b_this, &c_nv_tmp_data);
  st.site = &y_emlrtRSI;
  b_this->PointCloudArrayData->size[0] = 1;
  b_this->PointCloudArrayData->size[1] = 1;
  st.site = &ab_emlrtRSI;
  b_this->Kdtree = NULL;
  b_this->LocationHandle = NULL;
  b_this->matlabCodegenIsDeleted = false;
  return b_this;
}

pointCloud *pointCloud_select(const emlrtStack *sp, const pointCloud *this,
                              const emxArray_real_T *varargin_1,
                              pointCloud *iobj_0)
{
  static const char_T functionName[6] = {'s', 'e', 'l', 'e', 'c', 't'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_real32_T *b_intensity;
  emxArray_real32_T *intensity;
  emxArray_real32_T *loc;
  emxArray_real32_T *location;
  emxArray_real32_T *normal;
  emxArray_real32_T *nv;
  emxArray_real32_T *r;
  emxArray_real32_T *rangeData;
  emxArray_uint8_T *c;
  emxArray_uint8_T *color;
  pointCloud *ptCloudOut;
  const real_T *varargin_1_data;
  int32_T a;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T last;
  real32_T *intensity_data;
  real32_T *loc_data;
  real32_T *location_data;
  real32_T *normal_data;
  real32_T *rangeData_data;
  uint8_T *c_data;
  uint8_T *color_data;
  boolean_T exitg1;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &mg_emlrtRSI;
  b_st.site = &ng_emlrtRSI;
  n = (this->PointCloudArrayData->size[0] *
           this->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &st, &y_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 6, &functionName[0]);
  }
  st.site = &lg_emlrtRSI;
  b_st.site = &jc_emlrtRSI;
  n = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= varargin_1->size[0] - 1)) {
    if ((!muDoubleScalarIsInf(varargin_1_data[k])) &&
        (!muDoubleScalarIsNaN(varargin_1_data[k])) &&
        (muDoubleScalarFloor(varargin_1_data[k]) == varargin_1_data[k])) {
      k++;
    } else {
      n = false;
      exitg1 = true;
    }
  }
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &x_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:expectedInteger", 3, 4, 5, "input");
  }
  if (varargin_1->size[0] != 0) {
    real_T ex;
    st.site = &kg_emlrtRSI;
    b_st.site = &vd_emlrtRSI;
    c_st.site = &wd_emlrtRSI;
    d_st.site = &xd_emlrtRSI;
    e_st.site = &yd_emlrtRSI;
    f_st.site = &ae_emlrtRSI;
    if (varargin_1->size[0] > 2) {
      g_st.site = &og_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &pg_emlrtRSI;
        if (varargin_1->size[0] > 2147483646) {
          i_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= varargin_1->size[0])) {
          if (!muDoubleScalarIsNaN(varargin_1_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (idx != 0) {
        g_st.site = &be_emlrtRSI;
        h_st.site = &ce_emlrtRSI;
        if ((idx + 1 <= varargin_1->size[0]) &&
            (varargin_1->size[0] > 2147483646)) {
          i_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
      }
    }
    st.site = &kg_emlrtRSI;
    b_st.site = &lf_emlrtRSI;
    c_st.site = &mf_emlrtRSI;
    d_st.site = &nf_emlrtRSI;
    e_st.site = &of_emlrtRSI;
    f_st.site = &pf_emlrtRSI;
    last = varargin_1->size[0];
    if (varargin_1->size[0] <= 2) {
      if (varargin_1->size[0] == 1) {
        ex = varargin_1_data[0];
      } else if ((varargin_1_data[0] < varargin_1_data[1]) ||
                 (muDoubleScalarIsNaN(varargin_1_data[0]) &&
                  (!muDoubleScalarIsNaN(varargin_1_data[1])))) {
        ex = varargin_1_data[1];
      } else {
        ex = varargin_1_data[0];
      }
    } else {
      g_st.site = &og_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &pg_emlrtRSI;
        if (varargin_1->size[0] > 2147483646) {
          i_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(varargin_1_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (idx == 0) {
        ex = varargin_1_data[0];
      } else {
        g_st.site = &be_emlrtRSI;
        ex = varargin_1_data[idx - 1];
        a = idx + 1;
        h_st.site = &ce_emlrtRSI;
        if ((idx + 1 <= varargin_1->size[0]) &&
            (varargin_1->size[0] > 2147483646)) {
          i_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        for (k = a; k <= last; k++) {
          real_T d;
          d = varargin_1_data[k - 1];
          if (ex < d) {
            ex = d;
          }
        }
      }
    }
    st.site = &kg_emlrtRSI;
    idx = this->Location->size[0];
    if (ex > idx) {
      emlrtErrorWithMessageIdR2018a(
          sp, &ab_emlrtRTEI, "vision:pointcloud:indicesOutofRangeForSelect",
          "vision:pointcloud:indicesOutofRangeForSelect", 0);
    }
  }
  st.site = &jg_emlrtRSI;
  b_st.site = &qg_emlrtRSI;
  emxInit_real32_T(&b_st, &location, 2, &qf_emlrtRTEI);
  k = location->size[0] * location->size[1];
  location->size[0] = this->Location->size[0];
  location->size[1] = 3;
  emxEnsureCapacity_real32_T(&b_st, location, k, &qf_emlrtRTEI);
  location_data = location->data;
  idx = this->Location->size[0] * 3;
  for (k = 0; k < idx; k++) {
    location_data[k] = this->Location->data[k];
  }
  emxInit_uint8_T(&b_st, &color, &rf_emlrtRTEI);
  k = color->size[0] * color->size[1];
  color->size[0] = this->Color->size[0];
  color->size[1] = this->Color->size[1];
  emxEnsureCapacity_uint8_T(&b_st, color, k, &rf_emlrtRTEI);
  color_data = color->data;
  idx = this->Color->size[0] * this->Color->size[1];
  for (k = 0; k < idx; k++) {
    color_data[k] = this->Color->data[k];
  }
  emxInit_real32_T(&b_st, &normal, 2, &sf_emlrtRTEI);
  k = normal->size[0] * normal->size[1];
  normal->size[0] = this->Normal->size[0];
  normal->size[1] = this->Normal->size[1];
  emxEnsureCapacity_real32_T(&b_st, normal, k, &sf_emlrtRTEI);
  normal_data = normal->data;
  idx = this->Normal->size[0] * this->Normal->size[1];
  for (k = 0; k < idx; k++) {
    normal_data[k] = this->Normal->data[k];
  }
  emxInit_real32_T(&b_st, &intensity, 2, &tf_emlrtRTEI);
  k = intensity->size[0] * intensity->size[1];
  intensity->size[0] = this->Intensity->size[0];
  intensity->size[1] = this->Intensity->size[1];
  emxEnsureCapacity_real32_T(&b_st, intensity, k, &tf_emlrtRTEI);
  intensity_data = intensity->data;
  idx = this->Intensity->size[0] * this->Intensity->size[1];
  for (k = 0; k < idx; k++) {
    intensity_data[k] = this->Intensity->data[k];
  }
  emxInit_real32_T(&b_st, &rangeData, 2, &uf_emlrtRTEI);
  k = rangeData->size[0] * rangeData->size[1];
  rangeData->size[0] = this->RangeData->size[0];
  rangeData->size[1] = this->RangeData->size[1];
  emxEnsureCapacity_real32_T(&b_st, rangeData, k, &uf_emlrtRTEI);
  rangeData_data = rangeData->data;
  idx = this->RangeData->size[0] * this->RangeData->size[1];
  for (k = 0; k < idx; k++) {
    rangeData_data[k] = this->RangeData->data[k];
  }
  emxInit_real32_T(&b_st, &loc, 2, &wf_emlrtRTEI);
  if (location->size[0] != 0) {
    k = loc->size[0] * loc->size[1];
    loc->size[0] = varargin_1->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real32_T(&b_st, loc, k, &vf_emlrtRTEI);
    loc_data = loc->data;
    idx = varargin_1->size[0];
    for (k = 0; k < 3; k++) {
      for (i = 0; i < idx; i++) {
        last = (int32_T)varargin_1_data[i];
        if ((last < 1) || (last > location->size[0])) {
          emlrtDynamicBoundsCheckR2012b(last, 1, location->size[0], &m_emlrtBCI,
                                        &b_st);
        }
        loc_data[i + loc->size[0] * k] =
            location_data[(last + location->size[0] * k) - 1];
      }
    }
  } else {
    loc->size[0] = 0;
    loc->size[1] = 3;
  }
  emxFree_real32_T(&b_st, &location);
  emxInit_uint8_T(&b_st, &c, &wf_emlrtRTEI);
  if ((color->size[0] != 0) && (color->size[1] != 0)) {
    k = c->size[0] * c->size[1];
    c->size[0] = varargin_1->size[0];
    c->size[1] = color->size[1];
    emxEnsureCapacity_uint8_T(&b_st, c, k, &vf_emlrtRTEI);
    c_data = c->data;
    idx = color->size[1];
    for (k = 0; k < idx; k++) {
      a = varargin_1->size[0];
      for (i = 0; i < a; i++) {
        last = (int32_T)varargin_1_data[i];
        if ((last < 1) || (last > color->size[0])) {
          emlrtDynamicBoundsCheckR2012b(last, 1, color->size[0], &m_emlrtBCI,
                                        &b_st);
        }
        c_data[i + c->size[0] * k] =
            color_data[(last + color->size[0] * k) - 1];
      }
    }
  } else {
    c->size[0] = 0;
    c->size[1] = 0;
  }
  emxFree_uint8_T(&b_st, &color);
  emxInit_real32_T(&b_st, &nv, 2, &wf_emlrtRTEI);
  if ((normal->size[0] != 0) && (normal->size[1] != 0)) {
    k = nv->size[0] * nv->size[1];
    nv->size[0] = varargin_1->size[0];
    nv->size[1] = normal->size[1];
    emxEnsureCapacity_real32_T(&b_st, nv, k, &vf_emlrtRTEI);
    location_data = nv->data;
    idx = normal->size[1];
    for (k = 0; k < idx; k++) {
      a = varargin_1->size[0];
      for (i = 0; i < a; i++) {
        last = (int32_T)varargin_1_data[i];
        if ((last < 1) || (last > normal->size[0])) {
          emlrtDynamicBoundsCheckR2012b(last, 1, normal->size[0], &m_emlrtBCI,
                                        &b_st);
        }
        location_data[i + nv->size[0] * k] =
            normal_data[(last + normal->size[0] * k) - 1];
      }
    }
  } else {
    nv->size[0] = 0;
    nv->size[1] = 0;
  }
  emxFree_real32_T(&b_st, &normal);
  emxInit_real32_T(&b_st, &b_intensity, 2, &wf_emlrtRTEI);
  if ((intensity->size[0] != 0) && (intensity->size[1] != 0)) {
    k = b_intensity->size[0] * b_intensity->size[1];
    b_intensity->size[0] = varargin_1->size[0];
    b_intensity->size[1] = intensity->size[1];
    emxEnsureCapacity_real32_T(&b_st, b_intensity, k, &vf_emlrtRTEI);
    location_data = b_intensity->data;
    idx = intensity->size[1];
    for (k = 0; k < idx; k++) {
      a = varargin_1->size[0];
      for (i = 0; i < a; i++) {
        last = (int32_T)varargin_1_data[i];
        if ((last < 1) || (last > intensity->size[0])) {
          emlrtDynamicBoundsCheckR2012b(last, 1, intensity->size[0],
                                        &m_emlrtBCI, &b_st);
        }
        location_data[i + b_intensity->size[0] * k] =
            intensity_data[(last + intensity->size[0] * k) - 1];
      }
    }
  } else {
    b_intensity->size[0] = 0;
    b_intensity->size[1] = 0;
  }
  emxFree_real32_T(&b_st, &intensity);
  emxInit_real32_T(&b_st, &r, 2, &wf_emlrtRTEI);
  if ((rangeData->size[0] != 0) && (rangeData->size[1] != 0)) {
    k = r->size[0] * r->size[1];
    r->size[0] = varargin_1->size[0];
    r->size[1] = rangeData->size[1];
    emxEnsureCapacity_real32_T(&b_st, r, k, &vf_emlrtRTEI);
    location_data = r->data;
    idx = rangeData->size[1];
    for (k = 0; k < idx; k++) {
      a = varargin_1->size[0];
      for (i = 0; i < a; i++) {
        last = (int32_T)varargin_1_data[i];
        if ((last < 1) || (last > rangeData->size[0])) {
          emlrtDynamicBoundsCheckR2012b(last, 1, rangeData->size[0],
                                        &m_emlrtBCI, &b_st);
        }
        location_data[i + r->size[0] * k] =
            rangeData_data[(last + rangeData->size[0] * k) - 1];
      }
    }
  } else {
    r->size[0] = 0;
    r->size[1] = 0;
  }
  emxFree_real32_T(&b_st, &rangeData);
  st.site = &ig_emlrtRSI;
  ptCloudOut = b_pointCloud_pointCloud(&st, iobj_0, loc, c, nv, b_intensity);
  emxFree_real32_T(sp, &b_intensity);
  emxFree_real32_T(sp, &nv);
  emxFree_uint8_T(sp, &c);
  emxFree_real32_T(sp, &loc);
  st.site = &hg_emlrtRSI;
  pointCloudBase_set_RangeData(&st, ptCloudOut, r);
  emxFree_real32_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return ptCloudOut;
}

/* End of code generation (pointCloud.c) */
