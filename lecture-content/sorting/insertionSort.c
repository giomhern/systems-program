#include <stdio.h>
#include <stdlib.h>


typedef struct intlist intlist;

struct intlist
{
    int value;
    intlist *next;
};

intlist* insert(intlist* l, int value){
    if(l == NULL){
        return prepend(value, NULL);
    }
    if(value < l->value){
        return prepend(value, l);
    }
    l->next = insert(l->next, value);
    return l;
}

intlist* insertion_sort(intlist* unsorted){
    intlist* sorted = NULL;
    while(unsorted){
        sorted = insert(sorted, unsorted->value);
        unsorted = unsorted->next;
    }
    return sorted;
}

