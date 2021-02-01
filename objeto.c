#include <stdio.h>
#include <string.h>

#include "objeto.h"

objeto_t objetos[] = {
    {"sua casa", "casa", NULL},
    {"seu vilarejo", "vilarejo", NULL},
    {"seu vizinho", "vizinho", casa},
    {"voce", "jogador", casa},
    {"um dos biscoitos que sua vovó fez para você", "Biscoito", jogador},
    {"o seu estilingue", "Estilingue", jogador},
};

int objetos_em_localizacao(objeto_t *localizacao) {
    int objeto_c = 0;
    for (int i = 0; &objetos[i] < final_do_array; i++) {
        if (objetos[i].localizacao == localizacao && &objetos[i] != jogador) {
            if (objeto_c == 0) printf("Você encherga:\n");
            objeto_c++;
            printf("%s\n", objetos[i].info);
        }
    }
    return objeto_c;
}

objeto_t *procurar_objeto(char *subs) {
    objeto_t *objeto = NULL;
    if (subs == NULL) {
        return objeto;
    }
    for (objeto_t *obj_p = objetos; obj_p != final_do_array; obj_p++) {
        if (!strcmp(subs, obj_p->nome)) {
            objeto = obj_p;
        }
    }
    return objeto;
}
