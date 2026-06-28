#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuario.h"
#include "livro.h"

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

void buscaEmail(SentUsuario *sentU){
    char email[100];
    Usuarios *aux;

    printf("Email: ");
    scanf("%99s", email);

    for (aux = sentU->first; aux != NULL; aux = aux->next) {
        if (strcmp(aux->email, email) == 0) {
            printf("\n--- Usuario encontrado ---\n");
            printf("Nome:  %s\n", aux->nome);
            printf("Email: %s\n", aux->email);
            return;
        }
    }

    printf("Usuario nao cadastrado.\n");

}

void buscaNome(SentUsuario *sentU) {
    char nome[100];
    int encontrou = 0;
    Usuarios *aux;

    printf("Nome: ");
    scanf("%99s", nome);

    for (aux = sentU->first; aux != NULL; aux = aux->next) {
        if (strcmp(aux->nome, nome) == 0) {
            if (!encontrou) {
                printf("\n--- Usuarios encontrados ---\n");
                encontrou = 1;
            }
            printf("Nome: %s | Email: %s\n", aux->nome, aux->email);
        }
    }

    if (!encontrou)
        printf("Usuario nao cadastrado.\n");
}

void buscaEmprestimosPorEmail(SentLivros *sentL, SentUsuario *sentU) {
    char email[100];
    int usuarioExiste = 0;
    Usuarios *auxU;
    Livros *auxL;
    int encontrou = 0;

    printf("Email do usuario: ");
    scanf("%99s", email);

    for (auxU = sentU->first; auxU != NULL; auxU = auxU->next) {
        if (strcmp(auxU->email, email) == 0) {
            usuarioExiste = 1;
            break;
        }
    }

    if (!usuarioExiste) {
        printf("Usuario nao cadastrado.\n");
        return;
    }

    for (auxL = sentL->first; auxL != NULL; auxL = auxL->next) {
        if (auxL->status == 1 && strcmp(auxL->email_usuario, email) == 0) {
            if (!encontrou) {
                printf("\n--- Livros em posse do usuario ---\n");
                encontrou = 1;
            }
            printf("ID: %d | Titulo: %s | Autor: %s\n", auxL->id, auxL->titulo, auxL->autor);
        }
    }

    if (!encontrou)
        printf("Usuario nao possui livros emprestados.\n");
        
}