#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ranking.h"
#include "comandos.h"
#include "objeto.h"
#include "validacao.h"
#include "paineis.h"
#include "inventario.h"
#include "utils.h"

void clear(void) {
#if defined _WIN32 || defined _WIN64
    system("cls");
#else
    system("clear");
#endif
}

void info(void) {
    puts(painel_info);
}

void ajuda(void) {
    puts(painel_ajuda);
}

void olhar(char *substantivo) {
    if (substantivo != NULL && (!strcmp(substantivo, "redor") || 
                                !strcmp(substantivo, "volta"))  ) {
        printf("Você está em %s.\n", jogador->localizacao->info);
        objetos_em_localizacao(jogador->localizacao);
    } else {
        printf("Não entendo oque você quer ver.\n");
        printf("Ex de uso: \">>> olhar em volta\"\n");
    }
}

void ir(char *substantivo) {
    objeto_t *objeto = campo_de_visao("pra onde você quer ir", substantivo);
    if (!objeto) return;

    if (!checar_passagem(jogador->localizacao, objeto)) {
        jogador->localizacao = objeto->destino;
        printf("Feito.\n");
        olhar("redor");
    } else if (jogador->localizacao != objeto->localizacao) {
        printf("Você não vê nenhum %s.\n", substantivo);
    } else if (objeto->destino) {
        jogador->localizacao = objeto->destino;
        puts("Feito.");
        olhar("redor");
    } else {
        for (int i = 0; &objetos[i] != final_array; i++) {
            if (!strcmp(objetos[i].nome, substantivo)) {
                jogador->localizacao = &objetos[i];
            }
        }
    }
}
