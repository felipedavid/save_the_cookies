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

int objetosEmLocalizacao(objeto_t *localizacao) {
    int nObjetos = 0;
    for (objeto_t *obj_p = objetos; obj_p != finalDoArray; obj_p++) {
        if (obj_p->localizacao == localizacao && obj_p->localizacao != jogador) {
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
