void cadastrar_ranking(void);
void mostrar_ranking(void);

typedef struct {
    int dia, mes, ano;
} DATA;

typedef struct JOGADOR {
    char *nome;
    char *email;
    int pontos;
    DATA nascimento;
    struct JOGADOR *next;
} JOGADOR;

extern JOGADOR ranking_jogadores[];
#define fim_jogadores (ranking_jogadores+2)
