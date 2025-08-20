/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse_data.c
 *
 * Code generation for function 'pcfitellipse_data'
 *
 */

/* Include files */
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                               /* bFirstTime */
    false,                                              /* bInitialized */
    131642U,                                            /* fVersionInfo */
    NULL,                                               /* fErrorFunction */
    "pcfitellipse",                                     /* fFunctionName */
    NULL,                                               /* fRTCallStack */
    false,                                              /* bDebugMode */
    {3997702259U, 743900116U, 937962426U, 2289393452U}, /* fSigWrd */
    NULL                                                /* fSigMem */
};

emlrtRSInfo f_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

emlrtRSInfo g_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

emlrtRSInfo h_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

emlrtRSInfo i_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

emlrtRSInfo o_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

emlrtRSInfo ub_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" /* pathName */
};

emlrtRSInfo fc_emlrtRSI =
    {
        71,      /* lineNo */
        "power", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

emlrtRSInfo mc_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

emlrtRSInfo nc_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" /* pathName */
};

emlrtRSInfo oc_emlrtRSI = {
    1,                          /* lineNo */
    "computeFiniteDifferences", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\optimlib\\+optim\\+coder\\+"
    "utils\\+FiniteDifferences\\computeFiniteDifferenc"
    "es.p" /* pathName */
};

emlrtRSInfo sc_emlrtRSI = {
    64,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv."
    "m" /* pathName */
};

emlrtRSInfo tc_emlrtRSI = {
    71,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo uc_emlrtRSI = {
    74,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo wc_emlrtRSI = {
    38,      /* lineNo */
    "xcopy", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xcopy."
    "m" /* pathName */
};

emlrtRSInfo xc_emlrtRSI = {
    69,      /* lineNo */
    "xcopy", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xcopy.m" /* pathName */
};

emlrtRSInfo gd_emlrtRSI = {
    58,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo hd_emlrtRSI = {
    51,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo id_emlrtRSI = {
    23,       /* lineNo */
    "ixamax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\ixamax.m" /* pathName */
};

emlrtRSInfo jd_emlrtRSI = {
    24,       /* lineNo */
    "ixamax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\ixamax.m" /* pathName */
};

emlrtRSInfo od_emlrtRSI = {
    1,           /* lineNo */
    "factorQRE", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\factorQRE.p" /* pathName */
};

emlrtRSInfo ae_emlrtRSI = {
    31,      /* lineNo */
    "xscal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal."
    "m" /* pathName */
};

emlrtRSInfo be_emlrtRSI = {
    18,      /* lineNo */
    "xscal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xscal.m" /* pathName */
};

emlrtRSInfo ce_emlrtRSI = {
    37,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo de_emlrtRSI =
    {
        45,     /* lineNo */
        "xger", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xger.m" /* pathName */
};

emlrtRSInfo ee_emlrtRSI = {
    15,     /* lineNo */
    "xger", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xger.m" /* pathName */
};

emlrtRSInfo fe_emlrtRSI = {
    41,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

emlrtRSInfo ie_emlrtRSI = {
    1,                /* lineNo */
    "computeSquareQ", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\computeSquareQ.p" /* pathName */
};

emlrtRSInfo le_emlrtRSI = {
    55,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsv."
    "m" /* pathName */
};

emlrtRSInfo xe_emlrtRSI =
    {
        35,     /* lineNo */
        "xdot", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xdot.m" /* pathName */
};

emlrtRSInfo ye_emlrtRSI = {
    15,     /* lineNo */
    "xdot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdot.m" /* pathName */
};

emlrtRSInfo ef_emlrtRSI = {
    1,              /* lineNo */
    "removeConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p" /* pathName */
};

emlrtRSInfo if_emlrtRSI = {
    1,          /* lineNo */
    "factorQR", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\factorQR.p" /* pathName */
};

emlrtRSInfo vf_emlrtRSI = {
    41,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

emlrtRSInfo ig_emlrtRSI = {
    23,      /* lineNo */
    "xrotg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg."
    "m" /* pathName */
};

emlrtRSInfo kg_emlrtRSI = {
    24,     /* lineNo */
    "xrot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xrot.m" /* pathName */
};

emlrtRSInfo ng_emlrtRSI = {
    1,        /* lineNo */
    "factor", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "CholManager\\factor.p" /* pathName */
};

emlrtRSInfo qg_emlrtRSI = {
    1,        /* lineNo */
    "factor", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\factor.p" /* pathName */
};

emlrtRSInfo sg_emlrtRSI = {
    54,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

emlrtRSInfo tg_emlrtRSI = {
    1,       /* lineNo */
    "solve", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "CholManager\\solve.p" /* pathName */
};

emlrtRSInfo ug_emlrtRSI = {
    65,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

emlrtRSInfo vg_emlrtRSI = {
    72,      /* lineNo */
    "xtrsv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsv.m" /* pathName */
};

emlrtRSInfo oh_emlrtRSI = {
    1,             /* lineNo */
    "addLBConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addLBConstr.p" /* pathName */
};

emlrtRSInfo qh_emlrtRSI = {
    1,             /* lineNo */
    "addUBConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addUBConstr.p" /* pathName */
};

emlrtRSInfo oi_emlrtRSI = {
    31,                                                            /* lineNo */
    "@(model)validateModelFcn(model,Pbar,c,R,Yhbar,MD_threshold)", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                    */
};

emlrtRSInfo pi_emlrtRSI = {
    77,                              /* lineNo */
    "pcfitellipse/validateModelFcn", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                    */
};

emlrtRSInfo qi_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

emlrtRTEInfo emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

emlrtRTEInfo u_emlrtRTEI = {
    44,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

emlrtRTEInfo v_emlrtRTEI = {
    47,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

emlrtBCInfo mb_emlrtBCI = {
    1,          /* iFirst */
    15,         /* iLast */
    1,          /* lineNo */
    1,          /* colNo */
    "",         /* aName */
    "isActive", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\isActive.p", /* pName */
    0                         /* checkKind */
};

emlrtBCInfo nb_emlrtBCI = {
    1,              /* iFirst */
    6,              /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p", /* pName */
    0                             /* checkKind */
};

emlrtBCInfo qb_emlrtBCI = {
    1,              /* iFirst */
    15,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p", /* pName */
    0                             /* checkKind */
};

emlrtBCInfo rb_emlrtBCI = {
    1,              /* iFirst */
    15,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p", /* pName */
    3                             /* checkKind */
};

emlrtBCInfo tb_emlrtBCI = {
    1,              /* iFirst */
    5,              /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeConstr.p", /* pName */
    3                             /* checkKind */
};

emlrtRTEInfo w_emlrtRTEI = {
    18,                               /* lineNo */
    27,                               /* colNo */
    "eml_int_forloop_overflow_check", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pName */
};

emlrtBCInfo kd_emlrtBCI = {
    1,        /* iFirst */
    225,      /* iLast */
    1,        /* lineNo */
    1,        /* colNo */
    "",       /* aName */
    "factor", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "DynamicRegCholManager\\factor.p", /* pName */
    0                                  /* checkKind */
};

emlrtBCInfo vd_emlrtBCI = {
    1,                         /* iFirst */
    15,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "addConstrUpdateRecords_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addConstrUpdateRecords_.p", /* pName */
    3                                        /* checkKind */
};

const int32_T iv[4] = {0, 1, 2, 3};

/* End of code generation (pcfitellipse_data.c) */
