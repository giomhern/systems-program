#include <stdio.h>
#include <stdlib.h>



// sentinel value is a value that is used to terminate a loop -- NULL Terminator

char* emphasize(char* s){
    char* res = (char*) malloc(sizeof(char) * strlen(s) + 1);
    unsigned int i = 0;
    while(s[i] != '\0'){
       if(s[i] == '.'){
              res[i] = '!';
         } else {
              res[i] = s[i];
       }
       i++;
    }
    res[i] = '\0';
    return res;
}
 
unsigned int strlen(char* s){
    unsigned int counter = 0;
    unsigned int i = 0;
    for(i = 0; s[i] != '\0'; i++){
        counter++;
    }
    return counter;
}
//  char t[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
int main(){
    char* s = "Hello World!";
    char* u = (char*) malloc(sizeof(char) * 6);

    return 0;
}