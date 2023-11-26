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
    struct node* fast = source;
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

void moveNode(struct node **destRef, struct node **sourceRef){
    struct node* newNode = *sourceRef;
    (*sourceRef) = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}

void alternatingSplit(struct node** source, struct node** aRef, struct node** bRef){
    // unsigned int count = 0;
    // while((*source) != NULL{
    //     if(count % 2 == 0){
    //         moveNode(aRef, source);
    //     } else if(count % 3 == 0){
    //         moveNode(bRef, source);
    //     }
    //     (*source) = (*source)->next;
    // }

    struct node* a = NULL;
    struct node* b = NULL;
    struct node* curr = (*source);
    while(curr != NULL){
        moveNode(&a, &curr);
        if(curr != NULL){
            moveNode(&b, &curr);
        }
    } 
    *aRef = a;
    *bRef = b;
}

struct node* shuffleMerge(struct node* a, struct node* b){
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;
}


int Count(struct node* head, int searchFor){
    struct node* curr;
    int count = 0;
    for(curr = head; curr != NULL; curr = curr->next){
        if(curr->data == searchFor){
            count++;
        }
    }
    return count;
}

int GetNth(struct node* head, int index){
    int idx = 0;
    struct node* curr = head;
    while(curr != NULL){
        if(idx == index){
            return curr->data;
        }
        idx++;
        curr = curr->next;
    }
    if(idx != index){
        fprintf(stderr, "The index is not found within the linked list");
    }
}

void DeleteList(struct node* head){
    if(head == NULL) return;
    struct node* curr = head;
    while(curr->next != NULL){
        struct node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(curr);
}

int Pop(struct node** headRef){
    if((*headRef) == NULL) return NULL;
    struct node* temp = (*headRef);
    int val = temp->data;
    (*headRef) = (*headRef)->next;
    free(temp);
    return val;
}


void InsertNth(struct node** headRef, int index, int data){
    // for inserts you want to stop at the node right before so you can make the 
    // the switch
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    int idx_tracker = 0;
    if(index == 0){
        newNode->next = (*headRef);
    }
    struct node* curr = (*headRef);
    while(curr->next != NULL){
        if(idx_tracker == index){
            struct node* temp = curr->next;
            curr->next = newNode;
            newNode->next = temp;
        }
        curr = curr->next;
        idx_tracker++;
    }
}


void SortedInsert(struct node** headRef, struct node* newNode){
    // already sorted in order 
    // compare with the one ahead, if smaller than one ahead, then thats where it 
    // goes and then fix the next values for them 
    // if not keep iterating 
    if((*headRef) == NULL) return NULL;
    struct node* curr = (*headRef);

    // 1 4 5 
    // 4 
    while(curr->next != NULL && curr->next->data < newNode->data){
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}


void InsertSort(struct node** headRef){
    struct node* curr = (*headRef), *result = NULL, *next;
    while(curr != NULL){
        next = curr->next;
        SortedInsert(&result, curr);
        curr = next;
    }
    *headRef = result;
}


void Append(struct node** aRef, struct node** bRef){
    struct node* aHead = (*aRef);
    while(aHead != NULL){
        aHead = aHead->next;
    }
    aHead->next = (*bRef);
    (*aRef) = aHead;
}
