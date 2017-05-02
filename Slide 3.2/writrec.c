#include <stdio.h>
#include <string.h>

int main() {

    char buffer[200];

    char file_name[30], last_name[30], name[30], address[30], city[30], state[30], zip[30];

    printf("=========== Writerec ===========\n\n");

    printf("  Nome do arquivo de saida: ");
    __fpurge(stdin);    scanf("%[^\n]", file_name);
    FILE *file = fopen(file_name, "w");

    if (fopen == NULL) {
        printf("ERROR: File is null.");
    }

    char r;

    do {
        buffer[0] = '\0';

        printf("\n  Nome: ");
        __fpurge(stdin); scanf("%[^\n]", name);
        printf("  Insira o sobrenome: ");
        __fpurge(stdin); scanf("%[^\n]", last_name);
        printf("  Endereco: ");
        __fpurge(stdin); scanf("%[^\n]", address);
        printf("  Cidade: ");
        __fpurge(stdin); scanf("%[^\n]", city);
        printf("  Estado: ");
        __fpurge(stdin); scanf("%[^\n]", state);
        printf("  CEP: ");
        __fpurge(stdin); scanf("%s", zip);

        strcat(name, "|");
        strcat(last_name, "|");
        strcat(address, "|");
        strcat(city, "|");
        strcat(state, "|");
        strcat(zip, "|");
        strcat(buffer, name);
        strcat(buffer, last_name);
        strcat(buffer, address);
        strcat(buffer, city);
        strcat(buffer, state);
        strcat(buffer, zip);

        int buffer_size = strlen(buffer);

        fwrite(&buffer_size, sizeof(buffer_size), 1, file);
        fwrite(buffer, sizeof(char), buffer_size, file);

        printf("\n  Deseja continuar? [S/n] -> ");
        __fpurge(stdin); scanf(" %c", &r);

    } while (r == 's' || r == 'S');

    fclose(file);
    return 0;

}
