typedef struct Usuarios {
    char nome[100];
    char email[100];
    struct Usuarios *next;
    struct Usuarios *prev;
} Usuarios;

typedef struct SentUsuario {
    Usuarios *first;
    Usuarios *last;
}SentUsuario;

void insereUsuario(SentUsuario *sentU);

void buscaEmail(SentUsuario *sentU);
void buscaNome(SentUsuario *sentU);
void buscaEmprestimosPorEmail(SentLivros *sentL, SentUsuario *sentU);

