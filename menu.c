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