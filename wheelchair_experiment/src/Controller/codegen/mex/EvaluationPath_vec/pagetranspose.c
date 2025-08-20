/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pagetranspose.c
 *
 * Code generation for function 'pagetranspose'
 *
 */

/* Include files */
#include "pagetranspose.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo jb_emlrtRSI = {
    8,               /* lineNo */
    "pagetranspose", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagetranspose.m" /* pathName
                                                                           */
};

static emlrtRTEInfo jd_emlrtRTEI = {
    8,               /* lineNo */
    1,               /* colNo */
    "pagetranspose", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagetranspose.m" /* pName
                                                                           */
};

/* Function Definitions */
void b_pagetranspose(const emlrtStack *sp, const real_T x_data[],
                     const int32_T x_size[3], real_T y_data[],
                     int32_T y_size[3])
{
  static const int8_T b_iv[3] = {2, 1, 3};
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_k;
  int32_T c_k;
  int32_T k;
  int32_T plast;
  int8_T subsa_idx_2;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b = true;
  if (x_size[1] != 0) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (x_size[b_iv[k] - 1] != 1) {
        if (plast > b_iv[k]) {
          b = false;
          exitg1 = true;
        } else {
          plast = b_iv[k];
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b) {
    int32_T n;
    b_st.site = &kb_emlrtRSI;
    plast = 6 * x_size[1] * 21;
    n = 6;
    if (x_size[1] > 6) {
      n = x_size[1];
    }
    if (n < 21) {
      n = 21;
    }
    if (x_size[1] > muIntScalarMax_sint32(plast, n)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    y_size[0] = x_size[1];
    y_size[1] = 6;
    y_size[2] = 21;
    if (plast - 1 >= 0) {
      memcpy(&y_data[0], &x_data[0], (uint32_T)plast * sizeof(real_T));
    }
  } else {
    int32_T n;
    b_st.site = &lb_emlrtRSI;
    plast = 6 * x_size[1] * 21;
    n = 6;
    if (x_size[1] > 6) {
      n = x_size[1];
    }
    if (n < 21) {
      n = 21;
    }
    if (x_size[1] > muIntScalarMax_sint32(plast, n)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    plast = x_size[1];
    y_size[0] = x_size[1];
    y_size[1] = 6;
    y_size[2] = 21;
    for (k = 0; k < 21; k++) {
      if (plast - 1 >= 0) {
        subsa_idx_2 = (int8_T)(k + 1);
      }
      for (b_k = 0; b_k < plast; b_k++) {
        n = y_size[0];
        for (c_k = 0; c_k < 6; c_k++) {
          y_data[(b_k + n * c_k) + n * 6 * (subsa_idx_2 - 1)] =
              x_data[(c_k + 6 * b_k) + 6 * x_size[1] * (subsa_idx_2 - 1)];
        }
      }
    }
  }
}

void c_pagetranspose(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *y)
{
  static const int8_T b_iv[4] = {2, 1, 3, 4};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  const real_T *x_data;
  real_T *y_data;
  int32_T b_k;
  int32_T k;
  int32_T plast;
  int32_T subsa_idx_3;
  boolean_T b;
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
  x_data = x->data;
  st.site = &jb_emlrtRSI;
  b = true;
  if ((x->size[2] != 0) && (x->size[3] != 0)) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (x->size[b_iv[k] - 1] != 1) {
        if (plast > b_iv[k]) {
          b = false;
          exitg1 = true;
        } else {
          plast = b_iv[k];
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b) {
    int32_T nx_tmp;
    b_st.site = &kb_emlrtRSI;
    nx_tmp = (x->size[2] << 1) * x->size[3];
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    plast = 2;
    if (x->size[2] > 2) {
      plast = x->size[2];
    }
    if (x->size[3] > plast) {
      plast = x->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (x->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 2;
    y->size[2] = x->size[2];
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&st, y, b_k, &jd_emlrtRTEI);
    y_data = y->data;
    for (b_k = 0; b_k < nx_tmp; b_k++) {
      y_data[b_k] = x_data[b_k];
    }
  } else {
    int32_T nx_tmp;
    b_st.site = &lb_emlrtRSI;
    nx_tmp = (x->size[2] << 1) * x->size[3];
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    plast = 2;
    if (x->size[2] > 2) {
      plast = x->size[2];
    }
    if (x->size[3] > plast) {
      plast = x->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (x->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 2;
    plast = x->size[2];
    y->size[2] = x->size[2];
    nx_tmp = x->size[3];
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&st, y, b_k, &kd_emlrtRTEI);
    y_data = y->data;
    b_st.site = &mb_emlrtRSI;
    c_st.site = &nb_emlrtRSI;
    if (x->size[3] > 2147483646) {
      d_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < nx_tmp; k++) {
      c_st.site = &ob_emlrtRSI;
      d_st.site = &nb_emlrtRSI;
      if (x->size[2] > 2147483646) {
        e_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      if (x->size[2] - 1 >= 0) {
        subsa_idx_3 = k + 1;
      }
      for (b_k = 0; b_k < plast; b_k++) {
        y_data[2 * b_k + 2 * y->size[2] * (subsa_idx_3 - 1)] =
            x_data[2 * b_k + 2 * x->size[2] * (subsa_idx_3 - 1)];
        y_data[(2 * b_k + 2 * y->size[2] * (subsa_idx_3 - 1)) + 1] =
            x_data[(2 * b_k + 2 * x->size[2] * (subsa_idx_3 - 1)) + 1];
      }
    }
  }
}

void d_pagetranspose(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *y)
{
  static const int8_T b_iv[4] = {2, 1, 3, 4};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const real_T *x_data;
  real_T *y_data;
  int32_T b_k;
  int32_T c_k;
  int32_T d_k;
  int32_T i;
  int32_T k;
  int32_T plast;
  int32_T subsa_idx_1;
  int32_T subsa_idx_2;
  int32_T subsa_idx_3;
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
  x_data = x->data;
  st.site = &jb_emlrtRSI;
  overflow = true;
  if ((x->size[0] != 0) && (x->size[2] != 0) && (x->size[3] != 0)) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (x->size[b_iv[k] - 1] != 1) {
        if (plast > b_iv[k]) {
          overflow = false;
          exitg1 = true;
        } else {
          plast = b_iv[k];
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (overflow) {
    int32_T nx_tmp;
    b_st.site = &kb_emlrtRSI;
    nx_tmp = (x->size[0] << 1) * x->size[2] * x->size[3];
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    plast = x->size[0];
    if (x->size[0] < 2) {
      plast = 2;
    }
    if (x->size[2] > plast) {
      plast = x->size[2];
    }
    if (x->size[3] > plast) {
      plast = x->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (x->size[0] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    i = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 2;
    y->size[1] = x->size[0];
    y->size[2] = x->size[2];
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&st, y, i, &jd_emlrtRTEI);
    y_data = y->data;
    for (i = 0; i < nx_tmp; i++) {
      y_data[i] = x_data[i];
    }
  } else {
    int32_T nx_tmp;
    b_st.site = &lb_emlrtRSI;
    nx_tmp = (x->size[0] << 1) * x->size[2] * x->size[3];
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    plast = x->size[0];
    if (x->size[0] < 2) {
      plast = 2;
    }
    if (x->size[2] > plast) {
      plast = x->size[2];
    }
    if (x->size[3] > plast) {
      plast = x->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (x->size[0] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    i = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 2;
    y->size[1] = x->size[0];
    plast = x->size[2];
    y->size[2] = x->size[2];
    nx_tmp = x->size[3];
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&st, y, i, &kd_emlrtRTEI);
    y_data = y->data;
    b_st.site = &mb_emlrtRSI;
    c_st.site = &nb_emlrtRSI;
    if (x->size[3] > 2147483646) {
      d_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < nx_tmp; k++) {
      c_st.site = &ob_emlrtRSI;
      d_st.site = &nb_emlrtRSI;
      if (x->size[2] > 2147483646) {
        e_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (b_k = 0; b_k < plast; b_k++) {
        d_st.site = &ob_emlrtRSI;
        overflow = (x->size[0] > 2147483646);
        i = (uint8_T)x->size[0];
        for (c_k = 0; c_k < 2; c_k++) {
          e_st.site = &ob_emlrtRSI;
          f_st.site = &nb_emlrtRSI;
          if (overflow) {
            g_st.site = &gb_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }
          if ((uint8_T)x->size[0] - 1 >= 0) {
            subsa_idx_1 = c_k + 1;
            subsa_idx_2 = b_k + 1;
            subsa_idx_3 = k + 1;
          }
          for (d_k = 0; d_k < i; d_k++) {
            y_data[(((subsa_idx_1 + 2 * d_k) +
                     2 * y->size[1] * (subsa_idx_2 - 1)) +
                    2 * y->size[1] * y->size[2] * (subsa_idx_3 - 1)) -
                   1] = x_data[((d_k + x->size[0] * (subsa_idx_1 - 1)) +
                                x->size[0] * 2 * (subsa_idx_2 - 1)) +
                               x->size[0] * 2 * x->size[2] * (subsa_idx_3 - 1)];
          }
        }
      }
    }
  }
}

void e_pagetranspose(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *y)
{
  static const int8_T b_iv[4] = {2, 1, 3, 4};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const real_T *x_data;
  real_T *y_data;
  int32_T b_k;
  int32_T c_k;
  int32_T d_k;
  int32_T i;
  int32_T k;
  int32_T plast;
  int32_T subsa_idx_1;
  int32_T subsa_idx_2;
  int32_T subsa_idx_3;
  boolean_T b;
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
  x_data = x->data;
  st.site = &jb_emlrtRSI;
  b = true;
  if ((x->size[0] != 0) && (x->size[1] != 0) && (x->size[2] != 0) &&
      (x->size[3] != 0)) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (x->size[b_iv[k] - 1] != 1) {
        if (plast > b_iv[k]) {
          b = false;
          exitg1 = true;
        } else {
          plast = b_iv[k];
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b) {
    int32_T nx_tmp;
    b_st.site = &kb_emlrtRSI;
    nx_tmp = x->size[0] * x->size[1] * x->size[2] * x->size[3];
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    plast = x->size[0];
    if (x->size[1] > x->size[0]) {
      plast = x->size[1];
    }
    if (x->size[2] > plast) {
      plast = x->size[2];
    }
    if (x->size[3] > plast) {
      plast = x->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (x->size[1] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[0] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    i = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = x->size[1];
    y->size[1] = x->size[0];
    y->size[2] = x->size[2];
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&st, y, i, &jd_emlrtRTEI);
    y_data = y->data;
    for (i = 0; i < nx_tmp; i++) {
      y_data[i] = x_data[i];
    }
  } else {
    int32_T nx_tmp;
    b_st.site = &lb_emlrtRSI;
    nx_tmp = x->size[0] * x->size[1] * x->size[2] * x->size[3];
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    plast = x->size[0];
    if (x->size[1] > x->size[0]) {
      plast = x->size[1];
    }
    if (x->size[2] > plast) {
      plast = x->size[2];
    }
    if (x->size[3] > plast) {
      plast = x->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (x->size[1] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[0] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    i = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = x->size[1];
    y->size[1] = x->size[0];
    plast = x->size[2];
    y->size[2] = x->size[2];
    nx_tmp = x->size[3];
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&st, y, i, &kd_emlrtRTEI);
    y_data = y->data;
    b_st.site = &mb_emlrtRSI;
    c_st.site = &nb_emlrtRSI;
    if (x->size[3] > 2147483646) {
      d_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < nx_tmp; k++) {
      c_st.site = &ob_emlrtRSI;
      d_st.site = &nb_emlrtRSI;
      if (x->size[2] > 2147483646) {
        e_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (b_k = 0; b_k < plast; b_k++) {
        d_st.site = &ob_emlrtRSI;
        e_st.site = &nb_emlrtRSI;
        if (x->size[1] > 2147483646) {
          f_st.site = &gb_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }
        i = (uint8_T)x->size[1];
        for (c_k = 0; c_k < i; c_k++) {
          int32_T i1;
          e_st.site = &ob_emlrtRSI;
          f_st.site = &nb_emlrtRSI;
          if (x->size[0] > 2147483646) {
            g_st.site = &gb_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }
          i1 = (uint8_T)x->size[0];
          if ((uint8_T)x->size[0] - 1 >= 0) {
            subsa_idx_1 = c_k + 1;
            subsa_idx_2 = b_k + 1;
            subsa_idx_3 = k + 1;
          }
          for (d_k = 0; d_k < i1; d_k++) {
            y_data[(((subsa_idx_1 + y->size[0] * d_k) +
                     y->size[0] * y->size[1] * (subsa_idx_2 - 1)) +
                    y->size[0] * y->size[1] * y->size[2] * (subsa_idx_3 - 1)) -
                   1] = x_data[((d_k + x->size[0] * (subsa_idx_1 - 1)) +
                                x->size[0] * x->size[1] * (subsa_idx_2 - 1)) +
                               x->size[0] * x->size[1] * x->size[2] *
                                   (subsa_idx_3 - 1)];
          }
        }
      }
    }
  }
}

void pagetranspose(const emlrtStack *sp, const emxArray_real_T *x,
                   emxArray_real_T *y)
{
  static const int8_T b_iv[4] = {2, 1, 3, 4};
  emlrtStack b_st;
  emlrtStack st;
  const real_T *x_data;
  real_T *y_data;
  int32_T b_k;
  int32_T c_k;
  int32_T d_k;
  int32_T k;
  int32_T plast;
  int16_T subsa_idx_1;
  int16_T subsa_idx_2;
  int16_T subsa_idx_3;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  st.site = &jb_emlrtRSI;
  b = true;
  if ((x->size[0] != 0) && (x->size[2] != 0) && (x->size[3] != 0)) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (x->size[b_iv[k] - 1] != 1) {
        if (plast > b_iv[k]) {
          b = false;
          exitg1 = true;
        } else {
          plast = b_iv[k];
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b) {
    int32_T nx_tmp;
    b_st.site = &kb_emlrtRSI;
    nx_tmp = (x->size[0] << 2) * x->size[2] * x->size[3];
    plast = x->size[0];
    if (x->size[0] < 4) {
      plast = 4;
    }
    if (x->size[2] > plast) {
      plast = x->size[2];
    }
    if (x->size[3] > plast) {
      plast = x->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (x->size[0] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 4;
    y->size[1] = x->size[0];
    y->size[2] = x->size[2];
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&st, y, b_k, &jd_emlrtRTEI);
    y_data = y->data;
    for (b_k = 0; b_k < nx_tmp; b_k++) {
      y_data[b_k] = x_data[b_k];
    }
  } else {
    int32_T n_tmp;
    int32_T nx_tmp;
    b_st.site = &lb_emlrtRSI;
    nx_tmp = (x->size[0] << 2) * x->size[2] * x->size[3];
    n_tmp = x->size[0];
    plast = x->size[0];
    if (x->size[0] < 4) {
      plast = 4;
    }
    if (x->size[2] > plast) {
      plast = x->size[2];
    }
    if (x->size[3] > plast) {
      plast = x->size[3];
    }
    plast = muIntScalarMax_sint32(nx_tmp, plast);
    if (x->size[0] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[2] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (x->size[3] > plast) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 4;
    y->size[1] = x->size[0];
    plast = x->size[2];
    y->size[2] = x->size[2];
    nx_tmp = x->size[3];
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&st, y, b_k, &kd_emlrtRTEI);
    y_data = y->data;
    for (k = 0; k < nx_tmp; k++) {
      for (b_k = 0; b_k < plast; b_k++) {
        for (c_k = 0; c_k < 4; c_k++) {
          if (n_tmp - 1 >= 0) {
            subsa_idx_1 = (int16_T)(c_k + 1);
            subsa_idx_2 = (int16_T)(b_k + 1);
            subsa_idx_3 = (int16_T)(k + 1);
          }
          for (d_k = 0; d_k < n_tmp; d_k++) {
            y_data[(((subsa_idx_1 + 4 * d_k) +
                     4 * y->size[1] * (subsa_idx_2 - 1)) +
                    4 * y->size[1] * y->size[2] * (subsa_idx_3 - 1)) -
                   1] = x_data[((d_k + x->size[0] * (subsa_idx_1 - 1)) +
                                x->size[0] * 4 * (subsa_idx_2 - 1)) +
                               x->size[0] * 4 * x->size[2] * (subsa_idx_3 - 1)];
          }
        }
      }
    }
  }
}

/* End of code generation (pagetranspose.c) */
