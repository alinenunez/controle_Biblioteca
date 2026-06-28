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

typedef struct sentLivros{
    Livros *first;
    Livros *last;
} sentLivros;

void insereListaLivros(sentLivros *sentL);
