/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitcuboid.c
 *
 * Code generation for function 'pcfitcuboid'
 *
 */

/* Include files */
#include "pcfitcuboid.h"
#include "abs.h"
#include "cosd.h"
#include "eml_int_forloop_overflow_check.h"
#include "mtimes.h"
#include "removePlane_BBox_data.h"
#include "removePlane_BBox_emxutil.h"
#include "removePlane_BBox_types.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "sumMatrixIncludeNaN.h"
#include "var.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mc_emlrtRSI =
    {
        164,               /* lineNo */
        "findBoundingBox", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo nc_emlrtRSI =
    {
        166,               /* lineNo */
        "findBoundingBox", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo oc_emlrtRSI =
    {
        167,               /* lineNo */
        "findBoundingBox", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo pc_emlrtRSI =
    {
        170,               /* lineNo */
        "findBoundingBox", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo qc_emlrtRSI =
    {
        181,            /* lineNo */
        "findRotation", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo rc_emlrtRSI =
    {
        182,            /* lineNo */
        "findRotation", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo sc_emlrtRSI =
    {
        184,            /* lineNo */
        "findRotation", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo tc_emlrtRSI =
    {
        187,            /* lineNo */
        "findRotation", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo uc_emlrtRSI =
    {
        188,            /* lineNo */
        "findRotation", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo vc_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI =
    {
        261,                 /* lineNo */
        "calculateVariance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo ad_emlrtRSI =
    {
        262,                 /* lineNo */
        "calculateVariance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo bd_emlrtRSI =
    {
        274,                 /* lineNo */
        "calculateVariance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo cd_emlrtRSI =
    {
        277,                 /* lineNo */
        "calculateVariance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo dd_emlrtRSI =
    {
        285,                 /* lineNo */
        "getDistanceMatrix", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo ed_emlrtRSI =
    {
        286,                 /* lineNo */
        "getDistanceMatrix", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo fd_emlrtRSI =
    {
        289,                 /* lineNo */
        "getDistanceMatrix", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo gd_emlrtRSI =
    {
        290,                 /* lineNo */
        "getDistanceMatrix", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo hd_emlrtRSI = {
    225,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    318,                     /* lineNo */
    "unaryMinOrMaxDispatch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    386,          /* lineNo */
    "minOrMax2D", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    468,                         /* lineNo */
    "minOrMax2DColumnMajorDim1", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    17,    /* lineNo */
    "min", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" /* pathName
                                                                        */
};

static emlrtRSInfo de_emlrtRSI =
    {
        40,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI =
    {
        194,          /* lineNo */
        "findVertex", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo he_emlrtRSI =
    {
        195,          /* lineNo */
        "findVertex", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo ie_emlrtRSI =
    {
        196,          /* lineNo */
        "findVertex", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo je_emlrtRSI =
    {
        197,          /* lineNo */
        "findVertex", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo ke_emlrtRSI =
    {
        209,          /* lineNo */
        "findVertex", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo le_emlrtRSI =
    {
        222,            /* lineNo */
        "findLongEdge", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo me_emlrtRSI =
    {
        223,            /* lineNo */
        "findLongEdge", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtECInfo emlrtECI =
    {
        1,                   /* nDims */
        269,                 /* lineNo */
        31,                  /* colNo */
        "calculateVariance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtECInfo b_emlrtECI =
    {
        1,                   /* nDims */
        268,                 /* lineNo */
        31,                  /* colNo */
        "calculateVariance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtBCInfo b_emlrtBCI =
    {
        -1,                  /* iFirst */
        -1,                  /* iLast */
        268,                 /* lineNo */
        31,                  /* colNo */
        "",                  /* aName */
        "calculateVariance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI =
    {
        -1,                  /* iFirst */
        -1,                  /* iLast */
        269,                 /* lineNo */
        31,                  /* colNo */
        "",                  /* aName */
        "calculateVariance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtECInfo c_emlrtECI =
    {
        1,                   /* nDims */
        292,                 /* lineNo */
        9,                   /* colNo */
        "getDistanceMatrix", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtECInfo d_emlrtECI =
    {
        1,                   /* nDims */
        290,                 /* lineNo */
        13,                  /* colNo */
        "getDistanceMatrix", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtECInfo e_emlrtECI =
    {
        1,                   /* nDims */
        289,                 /* lineNo */
        13,                  /* colNo */
        "getDistanceMatrix", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtBCInfo d_emlrtBCI =
    {
        -1,                  /* iFirst */
        -1,                  /* iLast */
        293,                 /* lineNo */
        31,                  /* colNo */
        "",                  /* aName */
        "getDistanceMatrix", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI =
    {
        -1,                  /* iFirst */
        -1,                  /* iLast */
        293,                 /* lineNo */
        1,                   /* colNo */
        "",                  /* aName */
        "getDistanceMatrix", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtRTEInfo n_emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo qb_emlrtRTEI =
    {
        268,           /* lineNo */
        31,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo rb_emlrtRTEI =
    {
        161,           /* lineNo */
        42,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo sb_emlrtRTEI =
    {
        269,           /* lineNo */
        31,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo tb_emlrtRTEI =
    {
        268,           /* lineNo */
        21,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo ub_emlrtRTEI =
    {
        269,           /* lineNo */
        21,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo vb_emlrtRTEI =
    {
        166,           /* lineNo */
        1,             /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo wb_emlrtRTEI =
    {
        167,           /* lineNo */
        1,             /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo xb_emlrtRTEI =
    {
        181,           /* lineNo */
        1,             /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo yb_emlrtRTEI =
    {
        182,           /* lineNo */
        1,             /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo ac_emlrtRTEI =
    {
        261,           /* lineNo */
        1,             /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo bc_emlrtRTEI =
    {
        289,           /* lineNo */
        13,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo cc_emlrtRTEI =
    {
        290,           /* lineNo */
        13,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo dc_emlrtRTEI =
    {
        292,           /* lineNo */
        9,             /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo ec_emlrtRTEI =
    {
        281,           /* lineNo */
        27,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo fc_emlrtRTEI =
    {
        289,           /* lineNo */
        1,             /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo gc_emlrtRTEI =
    {
        293,           /* lineNo */
        16,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRSInfo we_emlrtRSI =
    {
        292,                 /* lineNo */
        "getDistanceMatrix", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo xe_emlrtRSI =
    {
        268,                 /* lineNo */
        "calculateVariance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo ye_emlrtRSI =
    {
        269,                 /* lineNo */
        "calculateVariance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

/* Function Declarations */
static void b_binary_expand_op(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               const emxArray_real_T *in4);

static void binary_expand_op(const emlrtStack *sp, emxArray_boolean_T *in1,
                             const emxArray_real_T *in2, int32_T in3,
                             const emxArray_real_T *in4);

static void c_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                               const emlrtRSInfo in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4);

static void d_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                               const emlrtRSInfo in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4);

static void findIntersectionPoint(const real_T A[3], const real_T B[3],
                                  real_T point[2]);

static real_T findLongEdge(const emlrtStack *sp, const real_T vertices[8],
                           real_T longVertex[2], real_T *width);

static void findVertex(const emlrtStack *sp, real_T theta,
                       const emxArray_real_T *projection1,
                       const emxArray_real_T *projection2,
                       real_T boundingBox2d[5]);

static void getDistanceMatrix(const emlrtStack *sp,
                              const emxArray_real_T *projections,
                              emxArray_real_T *distanceMatrix);

static void lt(const emlrtStack *sp, emxArray_boolean_T *in1,
               const emxArray_real_T *in2, const emxArray_real_T *in3);

/* Function Definitions */
static void b_binary_expand_op(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               const emxArray_real_T *in4)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  if (in4->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &qb_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0 + in2->size[0] * in3] <=
                   in4_data[i * stride_1_0 + in4->size[0] * in3]);
  }
}

static void binary_expand_op(const emlrtStack *sp, emxArray_boolean_T *in1,
                             const emxArray_real_T *in2, int32_T in3,
                             const emxArray_real_T *in4)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  if (in4->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &sb_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0 + in2->size[0] * in3] <
                   in4_data[i * stride_1_0 + in4->size[0] * in3]);
  }
}

static void c_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                               const emlrtRSInfo in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4)
{
  emlrtStack st;
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  const real_T *in4_data;
  real_T *b_in3_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in3, 2, &cc_emlrtRTEI);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = b_in3->size[0] * b_in3->size[1];
  b_in3->size[0] = loop_ub;
  b_in3->size[1] = 91;
  emxEnsureCapacity_real_T(sp, b_in3, i, &cc_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  for (i = 0; i < 91; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in3_data[i1 + b_in3->size[0] * i] =
          in3_data[i1 * stride_0_0 + in3->size[0] * i] -
          in4_data[i1 * stride_1_0 + in4->size[0] * i];
    }
  }
  st.site = (emlrtRSInfo *)&in2;
  b_abs(&st, b_in3, in1);
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void d_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                               const emlrtRSInfo in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4)
{
  emlrtStack st;
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  const real_T *in4_data;
  real_T *b_in3_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in3, 2, &bc_emlrtRTEI);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = b_in3->size[0] * b_in3->size[1];
  b_in3->size[0] = loop_ub;
  b_in3->size[1] = 91;
  emxEnsureCapacity_real_T(sp, b_in3, i, &bc_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  for (i = 0; i < 91; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in3_data[i1 + b_in3->size[0] * i] =
          in3_data[i1 * stride_0_0 + in3->size[0] * i] -
          in4_data[i1 * stride_1_0 + in4->size[0] * i];
    }
  }
  st.site = (emlrtRSInfo *)&in2;
  b_abs(&st, b_in3, in1);
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void findIntersectionPoint(const real_T A[3], const real_T B[3],
                                  real_T point[2])
{
  if (A[1] == 0.0) {
    point[0] = A[2] / A[0];
  } else if (B[1] == 0.0) {
    point[0] = B[2] / B[0];
  } else {
    point[0] = (B[2] / B[1] - A[2] / A[1]) / (B[0] / B[1] - A[0] / A[1]);
  }
  if (A[1] != 0.0) {
    point[1] = -A[0] * point[0] / A[1] + A[2] / A[1];
  } else {
    point[1] = -B[0] * point[0] / B[1] + B[2] / B[1];
  }
}

static real_T findLongEdge(const emlrtStack *sp, const real_T vertices[8],
                           real_T longVertex[2], real_T *width)
{
  emlrtStack st;
  real_T y[2];
  real_T distance2;
  real_T length;
  st.prev = sp;
  st.tls = sp->tls;
  distance2 = vertices[0] - vertices[1];
  y[0] = distance2 * distance2;
  distance2 = vertices[4] - vertices[5];
  y[1] = distance2 * distance2;
  *width = c_sumColumnB(y);
  st.site = &le_emlrtRSI;
  if (*width < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &n_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *width = muDoubleScalarSqrt(*width);
  distance2 = vertices[2] - vertices[1];
  y[0] = distance2 * distance2;
  distance2 = vertices[6] - vertices[5];
  y[1] = distance2 * distance2;
  distance2 = c_sumColumnB(y);
  st.site = &me_emlrtRSI;
  if (distance2 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &n_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  distance2 = muDoubleScalarSqrt(distance2);
  if (*width > distance2) {
    longVertex[0] = vertices[0];
    longVertex[1] = vertices[4];
    length = *width;
    *width = distance2;
  } else {
    longVertex[0] = vertices[2];
    longVertex[1] = vertices[6];
    length = distance2;
  }
  return length;
}

static void findVertex(const emlrtStack *sp, real_T theta,
                       const emxArray_real_T *projection1,
                       const emxArray_real_T *projection2,
                       real_T boundingBox2d[5])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  real_T vertices[8];
  real_T A[3];
  real_T B[3];
  real_T b_A_tmp[3];
  real_T longVertex[2];
  const real_T *projection1_data;
  const real_T *projection2_data;
  real_T A_tmp;
  real_T b_ex;
  real_T d;
  real_T ex;
  real_T yaw;
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
  boolean_T exitg1;
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
  projection2_data = projection2->data;
  projection1_data = projection1->data;
  yaw = theta;
  b_sind(&yaw);
  A_tmp = theta;
  b_cosd(&A_tmp);
  st.site = &ge_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (projection1->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  last = projection1->size[0];
  if (projection1->size[0] <= 2) {
    if (projection1->size[0] == 1) {
      ex = projection1_data[0];
    } else if ((projection1_data[0] > projection1_data[1]) ||
               (muDoubleScalarIsNaN(projection1_data[0]) &&
                (!muDoubleScalarIsNaN(projection1_data[1])))) {
      ex = projection1_data[1];
    } else {
      ex = projection1_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(projection1_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (projection1->size[0] > 2147483646) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(projection1_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = projection1_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      ex = projection1_data[idx - 1];
      a = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= projection1->size[0]) &&
          (projection1->size[0] > 2147483646)) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = a; k <= last; k++) {
        d = projection1_data[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  A[0] = A_tmp;
  A[1] = yaw;
  A[2] = ex;
  st.site = &he_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (projection2->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  last = projection2->size[0];
  if (projection2->size[0] <= 2) {
    if (projection2->size[0] == 1) {
      ex = projection2_data[0];
    } else if ((projection2_data[0] > projection2_data[1]) ||
               (muDoubleScalarIsNaN(projection2_data[0]) &&
                (!muDoubleScalarIsNaN(projection2_data[1])))) {
      ex = projection2_data[1];
    } else {
      ex = projection2_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(projection2_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (projection2->size[0] > 2147483646) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(projection2_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = projection2_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      ex = projection2_data[idx - 1];
      a = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= projection2->size[0]) &&
          (projection2->size[0] > 2147483646)) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = a; k <= last; k++) {
        d = projection2_data[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  B[0] = -yaw;
  B[1] = A_tmp;
  B[2] = ex;
  st.site = &ie_emlrtRSI;
  b_st.site = &hc_emlrtRSI;
  c_st.site = &ic_emlrtRSI;
  d_st.site = &jc_emlrtRSI;
  e_st.site = &kc_emlrtRSI;
  f_st.site = &lc_emlrtRSI;
  last = projection1->size[0];
  if (projection1->size[0] <= 2) {
    if (projection1->size[0] == 1) {
      ex = projection1_data[0];
    } else if ((projection1_data[0] < projection1_data[1]) ||
               (muDoubleScalarIsNaN(projection1_data[0]) &&
                (!muDoubleScalarIsNaN(projection1_data[1])))) {
      ex = projection1_data[1];
    } else {
      ex = projection1_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(projection1_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (projection1->size[0] > 2147483646) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(projection1_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = projection1_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      ex = projection1_data[idx - 1];
      a = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= projection1->size[0]) &&
          (projection1->size[0] > 2147483646)) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = a; k <= last; k++) {
        d = projection1_data[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  st.site = &je_emlrtRSI;
  b_st.site = &hc_emlrtRSI;
  c_st.site = &ic_emlrtRSI;
  d_st.site = &jc_emlrtRSI;
  e_st.site = &kc_emlrtRSI;
  f_st.site = &lc_emlrtRSI;
  last = projection2->size[0];
  if (projection2->size[0] <= 2) {
    if (projection2->size[0] == 1) {
      b_ex = projection2_data[0];
    } else if ((projection2_data[0] < projection2_data[1]) ||
               (muDoubleScalarIsNaN(projection2_data[0]) &&
                (!muDoubleScalarIsNaN(projection2_data[1])))) {
      b_ex = projection2_data[1];
    } else {
      b_ex = projection2_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(projection2_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (projection2->size[0] > 2147483646) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(projection2_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      b_ex = projection2_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      b_ex = projection2_data[idx - 1];
      a = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= projection2->size[0]) &&
          (projection2->size[0] > 2147483646)) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = a; k <= last; k++) {
        d = projection2_data[k - 1];
        if (b_ex < d) {
          b_ex = d;
        }
      }
    }
  }
  b_A_tmp[0] = A_tmp;
  b_A_tmp[1] = yaw;
  b_A_tmp[2] = ex;
  findIntersectionPoint(B, b_A_tmp, longVertex);
  vertices[0] = longVertex[0];
  vertices[4] = longVertex[1];
  findIntersectionPoint(A, B, longVertex);
  vertices[1] = longVertex[0];
  vertices[5] = longVertex[1];
  B[0] = -yaw;
  B[1] = A_tmp;
  B[2] = b_ex;
  findIntersectionPoint(A, B, longVertex);
  vertices[2] = longVertex[0];
  vertices[6] = longVertex[1];
  vertices[3] = (vertices[0] + longVertex[0]) - vertices[1];
  vertices[7] = (longVertex[1] + vertices[4]) - vertices[5];
  st.site = &ke_emlrtRSI;
  A_tmp = findLongEdge(&st, vertices, longVertex, &ex);
  d = vertices[5] - longVertex[1];
  if (d != 0.0) {
    yaw = 57.295779513082323 *
          muDoubleScalarAtan(d / (vertices[1] - longVertex[0]));
  } else {
    yaw = 0.0;
  }
  boundingBox2d[0] = (vertices[1] + vertices[3]) / 2.0;
  boundingBox2d[1] = (vertices[5] + vertices[7]) / 2.0;
  boundingBox2d[2] = A_tmp;
  boundingBox2d[3] = ex;
  boundingBox2d[4] = yaw;
}

static void getDistanceMatrix(const emlrtStack *sp,
                              const emxArray_real_T *projections,
                              emxArray_real_T *distanceMatrix)
{
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_boolean_T *r2;
  emxArray_int32_T *r4;
  emxArray_real_T *c_projections;
  emxArray_real_T *r;
  emxArray_real_T *toMax;
  real_T Cmax[91];
  real_T Cmin[91];
  real_T b_projections[2];
  const real_T *projections_data;
  real_T b;
  real_T d;
  real_T *b_projections_data;
  real_T *distanceMatrix_data;
  real_T *toMax_data;
  int32_T b_i;
  int32_T i;
  int32_T j;
  int32_T m;
  int32_T *r5;
  boolean_T overflow;
  boolean_T p;
  boolean_T *r3;
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
  projections_data = projections->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &dd_emlrtRSI;
  b_st.site = &hc_emlrtRSI;
  c_st.site = &ic_emlrtRSI;
  d_st.site = &jc_emlrtRSI;
  if (projections->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &hd_emlrtRSI;
  f_st.site = &id_emlrtRSI;
  g_st.site = &jd_emlrtRSI;
  m = projections->size[0];
  overflow = (projections->size[0] > 2147483646);
  for (j = 0; j < 91; j++) {
    Cmax[j] = projections_data[projections->size[0] * j];
    h_st.site = &kd_emlrtRSI;
    if (overflow) {
      i_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }
    for (i = 2; i <= m; i++) {
      b = projections_data[(i + projections->size[0] * j) - 1];
      if (muDoubleScalarIsNaN(b)) {
        p = false;
      } else {
        d = Cmax[j];
        if (muDoubleScalarIsNaN(d)) {
          p = true;
        } else {
          p = (d < b);
        }
      }
      if (p) {
        Cmax[j] = b;
      }
    }
  }
  st.site = &ed_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  e_st.site = &hd_emlrtRSI;
  f_st.site = &id_emlrtRSI;
  g_st.site = &jd_emlrtRSI;
  m = projections->size[0];
  overflow = (projections->size[0] > 2147483646);
  for (j = 0; j < 91; j++) {
    Cmin[j] = projections_data[projections->size[0] * j];
    h_st.site = &kd_emlrtRSI;
    if (overflow) {
      i_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }
    for (i = 2; i <= m; i++) {
      b = projections_data[(i + projections->size[0] * j) - 1];
      if (muDoubleScalarIsNaN(b)) {
        p = false;
      } else {
        d = Cmin[j];
        if (muDoubleScalarIsNaN(d)) {
          p = true;
        } else {
          p = (d > b);
        }
      }
      if (p) {
        Cmin[j] = b;
      }
    }
  }
  b_projections[0] = projections->size[0];
  b_projections[1] = 1.0;
  emxInit_real_T(sp, &r, 2, &bc_emlrtRTEI);
  st.site = &fd_emlrtRSI;
  repmat(&st, Cmax, b_projections, r);
  distanceMatrix_data = r->data;
  if ((r->size[0] != projections->size[0]) &&
      ((r->size[0] != 1) && (projections->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[0], projections->size[0], &e_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &toMax, 2, &fc_emlrtRTEI);
  emxInit_real_T(sp, &c_projections, 2, &cc_emlrtRTEI);
  if (r->size[0] == projections->size[0]) {
    b_i = c_projections->size[0] * c_projections->size[1];
    c_projections->size[0] = r->size[0];
    c_projections->size[1] = 91;
    emxEnsureCapacity_real_T(sp, c_projections, b_i, &bc_emlrtRTEI);
    b_projections_data = c_projections->data;
    i = r->size[0] * 91;
    m = (i / 2) << 1;
    j = m - 2;
    for (b_i = 0; b_i <= j; b_i += 2) {
      r1 = _mm_loadu_pd(&distanceMatrix_data[b_i]);
      _mm_storeu_pd(&b_projections_data[b_i],
                    _mm_sub_pd(r1, _mm_loadu_pd(&projections_data[b_i])));
    }
    for (b_i = m; b_i < i; b_i++) {
      b_projections_data[b_i] =
          distanceMatrix_data[b_i] - projections_data[b_i];
    }
    st.site = &fd_emlrtRSI;
    b_abs(&st, c_projections, toMax);
    toMax_data = toMax->data;
  } else {
    st.site = &fd_emlrtRSI;
    d_binary_expand_op(&st, toMax, fd_emlrtRSI, r, projections);
    toMax_data = toMax->data;
  }
  b_projections[0] = projections->size[0];
  b_projections[1] = 1.0;
  st.site = &gd_emlrtRSI;
  repmat(&st, Cmin, b_projections, r);
  distanceMatrix_data = r->data;
  if ((projections->size[0] != r->size[0]) &&
      ((projections->size[0] != 1) && (r->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(projections->size[0], r->size[0], &d_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (projections->size[0] == r->size[0]) {
    b_i = c_projections->size[0] * c_projections->size[1];
    c_projections->size[0] = projections->size[0];
    c_projections->size[1] = 91;
    emxEnsureCapacity_real_T(sp, c_projections, b_i, &cc_emlrtRTEI);
    b_projections_data = c_projections->data;
    i = projections->size[0] * 91;
    m = (i / 2) << 1;
    j = m - 2;
    for (b_i = 0; b_i <= j; b_i += 2) {
      r1 = _mm_loadu_pd(&distanceMatrix_data[b_i]);
      _mm_storeu_pd(&b_projections_data[b_i],
                    _mm_sub_pd(_mm_loadu_pd(&projections_data[b_i]), r1));
    }
    for (b_i = m; b_i < i; b_i++) {
      b_projections_data[b_i] =
          projections_data[b_i] - distanceMatrix_data[b_i];
    }
    st.site = &gd_emlrtRSI;
    b_abs(&st, c_projections, distanceMatrix);
    distanceMatrix_data = distanceMatrix->data;
  } else {
    st.site = &gd_emlrtRSI;
    c_binary_expand_op(&st, distanceMatrix, gd_emlrtRSI, projections, r);
    distanceMatrix_data = distanceMatrix->data;
  }
  emxFree_real_T(sp, &c_projections);
  emxFree_real_T(sp, &r);
  if ((toMax->size[0] != distanceMatrix->size[0]) &&
      ((toMax->size[0] != 1) && (distanceMatrix->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(toMax->size[0], distanceMatrix->size[0],
                                &c_emlrtECI, (emlrtConstCTX)sp);
  }
  emxInit_boolean_T(sp, &r2, 2, &dc_emlrtRTEI);
  if (toMax->size[0] == distanceMatrix->size[0]) {
    b_i = r2->size[0] * r2->size[1];
    r2->size[0] = toMax->size[0];
    r2->size[1] = 91;
    emxEnsureCapacity_boolean_T(sp, r2, b_i, &dc_emlrtRTEI);
    r3 = r2->data;
    i = toMax->size[0] * 91;
    for (b_i = 0; b_i < i; b_i++) {
      r3[b_i] = (toMax_data[b_i] < distanceMatrix_data[b_i]);
    }
  } else {
    st.site = &we_emlrtRSI;
    lt(&st, r2, toMax, distanceMatrix);
    r3 = r2->data;
  }
  j = r2->size[0] * 91 - 1;
  m = 0;
  for (i = 0; i <= j; i++) {
    if (r3[i]) {
      m++;
    }
  }
  emxInit_int32_T(sp, &r4, &gc_emlrtRTEI);
  b_i = r4->size[0];
  r4->size[0] = m;
  emxEnsureCapacity_int32_T(sp, r4, b_i, &ec_emlrtRTEI);
  r5 = r4->data;
  m = 0;
  for (i = 0; i <= j; i++) {
    if (r3[i]) {
      r5[m] = i;
      m++;
    }
  }
  emxFree_boolean_T(sp, &r2);
  m = toMax->size[0] * 91;
  i = r4->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (r5[b_i] > m - 1) {
      emlrtDynamicBoundsCheckR2012b(r5[b_i], 0, m - 1, &d_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
  }
  m = distanceMatrix->size[0] * 91;
  i = r4->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (r5[b_i] > m - 1) {
      emlrtDynamicBoundsCheckR2012b(r5[b_i], 0, m - 1, &e_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    distanceMatrix_data[r5[b_i]] = toMax_data[r5[b_i]];
  }
  emxFree_int32_T(sp, &r4);
  emxFree_real_T(sp, &toMax);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void lt(const emlrtStack *sp, emxArray_boolean_T *in1,
               const emxArray_real_T *in2, const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = 91;
  emxEnsureCapacity_boolean_T(sp, in1, i, &dc_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < 91; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          (in2_data[i1 * stride_0_0 + in2->size[0] * i] <
           in3_data[i1 * stride_1_0 + in3->size[0] * i]);
    }
  }
}

real_T findBoundingBox(const emlrtStack *sp, const emxArray_real_T *X,
                       real_T boundingBox2d[5], real_T *score)
{
  static const real_T B[182] = {1.0,
                                0.99984769515639127,
                                0.99939082701909576,
                                0.99862953475457383,
                                0.9975640502598242,
                                0.99619469809174555,
                                0.99452189536827329,
                                0.992546151641322,
                                0.99026806874157036,
                                0.98768834059513777,
                                0.984807753012208,
                                0.981627183447664,
                                0.97814760073380569,
                                0.97437006478523525,
                                0.97029572627599647,
                                0.96592582628906831,
                                0.96126169593831889,
                                0.95630475596303544,
                                0.95105651629515353,
                                0.94551857559931685,
                                0.93969262078590843,
                                0.93358042649720174,
                                0.92718385456678742,
                                0.92050485345244037,
                                0.91354545764260087,
                                0.90630778703664994,
                                0.898794046299167,
                                0.8910065241883679,
                                0.882947592858927,
                                0.87461970713939574,
                                0.86602540378443871,
                                0.85716730070211233,
                                0.848048096156426,
                                0.838670567945424,
                                0.82903757255504162,
                                0.8191520442889918,
                                0.80901699437494745,
                                0.79863551004729283,
                                0.7880107536067219,
                                0.7771459614569709,
                                0.766044443118978,
                                0.754709580222772,
                                0.74314482547739424,
                                0.73135370161917046,
                                0.71933980033865119,
                                0.70710678118654757,
                                0.69465837045899725,
                                0.68199836006249848,
                                0.66913060635885824,
                                0.65605902899050728,
                                0.64278760968653925,
                                0.62932039104983739,
                                0.61566147532565829,
                                0.60181502315204827,
                                0.58778525229247314,
                                0.573576436351046,
                                0.5591929034707469,
                                0.54463903501502708,
                                0.5299192642332049,
                                0.51503807491005416,
                                0.49999999999999994,
                                0.48480962024633706,
                                0.46947156278589081,
                                0.45399049973954675,
                                0.4383711467890774,
                                0.42261826174069944,
                                0.40673664307580021,
                                0.39073112848927377,
                                0.374606593415912,
                                0.35836794954530027,
                                0.34202014332566871,
                                0.3255681544571567,
                                0.3090169943749474,
                                0.29237170472273677,
                                0.27563735581699916,
                                0.25881904510252074,
                                0.24192189559966773,
                                0.224951054343865,
                                0.20791169081775934,
                                0.1908089953765448,
                                0.17364817766693033,
                                0.15643446504023087,
                                0.13917310096006544,
                                0.12186934340514748,
                                0.10452846326765347,
                                0.087155742747658166,
                                0.0697564737441253,
                                0.052335956242943835,
                                0.034899496702500969,
                                0.017452406437283512,
                                -0.0,
                                0.0,
                                0.017452406437283512,
                                0.034899496702500969,
                                0.052335956242943835,
                                0.0697564737441253,
                                0.087155742747658166,
                                0.10452846326765347,
                                0.12186934340514748,
                                0.13917310096006544,
                                0.15643446504023087,
                                0.17364817766693033,
                                0.1908089953765448,
                                0.20791169081775934,
                                0.224951054343865,
                                0.24192189559966773,
                                0.25881904510252074,
                                0.27563735581699916,
                                0.29237170472273677,
                                0.3090169943749474,
                                0.3255681544571567,
                                0.34202014332566871,
                                0.35836794954530027,
                                0.374606593415912,
                                0.39073112848927377,
                                0.40673664307580021,
                                0.42261826174069944,
                                0.4383711467890774,
                                0.45399049973954675,
                                0.46947156278589081,
                                0.48480962024633706,
                                0.49999999999999994,
                                0.51503807491005416,
                                0.5299192642332049,
                                0.54463903501502708,
                                0.5591929034707469,
                                0.573576436351046,
                                0.58778525229247314,
                                0.60181502315204827,
                                0.61566147532565829,
                                0.62932039104983739,
                                0.64278760968653925,
                                0.65605902899050728,
                                0.66913060635885824,
                                0.68199836006249848,
                                0.69465837045899725,
                                0.70710678118654746,
                                0.71933980033865119,
                                0.73135370161917046,
                                0.74314482547739424,
                                0.754709580222772,
                                0.766044443118978,
                                0.7771459614569709,
                                0.7880107536067219,
                                0.79863551004729283,
                                0.80901699437494745,
                                0.8191520442889918,
                                0.82903757255504162,
                                0.838670567945424,
                                0.848048096156426,
                                0.85716730070211233,
                                0.86602540378443871,
                                0.87461970713939574,
                                0.882947592858927,
                                0.8910065241883679,
                                0.898794046299167,
                                0.90630778703664994,
                                0.91354545764260087,
                                0.92050485345244037,
                                0.92718385456678742,
                                0.93358042649720174,
                                0.93969262078590843,
                                0.94551857559931685,
                                0.95105651629515353,
                                0.95630475596303544,
                                0.96126169593831889,
                                0.96592582628906831,
                                0.97029572627599647,
                                0.97437006478523525,
                                0.97814760073380569,
                                0.981627183447664,
                                0.984807753012208,
                                0.98768834059513777,
                                0.99026806874157036,
                                0.992546151641322,
                                0.99452189536827329,
                                0.99619469809174555,
                                0.9975640502598242,
                                0.99862953475457383,
                                0.99939082701909576,
                                0.99984769515639127,
                                1.0};
  static const real_T b_B[182] = {-0.0,
                                  -0.017452406437283512,
                                  -0.034899496702500969,
                                  -0.052335956242943835,
                                  -0.0697564737441253,
                                  -0.087155742747658166,
                                  -0.10452846326765347,
                                  -0.12186934340514748,
                                  -0.13917310096006544,
                                  -0.15643446504023087,
                                  -0.17364817766693033,
                                  -0.1908089953765448,
                                  -0.20791169081775934,
                                  -0.224951054343865,
                                  -0.24192189559966773,
                                  -0.25881904510252074,
                                  -0.27563735581699916,
                                  -0.29237170472273677,
                                  -0.3090169943749474,
                                  -0.3255681544571567,
                                  -0.34202014332566871,
                                  -0.35836794954530027,
                                  -0.374606593415912,
                                  -0.39073112848927377,
                                  -0.40673664307580021,
                                  -0.42261826174069944,
                                  -0.4383711467890774,
                                  -0.45399049973954675,
                                  -0.46947156278589081,
                                  -0.48480962024633706,
                                  -0.49999999999999994,
                                  -0.51503807491005416,
                                  -0.5299192642332049,
                                  -0.54463903501502708,
                                  -0.5591929034707469,
                                  -0.573576436351046,
                                  -0.58778525229247314,
                                  -0.60181502315204827,
                                  -0.61566147532565829,
                                  -0.62932039104983739,
                                  -0.64278760968653925,
                                  -0.65605902899050728,
                                  -0.66913060635885824,
                                  -0.68199836006249848,
                                  -0.69465837045899725,
                                  -0.70710678118654746,
                                  -0.71933980033865119,
                                  -0.73135370161917046,
                                  -0.74314482547739424,
                                  -0.754709580222772,
                                  -0.766044443118978,
                                  -0.7771459614569709,
                                  -0.7880107536067219,
                                  -0.79863551004729283,
                                  -0.80901699437494745,
                                  -0.8191520442889918,
                                  -0.82903757255504162,
                                  -0.838670567945424,
                                  -0.848048096156426,
                                  -0.85716730070211233,
                                  -0.86602540378443871,
                                  -0.87461970713939574,
                                  -0.882947592858927,
                                  -0.8910065241883679,
                                  -0.898794046299167,
                                  -0.90630778703664994,
                                  -0.91354545764260087,
                                  -0.92050485345244037,
                                  -0.92718385456678742,
                                  -0.93358042649720174,
                                  -0.93969262078590843,
                                  -0.94551857559931685,
                                  -0.95105651629515353,
                                  -0.95630475596303544,
                                  -0.96126169593831889,
                                  -0.96592582628906831,
                                  -0.97029572627599647,
                                  -0.97437006478523525,
                                  -0.97814760073380569,
                                  -0.981627183447664,
                                  -0.984807753012208,
                                  -0.98768834059513777,
                                  -0.99026806874157036,
                                  -0.992546151641322,
                                  -0.99452189536827329,
                                  -0.99619469809174555,
                                  -0.9975640502598242,
                                  -0.99862953475457383,
                                  -0.99939082701909576,
                                  -0.99984769515639127,
                                  -1.0,
                                  1.0,
                                  0.99984769515639127,
                                  0.99939082701909576,
                                  0.99862953475457383,
                                  0.9975640502598242,
                                  0.99619469809174555,
                                  0.99452189536827329,
                                  0.992546151641322,
                                  0.99026806874157036,
                                  0.98768834059513777,
                                  0.984807753012208,
                                  0.981627183447664,
                                  0.97814760073380569,
                                  0.97437006478523525,
                                  0.97029572627599647,
                                  0.96592582628906831,
                                  0.96126169593831889,
                                  0.95630475596303544,
                                  0.95105651629515353,
                                  0.94551857559931685,
                                  0.93969262078590843,
                                  0.93358042649720174,
                                  0.92718385456678742,
                                  0.92050485345244037,
                                  0.91354545764260087,
                                  0.90630778703664994,
                                  0.898794046299167,
                                  0.8910065241883679,
                                  0.882947592858927,
                                  0.87461970713939574,
                                  0.86602540378443871,
                                  0.85716730070211233,
                                  0.848048096156426,
                                  0.838670567945424,
                                  0.82903757255504162,
                                  0.8191520442889918,
                                  0.80901699437494745,
                                  0.79863551004729283,
                                  0.7880107536067219,
                                  0.7771459614569709,
                                  0.766044443118978,
                                  0.754709580222772,
                                  0.74314482547739424,
                                  0.73135370161917046,
                                  0.71933980033865119,
                                  0.70710678118654757,
                                  0.69465837045899725,
                                  0.68199836006249848,
                                  0.66913060635885824,
                                  0.65605902899050728,
                                  0.64278760968653925,
                                  0.62932039104983739,
                                  0.61566147532565829,
                                  0.60181502315204827,
                                  0.58778525229247314,
                                  0.573576436351046,
                                  0.5591929034707469,
                                  0.54463903501502708,
                                  0.5299192642332049,
                                  0.51503807491005416,
                                  0.49999999999999994,
                                  0.48480962024633706,
                                  0.46947156278589081,
                                  0.45399049973954675,
                                  0.4383711467890774,
                                  0.42261826174069944,
                                  0.40673664307580021,
                                  0.39073112848927377,
                                  0.374606593415912,
                                  0.35836794954530027,
                                  0.34202014332566871,
                                  0.3255681544571567,
                                  0.3090169943749474,
                                  0.29237170472273677,
                                  0.27563735581699916,
                                  0.25881904510252074,
                                  0.24192189559966773,
                                  0.224951054343865,
                                  0.20791169081775934,
                                  0.1908089953765448,
                                  0.17364817766693033,
                                  0.15643446504023087,
                                  0.13917310096006544,
                                  0.12186934340514748,
                                  0.10452846326765347,
                                  0.087155742747658166,
                                  0.0697564737441253,
                                  0.052335956242943835,
                                  0.034899496702500969,
                                  0.017452406437283512,
                                  -0.0};
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
  emxArray_boolean_T *r2;
  emxArray_boolean_T *r3;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *C1key;
  emxArray_real_T *C2key;
  emxArray_real_T *distance1;
  emxArray_real_T *projection1;
  emxArray_real_T *projection2;
  real_T scores[91];
  real_T dv[2];
  const real_T *X_data;
  real_T alpha1;
  real_T beta1;
  real_T d;
  real_T theta;
  real_T *C1key_data;
  real_T *projection1_data;
  real_T *projection2_data;
  int32_T b_i;
  int32_T c_i;
  int32_T end;
  int32_T i;
  int32_T idx;
  int32_T *r5;
  int32_T *r6;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T b;
  boolean_T exitg1;
  boolean_T *r4;
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
  X_data = X->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &mc_emlrtRSI;
  b_st.site = &qc_emlrtRSI;
  c_st.site = &vc_emlrtRSI;
  emxInit_real_T(&c_st, &projection1, 2, &xb_emlrtRTEI);
  if (X->size[0] == 0) {
    projection1->size[0] = 0;
    projection1->size[1] = 91;
  } else {
    d_st.site = &wc_emlrtRSI;
    e_st.site = &xc_emlrtRSI;
    TRANSB1 = 'T';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)X->size[0];
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)2;
    lda_t = (ptrdiff_t)X->size[0];
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)X->size[0];
    i = projection1->size[0] * projection1->size[1];
    projection1->size[0] = X->size[0];
    projection1->size[1] = 91;
    emxEnsureCapacity_real_T(&e_st, projection1, i, &pb_emlrtRTEI);
    projection1_data = projection1->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&X_data[0],
          &lda_t, (real_T *)&B[0], &ldb_t, &beta1, &projection1_data[0],
          &ldc_t);
  }
  b_st.site = &rc_emlrtRSI;
  c_st.site = &vc_emlrtRSI;
  emxInit_real_T(&c_st, &projection2, 2, &yb_emlrtRTEI);
  if (X->size[0] == 0) {
    projection2->size[0] = 0;
    projection2->size[1] = 91;
  } else {
    d_st.site = &wc_emlrtRSI;
    e_st.site = &xc_emlrtRSI;
    TRANSB1 = 'T';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)X->size[0];
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)2;
    lda_t = (ptrdiff_t)X->size[0];
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)X->size[0];
    i = projection2->size[0] * projection2->size[1];
    projection2->size[0] = X->size[0];
    projection2->size[1] = 91;
    emxEnsureCapacity_real_T(&e_st, projection2, i, &pb_emlrtRTEI);
    projection2_data = projection2->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&X_data[0],
          &lda_t, (real_T *)&b_B[0], &ldb_t, &beta1, &projection2_data[0],
          &ldc_t);
  }
  b_st.site = &sc_emlrtRSI;
  emxInit_real_T(&b_st, &distance1, 2, &ac_emlrtRTEI);
  c_st.site = &yc_emlrtRSI;
  getDistanceMatrix(&c_st, projection1, distance1);
  projection2_data = distance1->data;
  c_st.site = &ad_emlrtRSI;
  getDistanceMatrix(&c_st, projection2, projection1);
  projection1_data = projection1->data;
  emxFree_real_T(&b_st, &projection2);
  memset(&scores[0], 0, 91U * sizeof(real_T));
  emxInit_real_T(&b_st, &C1key, 1, &vb_emlrtRTEI);
  emxInit_int32_T(&b_st, &r, &qb_emlrtRTEI);
  emxInit_int32_T(&b_st, &r1, &sb_emlrtRTEI);
  emxInit_boolean_T(&b_st, &r2, 1, &qb_emlrtRTEI);
  emxInit_boolean_T(&b_st, &r3, 1, &sb_emlrtRTEI);
  for (b_i = 0; b_i < 91; b_i++) {
    idx = distance1->size[0];
    if ((distance1->size[0] != projection1->size[0]) &&
        ((distance1->size[0] != 1) && (projection1->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(distance1->size[0], projection1->size[0],
                                  &b_emlrtECI, &b_st);
    }
    if (distance1->size[0] == projection1->size[0]) {
      i = r2->size[0];
      r2->size[0] = distance1->size[0];
      emxEnsureCapacity_boolean_T(&b_st, r2, i, &qb_emlrtRTEI);
      r4 = r2->data;
      for (i = 0; i < idx; i++) {
        r4[i] = (projection2_data[i + distance1->size[0] * b_i] <=
                 projection1_data[i + projection1->size[0] * b_i]);
      }
    } else {
      c_st.site = &xe_emlrtRSI;
      b_binary_expand_op(&c_st, r2, distance1, b_i, projection1);
      r4 = r2->data;
    }
    end = r2->size[0] - 1;
    idx = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (r4[c_i]) {
        idx++;
      }
    }
    i = r->size[0];
    r->size[0] = idx;
    emxEnsureCapacity_int32_T(&b_st, r, i, &rb_emlrtRTEI);
    r5 = r->data;
    idx = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (r4[c_i]) {
        r5[idx] = c_i;
        idx++;
      }
    }
    idx = r->size[0];
    for (i = 0; i < idx; i++) {
      if (r5[i] > distance1->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(r5[i], 0, distance1->size[0] - 1,
                                      &b_emlrtBCI, &b_st);
      }
    }
    idx = projection1->size[0];
    if ((projection1->size[0] != distance1->size[0]) &&
        ((projection1->size[0] != 1) && (distance1->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(projection1->size[0], distance1->size[0],
                                  &emlrtECI, &b_st);
    }
    if (projection1->size[0] == distance1->size[0]) {
      i = r3->size[0];
      r3->size[0] = projection1->size[0];
      emxEnsureCapacity_boolean_T(&b_st, r3, i, &sb_emlrtRTEI);
      r4 = r3->data;
      for (i = 0; i < idx; i++) {
        r4[i] = (projection1_data[i + projection1->size[0] * b_i] <
                 projection2_data[i + distance1->size[0] * b_i]);
      }
    } else {
      c_st.site = &ye_emlrtRSI;
      binary_expand_op(&c_st, r3, projection1, b_i, distance1);
      r4 = r3->data;
    }
    end = r3->size[0] - 1;
    idx = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (r4[c_i]) {
        idx++;
      }
    }
    i = r1->size[0];
    r1->size[0] = idx;
    emxEnsureCapacity_int32_T(&b_st, r1, i, &rb_emlrtRTEI);
    r6 = r1->data;
    idx = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (r4[c_i]) {
        r6[idx] = c_i;
        idx++;
      }
    }
    idx = r1->size[0];
    for (i = 0; i < idx; i++) {
      if (r6[i] > projection1->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(r6[i], 0, projection1->size[0] - 1,
                                      &c_emlrtBCI, &b_st);
      }
    }
    idx = r->size[0];
    if (r->size[0] > 1) {
      i = C1key->size[0];
      C1key->size[0] = r->size[0];
      emxEnsureCapacity_real_T(&b_st, C1key, i, &tb_emlrtRTEI);
      C1key_data = C1key->data;
      for (i = 0; i < idx; i++) {
        C1key_data[i] = projection2_data[r5[i] + distance1->size[0] * b_i];
      }
      c_st.site = &bd_emlrtRSI;
      scores[b_i] += var(&c_st, C1key);
    }
    idx = r1->size[0];
    if (r1->size[0] > 1) {
      i = C1key->size[0];
      C1key->size[0] = r1->size[0];
      emxEnsureCapacity_real_T(&b_st, C1key, i, &ub_emlrtRTEI);
      C1key_data = C1key->data;
      for (i = 0; i < idx; i++) {
        C1key_data[i] = projection1_data[r6[i] + projection1->size[0] * b_i];
      }
      c_st.site = &cd_emlrtRSI;
      scores[b_i] += var(&c_st, C1key);
    }
  }
  emxFree_boolean_T(&b_st, &r3);
  emxFree_boolean_T(&b_st, &r2);
  emxFree_int32_T(&b_st, &r1);
  emxFree_int32_T(&b_st, &r);
  emxFree_real_T(&b_st, &distance1);
  emxFree_real_T(&b_st, &projection1);
  b_st.site = &tc_emlrtRSI;
  c_st.site = &ce_emlrtRSI;
  d_st.site = &de_emlrtRSI;
  b = !muDoubleScalarIsNaN(scores[0]);
  if (b) {
    end = 1;
  } else {
    end = 0;
    c_i = 2;
    exitg1 = false;
    while ((!exitg1) && (c_i < 92)) {
      if (!muDoubleScalarIsNaN(scores[c_i - 1])) {
        end = c_i;
        exitg1 = true;
      } else {
        c_i++;
      }
    }
  }
  if (end == 0) {
    alpha1 = scores[0];
    end = 1;
  } else {
    alpha1 = scores[end - 1];
    i = end + 1;
    for (c_i = i; c_i < 92; c_i++) {
      d = scores[c_i - 1];
      if (alpha1 > d) {
        alpha1 = d;
        end = c_i;
      }
    }
  }
  b_st.site = &uc_emlrtRSI;
  c_st.site = &hc_emlrtRSI;
  d_st.site = &ic_emlrtRSI;
  if (b) {
    idx = 1;
  } else {
    idx = 0;
    c_i = 2;
    exitg1 = false;
    while ((!exitg1) && (c_i < 92)) {
      if (!muDoubleScalarIsNaN(scores[c_i - 1])) {
        idx = c_i;
        exitg1 = true;
      } else {
        c_i++;
      }
    }
  }
  if (idx == 0) {
    beta1 = scores[0];
  } else {
    beta1 = scores[idx - 1];
    i = idx + 1;
    for (c_i = i; c_i < 92; c_i++) {
      d = scores[c_i - 1];
      if (beta1 < d) {
        beta1 = d;
      }
    }
  }
  *score = 1.0 - alpha1 / beta1;
  theta = (real_T)end - 1.0;
  d = (real_T)end - 1.0;
  b_sind(&d);
  alpha1 = (real_T)end - 1.0;
  b_cosd(&alpha1);
  st.site = &nc_emlrtRSI;
  dv[0] = alpha1;
  dv[1] = d;
  b_st.site = &vc_emlrtRSI;
  mtimes(&b_st, X, dv, C1key);
  st.site = &oc_emlrtRSI;
  dv[0] = -d;
  dv[1] = alpha1;
  emxInit_real_T(&st, &C2key, 1, &wb_emlrtRTEI);
  b_st.site = &vc_emlrtRSI;
  mtimes(&b_st, X, dv, C2key);
  st.site = &pc_emlrtRSI;
  findVertex(&st, (real_T)end - 1.0, C1key, C2key, boundingBox2d);
  emxFree_real_T(sp, &C2key);
  emxFree_real_T(sp, &C1key);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return theta;
}

/* End of code generation (pcfitcuboid.c) */
