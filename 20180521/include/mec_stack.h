#ifndef _MEC_STACK_H_
#define _MEC_STACK_H_

//定义一个控制头
typedef struct MEC_STACK {
	int *stack;
	int capacity;
	int top;
}MEC_STACK;

void initMecStack(MEC_STACK **head, int capacity);
void destoryMecStack(MEC_STACK ** head);
boolean isMecStackEmpty(MEC_STACK stackCtrl);
boolean isMecStackFull(MEC_STACK stackCtrl);
boolean push(MEC_STACK *head, void *value);
void *pop(MEC_STACK *head);
void *readMecStackTop(MEC_STACK stackCtrl);

#endif

