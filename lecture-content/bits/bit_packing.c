#include <stdio.h>
typedef struct intlist intlist;

struct intlist
{
    int value;
    intlist *next;
};

int addten(int x) {
    return x + 10;
}   

int foo(){
    int (*fptr)(int);
    fptr = &addten; // you do not have to write the ampersand
    int y = (*fptr)(5);
    return y;
}

void map(intlist* l, int(*f)(int)){
    while(l){
        l->value = f(l->value);
        l = l->next;
    }
}

int main() {
    // Example: Packing and Unpacking RGB values using Bit Masking

    // Define individual color values
    unsigned char red = 100;   // Example red value
    unsigned char green = 150; // Example green value
    unsigned char blue = 200;  // Example blue value

    // Packing RGB values into a single integer
    // Shift red 16 bits to the left, green 8 bits to the left, and leave blue as is
    unsigned int packed_color = (red << 16) | (green << 8) | blue;
    printf("Packed Color: 0x%06x\n", packed_color);

    // Unpacking RGB values from the packed integer
    // Mask and shift to extract each color
    unsigned char unpacked_red = (packed_color >> 16) & 0xFF;
    unsigned char unpacked_green = (packed_color >> 8) & 0xFF;
    unsigned char unpacked_blue = packed_color & 0xFF;

    printf("Unpacked Red: %d\n", unpacked_red);
    printf("Unpacked Green: %d\n", unpacked_green);
    printf("Unpacked Blue: %d\n", unpacked_blue);

    int x = 13; // binary is 

    // 13 / 2  Q: 6 R: 1
    //  6 / 2 Q: 3 R: 0
    // 3 / 2 Q: 1 R: 1
    // 1 / 2 Q: 0 R: 1 
    // 1101 --> 101101
    // 1101 
    printf("Ans: %d", x | (4 << 5));
    return 0;
}
