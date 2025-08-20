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
#include "pointCloudBase.h"
#include "removePlane_BBox_data.h"
#include "removePlane_BBox_emxutil.h"
#include "removePlane_BBox_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = {
    33,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    34,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    43,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    75,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    87,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    88,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    89,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    90,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    139,                         /* lineNo */
    "pointCloudBase/set.Normal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    236,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    239,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    241,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    299,                             /* lineNo */
    "pointCloud/extractValidPoints", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    302,                             /* lineNo */
    "pointCloud/extractValidPoints", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    303,                             /* lineNo */
    "pointCloud/extractValidPoints", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    509,                                /* lineNo */
    "pointCloudBase/arrayNotSupported", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    430,                                     /* lineNo */
    "pointCloudBase/extractValidPointsImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    15,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

static emlrtRSInfo rb_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    138,                     /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    182,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    200,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    207,                         /* lineNo */
    "pointCloudBase/subsetImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    144,                            /* lineNo */
    "pointCloudBase/set.Intensity", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    707,                                /* lineNo */
    21,                                 /* colNo */
    "pointCloudBase/validateIntensity", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    790,                             /* lineNo */
    13,                              /* colNo */
    "pointCloudBase/validateNormal", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    510,                                /* lineNo */
    17,                                 /* colNo */
    "pointCloudBase/arrayNotSupported", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    1,           /* lineNo */
    1,           /* colNo */
    "",          /* aName */
    "getSubset", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+pc\\getSubset.p", /* pName */
    0                             /* checkKind */
};

static emlrtRTEInfo x_emlrtRTEI = {
    85,               /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    427,              /* lineNo */
    27,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    427,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    170,                     /* lineNo */
    24,                      /* colNo */
    "combineVectorElements", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    208,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    208,              /* lineNo */
    32,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    208,              /* lineNo */
    62,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    209,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    209,              /* lineNo */
    33,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    234,          /* lineNo */
    45,           /* colNo */
    "pointCloud", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    1,           /* lineNo */
    1,           /* colNo */
    "getSubset", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+pc\\getSubset.p" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    139,              /* lineNo */
    12,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    144,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    15,    /* lineNo */
    9,     /* colNo */
    "sum", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pName
                                                                        */
};

/* Function Definitions */
pointCloud *pointCloud_pointCloud(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *varargin_1)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T normal_tmp_data;
  emxArray_uint8_T r;
  pointCloud *b_this;
  const real_T *varargin_1_data;
  int32_T iv[2];
  int32_T normal_tmp_size[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  varargin_1_data = varargin_1->data;
  b_this = this;
  b_this->HasKdtreeConstructed = false;
  b_this->HasLocationHandleAllocated = false;
  st.site = &d_emlrtRSI;
  i = b_this->Location->size[0] * b_this->Location->size[1];
  b_this->Location->size[0] = varargin_1->size[0];
  b_this->Location->size[1] = 3;
  emxEnsureCapacity_real_T(&st, b_this->Location, i, &x_emlrtRTEI);
  loop_ub = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this->Location->data[i] = varargin_1_data[i];
  }
  iv[0] = 0;
  iv[1] = 0;
  r.size = &iv[0];
  r.allocatedSize = 0;
  r.numDimensions = 2;
  r.canFreeData = false;
  b_st.site = &h_emlrtRSI;
  pointCloudBase_set_Color(&b_st, b_this, &r);
  b_this->Normal->size[0] = 0;
  b_this->Normal->size[1] = 0;
  b_this->Intensity->size[0] = 0;
  b_this->Intensity->size[1] = 0;
  normal_tmp_size[0] = 0;
  normal_tmp_size[1] = 0;
  normal_tmp_data.size = &normal_tmp_size[0];
  normal_tmp_data.allocatedSize = 0;
  normal_tmp_data.numDimensions = 2;
  normal_tmp_data.canFreeData = false;
  b_st.site = &k_emlrtRSI;
  pointCloudBase_set_RangeData(&b_st, b_this, &normal_tmp_data);
  st.site = &e_emlrtRSI;
  b_this->PointCloudArrayData->size[0] = 1;
  b_this->PointCloudArrayData->size[1] = 1;
  st.site = &f_emlrtRSI;
  b_this->Kdtree = NULL;
  b_this->LocationHandle = NULL;
  b_this->matlabCodegenIsDeleted = false;
  return b_this;
}

pointCloud *pointCloud_removeInvalidPoints(const emlrtStack *sp,
                                           const pointCloud *this,
                                           pointCloud *iobj_0)
{
  static const char_T functionName[19] = {'r', 'e', 'm', 'o', 'v', 'e', 'I',
                                          'n', 'v', 'a', 'l', 'i', 'd', 'P',
                                          'o', 'i', 'n', 't', 's'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *tf;
  emxArray_int32_T *nz;
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_real_T tmp_data;
  emxArray_real_T *b_intensity;
  emxArray_real_T *intensity;
  emxArray_real_T *loc;
  emxArray_real_T *normal;
  emxArray_real_T *nv;
  emxArray_real_T *rangeData;
  emxArray_real_T *x;
  emxArray_uint8_T *c;
  emxArray_uint8_T *color;
  pointCloud *ptCloudOut;
  real_T *b_intensity_data;
  real_T *intensity_data;
  real_T *loc_data;
  real_T *normal_data;
  real_T *rangeData_data;
  real_T *x_data;
  int32_T tmp_size[2];
  int32_T j;
  int32_T k;
  int32_T vstride;
  int32_T xoffset;
  int32_T *nz_data;
  int32_T *r1;
  uint8_T *c_data;
  uint8_T *color_data;
  boolean_T n;
  boolean_T *tf_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ib_emlrtRSI;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &ob_emlrtRSI;
  n = (this->PointCloudArrayData->size[0] *
           this->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &m_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 19, &functionName[0]);
  }
  b_st.site = &mb_emlrtRSI;
  emxInit_real_T(&b_st, &x, 2, &cb_emlrtRTEI);
  k = x->size[0] * x->size[1];
  x->size[0] = this->Location->size[0];
  x->size[1] = 3;
  emxEnsureCapacity_real_T(&b_st, x, k, &cb_emlrtRTEI);
  x_data = x->data;
  xoffset = this->Location->size[0] * 3;
  for (k = 0; k < xoffset; k++) {
    x_data[k] = this->Location->data[k];
  }
  emxInit_boolean_T(&b_st, &tf, 2, &db_emlrtRTEI);
  k = tf->size[0] * tf->size[1];
  tf->size[0] = x->size[0];
  tf->size[1] = 3;
  emxEnsureCapacity_boolean_T(&b_st, tf, k, &db_emlrtRTEI);
  tf_data = tf->data;
  xoffset = x->size[0] * 3;
  for (k = 0; k < xoffset; k++) {
    tf_data[k] = ((!muDoubleScalarIsInf(x_data[k])) &&
                  (!muDoubleScalarIsNaN(x_data[k])));
  }
  c_st.site = &pb_emlrtRSI;
  d_st.site = &qb_emlrtRSI;
  e_st.site = &rb_emlrtRSI;
  emxInit_int32_T(&e_st, &nz, &ob_emlrtRTEI);
  nz_data = nz->data;
  if (tf->size[0] == 0) {
    nz->size[0] = 0;
  } else {
    f_st.site = &sb_emlrtRSI;
    vstride = tf->size[0];
    k = nz->size[0];
    nz->size[0] = tf->size[0];
    emxEnsureCapacity_int32_T(&f_st, nz, k, &eb_emlrtRTEI);
    nz_data = nz->data;
    g_st.site = &tb_emlrtRSI;
    if (tf->size[0] > 2147483646) {
      h_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&h_st);
    }
    for (j = 0; j < vstride; j++) {
      nz_data[j] = tf_data[j];
    }
    for (k = 0; k < 2; k++) {
      xoffset = (k + 1) * vstride;
      g_st.site = &ub_emlrtRSI;
      for (j = 0; j < vstride; j++) {
        nz_data[j] += tf_data[xoffset + j];
      }
    }
  }
  emxFree_boolean_T(&e_st, &tf);
  b_st.site = &nb_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  k = x->size[0] * x->size[1];
  x->size[0] = this->Location->size[0];
  x->size[1] = 3;
  emxEnsureCapacity_real_T(&c_st, x, k, &fb_emlrtRTEI);
  x_data = x->data;
  xoffset = this->Location->size[0] * 3;
  for (k = 0; k < xoffset; k++) {
    x_data[k] = this->Location->data[k];
  }
  emxInit_uint8_T(&c_st, &color, &gb_emlrtRTEI);
  k = color->size[0] * color->size[1];
  color->size[0] = this->Color->size[0];
  color->size[1] = this->Color->size[1];
  emxEnsureCapacity_uint8_T(&c_st, color, k, &gb_emlrtRTEI);
  color_data = color->data;
  xoffset = this->Color->size[0] * this->Color->size[1];
  for (k = 0; k < xoffset; k++) {
    color_data[k] = this->Color->data[k];
  }
  emxInit_real_T(&c_st, &normal, 2, &hb_emlrtRTEI);
  k = normal->size[0] * normal->size[1];
  normal->size[0] = this->Normal->size[0];
  normal->size[1] = this->Normal->size[1];
  emxEnsureCapacity_real_T(&c_st, normal, k, &hb_emlrtRTEI);
  normal_data = normal->data;
  xoffset = this->Normal->size[0] * this->Normal->size[1];
  for (k = 0; k < xoffset; k++) {
    normal_data[k] = this->Normal->data[k];
  }
  emxInit_real_T(&c_st, &intensity, 2, &ib_emlrtRTEI);
  k = intensity->size[0] * intensity->size[1];
  intensity->size[0] = this->Intensity->size[0];
  intensity->size[1] = this->Intensity->size[1];
  emxEnsureCapacity_real_T(&c_st, intensity, k, &ib_emlrtRTEI);
  intensity_data = intensity->data;
  xoffset = this->Intensity->size[0] * this->Intensity->size[1];
  for (k = 0; k < xoffset; k++) {
    intensity_data[k] = this->Intensity->data[k];
  }
  emxInit_real_T(&c_st, &rangeData, 2, &jb_emlrtRTEI);
  k = rangeData->size[0] * rangeData->size[1];
  rangeData->size[0] = this->RangeData->size[0];
  rangeData->size[1] = this->RangeData->size[1];
  emxEnsureCapacity_real_T(&c_st, rangeData, k, &jb_emlrtRTEI);
  rangeData_data = rangeData->data;
  xoffset = this->RangeData->size[0] * this->RangeData->size[1];
  for (k = 0; k < xoffset; k++) {
    rangeData_data[k] = this->RangeData->data[k];
  }
  emxInit_real_T(&c_st, &loc, 2, &kb_emlrtRTEI);
  loc_data = loc->data;
  if (x->size[0] != 0) {
    vstride = nz->size[0] - 1;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        xoffset++;
      }
    }
    emxInit_int32_T(&c_st, &r, &lb_emlrtRTEI);
    k = r->size[0];
    r->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&c_st, r, k, &kb_emlrtRTEI);
    r1 = r->data;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        r1[xoffset] = j;
        xoffset++;
      }
    }
    k = loc->size[0] * loc->size[1];
    loc->size[0] = r->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(&c_st, loc, k, &lb_emlrtRTEI);
    loc_data = loc->data;
    xoffset = r->size[0];
    for (k = 0; k < 3; k++) {
      for (j = 0; j < xoffset; j++) {
        if (r1[j] > x->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r1[j], 0, x->size[0] - 1, &emlrtBCI,
                                        &c_st);
        }
        loc_data[j + loc->size[0] * k] = x_data[r1[j] + x->size[0] * k];
      }
    }
    emxFree_int32_T(&c_st, &r);
  } else {
    loc->size[0] = 0;
    loc->size[1] = 3;
  }
  emxFree_real_T(&c_st, &x);
  emxInit_uint8_T(&c_st, &c, &kb_emlrtRTEI);
  if ((color->size[0] != 0) && (color->size[1] != 0)) {
    vstride = nz->size[0] - 1;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        xoffset++;
      }
    }
    emxInit_int32_T(&c_st, &r2, &lb_emlrtRTEI);
    k = r2->size[0];
    r2->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&c_st, r2, k, &kb_emlrtRTEI);
    r1 = r2->data;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        r1[xoffset] = j;
        xoffset++;
      }
    }
    k = c->size[0] * c->size[1];
    c->size[0] = r2->size[0];
    c->size[1] = color->size[1];
    emxEnsureCapacity_uint8_T(&c_st, c, k, &lb_emlrtRTEI);
    c_data = c->data;
    xoffset = color->size[1];
    for (k = 0; k < xoffset; k++) {
      vstride = r2->size[0];
      for (j = 0; j < vstride; j++) {
        if (r1[j] > color->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r1[j], 0, color->size[0] - 1, &emlrtBCI,
                                        &c_st);
        }
        c_data[j + c->size[0] * k] = color_data[r1[j] + color->size[0] * k];
      }
    }
    emxFree_int32_T(&c_st, &r2);
  } else {
    c->size[0] = 0;
    c->size[1] = 0;
  }
  emxFree_uint8_T(&c_st, &color);
  emxInit_real_T(&c_st, &nv, 2, &kb_emlrtRTEI);
  x_data = nv->data;
  if ((normal->size[0] != 0) && (normal->size[1] != 0)) {
    vstride = nz->size[0] - 1;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        xoffset++;
      }
    }
    emxInit_int32_T(&c_st, &r3, &lb_emlrtRTEI);
    k = r3->size[0];
    r3->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&c_st, r3, k, &kb_emlrtRTEI);
    r1 = r3->data;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        r1[xoffset] = j;
        xoffset++;
      }
    }
    k = nv->size[0] * nv->size[1];
    nv->size[0] = r3->size[0];
    nv->size[1] = normal->size[1];
    emxEnsureCapacity_real_T(&c_st, nv, k, &lb_emlrtRTEI);
    x_data = nv->data;
    xoffset = normal->size[1];
    for (k = 0; k < xoffset; k++) {
      vstride = r3->size[0];
      for (j = 0; j < vstride; j++) {
        if (r1[j] > normal->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r1[j], 0, normal->size[0] - 1,
                                        &emlrtBCI, &c_st);
        }
        x_data[j + nv->size[0] * k] = normal_data[r1[j] + normal->size[0] * k];
      }
    }
    emxFree_int32_T(&c_st, &r3);
  } else {
    nv->size[0] = 0;
    nv->size[1] = 0;
  }
  emxInit_real_T(&c_st, &b_intensity, 2, &kb_emlrtRTEI);
  b_intensity_data = b_intensity->data;
  if ((intensity->size[0] != 0) && (intensity->size[1] != 0)) {
    vstride = nz->size[0] - 1;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        xoffset++;
      }
    }
    emxInit_int32_T(&c_st, &r4, &lb_emlrtRTEI);
    k = r4->size[0];
    r4->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&c_st, r4, k, &kb_emlrtRTEI);
    r1 = r4->data;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        r1[xoffset] = j;
        xoffset++;
      }
    }
    k = b_intensity->size[0] * b_intensity->size[1];
    b_intensity->size[0] = r4->size[0];
    b_intensity->size[1] = intensity->size[1];
    emxEnsureCapacity_real_T(&c_st, b_intensity, k, &lb_emlrtRTEI);
    b_intensity_data = b_intensity->data;
    xoffset = intensity->size[1];
    for (k = 0; k < xoffset; k++) {
      vstride = r4->size[0];
      for (j = 0; j < vstride; j++) {
        if (r1[j] > intensity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r1[j], 0, intensity->size[0] - 1,
                                        &emlrtBCI, &c_st);
        }
        b_intensity_data[j + b_intensity->size[0] * k] =
            intensity_data[r1[j] + intensity->size[0] * k];
      }
    }
    emxFree_int32_T(&c_st, &r4);
  } else {
    b_intensity->size[0] = 0;
    b_intensity->size[1] = 0;
  }
  emxFree_real_T(&c_st, &intensity);
  if ((rangeData->size[0] != 0) && (rangeData->size[1] != 0)) {
    vstride = nz->size[0] - 1;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        xoffset++;
      }
    }
    emxInit_int32_T(&c_st, &r5, &lb_emlrtRTEI);
    k = r5->size[0];
    r5->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&c_st, r5, k, &kb_emlrtRTEI);
    r1 = r5->data;
    xoffset = 0;
    for (j = 0; j <= vstride; j++) {
      if (nz_data[j] == 3) {
        r1[xoffset] = j;
        xoffset++;
      }
    }
    k = normal->size[0] * normal->size[1];
    normal->size[0] = r5->size[0];
    normal->size[1] = rangeData->size[1];
    emxEnsureCapacity_real_T(&c_st, normal, k, &lb_emlrtRTEI);
    normal_data = normal->data;
    xoffset = rangeData->size[1];
    for (k = 0; k < xoffset; k++) {
      vstride = r5->size[0];
      for (j = 0; j < vstride; j++) {
        if (r1[j] > rangeData->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r1[j], 0, rangeData->size[0] - 1,
                                        &emlrtBCI, &c_st);
        }
        normal_data[j + normal->size[0] * k] =
            rangeData_data[r1[j] + rangeData->size[0] * k];
      }
    }
    emxFree_int32_T(&c_st, &r5);
  } else {
    normal->size[0] = 0;
    normal->size[1] = 0;
  }
  emxFree_real_T(&c_st, &rangeData);
  emxFree_int32_T(&c_st, &nz);
  st.site = &jb_emlrtRSI;
  iobj_0->HasKdtreeConstructed = false;
  iobj_0->HasLocationHandleAllocated = false;
  b_st.site = &d_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  ptCloudOut = iobj_0;
  k = iobj_0->Location->size[0] * iobj_0->Location->size[1];
  iobj_0->Location->size[0] = loc->size[0];
  iobj_0->Location->size[1] = 3;
  emxEnsureCapacity_real_T(&b_st, iobj_0->Location, k, &x_emlrtRTEI);
  xoffset = loc->size[0] * 3;
  for (k = 0; k < xoffset; k++) {
    iobj_0->Location->data[k] = loc_data[k];
  }
  emxFree_real_T(&b_st, &loc);
  c_st.site = &h_emlrtRSI;
  pointCloudBase_set_Color(&c_st, iobj_0, c);
  emxFree_uint8_T(&b_st, &c);
  c_st.site = &i_emlrtRSI;
  d_st.site = &s_emlrtRSI;
  xoffset = iobj_0->Location->size[0];
  if ((nv->size[0] != 0) && (nv->size[1] != 0)) {
    uint32_T sz[2];
    uint32_T varargin_2[2];
    boolean_T exitg1;
    sz[0] = (uint32_T)nv->size[0];
    varargin_2[0] = (uint32_T)xoffset;
    sz[1] = (uint32_T)nv->size[1];
    varargin_2[1] = 3U;
    n = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if ((int32_T)sz[k] != (int32_T)varargin_2[k]) {
        n = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!n) {
      emlrtErrorWithMessageIdR2018a(&d_st, &l_emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZNormal",
                                    "vision:pointcloud:unmatchedXYZNormal", 0);
    }
  }
  k = iobj_0->Normal->size[0] * iobj_0->Normal->size[1];
  iobj_0->Normal->size[0] = nv->size[0];
  iobj_0->Normal->size[1] = nv->size[1];
  emxEnsureCapacity_real_T(&c_st, iobj_0->Normal, k, &mb_emlrtRTEI);
  xoffset = nv->size[0] * nv->size[1];
  for (k = 0; k < xoffset; k++) {
    iobj_0->Normal->data[k] = x_data[k];
  }
  emxFree_real_T(&c_st, &nv);
  c_st.site = &j_emlrtRSI;
  d_st.site = &wb_emlrtRSI;
  xoffset = iobj_0->Location->size[0];
  if ((b_intensity->size[0] != 0) && (b_intensity->size[1] != 0) &&
      ((b_intensity->size[1] != 1) || (b_intensity->size[0] != xoffset))) {
    emlrtErrorWithMessageIdR2018a(&d_st, &k_emlrtRTEI,
                                  "vision:pointcloud:unmatchedXYZIntensity",
                                  "vision:pointcloud:unmatchedXYZIntensity", 0);
  }
  k = iobj_0->Intensity->size[0] * iobj_0->Intensity->size[1];
  iobj_0->Intensity->size[0] = b_intensity->size[0];
  iobj_0->Intensity->size[1] = b_intensity->size[1];
  emxEnsureCapacity_real_T(&c_st, iobj_0->Intensity, k, &nb_emlrtRTEI);
  xoffset = b_intensity->size[0] * b_intensity->size[1];
  for (k = 0; k < xoffset; k++) {
    iobj_0->Intensity->data[k] = b_intensity_data[k];
  }
  emxFree_real_T(&c_st, &b_intensity);
  tmp_size[0] = 0;
  tmp_size[1] = 0;
  tmp_data.size = &tmp_size[0];
  tmp_data.allocatedSize = 0;
  tmp_data.numDimensions = 2;
  tmp_data.canFreeData = false;
  c_st.site = &k_emlrtRSI;
  pointCloudBase_set_RangeData(&c_st, iobj_0, &tmp_data);
  b_st.site = &e_emlrtRSI;
  iobj_0->PointCloudArrayData->size[0] = 1;
  iobj_0->PointCloudArrayData->size[1] = 1;
  b_st.site = &f_emlrtRSI;
  iobj_0->Kdtree = NULL;
  iobj_0->LocationHandle = NULL;
  iobj_0->matlabCodegenIsDeleted = false;
  st.site = &kb_emlrtRSI;
  pointCloudBase_set_RangeData(&st, iobj_0, normal);
  emxFree_real_T(sp, &normal);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return ptCloudOut;
}

/* End of code generation (pointCloud.c) */
