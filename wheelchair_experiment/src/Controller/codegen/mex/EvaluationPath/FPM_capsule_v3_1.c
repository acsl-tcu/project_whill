/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FPM_capsule_v3_1.c
 *
 * Code generation for function 'FPM_capsule_v3_1'
 *
 */

/* Include files */
#include "FPM_capsule_v3_1.h"
#include "EvaluationPath_data.h"
#include "EvaluationPath_emxutil.h"
#include "EvaluationPath_types.h"
#include "acos.h"
#include "asin.h"
#include "assertCompatibleDims.h"
#include "atan2.h"
#include "cos.h"
#include "dot.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "mtimes.h"
#include "norm.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sign.h"
#include "sin.h"
#include "unsafeSxfun.h"
#include "vecnorm.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kb_emlrtRSI = {
    72,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    73,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    75,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    76,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    79,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    80,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    83,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    87,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    88,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    93,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    94,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    95,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    97,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    98,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    99,                 /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    100,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    101,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    103,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    104,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    105,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    106,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    107,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo hc_emlrtRSI = {
    108,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI = {
    110,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    111,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    115,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    116,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    119,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    122,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    136,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    39,    /* lineNo */
    "cat", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                       */
};

static emlrtRSInfo qc_emlrtRSI = {
    65,         /* lineNo */
    "cat_impl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                       */
};

static emlrtRSInfo xc_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI =
    {
        34,               /* lineNo */
        "rdivide_helper", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "rdivide_helper.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    53,    /* lineNo */
    "div", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/div.m" /* pathName
                                                                       */
};

static emlrtRSInfo md_emlrtRSI = {
    15,    /* lineNo */
    "min", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/min.m" /* pathName
                                                                     */
};

static emlrtRSInfo nd_emlrtRSI = {
    66,         /* lineNo */
    "minOrMax", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo od_emlrtRSI = {
    112,       /* lineNo */
    "minimum", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo pd_emlrtRSI =
    {
        273,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo qd_emlrtRSI =
    {
        962,                    /* lineNo */
        "minRealVectorOmitNaN", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    73,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI = {
    65,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo td_emlrtRSI = {
    114,         /* lineNo */
    "findFirst", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    131,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    225,                   /* lineNo */
    27,                    /* colNo */
    "check_non_axis_size", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/cat.m" /* pName
                                                                       */
};

static emlrtECInfo cb_emlrtECI = {
    -1,                 /* nDims */
    127,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo db_emlrtECI = {
    -1,                 /* nDims */
    122,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo eb_emlrtECI = {
    1,                  /* nDims */
    126,                /* lineNo */
    16,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo fb_emlrtECI = {
    1,                  /* nDims */
    126,                /* lineNo */
    23,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo gb_emlrtECI = {
    1,                  /* nDims */
    121,                /* lineNo */
    16,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo hb_emlrtECI = {
    -1,                 /* nDims */
    117,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo ib_emlrtECI = {
    -1,                 /* nDims */
    111,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo jb_emlrtECI = {
    -1,                 /* nDims */
    114,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo kb_emlrtECI = {
    -1,                 /* nDims */
    92,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo lb_emlrtECI = {
    -1,                 /* nDims */
    116,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo mb_emlrtECI = {
    -1,                 /* nDims */
    110,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo nb_emlrtECI = {
    -1,                 /* nDims */
    115,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo ob_emlrtECI = {
    -1,                 /* nDims */
    108,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo pb_emlrtECI = {
    -1,                 /* nDims */
    106,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo qb_emlrtECI = {
    -1,                 /* nDims */
    107,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo rb_emlrtECI = {
    -1,                 /* nDims */
    105,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo sb_emlrtECI = {
    -1,                 /* nDims */
    108,                /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo tb_emlrtECI = {
    -1,                 /* nDims */
    107,                /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo ub_emlrtECI = {
    -1,                 /* nDims */
    104,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo vb_emlrtECI = {
    -1,                 /* nDims */
    101,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo wb_emlrtECI = {
    -1,                 /* nDims */
    106,                /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo xb_emlrtECI = {
    -1,                 /* nDims */
    105,                /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo yb_emlrtECI = {
    -1,                 /* nDims */
    103,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo ac_emlrtECI = {
    -1,                 /* nDims */
    100,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo bc_emlrtECI = {
    -1,                 /* nDims */
    101,                /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo cc_emlrtECI = {
    -1,                 /* nDims */
    99,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo dc_emlrtECI = {
    -1,                 /* nDims */
    100,                /* lineNo */
    28,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo ec_emlrtECI = {
    -1,                 /* nDims */
    98,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo fc_emlrtECI = {
    -1,                 /* nDims */
    97,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo gc_emlrtECI = {
    -1,                 /* nDims */
    99,                 /* lineNo */
    85,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo hc_emlrtECI = {
    1,                  /* nDims */
    99,                 /* lineNo */
    36,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo ic_emlrtECI = {
    -1,                 /* nDims */
    99,                 /* lineNo */
    36,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo jc_emlrtECI = {
    -1,                 /* nDims */
    95,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo kc_emlrtECI = {
    -1,                 /* nDims */
    98,                 /* lineNo */
    85,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo lc_emlrtECI = {
    1,                  /* nDims */
    98,                 /* lineNo */
    36,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo mc_emlrtECI = {
    -1,                 /* nDims */
    98,                 /* lineNo */
    36,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo nc_emlrtECI = {
    -1,                 /* nDims */
    94,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo oc_emlrtECI = {
    -1,                 /* nDims */
    93,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo pc_emlrtECI = {
    1,                  /* nDims */
    90,                 /* lineNo */
    15,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo qc_emlrtECI = {
    1,                  /* nDims */
    86,                 /* lineNo */
    18,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo rc_emlrtECI = {
    1,                  /* nDims */
    86,                 /* lineNo */
    25,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo sc_emlrtECI = {
    1,                  /* nDims */
    82,                 /* lineNo */
    13,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo tc_emlrtECI = {
    1,                  /* nDims */
    73,                 /* lineNo */
    15,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtECInfo uc_emlrtECI = {
    1,                  /* nDims */
    72,                 /* lineNo */
    15,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtDCInfo p_emlrtDCI = {
    31,                 /* lineNo */
    5,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    1     /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = {
    51,                 /* lineNo */
    23,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    1     /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    92,                 /* lineNo */
    15,                 /* colNo */
    "phi_o",            /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    92,                 /* lineNo */
    34,                 /* colNo */
    "phiQo",            /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    93,                 /* lineNo */
    14,                 /* colNo */
    "PoQo",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    93,                 /* lineNo */
    38,                 /* colNo */
    "Qo",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    94,                 /* lineNo */
    14,                 /* colNo */
    "PoQ1",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    94,                 /* lineNo */
    38,                 /* colNo */
    "Q1",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    95,                 /* lineNo */
    14,                 /* colNo */
    "PoQ2",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    95,                 /* lineNo */
    38,                 /* colNo */
    "Q2",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    97,                 /* lineNo */
    38,                 /* colNo */
    "phiQo",            /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    97,                 /* lineNo */
    49,                 /* colNo */
    "tho",              /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    97,                 /* lineNo */
    14,                 /* colNo */
    "mark",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    98,                 /* lineNo */
    41,                 /* colNo */
    "PoQo",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    98,                 /* lineNo */
    56,                 /* colNo */
    "PoQ1",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    98,                 /* lineNo */
    72,                 /* colNo */
    "a_obs",            /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    98,                 /* lineNo */
    93,                 /* colNo */
    "PoQo",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    98,                 /* lineNo */
    106,                /* colNo */
    "PoQ1",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    98,                 /* lineNo */
    12,                 /* colNo */
    "z1",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    99,                 /* lineNo */
    41,                 /* colNo */
    "PoQo",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    99,                 /* lineNo */
    56,                 /* colNo */
    "PoQ2",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    99,                 /* lineNo */
    72,                 /* colNo */
    "a_obs",            /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    99,                 /* lineNo */
    93,                 /* colNo */
    "PoQo",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    99,                 /* lineNo */
    106,                /* colNo */
    "PoQ2",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    99,                 /* lineNo */
    12,                 /* colNo */
    "z2",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    100,                /* lineNo */
    33,                 /* colNo */
    "mark",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    100,                /* lineNo */
    49,                 /* colNo */
    "z1",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    100,                /* lineNo */
    16,                 /* colNo */
    "phi_Q1",           /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    101,                /* lineNo */
    33,                 /* colNo */
    "mark",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    101,                /* lineNo */
    49,                 /* colNo */
    "z2",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    101,                /* lineNo */
    16,                 /* colNo */
    "phi_Q2",           /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    103,                /* lineNo */
    12,                 /* colNo */
    "z3",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    103,                /* lineNo */
    34,                 /* colNo */
    "D",                /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    103,                /* lineNo */
    49,                 /* colNo */
    "PoQ1",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    104,                /* lineNo */
    12,                 /* colNo */
    "z4",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    104,                /* lineNo */
    34,                 /* colNo */
    "D",                /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    104,                /* lineNo */
    49,                 /* colNo */
    "PoQ2",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    105,                /* lineNo */
    34,                 /* colNo */
    "phi_Q1",           /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    105,                /* lineNo */
    49,                 /* colNo */
    "z3",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    105,                /* lineNo */
    18,                 /* colNo */
    "phi_Q1_l",         /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    106,                /* lineNo */
    34,                 /* colNo */
    "phi_Q1",           /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    106,                /* lineNo */
    49,                 /* colNo */
    "z3",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    106,                /* lineNo */
    18,                 /* colNo */
    "phi_Q1_r",         /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    107,                /* lineNo */
    34,                 /* colNo */
    "phi_Q2",           /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    107,                /* lineNo */
    49,                 /* colNo */
    "z4",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    107,                /* lineNo */
    18,                 /* colNo */
    "phi_Q2_l",         /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    108,                /* lineNo */
    34,                 /* colNo */
    "phi_Q2",           /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    108,                /* lineNo */
    49,                 /* colNo */
    "z4",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    108,                /* lineNo */
    18,                 /* colNo */
    "phi_Q2_r",         /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    110,                /* lineNo */
    17,                 /* colNo */
    "phi_o_l",          /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    110,                /* lineNo */
    41,                 /* colNo */
    "phi_Q1_l",         /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    110,                /* lineNo */
    58,                 /* colNo */
    "phi_Q2_l",         /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    111,                /* lineNo */
    17,                 /* colNo */
    "phi_o_r",          /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    111,                /* lineNo */
    41,                 /* colNo */
    "phi_Q1_r",         /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    111,                /* lineNo */
    58,                 /* colNo */
    "phi_Q2_r",         /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    114,                /* lineNo */
    15,                 /* colNo */
    "phi_o",            /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    114,                /* lineNo */
    35,                 /* colNo */
    "phi_Q3",           /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    115,                /* lineNo */
    12,                 /* colNo */
    "z5",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    115,                /* lineNo */
    38,                 /* colNo */
    "PoQ3",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    115,                /* lineNo */
    49,                 /* colNo */
    "D",                /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    116,                /* lineNo */
    17,                 /* colNo */
    "phi_o_l",          /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    116,                /* lineNo */
    40,                 /* colNo */
    "z5",               /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    117,                /* lineNo */
    17,                 /* colNo */
    "phi_o_r",          /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    117,                /* lineNo */
    36,                 /* colNo */
    "phi_o_l",          /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    122,                /* lineNo */
    43,                 /* colNo */
    "PoQ3",             /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    122,                /* lineNo */
    57,                 /* colNo */
    "b_obs",            /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    122,                /* lineNo */
    19,                 /* colNo */
    "grade_obs",        /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    127,                /* lineNo */
    19,                 /* colNo */
    "grade_obs",        /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    127,                /* lineNo */
    39,                 /* colNo */
    "grade_obs",        /* aName */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    31,                 /* lineNo */
    5,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    51,                 /* lineNo */
    23,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    52,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    53,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    54,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    55,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    56,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    57,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    58,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    59,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    60,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    61,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    62,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    63,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    64,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = {
    65,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    66,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    67,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    68,                 /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    72,                 /* lineNo */
    17,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    72,                 /* lineNo */
    16,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    72,                 /* lineNo */
    26,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    73,                 /* lineNo */
    17,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    73,                 /* lineNo */
    16,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    73,                 /* lineNo */
    26,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = {
    76,                 /* lineNo */
    23,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = {
    76,                 /* lineNo */
    45,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    2,                  /* lineNo */
    63,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = {
    93,                 /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo id_emlrtRTEI = {
    94,                 /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = {
    95,                 /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = {
    97,                 /* lineNo */
    28,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = {
    97,                 /* lineNo */
    23,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo md_emlrtRTEI = {
    98,                 /* lineNo */
    51,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = {
    98,                 /* lineNo */
    85,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo od_emlrtRTEI = {
    98,                 /* lineNo */
    21,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    99,                 /* lineNo */
    51,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    99,                 /* lineNo */
    85,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = {
    100,                /* lineNo */
    41,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo td_emlrtRTEI = {
    101,                /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = {
    103,                /* lineNo */
    21,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = {
    104,                /* lineNo */
    21,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = {
    105,                /* lineNo */
    41,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = {
    106,                /* lineNo */
    41,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    107,                /* lineNo */
    41,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = {
    108,                /* lineNo */
    41,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI =
    {
        550,             /* lineNo */
        21,              /* colNo */
        "unaryMinOrMax", /* fName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = {
    115,                /* lineNo */
    22,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo de_emlrtRTEI = {
    116,                /* lineNo */
    32,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = {
    117,                /* lineNo */
    27,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = {
    119,                /* lineNo */
    23,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = {
    119,                /* lineNo */
    34,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo he_emlrtRTEI = {
    121,                /* lineNo */
    16,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = {
    121,                /* lineNo */
    35,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo je_emlrtRTEI = {
    122,                /* lineNo */
    32,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = {
    126,                /* lineNo */
    16,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo le_emlrtRTEI = {
    127,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo me_emlrtRTEI = {
    121,                /* lineNo */
    9,                  /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = {
    2,                  /* lineNo */
    50,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = {
    2,                  /* lineNo */
    23,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = {
    2,                  /* lineNo */
    31,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = {
    122,                /* lineNo */
    43,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo re_emlrtRTEI = {
    127,                /* lineNo */
    19,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRTEInfo se_emlrtRTEI = {
    76,                 /* lineNo */
    17,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

static emlrtRSInfo ke_emlrtRSI = {
    121,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

static emlrtRSInfo le_emlrtRSI =
    {
        31,            /* lineNo */
        "unsafeSxfun", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unsafeSxfun.m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI = {
    126,                /* lineNo */
    "FPM_capsule_v3_1", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pathName */
};

/* Function Declarations */
static void b_plus(real_T in1_data[], int32_T in1_size[2],
                   const real_T in2_data[], const int32_T in2_size[2]);

static void binary_expand_op_10(real_T in1_data[], int32_T *in1_size,
                                const emxArray_real_T *in2,
                                const real_T in3_data[],
                                const int32_T *in3_size);

static void binary_expand_op_13(real_T in1_data[], int32_T in1_size[2],
                                const real_T in2_data[],
                                const int32_T *in2_size);

static int32_T binary_expand_op_6(boolean_T in1_data[], const real_T in2_data[],
                                  const int32_T *in2_size,
                                  const real_T in3_data[],
                                  const int32_T in3_size[2], real_T in4,
                                  real_T in5);

static void binary_expand_op_7(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3);

static void binary_expand_op_8(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3);

static void c_and(const emlrtStack *sp, emxArray_boolean_T *in1,
                  const emxArray_boolean_T *in2, const boolean_T in3_data[],
                  const int32_T *in3_size);

static void d_and(const emlrtStack *sp, emxArray_boolean_T *in1,
                  const boolean_T in2_data[], const int32_T *in2_size);

static void e_and(const emlrtStack *sp, emxArray_boolean_T *in1,
                  const emxArray_boolean_T *in2);

static int32_T gt(boolean_T in1_data[], const real_T in2_data[],
                  const int32_T *in2_size, const real_T in3_data[],
                  const int32_T *in3_size);

static void minus(real_T in1_data[], int32_T in1_size[2],
                  const real_T in2_data[], const int32_T in2_size[2]);

static void times(real_T in1_data[], int32_T in1_size[2],
                  const real_T in2_data[], const int32_T in2_size[2]);

/* Function Definitions */
static void b_plus(real_T in1_data[], int32_T in1_size[2],
                   const real_T in2_data[], const int32_T in2_size[2])
{
  real_T b_in1_data[60];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in2_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in2_size[0];
  }
  stride_0_0 = (in1_size[0] != 1);
  stride_1_0 = (in2_size[0] != 1);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + loop_ub * i] =
          in1_data[i1 * stride_0_0 + in1_size[0] * i] +
          in2_data[i1 * stride_1_0 + in2_size[0] * i];
    }
  }
  in1_size[0] = loop_ub;
  in1_size[1] = 2;
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = b_in1_data[i1 + loop_ub * i];
    }
  }
}

static void binary_expand_op_10(real_T in1_data[], int32_T *in1_size,
                                const emxArray_real_T *in2,
                                const real_T in3_data[],
                                const int32_T *in3_size)
{
  real_T b_in1_data[30];
  const real_T *in2_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in2_data = in2->data;
  if (*in3_size == 1) {
    loop_ub = *in1_size;
  } else {
    loop_ub = *in3_size;
  }
  stride_0_0 = (*in1_size != 1);
  stride_1_0 = (*in3_size != 1);
  for (i = 0; i < loop_ub; i++) {
    int32_T in1_tmp;
    in1_tmp = i * stride_0_0;
    b_in1_data[i] =
        (in1_data[in1_tmp] + in2_data[in1_tmp]) - in3_data[i * stride_1_0];
  }
  *in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in1_data[0], (uint32_T)loop_ub * sizeof(real_T));
  }
}

static void binary_expand_op_13(real_T in1_data[], int32_T in1_size[2],
                                const real_T in2_data[],
                                const int32_T *in2_size)
{
  real_T b_in2_data[60];
  int32_T i;
  int32_T i1;
  int32_T in2_idx_0;
  int32_T loop_ub;
  int32_T stride_1_0;
  in2_idx_0 = *in2_size;
  if (in1_size[0] == 1) {
    loop_ub = in2_idx_0;
  } else {
    loop_ub = in1_size[0];
  }
  in2_idx_0 = (in2_idx_0 != 1);
  stride_1_0 = (in1_size[0] != 1);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in2_data[i1 + loop_ub * i] =
          in2_data[i1 * in2_idx_0] *
          in1_data[i1 * stride_1_0 + in1_size[0] * i];
    }
  }
  in1_size[0] = loop_ub;
  in1_size[1] = 2;
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = b_in2_data[i1 + loop_ub * i];
    }
  }
}

static int32_T binary_expand_op_6(boolean_T in1_data[], const real_T in2_data[],
                                  const int32_T *in2_size,
                                  const real_T in3_data[],
                                  const int32_T in3_size[2], real_T in4,
                                  real_T in5)
{
  int32_T i;
  int32_T in1_size;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in3_size[0] == 1) {
    in1_size = *in2_size;
  } else {
    in1_size = in3_size[0];
  }
  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (in3_size[0] != 1);
  for (i = 0; i < in1_size; i++) {
    in1_data[i] = (((in2_data[i * stride_0_0] -
                     in3_data[i * stride_1_0 + in3_size[0] * 5]) -
                    in4) -
                       in5 <=
                   0.0);
  }
  return in1_size;
}

static void binary_expand_op_7(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  int32_T i;
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
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ie_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0] + in3_data[i * stride_1_0] < 0.0);
  }
}

static void binary_expand_op_8(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  int32_T i;
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
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &he_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0] + in3_data[i * stride_1_0] >= 0.0);
  }
}

static void c_and(const emlrtStack *sp, emxArray_boolean_T *in1,
                  const emxArray_boolean_T *in2, const boolean_T in3_data[],
                  const int32_T *in3_size)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  const boolean_T *in2_data;
  boolean_T *in1_data;
  in2_data = in2->data;
  if (*in3_size == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = *in3_size;
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ke_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (*in3_size != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0] && in3_data[i * stride_1_0]);
  }
}

static void d_and(const emlrtStack *sp, emxArray_boolean_T *in1,
                  const boolean_T in2_data[], const int32_T *in2_size)
{
  emxArray_boolean_T *b_in1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in1, 1, &he_emlrtRTEI);
  if (*in2_size == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = *in2_size;
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, b_in1, i, &he_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (*in2_size != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = (in1_data[i * stride_0_0] && in2_data[i * stride_1_0]);
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &he_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_boolean_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void e_and(const emlrtStack *sp, emxArray_boolean_T *in1,
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
  emxInit_boolean_T(sp, &b_in1, 1, &he_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, b_in1, i, &he_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = (in1_data[i * stride_0_0] && in2_data[i * stride_1_0]);
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &he_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_boolean_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static int32_T gt(boolean_T in1_data[], const real_T in2_data[],
                  const int32_T *in2_size, const real_T in3_data[],
                  const int32_T *in3_size)
{
  int32_T i;
  int32_T in1_size;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in3_size == 1) {
    in1_size = *in2_size;
  } else {
    in1_size = *in3_size;
  }
  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in3_size != 1);
  for (i = 0; i < in1_size; i++) {
    in1_data[i] = (in2_data[i * stride_0_0] > in3_data[i * stride_1_0]);
  }
  return in1_size;
}

static void minus(real_T in1_data[], int32_T in1_size[2],
                  const real_T in2_data[], const int32_T in2_size[2])
{
  real_T b_in1_data[60];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in2_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in2_size[0];
  }
  stride_0_0 = (in1_size[0] != 1);
  stride_1_0 = (in2_size[0] != 1);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + loop_ub * i] =
          in1_data[i1 * stride_0_0 + in1_size[0] * i] -
          in2_data[i1 * stride_1_0 + in2_size[0] * i];
    }
  }
  in1_size[0] = loop_ub;
  in1_size[1] = 2;
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = b_in1_data[i1 + loop_ub * i];
    }
  }
}

static void times(real_T in1_data[], int32_T in1_size[2],
                  const real_T in2_data[], const int32_T in2_size[2])
{
  real_T b_in1_data[60];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in2_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in2_size[0];
  }
  stride_0_0 = (in1_size[0] != 1);
  stride_1_0 = (in2_size[0] != 1);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + loop_ub * i] =
          in1_data[i1 * stride_0_0 + in1_size[0] * i] *
          in2_data[i1 * stride_1_0 + in2_size[0] * i];
    }
  }
  in1_size[0] = loop_ub;
  in1_size[1] = 2;
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = b_in1_data[i1 + loop_ub * i];
    }
  }
}

real_T FPM_capsule_v3_1(const emlrtStack *sp, real_T obj_ObsNum,
                        real_T obj_wheel_width, real_T obj_wheel_len_front,
                        real_T x, real_T y, real_T th,
                        const real_T obs_now_data[],
                        const int32_T obs_now_size[2], const real_T target[2],
                        real_T param_FPM_eta, real_T param_FPM_alpha,
                        real_T param_FPM_margin, real_T param_FPM_obs_cost,
                        emxArray_real_T *phi_o)
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
  emxArray_boolean_T *idx2;
  emxArray_boolean_T *r12;
  emxArray_boolean_T *r8;
  emxArray_int32_T *r10;
  emxArray_int32_T *r13;
  emxArray_real_T b_tho_data;
  emxArray_real_T c_obs_now_data;
  emxArray_real_T c_tho_data;
  emxArray_real_T d_obs_now_data;
  emxArray_real_T *PoQ1;
  emxArray_real_T *PoQ2;
  emxArray_real_T *PoQo;
  emxArray_real_T *grade_obs;
  emxArray_real_T *mark;
  emxArray_real_T *phi_Q1;
  emxArray_real_T *phi_Q1_l;
  emxArray_real_T *phi_Q1_r;
  emxArray_real_T *phi_Q2;
  emxArray_real_T *phi_Q2_l;
  emxArray_real_T *phi_Q2_r;
  emxArray_real_T *phi_o_l;
  emxArray_real_T *phi_o_r;
  emxArray_real_T *r;
  emxArray_real_T *r2;
  emxArray_real_T *r6;
  emxArray_real_T *z1;
  emxArray_real_T *z2;
  emxArray_real_T *z3;
  emxArray_real_T *z4;
  emxArray_real_T *z5;
  real_T Q1_2_data[60];
  real_T Q1_data[60];
  real_T Q2_2_data[60];
  real_T Q2_data[60];
  real_T y_data[60];
  real_T D_data[30];
  real_T PoQ3_data[30];
  real_T b_obs_now_data[30];
  real_T tho_data[30];
  real_T x_data[30];
  real_T Po[2];
  real_T dv[2];
  real_T dv1[2];
  real_T Grade;
  real_T R_tmp;
  real_T b_R_tmp;
  real_T maxval;
  real_T phig;
  real_T *PoQ1_data;
  real_T *PoQ2_data;
  real_T *PoQo_data;
  real_T *grade_obs_data;
  real_T *mark_data;
  real_T *phi_Q1_data;
  real_T *phi_Q1_l_data;
  real_T *phi_Q1_r_data;
  real_T *phi_Q2_data;
  real_T *phi_Q2_l_data;
  real_T *phi_Q2_r_data;
  real_T *phi_o_data;
  real_T *phi_o_l_data;
  real_T *phi_o_r_data;
  real_T *r1;
  real_T *r3;
  real_T *z1_data;
  real_T *z2_data;
  real_T *z3_data;
  real_T *z4_data;
  real_T *z5_data;
  int32_T Q1_2_size[2];
  int32_T Q1_size[2];
  int32_T Q2_2_size[2];
  int32_T Q2_size[2];
  int32_T b_obs_now_size;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T idx_size;
  int32_T last;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T scalarLB_tmp;
  int32_T tho_size;
  int32_T trueCount;
  int32_T vectorUB_tmp;
  int32_T *r11;
  int8_T b_tmp_data[30];
  int8_T tmp_data[30];
  boolean_T idx_data[30];
  boolean_T *idx2_data;
  boolean_T *r9;
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
  emlrtMEXProfilingFunctionEntry((char_T *)FPM_capsule_v3_1_complete_name,
                                 isMexOutdated);
  /*  function [Grade] = FPM_capsule_v3_1(obj,x,y,th,obs_now,target,param_FPM)
   */
  /*  テスト用 */
  /*  function [Grade,phi_o,phi_Q1,phi_Q2,grade_trgt,grade_obs] =
   * FPM_capsule_v3_1(obj,x,y,th,obs_now,target,param_FPM)  % テスト用 */
  /*  ベクトルで計算 */
  /*  インデックスで計算 */
  /*  「 _2 」がつく変数は車両座標系 */
  /* --パラメータ-------------------------------------- */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  /*  PMF for the goalの最小値と最大値の比率 */
  emlrtMEXProfilingStatement(2, isMexOutdated);
  /*  PMF for the Obstacle の障害物を考慮する距離 */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  /*  PMF for the Obstacle の障害物のマージン */
  emlrtMEXProfilingStatement(4, isMexOutdated);
  /*  障害物に接触する場合のコスト */
  /* ------------------------------------------------- */
  /* --組み込み用-------------------------------------- */
  emlrtMEXProfilingStatement(5, isMexOutdated);
  Po[0] = x;
  Po[1] = y;
  /*  車椅子の位置 */
  emlrtMEXProfilingStatement(6, isMexOutdated);
  /*  車椅子の横幅 */
  emlrtMEXProfilingStatement(7, isMexOutdated);
  /*  車椅子の縦幅 */
  emlrtMEXProfilingStatement(8, isMexOutdated);
  dv[0] = obj_wheel_width;
  dv[1] = obj_wheel_len_front;
  Grade = b_norm(dv);
  /*  車椅子の回転中心から角の距離 */
  /* ----------------------------------------------- */
  emlrtMEXProfilingStatement(9, isMexOutdated);
  /*  歩行者の数 */
  emlrtMEXProfilingStatement(10, isMexOutdated);
  /*  歩行者の位置 */
  emlrtMEXProfilingStatement(11, isMexOutdated);
  /*  歩行者の横幅 */
  emlrtMEXProfilingStatement(12, isMexOutdated);
  /*  歩行者の縦幅 */
  emlrtMEXProfilingStatement(13, isMexOutdated);
  loop_ub = obs_now_size[0];
  tho_size = obs_now_size[0];
  for (i = 0; i < loop_ub; i++) {
    tho_data[i] = obs_now_data[i + obs_now_size[0] * 2];
  }
  /*  歩行者が向いている方向 */
  /* ----------------------------------------------- */
  emlrtMEXProfilingStatement(14, isMexOutdated);
  /*  目標位置 */
  /* ----------------------------------------------- */
  emlrtMEXProfilingStatement(15, isMexOutdated);
  maxval = muDoubleScalarMax(obj_ObsNum, 1.0);
  emxInit_real_T(sp, &grade_obs, 1, &ne_emlrtRTEI);
  i = (int32_T)muDoubleScalarFloor(maxval);
  if (maxval != i) {
    emlrtIntegerCheckR2012b(maxval, &p_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub_tmp = (int32_T)maxval;
  i1 = grade_obs->size[0];
  grade_obs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, grade_obs, i1, &ec_emlrtRTEI);
  grade_obs_data = grade_obs->data;
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(maxval, &p_emlrtDCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    grade_obs_data[i] = 1.0;
  }
  /*  障害物のPFM       */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /* --PMF of Goal (begin)-----------------------------------------------------
   */
  /*  PMF for the goal の最大値 */
  emlrtMEXProfilingStatement(17, isMexOutdated);
  /*  PMF for the goal の最小値 */
  emlrtMEXProfilingStatement(18, isMexOutdated);
  phig = muDoubleScalarAtan2(target[1] - y, target[0] - x) - th;
  /*  車椅子から見たgoal がある方向 */
  emlrtMEXProfilingStatement(19, isMexOutdated);
  emlrtMEXProfilingStatement(20, isMexOutdated);
  /*  PMF of Goal */
  /* --PMF of Goal (end)-------------------------------------------------------
   */
  /* --PFM of Obstacle (begin)-------------------------------------------------
   */
  /*  Po 車両中心 */
  /*  Qo 歩行者中心 */
  /*  Q1 歩行者端円中心1 */
  /*  Q2 歩行者端円中心2 */
  emlrtMEXProfilingStatement(21, isMexOutdated);
  if (obj_ObsNum > 0.0) {
    __m128d r4;
    __m128d r5;
    __m128d r7;
    real_T phi_Q3_data[30];
    real_T R[4];
    int32_T y_size[2];
    int32_T D_size;
    int32_T b_loop_ub_tmp;
    int32_T scalarLB;
    int32_T vectorUB;
    int8_T i2;
    boolean_T p;
    /*  ---事前初期化------------------ */
    emlrtMEXProfilingStatement(22, isMexOutdated);
    i = (int32_T)muDoubleScalarFloor(obj_ObsNum);
    if (obj_ObsNum != i) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &q_emlrtDCI, (emlrtConstCTX)sp);
    }
    b_loop_ub_tmp = (int32_T)obj_ObsNum;
    i1 = phi_o->size[0];
    phi_o->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, phi_o, i1, &fc_emlrtRTEI);
    phi_o_data = phi_o->data;
    if (b_loop_ub_tmp != i) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &q_emlrtDCI, (emlrtConstCTX)sp);
    }
    for (i = 0; i < b_loop_ub_tmp; i++) {
      phi_o_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(23, isMexOutdated);
    emxInit_real_T(sp, &phi_Q1, 1, &gc_emlrtRTEI);
    i = phi_Q1->size[0];
    phi_Q1->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, phi_Q1, i, &gc_emlrtRTEI);
    phi_Q1_data = phi_Q1->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      phi_Q1_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(24, isMexOutdated);
    emxInit_real_T(sp, &phi_Q2, 1, &hc_emlrtRTEI);
    i = phi_Q2->size[0];
    phi_Q2->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, phi_Q2, i, &hc_emlrtRTEI);
    phi_Q2_data = phi_Q2->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      phi_Q2_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(25, isMexOutdated);
    emxInit_real_T(sp, &phi_Q1_l, 1, &ic_emlrtRTEI);
    i = phi_Q1_l->size[0];
    phi_Q1_l->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, phi_Q1_l, i, &ic_emlrtRTEI);
    phi_Q1_l_data = phi_Q1_l->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      phi_Q1_l_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(26, isMexOutdated);
    emxInit_real_T(sp, &phi_Q1_r, 1, &jc_emlrtRTEI);
    i = phi_Q1_r->size[0];
    phi_Q1_r->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, phi_Q1_r, i, &jc_emlrtRTEI);
    phi_Q1_r_data = phi_Q1_r->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      phi_Q1_r_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(27, isMexOutdated);
    emxInit_real_T(sp, &phi_Q2_l, 1, &kc_emlrtRTEI);
    i = phi_Q2_l->size[0];
    phi_Q2_l->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &kc_emlrtRTEI);
    phi_Q2_l_data = phi_Q2_l->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      phi_Q2_l_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(28, isMexOutdated);
    emxInit_real_T(sp, &phi_Q2_r, 1, &lc_emlrtRTEI);
    i = phi_Q2_r->size[0];
    phi_Q2_r->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, phi_Q2_r, i, &lc_emlrtRTEI);
    phi_Q2_r_data = phi_Q2_r->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      phi_Q2_r_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(29, isMexOutdated);
    emxInit_real_T(sp, &phi_o_l, 1, &oe_emlrtRTEI);
    i = phi_o_l->size[0];
    phi_o_l->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, phi_o_l, i, &mc_emlrtRTEI);
    phi_o_l_data = phi_o_l->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      phi_o_l_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(30, isMexOutdated);
    emxInit_real_T(sp, &phi_o_r, 1, &pe_emlrtRTEI);
    i = phi_o_r->size[0];
    phi_o_r->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, phi_o_r, i, &nc_emlrtRTEI);
    phi_o_r_data = phi_o_r->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      phi_o_r_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(31, isMexOutdated);
    emxInit_real_T(sp, &PoQo, 1, &oc_emlrtRTEI);
    i = PoQo->size[0];
    PoQo->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, PoQo, i, &oc_emlrtRTEI);
    PoQo_data = PoQo->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      PoQo_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(32, isMexOutdated);
    emxInit_real_T(sp, &PoQ1, 1, &pc_emlrtRTEI);
    i = PoQ1->size[0];
    PoQ1->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, PoQ1, i, &pc_emlrtRTEI);
    PoQ1_data = PoQ1->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      PoQ1_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(33, isMexOutdated);
    emxInit_real_T(sp, &PoQ2, 1, &qc_emlrtRTEI);
    i = PoQ2->size[0];
    PoQ2->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, PoQ2, i, &qc_emlrtRTEI);
    PoQ2_data = PoQ2->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      PoQ2_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(34, isMexOutdated);
    emxInit_real_T(sp, &z1, 1, &rc_emlrtRTEI);
    i = z1->size[0];
    z1->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, z1, i, &rc_emlrtRTEI);
    z1_data = z1->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      z1_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(35, isMexOutdated);
    emxInit_real_T(sp, &z2, 1, &sc_emlrtRTEI);
    i = z2->size[0];
    z2->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, z2, i, &sc_emlrtRTEI);
    z2_data = z2->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      z2_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(36, isMexOutdated);
    emxInit_real_T(sp, &z3, 1, &tc_emlrtRTEI);
    i = z3->size[0];
    z3->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, z3, i, &tc_emlrtRTEI);
    z3_data = z3->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      z3_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(37, isMexOutdated);
    emxInit_real_T(sp, &z4, 1, &uc_emlrtRTEI);
    i = z4->size[0];
    z4->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, z4, i, &uc_emlrtRTEI);
    z4_data = z4->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      z4_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(38, isMexOutdated);
    emxInit_real_T(sp, &z5, 1, &vc_emlrtRTEI);
    i = z5->size[0];
    z5->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, z5, i, &vc_emlrtRTEI);
    z5_data = z5->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      z5_data[i] = 0.0;
    }
    emlrtMEXProfilingStatement(39, isMexOutdated);
    emxInit_real_T(sp, &mark, 1, &wc_emlrtRTEI);
    i = mark->size[0];
    mark->size[0] = b_loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, mark, i, &wc_emlrtRTEI);
    mark_data = mark->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      mark_data[i] = 0.0;
    }
    /* ------------------------------- */
    emlrtMEXProfilingStatement(40, isMexOutdated);
    D_size = obs_now_size[0];
    scalarLB_tmp = (obs_now_size[0] / 2) << 1;
    vectorUB_tmp = scalarLB_tmp - 2;
    for (i = 0; i <= vectorUB_tmp; i += 2) {
      _mm_storeu_pd(
          &D_data[i],
          _mm_add_pd(
              _mm_add_pd(_mm_set1_pd(obj_wheel_width),
                         _mm_loadu_pd(&obs_now_data[i + obs_now_size[0] * 5])),
              _mm_set1_pd(param_FPM_margin)));
    }
    for (i = scalarLB_tmp; i < loop_ub; i++) {
      D_data[i] = (obj_wheel_width + obs_now_data[i + obs_now_size[0] * 5]) +
                  param_FPM_margin;
    }
    emlrtMEXProfilingStatement(41, isMexOutdated);
    st.site = &kb_emlrtRSI;
    emxInit_real_T(&st, &r, 1, &xc_emlrtRTEI);
    i = r->size[0];
    r->size[0] = obs_now_size[0];
    emxEnsureCapacity_real_T(&st, r, i, &xc_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < loop_ub; i++) {
      r1[i] = tho_data[i];
    }
    b_st.site = &kb_emlrtRSI;
    c_sin(&b_st, r);
    r1 = r->data;
    emxInit_real_T(&st, &r2, 1, &se_emlrtRTEI);
    idx = r->size[0];
    i = r2->size[0];
    r2->size[0] = r->size[0];
    emxEnsureCapacity_real_T(&st, r2, i, &yc_emlrtRTEI);
    r3 = r2->data;
    scalarLB = (r->size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r4 = _mm_loadu_pd(&r1[i]);
      _mm_storeu_pd(&r3[i], _mm_mul_pd(r4, _mm_set1_pd(-1.0)));
    }
    for (i = scalarLB; i < idx; i++) {
      r3[i] = -r1[i];
    }
    i = r->size[0];
    r->size[0] = obs_now_size[0];
    emxEnsureCapacity_real_T(&st, r, i, &ad_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < loop_ub; i++) {
      r1[i] = tho_data[i];
    }
    b_st.site = &kb_emlrtRSI;
    c_cos(&b_st, r);
    r1 = r->data;
    b_st.site = &pc_emlrtRSI;
    c_st.site = &qc_emlrtRSI;
    if (r->size[0] != r2->size[0]) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &i_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
    }
    idx = r2->size[0];
    Q1_size[0] = r2->size[0];
    Q1_size[1] = 2;
    for (i = 0; i < idx; i++) {
      Q1_data[i] = r3[i];
    }
    idx = r->size[0];
    for (i = 0; i < idx; i++) {
      Q1_data[i + Q1_size[0]] = r1[i];
    }
    st.site = &kb_emlrtRSI;
    b_st.site = &pc_emlrtRSI;
    c_st.site = &qc_emlrtRSI;
    Q1_2_size[0] = obs_now_size[0];
    Q1_2_size[1] = 2;
    for (i = 0; i < loop_ub; i++) {
      b_R_tmp = obs_now_data[i + obs_now_size[0] * 4];
      Q1_2_data[i] = b_R_tmp;
      Q1_2_data[i + Q1_2_size[0]] = b_R_tmp;
    }
    if ((r2->size[0] != obs_now_size[0]) &&
        ((r2->size[0] != 1) && (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(r2->size[0], obs_now_size[0], &uc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Q1_size[0] == obs_now_size[0]) {
      last = Q1_size[0] << 1;
      Q1_size[1] = 2;
      scalarLB = (last / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r4 = _mm_loadu_pd(&Q1_data[i]);
        r5 = _mm_loadu_pd(&Q1_2_data[i]);
        _mm_storeu_pd(&Q1_data[i], _mm_mul_pd(r4, r5));
      }
      for (i = scalarLB; i < last; i++) {
        Q1_data[i] *= Q1_2_data[i];
      }
    } else {
      times(Q1_data, Q1_size, Q1_2_data, Q1_2_size);
    }
    if ((Q1_size[0] != obs_now_size[0]) &&
        ((Q1_size[0] != 1) && (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q1_size[0], obs_now_size[0], &uc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Q1_size[0] == obs_now_size[0]) {
      idx = Q1_size[0];
      scalarLB = (Q1_size[0] / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 <= vectorUB; i1 += 2) {
          last = i1 + Q1_size[0] * i;
          r4 = _mm_loadu_pd(&Q1_data[last]);
          _mm_storeu_pd(
              &Q1_data[last],
              _mm_add_pd(
                  r4, _mm_loadu_pd(&obs_now_data[i1 + obs_now_size[0] * i])));
        }
        for (i1 = scalarLB; i1 < idx; i1++) {
          last = i1 + Q1_size[0] * i;
          Q1_data[last] += obs_now_data[i1 + obs_now_size[0] * i];
        }
      }
    } else {
      b_plus(Q1_data, Q1_size, obs_now_data, obs_now_size);
    }
    emlrtMEXProfilingStatement(42, isMexOutdated);
    st.site = &lb_emlrtRSI;
    i = r->size[0];
    r->size[0] = obs_now_size[0];
    emxEnsureCapacity_real_T(&st, r, i, &bd_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < loop_ub; i++) {
      r1[i] = tho_data[i];
    }
    b_st.site = &lb_emlrtRSI;
    c_sin(&b_st, r);
    r1 = r->data;
    idx = r->size[0];
    i = r2->size[0];
    r2->size[0] = r->size[0];
    emxEnsureCapacity_real_T(&st, r2, i, &cd_emlrtRTEI);
    r3 = r2->data;
    scalarLB = (r->size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r4 = _mm_loadu_pd(&r1[i]);
      _mm_storeu_pd(&r3[i], _mm_mul_pd(r4, _mm_set1_pd(-1.0)));
    }
    for (i = scalarLB; i < idx; i++) {
      r3[i] = -r1[i];
    }
    i = r->size[0];
    r->size[0] = obs_now_size[0];
    emxEnsureCapacity_real_T(&st, r, i, &dd_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < loop_ub; i++) {
      r1[i] = tho_data[i];
    }
    b_st.site = &lb_emlrtRSI;
    c_cos(&b_st, r);
    r1 = r->data;
    b_st.site = &pc_emlrtRSI;
    c_st.site = &qc_emlrtRSI;
    if (r->size[0] != r2->size[0]) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &i_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
    }
    idx = r2->size[0];
    Q2_size[0] = r2->size[0];
    Q2_size[1] = 2;
    for (i = 0; i < idx; i++) {
      Q2_data[i] = r3[i];
    }
    idx = r->size[0];
    for (i = 0; i < idx; i++) {
      Q2_data[i + Q2_size[0]] = r1[i];
    }
    st.site = &lb_emlrtRSI;
    b_st.site = &pc_emlrtRSI;
    c_st.site = &qc_emlrtRSI;
    Q1_2_size[1] = 2;
    for (i = 0; i <= vectorUB_tmp; i += 2) {
      r4 = _mm_mul_pd(_mm_loadu_pd(&obs_now_data[i + obs_now_size[0] * 4]),
                      _mm_set1_pd(-1.0));
      _mm_storeu_pd(&Q1_2_data[i], r4);
      _mm_storeu_pd(&Q1_2_data[i + Q1_2_size[0]], r4);
    }
    for (i = scalarLB_tmp; i < loop_ub; i++) {
      b_R_tmp = obs_now_data[i + obs_now_size[0] * 4];
      Q1_2_data[i] = -b_R_tmp;
      Q1_2_data[i + Q1_2_size[0]] = -b_R_tmp;
    }
    if ((r2->size[0] != obs_now_size[0]) &&
        ((r2->size[0] != 1) && (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(r2->size[0], obs_now_size[0], &tc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Q2_size[0] == obs_now_size[0]) {
      last = Q2_size[0] << 1;
      Q2_size[1] = 2;
      scalarLB = (last / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r4 = _mm_loadu_pd(&Q2_data[i]);
        r5 = _mm_loadu_pd(&Q1_2_data[i]);
        _mm_storeu_pd(&Q2_data[i], _mm_mul_pd(r4, r5));
      }
      for (i = scalarLB; i < last; i++) {
        Q2_data[i] *= Q1_2_data[i];
      }
    } else {
      times(Q2_data, Q2_size, Q1_2_data, Q1_2_size);
    }
    if ((Q2_size[0] != obs_now_size[0]) &&
        ((Q2_size[0] != 1) && (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q2_size[0], obs_now_size[0], &tc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Q2_size[0] == obs_now_size[0]) {
      idx = Q2_size[0];
      scalarLB = (Q2_size[0] / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 <= vectorUB; i1 += 2) {
          last = i1 + Q2_size[0] * i;
          r4 = _mm_loadu_pd(&Q2_data[last]);
          _mm_storeu_pd(
              &Q2_data[last],
              _mm_add_pd(
                  r4, _mm_loadu_pd(&obs_now_data[i1 + obs_now_size[0] * i])));
        }
        for (i1 = scalarLB; i1 < idx; i1++) {
          last = i1 + Q2_size[0] * i;
          Q2_data[last] += obs_now_data[i1 + obs_now_size[0] * i];
        }
      }
    } else {
      b_plus(Q2_data, Q2_size, obs_now_data, obs_now_size);
    }
    emlrtMEXProfilingStatement(43, isMexOutdated);
    b_obs_now_size = obs_now_size[0];
    tho_size = obs_now_size[0];
    for (i = 0; i <= vectorUB_tmp; i += 2) {
      _mm_storeu_pd(&b_obs_now_data[i],
                    _mm_sub_pd(_mm_loadu_pd(&obs_now_data[i + obs_now_size[0]]),
                               _mm_set1_pd(y)));
      _mm_storeu_pd(&tho_data[i],
                    _mm_sub_pd(_mm_loadu_pd(&obs_now_data[i]), _mm_set1_pd(x)));
    }
    for (i = scalarLB_tmp; i < loop_ub; i++) {
      b_obs_now_data[i] = obs_now_data[i + obs_now_size[0]] - y;
      tho_data[i] = obs_now_data[i] - x;
    }
    c_obs_now_data.data = &b_obs_now_data[0];
    c_obs_now_data.size = &b_obs_now_size;
    c_obs_now_data.allocatedSize = 30;
    c_obs_now_data.numDimensions = 1;
    c_obs_now_data.canFreeData = false;
    b_tho_data.data = &tho_data[0];
    b_tho_data.size = &tho_size;
    b_tho_data.allocatedSize = 30;
    b_tho_data.numDimensions = 1;
    b_tho_data.canFreeData = false;
    st.site = &mb_emlrtRSI;
    b_atan2(&st, &c_obs_now_data, &b_tho_data, r);
    r1 = r->data;
    loop_ub = r->size[0];
    tho_size = r->size[0];
    for (i = 0; i < loop_ub; i++) {
      tho_data[i] = r1[i];
    }
    emlrtMEXProfilingStatement(44, isMexOutdated);
    i = r->size[0];
    r->size[0] = loop_ub;
    emxEnsureCapacity_real_T(sp, r, i, &ed_emlrtRTEI);
    r1 = r->data;
    scalarLB_tmp = (tho_size / 2) << 1;
    vectorUB_tmp = scalarLB_tmp - 2;
    for (i = 0; i <= vectorUB_tmp; i += 2) {
      r4 = _mm_loadu_pd(&tho_data[i]);
      _mm_storeu_pd(&r1[i], _mm_sub_pd(r4, _mm_set1_pd(th)));
    }
    for (i = scalarLB_tmp; i < loop_ub; i++) {
      r1[i] = tho_data[i] - th;
    }
    st.site = &nb_emlrtRSI;
    c_sin(&st, r);
    emxInit_real_T(sp, &r6, 1, &fd_emlrtRTEI);
    i = r6->size[0];
    r6->size[0] = loop_ub;
    emxEnsureCapacity_real_T(sp, r6, i, &fd_emlrtRTEI);
    r1 = r6->data;
    for (i = 0; i <= vectorUB_tmp; i += 2) {
      r4 = _mm_loadu_pd(&tho_data[i]);
      _mm_storeu_pd(&r1[i], _mm_sub_pd(r4, _mm_set1_pd(th)));
    }
    for (i = scalarLB_tmp; i < loop_ub; i++) {
      r1[i] = tho_data[i] - th;
    }
    st.site = &nb_emlrtRSI;
    c_cos(&st, r6);
    st.site = &nb_emlrtRSI;
    b_atan2(&st, r, r6, r2);
    r3 = r2->data;
    /*  車両から見た歩行者が存在する方向 */
    /*  ---PoとQ1Q2の距離PoQ3とphi_Q3を計算------------------------------ */
    emlrtMEXProfilingStatement(45, isMexOutdated);
    R_tmp = muDoubleScalarSin(-th);
    b_R_tmp = muDoubleScalarCos(-th);
    R[0] = b_R_tmp;
    R[2] = -R_tmp;
    R[1] = R_tmp;
    R[3] = b_R_tmp;
    emlrtMEXProfilingStatement(46, isMexOutdated);
    st.site = &ob_emlrtRSI;
    loop_ub = Q1_size[0];
    Q2_2_size[0] = Q1_size[0];
    Q2_2_size[1] = 2;
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r4 = _mm_loadu_pd(&Q1_data[i1 + Q1_size[0] * i]);
        _mm_storeu_pd(&Q2_2_data[i1 + Q2_2_size[0] * i],
                      _mm_sub_pd(r4, _mm_set1_pd(Po[i])));
      }
      for (i1 = scalarLB; i1 < loop_ub; i1++) {
        Q2_2_data[i1 + Q2_2_size[0] * i] = Q1_data[i1 + Q1_size[0] * i] - Po[i];
      }
    }
    b_st.site = &xc_emlrtRSI;
    mtimes(R, Q2_2_data, Q2_2_size, y_data, y_size);
    loop_ub = y_size[1];
    Q1_2_size[0] = y_size[1];
    Q1_2_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Q1_2_data[i1 + Q1_2_size[0] * i] = y_data[i + 2 * i1];
      }
    }
    /*  車両から見たQ1の位置 */
    emlrtMEXProfilingStatement(47, isMexOutdated);
    st.site = &pb_emlrtRSI;
    idx = Q2_size[0];
    Q2_2_size[0] = Q2_size[0];
    Q2_2_size[1] = 2;
    scalarLB = (idx / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r4 = _mm_loadu_pd(&Q2_data[i1 + Q2_size[0] * i]);
        _mm_storeu_pd(&Q2_2_data[i1 + Q2_2_size[0] * i],
                      _mm_sub_pd(r4, _mm_set1_pd(Po[i])));
      }
      for (i1 = scalarLB; i1 < idx; i1++) {
        Q2_2_data[i1 + Q2_2_size[0] * i] = Q2_data[i1 + Q2_size[0] * i] - Po[i];
      }
    }
    b_st.site = &xc_emlrtRSI;
    mtimes(R, Q2_2_data, Q2_2_size, y_data, y_size);
    idx = y_size[1];
    Q2_2_size[0] = y_size[1];
    Q2_2_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < idx; i1++) {
        Q2_2_data[i1 + Q2_2_size[0] * i] = y_data[i + 2 * i1];
      }
    }
    /*  車両から見たQ2の位置 */
    emlrtMEXProfilingStatement(48, isMexOutdated);
    if ((y_size[1] != loop_ub) && ((y_size[1] != 1) && (loop_ub != 1))) {
      emlrtDimSizeImpxCheckR2021b(y_size[1], loop_ub, &sc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Q1_2_size[0] == y_size[1]) {
      last = y_size[1] << 1;
      Q2_2_size[1] = 2;
      scalarLB = (last / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r4 = _mm_loadu_pd(&Q2_2_data[i]);
        r5 = _mm_loadu_pd(&Q1_2_data[i]);
        _mm_storeu_pd(&Q2_2_data[i], _mm_sub_pd(r4, r5));
      }
      for (i = scalarLB; i < last; i++) {
        Q2_2_data[i] -= Q1_2_data[i];
      }
    } else {
      minus(Q2_2_data, Q2_2_size, Q1_2_data, Q1_2_size);
    }
    /*  ベクトル Q1 → Q2 */
    emlrtMEXProfilingStatement(49, isMexOutdated);
    st.site = &qb_emlrtRSI;
    b_st.site = &qb_emlrtRSI;
    last = dot(&b_st, Q1_2_data, Q1_2_size, Q2_2_data, Q2_2_size, x_data);
    scalarLB_tmp = (last / 2) << 1;
    vectorUB = scalarLB_tmp - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r4 = _mm_loadu_pd(&x_data[i]);
      _mm_storeu_pd(&x_data[i], _mm_mul_pd(r4, _mm_set1_pd(-1.0)));
    }
    for (i = scalarLB_tmp; i < last; i++) {
      x_data[i] = -x_data[i];
    }
    b_st.site = &qb_emlrtRSI;
    tho_size = dot(&b_st, Q2_2_data, Q2_2_size, Q2_2_data, Q2_2_size, tho_data);
    b_st.site = &cd_emlrtRSI;
    c_st.site = &dd_emlrtRSI;
    assertCompatibleDims(&c_st, last, tho_size);
    /*  内積を使って係数 t を計算 */
    emlrtMEXProfilingStatement(50, isMexOutdated);
    if (last == tho_size) {
      tho_size = last;
      scalarLB = last / 2 * 2;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r4 = _mm_loadu_pd(&x_data[i]);
        r5 = _mm_loadu_pd(&tho_data[i]);
        r4 = _mm_div_pd(r4, r5);
        _mm_storeu_pd(&dv1[0], r4);
        dv[0] = muDoubleScalarMin(1.0, dv1[0]);
        dv[1] = muDoubleScalarMin(1.0, dv1[1]);
        dv[0] = muDoubleScalarMax(0.0, dv[0]);
        dv[1] = muDoubleScalarMax(0.0, dv[1]);
        r4 = _mm_loadu_pd(&dv[0]);
        _mm_storeu_pd(&tho_data[i], r4);
      }
      for (i = scalarLB; i < last; i++) {
        R_tmp = x_data[i] / tho_data[i];
        tho_data[i] = muDoubleScalarMax(0.0, muDoubleScalarMin(1.0, R_tmp));
      }
    } else {
      binary_expand_op_14(tho_data, &tho_size, x_data, &last);
    }
    /*  t を 0 ≤ t ≤ 1 に制限 */
    emlrtMEXProfilingStatement(51, isMexOutdated);
    loop_ub = tho_size;
    if ((tho_size != Q2_2_size[0]) &&
        ((tho_size != 1) && (Q2_2_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(tho_size, Q2_2_size[0], &rc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (tho_size == Q2_2_size[0]) {
      last = tho_size;
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 <= vectorUB; i1 += 2) {
          r4 = _mm_loadu_pd(&tho_data[i1]);
          r5 = _mm_loadu_pd(&Q2_2_data[i1 + Q2_2_size[0] * i]);
          _mm_storeu_pd(&y_data[i1 + last * i], _mm_mul_pd(r4, r5));
        }
        for (i1 = scalarLB; i1 < loop_ub; i1++) {
          y_data[i1 + last * i] =
              tho_data[i1] * Q2_2_data[i1 + Q2_2_size[0] * i];
        }
      }
      Q2_2_size[0] = last;
      Q2_2_size[1] = 2;
      last <<= 1;
      if (last - 1 >= 0) {
        memcpy(&Q2_2_data[0], &y_data[0], (uint32_T)last * sizeof(real_T));
      }
    } else {
      binary_expand_op_13(Q2_2_data, Q2_2_size, tho_data, &tho_size);
    }
    if ((Q1_2_size[0] != Q2_2_size[0]) &&
        ((Q1_2_size[0] != 1) && (Q2_2_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q1_2_size[0], Q2_2_size[0], &qc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Q1_2_size[0] == Q2_2_size[0]) {
      last = Q1_2_size[0] << 1;
      Q1_2_size[1] = 2;
      scalarLB = (last / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r4 = _mm_loadu_pd(&Q1_2_data[i]);
        r5 = _mm_loadu_pd(&Q2_2_data[i]);
        _mm_storeu_pd(&Q1_2_data[i], _mm_add_pd(r4, r5));
      }
      for (i = scalarLB; i < last; i++) {
        Q1_2_data[i] += Q2_2_data[i];
      }
    } else {
      b_plus(Q1_2_data, Q1_2_size, Q2_2_data, Q2_2_size);
    }
    /*  交点の座標 */
    emlrtMEXProfilingStatement(52, isMexOutdated);
    st.site = &rb_emlrtRSI;
    scalarLB_tmp = vecnorm(Q1_2_data, Q1_2_size, PoQ3_data);
    /*  原点からの最短距離 */
    emlrtMEXProfilingStatement(53, isMexOutdated);
    loop_ub = Q1_2_size[0];
    tho_size = Q1_2_size[0];
    b_obs_now_size = Q1_2_size[0];
    if (loop_ub - 1 >= 0) {
      memcpy(&b_obs_now_data[0], &Q1_2_data[0],
             (uint32_T)loop_ub * sizeof(real_T));
    }
    for (i = 0; i < loop_ub; i++) {
      tho_data[i] = Q1_2_data[i + Q1_2_size[0]];
    }
    c_tho_data.data = &tho_data[0];
    c_tho_data.size = &tho_size;
    c_tho_data.allocatedSize = 30;
    c_tho_data.numDimensions = 1;
    c_tho_data.canFreeData = false;
    d_obs_now_data.data = &b_obs_now_data[0];
    d_obs_now_data.size = &b_obs_now_size;
    d_obs_now_data.allocatedSize = 30;
    d_obs_now_data.numDimensions = 1;
    d_obs_now_data.canFreeData = false;
    st.site = &sb_emlrtRSI;
    b_atan2(&st, &c_tho_data, &d_obs_now_data, r);
    r1 = r->data;
    loop_ub = r->size[0];
    vectorUB_tmp = r->size[0];
    for (i = 0; i < loop_ub; i++) {
      phi_Q3_data[i] = r1[i];
    }
    /*  車両から見た交点のある方向 */
    /*  ---------------------------------------------------------------- */
    emlrtMEXProfilingStatement(54, isMexOutdated);
    if ((scalarLB_tmp != obs_now_size[0]) &&
        ((scalarLB_tmp != 1) && (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(scalarLB_tmp, obs_now_size[0], &pc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (scalarLB_tmp == obs_now_size[0]) {
      idx_size = scalarLB_tmp;
      for (i = 0; i < scalarLB_tmp; i++) {
        idx_data[i] = (PoQ3_data[i] > D_data[i]);
      }
    } else {
      idx_size =
          gt(idx_data, PoQ3_data, &scalarLB_tmp, D_data, &obs_now_size[0]);
    }
    /*  --- 重なっていない場合-------------------------------------------- */
    emlrtMEXProfilingStatement(55, isMexOutdated);
    trueCount = 0;
    idx = 0;
    for (loop_ub = 0; loop_ub < idx_size; loop_ub++) {
      if (idx_data[loop_ub]) {
        trueCount++;
        tmp_data[idx] = (int8_T)loop_ub;
        idx++;
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > b_loop_ub_tmp - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &m_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > r2->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, r2->size[0] - 1, &n_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &kb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      phi_o_data[i2] = r3[i2];
    }
    emlrtMEXProfilingStatement(56, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &o_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    Q2_2_size[0] = trueCount;
    Q2_2_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < trueCount; i1++) {
        i2 = tmp_data[i1];
        if (i2 > obs_now_size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(i2, 0, obs_now_size[0] - 1, &p_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        Q2_2_data[i1 + trueCount * i] =
            obs_now_data[i2 + obs_now_size[0] * i] - Po[i];
      }
    }
    emxReserve_real_T(sp, r, &hd_emlrtRTEI);
    r1 = r->data;
    st.site = &tb_emlrtRSI;
    (*(int32_T(*)[1])r->size)[0] =
        vecnorm(Q2_2_data, Q2_2_size, (real_T *)r->data);
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r->size[0], 1, &oc_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      PoQo_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(57, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &q_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    Q2_2_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < trueCount; i1++) {
        i2 = tmp_data[i1];
        if (i2 > Q1_size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(i2, 0, Q1_size[0] - 1, &r_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        Q2_2_data[i1 + trueCount * i] = Q1_data[i2 + Q1_size[0] * i] - Po[i];
      }
    }
    emxReserve_real_T(sp, r, &id_emlrtRTEI);
    r1 = r->data;
    st.site = &ub_emlrtRSI;
    (*(int32_T(*)[1])r->size)[0] =
        vecnorm(Q2_2_data, Q2_2_size, (real_T *)r->data);
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r->size[0], 1, &nc_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      PoQ1_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(58, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &s_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    Q2_2_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < trueCount; i1++) {
        i2 = tmp_data[i1];
        if (i2 > Q2_size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(i2, 0, Q2_size[0] - 1, &t_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        Q2_2_data[i1 + trueCount * i] = Q2_data[i2 + Q2_size[0] * i] - Po[i];
      }
    }
    emxReserve_real_T(sp, r, &jd_emlrtRTEI);
    r1 = r->data;
    st.site = &vb_emlrtRSI;
    (*(int32_T(*)[1])r->size)[0] =
        vecnorm(Q2_2_data, Q2_2_size, (real_T *)r->data);
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r->size[0], 1, &jc_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      PoQ2_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(59, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > r2->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, r2->size[0] - 1, &u_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > obs_now_size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, obs_now_size[0] - 1, &v_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &w_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &kd_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      r1[i] = (r3[i2] - obs_now_data[i2 + obs_now_size[0] * 2]) + th;
    }
    st.site = &wb_emlrtRSI;
    c_cos(&st, r);
    emxReserve_real_T(sp, r, &ld_emlrtRTEI);
    r1 = r->data;
    st.site = &wb_emlrtRSI;
    b_sign((real_T *)r->data, &(*(int32_T(*)[1])r->size)[0]);
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r->size[0], 1, &fc_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      mark_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(60, isMexOutdated);
    tho_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQo->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQo->size[0] - 1, &x_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      tho_data[i] = PoQo_data[i2];
    }
    st.site = &xb_emlrtRSI;
    last = power(tho_data, tho_size, x_data);
    b_obs_now_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQ1->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQ1->size[0] - 1, &y_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_obs_now_data[i] = PoQ1_data[i2];
    }
    emxReserve_real_T(sp, r, &md_emlrtRTEI);
    r1 = r->data;
    st.site = &xb_emlrtRSI;
    (*(int32_T(*)[1])r->size)[0] =
        power(b_obs_now_data, b_obs_now_size, (real_T *)r->data);
    if (last != r->size[0]) {
      emlrtSizeEqCheck1DR2012b(last, r->size[0], &mc_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    b_obs_now_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > obs_now_size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, obs_now_size[0] - 1, &ab_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_obs_now_data[i] = obs_now_data[i2 + obs_now_size[0] * 4];
    }
    st.site = &xb_emlrtRSI;
    tho_size = power(b_obs_now_data, b_obs_now_size, tho_data);
    if ((last != tho_size) && ((last != 1) && (tho_size != 1))) {
      emlrtDimSizeImpxCheckR2021b(last, tho_size, &lc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    i = r2->size[0];
    r2->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r2, i, &nd_emlrtRTEI);
    r3 = r2->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQo->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQo->size[0] - 1, &bb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r3[i] = 2.0 * PoQo_data[i2];
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQ1->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQ1->size[0] - 1, &cb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    loop_ub = r2->size[0];
    if (r2->size[0] != trueCount) {
      emlrtSizeEqCheck1DR2012b(r2->size[0], trueCount, &kc_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &db_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    st.site = &xb_emlrtRSI;
    if (last == tho_size) {
      scalarLB = (last / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r4 = _mm_loadu_pd(&x_data[i]);
        r5 = _mm_loadu_pd(&r1[i]);
        r7 = _mm_loadu_pd(&tho_data[i]);
        _mm_storeu_pd(&x_data[i], _mm_sub_pd(_mm_add_pd(r4, r5), r7));
      }
      for (i = scalarLB; i < last; i++) {
        x_data[i] = (x_data[i] + r1[i]) - tho_data[i];
      }
    } else {
      binary_expand_op_10(x_data, &last, r, tho_data, &tho_size);
    }
    tho_size = r2->size[0];
    for (i = 0; i < loop_ub; i++) {
      tho_data[i] = r3[i] * PoQ1_data[tmp_data[i]];
    }
    b_st.site = &cd_emlrtRSI;
    c_st.site = &dd_emlrtRSI;
    assertCompatibleDims(&c_st, last, tho_size);
    if (last == tho_size) {
      i = r->size[0];
      r->size[0] = last;
      emxEnsureCapacity_real_T(sp, r, i, &od_emlrtRTEI);
      r1 = r->data;
      for (i = 0; i < last; i++) {
        R_tmp = x_data[i] / tho_data[i];
        r1[i] = muDoubleScalarMax(-1.0, muDoubleScalarMin(1.0, R_tmp));
      }
    } else {
      st.site = &le_emlrtRSI;
      binary_expand_op_9(&st, r, x_data, &last, tho_data, &tho_size);
      r1 = r->data;
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r->size[0], 1, &ec_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      z1_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(61, isMexOutdated);
    tho_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQo->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQo->size[0] - 1, &eb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      tho_data[i] = PoQo_data[i2];
    }
    st.site = &yb_emlrtRSI;
    last = power(tho_data, tho_size, x_data);
    b_obs_now_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQ2->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQ2->size[0] - 1, &fb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_obs_now_data[i] = PoQ2_data[i2];
    }
    emxReserve_real_T(sp, r, &pd_emlrtRTEI);
    r1 = r->data;
    st.site = &yb_emlrtRSI;
    (*(int32_T(*)[1])r->size)[0] =
        power(b_obs_now_data, b_obs_now_size, (real_T *)r->data);
    if (last != r->size[0]) {
      emlrtSizeEqCheck1DR2012b(last, r->size[0], &ic_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    b_obs_now_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > obs_now_size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, obs_now_size[0] - 1, &gb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_obs_now_data[i] = obs_now_data[i2 + obs_now_size[0] * 4];
    }
    st.site = &yb_emlrtRSI;
    tho_size = power(b_obs_now_data, b_obs_now_size, tho_data);
    if ((last != tho_size) && ((last != 1) && (tho_size != 1))) {
      emlrtDimSizeImpxCheckR2021b(last, tho_size, &hc_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    i = r2->size[0];
    r2->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r2, i, &qd_emlrtRTEI);
    r3 = r2->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQo->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQo->size[0] - 1, &hb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r3[i] = 2.0 * PoQo_data[i2];
    }
    emxFree_real_T(sp, &PoQo);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQ2->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQ2->size[0] - 1, &ib_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    loop_ub = r2->size[0];
    if (r2->size[0] != trueCount) {
      emlrtSizeEqCheck1DR2012b(r2->size[0], trueCount, &gc_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &jb_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    st.site = &yb_emlrtRSI;
    if (last == tho_size) {
      scalarLB = (last / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r4 = _mm_loadu_pd(&x_data[i]);
        r5 = _mm_loadu_pd(&r1[i]);
        r7 = _mm_loadu_pd(&tho_data[i]);
        _mm_storeu_pd(&x_data[i], _mm_sub_pd(_mm_add_pd(r4, r5), r7));
      }
      for (i = scalarLB; i < last; i++) {
        x_data[i] = (x_data[i] + r1[i]) - tho_data[i];
      }
    } else {
      binary_expand_op_10(x_data, &last, r, tho_data, &tho_size);
    }
    tho_size = r2->size[0];
    for (i = 0; i < loop_ub; i++) {
      tho_data[i] = r3[i] * PoQ2_data[tmp_data[i]];
    }
    emxFree_real_T(&st, &r2);
    b_st.site = &cd_emlrtRSI;
    c_st.site = &dd_emlrtRSI;
    assertCompatibleDims(&c_st, last, tho_size);
    if (last == tho_size) {
      i = r->size[0];
      r->size[0] = last;
      emxEnsureCapacity_real_T(sp, r, i, &rd_emlrtRTEI);
      r1 = r->data;
      for (i = 0; i < last; i++) {
        R_tmp = x_data[i] / tho_data[i];
        r1[i] = muDoubleScalarMax(-1.0, muDoubleScalarMin(1.0, R_tmp));
      }
    } else {
      st.site = &le_emlrtRSI;
      binary_expand_op_9(&st, r, x_data, &last, tho_data, &tho_size);
      r1 = r->data;
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r->size[0], 1, &cc_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      z2_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(62, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > mark->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, mark->size[0] - 1, &kb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &sd_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > z1->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, z1->size[0] - 1, &lb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r1[i] = z1_data[i2];
    }
    emxFree_real_T(sp, &z1);
    emxReserve_real_T(sp, r, &sd_emlrtRTEI);
    r1 = r->data;
    st.site = &ac_emlrtRSI;
    b_acos((real_T *)r->data, &(*(int32_T(*)[1])r->size)[0]);
    if (trueCount != r->size[0]) {
      emlrtSizeEqCheck1DR2012b(trueCount, r->size[0], &dc_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &mb_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    tho_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      tho_data[i] = mark_data[tmp_data[i]] * r1[i];
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &tho_size, 1, &ac_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      phi_Q1_data[tmp_data[i]] = tho_data[i];
    }
    emlrtMEXProfilingStatement(63, isMexOutdated);
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &td_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > mark->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, mark->size[0] - 1, &nb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r1[i] = -mark_data[i2];
    }
    emxFree_real_T(sp, &mark);
    tho_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > z2->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, z2->size[0] - 1, &ob_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      tho_data[i] = z2_data[i2];
    }
    emxFree_real_T(sp, &z2);
    st.site = &bc_emlrtRSI;
    b_acos(tho_data, &tho_size);
    loop_ub = r->size[0];
    if (r->size[0] != tho_size) {
      emlrtSizeEqCheck1DR2012b(r->size[0], tho_size, &bc_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &pb_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    emxEnsureCapacity_real_T(sp, r, i, &td_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < loop_ub; i++) {
      r1[i] *= tho_data[i];
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &loop_ub, 1, &vb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      phi_Q2_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(64, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &qb_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    st.site = &cc_emlrtRSI;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > D_size - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, D_size - 1, &rb_emlrtBCI, &st);
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQ1->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQ1->size[0] - 1, &sb_emlrtBCI,
                                      &st);
      }
    }
    b_st.site = &cd_emlrtRSI;
    b_obs_now_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      b_obs_now_data[i] = PoQ1_data[tmp_data[i]];
    }
    c_st.site = &dd_emlrtRSI;
    b_assertCompatibleDims(&c_st, trueCount, b_obs_now_size);
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &ud_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      R_tmp = D_data[i2] / PoQ1_data[i2];
      r1[i] = muDoubleScalarMax(-1.0, muDoubleScalarMin(R_tmp, 1.0));
    }
    emxFree_real_T(sp, &PoQ1);
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &yb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      z3_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(65, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &tb_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    st.site = &dc_emlrtRSI;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > D_size - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, D_size - 1, &ub_emlrtBCI, &st);
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > PoQ2->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, PoQ2->size[0] - 1, &vb_emlrtBCI,
                                      &st);
      }
    }
    b_st.site = &cd_emlrtRSI;
    b_obs_now_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      b_obs_now_data[i] = PoQ2_data[tmp_data[i]];
    }
    c_st.site = &dd_emlrtRSI;
    b_assertCompatibleDims(&c_st, trueCount, b_obs_now_size);
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &vd_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      R_tmp = D_data[i2] / PoQ2_data[i2];
      r1[i] = muDoubleScalarMax(-1.0, muDoubleScalarMin(R_tmp, 1.0));
    }
    emxFree_real_T(sp, &PoQ2);
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &ub_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      z4_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(66, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > phi_Q1->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_Q1->size[0] - 1, &wb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &wd_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > z3->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, z3->size[0] - 1, &xb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r1[i] = z3_data[i2];
    }
    emxReserve_real_T(sp, r, &wd_emlrtRTEI);
    r1 = r->data;
    st.site = &ec_emlrtRSI;
    b_asin((real_T *)r->data, &(*(int32_T(*)[1])r->size)[0]);
    if (trueCount != r->size[0]) {
      emlrtSizeEqCheck1DR2012b(trueCount, r->size[0], &xb_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &yb_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &rb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      phi_Q1_l_data[i2] = phi_Q1_data[i2] + r1[i];
    }
    emlrtMEXProfilingStatement(67, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > phi_Q1->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_Q1->size[0] - 1, &ac_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &xd_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > z3->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, z3->size[0] - 1, &bc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r1[i] = z3_data[i2];
    }
    emxFree_real_T(sp, &z3);
    emxReserve_real_T(sp, r, &xd_emlrtRTEI);
    r1 = r->data;
    st.site = &fc_emlrtRSI;
    b_asin((real_T *)r->data, &(*(int32_T(*)[1])r->size)[0]);
    if (trueCount != r->size[0]) {
      emlrtSizeEqCheck1DR2012b(trueCount, r->size[0], &wb_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &cc_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &pb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      phi_Q1_r_data[i2] = phi_Q1_data[i2] - r1[i];
    }
    emlrtMEXProfilingStatement(68, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > phi_Q2->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_Q2->size[0] - 1, &dc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &yd_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > z4->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, z4->size[0] - 1, &ec_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r1[i] = z4_data[i2];
    }
    emxReserve_real_T(sp, r, &yd_emlrtRTEI);
    r1 = r->data;
    st.site = &gc_emlrtRSI;
    b_asin((real_T *)r->data, &(*(int32_T(*)[1])r->size)[0]);
    if (trueCount != r->size[0]) {
      emlrtSizeEqCheck1DR2012b(trueCount, r->size[0], &tb_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &fc_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &qb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      phi_Q2_l_data[i2] = phi_Q2_data[i2] + r1[i];
    }
    emlrtMEXProfilingStatement(69, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > phi_Q2->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_Q2->size[0] - 1, &gc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &ae_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > z4->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, z4->size[0] - 1, &hc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r1[i] = z4_data[i2];
    }
    emxFree_real_T(sp, &z4);
    emxReserve_real_T(sp, r, &ae_emlrtRTEI);
    r1 = r->data;
    st.site = &hc_emlrtRSI;
    b_asin((real_T *)r->data, &(*(int32_T(*)[1])r->size)[0]);
    if (trueCount != r->size[0]) {
      emlrtSizeEqCheck1DR2012b(trueCount, r->size[0], &sb_emlrtECI,
                               (emlrtConstCTX)sp);
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &ic_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &ob_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      phi_Q2_r_data[i2] = phi_Q2_data[i2] - r1[i];
    }
    emxFree_real_T(sp, &phi_Q2);
    emlrtMEXProfilingStatement(70, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &jc_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    st.site = &ic_emlrtRSI;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > phi_Q1_l->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_Q1_l->size[0] - 1,
                                      &kc_emlrtBCI, &st);
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > phi_Q2_l->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_Q2_l->size[0] - 1,
                                      &lc_emlrtBCI, &st);
      }
    }
    b_st.site = &pc_emlrtRSI;
    c_st.site = &qc_emlrtRSI;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      Q1_2_data[i] = phi_Q1_l_data[i2];
      Q1_2_data[i + trueCount] = phi_Q2_l_data[i2];
    }
    emxFree_real_T(&b_st, &phi_Q2_l);
    emxFree_real_T(&b_st, &phi_Q1_l);
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &be_emlrtRTEI);
    r1 = r->data;
    if (trueCount >= 1) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        r1[loop_ub] = Q1_2_data[loop_ub];
      }
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        R_tmp = Q1_2_data[loop_ub + trueCount];
        if (muDoubleScalarIsNaN(R_tmp)) {
          p = false;
        } else if (muDoubleScalarIsNaN(r1[loop_ub])) {
          p = true;
        } else {
          p = (r1[loop_ub] < R_tmp);
        }
        if (p) {
          r1[loop_ub] = R_tmp;
        }
      }
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &mb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      phi_o_l_data[tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(71, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &mc_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    st.site = &jc_emlrtRSI;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > phi_Q1_r->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_Q1_r->size[0] - 1,
                                      &nc_emlrtBCI, &st);
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      if (i2 > phi_Q2_r->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_Q2_r->size[0] - 1,
                                      &oc_emlrtBCI, &st);
      }
    }
    b_st.site = &pc_emlrtRSI;
    c_st.site = &qc_emlrtRSI;
    for (i = 0; i < trueCount; i++) {
      i2 = tmp_data[i];
      Q1_2_data[i] = phi_Q1_r_data[i2];
      Q1_2_data[i + trueCount] = phi_Q2_r_data[i2];
    }
    emxFree_real_T(&b_st, &phi_Q2_r);
    emxFree_real_T(&b_st, &phi_Q1_r);
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &be_emlrtRTEI);
    r1 = r->data;
    if (trueCount >= 1) {
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        r1[loop_ub] = Q1_2_data[loop_ub];
      }
      for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
        R_tmp = Q1_2_data[loop_ub + trueCount];
        if (muDoubleScalarIsNaN(R_tmp)) {
          p = false;
        } else if (muDoubleScalarIsNaN(r1[loop_ub])) {
          p = true;
        } else {
          p = (r1[loop_ub] > R_tmp);
        }
        if (p) {
          r1[loop_ub] = R_tmp;
        }
      }
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &ib_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      phi_o_r_data[tmp_data[i]] = r1[i];
    }
    /*  ----------------------------------------------------------------- */
    /*  ---重なっている場合------------------------------------------------ */
    emlrtMEXProfilingStatement(72, isMexOutdated);
    trueCount = 0;
    idx = 0;
    for (loop_ub = 0; loop_ub < idx_size; loop_ub++) {
      if (!idx_data[loop_ub]) {
        trueCount++;
        b_tmp_data[idx] = (int8_T)loop_ub;
        idx++;
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      if (i2 > phi_o->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_o->size[0] - 1, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      if (i2 > vectorUB_tmp - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, vectorUB_tmp - 1, &qc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &jb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      phi_o_data[i2] = phi_Q3_data[i2];
    }
    emlrtMEXProfilingStatement(73, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      if (i2 > (int32_T)obj_ObsNum - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, (int32_T)obj_ObsNum - 1,
                                      &rc_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    st.site = &kc_emlrtRSI;
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      if (i2 > scalarLB_tmp - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, scalarLB_tmp - 1, &sc_emlrtBCI,
                                      &st);
      }
    }
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      if (i2 > D_size - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, D_size - 1, &tc_emlrtBCI, &st);
      }
    }
    b_st.site = &cd_emlrtRSI;
    tho_size = trueCount;
    for (i = 0; i < trueCount; i++) {
      tho_data[i] = PoQ3_data[b_tmp_data[i]];
    }
    c_st.site = &dd_emlrtRSI;
    b_assertCompatibleDims(&c_st, tho_size, trueCount);
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &ce_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      r1[i] = muDoubleScalarMax(
          -1.0, muDoubleScalarMin(PoQ3_data[i2] / D_data[i2], 1.0));
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &trueCount, 1, &nb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      z5_data[b_tmp_data[i]] = r1[i];
    }
    emlrtMEXProfilingStatement(74, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      if (i2 > phi_o_l->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_o_l->size[0] - 1, &uc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &de_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      if (i2 > z5->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, z5->size[0] - 1, &vc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r1[i] = z5_data[i2];
    }
    emxFree_real_T(sp, &z5);
    emxReserve_real_T(sp, r, &de_emlrtRTEI);
    r1 = r->data;
    st.site = &lc_emlrtRSI;
    b_asin((real_T *)r->data, &(*(int32_T(*)[1])r->size)[0]);
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r->size[0], 1, &lb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      phi_o_l_data[b_tmp_data[i]] = 3.1415926535897931 - r1[i];
    }
    emlrtMEXProfilingStatement(75, isMexOutdated);
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      if (i2 > phi_o_r->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_o_r->size[0] - 1, &wc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_real_T(sp, r, i, &ee_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < trueCount; i++) {
      i2 = b_tmp_data[i];
      if (i2 > phi_o_l->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, phi_o_l->size[0] - 1, &xc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r1[i] = -phi_o_l_data[i2];
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r->size[0], 1, &hb_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < trueCount; i++) {
      phi_o_r_data[b_tmp_data[i]] = r1[i];
    }
    /*  ----------------------------------------------------------------- */
    emlrtMEXProfilingStatement(76, isMexOutdated);
    loop_ub = phi_o->size[0];
    i = r->size[0];
    r->size[0] = phi_o->size[0];
    emxEnsureCapacity_real_T(sp, r, i, &fe_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < loop_ub; i++) {
      r1[i] = phi_o_data[i];
    }
    st.site = &mc_emlrtRSI;
    c_sin(&st, r);
    i = r6->size[0];
    r6->size[0] = phi_o->size[0];
    emxEnsureCapacity_real_T(sp, r6, i, &ge_emlrtRTEI);
    r1 = r6->data;
    for (i = 0; i < loop_ub; i++) {
      r1[i] = phi_o_data[i];
    }
    st.site = &mc_emlrtRSI;
    c_cos(&st, r6);
    st.site = &mc_emlrtRSI;
    b_atan2(&st, r, r6, phi_o);
    phi_o_data = phi_o->data;
    emxFree_real_T(sp, &r6);
    /*  ---障害物のある方向のPMFを下げる------------------------------------ */
    emlrtMEXProfilingStatement(77, isMexOutdated);
    loop_ub = phi_o->size[0];
    if ((phi_o->size[0] != b_loop_ub_tmp) &&
        ((phi_o->size[0] != 1) && (obj_ObsNum != 1.0))) {
      emlrtDimSizeImpxCheckR2021b(phi_o->size[0], (int32_T)obj_ObsNum,
                                  &gb_emlrtECI, (emlrtConstCTX)sp);
    }
    emxInit_boolean_T(sp, &idx2, 1, &me_emlrtRTEI);
    if (phi_o->size[0] == phi_o_l->size[0]) {
      i = idx2->size[0];
      idx2->size[0] = phi_o->size[0];
      emxEnsureCapacity_boolean_T(sp, idx2, i, &he_emlrtRTEI);
      idx2_data = idx2->data;
      for (i = 0; i < loop_ub; i++) {
        idx2_data[i] = (phi_o_data[i] + phi_o_l_data[i] >= 0.0);
      }
    } else {
      st.site = &ke_emlrtRSI;
      binary_expand_op_8(&st, idx2, phi_o, phi_o_l);
      idx2_data = idx2->data;
    }
    emxFree_real_T(sp, &phi_o_l);
    emxInit_boolean_T(sp, &r8, 1, &he_emlrtRTEI);
    if (phi_o->size[0] == phi_o_r->size[0]) {
      loop_ub = phi_o->size[0];
      i = r8->size[0];
      r8->size[0] = phi_o->size[0];
      emxEnsureCapacity_boolean_T(sp, r8, i, &ie_emlrtRTEI);
      r9 = r8->data;
      for (i = 0; i < loop_ub; i++) {
        r9[i] = (phi_o_data[i] + phi_o_r_data[i] < 0.0);
      }
    } else {
      st.site = &ke_emlrtRSI;
      binary_expand_op_7(&st, r8, phi_o, phi_o_r);
      r9 = r8->data;
    }
    emxFree_real_T(sp, &phi_o_r);
    loop_ub = idx2->size[0];
    if ((idx2->size[0] != r8->size[0]) &&
        ((idx2->size[0] != 1) && (r8->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx2->size[0], r8->size[0], &gb_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (idx2->size[0] == r8->size[0]) {
      for (i = 0; i < loop_ub; i++) {
        idx2_data[i] = (idx2_data[i] && r9[i]);
      }
    } else {
      st.site = &ke_emlrtRSI;
      e_and(&st, idx2, r8);
      idx2_data = idx2->data;
    }
    emxFree_boolean_T(sp, &r8);
    for (i = 0; i < scalarLB_tmp; i++) {
      idx_data[i] = (PoQ3_data[i] < param_FPM_alpha);
    }
    loop_ub = idx2->size[0];
    if ((idx2->size[0] != scalarLB_tmp) &&
        ((idx2->size[0] != 1) && (scalarLB_tmp != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx2->size[0], scalarLB_tmp, &gb_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (idx2->size[0] == scalarLB_tmp) {
      for (i = 0; i < loop_ub; i++) {
        idx2_data[i] = (idx2_data[i] && idx_data[i]);
      }
    } else {
      st.site = &ke_emlrtRSI;
      d_and(&st, idx2, idx_data, &scalarLB_tmp);
      idx2_data = idx2->data;
    }
    emlrtMEXProfilingStatement(78, isMexOutdated);
    last = idx2->size[0];
    trueCount = 0;
    for (loop_ub = 0; loop_ub < last; loop_ub++) {
      if (idx2_data[loop_ub]) {
        trueCount++;
      }
    }
    emxInit_int32_T(sp, &r10, &qe_emlrtRTEI);
    i = r10->size[0];
    r10->size[0] = trueCount;
    emxEnsureCapacity_int32_T(sp, r10, i, &gd_emlrtRTEI);
    r11 = r10->data;
    idx = 0;
    for (loop_ub = 0; loop_ub < last; loop_ub++) {
      if (idx2_data[loop_ub]) {
        r11[idx] = loop_ub;
        idx++;
      }
    }
    b_loop_ub_tmp = r10->size[0];
    for (i = 0; i < b_loop_ub_tmp; i++) {
      if (r11[i] > scalarLB_tmp - 1) {
        emlrtDynamicBoundsCheckR2012b(r11[i], 0, scalarLB_tmp - 1, &yc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < b_loop_ub_tmp; i++) {
      if (r11[i] > obs_now_size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(r11[i], 0, obs_now_size[0] - 1,
                                      &ad_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < b_loop_ub_tmp; i++) {
      if (r11[i] > loop_ub_tmp - 1) {
        emlrtDynamicBoundsCheckR2012b(r11[i], 0, (int32_T)maxval - 1,
                                      &bd_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    i = r->size[0];
    r->size[0] = r10->size[0];
    emxEnsureCapacity_real_T(sp, r, i, &je_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      r1[i] =
          -((PoQ3_data[r11[i]] - obs_now_data[r11[i] + obs_now_size[0] * 5]) -
            Grade);
    }
    st.site = &nc_emlrtRSI;
    b_exp(&st, r);
    r1 = r->data;
    emlrtSubAssignSizeCheckR2012b(&r10->size[0], 1, &r->size[0], 1,
                                  &db_emlrtECI, (emlrtCTX)sp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      grade_obs_data[r11[i]] = 1.0 - r1[i];
    }
    emxFree_real_T(sp, &r);
    emxFree_int32_T(sp, &r10);
    /*  grade_obs(idx2,1) = 1-(alpha-PoQ3(idx2,1))./(alpha-(b_obs(idx2,1) + ds +
     * r_wheel)); */
    /*  ----------------------------------------------------------------- */
    /*  ---障害物のコストを計算-------------------------------------------- */
    emlrtMEXProfilingStatement(79, isMexOutdated);
    if ((scalarLB_tmp != obs_now_size[0]) &&
        ((scalarLB_tmp != 1) && (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(scalarLB_tmp, obs_now_size[0], &fb_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (scalarLB_tmp == obs_now_size[0]) {
      idx_size = scalarLB_tmp;
      for (i = 0; i < scalarLB_tmp; i++) {
        idx_data[i] = (((PoQ3_data[i] - obs_now_data[i + obs_now_size[0] * 5]) -
                        param_FPM_margin) -
                           Grade <=
                       0.0);
      }
    } else {
      idx_size =
          binary_expand_op_6(idx_data, PoQ3_data, &scalarLB_tmp, obs_now_data,
                             obs_now_size, param_FPM_margin, Grade);
    }
    if ((idx2->size[0] != idx_size) &&
        ((idx2->size[0] != 1) && (idx_size != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx2->size[0], idx_size, &eb_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    emlrtMEXProfilingStatement(80, isMexOutdated);
    emxInit_boolean_T(sp, &r12, 1, &ke_emlrtRTEI);
    if (idx2->size[0] == idx_size) {
      i = r12->size[0];
      r12->size[0] = idx2->size[0];
      emxEnsureCapacity_boolean_T(sp, r12, i, &ke_emlrtRTEI);
      r9 = r12->data;
      for (i = 0; i < last; i++) {
        r9[i] = (idx2_data[i] && idx_data[i]);
      }
    } else {
      st.site = &me_emlrtRSI;
      c_and(&st, r12, idx2, idx_data, &idx_size);
      r9 = r12->data;
    }
    emxFree_boolean_T(sp, &idx2);
    last = r12->size[0];
    trueCount = 0;
    for (loop_ub = 0; loop_ub < last; loop_ub++) {
      if (r9[loop_ub]) {
        trueCount++;
      }
    }
    emxInit_int32_T(sp, &r13, &re_emlrtRTEI);
    i = r13->size[0];
    r13->size[0] = trueCount;
    emxEnsureCapacity_int32_T(sp, r13, i, &gd_emlrtRTEI);
    r11 = r13->data;
    idx = 0;
    for (loop_ub = 0; loop_ub < last; loop_ub++) {
      if (r9[loop_ub]) {
        r11[idx] = loop_ub;
        idx++;
      }
    }
    emxFree_boolean_T(sp, &r12);
    loop_ub_tmp = r13->size[0];
    for (i = 0; i < loop_ub_tmp; i++) {
      if (r11[i] > grade_obs->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(r11[i], 0, grade_obs->size[0] - 1,
                                      &cd_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < loop_ub_tmp; i++) {
      if (r11[i] > grade_obs->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(r11[i], 0, grade_obs->size[0] - 1,
                                      &dd_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    emlrtSubAssignSizeCheckR2012b(&r13->size[0], 1, &r13->size[0], 1,
                                  &cb_emlrtECI, (emlrtCTX)sp);
    i = phi_Q1->size[0];
    phi_Q1->size[0] = r13->size[0];
    emxEnsureCapacity_real_T(sp, phi_Q1, i, &le_emlrtRTEI);
    phi_Q1_data = phi_Q1->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      phi_Q1_data[i] = grade_obs_data[r11[i]] - param_FPM_obs_cost;
    }
    for (i = 0; i < loop_ub_tmp; i++) {
      grade_obs_data[r11[i]] = phi_Q1_data[i];
    }
    emxFree_int32_T(sp, &r13);
    emxFree_real_T(sp, &phi_Q1);
    /*  ----------------------------------------------------------------- */
    emlrtMEXProfilingStatement(85, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(81, isMexOutdated);
    emlrtMEXProfilingStatement(82, isMexOutdated);
    phi_o->size[0] = 0;
    emlrtMEXProfilingStatement(85, isMexOutdated);
  }
  /* --PFM of Obstacle (end)---------------------------------------------------
   */
  /* --最終的なPMF--------------------------------------------------------------
   */
  emlrtMEXProfilingStatement(86, isMexOutdated);
  st.site = &oc_emlrtRSI;
  b_st.site = &md_emlrtRSI;
  c_st.site = &nd_emlrtRSI;
  d_st.site = &od_emlrtRSI;
  e_st.site = &pd_emlrtRSI;
  f_st.site = &qd_emlrtRSI;
  last = grade_obs->size[0];
  if (grade_obs->size[0] <= 2) {
    if (grade_obs->size[0] == 1) {
      R_tmp = grade_obs_data[0];
    } else {
      R_tmp = grade_obs_data[grade_obs->size[0] - 1];
      if ((!(grade_obs_data[0] > R_tmp)) &&
          ((!muDoubleScalarIsNaN(grade_obs_data[0])) ||
           muDoubleScalarIsNaN(R_tmp))) {
        R_tmp = grade_obs_data[0];
      }
    }
  } else {
    g_st.site = &sd_emlrtRSI;
    if (!muDoubleScalarIsNaN(grade_obs_data[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      h_st.site = &td_emlrtRSI;
      if (grade_obs->size[0] > 2147483646) {
        i_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      scalarLB_tmp = 2;
      exitg1 = false;
      while ((!exitg1) && (scalarLB_tmp <= last)) {
        if (!muDoubleScalarIsNaN(grade_obs_data[scalarLB_tmp - 1])) {
          idx = scalarLB_tmp;
          exitg1 = true;
        } else {
          scalarLB_tmp++;
        }
      }
    }
    if (idx == 0) {
      R_tmp = grade_obs_data[0];
    } else {
      g_st.site = &rd_emlrtRSI;
      R_tmp = grade_obs_data[idx - 1];
      vectorUB_tmp = idx + 1;
      h_st.site = &ud_emlrtRSI;
      if ((idx + 1 <= grade_obs->size[0]) &&
          (grade_obs->size[0] > 2147483646)) {
        i_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (scalarLB_tmp = vectorUB_tmp; scalarLB_tmp <= last; scalarLB_tmp++) {
        b_R_tmp = grade_obs_data[scalarLB_tmp - 1];
        if (R_tmp > b_R_tmp) {
          R_tmp = b_R_tmp;
        }
      }
    }
  }
  emxFree_real_T(&f_st, &grade_obs);
  /* --------------------------------------------------------------------------
   */
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  Grade = muDoubleScalarMin(
      -((1.0 - param_FPM_eta) / 3.1415926535897931) *
              muDoubleScalarAbs(muDoubleScalarAtan2(muDoubleScalarSin(phig),
                                                    muDoubleScalarCos(phig))) +
          1.0,
      R_tmp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return Grade;
}

/* End of code generation (FPM_capsule_v3_1.c) */
