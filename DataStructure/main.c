//
// Created by USER on 15/03/2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "Related_DSA.h"
int main(){
    struct D_node* head;
    D_insertAtBegining(&head,10);
    D_insertAtBegining(&head,20);
    D_insertAtBegining(&head,30);
    D_insertAtBegining(&head,40);
    D_insertAtBegining(&head,50);
    D_deleteNode(&head,20);
    D_alldata(head);
}