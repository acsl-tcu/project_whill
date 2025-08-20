/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_removeleg_api.c
 *
 * Code generation for function '_coder_removeleg_api'
 *
 */

/* Include files */
#include "_coder_removeleg_api.h"
#include "removeleg.h"
#include "removeleg_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real32_T *b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId,
                                    int32_T y_size[2]);

static real32_T *c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId,
                                    int32_T ret_size[2]);

static real32_T *emlrt_marshallIn(const emlrtStack *sp, const mxArray *point,
                                  const char_T *identifier, int32_T y_size[2]);

static const mxArray *emlrt_marshallOut(const real32_T u_data[],
                                        const int32_T u_size[2]);

/* Function Definitions */
static real32_T *b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId,
                                    int32_T y_size[2])
{
  real32_T *y_data;
  y_data = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real32_T *c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId,
                                    int32_T ret_size[2])
{
  static const int32_T dims[2] = {1000, 3};
  int32_T iv[2];
  real32_T *ret_data;
  boolean_T bv[2] = {true, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  ret_data = (real32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret_data;
}

static real32_T *emlrt_marshallIn(const emlrtStack *sp, const mxArray *point,
                                  const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real32_T *y_data;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y_data = b_emlrt_marshallIn(sp, emlrtAlias(point), &thisId, y_size);
  emlrtDestroyArray(&point);
  return y_data;
}

static const mxArray *emlrt_marshallOut(const real32_T u_data[],
                                        const int32_T u_size[2])
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u_size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

void removeleg_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  int32_T point_size[2];
  int32_T savePoint_size[2];
  real32_T(*point_data)[3000];
  real32_T(*savePoint_data)[3000];
  st.tls = emlrtRootTLSGlobal;
  savePoint_data = (real32_T(*)[3000])mxMalloc(sizeof(real32_T[3000]));
  /* Marshall function inputs */
  *(real32_T **)&point_data =
      emlrt_marshallIn(&st, emlrtAlias(prhs), "point", point_size);
  /* Invoke the target function */
  removeleg(&st, *point_data, point_size, *savePoint_data, savePoint_size);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*savePoint_data, savePoint_size);
}

/* End of code generation (_coder_removeleg_api.c) */
