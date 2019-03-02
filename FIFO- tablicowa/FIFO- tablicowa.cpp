
// Implementacja kolejki FIFO przy wykorzystaniu tablic
// Implementation of FIFO queue using arrays

#include "FIFO.h"
#include "pch.h"

#define MAXSIZE 10

int main()
{
	QueueFIFO queue;

	if( !QfCreate( &queue, MAXSIZE ) )
	{
		perror( "NIE MOZNA STWORZYC KOLEJKI" );
	}
	//queue.MaxQueueSize = 10;

	printf( "MAXSIZE: %d \n", queue.MaxQueueSize );

	if( QFEmpty( &queue ) )
		printf( "Kolejka jest pusta\n" );

	printf( "Dodanie 4 elementow\n" );
	QFIFOITEM* a = CreateElement( 5 );
	QFEnqueue( &queue, *a );
	a = CreateElement( 6 );
	QFEnqueue( &queue, *a );
	a = CreateElement( 7 );
	QFEnqueue( &queue, *a );
	a = CreateElement( 8 );
	QFEnqueue( &queue, *a );
	QFPrint( queue );
	printf( "Obecny rozmiar: %d \n", queue.CurrentQueueSize );


	printf( "Sciagnienie elementu: %d\n", QFDequeue( &queue ) );
	printf( "Sciagnienie elementu: %d\n", QFDequeue( &queue ) );

	printf( "Obecny rozmiar: %d \n", queue.CurrentQueueSize );

	QFPrint( queue );

	printf( "Usuniecie elementu: \n" );

	QFDel( &queue );
	QFPrint( queue );
	printf( "Obecny rozmiar: %d \n", queue.CurrentQueueSize );

	printf( "Czyszczenie\n" );
	QFClear( &queue );
	if( QFEmpty( &queue ) )
		printf( "Kolejka jest pusta \n" );
	printf( "Usuniecie kolejki: \n" );
	QFRemove( &queue );


}

/*
int QfCreate( QueueFIFO* q, int nSize ); // inicjalizuje kolejke zwraca 1 i 0
int QFEmpty( QueueFIFO* q );	// zwraca 1 gdy pusta, else 0
void QFEnqueue( QueueFIFO* q, int x );// wstawia na koniec kolejki
int QFDequeue( QueueFIFO* q ); //nie zwalnia pamieci, tylko zwraca wskaznik i wstawia tam NULL	  = sciagniecie ala pop
void QFClear( QueueFIFO* q ); //czysci wszystkie podlaczone elementy dynamiczne- czysci kolejke, ustawia head i tail na nulla
void QFRemove( QueueFIFO* q );	//czysci cala kolejke, usuwa ja
void QFDel( QueueFIFO* q );// usuwa tylko pierwszy element
void QFPrint( QueueFIFO q );

*/