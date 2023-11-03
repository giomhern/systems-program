#include <stdio.h>
#include <stdlib.h>

typedef struct intlist intlist;

struct intlist
{
    int val;
    intlist *next;
};

intlist* evens(intlist* l){
    if (l == NULL){
        return NULL;
    }
    if (l->val % 2 == 0){
        return prepend(l->val, evens(l->next));
    }
    return evens(l->next);
}

intlist* free_list(intlist* l){
    if (l == NULL){
        return NULL;
    }
    intlist* next = l->next;
    free(l);
    return free_list(next);
}

int sum(intlist* l){
   int res = 0;
   while(res != NULL){
         res += l->val;
         l = l->next;
   }
   return res;
}

void squares_change(intlist* l){
    if (l == NULL){
        return;
    }
    l->val = l->val * l->val;
    squares_change(l->next);
}

void free_list(intlist* l){
   while(l){
    intlist* temp = l->next;
    free(l);
    l = temp;

   }
}

intlist* squares_copy(intlist* l){
    intlist *head, *list;
    if (l == NULL){
        return NULL;
    }
    
}