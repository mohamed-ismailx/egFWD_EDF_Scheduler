

//one The Idle task.

static portTASK_FUNCTION( prvIdleTask, pvParameters )
{
                ......
    for( ; ; )
    {
		#if( configUSE_EDF_SCHEDULER == 1)
		{
			//Modify the idle task to keep it always the farest deadline
			listSET_LIST_ITEM_VALUE( &( ( pxCurrentTCB )->xStateListItem ), ( pxCurrentTCB )->xTaskPeriod + xTaskGetTickCount() );
			listINSERT_END( &(xReadyTasksListEDF), &( ( pxCurrentTCB )->xStateListItem ) );
		}
		#endif

//two
BaseType_t xTaskIncrementTick( void )
{
     
	 ..............

    if( uxSchedulerSuspended == ( UBaseType_t ) pdFALSE )
    {

        ........

        if( xConstTickCount == ( TickType_t ) 0U ) /*lint !e774 'if' does not always evaluate to false as it is looking for an overflow. */
        {
            .......
        }
        else
        {
            ........
        }
 
 
           .........
		   
        if( xConstTickCount >= xNextTaskUnblockTime )
        {
            for( ; ; )
            {
                if( listLIST_IS_EMPTY( pxDelayedTaskList ) != pdFALSE )
                {
                   
				   ................
                }
                else
                {
                   .......
                    if( xConstTickCount < xItemValue )
                    {
                       ........
                    }
                    else
                    {
                        .......
                    }

                 ........
				 ........
				 ........
                    if( listLIST_ITEM_CONTAINER( &( pxTCB->xEventListItem ) ) != NULL )
                    {
                        ...
                    }
                    else
                    {
                       .....
                    }

					
					#if (configUSE_EDF_SCHEDULER == 1)
						listSET_LIST_ITEM_VALUE( &( ( pxTCB )->xStateListItem ), ( pxTCB)->xTaskPeriod + xTaskGetTickCount() );
					#endif
					
                    prvAddTaskToReadyList( pxTCB );
					
					#if configUSE_EDF_SCHEDULER == 1
						xSwitchRequired = pdTRUE;
					#endif
					
					
					.............
                }
            }
        }
	}
}

