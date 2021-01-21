#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "comandos.h"
//#include "objeto.h"

static bool obter_entrada(void);
bool analisar_entrada(char *entrada);
bool executar_comando(char *verbo, char *preposicao, char *substantivo);

static char entrada[256] = "olhar em volta";

int main(void) {
    info(); // requisitos 1/15, função definida em 'comandos.c'

    puts("\tAviso: O game é case sensitive. ('sair' != 'SaiR')\n");

    // game loop
    // pegar entrada do usuário -> procurar por comandos válidos -> executar
    // comando se válido -> repetir 
    while (analisar_entrada(entrada) && obter_entrada());

    return EXIT_SUCCESS;
}

static bool obter_entrada(void) {
    printf("\n>>> ");
    char *tanto_faz = fgets(entrada, sizeof(entrada), stdin);
    return tanto_faz != NULL;
}

bool analisar_entrada(char *entrada) {
    char *verbo = strtok(entrada, " \n");
    //char *preposicao = strtok(NULL, " \n");
    //char *substantivo = strtok(NULL, "\n");
    if (verbo == NULL) return false;

    return executar_comando(verbo, NULL, NULL);
}

bool executar_comando(char *verbo, char *preposicao, char *substantivo) {
    if (!strcmp(verbo, "sair"))
        return false;
    else if (!strcmp(verbo, "info"))
        info();
    else if (!strcmp(verbo, "ajuda"))
        ajuda();
    else if (!strcmp(verbo, "olhar"))
        olhar(substantivo);
    else if (!strcmp(verbo, "clear"))
        clear();
    else if (!strcmp(verbo, "inventario"))
        inventario();
    else if (!strcmp(verbo, "ir"))
        ir(substantivo);
    else if (!strcmp(verbo, "none"))
        ;
    else 
        printf("Comando '%s' não existe.\n", verbo);

    return true;
}
