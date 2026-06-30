#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "generadores.h"

struct Persona *nuevaPersona(void);
struct Alumno *nuevoAlumno(void);
void Altas(struct Persona **);

struct Persona *nuevaPersona(void){
    struct Persona *ptrTemp=NULL;
    ptrTemp = (struct Persona *) malloc(sizeof(struct Persona));

    if(ptrTemp==NULL){
        printf("No se reservo memoria\n");
        return NULL;
    }else{
        ptrTemp->ptrSig=NULL;

        printf("NOMBRE: ");
        ptrTemp->nombre = generarEspacio();

        printf("EDAD: ");
        scanf("%d",&ptrTemp->edad);

        printf("GENERO (H/M): ");
        scanf(" %c",&ptrTemp->genero);

        printf("FECHA DE NACIMIENTO (DD/MM/AAAA): ");
        getchar();
        fgets(ptrTemp->fn, sizeof(ptrTemp->fn), stdin);

        ptrTemp->fn[strcspn(ptrTemp->fn, "\n")] = '\0';

        ptrTemp->ptrAlum=nuevoAlumno();

        return ptrTemp;
    }
}

struct Alumno *nuevoAlumno(void){
    struct Alumno *ptrTempA=NULL;
    ptrTempA = (struct Alumno *) malloc(sizeof(struct Alumno));

    if(ptrTempA==NULL){
        printf("No se reservo memoria\n");
        return NULL;
    }else{
        printf("MATRICULA: ");
        limpiarBuffer();
        fgets(ptrTempA->matricula, sizeof(ptrTempA->matricula), stdin);
        ptrTempA->matricula[strcspn(ptrTempA->matricula, "\n")] = '\0';

        printf("CARRERA (IDSSI / IF / LCA / LB / LAT): ");
        ptrTempA->carrera = generarEspacio();

        printf("SEMESTRE: ");
        scanf("%d", &ptrTempA->semestre);

        for(int i = 0; i < 5; i++){
            printf("\nMateria %d\n", i + 1);

            for(int j=0;j<3;j++){
                 printf("Parcial %d: ",j+1);
                scanf("%f", &ptrTempA->calif[i][j]);
            }

            printf("Ordinario: ");
            scanf("%f", &ptrTempA->calif[i][3]);
        }

        generarPromedio(ptrTempA);
        generarCorreo(ptrTempA);

        return ptrTempA;
    }
}


void Altas(struct Persona **ptr){
    struct Persona *ptrTemp;
    struct Persona *ptrAux;

    ptrTemp=nuevaPersona();
    if(ptrTemp==NULL){
        printf("No se creo el nuevo nodo\n");
    }else{
        if(*ptr==NULL){
            *ptr=ptrTemp;
        }else{
                ptrAux=*ptr;

                while(ptrAux->ptrSig != NULL){
                ptrAux = ptrAux->ptrSig;
                }
                ptrAux->ptrSig = ptrTemp;
            }
        }

}