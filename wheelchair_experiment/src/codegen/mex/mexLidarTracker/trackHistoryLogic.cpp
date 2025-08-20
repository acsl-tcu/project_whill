//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  trackHistoryLogic.cpp
//
//  Code generation for function 'trackHistoryLogic'
//


// Include files
#include "trackHistoryLogic.h"
#include "combineVectorElements.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo gkb_emlrtRSI = { 274,// lineNo
  "trackHistoryLogic/checkDeletion",   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackHistoryLogic.m"// pathName 
};

static emlrtRTEInfo yc_emlrtRTEI = { 208,// lineNo
  56,                                  // colNo
  "trackHistoryLogic/hit",             // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackHistoryLogic.m"// pName 
};

static emlrtRTEInfo ad_emlrtRTEI = { 215,// lineNo
  56,                                  // colNo
  "trackHistoryLogic/miss",            // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackHistoryLogic.m"// pName 
};

static emlrtRTEInfo bd_emlrtRTEI = { 200,// lineNo
  35,                                  // colNo
  "trackHistoryLogic/init",            // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackHistoryLogic.m"// pName 
};

static emlrtRTEInfo pn_emlrtRTEI = { 274,// lineNo
  40,                                  // colNo
  "trackHistoryLogic",                 // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/trackHistoryLogic.m"// pName 
};

// Function Definitions
namespace coder
{
  void trackHistoryLogic::get_History(boolean_T value[10]) const
  {
    for (int32_T i = 0; i < 10; i++) {
      value[i] = this->pRecentHistory[i];
    }
  }

  boolean_T trackHistoryLogic::checkConfirmation() const
  {
    int32_T nz;
    boolean_T x[10];
    boolean_T tf;
    if (this->pIsFirstUpdate) {
      tf = false;
    } else {
      for (nz = 0; nz < 10; nz++) {
        x[nz] = this->pRecentHistory[nz];
      }

      nz = x[0];
      for (int32_T k = 0; k < 9; k++) {
        nz += x[k + 1];
      }

      tf = (nz >= 7);
    }

    return tf;
  }

  boolean_T trackHistoryLogic::checkDeletion(const emlrtStack *sp, boolean_T
    tentativeTrack, uint32_T age) const
  {
    array<boolean_T, 2U> c_x;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T nz;
    boolean_T x[10];
    boolean_T b_x[5];
    boolean_T tf;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    if (this->pIsFirstUpdate) {
      tf = false;
    } else if (!tentativeTrack) {
      if (age > 5U) {
        for (int32_T k = 0; k < 5; k++) {
          b_x[k] = !this->pRecentHistory[k];
        }

        tf = ((((b_x[0] + b_x[1]) + b_x[2]) + b_x[3]) + b_x[4] >= 5);
      } else {
        if (1U > age) {
          nz = 0;
        } else {
          nz = static_cast<int32_T>(age);
        }

        st.site = &gkb_emlrtRSI;
        c_x.set_size(&pn_emlrtRTEI, &st, 1, nz);
        for (int32_T k = 0; k < nz; k++) {
          c_x[k] = !this->pRecentHistory[k];
        }

        b_st.site = &wi_emlrtRSI;
        c_st.site = &xi_emlrtRSI;
        nz = c_combineVectorElements(&c_st, c_x);
        tf = (nz >= 5);
      }
    } else {
      int32_T k;
      uint32_T qY;
      for (k = 0; k < 10; k++) {
        x[k] = this->pRecentHistory[k];
      }

      nz = x[0];
      for (k = 0; k < 9; k++) {
        nz += x[k + 1];
      }

      qY = 10U - age;
      if (10U - age > 10U) {
        qY = 0U;
      }

      tf = (7.0 - static_cast<real_T>(nz) > qY);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    return tf;
  }

  trackHistoryLogic *trackHistoryLogic::clone(trackHistoryLogic *iobj_0) const
  {
    trackHistoryLogic *cloned;
    int32_T i;
    boolean_T obj[50];
    cloned = iobj_0->init();
    for (i = 0; i < 50; i++) {
      obj[i] = this->pRecentHistory[i];
    }

    for (i = 0; i < 50; i++) {
      cloned->pRecentHistory[i] = obj[i];
    }

    cloned->pIsFirstUpdate = this->pIsFirstUpdate;
    return cloned;
  }

  void trackHistoryLogic::hit(const emlrtStack *sp)
  {
    int32_T i;
    boolean_T bv[50];
    if (this->pIsFirstUpdate) {
      emlrtErrorWithMessageIdR2018a(sp, &yc_emlrtRTEI,
        "shared_tracking:trackHistoryLogic:notInitialized",
        "shared_tracking:trackHistoryLogic:notInitialized", 3, 4, 3, "hit");
    }

    bv[0] = true;
    for (i = 0; i < 49; i++) {
      bv[i + 1] = this->pRecentHistory[i];
    }

    for (i = 0; i < 50; i++) {
      this->pRecentHistory[i] = bv[i];
    }

    this->pIsFirstUpdate = false;
  }

  trackHistoryLogic *trackHistoryLogic::init()
  {
    trackHistoryLogic *obj;
    obj = this;
    for (int32_T i = 0; i < 50; i++) {
      obj->pRecentHistory[i] = false;
    }

    return obj;
  }

  b_trackHistoryLogic *b_trackHistoryLogic::init()
  {
    return this;
  }

  void trackHistoryLogic::init(const emlrtStack *sp)
  {
    int32_T i;
    boolean_T bv[50];
    if (!this->pIsFirstUpdate) {
      emlrtErrorWithMessageIdR2018a(sp, &bd_emlrtRTEI,
        "shared_tracking:trackHistoryLogic:alreadyInitialized",
        "shared_tracking:trackHistoryLogic:alreadyInitialized", 0);
    }

    bv[0] = true;
    for (i = 0; i < 49; i++) {
      bv[i + 1] = this->pRecentHistory[i];
    }

    for (i = 0; i < 50; i++) {
      this->pRecentHistory[i] = bv[i];
    }

    this->pIsFirstUpdate = false;
  }

  void trackHistoryLogic::miss(const emlrtStack *sp)
  {
    int32_T i;
    boolean_T bv[50];
    if (this->pIsFirstUpdate) {
      emlrtErrorWithMessageIdR2018a(sp, &ad_emlrtRTEI,
        "shared_tracking:trackHistoryLogic:notInitialized",
        "shared_tracking:trackHistoryLogic:notInitialized", 3, 4, 4, "miss");
    }

    bv[0] = false;
    for (i = 0; i < 49; i++) {
      bv[i + 1] = this->pRecentHistory[i];
    }

    for (i = 0; i < 50; i++) {
      this->pRecentHistory[i] = bv[i];
    }

    this->pIsFirstUpdate = false;
  }

  void trackHistoryLogic::output(boolean_T value[10]) const
  {
    this->get_History(value);
  }

  void trackHistoryLogic::reset()
  {
    for (int32_T i = 0; i < 50; i++) {
      this->pRecentHistory[i] = false;
    }

    this->pIsFirstUpdate = true;
  }
}

// End of code generation (trackHistoryLogic.cpp)
