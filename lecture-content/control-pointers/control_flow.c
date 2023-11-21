#include <stdlib.h>
#include <stdio.h>
/*
    char -128 -> 127 %d %c 
    unsigned char 0 -> 255 %u %c
    short -32768 -> 32767 %d %hd
    unsigned short 0 -> 65535 %u %hu
    int -2147483648 -> 2147483647 %d %i
    unsigned int 0 -> 4294967295 %u %u
    long -2147483648 -> 2147483647 %ld %li
    unsigned long 0 -> 4294967295 %lu %lu
    long long -9223372036854775808 -> 9223372036854775807 %lld %lli
    unsigned long long 0 -> 18446744073709551615 %llu %llu
    float 1.2E-38 -> 3.4E+38 %f %f
    double 2.3E-308 -> 1.7E+308 %lf %lf
*/

/*
+: add
-: sub
*: mul
/: div {5.0 / 2.0 = 2.5, but 5 / 2 = 2 -- truncated}
%: mod
*/

/*
Booleans example:
    int a = 1;
    int b = 0;
    int c = a && b; // c = 0
    int d = a || b; // d = 1
    int e = !a; // e = 0
*/

void fadd(double a[static 10], double b[static 10]){
    for(int i = 0; i < 10; i++){
        if(a[i] < 0.0) return;
        a[i] += b[i];
    }
}

float is_leap_year(unsigned short int year){
    if(year % 400 == 0) return 1;
    else if(year % 100 == 0) return 0;
    else if(year % 4 == 0) return 1;
    return 0;
}

unsigned long long int factorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void print_factorial(unsigned int n)
{
    printf("%d! = %llu\n", n, factorial(n));
}

int is_leap_year_simp(unsigned short y){
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

unsigned char days_in_month(unsigned char m, unsigned short y){
    switch(m){
        case 9:
        case 4:
        case 6:
        case 11:
            return 30;
        case 2:
            return is_leap_year_simp(y) ? 29 : 28;
        default:
            return 31;
    }
    return 0;
}

// declare it first and then dont have to declare it after 
double distance(double x1, double y1, double x2, double y2){
    double dx = x1 - x2;
    double dy = y1 - y2;
    
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main()
{
    double a[10] = {4}, b[20] = {6};
    int c = 5;
    fadd(a, b); // OK
    printf("%f\n", a[0]);
    print_factorial(6);
    printf("%s\n", is_leap_year(2020) == 1 ? "TRUE" : "FALSE");
    return 0;
}