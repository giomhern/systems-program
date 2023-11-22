#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int main(){

    // Traveling Pointers and Pointer Arithmetic
    // Understanding pointers and memory addresses
    int a = 10;
    int *ptr = &a;

    // Pointer arithmetic
    ptr++; // Moves to the next integer position
    ptr--; // Moves back to the original position

    // Structs
    // Defining a struct
    struct Point
    {
        int x, y;
    };

    // Accessing struct fields
    struct Point p1 = {1, 2};
    int x_val = p1.x;

    // Pointers to Structs, Nested Structs, Arrays of Structs
    // Pointer to a struct
    struct Point *ptr = &p1;

    // Nested structs
    struct Rectangle
    {
        struct Point topLeft;
        struct Point bottomRight;
    };

    // Array of structs
    struct Point pointsArray[5];

    // Unions
    // Defining a union
    union Data
    {
        int intVal;
        float floatVal;
        char str[20];
    };

    // Enums
    // Enum definition
    enum Color
    {
        RED,
        GREEN,
        BLUE
    };
    enum Color favoriteColor = RED;

    // Tagged Unions
    // Combining enums with unions
    enum DataType
    {
        INT,
        FLOAT,
        STR
    };
    union Data
    {
        int intVal;
        float floatVal;
        char str[20];
    };
    struct TaggedData
    {
        enum DataType type;
        union Data data;
    };

    // Linked Lists
    // Defining a node for a singly linked list
    struct Node
    {
        int data;
        struct Node *next;
    };

    // Multi-dimensional Arrays
    // Declaring a 2D array
    int arr[3][4];

    // Stacks and Queues
    // Stack implementation using array
    int stack[100], top = -1;

    // Queue implementation using array
    int queue[100], front = 0, rear = -1;

    // Trees
    // Defining a binary tree node
    struct TreeNode
    {
        int data;
        struct TreeNode *left, *right;
    };

    // Binary, Octal, and Hexadecimal
    // Working with different number systems
    int bin = 0b1010; // Binary
    int oct = 012;    // Octal
    int hex = 0xA;    // Hexadecimal

    // Base Conversions
    // Functions for converting between bases can be implemented

    // Hash Tables
    // Basic concept of hash table
    // (Implementing a hash table requires more detailed code)

    // Bit Packing
    // Packing bits into a single byte
    // unsigned char packedData = (data1 & 0x0F) | (data2 << 4);

    // Function Pointers
    // Using function pointers
    //void (*fun_ptr)(int) = &fun;

    // Pthreads
    // Creating a thread
    pthread_t thread;
    // pthread_create(&thread, NULL, threadFunction, NULL);
}