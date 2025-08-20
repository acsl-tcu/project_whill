/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * HelperBoundingBoxDetector.c
 *
 * Code generation for function 'HelperBoundingBoxDetector'
 *
 */

/* Include files */
#include "HelperBoundingBoxDetector.h"
#include "Faster_processingPcloud_data.h"
#include "Faster_processingPcloud_emxutil.h"
#include "Faster_processingPcloud_internal_types.h"
#include "Faster_processingPcloud_types.h"
#include "affine3d.h"
#include "det.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "handle.h"
#include "homogeneous.h"
#include "ismember.h"
#include "mean.h"
#include "pcsegdist.h"
#include "pointCloud.h"
#include "rigid3dImpl.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "PCANormalCore_api.hpp"
#include "cvstCG_kdtree.h"
#include "mwmathutil.h"
#include <math.h>

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = {
    91,                                   /* lineNo */
    "HelperBoundingBoxDetector/stepImpl", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    103,                                  /* lineNo */
    "HelperBoundingBoxDetector/stepImpl", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    85,                                   /* lineNo */
    "HelperBoundingBoxDetector/stepImpl", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    333,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    346,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    347,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    349,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    330,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    331,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    348,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    49,                /* lineNo */
    "rigid3d/rigid3d", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/+coder/"
    "rigid3d.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    50,                /* lineNo */
    "rigid3d/rigid3d", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/+coder/"
    "rigid3d.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    86,                        /* lineNo */
    "rigid3dImpl/rigid3dImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    87,                        /* lineNo */
    "rigid3dImpl/rigid3dImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    98,                        /* lineNo */
    "rigid3dImpl/rigid3dImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    102,                       /* lineNo */
    "rigid3dImpl/rigid3dImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    8,                                                             /* lineNo */
    "pctransform",                                                 /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pctransform.m" /* pathName
                                                                    */
};

static emlrtRSInfo vd_emlrtRSI = {
    59,                                                            /* lineNo */
    "pctransform",                                                 /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/pctransform.m" /* pathName
                                                                    */
};

static emlrtRSInfo xd_emlrtRSI = {
    31,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    44,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    55,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    66,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    70,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    72,          /* lineNo */
    "transform", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    10,                 /* lineNo */
    "isRigidTransform", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "isRigidTransform.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    12,                 /* lineNo */
    "isRigidTransform", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "isRigidTransform.m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI = {
    463,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo je_emlrtRSI = {
    469,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ke_emlrtRSI = {
    478,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo tf_emlrtRSI = {
    164,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo uf_emlrtRSI = {
    173,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo vf_emlrtRSI = {
    176,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    177,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo xf_emlrtRSI = {
    178,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    179,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    180,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI = {
    181,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo cg_emlrtRSI = {
    188,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo dg_emlrtRSI = {
    198,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo eg_emlrtRSI = {
    200,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo wh_emlrtRSI = {
    71,                                                           /* lineNo */
    "power",                                                      /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtRSInfo vi_emlrtRSI = {
    45,         /* lineNo */
    "ismember", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName
                                                                      */
};

static emlrtECInfo emlrtECI = {
    1,                 /* nDims */
    337,               /* lineNo */
    14,                /* colNo */
    "cropPointCloud2", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    87,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    80,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    99,                        /* lineNo */
    21,                        /* colNo */
    "rigid3dImpl/rigid3dImpl", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    120,               /* lineNo */
    9,                 /* colNo */
    "computeDimsData", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    32,          /* lineNo */
    26,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    32,          /* lineNo */
    54,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    33,          /* lineNo */
    17,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    35,          /* lineNo */
    17,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    36,          /* lineNo */
    17,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    37,          /* lineNo */
    17,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    56,          /* lineNo */
    30,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    56,          /* lineNo */
    56,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    57,          /* lineNo */
    21,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    59,          /* lineNo */
    20,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    60,          /* lineNo */
    20,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    61,          /* lineNo */
    20,          /* colNo */
    "",          /* aName */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    195,                /* lineNo */
    28,                 /* colNo */
    "isValidCluster",   /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    208,                /* lineNo */
    19,                 /* colNo */
    "newLabels",        /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    201,                /* lineNo */
    12,                 /* colNo */
    "labels",           /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    172,                /* lineNo */
    35,                 /* colNo */
    "pointData",        /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    207,                  /* lineNo */
    41,                   /* colNo */
    "pedestrianClusters", /* aName */
    "getBoundingBoxes",   /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    194,                /* lineNo */
    22,                 /* colNo */
    "bboxes",           /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m", /* pName */
    0                                        /* checkKind */
};

static emlrtRTEInfo w_emlrtRTEI =
    {
        198,             /* lineNo */
        27,              /* colNo */
        "unaryMinOrMax", /* fName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pName */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    212,                /* lineNo */
    23,                 /* colNo */
    "bboxes",           /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m", /* pName */
    0                                        /* checkKind */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    29,          /* lineNo */
    30,          /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    332,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    333,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    334,                         /* lineNo */
    15,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    334,                         /* lineNo */
    45,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    53,          /* lineNo */
    33,          /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    335,                         /* lineNo */
    15,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    335,                         /* lineNo */
    45,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    460,          /* lineNo */
    21,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    442,          /* lineNo */
    17,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    336,                         /* lineNo */
    15,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    336,                         /* lineNo */
    45,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    470,          /* lineNo */
    47,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    146,               /* lineNo */
    38,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    147,               /* lineNo */
    36,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    148,               /* lineNo */
    36,                /* colNo */
    "kdtreeBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    49,                   /* lineNo */
    17,                   /* colNo */
    "PCANormalBuildable", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/"
    "+buildable/PCANormalBuildable.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    346,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    478,          /* lineNo */
    21,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    347,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    86,                          /* lineNo */
    13,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    87,                          /* lineNo */
    13,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    85,                          /* lineNo */
    14,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    331,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    334,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    335,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    336,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    66,                          /* lineNo */
    112,                         /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    16,          /* lineNo */
    9,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    42,          /* lineNo */
    1,           /* colNo */
    "transform", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+pc/"
    "transform.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    478,          /* lineNo */
    35,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    167,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = {
    168,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = {
    198,                         /* lineNo */
    31,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    118,                         /* lineNo */
    40,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = {
    198,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo id_emlrtRTEI = {
    172,                         /* lineNo */
    25,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = {
    204,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = {
    212,                         /* lineNo */
    14,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = {
    212,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo md_emlrtRTEI = {
    200,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = {
    118,                         /* lineNo */
    30,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo od_emlrtRTEI = {
    172,                         /* lineNo */
    35,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    212,                         /* lineNo */
    23,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = {
    337,                         /* lineNo */
    14,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pName */
};

static emlrtRSInfo lk_emlrtRSI = {
    337,               /* lineNo */
    "cropPointCloud2", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

/* Function Declarations */
static void b_and(const emlrtStack *sp, emxArray_boolean_T *in1,
                  const emxArray_boolean_T *in2);

static real_T getBoundingBoxes(const emlrtStack *sp, const pointCloud *ptCloud,
                               real_T minDistance, real_T minDetsPerCluster,
                               real_T maxZDistance, real_T minZDistance,
                               real_T Plant_X, real_T Plant_Y, real_T Plant_yaw,
                               emxArray_real_T *bboxes,
                               emxArray_real_T *labels);

/* Function Definitions */
static void b_and(const emlrtStack *sp, emxArray_boolean_T *in1,
                  const emxArray_boolean_T *in2)
{
  emxArray_boolean_T *b_in1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  const boolean_T *in2_data;
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in1, 1, &lf_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, b_in1, i, &lf_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = (in1_data[i * stride_0_0] && in2_data[i * stride_1_0]);
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &lf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_boolean_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static real_T getBoundingBoxes(const emlrtStack *sp, const pointCloud *ptCloud,
                               real_T minDistance, real_T minDetsPerCluster,
                               real_T maxZDistance, real_T minZDistance,
                               real_T Plant_X, real_T Plant_Y, real_T Plant_yaw,
                               emxArray_real_T *bboxes, emxArray_real_T *labels)
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
  emxArray_boolean_T *b_isValidCluster;
  emxArray_boolean_T *isValidCluster;
  emxArray_boolean_T *pedestrianLabels;
  emxArray_int32_T *ii;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *b_bboxes;
  emxArray_real_T *b_ptCloud;
  emxArray_real_T *pedestrianClusters;
  emxArray_uint32_T *b_labels;
  real_T numClusters;
  real_T *b_labels_data;
  real_T *bboxes_data;
  real_T *pedestrianClusters_data;
  int32_T b_i;
  int32_T end;
  int32_T i;
  int32_T idx;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T *ii_data;
  uint32_T currentLabel;
  uint32_T *labels_data;
  boolean_T *isValidCluster_data;
  boolean_T *pedestrianLabels_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  This method fits bounding boxes on each cluster with some basic */
  /*  rules. */
  /*  Cluster must have atleast minDetsPerCluster points. */
  /*  Its mean z must be between maxZDistance and minZDistance. */
  /*  length, width and height are calculated using min and max from each */
  /*  dimension. */
  /*  PCAによる壁面などの形状クラスタを除去====================================
   */
  /*  % クラスタリング */
  /*  [labels,numClusters] = pcsegdist(ptCloud,minDistance); */
  /*  pointData = ptCloud.Location; */
  /*  % 主成分分析で歩行者クラスタを抽出 */
  /*  contributions = zeros(numClusters,3); */
  /*  eig = zeros(numClusters,3); */
  /*  isPedestrian = ones(numClusters,1); */
  /*  for i = 1:numClusters */
  /*      thisPointData = pointData(labels == i,:); */
  /*      [~,~,latent,~,explained,~] = pca(thisPointData); */
  /*      if size(explained,1) == 3 % 寄与率が存在しない場合スキップ */
  /*          contributions(i,:) = explained(1:3)'; */
  /*          eig(i,:) = latent(1:3)'; */
  /*      end */
  /*   */
  /*      if any([any(explained < 0.1);any(latent > 0.6)]) */
  /*          isPedestrian(i) = 0; */
  /*      end */
  /*  end */
  /*  pedestrianClusters = find(isPedestrian == 1); %
   * 主成分の寄与率と固有値から歩行者を判別 */
  /*  % クラスタ数，ラベル共に歩行者クラスタ以外を無効化 */
  /*  pedestrianLabels = ismember(labels, pedestrianClusters);     */
  /*  labels(~pedestrianLabels) = 0; */
  /*  numClusters = length(pedestrianClusters); */
  /*  % ラベル番号の振り直し */
  /*  newLabels = zeros(size(labels)); */
  /*  currentLabel = 1; */
  /*  for i = 1:length(pedestrianClusters) */
  /*      clusterIdx = pedestrianClusters(i); */
  /*      newLabels(labels == clusterIdx) = currentLabel; */
  /*      currentLabel = currentLabel + 1; */
  /*  end */
  /*  labels = newLabels; */
  /* ======================================================================== */
  /*  ここがオリジナル．PCAが無いので疎点群でも取得可能-------------------------
   */
  emxInit_uint32_T(sp, &b_labels, 1, &nd_emlrtRTEI);
  st.site = &tf_emlrtRSI;
  numClusters = pcsegdist(&st, ptCloud, minDistance, b_labels);
  labels_data = b_labels->data;
  /* --------------------------------------------------------------------------
   */
  i = bboxes->size[0] * bboxes->size[1];
  bboxes->size[0] = 3;
  loop_ub = (int32_T)numClusters;
  bboxes->size[1] = (int32_T)numClusters;
  emxEnsureCapacity_real_T(sp, bboxes, i, &dd_emlrtRTEI);
  bboxes_data = bboxes->data;
  loop_ub_tmp = 3 * (int32_T)numClusters;
  for (i = 0; i < loop_ub_tmp; i++) {
    bboxes_data[i] = rtNaN;
  }
  emxInit_boolean_T(sp, &isValidCluster, 2, &ed_emlrtRTEI);
  i = isValidCluster->size[0] * isValidCluster->size[1];
  isValidCluster->size[0] = 1;
  isValidCluster->size[1] = (int32_T)numClusters;
  emxEnsureCapacity_boolean_T(sp, isValidCluster, i, &ed_emlrtRTEI);
  isValidCluster_data = isValidCluster->data;
  for (i = 0; i < loop_ub; i++) {
    isValidCluster_data[i] = false;
  }
  /*  M = mode(labels(:)); */
  emxInit_int32_T(sp, &r, 1, &od_emlrtRTEI);
  emxInit_real_T(sp, &b_ptCloud, 2, &id_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    real_T meanPoint[3];
    end = b_labels->size[0];
    idx = 0;
    for (i = 0; i < end; i++) {
      if (labels_data[i] == (uint32_T)b_i + 1U) {
        idx++;
      }
    }
    i = r->size[0];
    r->size[0] = idx;
    emxEnsureCapacity_int32_T(sp, r, i, &gd_emlrtRTEI);
    ii_data = r->data;
    idx = 0;
    for (i = 0; i < end; i++) {
      if (labels_data[i] == (uint32_T)b_i + 1U) {
        ii_data[idx] = i;
        idx++;
      }
    }
    idx = ptCloud->Location->size[0];
    loop_ub_tmp = r->size[0];
    for (i = 0; i < loop_ub_tmp; i++) {
      if (ii_data[i] > idx - 1) {
        emlrtDynamicBoundsCheckR2012b(ii_data[i], 0, idx - 1, &q_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    i = b_ptCloud->size[0] * b_ptCloud->size[1];
    b_ptCloud->size[0] = r->size[0];
    b_ptCloud->size[1] = 3;
    emxEnsureCapacity_real_T(sp, b_ptCloud, i, &id_emlrtRTEI);
    pedestrianClusters_data = b_ptCloud->data;
    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < loop_ub_tmp; idx++) {
        pedestrianClusters_data[idx + b_ptCloud->size[0] * i] =
            ptCloud->Location
                ->data[ii_data[idx] + ptCloud->Location->size[0] * i];
      }
    }
    st.site = &uf_emlrtRSI;
    mean(&st, b_ptCloud, meanPoint);
    if ((r->size[0] > minDetsPerCluster) && (meanPoint[2] < maxZDistance) &&
        (meanPoint[2] > minZDistance)) {
      real_T a;
      real_T b_r;
      real_T xMax;
      real_T yMax;
      real_T yMin;
      boolean_T exitg1;
      /* && i ~= M */
      st.site = &vf_emlrtRSI;
      b_st.site = &ef_emlrtRSI;
      c_st.site = &ff_emlrtRSI;
      d_st.site = &gf_emlrtRSI;
      if (r->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &w_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      e_st.site = &hf_emlrtRSI;
      f_st.site = &if_emlrtRSI;
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          numClusters = ptCloud->Location->data[ii_data[0]];
        } else {
          numClusters = ptCloud->Location->data[ii_data[0]];
          b_r = ptCloud->Location->data[ii_data[1]];
          if ((numClusters > b_r) ||
              (muDoubleScalarIsNaN(ptCloud->Location->data[ii_data[0]]) &&
               (!muDoubleScalarIsNaN(ptCloud->Location->data[ii_data[1]])))) {
            numClusters = b_r;
          }
        }
      } else {
        g_st.site = &kf_emlrtRSI;
        if (!muDoubleScalarIsNaN(ptCloud->Location->data[ii_data[0]])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &lf_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          i = 2;
          exitg1 = false;
          while ((!exitg1) && (i <= loop_ub_tmp)) {
            if (!muDoubleScalarIsNaN(ptCloud->Location->data[ii_data[i - 1]])) {
              idx = i;
              exitg1 = true;
            } else {
              i++;
            }
          }
        }
        if (idx == 0) {
          numClusters = ptCloud->Location->data[ii_data[0]];
        } else {
          g_st.site = &jf_emlrtRSI;
          numClusters = ptCloud->Location->data[ii_data[idx - 1]];
          end = idx + 1;
          h_st.site = &mf_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (i = end; i <= loop_ub_tmp; i++) {
            b_r = ptCloud->Location->data[ii_data[i - 1]];
            if (numClusters > b_r) {
              numClusters = b_r;
            }
          }
        }
      }
      st.site = &wf_emlrtRSI;
      b_st.site = &nf_emlrtRSI;
      c_st.site = &of_emlrtRSI;
      d_st.site = &pf_emlrtRSI;
      e_st.site = &qf_emlrtRSI;
      f_st.site = &rf_emlrtRSI;
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          xMax = ptCloud->Location->data[ii_data[0]];
        } else {
          xMax = ptCloud->Location->data[ii_data[0]];
          b_r = ptCloud->Location->data[ii_data[1]];
          if ((xMax < b_r) ||
              (muDoubleScalarIsNaN(ptCloud->Location->data[ii_data[0]]) &&
               (!muDoubleScalarIsNaN(ptCloud->Location->data[ii_data[1]])))) {
            xMax = b_r;
          }
        }
      } else {
        g_st.site = &kf_emlrtRSI;
        if (!muDoubleScalarIsNaN(ptCloud->Location->data[ii_data[0]])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &lf_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          i = 2;
          exitg1 = false;
          while ((!exitg1) && (i <= loop_ub_tmp)) {
            if (!muDoubleScalarIsNaN(ptCloud->Location->data[ii_data[i - 1]])) {
              idx = i;
              exitg1 = true;
            } else {
              i++;
            }
          }
        }
        if (idx == 0) {
          xMax = ptCloud->Location->data[ii_data[0]];
        } else {
          g_st.site = &jf_emlrtRSI;
          xMax = ptCloud->Location->data[ii_data[idx - 1]];
          end = idx + 1;
          h_st.site = &mf_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (i = end; i <= loop_ub_tmp; i++) {
            b_r = ptCloud->Location->data[ii_data[i - 1]];
            if (xMax < b_r) {
              xMax = b_r;
            }
          }
        }
      }
      st.site = &xf_emlrtRSI;
      b_st.site = &ef_emlrtRSI;
      c_st.site = &ff_emlrtRSI;
      d_st.site = &gf_emlrtRSI;
      e_st.site = &hf_emlrtRSI;
      f_st.site = &if_emlrtRSI;
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          yMin =
              ptCloud->Location->data[ii_data[0] + ptCloud->Location->size[0]];
        } else {
          yMin =
              ptCloud->Location->data[ii_data[0] + ptCloud->Location->size[0]];
          b_r =
              ptCloud->Location->data[ii_data[1] + ptCloud->Location->size[0]];
          if ((yMin > b_r) ||
              (muDoubleScalarIsNaN(
                   ptCloud->Location
                       ->data[ii_data[0] + ptCloud->Location->size[0]]) &&
               (!muDoubleScalarIsNaN(
                   ptCloud->Location
                       ->data[ii_data[1] + ptCloud->Location->size[0]])))) {
            yMin = b_r;
          }
        }
      } else {
        g_st.site = &kf_emlrtRSI;
        if (!muDoubleScalarIsNaN(
                ptCloud->Location
                    ->data[ii_data[0] + ptCloud->Location->size[0]])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &lf_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          i = 2;
          exitg1 = false;
          while ((!exitg1) && (i <= loop_ub_tmp)) {
            if (!muDoubleScalarIsNaN(
                    ptCloud->Location
                        ->data[ii_data[i - 1] + ptCloud->Location->size[0]])) {
              idx = i;
              exitg1 = true;
            } else {
              i++;
            }
          }
        }
        if (idx == 0) {
          yMin =
              ptCloud->Location->data[ii_data[0] + ptCloud->Location->size[0]];
        } else {
          g_st.site = &jf_emlrtRSI;
          yMin = ptCloud->Location
                     ->data[ii_data[idx - 1] + ptCloud->Location->size[0]];
          end = idx + 1;
          h_st.site = &mf_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (i = end; i <= loop_ub_tmp; i++) {
            b_r = ptCloud->Location
                      ->data[ii_data[i - 1] + ptCloud->Location->size[0]];
            if (yMin > b_r) {
              yMin = b_r;
            }
          }
        }
      }
      st.site = &yf_emlrtRSI;
      b_st.site = &nf_emlrtRSI;
      c_st.site = &of_emlrtRSI;
      d_st.site = &pf_emlrtRSI;
      e_st.site = &qf_emlrtRSI;
      f_st.site = &rf_emlrtRSI;
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          yMax =
              ptCloud->Location->data[ii_data[0] + ptCloud->Location->size[0]];
        } else {
          yMax =
              ptCloud->Location->data[ii_data[0] + ptCloud->Location->size[0]];
          b_r =
              ptCloud->Location->data[ii_data[1] + ptCloud->Location->size[0]];
          if ((yMax < b_r) ||
              (muDoubleScalarIsNaN(
                   ptCloud->Location
                       ->data[ii_data[0] + ptCloud->Location->size[0]]) &&
               (!muDoubleScalarIsNaN(
                   ptCloud->Location
                       ->data[ii_data[1] + ptCloud->Location->size[0]])))) {
            yMax = b_r;
          }
        }
      } else {
        g_st.site = &kf_emlrtRSI;
        if (!muDoubleScalarIsNaN(
                ptCloud->Location
                    ->data[ii_data[0] + ptCloud->Location->size[0]])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &lf_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          i = 2;
          exitg1 = false;
          while ((!exitg1) && (i <= loop_ub_tmp)) {
            if (!muDoubleScalarIsNaN(
                    ptCloud->Location
                        ->data[ii_data[i - 1] + ptCloud->Location->size[0]])) {
              idx = i;
              exitg1 = true;
            } else {
              i++;
            }
          }
        }
        if (idx == 0) {
          yMax =
              ptCloud->Location->data[ii_data[0] + ptCloud->Location->size[0]];
        } else {
          g_st.site = &jf_emlrtRSI;
          yMax = ptCloud->Location
                     ->data[ii_data[idx - 1] + ptCloud->Location->size[0]];
          end = idx + 1;
          h_st.site = &mf_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (i = end; i <= loop_ub_tmp; i++) {
            b_r = ptCloud->Location
                      ->data[ii_data[i - 1] + ptCloud->Location->size[0]];
            if (yMax < b_r) {
              yMax = b_r;
            }
          }
        }
      }
      st.site = &ag_emlrtRSI;
      b_st.site = &ef_emlrtRSI;
      c_st.site = &ff_emlrtRSI;
      d_st.site = &gf_emlrtRSI;
      e_st.site = &hf_emlrtRSI;
      f_st.site = &if_emlrtRSI;
      if (r->size[0] > 2) {
        g_st.site = &kf_emlrtRSI;
        if (!muDoubleScalarIsNaN(
                ptCloud->Location
                    ->data[ii_data[0] + ptCloud->Location->size[0] * 2])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &lf_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          i = 2;
          exitg1 = false;
          while ((!exitg1) && (i <= r->size[0])) {
            if (!muDoubleScalarIsNaN(
                    ptCloud->Location->data[ii_data[i - 1] +
                                            ptCloud->Location->size[0] * 2])) {
              idx = i;
              exitg1 = true;
            } else {
              i++;
            }
          }
        }
        if (idx != 0) {
          g_st.site = &jf_emlrtRSI;
          h_st.site = &mf_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
        }
      }
      st.site = &bg_emlrtRSI;
      b_st.site = &nf_emlrtRSI;
      c_st.site = &of_emlrtRSI;
      d_st.site = &pf_emlrtRSI;
      e_st.site = &qf_emlrtRSI;
      f_st.site = &rf_emlrtRSI;
      if (r->size[0] > 2) {
        g_st.site = &kf_emlrtRSI;
        if (!muDoubleScalarIsNaN(
                ptCloud->Location
                    ->data[ii_data[0] + ptCloud->Location->size[0] * 2])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &lf_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          i = 2;
          exitg1 = false;
          while ((!exitg1) && (i <= r->size[0])) {
            if (!muDoubleScalarIsNaN(
                    ptCloud->Location->data[ii_data[i - 1] +
                                            ptCloud->Location->size[0] * 2])) {
              idx = i;
              exitg1 = true;
            } else {
              i++;
            }
          }
        }
        if (idx != 0) {
          g_st.site = &jf_emlrtRSI;
          h_st.site = &mf_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
        }
      }
      b_r = xMax - numClusters;
      a = yMax - yMin;
      st.site = &cg_emlrtRSI;
      b_st.site = &vh_emlrtRSI;
      c_st.site = &wh_emlrtRSI;
      st.site = &cg_emlrtRSI;
      b_st.site = &vh_emlrtRSI;
      c_st.site = &wh_emlrtRSI;
      b_r = b_r * b_r + a * a;
      st.site = &cg_emlrtRSI;
      if (b_r < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &y_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      b_r = muDoubleScalarSqrt(b_r);
      b_r /= 2.0;
      /*              bboxes(:,i) = [x y z l w h]'; */
      /*              bboxes(:,i) = [x y z]'; */
      a = homogeneous(Plant_X, Plant_Y, Plant_yaw, (numClusters + xMax) / 2.0,
                      (yMin + yMax) / 2.0, &numClusters);
      /*  bboxes(:,i) = [x;y;r]; */
      if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
          ((int32_T)((uint32_T)b_i + 1U) > bboxes->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                      bboxes->size[1], &s_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      bboxes_data[3 * b_i] = a;
      bboxes_data[3 * b_i + 1] = numClusters;
      bboxes_data[3 * b_i + 2] = b_r;
      if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
          ((int32_T)((uint32_T)b_i + 1U) > isValidCluster->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                      isValidCluster->size[1], &n_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      isValidCluster_data[b_i] = (b_r < 0.8);
      /*  max radius of 2 meters % 有効なクラスタを番号を抽出 */
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &b_ptCloud);
  emxFree_int32_T(sp, &r);
  st.site = &dg_emlrtRSI;
  emxInit_boolean_T(&st, &b_isValidCluster, 2, &fd_emlrtRTEI);
  i = b_isValidCluster->size[0] * b_isValidCluster->size[1];
  b_isValidCluster->size[0] = 1;
  loop_ub = isValidCluster->size[1];
  b_isValidCluster->size[1] = isValidCluster->size[1];
  emxEnsureCapacity_boolean_T(&st, b_isValidCluster, i, &fd_emlrtRTEI);
  pedestrianLabels_data = b_isValidCluster->data;
  for (i = 0; i < loop_ub; i++) {
    pedestrianLabels_data[i] = isValidCluster_data[i];
  }
  emxInit_int32_T(&st, &ii, 2, &lc_emlrtRTEI);
  b_st.site = &re_emlrtRSI;
  b_eml_find(&b_st, b_isValidCluster, ii);
  ii_data = ii->data;
  emxFree_boolean_T(&st, &b_isValidCluster);
  emxInit_real_T(&st, &pedestrianClusters, 2, &hd_emlrtRTEI);
  i = pedestrianClusters->size[0] * pedestrianClusters->size[1];
  pedestrianClusters->size[0] = 1;
  loop_ub_tmp = ii->size[1];
  pedestrianClusters->size[1] = ii->size[1];
  emxEnsureCapacity_real_T(&st, pedestrianClusters, i, &hd_emlrtRTEI);
  pedestrianClusters_data = pedestrianClusters->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    pedestrianClusters_data[i] = ii_data[i];
  }
  emxFree_int32_T(&st, &ii);
  /*  クラスタ数，ラベル共に有効クラスタ以外を無効化 */
  st.site = &eg_emlrtRSI;
  emxInit_boolean_T(&st, &pedestrianLabels, 1, &md_emlrtRTEI);
  b_st.site = &vi_emlrtRSI;
  isMember(&b_st, b_labels, pedestrianClusters, pedestrianLabels);
  pedestrianLabels_data = pedestrianLabels->data;
  end = pedestrianLabels->size[0];
  for (b_i = 0; b_i < end; b_i++) {
    if (!pedestrianLabels_data[b_i]) {
      if (b_i > b_labels->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_labels->size[0] - 1,
                                      &p_emlrtBCI, (emlrtConstCTX)sp);
      }
      labels_data[b_i] = 0U;
    }
  }
  emxFree_boolean_T(sp, &pedestrianLabels);
  end = pedestrianClusters->size[1];
  /*  ラベル番号の振り直し */
  idx = b_labels->size[0];
  i = labels->size[0];
  labels->size[0] = b_labels->size[0];
  emxEnsureCapacity_real_T(sp, labels, i, &jd_emlrtRTEI);
  b_labels_data = labels->data;
  for (i = 0; i < idx; i++) {
    b_labels_data[i] = 0.0;
  }
  currentLabel = 1U;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i + 1 > loop_ub_tmp) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, loop_ub_tmp, &r_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    for (i = 0; i < idx; i++) {
      if (labels_data[i] == pedestrianClusters_data[b_i]) {
        if (i > labels->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(i, 0, labels->size[0] - 1, &o_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        b_labels_data[i] = currentLabel;
      }
    }
    currentLabel++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_uint32_T(sp, &b_labels);
  emxFree_real_T(sp, &pedestrianClusters);
  idx = 0;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (isValidCluster_data[b_i]) {
      idx++;
    }
  }
  emxInit_int32_T(sp, &r1, 2, &pd_emlrtRTEI);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = idx;
  emxEnsureCapacity_int32_T(sp, r1, i, &gd_emlrtRTEI);
  ii_data = r1->data;
  idx = 0;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (isValidCluster_data[b_i]) {
      ii_data[idx] = b_i;
      idx++;
    }
  }
  emxFree_boolean_T(sp, &isValidCluster);
  emxInit_real_T(sp, &b_bboxes, 2, &kd_emlrtRTEI);
  i = b_bboxes->size[0] * b_bboxes->size[1];
  b_bboxes->size[0] = 3;
  loop_ub = r1->size[1];
  b_bboxes->size[1] = r1->size[1];
  emxEnsureCapacity_real_T(sp, b_bboxes, i, &kd_emlrtRTEI);
  pedestrianClusters_data = b_bboxes->data;
  for (i = 0; i < loop_ub; i++) {
    if (ii_data[i] > bboxes->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(ii_data[i], 0, bboxes->size[1] - 1,
                                    &t_emlrtBCI, (emlrtConstCTX)sp);
    }
    pedestrianClusters_data[3 * i] = bboxes_data[3 * ii_data[i]];
    if (ii_data[i] > bboxes->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(ii_data[i], 0, bboxes->size[1] - 1,
                                    &t_emlrtBCI, (emlrtConstCTX)sp);
    }
    pedestrianClusters_data[3 * i + 1] = bboxes_data[3 * ii_data[i] + 1];
    if (ii_data[i] > bboxes->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(ii_data[i], 0, bboxes->size[1] - 1,
                                    &t_emlrtBCI, (emlrtConstCTX)sp);
    }
    pedestrianClusters_data[3 * i + 2] = bboxes_data[3 * ii_data[i] + 2];
  }
  emxFree_int32_T(sp, &r1);
  i = bboxes->size[0] * bboxes->size[1];
  bboxes->size[0] = 3;
  bboxes->size[1] = b_bboxes->size[1];
  emxEnsureCapacity_real_T(sp, bboxes, i, &ld_emlrtRTEI);
  bboxes_data = bboxes->data;
  loop_ub_tmp = 3 * b_bboxes->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    bboxes_data[i] = pedestrianClusters_data[i];
  }
  emxFree_real_T(sp, &b_bboxes);
  numClusters = end;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return numClusters;
}

real_T c_HelperBoundingBoxDetector_ste(
    const emlrtStack *sp, const HelperBoundingBoxDetector *obj,
    pointCloud *currentPointCloud, real_T Plant_X, real_T Plant_Y,
    real_T Plant_Z, real_T Plant_yaw, const real_T wall[6],
    emxArray_real_T *detBBoxes, emxArray_real_T *survivedIndices,
    emxArray_real_T *croppedIndices, emxArray_real_T *obstacleIndices,
    emxArray_real_T *groundIndices, emxArray_real_T *labels)
{
  void *kdtreeObj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T *insideX;
  emxArray_boolean_T *insideY;
  emxArray_boolean_T *insideZ;
  emxArray_boolean_T *r;
  emxArray_int32_T *ii;
  emxArray_real_T *a__8;
  emxArray_real_T *loc;
  emxArray_real_T *normals;
  emxArray_real_T *nv;
  emxArray_real_T *queryPoints;
  emxArray_uint32_T *indices;
  emxArray_uint32_T *valid;
  pointCloud lobj_0;
  pointCloud pcSurvived;
  pointCloud ptCloud_obs;
  pointCloud *b_this;
  real_T T[16];
  real_T tform_AffineTform_T[16];
  real_T unusedExpr[16];
  real_T rot[9];
  real_T trans[3];
  real_T d;
  real_T numClusters;
  real_T rot_tmp;
  real_T *loc_data;
  real_T *nv_data;
  real_T *obstacleIndices_data;
  int32_T K;
  int32_T b_n;
  int32_T count;
  int32_T exponent;
  int32_T i;
  int32_T i1;
  int32_T ptIter;
  int32_T zOffset;
  int32_T *ii_data;
  uint32_T *indices_data;
  uint32_T *valid_data;
  boolean_T b;
  boolean_T n;
  boolean_T *insideX_data;
  boolean_T *insideY_data;
  boolean_T *insideZ_data;
  boolean_T *r1;
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
  emxInitStruct_pointCloud(sp, &pcSurvived, &gc_emlrtRTEI);
  emxInitStruct_pointCloud(sp, &ptCloud_obs, &hc_emlrtRTEI);
  emxInit_boolean_T(sp, &insideX, 1, &ic_emlrtRTEI);
  emxInit_boolean_T(sp, &insideY, 1, &jc_emlrtRTEI);
  emxInit_boolean_T(sp, &insideZ, 1, &kc_emlrtRTEI);
  emxInit_boolean_T(sp, &r, 1, &mb_emlrtRTEI);
  emxInit_int32_T(sp, &ii, 1, &lc_emlrtRTEI);
  emxInitStruct_pointCloud(sp, &lobj_0, &mc_emlrtRTEI);
  emxInit_real_T(sp, &loc, 2, &nc_emlrtRTEI);
  emxInit_real_T(sp, &nv, 2, &oc_emlrtRTEI);
  emxInit_real_T(sp, &a__8, 2, &mc_emlrtRTEI);
  emxInit_uint32_T(sp, &indices, 2, &mc_emlrtRTEI);
  emxInit_uint32_T(sp, &valid, 1, &mc_emlrtRTEI);
  emxInit_real_T(sp, &queryPoints, 2, &vb_emlrtRTEI);
  emxInit_real_T(sp, &normals, 2, &pc_emlrtRTEI);
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &pcSurvived,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  pcSurvived.matlabCodegenIsDeleted = true;
  /*  [detBBoxes,survivedIndices,croppedIndices,numClusters,labels] */
  /*  % Use remove ground */
  /*  % Crop point cloud--------------------------------------------- */
  /*  [pcSurvived,survivedIndices,croppedIndices] =
   * cropPointCloud2(currentPointCloud,Plant,wall,axis); */
  /*  %-------------------------------------------------------------- */
  /*  % Remove ground plane------------------------------------------ */
  /*  [pcObstacles,obstacleIndices,groundIndices] =
   * removeGroundPlane(pcSurvived,obj.maxWindowRadius, ... */
  /*      obj.elevationThreshold,obj.elevationScale,survivedIndices,currentPointCloud);
   */
  /*  %-------------------------------------------------------------- */
  /*  % Form clusters and get bounding boxes------------------------- */
  /*  [detBBoxes,numClusters,labels] =
   * getBoundingBoxes(pcObstacles,obj.SegmentationMinDistance, ... */
  /*      obj.MinDetectionsPerCluster,obj.MaxZDistanceCluster,obj.MinZDistanceCluster,Plant,time,SP);
   */
  /*  %-------------------------------------------------------------- */
  /*  Nouse remove ground */
  /*  Crop point cloud--------------------------------------------- */
  /*  [pcSurvived,survivedIndices,croppedIndices] =
   * cropPointCloud(currentPointCloud,obj.XLimits,obj.YLimits,obj.ZLimits,obj.EgoVehicleRadius);
   */
  st.site = &fb_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, &ptCloud_obs,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  ptCloud_obs.matlabCodegenIsDeleted = true;
  /*  function [ptCloudOut,indices,croppedIndices] =
   * cropPointCloud(ptCloudIn,xLim,yLim,zLim,egoVehicleRadius) */
  /*      % This method selects the point cloud within limits and removes the */
  /*      % ego vehicle point cloud using findNeighborsInRadius */
  /*      locations = ptCloudIn.Location; */
  /*      locations = reshape(locations,[],3); */
  /*      insideX = locations(:,1) < xLim(2) & locations(:,1) > xLim(1); */
  /*      insideY = locations(:,2) < yLim(2) & locations(:,2) > yLim(1); */
  /*      insideZ = locations(:,3) < zLim(2) & locations(:,3) > zLim(1); */
  /*      inside = insideX & insideY & insideZ; */
  /*   */
  /*      % Remove ego vehicle */
  /*      nearIndices = findNeighborsInRadius(ptCloudIn,[0 0
   * 0],egoVehicleRadius); */
  /*      nonEgoIndices = true(ptCloudIn.Count,1); */
  /*      nonEgoIndices(nearIndices) = false; */
  /*      validIndices = inside & nonEgoIndices; */
  /*      indices = find(validIndices); */
  /*      croppedIndices = find(~validIndices); */
  /*      ptCloudOut = select(ptCloudIn,indices); */
  /*  end */
  /*  This method selects the point cloud within limits and removes the */
  /*  ego vehicle point cloud using findNeighborsInRadius */
  /*  pcshow(ptCloudIn); */
  numClusters = muDoubleScalarSin(Plant_yaw);
  rot_tmp = muDoubleScalarCos(Plant_yaw);
  rot[0] = rot_tmp;
  rot[3] = numClusters;
  rot[6] = 0.0;
  rot[1] = -numClusters;
  rot[4] = rot_tmp;
  rot[7] = 0.0;
  rot[2] = 0.0;
  rot[5] = 0.0;
  rot[8] = 1.0;
  /*  axis == 3 */
  trans[0] = Plant_X;
  trans[1] = Plant_Y;
  trans[2] = Plant_Z;
  /* [Plant.X Plant.Y 0]; */
  b_st.site = &kb_emlrtRSI;
  c_st.site = &nb_emlrtRSI;
  d_st.site = &pb_emlrtRSI;
  validateRotationMatrix(&d_st, rot);
  d_st.site = &qb_emlrtRSI;
  validateTranslationVector(&d_st, trans);
  for (i = 0; i < 3; i++) {
    zOffset = i << 2;
    T[zOffset] = rot[3 * i];
    T[zOffset + 1] = rot[3 * i + 1];
    T[zOffset + 2] = rot[3 * i + 2];
    T[i + 12] = 0.0;
    T[zOffset + 3] = trans[i];
  }
  T[15] = 1.0;
  d_st.site = &rb_emlrtRSI;
  if (!c_rigid3dImpl_isTransformationM(&d_st, T)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
                                  "images:geotrans:invalidRigidMatrix",
                                  "images:geotrans:invalidRigidMatrix", 0);
  }
  d_st.site = &sb_emlrtRSI;
  affine3d_affine3d(&d_st, T, tform_AffineTform_T);
  c_st.site = &ob_emlrtRSI;
  d_st.site = &pb_emlrtRSI;
  validateRotationMatrix(&d_st, rot);
  d_st.site = &qb_emlrtRSI;
  validateTranslationVector(&d_st, trans);
  for (i = 0; i < 3; i++) {
    zOffset = i << 2;
    T[zOffset] = rot[3 * i];
    T[zOffset + 1] = rot[3 * i + 1];
    T[zOffset + 2] = rot[3 * i + 2];
    T[i + 12] = 0.0;
    T[zOffset + 3] = trans[i];
  }
  T[15] = 1.0;
  d_st.site = &rb_emlrtRSI;
  if (!c_rigid3dImpl_isTransformationM(&d_st, T)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
                                  "images:geotrans:invalidRigidMatrix",
                                  "images:geotrans:invalidRigidMatrix", 0);
  }
  d_st.site = &sb_emlrtRSI;
  affine3d_affine3d(&d_st, T, unusedExpr);
  b_st.site = &lb_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  d_st.site = &ub_emlrtRSI;
  n = (currentPointCloud->PointCloudArrayData->size[0] *
           currentPointCloud->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:pctransform:expectedScalar", 3, 4, 9, "ptCloudIn");
  }
  c_st.site = &vd_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&c_st);
  emlrtPushHeapReferenceStackR2021a(&c_st, true, &lobj_0,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  lobj_0.matlabCodegenIsDeleted = true;
  count = (int32_T)((real_T)(currentPointCloud->Location->size[0] * 3) / 3.0);
  i = loc->size[0] * loc->size[1];
  loc->size[0] = currentPointCloud->Location->size[0];
  loc->size[1] = 3;
  emxEnsureCapacity_real_T(&c_st, loc, i, &jb_emlrtRTEI);
  loc_data = loc->data;
  zOffset = count << 1;
  d_st.site = &xd_emlrtRSI;
  for (ptIter = 0; ptIter < count; ptIter++) {
    i = currentPointCloud->Location->size[0] * 3;
    if (ptIter + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(ptIter + 1, 1, i, &emlrtBCI, &c_st);
    }
    trans[0] = currentPointCloud->Location->data[ptIter];
    i = currentPointCloud->Location->size[0] * 3;
    i1 = (ptIter + count) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &b_emlrtBCI, &c_st);
    }
    trans[1] = currentPointCloud->Location->data[i1 - 1];
    i = currentPointCloud->Location->size[0] * 3;
    b_n = (ptIter + zOffset) + 1;
    if ((b_n < 1) || (b_n > i)) {
      emlrtDynamicBoundsCheckR2012b(b_n, 1, i, &c_emlrtBCI, &c_st);
    }
    trans[2] = currentPointCloud->Location->data[b_n - 1];
    d = trans[0];
    numClusters = trans[1];
    rot_tmp = trans[2];
    for (i = 0; i < 3; i++) {
      K = i << 2;
      trans[i] = (d * tform_AffineTform_T[K] +
                  numClusters * tform_AffineTform_T[K + 1]) +
                 rot_tmp * tform_AffineTform_T[K + 2];
    }
    i = loc->size[0] * 3;
    if (ptIter + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(ptIter + 1, 1, i, &d_emlrtBCI, &c_st);
    }
    loc_data[ptIter] = trans[0] + tform_AffineTform_T[3];
    i = loc->size[0] * 3;
    if (i1 > i) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &e_emlrtBCI, &c_st);
    }
    loc_data[i1 - 1] = trans[1] + tform_AffineTform_T[7];
    i = loc->size[0] * 3;
    if (b_n > i) {
      emlrtDynamicBoundsCheckR2012b(b_n, 1, i, &f_emlrtBCI, &c_st);
    }
    loc_data[b_n - 1] = trans[2] + tform_AffineTform_T[11];
  }
  nv->size[0] = 0;
  nv->size[1] = 0;
  n = (currentPointCloud->Normal->size[0] == 0);
  b = (currentPointCloud->Normal->size[1] == 0);
  if ((!n) && (!b)) {
    real_T ex;
    boolean_T exitg1;
    d_st.site = &yd_emlrtRSI;
    for (i = 0; i < 3; i++) {
      zOffset = i << 2;
      rot[3 * i] = tform_AffineTform_T[zOffset];
      rot[3 * i + 1] = tform_AffineTform_T[zOffset + 1];
      rot[3 * i + 2] = tform_AffineTform_T[zOffset + 2];
    }
    e_st.site = &ee_emlrtRSI;
    svd(&e_st, rot, trans);
    n = !muDoubleScalarIsNaN(trans[0]);
    if (n) {
      zOffset = 1;
    } else {
      zOffset = 0;
      b_n = 2;
      exitg1 = false;
      while ((!exitg1) && (b_n < 4)) {
        if (!muDoubleScalarIsNaN(trans[b_n - 1])) {
          zOffset = b_n;
          exitg1 = true;
        } else {
          b_n++;
        }
      }
    }
    if (zOffset == 0) {
      rot_tmp = trans[0];
    } else {
      rot_tmp = trans[zOffset - 1];
      i = zOffset + 1;
      for (b_n = i; b_n < 4; b_n++) {
        d = trans[b_n - 1];
        if (rot_tmp < d) {
          rot_tmp = d;
        }
      }
    }
    if (n) {
      zOffset = 1;
    } else {
      zOffset = 0;
      b_n = 2;
      exitg1 = false;
      while ((!exitg1) && (b_n < 4)) {
        if (!muDoubleScalarIsNaN(trans[b_n - 1])) {
          zOffset = b_n;
          exitg1 = true;
        } else {
          b_n++;
        }
      }
    }
    if (zOffset == 0) {
      ex = trans[0];
    } else {
      ex = trans[zOffset - 1];
      i = zOffset + 1;
      for (b_n = i; b_n < 4; b_n++) {
        d = trans[b_n - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
    numClusters = muDoubleScalarAbs(rot_tmp);
    if (muDoubleScalarIsInf(numClusters) || muDoubleScalarIsNaN(numClusters)) {
      numClusters = rtNaN;
    } else if (numClusters < 4.4501477170144028E-308) {
      numClusters = 4.94065645841247E-324;
    } else {
      frexp(numClusters, &exponent);
      numClusters = ldexp(1.0, exponent - 53);
    }
    if (rot_tmp - ex < 100.0 * numClusters) {
      e_st.site = &fe_emlrtRSI;
      numClusters = det(&e_st, tform_AffineTform_T) - 1.0;
      if (muDoubleScalarAbs(numClusters) < 2.2204460492503131E-14) {
        n = true;
      } else {
        n = false;
      }
    } else {
      n = false;
    }
    if (n) {
      count = (int32_T)((real_T)(currentPointCloud->Normal->size[0] *
                                 currentPointCloud->Normal->size[1]) /
                        3.0);
      i = nv->size[0] * nv->size[1];
      nv->size[0] = currentPointCloud->Normal->size[0];
      nv->size[1] = currentPointCloud->Normal->size[1];
      emxEnsureCapacity_real_T(&c_st, nv, i, &ob_emlrtRTEI);
      nv_data = nv->data;
      zOffset = count << 1;
      d_st.site = &ae_emlrtRSI;
      for (ptIter = 0; ptIter < count; ptIter++) {
        i = currentPointCloud->Normal->size[0] *
            currentPointCloud->Normal->size[1];
        if (ptIter + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(ptIter + 1, 1, i, &g_emlrtBCI, &c_st);
        }
        trans[0] = currentPointCloud->Normal->data[ptIter];
        i = currentPointCloud->Normal->size[0] *
            currentPointCloud->Normal->size[1];
        i1 = (ptIter + count) + 1;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &h_emlrtBCI, &c_st);
        }
        trans[1] = currentPointCloud->Normal->data[i1 - 1];
        i = currentPointCloud->Normal->size[0] *
            currentPointCloud->Normal->size[1];
        b_n = (ptIter + zOffset) + 1;
        if ((b_n < 1) || (b_n > i)) {
          emlrtDynamicBoundsCheckR2012b(b_n, 1, i, &i_emlrtBCI, &c_st);
        }
        trans[2] = currentPointCloud->Normal->data[b_n - 1];
        d = trans[0];
        numClusters = trans[1];
        rot_tmp = trans[2];
        for (i = 0; i < 3; i++) {
          K = i << 2;
          trans[i] = (d * tform_AffineTform_T[K] +
                      numClusters * tform_AffineTform_T[K + 1]) +
                     rot_tmp * tform_AffineTform_T[K + 2];
        }
        i = nv->size[0] * nv->size[1];
        if (ptIter + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(ptIter + 1, 1, i, &j_emlrtBCI, &c_st);
        }
        nv_data[ptIter] = trans[0];
        i = nv->size[0] * nv->size[1];
        if (i1 > i) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &k_emlrtBCI, &c_st);
        }
        nv_data[i1 - 1] = trans[1];
        i = nv->size[0] * nv->size[1];
        if (b_n > i) {
          emlrtDynamicBoundsCheckR2012b(b_n, 1, i, &l_emlrtBCI, &c_st);
        }
        nv_data[b_n - 1] = trans[2];
      }
    } else {
      d_st.site = &be_emlrtRSI;
      e_st.site = &be_emlrtRSI;
      b_this = pointCloud_pointCloud(&e_st, &lobj_0, loc);
      zOffset = b_this->Location->size[0];
      K = (int32_T)muDoubleScalarMin(6.0, zOffset);
      count = b_this->Location->size[0];
      if (count <= 2) {
        uint32_T unnamed_idx_0;
        unnamed_idx_0 = (uint32_T)b_this->Location->size[0];
        i = nv->size[0] * nv->size[1];
        nv->size[0] = (int32_T)unnamed_idx_0;
        nv->size[1] = 3;
        emxEnsureCapacity_real_T(&d_st, nv, i, &sb_emlrtRTEI);
        nv_data = nv->data;
        zOffset = (int32_T)unnamed_idx_0 * 3;
        for (i = 0; i < zOffset; i++) {
          nv_data[i] = rtNaN;
        }
      } else {
        i = b_this->Location->size[0];
        i1 = nv->size[0] * nv->size[1];
        nv->size[0] = i;
        nv->size[1] = 3;
        emxEnsureCapacity_real_T(&d_st, nv, i1, &rb_emlrtRTEI);
        nv_data = nv->data;
        count = b_this->Location->size[0] * 3;
        for (i1 = 0; i1 < count; i1++) {
          nv_data[i1] = b_this->Location->data[i1];
        }
        e_st.site = &ie_emlrtRSI;
        pointCloud_buildKdtree(&e_st, b_this);
        e_st.site = &je_emlrtRSI;
        kdtreeObj = b_this->Kdtree;
        i1 = queryPoints->size[0] * queryPoints->size[1];
        queryPoints->size[0] = i;
        queryPoints->size[1] = 3;
        emxEnsureCapacity_real_T(&e_st, queryPoints, i1, &vb_emlrtRTEI);
        loc_data = queryPoints->data;
        zOffset = nv->size[0] * 3;
        for (i1 = 0; i1 < zOffset; i1++) {
          loc_data[i1] = nv_data[i1];
        }
        i1 = indices->size[0] * indices->size[1];
        indices->size[0] = K;
        indices->size[1] = i;
        emxEnsureCapacity_uint32_T(&e_st, indices, i1, &wb_emlrtRTEI);
        indices_data = indices->data;
        i1 = a__8->size[0] * a__8->size[1];
        a__8->size[0] = K;
        a__8->size[1] = i;
        emxEnsureCapacity_real_T(&e_st, a__8, i1, &xb_emlrtRTEI);
        obstacleIndices_data = a__8->data;
        i1 = valid->size[0];
        valid->size[0] = i;
        emxEnsureCapacity_uint32_T(&e_st, valid, i1, &yb_emlrtRTEI);
        valid_data = valid->data;
        kdtreeKNNSearch_double(kdtreeObj, &loc_data[0], (uint32_T)nv->size[0],
                               3U, (uint32_T)K, 0.0, &indices_data[0],
                               &obstacleIndices_data[0], &valid_data[0], 2000,
                               500U);
        e_st.site = &ke_emlrtRSI;
        i1 = normals->size[0] * normals->size[1];
        normals->size[0] = i;
        normals->size[1] = 3;
        emxEnsureCapacity_real_T(&e_st, normals, i1, &ac_emlrtRTEI);
        loc_data = normals->data;
        PCANormalImpl_double(&nv_data[0], &indices_data[0], &valid_data[0],
                             (uint32_T)nv->size[0], (uint32_T)indices->size[0],
                             &loc_data[0]);
        i = nv->size[0] * nv->size[1];
        nv->size[0] = normals->size[0];
        nv->size[1] = 3;
        emxEnsureCapacity_real_T(&d_st, nv, i, &cc_emlrtRTEI);
        nv_data = nv->data;
        zOffset = normals->size[0] * 3;
        for (i = 0; i < zOffset; i++) {
          nv_data[i] = loc_data[i];
        }
      }
    }
  }
  d_st.site = &ce_emlrtRSI;
  b_pointCloud_pointCloud(&d_st, &ptCloud_obs, loc, currentPointCloud->Color,
                          nv, currentPointCloud->Intensity);
  d_st.site = &de_emlrtRSI;
  handle_matlabCodegenDestructor(&d_st, &lobj_0);
  emlrtHeapReferenceStackLeaveFcnR2012b(&c_st);
  b_n = ptCloud_obs.Location->size[0];
  i = nv->size[0] * nv->size[1];
  nv->size[0] = b_n;
  nv->size[1] = 3;
  emxEnsureCapacity_real_T(&st, nv, i, &kb_emlrtRTEI);
  nv_data = nv->data;
  count = ptCloud_obs.Location->size[0] * 3;
  for (i = 0; i < count; i++) {
    nv_data[i] = ptCloud_obs.Location->data[i];
  }
  b_st.site = &gb_emlrtRSI;
  zOffset = nv->size[0] * 3;
  c_st.site = &qe_emlrtRSI;
  K = (int32_T)((uint32_T)zOffset / 3U);
  if (K > zOffset) {
    emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (nv->size[0] < 3) {
    b_n = 3;
  }
  if (K > muIntScalarMax_sint32(zOffset, b_n)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (K * 3 != zOffset) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  i = nv->size[0] * nv->size[1];
  nv->size[0] = K;
  nv->size[1] = 3;
  emxEnsureCapacity_real_T(&st, nv, i, &lb_emlrtRTEI);
  nv_data = nv->data;
  i = insideX->size[0];
  insideX->size[0] = K;
  emxEnsureCapacity_boolean_T(&st, insideX, i, &mb_emlrtRTEI);
  insideX_data = insideX->data;
  i = r->size[0];
  r->size[0] = K;
  emxEnsureCapacity_boolean_T(&st, r, i, &nb_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < K; i++) {
    d = nv_data[i];
    insideX_data[i] = (d < wall[3]);
    r1[i] = (d > wall[0]);
  }
  i = insideY->size[0];
  insideY->size[0] = K;
  emxEnsureCapacity_boolean_T(&st, insideY, i, &pb_emlrtRTEI);
  insideY_data = insideY->data;
  for (i = 0; i < K; i++) {
    insideX_data[i] = (insideX_data[i] && r1[i]);
    insideY_data[i] = (nv_data[i + nv->size[0]] < wall[4]);
  }
  i = r->size[0];
  r->size[0] = K;
  emxEnsureCapacity_boolean_T(&st, r, i, &qb_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < K; i++) {
    r1[i] = (nv_data[i + nv->size[0]] > wall[1]);
  }
  i = insideZ->size[0];
  insideZ->size[0] = K;
  emxEnsureCapacity_boolean_T(&st, insideZ, i, &tb_emlrtRTEI);
  insideZ_data = insideZ->data;
  for (i = 0; i < K; i++) {
    insideY_data[i] = (insideY_data[i] && r1[i]);
    insideZ_data[i] = (nv_data[i + nv->size[0] * 2] < wall[5]);
  }
  i = r->size[0];
  r->size[0] = K;
  emxEnsureCapacity_boolean_T(&st, r, i, &ub_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < K; i++) {
    r1[i] = (nv_data[i + nv->size[0] * 2] > wall[2]);
  }
  for (i = 0; i < K; i++) {
    insideZ_data[i] = (insideZ_data[i] && r1[i]);
  }
  if (insideX->size[0] == insideY->size[0]) {
    for (i = 0; i < K; i++) {
      insideX_data[i] = (insideX_data[i] && insideY_data[i]);
    }
  } else {
    b_st.site = &lk_emlrtRSI;
    b_and(&b_st, insideX, insideY);
    insideX_data = insideX->data;
  }
  count = insideX->size[0];
  if ((insideX->size[0] != K) && ((insideX->size[0] != 1) && (K != 1))) {
    emlrtDimSizeImpxCheckR2021b(insideX->size[0], K, &emlrtECI, &st);
  }
  if (insideX->size[0] == insideZ->size[0]) {
    for (i = 0; i < count; i++) {
      insideX_data[i] = (insideX_data[i] && insideZ_data[i]);
    }
  } else {
    b_st.site = &lk_emlrtRSI;
    b_and(&b_st, insideX, insideZ);
    insideX_data = insideX->data;
  }
  /*  Remove ego vehicle */
  /*      nearIndices = findNeighborsInRadius(ptCloudIn,[0 0
   * 0],egoVehicleRadius); */
  /*      nonEgoIndices = true(ptCloudIn.Count,1); */
  /*      nonEgoIndices(nearIndices) = false; */
  /* & nonEgoIndices; */
  b_st.site = &hb_emlrtRSI;
  c_st.site = &re_emlrtRSI;
  eml_find(&c_st, insideX, ii);
  ii_data = ii->data;
  count = ii->size[0];
  i = survivedIndices->size[0];
  survivedIndices->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(&b_st, survivedIndices, i, &bc_emlrtRTEI);
  loc_data = survivedIndices->data;
  for (i = 0; i < count; i++) {
    loc_data[i] = ii_data[i];
  }
  b_st.site = &ib_emlrtRSI;
  zOffset = insideX->size[0];
  for (i = 0; i < zOffset; i++) {
    insideX_data[i] = !insideX_data[i];
  }
  c_st.site = &re_emlrtRSI;
  eml_find(&c_st, insideX, ii);
  ii_data = ii->data;
  zOffset = ii->size[0];
  i = croppedIndices->size[0];
  croppedIndices->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(&b_st, croppedIndices, i, &dc_emlrtRTEI);
  nv_data = croppedIndices->data;
  for (i = 0; i < zOffset; i++) {
    nv_data[i] = ii_data[i];
  }
  b_st.site = &mb_emlrtRSI;
  pointCloud_select(&b_st, currentPointCloud, survivedIndices, &pcSurvived);
  b_st.site = &jb_emlrtRSI;
  handle_matlabCodegenDestructor(&b_st, &ptCloud_obs);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
  i = obstacleIndices->size[0];
  obstacleIndices->size[0] = count;
  emxEnsureCapacity_real_T(sp, obstacleIndices, i, &ec_emlrtRTEI);
  obstacleIndices_data = obstacleIndices->data;
  for (i = 0; i < count; i++) {
    obstacleIndices_data[i] = loc_data[i];
  }
  i = groundIndices->size[0];
  groundIndices->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(sp, groundIndices, i, &fc_emlrtRTEI);
  loc_data = groundIndices->data;
  for (i = 0; i < zOffset; i++) {
    loc_data[i] = nv_data[i];
  }
  /*  removeGroundPlane(pcSurvived,obj.GroundMaxDistance,obj.GroundReferenceVector,obj.GroundMaxAngularDistance,survivedIndices,obj.roi);
   */
  /* -------------------------------------------------------------- */
  /*  Form clusters and get bounding boxes------------------------- */
  st.site = &db_emlrtRSI;
  numClusters = getBoundingBoxes(
      &st, &pcSurvived, obj->SegmentationMinDistance,
      obj->MinDetectionsPerCluster, obj->MaxZDistanceCluster,
      obj->MinZDistanceCluster, Plant_X, Plant_Y, Plant_yaw, detBBoxes, labels);
  /* -------------------------------------------------------------- */
  /*  Assemble detections------------------------------------------ */
  /*  if isempty(obj.MeasurementParameters) */
  /*      measParams = {}; */
  /*  else */
  /*      measParams = obj.MeasurementParameters; */
  /*  end */
  /*  bboxDets =
   * assembleDetections(detBBoxes,obj.MeasurementNoise,measParams,time); */
  /* -------------------------------------------------------------- */
  st.site = &eb_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &pcSurvived);
  emxFree_real_T(sp, &normals);
  emxFree_real_T(sp, &queryPoints);
  emxFree_uint32_T(sp, &valid);
  emxFree_uint32_T(sp, &indices);
  emxFree_real_T(sp, &a__8);
  emxFree_real_T(sp, &nv);
  emxFree_real_T(sp, &loc);
  emxFreeStruct_pointCloud(sp, &lobj_0);
  emxFree_int32_T(sp, &ii);
  emxFree_boolean_T(sp, &r);
  emxFree_boolean_T(sp, &insideZ);
  emxFree_boolean_T(sp, &insideY);
  emxFree_boolean_T(sp, &insideX);
  emxFreeStruct_pointCloud(sp, &ptCloud_obs);
  emxFreeStruct_pointCloud(sp, &pcSurvived);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return numClusters;
}

/* End of code generation (HelperBoundingBoxDetector.c) */
