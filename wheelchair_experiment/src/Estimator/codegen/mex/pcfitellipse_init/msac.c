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
#include "pcfitellipse_init.h"
#include "pcfitellipse_init_data.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = {
    129,    /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    105,    /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    87,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    86,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    78,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    71,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    67,     /* lineNo */
    "msac", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo
    v_emlrtRSI =
        {
            24,         /* lineNo */
            "randperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo
    w_emlrtRSI =
        {
            40,          /* lineNo */
            "randkperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo
    x_emlrtRSI =
        {
            50,          /* lineNo */
            "randkperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo
    y_emlrtRSI =
        {
            57,          /* lineNo */
            "randkperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo
    ab_emlrtRSI =
        {
            69,          /* lineNo */
            "randkperm", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pathName */
};

static emlrtRSInfo gi_emlrtRSI = {
    140,             /* lineNo */
    "evaluateModel", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo hi_emlrtRSI = {
    142,             /* lineNo */
    "evaluateModel", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\msac.m" /* pathName */
};

static emlrtRSInfo mi_emlrtRSI = {
    15,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

static emlrtRSInfo pi_emlrtRSI = {
    11,                  /* lineNo */
    "computeLoopNumber", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\computeLoopNumber.m" /* pathName */
};

static emlrtRSInfo qi_emlrtRSI = {
    18,                  /* lineNo */
    "computeLoopNumber", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\computeLoopNumber.m" /* pathName */
};

static emlrtRSInfo ri_emlrtRSI = {
    19,                  /* lineNo */
    "computeLoopNumber", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "ransac\\computeLoopNumber.m" /* pathName */
};

static emlrtRSInfo si_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m" /* pathName
                                                                          */
};

static emlrtRTEInfo i_emlrtRTEI = {
    14,      /* lineNo */
    9,       /* colNo */
    "log10", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\log10.m" /* pName
                                                                        */
};

static emlrtRTEInfo j_emlrtRTEI =
    {
        82,         /* lineNo */
        5,          /* colNo */
        "fltpower", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    l_emlrtRTEI =
        {
            20,         /* lineNo */
            19,         /* colNo */
            "randperm", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randper"
            "m.m" /* pName */
};

static emlrtRTEInfo
    m_emlrtRTEI =
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

static emlrtBCInfo c_emlrtBCI = {
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

static emlrtBCInfo d_emlrtBCI = {
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

/* Function Definitions */
boolean_T msac(const emlrtStack *sp, const real_T allPoints_data[],
               const int32_T allPoints_size[2], real_T params_sampleSize,
               real_T params_maxDistance, real_T params_confidence,
               real_T params_maxNumTrials,
               const real_T funcs_fitFunc_workspace_a0[5],
               const real_T funcs_fitFunc_workspace_A[5],
               real_T funcs_fitFunc_workspace_B,
               const real_T funcs_fitFunc_workspace_lb[5],
               const real_T funcs_fitFunc_workspace_ub[5],
               real_T bestModelParams_data[], int32_T bestModelParams_size[2],
               boolean_T inliers_data[], int32_T *inliers_size,
               boolean_T *reachedMaxSkipTrials)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T hashTbl_data[1500];
  real_T indices_data[1500];
  real_T link_data[1500];
  real_T loc_data[1500];
  real_T bestDis;
  real_T d;
  int32_T samplePoints_size[2];
  int32_T allPoints;
  int32_T i;
  int32_T loop_ub_tmp;
  int32_T m;
  int32_T numPts;
  int32_T numTrials;
  int32_T nz;
  uint32_T idxTrial;
  int16_T val_data[1500];
  boolean_T b;
  boolean_T isFound;
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
  numPts = allPoints_size[0];
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
  bestDis = params_maxDistance * (real_T)allPoints_size[0];
  bestModelParams_size[0] = 0;
  bestModelParams_size[1] = 0;
  *inliers_size = allPoints_size[0];
  nz = allPoints_size[0];
  if (nz - 1 >= 0) {
    memset(&inliers_data[0], 0, (uint32_T)nz * sizeof(boolean_T));
  }
  if (numTrials >= 1) {
    if ((params_sampleSize >= 0.0) &&
        (params_sampleSize == muDoubleScalarFloor(params_sampleSize))) {
      b = true;
    } else {
      b = false;
    }
    allPoints = allPoints_size[0];
  }
  if (numTrials >= 1.0) {
    loop_ub_tmp = (int32_T)params_sampleSize;
    samplePoints_size[0] = (int32_T)params_sampleSize;
    samplePoints_size[1] = 2;
  }
  while ((real_T)idxTrial <= numTrials) {
    real_T samplePoints_data[3000];
    real_T modelParams[5];
    real_T b_i;
    real_T selectedLoc;
    st.site = &u_emlrtRSI;
    if (!b) {
      emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
                                    "MATLAB:randperm:inputType",
                                    "MATLAB:randperm:inputType", 0);
    }
    if (!(params_sampleSize <= numPts)) {
      emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                    "MATLAB:randperm:inputKTooLarge",
                                    "MATLAB:randperm:inputKTooLarge", 0);
    }
    b_st.site = &v_emlrtRSI;
    if (!(params_sampleSize >= 0.0)) {
      emlrtNonNegativeCheckR2012b(params_sampleSize, &emlrtDCI, &b_st);
    }
    if (loop_ub_tmp - 1 >= 0) {
      memset(&indices_data[0], 0, (uint32_T)loop_ub_tmp * sizeof(real_T));
    }
    if (!(params_sampleSize == 0.0)) {
      if (params_sampleSize >= numPts) {
        indices_data[0] = 1.0;
        for (i = 0; i <= numPts - 2; i++) {
          real_T j;
          c_st.site = &w_emlrtRSI;
          j = b_rand() * (((real_T)i + 1.0) + 1.0);
          j = muDoubleScalarFloor(j);
          indices_data[i + 1] = indices_data[(int32_T)(j + 1.0) - 1];
          indices_data[(int32_T)(j + 1.0) - 1] = ((real_T)i + 1.0) + 1.0;
        }
      } else if (params_sampleSize >= (real_T)numPts / 4.0) {
        real_T t;
        t = 0.0;
        i = (int32_T)((params_sampleSize - 1.0) + 1.0);
        for (m = 0; m < i; m++) {
          real_T j;
          real_T newEntry;
          selectedLoc = params_sampleSize - (real_T)m;
          b_i = (real_T)numPts - t;
          newEntry = selectedLoc / b_i;
          c_st.site = &x_emlrtRSI;
          j = b_rand();
          while (j > newEntry) {
            t++;
            b_i--;
            newEntry += (1.0 - newEntry) * (selectedLoc / b_i);
          }
          t++;
          c_st.site = &y_emlrtRSI;
          j = b_rand() * ((real_T)m + 1.0);
          j = muDoubleScalarFloor(j);
          indices_data[m] = indices_data[(int32_T)(j + 1.0) - 1];
          indices_data[(int32_T)(j + 1.0) - 1] = t;
        }
      } else {
        real_T newEntry;
        if (loop_ub_tmp - 1 >= 0) {
          memset(&hashTbl_data[0], 0, (uint32_T)loop_ub_tmp * sizeof(real_T));
        }
        if (loop_ub_tmp - 1 >= 0) {
          memset(&link_data[0], 0, (uint32_T)loop_ub_tmp * sizeof(real_T));
        }
        if (loop_ub_tmp - 1 >= 0) {
          memset(&val_data[0], 0, (uint32_T)loop_ub_tmp * sizeof(int16_T));
        }
        if (loop_ub_tmp - 1 >= 0) {
          memset(&loc_data[0], 0, (uint32_T)loop_ub_tmp * sizeof(real_T));
        }
        newEntry = 1.0;
        for (m = 0; m < loop_ub_tmp; m++) {
          real_T j;
          nz = (numPts - m) - 1;
          c_st.site = &ab_emlrtRSI;
          selectedLoc = b_rand() * ((real_T)nz + 1.0);
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
              val_data[(int32_T)j - 1] = (int16_T)nz;
            }
          }
        }
      }
    }
    for (i = 0; i < 2; i++) {
      for (nz = 0; nz < loop_ub_tmp; nz++) {
        b_i = indices_data[nz];
        if (b_i != (int32_T)b_i) {
          emlrtIntegerCheckR2012b(b_i, &b_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)b_i < 1) || ((int32_T)b_i > allPoints)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_i, 1, allPoints, &c_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        samplePoints_data[nz + (int32_T)params_sampleSize * i] =
            allPoints_data[((int32_T)b_i + allPoints_size[0] * i) - 1];
      }
    }
    st.site = &t_emlrtRSI;
    b_st.site = &cb_emlrtRSI;
    pcfitellipse_init_anonFcn1(
        &b_st, funcs_fitFunc_workspace_a0, funcs_fitFunc_workspace_A,
        funcs_fitFunc_workspace_B, funcs_fitFunc_workspace_lb,
        funcs_fitFunc_workspace_ub, samplePoints_data, samplePoints_size,
        modelParams);
    st.site = &s_emlrtRSI;
    b_st.site = &gi_emlrtRSI;
    m = pcfitellipse_init_anonFcn2(&b_st, modelParams, allPoints_data,
                                   allPoints_size, hashTbl_data);
    nz = m - 1;
    for (i = 0; i <= nz; i++) {
      if (hashTbl_data[i] > params_maxDistance) {
        if (i > m - 1) {
          emlrtDynamicBoundsCheckR2012b(i, 0, m - 1, &d_emlrtBCI, &st);
        }
        hashTbl_data[i] = params_maxDistance;
      }
    }
    b_st.site = &hi_emlrtRSI;
    c_st.site = &ub_emlrtRSI;
    d_st.site = &vb_emlrtRSI;
    e_st.site = &wb_emlrtRSI;
    if (m == 0) {
      b_i = 0.0;
    } else {
      f_st.site = &xb_emlrtRSI;
      g_st.site = &yb_emlrtRSI;
      h_st.site = &ac_emlrtRSI;
      b_i = sumColumnB(&h_st, hashTbl_data, m);
    }
    if (b_i < bestDis) {
      bestDis = b_i;
      *inliers_size = m;
      for (i = 0; i < m; i++) {
        inliers_data[i] = (hashTbl_data[i] < params_maxDistance);
      }
      bestModelParams_size[0] = 1;
      bestModelParams_size[1] = 5;
      for (i = 0; i < 5; i++) {
        bestModelParams_data[i] = modelParams[i];
      }
      st.site = &r_emlrtRSI;
      b_st.site = &mi_emlrtRSI;
      c_st.site = &vb_emlrtRSI;
      nz = combineVectorElements(inliers_data, m);
      st.site = &q_emlrtRSI;
      b_st.site = &pi_emlrtRSI;
      b_i = (real_T)nz / (real_T)numPts;
      c_st.site = &si_emlrtRSI;
      d_st.site = &nb_emlrtRSI;
      if ((b_i < 0.0) &&
          (muDoubleScalarFloor(params_sampleSize) != params_sampleSize)) {
        emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI,
                                      "Coder:toolbox:power_domainError",
                                      "Coder:toolbox:power_domainError", 0);
      }
      b_i = muDoubleScalarPower(b_i, params_sampleSize);
      if (b_i < 2.2204460492503131E-16) {
        nz = MAX_int32_T;
      } else {
        selectedLoc = 0.01 * params_confidence;
        b_st.site = &qi_emlrtRSI;
        if (1.0 - selectedLoc < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &i_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 5, "log10");
        }
        b_st.site = &ri_emlrtRSI;
        if (1.0 - b_i < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &i_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
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
  }
  if (*inliers_size != 0) {
    st.site = &p_emlrtRSI;
    b_st.site = &mi_emlrtRSI;
    c_st.site = &vb_emlrtRSI;
    nz = combineVectorElements(inliers_data, *inliers_size);
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
      st.site = &o_emlrtRSI;
      warning(&st);
    }
  } else {
    *inliers_size = allPoints_size[0];
    nz = allPoints_size[0];
    if (nz - 1 >= 0) {
      memset(&inliers_data[0], 0, (uint32_T)nz * sizeof(boolean_T));
    }
  }
  *reachedMaxSkipTrials = false;
  return isFound;
}

/* End of code generation (msac.c) */
