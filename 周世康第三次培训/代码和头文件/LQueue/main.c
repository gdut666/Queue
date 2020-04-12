#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include "LQueue.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("\t\t------------------------��������LQueue-----------------------\n\n\n");	

	int choice;  //������ѡ��     0<choice< 
	int temp1;
	int isInit = 0;
	
	while (1) {
		showPrompt();
		
		choice = scanf("%d",&temp1);		//����ѡ�� 
		if (choice == 0) {				
			fflush(stdin);
			printf("��������ȷ�����֣�\n");
			continue;
		}
		else choice = temp1;
		
		switch(choice) {
			case 1:
				if (isInit == 1) {
					printf("��ʼ��ʧ�ܣ� ԭ��:�����ѳ�ʼ����\n");
					break;
				}
				
				isInit = 1;
				LQueue *lq = (LQueue *)malloc(sizeof(LQueue));
				InitLQueue(lq);
				printf("���г�ʼ���ɹ���\n");
				break;
				
			case 2:
				if ( isInit == 0 ) {
					printf("���ٶ���ʧ�ܣ�ԭ��:����δ��ʼ����\n");
					break;
				}
				isInit = 0;
				DestoryLQueue(lq);
				printf("���ٳɹ���\n");
				break;
				
			case 3:
				break;
				
				
			case 4:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				if ( IsEmptyLQueue(lq) ) printf("����Ϊ�գ�\n");
				else printf("����δ�գ�\n");
				break;
				
			case 5:
				if ( isInit == 0 ) {
				printf("����δ��ʼ����\n");
				break;
				}
				if ( IsEmptyLQueue(lq) == TRUE ) {
					printf("����Ϊ�գ��޷��鿴ͷԪ�أ�\n");
					break;
				}
				switch(lq->front->next->nodetype) {
					case INT:
						{
							int headElem;
							GetHeadLQueue(lq,&headElem);
							printf("����ͷԪ�سɹ���ͷԪ��Ϊ%d\n",headElem);
							break;
						}
					case CHAR:
						{
							char headElem;
							GetHeadLQueue(lq,&headElem);
							printf("����ͷԪ�سɹ���ͷԪ��Ϊ%c\n",headElem);
							break;
						}
					case DOUBLE:
						{
							double headElem;
							GetHeadLQueue(lq,&headElem);
							printf("����ͷԪ�سɹ���ͷԪ��Ϊ%.2lf\n",headElem);
							break;
						}
					case STRING:
					    {
							char headElem[50];
							GetHeadLQueue(lq,headElem);
							printf("����ͷԪ�سɹ���ͷԪ��Ϊ%s\n",headElem);
							break;
						}
					default :
						printf("ERROR\n");
					
				}
				break;
				
			case 6:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				printf("���г���Ϊ%d\n",LengthLQueue(lq));
				break;	
				
			case 7:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				chooseType(lq);
				printf("������Ҫ��ӵ�����:\n");
				switch (type) {
					case INT: {
						int a;
						int temp;
						fflush(stdin);
						a = scanf("%d",&temp);
		                if (a == 0) {
			            printf("��������ȷ�����֣�\n");
			            continue;
		                }
		                else a = temp;
						EnLQueue(lq,&a);
						printf("��ӳɹ���\n");
						break;	
					}
					case CHAR: {
						char b;
						char temp;
						fflush(stdin);
						b = scanf("%c",&temp);
		                if (b != 1) {
//			            fflush(stdin);
			            printf("��������ȷ�����֣�\n");
			            continue;
		                }
		                else b = temp;
						EnLQueue(lq,&b);
						printf("��ӳɹ���\n");
						break;
					}
					case DOUBLE: {
						double temp;
						double c;
						fflush(stdin);
						c = scanf("%lf",&temp);
		                if (c == 0) {
//			            fflush(stdin);
			            printf("��������ȷ�ĸ������ݣ�\n");
			            continue;
		                }
		                else c = temp;
						EnLQueue(lq,&c);
						printf("��ӳɹ���\n");
						break;
					}
					case STRING: {
						char d[50];
						fflush(stdin);
				  		scanf("%s",d);
				  		EnLQueue(lq,d);
				  		printf("��ӳɹ���\n");
						break;
					}
				  	default:
				  		printf("������1-4\n");break;
				  	}				  
				  	break;
				  	
				  	
			case 8:
				if ( isInit == 0 ) {
				printf("����δ��ʼ����\n");
				break;
				}
				DeLQueue(lq);
				printf("���ӳɹ���\n");
				break;
				
			case 9:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				ClearLQueue(lq);
				printf("��ճɹ���\n");
				break;
				
			case 10:
				if ( isInit == 0 ) {
				printf("����δ��ʼ����\n");
				break;
				}
				TraverseLQueue(lq,LPrint);
				break;
				
			case 11:
				return 0;
		}
	}
	return 0;
}
