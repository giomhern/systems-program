#include <stdio.h>
#include <stdlib.h>

/*
Very useful for testing the strings 
    #include <string.h>
    strdup
    strcpy
    strlen

    strcmp:
        - compares two strings using lexicographical order
        - returns 0 if they are the same, and a positive or negative number
        if they are not the same based on the first character that
        is different
            - a bigger number is returned if the first string is 
            bigger than the second (appears later in the alphabet)
            - a smaller number is returned if the first string is smaller than the second
            (appears earlier in the alphabet)
*/


/*
Implementations of the string functions in string.h
    strcopy
    str_copy
    str_copy_plus
*/

void strcopy(char* dest, char* src){
    unsigned int i = 0;
    while(src[i] != '\0'){ 
        // we want to iterate until we reach the null terminator
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void str_copy(char* dest, char* src){
    while(*src != '\0'){ // doesn't include the null terminator --> 
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // include it here at the end for the last index of the string
}

void str_copy_plus(char* dest, char* src){
    while((*dest++ = *src++) != '\0'){
        ; // do nothing
    } // this is the same as the above function
    // *dest = '\0'; do not need to do this bc you have already allocated the 
    // pointer up to the null terminator for each individual char 
}



/*
Structures:
    Closest to object oriented programming in C
    Cannot write methods in C, but can write functions that take in structs
    Needs to be in the header file depends on how broadly used it is
*/
struct Point { 
    double x;
    double y; 
};

struct Point midpoint(struct Point p1, struct Point p2){
    struct Point res;
    res.x = (p1.x + p2.x) / 2;
    res.y = (p1.y + p2.y) / 2;
    return res; // you get a copy of this and work more like integers/doubles
}

double distance (struct Point p1, struct Point p2){
    double xDiff = p1.x - p2.x;
    double yDiff = p1.y - p2.y;
    double dist = sqrt(xDiff * xDiff + yDiff * yDiff);
    return dist;
}

void foo(){
    struct Point p1 = {10, 20}; // include struct b/c it is a type -- yes!
     // p1 = {-4, 2} NONONONONONO
    struct Point p2 = {30, 40};
    p1.x = 5;
    double d = distance(p1, p2);
}

int main(){

    char* s = "Hello World!";
    char* u = (char*) malloc(sizeof(char) * 6);
    strcopy(u, s); // copies the string s into the string u
    printf("%s\n", u); // prints out the string u

    return 0; 

}