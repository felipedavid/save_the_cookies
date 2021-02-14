#include <stdio.h>
#include <string.h>

#include "objeto.h"

objeto_t objetos[] = {
    {"Sua casa", "casa", NULL, NULL},
    {"Sua vila", "vila", NULL, NULL},
    {"Seu vilarejo", "vilarejo", NULL, NULL},
    {"Seu vizinho", "vizinho", casa, NULL},
    {"Você", "jogador", casa, NULL},
    {"Um dos biscoitos que sua vovó fez para você", "biscoito", casa, NULL},
    {"O seu estilingue", "estilingue", casa, NULL},
    {"a entrada da sua casa", "entrada", vila, casa},
    {"a porta de 'saída' da sua casa", "saida", casa, vila},
};

int objetos_em_localizacao(objeto_t *localizacao) {
    int n_objetos = 0;
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p->localizacao == localizacao && obj_p != jogador) {
            if (n_objetos == 0) {
                printf("Você encherga:\n");
            }
            n_objetos++;
            printf("%s\n", obj_p->info);
        }
    }
    return n_objetos;;
}
