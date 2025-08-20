/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pointCloudBase.c
 *
 * Code generation for function 'pointCloudBase'
 *
 */

/* Include files */
#include "pointCloudBase.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "repmat.h"
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = {
    134,                        /* lineNo */
    "pointCloudBase/set.Color", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    761,                            /* lineNo */
    "pointCloudBase/validateColor", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    66,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRSInfo v_emlrtRSI = {
    69,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRSInfo w_emlrtRSI = {
    71,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRSInfo gf_emlrtRSI = {
    40,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    47,       /* lineNo */
    5,        /* colNo */
    "repmat", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pName
                                                                         */
};

static emlrtRTEInfo g_emlrtRTEI = {
    764,                            /* lineNo */
    17,                             /* colNo */
    "pointCloudBase/validateColor", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    701,                                /* lineNo */
    21,                                 /* colNo */
    "pointCloudBase/validateIntensity", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    -1,          /* nDims */
    1,           /* lineNo */
    1,           /* colNo */
    "getSubset", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+pc\\getSubset.p" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    769,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    59,       /* lineNo */
    28,       /* colNo */
    "repmat", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pName
                                                                         */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    149,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    134,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRSInfo rh_emlrtRSI = {
    47,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

/* Function Declarations */
static void b_error(const emlrtStack *sp, const mxArray *m,
                    emlrtMCInfo *location);

/* Function Definitions */
static void b_error(const emlrtStack *sp, const mxArray *m,
                    emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 1, &pArray, "error", true,
                        location);
}

void b_pointCloudBase_set_Color(const emlrtStack *sp, pointCloud *this,
                                const emxArray_uint8_T *b_value)
{
  emlrtStack st;
  int32_T i;
  int32_T k;
  const uint8_T *value_data;
  st.prev = sp;
  st.tls = sp->tls;
  value_data = b_value->data;
  st.site = &r_emlrtRSI;
  if ((b_value->size[0] != 0) && (b_value->size[1] != 0) &&
      (b_value->size[2] != 0)) {
    uint32_T varargin_1[3];
    uint32_T varargin_2[3];
    boolean_T exitg1;
    boolean_T p;
    varargin_1[0] = (uint32_T)b_value->size[0];
    varargin_2[0] = (uint32_T)this->Location->size[0];
    varargin_1[1] = (uint32_T)b_value->size[1];
    varargin_2[1] = (uint32_T)this->Location->size[1];
    varargin_1[2] = (uint32_T)b_value->size[2];
    varargin_2[2] = 3U;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if ((int32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZColor",
                                    "vision:pointcloud:unmatchedXYZColor", 0);
    }
  }
  i = this->Color->size[0] * this->Color->size[1] * this->Color->size[2];
  this->Color->size[0] = b_value->size[0];
  this->Color->size[1] = b_value->size[1];
  this->Color->size[2] = b_value->size[2];
  emxEnsureCapacity_uint8_T(sp, this->Color, i, &pc_emlrtRTEI);
  k = b_value->size[0] * b_value->size[1] * b_value->size[2];
  for (i = 0; i < k; i++) {
    this->Color->data[i] = value_data[i];
  }
}

void b_pointCloudBase_set_RangeData(const emlrtStack *sp, pointCloud *this,
                                    const emxArray_real_T *b_value)
{
  emlrtStack st;
  const real_T *value_data;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  value_data = b_value->data;
  st.site = &ab_emlrtRSI;
  if ((b_value->size[0] != 0) && (b_value->size[1] != 0) &&
      (b_value->size[2] != 0)) {
    uint32_T varargin_1[3];
    uint32_T varargin_2[3];
    boolean_T exitg1;
    boolean_T p;
    varargin_1[0] = (uint32_T)b_value->size[0];
    varargin_2[0] = (uint32_T)this->Location->size[0];
    varargin_1[1] = (uint32_T)b_value->size[1];
    varargin_2[1] = (uint32_T)this->Location->size[1];
    varargin_1[2] = (uint32_T)b_value->size[2];
    varargin_2[2] = 3U;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if ((int32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZRange",
                                    "vision:pointcloud:unmatchedXYZRange", 0);
    }
  }
  i = this->RangeData->size[0] * this->RangeData->size[1] *
      this->RangeData->size[2];
  this->RangeData->size[0] = b_value->size[0];
  this->RangeData->size[1] = b_value->size[1];
  this->RangeData->size[2] = b_value->size[2];
  emxEnsureCapacity_real_T(sp, this->RangeData, i, &bc_emlrtRTEI);
  k = b_value->size[0] * b_value->size[1] * b_value->size[2];
  for (i = 0; i < k; i++) {
    this->RangeData->data[i] = value_data[i];
  }
}

void pointCloudBase_set_Color(const emlrtStack *sp, pointCloud *this,
                              const emxArray_uint8_T *b_value)
{
  static const int32_T iv[2] = {1, 15};
  static const char_T u[15] = {'M', 'A', 'T', 'L', 'A', 'B', ':', 'p',
                               'm', 'a', 'x', 's', 'i', 'z', 'e'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *m;
  const mxArray *y;
  real_T numPoints[2];
  int32_T itilerow;
  int32_T jcol;
  int32_T k;
  int32_T ncols;
  const uint8_T *value_data;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  value_data = b_value->data;
  st.site = &r_emlrtRSI;
  numPoints[0] = b_value->size[0];
  numPoints[1] = b_value->size[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)numPoints[k] != (k << 1) + 1) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  numPoints[0] = this->Location->size[0];
  numPoints[1] = 1.0;
  if (p) {
    int32_T nrows;
    int32_T outsize_idx_0_tmp;
    int32_T outsize_idx_0_tmp_tmp;
    b_st.site = &s_emlrtRSI;
    c_st.site = &t_emlrtRSI;
    assertValidSizeArg(&c_st, numPoints);
    outsize_idx_0_tmp_tmp = (int32_T)numPoints[0];
    outsize_idx_0_tmp = b_value->size[0] * outsize_idx_0_tmp_tmp;
    if (!(outsize_idx_0_tmp == (real_T)b_value->size[0] * numPoints[0])) {
      y = NULL;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a(&b_st, 15, m, &u[0]);
      emlrtAssign(&y, m);
      c_st.site = &rh_emlrtRSI;
      b_error(&c_st, y, &emlrtMCI);
    }
    ncols = this->Color->size[0] * this->Color->size[1];
    this->Color->size[0] = outsize_idx_0_tmp;
    this->Color->size[1] = b_value->size[1];
    emxEnsureCapacity_uint8_T(&b_st, this->Color, ncols, &ac_emlrtRTEI);
    nrows = b_value->size[0];
    ncols = b_value->size[1];
    c_st.site = &u_emlrtRSI;
    if (b_value->size[1] > 2147483646) {
      d_st.site = &x_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (jcol = 0; jcol < ncols; jcol++) {
      int32_T iacol;
      int32_T ibmat;
      iacol = jcol * nrows;
      ibmat = jcol * outsize_idx_0_tmp - 1;
      c_st.site = &v_emlrtRSI;
      if (outsize_idx_0_tmp_tmp > 2147483646) {
        d_st.site = &x_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (itilerow = 0; itilerow < outsize_idx_0_tmp_tmp; itilerow++) {
        int32_T ibcol;
        ibcol = ibmat + itilerow * nrows;
        c_st.site = &w_emlrtRSI;
        if (nrows > 2147483646) {
          d_st.site = &x_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (k = 0; k < nrows; k++) {
          this->Color->data[(ibcol + k) + 1] = value_data[iacol + k];
        }
      }
    }
  } else {
    int32_T nrows;
    if ((b_value->size[0] != 0) && (b_value->size[1] != 0)) {
      uint32_T varargin_2[2];
      numPoints[0] = b_value->size[0];
      varargin_2[0] = (uint32_T)this->Location->size[0];
      numPoints[1] = b_value->size[1];
      varargin_2[1] = 3U;
      p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if ((int32_T)numPoints[k] != (int32_T)varargin_2[k]) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (!p) {
        emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
                                      "vision:pointcloud:unmatchedXYZColor",
                                      "vision:pointcloud:unmatchedXYZColor", 0);
      }
    }
    ncols = this->Color->size[0] * this->Color->size[1];
    this->Color->size[0] = b_value->size[0];
    this->Color->size[1] = b_value->size[1];
    emxEnsureCapacity_uint8_T(&st, this->Color, ncols, &yb_emlrtRTEI);
    nrows = b_value->size[0] * b_value->size[1];
    for (ncols = 0; ncols < nrows; ncols++) {
      this->Color->data[ncols] = value_data[ncols];
    }
  }
}

void pointCloudBase_set_Intensity(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *b_value)
{
  emlrtStack st;
  const real_T *value_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  value_data = b_value->data;
  st.site = &hc_emlrtRSI;
  if ((b_value->size[0] != 0) && (b_value->size[1] != 0) &&
      ((b_value->size[0] != this->Location->size[0]) ||
       (b_value->size[1] != this->Location->size[1]))) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
                                  "vision:pointcloud:unmatchedXYZIntensity",
                                  "vision:pointcloud:unmatchedXYZIntensity", 0);
  }
  i = this->Intensity->size[0] * this->Intensity->size[1];
  this->Intensity->size[0] = b_value->size[0];
  this->Intensity->size[1] = b_value->size[1];
  emxEnsureCapacity_real_T(sp, this->Intensity, i, &lb_emlrtRTEI);
  loop_ub = b_value->size[0] * b_value->size[1];
  for (i = 0; i < loop_ub; i++) {
    this->Intensity->data[i] = value_data[i];
  }
}

void pointCloudBase_set_Normal(const emlrtStack *sp, pointCloud *this,
                               const emxArray_real_T *b_value)
{
  emlrtStack st;
  const real_T *value_data;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  value_data = b_value->data;
  st.site = &y_emlrtRSI;
  if ((b_value->size[0] != 0) && (b_value->size[1] != 0) &&
      (b_value->size[2] != 0)) {
    uint32_T varargin_1[3];
    uint32_T varargin_2[3];
    boolean_T exitg1;
    boolean_T p;
    varargin_1[0] = (uint32_T)b_value->size[0];
    varargin_2[0] = (uint32_T)this->Location->size[0];
    varargin_1[1] = (uint32_T)b_value->size[1];
    varargin_2[1] = (uint32_T)this->Location->size[1];
    varargin_1[2] = (uint32_T)b_value->size[2];
    varargin_2[2] = 3U;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if ((int32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZNormal",
                                    "vision:pointcloud:unmatchedXYZNormal", 0);
    }
  }
  i = this->Normal->size[0] * this->Normal->size[1] * this->Normal->size[2];
  this->Normal->size[0] = b_value->size[0];
  this->Normal->size[1] = b_value->size[1];
  this->Normal->size[2] = b_value->size[2];
  emxEnsureCapacity_real_T(sp, this->Normal, i, &lc_emlrtRTEI);
  k = b_value->size[0] * b_value->size[1] * b_value->size[2];
  for (i = 0; i < k; i++) {
    this->Normal->data[i] = value_data[i];
  }
}

void pointCloudBase_set_RangeData(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *b_value)
{
  emlrtStack st;
  const real_T *value_data;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  value_data = b_value->data;
  st.site = &ab_emlrtRSI;
  if ((b_value->size[0] != 0) && (b_value->size[1] != 0)) {
    uint32_T varargin_1[2];
    uint32_T varargin_2[2];
    boolean_T exitg1;
    boolean_T p;
    varargin_1[0] = (uint32_T)b_value->size[0];
    varargin_2[0] = (uint32_T)this->Location->size[0];
    varargin_1[1] = (uint32_T)b_value->size[1];
    varargin_2[1] = 3U;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if ((int32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZRange",
                                    "vision:pointcloud:unmatchedXYZRange", 0);
    }
  }
  i = this->RangeData->size[0] * this->RangeData->size[1];
  this->RangeData->size[0] = b_value->size[0];
  this->RangeData->size[1] = b_value->size[1];
  emxEnsureCapacity_real_T(sp, this->RangeData, i, &bc_emlrtRTEI);
  k = b_value->size[0] * b_value->size[1];
  for (i = 0; i < k; i++) {
    this->RangeData->data[i] = value_data[i];
  }
}

void pointCloudBase_subsetImpl(const emlrtStack *sp, const pointCloud *this,
                               const emxArray_real_T *indices,
                               emxArray_real_T *loc, emxArray_uint8_T *c,
                               emxArray_real_T *nv, emxArray_real_T *intensity,
                               emxArray_real_T *r)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_int32_T *b_r;
  emxArray_real_T *tmp;
  emxArray_uint8_T *b_tmp;
  real_T varargin_1[3];
  const real_T *indices_data;
  real_T *loc_data;
  real_T *tmp_data;
  int32_T b_varargin_1[3];
  int32_T sz[3];
  int32_T b_emptyDimValue[2];
  int32_T b_indices[2];
  int32_T emptyDimValue;
  int32_T i;
  int32_T i1;
  int32_T loop_ub_tmp;
  int32_T n;
  int32_T nx;
  int32_T nx_tmp;
  int32_T *r1;
  uint8_T *b_tmp_data;
  uint8_T *c_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  indices_data = indices->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &gc_emlrtRSI;
  emxInit_real_T(&st, &tmp, 2, &jc_emlrtRTEI);
  emxInit_int32_T(&st, &b_r, 1, &jc_emlrtRTEI);
  if ((this->Location->size[0] != 0) && (this->Location->size[1] != 0)) {
    b_st.site = &ef_emlrtRSI;
    nx = this->Location->size[0] * this->Location->size[1] * 3;
    c_st.site = &ff_emlrtRSI;
    emptyDimValue = (int32_T)((uint32_T)nx / 3U);
    if (emptyDimValue > nx) {
      emlrtErrorWithMessageIdR2018a(&c_st, &ab_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    n = this->Location->size[0];
    if (this->Location->size[1] > this->Location->size[0]) {
      n = this->Location->size[1];
    }
    if (n < 3) {
      n = 3;
    }
    if (emptyDimValue > muIntScalarMax_sint32(nx, n)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (emptyDimValue * 3 != nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    i = tmp->size[0] * tmp->size[1];
    tmp->size[0] = emptyDimValue;
    tmp->size[1] = 3;
    emxEnsureCapacity_real_T(&st, tmp, i, &jc_emlrtRTEI);
    tmp_data = tmp->data;
    loop_ub_tmp = emptyDimValue * 3;
    for (i = 0; i < loop_ub_tmp; i++) {
      tmp_data[i] = rtNaN;
    }
    i = b_r->size[0];
    b_r->size[0] = indices->size[0];
    emxEnsureCapacity_int32_T(&st, b_r, i, &jc_emlrtRTEI);
    r1 = b_r->data;
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > emptyDimValue)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, emptyDimValue, &f_emlrtBCI, &st);
      }
      r1[i] = i1 - 1;
    }
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > emptyDimValue)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, emptyDimValue, &f_emlrtBCI, &st);
      }
    }
    b_emptyDimValue[0] = b_r->size[0];
    b_emptyDimValue[1] = 3;
    b_indices[0] = indices->size[0];
    b_indices[1] = 3;
    emlrtSubAssignSizeCheckR2012b(&b_emptyDimValue[0], 2, &b_indices[0], 2,
                                  &c_emlrtECI, &st);
    n = indices->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < n; i1++) {
        tmp_data[r1[i1] + tmp->size[0] * i] =
            this->Location
                ->data[((int32_T)indices_data[i1] + emptyDimValue * i) - 1];
      }
      varargin_1[i] = this->Location->size[i];
    }
    i = (int32_T)varargin_1[0];
    i1 = (int32_T)varargin_1[1];
    n = i * i1 * 3;
    if (n != loop_ub_tmp) {
      emlrtSubAssignSizeCheck1dR2017a(n, loop_ub_tmp, &c_emlrtECI, &st);
    }
    nx = loc->size[0] * loc->size[1] * loc->size[2];
    loc->size[0] = i;
    loc->size[1] = i1;
    loc->size[2] = 3;
    emxEnsureCapacity_real_T(&st, loc, nx, &jc_emlrtRTEI);
    loc_data = loc->data;
    for (i = 0; i < n; i++) {
      loc_data[i] = tmp_data[i];
    }
  } else {
    loc->size[0] = 0;
    loc->size[1] = 0;
    loc->size[2] = 3;
  }
  if ((this->Color->size[0] != 0) && (this->Color->size[1] != 0) &&
      (this->Color->size[2] != 0)) {
    b_st.site = &ef_emlrtRSI;
    nx_tmp = this->Color->size[0] * this->Color->size[1] * this->Color->size[2];
    c_st.site = &ff_emlrtRSI;
    emptyDimValue = (int32_T)((uint32_T)nx_tmp / 3U);
    if (emptyDimValue > nx_tmp) {
      emlrtErrorWithMessageIdR2018a(&c_st, &ab_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    n = this->Color->size[0];
    if (this->Color->size[1] > this->Color->size[0]) {
      n = this->Color->size[1];
    }
    if (this->Color->size[2] > n) {
      n = this->Color->size[2];
    }
    nx = muIntScalarMax_sint32(nx_tmp, n);
    if (emptyDimValue > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (nx < 3) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (emptyDimValue * 3 != nx_tmp) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    emxInit_uint8_T(&st, &b_tmp, 2, &jc_emlrtRTEI);
    i = b_tmp->size[0] * b_tmp->size[1];
    b_tmp->size[0] = emptyDimValue;
    b_tmp->size[1] = 3;
    emxEnsureCapacity_uint8_T(&st, b_tmp, i, &jc_emlrtRTEI);
    b_tmp_data = b_tmp->data;
    loop_ub_tmp = emptyDimValue * 3;
    for (i = 0; i < loop_ub_tmp; i++) {
      b_tmp_data[i] = 0U;
    }
    i = b_r->size[0];
    b_r->size[0] = indices->size[0];
    emxEnsureCapacity_int32_T(&st, b_r, i, &jc_emlrtRTEI);
    r1 = b_r->data;
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > emptyDimValue)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, emptyDimValue, &f_emlrtBCI, &st);
      }
      r1[i] = i1 - 1;
    }
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > emptyDimValue)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, emptyDimValue, &f_emlrtBCI, &st);
      }
    }
    b_emptyDimValue[0] = b_r->size[0];
    b_emptyDimValue[1] = 3;
    b_indices[0] = indices->size[0];
    b_indices[1] = 3;
    emlrtSubAssignSizeCheckR2012b(&b_emptyDimValue[0], 2, &b_indices[0], 2,
                                  &c_emlrtECI, &st);
    n = indices->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < n; i1++) {
        b_tmp_data[r1[i1] + b_tmp->size[0] * i] =
            this->Color
                ->data[((int32_T)indices_data[i1] + emptyDimValue * i) - 1];
      }
    }
    b_st.site = &ef_emlrtRSI;
    varargin_1[0] = this->Color->size[0];
    varargin_1[1] = this->Color->size[1];
    varargin_1[2] = this->Color->size[2];
    c_st.site = &gf_emlrtRSI;
    b_assertValidSizeArg(&c_st, varargin_1);
    b_varargin_1[0] = (int32_T)varargin_1[0];
    b_varargin_1[1] = (int32_T)varargin_1[1];
    b_varargin_1[2] = (int32_T)varargin_1[2];
    num2cell_vector(b_varargin_1, sz);
    n = b_tmp->size[0];
    if (b_tmp->size[0] < 3) {
      n = 3;
    }
    nx = muIntScalarMax_sint32(loop_ub_tmp, n);
    if (sz[0] > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (sz[1] > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (sz[2] > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (sz[0] * sz[1] * sz[2] != loop_ub_tmp) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    i = c->size[0] * c->size[1] * c->size[2];
    c->size[0] = this->Color->size[0];
    c->size[1] = this->Color->size[1];
    c->size[2] = this->Color->size[2];
    emxEnsureCapacity_uint8_T(&st, c, i, &jc_emlrtRTEI);
    c_data = c->data;
    for (i = 0; i < nx_tmp; i++) {
      c_data[i] = b_tmp_data[i];
    }
    emxFree_uint8_T(&st, &b_tmp);
  } else {
    c->size[0] = 0;
    c->size[1] = 0;
    c->size[2] = 1;
  }
  if ((this->Normal->size[0] != 0) && (this->Normal->size[1] != 0) &&
      (this->Normal->size[2] != 0)) {
    b_st.site = &ef_emlrtRSI;
    nx_tmp =
        this->Normal->size[0] * this->Normal->size[1] * this->Normal->size[2];
    c_st.site = &ff_emlrtRSI;
    emptyDimValue = (int32_T)((uint32_T)nx_tmp / 3U);
    if (emptyDimValue > nx_tmp) {
      emlrtErrorWithMessageIdR2018a(&c_st, &ab_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    n = this->Normal->size[0];
    if (this->Normal->size[1] > this->Normal->size[0]) {
      n = this->Normal->size[1];
    }
    if (this->Normal->size[2] > n) {
      n = this->Normal->size[2];
    }
    nx = muIntScalarMax_sint32(nx_tmp, n);
    if (emptyDimValue > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (nx < 3) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (emptyDimValue * 3 != nx_tmp) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    i = tmp->size[0] * tmp->size[1];
    tmp->size[0] = emptyDimValue;
    tmp->size[1] = 3;
    emxEnsureCapacity_real_T(&st, tmp, i, &jc_emlrtRTEI);
    tmp_data = tmp->data;
    loop_ub_tmp = emptyDimValue * 3;
    for (i = 0; i < loop_ub_tmp; i++) {
      tmp_data[i] = rtNaN;
    }
    i = b_r->size[0];
    b_r->size[0] = indices->size[0];
    emxEnsureCapacity_int32_T(&st, b_r, i, &jc_emlrtRTEI);
    r1 = b_r->data;
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > emptyDimValue)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, emptyDimValue, &f_emlrtBCI, &st);
      }
      r1[i] = i1 - 1;
    }
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > emptyDimValue)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, emptyDimValue, &f_emlrtBCI, &st);
      }
    }
    b_emptyDimValue[0] = b_r->size[0];
    b_emptyDimValue[1] = 3;
    b_indices[0] = indices->size[0];
    b_indices[1] = 3;
    emlrtSubAssignSizeCheckR2012b(&b_emptyDimValue[0], 2, &b_indices[0], 2,
                                  &c_emlrtECI, &st);
    n = indices->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < n; i1++) {
        tmp_data[r1[i1] + tmp->size[0] * i] =
            this->Normal
                ->data[((int32_T)indices_data[i1] + emptyDimValue * i) - 1];
      }
    }
    b_st.site = &ef_emlrtRSI;
    varargin_1[0] = this->Normal->size[0];
    varargin_1[1] = this->Normal->size[1];
    varargin_1[2] = this->Normal->size[2];
    c_st.site = &gf_emlrtRSI;
    b_assertValidSizeArg(&c_st, varargin_1);
    b_varargin_1[0] = (int32_T)varargin_1[0];
    b_varargin_1[1] = (int32_T)varargin_1[1];
    b_varargin_1[2] = (int32_T)varargin_1[2];
    num2cell_vector(b_varargin_1, sz);
    n = tmp->size[0];
    if (tmp->size[0] < 3) {
      n = 3;
    }
    nx = muIntScalarMax_sint32(loop_ub_tmp, n);
    if (sz[0] > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (sz[1] > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (sz[2] > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (sz[0] * sz[1] * sz[2] != loop_ub_tmp) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    i = nv->size[0] * nv->size[1] * nv->size[2];
    nv->size[0] = this->Normal->size[0];
    nv->size[1] = this->Normal->size[1];
    nv->size[2] = this->Normal->size[2];
    emxEnsureCapacity_real_T(&st, nv, i, &jc_emlrtRTEI);
    loc_data = nv->data;
    for (i = 0; i < nx_tmp; i++) {
      loc_data[i] = tmp_data[i];
    }
  } else {
    nv->size[0] = 0;
    nv->size[1] = 0;
    nv->size[2] = 1;
  }
  if ((this->Intensity->size[0] != 0) && (this->Intensity->size[1] != 0)) {
    real_T b_this[2];
    b_this[0] = this->Intensity->size[0];
    b_this[1] = this->Intensity->size[1];
    b_st.site = &ef_emlrtRSI;
    repmat(&b_st, b_this, intensity);
    loc_data = intensity->data;
    nx = intensity->size[0] * intensity->size[1];
    i = b_r->size[0];
    b_r->size[0] = indices->size[0];
    emxEnsureCapacity_int32_T(&st, b_r, i, &jc_emlrtRTEI);
    r1 = b_r->data;
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > nx)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nx, &f_emlrtBCI, &st);
      }
      r1[i] = i1;
    }
    nx = this->Intensity->size[0] * this->Intensity->size[1];
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > nx)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nx, &f_emlrtBCI, &st);
      }
    }
    if (b_r->size[0] != indices->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(b_r->size[0], indices->size[0],
                                      &c_emlrtECI, &st);
    }
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      loc_data[r1[i] - 1] = this->Intensity->data[(int32_T)indices_data[i] - 1];
    }
  } else {
    intensity->size[0] = 0;
    intensity->size[1] = 0;
  }
  if ((this->RangeData->size[0] != 0) && (this->RangeData->size[1] != 0) &&
      (this->RangeData->size[2] != 0)) {
    b_st.site = &ef_emlrtRSI;
    nx_tmp = this->RangeData->size[0] * this->RangeData->size[1] *
             this->RangeData->size[2];
    c_st.site = &ff_emlrtRSI;
    emptyDimValue = (int32_T)((uint32_T)nx_tmp / 3U);
    if (emptyDimValue > nx_tmp) {
      emlrtErrorWithMessageIdR2018a(&c_st, &ab_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    n = this->RangeData->size[0];
    if (this->RangeData->size[1] > this->RangeData->size[0]) {
      n = this->RangeData->size[1];
    }
    if (this->RangeData->size[2] > n) {
      n = this->RangeData->size[2];
    }
    nx = muIntScalarMax_sint32(nx_tmp, n);
    if (emptyDimValue > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (nx < 3) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (emptyDimValue * 3 != nx_tmp) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    i = tmp->size[0] * tmp->size[1];
    tmp->size[0] = emptyDimValue;
    tmp->size[1] = 3;
    emxEnsureCapacity_real_T(&st, tmp, i, &jc_emlrtRTEI);
    tmp_data = tmp->data;
    loop_ub_tmp = emptyDimValue * 3;
    for (i = 0; i < loop_ub_tmp; i++) {
      tmp_data[i] = rtNaN;
    }
    i = b_r->size[0];
    b_r->size[0] = indices->size[0];
    emxEnsureCapacity_int32_T(&st, b_r, i, &jc_emlrtRTEI);
    r1 = b_r->data;
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > emptyDimValue)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, emptyDimValue, &f_emlrtBCI, &st);
      }
      r1[i] = i1 - 1;
    }
    n = indices->size[0];
    for (i = 0; i < n; i++) {
      i1 = (int32_T)indices_data[i];
      if ((i1 < 1) || (i1 > emptyDimValue)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, emptyDimValue, &f_emlrtBCI, &st);
      }
    }
    b_emptyDimValue[0] = b_r->size[0];
    b_emptyDimValue[1] = 3;
    b_indices[0] = indices->size[0];
    b_indices[1] = 3;
    emlrtSubAssignSizeCheckR2012b(&b_emptyDimValue[0], 2, &b_indices[0], 2,
                                  &c_emlrtECI, &st);
    n = indices->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < n; i1++) {
        tmp_data[r1[i1] + tmp->size[0] * i] =
            this->RangeData
                ->data[((int32_T)indices_data[i1] + emptyDimValue * i) - 1];
      }
    }
    b_st.site = &ef_emlrtRSI;
    varargin_1[0] = this->RangeData->size[0];
    varargin_1[1] = this->RangeData->size[1];
    varargin_1[2] = this->RangeData->size[2];
    c_st.site = &gf_emlrtRSI;
    b_assertValidSizeArg(&c_st, varargin_1);
    b_varargin_1[0] = (int32_T)varargin_1[0];
    b_varargin_1[1] = (int32_T)varargin_1[1];
    b_varargin_1[2] = (int32_T)varargin_1[2];
    num2cell_vector(b_varargin_1, sz);
    n = tmp->size[0];
    if (tmp->size[0] < 3) {
      n = 3;
    }
    nx = muIntScalarMax_sint32(loop_ub_tmp, n);
    if (sz[0] > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (sz[1] > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (sz[2] > nx) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (sz[0] * sz[1] * sz[2] != loop_ub_tmp) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    i = r->size[0] * r->size[1] * r->size[2];
    r->size[0] = this->RangeData->size[0];
    r->size[1] = this->RangeData->size[1];
    r->size[2] = this->RangeData->size[2];
    emxEnsureCapacity_real_T(&st, r, i, &jc_emlrtRTEI);
    loc_data = r->data;
    for (i = 0; i < nx_tmp; i++) {
      loc_data[i] = tmp_data[i];
    }
  } else {
    r->size[0] = 0;
    r->size[1] = 0;
    r->size[2] = 1;
  }
  emxFree_int32_T(&st, &b_r);
  emxFree_real_T(&st, &tmp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (pointCloudBase.c) */
