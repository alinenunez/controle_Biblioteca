#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

void menuPrincipal(SentLivros *sentL, SentUsuario *sentU){
    int opcao;

    do{
        printf("\n=== SISTEMA DE BIBLIOTECA ===\n");
        printf("1. Cadastro\n");
        printf("2. Consulta\n");
        printf("3. Atualizacao\n");
        printf("4. Exclusao\n");
        printf("5. Emprestimo\n");
        printf("6. Devolucao\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                menuCadastro(sentL, sentU);
                break;
            case 2:
                menuConsulta(sentL, sentU);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                break;    
        default:
            printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
}

void menuCadastro(SentLivros *sentL, SentUsuario *sentU){
    int opcao;

    do{
        printf("\n=== CADASTRO ===\n");
        printf("1. Livros\n");
        printf("2. Usuarios\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                insereListaLivros(sentL);
                break;
            case 2:
                insereUsuario(sentU);
                break;
            case 0:
                printf("Voltando...\n");
                break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuConsulta(SentLivros *sentL, SentUsuario *sentU) {
    int opcao;

    do {
        printf("\n=== CONSULTA ===\n");
        printf("1. Livros\n");
        printf("2. Usuarios\n");
        printf("3. Emprestimos\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuConsultaLivros(sentL);
                break;
            case 2:
                menuConsultaUsuarios(sentU);
                break;
            case 3:
                buscaEmprestimosPorEmail(sentL, sentU);
                break;
            case 0:
                printf("Voltando...\n");
                break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuConsultaLivros(SentLivros *sentL) {
    int opcao;

    do {
        printf("\n=== CONSULTA LIVROS ===\n");
        printf("1. Por codigo\n");
        printf("2. Por autor\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                buscaLivroPorCodigo(sentL);
                break;
            case 2:
                buscaLivroPorAutor(sentL);
                break;
            case 0:
                printf("Voltando...\n");
                break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuConsultaUsuarios(SentUsuario *sentU) {
    int opcao;

    do {
        printf("\n=== CONSULTA USUARIOS ===\n");
        printf("1. Por email\n");
        printf("2. Por nome\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                buscaUsuarioPorEmail(sentU);
                break;
            case 2:
                buscaUsuarioPorNome(sentU);
                break;
            case 0:
                printf("Voltando...\n");
                break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}