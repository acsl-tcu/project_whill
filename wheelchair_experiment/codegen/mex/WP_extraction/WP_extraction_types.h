//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// WP_extraction_types.h
//
// Code generation for function 'WP_extraction'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"

// Type Definitions
struct struct0_T {
  real_T NP;
  real_T K;
  real_T waypoint[30];
  real_T target_n[21000];
  real_T target[42000];
  real_T limit[84000];
  real_T wall[60];
};

struct WP_extraction_api {
  struct0_T obj;
};

struct WP_extractionStackData {
  WP_extraction_api f0;
};

// End of code generation (WP_extraction_types.h)
