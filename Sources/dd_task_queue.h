/*
 * dd_task_queue.h
 *
 *  Created on: Mar 13, 2016
 *      Author: afbcom
 */

#ifndef SOURCES_DD_TASK_QUEUE_H_
#define SOURCES_DD_TASK_QUEUE_H_



#endif /* SOURCES_DD_TASK_QUEUE_H_ */
#include "os_tasks.h"
#include "stdint.h"



typedef struct task_list_
{
	uint32_t tid;
	uint32_t deadline;
	uint32_t task_type;
	uint32_t creation_time;
	struct task_list_ *next_cell;
	struct task_list_ *previous_cell;
} task_list_type;

typedef struct task_list_ptr
{
	task_list_type *head;
	task_list_type *tail;
	uint8_t length;
} task_list_ptr_type;

task_list_type* dd_task_create_entry( void );
void 			dd_task_struct_init( task_list_type *input, uint32_t tid, uint32_t deadline, uint32_t task_type );
void	 		dd_task_insert( task_list_type *task, task_list_ptr_type *head );
uint8_t 		dd_task_list_queue( task_list_type *head );
void 			dd_task_delete_top( task_list_type *head );


