/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath_data.c
 *
 * Code generation for function 'EvaluationPath_data'
 *
 */

/* Include files */
#include "EvaluationPath_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

boolean_T isMexOutdated;

const char_T *EvaluationPath_complete_name;

const char_T *FPM_capsule_v3_1_complete_name;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131659U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "EvaluationPath",                                     /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo p_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

emlrtRSInfo q_emlrtRSI = {
    113,               /* lineNo */
    "computeDimsData", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

emlrtRSInfo s_emlrtRSI = {
    38,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

emlrtRSInfo t_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRTEInfo emlrtRTEI = {
    87,                  /* lineNo */
    23,                  /* colNo */
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
    80,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo bc_emlrtRTEI = {
    60,        /* lineNo */
    20,        /* colNo */
    "permute", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pName
                                                                       */
};

emlrtRTEInfo rd_emlrtRTEI = {
    99,                 /* lineNo */
    21,                 /* colNo */
    "FPM_capsule_v3_1", /* fName */
    "/home/takumi/Document/"
    "capsuele_v5.1_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Controller/FPM_capsule_v3_1"
    ".m" /* pName */
};

/* End of code generation (EvaluationPath_data.c) */
