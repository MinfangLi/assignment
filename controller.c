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
 * File: controller.c
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

#include "controller.h"

/* Named constants for Chart: '<Root>/Decision_Logic' */
#define control_IN_OverCurrent_Detected ((uint8_T)3U)
#define controller_IN_Error            ((uint8_T)1U)
#define controller_IN_Extract          ((uint8_T)1U)
#define controller_IN_Extracted        ((uint8_T)1U)
#define controller_IN_Insert           ((uint8_T)2U)
#define controller_IN_Inserted         ((uint8_T)2U)
#define controller_IN_Moving           ((uint8_T)3U)
#define controller_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define controller_IN_NormalOperation  ((uint8_T)2U)

/* Block states (default storage) */
DW_controller_T controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_controller_T controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_controller_T controller_Y;

/* Real-time model */
RT_MODEL_controller_T controller_M_;
RT_MODEL_controller_T *const controller_M = &controller_M_;

/* Model step function */
void controller_step(void)
{
  /* Chart: '<Root>/Decision_Logic' incorporates:
   *  Inport: '<Root>/AxelLock_DI'
   *  Inport: '<Root>/Current_A'
   *  Inport: '<Root>/Extracted_Pos_Switch_DI'
   *  Inport: '<Root>/Inserted_Pos_Switch_DI'
   */
  if (controller_DW.temporalCounter_i1 < 63U) {
    controller_DW.temporalCounter_i1++;
  }

  if (controller_DW.is_active_c3_controller == 0U) {
    controller_DW.is_active_c3_controller = 1U;
    controller_DW.is_Operations = controller_IN_Moving;

    /* Outport: '<Root>/Enable_DO' */
    controller_Y.Enable_DO = true;
    if (controller_U.AxelLock_DI) {
      controller_DW.is_Moving = controller_IN_Insert;

      /* Outport: '<Root>/Insert_DO' */
      controller_Y.Insert_DO = true;

      /* Outport: '<Root>/Extract_DO' */
      controller_Y.Extract_DO = false;
    } else {
      controller_DW.is_Moving = controller_IN_Extract;

      /* Outport: '<Root>/Insert_DO' */
      controller_Y.Insert_DO = false;

      /* Outport: '<Root>/Extract_DO' */
      controller_Y.Extract_DO = true;
    }

    controller_DW.is_Monitoring = controller_IN_NormalOperation;

    /* Outport: '<Root>/Error_DO' incorporates:
     *  Inport: '<Root>/AxelLock_DI'
     */
    controller_Y.Error_DO = false;
  } else {
    switch (controller_DW.is_Operations) {
     case controller_IN_Extracted:
      /* Outport: '<Root>/Insert_DO' */
      controller_Y.Insert_DO = false;

      /* Outport: '<Root>/Extract_DO' */
      controller_Y.Extract_DO = false;
      if ((!controller_U.Extracted_Pos_Switch_DI) || controller_U.AxelLock_DI) {
        controller_DW.is_Operations = controller_IN_Moving;

        /* Outport: '<Root>/Enable_DO' */
        controller_Y.Enable_DO = true;
        if (controller_U.AxelLock_DI) {
          controller_DW.is_Moving = controller_IN_Insert;

          /* Outport: '<Root>/Insert_DO' */
          controller_Y.Insert_DO = true;

          /* Outport: '<Root>/Extract_DO' */
          controller_Y.Extract_DO = false;
        } else {
          controller_DW.is_Moving = controller_IN_Extract;

          /* Outport: '<Root>/Insert_DO' */
          controller_Y.Insert_DO = false;

          /* Outport: '<Root>/Extract_DO' */
          controller_Y.Extract_DO = true;
        }
      }
      break;

     case controller_IN_Inserted:
      /* Outport: '<Root>/Insert_DO' */
      controller_Y.Insert_DO = false;

      /* Outport: '<Root>/Extract_DO' */
      controller_Y.Extract_DO = false;
      if ((!controller_U.Inserted_Pos_Switch_DI) || (!controller_U.AxelLock_DI))
      {
        controller_DW.is_Operations = controller_IN_Moving;

        /* Outport: '<Root>/Enable_DO' */
        controller_Y.Enable_DO = true;
        if (controller_U.AxelLock_DI) {
          controller_DW.is_Moving = controller_IN_Insert;

          /* Outport: '<Root>/Insert_DO' */
          controller_Y.Insert_DO = true;

          /* Outport: '<Root>/Extract_DO' */
          controller_Y.Extract_DO = false;
        } else {
          controller_DW.is_Moving = controller_IN_Extract;

          /* Outport: '<Root>/Insert_DO' */
          controller_Y.Insert_DO = false;

          /* Outport: '<Root>/Extract_DO' */
          controller_Y.Extract_DO = true;
        }
      }
      break;

     default:
      /* case IN_Moving: */
      if (controller_U.Inserted_Pos_Switch_DI && controller_U.AxelLock_DI) {
        controller_DW.is_Moving = controller_IN_NO_ACTIVE_CHILD;
        controller_DW.is_Operations = controller_IN_Inserted;

        /* Outport: '<Root>/Insert_DO' */
        controller_Y.Insert_DO = false;

        /* Outport: '<Root>/Extract_DO' */
        controller_Y.Extract_DO = false;

        /* Outport: '<Root>/Error_DO' */
        controller_Y.Error_DO = false;
      } else if (controller_U.Extracted_Pos_Switch_DI &&
                 (!controller_U.AxelLock_DI)) {
        controller_DW.is_Moving = controller_IN_NO_ACTIVE_CHILD;
        controller_DW.is_Operations = controller_IN_Extracted;

        /* Outport: '<Root>/Insert_DO' */
        controller_Y.Insert_DO = false;

        /* Outport: '<Root>/Extract_DO' */
        controller_Y.Extract_DO = false;

        /* Outport: '<Root>/Error_DO' */
        controller_Y.Error_DO = false;
      } else if (controller_DW.is_Moving == controller_IN_Extract) {
        /* Outport: '<Root>/Insert_DO' */
        controller_Y.Insert_DO = false;

        /* Outport: '<Root>/Extract_DO' */
        controller_Y.Extract_DO = true;
        if (controller_U.AxelLock_DI) {
          controller_DW.is_Moving = controller_IN_Insert;

          /* Outport: '<Root>/Insert_DO' */
          controller_Y.Insert_DO = true;

          /* Outport: '<Root>/Extract_DO' */
          controller_Y.Extract_DO = false;
        }
      } else {
        /* Outport: '<Root>/Insert_DO' */
        /* case IN_Insert: */
        controller_Y.Insert_DO = true;

        /* Outport: '<Root>/Extract_DO' */
        controller_Y.Extract_DO = false;
        if (!controller_U.AxelLock_DI) {
          controller_DW.is_Moving = controller_IN_Extract;

          /* Outport: '<Root>/Insert_DO' */
          controller_Y.Insert_DO = false;

          /* Outport: '<Root>/Extract_DO' */
          controller_Y.Extract_DO = true;
        }
      }
      break;
    }

    switch (controller_DW.is_Monitoring) {
     case controller_IN_Error:
      /* Outport: '<Root>/Enable_DO' */
      controller_Y.Enable_DO = false;

      /* Outport: '<Root>/Error_DO' */
      controller_Y.Error_DO = true;
      break;

     case controller_IN_NormalOperation:
      if (controller_U.Current_A >= 1.5F) {
        controller_DW.is_Monitoring = control_IN_OverCurrent_Detected;
        controller_DW.temporalCounter_i1 = 0U;
      } else {
        if (controller_U.Inserted_Pos_Switch_DI &&
            controller_U.Extracted_Pos_Switch_DI) {
          controller_DW.is_Monitoring = controller_IN_Error;
        }
      }
      break;

     default:
      /* case IN_OverCurrent_Detected: */
      if (controller_DW.temporalCounter_i1 >= 50) {
        controller_DW.is_Monitoring = controller_IN_Error;
      } else {
        if (controller_U.Current_A < 1.5F) {
          controller_DW.is_Monitoring = controller_IN_NormalOperation;

          /* Outport: '<Root>/Error_DO' */
          controller_Y.Error_DO = false;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Decision_Logic' */
}

/* Model initialize function */
void controller_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */