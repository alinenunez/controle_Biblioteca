#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

void insereUsuario(SentUsuario *sentU){
    Usuarios *new = malloc(sizeof(Usuarios));
    Usuarios *aux;

    if(new == NULL){
        printf("Erro: memoria insuficiente.\n");
        return;
    }

    printf("Email: ");
    scanf("%99s", new->email);

    for(aux = sentU->first; aux!=NULL; aux=aux->next){
        if(strcmp(aux->email, new->email)==0){
            printf("Erro: email ja cadastrado.\n");
            free(new);
            return;
        }
    }

    printf("Nome: ");
    scanf("%99s", new->nome);

    new->prev = NULL;
    new->next = NULL;

    if(sentU->first == NULL){ //lsita vazia
        sentU->first = new;
        sentU->last = new;
        printf("Usuario cadastrado com sucesso.\n");


    }else if(strcmp(new->email, sentU->first->email)<0){ //novo e-mail é menor que todos, insere no inicio
        new->next = sentU->first;
        sentU->first->prev = new;
        sentU->first = new;
        printf("Usuario cadastrado com sucesso.\n");

    }else{
        for(aux = sentU->first; aux!=NULL; aux=aux->next){ //novo e-mail é menor que o prox e maior que o ant, insere no meio
            if(strcmp(new->email, aux->email)<0){
                new->next = aux;
                new->prev = aux->prev;
                aux->prev->next = new;
                aux->prev = new;
                printf("Usuario cadastrado com sucesso.\n");
                return;
            }
        }
        //novo email é maior que todos, insere no final
        new->prev = sentU->last;
        sentU->last->next = new;
        sentU->last = new;
    }

        printf("Usuario cadastrado com sucesso!\n");


}
