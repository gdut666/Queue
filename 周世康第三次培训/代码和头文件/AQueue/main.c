#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#include "AQueue.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	showTitle();
	int temp;
	int isInit = 0;
	int choice;
	while (1) {
		showPrompt();
		
		choice = scanf("%d",&temp);
		if (choice == 0) {
			fflush(stdin);
			printf("��������ȷ�����֣�\n");
			continue;
		}
		else choice = temp;
		
		switch (choice) {
			case 1:
				if (isInit == 1) {
					printf("��ʼ��ʧ�ܣ� ԭ��:�����ѳ�ʼ����\n");
					break;
				}
				isInit = 1;
				AQueue *aq = (AQueue *)malloc(sizeof(AQueue));
				InitAQueue(aq);
				printf("���г�ʼ���ɹ���\n");
				break;
				
			case 2:
				if ( isInit == 0 ) {
					printf("���ٶ���ʧ�ܣ�ԭ��:����δ��ʼ����\n");
					break;
				}
				isInit = 0;
				DestoryAQueue(aq);
				printf("���ٶ��гɹ���\n");
				break;
				
			case 3:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				if ( IsFullAQueue(aq) ) printf("����������");
				else printf("����δ����\n");
				break;
				
			case 4:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				if ( IsEmptyAQueue(aq) ) printf("����Ϊ�գ�\n");
				else printf("����δ�գ�\n");
				break;
				
			case 5:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				switch(datatypeArray[aq->front]) {
					case INT:
						{
							int headElem;
							GetHeadAQueue(aq,&headElem);
							printf("����ͷԪ�سɹ���ͷԪ��Ϊ%d\n",headElem);
							break;
						}
					case CHAR:
						{
							char headElem;
							GetHeadAQueue(aq,&headElem);
							printf("����ͷԪ�سɹ���ͷԪ��Ϊ%c\n",headElem);
							break;
						}
					case DOUBLE:
						{
							double headElem;
							GetHeadAQueue(aq,&headElem);
							printf("����ͷԪ�سɹ���ͷԪ��Ϊ%.2lf\n",headElem);
							break;
						}
					case STRING:
					    {
							char headElem[50];
							GetHeadAQueue(aq,headElem);
							printf("����ͷԪ�سɹ���ͷԪ��Ϊ%s\n",headElem);
							break;
						}
					default :
						printf("ERROR\n");
					
				}
//				int *headElem;
//				if ( GetHeadAQueue(aq,&headElem) ) {
//					printf("����ͷԪ�سɹ���ͷԪ��Ϊ%d\n",headElem);
//				}
//				else printf("����ͷԪ��ʧ�ܣ�\n");
				break;
				
			case 6:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				printf("���г���Ϊ%d\n",LengthAQueue(aq));
				break;
				
			case 7:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				chooseType(aq);
				printf("������Ҫ��ӵ�����:\n");
				switch (datatype) {
					case INT: {
						int a;
						fflush(stdin);
						a = scanf("%d",&temp);
		                if (a == 0) {
//			            fflush(stdin);
			            printf("��������ȷ�����֣�\n");
			            continue;
		                }
		                else a = temp;
						EnAQueue(aq,&a);
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
						EnAQueue(aq,&b);
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
						EnAQueue(aq,&c);
						printf("��ӳɹ���\n");
						break;
					}
					case STRING: {
						char d[50];
						fflush(stdin);
				  		scanf("%s",d);
				  		EnAQueue(aq,d);
				  		printf("��ӳɹ���\n");
						break;
					}
				  	default:
				  		printf("������1-4\n");break;
				  	}
				  	
				datatypeArray[aq->rear-1] = datatype; 
				break;
				
			case 8:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				DeAQueue(aq);
				break;
			case 9:
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				ClearAQueue(aq);
				break;
				
			case 10:{
				if ( isInit == 0 ) {
					printf("����δ��ʼ����\n");
					break;
				}
				TraverseAQueue(aq,APrint);
				break;}
				
			case 11:
				return 0;
		}
	}
}



