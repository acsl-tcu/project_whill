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
#include "removePlane_BBox_data.h"
#include "removePlane_BBox_emxutil.h"
#include "removePlane_BBox_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = {
    134,                        /* lineNo */
    "pointCloudBase/set.Color", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    761,                            /* lineNo */
    "pointCloudBase/validateColor", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    66,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRSInfo q_emlrtRSI = {
    71,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRSInfo t_emlrtRSI = {
    149,                            /* lineNo */
    "pointCloudBase/set.RangeData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
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

static emlrtRTEInfo j_emlrtRTEI = {
    805,                            /* lineNo */
    13,                             /* colNo */
    "pointCloudBase/validateRange", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    769,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    149,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRSInfo ve_emlrtRSI = {
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
  st.site = &l_emlrtRSI;
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
    b_st.site = &m_emlrtRSI;
    c_st.site = &n_emlrtRSI;
    assertValidSizeArg(&c_st, numPoints);
    outsize_idx_0_tmp_tmp = (int32_T)numPoints[0];
    outsize_idx_0_tmp = b_value->size[0] * outsize_idx_0_tmp_tmp;
    if (!(outsize_idx_0_tmp == (real_T)b_value->size[0] * numPoints[0])) {
      y = NULL;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a(&b_st, 15, m, &u[0]);
      emlrtAssign(&y, m);
      c_st.site = &ve_emlrtRSI;
      b_error(&c_st, y, &emlrtMCI);
    }
    ncols = this->Color->size[0] * this->Color->size[1];
    this->Color->size[0] = outsize_idx_0_tmp;
    this->Color->size[1] = b_value->size[1];
    emxEnsureCapacity_uint8_T(&b_st, this->Color, ncols, &ab_emlrtRTEI);
    nrows = b_value->size[0];
    ncols = b_value->size[1];
    c_st.site = &o_emlrtRSI;
    if (b_value->size[1] > 2147483646) {
      d_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (jcol = 0; jcol < ncols; jcol++) {
      int32_T iacol;
      int32_T ibmat;
      iacol = jcol * nrows;
      ibmat = jcol * outsize_idx_0_tmp - 1;
      c_st.site = &p_emlrtRSI;
      if (outsize_idx_0_tmp_tmp > 2147483646) {
        d_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (itilerow = 0; itilerow < outsize_idx_0_tmp_tmp; itilerow++) {
        int32_T ibcol;
        ibcol = ibmat + itilerow * nrows;
        c_st.site = &q_emlrtRSI;
        if (nrows > 2147483646) {
          d_st.site = &r_emlrtRSI;
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
    emxEnsureCapacity_uint8_T(&st, this->Color, ncols, &y_emlrtRTEI);
    nrows = b_value->size[0] * b_value->size[1];
    for (ncols = 0; ncols < nrows; ncols++) {
      this->Color->data[ncols] = value_data[ncols];
    }
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
  st.site = &t_emlrtRSI;
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
      emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZRange",
                                    "vision:pointcloud:unmatchedXYZRange", 0);
    }
  }
  i = this->RangeData->size[0] * this->RangeData->size[1];
  this->RangeData->size[0] = b_value->size[0];
  this->RangeData->size[1] = b_value->size[1];
  emxEnsureCapacity_real_T(sp, this->RangeData, i, &bb_emlrtRTEI);
  k = b_value->size[0] * b_value->size[1];
  for (i = 0; i < k; i++) {
    this->RangeData->data[i] = value_data[i];
  }
}

/* End of code generation (pointCloudBase.c) */
