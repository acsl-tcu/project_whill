/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * permute.c
 *
 * Code generation for function 'permute'
 *
 */

/* Include files */
#include "permute.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo od_emlrtRTEI = {
    56,        /* lineNo */
    5,         /* colNo */
    "permute", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/permute.m" /* pName
                                                                       */
};

/* Function Definitions */
void permute(const emlrtStack *sp, const emxArray_boolean_T *a,
             emxArray_boolean_T *b)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b_k;
  int32_T c_k;
  int32_T k;
  int32_T plast;
  int32_T subsa_idx_2;
  int32_T subsa_idx_3;
  const boolean_T *a_data;
  boolean_T b_b;
  boolean_T *b_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  a_data = a->data;
  b_b = true;
  if ((a->size[1] != 0) && (a->size[2] != 0) && (a->size[3] != 0)) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (a->size[k] != 1) {
        if (plast > k + 1) {
          b_b = false;
          exitg1 = true;
        } else {
          plast = k + 1;
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b_b) {
    int32_T nx_tmp;
    st.site = &kb_emlrtRSI;
    nx_tmp = (a->size[1] << 2) * a->size[2] * a->size[3];
    b_st.site = &cb_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    plast = 4;
    if (a->size[1] > 4) {
      plast = a->size[1];
    }
    if (a->size[2] > plast) {
      plast = a->size[2];
    }
    if (a->size[3] > plast) {
      plast = a->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (a->size[1] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (a->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (a->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_k = b->size[0] * b->size[1] * b->size[2] * b->size[3];
    b->size[0] = 4;
    b->size[1] = a->size[1];
    b->size[2] = a->size[2];
    b->size[3] = a->size[3];
    emxEnsureCapacity_boolean_T(sp, b, b_k, &od_emlrtRTEI);
    b_data = b->data;
    for (b_k = 0; b_k < nx_tmp; b_k++) {
      b_data[b_k] = a_data[b_k];
    }
  } else {
    int32_T c_b;
    int32_T nx_tmp;
    st.site = &lb_emlrtRSI;
    nx_tmp = (a->size[1] << 2) * a->size[2] * a->size[3];
    b_st.site = &cb_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    plast = 4;
    if (a->size[1] > 4) {
      plast = a->size[1];
    }
    if (a->size[2] > plast) {
      plast = a->size[2];
    }
    if (a->size[3] > plast) {
      plast = a->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (a->size[1] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (a->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (a->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_k = b->size[0] * b->size[1] * b->size[2] * b->size[3];
    b->size[0] = 4;
    plast = a->size[1];
    b->size[1] = a->size[1];
    nx_tmp = a->size[2];
    b->size[2] = a->size[2];
    c_b = a->size[3];
    b->size[3] = a->size[3];
    emxEnsureCapacity_boolean_T(sp, b, b_k, &kd_emlrtRTEI);
    b_data = b->data;
    st.site = &mb_emlrtRSI;
    b_st.site = &nb_emlrtRSI;
    if (a->size[3] > 2147483646) {
      c_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k < c_b; k++) {
      b_st.site = &ob_emlrtRSI;
      c_st.site = &nb_emlrtRSI;
      if (a->size[2] > 2147483646) {
        d_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (b_k = 0; b_k < nx_tmp; b_k++) {
        c_st.site = &ob_emlrtRSI;
        if (a->size[1] - 1 >= 0) {
          subsa_idx_2 = b_k + 1;
          subsa_idx_3 = k + 1;
        }
        for (c_k = 0; c_k < plast; c_k++) {
          b_data[(4 * c_k + 4 * b->size[1] * (subsa_idx_2 - 1)) +
                 4 * b->size[1] * b->size[2] * (subsa_idx_3 - 1)] =
              a_data[(4 * c_k + 4 * a->size[1] * (subsa_idx_2 - 1)) +
                     4 * a->size[1] * a->size[2] * (subsa_idx_3 - 1)];
          b_data[((4 * c_k + 4 * b->size[1] * (subsa_idx_2 - 1)) +
                  4 * b->size[1] * b->size[2] * (subsa_idx_3 - 1)) +
                 1] = a_data[((4 * c_k + 4 * a->size[1] * (subsa_idx_2 - 1)) +
                              4 * a->size[1] * a->size[2] * (subsa_idx_3 - 1)) +
                             1];
          b_data[((4 * c_k + 4 * b->size[1] * (subsa_idx_2 - 1)) +
                  4 * b->size[1] * b->size[2] * (subsa_idx_3 - 1)) +
                 2] = a_data[((4 * c_k + 4 * a->size[1] * (subsa_idx_2 - 1)) +
                              4 * a->size[1] * a->size[2] * (subsa_idx_3 - 1)) +
                             2];
          b_data[((4 * c_k + 4 * b->size[1] * (subsa_idx_2 - 1)) +
                  4 * b->size[1] * b->size[2] * (subsa_idx_3 - 1)) +
                 3] = a_data[((4 * c_k + 4 * a->size[1] * (subsa_idx_2 - 1)) +
                              4 * a->size[1] * a->size[2] * (subsa_idx_3 - 1)) +
                             3];
        }
      }
    }
  }
}

/* End of code generation (permute.c) */
