//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_EvaluationPath_api.cpp
//
//  Code generation for function '_coder_EvaluationPath_api'
//


// Include files
#include "_coder_EvaluationPath_api.h"
#include "EvaluationPath.h"
#include "EvaluationPath_data.h"
#include "EvaluationPath_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static const int32_T iv[3] = { 2, 21, 10000 };

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pu, const
  char_T *identifier, coder::array<real_T, 3U> &y);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2]);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[16]);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 3U> &y);
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static const mxArray *b_emlrt_marshallOut(const coder::array<boolean_T, 2U> &u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 3U> &y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 3U> &y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[16]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 3U> &ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_0 y[22]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *px, const
  char_T *identifier, coder::array<real_T, 3U> &y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *obj, const
  char_T *identifier, struct0_T *y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *preobs, const
  char_T *identifier, cell_wrap_0 y[22]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 3U> &y);
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 3U> &ret);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 3U> &ret);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 3U> &ret);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 3U> &y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pu, const
  char_T *identifier, coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(pu), &thisId, y);
  emlrtDestroyArray(&pu);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 20, 2 };

  int32_T b_iv[2];
  const boolean_T bv[2] = { true, false };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    b_iv);
  ret_size[0] = b_iv[0];
  ret_size[1] = b_iv[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 8, false);
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[16])
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static const mxArray *b_emlrt_marshallOut(const coder::array<boolean_T, 2U> &u)
{
  static const int32_T b_iv[2] = { 0, 0 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateLogicalArray(2, &b_iv[0]);
  emlrtMxSetData((mxArray *)m, &(((coder::array<boolean_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<boolean_T, 2U> *)&u)->size(),
                     2);
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 3U> &y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  real_T (*r)[2];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 3U> &y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[16])
{
  static const int32_T dims[3] = { 2, 4, 2 };

  real_T (*r)[16];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims);
  r = (real_T (*)[16])emlrtMxGetData(src);
  for (int32_T i = 0; i < 16; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3] = { 4, 21, 10000 };

  int32_T b_iv[3];
  const boolean_T bv[3] = { false, false, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims, &bv[0],
    b_iv);
  ret.set_size((emlrtRTEInfo *)NULL, sp, b_iv[0], b_iv[1], b_iv[2]);
  emlrtImportArrayR2015b(sp, src, &(ret.data())[0], 8, false);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[15] = { "K", "NP", "ObsNum", "r_wheel",
    "r_obs", "R", "W", "Wo", "Vref", "limit", "target", "ltheta",
    "wall_penalty1", "wall_penalty2", "wall_threshold" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 15, fieldNames, 0U, &dims);
  thisId.fIdentifier = "K";
  y->K = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "K")),
    &thisId);
  thisId.fIdentifier = "NP";
  y->NP = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "NP")),
    &thisId);
  thisId.fIdentifier = "ObsNum";
  y->ObsNum = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "ObsNum")), &thisId);
  thisId.fIdentifier = "r_wheel";
  y->r_wheel = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "r_wheel")), &thisId);
  thisId.fIdentifier = "r_obs";
  y->r_obs = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "r_obs")), &thisId);
  thisId.fIdentifier = "R";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "R")),
                   &thisId, y->R);
  thisId.fIdentifier = "W";
  y->W = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6, "W")),
    &thisId);
  thisId.fIdentifier = "Wo";
  y->Wo = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7, "Wo")),
    &thisId);
  thisId.fIdentifier = "Vref";
  y->Vref = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "Vref")), &thisId);
  thisId.fIdentifier = "limit";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9, "limit")),
                   &thisId, y->limit);
  thisId.fIdentifier = "target";
  b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10, "target")),
                     &thisId, y->target);
  thisId.fIdentifier = "ltheta";
  b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11, "ltheta")),
                     &thisId, y->ltheta);
  thisId.fIdentifier = "wall_penalty1";
  y->wall_penalty1 = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 12, "wall_penalty1")), &thisId);
  thisId.fIdentifier = "wall_penalty2";
  y->wall_penalty2 = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 13, "wall_penalty2")), &thisId);
  thisId.fIdentifier = "wall_threshold";
  y->wall_threshold = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 14, "wall_threshold")), &thisId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *px, const
  char_T *identifier, coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  c_emlrt_marshallIn(sp, emlrtAlias(px), &thisId, y);
  emlrtDestroyArray(&px);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2])
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_0 y[22])
{
  emlrtMsgIdentifier thisId;
  int32_T b_iv[1];
  char_T str[11];
  boolean_T bv[1];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b_iv[0] = 22;
  bv[0] = false;
  emlrtCheckCell(sp, parentId, u, 1U, &b_iv[0], &bv[0]);
  for (int32_T i = 0; i < 22; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i)), &thisId,
                     y[i].f1.data, y[i].f1.size);
  }

  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *preobs, const
  char_T *identifier, cell_wrap_0 y[22])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(preobs), &thisId, y);
  emlrtDestroyArray(&preobs);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *obj, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(obj), &thisId, y);
  emlrtDestroyArray(&obj);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 3U> &y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T b_iv[2] = { 0, 0 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 3U> &ret)
{
  int32_T b_iv[3];
  const boolean_T bv[3] = { false, false, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 3U, iv, &bv[0],
    b_iv);
  ret.set_size((emlrtRTEInfo *)NULL, sp, b_iv[0], b_iv[1], b_iv[2]);
  emlrtImportArrayR2015b(sp, src, &(ret.data())[0], 8, false);
  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3] = { 3, 21, 10000 };

  int32_T b_iv[3];
  const boolean_T bv[3] = { false, false, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims, &bv[0],
    b_iv);
  ret.prealloc(b_iv[0] * b_iv[1] * b_iv[2]);
  ret.set_size((emlrtRTEInfo *)NULL, sp, b_iv[0], b_iv[1], b_iv[2]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2));
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 3U> &ret)
{
  int32_T b_iv[3];
  const boolean_T bv[3] = { false, false, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 3U, iv, &bv[0],
    b_iv);
  ret.prealloc(b_iv[0] * b_iv[1] * b_iv[2]);
  ret.set_size((emlrtRTEInfo *)NULL, sp, b_iv[0], b_iv[1], b_iv[2]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2));
  emlrtDestroyArray(&src);
}

void EvaluationPath_api(const mxArray * const prhs[4], int32_T nlhs, const
  mxArray *plhs[2])
{
  coder::array<real_T, 3U> pu;
  coder::array<real_T, 3U> px;
  coder::array<real_T, 2U> pw;
  coder::array<boolean_T, 2U> remove_sample;
  cell_wrap_0 preobs[22];
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  struct0_T obj;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  // Marshall function inputs
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "obj", &obj);
  px.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "px", px);
  pu.no_free();
  b_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "pu", pu);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "preobs", preobs);

  // Invoke the target function
  EvaluationPath(&st, &obj, px, pu, preobs, pw, remove_sample);

  // Marshall function outputs
  pw.no_free();
  plhs[0] = emlrt_marshallOut(pw);
  if (nlhs > 1) {
    remove_sample.no_free();
    plhs[1] = b_emlrt_marshallOut(remove_sample);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_EvaluationPath_api.cpp)
