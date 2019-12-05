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

int main()
{

	NODE *head = creat_NODE(2);
	add_NODE(5, head);
	add_NODE(3, head);
	add_NODE(2, head);

	while(head != NULL)
	{
		printf("%d\n", head -> data);
		head = head -> next_NODE;
	}

	return 0;
}