/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_observation_data.c
 *
 * Code generation for function 'calc_observation_data'
 *
 */

/* Include files */
#include "calc_observation_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

boolean_T state_not_empty_main;

boolean_T method_not_empty_main;

emlrtContext emlrtContextGlobal = {
    true,                                               /* bFirstTime */
    false,                                              /* bInitialized */
    131659U,                                            /* fVersionInfo */
    NULL,                                               /* fErrorFunction */
    "calc_observation",                                 /* fFunctionName */
    NULL,                                               /* fRTCallStack */
    false,                                              /* bDebugMode */
    {3997702259U, 743900116U, 937962426U, 2289393452U}, /* fSigWrd */
    NULL                                                /* fSigMem */
};

emlrtRSInfo u_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo x_emlrtRSI = {
    112,    /* lineNo */
    "mean", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/mean.m" /* pathName
                                                                      */
};

emlrtRSInfo y_emlrtRSI = {
    86,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

emlrtRSInfo ab_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

emlrtRSInfo bb_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

emlrtRSInfo cb_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

emlrtRSInfo eb_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

emlrtRSInfo vb_emlrtRSI =
    {
        23,      /* lineNo */
        "xrotg", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xrotg.m" /* pathName */
};

emlrtRSInfo nc_emlrtRSI = {
    39,    /* lineNo */
    "cat", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                       */
};

emlrtRSInfo de_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" /* pathName */
};

emlrtRSInfo oe_emlrtRSI = {
    71,                                                           /* lineNo */
    "power",                                                      /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

emlrtRSInfo re_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                     */
};

emlrtRSInfo se_emlrtRSI =
    {
        99,        /* lineNo */
        "sumprod", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
        "sumprod.m" /* pathName */
};

emlrtRSInfo xe_emlrtRSI =
    {
        86,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo ye_emlrtRSI =
    {
        71,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo af_emlrtRSI =
    {
        74,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo cf_emlrtRSI =
    {
        38,      /* lineNo */
        "xcopy", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xcopy.m" /* pathName */
};

emlrtRSInfo df_emlrtRSI =
    {
        69,      /* lineNo */
        "xcopy", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xcopy.m" /* pathName */
};

emlrtRSInfo ff_emlrtRSI = {
    1,                /* lineNo */
    "setProblemType", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/setProblemType.p" /* pathName */
};

emlrtRSInfo lf_emlrtRSI =
    {
        58,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo mf_emlrtRSI =
    {
        51,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo nf_emlrtRSI =
    {
        23,       /* lineNo */
        "ixamax", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "ixamax.m" /* pathName */
};

emlrtRSInfo of_emlrtRSI = {
    24,       /* lineNo */
    "ixamax", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
    "ixamax.m" /* pathName */
};

emlrtRSInfo uf_emlrtRSI = {
    1,           /* lineNo */
    "factorQRE", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+QRManager/"
    "factorQRE.p" /* pathName */
};

emlrtRSInfo gg_emlrtRSI =
    {
        31,      /* lineNo */
        "xscal", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xscal.m" /* pathName */
};

emlrtRSInfo hg_emlrtRSI =
    {
        18,      /* lineNo */
        "xscal", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xscal.m" /* pathName */
};

emlrtRSInfo ig_emlrtRSI =
    {
        37,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo
    jg_emlrtRSI =
        {
            45,     /* lineNo */
            "xger", /* fcnName */
            "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
            "xger.m" /* pathName */
};

emlrtRSInfo kg_emlrtRSI =
    {
        15,     /* lineNo */
        "xger", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xger.m" /* pathName */
};

emlrtRSInfo lg_emlrtRSI =
    {
        41,      /* lineNo */
        "xgerx", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" /* pathName */
};

emlrtRSInfo mg_emlrtRSI = {
    1,                /* lineNo */
    "computeSquareQ", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+QRManager/"
    "computeSquareQ.p" /* pathName */
};

emlrtRSInfo qg_emlrtRSI =
    {
        55,      /* lineNo */
        "xtrsv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xtrsv.m" /* pathName */
};

emlrtRSInfo xg_emlrtRSI =
    {
        1,        /* lineNo */
        "driver", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
        "driver.p" /* pathName */
};

emlrtRSInfo
    dh_emlrtRSI =
        {
            35,     /* lineNo */
            "xdot", /* fcnName */
            "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
            "xdot.m" /* pathName */
};

emlrtRSInfo eh_emlrtRSI =
    {
        15,     /* lineNo */
        "xdot", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xdot.m" /* pathName */
};

emlrtRSInfo fh_emlrtRSI =
    {
        42,      /* lineNo */
        "xdotx", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xdotx.m" /* pathName */
};

emlrtRSInfo hh_emlrtRSI =
    {
        1,           /* lineNo */
        "countsort", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+utils/"
        "countsort.p" /* pathName */
};

emlrtRSInfo rh_emlrtRSI = {
    1,                        /* lineNo */
    "maxConstraintViolation", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation.p" /* pathName */
};

emlrtRSInfo sh_emlrtRSI = {
    1,                                           /* lineNo */
    "maxConstraintViolation_AMats_regularized_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation_AMats_regularized_.p" /* pathName */
};

emlrtRSInfo th_emlrtRSI =
    {
        41,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo uh_emlrtRSI = {
    1,                                              /* lineNo */
    "maxConstraintViolation_AMats_nonregularized_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation_AMats_nonregularized_.p" /* pathName */
};

emlrtRSInfo xh_emlrtRSI = {
    1,         /* lineNo */
    "iterate", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "iterate.p" /* pathName */
};

emlrtRSInfo di_emlrtRSI =
    {
        24,     /* lineNo */
        "xrot", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xrot.m" /* pathName */
};

emlrtRSInfo mi_emlrtRSI =
    {
        1,        /* lineNo */
        "factor", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+CholManager/"
        "factor.p" /* pathName */
};

emlrtRSInfo pi_emlrtRSI = {
    1,        /* lineNo */
    "factor", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/factor.p" /* pathName */
};

emlrtRSInfo ri_emlrtRSI =
    {
        54,      /* lineNo */
        "xgerx", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" /* pathName */
};

emlrtRSInfo si_emlrtRSI =
    {
        1,       /* lineNo */
        "solve", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+CholManager/"
        "solve.p" /* pathName */
};

emlrtRSInfo ti_emlrtRSI =
    {
        65,      /* lineNo */
        "xtrsv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xtrsv.m" /* pathName */
};

emlrtRSInfo ui_emlrtRSI =
    {
        72,      /* lineNo */
        "xtrsv", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xtrsv.m" /* pathName */
};

emlrtRSInfo nj_emlrtRSI = {
    1,             /* lineNo */
    "addLBConstr", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addLBConstr.p" /* pathName */
};

emlrtRSInfo pj_emlrtRSI = {
    1,             /* lineNo */
    "addUBConstr", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addUBConstr.p" /* pathName */
};

emlrtRSInfo qj_emlrtRSI = {
    1,                          /* lineNo */
    "checkUnboundedOrIllPosed", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+stopping/checkUnboundedOrIllPosed.p" /* pathName */
};

emlrtRSInfo rj_emlrtRSI = {
    1,                            /* lineNo */
    "checkStoppingAndUpdateFval", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+stopping/checkStoppingAndUpdateFval.p" /* pathName */
};

emlrtRSInfo vj_emlrtRSI = {
    1,                    /* lineNo */
    "updatePenaltyParam", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+MeritFunction/updatePenaltyParam.p" /* pathName */
};

emlrtRSInfo qk_emlrtRSI = {
    31,                                                            /* lineNo */
    "@(model)validateModelFcn(model,Pbar,c,R,Yhbar,MD_threshold)", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pathName */
};

emlrtRSInfo rk_emlrtRSI = {
    115,                             /* lineNo */
    "pcfitellipse/validateModelFcn", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pathName */
};

emlrtRSInfo sk_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "mrdivide_helper.m" /* pathName */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t calc_observation_nestLockGlobal;

emlrtRTEInfo i_emlrtRTEI = {
    13,                                                            /* lineNo */
    9,                                                             /* colNo */
    "sqrt",                                                        /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elfun/sqrt.m" /* pName */
};

emlrtBCInfo rb_emlrtBCI = {
    1,                /* iFirst */
    15,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "setProblemType", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/setProblemType.p", /* pName */
    3                               /* checkKind */
};

emlrtBCInfo sb_emlrtBCI = {
    1,                /* iFirst */
    15,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "setProblemType", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/setProblemType.p", /* pName */
    0                               /* checkKind */
};

emlrtRTEInfo db_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" /* pName */
};

emlrtRTEInfo eb_emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" /* pName */
};

emlrtBCInfo cc_emlrtBCI = {
    1,                        /* iFirst */
    8,                        /* iLast */
    1,                        /* lineNo */
    1,                        /* colNo */
    "",                       /* aName */
    "maxConstraintViolation", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation.p", /* pName */
    0                                       /* checkKind */
};

emlrtBCInfo pc_emlrtBCI =
    {
        1,           /* iFirst */
        15,          /* iLast */
        1,           /* lineNo */
        1,           /* colNo */
        "",          /* aName */
        "countsort", /* fName */
        "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+utils/"
        "countsort.p", /* pName */
        3              /* checkKind */
};

emlrtBCInfo vc_emlrtBCI =
    {
        1,           /* iFirst */
        15,          /* iLast */
        1,           /* lineNo */
        1,           /* colNo */
        "",          /* aName */
        "countsort", /* fName */
        "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+utils/"
        "countsort.p", /* pName */
        0              /* checkKind */
};

emlrtBCInfo kd_emlrtBCI = {
    1,          /* iFirst */
    15,         /* iLast */
    1,          /* lineNo */
    1,          /* colNo */
    "",         /* aName */
    "isActive", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/isActive.p", /* pName */
    0                         /* checkKind */
};

emlrtBCInfo ld_emlrtBCI = {
    1,         /* iFirst */
    15,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "iterate", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "iterate.p", /* pName */
    0            /* checkKind */
};

emlrtBCInfo md_emlrtBCI = {
    1,         /* iFirst */
    15,        /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "iterate", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "iterate.p", /* pName */
    3            /* checkKind */
};

emlrtBCInfo od_emlrtBCI = {
    1,                            /* iFirst */
    8,                            /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "checkStoppingAndUpdateFval", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+stopping/checkStoppingAndUpdateFval.p", /* pName */
    0                                         /* checkKind */
};

emlrtBCInfo pd_emlrtBCI = {
    1,                            /* iFirst */
    8,                            /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "checkStoppingAndUpdateFval", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+stopping/checkStoppingAndUpdateFval.p", /* pName */
    3                                         /* checkKind */
};

emlrtRTEInfo fb_emlrtRTEI = {
    18,                               /* lineNo */
    27,                               /* colNo */
    "eml_int_forloop_overflow_check", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pName */
};

emlrtBCInfo ee_emlrtBCI = {
    1,        /* iFirst */
    225,      /* iLast */
    1,        /* lineNo */
    1,        /* colNo */
    "",       /* aName */
    "factor", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/factor.p", /* pName */
    0                                  /* checkKind */
};

emlrtBCInfo pe_emlrtBCI = {
    1,                         /* iFirst */
    15,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "addConstrUpdateRecords_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addConstrUpdateRecords_.p", /* pName */
    3                                        /* checkKind */
};

emlrtRTEInfo dd_emlrtRTEI = {
    109,            /* lineNo */
    86,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

emlrtRTEInfo ed_emlrtRTEI = {
    109,            /* lineNo */
    9,              /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

const int8_T iv[30] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1};

const int8_T iv1[30] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
                        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1};

/* End of code generation (calc_observation_data.c) */
