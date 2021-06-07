/*
 * MODEL-BASED SOFTWARE DESIGN
 * LABORATORY 2 SOLUTION - A.Y. 2020/21
 * 
 * (C) 2021 JACOPO SINI, MASSIMO VIOLANTE - Politecnico di Torino 
 */ 

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.h
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Mar 18 12:35:10 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#ifndef controller_COMMON_INCLUDES_
# define controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* controller_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_controller_T RT_MODEL_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_controller;     /* '<Root>/Decision_Logic' */
  uint8_T is_Operations;               /* '<Root>/Decision_Logic' */
  uint8_T is_Moving;                   /* '<Root>/Decision_Logic' */
  uint8_T is_Monitoring;               /* '<Root>/Decision_Logic' */
  uint8_T temporalCounter_i1;          /* '<Root>/Decision_Logic' */
} DW_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T AxelLock_DI;               /* '<Root>/AxelLock_DI' */
  real32_T Pos_mm;                     /* '<Root>/Pos_mm' */
  real32_T Current_A;                  /* '<Root>/Current_A' */
  boolean_T Inserted_Pos_Switch_DI;    /* '<Root>/Inserted_Pos_Switch_DI' */
  boolean_T Extracted_Pos_Switch_DI;   /* '<Root>/Extracted_Pos_Switch_DI' */
} ExtU_controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Enable_DO;                 /* '<Root>/Enable_DO' */
  boolean_T Insert_DO;                 /* '<Root>/Insert_DO' */
  boolean_T Extract_DO;                /* '<Root>/Extract_DO' */
  boolean_T Error_DO;                  /* '<Root>/Error_DO' */
} ExtY_controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_controller_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_controller_T controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_controller_T controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_controller_T controller_Y;

/* Model entry point functions */
extern void controller_initialize(void);
extern void controller_step(void);
extern void controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_T *const controller_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller'
 * '<S1>'   : 'controller/Decision_Logic'
 */
#endif                                 /* RTW_HEADER_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
