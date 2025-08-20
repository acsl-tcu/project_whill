/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath_vec_data.c
 *
 * Code generation for function 'EvaluationPath_vec_data'
 *
 */

/* Include files */
#include "EvaluationPath_vec_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

boolean_T isMexOutdated;

const char_T *c_EvaluationPath_vec_complete_n;

const char_T *c_FPM_capsule_v3_3vec_complete_;

const char_T *get_distance_complete_name;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131659U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "EvaluationPath_vec",                                 /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo cb_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

emlrtRSInfo db_emlrtRSI = {
    113,               /* lineNo */
    "computeDimsData", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

emlrtRSInfo fb_emlrtRSI = {
    38,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

emlrtRSInfo gb_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo kb_emlrtRSI = {
    56,        /* lineNo */
    "permute", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

emlrtRSInfo lb_emlrtRSI = {
    60,        /* lineNo */
    "permute", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

emlrtRSInfo mb_emlrtRSI = {
    66,        /* lineNo */
    "permute", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

emlrtRSInfo nb_emlrtRSI = {
    84,       /* lineNo */
    "looper", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

emlrtRSInfo ob_emlrtRSI = {
    85,       /* lineNo */
    "looper", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pathName
                                                                       */
};

emlrtRSInfo bc_emlrtRSI =
    {
        99,        /* lineNo */
        "sumprod", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
        "sumprod.m" /* pathName */
};

emlrtRSInfo fc_emlrtRSI = {
    40,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

emlrtRSInfo be_emlrtRSI = {
    57,      /* lineNo */
    "ixfun", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pathName
                                                                         */
};

emlrtRSInfo ce_emlrtRSI = {
    102,                          /* lineNo */
    "binaryImplicitExpansionFun", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pathName
                                                                         */
};

emlrtRSInfo qe_emlrtRSI =
    {
        34,               /* lineNo */
        "rdivide_helper", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "rdivide_helper.m" /* pathName */
};

emlrtRSInfo re_emlrtRSI = {
    53,    /* lineNo */
    "div", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/div.m" /* pathName
                                                                       */
};

emlrtRSInfo se_emlrtRSI = {
    56,        /* lineNo */
    "vecnorm", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/matfun/vecnorm.m" /* pathName
                                                                        */
};

emlrtRSInfo te_emlrtRSI = {
    72,                    /* lineNo */
    "applyVectorFunction", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyVectorFunction.m" /* pathName */
};

emlrtRSInfo ue_emlrtRSI = {
    144,        /* lineNo */
    "looper1D", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyVectorFunction.m" /* pathName */
};

emlrtRTEInfo emlrtRTEI = {
    80,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo b_emlrtRTEI = {
    85,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo c_emlrtRTEI = {
    87,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo o_emlrtRTEI = {
    13,                     /* lineNo */
    27,                     /* colNo */
    "assertCompatibleDims", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/coder/coder/lib/+coder/+internal/"
    "assertCompatibleDims.m" /* pName */
};

emlrtRTEInfo kd_emlrtRTEI = {
    60,        /* lineNo */
    20,        /* colNo */
    "permute", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pName
                                                                       */
};

emlrtRTEInfo we_emlrtRTEI = {
    91,                    /* lineNo */
    9,                     /* colNo */
    "FPM_capsule_v3_3vec", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/FPM_capsule_v3_3vec.m" /* pName */
};

emlrtRTEInfo lf_emlrtRTEI = {
    105,                   /* lineNo */
    9,                     /* colNo */
    "FPM_capsule_v3_3vec", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/FPM_capsule_v3_3vec.m" /* pName */
};

emlrtRTEInfo pf_emlrtRTEI = {
    106,                   /* lineNo */
    23,                    /* colNo */
    "FPM_capsule_v3_3vec", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/FPM_capsule_v3_3vec.m" /* pName */
};

emlrtRTEInfo uf_emlrtRTEI = {
    54,    /* lineNo */
    9,     /* colNo */
    "div", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/div.m" /* pName
                                                                       */
};

emlrtRTEInfo xf_emlrtRTEI = {
    111,                   /* lineNo */
    23,                    /* colNo */
    "FPM_capsule_v3_3vec", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/FPM_capsule_v3_3vec.m" /* pName */
};

/* End of code generation (EvaluationPath_vec_data.c) */
