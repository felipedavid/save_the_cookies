// 6/15
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

bool eh_letra(char caractere) {
    return false;
}

bool eh_numero(char caractere) {
    return false;
}

bool pontos_valido(int pontos) {
    if (pontos >= 0) {
        return true;
    }
    return false;
}

bool nome_valido(char *nome) {
    for (int i = 0; i < strlen(nome); i++) {
        if ((nome[i] >= 'A' && nome[i] <= 'Z') ||
            (nome[i] >= 'a' && nome[i] <= 'z') ||
            (nome[i] == ' ')) {
            continue;
        }
        return false;
    }
    return true;
}

bool email_valido(char *email) {
    return false;
}

// 'senha valida' == +8 caracteres e com algum caractere numérico
// pra que senha? slá, vai que algum dia eu esteja tão intediado que
// decida implementar um sistema multiplayer, kkk
bool senha_valida(char *senha) {
    int c, n, s;
    c = n = s = 0;

    for (int i = 0; i < strlen(senha); i++) {
        if (senha[i] == ' '  || senha[i] == '\0' || 
            senha[i] == '\n' || senha[i] == '\t') {
            return false;
        } else if ((senha[i] >= 'A' && senha[i] <= 'Z') ||
            (senha[i] >= 'a' && senha[i] <= 'z')) {
            c++;
        } else if (senha[i] >= '0' && senha[i] <= '9') {
            n++;
        } else {
            s++;
        }
    }

    if (n >= 1 && (c+n+s) >= 8) {
        return true;
    }
    return false;
}
