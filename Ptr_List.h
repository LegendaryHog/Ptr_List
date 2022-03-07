#ifndef PTRLISTH
#define PTRLISTH

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int data_t;
typedef struct Node {
    data_t data;
    struct Node*  next;
    struct Node*  prev;
} Node;



enum ERRORS {
    NO_ERR = 0,
    ERR = 1,
};

Node* List_Ctor    (void);
int   List_Dtor    (Node* ficnode);
Node* Node_Ins_Aft (Node* last, data_t push);
int   Node_Delete  (Node* elem);
int   List_Dump    (Node* ficnode);

#endif