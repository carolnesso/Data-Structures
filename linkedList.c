#include <stdio.h>
#include <stdlib.h>//possui algumas funcoes do tipo malloc

/*typedef serve para dar o nome da nossa struct do tipo batata
o nome dela sera inserido apos a ultima chave que o define e antes do ponto e virgula*/
typedef struct batata
{
	int data;//inteiro que ira armazenar os valores da linked list
	struct batata *next;//nao foi definido o nome NODE, entao usa-se o o nome sem abreviação
}NODE;

NODE* creat_node(int value)
{
	NODE *new_node = malloc(sizeof(NODE));/*o ponteiro new_node ira apontar para a estrutura
	que recebe o alocamento de memoria do tamanho da estrutura, que no caso sera a NODE*/
	new_node->data = value;//new_node ira apontar para a data do NODE e atribuir um valor a ela
	new_node->next = NULL;//o next_node ira receber o NULL
	return new_node;//ira retornar o NODE para a main
}

void add_node(NODE *head, int value)
{
	NODE *aux = head;/*ponteiro aux aponta para o NODE que recebe o head, em seguida iremos pro while
	em que nesse while o aux vai apontar para o next, que enquanto for diferente de NULL ele ira
	executar*/
	while(aux->next != NULL)
	{
		aux = aux->next;/*na execuçao, o aux ira receber aux que aponta para o next*/
	}
	aux->next = creat_node(value);/*quando o while parar, aux que aponta para o next ira receber
	o retorno da funçao, que sera a criacao de um novo NODE*/
}

int main(void)
{	
	NODE *head = creat_node(14);//NODE entra como tipo do ponteiro, como se fosse int ou char...
	/*logo, o ponteiro head aponta para o NODE, que recebe o retorno da funcao creat_node
	que passa como parametro o valor 14, para a primeira DATA, nosso inteiro na struct*/
	add_node(head,4);/*o passo anterior quase que se repete, so que ele ira chamar a funcao add_node
	passamos o head e o value como parametro*/
	add_node(head,5);
	add_node(head,10);

	while(head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}

//	free(a);
}