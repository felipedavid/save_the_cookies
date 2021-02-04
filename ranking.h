void cadastrarRanking(void);
void mostrarRanking(void);

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

extern JOGADOR rankingJogadores[];
#define fimJogadores (rankingJogadores+2)
