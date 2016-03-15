/* ###################################################################
**     Filename    : os_tasks.h
**     Project     : project3
**     Processor   : MK64FN1M0VLL12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-03-13, 11:57, # CodeGen: 1
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         dd_user_task_main - void dd_user_task_main(os_task_param_t task_init_data);
**         dd_monitor_main   - void dd_monitor_main(os_task_param_t task_init_data);
**         dd_scheduler_main - void dd_scheduler_main(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file os_tasks.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup os_tasks_module os_tasks module documentation
**  @{
*/         

#ifndef __os_tasks_H
#define __os_tasks_H
/* MODULE os_tasks */

#include "fsl_device_registers.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "mqx_ksdk.h"
#include "uart1.h"
#include "fsl_mpu1.h"
#include "fsl_hwtimer1.h"
#include "MainTask.h"
#include "dd_scheduler.h"
#include "dd_monitor.h"
#include "myUART.h"
#include "dd_user_task.h"
#include "TX.h"
#include "message.h"
#include "mutex.h"
#include "access_functions.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*
 * defines
 */

#define MONITOR_QUEUE     	3
#define TRANSMIT_QUEUE		4
#define dd_CREATE_QUEUE     5
#define SCHEDLUER_QUEUE     6
#define msgBuffSize         128
#define NUM_CLIENTS         (10)


/*
 * Prototypes
 */
uint8_t init(void);



/*
 * Structs
 */
typedef struct char_message
{
   MESSAGE_HEADER_STRUCT   HEADER;
   unsigned char           DATA[5];
} CHAR_MESSAGE, * CHAR_MESSAGE_PTR;


typedef struct uint32_message
{
   MESSAGE_HEADER_STRUCT   HEADER;
   uint32_t           DATA[ 5 ];
} UINT32_MESSAGE, *UINT32_MESSAGE_PTR;


/*
** ===================================================================
**     Callback    : dd_user_task_main
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void dd_user_task_main(os_task_param_t task_init_data);

/*
** ===================================================================
**     Callback    : dd_monitor_main
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void dd_monitor_main(os_task_param_t task_init_data);

/*
** ===================================================================
**     Callback    : dd_scheduler_main
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void dd_scheduler_main(os_task_param_t task_init_data);


/*
** ===================================================================
**     Callback    : TX_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void TX_task(os_task_param_t task_init_data);

/* END os_tasks */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __os_tasks_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
