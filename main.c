#include "Ptr_List.h"

int main (void)
{
    Node* ficnode = List_Ctor ();
    Node_Ins_Aft (ficnode, 10);
    Node_Ins_Aft (ficnode->next, 20);
    List_Dtor (ficnode);
    return 0;
}