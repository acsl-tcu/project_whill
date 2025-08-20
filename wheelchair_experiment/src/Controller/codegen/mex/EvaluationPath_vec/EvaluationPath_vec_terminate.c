/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath_vec_terminate.c
 *
 * Code generation for function 'EvaluationPath_vec_terminate'
 *
 */

/* Include files */
#include "EvaluationPath_vec_terminate.h"
#include "EvaluationPath_vec_data.h"
#include "_coder_EvaluationPath_vec_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void emlrtExitTimeCleanupDtorFcn(const void *r);

/* Function Definitions */
static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void EvaluationPath_vec_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(
      &st, false, NULL, (void *)&emlrtExitTimeCleanupDtorFcn, NULL, NULL, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtProfilerUnregisterMEXFcn((char_T *)c_EvaluationPath_vec_complete_n,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)c_FPM_capsule_v3_3vec_complete_,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)get_distance_complete_name,
                                isMexOutdated);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void EvaluationPath_vec_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (EvaluationPath_vec_terminate.c) */
