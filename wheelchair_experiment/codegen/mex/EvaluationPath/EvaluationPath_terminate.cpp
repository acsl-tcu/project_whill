//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EvaluationPath_terminate.cpp
//
//  Code generation for function 'EvaluationPath_terminate'
//


// Include files
#include "EvaluationPath_terminate.h"
#include "EvaluationPath_data.h"
#include "_coder_EvaluationPath_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void EvaluationPath_atexit()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtProfilerUnregisterMEXFcn(EvaluationPath_complete_name,
    static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerUnregisterMEXFcn(FPM_4_complete_name, static_cast<boolean_T>
    (isMexOutdated));
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void EvaluationPath_terminate()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (EvaluationPath_terminate.cpp)
