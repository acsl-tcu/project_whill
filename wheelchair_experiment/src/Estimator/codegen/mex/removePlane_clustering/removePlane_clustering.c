/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removePlane_clustering.c
 *
 * Code generation for function 'removePlane_clustering'
 *
 */

/* Include files */
#include "removePlane_clustering.h"
#include "convertFromCartesianToSphericalCoordinate.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "handle.h"
#include "lidarParameters.h"
#include "pcorganize.h"
#include "pcsegdist.h"
#include "pointCloud.h"
#include "pointCloudBase.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"
#include "labelRangeDataGroundRemovalUtilsCore_api.hpp"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    2,                        /* lineNo */
    "removePlane_clustering", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pathName
                                                                            */
};

static emlrtRSInfo b_emlrtRSI = {
    3,                        /* lineNo */
    "removePlane_clustering", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pathName
                                                                            */
};

static emlrtRSInfo c_emlrtRSI = {
    12,                       /* lineNo */
    "removePlane_clustering", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pathName
                                                                            */
};

static emlrtRSInfo d_emlrtRSI = {
    19,                       /* lineNo */
    "removePlane_clustering", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pathName
                                                                            */
};

static emlrtRSInfo e_emlrtRSI = {
    21,                       /* lineNo */
    "removePlane_clustering", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pathName
                                                                            */
};

static emlrtRSInfo f_emlrtRSI = {
    8,                        /* lineNo */
    "removePlane_clustering", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    4,                        /* lineNo */
    "removePlane_clustering", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    9,                        /* lineNo */
    "removePlane_clustering", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    14,                       /* lineNo */
    "removePlane_clustering", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pathName
                                                                            */
};

static emlrtRSInfo bb_emlrtRSI = {
    119,                          /* lineNo */
    "pointCloud/findPointsInROI", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    309,                                  /* lineNo */
    "pointCloudBase/findPointsInROIImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    311,                                  /* lineNo */
    "pointCloudBase/findPointsInROIImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    321,                                  /* lineNo */
    "pointCloudBase/findPointsInROIImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    1164,                                         /* lineNo */
    "pointCloud/validateAndParseBoxSearchOption", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    680,                          /* lineNo */
    "pointCloudBase/validateROI", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    581,                                  /* lineNo */
    "pointCloudBase/bruteForceBoxSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    587,                                  /* lineNo */
    "pointCloudBase/bruteForceBoxSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    599,                                  /* lineNo */
    "pointCloudBase/bruteForceBoxSearch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo
    rc_emlrtRSI =
        {
            47,           /* lineNo */
            "pcorganize", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    sc_emlrtRSI =
        {
            50,           /* lineNo */
            "pcorganize", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo le_emlrtRSI = {
    8,                            /* lineNo */
    "segmentGroundFromLidarData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\segmentGroundFromLidarData"
    ".m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI = {
    22,                           /* lineNo */
    "segmentGroundFromLidarData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\segmentGroundFromLidarData"
    ".m" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI = {
    36,                           /* lineNo */
    "segmentGroundFromLidarData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\segmentGroundFromLidarData"
    ".m" /* pathName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    14,                           /* lineNo */
    1,                            /* colNo */
    "segmentGroundFromLidarData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\segmentGroundFromLidarData"
    ".m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    589,                                  /* lineNo */
    51,                                   /* colNo */
    "",                                   /* aName */
    "pointCloudBase/bruteForceBoxSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    1191,                                         /* lineNo */
    17,                                           /* colNo */
    "pointCloud/validateAndParseBoxSearchOption", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    590,                                  /* lineNo */
    41,                                   /* colNo */
    "",                                   /* aName */
    "pointCloudBase/bruteForceBoxSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    590,                                  /* lineNo */
    85,                                   /* colNo */
    "",                                   /* aName */
    "pointCloudBase/bruteForceBoxSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    591,                                  /* lineNo */
    41,                                   /* colNo */
    "",                                   /* aName */
    "pointCloudBase/bruteForceBoxSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    589,                                  /* lineNo */
    27,                                   /* colNo */
    "",                                   /* aName */
    "pointCloudBase/bruteForceBoxSearch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m", /* pName */
    0                             /* checkKind */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    321,              /* lineNo */
    27,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    599,              /* lineNo */
    23,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    37,                           /* lineNo */
    37,                           /* colNo */
    "segmentGroundFromLidarData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\segmentGroundFromLidarData"
    ".m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    12,                       /* lineNo */
    5,                        /* colNo */
    "removePlane_clustering", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pName
                                                                            */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    14,                       /* lineNo */
    35,                       /* colNo */
    "removePlane_clustering", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pName
                                                                            */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    20,                       /* lineNo */
    5,                        /* colNo */
    "removePlane_clustering", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pName
                                                                            */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    1,                        /* lineNo */
    11,                       /* colNo */
    "removePlane_clustering", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pName
                                                                            */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    9,                        /* lineNo */
    5,                        /* colNo */
    "removePlane_clustering", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pName
                                                                            */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    4,                        /* lineNo */
    5,                        /* colNo */
    "removePlane_clustering", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pName
                                                                            */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    2,                        /* lineNo */
    5,                        /* colNo */
    "removePlane_clustering", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_clustering.m" /* pName
                                                                            */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    583,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pName */
};

/* Function Definitions */
void removePlane_clustering(const emlrtStack *sp,
                            const emxArray_real_T *ptCloudLocation,
                            const real_T roi[6], real_T minDistance,
                            const real_T rangeCP[2], emxArray_real_T *notGround,
                            emxArray_uint32_T *labels, real_T *numClusters)
{
  static const char_T functionName[15] = {'f', 'i', 'n', 'd', 'P',
                                          'o', 'i', 'n', 't', 's',
                                          'I', 'n', 'R', 'O', 'I'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_boolean_T *b_groundPtsIdx;
  emxArray_boolean_T *groundPtsIdx;
  emxArray_boolean_T *inROI;
  emxArray_int32_T *ii;
  emxArray_real_T tmp_data;
  emxArray_real_T *rangeData;
  emxArray_uint32_T *b_ii;
  emxArray_uint8_T r;
  pointCloud b_notGround;
  pointCloud ptCloud;
  pointCloud ptCloudIn;
  pointCloud ptCloudOut;
  real_T params_HorizontalBeamAngles[1024];
  real_T params_VerticalBeamAngles_data[16];
  const real_T *ptCloudLocation_data;
  real_T b_expl_temp;
  real_T *notGround_data;
  int32_T iv[2];
  int32_T tmp_size[2];
  int32_T i;
  int32_T k;
  int32_T ptCloudOut_idx_0;
  int32_T ptIter;
  int32_T zOffset;
  int32_T *ii_data;
  uint32_T *b_ii_data;
  boolean_T x[3];
  boolean_T b;
  boolean_T b1;
  boolean_T exitg1;
  boolean_T n;
  boolean_T *groundPtsIdx_data;
  boolean_T *inROI_data;
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
  ptCloudLocation_data = ptCloudLocation->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud(sp, &b_notGround, &sb_emlrtRTEI);
  emxInitStruct_pointCloud(sp, &ptCloudOut, &tb_emlrtRTEI);
  emxInitStruct_pointCloud1(sp, &ptCloudIn, &ub_emlrtRTEI);
  emxInitStruct_pointCloud1(sp, &ptCloud, &vb_emlrtRTEI);
  emxInit_boolean_T(sp, &groundPtsIdx, 2, &pb_emlrtRTEI);
  emxInit_boolean_T(sp, &inROI, 1, &wb_emlrtRTEI);
  emxInit_int32_T(sp, &ii, 1, &xb_emlrtRTEI);
  emxInit_real_T(sp, &rangeData, 3, &ob_emlrtRTEI);
  emxInit_uint32_T(sp, &b_ii, 1, &nb_emlrtRTEI);
  emxInit_boolean_T(sp, &b_groundPtsIdx, 2, &qb_emlrtRTEI);
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ptCloudIn,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  ptCloudIn.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ptCloud,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  ptCloud.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &b_notGround,
                                    (void *)&b_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  b_notGround.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ptCloudOut,
                                    (void *)&b_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ptCloudOut.matlabCodegenIsDeleted = true;
  st.site = &emlrtRSI;
  ptCloud.HasKdtreeConstructed = false;
  ptCloud.HasLocationHandleAllocated = false;
  b_st.site = &j_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  i = ptCloud.Location->size[0] * ptCloud.Location->size[1];
  ptCloud.Location->size[0] = ptCloudLocation->size[0];
  ptCloud.Location->size[1] = 3;
  emxEnsureCapacity_real_T(&b_st, ptCloud.Location, i, &kb_emlrtRTEI);
  zOffset = ptCloudLocation->size[0] * 3;
  for (i = 0; i < zOffset; i++) {
    ptCloud.Location->data[i] = ptCloudLocation_data[i];
  }
  iv[0] = 0;
  iv[1] = 0;
  r.size = &iv[0];
  r.allocatedSize = 0;
  r.numDimensions = 2;
  r.canFreeData = false;
  c_st.site = &n_emlrtRSI;
  pointCloudBase_set_Color(&c_st, &ptCloud, &r);
  c_st.site = &o_emlrtRSI;
  d_st.site = &y_emlrtRSI;
  ptCloud.Normal->size[0] = 0;
  ptCloud.Normal->size[1] = 0;
  c_st.site = &p_emlrtRSI;
  i = ptCloud.Intensity->size[0] * ptCloud.Intensity->size[1];
  ptCloud.Intensity->size[0] = ptCloud.Normal->size[0];
  ptCloud.Intensity->size[1] = ptCloud.Normal->size[1];
  emxEnsureCapacity_real_T(&c_st, ptCloud.Intensity, i, &lb_emlrtRTEI);
  zOffset = ptCloud.Normal->size[0] * ptCloud.Normal->size[1];
  for (i = 0; i < zOffset; i++) {
    ptCloud.Intensity->data[i] = ptCloud.Normal->data[i];
  }
  tmp_size[0] = 0;
  tmp_size[1] = 0;
  tmp_data.size = &tmp_size[0];
  tmp_data.allocatedSize = 0;
  tmp_data.numDimensions = 2;
  tmp_data.canFreeData = false;
  c_st.site = &q_emlrtRSI;
  pointCloudBase_set_RangeData(&c_st, &ptCloud, &tmp_data);
  b_st.site = &k_emlrtRSI;
  ptCloud.PointCloudArrayData->size[0] = 1;
  ptCloud.PointCloudArrayData->size[1] = 1;
  b_st.site = &l_emlrtRSI;
  ptCloud.Kdtree = NULL;
  ptCloud.LocationHandle = NULL;
  ptCloud.matlabCodegenIsDeleted = false;
  st.site = &b_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  d_st.site = &fb_emlrtRSI;
  n = (ptCloud.PointCloudArrayData->size[0] *
           ptCloud.PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &f_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 15, &functionName[0]);
  }
  c_st.site = &db_emlrtRSI;
  d_st.site = &gb_emlrtRSI;
  e_st.site = &hb_emlrtRSI;
  f_st.site = &ib_emlrtRSI;
  n = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 6)) {
    if (!muDoubleScalarIsNaN(roi[k])) {
      k++;
    } else {
      n = false;
      exitg1 = true;
    }
  }
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:expectedNonNaN", 3, 4, 3, "roi");
  }
  x[0] = (roi[0] > roi[3]);
  x[1] = (roi[1] > roi[4]);
  x[2] = (roi[2] > roi[5]);
  n = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (x[k]) {
      n = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (n) {
    emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
                                  "vision:pointcloud:invalidROI",
                                  "vision:pointcloud:invalidROI", 0);
  }
  c_st.site = &eb_emlrtRSI;
  d_st.site = &jb_emlrtRSI;
  k = ptCloud.Location->size[0];
  i = inROI->size[0];
  inROI->size[0] = k;
  emxEnsureCapacity_boolean_T(&c_st, inROI, i, &mb_emlrtRTEI);
  inROI_data = inROI->data;
  zOffset = k << 1;
  d_st.site = &kb_emlrtRSI;
  if (k > 2147483646) {
    e_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (ptIter = 0; ptIter < k; ptIter++) {
    real_T expl_temp;
    i = ptCloud.Location->size[0] * 3;
    if (ptIter + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(ptIter + 1, 1, i, &emlrtBCI, &c_st);
    }
    ptCloudOut_idx_0 = (ptIter + k) + 1;
    if ((ptCloudOut_idx_0 < 1) || (ptCloudOut_idx_0 > i)) {
      emlrtDynamicBoundsCheckR2012b(ptCloudOut_idx_0, 1, i, &b_emlrtBCI, &c_st);
    }
    expl_temp = ptCloud.Location->data[ptCloudOut_idx_0 - 1];
    if (ptCloudOut_idx_0 > i) {
      emlrtDynamicBoundsCheckR2012b(ptCloudOut_idx_0, 1, i, &c_emlrtBCI, &c_st);
    }
    ptCloudOut_idx_0 = (ptIter + zOffset) + 1;
    if ((ptCloudOut_idx_0 < 1) || (ptCloudOut_idx_0 > i)) {
      emlrtDynamicBoundsCheckR2012b(ptCloudOut_idx_0, 1, i, &d_emlrtBCI, &c_st);
    }
    b_expl_temp = ptCloud.Location->data[ptCloudOut_idx_0 - 1];
    if (ptIter + 1 > inROI->size[0]) {
      emlrtDynamicBoundsCheckR2012b(ptIter + 1, 1, inROI->size[0], &e_emlrtBCI,
                                    &c_st);
    }
    inROI_data[ptIter] = ((ptCloud.Location->data[ptIter] >= roi[0]) &&
                          (ptCloud.Location->data[ptIter] <= roi[3]) &&
                          (expl_temp >= roi[1]) && (expl_temp <= roi[4]) &&
                          (b_expl_temp >= roi[2]) && (b_expl_temp <= roi[5]));
  }
  d_st.site = &lb_emlrtRSI;
  e_st.site = &mb_emlrtRSI;
  eml_find(&e_st, inROI, ii);
  ii_data = ii->data;
  i = b_ii->size[0];
  b_ii->size[0] = ii->size[0];
  emxEnsureCapacity_uint32_T(sp, b_ii, i, &nb_emlrtRTEI);
  b_ii_data = b_ii->data;
  zOffset = ii->size[0];
  for (i = 0; i < zOffset; i++) {
    ptCloudOut_idx_0 = ii_data[i];
    if (ptCloudOut_idx_0 < 0) {
      ptCloudOut_idx_0 = 0;
    }
    b_ii_data[i] = (uint32_T)ptCloudOut_idx_0;
  }
  int32_T params_VerticalBeamAngles_size[2];
  st.site = &g_emlrtRSI;
  pointCloud_select(&st, &ptCloud, b_ii, &ptCloudIn);
  /*  transform organized point cloud */
  st.site = &f_emlrtRSI;
  lidarParameters_lidarParameters(
      &st, &b_expl_temp, params_VerticalBeamAngles_data,
      params_VerticalBeamAngles_size, params_HorizontalBeamAngles);
  st.site = &h_emlrtRSI;
  b_st.site = &rc_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  d_st.site = &tc_emlrtRSI;
  n = (ptCloudIn.PointCloudArrayData->size[0] *
           ptCloudIn.PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:pcorganize:expectedScalar", 3, 4, 9, "ptCloudIn");
  }
  b_st.site = &sc_emlrtRSI;
  pcorganizeImpl(&b_st, &ptCloudIn, params_VerticalBeamAngles_data,
                 params_HorizontalBeamAngles, &ptCloudOut);
  /*  segment ground */
  st.site = &c_emlrtRSI;
  b_st.site = &le_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  d_st.site = &tc_emlrtRSI;
  n = (ptCloudOut.PointCloudArrayData->size[0] *
           ptCloudOut.PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:segmentGroundFromLidarData:expectedScalar", 3, 4, 7, "ptCloud");
  }
  if (ptCloudOut.Location->size[0] <= 1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "vision:pointcloud:rowSizeMustBeGreaterThanOne",
        "vision:pointcloud:rowSizeMustBeGreaterThanOne", 0);
  }
  n = (ptCloudOut.RangeData->size[0] == 0);
  b = (ptCloudOut.RangeData->size[1] == 0);
  b1 = (ptCloudOut.RangeData->size[2] == 0);
  if (n || b || b1) {
    b_st.site = &me_emlrtRSI;
    c_st.site = &me_emlrtRSI;
    c_convertFromCartesianToSpheric(&c_st, ptCloudOut.Location,
                                    ptCloudOut.RangeData);
    c_st.site = &ab_emlrtRSI;
    k = ptCloudOut.Location->size[0];
    zOffset = ptCloudOut.Location->size[1];
    ptCloudOut_idx_0 = ptCloudOut.RangeData->size[0];
    ptIter = ptCloudOut.RangeData->size[1];
    if ((ptCloudOut_idx_0 != 0) && (ptIter != 0)) {
      uint32_T varargin_1[3];
      uint32_T varargin_2[3];
      uint32_T b_ptCloudOut_idx_0;
      uint32_T ptCloudOut_idx_1;
      b_ptCloudOut_idx_0 = (uint32_T)ptCloudOut.RangeData->size[0];
      ptCloudOut_idx_1 = (uint32_T)ptCloudOut.RangeData->size[1];
      varargin_1[0] = b_ptCloudOut_idx_0;
      varargin_2[0] = (uint32_T)k;
      varargin_1[1] = ptCloudOut_idx_1;
      varargin_2[1] = (uint32_T)zOffset;
      varargin_1[2] = 3U;
      varargin_2[2] = 3U;
      n = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if ((int32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
          n = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (!n) {
        emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                      "vision:pointcloud:unmatchedXYZRange",
                                      "vision:pointcloud:unmatchedXYZRange", 0);
      }
    }
  }
  b_st.site = &ne_emlrtRSI;
  i = rangeData->size[0] * rangeData->size[1] * rangeData->size[2];
  rangeData->size[0] = ptCloudOut.RangeData->size[0];
  rangeData->size[1] = ptCloudOut.RangeData->size[1];
  rangeData->size[2] = ptCloudOut.RangeData->size[2];
  emxEnsureCapacity_real_T(&b_st, rangeData, i, &ob_emlrtRTEI);
  notGround_data = rangeData->data;
  k = ptCloudOut.RangeData->size[0] * ptCloudOut.RangeData->size[1];
  zOffset = k * ptCloudOut.RangeData->size[2];
  for (i = 0; i < zOffset; i++) {
    notGround_data[i] = ptCloudOut.RangeData->data[i];
  }
  i = groundPtsIdx->size[0] * groundPtsIdx->size[1];
  groundPtsIdx->size[0] = rangeData->size[0];
  groundPtsIdx->size[1] = rangeData->size[1];
  emxEnsureCapacity_boolean_T(&b_st, groundPtsIdx, i, &pb_emlrtRTEI);
  inROI_data = groundPtsIdx->data;
  for (i = 0; i < k; i++) {
    inROI_data[i] = false;
  }
  preprocessAndSegmentGround_double(
      &notGround_data[0], rangeData->size[0], rangeData->size[1],
      &inROI_data[0], 0.52359877559829882, 0.087266462599716474, 1.0);
  /*  ground = select(ptCloudOut,groundPtsIdx); */
  i = b_groundPtsIdx->size[0] * b_groundPtsIdx->size[1];
  b_groundPtsIdx->size[0] = groundPtsIdx->size[0];
  b_groundPtsIdx->size[1] = groundPtsIdx->size[1];
  emxEnsureCapacity_boolean_T(sp, b_groundPtsIdx, i, &qb_emlrtRTEI);
  groundPtsIdx_data = b_groundPtsIdx->data;
  zOffset = groundPtsIdx->size[0] * groundPtsIdx->size[1];
  for (i = 0; i < zOffset; i++) {
    groundPtsIdx_data[i] = !inROI_data[i];
  }
  st.site = &i_emlrtRSI;
  b_pointCloud_select(&st, &ptCloudOut, b_groundPtsIdx, &b_notGround);
  /*  clustering */
  /*  minDistance = 0.2; */
  /*  rangeCP = [300,inf]; */
  st.site = &d_emlrtRSI;
  *numClusters = pcsegdist(&st, &b_notGround, minDistance, rangeCP, labels);
  i = notGround->size[0] * notGround->size[1] * notGround->size[2];
  notGround->size[0] = b_notGround.Location->size[0];
  notGround->size[1] = b_notGround.Location->size[1];
  notGround->size[2] = 3;
  emxEnsureCapacity_real_T(sp, notGround, i, &rb_emlrtRTEI);
  notGround_data = notGround->data;
  zOffset = b_notGround.Location->size[0] * b_notGround.Location->size[1] * 3;
  for (i = 0; i < zOffset; i++) {
    notGround_data[i] = b_notGround.Location->data[i];
  }
  st.site = &e_emlrtRSI;
  b_handle_matlabCodegenDestructo(&st, &ptCloudOut);
  st.site = &e_emlrtRSI;
  b_handle_matlabCodegenDestructo(&st, &b_notGround);
  st.site = &e_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &ptCloud);
  st.site = &e_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &ptCloudIn);
  emxFree_boolean_T(sp, &b_groundPtsIdx);
  emxFree_uint32_T(sp, &b_ii);
  emxFree_real_T(sp, &rangeData);
  emxFree_int32_T(sp, &ii);
  emxFree_boolean_T(sp, &inROI);
  emxFree_boolean_T(sp, &groundPtsIdx);
  emxFreeStruct_pointCloud(sp, &ptCloud);
  emxFreeStruct_pointCloud(sp, &ptCloudIn);
  emxFreeStruct_pointCloud(sp, &ptCloudOut);
  emxFreeStruct_pointCloud(sp, &b_notGround);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (removePlane_clustering.c) */
