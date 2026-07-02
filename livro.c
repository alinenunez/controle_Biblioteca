#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

void insereListaLivros(SentLivros *sentL){
    Livros *new = malloc(sizeof(Livros));

    if(new == NULL){
        printf("Erro: memoria insuficiente.\n");
        return;
    }
    if(sentL->last == NULL){
        new->id = 1; //primeiro livro
    }else{
        new->id = sentL->last->id + 1;
    }

    printf("Titulo: ");
    scanf("%99s", new->titulo);

    printf("Autor: ");
    scanf("%99s", new->autor);

    printf("Ano de publicacao: ");
    scanf("%d", &new->anoP);

    new->status = 0;
    strcpy(new->email_usuario, ""); //livro novo, sem usuario atrelado

    new->prev = NULL;
    new->next = NULL;

    if(sentL->first == NULL){ //lista vazia
        sentL->first = new;
        sentL->last  = new;
    }else{
        //insere no final
        new->prev = sentL->last; 
        sentL->last->next = new;        
        sentL->last = new;        
    }

    printf("Livro cadastrado com sucesso! ID: %d\n", new->id);

}

void buscaLivroID (SentLivros *sentL){
    int id;
    Livros *aux;

    printf("Codigo do livro: ");
    scanf("%d", &id);

    for(aux = sentL->first; aux!= NULL; aux = aux->next){
        if(aux->id == id){
            printf("\n--- Livro encontrado ---\n");
            printf("ID:     %d\n",  aux->id);
            printf("Titulo: %s\n",  aux->titulo);
            printf("Autor:  %s\n",  aux->autor);
            printf("Ano:    %d\n",  aux->anoP);
            printf("Status: %s\n",  aux->status == 0 ? "Disponivel" : "Emprestado");
            if (aux->status == 1){
                printf("Emprestado para: %s\n", aux->email_usuario);
            return;
            } 
        }
    }

    printf("Livro nao encontrado.\n");
}

void buscaAutor (SentLivros *sentL){
    char autor[100];
    Livros *aux;
    int encontrou = 0;

    printf("Autor: ");
    scanf("%99s", autor);

    for(aux = sentL->first; aux!= NULL; aux = aux->next){
        if (strcmp(aux->autor, autor) == 0) {
            if (!encontrou) {
                printf("\n--- Livros encontrados ---\n");
                encontrou = 1;
            }
            printf("ID: %d | Titulo: %s | Ano: %d | Status: %s\n",
                aux->id,
                aux->titulo,
                aux->anoP,
                aux->status == 0 ? "Disponivel" : "Emprestado");
        }
    }
    if(!encontrou)
        printf("Livro nao encontrado. \n");
}

void atualizaLivro(SentLivros *sentL) {
    int id;
    Livros *aux;

    printf("Codigo do livro a atualizar: ");
    scanf("%d", &id);

    for (aux = sentL->first; aux != NULL; aux = aux->next) {
        if (aux->id == id) {
            int opcao;
            do {
                printf("\n--- O que deseja alterar? ---\n");
                printf("1. Titulo\n");
                printf("2. Autor\n");
                printf("3. Ano\n");
                printf("0. Voltar\n");
                printf("Opcao: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        printf("Novo titulo: ");
                        scanf("%99s", aux->titulo);
                        printf("Titulo atualizado com sucesso!\n");
                        break;
                    case 2:
                        printf("Novo autor: ");
                        scanf("%99s", aux->autor);
                        printf("Autor atualizado com sucesso!\n");
                        break;
                    case 3:
                        printf("Novo ano: ");
                        scanf("%d", &aux->anoP);
                        printf("Ano atualizado com sucesso!\n");
                        break;
                    case 0:
                        printf("Voltando...\n");
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
            } while (opcao != 0);
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

