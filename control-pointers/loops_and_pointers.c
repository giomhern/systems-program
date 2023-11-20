#include <stdio.h>
#include <stdlib.h>

void vector_add(double x1, double y1, double z1, double x2, double y2, double* xr, double* yr)
{
    *xr = x1 + x2;
    *yr = y1 + y2;

}

void foo()
{
    double x1 = 1.0, y1 = 2.0, z1 = 3.0;
    double x2 = 4.0, y2 = 5.0, z2 = 6.0;
    double xr, yr, zr;
    vector_add(x1, y1, z1, x2, y2, &xr, &yr);
    printf("xr = %f, yr = %f\n", xr, yr);
}

void swap(int* i, int* j) // locations of two numbers ~ pointers
{
    int temp = *i; // temp = 7
    *i = *j; // i = 13
    *j = temp; // j = 7
}

void foo_1(){
    int a = 7, b = 13;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}

double sum(double* ds, int dslen)
{
    double s = 0;
    unsigned int i;
    for (i = 0; i < dslen; i++)
    {
        s += ds[i];
    }
    return s;
}

void squares_change(double* ds, int dslen)
{
    unsigned int i;
    for (i = 0; i < dslen; i++)
    {
        ds[i] = ds[i] * ds[i];
    }
}

double* squares_copy(double* ds,  unsigned int dslen){
    double* res = (double*) malloc(sizeof(double) * dslen); // malloc needs to know how much memory you need
    // malloc returns a pointer to the memory it allocated
    if(res == NULL){
        printf("malloc failed\n");
        exit(1);
    }
    unsigned int i;
    for (i = 0; i < dslen; i++)
    {
        res[i] = ds[i] * ds[i];
    }
    return res;
}

void foo_3(){
    double ds[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double* nums_eq = squares_copy(ds, 5);
    for(unsigned int i = 0; i < 4; i++){
        printf("%f\n", nums_eq[i]);
    }
    printf("\n");
}


/*

Test cases:

    cr_assert(nums[0] == 1);
    cr_assert(nums[1] == 2)
*/


int* evens(int nums[], int numslen, int* evenslen)
{
    unsigned int nevens = 0;
    for(int i = 0; i < numslen; i++){
        if(nums[i] % 2 == 0){
            nevens++;
        }
    }
    int* res = (int*) malloc(sizeof(int) * numslen);
    if(res == NULL){
        printf("malloc failed\n");
        exit(1);
    }
    unsigned int j = 0;
    for(int i = 0; i < numslen; i++){
        if(nums[i] % 2 == 0){
            res[j] = nums[i];
            j++;
        }
    }
    *evenslen = nevens;
    return res;
}


/* calls for above function

void foo(){
    int ns[] = {1, 2, 4, 5};
    unsigned int nevens;
    int* es = evens(ns, 4, &nevens);
    for(unsigned int i = 0; i < nevens; i++){
        printf("%d\n", es[i]);
    }
}


*(nums + 2) <=> nums[2]
*nums <=> nums[0]
// pointer arithmetic

*/

void foo_2(){
    double ds[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double s = sum(ds, 5);
    printf("s = %f\n", s);
}

int main()
{
    foo_1();
    return 0;
}
