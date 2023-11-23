#include <stdio.h>
#include <stdlib.h>
#include "vehicle.h"
#include "string.h"


void initializeVehicle(vehicle *v, char *make, char *model, int year, double mileage){
    struct vehicle* v;
    strcpy(v->make, make);
    strcpy(v->model, model);
    v->year = year;
    v->mileage = mileage;
}


void displayVehicleDetails(const vehicle *v){
    printf("%s Vehicle make: ", v->make);
    printf("\n");
    printf("%s Vehicle model: ", v->model);
    printf("\n");
    printf("%s Vehicle year: ", v->year);
    printf("\n");
    printf("%s Vehicle mileage: ", v->mileage);
}

void updateVehicleMileage(vehicle *v, double newMileage){
    v->mileage = newMileage;
}


void demonstrateVehicleTypeUsage(vehicleType *vt){
    vehicleType vt;
    strcpy(vt->car.veh.make, "Toyota");
    printf("Vehicle make: %s \n", vt->car.veh.make);
    strcpy(vt->car.veh.model, "Corolla");
    vt->car.veh.year = 2010;
    vt->car.veh.mileage = 20000;
}

int compareVehiclesByYear(const vehicle *v1, const vehicle *v2){
    if(v1->year > v2->year){
        return 1;
    }
    else if(v1->year < v2->year){
        return -1;
    }
    else{
        return 0;
    }
}



