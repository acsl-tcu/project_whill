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
#include "handle.h"
#include "pointCloud.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"
#include "unique.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo hf_emlrtRSI =
    {
        11,          /* lineNo */
        "pcsegdist", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo if_emlrtRSI =
    {
        14,          /* lineNo */
        "pcsegdist", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo jf_emlrtRSI =
    {
        27,          /* lineNo */
        "pcsegdist", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo kf_emlrtRSI =
    {
        28,          /* lineNo */
        "pcsegdist", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo lf_emlrtRSI =
    {
        45,            /* lineNo */
        "parseInputs", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo mf_emlrtRSI =
    {
        102,                        /* lineNo */
        "validateNumClusterPoints", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo nf_emlrtRSI =
    {
        138,             /* lineNo */
        "pcsegdistImpl", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo of_emlrtRSI =
    {
        153,             /* lineNo */
        "pcsegdistImpl", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo pf_emlrtRSI =
    {
        160,             /* lineNo */
        "pcsegdistImpl", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo qf_emlrtRSI =
    {
        161,             /* lineNo */
        "pcsegdistImpl", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo rf_emlrtRSI =
    {
        166,             /* lineNo */
        "pcsegdistImpl", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo sf_emlrtRSI =
    {
        171,             /* lineNo */
        "pcsegdistImpl", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo tf_emlrtRSI =
    {
        180,             /* lineNo */
        "pcsegdistImpl", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo uf_emlrtRSI =
    {
        136,             /* lineNo */
        "pcsegdistImpl", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pathName
                                                                       */
};

static emlrtRSInfo fh_emlrtRSI = {
    48,       /* lineNo */
    "unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtBCInfo i_emlrtBCI =
    {
        -1,              /* iFirst */
        -1,              /* iLast */
        160,             /* lineNo */
        53,              /* colNo */
        "",              /* aName */
        "pcsegdistImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI =
    {
        -1,              /* iFirst */
        -1,              /* iLast */
        175,             /* lineNo */
        29,              /* colNo */
        "",              /* aName */
        "pcsegdistImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtECInfo d_emlrtECI =
    {
        -1,              /* nDims */
        179,             /* lineNo */
        1,               /* colNo */
        "pcsegdistImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI =
    {
        113,                        /* lineNo */
        9,                          /* colNo */
        "validateNumClusterPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtBCInfo k_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        203,           /* lineNo */
        13,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        210,           /* lineNo */
        20,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI =
    {
        -1,                          /* iFirst */
        -1,                          /* iLast */
        190,                         /* lineNo */
        29,                          /* colNo */
        "",                          /* aName */
        "filterClustersByNumPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI =
    {
        -1,                          /* iFirst */
        -1,                          /* iLast */
        194,                         /* lineNo */
        29,                          /* colNo */
        "",                          /* aName */
        "filterClustersByNumPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    13,                   /* lineNo */
    37,                   /* colNo */
    "validateincreasing", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateincreasing.m" /* pName */
};

static emlrtBCInfo o_emlrtBCI =
    {
        -1,              /* iFirst */
        -1,              /* iLast */
        155,             /* lineNo */
        14,              /* colNo */
        "",              /* aName */
        "pcsegdistImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo p_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        225,           /* lineNo */
        6,             /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo q_emlrtBCI =
    {
        -1,                          /* iFirst */
        -1,                          /* iLast */
        187,                         /* lineNo */
        39,                          /* colNo */
        "",                          /* aName */
        "filterClustersByNumPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo r_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        206,           /* lineNo */
        10,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo s_emlrtBCI =
    {
        -1,              /* iFirst */
        -1,              /* iLast */
        179,             /* lineNo */
        8,               /* colNo */
        "",              /* aName */
        "pcsegdistImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo t_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        206,           /* lineNo */
        22,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo u_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        227,           /* lineNo */
        7,             /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo v_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        216,           /* lineNo */
        14,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo w_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        207,           /* lineNo */
        14,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo x_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        207,           /* lineNo */
        21,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo y_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        218,           /* lineNo */
        18,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        217,           /* lineNo */
        15,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        209,           /* lineNo */
        25,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI =
    {
        -1,              /* iFirst */
        -1,              /* iLast */
        175,             /* lineNo */
        11,              /* colNo */
        "",              /* aName */
        "pcsegdistImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo db_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        219,           /* lineNo */
        22,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        219,           /* lineNo */
        15,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        208,           /* lineNo */
        28,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI =
    {
        -1,                          /* iFirst */
        -1,                          /* iLast */
        190,                         /* lineNo */
        11,                          /* colNo */
        "",                          /* aName */
        "filterClustersByNumPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI =
    {
        -1,                          /* iFirst */
        -1,                          /* iLast */
        194,                         /* lineNo */
        11,                          /* colNo */
        "",                          /* aName */
        "filterClustersByNumPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        208,           /* lineNo */
        13,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI =
    {
        -1,            /* iFirst */
        -1,            /* iLast */
        210,           /* lineNo */
        13,            /* colNo */
        "",            /* aName */
        "labelPoints", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtRTEInfo fd_emlrtRTEI =
    {
        132,         /* lineNo */
        1,           /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo gd_emlrtRTEI =
    {
        138,         /* lineNo */
        1,           /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo hd_emlrtRTEI =
    {
        179,         /* lineNo */
        8,           /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo id_emlrtRTEI =
    {
        187,         /* lineNo */
        21,          /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo jd_emlrtRTEI =
    {
        227,         /* lineNo */
        7,           /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo kd_emlrtRTEI =
    {
        1,           /* lineNo */
        34,          /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo ld_emlrtRTEI =
    {
        136,         /* lineNo */
        2,           /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo md_emlrtRTEI =
    {
        149,         /* lineNo */
        9,           /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo nd_emlrtRTEI =
    {
        227,         /* lineNo */
        5,           /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo od_emlrtRTEI =
    {
        208,         /* lineNo */
        15,          /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

static emlrtRTEInfo pd_emlrtRTEI =
    {
        210,         /* lineNo */
        15,          /* colNo */
        "pcsegdist", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\pcsegdist.m" /* pName
                                                                       */
};

/* Function Definitions */
real_T pcsegdist(const emlrtStack *sp, pointCloud *ptCloud, real_T minDistance,
                 const real_T varargin_2[2], emxArray_uint32_T *labels)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_boolean_T *s;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_real_T *validIndices;
  emxArray_uint32_T *L;
  emxArray_uint32_T *ind;
  pointCloud pc;
  pointCloud *b_pc;
  real_T newLabel;
  real_T numClusters;
  real_T *validIndices_data;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T loop_ub_tmp;
  int32_T obj_size_idx_0;
  int32_T obj_size_idx_1;
  int32_T *r3;
  uint32_T b_L;
  uint32_T u;
  uint32_T *L_data;
  uint32_T *ind_data;
  uint32_T *labels_data;
  boolean_T exitg1;
  boolean_T n;
  boolean_T *s_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud1(sp, &pc, &ld_emlrtRTEI);
  emxInit_uint32_T(sp, &L, 1, &gd_emlrtRTEI);
  emxInit_uint32_T(sp, &ind, 1, &md_emlrtRTEI);
  emxInit_real_T(sp, &validIndices, 1, &kd_emlrtRTEI);
  emxInit_int32_T(sp, &r, 1, &nd_emlrtRTEI);
  emxInit_boolean_T(sp, &s, 1, &id_emlrtRTEI);
  emxInit_int32_T(sp, &r1, 1, &od_emlrtRTEI);
  emxInit_int32_T(sp, &r2, 1, &pd_emlrtRTEI);
  st.site = &hf_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  c_st.site = &tc_emlrtRSI;
  n = (ptCloud->PointCloudArrayData->size[0] *
           ptCloud->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:pcsegdist:expectedScalar", 3, 4, 7, "ptCloud");
  }
  st.site = &if_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (muDoubleScalarIsNaN(minDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:pcsegdist:expectedNonNaN", 3, 4, 11, "minDistance");
  }
  b_st.site = &ib_emlrtRSI;
  if (minDistance <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &bb_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:pcsegdist:expectedPositive", 3, 4, 11, "minDistance");
  }
  b_st.site = &ib_emlrtRSI;
  if (muDoubleScalarIsInf(minDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:pcsegdist:expectedFinite", 3, 4, 11, "minDistance");
  }
  st.site = &jf_emlrtRSI;
  b_st.site = &lf_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  d_st.site = &ib_emlrtRSI;
  n = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!muDoubleScalarIsNaN(varargin_2[k])) {
      k++;
    } else {
      n = false;
      exitg1 = true;
    }
  }
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:pcsegdist:expectedNonNaN", 3, 4, 16, "NumClusterPoints");
  }
  d_st.site = &ib_emlrtRSI;
  n = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_2[k] <= 0.0)) {
      k++;
    } else {
      n = false;
      exitg1 = true;
    }
  }
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &bb_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:pcsegdist:expectedPositive", 3, 4, 16, "NumClusterPoints");
  }
  d_st.site = &ib_emlrtRSI;
  if (!(varargin_2[0] < varargin_2[1])) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &eb_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedIncreasing",
        "MATLAB:pcsegdist:expectedIncreasing", 3, 4, 16, "NumClusterPoints");
  }
  if ((!(varargin_2[0] == muDoubleScalarFloor(varargin_2[0]))) ||
      ((!muDoubleScalarIsInf(varargin_2[1])) &&
       (!(varargin_2[1] == muDoubleScalarFloor(varargin_2[1]))))) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &db_emlrtRTEI, "vision:pointcloud:mustBeIntegerNumClusterPoints",
        "vision:pointcloud:mustBeIntegerNumClusterPoints", 0);
  }
  st.site = &kf_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, &pc,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  pc.matlabCodegenIsDeleted = true;
  obj_size_idx_0 = ptCloud->Location->size[0];
  obj_size_idx_1 = ptCloud->Location->size[1];
  i = labels->size[0] * labels->size[1];
  labels->size[0] = obj_size_idx_0;
  labels->size[1] = obj_size_idx_1;
  emxEnsureCapacity_uint32_T(&st, labels, i, &fd_emlrtRTEI);
  labels_data = labels->data;
  loop_ub_tmp = obj_size_idx_0 * obj_size_idx_1;
  for (i = 0; i < loop_ub_tmp; i++) {
    labels_data[i] = 0U;
  }
  b_st.site = &uf_emlrtRSI;
  pointCloud_removeInvalidPoints(&b_st, ptCloud, &pc, &b_pc, validIndices);
  validIndices_data = validIndices->data;
  b_st.site = &nf_emlrtRSI;
  obj_size_idx_0 = pc.Location->size[0];
  i = L->size[0];
  L->size[0] = obj_size_idx_0;
  emxEnsureCapacity_uint32_T(&st, L, i, &gd_emlrtRTEI);
  L_data = L->data;
  for (i = 0; i < obj_size_idx_0; i++) {
    L_data[i] = 0U;
  }
  newLabel = 0.0;
  b_st.site = &of_emlrtRSI;
  i = pc.Location->size[0] - 1;
  for (b_i = 0; b_i <= i; b_i++) {
    if (b_i + 1 > L->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &o_emlrtBCI, &st);
    }
    if (L_data[b_i] == 0U) {
      real_T c_pc[3];
      real_T b_newLabel;
      i1 = pc.Location->size[0];
      if (b_i + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i1, &i_emlrtBCI, &st);
      }
      c_pc[0] = pc.Location->data[b_i];
      c_pc[1] = pc.Location->data[b_i + pc.Location->size[0]];
      c_pc[2] = pc.Location->data[b_i + pc.Location->size[0] * 2];
      b_st.site = &pf_emlrtRSI;
      c_pointCloud_findNeighborsInRad(&b_st, &pc, c_pc, minDistance, ind);
      ind_data = ind->data;
      b_st.site = &qf_emlrtRSI;
      b_newLabel = newLabel;
      i1 = ind->size[0];
      for (k = 0; k < i1; k++) {
        boolean_T guard1;
        if (k + 1 > ind->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, ind->size[0], &k_emlrtBCI,
                                        &b_st);
        }
        if (((int32_T)ind_data[k] < 1) || ((int32_T)ind_data[k] > L->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[k], 1, L->size[0],
                                        &r_emlrtBCI, &b_st);
        }
        c_i = (int32_T)ind_data[k] - 1;
        b_L = L_data[c_i];
        guard1 = false;
        if (b_L > 0U) {
          uint32_T c_L;
          if (b_i + 1 > L->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &t_emlrtBCI,
                                          &b_st);
          }
          c_L = L_data[b_i];
          if (c_L > 0U) {
            n = (((int32_T)ind_data[k] < 1) ||
                 ((int32_T)ind_data[k] > L->size[0]));
            if (n) {
              emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[k], 1, L->size[0],
                                            &w_emlrtBCI, &b_st);
            }
            if (b_i + 1 > L->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &x_emlrtBCI,
                                            &b_st);
            }
            if (b_L > c_L) {
              obj_size_idx_1 = L->size[0] - 1;
              obj_size_idx_0 = 0;
              for (c_i = 0; c_i <= obj_size_idx_1; c_i++) {
                if (L_data[c_i] == b_L) {
                  obj_size_idx_0++;
                }
              }
              c_i = r1->size[0];
              r1->size[0] = obj_size_idx_0;
              emxEnsureCapacity_int32_T(&b_st, r1, c_i, &kd_emlrtRTEI);
              r3 = r1->data;
              obj_size_idx_0 = 0;
              for (c_i = 0; c_i <= obj_size_idx_1; c_i++) {
                if (L_data[c_i] == b_L) {
                  r3[obj_size_idx_0] = c_i;
                  obj_size_idx_0++;
                }
              }
              if (b_i + 1 > L->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                              &fb_emlrtBCI, &b_st);
              }
              obj_size_idx_0 = r1->size[0];
              for (c_i = 0; c_i < obj_size_idx_0; c_i++) {
                if (r3[c_i] > L->size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(r3[c_i], 0, L->size[0] - 1,
                                                &ib_emlrtBCI, &b_st);
                }
                L_data[r3[c_i]] = c_L;
              }
            } else {
              if (b_i + 1 > L->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                              &bb_emlrtBCI, &b_st);
              }
              if (b_L < c_L) {
                if (b_i + 1 > L->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                                &l_emlrtBCI, &b_st);
                }
                obj_size_idx_1 = L->size[0] - 1;
                obj_size_idx_0 = 0;
                for (c_i = 0; c_i <= obj_size_idx_1; c_i++) {
                  if (L_data[c_i] == L_data[b_i]) {
                    obj_size_idx_0++;
                  }
                }
                c_i = r2->size[0];
                r2->size[0] = obj_size_idx_0;
                emxEnsureCapacity_int32_T(&b_st, r2, c_i, &kd_emlrtRTEI);
                r3 = r2->data;
                obj_size_idx_0 = 0;
                for (c_i = 0; c_i <= obj_size_idx_1; c_i++) {
                  if (L_data[c_i] == L_data[b_i]) {
                    r3[obj_size_idx_0] = c_i;
                    obj_size_idx_0++;
                  }
                }
                obj_size_idx_0 = r2->size[0];
                for (c_i = 0; c_i < obj_size_idx_0; c_i++) {
                  if (r3[c_i] > L->size[0] - 1) {
                    emlrtDynamicBoundsCheckR2012b(r3[c_i], 0, L->size[0] - 1,
                                                  &jb_emlrtBCI, &b_st);
                  }
                  L_data[r3[c_i]] = b_L;
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
          n = (((int32_T)ind_data[k] < 1) ||
               ((int32_T)ind_data[k] > L->size[0]));
          if (n) {
            emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[k], 1, L->size[0],
                                          &v_emlrtBCI, &b_st);
          }
          if (b_L > 0U) {
            if (b_i + 1 > L->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                            &ab_emlrtBCI, &b_st);
            }
            L_data[b_i] = b_L;
          } else {
            if (b_i + 1 > L->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &y_emlrtBCI,
                                            &b_st);
            }
            b_L = L_data[b_i];
            if (b_L > 0U) {
              if (b_i + 1 > L->size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0],
                                              &db_emlrtBCI, &b_st);
              }
              if (((int32_T)ind_data[k] < 1) ||
                  ((int32_T)ind_data[k] > L->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[k], 1,
                                              L->size[0], &eb_emlrtBCI, &b_st);
              }
              L_data[c_i] = b_L;
            }
          }
        }
      }
      if (b_i + 1 > L->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L->size[0], &p_emlrtBCI,
                                      &b_st);
      }
      if (L_data[b_i] == 0U) {
        b_newLabel = newLabel + 1.0;
        i1 = r->size[0];
        r->size[0] = ind->size[0];
        emxEnsureCapacity_int32_T(&b_st, r, i1, &jd_emlrtRTEI);
        r3 = r->data;
        obj_size_idx_0 = ind->size[0];
        for (i1 = 0; i1 < obj_size_idx_0; i1++) {
          if (((int32_T)ind_data[i1] < 1) ||
              ((int32_T)ind_data[i1] > L->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)ind_data[i1], 1, L->size[0],
                                          &u_emlrtBCI, &b_st);
          }
          r3[i1] = (int32_T)ind_data[i1];
        }
        obj_size_idx_0 = r->size[0];
        if (obj_size_idx_0 - 1 >= 0) {
          if (newLabel + 1.0 < 4.294967296E+9) {
            u = (uint32_T)(newLabel + 1.0);
          } else {
            u = MAX_uint32_T;
          }
        }
        for (i1 = 0; i1 < obj_size_idx_0; i1++) {
          L_data[r3[i1] - 1] = u;
        }
      }
      newLabel = b_newLabel;
    }
  }
  b_st.site = &rf_emlrtRSI;
  c_st.site = &fh_emlrtRSI;
  unique_vector(&c_st, L, ind);
  ind_data = ind->data;
  if ((varargin_2[0] > 1.0) || (!muDoubleScalarIsInf(varargin_2[1]))) {
    b_st.site = &sf_emlrtRSI;
    numClusters = 0.0;
    i = ind->size[0];
    for (c_i = 0; c_i < i; c_i++) {
      if (c_i + 1 > ind->size[0]) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, ind->size[0], &q_emlrtBCI,
                                      &b_st);
      }
      obj_size_idx_0 = L->size[0];
      i1 = s->size[0];
      s->size[0] = L->size[0];
      emxEnsureCapacity_boolean_T(&b_st, s, i1, &id_emlrtRTEI);
      s_data = s->data;
      for (i1 = 0; i1 < obj_size_idx_0; i1++) {
        s_data[i1] = (L_data[i1] == ind_data[c_i]);
      }
      obj_size_idx_0 = 0;
      i1 = s->size[0];
      for (k = 0; k < i1; k++) {
        if (s_data[k]) {
          obj_size_idx_0++;
        }
      }
      if ((obj_size_idx_0 < varargin_2[0]) ||
          (obj_size_idx_0 > varargin_2[1])) {
        if (c_i + 1 > ind->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, ind->size[0], &m_emlrtBCI,
                                        &b_st);
        }
        obj_size_idx_1 = L->size[0] - 1;
        for (b_i = 0; b_i <= obj_size_idx_1; b_i++) {
          if (L_data[b_i] == ind_data[c_i]) {
            if (b_i > L->size[0] - 1) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, L->size[0] - 1,
                                            &gb_emlrtBCI, &b_st);
            }
            L_data[b_i] = 0U;
          }
        }
      } else {
        numClusters++;
        if (c_i + 1 > ind->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, ind->size[0], &n_emlrtBCI,
                                        &b_st);
        }
        obj_size_idx_0 = L->size[0] - 1;
        for (b_i = 0; b_i <= obj_size_idx_0; b_i++) {
          if (L_data[b_i] == ind_data[c_i]) {
            if (b_i > obj_size_idx_0) {
              emlrtDynamicBoundsCheckR2012b(b_i, 0, obj_size_idx_0,
                                            &hb_emlrtBCI, &b_st);
            }
            if (numClusters < 4.294967296E+9) {
              b_L = (uint32_T)numClusters;
            } else {
              b_L = MAX_uint32_T;
            }
            L_data[b_i] = b_L;
          }
        }
      }
    }
  } else {
    numClusters = ind->size[0];
    i = ind->size[0];
    for (k = 0; k < i; k++) {
      if (k + 1 > ind->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, ind->size[0], &j_emlrtBCI, &st);
      }
      obj_size_idx_1 = L->size[0] - 1;
      for (b_i = 0; b_i <= obj_size_idx_1; b_i++) {
        if (L_data[b_i] == ind_data[k]) {
          if (b_i > L->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, L->size[0] - 1, &cb_emlrtBCI,
                                          &st);
          }
          L_data[b_i] = (uint32_T)(k + 1);
        }
      }
    }
  }
  i = r->size[0];
  r->size[0] = validIndices->size[0];
  emxEnsureCapacity_int32_T(&st, r, i, &hd_emlrtRTEI);
  r3 = r->data;
  obj_size_idx_0 = validIndices->size[0];
  for (i = 0; i < obj_size_idx_0; i++) {
    i1 = (int32_T)validIndices_data[i];
    if ((i1 < 1) || (i1 > loop_ub_tmp)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, loop_ub_tmp, &s_emlrtBCI, &st);
    }
    r3[i] = i1;
  }
  if (r->size[0] != L->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(r->size[0], L->size[0], &d_emlrtECI, &st);
  }
  obj_size_idx_0 = L->size[0];
  for (i = 0; i < obj_size_idx_0; i++) {
    labels_data[r3[i] - 1] = L_data[i];
  }
  b_st.site = &tf_emlrtRSI;
  handle_matlabCodegenDestructor(&b_st, &pc);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
  emxFree_int32_T(sp, &r2);
  emxFree_int32_T(sp, &r1);
  emxFree_boolean_T(sp, &s);
  emxFree_int32_T(sp, &r);
  emxFree_real_T(sp, &validIndices);
  emxFree_uint32_T(sp, &ind);
  emxFree_uint32_T(sp, &L);
  emxFreeStruct_pointCloud(sp, &pc);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return numClusters;
}

/* End of code generation (pcsegdist.c) */
