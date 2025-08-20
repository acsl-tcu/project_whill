/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pointCloud.c
 *
 * Code generation for function 'pointCloud'
 *
 */

/* Include files */
#include "pointCloud.h"
#include "calc_observation_emxutil.h"
#include "calc_observation_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo m_emlrtRSI = {
    33,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/+codegen/+pc/pointCloud.m" /* pathName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    85,               /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/shared/pointclouds/+pointclouds/"
    "+internal/pointCloudBase.m" /* pName */
};

/* Function Definitions */
pointCloud *pointCloud_pointCloud(const emlrtStack *sp, pointCloud *b_this,
                                  const emxArray_real_T *varargin_1)
{
  emlrtStack st;
  pointCloud *c_this;
  const real_T *varargin_1_data;
  int32_T i;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  varargin_1_data = varargin_1->data;
  c_this = b_this;
  c_this->HasKdtreeConstructed = false;
  c_this->HasLocationHandleAllocated = false;
  st.site = &m_emlrtRSI;
  i = c_this->Location->size[0] * c_this->Location->size[1];
  c_this->Location->size[0] = varargin_1->size[0];
  c_this->Location->size[1] = 3;
  emxEnsureCapacity_real_T(&st, c_this->Location, i, &yb_emlrtRTEI);
  loop_ub_tmp = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub_tmp; i++) {
    c_this->Location->data[i] = varargin_1_data[i];
  }
  c_this->Color->size[0] = 0;
  c_this->Color->size[1] = 0;
  c_this->Normal->size[0] = 0;
  c_this->Normal->size[1] = 0;
  c_this->Intensity->size[0] = 0;
  c_this->Intensity->size[1] = 0;
  c_this->Kdtree = NULL;
  c_this->LocationHandle = NULL;
  c_this->matlabCodegenIsDeleted = false;
  return c_this;
}

/* End of code generation (pointCloud.c) */
