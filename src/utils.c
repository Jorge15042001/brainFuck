#include "utils.h"

#include <stdlib.h>
#include <stdio.h>


char *inputString(){
//The size is extended by the input with the value of the provisional
    FILE * fp = stdin;
    char *str;
    int ch;
    unsigned int size = 8;
    unsigned int len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}
