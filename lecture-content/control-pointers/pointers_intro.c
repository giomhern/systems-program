#include <stdlib.h>
#include <stdio.h>

int main(){
    int x = 5;
    int *xPtr; // initialize a pointer to an int

    xPtr = &x; // reference pointer to the int x 
    *xPtr = 6; // dereference pointer to 6

    printf("%d\n", x); // does not swap 5 and 6
    return 0;
}

/*

a - 7, *aPtr --> 7
b - 7, *bPtr --> 7
c - 13, *cPtr --> 13


a == b --> 1
a == c --> 0
b == c --> 0
aptr == bptr --> 0
aptr == cptr --> 0
bptr == cptr --> 0
*aptr == *bptr --> 1

*/