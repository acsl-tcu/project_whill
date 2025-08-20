//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mexLidarTracker_data.h
//
//  Code generation for function 'mexLidarTracker_data'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern boolean_T isMexOutdated;
extern const char_T *mexLidarTracker_complete_name;
extern const char_T *c_HelperBoundingBoxDetector_Hel;
extern const char_T *c_HelperBoundingBoxDetector_ste;
extern const char_T *cropPointCloud2_complete_name;
extern const char_T *removeGroundPlane_complete_name;
extern const char_T *getBoundingBoxes_complete_name;
extern const char_T *homogeneous_complete_name;
extern const char_T *c_assembleDetections_complete_n;
extern const char_T *initializeEKF_complete_name;
extern const char_T *c_helperCalcDetectability_compl;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo l_emlrtRSI;
extern emlrtRSInfo yb_emlrtRSI;
extern emlrtRSInfo ec_emlrtRSI;
extern emlrtRSInfo gc_emlrtRSI;
extern emlrtRSInfo hc_emlrtRSI;
extern emlrtRSInfo jc_emlrtRSI;
extern emlrtRSInfo lc_emlrtRSI;
extern emlrtRSInfo mc_emlrtRSI;
extern emlrtRSInfo md_emlrtRSI;
extern emlrtRSInfo nd_emlrtRSI;
extern emlrtRSInfo od_emlrtRSI;
extern emlrtRSInfo pd_emlrtRSI;
extern emlrtRSInfo qd_emlrtRSI;
extern emlrtRSInfo rd_emlrtRSI;
extern emlrtRSInfo sd_emlrtRSI;
extern emlrtRSInfo td_emlrtRSI;
extern emlrtRSInfo ud_emlrtRSI;
extern emlrtRSInfo vd_emlrtRSI;
extern emlrtRSInfo wd_emlrtRSI;
extern emlrtRSInfo xd_emlrtRSI;
extern emlrtRSInfo yd_emlrtRSI;
extern emlrtRSInfo ie_emlrtRSI;
extern emlrtRSInfo je_emlrtRSI;
extern emlrtRSInfo ke_emlrtRSI;
extern emlrtRSInfo le_emlrtRSI;
extern emlrtRSInfo xe_emlrtRSI;
extern emlrtRSInfo jf_emlrtRSI;
extern emlrtRSInfo ig_emlrtRSI;
extern emlrtRSInfo qg_emlrtRSI;
extern emlrtRSInfo rg_emlrtRSI;
extern emlrtRSInfo sg_emlrtRSI;
extern emlrtRSInfo tg_emlrtRSI;
extern emlrtRSInfo ug_emlrtRSI;
extern emlrtRSInfo vg_emlrtRSI;
extern emlrtRSInfo wi_emlrtRSI;
extern emlrtRSInfo xi_emlrtRSI;
extern emlrtRSInfo yi_emlrtRSI;
extern emlrtRSInfo aj_emlrtRSI;
extern emlrtRSInfo bj_emlrtRSI;
extern emlrtRSInfo tj_emlrtRSI;
extern emlrtRSInfo uj_emlrtRSI;
extern emlrtRSInfo yj_emlrtRSI;
extern emlrtRSInfo ak_emlrtRSI;
extern emlrtRSInfo bk_emlrtRSI;
extern emlrtRSInfo ck_emlrtRSI;
extern emlrtRSInfo fk_emlrtRSI;
extern emlrtRSInfo gk_emlrtRSI;
extern emlrtRSInfo hk_emlrtRSI;
extern emlrtRSInfo ik_emlrtRSI;
extern emlrtRSInfo jk_emlrtRSI;
extern emlrtRSInfo kk_emlrtRSI;
extern emlrtRSInfo lk_emlrtRSI;
extern emlrtRSInfo pk_emlrtRSI;
extern emlrtRSInfo qk_emlrtRSI;
extern emlrtRSInfo tk_emlrtRSI;
extern emlrtRSInfo yk_emlrtRSI;
extern emlrtRSInfo il_emlrtRSI;
extern emlrtRSInfo gn_emlrtRSI;
extern emlrtRSInfo pn_emlrtRSI;
extern emlrtRSInfo qn_emlrtRSI;
extern emlrtRSInfo un_emlrtRSI;
extern emlrtRSInfo vn_emlrtRSI;
extern emlrtRSInfo wn_emlrtRSI;
extern emlrtRSInfo jo_emlrtRSI;
extern emlrtRSInfo no_emlrtRSI;
extern emlrtRSInfo oo_emlrtRSI;
extern emlrtRSInfo po_emlrtRSI;
extern emlrtRSInfo qo_emlrtRSI;
extern emlrtRSInfo ro_emlrtRSI;
extern emlrtRSInfo so_emlrtRSI;
extern emlrtRSInfo to_emlrtRSI;
extern emlrtRSInfo uo_emlrtRSI;
extern emlrtRSInfo vo_emlrtRSI;
extern emlrtRSInfo wo_emlrtRSI;
extern emlrtRSInfo xo_emlrtRSI;
extern emlrtRSInfo yo_emlrtRSI;
extern emlrtRSInfo ap_emlrtRSI;
extern emlrtRSInfo bp_emlrtRSI;
extern emlrtRSInfo cp_emlrtRSI;
extern emlrtRSInfo dp_emlrtRSI;
extern emlrtRSInfo ep_emlrtRSI;
extern emlrtRSInfo fp_emlrtRSI;
extern emlrtRSInfo gp_emlrtRSI;
extern emlrtRSInfo hp_emlrtRSI;
extern emlrtRSInfo ip_emlrtRSI;
extern emlrtRSInfo jp_emlrtRSI;
extern emlrtRSInfo kp_emlrtRSI;
extern emlrtRSInfo lp_emlrtRSI;
extern emlrtRSInfo np_emlrtRSI;
extern emlrtRSInfo op_emlrtRSI;
extern emlrtRSInfo pp_emlrtRSI;
extern emlrtRSInfo rp_emlrtRSI;
extern emlrtRSInfo vp_emlrtRSI;
extern emlrtRSInfo vr_emlrtRSI;
extern emlrtRSInfo wr_emlrtRSI;
extern emlrtRSInfo xr_emlrtRSI;
extern emlrtRSInfo et_emlrtRSI;
extern emlrtRSInfo gt_emlrtRSI;
extern emlrtRSInfo ht_emlrtRSI;
extern emlrtRSInfo it_emlrtRSI;
extern emlrtRSInfo jt_emlrtRSI;
extern emlrtRSInfo kt_emlrtRSI;
extern emlrtRSInfo xt_emlrtRSI;
extern emlrtRSInfo yt_emlrtRSI;
extern emlrtRSInfo au_emlrtRSI;
extern emlrtRSInfo bu_emlrtRSI;
extern emlrtRSInfo cu_emlrtRSI;
extern emlrtRSInfo su_emlrtRSI;
extern emlrtRSInfo ry_emlrtRSI;
extern emlrtRSInfo sy_emlrtRSI;
extern emlrtRSInfo ty_emlrtRSI;
extern emlrtRSInfo bab_emlrtRSI;
extern emlrtRSInfo cab_emlrtRSI;
extern emlrtRSInfo dab_emlrtRSI;
extern emlrtRSInfo eab_emlrtRSI;
extern emlrtRSInfo fab_emlrtRSI;
extern emlrtRSInfo gab_emlrtRSI;
extern emlrtRSInfo hab_emlrtRSI;
extern emlrtRSInfo iab_emlrtRSI;
extern emlrtRSInfo jab_emlrtRSI;
extern emlrtRSInfo kab_emlrtRSI;
extern emlrtRSInfo lab_emlrtRSI;
extern emlrtRSInfo mab_emlrtRSI;
extern emlrtRSInfo nab_emlrtRSI;
extern emlrtRSInfo oab_emlrtRSI;
extern emlrtRSInfo pab_emlrtRSI;
extern emlrtRSInfo qab_emlrtRSI;
extern emlrtRSInfo rab_emlrtRSI;
extern emlrtRSInfo sab_emlrtRSI;
extern emlrtRSInfo tab_emlrtRSI;
extern emlrtRSInfo uab_emlrtRSI;
extern emlrtRSInfo tbb_emlrtRSI;
extern emlrtRSInfo ecb_emlrtRSI;
extern emlrtRSInfo hcb_emlrtRSI;
extern emlrtRSInfo icb_emlrtRSI;
extern emlrtRSInfo jcb_emlrtRSI;
extern emlrtRSInfo kcb_emlrtRSI;
extern emlrtRSInfo mcb_emlrtRSI;
extern emlrtRSInfo aeb_emlrtRSI;
extern emlrtRSInfo beb_emlrtRSI;
extern emlrtRSInfo xfb_emlrtRSI;
extern emlrtRSInfo ogb_emlrtRSI;
extern emlrtRSInfo chb_emlrtRSI;
extern emlrtRSInfo dhb_emlrtRSI;
extern emlrtRTEInfo emlrtRTEI;
extern emlrtRTEInfo j_emlrtRTEI;
extern emlrtRTEInfo n_emlrtRTEI;
extern emlrtRTEInfo o_emlrtRTEI;
extern emlrtRTEInfo s_emlrtRTEI;
extern emlrtRTEInfo u_emlrtRTEI;
extern emlrtRTEInfo w_emlrtRTEI;
extern emlrtRTEInfo x_emlrtRTEI;
extern emlrtRTEInfo y_emlrtRTEI;
extern emlrtRTEInfo db_emlrtRTEI;
extern emlrtRTEInfo eb_emlrtRTEI;
extern emlrtRTEInfo ib_emlrtRTEI;
extern emlrtRTEInfo jb_emlrtRTEI;
extern emlrtRTEInfo ob_emlrtRTEI;
extern emlrtRTEInfo qb_emlrtRTEI;
extern emlrtRTEInfo ub_emlrtRTEI;
extern emlrtRTEInfo wb_emlrtRTEI;
extern emlrtBCInfo cd_emlrtBCI;
extern emlrtRTEInfo yb_emlrtRTEI;
extern emlrtRTEInfo ac_emlrtRTEI;
extern emlrtDCInfo p_emlrtDCI;
extern emlrtRTEInfo jc_emlrtRTEI;
extern emlrtRTEInfo uc_emlrtRTEI;
extern emlrtRTEInfo uf_emlrtRTEI;
extern emlrtRTEInfo hg_emlrtRTEI;
extern emlrtRTEInfo ig_emlrtRTEI;
extern emlrtRTEInfo kg_emlrtRTEI;
extern emlrtRTEInfo lg_emlrtRTEI;
extern emlrtRTEInfo og_emlrtRTEI;
extern emlrtRTEInfo th_emlrtRTEI;
extern emlrtRTEInfo rk_emlrtRTEI;
extern emlrtRTEInfo wk_emlrtRTEI;
extern emlrtRTEInfo nm_emlrtRTEI;
extern emlrtRTEInfo xn_emlrtRTEI;
extern emlrtRTEInfo yn_emlrtRTEI;
extern const int8_T iv[9];

// End of code generation (mexLidarTracker_data.h)
