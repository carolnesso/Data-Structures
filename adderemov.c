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

void add_NODE(int value, NODE *head)
{
	NODE *aux = head;

	while(aux -> next != NULL)
	{
		aux = aux -> next;
	}

	aux -> next = creat_NODE(value);
}

NODE *remove_NODE(int value, NODE **head)
{
	NODE *aux = *head;
	NODE *previous = NULL;
	NODE *current = aux;

	while(current != NULL && current -> data != value)
	{
		previous = current;
		current = current -> next;
	}

	if (current == NULL)
	{
		return aux;
	}

	if (previous == NULL)
	{
		*head = current -> next;
	}

	else
	{
		previous -> next = current -> next;
	}

	free(current);
	return aux;
}


int main()
{
	int value;
	
	scanf("%d", &value);
	NODE *head = creat_NODE(value);

	while(value != -1)
	{
		scanf("%d", &value);

		if (value!=-1)
		{
			add_NODE(value, head);
		}
	}

	NODE *aux = head;

	while(aux != NULL)
	{
		printf("%d ", aux -> data);
		aux = aux -> next;
	}

	printf("Qual numero deseja excluir?\n")
;	scanf("%d", &value);

	remove_NODE(value, &head);

	while(head != NULL)
	{
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");

	return 0;
}