typedef struct objeto {
    char *info;
    char *nome;
    struct objeto *localizacao;
    struct objeto *destino;
} objeto_t;

extern objeto_t objetos[];
#define casa           (objetos+0)
#define vila           (objetos+1)
#define vilarejo       (objetos+2)
#define vizinho        (objetos+3)
#define jogador        (objetos+4)
#define biscoito       (objetos+5)
#define estilingue     (objetos+6)
#define emCasa         (objetos+7)
#define saidaCasa      (objetos+8)
#define final_array    (objetos+9)

int objetos_em_localizacao(objeto_t *localizacao);
objeto_t *procurar_objeto(char *subs);
