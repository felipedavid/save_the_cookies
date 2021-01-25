#include <stdio.h>
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
    unsigned char objeto_c = 0;
    for (int i = 0; &objetos[i] < final_do_array; i++) {
        if (objetos[i].localizacao == localizacao && &objetos[i] != jogador) {
            if (objeto_c == 0) printf("Você encherga:\n");
            objeto_c++;
            printf("%s\n", objetos[i].info);
        }
    }
    return objeto_c;
}
