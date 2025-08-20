/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexLidarTracker_data.c
 *
 * Code generation for function 'mexLidarTracker_data'
 *
 */

/* Include files */
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

boolean_T isMexOutdated;

const char_T *mexLidarTracker_complete_name;

const char_T *c_HelperBoundingBoxDetector_Hel;

const char_T *c_HelperBoundingBoxDetector_ste;

const char_T *cropPointCloud2_complete_name;

const char_T *getBoundingBoxes_complete_name;

const char_T *homogeneous_complete_name;

const char_T *c_assembleDetections_complete_n;

const char_T *initializeEKF_complete_name;

const char_T *c_helperCalcDetectability_compl;

emlrtContext emlrtContextGlobal = {
    true,                                               /* bFirstTime */
    false,                                              /* bInitialized */
    131642U,                                            /* fVersionInfo */
    NULL,                                               /* fErrorFunction */
    "mexLidarTracker",                                  /* fFunctionName */
    NULL,                                               /* fRTCallStack */
    false,                                              /* bDebugMode */
    {1289804844U, 474517995U, 4058475124U, 792733075U}, /* fSigWrd */
    NULL                                                /* fSigMem */
};

emlrtRSInfo l_emlrtRSI = {
    1,                    /* lineNo */
    "SystemCore/release", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pathName */
};

emlrtRSInfo ib_emlrtRSI = {
    28,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
                                                                      */
};

emlrtRSInfo jb_emlrtRSI = {
    66,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
                                                                      */
};

emlrtRSInfo lb_emlrtRSI = {
    71,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
                                                                      */
};

emlrtRSInfo mb_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo jc_emlrtRSI =
    {
        93,                   /* lineNo */
        "validateattributes", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/lang/"
        "validateattributes.m" /* pathName */
};

emlrtRSInfo oc_emlrtRSI = {
    14,                                                            /* lineNo */
    "svd",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/svd.m" /* pathName
                                                                    */
};

emlrtRSInfo pc_emlrtRSI = {
    18,                                                            /* lineNo */
    "svd",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/svd.m" /* pathName
                                                                    */
};

emlrtRSInfo qc_emlrtRSI =
    {
        29,             /* lineNo */
        "anyNonFinite", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "anyNonFinite.m" /* pathName */
};

emlrtRSInfo
    rc_emlrtRSI =
        {
            44,          /* lineNo */
            "vAllOrAny", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
            "vAllOrAny.m" /* pathName */
};

emlrtRSInfo tc_emlrtRSI = {
    28,    /* lineNo */
    "svd", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/svd.m" /* pathName
                                                                       */
};

emlrtRSInfo uc_emlrtRSI = {
    107,          /* lineNo */
    "callLAPACK", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/svd.m" /* pathName
                                                                       */
};

emlrtRSInfo vc_emlrtRSI =
    {
        34,       /* lineNo */
        "xgesvd", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pathName */
};

emlrtRSInfo jd_emlrtRSI =
    {
        23,      /* lineNo */
        "xnrm2", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "xnrm2.m" /* pathName */
};

emlrtRSInfo kd_emlrtRSI =
    {
        38,      /* lineNo */
        "xnrm2", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xnrm2.m" /* pathName */
};

emlrtRSInfo vd_emlrtRSI = {
    15,    /* lineNo */
    "min", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/min.m" /* pathName
                                                                     */
};

emlrtRSInfo wd_emlrtRSI = {
    46,         /* lineNo */
    "minOrMax", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo xd_emlrtRSI = {
    92,        /* lineNo */
    "minimum", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo yd_emlrtRSI =
    {
        208,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo ae_emlrtRSI =
    {
        897,                    /* lineNo */
        "minRealVectorOmitNaN", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo be_emlrtRSI = {
    72,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo ce_emlrtRSI = {
    130,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo ie_emlrtRSI =
    {
        23,       /* lineNo */
        "ixamax", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "ixamax.m" /* pathName */
};

emlrtRSInfo je_emlrtRSI = {
    24,       /* lineNo */
    "ixamax", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
    "ixamax.m" /* pathName */
};

emlrtRSInfo
    le_emlrtRSI =
        {
            45,     /* lineNo */
            "xger", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
            "xger.m" /* pathName */
};

emlrtRSInfo me_emlrtRSI =
    {
        15,     /* lineNo */
        "xger", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xger.m" /* pathName */
};

emlrtRSInfo ne_emlrtRSI =
    {
        54,      /* lineNo */
        "xgerx", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" /* pathName */
};

emlrtRSInfo oe_emlrtRSI =
    {
        41,      /* lineNo */
        "xgerx", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" /* pathName */
};

emlrtRSInfo we_emlrtRSI = {
    11,               /* lineNo */
    "validatescalar", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatescalar.m" /* pathName */
};

emlrtRSInfo ef_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

emlrtRSInfo ff_emlrtRSI =
    {
        142,      /* lineNo */
        "mtimes", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

emlrtRSInfo gf_emlrtRSI = {
    51,       /* lineNo */
    "mtimes", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
    "mtimes.m" /* pathName */
};

emlrtRSInfo hf_emlrtRSI =
    {
        178,           /* lineNo */
        "mtimes_blas", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

emlrtRSInfo lf_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/max.m" /* pathName
                                                                     */
};

emlrtRSInfo mf_emlrtRSI = {
    44,         /* lineNo */
    "minOrMax", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo nf_emlrtRSI = {
    79,        /* lineNo */
    "maximum", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo of_emlrtRSI =
    {
        190,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo pf_emlrtRSI =
    {
        901,                    /* lineNo */
        "maxRealVectorOmitNaN", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo qf_emlrtRSI =
    {
        69,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

emlrtRSInfo bg_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

emlrtRSInfo cg_emlrtRSI = {
    39,                                                            /* lineNo */
    "find",                                                        /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

emlrtRSInfo ng_emlrtRSI = {
    509,                                /* lineNo */
    "pointCloudBase/arrayNotSupported", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

emlrtRSInfo og_emlrtRSI = {
    64,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo pg_emlrtRSI = {
    113,         /* lineNo */
    "findFirst", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo qg_emlrtRSI = {
    207,                         /* lineNo */
    "pointCloudBase/subsetImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

emlrtRSInfo uh_emlrtRSI = {
    15,    /* lineNo */
    "sum", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                     */
};

emlrtRSInfo vh_emlrtRSI =
    {
        99,        /* lineNo */
        "sumprod", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
        "sumprod.m" /* pathName */
};

emlrtRSInfo wh_emlrtRSI = {
    138,                     /* lineNo */
    "combineVectorElements", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

emlrtRSInfo pi_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName
                                                                       */
};

emlrtRSInfo qi_emlrtRSI = {
    71,                                                           /* lineNo */
    "power",                                                      /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

emlrtRSInfo vi_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                     */
};

emlrtRSInfo wi_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

emlrtRSInfo yi_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

emlrtRSInfo aj_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

emlrtRSInfo ej_emlrtRSI = {
    33,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

emlrtRSInfo fj_emlrtRSI = {
    48,                                                            /* lineNo */
    "unique",                                                      /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

emlrtRSInfo gj_emlrtRSI = {
    164,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

emlrtRSInfo hj_emlrtRSI = {
    166,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

emlrtRSInfo ij_emlrtRSI = {
    210,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

emlrtRSInfo kj_emlrtRSI = {
    234,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

emlrtRSInfo mj_emlrtRSI = {
    248,                                                           /* lineNo */
    "unique_vector",                                               /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pathName
                                                                    */
};

emlrtRSInfo nj_emlrtRSI = {
    145,       /* lineNo */
    "sortIdx", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo
    oj_emlrtRSI =
        {
            57,          /* lineNo */
            "mergesort", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pathName */
};

emlrtRSInfo
    pj_emlrtRSI =
        {
            113,         /* lineNo */
            "mergesort", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pathName */
};

emlrtRSInfo tj_emlrtRSI = {
    42,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/sort.m" /* pathName
                                                                      */
};

emlrtRSInfo ck_emlrtRSI = {
    105,       /* lineNo */
    "sortIdx", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo dk_emlrtRSI = {
    308,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo ek_emlrtRSI = {
    316,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo fk_emlrtRSI = {
    317,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo gk_emlrtRSI = {
    325,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo hk_emlrtRSI = {
    333,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo ik_emlrtRSI = {
    443,                      /* lineNo */
    "initialize_vector_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo jk_emlrtRSI = {
    468,                      /* lineNo */
    "initialize_vector_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo kk_emlrtRSI = {
    473,                      /* lineNo */
    "initialize_vector_sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo lk_emlrtRSI = {
    587,                /* lineNo */
    "merge_pow2_block", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo mk_emlrtRSI = {
    589,                /* lineNo */
    "merge_pow2_block", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo nk_emlrtRSI = {
    617,                /* lineNo */
    "merge_pow2_block", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo ok_emlrtRSI = {
    499,           /* lineNo */
    "merge_block", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo qk_emlrtRSI = {
    507,           /* lineNo */
    "merge_block", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo rk_emlrtRSI = {
    514,           /* lineNo */
    "merge_block", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

emlrtRSInfo vk_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

emlrtRSInfo xk_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

emlrtRSInfo ml_emlrtRSI = {
    18,                                /* lineNo */
    "isSymmetricPositiveSemiDefinite", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/isSymmetricPositiveSemiDefinite.m" /* pathName
                                                                           */
};

emlrtRSInfo nl_emlrtRSI = {
    20,                                /* lineNo */
    "isSymmetricPositiveSemiDefinite", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/isSymmetricPositiveSemiDefinite.m" /* pathName
                                                                           */
};

emlrtRSInfo ol_emlrtRSI = {
    13,                                                         /* lineNo */
    "all",                                                      /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/all.m" /* pathName */
};

emlrtRSInfo pl_emlrtRSI = {
    143,        /* lineNo */
    "allOrAny", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pathName
                                                                            */
};

emlrtRSInfo ql_emlrtRSI = {
    81,                                                            /* lineNo */
    "eig",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName
                                                                    */
};

emlrtRSInfo rl_emlrtRSI = {
    127,                                                           /* lineNo */
    "eig",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName
                                                                    */
};

emlrtRSInfo sl_emlrtRSI = {
    135,                                                           /* lineNo */
    "eig",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName
                                                                    */
};

emlrtRSInfo tl_emlrtRSI = {
    143,                                                           /* lineNo */
    "eig",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName
                                                                    */
};

emlrtRSInfo ul_emlrtRSI = {
    13,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pathName */
};

emlrtRSInfo vl_emlrtRSI = {
    40,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pathName */
};

emlrtRSInfo wl_emlrtRSI = {
    8,         /* lineNo */
    "xsyheev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xsyheev.m" /* pathName */
};

emlrtRSInfo xl_emlrtRSI = {
    61,              /* lineNo */
    "ceval_xsyheev", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xsyheev.m" /* pathName */
};

emlrtRSInfo yl_emlrtRSI = {
    32,        /* lineNo */
    "xzlascl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlascl.m" /* pathName */
};

emlrtRSInfo am_emlrtRSI = {
    34,        /* lineNo */
    "xzlascl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlascl.m" /* pathName */
};

emlrtRSInfo bm_emlrtRSI = {
    81,        /* lineNo */
    "xzlarfg", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarfg.m" /* pathName */
};

emlrtRSInfo dm_emlrtRSI = {
    68,        /* lineNo */
    "xzlarfg", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarfg.m" /* pathName */
};

emlrtRSInfo em_emlrtRSI = {
    53,        /* lineNo */
    "xzlarfg", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarfg.m" /* pathName */
};

emlrtRSInfo fm_emlrtRSI = {
    41,        /* lineNo */
    "xzlarfg", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarfg.m" /* pathName */
};

emlrtRSInfo gm_emlrtRSI = {
    20,        /* lineNo */
    "xzlarfg", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarfg.m" /* pathName */
};

emlrtRSInfo hm_emlrtRSI = {
    10,                         /* lineNo */
    "eigSkewHermitianStandard", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
    "eigSkewHermitianStandard.m" /* pathName */
};

emlrtRSInfo im_emlrtRSI = {
    19,                             /* lineNo */
    "eigRealSkewSymmetricStandard", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
    "eigRealSkewSymmetricStandard.m" /* pathName */
};

emlrtRSInfo jm_emlrtRSI = {
    35,      /* lineNo */
    "schur", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName
                                                                      */
};

emlrtRSInfo km_emlrtRSI = {
    52,      /* lineNo */
    "schur", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName
                                                                      */
};

emlrtRSInfo lm_emlrtRSI = {
    54,      /* lineNo */
    "schur", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName
                                                                      */
};

emlrtRSInfo mm_emlrtRSI = {
    83,      /* lineNo */
    "schur", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName
                                                                      */
};

emlrtRSInfo nm_emlrtRSI =
    {
        18,       /* lineNo */
        "xgehrd", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgehrd.m" /* pathName */
};

emlrtRSInfo om_emlrtRSI = {
    46,        /* lineNo */
    "xzgehrd", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgehrd.m" /* pathName */
};

emlrtRSInfo pm_emlrtRSI = {
    50,        /* lineNo */
    "xzgehrd", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgehrd.m" /* pathName */
};

emlrtRSInfo qm_emlrtRSI = {
    58,        /* lineNo */
    "xzgehrd", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgehrd.m" /* pathName */
};

emlrtRSInfo rm_emlrtRSI = {
    53,       /* lineNo */
    "xzlarf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarf.m" /* pathName */
};

emlrtRSInfo sm_emlrtRSI = {
    84,       /* lineNo */
    "xzlarf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarf.m" /* pathName */
};

emlrtRSInfo tm_emlrtRSI = {
    91,       /* lineNo */
    "xzlarf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarf.m" /* pathName */
};

emlrtRSInfo vm_emlrtRSI =
    {
        64,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo wm_emlrtRSI =
    {
        58,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo ym_emlrtRSI =
    {
        37,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo an_emlrtRSI =
    {
        45,      /* lineNo */
        "xgerc", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgerc.m" /* pathName */
};

emlrtRSInfo bn_emlrtRSI = {
    75,       /* lineNo */
    "xzlarf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarf.m" /* pathName */
};

emlrtRSInfo cn_emlrtRSI = {
    68,       /* lineNo */
    "xzlarf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarf.m" /* pathName */
};

emlrtRSInfo dn_emlrtRSI = {
    50,       /* lineNo */
    "xzlarf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarf.m" /* pathName */
};

emlrtRSInfo fn_emlrtRSI =
    {
        74,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

emlrtRSInfo on_emlrtRSI = {
    243,       /* lineNo */
    "xdlahqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xdlahqr.m" /* pathName */
};

emlrtRSInfo io_emlrtRSI = {
    34,            /* lineNo */
    "eigStandard", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
    "eigStandard.m" /* pathName */
};

emlrtRSInfo jo_emlrtRSI = {
    45,            /* lineNo */
    "eigStandard", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
    "eigStandard.m" /* pathName */
};

emlrtRSInfo ip_emlrtRSI =
    {
        30,      /* lineNo */
        "xswap", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "xswap.m" /* pathName */
};

emlrtRSInfo jp_emlrtRSI =
    {
        20,      /* lineNo */
        "xswap", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xswap.m" /* pathName */
};

emlrtRSInfo lp_emlrtRSI = {
    1,                 /* lineNo */
    "SystemCore/step", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pathName */
};

emlrtRSInfo mp_emlrtRSI = {
    1,                          /* lineNo */
    "SystemCore/setupAndReset", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pathName */
};

emlrtRSInfo np_emlrtRSI = {
    1,                  /* lineNo */
    "SystemCore/setup", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pathName */
};

emlrtRSInfo su_emlrtRSI = {
    1264,                                        /* lineNo */
    "ExtendedKalmanFilter/set.pStateCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

emlrtRSInfo hv_emlrtRSI = {
    1046,                                       /* lineNo */
    "ExtendedKalmanFilter/get.StateCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

emlrtRSInfo iv_emlrtRSI = {
    1047,                                       /* lineNo */
    "ExtendedKalmanFilter/get.StateCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

emlrtRSInfo jv_emlrtRSI = {
    1588,                                                          /* lineNo */
    "ExtendedKalmanFilter/stateCovarianceScalarExpandIfNecessary", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

emlrtRSInfo kv_emlrtRSI = {
    1165,                                        /* lineNo */
    "ExtendedKalmanFilter/get.MeasurementNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

emlrtRSInfo lv_emlrtRSI = {
    1166,                                        /* lineNo */
    "ExtendedKalmanFilter/get.MeasurementNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

emlrtRSInfo mw_emlrtRSI = {
    112,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

emlrtRSInfo nw_emlrtRSI = {
    204,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

emlrtRSInfo ow_emlrtRSI = {
    192,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

emlrtRSInfo pw_emlrtRSI = {
    190,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

emlrtRSInfo qw_emlrtRSI = {
    173,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

emlrtRSInfo sw_emlrtRSI = {
    198,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

emlrtRSInfo hx_emlrtRSI = {
    41,    /* lineNo */
    "cat", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                       */
};

emlrtRSInfo ix_emlrtRSI = {
    113,        /* lineNo */
    "cat_impl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                       */
};

emlrtRSInfo kx_emlrtRSI = {
    39,                                   /* lineNo */
    "StrictSingleCoderUtilities/IntFind", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/+codegen/StrictSingleCoderU"
    "tilities.m" /* pathName */
};

emlrtRSInfo lx_emlrtRSI = {
    13,                                                         /* lineNo */
    "any",                                                      /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/any.m" /* pathName */
};

emlrtRSInfo sx_emlrtRSI = {
    37,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/sort.m" /* pathName
                                                                      */
};

emlrtRSInfo ey_emlrtRSI = {
    257,                                           /* lineNo */
    "AssignmentCostCalculator/validateInputsImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

emlrtRSInfo fy_emlrtRSI = {
    163,                                  /* lineNo */
    "AssignmentCostCalculator/setupImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

emlrtRSInfo gy_emlrtRSI = {
    265,                     /* lineNo */
    "ObjectTrack/get.State", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo yab_emlrtRSI = {
    28,                                                           /* lineNo */
    "colon",                                                      /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/colon.m" /* pathName */
};

emlrtRSInfo abb_emlrtRSI = {
    82,                                                           /* lineNo */
    "colon",                                                      /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/colon.m" /* pathName */
};

emlrtRSInfo
    acb_emlrtRSI =
        {
            98,         /* lineNo */
            "constvel", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
            "constvel.m" /* pathName */
};

emlrtRSInfo
    bcb_emlrtRSI =
        {
            159,        /* lineNo */
            "constvel", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
            "constvel.m" /* pathName */
};

emlrtRSInfo
    ccb_emlrtRSI =
        {
            165,        /* lineNo */
            "constvel", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
            "constvel.m" /* pathName */
};

emlrtRSInfo dcb_emlrtRSI = {
    128,      /* lineNo */
    "cvmeas", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/cvmeas.m" /* pathName
                                                                           */
};

emlrtRSInfo gcb_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "mrdivide_helper.m" /* pathName */
};

emlrtRSInfo hcb_emlrtRSI = {
    42,      /* lineNo */
    "mrdiv", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "mrdivide_helper.m" /* pathName */
};

emlrtRSInfo icb_emlrtRSI = {
    61,        /* lineNo */
    "lusolve", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

emlrtRSInfo jcb_emlrtRSI = {
    293,          /* lineNo */
    "lusolve3x3", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

emlrtRSInfo lcb_emlrtRSI = {
    90,              /* lineNo */
    "warn_singular", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

emlrtRSInfo qcb_emlrtRSI = {
    1613,                               /* lineNo */
    "ObjectTrack/sortDetectionsByTime", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo rcb_emlrtRSI = {
    1619,                               /* lineNo */
    "ObjectTrack/sortDetectionsByTime", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo cdb_emlrtRSI = {
    1846,                                                          /* lineNo */
    "ExtendedKalmanFilter/ensureStateAndStateCovarianceIsDefined", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

emlrtRSInfo rdb_emlrtRSI =
    {
        54,            /* lineNo */
        "constveljac", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "constveljac.m" /* pathName */
};

emlrtRSInfo sdb_emlrtRSI =
    {
        67,            /* lineNo */
        "constveljac", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "constveljac.m" /* pathName */
};

emlrtRSInfo tdb_emlrtRSI =
    {
        73,            /* lineNo */
        "constveljac", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "constveljac.m" /* pathName */
};

emlrtRSInfo ydb_emlrtRSI = {
    17,         /* lineNo */
    "qrFactor", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/qrFactor.m" /* pathName */
};

emlrtRSInfo aeb_emlrtRSI = {
    18,         /* lineNo */
    "qrFactor", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/qrFactor.m" /* pathName */
};

emlrtRSInfo beb_emlrtRSI =
    {
        136,      /* lineNo */
        "mtimes", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

emlrtRSInfo ceb_emlrtRSI = {
    150,    /* lineNo */
    "MMRF", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
    "mtimes.m" /* pathName */
};

emlrtRSInfo deb_emlrtRSI = {
    24,                                                           /* lineNo */
    "qr",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/qr.m" /* pathName */
};

emlrtRSInfo eeb_emlrtRSI =
    {
        35,       /* lineNo */
        "eml_qr", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
        "eml_qr.m" /* pathName */
};

emlrtRSInfo feb_emlrtRSI =
    {
        166,       /* lineNo */
        "qr_econ", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
        "eml_qr.m" /* pathName */
};

emlrtRSInfo geb_emlrtRSI =
    {
        175,       /* lineNo */
        "qr_econ", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
        "eml_qr.m" /* pathName */
};

emlrtRSInfo heb_emlrtRSI =
    {
        187,       /* lineNo */
        "qr_econ", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
        "eml_qr.m" /* pathName */
};

emlrtRSInfo ieb_emlrtRSI =
    {
        30,       /* lineNo */
        "xgeqrf", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqrf.m" /* pathName */
};

emlrtRSInfo jeb_emlrtRSI = {
    116,       /* lineNo */
    "xzgeqp3", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgeqp3.m" /* pathName */
};

emlrtRSInfo keb_emlrtRSI = {
    160,   /* lineNo */
    "qrf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgeqp3.m" /* pathName */
};

emlrtRSInfo leb_emlrtRSI = {
    146,   /* lineNo */
    "qrf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgeqp3.m" /* pathName */
};

emlrtRSInfo meb_emlrtRSI = {
    135,   /* lineNo */
    "qrf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgeqp3.m" /* pathName */
};

emlrtRSInfo neb_emlrtRSI =
    {
        202,        /* lineNo */
        "unpackQR", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/private/"
        "eml_qr.m" /* pathName */
};

emlrtRSInfo oeb_emlrtRSI =
    {
        17,       /* lineNo */
        "xorgqr", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xorgqr.m" /* pathName */
};

emlrtRSInfo peb_emlrtRSI = {
    46,        /* lineNo */
    "xzungqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzungqr.m" /* pathName */
};

emlrtRSInfo qeb_emlrtRSI = {
    41,        /* lineNo */
    "xzungqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzungqr.m" /* pathName */
};

emlrtRSInfo reb_emlrtRSI = {
    34,        /* lineNo */
    "xzungqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzungqr.m" /* pathName */
};

emlrtRSInfo seb_emlrtRSI = {
    16,        /* lineNo */
    "xzungqr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzungqr.m" /* pathName */
};

emlrtRSInfo vhb_emlrtRSI =
    {
        13,               /* lineNo */
        "nullAssignment", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pathName */
};

emlrtRSInfo whb_emlrtRSI =
    {
        17,               /* lineNo */
        "nullAssignment", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "nullAssignment.m" /* pathName */
};

emlrtRSInfo gib_emlrtRSI =
    {
        225,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo lib_emlrtRSI = {
    16,                                                         /* lineNo */
    "all",                                                      /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/all.m" /* pathName */
};

emlrtRSInfo akb_emlrtRSI = {
    14,                         /* lineNo */
    "validateInputSizeAndType", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/validateInputSizeAndType.m" /* pathName
                                                                    */
};

emlrtRSInfo llb_emlrtRSI = {
    920,                       /* lineNo */
    "ObjectTrack/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo mlb_emlrtRSI = {
    926,                       /* lineNo */
    "ObjectTrack/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo nlb_emlrtRSI = {
    929,                       /* lineNo */
    "ObjectTrack/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo olb_emlrtRSI = {
    932,                       /* lineNo */
    "ObjectTrack/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo plb_emlrtRSI = {
    936,                       /* lineNo */
    "ObjectTrack/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo qlb_emlrtRSI = {
    949,                       /* lineNo */
    "ObjectTrack/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo rlb_emlrtRSI = {
    954,                       /* lineNo */
    "ObjectTrack/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo tlb_emlrtRSI = {
    341,                               /* lineNo */
    "ObjectTrack/setObjectAttributes", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo ulb_emlrtRSI = {
    362,                               /* lineNo */
    "ObjectTrack/setObjectAttributes", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo xlb_emlrtRSI = {
    972,                                                  /* lineNo */
    "ObjectTrack/updateClassificationFromDetectionsJPDA", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo bmb_emlrtRSI = {
    1831,                              /* lineNo */
    "ObjectTrack/prepareTrackForJPDA", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo dmb_emlrtRSI =
    {
        233,                       /* lineNo */
        "trackingEKF/correctjpda", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

emlrtRSInfo emb_emlrtRSI =
    {
        240,                       /* lineNo */
        "trackingEKF/correctjpda", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

emlrtRSInfo fmb_emlrtRSI =
    {
        242,                       /* lineNo */
        "trackingEKF/correctjpda", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

emlrtRSInfo gmb_emlrtRSI =
    {
        236,                       /* lineNo */
        "trackingEKF/correctjpda", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

emlrtRSInfo hmb_emlrtRSI =
    {
        257,                       /* lineNo */
        "trackingEKF/correctjpda", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

emlrtRSInfo imb_emlrtRSI =
    {
        260,                       /* lineNo */
        "trackingEKF/correctjpda", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

emlrtRSInfo jmb_emlrtRSI =
    {
        835,                                     /* lineNo */
        "trackingEKF/validateCorrectJPDAInputs", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

emlrtRSInfo kmb_emlrtRSI =
    {
        841,                                     /* lineNo */
        "trackingEKF/validateCorrectJPDAInputs", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

emlrtRSInfo lmb_emlrtRSI =
    {
        850,                                     /* lineNo */
        "trackingEKF/validateCorrectJPDAInputs", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

emlrtRSInfo omb_emlrtRSI = {
    78,                                                           /* lineNo */
    "EKFCorrectorAdditive/getPredictedMeasurementAndCovariances", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m" /* pathName */
};

emlrtRSInfo pmb_emlrtRSI = {
    70,                                                           /* lineNo */
    "EKFCorrectorAdditive/getPredictedMeasurementAndCovariances", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m" /* pathName */
};

emlrtRSInfo qmb_emlrtRSI = {
    170,                        /* lineNo */
    "EKFCorrector/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m" /* pathName */
};

emlrtRSInfo smb_emlrtRSI = {
    175,                        /* lineNo */
    "EKFCorrector/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m" /* pathName */
};

emlrtRSInfo tmb_emlrtRSI = {
    179,                        /* lineNo */
    "EKFCorrector/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m" /* pathName */
};

emlrtRSInfo umb_emlrtRSI = {
    26,                                   /* lineNo */
    "jpdaWeightInnovationAndCovariances", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/jpdaWeightInnovationAndCovariance"
    "s.m" /* pathName */
};

emlrtRSInfo knb_emlrtRSI = {
    1853,                               /* lineNo */
    "ObjectTrack/updateTrackLogicJPDA", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo lnb_emlrtRSI = {
    1859,                               /* lineNo */
    "ObjectTrack/updateTrackLogicJPDA", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

emlrtRSInfo spb_emlrtRSI = {
    66,      /* lineNo */
    "ixfun", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pathName
                                                                         */
};

emlrtRSInfo tpb_emlrtRSI = {
    45,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

emlrtRSInfo upb_emlrtRSI =
    {
        19,             /* lineNo */
        "scalexpAlloc", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "scalexpAlloc.m" /* pathName */
};

emlrtRTEInfo emlrtRTEI = {
    288,                   /* lineNo */
    27,                    /* colNo */
    "check_non_axis_size", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/cat.m" /* pName
                                                                       */
};

emlrtRTEInfo h_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatefinite.m" /* pName */
};

emlrtRTEInfo k_emlrtRTEI = {
    74,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo l_emlrtRTEI = {
    81,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo q_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatenonnan", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnan.m" /* pName */
};

emlrtRTEInfo r_emlrtRTEI =
    {
        133,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pName */
};

emlrtRTEInfo s_emlrtRTEI =
    {
        138,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pName */
};

emlrtRTEInfo t_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatescalar", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatescalar.m" /* pName */
};

emlrtRTEInfo x_emlrtRTEI = {
    13,                /* lineNo */
    37,                /* colNo */
    "validateinteger", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validateinteger.m" /* pName */
};

emlrtRTEInfo y_emlrtRTEI = {
    510,                                /* lineNo */
    17,                                 /* colNo */
    "pointCloudBase/arrayNotSupported", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

emlrtBCInfo m_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    1,           /* lineNo */
    1,           /* colNo */
    "",          /* aName */
    "getSubset", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+pc/getSubset.p", /* pName */
    0                            /* checkKind */
};

emlrtRTEInfo eb_emlrtRTEI =
    {
        134,             /* lineNo */
        27,              /* colNo */
        "unaryMinOrMax", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pName */
};

emlrtRTEInfo fb_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatepositive.m" /* pName */
};

emlrtRTEInfo hb_emlrtRTEI = {
    13,                                                            /* lineNo */
    9,                                                             /* colNo */
    "sqrt",                                                        /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elfun/sqrt.m" /* pName */
};

emlrtRTEInfo ib_emlrtRTEI = {
    14,                    /* lineNo */
    37,                    /* colNo */
    "validatenonnegative", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnegative.m" /* pName */
};

emlrtRTEInfo jb_emlrtRTEI = {
    241,                                                           /* lineNo */
    1,                                                             /* colNo */
    "unique_vector",                                               /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pName */
};

emlrtRTEInfo kb_emlrtRTEI = {
    47,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" /* pName */
};

emlrtRTEInfo lb_emlrtRTEI = {
    44,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" /* pName */
};

emlrtRTEInfo mb_emlrtRTEI = {
    24,                                /* lineNo */
    5,                                 /* colNo */
    "isSymmetricPositiveSemiDefinite", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/isSymmetricPositiveSemiDefinite.m" /* pName
                                                                           */
};

emlrtRTEInfo nb_emlrtRTEI = {
    1,                 /* lineNo */
    1,                 /* colNo */
    "SystemCore/step", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pName */
};

emlrtRTEInfo qb_emlrtRTEI = {
    1,                  /* lineNo */
    1,                  /* colNo */
    "SystemCore/setup", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pName */
};

emlrtRTEInfo ec_emlrtRTEI = {
    14,                                                           /* lineNo */
    9,                                                            /* colNo */
    "log",                                                        /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elfun/log.m" /* pName */
};

emlrtDCInfo g_emlrtDCI = {
    31,       /* lineNo */
    14,       /* colNo */
    "repmat", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/repmat.m", /* pName
                                                                       */
    4 /* checkKind */
};

emlrtECInfo u_emlrtECI = {
    -1,                                 /* nDims */
    1619,                               /* lineNo */
    20,                                 /* colNo */
    "ObjectTrack/sortDetectionsByTime", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pName */
};

emlrtBCInfo cf_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    1615,                               /* lineNo */
    78,                                 /* colNo */
    "",                                 /* aName */
    "ObjectTrack/sortDetectionsByTime", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m", /* pName */
    0                                            /* checkKind */
};

emlrtBCInfo df_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    1617,                               /* lineNo */
    46,                                 /* colNo */
    "",                                 /* aName */
    "ObjectTrack/sortDetectionsByTime", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m", /* pName */
    0                                            /* checkKind */
};

emlrtBCInfo ef_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    1617,                               /* lineNo */
    63,                                 /* colNo */
    "",                                 /* aName */
    "ObjectTrack/sortDetectionsByTime", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m", /* pName */
    0                                            /* checkKind */
};

emlrtBCInfo ff_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    1617,                               /* lineNo */
    30,                                 /* colNo */
    "",                                 /* aName */
    "ObjectTrack/sortDetectionsByTime", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m", /* pName */
    0                                            /* checkKind */
};

emlrtRTEInfo ad_emlrtRTEI = {
    207,                     /* lineNo */
    56,                      /* colNo */
    "trackHistoryLogic/hit", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "trackHistoryLogic.m" /* pName */
};

emlrtECInfo cb_emlrtECI = {
    -1,             /* nDims */
    41,             /* lineNo */
    1,              /* colNo */
    "wrapResidual", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pName */
};

emlrtECInfo eb_emlrtECI = {
    -1,             /* nDims */
    50,             /* lineNo */
    1,              /* colNo */
    "wrapResidual", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pName */
};

emlrtRTEInfo id_emlrtRTEI =
    {
        14,             /* lineNo */
        15,             /* colNo */
        "scalexpCheck", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
        "scalexpCheck.m" /* pName */
};

emlrtRTEInfo ud_emlrtRTEI = {
    59,       /* lineNo */
    28,       /* colNo */
    "repmat", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/repmat.m" /* pName */
};

emlrtRTEInfo qe_emlrtRTEI = {
    31,                                                            /* lineNo */
    6,                                                             /* colNo */
    "find",                                                        /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

emlrtRTEInfo vf_emlrtRTEI = {
    1,           /* lineNo */
    1,           /* colNo */
    "getSubset", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+pc/getSubset.p" /* pName */
};

emlrtRTEInfo fh_emlrtRTEI = {
    164,                                                           /* lineNo */
    1,                                                             /* colNo */
    "unique",                                                      /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pName */
};

emlrtRTEInfo
    gh_emlrtRTEI =
        {
            52,          /* lineNo */
            9,           /* colNo */
            "mergesort", /* fName */
            "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pName */
};

emlrtRTEInfo hh_emlrtRTEI = {
    165,                                                           /* lineNo */
    20,                                                            /* colNo */
    "unique",                                                      /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pName */
};

emlrtRTEInfo ih_emlrtRTEI = {
    242,                                                           /* lineNo */
    1,                                                             /* colNo */
    "unique",                                                      /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/unique.m" /* pName */
};

emlrtRTEInfo
    jh_emlrtRTEI =
        {
            52,          /* lineNo */
            1,           /* colNo */
            "mergesort", /* fName */
            "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pName */
};

emlrtRTEInfo rh_emlrtRTEI = {
    146,                /* lineNo */
    24,                 /* colNo */
    "blockedSummation", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pName */
};

emlrtRTEInfo nk_emlrtRTEI = {
    38,     /* lineNo */
    5,      /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/sort.m" /* pName */
};

emlrtRTEInfo tk_emlrtRTEI = {
    1615,          /* lineNo */
    17,            /* colNo */
    "ObjectTrack", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pName */
};

emlrtRTEInfo jl_emlrtRTEI = {
    2309,          /* lineNo */
    36,            /* colNo */
    "JPDATracker", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "JPDATracker.m" /* pName */
};

emlrtRTEInfo dm_emlrtRTEI = {
    56,        /* lineNo */
    5,         /* colNo */
    "sortIdx", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName
                                                                           */
};

emlrtRTEInfo fn_emlrtRTEI = {
    49,             /* lineNo */
    1,              /* colNo */
    "wrapResidual", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/wrapResidual.m" /* pName */
};

emlrtRTEInfo fo_emlrtRTEI = {
    386,       /* lineNo */
    1,         /* colNo */
    "sortIdx", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName
                                                                           */
};

emlrtRTEInfo go_emlrtRTEI = {
    388,       /* lineNo */
    1,         /* colNo */
    "sortIdx", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName
                                                                           */
};

emlrtRTEInfo ho_emlrtRTEI = {
    308,       /* lineNo */
    14,        /* colNo */
    "sortIdx", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName
                                                                           */
};

emlrtRTEInfo io_emlrtRTEI = {
    308,       /* lineNo */
    20,        /* colNo */
    "sortIdx", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName
                                                                           */
};

const int32_T iv[4] = {0, 1, 2, 3};

const char_T cv[13] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                       '_', 'd', 's', 'y', 'e', 'v'};

const int8_T iv1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};

const int8_T iv2[36] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                        0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1};

/* End of code generation (mexLidarTracker_data.c) */
