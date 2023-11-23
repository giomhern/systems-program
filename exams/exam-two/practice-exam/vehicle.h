#ifndef VEHICLE_H
#define VEHICLE_H

typedef struct {
    char make[50];
    char model[50];
    int year;
    double mileage;
} vehicle;

typedef struct {
    char name[100];
    char address[200];
} owner;

typedef union {
    struct car {
        vehicle veh;
        int seats;
    } car;
    struct motorcycle {
        vehicle veh;
        int hasSidecar;
    } motorcycle;
} vehicleType;

// Practice Problems:

// 1. Initialize a `vehicle` struct with given data.
// 2. Write a function to display the details of a `vehicle`.
// 3. Implement a function to update the mileage of a `vehicle`.
// 4. Create a `vehicleType` and demonstrate how to access its members.
// 5. Write a function to compare two vehicles based on their year.

void initializeVehicle(vehicle *v, char *make, char *model, int year, double mileage);
void displayVehicleDetails(const vehicle *v);
void updateVehicleMileage(vehicle *v, double newMileage);
void demonstrateVehicleTypeUsage(vehicleType *vt);
int compareVehiclesByYear(const vehicle *v1, const vehicle *v2);

#endif // VEHICLE_H
