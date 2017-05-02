#include <stdio.h>

int get_rec(FILE *file, char buffer[]) {

    int rec_lenght;

    if (fread(&rec_lenght, sizeof(int), 1, file) == 0)
        return 0;

    fread(buffer, rec_lenght, 1, file);

    return rec_lenght;

}
