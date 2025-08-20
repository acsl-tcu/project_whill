/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Discretemodel_initialize.c
 *
 * Code generation for function 'Discretemodel_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Discretemodel.h"
#include "Discretemodel_initialize.h"
#include "_coder_Discretemodel_mex.h"
#include "Discretemodel_data.h"

/* Function Declarations */
static void Discretemodel_once(void);

/* Function Definitions */
static void Discretemodel_once(void)
{
  int32_T i0;
  int32_T iv1[8];
  Discretemodel_complete_name =
    "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m>Discretemodel(codegen)";
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  for (i0 = 0; i0 < 8; i0++) {
    iv1[i0] = 2 + i0;
  }

  emlrtProfilerRegisterMEXFcn(Discretemodel_complete_name,
    "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m", "Discretemodel", 8, iv1,
    isMexOutdated);
}

void Discretemodel_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    Discretemodel_once();
  }
}

/* End of code generation (Discretemodel_initialize.c) */
