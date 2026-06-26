typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int ano;
    int status;
    char email_usuario[100];
} Livros;

struct NoLivro{
    Livros arsenal;
    struct NoLivro *next;
    struct NoLivro *prev;
};
typedef struct NoLivro noLivro;

