#include <stdio.h>
#include <stdlib.h>


typedef struct inttree inttree;

struct inttree {
    int val;
    inttree *left, *right;
};


int treesum(inttree* t){
    if(t == NULL){
        return 0;
    }
    return t->val + treesum(t->left) + treesum(t->right);
}

int tree_sum(inttree* t){
    // use of ternary operation
    return t ? (t->val + tree_sum(t->left) + tree_sum(t->right)): 0;
}

/*

Binary numbers 


128 64 32 16 8 4 2 1 


5 === 101 --> Binary representation of numbers

unsigned char holds 8 bits


123 

123 % 10 = 3
123 / 10 = 12
12 % 10 = 2
12 / 10 = 1
1 % 10 = 1
1 / 10 = 0

143 

143 % 2 = 1
143 / 2 = 71
71 % 2 = 1
71 / 2 = 35
35 % 2 = 1
35 / 2 = 17
17 % 2 = 1
17 / 2 = 8
8 % 2 = 0
8 / 2 = 4
4 % 2 = 0
4 / 2 = 2
2 % 2 = 0
2 / 2 = 1
1 % 2 = 1
1 / 2 = 0

 dec -> hex -> oct 
 and backwards 


 dec -> binary -> oct
 


 binary search
*/