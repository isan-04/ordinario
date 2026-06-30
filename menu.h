#include <stdio.h>
#include "generadores.h"

int menuPrincipal(void);
int menuAltas(void);

int menuPrincipal(void){
    int opc;
    printf("\n ---MENU---\n");
    printf("1.- Altas\n");
    printf("2.- Bajas\n");
    printf("3.- Mostrar\n");
    printf("4.- Funciones Especiales\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}

int menuAltas(void){
    int opc;
    printf("\n ---MENU ALTAS---\n");
    printf("1.- Ingresar un Alumno\n");
    printf("2.- Ingresar varios Alumnos\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}

int menuBajas(void){
     int opc;
    printf("\n ---MENU BAJAS---\n");
    printf("1.- Eliminar Primer Alumno\n");
    printf("2.- Eliminar Varios Alumnos\n");
    printf("3.- Eliminar Todos\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}

int menuMostrar(void){
    int opc;
    printf("\n ---MENU MOSTRAR---\n");
    printf("1.- Mostrar Todos\n");
    printf("2.- Mostrar por Carrera\n");
    printf("3.- Mostrar por Semestre\n");
    printf("4.- Mostrar por Carrera y Semestre\n");
    printf("5.- Mostrar por Nombre\n");
    printf("6.- Mostrar por Matricula\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}


int menuEspeciales(void){
    int opc;
    printf("\n ---MENU ESPECIALES---\n");
    printf("1.- Modificar\n");
    printf("2.- Mostrar calificaciones\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}

int menuModificar(void){
    int opc;
    printf("\n ---MENU MODIFICAR---\n");
    printf("1.- Calificaciones de Alumno\n");
    printf("2.- Datos de Alumno\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}

int menuModificarCalif(void){
    int opc;
    printf("\n ---MENU MODIFICAR PARCIALES---\n");
    printf("1.- Calificaciones de un Parcial\n");
    printf("2.- Calificaciones de una Materia\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}

int menuModificarDatos(void){
    int opc;
    printf("\n ---MENU MODIFICAR DATOS---\n");
    printf("1.- Datos de la Persona \n");
    printf("2.- Datos del Alumno\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}


int menuMostrarCalificaciones(void){
    int opc;
    printf("\n ---MENU MOSTRAR CALIFICACIONES---\n");
    printf("1.- Semestre\n");
    printf("2.- Carrera\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}

int menuMostrarCalificacionesSemestre(void){
    int opc;
    printf("\n ---MENU SEMESTRE---\n");
    printf("1.- Materia\n");
    printf("2.- Parcial\n");
    printf("0.- Salir.\n");
    scanf("%d",&opc);
    limpiarBuffer();
    return opc;
}



