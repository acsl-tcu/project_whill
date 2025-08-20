/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ransac.c
 *
 * Code generation for function 'ransac'
 *
 */

/* Include files */
#include "ransac.h"
#include "calc_observation_emxutil.h"
#include "calc_observation_internal_types.h"
#include "calc_observation_types.h"
#include "msac.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo tc_emlrtRSI = {
    148,                                                      /* lineNo */
    "ransac",                                                 /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    164,                                                      /* lineNo */
    "ransac",                                                 /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    175,                                                      /* lineNo */
    "ransac",                                                 /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    180,                                                      /* lineNo */
    "ransac",                                                 /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    199,                                                      /* lineNo */
    "parseInputs",                                            /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    205,                                                      /* lineNo */
    "parseInputs",                                            /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    207,                                                      /* lineNo */
    "parseInputs",                                            /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    261,                                                      /* lineNo */
    "parseInputs",                                            /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    262,                                                      /* lineNo */
    "parseInputs",                                            /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    263,                                                      /* lineNo */
    "parseInputs",                                            /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI =
    {
        93,                   /* lineNo */
        "validateattributes", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/lang/"
        "validateattributes.m" /* pathName */
};

static emlrtRSInfo fd_emlrtRSI = {
    294,                                                      /* lineNo */
    "checkMaxDistance",                                       /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    276,                                                      /* lineNo */
    "checkMaxNumTrials",                                      /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo hd_emlrtRSI = {
    282,                                                      /* lineNo */
    "checkMaxSamplingAttempts",                               /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    288,                                                      /* lineNo */
    "checkConfidence",                                        /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    188,                                                      /* lineNo */
    5,                                                        /* colNo */
    "checkRuntimeStatus",                                     /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    190,                                                      /* lineNo */
    1,                                                        /* colNo */
    "checkRuntimeStatus",                                     /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    13,                 /* lineNo */
    37,                 /* colNo */
    "validatenonempty", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonempty.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    13,                /* lineNo */
    37,                /* colNo */
    "validateinteger", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validateinteger.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatepositive.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    14,                    /* lineNo */
    37,                    /* colNo */
    "validatenonnegative", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnegative.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatefinite.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    22,           /* lineNo */
    27,           /* colNo */
    "validatelt", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatelt.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    162,                                                      /* lineNo */
    5,                                                        /* colNo */
    "ransac",                                                 /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/ransac.m" /* pName */
};

/* Function Definitions */
void ransac(const emlrtStack *sp, const emxArray_real_T *data,
            const real_T fitFun_workspace_a0[5],
            const real_T fitFun_workspace_A[5], real_T fitFun_workspace_B,
            const real_T fitFun_workspace_lb[5],
            const real_T fitFun_workspace_ub[5],
            const real_T c_fitFun_workspace_nonlcon_work[2],
            real_T d_fitFun_workspace_nonlcon_work,
            real_T e_fitFun_workspace_nonlcon_work,
            real_T f_fitFun_workspace_nonlcon_work, real_T sampleSize,
            real_T maxDistance, real_T varargin_2, real_T varargin_4,
            real_T varargin_6, const e_struct_T *varargin_8_workspace,
            real_T model_data[], int32_T model_size[2],
            emxArray_boolean_T *inlierIdx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T i;
  int32_T status;
  boolean_T reachedMaxSkipTrials;
  boolean_T *inlierIdx_data;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &xc_emlrtRSI;
  c_st.site = &ed_emlrtRSI;
  if (data->size[0] == 0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &l_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:ransac:expectedNonempty", 3, 4, 4, "data");
  }
  b_st.site = &yc_emlrtRSI;
  c_st.site = &ed_emlrtRSI;
  if (muDoubleScalarIsInf(sampleSize) || muDoubleScalarIsNaN(sampleSize) ||
      (!(muDoubleScalarFloor(sampleSize) == sampleSize))) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:ransac:expectedInteger", 3, 4, 10, "sampleSize");
  }
  c_st.site = &ed_emlrtRSI;
  if (sampleSize <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 10, "sampleSize");
  }
  b_st.site = &ad_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  d_st.site = &ed_emlrtRSI;
  if (maxDistance < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &o_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:ransac:expectedNonnegative", 3, 4, 11, "maxDistance");
  }
  d_st.site = &ed_emlrtRSI;
  if (muDoubleScalarIsInf(maxDistance) || muDoubleScalarIsNaN(maxDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &p_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ransac:expectedFinite", 3, 4, 11, "maxDistance");
  }
  b_st.site = &bd_emlrtRSI;
  c_st.site = &gd_emlrtRSI;
  d_st.site = &ed_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_4) || muDoubleScalarIsNaN(varargin_4) ||
      (!(muDoubleScalarFloor(varargin_4) == varargin_4))) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &m_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:ransac:expectedInteger", 3, 4, 12, "MaxNumTrials");
  }
  d_st.site = &ed_emlrtRSI;
  if (varargin_4 <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 12, "MaxNumTrials");
  }
  b_st.site = &cd_emlrtRSI;
  c_st.site = &hd_emlrtRSI;
  d_st.site = &ed_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_2) || muDoubleScalarIsNaN(varargin_2) ||
      (!(muDoubleScalarFloor(varargin_2) == varargin_2))) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &m_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:ransac:expectedInteger", 3, 4, 19, "MaxSamplingAttempts");
  }
  d_st.site = &ed_emlrtRSI;
  if (varargin_2 <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 19, "MaxSamplingAttempts");
  }
  b_st.site = &dd_emlrtRSI;
  c_st.site = &id_emlrtRSI;
  d_st.site = &ed_emlrtRSI;
  if (varargin_6 <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 10, "Confidence");
  }
  d_st.site = &ed_emlrtRSI;
  if (!(varargin_6 < 100.0)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                                  "MATLAB:validateattributes:expectedScalar",
                                  "MATLAB:ransac:notLess", 9, 4, 10,
                                  "Confidence", 4, 1, "<", 4, 3, "100");
  }
  reachedMaxSkipTrials = false;
  if (data->size[0] < sampleSize) {
    int32_T loop_ub;
    status = 1;
    model_size[0] = 0;
    model_size[1] = 0;
    loop_ub = data->size[0];
    i = inlierIdx->size[0];
    inlierIdx->size[0] = data->size[0];
    emxEnsureCapacity_boolean_T(sp, inlierIdx, i, &gc_emlrtRTEI);
    inlierIdx_data = inlierIdx->data;
    for (i = 0; i < loop_ub; i++) {
      inlierIdx_data[i] = false;
    }
  } else {
    boolean_T isFound;
    st.site = &uc_emlrtRSI;
    isFound =
        msac(&st, data, sampleSize, maxDistance, varargin_6, varargin_4,
             varargin_2, fitFun_workspace_a0, fitFun_workspace_A,
             fitFun_workspace_B, fitFun_workspace_lb, fitFun_workspace_ub,
             c_fitFun_workspace_nonlcon_work, d_fitFun_workspace_nonlcon_work,
             e_fitFun_workspace_nonlcon_work, f_fitFun_workspace_nonlcon_work,
             varargin_8_workspace, model_data, model_size, inlierIdx,
             &reachedMaxSkipTrials);
    if (isFound) {
      status = 0;
    } else {
      status = 2;
    }
  }
  if (reachedMaxSkipTrials) {
    st.site = &vc_emlrtRSI;
    c_warning(&st, varargin_2);
  }
  st.site = &wc_emlrtRSI;
  if (status == 1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &j_emlrtRTEI, "vision:ransac:notEnoughDataPts",
        "vision:ransac:notEnoughDataPts", 2, 6, sampleSize);
  }
  if (status == 2) {
    emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
                                  "vision:ransac:notEnoughInliers",
                                  "vision:ransac:notEnoughInliers", 0);
  }
}

/* End of code generation (ransac.c) */
