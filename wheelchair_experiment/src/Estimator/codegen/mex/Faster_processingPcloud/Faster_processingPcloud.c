/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Faster_processingPcloud.c
 *
 * Code generation for function 'Faster_processingPcloud'
 *
 */

/* Include files */
#include "Faster_processingPcloud.h"
#include "Faster_processingPcloud_data.h"
#include "Faster_processingPcloud_emxutil.h"
#include "Faster_processingPcloud_internal_types.h"
#include "Faster_processingPcloud_types.h"
#include "HelperBoundingBoxDetector.h"
#include "handle.h"
#include "pointCloud.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Variable Definitions */
static boolean_T detectorModel_not_empty;

static emlrtRSInfo emlrtRSI = {
    5,                         /* lineNo */
    "Faster_processingPcloud", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/Faster_processingPcloud.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    10,                        /* lineNo */
    "Faster_processingPcloud", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/Faster_processingPcloud.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    16,                        /* lineNo */
    "Faster_processingPcloud", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/Faster_processingPcloud.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    18,                        /* lineNo */
    "Faster_processingPcloud", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/Faster_processingPcloud.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    60,                                                    /* lineNo */
    "HelperBoundingBoxDetector/HelperBoundingBoxDetector", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    61,                                                    /* lineNo */
    "HelperBoundingBoxDetector/HelperBoundingBoxDetector", /* fcnName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/HelperBoundingBoxDetector.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    1,               /* lineNo */
    "System/System", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/System.p" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    1,                          /* lineNo */
    "SystemProp/setProperties", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemProp.p" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    1,                           /* lineNo */
    "SystemCore/parenReference", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    1,                           /* lineNo */
    1,                           /* colNo */
    "SystemCore/parenReference", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/system/coder/+matlab/+system/"
    "+coder/SystemCore.p" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    10,                        /* lineNo */
    5,                         /* colNo */
    "Faster_processingPcloud", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/Faster_processingPcloud.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    2,                         /* lineNo */
    76,                        /* colNo */
    "Faster_processingPcloud", /* fName */
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/Faster_processingPcloud.m" /* pName */
};

/* Function Definitions */
void Faster_processingPcloud(const emlrtStack *sp, const emxArray_real_T *pt,
                             real_T theta, const real_T trans[3],
                             const real_T roi[6], real_T distThreshold,
                             real_T b_time, emxArray_real_T *detections,
                             emxArray_real_T *survivedIndices,
                             emxArray_real_T *obstacleIndices,
                             emxArray_real_T *labels, real_T *numClusters)
{
  static HelperBoundingBoxDetector detectorModel;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *varargout_3;
  emxArray_real_T *varargout_5;
  pointCloud ptCloud;
  (void)b_time;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud(sp, &ptCloud, &db_emlrtRTEI);
  emxInit_real_T(sp, &varargout_5, 1, &eb_emlrtRTEI);
  emxInit_real_T(sp, &varargout_3, 1, &eb_emlrtRTEI);
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ptCloud,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  ptCloud.matlabCodegenIsDeleted = true;
  /*  latest 2024/11/17~ */
  if (!detectorModel_not_empty) {
    st.site = &emlrtRSI;
    detectorModel.MaxZDistanceCluster = 2.0;
    detectorModel.MinZDistanceCluster = -2.0;
    b_st.site = &e_emlrtRSI;
    c_st.site = &g_emlrtRSI;
    c_st.site = &g_emlrtRSI;
    detectorModel.isInitialized = 0;
    b_st.site = &f_emlrtRSI;
    c_st.site = &h_emlrtRSI;
    detectorModel.SegmentationMinDistance = distThreshold;
    detectorModel.MinDetectionsPerCluster = 5.0;
    detectorModel_not_empty = true;
    /*    % minimum Euclidian distance */
    /*      % minimum points per cluster */
    /*        % measurement noise in detection report. */
    /*  maximum distance of ground points from ground plane */
  }
  st.site = &b_emlrtRSI;
  pointCloud_pointCloud(&st, &ptCloud, pt);
  /*  Sensor(LiDAR) position */
  st.site = &c_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  if (detectorModel.isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &emlrtRTEI, "MATLAB:system:methodCalledWhenReleasedCodegen",
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }
  if (detectorModel.isInitialized != 1) {
    c_st.site = &i_emlrtRSI;
    d_st.site = &i_emlrtRSI;
    if (detectorModel.isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &emlrtRTEI,
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
          "setup");
    }
    detectorModel.isInitialized = 1;
  }
  c_st.site = &i_emlrtRSI;
  *numClusters = c_HelperBoundingBoxDetector_ste(
      &c_st, &detectorModel, &ptCloud, trans[0], trans[1], trans[2], theta, roi,
      detections, survivedIndices, varargout_3, obstacleIndices, varargout_5,
      labels);
  st.site = &d_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &ptCloud);
  emxFree_real_T(sp, &varargout_3);
  emxFree_real_T(sp, &varargout_5);
  emxFreeStruct_pointCloud(sp, &ptCloud);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void Faster_processingPcloud_init(void)
{
  detectorModel_not_empty = false;
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

/* End of code generation (Faster_processingPcloud.c) */
