#ifndef GENERADORES_H
#define GENERADORES_H

#include "datos.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *generarEspacio();
void generarPromedio(struct Alumno *ptrTempA);
void generarCorreo(struct Alumno *ptrTempA);

char *generarEspacio(){
    char c;
    char *cadena = NULL;
    int tam = 0;

    while((c=getchar())=='\n');
    do{
        cadena = realloc(cadena,(tam+1)*sizeof(char));
        cadena[tam]=c;
        tam++;
        c=getchar();

    }while(c!='\n' && c!=EOF);


    cadena = realloc(cadena,(tam+1)*sizeof(char));
    cadena[tam]='\0';

    return cadena;
}

void generarPromedio(struct Alumno *ptrTempA){
    float promParciales;

    for(int i = 0; i < 5; i++){
        promParciales = (ptrTempA->calif[i][0] + ptrTempA->calif[i][1] + ptrTempA->calif[i][2]) / 3;

        ptrTempA->calif[i][4] = (promParciales * 0.5) + (ptrTempA->calif[i][3] * 0.5);
    }
}

void generarCorreo(struct Alumno *ptrTempA){
    int lenCarrera;

    lenCarrera = strlen(ptrTempA->carrera);

    sprintf(ptrTempA->correo, "%.4s%.4s%c%c@unsij.edu.mx", ptrTempA->matricula, &ptrTempA->matricula[6],ptrTempA->carrera[lenCarrera-2],ptrTempA->carrera[lenCarrera-1]);

}

void limpiarBuffer(){
    int c;

    while((c = getchar()) != '\n' && c != EOF);

}
#endif