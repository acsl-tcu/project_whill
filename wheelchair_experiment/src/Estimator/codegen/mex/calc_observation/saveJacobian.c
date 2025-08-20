/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * saveJacobian.c
 *
 * Code generation for function 'saveJacobian'
 *
 */

/* Include files */
#include "saveJacobian.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo tg_emlrtRSI = {
    1,              /* lineNo */
    "saveJacobian", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+TrialState/saveJacobian.p" /* pathName */
};

/* Function Definitions */
void saveJacobian(const emlrtStack *sp, f_struct_T *obj, int32_T nVar,
                  const real_T JacCineqTrans[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  i = (uint8_T)nVar;
  st.site = &tg_emlrtRSI;
  b_st.site = &cf_emlrtRSI;
  c_st.site = &df_emlrtRSI;
  if (nVar > 2147483646) {
    d_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  memcpy(&obj->JacCineqTrans_old[0], &JacCineqTrans[8],
         (uint32_T)i * sizeof(real_T));
  st.site = &tg_emlrtRSI;
}

/* End of code generation (saveJacobian.c) */
