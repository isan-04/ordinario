#include <stdio.h>
#ifndef DATOS_H
#define DATOS_H

struct Persona{
    char *nombre;
    int edad;
    char genero;
    char fn[11];
    struct Alumno *ptrAlum;
    struct Persona *ptrSig;
};

struct Alumno{
    char matricula[11];
    char *carrera;
    int semestre;
    char correo[24];
    float calif[5][5];
};

#endif
