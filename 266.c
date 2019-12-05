#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *next;
}NODE;

NODE *creat_NODE(int value)
{
	NODE *new_NODE = malloc(sizeof(NODE));
	new_NODE -> data = value;
	new_NODE -> next = NULL;

	return new_NODE;
}

int add_NODE(NODE *head, int value)
{
	NODE *aux = head;

	while(aux -> next != NULL)
	{
		aux = aux -> next;
	}

	aux -> next = creat_NODE(value);
}

int main()
{
	int num;

	scanf("%d", &num);
	NODE *head = creat_NODE(num);

	while(scanf() != EOF)
	{
		add_NODE(head, num);
	}

	return 0;
}