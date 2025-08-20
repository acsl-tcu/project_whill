/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath_initialize.c
 *
 * Code generation for function 'EvaluationPath_initialize'
 *
 */

/* Include files */
#include "EvaluationPath_initialize.h"
#include "EvaluationPath_data.h"
#include "_coder_EvaluationPath_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void EvaluationPath_once(void);

/* Function Definitions */
static void EvaluationPath_once(void)
{
  static const int32_T b_lineInfo[86] = {
      9,   10,  11,  12,  16,  17,  18,  19,  21,  22,  23,  24,  25,  27,  31,
      36,  37,  39,  40,  41,  49,  51,  52,  53,  54,  55,  56,  57,  58,  59,
      60,  61,  62,  63,  64,  65,  66,  67,  68,  70,  72,  73,  75,  76,  78,
      79,  80,  82,  83,  84,  86,  87,  88,  90,  92,  93,  94,  95,  97,  98,
      99,  100, 101, 103, 104, 105, 106, 107, 108, 110, 111, 114, 115, 116, 117,
      119, 121, 122, 126, 127, 129, 130, 131, 132, 133, 136};
  static const int32_T lineInfo[37] = {
      5,   7,   9,   13,  15,  16,  18,  19,  21,  22,  24, 25, 28,
      29,  30,  32,  34,  36,  38,  40,  41,  45,  47,  49, 52, 187,
      188, 190, 197, 199, 200, 201, 204, 205, 207, 210, 211};
  mex_InitInfAndNan();
  FPM_capsule_v3_1_complete_name =
      "/home/takumi/Document/"
      "capsuele_v5.1_"
      "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
      "Controller/FPM_capsule_v3_1"
      ".m>FPM_capsule_v3_1(codegen)";
  EvaluationPath_complete_name =
      "/home/takumi/Document/"
      "capsuele_v5.1_"
      "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
      "Controller/EvaluationPath.m"
      ">EvaluationPath(codegen)";
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  emlrtProfilerRegisterMEXFcn(
      (char_T *)EvaluationPath_complete_name,
      (char_T *)"/home/takumi/Document/"
                "capsuele_v5.1_"
                "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
                "src/Controller/EvaluationPath.m",
      (char_T *)"EvaluationPath", 37, &lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)FPM_capsule_v3_1_complete_name,
      (char_T *)"/home/takumi/Document/"
                "capsuele_v5.1_"
                "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
                "src/Controller/FPM_capsule_v3_1"
                ".m",
      (char_T *)"FPM_capsule_v3_1", 86, &b_lineInfo[0], isMexOutdated);
}

void EvaluationPath_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    EvaluationPath_once();
  }
  emlrtCheckProfilerStatus();
}

/* End of code generation (EvaluationPath_initialize.c) */
