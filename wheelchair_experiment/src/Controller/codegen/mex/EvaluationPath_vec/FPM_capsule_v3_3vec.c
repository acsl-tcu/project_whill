/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FPM_capsule_v3_3vec.c
 *
 * Code generation for function 'FPM_capsule_v3_3vec'
 *
 */

/* Include files */
#include "FPM_capsule_v3_3vec.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "abs.h"
#include "acos.h"
#include "asin.h"
#include "assertCompatibleDims.h"
#include "assertValidSizeArg.h"
#include "atan2.h"
#include "cos.h"
#include "dot.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "indexShapeCheck.h"
#include "ixfun.h"
#include "norm.h"
#include "pagemtimes.h"
#include "pagetranspose.h"
#include "power.h"
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"
#include "sign.h"
#include "sin.h"
#include "unsafeSxfun.h"
#include "vecnorm.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo gc_emlrtRSI = { 16, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 44, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 46, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 48, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 79, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 80, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 82, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 83, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 85, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 86, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 87, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 90, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 94, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 95, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 100,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 101,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 102,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 104,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 105,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 106,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 107,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 108,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 110,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 111,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 112,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 113,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 114,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 115,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 117,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 118,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 122,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 123,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 129,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 133,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 149,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 43, /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 65, /* lineNo */
  "cat_impl",                          /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 71, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 15, /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 64, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 99, /* lineNo */
  "maximum",                           /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 290,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 395,/* lineNo */
  "unaryMinOrMaxDispatch",             /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 597,/* lineNo */
  "minOrMaxNDFlat",                    /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 603,/* lineNo */
  "minOrMaxNDFlat",                    /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo mf_emlrtRSI = { 607,/* lineNo */
  "minOrMaxNDFlat",                    /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 610,/* lineNo */
  "minOrMaxNDFlat",                    /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 15, /* lineNo */
  "min",                               /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 66, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 112,/* lineNo */
  "minimum",                           /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 51, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 87, /* lineNo */
  "minimum2",                          /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 139,/* lineNo */
  "binaryMinOrMax",                    /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/binaryMinOrMax.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 198,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 225,/* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtECInfo pb_emlrtECI = { 4,  /* nDims */
  136,                                 /* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo qb_emlrtECI = { 3,  /* nDims */
  136,                                 /* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo rb_emlrtECI = { 1,  /* nDims */
  136,                                 /* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo sb_emlrtECI = { 3,  /* nDims */
  133,                                 /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo tb_emlrtECI = { 1,  /* nDims */
  133,                                 /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ub_emlrtECI = { 4,  /* nDims */
  132,                                 /* lineNo */
  16,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo vb_emlrtECI = { 3,  /* nDims */
  132,                                 /* lineNo */
  16,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo wb_emlrtECI = { 1,  /* nDims */
  132,                                 /* lineNo */
  16,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo xb_emlrtECI = { 4,  /* nDims */
  132,                                 /* lineNo */
  35,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo yb_emlrtECI = { 3,  /* nDims */
  132,                                 /* lineNo */
  35,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ac_emlrtECI = { 1,  /* nDims */
  132,                                 /* lineNo */
  35,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo bc_emlrtECI = { 4,  /* nDims */
  128,                                 /* lineNo */
  19,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo cc_emlrtECI = { 3,  /* nDims */
  128,                                 /* lineNo */
  19,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo dc_emlrtECI = { 1,  /* nDims */
  128,                                 /* lineNo */
  19,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ec_emlrtECI = { 4,  /* nDims */
  127,                                 /* lineNo */
  19,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo fc_emlrtECI = { 3,  /* nDims */
  127,                                 /* lineNo */
  19,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo gc_emlrtECI = { 1,  /* nDims */
  127,                                 /* lineNo */
  19,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo hc_emlrtECI = { 4,  /* nDims */
  126,                                 /* lineNo */
  15,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ic_emlrtECI = { 3,  /* nDims */
  126,                                 /* lineNo */
  15,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo jc_emlrtECI = { 1,  /* nDims */
  126,                                 /* lineNo */
  15,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo kc_emlrtECI = { 3,  /* nDims */
  124,                                 /* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo lc_emlrtECI = { 1,  /* nDims */
  124,                                 /* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo mc_emlrtECI = { 3,  /* nDims */
  123,                                 /* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo nc_emlrtECI = { 1,  /* nDims */
  123,                                 /* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo oc_emlrtECI = { 4,  /* nDims */
  118,                                 /* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo pc_emlrtECI = { 3,  /* nDims */
  118,                                 /* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo qc_emlrtECI = { 1,  /* nDims */
  118,                                 /* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo rc_emlrtECI = { 4,  /* nDims */
  117,                                 /* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo sc_emlrtECI = { 3,  /* nDims */
  117,                                 /* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo tc_emlrtECI = { 1,  /* nDims */
  117,                                 /* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo uc_emlrtECI = { 4,  /* nDims */
  115,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo vc_emlrtECI = { 3,  /* nDims */
  115,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo wc_emlrtECI = { 1,  /* nDims */
  115,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo xc_emlrtECI = { 4,  /* nDims */
  114,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo yc_emlrtECI = { 3,  /* nDims */
  114,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ad_emlrtECI = { 1,  /* nDims */
  114,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo bd_emlrtECI = { -1, /* nDims */
  111,                                 /* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo cd_emlrtECI = { -1, /* nDims */
  108,                                 /* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo dd_emlrtECI = { 4,  /* nDims */
  113,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ed_emlrtECI = { 3,  /* nDims */
  113,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo fd_emlrtECI = { 1,  /* nDims */
  113,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo gd_emlrtECI = { 4,  /* nDims */
  112,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo hd_emlrtECI = { 3,  /* nDims */
  112,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo id_emlrtECI = { 1,  /* nDims */
  112,                                 /* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo jd_emlrtECI = { -1, /* nDims */
  110,                                 /* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo kd_emlrtECI = { -1, /* nDims */
  107,                                 /* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ld_emlrtECI = { 4,  /* nDims */
  108,                                 /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo md_emlrtECI = { 3,  /* nDims */
  108,                                 /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo nd_emlrtECI = { 1,  /* nDims */
  108,                                 /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo od_emlrtECI = { -1, /* nDims */
  106,                                 /* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo pd_emlrtECI = { 4,  /* nDims */
  107,                                 /* lineNo */
  30,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo qd_emlrtECI = { 3,  /* nDims */
  107,                                 /* lineNo */
  30,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo rd_emlrtECI = { 1,  /* nDims */
  107,                                 /* lineNo */
  30,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo sd_emlrtECI = { 4,  /* nDims */
  106,                                 /* lineNo */
  66,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo td_emlrtECI = { 3,  /* nDims */
  106,                                 /* lineNo */
  66,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ud_emlrtECI = { 1,  /* nDims */
  106,                                 /* lineNo */
  66,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo vd_emlrtECI = { 3,  /* nDims */
  106,                                 /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo wd_emlrtECI = { 1,  /* nDims */
  106,                                 /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo xd_emlrtECI = { 4,  /* nDims */
  106,                                 /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo yd_emlrtECI = { 4,  /* nDims */
  105,                                 /* lineNo */
  56,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ae_emlrtECI = { 3,  /* nDims */
  105,                                 /* lineNo */
  56,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo be_emlrtECI = { 1,  /* nDims */
  105,                                 /* lineNo */
  56,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ce_emlrtECI = { 3,  /* nDims */
  105,                                 /* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo de_emlrtECI = { 1,  /* nDims */
  105,                                 /* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ee_emlrtECI = { 4,  /* nDims */
  105,                                 /* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo fe_emlrtECI = { 4,  /* nDims */
  104,                                 /* lineNo */
  24,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ge_emlrtECI = { 3,  /* nDims */
  104,                                 /* lineNo */
  24,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo he_emlrtECI = { 1,  /* nDims */
  104,                                 /* lineNo */
  24,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ie_emlrtECI = { 3,  /* nDims */
  102,                                 /* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo je_emlrtECI = { 3,  /* nDims */
  101,                                 /* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ke_emlrtECI = { 3,  /* nDims */
  100,                                 /* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo le_emlrtECI = { 4,  /* nDims */
  99,                                  /* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo me_emlrtECI = { 3,  /* nDims */
  99,                                  /* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ne_emlrtECI = { 1,  /* nDims */
  99,                                  /* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo oe_emlrtECI = { 3,  /* nDims */
  97,                                  /* lineNo */
  15,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo pe_emlrtECI = { 1,  /* nDims */
  97,                                  /* lineNo */
  15,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  48,                                  /* colNo */
  "Q1Q2_2",                            /* aName */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  32,                                  /* colNo */
  "Q1Q2_2",                            /* aName */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo qe_emlrtECI = { 4,  /* nDims */
  93,                                  /* lineNo */
  18,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo re_emlrtECI = { 3,  /* nDims */
  93,                                  /* lineNo */
  18,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo se_emlrtECI = { 2,  /* nDims */
  93,                                  /* lineNo */
  18,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo te_emlrtECI = { 1,  /* nDims */
  93,                                  /* lineNo */
  18,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ue_emlrtECI = { 4,  /* nDims */
  93,                                  /* lineNo */
  25,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ve_emlrtECI = { 3,  /* nDims */
  93,                                  /* lineNo */
  25,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo we_emlrtECI = { 1,  /* nDims */
  93,                                  /* lineNo */
  25,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo xe_emlrtECI = { 4,  /* nDims */
  89,                                  /* lineNo */
  13,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ye_emlrtECI = { 3,  /* nDims */
  89,                                  /* lineNo */
  13,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo af_emlrtECI = { 2,  /* nDims */
  89,                                  /* lineNo */
  13,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo bf_emlrtECI = { 1,  /* nDims */
  89,                                  /* lineNo */
  13,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo cf_emlrtECI = { 3,  /* nDims */
  87,                                  /* lineNo */
  57,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo df_emlrtECI = { 3,  /* nDims */
  86,                                  /* lineNo */
  57,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ef_emlrtECI = { 4,  /* nDims */
  83,                                  /* lineNo */
  49,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo ff_emlrtECI = { 3,  /* nDims */
  83,                                  /* lineNo */
  49,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo gf_emlrtECI = { 4,  /* nDims */
  83,                                  /* lineNo */
  27,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo hf_emlrtECI = { 3,  /* nDims */
  83,                                  /* lineNo */
  27,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo if_emlrtECI = { 3,  /* nDims */
  82,                                  /* lineNo */
  30,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo jf_emlrtECI = { 3,  /* nDims */
  80,                                  /* lineNo */
  15,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo kf_emlrtECI = { 1,  /* nDims */
  80,                                  /* lineNo */
  15,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo lf_emlrtECI = { 3,  /* nDims */
  79,                                  /* lineNo */
  15,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo mf_emlrtECI = { 1,  /* nDims */
  79,                                  /* lineNo */
  15,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtDCInfo p_emlrtDCI = { 75,  /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 75,  /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 75,  /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 75,  /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 74,  /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 74,  /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 74,  /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 74,  /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 70,  /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 70,  /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 70, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 70, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 69, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 69, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 69, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 69, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = { 68, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = { 68, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = { 68, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo jb_emlrtDCI = { 68, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo kb_emlrtDCI = { 67, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo lb_emlrtDCI = { 67, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo mb_emlrtDCI = { 67, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo nb_emlrtDCI = { 67, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ob_emlrtDCI = { 66, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo pb_emlrtDCI = { 66, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo qb_emlrtDCI = { 66, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo rb_emlrtDCI = { 66, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo sb_emlrtDCI = { 65, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo tb_emlrtDCI = { 65, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ub_emlrtDCI = { 65, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo vb_emlrtDCI = { 65, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo wb_emlrtDCI = { 64, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo xb_emlrtDCI = { 64, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo yb_emlrtDCI = { 64, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo ac_emlrtDCI = { 64, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo bc_emlrtDCI = { 63, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo cc_emlrtDCI = { 63, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo dc_emlrtDCI = { 63, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo ec_emlrtDCI = { 63, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo fc_emlrtDCI = { 62, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo gc_emlrtDCI = { 62, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo hc_emlrtDCI = { 62, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo ic_emlrtDCI = { 62, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo jc_emlrtDCI = { 61, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo kc_emlrtDCI = { 61, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo lc_emlrtDCI = { 61, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo mc_emlrtDCI = { 61, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo nc_emlrtDCI = { 59, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo oc_emlrtDCI = { 59, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo pc_emlrtDCI = { 59, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo qc_emlrtDCI = { 59, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo rc_emlrtDCI = { 58, /* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo sc_emlrtDCI = { 58, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo tc_emlrtDCI = { 58, /* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo uc_emlrtDCI = { 58, /* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo nf_emlrtECI = { 4,  /* nDims */
  45,                                  /* lineNo */
  12,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtECInfo of_emlrtECI = { 3,  /* nDims */
  45,                                  /* lineNo */
  12,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtDCInfo vc_emlrtDCI = { 31, /* lineNo */
  48,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo wc_emlrtDCI = { 31, /* lineNo */
  48,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo xc_emlrtDCI = { 31, /* lineNo */
  40,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo yc_emlrtDCI = { 31, /* lineNo */
  40,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo ad_emlrtDCI = { 31, /* lineNo */
  24,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo bd_emlrtDCI = { 44, /* lineNo */
  33,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  33,                                  /* colNo */
  "obj.th_target_w",                   /* aName */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo sd_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo td_emlrtRTEI = { 31,/* lineNo */
  5,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = { 44,/* lineNo */
  41,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = { 46,/* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = { 581,/* lineNo */
  21,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = { 59,/* lineNo */
  23,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo be_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "min",                               /* fName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/min.m"/* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = { 60,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo de_emlrtRTEI = { 149,/* lineNo */
  5,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = { 71,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo he_emlrtRTEI = { 82,/* lineNo */
  30,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = { 82,/* lineNo */
  53,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo je_emlrtRTEI = { 83,/* lineNo */
  23,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = { 83,/* lineNo */
  49,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo le_emlrtRTEI = { 85,/* lineNo */
  14,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo me_emlrtRTEI = { 83,/* lineNo */
  45,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = { 85,/* lineNo */
  24,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = { 85,/* lineNo */
  23,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = { 85,/* lineNo */
  33,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo re_emlrtRTEI = { 85,/* lineNo */
  42,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo se_emlrtRTEI = { 85,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo te_emlrtRTEI = { 86,/* lineNo */
  57,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = { 87,/* lineNo */
  57,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = { 90,/* lineNo */
  13,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = { 93,/* lineNo */
  25,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = { 95,/* lineNo */
  23,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo af_emlrtRTEI = { 95,/* lineNo */
  39,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = { 97,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = { 99,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo df_emlrtRTEI = { 100,/* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = { 101,/* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = { 102,/* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo gf_emlrtRTEI = { 104,/* lineNo */
  24,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo hf_emlrtRTEI = { 105,/* lineNo */
  28,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo if_emlrtRTEI = { 104,/* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo jf_emlrtRTEI = { 105,/* lineNo */
  36,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo kf_emlrtRTEI = { 105,/* lineNo */
  56,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = { 106,/* lineNo */
  38,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = { 106,/* lineNo */
  46,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo of_emlrtRTEI = { 106,/* lineNo */
  66,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = { 107,/* lineNo */
  45,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo rf_emlrtRTEI = { 107,/* lineNo */
  30,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = { 108,/* lineNo */
  29,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = { 108,/* lineNo */
  45,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = { 110,/* lineNo */
  23,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = { 112,/* lineNo */
  27,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo yf_emlrtRTEI = { 112,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = { 113,/* lineNo */
  27,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = { 113,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = { 114,/* lineNo */
  27,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = { 114,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = { 115,/* lineNo */
  27,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = { 115,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = { 117,/* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = { 117,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = { 118,/* lineNo */
  22,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo jg_emlrtRTEI = { 118,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo kg_emlrtRTEI = { 123,/* lineNo */
  36,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo lg_emlrtRTEI = { 123,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = { 124,/* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = { 123,/* lineNo */
  25,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo og_emlrtRTEI = { 124,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = { 126,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo qg_emlrtRTEI = { 127,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo rg_emlrtRTEI = { 128,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo sg_emlrtRTEI = { 129,/* lineNo */
  23,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo tg_emlrtRTEI = { 129,/* lineNo */
  34,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ug_emlrtRTEI = { 132,/* lineNo */
  16,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo vg_emlrtRTEI = { 132,/* lineNo */
  35,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo wg_emlrtRTEI = { 132,/* lineNo */
  53,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo xg_emlrtRTEI = { 132,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = { 133,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = { 133,/* lineNo */
  27,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = { 136,/* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = { 133,/* lineNo */
  23,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = { 136,/* lineNo */
  37,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo eh_emlrtRTEI = { 136,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo fh_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo gh_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo hh_emlrtRTEI = { 63,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ih_emlrtRTEI = { 67,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo jh_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo kh_emlrtRTEI = { 69,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo lh_emlrtRTEI = { 82,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo mh_emlrtRTEI = { 83,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo nh_emlrtRTEI = { 86,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo oh_emlrtRTEI = { 87,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ph_emlrtRTEI = { 94,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo qh_emlrtRTEI = { 95,/* lineNo */
  9,                                   /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo rh_emlrtRTEI = { 117,/* lineNo */
  26,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo sh_emlrtRTEI = { 86,/* lineNo */
  43,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo mi_emlrtRTEI = { 128,/* lineNo */
  19,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ni_emlrtRTEI = { 123,/* lineNo */
  21,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo oi_emlrtRTEI = { 115,/* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo pi_emlrtRTEI = { 114,/* lineNo */
  20,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo qi_emlrtRTEI = { 93,/* lineNo */
  18,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRTEInfo ri_emlrtRTEI = { 89,/* lineNo */
  13,                                  /* colNo */
  "FPM_capsule_v3_3vec",               /* fName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pName */
};

static emlrtRSInfo hg_emlrtRSI = { 136,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 132,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 126,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 127,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 128,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo mg_emlrtRSI = { 124,/* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo ng_emlrtRSI = { 31, /* lineNo */
  "unsafeSxfun",                       /* fcnName */
  "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/unsafeSxfun.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 93, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo pg_emlrtRSI = { 89, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 45, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo vg_emlrtRSI = { 99, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

static emlrtRSInfo wg_emlrtRSI = { 97, /* lineNo */
  "FPM_capsule_v3_3vec",               /* fcnName */
  "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
  "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/caps"
  "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/FPM_capsule_v3_3vec.m"/* pathName */
};

/* Function Declarations */
static void b_minus(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2);
static void b_times(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2, const emxArray_real_T *in3);
static void binary_expand_op_15(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_boolean_T *in2);
static void binary_expand_op_16(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_boolean_T *in2);
static void binary_expand_op_17(const emlrtStack *sp, emxArray_real_T *in1,
  const real_T in2_data[], const int32_T in2_size[3], real_T in3);
static void binary_expand_op_18(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, const emxArray_real_T *in3);
static void binary_expand_op_19(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, const emxArray_real_T *in3);
static void binary_expand_op_20(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_boolean_T *in2);
static void binary_expand_op_21(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_boolean_T *in2);
static void binary_expand_op_22(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_real_T *in3, const real_T in4_data[], const int32_T in4_size[3]);
static void binary_expand_op_27(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_real_T *in2);
static void binary_expand_op_29(const emlrtStack *sp, emxArray_real_T *in1,
  const real_T in2_data[], const int32_T in2_size[3]);
static void binary_expand_op_32(const emlrtStack *sp, emxArray_real_T *in1,
  const real_T in2_data[], const int32_T in2_size[3]);
static void binary_expand_op_33(const emlrtStack *sp, emxArray_real_T *in1,
  const emlrtRSInfo in2, const real_T in3_data[], const int32_T in3_size[3],
  const emxArray_real_T *in4);
static void binary_expand_op_35(const emlrtStack *sp, emxArray_real_T *in1,
  const emlrtRSInfo in2, const real_T in3_data[], const int32_T in3_size[3],
  const emxArray_real_T *in4);
static void binary_expand_op_36(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_real_T *in2, const emxArray_boolean_T *in3);
static void binary_expand_op_37(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, const real_T in3_data[], const int32_T in3_size[3]);
static void binary_expand_op_39(const emlrtStack *sp, emxArray_real_T *in1,
  const emlrtRSInfo in2, const real_T in3_data[], const int32_T in3_size[3],
  const emxArray_real_T *in4);
static void binary_expand_op_41(const emlrtStack *sp, emxArray_real_T *in1,
  const emlrtRSInfo in2, const real_T in3_data[], const int32_T in3_size[3],
  const emxArray_real_T *in4);
static void binary_expand_op_42(real_T in1_data[], int32_T in1_size[3], const
  real_T in2_data[], const int32_T in2_size[3], const real_T in3_data[], const
  int32_T in3_size[3]);
static void binary_expand_op_44(const emlrtStack *sp, emxArray_real_T *in1,
  const real_T in2_data[], const emxArray_real_T *in3, const real_T in4[4],
  const emxArray_real_T *in5);
static void c_and(const emlrtStack *sp, emxArray_boolean_T *in1, const
                  emxArray_boolean_T *in2);
static void c_minus(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2);
static void c_plus(const emlrtStack *sp, emxArray_real_T *in1, const
                   emxArray_real_T *in2);
static void c_times(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2);
static void d_minus(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2, const emxArray_real_T *in3);
static void d_plus(const emlrtStack *sp, emxArray_real_T *in1, const
                   emxArray_real_T *in2);
static void d_times(real_T in1_data[], int32_T in1_size[3], const real_T
                    in2_data[], const int32_T in2_size[3]);
static void e_plus(const emlrtStack *sp, emxArray_real_T *in1, const
                   emxArray_real_T *in2);
static void f_plus(const emlrtStack *sp, emxArray_real_T *in1, const
                   emxArray_real_T *in2);
static void minus(const emlrtStack *sp, emxArray_real_T *in1, const
                  emxArray_real_T *in2);
static void times(const emlrtStack *sp, emxArray_real_T *in1, const
                  emxArray_real_T *in2);

/* Function Definitions */
static void b_minus(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_1;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &ri_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }

  b_in1->size[1] = b_loop_ub;
  if (in2->size[2] == 1) {
    c_loop_ub = in1->size[2];
  } else {
    c_loop_ub = in2->size[2];
  }

  b_in1->size[2] = c_loop_ub;
  if (in2->size[3] == 1) {
    d_loop_ub = in1->size[3];
  } else {
    d_loop_ub = in2->size[3];
  }

  b_in1->size[3] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &ri_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  stride_1_2 = (in2->size[2] != 1);
  stride_1_3 = (in2->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < d_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      int32_T aux_0_1;
      int32_T aux_1_1;
      aux_0_1 = 0;
      aux_1_1 = 0;
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          b_in1_data[((i3 + b_in1->size[0] * i2) + b_in1->size[0] * b_in1->size
                      [1] * i1) + b_in1->size[0] * b_in1->size[1] * b_in1->size
            [2] * i] = in1_data[((i3 * stride_0_0 + in1->size[0] * aux_0_1) +
            in1->size[0] * in1->size[1] * aux_0_2) + in1->size[0] * in1->size[1]
            * in1->size[2] * aux_0_3] - in2_data[((i3 * stride_1_0 + in2->size[0]
            * aux_1_1) + in2->size[0] * in2->size[1] * aux_1_2) + in2->size[0] *
            in2->size[1] * in2->size[2] * aux_1_3];
        }

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
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  in1->size[2] = c_loop_ub;
  in1->size[3] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &ri_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < d_loop_ub; i++) {
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          in1_data[((i3 + in1->size[0] * i2) + in1->size[0] * in1->size[1] * i1)
            + in1->size[0] * in1->size[1] * in1->size[2] * i] = b_in1_data[((i3
            + b_in1->size[0] * i2) + b_in1->size[0] * b_in1->size[1] * i1) +
            b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * i];
        }
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void b_times(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2, const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &kf_emlrtRTEI);
  if (in3->size[2] == 1) {
    b_loop_ub = in2->size[2];
  } else {
    b_loop_ub = in3->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &kf_emlrtRTEI);
  if (in3->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in3->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &kf_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_2 = (in3->size[2] != 1);
  stride_1_3 = (in3->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          in2_data[(i2 * stride_0_0 + in2->size[0] * aux_0_2) + in2->size[0] *
          in2->size[2] * aux_0_3] * in3_data[(i2 * stride_1_0 + in3->size[0] *
          aux_1_2) + in3->size[0] * in3->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_15(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_boolean_T *in2)
{
  emxArray_real_T *b_in1;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  const boolean_T *in2_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &bh_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
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
  emxEnsureCapacity_real_T(sp, b_in1, i, &bh_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_0 = (in2->size[0] != 1);
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
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) + in1->size[0]
          * in1->size[2] * aux_0_3] + (real_T)in2_data[(i2 * stride_1_0 +
          in2->size[0] * aux_1_2) + in2->size[0] * in2->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &bh_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_16(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_boolean_T *in2)
{
  emxArray_real_T *b_in1;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  const boolean_T *in2_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &bh_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
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
  emxEnsureCapacity_real_T(sp, b_in1, i, &bh_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_0 = (in2->size[0] != 1);
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
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) + in1->size[0]
          * in1->size[2] * aux_0_3] * (real_T)in2_data[(i2 * stride_1_0 +
          in2->size[0] * aux_1_2) + in2->size[0] * in2->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &bh_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_17(const emlrtStack *sp, emxArray_real_T *in1,
  const real_T in2_data[], const int32_T in2_size[3], real_T in3)
{
  emxArray_real_T *b_in1;
  real_T b_in2_data[630];
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T e_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_1_0;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  loop_ub = in2_size[0];
  b_loop_ub = in2_size[2];
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in2_data[i1 + loop_ub * i] = in2_data[(i1 + in2_size[0] * 5) + in2_size
        [0] * 6 * i];
    }
  }

  emxInit_real_T(sp, &b_in1, 4, &ah_emlrtRTEI);
  if (loop_ub == 1) {
    c_loop_ub = in1->size[0];
  } else {
    c_loop_ub = loop_ub;
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = c_loop_ub;
  b_in1->size[1] = 1;
  if (b_loop_ub == 1) {
    d_loop_ub = in1->size[2];
  } else {
    d_loop_ub = b_loop_ub;
  }

  b_in1->size[2] = d_loop_ub;
  e_loop_ub = in1->size[3];
  b_in1->size[3] = e_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &ah_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_1_0 = (loop_ub != 1);
  b_loop_ub = (b_loop_ub != 1);
  for (i = 0; i < e_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < d_loop_ub; i1++) {
      for (i2 = 0; i2 < c_loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = -((in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) +
                  in1->size[0] * in1->size[2] * i] - b_in2_data[i2 * stride_1_0
                  + loop_ub * aux_1_2]) - in3);
      }

      aux_1_2 += b_loop_ub;
      aux_0_2 += stride_0_2;
    }
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = c_loop_ub;
  in1->size[1] = 1;
  in1->size[2] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &ah_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < e_loop_ub; i++) {
    for (i1 = 0; i1 < d_loop_ub; i1++) {
      for (i2 = 0; i2 < c_loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_18(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  emxEnsureCapacity_boolean_T(sp, in1, i, &vg_emlrtRTEI);
  if (in3->size[2] == 1) {
    b_loop_ub = in2->size[2];
  } else {
    b_loop_ub = in3->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &vg_emlrtRTEI);
  if (in3->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in3->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &vg_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_2 = (in3->size[2] != 1);
  stride_1_3 = (in3->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          (in2_data[(i2 * stride_0_0 + in2->size[0] * aux_0_2) + in2->size[0] *
           in2->size[2] * aux_0_3] + in3_data[(i2 * stride_1_0 + in3->size[0] *
            aux_1_2) + in3->size[0] * in3->size[2] * aux_1_3] < 0.0);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_19(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ug_emlrtRTEI);
  if (in3->size[2] == 1) {
    b_loop_ub = in2->size[2];
  } else {
    b_loop_ub = in3->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ug_emlrtRTEI);
  if (in3->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in3->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ug_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_2 = (in3->size[2] != 1);
  stride_1_3 = (in3->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          (in2_data[(i2 * stride_0_0 + in2->size[0] * aux_0_2) + in2->size[0] *
           in2->size[2] * aux_0_3] + in3_data[(i2 * stride_1_0 + in3->size[0] *
            aux_1_2) + in3->size[0] * in3->size[2] * aux_1_3] >= 0.0);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_20(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_boolean_T *in2)
{
  emxArray_real_T *b_in1;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_1_0;
  int32_T stride_1_2;
  const boolean_T *in2_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &mg_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
  if (in2->size[2] == 1) {
    b_loop_ub = in1->size[2];
  } else {
    b_loop_ub = in2->size[2];
  }

  b_in1->size[2] = b_loop_ub;
  c_loop_ub = in1->size[3];
  b_in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &mg_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_2 = (in2->size[2] != 1);
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) + in1->size[0]
          * in1->size[2] * i] * (real_T)in2_data[(i2 * stride_1_0 + in2->size[0]
          * aux_1_2) + in2->size[0] * in2->size[2] * i];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &mg_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_21(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_boolean_T *in2)
{
  emxArray_real_T *r;
  real_T *in1_data;
  real_T *r1;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_1_0;
  int32_T stride_1_2;
  const boolean_T *in2_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &r, 4, &ni_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = r->size[0] * r->size[1] * r->size[2] * r->size[3];
  r->size[0] = loop_ub;
  r->size[1] = 1;
  if (in2->size[2] == 1) {
    b_loop_ub = in1->size[2];
  } else {
    b_loop_ub = in2->size[2];
  }

  r->size[2] = b_loop_ub;
  c_loop_ub = in1->size[3];
  r->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, r, i, &ni_emlrtRTEI);
  r1 = r->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_2 = (in2->size[2] != 1);
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        r1[(i2 + r->size[0] * i1) + r->size[0] * r->size[2] * i] =
          (3.1415926535897931 - in1_data[(i2 * stride_0_0 + in1->size[0] *
            aux_0_2) + in1->size[0] * in1->size[2] * i]) * (real_T)in2_data[(i2 *
          stride_1_0 + in2->size[0] * aux_1_2) + in2->size[0] * in2->size[2] * i];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &ni_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          r1[(i2 + r->size[0] * i1) + r->size[0] * r->size[2] * i];
      }
    }
  }

  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_22(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_real_T *in3, const real_T in4_data[], const int32_T in4_size[3])
{
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  real_T *b_in3_data;
  real_T *in1_data;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T in4_idx_0;
  int32_T in4_idx_2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_1_0;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  in4_idx_0 = in4_size[0];
  in4_idx_2 = in4_size[2];
  emxInit_real_T(sp, &b_in3, 4, &uf_emlrtRTEI);
  if (in4_idx_0 == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4_idx_0;
  }

  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2] * b_in3->size[3];
  b_in3->size[0] = loop_ub;
  b_in3->size[1] = 1;
  if (in4_idx_2 == 1) {
    b_loop_ub = in3->size[2];
  } else {
    b_loop_ub = in4_idx_2;
  }

  b_in3->size[2] = b_loop_ub;
  c_loop_ub = in3->size[3];
  b_in3->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &uf_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_0_2 = (in3->size[2] != 1);
  stride_1_0 = (in4_idx_0 != 1);
  in4_idx_2 = (in4_idx_2 != 1);
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in3_data[(i2 + b_in3->size[0] * i1) + b_in3->size[0] * b_in3->size[2] *
          i] = in3_data[(i2 * stride_0_0 + in3->size[0] * aux_0_2) + in3->size[0]
          * in3->size[2] * i] / in4_data[i2 * stride_1_0 + in4_idx_0 * aux_1_2];
      }

      aux_1_2 += in4_idx_2;
      aux_0_2 += stride_0_2;
    }
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &ng_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T varargin_1;
        varargin_1 = b_in3_data[(i2 + b_in3->size[0] * i1) + b_in3->size[0] *
          b_in3->size[2] * i];
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          muDoubleScalarMax(-1.0, muDoubleScalarMin(varargin_1, 1.0));
      }
    }
  }

  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_27(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_real_T *in2)
{
  emxArray_real_T *b_in2;
  const real_T *in2_data;
  real_T *b_in2_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in2, 4, &rf_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }

  i = b_in2->size[0] * b_in2->size[1] * b_in2->size[2] * b_in2->size[3];
  b_in2->size[0] = loop_ub;
  b_in2->size[1] = 1;
  if (in1->size[2] == 1) {
    b_loop_ub = in2->size[2];
  } else {
    b_loop_ub = in1->size[2];
  }

  b_in2->size[2] = b_loop_ub;
  if (in1->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in1->size[3];
  }

  b_in2->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in2, i, &rf_emlrtRTEI);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_0 = (in1->size[0] != 1);
  stride_1_2 = (in1->size[2] != 1);
  stride_1_3 = (in1->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in2_data[(i2 + b_in2->size[0] * i1) + b_in2->size[0] * b_in2->size[2] *
          i] = in2_data[(i2 * stride_0_0 + in2->size[0] * aux_0_2) + in2->size[0]
          * in2->size[2] * aux_0_3] * in1_data[(i2 * stride_1_0 + in1->size[0] *
          aux_1_2) + in1->size[0] * in1->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &rf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in2_data[(i2 + b_in2->size[0] * i1) + b_in2->size[0] * b_in2->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_29(const emlrtStack *sp, emxArray_real_T *in1,
  const real_T in2_data[], const int32_T in2_size[3])
{
  emxArray_real_T *b_in1;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T in2_idx_0;
  int32_T in2_idx_2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_1_0;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  in2_idx_0 = in2_size[0];
  in2_idx_2 = in2_size[2];
  emxInit_real_T(sp, &b_in1, 4, &mf_emlrtRTEI);
  if (in2_idx_0 == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2_idx_0;
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
  if (in2_idx_2 == 1) {
    b_loop_ub = in1->size[2];
  } else {
    b_loop_ub = in2_idx_2;
  }

  b_in1->size[2] = b_loop_ub;
  c_loop_ub = in1->size[3];
  b_in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &mf_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_1_0 = (in2_idx_0 != 1);
  in2_idx_2 = (in2_idx_2 != 1);
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) + in1->size[0]
          * in1->size[2] * i] - in2_data[i2 * stride_1_0 + in2_idx_0 * aux_1_2];
      }

      aux_1_2 += in2_idx_2;
      aux_0_2 += stride_0_2;
    }
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &mf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_32(const emlrtStack *sp, emxArray_real_T *in1,
  const real_T in2_data[], const int32_T in2_size[3])
{
  emxArray_real_T *b_in1;
  real_T b_in2_data[630];
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T e_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_1_0;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  loop_ub = in2_size[0];
  b_loop_ub = in2_size[2];
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in2_data[i1 + loop_ub * i] = in2_data[(i1 + in2_size[0] * 2) + in2_size
        [0] * 6 * i];
    }
  }

  emxInit_real_T(sp, &b_in1, 4, &gf_emlrtRTEI);
  if (loop_ub == 1) {
    c_loop_ub = in1->size[0];
  } else {
    c_loop_ub = loop_ub;
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = c_loop_ub;
  b_in1->size[1] = 1;
  if (b_loop_ub == 1) {
    d_loop_ub = in1->size[2];
  } else {
    d_loop_ub = b_loop_ub;
  }

  b_in1->size[2] = d_loop_ub;
  e_loop_ub = in1->size[3];
  b_in1->size[3] = e_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &gf_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_1_0 = (loop_ub != 1);
  b_loop_ub = (b_loop_ub != 1);
  for (i = 0; i < e_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < d_loop_ub; i1++) {
      for (i2 = 0; i2 < c_loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) + in1->size[0]
          * in1->size[2] * i] - b_in2_data[i2 * stride_1_0 + loop_ub * aux_1_2];
      }

      aux_1_2 += b_loop_ub;
      aux_0_2 += stride_0_2;
    }
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = c_loop_ub;
  in1->size[1] = 1;
  in1->size[2] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &gf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < e_loop_ub; i++) {
    for (i1 = 0; i1 < d_loop_ub; i1++) {
      for (i2 = 0; i2 < c_loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_33(const emlrtStack *sp, emxArray_real_T *in1,
  const emlrtRSInfo in2, const real_T in3_data[], const int32_T in3_size[3],
  const emxArray_real_T *in4)
{
  emlrtStack st;
  emxArray_real_T *in3;
  const real_T *in4_data;
  real_T *b_in3_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T in3_idx_0;
  int32_T in3_idx_2;
  int32_T loop_ub;
  int32_T stride_1_2;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  in3_idx_0 = in3_size[0];
  in3_idx_2 = in3_size[2];
  emxInit_real_T(sp, &in3, 4, &ff_emlrtRTEI);
  i = in3->size[0] * in3->size[1] * in3->size[2] * in3->size[3];
  in3->size[0] = in3_idx_0;
  in3->size[1] = 2;
  if (in4->size[2] == 1) {
    loop_ub = in3_idx_2;
  } else {
    loop_ub = in4->size[2];
  }

  in3->size[2] = loop_ub;
  b_loop_ub = in4->size[3];
  in3->size[3] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in3, i, &ff_emlrtRTEI);
  b_in3_data = in3->data;
  in3_idx_2 = (in3_idx_2 != 1);
  stride_1_2 = (in4->size[2] != 1);
  for (i = 0; i < b_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < in3_idx_0; i3++) {
          b_in3_data[((i3 + in3->size[0] * i2) + in3->size[0] * 2 * i1) +
            in3->size[0] * 2 * in3->size[2] * i] = in3_data[(i3 + in3_idx_0 * i2)
            + in3_idx_0 * 2 * aux_0_2] - in4_data[(i2 + 2 * aux_1_2) + 2 *
            in4->size[2] * i];
        }
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += in3_idx_2;
    }
  }

  st.site = (emlrtRSInfo *)&in2;
  b_vecnorm(&st, in3, in1);
  emxFree_real_T(sp, &in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_35(const emlrtStack *sp, emxArray_real_T *in1,
  const emlrtRSInfo in2, const real_T in3_data[], const int32_T in3_size[3],
  const emxArray_real_T *in4)
{
  emlrtStack st;
  emxArray_real_T *in3;
  real_T b_in3_data[1260];
  const real_T *in4_data;
  real_T *c_in3_data;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_1_2;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  loop_ub = in3_size[0];
  b_loop_ub = in3_size[2];
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in3_data[(i2 + loop_ub * i1) + loop_ub * 2 * i] = in3_data[(i2 +
          in3_size[0] * i1) + in3_size[0] * 6 * i];
      }
    }
  }

  emxInit_real_T(sp, &in3, 4, &df_emlrtRTEI);
  i = in3->size[0] * in3->size[1] * in3->size[2] * in3->size[3];
  in3->size[0] = loop_ub;
  in3->size[1] = 2;
  if (in4->size[2] == 1) {
    c_loop_ub = b_loop_ub;
  } else {
    c_loop_ub = in4->size[2];
  }

  in3->size[2] = c_loop_ub;
  d_loop_ub = in4->size[3];
  in3->size[3] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, in3, i, &df_emlrtRTEI);
  c_in3_data = in3->data;
  b_loop_ub = (b_loop_ub != 1);
  stride_1_2 = (in4->size[2] != 1);
  for (i = 0; i < d_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          c_in3_data[((i3 + in3->size[0] * i2) + in3->size[0] * 2 * i1) +
            in3->size[0] * 2 * in3->size[2] * i] = b_in3_data[(i3 + loop_ub * i2)
            + loop_ub * 2 * aux_0_2] - in4_data[(i2 + 2 * aux_1_2) + 2 *
            in4->size[2] * i];
        }
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += b_loop_ub;
    }
  }

  st.site = (emlrtRSInfo *)&in2;
  b_vecnorm(&st, in3, in1);
  emxFree_real_T(sp, &in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_36(const emlrtStack *sp, emxArray_real_T *in1,
  const emxArray_real_T *in2, const emxArray_boolean_T *in3)
{
  const real_T *in2_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  const boolean_T *in3_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &cf_emlrtRTEI);
  if (in3->size[2] == 1) {
    b_loop_ub = in2->size[2];
  } else {
    b_loop_ub = in3->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &cf_emlrtRTEI);
  if (in3->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in3->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &cf_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_2 = (in3->size[2] != 1);
  stride_1_3 = (in3->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          in2_data[(i2 * stride_0_0 + in2->size[0] * aux_0_2) + in2->size[0] *
          in2->size[2] * aux_0_3] * (real_T)in3_data[(i2 * stride_1_0 +
          in3->size[0] * aux_1_2) + in3->size[0] * in3->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_37(const emlrtStack *sp, emxArray_boolean_T *in1,
  const emxArray_real_T *in2, const real_T in3_data[], const int32_T in3_size[3])
{
  const real_T *in2_data;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T in3_idx_0;
  int32_T in3_idx_2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_1_0;
  boolean_T *in1_data;
  in2_data = in2->data;
  in3_idx_0 = in3_size[0];
  in3_idx_2 = in3_size[2];
  if (in3_idx_0 == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3_idx_0;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  emxEnsureCapacity_boolean_T(sp, in1, i, &bf_emlrtRTEI);
  if (in3_idx_2 == 1) {
    b_loop_ub = in2->size[2];
  } else {
    b_loop_ub = in3_idx_2;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &bf_emlrtRTEI);
  c_loop_ub = in2->size[3];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &bf_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_2 = (in2->size[2] != 1);
  stride_1_0 = (in3_idx_0 != 1);
  in3_idx_2 = (in3_idx_2 != 1);
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          (in2_data[(i2 * stride_0_0 + in2->size[0] * aux_0_2) + in2->size[0] *
           in2->size[2] * i] > in3_data[i2 * stride_1_0 + in3_idx_0 * aux_1_2]);
      }

      aux_1_2 += in3_idx_2;
      aux_0_2 += stride_0_2;
    }
  }
}

static void binary_expand_op_39(const emlrtStack *sp, emxArray_real_T *in1,
  const emlrtRSInfo in2, const real_T in3_data[], const int32_T in3_size[3],
  const emxArray_real_T *in4)
{
  emlrtStack st;
  emxArray_real_T *in3;
  const real_T *in4_data;
  real_T *b_in3_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T in3_idx_0;
  int32_T in3_idx_2;
  int32_T loop_ub;
  int32_T stride_1_2;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  in3_idx_0 = in3_size[0];
  in3_idx_2 = in3_size[2];
  emxInit_real_T(sp, &in3, 4, &ue_emlrtRTEI);
  i = in3->size[0] * in3->size[1] * in3->size[2] * in3->size[3];
  in3->size[0] = in3_idx_0;
  in3->size[1] = 2;
  if (in4->size[2] == 1) {
    loop_ub = in3_idx_2;
  } else {
    loop_ub = in4->size[2];
  }

  in3->size[2] = loop_ub;
  b_loop_ub = in4->size[3];
  in3->size[3] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in3, i, &ue_emlrtRTEI);
  b_in3_data = in3->data;
  in3_idx_2 = (in3_idx_2 != 1);
  stride_1_2 = (in4->size[2] != 1);
  for (i = 0; i < b_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < in3_idx_0; i3++) {
          b_in3_data[((i3 + in3->size[0] * i2) + in3->size[0] * 2 * i1) +
            in3->size[0] * 2 * in3->size[2] * i] = in3_data[(i3 + in3_idx_0 * i2)
            + in3_idx_0 * 2 * aux_0_2] - in4_data[(i2 + 2 * aux_1_2) + 2 *
            in4->size[2] * i];
        }
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += in3_idx_2;
    }
  }

  st.site = (emlrtRSInfo *)&in2;
  d_pagetranspose(&st, in3, in1);
  emxFree_real_T(sp, &in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_41(const emlrtStack *sp, emxArray_real_T *in1,
  const emlrtRSInfo in2, const real_T in3_data[], const int32_T in3_size[3],
  const emxArray_real_T *in4)
{
  emlrtStack st;
  emxArray_real_T *b_in3;
  emxArray_real_T *in3;
  real_T b_in3_data[630];
  real_T c_in3_data[630];
  const real_T *in4_data;
  real_T *d_in3_data;
  real_T *e_in3_data;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T in3_data_tmp;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  loop_ub = in3_size[0];
  b_loop_ub = in3_size[2];
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in3_data_tmp = in3_size[0] * 6 * i;
      b_in3_data[i1 + loop_ub * i] = in3_data[(i1 + in3_size[0]) + in3_data_tmp];
      c_in3_data[i1 + loop_ub * i] = in3_data[i1 + in3_data_tmp];
    }
  }

  emxInit_real_T(sp, &in3, 4, &he_emlrtRTEI);
  i = in3->size[0] * in3->size[1] * in3->size[2] * in3->size[3];
  in3->size[0] = loop_ub;
  in3->size[1] = 1;
  if (in4->size[2] == 1) {
    c_loop_ub = b_loop_ub;
  } else {
    c_loop_ub = in4->size[2];
  }

  in3->size[2] = c_loop_ub;
  d_loop_ub = in4->size[3];
  in3->size[3] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, in3, i, &he_emlrtRTEI);
  d_in3_data = in3->data;
  in3_data_tmp = (b_loop_ub != 1);
  b_loop_ub = (in4->size[2] != 1);
  emxInit_real_T(sp, &b_in3, 4, &ie_emlrtRTEI);
  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2] * b_in3->size[3];
  b_in3->size[0] = loop_ub;
  b_in3->size[1] = 1;
  b_in3->size[2] = c_loop_ub;
  b_in3->size[3] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &ie_emlrtRTEI);
  e_in3_data = b_in3->data;
  for (i = 0; i < d_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        d_in3_data[(i2 + in3->size[0] * i1) + in3->size[0] * in3->size[2] * i] =
          b_in3_data[i2 + loop_ub * aux_0_2] - in4_data[(2 * aux_1_2 + 2 *
          in4->size[2] * i) + 1];
      }

      aux_1_2 += b_loop_ub;
      aux_0_2 += in3_data_tmp;
    }

    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        e_in3_data[(i2 + b_in3->size[0] * i1) + b_in3->size[0] * b_in3->size[2] *
          i] = c_in3_data[i2 + loop_ub * aux_0_2] - in4_data[2 * aux_1_2 + 2 *
          in4->size[2] * i];
      }

      aux_1_2 += b_loop_ub;
      aux_0_2 += in3_data_tmp;
    }
  }

  st.site = (emlrtRSInfo *)&in2;
  c_atan2(&st, in3, b_in3, in1);
  emxFree_real_T(sp, &b_in3);
  emxFree_real_T(sp, &in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_42(real_T in1_data[], int32_T in1_size[3], const
  real_T in2_data[], const int32_T in2_size[3], const real_T in3_data[], const
  int32_T in3_size[3])
{
  int32_T aux_0_2;
  int32_T aux_1_2;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_0_2;
  int32_T stride_1_0;
  int32_T stride_1_2;
  if (in3_size[0] == 1) {
    loop_ub = in2_size[0];
  } else {
    loop_ub = in3_size[0];
  }

  in1_size[0] = loop_ub;
  in1_size[1] = 2;
  if (in3_size[2] == 1) {
    b_loop_ub = in2_size[2];
  } else {
    b_loop_ub = in3_size[2];
  }

  in1_size[2] = b_loop_ub;
  stride_0_0 = (in2_size[0] != 1);
  stride_0_1 = (in2_size[1] != 1);
  stride_0_2 = (in2_size[2] != 1);
  stride_1_0 = (in3_size[0] != 1);
  stride_1_2 = (in3_size[2] != 1);
  aux_0_2 = 0;
  aux_1_2 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    int32_T aux_0_1;
    aux_0_1 = 0;
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1_size[0] * i1) + in1_size[0] * 2 * i] = in2_data[(i2 *
          stride_0_0 + in2_size[0] * aux_0_1) + in2_size[0] * in2_size[1] *
          aux_0_2] + in3_data[(i2 * stride_1_0 + in3_size[0] * i1) + in3_size[0]
          * 6 * aux_1_2];
      }

      aux_0_1 += stride_0_1;
    }

    aux_1_2 += stride_1_2;
    aux_0_2 += stride_0_2;
  }
}

static void binary_expand_op_44(const emlrtStack *sp, emxArray_real_T *in1,
  const real_T in2_data[], const emxArray_real_T *in3, const real_T in4[4],
  const emxArray_real_T *in5)
{
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  const real_T *in5_data;
  real_T *b_in3_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_1_2;
  int32_T stride_1_3;
  int32_T unnamed_idx_2;
  int32_T unnamed_idx_3;
  in5_data = in5->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in3, 2, &ud_emlrtRTEI);
  i = b_in3->size[0] * b_in3->size[1];
  b_in3->size[0] = 20;
  loop_ub = in3->size[1];
  b_in3->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &ud_emlrtRTEI);
  b_in3_data = b_in3->data;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 20; i1++) {
      b_in3_data[i1 + 20 * i] = in3_data[(i1 + 21 * i) + 1];
    }
  }

  unnamed_idx_2 = (int32_T)in4[2];
  unnamed_idx_3 = (int32_T)in4[3];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 1;
  in1->size[1] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &wd_emlrtRTEI);
  if (in5->size[2] == 1) {
    loop_ub = unnamed_idx_2;
  } else {
    loop_ub = in5->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &wd_emlrtRTEI);
  if (in5->size[3] == 1) {
    b_loop_ub = unnamed_idx_3;
  } else {
    b_loop_ub = in5->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &wd_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (unnamed_idx_2 != 1);
  unnamed_idx_3 = (unnamed_idx_3 != 1);
  stride_1_2 = (in5->size[2] != 1);
  stride_1_3 = (in5->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[2] * i] = in2_data[(int32_T)b_in3_data[i1 *
        stride_0_2 + unnamed_idx_2 * aux_0_3] - 1] - in5_data[i1 * stride_1_2 +
        in5->size[2] * aux_1_3];
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += unnamed_idx_3;
  }

  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void c_and(const emlrtStack *sp, emxArray_boolean_T *in1, const
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
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  const boolean_T *in2_data;
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in1, 4, &ug_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
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
  emxEnsureCapacity_boolean_T(sp, b_in1, i, &ug_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_0 = (in2->size[0] != 1);
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
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = (in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) + in1->size
                [0] * in1->size[2] * aux_0_3] && in2_data[(i2 * stride_1_0 +
                 in2->size[0] * aux_1_2) + in2->size[0] * in2->size[2] * aux_1_3]);
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ug_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_boolean_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void c_minus(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
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
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &ke_emlrtRTEI);
  loop_ub = in1->size[0];
  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
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
  emxEnsureCapacity_real_T(sp, b_in1, i, &ke_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
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
      int32_T scalarLB;
      int32_T vectorUB;
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        __m128d r;
        r = _mm_loadu_pd(&in1_data[(i2 + in1->size[0] * aux_0_2) + in1->size[0] *
                         in1->size[2] * aux_0_3]);
        _mm_storeu_pd(&b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] *
                      b_in1->size[2] * i], _mm_sub_pd(r, _mm_set1_pd
          (in2_data[aux_1_2 + in2->size[2] * aux_1_3])));
      }

      for (i2 = scalarLB; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 + in1->size[0] * aux_0_2) + in1->size[0] * in1->
          size[2] * aux_0_3] - in2_data[aux_1_2 + in2->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  loop_ub = b_in1->size[0];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &ke_emlrtRTEI);
  b_loop_ub = b_in1->size[2];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_in1->size[2];
  emxEnsureCapacity_real_T(sp, in1, i, &ke_emlrtRTEI);
  c_loop_ub = b_in1->size[3];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = b_in1->size[3];
  emxEnsureCapacity_real_T(sp, in1, i, &ke_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void c_plus(const emlrtStack *sp, emxArray_real_T *in1, const
                   emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &mi_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
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
  emxEnsureCapacity_real_T(sp, b_in1, i, &mi_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_0 = (in2->size[0] != 1);
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
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) + in1->size[0]
          * in1->size[2] * aux_0_3] + in2_data[(i2 * stride_1_0 + in2->size[0] *
          aux_1_2) + in2->size[0] * in2->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &mi_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void c_times(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2)
{
  emxArray_real_T *b_in2;
  const real_T *in2_data;
  real_T *b_in2_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in2, 4, &xe_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }

  i = b_in2->size[0] * b_in2->size[1] * b_in2->size[2] * b_in2->size[3];
  b_in2->size[0] = loop_ub;
  b_loop_ub = in1->size[1];
  b_in2->size[1] = b_loop_ub;
  if (in1->size[2] == 1) {
    c_loop_ub = in2->size[2];
  } else {
    c_loop_ub = in1->size[2];
  }

  b_in2->size[2] = c_loop_ub;
  if (in1->size[3] == 1) {
    d_loop_ub = in2->size[3];
  } else {
    d_loop_ub = in1->size[3];
  }

  b_in2->size[3] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in2, i, &xe_emlrtRTEI);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_0 = (in1->size[0] != 1);
  stride_1_2 = (in1->size[2] != 1);
  stride_1_3 = (in1->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < d_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          b_in2_data[((i3 + b_in2->size[0] * i2) + b_in2->size[0] * b_in2->size
                      [1] * i1) + b_in2->size[0] * b_in2->size[1] * b_in2->size
            [2] * i] = in2_data[(i3 * stride_0_0 + in2->size[0] * aux_0_2) +
            in2->size[0] * in2->size[2] * aux_0_3] * in1_data[((i3 * stride_1_0
            + in1->size[0] * i2) + in1->size[0] * in1->size[1] * aux_1_2) +
            in1->size[0] * in1->size[1] * in1->size[2] * aux_1_3];
        }
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[2] = c_loop_ub;
  in1->size[3] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &xe_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < d_loop_ub; i++) {
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          in1_data[((i3 + in1->size[0] * i2) + in1->size[0] * in1->size[1] * i1)
            + in1->size[0] * in1->size[1] * in1->size[2] * i] = b_in2_data[((i3
            + b_in2->size[0] * i2) + b_in2->size[0] * b_in2->size[1] * i1) +
            b_in2->size[0] * b_in2->size[1] * b_in2->size[2] * i];
        }
      }
    }
  }

  emxFree_real_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void d_minus(const emlrtStack *sp, emxArray_real_T *in1, const
                    emxArray_real_T *in2, const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  real_T *in1_data;
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
  in3_data = in3->data;
  in2_data = in2->data;
  loop_ub = in2->size[0];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &je_emlrtRTEI);
  if (in3->size[2] == 1) {
    b_loop_ub = in2->size[2];
  } else {
    b_loop_ub = in3->size[2];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &je_emlrtRTEI);
  if (in3->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in3->size[3];
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &je_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in3->size[2] != 1);
  stride_1_3 = (in3->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      int32_T scalarLB;
      int32_T vectorUB;
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        __m128d r;
        r = _mm_loadu_pd(&in2_data[(i2 + in2->size[0] * aux_0_2) + in2->size[0] *
                         in2->size[2] * aux_0_3]);
        _mm_storeu_pd(&in1_data[(i2 + in1->size[0] * i1) + in1->size[0] *
                      in1->size[2] * i], _mm_sub_pd(r, _mm_set1_pd
          (in3_data[aux_1_2 + in3->size[2] * aux_1_3])));
      }

      for (i2 = scalarLB; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          in2_data[(i2 + in2->size[0] * aux_0_2) + in2->size[0] * in2->size[2] *
          aux_0_3] - in3_data[aux_1_2 + in3->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void d_plus(const emlrtStack *sp, emxArray_real_T *in1, const
                   emxArray_real_T *in2)
{
  emxArray_real_T *b_in2;
  const real_T *in2_data;
  real_T *b_in2_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in2, 4, &pi_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }

  i = b_in2->size[0] * b_in2->size[1] * b_in2->size[2] * b_in2->size[3];
  b_in2->size[0] = loop_ub;
  b_in2->size[1] = 1;
  if (in1->size[2] == 1) {
    b_loop_ub = in2->size[2];
  } else {
    b_loop_ub = in1->size[2];
  }

  b_in2->size[2] = b_loop_ub;
  if (in1->size[3] == 1) {
    c_loop_ub = in2->size[3];
  } else {
    c_loop_ub = in1->size[3];
  }

  b_in2->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in2, i, &pi_emlrtRTEI);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_0 = (in1->size[0] != 1);
  stride_1_2 = (in1->size[2] != 1);
  stride_1_3 = (in1->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in2_data[(i2 + b_in2->size[0] * i1) + b_in2->size[0] * b_in2->size[2] *
          i] = in2_data[(i2 * stride_0_0 + in2->size[0] * aux_0_2) + in2->size[0]
          * in2->size[2] * aux_0_3] + in1_data[(i2 * stride_1_0 + in1->size[0] *
          aux_1_2) + in1->size[0] * in1->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &pi_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in2_data[(i2 + b_in2->size[0] * i1) + b_in2->size[0] * b_in2->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void d_times(real_T in1_data[], int32_T in1_size[3], const real_T
                    in2_data[], const int32_T in2_size[3])
{
  real_T b_in1_data[1260];
  int32_T aux_0_2;
  int32_T aux_1_2;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_0_2;
  int32_T stride_1_0;
  int32_T stride_1_1;
  int32_T stride_1_2;
  if (in2_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in2_size[0];
  }

  if (in2_size[1] == 1) {
    b_loop_ub = in1_size[1];
  } else {
    b_loop_ub = in2_size[1];
  }

  if (in2_size[2] == 1) {
    c_loop_ub = in1_size[2];
  } else {
    c_loop_ub = in2_size[2];
  }

  stride_0_0 = (in1_size[0] != 1);
  stride_0_1 = (in1_size[1] != 1);
  stride_0_2 = (in1_size[2] != 1);
  stride_1_0 = (in2_size[0] != 1);
  stride_1_1 = (in2_size[1] != 1);
  stride_1_2 = (in2_size[2] != 1);
  aux_0_2 = 0;
  aux_1_2 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_1;
    int32_T aux_1_1;
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + loop_ub * i1) + loop_ub * b_loop_ub * i] = in1_data[(i2
          * stride_0_0 + in1_size[0] * aux_0_1) + in1_size[0] * in1_size[1] *
          aux_0_2] * in2_data[(i2 * stride_1_0 + in2_size[0] * aux_1_1) +
          in2_size[0] * in2_size[1] * aux_1_2];
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    aux_1_2 += stride_1_2;
    aux_0_2 += stride_0_2;
  }

  in1_size[0] = loop_ub;
  in1_size[1] = b_loop_ub;
  in1_size[2] = c_loop_ub;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1_size[0] * i1) + in1_size[0] * in1_size[1] * i] =
          b_in1_data[(i2 + loop_ub * i1) + loop_ub * b_loop_ub * i];
      }
    }
  }
}

static void e_plus(const emlrtStack *sp, emxArray_real_T *in1, const
                   emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
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
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &gf_emlrtRTEI);
  loop_ub = in1->size[0];
  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
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
  emxEnsureCapacity_real_T(sp, b_in1, i, &gf_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
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
      int32_T scalarLB;
      int32_T vectorUB;
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        __m128d r;
        r = _mm_loadu_pd(&in1_data[(i2 + in1->size[0] * aux_0_2) + in1->size[0] *
                         in1->size[2] * aux_0_3]);
        _mm_storeu_pd(&b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] *
                      b_in1->size[2] * i], _mm_add_pd(r, _mm_set1_pd
          (in2_data[aux_1_2 + in2->size[2] * aux_1_3])));
      }

      for (i2 = scalarLB; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 + in1->size[0] * aux_0_2) + in1->size[0] * in1->
          size[2] * aux_0_3] + in2_data[aux_1_2 + in2->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  loop_ub = b_in1->size[0];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &gf_emlrtRTEI);
  b_loop_ub = b_in1->size[2];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = b_in1->size[2];
  emxEnsureCapacity_real_T(sp, in1, i, &gf_emlrtRTEI);
  c_loop_ub = b_in1->size[3];
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = b_in1->size[3];
  emxEnsureCapacity_real_T(sp, in1, i, &gf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void f_plus(const emlrtStack *sp, emxArray_real_T *in1, const
                   emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_1;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &qi_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }

  b_in1->size[1] = b_loop_ub;
  if (in2->size[2] == 1) {
    c_loop_ub = in1->size[2];
  } else {
    c_loop_ub = in2->size[2];
  }

  b_in1->size[2] = c_loop_ub;
  if (in2->size[3] == 1) {
    d_loop_ub = in1->size[3];
  } else {
    d_loop_ub = in2->size[3];
  }

  b_in1->size[3] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &qi_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  stride_1_2 = (in2->size[2] != 1);
  stride_1_3 = (in2->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < d_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      int32_T aux_0_1;
      int32_T aux_1_1;
      aux_0_1 = 0;
      aux_1_1 = 0;
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          b_in1_data[((i3 + b_in1->size[0] * i2) + b_in1->size[0] * b_in1->size
                      [1] * i1) + b_in1->size[0] * b_in1->size[1] * b_in1->size
            [2] * i] = in1_data[((i3 * stride_0_0 + in1->size[0] * aux_0_1) +
            in1->size[0] * in1->size[1] * aux_0_2) + in1->size[0] * in1->size[1]
            * in1->size[2] * aux_0_3] + in2_data[((i3 * stride_1_0 + in2->size[0]
            * aux_1_1) + in2->size[0] * in2->size[1] * aux_1_2) + in2->size[0] *
            in2->size[1] * in2->size[2] * aux_1_3];
        }

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
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  in1->size[2] = c_loop_ub;
  in1->size[3] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &qi_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < d_loop_ub; i++) {
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          in1_data[((i3 + in1->size[0] * i2) + in1->size[0] * in1->size[1] * i1)
            + in1->size[0] * in1->size[1] * in1->size[2] * i] = b_in1_data[((i3
            + b_in1->size[0] * i2) + b_in1->size[0] * b_in1->size[1] * i1) +
            b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * i];
        }
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void minus(const emlrtStack *sp, emxArray_real_T *in1, const
                  emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &oi_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
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
  emxEnsureCapacity_real_T(sp, b_in1, i, &oi_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_0 = (in2->size[0] != 1);
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
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) + in1->size[0]
          * in1->size[2] * aux_0_3] - in2_data[(i2 * stride_1_0 + in2->size[0] *
          aux_1_2) + in2->size[0] * in2->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &oi_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void times(const emlrtStack *sp, emxArray_real_T *in1, const
                  emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &sf_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 1;
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
  emxEnsureCapacity_real_T(sp, b_in1, i, &sf_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_0 = (in2->size[0] != 1);
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
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2] *
          i] = in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_2) + in1->size[0]
          * in1->size[2] * aux_0_3] * in2_data[(i2 * stride_1_0 + in2->size[0] *
          aux_1_2) + in2->size[0] * in2->size[2] * aux_1_3];
      }

      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }

    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }

  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &sf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
          b_in1_data[(i2 + b_in1->size[0] * i1) + b_in1->size[0] * b_in1->size[2]
          * i];
      }
    }
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void FPM_capsule_v3_3vec(const emlrtStack *sp, real_T obj_K, real_T obj_NP,
  real_T obj_ObsNum, real_T obj_wheel_width, real_T obj_wheel_len_front, const
  emxArray_real_T *obj_target_n, const real_T obj_th_target_w_data[], int32_T
  obj_th_target_w_size, const emxArray_real_T *x, const emxArray_real_T *y,
  const emxArray_real_T *th, const real_T obs_now_data[], const int32_T
  obs_now_size[3], real_T param_FPM_eta, real_T param_FPM_alpha, real_T
  param_FPM_margin, emxArray_real_T *Grade)
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *idx;
  emxArray_boolean_T *idx2;
  emxArray_real_T *Po;
  emxArray_real_T *PoQ1;
  emxArray_real_T *PoQ2;
  emxArray_real_T *PoQ3;
  emxArray_real_T *PoQo;
  emxArray_real_T *Q1;
  emxArray_real_T *Q1_2;
  emxArray_real_T *Q2_2;
  emxArray_real_T *R;
  emxArray_real_T *b_obj_target_n;
  emxArray_real_T *b_phiQo_global;
  emxArray_real_T *b_result;
  emxArray_real_T *c_result;
  emxArray_real_T *grade_trgt;
  emxArray_real_T *obs_now;
  emxArray_real_T *phaierror;
  emxArray_real_T *phiQo;
  emxArray_real_T *phiQo_global;
  emxArray_real_T *phi_Q1;
  emxArray_real_T *phi_Q2;
  emxArray_real_T *phi_Q2_l;
  emxArray_real_T *phi_Q3;
  emxArray_real_T *phi_o_l_n;
  emxArray_real_T *phi_o_n;
  emxArray_real_T *phig;
  emxArray_real_T *r2;
  emxArray_real_T *r3;
  emxArray_real_T *result;
  emxArray_real_T *varargin_2;
  emxArray_real_T *z2;
  emxArray_real_T *z3;
  emxArray_real_T *z4;
  real_T Q1_data[1260];
  real_T Q2_data[1260];
  real_T b_tmp_data[1260];
  real_T tmp_data[1260];
  real_T D_data[630];
  real_T a_obs_data[630];
  real_T tho_data[630];
  real_T varargin_1_data[630];
  real_T varargin_2_data[630];
  real_T sz[4];
  const real_T *obj_target_n_data;
  const real_T *th_data;
  const real_T *x_data;
  const real_T *y_data;
  real_T a;
  real_T d;
  real_T maxval_tmp;
  real_T r_wheel;
  real_T *PoQ1_data;
  real_T *PoQ3_data;
  real_T *PoQo_data;
  real_T *Po_data;
  real_T *Q2_2_data;
  real_T *R_data;
  real_T *grade_trgt_data;
  real_T *phiQo_data;
  real_T *phiQo_global_data;
  real_T *phi_Q1_data;
  real_T *phi_Q2_data;
  real_T *phi_Q2_l_data;
  real_T *phi_Q3_data;
  real_T *phig_data;
  real_T *z2_data;
  real_T *z3_data;
  real_T *z4_data;
  int32_T b_sz[4];
  int32_T c_sz[4];
  int32_T Q1_size[3];
  int32_T Q2_size[3];
  int32_T b_tmp_size[3];
  int32_T tmp_size[3];
  int32_T varargin_1_size[3];
  int32_T b_loop_ub;
  int32_T b_loop_ub_tmp;
  int32_T c_loop_ub;
  int32_T c_loop_ub_tmp;
  int32_T d_loop_ub;
  int32_T d_loop_ub_tmp;
  int32_T e_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T n;
  int32_T npages;
  int32_T nx;
  int32_T xOffset;
  int32_T xPageOffset;
  boolean_T out;
  boolean_T *idx2_data;
  boolean_T *idx_data;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  th_data = th->data;
  y_data = y->data;
  x_data = x->data;
  obj_target_n_data = obj_target_n->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emlrtMEXProfilingFunctionEntry((char_T *)c_FPM_capsule_v3_3vec_complete_,
    isMexOutdated);

  /*  function [Grade] = FPM_capsule_v3_1(obj,x,y,th,obs_now,target,param_FPM) */
  /*  function [Grade,phi_o,phi_Q1,phi_Q2,grade_trgt,grade_obs] = FPM_capsule_v3_1(obj,x,y,th,obs_now,target,param_FPM)  % テスト用 */
  /*  ベクトルで計算 */
  /*  インデックスで計算 */
  /*  「 _2 」がつく変数は車両座標系 */
  /* --パラメータ-------------------------------------- */
  emlrtMEXProfilingStatement(1, isMexOutdated);

  /*  PMF for the goalの最小値と最大値の比率 */
  emlrtMEXProfilingStatement(2, isMexOutdated);

  /*  PMF for the Obstacle の障害物を考慮する距離 */
  emlrtMEXProfilingStatement(3, isMexOutdated);

  /*  PMF for the Obstacle の障害物のマージン */
  /*  障害物に接触する場合のコスト */
  /* ------------------------------------------------- */
  /* --組み込み用-------------------------------------- */
  emlrtMEXProfilingStatement(5, isMexOutdated);
  st.site = &gc_emlrtRSI;
  b_st.site = &qd_emlrtRSI;
  c_st.site = &rd_emlrtRSI;
  if (y->size[2] != x->size[2]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  c_st.site = &rd_emlrtRSI;
  if (y->size[3] != x->size[3]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T(&b_st, &Po, 4, &sd_emlrtRTEI);
  i = Po->size[0] * Po->size[1] * Po->size[2] * Po->size[3];
  Po->size[0] = 1;
  Po->size[1] = 2;
  loop_ub = x->size[2];
  Po->size[2] = x->size[2];
  b_loop_ub = x->size[3];
  Po->size[3] = x->size[3];
  emxEnsureCapacity_real_T(&b_st, Po, i, &sd_emlrtRTEI);
  Po_data = Po->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      Po_data[2 * i1 + 2 * Po->size[2] * i] = x_data[i1 + x->size[2] * i];
    }
  }

  loop_ub = y->size[3];
  for (i = 0; i < loop_ub; i++) {
    c_loop_ub = y->size[2];
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      Po_data[(2 * i1 + 2 * Po->size[2] * i) + 1] = y_data[i1 + y->size[2] * i];
    }
  }

  real_T b_obj_wheel_width[2];

  /*  車椅子の位置 */
  emlrtMEXProfilingStatement(6, isMexOutdated);

  /*  車椅子の横幅 */
  emlrtMEXProfilingStatement(7, isMexOutdated);

  /*  車椅子の縦幅 */
  emlrtMEXProfilingStatement(8, isMexOutdated);
  b_obj_wheel_width[0] = obj_wheel_width;
  b_obj_wheel_width[1] = obj_wheel_len_front;
  r_wheel = b_norm(b_obj_wheel_width);

  /*  車椅子の回転中心から角の距離 */
  /* ----------------------------------------------- */
  emlrtMEXProfilingStatement(9, isMexOutdated);

  /*  歩行者の数 */
  emlrtMEXProfilingStatement(10, isMexOutdated);

  /*  歩行者の位置 */
  emlrtMEXProfilingStatement(11, isMexOutdated);
  loop_ub = obs_now_size[0];
  tmp_size[0] = obs_now_size[0];
  c_loop_ub = obs_now_size[2];
  tmp_size[2] = obs_now_size[2];
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      a_obs_data[i1 + tmp_size[0] * i] = obs_now_data[(i1 + obs_now_size[0] * 4)
        + obs_now_size[0] * 6 * i];
    }
  }

  /*  歩行者の横幅 */
  emlrtMEXProfilingStatement(12, isMexOutdated);

  /*  歩行者の縦幅 */
  emlrtMEXProfilingStatement(13, isMexOutdated);
  varargin_1_size[0] = obs_now_size[0];
  varargin_1_size[2] = obs_now_size[2];
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      tho_data[i1 + varargin_1_size[0] * i] = obs_now_data[(i1 + obs_now_size[0]
        * 2) + obs_now_size[0] * 6 * i];
    }
  }

  /*  歩行者が向いている方向 */
  /* ----------------------------------------------- */
  /*  目標位置 */
  /* ----------------------------------------------- */
  emlrtMEXProfilingStatement(15, isMexOutdated);
  maxval_tmp = muDoubleScalarMax(obj_ObsNum, 1.0);
  if (maxval_tmp != (int32_T)muDoubleScalarFloor(maxval_tmp)) {
    emlrtIntegerCheckR2012b(maxval_tmp, &ad_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (!(obj_K - 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj_K - 1.0, &yc_emlrtDCI, (emlrtConstCTX)sp);
  }

  d = (int32_T)muDoubleScalarFloor(obj_K - 1.0);
  if (obj_K - 1.0 != d) {
    emlrtIntegerCheckR2012b(obj_K - 1.0, &xc_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (!(obj_NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj_NP, &wc_emlrtDCI, (emlrtConstCTX)sp);
  }

  i = (int32_T)muDoubleScalarFloor(obj_NP);
  if (obj_NP != i) {
    emlrtIntegerCheckR2012b(obj_NP, &vc_emlrtDCI, (emlrtConstCTX)sp);
  }

  emxInit_real_T(sp, &PoQ3, 4, &ph_emlrtRTEI);
  i1 = PoQ3->size[0] * PoQ3->size[1] * PoQ3->size[2] * PoQ3->size[3];
  PoQ3->size[0] = (int32_T)maxval_tmp;
  PoQ3->size[1] = 1;
  loop_ub_tmp = (int32_T)(obj_K - 1.0);
  PoQ3->size[2] = (int32_T)(obj_K - 1.0);
  b_loop_ub_tmp = (int32_T)obj_NP;
  PoQ3->size[3] = (int32_T)obj_NP;
  emxEnsureCapacity_real_T(sp, PoQ3, i1, &td_emlrtRTEI);
  PoQ3_data = PoQ3->data;
  c_loop_ub_tmp = (int32_T)maxval_tmp * (int32_T)(obj_K - 1.0) * (int32_T)obj_NP;
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    PoQ3_data[i1] = 1.0;
  }

  /*  障害物のPFM       */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* --PMF of Goal (begin)----------------------------------------------------- */
  /*  PMF for the goal の最大値 */
  emlrtMEXProfilingStatement(17, isMexOutdated);

  /*  PMF for the goal の最小値 */
  /*  v1 次のwaypointがある方向を目標とする */
  /*  phig        = atan2((goal(1,2,:,:) - y),(goal(1,1,:,:) - x)) - th;      % 車椅子から見たgoal がある方向 */
  /*  phaierror   = atan2(sin(phig - 0),cos(phig - 0)); */
  /*  v2 waypointを結ぶ直線の方向を目標とする  */
  emlrtMEXProfilingStatement(18, isMexOutdated);
  sz[0] = 1.0;
  sz[1] = 1.0;
  sz[2] = obj_K - 1.0;
  sz[3] = obj_NP;
  st.site = &hc_emlrtRSI;
  nx = 20 * obj_target_n->size[1];
  b_st.site = &fc_emlrtRSI;
  b_assertValidSizeArg(&b_st, sz);
  b_sz[0] = 1;
  b_sz[1] = 1;
  b_sz[2] = (int32_T)(obj_K - 1.0);
  b_sz[3] = (int32_T)obj_NP;
  c_num2cell_vector(b_sz, c_sz);
  n = 20;
  if (obj_target_n->size[1] > 20) {
    n = obj_target_n->size[1];
  }

  n = muIntScalarMax_sint32(nx, n);
  if (c_sz[2] > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (c_sz[3] > n) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = (c_sz[2] >= 0);
  if ((!out) || (c_sz[3] < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (c_sz[2] * c_sz[3] != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_sz[0] = 1;
  b_sz[1] = 1;
  b_sz[2] = (int32_T)(obj_K - 1.0);
  b_sz[3] = (int32_T)obj_NP;
  st.site = &hc_emlrtRSI;
  b_indexShapeCheck(&st, obj_th_target_w_size, b_sz);
  emxInit_real_T(sp, &b_obj_target_n, 2, &ud_emlrtRTEI);
  i1 = b_obj_target_n->size[0] * b_obj_target_n->size[1];
  b_obj_target_n->size[0] = 20;
  d_loop_ub = obj_target_n->size[1];
  b_obj_target_n->size[1] = obj_target_n->size[1];
  emxEnsureCapacity_real_T(sp, b_obj_target_n, i1, &ud_emlrtRTEI);
  R_data = b_obj_target_n->data;
  for (i1 = 0; i1 < d_loop_ub; i1++) {
    for (i2 = 0; i2 < 20; i2++) {
      R_data[i2 + 20 * i1] = obj_target_n_data[(i2 + 21 * i1) + 1];
    }
  }

  c_loop_ub_tmp = (int32_T)(obj_K - 1.0) * (int32_T)obj_NP;
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    maxval_tmp = R_data[i1];
    if (maxval_tmp != (int32_T)muDoubleScalarFloor(maxval_tmp)) {
      emlrtIntegerCheckR2012b(maxval_tmp, &bd_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)maxval_tmp < 1) || ((int32_T)maxval_tmp > obj_th_target_w_size))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)maxval_tmp, 1, obj_th_target_w_size,
        &n_emlrtBCI, (emlrtConstCTX)sp);
    }
  }

  emlrtMEXProfilingStatement(19, isMexOutdated);
  if (((int32_T)(obj_K - 1.0) != th->size[2]) && (((int32_T)(obj_K - 1.0) != 1) &&
       (th->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b((int32_T)(obj_K - 1.0), th->size[2],
      &of_emlrtECI, (emlrtConstCTX)sp);
  }

  if (((int32_T)obj_NP != th->size[3]) && (((int32_T)obj_NP != 1) && (th->size[3]
        != 1))) {
    emlrtDimSizeImpxCheckR2021b((int32_T)obj_NP, th->size[3], &nf_emlrtECI,
      (emlrtConstCTX)sp);
  }

  emxInit_real_T(sp, &phig, 4, &wd_emlrtRTEI);
  if (((int32_T)(obj_K - 1.0) == th->size[2]) && ((int32_T)obj_NP == th->size[3]))
  {
    i1 = b_obj_target_n->size[0] * b_obj_target_n->size[1];
    b_obj_target_n->size[0] = 20;
    b_obj_target_n->size[1] = obj_target_n->size[1];
    emxEnsureCapacity_real_T(sp, b_obj_target_n, i1, &ud_emlrtRTEI);
    R_data = b_obj_target_n->data;
    for (i1 = 0; i1 < d_loop_ub; i1++) {
      for (i2 = 0; i2 < 20; i2++) {
        R_data[i2 + 20 * i1] = obj_target_n_data[(i2 + 21 * i1) + 1];
      }
    }

    i1 = phig->size[0] * phig->size[1] * phig->size[2] * phig->size[3];
    phig->size[0] = 1;
    phig->size[1] = 1;
    phig->size[2] = (int32_T)(obj_K - 1.0);
    phig->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, phig, i1, &wd_emlrtRTEI);
    phig_data = phig->data;
    for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
      phig_data[i1] = obj_th_target_w_data[(int32_T)R_data[i1] - 1] - th_data[i1];
    }
  } else {
    st.site = &qg_emlrtRSI;
    binary_expand_op_44(&st, phig, obj_th_target_w_data, obj_target_n, sz, th);
    phig_data = phig->data;
  }

  emxFree_real_T(sp, &b_obj_target_n);
  emlrtMEXProfilingStatement(20, isMexOutdated);
  emxInit_real_T(sp, &varargin_2, 4, &oe_emlrtRTEI);
  i1 = varargin_2->size[0] * varargin_2->size[1] * varargin_2->size[2] *
    varargin_2->size[3];
  varargin_2->size[0] = 1;
  varargin_2->size[1] = 1;
  varargin_2->size[2] = phig->size[2];
  varargin_2->size[3] = phig->size[3];
  emxEnsureCapacity_real_T(sp, varargin_2, i1, &vd_emlrtRTEI);
  R_data = varargin_2->data;
  c_loop_ub_tmp = phig->size[2] * phig->size[3];
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    R_data[i1] = phig_data[i1];
  }

  st.site = &ic_emlrtRSI;
  c_sin(&st, varargin_2);
  st.site = &ic_emlrtRSI;
  c_cos(&st, phig);
  emxInit_real_T(sp, &phaierror, 4, &fh_emlrtRTEI);
  st.site = &ic_emlrtRSI;
  b_atan2(&st, varargin_2, phig, phaierror);
  emlrtMEXProfilingStatement(21, isMexOutdated);
  a = -((1.0 - param_FPM_eta) / 3.1415926535897931);
  emxInit_real_T(sp, &grade_trgt, 4, &xd_emlrtRTEI);
  st.site = &jc_emlrtRSI;
  b_abs(&st, phaierror, grade_trgt);
  emxFree_real_T(sp, &phaierror);
  c_loop_ub_tmp = grade_trgt->size[2] * grade_trgt->size[3];
  i1 = grade_trgt->size[0] * grade_trgt->size[1] * grade_trgt->size[2] *
    grade_trgt->size[3];
  grade_trgt->size[0] = 1;
  grade_trgt->size[1] = 1;
  emxEnsureCapacity_real_T(sp, grade_trgt, i1, &xd_emlrtRTEI);
  grade_trgt_data = grade_trgt->data;
  xPageOffset = (c_loop_ub_tmp / 2) << 1;
  npages = xPageOffset - 2;
  for (i1 = 0; i1 <= npages; i1 += 2) {
    r = _mm_loadu_pd(&grade_trgt_data[i1]);
    _mm_storeu_pd(&grade_trgt_data[i1], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(a), r),
      _mm_set1_pd(1.0)));
  }

  for (i1 = xPageOffset; i1 < c_loop_ub_tmp; i1++) {
    grade_trgt_data[i1] = a * grade_trgt_data[i1] + 1.0;
  }

  /*  PMF of Goal */
  /* --PMF of Goal (end)------------------------------------------------------- */
  /* --PFM of Obstacle (begin)------------------------------------------------- */
  /*  Po 車両中心 */
  /*  Qo 歩行者中心 */
  /*  Q1 歩行者端円中心1 */
  /*  Q2 歩行者端円中心2 */
  emlrtMEXProfilingStatement(22, isMexOutdated);
  if (obj_ObsNum > 0.0) {
    __m128d r1;
    int32_T exOffset;
    int32_T f_loop_ub;

    /*  ---事前初期化------------------ */
    emlrtMEXProfilingStatement(23, isMexOutdated);
    i1 = (int32_T)muDoubleScalarFloor(obj_ObsNum);
    if (obj_ObsNum != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &uc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &tc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &sc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &rc_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(24, isMexOutdated);
    d_loop_ub = (int32_T)obj_ObsNum;
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &qc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &pc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &oc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &nc_emlrtDCI, (emlrtConstCTX)sp);
    }

    emxInit_real_T(sp, &phi_Q1, 4, &gh_emlrtRTEI);
    i2 = phi_Q1->size[0] * phi_Q1->size[1] * phi_Q1->size[2] * phi_Q1->size[3];
    phi_Q1->size[0] = d_loop_ub;
    phi_Q1->size[1] = 1;
    phi_Q1->size[2] = (int32_T)(obj_K - 1.0);
    phi_Q1->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, phi_Q1, i2, &ae_emlrtRTEI);
    phi_Q1_data = phi_Q1->data;
    c_loop_ub_tmp = d_loop_ub * (int32_T)(obj_K - 1.0) * (int32_T)obj_NP;
    for (i2 = 0; i2 < c_loop_ub_tmp; i2++) {
      phi_Q1_data[i2] = 0.0;
    }

    emlrtMEXProfilingStatement(25, isMexOutdated);
    emxInit_real_T(sp, &phi_Q2, 4, &ce_emlrtRTEI);
    i2 = phi_Q2->size[0] * phi_Q2->size[1] * phi_Q2->size[2] * phi_Q2->size[3];
    phi_Q2->size[0] = d_loop_ub;
    phi_Q2->size[1] = 1;
    phi_Q2->size[2] = (int32_T)(obj_K - 1.0);
    phi_Q2->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, phi_Q2, i2, &ce_emlrtRTEI);
    phi_Q2_data = phi_Q2->data;
    for (i2 = 0; i2 < c_loop_ub_tmp; i2++) {
      phi_Q2_data[i2] = 0.0;
    }

    emlrtMEXProfilingStatement(26, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &mc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &lc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &kc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &jc_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(27, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &ic_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &hc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &gc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &fc_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(28, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &ec_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &dc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &cc_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &bc_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(29, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &ac_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &yb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &xb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &wb_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(30, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &vb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &ub_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &tb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &sb_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(31, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &rb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &qb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &pb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &ob_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(32, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &nb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &mb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &lb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &kb_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(33, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &jb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &ib_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &hb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &gb_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(34, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &fb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &eb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &db_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &cb_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(35, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &bb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &ab_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &y_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &x_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(36, isMexOutdated);
    emxInit_real_T(sp, &z2, 4, &ee_emlrtRTEI);
    i2 = z2->size[0] * z2->size[1] * z2->size[2] * z2->size[3];
    z2->size[0] = d_loop_ub;
    z2->size[1] = 1;
    z2->size[2] = (int32_T)(obj_K - 1.0);
    z2->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, z2, i2, &ee_emlrtRTEI);
    z2_data = z2->data;
    for (i2 = 0; i2 < c_loop_ub_tmp; i2++) {
      z2_data[i2] = 0.0;
    }

    emlrtMEXProfilingStatement(37, isMexOutdated);
    emxInit_real_T(sp, &z3, 4, &fe_emlrtRTEI);
    i2 = z3->size[0] * z3->size[1] * z3->size[2] * z3->size[3];
    z3->size[0] = d_loop_ub;
    z3->size[1] = 1;
    z3->size[2] = (int32_T)(obj_K - 1.0);
    z3->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, z3, i2, &fe_emlrtRTEI);
    z3_data = z3->data;
    for (i2 = 0; i2 < c_loop_ub_tmp; i2++) {
      z3_data[i2] = 0.0;
    }

    emlrtMEXProfilingStatement(38, isMexOutdated);
    emxInit_real_T(sp, &z4, 4, &ge_emlrtRTEI);
    i2 = z4->size[0] * z4->size[1] * z4->size[2] * z4->size[3];
    z4->size[0] = d_loop_ub;
    z4->size[1] = 1;
    z4->size[2] = (int32_T)(obj_K - 1.0);
    z4->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, z4, i2, &ge_emlrtRTEI);
    z4_data = z4->data;
    for (i2 = 0; i2 < c_loop_ub_tmp; i2++) {
      z4_data[i2] = 0.0;
    }

    emlrtMEXProfilingStatement(39, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &w_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &v_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &u_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &t_emlrtDCI, (emlrtConstCTX)sp);
    }

    emlrtMEXProfilingStatement(40, isMexOutdated);
    if (d_loop_ub != i1) {
      emlrtIntegerCheckR2012b(obj_ObsNum, &s_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(obj_K - 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj_K - 1.0, &r_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (obj_K - 1.0 != d) {
      emlrtIntegerCheckR2012b(obj_K - 1.0, &q_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((int32_T)obj_NP != i) {
      emlrtIntegerCheckR2012b(obj_NP, &p_emlrtDCI, (emlrtConstCTX)sp);
    }

    /* ------------------------------- */
    emlrtMEXProfilingStatement(41, isMexOutdated);
    for (i = 0; i < c_loop_ub; i++) {
      xPageOffset = (obs_now_size[0] / 2) << 1;
      npages = xPageOffset - 2;
      for (i1 = 0; i1 <= npages; i1 += 2) {
        _mm_storeu_pd(&D_data[i1 + tmp_size[0] * i], _mm_add_pd(_mm_add_pd
          (_mm_set1_pd(obj_wheel_width), _mm_loadu_pd(&obs_now_data[(i1 +
          obs_now_size[0] * 5) + obs_now_size[0] * 6 * i])), _mm_set1_pd
          (param_FPM_margin)));
      }

      for (i1 = xPageOffset; i1 < loop_ub; i1++) {
        D_data[i1 + tmp_size[0] * i] = (obj_wheel_width + obs_now_data[(i1 +
          obs_now_size[0] * 5) + obs_now_size[0] * 6 * i]) + param_FPM_margin;
      }
    }

    emlrtMEXProfilingStatement(42, isMexOutdated);
    st.site = &kc_emlrtRSI;
    varargin_1_size[1] = 1;
    d_loop_ub_tmp = obs_now_size[0] * obs_now_size[2];
    if (d_loop_ub_tmp - 1 >= 0) {
      memcpy(&varargin_1_data[0], &tho_data[0], (uint32_T)d_loop_ub_tmp * sizeof
             (real_T));
    }

    b_st.site = &kc_emlrtRSI;
    d_sin(varargin_1_data, varargin_1_size);
    n = varargin_1_size[0] * varargin_1_size[2];
    xPageOffset = (n / 2) << 1;
    npages = xPageOffset - 2;
    for (i = 0; i <= npages; i += 2) {
      r = _mm_loadu_pd(&varargin_1_data[i]);
      _mm_storeu_pd(&varargin_1_data[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }

    for (i = xPageOffset; i < n; i++) {
      varargin_1_data[i] = -varargin_1_data[i];
    }

    tmp_size[1] = 1;
    if (d_loop_ub_tmp - 1 >= 0) {
      memcpy(&varargin_2_data[0], &tho_data[0], (uint32_T)d_loop_ub_tmp * sizeof
             (real_T));
    }

    b_st.site = &kc_emlrtRSI;
    d_cos(varargin_2_data, tmp_size);
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    if (tmp_size[0] != varargin_1_size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    c_st.site = &rd_emlrtRSI;
    if (tmp_size[2] != varargin_1_size[2]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    nx = varargin_1_size[0];
    exOffset = varargin_1_size[0];
    n = varargin_1_size[2];
    b_tmp_size[0] = varargin_1_size[0];
    b_tmp_size[1] = 2;
    b_tmp_size[2] = varargin_1_size[2];
    for (i = 0; i < n; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        tmp_data[i1 + b_tmp_size[0] * 2 * i] = varargin_1_data[i1 +
          varargin_1_size[0] * i];
      }
    }

    for (i = 0; i < n; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        tmp_data[(i1 + b_tmp_size[0]) + b_tmp_size[0] * 2 * i] =
          varargin_2_data[i1 + exOffset * i];
      }
    }

    st.site = &kc_emlrtRSI;
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    varargin_1_size[0] = obs_now_size[0];
    exOffset = obs_now_size[0];
    tmp_size[0] = obs_now_size[0];
    for (i = 0; i < c_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        maxval_tmp = obs_now_data[(i1 + obs_now_size[0] * 4) + obs_now_size[0] *
          6 * i];
        varargin_1_data[i1 + varargin_1_size[0] * i] = maxval_tmp;
        varargin_2_data[i1 + tmp_size[0] * i] = maxval_tmp;
      }
    }

    n = obs_now_size[0];
    tmp_size[1] = 2;
    tmp_size[2] = obs_now_size[2];
    for (i = 0; i < c_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_tmp_data[i1 + tmp_size[0] * 2 * i] = varargin_1_data[i1 + exOffset * i];
      }

      for (i1 = 0; i1 < loop_ub; i1++) {
        b_tmp_data[(i1 + tmp_size[0]) + tmp_size[0] * 2 * i] =
          varargin_2_data[i1 + n * i];
      }
    }

    if ((nx != obs_now_size[0]) && ((nx != 1) && (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(nx, obs_now_size[0], &mf_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((varargin_1_size[2] != obs_now_size[2]) && ((varargin_1_size[2] != 1) &&
         (obs_now_size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(varargin_1_size[2], obs_now_size[2],
        &lf_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((b_tmp_size[0] == obs_now_size[0]) && (varargin_1_size[2] ==
         obs_now_size[2])) {
      n = b_tmp_size[0] * 2 * varargin_1_size[2];
      xPageOffset = (n / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&tmp_data[i]);
        r1 = _mm_loadu_pd(&b_tmp_data[i]);
        _mm_storeu_pd(&tmp_data[i], _mm_mul_pd(r, r1));
      }

      for (i = xPageOffset; i < n; i++) {
        tmp_data[i] *= b_tmp_data[i];
      }
    } else {
      d_times(tmp_data, b_tmp_size, b_tmp_data, tmp_size);
    }

    e_loop_ub = b_tmp_size[0];
    if ((b_tmp_size[0] != obs_now_size[0]) && ((b_tmp_size[0] != 1) &&
         (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(b_tmp_size[0], obs_now_size[0], &mf_emlrtECI,
        (emlrtConstCTX)sp);
    }

    xOffset = b_tmp_size[2];
    if ((b_tmp_size[2] != obs_now_size[2]) && ((b_tmp_size[2] != 1) &&
         (obs_now_size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(b_tmp_size[2], obs_now_size[2], &lf_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((b_tmp_size[0] == obs_now_size[0]) && (b_tmp_size[1] == 2) &&
        (b_tmp_size[2] == obs_now_size[2])) {
      Q1_size[0] = b_tmp_size[0];
      Q1_size[1] = 2;
      Q1_size[2] = b_tmp_size[2];
      for (i = 0; i < xOffset; i++) {
        xPageOffset = (b_tmp_size[0] / 2) << 1;
        npages = xPageOffset - 2;
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 <= npages; i2 += 2) {
            r = _mm_loadu_pd(&tmp_data[(i2 + b_tmp_size[0] * i1) + b_tmp_size[0]
                             * 2 * i]);
            _mm_storeu_pd(&Q1_data[(i2 + Q1_size[0] * i1) + Q1_size[0] * 2 * i],
                          _mm_add_pd(r, _mm_loadu_pd(&obs_now_data[(i2 +
              obs_now_size[0] * i1) + obs_now_size[0] * 6 * i])));
          }

          for (i2 = xPageOffset; i2 < e_loop_ub; i2++) {
            Q1_data[(i2 + Q1_size[0] * i1) + Q1_size[0] * 2 * i] = tmp_data[(i2
              + b_tmp_size[0] * i1) + b_tmp_size[0] * 2 * i] + obs_now_data[(i2
              + obs_now_size[0] * i1) + obs_now_size[0] * 6 * i];
          }
        }
      }
    } else {
      binary_expand_op_42(Q1_data, Q1_size, tmp_data, b_tmp_size, obs_now_data,
                          obs_now_size);
    }

    emlrtMEXProfilingStatement(43, isMexOutdated);
    st.site = &lc_emlrtRSI;
    varargin_1_size[1] = 1;
    varargin_1_size[2] = obs_now_size[2];
    if (d_loop_ub_tmp - 1 >= 0) {
      memcpy(&varargin_1_data[0], &tho_data[0], (uint32_T)d_loop_ub_tmp * sizeof
             (real_T));
    }

    b_st.site = &lc_emlrtRSI;
    d_sin(varargin_1_data, varargin_1_size);
    d_loop_ub_tmp = varargin_1_size[0] * varargin_1_size[2];
    xPageOffset = (d_loop_ub_tmp / 2) << 1;
    npages = xPageOffset - 2;
    for (i = 0; i <= npages; i += 2) {
      r = _mm_loadu_pd(&varargin_1_data[i]);
      _mm_storeu_pd(&varargin_1_data[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }

    for (i = xPageOffset; i < d_loop_ub_tmp; i++) {
      varargin_1_data[i] = -varargin_1_data[i];
    }

    b_st.site = &lc_emlrtRSI;
    d_cos(tho_data, varargin_1_size);
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    nx = varargin_1_size[0];
    exOffset = varargin_1_size[0];
    n = varargin_1_size[2];
    b_tmp_size[0] = varargin_1_size[0];
    b_tmp_size[1] = 2;
    b_tmp_size[2] = varargin_1_size[2];
    for (i = 0; i < n; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        tmp_data[i1 + b_tmp_size[0] * 2 * i] = varargin_1_data[i1 +
          varargin_1_size[0] * i];
      }
    }

    for (i = 0; i < n; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        tmp_data[(i1 + b_tmp_size[0]) + b_tmp_size[0] * 2 * i] = tho_data[i1 +
          exOffset * i];
      }
    }

    st.site = &lc_emlrtRSI;
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    varargin_1_size[0] = obs_now_size[0];
    exOffset = obs_now_size[0];
    for (i = 0; i < c_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        maxval_tmp = obs_now_data[(i1 + obs_now_size[0] * 4) + obs_now_size[0] *
          6 * i];
        varargin_1_data[i1 + varargin_1_size[0] * i] = maxval_tmp;
        varargin_2_data[i1 + tmp_size[0] * i] = maxval_tmp;
      }
    }

    n = obs_now_size[0];
    tmp_size[1] = 2;
    for (i = 0; i < c_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_tmp_data[i1 + tmp_size[0] * 2 * i] = -varargin_1_data[i1 + exOffset *
          i];
      }

      for (i1 = 0; i1 < loop_ub; i1++) {
        b_tmp_data[(i1 + tmp_size[0]) + tmp_size[0] * 2 * i] =
          -varargin_2_data[i1 + n * i];
      }
    }

    if ((nx != obs_now_size[0]) && ((nx != 1) && (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(nx, obs_now_size[0], &kf_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((varargin_1_size[2] != obs_now_size[2]) && ((varargin_1_size[2] != 1) &&
         (obs_now_size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(varargin_1_size[2], obs_now_size[2],
        &jf_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((b_tmp_size[0] == obs_now_size[0]) && (varargin_1_size[2] ==
         obs_now_size[2])) {
      d_loop_ub_tmp = b_tmp_size[0] * 2 * varargin_1_size[2];
      xPageOffset = (d_loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&tmp_data[i]);
        r1 = _mm_loadu_pd(&b_tmp_data[i]);
        _mm_storeu_pd(&tmp_data[i], _mm_mul_pd(r, r1));
      }

      for (i = xPageOffset; i < d_loop_ub_tmp; i++) {
        tmp_data[i] *= b_tmp_data[i];
      }
    } else {
      d_times(tmp_data, b_tmp_size, b_tmp_data, tmp_size);
    }

    e_loop_ub = b_tmp_size[0];
    if ((b_tmp_size[0] != obs_now_size[0]) && ((b_tmp_size[0] != 1) &&
         (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(b_tmp_size[0], obs_now_size[0], &kf_emlrtECI,
        (emlrtConstCTX)sp);
    }

    xOffset = b_tmp_size[2];
    if ((b_tmp_size[2] != obs_now_size[2]) && ((b_tmp_size[2] != 1) &&
         (obs_now_size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(b_tmp_size[2], obs_now_size[2], &jf_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((b_tmp_size[0] == obs_now_size[0]) && (b_tmp_size[1] == 2) &&
        (b_tmp_size[2] == obs_now_size[2])) {
      Q2_size[0] = b_tmp_size[0];
      Q2_size[1] = 2;
      Q2_size[2] = b_tmp_size[2];
      for (i = 0; i < xOffset; i++) {
        xPageOffset = (b_tmp_size[0] / 2) << 1;
        npages = xPageOffset - 2;
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 <= npages; i2 += 2) {
            r = _mm_loadu_pd(&tmp_data[(i2 + b_tmp_size[0] * i1) + b_tmp_size[0]
                             * 2 * i]);
            _mm_storeu_pd(&Q2_data[(i2 + Q2_size[0] * i1) + Q2_size[0] * 2 * i],
                          _mm_add_pd(r, _mm_loadu_pd(&obs_now_data[(i2 +
              obs_now_size[0] * i1) + obs_now_size[0] * 6 * i])));
          }

          for (i2 = xPageOffset; i2 < e_loop_ub; i2++) {
            Q2_data[(i2 + Q2_size[0] * i1) + Q2_size[0] * 2 * i] = tmp_data[(i2
              + b_tmp_size[0] * i1) + b_tmp_size[0] * 2 * i] + obs_now_data[(i2
              + obs_now_size[0] * i1) + obs_now_size[0] * 6 * i];
          }
        }
      }
    } else {
      binary_expand_op_42(Q2_data, Q2_size, tmp_data, b_tmp_size, obs_now_data,
                          obs_now_size);
    }

    emlrtMEXProfilingStatement(44, isMexOutdated);
    if ((obs_now_size[2] != x->size[2]) && ((obs_now_size[2] != 1) && (x->size[2]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(obs_now_size[2], x->size[2], &if_emlrtECI,
        (emlrtConstCTX)sp);
    }

    emxInit_real_T(sp, &phi_Q2_l, 4, &hh_emlrtRTEI);
    emxInit_real_T(sp, &phiQo_global, 4, &lh_emlrtRTEI);
    emxInit_real_T(sp, &obs_now, 4, &ie_emlrtRTEI);
    if (obs_now_size[2] == Po->size[2]) {
      b_sz[0] = obs_now_size[0];
      for (i = 0; i < c_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          n = obs_now_size[0] * 6 * i;
          varargin_1_data[i1 + varargin_1_size[0] * i] = obs_now_data[(i1 +
            obs_now_size[0]) + n];
          varargin_2_data[i1 + tmp_size[0] * i] = obs_now_data[i1 + n];
        }
      }

      n = obs_now_size[0];
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[0] = obs_now_size[0];
      phi_Q2_l->size[1] = 1;
      phi_Q2_l->size[2] = obs_now_size[2];
      phi_Q2_l->size[3] = x->size[3];
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &he_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      i = obs_now->size[0] * obs_now->size[1] * obs_now->size[2] * obs_now->
        size[3];
      obs_now->size[0] = obs_now_size[0];
      obs_now->size[1] = 1;
      obs_now->size[2] = obs_now_size[2];
      obs_now->size[3] = x->size[3];
      emxEnsureCapacity_real_T(sp, obs_now, i, &ie_emlrtRTEI);
      Q2_2_data = obs_now->data;
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < c_loop_ub; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) + phi_Q2_l->size[0] *
              phi_Q2_l->size[2] * i] = varargin_1_data[i2 + b_sz[0] * i1] -
              Po_data[(2 * i1 + 2 * Po->size[2] * i) + 1];
          }
        }

        for (i1 = 0; i1 < c_loop_ub; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            Q2_2_data[(i2 + obs_now->size[0] * i1) + obs_now->size[0] *
              obs_now->size[2] * i] = varargin_2_data[i2 + n * i1] - Po_data[2 *
              i1 + 2 * Po->size[2] * i];
          }
        }
      }

      st.site = &mc_emlrtRSI;
      c_atan2(&st, phi_Q2_l, obs_now, phiQo_global);
      phiQo_global_data = phiQo_global->data;
    } else {
      st.site = &mc_emlrtRSI;
      binary_expand_op_41(&st, phiQo_global, mc_emlrtRSI, obs_now_data,
                          obs_now_size, Po);
      phiQo_global_data = phiQo_global->data;
    }

    emlrtMEXProfilingStatement(45, isMexOutdated);
    b_loop_ub = phiQo_global->size[2];
    if ((phiQo_global->size[2] != th->size[2]) && ((phiQo_global->size[2] != 1) &&
         (th->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo_global->size[2], th->size[2],
        &hf_emlrtECI, (emlrtConstCTX)sp);
    }

    e_loop_ub = phiQo_global->size[3];
    if ((phiQo_global->size[3] != th->size[3]) && ((phiQo_global->size[3] != 1) &&
         (th->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo_global->size[3], th->size[3],
        &gf_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phiQo_global->size[2] != th->size[2]) && ((phiQo_global->size[2] != 1) &&
         (th->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo_global->size[2], th->size[2],
        &ff_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phiQo_global->size[3] != th->size[3]) && ((phiQo_global->size[3] != 1) &&
         (th->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo_global->size[3], th->size[3],
        &ef_emlrtECI, (emlrtConstCTX)sp);
    }

    emxInit_real_T(sp, &r2, 4, &je_emlrtRTEI);
    if ((phiQo_global->size[2] == th->size[2]) && (phiQo_global->size[3] ==
         th->size[3])) {
      xOffset = phiQo_global->size[0];
      i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
      r2->size[0] = phiQo_global->size[0];
      r2->size[1] = 1;
      r2->size[2] = phiQo_global->size[2];
      r2->size[3] = phiQo_global->size[3];
      emxEnsureCapacity_real_T(sp, r2, i, &je_emlrtRTEI);
      Q2_2_data = r2->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          xPageOffset = (phiQo_global->size[0] / 2) << 1;
          npages = xPageOffset - 2;
          for (i2 = 0; i2 <= npages; i2 += 2) {
            r = _mm_loadu_pd(&phiQo_global_data[(i2 + phiQo_global->size[0] * i1)
                             + phiQo_global->size[0] * phiQo_global->size[2] * i]);
            _mm_storeu_pd(&Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] *
                          r2->size[2] * i], _mm_sub_pd(r, _mm_set1_pd(th_data[i1
              + th->size[2] * i])));
          }

          for (i2 = xPageOffset; i2 < xOffset; i2++) {
            Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] * r2->size[2] * i] =
              phiQo_global_data[(i2 + phiQo_global->size[0] * i1) +
              phiQo_global->size[0] * phiQo_global->size[2] * i] - th_data[i1 +
              th->size[2] * i];
          }
        }
      }
    } else {
      d_minus(sp, r2, phiQo_global, th);
    }

    st.site = &nc_emlrtRSI;
    e_sin(&st, r2);
    if ((phiQo_global->size[2] == th->size[2]) && (phiQo_global->size[3] ==
         th->size[3])) {
      b_loop_ub = phiQo_global->size[0];
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[0] = phiQo_global->size[0];
      phi_Q2_l->size[1] = 1;
      e_loop_ub = phiQo_global->size[2];
      phi_Q2_l->size[2] = phiQo_global->size[2];
      xOffset = phiQo_global->size[3];
      phi_Q2_l->size[3] = phiQo_global->size[3];
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &ke_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      for (i = 0; i < xOffset; i++) {
        for (i1 = 0; i1 < e_loop_ub; i1++) {
          xPageOffset = (phiQo_global->size[0] / 2) << 1;
          npages = xPageOffset - 2;
          for (i2 = 0; i2 <= npages; i2 += 2) {
            r = _mm_loadu_pd(&phiQo_global_data[(i2 + phiQo_global->size[0] * i1)
                             + phiQo_global->size[0] * phiQo_global->size[2] * i]);
            _mm_storeu_pd(&phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) +
                          phi_Q2_l->size[0] * phi_Q2_l->size[2] * i], _mm_sub_pd
                          (r, _mm_set1_pd(th_data[i1 + th->size[2] * i])));
          }

          for (i2 = xPageOffset; i2 < b_loop_ub; i2++) {
            phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) + phi_Q2_l->size[0] *
              phi_Q2_l->size[2] * i] = phiQo_global_data[(i2 +
              phiQo_global->size[0] * i1) + phiQo_global->size[0] *
              phiQo_global->size[2] * i] - th_data[i1 + th->size[2] * i];
          }
        }
      }

      i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
        phiQo_global->size[3];
      phiQo_global->size[0] = phi_Q2_l->size[0];
      phiQo_global->size[1] = 1;
      phiQo_global->size[2] = phi_Q2_l->size[2];
      phiQo_global->size[3] = phi_Q2_l->size[3];
      emxEnsureCapacity_real_T(sp, phiQo_global, i, &me_emlrtRTEI);
      phiQo_global_data = phiQo_global->data;
      d_loop_ub_tmp = phi_Q2_l->size[0] * phi_Q2_l->size[2] * phi_Q2_l->size[3];
      for (i = 0; i < d_loop_ub_tmp; i++) {
        phiQo_global_data[i] = phi_Q2_l_data[i];
      }
    } else {
      c_minus(sp, phiQo_global, th);
    }

    st.site = &nc_emlrtRSI;
    e_cos(&st, phiQo_global);
    emxInit_real_T(sp, &phiQo, 4, &mh_emlrtRTEI);
    st.site = &nc_emlrtRSI;
    d_atan2(&st, r2, phiQo_global, phiQo);
    phiQo_data = phiQo->data;

    /*  車両から見た歩行者が存在する方向 */
    /*  ---PoとQ1Q2の距離PoQ3とphi_Q3を計算------------------------------ */
    emlrtMEXProfilingStatement(46, isMexOutdated);
    emxInit_real_T(sp, &result, 4, &le_emlrtRTEI);
    st.site = &oc_emlrtRSI;
    i = phig->size[0] * phig->size[1] * phig->size[2] * phig->size[3];
    phig->size[0] = 1;
    phig->size[1] = 1;
    phig->size[2] = th->size[2];
    phig->size[3] = th->size[3];
    emxEnsureCapacity_real_T(&st, phig, i, &le_emlrtRTEI);
    phig_data = phig->data;
    d_loop_ub_tmp = th->size[2] * th->size[3];
    nx = (d_loop_ub_tmp / 2) << 1;
    exOffset = nx - 2;
    for (i = 0; i <= exOffset; i += 2) {
      _mm_storeu_pd(&phig_data[i], _mm_mul_pd(_mm_loadu_pd(&th_data[i]),
        _mm_set1_pd(-1.0)));
    }

    for (i = nx; i < d_loop_ub_tmp; i++) {
      phig_data[i] = -th_data[i];
    }

    b_st.site = &oc_emlrtRSI;
    c_cos(&b_st, phig);
    phig_data = phig->data;
    i = varargin_2->size[0] * varargin_2->size[1] * varargin_2->size[2] *
      varargin_2->size[3];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = 1;
    varargin_2->size[2] = th->size[2];
    varargin_2->size[3] = th->size[3];
    emxEnsureCapacity_real_T(&st, varargin_2, i, &ne_emlrtRTEI);
    R_data = varargin_2->data;
    for (i = 0; i <= exOffset; i += 2) {
      _mm_storeu_pd(&R_data[i], _mm_mul_pd(_mm_loadu_pd(&th_data[i]),
        _mm_set1_pd(-1.0)));
    }

    for (i = nx; i < d_loop_ub_tmp; i++) {
      R_data[i] = -th_data[i];
    }

    b_st.site = &oc_emlrtRSI;
    c_sin(&b_st, varargin_2);
    n = varargin_2->size[2] * varargin_2->size[3];
    i = varargin_2->size[0] * varargin_2->size[1] * varargin_2->size[2] *
      varargin_2->size[3];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = 1;
    emxEnsureCapacity_real_T(&st, varargin_2, i, &oe_emlrtRTEI);
    R_data = varargin_2->data;
    xPageOffset = (n / 2) << 1;
    npages = xPageOffset - 2;
    for (i = 0; i <= npages; i += 2) {
      r = _mm_loadu_pd(&R_data[i]);
      _mm_storeu_pd(&R_data[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }

    for (i = xPageOffset; i < n; i++) {
      R_data[i] = -R_data[i];
    }

    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    if (varargin_2->size[2] != phig->size[2]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    c_st.site = &rd_emlrtRSI;
    if (varargin_2->size[3] != phig->size[3]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    i = result->size[0] * result->size[1] * result->size[2] * result->size[3];
    result->size[0] = 1;
    result->size[1] = 2;
    b_loop_ub = phig->size[2];
    result->size[2] = phig->size[2];
    e_loop_ub = phig->size[3];
    result->size[3] = phig->size[3];
    emxEnsureCapacity_real_T(&b_st, result, i, &pe_emlrtRTEI);
    PoQ1_data = result->data;
    for (i = 0; i < e_loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        PoQ1_data[2 * i1 + 2 * result->size[2] * i] = phig_data[i1 + phig->size
          [2] * i];
      }
    }

    xOffset = varargin_2->size[3];
    for (i = 0; i < xOffset; i++) {
      f_loop_ub = varargin_2->size[2];
      for (i1 = 0; i1 < f_loop_ub; i1++) {
        PoQ1_data[(2 * i1 + 2 * result->size[2] * i) + 1] = R_data[i1 +
          varargin_2->size[2] * i];
      }
    }

    emxInit_real_T(sp, &b_result, 4, &qe_emlrtRTEI);
    st.site = &oc_emlrtRSI;
    i = phig->size[0] * phig->size[1] * phig->size[2] * phig->size[3];
    phig->size[0] = 1;
    phig->size[1] = 1;
    phig->size[2] = th->size[2];
    phig->size[3] = th->size[3];
    emxEnsureCapacity_real_T(&st, phig, i, &qe_emlrtRTEI);
    phig_data = phig->data;
    for (i = 0; i <= exOffset; i += 2) {
      _mm_storeu_pd(&phig_data[i], _mm_mul_pd(_mm_loadu_pd(&th_data[i]),
        _mm_set1_pd(-1.0)));
    }

    for (i = nx; i < d_loop_ub_tmp; i++) {
      phig_data[i] = -th_data[i];
    }

    b_st.site = &oc_emlrtRSI;
    c_sin(&b_st, phig);
    phig_data = phig->data;
    i = varargin_2->size[0] * varargin_2->size[1] * varargin_2->size[2] *
      varargin_2->size[3];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = 1;
    varargin_2->size[2] = th->size[2];
    varargin_2->size[3] = th->size[3];
    emxEnsureCapacity_real_T(&st, varargin_2, i, &re_emlrtRTEI);
    R_data = varargin_2->data;
    for (i = 0; i <= exOffset; i += 2) {
      _mm_storeu_pd(&R_data[i], _mm_mul_pd(_mm_loadu_pd(&th_data[i]),
        _mm_set1_pd(-1.0)));
    }

    for (i = nx; i < d_loop_ub_tmp; i++) {
      R_data[i] = -th_data[i];
    }

    b_st.site = &oc_emlrtRSI;
    c_cos(&b_st, varargin_2);
    R_data = varargin_2->data;
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    if (varargin_2->size[2] != phig->size[2]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    c_st.site = &rd_emlrtRSI;
    if (varargin_2->size[3] != phig->size[3]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    i = b_result->size[0] * b_result->size[1] * b_result->size[2] *
      b_result->size[3];
    b_result->size[0] = 1;
    b_result->size[1] = 2;
    xOffset = phig->size[2];
    b_result->size[2] = phig->size[2];
    f_loop_ub = phig->size[3];
    b_result->size[3] = phig->size[3];
    emxEnsureCapacity_real_T(&b_st, b_result, i, &pe_emlrtRTEI);
    Q2_2_data = b_result->data;
    for (i = 0; i < f_loop_ub; i++) {
      for (i1 = 0; i1 < xOffset; i1++) {
        Q2_2_data[2 * i1 + 2 * b_result->size[2] * i] = phig_data[i1 +
          phig->size[2] * i];
      }
    }

    n = varargin_2->size[3];
    for (i = 0; i < n; i++) {
      nx = varargin_2->size[2];
      for (i1 = 0; i1 < nx; i1++) {
        Q2_2_data[(2 * i1 + 2 * b_result->size[2] * i) + 1] = R_data[i1 +
          varargin_2->size[2] * i];
      }
    }

    st.site = &oc_emlrtRSI;
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    if (b_result->size[2] != result->size[2]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    c_st.site = &rd_emlrtRSI;
    if (b_result->size[3] != result->size[3]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    emxInit_real_T(&b_st, &R, 4, &se_emlrtRTEI);
    i = R->size[0] * R->size[1] * R->size[2] * R->size[3];
    R->size[0] = 2;
    R->size[1] = 2;
    R->size[2] = b_loop_ub;
    R->size[3] = e_loop_ub;
    emxEnsureCapacity_real_T(&b_st, R, i, &se_emlrtRTEI);
    R_data = R->data;
    for (i = 0; i < e_loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        R_data[4 * i1 + 4 * R->size[2] * i] = PoQ1_data[2 * i1 + 2 *
          result->size[2] * i];
        R_data[(4 * i1 + 4 * R->size[2] * i) + 2] = PoQ1_data[(2 * i1 + 2 *
          result->size[2] * i) + 1];
      }
    }

    emxFree_real_T(&b_st, &result);
    for (i = 0; i < f_loop_ub; i++) {
      for (i1 = 0; i1 < xOffset; i1++) {
        R_data[(4 * i1 + 4 * R->size[2] * i) + 1] = Q2_2_data[2 * i1 + 2 *
          b_result->size[2] * i];
        R_data[(4 * i1 + 4 * R->size[2] * i) + 3] = Q2_2_data[(2 * i1 + 2 *
          b_result->size[2] * i) + 1];
      }
    }

    emxFree_real_T(&b_st, &b_result);
    emlrtMEXProfilingStatement(47, isMexOutdated);
    b_loop_ub = Q1_size[2];
    if ((Q1_size[2] != Po->size[2]) && ((Q1_size[2] != 1) && (Po->size[2] != 1)))
    {
      emlrtDimSizeImpxCheckR2021b(Q1_size[2], Po->size[2], &df_emlrtECI,
        (emlrtConstCTX)sp);
    }

    emxInit_real_T(sp, &r3, 4, &sh_emlrtRTEI);
    emxInit_real_T(sp, &Q1, 4, &te_emlrtRTEI);
    if (Q1_size[2] == Po->size[2]) {
      f_loop_ub = Q1_size[0];
      b_sz[0] = Q1_size[0];
      i = Q1->size[0] * Q1->size[1] * Q1->size[2] * Q1->size[3];
      Q1->size[0] = Q1_size[0];
      Q1->size[1] = 2;
      Q1->size[2] = Q1_size[2];
      e_loop_ub = Po->size[3];
      Q1->size[3] = Po->size[3];
      emxEnsureCapacity_real_T(sp, Q1, i, &te_emlrtRTEI);
      R_data = Q1->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          for (i2 = 0; i2 < 2; i2++) {
            for (n = 0; n < f_loop_ub; n++) {
              R_data[((n + Q1->size[0] * i2) + Q1->size[0] * 2 * i1) + Q1->size
                [0] * 2 * Q1->size[2] * i] = Q1_data[(n + b_sz[0] * i2) + b_sz[0]
                * 2 * i1] - Po_data[(i2 + 2 * i1) + 2 * Po->size[2] * i];
            }
          }
        }
      }

      st.site = &pc_emlrtRSI;
      d_pagetranspose(&st, Q1, r3);
    } else {
      st.site = &pc_emlrtRSI;
      binary_expand_op_39(&st, r3, pc_emlrtRSI, Q1_data, Q1_size, Po);
    }

    emxInit_real_T(sp, &b_phiQo_global, 4, &xe_emlrtRTEI);
    st.site = &pc_emlrtRSI;
    pagemtimes(&st, R, r3, b_phiQo_global);
    emxInit_real_T(sp, &Q1_2, 4, &nh_emlrtRTEI);
    st.site = &pc_emlrtRSI;
    e_pagetranspose(&st, b_phiQo_global, Q1_2);
    phig_data = Q1_2->data;

    /*  車両から見たQ1の位置 */
    emlrtMEXProfilingStatement(48, isMexOutdated);
    b_loop_ub = Q2_size[2];
    if ((Q2_size[2] != Po->size[2]) && ((Q2_size[2] != 1) && (Po->size[2] != 1)))
    {
      emlrtDimSizeImpxCheckR2021b(Q2_size[2], Po->size[2], &cf_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (Q2_size[2] == Po->size[2]) {
      f_loop_ub = Q2_size[0];
      b_sz[0] = Q2_size[0];
      i = Q1->size[0] * Q1->size[1] * Q1->size[2] * Q1->size[3];
      Q1->size[0] = Q2_size[0];
      Q1->size[1] = 2;
      Q1->size[2] = Q2_size[2];
      e_loop_ub = Po->size[3];
      Q1->size[3] = Po->size[3];
      emxEnsureCapacity_real_T(sp, Q1, i, &ue_emlrtRTEI);
      R_data = Q1->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          for (i2 = 0; i2 < 2; i2++) {
            for (n = 0; n < f_loop_ub; n++) {
              R_data[((n + Q1->size[0] * i2) + Q1->size[0] * 2 * i1) + Q1->size
                [0] * 2 * Q1->size[2] * i] = Q2_data[(n + b_sz[0] * i2) + b_sz[0]
                * 2 * i1] - Po_data[(i2 + 2 * i1) + 2 * Po->size[2] * i];
            }
          }
        }
      }

      st.site = &qc_emlrtRSI;
      d_pagetranspose(&st, Q1, r3);
    } else {
      st.site = &qc_emlrtRSI;
      binary_expand_op_39(&st, r3, qc_emlrtRSI, Q2_data, Q2_size, Po);
    }

    st.site = &qc_emlrtRSI;
    pagemtimes(&st, R, r3, b_phiQo_global);
    emxFree_real_T(sp, &r3);
    emxFree_real_T(sp, &R);
    emxInit_real_T(sp, &Q2_2, 4, &oh_emlrtRTEI);
    st.site = &qc_emlrtRSI;
    e_pagetranspose(&st, b_phiQo_global, Q2_2);
    Q2_2_data = Q2_2->data;

    /*  車両から見たQ2の位置 */
    emlrtMEXProfilingStatement(49, isMexOutdated);
    if ((Q2_2->size[0] != Q1_2->size[0]) && ((Q2_2->size[0] != 1) && (Q1_2->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q2_2->size[0], Q1_2->size[0], &bf_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((Q2_2->size[1] != Q1_2->size[1]) && ((Q2_2->size[1] != 1) && (Q1_2->
          size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q2_2->size[1], Q1_2->size[1], &af_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((Q2_2->size[2] != Q1_2->size[2]) && ((Q2_2->size[2] != 1) && (Q1_2->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q2_2->size[2], Q1_2->size[2], &ye_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((Q2_2->size[3] != Q1_2->size[3]) && ((Q2_2->size[3] != 1) && (Q1_2->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q2_2->size[3], Q1_2->size[3], &xe_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((Q2_2->size[0] == Q1_2->size[0]) && (Q2_2->size[1] == Q1_2->size[1]) &&
        (Q2_2->size[2] == Q1_2->size[2]) && (Q2_2->size[3] == Q1_2->size[3])) {
      d_loop_ub_tmp = Q2_2->size[0] * Q2_2->size[1] * Q2_2->size[2] * Q2_2->
        size[3];
      xPageOffset = (d_loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&Q2_2_data[i]);
        r1 = _mm_loadu_pd(&phig_data[i]);
        _mm_storeu_pd(&Q2_2_data[i], _mm_sub_pd(r, r1));
      }

      for (i = xPageOffset; i < d_loop_ub_tmp; i++) {
        Q2_2_data[i] -= phig_data[i];
      }
    } else {
      st.site = &pg_emlrtRSI;
      b_minus(&st, Q2_2, Q1_2);
      Q2_2_data = Q2_2->data;
    }

    /*  ベクトル Q1 → Q2 */
    emlrtMEXProfilingStatement(50, isMexOutdated);
    st.site = &rc_emlrtRSI;
    b_st.site = &rc_emlrtRSI;
    dot(&b_st, Q1_2, Q2_2, phi_Q2_l);
    d_loop_ub_tmp = phi_Q2_l->size[0] * phi_Q2_l->size[2] * phi_Q2_l->size[3];
    i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
      phi_Q2_l->size[3];
    phi_Q2_l->size[1] = 1;
    emxEnsureCapacity_real_T(&st, phi_Q2_l, i, &ve_emlrtRTEI);
    phi_Q2_l_data = phi_Q2_l->data;
    xPageOffset = (d_loop_ub_tmp / 2) << 1;
    npages = xPageOffset - 2;
    for (i = 0; i <= npages; i += 2) {
      r = _mm_loadu_pd(&phi_Q2_l_data[i]);
      _mm_storeu_pd(&phi_Q2_l_data[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }

    for (i = xPageOffset; i < d_loop_ub_tmp; i++) {
      phi_Q2_l_data[i] = -phi_Q2_l_data[i];
    }

    b_st.site = &rc_emlrtRSI;
    dot(&b_st, Q2_2, Q2_2, phiQo_global);
    b_st.site = &qe_emlrtRSI;
    c_st.site = &re_emlrtRSI;
    assertCompatibleDims(&c_st, phi_Q2_l, phiQo_global);

    /*  内積を使って係数 t を計算 */
    emlrtMEXProfilingStatement(51, isMexOutdated);
    if ((phi_Q2_l->size[0] == phiQo_global->size[0]) && (phi_Q2_l->size[2] ==
         phiQo_global->size[2]) && (phi_Q2_l->size[3] == phiQo_global->size[3]))
    {
      d_loop_ub_tmp = phi_Q2_l->size[0] * phi_Q2_l->size[2] * phi_Q2_l->size[3];
      i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
        phiQo_global->size[3];
      phiQo_global->size[0] = phi_Q2_l->size[0];
      phiQo_global->size[1] = 1;
      phiQo_global->size[2] = phi_Q2_l->size[2];
      phiQo_global->size[3] = phi_Q2_l->size[3];
      emxEnsureCapacity_real_T(sp, phiQo_global, i, &we_emlrtRTEI);
      phiQo_global_data = phiQo_global->data;
      for (i = 0; i < d_loop_ub_tmp; i++) {
        maxval_tmp = phi_Q2_l_data[i] / phiQo_global_data[i];
        phiQo_global_data[i] = muDoubleScalarMax(0.0, muDoubleScalarMin(1.0,
          maxval_tmp));
      }
    } else {
      st.site = &ng_emlrtRSI;
      binary_expand_op_38(&st, phiQo_global, phi_Q2_l);
      phiQo_global_data = phiQo_global->data;
    }

    /*  t を 0 ≤ t ≤ 1 に制限 */
    emlrtMEXProfilingStatement(52, isMexOutdated);
    b_loop_ub = phiQo_global->size[0];
    if ((phiQo_global->size[0] != Q2_2->size[0]) && ((phiQo_global->size[0] != 1)
         && (Q2_2->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo_global->size[0], Q2_2->size[0],
        &we_emlrtECI, (emlrtConstCTX)sp);
    }

    e_loop_ub = phiQo_global->size[2];
    if ((phiQo_global->size[2] != Q2_2->size[2]) && ((phiQo_global->size[2] != 1)
         && (Q2_2->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo_global->size[2], Q2_2->size[2],
        &ve_emlrtECI, (emlrtConstCTX)sp);
    }

    xOffset = phiQo_global->size[3];
    if ((phiQo_global->size[3] != Q2_2->size[3]) && ((phiQo_global->size[3] != 1)
         && (Q2_2->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo_global->size[3], Q2_2->size[3],
        &ue_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phiQo_global->size[0] == Q2_2->size[0]) && (phiQo_global->size[2] ==
         Q2_2->size[2]) && (phiQo_global->size[3] == Q2_2->size[3])) {
      i = b_phiQo_global->size[0] * b_phiQo_global->size[1] *
        b_phiQo_global->size[2] * b_phiQo_global->size[3];
      b_phiQo_global->size[0] = phiQo_global->size[0];
      f_loop_ub = Q2_2->size[1];
      b_phiQo_global->size[1] = Q2_2->size[1];
      b_phiQo_global->size[2] = phiQo_global->size[2];
      b_phiQo_global->size[3] = phiQo_global->size[3];
      emxEnsureCapacity_real_T(sp, b_phiQo_global, i, &xe_emlrtRTEI);
      R_data = b_phiQo_global->data;
      for (i = 0; i < xOffset; i++) {
        for (i1 = 0; i1 < e_loop_ub; i1++) {
          for (i2 = 0; i2 < f_loop_ub; i2++) {
            xPageOffset = (phiQo_global->size[0] / 2) << 1;
            npages = xPageOffset - 2;
            for (n = 0; n <= npages; n += 2) {
              r = _mm_loadu_pd(&phiQo_global_data[(n + phiQo_global->size[0] *
                i1) + phiQo_global->size[0] * phiQo_global->size[2] * i]);
              r1 = _mm_loadu_pd(&Q2_2_data[((n + Q2_2->size[0] * i2) +
                Q2_2->size[0] * Q2_2->size[1] * i1) + Q2_2->size[0] * Q2_2->
                                size[1] * Q2_2->size[2] * i]);
              _mm_storeu_pd(&R_data[((n + b_phiQo_global->size[0] * i2) +
                b_phiQo_global->size[0] * b_phiQo_global->size[1] * i1) +
                            b_phiQo_global->size[0] * b_phiQo_global->size[1] *
                            b_phiQo_global->size[2] * i], _mm_mul_pd(r, r1));
            }

            for (n = xPageOffset; n < b_loop_ub; n++) {
              R_data[((n + b_phiQo_global->size[0] * i2) + b_phiQo_global->size
                      [0] * b_phiQo_global->size[1] * i1) + b_phiQo_global->
                size[0] * b_phiQo_global->size[1] * b_phiQo_global->size[2] * i]
                = phiQo_global_data[(n + phiQo_global->size[0] * i1) +
                phiQo_global->size[0] * phiQo_global->size[2] * i] * Q2_2_data
                [((n + Q2_2->size[0] * i2) + Q2_2->size[0] * Q2_2->size[1] * i1)
                + Q2_2->size[0] * Q2_2->size[1] * Q2_2->size[2] * i];
            }
          }
        }
      }

      i = Q2_2->size[0] * Q2_2->size[1] * Q2_2->size[2] * Q2_2->size[3];
      Q2_2->size[0] = b_phiQo_global->size[0];
      Q2_2->size[1] = b_phiQo_global->size[1];
      Q2_2->size[2] = b_phiQo_global->size[2];
      Q2_2->size[3] = b_phiQo_global->size[3];
      emxEnsureCapacity_real_T(sp, Q2_2, i, &xe_emlrtRTEI);
      Q2_2_data = Q2_2->data;
      d_loop_ub_tmp = b_phiQo_global->size[0] * b_phiQo_global->size[1] *
        b_phiQo_global->size[2] * b_phiQo_global->size[3];
      for (i = 0; i < d_loop_ub_tmp; i++) {
        Q2_2_data[i] = R_data[i];
      }
    } else {
      st.site = &og_emlrtRSI;
      c_times(&st, Q2_2, phiQo_global);
      Q2_2_data = Q2_2->data;
    }

    emxFree_real_T(sp, &b_phiQo_global);
    if ((Q1_2->size[0] != Q2_2->size[0]) && ((Q1_2->size[0] != 1) && (Q2_2->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q1_2->size[0], Q2_2->size[0], &te_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((Q1_2->size[1] != Q2_2->size[1]) && ((Q1_2->size[1] != 1) && (Q2_2->
          size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q1_2->size[1], Q2_2->size[1], &se_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((Q1_2->size[2] != Q2_2->size[2]) && ((Q1_2->size[2] != 1) && (Q2_2->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q1_2->size[2], Q2_2->size[2], &re_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((Q1_2->size[3] != Q2_2->size[3]) && ((Q1_2->size[3] != 1) && (Q2_2->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Q1_2->size[3], Q2_2->size[3], &qe_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((Q1_2->size[0] == Q2_2->size[0]) && (Q1_2->size[1] == Q2_2->size[1]) &&
        (Q1_2->size[2] == Q2_2->size[2]) && (Q1_2->size[3] == Q2_2->size[3])) {
      d_loop_ub_tmp = Q1_2->size[0] * Q1_2->size[1] * Q1_2->size[2] * Q1_2->
        size[3];
      xPageOffset = (d_loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&phig_data[i]);
        r1 = _mm_loadu_pd(&Q2_2_data[i]);
        _mm_storeu_pd(&phig_data[i], _mm_add_pd(r, r1));
      }

      for (i = xPageOffset; i < d_loop_ub_tmp; i++) {
        phig_data[i] += Q2_2_data[i];
      }
    } else {
      st.site = &og_emlrtRSI;
      f_plus(&st, Q1_2, Q2_2);
      phig_data = Q1_2->data;
    }

    emxFree_real_T(sp, &Q2_2);

    /*  交点の座標 */
    emlrtMEXProfilingStatement(53, isMexOutdated);
    st.site = &sc_emlrtRSI;
    vecnorm(&st, Q1_2, PoQ3);
    PoQ3_data = PoQ3->data;

    /*  原点からの最短距離 */
    emlrtMEXProfilingStatement(54, isMexOutdated);
    if (Q1_2->size[1] < 2) {
      emlrtDynamicBoundsCheckR2012b(2, 1, Q1_2->size[1], &m_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (Q1_2->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Q1_2->size[1], &l_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    b_loop_ub = Q1_2->size[0];
    i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
      phi_Q2_l->size[3];
    phi_Q2_l->size[0] = Q1_2->size[0];
    phi_Q2_l->size[1] = 1;
    e_loop_ub = Q1_2->size[2];
    phi_Q2_l->size[2] = Q1_2->size[2];
    xOffset = Q1_2->size[3];
    phi_Q2_l->size[3] = Q1_2->size[3];
    emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &ye_emlrtRTEI);
    phi_Q2_l_data = phi_Q2_l->data;
    i = obs_now->size[0] * obs_now->size[1] * obs_now->size[2] * obs_now->size[3];
    obs_now->size[0] = Q1_2->size[0];
    obs_now->size[1] = 1;
    obs_now->size[2] = Q1_2->size[2];
    obs_now->size[3] = Q1_2->size[3];
    emxEnsureCapacity_real_T(sp, obs_now, i, &af_emlrtRTEI);
    Q2_2_data = obs_now->data;
    for (i = 0; i < xOffset; i++) {
      for (i1 = 0; i1 < e_loop_ub; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) + phi_Q2_l->size[0] *
            phi_Q2_l->size[2] * i] = phig_data[((i2 + Q1_2->size[0]) +
            Q1_2->size[0] * Q1_2->size[1] * i1) + Q1_2->size[0] * Q1_2->size[1] *
            Q1_2->size[2] * i];
          Q2_2_data[(i2 + obs_now->size[0] * i1) + obs_now->size[0] *
            obs_now->size[2] * i] = phig_data[(i2 + Q1_2->size[0] * Q1_2->size[1]
            * i1) + Q1_2->size[0] * Q1_2->size[1] * Q1_2->size[2] * i];
        }
      }
    }

    emxFree_real_T(sp, &Q1_2);
    emxInit_real_T(sp, &phi_Q3, 4, &qh_emlrtRTEI);
    st.site = &tc_emlrtRSI;
    d_atan2(&st, phi_Q2_l, obs_now, phi_Q3);
    phi_Q3_data = phi_Q3->data;

    /*  車両から見た交点のある方向 */
    /*  ---------------------------------------------------------------- */
    emlrtMEXProfilingStatement(55, isMexOutdated);
    b_loop_ub = PoQ3->size[0];
    if ((PoQ3->size[0] != obs_now_size[0]) && ((PoQ3->size[0] != 1) &&
         (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[0], obs_now_size[0], &pe_emlrtECI,
        (emlrtConstCTX)sp);
    }

    e_loop_ub = PoQ3->size[2];
    if ((PoQ3->size[2] != obs_now_size[2]) && ((PoQ3->size[2] != 1) &&
         (obs_now_size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[2], obs_now_size[2], &oe_emlrtECI,
        (emlrtConstCTX)sp);
    }

    emxInit_boolean_T(sp, &idx, 4, &bf_emlrtRTEI);
    if ((PoQ3->size[0] == obs_now_size[0]) && (PoQ3->size[2] == obs_now_size[2]))
    {
      b_sz[0] = obs_now_size[0];
      i = idx->size[0] * idx->size[1] * idx->size[2] * idx->size[3];
      idx->size[0] = PoQ3->size[0];
      idx->size[1] = 1;
      idx->size[2] = PoQ3->size[2];
      xOffset = PoQ3->size[3];
      idx->size[3] = PoQ3->size[3];
      emxEnsureCapacity_boolean_T(sp, idx, i, &bf_emlrtRTEI);
      idx_data = idx->data;
      for (i = 0; i < xOffset; i++) {
        for (i1 = 0; i1 < e_loop_ub; i1++) {
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            idx_data[(i2 + idx->size[0] * i1) + idx->size[0] * idx->size[2] * i]
              = (PoQ3_data[(i2 + PoQ3->size[0] * i1) + PoQ3->size[0] *
                 PoQ3->size[2] * i] > D_data[i2 + b_sz[0] * i1]);
          }
        }
      }
    } else {
      st.site = &wg_emlrtRSI;
      binary_expand_op_37(&st, idx, PoQ3, D_data, tmp_size);
      idx_data = idx->data;
    }

    /*  --- 重なっていない場合-------------------------------------------- */
    emlrtMEXProfilingStatement(56, isMexOutdated);
    if ((phiQo->size[0] != idx->size[0]) && ((phiQo->size[0] != 1) && (idx->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[0], idx->size[0], &ne_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phiQo->size[2] != idx->size[2]) && ((phiQo->size[2] != 1) && (idx->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[2], idx->size[2], &me_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phiQo->size[3] != idx->size[3]) && ((phiQo->size[3] != 1) && (idx->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[3], idx->size[3], &le_emlrtECI,
        (emlrtConstCTX)sp);
    }

    emxInit_real_T(sp, &phi_o_n, 4, &cf_emlrtRTEI);
    if ((phiQo->size[0] == idx->size[0]) && (phiQo->size[2] == idx->size[2]) &&
        (phiQo->size[3] == idx->size[3])) {
      i = phi_o_n->size[0] * phi_o_n->size[1] * phi_o_n->size[2] * phi_o_n->
        size[3];
      phi_o_n->size[0] = phiQo->size[0];
      phi_o_n->size[1] = 1;
      phi_o_n->size[2] = phiQo->size[2];
      phi_o_n->size[3] = phiQo->size[3];
      emxEnsureCapacity_real_T(sp, phi_o_n, i, &cf_emlrtRTEI);
      R_data = phi_o_n->data;
      d_loop_ub_tmp = phiQo->size[0] * phiQo->size[2] * phiQo->size[3];
      for (i = 0; i < d_loop_ub_tmp; i++) {
        R_data[i] = phiQo_data[i] * (real_T)idx_data[i];
      }
    } else {
      st.site = &vg_emlrtRSI;
      binary_expand_op_36(&st, phi_o_n, phiQo, idx);
    }

    emlrtMEXProfilingStatement(57, isMexOutdated);
    if ((obs_now_size[2] != Po->size[2]) && ((obs_now_size[2] != 1) && (Po->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(obs_now_size[2], Po->size[2], &ke_emlrtECI,
        (emlrtConstCTX)sp);
    }

    emxInit_real_T(sp, &PoQo, 4, &ih_emlrtRTEI);
    if (obs_now_size[2] == Po->size[2]) {
      n = obs_now_size[0];
      for (i = 0; i < c_loop_ub; i++) {
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            tmp_data[(i2 + n * i1) + n * 2 * i] = obs_now_data[(i2 +
              obs_now_size[0] * i1) + obs_now_size[0] * 6 * i];
          }
        }
      }

      b_sz[0] = obs_now_size[0];
      i = Q1->size[0] * Q1->size[1] * Q1->size[2] * Q1->size[3];
      Q1->size[0] = obs_now_size[0];
      Q1->size[1] = 2;
      Q1->size[2] = obs_now_size[2];
      b_loop_ub = Po->size[3];
      Q1->size[3] = Po->size[3];
      emxEnsureCapacity_real_T(sp, Q1, i, &df_emlrtRTEI);
      R_data = Q1->data;
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < c_loop_ub; i1++) {
          for (i2 = 0; i2 < 2; i2++) {
            for (n = 0; n < loop_ub; n++) {
              R_data[((n + Q1->size[0] * i2) + Q1->size[0] * 2 * i1) + Q1->size
                [0] * 2 * Q1->size[2] * i] = tmp_data[(n + b_sz[0] * i2) + b_sz
                [0] * 2 * i1] - Po_data[(i2 + 2 * i1) + 2 * Po->size[2] * i];
            }
          }
        }
      }

      st.site = &uc_emlrtRSI;
      b_vecnorm(&st, Q1, PoQo);
      PoQo_data = PoQo->data;
    } else {
      st.site = &uc_emlrtRSI;
      binary_expand_op_35(&st, PoQo, uc_emlrtRSI, obs_now_data, obs_now_size, Po);
      PoQo_data = PoQo->data;
    }

    emlrtMEXProfilingStatement(58, isMexOutdated);
    b_loop_ub = Q1_size[2];
    if ((Q1_size[2] != Po->size[2]) && ((Q1_size[2] != 1) && (Po->size[2] != 1)))
    {
      emlrtDimSizeImpxCheckR2021b(Q1_size[2], Po->size[2], &je_emlrtECI,
        (emlrtConstCTX)sp);
    }

    emxInit_real_T(sp, &PoQ1, 4, &jh_emlrtRTEI);
    if (Q1_size[2] == Po->size[2]) {
      f_loop_ub = Q1_size[0];
      b_sz[0] = Q1_size[0];
      i = Q1->size[0] * Q1->size[1] * Q1->size[2] * Q1->size[3];
      Q1->size[0] = Q1_size[0];
      Q1->size[1] = 2;
      Q1->size[2] = Q1_size[2];
      e_loop_ub = Po->size[3];
      Q1->size[3] = Po->size[3];
      emxEnsureCapacity_real_T(sp, Q1, i, &ef_emlrtRTEI);
      R_data = Q1->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          for (i2 = 0; i2 < 2; i2++) {
            for (n = 0; n < f_loop_ub; n++) {
              R_data[((n + Q1->size[0] * i2) + Q1->size[0] * 2 * i1) + Q1->size
                [0] * 2 * Q1->size[2] * i] = Q1_data[(n + b_sz[0] * i2) + b_sz[0]
                * 2 * i1] - Po_data[(i2 + 2 * i1) + 2 * Po->size[2] * i];
            }
          }
        }
      }

      st.site = &vc_emlrtRSI;
      b_vecnorm(&st, Q1, PoQ1);
      PoQ1_data = PoQ1->data;
    } else {
      st.site = &vc_emlrtRSI;
      binary_expand_op_33(&st, PoQ1, vc_emlrtRSI, Q1_data, Q1_size, Po);
      PoQ1_data = PoQ1->data;
    }

    emlrtMEXProfilingStatement(59, isMexOutdated);
    b_loop_ub = Q2_size[2];
    if ((Q2_size[2] != Po->size[2]) && ((Q2_size[2] != 1) && (Po->size[2] != 1)))
    {
      emlrtDimSizeImpxCheckR2021b(Q2_size[2], Po->size[2], &ie_emlrtECI,
        (emlrtConstCTX)sp);
    }

    emxInit_real_T(sp, &PoQ2, 4, &kh_emlrtRTEI);
    if (Q2_size[2] == Po->size[2]) {
      f_loop_ub = Q2_size[0];
      b_sz[0] = Q2_size[0];
      i = Q1->size[0] * Q1->size[1] * Q1->size[2] * Q1->size[3];
      Q1->size[0] = Q2_size[0];
      Q1->size[1] = 2;
      Q1->size[2] = Q2_size[2];
      e_loop_ub = Po->size[3];
      Q1->size[3] = Po->size[3];
      emxEnsureCapacity_real_T(sp, Q1, i, &ff_emlrtRTEI);
      R_data = Q1->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          for (i2 = 0; i2 < 2; i2++) {
            for (n = 0; n < f_loop_ub; n++) {
              R_data[((n + Q1->size[0] * i2) + Q1->size[0] * 2 * i1) + Q1->size
                [0] * 2 * Q1->size[2] * i] = Q2_data[(n + b_sz[0] * i2) + b_sz[0]
                * 2 * i1] - Po_data[(i2 + 2 * i1) + 2 * Po->size[2] * i];
            }
          }
        }
      }

      st.site = &wc_emlrtRSI;
      b_vecnorm(&st, Q1, PoQ2);
      R_data = PoQ2->data;
    } else {
      st.site = &wc_emlrtRSI;
      binary_expand_op_33(&st, PoQ2, wc_emlrtRSI, Q2_data, Q2_size, Po);
      R_data = PoQ2->data;
    }

    emxFree_real_T(sp, &Q1);
    emlrtMEXProfilingStatement(60, isMexOutdated);
    b_loop_ub = phiQo->size[0];
    if ((phiQo->size[0] != obs_now_size[0]) && ((phiQo->size[0] != 1) &&
         (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[0], obs_now_size[0], &he_emlrtECI,
        (emlrtConstCTX)sp);
    }

    e_loop_ub = phiQo->size[2];
    if ((phiQo->size[2] != obs_now_size[2]) && ((phiQo->size[2] != 1) &&
         (obs_now_size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[2], obs_now_size[2], &ge_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phiQo->size[0] == obs_now_size[0]) && (phiQo->size[2] == obs_now_size[2]))
    {
      for (i = 0; i < c_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          varargin_1_data[i1 + varargin_1_size[0] * i] = obs_now_data[(i1 +
            obs_now_size[0] * 2) + obs_now_size[0] * 6 * i];
        }
      }

      b_sz[0] = obs_now_size[0];
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[0] = phiQo->size[0];
      phi_Q2_l->size[1] = 1;
      phi_Q2_l->size[2] = phiQo->size[2];
      xOffset = phiQo->size[3];
      phi_Q2_l->size[3] = phiQo->size[3];
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &gf_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      for (i = 0; i < xOffset; i++) {
        for (i1 = 0; i1 < e_loop_ub; i1++) {
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) + phi_Q2_l->size[0] *
              phi_Q2_l->size[2] * i] = phiQo_data[(i2 + phiQo->size[0] * i1) +
              phiQo->size[0] * phiQo->size[2] * i] - varargin_1_data[i2 + b_sz[0]
              * i1];
          }
        }
      }

      i = phiQo->size[0] * phiQo->size[1] * phiQo->size[2] * phiQo->size[3];
      phiQo->size[0] = b_loop_ub;
      phiQo->size[1] = 1;
      phiQo->size[2] = e_loop_ub;
      phiQo->size[3] = xOffset;
      emxEnsureCapacity_real_T(sp, phiQo, i, &gf_emlrtRTEI);
      phiQo_data = phiQo->data;
      d_loop_ub_tmp = phi_Q2_l->size[0] * phi_Q2_l->size[2] * phi_Q2_l->size[3];
      for (i = 0; i < d_loop_ub_tmp; i++) {
        phiQo_data[i] = phi_Q2_l_data[i];
      }
    } else {
      st.site = &xc_emlrtRSI;
      binary_expand_op_32(&st, phiQo, obs_now_data, obs_now_size);
      phiQo_data = phiQo->data;
    }

    b_loop_ub = phiQo->size[2];
    if ((phiQo->size[2] != th->size[2]) && ((phiQo->size[2] != 1) && (th->size[2]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[2], th->size[2], &ge_emlrtECI,
        (emlrtConstCTX)sp);
    }

    e_loop_ub = phiQo->size[3];
    if ((phiQo->size[3] != th->size[3]) && ((phiQo->size[3] != 1) && (th->size[3]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[3], th->size[3], &fe_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phiQo->size[2] == th->size[2]) && (phiQo->size[3] == th->size[3])) {
      xOffset = phiQo->size[0];
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[0] = phiQo->size[0];
      phi_Q2_l->size[1] = 1;
      phi_Q2_l->size[2] = phiQo->size[2];
      phi_Q2_l->size[3] = phiQo->size[3];
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &gf_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          xPageOffset = (phiQo->size[0] / 2) << 1;
          npages = xPageOffset - 2;
          for (i2 = 0; i2 <= npages; i2 += 2) {
            r = _mm_loadu_pd(&phiQo_data[(i2 + phiQo->size[0] * i1) +
                             phiQo->size[0] * phiQo->size[2] * i]);
            _mm_storeu_pd(&phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) +
                          phi_Q2_l->size[0] * phi_Q2_l->size[2] * i], _mm_add_pd
                          (r, _mm_set1_pd(th_data[i1 + th->size[2] * i])));
          }

          for (i2 = xPageOffset; i2 < xOffset; i2++) {
            phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) + phi_Q2_l->size[0] *
              phi_Q2_l->size[2] * i] = phiQo_data[(i2 + phiQo->size[0] * i1) +
              phiQo->size[0] * phiQo->size[2] * i] + th_data[i1 + th->size[2] *
              i];
          }
        }
      }

      i = phiQo->size[0] * phiQo->size[1] * phiQo->size[2] * phiQo->size[3];
      phiQo->size[0] = phi_Q2_l->size[0];
      phiQo->size[1] = 1;
      phiQo->size[2] = phi_Q2_l->size[2];
      phiQo->size[3] = phi_Q2_l->size[3];
      emxEnsureCapacity_real_T(sp, phiQo, i, &if_emlrtRTEI);
      phiQo_data = phiQo->data;
      d_loop_ub_tmp = phi_Q2_l->size[0] * phi_Q2_l->size[2] * phi_Q2_l->size[3];
      for (i = 0; i < d_loop_ub_tmp; i++) {
        phiQo_data[i] = phi_Q2_l_data[i];
      }
    } else {
      e_plus(sp, phiQo, th);
    }

    st.site = &xc_emlrtRSI;
    e_cos(&st, phiQo);
    st.site = &xc_emlrtRSI;
    b_sign(&st, phiQo);
    phiQo_data = phiQo->data;
    emlrtMEXProfilingStatement(61, isMexOutdated);
    st.site = &yc_emlrtRSI;
    b_st.site = &cf_emlrtRSI;
    i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
      phi_Q2_l->size[3];
    phi_Q2_l->size[0] = PoQo->size[0];
    phi_Q2_l->size[1] = 1;
    phi_Q2_l->size[2] = PoQo->size[2];
    phi_Q2_l->size[3] = PoQo->size[3];
    emxEnsureCapacity_real_T(&b_st, phi_Q2_l, i, &hf_emlrtRTEI);
    phi_Q2_l_data = phi_Q2_l->data;
    d_loop_ub_tmp = PoQo->size[0] * PoQo->size[2] * PoQo->size[3];
    for (i = 0; i < d_loop_ub_tmp; i++) {
      a = PoQo_data[i];
      phi_Q2_l_data[i] = a * a;
    }

    st.site = &yc_emlrtRSI;
    b_st.site = &cf_emlrtRSI;
    i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = PoQ1->size[0];
    r2->size[1] = 1;
    r2->size[2] = PoQ1->size[2];
    r2->size[3] = PoQ1->size[3];
    emxEnsureCapacity_real_T(&b_st, r2, i, &jf_emlrtRTEI);
    Q2_2_data = r2->data;
    n = PoQ1->size[0] * PoQ1->size[2] * PoQ1->size[3];
    for (i = 0; i < n; i++) {
      a = PoQ1_data[i];
      Q2_2_data[i] = a * a;
    }

    if ((PoQo->size[0] != PoQ1->size[0]) && ((PoQo->size[0] != 1) && (PoQ1->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQo->size[0], PoQ1->size[0], &de_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQo->size[2] != PoQ1->size[2]) && ((PoQo->size[2] != 1) && (PoQ1->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQo->size[2], PoQ1->size[2], &ce_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQo->size[3] != PoQ1->size[3]) && ((PoQo->size[3] != 1) && (PoQ1->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQo->size[3], PoQ1->size[3], &ee_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q2_l->size[0] == r2->size[0]) && (phi_Q2_l->size[2] == r2->size[2])
        && (phi_Q2_l->size[3] == r2->size[3])) {
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[1] = 1;
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &hf_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      xPageOffset = (d_loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&phi_Q2_l_data[i]);
        r1 = _mm_loadu_pd(&Q2_2_data[i]);
        _mm_storeu_pd(&phi_Q2_l_data[i], _mm_add_pd(r, r1));
      }

      for (i = xPageOffset; i < d_loop_ub_tmp; i++) {
        phi_Q2_l_data[i] += Q2_2_data[i];
      }
    } else {
      st.site = &yc_emlrtRSI;
      c_plus(&st, phi_Q2_l, r2);
      phi_Q2_l_data = phi_Q2_l->data;
    }

    st.site = &yc_emlrtRSI;
    power(a_obs_data, tmp_size, tho_data, varargin_1_size);
    b_loop_ub = phi_Q2_l->size[0];
    if ((phi_Q2_l->size[0] != varargin_1_size[0]) && ((phi_Q2_l->size[0] != 1) &&
         (varargin_1_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q2_l->size[0], varargin_1_size[0],
        &de_emlrtECI, (emlrtConstCTX)sp);
    }

    e_loop_ub = phi_Q2_l->size[2];
    if ((phi_Q2_l->size[2] != varargin_1_size[2]) && ((phi_Q2_l->size[2] != 1) &&
         (varargin_1_size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q2_l->size[2], varargin_1_size[2],
        &ce_emlrtECI, (emlrtConstCTX)sp);
    }

    emxInit_real_T(sp, &phi_o_l_n, 4, &hg_emlrtRTEI);
    i = phi_o_l_n->size[0] * phi_o_l_n->size[1] * phi_o_l_n->size[2] *
      phi_o_l_n->size[3];
    phi_o_l_n->size[0] = PoQo->size[0];
    phi_o_l_n->size[1] = 1;
    phi_o_l_n->size[2] = PoQo->size[2];
    phi_o_l_n->size[3] = PoQo->size[3];
    emxEnsureCapacity_real_T(sp, phi_o_l_n, i, &kf_emlrtRTEI);
    phig_data = phi_o_l_n->data;
    nx = (d_loop_ub_tmp / 2) << 1;
    exOffset = nx - 2;
    for (i = 0; i <= exOffset; i += 2) {
      r = _mm_loadu_pd(&PoQo_data[i]);
      _mm_storeu_pd(&phig_data[i], _mm_mul_pd(_mm_set1_pd(2.0), r));
    }

    for (i = nx; i < d_loop_ub_tmp; i++) {
      phig_data[i] = 2.0 * PoQo_data[i];
    }

    if ((phi_o_l_n->size[0] != PoQ1->size[0]) && ((phi_o_l_n->size[0] != 1) &&
         (PoQ1->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_l_n->size[0], PoQ1->size[0],
        &be_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_l_n->size[2] != PoQ1->size[2]) && ((phi_o_l_n->size[2] != 1) &&
         (PoQ1->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_l_n->size[2], PoQ1->size[2],
        &ae_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_l_n->size[3] != PoQ1->size[3]) && ((phi_o_l_n->size[3] != 1) &&
         (PoQ1->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_l_n->size[3], PoQ1->size[3],
        &yd_emlrtECI, (emlrtConstCTX)sp);
    }

    st.site = &yc_emlrtRSI;
    if ((phi_Q2_l->size[0] == varargin_1_size[0]) && (phi_Q2_l->size[2] ==
         varargin_1_size[2])) {
      b_sz[0] = varargin_1_size[0];
      i = obs_now->size[0] * obs_now->size[1] * obs_now->size[2] * obs_now->
        size[3];
      obs_now->size[0] = phi_Q2_l->size[0];
      obs_now->size[1] = 1;
      obs_now->size[2] = phi_Q2_l->size[2];
      xOffset = phi_Q2_l->size[3];
      obs_now->size[3] = phi_Q2_l->size[3];
      emxEnsureCapacity_real_T(&st, obs_now, i, &hf_emlrtRTEI);
      Q2_2_data = obs_now->data;
      for (i = 0; i < xOffset; i++) {
        for (i1 = 0; i1 < e_loop_ub; i1++) {
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            Q2_2_data[(i2 + obs_now->size[0] * i1) + obs_now->size[0] *
              obs_now->size[2] * i] = phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1)
              + phi_Q2_l->size[0] * phi_Q2_l->size[2] * i] - tho_data[i2 + b_sz
              [0] * i1];
          }
        }
      }

      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[0] = b_loop_ub;
      phi_Q2_l->size[1] = 1;
      phi_Q2_l->size[2] = e_loop_ub;
      phi_Q2_l->size[3] = xOffset;
      emxEnsureCapacity_real_T(&st, phi_Q2_l, i, &hf_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      n = obs_now->size[0] * obs_now->size[2] * obs_now->size[3];
      for (i = 0; i < n; i++) {
        phi_Q2_l_data[i] = Q2_2_data[i];
      }
    } else {
      b_st.site = &yc_emlrtRSI;
      binary_expand_op_29(&b_st, phi_Q2_l, tho_data, varargin_1_size);
      phi_Q2_l_data = phi_Q2_l->data;
    }

    if ((phi_o_l_n->size[0] == PoQ1->size[0]) && (phi_o_l_n->size[2] ==
         PoQ1->size[2]) && (phi_o_l_n->size[3] == PoQ1->size[3])) {
      i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
        phiQo_global->size[3];
      phiQo_global->size[0] = phi_o_l_n->size[0];
      phiQo_global->size[1] = 1;
      phiQo_global->size[2] = phi_o_l_n->size[2];
      phiQo_global->size[3] = phi_o_l_n->size[3];
      emxEnsureCapacity_real_T(&st, phiQo_global, i, &kf_emlrtRTEI);
      phiQo_global_data = phiQo_global->data;
      n = phi_o_l_n->size[0] * phi_o_l_n->size[2] * phi_o_l_n->size[3];
      xPageOffset = (n / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&phig_data[i]);
        r1 = _mm_loadu_pd(&PoQ1_data[i]);
        _mm_storeu_pd(&phiQo_global_data[i], _mm_mul_pd(r, r1));
      }

      for (i = xPageOffset; i < n; i++) {
        phiQo_global_data[i] = phig_data[i] * PoQ1_data[i];
      }
    } else {
      b_st.site = &yc_emlrtRSI;
      b_times(&b_st, phiQo_global, phi_o_l_n, PoQ1);
    }

    b_st.site = &qe_emlrtRSI;
    c_st.site = &re_emlrtRSI;
    assertCompatibleDims(&c_st, phi_Q2_l, phiQo_global);
    if ((phi_Q2_l->size[0] == phiQo_global->size[0]) && (phi_Q2_l->size[2] ==
         phiQo_global->size[2]) && (phi_Q2_l->size[3] == phiQo_global->size[3]))
    {
      n = phi_Q2_l->size[0] * phi_Q2_l->size[2] * phi_Q2_l->size[3];
      i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
        phiQo_global->size[3];
      phiQo_global->size[0] = phi_Q2_l->size[0];
      phiQo_global->size[1] = 1;
      phiQo_global->size[2] = phi_Q2_l->size[2];
      phiQo_global->size[3] = phi_Q2_l->size[3];
      emxEnsureCapacity_real_T(sp, phiQo_global, i, &lf_emlrtRTEI);
      phiQo_global_data = phiQo_global->data;
      for (i = 0; i < n; i++) {
        maxval_tmp = phi_Q2_l_data[i] / phiQo_global_data[i];
        phiQo_global_data[i] = muDoubleScalarMax(-1.0, muDoubleScalarMin(1.0,
          maxval_tmp));
      }
    } else {
      st.site = &ng_emlrtRSI;
      binary_expand_op_30(&st, phiQo_global, phi_Q2_l);
      phiQo_global_data = phiQo_global->data;
    }

    emlrtMEXProfilingStatement(62, isMexOutdated);
    st.site = &ad_emlrtRSI;
    b_st.site = &cf_emlrtRSI;
    i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
      phi_Q2_l->size[3];
    phi_Q2_l->size[0] = PoQo->size[0];
    phi_Q2_l->size[1] = 1;
    phi_Q2_l->size[2] = PoQo->size[2];
    phi_Q2_l->size[3] = PoQo->size[3];
    emxEnsureCapacity_real_T(&b_st, phi_Q2_l, i, &mf_emlrtRTEI);
    phi_Q2_l_data = phi_Q2_l->data;
    for (i = 0; i < d_loop_ub_tmp; i++) {
      a = PoQo_data[i];
      phi_Q2_l_data[i] = a * a;
    }

    st.site = &ad_emlrtRSI;
    b_st.site = &cf_emlrtRSI;
    i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = PoQ2->size[0];
    r2->size[1] = 1;
    r2->size[2] = PoQ2->size[2];
    r2->size[3] = PoQ2->size[3];
    emxEnsureCapacity_real_T(&b_st, r2, i, &nf_emlrtRTEI);
    Q2_2_data = r2->data;
    n = PoQ2->size[0] * PoQ2->size[2] * PoQ2->size[3];
    for (i = 0; i < n; i++) {
      a = R_data[i];
      Q2_2_data[i] = a * a;
    }

    if ((PoQo->size[0] != PoQ2->size[0]) && ((PoQo->size[0] != 1) && (PoQ2->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQo->size[0], PoQ2->size[0], &wd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQo->size[2] != PoQ2->size[2]) && ((PoQo->size[2] != 1) && (PoQ2->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQo->size[2], PoQ2->size[2], &vd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQo->size[3] != PoQ2->size[3]) && ((PoQo->size[3] != 1) && (PoQ2->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQo->size[3], PoQ2->size[3], &xd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q2_l->size[0] == r2->size[0]) && (phi_Q2_l->size[2] == r2->size[2])
        && (phi_Q2_l->size[3] == r2->size[3])) {
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[1] = 1;
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &mf_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      for (i = 0; i <= exOffset; i += 2) {
        r = _mm_loadu_pd(&phi_Q2_l_data[i]);
        r1 = _mm_loadu_pd(&Q2_2_data[i]);
        _mm_storeu_pd(&phi_Q2_l_data[i], _mm_add_pd(r, r1));
      }

      for (i = nx; i < d_loop_ub_tmp; i++) {
        phi_Q2_l_data[i] += Q2_2_data[i];
      }
    } else {
      st.site = &ad_emlrtRSI;
      c_plus(&st, phi_Q2_l, r2);
      phi_Q2_l_data = phi_Q2_l->data;
    }

    st.site = &ad_emlrtRSI;
    power(a_obs_data, tmp_size, tho_data, varargin_1_size);
    b_loop_ub = phi_Q2_l->size[0];
    if ((phi_Q2_l->size[0] != varargin_1_size[0]) && ((phi_Q2_l->size[0] != 1) &&
         (varargin_1_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q2_l->size[0], varargin_1_size[0],
        &wd_emlrtECI, (emlrtConstCTX)sp);
    }

    e_loop_ub = phi_Q2_l->size[2];
    if ((phi_Q2_l->size[2] != varargin_1_size[2]) && ((phi_Q2_l->size[2] != 1) &&
         (varargin_1_size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q2_l->size[2], varargin_1_size[2],
        &vd_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_l_n->size[0] != PoQ2->size[0]) && ((phi_o_l_n->size[0] != 1) &&
         (PoQ2->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_l_n->size[0], PoQ2->size[0],
        &ud_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_l_n->size[2] != PoQ2->size[2]) && ((phi_o_l_n->size[2] != 1) &&
         (PoQ2->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_l_n->size[2], PoQ2->size[2],
        &td_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_l_n->size[3] != PoQ2->size[3]) && ((phi_o_l_n->size[3] != 1) &&
         (PoQ2->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_l_n->size[3], PoQ2->size[3],
        &sd_emlrtECI, (emlrtConstCTX)sp);
    }

    st.site = &ad_emlrtRSI;
    if ((phi_Q2_l->size[0] == varargin_1_size[0]) && (phi_Q2_l->size[2] ==
         varargin_1_size[2])) {
      b_sz[0] = varargin_1_size[0];
      i = obs_now->size[0] * obs_now->size[1] * obs_now->size[2] * obs_now->
        size[3];
      obs_now->size[0] = phi_Q2_l->size[0];
      obs_now->size[1] = 1;
      obs_now->size[2] = phi_Q2_l->size[2];
      xOffset = phi_Q2_l->size[3];
      obs_now->size[3] = phi_Q2_l->size[3];
      emxEnsureCapacity_real_T(&st, obs_now, i, &mf_emlrtRTEI);
      Q2_2_data = obs_now->data;
      for (i = 0; i < xOffset; i++) {
        for (i1 = 0; i1 < e_loop_ub; i1++) {
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            Q2_2_data[(i2 + obs_now->size[0] * i1) + obs_now->size[0] *
              obs_now->size[2] * i] = phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1)
              + phi_Q2_l->size[0] * phi_Q2_l->size[2] * i] - tho_data[i2 + b_sz
              [0] * i1];
          }
        }
      }

      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[0] = b_loop_ub;
      phi_Q2_l->size[1] = 1;
      phi_Q2_l->size[2] = e_loop_ub;
      phi_Q2_l->size[3] = xOffset;
      emxEnsureCapacity_real_T(&st, phi_Q2_l, i, &mf_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      d_loop_ub_tmp = obs_now->size[0] * obs_now->size[2] * obs_now->size[3];
      for (i = 0; i < d_loop_ub_tmp; i++) {
        phi_Q2_l_data[i] = Q2_2_data[i];
      }
    } else {
      b_st.site = &ad_emlrtRSI;
      binary_expand_op_29(&b_st, phi_Q2_l, tho_data, varargin_1_size);
      phi_Q2_l_data = phi_Q2_l->data;
    }

    emxFree_real_T(&st, &obs_now);
    if ((phi_o_l_n->size[0] == PoQ2->size[0]) && (phi_o_l_n->size[2] ==
         PoQ2->size[2]) && (phi_o_l_n->size[3] == PoQ2->size[3])) {
      d_loop_ub_tmp = phi_o_l_n->size[0] * phi_o_l_n->size[2] * phi_o_l_n->size
        [3];
      i = phi_o_l_n->size[0] * phi_o_l_n->size[1] * phi_o_l_n->size[2] *
        phi_o_l_n->size[3];
      phi_o_l_n->size[1] = 1;
      emxEnsureCapacity_real_T(&st, phi_o_l_n, i, &of_emlrtRTEI);
      phig_data = phi_o_l_n->data;
      xPageOffset = (d_loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&phig_data[i]);
        r1 = _mm_loadu_pd(&R_data[i]);
        _mm_storeu_pd(&phig_data[i], _mm_mul_pd(r, r1));
      }

      for (i = xPageOffset; i < d_loop_ub_tmp; i++) {
        phig_data[i] *= R_data[i];
      }
    } else {
      b_st.site = &ad_emlrtRSI;
      times(&b_st, phi_o_l_n, PoQ2);
      phig_data = phi_o_l_n->data;
    }

    b_st.site = &qe_emlrtRSI;
    c_st.site = &re_emlrtRSI;
    assertCompatibleDims(&c_st, phi_Q2_l, phi_o_l_n);
    if ((phi_Q2_l->size[0] == phi_o_l_n->size[0]) && (phi_Q2_l->size[2] ==
         phi_o_l_n->size[2]) && (phi_Q2_l->size[3] == phi_o_l_n->size[3])) {
      i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
      r2->size[0] = phi_Q2_l->size[0];
      r2->size[1] = 1;
      r2->size[2] = phi_Q2_l->size[2];
      r2->size[3] = phi_Q2_l->size[3];
      emxEnsureCapacity_real_T(sp, r2, i, &pf_emlrtRTEI);
      Q2_2_data = r2->data;
      d_loop_ub_tmp = phi_Q2_l->size[0] * phi_Q2_l->size[2] * phi_Q2_l->size[3];
      for (i = 0; i < d_loop_ub_tmp; i++) {
        maxval_tmp = phi_Q2_l_data[i] / phig_data[i];
        Q2_2_data[i] = muDoubleScalarMax(-1.0, muDoubleScalarMin(1.0, maxval_tmp));
      }
    } else {
      st.site = &ng_emlrtRSI;
      binary_expand_op_28(&st, r2, phi_Q2_l, phi_o_l_n);
      Q2_2_data = r2->data;
    }

    b_sz[0] = d_loop_ub;
    b_sz[1] = 1;
    b_sz[2] = (int32_T)(obj_K - 1.0);
    b_sz[3] = (int32_T)obj_NP;
    emlrtSubAssignSizeCheckR2012b(&b_sz[0], 4, &r2->size[0], 4, &od_emlrtECI,
      (emlrtCTX)sp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          z2_data[(i2 + z2->size[0] * i1) + z2->size[0] * z2->size[2] * i] =
            Q2_2_data[(i2 + d_loop_ub * i1) + d_loop_ub * (int32_T)(obj_K - 1.0)
            * i];
        }
      }
    }

    emlrtMEXProfilingStatement(63, isMexOutdated);
    b_loop_ub = phiQo_global->size[0];
    i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = phiQo_global->size[0];
    r2->size[1] = 1;
    e_loop_ub = phiQo_global->size[2];
    r2->size[2] = phiQo_global->size[2];
    xOffset = phiQo_global->size[3];
    r2->size[3] = phiQo_global->size[3];
    emxEnsureCapacity_real_T(sp, r2, i, &qf_emlrtRTEI);
    Q2_2_data = r2->data;
    for (i = 0; i < xOffset; i++) {
      for (i1 = 0; i1 < e_loop_ub; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] * r2->size[2] * i] =
            phiQo_global_data[(i2 + phiQo_global->size[0] * i1) +
            phiQo_global->size[0] * phiQo_global->size[2] * i];
        }
      }
    }

    st.site = &bd_emlrtRSI;
    b_acos(&st, r2);
    b_loop_ub = phiQo->size[0];
    if ((phiQo->size[0] != r2->size[0]) && ((phiQo->size[0] != 1) && (r2->size[0]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[0], r2->size[0], &rd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    e_loop_ub = phiQo->size[2];
    if ((phiQo->size[2] != r2->size[2]) && ((phiQo->size[2] != 1) && (r2->size[2]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[2], r2->size[2], &qd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    xOffset = phiQo->size[3];
    if ((phiQo->size[3] != r2->size[3]) && ((phiQo->size[3] != 1) && (r2->size[3]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo->size[3], r2->size[3], &pd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phiQo->size[0] == r2->size[0]) && (phiQo->size[2] == r2->size[2]) &&
        (phiQo->size[3] == r2->size[3])) {
      i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
      r2->size[0] = phiQo->size[0];
      r2->size[1] = 1;
      r2->size[2] = phiQo->size[2];
      r2->size[3] = phiQo->size[3];
      emxEnsureCapacity_real_T(sp, r2, i, &rf_emlrtRTEI);
      Q2_2_data = r2->data;
      for (i = 0; i < xOffset; i++) {
        for (i1 = 0; i1 < e_loop_ub; i1++) {
          xPageOffset = (phiQo->size[0] / 2) << 1;
          npages = xPageOffset - 2;
          for (i2 = 0; i2 <= npages; i2 += 2) {
            r = _mm_loadu_pd(&phiQo_data[(i2 + phiQo->size[0] * i1) +
                             phiQo->size[0] * phiQo->size[2] * i]);
            r1 = _mm_loadu_pd(&Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] *
                              r2->size[2] * i]);
            _mm_storeu_pd(&Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] *
                          r2->size[2] * i], _mm_mul_pd(r, r1));
          }

          for (i2 = xPageOffset; i2 < b_loop_ub; i2++) {
            Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] * r2->size[2] * i] *=
              phiQo_data[(i2 + phiQo->size[0] * i1) + phiQo->size[0] *
              phiQo->size[2] * i];
          }
        }
      }
    } else {
      st.site = &bd_emlrtRSI;
      binary_expand_op_27(&st, r2, phiQo);
      Q2_2_data = r2->data;
    }

    b_sz[0] = d_loop_ub;
    b_sz[1] = 1;
    b_sz[2] = (int32_T)(obj_K - 1.0);
    b_sz[3] = (int32_T)obj_NP;
    emlrtSubAssignSizeCheckR2012b(&b_sz[0], 4, &r2->size[0], 4, &kd_emlrtECI,
      (emlrtCTX)sp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          phi_Q1_data[(i2 + phi_Q1->size[0] * i1) + phi_Q1->size[0] *
            phi_Q1->size[2] * i] = Q2_2_data[(i2 + d_loop_ub * i1) + d_loop_ub *
            (int32_T)(obj_K - 1.0) * i];
        }
      }
    }

    emlrtMEXProfilingStatement(64, isMexOutdated);
    b_loop_ub = phiQo->size[0];
    i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = phiQo->size[0];
    r2->size[1] = 1;
    e_loop_ub = phiQo->size[2];
    r2->size[2] = phiQo->size[2];
    xOffset = phiQo->size[3];
    r2->size[3] = phiQo->size[3];
    emxEnsureCapacity_real_T(sp, r2, i, &sf_emlrtRTEI);
    Q2_2_data = r2->data;
    for (i = 0; i < xOffset; i++) {
      for (i1 = 0; i1 < e_loop_ub; i1++) {
        xPageOffset = (phiQo->size[0] / 2) << 1;
        npages = xPageOffset - 2;
        for (i2 = 0; i2 <= npages; i2 += 2) {
          r = _mm_loadu_pd(&phiQo_data[(i2 + phiQo->size[0] * i1) + phiQo->size
                           [0] * phiQo->size[2] * i]);
          _mm_storeu_pd(&Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] *
                        r2->size[2] * i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
        }

        for (i2 = xPageOffset; i2 < b_loop_ub; i2++) {
          Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] * r2->size[2] * i] =
            -phiQo_data[(i2 + phiQo->size[0] * i1) + phiQo->size[0] *
            phiQo->size[2] * i];
        }
      }
    }

    emxFree_real_T(sp, &phiQo);
    i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
      phiQo_global->size[3];
    phiQo_global->size[0] = d_loop_ub;
    phiQo_global->size[1] = 1;
    phiQo_global->size[2] = (int32_T)(obj_K - 1.0);
    phiQo_global->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, phiQo_global, i, &tf_emlrtRTEI);
    phiQo_global_data = phiQo_global->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          phiQo_global_data[(i2 + phiQo_global->size[0] * i1) +
            phiQo_global->size[0] * phiQo_global->size[2] * i] = z2_data[(i2 +
            z2->size[0] * i1) + z2->size[0] * z2->size[2] * i];
        }
      }
    }

    st.site = &cd_emlrtRSI;
    b_acos(&st, phiQo_global);
    phiQo_global_data = phiQo_global->data;
    if ((r2->size[0] != phiQo_global->size[0]) && ((r2->size[0] != 1) &&
         (phiQo_global->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(r2->size[0], phiQo_global->size[0],
        &nd_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((r2->size[2] != phiQo_global->size[2]) && ((r2->size[2] != 1) &&
         (phiQo_global->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(r2->size[2], phiQo_global->size[2],
        &md_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((r2->size[3] != phiQo_global->size[3]) && ((r2->size[3] != 1) &&
         (phiQo_global->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(r2->size[3], phiQo_global->size[3],
        &ld_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((r2->size[0] == phiQo_global->size[0]) && (r2->size[2] ==
         phiQo_global->size[2]) && (r2->size[3] == phiQo_global->size[3])) {
      d_loop_ub_tmp = r2->size[0] * r2->size[2] * r2->size[3];
      i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
      r2->size[1] = 1;
      emxEnsureCapacity_real_T(sp, r2, i, &sf_emlrtRTEI);
      Q2_2_data = r2->data;
      xPageOffset = (d_loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&Q2_2_data[i]);
        r1 = _mm_loadu_pd(&phiQo_global_data[i]);
        _mm_storeu_pd(&Q2_2_data[i], _mm_mul_pd(r, r1));
      }

      for (i = xPageOffset; i < d_loop_ub_tmp; i++) {
        Q2_2_data[i] *= phiQo_global_data[i];
      }
    } else {
      st.site = &cd_emlrtRSI;
      times(&st, r2, phiQo_global);
      Q2_2_data = r2->data;
    }

    b_sz[0] = d_loop_ub;
    b_sz[1] = 1;
    b_sz[2] = (int32_T)(obj_K - 1.0);
    b_sz[3] = (int32_T)obj_NP;
    emlrtSubAssignSizeCheckR2012b(&b_sz[0], 4, &r2->size[0], 4, &cd_emlrtECI,
      (emlrtCTX)sp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          phi_Q2_data[(i2 + phi_Q2->size[0] * i1) + phi_Q2->size[0] *
            phi_Q2->size[2] * i] = Q2_2_data[(i2 + d_loop_ub * i1) + d_loop_ub *
            (int32_T)(obj_K - 1.0) * i];
        }
      }
    }

    emlrtMEXProfilingStatement(65, isMexOutdated);
    st.site = &dd_emlrtRSI;
    b_st.site = &qe_emlrtRSI;
    c_st.site = &re_emlrtRSI;
    b_assertCompatibleDims(&c_st, tmp_size, PoQ1);
    if ((obs_now_size[0] == PoQ1->size[0]) && (obs_now_size[2] == PoQ1->size[2]))
    {
      f_loop_ub = obs_now_size[0];
      b_sz[0] = obs_now_size[0];
      nx = obs_now_size[2];
      i = z2->size[0] * z2->size[1] * z2->size[2] * z2->size[3];
      z2->size[0] = obs_now_size[0];
      z2->size[1] = 1;
      z2->size[2] = obs_now_size[2];
      b_loop_ub = PoQ1->size[3];
      z2->size[3] = PoQ1->size[3];
      emxEnsureCapacity_real_T(sp, z2, i, &uf_emlrtRTEI);
      z2_data = z2->data;
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < nx; i1++) {
          for (i2 = 0; i2 < f_loop_ub; i2++) {
            z2_data[(i2 + z2->size[0] * i1) + z2->size[0] * z2->size[2] * i] =
              D_data[i2 + b_sz[0] * i1] / PoQ1_data[(i2 + PoQ1->size[0] * i1) +
              PoQ1->size[0] * PoQ1->size[2] * i];
          }
        }
      }

      i = PoQ1->size[0] * PoQ1->size[1] * PoQ1->size[2] * PoQ1->size[3];
      PoQ1->size[0] = obs_now_size[0];
      PoQ1->size[1] = 1;
      PoQ1->size[2] = obs_now_size[2];
      PoQ1->size[3] = b_loop_ub;
      emxEnsureCapacity_real_T(sp, PoQ1, i, &uf_emlrtRTEI);
      PoQ1_data = PoQ1->data;
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < nx; i1++) {
          for (i2 = 0; i2 < f_loop_ub; i2++) {
            PoQ1_data[(i2 + PoQ1->size[0] * i1) + PoQ1->size[0] * PoQ1->size[2] *
              i] = z2_data[(i2 + z2->size[0] * i1) + z2->size[0] * z2->size[2] *
              i];
          }
        }
      }

      i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
      r2->size[0] = obs_now_size[0];
      r2->size[1] = 1;
      r2->size[2] = obs_now_size[2];
      r2->size[3] = b_loop_ub;
      emxEnsureCapacity_real_T(sp, r2, i, &vf_emlrtRTEI);
      Q2_2_data = r2->data;
      d_loop_ub_tmp = PoQ1->size[0] * PoQ1->size[2] * PoQ1->size[3];
      for (i = 0; i < d_loop_ub_tmp; i++) {
        a = PoQ1_data[i];
        Q2_2_data[i] = muDoubleScalarMax(-1.0, muDoubleScalarMin(a, 1.0));
      }
    } else {
      st.site = &ng_emlrtRSI;
      binary_expand_op_25(&st, r2, D_data, tmp_size, PoQ1);
      Q2_2_data = r2->data;
    }

    emxFree_real_T(sp, &PoQ1);
    b_sz[0] = d_loop_ub;
    b_sz[1] = 1;
    b_sz[2] = (int32_T)(obj_K - 1.0);
    b_sz[3] = (int32_T)obj_NP;
    emlrtSubAssignSizeCheckR2012b(&b_sz[0], 4, &r2->size[0], 4, &jd_emlrtECI,
      (emlrtCTX)sp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          z3_data[(i2 + z3->size[0] * i1) + z3->size[0] * z3->size[2] * i] =
            Q2_2_data[(i2 + d_loop_ub * i1) + d_loop_ub * (int32_T)(obj_K - 1.0)
            * i];
        }
      }
    }

    emlrtMEXProfilingStatement(66, isMexOutdated);
    st.site = &ed_emlrtRSI;
    b_st.site = &qe_emlrtRSI;
    c_st.site = &re_emlrtRSI;
    b_assertCompatibleDims(&c_st, tmp_size, PoQ2);
    if ((obs_now_size[0] == PoQ2->size[0]) && (obs_now_size[2] == PoQ2->size[2]))
    {
      f_loop_ub = obs_now_size[0];
      b_sz[0] = obs_now_size[0];
      nx = obs_now_size[2];
      i = z2->size[0] * z2->size[1] * z2->size[2] * z2->size[3];
      z2->size[0] = obs_now_size[0];
      z2->size[1] = 1;
      z2->size[2] = obs_now_size[2];
      b_loop_ub = PoQ2->size[3];
      z2->size[3] = PoQ2->size[3];
      emxEnsureCapacity_real_T(sp, z2, i, &uf_emlrtRTEI);
      z2_data = z2->data;
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < nx; i1++) {
          for (i2 = 0; i2 < f_loop_ub; i2++) {
            z2_data[(i2 + z2->size[0] * i1) + z2->size[0] * z2->size[2] * i] =
              D_data[i2 + b_sz[0] * i1] / R_data[(i2 + PoQ2->size[0] * i1) +
              PoQ2->size[0] * PoQ2->size[2] * i];
          }
        }
      }

      i = PoQ2->size[0] * PoQ2->size[1] * PoQ2->size[2] * PoQ2->size[3];
      PoQ2->size[0] = obs_now_size[0];
      PoQ2->size[1] = 1;
      PoQ2->size[2] = obs_now_size[2];
      PoQ2->size[3] = b_loop_ub;
      emxEnsureCapacity_real_T(sp, PoQ2, i, &uf_emlrtRTEI);
      R_data = PoQ2->data;
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < nx; i1++) {
          for (i2 = 0; i2 < f_loop_ub; i2++) {
            R_data[(i2 + PoQ2->size[0] * i1) + PoQ2->size[0] * PoQ2->size[2] * i]
              = z2_data[(i2 + z2->size[0] * i1) + z2->size[0] * z2->size[2] * i];
          }
        }
      }

      i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
      r2->size[0] = obs_now_size[0];
      r2->size[1] = 1;
      r2->size[2] = obs_now_size[2];
      r2->size[3] = b_loop_ub;
      emxEnsureCapacity_real_T(sp, r2, i, &xf_emlrtRTEI);
      Q2_2_data = r2->data;
      d_loop_ub_tmp = PoQ2->size[0] * PoQ2->size[2] * PoQ2->size[3];
      for (i = 0; i < d_loop_ub_tmp; i++) {
        a = R_data[i];
        Q2_2_data[i] = muDoubleScalarMax(-1.0, muDoubleScalarMin(a, 1.0));
      }
    } else {
      st.site = &ng_emlrtRSI;
      binary_expand_op_25(&st, r2, D_data, tmp_size, PoQ2);
      Q2_2_data = r2->data;
    }

    emxFree_real_T(sp, &z2);
    emxFree_real_T(sp, &PoQ2);
    b_sz[0] = d_loop_ub;
    b_sz[1] = 1;
    b_sz[2] = (int32_T)(obj_K - 1.0);
    b_sz[3] = (int32_T)obj_NP;
    emlrtSubAssignSizeCheckR2012b(&b_sz[0], 4, &r2->size[0], 4, &bd_emlrtECI,
      (emlrtCTX)sp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          z4_data[(i2 + z4->size[0] * i1) + z4->size[0] * z4->size[2] * i] =
            Q2_2_data[(i2 + d_loop_ub * i1) + d_loop_ub * (int32_T)(obj_K - 1.0)
            * i];
        }
      }
    }

    emlrtMEXProfilingStatement(67, isMexOutdated);
    i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
      phiQo_global->size[3];
    phiQo_global->size[0] = d_loop_ub;
    phiQo_global->size[1] = 1;
    phiQo_global->size[2] = (int32_T)(obj_K - 1.0);
    phiQo_global->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, phiQo_global, i, &wf_emlrtRTEI);
    phiQo_global_data = phiQo_global->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          phiQo_global_data[(i2 + phiQo_global->size[0] * i1) +
            phiQo_global->size[0] * phiQo_global->size[2] * i] = z3_data[(i2 +
            z3->size[0] * i1) + z3->size[0] * z3->size[2] * i];
        }
      }
    }

    st.site = &fd_emlrtRSI;
    b_asin(&st, phiQo_global);
    if ((d_loop_ub != phiQo_global->size[0]) && ((obj_ObsNum != 1.0) &&
         (phiQo_global->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b((int32_T)obj_ObsNum, phiQo_global->size[0],
        &id_emlrtECI, (emlrtConstCTX)sp);
    }

    if (((int32_T)(obj_K - 1.0) != phiQo_global->size[2]) && (((int32_T)(obj_K -
           1.0) != 1) && (phiQo_global->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b((int32_T)(obj_K - 1.0), phiQo_global->size[2],
        &hd_emlrtECI, (emlrtConstCTX)sp);
    }

    if (((int32_T)obj_NP != phiQo_global->size[3]) && ((obj_NP != 1.0) &&
         (phiQo_global->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b((int32_T)obj_NP, phiQo_global->size[3],
        &gd_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_Q1->size[0] == phiQo_global->size[0]) && (phi_Q1->size[2] ==
         phiQo_global->size[2]) && (phi_Q1->size[3] == phiQo_global->size[3])) {
      i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
        phiQo_global->size[3];
      phiQo_global->size[0] = d_loop_ub;
      phiQo_global->size[1] = 1;
      phiQo_global->size[2] = (int32_T)(obj_K - 1.0);
      phiQo_global->size[3] = (int32_T)obj_NP;
      emxEnsureCapacity_real_T(sp, phiQo_global, i, &yf_emlrtRTEI);
      phiQo_global_data = phiQo_global->data;
      xPageOffset = (c_loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&phi_Q1_data[i]);
        r1 = _mm_loadu_pd(&phiQo_global_data[i]);
        _mm_storeu_pd(&phiQo_global_data[i], _mm_add_pd(r, r1));
      }

      for (i = xPageOffset; i < c_loop_ub_tmp; i++) {
        phiQo_global_data[i] += phi_Q1_data[i];
      }
    } else {
      st.site = &fd_emlrtRSI;
      d_plus(&st, phiQo_global, phi_Q1);
      phiQo_global_data = phiQo_global->data;
    }

    emlrtMEXProfilingStatement(68, isMexOutdated);
    i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = d_loop_ub;
    r2->size[1] = 1;
    r2->size[2] = (int32_T)(obj_K - 1.0);
    r2->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, r2, i, &ag_emlrtRTEI);
    Q2_2_data = r2->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] * r2->size[2] * i] =
            z3_data[(i2 + z3->size[0] * i1) + z3->size[0] * z3->size[2] * i];
        }
      }
    }

    emxFree_real_T(sp, &z3);
    st.site = &gd_emlrtRSI;
    b_asin(&st, r2);
    Q2_2_data = r2->data;
    if ((phi_Q1->size[0] != r2->size[0]) && ((phi_Q1->size[0] != 1) && (r2->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q1->size[0], r2->size[0], &fd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q1->size[2] != r2->size[2]) && ((phi_Q1->size[2] != 1) && (r2->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q1->size[2], r2->size[2], &ed_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q1->size[3] != r2->size[3]) && ((phi_Q1->size[3] != 1) && (r2->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q1->size[3], r2->size[3], &dd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q1->size[0] == r2->size[0]) && (phi_Q1->size[2] == r2->size[2]) &&
        (phi_Q1->size[3] == r2->size[3])) {
      d_loop_ub_tmp = phi_Q1->size[0] * phi_Q1->size[2] * phi_Q1->size[3];
      i = phi_Q1->size[0] * phi_Q1->size[1] * phi_Q1->size[2] * phi_Q1->size[3];
      phi_Q1->size[1] = 1;
      emxEnsureCapacity_real_T(sp, phi_Q1, i, &bg_emlrtRTEI);
      phi_Q1_data = phi_Q1->data;
      xPageOffset = (d_loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&phi_Q1_data[i]);
        r1 = _mm_loadu_pd(&Q2_2_data[i]);
        _mm_storeu_pd(&phi_Q1_data[i], _mm_sub_pd(r, r1));
      }

      for (i = xPageOffset; i < d_loop_ub_tmp; i++) {
        phi_Q1_data[i] -= Q2_2_data[i];
      }
    } else {
      st.site = &gd_emlrtRSI;
      minus(&st, phi_Q1, r2);
      phi_Q1_data = phi_Q1->data;
    }

    emlrtMEXProfilingStatement(69, isMexOutdated);
    i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
      phi_Q2_l->size[3];
    phi_Q2_l->size[0] = d_loop_ub;
    phi_Q2_l->size[1] = 1;
    phi_Q2_l->size[2] = (int32_T)(obj_K - 1.0);
    phi_Q2_l->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &cg_emlrtRTEI);
    phi_Q2_l_data = phi_Q2_l->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) + phi_Q2_l->size[0] *
            phi_Q2_l->size[2] * i] = z4_data[(i2 + z4->size[0] * i1) + z4->size
            [0] * z4->size[2] * i];
        }
      }
    }

    st.site = &hd_emlrtRSI;
    b_asin(&st, phi_Q2_l);
    if ((d_loop_ub != phi_Q2_l->size[0]) && ((obj_ObsNum != 1.0) &&
         (phi_Q2_l->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b((int32_T)obj_ObsNum, phi_Q2_l->size[0],
        &ad_emlrtECI, (emlrtConstCTX)sp);
    }

    if (((int32_T)(obj_K - 1.0) != phi_Q2_l->size[2]) && (((int32_T)(obj_K - 1.0)
          != 1) && (phi_Q2_l->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b((int32_T)(obj_K - 1.0), phi_Q2_l->size[2],
        &yc_emlrtECI, (emlrtConstCTX)sp);
    }

    if (((int32_T)obj_NP != phi_Q2_l->size[3]) && ((obj_NP != 1.0) &&
         (phi_Q2_l->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b((int32_T)obj_NP, phi_Q2_l->size[3],
        &xc_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_Q2->size[0] == phi_Q2_l->size[0]) && (phi_Q2->size[2] ==
         phi_Q2_l->size[2]) && (phi_Q2->size[3] == phi_Q2_l->size[3])) {
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[0] = d_loop_ub;
      phi_Q2_l->size[1] = 1;
      phi_Q2_l->size[2] = (int32_T)(obj_K - 1.0);
      phi_Q2_l->size[3] = (int32_T)obj_NP;
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &dg_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      xPageOffset = (c_loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&phi_Q2_data[i]);
        r1 = _mm_loadu_pd(&phi_Q2_l_data[i]);
        _mm_storeu_pd(&phi_Q2_l_data[i], _mm_add_pd(r, r1));
      }

      for (i = xPageOffset; i < c_loop_ub_tmp; i++) {
        phi_Q2_l_data[i] += phi_Q2_data[i];
      }
    } else {
      st.site = &hd_emlrtRSI;
      d_plus(&st, phi_Q2_l, phi_Q2);
      phi_Q2_l_data = phi_Q2_l->data;
    }

    emlrtMEXProfilingStatement(70, isMexOutdated);
    i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = d_loop_ub;
    r2->size[1] = 1;
    r2->size[2] = (int32_T)(obj_K - 1.0);
    r2->size[3] = (int32_T)obj_NP;
    emxEnsureCapacity_real_T(sp, r2, i, &eg_emlrtRTEI);
    Q2_2_data = r2->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          Q2_2_data[(i2 + r2->size[0] * i1) + r2->size[0] * r2->size[2] * i] =
            z4_data[(i2 + z4->size[0] * i1) + z4->size[0] * z4->size[2] * i];
        }
      }
    }

    emxFree_real_T(sp, &z4);
    st.site = &id_emlrtRSI;
    b_asin(&st, r2);
    Q2_2_data = r2->data;
    if ((phi_Q2->size[0] != r2->size[0]) && ((phi_Q2->size[0] != 1) && (r2->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q2->size[0], r2->size[0], &wc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q2->size[2] != r2->size[2]) && ((phi_Q2->size[2] != 1) && (r2->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q2->size[2], r2->size[2], &vc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q2->size[3] != r2->size[3]) && ((phi_Q2->size[3] != 1) && (r2->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q2->size[3], r2->size[3], &uc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q2->size[0] == r2->size[0]) && (phi_Q2->size[2] == r2->size[2]) &&
        (phi_Q2->size[3] == r2->size[3])) {
      loop_ub_tmp = phi_Q2->size[0] * phi_Q2->size[2] * phi_Q2->size[3];
      i = phi_Q2->size[0] * phi_Q2->size[1] * phi_Q2->size[2] * phi_Q2->size[3];
      phi_Q2->size[1] = 1;
      emxEnsureCapacity_real_T(sp, phi_Q2, i, &fg_emlrtRTEI);
      phi_Q2_data = phi_Q2->data;
      xPageOffset = (loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&phi_Q2_data[i]);
        r1 = _mm_loadu_pd(&Q2_2_data[i]);
        _mm_storeu_pd(&phi_Q2_data[i], _mm_sub_pd(r, r1));
      }

      for (i = xPageOffset; i < loop_ub_tmp; i++) {
        phi_Q2_data[i] -= Q2_2_data[i];
      }
    } else {
      st.site = &id_emlrtRSI;
      minus(&st, phi_Q2, r2);
      phi_Q2_data = phi_Q2->data;
    }

    emlrtMEXProfilingStatement(71, isMexOutdated);
    emxInit_real_T(sp, &c_result, 4, &rh_emlrtRTEI);
    st.site = &jd_emlrtRSI;
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    if (phi_Q2_l->size[0] != phiQo_global->size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    c_st.site = &rd_emlrtRSI;
    if (phi_Q2_l->size[2] != phiQo_global->size[2]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    c_st.site = &rd_emlrtRSI;
    if (phi_Q2_l->size[3] != phiQo_global->size[3]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    f_loop_ub = phiQo_global->size[0];
    b_sz[0] = phiQo_global->size[0];
    nx = phiQo_global->size[2];
    b_sz[2] = phiQo_global->size[2];
    n = phiQo_global->size[3];
    i = c_result->size[0] * c_result->size[1] * c_result->size[2] *
      c_result->size[3];
    c_result->size[0] = phiQo_global->size[0];
    c_result->size[1] = 2;
    c_result->size[2] = phiQo_global->size[2];
    c_result->size[3] = phiQo_global->size[3];
    emxEnsureCapacity_real_T(&b_st, c_result, i, &pe_emlrtRTEI);
    PoQ1_data = c_result->data;
    for (i = 0; i < n; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        for (i2 = 0; i2 < f_loop_ub; i2++) {
          PoQ1_data[(i2 + c_result->size[0] * c_result->size[1] * i1) +
            c_result->size[0] * c_result->size[1] * c_result->size[2] * i] =
            phiQo_global_data[(i2 + phiQo_global->size[0] * i1) +
            phiQo_global->size[0] * phiQo_global->size[2] * i];
        }
      }
    }

    for (i = 0; i < n; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        for (i2 = 0; i2 < f_loop_ub; i2++) {
          PoQ1_data[((i2 + c_result->size[0]) + c_result->size[0] *
                     c_result->size[1] * i1) + c_result->size[0] *
            c_result->size[1] * c_result->size[2] * i] = phi_Q2_l_data[(i2 +
            b_sz[0] * i1) + b_sz[0] * b_sz[2] * i];
        }
      }
    }

    st.site = &jd_emlrtRSI;
    b_st.site = &ff_emlrtRSI;
    c_st.site = &gf_emlrtRSI;
    d_st.site = &hf_emlrtRSI;
    e_st.site = &if_emlrtRSI;
    f_st.site = &jf_emlrtRSI;
    i = phi_o_l_n->size[0] * phi_o_l_n->size[1] * phi_o_l_n->size[2] *
      phi_o_l_n->size[3];
    phi_o_l_n->size[0] = c_result->size[0];
    phi_o_l_n->size[1] = 1;
    phi_o_l_n->size[2] = c_result->size[2];
    phi_o_l_n->size[3] = c_result->size[3];
    emxEnsureCapacity_real_T(&f_st, phi_o_l_n, i, &yd_emlrtRTEI);
    phig_data = phi_o_l_n->data;
    if ((c_result->size[0] == 0) || (c_result->size[2] == 0) || (c_result->size
         [3] == 0)) {
      i = phi_o_l_n->size[0] * phi_o_l_n->size[1] * phi_o_l_n->size[2] *
        phi_o_l_n->size[3];
      phi_o_l_n->size[0] = c_result->size[0];
      phi_o_l_n->size[1] = 1;
      phi_o_l_n->size[2] = c_result->size[2];
      phi_o_l_n->size[3] = c_result->size[3];
      emxEnsureCapacity_real_T(&f_st, phi_o_l_n, i, &gg_emlrtRTEI);
      phig_data = phi_o_l_n->data;
      loop_ub_tmp = c_result->size[0] * c_result->size[2] * c_result->size[3];
      for (i = 0; i < loop_ub_tmp; i++) {
        phig_data[i] = rtNaN;
      }
    } else {
      npages = c_result->size[2] * c_result->size[3];
      nx = c_result->size[0] << 1;
      g_st.site = &kf_emlrtRSI;
      if (npages > 2147483646) {
        h_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      for (d_loop_ub_tmp = 0; d_loop_ub_tmp < npages; d_loop_ub_tmp++) {
        exOffset = d_loop_ub_tmp * f_loop_ub;
        xPageOffset = d_loop_ub_tmp * nx;
        g_st.site = &lf_emlrtRSI;
        if (f_loop_ub > 2147483646) {
          h_st.site = &gb_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }

        for (e_loop_ub = 0; e_loop_ub < f_loop_ub; e_loop_ub++) {
          phig_data[exOffset + e_loop_ub] = PoQ1_data[xPageOffset + e_loop_ub];
        }

        g_st.site = &mf_emlrtRSI;
        xOffset = (xPageOffset + f_loop_ub) - 1;
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < 1; c_loop_ub_tmp++) {
          g_st.site = &nf_emlrtRSI;
          for (e_loop_ub = 0; e_loop_ub < f_loop_ub; e_loop_ub++) {
            n = exOffset + e_loop_ub;
            a = phig_data[n];
            maxval_tmp = PoQ1_data[(xOffset + e_loop_ub) + 1];
            if (muDoubleScalarIsNaN(maxval_tmp)) {
              out = false;
            } else if (muDoubleScalarIsNaN(a)) {
              out = true;
            } else {
              out = (a < maxval_tmp);
            }

            if (out) {
              phig_data[n] = maxval_tmp;
            }
          }
        }
      }
    }

    if ((c_result->size[0] != idx->size[0]) && ((c_result->size[0] != 1) &&
         (idx->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c_result->size[0], idx->size[0], &tc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((c_result->size[2] != idx->size[2]) && ((c_result->size[2] != 1) &&
         (idx->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c_result->size[2], idx->size[2], &sc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((c_result->size[3] != idx->size[3]) && ((c_result->size[3] != 1) &&
         (idx->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c_result->size[3], idx->size[3], &rc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_o_l_n->size[0] == idx->size[0]) && (phi_o_l_n->size[2] == idx->
         size[2]) && (phi_o_l_n->size[3] == idx->size[3])) {
      loop_ub_tmp = phi_o_l_n->size[0] * phi_o_l_n->size[2] * phi_o_l_n->size[3];
      i = phi_o_l_n->size[0] * phi_o_l_n->size[1] * phi_o_l_n->size[2] *
        phi_o_l_n->size[3];
      phi_o_l_n->size[1] = 1;
      emxEnsureCapacity_real_T(sp, phi_o_l_n, i, &hg_emlrtRTEI);
      phig_data = phi_o_l_n->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        phig_data[i] *= (real_T)idx_data[i];
      }
    } else {
      st.site = &jd_emlrtRSI;
      binary_expand_op_16(&st, phi_o_l_n, idx);
    }

    emlrtMEXProfilingStatement(72, isMexOutdated);
    st.site = &kd_emlrtRSI;
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    if (phi_Q2->size[0] != phi_Q1->size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    c_st.site = &rd_emlrtRSI;
    if (phi_Q2->size[2] != phi_Q1->size[2]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    c_st.site = &rd_emlrtRSI;
    if (phi_Q2->size[3] != phi_Q1->size[3]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    f_loop_ub = phi_Q1->size[0];
    b_sz[0] = phi_Q1->size[0];
    nx = phi_Q1->size[2];
    b_sz[2] = phi_Q1->size[2];
    n = phi_Q1->size[3];
    i = c_result->size[0] * c_result->size[1] * c_result->size[2] *
      c_result->size[3];
    c_result->size[0] = phi_Q1->size[0];
    c_result->size[1] = 2;
    c_result->size[2] = phi_Q1->size[2];
    c_result->size[3] = phi_Q1->size[3];
    emxEnsureCapacity_real_T(&b_st, c_result, i, &pe_emlrtRTEI);
    PoQ1_data = c_result->data;
    for (i = 0; i < n; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        for (i2 = 0; i2 < f_loop_ub; i2++) {
          PoQ1_data[(i2 + c_result->size[0] * c_result->size[1] * i1) +
            c_result->size[0] * c_result->size[1] * c_result->size[2] * i] =
            phi_Q1_data[(i2 + phi_Q1->size[0] * i1) + phi_Q1->size[0] *
            phi_Q1->size[2] * i];
        }
      }
    }

    emxFree_real_T(&b_st, &phi_Q1);
    for (i = 0; i < n; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        for (i2 = 0; i2 < f_loop_ub; i2++) {
          PoQ1_data[((i2 + c_result->size[0]) + c_result->size[0] *
                     c_result->size[1] * i1) + c_result->size[0] *
            c_result->size[1] * c_result->size[2] * i] = phi_Q2_data[(i2 + b_sz
            [0] * i1) + b_sz[0] * b_sz[2] * i];
        }
      }
    }

    emxFree_real_T(&b_st, &phi_Q2);
    st.site = &kd_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    c_st.site = &pf_emlrtRSI;
    d_st.site = &qf_emlrtRSI;
    e_st.site = &if_emlrtRSI;
    f_st.site = &jf_emlrtRSI;
    i = PoQo->size[0] * PoQo->size[1] * PoQo->size[2] * PoQo->size[3];
    PoQo->size[0] = c_result->size[0];
    PoQo->size[1] = 1;
    PoQo->size[2] = c_result->size[2];
    PoQo->size[3] = c_result->size[3];
    emxEnsureCapacity_real_T(&f_st, PoQo, i, &yd_emlrtRTEI);
    PoQo_data = PoQo->data;
    if ((c_result->size[0] == 0) || (c_result->size[2] == 0) || (c_result->size
         [3] == 0)) {
      i = PoQo->size[0] * PoQo->size[1] * PoQo->size[2] * PoQo->size[3];
      PoQo->size[0] = c_result->size[0];
      PoQo->size[1] = 1;
      PoQo->size[2] = c_result->size[2];
      PoQo->size[3] = c_result->size[3];
      emxEnsureCapacity_real_T(&f_st, PoQo, i, &ig_emlrtRTEI);
      PoQo_data = PoQo->data;
      loop_ub_tmp = c_result->size[0] * c_result->size[2] * c_result->size[3];
      for (i = 0; i < loop_ub_tmp; i++) {
        PoQo_data[i] = rtNaN;
      }
    } else {
      npages = c_result->size[2] * c_result->size[3];
      nx = c_result->size[0] << 1;
      g_st.site = &kf_emlrtRSI;
      if (npages > 2147483646) {
        h_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      for (d_loop_ub_tmp = 0; d_loop_ub_tmp < npages; d_loop_ub_tmp++) {
        exOffset = d_loop_ub_tmp * f_loop_ub;
        xPageOffset = d_loop_ub_tmp * nx;
        g_st.site = &lf_emlrtRSI;
        if (f_loop_ub > 2147483646) {
          h_st.site = &gb_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }

        for (e_loop_ub = 0; e_loop_ub < f_loop_ub; e_loop_ub++) {
          PoQo_data[exOffset + e_loop_ub] = PoQ1_data[xPageOffset + e_loop_ub];
        }

        g_st.site = &mf_emlrtRSI;
        xOffset = (xPageOffset + f_loop_ub) - 1;
        for (c_loop_ub_tmp = 0; c_loop_ub_tmp < 1; c_loop_ub_tmp++) {
          g_st.site = &nf_emlrtRSI;
          for (e_loop_ub = 0; e_loop_ub < f_loop_ub; e_loop_ub++) {
            n = exOffset + e_loop_ub;
            a = PoQo_data[n];
            maxval_tmp = PoQ1_data[(xOffset + e_loop_ub) + 1];
            if (muDoubleScalarIsNaN(maxval_tmp)) {
              out = false;
            } else if (muDoubleScalarIsNaN(a)) {
              out = true;
            } else {
              out = (a > maxval_tmp);
            }

            if (out) {
              PoQo_data[n] = maxval_tmp;
            }
          }
        }
      }
    }

    if ((c_result->size[0] != idx->size[0]) && ((c_result->size[0] != 1) &&
         (idx->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c_result->size[0], idx->size[0], &qc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((c_result->size[2] != idx->size[2]) && ((c_result->size[2] != 1) &&
         (idx->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c_result->size[2], idx->size[2], &pc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((c_result->size[3] != idx->size[3]) && ((c_result->size[3] != 1) &&
         (idx->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c_result->size[3], idx->size[3], &oc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    emxFree_real_T(sp, &c_result);
    if ((PoQo->size[0] == idx->size[0]) && (PoQo->size[2] == idx->size[2]) &&
        (PoQo->size[3] == idx->size[3])) {
      loop_ub_tmp = PoQo->size[0] * PoQo->size[2] * PoQo->size[3];
      i = PoQo->size[0] * PoQo->size[1] * PoQo->size[2] * PoQo->size[3];
      PoQo->size[1] = 1;
      emxEnsureCapacity_real_T(sp, PoQo, i, &jg_emlrtRTEI);
      PoQo_data = PoQo->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        PoQo_data[i] *= (real_T)idx_data[i];
      }
    } else {
      st.site = &kd_emlrtRSI;
      binary_expand_op_16(&st, PoQo, idx);
    }

    /*  ----------------------------------------------------------------- */
    /*  ---重なっている場合------------------------------------------------ */
    emlrtMEXProfilingStatement(73, isMexOutdated);
    emlrtMEXProfilingStatement(74, isMexOutdated);
    st.site = &ld_emlrtRSI;
    b_st.site = &qe_emlrtRSI;
    c_st.site = &re_emlrtRSI;
    c_assertCompatibleDims(&c_st, PoQ3, tmp_size);
    emlrtMEXProfilingStatement(75, isMexOutdated);
    if ((PoQ3->size[0] == obs_now_size[0]) && (PoQ3->size[2] == obs_now_size[2]))
    {
      b_sz[0] = obs_now_size[0];
      b_loop_ub = PoQ3->size[0];
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[0] = PoQ3->size[0];
      phi_Q2_l->size[1] = 1;
      d_loop_ub = PoQ3->size[2];
      phi_Q2_l->size[2] = PoQ3->size[2];
      e_loop_ub = PoQ3->size[3];
      phi_Q2_l->size[3] = PoQ3->size[3];
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &uf_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < d_loop_ub; i1++) {
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) + phi_Q2_l->size[0] *
              phi_Q2_l->size[2] * i] = PoQ3_data[(i2 + PoQ3->size[0] * i1) +
              PoQ3->size[0] * PoQ3->size[2] * i] / D_data[i2 + b_sz[0] * i1];
          }
        }
      }

      i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
        phiQo_global->size[3];
      phiQo_global->size[0] = PoQ3->size[0];
      phiQo_global->size[1] = 1;
      phiQo_global->size[2] = PoQ3->size[2];
      phiQo_global->size[3] = PoQ3->size[3];
      emxEnsureCapacity_real_T(sp, phiQo_global, i, &ng_emlrtRTEI);
      phiQo_global_data = phiQo_global->data;
      loop_ub_tmp = phi_Q2_l->size[0] * phi_Q2_l->size[2] * phi_Q2_l->size[3];
      for (i = 0; i < loop_ub_tmp; i++) {
        a = phi_Q2_l_data[i];
        phiQo_global_data[i] = muDoubleScalarMax(-1.0, muDoubleScalarMin(a, 1.0));
      }
    } else {
      binary_expand_op_22(sp, phiQo_global, PoQ3, D_data, tmp_size);
    }

    st.site = &md_emlrtRSI;
    b_asin(&st, phiQo_global);
    loop_ub_tmp = idx->size[0] * idx->size[2] * idx->size[3];
    i = idx->size[0] * idx->size[1] * idx->size[2] * idx->size[3];
    idx->size[1] = 1;
    emxEnsureCapacity_boolean_T(sp, idx, i, &kg_emlrtRTEI);
    idx_data = idx->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      idx_data[i] = !idx_data[i];
    }

    if ((phiQo_global->size[0] != idx->size[0]) && ((phiQo_global->size[0] != 1)
         && (idx->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo_global->size[0], idx->size[0],
        &nc_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phiQo_global->size[2] != idx->size[2]) && ((phiQo_global->size[2] != 1)
         && (idx->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phiQo_global->size[2], idx->size[2],
        &mc_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phiQo_global->size[0] == idx->size[0]) && (phiQo_global->size[2] ==
         idx->size[2])) {
      loop_ub_tmp = phiQo_global->size[0] * phiQo_global->size[2] *
        phiQo_global->size[3];
      i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
        phiQo_global->size[3];
      phiQo_global->size[1] = 1;
      emxEnsureCapacity_real_T(sp, phiQo_global, i, &lg_emlrtRTEI);
      phiQo_global_data = phiQo_global->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        phiQo_global_data[i] = (3.1415926535897931 - phiQo_global_data[i]) *
          (real_T)idx_data[i];
      }
    } else {
      st.site = &md_emlrtRSI;
      binary_expand_op_21(&st, phiQo_global, idx);
      phiQo_global_data = phiQo_global->data;
    }

    emlrtMEXProfilingStatement(76, isMexOutdated);
    i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
      phi_Q2_l->size[3];
    phi_Q2_l->size[0] = phiQo_global->size[0];
    phi_Q2_l->size[1] = 1;
    phi_Q2_l->size[2] = phiQo_global->size[2];
    phi_Q2_l->size[3] = phiQo_global->size[3];
    emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &mg_emlrtRTEI);
    phi_Q2_l_data = phi_Q2_l->data;
    loop_ub_tmp = phiQo_global->size[0] * phiQo_global->size[2] *
      phiQo_global->size[3];
    xPageOffset = (loop_ub_tmp / 2) << 1;
    npages = xPageOffset - 2;
    for (i = 0; i <= npages; i += 2) {
      r = _mm_loadu_pd(&phiQo_global_data[i]);
      _mm_storeu_pd(&phi_Q2_l_data[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }

    for (i = xPageOffset; i < loop_ub_tmp; i++) {
      phi_Q2_l_data[i] = -phiQo_global_data[i];
    }

    if ((phi_Q2_l->size[0] != idx->size[0]) && ((phi_Q2_l->size[0] != 1) &&
         (idx->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q2_l->size[0], idx->size[0], &lc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q2_l->size[2] != idx->size[2]) && ((phi_Q2_l->size[2] != 1) &&
         (idx->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_Q2_l->size[2], idx->size[2], &kc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_Q2_l->size[0] == idx->size[0]) && (phi_Q2_l->size[2] == idx->size[2]))
    {
      loop_ub_tmp = phi_Q2_l->size[0] * phi_Q2_l->size[2] * phi_Q2_l->size[3];
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[1] = 1;
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &og_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        phi_Q2_l_data[i] *= (real_T)idx_data[i];
      }
    } else {
      st.site = &mg_emlrtRSI;
      binary_expand_op_20(&st, phi_Q2_l, idx);
      phi_Q2_l_data = phi_Q2_l->data;
    }

    /*  ----------------------------------------------------------------- */
    emlrtMEXProfilingStatement(77, isMexOutdated);
    if ((phi_o_n->size[0] != phi_Q3->size[0]) && ((phi_o_n->size[0] != 1) &&
         (phi_Q3->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_n->size[0], phi_Q3->size[0],
        &jc_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_n->size[2] != phi_Q3->size[2]) && ((phi_o_n->size[2] != 1) &&
         (phi_Q3->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_n->size[2], phi_Q3->size[2],
        &ic_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_n->size[3] != phi_Q3->size[3]) && ((phi_o_n->size[3] != 1) &&
         (phi_Q3->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_n->size[3], phi_Q3->size[3],
        &hc_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_n->size[0] == phi_Q3->size[0]) && (phi_o_n->size[2] ==
         phi_Q3->size[2]) && (phi_o_n->size[3] == phi_Q3->size[3])) {
      loop_ub_tmp = phi_o_n->size[0] * phi_o_n->size[2] * phi_o_n->size[3];
      i = phi_o_n->size[0] * phi_o_n->size[1] * phi_o_n->size[2] * phi_o_n->
        size[3];
      phi_o_n->size[1] = 1;
      emxEnsureCapacity_real_T(sp, phi_o_n, i, &pg_emlrtRTEI);
      R_data = phi_o_n->data;
      xPageOffset = (loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&R_data[i]);
        r1 = _mm_loadu_pd(&phi_Q3_data[i]);
        _mm_storeu_pd(&R_data[i], _mm_add_pd(r, r1));
      }

      for (i = xPageOffset; i < loop_ub_tmp; i++) {
        R_data[i] += phi_Q3_data[i];
      }
    } else {
      st.site = &jg_emlrtRSI;
      c_plus(&st, phi_o_n, phi_Q3);
      R_data = phi_o_n->data;
    }

    emxFree_real_T(sp, &phi_Q3);
    emlrtMEXProfilingStatement(78, isMexOutdated);
    if ((phi_o_l_n->size[0] != phiQo_global->size[0]) && ((phi_o_l_n->size[0] !=
          1) && (phiQo_global->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_l_n->size[0], phiQo_global->size[0],
        &gc_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_l_n->size[2] != phiQo_global->size[2]) && ((phi_o_l_n->size[2] !=
          1) && (phiQo_global->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_l_n->size[2], phiQo_global->size[2],
        &fc_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_l_n->size[3] != phiQo_global->size[3]) && ((phi_o_l_n->size[3] !=
          1) && (phiQo_global->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_l_n->size[3], phiQo_global->size[3],
        &ec_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_l_n->size[0] == phiQo_global->size[0]) && (phi_o_l_n->size[2] ==
         phiQo_global->size[2]) && (phi_o_l_n->size[3] == phiQo_global->size[3]))
    {
      loop_ub_tmp = phi_o_l_n->size[0] * phi_o_l_n->size[2] * phi_o_l_n->size[3];
      i = phi_o_l_n->size[0] * phi_o_l_n->size[1] * phi_o_l_n->size[2] *
        phi_o_l_n->size[3];
      phi_o_l_n->size[1] = 1;
      emxEnsureCapacity_real_T(sp, phi_o_l_n, i, &qg_emlrtRTEI);
      phig_data = phi_o_l_n->data;
      xPageOffset = (loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&phig_data[i]);
        r1 = _mm_loadu_pd(&phiQo_global_data[i]);
        _mm_storeu_pd(&phig_data[i], _mm_add_pd(r, r1));
      }

      for (i = xPageOffset; i < loop_ub_tmp; i++) {
        phig_data[i] += phiQo_global_data[i];
      }
    } else {
      st.site = &kg_emlrtRSI;
      c_plus(&st, phi_o_l_n, phiQo_global);
      phig_data = phi_o_l_n->data;
    }

    emlrtMEXProfilingStatement(79, isMexOutdated);
    if ((PoQo->size[0] != phi_Q2_l->size[0]) && ((PoQo->size[0] != 1) &&
         (phi_Q2_l->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQo->size[0], phi_Q2_l->size[0], &dc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQo->size[2] != phi_Q2_l->size[2]) && ((PoQo->size[2] != 1) &&
         (phi_Q2_l->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQo->size[2], phi_Q2_l->size[2], &cc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQo->size[3] != phi_Q2_l->size[3]) && ((PoQo->size[3] != 1) &&
         (phi_Q2_l->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQo->size[3], phi_Q2_l->size[3], &bc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQo->size[0] == phi_Q2_l->size[0]) && (PoQo->size[2] == phi_Q2_l->
         size[2]) && (PoQo->size[3] == phi_Q2_l->size[3])) {
      loop_ub_tmp = PoQo->size[0] * PoQo->size[2] * PoQo->size[3];
      i = PoQo->size[0] * PoQo->size[1] * PoQo->size[2] * PoQo->size[3];
      PoQo->size[1] = 1;
      emxEnsureCapacity_real_T(sp, PoQo, i, &rg_emlrtRTEI);
      PoQo_data = PoQo->data;
      xPageOffset = (loop_ub_tmp / 2) << 1;
      npages = xPageOffset - 2;
      for (i = 0; i <= npages; i += 2) {
        r = _mm_loadu_pd(&PoQo_data[i]);
        r1 = _mm_loadu_pd(&phi_Q2_l_data[i]);
        _mm_storeu_pd(&PoQo_data[i], _mm_add_pd(r, r1));
      }

      for (i = xPageOffset; i < loop_ub_tmp; i++) {
        PoQo_data[i] += phi_Q2_l_data[i];
      }
    } else {
      st.site = &lg_emlrtRSI;
      c_plus(&st, PoQo, phi_Q2_l);
      PoQo_data = PoQo->data;
    }

    emlrtMEXProfilingStatement(80, isMexOutdated);
    i = r2->size[0] * r2->size[1] * r2->size[2] * r2->size[3];
    r2->size[0] = phi_o_n->size[0];
    r2->size[1] = 1;
    r2->size[2] = phi_o_n->size[2];
    r2->size[3] = phi_o_n->size[3];
    emxEnsureCapacity_real_T(sp, r2, i, &sg_emlrtRTEI);
    Q2_2_data = r2->data;
    loop_ub_tmp = phi_o_n->size[0] * phi_o_n->size[2] * phi_o_n->size[3];
    for (i = 0; i < loop_ub_tmp; i++) {
      Q2_2_data[i] = R_data[i];
    }

    st.site = &nd_emlrtRSI;
    e_sin(&st, r2);
    i = phiQo_global->size[0] * phiQo_global->size[1] * phiQo_global->size[2] *
      phiQo_global->size[3];
    phiQo_global->size[0] = phi_o_n->size[0];
    phiQo_global->size[1] = 1;
    phiQo_global->size[2] = phi_o_n->size[2];
    phiQo_global->size[3] = phi_o_n->size[3];
    emxEnsureCapacity_real_T(sp, phiQo_global, i, &tg_emlrtRTEI);
    phiQo_global_data = phiQo_global->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      phiQo_global_data[i] = R_data[i];
    }

    st.site = &nd_emlrtRSI;
    e_cos(&st, phiQo_global);
    st.site = &nd_emlrtRSI;
    d_atan2(&st, r2, phiQo_global, phi_o_n);
    R_data = phi_o_n->data;
    emxFree_real_T(sp, &r2);
    emxFree_real_T(sp, &phiQo_global);

    /*  ---障害物のある方向のPMFを下げる------------------------------------ */
    emlrtMEXProfilingStatement(81, isMexOutdated);
    if ((phi_o_n->size[0] != phi_o_l_n->size[0]) && ((phi_o_n->size[0] != 1) &&
         (phi_o_l_n->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_n->size[0], phi_o_l_n->size[0],
        &wb_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_n->size[2] != phi_o_l_n->size[2]) && ((phi_o_n->size[2] != 1) &&
         (phi_o_l_n->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_n->size[2], phi_o_l_n->size[2],
        &vb_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_n->size[3] != phi_o_l_n->size[3]) && ((phi_o_n->size[3] != 1) &&
         (phi_o_l_n->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_n->size[3], phi_o_l_n->size[3],
        &ub_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((phi_o_n->size[0] != PoQo->size[0]) && ((phi_o_n->size[0] != 1) &&
         (PoQo->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_n->size[0], PoQo->size[0], &ac_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_o_n->size[2] != PoQo->size[2]) && ((phi_o_n->size[2] != 1) &&
         (PoQo->size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_n->size[2], PoQo->size[2], &yb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((phi_o_n->size[3] != PoQo->size[3]) && ((phi_o_n->size[3] != 1) &&
         (PoQo->size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(phi_o_n->size[3], PoQo->size[3], &xb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    emxInit_boolean_T(sp, &idx2, 4, &xg_emlrtRTEI);
    if ((phi_o_n->size[0] == phi_o_l_n->size[0]) && (phi_o_n->size[2] ==
         phi_o_l_n->size[2]) && (phi_o_n->size[3] == phi_o_l_n->size[3])) {
      i = idx2->size[0] * idx2->size[1] * idx2->size[2] * idx2->size[3];
      idx2->size[0] = phi_o_n->size[0];
      idx2->size[1] = 1;
      idx2->size[2] = phi_o_n->size[2];
      idx2->size[3] = phi_o_n->size[3];
      emxEnsureCapacity_boolean_T(sp, idx2, i, &ug_emlrtRTEI);
      idx2_data = idx2->data;
      loop_ub_tmp = phi_o_n->size[0] * phi_o_n->size[2] * phi_o_n->size[3];
      for (i = 0; i < loop_ub_tmp; i++) {
        idx2_data[i] = (R_data[i] + phig_data[i] >= 0.0);
      }
    } else {
      st.site = &ig_emlrtRSI;
      binary_expand_op_19(&st, idx2, phi_o_n, phi_o_l_n);
    }

    emxFree_real_T(sp, &phi_o_l_n);
    if ((phi_o_n->size[0] == PoQo->size[0]) && (phi_o_n->size[2] == PoQo->size[2])
        && (phi_o_n->size[3] == PoQo->size[3])) {
      i = idx->size[0] * idx->size[1] * idx->size[2] * idx->size[3];
      idx->size[0] = phi_o_n->size[0];
      idx->size[1] = 1;
      idx->size[2] = phi_o_n->size[2];
      idx->size[3] = phi_o_n->size[3];
      emxEnsureCapacity_boolean_T(sp, idx, i, &vg_emlrtRTEI);
      idx_data = idx->data;
      loop_ub_tmp = phi_o_n->size[0] * phi_o_n->size[2] * phi_o_n->size[3];
      for (i = 0; i < loop_ub_tmp; i++) {
        idx_data[i] = (R_data[i] + PoQo_data[i] < 0.0);
      }
    } else {
      st.site = &ig_emlrtRSI;
      binary_expand_op_18(&st, idx, phi_o_n, PoQo);
      idx_data = idx->data;
    }

    emxFree_real_T(sp, &phi_o_n);
    emxFree_real_T(sp, &PoQo);
    if ((idx2->size[0] != idx->size[0]) && ((idx2->size[0] != 1) && (idx->size[0]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx2->size[0], idx->size[0], &wb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((idx2->size[2] != idx->size[2]) && ((idx2->size[2] != 1) && (idx->size[2]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx2->size[2], idx->size[2], &vb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((idx2->size[3] != idx->size[3]) && ((idx2->size[3] != 1) && (idx->size[3]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx2->size[3], idx->size[3], &ub_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((idx2->size[0] == idx->size[0]) && (idx2->size[2] == idx->size[2]) &&
        (idx2->size[3] == idx->size[3])) {
      loop_ub_tmp = idx2->size[0] * idx2->size[2] * idx2->size[3];
      i = idx2->size[0] * idx2->size[1] * idx2->size[2] * idx2->size[3];
      idx2->size[1] = 1;
      emxEnsureCapacity_boolean_T(sp, idx2, i, &ug_emlrtRTEI);
      idx2_data = idx2->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        idx2_data[i] = (idx2_data[i] && idx_data[i]);
      }
    } else {
      st.site = &ig_emlrtRSI;
      c_and(&st, idx2, idx);
    }

    b_loop_ub = PoQ3->size[0];
    i = idx->size[0] * idx->size[1] * idx->size[2] * idx->size[3];
    idx->size[0] = PoQ3->size[0];
    idx->size[1] = 1;
    d_loop_ub = PoQ3->size[2];
    idx->size[2] = PoQ3->size[2];
    e_loop_ub = PoQ3->size[3];
    idx->size[3] = PoQ3->size[3];
    emxEnsureCapacity_boolean_T(sp, idx, i, &wg_emlrtRTEI);
    idx_data = idx->data;
    loop_ub_tmp = PoQ3->size[0] * PoQ3->size[2] * PoQ3->size[3];
    for (i = 0; i < loop_ub_tmp; i++) {
      idx_data[i] = (PoQ3_data[i] < param_FPM_alpha);
    }

    if ((idx2->size[0] != PoQ3->size[0]) && ((idx2->size[0] != 1) && (PoQ3->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx2->size[0], PoQ3->size[0], &wb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((idx2->size[2] != PoQ3->size[2]) && ((idx2->size[2] != 1) && (PoQ3->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx2->size[2], PoQ3->size[2], &vb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((idx2->size[3] != PoQ3->size[3]) && ((idx2->size[3] != 1) && (PoQ3->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx2->size[3], PoQ3->size[3], &ub_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((idx2->size[0] == idx->size[0]) && (idx2->size[2] == idx->size[2]) &&
        (idx2->size[3] == idx->size[3])) {
      b_loop_ub_tmp = idx2->size[0] * idx2->size[2] * idx2->size[3];
      i = idx2->size[0] * idx2->size[1] * idx2->size[2] * idx2->size[3];
      idx2->size[1] = 1;
      emxEnsureCapacity_boolean_T(sp, idx2, i, &xg_emlrtRTEI);
      idx2_data = idx2->data;
      for (i = 0; i < b_loop_ub_tmp; i++) {
        idx2_data[i] = (idx2_data[i] && idx_data[i]);
      }
    } else {
      st.site = &ig_emlrtRSI;
      c_and(&st, idx2, idx);
      idx2_data = idx2->data;
    }

    emxFree_boolean_T(sp, &idx);
    emlrtMEXProfilingStatement(82, isMexOutdated);
    if ((PoQ3->size[0] != obs_now_size[0]) && ((PoQ3->size[0] != 1) &&
         (obs_now_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[0], obs_now_size[0], &tb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQ3->size[2] != obs_now_size[2]) && ((PoQ3->size[2] != 1) &&
         (obs_now_size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[2], obs_now_size[2], &sb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQ3->size[0] == obs_now_size[0]) && (PoQ3->size[2] == obs_now_size[2]))
    {
      varargin_1_size[0] = obs_now_size[0];
      for (i = 0; i < c_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          varargin_1_data[i1 + varargin_1_size[0] * i] = obs_now_data[(i1 +
            obs_now_size[0] * 5) + obs_now_size[0] * 6 * i];
        }
      }

      b_sz[0] = obs_now_size[0];
      i = phi_Q2_l->size[0] * phi_Q2_l->size[1] * phi_Q2_l->size[2] *
        phi_Q2_l->size[3];
      phi_Q2_l->size[0] = PoQ3->size[0];
      phi_Q2_l->size[1] = 1;
      phi_Q2_l->size[2] = PoQ3->size[2];
      phi_Q2_l->size[3] = PoQ3->size[3];
      emxEnsureCapacity_real_T(sp, phi_Q2_l, i, &ah_emlrtRTEI);
      phi_Q2_l_data = phi_Q2_l->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < d_loop_ub; i1++) {
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            phi_Q2_l_data[(i2 + phi_Q2_l->size[0] * i1) + phi_Q2_l->size[0] *
              phi_Q2_l->size[2] * i] = -((PoQ3_data[(i2 + PoQ3->size[0] * i1) +
              PoQ3->size[0] * PoQ3->size[2] * i] - varargin_1_data[i2 + b_sz[0] *
              i1]) - r_wheel);
          }
        }
      }

      i = PoQ3->size[0] * PoQ3->size[1] * PoQ3->size[2] * PoQ3->size[3];
      PoQ3->size[0] = b_loop_ub;
      PoQ3->size[1] = 1;
      PoQ3->size[2] = d_loop_ub;
      PoQ3->size[3] = e_loop_ub;
      emxEnsureCapacity_real_T(sp, PoQ3, i, &ch_emlrtRTEI);
      PoQ3_data = PoQ3->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        PoQ3_data[i] = phi_Q2_l_data[i];
      }
    } else {
      binary_expand_op_17(sp, PoQ3, obs_now_data, obs_now_size, r_wheel);
    }

    emxFree_real_T(sp, &phi_Q2_l);
    st.site = &od_emlrtRSI;
    b_exp(&st, PoQ3);
    loop_ub_tmp = PoQ3->size[0] * PoQ3->size[2] * PoQ3->size[3];
    i = PoQ3->size[0] * PoQ3->size[1] * PoQ3->size[2] * PoQ3->size[3];
    PoQ3->size[1] = 1;
    emxEnsureCapacity_real_T(sp, PoQ3, i, &yg_emlrtRTEI);
    PoQ3_data = PoQ3->data;
    xPageOffset = (loop_ub_tmp / 2) << 1;
    npages = xPageOffset - 2;
    for (i = 0; i <= npages; i += 2) {
      r = _mm_loadu_pd(&PoQ3_data[i]);
      _mm_storeu_pd(&PoQ3_data[i], _mm_sub_pd(_mm_set1_pd(1.0), r));
    }

    for (i = xPageOffset; i < loop_ub_tmp; i++) {
      PoQ3_data[i] = 1.0 - PoQ3_data[i];
    }

    /*  grade_obs(idx2,1) = 1-(alpha-PoQ3(idx2,1))./(alpha-(b_obs(idx2,1) + ds + r_wheel)); */
    emlrtMEXProfilingStatement(83, isMexOutdated);
    if ((PoQ3->size[0] != idx2->size[0]) && ((PoQ3->size[0] != 1) && (idx2->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[0], idx2->size[0], &rb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQ3->size[2] != idx2->size[2]) && ((PoQ3->size[2] != 1) && (idx2->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[2], idx2->size[2], &qb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQ3->size[3] != idx2->size[3]) && ((PoQ3->size[3] != 1) && (idx2->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[3], idx2->size[3], &pb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQ3->size[0] == idx2->size[0]) && (PoQ3->size[2] == idx2->size[2]) &&
        (PoQ3->size[3] == idx2->size[3])) {
      loop_ub_tmp = PoQ3->size[0] * PoQ3->size[2] * PoQ3->size[3];
      i = PoQ3->size[0] * PoQ3->size[1] * PoQ3->size[2] * PoQ3->size[3];
      PoQ3->size[1] = 1;
      emxEnsureCapacity_real_T(sp, PoQ3, i, &bh_emlrtRTEI);
      PoQ3_data = PoQ3->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        PoQ3_data[i] *= (real_T)idx2_data[i];
      }
    } else {
      st.site = &hg_emlrtRSI;
      binary_expand_op_16(&st, PoQ3, idx2);
    }

    loop_ub_tmp = idx2->size[0] * idx2->size[2] * idx2->size[3];
    i = idx2->size[0] * idx2->size[1] * idx2->size[2] * idx2->size[3];
    idx2->size[1] = 1;
    emxEnsureCapacity_boolean_T(sp, idx2, i, &dh_emlrtRTEI);
    idx2_data = idx2->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      idx2_data[i] = !idx2_data[i];
    }

    if ((PoQ3->size[0] != idx2->size[0]) && ((PoQ3->size[0] != 1) && (idx2->
          size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[0], idx2->size[0], &rb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQ3->size[2] != idx2->size[2]) && ((PoQ3->size[2] != 1) && (idx2->
          size[2] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[2], idx2->size[2], &qb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQ3->size[3] != idx2->size[3]) && ((PoQ3->size[3] != 1) && (idx2->
          size[3] != 1))) {
      emlrtDimSizeImpxCheckR2021b(PoQ3->size[3], idx2->size[3], &pb_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((PoQ3->size[0] == idx2->size[0]) && (PoQ3->size[2] == idx2->size[2]) &&
        (PoQ3->size[3] == idx2->size[3])) {
      loop_ub_tmp = PoQ3->size[0] * PoQ3->size[2] * PoQ3->size[3];
      i = PoQ3->size[0] * PoQ3->size[1] * PoQ3->size[2] * PoQ3->size[3];
      PoQ3->size[1] = 1;
      emxEnsureCapacity_real_T(sp, PoQ3, i, &eh_emlrtRTEI);
      PoQ3_data = PoQ3->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        PoQ3_data[i] += (real_T)idx2_data[i];
      }
    } else {
      st.site = &hg_emlrtRSI;
      binary_expand_op_15(&st, PoQ3, idx2);
      PoQ3_data = PoQ3->data;
    }

    emxFree_boolean_T(sp, &idx2);

    /*  ----------------------------------------------------------------- */
    /*  ---障害物のコストを計算-------------------------------------------- */
    /*  idx3 = idx2 & PoQ3 - b_obs - ds -r_wheel <= 0; */
    /*  grade_obs(idx3,1,:,:) = grade_obs(idx3,1,:,:)-obs_cost; */
    /*  ----------------------------------------------------------------- */
    emlrtMEXProfilingStatement(85, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(84, isMexOutdated);

    /*  phi_o  =double([]); */
    /*  phi_o_l=double([]); */
    /*  phi_o_r=double([]); */
    emlrtMEXProfilingStatement(85, isMexOutdated);
  }

  emxFree_real_T(sp, &varargin_2);
  emxFree_real_T(sp, &Po);

  /* --PFM of Obstacle (end)--------------------------------------------------- */
  /* --最終的なPMF-------------------------------------------------------------- */
  emlrtMEXProfilingStatement(86, isMexOutdated);
  st.site = &pd_emlrtRSI;
  b_st.site = &of_emlrtRSI;
  c_st.site = &pf_emlrtRSI;
  d_st.site = &qf_emlrtRSI;
  if (PoQ3->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &h_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &if_emlrtRSI;
  f_st.site = &jf_emlrtRSI;
  i = phig->size[0] * phig->size[1] * phig->size[2] * phig->size[3];
  phig->size[0] = 1;
  phig->size[1] = 1;
  phig->size[2] = PoQ3->size[2];
  phig->size[3] = PoQ3->size[3];
  emxEnsureCapacity_real_T(&f_st, phig, i, &yd_emlrtRTEI);
  phig_data = phig->data;
  if ((PoQ3->size[2] == 0) || (PoQ3->size[3] == 0)) {
    i = phig->size[0] * phig->size[1] * phig->size[2] * phig->size[3];
    phig->size[0] = 1;
    phig->size[1] = 1;
    phig->size[2] = PoQ3->size[2];
    phig->size[3] = PoQ3->size[3];
    emxEnsureCapacity_real_T(&f_st, phig, i, &be_emlrtRTEI);
    phig_data = phig->data;
    loop_ub_tmp = PoQ3->size[2] * PoQ3->size[3];
    for (i = 0; i < loop_ub_tmp; i++) {
      phig_data[i] = rtNaN;
    }
  } else {
    n = PoQ3->size[0];
    npages = PoQ3->size[2] * PoQ3->size[3];
    g_st.site = &kf_emlrtRSI;
    if (npages > 2147483646) {
      h_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&h_st);
    }

    for (d_loop_ub_tmp = 0; d_loop_ub_tmp < npages; d_loop_ub_tmp++) {
      xPageOffset = d_loop_ub_tmp * n;
      phig_data[d_loop_ub_tmp] = PoQ3_data[xPageOffset];
      g_st.site = &mf_emlrtRSI;
      if (n > 2147483646) {
        h_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      for (c_loop_ub_tmp = 2; c_loop_ub_tmp <= n; c_loop_ub_tmp++) {
        xOffset = (xPageOffset + c_loop_ub_tmp) - 1;
        if (muDoubleScalarIsNaN(PoQ3_data[xOffset])) {
          out = false;
        } else if (muDoubleScalarIsNaN(phig_data[d_loop_ub_tmp])) {
          out = true;
        } else {
          out = (phig_data[d_loop_ub_tmp] > PoQ3_data[xOffset]);
        }

        if (out) {
          phig_data[d_loop_ub_tmp] = PoQ3_data[xOffset];
        }
      }
    }
  }

  emxFree_real_T(&f_st, &PoQ3);
  st.site = &pd_emlrtRSI;
  b_st.site = &of_emlrtRSI;
  c_st.site = &sf_emlrtRSI;
  d_st.site = &tf_emlrtRSI;
  e_st.site = &uf_emlrtRSI;
  f_st.site = &be_emlrtRSI;
  if ((grade_trgt->size[2] == phig->size[2]) && (grade_trgt->size[3] ==
       phig->size[3])) {
    i = Grade->size[0] * Grade->size[1] * Grade->size[2] * Grade->size[3];
    Grade->size[0] = 1;
    Grade->size[1] = 1;
    Grade->size[2] = grade_trgt->size[2];
    Grade->size[3] = grade_trgt->size[3];
    emxEnsureCapacity_real_T(&f_st, Grade, i, &de_emlrtRTEI);
    R_data = Grade->data;
    loop_ub_tmp = grade_trgt->size[2] * grade_trgt->size[3];
    for (i = 0; i < loop_ub_tmp; i++) {
      a = grade_trgt_data[i];
      maxval_tmp = phig_data[i];
      R_data[i] = muDoubleScalarMin(a, maxval_tmp);
    }
  } else {
    g_st.site = &ce_emlrtRSI;
    expand_min(&g_st, grade_trgt, phig, Grade);
  }

  emxFree_real_T(&f_st, &grade_trgt);
  emxFree_real_T(&f_st, &phig);

  /*  Grade = grade_trgt; */
  /* -------------------------------------------------------------------------- */
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (FPM_capsule_v3_3vec.c) */
