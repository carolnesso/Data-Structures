#include <stdio.h>

void quick_sort(int vetor[], int begin, int end)
{
	if (begin >= end)
	{
		for (int i = 0; i < 10; ++i)
		{
			printf("%d\n", vetor[i]);
		}
		return;
	}

	else
	{
		int pivo = (begin + end)/2;
		int var = vetor[pivo];
		int a = begin;
		int b = end;

		while(a < b)
		{
			while(vetor[a++] <= var);
			while(vetor[b--] >= var);
			if (a < b)
			{
				b += a;
				a = b - a;
				b -= a;
			}
		}
		
		quick_sort(vetor, begin, pivo - 1);
		quick_sort(vetor, pivo + 1, end);

	}
}

int main()
{
	int a[10];

	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &a[i]);
	}

	quick_sort(a, 0, 9);

	return 0;
}