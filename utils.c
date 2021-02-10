#include <stdio.h>

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

char *parse_verbo(char *entrada) {
    printf(">>> Funcionalidade não implementada <<<");
    return NULL;
}

char *parse_substantivo(char *entrada) {
    printf(">>> Funcionalidade não implementada <<<");
    return NULL;
}

objeto_t *testar_NPC(void) {
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p == vizinho && obj_p->localizacao == jogador->localizacao) {
            return obj_p;
        }
    }
    return NULL;
}
