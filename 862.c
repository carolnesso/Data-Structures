#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int num;
	int data;
	struct NODE *next;
}NODE;

NODE *creat_NODE(int value, int i)
{
	NODE *new_NODE = malloc(sizeof(NODE));
	new_NODE -> data = value;
	new_NODE -> next = NULL;

	return new_NODE;
}

void add_NODE(NODE *head, int value, int i)
{
	NODE *aux = head;

	while(aux -> next != NULL)
	{
		aux = aux -> next;
	}

	aux -> next = creat_NODE(value, i);
}

int frequency(NODE *head, int k)
{

	int cont = 0, cont_MAX = 0;

	while(head != NULL)
	{
		if (head -> data == k)
		{
			cont++;
		}

		if (cont > cont_MAX)
		{
			/* code */
		}
	}
}

int main()
{
	int num, k;
	int i = 0;
	scanf("%d", &num);

	NODE *head = creat_NODE(num, i);

	while(scanf("%d", &num) != EOF)
	{
		add_NODE(head, num, i++);
	}

	scanf("%d", &k);

	frequency(head, k);

	while(head != NULL)
	{
		printf("%d %d\n", i,head -> data);
		head = head -> next;
	}

	return 0;
}