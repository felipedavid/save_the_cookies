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

int objetosEmLocalizacao(objeto_t *localizacao) {
    int nObjetos = 0;
    for (objeto_t *obj_p = objetos; obj_p != finalDoArray; obj_p++) {
        if (obj_p->localizacao == localizacao && obj_p != jogador) {
            if (nObjetos == 0) printf("Você encherga:\n");
            nObjetos++;
            printf("%s\n", obj_p->info);
        }
    }
    return nObjetos;;
}

objeto_t *procurarObjeto(char *subs) {
    objeto_t *objeto = NULL;
    if (subs == NULL) {
        return objeto;
    }
    for (objeto_t *obj_p = objetos; obj_p != finalDoArray; obj_p++) {
        if (!strcmp(subs, obj_p->nome)) {
            objeto = obj_p;
        }
    }
    return objeto;
}
