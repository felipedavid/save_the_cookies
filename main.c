#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "comandos.h"
#include "utils.h"

bool obter_entrada(void);
bool executar_entrada(void);

static char entrada[256];

int main(void) {
    puts("\tAviso: O game é case sensitive. ('sair' != 'SaiR')\n\n");

    // 2/15
    info();
    ajuda();
    venceu();
    perdeu();
    inventario();

    // game loop
    // pegar entrada do usuário -> parse e executar -> repetir 
    while (executar_entrada() && obter_entrada());

    return EXIT_SUCCESS;
}

bool obter_entrada(void) {
    printf("\n>>> ");
    char *tanto_faz = fgets(entrada, sizeof(entrada), stdin);
    return tanto_faz != NULL;
}

bool executar_entrada(void) {
    char *verbo = strtok(entrada, " \n");
    char *substantivo = strtok(NULL, "\n");
    if (verbo == NULL) return true;

    if (!strcmp(verbo, "sair")) {
        return false;
    } else if (!strcmp(verbo, "info")) {
        info();
    } else if (!strcmp(verbo, "ajuda")) {
        ajuda();
    } else if (!strcmp(verbo, "olhar")) {
        olhar(substantivo);
    } else if (!strcmp(verbo, "clear")) {
        clear();
    } else if (!strcmp(verbo, "inventario")) {
        inventario();
    } else if (!strcmp(verbo, "ir")) {
        ir(substantivo);
    } else if (!strcmp(verbo, "pegar")) {
        pegar(substantivo);
    } else if (!strcmp(verbo, "soltar")) {
        largar(substantivo);
    } else {
        printf("Comando '%s' não existe.\n", verbo);
    }
    return true;
}
