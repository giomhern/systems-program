struct list_node {
    char *str;
    struct list_node *next;
};

/*

You may assume the list does not contain any duplicates and the strings are not sorted in any particular order. You are to write code to insert a new string s into a linked list. You may insert the copy of s anywhere in the list if you need to add it. The list might be empty initially, in which case you should create a single node pointing to a copy of s and return a pointer to that new node as a result. If the string s already appears in the list, the function should return a pointer to the original, unmodified list.
Example: The following statement would add “xyzzy” to the list whose first node is words if “xyzzy” is not already in the list;
words = insert(“xyzzy”, words);
Write your code in two steps in Parts (a) and (b) below and on the next page:
    Part (a) (8 points) Complete the definition of the following function new_node so that it returns a pointer to a newly heap-allocated list_node that references a newly heap- allocated copy of the given string. Some useful #includes are provided for you.
    You may assume the list does not contain any duplicates and the strings are not sorted in any particular order. You are to write code to insert a new string s into a linked list. You may insert the copy of s anywhere in the list if you need to add it. The list might be empty initially, in which case you should create a single node pointing to a copy of s and return a pointer to that new node as a result. If the string s already appears in the list, the function should return a pointer to the original, unmodified list.
    Example: The following statement would add “xyzzy” to the list whose first node is words if “xyzzy” is not already in the list;
    words = insert(“xyzzy”, words);
    Write your code in two steps in Parts (a) and (b) below and on the next page:
    Part (a) (8 points) Complete the definition of the following function new_node so that it returns a pointer to a newly heap-allocated list_node that references a newly heap- allocated copy of the given string. Some useful #includes are provided for you.

*/

struct list_node *new_node(char *s);

/*
    Part (b) (10 points) Now, implement the following function 
    to insert a new heap- allocated copy of a string s into linked list l. (If a new node is needed to hold s, use the new_node function from part (a) to create it.) If string s already occurs in the linked list, the function should not change the list. The function should return a pointer to the head of the (possibly modified) list l. 
    You may assume that all strings are properly \0- terminated and you do not 
    need to worry about overrun errors (i.e., it’s ok to use strcmp instead of strncmp, etc.).
    insert a copy of string s into the linked list l        
    and return a pointer to l.  If s already appears in l,  
    do not change l and just return a pointer to it.       
*/

struct list_node *insert(char *s, struct list_node *l);

struct free_node
{
    uintptr_t size; // number of bytes in this node including this header 
    struct free_node *next; // next node on the free_list or NULL if no more nodes
};

/* return true (1) if the node addresses on list p are */
/* strictly increasing, otherwise return false (0)     */
int looks_ok(struct free_node *p);

struct node {
    int data;
    struct node *next;
};

int count(struct node *head, int searchFor);

int get_nth(struct node* head, int index);

void sortedInsert(struct node **headRef, struct node *newNode);

void insertSort(struct node **headRef);

void append(struct node **aRef, struct node **bRef);
