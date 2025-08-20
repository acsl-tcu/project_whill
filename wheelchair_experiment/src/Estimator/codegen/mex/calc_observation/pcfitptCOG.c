/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitptCOG.c
 *
 * Code generation for function 'pcfitptCOG'
 *
 */

/* Include files */
#include "pcfitptCOG.h"
#include "calc_observation_data.h"
#include "calc_observation_emxutil.h"
#include "calc_observation_types.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo vl_emlrtRSI = {
    2,            /* lineNo */
    "pcfitptCOG", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitptCOG.m" /* pathName */
};

static emlrtRSInfo wl_emlrtRSI = {
    4,            /* lineNo */
    "pcfitptCOG", /* fcnName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitptCOG.m" /* pathName */
};

static emlrtRTEInfo hd_emlrtRTEI = {
    2,            /* lineNo */
    31,           /* colNo */
    "pcfitptCOG", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitptCOG.m" /* pName */
};

static emlrtRTEInfo id_emlrtRTEI = {
    2,            /* lineNo */
    57,           /* colNo */
    "pcfitptCOG", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitptCOG.m" /* pName */
};

/* Function Definitions */
void pcfitptCOG(const emlrtStack *sp, const pointCloud *point,
                const real_T xhat[6], real_T modelptCOG_crr[2],
                real_T modelptCOG[2])
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *b_point;
  real_T accumulatedData;
  real_T *point_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  ,pxhat,imm */
  st.site = &vl_emlrtRSI;
  emxInit_real_T(&st, &b_point, 1, &hd_emlrtRTEI);
  loop_ub = point->Location->size[0];
  i = b_point->size[0];
  b_point->size[0] = loop_ub;
  emxEnsureCapacity_real_T(&st, b_point, i, &hd_emlrtRTEI);
  point_data = b_point->data;
  for (i = 0; i < loop_ub; i++) {
    point_data[i] = point->Location->data[i];
  }
  b_st.site = &x_emlrtRSI;
  accumulatedData = combineVectorElements(&b_st, b_point);
  st.site = &vl_emlrtRSI;
  i = b_point->size[0];
  b_point->size[0] = loop_ub;
  emxEnsureCapacity_real_T(&st, b_point, i, &id_emlrtRTEI);
  point_data = b_point->data;
  for (i = 0; i < loop_ub; i++) {
    point_data[i] = point->Location->data[i + point->Location->size[0]];
  }
  real_T b_accumulatedData;
  b_st.site = &x_emlrtRSI;
  b_accumulatedData = combineVectorElements(&b_st, b_point);
  emxFree_real_T(&st, &b_point);
  modelptCOG[0] = accumulatedData / (real_T)point->Location->size[0];
  modelptCOG[1] = b_accumulatedData / (real_T)point->Location->size[0];
  /*  点群重心 */
  st.site = &wl_emlrtRSI;
  accumulatedData = muDoubleScalarSin(muDoubleScalarRound(xhat[2]) / 4.0);
  /*  xhat(8) 姿勢角に合わせたオフセット補正 */
  /*  pv = pxhat(4).*[cos(pxhat(3));sin(pxhat(3))]; */
  /*  modelptCOG_crr = modelptCOG + (xhat(8).*[abs(cos(xhat(3)));sin(xhat(3))]);
   */
  accumulatedData =
      (xhat[4] - (xhat[4] - xhat[5]) * (accumulatedData * accumulatedData)) *
      xhat[5];
  modelptCOG_crr[0] =
      modelptCOG[0] +
      accumulatedData * muDoubleScalarAbs(muDoubleScalarCos(xhat[2]));
  modelptCOG_crr[1] =
      modelptCOG[1] + accumulatedData * muDoubleScalarSin(xhat[2]);
  /*  胴体中心に近づけるためのオフセット */
  /*  modelptCOG_crr = modelptCOG +
   * sign(dot(modelptCOG,xhat(4:5))).*(xhat(8).*[cos(xhat(3));sin(xhat(3))]); */
  /*  S = c*Pbar*c'+R; */
  /*  score = likelihood(imm.TrackingFilters{3,1},modelptCOG_crr); */
  /*  if forassociate */
  /*      Ytilde = modelptCOG-Yhbar; */
  /*  else */
  /*      Ytilde = modelptCOG_crr-Yhbar; */
  /*  end */
  /*  MD = sqrt(Ytilde'/S*Ytilde); */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (pcfitptCOG.c) */
