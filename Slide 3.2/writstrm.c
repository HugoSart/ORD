/* cria arquivo de nomes e endere�os organizado
como uma sequ�ncia (stream) de bytes.
Os campos s�o delimitados por | */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DELIM_STR "|"

int main() {
    char first[30], last[30], address[30], city[20], state[15], zip[9];
    char filename[15];
    FILE* fd;

    printf("Entre com o nome do arquivo a ser criado: ");
    fgets(filename, 15, stdin);
    filename[strlen(filename)-1] = '\0';
    fflush(stdin);	//necessario para o caso do nome digitado ser maior do que o que foi lido
    				//na verdade, precisaria desse flush depois de todas as leituras

    if ((fd = fopen(filename,"w")) == NULL) {
        printf("Erro na cria��o do arquivo --- programa abortado\n");
        exit(1);
    }

    printf("\n\nDigite o Sobrenome, ou <ENTER> para sair\n>>>");
    fgets(last, 30, stdin);
    last[strlen(last)-1] = '\0';

    while(strlen(last) > 1) {
        printf("\nPrimeiro nome\n>>>");
        fgets(first, 30, stdin);
        first[strlen(first)-1] = '\0';
        printf("\nEndereco\n>>>");
        fgets(address, 30, stdin);
        address[strlen(address)-1] = '\0';
        printf("\nCidade\n>>>");
        fgets(city, 20, stdin);
        city[strlen(city)-1] = '\0';
		    printf("\nEstado\n>>>");
        fgets(state, 15, stdin);
        state[strlen(state)-1] = '\0';
        printf("\nCEP\n>>>");
        fgets(zip, 9, stdin);
        zip[strlen(zip)-1] = '\0';

        fprintf(fd, "%s | %s | %s | %s | %s | %s\n", last, first, address, city, state, zip);

        /* come�a a pr�xima entrada */
        printf("\n\nDigite o Sobrenome, ou <ENTER> para sair\n>>>");
        fgets(last, 30, stdin);
        last[strlen(last)-1] = '\0';
    }

    /* fechar o arquivo */
    fclose(fd);
}
