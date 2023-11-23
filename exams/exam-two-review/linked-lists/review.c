#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

/*
    Counts the number of nodes
*/
void count_of_nodes(struct node* head){
    int count = 0;
    if(head == NULL){
        // points to nothing so it is empty
        printf("Linked list is empty");
    }

    // creates a new node called ptr to NULL 
    struct node* ptr = NULL; 

    // points the address of head -> ptr so now ptr = head = address of 100
    ptr = head;

    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }

    printf("%d \n", count);
}

void add_at_end(struct node *head, int data){
    struct node* ptr, *temp;
    ptr = head; // ptr = head = 1000
    
    // creates a new node
    temp = (struct node*)malloc(sizeof(struct node));

    // sets the data of the temp to the data we want to add 
    temp->data = data;

    // sets temp->next to NULL for future ptr 
    temp->next = NULL;

    while(ptr->next != NULL){ // the next ptr has to be NULL to break it to be able to replace it
        ptr = ptr->next;
    }

    // links the NULL now to the temp node 
    ptr->next = temp;
    
}

struct node* add_beg(struct node* head, int val){
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;
    ptr->next = head;
    head = ptr;
    return head;
}

void add_at_pos(struct node* head, int data, int pos){
    struct node* ptr = head;
    struct node* ptr2 = malloc(sizeof(struct node));

    ptr2->data = data;
    ptr2->next = NULL;

    pos--;
    
    while(pos != 1){
        ptr = ptr->next;
        pos--;
    }

    ptr2->next = ptr->next;
    ptr->next = ptr2;
}


/*
int main(){
    // ptr->next = head --> next pointer points to the beginning prev head
    // update the link/next value to the address of prev head first then update head to ptr

    // creates the head node of the linked list

    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 98;
    ptr->next = NULL;

    head->next = ptr;

    int data = 5;

    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}
*/

struct node* del_first(struct node* head){
    if(head == NULL){
        printf("List is already empty");
    } else {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct node* remove_all_elements(struct node* head, int val){
    if(head == NULL) return NULL;
    while(head != NULL && head->data == val){
        head = head->next;
    }

    struct node* curr = head, *prev = NULL;
    while(curr != NULL){
        if(curr->data == val){
            // ptr prev's next is changed past the current node to the curr->next node
            prev->next = curr->next; 
            curr = curr->next;
        } else {
            // else just traverses as normal
            prev = curr; 
            curr = curr->next;
        }
    }
    return head;
}


int main(){
    struct node* head = malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    add_at_end(head, 98);
    add_at_end(head, 5);
    int data = 67, position = 3;

    add_at_pos(head, data, position);
    struct node* ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
    
    return 0;
}