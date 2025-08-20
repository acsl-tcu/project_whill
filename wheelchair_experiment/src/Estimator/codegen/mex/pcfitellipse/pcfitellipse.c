/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse.c
 *
 * Code generation for function 'pcfitellipse'
 *
 */

/* Include files */
#include "pcfitellipse.h"
#include "checkLinearInputs.h"
#include "computeConstraints_.h"
#include "computeForwardDifferences.h"
#include "computeObjective_.h"
#include "driver1.h"
#include "initActiveSet.h"
#include "mean.h"
#include "mrdivide_helper.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "pcfitellipse_types.h"
#include "ransac.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "unsafeSxfun.h"
#include "updateWorkingSetForNewQP.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    20,             /* lineNo */
    "pcfitellipse", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                    */
};

static emlrtRSInfo b_emlrtRSI = {
    35,             /* lineNo */
    "pcfitellipse", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                    */
};

static emlrtRSInfo c_emlrtRSI = {
    38,             /* lineNo */
    "pcfitellipse", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                    */
};

static emlrtRSInfo d_emlrtRSI = {
    59,             /* lineNo */
    "pcfitellipse", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                    */
};

static emlrtRSInfo vb_emlrtRSI = {
    24, /* lineNo */
    "@(points)fmincon(@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a("
    "2))*cos(a(5)))/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))"
    "+(points(:,2)-a(2))*-sin(a(5)))/"
    "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),1),a0,"
    "A,B,Aeq,Beq,lb,ub,nonl"
    "con,options)", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                    */
};

static emlrtRSInfo wb_emlrtRSI = {
    1,         /* lineNo */
    "fmincon", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\optim\\eml\\fmincon.p" /* pathName
                                                                         */
};

static emlrtRSInfo ac_emlrtRSI = {
    1,                                /* lineNo */
    "evalObjAndConstrAndDerivatives", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+utils\\+"
    "ObjNonlinEvaluator\\evalObjAndConstrAndDerivatives.p" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI =
    {
        24, /* lineNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fcnName */
        "C:\\Users\\masan\\OneDrive - "
        "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad"
        "\xa6 Tokyo City University (1)\\"
        "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                        */
};

static emlrtRSInfo dc_emlrtRSI =
    {
        25, /* lineNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fcnName */
        "C:\\Users\\masan\\OneDrive - "
        "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad"
        "\xa6 Tokyo City University (1)\\"
        "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                        */
};

static emlrtRSInfo ec_emlrtRSI =
    {
        26, /* lineNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fcnName */
        "C:\\Users\\masan\\OneDrive - "
        "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad"
        "\xa6 Tokyo City University (1)\\"
        "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                        */
};

static emlrtRSInfo gc_emlrtRSI = {
    14,      /* lineNo */
    "hypot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\hypot.m" /* pathName
                                                                        */
};

static emlrtRSInfo hc_emlrtRSI = {
    66,      /* lineNo */
    "ixfun", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" /* pathName
                                                                            */
};

static emlrtRSInfo ic_emlrtRSI = {
    45,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    19,             /* lineNo */
    "scalexpAlloc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc."
    "m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI =
    {
        10,    /* lineNo */
        "exp", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" /* pathName
                                                                          */
};

static emlrtRSInfo lc_emlrtRSI = {
    33,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" /* pathName */
};

static emlrtRSInfo ij_emlrtRSI = {
    29,                                                    /* lineNo */
    "@(model,points)sum(distanceEllipse(model,points),2)", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pathName
                                                                    */
};

static emlrtBCInfo emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    43,             /* lineNo */
    25,             /* colNo */
    "modelRANSAC",  /* aName */
    "pcfitellipse", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    43,             /* lineNo */
    40,             /* colNo */
    "modelRANSAC",  /* aName */
    "pcfitellipse", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    54,             /* lineNo */
    52,             /* colNo */
    "modelRANSAC",  /* aName */
    "pcfitellipse", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    38,             /* lineNo */
    22,             /* colNo */
    "points",       /* aName */
    "pcfitellipse", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    38,             /* lineNo */
    43,             /* colNo */
    "points",       /* aName */
    "pcfitellipse", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                /* iFirst */
    8,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compressBounds", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\compressBounds.p", /* pName */
    3                               /* checkKind */
};

static emlrtRTEInfo p_emlrtRTEI = {
    1,         /* lineNo */
    1,         /* colNo */
    "checkX0", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\optimlib\\+optim\\+coder\\+"
    "validate\\checkX0.p" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    1,         /* lineNo */
    1,         /* colNo */
    "fmincon", /* fName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\optim\\eml\\fmincon.p" /* pName
                                                                         */
};

static emlrtBCInfo i_emlrtBCI = {
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

static emlrtECInfo emlrtECI =
    {
        1,  /* nDims */
        24, /* lineNo */
        48, /* colNo */
        "@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))"
        "/a(3)).^2+((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2"
        "))*-sin(a(5)))/"
        "a(4)).^2-1).^2+exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),"
        "1)", /* fName */
        "C:\\Users\\masan\\OneDrive - "
        "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad"
        "\xa6 Tokyo City University (1)\\"
        "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pName
                                                                        */
};

static emlrtECInfo b_emlrtECI = {
    1,                              /* nDims */
    71,                             /* lineNo */
    21,                             /* colNo */
    "pcfitellipse/distanceEllipse", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m" /* pName */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    75,                              /* lineNo */
    23,                              /* colNo */
    "model",                         /* aName */
    "pcfitellipse/validateModelFcn", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    75,                              /* lineNo */
    32,                              /* colNo */
    "model",                         /* aName */
    "pcfitellipse/validateModelFcn", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    75,                              /* lineNo */
    41,                              /* colNo */
    "model",                         /* aName */
    "pcfitellipse/validateModelFcn", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University (1)\\"
    "graduation\\IMMEst_okugai_v4\\src\\Estimator\\pcfitellipse.m", /* pName */
    0 /* checkKind */
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

void pcfitellipse(pcfitellipseStackData *SD, const emlrtStack *sp,
                  const real_T points_data[], const int32_T points_size[2],
                  const real_T a0[5], real_T sampleSize, real_T maxDistance,
                  const real_T A[5], real_T B, const real_T lb[5],
                  const real_T ub[5], real_T Num, real_T CNum,
                  const real_T Pbar[36], const real_T c[30], const real_T R[25],
                  real_T MD_threshold, real_T MSANum, const real_T Xhbar[6],
                  real_T eta, real_T Y[5], real_T inlier_data[],
                  int32_T inlier_size[2], real_T *SBreakFlag, real_T *MD,
                  real_T S_final[25])
{
  e_struct_T expl_temp;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_points_data[1500];
  real_T c_points_data[1500];
  real_T b_c[30];
  real_T b_modelRANSAC_data[25];
  real_T c_modelRANSAC_data[25];
  real_T modelRANSAC_data[5];
  real_T c_fitEllipseFcn_workspace_nonlc[2];
  real_T axis_threshold;
  real_T maxRatio;
  real_T minRatio;
  real_T ratio;
  int32_T modelRANSAC_size[2];
  int32_T b_i;
  int32_T i;
  int32_T inlierIdx_size;
  int32_T loop_ub;
  int32_T partialTrueCount;
  int16_T tmp_data[1500];
  int16_T i1;
  boolean_T inlierIdx_data[1500];
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T judgeOverRatio;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  /*  points      = zeros(size(x,1),2); %点群を保存する配列の初期化 */
  /*  points(:,1) = double(x); %点群のx座標をdouble型へ */
  /*  points(:,2) = double(y); %点群のy座標をdouble型へ */
  /*  % 関心領域の設定,楕円にしたい */
  /*  if cnt >= 0 % selectedCount */
  /*      xpoints = x(hypot(x-Xhbar(1,1),y-Xhbar(2,1)) < selectedArea); */
  /*      points = zeros(length(xpoints),2); */
  /*      points(:,1) = xpoints; */
  /*      points(:,2) = y(hypot(x-Xhbar(1,1),y-Xhbar(2,1)) < selectedArea); */
  /*      points = double(points); */
  /*  else */
  /*      points      = zeros(size(x,1),2); %点群を保存する配列の初期化 */
  /*      points(:,1) = double(x); %点群のx座標をdouble型へ */
  /*      points(:,2) = double(y); %点群のy座標をdouble型へ */
  /*  end */
  loop_ub = points_size[0];
  if (loop_ub - 1 >= 0) {
    memcpy(&b_points_data[0], &points_data[0],
           (uint32_T)loop_ub * sizeof(real_T));
  }
  for (i = 0; i < loop_ub; i++) {
    c_points_data[i] = points_data[i + points_size[0]];
  }
  emlrtStack *r;
  emlrtStack *r1;
  st.site = &emlrtRSI;
  r = &st;
  minRatio = mean(r, b_points_data, points_size[0]);
  b_st.site = &emlrtRSI;
  r1 = &b_st;
  maxRatio = mean(r1, c_points_data, points_size[0]);
  c_fitEllipseFcn_workspace_nonlc[0] = minRatio;
  c_fitEllipseFcn_workspace_nonlc[1] = maxRatio;
  /*  歩行者クラスタの重心 */
  /* ソルバーの設定。このままでOK */
  /* RANSACでモデルの候補生成のための計算式。サンプリングした点群のみ使ってfminconを解く。
   */
  for (i = 0; i < 5; i++) {
    minRatio = 0.0;
    for (b_i = 0; b_i < 6; b_i++) {
      minRatio += c[i + 5 * b_i] * Xhbar[b_i];
    }
    expl_temp.Yhbar[i] = minRatio;
  }
  /* 1st RANSAC */
  /* modelRANSAC:x,y,alpha,beta,theta(楕円中心,長軸,短軸,方向角),inlierIdx:各点群がInlierかどうか1,0で表示
   */
  expl_temp.MD_threshold = MD_threshold;
  memcpy(&expl_temp.R[0], &R[0], 25U * sizeof(real_T));
  memcpy(&expl_temp.c[0], &c[0], 30U * sizeof(real_T));
  memcpy(&expl_temp.Pbar[0], &Pbar[0], 36U * sizeof(real_T));
  c_st.site = &b_emlrtRSI;
  inlierIdx_size = ransac(SD, &c_st, points_data, points_size, a0, A, B, lb, ub,
                          c_fitEllipseFcn_workspace_nonlc, sampleSize,
                          maxDistance, MSANum, Num, CNum, &expl_temp,
                          modelRANSAC_data, modelRANSAC_size, inlierIdx_data);
  inlierIdx_size--;
  loop_ub = 0;
  partialTrueCount = 0;
  for (b_i = 0; b_i <= inlierIdx_size; b_i++) {
    if (inlierIdx_data[b_i]) {
      loop_ub++;
      tmp_data[partialTrueCount] = (int16_T)b_i;
      partialTrueCount++;
    }
  }
  c_st.site = &c_emlrtRSI;
  for (i = 0; i < loop_ub; i++) {
    i1 = tmp_data[i];
    if (i1 > points_size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, points_size[0] - 1, &d_emlrtBCI,
                                    &c_st);
    }
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = tmp_data[i];
    if (i1 > points_size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, points_size[0] - 1, &e_emlrtBCI,
                                    &c_st);
    }
  }
  inlier_size[0] = loop_ub;
  inlier_size[1] = 2;
  for (i = 0; i < loop_ub; i++) {
    i1 = tmp_data[i];
    inlier_data[i] = points_data[i1];
    inlier_data[i + loop_ub] = points_data[i1 + points_size[0]];
  }
  /* 外れ値でない点群を保存 */
  maxRatio = ub[2] / lb[3];
  /*  alpha/betaの最大比率 */
  minRatio = lb[2] / ub[3];
  /*  alpha/betaの最小比率 */
  /*  eta = 0.1; */
  axis_threshold = (maxRatio - minRatio) * eta;
  /*  共分散行列崩れ判定の閾値 */
  loop_ub = modelRANSAC_size[0] * modelRANSAC_size[1];
  if (loop_ub < 3) {
    emlrtDynamicBoundsCheckR2012b(3, 1, loop_ub, &emlrtBCI, &b_st);
  }
  if (loop_ub < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, 3, &b_emlrtBCI, &b_st);
  }
  ratio = modelRANSAC_data[2] / modelRANSAC_data[3];
  x[0] = (ratio < minRatio + axis_threshold);
  x[1] = (ratio > maxRatio - axis_threshold);
  judgeOverRatio = false;
  inlierIdx_size = 0;
  exitg1 = false;
  while ((!exitg1) && (inlierIdx_size < 2)) {
    if (x[inlierIdx_size]) {
      judgeOverRatio = true;
      exitg1 = true;
    } else {
      inlierIdx_size++;
    }
  }
  if (judgeOverRatio) {
    /*  事後誤差共分散行列を比率調整するための判定,0:異常なし，1:イノベーション共分散の崩れ発生
     */
    *SBreakFlag = 1.0;
  } else {
    *SBreakFlag = 0.0;
  }
  /*  */
  inlierIdx_size = modelRANSAC_size[0];
  for (i = 0; i < inlierIdx_size; i++) {
    partialTrueCount = modelRANSAC_size[1];
    for (b_i = 0; b_i < partialTrueCount; b_i++) {
      b_modelRANSAC_data[b_i] = modelRANSAC_data[modelRANSAC_size[0] * b_i];
    }
  }
  memcpy(&c_modelRANSAC_data[0], &b_modelRANSAC_data[0],
         (uint32_T)loop_ub * sizeof(real_T));
  if (loop_ub < 5) {
    emlrtDynamicBoundsCheckR2012b(5, 1, 4, &c_emlrtBCI, &b_st);
  }
  Y[0] = c_modelRANSAC_data[0];
  Y[1] = c_modelRANSAC_data[1];
  Y[2] = c_modelRANSAC_data[4];
  Y[3] = c_modelRANSAC_data[2];
  Y[4] = c_modelRANSAC_data[3];
  /*  [x,y,theta,alpha,beta] */
  /*  obj.ellipse.Xhbar(3) = wrapTo2Pi(obj.ellipse.Xhbar(3)); */
  /*  obj.ellipse.model(3) =
   * wrapAngle(obj.ellipse.Xhbar(3),obj.ellipse.model(3)); */
  for (i = 0; i < 5; i++) {
    for (b_i = 0; b_i < 6; b_i++) {
      minRatio = 0.0;
      for (inlierIdx_size = 0; inlierIdx_size < 6; inlierIdx_size++) {
        minRatio += c[i + 5 * inlierIdx_size] * Pbar[inlierIdx_size + 6 * b_i];
      }
      b_c[i + 5 * b_i] = minRatio;
    }
    for (b_i = 0; b_i < 5; b_i++) {
      minRatio = 0.0;
      for (inlierIdx_size = 0; inlierIdx_size < 6; inlierIdx_size++) {
        minRatio += b_c[i + 5 * inlierIdx_size] * c[b_i + 5 * inlierIdx_size];
      }
      inlierIdx_size = i + 5 * b_i;
      S_final[inlierIdx_size] = minRatio + R[inlierIdx_size];
    }
    expl_temp.Yhbar[i] = Y[i] - expl_temp.Yhbar[i];
  }
  c_st.site = &d_emlrtRSI;
  for (i = 0; i < 5; i++) {
    modelRANSAC_data[i] = expl_temp.Yhbar[i];
  }
  d_st.site = &qi_emlrtRSI;
  mrdiv(&d_st, modelRANSAC_data, S_final);
  maxRatio = 0.0;
  for (i = 0; i < 5; i++) {
    maxRatio += modelRANSAC_data[i] * expl_temp.Yhbar[i];
  }
  c_st.site = &d_emlrtRSI;
  if (maxRatio < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *MD = muDoubleScalarSqrt(maxRatio);
}

void pcfitellipse_anonFcn2(pcfitellipseStackData *SD, const emlrtStack *sp,
                           const real_T a0[5], const real_T A[5], real_T B,
                           const real_T lb[5], const real_T ub[5],
                           const real_T nonlcon_workspace_COG_init[2],
                           const real_T points_data[],
                           const int32_T points_size[2], real_T varargout_1[5])
{
  b_struct_T QPObjective;
  c_struct_T MeritFunction;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  f_struct_T memspace;
  g_struct_T QRManager;
  h_struct_T CholManager;
  i_coder_internal_stickyStruct FcnEvaluator;
  j_struct_T TrialState;
  k_struct_T WorkingSet;
  real_T Hessian[25];
  real_T c;
  real_T normResid;
  int32_T i;
  int32_T idx;
  int32_T loop_ub_tmp;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  int8_T obj_tmp[5];
  boolean_T varargin_1[5];
  boolean_T exitg1;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &wb_emlrtRSI;
  for (i = 0; i < 5; i++) {
    normResid = a0[i];
    varargin_1[i] = ((!muDoubleScalarIsInf(normResid)) &&
                     (!muDoubleScalarIsNaN(normResid)));
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
        &b_st, &p_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
        "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 2, "x0");
  }
  b_st.site = &wb_emlrtRSI;
  checkLinearInputs(&b_st, A, B, lb, ub);
  TrialState.nVarMax = 8;
  TrialState.mNonlinIneq = 1;
  TrialState.mNonlinEq = 0;
  TrialState.mIneq = 2;
  TrialState.mEq = 0;
  TrialState.iNonIneq0 = 2;
  TrialState.iNonEq0 = 1;
  TrialState.sqpFval_old = 0.0;
  TrialState.sqpIterations = 0;
  TrialState.sqpExitFlag = 0;
  memset(&TrialState.lambdasqp[0], 0, 15U * sizeof(real_T));
  TrialState.steplength = 1.0;
  memset(&TrialState.delta_x[0], 0, 8U * sizeof(real_T));
  TrialState.fstar = 0.0;
  TrialState.firstorderopt = 0.0;
  memset(&TrialState.lambda[0], 0, 15U * sizeof(real_T));
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
  FcnEvaluator.next.next.next.next.next.next.next.value.workspace.COG_init[0] =
      nonlcon_workspace_COG_init[0];
  FcnEvaluator.next.next.next.next.next.next.next.value.workspace.COG_init[1] =
      nonlcon_workspace_COG_init[1];
  WorkingSet.nVar = 5;
  WorkingSet.nVarOrig = 5;
  WorkingSet.nVarMax = 8;
  WorkingSet.ldA = 8;
  memset(&WorkingSet.Aineq[0], 0, 16U * sizeof(real_T));
  WorkingSet.bineq[0] = 0.0;
  WorkingSet.bineq[1] = 0.0;
  memset(&WorkingSet.lb[0], 0, 8U * sizeof(real_T));
  memset(&WorkingSet.ub[0], 0, 8U * sizeof(real_T));
  WorkingSet.mEqRemoved = 0;
  memset(&WorkingSet.ATwset[0], 0, 120U * sizeof(real_T));
  WorkingSet.nActiveConstr = 0;
  memset(&WorkingSet.bwset[0], 0, 15U * sizeof(real_T));
  memset(&WorkingSet.maxConstrWorkspace[0], 0, 15U * sizeof(real_T));
  for (i = 0; i < 15; i++) {
    WorkingSet.isActiveConstr[i] = false;
    WorkingSet.Wid[i] = 0;
    WorkingSet.Wlocalidx[i] = 0;
  }
  for (i = 0; i < 5; i++) {
    WorkingSet.nWConstr[i] = 0;
  }
  WorkingSet.probType = 3;
  WorkingSet.SLACK0 = 1.0E-5;
  b_st.site = &wb_emlrtRSI;
  for (i = 0; i < 8; i++) {
    WorkingSet.indexLB[i] = 0;
    WorkingSet.indexUB[i] = 0;
    WorkingSet.indexFixed[i] = 0;
  }
  mLB = 0;
  mUB = 0;
  mFixed = 0;
  for (idx = 0; idx < 5; idx++) {
    boolean_T guard1;
    normResid = lb[idx];
    guard1 = false;
    if ((!muDoubleScalarIsInf(normResid)) &&
        (!muDoubleScalarIsNaN(normResid))) {
      if (muDoubleScalarAbs(normResid - ub[idx]) < 1.0E-6) {
        mFixed++;
        if (mFixed > 8) {
          emlrtDynamicBoundsCheckR2012b(9, 1, 8, &h_emlrtBCI, &b_st);
        }
        WorkingSet.indexFixed[mFixed - 1] = idx + 1;
      } else {
        mLB++;
        if (mLB > 8) {
          emlrtDynamicBoundsCheckR2012b(9, 1, 8, &h_emlrtBCI, &b_st);
        }
        WorkingSet.indexLB[mLB - 1] = idx + 1;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      normResid = ub[idx];
      if ((!muDoubleScalarIsInf(normResid)) &&
          (!muDoubleScalarIsNaN(normResid))) {
        mUB++;
        if (mUB > 8) {
          emlrtDynamicBoundsCheckR2012b(9, 1, 8, &h_emlrtBCI, &b_st);
        }
        WorkingSet.indexUB[mUB - 1] = idx + 1;
      }
    }
  }
  b_st.site = &wb_emlrtRSI;
  i = ((mLB + mUB) + mFixed) + 2;
  WorkingSet.mConstr = i;
  WorkingSet.mConstrOrig = i;
  WorkingSet.mConstrMax = 15;
  obj_tmp[0] = (int8_T)mFixed;
  obj_tmp[1] = 0;
  obj_tmp[2] = 2;
  obj_tmp[3] = (int8_T)mLB;
  obj_tmp[4] = (int8_T)mUB;
  WorkingSet.sizesPhaseOne[0] = mFixed;
  WorkingSet.sizesPhaseOne[1] = 0;
  WorkingSet.sizesPhaseOne[2] = 2;
  WorkingSet.sizesPhaseOne[3] = mLB + 1;
  WorkingSet.sizesPhaseOne[4] = mUB;
  WorkingSet.sizesRegularized[0] = mFixed;
  WorkingSet.sizesRegularized[1] = 0;
  WorkingSet.sizesRegularized[2] = 2;
  WorkingSet.sizesRegularized[3] = mLB + 2;
  WorkingSet.sizesRegularized[4] = mUB;
  WorkingSet.sizesRegPhaseOne[0] = mFixed;
  WorkingSet.sizesRegPhaseOne[1] = 0;
  WorkingSet.sizesRegPhaseOne[2] = 2;
  WorkingSet.sizesRegPhaseOne[3] = mLB + 3;
  WorkingSet.sizesRegPhaseOne[4] = mUB;
  WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
  WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  WorkingSet.isActiveIdxRegPhaseOne[3] = 2;
  WorkingSet.isActiveIdxRegPhaseOne[4] = mLB;
  WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    int8_T b_i;
    b_i = obj_tmp[i];
    WorkingSet.sizes[i] = b_i;
    WorkingSet.sizesNormal[i] = b_i;
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
  WorkingSet.isActiveIdxRegPhaseOne[3] = 2;
  WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 1;
  WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
        WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  for (i = 0; i < 6; i++) {
    WorkingSet.isActiveIdxPhaseOne[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
  WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  WorkingSet.isActiveIdxRegPhaseOne[3] = 2;
  WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 2;
  WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
        WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  for (i = 0; i < 6; i++) {
    WorkingSet.isActiveIdxRegularized[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
  WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  WorkingSet.isActiveIdxRegPhaseOne[3] = 2;
  WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 3;
  WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
        WorkingSet.isActiveIdxRegPhaseOne[i];
  }
  for (i = 0; i < 5; i++) {
    WorkingSet.Aineq[i] = A[i];
  }
  b_st.site = &wb_emlrtRSI;
  for (idx = 0; idx < mLB; idx++) {
    i = WorkingSet.indexLB[idx];
    if ((i < 1) || (i > 5)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 5, &i_emlrtBCI, &st);
    }
    TrialState.xstarsqp[i - 1] =
        muDoubleScalarMax(TrialState.xstarsqp[i - 1], lb[i - 1]);
  }
  b_st.site = &wb_emlrtRSI;
  for (idx = 0; idx < mUB; idx++) {
    i = WorkingSet.indexUB[idx];
    if ((i < 1) || (i > 5)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 5, &i_emlrtBCI, &st);
    }
    TrialState.xstarsqp[i - 1] =
        muDoubleScalarMin(TrialState.xstarsqp[i - 1], ub[i - 1]);
  }
  b_st.site = &wb_emlrtRSI;
  for (idx = 0; idx < mFixed; idx++) {
    i = WorkingSet.indexFixed[idx];
    if (i < 1) {
      emlrtDynamicBoundsCheckR2012b(0, 1, 5, &i_emlrtBCI, &st);
    }
    TrialState.xstarsqp[i - 1] = ub[i - 1];
  }
  b_st.site = &wb_emlrtRSI;
  c_st.site = &ac_emlrtRSI;
  normResid = computeObjective_(
      &c_st,
      &FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace,
      TrialState.xstarsqp, &i);
  if (i == 1) {
    i = computeConstraints_(FcnEvaluator.next.next.next.next.next.next.next
                                .value.workspace.COG_init,
                            TrialState.xstarsqp, TrialState.cIneq);
  }
  TrialState.sqpFval = normResid;
  if (i != 1) {
    emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                  "optim_codegen:fmincon:UndefAtX0",
                                  "optim_codegen:fmincon:UndefAtX0", 0);
  }
  b_st.site = &wb_emlrtRSI;
  SD->f0.FiniteDifferences.objfun.workspace.points.size[0] = points_size[0];
  SD->f0.FiniteDifferences.objfun.workspace.points.size[1] = 2;
  if (loop_ub_tmp - 1 >= 0) {
    memcpy(&SD->f0.FiniteDifferences.objfun.workspace.points.data[0],
           &points_data[0], (uint32_T)loop_ub_tmp * sizeof(real_T));
  }
  SD->f0.FiniteDifferences.nonlin.workspace.COG_init[0] =
      nonlcon_workspace_COG_init[0];
  SD->f0.FiniteDifferences.nonlin.workspace.COG_init[1] =
      nonlcon_workspace_COG_init[1];
  SD->f0.FiniteDifferences.f_1 = 0.0;
  SD->f0.FiniteDifferences.f_2 = 0.0;
  SD->f0.FiniteDifferences.nVar = 5;
  SD->f0.FiniteDifferences.mIneq = 1;
  SD->f0.FiniteDifferences.mEq = 0;
  SD->f0.FiniteDifferences.numEvals = 0;
  SD->f0.FiniteDifferences.SpecifyObjectiveGradient = false;
  SD->f0.FiniteDifferences.SpecifyConstraintGradient = false;
  SD->f0.FiniteDifferences.isEmptyNonlcon = false;
  SD->f0.FiniteDifferences.FiniteDifferenceType = 0;
  for (i = 0; i < 5; i++) {
    varargin_1[i] = SD->f0.FiniteDifferences.hasLB[i];
  }
  y = false;
  idx = 0;
  while ((!y) && (idx + 1 <= 5)) {
    varargin_1[idx] =
        ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
    SD->f0.FiniteDifferences.hasUB[idx] =
        ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
    if (varargin_1[idx] || SD->f0.FiniteDifferences.hasUB[idx]) {
      y = true;
    }
    idx++;
  }
  while (idx + 1 <= 5) {
    varargin_1[idx] =
        ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
    SD->f0.FiniteDifferences.hasUB[idx] =
        ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
    idx++;
  }
  for (i = 0; i < 5; i++) {
    SD->f0.FiniteDifferences.hasLB[i] = varargin_1[i];
  }
  SD->f0.FiniteDifferences.hasBounds = y;
  c_st.site = &oc_emlrtRSI;
  computeForwardDifferences(&c_st, &SD->f0.FiniteDifferences, normResid,
                            TrialState.cIneq, TrialState.xstarsqp,
                            TrialState.grad, WorkingSet.Aineq, lb, ub);
  TrialState.FunctionEvaluations = SD->f0.FiniteDifferences.numEvals + 1;
  b_st.site = &wb_emlrtRSI;
  c = 0.0;
  for (i = 0; i < 5; i++) {
    c += WorkingSet.Aineq[i] * TrialState.xstarsqp[i];
  }
  TrialState.cIneq[0] = -B + c;
  b_st.site = &wb_emlrtRSI;
  updateWorkingSetForNewQP(&b_st, a0, &WorkingSet, TrialState.cIneq, mLB, lb,
                           mUB, ub, mFixed);
  b_st.site = &wb_emlrtRSI;
  initActiveSet(&b_st, &WorkingSet);
  MeritFunction.initFval = normResid;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  MeritFunction.initConstrViolationEq = 0.0;
  normResid = 0.0;
  if (TrialState.cIneq[0] > 0.0) {
    normResid = TrialState.cIneq[0];
  }
  if (TrialState.cIneq[1] > 0.0) {
    normResid += TrialState.cIneq[1];
  }
  MeritFunction.initConstrViolationIneq = normResid;
  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpPrimalFeasError = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  MeritFunction.firstOrderOpt = 0.0;
  MeritFunction.hasObjective = true;
  b_st.site = &wb_emlrtRSI;
  b_driver(&b_st, B, lb, ub, &TrialState, &MeritFunction, &FcnEvaluator,
           &SD->f0.FiniteDifferences, &memspace, &WorkingSet, Hessian,
           &QRManager, &CholManager, &QPObjective);
  for (i = 0; i < 5; i++) {
    varargout_1[i] = TrialState.xstarsqp[i];
  }
}

real_T pcfitellipse_anonFcn2_anonFcn1(const emlrtStack *sp,
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
  st.site = &cc_emlrtRSI;
  b_st.site = &fc_emlrtRSI;
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
  st.site = &dc_emlrtRSI;
  b_st.site = &fc_emlrtRSI;
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
  st.site = &cc_emlrtRSI;
  b_st.site = &fc_emlrtRSI;
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
  st.site = &ec_emlrtRSI;
  b_st.site = &gc_emlrtRSI;
  c_st.site = &hc_emlrtRSI;
  d_st.site = &ic_emlrtRSI;
  e_st.site = &jc_emlrtRSI;
  r_size = points_size[0];
  i = points_size[0];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    r_data[loop_ub] = muDoubleScalarHypot(
        points_data[loop_ub], points_data[loop_ub + points_size[0]]);
  }
  x_tmp = muDoubleScalarHypot(a[0], a[1]);
  st.site = &ec_emlrtRSI;
  for (i = 0; i <= vectorUB_tmp; i += 2) {
    r = _mm_loadu_pd(&r_data[i]);
    _mm_storeu_pd(&r_data[i], _mm_sub_pd(r, _mm_set1_pd(x_tmp)));
  }
  for (i = scalarLB_tmp; i < r_size; i++) {
    r_data[i] -= x_tmp;
  }
  b_st.site = &kc_emlrtRSI;
  c_st.site = &lc_emlrtRSI;
  for (loop_ub = 0; loop_ub < r_size; loop_ub++) {
    r_data[loop_ub] = muDoubleScalarExp(r_data[loop_ub]);
  }
  if ((tmp_size != points_size[0]) &&
      ((tmp_size != 1) && (points_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(tmp_size, points_size[0], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  st.site = &cc_emlrtRSI;
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
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  if (tmp_size == 0) {
    varargout_1 = 0.0;
  } else {
    e_st.site = &g_emlrtRSI;
    f_st.site = &h_emlrtRSI;
    g_st.site = &i_emlrtRSI;
    varargout_1 = sumColumnB(&g_st, x_data, tmp_size);
  }
  return varargout_1;
}

int32_T pcfitellipse_anonFcn3(const emlrtStack *sp, const real_T model[5],
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
  st.site = &ij_emlrtRSI;
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
    emlrtDimSizeImpxCheckR2021b(loop_ub, tmp_size, &b_emlrtECI, &st);
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

boolean_T pcfitellipse_anonFcn4(const emlrtStack *sp, const real_T Pbar[36],
                                const real_T c[30], const real_T R[25],
                                const real_T Yhbar[5], real_T MD_threshold,
                                const real_T model_data[], int32_T model_size)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_c[30];
  real_T c_c[25];
  real_T Y[5];
  real_T Ytilde[5];
  real_T b_Y;
  int32_T c_tmp;
  int32_T i;
  int32_T i1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  /*  weightも入ってた */
  /* イノベーション共分散行列 */
  if (model_size < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, model_size, &k_emlrtBCI, &st);
  }
  if (model_size < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &l_emlrtBCI, &st);
  }
  if (model_size < 5) {
    emlrtDynamicBoundsCheckR2012b(5, 1, model_size, &m_emlrtBCI, &st);
  }
  /*  観測値 */
  Ytilde[0] = model_data[0] - Yhbar[0];
  Ytilde[1] = model_data[1] - Yhbar[1];
  Ytilde[2] = model_data[4] - Yhbar[2];
  Ytilde[3] = model_data[2] - Yhbar[3];
  Ytilde[4] = model_data[3] - Yhbar[4];
  /*  観測予測誤差 */
  b_st.site = &pi_emlrtRSI;
  for (i = 0; i < 5; i++) {
    Y[i] = Ytilde[i];
    for (i1 = 0; i1 < 6; i1++) {
      b_Y = 0.0;
      for (c_tmp = 0; c_tmp < 6; c_tmp++) {
        b_Y += c[i + 5 * c_tmp] * Pbar[c_tmp + 6 * i1];
      }
      b_c[i + 5 * i1] = b_Y;
    }
    for (i1 = 0; i1 < 5; i1++) {
      b_Y = 0.0;
      for (c_tmp = 0; c_tmp < 6; c_tmp++) {
        b_Y += b_c[i + 5 * c_tmp] * c[i1 + 5 * c_tmp];
      }
      c_tmp = i + 5 * i1;
      c_c[c_tmp] = b_Y + R[c_tmp];
    }
  }
  c_st.site = &qi_emlrtRSI;
  mrdiv(&c_st, Y, c_c);
  b_Y = 0.0;
  for (i = 0; i < 5; i++) {
    b_Y += Y[i] * Ytilde[i];
  }
  b_st.site = &pi_emlrtRSI;
  if (b_Y < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  return muDoubleScalarSqrt(b_Y) < MD_threshold;
  /*  MahalDist:(x y theta alpha beta)の順  */
}

/* End of code generation (pcfitellipse.c) */
