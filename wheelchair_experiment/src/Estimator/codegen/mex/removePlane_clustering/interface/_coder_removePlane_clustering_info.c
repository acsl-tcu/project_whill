/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_removePlane_clustering_info.c
 *
 * Code generation for function 'removePlane_clustering'
 *
 */

/* Include files */
#include "_coder_removePlane_clustering_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[4] = {
      "789c6360f4f465646060e0638000013608cd0be34369260654802ecf8883860156061614"
      "7d30f97e289d9c9f57925a5102e1e425e6a6c275a6e4e766e625e695"
      "845416a43214a516e7e794a5a68065d2327352433273538391397e205eae1b92149c0392"
      "02b19d335293b3834b73198a328a112ecc41e6c0c32301877f590884",
      "073a400f0f747523c5be1564da0733df85807d30f9e8d05895dcc4929cc4a4a2fcfc1295"
      "9892fcfc9ca4fc8a989ccc94c42208999258921853969a939f529997"
      "1a9c9a579c5fe4949a98eb98979e935aac07d48cecee041ceee227d2ddb8f2052f030798"
      "feb8f23a233ded6310d252a7ab7d503050f655e0308fd8742786c33e",
      "0134f95cf72c3753c7a814e34c8ff09c42d7b0907c67035337843b0208d843c81d0c38f8"
      "b4361f00c27a52e9",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1576U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum",    "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "PropertyList"};
  const char_T *epFieldName[6] = {
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("removePlane_clustering"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString("C:\\Users\\masan\\OneDrive - "
                          "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5"
                          "\xa4\xa7\xe5\xad\xa6 Tokyo City University\\gra"
                          "duation\\noPrimeEst_"
                          "ubuntu\\src\\Estimator\\removePlane_clustering.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739162.896574074));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("9.14.0.2254940 (R2023a) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("mGjF5AZd3iHWlqEVToC05F"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_removePlane_clustering_info.c) */
