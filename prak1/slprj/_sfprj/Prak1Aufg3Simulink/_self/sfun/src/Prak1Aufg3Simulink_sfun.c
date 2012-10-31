/* Include files */

#include "Prak1Aufg3Simulink_sfun.h"
#include "c1_Prak1Aufg3Simulink.h"
#include "c2_Prak1Aufg3Simulink.h"
#include "c3_Prak1Aufg3Simulink.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Prak1Aufg3SimulinkMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Prak1Aufg3Simulink_initializer(void)
{
}

void Prak1Aufg3Simulink_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Prak1Aufg3Simulink_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Prak1Aufg3Simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Prak1Aufg3Simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Prak1Aufg3Simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Prak1Aufg3Simulink_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(879460495U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3840479191U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(356170434U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3298206955U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3809510762U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3796846601U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2345048706U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3528455393U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Prak1Aufg3Simulink_get_check_sum(mxArray *plhs[]);
          sf_c1_Prak1Aufg3Simulink_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Prak1Aufg3Simulink_get_check_sum(mxArray *plhs[]);
          sf_c2_Prak1Aufg3Simulink_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Prak1Aufg3Simulink_get_check_sum(mxArray *plhs[]);
          sf_c3_Prak1Aufg3Simulink_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3691397736U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2228706418U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(148782436U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4073970181U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(259706605U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1416293510U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2862988690U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2690388353U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Prak1Aufg3Simulink_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_Prak1Aufg3Simulink_get_autoinheritance_info(void);
        plhs[0] = sf_c1_Prak1Aufg3Simulink_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_Prak1Aufg3Simulink_get_autoinheritance_info(void);
        plhs[0] = sf_c2_Prak1Aufg3Simulink_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_Prak1Aufg3Simulink_get_autoinheritance_info(void);
        plhs[0] = sf_c3_Prak1Aufg3Simulink_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Prak1Aufg3Simulink_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_Prak1Aufg3Simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Prak1Aufg3Simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Prak1Aufg3Simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Prak1Aufg3Simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Prak1Aufg3Simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Prak1Aufg3Simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void Prak1Aufg3Simulink_debug_initialize(void)
{
  _Prak1Aufg3SimulinkMachineNumber_ = sf_debug_initialize_machine(
    "Prak1Aufg3Simulink","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(_Prak1Aufg3SimulinkMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_Prak1Aufg3SimulinkMachineNumber_,0);
}

void Prak1Aufg3Simulink_register_exported_symbols(SimStruct* S)
{
}