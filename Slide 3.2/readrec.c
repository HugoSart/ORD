#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getrf.h"

int main() {

    char file_name[30];

    printf("============== Readrec ================\n\n");
    printf("  Nome do arquivo: ");

    __fpurge(stdin);    scanf("%[^\n]", file_name);

    FILE *file;

    if ((file = fopen(file_name, "r")) == 0) {
        printf("\nERROR: File \"%s\" not found!\n", file_name);
        exit(1);
    }
    printf("\n");
    char buffer[200];
    buffer[0] = '\n';
    int scap_pos = 1, rec_lenght;
    rewind(file);

    do {
        rec_lenght = get_rec(file, buffer);
        printf("  %s\n", buffer);
    } while (rec_lenght > 0);

    fclose(file);

    return 0;

}
