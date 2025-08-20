/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calc_observation_info.c
 *
 * Code generation for function 'calc_observation'
 *
 */

/* Include files */
#include "_coder_calc_observation_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789ced55cd6ed340101ea31610e2275c38f004888393168ac20d296913aad01425120884"
      "5263afe325b67763afd3b4272e48e550e80121f1323c03078ebc0347"
      "ae8c1d3bfe11ab448a8888e84af6fc7cb3f34d26930c288f9f2800701d26a7192bd762bb"
      "14cb0b903f455c29c429f9705887b5dcbd04ff184b9db9828cc5c470",
      "35874c6f1acca1aee68aee1127e0119fd923624488496dd2a50ee9648dbdd0727632d0d4"
      "08a150af59441f7402073ccb4f2bb4b3c6b41f8f943f7fdeb539fbe1"
      "4afa7133963f62f912b6e11594c102060e10d47c10108081ba8b5a19ea88e8e871a69e26"
      "68700c1486d0459f1ff936a002bf3a77bedc870f9f6f9ffd3ce5a7ad",
      "931e6ca27713b6a087b21abfcb984d038ef702bc6de3d38311c6a8700fb54bef39a183d6"
      "c9fadbb0120f63cb5861c841b1020d2543ef24878def1edaaf11c7af"
      "08b368511cc33a558ccef6934bfa356f3faf4afa592ae05c37a920b64db94fb2fc070bf2"
      "5f94f24f105f78812e52beea82f3f346c297cccff758aeeafc70444c",
      "f48928878d1a8fa6a8383707923edd98b38f4599c65f8ea4f949ef2f932f39ff0bdf5892"
      "6fdedfc12d095fa980efef9151a56a8e9f6b0f589feeecb69f56addd"
      "edb48efd193cb3ea0089bdacfce7fbe8dfda475724fd2c15f0681f71516b3720c77fb620"
      "ffdd19fc09ce1975856eb3c0f055d488e76ab6aa3383f489ab725d8d",
      "f05a88e7ebab2c386f96a4be64debec57255e72ddd5f1c9f1ab4a111cdd8b2fe67bfbeab"
      "9fefadbfc8b7acbd650d5e1cb5b7b4a6517f7858d79f1db63686c7c3"
      "c6eaefaddf1e6d1c12",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3680U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 11);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("calc_observation"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(11.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
          "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
          "_08_08/"
          "capsuele_v5.3_"
          "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
          "Estimator/calc_observation.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739848.82876157411));
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
                emlrtMxCreateString("1kOPfYEAhJsL0oUdQuqZG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_calc_observation_info.c) */
