//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// EvaluationPath_GPU_data.cu
//
// Code generation for function 'EvaluationPath_GPU_data'
//

// Include files
#include "EvaluationPath_GPU_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                               // bFirstTime
    false,                                              // bInitialized
    131611U,                                            // fVersionInfo
    nullptr,                                            // fErrorFunction
    "EvaluationPath_GPU",                               // fFunctionName
    nullptr,                                            // fRTCallStack
    false,                                              // bDebugMode
    {3130694236U, 2616137409U, 972914731U, 129233577U}, // fSigWrd
    nullptr                                             // fSigMem
};

// End of code generation (EvaluationPath_GPU_data.cu)
