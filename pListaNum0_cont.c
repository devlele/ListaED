/*
	Versao inicial do programa da lista linear de números
	implementada por CONTIGUIDADE.
	É a versão equivalente (agora por contiguidade) daquela 
	(por encadeamento) encontrada no arquivo 63_ED-ListasLineares.pdf
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO	50

int main(void)
{	int numero, final, cont;
	int lista[MAXIMO];

	/* inicializando a variável inicio com um endereco vazio */
	final = 0;
	
	while (1)
	{	printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		lista[final] = numero;
		final = final + 1;
	}

	/* imprimindo os valores da lista */
	printf("\n\n\nConteudo da lista:\n");
	cont = 0;
	while (cont != final)
	{	printf("%d\n", lista[cont]);
		cont = cont + 1;
	}
	
	return 0;
}
