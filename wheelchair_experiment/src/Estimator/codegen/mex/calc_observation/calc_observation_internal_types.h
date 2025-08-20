/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_observation_internal_types.h
 *
 * Code generation for function 'calc_observation'
 *
 */

#pragma once

/* Include files */
#include "calc_observation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct {
  real_T workspace_float[120];
  int32_T workspace_int[15];
  int32_T workspace_sort[15];
} c_struct_T;
#endif /* typedef_c_struct_T */

#ifndef typedef_e_struct_T
#define typedef_e_struct_T
typedef struct {
  real_T Pbar[36];
  real_T R[25];
  real_T Yhbar[5];
  real_T MD_threshold;
} e_struct_T;
#endif /* typedef_e_struct_T */

#ifndef typedef_f_struct_T
#define typedef_f_struct_T
typedef struct {
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[5];
  real_T xstarsqp_old[5];
  real_T cIneq[2];
  real_T cIneq_old[2];
  real_T grad[8];
  real_T grad_old[8];
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  real_T lambdasqp[15];
  real_T lambdaStopTest[15];
  real_T lambdaStopTestPrev[15];
  real_T steplength;
  real_T delta_x[8];
  real_T socDirection[8];
  int32_T workingset_old[15];
  real_T JacCineqTrans_old[8];
  real_T gradLag[8];
  real_T delta_gradLag[8];
  real_T xstar[8];
  real_T fstar;
  real_T lambda[15];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[8];
} f_struct_T;
#endif /* typedef_f_struct_T */

#ifndef typedef_g_struct_T
#define typedef_g_struct_T
typedef struct {
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T nVar;
  real_T Aineq[16];
  real_T bineq[2];
  real_T lb[8];
  real_T ub[8];
  int32_T indexLB[8];
  int32_T indexUB[8];
  int32_T indexFixed[8];
  int32_T mEqRemoved;
  real_T ATwset[120];
  real_T bwset[15];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[15];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[15];
  int32_T Wid[15];
  int32_T Wlocalidx[15];
  int32_T nWConstr[5];
  int32_T probType;
} g_struct_T;
#endif /* typedef_g_struct_T */

#ifndef typedef_i_struct_T
#define typedef_i_struct_T
typedef struct {
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
} i_struct_T;
#endif /* typedef_i_struct_T */

#ifndef typedef_j_struct_T
#define typedef_j_struct_T
typedef struct {
  real_T QR[225];
  real_T Q[225];
  int32_T jpvt[15];
  int32_T mrows;
  int32_T ncols;
  real_T tau[15];
  int32_T minRowCol;
  boolean_T usedPivoting;
} j_struct_T;
#endif /* typedef_j_struct_T */

#ifndef typedef_k_struct_T
#define typedef_k_struct_T
typedef struct {
  real_T FMat[225];
  int32_T ndims;
  int32_T info;
  boolean_T ConvexCheck;
  real_T workspace_;
} k_struct_T;
#endif /* typedef_k_struct_T */

#ifndef typedef_l_struct_T
#define typedef_l_struct_T
typedef struct {
  real_T grad[8];
  real_T Hx[7];
  boolean_T hasLinear;
  int32_T nvar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
} l_struct_T;
#endif /* typedef_l_struct_T */

#ifndef typedef_m_struct_T
#define typedef_m_struct_T
typedef struct {
  char_T SolverName[7];
  int32_T MaxIterations;
} m_struct_T;
#endif /* typedef_m_struct_T */

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

#ifndef typedef_rtRunTimeErrorInfo
#define typedef_rtRunTimeErrorInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtRunTimeErrorInfo;
#endif /* typedef_rtRunTimeErrorInfo */

/* End of code generation (calc_observation_internal_types.h) */
