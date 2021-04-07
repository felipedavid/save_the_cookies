#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "objeto.h"

void venceu(void) {
    printf("/////////////////////////////////////////////////////////////////////////////\n"
        "///                                                                       ///\n"
        "///          ===================================================          ///\n"
        "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
        "///          = = =    Winner, Winner, Cookie for Dinner.   = = =          ///\n"
        "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
        "///          ===================================================          ///\n"
        "///                                                                       ///\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        " >>> Pressione 'enter' para sair.\n");
}

void perdeu(void) {
    printf("/////////////////////////////////////////////////////////////////////////////\n"
        "///                                                                       ///\n"
        "///          ===================================================          ///\n"
        "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
        "///          = = = =           Perdeu Soy Boy.           = = = =          ///\n"
        "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
        "///          ===================================================          ///\n"
        "///                                                                       ///\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        " >>> Pressione 'enter' para sair.\n");
}

objeto_t *testar_NPC(void) {
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p == vizinho && obj_p->localizacao == jogador->localizacao) {
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
