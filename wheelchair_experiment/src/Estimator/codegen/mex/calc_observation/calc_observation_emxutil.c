/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_observation_emxutil.c
 *
 * Code generation for function 'calc_observation_emxutil'
 *
 */

/* Include files */
#include "calc_observation_emxutil.h"
#include "calc_observation_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void c_emxFreeStruct_anonymous_funct(const emlrtStack *sp,
                                     b_anonymous_function *pStruct)
{
  emxFreeStruct_struct_T(sp, &pStruct->workspace);
}

void c_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     coder_internal_stickyStruct *pStruct)
{
  c_emxFreeStruct_anonymous_funct(sp, &pStruct->value);
}

void c_emxInitStruct_anonymous_funct(const emlrtStack *sp,
                                     b_anonymous_function *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  emxInitStruct_struct_T(sp, &pStruct->workspace, srcLocation);
}

void c_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     i_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  d_emxInitStruct_coder_internal_(sp, &pStruct->next, srcLocation);
}

void d_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     b_coder_internal_stickyStruct *pStruct)
{
  c_emxFreeStruct_coder_internal_(sp, &pStruct->next);
}

void d_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     h_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  e_emxInitStruct_coder_internal_(sp, &pStruct->next, srcLocation);
}

void e_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     c_coder_internal_stickyStruct *pStruct)
{
  d_emxFreeStruct_coder_internal_(sp, &pStruct->next);
}

void e_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     g_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  f_emxInitStruct_coder_internal_(sp, &pStruct->next, srcLocation);
}

void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(boolean_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(int32_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(real_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_struct2_T(const emlrtStack *sp,
                                 emxArray_struct2_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(struct2_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(struct2_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (struct2_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxFreeStruct_pointCloud(const emlrtStack *sp, pointCloud *pStruct)
{
  emxFree_real_T(sp, &pStruct->Location);
  emxFree_uint8_T(sp, &pStruct->Color);
  emxFree_real_T(sp, &pStruct->Normal);
  emxFree_real_T(sp, &pStruct->Intensity);
}

void emxFreeStruct_struct_T(const emlrtStack *sp, d_struct_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->points);
}

void emxFreeStruct_struct_T1(const emlrtStack *sp, h_struct_T *pStruct)
{
  c_emxFreeStruct_anonymous_funct(sp, &pStruct->objfun);
}

void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxFree_struct2_T(const emlrtStack *sp, emxArray_struct2_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct2_T *)NULL) {
    if (((*pEmxArray)->data != (struct2_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_struct2_T *)NULL;
  }
}

void emxFree_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (uint8_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

void emxInitStruct_pointCloud(const emlrtStack *sp, pointCloud *pStruct,
                              const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->Location, 2, srcLocation);
  emxInit_uint8_T(sp, &pStruct->Color, srcLocation);
  emxInit_real_T(sp, &pStruct->Normal, 2, srcLocation);
  emxInit_real_T(sp, &pStruct->Intensity, 2, srcLocation);
}

void emxInitStruct_struct_T(const emlrtStack *sp, d_struct_T *pStruct,
                            const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->points, 2, srcLocation);
}

void emxInitStruct_struct_T1(const emlrtStack *sp, h_struct_T *pStruct,
                             const emlrtRTEInfo *srcLocation)
{
  c_emxInitStruct_anonymous_funct(sp, &pStruct->objfun, srcLocation);
}

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation)
{
  emxArray_boolean_T *emxArray;
  *pEmxArray =
      (emxArray_boolean_T *)emlrtMallocEmxArray(sizeof(emxArray_boolean_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_boolean_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation)
{
  emxArray_int32_T *emxArray;
  *pEmxArray =
      (emxArray_int32_T *)emlrtMallocEmxArray(sizeof(emxArray_int32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_int32_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size =
      (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_struct2_T(const emlrtStack *sp, emxArray_struct2_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation)
{
  emxArray_struct2_T *emxArray;
  *pEmxArray =
      (emxArray_struct2_T *)emlrtMallocEmxArray(sizeof(emxArray_struct2_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_struct2_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (struct2_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation)
{
  emxArray_uint8_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_uint8_T *)emlrtMallocEmxArray(sizeof(emxArray_uint8_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_uint8_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (uint8_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void f_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     d_coder_internal_stickyStruct *pStruct)
{
  e_emxFreeStruct_coder_internal_(sp, &pStruct->next);
}

void f_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     f_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  g_emxInitStruct_coder_internal_(sp, &pStruct->next, srcLocation);
}

void g_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     e_coder_internal_stickyStruct *pStruct)
{
  f_emxFreeStruct_coder_internal_(sp, &pStruct->next);
}

void g_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     e_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  h_emxInitStruct_coder_internal_(sp, &pStruct->next, srcLocation);
}

void h_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     f_coder_internal_stickyStruct *pStruct)
{
  g_emxFreeStruct_coder_internal_(sp, &pStruct->next);
}

void h_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     d_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  i_emxInitStruct_coder_internal_(sp, &pStruct->next, srcLocation);
}

void i_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     g_coder_internal_stickyStruct *pStruct)
{
  h_emxFreeStruct_coder_internal_(sp, &pStruct->next);
}

void i_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     c_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  j_emxInitStruct_coder_internal_(sp, &pStruct->next, srcLocation);
}

void j_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     h_coder_internal_stickyStruct *pStruct)
{
  i_emxFreeStruct_coder_internal_(sp, &pStruct->next);
}

void j_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     b_coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  k_emxInitStruct_coder_internal_(sp, &pStruct->next, srcLocation);
}

void k_emxFreeStruct_coder_internal_(const emlrtStack *sp,
                                     i_coder_internal_stickyStruct *pStruct)
{
  j_emxFreeStruct_coder_internal_(sp, &pStruct->next);
}

void k_emxInitStruct_coder_internal_(const emlrtStack *sp,
                                     coder_internal_stickyStruct *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  c_emxInitStruct_anonymous_funct(sp, &pStruct->value, srcLocation);
}

/* End of code generation (calc_observation_emxutil.c) */
