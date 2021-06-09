// 6/15
// 7/15
// OBS: Inserir o comando ">>> ranking add" para testar a validacao.
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

bool eh_letra(char caractere) {
    return ((caractere >= 'A' && caractere <= 'Z') ||
            (caractere >= 'a' && caractere <= 'z'));
}

bool eh_numero(char caractere) {
    return (caractere >= '0' && caractere <= '9');
}

bool pontos_valido(int pontos) {
    return (pontos >= 0);
}

bool nome_valido(char *nome) {
    size_t nome_len = strlen(nome)-1; // \n
    for (size_t i = 0; i < nome_len ; i++) {
        if ((!eh_letra(nome[i])) && (nome[i] != ' ')) {
            return false;
        }
    }
    return true;
}

bool email_valido(char *email) {
    int posicaoArroba, posicaoPonto;
    bool pontoPresente = false, arrobaPresente = false;

    size_t len_email = strlen(email)-1;
    for (size_t i = 0; i < len_email; i++) {
        if (email[i] == '.') {
            posicaoPonto = i;
            pontoPresente = true;
        } else if (email[i] == '@') {
            posicaoArroba = i;
            arrobaPresente = true;
        } else if (!(eh_letra(email[i]) || eh_numero(email[i]))) {
            return false;
        }
    }

    return (pontoPresente && arrobaPresente &&
           (posicaoArroba+2 < posicaoPonto) &&
           (posicaoArroba > 2));
}

// 'senha valida' == +8 caracteres e com algum caractere numérico
// pra que senha? slá, vai que algum dia eu esteja tão intediado que
// decida implementar um sistema multiplayer, kkk
bool senha_valida(char *senha) {
    int c, n, s;
    c = n = s = 0;

    size_t len_senha = strlen(senha);
    for (size_t i = 0; i < len_senha; i++) {
        if (senha[i] == ' '  || senha[i] == '\0' || 
            senha[i] == '\n' || senha[i] == '\t') {
            return false;
        } 

        if (eh_letra(senha[i])) {
            c++;
        } else if (eh_numero(senha[i])) {
            n++;
        } else {
            s++;
        }
    }

    return (n > 0 && (c+n+s) >= 8);
}
