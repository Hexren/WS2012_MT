/* Include files */

#include "blascompat32.h"
#include "ErdMond_sfun.h"
#include "c2_ErdMond.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ErdMond_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[7] = { "r", "h", "nargin", "nargout",
  "deltaDegree", "h0", "x0" };

/* Function Declarations */
static void initialize_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance);
static void initialize_params_c2_ErdMond(SFc2_ErdMondInstanceStruct
  *chartInstance);
static void enable_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance);
static void disable_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_ErdMond(SFc2_ErdMondInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_ErdMond(SFc2_ErdMondInstanceStruct
  *chartInstance);
static void set_sim_state_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance);
static void sf_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance);
static void initSimStructsc2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance, const
  mxArray *c2_x0, const char_T *c2_identifier, real_T c2_y[2]);
static void c2_b_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18]);
static void c2_eml_scalar_rem90(SFc2_ErdMondInstanceStruct *chartInstance,
  real_T c2_x, real_T *c2_n, real_T *c2_y);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ErdMond, const char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_ErdMondInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_ErdMond = 0U;
}

static void initialize_params_c2_ErdMond(SFc2_ErdMondInstanceStruct
  *chartInstance)
{
}

static void enable_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_ErdMond(SFc2_ErdMondInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_ErdMond(SFc2_ErdMondInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[2];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_x0)[2];
  c2_x0 = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    c2_u[c2_i0] = (*c2_x0)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_ErdMond;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[2];
  int32_T c2_i1;
  real_T (*c2_x0)[2];
  c2_x0 = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "x0",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    (*c2_x0)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_ErdMond = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_ErdMond");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_ErdMond(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance)
{
}

static void sf_c2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_deltaDegree;
  real_T c2_h0;
  uint32_T c2_debug_family_var_map[7];
  real_T c2_r;
  real_T c2_h;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  real_T c2_x0[2];
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  boolean_T c2_b;
  boolean_T c2_b0;
  real_T c2_e_x;
  boolean_T c2_b_b;
  boolean_T c2_b1;
  boolean_T c2_c_b;
  real_T c2_f_x;
  real_T c2_n;
  real_T c2_b_n;
  real_T c2_a;
  real_T c2_d_b;
  real_T c2_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  boolean_T c2_e_b;
  boolean_T c2_b2;
  real_T c2_k_x;
  boolean_T c2_f_b;
  boolean_T c2_b3;
  boolean_T c2_g_b;
  real_T c2_l_x;
  real_T c2_c_n;
  real_T c2_d_n;
  real_T c2_b_a;
  real_T c2_h_b;
  real_T c2_b_y;
  int32_T c2_i3;
  real_T *c2_b_deltaDegree;
  real_T *c2_b_h0;
  real_T (*c2_b_x0)[2];
  c2_b_h0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_x0 = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_deltaDegree = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_deltaDegree, 0U);
  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_x0)[c2_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_h0, 2U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_deltaDegree;
  c2_b_hoistedGlobal = *c2_b_h0;
  c2_deltaDegree = c2_hoistedGlobal;
  c2_h0 = c2_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_r, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_h, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_deltaDegree, 4U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_h0, 5U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_x0, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_r = 6.378E+6;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_h = c2_r + c2_h0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_x = c2_deltaDegree;
  c2_b_x = c2_x;
  c2_c_x = c2_b_x;
  c2_d_x = c2_c_x;
  c2_b = muDoubleScalarIsInf(c2_d_x);
  c2_b0 = !c2_b;
  c2_e_x = c2_c_x;
  c2_b_b = muDoubleScalarIsNaN(c2_e_x);
  c2_b1 = !c2_b_b;
  c2_c_b = (c2_b0 && c2_b1);
  if (!c2_c_b) {
    c2_b_x = rtNaN;
  } else {
    c2_eml_scalar_rem90(chartInstance, c2_b_x, &c2_n, &c2_f_x);
    c2_b_n = c2_n;
    c2_b_x = c2_f_x;
    if (c2_b_n == 0.0) {
      c2_b_x = muDoubleScalarCos(c2_b_x);
    } else if (c2_b_n == 1.0) {
      c2_b_x = -muDoubleScalarSin(c2_b_x);
    } else if (c2_b_n == -1.0) {
      c2_b_x = muDoubleScalarSin(c2_b_x);
    } else {
      c2_b_x = -muDoubleScalarCos(c2_b_x);
    }
  }

  c2_a = c2_b_x;
  c2_d_b = c2_h;
  c2_y = c2_a * c2_d_b;
  c2_g_x = c2_deltaDegree;
  c2_h_x = c2_g_x;
  c2_i_x = c2_h_x;
  c2_j_x = c2_i_x;
  c2_e_b = muDoubleScalarIsInf(c2_j_x);
  c2_b2 = !c2_e_b;
  c2_k_x = c2_i_x;
  c2_f_b = muDoubleScalarIsNaN(c2_k_x);
  c2_b3 = !c2_f_b;
  c2_g_b = (c2_b2 && c2_b3);
  if (!c2_g_b) {
    c2_h_x = rtNaN;
  } else {
    c2_eml_scalar_rem90(chartInstance, c2_h_x, &c2_c_n, &c2_l_x);
    c2_d_n = c2_c_n;
    c2_h_x = c2_l_x;
    if (c2_d_n == 0.0) {
      c2_h_x = muDoubleScalarSin(c2_h_x);
    } else if (c2_d_n == 1.0) {
      c2_h_x = muDoubleScalarCos(c2_h_x);
    } else if (c2_d_n == -1.0) {
      c2_h_x = -muDoubleScalarCos(c2_h_x);
    } else {
      c2_h_x = -muDoubleScalarSin(c2_h_x);
    }
  }

  c2_b_a = c2_h_x;
  c2_h_b = c2_h;
  c2_b_y = c2_b_a * c2_h_b;
  c2_x0[0] = c2_y;
  c2_x0[1] = c2_b_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    (*c2_b_x0)[c2_i3] = c2_x0[c2_i3];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_ErdMondMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_ErdMond(SFc2_ErdMondInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i4;
  real_T c2_b_inData[2];
  int32_T c2_i5;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_ErdMondInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErdMondInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
    c2_b_inData[c2_i4] = (*(real_T (*)[2])c2_inData)[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    c2_u[c2_i5] = c2_b_inData[c2_i5];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance, const
  mxArray *c2_x0, const char_T *c2_identifier, real_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_x0), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_x0);
}

static void c2_b_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2])
{
  real_T c2_dv1[2];
  int32_T c2_i6;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
    c2_y[c2_i6] = c2_dv1[c2_i6];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_x0;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i7;
  SFc2_ErdMondInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErdMondInstanceStruct *)chartInstanceVoid;
  c2_x0 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_x0), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_x0);
  for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
    (*(real_T (*)[2])c2_outData)[c2_i7] = c2_y[c2_i7];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ErdMondInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErdMondInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_ErdMondInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErdMondInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_ErdMond_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[18];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i8;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18), FALSE);
  for (c2_i8 = 0; c2_i8 < 18; c2_i8++) {
    c2_r0 = &c2_info[c2_i8];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i8);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18])
{
  c2_info[0].context = "";
  c2_info[0].name = "cosd";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cosd.m";
  c2_info[0].fileTimeLo = 1286818706U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cosd.m";
  c2_info[1].name = "eml_scalar_cosd";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c2_info[1].fileTimeLo = 1320889436U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c2_info[2].name = "isfinite";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[2].fileTimeLo = 1286818758U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[3].name = "isinf";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[3].fileTimeLo = 1286818760U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[4].name = "isnan";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[4].fileTimeLo = 1286818760U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c2_info[5].name = "eml_scalar_rem90";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c2_info[5].fileTimeLo = 1320889436U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c2_info[6].name = "rem";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[6].fileTimeLo = 1286818748U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[7].name = "eml_scalar_eg";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[7].fileTimeLo = 1286818796U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[8].name = "eml_scalexp_alloc";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[8].fileTimeLo = 1286818796U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[9].name = "eml_scalar_rem";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  c2_info[9].fileTimeLo = 1286818732U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c2_info[10].name = "abs";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[10].fileTimeLo = 1286818694U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[11].name = "eml_scalar_abs";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[11].fileTimeLo = 1286818712U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c2_info[12].name = "mtimes";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].fileTimeLo = 1289519692U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "mtimes";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].fileTimeLo = 1289519692U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "sind";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sind.m";
  c2_info[14].fileTimeLo = 1286818750U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sind.m";
  c2_info[15].name = "eml_scalar_sind";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sind.m";
  c2_info[15].fileTimeLo = 1320889436U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sind.m";
  c2_info[16].name = "isfinite";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[16].fileTimeLo = 1286818758U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sind.m";
  c2_info[17].name = "eml_scalar_rem90";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m";
  c2_info[17].fileTimeLo = 1320889436U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
}

static void c2_eml_scalar_rem90(SFc2_ErdMondInstanceStruct *chartInstance,
  real_T c2_x, real_T *c2_n, real_T *c2_y)
{
  real_T c2_b_x;
  real_T c2_xk;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_ix;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_b;
  real_T c2_b_b;
  real_T c2_c_b;
  real_T c2_d_b;
  real_T c2_e_b;
  c2_b_x = c2_x;
  c2_xk = c2_b_x;
  c2_c_x = c2_xk;
  c2_x = muDoubleScalarRem(c2_c_x, 360.0);
  c2_d_x = c2_x;
  c2_e_x = c2_d_x;
  c2_ix = muDoubleScalarAbs(c2_e_x);
  if (c2_ix > 180.0) {
    if (c2_x > 0.0) {
      c2_x -= 360.0;
    } else {
      c2_x += 360.0;
    }

    c2_f_x = c2_x;
    c2_g_x = c2_f_x;
    c2_ix = muDoubleScalarAbs(c2_g_x);
  }

  if (c2_ix <= 45.0) {
    c2_b = c2_x;
    *c2_y = 0.017453292519943295 * c2_b;
    *c2_n = 0.0;
  } else if (c2_ix <= 135.0) {
    if (c2_x > 0.0) {
      c2_b_b = c2_x - 90.0;
      *c2_y = 0.017453292519943295 * c2_b_b;
      *c2_n = 1.0;
    } else {
      c2_c_b = c2_x + 90.0;
      *c2_y = 0.017453292519943295 * c2_c_b;
      *c2_n = -1.0;
    }
  } else if (c2_x > 0.0) {
    c2_d_b = c2_x - 180.0;
    *c2_y = 0.017453292519943295 * c2_d_b;
    *c2_n = 2.0;
  } else {
    c2_e_b = c2_x + 180.0;
    *c2_y = 0.017453292519943295 * c2_e_b;
    *c2_n = -2.0;
  }
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ErdMondInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErdMondInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i9;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i9, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i9;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_ErdMondInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErdMondInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ErdMond, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_ErdMond), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_ErdMond);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_ErdMondInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_ErdMondInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_ErdMond_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2244097622U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2011113658U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1848299274U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(389463087U);
}

mxArray *sf_c2_ErdMond_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kMYYNTXdlBYz1yJGNps0AE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c2_ErdMond(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"x0\",},{M[8],M[0],T\"is_active_c2_ErdMond\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ErdMond_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ErdMondInstanceStruct *chartInstance;
    chartInstance = (SFc2_ErdMondInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ErdMondMachineNumber_,
          2,
          1,
          1,
          3,
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
          init_script_number_translation(_ErdMondMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_ErdMondMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ErdMondMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"deltaDegree");
          _SFD_SET_DATA_PROPS(1,2,0,1,"x0");
          _SFD_SET_DATA_PROPS(2,1,1,0,"h0");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,170);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_deltaDegree;
          real_T *c2_h0;
          real_T (*c2_x0)[2];
          c2_h0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_x0 = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_deltaDegree = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_deltaDegree);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_x0);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_h0);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ErdMondMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "jLKX77vcKkHRZ29yRZtaSH";
}

static void sf_opaque_initialize_c2_ErdMond(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_ErdMondInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c2_ErdMond((SFc2_ErdMondInstanceStruct*) chartInstanceVar);
  initialize_c2_ErdMond((SFc2_ErdMondInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_ErdMond(void *chartInstanceVar)
{
  enable_c2_ErdMond((SFc2_ErdMondInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_ErdMond(void *chartInstanceVar)
{
  disable_c2_ErdMond((SFc2_ErdMondInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_ErdMond(void *chartInstanceVar)
{
  sf_c2_ErdMond((SFc2_ErdMondInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_ErdMond(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_ErdMond((SFc2_ErdMondInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_ErdMond();/* state var info */
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

extern void sf_internal_set_sim_state_c2_ErdMond(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_ErdMond();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_ErdMond((SFc2_ErdMondInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_ErdMond(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_ErdMond(S);
}

static void sf_opaque_set_sim_state_c2_ErdMond(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_ErdMond(S, st);
}

static void sf_opaque_terminate_c2_ErdMond(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_ErdMondInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_ErdMond((SFc2_ErdMondInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_ErdMond_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_ErdMond((SFc2_ErdMondInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ErdMond(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ErdMond((SFc2_ErdMondInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_ErdMond(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ErdMond_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(943532550U));
  ssSetChecksum1(S,(19410659U));
  ssSetChecksum2(S,(4057738140U));
  ssSetChecksum3(S,(1373044293U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_ErdMond(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_ErdMond(SimStruct *S)
{
  SFc2_ErdMondInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErdMondInstanceStruct *)malloc(sizeof
    (SFc2_ErdMondInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_ErdMondInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_ErdMond;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_ErdMond;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_ErdMond;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_ErdMond;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_ErdMond;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_ErdMond;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_ErdMond;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_ErdMond;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_ErdMond;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_ErdMond;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_ErdMond;
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

void c2_ErdMond_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_ErdMond(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ErdMond(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ErdMond(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ErdMond_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
