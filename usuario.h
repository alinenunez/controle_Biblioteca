typedef struct {
    char nome[100];
    char email[100];
} Usuarios;

struct NoUsuario {
    Usuarios base;
    struct NoUsuario *next;
    struct NoUsuario *prev;
};
typedef struct NoUsuario noUsuario;