/*
 * access_functions.h
 *
 *  Created on: Mar 13, 2016
 *      Author: trevor
 */

#ifndef SOURCES_ACCESS_FUNCTIONS_H_
#define SOURCES_ACCESS_FUNCTIONS_H_

#include "os_tasks.h"
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "mqx.h"



#endif /* SOURCES_ACCESS_FUNCTIONS_H_ */


#define MIN_PRIORITY 30




_task_id dd_tcreate(uint32_t template_index, uint32_t deadline);

uint32_t dd_delete(uint32_t task_id);


uint32_t dd_return_active_list();

uint32_t dd_return_overdue_list();



