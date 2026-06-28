#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

void insereListaLivros(sentLivros *sentL){
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