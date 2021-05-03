#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "objeto.h"
#include "utils.h"

objeto_t objetos[] = {
    {"sua avó", "", "", "", 0, 0, 1, 0, "vovo", casa, NULL, true},
    {"bengala de sua avó", "", "", "", 5, 0, 1, 10, "bengala", casa, NULL, true},
    {"você", "", "", "", 5, 10, 100, 0, "jogador", quarto, NULL, true},

    {"floresta", "", "", "", 0, 0, 1, 0, "floresta", NULL, NULL, true},

    {"casa da sua avó", "", "", "", 0, 0, 1, 0, "casa", NULL, NULL, true},
    {"saida da casa", "", "", "", 0, 0, 1, 0, "saida", casa, floresta, true},
    {"entrada da casa", "", "", "", 0, 0, 1, 0, "entrada", floresta, casa, true},

    {"seu quarto", "", "", "", 0, 0, 1, 0, "quarto", NULL, NULL, true},
    {"saída do seu quarto", "", "", "", 0, 0, 1, 0, "saida", quarto, casa, true},
    {"entrada do seu quarto", "", "", "", 0, 0, 1, 0, "entrada", casa, quarto, true},

    {"caverna", "", "", "", 0, 0, 1, 0, "caverna", NULL, NULL, true},
    {"saida da caverna", "", "", "", 0, 0, 1, 0, "saida", caverna, floresta, true},
    {"entrada da caverna", "", "", "", 0, 0, 1, 0, "entrada", floresta, caverna, true},

    {"monstro esqueleto", "", "", "", 0, 10, 75, 7, "esqueleto", caverna, NULL, true},
    {"biscoito", "", "", "", 20, 10, 30, 7, "biscoito", vovo, NULL, true},
    {"espada enferrujada", "", "", "", 5, 10, 30, 7, "espada", esqueleto, NULL, true},
};

bool esta_segurando(objeto_t *caixa, objeto_t *objeto) {
    if (!objeto) return false;

    if (objeto->localizacao == caixa) {
        return true;
    }
    return false;
}

int objetos_em_localizacao(objeto_t *localizacao) {
    int n_objetos = 0;
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (esta_segurando(localizacao, obj_p) && obj_p != jogador) {
            if (n_objetos == 0) {
                printf("Você encherga:\n");
            }
            n_objetos++;
            if (obj_p->visivel) {
                printf(" - %s\n", obj_p->info);
            }
        }
    }
    return n_objetos;;
}

distancia_t checar_distancia(objeto_t *origem, objeto_t *destino) {
    distancia_t distancia;

    if (!destino) {
        distancia = distancia_indefinida;
    } else if (destino == origem) {
        distancia = distancia_jogador;
    } else if (esta_segurando(origem, destino)) {
        distancia = distancia_no_jogador;
    } else if (esta_segurando(destino, origem)) {
        distancia = distancia_mapa_jogador;
    } else if (esta_segurando(origem->localizacao, destino)) {
        distancia = distancia_no_mapa_jogador;
    } else if (esta_segurando(origem, destino->localizacao)) {
        distancia = distancia_mao_jogador;
    } else if (esta_segurando(origem->localizacao, destino->localizacao)) {
        distancia = distancia_mao_jogador;
    } else if (checar_passagem(origem->localizacao, destino)) {
        distancia = distancia_proximo_a_jogador;
    } else {
        distancia = distancia_diferente_jogador;
    }

    return distancia;
}
