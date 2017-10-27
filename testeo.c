#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[10]; // Cadena a Insertar

    int states[] = {0,1,2}; // Estados
    char transitions[2] = {'a','b'}; // Transiciones

    int start_state = 0; //Estado Inicial
    int current_state; //Estado actual
    int end_state = 2; //Estado Final

    char current_transition; //Transicion Actual

    int tt[3][2] = {{ 1,  0},   // TT
                    { 2,  1},
                    {-1, -1} };

    int validation = 1;
    int i = 0;
    int j;

    printf("Ingrese cadena: \n");
    scanf("%s", str1);

    /** Inicializacion del estado */
    current_state = start_state;
    while (str1[i] != '\0'){
        current_transition = str1[i]; // Atajo
        switch (current_state){ //Todos los estados posibles
            case 0:
                if(current_transition == 'a'){
                    current_state = tt[i][1];
                    printf("camio de estado al (1): %d",current_state);
                }
                break;
            case 1:
                break;
            case 2:
                break;
        }
        i++;  // Avanzo en la lectura de cadena para cortar string
    }
    return 0;
}
/*
int indexInTT(char caracter)
{
    char transitions[2] = {'a','b'}; // Transiciones
    int index = 0;
    while(caracter != transitions[index]){
        if(index > (sizeof(transitions) + 5)){
            printf("size of %d",sizeof(transitions));
            return 3; // Que retorne el estado de rechazo
            break;
        }

        index++;
    }
    return index;
}*/

int inArray(char element, char *arreglo){
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
