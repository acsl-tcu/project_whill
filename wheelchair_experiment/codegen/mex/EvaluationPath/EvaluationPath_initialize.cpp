//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EvaluationPath_initialize.cpp
//
//  Code generation for function 'EvaluationPath_initialize'
//


// Include files
#include "EvaluationPath_initialize.h"
#include "EvaluationPath_data.h"
#include "_coder_EvaluationPath_mex.h"
#include "rt_nonfinite.h"

// Function Declarations
static void EvaluationPath_once();

// Function Definitions
static void EvaluationPath_once()
{
  static const int32_T b_lineInfo[49] = { 2, 4, 5, 6, 7, 9, 10, 11, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 23, 25, 38, 39, 40, 51, 53, 59, 62, 63, 64, 65, 66,
    67, 69, 72, 73, 76, 77, 78, 79, 80, 81, 82, 83, 84, 109, 110, 111, 112, 113,
    114 };

  static const int32_T lineInfo[22] = { 4, 5, 6, 7, 8, 11, 13, 14, 16, 17, 19,
    20, 22, 23, 27, 78, 79, 80, 81, 82, 83, 84 };

  mex_InitInfAndNan();
  FPM_4_complete_name =
    "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m>FPM_4(codegen)";
  EvaluationPath_complete_name =
    "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m>EvaluationPath(codegen)";
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  emlrtProfilerRegisterMEXFcn(EvaluationPath_complete_name,
    "/home/ekawaguchi/デスクトップ/0307program/EvaluationPath.m",
    "EvaluationPath", 22, &lineInfo[0], static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(FPM_4_complete_name,
    "/home/ekawaguchi/デスクトップ/0307program/FPM_4.m", "FPM_4", 49,
    &b_lineInfo[0], static_cast<boolean_T>(isMexOutdated));
}

void EvaluationPath_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    EvaluationPath_once();
  }
}

// End of code generation (EvaluationPath_initialize.cpp)
