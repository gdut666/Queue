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
			printf("请输入正确的数字！\n");
			continue;
		}
		else choice = temp;
		
		switch (choice) {
			case 1:
				if (isInit == 1) {
					printf("初始化失败！ 原因:队列已初始化！\n");
					break;
				}
				isInit = 1;
				AQueue *aq = (AQueue *)malloc(sizeof(AQueue));
				InitAQueue(aq);
				printf("队列初始化成功！\n");
				break;
				
			case 2:
				if ( isInit == 0 ) {
					printf("销毁队列失败！原因:队列未初始化！\n");
					break;
				}
				isInit = 0;
				DestoryAQueue(aq);
				printf("销毁队列成功！\n");
				break;
				
			case 3:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				if ( IsFullAQueue(aq) ) printf("队列已满！");
				else printf("队列未满！\n");
				break;
				
			case 4:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				if ( IsEmptyAQueue(aq) ) printf("队列为空！\n");
				else printf("队列未空！\n");
				break;
				
			case 5:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				switch(datatypeArray[aq->front]) {
					case INT:
						{
							int headElem;
							GetHeadAQueue(aq,&headElem);
							printf("查找头元素成功！头元素为%d\n",headElem);
							break;
						}
					case CHAR:
						{
							char headElem;
							GetHeadAQueue(aq,&headElem);
							printf("查找头元素成功！头元素为%c\n",headElem);
							break;
						}
					case DOUBLE:
						{
							double headElem;
							GetHeadAQueue(aq,&headElem);
							printf("查找头元素成功！头元素为%.2lf\n",headElem);
							break;
						}
					case STRING:
					    {
							char headElem[50];
							GetHeadAQueue(aq,headElem);
							printf("查找头元素成功！头元素为%s\n",headElem);
							break;
						}
					default :
						printf("ERROR\n");
					
				}
//				int *headElem;
//				if ( GetHeadAQueue(aq,&headElem) ) {
//					printf("查找头元素成功！头元素为%d\n",headElem);
//				}
//				else printf("查找头元素失败！\n");
				break;
				
			case 6:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				printf("队列长度为%d\n",LengthAQueue(aq));
				break;
				
			case 7:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				chooseType(aq);
				printf("请输入要入队的数据:\n");
				switch (datatype) {
					case INT: {
						int a;
						fflush(stdin);
						a = scanf("%d",&temp);
		                if (a == 0) {
//			            fflush(stdin);
			            printf("请输入正确的数字！\n");
			            continue;
		                }
		                else a = temp;
						EnAQueue(aq,&a);
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
						EnAQueue(aq,&b);
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
						EnAQueue(aq,&c);
						printf("入队成功！\n");
						break;
					}
					case STRING: {
						char d[50];
						fflush(stdin);
				  		scanf("%s",d);
				  		EnAQueue(aq,d);
				  		printf("入队成功！\n");
						break;
					}
				  	default:
				  		printf("请输入1-4\n");break;
				  	}
				  	
				datatypeArray[aq->rear-1] = datatype; 
				break;
				
			case 8:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				DeAQueue(aq);
				break;
			case 9:
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				ClearAQueue(aq);
				break;
				
			case 10:{
				if ( isInit == 0 ) {
					printf("队列未初始化！\n");
					break;
				}
				TraverseAQueue(aq,APrint);
				break;}
				
			case 11:
				return 0;
		}
	}
}



