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

void buscaLivro (SentLivros *sentL){
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