/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * msac.c
 *
 * Code generation for function 'msac'
 *
 */

/* Include files */
#include "msac.h"
#include "combineVectorElements.h"
#include "mod.h"
#include "polyfit.h"
#include "rand.h"
#include "removePlane_ransac.h"
#include "removePlane_ransac_data.h"
#include "removePlane_ransac_emxutil.h"
#include "removePlane_ransac_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "warning.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = {
    129,    /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    105,    /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    87,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    86,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    78,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    71,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    67,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo
    q_emlrtRSI =
        {
            24,         /* lineNo */
            "randperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo
    r_emlrtRSI =
        {
            40,          /* lineNo */
            "randkperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo
    s_emlrtRSI =
        {
            50,          /* lineNo */
            "randkperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo
    t_emlrtRSI =
        {
            57,          /* lineNo */
            "randkperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo
    u_emlrtRSI =
        {
            69,          /* lineNo */
            "randkperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    2,                                             /* lineNo */
    "@(points)polyfit(points(:,1),points(:,2),1)", /* fcnName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_ransac.m" /* pathName
                                                                          */
};

static emlrtRSInfo qb_emlrtRSI = {
    140,             /* lineNo */
    "evaluateModel", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    142,             /* lineNo */
    "evaluateModel", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    15,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

static emlrtRSInfo oc_emlrtRSI = {
    11,                  /* lineNo */
    "computeLoopNumber", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\computeLoopNumber.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    18,                  /* lineNo */
    "computeLoopNumber", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\computeLoopNumber.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    19,                  /* lineNo */
    "computeLoopNumber", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\computeLoopNumber.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m" /* pathName
                                                                          */
};

static emlrtRTEInfo h_emlrtRTEI = {
    14,      /* lineNo */
    9,       /* colNo */
    "log10", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\log10.m" /* pName
                                                                        */
};

static emlrtRTEInfo i_emlrtRTEI =
    {
        82,         /* lineNo */
        5,          /* colNo */
        "fltpower", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    k_emlrtRTEI =
        {
            20,         /* lineNo */
            19,         /* colNo */
            "randperm", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pName */
};

static emlrtRTEInfo
    l_emlrtRTEI =
        {
            23,         /* lineNo */
            19,         /* colNo */
            "randperm", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pName */
};

static emlrtDCInfo
    emlrtDCI =
        {
            31,          /* lineNo */
            19,          /* colNo */
            "randkperm", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m", /* pName */
            4      /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    70,     /* lineNo */
    30,     /* colNo */
    "",     /* aName */
    "msac", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m", /* pName */
    0                 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    70,     /* lineNo */
    30,     /* colNo */
    "msac", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m", /* pName */
    1                 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    141,             /* lineNo */
    5,               /* colNo */
    "",              /* aName */
    "evaluateModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m", /* pName */
    0                 /* checkKind */
};

static emlrtRTEInfo r_emlrtRTEI = {
    55,     /* lineNo */
    1,      /* colNo */
    "msac", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    132,    /* lineNo */
    5,      /* colNo */
    "msac", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    67,     /* lineNo */
    5,      /* colNo */
    "msac", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pName */
};

static emlrtRTEInfo
    u_emlrtRTEI =
        {
            62,         /* lineNo */
            5,          /* colNo */
            "randperm", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    70,     /* lineNo */
    5,      /* colNo */
    "msac", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pName */
};

static emlrtRTEInfo
    w_emlrtRTEI =
        {
            63,         /* lineNo */
            5,          /* colNo */
            "randperm", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pName */
};

static emlrtRTEInfo
    x_emlrtRTEI =
        {
            64,         /* lineNo */
            5,          /* colNo */
            "randperm", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pName */
};

static emlrtRTEInfo
    y_emlrtRTEI =
        {
            65,         /* lineNo */
            5,          /* colNo */
            "randperm", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    2,                    /* lineNo */
    32,                   /* colNo */
    "removePlane_ransac", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_ransac.m" /* pName
                                                                          */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    2,                    /* lineNo */
    44,                   /* colNo */
    "removePlane_ransac", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_ransac.m" /* pName
                                                                          */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    84,     /* lineNo */
    27,     /* colNo */
    "msac", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pName */
};

/* Function Definitions */
boolean_T msac(const emlrtStack *sp, const emxArray_real_T *allPoints,
               real_T params_sampleSize, real_T params_maxDistance,
               real_T bestModelParams_data[], int32_T bestModelParams_size[2],
               emxArray_boolean_T *inliers, boolean_T *reachedMaxSkipTrials)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_int32_T *val;
  emxArray_real_T *hashTbl;
  emxArray_real_T *indices;
  emxArray_real_T *link;
  emxArray_real_T *loc;
  emxArray_real_T *samplePoints;
  const real_T *allPoints_data;
  real_T bestDis;
  real_T *hashTbl_data;
  real_T *indices_data;
  real_T *link_data;
  real_T *loc_data;
  int32_T ib;
  int32_T idxTrial;
  int32_T inb;
  int32_T nleft;
  int32_T numPts;
  int32_T numTrials;
  int32_T nz;
  int32_T *val_data;
  boolean_T b;
  boolean_T isFound;
  boolean_T *inliers_data;
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
  allPoints_data = allPoints->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  numPts = allPoints->size[0];
  idxTrial = 1;
  numTrials = 1000;
  bestDis = params_maxDistance * (real_T)allPoints->size[0];
  bestModelParams_size[0] = 0;
  bestModelParams_size[1] = 0;
  ib = inliers->size[0];
  inliers->size[0] = allPoints->size[0];
  emxEnsureCapacity_boolean_T(sp, inliers, ib, &r_emlrtRTEI);
  inliers_data = inliers->data;
  nz = allPoints->size[0];
  for (ib = 0; ib < nz; ib++) {
    inliers_data[ib] = false;
  }
  if ((params_sampleSize >= 0.0) &&
      (params_sampleSize == muDoubleScalarFloor(params_sampleSize))) {
    b = true;
  } else {
    b = false;
  }
  emxInit_real_T(sp, &indices, 2, &t_emlrtRTEI);
  emxInit_real_T(sp, &samplePoints, 2, &v_emlrtRTEI);
  emxInit_real_T(sp, &hashTbl, 1, &u_emlrtRTEI);
  emxInit_real_T(sp, &link, 1, &w_emlrtRTEI);
  emxInit_int32_T(sp, &val, &x_emlrtRTEI);
  emxInit_real_T(sp, &loc, 1, &y_emlrtRTEI);
  while (idxTrial <= numTrials) {
    real_T modelParams[2];
    real_T selectedLoc;
    st.site = &p_emlrtRSI;
    if (!b) {
      emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
                                    "MATLAB:randperm:inputType",
                                    "MATLAB:randperm:inputType", 0);
    }
    if (!(params_sampleSize <= numPts)) {
      emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
                                    "MATLAB:randperm:inputKTooLarge",
                                    "MATLAB:randperm:inputKTooLarge", 0);
    }
    b_st.site = &q_emlrtRSI;
    ib = indices->size[0] * indices->size[1];
    indices->size[0] = 1;
    emxEnsureCapacity_real_T(&b_st, indices, ib, &t_emlrtRTEI);
    if (!(params_sampleSize >= 0.0)) {
      emlrtNonNegativeCheckR2012b(params_sampleSize, &emlrtDCI, &b_st);
    }
    inb = (int32_T)params_sampleSize;
    ib = indices->size[0] * indices->size[1];
    indices->size[1] = (int32_T)params_sampleSize;
    emxEnsureCapacity_real_T(&b_st, indices, ib, &t_emlrtRTEI);
    indices_data = indices->data;
    for (ib = 0; ib < inb; ib++) {
      indices_data[ib] = 0.0;
    }
    if (!(params_sampleSize == 0.0)) {
      if (params_sampleSize >= numPts) {
        indices_data[0] = 1.0;
        for (inb = 0; inb <= numPts - 2; inb++) {
          real_T j;
          c_st.site = &r_emlrtRSI;
          j = b_rand() * (((real_T)inb + 1.0) + 1.0);
          j = muDoubleScalarFloor(j);
          indices_data[inb + 1] = indices_data[(int32_T)(j + 1.0) - 1];
          indices_data[(int32_T)(j + 1.0) - 1] = ((real_T)inb + 1.0) + 1.0;
        }
      } else if (params_sampleSize >= (real_T)numPts / 4.0) {
        real_T t;
        t = 0.0;
        ib = (int32_T)((params_sampleSize - 1.0) + 1.0);
        for (nleft = 0; nleft < ib; nleft++) {
          real_T i;
          real_T j;
          real_T newEntry;
          selectedLoc = params_sampleSize - (real_T)nleft;
          i = (real_T)numPts - t;
          newEntry = selectedLoc / i;
          c_st.site = &s_emlrtRSI;
          j = b_rand();
          while (j > newEntry) {
            t++;
            i--;
            newEntry += (1.0 - newEntry) * (selectedLoc / i);
          }
          t++;
          c_st.site = &t_emlrtRSI;
          j = b_rand() * ((real_T)nleft + 1.0);
          j = muDoubleScalarFloor(j);
          indices_data[nleft] = indices_data[(int32_T)(j + 1.0) - 1];
          indices_data[(int32_T)(j + 1.0) - 1] = t;
        }
      } else {
        real_T newEntry;
        ib = hashTbl->size[0];
        hashTbl->size[0] = (int32_T)params_sampleSize;
        emxEnsureCapacity_real_T(&b_st, hashTbl, ib, &u_emlrtRTEI);
        hashTbl_data = hashTbl->data;
        ib = link->size[0];
        link->size[0] = (int32_T)params_sampleSize;
        emxEnsureCapacity_real_T(&b_st, link, ib, &w_emlrtRTEI);
        link_data = link->data;
        ib = val->size[0];
        val->size[0] = (int32_T)params_sampleSize;
        emxEnsureCapacity_int32_T(&b_st, val, ib, &x_emlrtRTEI);
        val_data = val->data;
        ib = loc->size[0];
        loc->size[0] = (int32_T)params_sampleSize;
        emxEnsureCapacity_real_T(&b_st, loc, ib, &y_emlrtRTEI);
        loc_data = loc->data;
        for (ib = 0; ib < inb; ib++) {
          hashTbl_data[ib] = 0.0;
          link_data[ib] = 0.0;
          val_data[ib] = 0;
          loc_data[ib] = 0.0;
        }
        newEntry = 1.0;
        for (nleft = 0; nleft < inb; nleft++) {
          real_T i;
          real_T j;
          nz = (numPts - nleft) - 1;
          c_st.site = &u_emlrtRSI;
          selectedLoc = b_rand() * ((real_T)nz + 1.0);
          selectedLoc = muDoubleScalarFloor(selectedLoc);
          i = b_mod(selectedLoc, params_sampleSize) + 1.0;
          j = hashTbl_data[(int32_T)i - 1];
          while ((j > 0.0) && (loc_data[(int32_T)j - 1] != selectedLoc)) {
            j = link_data[(int32_T)j - 1];
          }
          if (j > 0.0) {
            indices_data[nleft] = (real_T)val_data[(int32_T)j - 1] + 1.0;
          } else {
            indices_data[nleft] = selectedLoc + 1.0;
            j = newEntry;
            newEntry++;
            loc_data[(int32_T)j - 1] = selectedLoc;
            link_data[(int32_T)j - 1] = hashTbl_data[(int32_T)i - 1];
            hashTbl_data[(int32_T)i - 1] = j;
          }
          if ((real_T)nleft + 1.0 < params_sampleSize) {
            selectedLoc =
                hashTbl_data[(int32_T)(b_mod(nz, params_sampleSize) + 1.0) - 1];
            while ((selectedLoc > 0.0) &&
                   (loc_data[(int32_T)selectedLoc - 1] != nz)) {
              selectedLoc = link_data[(int32_T)selectedLoc - 1];
            }
            if (selectedLoc > 0.0) {
              val_data[(int32_T)j - 1] = val_data[(int32_T)selectedLoc - 1];
            } else {
              val_data[(int32_T)j - 1] = nz;
            }
          }
        }
      }
    }
    ib = samplePoints->size[0] * samplePoints->size[1];
    samplePoints->size[0] = indices->size[1];
    samplePoints->size[1] = 2;
    emxEnsureCapacity_real_T(sp, samplePoints, ib, &v_emlrtRTEI);
    loc_data = samplePoints->data;
    nz = indices->size[1];
    for (ib = 0; ib < 2; ib++) {
      for (nleft = 0; nleft < nz; nleft++) {
        inb = (int32_T)indices_data[nleft];
        if (indices_data[nleft] != inb) {
          emlrtIntegerCheckR2012b(indices_data[nleft], &b_emlrtDCI,
                                  (emlrtConstCTX)sp);
        }
        if ((inb < 1) || (inb > allPoints->size[0])) {
          emlrtDynamicBoundsCheckR2012b(inb, 1, allPoints->size[0], &emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        loc_data[nleft + samplePoints->size[0] * ib] =
            allPoints_data[(inb + allPoints->size[0] * ib) - 1];
      }
    }
    st.site = &o_emlrtRSI;
    ib = hashTbl->size[0];
    hashTbl->size[0] = indices->size[1];
    emxEnsureCapacity_real_T(&st, hashTbl, ib, &ab_emlrtRTEI);
    hashTbl_data = hashTbl->data;
    nz = indices->size[1];
    ib = link->size[0];
    link->size[0] = indices->size[1];
    emxEnsureCapacity_real_T(&st, link, ib, &bb_emlrtRTEI);
    link_data = link->data;
    for (ib = 0; ib < nz; ib++) {
      hashTbl_data[ib] = loc_data[ib];
      link_data[ib] = loc_data[ib + samplePoints->size[0]];
    }
    b_st.site = &w_emlrtRSI;
    polyfit(&b_st, hashTbl, link, modelParams);
    st.site = &n_emlrtRSI;
    b_st.site = &qb_emlrtRSI;
    removePlane_ransac_anonFcn2(&b_st, modelParams, allPoints, hashTbl);
    hashTbl_data = hashTbl->data;
    nz = hashTbl->size[0] - 1;
    for (inb = 0; inb <= nz; inb++) {
      if (hashTbl_data[inb] > params_maxDistance) {
        if (inb > hashTbl->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(inb, 0, hashTbl->size[0] - 1,
                                        &b_emlrtBCI, &st);
        }
        hashTbl_data[inb] = params_maxDistance;
      }
    }
    b_st.site = &rb_emlrtRSI;
    c_st.site = &ub_emlrtRSI;
    d_st.site = &vb_emlrtRSI;
    e_st.site = &wb_emlrtRSI;
    if (hashTbl->size[0] == 0) {
      selectedLoc = 0.0;
    } else {
      f_st.site = &ac_emlrtRSI;
      g_st.site = &bc_emlrtRSI;
      if (hashTbl->size[0] < 4096) {
        h_st.site = &cc_emlrtRSI;
        selectedLoc = sumColumnB(&h_st, hashTbl, hashTbl->size[0]);
      } else {
        nz = (int32_T)((uint32_T)hashTbl->size[0] >> 12);
        inb = nz << 12;
        nleft = hashTbl->size[0] - inb;
        selectedLoc = sumColumnB4(hashTbl, 1);
        for (ib = 2; ib <= nz; ib++) {
          selectedLoc += sumColumnB4(hashTbl, ((ib - 1) << 12) + 1);
        }
        if (nleft > 0) {
          h_st.site = &ec_emlrtRSI;
          selectedLoc += b_sumColumnB(&h_st, hashTbl, nleft, inb + 1);
        }
      }
    }
    if (selectedLoc < bestDis) {
      bestDis = selectedLoc;
      ib = inliers->size[0];
      inliers->size[0] = hashTbl->size[0];
      emxEnsureCapacity_boolean_T(sp, inliers, ib, &cb_emlrtRTEI);
      inliers_data = inliers->data;
      nz = hashTbl->size[0];
      for (ib = 0; ib < nz; ib++) {
        inliers_data[ib] = (hashTbl_data[ib] < params_maxDistance);
      }
      bestModelParams_size[0] = 1;
      bestModelParams_size[1] = 2;
      bestModelParams_data[0] = modelParams[0];
      bestModelParams_data[1] = modelParams[1];
      st.site = &m_emlrtRSI;
      b_st.site = &lc_emlrtRSI;
      c_st.site = &vb_emlrtRSI;
      nz = combineVectorElements(&c_st, inliers);
      st.site = &l_emlrtRSI;
      b_st.site = &oc_emlrtRSI;
      selectedLoc = (real_T)nz / (real_T)numPts;
      c_st.site = &rc_emlrtRSI;
      d_st.site = &tb_emlrtRSI;
      if ((selectedLoc < 0.0) &&
          (muDoubleScalarFloor(params_sampleSize) != params_sampleSize)) {
        emlrtErrorWithMessageIdR2018a(&d_st, &i_emlrtRTEI,
                                      "Coder:toolbox:power_domainError",
                                      "Coder:toolbox:power_domainError", 0);
      }
      selectedLoc = muDoubleScalarPower(selectedLoc, params_sampleSize);
      if (selectedLoc < 2.2204460492503131E-16) {
        nz = MAX_int32_T;
      } else {
        b_st.site = &pc_emlrtRSI;
        b_st.site = &qc_emlrtRSI;
        if (1.0 - selectedLoc < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &h_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 5, "log10");
        }
        selectedLoc = muDoubleScalarCeil(
            -1.9999999999999996 / muDoubleScalarLog10(1.0 - selectedLoc));
        if (selectedLoc < 2.147483648E+9) {
          nz = (int32_T)selectedLoc;
        } else if (selectedLoc >= 2.147483648E+9) {
          nz = MAX_int32_T;
        } else {
          nz = 0;
        }
      }
      numTrials = muIntScalarMin_sint32(numTrials, nz);
    }
    idxTrial++;
  }
  emxFree_real_T(sp, &loc);
  emxFree_int32_T(sp, &val);
  emxFree_real_T(sp, &link);
  emxFree_real_T(sp, &hashTbl);
  emxFree_real_T(sp, &samplePoints);
  emxFree_real_T(sp, &indices);
  if (inliers->size[0] != 0) {
    st.site = &k_emlrtRSI;
    b_st.site = &lc_emlrtRSI;
    c_st.site = &vb_emlrtRSI;
    nz = combineVectorElements(&c_st, inliers);
    if (nz >= params_sampleSize) {
      isFound = true;
    } else {
      isFound = false;
    }
  } else {
    isFound = false;
  }
  if (isFound) {
    if (numTrials >= 1000) {
      st.site = &j_emlrtRSI;
      c_warning(&st);
    }
  } else {
    ib = inliers->size[0];
    inliers->size[0] = allPoints->size[0];
    emxEnsureCapacity_boolean_T(sp, inliers, ib, &s_emlrtRTEI);
    inliers_data = inliers->data;
    nz = allPoints->size[0];
    for (ib = 0; ib < nz; ib++) {
      inliers_data[ib] = false;
    }
  }
  *reachedMaxSkipTrials = false;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return isFound;
}

/* End of code generation (msac.c) */
