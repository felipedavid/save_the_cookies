#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "objeto.h"
#include "paineis.h"

void venceu(void) {
    puts(painel_vencedor);
}

void perdeu(void) {
    puts(painel_perdedor);
}

objeto_t *testar_NPC(void) {
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p == vovo && obj_p->localizacao == jogador->localizacao) {
            return obj_p;
        }
    }
    return NULL;
}

objeto_t *checar_passagem(objeto_t *origem, objeto_t *destino) {
    if (origem == NULL || destino == NULL) return NULL;

    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p->localizacao == origem && obj_p->destino == destino) {
            return obj_p;
        }
    }
    return NULL;
}
