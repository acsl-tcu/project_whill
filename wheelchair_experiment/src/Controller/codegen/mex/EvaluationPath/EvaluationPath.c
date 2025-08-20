/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath.c
 *
 * Code generation for function 'EvaluationPath'
 *
 */

/* Include files */
#include "EvaluationPath.h"
#include "EvaluationPath_data.h"
#include "EvaluationPath_emxutil.h"
#include "EvaluationPath_types.h"
#include "FPM_capsule_v3_1.h"
#include "any.h"
#include "assertValidSizeArg.h"
#include "cos.h"
#include "indexShapeCheck.h"
#include "pagetranspose.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "sum.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    15,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    16,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    18,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    19,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    21,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    22,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    24,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    25,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    28,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    38,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    40,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    187,              /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    204,              /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    205,              /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    207,              /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI = {
    40,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

static emlrtECInfo emlrtECI = {
    2,                /* nDims */
    210,              /* lineNo */
    10,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,               /* nDims */
    199,              /* lineNo */
    9,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    -1,               /* nDims */
    197,              /* lineNo */
    9,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    197,              /* lineNo */
    17,               /* colNo */
    "grade",          /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    1,                /* iFirst */
    1000,             /* iLast */
    190,              /* lineNo */
    31,               /* colNo */
    "pu",             /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    1,                /* iFirst */
    21,               /* iLast */
    187,              /* lineNo */
    120,              /* colNo */
    "obj.target",     /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                /* iFirst */
    21,               /* iLast */
    187,              /* lineNo */
    103,              /* colNo */
    "preobs",         /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    52,               /* lineNo */
    17,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    49,               /* lineNo */
    30,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    45,               /* lineNo */
    13,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    3,                /* nDims */
    40,               /* lineNo */
    23,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    4,                /* nDims */
    41,               /* lineNo */
    93,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    3,                /* nDims */
    41,               /* lineNo */
    93,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo g_emlrtECI = {
    4,                /* nDims */
    41,               /* lineNo */
    38,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo h_emlrtECI = {
    3,                /* nDims */
    41,               /* lineNo */
    38,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo i_emlrtECI = {
    4,                /* nDims */
    40,               /* lineNo */
    78,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo j_emlrtECI = {
    3,                /* nDims */
    40,               /* lineNo */
    78,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo k_emlrtECI = {
    4,                /* nDims */
    40,               /* lineNo */
    23,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo l_emlrtECI = {
    -1,               /* nDims */
    25,               /* lineNo */
    6,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo m_emlrtECI = {
    -1,               /* nDims */
    24,               /* lineNo */
    6,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo n_emlrtECI = {
    -1,               /* nDims */
    22,               /* lineNo */
    6,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo o_emlrtECI = {
    -1,               /* nDims */
    21,               /* lineNo */
    6,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo p_emlrtECI = {
    -1,               /* nDims */
    19,               /* lineNo */
    6,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo q_emlrtECI = {
    -1,               /* nDims */
    18,               /* lineNo */
    6,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo r_emlrtECI = {
    -1,               /* nDims */
    16,               /* lineNo */
    6,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo s_emlrtECI = {
    -1,               /* nDims */
    15,               /* lineNo */
    6,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtBCInfo e_emlrtBCI = {
    1,                /* iFirst */
    21,               /* iLast */
    28,               /* lineNo */
    38,               /* colNo */
    "obj.target_n",   /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    28,               /* lineNo */
    38,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtECInfo t_emlrtECI = {
    2,                /* nDims */
    25,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo u_emlrtECI = {
    2,                /* nDims */
    24,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo v_emlrtECI = {
    2,                /* nDims */
    22,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo w_emlrtECI = {
    2,                /* nDims */
    21,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo x_emlrtECI = {
    2,                /* nDims */
    19,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo y_emlrtECI = {
    2,                /* nDims */
    18,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo ab_emlrtECI = {
    2,                /* nDims */
    16,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtECInfo bb_emlrtECI = {
    2,                /* nDims */
    15,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtDCInfo c_emlrtDCI = {
    13,               /* lineNo */
    39,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    13,               /* lineNo */
    33,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    13,               /* lineNo */
    33,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    4                              /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    9,                /* lineNo */
    21,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    7,                /* lineNo */
    29,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    7,                /* lineNo */
    21,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    5,                /* lineNo */
    24,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    5,                /* lineNo */
    24,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    4                              /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    5,                /* lineNo */
    16,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    5,                /* lineNo */
    16,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    4                              /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    28,               /* lineNo */
    23,               /* colNo */
    "obj.selectZone", /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    28,               /* lineNo */
    23,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    36,               /* lineNo */
    37,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                /* iFirst */
    10,               /* iLast */
    36,               /* lineNo */
    37,               /* colNo */
    "NoEntryZone2",   /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = {
    47,               /* lineNo */
    9,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    190,              /* lineNo */
    17,               /* colNo */
    "vcost",          /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                /* iFirst */
    21,               /* iLast */
    187,              /* lineNo */
    61,               /* colNo */
    "px",             /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                /* iFirst */
    1000,             /* iLast */
    187,              /* lineNo */
    65,               /* colNo */
    "px",             /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                /* iFirst */
    21,               /* iLast */
    187,              /* lineNo */
    73,               /* colNo */
    "px",             /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    187,              /* lineNo */
    25,               /* colNo */
    "grade_temp",     /* aName */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo r_emlrtRTEI = {
    5,                /* lineNo */
    2,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    7,                /* lineNo */
    5,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    9,                /* lineNo */
    5,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    13,               /* lineNo */
    6,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    15,               /* lineNo */
    87,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    15,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    16,               /* lineNo */
    87,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    16,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    18,               /* lineNo */
    87,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    18,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    19,               /* lineNo */
    87,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    19,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    21,               /* lineNo */
    87,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    21,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    22,               /* lineNo */
    87,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    22,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    24,               /* lineNo */
    87,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    24,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    25,               /* lineNo */
    87,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    25,               /* lineNo */
    32,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    28,               /* lineNo */
    5,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    36,               /* lineNo */
    21,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    40,               /* lineNo */
    23,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    40,               /* lineNo */
    78,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    41,               /* lineNo */
    38,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    41,               /* lineNo */
    93,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    204,              /* lineNo */
    16,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    47,               /* lineNo */
    9,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    207,              /* lineNo */
    5,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    210,              /* lineNo */
    10,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    210,              /* lineNo */
    5,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    38,               /* lineNo */
    5,                /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    1,                /* lineNo */
    31,               /* colNo */
    "EvaluationPath", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pName */
};

static emlrtRSInfo je_emlrtRSI = {
    210,              /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI = {
    41,               /* lineNo */
    "EvaluationPath", /* fcnName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/EvaluationPath.m" /* pathName */
};

/* Function Declarations */
static void b_and(const emlrtStack *sp, emxArray_boolean_T *in1,
                  const emxArray_boolean_T *in2);

static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const real_T in2[1000], const struct0_T *in3,
                             const real_T in4[1000], const real_T in5[2]);

static void binary_expand_op_1(const emlrtStack *sp, const emlrtRSInfo in2,
                               const emxArray_boolean_T *in3,
                               const emxArray_boolean_T *in4,
                               boolean_T in1[1000]);

static void binary_expand_op_2(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               int32_T in4, const emxArray_real_T *in5);

static void binary_expand_op_3(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               int32_T in4, const emxArray_real_T *in5);

static void binary_expand_op_4(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               int32_T in4, const emxArray_real_T *in5);

static void binary_expand_op_5(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               int32_T in4, const emxArray_real_T *in5);

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2);

/* Function Definitions */
static void b_and(const emlrtStack *sp, emxArray_boolean_T *in1,
                  const emxArray_boolean_T *in2)
{
  emxArray_boolean_T *b_in1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_1_2;
  const boolean_T *in2_data;
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in1, 4, &ob_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = 4;
  b_in1->size[1] = 6;
  if (in2->size[2] == 1) {
    loop_ub = in1->size[2];
  } else {
    loop_ub = in2->size[2];
  }
  b_in1->size[2] = loop_ub;
  b_in1->size[3] = 1000;
  emxEnsureCapacity_boolean_T(sp, b_in1, i, &ob_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_2 = (in1->size[2] != 1);
  stride_1_2 = (in2->size[2] != 1);
  for (i = 0; i < 1000; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        b_in1_data[(4 * i2 + 24 * i1) + 24 * b_in1->size[2] * i] =
            (in1_data[(4 * i2 + 24 * aux_0_2) + 24 * in1->size[2] * i] &&
             in2_data[(4 * i2 + 24 * aux_1_2) + 24 * in2->size[2] * i]);
        b_in1_data[((4 * i2 + 24 * i1) + 24 * b_in1->size[2] * i) + 1] =
            (in1_data[((4 * i2 + 24 * aux_0_2) + 24 * in1->size[2] * i) + 1] &&
             in2_data[((4 * i2 + 24 * aux_1_2) + 24 * in2->size[2] * i) + 1]);
        b_in1_data[((4 * i2 + 24 * i1) + 24 * b_in1->size[2] * i) + 2] =
            (in1_data[((4 * i2 + 24 * aux_0_2) + 24 * in1->size[2] * i) + 2] &&
             in2_data[((4 * i2 + 24 * aux_1_2) + 24 * in2->size[2] * i) + 2]);
        b_in1_data[((4 * i2 + 24 * i1) + 24 * b_in1->size[2] * i) + 3] =
            (in1_data[((4 * i2 + 24 * aux_0_2) + 24 * in1->size[2] * i) + 3] &&
             in2_data[((4 * i2 + 24 * aux_1_2) + 24 * in2->size[2] * i) + 3]);
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  in1->size[1] = 6;
  in1->size[2] = loop_ub;
  in1->size[3] = 1000;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ob_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        stride_0_2 = 4 * i2 + 24 * i1;
        in1_data[stride_0_2 + 24 * in1->size[2] * i] =
            b_in1_data[stride_0_2 + 24 * b_in1->size[2] * i];
        in1_data[((4 * i2 + 24 * i1) + 24 * in1->size[2] * i) + 1] =
            b_in1_data[((4 * i2 + 24 * i1) + 24 * b_in1->size[2] * i) + 1];
        in1_data[((4 * i2 + 24 * i1) + 24 * in1->size[2] * i) + 2] =
            b_in1_data[((4 * i2 + 24 * i1) + 24 * b_in1->size[2] * i) + 2];
        in1_data[((4 * i2 + 24 * i1) + 24 * in1->size[2] * i) + 3] =
            b_in1_data[((4 * i2 + 24 * i1) + 24 * b_in1->size[2] * i) + 3];
      }
    }
  }
  emxFree_boolean_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const real_T in2[1000], const struct0_T *in3,
                             const real_T in4[1000], const real_T in5[2])
{
  emxArray_real_T *b_in1;
  real_T b_in3;
  real_T c_in3;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T unnamed_idx_1;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  b_in3 = in3->R[1];
  c_in3 = in3->R[0];
  unnamed_idx_1 = (int32_T)in5[1];
  emxInit_real_T(sp, &b_in1, 2, &vb_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (unnamed_idx_1 == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = unnamed_idx_1;
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &vb_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  unnamed_idx_1 = (unnamed_idx_1 != 1);
  for (i = 0; i < loop_ub; i++) {
    int32_T in1_tmp;
    in1_tmp = i * unnamed_idx_1;
    b_in1_data[i] = in1_data[i * stride_0_1] +
                    (in2[in1_tmp] * b_in3 + in4[in1_tmp] * c_in3);
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &vb_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_1(const emlrtStack *sp, const emlrtRSInfo in2,
                               const emxArray_boolean_T *in3,
                               const emxArray_boolean_T *in4,
                               boolean_T in1[1000])
{
  emlrtStack st;
  emxArray_boolean_T *b_in3;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_1_2;
  const boolean_T *in3_data;
  const boolean_T *in4_data;
  boolean_T *b_in3_data;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in3, 4, &ob_emlrtRTEI);
  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2] * b_in3->size[3];
  b_in3->size[0] = 4;
  b_in3->size[1] = 6;
  if (in4->size[2] == 1) {
    loop_ub = in3->size[2];
  } else {
    loop_ub = in4->size[2];
  }
  b_in3->size[2] = loop_ub;
  b_in3->size[3] = 1000;
  emxEnsureCapacity_boolean_T(sp, b_in3, i, &ob_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_2 = (in3->size[2] != 1);
  stride_1_2 = (in4->size[2] != 1);
  for (i = 0; i < 1000; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        b_in3_data[(4 * i2 + 24 * i1) + 24 * b_in3->size[2] * i] =
            (in3_data[(4 * i2 + 24 * aux_0_2) + 24 * in3->size[2] * i] &&
             in4_data[(4 * i2 + 24 * aux_1_2) + 24 * in4->size[2] * i]);
        b_in3_data[((4 * i2 + 24 * i1) + 24 * b_in3->size[2] * i) + 1] =
            (in3_data[((4 * i2 + 24 * aux_0_2) + 24 * in3->size[2] * i) + 1] &&
             in4_data[((4 * i2 + 24 * aux_1_2) + 24 * in4->size[2] * i) + 1]);
        b_in3_data[((4 * i2 + 24 * i1) + 24 * b_in3->size[2] * i) + 2] =
            (in3_data[((4 * i2 + 24 * aux_0_2) + 24 * in3->size[2] * i) + 2] &&
             in4_data[((4 * i2 + 24 * aux_1_2) + 24 * in4->size[2] * i) + 2]);
        b_in3_data[((4 * i2 + 24 * i1) + 24 * b_in3->size[2] * i) + 3] =
            (in3_data[((4 * i2 + 24 * aux_0_2) + 24 * in3->size[2] * i) + 3] &&
             in4_data[((4 * i2 + 24 * aux_1_2) + 24 * in4->size[2] * i) + 3]);
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
  }
  st.site = (emlrtRSInfo *)&in2;
  any(&st, b_in3, in1);
  emxFree_boolean_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_2(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               int32_T in4, const emxArray_real_T *in5)
{
  const real_T *in2_data;
  const real_T *in5_data;
  int32_T aux_0_3;
  int32_T i;
  int32_T i1;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  boolean_T *in1_data;
  in5_data = in5->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  in1->size[1] = 6;
  emxEnsureCapacity_boolean_T(sp, in1, i, &rb_emlrtRTEI);
  i = in4 - in3;
  if (in5->size[2] == 1) {
    loop_ub = i;
  } else {
    loop_ub = in5->size[2];
  }
  i1 = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = loop_ub;
  in1->size[3] = 1000;
  emxEnsureCapacity_boolean_T(sp, in1, i1, &rb_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (i != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in5->size[2] != 1);
  aux_0_3 = 0;
  for (i = 0; i < 1000; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      int32_T i2;
      i2 = in3 + aux_0_2;
      for (i3 = 0; i3 < 6; i3++) {
        in1_data[(4 * i3 + 24 * i1) + 24 * in1->size[2] * i] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 4] <=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 3]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 1] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 5] <=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 3]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 2] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 6] <=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 3]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 3] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 7] <=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 3]);
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_3(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               int32_T in4, const emxArray_real_T *in5)
{
  const real_T *in2_data;
  const real_T *in5_data;
  int32_T aux_0_3;
  int32_T i;
  int32_T i1;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  boolean_T *in1_data;
  in5_data = in5->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  in1->size[1] = 6;
  emxEnsureCapacity_boolean_T(sp, in1, i, &qb_emlrtRTEI);
  i = in4 - in3;
  if (in5->size[2] == 1) {
    loop_ub = i;
  } else {
    loop_ub = in5->size[2];
  }
  i1 = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = loop_ub;
  in1->size[3] = 1000;
  emxEnsureCapacity_boolean_T(sp, in1, i1, &qb_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (i != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in5->size[2] != 1);
  aux_0_3 = 0;
  for (i = 0; i < 1000; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      int32_T i2;
      i2 = in3 + aux_0_2;
      for (i3 = 0; i3 < 6; i3++) {
        in1_data[(4 * i3 + 24 * i1) + 24 * in1->size[2] * i] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 4] >=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 2]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 1] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 5] >=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 2]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 2] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 6] >=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 2]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 3] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 7] >=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 2]);
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_4(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               int32_T in4, const emxArray_real_T *in5)
{
  const real_T *in2_data;
  const real_T *in5_data;
  int32_T aux_0_3;
  int32_T i;
  int32_T i1;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  boolean_T *in1_data;
  in5_data = in5->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  in1->size[1] = 6;
  emxEnsureCapacity_boolean_T(sp, in1, i, &pb_emlrtRTEI);
  i = in4 - in3;
  if (in5->size[2] == 1) {
    loop_ub = i;
  } else {
    loop_ub = in5->size[2];
  }
  i1 = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = loop_ub;
  in1->size[3] = 1000;
  emxEnsureCapacity_boolean_T(sp, in1, i1, &pb_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (i != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in5->size[2] != 1);
  aux_0_3 = 0;
  for (i = 0; i < 1000; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      int32_T i2;
      i2 = in3 + aux_0_2;
      for (i3 = 0; i3 < 6; i3++) {
        in1_data[(4 * i3 + 24 * i1) + 24 * in1->size[2] * i] =
            (in2_data[8 * i2 + 8 * in2->size[2] * aux_0_3] <=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 1]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 1] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 1] <=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 1]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 2] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 2] <=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 1]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 3] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 3] <=
             in5_data[((4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i) + 1]);
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_5(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2, int32_T in3,
                               int32_T in4, const emxArray_real_T *in5)
{
  const real_T *in2_data;
  const real_T *in5_data;
  int32_T aux_0_3;
  int32_T i;
  int32_T i1;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  boolean_T *in1_data;
  in5_data = in5->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  in1->size[1] = 6;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ob_emlrtRTEI);
  i = in4 - in3;
  if (in5->size[2] == 1) {
    loop_ub = i;
  } else {
    loop_ub = in5->size[2];
  }
  i1 = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = loop_ub;
  in1->size[3] = 1000;
  emxEnsureCapacity_boolean_T(sp, in1, i1, &ob_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (i != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in5->size[2] != 1);
  aux_0_3 = 0;
  for (i = 0; i < 1000; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      int32_T i2;
      i2 = in3 + aux_0_2;
      for (i3 = 0; i3 < 6; i3++) {
        in1_data[(4 * i3 + 24 * i1) + 24 * in1->size[2] * i] =
            (in2_data[8 * i2 + 8 * in2->size[2] * aux_0_3] >=
             in5_data[(4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 1] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 1] >=
             in5_data[(4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 2] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 2] >=
             in5_data[(4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i]);
        in1_data[((4 * i3 + 24 * i1) + 24 * in1->size[2] * i) + 3] =
            (in2_data[(8 * i2 + 8 * in2->size[2] * aux_0_3) + 3] >=
             in5_data[(4 * i3 + 24 * aux_1_2) + 24 * in5->size[2] * i]);
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
    aux_0_3 += stride_0_3;
  }
}

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &vb_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &vb_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in2->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] + in2_data[i * stride_1_1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &vb_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void EvaluationPath(EvaluationPathStackData *SD, const emlrtStack *sp,
                    const struct0_T *obj, const real_T px[63000],
                    const real_T pu[42000], const real_T preobs_data[],
                    const int32_T preobs_size[3], const struct1_T *param_FPM,
                    emxArray_real_T *pw, boolean_T remove_sample[1000])
{
  __m128d r1;
  __m128d r8;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *r2;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_real_T e_obj;
  emxArray_real_T *B;
  emxArray_real_T *NoEntryZone4;
  emxArray_real_T *OBScost;
  emxArray_real_T *a__1;
  emxArray_real_T *b_px;
  emxArray_real_T *d_obj;
  emxArray_real_T *grade;
  emxArray_real_T *grade_temp;
  emxArray_real_T *obscost;
  emxArray_real_T *r;
  emxArray_real_T *vcost;
  emxArray_real_T *vehicle_corner;
  real_T y[20000];
  real_T dv1[1000];
  real_T dv2[1000];
  real_T dv[2];
  real_T c_obj;
  real_T d;
  real_T d1;
  real_T y_tmp;
  real_T *B_data;
  real_T *NoEntryZone4_data;
  real_T *grade_data;
  real_T *obscost_data;
  real_T *vcost_data;
  real_T *vehicle_corner_data;
  int32_T b_iv[4];
  int32_T iv1[4];
  int32_T b_obj[2];
  int32_T b_preobs_size[2];
  int32_T b_loop_ub;
  int32_T b_loop_ub_tmp;
  int32_T c_loop_ub_tmp;
  int32_T d_loop_ub_tmp;
  int32_T f_obj;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T n;
  int32_T nx;
  int32_T obj_tmp;
  boolean_T out;
  boolean_T *r4;
  boolean_T *r5;
  boolean_T *r7;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emlrtMEXProfilingFunctionEntry((char_T *)EvaluationPath_complete_name,
                                 isMexOutdated);
  /* EVALUATIONPATH この関数の概要をここに記述 */
  /*    詳細説明をここに記述 */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  y_tmp = obj->K - 1.0;
  if (!(obj->K - 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K - 1.0, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  d = (int32_T)muDoubleScalarFloor(obj->K - 1.0);
  if (obj->K - 1.0 != d) {
    emlrtIntegerCheckR2012b(obj->K - 1.0, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(obj->NP);
  if (obj->NP != i) {
    emlrtIntegerCheckR2012b(obj->NP, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &grade, 2, &r_emlrtRTEI);
  loop_ub_tmp = (int32_T)(obj->K - 1.0);
  i1 = grade->size[0] * grade->size[1];
  grade->size[0] = (int32_T)(obj->K - 1.0);
  b_loop_ub_tmp = (int32_T)obj->NP;
  grade->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, grade, i1, &r_emlrtRTEI);
  grade_data = grade->data;
  c_loop_ub_tmp = (int32_T)(obj->K - 1.0) * (int32_T)obj->NP;
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    grade_data[i1] = 0.0;
  }
  /*  remove_sample = false(1,obj.NP); */
  emlrtMEXProfilingStatement(2, isMexOutdated);
  if (obj->K - 1.0 != d) {
    emlrtIntegerCheckR2012b(obj->K - 1.0, &h_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (obj->NP != i) {
    emlrtIntegerCheckR2012b(obj->NP, &g_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &obscost, 2, &s_emlrtRTEI);
  i1 = obscost->size[0] * obscost->size[1];
  obscost->size[0] = (int32_T)(obj->K - 1.0);
  obscost->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, obscost, i1, &s_emlrtRTEI);
  obscost_data = obscost->data;
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    obscost_data[i1] = 0.0;
  }
  /*  wallcost = zeros(obj.K-1,obj.NP); */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  if ((int32_T)obj->NP != i) {
    emlrtIntegerCheckR2012b(obj->NP, &f_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &vcost, 2, &t_emlrtRTEI);
  i1 = vcost->size[0] * vcost->size[1];
  vcost->size[0] = 1;
  vcost->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, vcost, i1, &t_emlrtRTEI);
  vcost_data = vcost->data;
  for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
    vcost_data[i1] = 0.0;
  }
  /* 高速化のための変数 */
  emlrtMEXProfilingStatement(4, isMexOutdated);
  if (!(obj->K >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  d1 = (int32_T)muDoubleScalarFloor(obj->K);
  if (obj->K != d1) {
    emlrtIntegerCheckR2012b(obj->K, &d_emlrtDCI, (emlrtConstCTX)sp);
  }
  if ((int32_T)obj->NP != i) {
    emlrtIntegerCheckR2012b(obj->NP, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &vehicle_corner, 4, &u_emlrtRTEI);
  i = vehicle_corner->size[0] * vehicle_corner->size[1] *
      vehicle_corner->size[2] * vehicle_corner->size[3];
  vehicle_corner->size[0] = 4;
  vehicle_corner->size[1] = 2;
  loop_ub = (int32_T)obj->K;
  vehicle_corner->size[2] = (int32_T)obj->K;
  vehicle_corner->size[3] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, vehicle_corner, i, &u_emlrtRTEI);
  vehicle_corner_data = vehicle_corner->data;
  d_loop_ub_tmp = ((int32_T)obj->K << 3) * (int32_T)obj->NP;
  for (i = 0; i < d_loop_ub_tmp; i++) {
    vehicle_corner_data[i] = 0.0;
  }
  /*  左後ろ */
  emlrtMEXProfilingStatement(5, isMexOutdated);
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if ((int32_T)obj->K * (int32_T)obj->NP != 21000) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }
  emxInit_real_T(sp, &r, 2, &v_emlrtRTEI);
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &v_emlrtRTEI);
  B_data = r->data;
  for (i = 0; i < 21000; i++) {
    B_data[i] = obj->ltheta[1] + SD->f0.px[i];
  }
  st.site = &emlrtRSI;
  b_sin(&st, r);
  B_data = r->data;
  d_loop_ub_tmp = r->size[0] * r->size[1];
  c_obj = obj->ltheta[0];
  nx = (d_loop_ub_tmp / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_mul_pd(_mm_set1_pd(c_obj), r1));
  }
  for (i = nx; i < d_loop_ub_tmp; i++) {
    B_data[i] *= c_obj;
  }
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&b_obj[0], &r->size[0], &bb_emlrtECI,
                                  (emlrtCTX)sp);
  }
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = (int32_T)obj->K;
  b_iv[3] = (int32_T)obj->NP;
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &s_emlrtECI,
                                (emlrtCTX)sp);
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }
  emxInit_real_T(sp, &b_px, 2, &w_emlrtRTEI);
  i = b_px->size[0] * b_px->size[1];
  b_px->size[0] = (int32_T)obj->K;
  b_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, b_px, i, &w_emlrtRTEI);
  NoEntryZone4_data = b_px->data;
  for (i = 0; i < 21000; i++) {
    NoEntryZone4_data[i] = SD->f0.px[i] + B_data[i];
  }
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      vehicle_corner_data[8 * i1 + 8 * vehicle_corner->size[2] * i] =
          NoEntryZone4_data[i1 + loop_ub * i];
    }
  }
  emlrtMEXProfilingStatement(6, isMexOutdated);
  st.site = &b_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  st.site = &b_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &x_emlrtRTEI);
  B_data = r->data;
  for (i = 0; i < 21000; i++) {
    B_data[i] = obj->ltheta[9] + SD->f0.px[i];
  }
  st.site = &b_emlrtRSI;
  b_cos(&st, r);
  B_data = r->data;
  d_loop_ub_tmp = r->size[0] * r->size[1];
  c_obj = obj->ltheta[8];
  nx = (d_loop_ub_tmp / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_mul_pd(_mm_set1_pd(c_obj), r1));
  }
  for (i = nx; i < d_loop_ub_tmp; i++) {
    B_data[i] *= c_obj;
  }
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&b_obj[0], &r->size[0], &ab_emlrtECI,
                                  (emlrtCTX)sp);
  }
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = (int32_T)obj->K;
  b_iv[3] = (int32_T)obj->NP;
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &r_emlrtECI,
                                (emlrtCTX)sp);
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }
  i = b_px->size[0] * b_px->size[1];
  b_px->size[0] = (int32_T)obj->K;
  b_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, b_px, i, &y_emlrtRTEI);
  NoEntryZone4_data = b_px->data;
  for (i = 0; i < 21000; i++) {
    NoEntryZone4_data[i] = SD->f0.px[i] + B_data[i];
  }
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 4] =
          NoEntryZone4_data[i1 + loop_ub * i];
    }
  }
  /* 　左前 */
  emlrtMEXProfilingStatement(7, isMexOutdated);
  st.site = &c_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  st.site = &c_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &ab_emlrtRTEI);
  B_data = r->data;
  for (i = 0; i < 21000; i++) {
    B_data[i] = obj->ltheta[3] + SD->f0.px[i];
  }
  st.site = &c_emlrtRSI;
  b_cos(&st, r);
  B_data = r->data;
  d_loop_ub_tmp = r->size[0] * r->size[1];
  c_obj = obj->ltheta[2];
  nx = (d_loop_ub_tmp / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_mul_pd(_mm_set1_pd(c_obj), r1));
  }
  for (i = nx; i < d_loop_ub_tmp; i++) {
    B_data[i] *= c_obj;
  }
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&b_obj[0], &r->size[0], &y_emlrtECI,
                                  (emlrtCTX)sp);
  }
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = (int32_T)obj->K;
  b_iv[3] = (int32_T)obj->NP;
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &q_emlrtECI,
                                (emlrtCTX)sp);
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }
  i = b_px->size[0] * b_px->size[1];
  b_px->size[0] = (int32_T)obj->K;
  b_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, b_px, i, &bb_emlrtRTEI);
  NoEntryZone4_data = b_px->data;
  for (i = 0; i < 21000; i++) {
    NoEntryZone4_data[i] = SD->f0.px[i] + B_data[i];
  }
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 1] =
          NoEntryZone4_data[i1 + loop_ub * i];
    }
  }
  emlrtMEXProfilingStatement(8, isMexOutdated);
  st.site = &d_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  st.site = &d_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &cb_emlrtRTEI);
  B_data = r->data;
  for (i = 0; i < 21000; i++) {
    B_data[i] = obj->ltheta[11] + SD->f0.px[i];
  }
  st.site = &d_emlrtRSI;
  b_sin(&st, r);
  B_data = r->data;
  d_loop_ub_tmp = r->size[0] * r->size[1];
  c_obj = obj->ltheta[10];
  nx = (d_loop_ub_tmp / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_mul_pd(_mm_set1_pd(c_obj), r1));
  }
  for (i = nx; i < d_loop_ub_tmp; i++) {
    B_data[i] *= c_obj;
  }
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&b_obj[0], &r->size[0], &x_emlrtECI,
                                  (emlrtCTX)sp);
  }
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = (int32_T)obj->K;
  b_iv[3] = (int32_T)obj->NP;
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &p_emlrtECI,
                                (emlrtCTX)sp);
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }
  i = b_px->size[0] * b_px->size[1];
  b_px->size[0] = (int32_T)obj->K;
  b_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, b_px, i, &db_emlrtRTEI);
  NoEntryZone4_data = b_px->data;
  for (i = 0; i < 21000; i++) {
    NoEntryZone4_data[i] = SD->f0.px[i] + B_data[i];
  }
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 5] =
          NoEntryZone4_data[i1 + loop_ub * i];
    }
  }
  /* 　右後ろ */
  emlrtMEXProfilingStatement(9, isMexOutdated);
  st.site = &e_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  st.site = &e_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &eb_emlrtRTEI);
  B_data = r->data;
  for (i = 0; i < 21000; i++) {
    B_data[i] = obj->ltheta[5] - SD->f0.px[i];
  }
  st.site = &e_emlrtRSI;
  b_cos(&st, r);
  B_data = r->data;
  d_loop_ub_tmp = r->size[0] * r->size[1];
  c_obj = obj->ltheta[4];
  nx = (d_loop_ub_tmp / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_mul_pd(_mm_set1_pd(c_obj), r1));
  }
  for (i = nx; i < d_loop_ub_tmp; i++) {
    B_data[i] *= c_obj;
  }
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&b_obj[0], &r->size[0], &w_emlrtECI,
                                  (emlrtCTX)sp);
  }
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = (int32_T)obj->K;
  b_iv[3] = (int32_T)obj->NP;
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &o_emlrtECI,
                                (emlrtCTX)sp);
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }
  i = b_px->size[0] * b_px->size[1];
  b_px->size[0] = (int32_T)obj->K;
  b_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, b_px, i, &fb_emlrtRTEI);
  NoEntryZone4_data = b_px->data;
  for (i = 0; i < 21000; i++) {
    NoEntryZone4_data[i] = SD->f0.px[i] + B_data[i];
  }
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 2] =
          NoEntryZone4_data[i1 + loop_ub * i];
    }
  }
  emlrtMEXProfilingStatement(10, isMexOutdated);
  st.site = &f_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  st.site = &f_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &gb_emlrtRTEI);
  B_data = r->data;
  for (i = 0; i < 21000; i++) {
    B_data[i] = obj->ltheta[13] - SD->f0.px[i];
  }
  st.site = &f_emlrtRSI;
  b_cos(&st, r);
  B_data = r->data;
  d_loop_ub_tmp = r->size[0] * r->size[1];
  c_obj = obj->ltheta[12];
  nx = (d_loop_ub_tmp / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_mul_pd(_mm_set1_pd(c_obj), r1));
  }
  for (i = nx; i < d_loop_ub_tmp; i++) {
    B_data[i] *= c_obj;
  }
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&b_obj[0], &r->size[0], &v_emlrtECI,
                                  (emlrtCTX)sp);
  }
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = (int32_T)obj->K;
  b_iv[3] = (int32_T)obj->NP;
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &n_emlrtECI,
                                (emlrtCTX)sp);
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }
  i = b_px->size[0] * b_px->size[1];
  b_px->size[0] = (int32_T)obj->K;
  b_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, b_px, i, &hb_emlrtRTEI);
  NoEntryZone4_data = b_px->data;
  for (i = 0; i < 21000; i++) {
    NoEntryZone4_data[i] = SD->f0.px[i] + B_data[i];
  }
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 6] =
          NoEntryZone4_data[i1 + loop_ub * i];
    }
  }
  /* 　右前 */
  emlrtMEXProfilingStatement(11, isMexOutdated);
  st.site = &g_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  st.site = &g_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &ib_emlrtRTEI);
  B_data = r->data;
  for (i = 0; i < 21000; i++) {
    B_data[i] = obj->ltheta[7] + SD->f0.px[i];
  }
  st.site = &g_emlrtRSI;
  b_sin(&st, r);
  B_data = r->data;
  d_loop_ub_tmp = r->size[0] * r->size[1];
  c_obj = obj->ltheta[6];
  nx = (d_loop_ub_tmp / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_mul_pd(_mm_set1_pd(c_obj), r1));
  }
  for (i = nx; i < d_loop_ub_tmp; i++) {
    B_data[i] *= c_obj;
  }
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&b_obj[0], &r->size[0], &u_emlrtECI,
                                  (emlrtCTX)sp);
  }
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = (int32_T)obj->K;
  b_iv[3] = (int32_T)obj->NP;
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &m_emlrtECI,
                                (emlrtCTX)sp);
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[3 * i1 + 63 * i];
    }
  }
  i = b_px->size[0] * b_px->size[1];
  b_px->size[0] = (int32_T)obj->K;
  b_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, b_px, i, &jb_emlrtRTEI);
  NoEntryZone4_data = b_px->data;
  for (i = 0; i < 21000; i++) {
    NoEntryZone4_data[i] = SD->f0.px[i] + B_data[i];
  }
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 3] =
          NoEntryZone4_data[i1 + loop_ub * i];
    }
  }
  emlrtMEXProfilingStatement(12, isMexOutdated);
  st.site = &h_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  st.site = &h_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  if ((int32_T)obj->K > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP > 21000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)obj->K >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 2];
    }
  }
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &kb_emlrtRTEI);
  B_data = r->data;
  for (i = 0; i < 21000; i++) {
    B_data[i] = obj->ltheta[15] + SD->f0.px[i];
  }
  st.site = &h_emlrtRSI;
  b_sin(&st, r);
  B_data = r->data;
  d_loop_ub_tmp = r->size[0] * r->size[1];
  c_obj = obj->ltheta[14];
  nx = (d_loop_ub_tmp / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_mul_pd(_mm_set1_pd(c_obj), r1));
  }
  for (i = nx; i < d_loop_ub_tmp; i++) {
    B_data[i] *= c_obj;
  }
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&b_obj[0], &r->size[0], &t_emlrtECI,
                                  (emlrtCTX)sp);
  }
  b_iv[0] = 1;
  b_iv[1] = 1;
  b_iv[2] = (int32_T)obj->K;
  b_iv[3] = (int32_T)obj->NP;
  b_obj[0] = (int32_T)obj->K;
  b_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 4, &b_obj[0], 2, &l_emlrtECI,
                                (emlrtCTX)sp);
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      SD->f0.px[i1 + 21 * i] = px[(3 * i1 + 63 * i) + 1];
    }
  }
  i = b_px->size[0] * b_px->size[1];
  b_px->size[0] = (int32_T)obj->K;
  b_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, b_px, i, &lb_emlrtRTEI);
  NoEntryZone4_data = b_px->data;
  for (i = 0; i < 21000; i++) {
    NoEntryZone4_data[i] = SD->f0.px[i] + B_data[i];
  }
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 7] =
          NoEntryZone4_data[i1 + loop_ub * i];
    }
  }
  emxFree_real_T(sp, &b_px);
  /*     %% wall */
  emlrtMEXProfilingStatement(13, isMexOutdated);
  if (obj->K < 2.0) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    if (obj->K != d1) {
      emlrtIntegerCheckR2012b(obj->K, &b_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)obj->K < 1) || ((int32_T)obj->K > 21)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj->K, 1, 21, &e_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = (int32_T)obj->K;
  }
  obj_tmp = i1 - i;
  b_obj[0] = obj_tmp;
  b_obj[1] = 1000;
  st.site = &i_emlrtRSI;
  indexShapeCheck(&st, obj->selectZone.size[0], b_obj);
  emxInit_real_T(sp, &B, 2, &mb_emlrtRTEI);
  i1 = B->size[0] * B->size[1];
  B->size[0] = obj_tmp;
  B->size[1] = 1000;
  emxEnsureCapacity_real_T(sp, B, i1, &mb_emlrtRTEI);
  B_data = B->data;
  for (i1 = 0; i1 < 1000; i1++) {
    for (i2 = 0; i2 < obj_tmp; i2++) {
      d1 = obj->target_n[(i + i2) + 21 * i1];
      if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
        emlrtIntegerCheckR2012b(d1, &m_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d1 < 1) || ((int32_T)d1 > obj->selectZone.size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, obj->selectZone.size[0],
                                      &f_emlrtBCI, (emlrtConstCTX)sp);
      }
      B_data[i2 + B->size[0] * i1] = obj->selectZone.data[(int32_T)d1 - 1];
    }
  }
  emlrtMEXProfilingStatement(15, isMexOutdated);
  /*  Bを1列ベクトルに変換 */
  emlrtMEXProfilingStatement(16, isMexOutdated);
  /*  [p*q, 1] */
  /*  Aの各スライスを2次元に展開 */
  emlrtMEXProfilingStatement(17, isMexOutdated);
  /*  [m*n, k] */
  /*  BvecでA2から列を抽出 */
  emlrtMEXProfilingStatement(18, isMexOutdated);
  d_loop_ub_tmp = obj_tmp * 1000;
  for (i = 0; i < d_loop_ub_tmp; i++) {
    d1 = B_data[i];
    if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
      emlrtIntegerCheckR2012b(d1, &n_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d1 < 1) || ((int32_T)d1 > 10)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 10, &g_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
  }
  /*  [m*n, p*q] */
  /*  元の形に戻す */
  emlrtMEXProfilingStatement(19, isMexOutdated);
  st.site = &j_emlrtRSI;
  nx = 24 * d_loop_ub_tmp;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  assertValidSizeArg(&c_st, (real_T)(obj_tmp - 1) + 1.0);
  n = 24;
  if (d_loop_ub_tmp > 24) {
    n = obj_tmp * 1000;
  }
  if (muIntScalarMax_sint32(nx, n) < 1000) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (24 * obj_tmp * 1000 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  emxInit_real_T(sp, &d_obj, 2, &nb_emlrtRTEI);
  i = d_obj->size[0] * d_obj->size[1];
  d_obj->size[0] = 24;
  d_obj->size[1] = d_loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, d_obj, i, &nb_emlrtRTEI);
  NoEntryZone4_data = d_obj->data;
  for (i = 0; i < d_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      NoEntryZone4_data[i1 + 24 * i] =
          obj->NoEntryZone[i1 + 24 * ((int32_T)B_data[i] - 1)];
    }
  }
  emxFree_real_T(sp, &B);
  e_obj = *d_obj;
  iv1[0] = 6;
  iv1[1] = 4;
  iv1[2] = obj_tmp;
  iv1[3] = 1000;
  e_obj.size = &iv1[0];
  e_obj.numDimensions = 4;
  emxInit_real_T(sp, &NoEntryZone4, 4, &xb_emlrtRTEI);
  st.site = &j_emlrtRSI;
  pagetranspose(&st, &e_obj, NoEntryZone4);
  NoEntryZone4_data = NoEntryZone4->data;
  emxFree_real_T(sp, &d_obj);
  /*  [m, n, p, q] */
  emlrtMEXProfilingStatement(20, isMexOutdated);
  emlrtMEXProfilingStatement(21, isMexOutdated);
  if (vehicle_corner->size[2] < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = (int32_T)obj->K;
  }
  loop_ub = i1 - i;
  if ((loop_ub != NoEntryZone4->size[2]) &&
      ((loop_ub != 1) && (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, NoEntryZone4->size[2], &d_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((obj->NP != 1000.0) && (obj->NP != 1.0)) {
    emlrtDimSizeImpxCheckR2021b((int32_T)obj->NP, 1000, &k_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (vehicle_corner->size[2] < 2) {
    i2 = 0;
    nx = 0;
  } else {
    i2 = 1;
    nx = (int32_T)obj->K;
  }
  n = nx - i2;
  if ((n != NoEntryZone4->size[2]) &&
      ((n != 1) && (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(n, NoEntryZone4->size[2], &j_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((obj->NP != 1000.0) && (obj->NP != 1.0)) {
    emlrtDimSizeImpxCheckR2021b((int32_T)obj->NP, 1000, &i_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  emxInit_boolean_T(sp, &r2, 4, &ob_emlrtRTEI);
  if ((loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] == 1000)) {
    i1 = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = 4;
    r2->size[1] = 6;
    r2->size[2] = loop_ub;
    r2->size[3] = 1000;
    emxEnsureCapacity_boolean_T(sp, r2, i1, &ob_emlrtRTEI);
    r5 = r2->data;
    for (i1 = 0; i1 < 1000; i1++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        obj_tmp = i + i3;
        for (i4 = 0; i4 < 6; i4++) {
          d_loop_ub_tmp = 4 * i4 + 24 * i3;
          r5[d_loop_ub_tmp + 24 * r2->size[2] * i1] =
              (vehicle_corner_data[8 * obj_tmp +
                                   8 * vehicle_corner->size[2] * i1] >=
               NoEntryZone4_data[d_loop_ub_tmp +
                                 24 * NoEntryZone4->size[2] * i1]);
          r5[((4 * i4 + 24 * i3) + 24 * r2->size[2] * i1) + 1] =
              (vehicle_corner_data
                   [(8 * obj_tmp + 8 * vehicle_corner->size[2] * i1) + 1] >=
               NoEntryZone4_data[(4 * i4 + 24 * i3) +
                                 24 * NoEntryZone4->size[2] * i1]);
          r5[((4 * i4 + 24 * i3) + 24 * r2->size[2] * i1) + 2] =
              (vehicle_corner_data
                   [(8 * obj_tmp + 8 * vehicle_corner->size[2] * i1) + 2] >=
               NoEntryZone4_data[(4 * i4 + 24 * i3) +
                                 24 * NoEntryZone4->size[2] * i1]);
          r5[((4 * i4 + 24 * i3) + 24 * r2->size[2] * i1) + 3] =
              (vehicle_corner_data
                   [(8 * obj_tmp + 8 * vehicle_corner->size[2] * i1) + 3] >=
               NoEntryZone4_data[(4 * i4 + 24 * i3) +
                                 24 * NoEntryZone4->size[2] * i1]);
        }
      }
    }
  } else {
    st.site = &k_emlrtRSI;
    binary_expand_op_5(&st, r2, vehicle_corner, i, i1, NoEntryZone4);
  }
  emxInit_boolean_T(sp, &r3, 4, &ob_emlrtRTEI);
  if ((n == NoEntryZone4->size[2]) && (vehicle_corner->size[3] == 1000)) {
    i = r3->size[0] * r3->size[1] * r3->size[2] * r3->size[3];
    r3->size[0] = 4;
    r3->size[1] = 6;
    r3->size[2] = n;
    r3->size[3] = 1000;
    emxEnsureCapacity_boolean_T(sp, r3, i, &pb_emlrtRTEI);
    r4 = r3->data;
    for (i = 0; i < 1000; i++) {
      for (i1 = 0; i1 < n; i1++) {
        nx = i2 + i1;
        for (i3 = 0; i3 < 6; i3++) {
          obj_tmp = 4 * i3 + 24 * i1;
          r4[obj_tmp + 24 * r3->size[2] * i] =
              (vehicle_corner_data[8 * nx + 8 * vehicle_corner->size[2] * i] <=
               NoEntryZone4_data[(obj_tmp + 24 * NoEntryZone4->size[2] * i) +
                                 1]);
          r4[((4 * i3 + 24 * i1) + 24 * r3->size[2] * i) + 1] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i) +
                                   1] <=
               NoEntryZone4_data
                   [((4 * i3 + 24 * i1) + 24 * NoEntryZone4->size[2] * i) + 1]);
          r4[((4 * i3 + 24 * i1) + 24 * r3->size[2] * i) + 2] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i) +
                                   2] <=
               NoEntryZone4_data
                   [((4 * i3 + 24 * i1) + 24 * NoEntryZone4->size[2] * i) + 1]);
          r4[((4 * i3 + 24 * i1) + 24 * r3->size[2] * i) + 3] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i) +
                                   3] <=
               NoEntryZone4_data
                   [((4 * i3 + 24 * i1) + 24 * NoEntryZone4->size[2] * i) + 1]);
        }
      }
    }
  } else {
    st.site = &k_emlrtRSI;
    binary_expand_op_4(&st, r3, vehicle_corner, i2, nx, NoEntryZone4);
    r4 = r3->data;
  }
  if ((r2->size[2] != r3->size[2]) &&
      ((r2->size[2] != 1) && (r3->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r2->size[2], r3->size[2], &d_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (vehicle_corner->size[2] < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = vehicle_corner->size[2];
  }
  loop_ub = i1 - i;
  if ((loop_ub != NoEntryZone4->size[2]) &&
      ((loop_ub != 1) && (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, NoEntryZone4->size[2], &h_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((vehicle_corner->size[3] != 1000) && (vehicle_corner->size[3] != 1)) {
    emlrtDimSizeImpxCheckR2021b(vehicle_corner->size[3], 1000, &g_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (r2->size[2] == r3->size[2]) {
    d_loop_ub_tmp = 24 * r2->size[2] * 1000;
    i2 = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = 4;
    r2->size[1] = 6;
    r2->size[3] = 1000;
    emxEnsureCapacity_boolean_T(sp, r2, i2, &ob_emlrtRTEI);
    r5 = r2->data;
    for (i2 = 0; i2 < d_loop_ub_tmp; i2++) {
      r5[i2] = (r5[i2] && r4[i2]);
    }
  } else {
    st.site = &k_emlrtRSI;
    b_and(&st, r2, r3);
  }
  if ((loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] == 1000)) {
    i1 = r3->size[0] * r3->size[1] * r3->size[2] * r3->size[3];
    r3->size[0] = 4;
    r3->size[1] = 6;
    r3->size[2] = loop_ub;
    r3->size[3] = 1000;
    emxEnsureCapacity_boolean_T(sp, r3, i1, &qb_emlrtRTEI);
    r4 = r3->data;
    for (i1 = 0; i1 < 1000; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        nx = i + i2;
        for (i3 = 0; i3 < 6; i3++) {
          obj_tmp = 4 * i3 + 24 * i2;
          r4[obj_tmp + 24 * r3->size[2] * i1] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i1) +
                                   4] >=
               NoEntryZone4_data[(obj_tmp + 24 * NoEntryZone4->size[2] * i1) +
                                 2]);
          r4[((4 * i3 + 24 * i2) + 24 * r3->size[2] * i1) + 1] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i1) +
                                   5] >=
               NoEntryZone4_data[((4 * i3 + 24 * i2) +
                                  24 * NoEntryZone4->size[2] * i1) +
                                 2]);
          r4[((4 * i3 + 24 * i2) + 24 * r3->size[2] * i1) + 2] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i1) +
                                   6] >=
               NoEntryZone4_data[((4 * i3 + 24 * i2) +
                                  24 * NoEntryZone4->size[2] * i1) +
                                 2]);
          r4[((4 * i3 + 24 * i2) + 24 * r3->size[2] * i1) + 3] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i1) +
                                   7] >=
               NoEntryZone4_data[((4 * i3 + 24 * i2) +
                                  24 * NoEntryZone4->size[2] * i1) +
                                 2]);
        }
      }
    }
  } else {
    st.site = &ne_emlrtRSI;
    binary_expand_op_3(&st, r3, vehicle_corner, i, i1, NoEntryZone4);
    r4 = r3->data;
  }
  if ((r2->size[2] != r3->size[2]) &&
      ((r2->size[2] != 1) && (r3->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r2->size[2], r3->size[2], &d_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (vehicle_corner->size[2] < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = vehicle_corner->size[2];
  }
  loop_ub = i1 - i;
  if ((loop_ub != NoEntryZone4->size[2]) &&
      ((loop_ub != 1) && (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, NoEntryZone4->size[2], &f_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((vehicle_corner->size[3] != 1000) && (vehicle_corner->size[3] != 1)) {
    emlrtDimSizeImpxCheckR2021b(vehicle_corner->size[3], 1000, &e_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (r2->size[2] == r3->size[2]) {
    d_loop_ub_tmp = 24 * r2->size[2] * 1000;
    i2 = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = 4;
    r2->size[1] = 6;
    r2->size[3] = 1000;
    emxEnsureCapacity_boolean_T(sp, r2, i2, &ob_emlrtRTEI);
    r5 = r2->data;
    for (i2 = 0; i2 < d_loop_ub_tmp; i2++) {
      r5[i2] = (r5[i2] && r4[i2]);
    }
  } else {
    st.site = &k_emlrtRSI;
    b_and(&st, r2, r3);
    r5 = r2->data;
  }
  if ((loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] == 1000)) {
    i1 = r3->size[0] * r3->size[1] * r3->size[2] * r3->size[3];
    r3->size[0] = 4;
    r3->size[1] = 6;
    r3->size[2] = loop_ub;
    r3->size[3] = 1000;
    emxEnsureCapacity_boolean_T(sp, r3, i1, &rb_emlrtRTEI);
    r4 = r3->data;
    for (i1 = 0; i1 < 1000; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        nx = i + i2;
        for (i3 = 0; i3 < 6; i3++) {
          obj_tmp = 4 * i3 + 24 * i2;
          r4[obj_tmp + 24 * r3->size[2] * i1] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i1) +
                                   4] <=
               NoEntryZone4_data[(obj_tmp + 24 * NoEntryZone4->size[2] * i1) +
                                 3]);
          r4[((4 * i3 + 24 * i2) + 24 * r3->size[2] * i1) + 1] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i1) +
                                   5] <=
               NoEntryZone4_data[((4 * i3 + 24 * i2) +
                                  24 * NoEntryZone4->size[2] * i1) +
                                 3]);
          r4[((4 * i3 + 24 * i2) + 24 * r3->size[2] * i1) + 2] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i1) +
                                   6] <=
               NoEntryZone4_data[((4 * i3 + 24 * i2) +
                                  24 * NoEntryZone4->size[2] * i1) +
                                 3]);
          r4[((4 * i3 + 24 * i2) + 24 * r3->size[2] * i1) + 3] =
              (vehicle_corner_data[(8 * nx + 8 * vehicle_corner->size[2] * i1) +
                                   7] <=
               NoEntryZone4_data[((4 * i3 + 24 * i2) +
                                  24 * NoEntryZone4->size[2] * i1) +
                                 3]);
        }
      }
    }
  } else {
    st.site = &ne_emlrtRSI;
    binary_expand_op_2(&st, r3, vehicle_corner, i, i1, NoEntryZone4);
    r4 = r3->data;
  }
  emxFree_real_T(sp, &NoEntryZone4);
  emxFree_real_T(sp, &vehicle_corner);
  if ((r2->size[2] != r3->size[2]) &&
      ((r2->size[2] != 1) && (r3->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r2->size[2], r3->size[2], &d_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (r2->size[2] == r3->size[2]) {
    emxInit_boolean_T(sp, &r6, 4, &ob_emlrtRTEI);
    i = r6->size[0] * r6->size[1] * r6->size[2] * r6->size[3];
    r6->size[0] = 4;
    r6->size[1] = 6;
    r6->size[2] = r2->size[2];
    r6->size[3] = 1000;
    emxEnsureCapacity_boolean_T(sp, r6, i, &ob_emlrtRTEI);
    r7 = r6->data;
    d_loop_ub_tmp = 24 * r2->size[2] * 1000;
    for (i = 0; i < d_loop_ub_tmp; i++) {
      r7[i] = (r5[i] && r4[i]);
    }
    st.site = &k_emlrtRSI;
    any(&st, r6, remove_sample);
    emxFree_boolean_T(sp, &r6);
  } else {
    st.site = &k_emlrtRSI;
    binary_expand_op_1(&st, k_emlrtRSI, r2, r3, remove_sample);
  }
  emxFree_boolean_T(sp, &r3);
  emxFree_boolean_T(sp, &r2);
  emlrtMEXProfilingStatement(22, isMexOutdated);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, obj->NP, mxDOUBLE_CLASS,
                                (int32_T)obj->NP, &e_emlrtRTEI,
                                (emlrtConstCTX)sp);
  if (obj->NP - 1.0 >= 0.0) {
    i5 = (int32_T)(obj->K - 1.0);
    if ((int32_T)(obj->K - 1.0) - 1 >= 0) {
      b_loop_ub = preobs_size[1];
    }
    f_obj = (int32_T)(obj->K - 1.0);
  }
  emxInit_real_T(sp, &grade_temp, 1, &tb_emlrtRTEI);
  emxInit_real_T(sp, &a__1, 1, &yb_emlrtRTEI);
  if ((b_loop_ub_tmp - 1 >= 0) && (i5 - 1 >= 0)) {
    b_preobs_size[0] = preobs_size[1];
    b_preobs_size[1] = 6;
  }
  for (nx = 0; nx < b_loop_ub_tmp; nx++) {
    /*  確認用 */
    /*  parfor j = 1:obj.NP */
    emlrtMEXProfilingStatement(23, isMexOutdated);
    if (y_tmp != d) {
      emlrtIntegerCheckR2012b(y_tmp, &o_emlrtDCI, (emlrtConstCTX)sp);
    }
    i = grade_temp->size[0];
    grade_temp->size[0] = (int32_T)y_tmp;
    emxEnsureCapacity_real_T(sp, grade_temp, i, &tb_emlrtRTEI);
    B_data = grade_temp->data;
    if (y_tmp != d) {
      emlrtIntegerCheckR2012b(y_tmp, &o_emlrtDCI, (emlrtConstCTX)sp);
    }
    for (i = 0; i < loop_ub_tmp; i++) {
      B_data[i] = 0.0;
    }
    /*  remove_temp = false; */
    emlrtMEXProfilingStatement(24, isMexOutdated);
    if (y_tmp != d) {
      emlrtIntegerCheckR2012b(y_tmp, &emlrtDCI, (emlrtConstCTX)sp);
    }
    /*  wallcost_x_temp = zeros(obj.K-1,1); */
    /*  wallcost_y_temp = zeros(obj.K-1,1); */
    emlrtMEXProfilingStatement(25, isMexOutdated);
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, obj->K - 1.0, mxDOUBLE_CLASS,
                                  (int32_T)(obj->K - 1.0), &d_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (n = 0; n < i5; n++) {
      real_T b_preobs_data[180];
      /*             %% 壁面制約　1個前の壁面も含む */
      /*  ver.1 */
      /*              if any(vehicle_corner(:,1,i+1,j) < obj.limit(1,i+1,j) |
       * vehicle_corner(:,1,i+1,j) > obj.limit(2,i+1,j) |
       * vehicle_corner(:,2,i+1,j) < obj.limit(3,i+1,j) |
       * vehicle_corner(:,2,i+1,j) > obj.limit(4,i+1,j)) %壁面の考慮 */
      /*                  remove_temp = true; */
      /*              end */
      /*  ver.2 */
      /*              if any(vehicle_corner(:,1,i+1,j) <
       * obj.wall(obj.target_n(i+1,j)  ,1) | vehicle_corner(:,1,i+1,j) >
       * obj.wall(obj.target_n(i+1,j)  ,2) | vehicle_corner(:,2,i+1,j) <
       * obj.wall(obj.target_n(i+1,j)  ,3) | vehicle_corner(:,2,i+1,j) >
       * obj.wall(obj.target_n(i+1,j)  ,4)) &&... %壁面の考慮 */
      /*                 any(vehicle_corner(:,1,i+1,j) <
       * obj.wall(obj.target_n(i+1,j)-1,1) | vehicle_corner(:,1,i+1,j) >
       * obj.wall(obj.target_n(i+1,j)-1,2) | vehicle_corner(:,2,i+1,j) <
       * obj.wall(obj.target_n(i+1,j)-1,3) | vehicle_corner(:,2,i+1,j) >
       * obj.wall(obj.target_n(i+1,j)-1,4)) &&... */
      /*                 any(vehicle_corner(:,1,i+1,j) <
       * obj.wall(obj.target_n(i+1,j)+1,1) | vehicle_corner(:,1,i+1,j) >
       * obj.wall(obj.target_n(i+1,j)+1,2) | vehicle_corner(:,2,i+1,j) <
       * obj.wall(obj.target_n(i+1,j)+1,3) | vehicle_corner(:,2,i+1,j) >
       * obj.wall(obj.target_n(i+1,j)+1,4)) */
      /*                  remove_temp = true; */
      /*              end */
      /*  ver .3 */
      /*  全ての点が少なくとも1つの四角形内にあるか確認 */
      /*  insideWall1 = vehicle_corner(:,1,i+1,j) >=
       * obj.wall(obj.target_n(i+1,j)-1,1) & vehicle_corner(:,1,i+1,j) <=
       * obj.wall(obj.target_n(i+1,j)-1,2) & ... */
      /*                vehicle_corner(:,2,i+1,j) >=
       * obj.wall(obj.target_n(i+1,j)-1,3) & vehicle_corner(:,2,i+1,j) <=
       * obj.wall(obj.target_n(i+1,j)-1,4); */
      /*   */
      /*  insideWall2 = vehicle_corner(:,1,i+1,j) >=
       * obj.wall(obj.target_n(i+1,j)+1,1) & vehicle_corner(:,1,i+1,j) <=
       * obj.wall(obj.target_n(i+1,j)+1,2) & ... */
      /*                vehicle_corner(:,2,i+1,j) >=
       * obj.wall(obj.target_n(i+1,j)+1,3) & vehicle_corner(:,2,i+1,j) <=
       * obj.wall(obj.target_n(i+1,j)+1,4); */
      /*   */
      /*  insideWall3 = vehicle_corner(:,1,i+1,j) >=
       * obj.wall(obj.target_n(i+1,j)  ,1) & vehicle_corner(:,1,i+1,j) <=
       * obj.wall(obj.target_n(i+1,j)  ,2) & ... */
      /*                vehicle_corner(:,2,i+1,j) >=
       * obj.wall(obj.target_n(i+1,j)  ,3) & vehicle_corner(:,2,i+1,j) <=
       * obj.wall(obj.target_n(i+1,j)  ,4); */
      /*  いずれかの四角形内に各点があるか */
      /*  inside_any = insideWall1 | insideWall2 | insideWall3; */
      /*  if ~all(inside_any) */
      /*      remove_temp = true; */
      /*  end */
      /*  ver.4 */
      /*  if remove_temp == false */
      /*      Zone=obj.NoEntryZone{obj.selectZone(obj.target_n(i+1,j),1),1}; */
      /*      for k=1:size(Zone,1) */
      /*          if any(vehicle_corner(:,1,i+1,j) >=Zone(k,1) &
       * vehicle_corner(:,1,i+1,j) <= Zone(k,2) &... */
      /*                 vehicle_corner(:,2,i+1,j) >=Zone(k,3) &
       * vehicle_corner(:,2,i+1,j) <= Zone(k,4)) */
      /*              remove_temp = true; */
      /*              break */
      /*          end */
      /*      end */
      /*  end */
      /*  ver.5 */
      /*  if remove_temp == false */
      /*      Zone=obj.NoEntryZone(:,:,obj.selectZone(obj.target_n(i+1,j))); */
      /*      for k=1:obj.ZoneNum(obj.selectZone(obj.target_n(i+1,j))) */
      /*          if any(vehicle_corner(:,1,i+1,j) >=Zone(k,1) &
       * vehicle_corner(:,1,i+1,j) <= Zone(k,2) &... */
      /*                 vehicle_corner(:,2,i+1,j) >=Zone(k,3) &
       * vehicle_corner(:,2,i+1,j) <= Zone(k,4)) */
      /*              remove_temp = true; */
      /*              break */
      /*          end */
      /*      end */
      /*  end */
      /*  if remove_temp == true */
      /*      break */
      /*  end */
      /*             %% 壁面コスト */
      /*  wallcost_x_temp(i,1) =
       * max(obj.wall_penalty1*((vehicle_corner(:,1,i+1,j)-(obj.limit(2,i+1,j)-obj.wall_threshold)).*(vehicle_corner(:,1,i+1,j)>(obj.limit(2,i+1,j)-obj.wall_threshold)))
       * +
       * -obj.wall_penalty1*((vehicle_corner(:,1,i+1,j)+-1*(obj.limit(1,i+1,j)+obj.wall_threshold)).*((obj.limit(1,i+1,j)+obj.wall_threshold)>vehicle_corner(:,1,i+1,j)))
       * + obj.wall_penalty2*(vehicle_corner(:,1,i+1,j)>obj.limit(2,i+1,j) |
       * vehicle_corner(:,1,i+1,j)<obj.limit(1,i+1,j))); */
      /*  wallcost_y_temp(i,1) =
       * max(obj.wall_penalty1*((vehicle_corner(:,2,i+1,j)-(obj.limit(4,i+1,j)-obj.wall_threshold)).*(vehicle_corner(:,2,i+1,j)>(obj.limit(4,i+1,j)-obj.wall_threshold)))
       * +
       * -obj.wall_penalty1*((vehicle_corner(:,2,i+1,j)+-1*(obj.limit(3,i+1,j)+obj.wall_threshold)).*((obj.limit(3,i+1,j)+obj.wall_threshold)>vehicle_corner(:,2,i+1,j)))
       * + obj.wall_penalty2*(vehicle_corner(:,2,i+1,j)>obj.limit(4,i+1,j) |
       * vehicle_corner(:,2,i+1,j)<obj.limit(3,i+1,j))); */
      /*             %% */
      /* xmin xmax ymin ymax */
      /*             %% obstacle cost(only nearest) */
      /*              obsdis = -inf; */
      /*               */
      /*              for k=1:obj.ObsNum */
      /*                  obsdis_temp =
       * norm(preobs{i+2,1}(k,:)-[px(1,i+1,j),px(2,i+1,j)]); */
      /*                  if obsdis_temp > obsdis */
      /*                     obsdis = obsdis_temp; */
      /*                     nearest = k; */
      /*                  end */
      /*              end */
      /*  %             obscost_temp(i,1) = pu(1,i+1,j)^2/(abs(obsdis)+0.1); */
      /*              obscost_temp(i,1) = sqrt(((pu(1,i+1,j)^2)*sin(px(3,i+1,j))
       * - obj.VOBS(k,2))^2 + ((pu(1,i+1,j)^2)*cos(px(3,i+1,j)) -
       * obj.VOBS(k,1))^2)/(abs(obsdis)); */
      /* obstacle cost(all detection) */
      /*              if obj.ObsNum == 0 */
      /*                  obsdis = zeros(1,1); */
      /*                  obsdis = -inf; */
      /*              end */
      /*              obsdis = -inf; */
      /*              for k=1:obj.ObsNum */
      /*                  obsdis(k) =
       * norm(preobs{i+2,1}(k,:)-[px(1,i+1,j),px(2,i+1,j)]); */
      /*              end */
      /* probability */
      /*              k = 1; */
      /*              %i:horizon j:samples k:obsnum */
      /*              sig=obscov{1,1}{1,i}{1,k}([1 3],[1 3]); */
      /*              loc = px([1,2],i+1,j); */
      /*              Obsloc = obsstat{1,1}{1,i}{1,k}([1,3],:); */
      /*              vel =
       * [pu(1,i+1,j)*cos(px(3,i+1,j));pu(1,i+1,j)*sin(px(3,i+1,j))]; */
      /*              Obsvel = obsstat{1,1}{1,i}{1,k}([2,4],:); */
      /*  %
       * (norm(vel)*norm(Obsvel)-dot(vel,Obsvel))*exp((-1/2)*(loc-Obsloc)'*inv(sig)*(loc-Obsloc));
       */
      /*              (norm(vel)*norm(Obsvel)-dot(vel,Obsvel))*exp((-1/2)*(loc-Obsloc)'*(sig\(loc-Obsloc)));
       */
      /*             */
      /*  -- prob------------------------------------------------- */
      /*              prob = zeros(1,obj.ObsNum); */
      /*              obsprob = prob; */
      /*              if obscov{1,1}{1,1}{1,1}(1,1) == 0 */
      /*                  prob = 0; */
      /*                  obsprob = 0; */
      /*              else */
      /*                  for k=1:obj.ObsNum */
      /*                      sig=obscov{1,1}{1,i}{1,k}([1 3],[1 3]); */
      /*                      loc = px([1,2],i+1,j); */
      /*                      Obsloc = obsstat{1,1}{1,i}{1,k}([1,3],:); */
      /*                      vel =
       * [pu(1,i+1,j)*cos(px(3,i+1,j));pu(1,i+1,j)*sin(px(3,i+1,j))]; */
      /*                      Obsvel = obsstat{1,1}{1,i}{1,k}([2,4],:); */
      /*                      if norm(loc-Obsloc) */
      /*                          % loc_r =
       * move_point(Obsloc,loc,preobs{i,1}(k,5)); */
      /*  %                         prob(k) =
       * 1/(sqrt(det(sig)*(2*pi)^2))*exp((-1/2)*(loc_r)'*(sig\(loc_r))); */
      /*                          prob(k) = 1/(sqrt(det(sig)*(2*pi)^2)); */
      /*                      else */
      /*                          loc = move_point(loc,Obsloc,preobs{i,1}(k,5));
       */
      /*                          prob(k) =
       * 1/(sqrt(det(sig)*(2*pi)^2))*exp((-1/2)*(loc-Obsloc)'*(sig\(loc-Obsloc)));
       */
      /*                      end */
      /*  % %                     prob(k) =
       * 1/(sqrt(det(sig)*(2*pi)^2))*exp((-1/2)*(loc-Obsloc)'*(sig\(loc-Obsloc)));
       */
      /*                      obsprob(k) = (norm(vel)-dot(vel,Obsvel))*prob(k);
       */
      /*  %                     obsprob(k) =
       * (norm(vel)*norm(Obsvel))*exp((-1/2)*(loc-Obsloc)'*(sig\(loc-Obsloc)));
       */
      /*                  end */
      /*              end */
      /*   */
      /*              obscost_temp(i,1) = sum(obsprob); */
      /*  ------------------------------------------------------ */
      /*              obscost_temp(i,1) = sum(sqrt((obj.VOBS(1:obj.ObsNum,2) -
       * (repmat(pu(1,i+1,j),obj.ObsNum,1)).*sin(repmat(px(3,i+1,j),obj.ObsNum,1))).^2
       * + (obj.VOBS(1:obj.ObsNum,1) -
       * (repmat(pu(1,i+1,j),obj.ObsNum,1)).*cos(repmat(px(3,i+1,j),obj.ObsNum,1))).^2)./(abs(obsdis)'));
       */
      /*         %% FPM cost */
      /*  [~,grade_temp(i,1)] =
       * FPM_capsule_v2(obj,px(1,i+1,j),px(2,i+1,j),px(3,i+1,j),obsstat2{1,i}',obj.target(:,i+1,j)',param_FPM);
       */
      emlrtMEXProfilingStatement(26, isMexOutdated);
      if (((int32_T)((uint32_T)n + 1U) < 1) ||
          ((int32_T)((uint32_T)n + 1U) > 21)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 1U), 1, 21,
                                      &d_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)n + 2U) < 1) ||
          ((int32_T)((uint32_T)n + 2U) > 21)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1, 21,
                                      &c_emlrtBCI, (emlrtConstCTX)sp);
      }
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_preobs_data[i1 + b_preobs_size[0] * i] =
              preobs_data[(i + 6 * i1) + 6 * preobs_size[1] * n];
        }
      }
      if (((int32_T)((uint32_T)n + 2U) < 1) ||
          ((int32_T)((uint32_T)n + 2U) > 21)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1, 21,
                                      &i_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)nx + 1U) < 1) ||
          ((int32_T)((uint32_T)nx + 1U) > 1000)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)nx + 1U), 1, 1000,
                                      &j_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)n + 2U) < 1) ||
          ((int32_T)((uint32_T)n + 2U) > 21)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1, 21,
                                      &k_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)n + 1U) < 1) ||
          ((int32_T)((uint32_T)n + 1U) > grade_temp->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 1U), 1,
                                      grade_temp->size[0], &l_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      st.site = &l_emlrtRSI;
      B_data[n] = FPM_capsule_v3_1(
          &st, obj->ObsNum, obj->wheel_width, obj->wheel_len_front,
          px[3 * (n + 1) + 63 * nx], px[(3 * (n + 1) + 63 * nx) + 1],
          px[(3 * (n + 1) + 63 * nx) + 2], b_preobs_data, b_preobs_size,
          &obj->target[((n + 1) << 1) + 42 * nx], param_FPM->eta,
          param_FPM->alpha, param_FPM->margin, param_FPM->obs_cost, a__1);
      emlrtMEXProfilingStatement(27, isMexOutdated);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    /*         %% velocity cost */
    emlrtMEXProfilingStatement(28, isMexOutdated);
    if ((nx + 1 < 1) || (nx + 1 > 1000)) {
      emlrtDynamicBoundsCheckR2012b(nx + 1, 1, 1000, &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    d1 = pu[42 * nx];
    if (((int32_T)((uint32_T)nx + 1U) < 1) ||
        ((int32_T)((uint32_T)nx + 1U) > vcost->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)nx + 1U), 1,
                                    vcost->size[1], &h_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    vcost_data[nx] = (d1 - 0.55) * 5000.0 * (real_T)(d1 > 0.55) +
                     (d1 + 0.25) * -5000.0 * (real_T)(d1 < -0.25);
    /*         %% wall cost */
    /*  wallcost_x_temp(isnan(wallcost_x_temp)) = 0; */
    /*  wallcost_y_temp(isnan(wallcost_y_temp)) = 0; */
    /*  wallcost(:,j) = wallcost_x_temp + wallcost_y_temp; */
    emlrtMEXProfilingStatement(29, isMexOutdated);
    if ((nx + 1 < 1) || (nx + 1 > b_loop_ub_tmp)) {
      emlrtDynamicBoundsCheckR2012b(nx + 1, 1, b_loop_ub_tmp, &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    emlrtSubAssignSizeCheckR2012b(&loop_ub_tmp, 1, &grade_temp->size[0], 1,
                                  &c_emlrtECI, (emlrtCTX)sp);
    for (i = 0; i < loop_ub_tmp; i++) {
      grade_data[i + grade->size[0] * nx] = B_data[i];
    }
    /*  remove_sample(1,j) = remove_temp; */
    emlrtMEXProfilingStatement(30, isMexOutdated);
    emlrtSubAssignSizeCheckR2012b(&loop_ub_tmp, 1, &f_obj, 1, &b_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < loop_ub_tmp; i++) {
      obscost_data[i + obscost->size[0] * nx] = 0.0;
    }
    emlrtMEXProfilingStatement(31, isMexOutdated);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &a__1);
  emxFree_real_T(sp, &grade_temp);
  emlrtMEXProfilingStatement(32, isMexOutdated);
  /*      tocBytes(gcp);obscov */
  emlrtMEXProfilingStatement(33, isMexOutdated);
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)(obj->K - 1.0);
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &sb_emlrtRTEI);
  B_data = r->data;
  nx = (c_loop_ub_tmp / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&grade_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_sub_pd(_mm_set1_pd(1.0), r1));
  }
  for (i = nx; i < c_loop_ub_tmp; i++) {
    B_data[i] = 1.0 - grade_data[i];
  }
  emxFree_real_T(sp, &grade);
  st.site = &m_emlrtRSI;
  sum(&st, r, pw);
  emxFree_real_T(sp, &r);
  emlrtMEXProfilingStatement(34, isMexOutdated);
  for (nx = 0; nx < 20000; nx++) {
    y_tmp = pu[(((nx % 20) << 1) + 42 * (nx / 20)) + 1];
    SD->f0.y[nx] = y_tmp * y_tmp;
  }
  for (i = 0; i < 1000; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      SD->f0.a[i1 + 20 * i] = pu[(i1 << 1) + 42 * i] - obj->Vref;
    }
  }
  for (nx = 0; nx <= 19998; nx += 2) {
    r1 = _mm_loadu_pd(&SD->f0.a[nx]);
    _mm_storeu_pd(&y[nx], _mm_mul_pd(r1, r1));
  }
  dv[0] = 1.0;
  dv[1] = obj->NP;
  st.site = &n_emlrtRSI;
  b_st.site = &ie_emlrtRSI;
  b_assertValidSizeArg(&b_st, dv);
  if (obj->NP > 1000.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (obj->NP != 1000.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  /*      Turningcost =
   * reshape(sum((pu(1,1:end-1,:).*pu(2,1:end-1,:)).^2),[1,obj.NP])*obj.W; */
  emlrtMEXProfilingStatement(35, isMexOutdated);
  emxInit_real_T(sp, &OBScost, 2, &ub_emlrtRTEI);
  st.site = &o_emlrtRSI;
  sum(&st, obscost, OBScost);
  emxFree_real_T(sp, &obscost);
  i = OBScost->size[0] * OBScost->size[1];
  OBScost->size[0] = 1;
  emxEnsureCapacity_real_T(sp, OBScost, i, &ub_emlrtRTEI);
  B_data = OBScost->data;
  loop_ub = OBScost->size[1] - 1;
  nx = (OBScost->size[1] / 2) << 1;
  n = nx - 2;
  for (i = 0; i <= n; i += 2) {
    r1 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&B_data[i], _mm_mul_pd(_mm_set1_pd(obj->Wo), r1));
  }
  for (i = nx; i <= loop_ub; i++) {
    B_data[i] *= obj->Wo;
  }
  /*  WALLcost = 0.5*sum(wallcost); */
  /*  pw = FPMcost + Inputcost + OBScost + vcost + WALLcost; */
  emlrtMEXProfilingStatement(36, isMexOutdated);
  if ((pw->size[1] != (int32_T)obj->NP) &&
      ((pw->size[1] != 1) && (obj->NP != 1.0))) {
    emlrtDimSizeImpxCheckR2021b(pw->size[1], (int32_T)obj->NP, &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  b_sum(SD->f0.y, dv1);
  b_sum(y, dv2);
  if (pw->size[1] == (int32_T)obj->NP) {
    c_obj = obj->R[1];
    y_tmp = obj->R[0];
    loop_ub = pw->size[1] - 1;
    i = pw->size[0] * pw->size[1];
    pw->size[0] = 1;
    emxEnsureCapacity_real_T(sp, pw, i, &vb_emlrtRTEI);
    NoEntryZone4_data = pw->data;
    nx = (pw->size[1] / 2) << 1;
    n = nx - 2;
    for (i = 0; i <= n; i += 2) {
      __m128d r9;
      r1 = _mm_loadu_pd(&dv1[i]);
      r8 = _mm_loadu_pd(&dv2[i]);
      r9 = _mm_loadu_pd(&NoEntryZone4_data[i]);
      _mm_storeu_pd(
          &NoEntryZone4_data[i],
          _mm_add_pd(r9, _mm_add_pd(_mm_mul_pd(r1, _mm_set1_pd(c_obj)),
                                    _mm_mul_pd(r8, _mm_set1_pd(y_tmp)))));
    }
    for (i = nx; i <= loop_ub; i++) {
      NoEntryZone4_data[i] += dv1[i] * c_obj + dv2[i] * y_tmp;
    }
  } else {
    st.site = &je_emlrtRSI;
    binary_expand_op(&st, pw, dv1, obj, dv2, dv);
  }
  if ((pw->size[1] != OBScost->size[1]) &&
      ((pw->size[1] != 1) && (OBScost->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(pw->size[1], OBScost->size[1], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (pw->size[1] == OBScost->size[1]) {
    loop_ub = pw->size[1] - 1;
    i = pw->size[0] * pw->size[1];
    pw->size[0] = 1;
    emxEnsureCapacity_real_T(sp, pw, i, &vb_emlrtRTEI);
    NoEntryZone4_data = pw->data;
    nx = (pw->size[1] / 2) << 1;
    n = nx - 2;
    for (i = 0; i <= n; i += 2) {
      r1 = _mm_loadu_pd(&NoEntryZone4_data[i]);
      r8 = _mm_loadu_pd(&B_data[i]);
      _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r1, r8));
    }
    for (i = nx; i <= loop_ub; i++) {
      NoEntryZone4_data[i] += B_data[i];
    }
  } else {
    st.site = &je_emlrtRSI;
    plus(&st, pw, OBScost);
  }
  emxFree_real_T(sp, &OBScost);
  if ((pw->size[1] != vcost->size[1]) &&
      ((pw->size[1] != 1) && (vcost->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(pw->size[1], vcost->size[1], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (pw->size[1] == vcost->size[1]) {
    loop_ub = pw->size[1] - 1;
    i = pw->size[0] * pw->size[1];
    pw->size[0] = 1;
    emxEnsureCapacity_real_T(sp, pw, i, &wb_emlrtRTEI);
    NoEntryZone4_data = pw->data;
    nx = (pw->size[1] / 2) << 1;
    n = nx - 2;
    for (i = 0; i <= n; i += 2) {
      r1 = _mm_loadu_pd(&NoEntryZone4_data[i]);
      r8 = _mm_loadu_pd(&vcost_data[i]);
      _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r1, r8));
    }
    for (i = nx; i <= loop_ub; i++) {
      NoEntryZone4_data[i] += vcost_data[i];
    }
  } else {
    st.site = &je_emlrtRSI;
    plus(&st, pw, vcost);
  }
  emxFree_real_T(sp, &vcost);
  emlrtMEXProfilingStatement(37, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (EvaluationPath.c) */
