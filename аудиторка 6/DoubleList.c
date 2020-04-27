#include <stdio.h>
#include <stdlib.h>
/*
struct Complex
{
	double Re;
	double Im;
};
typedef struct Complex COMPLEX;
struct List
{
	COMPLEX entry;
	struct List* next;
};
typedef struct List LIST;
*/
struct DList
{
	float value;
	struct DList* prev;
	struct DList* next;
};
typedef struct DList DLIST;



void outputToRight(DLIST* head)
{
	printf("Output from head : ");
	while (head!=0)
	{
		if(head->next != 0)
			printf("%3.1f ~> ", head->value);
		else
			printf("%3.1f \n", head->value);
		head = head->next;
	}
}
void outputToLeft(DLIST* tail)
{
	printf("Output from tail : ");
	while (tail != 0)
	{
		if(tail->prev != 0)
			printf("%3.1f ~>", tail->value);
		else
			printf("%3.1f \n", tail->value);
		tail = tail->prev;
	}
}
DLIST* addToRight(DLIST* tail, float value_)
{
	tail->next = (DLIST*)malloc(sizeof(DLIST));
	tail->next->value = value_;
	tail->next->next = 0;
	tail->next->prev = tail;
	return tail->next;
}
DLIST* addToLeft(DLIST* head, float value_)
{
	head->prev = (DLIST*)malloc(sizeof(DLIST));
	head->prev->value = value_;
	head->prev->next = head;
	head->prev->prev = 0;
	return head->prev;
}


void addBeforeCurrent(DLIST* current, float value_)
{
	if (current != 0) {

		
		DLIST *currPrev = current->prev;
		if(currPrev!=0){
		currPrev->next = (DLIST*)malloc(sizeof(DLIST));
		currPrev->next->value = value_;
		currPrev->next->next = current;
		currPrev->next->prev = currPrev;
		current->prev = currPrev->next;
		}
		else {
			current->prev = (DLIST*)malloc(sizeof(DLIST));
			current->prev->value = value_;
			current->prev->next = current;
			current->prev->prev = 0;
			((current->prev)->next) = current->prev;
			
		}
			

	}
}

DLIST* findByValue(DLIST* head, float value_)
{
	DLIST* tmp = head;
	while ((tmp) != 0) {

	
		if(((tmp->value) == value_)) return tmp;
		tmp = tmp->next;
	}
	return 0;
}

void addBeforeValue(DLIST* head, float value_, float newValue)
{
	
	DLIST* tmp = head;
	while (findByValue(tmp, value_ )!= 0) {
	
			addBeforeCurrent(findByValue(tmp, value_), newValue);
			tmp = (findByValue(tmp, value_))->next;
	}
			
}

void NewList(DLIST** head, DLIST **tail) {
	*head = (DLIST*)malloc(sizeof(DLIST));
	*tail = (DLIST*)malloc(sizeof(DLIST));
	(*head)->value = 0;
	(*head)->next = (*tail);
	(*head)->prev = 0;
	(*tail)->value = 1;
	(*tail)->prev = (*head);
	(*tail)->next = 0;
}

void FreeList(DLIST* head)
{
	while (head != 0)
	{
		
		head = head->next;
		if(head !=0)
		free(head->prev);
	}
}

int DeleteByValue(DLIST* head, float value_) //можно было реализоать через deleteByPointer и  findByValue
{                                            //но было уже поздно
	DLIST* tmp = head;
	DLIST* tmp2;
	while ((tmp->next) != 0) {


		if (((tmp->value) == value_)) {
			tmp2 = tmp;
			if((tmp->prev!=0)) (tmp->prev)->next = tmp->next;
			if ((tmp->next != 0)) (tmp->next)->prev = tmp->prev;
			
			tmp = tmp->next;
			free(tmp2);
			

		}
		else
		{
           tmp = tmp->next;
		}
		
	}
	return 0;
}

void deleteByPointer(DLIST* tmp) {
	if (tmp != 0) {
		DLIST* tmp2 = tmp;
		if ((tmp->prev != 0)) (tmp->prev)->next = tmp->next;
		if ((tmp->next != 0)) (tmp->next)->prev = tmp->prev;

		tmp = tmp->next;
		free(tmp2);

	}
	
}

void swapTwoElement(DLIST* tmp, DLIST* tmp2) {
	DLIST t;
	t.value = (tmp->value);
	(tmp->value) = (tmp2->value);
	(tmp2->value) = t.value;
}

void splice(DLIST* one, DLIST* left, DLIST* right, DLIST* two, DLIST* position) {
	DLIST* tmp= right;
	while (tmp!=left)
	{
	if(tmp!=right)	addBeforeCurrent((position->next), (tmp->value));
		tmp = tmp->prev;
	}

	tmp = left;
	DLIST* tmp2;
	outputToRight(one);
	outputToRight(two);
	while (tmp != right)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if ((tmp2 != right)&&(tmp2!= left))	deleteByPointer(tmp2);
		
	}
	outputToRight(one);
	outputToRight(two);
}

int main()
{
	DLIST* head, *tail;
	NewList(&head, &tail);


	DLIST* head2, *tail2;
	NewList(&head2, &tail2);


	

	for(int i=2;i<4;++i)
		tail = addToRight(tail, i);
	for (int i = -1; i>-4; --i)
		head = addToLeft(head, i);

	for (int i = 2; i < 4; ++i)
		tail2 = addToRight(tail2, i);
	for (int i = -1; i > -4; --i)
		head2 = addToLeft(head2, i);
	outputToRight(head);
	outputToLeft(tail);

	addBeforeValue(head, 2, -100);
	addBeforeCurrent(findByValue(head, -100), -300);

	outputToRight(head);
	outputToLeft(tail);
	DeleteByValue(head, -100);

	outputToRight(head);
	outputToLeft(tail);

	deleteByPointer(findByValue(head, -300));

	outputToRight(head);
	outputToLeft(tail);

	swapTwoElement((findByValue(head, -3)), (findByValue(head, -2)));

	outputToRight(head);
	outputToLeft(tail);

	splice(head, findByValue(head2, -2), findByValue(head2, 2), head2, findByValue(head, -1));

	system("pause");
	FreeList(head);
	FreeList(head2);
	return 0;
}