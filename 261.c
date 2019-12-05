#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	int cont;
	struct NODE *next;
}NODE;

NODE *create_NODE(int value)
{
	NODE *new_NODE = malloc(sizeof(NODE));
	new_NODE -> data = value;
	new_NODE -> next = NULL;
	new_NODE -> cont = 0;

	return new_NODE;
}

int add_NODE(NODE *head, int value)
{
	NODE *aux = head;

	while(aux -> next != NULL)
	{
		aux = aux -> next;
	}

	aux -> next = create_NODE(value);
}

int compare_lists(NODE *head_a, NODE *head_b)
{
	int cont = 0;

	NODE *aux_a = head_a;
	NODE *aux_b = head_b;

	while (aux_a != NULL)
	{
		while(aux_b != NULL)
		{
			if (aux_a -> data == aux_b -> data)
			{
				aux_b -> cont++;
			}

			aux_b = aux_b -> next;
		}

		aux_b = head_b;
		aux_a = aux_a -> next;
	}

	return cont;
}

int main()
{
	int a, b, va, vb;

	int i = 1;

	scanf("%d", &a);
	scanf("%d", &va);

	NODE *head_a = create_NODE(va);

	while(i < a)
	{
		scanf("%d", &va);
		add_NODE(head_a, va);	
		i++;	
	}

	i = 1;

	scanf("%d", &b);
	scanf("%d", &vb);

	NODE *head_b = create_NODE(vb);

	while(i < b)
	{
		scanf("%d", &vb);
		add_NODE(head_b, vb);
		i++;
	}

	int result = compare_lists(head_a, head_b);

	while(head_b != NULL)
	{
		if (head_b -> cont == 0)
		{
			printf("0\n");
			return 0;
		}

		head_b = head_b -> next;
	}

	printf("1\n");

	return 0;
}