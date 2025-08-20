/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EvaluationPath_vec_info.c
 *
 * Code generation for function 'EvaluationPath_vec'
 *
 */

/* Include files */
#include "_coder_EvaluationPath_vec_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789ced55bb6fd360103fa39687042508d4818991a92e4d9b742d6953256d42a454488090"
      "e37ebec456fc925f6d37c632149890f86f5891107f000b8c6c1d5939"
      "3b76fc1056221919057152fcfbeebbc7ef72bee4806b753800588189fcb835c110a012e2"
      "15484bd6ce65fcb8b43b2cc3522a2eb2bf0d9119ba83a7ce44d1450d",
      "a79192a129baa83b4767268285b6a17a280596a1a2e291a2613fa9747d4d6b264c53c537"
      "f9e7868c6cdc7735b0643bae504d2ad37eac73bfffbe4b73f66398d3"
      "8f3b217e0ef105ecc14be041060334403a3920c2185cd214d276e99e051a824e361e1ec1"
      "3afcec3ffcb0096fdedf7f7779615e1c9e0bb041b71bb00502612d78",
      "d6c997512e136c8a4750e92380473e6b50a5d3b5d7262ae3c3f3e5573c7958e4cb4383d8"
      "7c168b500d222cbadda3289134979e0e55e5fbf482b31c64448a5da3"
      "0a93fd3bcde9cfbcfdbb9bd3bf4ac6deec7504269ab6aba2e05585aa872c55c7a0601d57"
      "73eb98586cc77299f3e7e66694c317cdcd971017616e9a34251d8a88",
      "b345b9fc3cd5d4e4cc7a5fb7e7ec5f1663ffeb017ebdd790a144be4bfefb4a997c91fc2d"
      "bea2bffbd51cbe4ac6be39b415b3b6551bb19deed31d6cb777597dd4"
      "88ebe8cde0995507e4e865e5ffbf7f8aed1f33a73ff3f6ef664eff2a19fb081d41526c47"
      "d41926f90705f967ed1dc9708f558cf91e149c9741468f249a978f21",
      "2ec2bc8c081d8a90a8223ba84f276f0c66a4acff45ef53b97be69bd9ba51265f24fffa9e"
      "e93e6f3ddb77cd13efecf840694907db4fea27edc78bbf677e018a4b"
      "08c8",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3584U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("EvaluationPath_vec"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
                          "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0"
                          "\xe8\xa1\x8c_2025_06_07/caps"
                          "uele_v5.3_"
                          "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8"
                          "\x80\x85/src/Controller/EvaluationPath_vec.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739775.703275463));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2863752 (R2024b) Update 5"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("wHBBeotpCnFZI6V13Aulp"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_EvaluationPath_vec_info.c) */
