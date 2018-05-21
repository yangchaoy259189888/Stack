#include <stdio.h>
#include <malloc.h>

#include "../include/preDefine.h"
#include "../include/mec_stack.h"

//��Ҫ�Դ����һ��ָ���ָ�����޸�ʱ���βξ�Ӧ��Ϊ����ָ��
void initMecStack(MEC_STACK **head, int capacity) {
	if(NULL == head || NULL != *head || capacity <= 0) {	//NULL != *head��ʾ�ܾ��������ͷ����Ϊ*head�Ѿ�ָ����һ������ͷ
		return;
	}

	*head = (MEC_STACK *) malloc(sizeof(MEC_STACK));
	//�޸�head��ָ��Ŀռ���ָ���capacity��top��stack������ֵ 
	(*head)->capacity = capacity;
	(*head)->top = 0;
	//����һ���Ѿ���ʼ�������ҿռ��СΪ sizeof(void *)*capacity��Ķ�ջ�ռ� 
	(*head)->stack = (void **) calloc(sizeof(void *), capacity);
}

//����������Ŀռ�
/*
	����������Ϊ destoryMecStack(MEC_STACK *head)������÷����� destoryMecStack(myStack)
	�����ǰ�ʵ��myStack��ֵ����һ�ݣ���ֵ����Ӧ���βα�������ô������ѿռ�ȫ���ͷ��ˣ�myStack��ֵ��Ȼ��ԭ����ֵ 
*/
void destoryMecStack(MEC_STACK **head) {
	//���ͷŶ�ջ�ռ� 
	free((*head)->stack);
	//���ͷſ���ͷ 
	free(*head);
	//����*head��ֵNULL 
	*head = NULL;
}

//�ж϶�ջ�Ƕ�Ϊ�� 
boolean isMecStackEmpty(MEC_STACK stackCtrl) {
	return 0 == stackCtrl.top;
}

//�ж϶�ջ�Ƿ��� 
boolean isMecStackFull(MEC_STACK stackCtrl) {
	return stackCtrl.top >= stackCtrl.capacity;
}

//��ջ 
boolean push(MEC_STACK *head, void *value) {
	if(NULL == head || NULL == *value || isMecStackFull(*head)) {
		return FALSE;
	}
	
	head->stack[head->top++] = value;
	
	return TRUE;
}

//��ջ 
void *pop(MEC_STACK *head) {
	if(NULL == head || isMecStackEmpty(*head)) {
		return NULL;
	}
	
	return head->stack[--head->top];
}

//��ȡ��ջ��ջ��Ԫ�� 
void *readMecStackTop(MEC_STACK stackCtrl) {
	if(isMecStackEmpty(stackCtrl))  {
		return NULL;
	}
	
	return stackCtrl.stack[stackCtrl.top - 1];
}
