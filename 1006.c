#include <stdio.h>

void subtracao(int a, int b, int numb)
{
	if ((b*b)-(a*a)==numb)
	{
		printf("%d - %d\n", (b*b), (a*a));
	}
	else
	{
		a++;
		b++;
		subtracao(a, b, numb);
	}
}
void ler_numeros()
{
	int numb;
	scanf("%d", &numb);
	if (numb!=0)
	{
		subtracao(1, 2, numb);
		ler_numeros();
	}
}
int main(int argc, char const *argv[])
{
	ler_numeros();
	return 0;
}