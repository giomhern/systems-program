#include <stdio.h>
#include <stdlib.h>
    

typedef enum
{
    Red,
    Green,
    Blue
} Color;

typedef enum
{
    Sedan,
    SUV,
    Truck,
    Coupe
} VehicleType;

typedef struct
{
    char make[50];
    char model[50];
    int year;
    VehicleType type;
} Vehicle;


int main(){
    // initializes a new vehicle struct called myCar 
    Vehicle myCar = {"Toyota", "Camry", 2020, Sedan};
    printf("myCar make: %s \n", myCar.make);

    // initializes a new Color enum called Green and prints based on condition
    Color favoriteColor = Green;
    switch (favoriteColor)
    {
    case Red:
        printf("Favorite color is Red.\n");
        break;
    case Green:
        printf("Favorite color is Green.\n");
        break;
    case Blue:
        printf("Favorite color is Blue.\n");
        break;
    }
    return 0;
}