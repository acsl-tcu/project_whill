/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Discretemodel_info.c
 *
 * Code generation for function '_coder_Discretemodel_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Discretemodel.h"
#include "_coder_Discretemodel_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("Discretemodel"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "E:\\users\\yamaguchi\\test\\test\\Discretemodel.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738064.8859722222));
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.6.0.1214997 (R2019a) Update 6"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[11] = {
    "789ced5a4d732245189eac6b3656f991835a7a3207cb2a6b9549e226e0565905330961221058d8906c6a35cdd0c040cf47cd07909c72f2ecc993674b6f1ef564"
    "bcf907d42a7f82277f82c30c4d8659ba2099c9b090ee1474ba5ea69fb71fde7ebafb6d982521b7c430cc9bf6eb9efd2a6418a7bce156cceaa0bec78c16bf7d69",
    "50bfee6be3f22a737fe4396cff7e508baa62c29ee93690a4c0bc2557a16e371420c3613735559614a098e5330d323a3454d48135c75297102c4b32ccaa9e4646"
    "b21b72da631a36faa6feff7c138aed9225337ad3b87217791b8c879f4bc2f8ef4fc9cf31819ffee73eb5ffb0fd44c81ef1cff9c76c41571b3a90d7fabe1a6c2e",
    "55cea638f6c9e6fac6e78035551555d51e6b34810e6baca8d6a03e787f38a8249b565d0188354c5d521a31d9379e5382bfcb538ec75fe3f21ab3e2697d92c478"
    "1784fea6e56f8d8087f9c37667f83159ea494a0c73102b69aa5a7f02355537278d7f5a7f1e10fd79e0f863296d45ed2a43beff08885723e2b9e3c7f6132194f0",
    "7108f4449187413794a28ba3cbf7d67ef82b156ddc463d4f6687d723f4376d5cbe4bc0c37189edba9ab73a957c3ec19db7d2fc717643e0734fd39ef56702ce24"
    "3f18423baafe4f09cf4fe2d15f483c4e8b176e9cfcf75b58fafd01010f8f0fdb5dfd1e2ab7609424d9b2f705ed92b38ecd8cef5f6e8887fb3f9a8087edd75aff",
    "a18c9cd70b8bbe9fb6981c5ddc5c2cfdfa0fd5eb79d7ebfd432ed5290be6feb9d04aa5b5c6975b45b398a17aed2f2fab5e078d93770878787cd8eed36bf7b4c1"
    "cc8ee7cb1be2dddd73dae5371785bfa95edf125e547a2da0bda36e66a3d3951219b0b997288bcfb6046e71f4fa5bc2f3d3f2c812fac73c62fbc9eef3ddc7ac65",
    "40dd60cf800c1a96d89458131aa6fbb62319a20e4d28dbd317d9b335dab85a4d06d555dcff2b04bc55dbd2e74354dd44585878cbbef615deb29bbf50ad2a8257"
    "783f06c4db23e2b9df37b6f7757cf73afb6d245559199808545988ea9662ebb9116d1cfcfef4a33fa95edf125e547aad957badf88159d88e1f8072a955d6f7ce",
    "446581f49acedfd1321a6f1f8696177f9f808779c276ff3e5d0408e831acf2b3dbaf07cdab9426e061fbb5e3646c5ee5a1cbdb2066bce33825f8195edc24b7bf"
    "fb89eafebceb7e42cf1aa028e68e2bd5e3a32ac76d3faa3720d5fd3ba7fb41cf331f13f0304fd8eed37da069e8ace48858da524453521541292020e2ab76ec9f",
    "16d0bfb726f887edf581175f378152b30f0061dd975627e0637b38eb0299569cd08930ce8a957f69fe7dded709abc0f3bd385fd1f2e52d18cf373fcb65e36d7e"
    "71d6093abfc78f6bba78bcfa5d0d096f5a1e577c6d66f8b9158747c93034a01b705679a09f03e2e589786e9c607b90fd449fa1fe8e0273d58f8908cf052b5f7c",
    "45f57edef5be5b118c346a1fa637eb7a09755a07fbca7991ea3dd57ba7c4162e5f74d3f580e68bc6d7b8d07c513478345f144eff41f3208b71affb7664f7ba86"
    "a4386d7aaf3b293f683315691c24e9bdee2de245a5d70064b867dd76463accf116e23865275ec8ef2c8e5ed3f93b5a5ece7b5dacf2f45ef77afb743766bce338",
    "25f819e2ef2f93749f3effbabfbe95d94ef0ddcae63ad7eda2750d3dda699c2fd03e9deafe68a1f7bae3fda3f7baa37ed37bddf9c0a3f7bae1f44fe7f7f871cd"
    "579e3fbcf3c3ddcaf3d3f3c3a2e1d1f343b0feff07b5613a3c", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 18536U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_Discretemodel_info.c) */
