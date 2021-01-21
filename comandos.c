#include <stdio.h>
#include <stdlib.h>

#include "comandos.h"

void info(void) {

    puts("/////////////////////////////////////////////////////////////////////////////\n"
        "///                                                                       ///\n"
        "///              Universidade Federal do Rio Grande do Norte              ///\n"
        "///                  Centro de Ensino Superior do Seridó                  ///\n"
        "///                Departamento de Computação e Tecnologia                ///\n"
        "///                   Disciplina DCT1106 -- Programação                   ///\n"
        "///                 Developed by  @felipedavid - Jan, 2021                ///\n"
        "///                                                                       ///\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "///                                                                       ///\n"
        "///          ===================================================          ///\n"
        "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
        "///          = = = =           Save The Cookies          = = = =          ///\n"
        "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
        "///          ===================================================          ///\n"
        "///                                                                       ///\n"
        "/// Um simples text-based rpg game para demonstar as principais           ///\n"
        "/// funcionalidades dos clássicos rpgs de texto famosos nos anos 70. A    ///\n"
        "/// premissa do game é bem simples, monstros atacaram o seu vilareijo     ///\n"
        "/// durante a noite e acabaram roubando todo o seu estoque de alimentos,  ///\n"
        "/// entre os alimentos roubados estavam os biscoitos que sua vovó fez     ///\n"
        "/// para você. Seu objetivo é atacar o labirinto de onde esses monstros   ///\n"
        "/// saíram e tentar recuperar o máximo de biscoitos possível.             ///\n"
        "///                                                                       ///\n"
        "/// AVISO: Esse game não tem como objetivo intrerter ninguém. O game      ///\n"
        "/// como um todo é formado apenas de funcionalidades que achei            ///\n"
        "/// interessante 'implementar' não que melhoram a experiência             ///\n"
        "/// experiência do jogador. \"Programe jogos, não os jogue.\" :P            ///\n"
        "///                                                                       ///\n"
        "/////////////////////////////////////////////////////////////////////////////\n\n"
        "\t>>> Digite 'ajuda' para visualizar o manual de comandos...\n"
        "\t>>> Digite 'sair' para fechar o game...\n");
}

void ajuda(void) {
    puts(""
    "info  -> Exibe informações do projeto\n"
    "ajuda -> Exibe esse manual de comandos\n"
    "olhar -> Exibe informações do objeto especificado.\n"
    "         Se nenhum objeto for especificado, o comando exibe informações\n"
    "         do local atual.\n"
    "sair  -> Sai do programa\n");
}

void olhar(char *substantivo) {
    printf("Não implementado\n");
}

void inventario(void) {
    printf("Não implementado\n");
}

void clear(void) {
    #if defined _WIN32 || defined _WIN64
        system("cls");
    #else
        system("clear");
    #endif
}

void ir(char *substantivo) {
    if (substantivo == NULL) {
        printf("Pra onde você quer ir?\n"); 
    }
}
