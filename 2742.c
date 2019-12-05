#include <stdio.h>

int looking_for(int array[], int money, int d_i)
{
	int cont = 0, aux = 0;

	for (int i = 0; i < money; ++i)
	{
		if (array[i] == array[d_i])
		{
			cont += 1;
		}
	}

	if (cont == 1)
	{
		cont = d_i; 
	}

	else if (cont < 1)
	{
		cont = 
	}

	printf("%d %d\n", d_i, cont);
}

int binary_search(int array[], int begin, int end, int x)
{
	int medium = 0;

	while(begin <= end)
	{
		medium = (begin + end)/2;

		if (array[medium] == x)
		{
			return medium;
		}

		else if (array[medium] > x)
		{
			end = medium;
		}

		else 
		{
			begin = medium;
		}	
	}
	return begin;
}

int main()
{
	int result, money, numbers, x;
	int j = 1;

	scanf("%d", &money);

	int array[money];//the array content the all money in order

	for (int i = 0; i < money; ++i)
	{//represenr the list of money 
		scanf("%d", &array[i]);
	}

	scanf("%d",&numbers);

	while(j <= numbers)
	{
		scanf("%d", &x);
		int d_i = binary_search(array, 0, money-1, x);
		printf("%d\n", d_i);
		looking_for(array, money, d_i);
		j++;
	}

	return 0;
}