#ifndef BUSCAR_H
#define BUSCAR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "mostrar.h"

struct Persona *buscarNombre(struct Persona *ptr);
struct Persona *buscarMatricula(struct Persona *ptr);
void buscarCarrera(struct Persona *ptr);
void buscarSemestre(struct Persona *ptr);
void buscarCarreraSemestre(struct Persona *ptr);

struct Persona *buscarNombre(struct Persona *ptr){
    char *nombre;
    struct Persona *aux;

    printf("NOMBRE: ");
    nombre = generarEspacio();

    aux = ptr;

    while(aux != NULL){
        if(strcmp(aux->nombre, nombre) == 0){
            free(nombre);
            return aux;
        }
        aux = aux->ptrSig;
    }
    free(nombre);
    return NULL;
}

struct Persona *buscarMatricula(struct Persona *ptr){
    char matricula[11];
    struct Persona *aux;

    printf("MATRICULA: ");
    fgets(matricula, sizeof(matricula), stdin);
    matricula[strcspn(matricula, "\n")] = '\0';

    aux = ptr;

    while(aux != NULL){
        if(strcmp(aux->ptrAlum->matricula, matricula) == 0){
            return aux;
        }

        aux = aux->ptrSig;
    }

    return NULL;
}

void buscarCarrera(struct Persona *ptr){
    char *carrera;
    int i=0;

    printf("CARRERA (IDSSI / IF / LCA / LB / LAT): ");
    carrera = generarEspacio();

    while(ptr != NULL){
        if(strcmp(ptr->ptrAlum->carrera, carrera) == 0){
            mostrarAlumno(ptr);
            i++;
        }
        ptr = ptr->ptrSig;
    }

    if(i==0){
        printf("NO HAY ALUMNOS DE ESTA CARRERA\n");
    }

    free(carrera);
}

void buscarSemestre(struct Persona *ptr){
    int semestre;
    int i=0;

    printf("SEMESTRE: ");
    scanf("%d", &semestre);

    while(ptr != NULL){
        if(ptr->ptrAlum->semestre == semestre){
            mostrarAlumno(ptr);
            i++;
        }
        ptr = ptr->ptrSig;
    }
    
    if(i==0){
        printf("NO HAY ALUMNOS DE ESTE SEMESTRE\n");
    }
}

void buscarCarreraSemestre(struct Persona *ptr){
    char *carrera;
    int semestre;
    int i=0;

    printf("CARRERA (IDSSI / IF / LCA / LB / LAT): ");
    carrera = generarEspacio();

    printf("SEMESTRE: ");
    scanf("%d", &semestre);

    while(ptr != NULL){
        if(strcmp(ptr->ptrAlum->carrera, carrera) == 0 && ptr->ptrAlum->semestre == semestre){
            mostrarAlumno(ptr);
            i++;
            
        }
        ptr = ptr->ptrSig;
    }

    if(i==0){
        printf("NO HAY ALUMNOS DE ESTE SEMESTRE Y CARRERA\n");
    }

    free(carrera);
}
#endif