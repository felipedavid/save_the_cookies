#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "utils.h"
//#include "objeto.h"

static bool obter_entrada(void);
bool analisar_entrada(char *entrada);
bool executar_comando(char *verbo, char *substantivo);

static char entrada[256] = "none";

int main(void) {
    menu_sobre(); // requisitos 1/15

    // game loop
    // pegar entrada do usuário -> procurar por comandos válidos -> executar
    // comando se válido -> repetir 
    while (analisar_entrada(entrada) && obter_entrada());

    return EXIT_SUCCESS;
}

static bool obter_entrada(void) {
    printf(">>> ");
    char *tanto_faz = fgets(entrada, sizeof(entrada), stdin);
    return tanto_faz != NULL;
}

bool analisar_entrada(char *entrada) {
    char *verbo = strtok(entrada, " \n");
    if (verbo == NULL) return false;

    return executar_comando(verbo, NULL);
}

bool executar_comando(char *verbo, char *substantivo) {
    if (!strcmp(verbo, "sair"))
        return false;
    else if (!strcmp(verbo, "info"))
        menu_sobre();
    else if (!strcmp(verbo, "olhar"))
        printf("Você está no seu quarto.\n\n");
    else if (!strcmp(verbo, "none"))
        ;
    else 
        printf("Comando '%s' não existe.\n\n", verbo);

    return true;
}
