/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Faster_processingPcloud_data.c
 *
 * Code generation for function 'Faster_processingPcloud_data'
 *
 */

/* Include files */
#include "Faster_processingPcloud_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131659U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "Faster_processingPcloud",                            /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {1556225339U, 3621151966U, 3445039243U, 1907043489U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo ab_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo ub_emlrtRSI =
    {
        93,                   /* lineNo */
        "validateattributes", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/lang/"
        "validateattributes.m" /* pathName */
};

emlrtRSInfo gd_emlrtRSI = {
    21,                                                            /* lineNo */
    "det",                                                         /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/matfun/det.m" /* pathName
                                                                    */
};

emlrtRSInfo hd_emlrtRSI =
    {
        30,       /* lineNo */
        "xgetrf", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgetrf.m" /* pathName */
};

emlrtRSInfo id_emlrtRSI = {
    55,        /* lineNo */
    "xzgetrf", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" /* pathName */
};

emlrtRSInfo jd_emlrtRSI = {
    63,        /* lineNo */
    "xzgetrf", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" /* pathName */
};

emlrtRSInfo kd_emlrtRSI =
    {
        45,      /* lineNo */
        "xgeru", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgeru.m" /* pathName */
};

emlrtRSInfo
    ld_emlrtRSI =
        {
            45,     /* lineNo */
            "xger", /* fcnName */
            "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
            "xger.m" /* pathName */
};

emlrtRSInfo md_emlrtRSI =
    {
        15,     /* lineNo */
        "xger", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xger.m" /* pathName */
};

emlrtRSInfo nd_emlrtRSI =
    {
        41,      /* lineNo */
        "xgerx", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" /* pathName */
};

emlrtRSInfo od_emlrtRSI =
    {
        54,      /* lineNo */
        "xgerx", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" /* pathName */
};

emlrtRSInfo re_emlrtRSI = {
    39,                                                            /* lineNo */
    "find",                                                        /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

emlrtRSInfo df_emlrtRSI = {
    509,                                /* lineNo */
    "pointCloudBase/arrayNotSupported", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

emlrtRSInfo ef_emlrtRSI = {
    15,    /* lineNo */
    "min", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/min.m" /* pathName
                                                                     */
};

emlrtRSInfo ff_emlrtRSI = {
    66,         /* lineNo */
    "minOrMax", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo gf_emlrtRSI = {
    112,       /* lineNo */
    "minimum", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo hf_emlrtRSI =
    {
        273,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo if_emlrtRSI =
    {
        962,                    /* lineNo */
        "minRealVectorOmitNaN", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo jf_emlrtRSI = {
    73,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo kf_emlrtRSI = {
    65,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo lf_emlrtRSI = {
    114,         /* lineNo */
    "findFirst", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo mf_emlrtRSI = {
    131,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo nf_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/max.m" /* pathName
                                                                     */
};

emlrtRSInfo of_emlrtRSI = {
    64,         /* lineNo */
    "minOrMax", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo pf_emlrtRSI = {
    99,        /* lineNo */
    "maximum", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo qf_emlrtRSI =
    {
        255,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo rf_emlrtRSI =
    {
        966,                    /* lineNo */
        "maxRealVectorOmitNaN", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo sf_emlrtRSI = {
    207,                         /* lineNo */
    "pointCloudBase/subsetImpl", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

emlrtRSInfo vh_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName
                                                                       */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t Faster_processingPcloud_nestLockGlobal;

emlrtRTEInfo g_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatescalar", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatescalar.m" /* pName */
};

emlrtRTEInfo i_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatefinite.m" /* pName */
};

emlrtRTEInfo m_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatenonnan", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnan.m" /* pName */
};

emlrtRTEInfo t_emlrtRTEI = {
    510,                                /* lineNo */
    17,                                 /* colNo */
    "pointCloudBase/arrayNotSupported", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

emlrtBCInfo m_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    1,           /* lineNo */
    1,           /* colNo */
    "",          /* aName */
    "getSubset", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+pc/getSubset.p", /* pName */
    0                            /* checkKind */
};

emlrtRTEInfo y_emlrtRTEI = {
    13,                                                            /* lineNo */
    9,                                                             /* colNo */
    "sqrt",                                                        /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elfun/sqrt.m" /* pName */
};

emlrtRTEInfo lc_emlrtRTEI = {
    31,                                                            /* lineNo */
    6,                                                             /* colNo */
    "find",                                                        /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

emlrtRTEInfo bd_emlrtRTEI = {
    1,           /* lineNo */
    1,           /* colNo */
    "getSubset", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+pc/getSubset.p" /* pName */
};

/* End of code generation (Faster_processingPcloud_data.c) */
