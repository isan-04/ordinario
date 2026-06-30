#ifndef ESPECIALES_H
#define ESPECIALES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "buscar.h"

void modificarPersona(struct Persona *ptr){
    struct Persona *aux;

    aux = buscarMatricula(ptr);

    if(aux == NULL){
        printf("ALUMNO NO ENCONTRADO\n");
        return;
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