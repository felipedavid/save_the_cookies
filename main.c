#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "comandos.h"
#include "objeto.h"
#include "utils.h"
#include "inventario.h"
#include "ranking.h"

bool obter_entrada(void);
bool executar_entrada(void);

static char entrada[256] = "info";

int main(void) {
    while (executar_entrada() && obter_entrada());

    return EXIT_SUCCESS;
}

bool obter_entrada(void) {
    printf("\n>>> ");
    return fgets(entrada, sizeof(entrada), stdin);
}

bool executar_entrada(void) {
    char *verbo = parse_verbo(entrada);
    char *substantivo = parse_substantivo(entrada);

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
        abrir_inventario();
    } else if (!strcmp(verbo, "ir")) {
        ir(substantivo);
    } else if (!strcmp(verbo, "pegar")) {
        pegar_item(substantivo);
    } else if (!strcmp(verbo, "dar")) {
        dar_item(substantivo);
    } else if (!strcmp(verbo, "largar")) {
        largar_item(substantivo);
    } else if (!strcmp(verbo, "rank") || !strcmp(verbo, "ranking")) {
        rank(substantivo);
    } else {
        printf("Comando '%s' não existe.\n", verbo);
        printf("Digite 'ajuda' para ver os comandos válidos.\n");
    }

    free(verbo);
    free(substantivo);

    return true;
}
