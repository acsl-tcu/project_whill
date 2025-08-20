/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removePlane_ransac.c
 *
 * Code generation for function 'removePlane_ransac'
 *
 */

/* Include files */
#include "removePlane_ransac.h"
#include "eml_int_forloop_overflow_check.h"
#include "msac.h"
#include "polyval.h"
#include "removePlane_ransac_data.h"
#include "removePlane_ransac_emxutil.h"
#include "removePlane_ransac_types.h"
#include "rt_nonfinite.h"
#include "unsafeSxfun.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    4,                    /* lineNo */
    "removePlane_ransac", /* fcnName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_ransac.m" /* pathName
                                                                          */
};

static emlrtRSInfo b_emlrtRSI = {
    180,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo c_emlrtRSI = {
    164,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo d_emlrtRSI = {
    148,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo e_emlrtRSI = {
    199,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo f_emlrtRSI = {
    205,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    207,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    93,                   /* lineNo */
    "validateattributes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    294,                /* lineNo */
    "checkMaxDistance", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo sb_emlrtRSI = {
    3, /* lineNo */
    "@(model,points)sum((points(:,2)-polyval(model,points(:,1))).^2,2)", /* fcnName
                                                                          */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_ransac.m" /* pathName
                                                                          */
};

static emlrtRSInfo xb_emlrtRSI = {
    112,                /* lineNo */
    "blockedSummation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    173,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    188,                  /* lineNo */
    5,                    /* colNo */
    "checkRuntimeStatus", /* fName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pName
                                                                            */
};

static emlrtRTEInfo b_emlrtRTEI = {
    190,                  /* lineNo */
    1,                    /* colNo */
    "checkRuntimeStatus", /* fName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pName
                                                                            */
};

static emlrtRTEInfo c_emlrtRTEI = {
    13,                 /* lineNo */
    37,                 /* colNo */
    "validatenonempty", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonempty.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    13,                /* lineNo */
    37,                /* colNo */
    "validateinteger", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateinteger.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    14,                    /* lineNo */
    37,                    /* colNo */
    "validatenonnegative", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnegative.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    1,  /* nDims */
    3,  /* lineNo */
    36, /* colNo */
    "@(model,points)sum((points(:,2)-polyval(model,points(:,1))).^2,2)", /* fName
                                                                          */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_ransac.m" /* pName
                                                                          */
};

static emlrtRTEInfo q_emlrtRTEI = {
    162,      /* lineNo */
    5,        /* colNo */
    "ransac", /* fName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pName
                                                                            */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    33,        /* lineNo */
    20,        /* colNo */
    "polyval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" /* pName
                                                                            */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    3,                    /* lineNo */
    48,                   /* colNo */
    "removePlane_ransac", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_ransac.m" /* pName
                                                                          */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    146,                /* lineNo */
    24,                 /* colNo */
    "blockedSummation", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    3,                    /* lineNo */
    35,                   /* colNo */
    "removePlane_ransac", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_ransac.m" /* pName
                                                                          */
};

static emlrtRSInfo tc_emlrtRSI =
    {
        31,            /* lineNo */
        "unsafeSxfun", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\unsafeSxfun.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    39,        /* lineNo */
    "polyval", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" /* pathName
                                                                            */
};

/* Function Definitions */
void removePlane_ransac(const emlrtStack *sp, const emxArray_real_T *data,
                        real_T sampleSize, real_T maxDistance,
                        real_T model_data[], int32_T model_size[2],
                        emxArray_boolean_T *inlierIdx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T i;
  int32_T status;
  boolean_T reachedMaxSkipTrials;
  boolean_T *inlierIdx_data;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &d_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  d_st.site = &h_emlrtRSI;
  if (data->size[0] == 0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:ransac:expectedNonempty", 3, 4, 4, "data");
  }
  c_st.site = &f_emlrtRSI;
  d_st.site = &h_emlrtRSI;
  if (muDoubleScalarIsInf(sampleSize) || muDoubleScalarIsNaN(sampleSize) ||
      (!(muDoubleScalarFloor(sampleSize) == sampleSize))) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:ransac:expectedInteger", 3, 4, 10, "sampleSize");
  }
  d_st.site = &h_emlrtRSI;
  if (sampleSize <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 10, "sampleSize");
  }
  c_st.site = &g_emlrtRSI;
  d_st.site = &i_emlrtRSI;
  e_st.site = &h_emlrtRSI;
  if (maxDistance < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &f_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:ransac:expectedNonnegative", 3, 4, 11, "maxDistance");
  }
  e_st.site = &h_emlrtRSI;
  if (muDoubleScalarIsInf(maxDistance) || muDoubleScalarIsNaN(maxDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ransac:expectedFinite", 3, 4, 11, "maxDistance");
  }
  if (data->size[0] < sampleSize) {
    int32_T loop_ub;
    status = 1;
    model_size[0] = 0;
    model_size[1] = 0;
    i = inlierIdx->size[0];
    inlierIdx->size[0] = data->size[0];
    emxEnsureCapacity_boolean_T(&st, inlierIdx, i, &q_emlrtRTEI);
    inlierIdx_data = inlierIdx->data;
    loop_ub = data->size[0];
    for (i = 0; i < loop_ub; i++) {
      inlierIdx_data[i] = false;
    }
  } else {
    boolean_T isFound;
    b_st.site = &c_emlrtRSI;
    isFound = msac(&b_st, data, sampleSize, maxDistance, model_data, model_size,
                   inlierIdx, &reachedMaxSkipTrials);
    if (isFound) {
      status = 0;
    } else {
      status = 2;
    }
  }
  b_st.site = &b_emlrtRSI;
  if (status == 1) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &emlrtRTEI, "vision:ransac:notEnoughDataPts",
        "vision:ransac:notEnoughDataPts", 2, 6, sampleSize);
  }
  if (status == 2) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                  "vision:ransac:notEnoughInliers",
                                  "vision:ransac:notEnoughInliers", 0);
  }
  /*  modelInliers = polyfit(data(inlierIdx,1),data(inlierIdx,2),1); */
}

void removePlane_ransac_anonFcn2(const emlrtStack *sp, const real_T model[2],
                                 const emxArray_real_T *points,
                                 emxArray_real_T *varargout_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_real_T *y;
  const real_T *points_data;
  real_T b_model;
  real_T *varargout_1_data;
  real_T *y_data;
  int32_T i;
  int32_T scalarLB;
  int32_T vstride;
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
  points_data = points->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &y, 1, &lb_emlrtRTEI);
  i = y->size[0];
  y->size[0] = points->size[0];
  emxEnsureCapacity_real_T(sp, y, i, &hb_emlrtRTEI);
  if (points->size[0] != 0) {
    i = y->size[0];
    y->size[0] = points->size[0];
    emxEnsureCapacity_real_T(sp, y, i, &ib_emlrtRTEI);
    y_data = y->data;
    vstride = points->size[0];
    for (i = 0; i < vstride; i++) {
      y_data[i] = model[0];
    }
    if (points->size[0] == y->size[0]) {
      int32_T vectorUB;
      b_model = model[1];
      i = y->size[0];
      y->size[0] = points->size[0];
      emxEnsureCapacity_real_T(sp, y, i, &ib_emlrtRTEI);
      y_data = y->data;
      vstride = points->size[0];
      scalarLB = (points->size[0] / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        __m128d r;
        r = _mm_loadu_pd(&y_data[i]);
        _mm_storeu_pd(&y_data[i],
                      _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&points_data[i]), r),
                                 _mm_set1_pd(b_model)));
      }
      for (i = scalarLB; i < vstride; i++) {
        y_data[i] = points_data[i] * y_data[i] + b_model;
      }
    } else {
      st.site = &uc_emlrtRSI;
      b_binary_expand_op(&st, y, points, model);
    }
  }
  if ((points->size[0] != y->size[0]) &&
      ((points->size[0] != 1) && (y->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(points->size[0], y->size[0], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  st.site = &sb_emlrtRSI;
  b_st.site = &tb_emlrtRSI;
  if (points->size[0] == y->size[0]) {
    i = y->size[0];
    y->size[0] = points->size[0];
    emxEnsureCapacity_real_T(&b_st, y, i, &jb_emlrtRTEI);
    y_data = y->data;
    vstride = points->size[0];
    for (i = 0; i < vstride; i++) {
      b_model = points_data[i + points->size[0]] - y_data[i];
      y_data[i] = b_model * b_model;
    }
  } else {
    c_st.site = &tc_emlrtRSI;
    binary_expand_op(&c_st, y, points);
    y_data = y->data;
  }
  st.site = &sb_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  d_st.site = &wb_emlrtRSI;
  if (y->size[0] == 0) {
    varargout_1->size[0] = 0;
  } else {
    e_st.site = &xb_emlrtRSI;
    vstride = y->size[0];
    i = varargout_1->size[0];
    varargout_1->size[0] = y->size[0];
    emxEnsureCapacity_real_T(&e_st, varargout_1, i, &kb_emlrtRTEI);
    varargout_1_data = varargout_1->data;
    f_st.site = &yb_emlrtRSI;
    if (y->size[0] > 2147483646) {
      g_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&g_st);
    }
    for (scalarLB = 0; scalarLB < vstride; scalarLB++) {
      varargout_1_data[scalarLB] = y_data[scalarLB];
    }
  }
  emxFree_real_T(&d_st, &y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (removePlane_ransac.c) */
