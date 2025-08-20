/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Discretemodel.c
 *
 * Code generation for function 'Discretemodel'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Discretemodel.h"
#include "Discretemodel_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 2,   /* lineNo */
  10,                                  /* colNo */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 3, /* lineNo */
  11,                                  /* colNo */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  21,                                  /* iLast */
  4,                                   /* lineNo */
  50,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  4,                                   /* lineNo */
  52,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  5,                                   /* lineNo */
  50,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  5,                                   /* lineNo */
  52,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  4,                                   /* lineNo */
  19,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  4,                                   /* lineNo */
  19,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  4,                                   /* lineNo */
  31,                                  /* colNo */
  "pu",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  4,                                   /* lineNo */
  31,                                  /* colNo */
  "pu",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  4,                                   /* lineNo */
  56,                                  /* colNo */
  "obj.DT",                            /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  4,                                   /* lineNo */
  4,                                   /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  4,                                   /* lineNo */
  4,                                   /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  5,                                   /* lineNo */
  19,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  5,                                   /* lineNo */
  19,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  5,                                   /* lineNo */
  31,                                  /* colNo */
  "pu",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  5,                                   /* lineNo */
  31,                                  /* colNo */
  "pu",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  5,                                   /* lineNo */
  56,                                  /* colNo */
  "obj.DT",                            /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  5,                                   /* lineNo */
  4,                                   /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  5,                                   /* lineNo */
  4,                                   /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  6,                                   /* lineNo */
  19,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  6,                                   /* lineNo */
  19,                                  /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  6,                                   /* lineNo */
  31,                                  /* colNo */
  "pu",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  6,                                   /* lineNo */
  31,                                  /* colNo */
  "pu",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  6,                                   /* lineNo */
  41,                                  /* colNo */
  "obj.DT",                            /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { 1,   /* iFirst */
  21,                                  /* iLast */
  6,                                   /* lineNo */
  4,                                   /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  6,                                   /* lineNo */
  4,                                   /* colNo */
  "px",                                /* aName */
  "Discretemodel",                     /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void Discretemodel(const emlrtStack *sp, const struct0_T *obj, real_T px[63000],
                   const real_T pu[42000])
{
  int32_T i1;
  int32_T j;
  int32_T i2;
  int32_T i;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  emlrtMEXProfilingFunctionEntry(Discretemodel_complete_name, isMexOutdated);
  emlrtMEXProfilingStatement(1, isMexOutdated);
  i1 = (int32_T)obj->NP;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj->NP, mxDOUBLE_CLASS, (int32_T)
    obj->NP, &emlrtRTEI, sp);
  for (j = 0; j < i1; j++) {
    emlrtMEXProfilingStatement(2, isMexOutdated);
    i2 = (int32_T)(obj->K - 1.0);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj->K - 1.0, mxDOUBLE_CLASS,
      (int32_T)(obj->K - 1.0), &b_emlrtRTEI, sp);
    for (i = 0; i < i2; i++) {
      emlrtMEXProfilingStatement(3, isMexOutdated);
      i3 = 1 + i;
      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &emlrtBCI, sp);
      }

      i3 = 1 + j;
      if ((i3 < 1) || (i3 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 1000, &b_emlrtBCI, sp);
      }

      i3 = (int32_T)(1U + i);
      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &e_emlrtBCI, sp);
      }

      i4 = (int32_T)(1U + j);
      if ((i4 < 1) || (i4 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &f_emlrtBCI, sp);
      }

      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &g_emlrtBCI, sp);
      }

      if ((i4 < 1) || (i4 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &h_emlrtBCI, sp);
      }

      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &i_emlrtBCI, sp);
      }

      i5 = (int32_T)(i + 2U);
      if ((i5 < 1) || (i5 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, 21, &j_emlrtBCI, sp);
      }

      if ((i4 < 1) || (i4 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &k_emlrtBCI, sp);
      }

      i6 = 2 + (3 * i + 63 * j);
      px[3 * (i5 - 1) + 63 * (i4 - 1)] = px[3 * (i3 - 1) + 63 * (i4 - 1)] + pu
        [((i3 - 1) << 1) + 42 * (i4 - 1)] * muDoubleScalarCos(px[i6]) * obj->
        DT[i3 - 1];
      emlrtMEXProfilingStatement(4, isMexOutdated);
      i7 = 1 + i;
      if ((i7 < 1) || (i7 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, 21, &c_emlrtBCI, sp);
      }

      i7 = 1 + j;
      if ((i7 < 1) || (i7 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, 1000, &d_emlrtBCI, sp);
      }

      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &l_emlrtBCI, sp);
      }

      if ((i4 < 1) || (i4 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &m_emlrtBCI, sp);
      }

      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &n_emlrtBCI, sp);
      }

      if ((i4 < 1) || (i4 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &o_emlrtBCI, sp);
      }

      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &p_emlrtBCI, sp);
      }

      if ((i5 < 1) || (i5 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, 21, &q_emlrtBCI, sp);
      }

      if ((i4 < 1) || (i4 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &r_emlrtBCI, sp);
      }

      px[1 + (3 * (i5 - 1) + 63 * (i4 - 1))] = px[1 + (3 * (i3 - 1) + 63 * (i4 -
        1))] + pu[((i3 - 1) << 1) + 42 * (i4 - 1)] * muDoubleScalarSin(px[i6]) *
        obj->DT[i3 - 1];
      emlrtMEXProfilingStatement(5, isMexOutdated);
      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &s_emlrtBCI, sp);
      }

      if ((i4 < 1) || (i4 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &t_emlrtBCI, sp);
      }

      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &u_emlrtBCI, sp);
      }

      if ((i4 < 1) || (i4 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &v_emlrtBCI, sp);
      }

      if ((i3 < 1) || (i3 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 21, &w_emlrtBCI, sp);
      }

      if ((i5 < 1) || (i5 > 21)) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, 21, &x_emlrtBCI, sp);
      }

      if ((i4 < 1) || (i4 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &y_emlrtBCI, sp);
      }

      px[2 + (3 * (i5 - 1) + 63 * (i4 - 1))] = px[2 + (3 * (i3 - 1) + 63 * (i4 -
        1))] + pu[1 + (((i3 - 1) << 1) + 42 * (i4 - 1))] * obj->DT[i3 - 1];
      emlrtMEXProfilingStatement(6, isMexOutdated);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emlrtMEXProfilingStatement(7, isMexOutdated);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtMEXProfilingStatement(8, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
}

/* End of code generation (Discretemodel.c) */
