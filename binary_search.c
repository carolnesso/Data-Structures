#include <stdio.h>

int binary_search(int a[], int b, int e)
{
	int m = 0;
	while(b<=e)
	{
		m = (b+e)/2;
		if (a[m]==15)
		{
			return m;
		}
		if (a[m]>15)
		{
			e = m;
		}
		else
		{
			b = m;
		}
	}
	return -1;
}

int linear_search(int a[], int e)
{
	int i = 0;
	while(i!=e)
	{
		if (a[i]==15)
		{
			return i;
		}
		i++;
	}
}

int main()
{
	int a[8];
	for (int i = 0; i < 8; ++i)
	{
		scanf("%d", &a[i]);
	}
	// int lr = linear_search(a, 8);
	// printf("%d\n", lr+1);
	int br = binary_search(a, 0, 8);
	printf("%d\n", br+1);
}