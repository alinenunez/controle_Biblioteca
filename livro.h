typedef struct Livros {
    int id;
    char titulo[100];
    char autor[100];
    int anoP;
    int status;
    char email_usuario[100];
    struct Livros* next;
    struct Livros* prev;
} Livros;

typedef struct SentLivros{
    Livros *first;
    Livros *last;
} SentLivros;

void insereListaLivros(SentLivros *sentL);
void buscaLivro (SentLivros *sentL);
void buscaAutor (SentLivros *sentL);

