/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcsegdist.c
 *
 * Code generation for function 'pcsegdist'
 *
 */

/* Include files */
#include "pcsegdist.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "handle.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "pointCloud.h"
#include "pointCloudBase.h"
#include "rt_nonfinite.h"
#include "unique.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ch_emlrtRSI = {
    11,                                                          /* lineNo */
    "pcsegdist",                                                 /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo dh_emlrtRSI = {
    14,                                                          /* lineNo */
    "pcsegdist",                                                 /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo eh_emlrtRSI = {
    28,                                                          /* lineNo */
    "pcsegdist",                                                 /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo fh_emlrtRSI = {
    138,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    153,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo hh_emlrtRSI = {
    160,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo ih_emlrtRSI = {
    161,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    166,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo kh_emlrtRSI = {
    180,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo lh_emlrtRSI = {
    136,                                                         /* lineNo */
    "pcsegdistImpl",                                             /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pathName */
};

static emlrtRSInfo mh_emlrtRSI = {
    236,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo nh_emlrtRSI = {
    239,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo oh_emlrtRSI = {
    241,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo ph_emlrtRSI = {
    245,                              /* lineNo */
    "pointCloud/removeInvalidPoints", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    299,                             /* lineNo */
    "pointCloud/extractValidPoints", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo rh_emlrtRSI = {
    302,                             /* lineNo */
    "pointCloud/extractValidPoints", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    303,                             /* lineNo */
    "pointCloud/extractValidPoints", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    430,                                     /* lineNo */
    "pointCloudBase/extractValidPointsImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pathName */
};

static emlrtRSInfo xh_emlrtRSI = {
    182,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo yh_emlrtRSI = {
    200,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    210,                                                          /* lineNo */
    20,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    203,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtECInfo i_emlrtECI = {
    -1,                                                          /* nDims */
    179,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pcsegdistImpl",                                             /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    175,                                                          /* lineNo */
    29,                                                           /* colNo */
    "",                                                           /* aName */
    "pcsegdistImpl",                                              /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    174,                                                         /* lineNo */
    13,                                                          /* colNo */
    "pcsegdistImpl",                                             /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    160,                                                          /* lineNo */
    53,                                                           /* colNo */
    "",                                                           /* aName */
    "pcsegdistImpl",                                              /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    155,                                                          /* lineNo */
    14,                                                           /* colNo */
    "",                                                           /* aName */
    "pcsegdistImpl",                                              /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    179,                                                          /* lineNo */
    8,                                                            /* colNo */
    "",                                                           /* aName */
    "pcsegdistImpl",                                              /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    225,                                                          /* lineNo */
    6,                                                            /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    206,                                                          /* lineNo */
    10,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    206,                                                          /* lineNo */
    22,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    175,                                                          /* lineNo */
    11,                                                           /* colNo */
    "",                                                           /* aName */
    "pcsegdistImpl",                                              /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    227,                                                          /* lineNo */
    7,                                                            /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    216,                                                          /* lineNo */
    14,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    207,                                                          /* lineNo */
    14,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    207,                                                          /* lineNo */
    21,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    218,                                                          /* lineNo */
    18,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    217,                                                          /* lineNo */
    15,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    209,                                                          /* lineNo */
    25,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    219,                                                          /* lineNo */
    22,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    219,                                                          /* lineNo */
    15,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    208,                                                          /* lineNo */
    28,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    208,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    210,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "labelPoints",                                                /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo hg_emlrtRTEI = {
    132,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = {
    427,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

static emlrtRTEInfo jg_emlrtRTEI = {
    170,                     /* lineNo */
    24,                      /* colNo */
    "combineVectorElements", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pName */
};

static emlrtRTEInfo kg_emlrtRTEI = {
    302,          /* lineNo */
    17,           /* colNo */
    "pointCloud", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pName */
};

static emlrtRTEInfo lg_emlrtRTEI = {
    1,                                                           /* lineNo */
    34,                                                          /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = {
    138,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = {
    227,                                                         /* lineNo */
    7,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo og_emlrtRTEI = {
    136,                                                         /* lineNo */
    2,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = {
    149,                                                         /* lineNo */
    9,                                                           /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo qg_emlrtRTEI = {
    15,                                                             /* lineNo */
    9,                                                              /* colNo */
    "sum",                                                          /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/sum.m" /* pName */
};

static emlrtRTEInfo rg_emlrtRTEI = {
    208,                                                         /* lineNo */
    15,                                                          /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

static emlrtRTEInfo sg_emlrtRTEI = {
    210,                                                         /* lineNo */
    15,                                                          /* colNo */
    "pcsegdist",                                                 /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/pcsegdist.m" /* pName */
};

/* Function Definitions */
real32_T pcsegdist(const emlrtStack *sp, const pointCloud *ptCloud,
                   real_T minDistance, emxArray_uint32_T *labels)
{
  static const char_T functionName[19] = {'r', 'e', 'm', 'o', 'v', 'e', 'I',
                                          'n', 'v', 'a', 'l', 'i', 'd', 'P',
                                          'o', 'i', 'n', 't', 's'};
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
  emxArray_boolean_T *indices;
  emxArray_boolean_T *tf;
  emxArray_int32_T *b_r;
  emxArray_int32_T *ii;
  emxArray_int32_T *nz;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_real32_T *intensity;
  emxArray_real32_T *loc;
  emxArray_real32_T *nv;
  emxArray_real32_T *r;
  emxArray_uint32_T *L;
  emxArray_uint32_T *ind;
  emxArray_uint8_T *c;
  pointCloud pc;
  pointCloud *b_pc;
  real_T newLabel;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  int32_T loop_ub;
  int32_T vstride;
  int32_T xoffset;
  int32_T *ii_data;
  int32_T *nz_data;
  real32_T numClusters;
  real32_T *loc_data;
  uint32_T labelsSize_idx_0;
  uint32_T u;
  uint32_T *L_data;
  uint32_T *ind_data;
  uint32_T *labels_data;
  uint8_T *c_data;
  boolean_T *tf_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud(sp, &pc, &og_emlrtRTEI);
  emxInit_uint32_T(sp, &L, 1, &mg_emlrtRTEI, true);
  emxInit_uint32_T(sp, &ind, 1, &pg_emlrtRTEI, true);
  emxInit_boolean_T(sp, &indices, 1, &lg_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &qe_emlrtRTEI);
  emxInit_boolean_T(sp, &tf, 2, &ig_emlrtRTEI, true);
  emxInit_int32_T(sp, &nz, 1, &qg_emlrtRTEI);
  nz_data = nz->data;
  emxInit_real32_T(sp, &loc, 2, &lg_emlrtRTEI);
  emxInit_uint8_T(sp, &c, &lg_emlrtRTEI);
  emxInit_real32_T(sp, &nv, 2, &lg_emlrtRTEI);
  emxInit_real32_T(sp, &intensity, 2, &lg_emlrtRTEI);
  emxInit_real32_T(sp, &r, 2, &lg_emlrtRTEI);
  emxInit_int32_T(sp, &b_r, 1, &vf_emlrtRTEI);
  emxInit_int32_T(sp, &r1, 1, &vf_emlrtRTEI);
  emxInit_int32_T(sp, &r2, 1, &vf_emlrtRTEI);
  emxInit_int32_T(sp, &r3, 1, &vf_emlrtRTEI);
  emxInit_int32_T(sp, &r4, 1, &rg_emlrtRTEI);
  emxInit_int32_T(sp, &r5, 1, &sg_emlrtRTEI);
  st.site = &ch_emlrtRSI;
  b_st.site = &jc_emlrtRSI;
  c_st.site = &we_emlrtRSI;
  if (ptCloud->PointCloudArrayData->size[0] *
          ptCloud->PointCloudArrayData->size[1] !=
      1) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &t_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:pcsegdist:expectedScalar", 3, 4, 7, "ptCloud");
  }
  st.site = &dh_emlrtRSI;
  b_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsNaN(minDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &q_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:pcsegdist:expectedNonNaN", 3, 4, 11, "minDistance");
  }
  b_st.site = &jc_emlrtRSI;
  if (minDistance <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &fb_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:pcsegdist:expectedPositive", 3, 4, 11, "minDistance");
  }
  b_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsInf(minDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:pcsegdist:expectedFinite", 3, 4, 11, "minDistance");
  }
  st.site = &eh_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, &pc,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  pc.matlabCodegenIsDeleted = true;
  labelsSize_idx_0 = (uint32_T)ptCloud->Location->size[0];
  i = labels->size[0];
  labels->size[0] = (int32_T)labelsSize_idx_0;
  emxEnsureCapacity_uint32_T(&st, labels, i, &hg_emlrtRTEI);
  labels_data = labels->data;
  loop_ub = (int32_T)labelsSize_idx_0;
  for (i = 0; i < loop_ub; i++) {
    labels_data[i] = 0U;
  }
  b_st.site = &lh_emlrtRSI;
  c_st.site = &mh_emlrtRSI;
  d_st.site = &qh_emlrtRSI;
  e_st.site = &ng_emlrtRSI;
  if (ptCloud->PointCloudArrayData->size[0] *
          ptCloud->PointCloudArrayData->size[1] !=
      1) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &y_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 19, &functionName[0]);
  }
  d_st.site = &rh_emlrtRSI;
  i = tf->size[0] * tf->size[1];
  tf->size[0] = ptCloud->Location->size[0];
  tf->size[1] = 3;
  emxEnsureCapacity_boolean_T(&d_st, tf, i, &ig_emlrtRTEI);
  tf_data = tf->data;
  loop_ub = ptCloud->Location->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    tf_data[i] = ((!muSingleScalarIsInf(ptCloud->Location->data[i])) &&
                  (!muSingleScalarIsNaN(ptCloud->Location->data[i])));
  }
  e_st.site = &th_emlrtRSI;
  f_st.site = &uh_emlrtRSI;
  g_st.site = &vh_emlrtRSI;
  if (tf->size[0] == 0) {
    nz->size[0] = 0;
  } else {
    h_st.site = &wh_emlrtRSI;
    vstride = tf->size[0];
    i = nz->size[0];
    nz->size[0] = tf->size[0];
    emxEnsureCapacity_int32_T(&h_st, nz, i, &jg_emlrtRTEI);
    nz_data = nz->data;
    i_st.site = &xh_emlrtRSI;
    if (tf->size[0] > 2147483646) {
      j_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&j_st);
    }
    for (loop_ub = 0; loop_ub < vstride; loop_ub++) {
      nz_data[loop_ub] = tf_data[loop_ub];
    }
    for (k = 0; k < 2; k++) {
      xoffset = (k + 1) * vstride;
      i_st.site = &yh_emlrtRSI;
      for (loop_ub = 0; loop_ub < vstride; loop_ub++) {
        nz_data[loop_ub] += tf_data[xoffset + loop_ub];
      }
    }
  }
  i = indices->size[0];
  indices->size[0] = nz->size[0];
  emxEnsureCapacity_boolean_T(&d_st, indices, i, &kg_emlrtRTEI);
  tf_data = indices->data;
  loop_ub = nz->size[0];
  for (i = 0; i < loop_ub; i++) {
    tf_data[i] = (nz_data[i] == 3);
  }
  d_st.site = &sh_emlrtRSI;
  e_st.site = &qg_emlrtRSI;
  if (ptCloud->Location->size[0] != 0) {
    vstride = indices->size[0] - 1;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = ii->size[0];
    ii->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, ii, i, &lg_emlrtRTEI);
    ii_data = ii->data;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        ii_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->Location->size[0];
    i = loc->size[0] * loc->size[1];
    loc->size[0] = ii->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real32_T(&e_st, loc, i, &vf_emlrtRTEI);
    loc_data = loc->data;
    loop_ub = ii->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        if (ii_data[i1] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(ii_data[i1], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        loc_data[i1 + loc->size[0] * i] =
            ptCloud->Location
                ->data[ii_data[i1] + ptCloud->Location->size[0] * i];
      }
    }
  } else {
    loc->size[0] = 0;
    loc->size[1] = 3;
  }
  if ((ptCloud->Color->size[0] != 0) && (ptCloud->Color->size[1] != 0)) {
    vstride = indices->size[0] - 1;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = b_r->size[0];
    b_r->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, b_r, i, &lg_emlrtRTEI);
    nz_data = b_r->data;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        nz_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->Color->size[0];
    i = c->size[0] * c->size[1];
    c->size[0] = b_r->size[0];
    c->size[1] = ptCloud->Color->size[1];
    emxEnsureCapacity_uint8_T(&e_st, c, i, &vf_emlrtRTEI);
    c_data = c->data;
    loop_ub = ptCloud->Color->size[1];
    for (i = 0; i < loop_ub; i++) {
      vstride = b_r->size[0];
      for (i1 = 0; i1 < vstride; i1++) {
        if (nz_data[i1] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[i1], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        c_data[i1 + c->size[0] * i] =
            ptCloud->Color->data[nz_data[i1] + ptCloud->Color->size[0] * i];
      }
    }
  } else {
    c->size[0] = 0;
    c->size[1] = 0;
  }
  if ((ptCloud->Normal->size[0] != 0) && (ptCloud->Normal->size[1] != 0)) {
    vstride = indices->size[0] - 1;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = r1->size[0];
    r1->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, r1, i, &lg_emlrtRTEI);
    nz_data = r1->data;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        nz_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->Normal->size[0];
    i = nv->size[0] * nv->size[1];
    nv->size[0] = r1->size[0];
    nv->size[1] = ptCloud->Normal->size[1];
    emxEnsureCapacity_real32_T(&e_st, nv, i, &vf_emlrtRTEI);
    loc_data = nv->data;
    loop_ub = ptCloud->Normal->size[1];
    for (i = 0; i < loop_ub; i++) {
      vstride = r1->size[0];
      for (i1 = 0; i1 < vstride; i1++) {
        if (nz_data[i1] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[i1], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        loc_data[i1 + nv->size[0] * i] =
            ptCloud->Normal->data[nz_data[i1] + ptCloud->Normal->size[0] * i];
      }
    }
  } else {
    nv->size[0] = 0;
    nv->size[1] = 0;
  }
  if ((ptCloud->Intensity->size[0] != 0) &&
      (ptCloud->Intensity->size[1] != 0)) {
    vstride = indices->size[0] - 1;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = r2->size[0];
    r2->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, r2, i, &lg_emlrtRTEI);
    nz_data = r2->data;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        nz_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->Intensity->size[0];
    i = intensity->size[0] * intensity->size[1];
    intensity->size[0] = r2->size[0];
    intensity->size[1] = ptCloud->Intensity->size[1];
    emxEnsureCapacity_real32_T(&e_st, intensity, i, &vf_emlrtRTEI);
    loc_data = intensity->data;
    loop_ub = ptCloud->Intensity->size[1];
    for (i = 0; i < loop_ub; i++) {
      vstride = r2->size[0];
      for (i1 = 0; i1 < vstride; i1++) {
        if (nz_data[i1] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[i1], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        loc_data[i1 + intensity->size[0] * i] =
            ptCloud->Intensity
                ->data[nz_data[i1] + ptCloud->Intensity->size[0] * i];
      }
    }
  } else {
    intensity->size[0] = 0;
    intensity->size[1] = 0;
  }
  if ((ptCloud->RangeData->size[0] != 0) &&
      (ptCloud->RangeData->size[1] != 0)) {
    vstride = indices->size[0] - 1;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        xoffset++;
      }
    }
    i = r3->size[0];
    r3->size[0] = xoffset;
    emxEnsureCapacity_int32_T(&e_st, r3, i, &lg_emlrtRTEI);
    nz_data = r3->data;
    xoffset = 0;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (tf_data[b_i]) {
        nz_data[xoffset] = b_i;
        xoffset++;
      }
    }
    xoffset = ptCloud->RangeData->size[0];
    i = r->size[0] * r->size[1];
    r->size[0] = r3->size[0];
    r->size[1] = ptCloud->RangeData->size[1];
    emxEnsureCapacity_real32_T(&e_st, r, i, &vf_emlrtRTEI);
    loc_data = r->data;
    loop_ub = ptCloud->RangeData->size[1];
    for (i = 0; i < loop_ub; i++) {
      vstride = r3->size[0];
      for (i1 = 0; i1 < vstride; i1++) {
        if (nz_data[i1] > xoffset - 1) {
          emlrtDynamicBoundsCheckR2012b(nz_data[i1], 0, xoffset - 1,
                                        &m_emlrtBCI, &e_st);
        }
        loc_data[i1 + r->size[0] * i] =
            ptCloud->RangeData
                ->data[nz_data[i1] + ptCloud->RangeData->size[0] * i];
      }
    }
  } else {
    r->size[0] = 0;
    r->size[1] = 0;
  }
  c_st.site = &nh_emlrtRSI;
  b_pc = b_pointCloud_pointCloud(&c_st, &pc, loc, c, nv, intensity);
  c_st.site = &oh_emlrtRSI;
  pointCloudBase_set_RangeData(&c_st, b_pc, r);
  c_st.site = &ph_emlrtRSI;
  d_st.site = &cg_emlrtRSI;
  eml_find(&d_st, indices, ii);
  ii_data = ii->data;
  b_st.site = &fh_emlrtRSI;
  xoffset = pc.Location->size[0];
  i = L->size[0];
  L->size[0] = xoffset;
  emxEnsureCapacity_uint32_T(&st, L, i, &mg_emlrtRTEI);
  L_data = L->data;
  for (i = 0; i < xoffset; i++) {
    L_data[i] = 0U;
  }
  newLabel = 0.0;
  b_st.site = &gh_emlrtRSI;
  i = pc.Location->size[0] - 1;
  for (b_i = 0; b_i <= i; b_i++) {
    if (b_i + 1 > L->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &v_emlrtBCI, &st);
    }
    if (L_data[b_i] == 0U) {
      real_T b_newLabel;
      real32_T c_pc[3];
      i1 = pc.Location->size[0];
      if (b_i + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i1, &u_emlrtBCI, &st);
      }
      c_pc[0] = pc.Location->data[b_i];
      c_pc[1] = pc.Location->data[b_i + pc.Location->size[0]];
      c_pc[2] = pc.Location->data[b_i + pc.Location->size[0] * 2];
      b_st.site = &hh_emlrtRSI;
      c_pointCloud_findNeighborsInRad(&b_st, &pc, c_pc, (real32_T)minDistance,
                                      ind);
      ind_data = ind->data;
      b_st.site = &ih_emlrtRSI;
      b_newLabel = newLabel;
      i1 = ind->size[0];
      for (k = 0; k < i1; k++) {
        uint32_T b_L;
        boolean_T b;
        boolean_T guard1;
        if (k + 1 > ind->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, ind->size[0], &s_emlrtBCI,
                                        &b_st);
        }
        if (((int32_T)ind_data[k] < 1) || ((int32_T)ind_data[k] > L->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[k], 1, L->size[0],
                                        &y_emlrtBCI, &b_st);
        }
        i2 = (int32_T)ind_data[k] - 1;
        b_L = L_data[i2];
        guard1 = false;
        if (b_L > 0U) {
          uint32_T c_L;
          if (b_i + 1 > L->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &ab_emlrtBCI,
                                          &b_st);
          }
          c_L = L_data[b_i];
          if (c_L > 0U) {
            b = (((int32_T)ind_data[k] < 1) ||
                 ((int32_T)ind_data[k] > L->size[0]));
            if (b) {
              emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[k], 1, L->size[0],
                                            &eb_emlrtBCI, &b_st);
            }
            if (b_i + 1 > L->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                            &fb_emlrtBCI, &b_st);
            }
            if (b_L > c_L) {
              vstride = L->size[0] - 1;
              xoffset = 0;
              for (loop_ub = 0; loop_ub <= vstride; loop_ub++) {
                if (L_data[loop_ub] == b_L) {
                  xoffset++;
                }
              }
              i2 = r4->size[0];
              r4->size[0] = xoffset;
              emxEnsureCapacity_int32_T(&b_st, r4, i2, &lg_emlrtRTEI);
              nz_data = r4->data;
              xoffset = 0;
              for (loop_ub = 0; loop_ub <= vstride; loop_ub++) {
                if (L_data[loop_ub] == b_L) {
                  nz_data[xoffset] = loop_ub;
                  xoffset++;
                }
              }
              if (b_i + 1 > L->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                              &lb_emlrtBCI, &b_st);
              }
              loop_ub = r4->size[0];
              for (i2 = 0; i2 < loop_ub; i2++) {
                if (nz_data[i2] > L->size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(nz_data[i2], 0, L->size[0] - 1,
                                                &mb_emlrtBCI, &b_st);
                }
                L_data[nz_data[i2]] = c_L;
              }
            } else {
              if (b_i + 1 > L->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                              &ib_emlrtBCI, &b_st);
              }
              if (b_L < c_L) {
                if (b_i + 1 > L->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                                &r_emlrtBCI, &b_st);
                }
                vstride = L->size[0] - 1;
                xoffset = 0;
                for (loop_ub = 0; loop_ub <= vstride; loop_ub++) {
                  if (L_data[loop_ub] == L_data[b_i]) {
                    xoffset++;
                  }
                }
                i2 = r5->size[0];
                r5->size[0] = xoffset;
                emxEnsureCapacity_int32_T(&b_st, r5, i2, &lg_emlrtRTEI);
                nz_data = r5->data;
                xoffset = 0;
                for (loop_ub = 0; loop_ub <= vstride; loop_ub++) {
                  if (L_data[loop_ub] == L_data[b_i]) {
                    nz_data[xoffset] = loop_ub;
                    xoffset++;
                  }
                }
                loop_ub = r5->size[0];
                for (i2 = 0; i2 < loop_ub; i2++) {
                  if (nz_data[i2] > L->size[0] - 1) {
                    emlrtDynamicBoundsCheckR2012b(
                        nz_data[i2], 0, L->size[0] - 1, &nb_emlrtBCI, &b_st);
                  }
                  L_data[nz_data[i2]] = b_L;
                }
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          b = (((int32_T)ind_data[k] < 1) ||
               ((int32_T)ind_data[k] > L->size[0]));
          if (b) {
            emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[k], 1, L->size[0],
                                          &db_emlrtBCI, &b_st);
          }
          if (b_L > 0U) {
            if (b_i + 1 > L->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                            &hb_emlrtBCI, &b_st);
            }
            L_data[b_i] = b_L;
          } else {
            if (b_i + 1 > L->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                            &gb_emlrtBCI, &b_st);
            }
            b_L = L_data[b_i];
            if (b_L > 0U) {
              if (b_i + 1 > L->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                              &jb_emlrtBCI, &b_st);
              }
              if (((int32_T)ind_data[k] < 1) ||
                  ((int32_T)ind_data[k] > L->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[k], 1,
                                              L->size[0], &kb_emlrtBCI, &b_st);
              }
              L_data[i2] = b_L;
            }
          }
        }
      }
      if (b_i + 1 > L->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &x_emlrtBCI,
                                      &b_st);
      }
      if (L_data[b_i] == 0U) {
        b_newLabel = newLabel + 1.0;
        i1 = nz->size[0];
        nz->size[0] = ind->size[0];
        emxEnsureCapacity_int32_T(&b_st, nz, i1, &ng_emlrtRTEI);
        nz_data = nz->data;
        loop_ub = ind->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          if (((int32_T)ind_data[i1] < 1) ||
              ((int32_T)ind_data[i1] > L->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[i1], 1, L->size[0],
                                          &cb_emlrtBCI, &b_st);
          }
          nz_data[i1] = (int32_T)ind_data[i1];
        }
        loop_ub = nz->size[0];
        if (loop_ub - 1 >= 0) {
          if (newLabel + 1.0 < 4.294967296E+9) {
            u = (uint32_T)(newLabel + 1.0);
          } else {
            u = MAX_uint32_T;
          }
        }
        for (i1 = 0; i1 < loop_ub; i1++) {
          L_data[nz_data[i1] - 1] = u;
        }
      }
      newLabel = b_newLabel;
    }
  }
  b_st.site = &jh_emlrtRSI;
  c_st.site = &fj_emlrtRSI;
  unique_vector(&c_st, L, ind);
  ind_data = ind->data;
  i = (int32_T)(real32_T)ind->size[0];
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, (real32_T)ind->size[0],
                                mxSINGLE_CLASS, (int32_T)(real32_T)ind->size[0],
                                &gb_emlrtRTEI, &st);
  for (k = 0; k < i; k++) {
    if (((int32_T)((real32_T)k + 1.0F) < 1) ||
        ((int32_T)((real32_T)k + 1.0F) > ind->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((real32_T)k + 1.0F), 1,
                                    ind->size[0], &t_emlrtBCI, &st);
    }
    vstride = L->size[0] - 1;
    for (b_i = 0; b_i <= vstride; b_i++) {
      if (L_data[b_i] == ind_data[(int32_T)((real32_T)k + 1.0F) - 1]) {
        if (b_i > L->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, L->size[0] - 1, &bb_emlrtBCI,
                                        &st);
        }
        L_data[b_i] = (uint32_T)((real32_T)k + 1.0F);
      }
    }
  }
  loop_ub = ii->size[0];
  for (i = 0; i < loop_ub; i++) {
    if ((ii_data[i] < 1) || (ii_data[i] > (int32_T)labelsSize_idx_0)) {
      emlrtDynamicBoundsCheckR2012b(ii_data[i], 1, (int32_T)labelsSize_idx_0,
                                    &w_emlrtBCI, &st);
    }
  }
  if (ii->size[0] != L->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(ii->size[0], L->size[0], &i_emlrtECI, &st);
  }
  loop_ub = L->size[0];
  for (i = 0; i < loop_ub; i++) {
    labels_data[ii_data[i] - 1] = L_data[i];
  }
  b_st.site = &kh_emlrtRSI;
  handle_matlabCodegenDestructor(&b_st, &pc);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
  numClusters = (real32_T)ind->size[0];
  emxFree_int32_T(sp, &r5);
  emxFree_int32_T(sp, &r4);
  emxFree_int32_T(sp, &r3);
  emxFree_int32_T(sp, &r2);
  emxFree_int32_T(sp, &r1);
  emxFree_int32_T(sp, &b_r);
  emxFree_real32_T(sp, &r);
  emxFree_real32_T(sp, &intensity);
  emxFree_real32_T(sp, &nv);
  emxFree_uint8_T(sp, &c);
  emxFree_real32_T(sp, &loc);
  emxFree_int32_T(sp, &nz);
  emxFree_boolean_T(sp, &tf);
  emxFree_int32_T(sp, &ii);
  emxFree_boolean_T(sp, &indices);
  emxFree_uint32_T(sp, &ind);
  emxFree_uint32_T(sp, &L);
  emxFreeStruct_pointCloud(sp, &pc);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return numClusters;
}

/* End of code generation (pcsegdist.c) */
