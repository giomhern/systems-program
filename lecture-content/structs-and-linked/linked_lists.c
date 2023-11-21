#include <stdio.h>
#include <stdlib.h>

/*

typedef unsigned long long int ullint;
*/
typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

intlist* prepend(int val, intlist* next){
    intlist* new = malloc(sizeof(intlist));
    new->val = val;
    new->next = next;
    return new;
}

int sum(intlist* l){
    if (l == NULL){
        return 0;
    }
    return l->val + sum(l->next);
}


void squares_change(intlist* l){
    if (l == NULL){
        return;
    }
    l->val = l->val * l->val;
    squares_change(l->next);
}

intlist* squares_copy(intlist* l){
    if (l == NULL){
        return NULL;
    }
    return prepend(l->val * l->val, squares_copy(l->next));
}

int main(){
    intlist* l = prepend(1, prepend(2, prepend(3, NULL)));
}