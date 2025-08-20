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
#include "combineVectorElements.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "pointCloudBase.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "sumMatrixIncludeNaN.h"
#include "warning.h"
#include "cvstCG_ComputeMetric.h"
#include "cvstCG_kdtree.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = {
    154,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    166,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    220,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    228,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    230,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    15,    /* lineNo */
    "min", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" /* pathName
                                                                        */
};

static emlrtRSInfo xb_emlrtRSI =
    {
        46,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI =
    {
        92,        /* lineNo */
        "minimum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    225,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    312,                     /* lineNo */
    "unaryMinOrMaxDispatch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    353,          /* lineNo */
    "minOrMax1D", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" /* pathName
                                                                        */
};

static emlrtRSInfo ec_emlrtRSI =
    {
        44,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI =
    {
        79,        /* lineNo */
        "maximum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo bf_emlrtRSI = {
    172,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo cf_emlrtRSI = {
    175,                 /* lineNo */
    "pointCloud/select", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo df_emlrtRSI = {
    158,        /* lineNo */
    "eml_find", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

static emlrtRSInfo vf_emlrtRSI = {
    245,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    432,                                     /* lineNo */
    "pointCloudBase/extractValidPointsImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    88,                                 /* lineNo */
    "pointCloud/findNeighborsInRadius", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    262,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI = {
    264,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo cg_emlrtRSI = {
    271,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo dg_emlrtRSI = {
    273,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo eg_emlrtRSI = {
    288,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo fg_emlrtRSI = {
    299,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo gg_emlrtRSI = {
    1231,                                            /* lineNo */
    "pointCloud/validateAndParseRadiusSearchOption", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo hg_emlrtRSI = {
    1237,                                            /* lineNo */
    "pointCloud/validateAndParseRadiusSearchOption", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo ig_emlrtRSI = {
    649,                                 /* lineNo */
    "pointCloudBase/validateQueryPoint", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo jg_emlrtRSI = {
    674,                             /* lineNo */
    "pointCloudBase/validateRadius", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo kg_emlrtRSI = {
    552,                                     /* lineNo */
    "pointCloudBase/bruteForceRadiusSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo lg_emlrtRSI = {
    554,                                     /* lineNo */
    "pointCloudBase/bruteForceRadiusSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo mg_emlrtRSI = {
    559,                                     /* lineNo */
    "pointCloudBase/bruteForceRadiusSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo ng_emlrtRSI = {
    867,                     /* lineNo */
    "pointCloud/bruteForce", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo og_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m" /* pathName
                                                                          */
};

static emlrtRSInfo pg_emlrtRSI = {
    929,                             /* lineNo */
    "pointCloud/kdtreeRadiusSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo qg_emlrtRSI = {
    931,                             /* lineNo */
    "pointCloud/kdtreeRadiusSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo rg_emlrtRSI = {
    820,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo sg_emlrtRSI = {
    826,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo tg_emlrtRSI = {
    830,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo ug_emlrtRSI = {
    838,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    213,                                  /* lineNo */
    "kdtreeBuildable/kdtreeRadiusSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\kdtreeBuildable.m" /* pathName */
};

static emlrtRSInfo wg_emlrtRSI = {
    214,                                  /* lineNo */
    "kdtreeBuildable/kdtreeRadiusSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\kdtreeBuildable.m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

static emlrtRTEInfo l_emlrtRTEI = {
    166,                 /* lineNo */
    21,                  /* colNo */
    "pointCloud/select", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    707,                                /* lineNo */
    21,                                 /* colNo */
    "pointCloudBase/validateIntensity", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    15,             /* lineNo */
    19,             /* colNo */
    "validatesize", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatesize.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    14,                    /* lineNo */
    37,                    /* colNo */
    "validatenonnegative", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnegative.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    69,                            /* lineNo */
    13,                            /* colNo */
    "kdtreeBuildable/kdtreeIndex", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\kdtreeBuildable.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    213,                                  /* lineNo */
    45,                                   /* colNo */
    "kdtreeBuildable/kdtreeRadiusSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\kdtreeBuildable.m", /* pName */
    1                               /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    214,                                  /* lineNo */
    43,                                   /* colNo */
    "kdtreeBuildable/kdtreeRadiusSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\kdtreeBuildable.m", /* pName */
    1                               /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    559,                                     /* lineNo */
    36,                                      /* colNo */
    "",                                      /* aName */
    "pointCloudBase/bruteForceRadiusSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    564,                                     /* lineNo */
    35,                                      /* colNo */
    "",                                      /* aName */
    "pointCloudBase/bruteForceRadiusSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    565,                                     /* lineNo */
    33,                                      /* colNo */
    "",                                      /* aName */
    "pointCloudBase/bruteForceRadiusSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    149,          /* lineNo */
    31,           /* colNo */
    "pointCloud", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    39,     /* lineNo */
    5,      /* colNo */
    "find", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    40,     /* lineNo */
    9,      /* colNo */
    "find", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

static emlrtRTEInfo rd_emlrtRTEI = {
    427,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = {
    302,          /* lineNo */
    17,           /* colNo */
    "pointCloud", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo td_emlrtRTEI = {
    234,          /* lineNo */
    45,           /* colNo */
    "pointCloud", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = {
    245,          /* lineNo */
    21,           /* colNo */
    "pointCloud", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = {
    820,          /* lineNo */
    110,          /* colNo */
    "pointCloud", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = {
    552,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    43,                       /* lineNo */
    21,                       /* colNo */
    "ComputeMetricBuildable", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\ComputeMetricBuildable.m" /* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = {
    554,              /* lineNo */
    35,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI = {
    213,               /* lineNo */
    39,                /* colNo */
    "kdtreeBuildable", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = {
    364,    /* lineNo */
    24,     /* colNo */
    "find", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

static emlrtRTEInfo de_emlrtRTEI = {
    214,               /* lineNo */
    37,                /* colNo */
    "kdtreeBuildable", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = {
    554,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = {
    559,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = {
    85,           /* lineNo */
    37,           /* colNo */
    "pointCloud", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo he_emlrtRTEI = {
    214,               /* lineNo */
    13,                /* colNo */
    "kdtreeBuildable", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = {
    41,                       /* lineNo */
    17,                       /* colNo */
    "ComputeMetricBuildable", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "buildable\\ComputeMetricBuildable.m" /* pName */
};

/* Function Definitions */
pointCloud *b_pointCloud_select(const emlrtStack *sp, const pointCloud *this,
                                const emxArray_boolean_T *varargin_1,
                                pointCloud *iobj_0)
{
  static const char_T functionName[6] = {'s', 'e', 'l', 'e', 'c', 't'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_int32_T *ii;
  emxArray_real_T tmp_data;
  emxArray_real_T *c_ii;
  emxArray_real_T *intensity;
  emxArray_real_T *loc;
  emxArray_real_T *nv;
  emxArray_real_T *r;
  emxArray_uint8_T *c;
  pointCloud *ptCloudOut;
  real_T *b_ii_data;
  int32_T tmp_size[3];
  int32_T b_ii;
  int32_T i;
  int32_T idx;
  int32_T nx;
  int32_T *ii_data;
  uint32_T t0_f4_idx_0;
  uint32_T t0_f4_idx_1;
  const boolean_T *varargin_1_data;
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
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &rb_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  n = (this->PointCloudArrayData->size[0] *
           this->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 6, &functionName[0]);
  }
  t0_f4_idx_0 = (uint32_T)this->Location->size[0];
  t0_f4_idx_1 = (uint32_T)this->Location->size[1];
  st.site = &bf_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  n = true;
  if (((int32_T)t0_f4_idx_0 != varargin_1->size[0]) ||
      ((int32_T)t0_f4_idx_1 != varargin_1->size[1])) {
    n = false;
  }
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &w_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectSize",
        "MATLAB:incorrectSize", 3, 4, 5, "Input");
  }
  st.site = &cf_emlrtRSI;
  b_st.site = &mb_emlrtRSI;
  nx = varargin_1->size[0] * varargin_1->size[1];
  c_st.site = &nb_emlrtRSI;
  idx = 0;
  emxInit_int32_T(&c_st, &ii, 1, &xb_emlrtRTEI);
  i = ii->size[0];
  ii->size[0] = nx;
  emxEnsureCapacity_int32_T(&c_st, ii, i, &cc_emlrtRTEI);
  ii_data = ii->data;
  d_st.site = &ob_emlrtRSI;
  if (nx > 2147483646) {
    e_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= nx - 1)) {
    if (varargin_1_data[b_ii]) {
      idx++;
      ii_data[idx - 1] = b_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }
  if (idx > nx) {
    emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (nx == 1) {
    if (idx == 0) {
      ii->size[0] = 0;
    }
  } else {
    int32_T iv[2];
    if (idx < 1) {
      i = 0;
    } else {
      i = idx;
    }
    iv[0] = 1;
    iv[1] = i;
    d_st.site = &pb_emlrtRSI;
    indexShapeCheck(&d_st, ii->size[0], iv);
    b_ii = ii->size[0];
    ii->size[0] = i;
    emxEnsureCapacity_int32_T(&c_st, ii, b_ii, &cd_emlrtRTEI);
    ii_data = ii->data;
  }
  if ((varargin_1->size[0] == 1) && (ii->size[0] != 1) &&
      (varargin_1->size[1] >= 2)) {
    c_st.site = &df_emlrtRSI;
    warning(&c_st);
  }
  emxInit_real_T(sp, &c_ii, 1, &dd_emlrtRTEI);
  i = c_ii->size[0];
  c_ii->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(sp, c_ii, i, &dd_emlrtRTEI);
  b_ii_data = c_ii->data;
  b_ii = ii->size[0];
  for (i = 0; i < b_ii; i++) {
    b_ii_data[i] = ii_data[i];
  }
  emxFree_int32_T(sp, &ii);
  emxInit_real_T(sp, &loc, 3, &kc_emlrtRTEI);
  emxInit_uint8_T(sp, &c, 3, &kc_emlrtRTEI);
  emxInit_real_T(sp, &nv, 3, &kc_emlrtRTEI);
  emxInit_real_T(sp, &intensity, 2, &kc_emlrtRTEI);
  emxInit_real_T(sp, &r, 3, &kc_emlrtRTEI);
  st.site = &tb_emlrtRSI;
  pointCloudBase_subsetImpl(&st, this, c_ii, loc, c, nv, intensity, r);
  b_ii_data = loc->data;
  emxFree_real_T(sp, &c_ii);
  st.site = &ub_emlrtRSI;
  iobj_0->HasKdtreeConstructed = false;
  iobj_0->HasLocationHandleAllocated = false;
  b_st.site = &j_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  ptCloudOut = iobj_0;
  i = iobj_0->Location->size[0] * iobj_0->Location->size[1] *
      iobj_0->Location->size[2];
  iobj_0->Location->size[0] = loc->size[0];
  iobj_0->Location->size[1] = loc->size[1];
  iobj_0->Location->size[2] = 3;
  emxEnsureCapacity_real_T(&b_st, iobj_0->Location, i, &kb_emlrtRTEI);
  b_ii = loc->size[0] * loc->size[1] * 3;
  for (i = 0; i < b_ii; i++) {
    iobj_0->Location->data[i] = b_ii_data[i];
  }
  emxFree_real_T(&b_st, &loc);
  c_st.site = &n_emlrtRSI;
  b_pointCloudBase_set_Color(&c_st, iobj_0, c);
  emxFree_uint8_T(&b_st, &c);
  c_st.site = &o_emlrtRSI;
  pointCloudBase_set_Normal(&c_st, iobj_0, nv);
  emxFree_real_T(&b_st, &nv);
  c_st.site = &p_emlrtRSI;
  pointCloudBase_set_Intensity(&c_st, iobj_0, intensity);
  emxFree_real_T(&b_st, &intensity);
  tmp_size[0] = 0;
  tmp_size[1] = 0;
  tmp_size[2] = 0;
  tmp_data.size = &tmp_size[0];
  tmp_data.allocatedSize = 0;
  tmp_data.numDimensions = 3;
  tmp_data.canFreeData = false;
  c_st.site = &q_emlrtRSI;
  b_pointCloudBase_set_RangeData(&c_st, iobj_0, &tmp_data);
  b_st.site = &k_emlrtRSI;
  iobj_0->PointCloudArrayData->size[0] = 1;
  iobj_0->PointCloudArrayData->size[1] = 1;
  b_st.site = &l_emlrtRSI;
  iobj_0->Kdtree = NULL;
  iobj_0->LocationHandle = NULL;
  iobj_0->matlabCodegenIsDeleted = false;
  st.site = &vb_emlrtRSI;
  b_pointCloudBase_set_RangeData(&st, iobj_0, r);
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return ptCloudOut;
}

void c_pointCloud_findNeighborsInRad(const emlrtStack *sp, pointCloud *this,
                                     const real_T varargin_1[3],
                                     real_T varargin_2,
                                     emxArray_uint32_T *indices)
{
  static const char_T functionName[21] = {'f', 'i', 'n', 'd', 'N', 'e', 'i',
                                          'g', 'h', 'b', 'o', 'r', 's', 'I',
                                          'n', 'R', 'a', 'd', 'i', 'u', 's'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_real_T *allDists;
  emxArray_real_T *dists_;
  emxArray_real_T *r;
  real_T point[3];
  real_T *allDists_data;
  real_T *dists__data;
  int32_T i;
  int32_T k;
  int32_T *ii_data;
  uint32_T *indices_data;
  boolean_T createIndex;
  boolean_T exitg1;
  boolean_T *x_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &yf_emlrtRSI;
  b_st.site = &ag_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  if (this->PointCloudArrayData->size[0] * this->PointCloudArrayData->size[1] !=
      1) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &f_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 21, &functionName[0]);
  }
  b_st.site = &bg_emlrtRSI;
  c_st.site = &gg_emlrtRSI;
  d_st.site = &ig_emlrtRSI;
  e_st.site = &ib_emlrtRSI;
  createIndex = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!muDoubleScalarIsNaN(varargin_1[k])) {
      k++;
    } else {
      createIndex = false;
      exitg1 = true;
    }
  }
  if (!createIndex) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:expectedNonNaN", 3, 4, 5, "point");
  }
  e_st.site = &ib_emlrtRSI;
  createIndex = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if ((!muDoubleScalarIsInf(varargin_1[k])) &&
        (!muDoubleScalarIsNaN(varargin_1[k]))) {
      k++;
    } else {
      createIndex = false;
      exitg1 = true;
    }
  }
  if (!createIndex) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &cb_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:expectedFinite", 3, 4, 5, "point");
  }
  point[0] = varargin_1[0];
  point[1] = varargin_1[1];
  point[2] = varargin_1[2];
  c_st.site = &hg_emlrtRSI;
  d_st.site = &jg_emlrtRSI;
  e_st.site = &ib_emlrtRSI;
  if (muDoubleScalarIsNaN(varargin_2)) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:expectedNonNaN", 3, 4, 6, "radius");
  }
  e_st.site = &ib_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_2)) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &cb_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:expectedFinite", 3, 4, 6, "radius");
  }
  e_st.site = &ib_emlrtRSI;
  if (varargin_2 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &fb_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:expectedNonnegative", 3, 4, 6, "radius");
  }
  b_st.site = &cg_emlrtRSI;
  emxInit_real_T(&st, &dists_, 1, &he_emlrtRTEI);
  if (this->Location->size[0] < 500) {
    real_T y;
    int32_T idx;
    int32_T nx;
    b_st.site = &dg_emlrtRSI;
    c_st.site = &kg_emlrtRSI;
    k = this->Location->size[0];
    d_st.site = &ng_emlrtRSI;
    emxInit_real_T(&d_st, &allDists, 2, &xd_emlrtRTEI);
    i = allDists->size[0] * allDists->size[1];
    allDists->size[0] = 1;
    allDists->size[1] = k;
    emxEnsureCapacity_real_T(&d_st, allDists, i, &xd_emlrtRTEI);
    allDists_data = allDists->data;
    emxInit_real_T(&d_st, &r, 2, &ie_emlrtRTEI);
    i = r->size[0] * r->size[1];
    r->size[0] = 3;
    r->size[1] = this->Location->size[0];
    emxEnsureCapacity_real_T(&d_st, r, i, &yd_emlrtRTEI);
    dists__data = r->data;
    for (i = 0; i < k; i++) {
      allDists_data[i] = 0.0;
      dists__data[3 * i] = this->Location->data[i];
      dists__data[3 * i + 1] =
          this->Location->data[i + this->Location->size[0]];
      dists__data[3 * i + 2] =
          this->Location->data[i + this->Location->size[0] * 2];
    }
    ComputeMetric_ssd_double(&point[0], &dists__data[0], &allDists_data[0], 1U,
                             (uint32_T)this->Location->size[0], 3U);
    emxFree_real_T(&d_st, &r);
    c_st.site = &lg_emlrtRSI;
    d_st.site = &og_emlrtRSI;
    e_st.site = &pd_emlrtRSI;
    y = varargin_2 * varargin_2;
    c_st.site = &lg_emlrtRSI;
    emxInit_boolean_T(&c_st, &x, 2, &ae_emlrtRTEI);
    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = allDists->size[1];
    emxEnsureCapacity_boolean_T(&c_st, x, i, &ae_emlrtRTEI);
    x_data = x->data;
    k = allDists->size[1];
    for (i = 0; i < k; i++) {
      x_data[i] = (allDists_data[i] <= y);
    }
    d_st.site = &mb_emlrtRSI;
    nx = x->size[1];
    e_st.site = &nb_emlrtRSI;
    idx = 0;
    emxInit_int32_T(&e_st, &ii, 2, &xb_emlrtRTEI);
    i = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = x->size[1];
    emxEnsureCapacity_int32_T(&e_st, ii, i, &ce_emlrtRTEI);
    ii_data = ii->data;
    f_st.site = &ob_emlrtRSI;
    if (x->size[1] > 2147483646) {
      g_st.site = &x_emlrtRSI;
      check_forloop_overflow_error(&g_st);
    }
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= nx - 1)) {
      if (x_data[k]) {
        idx++;
        ii_data[idx - 1] = k + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          k++;
        }
      } else {
        k++;
      }
    }
    if (idx > x->size[1]) {
      emlrtErrorWithMessageIdR2018a(&e_st, &j_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (x->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else {
      i = ii->size[0] * ii->size[1];
      if (idx < 1) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }
      emxEnsureCapacity_int32_T(&e_st, ii, i, &cd_emlrtRTEI);
      ii_data = ii->data;
    }
    emxFree_boolean_T(&e_st, &x);
    i = indices->size[0];
    indices->size[0] = ii->size[1];
    emxEnsureCapacity_uint32_T(&b_st, indices, i, &ee_emlrtRTEI);
    indices_data = indices->data;
    k = ii->size[1];
    for (i = 0; i < k; i++) {
      indices_data[i] = (uint32_T)ii_data[i];
    }
    emxFree_int32_T(&b_st, &ii);
    if (indices->size[0] == 0) {
      dists_->size[0] = 0;
    } else {
      c_st.site = &mg_emlrtRSI;
      d_indexShapeCheck(&c_st, allDists->size, indices->size[0]);
      i = dists_->size[0];
      dists_->size[0] = indices->size[0];
      emxEnsureCapacity_real_T(&b_st, dists_, i, &fe_emlrtRTEI);
      dists__data = dists_->data;
      k = indices->size[0];
      for (i = 0; i < k; i++) {
        if ((int32_T)indices_data[i] > allDists->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)indices_data[i], 1,
                                        allDists->size[1], &kb_emlrtBCI, &b_st);
        }
        dists__data[i] = allDists_data[(int32_T)indices_data[i] - 1];
      }
      nx = dists_->size[0] - 1;
      idx = 0;
      for (i = 0; i <= nx; i++) {
        if ((!muDoubleScalarIsInf(dists__data[i])) &&
            (!muDoubleScalarIsNaN(dists__data[i]))) {
          idx++;
        }
      }
      k = 0;
      for (i = 0; i <= nx; i++) {
        if ((!muDoubleScalarIsInf(dists__data[i])) &&
            (!muDoubleScalarIsNaN(dists__data[i]))) {
          if (i > indices->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(i, 0, indices->size[0] - 1,
                                          &lb_emlrtBCI, &b_st);
          }
          indices_data[k] = indices_data[i];
          k++;
        }
      }
      i = indices->size[0];
      indices->size[0] = idx;
      emxEnsureCapacity_uint32_T(&b_st, indices, i, &ge_emlrtRTEI);
      idx = 0;
      for (i = 0; i <= nx; i++) {
        if ((!muDoubleScalarIsInf(dists__data[i])) &&
            (!muDoubleScalarIsNaN(dists__data[i]))) {
          idx++;
        }
      }
      k = 0;
      for (i = 0; i <= nx; i++) {
        if ((!muDoubleScalarIsInf(dists__data[i])) &&
            (!muDoubleScalarIsNaN(dists__data[i]))) {
          if (i > dists_->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(i, 0, dists_->size[0] - 1,
                                          &mb_emlrtBCI, &b_st);
          }
          dists__data[k] = dists__data[i];
          k++;
        }
      }
      i = dists_->size[0];
      dists_->size[0] = idx;
      emxEnsureCapacity_real_T(&b_st, dists_, i, &ge_emlrtRTEI);
    }
    emxFree_real_T(&b_st, &allDists);
  } else {
    void *ptrDists;
    void *ptrIndices;
    real_T y;
    uint32_T valid;
    b_st.site = &eg_emlrtRSI;
    c_st.site = &pg_emlrtRSI;
    if (!this->HasLocationHandleAllocated) {
      void *locationPtr;
      d_st.site = &rg_emlrtRSI;
      emxInit_real_T(&d_st, &allDists, 2, &wd_emlrtRTEI);
      i = allDists->size[0] * allDists->size[1];
      allDists->size[0] = this->Location->size[0];
      allDists->size[1] = 3;
      emxEnsureCapacity_real_T(&d_st, allDists, i, &wd_emlrtRTEI);
      dists__data = allDists->data;
      k = this->Location->size[0] * 3;
      for (i = 0; i < k; i++) {
        dists__data[i] = this->Location->data[i];
      }
      locationPtr = NULL;
      if (this->Location->size[0] != 0) {
        kdtreeGetLocationDataPointer_double(&dists__data[0],
                                            (uint32_T)this->Location->size[0],
                                            3U, &locationPtr);
      }
      emxFree_real_T(&d_st, &allDists);
      this->LocationHandle = locationPtr;
      this->HasLocationHandleAllocated = true;
    }
    if (!this->HasKdtreeConstructed) {
      d_st.site = &sg_emlrtRSI;
      this->Kdtree = NULL;
      kdtreeConstruct_double(&this->Kdtree);
      this->HasKdtreeConstructed = true;
      createIndex = true;
    } else {
      d_st.site = &tg_emlrtRSI;
      createIndex =
          kdtreeNeedsReindex_double(this->Kdtree, this->LocationHandle);
    }
    if (createIndex) {
      d_st.site = &ug_emlrtRSI;
      e_st.site = &ug_emlrtRSI;
      k = this->Location->size[0];
      if (k == 0) {
        emlrtErrorWithMessageIdR2018a(&d_st, &gb_emlrtRTEI,
                                      "vision:ocvShared:emptyInput",
                                      "vision:ocvShared:emptyInput", 0);
      }
      kdtreeIndex_double(this->Kdtree, this->LocationHandle, (uint32_T)k, 3U,
                         4.0, 1.0, 0.0);
    }
    c_st.site = &qg_emlrtRSI;
    ptrIndices = NULL;
    ptrDists = NULL;
    kdtreeRadiusSearch_double(this->Kdtree, &point[0], 1U, 3U, varargin_2, 0.0,
                              0.0, &ptrIndices, &ptrDists, &valid, 1000, 500U);
    d_st.site = &vg_emlrtRSI;
    e_st.site = &xg_emlrtRSI;
    f_st.site = &ld_emlrtRSI;
    y = sumColumnB(valid);
    if (y != (int32_T)muDoubleScalarFloor(y)) {
      emlrtIntegerCheckR2012b(y, &emlrtDCI, &c_st);
    }
    i = indices->size[0];
    indices->size[0] = (int32_T)y;
    emxEnsureCapacity_uint32_T(&c_st, indices, i, &be_emlrtRTEI);
    indices_data = indices->data;
    d_st.site = &wg_emlrtRSI;
    e_st.site = &xg_emlrtRSI;
    f_st.site = &ld_emlrtRSI;
    y = sumColumnB(valid);
    if (y != (int32_T)muDoubleScalarFloor(y)) {
      emlrtIntegerCheckR2012b(y, &b_emlrtDCI, &c_st);
    }
    i = dists_->size[0];
    dists_->size[0] = (int32_T)y;
    emxEnsureCapacity_real_T(&c_st, dists_, i, &de_emlrtRTEI);
    dists__data = dists_->data;
    kdtreeRadiusSearchSetOutputs_double(ptrIndices, ptrDists, &indices_data[0],
                                        &dists__data[0]);
  }
  b_st.site = &fg_emlrtRSI;
  b_sqrt(&b_st, dists_);
  emxFree_real_T(&st, &dists_);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

pointCloud *pointCloud_pointCloud(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *varargin_1,
                                  const emxArray_uint8_T *varargin_3,
                                  const emxArray_real_T *varargin_5,
                                  const emxArray_real_T *varargin_7)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T tmp_data;
  pointCloud *b_this;
  const real_T *varargin_1_data;
  const real_T *varargin_5_data;
  const real_T *varargin_7_data;
  int32_T tmp_size[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  varargin_7_data = varargin_7->data;
  varargin_5_data = varargin_5->data;
  varargin_1_data = varargin_1->data;
  b_this = this;
  b_this->HasKdtreeConstructed = false;
  b_this->HasLocationHandleAllocated = false;
  st.site = &j_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  i = b_this->Location->size[0] * b_this->Location->size[1];
  b_this->Location->size[0] = varargin_1->size[0];
  b_this->Location->size[1] = 3;
  emxEnsureCapacity_real_T(&st, b_this->Location, i, &kb_emlrtRTEI);
  loop_ub = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this->Location->data[i] = varargin_1_data[i];
  }
  b_st.site = &n_emlrtRSI;
  pointCloudBase_set_Color(&b_st, b_this, varargin_3);
  b_st.site = &o_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  loop_ub = b_this->Location->size[0];
  if ((varargin_5->size[0] != 0) && (varargin_5->size[1] != 0)) {
    uint32_T b_varargin_1[2];
    uint32_T varargin_2[2];
    boolean_T exitg1;
    boolean_T p;
    b_varargin_1[0] = (uint32_T)varargin_5->size[0];
    varargin_2[0] = (uint32_T)loop_ub;
    b_varargin_1[1] = (uint32_T)varargin_5->size[1];
    varargin_2[1] = 3U;
    p = true;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 2)) {
      if ((int32_T)b_varargin_1[loop_ub] != (int32_T)varargin_2[loop_ub]) {
        p = false;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZNormal",
                                    "vision:pointcloud:unmatchedXYZNormal", 0);
    }
  }
  i = b_this->Normal->size[0] * b_this->Normal->size[1];
  b_this->Normal->size[0] = varargin_5->size[0];
  b_this->Normal->size[1] = varargin_5->size[1];
  emxEnsureCapacity_real_T(&b_st, b_this->Normal, i, &lc_emlrtRTEI);
  loop_ub = varargin_5->size[0] * varargin_5->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_this->Normal->data[i] = varargin_5_data[i];
  }
  b_st.site = &p_emlrtRSI;
  c_st.site = &hc_emlrtRSI;
  loop_ub = b_this->Location->size[0];
  if ((varargin_7->size[0] != 0) && (varargin_7->size[1] != 0) &&
      ((varargin_7->size[1] != 1) || (varargin_7->size[0] != loop_ub))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &n_emlrtRTEI,
                                  "vision:pointcloud:unmatchedXYZIntensity",
                                  "vision:pointcloud:unmatchedXYZIntensity", 0);
  }
  i = b_this->Intensity->size[0] * b_this->Intensity->size[1];
  b_this->Intensity->size[0] = varargin_7->size[0];
  b_this->Intensity->size[1] = varargin_7->size[1];
  emxEnsureCapacity_real_T(&b_st, b_this->Intensity, i, &lb_emlrtRTEI);
  loop_ub = varargin_7->size[0] * varargin_7->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_this->Intensity->data[i] = varargin_7_data[i];
  }
  tmp_size[0] = 0;
  tmp_size[1] = 0;
  tmp_data.size = &tmp_size[0];
  tmp_data.allocatedSize = 0;
  tmp_data.numDimensions = 2;
  tmp_data.canFreeData = false;
  b_st.site = &q_emlrtRSI;
  pointCloudBase_set_RangeData(&b_st, b_this, &tmp_data);
  st.site = &k_emlrtRSI;
  b_this->PointCloudArrayData->size[0] = 1;
  b_this->PointCloudArrayData->size[1] = 1;
  st.site = &l_emlrtRSI;
  b_this->Kdtree = NULL;
  b_this->LocationHandle = NULL;
  b_this->matlabCodegenIsDeleted = false;
  return b_this;
}

void pointCloud_removeInvalidPoints(const emlrtStack *sp,
                                    const pointCloud *this, pointCloud *iobj_0,
                                    pointCloud **ptCloudOut,
                                    emxArray_real_T *indicesOut)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T b_tf;
  emxArray_boolean_T *indices;
  emxArray_boolean_T *tf;
  emxArray_int32_T *nz;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T *b_intensity;
  emxArray_real_T *intensity;
  emxArray_real_T *loc;
  emxArray_real_T *normal;
  emxArray_real_T *nv;
  emxArray_real_T *rangeData;
  emxArray_real_T *x;
  emxArray_uint8_T *c;
  emxArray_uint8_T *color;
  real_T *indicesOut_data;
  real_T *intensity_data;
  real_T *loc_data;
  real_T *normal_data;
  real_T *rangeData_data;
  int32_T b_emptyDimValue[2];
  int32_T emptyDimValue;
  int32_T i;
  int32_T loop_ub;
  int32_T maxdimlen;
  int32_T nx;
  int32_T *nz_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &dd_emlrtRSI;
  b_st.site = &gd_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  n = (this->PointCloudArrayData->size[0] *
           this->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &f_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 19, &cv[0]);
  }
  b_st.site = &hd_emlrtRSI;
  emxInit_real_T(&b_st, &x, 3, &qd_emlrtRTEI);
  i = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = this->Location->size[0];
  x->size[1] = this->Location->size[1];
  x->size[2] = 3;
  emxEnsureCapacity_real_T(&b_st, x, i, &qd_emlrtRTEI);
  indicesOut_data = x->data;
  loop_ub = this->Location->size[0] * this->Location->size[1] * 3;
  for (i = 0; i < loop_ub; i++) {
    indicesOut_data[i] = this->Location->data[i];
  }
  emxInit_boolean_T(&b_st, &tf, 3, &rd_emlrtRTEI);
  i = tf->size[0] * tf->size[1] * tf->size[2];
  tf->size[0] = x->size[0];
  tf->size[1] = x->size[1];
  tf->size[2] = 3;
  emxEnsureCapacity_boolean_T(&b_st, tf, i, &rd_emlrtRTEI);
  tf_data = tf->data;
  maxdimlen = x->size[0] * x->size[1] * 3;
  for (i = 0; i < maxdimlen; i++) {
    tf_data[i] = ((!muDoubleScalarIsInf(indicesOut_data[i])) &&
                  (!muDoubleScalarIsNaN(indicesOut_data[i])));
  }
  c_st.site = &wf_emlrtRSI;
  d_st.site = &ff_emlrtRSI;
  emptyDimValue = (int32_T)((uint32_T)maxdimlen / 3U);
  if (emptyDimValue > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ab_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  loop_ub = tf->size[0];
  if (tf->size[1] > tf->size[0]) {
    loop_ub = tf->size[1];
  }
  if (loop_ub < 3) {
    loop_ub = 3;
  }
  if (emptyDimValue > muIntScalarMax_sint32(maxdimlen, loop_ub)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &y_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (emptyDimValue * 3 != maxdimlen) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  c_st.site = &wf_emlrtRSI;
  d_st.site = &kd_emlrtRSI;
  b_tf = *tf;
  b_emptyDimValue[0] = emptyDimValue;
  b_emptyDimValue[1] = 3;
  b_tf.size = &b_emptyDimValue[0];
  b_tf.numDimensions = 2;
  emxInit_int32_T(&d_st, &nz, 1, &vd_emlrtRTEI);
  e_st.site = &ld_emlrtRSI;
  combineVectorElements(&e_st, &b_tf, nz);
  nz_data = nz->data;
  emxFree_boolean_T(&d_st, &tf);
  emxInit_boolean_T(&b_st, &indices, 1, &td_emlrtRTEI);
  i = indices->size[0];
  indices->size[0] = nz->size[0];
  emxEnsureCapacity_boolean_T(&b_st, indices, i, &sd_emlrtRTEI);
  tf_data = indices->data;
  loop_ub = nz->size[0];
  for (i = 0; i < loop_ub; i++) {
    tf_data[i] = (nz_data[i] == 3);
  }
  b_st.site = &id_emlrtRSI;
  c_st.site = &gc_emlrtRSI;
  i = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = this->Location->size[0];
  x->size[1] = this->Location->size[1];
  x->size[2] = 3;
  emxEnsureCapacity_real_T(&c_st, x, i, &ec_emlrtRTEI);
  indicesOut_data = x->data;
  loop_ub = this->Location->size[0] * this->Location->size[1] * 3;
  for (i = 0; i < loop_ub; i++) {
    indicesOut_data[i] = this->Location->data[i];
  }
  emxInit_uint8_T(&c_st, &color, 3, &fc_emlrtRTEI);
  i = color->size[0] * color->size[1] * color->size[2];
  color->size[0] = this->Color->size[0];
  color->size[1] = this->Color->size[1];
  color->size[2] = this->Color->size[2];
  emxEnsureCapacity_uint8_T(&c_st, color, i, &fc_emlrtRTEI);
  color_data = color->data;
  loop_ub = this->Color->size[0] * this->Color->size[1] * this->Color->size[2];
  for (i = 0; i < loop_ub; i++) {
    color_data[i] = this->Color->data[i];
  }
  emxInit_real_T(&c_st, &normal, 3, &gc_emlrtRTEI);
  i = normal->size[0] * normal->size[1] * normal->size[2];
  normal->size[0] = this->Normal->size[0];
  normal->size[1] = this->Normal->size[1];
  normal->size[2] = this->Normal->size[2];
  emxEnsureCapacity_real_T(&c_st, normal, i, &gc_emlrtRTEI);
  normal_data = normal->data;
  loop_ub =
      this->Normal->size[0] * this->Normal->size[1] * this->Normal->size[2];
  for (i = 0; i < loop_ub; i++) {
    normal_data[i] = this->Normal->data[i];
  }
  emxInit_real_T(&c_st, &intensity, 2, &hc_emlrtRTEI);
  i = intensity->size[0] * intensity->size[1];
  intensity->size[0] = this->Intensity->size[0];
  intensity->size[1] = this->Intensity->size[1];
  emxEnsureCapacity_real_T(&c_st, intensity, i, &hc_emlrtRTEI);
  intensity_data = intensity->data;
  loop_ub = this->Intensity->size[0] * this->Intensity->size[1];
  for (i = 0; i < loop_ub; i++) {
    intensity_data[i] = this->Intensity->data[i];
  }
  emxInit_real_T(&c_st, &rangeData, 3, &ic_emlrtRTEI);
  i = rangeData->size[0] * rangeData->size[1] * rangeData->size[2];
  rangeData->size[0] = this->RangeData->size[0];
  rangeData->size[1] = this->RangeData->size[1];
  rangeData->size[2] = this->RangeData->size[2];
  emxEnsureCapacity_real_T(&c_st, rangeData, i, &ic_emlrtRTEI);
  rangeData_data = rangeData->data;
  loop_ub = this->RangeData->size[0] * this->RangeData->size[1] *
            this->RangeData->size[2];
  for (i = 0; i < loop_ub; i++) {
    rangeData_data[i] = this->RangeData->data[i];
  }
  emxInit_real_T(&c_st, &loc, 2, &td_emlrtRTEI);
  if ((x->size[0] != 0) && (x->size[1] != 0)) {
    d_st.site = &ef_emlrtRSI;
    nx = x->size[0] * x->size[1] * 3;
    e_st.site = &ff_emlrtRSI;
    emptyDimValue = (int32_T)((uint32_T)nx / 3U);
    if (emptyDimValue > nx) {
      emlrtErrorWithMessageIdR2018a(&e_st, &ab_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    loop_ub = x->size[0];
    if (x->size[1] > x->size[0]) {
      loop_ub = x->size[1];
    }
    if (loop_ub < 3) {
      loop_ub = 3;
    }
    if (emptyDimValue > muIntScalarMax_sint32(nx, loop_ub)) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (emptyDimValue * 3 != nx) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    nx = indices->size[0] - 1;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        maxdimlen++;
      }
    }
    emxInit_int32_T(&c_st, &r, 1, &jc_emlrtRTEI);
    i = r->size[0];
    r->size[0] = maxdimlen;
    emxEnsureCapacity_int32_T(&c_st, r, i, &td_emlrtRTEI);
    nz_data = r->data;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        nz_data[maxdimlen] = loop_ub;
        maxdimlen++;
      }
    }
    i = loc->size[0] * loc->size[1];
    loc->size[0] = r->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(&c_st, loc, i, &jc_emlrtRTEI);
    loc_data = loc->data;
    loop_ub = r->size[0];
    for (i = 0; i < 3; i++) {
      for (maxdimlen = 0; maxdimlen < loop_ub; maxdimlen++) {
        if (nz_data[maxdimlen] > emptyDimValue - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[maxdimlen], 0,
                                        emptyDimValue - 1, &f_emlrtBCI, &c_st);
        }
        loc_data[maxdimlen + loc->size[0] * i] =
            indicesOut_data[nz_data[maxdimlen] + emptyDimValue * i];
      }
    }
    emxFree_int32_T(&c_st, &r);
  } else {
    loc->size[0] = 0;
    loc->size[1] = 3;
  }
  emxFree_real_T(&c_st, &x);
  emxInit_uint8_T(&c_st, &c, 2, &td_emlrtRTEI);
  if ((color->size[0] != 0) && (color->size[1] != 0) && (color->size[2] != 0)) {
    d_st.site = &ef_emlrtRSI;
    nx = color->size[0] * color->size[1] * color->size[2];
    e_st.site = &ff_emlrtRSI;
    emptyDimValue = (int32_T)((uint32_T)nx / 3U);
    if (emptyDimValue > nx) {
      emlrtErrorWithMessageIdR2018a(&e_st, &ab_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    loop_ub = color->size[0];
    if (color->size[1] > color->size[0]) {
      loop_ub = color->size[1];
    }
    if (color->size[2] > loop_ub) {
      loop_ub = color->size[2];
    }
    maxdimlen = muIntScalarMax_sint32(nx, loop_ub);
    if (emptyDimValue > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (maxdimlen < 3) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (emptyDimValue * 3 != nx) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    nx = indices->size[0] - 1;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        maxdimlen++;
      }
    }
    emxInit_int32_T(&c_st, &r2, 1, &jc_emlrtRTEI);
    i = r2->size[0];
    r2->size[0] = maxdimlen;
    emxEnsureCapacity_int32_T(&c_st, r2, i, &td_emlrtRTEI);
    nz_data = r2->data;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        nz_data[maxdimlen] = loop_ub;
        maxdimlen++;
      }
    }
    i = c->size[0] * c->size[1];
    c->size[0] = r2->size[0];
    c->size[1] = 3;
    emxEnsureCapacity_uint8_T(&c_st, c, i, &jc_emlrtRTEI);
    c_data = c->data;
    loop_ub = r2->size[0];
    for (i = 0; i < 3; i++) {
      for (maxdimlen = 0; maxdimlen < loop_ub; maxdimlen++) {
        if (nz_data[maxdimlen] > emptyDimValue - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[maxdimlen], 0,
                                        emptyDimValue - 1, &f_emlrtBCI, &c_st);
        }
        c_data[maxdimlen + c->size[0] * i] =
            color_data[nz_data[maxdimlen] + emptyDimValue * i];
      }
    }
    emxFree_int32_T(&c_st, &r2);
  } else {
    c->size[0] = 0;
    c->size[1] = 0;
  }
  emxFree_uint8_T(&c_st, &color);
  emxInit_real_T(&c_st, &nv, 2, &td_emlrtRTEI);
  if ((normal->size[0] != 0) && (normal->size[1] != 0) &&
      (normal->size[2] != 0)) {
    d_st.site = &ef_emlrtRSI;
    nx = normal->size[0] * normal->size[1] * normal->size[2];
    e_st.site = &ff_emlrtRSI;
    emptyDimValue = (int32_T)((uint32_T)nx / 3U);
    if (emptyDimValue > nx) {
      emlrtErrorWithMessageIdR2018a(&e_st, &ab_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    loop_ub = normal->size[0];
    if (normal->size[1] > normal->size[0]) {
      loop_ub = normal->size[1];
    }
    if (normal->size[2] > loop_ub) {
      loop_ub = normal->size[2];
    }
    maxdimlen = muIntScalarMax_sint32(nx, loop_ub);
    if (emptyDimValue > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (maxdimlen < 3) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (emptyDimValue * 3 != nx) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    nx = indices->size[0] - 1;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        maxdimlen++;
      }
    }
    emxInit_int32_T(&c_st, &r3, 1, &jc_emlrtRTEI);
    i = r3->size[0];
    r3->size[0] = maxdimlen;
    emxEnsureCapacity_int32_T(&c_st, r3, i, &td_emlrtRTEI);
    nz_data = r3->data;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        nz_data[maxdimlen] = loop_ub;
        maxdimlen++;
      }
    }
    i = nv->size[0] * nv->size[1];
    nv->size[0] = r3->size[0];
    nv->size[1] = 3;
    emxEnsureCapacity_real_T(&c_st, nv, i, &jc_emlrtRTEI);
    indicesOut_data = nv->data;
    loop_ub = r3->size[0];
    for (i = 0; i < 3; i++) {
      for (maxdimlen = 0; maxdimlen < loop_ub; maxdimlen++) {
        if (nz_data[maxdimlen] > emptyDimValue - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[maxdimlen], 0,
                                        emptyDimValue - 1, &f_emlrtBCI, &c_st);
        }
        indicesOut_data[maxdimlen + nv->size[0] * i] =
            normal_data[nz_data[maxdimlen] + emptyDimValue * i];
      }
    }
    emxFree_int32_T(&c_st, &r3);
  } else {
    nv->size[0] = 0;
    nv->size[1] = 0;
  }
  emxFree_real_T(&c_st, &normal);
  emxInit_real_T(&c_st, &b_intensity, 2, &td_emlrtRTEI);
  if ((intensity->size[0] != 0) && (intensity->size[1] != 0)) {
    d_st.site = &ef_emlrtRSI;
    c_indexShapeCheck(&d_st, intensity->size, indices->size[0]);
    nx = indices->size[0] - 1;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        maxdimlen++;
      }
    }
    emxInit_int32_T(&c_st, &r1, 1, &jc_emlrtRTEI);
    i = r1->size[0];
    r1->size[0] = maxdimlen;
    emxEnsureCapacity_int32_T(&c_st, r1, i, &td_emlrtRTEI);
    nz_data = r1->data;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        nz_data[maxdimlen] = loop_ub;
        maxdimlen++;
      }
    }
    maxdimlen = intensity->size[0] * intensity->size[1];
    loop_ub = r1->size[0];
    for (i = 0; i < loop_ub; i++) {
      if (nz_data[i] > maxdimlen - 1) {
        emlrtDynamicBoundsCheckR2012b(nz_data[i], 0, maxdimlen - 1, &f_emlrtBCI,
                                      &c_st);
      }
    }
    if (r1->size[0] == 1) {
      i = b_intensity->size[0] * b_intensity->size[1];
      b_intensity->size[0] = 1;
      b_intensity->size[1] = 1;
      emxEnsureCapacity_real_T(&c_st, b_intensity, i, &jc_emlrtRTEI);
      indicesOut_data = b_intensity->data;
      indicesOut_data[0] = intensity_data[nz_data[0]];
    } else {
      i = b_intensity->size[0] * b_intensity->size[1];
      b_intensity->size[0] = r1->size[0];
      b_intensity->size[1] = 1;
      emxEnsureCapacity_real_T(&c_st, b_intensity, i, &jc_emlrtRTEI);
      indicesOut_data = b_intensity->data;
      loop_ub = r1->size[0];
      for (i = 0; i < loop_ub; i++) {
        indicesOut_data[i] = intensity_data[nz_data[i]];
      }
    }
    emxFree_int32_T(&c_st, &r1);
  } else {
    b_intensity->size[0] = 0;
    b_intensity->size[1] = 0;
  }
  if ((rangeData->size[0] != 0) && (rangeData->size[1] != 0) &&
      (rangeData->size[2] != 0)) {
    d_st.site = &ef_emlrtRSI;
    nx = rangeData->size[0] * rangeData->size[1] * rangeData->size[2];
    e_st.site = &ff_emlrtRSI;
    emptyDimValue = (int32_T)((uint32_T)nx / 3U);
    if (emptyDimValue > nx) {
      emlrtErrorWithMessageIdR2018a(&e_st, &ab_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    loop_ub = rangeData->size[0];
    if (rangeData->size[1] > rangeData->size[0]) {
      loop_ub = rangeData->size[1];
    }
    if (rangeData->size[2] > loop_ub) {
      loop_ub = rangeData->size[2];
    }
    maxdimlen = muIntScalarMax_sint32(nx, loop_ub);
    if (emptyDimValue > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (maxdimlen < 3) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &y_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (emptyDimValue * 3 != nx) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &x_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    nx = indices->size[0] - 1;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        maxdimlen++;
      }
    }
    emxInit_int32_T(&c_st, &r4, 1, &jc_emlrtRTEI);
    i = r4->size[0];
    r4->size[0] = maxdimlen;
    emxEnsureCapacity_int32_T(&c_st, r4, i, &td_emlrtRTEI);
    nz_data = r4->data;
    maxdimlen = 0;
    for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
      if (tf_data[loop_ub]) {
        nz_data[maxdimlen] = loop_ub;
        maxdimlen++;
      }
    }
    i = intensity->size[0] * intensity->size[1];
    intensity->size[0] = r4->size[0];
    intensity->size[1] = 3;
    emxEnsureCapacity_real_T(&c_st, intensity, i, &jc_emlrtRTEI);
    intensity_data = intensity->data;
    loop_ub = r4->size[0];
    for (i = 0; i < 3; i++) {
      for (maxdimlen = 0; maxdimlen < loop_ub; maxdimlen++) {
        if (nz_data[maxdimlen] > emptyDimValue - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[maxdimlen], 0,
                                        emptyDimValue - 1, &f_emlrtBCI, &c_st);
        }
        intensity_data[maxdimlen + intensity->size[0] * i] =
            rangeData_data[nz_data[maxdimlen] + emptyDimValue * i];
      }
    }
    emxFree_int32_T(&c_st, &r4);
  } else {
    intensity->size[0] = 0;
    intensity->size[1] = 0;
  }
  emxFree_real_T(&c_st, &rangeData);
  st.site = &ed_emlrtRSI;
  *ptCloudOut = pointCloud_pointCloud(&st, iobj_0, loc, c, nv, b_intensity);
  emxFree_real_T(sp, &b_intensity);
  emxFree_real_T(sp, &nv);
  emxFree_uint8_T(sp, &c);
  emxFree_real_T(sp, &loc);
  st.site = &fd_emlrtRSI;
  pointCloudBase_set_RangeData(&st, *ptCloudOut, intensity);
  emxFree_real_T(sp, &intensity);
  st.site = &vf_emlrtRSI;
  b_st.site = &mb_emlrtRSI;
  eml_find(&b_st, indices, nz);
  nz_data = nz->data;
  emxFree_boolean_T(&st, &indices);
  i = indicesOut->size[0];
  indicesOut->size[0] = nz->size[0];
  emxEnsureCapacity_real_T(&st, indicesOut, i, &ud_emlrtRTEI);
  indicesOut_data = indicesOut->data;
  loop_ub = nz->size[0];
  for (i = 0; i < loop_ub; i++) {
    indicesOut_data[i] = nz_data[i];
  }
  emxFree_int32_T(&st, &nz);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

pointCloud *pointCloud_select(const emlrtStack *sp, const pointCloud *this,
                              const emxArray_uint32_T *varargin_1,
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
  emlrtStack st;
  emxArray_real_T *b_intensity;
  emxArray_real_T *intensity;
  emxArray_real_T *loc;
  emxArray_real_T *location;
  emxArray_real_T *normal;
  emxArray_real_T *nv;
  emxArray_real_T *rangeData;
  emxArray_uint8_T *c;
  emxArray_uint8_T *color;
  pointCloud *ptCloudOut;
  real_T *intensity_data;
  real_T *loc_data;
  real_T *location_data;
  real_T *normal_data;
  real_T *rangeData_data;
  int32_T i;
  int32_T i1;
  int32_T istop;
  int32_T k;
  const uint32_T *varargin_1_data;
  uint8_T *c_data;
  uint8_T *color_data;
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
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &rb_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  n = (this->PointCloudArrayData->size[0] *
           this->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 6, &functionName[0]);
  }
  if (varargin_1->size[0] != 0) {
    uint32_T minval;
    uint32_T u;
    boolean_T guard1;
    st.site = &sb_emlrtRSI;
    b_st.site = &wb_emlrtRSI;
    c_st.site = &xb_emlrtRSI;
    d_st.site = &yb_emlrtRSI;
    e_st.site = &ac_emlrtRSI;
    istop = varargin_1->size[0];
    f_st.site = &bc_emlrtRSI;
    minval = varargin_1_data[0];
    g_st.site = &cc_emlrtRSI;
    if (varargin_1->size[0] > 2147483646) {
      h_st.site = &x_emlrtRSI;
      check_forloop_overflow_error(&h_st);
    }
    for (k = 2; k <= istop; k++) {
      u = varargin_1_data[k - 1];
      if (minval > u) {
        minval = u;
      }
    }
    guard1 = false;
    if (minval < 1U) {
      guard1 = true;
    } else {
      st.site = &sb_emlrtRSI;
      b_st.site = &dc_emlrtRSI;
      c_st.site = &ec_emlrtRSI;
      d_st.site = &fc_emlrtRSI;
      e_st.site = &ac_emlrtRSI;
      istop = varargin_1->size[0];
      f_st.site = &bc_emlrtRSI;
      minval = varargin_1_data[0];
      g_st.site = &cc_emlrtRSI;
      for (k = 2; k <= istop; k++) {
        u = varargin_1_data[k - 1];
        if (minval < u) {
          minval = u;
        }
      }
      st.site = &sb_emlrtRSI;
      istop = this->Location->size[0];
      if (minval > (uint32_T)istop) {
        guard1 = true;
      }
    }
    if (guard1) {
      emlrtErrorWithMessageIdR2018a(
          sp, &l_emlrtRTEI, "vision:pointcloud:indicesOutofRangeForSelect",
          "vision:pointcloud:indicesOutofRangeForSelect", 0);
    }
  }
  st.site = &tb_emlrtRSI;
  b_st.site = &gc_emlrtRSI;
  emxInit_real_T(&b_st, &location, 2, &ec_emlrtRTEI);
  i = location->size[0] * location->size[1];
  location->size[0] = this->Location->size[0];
  location->size[1] = 3;
  emxEnsureCapacity_real_T(&b_st, location, i, &ec_emlrtRTEI);
  location_data = location->data;
  istop = this->Location->size[0] * 3;
  for (i = 0; i < istop; i++) {
    location_data[i] = this->Location->data[i];
  }
  emxInit_uint8_T(&b_st, &color, 2, &fc_emlrtRTEI);
  i = color->size[0] * color->size[1];
  color->size[0] = this->Color->size[0];
  color->size[1] = this->Color->size[1];
  emxEnsureCapacity_uint8_T(&b_st, color, i, &fc_emlrtRTEI);
  color_data = color->data;
  istop = this->Color->size[0] * this->Color->size[1];
  for (i = 0; i < istop; i++) {
    color_data[i] = this->Color->data[i];
  }
  emxInit_real_T(&b_st, &normal, 2, &gc_emlrtRTEI);
  i = normal->size[0] * normal->size[1];
  normal->size[0] = this->Normal->size[0];
  normal->size[1] = this->Normal->size[1];
  emxEnsureCapacity_real_T(&b_st, normal, i, &gc_emlrtRTEI);
  normal_data = normal->data;
  istop = this->Normal->size[0] * this->Normal->size[1];
  for (i = 0; i < istop; i++) {
    normal_data[i] = this->Normal->data[i];
  }
  emxInit_real_T(&b_st, &intensity, 2, &hc_emlrtRTEI);
  i = intensity->size[0] * intensity->size[1];
  intensity->size[0] = this->Intensity->size[0];
  intensity->size[1] = this->Intensity->size[1];
  emxEnsureCapacity_real_T(&b_st, intensity, i, &hc_emlrtRTEI);
  intensity_data = intensity->data;
  istop = this->Intensity->size[0] * this->Intensity->size[1];
  for (i = 0; i < istop; i++) {
    intensity_data[i] = this->Intensity->data[i];
  }
  emxInit_real_T(&b_st, &rangeData, 2, &ic_emlrtRTEI);
  i = rangeData->size[0] * rangeData->size[1];
  rangeData->size[0] = this->RangeData->size[0];
  rangeData->size[1] = this->RangeData->size[1];
  emxEnsureCapacity_real_T(&b_st, rangeData, i, &ic_emlrtRTEI);
  rangeData_data = rangeData->data;
  istop = this->RangeData->size[0] * this->RangeData->size[1];
  for (i = 0; i < istop; i++) {
    rangeData_data[i] = this->RangeData->data[i];
  }
  emxInit_real_T(&b_st, &loc, 2, &kc_emlrtRTEI);
  if (location->size[0] != 0) {
    i = loc->size[0] * loc->size[1];
    loc->size[0] = varargin_1->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(&b_st, loc, i, &jc_emlrtRTEI);
    loc_data = loc->data;
    istop = varargin_1->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < istop; i1++) {
        if (((int32_T)varargin_1_data[i1] < 1) ||
            ((int32_T)varargin_1_data[i1] > location->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)varargin_1_data[i1], 1,
                                        location->size[0], &f_emlrtBCI, &b_st);
        }
        loc_data[i1 + loc->size[0] * i] = location_data
            [((int32_T)varargin_1_data[i1] + location->size[0] * i) - 1];
      }
    }
  } else {
    loc->size[0] = 0;
    loc->size[1] = 3;
  }
  emxFree_real_T(&b_st, &location);
  emxInit_uint8_T(&b_st, &c, 2, &kc_emlrtRTEI);
  if ((color->size[0] != 0) && (color->size[1] != 0)) {
    i = c->size[0] * c->size[1];
    c->size[0] = varargin_1->size[0];
    c->size[1] = color->size[1];
    emxEnsureCapacity_uint8_T(&b_st, c, i, &jc_emlrtRTEI);
    c_data = c->data;
    istop = color->size[1];
    for (i = 0; i < istop; i++) {
      k = varargin_1->size[0];
      for (i1 = 0; i1 < k; i1++) {
        if (((int32_T)varargin_1_data[i1] < 1) ||
            ((int32_T)varargin_1_data[i1] > color->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)varargin_1_data[i1], 1,
                                        color->size[0], &f_emlrtBCI, &b_st);
        }
        c_data[i1 + c->size[0] * i] =
            color_data[((int32_T)varargin_1_data[i1] + color->size[0] * i) - 1];
      }
    }
  } else {
    c->size[0] = 0;
    c->size[1] = 0;
  }
  emxFree_uint8_T(&b_st, &color);
  emxInit_real_T(&b_st, &nv, 2, &kc_emlrtRTEI);
  if ((normal->size[0] != 0) && (normal->size[1] != 0)) {
    i = nv->size[0] * nv->size[1];
    nv->size[0] = varargin_1->size[0];
    nv->size[1] = normal->size[1];
    emxEnsureCapacity_real_T(&b_st, nv, i, &jc_emlrtRTEI);
    location_data = nv->data;
    istop = normal->size[1];
    for (i = 0; i < istop; i++) {
      k = varargin_1->size[0];
      for (i1 = 0; i1 < k; i1++) {
        if (((int32_T)varargin_1_data[i1] < 1) ||
            ((int32_T)varargin_1_data[i1] > normal->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)varargin_1_data[i1], 1,
                                        normal->size[0], &f_emlrtBCI, &b_st);
        }
        location_data[i1 + nv->size[0] * i] =
            normal_data[((int32_T)varargin_1_data[i1] + normal->size[0] * i) -
                        1];
      }
    }
  } else {
    nv->size[0] = 0;
    nv->size[1] = 0;
  }
  emxInit_real_T(&b_st, &b_intensity, 2, &kc_emlrtRTEI);
  if ((intensity->size[0] != 0) && (intensity->size[1] != 0)) {
    i = b_intensity->size[0] * b_intensity->size[1];
    b_intensity->size[0] = varargin_1->size[0];
    b_intensity->size[1] = intensity->size[1];
    emxEnsureCapacity_real_T(&b_st, b_intensity, i, &jc_emlrtRTEI);
    location_data = b_intensity->data;
    istop = intensity->size[1];
    for (i = 0; i < istop; i++) {
      k = varargin_1->size[0];
      for (i1 = 0; i1 < k; i1++) {
        if (((int32_T)varargin_1_data[i1] < 1) ||
            ((int32_T)varargin_1_data[i1] > intensity->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)varargin_1_data[i1], 1,
                                        intensity->size[0], &f_emlrtBCI, &b_st);
        }
        location_data[i1 + b_intensity->size[0] * i] = intensity_data
            [((int32_T)varargin_1_data[i1] + intensity->size[0] * i) - 1];
      }
    }
  } else {
    b_intensity->size[0] = 0;
    b_intensity->size[1] = 0;
  }
  emxFree_real_T(&b_st, &intensity);
  if ((rangeData->size[0] != 0) && (rangeData->size[1] != 0)) {
    i = normal->size[0] * normal->size[1];
    normal->size[0] = varargin_1->size[0];
    normal->size[1] = rangeData->size[1];
    emxEnsureCapacity_real_T(&b_st, normal, i, &jc_emlrtRTEI);
    normal_data = normal->data;
    istop = rangeData->size[1];
    for (i = 0; i < istop; i++) {
      k = varargin_1->size[0];
      for (i1 = 0; i1 < k; i1++) {
        if (((int32_T)varargin_1_data[i1] < 1) ||
            ((int32_T)varargin_1_data[i1] > rangeData->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)varargin_1_data[i1], 1,
                                        rangeData->size[0], &f_emlrtBCI, &b_st);
        }
        normal_data[i1 + normal->size[0] * i] = rangeData_data
            [((int32_T)varargin_1_data[i1] + rangeData->size[0] * i) - 1];
      }
    }
  } else {
    normal->size[0] = 0;
    normal->size[1] = 0;
  }
  emxFree_real_T(&b_st, &rangeData);
  st.site = &ub_emlrtRSI;
  ptCloudOut = pointCloud_pointCloud(&st, iobj_0, loc, c, nv, b_intensity);
  emxFree_real_T(sp, &b_intensity);
  emxFree_real_T(sp, &nv);
  emxFree_uint8_T(sp, &c);
  emxFree_real_T(sp, &loc);
  st.site = &vb_emlrtRSI;
  pointCloudBase_set_RangeData(&st, ptCloudOut, normal);
  emxFree_real_T(sp, &normal);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return ptCloudOut;
}

/* End of code generation (pointCloud.c) */
