/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcsegdist.c
 *
 * Code generation for function 'pcsegdist'
 *
 */

/* Include files */
#include "pcsegdist.h"
#include "Faster_processingPcloud_data.h"
#include "Faster_processingPcloud_emxutil.h"
#include "Faster_processingPcloud_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "handle.h"
#include "indexShapeCheck.h"
#include "pointCloud.h"
#include "pointCloudBase.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "unique.h"
#include "cvstCG_ComputeMetric.h"
#include "cvstCG_kdtree.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo wd_emlrtRSI = {
    11,               /* lineNo */
    "validatescalar", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatescalar.m" /* pathName */
};

static emlrtRSInfo fg_emlrtRSI = {
    9,                                                           /* lineNo */
    "pcsegdist",                                                 /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo gg_emlrtRSI = {
    21,                                                          /* lineNo */
    "pcsegdist",                                                 /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo hg_emlrtRSI = {
    31,                                                          /* lineNo */
    "parseAndValidateInputs",                                    /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo ig_emlrtRSI = {
    34,                                                          /* lineNo */
    "parseAndValidateInputs",                                    /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo jg_emlrtRSI = {
    155,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo kg_emlrtRSI = {
    162,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo lg_emlrtRSI = {
    168,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo mg_emlrtRSI = {
    182,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo ng_emlrtRSI = {
    153,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo og_emlrtRSI = {
    236,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo pg_emlrtRSI = {
    239,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo qg_emlrtRSI = {
    241,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo rg_emlrtRSI = {
    245,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo sg_emlrtRSI = {
    308,                             /* lineNo */
    "pointCloud/extractValidPoints", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo tg_emlrtRSI = {
    311,                             /* lineNo */
    "pointCloud/extractValidPoints", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ug_emlrtRSI = {
    312,                             /* lineNo */
    "pointCloud/extractValidPoints", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    430,                                     /* lineNo */
    "pointCloudBase/extractValidPointsImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo wg_emlrtRSI = {
    15,    /* lineNo */
    "sum", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                     */
};

static emlrtRSInfo xg_emlrtRSI =
    {
        99,        /* lineNo */
        "sumprod", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
        "sumprod.m" /* pathName */
};

static emlrtRSInfo yg_emlrtRSI = {
    149,                     /* lineNo */
    "combineVectorElements", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo ah_emlrtRSI = {
    193,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo bh_emlrtRSI = {
    211,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo ch_emlrtRSI = {
    187,                                                         /* lineNo */
    "pcsegdistApproximateImpl",                                  /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo dh_emlrtRSI = {
    202,                                                         /* lineNo */
    "pcsegdistApproximateImpl",                                  /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo eh_emlrtRSI = {
    209,                                                         /* lineNo */
    "pcsegdistApproximateImpl",                                  /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo fh_emlrtRSI = {
    210,                                                         /* lineNo */
    "pcsegdistApproximateImpl",                                  /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    88,                                 /* lineNo */
    "pointCloud/findNeighborsInRadius", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo hh_emlrtRSI = {
    262,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo ih_emlrtRSI = {
    264,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    271,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo kh_emlrtRSI = {
    273,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo lh_emlrtRSI = {
    288,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo mh_emlrtRSI = {
    299,                                        /* lineNo */
    "pointCloudBase/findNeighborsInRadiusImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo nh_emlrtRSI = {
    1267,                                            /* lineNo */
    "pointCloud/validateAndParseRadiusSearchOption", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo oh_emlrtRSI = {
    1273,                                            /* lineNo */
    "pointCloud/validateAndParseRadiusSearchOption", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ph_emlrtRSI = {
    659,                                 /* lineNo */
    "pointCloudBase/validateQueryPoint", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    684,                             /* lineNo */
    "pointCloudBase/validateRadius", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo rh_emlrtRSI = {
    552,                                     /* lineNo */
    "pointCloudBase/bruteForceRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    554,                                     /* lineNo */
    "pointCloudBase/bruteForceRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    559,                                     /* lineNo */
    "pointCloudBase/bruteForceRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo uh_emlrtRSI = {
    907,                     /* lineNo */
    "pointCloud/bruteForce", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo xh_emlrtRSI = {
    968,                             /* lineNo */
    "pointCloud/kdtreeRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo yh_emlrtRSI = {
    970,                             /* lineNo */
    "pointCloud/kdtreeRadiusSearch", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ai_emlrtRSI = {
    16,                                                            /* lineNo */
    "sqrt",                                                        /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elfun/sqrt.m" /* pathName
                                                                    */
};

static emlrtRSInfo bi_emlrtRSI = {
    38,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

static emlrtRSInfo ci_emlrtRSI = {
    48,                                                            /* lineNo */
    "unique",                                                      /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

static emlrtRTEInfo x_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatepositive.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                                                          /* nDims */
    181,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pcsegdistImpl",                                             /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    177,                                                          /* lineNo */
    29,                                                           /* colNo */
    "",                                                           /* aName */
    "pcsegdistImpl",                                              /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    181,                                                          /* lineNo */
    8,                                                            /* colNo */
    "",                                                           /* aName */
    "pcsegdistImpl",                                              /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    177,                                                          /* lineNo */
    11,                                                           /* colNo */
    "",                                                           /* aName */
    "pcsegdistImpl",                                              /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    209,                                                          /* lineNo */
    53,                                                           /* colNo */
    "",                                                           /* aName */
    "pcsegdistApproximateImpl",                                   /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    237,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    244,                                                          /* lineNo */
    20,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    14,                    /* lineNo */
    37,                    /* colNo */
    "validatenonnegative", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnegative.m" /* pName */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    204,                                                          /* lineNo */
    14,                                                           /* colNo */
    "",                                                           /* aName */
    "pcsegdistApproximateImpl",                                   /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    207,                                  /* lineNo */
    45,                                   /* colNo */
    "kdtreeBuildable/kdtreeRadiusSearch", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m", /* pName */
    1                               /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    559,                                     /* lineNo */
    36,                                      /* colNo */
    "",                                      /* aName */
    "pointCloudBase/bruteForceRadiusSearch", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    259,                                                          /* lineNo */
    6,                                                            /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    240,                                                          /* lineNo */
    10,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    240,                                                          /* lineNo */
    22,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    261,                                                          /* lineNo */
    7,                                                            /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    250,                                                          /* lineNo */
    14,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    241,                                                          /* lineNo */
    14,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    241,                                                          /* lineNo */
    21,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    252,                                                          /* lineNo */
    18,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    251,                                                          /* lineNo */
    15,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    243,                                                          /* lineNo */
    25,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    253,                                                          /* lineNo */
    22,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    253,                                                          /* lineNo */
    15,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    564,                                     /* lineNo */
    35,                                      /* colNo */
    "",                                      /* aName */
    "pointCloudBase/bruteForceRadiusSearch", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    242,                                                          /* lineNo */
    28,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    242,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    244,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    565,                                     /* lineNo */
    33,                                      /* colNo */
    "",                                      /* aName */
    "pointCloudBase/bruteForceRadiusSearch", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    149,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = {
    427,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = {
    181,                     /* lineNo */
    24,                      /* colNo */
    "combineVectorElements", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pName */
};

static emlrtRTEInfo td_emlrtRTEI = {
    311,          /* lineNo */
    17,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = {
    1,                                                           /* lineNo */
    34,                                                          /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = {
    153,                                                         /* lineNo */
    2,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = {
    162,                                                         /* lineNo */
    5,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = {
    168,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    15,                                                             /* lineNo */
    9,                                                              /* colNo */
    "sum",                                                          /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m" /* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = {
    187,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI = {
    908,          /* lineNo */
    32,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = {
    207,               /* lineNo */
    39,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo de_emlrtRTEI = {
    208,               /* lineNo */
    37,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = {
    552,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = {
    43,                       /* lineNo */
    21,                       /* colNo */
    "ComputeMetricBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/ComputeMetricBuildable.m" /* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = {
    554,              /* lineNo */
    35,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo he_emlrtRTEI = {
    554,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = {
    261,                                                         /* lineNo */
    7,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo je_emlrtRTEI = {
    559,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = {
    185,                                                         /* lineNo */
    14,                                                          /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo le_emlrtRTEI = {
    261,                                                         /* lineNo */
    5,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo me_emlrtRTEI = {
    207,               /* lineNo */
    13,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = {
    208,               /* lineNo */
    13,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = {
    41,                       /* lineNo */
    17,                       /* colNo */
    "ComputeMetricBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/ComputeMetricBuildable.m" /* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = {
    242,                                                         /* lineNo */
    15,                                                          /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = {
    244,                                                         /* lineNo */
    15,                                                          /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pcsegdist.m" /* pName */
};

/* Function Declarations */
static void pcsegdistApproximateImpl(const emlrtStack *sp, pointCloud *pc,
                                     real_T minDistance, emxArray_uint32_T *L);

/* Function Definitions */
static void pcsegdistApproximateImpl(const emlrtStack *sp, pointCloud *pc,
                                     real_T minDistance, emxArray_uint32_T *L)
{
  static const char_T functionName[21] = {'f', 'i', 'n', 'd', 'N', 'e', 'i',
                                          'g', 'h', 'b', 'o', 'r', 's', 'I',
                                          'n', 'R', 'a', 'd', 'i', 'u', 's'};
  void *kdtreeObj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_boolean_T *b_allDists;
  emxArray_int32_T *ii;
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_real_T *allDists;
  emxArray_real_T *dists_;
  emxArray_real_T *features2;
  emxArray_real_T *r1;
  emxArray_uint32_T *indices_;
  real_T newLabel;
  real_T *allDists_data;
  real_T *dists__data;
  real_T *features2_data;
  real_T *r4;
  int32_T b_i;
  int32_T c_i;
  int32_T count;
  int32_T i;
  int32_T k;
  int32_T *ii_data;
  uint32_T u;
  uint32_T x;
  uint32_T *L_data;
  uint32_T *indices__data;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ch_emlrtRSI;
  count = pc->Location->size[0];
  i = L->size[0];
  L->size[0] = count;
  emxEnsureCapacity_uint32_T(sp, L, i, &ae_emlrtRTEI);
  L_data = L->data;
  for (i = 0; i < count; i++) {
    L_data[i] = 0U;
  }
  newLabel = 0.0;
  st.site = &dh_emlrtRSI;
  i = pc->Location->size[0];
  emxInit_int32_T(sp, &r, 1, &le_emlrtRTEI);
  emxInit_uint32_T(sp, &indices_, 1, &me_emlrtRTEI);
  emxInit_real_T(sp, &dists_, 1, &ne_emlrtRTEI);
  dists__data = dists_->data;
  emxInit_real_T(sp, &allDists, 2, &ee_emlrtRTEI);
  emxInit_int32_T(sp, &ii, 2, &lc_emlrtRTEI);
  emxInit_real_T(sp, &features2, 2, &be_emlrtRTEI);
  emxInit_real_T(sp, &r1, 2, &oe_emlrtRTEI);
  emxInit_int32_T(sp, &r2, 1, &pe_emlrtRTEI);
  emxInit_int32_T(sp, &r3, 1, &qe_emlrtRTEI);
  emxInit_boolean_T(sp, &b_allDists, 2, &ge_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i + 1 > L->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &bb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (L_data[b_i] == 0U) {
      real_T point[3];
      real_T c;
      int32_T b_loop_ub;
      int32_T loop_ub;
      int32_T trueCount;
      boolean_T exitg1;
      boolean_T n;
      st.site = &eh_emlrtRSI;
      c_i = pc->Location->size[0];
      if (b_i + 1 > c_i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, c_i, &x_emlrtBCI, &st);
      }
      point[0] = pc->Location->data[b_i];
      point[1] = pc->Location->data[b_i + pc->Location->size[0]];
      point[2] = pc->Location->data[b_i + pc->Location->size[0] * 2];
      b_st.site = &gh_emlrtRSI;
      c_st.site = &hh_emlrtRSI;
      d_st.site = &df_emlrtRSI;
      n = (pc->PointCloudArrayData->size[0] *
               pc->PointCloudArrayData->size[1] ==
           1);
      if (!n) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &t_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
            "vision:pointcloud:arrayNotSupported", 3, 4, 21, &functionName[0]);
      }
      c_st.site = &ih_emlrtRSI;
      d_st.site = &nh_emlrtRSI;
      e_st.site = &ph_emlrtRSI;
      f_st.site = &ub_emlrtRSI;
      n = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (!muDoubleScalarIsNaN(point[k])) {
          k++;
        } else {
          n = false;
          exitg1 = true;
        }
      }
      if (!n) {
        emlrtErrorWithMessageIdR2018a(
            &f_st, &m_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedNonNaN",
            "MATLAB:expectedNonNaN", 3, 4, 5, "point");
      }
      f_st.site = &ub_emlrtRSI;
      n = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if ((!muDoubleScalarIsInf(point[k])) &&
            (!muDoubleScalarIsNaN(point[k]))) {
          k++;
        } else {
          n = false;
          exitg1 = true;
        }
      }
      if (!n) {
        emlrtErrorWithMessageIdR2018a(
            &f_st, &i_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedFinite",
            "MATLAB:expectedFinite", 3, 4, 5, "point");
      }
      d_st.site = &oh_emlrtRSI;
      e_st.site = &qh_emlrtRSI;
      f_st.site = &ub_emlrtRSI;
      if (muDoubleScalarIsNaN(minDistance)) {
        emlrtErrorWithMessageIdR2018a(
            &f_st, &m_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedNonNaN",
            "MATLAB:expectedNonNaN", 3, 4, 6, "radius");
      }
      f_st.site = &ub_emlrtRSI;
      if (muDoubleScalarIsInf(minDistance)) {
        emlrtErrorWithMessageIdR2018a(
            &f_st, &i_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedFinite",
            "MATLAB:expectedFinite", 3, 4, 6, "radius");
      }
      f_st.site = &ub_emlrtRSI;
      if (minDistance < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &f_st, &ab_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedNonnegative",
            "MATLAB:expectedNonnegative", 3, 4, 6, "radius");
      }
      c_st.site = &jh_emlrtRSI;
      count = pc->Location->size[0];
      if (count < 500) {
        c_st.site = &kh_emlrtRSI;
        d_st.site = &rh_emlrtRSI;
        count = pc->Location->size[0];
        e_st.site = &uh_emlrtRSI;
        loop_ub = pc->Location->size[0];
        c_i = features2->size[0] * features2->size[1];
        features2->size[0] = loop_ub;
        features2->size[1] = 3;
        emxEnsureCapacity_real_T(&e_st, features2, c_i, &be_emlrtRTEI);
        features2_data = features2->data;
        b_loop_ub = pc->Location->size[0] * 3;
        for (c_i = 0; c_i < b_loop_ub; c_i++) {
          features2_data[c_i] = pc->Location->data[c_i];
        }
        c_i = allDists->size[0] * allDists->size[1];
        allDists->size[0] = 1;
        allDists->size[1] = count;
        emxEnsureCapacity_real_T(&e_st, allDists, c_i, &ee_emlrtRTEI);
        allDists_data = allDists->data;
        for (c_i = 0; c_i < count; c_i++) {
          allDists_data[c_i] = 0.0;
        }
        c_i = r1->size[0] * r1->size[1];
        r1->size[0] = 3;
        r1->size[1] = loop_ub;
        emxEnsureCapacity_real_T(&e_st, r1, c_i, &fe_emlrtRTEI);
        r4 = r1->data;
        for (c_i = 0; c_i < loop_ub; c_i++) {
          r4[3 * c_i] = features2_data[c_i];
          r4[3 * c_i + 1] = features2_data[c_i + features2->size[0]];
          r4[3 * c_i + 2] = features2_data[c_i + features2->size[0] * 2];
        }
        ComputeMetric_ssd_double(&point[0], &r4[0], &allDists_data[0], 1U,
                                 (uint32_T)features2->size[0], 3U);
        d_st.site = &sh_emlrtRSI;
        e_st.site = &vh_emlrtRSI;
        c = minDistance * minDistance;
        d_st.site = &sh_emlrtRSI;
        c_i = b_allDists->size[0] * b_allDists->size[1];
        b_allDists->size[0] = 1;
        loop_ub = allDists->size[1];
        b_allDists->size[1] = allDists->size[1];
        emxEnsureCapacity_boolean_T(&d_st, b_allDists, c_i, &ge_emlrtRTEI);
        b_allDists_data = b_allDists->data;
        for (c_i = 0; c_i < loop_ub; c_i++) {
          b_allDists_data[c_i] = (allDists_data[c_i] <= c);
        }
        e_st.site = &re_emlrtRSI;
        b_eml_find(&e_st, b_allDists, ii);
        ii_data = ii->data;
        b_loop_ub = ii->size[1];
        c_i = indices_->size[0];
        indices_->size[0] = ii->size[1];
        emxEnsureCapacity_uint32_T(&c_st, indices_, c_i, &he_emlrtRTEI);
        indices__data = indices_->data;
        for (c_i = 0; c_i < b_loop_ub; c_i++) {
          count = ii_data[c_i];
          if (count < 0) {
            count = 0;
          }
          indices__data[c_i] = (uint32_T)count;
        }
        if (indices_->size[0] == 0) {
          dists_->size[0] = 0;
        } else {
          d_st.site = &th_emlrtRSI;
          b_indexShapeCheck(&d_st, allDists->size, indices_->size[0]);
          c_i = dists_->size[0];
          dists_->size[0] = ii->size[1];
          emxEnsureCapacity_real_T(&c_st, dists_, c_i, &je_emlrtRTEI);
          dists__data = dists_->data;
          for (c_i = 0; c_i < b_loop_ub; c_i++) {
            if (((int32_T)indices__data[c_i] < 1) ||
                ((int32_T)indices__data[c_i] > loop_ub)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)indices__data[c_i], 1,
                                            loop_ub, &cb_emlrtBCI, &c_st);
            }
            dists__data[c_i] = allDists_data[(int32_T)indices__data[c_i] - 1];
          }
          count = dists_->size[0];
          trueCount = 0;
          for (c_i = 0; c_i < count; c_i++) {
            if ((!muDoubleScalarIsInf(dists__data[c_i])) &&
                (!muDoubleScalarIsNaN(dists__data[c_i]))) {
              trueCount++;
            }
          }
          b_loop_ub = 0;
          for (c_i = 0; c_i < count; c_i++) {
            if ((!muDoubleScalarIsInf(dists__data[c_i])) &&
                (!muDoubleScalarIsNaN(dists__data[c_i]))) {
              if (c_i > indices_->size[0] - 1) {
                emlrtDynamicBoundsCheckR2012b(c_i, 0, indices_->size[0] - 1,
                                              &pb_emlrtBCI, &c_st);
              }
              indices__data[b_loop_ub] = indices__data[c_i];
              b_loop_ub++;
            }
          }
          c_i = indices_->size[0];
          indices_->size[0] = trueCount;
          emxEnsureCapacity_uint32_T(&c_st, indices_, c_i, &ke_emlrtRTEI);
          indices__data = indices_->data;
          trueCount = 0;
          for (c_i = 0; c_i < count; c_i++) {
            if ((!muDoubleScalarIsInf(dists__data[c_i])) &&
                (!muDoubleScalarIsNaN(dists__data[c_i]))) {
              trueCount++;
            }
          }
          b_loop_ub = 0;
          for (c_i = 0; c_i < count; c_i++) {
            if ((!muDoubleScalarIsInf(dists__data[c_i])) &&
                (!muDoubleScalarIsNaN(dists__data[c_i]))) {
              if (c_i > dists_->size[0] - 1) {
                emlrtDynamicBoundsCheckR2012b(c_i, 0, dists_->size[0] - 1,
                                              &tb_emlrtBCI, &c_st);
              }
              dists__data[b_loop_ub] = dists__data[c_i];
              b_loop_ub++;
            }
          }
          c_i = dists_->size[0];
          dists_->size[0] = trueCount;
          emxEnsureCapacity_real_T(&c_st, dists_, c_i, &ke_emlrtRTEI);
          dists__data = dists_->data;
        }
      } else {
        void *ptrDists;
        void *ptrIndices;
        c_st.site = &lh_emlrtRSI;
        d_st.site = &xh_emlrtRSI;
        pointCloud_buildKdtree(&d_st, pc);
        d_st.site = &yh_emlrtRSI;
        kdtreeObj = pc->Kdtree;
        ptrIndices = NULL;
        ptrDists = NULL;
        kdtreeRadiusSearch_double(kdtreeObj, &point[0], 1U, 3U, minDistance,
                                  0.0, &ptrIndices, &ptrDists, &x, 1000, 500U);
        c = c_sumColumnB(x);
        if (c != (int32_T)muDoubleScalarFloor(c)) {
          emlrtIntegerCheckR2012b(c, &emlrtDCI, &d_st);
        }
        c_i = indices_->size[0];
        indices_->size[0] = (int32_T)c;
        emxEnsureCapacity_uint32_T(&d_st, indices_, c_i, &ce_emlrtRTEI);
        indices__data = indices_->data;
        c_i = dists_->size[0];
        dists_->size[0] = (int32_T)c;
        emxEnsureCapacity_real_T(&d_st, dists_, c_i, &de_emlrtRTEI);
        dists__data = dists_->data;
        kdtreeRadiusSearchSetOutputs_double(ptrIndices, ptrDists,
                                            &indices__data[0], &dists__data[0]);
      }
      c_st.site = &mh_emlrtRSI;
      n = false;
      c_i = dists_->size[0];
      for (k = 0; k < c_i; k++) {
        if (n || (dists__data[k] < 0.0)) {
          n = true;
        }
      }
      if (n) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &y_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      d_st.site = &ai_emlrtRSI;
      e_st.site = &bi_emlrtRSI;
      if (dists_->size[0] > 2147483646) {
        f_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }
      st.site = &fh_emlrtRSI;
      c = newLabel;
      loop_ub = indices_->size[0];
      for (k = 0; k < loop_ub; k++) {
        uint32_T b_L;
        boolean_T guard1;
        if (k + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, loop_ub, &y_emlrtBCI, &st);
        }
        count = L->size[0];
        if (((int32_T)indices__data[k] < 1) ||
            ((int32_T)indices__data[k] > L->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)indices__data[k], 1,
                                        L->size[0], &eb_emlrtBCI, &st);
        }
        c_i = (int32_T)indices__data[k] - 1;
        b_L = L_data[c_i];
        guard1 = false;
        if (b_L > 0U) {
          uint32_T c_L;
          if (b_i + 1 > L->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &fb_emlrtBCI,
                                          &st);
          }
          c_L = L_data[b_i];
          if (c_L > 0U) {
            n = (((int32_T)indices__data[k] < 1) ||
                 ((int32_T)indices__data[k] > L->size[0]));
            if (n) {
              emlrtDynamicBoundsCheckR2012b((int32_T)indices__data[k], 1,
                                            L->size[0], &ib_emlrtBCI, &st);
            }
            if (b_i + 1 > L->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                            &jb_emlrtBCI, &st);
            }
            if (b_L > c_L) {
              trueCount = 0;
              for (c_i = 0; c_i < count; c_i++) {
                if (L_data[c_i] == b_L) {
                  trueCount++;
                }
              }
              c_i = r2->size[0];
              r2->size[0] = trueCount;
              emxEnsureCapacity_int32_T(&st, r2, c_i, &ke_emlrtRTEI);
              ii_data = r2->data;
              b_loop_ub = 0;
              for (c_i = 0; c_i < count; c_i++) {
                if (L_data[c_i] == b_L) {
                  ii_data[b_loop_ub] = c_i;
                  b_loop_ub++;
                }
              }
              if (b_i + 1 > L->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                              &qb_emlrtBCI, &st);
              }
              b_loop_ub = r2->size[0];
              for (c_i = 0; c_i < b_loop_ub; c_i++) {
                if (ii_data[c_i] > L->size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(ii_data[c_i], 0, L->size[0] - 1,
                                                &rb_emlrtBCI, &st);
                }
                L_data[ii_data[c_i]] = c_L;
              }
            } else {
              if (b_i + 1 > L->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                              &mb_emlrtBCI, &st);
              }
              if (b_L < c_L) {
                if (b_i + 1 > L->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                                &ab_emlrtBCI, &st);
                }
                trueCount = 0;
                for (c_i = 0; c_i < count; c_i++) {
                  if (L_data[c_i] == L_data[b_i]) {
                    trueCount++;
                  }
                }
                c_i = r3->size[0];
                r3->size[0] = trueCount;
                emxEnsureCapacity_int32_T(&st, r3, c_i, &ke_emlrtRTEI);
                ii_data = r3->data;
                b_loop_ub = 0;
                for (c_i = 0; c_i < count; c_i++) {
                  if (L_data[c_i] == L_data[b_i]) {
                    ii_data[b_loop_ub] = c_i;
                    b_loop_ub++;
                  }
                }
                b_loop_ub = r3->size[0];
                for (c_i = 0; c_i < b_loop_ub; c_i++) {
                  if (ii_data[c_i] > L->size[0] - 1) {
                    emlrtDynamicBoundsCheckR2012b(
                        ii_data[c_i], 0, L->size[0] - 1, &sb_emlrtBCI, &st);
                  }
                  L_data[ii_data[c_i]] = b_L;
                }
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          n = (((int32_T)indices__data[k] < 1) ||
               ((int32_T)indices__data[k] > L->size[0]));
          if (n) {
            emlrtDynamicBoundsCheckR2012b((int32_T)indices__data[k], 1,
                                          L->size[0], &hb_emlrtBCI, &st);
          }
          if (b_L > 0U) {
            if (b_i + 1 > L->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                            &lb_emlrtBCI, &st);
            }
            L_data[b_i] = b_L;
          } else {
            if (b_i + 1 > L->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                            &kb_emlrtBCI, &st);
            }
            b_L = L_data[b_i];
            if (b_L > 0U) {
              if (b_i + 1 > L->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                              &nb_emlrtBCI, &st);
              }
              if (((int32_T)indices__data[k] < 1) ||
                  ((int32_T)indices__data[k] > L->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)indices__data[k], 1,
                                              L->size[0], &ob_emlrtBCI, &st);
              }
              L_data[c_i] = b_L;
            }
          }
        }
      }
      c_i = L->size[0];
      if (b_i + 1 > L->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &db_emlrtBCI,
                                      &st);
      }
      if (L_data[b_i] == 0U) {
        c = newLabel + 1.0;
        count = r->size[0];
        r->size[0] = indices_->size[0];
        emxEnsureCapacity_int32_T(&st, r, count, &ie_emlrtRTEI);
        ii_data = r->data;
        for (count = 0; count < loop_ub; count++) {
          if (((int32_T)indices__data[count] < 1) ||
              ((int32_T)indices__data[count] > c_i)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)indices__data[count], 1, c_i,
                                          &gb_emlrtBCI, &st);
          }
          ii_data[count] = (int32_T)indices__data[count];
        }
        loop_ub = r->size[0];
        if (loop_ub - 1 >= 0) {
          if (newLabel + 1.0 < 4.294967296E+9) {
            u = (uint32_T)(newLabel + 1.0);
          } else {
            u = MAX_uint32_T;
          }
        }
        for (c_i = 0; c_i < loop_ub; c_i++) {
          L_data[ii_data[c_i] - 1] = u;
        }
      }
      newLabel = c;
    }
  }
  emxFree_boolean_T(sp, &b_allDists);
  emxFree_int32_T(sp, &r3);
  emxFree_int32_T(sp, &r2);
  emxFree_real_T(sp, &r1);
  emxFree_real_T(sp, &features2);
  emxFree_int32_T(sp, &ii);
  emxFree_real_T(sp, &allDists);
  emxFree_real_T(sp, &dists_);
  emxFree_uint32_T(sp, &indices_);
  emxFree_int32_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

real_T pcsegdist(const emlrtStack *sp, const pointCloud *ptCloud,
                 real_T minDistance, emxArray_uint32_T *labels)
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
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  emxArray_boolean_T *indices;
  emxArray_boolean_T *tf;
  emxArray_int32_T *b_r;
  emxArray_int32_T *nz;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T *intensity;
  emxArray_real_T *loc;
  emxArray_real_T *nv;
  emxArray_real_T *r;
  emxArray_uint32_T *L;
  emxArray_uint32_T *uniqueLabels;
  emxArray_uint8_T *c;
  pointCloud pc;
  pointCloud *b_pc;
  real_T numClusters;
  real_T *loc_data;
  int32_T b_i;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T xoffset;
  int32_T *nz_data;
  uint32_T labelsSize_idx_0;
  uint32_T *L_data;
  uint32_T *labels_data;
  uint32_T *uniqueLabels_data;
  uint8_T *c_data;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud(sp, &pc, &vd_emlrtRTEI);
  emxInit_uint32_T(sp, &L, 1, &wd_emlrtRTEI);
  emxInit_uint32_T(sp, &uniqueLabels, 1, &xd_emlrtRTEI);
  emxInit_boolean_T(sp, &indices, 1, &ud_emlrtRTEI);
  emxInit_boolean_T(sp, &tf, 2, &rd_emlrtRTEI);
  emxInit_int32_T(sp, &nz, 1, &yd_emlrtRTEI);
  nz_data = nz->data;
  emxInit_real_T(sp, &loc, 2, &ud_emlrtRTEI);
  emxInit_uint8_T(sp, &c, &ud_emlrtRTEI);
  emxInit_real_T(sp, &nv, 2, &ud_emlrtRTEI);
  emxInit_real_T(sp, &intensity, 2, &ud_emlrtRTEI);
  emxInit_real_T(sp, &r, 2, &ud_emlrtRTEI);
  emxInit_int32_T(sp, &b_r, 1, &bd_emlrtRTEI);
  emxInit_int32_T(sp, &r1, 1, &bd_emlrtRTEI);
  emxInit_int32_T(sp, &r2, 1, &bd_emlrtRTEI);
  emxInit_int32_T(sp, &r3, 1, &bd_emlrtRTEI);
  emxInit_int32_T(sp, &r4, 1, &bd_emlrtRTEI);
  st.site = &fg_emlrtRSI;
  b_st.site = &hg_emlrtRSI;
  c_st.site = &ub_emlrtRSI;
  d_st.site = &wd_emlrtRSI;
  if (ptCloud->PointCloudArrayData->size[0] *
          ptCloud->PointCloudArrayData->size[1] !=
      1) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:pcsegdist:expectedScalar", 3, 4, 7, "ptCloud");
  }
  b_st.site = &ig_emlrtRSI;
  c_st.site = &ub_emlrtRSI;
  if (muDoubleScalarIsNaN(minDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:pcsegdist:expectedNonNaN", 3, 4, 11, "minDistance");
  }
  c_st.site = &ub_emlrtRSI;
  if (minDistance <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &x_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:pcsegdist:expectedPositive", 3, 4, 11, "minDistance");
  }
  c_st.site = &ub_emlrtRSI;
  if (muDoubleScalarIsInf(minDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &i_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:pcsegdist:expectedFinite", 3, 4, 11, "minDistance");
  }
  st.site = &gg_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, &pc,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  pc.matlabCodegenIsDeleted = true;
  labelsSize_idx_0 = (uint32_T)ptCloud->Location->size[0];
  i = labels->size[0];
  labels->size[0] = (int32_T)labelsSize_idx_0;
  emxEnsureCapacity_uint32_T(&st, labels, i, &qd_emlrtRTEI);
  labels_data = labels->data;
  loop_ub = (int32_T)labelsSize_idx_0;
  for (i = 0; i < loop_ub; i++) {
    labels_data[i] = 0U;
  }
  b_st.site = &ng_emlrtRSI;
  c_st.site = &og_emlrtRSI;
  d_st.site = &sg_emlrtRSI;
  e_st.site = &df_emlrtRSI;
  if (ptCloud->PointCloudArrayData->size[0] *
          ptCloud->PointCloudArrayData->size[1] !=
      1) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &t_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 19, &functionName[0]);
  }
  d_st.site = &tg_emlrtRSI;
  i = ptCloud->Location->size[0];
  b_i = tf->size[0] * tf->size[1];
  tf->size[0] = i;
  tf->size[1] = 3;
  emxEnsureCapacity_boolean_T(&d_st, tf, b_i, &rd_emlrtRTEI);
  tf_data = tf->data;
  loop_ub = ptCloud->Location->size[0] * 3;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    tf_data[b_i] = ((!muDoubleScalarIsInf(ptCloud->Location->data[b_i])) &&
                    (!muDoubleScalarIsNaN(ptCloud->Location->data[b_i])));
  }
  e_st.site = &vg_emlrtRSI;
  f_st.site = &wg_emlrtRSI;
  g_st.site = &xg_emlrtRSI;
  if (tf->size[0] == 0) {
    nz->size[0] = 0;
  } else {
    h_st.site = &yg_emlrtRSI;
    b_i = nz->size[0];
    nz->size[0] = i;
    emxEnsureCapacity_int32_T(&h_st, nz, b_i, &sd_emlrtRTEI);
    nz_data = nz->data;
    i_st.site = &ah_emlrtRSI;
    if (tf->size[0] > 2147483646) {
      j_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&j_st);
    }
    for (j = 0; j < i; j++) {
      nz_data[j] = tf_data[j];
    }
    for (k = 0; k < 2; k++) {
      xoffset = (k + 1) * i;
      i_st.site = &bh_emlrtRSI;
      for (j = 0; j < i; j++) {
        nz_data[j] += tf_data[xoffset + j];
      }
    }
  }
  loop_ub = nz->size[0];
  i = indices->size[0];
  indices->size[0] = nz->size[0];
  emxEnsureCapacity_boolean_T(&d_st, indices, i, &td_emlrtRTEI);
  tf_data = indices->data;
  for (i = 0; i < loop_ub; i++) {
    tf_data[i] = (nz_data[i] == 3);
  }
  d_st.site = &ug_emlrtRSI;
  e_st.site = &sf_emlrtRSI;
  if (ptCloud->Location->size[0] != 0) {
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = b_r->size[0];
    b_r->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, b_r, i, &ud_emlrtRTEI);
    nz_data = b_r->data;
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        nz_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->Location->size[0];
    j = b_r->size[0];
    i = loc->size[0] * loc->size[1];
    loc->size[0] = b_r->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(&e_st, loc, i, &bd_emlrtRTEI);
    loc_data = loc->data;
    for (i = 0; i < 3; i++) {
      for (b_i = 0; b_i < j; b_i++) {
        if (nz_data[b_i] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[b_i], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        loc_data[b_i + loc->size[0] * i] =
            ptCloud->Location
                ->data[nz_data[b_i] + ptCloud->Location->size[0] * i];
      }
    }
  } else {
    loc->size[0] = 0;
    loc->size[1] = 3;
  }
  if ((ptCloud->Color->size[0] != 0) && (ptCloud->Color->size[1] != 0)) {
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = r1->size[0];
    r1->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, r1, i, &ud_emlrtRTEI);
    nz_data = r1->data;
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        nz_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->Color->size[0];
    j = r1->size[0];
    i = c->size[0] * c->size[1];
    c->size[0] = r1->size[0];
    c->size[1] = ptCloud->Color->size[1];
    emxEnsureCapacity_uint8_T(&e_st, c, i, &bd_emlrtRTEI);
    c_data = c->data;
    k = ptCloud->Color->size[1];
    for (i = 0; i < k; i++) {
      for (b_i = 0; b_i < j; b_i++) {
        if (nz_data[b_i] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[b_i], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        c_data[b_i + c->size[0] * i] =
            ptCloud->Color->data[nz_data[b_i] + ptCloud->Color->size[0] * i];
      }
    }
  } else {
    c->size[0] = 0;
    c->size[1] = 0;
  }
  if ((ptCloud->Normal->size[0] != 0) && (ptCloud->Normal->size[1] != 0)) {
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = r2->size[0];
    r2->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, r2, i, &ud_emlrtRTEI);
    nz_data = r2->data;
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        nz_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->Normal->size[0];
    j = r2->size[0];
    i = nv->size[0] * nv->size[1];
    nv->size[0] = r2->size[0];
    nv->size[1] = ptCloud->Normal->size[1];
    emxEnsureCapacity_real_T(&e_st, nv, i, &bd_emlrtRTEI);
    loc_data = nv->data;
    k = ptCloud->Normal->size[1];
    for (i = 0; i < k; i++) {
      for (b_i = 0; b_i < j; b_i++) {
        if (nz_data[b_i] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[b_i], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        loc_data[b_i + nv->size[0] * i] =
            ptCloud->Normal->data[nz_data[b_i] + ptCloud->Normal->size[0] * i];
      }
    }
  } else {
    nv->size[0] = 0;
    nv->size[1] = 0;
  }
  if ((ptCloud->Intensity->size[0] != 0) &&
      (ptCloud->Intensity->size[1] != 0)) {
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = r3->size[0];
    r3->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, r3, i, &ud_emlrtRTEI);
    nz_data = r3->data;
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        nz_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->Intensity->size[0];
    j = r3->size[0];
    i = intensity->size[0] * intensity->size[1];
    intensity->size[0] = r3->size[0];
    intensity->size[1] = ptCloud->Intensity->size[1];
    emxEnsureCapacity_real_T(&e_st, intensity, i, &bd_emlrtRTEI);
    loc_data = intensity->data;
    k = ptCloud->Intensity->size[1];
    for (i = 0; i < k; i++) {
      for (b_i = 0; b_i < j; b_i++) {
        if (nz_data[b_i] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[b_i], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        loc_data[b_i + intensity->size[0] * i] =
            ptCloud->Intensity
                ->data[nz_data[b_i] + ptCloud->Intensity->size[0] * i];
      }
    }
  } else {
    intensity->size[0] = 0;
    intensity->size[1] = 0;
  }
  if ((ptCloud->RangeData->size[0] != 0) &&
      (ptCloud->RangeData->size[1] != 0)) {
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = r4->size[0];
    r4->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, r4, i, &ud_emlrtRTEI);
    nz_data = r4->data;
    xoffset = 0;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (tf_data[b_i]) {
        nz_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->RangeData->size[0];
    loop_ub = r4->size[0];
    i = r->size[0] * r->size[1];
    r->size[0] = r4->size[0];
    r->size[1] = ptCloud->RangeData->size[1];
    emxEnsureCapacity_real_T(&e_st, r, i, &bd_emlrtRTEI);
    loc_data = r->data;
    j = ptCloud->RangeData->size[1];
    for (i = 0; i < j; i++) {
      for (b_i = 0; b_i < loop_ub; b_i++) {
        if (nz_data[b_i] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[b_i], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        loc_data[b_i + r->size[0] * i] =
            ptCloud->RangeData
                ->data[nz_data[b_i] + ptCloud->RangeData->size[0] * i];
      }
    }
  } else {
    r->size[0] = 0;
    r->size[1] = 0;
  }
  c_st.site = &pg_emlrtRSI;
  b_pc = b_pointCloud_pointCloud(&c_st, &pc, loc, c, nv, intensity);
  c_st.site = &qg_emlrtRSI;
  pointCloudBase_set_RangeData(&c_st, b_pc, r);
  c_st.site = &rg_emlrtRSI;
  d_st.site = &re_emlrtRSI;
  eml_find(&d_st, indices, nz);
  nz_data = nz->data;
  b_st.site = &jg_emlrtRSI;
  xoffset = pc.Location->size[0];
  if (xoffset == 0) {
    j = 0;
  } else {
    b_st.site = &kg_emlrtRSI;
    pcsegdistApproximateImpl(&b_st, &pc, minDistance, L);
    L_data = L->data;
    b_st.site = &lg_emlrtRSI;
    c_st.site = &ci_emlrtRSI;
    unique_vector(&c_st, L, uniqueLabels);
    uniqueLabels_data = uniqueLabels->data;
    j = uniqueLabels->size[0];
    i = uniqueLabels->size[0];
    for (k = 0; k < i; k++) {
      if (k + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, i, &u_emlrtBCI, &st);
      }
      xoffset = L->size[0];
      for (b_i = 0; b_i < xoffset; b_i++) {
        if (L_data[b_i] == uniqueLabels_data[k]) {
          if (b_i > L->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, L->size[0] - 1, &w_emlrtBCI,
                                          &st);
          }
          L_data[b_i] = (uint32_T)(k + 1);
        }
      }
    }
    xoffset = nz->size[0];
    for (i = 0; i < xoffset; i++) {
      if ((nz_data[i] < 1) || (nz_data[i] > (int32_T)labelsSize_idx_0)) {
        emlrtDynamicBoundsCheckR2012b(nz_data[i], 1, (int32_T)labelsSize_idx_0,
                                      &v_emlrtBCI, &st);
      }
    }
    loop_ub = L->size[0];
    if (nz->size[0] != L->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(nz->size[0], L->size[0], &b_emlrtECI,
                                      &st);
    }
    for (i = 0; i < loop_ub; i++) {
      labels_data[nz_data[i] - 1] = L_data[i];
    }
  }
  b_st.site = &mg_emlrtRSI;
  handle_matlabCodegenDestructor(&b_st, &pc);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
  numClusters = j;
  emxFree_int32_T(sp, &r4);
  emxFree_int32_T(sp, &r3);
  emxFree_int32_T(sp, &r2);
  emxFree_int32_T(sp, &r1);
  emxFree_int32_T(sp, &b_r);
  emxFree_real_T(sp, &r);
  emxFree_real_T(sp, &intensity);
  emxFree_real_T(sp, &nv);
  emxFree_uint8_T(sp, &c);
  emxFree_real_T(sp, &loc);
  emxFree_int32_T(sp, &nz);
  emxFree_boolean_T(sp, &tf);
  emxFree_boolean_T(sp, &indices);
  emxFree_uint32_T(sp, &uniqueLabels);
  emxFree_uint32_T(sp, &L);
  emxFreeStruct_pointCloud(sp, &pc);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return numClusters;
}

/* End of code generation (pcsegdist.c) */
