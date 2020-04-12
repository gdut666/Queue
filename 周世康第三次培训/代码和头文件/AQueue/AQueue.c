#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#include <string.h>

void InitAQueue(AQueue *Q) {
	int i;
	Q->length = MAXQUEUE;
	for (i=0; i<MAXQUEUE; i++) {
		Q->data[i] = (void *)malloc(100);
		Q->front = Q->rear = 0;
	}
}

void DestoryAQueue(AQueue *Q) {
	int i;
	for (i=0; i<MAXQUEUE; i++) {
		free(Q->data[i]);
	}
	Q->data[0] = NULL;
}

Status IsFullAQueue(const AQueue *Q) {
	Status ret = FALSE;
	if ( (Q->rear+1)%MAXQUEUE == Q->front ) ret = TRUE;
	return ret;
}

Status IsEmptyAQueue(const AQueue *Q) {
	Status ret = FALSE;
	if (Q->front == Q->rear) ret = TRUE;
	return ret;
}

Status GetHeadAQueue(AQueue *Q, void *e) {
	Status ret = FALSE;
	int datasize;
	if ( IsEmptyAQueue(Q) == TRUE ) {
		printf("����Ϊ�գ��޷��õ���ͷ��\n");
	}
	else {
		switch(datatypeArray[Q->front]) {
			case INT:
				datasize = 4;break;
			case CHAR:
				datasize = 1;break;
			case DOUBLE:
				datasize = 8;break;
			case STRING:
				datasize = 50;break;
		}
		ret = TRUE;
		memcpy(e, Q->data[Q->front],datasize);
	}
	return ret;
}

int LengthAQueue(AQueue *Q) {
	return ( (Q->rear-Q->front+Q->length)%Q->length );
} 

Status EnAQueue(AQueue *Q, void *data) {
	Status ret = FALSE;
	if ( IsFullAQueue(Q) ) {
		printf("�����������������У�\n");
	}
	else {
		ret = TRUE;
		memcpy(Q->data[Q->rear], data, Q->dataSize);
		Q->rear = (Q->rear + 1)%Q->length;
	}
	return ret;
}

Status DeAQueue(AQueue *Q) {
	Status ret = FALSE;
	if ( IsEmptyAQueue(Q) ) printf("����Ϊ�գ����ܳ��ӣ�\n");
	else {
		ret = TRUE;
		printf("���ӳɹ���\n");
		Q->front = (Q->front+1) % (Q->length);
	}
	return ret;
}

void ClearAQueue(AQueue *Q) {
	if ( IsEmptyAQueue(Q) == TRUE ) {
		printf("����Ϊ�գ�������գ�\n");
	}
	else {
		printf("��ճɹ���\n");
		Q->front = Q->rear;
	}
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, typeData dtType)) {
	Status ret = FALSE;
	int i;
	if  ( IsEmptyAQueue( Q ) == TRUE ) {
		printf("����Ϊ�գ��޷�������\n");
	}
	else {
		ret = TRUE;
//		i = 0;
//		while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
//    		foo(Q->data[Q->front+i]);
//    		i = (i + 1) % MAXQUEUE;
//    	}
//    	
		i = (Q->front)%MAXQUEUE;
		for (; i != Q->rear ; i = (i+1)%Q->length ) {
			foo(Q->data[i],datatypeArray[i]);
		}
	}
	return ret;
} 

void APrint(void *q, typeData dtType) {	 
    if(dtType == DOUBLE)
        printf("--> %.2lf", *(double*)q);
    if(dtType == CHAR)
        printf("--> %c", *(char*)q);
    if(dtType == INT)
        printf("--> %d ", *(int*)q);
    if(dtType == STRING)
        printf("--> %s ", (char*)q);
}

void chooseType(AQueue *Q) {
	printf("������Ҫѡ�����������:\n");
	printf("1: int\n");
	printf("2: char\n");
	printf("3: double\n");
	printf("4: string\n");
	int dataTypeChoice;
	scanf("%d",&dataTypeChoice);
	if (dataTypeChoice<1||dataTypeChoice>4) printf("��������ȷ�����֣�\n");
	switch (dataTypeChoice) {
		case 1:
			datatype = INT;
			Q->dataSize = 4;
			break;
		case 2:
			datatype = CHAR;
			Q->dataSize = 1;	
			break;
		case 3:
			datatype = DOUBLE;
			Q->dataSize = 8;
			break;	
		case 4:
			datatype = STRING;
			Q->dataSize = 50;	
			break;	
	}
}

void showPrompt() {
	printf("\t������Ҫִ�еĲ���:\n");
	printf("\t1:��ʼ������\n");
	printf("\t2:���ٶ���\n");
	printf("\t3:�������Ƿ�����\n");
	printf("\t4:�������Ƿ�Ϊ��\n");
	printf("\t5:�鿴��ͷԪ��\n");
	printf("\t6:ȷ�����г���\n");
	printf("\t7:���\n");
	printf("\t8:����\n");
	printf("\t9:��ն���\n");
	printf("\t10:����������\n");
	printf("\t11:�˳�\n");
}

void showTitle() {
	printf("---------------------��������AQueue---------------------------\n");
	printf("\n\n");
}
