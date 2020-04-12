#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include "string.h" 

void InitLQueue(LQueue *Q) {
	Node *q = (Node *)malloc(sizeof(Node));
	if (q == NULL) {
		printf("Memory allocation failure!\n");
		return ;
	}
	q->next = NULL;
	Q->front = q;
	Q->rear = q;
}

void DestoryLQueue(LQueue *Q) {
	Node *p = Q->front;
	Node *q = NULL;
	Q->rear = Q->front;
	
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	free(Q->front);
//	free(Q->rear);
}

Status IsEmptyLQueue(const LQueue *Q) {
	Status ret;
	if (Q->front == Q->rear) ret = TRUE;
	else ret = FALSE;
	return ret;	
}

Status GetHeadLQueue(LQueue *Q, void *e) {
	Status ret = FALSE;
	if ( IsEmptyLQueue(Q) == TRUE ) {
		printf("����Ϊ�գ��޷��鿴ͷԪ�أ�\n");
	}
	else {
		ret = TRUE;
		memcpy(e,Q->front->next->data,Q->front->next->datasize);
	}
}

int LengthLQueue(LQueue *Q) {
	int len=0;
	Node *p = Q->front;
	while (p != Q->rear) {
		len++;
		p = p->next;
	}
	return len;
}


Status EnLQueue(LQueue *Q, void *data) {
	Status ret = FALSE;
	Node *p = (Node *)malloc(sizeof(Node));
	if (p == NULL) {
		printf("Memory allocation failure!\n");
		return ret;
	}
	ret = TRUE;
	p->datasize = Q->tempSize;
	p->nodetype = Q->tempType;
	
//	printf("p's datasize is %d\n",p->datasize);
//	printf("p's nodetype is%d\n",p->nodetype);

	
	p->data = (void *)malloc(p->datasize);
	memcpy(p->data, data, p->datasize);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
//	if (IsEmptyLQueue(Q)) printf("kong!!!!!!!!!!!\n");
//	else printf("bu kong!!!!!!!\n");
	return ret;
}

Status DeLQueue(LQueue *Q) {
	Status ret = FALSE;
	if ( IsEmptyLQueue(Q) == TRUE ) {
		printf("����Ϊ�գ��޷����ӣ�\n");
	}
	else {
		ret = TRUE;
		Node *p = (Node *)malloc(sizeof(Node));
		p = Q->front->next;
		Q->front->next = p->next;
		if (Q->front->next == NULL)
		Q->rear = Q->front;
		free(p);
	}
	return ret;
}

void ClearLQueue(LQueue *Q) {
	Node *p;
	Node *q;
	p = Q->front->next;
	Q->rear = Q->front;
	
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	Q->front->next = NULL;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, DataType type)) {
	Status ret = FALSE;
	if ( IsEmptyLQueue(Q) == TRUE ) {
		printf("����Ϊ�գ��޷�������\n");
	}
	else {
		ret = TRUE;
		Node *p;
		p = Q->front->next;
		while (p != NULL) {
			foo(p->data,p->nodetype);
			p = p->next;
		}
	}
	return ret;
}

void LPrint(void *q, DataType type1) {
	switch (type1) {
		case INT:
			printf("-->%d",*(int *)q);
			break;
		case CHAR:
			printf("-->%c",*(char *)q);
			break;
		case DOUBLE:
			printf("-->%.2lf",*(double *)q);
			break;
		case STRING:
			printf("-->%s",(char *)q);
			break;
	}
}

void showPrompt() {
	printf("\t������Ҫִ�еĲ���:\n");
	printf("\t1:��ʼ������\n");
	printf("\t2:���ٶ���\n");
	printf("\t3:ʲôҲ����\n");
	printf("\t4:�������Ƿ�Ϊ��\n");
	printf("\t5:�鿴��ͷԪ��\n");
	printf("\t6:ȷ�����г���\n");
	printf("\t7:���\n");
	printf("\t8:����\n");
	printf("\t9:��ն���\n");
	printf("\t10:����������\n");
	printf("\t11:�˳�\n");
}

void chooseType(LQueue *Q) {
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
			type = INT;
			Q->tempSize = 4;
			Q->tempType = INT;
			break;
		case 2:
			type = CHAR;
			Q->tempSize = 1;
			Q->tempType = CHAR;	
			break;
		case 3:
			type = DOUBLE;
			Q->tempSize = 8;
			Q->tempType = DOUBLE;
			break;	
		case 4:
			type = STRING;
			Q->tempSize = 50;
			Q->tempType = STRING;	
			break;	
	}
}
