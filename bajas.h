#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buscar.h"
#include "datos.h"

void eliminarPrimero(struct Persona **ptr);
void eliminarMatricula(struct Persona **ptr);
void eliminarTodos(struct Persona **ptr);

void eliminarPrimero(struct Persona **ptr){
    struct Persona *ptrAux;

    if(*ptr == NULL){
        printf("NO HAY ALUMNOS REGISTRADOS\n");
        return;
    }

    ptrAux = *ptr;
    *ptr = (*ptr)->ptrSig;

    free(ptrAux->nombre);
    free(ptrAux->ptrAlum->carrera);
    free(ptrAux->ptrAlum);
    free(ptrAux);

    printf("ALUMNO ELIMINADO\n");
}

void eliminarMatricula(struct Persona **ptr){
    struct Persona *ptrAux, *ptrAnt;
    char matricula[11];
    char resp;

    if(*ptr == NULL){
        printf("NO HAY ALUMNOS REGISTRADOS\n");
        return;
    }

    do{
        printf("MATRICULA: ");
        fgets(matricula, sizeof(matricula), stdin);
        matricula[strcspn(matricula, "\n")] = '\0';

        ptrAux = *ptr;
        ptrAnt = NULL;

        while(ptrAux != NULL && strcmp(ptrAux->ptrAlum->matricula, matricula) != 0){
            ptrAnt = ptrAux;
            ptrAux = ptrAux->ptrSig;
        }

        if(ptrAux == NULL){
            printf("ALUMNO NO ENCONTRADO\n");

        }else{

            if(ptrAnt == NULL){

                *ptr = ptrAux->ptrSig;

            }else{
                ptrAnt->ptrSig = ptrAux->ptrSig;
            }

            free(ptrAux->nombre);
            free(ptrAux->ptrAlum->carrera);
            free(ptrAux->ptrAlum);
            free(ptrAux);

            printf("ALUMNO ELIMINADO\n");
        }

        printf("DESEA SEGUIR ELIMINANDO ALUMNOS? (S/N): ");
        scanf(" %c", &resp);
        limpiarBuffer();

    }while(resp == 'S' || resp == 's');
}

void eliminarTodos(struct Persona **ptr){
    struct Persona *ptrAux;

    if(*ptr == NULL){
        printf("NO HAY ALUMNOS REGISTRADOS\n");
        return;
    }

    while(*ptr != NULL){
        ptrAux = *ptr;
        *ptr = (*ptr)->ptrSig;

        free(ptrAux->nombre);
        free(ptrAux->ptrAlum->carrera);
        free(ptrAux->ptrAlum);
        free(ptrAux);
    }

    printf("ALUMNOS ELIMINADOS\n");
}

