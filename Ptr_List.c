#include "Ptr_List.h"

Node* List_Ctor (void)
{
    Node* ficnode = (Node*) calloc (1, sizeof (Node));
    ficnode->next = ficnode;
    ficnode->prev = ficnode;
    ficnode->data = 0;
    return ficnode;
}

int List_Dtor (Node* ficnode)
{
    Node* node = ficnode->next;
    while (node != ficnode)
    {
        node = node->next;
        Node_Delete (node->prev);
    }
    free (ficnode);
    return NO_ERR;
}

Node* Node_Ins_Aft (Node* last, data_t push)
{
    assert (last != NULL);
    Node* new = (Node*) calloc (1, sizeof (Node));
    new->prev = last;           //last -> new
    new->next = last->next;     //new -> last + 1 (next)
    last->next->prev = new;     //new -> last + 1 (prev)
    last->next = new;           //last -> new

    new->data = push;
    return new;
}

int Node_Delete (Node* elem)
{
    elem->next->prev = elem->prev;
    elem->prev->next = elem->next;
    elem->data = 0;
    free (elem);
    return NO_ERR;
}