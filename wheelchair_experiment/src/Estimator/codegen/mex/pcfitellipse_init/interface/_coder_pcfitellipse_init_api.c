/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_pcfitellipse_init_api.c
 *
 * Code generation for function '_coder_pcfitellipse_init_api'
 *
 */

/* Include files */
#include "_coder_pcfitellipse_init_api.h"
#include "pcfitellipse_init.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real32_T *c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                                    const char_T *identifier, int32_T *y_size);

static real32_T *d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId,
                                    int32_T *y_size);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *a0,
                                   const char_T *identifier))[5];

static real_T emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_feval_,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const real_T u_data[],
                                        const int32_T u_size[2]);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[5];

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Aeq,
                               const char_T *identifier);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real32_T *j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId,
                                    int32_T *ret_size);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[5];

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real32_T *c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                                    const char_T *identifier, int32_T *y_size)
{
  emlrtMsgIdentifier thisId;
  real32_T *y_data;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y_data = d_emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y_size);
  emlrtDestroyArray(&x);
  return y_data;
}

static real32_T *d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId,
                                    int32_T *y_size)
{
  real32_T *y_data;
  y_data = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *a0,
                                   const char_T *identifier))[5]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[5];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(a0), &thisId);
  emlrtDestroyArray(&a0);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_feval_,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_feval_), &thisId);
  emlrtDestroyArray(&a__output_of_feval_);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u_data[],
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

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[5]
{
  real_T(*y)[5];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Aeq,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(Aeq), &thisId);
  emlrtDestroyArray(&Aeq);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real32_T *j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId,
                                    int32_T *ret_size)
{
  static const int32_T dims = 1500;
  real32_T *ret_data;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 1U,
                            (const void *)&dims, &b, ret_size);
  ret_data = (real32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret_data;
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[5]
{
  static const int32_T dims[2] = {1, 5};
  real_T(*ret)[5];
  int32_T b_iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[5])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = {0, 0};
  int32_T b_iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

void pcfitellipse_init_api(pcfitellipse_initStackData *SD,
                           const mxArray *const prhs[13], int32_T nlhs,
                           const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*inlier_data)[3000];
  real_T(*A)[5];
  real_T(*a0)[5];
  real_T(*lb)[5];
  real_T(*modelRANSAC_data)[5];
  real_T(*ub)[5];
  real_T B;
  real_T CNum;
  real_T Num;
  real_T maxDistance;
  real_T sampleSize;
  int32_T inlier_size[2];
  int32_T modelRANSAC_size[2];
  int32_T x_size;
  int32_T y_size;
  real32_T(*x_data)[1500];
  real32_T(*y_data)[1500];
  st.tls = emlrtRootTLSGlobal;
  modelRANSAC_data = (real_T(*)[5])mxMalloc(sizeof(real_T[5]));
  inlier_data = (real_T(*)[3000])mxMalloc(sizeof(real_T[3000]));
  /* Marshall function inputs */
  *(real32_T **)&x_data =
      c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x", &x_size);
  *(real32_T **)&y_data =
      c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "y", &y_size);
  a0 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "a0");
  sampleSize = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "sampleSize");
  maxDistance = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "maxDistance");
  A = e_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "A");
  B = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "B");
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "Aeq");
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "Beq");
  lb = e_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "lb");
  ub = e_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "ub");
  Num = emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "Num");
  CNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "CNum");
  /* Invoke the target function */
  pcfitellipse_init(SD, &st, *x_data, &x_size, *y_data, &y_size, *a0,
                    sampleSize, maxDistance, *A, B, *lb, *ub, Num, CNum,
                    *modelRANSAC_data, modelRANSAC_size, *inlier_data,
                    inlier_size);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*modelRANSAC_data, modelRANSAC_size);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*inlier_data, inlier_size);
  }
}

/* End of code generation (_coder_pcfitellipse_init_api.c) */
