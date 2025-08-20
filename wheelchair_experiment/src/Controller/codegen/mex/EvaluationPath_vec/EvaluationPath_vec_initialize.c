/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvaluationPath_vec_initialize.c
 *
 * Code generation for function 'EvaluationPath_vec_initialize'
 *
 */

/* Include files */
#include "EvaluationPath_vec_initialize.h"
#include "EvaluationPath_vec_data.h"
#include "_coder_EvaluationPath_vec_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void EvaluationPath_vec_once(void);

/* Function Definitions */
static void EvaluationPath_vec_once(void)
{
  static const int32_T b_lineInfo[86] = {
      9,   10,  11,  12,  16,  17,  18,  19,  21,  22,  23,  24,  25,  27,  31,
      36,  37,  44,  45,  46,  48,  56,  58,  59,  60,  61,  62,  63,  64,  65,
      66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  77,  79,  80,  82,  83,
      85,  86,  87,  89,  90,  91,  93,  94,  95,  97,  99,  100, 101, 102, 104,
      105, 106, 107, 108, 110, 111, 112, 113, 114, 115, 117, 118, 121, 122, 123,
      124, 126, 127, 128, 129, 132, 133, 136, 142, 146, 149};
  static const int32_T lineInfo[41] = {
      5,  7,  8,  10, 11, 13, 14, 16, 17, 20, 21, 22, 24, 26,
      28, 30, 33, 34, 37, 38, 39, 40, 43, 44, 45, 47, 48, 51,
      52, 53, 54, 57, 59, 62, 63, 64, 65, 66, 67, 71, 73};
  static const int32_T c_lineInfo[6] = {4, 6, 10, 12, 14, 15};
  mex_InitInfAndNan();
  get_distance_complete_name =
      "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
      "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_"
      "07/caps"
      "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
      "src/Controller/get_distance.m>get_distance(codegen)";
  c_FPM_capsule_v3_3vec_complete_ =
      "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
      "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_"
      "07/caps"
      "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
      "src/Controller/FPM_capsule_v3_3vec.m>FPM_capsule_v3_3vec("
      "codegen)";
  c_EvaluationPath_vec_complete_n =
      "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
      "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_"
      "07/caps"
      "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
      "src/Controller/EvaluationPath_vec.m>EvaluationPath_vec(co"
      "degen)";
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_EvaluationPath_vec_complete_n,
      (char_T *)"/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
                "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_"
                "2025_06_07/caps"
                "uele_v5.3_"
                "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
                "src/Controller/EvaluationPath_vec.m",
      (char_T *)"EvaluationPath_vec", 41, &lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_FPM_capsule_v3_3vec_complete_,
      (char_T *)"/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
                "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_"
                "2025_06_07/caps"
                "uele_v5.3_"
                "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
                "src/Controller/FPM_capsule_v3_3vec.m",
      (char_T *)"FPM_capsule_v3_3vec", 86, &b_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)get_distance_complete_name,
      (char_T *)"/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
                "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_"
                "2025_06_07/caps"
                "uele_v5.3_"
                "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
                "src/Controller/get_distance.m",
      (char_T *)"get_distance", 6, &c_lineInfo[0], isMexOutdated);
}

void EvaluationPath_vec_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
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
    EvaluationPath_vec_once();
  }
  emlrtCheckProfilerStatus();
}

/* End of code generation (EvaluationPath_vec_initialize.c) */
