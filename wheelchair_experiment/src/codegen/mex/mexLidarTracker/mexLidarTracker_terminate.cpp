//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mexLidarTracker_terminate.cpp
//
//  Code generation for function 'mexLidarTracker_terminate'
//


// Include files
#include "mexLidarTracker_terminate.h"
#include "_coder_mexLidarTracker_mex.h"
#include "mexLidarTracker.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void mexLidarTracker_atexit()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  mexLidarTracker_free();
  emlrtProfilerUnregisterMEXFcn(mexLidarTracker_complete_name, static_cast<
    boolean_T>(isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(c_HelperBoundingBoxDetector_Hel,
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(c_HelperBoundingBoxDetector_ste,
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(cropPointCloud2_complete_name,
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(removeGroundPlane_complete_name,
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(getBoundingBoxes_complete_name,
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(homogeneous_complete_name, static_cast<boolean_T>
    (isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(c_assembleDetections_complete_n,
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(initializeEKF_complete_name,
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(c_helperCalcDetectability_compl,
    static_cast<boolean_T>(isMexOutdated));
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void mexLidarTracker_terminate()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (mexLidarTracker_terminate.cpp)
