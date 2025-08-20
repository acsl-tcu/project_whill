/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexLidarTracker_terminate.c
 *
 * Code generation for function 'mexLidarTracker_terminate'
 *
 */

/* Include files */
#include "mexLidarTracker_terminate.h"
#include "_coder_mexLidarTracker_mex.h"
#include "mexLidarTracker.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexLidarTracker_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  mexLidarTracker_free(&st);
  emlrtProfilerUnregisterMEXFcn((char_T *)mexLidarTracker_complete_name,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)c_HelperBoundingBoxDetector_Hel,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)c_HelperBoundingBoxDetector_ste,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)cropPointCloud2_complete_name,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)getBoundingBoxes_complete_name,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)homogeneous_complete_name,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)c_assembleDetections_complete_n,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)initializeEKF_complete_name,
                                isMexOutdated);
  emlrtProfilerUnregisterMEXFcn((char_T *)c_helperCalcDetectability_compl,
                                isMexOutdated);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void mexLidarTracker_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (mexLidarTracker_terminate.c) */
