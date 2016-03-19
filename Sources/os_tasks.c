/* ###################################################################
**     Filename    : os_tasks.c
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

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"
#include "dd_task_queue.h"

#ifdef __cplusplus
extern "C" {
#endif 


_pool_id char_message_pool;
_pool_id uint32_message_pool;
//hello
/*
** ===================================================================
**     Callback    : dd_scheduler_main
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void dd_scheduler_main(os_task_param_t task_init_data)
{

	UINT32_MESSAGE_PTR msg_ptr;
	_queue_id scheduler_qid;

	init();

	//start task list experimental code-GITIGNORE ME ANOTHER TEST

	task_list_t *active_list_head = NULL;
	task_list_t *current_task;

	current_task = dd_task_create_entry();
	scheduler_qid=_msgq_open(SCHEDLUER_QUEUE,0);

	dd_task_struct_init( current_task, 1, 6, 0 );
	//printf("\r\nTID: %d\r\n", current_task->tid);
	active_list_head = dd_task_insert( current_task, active_list_head );
//	current_task = dd_task_create_entry();
//	dd_task_struct_init( current_task, 2, 5, 0 );
//	active_list_head = dd_task_insert( current_task, active_list_head );
//
//	current_task = dd_task_create_entry();
//	dd_task_struct_init( current_task, 8, 6, 0 );
//	active_list_head = dd_task_insert( current_task, active_list_head );
//
//	current_task = dd_task_create_entry();
//	dd_task_struct_init( current_task, 3, 7, 0 );
//	active_list_head = dd_task_insert( current_task, active_list_head );
//printf("\r\nTID: %d\r\n", active_list_head->tid);
//dd_task_list_queue( active_list_head );
//printf("Task Count: %d\r\n", dd_task_list_queue( active_list_head ) );
//end task list experimental code


	while(1)
	{
		msg_ptr = _msgq_receive(scheduler_qid,0);
		_msg_free(msg_ptr); 						// MIGHT BE ISSUE HERE

		switch (msg_ptr->DATA[0]) {

		//Insert calling task into struct. task id in data[1]
		case 'C':
		{

			printf("got message from create with task ID %d\n",
					msg_ptr->DATA[1]);


			/*
			 * Alex Put stuff here.
			 *
			 *
			 */


			//SEND MESSAGE BACK IS SAVE IS SUCCESSFUL

			msg_ptr = (UINT32_MESSAGE_PTR) _msg_alloc(uint32_message_pool);
			if (msg_ptr == NULL) {printf("\nCould not allocate a message for scheduler\n");}

			msg_ptr->HEADER.SOURCE_QID = scheduler_qid;
			msg_ptr->HEADER.TARGET_QID = _msgq_get_id(0, dd_CREATE_QUEUE);
			msg_ptr->HEADER.SIZE = sizeof(MESSAGE_HEADER_STRUCT) + sizeof(msg_ptr->DATA) + 4;


			msg_ptr->DATA[2] = 1;
			_msgq_send(msg_ptr);
			//printf("Task Count: %d\r\n", dd_task_list_queue( active_list_head ) );

			break;
		}

		//delete calling task from struct. task id in data[1]
		case 'D':
		{
			printf("Deleted User Function %d \n", msg_ptr->DATA[1]);
			break;

		}

		// List active tasks from struct
		case 'A':
		{
			printf("Active tasks\n");
			break;
		}


		// List overdue tasks from struct
		case 'O':
		{
			printf("Overdue tasks\n");
			break;
		}

		default:
			break;
		}

		OSA_TimeDelay(1);
	}

}

/*
** ===================================================================
**     Callback    : TX_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void TX_task(os_task_param_t task_init_data)
{

	CHAR_MESSAGE_PTR msg_ptr;
	_queue_id transmit_qid;
	uint8_t exitData=0;

	transmit_qid = _msgq_open( TRANSMIT_QUEUE, 0);

	if (transmit_qid == 0) { printf("\nErr: TX message queue\n"); _task_block();}

	while (1) {

		exitData=0;
		msg_ptr = _msgq_receive(transmit_qid, 0);

		while((msg_ptr->DATA[exitData] != 0 ) && ( exitData < msgBuffSize )){
			exitData++;
		}

		UART_DRV_SendData( myUART_IDX, msg_ptr->DATA, exitData );
		printf("%d\n", exitData);

		_msg_free(msg_ptr);


		OSA_TimeDelay(2);
	}
}

/*
** ===================================================================
**     Callback    : task_generator
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void task_generator(os_task_param_t task_init_data)
{

  while (1) {

    
    OSA_TimeDelay(10);
   

  }

}


/*
** ===================================================================
**     Callback    : dd_monitor_main
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void dd_monitor_main(os_task_param_t task_init_data)
{
	CHAR_MESSAGE_PTR msg_ptr;
	_queue_id monitor_qid;

	monitor_qid = _msgq_open(MONITOR_QUEUE, 0);

	dd_tcreate(DD_USER_TASK_TASK, 0);

	while(1)
	{
		msg_ptr=_msgq_receive(monitor_qid, 0);

	}

}

/*
** ===================================================================
**     Callback    : dd_user_task_main
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void dd_user_task_main(os_task_param_t task_init_data)
{
	uint32_t i;

	while (1) {

    /* Write your code here ... */
    for(i=0; i<100000000 ; i++){
    	//waste time
    }
    printf("user task\n");
   // dd_return_active_list();
   // dd_return_overdue_list();
    dd_delete(_task_get_id());

    OSA_TimeDelay(10);                 /* Example code (for task release) */

  }

}


uint8_t init(void){

	uint32_message_pool = _msgpool_create(sizeof(UINT32_MESSAGE),
	NUM_CLIENTS, 1, 0);

	if ( uint32_message_pool == MSGPOOL_NULL_POOL_ID )
	  { printf( "\nErr: create Uint32 message pool\n" );_task_block(); return 0;}

	//Open message pool for TX

	char_message_pool = _msgpool_create(sizeof(CHAR_MESSAGE),
	NUM_CLIENTS, 1, 0);

	if ( char_message_pool == MSGPOOL_NULL_POOL_ID )
	  { printf( "\nErr: create Char message pool\n" );_task_block(); return 0;}

	_task_create(0, TX_TASK, (uint32_t)(NULL) );
	OSA_TimeDelay(2);
	_task_create(0, DD_MONITOR_TASK, (uint32_t)(NULL) );



	return 1;

}

