
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
#include "task.h"

/*
 *  1. Opens a queue
 *  2. Creates the task specified and assigns it the minimum priority possible
 *  3. Composes a create_task_message and sends it to the DD-scheduler
 *  4. Waits for a reply at the queue it created above
 *  5. Once the reply is received, it obtains it
 *  6. Destroys the queue
 *  7. Returns to the invoking task
 */
//extern _pool_id uint32_message_pool;
extern _pool_id char_message_pool;
extern _pool_id uint32_message_pool;



_task_id dd_tcreate(uint32_t template_index, uint32_t deadline){

	_task_id task_id;
	UINT32_MESSAGE_PTR msg_ptr;
	_queue_id create_qid;
	uint32_t temp;

	//CREATE QUEUE
	create_qid = _msgq_open(dd_CREATE_QUEUE,0);

	//Create task and set priority = lowest

	task_id =_task_create(0, template_index, deadline );     //FIXME

	if (task_id == MQX_NULL_TASK_ID) { printf("Failed to Create User task"); }
	printf("task created with task ID %d\n", task_id);

	_task_get_priority(task_id, &temp);
	_task_set_priority(task_id, LOW_TASK_PRIORITY , &temp);


	msg_ptr = ( UINT32_MESSAGE_PTR )_msg_alloc( uint32_message_pool );
	if ( msg_ptr == NULL ){	printf( "\nCould not allocate a message for dd_tcreate\n" );return 0;}

	msg_ptr->HEADER.SOURCE_QID = create_qid;
	msg_ptr->HEADER.TARGET_QID = _msgq_get_id( 0, SCHEDLUER_QUEUE );
	msg_ptr->HEADER.SIZE = sizeof(MESSAGE_HEADER_STRUCT) +
			sizeof(msg_ptr->DATA)+ 4 ;

			//strlen((char *)msg_ptr->DATA)+1 ;

	msg_ptr->DATA[0] = 'C';
	msg_ptr->DATA[1] = task_id;
	msg_ptr->DATA[2] = deadline;
	msg_ptr->DATA[3] = 0;

	_msgq_send(msg_ptr);

	msg_ptr = _msgq_receive(create_qid,1000);	//FIXME - should timeout faster

	if(msg_ptr == NULL ){
		printf("Timeout Error\n");
	}
	else{ printf("Message from scheduler %d\n", msg_ptr->DATA[2]);}

	_msg_free(msg_ptr);

	_msgq_close(create_qid);

	return task_id;


}


uint32_t dd_delete(uint32_t task_id){

	UINT32_MESSAGE_PTR msg_ptr;


	msg_ptr = ( UINT32_MESSAGE_PTR )_msg_alloc( uint32_message_pool );
	if ( msg_ptr == NULL ){	printf( "\nCould not allocate a message for dd_tcreate\n" );return 0;}

	msg_ptr->HEADER.SOURCE_QID = 0;
	msg_ptr->HEADER.TARGET_QID = _msgq_get_id( 0, SCHEDLUER_QUEUE );
	msg_ptr->HEADER.SIZE = sizeof(MESSAGE_HEADER_STRUCT) +
			sizeof(msg_ptr->DATA)+ 4 ;

	msg_ptr->DATA[0] = 'D';
	msg_ptr->DATA[1] =  task_id;
	msg_ptr->DATA[2] =  0;

	_msgq_send(msg_ptr);
	_task_destroy(task_id);

	return 0;

}


uint32_t dd_return_active_list(){

	UINT32_MESSAGE_PTR msg_ptr;


	msg_ptr = ( UINT32_MESSAGE_PTR )_msg_alloc( uint32_message_pool );
	if ( msg_ptr == NULL ){	printf( "\nCould not allocate a message for dd_tcreate\n" );return 0;}

	msg_ptr->HEADER.SOURCE_QID = 0;
	msg_ptr->HEADER.TARGET_QID = _msgq_get_id( 0, SCHEDLUER_QUEUE );
	msg_ptr->HEADER.SIZE = sizeof(MESSAGE_HEADER_STRUCT) +
			sizeof(msg_ptr->DATA)+ 4 ;

	msg_ptr->DATA[0] = 'A';
	msg_ptr->DATA[1] =  0;

	_msgq_send(msg_ptr);

	return 0;
}
//struct task_list **list

//struct overdue_tasks **list
uint32_t dd_return_overdue_list(){

	UINT32_MESSAGE_PTR msg_ptr;


	msg_ptr = ( UINT32_MESSAGE_PTR )_msg_alloc( uint32_message_pool );
	if ( msg_ptr == NULL ){	printf( "\nCould not allocate a message for dd_tcreate\n" );return 0;}

	msg_ptr->HEADER.SOURCE_QID = 0;
	msg_ptr->HEADER.TARGET_QID = _msgq_get_id( 0, SCHEDLUER_QUEUE );
	msg_ptr->HEADER.SIZE = sizeof(MESSAGE_HEADER_STRUCT) +
			sizeof(msg_ptr->DATA)+ 4 ;

	msg_ptr->DATA[0] = 'O';
	msg_ptr->DATA[1] =  0;

	_msgq_send(msg_ptr);

	return 0;
}
