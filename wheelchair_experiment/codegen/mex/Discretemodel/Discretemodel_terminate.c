/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Discretemodel_terminate.c
 *
 * Code generation for function 'Discretemodel_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Discretemodel.h"
#include "Discretemodel_terminate.h"
#include "_coder_Discretemodel_mex.h"
#include "Discretemodel_data.h"

/* Function Definitions */
void Discretemodel_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtProfilerUnregisterMEXFcn(Discretemodel_complete_name, isMexOutdated);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Discretemodel_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Discretemodel_terminate.c) */
