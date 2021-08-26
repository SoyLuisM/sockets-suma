#include <stdlib.h>
void strreverse(char* begin, char* end){  
    char aux;  
    while(end>begin)   
        aux=*end, *end--=*begin, *begin++=aux; 
}
void itoa_(int value, char *str){
    char* wstr=str;
    int sign;  
    div_t res;
   
    if ((sign=value) < 0) value = -value;
   
    do {   
      *wstr++ = (value%10)+'0';
    }while(value=value/10);
   
    if(sign<0) *wstr++='-';
    *wstr='\0';

    strreverse(str,wstr-1);
}