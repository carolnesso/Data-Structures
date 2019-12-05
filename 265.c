#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
	char letter;
	int data;
	struct NODE *next;
}NODE;

NODE *creat_NODE(char frase[], int j, int value)
{
	NODE *new_NODE = malloc(sizeof(NODE));
	new_NODE -> letter = frase[j];
	new_NODE -> data = value;
	new_NODE -> next = NULL;

	return new_NODE;
}

int add_NODE(NODE **head, char frase[], int j, int value)
{
	NODE *aux = *head;
	NODE *new_NODE = creat_NODE(frase, j, value);
	new_NODE -> next = *head;
	*head = new_NODE;
}

void order(char frase[], int i)
{
	int j, k;

	for (j = 0; j < i; ++j)
	{
		for (k = 0; k < i; ++k)
		{
			if (frase[k] > frase[j])
			{
				int aux = frase[k];
				frase[k] = frase[j];
				frase[j] = aux;
			}
		}
	}

}

int counting_letters(char frase[], int i, NODE **head)
{
	int cont = 1, j = 0, k;

	for (k = 1; k <= i; ++k)
	{
		if (frase[j] == frase[k])
		{
			cont++;
		}

		else
		{
			if (*head == NULL)
			{
				*head = creat_NODE(frase , j, cont);
				j = k;
				cont = 1;
			}

			else
			{
				add_NODE(head, frase, j ,cont);
				j = k;
				cont = 1;
			}
		}
	}

}

int main()
{
	NODE *head = NULL;

	char frase[1000];

	scanf("%[^\n]", frase);

	int i = strlen(frase);

	order(frase, i);
	counting_letters(frase, i, &head);

	while(head != NULL)
	{
		printf("%c %d\n", head -> letter, head -> data);
		head = head -> next;
	}

	return 0;
}