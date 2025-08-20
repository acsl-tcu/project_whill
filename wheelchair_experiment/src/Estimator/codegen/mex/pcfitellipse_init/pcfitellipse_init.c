/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse_init.c
 *
 * Code generation for function 'pcfitellipse_init'
 *
 */

/* Include files */
#include "pcfitellipse_init.h"
#include "checkLinearInputs.h"
#include "computeForwardDifferences.h"
#include "computeObjective_.h"
#include "driver1.h"
#include "initActiveSet.h"
#include "msac.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "pcfitellipse_init_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "unsafeSxfun.h"
#include "updateWorkingSetForNewQP.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    14,                  /* lineNo */
    "pcfitellipse_init", /* fcnName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    16,                  /* lineNo */
    "pcfitellipse_init", /* fcnName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    180,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo d_emlrtRSI = {
    164,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo e_emlrtRSI = {
    148,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo f_emlrtRSI = {
    199,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    205,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    207,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    261,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo j_emlrtRSI = {
    263,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo k_emlrtRSI = {
    93,                   /* lineNo */
    "validateattributes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    294,                /* lineNo */
    "checkMaxDistance", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo m_emlrtRSI = {
    276,                 /* lineNo */
    "checkMaxNumTrials", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo n_emlrtRSI = {
    288,               /* lineNo */
    "checkConfidence", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo db_emlrtRSI = {
    7, /* lineNo */
    "@(points)fmincon(@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a("
    "2))*cos(a(5)))/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))"
    "+(points(:,2)-a(2))*-sin(a(5)))/"
    "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),1),a0,"
    "A,B,Aeq,Beq,lb,ub,nonl"
    "con,options)", /* fcnName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    1,         /* lineNo */
    "fmincon", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\optim\\eml\\fmincon.p" /* pathName
                                                                         */
};

static emlrtRSInfo ib_emlrtRSI = {
    1,                                /* lineNo */
    "evalObjAndConstrAndDerivatives", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "ObjNonlinEvaluator\\evalObjAndConstrAndDerivatives.p" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI =
    {
        7, /* lineNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fcnName */
        "C:\\Users\\student\\OneDrive - "
        "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad"
        "\xa6 Tokyo City University\\g"
        "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI =
    {
        8, /* lineNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fcnName */
        "C:\\Users\\student\\OneDrive - "
        "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad"
        "\xa6 Tokyo City University\\g"
        "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI =
    {
        9, /* lineNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fcnName */
        "C:\\Users\\student\\OneDrive - "
        "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad"
        "\xa6 Tokyo City University\\g"
        "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    14,      /* lineNo */
    "hypot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\hypot.m" /* pathName
                                                                        */
};

static emlrtRSInfo pb_emlrtRSI = {
    66,      /* lineNo */
    "ixfun", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" /* pathName
                                                                            */
};

static emlrtRSInfo qb_emlrtRSI = {
    45,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    19,             /* lineNo */
    "scalexpAlloc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc."
    "m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI =
    {
        10,    /* lineNo */
        "exp", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" /* pathName
                                                                          */
};

static emlrtRSInfo tb_emlrtRSI = {
    33,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" /* pathName */
};

static emlrtRSInfo ii_emlrtRSI = {
    12,                                                    /* lineNo */
    "@(model,points)sum(distanceEllipse(model,points),2)", /* fcnName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pathName */
};

static emlrtRSInfo ti_emlrtRSI = {
    39,    /* lineNo */
    "cat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pathName
                                                                          */
};

static emlrtRSInfo ui_emlrtRSI = {
    113,        /* lineNo */
    "cat_impl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pathName
                                                                          */
};

static emlrtECInfo emlrtECI = {
    -1,                  /* nDims */
    3,                   /* lineNo */
    5,                   /* colNo */
    "pcfitellipse_init", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                  /* nDims */
    4,                   /* lineNo */
    5,                   /* colNo */
    "pcfitellipse_init", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pName */
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

static emlrtRTEInfo h_emlrtRTEI = {
    22,           /* lineNo */
    27,           /* colNo */
    "validatelt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatelt.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    16,                  /* lineNo */
    22,                  /* colNo */
    "points",            /* aName */
    "pcfitellipse_init", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    16,                  /* lineNo */
    43,                  /* colNo */
    "points",            /* aName */
    "pcfitellipse_init", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    1,                /* iFirst */
    7,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compressBounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\compressBounds.p", /* pName */
    3                               /* checkKind */
};

static emlrtRTEInfo n_emlrtRTEI = {
    1,         /* lineNo */
    1,         /* colNo */
    "checkX0", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\optimlib\\+optim\\+coder\\+"
    "validate\\checkX0.p" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    1,         /* lineNo */
    1,         /* colNo */
    "fmincon", /* fName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\optim\\eml\\fmincon.p" /* pName
                                                                         */
};

static emlrtBCInfo f_emlrtBCI = {
    1,         /* iFirst */
    5,         /* iLast */
    1,         /* lineNo */
    1,         /* colNo */
    "",        /* aName */
    "fmincon", /* fName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\optim\\eml\\fmincon.p", /* pName
                                                                          */
    3 /* checkKind */
};

static emlrtECInfo c_emlrtECI =
    {
        1,  /* nDims */
        7,  /* lineNo */
        48, /* colNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fName */
        "C:\\Users\\student\\OneDrive - "
        "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad"
        "\xa6 Tokyo City University\\g"
        "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    1,                                   /* nDims */
    21,                                  /* lineNo */
    21,                                  /* colNo */
    "pcfitellipse_init/distanceEllipse", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\IMMEst\\src\\Estimator\\pcfitellipse_init.m" /* pName */
};

/* Function Declarations */
static void plus(real_T in1_data[], int32_T *in1_size, const real_T in2_data[],
                 const int32_T *in2_size);

/* Function Definitions */
static void plus(real_T in1_data[], int32_T *in1_size, const real_T in2_data[],
                 const int32_T *in2_size)
{
  real_T b_in1_data[1500];
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in2_size == 1) {
    loop_ub = *in1_size;
  } else {
    loop_ub = *in2_size;
  }
  stride_0_0 = (*in1_size != 1);
  stride_1_0 = (*in2_size != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_0] + in2_data[i * stride_1_0];
  }
  *in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in1_data[0], (uint32_T)loop_ub * sizeof(real_T));
  }
}

real_T c_pcfitellipse_init_anonFcn1_an(const emlrtStack *sp,
                                       const real_T points_data[],
                                       const int32_T points_size[2],
                                       const real_T a[5])
{
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T b_tmp_data[1500];
  real_T r_data[1500];
  real_T tmp_data[1500];
  real_T x_data[1500];
  real_T b;
  real_T b_a;
  real_T c_a;
  real_T varargout_1;
  real_T x_tmp;
  int32_T i;
  int32_T loop_ub;
  int32_T r_size;
  int32_T scalarLB_tmp;
  int32_T tmp_size;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
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
  x_tmp = muDoubleScalarSin(a[4]);
  b_a = a[0];
  r_size = points_size[0];
  loop_ub = points_size[0];
  b = muDoubleScalarCos(a[4]);
  c_a = a[1];
  scalarLB_tmp = (points_size[0] / 2) << 1;
  vectorUB_tmp = scalarLB_tmp - 2;
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    _mm_storeu_pd(
        &r_data[i],
        _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(&points_data[i]), _mm_set1_pd(b_a)),
                   _mm_set1_pd(-x_tmp)));
    _mm_storeu_pd(
        &x_data[i],
        _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(&points_data[i + points_size[0]]),
                              _mm_set1_pd(c_a)),
                   _mm_set1_pd(b)));
  }
  for (i = scalarLB_tmp; i < loop_ub; i++) {
    r_data[i] = (points_data[i] - b_a) * -x_tmp;
    x_data[i] = (points_data[i + points_size[0]] - c_a) * b;
  }
  b_a = a[0];
  tmp_size = points_size[0];
  loop_ub = points_size[0];
  c_a = a[1];
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    _mm_storeu_pd(
        &tmp_data[i],
        _mm_mul_pd(_mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(&points_data[i]),
                                         _mm_set1_pd(b_a)),
                              _mm_set1_pd(-1.0)),
                   _mm_set1_pd(b)));
    _mm_storeu_pd(
        &b_tmp_data[i],
        _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(&points_data[i + points_size[0]]),
                              _mm_set1_pd(c_a)),
                   _mm_set1_pd(-x_tmp)));
  }
  for (i = scalarLB_tmp; i < loop_ub; i++) {
    tmp_data[i] = -(points_data[i] - b_a) * b;
    b_tmp_data[i] = (points_data[i + points_size[0]] - c_a) * -x_tmp;
  }
  st.site = &kb_emlrtRSI;
  b_st.site = &nb_emlrtRSI;
  loop_ub = r_size / 2 * 2;
  vectorUB = loop_ub - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&r_data[i]);
    r1 = _mm_loadu_pd(&x_data[i]);
    r = _mm_add_pd(r, r1);
    r = _mm_div_pd(r, _mm_set1_pd(a[2]));
    r = _mm_mul_pd(r, r);
    _mm_storeu_pd(&r_data[i], r);
  }
  for (i = loop_ub; i < r_size; i++) {
    x_tmp = (r_data[i] + x_data[i]) / a[2];
    r_data[i] = x_tmp * x_tmp;
  }
  st.site = &lb_emlrtRSI;
  b_st.site = &nb_emlrtRSI;
  loop_ub = tmp_size / 2 * 2;
  vectorUB = loop_ub - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&tmp_data[i]);
    r1 = _mm_loadu_pd(&b_tmp_data[i]);
    r = _mm_add_pd(r, r1);
    r = _mm_div_pd(r, _mm_set1_pd(a[3]));
    r = _mm_mul_pd(r, r);
    _mm_storeu_pd(&x_data[i], r);
  }
  for (i = loop_ub; i < tmp_size; i++) {
    x_tmp = (tmp_data[i] + b_tmp_data[i]) / a[3];
    x_data[i] = x_tmp * x_tmp;
  }
  st.site = &kb_emlrtRSI;
  b_st.site = &nb_emlrtRSI;
  tmp_size = points_size[0];
  loop_ub = r_size / 2 * 2;
  vectorUB = loop_ub - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&r_data[i]);
    r1 = _mm_loadu_pd(&x_data[i]);
    r = _mm_add_pd(r, r1);
    r = _mm_sub_pd(r, _mm_set1_pd(1.0));
    r = _mm_mul_pd(r, r);
    _mm_storeu_pd(&x_data[i], r);
  }
  for (i = loop_ub; i < r_size; i++) {
    x_tmp = (r_data[i] + x_data[i]) - 1.0;
    x_data[i] = x_tmp * x_tmp;
  }
  st.site = &mb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  c_st.site = &pb_emlrtRSI;
  d_st.site = &qb_emlrtRSI;
  e_st.site = &rb_emlrtRSI;
  r_size = points_size[0];
  i = points_size[0];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    r_data[loop_ub] = muDoubleScalarHypot(
        points_data[loop_ub], points_data[loop_ub + points_size[0]]);
  }
  x_tmp = muDoubleScalarHypot(a[0], a[1]);
  st.site = &mb_emlrtRSI;
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    r = _mm_loadu_pd(&r_data[i]);
    _mm_storeu_pd(&r_data[i], _mm_sub_pd(r, _mm_set1_pd(x_tmp)));
  }
  for (i = scalarLB_tmp; i < r_size; i++) {
    r_data[i] -= x_tmp;
  }
  b_st.site = &sb_emlrtRSI;
  c_st.site = &tb_emlrtRSI;
  for (loop_ub = 0; loop_ub < r_size; loop_ub++) {
    r_data[loop_ub] = muDoubleScalarExp(r_data[loop_ub]);
  }
  if ((tmp_size != points_size[0]) &&
      ((tmp_size != 1) && (points_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(tmp_size, points_size[0], &c_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  st.site = &kb_emlrtRSI;
  if (tmp_size == points_size[0]) {
    loop_ub = (tmp_size / 2) << 1;
    vectorUB = loop_ub - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&x_data[i]);
      r1 = _mm_loadu_pd(&r_data[i]);
      _mm_storeu_pd(&x_data[i], _mm_add_pd(r, r1));
    }
    for (i = loop_ub; i < tmp_size; i++) {
      x_data[i] += r_data[i];
    }
  } else {
    plus(x_data, &tmp_size, r_data, &points_size[0]);
  }
  b_st.site = &ub_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  d_st.site = &wb_emlrtRSI;
  if (tmp_size == 0) {
    varargout_1 = 0.0;
  } else {
    e_st.site = &xb_emlrtRSI;
    f_st.site = &yb_emlrtRSI;
    g_st.site = &ac_emlrtRSI;
    varargout_1 = sumColumnB(&g_st, x_data, tmp_size);
  }
  return varargout_1;
}

void pcfitellipse_init(pcfitellipse_initStackData *SD, const emlrtStack *sp,
                       const real32_T x_data[], const int32_T x_size[1],
                       const real32_T y_data[], const int32_T y_size[1],
                       const real_T a0[5], real_T sampleSize,
                       real_T maxDistance, const real_T A[5], real_T B,
                       const real_T lb[5], const real_T ub[5], real_T Num,
                       real_T CNum, real_T modelRANSAC_data[],
                       int32_T modelRANSAC_size[2], real_T inlier_data[],
                       int32_T inlier_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T points_size[2];
  int32_T i;
  int32_T inlierIdx_size;
  int32_T loop_ub;
  int32_T status;
  int16_T tmp_data[1500];
  int16_T b_i;
  boolean_T inlierIdx_data[1500];
  boolean_T reachedMaxSkipTrials;
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
  points_size[0] = x_size[0];
  points_size[1] = 2;
  loop_ub = x_size[0] << 1;
  if (loop_ub - 1 >= 0) {
    memset(&SD->f0.points_data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
  }
  /* 点群を保存する配列の初期化 */
  emlrtSubAssignSizeCheckR2012b(&x_size[0], 1, &x_size[0], 1, &emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = x_size[0];
  for (inlierIdx_size = 0; inlierIdx_size < loop_ub; inlierIdx_size++) {
    SD->f0.points_data[inlierIdx_size] = x_data[inlierIdx_size];
  }
  /* 点群のx座標をdouble型へ */
  emlrtSubAssignSizeCheckR2012b(&points_size[0], 1, &y_size[0], 1, &b_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = y_size[0];
  for (inlierIdx_size = 0; inlierIdx_size < loop_ub; inlierIdx_size++) {
    SD->f0.points_data[inlierIdx_size + points_size[0]] =
        y_data[inlierIdx_size];
  }
  /* 点群のy座標をdouble型へ */
  /* fminconの制約条件 */
  /* ソルバーの設定。このままでOK */
  /* RANSACでモデルの候補生成のための計算式。サンプリングした点群のみ使ってfminconを解く。fminconの使い方はドキュメントを参照
   */
  /* ransacはmatlabの関数。modelRANSACはRANSACで計算されたx,y,alpha,beta,theta(楕円中心,長軸,短軸,方向角)の行列,inlierIdxは各点群がInlierかどうか1,0で表示
   */
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  d_st.site = &k_emlrtRSI;
  if (x_size[0] == 0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:ransac:expectedNonempty", 3, 4, 4, "data");
  }
  c_st.site = &g_emlrtRSI;
  d_st.site = &k_emlrtRSI;
  if (muDoubleScalarIsInf(sampleSize) || muDoubleScalarIsNaN(sampleSize) ||
      (!(muDoubleScalarFloor(sampleSize) == sampleSize))) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:ransac:expectedInteger", 3, 4, 10, "sampleSize");
  }
  d_st.site = &k_emlrtRSI;
  if (sampleSize <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 10, "sampleSize");
  }
  c_st.site = &h_emlrtRSI;
  d_st.site = &l_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  if (maxDistance < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &f_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:ransac:expectedNonnegative", 3, 4, 11, "maxDistance");
  }
  e_st.site = &k_emlrtRSI;
  if (muDoubleScalarIsInf(maxDistance) || muDoubleScalarIsNaN(maxDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ransac:expectedFinite", 3, 4, 11, "maxDistance");
  }
  c_st.site = &i_emlrtRSI;
  d_st.site = &m_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  if (muDoubleScalarIsInf(Num) || muDoubleScalarIsNaN(Num) ||
      (!(muDoubleScalarFloor(Num) == Num))) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:ransac:expectedInteger", 3, 4, 12, "MaxNumTrials");
  }
  e_st.site = &k_emlrtRSI;
  if (Num <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 12, "MaxNumTrials");
  }
  c_st.site = &j_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  if (CNum <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 10, "Confidence");
  }
  e_st.site = &k_emlrtRSI;
  if (!(CNum < 100.0)) {
    emlrtErrorWithMessageIdR2018a(&e_st, &h_emlrtRTEI,
                                  "MATLAB:validateattributes:expectedScalar",
                                  "MATLAB:ransac:notLess", 9, 4, 10,
                                  "Confidence", 4, 1, "<", 4, 3, "100");
  }
  if (x_size[0] < sampleSize) {
    status = 1;
    modelRANSAC_size[0] = 0;
    modelRANSAC_size[1] = 0;
    inlierIdx_size = x_size[0];
    loop_ub = x_size[0];
    memset(&inlierIdx_data[0], 0, (uint32_T)loop_ub * sizeof(boolean_T));
  } else {
    boolean_T isFound;
    b_st.site = &d_emlrtRSI;
    isFound =
        msac(&b_st, SD->f0.points_data, points_size, sampleSize, maxDistance,
             CNum, Num, a0, A, B, lb, ub, modelRANSAC_data, modelRANSAC_size,
             inlierIdx_data, &inlierIdx_size, &reachedMaxSkipTrials);
    if (isFound) {
      status = 0;
    } else {
      status = 2;
    }
  }
  b_st.site = &c_emlrtRSI;
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
  inlierIdx_size--;
  loop_ub = 0;
  status = 0;
  for (i = 0; i <= inlierIdx_size; i++) {
    if (inlierIdx_data[i]) {
      loop_ub++;
      tmp_data[status] = (int16_T)i;
      status++;
    }
  }
  st.site = &b_emlrtRSI;
  for (inlierIdx_size = 0; inlierIdx_size < loop_ub; inlierIdx_size++) {
    b_i = tmp_data[inlierIdx_size];
    if (b_i > points_size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, points_size[0] - 1, &emlrtBCI, &st);
    }
  }
  for (inlierIdx_size = 0; inlierIdx_size < loop_ub; inlierIdx_size++) {
    b_i = tmp_data[inlierIdx_size];
    if (b_i > points_size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, points_size[0] - 1, &b_emlrtBCI,
                                    &st);
    }
  }
  b_st.site = &ti_emlrtRSI;
  c_st.site = &ui_emlrtRSI;
  inlier_size[0] = loop_ub;
  inlier_size[1] = 2;
  for (inlierIdx_size = 0; inlierIdx_size < loop_ub; inlierIdx_size++) {
    b_i = tmp_data[inlierIdx_size];
    inlier_data[inlierIdx_size] = SD->f0.points_data[b_i];
    inlier_data[inlierIdx_size + loop_ub] =
        SD->f0.points_data[b_i + points_size[0]];
  }
}

void pcfitellipse_init_anonFcn1(const emlrtStack *sp, const real_T a0[5],
                                const real_T A[5], real_T B, const real_T lb[5],
                                const real_T ub[5], const real_T points_data[],
                                const int32_T points_size[2],
                                real_T varargout_1[5])
{
  b_struct_T MeritFunction;
  d_struct_T memspace;
  e_struct_T QRManager;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  f_struct_T CholManager;
  h_struct_T TrialState;
  i_coder_internal_stickyStruct FcnEvaluator;
  i_struct_T WorkingSet;
  j_struct_T FiniteDifferences;
  struct_T QPObjective;
  real_T Hessian[25];
  real_T c;
  int32_T i;
  int32_T idx;
  int32_T loop_ub_tmp;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  int8_T obj_tmp[5];
  int8_T b_i;
  boolean_T varargin_1[5];
  boolean_T exitg1;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &eb_emlrtRSI;
  for (i = 0; i < 5; i++) {
    c = a0[i];
    varargin_1[i] = ((!muDoubleScalarIsInf(c)) && (!muDoubleScalarIsNaN(c)));
  }
  y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 5)) {
    if (!varargin_1[i]) {
      y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }
  if (!y) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &n_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
        "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 2, "x0");
  }
  b_st.site = &eb_emlrtRSI;
  checkLinearInputs(&b_st, A, B, lb, ub);
  TrialState.nVarMax = 7;
  TrialState.mNonlinIneq = 0;
  TrialState.mNonlinEq = 0;
  TrialState.mIneq = 1;
  TrialState.mEq = 0;
  TrialState.iNonIneq0 = 2;
  TrialState.iNonEq0 = 1;
  TrialState.sqpFval_old = 0.0;
  TrialState.sqpIterations = 0;
  TrialState.sqpExitFlag = 0;
  memset(&TrialState.lambdasqp[0], 0, 13U * sizeof(real_T));
  TrialState.steplength = 1.0;
  for (i = 0; i < 7; i++) {
    TrialState.delta_x[i] = 0.0;
  }
  TrialState.fstar = 0.0;
  TrialState.firstorderopt = 0.0;
  memset(&TrialState.lambda[0], 0, 13U * sizeof(real_T));
  TrialState.state = 0;
  TrialState.maxConstr = 0.0;
  TrialState.iterations = 0;
  for (i = 0; i < 5; i++) {
    TrialState.xstarsqp[i] = a0[i];
  }
  FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.points
      .size[0] = points_size[0];
  FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.points
      .size[1] = 2;
  loop_ub_tmp = points_size[0] << 1;
  if (loop_ub_tmp - 1 >= 0) {
    memcpy(&FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .points.data[0],
           &points_data[0], (uint32_T)loop_ub_tmp * sizeof(real_T));
  }
  WorkingSet.nVar = 5;
  WorkingSet.nVarOrig = 5;
  WorkingSet.nVarMax = 7;
  WorkingSet.ldA = 7;
  WorkingSet.bineq = 0.0;
  for (i = 0; i < 7; i++) {
    WorkingSet.Aineq[i] = 0.0;
    WorkingSet.lb[i] = 0.0;
    WorkingSet.ub[i] = 0.0;
  }
  WorkingSet.mEqRemoved = 0;
  memset(&WorkingSet.ATwset[0], 0, 91U * sizeof(real_T));
  WorkingSet.nActiveConstr = 0;
  memset(&WorkingSet.bwset[0], 0, 13U * sizeof(real_T));
  memset(&WorkingSet.maxConstrWorkspace[0], 0, 13U * sizeof(real_T));
  for (i = 0; i < 13; i++) {
    WorkingSet.isActiveConstr[i] = false;
    WorkingSet.Wid[i] = 0;
    WorkingSet.Wlocalidx[i] = 0;
  }
  for (i = 0; i < 5; i++) {
    WorkingSet.nWConstr[i] = 0;
  }
  WorkingSet.probType = 3;
  WorkingSet.SLACK0 = 1.0E-5;
  b_st.site = &eb_emlrtRSI;
  for (i = 0; i < 7; i++) {
    WorkingSet.indexLB[i] = 0;
    WorkingSet.indexUB[i] = 0;
    WorkingSet.indexFixed[i] = 0;
  }
  mLB = 0;
  mUB = 0;
  mFixed = 0;
  for (idx = 0; idx < 5; idx++) {
    boolean_T guard1 = false;
    c = lb[idx];
    guard1 = false;
    if ((!muDoubleScalarIsInf(c)) && (!muDoubleScalarIsNaN(c))) {
      if (muDoubleScalarAbs(c - ub[idx]) < 1.0E-6) {
        mFixed++;
        if (mFixed > 7) {
          emlrtDynamicBoundsCheckR2012b(8, 1, 7, &e_emlrtBCI, &b_st);
        }
        WorkingSet.indexFixed[mFixed - 1] = idx + 1;
      } else {
        mLB++;
        if (mLB > 7) {
          emlrtDynamicBoundsCheckR2012b(8, 1, 7, &e_emlrtBCI, &b_st);
        }
        WorkingSet.indexLB[mLB - 1] = idx + 1;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      c = ub[idx];
      if ((!muDoubleScalarIsInf(c)) && (!muDoubleScalarIsNaN(c))) {
        mUB++;
        if (mUB > 7) {
          emlrtDynamicBoundsCheckR2012b(8, 1, 7, &e_emlrtBCI, &b_st);
        }
        WorkingSet.indexUB[mUB - 1] = idx + 1;
      }
    }
  }
  b_st.site = &eb_emlrtRSI;
  i = ((mLB + mUB) + mFixed) + 1;
  WorkingSet.mConstr = i;
  WorkingSet.mConstrOrig = i;
  WorkingSet.mConstrMax = 13;
  obj_tmp[0] = (int8_T)mFixed;
  obj_tmp[1] = 0;
  obj_tmp[2] = 1;
  obj_tmp[3] = (int8_T)mLB;
  obj_tmp[4] = (int8_T)mUB;
  for (i = 0; i < 5; i++) {
    b_i = obj_tmp[i];
    WorkingSet.sizes[i] = b_i;
    WorkingSet.sizesNormal[i] = b_i;
  }
  obj_tmp[0] = (int8_T)mFixed;
  obj_tmp[1] = 0;
  obj_tmp[2] = 1;
  obj_tmp[3] = (int8_T)(mLB + 1);
  obj_tmp[4] = (int8_T)mUB;
  WorkingSet.sizesRegPhaseOne[0] = mFixed;
  WorkingSet.sizesRegPhaseOne[1] = 0;
  WorkingSet.sizesRegPhaseOne[2] = 1;
  WorkingSet.sizesRegPhaseOne[3] = mLB + 2;
  WorkingSet.sizesRegPhaseOne[4] = mUB;
  WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
  WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  WorkingSet.isActiveIdxRegPhaseOne[3] = 1;
  WorkingSet.isActiveIdxRegPhaseOne[4] = mLB;
  WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    b_i = obj_tmp[i];
    WorkingSet.sizesPhaseOne[i] = b_i;
    WorkingSet.sizesRegularized[i] = b_i;
    WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
        WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  for (i = 0; i < 6; i++) {
    WorkingSet.isActiveIdx[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
    WorkingSet.isActiveIdxNormal[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
  WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  WorkingSet.isActiveIdxRegPhaseOne[3] = 1;
  WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 1;
  WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
        WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  for (i = 0; i < 6; i++) {
    WorkingSet.isActiveIdxPhaseOne[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
    WorkingSet.isActiveIdxRegularized[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
  WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  WorkingSet.isActiveIdxRegPhaseOne[3] = 1;
  WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 2;
  WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
        WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  for (i = 0; i < 5; i++) {
    WorkingSet.Aineq[i] = A[i];
  }
  b_st.site = &eb_emlrtRSI;
  for (idx = 0; idx < mLB; idx++) {
    i = WorkingSet.indexLB[idx];
    if ((i < 1) || (i > 5)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 5, &f_emlrtBCI, &st);
    }
    TrialState.xstarsqp[i - 1] =
        muDoubleScalarMax(TrialState.xstarsqp[i - 1], lb[i - 1]);
  }
  b_st.site = &eb_emlrtRSI;
  for (idx = 0; idx < mUB; idx++) {
    i = WorkingSet.indexUB[idx];
    if ((i < 1) || (i > 5)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 5, &f_emlrtBCI, &st);
    }
    TrialState.xstarsqp[i - 1] =
        muDoubleScalarMin(TrialState.xstarsqp[i - 1], ub[i - 1]);
  }
  b_st.site = &eb_emlrtRSI;
  for (idx = 0; idx < mFixed; idx++) {
    i = WorkingSet.indexFixed[idx];
    if (i < 1) {
      emlrtDynamicBoundsCheckR2012b(0, 1, 5, &f_emlrtBCI, &st);
    }
    TrialState.xstarsqp[i - 1] = ub[i - 1];
  }
  b_st.site = &eb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  TrialState.sqpFval = computeObjective_(
      &c_st,
      &FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace,
      TrialState.xstarsqp, &i);
  if (i == 1) {
    i = 1;
  }
  if (i != 1) {
    emlrtErrorWithMessageIdR2018a(&st, &o_emlrtRTEI,
                                  "optim_codegen:fmincon:UndefAtX0",
                                  "optim_codegen:fmincon:UndefAtX0", 0);
  }
  b_st.site = &eb_emlrtRSI;
  FiniteDifferences.objfun.workspace.points.size[0] = points_size[0];
  FiniteDifferences.objfun.workspace.points.size[1] = 2;
  if (loop_ub_tmp - 1 >= 0) {
    memcpy(&FiniteDifferences.objfun.workspace.points.data[0], &points_data[0],
           (uint32_T)loop_ub_tmp * sizeof(real_T));
  }
  FiniteDifferences.f_1 = 0.0;
  FiniteDifferences.f_2 = 0.0;
  FiniteDifferences.nVar = 5;
  FiniteDifferences.mIneq = 0;
  FiniteDifferences.mEq = 0;
  FiniteDifferences.numEvals = 0;
  FiniteDifferences.SpecifyObjectiveGradient = false;
  FiniteDifferences.SpecifyConstraintGradient = false;
  FiniteDifferences.isEmptyNonlcon = true;
  FiniteDifferences.FiniteDifferenceType = 0;
  for (i = 0; i < 5; i++) {
    varargin_1[i] = FiniteDifferences.hasLB[i];
  }
  y = false;
  idx = 0;
  while ((!y) && (idx + 1 <= 5)) {
    varargin_1[idx] =
        ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
    FiniteDifferences.hasUB[idx] =
        ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
    if (varargin_1[idx] || FiniteDifferences.hasUB[idx]) {
      y = true;
    }
    idx++;
  }
  while (idx + 1 <= 5) {
    varargin_1[idx] =
        ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
    FiniteDifferences.hasUB[idx] =
        ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
    idx++;
  }
  for (i = 0; i < 5; i++) {
    FiniteDifferences.hasLB[i] = varargin_1[i];
  }
  FiniteDifferences.hasBounds = y;
  c_st.site = &gc_emlrtRSI;
  computeForwardDifferences(&c_st, &FiniteDifferences, TrialState.sqpFval,
                            TrialState.xstarsqp, TrialState.grad, lb, ub);
  TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
  b_st.site = &eb_emlrtRSI;
  c = 0.0;
  for (i = 0; i < 5; i++) {
    c += WorkingSet.Aineq[i] * TrialState.xstarsqp[i];
  }
  c += -B;
  TrialState.cIneq = c;
  b_st.site = &eb_emlrtRSI;
  updateWorkingSetForNewQP(&b_st, a0, &WorkingSet, c, mLB, lb, mUB, ub, mFixed);
  b_st.site = &eb_emlrtRSI;
  initActiveSet(&b_st, &WorkingSet);
  MeritFunction.initFval = TrialState.sqpFval;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  MeritFunction.initConstrViolationEq = 0.0;
  MeritFunction.initConstrViolationIneq = 0.0;
  if (c > 0.0) {
    MeritFunction.initConstrViolationIneq = c;
  }
  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpPrimalFeasError = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  MeritFunction.firstOrderOpt = 0.0;
  MeritFunction.hasObjective = true;
  b_st.site = &eb_emlrtRSI;
  b_driver(&b_st, B, lb, ub, &TrialState, &MeritFunction, &FcnEvaluator,
           &FiniteDifferences, &memspace, &WorkingSet, Hessian, &QRManager,
           &CholManager, &QPObjective);
  for (i = 0; i < 5; i++) {
    varargout_1[i] = TrialState.xstarsqp[i];
  }
}

int32_T pcfitellipse_init_anonFcn2(const emlrtStack *sp, const real_T model[5],
                                   const real_T points_data[],
                                   const int32_T points_size[2],
                                   real_T varargout_1_data[])
{
  __m128d r;
  __m128d r1;
  emlrtStack st;
  real_T b_tmp_data[1500];
  real_T c_tmp_data[1500];
  real_T distance_data[1500];
  real_T tmp_data[1500];
  real_T b;
  real_T b_model;
  real_T x_tmp;
  int32_T i;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T scalarLB_tmp;
  int32_T tmp_size;
  int32_T varargout_1_size;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  /*    %サンプリングした点群から計算した楕円と各点群との誤差を計算する式 */
  st.site = &ii_emlrtRSI;
  /* 外れ値でない点群を保存     */
  /* サンプリングした点群から計算した楕円と各点群との誤差を計算 */
  /* 点群のx座標を代入 */
  /* 点群のy座標を代入 */
  /* 以下で誤差を計算.
   * pにはRANSACで計算されたx,y,alpha,beta,thetaがベクトルで入っている。 */
  b_model = model[0];
  varargout_1_size = points_size[0];
  loop_ub = points_size[0];
  scalarLB_tmp = (points_size[0] / 2) << 1;
  vectorUB = scalarLB_tmp - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    _mm_storeu_pd(&distance_data[i], _mm_sub_pd(_mm_loadu_pd(&points_data[i]),
                                                _mm_set1_pd(b_model)));
  }
  for (i = scalarLB_tmp; i < loop_ub; i++) {
    distance_data[i] = points_data[i] - b_model;
  }
  x_tmp = muDoubleScalarSin(model[4]);
  loop_ub = points_size[0];
  b = muDoubleScalarCos(model[4]);
  b_model = model[1];
  tmp_size = points_size[0];
  vectorUB_tmp = scalarLB_tmp - 2;
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    r = _mm_loadu_pd(&distance_data[i]);
    _mm_storeu_pd(&tmp_data[i], _mm_mul_pd(r, _mm_set1_pd(-x_tmp)));
    _mm_storeu_pd(&b_tmp_data[i],
                  _mm_sub_pd(_mm_loadu_pd(&points_data[i + points_size[0]]),
                             _mm_set1_pd(b_model)));
  }
  for (i = scalarLB_tmp; i < varargout_1_size; i++) {
    tmp_data[i] = distance_data[i] * -x_tmp;
    b_tmp_data[i] = points_data[i + points_size[0]] - b_model;
  }
  scalarLB = (points_size[0] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&b_tmp_data[i]);
    _mm_storeu_pd(&c_tmp_data[i], _mm_mul_pd(r, _mm_set1_pd(b)));
  }
  for (i = scalarLB; i < tmp_size; i++) {
    c_tmp_data[i] = b_tmp_data[i] * b;
  }
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    r = _mm_loadu_pd(&distance_data[i]);
    _mm_storeu_pd(&distance_data[i],
                  _mm_mul_pd(_mm_mul_pd(r, _mm_set1_pd(-1.0)), _mm_set1_pd(b)));
    r = _mm_loadu_pd(&b_tmp_data[i]);
    _mm_storeu_pd(&b_tmp_data[i], _mm_mul_pd(r, _mm_set1_pd(-x_tmp)));
  }
  for (i = scalarLB_tmp; i < varargout_1_size; i++) {
    distance_data[i] = -distance_data[i] * b;
    b_tmp_data[i] *= -x_tmp;
  }
  scalarLB = varargout_1_size / 2 * 2;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&tmp_data[i]);
    r1 = _mm_loadu_pd(&c_tmp_data[i]);
    r = _mm_add_pd(r, r1);
    r = _mm_div_pd(r, _mm_set1_pd(model[2]));
    r = _mm_mul_pd(r, r);
    _mm_storeu_pd(&tmp_data[i], r);
  }
  for (i = scalarLB; i < varargout_1_size; i++) {
    b_model = (tmp_data[i] + c_tmp_data[i]) / model[2];
    tmp_data[i] = b_model * b_model;
  }
  tmp_size = points_size[0];
  scalarLB = varargout_1_size / 2 * 2;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&distance_data[i]);
    r1 = _mm_loadu_pd(&b_tmp_data[i]);
    r = _mm_add_pd(r, r1);
    r = _mm_div_pd(r, _mm_set1_pd(model[3]));
    r = _mm_mul_pd(r, r);
    _mm_storeu_pd(&b_tmp_data[i], r);
  }
  for (i = scalarLB; i < varargout_1_size; i++) {
    b_model = (distance_data[i] + b_tmp_data[i]) / model[3];
    b_tmp_data[i] = b_model * b_model;
  }
  if ((loop_ub != tmp_size) && ((loop_ub != 1) && (tmp_size != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, tmp_size, &d_emlrtECI, &st);
  }
  if (loop_ub == tmp_size) {
    varargout_1_size = loop_ub;
    scalarLB = loop_ub / 2 * 2;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&tmp_data[i]);
      r1 = _mm_loadu_pd(&b_tmp_data[i]);
      r = _mm_add_pd(r, r1);
      r = _mm_sub_pd(r, _mm_set1_pd(1.0));
      r = _mm_mul_pd(r, r);
      _mm_storeu_pd(&distance_data[i], r);
    }
    for (i = scalarLB; i < loop_ub; i++) {
      b_model = (tmp_data[i] + b_tmp_data[i]) - 1.0;
      distance_data[i] = b_model * b_model;
    }
  } else {
    varargout_1_size = binary_expand_op(distance_data, tmp_data, &loop_ub,
                                        b_tmp_data, &tmp_size);
  }
  if (varargout_1_size == 0) {
    varargout_1_size = 0;
  } else {
    memcpy(&varargout_1_data[0], &distance_data[0],
           (uint32_T)varargout_1_size * sizeof(real_T));
  }
  return varargout_1_size;
}

/* End of code generation (pcfitellipse_init.c) */
