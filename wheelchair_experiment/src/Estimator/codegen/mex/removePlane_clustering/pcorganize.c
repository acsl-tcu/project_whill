/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcorganize.c
 *
 * Code generation for function 'pcorganize'
 *
 */

/* Include files */
#include "pcorganize.h"
#include "atan2d.h"
#include "combineVectorElements.h"
#include "handle.h"
#include "histcounts.h"
#include "ixfun.h"
#include "pointCloud.h"
#include "pointCloudBase.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo
    uc_emlrtRSI =
        {
            60,               /* lineNo */
            "pcorganizeImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    vc_emlrtRSI =
        {
            159,              /* lineNo */
            "pcorganizeImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    wc_emlrtRSI =
        {
            157,              /* lineNo */
            "pcorganizeImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    xc_emlrtRSI =
        {
            110,              /* lineNo */
            "pcorganizeImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    yc_emlrtRSI =
        {
            104,              /* lineNo */
            "pcorganizeImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ad_emlrtRSI =
        {
            97,               /* lineNo */
            "pcorganizeImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    bd_emlrtRSI =
        {
            96,               /* lineNo */
            "pcorganizeImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    cd_emlrtRSI =
        {
            92,               /* lineNo */
            "pcorganizeImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pathName
                                                                          */
};

static emlrtRSInfo jd_emlrtRSI = {
    430,                                     /* lineNo */
    "pointCloudBase/extractValidPointsImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\pointclouds\\+pointclouds\\+"
    "internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    102,                          /* lineNo */
    "binaryImplicitExpansionFun", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" /* pathName
                                                                            */
};

static emlrtRSInfo be_emlrtRSI = {
    37,     /* lineNo */
    "flip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" /* pathName
                                                                       */
};

static emlrtRSInfo ce_emlrtRSI = {
    29,     /* lineNo */
    "flip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" /* pathName
                                                                       */
};

static emlrtRSInfo de_emlrtRSI = {
    55,         /* lineNo */
    "prodsize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\prodsize.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    41,    /* lineNo */
    "cat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pathName
                                                                          */
};

static emlrtRSInfo fe_emlrtRSI = {
    113,        /* lineNo */
    "cat_impl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pathName
                                                                          */
};

static emlrtECInfo
    e_emlrtECI =
        {
            -1,               /* nDims */
            92,               /* lineNo */
            14,               /* colNo */
            "pcorganizeImpl", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtBCInfo nb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        122,              /* lineNo */
        26,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        122,              /* lineNo */
        49,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI =
    {
        123,              /* lineNo */
        34,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        123,              /* lineNo */
        34,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo d_emlrtDCI =
    {
        123,              /* lineNo */
        46,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        123,              /* lineNo */
        46,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        124,              /* lineNo */
        70,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo e_emlrtDCI =
    {
        124,              /* lineNo */
        29,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        124,              /* lineNo */
        29,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo f_emlrtDCI =
    {
        124,              /* lineNo */
        41,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        124,              /* lineNo */
        41,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        125,              /* lineNo */
        74,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        126,              /* lineNo */
        62,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        127,              /* lineNo */
        64,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        128,              /* lineNo */
        70,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        132,              /* lineNo */
        50,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        134,              /* lineNo */
        74,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo g_emlrtDCI =
    {
        134,              /* lineNo */
        33,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        134,              /* lineNo */
        33,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo h_emlrtDCI =
    {
        134,              /* lineNo */
        45,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        134,              /* lineNo */
        45,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        135,              /* lineNo */
        78,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        136,              /* lineNo */
        66,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        137,              /* lineNo */
        68,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo i_emlrtDCI =
    {
        126,              /* lineNo */
        29,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        126,              /* lineNo */
        29,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo j_emlrtDCI =
    {
        126,              /* lineNo */
        41,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        126,              /* lineNo */
        41,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo k_emlrtDCI =
    {
        136,              /* lineNo */
        33,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        136,              /* lineNo */
        33,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo l_emlrtDCI =
    {
        136,              /* lineNo */
        45,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        136,              /* lineNo */
        45,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo m_emlrtDCI =
    {
        127,              /* lineNo */
        30,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        127,              /* lineNo */
        30,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo n_emlrtDCI =
    {
        127,              /* lineNo */
        42,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        127,              /* lineNo */
        42,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo o_emlrtDCI =
    {
        137,              /* lineNo */
        34,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        137,              /* lineNo */
        34,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo p_emlrtDCI =
    {
        137,              /* lineNo */
        46,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        137,              /* lineNo */
        46,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        93,               /* lineNo */
        7,                /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        105,              /* lineNo */
        12,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        111,              /* lineNo */
        12,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        123,              /* lineNo */
        41,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        123,              /* lineNo */
        53,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        124,              /* lineNo */
        36,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        124,              /* lineNo */
        48,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        125,              /* lineNo */
        72,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        125,              /* lineNo */
        33,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo q_emlrtDCI =
    {
        125,              /* lineNo */
        33,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        125,              /* lineNo */
        40,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        125,              /* lineNo */
        45,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo r_emlrtDCI =
    {
        125,              /* lineNo */
        45,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        125,              /* lineNo */
        52,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        133,              /* lineNo */
        49,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo s_emlrtDCI =
    {
        133,              /* lineNo */
        49,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        133,              /* lineNo */
        56,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        133,              /* lineNo */
        61,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo t_emlrtDCI =
    {
        133,              /* lineNo */
        61,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        133,              /* lineNo */
        68,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        134,              /* lineNo */
        40,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        126,              /* lineNo */
        36,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        134,              /* lineNo */
        52,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo id_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        126,              /* lineNo */
        48,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        135,              /* lineNo */
        76,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        135,              /* lineNo */
        37,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo u_emlrtDCI =
    {
        135,              /* lineNo */
        37,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        135,              /* lineNo */
        44,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo md_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        135,              /* lineNo */
        49,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo v_emlrtDCI =
    {
        135,              /* lineNo */
        49,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        135,              /* lineNo */
        56,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo od_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        127,              /* lineNo */
        37,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        127,              /* lineNo */
        49,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        136,              /* lineNo */
        40,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        136,              /* lineNo */
        52,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        137,              /* lineNo */
        41,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo td_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        137,              /* lineNo */
        53,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        128,              /* lineNo */
        28,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo w_emlrtDCI =
    {
        128,              /* lineNo */
        28,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        128,              /* lineNo */
        35,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        128,              /* lineNo */
        40,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo x_emlrtDCI =
    {
        128,              /* lineNo */
        40,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        128,              /* lineNo */
        47,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        138,              /* lineNo */
        32,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo y_emlrtDCI =
    {
        138,              /* lineNo */
        32,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        138,              /* lineNo */
        39,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo be_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        138,              /* lineNo */
        44,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI =
    {
        138,              /* lineNo */
        44,               /* colNo */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        1 /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        138,              /* lineNo */
        51,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo de_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        127,              /* lineNo */
        66,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        126,              /* lineNo */
        64,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        137,              /* lineNo */
        70,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI =
    {
        -1,               /* iFirst */
        -1,               /* iLast */
        136,              /* lineNo */
        68,               /* colNo */
        "",               /* aName */
        "pcorganizeImpl", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtRTEInfo pe_emlrtRTEI = {
    14,         /* lineNo */
    5,          /* colNo */
    "isfinite", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\isfinite.m" /* pName
                                                                           */
};

static emlrtRTEInfo
    qe_emlrtRTEI =
        {
            58,           /* lineNo */
            23,           /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    re_emlrtRTEI =
        {
            61,           /* lineNo */
            5,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    se_emlrtRTEI =
        {
            74,           /* lineNo */
            21,           /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    te_emlrtRTEI =
        {
            72,           /* lineNo */
            9,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    ue_emlrtRTEI =
        {
            74,           /* lineNo */
            9,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    ve_emlrtRTEI =
        {
            81,           /* lineNo */
            9,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    we_emlrtRTEI =
        {
            79,           /* lineNo */
            9,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    xe_emlrtRTEI =
        {
            88,           /* lineNo */
            9,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    ye_emlrtRTEI =
        {
            86,           /* lineNo */
            9,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    af_emlrtRTEI =
        {
            92,           /* lineNo */
            14,           /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    bf_emlrtRTEI =
        {
            92,           /* lineNo */
            34,           /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    cf_emlrtRTEI =
        {
            96,           /* lineNo */
            20,           /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    df_emlrtRTEI =
        {
            96,           /* lineNo */
            5,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    ef_emlrtRTEI =
        {
            97,           /* lineNo */
            18,           /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    ff_emlrtRTEI =
        {
            97,           /* lineNo */
            33,           /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    gf_emlrtRTEI =
        {
            115,          /* lineNo */
            5,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    hf_emlrtRTEI =
        {
            116,          /* lineNo */
            5,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    if_emlrtRTEI =
        {
            118,          /* lineNo */
            5,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    jf_emlrtRTEI =
        {
            119,          /* lineNo */
            5,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    kf_emlrtRTEI =
        {
            58,           /* lineNo */
            38,           /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    lf_emlrtRTEI =
        {
            92,           /* lineNo */
            5,            /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    mf_emlrtRTEI =
        {
            104,          /* lineNo */
            10,           /* colNo */
            "pcorganize", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\pcorganize.m" /* pName
                                                                          */
};

/* Function Definitions */
pointCloud *pcorganizeImpl(const emlrtStack *sp, const pointCloud *ptCloud,
                           const real_T vbeamAngles_data[],
                           const real_T hbeamAngles[1024], pointCloud *iobj_0)
{
  __m128d r8;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_boolean_T *r5;
  emxArray_int32_T *b_r;
  emxArray_int32_T *nz;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T tmp_data;
  emxArray_real_T *b_intensity;
  emxArray_real_T *b_locations;
  emxArray_real_T *intensity;
  emxArray_real_T *loc;
  emxArray_real_T *locations;
  emxArray_real_T *normal;
  emxArray_real_T *nv;
  emxArray_real_T *pitch;
  emxArray_real_T *pseudoImage;
  emxArray_real_T *pseudoIntensity;
  emxArray_real_T *pseudoNormal;
  emxArray_real_T *ptDistance;
  emxArray_real_T *r;
  emxArray_real_T *rangeData;
  emxArray_real_T *rowIdx;
  emxArray_uint8_T b_pseudoColor_data;
  emxArray_uint8_T *c;
  emxArray_uint8_T *color;
  pointCloud b_ptCloud;
  pointCloud *ptCloudOrg;
  pointCloud *ptCloudOut;
  real_T a__4[1025];
  real_T a__3[1024];
  real_T a__2_data[17];
  real_T varargin_1_data[16];
  real_T tmp;
  real_T varargin_2;
  real_T *intensity_data;
  real_T *locations_data;
  real_T *nv_data;
  real_T *pitch_data;
  real_T *pseudoIntensity_data;
  real_T *pseudoNormal_data;
  real_T *ptDistance_data;
  real_T *r_data;
  real_T *rowIdx_data;
  int32_T pseudoColor_size[3];
  int32_T tmp_size[3];
  int32_T varargin_1_size[2];
  int32_T b_i;
  int32_T end;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T trueCount;
  int32_T *nz_data;
  int32_T *r7;
  uint8_T pseudoColor_data[49152];
  uint8_T *c_data;
  uint8_T *color_data;
  boolean_T b;
  boolean_T n;
  boolean_T *r6;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_pointCloud1(sp, &b_ptCloud, &kf_emlrtRTEI);
  emxInit_real_T(sp, &locations, 2, &re_emlrtRTEI);
  emxInit_real_T(sp, &r, 1, &lf_emlrtRTEI);
  emxInit_real_T(sp, &pitch, 1, &df_emlrtRTEI);
  emxInit_real_T(sp, &rowIdx, 1, &mf_emlrtRTEI);
  emxInit_real_T(sp, &pseudoImage, 3, &gf_emlrtRTEI);
  emxInit_real_T(sp, &pseudoIntensity, 2, &hf_emlrtRTEI);
  emxInit_real_T(sp, &pseudoNormal, 3, &if_emlrtRTEI);
  emxInit_real_T(sp, &ptDistance, 2, &jf_emlrtRTEI);
  emxInit_int32_T(sp, &nz, 1, &vd_emlrtRTEI);
  emxInit_real_T(sp, &loc, 2, &qe_emlrtRTEI);
  emxInit_uint8_T(sp, &c, 2, &we_emlrtRTEI);
  emxInit_real_T(sp, &nv, 2, &ye_emlrtRTEI);
  emxInit_real_T(sp, &intensity, 2, &qe_emlrtRTEI);
  emxInit_uint8_T(sp, &color, 2, &fc_emlrtRTEI);
  emxInit_real_T(sp, &normal, 2, &gc_emlrtRTEI);
  emxInit_real_T(sp, &b_intensity, 2, &hc_emlrtRTEI);
  emxInit_real_T(sp, &rangeData, 2, &ic_emlrtRTEI);
  emxInit_int32_T(sp, &b_r, 1, &jc_emlrtRTEI);
  emxInit_int32_T(sp, &r1, 1, &jc_emlrtRTEI);
  emxInit_int32_T(sp, &r2, 1, &jc_emlrtRTEI);
  emxInit_int32_T(sp, &r3, 1, &jc_emlrtRTEI);
  emxInit_int32_T(sp, &r4, 1, &jc_emlrtRTEI);
  emxInit_boolean_T(sp, &r5, 2, &pe_emlrtRTEI);
  emxInit_real_T(sp, &b_locations, 1, &ff_emlrtRTEI);
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &b_ptCloud,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  b_ptCloud.matlabCodegenIsDeleted = true;
  st.site = &uc_emlrtRSI;
  b_st.site = &dd_emlrtRSI;
  c_st.site = &gd_emlrtRSI;
  d_st.site = &fb_emlrtRSI;
  n = (ptCloud->PointCloudArrayData->size[0] *
           ptCloud->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &f_emlrtRTEI, "vision:pointcloud:arrayNotSupported",
        "vision:pointcloud:arrayNotSupported", 3, 4, 19, &cv[0]);
  }
  c_st.site = &hd_emlrtRSI;
  i = locations->size[0] * locations->size[1];
  locations->size[0] = ptCloud->Location->size[0];
  locations->size[1] = 3;
  emxEnsureCapacity_real_T(&c_st, locations, i, &qd_emlrtRTEI);
  locations_data = locations->data;
  loop_ub = ptCloud->Location->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    locations_data[i] = ptCloud->Location->data[i];
  }
  d_st.site = &jd_emlrtRSI;
  e_st.site = &kd_emlrtRSI;
  i = r5->size[0] * r5->size[1];
  r5->size[0] = locations->size[0];
  r5->size[1] = 3;
  emxEnsureCapacity_boolean_T(&e_st, r5, i, &pe_emlrtRTEI);
  r6 = r5->data;
  loop_ub = locations->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    r6[i] = ((!muDoubleScalarIsInf(locations_data[i])) &&
             (!muDoubleScalarIsNaN(locations_data[i])));
  }
  f_st.site = &ld_emlrtRSI;
  combineVectorElements(&f_st, r5, nz);
  nz_data = nz->data;
  c_st.site = &id_emlrtRSI;
  d_st.site = &gc_emlrtRSI;
  i = locations->size[0] * locations->size[1];
  locations->size[0] = ptCloud->Location->size[0];
  locations->size[1] = 3;
  emxEnsureCapacity_real_T(&d_st, locations, i, &ec_emlrtRTEI);
  locations_data = locations->data;
  loop_ub = ptCloud->Location->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    locations_data[i] = ptCloud->Location->data[i];
  }
  i = color->size[0] * color->size[1];
  color->size[0] = ptCloud->Color->size[0];
  color->size[1] = ptCloud->Color->size[1];
  emxEnsureCapacity_uint8_T(&d_st, color, i, &fc_emlrtRTEI);
  color_data = color->data;
  loop_ub = ptCloud->Color->size[0] * ptCloud->Color->size[1];
  for (i = 0; i < loop_ub; i++) {
    color_data[i] = ptCloud->Color->data[i];
  }
  i = normal->size[0] * normal->size[1];
  normal->size[0] = ptCloud->Normal->size[0];
  normal->size[1] = ptCloud->Normal->size[1];
  emxEnsureCapacity_real_T(&d_st, normal, i, &gc_emlrtRTEI);
  pseudoIntensity_data = normal->data;
  loop_ub = ptCloud->Normal->size[0] * ptCloud->Normal->size[1];
  for (i = 0; i < loop_ub; i++) {
    pseudoIntensity_data[i] = ptCloud->Normal->data[i];
  }
  i = b_intensity->size[0] * b_intensity->size[1];
  b_intensity->size[0] = ptCloud->Intensity->size[0];
  b_intensity->size[1] = ptCloud->Intensity->size[1];
  emxEnsureCapacity_real_T(&d_st, b_intensity, i, &hc_emlrtRTEI);
  intensity_data = b_intensity->data;
  loop_ub = ptCloud->Intensity->size[0] * ptCloud->Intensity->size[1];
  for (i = 0; i < loop_ub; i++) {
    intensity_data[i] = ptCloud->Intensity->data[i];
  }
  i = rangeData->size[0] * rangeData->size[1];
  rangeData->size[0] = ptCloud->RangeData->size[0];
  rangeData->size[1] = ptCloud->RangeData->size[1];
  emxEnsureCapacity_real_T(&d_st, rangeData, i, &ic_emlrtRTEI);
  pseudoNormal_data = rangeData->data;
  loop_ub = ptCloud->RangeData->size[0] * ptCloud->RangeData->size[1];
  for (i = 0; i < loop_ub; i++) {
    pseudoNormal_data[i] = ptCloud->RangeData->data[i];
  }
  if (locations->size[0] != 0) {
    end = nz->size[0] - 1;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        trueCount++;
      }
    }
    i = b_r->size[0];
    b_r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(&d_st, b_r, i, &qe_emlrtRTEI);
    r7 = b_r->data;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        r7[trueCount] = b_i;
        trueCount++;
      }
    }
    i = loc->size[0] * loc->size[1];
    loc->size[0] = b_r->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(&d_st, loc, i, &jc_emlrtRTEI);
    r_data = loc->data;
    loop_ub = b_r->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        if (r7[i1] > locations->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r7[i1], 0, locations->size[0] - 1,
                                        &f_emlrtBCI, &d_st);
        }
        r_data[i1 + loc->size[0] * i] =
            locations_data[r7[i1] + locations->size[0] * i];
      }
    }
  } else {
    loc->size[0] = 0;
    loc->size[1] = 3;
  }
  if ((color->size[0] != 0) && (color->size[1] != 0)) {
    end = nz->size[0] - 1;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        trueCount++;
      }
    }
    i = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(&d_st, r1, i, &qe_emlrtRTEI);
    r7 = r1->data;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        r7[trueCount] = b_i;
        trueCount++;
      }
    }
    i = c->size[0] * c->size[1];
    c->size[0] = r1->size[0];
    c->size[1] = color->size[1];
    emxEnsureCapacity_uint8_T(&d_st, c, i, &jc_emlrtRTEI);
    c_data = c->data;
    loop_ub = color->size[1];
    for (i = 0; i < loop_ub; i++) {
      trueCount = r1->size[0];
      for (i1 = 0; i1 < trueCount; i1++) {
        if (r7[i1] > color->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r7[i1], 0, color->size[0] - 1,
                                        &f_emlrtBCI, &d_st);
        }
        c_data[i1 + c->size[0] * i] = color_data[r7[i1] + color->size[0] * i];
      }
    }
  } else {
    c->size[0] = 0;
    c->size[1] = 0;
  }
  if ((normal->size[0] != 0) && (normal->size[1] != 0)) {
    end = nz->size[0] - 1;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        trueCount++;
      }
    }
    i = r2->size[0];
    r2->size[0] = trueCount;
    emxEnsureCapacity_int32_T(&d_st, r2, i, &qe_emlrtRTEI);
    r7 = r2->data;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        r7[trueCount] = b_i;
        trueCount++;
      }
    }
    i = nv->size[0] * nv->size[1];
    nv->size[0] = r2->size[0];
    nv->size[1] = normal->size[1];
    emxEnsureCapacity_real_T(&d_st, nv, i, &jc_emlrtRTEI);
    nv_data = nv->data;
    loop_ub = normal->size[1];
    for (i = 0; i < loop_ub; i++) {
      trueCount = r2->size[0];
      for (i1 = 0; i1 < trueCount; i1++) {
        if (r7[i1] > normal->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r7[i1], 0, normal->size[0] - 1,
                                        &f_emlrtBCI, &d_st);
        }
        nv_data[i1 + nv->size[0] * i] =
            pseudoIntensity_data[r7[i1] + normal->size[0] * i];
      }
    }
  } else {
    nv->size[0] = 0;
    nv->size[1] = 0;
  }
  if ((b_intensity->size[0] != 0) && (b_intensity->size[1] != 0)) {
    end = nz->size[0] - 1;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        trueCount++;
      }
    }
    i = r3->size[0];
    r3->size[0] = trueCount;
    emxEnsureCapacity_int32_T(&d_st, r3, i, &qe_emlrtRTEI);
    r7 = r3->data;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        r7[trueCount] = b_i;
        trueCount++;
      }
    }
    i = intensity->size[0] * intensity->size[1];
    intensity->size[0] = r3->size[0];
    intensity->size[1] = b_intensity->size[1];
    emxEnsureCapacity_real_T(&d_st, intensity, i, &jc_emlrtRTEI);
    r_data = intensity->data;
    loop_ub = b_intensity->size[1];
    for (i = 0; i < loop_ub; i++) {
      trueCount = r3->size[0];
      for (i1 = 0; i1 < trueCount; i1++) {
        if (r7[i1] > b_intensity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r7[i1], 0, b_intensity->size[0] - 1,
                                        &f_emlrtBCI, &d_st);
        }
        r_data[i1 + intensity->size[0] * i] =
            intensity_data[r7[i1] + b_intensity->size[0] * i];
      }
    }
  } else {
    intensity->size[0] = 0;
    intensity->size[1] = 0;
  }
  if ((rangeData->size[0] != 0) && (rangeData->size[1] != 0)) {
    end = nz->size[0] - 1;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        trueCount++;
      }
    }
    i = r4->size[0];
    r4->size[0] = trueCount;
    emxEnsureCapacity_int32_T(&d_st, r4, i, &qe_emlrtRTEI);
    r7 = r4->data;
    trueCount = 0;
    for (b_i = 0; b_i <= end; b_i++) {
      if (nz_data[b_i] == 3) {
        r7[trueCount] = b_i;
        trueCount++;
      }
    }
    i = normal->size[0] * normal->size[1];
    normal->size[0] = r4->size[0];
    normal->size[1] = rangeData->size[1];
    emxEnsureCapacity_real_T(&d_st, normal, i, &jc_emlrtRTEI);
    pseudoIntensity_data = normal->data;
    loop_ub = rangeData->size[1];
    for (i = 0; i < loop_ub; i++) {
      trueCount = r4->size[0];
      for (i1 = 0; i1 < trueCount; i1++) {
        if (r7[i1] > rangeData->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r7[i1], 0, rangeData->size[0] - 1,
                                        &f_emlrtBCI, &d_st);
        }
        pseudoIntensity_data[i1 + normal->size[0] * i] =
            pseudoNormal_data[r7[i1] + rangeData->size[0] * i];
      }
    }
  } else {
    normal->size[0] = 0;
    normal->size[1] = 0;
  }
  b_st.site = &ed_emlrtRSI;
  ptCloudOut = pointCloud_pointCloud(&b_st, &b_ptCloud, loc, c, nv, intensity);
  b_st.site = &fd_emlrtRSI;
  pointCloudBase_set_RangeData(&b_st, ptCloudOut, normal);
  i = locations->size[0] * locations->size[1];
  locations->size[0] = b_ptCloud.Location->size[0];
  locations->size[1] = 3;
  emxEnsureCapacity_real_T(sp, locations, i, &re_emlrtRTEI);
  locations_data = locations->data;
  loop_ub = b_ptCloud.Location->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    locations_data[i] = b_ptCloud.Location->data[i];
  }
  n = (b_ptCloud.Intensity->size[0] == 0);
  b = (b_ptCloud.Intensity->size[1] == 0);
  if ((!n) && (!b)) {
    i = b_intensity->size[0] * b_intensity->size[1];
    b_intensity->size[0] = b_ptCloud.Intensity->size[0];
    b_intensity->size[1] = b_ptCloud.Intensity->size[1];
    emxEnsureCapacity_real_T(sp, b_intensity, i, &te_emlrtRTEI);
    intensity_data = b_intensity->data;
    loop_ub = b_ptCloud.Intensity->size[0] * b_ptCloud.Intensity->size[1];
    for (i = 0; i < loop_ub; i++) {
      intensity_data[i] = b_ptCloud.Intensity->data[i];
    }
  } else {
    i = pitch->size[0];
    pitch->size[0] = b_ptCloud.Location->size[0];
    emxEnsureCapacity_real_T(sp, pitch, i, &se_emlrtRTEI);
    pitch_data = pitch->data;
    loop_ub = b_ptCloud.Location->size[0];
    for (i = 0; i < loop_ub; i++) {
      pitch_data[i] = 0.0;
    }
    i = b_intensity->size[0] * b_intensity->size[1];
    b_intensity->size[0] = pitch->size[0];
    b_intensity->size[1] = 1;
    emxEnsureCapacity_real_T(sp, b_intensity, i, &ue_emlrtRTEI);
    intensity_data = b_intensity->data;
    loop_ub = pitch->size[0];
    for (i = 0; i < loop_ub; i++) {
      intensity_data[i] = 0.0;
    }
  }
  n = (b_ptCloud.Color->size[0] == 0);
  b = (b_ptCloud.Color->size[1] == 0);
  if ((!n) && (!b)) {
    i = c->size[0] * c->size[1];
    c->size[0] = b_ptCloud.Color->size[0];
    c->size[1] = b_ptCloud.Color->size[1];
    emxEnsureCapacity_uint8_T(sp, c, i, &we_emlrtRTEI);
    c_data = c->data;
    loop_ub = b_ptCloud.Color->size[0] * b_ptCloud.Color->size[1];
    for (i = 0; i < loop_ub; i++) {
      c_data[i] = b_ptCloud.Color->data[i];
    }
  } else {
    i = c->size[0] * c->size[1];
    c->size[0] = b_ptCloud.Location->size[0];
    c->size[1] = 3;
    emxEnsureCapacity_uint8_T(sp, c, i, &ve_emlrtRTEI);
    c_data = c->data;
    loop_ub = b_ptCloud.Location->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      c_data[i] = 0U;
    }
  }
  n = (b_ptCloud.Normal->size[0] == 0);
  b = (b_ptCloud.Normal->size[1] == 0);
  if ((!n) && (!b)) {
    i = nv->size[0] * nv->size[1];
    nv->size[0] = b_ptCloud.Normal->size[0];
    nv->size[1] = b_ptCloud.Normal->size[1];
    emxEnsureCapacity_real_T(sp, nv, i, &ye_emlrtRTEI);
    nv_data = nv->data;
    loop_ub = b_ptCloud.Normal->size[0] * b_ptCloud.Normal->size[1];
    for (i = 0; i < loop_ub; i++) {
      nv_data[i] = b_ptCloud.Normal->data[i];
    }
  } else {
    i = nv->size[0] * nv->size[1];
    nv->size[0] = b_ptCloud.Location->size[0];
    nv->size[1] = 3;
    emxEnsureCapacity_real_T(sp, nv, i, &xe_emlrtRTEI);
    nv_data = nv->data;
    loop_ub = b_ptCloud.Location->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      nv_data[i] = 0.0;
    }
  }
  st.site = &cd_emlrtRSI;
  b_st.site = &pd_emlrtRSI;
  i = r->size[0];
  r->size[0] = locations->size[0];
  emxEnsureCapacity_real_T(&b_st, r, i, &af_emlrtRTEI);
  r_data = r->data;
  loop_ub = locations->size[0];
  for (i = 0; i < loop_ub; i++) {
    tmp = locations_data[i];
    r_data[i] = tmp * tmp;
  }
  st.site = &cd_emlrtRSI;
  b_st.site = &pd_emlrtRSI;
  i = pitch->size[0];
  pitch->size[0] = locations->size[0];
  emxEnsureCapacity_real_T(&b_st, pitch, i, &bf_emlrtRTEI);
  pitch_data = pitch->data;
  loop_ub = locations->size[0];
  for (i = 0; i < loop_ub; i++) {
    tmp = locations_data[i + locations->size[0]];
    pitch_data[i] = tmp * tmp;
  }
  if (r->size[0] != pitch->size[0]) {
    emlrtSizeEqCheck1DR2012b(r->size[0], pitch->size[0], &e_emlrtECI,
                             (emlrtConstCTX)sp);
  }
  loop_ub = r->size[0];
  trueCount = (r->size[0] / 2) << 1;
  end = trueCount - 2;
  for (i = 0; i <= end; i += 2) {
    __m128d r9;
    r8 = _mm_loadu_pd(&r_data[i]);
    r9 = _mm_loadu_pd(&pitch_data[i]);
    _mm_storeu_pd(&r_data[i], _mm_add_pd(r8, r9));
  }
  for (i = trueCount; i < loop_ub; i++) {
    r_data[i] += pitch_data[i];
  }
  st.site = &cd_emlrtRSI;
  b_sqrt(&st, r);
  r_data = r->data;
  end = r->size[0] - 1;
  for (b_i = 0; b_i <= end; b_i++) {
    if (r_data[b_i] == 0.0) {
      if (b_i > r->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, r->size[0] - 1, &oc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r_data[b_i] = 1.0E-6;
    }
  }
  st.site = &bd_emlrtRSI;
  b_st.site = &sd_emlrtRSI;
  c_st.site = &td_emlrtRSI;
  if (locations->size[0] == r->size[0]) {
    i = pitch->size[0];
    pitch->size[0] = locations->size[0];
    emxEnsureCapacity_real_T(&c_st, pitch, i, &df_emlrtRTEI);
    pitch_data = pitch->data;
    loop_ub = locations->size[0];
    for (i = 0; i < loop_ub; i++) {
      tmp = locations_data[i + locations->size[0] * 2];
      varargin_2 = r_data[i];
      pitch_data[i] = 57.295779513082323 * muDoubleScalarAtan2(tmp, varargin_2);
    }
  } else {
    i = rowIdx->size[0];
    rowIdx->size[0] = locations->size[0];
    emxEnsureCapacity_real_T(&c_st, rowIdx, i, &cf_emlrtRTEI);
    rowIdx_data = rowIdx->data;
    loop_ub = locations->size[0];
    for (i = 0; i < loop_ub; i++) {
      rowIdx_data[i] = locations_data[i + locations->size[0] * 2];
    }
    d_st.site = &ud_emlrtRSI;
    expand_atan2d(&d_st, rowIdx, r, pitch);
  }
  i = rowIdx->size[0];
  rowIdx->size[0] = locations->size[0];
  emxEnsureCapacity_real_T(sp, rowIdx, i, &ef_emlrtRTEI);
  rowIdx_data = rowIdx->data;
  loop_ub = locations->size[0];
  i = b_locations->size[0];
  b_locations->size[0] = locations->size[0];
  emxEnsureCapacity_real_T(sp, b_locations, i, &ff_emlrtRTEI);
  r_data = b_locations->data;
  for (i = 0; i < loop_ub; i++) {
    rowIdx_data[i] = locations_data[i + locations->size[0]];
    r_data[i] = locations_data[i];
  }
  st.site = &ad_emlrtRSI;
  b_atan2d(&st, rowIdx, b_locations, r);
  r_data = r->data;
  loop_ub = r->size[0];
  trueCount = (r->size[0] / 2) << 1;
  end = trueCount - 2;
  for (i = 0; i <= end; i += 2) {
    r8 = _mm_loadu_pd(&r_data[i]);
    _mm_storeu_pd(&r_data[i], _mm_sub_pd(_mm_set1_pd(180.0), r8));
  }
  for (i = trueCount; i < loop_ub; i++) {
    r_data[i] = 180.0 - r_data[i];
  }
  st.site = &yc_emlrtRSI;
  b_st.site = &yc_emlrtRSI;
  varargin_1_size[0] = 1;
  varargin_1_size[1] = 16;
  memcpy(&varargin_1_data[0], &vbeamAngles_data[0], 16U * sizeof(real_T));
  c_st.site = &ce_emlrtRSI;
  d_st.site = &de_emlrtRSI;
  c_st.site = &be_emlrtRSI;
  for (trueCount = 0; trueCount < 8; trueCount++) {
    tmp = varargin_1_data[trueCount];
    varargin_1_data[trueCount] = varargin_1_data[15 - trueCount];
    varargin_1_data[15 - trueCount] = tmp;
  }
  b_st.site = &ee_emlrtRSI;
  c_st.site = &fe_emlrtRSI;
  memcpy(&a__2_data[0], &varargin_1_data[0], 16U * sizeof(real_T));
  a__2_data[16] = rtInf;
  st.site = &yc_emlrtRSI;
  histcounts(&st, pitch, a__2_data, varargin_1_data, varargin_1_size, rowIdx);
  rowIdx_data = rowIdx->data;
  end = rowIdx->size[0] - 1;
  for (b_i = 0; b_i <= end; b_i++) {
    if (rowIdx_data[b_i] == 0.0) {
      if (b_i > rowIdx->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, rowIdx->size[0] - 1, &pc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      rowIdx_data[b_i] = rtNaN;
    }
  }
  loop_ub = rowIdx->size[0];
  trueCount = (rowIdx->size[0] / 2) << 1;
  end = trueCount - 2;
  for (i = 0; i <= end; i += 2) {
    r8 = _mm_loadu_pd(&rowIdx_data[i]);
    _mm_storeu_pd(&rowIdx_data[i], _mm_add_pd(_mm_sub_pd(_mm_set1_pd(16.0), r8),
                                              _mm_set1_pd(1.0)));
  }
  for (i = trueCount; i < loop_ub; i++) {
    rowIdx_data[i] = (16.0 - rowIdx_data[i]) + 1.0;
  }
  memcpy(&a__4[0], &hbeamAngles[0], 1024U * sizeof(real_T));
  a__4[1024] = rtInf;
  st.site = &xc_emlrtRSI;
  b_histcounts(&st, r, a__4, a__3, pitch);
  pitch_data = pitch->data;
  end = pitch->size[0] - 1;
  for (b_i = 0; b_i <= end; b_i++) {
    if (pitch_data[b_i] == 0.0) {
      if (b_i > pitch->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, pitch->size[0] - 1, &qc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      pitch_data[b_i] = rtNaN;
    }
  }
  i = pseudoImage->size[0] * pseudoImage->size[1] * pseudoImage->size[2];
  pseudoImage->size[0] = 16;
  pseudoImage->size[1] = 1024;
  pseudoImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, pseudoImage, i, &gf_emlrtRTEI);
  r_data = pseudoImage->data;
  for (i = 0; i < 49152; i++) {
    r_data[i] = rtNaN;
  }
  i = pseudoIntensity->size[0] * pseudoIntensity->size[1];
  pseudoIntensity->size[0] = 16;
  pseudoIntensity->size[1] = 1024;
  emxEnsureCapacity_real_T(sp, pseudoIntensity, i, &hf_emlrtRTEI);
  pseudoIntensity_data = pseudoIntensity->data;
  for (i = 0; i < 16384; i++) {
    pseudoIntensity_data[i] = 0.0;
  }
  pseudoColor_size[0] = 16;
  pseudoColor_size[1] = 1024;
  pseudoColor_size[2] = 3;
  i = pseudoNormal->size[0] * pseudoNormal->size[1] * pseudoNormal->size[2];
  pseudoNormal->size[0] = 16;
  pseudoNormal->size[1] = 1024;
  pseudoNormal->size[2] = 3;
  emxEnsureCapacity_real_T(sp, pseudoNormal, i, &if_emlrtRTEI);
  pseudoNormal_data = pseudoNormal->data;
  for (i = 0; i < 49152; i++) {
    pseudoColor_data[i] = 0U;
    pseudoNormal_data[i] = rtNaN;
  }
  i = ptDistance->size[0] * ptDistance->size[1];
  ptDistance->size[0] = 16;
  ptDistance->size[1] = 1024;
  emxEnsureCapacity_real_T(sp, ptDistance, i, &jf_emlrtRTEI);
  ptDistance_data = ptDistance->data;
  for (i = 0; i < 16384; i++) {
    ptDistance_data[i] = 0.0;
  }
  i = locations->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i + 1 > rowIdx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0], &nb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (!muDoubleScalarIsNaN(rowIdx_data[b_i])) {
      if (b_i + 1 > pitch->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0], &ob_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (!muDoubleScalarIsNaN(pitch_data[b_i])) {
        real_T d;
        real_T d1;
        real_T d2;
        if (b_i + 1 > rowIdx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                        &rc_emlrtBCI, (emlrtConstCTX)sp);
        }
        varargin_2 = rowIdx_data[b_i];
        d = (int32_T)muDoubleScalarFloor(varargin_2);
        if (varargin_2 != d) {
          emlrtIntegerCheckR2012b(varargin_2, &c_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                        &pb_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (b_i + 1 > pitch->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                        &sc_emlrtBCI, (emlrtConstCTX)sp);
        }
        d1 = pitch_data[b_i];
        d2 = (int32_T)muDoubleScalarFloor(d1);
        if (d1 != d2) {
          emlrtIntegerCheckR2012b(d1, &d_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &qb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        i1 = (int32_T)rowIdx_data[b_i] - 1;
        trueCount = (int32_T)pitch_data[b_i] - 1;
        end = i1 + 16 * trueCount;
        if (muDoubleScalarIsNaN(r_data[end])) {
          real_T absxk;
          real_T scale;
          real_T t;
          if (b_i + 1 > locations->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, locations->size[0],
                                          &rb_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (b_i + 1 > rowIdx->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                          &tc_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (varargin_2 != d) {
            emlrtIntegerCheckR2012b(varargin_2, &e_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                          &sb_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (b_i + 1 > pitch->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                          &uc_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (d1 != d2) {
            emlrtIntegerCheckR2012b(d1, &f_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &tb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          r_data[end] = locations_data[b_i];
          r_data[end + 16384] = locations_data[b_i + locations->size[0]];
          r_data[end + 32768] = locations_data[b_i + locations->size[0] * 2];
          if (b_intensity->size[1] < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1, b_intensity->size[1],
                                          &ub_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (b_i + 1 > b_intensity->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, b_intensity->size[0],
                                          &vc_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (b_i + 1 > rowIdx->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                          &xc_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (varargin_2 != d) {
            emlrtIntegerCheckR2012b(varargin_2, &q_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                          &wc_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (b_i + 1 > pitch->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                          &ad_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (d1 != d2) {
            emlrtIntegerCheckR2012b(d1, &r_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &yc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          pseudoIntensity_data[((int32_T)varargin_2 +
                                pseudoIntensity->size[0] * ((int32_T)d1 - 1)) -
                               1] = intensity_data[b_i];
          if (b_i + 1 > c->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, c->size[0], &vb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (b_i + 1 > rowIdx->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                          &gd_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (varargin_2 != d) {
            emlrtIntegerCheckR2012b(varargin_2, &i_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                          &gc_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (b_i + 1 > pitch->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                          &id_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (d1 != d2) {
            emlrtIntegerCheckR2012b(d1, &j_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &hc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (c->size[1] < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1, c->size[1], &ee_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          pseudoColor_data[i1 + pseudoColor_size[0] * trueCount] = c_data[b_i];
          if (c->size[1] < 2) {
            emlrtDynamicBoundsCheckR2012b(2, 1, c->size[1], &ee_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          pseudoColor_data[(i1 + pseudoColor_size[0] * trueCount) +
                           pseudoColor_size[0] * pseudoColor_size[1]] =
              c_data[b_i + c->size[0]];
          if (c->size[1] < 3) {
            emlrtDynamicBoundsCheckR2012b(3, 1, c->size[1], &ee_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          pseudoColor_data[(i1 + pseudoColor_size[0] * trueCount) +
                           pseudoColor_size[0] * pseudoColor_size[1] * 2] =
              c_data[b_i + c->size[0] * 2];
          if (b_i + 1 > nv->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nv->size[0], &wb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (b_i + 1 > rowIdx->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                          &od_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (varargin_2 != d) {
            emlrtIntegerCheckR2012b(varargin_2, &m_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                          &kc_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (b_i + 1 > pitch->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                          &pd_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (d1 != d2) {
            emlrtIntegerCheckR2012b(d1, &n_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &lc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (nv->size[1] < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1, nv->size[1], &de_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          pseudoNormal_data[i1 + pseudoNormal->size[0] * trueCount] =
              nv_data[b_i];
          if (nv->size[1] < 2) {
            emlrtDynamicBoundsCheckR2012b(2, 1, nv->size[1], &de_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          pseudoNormal_data[(i1 + pseudoNormal->size[0] * trueCount) +
                            pseudoNormal->size[0] * pseudoNormal->size[1]] =
              nv_data[b_i + nv->size[0]];
          if (nv->size[1] < 3) {
            emlrtDynamicBoundsCheckR2012b(3, 1, nv->size[1], &de_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          pseudoNormal_data[(i1 + pseudoNormal->size[0] * trueCount) +
                            pseudoNormal->size[0] * pseudoNormal->size[1] * 2] =
              nv_data[b_i + nv->size[0] * 2];
          if (b_i + 1 > locations->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, locations->size[0],
                                          &xb_emlrtBCI, (emlrtConstCTX)sp);
          }
          scale = 3.3121686421112381E-170;
          absxk = muDoubleScalarAbs(locations_data[b_i]);
          if (absxk > 3.3121686421112381E-170) {
            tmp = 1.0;
            scale = absxk;
          } else {
            t = absxk / 3.3121686421112381E-170;
            tmp = t * t;
          }
          absxk = muDoubleScalarAbs(locations_data[b_i + locations->size[0]]);
          if (absxk > scale) {
            t = scale / absxk;
            tmp = tmp * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            tmp += t * t;
          }
          absxk =
              muDoubleScalarAbs(locations_data[b_i + locations->size[0] * 2]);
          if (absxk > scale) {
            t = scale / absxk;
            tmp = tmp * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            tmp += t * t;
          }
          if (b_i + 1 > rowIdx->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                          &vd_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (varargin_2 != d) {
            emlrtIntegerCheckR2012b(varargin_2, &w_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                          &ud_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (b_i + 1 > pitch->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                          &xd_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (d1 != d2) {
            emlrtIntegerCheckR2012b(d1, &x_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &wd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          ptDistance_data[((int32_T)varargin_2 + 16 * ((int32_T)d1 - 1)) - 1] =
              scale * muDoubleScalarSqrt(tmp);
        } else {
          real_T absxk;
          real_T scale;
          real_T t;
          if (b_i + 1 > locations->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, locations->size[0],
                                          &yb_emlrtBCI, (emlrtConstCTX)sp);
          }
          scale = 3.3121686421112381E-170;
          absxk = muDoubleScalarAbs(locations_data[b_i]);
          if (absxk > 3.3121686421112381E-170) {
            tmp = 1.0;
            scale = absxk;
          } else {
            t = absxk / 3.3121686421112381E-170;
            tmp = t * t;
          }
          absxk = muDoubleScalarAbs(locations_data[b_i + locations->size[0]]);
          if (absxk > scale) {
            t = scale / absxk;
            tmp = tmp * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            tmp += t * t;
          }
          absxk =
              muDoubleScalarAbs(locations_data[b_i + locations->size[0] * 2]);
          if (absxk > scale) {
            t = scale / absxk;
            tmp = tmp * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            tmp += t * t;
          }
          tmp = scale * muDoubleScalarSqrt(tmp);
          if (b_i + 1 > rowIdx->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                          &cd_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (varargin_2 != d) {
            emlrtIntegerCheckR2012b(varargin_2, &s_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                          &bd_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (b_i + 1 > pitch->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                          &ed_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (d1 != d2) {
            emlrtIntegerCheckR2012b(d1, &t_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &dd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          loop_ub = ((int32_T)varargin_2 + 16 * ((int32_T)d1 - 1)) - 1;
          if (tmp < ptDistance_data[loop_ub]) {
            if (b_i + 1 > locations->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, locations->size[0],
                                            &ac_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > rowIdx->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                            &fd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (varargin_2 != d) {
              emlrtIntegerCheckR2012b(varargin_2, &g_emlrtDCI,
                                      (emlrtConstCTX)sp);
            }
            if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                            &bc_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > pitch->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                            &hd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (d1 != d2) {
              emlrtIntegerCheckR2012b(d1, &h_emlrtDCI, (emlrtConstCTX)sp);
            }
            if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &cc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            r_data[end] = locations_data[b_i];
            r_data[(i1 + 16 * trueCount) + 16384] =
                locations_data[b_i + locations->size[0]];
            r_data[(i1 + 16 * trueCount) + 32768] =
                locations_data[b_i + locations->size[0] * 2];
            if (b_intensity->size[1] < 1) {
              emlrtDynamicBoundsCheckR2012b(1, 1, b_intensity->size[1],
                                            &dc_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > b_intensity->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, b_intensity->size[0],
                                            &jd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > rowIdx->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                            &ld_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (varargin_2 != d) {
              emlrtIntegerCheckR2012b(varargin_2, &u_emlrtDCI,
                                      (emlrtConstCTX)sp);
            }
            if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                            &kd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > pitch->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                            &nd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (d1 != d2) {
              emlrtIntegerCheckR2012b(d1, &v_emlrtDCI, (emlrtConstCTX)sp);
            }
            if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &md_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            pseudoIntensity_data[((int32_T)varargin_2 +
                                  pseudoIntensity->size[0] *
                                      ((int32_T)d1 - 1)) -
                                 1] = intensity_data[b_i];
            if (b_i + 1 > c->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, c->size[0],
                                            &ec_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > rowIdx->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                            &qd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (varargin_2 != d) {
              emlrtIntegerCheckR2012b(varargin_2, &k_emlrtDCI,
                                      (emlrtConstCTX)sp);
            }
            if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                            &ic_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > pitch->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                            &rd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (d1 != d2) {
              emlrtIntegerCheckR2012b(d1, &l_emlrtDCI, (emlrtConstCTX)sp);
            }
            if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &jc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (c->size[1] < 1) {
              emlrtDynamicBoundsCheckR2012b(1, 1, c->size[1], &ge_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            pseudoColor_data[i1 + pseudoColor_size[0] * trueCount] =
                c_data[b_i];
            if (c->size[1] < 2) {
              emlrtDynamicBoundsCheckR2012b(2, 1, c->size[1], &ge_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            pseudoColor_data[(i1 + pseudoColor_size[0] * trueCount) +
                             pseudoColor_size[0] * pseudoColor_size[1]] =
                c_data[b_i + c->size[0]];
            if (c->size[1] < 3) {
              emlrtDynamicBoundsCheckR2012b(3, 1, c->size[1], &ge_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            pseudoColor_data[(i1 + pseudoColor_size[0] * trueCount) +
                             pseudoColor_size[0] * pseudoColor_size[1] * 2] =
                c_data[b_i + c->size[0] * 2];
            if (b_i + 1 > nv->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nv->size[0],
                                            &fc_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > rowIdx->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                            &sd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (varargin_2 != d) {
              emlrtIntegerCheckR2012b(varargin_2, &o_emlrtDCI,
                                      (emlrtConstCTX)sp);
            }
            if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                            &mc_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > pitch->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                            &td_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (d1 != d2) {
              emlrtIntegerCheckR2012b(d1, &p_emlrtDCI, (emlrtConstCTX)sp);
            }
            if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &nc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (nv->size[1] < 1) {
              emlrtDynamicBoundsCheckR2012b(1, 1, nv->size[1], &fe_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            pseudoNormal_data[i1 + pseudoNormal->size[0] * trueCount] =
                nv_data[b_i];
            if (nv->size[1] < 2) {
              emlrtDynamicBoundsCheckR2012b(2, 1, nv->size[1], &fe_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            pseudoNormal_data[(i1 + pseudoNormal->size[0] * trueCount) +
                              pseudoNormal->size[0] * pseudoNormal->size[1]] =
                nv_data[b_i + nv->size[0]];
            if (nv->size[1] < 3) {
              emlrtDynamicBoundsCheckR2012b(3, 1, nv->size[1], &fe_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            pseudoNormal_data[(i1 + pseudoNormal->size[0] * trueCount) +
                              pseudoNormal->size[0] * pseudoNormal->size[1] *
                                  2] = nv_data[b_i + nv->size[0] * 2];
            if (b_i + 1 > rowIdx->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, rowIdx->size[0],
                                            &ae_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (varargin_2 != d) {
              emlrtIntegerCheckR2012b(varargin_2, &y_emlrtDCI,
                                      (emlrtConstCTX)sp);
            }
            if (((int32_T)varargin_2 < 1) || ((int32_T)varargin_2 > 16)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)varargin_2, 1, 16,
                                            &yd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (b_i + 1 > pitch->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pitch->size[0],
                                            &ce_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (d1 != d2) {
              emlrtIntegerCheckR2012b(d1, &ab_emlrtDCI, (emlrtConstCTX)sp);
            }
            if (((int32_T)d1 < 1) || ((int32_T)d1 > 1024)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1024, &be_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            ptDistance_data[loop_ub] = tmp;
          }
        }
      }
    }
  }
  n = (b_ptCloud.Intensity->size[0] == 0);
  b = (b_ptCloud.Intensity->size[1] == 0);
  if (n || b) {
    pseudoIntensity->size[0] = 0;
    pseudoIntensity->size[1] = 0;
  }
  n = (b_ptCloud.Color->size[0] == 0);
  b = (b_ptCloud.Color->size[1] == 0);
  if (n || b) {
    pseudoColor_size[0] = 0;
    pseudoColor_size[1] = 0;
    pseudoColor_size[2] = 1;
  }
  n = (b_ptCloud.Normal->size[0] == 0);
  b = (b_ptCloud.Normal->size[1] == 0);
  if (n || b) {
    pseudoNormal->size[0] = 0;
    pseudoNormal->size[1] = 0;
    pseudoNormal->size[2] = 1;
  }
  st.site = &wc_emlrtRSI;
  ptCloudOrg = iobj_0;
  iobj_0->HasKdtreeConstructed = false;
  iobj_0->HasLocationHandleAllocated = false;
  b_st.site = &j_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  i = iobj_0->Location->size[0] * iobj_0->Location->size[1] *
      iobj_0->Location->size[2];
  iobj_0->Location->size[0] = 16;
  iobj_0->Location->size[1] = 1024;
  iobj_0->Location->size[2] = 3;
  emxEnsureCapacity_real_T(&b_st, iobj_0->Location, i, &kb_emlrtRTEI);
  for (i = 0; i < 49152; i++) {
    iobj_0->Location->data[i] = r_data[i];
  }
  b_pseudoColor_data.data = &pseudoColor_data[0];
  b_pseudoColor_data.size = &pseudoColor_size[0];
  b_pseudoColor_data.allocatedSize = 49152;
  b_pseudoColor_data.numDimensions = 3;
  b_pseudoColor_data.canFreeData = false;
  c_st.site = &n_emlrtRSI;
  b_pointCloudBase_set_Color(&c_st, iobj_0, &b_pseudoColor_data);
  c_st.site = &o_emlrtRSI;
  pointCloudBase_set_Normal(&c_st, iobj_0, pseudoNormal);
  c_st.site = &p_emlrtRSI;
  pointCloudBase_set_Intensity(&c_st, iobj_0, pseudoIntensity);
  tmp_size[0] = 0;
  tmp_size[1] = 0;
  tmp_size[2] = 0;
  tmp_data.size = &tmp_size[0];
  tmp_data.allocatedSize = 0;
  tmp_data.numDimensions = 3;
  tmp_data.canFreeData = false;
  c_st.site = &q_emlrtRSI;
  b_pointCloudBase_set_RangeData(&c_st, iobj_0, &tmp_data);
  b_st.site = &k_emlrtRSI;
  iobj_0->PointCloudArrayData->size[0] = 1;
  iobj_0->PointCloudArrayData->size[1] = 1;
  b_st.site = &l_emlrtRSI;
  iobj_0->Kdtree = NULL;
  iobj_0->LocationHandle = NULL;
  iobj_0->matlabCodegenIsDeleted = false;
  st.site = &vc_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &b_ptCloud);
  emxFree_real_T(sp, &b_locations);
  emxFree_boolean_T(sp, &r5);
  emxFree_int32_T(sp, &r4);
  emxFree_int32_T(sp, &r3);
  emxFree_int32_T(sp, &r2);
  emxFree_int32_T(sp, &r1);
  emxFree_int32_T(sp, &b_r);
  emxFree_real_T(sp, &rangeData);
  emxFree_real_T(sp, &b_intensity);
  emxFree_real_T(sp, &normal);
  emxFree_uint8_T(sp, &color);
  emxFree_real_T(sp, &intensity);
  emxFree_real_T(sp, &nv);
  emxFree_uint8_T(sp, &c);
  emxFree_real_T(sp, &loc);
  emxFree_int32_T(sp, &nz);
  emxFree_real_T(sp, &ptDistance);
  emxFree_real_T(sp, &pseudoNormal);
  emxFree_real_T(sp, &pseudoIntensity);
  emxFree_real_T(sp, &pseudoImage);
  emxFree_real_T(sp, &rowIdx);
  emxFree_real_T(sp, &pitch);
  emxFree_real_T(sp, &r);
  emxFree_real_T(sp, &locations);
  emxFreeStruct_pointCloud(sp, &b_ptCloud);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return ptCloudOrg;
}

/* End of code generation (pcorganize.c) */
