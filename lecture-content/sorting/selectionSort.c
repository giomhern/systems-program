#include <stdio.h>
#include <stdlib.h> 

unsigned int find_min(int* a, unsigned int from, unsigned int to){
    int min_so_far = a[from];
    unsigned int min_index = from;
    from++;
    while(from <= to){
        if(a[from] < min_so_far){
            min_so_far = a[from];
            min_index = from;
        }
        from++;
    }
    return min_index;
}

void selection_sort(int* a, int alen){
    unsigned int i = 0;
    while(i < alen - 1){
        unsigned int min_index = find_min(a, i, alen - 1);
        int temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
        i++;
    }
}