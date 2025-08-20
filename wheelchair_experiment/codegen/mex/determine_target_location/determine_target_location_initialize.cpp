//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  determine_target_location_initialize.cpp
//
//  Code generation for function 'determine_target_location_initialize'
//


// Include files
#include "determine_target_location_initialize.h"
#include "_coder_determine_target_location_mex.h"
#include "determine_target_location_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void determine_target_location_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation (determine_target_location_initialize.cpp)
