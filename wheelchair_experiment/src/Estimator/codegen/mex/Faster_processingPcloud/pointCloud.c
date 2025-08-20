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
#include "Faster_processingPcloud_data.h"
#include "Faster_processingPcloud_emxutil.h"
#include "Faster_processingPcloud_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "pointCloudBase.h"
#include "rt_nonfinite.h"
#include "cvstCG_kdtree.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = {
    33,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    34,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    43,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    75,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    87,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    88,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    89,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    90,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    139,                         /* lineNo */
    "pointCloudBase/set.Normal", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo le_emlrtRSI = {
    842,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo oe_emlrtRSI = {
    860,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    144,                            /* lineNo */
    "pointCloudBase/set.Intensity", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo we_emlrtRSI = {
    230,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo xe_emlrtRSI = {
    228,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ye_emlrtRSI = {
    220,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo af_emlrtRSI = {
    166,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo bf_emlrtRSI = {
    162,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo cf_emlrtRSI = {
    154,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    69,                            /* lineNo */
    13,                            /* colNo */
    "kdtreeBuildable/kdtreeIndex", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    819,                             /* lineNo */
    13,                              /* colNo */
    "pointCloudBase/validateNormal", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    720,                                /* lineNo */
    21,                                 /* colNo */
    "pointCloudBase/validateIntensity", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    13,                /* lineNo */
    37,                /* colNo */
    "validateinteger", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validateinteger.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    166,                 /* lineNo */
    21,                  /* colNo */
    "pointCloud/select", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    85,               /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    842,          /* lineNo */
    110,          /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    139,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    144,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    208,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    208,              /* lineNo */
    32,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    208,              /* lineNo */
    62,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    209,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    209,              /* lineNo */
    33,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    149,          /* lineNo */
    31,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

/* Function Definitions */
pointCloud *b_pointCloud_pointCloud(const emlrtStack *sp, pointCloud *b_this,
                                    const emxArray_real_T *varargin_1,
                                    const emxArray_uint8_T *varargin_3,
                                    const emxArray_real_T *varargin_5,
                                    const emxArray_real_T *varargin_7)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T tmp_data;
  pointCloud *c_this;
  const real_T *varargin_1_data;
  const real_T *varargin_5_data;
  const real_T *varargin_7_data;
  int32_T tmp_size[2];
  int32_T i;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  varargin_7_data = varargin_7->data;
  varargin_5_data = varargin_5->data;
  varargin_1_data = varargin_1->data;
  c_this = b_this;
  c_this->HasKdtreeConstructed = false;
  c_this->HasLocationHandleAllocated = false;
  st.site = &l_emlrtRSI;
  b_st.site = &o_emlrtRSI;
  i = c_this->Location->size[0] * c_this->Location->size[1];
  c_this->Location->size[0] = varargin_1->size[0];
  c_this->Location->size[1] = 3;
  emxEnsureCapacity_real_T(&st, c_this->Location, i, &fb_emlrtRTEI);
  loop_ub_tmp = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub_tmp; i++) {
    c_this->Location->data[i] = varargin_1_data[i];
  }
  b_st.site = &p_emlrtRSI;
  pointCloudBase_set_Color(&b_st, c_this, varargin_3);
  b_st.site = &q_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  loop_ub_tmp = c_this->Location->size[0];
  if ((varargin_5->size[0] != 0) && (varargin_5->size[1] != 0)) {
    uint32_T b_varargin_1[2];
    uint32_T varargin_2[2];
    boolean_T exitg1;
    boolean_T p;
    b_varargin_1[0] = (uint32_T)varargin_5->size[0];
    varargin_2[0] = (uint32_T)loop_ub_tmp;
    b_varargin_1[1] = (uint32_T)varargin_5->size[1];
    varargin_2[1] = 3U;
    p = true;
    loop_ub_tmp = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub_tmp < 2)) {
      if ((int32_T)b_varargin_1[loop_ub_tmp] !=
          (int32_T)varargin_2[loop_ub_tmp]) {
        p = false;
        exitg1 = true;
      } else {
        loop_ub_tmp++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZNormal",
                                    "vision:pointcloud:unmatchedXYZNormal", 0);
    }
  }
  i = c_this->Normal->size[0] * c_this->Normal->size[1];
  c_this->Normal->size[0] = varargin_5->size[0];
  c_this->Normal->size[1] = varargin_5->size[1];
  emxEnsureCapacity_real_T(&b_st, c_this->Normal, i, &rc_emlrtRTEI);
  loop_ub_tmp = varargin_5->size[0] * varargin_5->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    c_this->Normal->data[i] = varargin_5_data[i];
  }
  b_st.site = &r_emlrtRSI;
  c_st.site = &pe_emlrtRSI;
  loop_ub_tmp = c_this->Location->size[0];
  if ((varargin_7->size[0] != 0) && (varargin_7->size[1] != 0) &&
      ((varargin_7->size[1] != 1) || (varargin_7->size[0] != loop_ub_tmp))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &p_emlrtRTEI,
                                  "vision:pointcloud:unmatchedXYZIntensity",
                                  "vision:pointcloud:unmatchedXYZIntensity", 0);
  }
  i = c_this->Intensity->size[0] * c_this->Intensity->size[1];
  c_this->Intensity->size[0] = varargin_7->size[0];
  c_this->Intensity->size[1] = varargin_7->size[1];
  emxEnsureCapacity_real_T(&b_st, c_this->Intensity, i, &sc_emlrtRTEI);
  loop_ub_tmp = varargin_7->size[0] * varargin_7->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    c_this->Intensity->data[i] = varargin_7_data[i];
  }
  tmp_size[0] = 0;
  tmp_size[1] = 0;
  tmp_data.size = &tmp_size[0];
  tmp_data.allocatedSize = 0;
  tmp_data.numDimensions = 2;
  tmp_data.canFreeData = false;
  b_st.site = &s_emlrtRSI;
  pointCloudBase_set_RangeData(&b_st, c_this, &tmp_data);
  st.site = &m_emlrtRSI;
  c_this->PointCloudArrayData->size[0] = 1;
  c_this->PointCloudArrayData->size[1] = 1;
  st.site = &n_emlrtRSI;
  c_this->Kdtree = NULL;
  c_this->LocationHandle = NULL;
  c_this->matlabCodegenIsDeleted = false;
  return c_this;
}

void pointCloud_buildKdtree(const emlrtStack *sp, pointCloud *b_this)
{
  void *kdtreeObj;
  void *locationPtr;
  emlrtStack st;
  emxArray_real_T *location;
  real_T *location_data;
  int32_T i;
  int32_T loop_ub;
  boolean_T createIndex;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (!b_this->HasLocationHandleAllocated) {
    st.site = &le_emlrtRSI;
    emxInit_real_T(&st, &location, 2, &qc_emlrtRTEI);
    i = location->size[0] * location->size[1];
    location->size[0] = b_this->Location->size[0];
    location->size[1] = 3;
    emxEnsureCapacity_real_T(&st, location, i, &qc_emlrtRTEI);
    location_data = location->data;
    loop_ub = b_this->Location->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      location_data[i] = b_this->Location->data[i];
    }
    locationPtr = NULL;
    if (location->size[0] != 0) {
      kdtreeGetLocationDataPointer_double(
          &location_data[0], (uint32_T)location->size[0], 3U, &locationPtr);
    }
    emxFree_real_T(&st, &location);
    b_this->LocationHandle = locationPtr;
    b_this->HasLocationHandleAllocated = true;
  }
  if (!b_this->HasKdtreeConstructed) {
    locationPtr = NULL;
    kdtreeConstruct_double(&locationPtr);
    b_this->Kdtree = locationPtr;
    b_this->HasKdtreeConstructed = true;
    createIndex = true;
  } else {
    kdtreeObj = b_this->Kdtree;
    locationPtr = b_this->LocationHandle;
    createIndex = kdtreeNeedsReindex_double(kdtreeObj, locationPtr);
  }
  if (createIndex) {
    st.site = &oe_emlrtRSI;
    kdtreeObj = b_this->Kdtree;
    locationPtr = b_this->LocationHandle;
    loop_ub = b_this->Location->size[0];
    if (loop_ub == 0) {
      emlrtErrorWithMessageIdR2018a(&st, &n_emlrtRTEI,
                                    "vision:ocvShared:emptyInput",
                                    "vision:ocvShared:emptyInput", 0);
    }
    kdtreeIndex_double(kdtreeObj, locationPtr, (uint32_T)loop_ub, 3U, 10.0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

pointCloud *pointCloud_pointCloud(const emlrtStack *sp, pointCloud *b_this,
                                  const emxArray_real_T *varargin_1)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T normal_tmp_data;
  emxArray_uint8_T r;
  pointCloud *c_this;
  const real_T *varargin_1_data;
  int32_T iv[2];
  int32_T normal_tmp_size[2];
  int32_T i;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  varargin_1_data = varargin_1->data;
  c_this = b_this;
  c_this->HasKdtreeConstructed = false;
  c_this->HasLocationHandleAllocated = false;
  st.site = &l_emlrtRSI;
  i = c_this->Location->size[0] * c_this->Location->size[1];
  c_this->Location->size[0] = varargin_1->size[0];
  c_this->Location->size[1] = 3;
  emxEnsureCapacity_real_T(&st, c_this->Location, i, &fb_emlrtRTEI);
  loop_ub_tmp = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub_tmp; i++) {
    c_this->Location->data[i] = varargin_1_data[i];
  }
  iv[0] = 0;
  iv[1] = 0;
  r.size = &iv[0];
  r.allocatedSize = 0;
  r.numDimensions = 2;
  r.canFreeData = false;
  b_st.site = &p_emlrtRSI;
  pointCloudBase_set_Color(&b_st, c_this, &r);
  c_this->Normal->size[0] = 0;
  c_this->Normal->size[1] = 0;
  c_this->Intensity->size[0] = 0;
  c_this->Intensity->size[1] = 0;
  normal_tmp_size[0] = 0;
  normal_tmp_size[1] = 0;
  normal_tmp_data.size = &normal_tmp_size[0];
  normal_tmp_data.allocatedSize = 0;
  normal_tmp_data.numDimensions = 2;
  normal_tmp_data.canFreeData = false;
  b_st.site = &s_emlrtRSI;
  pointCloudBase_set_RangeData(&b_st, c_this, &normal_tmp_data);
  st.site = &m_emlrtRSI;
  c_this->PointCloudArrayData->size[0] = 1;
  c_this->PointCloudArrayData->size[1] = 1;
  st.site = &n_emlrtRSI;
  c_this->Kdtree = NULL;
  c_this->LocationHandle = NULL;
  c_this->matlabCodegenIsDeleted = false;
  return c_this;
}

pointCloud *pointCloud_select(const emlrtStack *sp, const pointCloud *b_this,
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
  emxArray_real_T *b_intensity;
  emxArray_real_T *intensity;
  emxArray_real_T *loc;
  emxArray_real_T *location;
  emxArray_real_T *normal;
  emxArray_real_T *nv;
  emxArray_real_T *r;
  emxArray_real_T *rangeData;
  emxArray_uint8_T *c;
  emxArray_uint8_T *color;
  pointCloud *ptCloudOut;
  const real_T *varargin_1_data;
  real_T *intensity_data;
  real_T *loc_data;
  real_T *location_data;
  real_T *normal_data;
  real_T *rangeData_data;
  int32_T a;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T idx;
  int32_T k;
  int32_T last;
  int32_T loop_ub;
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
  st.site = &cf_emlrtRSI;
  b_st.site = &df_emlrtRSI;
  n = (b_this->PointCloudArrayData->size[0] *
           b_this->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &st, &t_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 6, &functionName[0]);
  }
  st.site = &bf_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  n = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= varargin_1->size[0] - 1)) {
    if ((!muDoubleScalarIsInf(varargin_1_data[k])) &&
        (!muDoubleScalarIsNaN(varargin_1_data[k])) &&
        (varargin_1_data[k] == varargin_1_data[k])) {
      k++;
    } else {
      n = false;
      exitg1 = true;
    }
  }
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &s_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:expectedInteger", 3, 4, 5, "input");
  }
  if (varargin_1->size[0] != 0) {
    real_T ex;
    st.site = &af_emlrtRSI;
    b_st.site = &ef_emlrtRSI;
    c_st.site = &ff_emlrtRSI;
    d_st.site = &gf_emlrtRSI;
    e_st.site = &hf_emlrtRSI;
    f_st.site = &if_emlrtRSI;
    if (varargin_1->size[0] > 2) {
      g_st.site = &kf_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &lf_emlrtRSI;
        if (varargin_1->size[0] > 2147483646) {
          i_st.site = &ab_emlrtRSI;
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
        g_st.site = &jf_emlrtRSI;
        h_st.site = &mf_emlrtRSI;
        if ((idx + 1 <= varargin_1->size[0]) &&
            (varargin_1->size[0] > 2147483646)) {
          i_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
      }
    }
    st.site = &af_emlrtRSI;
    b_st.site = &nf_emlrtRSI;
    c_st.site = &of_emlrtRSI;
    d_st.site = &pf_emlrtRSI;
    e_st.site = &qf_emlrtRSI;
    f_st.site = &rf_emlrtRSI;
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
      g_st.site = &kf_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &lf_emlrtRSI;
        if (varargin_1->size[0] > 2147483646) {
          i_st.site = &ab_emlrtRSI;
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
        g_st.site = &jf_emlrtRSI;
        ex = varargin_1_data[idx - 1];
        a = idx + 1;
        h_st.site = &mf_emlrtRSI;
        if ((idx + 1 <= varargin_1->size[0]) &&
            (varargin_1->size[0] > 2147483646)) {
          i_st.site = &ab_emlrtRSI;
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
    st.site = &af_emlrtRSI;
    idx = b_this->Location->size[0];
    if (ex > idx) {
      emlrtErrorWithMessageIdR2018a(
          sp, &u_emlrtRTEI, "vision:pointcloud:indicesOutofRangeForSelect",
          "vision:pointcloud:indicesOutofRangeForSelect", 0);
    }
  }
  st.site = &ye_emlrtRSI;
  b_st.site = &sf_emlrtRSI;
  emxInit_real_T(&b_st, &location, 2, &vc_emlrtRTEI);
  i = b_this->Location->size[0];
  i1 = location->size[0] * location->size[1];
  location->size[0] = i;
  location->size[1] = 3;
  emxEnsureCapacity_real_T(&b_st, location, i1, &vc_emlrtRTEI);
  location_data = location->data;
  idx = b_this->Location->size[0] * 3;
  for (i1 = 0; i1 < idx; i1++) {
    location_data[i1] = b_this->Location->data[i1];
  }
  emxInit_uint8_T(&b_st, &color, &wc_emlrtRTEI);
  i1 = b_this->Color->size[0];
  i2 = color->size[0] * color->size[1];
  color->size[0] = i1;
  idx = b_this->Color->size[1];
  color->size[1] = idx;
  emxEnsureCapacity_uint8_T(&b_st, color, i2, &wc_emlrtRTEI);
  color_data = color->data;
  last = b_this->Color->size[0] * b_this->Color->size[1];
  for (i2 = 0; i2 < last; i2++) {
    color_data[i2] = b_this->Color->data[i2];
  }
  emxInit_real_T(&b_st, &normal, 2, &xc_emlrtRTEI);
  i2 = b_this->Normal->size[0];
  i3 = normal->size[0] * normal->size[1];
  normal->size[0] = i2;
  last = b_this->Normal->size[1];
  normal->size[1] = last;
  emxEnsureCapacity_real_T(&b_st, normal, i3, &xc_emlrtRTEI);
  normal_data = normal->data;
  a = b_this->Normal->size[0] * b_this->Normal->size[1];
  for (i3 = 0; i3 < a; i3++) {
    normal_data[i3] = b_this->Normal->data[i3];
  }
  emxInit_real_T(&b_st, &intensity, 2, &yc_emlrtRTEI);
  i3 = b_this->Intensity->size[0];
  i4 = intensity->size[0] * intensity->size[1];
  intensity->size[0] = i3;
  a = b_this->Intensity->size[1];
  intensity->size[1] = a;
  emxEnsureCapacity_real_T(&b_st, intensity, i4, &yc_emlrtRTEI);
  intensity_data = intensity->data;
  k = b_this->Intensity->size[0] * b_this->Intensity->size[1];
  for (i4 = 0; i4 < k; i4++) {
    intensity_data[i4] = b_this->Intensity->data[i4];
  }
  emxInit_real_T(&b_st, &rangeData, 2, &ad_emlrtRTEI);
  i4 = b_this->RangeData->size[0];
  i5 = rangeData->size[0] * rangeData->size[1];
  rangeData->size[0] = i4;
  k = b_this->RangeData->size[1];
  rangeData->size[1] = k;
  emxEnsureCapacity_real_T(&b_st, rangeData, i5, &ad_emlrtRTEI);
  rangeData_data = rangeData->data;
  loop_ub = b_this->RangeData->size[0] * b_this->RangeData->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    rangeData_data[i5] = b_this->RangeData->data[i5];
  }
  emxInit_real_T(&b_st, &loc, 2, &cd_emlrtRTEI);
  if (location->size[0] != 0) {
    loop_ub = varargin_1->size[0];
    i5 = loc->size[0] * loc->size[1];
    loc->size[0] = varargin_1->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(&b_st, loc, i5, &bd_emlrtRTEI);
    loc_data = loc->data;
    for (i5 = 0; i5 < 3; i5++) {
      for (i6 = 0; i6 < loop_ub; i6++) {
        int32_T i7;
        i7 = (int32_T)varargin_1_data[i6];
        if ((i7 < 1) || (i7 > i)) {
          emlrtDynamicBoundsCheckR2012b(i7, 1, i, &m_emlrtBCI, &b_st);
        }
        loc_data[i6 + loc->size[0] * i5] =
            location_data[(i7 + location->size[0] * i5) - 1];
      }
    }
  } else {
    loc->size[0] = 0;
    loc->size[1] = 3;
  }
  emxFree_real_T(&b_st, &location);
  emxInit_uint8_T(&b_st, &c, &cd_emlrtRTEI);
  if ((color->size[0] != 0) && (color->size[1] != 0)) {
    loop_ub = varargin_1->size[0];
    i = c->size[0] * c->size[1];
    c->size[0] = varargin_1->size[0];
    c->size[1] = idx;
    emxEnsureCapacity_uint8_T(&b_st, c, i, &bd_emlrtRTEI);
    c_data = c->data;
    for (i = 0; i < idx; i++) {
      for (i5 = 0; i5 < loop_ub; i5++) {
        i6 = (int32_T)varargin_1_data[i5];
        if ((i6 < 1) || (i6 > i1)) {
          emlrtDynamicBoundsCheckR2012b(i6, 1, i1, &m_emlrtBCI, &b_st);
        }
        c_data[i5 + c->size[0] * i] = color_data[(i6 + color->size[0] * i) - 1];
      }
    }
  } else {
    c->size[0] = 0;
    c->size[1] = 0;
  }
  emxFree_uint8_T(&b_st, &color);
  emxInit_real_T(&b_st, &nv, 2, &cd_emlrtRTEI);
  if ((normal->size[0] != 0) && (normal->size[1] != 0)) {
    idx = varargin_1->size[0];
    i = nv->size[0] * nv->size[1];
    nv->size[0] = varargin_1->size[0];
    nv->size[1] = last;
    emxEnsureCapacity_real_T(&b_st, nv, i, &bd_emlrtRTEI);
    location_data = nv->data;
    for (i = 0; i < last; i++) {
      for (i1 = 0; i1 < idx; i1++) {
        i5 = (int32_T)varargin_1_data[i1];
        if ((i5 < 1) || (i5 > i2)) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, i2, &m_emlrtBCI, &b_st);
        }
        location_data[i1 + nv->size[0] * i] =
            normal_data[(i5 + normal->size[0] * i) - 1];
      }
    }
  } else {
    nv->size[0] = 0;
    nv->size[1] = 0;
  }
  emxFree_real_T(&b_st, &normal);
  emxInit_real_T(&b_st, &b_intensity, 2, &cd_emlrtRTEI);
  if ((intensity->size[0] != 0) && (intensity->size[1] != 0)) {
    idx = varargin_1->size[0];
    i = b_intensity->size[0] * b_intensity->size[1];
    b_intensity->size[0] = varargin_1->size[0];
    b_intensity->size[1] = a;
    emxEnsureCapacity_real_T(&b_st, b_intensity, i, &bd_emlrtRTEI);
    location_data = b_intensity->data;
    for (i = 0; i < a; i++) {
      for (i1 = 0; i1 < idx; i1++) {
        i2 = (int32_T)varargin_1_data[i1];
        if ((i2 < 1) || (i2 > i3)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i3, &m_emlrtBCI, &b_st);
        }
        location_data[i1 + b_intensity->size[0] * i] =
            intensity_data[(i2 + intensity->size[0] * i) - 1];
      }
    }
  } else {
    b_intensity->size[0] = 0;
    b_intensity->size[1] = 0;
  }
  emxFree_real_T(&b_st, &intensity);
  emxInit_real_T(&b_st, &r, 2, &cd_emlrtRTEI);
  if ((rangeData->size[0] != 0) && (rangeData->size[1] != 0)) {
    idx = varargin_1->size[0];
    i = r->size[0] * r->size[1];
    r->size[0] = varargin_1->size[0];
    r->size[1] = k;
    emxEnsureCapacity_real_T(&b_st, r, i, &bd_emlrtRTEI);
    location_data = r->data;
    for (i = 0; i < k; i++) {
      for (i1 = 0; i1 < idx; i1++) {
        i2 = (int32_T)varargin_1_data[i1];
        if ((i2 < 1) || (i2 > i4)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i4, &m_emlrtBCI, &b_st);
        }
        location_data[i1 + r->size[0] * i] =
            rangeData_data[(i2 + rangeData->size[0] * i) - 1];
      }
    }
  } else {
    r->size[0] = 0;
    r->size[1] = 0;
  }
  emxFree_real_T(&b_st, &rangeData);
  st.site = &xe_emlrtRSI;
  ptCloudOut = b_pointCloud_pointCloud(&st, iobj_0, loc, c, nv, b_intensity);
  emxFree_real_T(sp, &b_intensity);
  emxFree_real_T(sp, &nv);
  emxFree_uint8_T(sp, &c);
  emxFree_real_T(sp, &loc);
  st.site = &we_emlrtRSI;
  pointCloudBase_set_RangeData(&st, ptCloudOut, r);
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return ptCloudOut;
}

/* End of code generation (pointCloud.c) */
