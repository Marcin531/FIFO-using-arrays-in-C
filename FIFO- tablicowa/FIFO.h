#ifndef FIFO_H
#define FIFO_H

#include<stdio.h>
#include <stdlib.h>
#include "global.h"

typedef struct
{

	QFIFOITEM* nKey;
	int nHead;// index of the first item - nHead
	int nTail;// index of the first empty item (one after last) - nTail
	int CurrentQueueSize;
	int MaxQueueSize;

}QueueFIFO;


int QfCreate( QueueFIFO* q, int nSize ); // inicjalizuje kolejke zwraca 1 i 0 
int QFEmpty( QueueFIFO* q );	// zwraca 1 gdy pusta, else 0
void QFEnqueue( QueueFIFO* q, QFIFOITEM x );// wstawia na koniec kolejki
int QFDequeue( QueueFIFO* q ); //nie zwalnia pamieci, tylko zwraca wskaznik i wstawia tam NULL	  = sciagniecie ala pop
void QFClear( QueueFIFO* q ); //czysci wszystkie podlaczone elementy dynamiczne- czysci kolejke, ustawia head i tail na nulla
void QFRemove( QueueFIFO* q );	//czysci cala kolejke, usuwa ja 
void QFDel( QueueFIFO* q );// usuwa tylko pierwszy element
void QFPrint( QueueFIFO q );
QFIFOITEM* CreateElement( int nKey );
#endif