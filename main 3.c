#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LER_FICHEIRO(char*[]);
void Sort(char*[], char*[]);
void Print(char*[]);

int main () {
    char *linhas[140], *linhas_ord[140];
    LER_FICHEIRO(linhas);
    Sort(linhas, linhas_ord);
    Print(linhas_ord);

    return 0;
}

void LER_FICHEIRO(char* linhas[]) {

    FILE *filepointer;
    char* str[60];
    unsigned int size, pos = 0; // unsigned remete para valores só positivos
    filepointer = fopen("RunResults.txt", "r"); //lê o ficheiro
    fgets(str, 60, filepointer);
    while (fgets(str, 60, filepointer) != NULL){
            size = strlen(str);
            linhas[pos] = (char*) malloc(size* sizeof (char));//alocação dinâmica de memória
            strcpy(linhas[pos], str); // copia a String str para linhas[pos]
            pos++;
        }

    fclose(filepointer); //acaba de ler o ficheiro
}

void Sort(char* linha1[], char* final[]){
    char* ordem[] = {"F20", "F40", "F45", "M20", "M35", "M40", "M45", "M50", "M55", "M60"};
    char escalao[3];
    int comp;
    unsigned int pos1 = 0, size;

    for (int i = 0; i < 10; i++) // 10 é o nº de escalões
    {
        for (int l = 0; l < 140; l++) // 140 linhas
        {
            sscanf(linha1[l], "%*d\t%s\t%*d\t%*d\t%*s\t%*c\t%*s", escalao);//como é uma string não precisa de &, o * ignora a informação referente
            comp = strcmp(escalao, ordem[i]);
            if (comp == 0, escalao != " ")
            {
                size = strlen(linha1[l]);
                strcpy(final[pos1],linha1[l]);
                pos1++;
            }
        }
    }
}

void Print(char* linhas_ord[]){
    FILE *filepointer;
    filepointer = fopen("RunResultsout.txt", "w");
    for (int l = 0; l < 140; l++)
    {
        fprintf(filepointer, "%s", linhas_ord[l]);
    }
    fclose(filepointer);
}
