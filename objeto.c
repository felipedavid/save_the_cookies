#include <stdio.h>
#include <string.h>

#include "objeto.h"

objeto_t objetos[] = {
    {"Sua casa", "casa", NULL},
    {"Seu vilarejo", "vilarejo", NULL},
    {"Seu vizinho", "vizinho", casa},
    {"Você", "jogador", casa},
    {"Um dos biscoitos que sua vovó fez para você", "biscoito", casa},
    {"O seu estilingue", "estilingue", casa},
};

int objetos_em_localizacao(objeto_t *localizacao) {
    int n_objetos = 0;
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p->localizacao == localizacao && obj_p != jogador) {
            if (n_objetos == 0) printf("Você encherga:\n");
            n_objetos++;
            printf("%s\n", obj_p->info);
        }
    }
    return n_objetos;;
}

objeto_t *procurar_objeto(char *subs) {
    objeto_t *objeto = NULL;
    if (subs == NULL) {
        return objeto;
    }
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (!strcmp(subs, obj_p->nome)) {
            objeto = obj_p;
        }
    }
    return objeto;
}
