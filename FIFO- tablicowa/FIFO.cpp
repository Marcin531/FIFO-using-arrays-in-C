#include"FIFO.h"


int QfCreate( QueueFIFO* pQueue, int nSize ) // inicjalizuje kolejke zwraca 1 i 0 
{
	pQueue->nKey = ( QFIFOITEM* ) calloc( nSize, sizeof( QFIFOITEM ) );
	if( !( pQueue ) )
	{
		perror( "ERROR-BAD MEMORY ALLOCATION!!!" );
		return 0;
	}
	
	pQueue->MaxQueueSize = nSize;
	pQueue->CurrentQueueSize = 0;
	pQueue->nHead = 0;
	pQueue->nTail = 0;
	
	return 1;
}
int QFEmpty( QueueFIFO* queue )	// zwraca 1 gdy pusta, else 0
{
	return !( queue->CurrentQueueSize );
}
void QFEnqueue( QueueFIFO* queue, QFIFOITEM x )// wstawia na koniec kolejki
{	
	
	if( queue->MaxQueueSize == queue->CurrentQueueSize )
	{
		printf( "Nie mozna dodac kolejnego elementu" );
	}
	else{
		
		queue->nKey[queue->nTail] = x;
		queue->nTail= (queue->nTail+1)% queue->MaxQueueSize;//!!!!
		queue->CurrentQueueSize++;
		
	}
}
int QFDequeue( QueueFIFO* queue ) //nie zwalnia pamieci, tylko zwraca wskaznik i wstawia tam NULL	  = sciagniecie ala pop
{
	if( !QFEmpty( queue ) )
	{
		QFIFOITEM a = queue->nKey[queue->nHead];
		QFDel( queue );
		return a.nKey;
	}
	printf( " Kolejka jest pusta\n" );
	return 0;
		
} 
void QFClear( QueueFIFO* queue ) //czysci wszystkie podlaczone elementy dynamiczne- czysci kolejke, ustawia head i tail na nulla
{
		
		while( queue->CurrentQueueSize )
			QFDel( queue );
		queue->nHead = 0;
		queue->nTail = 0;
		//free( queue->nKey );  wyzerow tabl
		//queue->nKey = NULL;
	
}
void QFRemove( QueueFIFO* queue )	//czysci cala kolejke, usuwa ja 
{
	if( !QFEmpty( queue ) )
	{
		QFClear( queue );
		free( queue->nKey );
		queue = NULL;
		
	}
}
void QFDel( QueueFIFO* queue )// usuwa tylko pierwszy element
{
	if( !QFEmpty(queue) )
	{
		queue->nKey[queue->nHead].nKey=NULL;
		queue->nHead = ( queue->nHead + 1 ) % queue->MaxQueueSize;
		queue->CurrentQueueSize--;
		
	}
	else
		printf( "Kolejka jest pusta" );
}

void QFPrint( QueueFIFO q )
{
	if( !QFEmpty( &q ) )
	{
		for( int i =q.nHead; i < q.nTail; i++ )
		{
			printf( "%d: %d\n",i-q.nHead,  q.nKey[i]  );
		}
	}
}


QFIFOITEM* CreateElement( int nKey )
{
	QFIFOITEM* n = ( QFIFOITEM* ) malloc( sizeof( QFIFOITEM ) );
	if( n )
	{
		n->nKey = nKey;
		return n;
	}
	else
		perror( "Nie udalo sie utworzyc elementu" );
	return 0;
}