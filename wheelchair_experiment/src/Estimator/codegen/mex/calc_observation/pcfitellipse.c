/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse.c
 *
 * Code generation for function 'pcfitellipse'
 *
 */

/* Include files */
#include "pcfitellipse.h"
#include "calc_observation_data.h"
#include "calc_observation_emxutil.h"
#include "calc_observation_internal_types.h"
#include "calc_observation_types.h"
#include "checkLinearInputs.h"
#include "combineVectorElements.h"
#include "computeConstraints_.h"
#include "computeFiniteDifferences.h"
#include "computeObjective_.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "hypot.h"
#include "initActiveSet.h"
#include "mrdivide_helper.h"
#include "ransac.h"
#include "rt_nonfinite.h"
#include "sumprod.h"
#include "unsafeSxfun.h"
#include "updateWorkingSetForNewQP.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = {
    21,             /* lineNo */
    "pcfitellipse", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    35,             /* lineNo */
    "pcfitellipse", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    38,             /* lineNo */
    "pcfitellipse", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    59,             /* lineNo */
    "pcfitellipse", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    24, /* lineNo */
    "@(points)fmincon(@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a("
    "2))*cos(a(5)))/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))"
    "+(points(:,2)-a(2))*-sin(a(5)))/"
    "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),1),a0,"
    "A,B,Aeq,Beq,lb,ub,nonl"
    "con,options)", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    1,                                                     /* lineNo */
    "fmincon",                                             /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/eml/fmincon.p" /* pathName */
};

static emlrtRSInfo je_emlrtRSI = {
    1,                                /* lineNo */
    "evalObjAndConstrAndDerivatives", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+utils/"
    "+ObjNonlinEvaluator/evalObjAndConstrAndDerivatives.p" /* pathName */
};

static emlrtRSInfo le_emlrtRSI =
    {
        24, /* lineNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fcnName */
        "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
        "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
        "_08_08/"
        "capsuele_v5.3_"
        "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
        "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI =
    {
        25, /* lineNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fcnName */
        "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
        "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
        "_08_08/"
        "capsuele_v5.3_"
        "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
        "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI =
    {
        26, /* lineNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fcnName */
        "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
        "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
        "_08_08/"
        "capsuele_v5.3_"
        "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
        "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    10,                                                           /* lineNo */
    "exp",                                                        /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elfun/exp.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    38,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

static emlrtRSInfo kl_emlrtRSI = {
    29,                                                    /* lineNo */
    "@(model,points)sum(distanceEllipse(model,points),2)", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo ll_emlrtRSI = {
    109,                            /* lineNo */
    "pcfitellipse/distanceEllipse", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pathName */
};

static emlrtRSInfo ml_emlrtRSI = {
    112,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo nl_emlrtRSI = {
    173,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    43,             /* lineNo */
    25,             /* colNo */
    "modelRANSAC",  /* aName */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    43,             /* lineNo */
    40,             /* colNo */
    "modelRANSAC",  /* aName */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    54,             /* lineNo */
    52,             /* colNo */
    "modelRANSAC",  /* aName */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    38,             /* lineNo */
    22,             /* colNo */
    "points",       /* aName */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    38,             /* lineNo */
    43,             /* colNo */
    "points",       /* aName */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m", /* pName */
    0                           /* checkKind */
};

static emlrtECInfo c_emlrtECI =
    {
        -1, /* nDims */
        24, /* lineNo */
        51, /* colNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fName */
        "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
        "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
        "_08_08/"
        "capsuele_v5.3_"
        "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
        "Estimator/pcfitellipse.m" /* pName */
};

static emlrtECInfo d_emlrtECI =
    {
        -1, /* nDims */
        25, /* lineNo */
        13, /* colNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fName */
        "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
        "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
        "_08_08/"
        "capsuele_v5.3_"
        "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
        "Estimator/pcfitellipse.m" /* pName */
};

static emlrtECInfo e_emlrtECI =
    {
        1,  /* nDims */
        24, /* lineNo */
        49, /* colNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fName */
        "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
        "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
        "_08_08/"
        "capsuele_v5.3_"
        "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
        "Estimator/pcfitellipse.m" /* pName */
};

static emlrtECInfo f_emlrtECI =
    {
        1,  /* nDims */
        24, /* lineNo */
        48, /* colNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fName */
        "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
        "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
        "_08_08/"
        "capsuele_v5.3_"
        "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
        "Estimator/pcfitellipse.m" /* pName */
};

static emlrtECInfo g_emlrtECI = {
    1,                              /* nDims */
    109,                            /* lineNo */
    21,                             /* colNo */
    "pcfitellipse/distanceEllipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtECInfo h_emlrtECI = {
    1,                              /* nDims */
    109,                            /* lineNo */
    88,                             /* colNo */
    "pcfitellipse/distanceEllipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtECInfo i_emlrtECI = {
    1,                              /* nDims */
    109,                            /* lineNo */
    23,                             /* colNo */
    "pcfitellipse/distanceEllipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    113,                             /* lineNo */
    23,                              /* colNo */
    "model",                         /* aName */
    "pcfitellipse/validateModelFcn", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    113,                             /* lineNo */
    32,                              /* colNo */
    "model",                         /* aName */
    "pcfitellipse/validateModelFcn", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    113,                             /* lineNo */
    41,                              /* colNo */
    "model",                         /* aName */
    "pcfitellipse/validateModelFcn", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    1,                /* iFirst */
    8,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compressBounds", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/compressBounds.p", /* pName */
    3                               /* checkKind */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    1,         /* lineNo */
    1,         /* colNo */
    "checkX0", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/optimlib/+optim/+coder/+validate/"
    "checkX0.p" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    1,                                                     /* lineNo */
    1,                                                     /* colNo */
    "fmincon",                                             /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/eml/fmincon.p" /* pName */
};

static emlrtBCInfo nb_emlrtBCI = {
    1,                                                      /* iFirst */
    5,                                                      /* iLast */
    1,                                                      /* lineNo */
    1,                                                      /* colNo */
    "",                                                     /* aName */
    "fmincon",                                              /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/eml/fmincon.p", /* pName */
    3                                                       /* checkKind */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    21,             /* lineNo */
    22,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    21,             /* lineNo */
    40,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    1,              /* lineNo */
    46,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    38,             /* lineNo */
    5,              /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    38,             /* lineNo */
    22,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    24,             /* lineNo */
    51,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    24,             /* lineNo */
    81,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = {
    25,             /* lineNo */
    13,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    25,             /* lineNo */
    43,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    25,             /* lineNo */
    11,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    26,             /* lineNo */
    19,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    26,             /* lineNo */
    31,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    109,            /* lineNo */
    24,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    109,            /* lineNo */
    23,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    109,            /* lineNo */
    51,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    109,            /* lineNo */
    50,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = {
    146,                /* lineNo */
    24,                 /* colNo */
    "blockedSummation", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    29,             /* lineNo */
    42,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = {
    126,            /* lineNo */
    37,             /* colNo */
    "stickyStruct", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/coder/coder/lib/+coder/+internal/"
    "stickyStruct.m" /* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = {
    1,                  /* lineNo */
    1,                  /* colNo */
    "factoryConstruct", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/factoryConstruct.p" /* pName */
};

static emlrtRSInfo dm_emlrtRSI =
    {
        31,            /* lineNo */
        "unsafeSxfun", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unsafeSxfun.m" /* pathName */
};

/* Function Definitions */
real_T pcfitellipse(const emlrtStack *sp, const emxArray_real_T *points,
                    const real_T a0[5], real_T sampleSize, real_T maxDistance,
                    const real_T A[5], real_T B, const real_T lb[5],
                    const real_T ub[5], real_T Num, real_T CNum,
                    const real_T Pbar[36], const real_T R[25],
                    real_T MD_threshold, real_T MSANum, const real_T Xhbar[6],
                    real_T eta, const struct1_T Plant, real_T Y[5],
                    emxArray_real_T *inlier, real_T S_final[25], real_T *MD)
{
  e_struct_T expl_temp;
  emlrtStack b_st;
  emlrtStack st;
  emxArray_boolean_T *inlierIdx;
  emxArray_int32_T *r;
  emxArray_real_T *b_points;
  real_T a[30];
  real_T b_modelRANSAC_data[25];
  real_T c_modelRANSAC_data[25];
  real_T modelRANSAC_data[5];
  real_T c_fitEllipseFcn_workspace_nonlc[2];
  const real_T *points_data;
  real_T SBreakFlag;
  real_T accumulatedData;
  real_T *inlier_data;
  int32_T modelRANSAC_size[2];
  int32_T b_SBreakFlag;
  int32_T end;
  int32_T i;
  int32_T loop_ub;
  int32_T trueCount;
  int32_T *r1;
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T judgeOverRatio;
  boolean_T *inlierIdx_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  points_data = points->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  MEXの中にparforを入れると爆速になる */
  /*  points      = zeros(size(x,1),2); %点群を保存する配列の初期化 */
  /*  points(:,1) = double(x); %点群のx座標をdouble型へ */
  /*  points(:,2) = double(y); %点群のy座標をdouble型へ */
  /*  % 関心領域の設定,楕円にしたい */
  /*  if cnt >= 0 % selectedCount */
  /*      xpoints = x(hypot(x-Xhbar(1,1),y-Xhbar(2,1)) < selectedArea); */
  /*      points = zeros(length(xpoints),2); */
  /*      points(:,1) = xpoints; */
  /*      points(:,2) = y(hypot(x-Xhbar(1,1),y-Xhbar(2,1)) < selectedArea); */
  /*      points = double(points); */
  /*  else */
  /*      points      = zeros(size(x,1),2); %点群を保存する配列の初期化 */
  /*      points(:,1) = double(x); %点群のx座標をdouble型へ */
  /*      points(:,2) = double(y); %点群のy座標をdouble型へ */
  /*  end */
  st.site = &pc_emlrtRSI;
  emxInit_real_T(&st, &b_points, 1, &bc_emlrtRTEI);
  loop_ub = points->size[0];
  i = b_points->size[0];
  b_points->size[0] = points->size[0];
  emxEnsureCapacity_real_T(&st, b_points, i, &bc_emlrtRTEI);
  inlier_data = b_points->data;
  for (i = 0; i < loop_ub; i++) {
    inlier_data[i] = points_data[i];
  }
  b_st.site = &x_emlrtRSI;
  accumulatedData = combineVectorElements(&b_st, b_points);
  st.site = &pc_emlrtRSI;
  i = b_points->size[0];
  b_points->size[0] = points->size[0];
  emxEnsureCapacity_real_T(&st, b_points, i, &cc_emlrtRTEI);
  inlier_data = b_points->data;
  for (i = 0; i < loop_ub; i++) {
    inlier_data[i] = points_data[i + points->size[0]];
  }
  b_st.site = &x_emlrtRSI;
  SBreakFlag = combineVectorElements(&b_st, b_points);
  emxFree_real_T(&st, &b_points);
  c_fitEllipseFcn_workspace_nonlc[0] =
      accumulatedData / (real_T)points->size[0];
  c_fitEllipseFcn_workspace_nonlc[1] = SBreakFlag / (real_T)points->size[0];
  /*  歩行者クラスタの重心 */
  /* ソルバーの設定。このままでOK */
  /* RANSACでモデルの候補生成のための計算式。サンプリングした点群のみ使ってfminconを解く。
   */
  for (i = 0; i < 5; i++) {
    accumulatedData = 0.0;
    for (end = 0; end < 6; end++) {
      accumulatedData += (real_T)iv[i + 5 * end] * Xhbar[end];
    }
    expl_temp.Yhbar[i] = accumulatedData;
  }
  /* 1st RANSAC */
  /* modelRANSAC:x,y,alpha,beta,theta(楕円中心,長軸,短軸,方向角),inlierIdx:各点群がInlierかどうか1,0で表示
   */
  expl_temp.MD_threshold = MD_threshold;
  memcpy(&expl_temp.R[0], &R[0], 25U * sizeof(real_T));
  memcpy(&expl_temp.Pbar[0], &Pbar[0], 36U * sizeof(real_T));
  emxInit_boolean_T(sp, &inlierIdx, &dc_emlrtRTEI);
  st.site = &qc_emlrtRSI;
  ransac(&st, points, a0, A, B, lb, ub, c_fitEllipseFcn_workspace_nonlc,
         Plant.X, Plant.Y, Plant.yaw, sampleSize, maxDistance, MSANum, Num,
         CNum, &expl_temp, modelRANSAC_data, modelRANSAC_size, inlierIdx);
  inlierIdx_data = inlierIdx->data;
  end = inlierIdx->size[0];
  trueCount = 0;
  for (loop_ub = 0; loop_ub < end; loop_ub++) {
    if (inlierIdx_data[loop_ub]) {
      trueCount++;
    }
  }
  emxInit_int32_T(sp, &r, &fc_emlrtRTEI);
  i = r->size[0];
  r->size[0] = trueCount;
  emxEnsureCapacity_int32_T(sp, r, i, &dc_emlrtRTEI);
  r1 = r->data;
  trueCount = 0;
  for (loop_ub = 0; loop_ub < end; loop_ub++) {
    if (inlierIdx_data[loop_ub]) {
      r1[trueCount] = loop_ub;
      trueCount++;
    }
  }
  emxFree_boolean_T(sp, &inlierIdx);
  st.site = &rc_emlrtRSI;
  trueCount = r->size[0];
  for (i = 0; i < trueCount; i++) {
    if (r1[i] > points->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 0, points->size[0] - 1, &x_emlrtBCI,
                                    &st);
    }
  }
  for (i = 0; i < trueCount; i++) {
    if (r1[i] > points->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 0, points->size[0] - 1, &y_emlrtBCI,
                                    &st);
    }
  }
  b_st.site = &nc_emlrtRSI;
  i = inlier->size[0] * inlier->size[1];
  inlier->size[0] = r->size[0];
  inlier->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, inlier, i, &ec_emlrtRTEI);
  inlier_data = inlier->data;
  for (i = 0; i < trueCount; i++) {
    inlier_data[i] = points_data[r1[i]];
    inlier_data[i + inlier->size[0]] = points_data[r1[i] + points->size[0]];
  }
  emxFree_int32_T(&b_st, &r);
  /* 外れ値でない点群を保存 */
  /*  alpha/betaの最大比率 */
  /*  alpha/betaの最小比率 */
  /*  eta = 0.1; */
  accumulatedData = 3.0 * eta;
  /*  共分散行列崩れ判定の閾値 */
  loop_ub = modelRANSAC_size[0] * modelRANSAC_size[1];
  if (loop_ub < 3) {
    emlrtDynamicBoundsCheckR2012b(3, 1, loop_ub, &u_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (loop_ub < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, 3, &v_emlrtBCI, (emlrtConstCTX)sp);
  }
  SBreakFlag = modelRANSAC_data[2] / modelRANSAC_data[3];
  x[0] = (SBreakFlag < accumulatedData + 1.0);
  x[1] = (SBreakFlag > 4.0 - accumulatedData);
  judgeOverRatio = false;
  trueCount = 0;
  exitg1 = false;
  while ((!exitg1) && (trueCount < 2)) {
    if (x[trueCount]) {
      judgeOverRatio = true;
      exitg1 = true;
    } else {
      trueCount++;
    }
  }
  if (judgeOverRatio) {
    /*  事後誤差共分散行列を比率調整するための判定,0:異常なし，1:イノベーション共分散の崩れ発生
     */
    b_SBreakFlag = 1;
  } else {
    b_SBreakFlag = 0;
  }
  /*  */
  end = modelRANSAC_size[1];
  trueCount = modelRANSAC_size[0];
  if (trueCount - 1 >= 0) {
    for (i = 0; i < end; i++) {
      b_modelRANSAC_data[i] = modelRANSAC_data[modelRANSAC_size[0] * i];
    }
  }
  memcpy(&c_modelRANSAC_data[0], &b_modelRANSAC_data[0],
         (uint32_T)loop_ub * sizeof(real_T));
  if (loop_ub < 5) {
    emlrtDynamicBoundsCheckR2012b(5, 1, 4, &w_emlrtBCI, (emlrtConstCTX)sp);
  }
  Y[0] = c_modelRANSAC_data[0];
  Y[1] = c_modelRANSAC_data[1];
  Y[2] = c_modelRANSAC_data[4];
  Y[3] = c_modelRANSAC_data[2];
  Y[4] = c_modelRANSAC_data[3];
  /*  [x,y,theta,alpha,beta] */
  /*  obj.ellipse.Xhbar(3) = wrapTo2Pi(obj.ellipse.Xhbar(3)); */
  /*  obj.ellipse.model(3) =
   * wrapAngle(obj.ellipse.Xhbar(3),obj.ellipse.model(3)); */
  for (i = 0; i < 5; i++) {
    for (end = 0; end < 6; end++) {
      accumulatedData = 0.0;
      for (trueCount = 0; trueCount < 6; trueCount++) {
        accumulatedData +=
            (real_T)iv[i + 5 * trueCount] * Pbar[trueCount + 6 * end];
      }
      a[i + 5 * end] = accumulatedData;
    }
    for (end = 0; end < 5; end++) {
      accumulatedData = 0.0;
      for (trueCount = 0; trueCount < 6; trueCount++) {
        accumulatedData +=
            a[i + 5 * trueCount] * (real_T)iv1[trueCount + 6 * end];
      }
      trueCount = i + 5 * end;
      S_final[trueCount] = accumulatedData + R[trueCount];
    }
    expl_temp.Yhbar[i] = Y[i] - expl_temp.Yhbar[i];
  }
  st.site = &sc_emlrtRSI;
  for (i = 0; i < 5; i++) {
    modelRANSAC_data[i] = expl_temp.Yhbar[i];
  }
  b_st.site = &sk_emlrtRSI;
  mrdiv(&b_st, modelRANSAC_data, S_final);
  accumulatedData = 0.0;
  for (i = 0; i < 5; i++) {
    accumulatedData += modelRANSAC_data[i] * expl_temp.Yhbar[i];
  }
  st.site = &sc_emlrtRSI;
  if (accumulatedData < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &i_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  SBreakFlag = b_SBreakFlag;
  *MD = muDoubleScalarSqrt(accumulatedData);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return SBreakFlag;
}

void pcfitellipse_anonFcn2(const emlrtStack *sp, real_T a0[5],
                           const real_T A[5], real_T B, const real_T lb[5],
                           const real_T ub[5], const anonymous_function nonlcon,
                           const emxArray_real_T *points)
{
  c_struct_T memspace;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  f_struct_T TrialState;
  g_struct_T WorkingSet;
  h_struct_T obj;
  i_coder_internal_stickyStruct FcnEvaluator;
  i_struct_T MeritFunction;
  j_struct_T QRManager;
  k_struct_T CholManager;
  l_struct_T QPObjective;
  const real_T *points_data;
  real_T exitflag;
  int32_T i;
  int32_T idx;
  int8_T obj_tmp[5];
  boolean_T varargin_1[5];
  boolean_T exitg1;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  points_data = points->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ee_emlrtRSI;
  b_st.site = &fe_emlrtRSI;
  for (i = 0; i < 5; i++) {
    exitflag = a0[i];
    varargin_1[i] =
        ((!muDoubleScalarIsInf(exitflag)) && (!muDoubleScalarIsNaN(exitflag)));
  }
  y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 5)) {
    if (!varargin_1[i]) {
      y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }
  if (!y) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &bb_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
        "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 2, "x0");
  }
  b_st.site = &fe_emlrtRSI;
  exitflag = checkLinearInputs(&b_st, A, B, lb, ub);
  b_st.site = &fe_emlrtRSI;
  if (!(exitflag == -2.0)) {
    real_T Hessian[25];
    real_T c;
    int32_T loop_ub_tmp;
    int32_T mFixed;
    int32_T mLB;
    int32_T mUB;
    TrialState.sqpFval_old = 0.0;
    TrialState.sqpIterations = 0;
    memset(&TrialState.lambdasqp[0], 0, 15U * sizeof(real_T));
    TrialState.steplength = 1.0;
    memset(&TrialState.delta_x[0], 0, 8U * sizeof(real_T));
    TrialState.fstar = 0.0;
    memset(&TrialState.lambda[0], 0, 15U * sizeof(real_T));
    TrialState.state = 0;
    TrialState.maxConstr = 0.0;
    TrialState.iterations = 0;
    for (i = 0; i < 5; i++) {
      TrialState.xstarsqp[i] = a0[i];
    }
    c_emxInitStruct_coder_internal_(&st, &FcnEvaluator, &cb_emlrtRTEI);
    i = FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
            .points->size[0] *
        FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
            .points->size[1];
    FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.points
        ->size[0] = points->size[0];
    FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.points
        ->size[1] = 2;
    emxEnsureCapacity_real_T(&st,
                             FcnEvaluator.next.next.next.next.next.next.next
                                 .next.value.workspace.points,
                             i, &kd_emlrtRTEI);
    loop_ub_tmp = points->size[0] << 1;
    for (i = 0; i < loop_ub_tmp; i++) {
      FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
          .points->data[i] = points_data[i];
    }
    FcnEvaluator.next.next.next.next.next.next.next.value = nonlcon;
    WorkingSet.nVar = 5;
    memset(&WorkingSet.Aineq[0], 0, 16U * sizeof(real_T));
    WorkingSet.bineq[0] = 0.0;
    WorkingSet.bineq[1] = 0.0;
    memset(&WorkingSet.lb[0], 0, 8U * sizeof(real_T));
    memset(&WorkingSet.ub[0], 0, 8U * sizeof(real_T));
    WorkingSet.mEqRemoved = 0;
    memset(&WorkingSet.ATwset[0], 0, 120U * sizeof(real_T));
    WorkingSet.nActiveConstr = 0;
    memset(&WorkingSet.bwset[0], 0, 15U * sizeof(real_T));
    memset(&WorkingSet.maxConstrWorkspace[0], 0, 15U * sizeof(real_T));
    for (i = 0; i < 15; i++) {
      WorkingSet.isActiveConstr[i] = false;
      WorkingSet.Wid[i] = 0;
      WorkingSet.Wlocalidx[i] = 0;
    }
    for (i = 0; i < 5; i++) {
      WorkingSet.nWConstr[i] = 0;
    }
    WorkingSet.probType = 3;
    b_st.site = &fe_emlrtRSI;
    for (i = 0; i < 8; i++) {
      WorkingSet.indexLB[i] = 0;
      WorkingSet.indexUB[i] = 0;
      WorkingSet.indexFixed[i] = 0;
    }
    mLB = 0;
    mUB = 0;
    mFixed = 0;
    for (idx = 0; idx < 5; idx++) {
      boolean_T guard1;
      exitflag = lb[idx];
      guard1 = false;
      if ((!muDoubleScalarIsInf(exitflag)) &&
          (!muDoubleScalarIsNaN(exitflag))) {
        if (muDoubleScalarAbs(exitflag - ub[idx]) < 1.0E-6) {
          mFixed++;
          if (mFixed > 8) {
            emlrtDynamicBoundsCheckR2012b(9, 1, 8, &mb_emlrtBCI, &b_st);
          }
          WorkingSet.indexFixed[mFixed - 1] = idx + 1;
        } else {
          mLB++;
          if (mLB > 8) {
            emlrtDynamicBoundsCheckR2012b(9, 1, 8, &mb_emlrtBCI, &b_st);
          }
          WorkingSet.indexLB[mLB - 1] = idx + 1;
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        exitflag = ub[idx];
        if ((!muDoubleScalarIsInf(exitflag)) &&
            (!muDoubleScalarIsNaN(exitflag))) {
          mUB++;
          if (mUB > 8) {
            emlrtDynamicBoundsCheckR2012b(9, 1, 8, &mb_emlrtBCI, &b_st);
          }
          WorkingSet.indexUB[mUB - 1] = idx + 1;
        }
      }
    }
    b_st.site = &fe_emlrtRSI;
    i = ((mLB + mUB) + mFixed) + 2;
    WorkingSet.mConstr = i;
    WorkingSet.mConstrOrig = i;
    obj_tmp[0] = (int8_T)mFixed;
    obj_tmp[1] = 0;
    obj_tmp[2] = 2;
    obj_tmp[3] = (int8_T)mLB;
    obj_tmp[4] = (int8_T)mUB;
    WorkingSet.sizesPhaseOne[0] = mFixed;
    WorkingSet.sizesPhaseOne[1] = 0;
    WorkingSet.sizesPhaseOne[2] = 2;
    WorkingSet.sizesPhaseOne[3] = mLB + 1;
    WorkingSet.sizesPhaseOne[4] = mUB;
    WorkingSet.sizesRegularized[0] = mFixed;
    WorkingSet.sizesRegularized[1] = 0;
    WorkingSet.sizesRegularized[2] = 2;
    WorkingSet.sizesRegularized[3] = mLB + 2;
    WorkingSet.sizesRegularized[4] = mUB;
    WorkingSet.sizesRegPhaseOne[0] = mFixed;
    WorkingSet.sizesRegPhaseOne[1] = 0;
    WorkingSet.sizesRegPhaseOne[2] = 2;
    WorkingSet.sizesRegPhaseOne[3] = mLB + 3;
    WorkingSet.sizesRegPhaseOne[4] = mUB;
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    WorkingSet.isActiveIdxRegPhaseOne[3] = 2;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (i = 0; i < 5; i++) {
      int8_T b_i;
      b_i = obj_tmp[i];
      WorkingSet.sizes[i] = b_i;
      WorkingSet.sizesNormal[i] = b_i;
      WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    for (i = 0; i < 6; i++) {
      WorkingSet.isActiveIdx[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
      WorkingSet.isActiveIdxNormal[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    WorkingSet.isActiveIdxRegPhaseOne[3] = 2;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 1;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (i = 0; i < 5; i++) {
      WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    for (i = 0; i < 6; i++) {
      WorkingSet.isActiveIdxPhaseOne[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    WorkingSet.isActiveIdxRegPhaseOne[3] = 2;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 2;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (i = 0; i < 5; i++) {
      WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    for (i = 0; i < 6; i++) {
      WorkingSet.isActiveIdxRegularized[i] =
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    WorkingSet.isActiveIdxRegPhaseOne[3] = 2;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 3;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (i = 0; i < 5; i++) {
      WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    for (i = 0; i < 5; i++) {
      WorkingSet.Aineq[i] = A[i];
    }
    b_st.site = &fe_emlrtRSI;
    for (idx = 0; idx < mLB; idx++) {
      i = WorkingSet.indexLB[idx];
      if ((i < 1) || (i > 5)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 5, &nb_emlrtBCI, &st);
      }
      TrialState.xstarsqp[i - 1] =
          muDoubleScalarMax(TrialState.xstarsqp[i - 1], lb[i - 1]);
    }
    b_st.site = &fe_emlrtRSI;
    for (idx = 0; idx < mUB; idx++) {
      i = WorkingSet.indexUB[idx];
      if ((i < 1) || (i > 5)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 5, &nb_emlrtBCI, &st);
      }
      TrialState.xstarsqp[i - 1] =
          muDoubleScalarMin(TrialState.xstarsqp[i - 1], ub[i - 1]);
    }
    b_st.site = &fe_emlrtRSI;
    for (idx = 0; idx < mFixed; idx++) {
      i = WorkingSet.indexFixed[idx];
      if (i < 1) {
        emlrtDynamicBoundsCheckR2012b(0, 1, 5, &nb_emlrtBCI, &st);
      }
      TrialState.xstarsqp[i - 1] = ub[i - 1];
    }
    b_st.site = &fe_emlrtRSI;
    c_st.site = &je_emlrtRSI;
    exitflag = computeObjective_(
        &c_st,
        FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace,
        TrialState.xstarsqp, &i);
    if (i == 1) {
      i = computeConstraints_(nonlcon.workspace.COG_init,
                              nonlcon.workspace.Plant, TrialState.xstarsqp,
                              TrialState.cIneq);
    }
    TrialState.sqpFval = exitflag;
    if (i != 1) {
      emlrtErrorWithMessageIdR2018a(&st, &cb_emlrtRTEI,
                                    "optim_codegen:fmincon:UndefAtX0",
                                    "optim_codegen:fmincon:UndefAtX0", 0);
    }
    emxInitStruct_struct_T1(&st, &obj, &cb_emlrtRTEI);
    i = obj.objfun.workspace.points->size[0] *
        obj.objfun.workspace.points->size[1];
    obj.objfun.workspace.points->size[0] = points->size[0];
    obj.objfun.workspace.points->size[1] = 2;
    emxEnsureCapacity_real_T(&st, obj.objfun.workspace.points, i,
                             &ld_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      obj.objfun.workspace.points->data[i] = points_data[i];
    }
    obj.nonlin = nonlcon;
    obj.f_1 = 0.0;
    obj.numEvals = 0;
    for (i = 0; i < 5; i++) {
      varargin_1[i] = obj.hasLB[i];
    }
    y = false;
    idx = 0;
    while ((!y) && (idx + 1 <= 5)) {
      varargin_1[idx] =
          ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
      obj.hasUB[idx] =
          ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
      if (varargin_1[idx] || obj.hasUB[idx]) {
        y = true;
      }
      idx++;
    }
    while (idx + 1 <= 5) {
      varargin_1[idx] =
          ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
      obj.hasUB[idx] =
          ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
      idx++;
    }
    for (i = 0; i < 5; i++) {
      obj.hasLB[i] = varargin_1[i];
    }
    obj.hasBounds = y;
    b_st.site = &fe_emlrtRSI;
    computeFiniteDifferences(&b_st, &obj, exitflag, TrialState.cIneq,
                             TrialState.xstarsqp, TrialState.grad,
                             WorkingSet.Aineq, lb, ub);
    TrialState.FunctionEvaluations = obj.numEvals + 1;
    b_st.site = &fe_emlrtRSI;
    c = 0.0;
    for (i = 0; i < 5; i++) {
      c += WorkingSet.Aineq[i] * TrialState.xstarsqp[i];
    }
    TrialState.cIneq[0] = -B + c;
    b_st.site = &fe_emlrtRSI;
    updateWorkingSetForNewQP(&b_st, a0, &WorkingSet, TrialState.cIneq, mLB, lb,
                             mUB, ub, mFixed);
    b_st.site = &fe_emlrtRSI;
    initActiveSet(&b_st, &WorkingSet);
    MeritFunction.initFval = exitflag;
    MeritFunction.penaltyParam = 1.0;
    MeritFunction.threshold = 0.0001;
    MeritFunction.nPenaltyDecreases = 0;
    MeritFunction.linearizedConstrViol = 0.0;
    exitflag = 0.0;
    if (TrialState.cIneq[0] > 0.0) {
      exitflag = TrialState.cIneq[0];
    }
    if (TrialState.cIneq[1] > 0.0) {
      exitflag += TrialState.cIneq[1];
    }
    MeritFunction.initConstrViolationIneq = exitflag;
    MeritFunction.phi = 0.0;
    MeritFunction.phiPrimePlus = 0.0;
    MeritFunction.phiFullStep = 0.0;
    MeritFunction.feasRelativeFactor = 0.0;
    MeritFunction.nlpPrimalFeasError = 0.0;
    MeritFunction.nlpDualFeasError = 0.0;
    MeritFunction.nlpComplError = 0.0;
    b_st.site = &fe_emlrtRSI;
    b_driver(&b_st, B, lb, ub, &TrialState, &MeritFunction, &FcnEvaluator, &obj,
             &memspace, &WorkingSet, Hessian, &QRManager, &CholManager,
             &QPObjective);
    emxFreeStruct_struct_T1(&st, &obj);
    k_emxFreeStruct_coder_internal_(&st, &FcnEvaluator);
    for (i = 0; i < 5; i++) {
      a0[i] = TrialState.xstarsqp[i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

real_T pcfitellipse_anonFcn2_anonFcn1(const emlrtStack *sp,
                                      const emxArray_real_T *points,
                                      const real_T a[5])
{
  __m128d r4;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *b_points;
  emxArray_real_T *c_points;
  emxArray_real_T *r;
  emxArray_real_T *r2;
  const real_T *points_data;
  real_T b;
  real_T b_a;
  real_T c_a;
  real_T varargout_1;
  real_T *b_points_data;
  real_T *c_points_data;
  real_T *r1;
  real_T *r3;
  int32_T b_loop_ub;
  int32_T i;
  int32_T loop_ub;
  int32_T scalarLB_tmp;
  int32_T vectorUB_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  points_data = points->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  varargout_1 = muDoubleScalarSin(a[4]);
  b_a = a[0];
  emxInit_real_T(sp, &r, 1, &rc_emlrtRTEI);
  loop_ub = points->size[0];
  i = r->size[0];
  r->size[0] = points->size[0];
  emxEnsureCapacity_real_T(sp, r, i, &rc_emlrtRTEI);
  r1 = r->data;
  b = muDoubleScalarCos(a[4]);
  c_a = a[1];
  emxInit_real_T(sp, &r2, 1, &rc_emlrtRTEI);
  i = r2->size[0];
  r2->size[0] = points->size[0];
  emxEnsureCapacity_real_T(sp, r2, i, &sc_emlrtRTEI);
  r3 = r2->data;
  scalarLB_tmp = (points->size[0] / 2) << 1;
  vectorUB_tmp = scalarLB_tmp - 2;
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    _mm_storeu_pd(&r1[i], _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(&points_data[i]),
                                                _mm_set1_pd(b_a)),
                                     _mm_set1_pd(-varargout_1)));
    _mm_storeu_pd(
        &r3[i],
        _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(&points_data[i + points->size[0]]),
                              _mm_set1_pd(c_a)),
                   _mm_set1_pd(b)));
  }
  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = (points_data[i] - b_a) * -varargout_1;
    r3[i] = (points_data[i + points->size[0]] - c_a) * b;
  }
  b_loop_ub = r->size[0];
  if (r->size[0] != r2->size[0]) {
    emlrtSizeEqCheck1DR2012b(r->size[0], r2->size[0], &c_emlrtECI,
                             (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &b_points, 1, &wc_emlrtRTEI);
  i = b_points->size[0];
  b_points->size[0] = points->size[0];
  emxEnsureCapacity_real_T(sp, b_points, i, &tc_emlrtRTEI);
  b_points_data = b_points->data;
  emxInit_real_T(sp, &c_points, 1, &xc_emlrtRTEI);
  i = c_points->size[0];
  c_points->size[0] = points->size[0];
  emxEnsureCapacity_real_T(sp, c_points, i, &uc_emlrtRTEI);
  c_points_data = c_points->data;
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    _mm_storeu_pd(
        &b_points_data[i],
        _mm_mul_pd(_mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(&points_data[i]),
                                         _mm_set1_pd(b_a)),
                              _mm_set1_pd(-1.0)),
                   _mm_set1_pd(b)));
    _mm_storeu_pd(
        &c_points_data[i],
        _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(&points_data[i + points->size[0]]),
                              _mm_set1_pd(c_a)),
                   _mm_set1_pd(-varargout_1)));
  }
  for (i = scalarLB_tmp; i < loop_ub; i++) {
    b_points_data[i] = -(points_data[i] - b_a) * b;
    c_points_data[i] = (points_data[i + points->size[0]] - c_a) * -varargout_1;
  }
  scalarLB_tmp = b_points->size[0];
  if (b_points->size[0] != c_points->size[0]) {
    emlrtSizeEqCheck1DR2012b(b_points->size[0], c_points->size[0], &d_emlrtECI,
                             (emlrtConstCTX)sp);
  }
  st.site = &le_emlrtRSI;
  b_st.site = &oe_emlrtRSI;
  for (i = 0; i < b_loop_ub; i++) {
    varargout_1 = (r1[i] + r3[i]) / a[2];
    r1[i] = varargout_1 * varargout_1;
  }
  st.site = &me_emlrtRSI;
  b_st.site = &oe_emlrtRSI;
  i = r2->size[0];
  r2->size[0] = b_points->size[0];
  emxEnsureCapacity_real_T(&b_st, r2, i, &vc_emlrtRTEI);
  r3 = r2->data;
  for (i = 0; i < scalarLB_tmp; i++) {
    varargout_1 = (b_points_data[i] + c_points_data[i]) / a[3];
    r3[i] = varargout_1 * varargout_1;
  }
  if ((r->size[0] != b_points->size[0]) &&
      ((r->size[0] != 1) && (b_points->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[0], b_points->size[0], &e_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  st.site = &le_emlrtRSI;
  b_st.site = &oe_emlrtRSI;
  if (r->size[0] == r2->size[0]) {
    for (i = 0; i < b_loop_ub; i++) {
      varargout_1 = (r1[i] + r3[i]) - 1.0;
      r1[i] = varargout_1 * varargout_1;
    }
  } else {
    c_st.site = &dm_emlrtRSI;
    binary_expand_op_1(&c_st, r, r2);
    r1 = r->data;
  }
  varargout_1 = muDoubleScalarHypot(a[0], a[1]);
  st.site = &ne_emlrtRSI;
  i = b_points->size[0];
  b_points->size[0] = points->size[0];
  emxEnsureCapacity_real_T(&st, b_points, i, &wc_emlrtRTEI);
  b_points_data = b_points->data;
  i = c_points->size[0];
  c_points->size[0] = points->size[0];
  emxEnsureCapacity_real_T(&st, c_points, i, &xc_emlrtRTEI);
  c_points_data = c_points->data;
  for (i = 0; i < loop_ub; i++) {
    b_points_data[i] = points_data[i];
    c_points_data[i] = points_data[i + points->size[0]];
  }
  b_st.site = &ne_emlrtRSI;
  b_hypot(&b_st, b_points, c_points, r2);
  r3 = r2->data;
  emxFree_real_T(&st, &c_points);
  emxFree_real_T(&st, &b_points);
  loop_ub = r2->size[0];
  scalarLB_tmp = (r2->size[0] / 2) << 1;
  vectorUB_tmp = scalarLB_tmp - 2;
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    r4 = _mm_loadu_pd(&r3[i]);
    _mm_storeu_pd(&r3[i], _mm_sub_pd(r4, _mm_set1_pd(varargout_1)));
  }
  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r3[i] -= varargout_1;
  }
  b_st.site = &pe_emlrtRSI;
  scalarLB_tmp = r2->size[0];
  c_st.site = &qe_emlrtRSI;
  if (r2->size[0] > 2147483646) {
    d_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (vectorUB_tmp = 0; vectorUB_tmp < scalarLB_tmp; vectorUB_tmp++) {
    r3[vectorUB_tmp] = muDoubleScalarExp(r3[vectorUB_tmp]);
  }
  loop_ub = r->size[0];
  if ((r->size[0] != r2->size[0]) &&
      ((r->size[0] != 1) && (r2->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[0], r2->size[0], &f_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  st.site = &le_emlrtRSI;
  b_st.site = &re_emlrtRSI;
  if (r->size[0] == r2->size[0]) {
    scalarLB_tmp = (r->size[0] / 2) << 1;
    vectorUB_tmp = scalarLB_tmp - 2;
    for (i = 0; i <= vectorUB_tmp; i += 2) {
      __m128d r5;
      r4 = _mm_loadu_pd(&r1[i]);
      r5 = _mm_loadu_pd(&r3[i]);
      _mm_storeu_pd(&r1[i], _mm_add_pd(r4, r5));
    }
    for (i = scalarLB_tmp; i < loop_ub; i++) {
      r1[i] += r3[i];
    }
    c_st.site = &se_emlrtRSI;
    varargout_1 = combineVectorElements(&c_st, r);
  } else {
    c_st.site = &se_emlrtRSI;
    varargout_1 = binary_expand_op(&c_st, se_emlrtRSI, r, r2);
  }
  emxFree_real_T(&b_st, &r2);
  emxFree_real_T(&b_st, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return varargout_1;
}

void pcfitellipse_anonFcn3(const emlrtStack *sp, const real_T model[5],
                           const emxArray_real_T *points,
                           emxArray_real_T *varargout_1)
{
  __m128d r4;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_real_T *distance;
  emxArray_real_T *r;
  emxArray_real_T *r2;
  emxArray_real_T *r5;
  const real_T *points_data;
  real_T b;
  real_T b_model;
  real_T varargin_1;
  real_T *distance_data;
  real_T *r1;
  real_T *r3;
  real_T *varargout_1_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T scalarLB_tmp;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
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
  points_data = points->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*    %サンプリングした点群から計算した楕円と各点群との誤差を計算する式 */
  emxInit_real_T(sp, &distance, 1, &gd_emlrtRTEI);
  st.site = &kl_emlrtRSI;
  /* サンプリングした点群から計算した楕円と各点群との誤差を計算 */
  /* 点群のx座標を代入 */
  /* 点群のy座標を代入 */
  /* 以下で誤差を計算.
   * pにはRANSACで計算されたx,y,alpha,beta,thetaがベクトルで入っている。 */
  varargin_1 = muDoubleScalarSin(model[4]);
  b_model = model[0];
  loop_ub = points->size[0];
  i = distance->size[0];
  distance->size[0] = points->size[0];
  emxEnsureCapacity_real_T(&st, distance, i, &yc_emlrtRTEI);
  distance_data = distance->data;
  scalarLB = (points->size[0] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    _mm_storeu_pd(&distance_data[i], _mm_sub_pd(_mm_loadu_pd(&points_data[i]),
                                                _mm_set1_pd(b_model)));
  }
  for (i = scalarLB; i < loop_ub; i++) {
    distance_data[i] = points_data[i] - b_model;
  }
  emxInit_real_T(&st, &r, 1, &ad_emlrtRTEI);
  loop_ub = distance->size[0];
  i = r->size[0];
  r->size[0] = distance->size[0];
  emxEnsureCapacity_real_T(&st, r, i, &ad_emlrtRTEI);
  r1 = r->data;
  b = muDoubleScalarCos(model[4]);
  b_model = model[1];
  emxInit_real_T(&st, &r2, 1, &bd_emlrtRTEI);
  i = r2->size[0];
  r2->size[0] = points->size[0];
  emxEnsureCapacity_real_T(&st, r2, i, &bd_emlrtRTEI);
  r3 = r2->data;
  scalarLB_tmp = (distance->size[0] / 2) << 1;
  vectorUB_tmp = scalarLB_tmp - 2;
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    r4 = _mm_loadu_pd(&distance_data[i]);
    _mm_storeu_pd(&r1[i], _mm_mul_pd(r4, _mm_set1_pd(-varargin_1)));
    _mm_storeu_pd(&r3[i],
                  _mm_sub_pd(_mm_loadu_pd(&points_data[i + points->size[0]]),
                             _mm_set1_pd(b_model)));
  }
  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = distance_data[i] * -varargin_1;
    r3[i] = points_data[i + points->size[0]] - b_model;
  }
  emxInit_real_T(&st, &r5, 1, &ad_emlrtRTEI);
  b_loop_ub = r2->size[0];
  i = r5->size[0];
  r5->size[0] = r2->size[0];
  emxEnsureCapacity_real_T(&st, r5, i, &cd_emlrtRTEI);
  varargout_1_data = r5->data;
  scalarLB = (r2->size[0] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r4 = _mm_loadu_pd(&r3[i]);
    _mm_storeu_pd(&varargout_1_data[i], _mm_mul_pd(r4, _mm_set1_pd(b)));
  }
  for (i = scalarLB; i < b_loop_ub; i++) {
    varargout_1_data[i] = r3[i] * b;
  }
  b_loop_ub = r->size[0];
  if ((r->size[0] != r5->size[0]) &&
      ((r->size[0] != 1) && (r5->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[0], r5->size[0], &i_emlrtECI, &st);
  }
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    r4 = _mm_loadu_pd(&distance_data[i]);
    _mm_storeu_pd(
        &distance_data[i],
        _mm_mul_pd(_mm_mul_pd(r4, _mm_set1_pd(-1.0)), _mm_set1_pd(b)));
    r4 = _mm_loadu_pd(&r3[i]);
    _mm_storeu_pd(&r3[i], _mm_mul_pd(r4, _mm_set1_pd(-varargin_1)));
  }
  for (i = scalarLB_tmp; i < loop_ub; i++) {
    distance_data[i] = -distance_data[i] * b;
    r3[i] *= -varargin_1;
  }
  loop_ub = distance->size[0];
  if ((distance->size[0] != r2->size[0]) &&
      ((distance->size[0] != 1) && (r2->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(distance->size[0], r2->size[0], &h_emlrtECI,
                                &st);
  }
  b_st.site = &ll_emlrtRSI;
  c_st.site = &oe_emlrtRSI;
  if (r->size[0] == r5->size[0]) {
    for (i = 0; i < b_loop_ub; i++) {
      varargin_1 = (r1[i] + varargout_1_data[i]) / model[2];
      r1[i] = varargin_1 * varargin_1;
    }
  } else {
    d_st.site = &dm_emlrtRSI;
    binary_expand_op_4(&d_st, r, r5, model);
    r1 = r->data;
  }
  emxFree_real_T(&c_st, &r5);
  b_st.site = &ll_emlrtRSI;
  c_st.site = &oe_emlrtRSI;
  if (distance->size[0] == r2->size[0]) {
    i = r2->size[0];
    r2->size[0] = distance->size[0];
    emxEnsureCapacity_real_T(&c_st, r2, i, &dd_emlrtRTEI);
    r3 = r2->data;
    for (i = 0; i < loop_ub; i++) {
      varargin_1 = (distance_data[i] + r3[i]) / model[3];
      r3[i] = varargin_1 * varargin_1;
    }
  } else {
    d_st.site = &dm_emlrtRSI;
    binary_expand_op_3(&d_st, r2, distance, model);
    r3 = r2->data;
  }
  loop_ub = r->size[0];
  if ((r->size[0] != r2->size[0]) &&
      ((r->size[0] != 1) && (r2->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[0], r2->size[0], &g_emlrtECI, &st);
  }
  b_st.site = &ll_emlrtRSI;
  c_st.site = &oe_emlrtRSI;
  if (r->size[0] == r2->size[0]) {
    i = distance->size[0];
    distance->size[0] = r->size[0];
    emxEnsureCapacity_real_T(&c_st, distance, i, &ed_emlrtRTEI);
    distance_data = distance->data;
    for (i = 0; i < loop_ub; i++) {
      varargin_1 = (r1[i] + r3[i]) - 1.0;
      distance_data[i] = varargin_1 * varargin_1;
    }
  } else {
    d_st.site = &dm_emlrtRSI;
    binary_expand_op_2(&d_st, distance, r, r2);
    distance_data = distance->data;
  }
  emxFree_real_T(&c_st, &r2);
  emxFree_real_T(&c_st, &r);
  st.site = &kl_emlrtRSI;
  b_st.site = &re_emlrtRSI;
  c_st.site = &se_emlrtRSI;
  d_st.site = &y_emlrtRSI;
  if (distance->size[0] == 0) {
    varargout_1->size[0] = 0;
  } else {
    e_st.site = &ml_emlrtRSI;
    loop_ub = distance->size[0];
    i = varargout_1->size[0];
    varargout_1->size[0] = distance->size[0];
    emxEnsureCapacity_real_T(&e_st, varargout_1, i, &fd_emlrtRTEI);
    varargout_1_data = varargout_1->data;
    f_st.site = &nl_emlrtRSI;
    if (distance->size[0] > 2147483646) {
      g_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&g_st);
    }
    for (scalarLB = 0; scalarLB < loop_ub; scalarLB++) {
      varargout_1_data[scalarLB] = distance_data[scalarLB];
    }
  }
  emxFree_real_T(&d_st, &distance);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

boolean_T pcfitellipse_anonFcn4(const emlrtStack *sp, const real_T Pbar[36],
                                const real_T R[25], const real_T Yhbar[5],
                                real_T MD_threshold, const real_T model_data[],
                                int32_T model_size)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T a[30];
  real_T b_a[25];
  real_T Y[5];
  real_T Ytilde[5];
  real_T b_Y;
  int32_T a_tmp;
  int32_T i;
  int32_T i1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qk_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  /*  weightも入ってた */
  /* イノベーション共分散行列 */
  if (model_size < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, model_size, &eb_emlrtBCI, &st);
  }
  if (model_size < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &fb_emlrtBCI, &st);
  }
  if (model_size < 5) {
    emlrtDynamicBoundsCheckR2012b(5, 1, model_size, &gb_emlrtBCI, &st);
  }
  /*  観測値 */
  Ytilde[0] = model_data[0] - Yhbar[0];
  Ytilde[1] = model_data[1] - Yhbar[1];
  Ytilde[2] = model_data[4] - Yhbar[2];
  Ytilde[3] = model_data[2] - Yhbar[3];
  Ytilde[4] = model_data[3] - Yhbar[4];
  /*  観測予測誤差 */
  b_st.site = &rk_emlrtRSI;
  for (i = 0; i < 5; i++) {
    Y[i] = Ytilde[i];
    for (i1 = 0; i1 < 6; i1++) {
      b_Y = 0.0;
      for (a_tmp = 0; a_tmp < 6; a_tmp++) {
        b_Y += (real_T)iv[i + 5 * a_tmp] * Pbar[a_tmp + 6 * i1];
      }
      a[i + 5 * i1] = b_Y;
    }
    for (i1 = 0; i1 < 5; i1++) {
      b_Y = 0.0;
      for (a_tmp = 0; a_tmp < 6; a_tmp++) {
        b_Y += a[i + 5 * a_tmp] * (real_T)iv1[a_tmp + 6 * i1];
      }
      a_tmp = i + 5 * i1;
      b_a[a_tmp] = b_Y + R[a_tmp];
    }
  }
  c_st.site = &sk_emlrtRSI;
  mrdiv(&c_st, Y, b_a);
  b_Y = 0.0;
  for (i = 0; i < 5; i++) {
    b_Y += Y[i] * Ytilde[i];
  }
  b_st.site = &rk_emlrtRSI;
  if (b_Y < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &i_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  return muDoubleScalarSqrt(b_Y) < MD_threshold;
  /*  MahalDist:(x y theta alpha beta)の順  */
}

/* End of code generation (pcfitellipse.c) */
