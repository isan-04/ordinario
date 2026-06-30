#ifndef MOSTRAR_H
#define MOSTRAR_H
#include <stdio.h>
#include <stdlib.h>
#include "datos.h"

void mostrarTodos(struct Persona *ptr);
void mostrarAlumno(struct Persona *ptr);

void mostrarTodos(struct Persona *ptr){
    struct Persona *ptrAux;

    if(ptr == NULL){
        printf("NO HAY ALUMNOS REGISTRADOS\n");
    }else{
        ptrAux = ptr;

        while(ptrAux != NULL){
            printf("\n---DATOS DEL ALUMNO---\n");

            printf("NOMBRE: %s\n", ptrAux->nombre);
            printf("EDAD: %d\n", ptrAux->edad);
            printf("GENERO: %c\n", ptrAux->genero);
            printf("FECHA DE NACIMIENTO: %s\n", ptrAux->fn);

            if(ptrAux->ptrAlum != NULL){

                printf("MATRICULA: %s\n",ptrAux->ptrAlum->matricula);
                printf("CARRERA: %s\n",ptrAux->ptrAlum->carrera);
                printf("SEMESTRE: %d\n",ptrAux->ptrAlum->semestre);
                printf("CORREO: %s\n",ptrAux->ptrAlum->correo);

                for(int i=0;i<5;i++){
                    printf("\nMATERIA %d\n",i+1);
                    for(int j=0;j<3;j++){
                        printf("Parcial %d: %.1f\n", j+1, ptrAux->ptrAlum->calif[i][j]);
                    }
                    printf("Ordinario: %.1f\n",ptrAux->ptrAlum->calif[i][3]);
                    printf("Promedio: %.1f\n",ptrAux->ptrAlum->calif[i][4]);
                }
            }
            ptrAux = ptrAux->ptrSig;
        }
    }
}

void mostrarAlumno(struct Persona *ptr){
    if(ptr == NULL){
        printf("ALUMNO NO ENCONTRADO\n");
        return;
    }

    printf("\n---DATOS DEL ALUMNO---\n");
    printf("NOMBRE: %s\n", ptr->nombre);
    printf("EDAD: %d\n", ptr->edad);
    printf("GENERO: %c\n", ptr->genero);
    printf("FECHA DE NACIMIENTO: %s\n", ptr->fn);

    printf("MATRICULA: %s\n", ptr->ptrAlum->matricula);
    printf("CARRERA: %s\n", ptr->ptrAlum->carrera);
    printf("SEMESTRE: %d\n", ptr->ptrAlum->semestre);
    printf("CORREO: %s\n", ptr->ptrAlum->correo);

    for(int i=0;i<5;i++){
        printf("\nMATERIA %d\n",i+1);
            for(int j=0;j<3;j++){
                printf("Parcial %d: %.1f\n", j+1, ptr->ptrAlum->calif[i][j]);
            }
        printf("Ordinario: %.1f\n", ptr->ptrAlum->calif[i][3]);
        printf("Promedio: %.1f\n", ptr->ptrAlum->calif[i][4]);
    }
}

#endif