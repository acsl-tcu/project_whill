//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_EvaluationPath_GPU_api.cu
//
// Code generation for function '_coder_EvaluationPath_GPU_api'
//

// Include files
#include "_coder_EvaluationPath_GPU_api.h"
#include "EvaluationPath_GPU.h"
#include "EvaluationPath_GPU_data.h"
#include "EvaluationPath_GPU_emxutil.h"
#include "EvaluationPath_GPU_types.h"
#include "rt_nonfinite.h"

// Variable Definitions
static const int32_T iv[3]{2, 21, 1000};

// Function Declarations
static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[84000]);

static real_T (*b_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[63000];

static real_T (*b_emlrt_marshallIn(const mxArray *pu,
                                   const char_T *identifier))[42000];

static void c_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[42000]);

static real_T (*c_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[42000];

static real_T d_emlrt_marshallIn(const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void d_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static void e_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[84000]);

static real_T (*e_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[63000];

static void emlrt_marshallIn(const mxArray *obj, const char_T *identifier,
                             struct0_T *y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T *y);

static real_T emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static real_T (*emlrt_marshallIn(const mxArray *px,
                                 const char_T *identifier))[63000];

static void emlrt_marshallIn(const mxArray *preobs, const char_T *identifier,
                             cell_wrap_0 y[22]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             cell_wrap_0 y[22]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[2]);

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

static const mxArray *emlrt_marshallOut(const emxArray_boolean_T *u);

static void f_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[42000]);

static real_T (*f_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[42000];

// Function Definitions
static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[84000])
{
  e_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*b_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[63000]
{
  real_T(*y)[63000];
  y = e_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*b_emlrt_marshallIn(const mxArray *pu,
                                   const char_T *identifier))[42000]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[42000];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(emlrtAlias(pu), &thisId);
  emlrtDestroyArray(&pu);
  return y;
}

static void c_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[42000])
{
  f_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*c_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[42000]
{
  real_T(*y)[42000];
  y = f_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T d_emlrt_marshallIn(const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void d_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2]{1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[84000])
{
  static const int32_T dims[3]{4, 21, 1000};
  real_T(*r)[84000];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 3U,
                          (void *)&dims[0]);
  r = (real_T(*)[84000])emlrtMxGetData(src);
  for (int32_T i{0}; i < 84000; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T (*e_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[63000]
{
  static const int32_T dims[3]{3, 21, 1000};
  real_T(*ret)[63000];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 3U,
                          (void *)&dims[0]);
  ret = (real_T(*)[63000])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void emlrt_marshallIn(const mxArray *obj, const char_T *identifier,
                             struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(obj), &thisId, y);
  emlrtDestroyArray(&obj);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[10]{"K", "NP", "ObsNum", "r_wheel", "r_obs",
                                      "R", "W",  "Vref",   "limit",   "target"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 10,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "K";
  y->K =
      emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                      0, (const char_T *)"K")),
                       &thisId);
  thisId.fIdentifier = "NP";
  y->NP =
      emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                      1, (const char_T *)"NP")),
                       &thisId);
  thisId.fIdentifier = "ObsNum";
  y->ObsNum = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                     (const char_T *)"ObsNum")),
      &thisId);
  thisId.fIdentifier = "r_wheel";
  y->r_wheel = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3,
                                     (const char_T *)"r_wheel")),
      &thisId);
  thisId.fIdentifier = "r_obs";
  y->r_obs = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4,
                                     (const char_T *)"r_obs")),
      &thisId);
  thisId.fIdentifier = "R";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5,
                                                  (const char_T *)"R")),
                   &thisId, y->R);
  thisId.fIdentifier = "W";
  y->W =
      emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                      6, (const char_T *)"W")),
                       &thisId);
  thisId.fIdentifier = "Vref";
  y->Vref = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 7,
                                     (const char_T *)"Vref")),
      &thisId);
  thisId.fIdentifier = "limit";
  b_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 8,
                                                    (const char_T *)"limit")),
                     &thisId, y->limit);
  thisId.fIdentifier = "target";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 9,
                                                    (const char_T *)"target")),
                     &thisId, y->target);
  emlrtDestroyArray(&u);
}

static real_T emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = d_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*emlrt_marshallIn(const mxArray *px,
                                 const char_T *identifier))[63000]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[63000];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(px), &thisId);
  emlrtDestroyArray(&px);
  return y;
}

static void emlrt_marshallIn(const mxArray *preobs, const char_T *identifier,
                             cell_wrap_0 y[22])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(preobs), &thisId, y);
  emlrtDestroyArray(&preobs);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             cell_wrap_0 y[22])
{
  emlrtMsgIdentifier thisId;
  int32_T b_iv[1];
  char_T str[11];
  boolean_T bv[1];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  bv[0] = false;
  b_iv[0] = 22;
  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 1U, &b_iv[0], &bv[0]);
  for (int32_T i{0}; i < 22; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    emlrt_marshallIn(
        emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, i)), &thisId,
        y[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[2])
{
  d_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T b_iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const emxArray_boolean_T *u)
{
  static const int32_T b_iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateLogicalArray(2, &b_iv[0]);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[42000])
{
  real_T(*r)[42000];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 3U, (void *)&iv[0]);
  r = (real_T(*)[42000])emlrtMxGetData(src);
  for (int32_T i{0}; i < 42000; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T (*f_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[42000]
{
  real_T(*ret)[42000];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 3U, (void *)&iv[0]);
  ret = (real_T(*)[42000])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void b_EvaluationPath_GPU_api(EvaluationPath_GPUStackData *SD,
                              const mxArray *const prhs[4], int32_T nlhs,
                              const mxArray *plhs[2])
{
  cell_wrap_0 preobs[22];
  emxArray_boolean_T *remove_sample;
  emxArray_real_T *pw;
  real_T(*px)[63000];
  real_T(*pu)[42000];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&pw, 2, true);
  emxInit_boolean_T(&remove_sample, 2, true);
  // Marshall function inputs
  emlrt_marshallIn(emlrtAliasP(prhs[0]), "obj", &SD->f0.obj);
  px = emlrt_marshallIn(emlrtAlias(prhs[1]), "px");
  pu = b_emlrt_marshallIn(emlrtAlias(prhs[2]), "pu");
  emlrt_marshallIn(emlrtAliasP(prhs[3]), "preobs", preobs);
  // Invoke the target function
  EvaluationPath_GPU(&SD->f0.obj, *px, *pu, preobs, pw, remove_sample);
  // Marshall function outputs
  pw->canFreeData = false;
  plhs[0] = emlrt_marshallOut(pw);
  emxFree_real_T(&pw);
  if (nlhs > 1) {
    remove_sample->canFreeData = false;
    plhs[1] = emlrt_marshallOut(remove_sample);
  }
  emxFree_boolean_T(&remove_sample);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

// End of code generation (_coder_EvaluationPath_GPU_api.cu)
