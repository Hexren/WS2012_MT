/* Include files */

#include "blascompat32.h"
#include "Erdorbits_sfun.h"
#include "c3_Erdorbits.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Erdorbits_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[9] = { "xE", "eSE", "r", "mE", "G",
  "nargin", "nargout", "xAktuell", "a" };

/* Function Declarations */
static void initialize_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance);
static void initialize_params_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance);
static void enable_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance);
static void disable_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance);
static void set_sim_state_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance);
static void sf_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance);
static void initSimStructsc3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_a, const char_T *c3_identifier, real_T c3_y[2]);
static void c3_b_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[28]);
static real_T c3_norm(SFc3_ErdorbitsInstanceStruct *chartInstance, real_T c3_x[2]);
static void c3_eml_int_forloop_overflow_check(SFc3_ErdorbitsInstanceStruct
  *chartInstance);
static void c3_eml_scalar_eg(SFc3_ErdorbitsInstanceStruct *chartInstance);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_Erdorbits, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_ErdorbitsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_Erdorbits = 0U;
}

static void initialize_params_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance)
{
}

static void enable_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[2];
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T (*c3_a)[2];
  c3_a = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    c3_u[c3_i0] = (*c3_a)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_Erdorbits;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[2];
  int32_T c3_i1;
  real_T (*c3_a)[2];
  c3_a = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "a",
                      c3_dv0);
  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    (*c3_a)[c3_i1] = c3_dv0[c3_i1];
  }

  chartInstance->c3_is_active_c3_Erdorbits = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "is_active_c3_Erdorbits");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Erdorbits(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance)
{
}

static void sf_c3_Erdorbits(SFc3_ErdorbitsInstanceStruct *chartInstance)
{
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  real_T c3_xAktuell[2];
  uint32_T c3_debug_family_var_map[9];
  real_T c3_xE[2];
  real_T c3_eSE[2];
  real_T c3_r;
  real_T c3_mE;
  real_T c3_G;
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  real_T c3_a[2];
  int32_T c3_i5;
  real_T c3_A[2];
  int32_T c3_i6;
  real_T c3_b_xAktuell[2];
  real_T c3_B;
  real_T c3_y;
  real_T c3_b_y;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  real_T c3_c_xAktuell[2];
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_c;
  real_T c3_b_B;
  real_T c3_c_y;
  real_T c3_d_y;
  real_T c3_e_y;
  real_T c3_d_a;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  real_T (*c3_e_a)[2];
  real_T (*c3_d_xAktuell)[2];
  c3_e_a = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_d_xAktuell = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_d_xAktuell)[c3_i2], 0U);
  }

  for (c3_i3 = 0; c3_i3 < 2; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_e_a)[c3_i3], 1U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
    c3_xAktuell[c3_i4] = (*c3_d_xAktuell)[c3_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c3_xE, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_eSE, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_r, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_mE, 3U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_G, 4U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 5U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 6U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_xAktuell, 7U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_a, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    c3_A[c3_i5] = c3_xAktuell[c3_i5];
  }

  for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
    c3_b_xAktuell[c3_i6] = c3_xAktuell[c3_i6];
  }

  c3_B = c3_norm(chartInstance, c3_b_xAktuell);
  c3_y = c3_B;
  c3_b_y = c3_y;
  for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
    c3_xE[c3_i7] = c3_A[c3_i7] / c3_b_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
    c3_A[c3_i8] = c3_xE[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
    c3_eSE[c3_i9] = -c3_A[c3_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  for (c3_i10 = 0; c3_i10 < 2; c3_i10++) {
    c3_c_xAktuell[c3_i10] = c3_xAktuell[c3_i10];
  }

  c3_r = c3_norm(chartInstance, c3_c_xAktuell);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_mE = 5.9736000000000006E+24;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_G = 6.6743E-11;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_b_a = c3_r;
  c3_c_a = c3_b_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_c = muDoubleScalarPower(c3_ak, 2.0);
  c3_b_B = c3_c;
  c3_c_y = c3_b_B;
  c3_d_y = c3_c_y;
  c3_e_y = 3.986959848E+14 / c3_d_y;
  c3_d_a = c3_e_y;
  for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
    c3_A[c3_i11] = c3_eSE[c3_i11];
  }

  for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
    c3_a[c3_i12] = c3_d_a * c3_A[c3_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -12);
  sf_debug_symbol_scope_pop();
  for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
    (*c3_e_a)[c3_i13] = c3_a[c3_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  sf_debug_check_for_state_inconsistency(_ErdorbitsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_Erdorbits(SFc3_ErdorbitsInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i14;
  real_T c3_b_inData[2];
  int32_T c3_i15;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc3_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
    c3_b_inData[c3_i14] = (*(real_T (*)[2])c3_inData)[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
    c3_u[c3_i15] = c3_b_inData[c3_i15];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_a, const char_T *c3_identifier, real_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_a), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_a);
}

static void c3_b_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2])
{
  real_T c3_dv1[2];
  int32_T c3_i16;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
    c3_y[c3_i16] = c3_dv1[c3_i16];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_a;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i17;
  SFc3_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc3_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c3_a = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_a), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_a);
  for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
    (*(real_T (*)[2])c3_outData)[c3_i17] = c3_y[c3_i17];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc3_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc3_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Erdorbits_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[28];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i18;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 28), FALSE);
  for (c3_i18 = 0; c3_i18 < 28; c3_i18++) {
    c3_r0 = &c3_info[c3_i18];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i18);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[28])
{
  c3_info[0].context = "";
  c3_info[0].name = "norm";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m";
  c3_info[0].fileTimeLo = 1286818826U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c3_info[1].name = "eml_index_class";
  c3_info[1].dominantType = "";
  c3_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[1].fileTimeLo = 1286818778U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c3_info[2].name = "eml_xnrm2";
  c3_info[2].dominantType = "int32";
  c3_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c3_info[2].fileTimeLo = 1299076776U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c3_info[3].name = "eml_blas_inline";
  c3_info[3].dominantType = "";
  c3_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[3].fileTimeLo = 1299076768U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c3_info[4].name = "eml_refblas_xnrm2";
  c3_info[4].dominantType = "int32";
  c3_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[4].fileTimeLo = 1299076784U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[5].name = "realmin";
  c3_info[5].dominantType = "char";
  c3_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c3_info[5].fileTimeLo = 1307651242U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c3_info[6].name = "eml_realmin";
  c3_info[6].dominantType = "char";
  c3_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c3_info[6].fileTimeLo = 1307651244U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c3_info[7].name = "eml_float_model";
  c3_info[7].dominantType = "char";
  c3_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c3_info[7].fileTimeLo = 1307651242U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[8].name = "eml_index_class";
  c3_info[8].dominantType = "";
  c3_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[8].fileTimeLo = 1286818778U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[9].name = "eml_index_minus";
  c3_info[9].dominantType = "int32";
  c3_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[9].fileTimeLo = 1286818778U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[10].name = "eml_index_class";
  c3_info[10].dominantType = "";
  c3_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[10].fileTimeLo = 1286818778U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[11].name = "eml_index_times";
  c3_info[11].dominantType = "int32";
  c3_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[11].fileTimeLo = 1286818780U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[12].name = "eml_index_class";
  c3_info[12].dominantType = "";
  c3_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[12].fileTimeLo = 1286818778U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[13].name = "eml_index_plus";
  c3_info[13].dominantType = "int32";
  c3_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[13].fileTimeLo = 1286818778U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[14].name = "eml_index_class";
  c3_info[14].dominantType = "";
  c3_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[14].fileTimeLo = 1286818778U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[15].name = "eml_int_forloop_overflow_check";
  c3_info[15].dominantType = "";
  c3_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[15].fileTimeLo = 1311255316U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c3_info[16].name = "intmax";
  c3_info[16].dominantType = "char";
  c3_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[16].fileTimeLo = 1311255316U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[17].name = "abs";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[17].fileTimeLo = 1286818694U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[18].name = "eml_scalar_abs";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[18].fileTimeLo = 1286818712U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context = "";
  c3_info[19].name = "mrdivide";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[19].fileTimeLo = 1325124138U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 1319729966U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[20].name = "rdivide";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[20].fileTimeLo = 1286818844U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[21].name = "eml_div";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[21].fileTimeLo = 1313347810U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context = "";
  c3_info[22].name = "mtimes";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[22].fileTimeLo = 1289519692U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context = "";
  c3_info[23].name = "mpower";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[23].fileTimeLo = 1286818842U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[24].name = "power";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[24].fileTimeLo = 1307651240U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[25].name = "eml_scalar_eg";
  c3_info[25].dominantType = "double";
  c3_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[25].fileTimeLo = 1286818796U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[26].name = "eml_scalexp_alloc";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[26].fileTimeLo = 1286818796U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[27].name = "eml_scalar_floor";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[27].fileTimeLo = 1286818726U;
  c3_info[27].fileTimeHi = 0U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
}

static real_T c3_norm(SFc3_ErdorbitsInstanceStruct *chartInstance, real_T c3_x[2])
{
  real_T c3_y;
  real_T c3_scale;
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_absxk;
  real_T c3_t;
  c3_y = 0.0;
  c3_scale = 2.2250738585072014E-308;
  c3_eml_int_forloop_overflow_check(chartInstance);
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_b_k = c3_k;
    c3_b_x = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c3_b_k), 1, 2, 1, 0) - 1];
    c3_c_x = c3_b_x;
    c3_absxk = muDoubleScalarAbs(c3_c_x);
    if (c3_absxk > c3_scale) {
      c3_t = c3_scale / c3_absxk;
      c3_y = 1.0 + c3_y * c3_t * c3_t;
      c3_scale = c3_absxk;
    } else {
      c3_t = c3_absxk / c3_scale;
      c3_y += c3_t * c3_t;
    }
  }

  return c3_scale * muDoubleScalarSqrt(c3_y);
}

static void c3_eml_int_forloop_overflow_check(SFc3_ErdorbitsInstanceStruct
  *chartInstance)
{
}

static void c3_eml_scalar_eg(SFc3_ErdorbitsInstanceStruct *chartInstance)
{
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc3_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i19;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i19, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i19;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc3_ErdorbitsInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_Erdorbits, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Erdorbits), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Erdorbits);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_ErdorbitsInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_ErdorbitsInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_Erdorbits_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3214900579U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3537672462U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2483620948U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1139940179U);
}

mxArray *sf_c3_Erdorbits_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Ys6vb4S7NQ9gnWLeAb0cIE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static const mxArray *sf_get_sim_state_info_c3_Erdorbits(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"a\",},{M[8],M[0],T\"is_active_c3_Erdorbits\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Erdorbits_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ErdorbitsInstanceStruct *chartInstance;
    chartInstance = (SFc3_ErdorbitsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ErdorbitsMachineNumber_,
          3,
          1,
          1,
          2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"xAktuell");
          _SFD_SET_DATA_PROPS(1,2,0,1,"a");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,391);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          real_T (*c3_xAktuell)[2];
          real_T (*c3_a)[2];
          c3_a = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_xAktuell = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_xAktuell);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_a);
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
  return "KJQ3J5q34MAl1hQiX02SwB";
}

static void sf_opaque_initialize_c3_Erdorbits(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ErdorbitsInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_Erdorbits((SFc3_ErdorbitsInstanceStruct*)
    chartInstanceVar);
  initialize_c3_Erdorbits((SFc3_ErdorbitsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Erdorbits(void *chartInstanceVar)
{
  enable_c3_Erdorbits((SFc3_ErdorbitsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Erdorbits(void *chartInstanceVar)
{
  disable_c3_Erdorbits((SFc3_ErdorbitsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Erdorbits(void *chartInstanceVar)
{
  sf_c3_Erdorbits((SFc3_ErdorbitsInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_Erdorbits(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_Erdorbits((SFc3_ErdorbitsInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Erdorbits();/* state var info */
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

extern void sf_internal_set_sim_state_c3_Erdorbits(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Erdorbits();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_Erdorbits((SFc3_ErdorbitsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_Erdorbits(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_Erdorbits(S);
}

static void sf_opaque_set_sim_state_c3_Erdorbits(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_Erdorbits(S, st);
}

static void sf_opaque_terminate_c3_Erdorbits(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ErdorbitsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_Erdorbits((SFc3_ErdorbitsInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Erdorbits_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Erdorbits((SFc3_ErdorbitsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Erdorbits(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Erdorbits((SFc3_ErdorbitsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Erdorbits(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Erdorbits_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4172722119U));
  ssSetChecksum1(S,(3485722352U));
  ssSetChecksum2(S,(1151666993U));
  ssSetChecksum3(S,(1332589546U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_Erdorbits(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Erdorbits(SimStruct *S)
{
  SFc3_ErdorbitsInstanceStruct *chartInstance;
  chartInstance = (SFc3_ErdorbitsInstanceStruct *)malloc(sizeof
    (SFc3_ErdorbitsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_ErdorbitsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Erdorbits;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_Erdorbits;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Erdorbits;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Erdorbits;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Erdorbits;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Erdorbits;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Erdorbits;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_Erdorbits;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Erdorbits;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Erdorbits;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Erdorbits;
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

void c3_Erdorbits_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Erdorbits(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Erdorbits(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Erdorbits(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Erdorbits_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
