#include <stdio.h>

int selection_sort(int array[], int n)
{
	int min, aux;

	for (int i = 0; i < (n - 1); ++i)
	{
		min = i;//min sera o primeiro num. nao ordenado
		for (int j = i + 1; j < n; ++j)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
			if (i != min)
			{
				aux = array[i];
				array[i] = array[min];
				array[min] = aux;
			}
		}
	}

	for (int j = 0; j < 10; ++j)
	{
		printf("%d ", array[j]);
	}
	printf("\n");
}

int main()
{
	int array[10];

	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &array[i]);
	}

	selection_sort(array, 10);
	return 0;
}