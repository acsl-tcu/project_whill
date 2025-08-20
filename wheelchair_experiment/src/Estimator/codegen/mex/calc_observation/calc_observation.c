/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_observation.c
 *
 * Code generation for function 'calc_observation'
 *
 */

/* Include files */
#include "calc_observation.h"
#include "calc_observation_data.h"
#include "calc_observation_emxutil.h"
#include "calc_observation_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_rand.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "handle.h"
#include "hypot.h"
#include "mean.h"
#include "norm.h"
#include "pcfitellipse.h"
#include "pcfitptCOG.h"
#include "pointCloud.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static int32_T threadID;
#pragma omp threadprivate(threadID)

static emlrtRSInfo emlrtRSI = {
    77,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    68,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    55,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    42,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    41,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    39,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    34,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    32,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    27,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    6,                  /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    24,                 /* lineNo */
    "calc_observation", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/max.m" /* pathName
                                                                     */
};

static emlrtRSInfo yb_emlrtRSI = {
    64,         /* lineNo */
    "minOrMax", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo ac_emlrtRSI = {
    99,        /* lineNo */
    "maximum", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo bc_emlrtRSI =
    {
        255,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI =
    {
        966,                    /* lineNo */
        "maxRealVectorOmitNaN", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    73,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    65,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    114,         /* lineNo */
    "findFirst", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    131,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    65,         /* lineNo */
    "cat_impl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                       */
};

static emlrtBCInfo emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    70,                 /* lineNo */
    20,                 /* colNo */
    "model1",           /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    68,                 /* lineNo */
    56,                 /* colNo */
    "Xhbar_observed",   /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    64,                 /* lineNo */
    20,                 /* colNo */
    "model1",           /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,                 /* nDims */
    62,                 /* lineNo */
    17,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                   /* iFirst */
    2000,                /* iLast */
    62,                  /* lineNo */
    37,                  /* colNo */
    "inlierpoints_full", /* aName */
    "calc_observation",  /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    57,                       /* lineNo */
    42,                       /* colNo */
    "Xhbar_observed_ellipse", /* aName */
    "calc_observation",       /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    45,                       /* lineNo */
    44,                       /* colNo */
    "Xhbar_observed_ellipse", /* aName */
    "calc_observation",       /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    -1,                 /* nDims */
    34,                 /* lineNo */
    42,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI =
    {
        198,             /* lineNo */
        27,              /* colNo */
        "unaryMinOrMax", /* fName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    8,                  /* lineNo */
    5,                  /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    1                               /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    8,                  /* lineNo */
    5,                  /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    4                               /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    26,                 /* lineNo */
    35,                 /* colNo */
    "assignment",       /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    27,                 /* lineNo */
    43,                 /* colNo */
    "ObsptClouds",      /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    39,                       /* lineNo */
    72,                       /* colNo */
    "Xhbar_observed_ellipse", /* aName */
    "calc_observation",       /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    39,                       /* lineNo */
    121,                      /* colNo */
    "Xhbar_observed_ellipse", /* aName */
    "calc_observation",       /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    41,                 /* lineNo */
    39,                 /* colNo */
    "ptPedestrian",     /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    41,                 /* lineNo */
    60,                 /* colNo */
    "ptPedestrian",     /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    67,                 /* lineNo */
    25,                 /* colNo */
    "isObserved1",      /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    43,                 /* lineNo */
    25,                 /* colNo */
    "isObserved1",      /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    71,                 /* lineNo */
    20,                 /* colNo */
    "model1",           /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    56,                      /* lineNo */
    77,                      /* colNo */
    "Pbar_observed_ellipse", /* aName */
    "calc_observation",      /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    55,                 /* lineNo */
    14,                 /* colNo */
    "model1",           /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    20,                 /* colNo */
    "model1",           /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    34,                 /* lineNo */
    42,                 /* colNo */
    "meas.Location",    /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    69,                 /* lineNo */
    13,                 /* colNo */
    "model1",           /* aName */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m", /* pName */
    0                               /* checkKind */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    8,                  /* lineNo */
    5,                  /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    1,                  /* lineNo */
    32,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    27,                 /* lineNo */
    27,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    36,                 /* lineNo */
    13,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    34,                 /* lineNo */
    68,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    39,                 /* lineNo */
    27,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    39,                 /* lineNo */
    76,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    40,                 /* lineNo */
    9,                  /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    34,                 /* lineNo */
    43,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    34,                 /* lineNo */
    121,                /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    41,                 /* lineNo */
    9,                  /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    34,                 /* lineNo */
    96,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    34,                 /* lineNo */
    13,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    39,                 /* lineNo */
    9,                  /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    27,                 /* lineNo */
    9,                  /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    34,                 /* lineNo */
    42,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    41,                 /* lineNo */
    39,                 /* colNo */
    "calc_observation", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/calc_observation.m" /* pName */
};

/* Function Definitions */
void calc_observation(const emlrtStack *sp, const struct0_T *RANSAC,
                      real_T numAssignments, const uint32_T assignment_data[],
                      const int32_T assignment_size[2],
                      const real_T Xhbar_observed_ellipse_data[],
                      const int32_T Xhbar_observed_ellipse_size[2],
                      const cell_wrap_0 Pbar_observed_ellipse_data[],
                      const int32_T Pbar_observed_ellipse_size[1],
                      const emxArray_real_T *ObsptClouds, real_T doRANSAC,
                      const real_T R[25], const real_T Xhbar_observed_data[],
                      const int32_T Xhbar_observed_size[2],
                      const real_T trans[3], const struct1_T *Plant,
                      emxArray_real_T *isObserved, emxArray_struct2_T *model1)
{
  __m128d r5;
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack st;
  emxArray_boolean_T *idx;
  emxArray_boolean_T *r4;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_real_T *b_ObsptClouds;
  emxArray_real_T *b_ptPedestrian;
  emxArray_real_T *c_ptPedestrian;
  emxArray_real_T *distances;
  emxArray_real_T *inlierpoints;
  emxArray_real_T *points;
  emxArray_real_T *ptPedestrian;
  pointCloud b_meas;
  pointCloud meas;
  struct2_T *model1_data;
  real_T inlierpoints_full[4000];
  real_T a__3[25];
  real_T dv2[6];
  real_T a0[5];
  real_T dv[5];
  real_T lb[5];
  real_T ub[5];
  real_T dv1[3];
  real_T a__4[2];
  real_T cog[2];
  const real_T *ObsptClouds_data;
  real_T B;
  real_T MD_threshold;
  real_T MSANum;
  real_T TrialNum;
  real_T a__1;
  real_T confDegree;
  real_T eta;
  real_T maxDistance;
  real_T r_removelegCluster;
  real_T sampleSize;
  real_T selectedArea;
  real_T tth;
  real_T *b_ptPedestrian_data;
  real_T *distances_data;
  real_T *isObserved_data;
  real_T *ptPedestrian_data;
  int32_T b_inlierpoints[2];
  int32_T b_i;
  int32_T b_idx;
  int32_T b_loop_ub;
  int32_T c_i;
  int32_T calc_observation_numThreads;
  int32_T i;
  int32_T last;
  int32_T loop_ub;
  int32_T *r1;
  uint32_T detectionIdx;
  int16_T b_tmp_data[5000];
  int16_T i1;
  boolean_T tmp_data[5000];
  boolean_T x[2];
  boolean_T emlrtHadParallelError = false;
  boolean_T exitg1;
  boolean_T y;
  boolean_T *idx_data;
  boolean_T *r;
  st.prev = sp;
  st.tls = sp->tls;
  ObsptClouds_data = ObsptClouds->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud(sp, &meas, &ub_emlrtRTEI);
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &meas,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  meas.matlabCodegenIsDeleted = true;
  /*     %% MEX & 並列化用の変数作成 */
  /*  各モデルの観測値の構造体 */
  st.site = &j_emlrtRSI;
  repmat(&st, numAssignments, model1);
  model1_data = model1->data;
  /*  Ellipse model */
  /*  観測判定 */
  if (!(numAssignments >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numAssignments, &b_emlrtDCI, (emlrtConstCTX)sp);
  }
  sampleSize = (int32_T)muDoubleScalarFloor(numAssignments);
  if (numAssignments != sampleSize) {
    emlrtIntegerCheckR2012b(numAssignments, &emlrtDCI, (emlrtConstCTX)sp);
  }
  i = isObserved->size[0];
  loop_ub = (int32_T)numAssignments;
  isObserved->size[0] = (int32_T)numAssignments;
  emxEnsureCapacity_real_T(sp, isObserved, i, &gb_emlrtRTEI);
  isObserved_data = isObserved->data;
  if (numAssignments != sampleSize) {
    emlrtIntegerCheckR2012b(numAssignments, &emlrtDCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    isObserved_data[i] = 0.0;
  }
  /*  Ellipse model */
  /*  ransacに使う変数を構造体から解体 */
  sampleSize = RANSAC->sampleSize;
  maxDistance = RANSAC->maxDistance;
  TrialNum = RANSAC->TrialNum;
  confDegree = RANSAC->confDegree;
  B = RANSAC->B;
  tth = RANSAC->tth;
  MD_threshold = RANSAC->MD_threshold;
  MSANum = RANSAC->MSANum;
  selectedArea = RANSAC->selectedArea;
  eta = RANSAC->eta;
  /*     %% 観測値の計算 */
  loop_ub = assignment_size[0];
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  if (!omp_in_parallel()) {
    c_st.site = &k_emlrtRSI;
    c_eml_rand_mt19937ar_stateful_s(true);
    c_st.site = &k_emlrtRSI;
    eml_rand_swap();
  }
  calc_observation_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(calc_observation_numThreads) private(         \
        ptPedestrian_data, distances_data, idx_data, r, r1,                    \
            b_ptPedestrian_data, r2, ptPedestrian, b_ptPedestrian, r3, r4,     \
            b_ObsptClouds, b_meas, c_ptPedestrian, distances, idx, points,     \
            inlierpoints, a__4, cog, inlierpoints_full, a__3,                  \
            r_removelegCluster, a__1, dv, ub, lb, a0, detectionIdx,            \
            emlrtJBEnviron, k_st, b_loop_ub, b_idx, c_i, tmp_data, last,       \
            b_tmp_data, i1, dv1, r5, dv2, x, y, exitg1, b_inlierpoints)        \
    firstprivate(b_st, c_st, d_st, e_st, f_st, g_st, h_st, i_st, j_st,         \
                     emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {
      b_st.prev = sp;
      b_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      b_st.site = NULL;
      emlrtSetJmpBuf(&b_st, &emlrtJBEnviron);
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
      k_st.prev = &j_st;
      k_st.tls = j_st.tls;
      emxInit_int32_T(&b_st, &r2, &wb_emlrtRTEI);
      emxInit_real_T(&b_st, &ptPedestrian, 1, &mb_emlrtRTEI);
      emxInit_real_T(&b_st, &b_ptPedestrian, 1, &lb_emlrtRTEI);
      emxInit_int32_T(&b_st, &r3, &vb_emlrtRTEI);
      emxInit_boolean_T(&b_st, &r4, &vb_emlrtRTEI);
      emxInit_real_T(&b_st, &b_ObsptClouds, 2, &ib_emlrtRTEI);
      emxInitStruct_pointCloud(&b_st, &b_meas, &ub_emlrtRTEI);
      emxInit_real_T(&b_st, &c_ptPedestrian, 2, &sb_emlrtRTEI);
      emxInit_real_T(&b_st, &distances, 1, &tb_emlrtRTEI);
      emxInit_boolean_T(&b_st, &idx, &nb_emlrtRTEI);
      emxInit_real_T(&b_st, &points, 2, &qb_emlrtRTEI);
      emxInit_real_T(&b_st, &inlierpoints, 2, &hb_emlrtRTEI);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (emlrtHadParallelError) {
        continue;
      }
      if (setjmp(emlrtJBEnviron) == 0) {
        /*  for i = 1:size(assignment,1) */
        if (b_i + 1 > assignment_size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, assignment_size[0],
                                        &g_emlrtBCI, &b_st);
        }
        detectionIdx = assignment_data[b_i + assignment_size[0]];
        b_loop_ub = ObsptClouds->size[1];
        b_idx = ObsptClouds->size[1];
        for (c_i = 0; c_i < b_loop_ub; c_i++) {
          tmp_data[c_i] = (ObsptClouds_data[4 * c_i + 3] == detectionIdx);
        }
        b_loop_ub = 0;
        last = 0;
        for (c_i = 0; c_i < b_idx; c_i++) {
          if (tmp_data[c_i]) {
            b_loop_ub++;
            b_tmp_data[last] = (int16_T)c_i;
            last++;
          }
        }
        c_i = b_ObsptClouds->size[0] * b_ObsptClouds->size[1];
        b_ObsptClouds->size[0] = b_loop_ub;
        b_ObsptClouds->size[1] = 3;
        emxEnsureCapacity_real_T(&b_st, b_ObsptClouds, c_i, &ib_emlrtRTEI);
        distances_data = b_ObsptClouds->data;
        for (c_i = 0; c_i < 3; c_i++) {
          for (b_idx = 0; b_idx < b_loop_ub; b_idx++) {
            i1 = b_tmp_data[b_idx];
            if ((i1 < 0) || (i1 > ObsptClouds->size[1] - 1)) {
              emlrtDynamicBoundsCheckR2012b(i1, 0, ObsptClouds->size[1] - 1,
                                            &h_emlrtBCI, &b_st);
            }
            distances_data[b_idx + b_ObsptClouds->size[0] * c_i] =
                ObsptClouds_data[c_i + 4 * i1];
          }
        }
        c_st.site = &i_emlrtRSI;
        pointCloud_pointCloud(&c_st, &b_meas, b_ObsptClouds);
        /*  対応付けインデックスと障害物点群ラベルが対応する点群を取得 */
        /*  Ellipse model */
        /*  ptPedestrian = removeleg(meas.Location,trans); %
         * RANSAC精度悪化防止のため脚点群除去 */
        r_removelegCluster = trans[2] / 0.2679491924311227;
        /*  LiDARの高さ/LiDARの垂直視野角15度 */
        c_st.site = &h_emlrtRSI;
        mean(&c_st, b_meas.Location, dv1);
        r5 = _mm_loadu_pd(&trans[0]);
        _mm_storeu_pd(&dv2[0], _mm_sub_pd(_mm_set1_pd(dv1[0]), r5));
        _mm_storeu_pd(&dv2[2], _mm_sub_pd(_mm_set1_pd(dv1[1]), r5));
        _mm_storeu_pd(&dv2[4], _mm_sub_pd(_mm_set1_pd(dv1[2]), r5));
        c_st.site = &h_emlrtRSI;
        if (b_norm(&c_st, dv2) >= r_removelegCluster) {
          /*  3 [m] */
          /*  体の45%が脚，上10cmが頭としてそれらを除去 */
          c_st.site = &g_emlrtRSI;
          c_i = distances->size[0];
          distances->size[0] = b_meas.Location->size[0];
          emxEnsureCapacity_real_T(&c_st, distances, c_i, &kb_emlrtRTEI);
          distances_data = distances->data;
          b_loop_ub = b_meas.Location->size[0];
          for (c_i = 0; c_i < b_loop_ub; c_i++) {
            distances_data[c_i] =
                b_meas.Location->data[c_i + b_meas.Location->size[0] * 2];
          }
          d_st.site = &xb_emlrtRSI;
          e_st.site = &yb_emlrtRSI;
          f_st.site = &ac_emlrtRSI;
          if (distances->size[0] < 1) {
            emlrtErrorWithMessageIdR2018a(
                &f_st, &c_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
                "Coder:toolbox:eml_min_or_max_varDimZero", 0);
          }
          g_st.site = &bc_emlrtRSI;
          h_st.site = &cc_emlrtRSI;
          last = distances->size[0];
          if (distances->size[0] <= 2) {
            if (distances->size[0] == 1) {
              r_removelegCluster = distances_data[0];
            } else if ((distances_data[0] < distances_data[1]) ||
                       (muDoubleScalarIsNaN(distances_data[0]) &&
                        (!muDoubleScalarIsNaN(distances_data[1])))) {
              r_removelegCluster = distances_data[1];
            } else {
              r_removelegCluster = distances_data[0];
            }
          } else {
            i_st.site = &ec_emlrtRSI;
            if (!muDoubleScalarIsNaN(distances_data[0])) {
              b_idx = 1;
            } else {
              b_idx = 0;
              j_st.site = &fc_emlrtRSI;
              if (distances->size[0] > 2147483646) {
                k_st.site = &u_emlrtRSI;
                check_forloop_overflow_error(&k_st);
              }
              c_i = 2;
              exitg1 = false;
              while ((!exitg1) && (c_i <= last)) {
                if (!muDoubleScalarIsNaN(distances_data[c_i - 1])) {
                  b_idx = c_i;
                  exitg1 = true;
                } else {
                  c_i++;
                }
              }
            }
            if (b_idx == 0) {
              r_removelegCluster = distances_data[0];
            } else {
              i_st.site = &dc_emlrtRSI;
              r_removelegCluster = distances_data[b_idx - 1];
              b_loop_ub = b_idx + 1;
              j_st.site = &gc_emlrtRSI;
              if ((b_idx + 1 <= distances->size[0]) &&
                  (distances->size[0] > 2147483646)) {
                k_st.site = &u_emlrtRSI;
                check_forloop_overflow_error(&k_st);
              }
              for (c_i = b_loop_ub; c_i <= last; c_i++) {
                if (r_removelegCluster < distances_data[c_i - 1]) {
                  r_removelegCluster = distances_data[c_i - 1];
                }
              }
            }
          }
          r_removelegCluster *= 0.45;
          c_i = idx->size[0];
          idx->size[0] = b_meas.Location->size[0];
          emxEnsureCapacity_boolean_T(&b_st, idx, c_i, &ob_emlrtRTEI);
          idx_data = idx->data;
          b_loop_ub = b_meas.Location->size[0];
          for (c_i = 0; c_i < b_loop_ub; c_i++) {
            idx_data[c_i] =
                (b_meas.Location->data[c_i + b_meas.Location->size[0] * 2] >
                 r_removelegCluster);
          }
          c_st.site = &g_emlrtRSI;
          c_i = distances->size[0];
          distances->size[0] = b_meas.Location->size[0];
          emxEnsureCapacity_real_T(&c_st, distances, c_i, &pb_emlrtRTEI);
          distances_data = distances->data;
          b_loop_ub = b_meas.Location->size[0];
          for (c_i = 0; c_i < b_loop_ub; c_i++) {
            distances_data[c_i] =
                b_meas.Location->data[c_i + b_meas.Location->size[0] * 2];
          }
          d_st.site = &xb_emlrtRSI;
          e_st.site = &yb_emlrtRSI;
          f_st.site = &ac_emlrtRSI;
          if (distances->size[0] < 1) {
            emlrtErrorWithMessageIdR2018a(
                &f_st, &c_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
                "Coder:toolbox:eml_min_or_max_varDimZero", 0);
          }
          g_st.site = &bc_emlrtRSI;
          h_st.site = &cc_emlrtRSI;
          last = distances->size[0];
          if (distances->size[0] <= 2) {
            if (distances->size[0] == 1) {
              r_removelegCluster = distances_data[0];
            } else if ((distances_data[0] < distances_data[1]) ||
                       (muDoubleScalarIsNaN(distances_data[0]) &&
                        (!muDoubleScalarIsNaN(distances_data[1])))) {
              r_removelegCluster = distances_data[1];
            } else {
              r_removelegCluster = distances_data[0];
            }
          } else {
            i_st.site = &ec_emlrtRSI;
            if (!muDoubleScalarIsNaN(distances_data[0])) {
              b_idx = 1;
            } else {
              b_idx = 0;
              j_st.site = &fc_emlrtRSI;
              if (distances->size[0] > 2147483646) {
                k_st.site = &u_emlrtRSI;
                check_forloop_overflow_error(&k_st);
              }
              c_i = 2;
              exitg1 = false;
              while ((!exitg1) && (c_i <= last)) {
                if (!muDoubleScalarIsNaN(distances_data[c_i - 1])) {
                  b_idx = c_i;
                  exitg1 = true;
                } else {
                  c_i++;
                }
              }
            }
            if (b_idx == 0) {
              r_removelegCluster = distances_data[0];
            } else {
              i_st.site = &dc_emlrtRSI;
              r_removelegCluster = distances_data[b_idx - 1];
              b_loop_ub = b_idx + 1;
              j_st.site = &gc_emlrtRSI;
              if ((b_idx + 1 <= distances->size[0]) &&
                  (distances->size[0] > 2147483646)) {
                k_st.site = &u_emlrtRSI;
                check_forloop_overflow_error(&k_st);
              }
              for (c_i = b_loop_ub; c_i <= last; c_i++) {
                if (r_removelegCluster < distances_data[c_i - 1]) {
                  r_removelegCluster = distances_data[c_i - 1];
                }
              }
            }
          }
          c_i = r4->size[0];
          r4->size[0] = b_meas.Location->size[0];
          emxEnsureCapacity_boolean_T(&b_st, r4, c_i, &rb_emlrtRTEI);
          r = r4->data;
          b_loop_ub = b_meas.Location->size[0];
          for (c_i = 0; c_i < b_loop_ub; c_i++) {
            r[c_i] =
                (b_meas.Location->data[c_i + b_meas.Location->size[0] * 2] <
                 r_removelegCluster - 0.1);
          }
          if (idx->size[0] != r4->size[0]) {
            emlrtSizeEqCheck1DR2012b(idx->size[0], r4->size[0], &b_emlrtECI,
                                     &b_st);
          }
          b_idx = idx->size[0];
          b_loop_ub = 0;
          for (c_i = 0; c_i < b_idx; c_i++) {
            if (idx_data[c_i] && r[c_i]) {
              b_loop_ub++;
            }
          }
          c_i = r3->size[0];
          r3->size[0] = b_loop_ub;
          emxEnsureCapacity_int32_T(&b_st, r3, c_i, &hb_emlrtRTEI);
          r1 = r3->data;
          last = 0;
          for (c_i = 0; c_i < b_idx; c_i++) {
            if (idx_data[c_i] && r[c_i]) {
              r1[last] = c_i;
              last++;
            }
          }
          last = b_meas.Location->size[0];
          b_loop_ub = r3->size[0];
          c_i = c_ptPedestrian->size[0] * c_ptPedestrian->size[1];
          c_ptPedestrian->size[0] = r3->size[0];
          c_ptPedestrian->size[1] = 3;
          emxEnsureCapacity_real_T(&b_st, c_ptPedestrian, c_i, &sb_emlrtRTEI);
          ptPedestrian_data = c_ptPedestrian->data;
          for (c_i = 0; c_i < 3; c_i++) {
            for (b_idx = 0; b_idx < b_loop_ub; b_idx++) {
              if ((r1[b_idx] < 0) || (r1[b_idx] > last - 1)) {
                emlrtDynamicBoundsCheckR2012b(r1[b_idx], 0, last - 1,
                                              &s_emlrtBCI, &b_st);
              }
              ptPedestrian_data[b_idx + c_ptPedestrian->size[0] * c_i] =
                  b_meas.Location
                      ->data[r1[b_idx] + b_meas.Location->size[0] * c_i];
            }
          }
        } else {
          c_i = c_ptPedestrian->size[0] * c_ptPedestrian->size[1];
          c_ptPedestrian->size[0] = b_meas.Location->size[0];
          c_ptPedestrian->size[1] = 3;
          emxEnsureCapacity_real_T(&b_st, c_ptPedestrian, c_i, &jb_emlrtRTEI);
          ptPedestrian_data = c_ptPedestrian->data;
          b_loop_ub = b_meas.Location->size[0] * 3;
          for (c_i = 0; c_i < b_loop_ub; c_i++) {
            ptPedestrian_data[c_i] = b_meas.Location->data[c_i];
          }
        }
        /*  予測値周辺の点群でRANSACを実行するため，点群を条件に従って抽出 */
        if (b_i + 1 > Xhbar_observed_ellipse_size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              b_i + 1, 1, Xhbar_observed_ellipse_size[1], &i_emlrtBCI, &b_st);
        }
        r_removelegCluster = Xhbar_observed_ellipse_data[6 * b_i];
        if (b_i + 1 > Xhbar_observed_ellipse_size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              b_i + 1, 1, Xhbar_observed_ellipse_size[1], &j_emlrtBCI, &b_st);
        }
        a__1 = Xhbar_observed_ellipse_data[6 * b_i + 1];
        c_i = b_ptPedestrian->size[0];
        b_ptPedestrian->size[0] = c_ptPedestrian->size[0];
        emxEnsureCapacity_real_T(&b_st, b_ptPedestrian, c_i, &lb_emlrtRTEI);
        distances_data = b_ptPedestrian->data;
        b_loop_ub = c_ptPedestrian->size[0];
        c_i = ptPedestrian->size[0];
        ptPedestrian->size[0] = c_ptPedestrian->size[0];
        emxEnsureCapacity_real_T(&b_st, ptPedestrian, c_i, &mb_emlrtRTEI);
        b_ptPedestrian_data = ptPedestrian->data;
        last = (c_ptPedestrian->size[0] / 2) << 1;
        b_idx = last - 2;
        for (c_i = 0; c_i <= b_idx; c_i += 2) {
          r5 = _mm_loadu_pd(&ptPedestrian_data[c_i]);
          _mm_storeu_pd(&distances_data[c_i],
                        _mm_sub_pd(r5, _mm_set1_pd(r_removelegCluster)));
          r5 = _mm_loadu_pd(&ptPedestrian_data[c_i + c_ptPedestrian->size[0]]);
          _mm_storeu_pd(&b_ptPedestrian_data[c_i],
                        _mm_sub_pd(r5, _mm_set1_pd(a__1)));
        }
        for (c_i = last; c_i < b_loop_ub; c_i++) {
          distances_data[c_i] = ptPedestrian_data[c_i] - r_removelegCluster;
          b_ptPedestrian_data[c_i] =
              ptPedestrian_data[c_i + c_ptPedestrian->size[0]] - a__1;
        }
        c_st.site = &f_emlrtRSI;
        b_hypot(&c_st, b_ptPedestrian, ptPedestrian, distances);
        distances_data = distances->data;
        c_i = idx->size[0];
        idx->size[0] = distances->size[0];
        emxEnsureCapacity_boolean_T(&b_st, idx, c_i, &nb_emlrtRTEI);
        idx_data = idx->data;
        b_loop_ub = distances->size[0];
        for (c_i = 0; c_i < b_loop_ub; c_i++) {
          idx_data[c_i] = (distances_data[c_i] < selectedArea);
        }
        /*  指定半径内に存在する点群のインデックス */
        b_idx = idx->size[0];
        b_loop_ub = 0;
        for (c_i = 0; c_i < b_idx; c_i++) {
          if (idx_data[c_i]) {
            b_loop_ub++;
          }
        }
        c_i = r2->size[0];
        r2->size[0] = b_loop_ub;
        emxEnsureCapacity_int32_T(&b_st, r2, c_i, &hb_emlrtRTEI);
        r1 = r2->data;
        last = 0;
        for (c_i = 0; c_i < b_idx; c_i++) {
          if (idx_data[c_i]) {
            r1[last] = c_i;
            last++;
          }
        }
        c_st.site = &e_emlrtRSI;
        b_loop_ub = r2->size[0];
        for (c_i = 0; c_i < b_loop_ub; c_i++) {
          if ((r1[c_i] < 0) || (r1[c_i] > c_ptPedestrian->size[0] - 1)) {
            emlrtDynamicBoundsCheckR2012b(
                r1[c_i], 0, c_ptPedestrian->size[0] - 1, &k_emlrtBCI, &c_st);
          }
        }
        b_loop_ub = r2->size[0];
        for (c_i = 0; c_i < b_loop_ub; c_i++) {
          if ((r1[c_i] < 0) || (r1[c_i] > c_ptPedestrian->size[0] - 1)) {
            emlrtDynamicBoundsCheckR2012b(
                r1[c_i], 0, c_ptPedestrian->size[0] - 1, &l_emlrtBCI, &c_st);
          }
        }
        d_st.site = &nc_emlrtRSI;
        e_st.site = &oc_emlrtRSI;
        b_loop_ub = r2->size[0];
        c_i = points->size[0] * points->size[1];
        points->size[0] = r2->size[0];
        points->size[1] = 2;
        emxEnsureCapacity_real_T(&d_st, points, c_i, &qb_emlrtRTEI);
        distances_data = points->data;
        for (c_i = 0; c_i < b_loop_ub; c_i++) {
          distances_data[c_i] = ptPedestrian_data[r1[c_i]];
          distances_data[c_i + points->size[0]] =
              ptPedestrian_data[r1[c_i] + c_ptPedestrian->size[0]];
        }
        /*  RANSACに入力する点群 */
        c_st.site = &d_emlrtRSI;
        last = b_meas.Location->size[0];
        x[0] = (points->size[0] >= doRANSAC);
        x[1] = (last > doRANSAC);
        y = true;
        c_i = 0;
        exitg1 = false;
        while ((!exitg1) && (c_i < 2)) {
          if (!x[c_i]) {
            y = false;
            exitg1 = true;
          } else {
            c_i++;
          }
        }
        if (y) {
          /*  点群が十分に得られる場合に実行 */
          if (b_i + 1 > isObserved->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, isObserved->size[0],
                                          &n_emlrtBCI, &b_st);
          }
          isObserved_data[b_i] = 1.0;
          /* RANSACの初期値には事前推定値(x,y,alpha,beta,theta) */
          if (b_i + 1 > Xhbar_observed_ellipse_size[1]) {
            emlrtDynamicBoundsCheckR2012b(
                b_i + 1, 1, Xhbar_observed_ellipse_size[1], &f_emlrtBCI, &b_st);
          }
          /*  事前推定値 */
          a0[0] = r_removelegCluster;
          a0[1] = a__1;
          a0[2] = Xhbar_observed_ellipse_data[6 * b_i + 4];
          a0[3] = Xhbar_observed_ellipse_data[6 * b_i + 5];
          a0[4] = Xhbar_observed_ellipse_data[6 * b_i + 2];
          lb[0] = rtMinusInf;
          lb[1] = rtMinusInf;
          lb[2] = 0.1;
          lb[3] = 0.05;
          lb[4] = a0[4] - tth;
          /*  下限制約(x,y,alpha,beta,theta) */
          ub[0] = rtInf;
          ub[1] = rtInf;
          ub[2] = 0.2;
          ub[3] = 0.1;
          ub[4] = a0[4] + tth;
          /*  上限制約(x,y,alpha,beta,theta) */
          /*  課題：モデル適合度が不足
           * (初期値の割り当ては前時刻で重心モデル回すor観測値テンプレから評価値高を選択)
           */
          if (b_i + 1 > Xhbar_observed_ellipse_size[1]) {
            emlrtDynamicBoundsCheckR2012b(
                b_i + 1, 1, Xhbar_observed_ellipse_size[1], &e_emlrtBCI, &b_st);
          }
          if (b_i > Pbar_observed_ellipse_size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(
                b_i, 0, Pbar_observed_ellipse_size[0] - 1, &p_emlrtBCI, &b_st);
          }
          c_st.site = &c_emlrtRSI;
          pcfitellipse(&c_st, points, a0, sampleSize, maxDistance, RANSAC->A, B,
                       lb, ub, TrialNum, confDegree,
                       Pbar_observed_ellipse_data[b_i].f1, R, MD_threshold,
                       MSANum, &Xhbar_observed_ellipse_data[6 * b_i], eta,
                       *Plant, dv, inlierpoints, a__3, &r_removelegCluster);
          distances_data = inlierpoints->data;
          for (c_i = 0; c_i < 5; c_i++) {
            if (b_i + 1 > model1->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                            &q_emlrtBCI, &b_st);
            }
            model1_data[b_i].model[c_i] = dv[c_i];
          }
          /*  可変のインライアを割り当てるためにこねこねする(＠ω＠) */
          memset(&inlierpoints_full[0], 0, 4000U * sizeof(real_T));
          /*  インライアが2000個以下と仮定 */
          if (inlierpoints->size[0] > 0) {
            if (inlierpoints->size[0] > 2000) {
              emlrtDynamicBoundsCheckR2012b(inlierpoints->size[0], 1, 2000,
                                            &d_emlrtBCI, &b_st);
            }
            b_inlierpoints[0] = inlierpoints->size[0];
            b_inlierpoints[1] = 2;
            emlrtSubAssignSizeCheckR2012b(&b_inlierpoints[0], 2,
                                          &inlierpoints->size[0], 2, &emlrtECI,
                                          &b_st);
            b_loop_ub = inlierpoints->size[0];
            for (c_i = 0; c_i < 2; c_i++) {
              for (b_idx = 0; b_idx < b_loop_ub; b_idx++) {
                inlierpoints_full[b_idx + 2000 * c_i] =
                    distances_data[b_idx + inlierpoints->size[0] * c_i];
              }
            }
          }
          if (b_i + 1 > model1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                          &c_emlrtBCI, &b_st);
          }
          for (c_i = 0; c_i < 4000; c_i++) {
            model1_data[b_i].inlierpoints[c_i] = inlierpoints_full[c_i];
          }
          if (b_i + 1 > model1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                          &r_emlrtBCI, &b_st);
          }
          model1_data[b_i].ModelType = 1.0;
        } else {
          if (b_i + 1 > isObserved->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, isObserved->size[0],
                                          &m_emlrtBCI, &b_st);
          }
          isObserved_data[b_i] = 0.0;
          if (b_i + 1 > Xhbar_observed_size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Xhbar_observed_size[1],
                                          &b_emlrtBCI, &b_st);
          }
          c_st.site = &b_emlrtRSI;
          pcfitptCOG(&c_st, &b_meas, &Xhbar_observed_data[6 * b_i], cog, a__4);
          if (b_i + 1 > model1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                          &t_emlrtBCI, &b_st);
          }
          model1_data[b_i].model[0] = cog[0];
          if (b_i + 1 > model1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                          &t_emlrtBCI, &b_st);
          }
          model1_data[b_i].model[1] = cog[1];
          if (b_i + 1 > model1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                          &t_emlrtBCI, &b_st);
          }
          model1_data[b_i].model[2] = rtNaN;
          if (b_i + 1 > model1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                          &t_emlrtBCI, &b_st);
          }
          model1_data[b_i].model[3] = rtNaN;
          if (b_i + 1 > model1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                          &t_emlrtBCI, &b_st);
          }
          model1_data[b_i].model[4] = rtNaN;
          if (b_i + 1 > model1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                          &emlrtBCI, &b_st);
          }
          for (c_i = 0; c_i < 4000; c_i++) {
            model1_data[b_i].inlierpoints[c_i] = 0.0;
          }
          if (b_i + 1 > model1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, model1->size[0],
                                          &o_emlrtBCI, &b_st);
          }
          model1_data[b_i].ModelType = 2.0;
          /*  COGモデルを使用 */
        }
        /* --------------------------------------------------------------------------
         */
        c_st.site = &emlrtRSI;
        handle_matlabCodegenDestructor(&c_st, &b_meas);
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&b_st, 12);
      emxFree_real_T(&b_st, &inlierpoints);
      emxFree_real_T(&b_st, &points);
      emxFree_boolean_T(&b_st, &idx);
      emxFree_real_T(&b_st, &distances);
      emxFree_real_T(&b_st, &c_ptPedestrian);
      emxFreeStruct_pointCloud(&b_st, &b_meas);
      emxFree_real_T(&b_st, &b_ObsptClouds);
      emxFree_boolean_T(&b_st, &r4);
      emxFree_int32_T(&b_st, &r3);
      emxFree_real_T(&b_st, &b_ptPedestrian);
      emxFree_real_T(&b_st, &ptPedestrian);
      emxFree_int32_T(&b_st, &r2);
    }
  }
  if (!omp_in_parallel()) {
    c_st.site = &k_emlrtRSI;
    c_eml_rand_mt19937ar_stateful_s(false);
    c_st.site = &k_emlrtRSI;
    eml_rand_swap();
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  emxFreeStruct_pointCloud(sp, &meas);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

int32_T getThreadID(void)
{
  return threadID;
}

void initThreadID(const emlrtStack *sp)
{
  jmp_buf *volatile emlrtJBStack;
  int32_T idx;
  int32_T initThreadID_numThreads;
  int32_T ub_loop;
  ub_loop = omp_get_max_threads();
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  initThreadID_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for schedule(static) num_threads(initThreadID_numThreads)

  for (idx = 1; idx <= ub_loop; idx++) {
    threadID = omp_get_thread_num();
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

/* End of code generation (calc_observation.c) */
