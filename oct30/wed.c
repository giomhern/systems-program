#include <stdio.h>
#include <stdlib.h>

typedef struct intlist intlist;

struct intlist
{
    int val;
    intlist *next;
};

intlist *prepend(int val, intlist *next)
{
    intlist *new = malloc(sizeof(intlist));
    new->val = val;
    new->next = next;
    return new;
}

intlist* squares_copy(intlist* l){
    intlist *head, *tail;
    if (l == NULL){
        return NULL;
    }
    head = prepend(l->val * l->val, NULL);
    tail = head;
    l = l->next;
}

intlist* evens(intlist* l){
    intlist *head = NULL, *tail;
    while(l != NULL){
        if (l->val % 2 == 0){
            if(head == NULL){
                head = prepend(l->val, NULL);
                tail = head;
            }
            else{
                tail->next = prepend(l->val, NULL);
                tail = tail->next;
            }
        }
        l = l->next;
    }
    return head;
}



int main(){
    int** m = (int**) malloc(sizeof(int*) * 3);
    int i;
    for(i = 0; i < 3; i++){
        m[i] = (int*) malloc(sizeof(int) * 3);
    }
    (m[0])[0] = 1;
    return 0;
}
