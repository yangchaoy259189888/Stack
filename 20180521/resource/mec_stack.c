#include <stdio.h>
#include <malloc.h>

#include "../include/preDefine.h"
#include "../include/mec_stack.h"

//需要对传入的一级指针的指向作修改时，形参就应该为二级指针
void initMecStack(MEC_STACK **head, int capacity) {
	if(NULL == head || NULL != *head || capacity <= 0) {	//NULL != *head表示拒绝申请控制头，因为*head已经指向了一个控制头
		return;
	}

	*head = (MEC_STACK *) malloc(sizeof(MEC_STACK));
	//修改head所指向的空间所指向的capacity，top，stack变量的值 
	(*head)->capacity = capacity;
	(*head)->top = 0;
	//申请一个已经初始化，并且空间大小为 sizeof(void *)*capacity大的堆栈空间 
	(*head)->stack = (void **) calloc(sizeof(void *), capacity);
}

//销毁所申请的空间
/*
	若声明销毁为 destoryMecStack(MEC_STACK *head)，则调用方法是 destoryMecStack(myStack)
	这样是把实参myStack的值复制一份，赋值给相应的形参变量；那么，就算把空间全部释放了，myStack的值依然是原来的值 
*/
void destoryMecStack(MEC_STACK **head) {
	//先释放堆栈空间 
	free((*head)->stack);
	//在释放控制头 
	free(*head);
	//最后给*head赋值NULL 
	*head = NULL;
}

//判断堆栈是都为空 
boolean isMecStackEmpty(MEC_STACK stackCtrl) {
	return 0 == stackCtrl.top;
}

//判断堆栈是否满 
boolean isMecStackFull(MEC_STACK stackCtrl) {
	return stackCtrl.top >= stackCtrl.capacity;
}

//入栈 
boolean push(MEC_STACK *head, void *value) {
	if(NULL == head || NULL == *value || isMecStackFull(*head)) {
		return FALSE;
	}
	
	head->stack[head->top++] = value;
	
	return TRUE;
}

//出栈 
void *pop(MEC_STACK *head) {
	if(NULL == head || isMecStackEmpty(*head)) {
		return NULL;
	}
	
	return head->stack[--head->top];
}

//读取堆栈的栈顶元素 
void *readMecStackTop(MEC_STACK stackCtrl) {
	if(isMecStackEmpty(stackCtrl))  {
		return NULL;
	}
	
	return stackCtrl.stack[stackCtrl.top - 1];
}
