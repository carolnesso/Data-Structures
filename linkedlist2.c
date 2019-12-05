#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *next_NODE;
}NODE;

NODE *creat_NODE(int valor)
{
	NODE *new_NODE = malloc(sizeof(NODE));
	new_NODE -> data = valor;
	new_NODE -> next_NODE = NULL;

	return new_NODE;
}

void add_NODE(int valor, NODE *head)
{
	NODE *aux = head;
	while(aux -> next_NODE != NULL)
	{
		aux = aux -> next_NODE;
	}
	aux -> next_NODE = creat_NODE(valor);
}

NODE *remove_NODE(int valor, NODE *head)
{
	NODE *previous = NULL;
	NODE *current = head;
	while(current != NULL && current -> data != valor)
	{
		previous = current;
		current = current -> next_NODE;
	}

	if (current == NULL)
	{
		return head;
	}

	if (previous == NULL)
	{
		head = current -> next_NODE;
	}

	else
	{
		previous -> next_NODE = current -> next_NODE;
	}

	free(current);
	return head;
}

int main()
{
	free(NULL);
	NODE *head = creat_NODE(2);
	add_NODE(5, head);
	add_NODE(3, head);
	add_NODE(2, head);
	remove_NODE(10, head);

	while(head != NULL)
	{
		printf("%d\n", head -> data);
		head = head -> next_NODE;
	}

	return 0;
}