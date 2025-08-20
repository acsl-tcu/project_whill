/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath_vec.c
 *
 * Code generation for function 'EvaluationPath_vec'
 *
 */

/* Include files */
#include "EvaluationPath_vec.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "FPM_capsule_v3_3vec.h"
#include "any.h"
#include "assertValidSizeArg.h"
#include "combineVectorElements.h"
#include "cos.h"
#include "get_distance.h"
#include "indexShapeCheck.h"
#include "pagetranspose.h"
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "sum.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7,     /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 8,   /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 10,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 11,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 13,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 14,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 16,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 17,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 20,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 26,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 30,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 33,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 37,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 39,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 43,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 44,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 45,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 47,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 48,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 54,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 57,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 59,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 63,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 64,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 65,  /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 66, /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 67, /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 15, /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  31,                                  /* colNo */
  "obj.waypoint",                      /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 64,    /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  31,                                  /* colNo */
  "obj.waypoint",                      /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 63,  /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  30,                                  /* colNo */
  "obj.V_ref",                         /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 57,  /* lineNo */
  30,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  10,                                  /* iLast */
  28,                                  /* lineNo */
  36,                                  /* colNo */
  "NoEntryZone2",                      /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 28,  /* lineNo */
  36,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 20,  /* lineNo */
  23,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  23,                                  /* colNo */
  "obj.selectZone",                    /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  71,                                  /* lineNo */
  10,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { 3,   /* nDims */
  59,                                  /* lineNo */
  25,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 3,   /* nDims */
  59,                                  /* lineNo */
  66,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  59,                                  /* lineNo */
  66,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  57,                                  /* lineNo */
  45,                                  /* colNo */
  "obj.target_n",                      /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 57,  /* lineNo */
  45,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { 3,   /* nDims */
  54,                                  /* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { 3,   /* nDims */
  54,                                  /* lineNo */
  69,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  134,                                 /* colNo */
  "target2",                           /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 47,  /* lineNo */
  134,                                 /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  132,                                 /* colNo */
  "target2",                           /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  47,                                  /* lineNo */
  111,                                 /* colNo */
  "preobs2",                           /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 47,  /* lineNo */
  88,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 47,  /* lineNo */
  69,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 47,  /* lineNo */
  50,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  48,                                  /* colNo */
  "px2",                               /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo g_emlrtECI = { 4,   /* nDims */
  37,                                  /* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { 3,   /* nDims */
  37,                                  /* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { 2,   /* nDims */
  37,                                  /* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { 4,   /* nDims */
  38,                                  /* lineNo */
  97,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { 3,   /* nDims */
  38,                                  /* lineNo */
  97,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { 4,   /* nDims */
  38,                                  /* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo m_emlrtECI = { 3,   /* nDims */
  38,                                  /* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo n_emlrtECI = { 4,   /* nDims */
  37,                                  /* lineNo */
  97,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo o_emlrtECI = { 3,   /* nDims */
  37,                                  /* lineNo */
  97,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo p_emlrtECI = { 4,   /* nDims */
  33,                                  /* lineNo */
  33,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo q_emlrtECI = { 3,   /* nDims */
  33,                                  /* lineNo */
  33,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo r_emlrtECI = { 2,   /* nDims */
  33,                                  /* lineNo */
  33,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo s_emlrtECI = { 4,   /* nDims */
  34,                                  /* lineNo */
  88,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo t_emlrtECI = { 3,   /* nDims */
  34,                                  /* lineNo */
  88,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo u_emlrtECI = { 4,   /* nDims */
  34,                                  /* lineNo */
  33,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo v_emlrtECI = { 3,   /* nDims */
  34,                                  /* lineNo */
  33,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo w_emlrtECI = { 4,   /* nDims */
  33,                                  /* lineNo */
  88,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo x_emlrtECI = { 3,   /* nDims */
  33,                                  /* lineNo */
  88,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo y_emlrtECI = { -1,  /* nDims */
  17,                                  /* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo ab_emlrtECI = { -1, /* nDims */
  16,                                  /* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo bb_emlrtECI = { -1, /* nDims */
  14,                                  /* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo cb_emlrtECI = { -1, /* nDims */
  13,                                  /* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo db_emlrtECI = { -1, /* nDims */
  11,                                  /* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo eb_emlrtECI = { -1, /* nDims */
  10,                                  /* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo fb_emlrtECI = { -1, /* nDims */
  8,                                   /* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo gb_emlrtECI = { -1, /* nDims */
  7,                                   /* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  20,                                  /* lineNo */
  38,                                  /* colNo */
  "obj.target_n",                      /* aName */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 20,  /* lineNo */
  38,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo hb_emlrtECI = { 2,  /* nDims */
  17,                                  /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo ib_emlrtECI = { 2,  /* nDims */
  16,                                  /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo jb_emlrtECI = { 2,  /* nDims */
  14,                                  /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo kb_emlrtECI = { 2,  /* nDims */
  13,                                  /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo lb_emlrtECI = { 2,  /* nDims */
  11,                                  /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo mb_emlrtECI = { 2,  /* nDims */
  10,                                  /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo nb_emlrtECI = { 2,  /* nDims */
  8,                                   /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtECInfo ob_emlrtECI = { 2,  /* nDims */
  7,                                   /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtDCInfo l_emlrtDCI = { 5,   /* lineNo */
  38,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 5,   /* lineNo */
  38,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 5,   /* lineNo */
  32,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 5,   /* lineNo */
  32,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo r_emlrtRTEI = { 5, /* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 7, /* lineNo */
  118,                                 /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 7, /* lineNo */
  86,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 7, /* lineNo */
  39,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 7, /* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 8, /* lineNo */
  118,                                 /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 8, /* lineNo */
  86,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 8, /* lineNo */
  39,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 8,/* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 10,/* lineNo */
  118,                                 /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 10,/* lineNo */
  86,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 10,/* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 11,/* lineNo */
  118,                                 /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 11,/* lineNo */
  86,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 11,/* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 13,/* lineNo */
  118,                                 /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 13,/* lineNo */
  86,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 13,/* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 14,/* lineNo */
  118,                                 /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 14,/* lineNo */
  86,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 14,/* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 16,/* lineNo */
  118,                                 /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 16,/* lineNo */
  86,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 16,/* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 17,/* lineNo */
  118,                                 /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 17,/* lineNo */
  86,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 17,/* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 28,/* lineNo */
  20,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 33,/* lineNo */
  33,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 33,/* lineNo */
  88,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 34,/* lineNo */
  33,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 34,/* lineNo */
  88,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 37,/* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 37,/* lineNo */
  97,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 38,/* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 38,/* lineNo */
  97,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 47,/* lineNo */
  40,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 47,/* lineNo */
  59,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 47,/* lineNo */
  78,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 48,/* lineNo */
  23,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 76,/* lineNo */
  9,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 31,/* lineNo */
  30,                                  /* colNo */
  "unsafeSxfun",                       /* fName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unsafeSxfun.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 57,/* lineNo */
  20,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 59,/* lineNo */
  61,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = { 59,/* lineNo */
  25,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 63,/* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 63,/* lineNo */
  18,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 64,/* lineNo */
  31,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 64,/* lineNo */
  18,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 65,/* lineNo */
  27,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 67,/* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 71,/* lineNo */
  10,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = { 47,/* lineNo */
  7,                                   /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 33,/* lineNo */
  21,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 63,/* lineNo */
  10,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 64,/* lineNo */
  10,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = { 15,/* lineNo */
  9,                                   /* colNo */
  "sum",                               /* fName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m"/* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = { 54,/* lineNo */
  22,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo id_emlrtRTEI = { 54,/* lineNo */
  70,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRTEInfo li_emlrtRTEI = { 59,/* lineNo */
  66,                                  /* colNo */
  "EvaluationPath_vec",                /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pName */
};

static emlrtRSInfo gg_emlrtRSI = { 71, /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo xg_emlrtRSI = { 34, /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

static emlrtRSInfo yg_emlrtRSI = { 38, /* lineNo */
  "EvaluationPath_vec",                /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/EvaluationPath_vec.m"/* pathName */
};

/* Function Declarations */
static void b_and(const emlrtStack *sp, emxArray_boolean_T *in1, const
                  emxArray_boolean_T *in2);
static void b_plus(real_T in1_data[], int32_T in1_size[3], const real_T
                   in2_data[], const int32_T in2_size[3]);
static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1, const
  emxArray_real_T *in2);
static void binary_expand_op_1(const emlrtStack *sp, emxArray_real_T *in1, const
  real_T in2_data[], const int32_T in2_size[3]);
static void binary_expand_op_10(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emlrtRSInfo in2, const emxArray_boolean_T *in3, const emxArray_boolean_T
  *in4);
static void binary_expand_op_11(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4);
static void binary_expand_op_12(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4);
static void binary_expand_op_13(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4);
static void binary_expand_op_14(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4);
static void binary_expand_op_2(const emlrtStack *sp, emxArray_real_T *in1, const
  emxArray_real_T *in2, const emxArray_real_T *in3, const real_T in4[2]);
static void binary_expand_op_3(const emlrtStack *sp, emxArray_real_T *in1, const
  emxArray_real_T *in2);
static void binary_expand_op_4(const emlrtStack *sp, emxArray_real_T *in1, const
  emlrtRSInfo in2, const emxArray_real_T *in4, const struct0_T *in5, int32_T in6);
static void binary_expand_op_5(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emlrtRSInfo in2, const emxArray_boolean_T *in3, const emxArray_boolean_T
  *in4);
static void binary_expand_op_6(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4, const
  struct0_T *in5);
static void binary_expand_op_7(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4, const
  struct0_T *in5);
static void binary_expand_op_8(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4, const
  struct0_T *in5);
static void binary_expand_op_9(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4, const
  struct0_T *in5);
static void plus(const emlrtStack *sp, emxArray_real_T *in1, const
                 emxArray_real_T *in2);

/* Function Definitions */
static void b_and(const emlrtStack *sp, emxArray_boolean_T *in1, const
                  emxArray_boolean_T *in2)
{
  emxArray_boolean_T *b_in1;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_1;
  int32_T stride_1_2;
  int32_T stride_1_3;
  const boolean_T *in2_data;
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in1, 4, &bc_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = 4;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }

  b_in1->size[1] = loop_ub;
  if (in2->size[2] == 1) {
    b_loop_ub = in1->size[2];
  } else {
    b_loop_ub = in2->size[2];
  }

  b_in1->size[2] = b_loop_ub;
  if (in2->size[3] == 1) {
    c_loop_ub = in1->size[3];
  } else {
    c_loop_ub = in2->size[3];
  }

  b_in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, b_in1, i, &bc_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_1 = (in2->size[1] != 1);
  stride_1_2 = (in2->size[2] != 1);
  stride_1_3 = (in2->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      int32_T aux_0_1;
      int32_T aux_1_1;
      aux_0_1 = 0;
      aux_1_1 = 0;
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(4 * i2 + 4 * b_in1->size[1] * i1) + 4 * b_in1->size[1] *
          b_in1->size[2] * i] = (in1_data[(4 * aux_0_1 + 4 * in1->size[1] *
          aux_0_2) + 4 * in1->size[1] * in1->size[2] * aux_0_3] && in2_data[(4 *
          aux_1_1 + 4 * in2->size[1] * aux_1_2) + 4 * in2->size[1] * in2->size[2]
          * aux_1_3]);
        b_in1_data[((4 * i2 + 4 * b_in1->size[1] * i1) + 4 * b_in1->size[1] *
                    b_in1->size[2] * i) + 1] = (in1_data[((4 * aux_0_1 + 4 *
          in1->size[1] * aux_0_2) + 4 * in1->size[1] * in1->size[2] * aux_0_3) +
          1] && in2_data[((4 * aux_1_1 + 4 * in2->size[1] * aux_1_2) + 4 *
                          in2->size[1] * in2->size[2] * aux_1_3) + 1]);
        b_in1_data[((4 * i2 + 4 * b_in1->size[1] * i1) + 4 * b_in1->size[1] *
                    b_in1->size[2] * i) + 2] = (in1_data[((4 * aux_0_1 + 4 *
          in1->size[1] * aux_0_2) + 4 * in1->size[1] * in1->size[2] * aux_0_3) +
          2] && in2_data[((4 * aux_1_1 + 4 * in2->size[1] * aux_1_2) + 4 *
                          in2->size[1] * in2->size[2] * aux_1_3) + 2]);
        b_in1_data[((4 * i2 + 4 * b_in1->size[1] * i1) + 4 * b_in1->size[1] *
                    b_in1->size[2] * i) + 3] = (in1_data[((4 * aux_0_1 + 4 *
          in1->size[1] * aux_0_2) + 4 * in1->size[1] * in1->size[2] * aux_0_3) +
          3] && in2_data[((4 * aux_1_1 + 4 * in2->size[1] * aux_1_2) + 4 *
                          in2->size[1] * in2->size[2] * aux_1_3) + 3]);
        aux_1_1 += stride_1_1;
        aux_0_1 += stride_0_1;
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  in1->size[1] = loop_ub;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &bc_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] * in1->
          size[2] * i] = b_in1_data[(4 * i2 + 4 * b_in1->size[1] * i1) + 4 *
          b_in1->size[1] * b_in1->size[2] * i];
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 1] = b_in1_data[((4 * i2 + 4 * b_in1->
          size[1] * i1) + 4 * b_in1->size[1] * b_in1->size[2] * i) + 1];
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 2] = b_in1_data[((4 * i2 + 4 * b_in1->
          size[1] * i1) + 4 * b_in1->size[1] * b_in1->size[2] * i) + 2];
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 3] = b_in1_data[((4 * i2 + 4 * b_in1->
          size[1] * i1) + 4 * b_in1->size[1] * b_in1->size[2] * i) + 3];
      }
    }
  }

  emxFree_boolean_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void b_plus(real_T in1_data[], int32_T in1_size[3], const real_T
                   in2_data[], const int32_T in2_size[3])
{
  real_T b_in1_data[2000];
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_1_2;
  if (in2_size[2] == 1) {
    loop_ub = in1_size[2];
  } else {
    loop_ub = in2_size[2];
  }

  stride_0_2 = (in1_size[2] != 1);
  stride_1_2 = (in2_size[2] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_2] + in2_data[i * stride_1_2];
  }

  in1_size[0] = 1;
  in1_size[1] = 1;
  in1_size[2] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in1_data[0], (uint32_T)loop_ub * sizeof(real_T));
  }
}

static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1, const
  emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T unnamed_idx_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  unnamed_idx_3 = in2->size[3];
  emxInit_real_T(sp, &b_in1, 2, &wc_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (unnamed_idx_3 == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = unnamed_idx_3;
  }

  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &wc_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  unnamed_idx_3 = (unnamed_idx_3 != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] + in2_data[i * unnamed_idx_3];
  }

  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &wc_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_1(const emlrtStack *sp, emxArray_real_T *in1, const
  real_T in2_data[], const int32_T in2_size[3])
{
  emxArray_real_T *b_in1;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T unnamed_idx_1;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  unnamed_idx_1 = in2_size[2];
  emxInit_real_T(sp, &b_in1, 2, &wc_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (unnamed_idx_1 == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = unnamed_idx_1;
  }

  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &wc_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  unnamed_idx_1 = (unnamed_idx_1 != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] + in2_data[i * unnamed_idx_1];
  }

  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &wc_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_10(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emlrtRSInfo in2, const emxArray_boolean_T *in3, const emxArray_boolean_T
  *in4)
{
  emlrtStack st;
  emxArray_boolean_T *b_in3;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_1;
  int32_T stride_1_2;
  int32_T stride_1_3;
  const boolean_T *in3_data;
  const boolean_T *in4_data;
  boolean_T *b_in3_data;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in3, 4, &vb_emlrtRTEI);
  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2] * b_in3->size[3];
  b_in3->size[0] = 4;
  if (in4->size[1] == 1) {
    loop_ub = in3->size[1];
  } else {
    loop_ub = in4->size[1];
  }

  b_in3->size[1] = loop_ub;
  if (in4->size[2] == 1) {
    b_loop_ub = in3->size[2];
  } else {
    b_loop_ub = in4->size[2];
  }

  b_in3->size[2] = b_loop_ub;
  if (in4->size[3] == 1) {
    c_loop_ub = in3->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  b_in3->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, b_in3, i, &vb_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_1 = (in3->size[1] != 1);
  stride_0_2 = (in3->size[2] != 1);
  stride_0_3 = (in3->size[3] != 1);
  stride_1_1 = (in4->size[1] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      int32_T aux_0_1;
      int32_T aux_1_1;
      aux_0_1 = 0;
      aux_1_1 = 0;
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in3_data[(4 * i2 + 4 * b_in3->size[1] * i1) + 4 * b_in3->size[1] *
          b_in3->size[2] * i] = (in3_data[(4 * aux_0_1 + 4 * in3->size[1] *
          aux_0_2) + 4 * in3->size[1] * in3->size[2] * aux_0_3] && in4_data[(4 *
          aux_1_1 + 4 * in4->size[1] * aux_1_2) + 4 * in4->size[1] * in4->size[2]
          * aux_1_3]);
        b_in3_data[((4 * i2 + 4 * b_in3->size[1] * i1) + 4 * b_in3->size[1] *
                    b_in3->size[2] * i) + 1] = (in3_data[((4 * aux_0_1 + 4 *
          in3->size[1] * aux_0_2) + 4 * in3->size[1] * in3->size[2] * aux_0_3) +
          1] && in4_data[((4 * aux_1_1 + 4 * in4->size[1] * aux_1_2) + 4 *
                          in4->size[1] * in4->size[2] * aux_1_3) + 1]);
        b_in3_data[((4 * i2 + 4 * b_in3->size[1] * i1) + 4 * b_in3->size[1] *
                    b_in3->size[2] * i) + 2] = (in3_data[((4 * aux_0_1 + 4 *
          in3->size[1] * aux_0_2) + 4 * in3->size[1] * in3->size[2] * aux_0_3) +
          2] && in4_data[((4 * aux_1_1 + 4 * in4->size[1] * aux_1_2) + 4 *
                          in4->size[1] * in4->size[2] * aux_1_3) + 2]);
        b_in3_data[((4 * i2 + 4 * b_in3->size[1] * i1) + 4 * b_in3->size[1] *
                    b_in3->size[2] * i) + 3] = (in3_data[((4 * aux_0_1 + 4 *
          in3->size[1] * aux_0_2) + 4 * in3->size[1] * in3->size[2] * aux_0_3) +
          3] && in4_data[((4 * aux_1_1 + 4 * in4->size[1] * aux_1_2) + 4 *
                          in4->size[1] * in4->size[2] * aux_1_3) + 3]);
        aux_1_1 += stride_1_1;
        aux_0_1 += stride_0_1;
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  st.site = (emlrtRSInfo *)&in2;
  any(&st, b_in3, in1);
  emxFree_boolean_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_11(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  emxEnsureCapacity_boolean_T(sp, in1, i, &yb_emlrtRTEI);
  loop_ub = in4->size[1];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &yb_emlrtRTEI);
  if (in4->size[2] == 1) {
    b_loop_ub = in3;
  } else {
    b_loop_ub = in4->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &yb_emlrtRTEI);
  if (in4->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &yb_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in3 != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] * in1->
          size[2] * i] = (in2_data[(8 * aux_0_2 + 8 * in2->size[2] * aux_0_3) +
                          4] <= in4_data[((4 * i2 + 4 * in4->size[1] * aux_1_2)
          + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 3]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 1] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 5] <= in4_data[((4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 3]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 2] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 6] <= in4_data[((4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 3]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 3] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 7] <= in4_data[((4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 3]);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_12(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  emxEnsureCapacity_boolean_T(sp, in1, i, &xb_emlrtRTEI);
  loop_ub = in4->size[1];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &xb_emlrtRTEI);
  if (in4->size[2] == 1) {
    b_loop_ub = in3;
  } else {
    b_loop_ub = in4->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &xb_emlrtRTEI);
  if (in4->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &xb_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in3 != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] * in1->
          size[2] * i] = (in2_data[(8 * aux_0_2 + 8 * in2->size[2] * aux_0_3) +
                          4] >= in4_data[((4 * i2 + 4 * in4->size[1] * aux_1_2)
          + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 2]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 1] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 5] >= in4_data[((4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 2]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 2] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 6] >= in4_data[((4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 2]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 3] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 7] >= in4_data[((4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 2]);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_13(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  emxEnsureCapacity_boolean_T(sp, in1, i, &wb_emlrtRTEI);
  loop_ub = in4->size[1];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &wb_emlrtRTEI);
  if (in4->size[2] == 1) {
    b_loop_ub = in3;
  } else {
    b_loop_ub = in4->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &wb_emlrtRTEI);
  if (in4->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &wb_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in3 != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] * in1->
          size[2] * i] = (in2_data[8 * aux_0_2 + 8 * in2->size[2] * aux_0_3] <=
                          in4_data[((4 * i2 + 4 * in4->size[1] * aux_1_2) + 4 *
          in4->size[1] * in4->size[2] * aux_1_3) + 1]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 1] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 1] <= in4_data[((4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 1]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 2] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 2] <= in4_data[((4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 1]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 3] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 3] <= in4_data[((4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3) + 1]);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_14(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  emxEnsureCapacity_boolean_T(sp, in1, i, &vb_emlrtRTEI);
  loop_ub = in4->size[1];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &vb_emlrtRTEI);
  if (in4->size[2] == 1) {
    b_loop_ub = in3;
  } else {
    b_loop_ub = in4->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &vb_emlrtRTEI);
  if (in4->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &vb_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in3 != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] * in1->
          size[2] * i] = (in2_data[8 * aux_0_2 + 8 * in2->size[2] * aux_0_3] >=
                          in4_data[(4 * i2 + 4 * in4->size[1] * aux_1_2) + 4 *
                          in4->size[1] * in4->size[2] * aux_1_3]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 1] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 1] >= in4_data[(4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 2] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 2] >= in4_data[(4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3]);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 3] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 3] >= in4_data[(4 * i2 + 4 * in4->size[1] *
          aux_1_2) + 4 * in4->size[1] * in4->size[2] * aux_1_3]);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_2(const emlrtStack *sp, emxArray_real_T *in1, const
  emxArray_real_T *in2, const emxArray_real_T *in3, const real_T in4[2])
{
  const real_T *in2_data;
  const real_T *in3_data;
  real_T *in1_data;
  int32_T b_unnamed_idx_1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T unnamed_idx_1;
  in3_data = in3->data;
  in2_data = in2->data;
  unnamed_idx_1 = in2->size[3];
  b_unnamed_idx_1 = (int32_T)in4[1];
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &wc_emlrtRTEI);
  if (b_unnamed_idx_1 == 1) {
    loop_ub = unnamed_idx_1;
  } else {
    loop_ub = b_unnamed_idx_1;
  }

  i = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &wc_emlrtRTEI);
  in1_data = in1->data;
  stride_0_1 = (unnamed_idx_1 != 1);
  unnamed_idx_1 = (b_unnamed_idx_1 != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_1] + in3_data[i * unnamed_idx_1];
  }
}

static void binary_expand_op_3(const emlrtStack *sp, emxArray_real_T *in1, const
  emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_1_2;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 3, &pc_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2];
  b_in1->size[0] = 1;
  b_in1->size[1] = 1;
  if (in2->size[2] == 1) {
    loop_ub = in1->size[2];
  } else {
    loop_ub = in2->size[2];
  }

  b_in1->size[2] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &pc_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_2 = (in1->size[2] != 1);
  stride_1_2 = (in2->size[2] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_2] + in2_data[i * stride_1_2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2];
  in1->size[0] = 1;
  in1->size[1] = 1;
  in1->size[2] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &pc_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_4(const emlrtStack *sp, emxArray_real_T *in1, const
  emlrtRSInfo in2, const emxArray_real_T *in4, const struct0_T *in5, int32_T in6)
{
  emlrtStack st;
  emxArray_real_T *b_in4;
  emxArray_real_T *b_in5;
  emxArray_real_T *r;
  const real_T *in4_data;
  real_T *b_in4_data;
  real_T *in5_data;
  int32_T aux_0_2;
  int32_T aux_1_2;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_1_1;
  int32_T unnamed_idx_1;
  int32_T unnamed_idx_2;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in5, 2, &nc_emlrtRTEI);
  i = b_in5->size[0] * b_in5->size[1];
  b_in5->size[0] = in6;
  loop_ub = in5->target_n->size[1];
  b_in5->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in5, i, &nc_emlrtRTEI);
  in5_data = b_in5->data;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < in6; i1++) {
      in5_data[i1 + b_in5->size[0] * i] = in5->V_ref.data[(int32_T)in5->
        target_n->data[i1 + 21 * i] - 1];
    }
  }

  unnamed_idx_1 = (int32_T)(in5->K - 1.0);
  unnamed_idx_2 = (int32_T)in5->NP;
  emxInit_real_T(sp, &b_in4, 3, &li_emlrtRTEI);
  i = b_in4->size[0] * b_in4->size[1] * b_in4->size[2];
  b_in4->size[0] = 1;
  b_in4->size[1] = 20;
  if (unnamed_idx_2 == 1) {
    loop_ub = in4->size[2];
  } else {
    loop_ub = unnamed_idx_2;
  }

  b_in4->size[2] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in4, i, &li_emlrtRTEI);
  b_in4_data = b_in4->data;
  stride_0_2 = (in4->size[2] != 1);
  stride_1_1 = (unnamed_idx_1 != 1);
  unnamed_idx_2 = (unnamed_idx_2 != 1);
  aux_0_2 = 0;
  aux_1_2 = 0;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      b_in4_data[i1 + 20 * i] = in4_data[2 * i1 + 42 * aux_0_2] - in5_data[i1 *
        stride_1_1 + unnamed_idx_1 * aux_1_2];
    }

    aux_1_2 += unnamed_idx_2;
    aux_0_2 += stride_0_2;
  }

  emxFree_real_T(sp, &b_in5);
  emxInit_real_T(sp, &r, 3, &mc_emlrtRTEI);
  i = r->size[0] * r->size[1] * r->size[2];
  r->size[0] = 1;
  r->size[1] = 20;
  r->size[2] = loop_ub;
  emxEnsureCapacity_real_T(sp, r, i, &mc_emlrtRTEI);
  in5_data = r->data;
  unnamed_idx_2 = 20 * b_in4->size[2];
  for (i = 0; i < unnamed_idx_2; i++) {
    real_T varargin_1;
    varargin_1 = b_in4_data[i];
    in5_data[i] = varargin_1 * varargin_1;
  }

  emxFree_real_T(sp, &b_in4);
  st.site = (emlrtRSInfo *)&in2;
  b_sum(&st, r, in1);
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_5(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emlrtRSInfo in2, const emxArray_boolean_T *in3, const emxArray_boolean_T
  *in4)
{
  emlrtStack st;
  emxArray_boolean_T *b_in3;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_1;
  int32_T stride_1_2;
  int32_T stride_1_3;
  const boolean_T *in3_data;
  const boolean_T *in4_data;
  boolean_T *b_in3_data;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in3, 4, &bc_emlrtRTEI);
  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2] * b_in3->size[3];
  b_in3->size[0] = 4;
  if (in4->size[1] == 1) {
    loop_ub = in3->size[1];
  } else {
    loop_ub = in4->size[1];
  }

  b_in3->size[1] = loop_ub;
  if (in4->size[2] == 1) {
    b_loop_ub = in3->size[2];
  } else {
    b_loop_ub = in4->size[2];
  }

  b_in3->size[2] = b_loop_ub;
  if (in4->size[3] == 1) {
    c_loop_ub = in3->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  b_in3->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, b_in3, i, &bc_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_1 = (in3->size[1] != 1);
  stride_0_2 = (in3->size[2] != 1);
  stride_0_3 = (in3->size[3] != 1);
  stride_1_1 = (in4->size[1] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      int32_T aux_0_1;
      int32_T aux_1_1;
      aux_0_1 = 0;
      aux_1_1 = 0;
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in3_data[(4 * i2 + 4 * b_in3->size[1] * i1) + 4 * b_in3->size[1] *
          b_in3->size[2] * i] = (in3_data[(4 * aux_0_1 + 4 * in3->size[1] *
          aux_0_2) + 4 * in3->size[1] * in3->size[2] * aux_0_3] && in4_data[(4 *
          aux_1_1 + 4 * in4->size[1] * aux_1_2) + 4 * in4->size[1] * in4->size[2]
          * aux_1_3]);
        b_in3_data[((4 * i2 + 4 * b_in3->size[1] * i1) + 4 * b_in3->size[1] *
                    b_in3->size[2] * i) + 1] = (in3_data[((4 * aux_0_1 + 4 *
          in3->size[1] * aux_0_2) + 4 * in3->size[1] * in3->size[2] * aux_0_3) +
          1] && in4_data[((4 * aux_1_1 + 4 * in4->size[1] * aux_1_2) + 4 *
                          in4->size[1] * in4->size[2] * aux_1_3) + 1]);
        b_in3_data[((4 * i2 + 4 * b_in3->size[1] * i1) + 4 * b_in3->size[1] *
                    b_in3->size[2] * i) + 2] = (in3_data[((4 * aux_0_1 + 4 *
          in3->size[1] * aux_0_2) + 4 * in3->size[1] * in3->size[2] * aux_0_3) +
          2] && in4_data[((4 * aux_1_1 + 4 * in4->size[1] * aux_1_2) + 4 *
                          in4->size[1] * in4->size[2] * aux_1_3) + 2]);
        b_in3_data[((4 * i2 + 4 * b_in3->size[1] * i1) + 4 * b_in3->size[1] *
                    b_in3->size[2] * i) + 3] = (in3_data[((4 * aux_0_1 + 4 *
          in3->size[1] * aux_0_2) + 4 * in3->size[1] * in3->size[2] * aux_0_3) +
          3] && in4_data[((4 * aux_1_1 + 4 * in4->size[1] * aux_1_2) + 4 *
                          in4->size[1] * in4->size[2] * aux_1_3) + 3]);
        aux_1_1 += stride_1_1;
        aux_0_1 += stride_0_1;
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  st.site = (emlrtRSInfo *)&in2;
  b_any(&st, b_in3, in1);
  emxFree_boolean_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_6(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4, const
  struct0_T *in5)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ec_emlrtRTEI);
  loop_ub = in4->size[1];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ec_emlrtRTEI);
  if (in4->size[2] == 1) {
    b_loop_ub = in3;
  } else {
    b_loop_ub = in4->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ec_emlrtRTEI);
  if (in4->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ec_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in3 != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T d;
        d = in4_data[((4 * i2 + 4 * in4->size[1] * aux_1_2) + 4 * in4->size[1] *
                      in4->size[2] * aux_1_3) + 3] + in5->wall_threshold;
        in1_data[(4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] * in1->
          size[2] * i] = (in2_data[(8 * aux_0_2 + 8 * in2->size[2] * aux_0_3) +
                          4] <= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 1] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 5] <= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 2] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 6] <= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 3] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 7] <= d);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_7(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4, const
  struct0_T *in5)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  emxEnsureCapacity_boolean_T(sp, in1, i, &dc_emlrtRTEI);
  loop_ub = in4->size[1];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &dc_emlrtRTEI);
  if (in4->size[2] == 1) {
    b_loop_ub = in3;
  } else {
    b_loop_ub = in4->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &dc_emlrtRTEI);
  if (in4->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &dc_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in3 != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T d;
        d = in4_data[((4 * i2 + 4 * in4->size[1] * aux_1_2) + 4 * in4->size[1] *
                      in4->size[2] * aux_1_3) + 2] - in5->wall_threshold;
        in1_data[(4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] * in1->
          size[2] * i] = (in2_data[(8 * aux_0_2 + 8 * in2->size[2] * aux_0_3) +
                          4] >= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 1] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 5] >= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 2] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 6] >= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 3] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 7] >= d);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_8(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4, const
  struct0_T *in5)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  emxEnsureCapacity_boolean_T(sp, in1, i, &cc_emlrtRTEI);
  loop_ub = in4->size[1];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &cc_emlrtRTEI);
  if (in4->size[2] == 1) {
    b_loop_ub = in3;
  } else {
    b_loop_ub = in4->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &cc_emlrtRTEI);
  if (in4->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &cc_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in3 != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T d;
        d = in4_data[((4 * i2 + 4 * in4->size[1] * aux_1_2) + 4 * in4->size[1] *
                      in4->size[2] * aux_1_3) + 1] + in5->wall_threshold;
        in1_data[(4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] * in1->
          size[2] * i] = (in2_data[8 * aux_0_2 + 8 * in2->size[2] * aux_0_3] <=
                          d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 1] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 1] <= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 2] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 2] <= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 3] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 3] <= d);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_9(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, int32_T in3, const emxArray_real_T *in4, const
  struct0_T *in5)
{
  const real_T *in2_data;
  const real_T *in4_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 4;
  emxEnsureCapacity_boolean_T(sp, in1, i, &bc_emlrtRTEI);
  loop_ub = in4->size[1];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &bc_emlrtRTEI);
  if (in4->size[2] == 1) {
    b_loop_ub = in3;
  } else {
    b_loop_ub = in4->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &bc_emlrtRTEI);
  if (in4->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &bc_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in3 != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T d;
        d = in4_data[(4 * i2 + 4 * in4->size[1] * aux_1_2) + 4 * in4->size[1] *
          in4->size[2] * aux_1_3] - in5->wall_threshold;
        in1_data[(4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] * in1->
          size[2] * i] = (in2_data[8 * aux_0_2 + 8 * in2->size[2] * aux_0_3] >=
                          d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 1] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 1] >= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 2] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 2] >= d);
        in1_data[((4 * i2 + 4 * in1->size[1] * i1) + 4 * in1->size[1] *
                  in1->size[2] * i) + 3] = (in2_data[(8 * aux_0_2 + 8 *
          in2->size[2] * aux_0_3) + 3] >= d);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void plus(const emlrtStack *sp, emxArray_real_T *in1, const
                 emxArray_real_T *in2)
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
  emxInit_real_T(sp, &b_in1, 2, &wc_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }

  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &wc_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in2->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] + in2_data[i * stride_1_1];
  }

  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &wc_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void EvaluationPath_vec(const emlrtStack *sp, const struct0_T *obj, const
  emxArray_real_T *px, const emxArray_real_T *pu, const real_T preobs_data[],
  const int32_T preobs_size[3], const struct1_T *param_FPM, emxArray_real_T *pw,
  emxArray_boolean_T *remove_sample)
{
  __m128d r2;
  __m128d r3;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *r4;
  emxArray_boolean_T *r5;
  emxArray_boolean_T *r7;
  emxArray_boolean_T *r8;
  emxArray_boolean_T *wall_near;
  emxArray_int32_T *i_obj;
  emxArray_int32_T *nz;
  emxArray_real_T f_obj;
  emxArray_real_T r13;
  emxArray_real_T *B;
  emxArray_real_T *NoEntryZone4;
  emxArray_real_T *WALLcost;
  emxArray_real_T *b_px;
  emxArray_real_T *b_y;
  emxArray_real_T *c_px;
  emxArray_real_T *d_px;
  emxArray_real_T *e_obj;
  emxArray_real_T *e_px;
  emxArray_real_T *f_px;
  emxArray_real_T *g_px;
  emxArray_real_T *grade;
  emxArray_real_T *r;
  emxArray_real_T *r10;
  emxArray_real_T *r11;
  emxArray_real_T *r12;
  emxArray_real_T *r14;
  emxArray_real_T *target2;
  emxArray_real_T *vehicle_corner;
  emxArray_real_T *wall_near_sum;
  emxArray_real_T *y;
  real_T b_preobs2_data[3780];
  real_T preobs2_data[3780];
  real_T c_tmp_data[2000];
  real_T d_tmp_data[2000];
  real_T dv[4];
  real_T dv1[2];
  const real_T *pu_data;
  const real_T *px_data;
  real_T b_obj;
  real_T d;
  real_T *B_data;
  real_T *NoEntryZone4_data;
  real_T *WALLcost_data;
  real_T *r1;
  real_T *vehicle_corner_data;
  real_T *wall_near_sum_data;
  int32_T b_iv[4];
  int32_T d_obj[4];
  int32_T g_obj[4];
  int32_T h_obj[4];
  int32_T j_obj[4];
  int32_T sz[4];
  int32_T b_tmp_size[3];
  int32_T tmp_size[3];
  int32_T c_obj[2];
  int32_T b_loop_ub;
  int32_T b_loop_ub_tmp;
  int32_T c_loop_ub_tmp;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T n;
  int32_T nx;
  int32_T nx_tmp;
  int32_T obj_tmp;
  int32_T scalarLB_tmp;
  int32_T vectorUB;
  int32_T *nz_data;
  boolean_T b_tmp_data[2000];
  boolean_T tmp_data[2000];
  boolean_T out;
  boolean_T *r6;
  boolean_T *r9;
  boolean_T *remove_sample_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  pu_data = pu->data;
  px_data = px->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emlrtMEXProfilingFunctionEntry((char_T *)c_EvaluationPath_vec_complete_n,
    isMexOutdated);

  /* 　EVALUATIONPATH この関数の概要をここに記述 */
  /* 　電動車椅子4点の座標 */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  if (!(obj->K >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K, &o_emlrtDCI, (emlrtConstCTX)sp);
  }

  d = muDoubleScalarFloor(obj->K);
  if (obj->K != (int32_T)d) {
    emlrtIntegerCheckR2012b(obj->K, &n_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &m_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (obj->NP != (int32_T)muDoubleScalarFloor(obj->NP)) {
    emlrtIntegerCheckR2012b(obj->NP, &l_emlrtDCI, (emlrtConstCTX)sp);
  }

  emxInit_real_T(sp, &vehicle_corner, 4, &r_emlrtRTEI);
  i = vehicle_corner->size[0] * vehicle_corner->size[1] * vehicle_corner->size[2]
    * vehicle_corner->size[3];
  vehicle_corner->size[0] = 4;
  vehicle_corner->size[1] = 2;
  loop_ub_tmp = (int32_T)obj->K;
  vehicle_corner->size[2] = (int32_T)obj->K;
  b_loop_ub_tmp = (int32_T)obj->NP;
  vehicle_corner->size[3] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, vehicle_corner, i, &r_emlrtRTEI);
  vehicle_corner_data = vehicle_corner->data;
  c_loop_ub_tmp = ((int32_T)obj->K << 3) * (int32_T)obj->NP;
  for (i = 0; i < c_loop_ub_tmp; i++) {
    vehicle_corner_data[i] = 0.0;
  }

  /*  左後ろ */
  emlrtMEXProfilingStatement(2, isMexOutdated);
  st.site = &emlrtRSI;
  nx_tmp = 21 * px->size[2];
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  loop_ub = (int32_T)obj->K * (int32_T)obj->NP;
  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_obj = obj->ltheta[1];
  emxInit_real_T(sp, &b_px, 3, &s_emlrtRTEI);
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_loop_ub = px->size[2];
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &s_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 2];
    }
  }

  emxInit_real_T(sp, &r, 2, &t_emlrtRTEI);
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &t_emlrtRTEI);
  r1 = r->data;
  scalarLB_tmp = (loop_ub / 2) << 1;
  nx = scalarLB_tmp - 2;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&r1[i], _mm_add_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = b_obj + B_data[i];
  }

  st.site = &emlrtRSI;
  b_sin(&st, r);
  r1 = r->data;
  c_loop_ub_tmp = r->size[0] * r->size[1];
  b_obj = obj->ltheta[0];
  n = (c_loop_ub_tmp / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&r1[i], _mm_mul_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = n; i < c_loop_ub_tmp; i++) {
    r1[i] *= b_obj;
  }

  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&c_obj[0], &r->size[0], &ob_emlrtECI,
      (emlrtCTX)sp);
  }

  d_obj[0] = 1;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&d_obj[0], 4, &c_obj[0], 2, &gb_emlrtECI,
    (emlrtCTX)sp);
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &u_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[3 * i1 + 63 * i];
    }
  }

  emxInit_real_T(sp, &c_px, 2, &v_emlrtRTEI);
  i = c_px->size[0] * c_px->size[1];
  c_px->size[0] = (int32_T)obj->K;
  c_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, c_px, i, &v_emlrtRTEI);
  NoEntryZone4_data = c_px->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    r3 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    NoEntryZone4_data[i] = B_data[i] + r1[i];
  }

  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      vehicle_corner_data[8 * i1 + 8 * vehicle_corner->size[2] * i] =
        NoEntryZone4_data[i1 + loop_ub_tmp * i];
    }
  }

  emlrtMEXProfilingStatement(3, isMexOutdated);
  st.site = &b_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &b_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_obj = obj->ltheta[9];
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &w_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 2];
    }
  }

  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &x_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&r1[i], _mm_add_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = b_obj + B_data[i];
  }

  st.site = &b_emlrtRSI;
  b_cos(&st, r);
  r1 = r->data;
  c_loop_ub_tmp = r->size[0] * r->size[1];
  b_obj = obj->ltheta[8];
  n = (c_loop_ub_tmp / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&r1[i], _mm_mul_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = n; i < c_loop_ub_tmp; i++) {
    r1[i] *= b_obj;
  }

  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&c_obj[0], &r->size[0], &nb_emlrtECI,
      (emlrtCTX)sp);
  }

  d_obj[0] = 1;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&d_obj[0], 4, &c_obj[0], 2, &fb_emlrtECI,
    (emlrtCTX)sp);
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &y_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 1];
    }
  }

  i = c_px->size[0] * c_px->size[1];
  c_px->size[0] = (int32_T)obj->K;
  c_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, c_px, i, &ab_emlrtRTEI);
  NoEntryZone4_data = c_px->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    r3 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    NoEntryZone4_data[i] = B_data[i] + r1[i];
  }

  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 4] =
        NoEntryZone4_data[i1 + loop_ub_tmp * i];
    }
  }

  /* 　左前 */
  emlrtMEXProfilingStatement(4, isMexOutdated);
  st.site = &c_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &c_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_obj = obj->ltheta[3];
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &bb_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 2];
    }
  }

  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &cb_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&r1[i], _mm_add_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = b_obj + B_data[i];
  }

  st.site = &c_emlrtRSI;
  b_cos(&st, r);
  r1 = r->data;
  c_loop_ub_tmp = r->size[0] * r->size[1];
  b_obj = obj->ltheta[2];
  n = (c_loop_ub_tmp / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&r1[i], _mm_mul_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = n; i < c_loop_ub_tmp; i++) {
    r1[i] *= b_obj;
  }

  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&c_obj[0], &r->size[0], &mb_emlrtECI,
      (emlrtCTX)sp);
  }

  d_obj[0] = 1;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&d_obj[0], 4, &c_obj[0], 2, &eb_emlrtECI,
    (emlrtCTX)sp);
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &u_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[3 * i1 + 63 * i];
    }
  }

  i = c_px->size[0] * c_px->size[1];
  c_px->size[0] = (int32_T)obj->K;
  c_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, c_px, i, &db_emlrtRTEI);
  NoEntryZone4_data = c_px->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    r3 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    NoEntryZone4_data[i] = B_data[i] + r1[i];
  }

  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 1] =
        NoEntryZone4_data[i1 + loop_ub_tmp * i];
    }
  }

  emlrtMEXProfilingStatement(5, isMexOutdated);
  st.site = &d_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &d_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_obj = obj->ltheta[11];
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &eb_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 2];
    }
  }

  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &fb_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&r1[i], _mm_add_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = b_obj + B_data[i];
  }

  st.site = &d_emlrtRSI;
  b_sin(&st, r);
  r1 = r->data;
  c_loop_ub_tmp = r->size[0] * r->size[1];
  b_obj = obj->ltheta[10];
  n = (c_loop_ub_tmp / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&r1[i], _mm_mul_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = n; i < c_loop_ub_tmp; i++) {
    r1[i] *= b_obj;
  }

  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&c_obj[0], &r->size[0], &lb_emlrtECI,
      (emlrtCTX)sp);
  }

  d_obj[0] = 1;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&d_obj[0], 4, &c_obj[0], 2, &db_emlrtECI,
    (emlrtCTX)sp);
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &y_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 1];
    }
  }

  i = c_px->size[0] * c_px->size[1];
  c_px->size[0] = (int32_T)obj->K;
  c_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, c_px, i, &gb_emlrtRTEI);
  NoEntryZone4_data = c_px->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    r3 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    NoEntryZone4_data[i] = B_data[i] + r1[i];
  }

  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 5] =
        NoEntryZone4_data[i1 + loop_ub_tmp * i];
    }
  }

  /* 　右後ろ */
  emlrtMEXProfilingStatement(6, isMexOutdated);
  st.site = &e_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &e_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_obj = obj->ltheta[5];
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &hb_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 2];
    }
  }

  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &ib_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&r1[i], _mm_sub_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = b_obj - B_data[i];
  }

  st.site = &e_emlrtRSI;
  b_cos(&st, r);
  r1 = r->data;
  c_loop_ub_tmp = r->size[0] * r->size[1];
  b_obj = obj->ltheta[4];
  n = (c_loop_ub_tmp / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&r1[i], _mm_mul_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = n; i < c_loop_ub_tmp; i++) {
    r1[i] *= b_obj;
  }

  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&c_obj[0], &r->size[0], &kb_emlrtECI,
      (emlrtCTX)sp);
  }

  d_obj[0] = 1;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&d_obj[0], 4, &c_obj[0], 2, &cb_emlrtECI,
    (emlrtCTX)sp);
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &u_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[3 * i1 + 63 * i];
    }
  }

  i = c_px->size[0] * c_px->size[1];
  c_px->size[0] = (int32_T)obj->K;
  c_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, c_px, i, &jb_emlrtRTEI);
  NoEntryZone4_data = c_px->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    r3 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    NoEntryZone4_data[i] = B_data[i] + r1[i];
  }

  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 2] =
        NoEntryZone4_data[i1 + loop_ub_tmp * i];
    }
  }

  emlrtMEXProfilingStatement(7, isMexOutdated);
  st.site = &f_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &f_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_obj = obj->ltheta[13];
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &kb_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 2];
    }
  }

  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &lb_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&r1[i], _mm_sub_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = b_obj - B_data[i];
  }

  st.site = &f_emlrtRSI;
  b_sin(&st, r);
  r1 = r->data;
  c_loop_ub_tmp = r->size[0] * r->size[1];
  b_obj = obj->ltheta[12];
  n = (c_loop_ub_tmp / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&r1[i], _mm_mul_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = n; i < c_loop_ub_tmp; i++) {
    r1[i] *= b_obj;
  }

  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&c_obj[0], &r->size[0], &jb_emlrtECI,
      (emlrtCTX)sp);
  }

  d_obj[0] = 1;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&d_obj[0], 4, &c_obj[0], 2, &bb_emlrtECI,
    (emlrtCTX)sp);
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &y_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 1];
    }
  }

  i = c_px->size[0] * c_px->size[1];
  c_px->size[0] = (int32_T)obj->K;
  c_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, c_px, i, &mb_emlrtRTEI);
  NoEntryZone4_data = c_px->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    r3 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    NoEntryZone4_data[i] = B_data[i] + r1[i];
  }

  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 6] =
        NoEntryZone4_data[i1 + loop_ub_tmp * i];
    }
  }

  /* 　右前 */
  emlrtMEXProfilingStatement(8, isMexOutdated);
  st.site = &g_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &g_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_obj = obj->ltheta[7];
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &nb_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 2];
    }
  }

  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &ob_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&r1[i], _mm_add_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = b_obj + B_data[i];
  }

  st.site = &g_emlrtRSI;
  b_cos(&st, r);
  r1 = r->data;
  c_loop_ub_tmp = r->size[0] * r->size[1];
  b_obj = obj->ltheta[6];
  n = (c_loop_ub_tmp / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&r1[i], _mm_mul_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = n; i < c_loop_ub_tmp; i++) {
    r1[i] *= b_obj;
  }

  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&c_obj[0], &r->size[0], &ib_emlrtECI,
      (emlrtCTX)sp);
  }

  d_obj[0] = 1;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&d_obj[0], 4, &c_obj[0], 2, &ab_emlrtECI,
    (emlrtCTX)sp);
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &u_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[3 * i1 + 63 * i];
    }
  }

  i = c_px->size[0] * c_px->size[1];
  c_px->size[0] = (int32_T)obj->K;
  c_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, c_px, i, &pb_emlrtRTEI);
  NoEntryZone4_data = c_px->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    r3 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    NoEntryZone4_data[i] = B_data[i] + r1[i];
  }

  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 3] =
        NoEntryZone4_data[i1 + loop_ub_tmp * i];
    }
  }

  emlrtMEXProfilingStatement(9, isMexOutdated);
  st.site = &h_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &h_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->K >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (loop_ub != nx_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_obj = obj->ltheta[15];
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &qb_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 2];
    }
  }

  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)obj->K;
  r->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, r, i, &rb_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    _mm_storeu_pd(&r1[i], _mm_add_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r1[i] = b_obj + B_data[i];
  }

  st.site = &h_emlrtRSI;
  b_sin(&st, r);
  r1 = r->data;
  c_loop_ub_tmp = r->size[0] * r->size[1];
  b_obj = obj->ltheta[14];
  n = (c_loop_ub_tmp / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&r1[i], _mm_mul_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = n; i < c_loop_ub_tmp; i++) {
    r1[i] *= b_obj;
  }

  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  if (((int32_T)obj->K != r->size[0]) || ((int32_T)obj->NP != r->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&c_obj[0], &r->size[0], &hb_emlrtECI,
      (emlrtCTX)sp);
  }

  d_obj[0] = 1;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  c_obj[0] = (int32_T)obj->K;
  c_obj[1] = (int32_T)obj->NP;
  emlrtSubAssignSizeCheckR2012b(&d_obj[0], 4, &c_obj[0], 2, &y_emlrtECI,
    (emlrtCTX)sp);
  i = b_px->size[0] * b_px->size[1] * b_px->size[2];
  b_px->size[0] = 1;
  b_px->size[1] = 21;
  b_px->size[2] = px->size[2];
  emxEnsureCapacity_real_T(sp, b_px, i, &y_emlrtRTEI);
  B_data = b_px->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 21; i1++) {
      B_data[i1 + 21 * i] = px_data[(3 * i1 + 63 * i) + 1];
    }
  }

  i = c_px->size[0] * c_px->size[1];
  c_px->size[0] = (int32_T)obj->K;
  c_px->size[1] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, c_px, i, &sb_emlrtRTEI);
  NoEntryZone4_data = c_px->data;
  for (i = 0; i <= nx; i += 2) {
    r2 = _mm_loadu_pd(&B_data[i]);
    r3 = _mm_loadu_pd(&r1[i]);
    _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++) {
    NoEntryZone4_data[i] = B_data[i] + r1[i];
  }

  emxFree_real_T(sp, &b_px);
  emxFree_real_T(sp, &r);
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 7] =
        NoEntryZone4_data[i1 + loop_ub_tmp * i];
    }
  }

  emxFree_real_T(sp, &c_px);

  /*     %% wall */
  emlrtMEXProfilingStatement(10, isMexOutdated);
  if (obj->K < 1.0) {
    loop_ub = 0;
  } else {
    if (obj->K != (int32_T)d) {
      emlrtIntegerCheckR2012b(obj->K, &k_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)obj->K < 1) || ((int32_T)obj->K > 21)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj->K, 1, 21, &k_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    loop_ub = (int32_T)obj->K;
  }

  c_obj[0] = loop_ub;
  obj_tmp = obj->target_n->size[1];
  c_obj[1] = obj->target_n->size[1];
  st.site = &i_emlrtRSI;
  indexShapeCheck(&st, obj->selectZone.size[0], c_obj);
  emxInit_real_T(sp, &B, 2, &tb_emlrtRTEI);
  i = B->size[0] * B->size[1];
  B->size[0] = loop_ub;
  B->size[1] = obj->target_n->size[1];
  emxEnsureCapacity_real_T(sp, B, i, &tb_emlrtRTEI);
  B_data = B->data;
  for (i = 0; i < obj_tmp; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_loop_ub_tmp = i1 + 21 * i;
      if (obj->target_n->data[c_loop_ub_tmp] != (int32_T)muDoubleScalarFloor
          (obj->target_n->data[c_loop_ub_tmp])) {
        emlrtIntegerCheckR2012b(obj->target_n->data[i1 + 21 * i], &e_emlrtDCI,
          (emlrtConstCTX)sp);
      }

      c_loop_ub_tmp = (int32_T)obj->target_n->data[c_loop_ub_tmp];
      if ((c_loop_ub_tmp < 1) || (c_loop_ub_tmp > obj->selectZone.size[0])) {
        emlrtDynamicBoundsCheckR2012b(c_loop_ub_tmp, 1, obj->selectZone.size[0],
          &e_emlrtBCI, (emlrtConstCTX)sp);
      }

      B_data[i1 + B->size[0] * i] = obj->selectZone.data[c_loop_ub_tmp - 1];
    }
  }

  emlrtMEXProfilingStatement(11, isMexOutdated);
  emlrtMEXProfilingStatement(12, isMexOutdated);

  /*  Bを1列ベクトルに変換 */
  emlrtMEXProfilingStatement(13, isMexOutdated);

  /*  [p*q, 1] */
  /*  NoEntryZoneの各スライスを2次元に展開 */
  emlrtMEXProfilingStatement(14, isMexOutdated);
  scalarLB_tmp = obj->NoEntryZone.size[0] << 2;
  st.site = &j_emlrtRSI;
  nx = scalarLB_tmp * 10;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, scalarLB_tmp);
  if (scalarLB_tmp > muIntScalarMax_sint32(nx, 10)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (scalarLB_tmp * 10 != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  /*  [m*n, k] */
  /*  BvecでNoEntryZone2から列を抽出 */
  emlrtMEXProfilingStatement(15, isMexOutdated);
  c_loop_ub_tmp = loop_ub * obj->target_n->size[1];
  for (i = 0; i < c_loop_ub_tmp; i++) {
    b_obj = B_data[i];
    if (b_obj != (int32_T)muDoubleScalarFloor(b_obj)) {
      emlrtIntegerCheckR2012b(b_obj, &d_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)b_obj < 1) || ((int32_T)b_obj > 10)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_obj, 1, 10, &d_emlrtBCI,
        (emlrtConstCTX)sp);
    }
  }

  /*  [m*n, p*q] */
  /*  元の形に戻す */
  emlrtMEXProfilingStatement(16, isMexOutdated);
  st.site = &k_emlrtRSI;
  nx = scalarLB_tmp * c_loop_ub_tmp;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NoEntryZone.size[0]);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, loop_ub);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->target_n->size[1]);
  n = scalarLB_tmp;
  if (c_loop_ub_tmp > scalarLB_tmp) {
    n = c_loop_ub_tmp;
  }

  n = muIntScalarMax_sint32(nx, n);
  if (obj->NoEntryZone.size[0] > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (n < 4) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (loop_ub > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (obj->target_n->size[1] > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (scalarLB_tmp * loop_ub * obj->target_n->size[1] != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emxInit_real_T(sp, &e_obj, 2, &ub_emlrtRTEI);
  i = e_obj->size[0] * e_obj->size[1];
  e_obj->size[0] = scalarLB_tmp;
  e_obj->size[1] = c_loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, e_obj, i, &ub_emlrtRTEI);
  NoEntryZone4_data = e_obj->data;
  for (i = 0; i < c_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < scalarLB_tmp; i1++) {
      NoEntryZone4_data[i1 + e_obj->size[0] * i] = obj->NoEntryZone.data[i1 +
        scalarLB_tmp * ((int32_T)B_data[i] - 1)];
    }
  }

  d_obj[3] = obj->target_n->size[1];
  f_obj = *e_obj;
  g_obj[0] = obj->NoEntryZone.size[0];
  g_obj[1] = 4;
  g_obj[2] = loop_ub;
  g_obj[3] = d_obj[3];
  f_obj.size = &g_obj[0];
  f_obj.numDimensions = 4;
  emxInit_real_T(sp, &NoEntryZone4, 4, &yc_emlrtRTEI);
  st.site = &k_emlrtRSI;
  pagetranspose(&st, &f_obj, NoEntryZone4);
  NoEntryZone4_data = NoEntryZone4->data;
  emxFree_real_T(sp, &e_obj);

  /*  [m, n, p, q] */
  /*     %% 壁面制約 */
  emlrtMEXProfilingStatement(17, isMexOutdated);
  emlrtMEXProfilingStatement(18, isMexOutdated);
  if (vehicle_corner->size[2] < 1) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)obj->K;
  }

  if ((loop_ub != NoEntryZone4->size[2]) && ((loop_ub != 1) &&
       (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, NoEntryZone4->size[2], &q_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (((int32_T)obj->NP != NoEntryZone4->size[3]) && (((int32_T)obj->NP != 1) &&
       (NoEntryZone4->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b((int32_T)obj->NP, NoEntryZone4->size[3],
      &p_emlrtECI, (emlrtConstCTX)sp);
  }

  if (vehicle_corner->size[2] < 1) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int32_T)obj->K;
  }

  if ((b_loop_ub != NoEntryZone4->size[2]) && ((b_loop_ub != 1) &&
       (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(b_loop_ub, NoEntryZone4->size[2], &x_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (((int32_T)obj->NP != NoEntryZone4->size[3]) && (((int32_T)obj->NP != 1) &&
       (NoEntryZone4->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b((int32_T)obj->NP, NoEntryZone4->size[3],
      &w_emlrtECI, (emlrtConstCTX)sp);
  }

  emxInit_boolean_T(sp, &r4, 4, &vb_emlrtRTEI);
  if ((loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] ==
       NoEntryZone4->size[3])) {
    i = r4->size[0] * r4->size[1] * r4->size[2] * r4->size[3];
    r4->size[0] = 4;
    nx = NoEntryZone4->size[1];
    r4->size[1] = NoEntryZone4->size[1];
    r4->size[2] = loop_ub;
    r4->size[3] = (int32_T)obj->NP;
    emxEnsureCapacity_boolean_T(sp, r4, i, &vb_emlrtRTEI);
    r6 = r4->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < nx; c_loop_ub_tmp++) {
          r6[(4 * c_loop_ub_tmp + 4 * r4->size[1] * i1) + 4 * r4->size[1] *
            r4->size[2] * i] = (vehicle_corner_data[8 * i1 + 8 *
                                vehicle_corner->size[2] * i] >=
                                NoEntryZone4_data[(4 * c_loop_ub_tmp + 4 *
            NoEntryZone4->size[1] * i1) + 4 * NoEntryZone4->size[1] *
                                NoEntryZone4->size[2] * i]);
          r6[((4 * c_loop_ub_tmp + 4 * r4->size[1] * i1) + 4 * r4->size[1] *
              r4->size[2] * i) + 1] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 1] >= NoEntryZone4_data[(4 *
            c_loop_ub_tmp + 4 * NoEntryZone4->size[1] * i1) + 4 *
            NoEntryZone4->size[1] * NoEntryZone4->size[2] * i]);
          r6[((4 * c_loop_ub_tmp + 4 * r4->size[1] * i1) + 4 * r4->size[1] *
              r4->size[2] * i) + 2] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 2] >= NoEntryZone4_data[(4 *
            c_loop_ub_tmp + 4 * NoEntryZone4->size[1] * i1) + 4 *
            NoEntryZone4->size[1] * NoEntryZone4->size[2] * i]);
          r6[((4 * c_loop_ub_tmp + 4 * r4->size[1] * i1) + 4 * r4->size[1] *
              r4->size[2] * i) + 3] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 3] >= NoEntryZone4_data[(4 *
            c_loop_ub_tmp + 4 * NoEntryZone4->size[1] * i1) + 4 *
            NoEntryZone4->size[1] * NoEntryZone4->size[2] * i]);
        }
      }
    }
  } else {
    st.site = &l_emlrtRSI;
    binary_expand_op_14(&st, r4, vehicle_corner, loop_ub, NoEntryZone4);
  }

  emxInit_boolean_T(sp, &r5, 4, &vb_emlrtRTEI);
  if ((b_loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] ==
       NoEntryZone4->size[3])) {
    i = r5->size[0] * r5->size[1] * r5->size[2] * r5->size[3];
    r5->size[0] = 4;
    loop_ub = NoEntryZone4->size[1];
    r5->size[1] = NoEntryZone4->size[1];
    r5->size[2] = b_loop_ub;
    nx = vehicle_corner->size[3];
    r5->size[3] = vehicle_corner->size[3];
    emxEnsureCapacity_boolean_T(sp, r5, i, &wb_emlrtRTEI);
    remove_sample_data = r5->data;
    for (i = 0; i < nx; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < loop_ub; c_loop_ub_tmp++) {
          remove_sample_data[(4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
            r5->size[1] * r5->size[2] * i] = (vehicle_corner_data[8 * i1 + 8 *
            vehicle_corner->size[2] * i] <= NoEntryZone4_data[((4 *
            c_loop_ub_tmp + 4 * NoEntryZone4->size[1] * i1) + 4 *
            NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) + 1]);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 1] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 1]
             <= NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->size[1]
               * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) +
             1]);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 2] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 2]
             <= NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->size[1]
               * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) +
             1]);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 3] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 3]
             <= NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->size[1]
               * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) +
             1]);
        }
      }
    }
  } else {
    st.site = &l_emlrtRSI;
    binary_expand_op_13(&st, r5, vehicle_corner, b_loop_ub, NoEntryZone4);
    remove_sample_data = r5->data;
  }

  if ((r4->size[1] != r5->size[1]) && ((r4->size[1] != 1) && (r5->size[1] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[1], r5->size[1], &r_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[2] != r5->size[2]) && ((r4->size[2] != 1) && (r5->size[2] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[2], r5->size[2], &q_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[3] != r5->size[3]) && ((r4->size[3] != 1) && (r5->size[3] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[3], r5->size[3], &p_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (vehicle_corner->size[2] < 1) {
    loop_ub = 0;
  } else {
    loop_ub = vehicle_corner->size[2];
  }

  if ((loop_ub != NoEntryZone4->size[2]) && ((loop_ub != 1) &&
       (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, NoEntryZone4->size[2], &v_emlrtECI,
      (emlrtConstCTX)sp);
  }

  b_loop_ub = vehicle_corner->size[3];
  if ((vehicle_corner->size[3] != NoEntryZone4->size[3]) &&
      ((vehicle_corner->size[3] != 1) && (NoEntryZone4->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(vehicle_corner->size[3], NoEntryZone4->size[3],
      &u_emlrtECI, (emlrtConstCTX)sp);
  }

  if ((r4->size[1] == r5->size[1]) && (r4->size[2] == r5->size[2]) && (r4->size
       [3] == r5->size[3])) {
    c_loop_ub_tmp = (r4->size[1] << 2) * r4->size[2] * r4->size[3];
    i = r4->size[0] * r4->size[1] * r4->size[2] * r4->size[3];
    r4->size[0] = 4;
    emxEnsureCapacity_boolean_T(sp, r4, i, &vb_emlrtRTEI);
    r6 = r4->data;
    for (i = 0; i < c_loop_ub_tmp; i++) {
      r6[i] = (r6[i] && remove_sample_data[i]);
    }
  } else {
    st.site = &l_emlrtRSI;
    b_and(&st, r4, r5);
  }

  if ((loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] ==
       NoEntryZone4->size[3])) {
    i = r5->size[0] * r5->size[1] * r5->size[2] * r5->size[3];
    r5->size[0] = 4;
    nx = NoEntryZone4->size[1];
    r5->size[1] = NoEntryZone4->size[1];
    r5->size[2] = loop_ub;
    r5->size[3] = vehicle_corner->size[3];
    emxEnsureCapacity_boolean_T(sp, r5, i, &xb_emlrtRTEI);
    remove_sample_data = r5->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < nx; c_loop_ub_tmp++) {
          remove_sample_data[(4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
            r5->size[1] * r5->size[2] * i] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 4] >= NoEntryZone4_data[((4 *
            c_loop_ub_tmp + 4 * NoEntryZone4->size[1] * i1) + 4 *
            NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) + 2]);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 1] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 5]
             >= NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->size[1]
               * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) +
             2]);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 2] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 6]
             >= NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->size[1]
               * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) +
             2]);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 3] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 7]
             >= NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->size[1]
               * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) +
             2]);
        }
      }
    }
  } else {
    st.site = &xg_emlrtRSI;
    binary_expand_op_12(&st, r5, vehicle_corner, loop_ub, NoEntryZone4);
    remove_sample_data = r5->data;
  }

  if ((r4->size[1] != r5->size[1]) && ((r4->size[1] != 1) && (r5->size[1] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[1], r5->size[1], &r_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[2] != r5->size[2]) && ((r4->size[2] != 1) && (r5->size[2] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[2], r5->size[2], &q_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[3] != r5->size[3]) && ((r4->size[3] != 1) && (r5->size[3] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[3], r5->size[3], &p_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (vehicle_corner->size[2] < 1) {
    loop_ub = 0;
  } else {
    loop_ub = vehicle_corner->size[2];
  }

  if ((loop_ub != NoEntryZone4->size[2]) && ((loop_ub != 1) &&
       (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, NoEntryZone4->size[2], &t_emlrtECI,
      (emlrtConstCTX)sp);
  }

  b_loop_ub = vehicle_corner->size[3];
  if ((vehicle_corner->size[3] != NoEntryZone4->size[3]) &&
      ((vehicle_corner->size[3] != 1) && (NoEntryZone4->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(vehicle_corner->size[3], NoEntryZone4->size[3],
      &s_emlrtECI, (emlrtConstCTX)sp);
  }

  if ((r4->size[1] == r5->size[1]) && (r4->size[2] == r5->size[2]) && (r4->size
       [3] == r5->size[3])) {
    c_loop_ub_tmp = (r4->size[1] << 2) * r4->size[2] * r4->size[3];
    i = r4->size[0] * r4->size[1] * r4->size[2] * r4->size[3];
    r4->size[0] = 4;
    emxEnsureCapacity_boolean_T(sp, r4, i, &vb_emlrtRTEI);
    r6 = r4->data;
    for (i = 0; i < c_loop_ub_tmp; i++) {
      r6[i] = (r6[i] && remove_sample_data[i]);
    }
  } else {
    st.site = &l_emlrtRSI;
    b_and(&st, r4, r5);
    r6 = r4->data;
  }

  if ((loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] ==
       NoEntryZone4->size[3])) {
    i = r5->size[0] * r5->size[1] * r5->size[2] * r5->size[3];
    r5->size[0] = 4;
    nx = NoEntryZone4->size[1];
    r5->size[1] = NoEntryZone4->size[1];
    r5->size[2] = loop_ub;
    r5->size[3] = vehicle_corner->size[3];
    emxEnsureCapacity_boolean_T(sp, r5, i, &yb_emlrtRTEI);
    remove_sample_data = r5->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < nx; c_loop_ub_tmp++) {
          remove_sample_data[(4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
            r5->size[1] * r5->size[2] * i] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 4] <= NoEntryZone4_data[((4 *
            c_loop_ub_tmp + 4 * NoEntryZone4->size[1] * i1) + 4 *
            NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) + 3]);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 1] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 5]
             <= NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->size[1]
               * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) +
             3]);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 2] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 6]
             <= NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->size[1]
               * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) +
             3]);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 3] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 7]
             <= NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->size[1]
               * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i) +
             3]);
        }
      }
    }
  } else {
    st.site = &xg_emlrtRSI;
    binary_expand_op_11(&st, r5, vehicle_corner, loop_ub, NoEntryZone4);
    remove_sample_data = r5->data;
  }

  if ((r4->size[1] != r5->size[1]) && ((r4->size[1] != 1) && (r5->size[1] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[1], r5->size[1], &r_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[2] != r5->size[2]) && ((r4->size[2] != 1) && (r5->size[2] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[2], r5->size[2], &q_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[3] != r5->size[3]) && ((r4->size[3] != 1) && (r5->size[3] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[3], r5->size[3], &p_emlrtECI,
      (emlrtConstCTX)sp);
  }

  emxInit_boolean_T(sp, &r7, 4, &dd_emlrtRTEI);
  emxInit_boolean_T(sp, &r8, 4, &vb_emlrtRTEI);
  if ((r4->size[1] == r5->size[1]) && (r4->size[2] == r5->size[2]) && (r4->size
       [3] == r5->size[3])) {
    i = r8->size[0] * r8->size[1] * r8->size[2] * r8->size[3];
    r8->size[0] = 4;
    r8->size[1] = r4->size[1];
    r8->size[2] = r4->size[2];
    r8->size[3] = r4->size[3];
    emxEnsureCapacity_boolean_T(sp, r8, i, &vb_emlrtRTEI);
    r9 = r8->data;
    c_loop_ub_tmp = (r4->size[1] << 2) * r4->size[2] * r4->size[3];
    for (i = 0; i < c_loop_ub_tmp; i++) {
      r9[i] = (r6[i] && remove_sample_data[i]);
    }

    st.site = &l_emlrtRSI;
    any(&st, r8, r7);
    r6 = r7->data;
  } else {
    st.site = &l_emlrtRSI;
    binary_expand_op_10(&st, r7, l_emlrtRSI, r4, r5);
    r6 = r7->data;
  }

  st.site = &l_emlrtRSI;
  nx_tmp = r7->size[3];
  b_st.site = &cb_emlrtRSI;
  n = 1;
  if (r7->size[3] > 1) {
    n = r7->size[3];
  }

  if (r7->size[3] > muIntScalarMax_sint32(nx_tmp, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  i = remove_sample->size[0];
  remove_sample->size[0] = r7->size[3];
  emxEnsureCapacity_boolean_T(sp, remove_sample, i, &ac_emlrtRTEI);
  remove_sample_data = remove_sample->data;
  for (i = 0; i < nx_tmp; i++) {
    remove_sample_data[i] = r6[i];
  }

  emxFree_boolean_T(sp, &r7);

  /*     %% Wall cost */
  emlrtMEXProfilingStatement(19, isMexOutdated);
  emlrtMEXProfilingStatement(20, isMexOutdated);
  if (vehicle_corner->size[2] < 1) {
    loop_ub = 0;
  } else {
    loop_ub = vehicle_corner->size[2];
  }

  if ((loop_ub != NoEntryZone4->size[2]) && ((loop_ub != 1) &&
       (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, NoEntryZone4->size[2], &h_emlrtECI,
      (emlrtConstCTX)sp);
  }

  b_loop_ub = vehicle_corner->size[3];
  if ((vehicle_corner->size[3] != NoEntryZone4->size[3]) &&
      ((vehicle_corner->size[3] != 1) && (NoEntryZone4->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(vehicle_corner->size[3], NoEntryZone4->size[3],
      &g_emlrtECI, (emlrtConstCTX)sp);
  }

  if (vehicle_corner->size[2] < 1) {
    nx = 0;
  } else {
    nx = vehicle_corner->size[2];
  }

  if ((nx != NoEntryZone4->size[2]) && ((nx != 1) && (NoEntryZone4->size[2] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(nx, NoEntryZone4->size[2], &o_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((vehicle_corner->size[3] != NoEntryZone4->size[3]) &&
      ((vehicle_corner->size[3] != 1) && (NoEntryZone4->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(vehicle_corner->size[3], NoEntryZone4->size[3],
      &n_emlrtECI, (emlrtConstCTX)sp);
  }

  if ((loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] ==
       NoEntryZone4->size[3])) {
    i = r4->size[0] * r4->size[1] * r4->size[2] * r4->size[3];
    r4->size[0] = 4;
    scalarLB_tmp = NoEntryZone4->size[1];
    r4->size[1] = NoEntryZone4->size[1];
    r4->size[2] = loop_ub;
    r4->size[3] = vehicle_corner->size[3];
    emxEnsureCapacity_boolean_T(sp, r4, i, &bc_emlrtRTEI);
    r6 = r4->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < scalarLB_tmp; c_loop_ub_tmp++) {
          b_obj = NoEntryZone4_data[(4 * c_loop_ub_tmp + 4 * NoEntryZone4->size
            [1] * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] * i] -
            obj->wall_threshold;
          r6[(4 * c_loop_ub_tmp + 4 * r4->size[1] * i1) + 4 * r4->size[1] *
            r4->size[2] * i] = (vehicle_corner_data[8 * i1 + 8 *
                                vehicle_corner->size[2] * i] >= b_obj);
          r6[((4 * c_loop_ub_tmp + 4 * r4->size[1] * i1) + 4 * r4->size[1] *
              r4->size[2] * i) + 1] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 1] >= b_obj);
          r6[((4 * c_loop_ub_tmp + 4 * r4->size[1] * i1) + 4 * r4->size[1] *
              r4->size[2] * i) + 2] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 2] >= b_obj);
          r6[((4 * c_loop_ub_tmp + 4 * r4->size[1] * i1) + 4 * r4->size[1] *
              r4->size[2] * i) + 3] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 3] >= b_obj);
        }
      }
    }
  } else {
    st.site = &m_emlrtRSI;
    binary_expand_op_9(&st, r4, vehicle_corner, loop_ub, NoEntryZone4, obj);
  }

  if ((nx == NoEntryZone4->size[2]) && (vehicle_corner->size[3] ==
       NoEntryZone4->size[3])) {
    i = r5->size[0] * r5->size[1] * r5->size[2] * r5->size[3];
    r5->size[0] = 4;
    loop_ub = NoEntryZone4->size[1];
    r5->size[1] = NoEntryZone4->size[1];
    r5->size[2] = nx;
    b_loop_ub = vehicle_corner->size[3];
    r5->size[3] = vehicle_corner->size[3];
    emxEnsureCapacity_boolean_T(sp, r5, i, &cc_emlrtRTEI);
    remove_sample_data = r5->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < loop_ub; c_loop_ub_tmp++) {
          b_obj = NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->
            size[1] * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] *
            i) + 1] + obj->wall_threshold;
          remove_sample_data[(4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
            r5->size[1] * r5->size[2] * i] = (vehicle_corner_data[8 * i1 + 8 *
            vehicle_corner->size[2] * i] <= b_obj);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 1] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 1]
             <= b_obj);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 2] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 2]
             <= b_obj);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 3] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 3]
             <= b_obj);
        }
      }
    }
  } else {
    st.site = &m_emlrtRSI;
    binary_expand_op_8(&st, r5, vehicle_corner, nx, NoEntryZone4, obj);
    remove_sample_data = r5->data;
  }

  if ((r4->size[1] != r5->size[1]) && ((r4->size[1] != 1) && (r5->size[1] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[1], r5->size[1], &i_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[2] != r5->size[2]) && ((r4->size[2] != 1) && (r5->size[2] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[2], r5->size[2], &h_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[3] != r5->size[3]) && ((r4->size[3] != 1) && (r5->size[3] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[3], r5->size[3], &g_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (vehicle_corner->size[2] < 1) {
    loop_ub = 0;
  } else {
    loop_ub = vehicle_corner->size[2];
  }

  if ((loop_ub != NoEntryZone4->size[2]) && ((loop_ub != 1) &&
       (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, NoEntryZone4->size[2], &m_emlrtECI,
      (emlrtConstCTX)sp);
  }

  b_loop_ub = vehicle_corner->size[3];
  if ((vehicle_corner->size[3] != NoEntryZone4->size[3]) &&
      ((vehicle_corner->size[3] != 1) && (NoEntryZone4->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(vehicle_corner->size[3], NoEntryZone4->size[3],
      &l_emlrtECI, (emlrtConstCTX)sp);
  }

  if ((r4->size[1] == r5->size[1]) && (r4->size[2] == r5->size[2]) && (r4->size
       [3] == r5->size[3])) {
    c_loop_ub_tmp = (r4->size[1] << 2) * r4->size[2] * r4->size[3];
    i = r4->size[0] * r4->size[1] * r4->size[2] * r4->size[3];
    r4->size[0] = 4;
    emxEnsureCapacity_boolean_T(sp, r4, i, &bc_emlrtRTEI);
    r6 = r4->data;
    for (i = 0; i < c_loop_ub_tmp; i++) {
      r6[i] = (r6[i] && remove_sample_data[i]);
    }
  } else {
    st.site = &m_emlrtRSI;
    b_and(&st, r4, r5);
  }

  if ((loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] ==
       NoEntryZone4->size[3])) {
    i = r5->size[0] * r5->size[1] * r5->size[2] * r5->size[3];
    r5->size[0] = 4;
    nx = NoEntryZone4->size[1];
    r5->size[1] = NoEntryZone4->size[1];
    r5->size[2] = loop_ub;
    r5->size[3] = vehicle_corner->size[3];
    emxEnsureCapacity_boolean_T(sp, r5, i, &dc_emlrtRTEI);
    remove_sample_data = r5->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < nx; c_loop_ub_tmp++) {
          b_obj = NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->
            size[1] * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] *
            i) + 2] - obj->wall_threshold;
          remove_sample_data[(4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
            r5->size[1] * r5->size[2] * i] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 4] >= b_obj);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 1] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 5]
             >= b_obj);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 2] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 6]
             >= b_obj);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 3] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 7]
             >= b_obj);
        }
      }
    }
  } else {
    st.site = &yg_emlrtRSI;
    binary_expand_op_7(&st, r5, vehicle_corner, loop_ub, NoEntryZone4, obj);
    remove_sample_data = r5->data;
  }

  if ((r4->size[1] != r5->size[1]) && ((r4->size[1] != 1) && (r5->size[1] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[1], r5->size[1], &i_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[2] != r5->size[2]) && ((r4->size[2] != 1) && (r5->size[2] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[2], r5->size[2], &h_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[3] != r5->size[3]) && ((r4->size[3] != 1) && (r5->size[3] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[3], r5->size[3], &g_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (vehicle_corner->size[2] < 1) {
    loop_ub = 0;
  } else {
    loop_ub = vehicle_corner->size[2];
  }

  if ((loop_ub != NoEntryZone4->size[2]) && ((loop_ub != 1) &&
       (NoEntryZone4->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, NoEntryZone4->size[2], &k_emlrtECI,
      (emlrtConstCTX)sp);
  }

  b_loop_ub = vehicle_corner->size[3];
  if ((vehicle_corner->size[3] != NoEntryZone4->size[3]) &&
      ((vehicle_corner->size[3] != 1) && (NoEntryZone4->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(vehicle_corner->size[3], NoEntryZone4->size[3],
      &j_emlrtECI, (emlrtConstCTX)sp);
  }

  if ((r4->size[1] == r5->size[1]) && (r4->size[2] == r5->size[2]) && (r4->size
       [3] == r5->size[3])) {
    c_loop_ub_tmp = (r4->size[1] << 2) * r4->size[2] * r4->size[3];
    i = r4->size[0] * r4->size[1] * r4->size[2] * r4->size[3];
    r4->size[0] = 4;
    emxEnsureCapacity_boolean_T(sp, r4, i, &bc_emlrtRTEI);
    r6 = r4->data;
    for (i = 0; i < c_loop_ub_tmp; i++) {
      r6[i] = (r6[i] && remove_sample_data[i]);
    }
  } else {
    st.site = &m_emlrtRSI;
    b_and(&st, r4, r5);
    r6 = r4->data;
  }

  if ((loop_ub == NoEntryZone4->size[2]) && (vehicle_corner->size[3] ==
       NoEntryZone4->size[3])) {
    i = r5->size[0] * r5->size[1] * r5->size[2] * r5->size[3];
    r5->size[0] = 4;
    nx = NoEntryZone4->size[1];
    r5->size[1] = NoEntryZone4->size[1];
    r5->size[2] = loop_ub;
    r5->size[3] = vehicle_corner->size[3];
    emxEnsureCapacity_boolean_T(sp, r5, i, &ec_emlrtRTEI);
    remove_sample_data = r5->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < nx; c_loop_ub_tmp++) {
          b_obj = NoEntryZone4_data[((4 * c_loop_ub_tmp + 4 * NoEntryZone4->
            size[1] * i1) + 4 * NoEntryZone4->size[1] * NoEntryZone4->size[2] *
            i) + 3] + obj->wall_threshold;
          remove_sample_data[(4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
            r5->size[1] * r5->size[2] * i] = (vehicle_corner_data[(8 * i1 + 8 *
            vehicle_corner->size[2] * i) + 4] <= b_obj);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 1] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 5]
             <= b_obj);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 2] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 6]
             <= b_obj);
          remove_sample_data[((4 * c_loop_ub_tmp + 4 * r5->size[1] * i1) + 4 *
                              r5->size[1] * r5->size[2] * i) + 3] =
            (vehicle_corner_data[(8 * i1 + 8 * vehicle_corner->size[2] * i) + 7]
             <= b_obj);
        }
      }
    }
  } else {
    st.site = &yg_emlrtRSI;
    binary_expand_op_6(&st, r5, vehicle_corner, loop_ub, NoEntryZone4, obj);
    remove_sample_data = r5->data;
  }

  emxFree_real_T(sp, &NoEntryZone4);
  emxFree_real_T(sp, &vehicle_corner);
  if ((r4->size[1] != r5->size[1]) && ((r4->size[1] != 1) && (r5->size[1] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[1], r5->size[1], &i_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[2] != r5->size[2]) && ((r4->size[2] != 1) && (r5->size[2] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[2], r5->size[2], &h_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((r4->size[3] != r5->size[3]) && ((r4->size[3] != 1) && (r5->size[3] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(r4->size[3], r5->size[3], &g_emlrtECI,
      (emlrtConstCTX)sp);
  }

  emxInit_boolean_T(sp, &wall_near, 4, &ad_emlrtRTEI);
  if ((r4->size[1] == r5->size[1]) && (r4->size[2] == r5->size[2]) && (r4->size
       [3] == r5->size[3])) {
    i = r8->size[0] * r8->size[1] * r8->size[2] * r8->size[3];
    r8->size[0] = 4;
    r8->size[1] = r4->size[1];
    r8->size[2] = r4->size[2];
    r8->size[3] = r4->size[3];
    emxEnsureCapacity_boolean_T(sp, r8, i, &bc_emlrtRTEI);
    r9 = r8->data;
    c_loop_ub_tmp = (r4->size[1] << 2) * r4->size[2] * r4->size[3];
    for (i = 0; i < c_loop_ub_tmp; i++) {
      r9[i] = (r6[i] && remove_sample_data[i]);
    }

    st.site = &m_emlrtRSI;
    b_any(&st, r8, wall_near);
  } else {
    st.site = &m_emlrtRSI;
    binary_expand_op_5(&st, wall_near, m_emlrtRSI, r4, r5);
  }

  emxFree_boolean_T(sp, &r8);
  emxFree_boolean_T(sp, &r5);
  emxFree_boolean_T(sp, &r4);
  emlrtMEXProfilingStatement(21, isMexOutdated);
  st.site = &n_emlrtRSI;
  b_st.site = &ac_emlrtRSI;
  emxInit_int32_T(&b_st, &nz, 4, &gd_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  combineVectorElements(&c_st, wall_near, nz);
  nz_data = nz->data;
  emxFree_boolean_T(&b_st, &wall_near);
  emxInit_real_T(&st, &wall_near_sum, 4, &fc_emlrtRTEI);
  i = wall_near_sum->size[0] * wall_near_sum->size[1] * wall_near_sum->size[2] *
    wall_near_sum->size[3];
  wall_near_sum->size[0] = 1;
  wall_near_sum->size[1] = 1;
  wall_near_sum->size[2] = 1;
  loop_ub = nz->size[3];
  wall_near_sum->size[3] = nz->size[3];
  emxEnsureCapacity_real_T(&st, wall_near_sum, i, &fc_emlrtRTEI);
  wall_near_sum_data = wall_near_sum->data;
  for (i = 0; i < loop_ub; i++) {
    wall_near_sum_data[i] = nz_data[i];
  }

  emlrtMEXProfilingStatement(22, isMexOutdated);
  emxInit_real_T(sp, &WALLcost, 2, &gc_emlrtRTEI);
  i = WALLcost->size[0] * WALLcost->size[1];
  WALLcost->size[0] = 1;
  WALLcost->size[1] = nz->size[3];
  emxFree_int32_T(sp, &nz);
  emxEnsureCapacity_real_T(sp, WALLcost, i, &gc_emlrtRTEI);
  WALLcost_data = WALLcost->data;
  n = (wall_near_sum->size[3] / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&wall_near_sum_data[i]);
    _mm_storeu_pd(&WALLcost_data[i], _mm_mul_pd(_mm_set1_pd(obj->wall_penalty1),
      r2));
  }

  for (i = n; i < loop_ub; i++) {
    WALLcost_data[i] = obj->wall_penalty1 * wall_near_sum_data[i];
  }

  /*     %% FPM cost */
  emlrtMEXProfilingStatement(23, isMexOutdated);
  st.site = &o_emlrtRSI;
  b_pagetranspose(&st, preobs_data, preobs_size, preobs2_data, tmp_size);
  emlrtMEXProfilingStatement(24, isMexOutdated);
  dv[0] = 2.0;
  dv[1] = 1.0;
  dv[2] = obj->K;
  dv[3] = obj->NP;
  st.site = &p_emlrtRSI;
  nx = 42 * obj->target->size[2];
  b_st.site = &fc_emlrtRSI;
  b_assertValidSizeArg(&b_st, dv);
  d_obj[0] = 2;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  num2cell_vector(d_obj, sz);
  n = 21;
  if (obj->target->size[2] > 21) {
    n = obj->target->size[2];
  }

  n = muIntScalarMax_sint32(nx, n);
  if (sz[2] > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (sz[3] > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = (sz[2] >= 0);
  if ((!out) || (sz[3] < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if ((sz[2] << 1) * sz[3] != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  f_obj = *obj->target;
  h_obj[0] = 2;
  h_obj[1] = 1;
  h_obj[2] = (int32_T)obj->K;
  h_obj[3] = (int32_T)obj->NP;
  f_obj.size = &h_obj[0];
  f_obj.numDimensions = 4;
  emxInit_real_T(sp, &target2, 4, &bd_emlrtRTEI);
  st.site = &p_emlrtRSI;
  c_pagetranspose(&st, &f_obj, target2);
  emlrtMEXProfilingStatement(25, isMexOutdated);
  dv[0] = 3.0;
  dv[1] = 1.0;
  dv[2] = obj->K;
  dv[3] = obj->NP;
  st.site = &q_emlrtRSI;
  nx = 63 * px->size[2];
  b_st.site = &fc_emlrtRSI;
  b_assertValidSizeArg(&b_st, dv);
  d_obj[0] = 3;
  d_obj[1] = 1;
  d_obj[2] = (int32_T)obj->K;
  d_obj[3] = (int32_T)obj->NP;
  b_num2cell_vector(d_obj, sz);
  n = 21;
  if (px->size[2] > 21) {
    n = px->size[2];
  }

  n = muIntScalarMax_sint32(nx, n);
  if (sz[2] > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (sz[3] > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = (sz[2] >= 0);
  if ((!out) || (sz[3] < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (3 * sz[2] * sz[3] != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  /*  [grade] = FPM_capsule_v3_2vec(obj,px2(1,:,2:obj.K,:),px2(2,:,2:obj.K,:),px2(3,:,2:obj.K,:),preobs2(:,:,1:obj.K-1),target2(:,:,2:obj.K,:),param_FPM); */
  emlrtMEXProfilingStatement(26, isMexOutdated);
  if (obj->K < 2.0) {
    i = 0;
    i1 = 0;
    c_loop_ub_tmp = 0;
    scalarLB_tmp = 0;
    nx = 0;
    n = 0;
    loop_ub = 0;
  } else {
    if ((int32_T)obj->K < 2) {
      emlrtDynamicBoundsCheckR2012b(2, 1, (int32_T)obj->K, &j_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    i = 1;
    if (obj->K != (int32_T)d) {
      emlrtIntegerCheckR2012b(obj->K, &j_emlrtDCI, (emlrtConstCTX)sp);
    }

    i1 = (int32_T)obj->K;
    c_loop_ub_tmp = 1;
    if ((int32_T)obj->K != (int32_T)d) {
      emlrtIntegerCheckR2012b(obj->K, &i_emlrtDCI, (emlrtConstCTX)sp);
    }

    scalarLB_tmp = (int32_T)obj->K;
    nx = 1;
    if ((int32_T)obj->K != (int32_T)d) {
      emlrtIntegerCheckR2012b(obj->K, &h_emlrtDCI, (emlrtConstCTX)sp);
    }

    n = (int32_T)obj->K;
    if (obj->K - 1.0 > 21.0) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(obj->K - 1.0), 1, 21, &i_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    loop_ub = (int32_T)(obj->K - 1.0);
    if (target2->size[2] < 2) {
      emlrtDynamicBoundsCheckR2012b(2, 1, target2->size[2], &h_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (obj->K != d) {
      emlrtIntegerCheckR2012b(obj->K, &g_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj->K > target2->size[2]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj->K, 1, target2->size[2],
        &g_emlrtBCI, (emlrtConstCTX)sp);
    }
  }

  emxInit_real_T(sp, &d_px, 4, &hc_emlrtRTEI);
  vectorUB = d_px->size[0] * d_px->size[1] * d_px->size[2] * d_px->size[3];
  d_px->size[0] = 1;
  d_px->size[1] = 1;
  b_loop_ub = i1 - i;
  d_px->size[2] = b_loop_ub;
  d_px->size[3] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, d_px, vectorUB, &hc_emlrtRTEI);
  B_data = d_px->data;
  for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
    for (vectorUB = 0; vectorUB < b_loop_ub; vectorUB++) {
      B_data[vectorUB + d_px->size[2] * i1] = px_data[3 * (i + vectorUB) + 3 *
        loop_ub_tmp * i1];
    }
  }

  emxInit_real_T(sp, &e_px, 4, &ic_emlrtRTEI);
  i = e_px->size[0] * e_px->size[1] * e_px->size[2] * e_px->size[3];
  e_px->size[0] = 1;
  e_px->size[1] = 1;
  b_loop_ub = scalarLB_tmp - c_loop_ub_tmp;
  e_px->size[2] = b_loop_ub;
  e_px->size[3] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, e_px, i, &ic_emlrtRTEI);
  B_data = e_px->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      B_data[i1 + e_px->size[2] * i] = px_data[(3 * (c_loop_ub_tmp + i1) + 3 *
        loop_ub_tmp * i) + 1];
    }
  }

  emxInit_real_T(sp, &f_px, 4, &jc_emlrtRTEI);
  i = f_px->size[0] * f_px->size[1] * f_px->size[2] * f_px->size[3];
  f_px->size[0] = 1;
  f_px->size[1] = 1;
  b_loop_ub = n - nx;
  f_px->size[2] = b_loop_ub;
  f_px->size[3] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, f_px, i, &jc_emlrtRTEI);
  B_data = f_px->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      B_data[i1 + f_px->size[2] * i] = px_data[(3 * (nx + i1) + 3 * loop_ub_tmp *
        i) + 2];
    }
  }

  b_loop_ub = tmp_size[0];
  tmp_size[1] = 6;
  tmp_size[2] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      for (c_loop_ub_tmp = 0; c_loop_ub_tmp < b_loop_ub; c_loop_ub_tmp++) {
        b_preobs2_data[(c_loop_ub_tmp + tmp_size[0] * i1) + tmp_size[0] * 6 * i]
          = preobs2_data[(c_loop_ub_tmp + tmp_size[0] * i1) + tmp_size[0] * 6 *
          i];
      }
    }
  }

  emxInit_real_T(sp, &grade, 4, &cd_emlrtRTEI);
  st.site = &r_emlrtRSI;
  FPM_capsule_v3_3vec(&st, obj->K, obj->NP, obj->ObsNum, obj->wheel_width,
                      obj->wheel_len_front, obj->target_n, obj->th_target_w.data,
                      obj->th_target_w.size[0], d_px, e_px, f_px, b_preobs2_data,
                      tmp_size, param_FPM->eta, param_FPM->alpha,
                      param_FPM->margin, grade);
  emxFree_real_T(sp, &f_px);
  emxFree_real_T(sp, &e_px);
  emxFree_real_T(sp, &d_px);
  emlrtMEXProfilingStatement(27, isMexOutdated);
  st.site = &s_emlrtRSI;
  sum(&st, grade, wall_near_sum);
  i = wall_near_sum->size[0] * wall_near_sum->size[1] * wall_near_sum->size[2] *
    wall_near_sum->size[3];
  wall_near_sum->size[0] = 1;
  wall_near_sum->size[1] = 1;
  wall_near_sum->size[2] = 1;
  emxEnsureCapacity_real_T(sp, wall_near_sum, i, &kc_emlrtRTEI);
  wall_near_sum_data = wall_near_sum->data;
  b_obj = obj->K - 1.0;
  loop_ub = wall_near_sum->size[3] - 1;
  n = (wall_near_sum->size[3] / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&wall_near_sum_data[i]);
    _mm_storeu_pd(&wall_near_sum_data[i], _mm_sub_pd(_mm_set1_pd(b_obj), r2));
  }

  for (i = n; i <= loop_ub; i++) {
    wall_near_sum_data[i] = b_obj - wall_near_sum_data[i];
  }

  st.site = &s_emlrtRSI;
  nx_tmp = wall_near_sum->size[3];
  b_st.site = &cb_emlrtRSI;
  n = 1;
  if (wall_near_sum->size[3] > 1) {
    n = wall_near_sum->size[3];
  }

  if (wall_near_sum->size[3] > muIntScalarMax_sint32(nx_tmp, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  /*     %% Velocity cost */
  emlrtMEXProfilingStatement(31, isMexOutdated);
  emxInit_real_T(sp, &y, 3, &hd_emlrtRTEI);
  i = y->size[0] * y->size[1] * y->size[2];
  y->size[0] = 1;
  y->size[1] = 1;
  loop_ub = pu->size[2];
  y->size[2] = pu->size[2];
  emxEnsureCapacity_real_T(sp, y, i, &lc_emlrtRTEI);
  vehicle_corner_data = y->data;
  tmp_size[0] = 1;
  tmp_size[1] = 1;
  tmp_size[2] = pu->size[2];
  for (i = 0; i < loop_ub; i++) {
    d = pu_data[42 * i];
    vehicle_corner_data[i] = (d - 0.55) * 5000.0;
    tmp_data[i] = (d > 0.55);
  }

  if (y->size[2] != tmp_size[2]) {
    emlrtSizeEqCheckNDErrorR2021b(&y->size[0], &tmp_size[0], &e_emlrtECI,
      (emlrtCTX)sp);
  }

  emxInit_real_T(sp, &b_y, 3, &id_emlrtRTEI);
  i = b_y->size[0] * b_y->size[1] * b_y->size[2];
  b_y->size[0] = 1;
  b_y->size[1] = 1;
  b_y->size[2] = pu->size[2];
  emxEnsureCapacity_real_T(sp, b_y, i, &lc_emlrtRTEI);
  NoEntryZone4_data = b_y->data;
  tmp_size[0] = 1;
  tmp_size[1] = 1;
  tmp_size[2] = pu->size[2];
  for (i = 0; i < loop_ub; i++) {
    d = pu_data[42 * i];
    NoEntryZone4_data[i] = (d - -0.25) * -5000.0;
    b_tmp_data[i] = (d < -0.25);
  }

  if (b_y->size[2] != tmp_size[2]) {
    emlrtSizeEqCheckNDErrorR2021b(&b_y->size[0], &tmp_size[0], &f_emlrtECI,
      (emlrtCTX)sp);
  }

  tmp_size[0] = 1;
  tmp_size[1] = 1;
  tmp_size[2] = pu->size[2];
  b_tmp_size[0] = 1;
  b_tmp_size[1] = 1;
  b_tmp_size[2] = pu->size[2];
  for (i = 0; i < loop_ub; i++) {
    c_tmp_data[i] = vehicle_corner_data[i] * (real_T)tmp_data[i];
    d_tmp_data[i] = NoEntryZone4_data[i] * (real_T)b_tmp_data[i];
  }

  if (tmp_size[2] == b_tmp_size[2]) {
    b_loop_ub = tmp_size[2] - 1;
    tmp_size[0] = 1;
    tmp_size[1] = 1;
    n = (tmp_size[2] / 2) << 1;
    vectorUB = n - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&c_tmp_data[i]);
      r3 = _mm_loadu_pd(&d_tmp_data[i]);
      _mm_storeu_pd(&c_tmp_data[i], _mm_add_pd(r2, r3));
    }

    for (i = n; i <= b_loop_ub; i++) {
      c_tmp_data[i] += d_tmp_data[i];
    }
  } else {
    b_plus(c_tmp_data, tmp_size, d_tmp_data, b_tmp_size);
  }

  st.site = &t_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  n = 1;
  if (tmp_size[2] > 1) {
    n = tmp_size[2];
  }

  if (tmp_size[2] > muIntScalarMax_sint32(tmp_size[2], n)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  /*     %% Input cost */
  emlrtMEXProfilingStatement(32, isMexOutdated);
  if (obj->K - 1.0 < 1.0) {
    b_loop_ub = 0;
  } else {
    if (obj->K - 1.0 != muDoubleScalarFloor(obj->K - 1.0)) {
      emlrtIntegerCheckR2012b(obj->K - 1.0, &f_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)(obj->K - 1.0) < 1) || ((int32_T)(obj->K - 1.0) > 21)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(obj->K - 1.0), 1, 21, &f_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    b_loop_ub = (int32_T)(obj->K - 1.0);
  }

  c_obj[0] = b_loop_ub;
  c_obj[1] = obj->target_n->size[1];
  st.site = &u_emlrtRSI;
  indexShapeCheck(&st, obj->V_ref.size[0], c_obj);
  for (i = 0; i < obj_tmp; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      c_loop_ub_tmp = i1 + 21 * i;
      if (obj->target_n->data[c_loop_ub_tmp] != (int32_T)muDoubleScalarFloor
          (obj->target_n->data[c_loop_ub_tmp])) {
        emlrtIntegerCheckR2012b(obj->target_n->data[i1 + 21 * i], &c_emlrtDCI,
          (emlrtConstCTX)sp);
      }

      c_loop_ub_tmp = (int32_T)obj->target_n->data[c_loop_ub_tmp];
      if ((c_loop_ub_tmp < 1) || (c_loop_ub_tmp > obj->V_ref.size[0])) {
        emlrtDynamicBoundsCheckR2012b(c_loop_ub_tmp, 1, obj->V_ref.size[0],
          &c_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
  }

  st.site = &u_emlrtRSI;
  nx = b_loop_ub * obj->target_n->size[1];
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K - 1.0);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = b_loop_ub;
  if (obj->target_n->size[1] > b_loop_ub) {
    n = obj->target_n->size[1];
  }

  n = muIntScalarMax_sint32(nx, n);
  if (n < 1) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)(obj->K - 1.0) > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)(obj->K - 1.0) >= 0);
  if ((!out) || ((int32_T)obj->NP < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if ((int32_T)(obj->K - 1.0) * (int32_T)obj->NP != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  /*  それぞれのポイントごとに目標速度を決定 */
  /*  Vref =obj.V_ref(obj.target_n(1,1));     % すべて同じ目標速度 */
  emlrtMEXProfilingStatement(33, isMexOutdated);
  if (((int32_T)(obj->K - 1.0) != 20) && ((int32_T)(obj->K - 1.0) != 1)) {
    emlrtDimSizeImpxCheckR2021b(20, (int32_T)(obj->K - 1.0), &d_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if ((pu->size[2] != (int32_T)obj->NP) && ((pu->size[2] != 1) && ((int32_T)
        obj->NP != 1))) {
    emlrtDimSizeImpxCheckR2021b(pu->size[2], (int32_T)obj->NP, &c_emlrtECI,
      (emlrtConstCTX)sp);
  }

  emxInit_real_T(sp, &r10, 3, &mc_emlrtRTEI);
  i = r10->size[0] * r10->size[1] * r10->size[2];
  r10->size[0] = 1;
  r10->size[1] = 20;
  r10->size[2] = pu->size[2];
  emxEnsureCapacity_real_T(sp, r10, i, &mc_emlrtRTEI);
  r1 = r10->data;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      b_obj = pu_data[(2 * i1 + 42 * i) + 1];
      r1[i1 + 20 * i] = b_obj * b_obj;
    }
  }

  st.site = &v_emlrtRSI;
  b_sum(&st, r10, y);
  i = y->size[0] * y->size[1] * y->size[2];
  y->size[0] = 1;
  y->size[1] = 1;
  emxEnsureCapacity_real_T(sp, y, i, &lc_emlrtRTEI);
  vehicle_corner_data = y->data;
  b_obj = obj->R[1];
  nx = y->size[2] - 1;
  n = (y->size[2] / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&vehicle_corner_data[i]);
    _mm_storeu_pd(&vehicle_corner_data[i], _mm_mul_pd(r2, _mm_set1_pd(b_obj)));
  }

  for (i = n; i <= nx; i++) {
    vehicle_corner_data[i] *= b_obj;
  }

  if (((int32_T)(obj->K - 1.0) == 20) && (pu->size[2] == (int32_T)obj->NP)) {
    i = B->size[0] * B->size[1];
    B->size[0] = b_loop_ub;
    B->size[1] = obj->target_n->size[1];
    emxEnsureCapacity_real_T(sp, B, i, &nc_emlrtRTEI);
    B_data = B->data;
    for (i = 0; i < obj_tmp; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        B_data[i1 + B->size[0] * i] = obj->V_ref.data[(int32_T)obj->
          target_n->data[i1 + 21 * i] - 1];
      }
    }

    i = r10->size[0] * r10->size[1] * r10->size[2];
    r10->size[0] = 1;
    r10->size[1] = 20;
    r10->size[2] = pu->size[2];
    emxEnsureCapacity_real_T(sp, r10, i, &mc_emlrtRTEI);
    r1 = r10->data;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < 20; i1++) {
        b_obj = pu_data[2 * i1 + 42 * i] - B_data[i1 + (int32_T)(obj->K - 1.0) *
          i];
        r1[i1 + 20 * i] = b_obj * b_obj;
      }
    }

    st.site = &v_emlrtRSI;
    b_sum(&st, r10, b_y);
  } else {
    st.site = &v_emlrtRSI;
    binary_expand_op_4(&st, b_y, v_emlrtRSI, pu, obj, b_loop_ub);
  }

  emxFree_real_T(sp, &r10);
  emxFree_real_T(sp, &B);
  i = b_y->size[0] * b_y->size[1] * b_y->size[2];
  b_y->size[0] = 1;
  b_y->size[1] = 1;
  emxEnsureCapacity_real_T(sp, b_y, i, &oc_emlrtRTEI);
  NoEntryZone4_data = b_y->data;
  b_obj = obj->R[0];
  loop_ub = b_y->size[2] - 1;
  n = (b_y->size[2] / 2) << 1;
  vectorUB = n - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r2 = _mm_loadu_pd(&NoEntryZone4_data[i]);
    _mm_storeu_pd(&NoEntryZone4_data[i], _mm_mul_pd(r2, _mm_set1_pd(b_obj)));
  }

  for (i = n; i <= loop_ub; i++) {
    NoEntryZone4_data[i] *= b_obj;
  }

  if ((y->size[2] != b_y->size[2]) && ((y->size[2] != 1) && (b_y->size[2] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(y->size[2], b_y->size[2], &b_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (y->size[2] == b_y->size[2]) {
    loop_ub = y->size[2] - 1;
    i = y->size[0] * y->size[1] * y->size[2];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(sp, y, i, &pc_emlrtRTEI);
    vehicle_corner_data = y->data;
    n = (y->size[2] / 2) << 1;
    vectorUB = n - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&vehicle_corner_data[i]);
      r3 = _mm_loadu_pd(&NoEntryZone4_data[i]);
      _mm_storeu_pd(&vehicle_corner_data[i], _mm_add_pd(r2, r3));
    }

    for (i = n; i <= loop_ub; i++) {
      vehicle_corner_data[i] += NoEntryZone4_data[i];
    }
  } else {
    st.site = &v_emlrtRSI;
    binary_expand_op_3(&st, y, b_y);
    vehicle_corner_data = y->data;
  }

  emxFree_real_T(sp, &b_y);
  dv1[0] = 1.0;
  dv1[1] = obj->NP;
  st.site = &v_emlrtRSI;
  nx = y->size[2];
  b_st.site = &fc_emlrtRSI;
  c_assertValidSizeArg(&b_st, dv1);
  n = 1;
  if (y->size[2] > 1) {
    n = y->size[2];
  }

  if ((int32_T)obj->NP > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if ((int32_T)obj->NP != y->size[2]) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  /*     %% Distance cost */
  emlrtMEXProfilingStatement(35, isMexOutdated);
  emxInit_int32_T(sp, &i_obj, 2, &qc_emlrtRTEI);
  i = i_obj->size[0] * i_obj->size[1];
  i_obj->size[0] = 21;
  i_obj->size[1] = obj->target_n->size[1];
  emxEnsureCapacity_int32_T(sp, i_obj, i, &qc_emlrtRTEI);
  nz_data = i_obj->data;
  c_loop_ub_tmp = 21 * obj->target_n->size[1];
  for (i = 0; i < c_loop_ub_tmp; i++) {
    d = obj->target_n->data[i] - 1.0;
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &b_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > obj->waypoint.size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, obj->waypoint.size[0],
        &b_emlrtBCI, (emlrtConstCTX)sp);
    }

    nz_data[i] = (int32_T)d;
  }

  emxInit_real_T(sp, &r11, 2, &ed_emlrtRTEI);
  i = r11->size[0] * r11->size[1];
  r11->size[0] = 2;
  r11->size[1] = c_loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, r11, i, &rc_emlrtRTEI);
  r1 = r11->data;
  for (i = 0; i < c_loop_ub_tmp; i++) {
    r1[2 * i] = obj->waypoint.data[nz_data[i] - 1];
    r1[2 * i + 1] = obj->waypoint.data[(nz_data[i] + obj->waypoint.size[0]) - 1];
  }

  st.site = &w_emlrtRSI;
  scalarLB_tmp = r11->size[1] << 1;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 2;
  if (r11->size[1] > 2) {
    n = c_loop_ub_tmp;
  }

  n = muIntScalarMax_sint32(scalarLB_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->NP >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  i = ((int32_T)obj->K << 1) * (int32_T)obj->NP;
  if (i != scalarLB_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emlrtMEXProfilingStatement(36, isMexOutdated);
  i1 = i_obj->size[0] * i_obj->size[1];
  i_obj->size[0] = 21;
  i_obj->size[1] = obj->target_n->size[1];
  emxEnsureCapacity_int32_T(sp, i_obj, i1, &sc_emlrtRTEI);
  nz_data = i_obj->data;
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    d = obj->target_n->data[i1];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)d < 1) || ((int32_T)d > obj->waypoint.size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, obj->waypoint.size[0],
        &emlrtBCI, (emlrtConstCTX)sp);
    }

    nz_data[i1] = (int32_T)d;
  }

  emxInit_real_T(sp, &r12, 2, &fd_emlrtRTEI);
  i1 = r12->size[0] * r12->size[1];
  r12->size[0] = 2;
  r12->size[1] = c_loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, r12, i1, &tc_emlrtRTEI);
  r1 = r12->data;
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    r1[2 * i1] = obj->waypoint.data[nz_data[i1] - 1];
    r1[2 * i1 + 1] = obj->waypoint.data[(nz_data[i1] + obj->waypoint.size[0]) -
      1];
  }

  emxFree_int32_T(sp, &i_obj);
  st.site = &x_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->K);
  c_st.site = &db_emlrtRSI;
  assertValidSizeArg(&c_st, obj->NP);
  n = 2;
  if (r12->size[1] > 2) {
    n = c_loop_ub_tmp;
  }

  n = muIntScalarMax_sint32(scalarLB_tmp, n);
  if ((int32_T)obj->K > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if ((int32_T)obj->NP > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = ((int32_T)obj->NP >= 0);
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (i != scalarLB_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emlrtMEXProfilingStatement(37, isMexOutdated);
  emxInit_real_T(sp, &g_px, 4, &uc_emlrtRTEI);
  i = g_px->size[0] * g_px->size[1] * g_px->size[2] * g_px->size[3];
  g_px->size[0] = 2;
  g_px->size[1] = 1;
  g_px->size[2] = (int32_T)obj->K;
  g_px->size[3] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, g_px, i, &uc_emlrtRTEI);
  B_data = g_px->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      c_loop_ub_tmp = 3 * i1 + 3 * (int32_T)obj->K * i;
      B_data[2 * i1 + 2 * g_px->size[2] * i] = px_data[c_loop_ub_tmp];
      B_data[(2 * i1 + 2 * g_px->size[2] * i) + 1] = px_data[c_loop_ub_tmp + 1];
    }
  }

  st.site = &y_emlrtRSI;
  c_pagetranspose(&st, g_px, target2);
  emxFree_real_T(sp, &g_px);
  emlrtMEXProfilingStatement(38, isMexOutdated);
  f_obj = *r11;
  j_obj[0] = 1;
  j_obj[1] = 2;
  j_obj[2] = (int32_T)obj->K;
  j_obj[3] = (int32_T)obj->NP;
  f_obj.size = &j_obj[0];
  f_obj.numDimensions = 4;
  r13 = *r12;
  b_iv[0] = 1;
  b_iv[1] = 2;
  b_iv[2] = (int32_T)obj->K;
  b_iv[3] = (int32_T)obj->NP;
  r13.size = &b_iv[0];
  r13.numDimensions = 4;
  st.site = &ab_emlrtRSI;
  get_distance(&st, &f_obj, &r13, target2, grade);
  emxFree_real_T(sp, &r12);
  emxFree_real_T(sp, &r11);
  emxFree_real_T(sp, &target2);
  emlrtMEXProfilingStatement(39, isMexOutdated);
  emxInit_real_T(sp, &r14, 4, &vc_emlrtRTEI);
  st.site = &bb_emlrtRSI;
  sum(&st, grade, r14);
  emxFree_real_T(sp, &grade);
  loop_ub = r14->size[3] - 1;
  i = r14->size[0] * r14->size[1] * r14->size[2] * r14->size[3];
  r14->size[0] = 1;
  r14->size[1] = 1;
  r14->size[2] = 1;
  i1 = r14->size[3];
  emxEnsureCapacity_real_T(sp, r14, i, &vc_emlrtRTEI);
  r1 = r14->data;
  for (i = 0; i <= loop_ub; i++) {
    r1[i] *= 0.15;
  }

  st.site = &bb_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  n = 1;
  if (r14->size[3] > 1) {
    n = r14->size[3];
  }

  if (r14->size[3] > muIntScalarMax_sint32(i1, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  /*     %% Cost SUM */
  /*  pw = FPMcost + Inputcost + Vcost + WALLcost; */
  emlrtMEXProfilingStatement(40, isMexOutdated);
  if ((wall_near_sum->size[3] != (int32_T)obj->NP) && ((wall_near_sum->size[3]
        != 1) && ((int32_T)obj->NP != 1))) {
    emlrtDimSizeImpxCheckR2021b(wall_near_sum->size[3], (int32_T)obj->NP,
      &emlrtECI, (emlrtConstCTX)sp);
  }

  if (wall_near_sum->size[3] == (int32_T)obj->NP) {
    i = pw->size[0] * pw->size[1];
    pw->size[0] = 1;
    pw->size[1] = wall_near_sum->size[3];
    emxEnsureCapacity_real_T(sp, pw, i, &wc_emlrtRTEI);
    NoEntryZone4_data = pw->data;
    n = (wall_near_sum->size[3] / 2) << 1;
    vectorUB = n - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&wall_near_sum_data[i]);
      r3 = _mm_loadu_pd(&vehicle_corner_data[i]);
      _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
    }

    for (i = n; i < nx_tmp; i++) {
      NoEntryZone4_data[i] = wall_near_sum_data[i] + vehicle_corner_data[i];
    }
  } else {
    st.site = &gg_emlrtRSI;
    binary_expand_op_2(&st, pw, wall_near_sum, y, dv1);
  }

  emxFree_real_T(sp, &y);
  emxFree_real_T(sp, &wall_near_sum);
  if ((pw->size[1] != tmp_size[2]) && ((pw->size[1] != 1) && (tmp_size[2] != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(pw->size[1], tmp_size[2], &emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (pw->size[1] == tmp_size[2]) {
    loop_ub = pw->size[1] - 1;
    i = pw->size[0] * pw->size[1];
    pw->size[0] = 1;
    emxEnsureCapacity_real_T(sp, pw, i, &wc_emlrtRTEI);
    NoEntryZone4_data = pw->data;
    n = (pw->size[1] / 2) << 1;
    vectorUB = n - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&NoEntryZone4_data[i]);
      r3 = _mm_loadu_pd(&c_tmp_data[i]);
      _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
    }

    for (i = n; i <= loop_ub; i++) {
      NoEntryZone4_data[i] += c_tmp_data[i];
    }
  } else {
    st.site = &gg_emlrtRSI;
    binary_expand_op_1(&st, pw, c_tmp_data, tmp_size);
  }

  if ((pw->size[1] != WALLcost->size[1]) && ((pw->size[1] != 1) &&
       (WALLcost->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(pw->size[1], WALLcost->size[1], &emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (pw->size[1] == WALLcost->size[1]) {
    loop_ub = pw->size[1] - 1;
    i = pw->size[0] * pw->size[1];
    pw->size[0] = 1;
    emxEnsureCapacity_real_T(sp, pw, i, &wc_emlrtRTEI);
    NoEntryZone4_data = pw->data;
    n = (pw->size[1] / 2) << 1;
    vectorUB = n - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&NoEntryZone4_data[i]);
      r3 = _mm_loadu_pd(&WALLcost_data[i]);
      _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
    }

    for (i = n; i <= loop_ub; i++) {
      NoEntryZone4_data[i] += WALLcost_data[i];
    }
  } else {
    st.site = &gg_emlrtRSI;
    plus(&st, pw, WALLcost);
  }

  emxFree_real_T(sp, &WALLcost);
  if ((pw->size[1] != i1) && ((pw->size[1] != 1) && (i1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(pw->size[1], i1, &emlrtECI, (emlrtConstCTX)sp);
  }

  if (pw->size[1] == r14->size[3]) {
    loop_ub = pw->size[1] - 1;
    i = pw->size[0] * pw->size[1];
    pw->size[0] = 1;
    emxEnsureCapacity_real_T(sp, pw, i, &xc_emlrtRTEI);
    NoEntryZone4_data = pw->data;
    n = (pw->size[1] / 2) << 1;
    vectorUB = n - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&NoEntryZone4_data[i]);
      r3 = _mm_loadu_pd(&r1[i]);
      _mm_storeu_pd(&NoEntryZone4_data[i], _mm_add_pd(r2, r3));
    }

    for (i = n; i <= loop_ub; i++) {
      NoEntryZone4_data[i] += r1[i];
    }
  } else {
    st.site = &gg_emlrtRSI;
    binary_expand_op(&st, pw, r14);
  }

  emxFree_real_T(sp, &r14);
  emlrtMEXProfilingStatement(41, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (EvaluationPath_vec.c) */
