#include <stdio.h>

int summation(int florest[], int n_tree, int mid)
{
	int i;
	int sum = 0;

	for (i = mid + 1; i < n_tree; ++i)
	{
		sum += florest[i] - florest[mid];
	}

	return sum;
}

int binary_search(int florest[], int n_tree, int begin, int end, int wood)
{
	int mid;
	int s = 0;

	while(begin <= end)
	{
		mid = (begin + end + 1)/2;
		
		s = summation(florest, n_tree, mid);
	
		if (begin == end)
		{
			return mid;
		}

		if (s == wood)
		{
			return mid;
		}

		else if (s < wood)
		{
			end = mid-1;
		}

		else
		{
			begin = mid;
		}

	}

	return -1;
}

void order(int florest[], int n_tree)
{
	int aux, i, j;

	for (i = 0; i < n_tree; ++i)
	{
		for (j = i; j < n_tree; ++j)
		{
			if (florest[i] > florest[j])
			{
				aux = florest[j];
				florest[j] = florest[i];
				florest[i] = aux;
			}
		}
	}

}

int main(void)
{
	int n_tree, wood, i, result;

	scanf("%d %d", &n_tree, &wood);

	int florest[n_tree];

	for (i = 0; i < n_tree; ++i)
	{
		scanf("%d", &florest[i]);
	}

	order(florest, n_tree);
	result = binary_search(florest, n_tree, 0, n_tree-1, wood);

	printf("%d\n", florest[result]);

	return 0;
}