/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * feasibleAndSortKBestEvents.c
 *
 * Code generation for function 'feasibleAndSortKBestEvents'
 *
 */

/* Include files */
#include "feasibleAndSortKBestEvents.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "feasibleJPDAEvents.h"
#include "indexShapeCheck.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sum.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo tw_emlrtRSI = {
    22,                           /* lineNo */
    "feasibleAndSortKBestEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pathName */
};

static emlrtRSInfo uw_emlrtRSI = {
    23,                           /* lineNo */
    "feasibleAndSortKBestEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pathName */
};

static emlrtRSInfo vw_emlrtRSI = {
    25,                           /* lineNo */
    "feasibleAndSortKBestEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pathName */
};

static emlrtRSInfo ww_emlrtRSI = {
    37,                           /* lineNo */
    "feasibleAndSortKBestEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pathName */
};

static emlrtRSInfo xw_emlrtRSI = {
    38,                           /* lineNo */
    "feasibleAndSortKBestEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pathName */
};

static emlrtRSInfo yw_emlrtRSI = {
    41,                           /* lineNo */
    "feasibleAndSortKBestEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pathName */
};

static emlrtRSInfo mx_emlrtRSI = {
    14,                             /* lineNo */
    "jointFeasibleEventLikelihood", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pathName */
};

static emlrtRSInfo nx_emlrtRSI = {
    18,                             /* lineNo */
    "jointFeasibleEventLikelihood", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pathName */
};

static emlrtRSInfo ox_emlrtRSI = {
    19,                             /* lineNo */
    "jointFeasibleEventLikelihood", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pathName */
};

static emlrtRSInfo px_emlrtRSI = {
    20,                             /* lineNo */
    "jointFeasibleEventLikelihood", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pathName */
};

static emlrtRSInfo qx_emlrtRSI = {
    17,                                                           /* lineNo */
    "log",                                                        /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elfun/log.m" /* pathName */
};

static emlrtRSInfo rx_emlrtRSI = {
    177,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo ay_emlrtRSI = {
    12,          /* lineNo */
    "logsumexp", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "logsumexp.m" /* pathName */
};

static emlrtRSInfo by_emlrtRSI = {
    14,          /* lineNo */
    "logsumexp", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "logsumexp.m" /* pathName */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    17,                             /* lineNo */
    20,                             /* colNo */
    "",                             /* aName */
    "jointFeasibleEventLikelihood", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    41,                           /* lineNo */
    26,                           /* colNo */
    "",                           /* aName */
    "feasibleAndSortKBestEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    41,                           /* lineNo */
    22,                           /* colNo */
    "",                           /* aName */
    "feasibleAndSortKBestEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    20,                             /* lineNo */
    40,                             /* colNo */
    "",                             /* aName */
    "jointFeasibleEventLikelihood", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    20,                             /* lineNo */
    22,                             /* colNo */
    "",                             /* aName */
    "jointFeasibleEventLikelihood", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m", /* pName */
    0                                             /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    41,                           /* lineNo */
    18,                           /* colNo */
    "",                           /* aName */
    "feasibleAndSortKBestEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m", /* pName */
    0                                           /* checkKind */
};

static emlrtRTEInfo th_emlrtRTEI = {
    23,                           /* lineNo */
    16,                           /* colNo */
    "feasibleAndSortKBestEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pName */
};

static emlrtRTEInfo uh_emlrtRTEI = {
    14,                             /* lineNo */
    16,                             /* colNo */
    "jointFeasibleEventLikelihood", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pName */
};

static emlrtRTEInfo vh_emlrtRTEI = {
    17,                             /* lineNo */
    12,                             /* colNo */
    "jointFeasibleEventLikelihood", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pName */
};

static emlrtRTEInfo wh_emlrtRTEI = {
    14,          /* lineNo */
    20,          /* colNo */
    "logsumexp", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "logsumexp.m" /* pName */
};

static emlrtRTEInfo xh_emlrtRTEI = {
    19,                             /* lineNo */
    5,                              /* colNo */
    "jointFeasibleEventLikelihood", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pName */
};

static emlrtRTEInfo yh_emlrtRTEI = {
    1,                            /* lineNo */
    28,                           /* colNo */
    "feasibleAndSortKBestEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pName */
};

static emlrtRTEInfo ai_emlrtRTEI = {
    38,                           /* lineNo */
    1,                            /* colNo */
    "feasibleAndSortKBestEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pName */
};

static emlrtRTEInfo bi_emlrtRTEI = {
    20,                             /* lineNo */
    31,                             /* colNo */
    "jointFeasibleEventLikelihood", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pName */
};

static emlrtRTEInfo ci_emlrtRTEI = {
    41,                           /* lineNo */
    1,                            /* colNo */
    "feasibleAndSortKBestEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pName */
};

static emlrtRTEInfo di_emlrtRTEI = {
    22,                           /* lineNo */
    1,                            /* colNo */
    "feasibleAndSortKBestEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pName */
};

static emlrtRTEInfo ei_emlrtRTEI = {
    23,                           /* lineNo */
    1,                            /* colNo */
    "feasibleAndSortKBestEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleAndSortKBestEvents.m" /* pName */
};

static emlrtRTEInfo fi_emlrtRTEI = {
    20,                             /* lineNo */
    40,                             /* colNo */
    "jointFeasibleEventLikelihood", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pName */
};

static emlrtRTEInfo gi_emlrtRTEI = {
    14,                             /* lineNo */
    1,                              /* colNo */
    "jointFeasibleEventLikelihood", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/jointFeasibleEventLikelihood.m" /* pName */
};

/* Function Definitions */
void feasibleAndSortKBestEvents(const emlrtStack *sp,
                                const emxArray_real_T *likelihoodMatrix,
                                const emxArray_boolean_T *validationMatrix,
                                emxArray_boolean_T *FJE,
                                emxArray_real_T *FJEProbs)
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  emxArray_boolean_T *FJEPaddedi;
  emxArray_boolean_T *allFJE;
  emxArray_boolean_T *b_allFJE;
  emxArray_int32_T *iidx;
  emxArray_real_T *b_loglhood;
  emxArray_real_T *loglhood;
  emxArray_real_T *logposterior;
  const real_T *likelihoodMatrix_data;
  real_T x;
  real_T xmax;
  real_T *FJEProbs_data;
  real_T *loglhood_data;
  real_T *logposterior_data;
  int32_T sizes[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_i;
  int32_T c_loglhood;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T isTrackUnassigned_size_idx_1;
  int32_T k;
  int32_T loop_ub;
  int32_T sizes_idx_0;
  int32_T vlen;
  int32_T xpageoffset;
  int32_T *iidx_data;
  boolean_T p;
  boolean_T *FJEPaddedi_data;
  boolean_T *FJE_data;
  boolean_T *allFJE_data;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  likelihoodMatrix_data = likelihoodMatrix->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &allFJE, 3, &di_emlrtRTEI, true);
  st.site = &tw_emlrtRSI;
  feasibleJPDAEvents(&st, validationMatrix, allFJE);
  allFJE_data = allFJE->data;
  st.site = &uw_emlrtRSI;
  emxInit_real_T(&st, &logposterior, 1, &ei_emlrtRTEI, true);
  i = logposterior->size[0];
  logposterior->size[0] = allFJE->size[2];
  emxEnsureCapacity_real_T(&st, logposterior, i, &th_emlrtRTEI);
  logposterior_data = logposterior->data;
  b_st.site = &mx_emlrtRSI;
  emxInit_real_T(&b_st, &loglhood, 1, &gi_emlrtRTEI, true);
  loop_ub = likelihoodMatrix->size[0] * likelihoodMatrix->size[1];
  i = loglhood->size[0];
  loglhood->size[0] = loop_ub;
  emxEnsureCapacity_real_T(&b_st, loglhood, i, &uh_emlrtRTEI);
  loglhood_data = loglhood->data;
  for (i = 0; i < loop_ub; i++) {
    loglhood_data[i] = likelihoodMatrix_data[i];
  }
  p = false;
  for (k = 0; k < loop_ub; k++) {
    if (p || (likelihoodMatrix_data[k] < 0.0)) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &ec_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
  }
  c_st.site = &qx_emlrtRSI;
  d_st.site = &ej_emlrtRSI;
  if (loop_ub > 2147483646) {
    e_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < loop_ub; k++) {
    loglhood_data[k] = muDoubleScalarLog(loglhood_data[k]);
  }
  i = allFJE->size[2];
  if (allFJE->size[2] - 1 >= 0) {
    if (allFJE->size[1] < 2) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = allFJE->size[1];
    }
    vlen = allFJE->size[0];
    b_loop_ub = allFJE->size[1];
    if ((allFJE->size[0] != 0) && (allFJE->size[1] != 0)) {
      sizes_idx_0 = allFJE->size[0];
    } else {
      sizes_idx_0 = 0;
    }
    c_loglhood = loglhood->size[0];
  }
  emxInit_int32_T(&st, &iidx, 1, &fi_emlrtRTEI);
  emxInit_boolean_T(&st, &FJEPaddedi, 2, &xh_emlrtRTEI, true);
  emxInit_boolean_T(&st, &b_allFJE, 2, &vh_emlrtRTEI, true);
  emxInit_real_T(&st, &b_loglhood, 1, &bi_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    int32_T nz_data[32];
    boolean_T isTrackUnassigned_data[33];
    if (b_i + 1 > allFJE->size[2]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allFJE->size[2], &rb_emlrtBCI,
                                    &st);
    }
    b_st.site = &nx_emlrtRSI;
    c_st.site = &uh_emlrtRSI;
    d_st.site = &vh_emlrtRSI;
    loop_ub = i2 - i1;
    if (loop_ub == 0) {
      loop_ub = 0;
    } else {
      e_st.site = &wh_emlrtRSI;
      f_st.site = &rx_emlrtRSI;
      for (c_i = 0; c_i < loop_ub; c_i++) {
        xpageoffset = c_i * allFJE->size[0];
        nz_data[c_i] = allFJE_data[(xpageoffset % allFJE->size[0] +
                                    allFJE->size[0] *
                                        (i1 + xpageoffset / allFJE->size[0])) +
                                   allFJE->size[0] * allFJE->size[1] * b_i];
        f_st.site = &sw_emlrtRSI;
        for (k = 2; k <= vlen; k++) {
          i3 = (xpageoffset + k) - 1;
          nz_data[c_i] +=
              allFJE_data[(i3 % allFJE->size[0] +
                           allFJE->size[0] * (i1 + i3 / allFJE->size[0])) +
                          allFJE->size[0] * allFJE->size[1] * b_i];
        }
      }
    }
    isTrackUnassigned_size_idx_1 = loop_ub + 1;
    isTrackUnassigned_data[0] = false;
    for (i3 = 0; i3 < loop_ub; i3++) {
      isTrackUnassigned_data[i3 + 1] = (nz_data[i3] == 0);
    }
    b_st.site = &ox_emlrtRSI;
    c_st.site = &hx_emlrtRSI;
    d_st.site = &ix_emlrtRSI;
    if ((allFJE->size[1] != loop_ub + 1) &&
        ((allFJE->size[0] != 0) && (allFJE->size[1] != 0))) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
    }
    i3 = b_allFJE->size[0] * b_allFJE->size[1];
    b_allFJE->size[0] = allFJE->size[0];
    b_allFJE->size[1] = allFJE->size[1];
    emxEnsureCapacity_boolean_T(&c_st, b_allFJE, i3, &vh_emlrtRTEI);
    FJE_data = b_allFJE->data;
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      c_i = allFJE->size[0];
      for (xpageoffset = 0; xpageoffset < c_i; xpageoffset++) {
        FJE_data[xpageoffset + b_allFJE->size[0] * i3] =
            allFJE_data[(xpageoffset + allFJE->size[0] * i3) +
                        allFJE->size[0] * allFJE->size[1] * b_i];
      }
    }
    i3 = FJEPaddedi->size[0] * FJEPaddedi->size[1];
    FJEPaddedi->size[0] = sizes_idx_0 + 1;
    FJEPaddedi->size[1] = loop_ub + 1;
    emxEnsureCapacity_boolean_T(&c_st, FJEPaddedi, i3, &xh_emlrtRTEI);
    FJEPaddedi_data = FJEPaddedi->data;
    for (i3 = 0; i3 < isTrackUnassigned_size_idx_1; i3++) {
      FJEPaddedi_data[FJEPaddedi->size[0] * i3] = isTrackUnassigned_data[i3];
      for (xpageoffset = 0; xpageoffset < sizes_idx_0; xpageoffset++) {
        FJEPaddedi_data[(xpageoffset + FJEPaddedi->size[0] * i3) + 1] =
            FJE_data[xpageoffset + sizes_idx_0 * i3];
      }
    }
    isTrackUnassigned_size_idx_1 =
        FJEPaddedi->size[0] * FJEPaddedi->size[1] - 1;
    xpageoffset = 0;
    for (c_i = 0; c_i <= isTrackUnassigned_size_idx_1; c_i++) {
      if (FJEPaddedi_data[c_i]) {
        xpageoffset++;
      }
    }
    i3 = iidx->size[0];
    iidx->size[0] = xpageoffset;
    emxEnsureCapacity_int32_T(&st, iidx, i3, &yh_emlrtRTEI);
    iidx_data = iidx->data;
    xpageoffset = 0;
    for (c_i = 0; c_i <= isTrackUnassigned_size_idx_1; c_i++) {
      if (FJEPaddedi_data[c_i]) {
        iidx_data[xpageoffset] = c_i;
        xpageoffset++;
      }
    }
    loop_ub = iidx->size[0];
    i3 = b_loglhood->size[0];
    b_loglhood->size[0] = iidx->size[0];
    emxEnsureCapacity_real_T(&st, b_loglhood, i3, &bi_emlrtRTEI);
    FJEProbs_data = b_loglhood->data;
    for (i3 = 0; i3 < loop_ub; i3++) {
      if (iidx_data[i3] > c_loglhood - 1) {
        emlrtDynamicBoundsCheckR2012b(iidx_data[i3], 0, c_loglhood - 1,
                                      &ub_emlrtBCI, &st);
      }
      FJEProbs_data[i3] = loglhood_data[iidx_data[i3]];
    }
    if (b_i + 1 > logposterior->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, logposterior->size[0],
                                    &vb_emlrtBCI, &st);
    }
    b_st.site = &px_emlrtRSI;
    logposterior_data[b_i] = b_sum(&b_st, b_loglhood);
  }
  emxFree_real_T(&st, &b_loglhood);
  emxFree_boolean_T(&st, &b_allFJE);
  emxFree_boolean_T(&st, &FJEPaddedi);
  st.site = &vw_emlrtRSI;
  b_st.site = &sx_emlrtRSI;
  b_sort(&b_st, logposterior, iidx);
  iidx_data = iidx->data;
  logposterior_data = logposterior->data;
  if (logposterior->size[0] < 1) {
    c_i = 0;
  } else {
    c_i = logposterior->size[0];
  }
  sizes[0] = 1;
  sizes[1] = c_i;
  st.site = &ww_emlrtRSI;
  indexShapeCheck(&st, logposterior->size[0], sizes);
  st.site = &xw_emlrtRSI;
  b_st.site = &ay_emlrtRSI;
  c_st.site = &lf_emlrtRSI;
  d_st.site = &mf_emlrtRSI;
  e_st.site = &nf_emlrtRSI;
  if (c_i < 1) {
    emlrtErrorWithMessageIdR2018a(&e_st, &eb_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  f_st.site = &of_emlrtRSI;
  g_st.site = &pf_emlrtRSI;
  if (c_i <= 2) {
    if (c_i == 1) {
      xmax = logposterior_data[0];
    } else if ((logposterior_data[0] < logposterior_data[1]) ||
               (muDoubleScalarIsNaN(logposterior_data[0]) &&
                (!muDoubleScalarIsNaN(logposterior_data[1])))) {
      xmax = logposterior_data[1];
    } else {
      xmax = logposterior_data[0];
    }
  } else {
    h_st.site = &og_emlrtRSI;
    if (!muDoubleScalarIsNaN(logposterior_data[0])) {
      xpageoffset = 1;
    } else {
      boolean_T exitg1;
      xpageoffset = 0;
      i_st.site = &pg_emlrtRSI;
      if (c_i > 2147483646) {
        j_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= c_i)) {
        if (!muDoubleScalarIsNaN(logposterior_data[k - 1])) {
          xpageoffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (xpageoffset == 0) {
      xmax = logposterior_data[0];
    } else {
      h_st.site = &be_emlrtRSI;
      xmax = logposterior_data[xpageoffset - 1];
      isTrackUnassigned_size_idx_1 = xpageoffset + 1;
      i_st.site = &ce_emlrtRSI;
      if ((xpageoffset + 1 <= c_i) && (c_i > 2147483646)) {
        j_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }
      for (k = isTrackUnassigned_size_idx_1; k <= c_i; k++) {
        x = logposterior_data[k - 1];
        if (xmax < x) {
          xmax = x;
        }
      }
    }
  }
  b_st.site = &by_emlrtRSI;
  i = loglhood->size[0];
  loglhood->size[0] = c_i;
  emxEnsureCapacity_real_T(&b_st, loglhood, i, &wh_emlrtRTEI);
  loglhood_data = loglhood->data;
  xpageoffset = (c_i / 2) << 1;
  isTrackUnassigned_size_idx_1 = xpageoffset - 2;
  for (i = 0; i <= isTrackUnassigned_size_idx_1; i += 2) {
    r = _mm_loadu_pd(&logposterior_data[i]);
    _mm_storeu_pd(&loglhood_data[i], _mm_sub_pd(r, _mm_set1_pd(xmax)));
  }
  for (i = xpageoffset; i < c_i; i++) {
    loglhood_data[i] = logposterior_data[i] - xmax;
  }
  c_st.site = &by_emlrtRSI;
  b_exp(&c_st, loglhood);
  c_st.site = &by_emlrtRSI;
  x = b_sum(&c_st, loglhood);
  emxFree_real_T(&b_st, &loglhood);
  if (x < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &ec_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
  }
  x = muDoubleScalarLog(x);
  x += xmax;
  i = FJEProbs->size[0];
  FJEProbs->size[0] = c_i;
  emxEnsureCapacity_real_T(sp, FJEProbs, i, &ai_emlrtRTEI);
  FJEProbs_data = FJEProbs->data;
  for (i = 0; i <= isTrackUnassigned_size_idx_1; i += 2) {
    r = _mm_loadu_pd(&logposterior_data[i]);
    _mm_storeu_pd(&FJEProbs_data[i], _mm_sub_pd(r, _mm_set1_pd(x)));
  }
  for (i = xpageoffset; i < c_i; i++) {
    FJEProbs_data[i] = logposterior_data[i] - x;
  }
  st.site = &xw_emlrtRSI;
  b_exp(&st, FJEProbs);
  if (logposterior->size[0] < 1) {
    loop_ub = 0;
  } else {
    if (iidx->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, iidx->size[0], &tb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (logposterior->size[0] > iidx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(logposterior->size[0], 1, iidx->size[0],
                                    &sb_emlrtBCI, (emlrtConstCTX)sp);
    }
    loop_ub = logposterior->size[0];
  }
  emxFree_real_T(sp, &logposterior);
  sizes[0] = 1;
  sizes[1] = loop_ub;
  st.site = &yw_emlrtRSI;
  indexShapeCheck(&st, iidx->size[0], sizes);
  i = FJE->size[0] * FJE->size[1] * FJE->size[2];
  FJE->size[0] = allFJE->size[0];
  FJE->size[1] = allFJE->size[1];
  FJE->size[2] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, FJE, i, &ci_emlrtRTEI);
  FJE_data = FJE->data;
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = allFJE->size[1];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      c_i = allFJE->size[0];
      for (i2 = 0; i2 < c_i; i2++) {
        if ((iidx_data[i] < 1) || (iidx_data[i] > allFJE->size[2])) {
          emlrtDynamicBoundsCheckR2012b(iidx_data[i], 1, allFJE->size[2],
                                        &wb_emlrtBCI, (emlrtConstCTX)sp);
        }
        FJE_data[(i2 + FJE->size[0] * i1) + FJE->size[0] * FJE->size[1] * i] =
            allFJE_data[(i2 + allFJE->size[0] * i1) +
                        allFJE->size[0] * allFJE->size[1] * (iidx_data[i] - 1)];
      }
    }
  }
  emxFree_int32_T(sp, &iidx);
  emxFree_boolean_T(sp, &allFJE);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (feasibleAndSortKBestEvents.c) */
