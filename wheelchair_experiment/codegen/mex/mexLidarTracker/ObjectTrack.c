/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ObjectTrack.c
 *
 * Code generation for function 'ObjectTrack'
 *
 */

/* Include files */
#include "ObjectTrack.h"
#include "EKFCorrector.h"
#include "ExtendedKalmanFilter.h"
#include "all.h"
#include "cholPSD.h"
#include "cvmeas.h"
#include "cvmeasjac.h"
#include "det.h"
#include "find.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "mod.h"
#include "mrdivide_helper.h"
#include "predictTrackFilter.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sumMatrixIncludeNaN.h"
#include "trackingEKF.h"
#include "validateInputSizeAndType.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ou_emlrtRSI = {
    618,                   /* lineNo */
    "ObjectTrack/nullify", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo pu_emlrtRSI = {
    619,                   /* lineNo */
    "ObjectTrack/nullify", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo tu_emlrtRSI = {
    1369,               /* lineNo */
    "ObjectTrack/copy", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo uu_emlrtRSI = {
    1344,               /* lineNo */
    "ObjectTrack/copy", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo vu_emlrtRSI = {
    1345,               /* lineNo */
    "ObjectTrack/copy", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo wu_emlrtRSI = {
    1355,               /* lineNo */
    "ObjectTrack/copy", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo av_emlrtRSI = {
    1392,                                /* lineNo */
    "ObjectTrack/copyPrivateProperties", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo bv_emlrtRSI = {
    1393,                                /* lineNo */
    "ObjectTrack/copyPrivateProperties", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo mv_emlrtRSI = {
    1614,                                                           /* lineNo */
    "ExtendedKalmanFilter/measurementNoiseScalarExpandIfNecessary", /* fcnName
                                                                     */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo teb_emlrtRSI = {
    1782,                               /* lineNo */
    "ObjectTrack/calcCostOneDetection", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo ueb_emlrtRSI =
    {
        304,                    /* lineNo */
        "trackingEKF/distance", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo veb_emlrtRSI =
    {
        317,                    /* lineNo */
        "trackingEKF/distance", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo web_emlrtRSI =
    {
        320,                    /* lineNo */
        "trackingEKF/distance", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo xeb_emlrtRSI = {
    6,                           /* lineNo */
    "validateMeasurementMatrix", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/validateMeasurementMatrix.m" /* pathName
                                                                     */
};

static emlrtRSInfo nfb_emlrtRSI = {
    46,                    /* lineNo */
    "EKFDistanceAdditive", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFDistanceAdditive.m" /* pathName */
};

static emlrtRSInfo ofb_emlrtRSI = {
    49,                    /* lineNo */
    "EKFDistanceAdditive", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFDistanceAdditive.m" /* pathName */
};

static emlrtRSInfo pfb_emlrtRSI = {
    67,                    /* lineNo */
    "EKFDistanceAdditive", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFDistanceAdditive.m" /* pathName */
};

static emlrtRSInfo qfb_emlrtRSI = {
    69,                    /* lineNo */
    "EKFDistanceAdditive", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFDistanceAdditive.m" /* pathName */
};

static emlrtRSInfo rfb_emlrtRSI = {
    73,                    /* lineNo */
    "EKFDistanceAdditive", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFDistanceAdditive.m" /* pathName */
};

static emlrtRSInfo sfb_emlrtRSI = {
    40,           /* lineNo */
    "KFDistance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/KFDistance.m" /* pathName */
};

static emlrtRSInfo tfb_emlrtRSI = {
    9,                    /* lineNo */
    "normalizedDistance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/normalizedDistance.m" /* pathName */
};

static emlrtRSInfo ufb_emlrtRSI = {
    10,                   /* lineNo */
    "normalizedDistance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/normalizedDistance.m" /* pathName */
};

static emlrtRSInfo vfb_emlrtRSI = {
    11,       /* lineNo */
    "logDet", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/logDet.m" /* pathName */
};

static emlrtRSInfo wfb_emlrtRSI = {
    13,       /* lineNo */
    "logDet", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/logDet.m" /* pathName */
};

static emlrtRSInfo dgb_emlrtRSI = {
    638,                   /* lineNo */
    "ObjectTrack/predict", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo egb_emlrtRSI = {
    640,                   /* lineNo */
    "ObjectTrack/predict", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo fgb_emlrtRSI = {
    660,                   /* lineNo */
    "ObjectTrack/predict", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo slb_emlrtRSI = {
    1812,                                     /* lineNo */
    "ObjectTrack/setAttributesFromDetection", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo apb_emlrtRSI = {
    275,                               /* lineNo */
    "ObjectTrack/get.StateCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo bpb_emlrtRSI = {
    477,                         /* lineNo */
    "ObjectTrack/trackToStruct", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo cpb_emlrtRSI = {
    478,                         /* lineNo */
    "ObjectTrack/trackToStruct", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo dpb_emlrtRSI = {
    483,                         /* lineNo */
    "ObjectTrack/trackToStruct", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo epb_emlrtRSI = {
    485,                         /* lineNo */
    "ObjectTrack/trackToStruct", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo fpb_emlrtRSI = {
    488,                         /* lineNo */
    "ObjectTrack/trackToStruct", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo gpb_emlrtRSI = {
    235,                        /* lineNo */
    "trackHistoryLogic/output", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "trackHistoryLogic.m" /* pathName */
};

static emlrtRSInfo hpb_emlrtRSI = {
    444,                                /* lineNo */
    "ObjectTrack/get.ObjectAttributes", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pathName */
};

static emlrtRSInfo ipb_emlrtRSI = {
    27,                /* lineNo */
    "horzcatCellList", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "horzcatCellList.m" /* pathName */
};

static emlrtRTEInfo kd_emlrtRTEI = {
    110,           /* lineNo */
    9,             /* colNo */
    "allocOutput", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "horzcatCellList.m" /* pName */
};

static emlrtRTEInfo uk_emlrtRTEI = {
    1619,          /* lineNo */
    20,            /* colNo */
    "ObjectTrack", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pName */
};

static emlrtRTEInfo vk_emlrtRTEI = {
    1608,          /* lineNo */
    28,            /* colNo */
    "ObjectTrack", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/ObjectTrack.m" /* pName */
};

/* Function Definitions */
boolean_T ObjectTrack_checkPromotion(d_matlabshared_tracking_interna *track)
{
  trackHistoryLogic *obj;
  int32_T k;
  int32_T nz;
  boolean_T toPromote;
  if (track->ObjectClassID != 0.0) {
    toPromote = true;
  } else {
    obj = track->TrackLogic;
    if (obj->pIsFirstUpdate) {
      toPromote = false;
    } else {
      boolean_T x[10];
      for (nz = 0; nz < 10; nz++) {
        x[nz] = obj->pRecentHistory[nz];
      }
      nz = x[0];
      for (k = 0; k < 9; k++) {
        nz += x[k + 1];
      }
      toPromote = (nz >= 7);
    }
  }
  return toPromote;
}

d_matlabshared_tracking_interna *
ObjectTrack_copy(const emlrtStack *sp, d_matlabshared_tracking_interna *track,
                 d_matlabshared_tracking_interna *iobj_0,
                 trackHistoryLogic *iobj_1, trackingEKF *iobj_2)
{
  d_matlabshared_tracking_interna *newTrack;
  emlrtStack b_st;
  emlrtStack st;
  trackHistoryLogic *obj;
  trackingEKF *filter;
  int32_T i;
  boolean_T b_obj[50];
  boolean_T b_track[20];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &uu_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  filter = trackingEKF_clone(track->Filter, &iobj_2[0]);
  st.site = &vu_emlrtRSI;
  obj = track->TrackLogic;
  for (i = 0; i < 50; i++) {
    iobj_1->pRecentHistory[i] = false;
  }
  for (i = 0; i < 50; i++) {
    b_obj[i] = obj->pRecentHistory[i];
  }
  for (i = 0; i < 50; i++) {
    iobj_1->pRecentHistory[i] = b_obj[i];
  }
  real_T classification;
  real_T t;
  uint32_T origID;
  uint32_T sysID;
  boolean_T isconfirmed;
  iobj_1->pIsFirstUpdate = obj->pIsFirstUpdate;
  st.site = &wu_emlrtRSI;
  sysID = track->BranchID;
  origID = track->TrackID;
  t = track->Time;
  classification = track->ObjectClassID;
  isconfirmed = track->IsConfirmed;
  newTrack = iobj_0;
  iobj_0->BranchID = sysID;
  iobj_0->TrackID = origID;
  iobj_0->Filter = filter;
  iobj_0->pDistanceFilter = trackingEKF_clone(filter, &iobj_2[1]);
  iobj_0->UpdateTime = t;
  iobj_0->Time = t;
  iobj_0->ObjectClassID = classification;
  iobj_0->TrackLogic = iobj_1;
  iobj_0->IsConfirmed = isconfirmed;
  for (i = 0; i < 20; i++) {
    iobj_0->pUsedObjectAttributes[i] = false;
  }
  iobj_0->pUsedObjectAttributes[0] = true;
  st.site = &tu_emlrtRSI;
  iobj_0->UpdateTime = track->UpdateTime;
  iobj_0->pIsCoasted = track->pIsCoasted;
  for (i = 0; i < 20; i++) {
    b_track[i] = track->pUsedObjectAttributes[i];
  }
  for (i = 0; i < 20; i++) {
    iobj_0->pUsedObjectAttributes[i] = b_track[i];
  }
  iobj_0->pAge = track->pAge;
  b_st.site = &av_emlrtRSI;
  trackingEKF_sync(&b_st, iobj_0->Filter, track->Filter);
  b_st.site = &bv_emlrtRSI;
  trackingEKF_sync(&b_st, iobj_0->pDistanceFilter, track->pDistanceFilter);
  return newTrack;
}

void ObjectTrack_correctjpda(const emlrtStack *sp,
                             d_matlabshared_tracking_interna *track,
                             const objectDetection *detections,
                             const uint32_T usedSensors[20])
{
  static real_T wrapping[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  trackHistoryLogic *obj;
  trackingEKF *filter;
  real_T P[36];
  real_T b_a[36];
  real_T b_value[36];
  real_T Pxy[18];
  real_T dHdx[18];
  real_T gain[18];
  real_T a[9];
  real_T b_dHdx[9];
  real_T b_detections[9];
  real_T c_a[9];
  real_T b_tmp_data[6];
  real_T b_wrapping[6];
  real_T c_tmp_data[6];
  real_T dv[6];
  real_T innovations[3];
  real_T resToWrap_data[3];
  real_T zEstimated[3];
  real_T resToWrap_tmp;
  int32_T b_iv[2];
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T trueCount;
  int32_T vectorUB_tmp;
  uint32_T q0;
  uint32_T qY;
  int8_T d_tmp_data[3];
  int8_T tmp_data[3];
  boolean_T bv[50];
  boolean_T isf[3];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  wrapping[0U] = rtMinusInf;
  wrapping[1U] = rtMinusInf;
  wrapping[2U] = rtMinusInf;
  wrapping[3U] = rtInf;
  wrapping[4U] = rtInf;
  wrapping[5U] = rtInf;
  st.site = &llb_emlrtRSI;
  ObjectTrack_predict(&st, track, detections->Time);
  st.site = &mlb_emlrtRSI;
  c_ObjectTrack_setAttributesFrom(&st, track, detections->SensorIndex,
                                  usedSensors);
  st.site = &nlb_emlrtRSI;
  b_st.site = &xlb_emlrtRSI;
  if (detections->ObjectClassID != 0.0) {
    track->ObjectClassID = detections->ObjectClassID;
  }
  st.site = &olb_emlrtRSI;
  memcpy(&b_detections[0], &detections->pMeasurementNoise[0],
         9U * sizeof(real_T));
  b_st.site = &bmb_emlrtRSI;
  c_ExtendedKalmanFilter_set_Meas(&b_st, track->Filter, b_detections);
  innovations[0] = detections->Measurement[0];
  innovations[1] = detections->Measurement[1];
  innovations[2] = detections->Measurement[2];
  st.site = &plb_emlrtRSI;
  filter = track->Filter;
  b_st.site = &dmb_emlrtRSI;
  c_st.site = &jmb_emlrtRSI;
  d_st.site = &jc_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 3)) {
    if ((!muDoubleScalarIsInf(innovations[i])) &&
        (!muDoubleScalarIsNaN(innovations[i]))) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:correctjpda:expectedFinite", 3, 4, 1, "z");
  }
  c_st.site = &kmb_emlrtRSI;
  validateInputSizeAndType(&c_st, innovations);
  c_st.site = &lmb_emlrtRSI;
  c_ExtendedKalmanFilter_validate(&c_st, filter);
  b_st.site = &emb_emlrtRSI;
  for (b_i = 0; b_i < 9; b_i++) {
    b_detections[b_i] = filter->pSqrtMeasurementNoise[b_i];
  }
  for (b_i = 0; b_i < 9; b_i++) {
    a[b_i] = filter->pSqrtMeasurementNoise[b_i];
  }
  b_st.site = &fmb_emlrtRSI;
  for (b_i = 0; b_i < 36; b_i++) {
    b_value[b_i] = filter->pSqrtStateCovariance[b_i];
  }
  for (b_i = 0; b_i < 36; b_i++) {
    b_a[b_i] = filter->pSqrtStateCovariance[b_i];
  }
  for (b_i = 0; b_i < 6; b_i++) {
    for (i1 = 0; i1 < 6; i1++) {
      resToWrap_tmp = 0.0;
      for (vectorUB_tmp = 0; vectorUB_tmp < 6; vectorUB_tmp++) {
        resToWrap_tmp +=
            b_a[b_i + 6 * vectorUB_tmp] * b_value[i1 + 6 * vectorUB_tmp];
      }
      P[b_i + 6 * i1] = resToWrap_tmp;
    }
  }
  b_st.site = &gmb_emlrtRSI;
  for (i = 0; i < 6; i++) {
    dv[i] = filter->pState[i];
  }
  c_st.site = &qmb_emlrtRSI;
  d_st.site = &pmb_emlrtRSI;
  cvmeasjac(&d_st, dv, dHdx);
  for (b_i = 0; b_i < 6; b_i++) {
    for (i1 = 0; i1 < 3; i1++) {
      resToWrap_tmp = 0.0;
      for (vectorUB_tmp = 0; vectorUB_tmp < 6; vectorUB_tmp++) {
        resToWrap_tmp +=
            P[b_i + 6 * vectorUB_tmp] * dHdx[i1 + 3 * vectorUB_tmp];
      }
      Pxy[b_i + 6 * i1] = resToWrap_tmp;
    }
  }
  for (b_i = 0; b_i < 3; b_i++) {
    for (i1 = 0; i1 < 3; i1++) {
      resToWrap_tmp = 0.0;
      for (vectorUB_tmp = 0; vectorUB_tmp < 6; vectorUB_tmp++) {
        resToWrap_tmp +=
            dHdx[b_i + 3 * vectorUB_tmp] * Pxy[vectorUB_tmp + 6 * i1];
      }
      i = b_i + 3 * i1;
      b_dHdx[i] = resToWrap_tmp;
      c_a[i] = (a[b_i] * b_detections[i1] + a[b_i + 3] * b_detections[i1 + 3]) +
               a[b_i + 6] * b_detections[i1 + 6];
    }
  }
  r = _mm_loadu_pd(&b_dHdx[0]);
  r1 = _mm_loadu_pd(&c_a[0]);
  _mm_storeu_pd(&b_dHdx[0], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&b_dHdx[2]);
  r1 = _mm_loadu_pd(&c_a[2]);
  _mm_storeu_pd(&b_dHdx[2], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&b_dHdx[4]);
  r1 = _mm_loadu_pd(&c_a[4]);
  _mm_storeu_pd(&b_dHdx[4], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&b_dHdx[6]);
  r1 = _mm_loadu_pd(&c_a[6]);
  _mm_storeu_pd(&b_dHdx[6], _mm_add_pd(r, r1));
  b_dHdx[8] += c_a[8];
  d_st.site = &omb_emlrtRSI;
  cvmeas(&d_st, dv, zEstimated);
  for (b_i = 0; b_i < 6; b_i++) {
    b_wrapping[b_i] = wrapping[b_i];
  }
  c_st.site = &smb_emlrtRSI;
  d_st.site = &umb_emlrtRSI;
  r = _mm_loadu_pd(&innovations[0]);
  r1 = _mm_loadu_pd(&zEstimated[0]);
  _mm_storeu_pd(&innovations[0], _mm_sub_pd(r, r1));
  innovations[2] -= zEstimated[2];
  d_all(isf);
  p = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= 2)) {
    if (isf[i]) {
      p = true;
      exitg1 = true;
    } else {
      i++;
    }
  }
  if (p) {
    real_T y_data[3];
    boolean_T b;
    boolean_T b1;
    trueCount = 0;
    if (isf[0]) {
      trueCount = 1;
    }
    if (isf[1]) {
      trueCount++;
    }
    if (isf[2]) {
      trueCount++;
    }
    i = 0;
    if (isf[0]) {
      tmp_data[0] = 0;
      i = 1;
    }
    if (isf[1]) {
      tmp_data[i] = 1;
      i++;
    }
    if (isf[2]) {
      tmp_data[i] = 2;
    }
    for (b_i = 0; b_i < trueCount; b_i++) {
      zEstimated[b_i] = rtInf;
      resToWrap_data[b_i] = rtMinusInf;
    }
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < trueCount; i1++) {
        b_tmp_data[i1 + trueCount * b_i] = wrapping[tmp_data[i1] + 3 * b_i];
      }
    }
    i = (trueCount / 2) << 1;
    vectorUB_tmp = i - 2;
    for (b_i = 0; b_i <= vectorUB_tmp; b_i += 2) {
      r = _mm_loadu_pd(&zEstimated[0]);
      r1 = _mm_loadu_pd(&resToWrap_data[0]);
      _mm_storeu_pd(&zEstimated[0],
                    _mm_div_pd(_mm_add_pd(r, r1), _mm_set1_pd(2.0)));
    }
    for (b_i = i; b_i < trueCount; b_i++) {
      zEstimated[b_i] = (zEstimated[b_i] - rtInf) / 2.0;
    }
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
        r = _mm_loadu_pd(&b_tmp_data[trueCount * b_i]);
        r1 = _mm_loadu_pd(&zEstimated[0]);
        _mm_storeu_pd(&c_tmp_data[trueCount * b_i], _mm_sub_pd(r, r1));
      }
      for (i1 = i; i1 < trueCount; i1++) {
        c_tmp_data[i1 + trueCount * b_i] =
            b_tmp_data[i1 + trueCount * b_i] - zEstimated[i1];
      }
    }
    tmp_size[0] = trueCount;
    tmp_size[1] = 2;
    i = trueCount << 1;
    if (i - 1 >= 0) {
      memcpy(&b_tmp_data[0], &c_tmp_data[0], (uint32_T)i * sizeof(real_T));
    }
    b_iv[0] = trueCount;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &tmp_size[0], 2, &cb_emlrtECI,
                                  &d_st);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < trueCount; i1++) {
        b_wrapping[tmp_data[i1] + 3 * b_i] = b_tmp_data[i1 + tmp_size[0] * b_i];
      }
    }
    trueCount = 0;
    p = (isf[0] && (muDoubleScalarAbs(muDoubleScalarAbs(innovations[0]) /
                                      b_wrapping[3]) > 0.001));
    if (p) {
      trueCount = 1;
    }
    b = (isf[1] && (muDoubleScalarAbs(muDoubleScalarAbs(innovations[1]) /
                                      b_wrapping[4]) > 0.001));
    if (b) {
      trueCount++;
    }
    b1 = (isf[2] && (muDoubleScalarAbs(muDoubleScalarAbs(innovations[2]) /
                                       b_wrapping[5]) > 0.001));
    if (b1) {
      trueCount++;
    }
    i = 0;
    if (p) {
      d_tmp_data[0] = 0;
      i = 1;
    }
    if (b) {
      d_tmp_data[i] = 1;
      i++;
    }
    if (b1) {
      d_tmp_data[i] = 2;
    }
    for (b_i = 0; b_i < trueCount; b_i++) {
      int8_T i2;
      i2 = d_tmp_data[b_i];
      resToWrap_tmp = b_wrapping[i2];
      resToWrap_data[b_i] = innovations[i2] - resToWrap_tmp;
      y_data[b_i] = b_wrapping[i2 + 3] - resToWrap_tmp;
    }
    i = trueCount;
    for (b_i = 0; b_i < trueCount; b_i++) {
      zEstimated[b_i] = b_mod(resToWrap_data[b_i], y_data[b_i]);
    }
    for (b_i = 0; b_i < trueCount; b_i++) {
      resToWrap_data[b_i] = zEstimated[b_i] + b_wrapping[d_tmp_data[b_i]];
    }
    emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &i, 1, &eb_emlrtECI, &d_st);
    for (b_i = 0; b_i < trueCount; b_i++) {
      innovations[d_tmp_data[b_i]] = resToWrap_data[b_i];
    }
  }
  zEstimated[0] = innovations[0];
  zEstimated[1] = innovations[1];
  zEstimated[2] = innovations[2];
  c_st.site = &tmb_emlrtRSI;
  c_EKFCorrector_correctStateAndC(&c_st, dv, P, innovations, Pxy, b_dHdx, dHdx,
                                  gain);
  for (i = 0; i < 6; i++) {
    filter->pState[i] = dv[i];
  }
  __m128d r2;
  __m128d r3;
  b_st.site = &gmb_emlrtRSI;
  c_st.site = &su_emlrtRSI;
  r = _mm_loadu_pd(&zEstimated[0]);
  r1 = _mm_loadu_pd(&b_dHdx[0]);
  r2 = _mm_set1_pd(0.0);
  r3 = _mm_set1_pd(innovations[0]);
  _mm_storeu_pd(
      &b_detections[0],
      _mm_add_pd(_mm_mul_pd(r2, r1), _mm_add_pd(r2, _mm_mul_pd(r, r3))));
  r = _mm_loadu_pd(&innovations[0]);
  _mm_storeu_pd(&a[0], _mm_mul_pd(r, r3));
  resToWrap_tmp = innovations[0] * innovations[2];
  b_detections[2] = 0.0 * b_dHdx[2] + resToWrap_tmp;
  a[2] = resToWrap_tmp;
  r = _mm_loadu_pd(&zEstimated[0]);
  r1 = _mm_loadu_pd(&b_dHdx[3]);
  r3 = _mm_set1_pd(innovations[1]);
  _mm_storeu_pd(
      &b_detections[3],
      _mm_add_pd(_mm_mul_pd(r2, r1), _mm_add_pd(r2, _mm_mul_pd(r, r3))));
  r = _mm_loadu_pd(&innovations[0]);
  _mm_storeu_pd(&a[3], _mm_mul_pd(r, r3));
  resToWrap_tmp = innovations[1] * innovations[2];
  b_detections[5] = 0.0 * b_dHdx[5] + resToWrap_tmp;
  a[5] = resToWrap_tmp;
  r = _mm_loadu_pd(&zEstimated[0]);
  r1 = _mm_loadu_pd(&b_dHdx[6]);
  r3 = _mm_set1_pd(innovations[2]);
  _mm_storeu_pd(
      &b_detections[6],
      _mm_add_pd(_mm_mul_pd(r2, r1), _mm_add_pd(r2, _mm_mul_pd(r, r3))));
  r = _mm_loadu_pd(&innovations[0]);
  _mm_storeu_pd(&a[6], _mm_mul_pd(r, r3));
  resToWrap_tmp = innovations[2] * innovations[2];
  b_detections[8] = 0.0 * b_dHdx[8] + resToWrap_tmp;
  a[8] = resToWrap_tmp;
  r = _mm_loadu_pd(&b_detections[0]);
  r1 = _mm_loadu_pd(&a[0]);
  _mm_storeu_pd(&b_detections[0], _mm_sub_pd(r, r1));
  r = _mm_loadu_pd(&b_detections[2]);
  r1 = _mm_loadu_pd(&a[2]);
  _mm_storeu_pd(&b_detections[2], _mm_sub_pd(r, r1));
  r = _mm_loadu_pd(&b_detections[4]);
  r1 = _mm_loadu_pd(&a[4]);
  _mm_storeu_pd(&b_detections[4], _mm_sub_pd(r, r1));
  r = _mm_loadu_pd(&b_detections[6]);
  r1 = _mm_loadu_pd(&a[6]);
  _mm_storeu_pd(&b_detections[6], _mm_sub_pd(r, r1));
  b_detections[8] -= resToWrap_tmp;
  for (b_i = 0; b_i < 6; b_i++) {
    real_T d;
    real_T d1;
    resToWrap_tmp = gain[b_i];
    d = gain[b_i + 6];
    d1 = gain[b_i + 12];
    for (i1 = 0; i1 < 3; i1++) {
      Pxy[b_i + 6 * i1] = (resToWrap_tmp * b_detections[3 * i1] +
                           d * b_detections[3 * i1 + 1]) +
                          d1 * b_detections[3 * i1 + 2];
    }
    resToWrap_tmp = Pxy[b_i];
    d = Pxy[b_i + 6];
    d1 = Pxy[b_i + 12];
    for (i1 = 0; i1 < 6; i1++) {
      i = b_i + 6 * i1;
      b_a[i] = P[i] + ((resToWrap_tmp * gain[i1] + d * gain[i1 + 6]) +
                       d1 * gain[i1 + 12]);
    }
  }
  d_st.site = &su_emlrtRSI;
  cholPSD(&d_st, b_a, b_value);
  for (b_i = 0; b_i < 36; b_i++) {
    filter->pSqrtStateCovariance[b_i] = b_value[b_i];
  }
  filter->pIsSetStateCovariance = true;
  filter->pSqrtStateCovarianceScalar = -1.0;
  filter->pHasPrediction = false;
  b_st.site = &hmb_emlrtRSI;
  if (!filter->pIsInitialized) {
    filter->pIsDistributionsSetup = true;
  }
  b_st.site = &imb_emlrtRSI;
  filter->pWasRetrodicted = false;
  q0 = track->pAge;
  qY = q0 + 1U;
  if (q0 + 1U < q0) {
    qY = MAX_uint32_T;
  }
  track->pAge = qY;
  track->UpdateTime = detections->Time;
  st.site = &qlb_emlrtRSI;
  b_st.site = &knb_emlrtRSI;
  c_st.site = &vi_emlrtRSI;
  i_sumColumnB();
  b_st.site = &knb_emlrtRSI;
  c_st.site = &vi_emlrtRSI;
  j_sumColumnB();
  track->pIsCoasted = false;
  b_st.site = &lnb_emlrtRSI;
  obj = track->TrackLogic;
  if (obj->pIsFirstUpdate) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &ad_emlrtRTEI,
        "shared_tracking:trackHistoryLogic:notInitialized",
        "shared_tracking:trackHistoryLogic:notInitialized", 3, 4, 3, "hit");
  }
  bv[0] = true;
  for (b_i = 0; b_i < 49; b_i++) {
    bv[b_i + 1] = obj->pRecentHistory[b_i];
  }
  for (b_i = 0; b_i < 50; b_i++) {
    obj->pRecentHistory[b_i] = bv[b_i];
  }
  obj->pIsFirstUpdate = false;
  if (!track->IsConfirmed) {
    st.site = &rlb_emlrtRSI;
    track->IsConfirmed = ObjectTrack_checkPromotion(track);
  }
}

void ObjectTrack_nullify(const emlrtStack *sp,
                         d_matlabshared_tracking_interna *track)
{
  emlrtStack st;
  trackHistoryLogic *obj;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  track->BranchID = 0U;
  track->TrackID = 0U;
  track->IsConfirmed = false;
  track->ObjectClassID = 0.0;
  for (i = 0; i < 20; i++) {
    track->pUsedObjectAttributes[i] = false;
  }
  track->UpdateTime = 0.0;
  track->Time = 0.0;
  track->pAge = 0U;
  track->pIsCoasted = true;
  obj = track->TrackLogic;
  for (i = 0; i < 50; i++) {
    obj->pRecentHistory[i] = false;
  }
  obj->pIsFirstUpdate = true;
  st.site = &ou_emlrtRSI;
  trackingEKF_nullify(&st, track->Filter);
  st.site = &pu_emlrtRSI;
  trackingEKF_nullify(&st, track->pDistanceFilter);
}

void ObjectTrack_predict(const emlrtStack *sp,
                         d_matlabshared_tracking_interna *track, real_T b_time)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T dt;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dgb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &jc_emlrtRSI;
  if (b_time < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:predict:expectedNonnegative", 3, 4, 4, "time");
  }
  b_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsInf(b_time) || muDoubleScalarIsNaN(b_time)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:predict:expectedFinite", 3, 4, 4, "time");
  }
  st.site = &egb_emlrtRSI;
  dt = b_time - track->Time;
  if (!(dt <= 0.0)) {
    st.site = &fgb_emlrtRSI;
    predictTrackFilter(&st, track->Filter, dt);
    track->Time = b_time;
  }
}

void ObjectTrack_trackToStruct(const emlrtStack *sp,
                               d_matlabshared_tracking_interna *track,
                               struct1_T *trackStruct)
{
  static const char_T logicType[7] = {'H', 'i', 's', 't', 'o', 'r', 'y'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  trackHistoryLogic *b_obj;
  trackingEKF *obj;
  real_T b_a[36];
  real_T dv[36];
  real_T a;
  real_T t0_ObjectClassID;
  real_T t0_UpdateTime;
  int32_T i;
  int32_T k;
  int32_T sz2;
  uint32_T t0_Age;
  uint32_T t0_BranchID;
  uint32_T t0_TrackID;
  boolean_T varargin_1[20];
  boolean_T exitg1;
  boolean_T t0_IsCoasted;
  boolean_T t0_IsConfirmed;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  t0_TrackID = track->TrackID;
  t0_BranchID = track->BranchID;
  t0_UpdateTime = track->Time;
  t0_Age = track->pAge;
  st.site = &bpb_emlrtRSI;
  b_st.site = &gy_emlrtRSI;
  obj = track->Filter;
  for (i = 0; i < 6; i++) {
    trackStruct->State[i] = obj->pState[i];
  }
  st.site = &cpb_emlrtRSI;
  b_st.site = &apb_emlrtRSI;
  obj = track->Filter;
  if ((!obj->pIsSetStateCovariance) ||
      (obj->pSqrtStateCovarianceScalar != -1.0)) {
    a = obj->pSqrtStateCovarianceScalar;
    for (sz2 = 0; sz2 < 36; sz2++) {
      obj->pSqrtStateCovariance[sz2] = a * (real_T)iv2[sz2];
    }
    obj->pIsSetStateCovariance = true;
    obj->pSqrtStateCovarianceScalar = -1.0;
  }
  for (sz2 = 0; sz2 < 36; sz2++) {
    dv[sz2] = obj->pSqrtStateCovariance[sz2];
  }
  for (sz2 = 0; sz2 < 36; sz2++) {
    b_a[sz2] = obj->pSqrtStateCovariance[sz2];
  }
  t0_ObjectClassID = track->ObjectClassID;
  st.site = &dpb_emlrtRSI;
  b_obj = track->TrackLogic;
  b_st.site = &gpb_emlrtRSI;
  for (sz2 = 0; sz2 < 10; sz2++) {
    trackStruct->TrackLogicState[sz2] = b_obj->pRecentHistory[sz2];
  }
  t0_IsConfirmed = track->IsConfirmed;
  st.site = &epb_emlrtRSI;
  t0_IsCoasted = track->pIsCoasted;
  trackStruct->TrackID = t0_TrackID;
  trackStruct->BranchID = t0_BranchID;
  trackStruct->SourceIndex = 0U;
  trackStruct->UpdateTime = t0_UpdateTime;
  trackStruct->Age = t0_Age;
  for (sz2 = 0; sz2 < 6; sz2++) {
    for (i = 0; i < 6; i++) {
      a = 0.0;
      for (k = 0; k < 6; k++) {
        a += b_a[sz2 + 6 * k] * dv[i + 6 * k];
      }
      trackStruct->StateCovariance[sz2 + 6 * i] = a;
    }
  }
  trackStruct->ObjectClassID = t0_ObjectClassID;
  trackStruct->ObjectClassProbabilities = 1.0;
  for (sz2 = 0; sz2 < 7; sz2++) {
    trackStruct->TrackLogic[sz2] = logicType[sz2];
  }
  trackStruct->IsConfirmed = t0_IsConfirmed;
  trackStruct->IsCoasted = t0_IsCoasted;
  trackStruct->IsSelfReported = true;
  st.site = &fpb_emlrtRSI;
  b_st.site = &hpb_emlrtRSI;
  for (i = 0; i < 20; i++) {
    varargin_1[i] = track->pUsedObjectAttributes[i];
  }
  c_st.site = &ipb_emlrtRSI;
  t0_IsConfirmed = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 20)) {
    if (varargin_1[k]) {
      t0_IsConfirmed = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (t0_IsConfirmed) {
    trackStruct->ObjectAttributes.size[0] = 1;
    trackStruct->ObjectAttributes.size[1] = 0;
  } else {
    i = 0;
    sz2 = 0;
    for (k = 0; k < 20; k++) {
      if (i < 1) {
        i = 1;
      }
      if (varargin_1[k]) {
        sz2++;
      }
    }
    if (sz2 > i * 20) {
      emlrtErrorWithMessageIdR2018a(&c_st, &kd_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    trackStruct->ObjectAttributes.size[0] = 1;
    trackStruct->ObjectAttributes.size[1] = sz2;
  }
}

real_T c_ObjectTrack_calcCostOneDetect(const emlrtStack *sp,
                                       d_matlabshared_tracking_interna *track,
                                       const real_T detection_Measurement[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  trackingEKF *EKF;
  real_T b_a[36];
  real_T d_a[36];
  real_T dv[36];
  real_T b_dHdx[18];
  real_T dHdx[18];
  real_T c_a[9];
  real_T e_a[9];
  real_T residualCovariance[9];
  real_T v[9];
  real_T b_value[6];
  real_T Y[3];
  real_T zEstimated[3];
  real_T a;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &teb_emlrtRSI;
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
  EKF = track->pDistanceFilter;
  b_st.site = &ueb_emlrtRSI;
  c_st.site = &xeb_emlrtRSI;
  d_st.site = &jc_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 3)) {
    if ((!muDoubleScalarIsInf(detection_Measurement[i])) &&
        (!muDoubleScalarIsNaN(detection_Measurement[i]))) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:trackingEKF:expectedFinite", 3, 4, 8, "z_matrix");
  }
  b_st.site = &veb_emlrtRSI;
  c_ExtendedKalmanFilter_validate(&b_st, EKF);
  b_st.site = &web_emlrtRSI;
  c_st.site = &nfb_emlrtRSI;
  for (i = 0; i < 6; i++) {
    b_value[i] = EKF->pState[i];
  }
  c_st.site = &nfb_emlrtRSI;
  cvmeasjac(&c_st, b_value, dHdx);
  c_st.site = &ofb_emlrtRSI;
  c_st.site = &pfb_emlrtRSI;
  for (i = 0; i < 6; i++) {
    b_value[i] = EKF->pState[i];
  }
  c_st.site = &pfb_emlrtRSI;
  cvmeas(&c_st, b_value, zEstimated);
  c_st.site = &qfb_emlrtRSI;
  d_st.site = &hv_emlrtRSI;
  if ((!EKF->pIsSetStateCovariance) ||
      (EKF->pSqrtStateCovarianceScalar != -1.0)) {
    a = EKF->pSqrtStateCovarianceScalar;
    e_st.site = &jv_emlrtRSI;
    for (b_i = 0; b_i < 36; b_i++) {
      EKF->pSqrtStateCovariance[b_i] = a * (real_T)iv2[b_i];
    }
    EKF->pIsSetStateCovariance = true;
    EKF->pSqrtStateCovarianceScalar = -1.0;
  }
  d_st.site = &iv_emlrtRSI;
  for (b_i = 0; b_i < 36; b_i++) {
    dv[b_i] = EKF->pSqrtStateCovariance[b_i];
  }
  for (b_i = 0; b_i < 36; b_i++) {
    b_a[b_i] = EKF->pSqrtStateCovariance[b_i];
  }
  c_st.site = &qfb_emlrtRSI;
  d_st.site = &kv_emlrtRSI;
  if ((!EKF->pIsSetMeasurementNoise) ||
      (EKF->pSqrtMeasurementNoiseScalar != -1.0)) {
    a = EKF->pSqrtMeasurementNoiseScalar;
    e_st.site = &mv_emlrtRSI;
    for (b_i = 0; b_i < 9; b_i++) {
      EKF->pSqrtMeasurementNoise[b_i] = a * (real_T)iv1[b_i];
    }
    EKF->pIsSetMeasurementNoise = true;
    EKF->pSqrtMeasurementNoiseScalar = -1.0;
  }
  d_st.site = &lv_emlrtRSI;
  for (b_i = 0; b_i < 9; b_i++) {
    v[b_i] = EKF->pSqrtMeasurementNoise[b_i];
  }
  for (b_i = 0; b_i < 9; b_i++) {
    c_a[b_i] = EKF->pSqrtMeasurementNoise[b_i];
  }
  for (b_i = 0; b_i < 6; b_i++) {
    for (i1 = 0; i1 < 6; i1++) {
      a = 0.0;
      for (i = 0; i < 6; i++) {
        a += b_a[b_i + 6 * i] * dv[i1 + 6 * i];
      }
      d_a[b_i + 6 * i1] = a;
    }
  }
  for (b_i = 0; b_i < 3; b_i++) {
    for (i1 = 0; i1 < 6; i1++) {
      a = 0.0;
      for (i = 0; i < 6; i++) {
        a += dHdx[b_i + 3 * i] * d_a[i + 6 * i1];
      }
      b_dHdx[b_i + 3 * i1] = a;
    }
    for (i1 = 0; i1 < 3; i1++) {
      a = 0.0;
      for (i = 0; i < 6; i++) {
        a += b_dHdx[b_i + 3 * i] * dHdx[i1 + 3 * i];
      }
      i = b_i + 3 * i1;
      residualCovariance[i] = a;
      e_a[i] = (c_a[b_i] * v[i1] + c_a[b_i + 3] * v[i1 + 3]) +
               c_a[b_i + 6] * v[i1 + 6];
    }
  }
  __m128d r;
  __m128d r1;
  r = _mm_loadu_pd(&residualCovariance[0]);
  r1 = _mm_loadu_pd(&e_a[0]);
  _mm_storeu_pd(&residualCovariance[0], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&residualCovariance[2]);
  r1 = _mm_loadu_pd(&e_a[2]);
  _mm_storeu_pd(&residualCovariance[2], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&residualCovariance[4]);
  r1 = _mm_loadu_pd(&e_a[4]);
  _mm_storeu_pd(&residualCovariance[4], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&residualCovariance[6]);
  r1 = _mm_loadu_pd(&e_a[6]);
  _mm_storeu_pd(&residualCovariance[6], _mm_add_pd(r, r1));
  residualCovariance[8] += e_a[8];
  c_st.site = &rfb_emlrtRSI;
  d_st.site = &sfb_emlrtRSI;
  r = _mm_loadu_pd(&zEstimated[0]);
  _mm_storeu_pd(&zEstimated[0],
                _mm_sub_pd(_mm_loadu_pd(&detection_Measurement[0]), r));
  zEstimated[2] = detection_Measurement[2] - zEstimated[2];
  e_st.site = &tfb_emlrtRSI;
  f_st.site = &gcb_emlrtRSI;
  b_mrdiv(&f_st, zEstimated, residualCovariance, Y);
  e_st.site = &ufb_emlrtRSI;
  f_st.site = &vfb_emlrtRSI;
  g_st.site = &vfb_emlrtRSI;
  a = det(&g_st, residualCovariance);
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &ec_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
  }
  a = muDoubleScalarLog(a);
  if (muDoubleScalarIsInf(a) || muDoubleScalarIsNaN(a)) {
    real_T d[3];
    f_st.site = &wfb_emlrtRSI;
    b_cholPSD(&f_st, residualCovariance, v);
    d[0] = v[0];
    d[1] = v[4];
    d[2] = v[8];
    f_st.site = &wfb_emlrtRSI;
    p = false;
    for (i = 0; i < 3; i++) {
      if (p || (d[i] < 0.0)) {
        p = true;
      }
    }
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &f_st, &ec_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
    }
    d[0] = muDoubleScalarLog(v[0]);
    d[1] = muDoubleScalarLog(v[4]);
    d[2] = muDoubleScalarLog(v[8]);
    f_st.site = &wfb_emlrtRSI;
    a = h_sumColumnB(d);
    a *= 2.0;
  }
  return ((Y[0] * zEstimated[0] + Y[1] * zEstimated[1]) +
          Y[2] * zEstimated[2]) +
         a;
}

void c_ObjectTrack_setAttributesFrom(const emlrtStack *sp,
                                     d_matlabshared_tracking_interna *track,
                                     real_T detection_SensorIndex,
                                     const uint32_T usedSensors[20])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T tmp_data[20];
  int32_T tmp_size[2];
  int32_T i;
  int32_T loop_ub;
  uint32_T ind_data[20];
  boolean_T b_detection_SensorIndex[20];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (i = 0; i < 20; i++) {
    b_detection_SensorIndex[i] = (detection_SensorIndex == usedSensors[i]);
  }
  d_eml_find(b_detection_SensorIndex, tmp_data, tmp_size);
  loop_ub = tmp_size[1];
  for (i = 0; i < loop_ub; i++) {
    int32_T i1;
    i1 = tmp_data[i];
    if (i1 < 0) {
      i1 = 0;
    }
    ind_data[i] = (uint32_T)i1;
  }
  st.site = &slb_emlrtRSI;
  b_st.site = &tlb_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  if (tmp_size[1] != 1) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &t_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:MultiObjectTracker:expectedScalar", 3, 4, 27,
        "objectDetection.SensorIndex");
  }
  b_st.site = &ulb_emlrtRSI;
  track->pUsedObjectAttributes[(int32_T)ind_data[0] - 1] = true;
}

void c_ObjectTrack_sortDetectionsByT(const emlrtStack *sp,
                                     const emxArray_objectDetection *detections,
                                     const emxArray_uint32_T *detectionIndices,
                                     emxArray_int32_T *sorting)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *iidx;
  emxArray_real_T *detTimes;
  const objectDetection *detections_data;
  real_T *detTimes_data;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T *sorting_data;
  const uint32_T *detectionIndices_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  detectionIndices_data = detectionIndices->data;
  detections_data = detections->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &qcb_emlrtRSI;
  repmat(&st, detectionIndices->size[1], sorting);
  if ((detections->size[0] != 0) && (detections->size[1] != 0)) {
    int32_T loop_ub;
    i = detections->size[0] * detections->size[1] - 1;
    if (i < 0) {
      emlrtDynamicBoundsCheckR2012b(0, 0, i, &cf_emlrtBCI, (emlrtConstCTX)sp);
    }
    emxInit_real_T(sp, &detTimes, 1, &tk_emlrtRTEI, true);
    i1 = detTimes->size[0];
    detTimes->size[0] = detectionIndices->size[1];
    emxEnsureCapacity_real_T(sp, detTimes, i1, &tk_emlrtRTEI);
    detTimes_data = detTimes->data;
    loop_ub = detectionIndices->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      detTimes_data[i1] = 0.0;
    }
    i1 = detectionIndices->size[1];
    for (b_i = 0; b_i < i1; b_i++) {
      if (b_i + 1 > detectionIndices->size[1]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, detectionIndices->size[1],
                                      &ef_emlrtBCI, (emlrtConstCTX)sp);
      }
      loop_ub = (int32_T)detectionIndices_data[b_i] - 1;
      if ((loop_ub < 0) || (loop_ub > i)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i, &df_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (b_i + 1 > detTimes->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, detTimes->size[0],
                                      &ff_emlrtBCI, (emlrtConstCTX)sp);
      }
      detTimes_data[b_i] = detections_data[loop_ub].Time;
    }
    st.site = &rcb_emlrtRSI;
    emxInit_int32_T(&st, &iidx, 1, &vk_emlrtRTEI);
    b_st.site = &sx_emlrtRSI;
    f_sort(&b_st, detTimes, iidx);
    sorting_data = iidx->data;
    i = detTimes->size[0];
    detTimes->size[0] = iidx->size[0];
    emxEnsureCapacity_real_T(&st, detTimes, i, &nk_emlrtRTEI);
    detTimes_data = detTimes->data;
    loop_ub = iidx->size[0];
    for (i = 0; i < loop_ub; i++) {
      detTimes_data[i] = sorting_data[i];
    }
    emxFree_int32_T(&st, &iidx);
    if (detTimes->size[0] != sorting->size[1]) {
      emlrtSubAssignSizeCheck1dR2017a(sorting->size[1], detTimes->size[0],
                                      &u_emlrtECI, (emlrtConstCTX)sp);
    }
    loop_ub = sorting->size[1];
    i = sorting->size[0] * sorting->size[1];
    sorting->size[0] = 1;
    sorting->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(sp, sorting, i, &uk_emlrtRTEI);
    sorting_data = sorting->data;
    for (i = 0; i < loop_ub; i++) {
      sorting_data[i] = (int32_T)detTimes_data[i];
    }
    emxFree_real_T(sp, &detTimes);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (ObjectTrack.c) */
