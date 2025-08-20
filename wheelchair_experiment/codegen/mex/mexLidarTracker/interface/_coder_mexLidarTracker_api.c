/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mexLidarTracker_api.c
 *
 * Code generation for function '_coder_mexLidarTracker_api'
 *
 */

/* Include files */
#include "_coder_mexLidarTracker_api.h"
#include "mexLidarTracker.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_internal_types.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo ao_emlrtRTEI = {
    1,                            /* lineNo */
    1,                            /* colNo */
    "_coder_mexLidarTracker_api", /* fName */
    ""                            /* pName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *ptCloudLocations,
                               const char_T *identifier, emxArray_real32_T *y);

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const struct1_T u_data[],
                                          const int32_T u_size);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y);

static const mxArray *d_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size[2]);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_time,
                                 const char_T *identifier);

static const mxArray *e_emlrt_marshallOut(const real32_T u);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_objectDetection *u);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *f_emlrt_marshallOut(const emxArray_uint32_T *u);

static struct0_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Plant,
                                    const char_T *identifier);

static struct0_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *wall,
                                   const char_T *identifier))[6];

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[6];

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real32_T *ret);

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6];

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *ptCloudLocations,
                               const char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(ptCloudLocations), &thisId, y);
  emlrtDestroyArray(&ptCloudLocations);
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const struct1_T u_data[],
                                          const int32_T u_size)
{
  static const int32_T b_iv1[2] = {6, 6};
  static const int32_T b_iv2[2] = {1, 7};
  static const int32_T iv3[2] = {1, 10};
  static const int32_T b_i = 6;
  static const char_T *sv[16] = {"TrackID",
                                 "BranchID",
                                 "SourceIndex",
                                 "UpdateTime",
                                 "Age",
                                 "State",
                                 "StateCovariance",
                                 "StateParameters",
                                 "ObjectClassID",
                                 "ObjectClassProbabilities",
                                 "TrackLogic",
                                 "TrackLogicState",
                                 "IsConfirmed",
                                 "IsCoasted",
                                 "IsSelfReported",
                                 "ObjectAttributes"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *y;
  real_T *pData;
  int32_T b_iv[2];
  int32_T b_j0;
  int32_T c_i;
  int32_T d_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y,
              emlrtCreateStructArray(1, &u_size, 16, (const char_T **)&sv[0]));
  emlrtCreateField(y, "TrackID");
  emlrtCreateField(y, "BranchID");
  emlrtCreateField(y, "SourceIndex");
  emlrtCreateField(y, "UpdateTime");
  emlrtCreateField(y, "Age");
  emlrtCreateField(y, "State");
  emlrtCreateField(y, "StateCovariance");
  emlrtCreateField(y, "StateParameters");
  emlrtCreateField(y, "ObjectClassID");
  emlrtCreateField(y, "ObjectClassProbabilities");
  emlrtCreateField(y, "TrackLogic");
  emlrtCreateField(y, "TrackLogicState");
  emlrtCreateField(y, "IsConfirmed");
  emlrtCreateField(y, "IsCoasted");
  emlrtCreateField(y, "IsSelfReported");
  emlrtCreateField(y, "ObjectAttributes");
  i = 0;
  if (u_size > 0) {
    b_iv[0] = 1;
  }
  for (b_j0 = 0; b_j0 < u_size; b_j0++) {
    int32_T i1;
    b_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j0].TrackID;
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, "TrackID", b_y, 0);
    c_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j0].BranchID;
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, "BranchID", c_y, 1);
    d_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j0].SourceIndex;
    emlrtAssign(&d_y, m);
    emlrtSetFieldR2017b(y, i, "SourceIndex", d_y, 2);
    e_y = NULL;
    m = emlrtCreateDoubleScalar(u_data[b_j0].UpdateTime);
    emlrtAssign(&e_y, m);
    emlrtSetFieldR2017b(y, i, "UpdateTime", e_y, 3);
    f_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j0].Age;
    emlrtAssign(&f_y, m);
    emlrtSetFieldR2017b(y, i, "Age", f_y, 4);
    g_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&b_i, mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    for (c_i = 0; c_i < 6; c_i++) {
      pData[c_i] = u_data[b_j0].State[c_i];
    }
    emlrtAssign(&g_y, m);
    emlrtSetFieldR2017b(y, i, "State", g_y, 5);
    h_y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&b_iv1[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    for (c_i = 0; c_i < 6; c_i++) {
      for (d_i = 0; d_i < 6; d_i++) {
        pData[i1 + d_i] = u_data[b_j0].StateCovariance[d_i + 6 * c_i];
      }
      i1 += 6;
    }
    emlrtAssign(&h_y, m);
    emlrtSetFieldR2017b(y, i, "StateCovariance", h_y, 6);
    i_y = NULL;
    emlrtAssign(&i_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
    emlrtSetFieldR2017b(y, i, "StateParameters", i_y, 7);
    j_y = NULL;
    m = emlrtCreateDoubleScalar(u_data[b_j0].ObjectClassID);
    emlrtAssign(&j_y, m);
    emlrtSetFieldR2017b(y, i, "ObjectClassID", j_y, 8);
    k_y = NULL;
    m = emlrtCreateDoubleScalar(u_data[b_j0].ObjectClassProbabilities);
    emlrtAssign(&k_y, m);
    emlrtSetFieldR2017b(y, i, "ObjectClassProbabilities", k_y, 9);
    l_y = NULL;
    m = emlrtCreateCharArray(2, &b_iv2[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 7, m,
                             &u_data[b_j0].TrackLogic[0]);
    emlrtAssign(&l_y, m);
    emlrtSetFieldR2017b(y, i, "TrackLogic", l_y, 10);
    m_y = NULL;
    m = emlrtCreateLogicalArray(2, &iv3[0]);
    emlrtInitLogicalArray(10, m, &u_data[b_j0].TrackLogicState[0]);
    emlrtAssign(&m_y, m);
    emlrtSetFieldR2017b(y, i, "TrackLogicState", m_y, 11);
    n_y = NULL;
    m = emlrtCreateLogicalScalar(u_data[b_j0].IsConfirmed);
    emlrtAssign(&n_y, m);
    emlrtSetFieldR2017b(y, i, "IsConfirmed", n_y, 12);
    o_y = NULL;
    m = emlrtCreateLogicalScalar(u_data[b_j0].IsCoasted);
    emlrtAssign(&o_y, m);
    emlrtSetFieldR2017b(y, i, "IsCoasted", o_y, 13);
    p_y = NULL;
    m = emlrtCreateLogicalScalar(u_data[b_j0].IsSelfReported);
    emlrtAssign(&p_y, m);
    emlrtSetFieldR2017b(y, i, "IsSelfReported", p_y, 14);
    q_y = NULL;
    b_iv[1] = u_data[b_j0].ObjectAttributes.size[1];
    emlrtAssign(&q_y, emlrtCreateStructArray(2, &b_iv[0], 0, NULL));
    emlrtSetFieldR2017b(y, i, "ObjectAttributes", q_y, 15);
    i++;
  }
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size[2])
{
  static const int32_T b_iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u_size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_time,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(b_time), &thisId);
  emlrtDestroyArray(&b_time);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const real32_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
  *(real32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_objectDetection *u)
{
  static const int32_T b_iv1[2] = {3, 3};
  static const int32_T i1 = 3;
  const mxArray *propValues[7];
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *m6;
  const mxArray *m7;
  const mxArray *y;
  const objectDetection *u_data;
  real_T *pData;
  int32_T b_iv[2];
  int32_T b_i;
  int32_T i;
  const char_T *propClasses[7] = {"objectDetection", "objectDetection",
                                  "objectDetection", "objectDetection",
                                  "objectDetection", "objectDetection",
                                  "objectDetection"};
  const char_T *propNames[7] = {"Time",
                                "Measurement",
                                "SensorIndex",
                                "ObjectClassID",
                                "MeasurementParameters",
                                "ObjectAttributes",
                                "pMeasurementNoise"};
  u_data = u->data;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &u->size[0]));
  i = 0;
  if (u->size[0] > 0) {
    b_iv[0] = 0;
    b_iv[1] = 0;
  }
  while (i < u->size[0]) {
    int32_T i2;
    b_y = NULL;
    m = NULL;
    m1 = NULL;
    m2 = NULL;
    m3 = NULL;
    m4 = NULL;
    m5 = NULL;
    m6 = NULL;
    emlrtAssign(&b_y,
                emlrtCreateClassInstance2022a((emlrtCTX)sp, "objectDetection"));
    m = NULL;
    c_y = NULL;
    m7 = emlrtCreateDoubleScalar(u_data[i].Time);
    emlrtAssign(&c_y, m7);
    emlrtAssign(&m, c_y);
    propValues[0] = m;
    m1 = NULL;
    d_y = NULL;
    m7 = emlrtCreateNumericArray(1, (const void *)&i1, mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m7);
    pData[0] = u_data[i].Measurement[0];
    pData[1] = u_data[i].Measurement[1];
    pData[2] = u_data[i].Measurement[2];
    emlrtAssign(&d_y, m7);
    emlrtAssign(&m1, d_y);
    propValues[1] = m1;
    m2 = NULL;
    e_y = NULL;
    m7 = emlrtCreateDoubleScalar(u_data[i].SensorIndex);
    emlrtAssign(&e_y, m7);
    emlrtAssign(&m2, e_y);
    propValues[2] = m2;
    m3 = NULL;
    f_y = NULL;
    m7 = emlrtCreateDoubleScalar(u_data[i].ObjectClassID);
    emlrtAssign(&f_y, m7);
    emlrtAssign(&m3, f_y);
    propValues[3] = m3;
    m4 = NULL;
    g_y = NULL;
    emlrtAssign(&g_y, emlrtCreateCellArrayR2014a(2, &b_iv[0]));
    emlrtAssign(&m4, g_y);
    propValues[4] = m4;
    m5 = NULL;
    h_y = NULL;
    emlrtAssign(&h_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
    emlrtAssign(&m5, h_y);
    propValues[5] = m5;
    m6 = NULL;
    i_y = NULL;
    m7 = emlrtCreateNumericArray(2, (const void *)&b_iv1[0], mxDOUBLE_CLASS,
                                 mxREAL);
    pData = emlrtMxGetPr(m7);
    i2 = 0;
    for (b_i = 0; b_i < 3; b_i++) {
      pData[i2] = u_data[i].pMeasurementNoise[3 * b_i];
      pData[i2 + 1] = u_data[i].pMeasurementNoise[3 * b_i + 1];
      pData[i2 + 2] = u_data[i].pMeasurementNoise[3 * b_i + 2];
      i2 += 3;
    }
    emlrtAssign(&i_y, m7);
    emlrtAssign(&m6, i_y);
    propValues[6] = m6;
    emlrtSetAllProperties((emlrtCTX)sp, &b_y, 0, 7,
                          (const char_T **)&propNames[0],
                          (const char_T **)&propClasses[0], &propValues[0]);
    emlrtAssign(&b_y, emlrtConvertInstanceToRedirectSource((emlrtCTX)sp, b_y, 0,
                                                           "objectDetection"));
    emlrtSetCell(y, i, b_y);
    i++;
  }
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const emxArray_uint32_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  const uint32_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxUINT32_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  emlrtAssign(&y, m);
  return y;
}

static struct0_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Plant,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  struct0_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(Plant), &thisId);
  emlrtDestroyArray(&Plant);
  return y;
}

static struct0_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = {"X", "Y", "yaw"};
  emlrtMsgIdentifier thisId;
  struct0_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 3,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "X";
  y.X = f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "X")),
      &thisId);
  thisId.fIdentifier = "Y";
  y.Y = f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "Y")),
      &thisId);
  thisId.fIdentifier = "yaw";
  y.yaw = f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "yaw")),
      &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *wall,
                                   const char_T *identifier))[6]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[6];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(wall), &thisId);
  emlrtDestroyArray(&wall);
  return y;
}

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[6]
{
  real_T(*y)[6];
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real32_T *ret)
{
  static const int32_T dims[2] = {16000, 3};
  int32_T b_iv[2];
  int32_T i;
  boolean_T bv[2] = {true, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret->allocatedSize = b_iv[0] * b_iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = b_iv[0];
  ret->size[1] = b_iv[1];
  emxEnsureCapacity_real32_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6]
{
  static const int32_T dims[2] = {3, 2};
  real_T(*ret)[6];
  int32_T b_iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[6])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void mexLidarTracker_api(const mxArray *const prhs[6], int32_T nlhs,
                         const mxArray *plhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_objectDetection *detections;
  emxArray_real32_T *ptCloudLocations;
  emxArray_real_T *croppedIndices;
  emxArray_real_T *obstacleIndices;
  emxArray_struct1_T_30 confirmedTracks;
  emxArray_uint32_T *labels;
  struct0_T Plant;
  real_T(*modelProbs_data)[60];
  real_T(*wall)[6];
  real_T SP;
  real_T axis;
  real_T b_time;
  int32_T modelProbs_size[2];
  real32_T numClusters;
  st.tls = emlrtRootTLSGlobal;
  modelProbs_data = (real_T(*)[60])mxMalloc(sizeof(real_T[60]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emxInit_real32_T(&st, &ptCloudLocations, 2, &ao_emlrtRTEI);
  ptCloudLocations->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "ptCloudLocations",
                     ptCloudLocations);
  b_time = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "time");
  Plant = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "Plant");
  wall = i_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "wall");
  axis = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "axis");
  SP = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "SP");
  /* Invoke the target function */
  emxInit_objectDetection(&st, &detections, 2, &ao_emlrtRTEI, true);
  emxInit_real_T(&st, &obstacleIndices, 1, &ao_emlrtRTEI, true);
  emxInit_real_T(&st, &croppedIndices, 1, &ao_emlrtRTEI, true);
  emxInit_uint32_T(&st, &labels, 1, &ao_emlrtRTEI, true);
  mexLidarTracker(&st, ptCloudLocations, b_time, &Plant, *wall, axis, SP,
                  detections, obstacleIndices, croppedIndices,
                  confirmedTracks.data, confirmedTracks.size, *modelProbs_data,
                  modelProbs_size, &numClusters, labels);
  emxFree_real32_T(&st, &ptCloudLocations);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, detections);
  emxFree_objectDetection(&st, &detections);
  if (nlhs > 1) {
    obstacleIndices->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(obstacleIndices);
  }
  emxFree_real_T(&st, &obstacleIndices);
  if (nlhs > 2) {
    croppedIndices->canFreeData = false;
    plhs[2] = b_emlrt_marshallOut(croppedIndices);
  }
  emxFree_real_T(&st, &croppedIndices);
  if (nlhs > 3) {
    plhs[3] =
        c_emlrt_marshallOut(&st, confirmedTracks.data, confirmedTracks.size[0]);
  }
  if (nlhs > 4) {
    plhs[4] = d_emlrt_marshallOut(*modelProbs_data, modelProbs_size);
  }
  if (nlhs > 5) {
    plhs[5] = e_emlrt_marshallOut(numClusters);
  }
  if (nlhs > 6) {
    labels->canFreeData = false;
    plhs[6] = f_emlrt_marshallOut(labels);
  }
  emxFree_uint32_T(&st, &labels);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_mexLidarTracker_api.c) */
