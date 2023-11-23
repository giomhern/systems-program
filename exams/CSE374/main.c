#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

struct list_node *new_node (char* s){
    struct list_node* res = malloc(sizeof(struct list_node));
    res->str = malloc(sizeof(char) * (strlen(s) + 1));
    strcopy(res->str, s);
    res->next = NULL;
    return res;
}

struct list_node *insert(char *s, struct list_node *l){
    if(l == NULL){
        return NULL;
    }
    struct list_node* ptr = l;
    int found = 0;
    while(ptr != NULL){
        if(strcmp(ptr->str, s) == 0){
            found = 1;
        }
        ptr = ptr->next;
    }
    if(found == 1){
        return l;
    }
    ptr->next = new_node(s);
    return l;
}

int looks_ok(struct free_node* p){
    if(p == NULL){
        return 1;
    }
    struct free_node* ptr = p;
    while(ptr->next != NULL){
        if((ptr->size) >= (ptr->next->size)){
            return 0;
        }
        ptr = ptr->next;
    }
    return 0;
}


int length(struct node* head){
    // although generally used by means of a while loop, can be written below:
    struct node* curr;
    int count = 0;
    for(curr = head; curr != NULL; curr = curr->next){
        count++;
    }
    return (count);
}

int count(struct node *head, int searchFor){
    struct node* ptr;
    unsigned int count = 0;
    for(ptr = head; ptr != NULL; ptr = ptr->next){
        if(ptr->data == searchFor){
            count++;
        }
    }
    return count;
}


int get_nth(struct node* head, int index){
    if(head == NULL) return NULL;
    int count = 0;
    while(head != NULL){
        if(count == index) return (head->data);
        count++;
        head = head->next;
    }
    return head->data;
}

void sortedInsert(struct node **headRef, struct node *newNode){
    if (*headRef == NULL || (*headRef)->data >= newNode->data)
    {
        newNode->next = *headRef;
        *headRef = newNode;
    } else{
        struct node *curr = headRef;
        while(curr->next != NULL && curr->next->data < newNode->data){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void insertSort(struct node **headRef){
    struct node* res = NULL;
    struct node* curr = (*headRef);
    struct node* next;
    
    while(curr != NULL){
        next = curr->next;
        sortedInsert(&res, curr);
        curr = next;
    }
    (*headRef) = res;
}

void append(struct node** aRef, struct node** bRef){
    struct node* curr = (*aRef);

    while(curr != NULL){
        curr = curr->next;
    }
    curr->next = (*bRef);
    (*bRef) = NULL;
}

void frontBackSplit(struct node* source, struct node** frontRef, struct node** backRef){
    struct node* fast = source->next;
    struct node* slow = source;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void removeDuplicates(struct node* head){
    struct node* ptr = head;
    while(ptr->next != NULL){
        if(ptr->next->data == ptr->data){
            struct node* nextNext = ptr->next->next;
            ptr->next = nextNext; 
        } else ptr = ptr->next;
    }
}