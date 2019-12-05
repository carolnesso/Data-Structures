#include <stdio.h>
#include <stdlib.h>

typedef struct seats
{
	int data;
	struct seats *next_node;
}NODE;

NODE *creat_node(int number)
{
	NODE *new_node = malloc(sizeof(NODE));
	new_node->data = number;
	new_node->next_node = NULL;
	return new_node;
}

NODE *add_node(NODE *head, int number)
{
	//serve para adicionar um novo node no inicio;
	// NODE *aux = head;
	// NODE *new_node = creat_node(number);
	// head = new_node;
	// next_node->next_node = aux;
	NODE *aux = head;
	while(aux->next_node != NULL)
	{
		aux = aux->next_node;
	}
	aux->next_node = creat_node(number);
}

int main()
{
	NODE *head = creat_node(540);
	add_node(head, 370);
	add_node(head, 290);
	add_node(head, 189);
	while(head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next_node;
	}
	return 0;
}