#include <stdlib.h>
#include <string.h>

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