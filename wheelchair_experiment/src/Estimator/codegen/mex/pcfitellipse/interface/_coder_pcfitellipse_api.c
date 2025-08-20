/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_pcfitellipse_api.c
 *
 * Code generation for function '_coder_pcfitellipse_api'
 *
 */

/* Include files */
#include "_coder_pcfitellipse_api.h"
#include "pcfitellipse.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_mexutil.h"
#include "pcfitellipse_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const real_T u[5]);

static real_T *c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *points,
                                  const char_T *identifier, int32_T y_size[2]);

static const mxArray *c_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size[2]);

static real_T *d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2]);

static const mxArray *d_emlrt_marshallOut(const real_T u[25]);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *a0,
                                   const char_T *identifier))[5];

static real_T emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_feval_,
                               const char_T *identifier);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[5];

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Aeq,
                               const char_T *identifier);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Pbar,
                                   const char_T *identifier))[36];

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[36];

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *c,
                                   const char_T *identifier))[30];

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[30];

static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *R,
                                   const char_T *identifier))[25];

static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[25];

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xhbar,
                                   const char_T *identifier))[6];

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[6];

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T *r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2]);

static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[5];

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId);

static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[36];

static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[30];

static real_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[25];

static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6];

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const real_T u[5])
{
  static const int32_T i = 0;
  static const int32_T i1 = 5;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T *c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *points,
                                  const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y_data = d_emlrt_marshallIn(sp, emlrtAlias(points), &thisId, y_size);
  emlrtDestroyArray(&points);
  return y_data;
}

static const mxArray *c_emlrt_marshallOut(const real_T u_data[],
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

static real_T *d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2])
{
  real_T *y_data;
  y_data = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static const mxArray *d_emlrt_marshallOut(const real_T u[25])
{
  static const int32_T b_iv[2] = {0, 0};
  static const int32_T iv1[2] = {5, 5};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
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

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[5]
{
  real_T(*y)[5];
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
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
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Pbar,
                                   const char_T *identifier))[36]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[36];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(Pbar), &thisId);
  emlrtDestroyArray(&Pbar);
  return y;
}

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[36]
{
  real_T(*y)[36];
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *c,
                                   const char_T *identifier))[30]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[30];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(c), &thisId);
  emlrtDestroyArray(&c);
  return y;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[30]
{
  real_T(*y)[30];
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *R,
                                   const char_T *identifier))[25]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[25];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = n_emlrt_marshallIn(sp, emlrtAlias(R), &thisId);
  emlrtDestroyArray(&R);
  return y;
}

static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[25]
{
  real_T(*y)[25];
  y = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xhbar,
                                   const char_T *identifier))[6]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[6];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = p_emlrt_marshallIn(sp, emlrtAlias(Xhbar), &thisId);
  emlrtDestroyArray(&Xhbar);
  return y;
}

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[6]
{
  real_T(*y)[6];
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T *r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2])
{
  static const int32_T dims[2] = {1500, 2};
  real_T *ret_data;
  int32_T b_iv[2];
  boolean_T bv[2] = {true, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret_size[0] = b_iv[0];
  ret_size[1] = b_iv[1];
  ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret_data;
}

static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[36]
{
  static const int32_T dims[2] = {6, 6};
  real_T(*ret)[36];
  int32_T b_iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[36])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[30]
{
  static const int32_T dims[2] = {5, 6};
  real_T(*ret)[30];
  int32_T b_iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[30])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[25]
{
  static const int32_T dims[2] = {5, 5};
  real_T(*ret)[25];
  int32_T b_iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[25])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6]
{
  static const int32_T dims = 6;
  real_T(*ret)[6];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[6])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void pcfitellipse_api(pcfitellipseStackData *SD, const mxArray *const prhs[19],
                      int32_T nlhs, const mxArray *plhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*inlier_data)[3000];
  real_T(*points_data)[3000];
  real_T(*Pbar)[36];
  real_T(*c)[30];
  real_T(*R)[25];
  real_T(*S_final)[25];
  real_T(*Xhbar)[6];
  real_T(*A)[5];
  real_T(*Y)[5];
  real_T(*a0)[5];
  real_T(*lb)[5];
  real_T(*ub)[5];
  real_T B;
  real_T CNum;
  real_T MD;
  real_T MD_threshold;
  real_T MSANum;
  real_T Num;
  real_T SBreakFlag;
  real_T eta;
  real_T maxDistance;
  real_T sampleSize;
  int32_T inlier_size[2];
  int32_T points_size[2];
  st.tls = emlrtRootTLSGlobal;
  Y = (real_T(*)[5])mxMalloc(sizeof(real_T[5]));
  inlier_data = (real_T(*)[3000])mxMalloc(sizeof(real_T[3000]));
  S_final = (real_T(*)[25])mxMalloc(sizeof(real_T[25]));
  /* Marshall function inputs */
  *(real_T **)&points_data =
      c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "points", points_size);
  a0 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "a0");
  sampleSize = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sampleSize");
  maxDistance = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "maxDistance");
  A = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "A");
  B = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "B");
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "Aeq");
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "Beq");
  lb = e_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "lb");
  ub = e_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "ub");
  Num = emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "Num");
  CNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "CNum");
  Pbar = i_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "Pbar");
  c = k_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "c");
  R = m_emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "R");
  MD_threshold = emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "MD_threshold");
  MSANum = emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "MSANum");
  Xhbar = o_emlrt_marshallIn(&st, emlrtAlias(prhs[17]), "Xhbar");
  eta = emlrt_marshallIn(&st, emlrtAliasP(prhs[18]), "eta");
  /* Invoke the target function */
  pcfitellipse(SD, &st, *points_data, points_size, *a0, sampleSize, maxDistance,
               *A, B, *lb, *ub, Num, CNum, *Pbar, *c, *R, MD_threshold, MSANum,
               *Xhbar, eta, *Y, *inlier_data, inlier_size, &SBreakFlag, &MD,
               *S_final);
  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*Y);
  if (nlhs > 1) {
    plhs[1] = c_emlrt_marshallOut(*inlier_data, inlier_size);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(SBreakFlag);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(MD);
  }
  if (nlhs > 4) {
    plhs[4] = d_emlrt_marshallOut(*S_final);
  }
}

/* End of code generation (_coder_pcfitellipse_api.c) */
