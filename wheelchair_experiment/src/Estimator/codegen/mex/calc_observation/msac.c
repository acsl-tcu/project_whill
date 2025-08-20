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
#include "calc_observation_data.h"
#include "calc_observation_emxutil.h"
#include "calc_observation_internal_types.h"
#include "calc_observation_types.h"
#include "combineVectorElements.h"
#include "mod.h"
#include "mrdivide_helper.h"
#include "pcfitellipse.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo jd_emlrtRSI = {
    67,     /* lineNo */
    "msac", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    71,     /* lineNo */
    "msac", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    74,     /* lineNo */
    "msac", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    78,     /* lineNo */
    "msac", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    86,     /* lineNo */
    "msac", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo od_emlrtRSI = {
    87,     /* lineNo */
    "msac", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    104,    /* lineNo */
    "msac", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo qd_emlrtRSI = {
    105,    /* lineNo */
    "msac", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    129,    /* lineNo */
    "msac", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI = {
    24,         /* lineNo */
    "randperm", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pathName
                                                                          */
};

static emlrtRSInfo td_emlrtRSI = {
    40,          /* lineNo */
    "randkperm", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pathName
                                                                          */
};

static emlrtRSInfo ud_emlrtRSI = {
    50,          /* lineNo */
    "randkperm", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pathName
                                                                          */
};

static emlrtRSInfo vd_emlrtRSI = {
    57,          /* lineNo */
    "randkperm", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pathName
                                                                          */
};

static emlrtRSInfo wd_emlrtRSI = {
    69,          /* lineNo */
    "randkperm", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pathName
                                                                          */
};

static emlrtRSInfo il_emlrtRSI = {
    140,             /* lineNo */
    "evaluateModel", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo jl_emlrtRSI = {
    142,             /* lineNo */
    "evaluateModel", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pathName */
};

static emlrtRSInfo ol_emlrtRSI = {
    15,    /* lineNo */
    "sum", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                     */
};

static emlrtRSInfo rl_emlrtRSI = {
    11,                  /* lineNo */
    "computeLoopNumber", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "computeLoopNumber.m" /* pathName */
};

static emlrtRSInfo sl_emlrtRSI = {
    18,                  /* lineNo */
    "computeLoopNumber", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "computeLoopNumber.m" /* pathName */
};

static emlrtRSInfo tl_emlrtRSI = {
    19,                  /* lineNo */
    "computeLoopNumber", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "computeLoopNumber.m" /* pathName */
};

static emlrtRSInfo ul_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName
                                                                       */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    141,             /* lineNo */
    5,               /* colNo */
    "",              /* aName */
    "evaluateModel", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m", /* pName */
    0         /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    70,     /* lineNo */
    30,     /* colNo */
    "msac", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m", /* pName */
    1         /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    70,     /* lineNo */
    30,     /* colNo */
    "",     /* aName */
    "msac", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m", /* pName */
    0         /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI = {
    23,         /* lineNo */
    19,         /* colNo */
    "randperm", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pName
                                                                          */
};

static emlrtRTEInfo t_emlrtRTEI = {
    20,         /* lineNo */
    19,         /* colNo */
    "randperm", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pName
                                                                          */
};

static emlrtRTEInfo u_emlrtRTEI = {
    82,                                                           /* lineNo */
    5,                                                            /* colNo */
    "fltpower",                                                   /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/power.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    14,                                                             /* lineNo */
    9,                                                              /* colNo */
    "log10",                                                        /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elfun/log10.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    55,     /* lineNo */
    1,      /* colNo */
    "msac", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    67,     /* lineNo */
    5,      /* colNo */
    "msac", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    132,    /* lineNo */
    5,      /* colNo */
    "msac", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    62,         /* lineNo */
    15,         /* colNo */
    "randperm", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pName
                                                                          */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    70,     /* lineNo */
    5,      /* colNo */
    "msac", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    63,         /* lineNo */
    5,          /* colNo */
    "randperm", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pName
                                                                          */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    64,         /* lineNo */
    5,          /* colNo */
    "randperm", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pName
                                                                          */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    65,         /* lineNo */
    5,          /* colNo */
    "randperm", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pName
                                                                          */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    84,     /* lineNo */
    27,     /* colNo */
    "msac", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/vision/vision/+vision/+internal/+ransac/"
    "msac.m" /* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    62,         /* lineNo */
    5,          /* colNo */
    "randperm", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/randperm.m" /* pName
                                                                          */
};

/* Function Definitions */
boolean_T msac(const emlrtStack *sp, const emxArray_real_T *allPoints,
               real_T params_sampleSize, real_T params_maxDistance,
               real_T params_confidence, real_T params_maxNumTrials,
               real_T params_maxSkipTrials,
               const real_T funcs_fitFunc_workspace_a0[5],
               const real_T funcs_fitFunc_workspace_A[5],
               real_T funcs_fitFunc_workspace_B,
               const real_T funcs_fitFunc_workspace_lb[5],
               const real_T funcs_fitFunc_workspace_ub[5],
               const real_T c_funcs_fitFunc_workspace_nonlc[2],
               real_T d_funcs_fitFunc_workspace_nonlc,
               real_T e_funcs_fitFunc_workspace_nonlc,
               real_T f_funcs_fitFunc_workspace_nonlc,
               const e_struct_T *funcs_checkFunc_workspace,
               real_T bestModelParams_data[], int32_T bestModelParams_size[2],
               emxArray_boolean_T *inliers, boolean_T *reachedMaxSkipTrials)
{
  anonymous_function expl_temp;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_int32_T *val;
  emxArray_real_T *hashTbl;
  emxArray_real_T *indices;
  emxArray_real_T *link;
  emxArray_real_T *loc;
  emxArray_real_T *samplePoints;
  const real_T *allPoints_data;
  real_T bestDis;
  real_T d;
  real_T skipTrials;
  real_T *hashTbl_data;
  real_T *indices_data;
  real_T *link_data;
  real_T *loc_data;
  int32_T i;
  int32_T m;
  int32_T numPts_tmp;
  int32_T numTrials;
  int32_T nz;
  int32_T *val_data;
  uint32_T idxTrial;
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
  allPoints_data = allPoints->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  numPts_tmp = allPoints->size[0];
  idxTrial = 1U;
  d = muDoubleScalarRound(params_maxNumTrials);
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      numTrials = (int32_T)d;
    } else {
      numTrials = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    numTrials = MAX_int32_T;
  } else {
    numTrials = 0;
  }
  bestDis = params_maxDistance * (real_T)allPoints->size[0];
  bestModelParams_size[0] = 0;
  bestModelParams_size[1] = 0;
  skipTrials = 0.0;
  i = inliers->size[0];
  inliers->size[0] = allPoints->size[0];
  emxEnsureCapacity_boolean_T(sp, inliers, i, &hc_emlrtRTEI);
  inliers_data = inliers->data;
  for (i = 0; i < numPts_tmp; i++) {
    inliers_data[i] = false;
  }
  emxInit_real_T(sp, &indices, 2, &ic_emlrtRTEI);
  emxInit_real_T(sp, &samplePoints, 2, &lc_emlrtRTEI);
  emxInit_real_T(sp, &hashTbl, 1, &qc_emlrtRTEI);
  emxInit_real_T(sp, &link, 1, &mc_emlrtRTEI);
  emxInit_int32_T(sp, &val, &nc_emlrtRTEI);
  emxInit_real_T(sp, &loc, 1, &oc_emlrtRTEI);
  while (((real_T)idxTrial <= numTrials) &&
         (skipTrials < params_maxSkipTrials)) {
    real_T a[30];
    real_T b_a[25];
    real_T Y[5];
    real_T Ytilde[5];
    real_T modelParams[5];
    real_T b_i;
    real_T selectedLoc;
    int32_T loop_ub_tmp;
    st.site = &jd_emlrtRSI;
    if ((!(params_sampleSize >= 0.0)) ||
        (!(params_sampleSize == muDoubleScalarFloor(params_sampleSize)))) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
                                    "MATLAB:randperm:inputType",
                                    "MATLAB:randperm:inputType", 0);
    }
    if (!(params_sampleSize <= numPts_tmp)) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                                    "MATLAB:randperm:inputKTooLarge",
                                    "MATLAB:randperm:inputKTooLarge", 0);
    }
    b_st.site = &sd_emlrtRSI;
    i = indices->size[0] * indices->size[1];
    indices->size[0] = 1;
    loop_ub_tmp = (int32_T)params_sampleSize;
    indices->size[1] = (int32_T)params_sampleSize;
    emxEnsureCapacity_real_T(&b_st, indices, i, &ic_emlrtRTEI);
    indices_data = indices->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      indices_data[i] = 0.0;
    }
    if (!(params_sampleSize == 0.0)) {
      if (params_sampleSize >= numPts_tmp) {
        indices_data[0] = 1.0;
        for (m = 0; m <= numPts_tmp - 2; m++) {
          real_T j;
          c_st.site = &td_emlrtRSI;
          j = b_rand(&c_st) * (((real_T)m + 1.0) + 1.0);
          j = muDoubleScalarFloor(j);
          indices_data[m + 1] = indices_data[(int32_T)(j + 1.0) - 1];
          indices_data[(int32_T)(j + 1.0) - 1] = ((real_T)m + 1.0) + 1.0;
        }
      } else if (params_sampleSize >= (real_T)numPts_tmp / 4.0) {
        real_T t;
        t = 0.0;
        i = (int32_T)((params_sampleSize - 1.0) + 1.0);
        for (m = 0; m < i; m++) {
          real_T j;
          real_T newEntry;
          selectedLoc = params_sampleSize - (real_T)m;
          b_i = (real_T)numPts_tmp - t;
          newEntry = selectedLoc / b_i;
          c_st.site = &ud_emlrtRSI;
          j = b_rand(&c_st);
          while (j > newEntry) {
            t++;
            b_i--;
            newEntry += (1.0 - newEntry) * (selectedLoc / b_i);
          }
          t++;
          c_st.site = &vd_emlrtRSI;
          j = b_rand(&c_st) * ((real_T)m + 1.0);
          j = muDoubleScalarFloor(j);
          indices_data[m] = indices_data[(int32_T)(j + 1.0) - 1];
          indices_data[(int32_T)(j + 1.0) - 1] = t;
        }
      } else {
        real_T newEntry;
        i = hashTbl->size[0];
        hashTbl->size[0] = (int32_T)params_sampleSize;
        emxEnsureCapacity_real_T(&b_st, hashTbl, i, &kc_emlrtRTEI);
        hashTbl_data = hashTbl->data;
        i = link->size[0];
        link->size[0] = (int32_T)params_sampleSize;
        emxEnsureCapacity_real_T(&b_st, link, i, &mc_emlrtRTEI);
        link_data = link->data;
        i = val->size[0];
        val->size[0] = (int32_T)params_sampleSize;
        emxEnsureCapacity_int32_T(&b_st, val, i, &nc_emlrtRTEI);
        val_data = val->data;
        i = loc->size[0];
        loc->size[0] = (int32_T)params_sampleSize;
        emxEnsureCapacity_real_T(&b_st, loc, i, &oc_emlrtRTEI);
        loc_data = loc->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          hashTbl_data[i] = 0.0;
          link_data[i] = 0.0;
          val_data[i] = 0;
          loc_data[i] = 0.0;
        }
        newEntry = 1.0;
        for (m = 0; m < loop_ub_tmp; m++) {
          real_T j;
          nz = (numPts_tmp - m) - 1;
          c_st.site = &wd_emlrtRSI;
          selectedLoc = b_rand(&c_st) * ((real_T)nz + 1.0);
          selectedLoc = muDoubleScalarFloor(selectedLoc);
          b_i = b_mod(selectedLoc, params_sampleSize) + 1.0;
          j = hashTbl_data[(int32_T)b_i - 1];
          while ((j > 0.0) && (loc_data[(int32_T)j - 1] != selectedLoc)) {
            j = link_data[(int32_T)j - 1];
          }
          if (j > 0.0) {
            indices_data[m] = (real_T)val_data[(int32_T)j - 1] + 1.0;
          } else {
            indices_data[m] = selectedLoc + 1.0;
            j = newEntry;
            newEntry++;
            loc_data[(int32_T)j - 1] = selectedLoc;
            link_data[(int32_T)j - 1] = hashTbl_data[(int32_T)b_i - 1];
            hashTbl_data[(int32_T)b_i - 1] = j;
          }
          if ((real_T)m + 1.0 < params_sampleSize) {
            b_i =
                hashTbl_data[(int32_T)(b_mod(nz, params_sampleSize) + 1.0) - 1];
            while ((b_i > 0.0) && (loc_data[(int32_T)b_i - 1] != nz)) {
              b_i = link_data[(int32_T)b_i - 1];
            }
            if (b_i > 0.0) {
              val_data[(int32_T)j - 1] = val_data[(int32_T)b_i - 1];
            } else {
              val_data[(int32_T)j - 1] = nz;
            }
          }
        }
      }
    }
    i = samplePoints->size[0] * samplePoints->size[1];
    samplePoints->size[0] = (int32_T)params_sampleSize;
    samplePoints->size[1] = 2;
    emxEnsureCapacity_real_T(sp, samplePoints, i, &lc_emlrtRTEI);
    hashTbl_data = samplePoints->data;
    for (i = 0; i < 2; i++) {
      for (m = 0; m < loop_ub_tmp; m++) {
        nz = (int32_T)indices_data[m];
        if (indices_data[m] != nz) {
          emlrtIntegerCheckR2012b(indices_data[m], &d_emlrtDCI,
                                  (emlrtConstCTX)sp);
        }
        if ((nz < 1) || (nz > numPts_tmp)) {
          emlrtDynamicBoundsCheckR2012b(nz, 1, numPts_tmp, &bb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        hashTbl_data[m + samplePoints->size[0] * i] =
            allPoints_data[(nz + allPoints->size[0] * i) - 1];
      }
    }
    st.site = &kd_emlrtRSI;
    for (i = 0; i < 5; i++) {
      modelParams[i] = funcs_fitFunc_workspace_a0[i];
    }
    expl_temp.workspace.COG_init[0] = c_funcs_fitFunc_workspace_nonlc[0];
    expl_temp.workspace.COG_init[1] = c_funcs_fitFunc_workspace_nonlc[1];
    expl_temp.workspace.Plant.X = d_funcs_fitFunc_workspace_nonlc;
    expl_temp.workspace.Plant.Y = e_funcs_fitFunc_workspace_nonlc;
    expl_temp.workspace.Plant.yaw = f_funcs_fitFunc_workspace_nonlc;
    b_st.site = &de_emlrtRSI;
    pcfitellipse_anonFcn2(&b_st, modelParams, funcs_fitFunc_workspace_A,
                          funcs_fitFunc_workspace_B, funcs_fitFunc_workspace_lb,
                          funcs_fitFunc_workspace_ub, expl_temp, samplePoints);
    st.site = &ld_emlrtRSI;
    b_st.site = &de_emlrtRSI;
    c_st.site = &qk_emlrtRSI;
    /*  weightも入ってた */
    /* イノベーション共分散行列 */
    /*  観測値 */
    Ytilde[0] = modelParams[0] - funcs_checkFunc_workspace->Yhbar[0];
    Ytilde[1] = modelParams[1] - funcs_checkFunc_workspace->Yhbar[1];
    Ytilde[2] = modelParams[4] - funcs_checkFunc_workspace->Yhbar[2];
    Ytilde[3] = modelParams[2] - funcs_checkFunc_workspace->Yhbar[3];
    Ytilde[4] = modelParams[3] - funcs_checkFunc_workspace->Yhbar[4];
    /*  観測予測誤差 */
    d_st.site = &rk_emlrtRSI;
    for (i = 0; i < 5; i++) {
      Y[i] = Ytilde[i];
      for (m = 0; m < 6; m++) {
        b_i = 0.0;
        for (nz = 0; nz < 6; nz++) {
          b_i += (real_T)iv[i + 5 * nz] *
                 funcs_checkFunc_workspace->Pbar[nz + 6 * m];
        }
        a[i + 5 * m] = b_i;
      }
      for (m = 0; m < 5; m++) {
        b_i = 0.0;
        for (nz = 0; nz < 6; nz++) {
          b_i += a[i + 5 * nz] * (real_T)iv1[nz + 6 * m];
        }
        nz = i + 5 * m;
        b_a[nz] = b_i + funcs_checkFunc_workspace->R[nz];
      }
    }
    e_st.site = &sk_emlrtRSI;
    mrdiv(&e_st, Y, b_a);
    b_i = 0.0;
    for (i = 0; i < 5; i++) {
      b_i += Y[i] * Ytilde[i];
    }
    d_st.site = &rk_emlrtRSI;
    if (b_i < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &i_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    /*  MahalDist:(x y theta alpha beta)の順  */
    if (muDoubleScalarSqrt(b_i) < funcs_checkFunc_workspace->MD_threshold) {
      st.site = &md_emlrtRSI;
      b_st.site = &il_emlrtRSI;
      pcfitellipse_anonFcn3(&b_st, modelParams, allPoints, hashTbl);
      hashTbl_data = hashTbl->data;
      nz = hashTbl->size[0];
      for (m = 0; m < nz; m++) {
        if (hashTbl_data[m] > params_maxDistance) {
          if (m > hashTbl->size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(m, 0, hashTbl->size[0] - 1,
                                          &ab_emlrtBCI, &st);
          }
          hashTbl_data[m] = params_maxDistance;
        }
      }
      b_st.site = &jl_emlrtRSI;
      c_st.site = &re_emlrtRSI;
      d_st.site = &se_emlrtRSI;
      b_i = combineVectorElements(&d_st, hashTbl);
      if (b_i < bestDis) {
        bestDis = b_i;
        nz = hashTbl->size[0];
        i = inliers->size[0];
        inliers->size[0] = hashTbl->size[0];
        emxEnsureCapacity_boolean_T(sp, inliers, i, &pc_emlrtRTEI);
        inliers_data = inliers->data;
        for (i = 0; i < nz; i++) {
          inliers_data[i] = (hashTbl_data[i] < params_maxDistance);
        }
        bestModelParams_size[0] = 1;
        bestModelParams_size[1] = 5;
        for (i = 0; i < 5; i++) {
          bestModelParams_data[i] = modelParams[i];
        }
        st.site = &nd_emlrtRSI;
        b_st.site = &ol_emlrtRSI;
        c_st.site = &se_emlrtRSI;
        nz = b_combineVectorElements(&c_st, inliers);
        st.site = &od_emlrtRSI;
        b_st.site = &rl_emlrtRSI;
        b_i = (real_T)nz / (real_T)numPts_tmp;
        c_st.site = &ul_emlrtRSI;
        d_st.site = &oe_emlrtRSI;
        if ((b_i < 0.0) &&
            (muDoubleScalarFloor(params_sampleSize) != params_sampleSize)) {
          emlrtErrorWithMessageIdR2018a(&d_st, &u_emlrtRTEI,
                                        "Coder:toolbox:power_domainError",
                                        "Coder:toolbox:power_domainError", 0);
        }
        b_i = muDoubleScalarPower(b_i, params_sampleSize);
        if (b_i < 2.2204460492503131E-16) {
          nz = MAX_int32_T;
        } else {
          selectedLoc = 0.01 * params_confidence;
          b_st.site = &sl_emlrtRSI;
          if (1.0 - selectedLoc < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &b_st, &v_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 5, "log10");
          }
          b_st.site = &tl_emlrtRSI;
          if (1.0 - b_i < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &b_st, &v_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 5, "log10");
          }
          b_i = muDoubleScalarCeil(muDoubleScalarLog10(1.0 - selectedLoc) /
                                   muDoubleScalarLog10(1.0 - b_i));
          if (b_i < 2.147483648E+9) {
            if (b_i >= -2.147483648E+9) {
              nz = (int32_T)b_i;
            } else {
              nz = MIN_int32_T;
            }
          } else if (b_i >= 2.147483648E+9) {
            nz = MAX_int32_T;
          } else {
            nz = 0;
          }
        }
        numTrials = muIntScalarMin_sint32(numTrials, nz);
      }
      idxTrial++;
    } else {
      skipTrials++;
    }
  }
  emxFree_real_T(sp, &loc);
  emxFree_int32_T(sp, &val);
  emxFree_real_T(sp, &link);
  emxFree_real_T(sp, &hashTbl);
  emxFree_real_T(sp, &samplePoints);
  emxFree_real_T(sp, &indices);
  st.site = &pd_emlrtRSI;
  b_st.site = &de_emlrtRSI;
  isFound = pcfitellipse_anonFcn4(
      &b_st, funcs_checkFunc_workspace->Pbar, funcs_checkFunc_workspace->R,
      funcs_checkFunc_workspace->Yhbar, funcs_checkFunc_workspace->MD_threshold,
      bestModelParams_data, bestModelParams_size[0] * bestModelParams_size[1]);
  if (isFound && (inliers->size[0] != 0)) {
    st.site = &qd_emlrtRSI;
    b_st.site = &ol_emlrtRSI;
    c_st.site = &se_emlrtRSI;
    nz = b_combineVectorElements(&c_st, inliers);
    if (nz >= params_sampleSize) {
      isFound = true;
    } else {
      isFound = false;
    }
  } else {
    isFound = false;
  }
  if (isFound) {
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i = (int32_T)d;
      } else {
        i = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      i = MAX_int32_T;
    } else {
      i = 0;
    }
    if (numTrials >= i) {
      st.site = &rd_emlrtRSI;
      b_warning(&st);
    }
  } else {
    i = inliers->size[0];
    inliers->size[0] = allPoints->size[0];
    emxEnsureCapacity_boolean_T(sp, inliers, i, &jc_emlrtRTEI);
    inliers_data = inliers->data;
    for (i = 0; i < numPts_tmp; i++) {
      inliers_data[i] = false;
    }
  }
  *reachedMaxSkipTrials = (skipTrials >= params_maxSkipTrials);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return isFound;
}

/* End of code generation (msac.c) */
