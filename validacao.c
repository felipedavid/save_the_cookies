// 6/15
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

bool eh_letra(char caractere) {
    if ((caractere >= 'A' && caractere <= 'Z') ||
        (caractere >= 'a' && caractere <= 'z')) {
        return true;
    }
    return false;
}

bool eh_numero(char caractere) {
    if (caractere >= '0' && caractere <= '9') {
        return true;
    }
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
        if (eh_letra(nome[i]) || (nome[i] == ' ')) {
            continue;
        }
        return false;
    }
    return true;
}

bool email_valido(char *email) {
    int pArroba, pPonto;
    bool pontoPresente = false, arrobaPresente = false;

    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '.') {
            pPonto = i;
            pontoPresente = true;
        } else if (email[i] == '@') {
            pArroba = i;
            arrobaPresente = true;
        }
    }

    if (pontoPresente && arrobaPresente && (pArroba > 2) &&
        (pArroba+2 < pPonto)) {
        return true;
    } 
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
        } else if (eh_letra(senha[i])) {
            c++;
        } else if (eh_numero(senha[i])) {
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
