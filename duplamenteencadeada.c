#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *next;
	struct NODE *previous;
}NODE;

NODE *creat(int number)
{
	NODE *new_NODE = malloc(sizeof(NODE));
	new_NODE -> data = number;
	new_NODE -> next = NULL;
	new_NODE -> previous = NULL;
	if (head != NULL)
	{
		head -> previous = new_NODE;
		return new_NODE;
	}
}

int main()
{
	NODE *head = creat();
	return 0;
}
