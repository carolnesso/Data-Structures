#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define max 100000

typedef struct binary_tree
{
	int data;
	struct binary_tree *left;
	struct binary_tree *right;

}binary_tree;

binary_tree *create_binary_tree(int value)
{
	binary_tree *new_tree = malloc(sizeof(binary_tree));
	new_tree -> data = value;
	new_tree -> left = NULL;
	new_tree -> right = NULL;

	return new_tree;
}

int is_empty(binary_tree *root)
{
	if (root == NULL)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

binary_tree *read_tree(char c, binary_tree *new_tree)
{
	if (c == '(')
	{
		scanf("%c", &c);

		if (c == ')')
		{
			return NULL;
		}

		else
		{
			int i = 0;
			char p[5];
			while(c != '(')
			{
				p[i] = c;
				scanf("%c", &c);
				i++;
			}
			p[i] = '\0';

			int value = atoi(p);

			new_tree = create_binary_tree(value);

			new_tree -> left = read_tree(c, new_tree);

			scanf("%c", &c);

			new_tree -> right = read_tree(c, new_tree);
		}

		scanf("%c", &c);
	}

	return new_tree;
}

int is_leaf(binary_tree *root)
{
	if (root -> left == NULL && root -> right == NULL)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void concate(binary_tree *matriz, binary_tree *bt2)
{
	if(matriz != NULL)
	{
		if (matriz -> data == bt2 -> data && is_leaf(matriz))
		{
			matriz -> left = bt2 -> left;
			matriz -> right = bt2 -> right;
		}

		else
		{
			concate(matriz -> left, bt2);
			concate(matriz -> right, bt2);
		}
	}
}

void print_pre_order(binary_tree *bt)
{
	printf("(");

	if (!is_empty(bt))
	{
		printf("%d", bt -> data);
		print_pre_order(bt -> left);
		print_pre_order(bt -> right);
	}

	printf(")");
}

int main(int argc, char const *argv[])
{
	char open;

	scanf("%c", &open);

	binary_tree *bt = read_tree(open, NULL);

	scanf(" %c", &open);

	binary_tree *bt2 = read_tree(open, NULL);

	while(bt2 != NULL)
	{
		concate(bt, bt2);

		scanf(" %c", &open);

		bt2 = read_tree(open, NULL);

		// print_pre_order(bt);
		// printf("\n");
		// print_pre_order(bt2);
		// printf("\n");
	}

	print_pre_order(bt);
	printf("\n");

	return 0;
}