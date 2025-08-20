/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * determine_target_location.c
 *
 * Code generation for function 'determine_target_location'
 *
 */

/* Include files */
#include "determine_target_location.h"
#include "assertValidSizeArg.h"
#include "determine_target_location_data.h"
#include "determine_target_location_emxutil.h"
#include "determine_target_location_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,                           /* lineNo */
    "determine_target_location", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    4,                           /* lineNo */
    "determine_target_location", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    5,                           /* lineNo */
    "determine_target_location", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    6,                           /* lineNo */
    "determine_target_location", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    113,               /* lineNo */
    "computeDimsData", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    40,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    38,        /* lineNo */
    "squeeze", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/squeeze.m" /* pathName
                                                                       */
};

static emlrtRTEInfo emlrtRTEI = {
    87,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    80,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    12,                                                             /* lineNo */
    23,                                                             /* colNo */
    "dot",                                                          /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    1,                           /* nDims */
    6,                           /* lineNo */
    13,                          /* colNo */
    "determine_target_location", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    2,                           /* nDims */
    6,                           /* lineNo */
    13,                          /* colNo */
    "determine_target_location", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    85,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    49,                   /* lineNo */
    19,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    3,                           /* lineNo */
    27,                          /* colNo */
    "determine_target_location", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    3,                           /* lineNo */
    27,                          /* colNo */
    "obj.waypoint",              /* aName */
    "determine_target_location", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    4,                           /* lineNo */
    27,                          /* colNo */
    "determine_target_location", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    4,                           /* lineNo */
    27,                          /* colNo */
    "obj.waypoint",              /* aName */
    "determine_target_location", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = {
    6,                           /* lineNo */
    25,                          /* colNo */
    "determine_target_location", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    6,                           /* lineNo */
    31,                          /* colNo */
    "determine_target_location", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    60,                                                             /* lineNo */
    20,                                                             /* colNo */
    "dot",                                                          /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    6,                           /* lineNo */
    21,                          /* colNo */
    "determine_target_location", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location.m" /* pName */
};

/* Function Declarations */
static void binary_expand_op(real_T in1[21000], const struct0_T *in2,
                             const emxArray_boolean_T *in3,
                             const uint16_T in4[2]);

/* Function Definitions */
static void binary_expand_op(real_T in1[21000], const struct0_T *in2,
                             const emxArray_boolean_T *in3,
                             const uint16_T in4[2])
{
  int32_T aux_0_1;
  int32_T b_in2;
  int32_T i;
  int32_T i1;
  int32_T in4_idx_0;
  int32_T stride_0_0;
  int32_T stride_0_1;
  const boolean_T *in3_data;
  in3_data = in3->data;
  in4_idx_0 = in4[0];
  b_in2 = in2->waypoint.size[0];
  stride_0_0 = (in4_idx_0 != 1);
  stride_0_1 = (in4[1] != 1);
  aux_0_1 = 0;
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      real_T d;
      int32_T i2;
      i2 = i1 + 21 * i;
      d = in2->target_n[i2];
      in1[i2] = d + (real_T)(in3_data[i1 * stride_0_0 + in4_idx_0 * aux_0_1] &&
                             (d != b_in2));
    }
    aux_0_1 += stride_0_1;
  }
}

void determine_target_location(c_determine_target_locationStac *SD,
                               const emlrtStack *sp, const struct0_T *obj,
                               const real_T px[63000], real_T tgt_n[21000])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *b_a;
  emxArray_real_T *a;
  emxArray_real_T *b;
  emxArray_real_T *c;
  real_T sz[4];
  real_T d;
  real_T *a_data;
  real_T *b_data;
  real_T *c_data;
  int32_T b_obj[21000];
  int32_T exitg2;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T npages;
  uint16_T varargin_2[4];
  uint16_T szb[2];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T out;
  boolean_T *b_a_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  waypointの更新 */
  for (i = 0; i < 21000; i++) {
    d = obj->target_n[i] - 1.0;
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > obj->waypoint.size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, obj->waypoint.size[0],
                                    &emlrtBCI, (emlrtConstCTX)sp);
    }
    b_obj[i] = (int32_T)d;
  }
  for (i = 0; i < 21000; i++) {
    i1 = i << 1;
    npages = b_obj[i];
    SD->f0.px[i1] = obj->waypoint.data[npages - 1];
    SD->f0.px[i1 + 1] =
        obj->waypoint.data[(npages + obj->waypoint.size[0]) - 1];
  }
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &f_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 42000) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if ((int32_T)obj->NP > 42000) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if (((int32_T)obj->K << 1) * (int32_T)obj->NP != 42000) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  for (i = 0; i < 21000; i++) {
    d = obj->target_n[i];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &b_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > obj->waypoint.size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, obj->waypoint.size[0],
                                    &b_emlrtBCI, (emlrtConstCTX)sp);
    }
    b_obj[i] = (int32_T)d;
  }
  for (i = 0; i < 21000; i++) {
    i1 = i << 1;
    npages = b_obj[i];
    SD->f0.dv[i1] = obj->waypoint.data[npages - 1];
    SD->f0.dv[i1 + 1] =
        obj->waypoint.data[(npages + obj->waypoint.size[0]) - 1];
  }
  st.site = &b_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &f_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 42000) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if ((int32_T)obj->NP > 42000) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  sz[0] = 1.0;
  sz[1] = 2.0;
  sz[2] = obj->K;
  sz[3] = obj->NP;
  st.site = &c_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  npages = 0;
  guard1 = false;
  do {
    exitg2 = 0;
    if (npages < 4) {
      if ((sz[npages] != muDoubleScalarFloor(sz[npages])) ||
          muDoubleScalarIsInf(sz[npages])) {
        guard1 = true;
        exitg2 = 1;
      } else {
        npages++;
        guard1 = false;
      }
    } else {
      npages = 0;
      exitg2 = 2;
    }
  } while (exitg2 == 0);
  if (exitg2 != 1) {
    exitg1 = false;
    while ((!exitg1) && (npages < 4)) {
      if ((sz[npages] < -2.147483648E+9) || (sz[npages] > 2.147483647E+9)) {
        guard1 = true;
        exitg1 = true;
      } else {
        npages++;
      }
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &e_emlrtRTEI,
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector",
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
        MIN_int32_T, 12, MAX_int32_T);
  }
  if (obj->K <= 0.0) {
    d = 0.0;
  } else {
    d = 2.0 * obj->K;
  }
  if (obj->NP <= 0.0) {
    d = 0.0;
  } else {
    d *= obj->NP;
  }
  if (!(d <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  if ((int32_T)obj->K > 42000) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if ((int32_T)obj->NP > 42000) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  emxInit_real_T(sp, &c, &k_emlrtRTEI);
  st.site = &d_emlrtRSI;
  emxInit_real_T(&st, &a, &h_emlrtRTEI);
  i = a->size[0] * a->size[1] * a->size[2] * a->size[3];
  a->size[0] = 1;
  a->size[1] = 2;
  a->size[2] = (int32_T)obj->K;
  a->size[3] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(&st, a, i, &h_emlrtRTEI);
  a_data = a->data;
  for (i = 0; i < 42000; i++) {
    a_data[i] = SD->f0.dv[i] - SD->f0.px[i];
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      npages = 3 * i1 + 63 * i;
      i2 = (i1 << 1) + 42 * i;
      SD->f0.px[i2] = px[npages];
      SD->f0.px[i2 + 1] = px[npages + 1];
    }
  }
  emxInit_real_T(&st, &b, &i_emlrtRTEI);
  i = b->size[0] * b->size[1] * b->size[2] * b->size[3];
  b->size[0] = 1;
  b->size[1] = 2;
  b->size[2] = (int32_T)obj->K;
  b->size[3] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(&st, b, i, &i_emlrtRTEI);
  b_data = b->data;
  for (i = 0; i < 42000; i++) {
    b_data[i] = SD->f0.px[i] - SD->f0.dv[i];
  }
  sz[0] = 1.0;
  varargin_2[0] = 1U;
  sz[1] = 2.0;
  varargin_2[1] = 2U;
  sz[2] = a->size[2];
  varargin_2[2] = (uint16_T)b->size[2];
  sz[3] = a->size[3];
  varargin_2[3] = (uint16_T)b->size[3];
  out = true;
  npages = 0;
  exitg1 = false;
  while ((!exitg1) && (npages < 4)) {
    if ((uint16_T)sz[npages] != varargin_2[npages]) {
      out = false;
      exitg1 = true;
    } else {
      npages++;
    }
  }
  if (!out) {
    out = ((a->size[2] == 1) && (a->size[3] == 1));
    if (!out) {
      emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                    "MATLAB:dot:InputSizeMismatch",
                                    "MATLAB:dot:InputSizeMismatch", 0);
    }
  }
  i = c->size[0] * c->size[1] * c->size[2] * c->size[3];
  c->size[0] = 1;
  c->size[1] = 1;
  c->size[2] = a->size[2];
  c->size[3] = a->size[3];
  emxEnsureCapacity_real_T(&st, c, i, &j_emlrtRTEI);
  c_data = c->data;
  npages = a->size[2] * a->size[3];
  i2 = 1;
  for (i = 0; i < npages; i++) {
    i1 = i2 - 1;
    i2 += 2;
    c_data[i] = a_data[i1] * b_data[i1] + a_data[i1 + 1] * b_data[i1 + 1];
  }
  emxFree_real_T(&st, &b);
  st.site = &d_emlrtRSI;
  emxInit_boolean_T(&st, &b_a, &k_emlrtRTEI);
  i = b_a->size[0] * b_a->size[1] * b_a->size[2] * b_a->size[3];
  b_a->size[0] = 1;
  b_a->size[1] = 1;
  b_a->size[2] = a->size[2];
  b_a->size[3] = a->size[3];
  emxEnsureCapacity_boolean_T(&st, b_a, i, &k_emlrtRTEI);
  b_a_data = b_a->data;
  i2 = c->size[2] * c->size[3];
  for (i = 0; i < i2; i++) {
    b_a_data[i] = (c_data[i] >= 0.0);
  }
  emxFree_real_T(&st, &c);
  szb[0] = 1U;
  szb[1] = 1U;
  out = (b_a->size[2] == 1);
  if ((!out) || (b_a->size[3] != 1)) {
    out = false;
  }
  if (!out) {
    npages = 0;
    if (b_a->size[2] != 1) {
      npages = 1;
      szb[0] = (uint16_T)b_a->size[2];
    }
    if (b_a->size[3] != 1) {
      szb[npages] = (uint16_T)b_a->size[3];
    }
  }
  b_st.site = &h_emlrtRSI;
  npages = 1;
  if (b_a->size[2] > 1) {
    npages = b_a->size[2];
  }
  if (b_a->size[3] > npages) {
    npages = a->size[3];
  }
  emxFree_real_T(&b_st, &a);
  npages = muIntScalarMax_sint32(i2, npages);
  if (szb[0] > npages) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (szb[1] > npages) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (szb[0] * szb[1] != i2) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  if ((szb[0] != 21) && (szb[0] != 1)) {
    emlrtDimSizeImpxCheckR2021b(szb[0], 21, &emlrtECI, (emlrtConstCTX)sp);
  }
  if ((szb[1] != 1000) && (szb[1] != 1)) {
    emlrtDimSizeImpxCheckR2021b(szb[1], 1000, &b_emlrtECI, (emlrtConstCTX)sp);
  }
  if ((szb[0] == 21) && (szb[1] == 1000)) {
    for (i = 0; i < 21000; i++) {
      d = obj->target_n[i];
      tgt_n[i] = d + (real_T)(b_a_data[i] && (d != obj->waypoint.size[0]));
    }
  } else {
    binary_expand_op(tgt_n, obj, b_a, szb);
  }
  emxFree_boolean_T(sp, &b_a);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (determine_target_location.c) */
