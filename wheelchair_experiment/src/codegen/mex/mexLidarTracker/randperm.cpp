//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  randperm.cpp
//
//  Code generation for function 'randperm'
//


// Include files
#include "randperm.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRTEInfo ab_emlrtRTEI = { 12,// lineNo
  15,                                  // colNo
  "randperm",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/randfun/randperm.m"// pName
};

static emlrtRTEInfo bb_emlrtRTEI = { 23,// lineNo
  19,                                  // colNo
  "randperm",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/randfun/randperm.m"// pName
};

// Function Definitions
namespace coder
{
  void randperm(const emlrtStack *sp, real_T n, real_T p_data[], int32_T p_size
                [2])
  {
    real_T loc_data[3];
    real_T val_data[3];
    real_T pt;
    int8_T hashTbl_data[3];
    int8_T link_data[3];
    if (!(n == muDoubleScalarFloor(n))) {
      emlrtErrorWithMessageIdR2018a(sp, &ab_emlrtRTEI,
        "MATLAB:randperm:inputType", "MATLAB:randperm:inputType", 0);
    }

    if (!(3.0 <= n)) {
      emlrtErrorWithMessageIdR2018a(sp, &bb_emlrtRTEI,
        "MATLAB:randperm:inputKTooLarge", "MATLAB:randperm:inputKTooLarge", 0);
    }

    p_size[0] = 1;
    p_size[1] = 3;
    p_data[1] = 0.0;
    p_data[2] = 0.0;
    if (3.0 >= n) {
      real_T j;
      p_data[0] = 1.0;
      j = b_rand() * 2.0;
      j = muDoubleScalarFloor(j);
      p_data[1] = p_data[static_cast<int32_T>(j + 1.0) - 1];
      p_data[static_cast<int32_T>(j + 1.0) - 1] = 2.0;
      j = b_rand() * 3.0;
      j = muDoubleScalarFloor(j);
      p_data[2] = p_data[static_cast<int32_T>(j + 1.0) - 1];
      p_data[static_cast<int32_T>(j + 1.0) - 1] = 3.0;
    } else if (3.0 >= n / 4.0) {
      real_T j;
      real_T selectedLoc;
      real_T t;
      t = 0.0;
      selectedLoc = n;
      pt = 3.0 / n;
      j = b_rand();
      while (j > pt) {
        t++;
        selectedLoc--;
        pt += (1.0 - pt) * (3.0 / selectedLoc);
      }

      t++;
      j = b_rand();
      j = muDoubleScalarFloor(j);
      p_data[0] = 0.0;
      p_data[static_cast<int32_T>(j + 1.0) - 1] = t;
      selectedLoc = n - t;
      pt = 2.0 / selectedLoc;
      j = b_rand();
      while (j > pt) {
        t++;
        selectedLoc--;
        pt += (1.0 - pt) * (2.0 / selectedLoc);
      }

      t++;
      j = b_rand() * 2.0;
      j = muDoubleScalarFloor(j);
      p_data[1] = p_data[static_cast<int32_T>(j + 1.0) - 1];
      p_data[static_cast<int32_T>(j + 1.0) - 1] = t;
      selectedLoc = n - t;
      pt = 1.0 / selectedLoc;
      j = b_rand();
      while (j > pt) {
        t++;
        selectedLoc--;
        pt += (1.0 - pt) * (1.0 / selectedLoc);
      }

      t++;
      j = b_rand() * 3.0;
      j = muDoubleScalarFloor(j);
      p_data[2] = p_data[static_cast<int32_T>(j + 1.0) - 1];
      p_data[static_cast<int32_T>(j + 1.0) - 1] = t;
    } else {
      real_T j;
      real_T selectedLoc;
      int32_T jlast;
      int8_T j_tmp;
      boolean_T exitg1;
      hashTbl_data[0] = 0;
      hashTbl_data[1] = 0;
      link_data[1] = 0;
      val_data[1] = 0.0;
      loc_data[1] = 0.0;
      hashTbl_data[2] = 0;
      link_data[2] = 0;
      val_data[2] = 0.0;
      loc_data[2] = 0.0;
      p_size[0] = 1;
      p_size[1] = 3;
      selectedLoc = b_rand() * ((n - 1.0) + 1.0);
      selectedLoc = muDoubleScalarFloor(selectedLoc);
      if (muDoubleScalarIsNaN(selectedLoc) || muDoubleScalarIsInf(selectedLoc))
      {
        pt = rtNaN;
      } else if (selectedLoc == 0.0) {
        pt = 0.0;
      } else {
        pt = muDoubleScalarRem(selectedLoc, 3.0);
        if (pt == 0.0) {
          pt = 0.0;
        } else {
          if (selectedLoc < 0.0) {
            pt += 3.0;
          }
        }
      }

      p_data[0] = selectedLoc + 1.0;
      loc_data[0] = selectedLoc;
      link_data[0] = 0;
      hashTbl_data[static_cast<int32_T>(pt + 1.0) - 1] = 1;
      if (muDoubleScalarIsInf(n - 1.0)) {
        pt = rtNaN;
      } else {
        pt = muDoubleScalarRem(n - 1.0, 3.0);
      }

      jlast = hashTbl_data[static_cast<int32_T>(pt + 1.0) - 1];
      while ((jlast > 0) && (selectedLoc != n - 1.0)) {
        jlast = 0;
      }

      if (jlast > 0) {
        val_data[0] = 0.0;
      } else {
        val_data[0] = n - 1.0;
      }

      selectedLoc = b_rand() * ((n - 2.0) + 1.0);
      selectedLoc = muDoubleScalarFloor(selectedLoc);
      if (muDoubleScalarIsNaN(selectedLoc) || muDoubleScalarIsInf(selectedLoc))
      {
        pt = rtNaN;
      } else if (selectedLoc == 0.0) {
        pt = 0.0;
      } else {
        pt = muDoubleScalarRem(selectedLoc, 3.0);
        if (pt == 0.0) {
          pt = 0.0;
        } else {
          if (selectedLoc < 0.0) {
            pt += 3.0;
          }
        }
      }

      j_tmp = hashTbl_data[static_cast<int32_T>(pt + 1.0) - 1];
      j = j_tmp;
      while ((j > 0.0) && (loc_data[0] != selectedLoc)) {
        j = 0.0;
      }

      if (j > 0.0) {
        p_data[1] = val_data[0] + 1.0;
      } else {
        p_data[1] = selectedLoc + 1.0;
        j = 2.0;
        loc_data[1] = selectedLoc;
        link_data[1] = j_tmp;
        hashTbl_data[static_cast<int32_T>(pt + 1.0) - 1] = 2;
      }

      if (muDoubleScalarIsInf(n - 2.0)) {
        pt = rtNaN;
      } else {
        pt = muDoubleScalarRem(n - 2.0, 3.0);
      }

      jlast = hashTbl_data[static_cast<int32_T>(pt + 1.0) - 1];
      while ((jlast > 0) && (loc_data[jlast - 1] != n - 2.0)) {
        jlast = link_data[jlast - 1];
      }

      if (jlast > 0) {
        val_data[static_cast<int32_T>(j) - 1] = val_data[jlast - 1];
      } else {
        val_data[static_cast<int32_T>(j) - 1] = n - 2.0;
      }

      selectedLoc = b_rand() * ((n - 3.0) + 1.0);
      selectedLoc = muDoubleScalarFloor(selectedLoc);
      if (muDoubleScalarIsNaN(selectedLoc) || muDoubleScalarIsInf(selectedLoc))
      {
        pt = rtNaN;
      } else if (selectedLoc == 0.0) {
        pt = 0.0;
      } else {
        pt = muDoubleScalarRem(selectedLoc, 3.0);
        if (pt == 0.0) {
          pt = 0.0;
        } else {
          if (selectedLoc < 0.0) {
            pt += 3.0;
          }
        }
      }

      j = hashTbl_data[static_cast<int32_T>(pt + 1.0) - 1];
      exitg1 = false;
      while ((!exitg1) && (j > 0.0)) {
        jlast = static_cast<int32_T>(j) - 1;
        if (loc_data[jlast] != selectedLoc) {
          j = link_data[jlast];
        } else {
          exitg1 = true;
        }
      }

      if (j > 0.0) {
        p_data[2] = val_data[static_cast<int32_T>(j) - 1] + 1.0;
      } else {
        p_data[2] = selectedLoc + 1.0;
      }
    }
  }
}

// End of code generation (randperm.cpp)
