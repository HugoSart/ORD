#include <stdio.h>

#define clear() printf("\033[H\033[J")

#define NEW 1
#define ACCESS 2
#define EXIT 0

FILE *file;

char *file_name(FILE *f) {
    char path[1024];
    char *result = malloc(sizeof(char)*1024);

    /* Open a file, get the file descriptor. */
    int fd = fileno(f);

    /* Read out the link to our file descriptor. */
    sprintf(path, "/proc/self/fd/%d", fd);
    memset(result, 0, sizeof(result));
    readlink(path, result, sizeof(result)-1);

    /* Print the result. */
    return result;
}

int menu_open() {

    int e = 0;

    do {

        clear();

        char *fileName;
        if (file != NULL) fileName = file_name(file);

        printf("\n          \x1b[34mCRIAR E GERENCIAR ARQUIVOS\x1b[0m         \n\n");
        if (file != NULL) printf("  Arquivo selecionado: %s\n\n", fileName);
        else printf("  Nenhum arquivo selecionado\n\n");
        printf("    [1] Criar um novo arquivo\n");
        printf("    [2] Selecionar um arquivo existente\n");
        printf("    [3] Inserir um registro no arquivo selecionado\n");
        printf("    [4] Ler registros do arquivo selecionado\n");
        printf("    [5] Editar registro existente\n");
        printf("\n    [0] Terminar programa\n\n");

        if (e < 0 || e > 2) printf("\x1b[33m  Escolha inválida! \x1b[0m\n");

        printf("\x1b[36m  ENTRADA >> \x1b[0m");
        scanf("%d", &e);

    } while (e < 0 || e > 4);

    return e;

}

void menu_new() {

        clear();

        char name[30];

        printf("\n          \x1b[34mCRIAR UM NOVO ARQUIVO\x1b[0m         \n\n");
        printf("\x1b[36m    Nome do arquivo:\x1b[0m ");
        __fpurge(stdin);    scanf("%[^\n]", name);
        fclose(fopen(name, "w"));

        printf("\x1b[32m\n  Arquivo criado com sucesso! \x1b[0m");

        __fpurge(stdin);getchar();

}

int menu_acess() {

    int e = 0;
    char name[30];

    do {

        clear();

        printf("\n          \x1b[34mACESSAR ARQUIVO\x1b[0m         \n\n");

        printf("  Arquivos disponiveis para acesso: \n\n");
        system("ls");
        printf("\n");

        printf("\x1b[36m  NOME DO ARQUIVO >> \x1b[0m");
        __fpurge(stdin);    scanf("%[^\n]", name);

        file = fopen(name, "r+");

    } while (e < 0 || e > 2);

    return e;

}

int main() {

    do {
        switch(menu_open()) {
            case NEW:
                menu_new();
                break;
            case ACCESS:
                menu_acess();
                break;
            case EXIT:
                return 0;
        }
    } while (1);

    return 0;

}
