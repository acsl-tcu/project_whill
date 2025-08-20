//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  trackHistoryLogic.h
//
//  Code generation for function 'trackHistoryLogic'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder
{
  class trackHistoryLogic
  {
   public:
    trackHistoryLogic *init();
    void reset();
    trackHistoryLogic *clone(trackHistoryLogic *iobj_0) const;
    boolean_T checkConfirmation() const;
    void output(boolean_T value[10]) const;
    void get_History(boolean_T value[10]) const;
    void hit(const emlrtStack *sp);
    void miss(const emlrtStack *sp);
    void init(const emlrtStack *sp);
    boolean_T checkDeletion(const emlrtStack *sp, boolean_T tentativeTrack,
      uint32_T age) const;
    boolean_T pRecentHistory[50];
   private:
    boolean_T pIsFirstUpdate;
  };

  class b_trackHistoryLogic
  {
   public:
    b_trackHistoryLogic *init();
  };
}

// End of code generation (trackHistoryLogic.h)
