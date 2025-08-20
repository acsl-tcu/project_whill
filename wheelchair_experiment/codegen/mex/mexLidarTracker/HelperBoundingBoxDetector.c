/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * HelperBoundingBoxDetector.c
 *
 * Code generation for function 'HelperBoundingBoxDetector'
 *
 */

/* Include files */
#include "HelperBoundingBoxDetector.h"
#include "eml_int_forloop_overflow_check.h"
#include "homogeneous.h"
#include "mean.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "mode.h"
#include "pcsegdist.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo rg_emlrtRSI = {
    101,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo sg_emlrtRSI = {
    106,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo tg_emlrtRSI = {
    109,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo ug_emlrtRSI = {
    112,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    113,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo wg_emlrtRSI = {
    114,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI = {
    115,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo yg_emlrtRSI = {
    116,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo ah_emlrtRSI = {
    117,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo bh_emlrtRSI = {
    124,                /* lineNo */
    "getBoundingBoxes", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pathName */
};

static emlrtRSInfo qj_emlrtRSI = {
    57,     /* lineNo */
    "mode", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/mode.m" /* pathName
                                                                      */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    130,                /* lineNo */
    28,                 /* colNo */
    "isValidCluster",   /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    108,                /* lineNo */
    35,                 /* colNo */
    "pointData",        /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    0       /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    105,                /* lineNo */
    5,                  /* colNo */
    "getBoundingBoxes", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    104,                /* lineNo */
    5,                  /* colNo */
    "getBoundingBoxes", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    105,                /* lineNo */
    30,                 /* colNo */
    "getBoundingBoxes", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    104,                /* lineNo */
    20,                 /* colNo */
    "getBoundingBoxes", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    1       /* checkKind */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    107,                /* lineNo */
    13,                 /* colNo */
    "getBoundingBoxes", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    129,                /* lineNo */
    22,                 /* colNo */
    "bboxes",           /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    133,                /* lineNo */
    23,                 /* colNo */
    "bboxes",           /* aName */
    "getBoundingBoxes", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m", /* pName */
    0       /* checkKind */
};

static emlrtRTEInfo xf_emlrtRTEI = {
    102,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo yf_emlrtRTEI = {
    104,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = {
    105,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = {
    90,                          /* lineNo */
    40,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = {
    133,                         /* lineNo */
    14,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = {
    108,                         /* lineNo */
    25,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = {
    133,                         /* lineNo */
    5,                           /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = {
    108,                         /* lineNo */
    35,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = {
    133,                         /* lineNo */
    23,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

static emlrtRTEInfo kp_emlrtRTEI = {
    271,                         /* lineNo */
    14,                          /* colNo */
    "HelperBoundingBoxDetector", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/HelperBoundingBoxDetect"
    "or.m" /* pName */
};

/* Function Definitions */
void b_and(const emlrtStack *sp, emxArray_boolean_T *in1,
           const emxArray_boolean_T *in2)
{
  emxArray_boolean_T *b_in1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  const boolean_T *in2_data;
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in1, 1, &kp_emlrtRTEI, true);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, b_in1, i, &kp_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = (in1_data[i * stride_0_0] && in2_data[i * stride_1_0]);
  }
  i = in1->size[0];
  in1->size[0] = b_in1->size[0];
  emxEnsureCapacity_boolean_T(sp, in1, i, &kp_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in1->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_boolean_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

real32_T getBoundingBoxes(const emlrtStack *sp, const pointCloud *ptCloud,
                          real_T minDistance, real_T minDetsPerCluster,
                          real_T maxZDistance, real_T minZDistance,
                          real_T Plant_X, real_T Plant_Y, real_T Plant_yaw,
                          real_T SP, emxArray_real_T *bboxes,
                          emxArray_uint32_T *labels)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_boolean_T *isValidCluster;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real32_T *b_pointData;
  emxArray_real32_T *pointData;
  emxArray_real_T *b_bboxes;
  real_T *b_bboxes_data;
  real_T *bboxes_data;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T last;
  int32_T *r2;
  real32_T numClusters;
  real32_T y_global;
  real32_T *b_pointData_data;
  real32_T *pointData_data;
  uint32_T *labels_data;
  boolean_T *isValidCluster_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emlrtMEXProfilingFunctionEntry((char_T *)getBoundingBoxes_complete_name,
                                 isMexOutdated);
  /*  This method fits bounding boxes on each cluster with some basic */
  /*  rules. */
  /*  Cluster must have atleast minDetsPerCluster points. */
  /*  Its mean z must be between maxZDistance and minZDistance. */
  /*  length, width and height are calculated using min and max from each */
  /*  dimension. */
  /*      global writerObj */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  st.site = &rg_emlrtRSI;
  numClusters = pcsegdist(&st, ptCloud, minDistance, labels);
  labels_data = labels->data;
  emlrtMEXProfilingStatement(2, isMexOutdated);
  emxInit_real32_T(sp, &pointData, 2, &xf_emlrtRTEI);
  i = pointData->size[0] * pointData->size[1];
  pointData->size[0] = ptCloud->Location->size[0];
  pointData->size[1] = 3;
  emxEnsureCapacity_real32_T(sp, pointData, i, &xf_emlrtRTEI);
  pointData_data = pointData->data;
  last = ptCloud->Location->size[0] * 3;
  for (i = 0; i < last; i++) {
    pointData_data[i] = ptCloud->Location->data[i];
  }
  /*      bboxes = nan(3,numClusters,'like',pointData); */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  i = (int32_T)muDoubleScalarFloor(numClusters);
  if ((real_T)numClusters != i) {
    emlrtIntegerCheckR2012b(numClusters, &d_emlrtDCI, (emlrtConstCTX)sp);
  }
  idx = bboxes->size[0] * bboxes->size[1];
  bboxes->size[0] = 3;
  b_i = (int32_T)numClusters;
  bboxes->size[1] = (int32_T)numClusters;
  emxEnsureCapacity_real_T(sp, bboxes, idx, &yf_emlrtRTEI);
  bboxes_data = bboxes->data;
  if ((real_T)numClusters != i) {
    emlrtIntegerCheckR2012b(numClusters, &b_emlrtDCI, (emlrtConstCTX)sp);
  }
  last = 3 * (int32_T)numClusters;
  for (idx = 0; idx < last; idx++) {
    bboxes_data[idx] = rtNaN;
  }
  emlrtMEXProfilingStatement(4, isMexOutdated);
  emxInit_boolean_T(sp, &isValidCluster, 2, &ag_emlrtRTEI, true);
  if ((real_T)numClusters != i) {
    emlrtIntegerCheckR2012b(numClusters, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  idx = isValidCluster->size[0] * isValidCluster->size[1];
  isValidCluster->size[0] = 1;
  isValidCluster->size[1] = (int32_T)numClusters;
  emxEnsureCapacity_boolean_T(sp, isValidCluster, idx, &ag_emlrtRTEI);
  isValidCluster_data = isValidCluster->data;
  if ((real_T)numClusters != i) {
    emlrtIntegerCheckR2012b(numClusters, &emlrtDCI, (emlrtConstCTX)sp);
  }
  last = (int32_T)numClusters;
  for (i = 0; i < last; i++) {
    isValidCluster_data[i] = false;
  }
  emlrtMEXProfilingStatement(5, isMexOutdated);
  st.site = &sg_emlrtRSI;
  b_st.site = &qj_emlrtRSI;
  arraymode(&b_st, labels);
  emlrtMEXProfilingStatement(6, isMexOutdated);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, numClusters, mxSINGLE_CLASS,
                                (int32_T)numClusters, &bb_emlrtRTEI,
                                (emlrtConstCTX)sp);
  emxInit_int32_T(sp, &r, 1, &fg_emlrtRTEI);
  emxInit_real32_T(sp, &b_pointData, 2, &dg_emlrtRTEI);
  for (c_i = 0; c_i < b_i; c_i++) {
    real32_T meanPoint[3];
    emlrtMEXProfilingStatement(7, isMexOutdated);
    idx = labels->size[0] - 1;
    last = 0;
    for (i = 0; i <= idx; i++) {
      if (labels_data[i] == (uint32_T)((real32_T)c_i + 1.0F)) {
        last++;
      }
    }
    i = r->size[0];
    r->size[0] = last;
    emxEnsureCapacity_int32_T(sp, r, i, &bg_emlrtRTEI);
    r2 = r->data;
    last = 0;
    for (i = 0; i <= idx; i++) {
      if (labels_data[i] == (uint32_T)((real32_T)c_i + 1.0F)) {
        r2[last] = i;
        last++;
      }
    }
    last = r->size[0];
    for (i = 0; i < last; i++) {
      if (r2[i] > pointData->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(r2[i], 0, pointData->size[0] - 1,
                                      &o_emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    emlrtMEXProfilingStatement(8, isMexOutdated);
    i = b_pointData->size[0] * b_pointData->size[1];
    b_pointData->size[0] = r->size[0];
    b_pointData->size[1] = 3;
    emxEnsureCapacity_real32_T(sp, b_pointData, i, &dg_emlrtRTEI);
    b_pointData_data = b_pointData->data;
    last = r->size[0];
    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < last; idx++) {
        b_pointData_data[idx + b_pointData->size[0] * i] =
            pointData_data[r2[idx] + pointData->size[0] * i];
      }
    }
    st.site = &tg_emlrtRSI;
    mean(&st, b_pointData, meanPoint);
    emlrtMEXProfilingStatement(9, isMexOutdated);
    if ((r->size[0] > minDetsPerCluster) && (meanPoint[2] < maxZDistance) &&
        (meanPoint[2] > minZDistance)) {
      real32_T a;
      real32_T l;
      real32_T xMax;
      real32_T xMin;
      real32_T yMax;
      real32_T yMin;
      boolean_T exitg1;
      /* && i ~= M */
      emlrtMEXProfilingStatement(11, isMexOutdated);
      st.site = &ug_emlrtRSI;
      b_st.site = &vd_emlrtRSI;
      c_st.site = &wd_emlrtRSI;
      d_st.site = &xd_emlrtRSI;
      if (r->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &eb_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      e_st.site = &yd_emlrtRSI;
      f_st.site = &ae_emlrtRSI;
      last = r->size[0];
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          xMin = pointData_data[r2[0]];
        } else {
          xMin = pointData_data[r2[0]];
          a = pointData_data[r2[1]];
          if ((xMin > a) ||
              (muSingleScalarIsNaN(xMin) && (!muSingleScalarIsNaN(a)))) {
            xMin = a;
          }
        }
      } else {
        g_st.site = &og_emlrtRSI;
        xMin = pointData_data[r2[0]];
        if (!muSingleScalarIsNaN(xMin)) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &pg_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= last)) {
            if (!muSingleScalarIsNaN(pointData_data[r2[k - 1]])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (idx != 0) {
          g_st.site = &be_emlrtRSI;
          xMin = pointData_data[r2[idx - 1]];
          i = idx + 1;
          h_st.site = &ce_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = i; k <= last; k++) {
            a = pointData_data[r2[k - 1]];
            if (xMin > a) {
              xMin = a;
            }
          }
        }
      }
      emlrtMEXProfilingStatement(12, isMexOutdated);
      st.site = &vg_emlrtRSI;
      b_st.site = &lf_emlrtRSI;
      c_st.site = &mf_emlrtRSI;
      d_st.site = &nf_emlrtRSI;
      e_st.site = &of_emlrtRSI;
      f_st.site = &pf_emlrtRSI;
      last = r->size[0];
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          xMax = pointData_data[r2[0]];
        } else {
          xMax = pointData_data[r2[0]];
          a = pointData_data[r2[1]];
          if ((xMax < a) ||
              (muSingleScalarIsNaN(xMax) && (!muSingleScalarIsNaN(a)))) {
            xMax = a;
          }
        }
      } else {
        g_st.site = &og_emlrtRSI;
        xMax = pointData_data[r2[0]];
        if (!muSingleScalarIsNaN(xMax)) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &pg_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= last)) {
            if (!muSingleScalarIsNaN(pointData_data[r2[k - 1]])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (idx != 0) {
          g_st.site = &be_emlrtRSI;
          xMax = pointData_data[r2[idx - 1]];
          i = idx + 1;
          h_st.site = &ce_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = i; k <= last; k++) {
            a = pointData_data[r2[k - 1]];
            if (xMax < a) {
              xMax = a;
            }
          }
        }
      }
      emlrtMEXProfilingStatement(13, isMexOutdated);
      st.site = &wg_emlrtRSI;
      b_st.site = &vd_emlrtRSI;
      c_st.site = &wd_emlrtRSI;
      d_st.site = &xd_emlrtRSI;
      e_st.site = &yd_emlrtRSI;
      f_st.site = &ae_emlrtRSI;
      last = r->size[0];
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          yMin = pointData_data[r2[0] + pointData->size[0]];
        } else {
          yMin = pointData_data[r2[0] + pointData->size[0]];
          a = pointData_data[r2[1] + pointData->size[0]];
          if ((yMin > a) ||
              (muSingleScalarIsNaN(yMin) && (!muSingleScalarIsNaN(a)))) {
            yMin = a;
          }
        }
      } else {
        g_st.site = &og_emlrtRSI;
        yMin = pointData_data[r2[0] + pointData->size[0]];
        if (!muSingleScalarIsNaN(yMin)) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &pg_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= last)) {
            if (!muSingleScalarIsNaN(
                    pointData_data[r2[k - 1] + pointData->size[0]])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (idx != 0) {
          g_st.site = &be_emlrtRSI;
          yMin = pointData_data[r2[idx - 1] + pointData->size[0]];
          i = idx + 1;
          h_st.site = &ce_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = i; k <= last; k++) {
            a = pointData_data[r2[k - 1] + pointData->size[0]];
            if (yMin > a) {
              yMin = a;
            }
          }
        }
      }
      emlrtMEXProfilingStatement(14, isMexOutdated);
      st.site = &xg_emlrtRSI;
      b_st.site = &lf_emlrtRSI;
      c_st.site = &mf_emlrtRSI;
      d_st.site = &nf_emlrtRSI;
      e_st.site = &of_emlrtRSI;
      f_st.site = &pf_emlrtRSI;
      last = r->size[0];
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          yMax = pointData_data[r2[0] + pointData->size[0]];
        } else {
          yMax = pointData_data[r2[0] + pointData->size[0]];
          a = pointData_data[r2[1] + pointData->size[0]];
          if ((yMax < a) ||
              (muSingleScalarIsNaN(yMax) && (!muSingleScalarIsNaN(a)))) {
            yMax = a;
          }
        }
      } else {
        g_st.site = &og_emlrtRSI;
        yMax = pointData_data[r2[0] + pointData->size[0]];
        if (!muSingleScalarIsNaN(yMax)) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &pg_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= last)) {
            if (!muSingleScalarIsNaN(
                    pointData_data[r2[k - 1] + pointData->size[0]])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (idx != 0) {
          g_st.site = &be_emlrtRSI;
          yMax = pointData_data[r2[idx - 1] + pointData->size[0]];
          i = idx + 1;
          h_st.site = &ce_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = i; k <= last; k++) {
            a = pointData_data[r2[k - 1] + pointData->size[0]];
            if (yMax < a) {
              yMax = a;
            }
          }
        }
      }
      emlrtMEXProfilingStatement(15, isMexOutdated);
      st.site = &yg_emlrtRSI;
      b_st.site = &vd_emlrtRSI;
      c_st.site = &wd_emlrtRSI;
      d_st.site = &xd_emlrtRSI;
      e_st.site = &yd_emlrtRSI;
      f_st.site = &ae_emlrtRSI;
      if (r->size[0] > 2) {
        g_st.site = &og_emlrtRSI;
        if (!muSingleScalarIsNaN(
                pointData_data[r2[0] + pointData->size[0] * 2])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &pg_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= r->size[0])) {
            if (!muSingleScalarIsNaN(
                    pointData_data[r2[k - 1] + pointData->size[0] * 2])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (idx != 0) {
          g_st.site = &be_emlrtRSI;
          h_st.site = &ce_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
        }
      }
      emlrtMEXProfilingStatement(16, isMexOutdated);
      st.site = &ah_emlrtRSI;
      b_st.site = &lf_emlrtRSI;
      c_st.site = &mf_emlrtRSI;
      d_st.site = &nf_emlrtRSI;
      e_st.site = &of_emlrtRSI;
      f_st.site = &pf_emlrtRSI;
      if (r->size[0] > 2) {
        g_st.site = &og_emlrtRSI;
        if (!muSingleScalarIsNaN(
                pointData_data[r2[0] + pointData->size[0] * 2])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &pg_emlrtRSI;
          if (r->size[0] > 2147483646) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= r->size[0])) {
            if (!muSingleScalarIsNaN(
                    pointData_data[r2[k - 1] + pointData->size[0] * 2])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (idx != 0) {
          g_st.site = &be_emlrtRSI;
          h_st.site = &ce_emlrtRSI;
          if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
            i_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
        }
      }
      emlrtMEXProfilingStatement(17, isMexOutdated);
      l = xMax - xMin;
      emlrtMEXProfilingStatement(18, isMexOutdated);
      a = yMax - yMin;
      emlrtMEXProfilingStatement(20, isMexOutdated);
      emlrtMEXProfilingStatement(21, isMexOutdated);
      emlrtMEXProfilingStatement(23, isMexOutdated);
      st.site = &bh_emlrtRSI;
      b_st.site = &pi_emlrtRSI;
      c_st.site = &qi_emlrtRSI;
      st.site = &bh_emlrtRSI;
      b_st.site = &pi_emlrtRSI;
      c_st.site = &qi_emlrtRSI;
      a = l * l + a * a;
      st.site = &bh_emlrtRSI;
      if (a < 0.0F) {
        emlrtErrorWithMessageIdR2018a(
            &st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      a = muSingleScalarSqrt(a);
      /*              bboxes(:,i) = [x y z l w h]'; */
      /*              bboxes(:,i) = [x y z]'; */
      emlrtMEXProfilingStatement(24, isMexOutdated);
      xMin = homogeneous(Plant_X, Plant_Y, Plant_yaw, (xMin + xMax) / 2.0F,
                         (yMin + yMax) / 2.0F, SP, &y_global);
      emlrtMEXProfilingStatement(25, isMexOutdated);
      if (((int32_T)((real32_T)c_i + 1.0F) < 1) ||
          ((int32_T)((real32_T)c_i + 1.0F) > bboxes->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((real32_T)c_i + 1.0F), 1,
                                      bboxes->size[1], &p_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i = 3 * ((int32_T)((real32_T)c_i + 1.0F) - 1);
      bboxes_data[i] = xMin;
      bboxes_data[i + 1] = y_global;
      bboxes_data[i + 2] = a / 2.0F;
      emlrtMEXProfilingStatement(26, isMexOutdated);
      if (((int32_T)((real32_T)c_i + 1.0F) < 1) ||
          ((int32_T)((real32_T)c_i + 1.0F) > isValidCluster->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((real32_T)c_i + 1.0F), 1,
                                      isValidCluster->size[1], &n_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      isValidCluster_data[(int32_T)(real32_T)(int32_T)((real32_T)c_i + 1.0F) -
                          1] = (l < 5.0F);
      /*  max length of 20 meters */
      emlrtMEXProfilingStatement(27, isMexOutdated);
    }
    emlrtMEXProfilingStatement(28, isMexOutdated);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real32_T(sp, &b_pointData);
  emxFree_int32_T(sp, &r);
  emxFree_real32_T(sp, &pointData);
  emlrtMEXProfilingStatement(29, isMexOutdated);
  idx = isValidCluster->size[1] - 1;
  last = 0;
  for (c_i = 0; c_i <= idx; c_i++) {
    if (isValidCluster_data[c_i]) {
      last++;
    }
  }
  emxInit_int32_T(sp, &r1, 2, &gg_emlrtRTEI);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = last;
  emxEnsureCapacity_int32_T(sp, r1, i, &bg_emlrtRTEI);
  r2 = r1->data;
  last = 0;
  for (c_i = 0; c_i <= idx; c_i++) {
    if (isValidCluster_data[c_i]) {
      r2[last] = c_i;
      last++;
    }
  }
  emxFree_boolean_T(sp, &isValidCluster);
  emxInit_real_T(sp, &b_bboxes, 2, &cg_emlrtRTEI, true);
  i = b_bboxes->size[0] * b_bboxes->size[1];
  b_bboxes->size[0] = 3;
  b_bboxes->size[1] = r1->size[1];
  emxEnsureCapacity_real_T(sp, b_bboxes, i, &cg_emlrtRTEI);
  b_bboxes_data = b_bboxes->data;
  last = r1->size[1];
  for (i = 0; i < last; i++) {
    if (r2[i] > bboxes->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(r2[i], 0, bboxes->size[1] - 1, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_bboxes_data[3 * i] = bboxes_data[3 * r2[i]];
    if (r2[i] > bboxes->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(r2[i], 0, bboxes->size[1] - 1, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_bboxes_data[3 * i + 1] = bboxes_data[3 * r2[i] + 1];
    if (r2[i] > bboxes->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(r2[i], 0, bboxes->size[1] - 1, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_bboxes_data[3 * i + 2] = bboxes_data[3 * r2[i] + 2];
  }
  emxFree_int32_T(sp, &r1);
  i = bboxes->size[0] * bboxes->size[1];
  bboxes->size[0] = 3;
  bboxes->size[1] = b_bboxes->size[1];
  emxEnsureCapacity_real_T(sp, bboxes, i, &eg_emlrtRTEI);
  bboxes_data = bboxes->data;
  last = 3 * b_bboxes->size[1];
  for (i = 0; i < last; i++) {
    bboxes_data[i] = b_bboxes_data[i];
  }
  emxFree_real_T(sp, &b_bboxes);
  /*      if isempty(bboxes) && time< 8e-3 */
  /*          bboxes = [100000;100000;0.001]; */
  /*      end */
  /*      open(writerObj) */
  /*      figure(99) */
  /*      numClusters = numClusters+1; */
  /*      labelColorIndex = labels+1; */
  /*      pcshow(ptCloud.Location,labelColorIndex,'MarkerSize',50) */
  /*      colormap([hsv(numClusters);[1 1 1]]) */
  /*      title('Point Cloud Clusters') */
  /*      view(0,90) */
  /*      xlim([-15 15])bboxes */
  /*      ylim([-15 15]) */
  /*      ax = gca; */
  /*      ax.XColor = 'white'; */
  /*      ax.YColor = 'white'; */
  /*      refreshdata(gcf); */
  /*      %-- get frames as images --% */
  /*      frame = getframe(gcf); */
  /*      %- Add frame to video object -% */
  /*      writeVideo(writerObj, frame); */
  /*      drawnow limitrate; */
  /*      hold off; */
  /*      close(writerObj) */
  emlrtMEXProfilingStatement(30, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return numClusters;
}

/* End of code generation (HelperBoundingBoxDetector.c) */
