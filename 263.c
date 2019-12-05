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

int check_it(int result[], int value, int i)
{
	int j;

	for (j = 0; j < i; ++j)
	{
		if (result[j] == value)
		{
			return 0;
		}
	}

	return 1;
}

int compare_lists(NODE *head_a, NODE *head_b, int result[])
{
	NODE *aux_a = head_a;
	NODE *aux_b = head_b;
	int i = 0;

	while(aux_a != NULL)
	{
		while(aux_b != NULL)
		{

			if (aux_a -> data == aux_b -> data)
			{
				if (check_it(result, aux_a ->data, i))
				{
					result[i] = aux_a -> data;
					i++;
				}
			}

			aux_b = aux_b -> next;
		}

		aux_b = head_b;
		aux_a = aux_a -> next;
	}

	return i;
}

int main()
{
	int i = 1, j, va, vb;

	scanf("%d", &va);

	NODE *head_a = creat_NODE(va);

	while(i < 20)
	{
		scanf("%d", &va);
		add_NODE(head_a, va);
		i++;
	}

	i = 1;

	scanf("%d", &vb);

	NODE *head_b = creat_NODE(vb);

	while(i < 20)
	{
		scanf("%d", &vb);
		add_NODE(head_b, vb);
		i++;
	}

	int result[20];

	i = 0;
	int k, l;

	i = compare_lists(head_a, head_b, result);

	if (i != 0)
	{
		for (k = 0; k < i; ++k)
		{
			for (l = 0; l < i; ++l)
			{
				if (result[l] > result[k])
				{
					int aux = result[l];
					result[l] = result[k];
					result[k] = aux;
				}
			}
		}
		for (j = 0; j < i; ++j)
		{
			printf("%d\n", result[j]);
		}
	}

	else
	{
		printf("VAZIO\n");
	}

	return 0;
}