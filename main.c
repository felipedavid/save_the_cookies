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
    // 4/15
    // Acho que essa funcionalidade já está próximo suficiente dos requisitos 
    // do 'sistema de navegação'
    while (executar_entrada() && obter_entrada());

    return EXIT_SUCCESS;
}

bool obter_entrada(void) {
    printf("\n>>> ");
    return fgets(entrada, sizeof(entrada), stdin);
}

bool executar_entrada(void) {
    clear();
    // Pensando em uma maneira sem muita gambiarra de se coletar o verbo e o
    // substantivo da entrada do jogador. Por enquanto, vamo de strtok mesmo.
    // char *verbo = parseVerbo(entrada)
    // char *substantivo = parseSubstantivo(entrada)
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
        mostrar_ranking(NULL);
    } else {
        printf("Comando '%s' não existe.\n", verbo);
        printf("Digite 'ajuda' para ver os comandos válidos.\n");
    }
    return true;
}
