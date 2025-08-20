/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexLidarTracker_initialize.c
 *
 * Code generation for function 'mexLidarTracker_initialize'
 *
 */

/* Include files */
#include "mexLidarTracker_initialize.h"
#include "_coder_mexLidarTracker_mex.h"
#include "mexLidarTracker.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

/* Function Declarations */
static void mexLidarTracker_once(const emlrtStack *sp);

/* Function Definitions */
static void mexLidarTracker_once(const emlrtStack *sp)
{
  static const int32_T f_lineInfo[33] = {
      75,  76,  83,  84,  85,  108, 109, 119, 120, 121, 122,
      129, 134, 135, 136, 137, 138, 140, 142, 143, 144, 145,
      146, 147, 148, 149, 150, 151, 152, 153, 154, 157, 158};
  static const int32_T d_lineInfo[30] = {101, 102, 104, 105, 106, 107, 108, 109,
                                         110, 111, 112, 113, 114, 115, 116, 117,
                                         118, 119, 120, 121, 122, 123, 124, 128,
                                         129, 130, 131, 132, 133, 158};
  static const int32_T lineInfo[24] = {4,  7,  14, 16, 19, 20, 21, 22,
                                       27, 30, 32, 33, 34, 35, 40, 42,
                                       43, 45, 50, 61, 63, 64, 80, 94};
  static const int32_T c_lineInfo[22] = {251, 252, 255, 256, 257, 258, 259, 260,
                                         261, 263, 264, 266, 267, 268, 269, 270,
                                         271, 279, 280, 281, 282, 283};
  static const int32_T b_lineInfo[9] = {63, 67, 69, 70, 71, 72, 73, 74, 75};
  static const int32_T e_lineInfo[9] = {4, 5, 6, 8, 9, 11, 14, 15, 16};
  __m128i r;
  __m128i r1;
  emlrtStack st;
  int32_T b_iv2[26];
  int32_T b_iv1[8];
  int32_T b_iv[2];
  int32_T i;
  mex_InitInfAndNan();
  st.prev = sp;
  st.tls = sp->tls;
  c_helperCalcDetectability_compl =
      "/home/student/"
      "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88"
      "/TMaehara/kakuritu/helperCalcDetectability"
      ".m>helperCalcDetectability(codegen)";
  initializeEKF_complete_name =
      "/home/student/"
      "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88"
      "/TMaehara/kakuritu/initializeEKF.m>initial"
      "izeEKF(codegen)";
  c_assembleDetections_complete_n =
      "/home/student/"
      "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88"
      "/TMaehara/kakuritu/HelperBoundingBoxDetect"
      "or.m>assembleDetections(codegen)";
  homogeneous_complete_name =
      "/home/student/"
      "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88"
      "/TMaehara/kakuritu/homogeneous.m>homogeneo"
      "us(codegen)";
  getBoundingBoxes_complete_name =
      "/home/student/"
      "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88"
      "/TMaehara/kakuritu/HelperBoundingBoxDetect"
      "or.m>getBoundingBoxes(codegen)";
  cropPointCloud2_complete_name =
      "/home/student/"
      "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88"
      "/TMaehara/kakuritu/HelperBoundingBoxDetect"
      "or.m>cropPointCloud2(codegen)";
  c_HelperBoundingBoxDetector_ste =
      "/home/student/"
      "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88"
      "/TMaehara/kakuritu/HelperBoundingBoxDetect"
      "or.m>HelperBoundingBoxDetector.stepImpl(codegen)";
  c_HelperBoundingBoxDetector_Hel =
      "/home/student/"
      "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88"
      "/TMaehara/kakuritu/HelperBoundingBoxDetect"
      "or.m>HelperBoundingBoxDetector.HelperBoundingBoxDetector(codegen)";
  mexLidarTracker_complete_name =
      "/home/student/"
      "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88"
      "/TMaehara/kakuritu/mexLidarTracker.m>mexLi"
      "darTracker(codegen)";
  currentNumTracks_not_empty_init();
  b_detectableTracksInput_not_emp();
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  emlrtProfilerRegisterMEXFcn(
      (char_T *)mexLidarTracker_complete_name,
      (char_T *)"/home/student/"
                "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3"
                "\xe3\x83\x88/TMaehara/kakuritu/mexLidarTracker.m",
      (char_T *)"mexLidarTracker", 24, &lineInfo[0], isMexOutdated);
  b_iv[0] = 55;
  b_iv[1] = 56;
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_HelperBoundingBoxDetector_Hel,
      (char_T *)"/home/student/"
                "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3"
                "\xe3\x83\x88/TMaehara/kakuritu/HelperBoundingBoxDetect"
                "or.m",
      (char_T *)"HelperBoundingBoxDetector>HelperBoundingBoxDetector."
                "HelperBoundingBoxDetector",
      2, &b_iv[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_HelperBoundingBoxDetector_ste,
      (char_T *)"/home/student/"
                "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3"
                "\xe3\x83\x88/TMaehara/kakuritu/HelperBoundingBoxDetect"
                "or.m",
      (char_T *)"HelperBoundingBoxDetector>HelperBoundingBoxDetector.stepImpl",
      9, &b_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)cropPointCloud2_complete_name,
      (char_T *)"/home/student/"
                "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3"
                "\xe3\x83\x88/TMaehara/kakuritu/HelperBoundingBoxDetect"
                "or.m",
      (char_T *)"HelperBoundingBoxDetector>cropPointCloud2", 22, &c_lineInfo[0],
      isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)getBoundingBoxes_complete_name,
      (char_T *)"/home/student/"
                "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3"
                "\xe3\x83\x88/TMaehara/kakuritu/HelperBoundingBoxDetect"
                "or.m",
      (char_T *)"HelperBoundingBoxDetector>getBoundingBoxes", 30,
      &d_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)homogeneous_complete_name,
      (char_T *)"/home/student/"
                "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3"
                "\xe3\x83\x88/TMaehara/kakuritu/homogeneous.m",
      (char_T *)"homogeneous", 9, &e_lineInfo[0], isMexOutdated);
  r = _mm_set1_epi32(81);
  r1 = _mm_loadu_si128((const __m128i *)&iv[0]);
  _mm_storeu_si128((__m128i *)&b_iv1[0],
                   _mm_add_epi32(r, _mm_add_epi32(_mm_set1_epi32(0), r1)));
  _mm_storeu_si128((__m128i *)&b_iv1[4],
                   _mm_add_epi32(r, _mm_add_epi32(_mm_set1_epi32(4), r1)));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_assembleDetections_complete_n,
      (char_T *)"/home/student/"
                "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3"
                "\xe3\x83\x88/TMaehara/kakuritu/HelperBoundingBoxDetect"
                "or.m",
      (char_T *)"HelperBoundingBoxDetector>assembleDetections", 8, &b_iv1[0],
      isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)initializeEKF_complete_name,
      (char_T *)"/home/student/"
                "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3"
                "\xe3\x83\x88/TMaehara/kakuritu/initializeEKF.m",
      (char_T *)"initializeEKF", 33, &f_lineInfo[0], isMexOutdated);
  for (i = 0; i <= 20; i += 4) {
    _mm_storeu_si128(
        (__m128i *)&b_iv2[i],
        _mm_add_epi32(_mm_set1_epi32(13),
                      _mm_add_epi32(_mm_set1_epi32(i),
                                    _mm_loadu_si128((const __m128i *)&iv[0]))));
  }
  b_iv2[24] = 37;
  b_iv2[25] = 38;
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_helperCalcDetectability_compl,
      (char_T *)"/home/student/"
                "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3"
                "\xe3\x83\x88/TMaehara/kakuritu/helperCalcDetectability"
                ".m",
      (char_T *)"helperCalcDetectability", 26, &b_iv2[0], isMexOutdated);
  st.site = NULL;
  mexLidarTracker_init(&st);
}

void mexLidarTracker_initialize(void)
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
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "sensor_fusion_and_tracking", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "image_toolbox", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "video_and_image_blockset", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    mexLidarTracker_once(&st);
  }
  emlrtCheckProfilerStatus();
}

/* End of code generation (mexLidarTracker_initialize.c) */
