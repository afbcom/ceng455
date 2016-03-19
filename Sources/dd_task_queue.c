/*
 * dd_task_queue.c
 *
 *  Created on: Mar 13, 2016
 *      Author: afbcom
 */


#include "dd_task_queue.h"
task_list_type* create_task_entry( void );

//typedef struct task_list_type
//{
//	uint32_t tid;
//	uint32_t deadline;
//	uint32_t task_type;
//	uint32_t creation_time;
//	struct task_list *next_cell;
//	struct task_list *previous_cell;
//} task_list;

task_list_type active_list;
task_list_type overdue_list;

task_list_type* dd_task_create_entry( void )
{
	task_list_type *temp;
	temp = (OSA_MemAlloc( sizeof( task_list_type ) ));
	return temp;
}

void dd_task_struct_init( task_list_type *input, uint32_t tid, uint32_t deadline, uint32_t task_type )
{
	MQX_TICK_STRUCT ticks;
	_time_get_ticks(&ticks);
	input->tid = tid;
	if ( deadline == 0 ) { deadline = 10000; }
	input->deadline = deadline;
	input->task_type = task_type;
	input->creation_time = ticks.TICKS[0];  //FIXME
	input->next_cell = NULL;
	input->previous_cell = NULL;
}

void dd_task_insert(task_list_type *insert_task, task_list_ptr_type *head )
{
	task_list_type *current_task;
	task_list_type *temp_task_ptr;
	uint8_t count = 0;
	uint8_t headflag = 1;
	uint8_t exitflag = 1;

	if ( head->length == 0 )
	{
		head->head = insert_task;
		head->length++;
	}
	else
	{
		current_task = head->head;
		while ( current_task != NULL && exitflag)
		{
			if ( current_task->deadline < insert_task->deadline )
			{
				current_task = current_task->next_cell;
				//current_task = (task_list_t*)(current_task->next_cell);
				headflag = 0;
				exitflag = 0;
			}
			else	//Current Tasks Deadline is greater,
			{		//therefore insert in front of current task
				insert_task->next_cell = current_task;
				if ( count )
				{
					insert_task->previous_cell = current_task->previous_cell;
					temp_task_ptr = current_task->previous_cell;
					temp_task_ptr->next_cell = insert_task;
				}
				//current_task->previous_cell->next_cell = insert_task;
				current_task->previous_cell = insert_task;
				current_task = NULL;//exit the loop
				printf("TI\r\n");
				if( headflag ) { head->head = insert_task; }
			}
		}
	}
}
uint8_t dd_task_list_queue( task_list_type *head )
{
	task_list_type *current_task;
	current_task = head;
	uint8_t count=0;

	while ( current_task )
	{
		//replace printf with send message to tx queue or something
		//printf("Task ID:%d, Deadline: %d \r\n", current_task->tid, current_task->deadline );
		current_task = current_task->next_cell;
		count++;
	}
	return count;
}

//To be called when task finishes to remove it from the list
void dd_task_delete_top( task_list_type *head )
{
	task_list_type *temp;
	temp = head;
	head = head->next_cell;
	OSA_MemFree( temp );
}
