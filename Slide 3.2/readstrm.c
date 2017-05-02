#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char file_name[30];

    printf("Nome do arquivo a ser lido: ");
    scanf("%[^\n]", file_name);

    FILE *file = fopen(file_name, "r");

    if (!file) {
        printf("ERROR: Nome invalido!\n");
        exit(1);
    }

    char name[30], last_name[30], address[30], city[30], state[30], zip[30], c;
    while (fscanf(file, "%s | %s | %s | %s | %s | %s\n", last_name, name, address, city, state, zip) != EOF) {
        printf("\nRegistro de: %s %s\n", name, last_name);
        printf("  Endereco: %s\n", address);
        printf("  Cidade: %s\n", city);
        printf("  Estado: %s\n", state);
        printf("  Codigo-postal: %s\n", zip);
    }

    fclose(file);

    return 0;

}

