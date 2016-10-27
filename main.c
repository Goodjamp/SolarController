/* Standard includes. */
#include <string.h>
#include <stdint.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

// Menu diver lib files
#include "ListBox.h"
#include "MenuItemBox.h"
#include "NumBox.h"

/* The bitmap used to display the FreeRTOS.org logo is stored in 16bit format
and therefore takes up a large proportion of the Flash space.  Setting this
parameter to 0 excludes the bitmap from the build, freeing up Flash space for
extra code. */
#define mainINCLUDE_BITMAP 					0

#if mainINCLUDE_BITMAP == 1
	#include "bitmap.h"
#endif

/* Task priorities. */
#define mainTASK1_PRIORITY				( tskIDLE_PRIORITY + 1 )
#define mainTASK2_PRIORITY				( tskIDLE_PRIORITY + 1 )
#define mainTASK1_STACK_SIZE			100
#define mainTASK2_STACK_SIZE			100


void task1( void *pvParameters );
void task2( void *pvParameters );

int main( void )
{
	/* Start the tasks defined within this file/specific to this demo. */
    xTaskCreate( task1, "TASK1", mainTASK1_STACK_SIZE, NULL, mainTASK1_PRIORITY, NULL );
	xTaskCreate( task2, "TASK2", mainTASK2_STACK_SIZE, NULL, mainTASK2_PRIORITY, NULL );

	/* Start the scheduler. */
	vTaskStartScheduler();

	return 0;
}

void task1( void *pvParameters )
{
	uint32_t counter=0;
	while(1)
	{
		counter++;
	}

};
void task2( void *pvParameters )
{
	uint32_t counter=0;
	while(1)
	{
		counter++;
	}
}


void vApplicationMallocFailedHook( void )
{
	/* Called if a call to pvPortMalloc() fails because there is insufficient
	free memory available in the FreeRTOS heap.  pvPortMalloc() is called
	internally by FreeRTOS API functions that create tasks, queues, software
	timers, and semaphores.  The size of the FreeRTOS heap is set by the
	configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) xTask;

	/* Run time stack overflow checking is performed if
	configconfigCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	volatile size_t xFreeStackSpace;

	/* This function is called on each cycle of the idle task.  In this case it
	does nothing useful, other than report the amout of FreeRTOS heap that
	remains unallocated. */
	xFreeStackSpace = xPortGetFreeHeapSize();

	if( xFreeStackSpace > 100 )
	{
		/* By now, the kernel has allocated everything it is going to, so
		if there is a lot of heap remaining unallocated then
		the value of configTOTAL_HEAP_SIZE in FreeRTOSConfig.h can be
		reduced accordingly. */
	}
}
