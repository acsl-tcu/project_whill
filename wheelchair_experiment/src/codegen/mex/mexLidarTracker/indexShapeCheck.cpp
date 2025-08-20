//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  indexShapeCheck.cpp
//
//  Code generation for function 'indexShapeCheck'
//


// Include files
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo nf_emlrtRSI = { 43, // lineNo
  "indexShapeCheck",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"// pathName 
};

static emlrtRSInfo cj_emlrtRSI = { 33, // lineNo
  "indexShapeCheck",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"// pathName 
};

static emlrtRSInfo mhb_emlrtRSI = { 51,// lineNo
  "indexShapeCheck",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"// pathName 
};

static emlrtRSInfo nhb_emlrtRSI = { 56,// lineNo
  "indexShapeCheck",                   // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"// pathName 
};

static emlrtRTEInfo r_emlrtRTEI = { 121,// lineNo
  5,                                   // colNo
  "errOrWarnIf",                       // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"// pName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    void b_indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[2],
      int32_T indexSize)
    {
      emlrtStack st;
      boolean_T c;
      st.prev = sp;
      st.tls = sp->tls;
      if ((matrixSize[1] == 1) && (indexSize != 1)) {
        c = true;
      } else {
        c = false;
      }

      st.site = &nf_emlrtRSI;
      if (c) {
        emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
          "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
      }
    }

    void indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[2],
                         int32_T indexSize)
    {
      emlrtStack st;
      boolean_T nonSingletonDimFound;
      st.prev = sp;
      st.tls = sp->tls;
      nonSingletonDimFound = (matrixSize[0] != 1);
      if (matrixSize[1] != 1) {
        if (nonSingletonDimFound) {
          nonSingletonDimFound = false;
        } else {
          nonSingletonDimFound = true;
        }
      }

      if (nonSingletonDimFound && (indexSize != 1)) {
        st.site = &cj_emlrtRSI;
        if ((matrixSize[0] == 1) != (indexSize == 1)) {
          emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
            "Coder:FE:PotentialMatrixMatrix_MV",
            "Coder:FE:PotentialMatrixMatrix_MV", 0);
        }
      }
    }

    void indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[2])
    {
      emlrtStack st;
      boolean_T nonSingletonDimFound;
      st.prev = sp;
      st.tls = sp->tls;
      nonSingletonDimFound = (matrixSize[0] != 1);
      if (matrixSize[1] != 1) {
        if (nonSingletonDimFound) {
          nonSingletonDimFound = false;
        } else {
          nonSingletonDimFound = true;
        }
      }

      if (nonSingletonDimFound) {
        if ((matrixSize[0] != 1) || (matrixSize[1] == 1)) {
          nonSingletonDimFound = true;
        } else {
          nonSingletonDimFound = false;
        }

        st.site = &cj_emlrtRSI;
        if (nonSingletonDimFound) {
          emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
            "Coder:FE:PotentialMatrixMatrix_MV",
            "Coder:FE:PotentialMatrixMatrix_MV", 0);
        }
      }
    }

    void indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[2],
                         const int32_T indexSize[2])
    {
      emlrtStack st;
      boolean_T nonSingletonDimFound;
      st.prev = sp;
      st.tls = sp->tls;
      nonSingletonDimFound = (matrixSize[0] != 1);
      if (matrixSize[1] != 1) {
        if (nonSingletonDimFound) {
          nonSingletonDimFound = false;
        } else {
          nonSingletonDimFound = true;
        }
      }

      if (nonSingletonDimFound) {
        if ((matrixSize[0] == 1) || (matrixSize[1] != 1)) {
          nonSingletonDimFound = true;
        } else {
          nonSingletonDimFound = false;
        }

        st.site = &mhb_emlrtRSI;
        if (nonSingletonDimFound) {
          emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
            "Coder:FE:PotentialMatrixMatrix_MM_Logical1",
            "Coder:FE:PotentialMatrixMatrix_MM_Logical1", 0);
        }
      } else {
        nonSingletonDimFound = (indexSize[0] != 1);
        if (indexSize[1] != 1) {
          if (nonSingletonDimFound) {
            nonSingletonDimFound = false;
          } else {
            nonSingletonDimFound = true;
          }
        }

        if (nonSingletonDimFound) {
          if ((indexSize[0] == 1) || (indexSize[1] != 1)) {
            nonSingletonDimFound = true;
          } else {
            nonSingletonDimFound = false;
          }

          st.site = &nhb_emlrtRSI;
          if (nonSingletonDimFound) {
            emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
              "Coder:FE:PotentialMatrixMatrix_MM_Logical2",
              "Coder:FE:PotentialMatrixMatrix_MM_Logical2", 0);
          }
        }
      }
    }

    void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const int32_T
                         indexSize[2])
    {
      emlrtStack st;
      boolean_T nonSingletonDimFound;
      st.prev = sp;
      st.tls = sp->tls;
      if (matrixSize == 1) {
        nonSingletonDimFound = (indexSize[0] != 1);
        if (indexSize[1] != 1) {
          if (nonSingletonDimFound) {
            nonSingletonDimFound = false;
          } else {
            nonSingletonDimFound = true;
          }
        }

        if (nonSingletonDimFound) {
          nonSingletonDimFound = true;
        } else {
          nonSingletonDimFound = false;
        }
      } else {
        nonSingletonDimFound = false;
      }

      st.site = &nf_emlrtRSI;
      if (nonSingletonDimFound) {
        emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
          "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
      }
    }
  }
}

// End of code generation (indexShapeCheck.cpp)
