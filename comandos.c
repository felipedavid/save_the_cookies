#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comandos.h"
#include "objeto.h"

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
         "/// premissa do game é bem simples, monstros atacaram o seu vilarejo      ///\n"
         "/// durante a noite e acabaram roubando todo o seu estoque de alimentos,  ///\n"
         "/// entre os alimentos roubados estavam os biscoitos que sua vovó fez     ///\n"
         "/// para você. Seu objetivo é atacar o labirinto de onde esses monstros   ///\n"
         "/// saíram e tentar recuperar o máximo de biscoitos possível.             ///\n"
         "///                                                                       ///\n"
         "/// Obs: Esse game não tem como objetivo divertir ou intrerter ninguém.   ///\n"
         "/// O game em si é formado apenas de funcionalidades que achei            ///\n"
         "/// interessante do meu ponto de vista como implementador e não jogador.  ///\n"
         "/// Garanto que me diverti bem mais desenvolvendo esse joguinho doque     ///\n"
         "/// você vai se divertir com os mĺzeros 2-5 minutos de gameplay xD.       ///\n"
         "///  - \"Programe jogos, não os jogue.\" :P                                 ///\n"
         "///                                                                       ///\n"
         "/// ps: a historinha do game é pura tiração de sarro.                     ///\n"
         "/////////////////////////////////////////////////////////////////////////////\n\n"
         "\t>>> Digite 'ajuda' para visualizar o manual de comandos...\n"
         "\t>>> Digite 'clear' para limpar a tela...\n"
         "\t>>> Digite 'sair' para fechar o game...\n");
}

void ajuda(void) {
    puts("/////////////////////////////////////////////////////////////////////\n"
         "///                                                               ///\n"
         "///      ===================================================      ///\n"
         "///      = = = =              Menu Ajuda             = = = =      ///\n"
         "///      ===================================================      ///\n"
         "///                                                               ///\n"
         "/// info  -> Exibe informações do projeto.                        ///\n"
         "/// ajuda -> Exibe esse manual de comandos.                       ///\n"
         "/// olhar -> Exibe informações do objeto especificado.            ///\n"
         "///          Se nenhum objeto for especificado, o comando exibe   ///\n"
         "///          informações do local atual.                          ///\n"
         "/// ir 'local' -> Você muda sua localização para 'local'.         ///\n"
         "/// inventario -> Exibe os items você está carregando.            ///\n"
         "/// pegar 'item' -> Coloca 'item' no inventário.                  ///\n"
         "/// largar 'item' -> Larga o 'item' do inventário.                ///\n"
         "/// rank -> mostra os jogadores com pontuação mais alta.          ///\n"
         "/// clear -> Limpa a tela.                                        ///\n"
         "/// sair  -> Sai do programa.                                     ///\n"
         "///                                                               ///\n"
         "/////////////////////////////////////////////////////////////////////\n\n");
}

void olhar(char *substantivo) {
    if (substantivo != NULL && (!strcmp(substantivo, "redor") || 
                                !strcmp(substantivo, "volta"))  ) {
        printf("Você está em %s.\n", jogador->localizacao->info);
        objetos_em_localizacao(jogador->localizacao);
    } else {
        printf("Não entendo oque você quer ver.\n");
        printf("Ex de uso: \">>> olhar em volta\"\n");
    }
}

void ir(char *substantivo) {
    if (substantivo == NULL) {
        printf("Pra onde você quer ir?\n"); 
    } else {
        for (int i = 0; &objetos[i] != final_array; i++) {
            if (!strcmp(objetos[i].nome, substantivo)) {
                jogador->localizacao = &objetos[i];
            }
        }
    }
    printf("Agora ");
    olhar(substantivo);
}

void clear(void) {
#if defined _WIN32 || defined _WIN64
    system("cls");
#else
    system("clear");
#endif
}
