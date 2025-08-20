/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_observation_emxutil.h
 *
 * Code generation for function 'calc_observation_emxutil'
 *
 */

#pragma once

/* Include files */
#include "calc_observation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void c_emxFreeStruct_anonymous_funct(const emlrtStack *sp,
                                     b_anonymous_function *pStruct);

void c_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     coder_internal_stickyStruct *pStruct);

void c_emxInitStruct_anonymous_funct(const emlrtStack *sp,
                                     b_anonymous_function *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void c_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     i_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void d_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     b_coder_internal_stickyStruct *pStruct);

void d_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     h_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void e_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     c_coder_internal_stickyStruct *pStruct);

void e_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     g_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_struct2_T(const emlrtStack *sp,
                                 emxArray_struct2_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxFreeStruct_pointCloud(const emlrtStack *sp, pointCloud *pStruct);

void emxFreeStruct_struct_T(const emlrtStack *sp, d_struct_T *pStruct);

void emxFreeStruct_struct_T1(const emlrtStack *sp, h_struct_T *pStruct);

void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray);

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxFree_struct2_T(const emlrtStack *sp, emxArray_struct2_T **pEmxArray);

void emxFree_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray);

void emxInitStruct_pointCloud(const emlrtStack *sp, pointCloud *pStruct,
                              const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct_T(const emlrtStack *sp, d_struct_T *pStruct,
                            const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct_T1(const emlrtStack *sp, h_struct_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation);

void emxInit_struct2_T(const emlrtStack *sp, emxArray_struct2_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

void emxInit_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void f_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     d_coder_internal_stickyStruct *pStruct);

void f_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     f_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void g_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     e_coder_internal_stickyStruct *pStruct);

void g_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     e_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void h_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     f_coder_internal_stickyStruct *pStruct);

void h_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     d_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void i_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     g_coder_internal_stickyStruct *pStruct);

void i_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     c_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void j_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     h_coder_internal_stickyStruct *pStruct);

void j_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     b_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void k_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     i_coder_internal_stickyStruct *pStruct);

void k_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation);

/* End of code generation (calc_observation_emxutil.h) */
