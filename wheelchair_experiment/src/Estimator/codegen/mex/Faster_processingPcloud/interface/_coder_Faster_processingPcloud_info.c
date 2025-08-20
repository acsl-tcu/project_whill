/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Faster_processingPcloud_info.c
 *
 * Code generation for function 'Faster_processingPcloud'
 *
 */

/* Include files */
#include "_coder_Faster_processingPcloud_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[7] = {
      "789ce5574f6f1241147fab54498c8a319ae8c9c44b4fd0a668f42845fe242dd2404d2c31"
      "b22c036cbbbbb3ee1fa49c7ad27aa87a32fa0d3cf9193c18bf80173f"
      "81578f1ef5edee0c7f369d400a41a4932cbf79f3e6cdeff1e3e50d0b527e5302804b108c"
      "0f5703bcc8ec18c333303cc27e89e1d990cdc7124486e2b8ff2d4385",
      "1a0ee9388161c83ae945d6a9ae1ab2e194f74d0216b1a9d62675dfd35035525675521a34"
      "0a9ea567065c3dc37379f3f51651f64aae0e56cbee67a80d1a3d3d6e"
      "49c77fdfc8987a54057a5c61f88561051ec25348400b28e840706683032ed4716ee02c01"
      "69f428b8a2f7565661057e97963f26e1cdfb9bef7e1d99471b8709dc",
      "238389d12eeed3f079066db8037158c3d9f9d72651f7360e970ebcf32ddc9b405e8f49c5"
      "7365448aab09c8e0dc5b45c131cac44f8f9be09a8d3b0d6842116d0d"
      "57bd0ce318cbf53a10e831ae5e37047ac542fe1cd14c62a5a86bd455a399a29d347188e2"
      "508bf9793e5cff93e61309d9fd7c028fd292ad41bee509eba526e0e3",
      "f5f2956105d6e7a85e727eace9d74bcaaf0a0333092ac5b33b980df1eb4961315ecd0cea"
      "5615e872794cddc2d8df1ff5b12cdd6ecd92eff3ab6ff159f2f1f1af"
      "f83a82f3c6adfbeb02be58c8bffaa0abbcb0d3a49bdc2a9174b951cb34d4ad5c3f8fe208"
      "9e517980c09ed5f95541fc281dc343a4e3b4f8f8f9d190dde70b3cb6",
      "43ccbc6e6af37a3fdc9bb05f6b827c78bffec1b0028f16a0634bec5f810979b44c3ce1b4"
      "f4b745e79b55ffdede293cbe9b2da5770bb9e7dbbbcdfda2bc5654b2"
      "8bd3bf7313f6133b64f3c1fbc94f86f3f5be70d26ed2f4578f8f20be165c5753a0dbb8ba"
      "5e10e81a0bf95b54a74d6210ea06bfc4b4eec97342fec0633b96ab38",
      "7dbee884755416f0f13afac470beea28c882fa7561e0e3d5853df47e59157cef69f5c5ef"
      "2fff343d3c2d7d7fd67c93de33d7047cb190bfe3d076b26bac6453b5"
      "b49bd1b39b3b4fee53f8ffef99bfb5ec5924",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 5040U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("Faster_processingPcloud"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
                          "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0"
                          "\xe8\xa1\x8c/capsuele_v5.3_"
                          "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8"
                          "\x80\x85/src/Estimator/Faster_processingPcloud.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739606.61101851857));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2833386 (R2024b) Update 4"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("xVmbgShv08SY0PPNVSINlC"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_Faster_processingPcloud_info.c) */
