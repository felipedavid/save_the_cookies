#include <stdbool.h>

typedef struct objeto {
    char *info; 
    char *info2;
    char *info3;
    char *info4;
    int peso;
    int espaco;
    int vida;
    int ataque;
    char *nome;
    struct objeto *localizacao;
    struct objeto *destino;
    bool visivel;
} objeto_t;

extern objeto_t objetos[];
#define vovo            (objetos+0)
#define bengala         (objetos+1)
#define jogador         (objetos+2)
#define floresta        (objetos+3)
#define casa            (objetos+4)
#define saida_casa      (objetos+5)
#define entrada_casa    (objetos+6)
#define quarto          (objetos+7)
#define saida_quarto    (objetos+8)
#define entrada_quarto  (objetos+9)
#define caverna         (objetos+10)
#define saida_caverna   (objetos+11)
#define entrada_caverna (objetos+12)
#define esqueleto       (objetos+13)
#define biscoito        (objetos+14)
#define espada          (objetos+15)
#define final_array     (objetos+16)

typedef enum {
    distancia_jogador,          
    distancia_no_jogador,       
    distancia_inventario,       
    distancia_mapa_jogador,     
    distancia_no_mapa_jogador,  
    distancia_mao_jogador,      
    distancia_proximo_a_jogador,
    distancia_diferente_jogador,
    distancia_indefinida,       
} distancia_t;


bool esta_segurando(objeto_t *container, objeto_t *objeto);
distancia_t checar_distancia(objeto_t *origem, objeto_t *destino);
int objetos_em_localizacao(objeto_t *localizacao);
