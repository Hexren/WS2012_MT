/* Include files */

#include "blascompat32.h"
#include "Erdorbits_sfun.h"
#include "c1_Erdorbits.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Erdorbits_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[10] = { "nE", "tE", "vt", "vn",
  "nargin", "nargout", "v0", "thetaDegree", "x0", "v0welt" };

/* Function Declarations */
static void initialize_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance);
static void initialize_params_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance);
static void enable_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance);
static void disable_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance);
static void set_sim_state_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance);
static void sf_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance);
static void c1_chartstep_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance);
static void initSimStructsc1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_v0welt, const char_T *c1_identifier, real_T c1_y[2]);
static void c1_b_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[39]);
static void c1_eml_int_forloop_overflow_check(SFc1_ErdorbitsInstanceStruct
  *chartInstance);
static void c1_eml_scalar_rem90(SFc1_ErdorbitsInstanceStruct *chartInstance,
  real_T c1_x, real_T *c1_n, real_T *c1_y);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_Erdorbits, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_ErdorbitsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_Erdorbits = 0U;
}

static void initialize_params_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance)
{
}

static void enable_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[2];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_v0welt)[2];
  c1_v0welt = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    c1_u[c1_i0] = (*c1_v0welt)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_Erdorbits;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[2];
  int32_T c1_i1;
  real_T (*c1_v0welt)[2];
  c1_v0welt = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "v0welt", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    (*c1_v0welt)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_Erdorbits = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "is_active_c1_Erdorbits");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Erdorbits(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance)
{
}

static void sf_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  real_T *c1_v0;
  real_T *c1_thetaDegree;
  real_T (*c1_x0)[2];
  real_T (*c1_v0welt)[2];
  c1_x0 = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c1_thetaDegree = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_v0welt = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_v0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_v0, 0U);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_v0welt)[c1_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_thetaDegree, 2U);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_x0)[c1_i3], 3U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_Erdorbits(chartInstance);
  sf_debug_check_for_state_inconsistency(_ErdorbitsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_v0;
  real_T c1_thetaDegree;
  int32_T c1_i4;
  real_T c1_x0[2];
  uint32_T c1_debug_family_var_map[10];
  real_T c1_nE[2];
  real_T c1_tE[2];
  real_T c1_vt;
  real_T c1_vn;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_v0welt[2];
  int32_T c1_i5;
  real_T c1_x[2];
  real_T c1_y;
  real_T c1_scale;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_absxk;
  real_T c1_t;
  int32_T c1_i6;
  real_T c1_B;
  real_T c1_b_y;
  real_T c1_c_y;
  int32_T c1_i7;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  boolean_T c1_b;
  boolean_T c1_b0;
  real_T c1_h_x;
  boolean_T c1_b_b;
  boolean_T c1_b1;
  boolean_T c1_c_b;
  real_T c1_i_x;
  real_T c1_n;
  real_T c1_b_n;
  real_T c1_a;
  real_T c1_d_b;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  boolean_T c1_e_b;
  boolean_T c1_b2;
  real_T c1_n_x;
  boolean_T c1_f_b;
  boolean_T c1_b3;
  boolean_T c1_g_b;
  real_T c1_o_x;
  real_T c1_c_n;
  real_T c1_d_n;
  real_T c1_b_a;
  real_T c1_h_b;
  int32_T c1_i8;
  real_T c1_i_b;
  int32_T c1_i9;
  int32_T c1_i10;
  real_T c1_c_a[2];
  real_T c1_j_b;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T *c1_b_v0;
  real_T *c1_b_thetaDegree;
  real_T (*c1_b_v0welt)[2];
  real_T (*c1_b_x0)[2];
  c1_b_x0 = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_thetaDegree = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_v0welt = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_v0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_v0;
  c1_b_hoistedGlobal = *c1_b_thetaDegree;
  c1_v0 = c1_hoistedGlobal;
  c1_thetaDegree = c1_b_hoistedGlobal;
  for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
    c1_x0[c1_i4] = (*c1_b_x0)[c1_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_nE, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_tE, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_vt, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_vn, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_v0, 6U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_thetaDegree, 7U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_x0, 8U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_v0welt, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    c1_x[c1_i5] = c1_x0[c1_i5];
  }

  c1_y = 0.0;
  c1_scale = 2.2250738585072014E-308;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_k = 1; c1_k < 3; c1_k++) {
    c1_b_k = c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_k), 1, 2, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_absxk = muDoubleScalarAbs(c1_c_x);
    if (c1_absxk > c1_scale) {
      c1_t = c1_scale / c1_absxk;
      c1_y = 1.0 + c1_y * c1_t * c1_t;
      c1_scale = c1_absxk;
    } else {
      c1_t = c1_absxk / c1_scale;
      c1_y += c1_t * c1_t;
    }
  }

  c1_y = c1_scale * muDoubleScalarSqrt(c1_y);
  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    c1_x[c1_i6] = c1_x0[c1_i6];
  }

  c1_B = c1_y;
  c1_b_y = c1_B;
  c1_c_y = c1_b_y;
  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    c1_nE[c1_i7] = c1_x[c1_i7] / c1_c_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_tE[0] = c1_nE[1];
  c1_tE[1] = -c1_nE[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_d_x = c1_thetaDegree;
  c1_e_x = c1_d_x;
  c1_f_x = c1_e_x;
  c1_g_x = c1_f_x;
  c1_b = muDoubleScalarIsInf(c1_g_x);
  c1_b0 = !c1_b;
  c1_h_x = c1_f_x;
  c1_b_b = muDoubleScalarIsNaN(c1_h_x);
  c1_b1 = !c1_b_b;
  c1_c_b = (c1_b0 && c1_b1);
  if (!c1_c_b) {
    c1_e_x = rtNaN;
  } else {
    c1_eml_scalar_rem90(chartInstance, c1_e_x, &c1_n, &c1_i_x);
    c1_b_n = c1_n;
    c1_e_x = c1_i_x;
    if (c1_b_n == 0.0) {
      c1_e_x = muDoubleScalarCos(c1_e_x);
    } else if (c1_b_n == 1.0) {
      c1_e_x = -muDoubleScalarSin(c1_e_x);
    } else if (c1_b_n == -1.0) {
      c1_e_x = muDoubleScalarSin(c1_e_x);
    } else {
      c1_e_x = -muDoubleScalarCos(c1_e_x);
    }
  }

  c1_a = c1_e_x;
  c1_d_b = c1_v0;
  c1_vt = c1_a * c1_d_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_j_x = c1_thetaDegree;
  c1_k_x = c1_j_x;
  c1_l_x = c1_k_x;
  c1_m_x = c1_l_x;
  c1_e_b = muDoubleScalarIsInf(c1_m_x);
  c1_b2 = !c1_e_b;
  c1_n_x = c1_l_x;
  c1_f_b = muDoubleScalarIsNaN(c1_n_x);
  c1_b3 = !c1_f_b;
  c1_g_b = (c1_b2 && c1_b3);
  if (!c1_g_b) {
    c1_k_x = rtNaN;
  } else {
    c1_eml_scalar_rem90(chartInstance, c1_k_x, &c1_c_n, &c1_o_x);
    c1_d_n = c1_c_n;
    c1_k_x = c1_o_x;
    if (c1_d_n == 0.0) {
      c1_k_x = muDoubleScalarSin(c1_k_x);
    } else if (c1_d_n == 1.0) {
      c1_k_x = muDoubleScalarCos(c1_k_x);
    } else if (c1_d_n == -1.0) {
      c1_k_x = -muDoubleScalarCos(c1_k_x);
    } else {
      c1_k_x = -muDoubleScalarSin(c1_k_x);
    }
  }

  c1_b_a = c1_k_x;
  c1_h_b = c1_v0;
  c1_vn = c1_b_a * c1_h_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
    c1_x[c1_i8] = c1_tE[c1_i8];
  }

  c1_i_b = c1_vt;
  for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
    c1_x[c1_i9] *= c1_i_b;
  }

  for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
    c1_c_a[c1_i10] = c1_nE[c1_i10];
  }

  c1_j_b = c1_vn;
  for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
    c1_c_a[c1_i11] *= c1_j_b;
  }

  for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
    c1_v0welt[c1_i12] = c1_x[c1_i12] + c1_c_a[c1_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -14);
  sf_debug_symbol_scope_pop();
  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    (*c1_b_v0welt)[c1_i13] = c1_v0welt[c1_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_Erdorbits(SFc1_ErdorbitsInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i14;
  real_T c1_b_inData[2];
  int32_T c1_i15;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
    c1_b_inData[c1_i14] = (*(real_T (*)[2])c1_inData)[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
    c1_u[c1_i15] = c1_b_inData[c1_i15];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_v0welt, const char_T *c1_identifier, real_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_v0welt), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_v0welt);
}

static void c1_b_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv1[2];
  int32_T c1_i16;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
    c1_y[c1_i16] = c1_dv1[c1_i16];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_v0welt;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i17;
  SFc1_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c1_v0welt = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_v0welt), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_v0welt);
  for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
    (*(real_T (*)[2])c1_outData)[c1_i17] = c1_y[c1_i17];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Erdorbits_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[39];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i18;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 39), FALSE);
  for (c1_i18 = 0; c1_i18 < 39; c1_i18++) {
    c1_r0 = &c1_info[c1_i18];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i18);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[39])
{
  c1_info[0].context = "";
  c1_info[0].name = "norm";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[0].fileTimeLo = 1286818826U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c1_info[1].name = "eml_index_class";
  c1_info[1].dominantType = "";
  c1_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[1].fileTimeLo = 1286818778U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c1_info[2].name = "eml_xnrm2";
  c1_info[2].dominantType = "int32";
  c1_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[2].fileTimeLo = 1299076776U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[3].name = "eml_blas_inline";
  c1_info[3].dominantType = "";
  c1_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[3].fileTimeLo = 1299076768U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[4].name = "eml_refblas_xnrm2";
  c1_info[4].dominantType = "int32";
  c1_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[4].fileTimeLo = 1299076784U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[5].name = "realmin";
  c1_info[5].dominantType = "char";
  c1_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[5].fileTimeLo = 1307651242U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[6].name = "eml_realmin";
  c1_info[6].dominantType = "char";
  c1_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[6].fileTimeLo = 1307651244U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[7].name = "eml_float_model";
  c1_info[7].dominantType = "char";
  c1_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[7].fileTimeLo = 1307651242U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[8].name = "eml_index_class";
  c1_info[8].dominantType = "";
  c1_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[8].fileTimeLo = 1286818778U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[9].name = "eml_index_minus";
  c1_info[9].dominantType = "int32";
  c1_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[9].fileTimeLo = 1286818778U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[10].name = "eml_index_class";
  c1_info[10].dominantType = "";
  c1_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[10].fileTimeLo = 1286818778U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[11].name = "eml_index_times";
  c1_info[11].dominantType = "int32";
  c1_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[11].fileTimeLo = 1286818780U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[12].name = "eml_index_class";
  c1_info[12].dominantType = "";
  c1_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[12].fileTimeLo = 1286818778U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[13].name = "eml_index_plus";
  c1_info[13].dominantType = "int32";
  c1_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[13].fileTimeLo = 1286818778U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[14].name = "eml_index_class";
  c1_info[14].dominantType = "";
  c1_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[14].fileTimeLo = 1286818778U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[15].name = "eml_int_forloop_overflow_check";
  c1_info[15].dominantType = "";
  c1_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[15].fileTimeLo = 1311255316U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[16].name = "intmax";
  c1_info[16].dominantType = "char";
  c1_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[16].fileTimeLo = 1311255316U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[17].name = "abs";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[17].fileTimeLo = 1286818694U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[18].name = "eml_scalar_abs";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[18].fileTimeLo = 1286818712U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context = "";
  c1_info[19].name = "mrdivide";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[19].fileTimeLo = 1325124138U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 1319729966U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[20].name = "rdivide";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[20].fileTimeLo = 1286818844U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[21].name = "eml_div";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[21].fileTimeLo = 1313347810U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context = "";
  c1_info[22].name = "cosd";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cosd.m";
  c1_info[22].fileTimeLo = 1286818706U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cosd.m";
  c1_info[23].name = "eml_scalar_cosd";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c1_info[23].fileTimeLo = 1320889436U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c1_info[24].name = "isfinite";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[24].fileTimeLo = 1286818758U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[25].name = "isinf";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[25].fileTimeLo = 1286818760U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[26].name = "isnan";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[26].fileTimeLo = 1286818760U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c1_info[27].name = "eml_scalar_rem90";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c1_info[27].fileTimeLo = 1320889436U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c1_info[28].name = "rem";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[28].fileTimeLo = 1286818748U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[29].name = "eml_scalar_eg";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[29].fileTimeLo = 1286818796U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[30].name = "eml_scalexp_alloc";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[30].fileTimeLo = 1286818796U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/rem.m";
  c1_info[31].name = "eml_scalar_rem";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  c1_info[31].fileTimeLo = 1286818732U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c1_info[32].name = "abs";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[32].fileTimeLo = 1286818694U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c1_info[33].name = "mtimes";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[33].fileTimeLo = 1289519692U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context = "";
  c1_info[34].name = "mtimes";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[34].fileTimeLo = 1289519692U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context = "";
  c1_info[35].name = "sind";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sind.m";
  c1_info[35].fileTimeLo = 1286818750U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sind.m";
  c1_info[36].name = "eml_scalar_sind";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sind.m";
  c1_info[36].fileTimeLo = 1320889436U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sind.m";
  c1_info[37].name = "isfinite";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[37].fileTimeLo = 1286818758U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sind.m";
  c1_info[38].name = "eml_scalar_rem90";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c1_info[38].fileTimeLo = 1320889436U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
}

static void c1_eml_int_forloop_overflow_check(SFc1_ErdorbitsInstanceStruct
  *chartInstance)
{
}

static void c1_eml_scalar_rem90(SFc1_ErdorbitsInstanceStruct *chartInstance,
  real_T c1_x, real_T *c1_n, real_T *c1_y)
{
  real_T c1_b_x;
  real_T c1_xk;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_ix;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_b;
  real_T c1_b_b;
  real_T c1_c_b;
  real_T c1_d_b;
  real_T c1_e_b;
  c1_b_x = c1_x;
  c1_xk = c1_b_x;
  c1_c_x = c1_xk;
  c1_x = muDoubleScalarRem(c1_c_x, 360.0);
  c1_d_x = c1_x;
  c1_e_x = c1_d_x;
  c1_ix = muDoubleScalarAbs(c1_e_x);
  if (c1_ix > 180.0) {
    if (c1_x > 0.0) {
      c1_x -= 360.0;
    } else {
      c1_x += 360.0;
    }

    c1_f_x = c1_x;
    c1_g_x = c1_f_x;
    c1_ix = muDoubleScalarAbs(c1_g_x);
  }

  if (c1_ix <= 45.0) {
    c1_b = c1_x;
    *c1_y = 0.017453292519943295 * c1_b;
    *c1_n = 0.0;
  } else if (c1_ix <= 135.0) {
    if (c1_x > 0.0) {
      c1_b_b = c1_x - 90.0;
      *c1_y = 0.017453292519943295 * c1_b_b;
      *c1_n = 1.0;
    } else {
      c1_c_b = c1_x + 90.0;
      *c1_y = 0.017453292519943295 * c1_c_b;
      *c1_n = -1.0;
    }
  } else if (c1_x > 0.0) {
    c1_d_b = c1_x - 180.0;
    *c1_y = 0.017453292519943295 * c1_d_b;
    *c1_n = 2.0;
  } else {
    c1_e_b = c1_x + 180.0;
    *c1_y = 0.017453292519943295 * c1_e_b;
    *c1_n = -2.0;
  }
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i19;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i19, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i19;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_Erdorbits, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Erdorbits), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Erdorbits);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_ErdorbitsInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_Erdorbits_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(89893697U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1398076717U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3907652297U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(889668683U);
}

mxArray *sf_c1_Erdorbits_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zTRjeZlI6lDk5CPplQh8nE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_Erdorbits(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"v0welt\",},{M[8],M[0],T\"is_active_c1_Erdorbits\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Erdorbits_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ErdorbitsInstanceStruct *chartInstance;
    chartInstance = (SFc1_ErdorbitsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ErdorbitsMachineNumber_,
          1,
          1,
          1,
          4,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_ErdorbitsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_ErdorbitsMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ErdorbitsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"v0");
          _SFD_SET_DATA_PROPS(1,2,0,1,"v0welt");
          _SFD_SET_DATA_PROPS(2,1,1,0,"thetaDegree");
          _SFD_SET_DATA_PROPS(3,1,1,0,"x0");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,424);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c1_v0;
          real_T *c1_thetaDegree;
          real_T (*c1_v0welt)[2];
          real_T (*c1_x0)[2];
          c1_x0 = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
          c1_thetaDegree = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_v0welt = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_v0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_v0);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_v0welt);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_thetaDegree);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_x0);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ErdorbitsMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "wy1W0FvyYrv1T5AdayiUl";
}

static void sf_opaque_initialize_c1_Erdorbits(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_ErdorbitsInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_Erdorbits((SFc1_ErdorbitsInstanceStruct*)
    chartInstanceVar);
  initialize_c1_Erdorbits((SFc1_ErdorbitsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Erdorbits(void *chartInstanceVar)
{
  enable_c1_Erdorbits((SFc1_ErdorbitsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Erdorbits(void *chartInstanceVar)
{
  disable_c1_Erdorbits((SFc1_ErdorbitsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Erdorbits(void *chartInstanceVar)
{
  sf_c1_Erdorbits((SFc1_ErdorbitsInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_Erdorbits(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Erdorbits((SFc1_ErdorbitsInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Erdorbits();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_Erdorbits(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Erdorbits();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Erdorbits((SFc1_ErdorbitsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_Erdorbits(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Erdorbits(S);
}

static void sf_opaque_set_sim_state_c1_Erdorbits(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_Erdorbits(S, st);
}

static void sf_opaque_terminate_c1_Erdorbits(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ErdorbitsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_Erdorbits((SFc1_ErdorbitsInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Erdorbits_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Erdorbits((SFc1_ErdorbitsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Erdorbits(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Erdorbits((SFc1_ErdorbitsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Erdorbits(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Erdorbits_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3748517253U));
  ssSetChecksum1(S,(321573768U));
  ssSetChecksum2(S,(1076853173U));
  ssSetChecksum3(S,(3951814434U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_Erdorbits(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Erdorbits(SimStruct *S)
{
  SFc1_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ErdorbitsInstanceStruct *)malloc(sizeof
    (SFc1_ErdorbitsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ErdorbitsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_Erdorbits;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_Erdorbits;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_Erdorbits;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Erdorbits;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Erdorbits;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_Erdorbits;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_Erdorbits;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_Erdorbits;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Erdorbits;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Erdorbits;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Erdorbits;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_Erdorbits_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Erdorbits(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Erdorbits(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Erdorbits(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Erdorbits_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
