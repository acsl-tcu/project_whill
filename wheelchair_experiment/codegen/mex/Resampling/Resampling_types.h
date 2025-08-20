/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Resampling_types.h
 *
 * Code generation for function 'Resampling'
 *
 */

#ifndef RESAMPLING_TYPES_H
#define RESAMPLING_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_rtString
#define typedef_rtString

typedef struct {
  char_T Value[6];
} rtString;

#endif                                 /*typedef_rtString*/

#ifndef typedef_rtString_1
#define typedef_rtString_1

typedef struct {
  char_T Value[3];
} rtString_1;

#endif                                 /*typedef_rtString_1*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T animation[3];
  real_T K;
  real_T NP;
  real_T Vref;
  real_T SwitchingPoint;
  real_T sigma_0;
  real_T sigma_v0;
  real_T sigma[21000];
  real_T sigma_v[1000];
  real_T st;
  real_T DT[21];
  real_T R[2];
  real_T r_wheel;
  real_T r_obs;
  rtString Inputmode;
  rtString_1 Resamplingmode;
  real_T time_obsmove;
  real_T reset_flag;
  real_T goal[2];
  real_T ObsNum;
  real_T count;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_ResamplingStackData
#define typedef_ResamplingStackData

typedef struct {
  struct {
    struct0_T obj;
  } f0;
} ResamplingStackData;

#endif                                 /*typedef_ResamplingStackData*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/
#endif

/* End of code generation (Resampling_types.h) */
