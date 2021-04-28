typedef struct objeto {
    char *info;
    char *nome;
    struct objeto *localizacao;
    struct objeto *destino;
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
#define final_array     (objetos+13)

int objetos_em_localizacao(objeto_t *localizacao);
objeto_t *procurar_objeto(char *subs);
