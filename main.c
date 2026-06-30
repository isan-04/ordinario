#include <stdio.h>
#include "datos.h"
#include "menu.h"
#include "altas.h"
#include "bajas.h"
#include "buscar.h"
#include "mostrar.h"


int main(){
    int op,opA,opB,opM;
    char respA,respB;
    struct Persona *ptr = NULL;

    do{
        op=menuPrincipal();
        switch (op){
            case 1:
                do{
                    opA=menuAltas();
                    switch(opA){
                        case 1:
                            Altas(&ptr);
                            break;
                            
                        case 2:
                            do{
                                Altas(&ptr);
                                printf("Desea Seguir Registrando Alumnos? (S/N): ");
                                scanf(" %c", &respA);
                            }while(respA != 'N' && respA != 'n');
                            break;

                        case 0:
                        printf("SALIENDO...\n");
                        break;

                        default:
                            printf("OPCIÓN INVÁLIDA\n");
                            break;

                    }
                }while(opA !=0);
                break;

            case 2:
                do{
                    opB=menuBajas();
                    switch(opB){
                        case 1:
                            eliminarPrimero(&ptr);
                            break;
                            
                        case 2:
                            eliminarMatricula(&ptr);
                            break;

                        case 3:
                            eliminarTodos(&ptr);
                            break;

                        case 0:
                        printf("SALIENDO...\n");
                        break;

                        default:
                            printf("OPCIÓN INVÁLIDA\n");
                            break;

                    }
                }while(opB !=0);
                break;

            case 3:
                do{
                    opM=menuMostrar();
                    switch(opM){
                        case 1:
                            mostrarTodos(ptr);
                            break;
                            
                        case 2:
                            buscarCarrera(ptr);
                            break;

                        case 3:
                            buscarSemestre(ptr);
                            break;

                        case 4:
                            buscarCarreraSemestre(ptr);
                            break;

                        case 5:
                            mostrarAlumno(buscarNombre(ptr));
                            break;

                        case 6:
                            mostrarAlumno(buscarMatricula(ptr));
                            break;

                        case 0:
                        printf("SALIENDO...\n");
                        break;

                        default:
                            printf("OPCIÓN INVÁLIDA\n");
                            break;

                    }
                }while(opM !=0);
                break;

            case 4:
                break;

            case 0:
                eliminarTodos(&ptr);
                break;

            default:
                break;
        
            }
        }while(op!=0);

}