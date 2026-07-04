#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "producto.h"
void limpiar_buffer(){
    int c;
    while ((c=getchar())!=  '\n' && c != EOF);
    
}
void quitar_nueva_linea(char *cadena){
    int i= 0;
    while (*(cadena+i) !=  '\0 ')
    {
        if (*(cadena+i)==  '\n ')
        {
            *(cadena+i)=  '\0 ';
        }
        i++;
    }
    
}