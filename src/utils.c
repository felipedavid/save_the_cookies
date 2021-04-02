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

int numero_palavras(char *string) {
	int i = 0, n_palavras = 0, estado;
    char c;

    estado = 0;
    while ((c=string[i])) {
        if (c == ' ' || c == '\n' || c == '\t')
            estado = 0;
        else if (estado == 0) {
            estado = 1;
            n_palavras++;
        }
		i++;
    }

	return n_palavras;
}

char *parse_verbo(char *entrada) {
    if (entrada == NULL) return NULL;

    char primeira_palavra[256], c;
    int i;

    for (i = 0; (c=entrada[i]) && c != '\0' && c != '\n' && c != ' '; i++) {
        primeira_palavra[i] = entrada[i]; 
    }
    primeira_palavra[i] = '\0';

    char *verbo = (char *) malloc(strlen(primeira_palavra) + 1);
    if (verbo == NULL) return NULL;

    strcpy(verbo, primeira_palavra);

    return verbo;
}

char *parse_substantivo(char *entrada) {
    if (numero_palavras(entrada) < 2) return NULL;
    
    char *substantivo, *ultima_palavra = strrchr(entrada, ' ');
    if (ultima_palavra && *(ultima_palavra+1)) {
        ultima_palavra[strcspn(ultima_palavra, "\n")] = 0;

        substantivo = (char *) malloc(strlen(ultima_palavra+1) + 1);
        if (substantivo == NULL) return NULL;
        
        strcpy(substantivo, ultima_palavra+1);
    }
    return substantivo;
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
