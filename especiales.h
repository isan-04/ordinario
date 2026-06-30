#ifndef ESPECIALES_H
#define ESPECIALES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "buscar.h"
#include "generadores.h"

void modificarParcial(struct Persona *ptr);
void modificarMateria(struct Persona *ptr);
void modificarPersona(struct Persona *ptr);
void modificarAlumno(struct Persona *ptr);

void modificarParcial(struct Persona *ptr){
    struct Persona *aux;
    int parcial;

    aux = buscarMatricula(ptr);

    if(aux == NULL){
        printf("ALUMNO NO ENCONTRADO\n");
        return;
    }else{
        printf("ALUMNO ENCONTRADO\n");
    }

    printf("\nPARCIAL A MODIFICAR\n");
    printf("1.- Parcial 1\n");
    printf("2.- Parcial 2\n");
    printf("3.- Parcial 3\n");
    printf("4.- Ordinario\n");
    printf("OPCION: ");
    scanf("%d", &parcial);

    if(parcial < 1 || parcial > 4){
        printf("PARCIAL INVALIDO\n");
        return;
    }

    for(int i = 0; i < 5; i++){
        printf("\nMATERIA %d\n", i + 1);
        if(parcial == 4){
            printf("ORDINARIO: ");
        }else{
            printf("PARCIAL %d: ", parcial);
        }

        scanf("%f", &aux->ptrAlum->calif[i][parcial - 1]);
    }

    generarPromedio(aux->ptrAlum);

    printf("CALIFICACIONES MODIFICADAS\n");
}

void modificarMateria(struct Persona *ptr){
    struct Persona *aux;
    int materia;

    aux = buscarMatricula(ptr);

    if(aux == NULL){
        printf("ALUMNO NO ENCONTRADO\n");
        return;
    }else{
        printf("ALUMNO ENCONTRADO\n");
    }

    printf("MATERIA (1-5): ");
    scanf("%d",&materia);

    if(materia < 1 || materia > 5){
        printf("MATERIA INVALIDA\n");
        return;
    }

    for(int i=0;i<3;i++){
        printf("Parcial %d: ", i+1);
        scanf("%f",&aux->ptrAlum->calif[materia-1][i]);
    }

    printf("Ordinario: ");
    scanf("%f",&aux->ptrAlum->calif[materia-1][3]);

    generarPromedio(aux->ptrAlum);

    printf("CALIFICACIONES MODIFICADAS\n");
}

void modificarPersona(struct Persona *ptr){
    struct Persona *aux;

    aux = buscarMatricula(ptr);

    if(aux == NULL){
        printf("ALUMNO NO ENCONTRADO\n");
        return;
    }else{
        printf("ALUMNO ENCONTRADO\n");
    }

    printf("\nNUEVO NOMBRE: ");
    free(aux->nombre);
    aux->nombre = generarEspacio();

    printf("NUEVA EDAD: ");
    scanf("%d",&aux->edad);

    printf("NUEVO GENERO (H/M): ");
    scanf(" %c",&aux->genero);

    printf("NUEVA FECHA DE NACIMIENTO (DD/MM/AAAA): ");
    limpiarBuffer();
    fgets(aux->fn,sizeof(aux->fn),stdin);
    aux->fn[strcspn(aux->fn,"\n")] = '\0';

    printf("DATOS MODIFICADOS\n");
}

void modificarAlumno(struct Persona *ptr){
    struct Persona *aux;

    aux = buscarMatricula(ptr);

    if(aux == NULL){
        printf("ALUMNO NO ENCONTRADO\n");
        return;
    }else{
        printf("ALUMNO ENCONTRADO\n");
    }

    printf("NUEVA MATRICULA: ");
        limpiarBuffer();
        fgets(aux->ptrAlum->matricula, sizeof(aux->ptrAlum->matricula), stdin);
        aux->ptrAlum->matricula[strcspn(aux->ptrAlum->matricula, "\n")] = '\0';

        printf("NUEVA CARRERA (IDSSI / IF / LCA / LB / LAT): ");
        free(aux->ptrAlum->carrera);
        aux->ptrAlum->carrera = generarEspacio();

        printf("NUEVO SEMESTRE: ");
        scanf("%d", & aux->ptrAlum->semestre);

        generarCorreo(aux->ptrAlum);
    printf("DATOS MODIFICADOS\n");
}

#endif