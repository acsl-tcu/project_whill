/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * handle.c
 *
 * Code generation for function 'handle'
 *
 */

/* Include files */
#include "handle.h"
#include "calc_observation_types.h"
#include "rt_nonfinite.h"
#include "cvstCG_kdtree.h"
#include <string.h>

/* Function Definitions */
void handle_matlabCodegenDestructor(const emlrtStack *sp, pointCloud *obj)
{
  void *locationPtr;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->HasLocationHandleAllocated) {
      locationPtr = obj->LocationHandle;
      kdtreeDeleteLocationDataPointer_double(locationPtr);
      obj->HasLocationHandleAllocated = false;
    }
    if (obj->HasKdtreeConstructed) {
      locationPtr = obj->Kdtree;
      kdtreeDeleteObj_double(locationPtr);
      obj->HasKdtreeConstructed = false;
    }
  }
}

/* End of code generation (handle.c) */
