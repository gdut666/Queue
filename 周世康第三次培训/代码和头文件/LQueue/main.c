#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include "LQueue.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("\t\t------------------------周世康的LQueue-----------------------\n\n\n");	

	int choice;  //操作的选择     0<choice< 
	int temp1;
	int isInit = 0;
	
	while (1) {
		showPrompt();
		
		choice = scanf("%d",&temp1);		//输入选择 
		if (choice == 0) {				
			fflush(stdin);
			printf("请输入正确的数字！\n");
			continue;
		}
		else choice = temp1;
		
		switch(choice) {
			case 1:
				if (isInit == 1) {
					printf("初始化失败！ 原因:队列已初始化！\n");
					break;
				}
				
				isInit = 1;
				LQueue *lq = (LQueue *)malloc(sizeof(LQueue));
				InitLQueue(lq);
				printf("队列初始化成功！\n");
				break;
				
			case 2:
				if ( isInit == 0 ) {
					printf("销毁队列失败！原因:队列未初始化！\n");
					break;
				}
				isInit = 0;
				DestoryLQueue(lq);
				printf("销毁成功！\n");
				break;
				
			case 3:
				break;
				
				
			case 4:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				if ( IsEmptyLQueue(lq) ) printf("队列为空！\n");
				else printf("队列未空！\n");
				break;
				
			case 5:
				if ( isInit == 0 ) {
				printf("队列未初始化！\n");
				break;
				}
				if ( IsEmptyLQueue(lq) == TRUE ) {
					printf("队列为空！无法查看头元素！\n");
					break;
				}
				switch(lq->front->next->nodetype) {
					case INT:
						{
							int headElem;
							GetHeadLQueue(lq,&headElem);
							printf("查找头元素成功！头元素为%d\n",headElem);
							break;
						}
					case CHAR:
						{
							char headElem;
							GetHeadLQueue(lq,&headElem);
							printf("查找头元素成功！头元素为%c\n",headElem);
							break;
						}
					case DOUBLE:
						{
							double headElem;
							GetHeadLQueue(lq,&headElem);
							printf("查找头元素成功！头元素为%.2lf\n",headElem);
							break;
						}
					case STRING:
					    {
							char headElem[50];
							GetHeadLQueue(lq,headElem);
							printf("查找头元素成功！头元素为%s\n",headElem);
							break;
						}
					default :
						printf("ERROR\n");
					
				}
				break;
				
			case 6:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				printf("队列长度为%d\n",LengthLQueue(lq));
				break;	
				
			case 7:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				chooseType(lq);
				printf("请输入要入队的数据:\n");
				switch (type) {
					case INT: {
						int a;
						int temp;
						fflush(stdin);
						a = scanf("%d",&temp);
		                if (a == 0) {
			            printf("请输入正确的数字！\n");
			            continue;
		                }
		                else a = temp;
						EnLQueue(lq,&a);
						printf("入队成功！\n");
						break;	
					}
					case CHAR: {
						char b;
						char temp;
						fflush(stdin);
						b = scanf("%c",&temp);
		                if (b != 1) {
//			            fflush(stdin);
			            printf("请输入正确的数字！\n");
			            continue;
		                }
		                else b = temp;
						EnLQueue(lq,&b);
						printf("入队成功！\n");
						break;
					}
					case DOUBLE: {
						double temp;
						double c;
						fflush(stdin);
						c = scanf("%lf",&temp);
		                if (c == 0) {
//			            fflush(stdin);
			            printf("请输入正确的浮点数据！\n");
			            continue;
		                }
		                else c = temp;
						EnLQueue(lq,&c);
						printf("入队成功！\n");
						break;
					}
					case STRING: {
						char d[50];
						fflush(stdin);
				  		scanf("%s",d);
				  		EnLQueue(lq,d);
				  		printf("入队成功！\n");
						break;
					}
				  	default:
				  		printf("请输入1-4\n");break;
				  	}				  
				  	break;
				  	
				  	
			case 8:
				if ( isInit == 0 ) {
				printf("队列未初始化！\n");
				break;
				}
				DeLQueue(lq);
				printf("出队成功！\n");
				break;
				
			case 9:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				ClearLQueue(lq);
				printf("清空成功！\n");
				break;
				
			case 10:
				if ( isInit == 0 ) {
				printf("队列未初始化！\n");
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
