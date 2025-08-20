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
#include "Faster_processingPcloud_data.h"
#include "Faster_processingPcloud_emxutil.h"
#include "Faster_processingPcloud_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = {
    134,                        /* lineNo */
    "pointCloudBase/set.Color", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    783,                            /* lineNo */
    "pointCloudBase/validateColor", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    34,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
                                                                      */
};

static emlrtRSInfo w_emlrtRSI = {
    72,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
                                                                      */
};

static emlrtRSInfo x_emlrtRSI = {
    75,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
                                                                      */
};

static emlrtRSInfo y_emlrtRSI = {
    77,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
                                                                      */
};

static emlrtRSInfo cb_emlrtRSI = {
    149,                            /* lineNo */
    "pointCloudBase/set.RangeData", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    53,       /* lineNo */
    5,        /* colNo */
    "repmat", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    790,                            /* lineNo */
    17,                             /* colNo */
    "pointCloudBase/validateColor", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    834,                            /* lineNo */
    13,                             /* colNo */
    "pointCloudBase/validateRange", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    795,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    65,       /* lineNo */
    28,       /* colNo */
    "repmat", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    149,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRSInfo kk_emlrtRSI = {
    53,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
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

void pointCloudBase_set_Color(const emlrtStack *sp, pointCloud *b_this,
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
  int32_T i;
  int32_T itilerow;
  int32_T jcol;
  int32_T k;
  uint32_T numPoints[2];
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
  st.site = &t_emlrtRSI;
  numPoints[0] = (uint32_T)b_value->size[0];
  numPoints[1] = (uint32_T)b_value->size[1];
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
  if (p) {
    int32_T nrows;
    int32_T ntilerows;
    int32_T outsize_idx_0_tmp;
    numPoints[0] = (uint32_T)b_this->Location->size[0];
    b_st.site = &u_emlrtRSI;
    c_st.site = &v_emlrtRSI;
    outsize_idx_0_tmp = b_value->size[0] * (int32_T)numPoints[0];
    if (!(outsize_idx_0_tmp ==
          (real_T)b_value->size[0] * (real_T)numPoints[0])) {
      y = NULL;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a(&b_st, 15, m, &u[0]);
      emlrtAssign(&y, m);
      c_st.site = &kk_emlrtRSI;
      b_error(&c_st, y, &emlrtMCI);
    }
    i = b_this->Color->size[0] * b_this->Color->size[1];
    b_this->Color->size[0] = outsize_idx_0_tmp;
    emxEnsureCapacity_uint8_T(&b_st, b_this->Color, i, &hb_emlrtRTEI);
    i = b_value->size[1];
    nrows = b_this->Color->size[0] * b_this->Color->size[1];
    b_this->Color->size[1] = b_value->size[1];
    emxEnsureCapacity_uint8_T(&b_st, b_this->Color, nrows, &hb_emlrtRTEI);
    nrows = b_value->size[0];
    ntilerows = (int32_T)numPoints[0];
    c_st.site = &w_emlrtRSI;
    if (b_value->size[1] > 2147483646) {
      d_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (jcol = 0; jcol < i; jcol++) {
      int32_T iacol;
      int32_T ibmat;
      iacol = jcol * nrows;
      ibmat = jcol * outsize_idx_0_tmp - 1;
      c_st.site = &x_emlrtRSI;
      if (ntilerows > 2147483646) {
        d_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (itilerow = 0; itilerow < ntilerows; itilerow++) {
        int32_T ibcol;
        ibcol = ibmat + itilerow * nrows;
        c_st.site = &y_emlrtRSI;
        if (nrows > 2147483646) {
          d_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (k = 0; k < nrows; k++) {
          b_this->Color->data[(ibcol + k) + 1] = value_data[iacol + k];
        }
      }
    }
  } else {
    int32_T nrows;
    if ((b_value->size[0] != 0) && (b_value->size[1] != 0)) {
      uint32_T varargin_2[2];
      varargin_2[0] = (uint32_T)b_this->Location->size[0];
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
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                      "vision:pointcloud:unmatchedXYZColor",
                                      "vision:pointcloud:unmatchedXYZColor", 0);
      }
    }
    i = b_this->Color->size[0] * b_this->Color->size[1];
    b_this->Color->size[0] = b_value->size[0];
    b_this->Color->size[1] = b_value->size[1];
    emxEnsureCapacity_uint8_T(&st, b_this->Color, i, &gb_emlrtRTEI);
    nrows = b_value->size[0] * b_value->size[1];
    for (i = 0; i < nrows; i++) {
      b_this->Color->data[i] = value_data[i];
    }
  }
}

void pointCloudBase_set_RangeData(const emlrtStack *sp, pointCloud *b_this,
                                  const emxArray_real_T *b_value)
{
  emlrtStack st;
  const real_T *value_data;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  value_data = b_value->data;
  st.site = &cb_emlrtRSI;
  if ((b_value->size[0] != 0) && (b_value->size[1] != 0)) {
    uint32_T varargin_1[2];
    uint32_T varargin_2[2];
    boolean_T exitg1;
    boolean_T p;
    varargin_1[0] = (uint32_T)b_value->size[0];
    varargin_2[0] = (uint32_T)b_this->Location->size[0];
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
      emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZRange",
                                    "vision:pointcloud:unmatchedXYZRange", 0);
    }
  }
  i = b_this->RangeData->size[0] * b_this->RangeData->size[1];
  b_this->RangeData->size[0] = b_value->size[0];
  b_this->RangeData->size[1] = b_value->size[1];
  emxEnsureCapacity_real_T(sp, b_this->RangeData, i, &ib_emlrtRTEI);
  k = b_value->size[0] * b_value->size[1];
  for (i = 0; i < k; i++) {
    b_this->RangeData->data[i] = value_data[i];
  }
}

/* End of code generation (pointCloudBase.c) */
