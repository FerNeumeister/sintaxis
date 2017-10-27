#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int columnIndex(char caracter)
{
    char transitions[15] = {'0','1','2','3','4','5','6','7','8','9','.','B'}; // Transiciones
    int index = 0;
    while(caracter != transitions[index]){
        if(index > (sizeof(transitions))){
            break;
        }
        index++;
    }
    return index;
}

int rowIndex(int state)
{
    int states[] = {'A','B','C','D','E','F','G'}; // Estados
    int index = 0;
    while(state!= states[index]){
        if(index > (sizeof(states))){
            break;
        }
        index++;
    }
    return index;
}

int setearEstado(int current_state, char current_transition, int i)
{
    char transitionTable[7][12] =  {{ 'B','B','G','G','G','G','G','G','G','G','G','G'},   // Tabla de Transiciones
                                    { 'F','F','G','G','G','G','G','G','G','G','C','E'},
                                    { 'D','D','D','D','D','D','D','D','D','D','G','G'},
                                    { 'E','E','E','E','E','E','E','E','E','E','G','G'},
                                    { 'G','G','G','G','G','G','G','G','G','G','G','G'},
                                    { 'F','F','G','G','G','G','G','G','G','G','G','E'},
                                    { 'G','G','G','G','G','G','G','G','G','G','G','G'} };

    current_state = transitionTable[rowIndex(current_state)][columnIndex(current_transition)];
    return current_state;
}


int main()
{
    char str1[20]; // Cadena a Insertar

    int start_state = 'A';
    int end_state = 'E';
    int current_state;
    char current_transition;

    int i = 0;

    printf("Ingrese cadena: \n");
    scanf("%s", str1);

    current_state = start_state;

    while (str1[i] != '\0'){
        current_transition = str1[i];
        current_state  = setearEstado(current_state,current_transition, i);
        i++;
    }

    if(current_state == end_state){
        printf("ACEPTADA LA PALABRA INGRESADA PERTENECE AL LENGUAJE \n");
    }else{
        printf("RECHAZADA LA PALABRA INGRESADA NO PERTENECE AL LENGUAJE \n");
    }

    return 0;
}

/*
- Carácter a analizar: primer carácter de la cadena
- Estado actual del autómata: estado inicial
- Mientras haya caracteres en la cadena, repetir:
(1) Determinar el nuevo estado actual (estado de llegada de la
transición)
(2) Actualizar el carácter a analizar
- Si el último estado actual es un estado final, entonces la cadena
procesada es una palabra del lenguaje; caso contrario, la cadena no
pertenece al lenguaje. */
