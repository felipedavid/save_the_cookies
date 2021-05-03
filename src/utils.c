#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "objeto.h"
#include "paineis.h"
#include "inventario.h"

void venceu(void) {
    puts(painel_vencedor);
}

void perdeu(void) {
    puts(painel_perdedor);
}

objeto_t *achar_mob(char *substantivo) {
    objeto_t *obj_ptr, *objeto_encontrado = NULL;
    for (obj_ptr = objetos; obj_ptr < final_array; obj_ptr++) {
        if (objeto_tem_nome(obj_ptr, substantivo)) {
            objeto_encontrado = obj_ptr;
        }
    }
    return objeto_encontrado;
}

objeto_t *testar_NPC() {
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p == vovo && esta_segurando(jogador->localizacao, obj_p)) {
            return obj_p;
        }
    }
    return NULL;
}

objeto_t *checar_passagem(objeto_t *origem, objeto_t *destino) {
    if (origem == NULL || destino == NULL) return NULL;

    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (esta_segurando(origem, obj_p) && obj_p->destino == destino) {
            return obj_p;
        }
    }
    return NULL;
}
