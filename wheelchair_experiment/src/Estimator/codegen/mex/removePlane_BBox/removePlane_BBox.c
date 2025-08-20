/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removePlane_BBox.c
 *
 * Code generation for function 'removePlane_BBox'
 *
 */

/* Include files */
#include "removePlane_BBox.h"
#include "cuboidModel.h"
#include "eml_int_forloop_overflow_check.h"
#include "handle.h"
#include "pcfitcuboid.h"
#include "pointCloud.h"
#include "removePlane_BBox_data.h"
#include "removePlane_BBox_emxutil.h"
#include "removePlane_BBox_internal_types.h"
#include "removePlane_BBox_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    2,                  /* lineNo */
    "removePlane_BBox", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_BBox.m" /* pathName
                                                                      */
};

static emlrtRSInfo b_emlrtRSI = {
    7,                  /* lineNo */
    "removePlane_BBox", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_BBox.m" /* pathName
                                                                      */
};

static emlrtRSInfo c_emlrtRSI = {
    3,                  /* lineNo */
    "removePlane_BBox", /* fcnName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_BBox.m" /* pathName
                                                                      */
};

static emlrtRSInfo u_emlrtRSI =
    {
        108,           /* lineNo */
        "pcfitcuboid", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo v_emlrtRSI =
    {
        112,           /* lineNo */
        "pcfitcuboid", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo w_emlrtRSI =
    {
        120,           /* lineNo */
        "pcfitcuboid", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo x_emlrtRSI =
    {
        126,           /* lineNo */
        "pcfitcuboid", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo y_emlrtRSI =
    {
        127,           /* lineNo */
        "pcfitcuboid", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo ab_emlrtRSI =
    {
        135,           /* lineNo */
        "pcfitcuboid", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo bb_emlrtRSI =
    {
        153,           /* lineNo */
        "pcfitcuboid", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo cb_emlrtRSI =
    {
        1,             /* lineNo */
        "pcfitcuboid", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo db_emlrtRSI =
    {
        119,           /* lineNo */
        "pcfitcuboid", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo eb_emlrtRSI =
    {
        300,                      /* lineNo */
        "validateAndParseInputs", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pathName
                                                                       */
};

static emlrtRSInfo gb_emlrtRSI = {
    11,               /* lineNo */
    "validatescalar", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatescalar.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatescalar", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatescalar.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    126,               /* lineNo */
    9,                 /* colNo */
    "computeDimsData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    74,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    81,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI =
    {
        112,           /* lineNo */
        31,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo t_emlrtRTEI =
    {
        131,           /* lineNo */
        20,            /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo u_emlrtRTEI = {
    1,                  /* lineNo */
    35,                 /* colNo */
    "removePlane_BBox", /* fName */
    "C:\\Users\\masan\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\gra"
    "duation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_BBox.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI =
    {
        119,           /* lineNo */
        5,             /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

static emlrtRTEInfo w_emlrtRTEI =
    {
        112,           /* lineNo */
        5,             /* colNo */
        "pcfitcuboid", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcfitcuboid.m" /* pName
                                                                       */
};

/* Function Definitions */
void removePlane_BBox(const emlrtStack *sp, const emxArray_real_T *pnew,
                      real_T *x, real_T *y)
{
  cuboidModel BBmodel;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  emxArray_real_T *b_ptCLoudValid;
  emxArray_real_T *c_pnew;
  pointCloud b_pnew;
  pointCloud ptCLoudValid;
  pointCloud ptCloudUnOrg;
  real_T boundingBox[9];
  real_T a__1;
  real_T *pnew_data;
  int32_T emptyDimValue;
  int32_T k;
  int32_T last;
  int32_T nx;
  boolean_T overflow;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud(sp, &b_pnew, &u_emlrtRTEI);
  emxInitStruct_pointCloud(sp, &ptCLoudValid, &v_emlrtRTEI);
  emxInitStruct_pointCloud(sp, &ptCloudUnOrg, &w_emlrtRTEI);
  emxInit_real_T(sp, &b_ptCLoudValid, 2, &t_emlrtRTEI);
  emxInit_real_T(sp, &c_pnew, 2, &s_emlrtRTEI);
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &b_pnew,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  b_pnew.matlabCodegenIsDeleted = true;
  st.site = &emlrtRSI;
  pointCloud_pointCloud(&st, &b_pnew, pnew);
  st.site = &c_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, &ptCLoudValid,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  ptCLoudValid.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a(&st, true, &ptCloudUnOrg,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  ptCloudUnOrg.matlabCodegenIsDeleted = true;
  b_st.site = &u_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  d_st.site = &fb_emlrtRSI;
  e_st.site = &gb_emlrtRSI;
  overflow = (b_pnew.PointCloudArrayData->size[0] *
                  b_pnew.PointCloudArrayData->size[1] ==
              1);
  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:pcfitcuboid:expectedScalar", 3, 4, 9, "ptCloudIn");
  }
  b_st.site = &v_emlrtRSI;
  last = b_pnew.Location->size[0];
  nx = last * 3;
  c_st.site = &hb_emlrtRSI;
  emptyDimValue = (int32_T)((uint32_T)nx / 3U);
  if (emptyDimValue > nx) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (last < 3) {
    last = 3;
  }
  if (emptyDimValue > muIntScalarMax_sint32(nx, last)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (emptyDimValue * 3 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &f_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  k = c_pnew->size[0] * c_pnew->size[1];
  c_pnew->size[0] = emptyDimValue;
  c_pnew->size[1] = 3;
  emxEnsureCapacity_real_T(&st, c_pnew, k, &s_emlrtRTEI);
  pnew_data = c_pnew->data;
  last = emptyDimValue * 3 - 1;
  for (k = 0; k <= last; k++) {
    pnew_data[k] = b_pnew.Location->data[k];
  }
  b_st.site = &v_emlrtRSI;
  pointCloud_pointCloud(&b_st, &ptCloudUnOrg, c_pnew);
  b_st.site = &db_emlrtRSI;
  pointCloud_removeInvalidPoints(&b_st, &ptCloudUnOrg, &ptCLoudValid);
  b_st.site = &w_emlrtRSI;
  last = ptCLoudValid.Location->size[0];
  if (last == 0) {
    memset(&boundingBox[0], 0, 9U * sizeof(real_T));
  } else {
    real_T maxHeight;
    real_T minHeight;
    boolean_T exitg1;
    b_st.site = &x_emlrtRSI;
    c_st.site = &xb_emlrtRSI;
    d_st.site = &yb_emlrtRSI;
    e_st.site = &ac_emlrtRSI;
    if (ptCLoudValid.Location->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &c_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    f_st.site = &bc_emlrtRSI;
    g_st.site = &cc_emlrtRSI;
    last = ptCLoudValid.Location->size[0];
    if (ptCLoudValid.Location->size[0] <= 2) {
      if (ptCLoudValid.Location->size[0] == 1) {
        minHeight =
            ptCLoudValid.Location->data[ptCLoudValid.Location->size[0] * 2];
      } else if ((ptCLoudValid.Location
                      ->data[ptCLoudValid.Location->size[0] * 2] >
                  ptCLoudValid.Location
                      ->data[ptCLoudValid.Location->size[0] * 2 + 1]) ||
                 (muDoubleScalarIsNaN(
                      ptCLoudValid.Location
                          ->data[ptCLoudValid.Location->size[0] * 2]) &&
                  (!muDoubleScalarIsNaN(
                      ptCLoudValid.Location
                          ->data[ptCLoudValid.Location->size[0] * 2 + 1])))) {
        minHeight =
            ptCLoudValid.Location->data[ptCLoudValid.Location->size[0] * 2 + 1];
      } else {
        minHeight =
            ptCLoudValid.Location->data[ptCLoudValid.Location->size[0] * 2];
      }
    } else {
      h_st.site = &ec_emlrtRSI;
      if (!muDoubleScalarIsNaN(
              ptCLoudValid.Location
                  ->data[ptCLoudValid.Location->size[0] * 2])) {
        nx = 1;
      } else {
        nx = 0;
        i_st.site = &fc_emlrtRSI;
        overflow = (ptCLoudValid.Location->size[0] > 2147483646);
        if (overflow) {
          j_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(
                  ptCLoudValid.Location
                      ->data[(k + ptCLoudValid.Location->size[0] * 2) - 1])) {
            nx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (nx == 0) {
        minHeight =
            ptCLoudValid.Location->data[ptCLoudValid.Location->size[0] * 2];
      } else {
        h_st.site = &dc_emlrtRSI;
        minHeight = ptCLoudValid.Location
                        ->data[(nx + ptCLoudValid.Location->size[0] * 2) - 1];
        emptyDimValue = nx + 1;
        i_st.site = &gc_emlrtRSI;
        overflow = ((nx + 1 <= ptCLoudValid.Location->size[0]) &&
                    (ptCLoudValid.Location->size[0] > 2147483646));
        if (overflow) {
          j_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }
        for (k = emptyDimValue; k <= last; k++) {
          a__1 = ptCLoudValid.Location
                     ->data[(k + ptCLoudValid.Location->size[0] * 2) - 1];
          if (minHeight > a__1) {
            minHeight = a__1;
          }
        }
      }
    }
    b_st.site = &y_emlrtRSI;
    c_st.site = &hc_emlrtRSI;
    d_st.site = &ic_emlrtRSI;
    e_st.site = &jc_emlrtRSI;
    f_st.site = &kc_emlrtRSI;
    g_st.site = &lc_emlrtRSI;
    last = ptCLoudValid.Location->size[0];
    if (ptCLoudValid.Location->size[0] <= 2) {
      if (ptCLoudValid.Location->size[0] == 1) {
        maxHeight =
            ptCLoudValid.Location->data[ptCLoudValid.Location->size[0] * 2];
      } else if ((ptCLoudValid.Location
                      ->data[ptCLoudValid.Location->size[0] * 2] <
                  ptCLoudValid.Location
                      ->data[ptCLoudValid.Location->size[0] * 2 + 1]) ||
                 (muDoubleScalarIsNaN(
                      ptCLoudValid.Location
                          ->data[ptCLoudValid.Location->size[0] * 2]) &&
                  (!muDoubleScalarIsNaN(
                      ptCLoudValid.Location
                          ->data[ptCLoudValid.Location->size[0] * 2 + 1])))) {
        maxHeight =
            ptCLoudValid.Location->data[ptCLoudValid.Location->size[0] * 2 + 1];
      } else {
        maxHeight =
            ptCLoudValid.Location->data[ptCLoudValid.Location->size[0] * 2];
      }
    } else {
      h_st.site = &ec_emlrtRSI;
      if (!muDoubleScalarIsNaN(
              ptCLoudValid.Location
                  ->data[ptCLoudValid.Location->size[0] * 2])) {
        nx = 1;
      } else {
        nx = 0;
        i_st.site = &fc_emlrtRSI;
        overflow = (ptCLoudValid.Location->size[0] > 2147483646);
        if (overflow) {
          j_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(
                  ptCLoudValid.Location
                      ->data[(k + ptCLoudValid.Location->size[0] * 2) - 1])) {
            nx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (nx == 0) {
        maxHeight =
            ptCLoudValid.Location->data[ptCLoudValid.Location->size[0] * 2];
      } else {
        h_st.site = &dc_emlrtRSI;
        maxHeight = ptCLoudValid.Location
                        ->data[(nx + ptCLoudValid.Location->size[0] * 2) - 1];
        emptyDimValue = nx + 1;
        i_st.site = &gc_emlrtRSI;
        overflow = ((nx + 1 <= ptCLoudValid.Location->size[0]) &&
                    (ptCLoudValid.Location->size[0] > 2147483646));
        if (overflow) {
          j_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }
        for (k = emptyDimValue; k <= last; k++) {
          a__1 = ptCLoudValid.Location
                     ->data[(k + ptCLoudValid.Location->size[0] * 2) - 1];
          if (maxHeight < a__1) {
            maxHeight = a__1;
          }
        }
      }
    }
    k = b_ptCLoudValid->size[0] * b_ptCLoudValid->size[1];
    b_ptCLoudValid->size[0] = ptCLoudValid.Location->size[0];
    b_ptCLoudValid->size[1] = 2;
    emxEnsureCapacity_real_T(&st, b_ptCLoudValid, k, &t_emlrtRTEI);
    pnew_data = b_ptCLoudValid->data;
    for (k = 0; k < 2; k++) {
      last = ptCLoudValid.Location->size[0];
      for (nx = 0; nx < last; nx++) {
        pnew_data[nx + b_ptCLoudValid->size[0] * k] =
            ptCLoudValid.Location
                ->data[nx + ptCLoudValid.Location->size[0] * k];
      }
    }
    real_T boundingBox2d[5];
    b_st.site = &ab_emlrtRSI;
    findBoundingBox(&b_st, b_ptCLoudValid, boundingBox2d, &a__1);
    boundingBox[0] = boundingBox2d[0];
    boundingBox[1] = boundingBox2d[1];
    boundingBox[2] = (maxHeight + minHeight) / 2.0;
    boundingBox[3] = boundingBox2d[2];
    boundingBox[4] = boundingBox2d[3];
    boundingBox[5] = maxHeight - minHeight;
    boundingBox[6] = 0.0;
    boundingBox[7] = 0.0;
    boundingBox[8] = boundingBox2d[4];
  }
  b_st.site = &bb_emlrtRSI;
  cuboidModel_cuboidModel(&b_st, &BBmodel, boundingBox);
  b_st.site = &cb_emlrtRSI;
  handle_matlabCodegenDestructor(&b_st, &ptCloudUnOrg);
  b_st.site = &cb_emlrtRSI;
  handle_matlabCodegenDestructor(&b_st, &ptCLoudValid);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
  *x = BBmodel.Parameters[3];
  *y = BBmodel.Parameters[4];
  st.site = &b_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &b_pnew);
  emxFree_real_T(sp, &c_pnew);
  emxFree_real_T(sp, &b_ptCLoudValid);
  emxFreeStruct_pointCloud(sp, &ptCloudUnOrg);
  emxFreeStruct_pointCloud(sp, &ptCLoudValid);
  emxFreeStruct_pointCloud(sp, &b_pnew);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (removePlane_BBox.c) */
